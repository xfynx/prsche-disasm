//! NFS 5 Porsche Unleashed Replay (`.rpl`) parser.
//!
//! Replay files store deterministic race recordings:
//! - 15,908 bytes (`0x3e24`) header describing race state (track, session, and up to 8 cars)
//! - 4 bytes (`0x3e24`..`0x3e28`) tick count
//! - Stream starting at offset `0x3e28` containing per-tick input frames (8 sub-samples/tick)
//!   compressed with a run-length encoding (RLE) scheme with 0xff escape.

use crate::{bytes, u32le, Result};

pub const REPLAY_HEADER_SIZE: usize = 0x3e24; // 15,908 bytes
pub const REPLAY_STREAM_OFFSET: usize = 0x3e28; // 15,912 bytes
pub const REPLAY_BUFFER_SIZE: usize = 0x1ce28; // 118,312 bytes
pub const REPLAY_CAR_STRIDE: usize = 0x580; // 1,408 bytes
pub const REPLAY_FIRST_CAR_OFFSET: usize = 0x0e20; // 3,616 bytes
pub const REPLAY_MAX_CARS: usize = 8;

/// A participating vehicle configuration recorded in the replay header.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct ReplayCar {
    pub driver_name: String,
    pub sim_name: String,
    pub model_name: String,
    pub short_name: String,
    pub sound_bank: String,
}

/// A decoded input frame for one game tick.
///
/// NFS 5 runs a fixed simulation sub-step rate of 8 sub-samples per tick.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct ReplayFrame {
    pub tick: u32,
    /// Steering sub-samples (neutral = 64, <64 = left, >64 = right; bit 7 is flag).
    pub steering: [u8; 8],
    /// Throttle sub-samples (0..127; bit 7 is flag).
    pub throttle: [u8; 8],
    /// Brake sub-samples (0..127; bit 7 is flag).
    pub brake: [u8; 8],
    /// Gear / state sub-samples.
    pub gear: [u8; 8],
}

impl ReplayFrame {
    /// Normalized steering deflection (-1.0 to +1.0) for a given sub-sample (0..7).
    pub fn normalized_steering(&self, sub_index: usize) -> f32 {
        let val = (self.steering[sub_index.min(7)] & 0x7f) as f32;
        ((val - 64.0) / 64.0).clamp(-1.0, 1.0)
    }

    /// Normalized throttle (0.0 to 1.0) for a given sub-sample (0..7).
    pub fn normalized_throttle(&self, sub_index: usize) -> f32 {
        let val = (self.throttle[sub_index.min(7)] & 0x7f) as f32;
        (val / 127.0).clamp(0.0, 1.0)
    }

    /// Normalized brake (0.0 to 1.0) for a given sub-sample (0..7).
    pub fn normalized_brake(&self, sub_index: usize) -> f32 {
        let val = (self.brake[sub_index.min(7)] & 0x7f) as f32;
        (val / 127.0).clamp(0.0, 1.0)
    }

    /// Auxiliary flag (bit 7, e.g. handbrake or clutch).
    pub fn steering_flag(&self, sub_index: usize) -> bool {
        (self.steering[sub_index.min(7)] & 0x80) != 0
    }
}

/// A parsed replay file (`savedata/replay.rpl` or `<name>.rpl`).
#[derive(Debug, Clone, PartialEq)]
pub struct ReplayFile {
    pub track_name: String,
    pub cars: Vec<ReplayCar>,
    pub total_ticks: u32,
    pub frames: Vec<ReplayFrame>,
}

impl ReplayFile {
    /// Primary player car (index 0).
    pub fn player_car(&self) -> Option<&ReplayCar> {
        self.cars.first()
    }

    /// Duration of the recorded replay in seconds given a tick frequency (default ~60 Hz).
    pub fn duration_seconds(&self, tick_hz: f32) -> f32 {
        if tick_hz > 0.0 {
            self.total_ticks as f32 / tick_hz
        } else {
            0.0
        }
    }
}

fn read_null_terminated_ascii(slice: &[u8]) -> String {
    let end = slice.iter().position(|&b| b == 0).unwrap_or(slice.len());
    String::from_utf8_lossy(&slice[..end]).trim().to_string()
}

