import struct

with open('local/game/savedata/replay.rpl', 'rb') as f:
    d = f.read()

total_size = len(d)
total_ticks = struct.unpack_from('<I', d, 0x3e24)[0]
print(f"Replay total size: {total_size} bytes, total ticks: {total_ticks}")

# Decode RLE block helper
def decode_rle_block(stream, offset):
    # stream[offset] is length of block in stream (including length byte)
    blk_len = stream[offset]
    offset += 1
    out = bytearray()
    end_off = offset + blk_len - 1
    while offset < end_off and len(out) < 8:
        b = stream[offset]
        offset += 1
        if b == 0xff:
            count = stream[offset]
            val = stream[offset+1]
            offset += 2
            out.extend([val] * count)
        else:
            out.append(b)
    # pad to 8 if needed
    while len(out) < 8:
        out.append(0)
    return out[:8], end_off

# Decode stream
stream_offset = 0x3e28
frames = []

for tick in range(total_ticks):
    if stream_offset >= total_size:
        print(f"Stream ended early at tick {tick}/{total_ticks}")
        break
    
    # Check if end marker or empty
    if d[stream_offset] == 0:
        print(f"Zero marker at tick {tick}")
        break
        
    # Block 0: raw 8 bytes
    arr0 = d[stream_offset:stream_offset+8]
    stream_offset += 8
    
    # Block 1: RLE (throttle)
    arr1, stream_offset = decode_rle_block(d, stream_offset)
    
    # Block 2: RLE (brake)
    arr2, stream_offset = decode_rle_block(d, stream_offset)
    
    # Block 3: RLE (gear/state)
    arr3, stream_offset = decode_rle_block(d, stream_offset)
    
    frames.append({
        'tick': tick,
        'steer': list(arr0),
        'throttle': list(arr1),
        'brake': list(arr2),
        'gear': list(arr3),
    })

print(f"Successfully decoded {len(frames)} frames!")
print(f"Final stream offset: 0x{stream_offset:x} / 0x{total_size:x}")

# Let's print sample frames from start, middle, and end
print("\n--- Frame 0 ---")
print("Steer:   ", frames[0]['steer'])
print("Throttle:", frames[0]['throttle'])
print("Brake:   ", frames[0]['brake'])
print("Gear:    ", frames[0]['gear'])

if len(frames) > 100:
    print(f"\n--- Frame 100 ---")
    print("Steer:   ", frames[100]['steer'])
    print("Throttle:", frames[100]['throttle'])
    print("Brake:   ", frames[100]['brake'])
    print("Gear:    ", frames[100]['gear'])

if len(frames) > 300:
    print(f"\n--- Frame 300 ---")
    print("Steer:   ", frames[300]['steer'])
    print("Throttle:", frames[300]['throttle'])
    print("Brake:   ", frames[300]['brake'])
    print("Gear:    ", frames[300]['gear'])

if len(frames) > 0:
    last = frames[-1]
    print(f"\n--- Frame {last['tick']} ---")
    print("Steer:   ", last['steer'])
    print("Throttle:", last['throttle'])
    print("Brake:   ", last['brake'])
    print("Gear:    ", last['gear'])
