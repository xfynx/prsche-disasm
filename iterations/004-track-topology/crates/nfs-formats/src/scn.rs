//! NFS5 scene placement scenario parser (.scn).
use crate::Result;

/// A placed geometry element from a `.scn` file.
#[derive(Debug, Clone, PartialEq)]
pub struct GeomElement {
    /// World position in track coordinates `[X, Y, Z]`.
    pub position: [f32; 3],
    /// 3x3 orientation matrix: row 0, row 1, row 2.
    pub rotation: [[f32; 3]; 3],
    /// 32-bit FourCC identifying the prop article (e.g. `0x454E4F43` = 'CONE').
    pub fourcc: u32,
    /// Element flags.
    pub flags: u32,
    /// Descriptive name or label.
    pub name: String,
}

/// Parsed `.scn` scenario file containing placed geometry elements.
#[derive(Debug, Clone, Default, PartialEq)]
pub struct ScnFile {
    pub geom_elements: Vec<GeomElement>,
}

/// Parse a `.scn` file from text.
pub fn parse_scn(input: &str) -> Result<ScnFile> {
    let mut lines = input
        .lines()
        .map(|l| l.trim())
        .filter(|l| !l.is_empty())
        .peekable();

    let mut geom_elements = Vec::new();

    while let Some(line) = lines.next() {
        if line.starts_with("GEOM_ELEMENT") {
            let pos_line = lines
                .next()
                .ok_or_else(|| "GEOM_ELEMENT: unexpected EOF reading position".to_string())?;
            let pos_tokens: Vec<&str> = pos_line.split_whitespace().collect();
            if pos_tokens.len() < 3 {
                return Err(format!(
                    "GEOM_ELEMENT: expected 3 position coordinates, found {}",
                    pos_tokens.len()
                ));
            }
            let position = [
                pos_tokens[0]
                    .parse::<f32>()
                    .map_err(|e| format!("GEOM_ELEMENT pos X: {e}"))?,
                pos_tokens[1]
                    .parse::<f32>()
                    .map_err(|e| format!("GEOM_ELEMENT pos Y: {e}"))?,
                pos_tokens[2]
                    .parse::<f32>()
                    .map_err(|e| format!("GEOM_ELEMENT pos Z: {e}"))?,
            ];

            let rot_line = lines.next().ok_or_else(|| {
                "GEOM_ELEMENT: unexpected EOF reading rotation matrix".to_string()
            })?;
            let rot_tokens: Vec<&str> = rot_line.split_whitespace().collect();
            if rot_tokens.len() < 9 {
                return Err(format!(
                    "GEOM_ELEMENT: expected 9 rotation matrix floats, found {}",
                    rot_tokens.len()
                ));
            }
            let mut rot = [0.0f32; 9];
            for (idx, tok) in rot_tokens.iter().take(9).enumerate() {
                rot[idx] = tok
                    .parse::<f32>()
                    .map_err(|e| format!("GEOM_ELEMENT rot[{idx}]: {e}"))?;
            }
            let rotation = [
                [rot[0], rot[1], rot[2]],
                [rot[3], rot[4], rot[5]],
                [rot[6], rot[7], rot[8]],
            ];

            let params_line = lines
                .next()
                .ok_or_else(|| "GEOM_ELEMENT: unexpected EOF reading parameters".to_string())?;
            let param_tokens: Vec<&str> = params_line.split_whitespace().collect();
            if param_tokens.len() < 2 {
                return Err(format!(
                    "GEOM_ELEMENT: expected at least flags and fourcc, found {}",
                    param_tokens.len()
                ));
            }
            let flags = param_tokens[0]
                .parse::<u32>()
                .map_err(|e| format!("GEOM_ELEMENT flags: {e}"))?;
            let fourcc = param_tokens[1]
                .parse::<u32>()
                .map_err(|e| format!("GEOM_ELEMENT fourcc: {e}"))?;

            let name = lines
                .next()
                .map(|s| s.to_string())
                .unwrap_or_else(|| "Geometry Element".to_string());

            geom_elements.push(GeomElement {
                position,
                rotation,
                fourcc,
                flags,
                name,
            });
        }
    }

    Ok(ScnFile { geom_elements })
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn parse_single_geom_element() {
        let input = r#"
GEOM_ELEMENT 4
-16.174486 0.000000 144.580231
0.999937 0.000000 0.000000	0.000000 0.999968 0.000000	0.000000 0.000000 0.999968
0 1162760003 0 0 -1 1 1 100
Geometry Element
"#;
        let scn = parse_scn(input).unwrap();
        assert_eq!(scn.geom_elements.len(), 1);
        let g = &scn.geom_elements[0];
        assert_eq!(g.fourcc, 1162760003); // 'CONE'
        assert_eq!(g.flags, 0);
        assert!((g.position[0] - -16.174486).abs() < 1e-4);
        assert!((g.position[2] - 144.580231).abs() < 1e-4);
        assert!((g.rotation[0][0] - 0.999937).abs() < 1e-4);
        assert_eq!(g.name, "Geometry Element");
    }

    #[test]
    fn parse_mixed_triggers_and_geom() {
        let input = r#"
TRIGGER_ELEMENT 5
-6.844955 0.000000 147.240662
1.000000 0.000000 0.000000	0.000000 1.000000 0.000000	0.000000 0.000000 1.000000
2 0 3.000000 3.000000 0.250000 0.000000 200.000000 0 -1 -1 0 -1 13 0 0 0 0
-6.844955 0.000000 148.740662	-6.844955 0.000000 145.740662
0 0.000000 0.000000 0.000000	2 0.000000 0.000000 -1.000000
Start
GEOM_ELEMENT 4
-9.539722 0.000000 116.106110
0.999937 0.000000 0.000000	0.000000 0.999968 0.000000	0.000000 0.000000 0.999968
0 1162760003 0 0 -1 1 1 100
Cone 2
"#;
        let scn = parse_scn(input).unwrap();
        assert_eq!(scn.geom_elements.len(), 1);
        assert_eq!(scn.geom_elements[0].name, "Cone 2");
    }
}