fn decode_rle_block(data: &[u8], offset: &mut usize) -> Result<[u8; 8]> {
    if *offset >= data.len() {
        return Err("unexpected EOF reading RLE block length".into());
    }
    let block_len = data[*offset] as usize;
    if block_len == 0 {
        return Err("zero length in RLE block".into());
    }
    let block_end = offset
        .checked_add(block_len)
        .ok_or("offset overflow in RLE block")?;
    if block_end > data.len() {
        return Err(format!(
            "RLE block length {block_len} exceeds buffer size {}",
            data.len()
        ));
    }

    let mut out = [0u8; 8];
    let mut out_len = 0;
    let mut p = *offset + 1;

    while p < block_end && out_len < 8 {
        let b = data[p];
        p += 1;
        if b == 0xff {
            if p + 1 >= block_end {
                return Err("truncated RLE repeat sequence in replay stream".into());
            }
            let count = data[p] as usize;
            let val = data[p + 1];
            p += 2;
            let take = count.min(8 - out_len);
            for _ in 0..take {
                out[out_len] = val;
                out_len += 1;
            }
        } else {
            out[out_len] = b;
            out_len += 1;
        }
    }

    *offset = block_end;
    Ok(out)
}

/// Parse a Porsche Unleashed replay binary payload (`.rpl`).
pub fn parse_replay(data: &[u8]) -> Result<ReplayFile> {
    if data.len() < REPLAY_STREAM_OFFSET {
        return Err(format!(
            "replay file too small: {} bytes, expected at least {REPLAY_STREAM_OFFSET}",
            data.len()
        ));
    }

    // 1. Track name at 0x005c (up to 32 bytes)
    let track_bytes = bytes(data, 0x005c, 32)?;
    let track_name = read_null_terminated_ascii(track_bytes);

    // 2. Cars array (up to 8 cars starting at 0x0e20 with stride 0x580)
    let mut cars = Vec::with_capacity(REPLAY_MAX_CARS);
    for i in 0..REPLAY_MAX_CARS {
        let car_base = REPLAY_FIRST_CAR_OFFSET + i * REPLAY_CAR_STRIDE;
        if car_base + REPLAY_CAR_STRIDE > REPLAY_HEADER_SIZE {
            break;
        }

        let driver_bytes = bytes(data, car_base, 32)?;
        let driver_name = read_null_terminated_ascii(driver_bytes);
        if driver_name.is_empty() {
            continue;
        }

        let sim_bytes = bytes(data, car_base + 0xac, 32)?;
        let sim_name = read_null_terminated_ascii(sim_bytes);

        let model_bytes = bytes(data, car_base + 0xec, 32)?;
        let model_name = read_null_terminated_ascii(model_bytes);

        let short_bytes = bytes(data, car_base + 0x12c, 32)?;
        let short_name = read_null_terminated_ascii(short_bytes);

        let sound_bytes = bytes(data, car_base + 0x16c, 32)?;
        let sound_bank = read_null_terminated_ascii(sound_bytes);

        cars.push(ReplayCar {
            driver_name,
            sim_name,
            model_name,
            short_name,
            sound_bank,
        });
    }

    // 3. Tick count at 0x3e24
    let total_ticks = u32le(data, 0x3e24)?;

    // 4. Frames stream starting at 0x3e28
    let mut offset = REPLAY_STREAM_OFFSET;
    let mut frames = Vec::new();

    for tick in 0..total_ticks {
        if offset >= data.len() {
            break;
        }

        // Check for end-of-replay terminator byte (0x00)
        if data[offset] == 0 {
            break;
        }

        // Block 0: raw 8 bytes steering
        let steer_slice = bytes(data, offset, 8)?;
        let mut steering = [0u8; 8];
        steering.copy_from_slice(steer_slice);
        offset += 8;

        // Block 1: RLE throttle
        let throttle = decode_rle_block(data, &mut offset)?;

        // Block 2: RLE brake
        let brake = decode_rle_block(data, &mut offset)?;

        // Block 3: RLE gear / state
        let gear = decode_rle_block(data, &mut offset)?;

        frames.push(ReplayFrame {
            tick,
            steering,
            throttle,
            brake,
            gear,
        });
    }

    Ok(ReplayFile {
        track_name,
        cars,
        total_ticks,
        frames,
    })
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn replay_rejects_truncated() {
        assert!(parse_replay(&[]).is_err());
        assert!(parse_replay(&[0u8; 100]).is_err());
        assert!(parse_replay(&[0u8; REPLAY_STREAM_OFFSET - 1]).is_err());
    }

    #[test]
    fn synthetic_replay_header_and_frames() {
        let mut data = vec![0u8; REPLAY_STREAM_OFFSET + 64];

        // Track name
        data[0x5c..0x5c + 5].copy_from_slice(b"alps\0");

        // Car 0
        let car0_base = REPLAY_FIRST_CAR_OFFSET;
        data[car0_base..car0_base + 7].copy_from_slice(b"Player\0");
        data[car0_base + 0xac..car0_base + 0xac + 7].copy_from_slice(b"box_25\0");
        data[car0_base + 0xec..car0_base + 0xec + 8].copy_from_slice(b"boxster\0");
        data[car0_base + 0x12c..car0_base + 0x12c + 4].copy_from_slice(b"box\0");
        data[car0_base + 0x16c..car0_base + 0x16c + 6].copy_from_slice(b"sdbox\0");

        // Total ticks: 2
        data[0x3e24..0x3e28].copy_from_slice(&2u32.to_le_bytes());

        // Frame 0 at 0x3e28:
        // Steering: 8 raw bytes [64, 64, 64, 64, 64, 64, 64, 64]
        let mut p = 0x3e28;
        data[p..p + 8].copy_from_slice(&[64u8; 8]);
        p += 8;

        // Throttle: RLE block [4, 0xff, 8, 100] (len=4, repeat 8 times 100)
        data[p..p + 4].copy_from_slice(&[4, 0xff, 8, 100]);
        p += 4;

        // Brake: RLE block [4, 0xff, 8, 0]
        data[p..p + 4].copy_from_slice(&[4, 0xff, 8, 0]);
        p += 4;

        // Gear: RLE block [4, 0xff, 8, 1]
        data[p..p + 4].copy_from_slice(&[4, 0xff, 8, 1]);
        p += 4;

        // Frame 1: ends early with 0x00 terminator
        data[p] = 0;

        let replay = parse_replay(&data).expect("synthetic replay parse");
        assert_eq!(replay.track_name, "alps");
        assert_eq!(replay.total_ticks, 2);
        assert_eq!(replay.cars.len(), 1);
        assert_eq!(replay.cars[0].driver_name, "Player");
        assert_eq!(replay.cars[0].sim_name, "box_25");
        assert_eq!(replay.cars[0].model_name, "boxster");
        assert_eq!(replay.frames.len(), 1);

        let f = &replay.frames[0];
        assert_eq!(f.tick, 0);
        assert_eq!(f.steering, [64u8; 8]);
        assert_eq!(f.throttle, [100u8; 8]);
        assert_eq!(f.brake, [0u8; 8]);
        assert_eq!(f.gear, [1u8; 8]);

        assert!((f.normalized_steering(0) - 0.0).abs() < 1e-4);
        assert!((f.normalized_throttle(0) - (100.0 / 127.0)).abs() < 1e-4);
        assert_eq!(f.normalized_brake(0), 0.0);
    }

    #[test]
    fn local_replay_parses_cleanly() {
        let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../../..")
            .join("local/game/savedata/replay.rpl");
        if !path.exists() {
            return;
        }

        let raw = std::fs::read(&path).expect("read replay.rpl");
        let replay = parse_replay(&raw).expect("parse replay.rpl");

        assert_eq!(replay.track_name, "coastal");
        assert_eq!(replay.total_ticks, 596);
        assert_eq!(replay.cars.len(), 8);

        let p1 = &replay.cars[0];
        assert_eq!(p1.driver_name, "xfynx");
        assert_eq!(p1.sim_name, "356_1");
        assert_eq!(p1.model_name, "356coupe11");
        assert_eq!(p1.short_name, "356");
        assert_eq!(p1.sound_bank, "sd1b");

        assert_eq!(replay.frames.len(), 37);
        let f0 = &replay.frames[0];
        assert_eq!(f0.steering, [64u8; 8]);
        assert_eq!(f0.throttle, [0u8; 8]);
        assert_eq!(f0.brake, [0u8; 8]);
        assert_eq!(f0.gear, [0u8; 8]);
    }
}
