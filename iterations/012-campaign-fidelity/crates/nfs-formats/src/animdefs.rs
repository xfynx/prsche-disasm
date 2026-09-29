//! Object-property metadata from Track/animdefs.txt (not just animations).
use crate::Result;

#[derive(Debug, Clone, Default, PartialEq)]
pub struct AnimDefinition {
    pub tag: u32,
    pub triggerable: bool,
}

#[derive(Debug, Clone, Default, PartialEq)]
pub struct AnimDefs {
    pub definitions: Vec<AnimDefinition>,
}

impl AnimDefs {
    /// EXE 0x47ed90: a missing nonzero tag falls back to the first ANIM.
    pub fn find_tag_or_first(&self, tag: u32) -> Option<&AnimDefinition> {
        if tag == 0 {
            return None;
        }
        self.definitions
            .iter()
            .find(|def| def.tag == tag)
            .or_else(|| self.definitions.first())
    }
}

/// Parse direct properties of top-level ANIM sections. Nested sections and
/// unrelated properties are skipped without letting their tags leak outward.
pub fn parse_animdefs(input: &str) -> Result<AnimDefs> {
    let tokens = tokenize(input)?;
    let mut cursor = 0;
    let mut result = AnimDefs::default();
    while cursor < tokens.len() {
        if !tokens[cursor].eq_ignore_ascii_case("SECTION") {
            return Err(format!(
                "animdefs: expected SECTION, found {}",
                tokens[cursor]
            ));
        }
        cursor += 1;
        expect(&tokens, &mut cursor, ":")?;
        let name = tokens.get(cursor).ok_or("animdefs: missing section name")?;
        cursor += 1;
        expect(&tokens, &mut cursor, "{")?;
        let mut definition = AnimDefinition::default();
        let is_anim = name.eq_ignore_ascii_case("ANIM");
        let mut depth = 1;
        while depth != 0 {
            let token = tokens.get(cursor).ok_or("animdefs: unclosed section")?;
            cursor += 1;
            match token.as_str() {
                "{" => depth += 1,
                "}" => depth -= 1,
                _ if is_anim && depth == 1 && tokens.get(cursor).is_some_and(|s| s == "=") => {
                    cursor += 1;
                    let value = tokens
                        .get(cursor)
                        .ok_or("animdefs: missing property value")?;
                    cursor += 1;
                    if token.eq_ignore_ascii_case("tag") {
                        if value.is_empty() || value.len() > 4 || !value.is_ascii() {
                            return Err(format!("animdefs: invalid tag {value}"));
                        }
                        let mut bytes = [0; 4];
                        bytes[..value.len()].copy_from_slice(value.as_bytes());
                        definition.tag = u32::from_le_bytes(bytes);
                    } else if token.eq_ignore_ascii_case("triggerable") {
                        definition.triggerable = value
                            .parse::<i32>()
                            .map_err(|e| format!("animdefs triggerable: {e}"))?
                            != 0;
                    }
                }
                _ => {}
            }
        }
        if is_anim {
            result.definitions.push(definition);
        }
    }
    Ok(result)
}

fn expect(tokens: &[String], cursor: &mut usize, wanted: &str) -> Result<()> {
    if tokens.get(*cursor).is_none_or(|s| s != wanted) {
        return Err(format!("animdefs: expected {wanted}"));
    }
    *cursor += 1;
    Ok(())
}

fn tokenize(input: &str) -> Result<Vec<String>> {
    let mut chars = input.chars().peekable();
    let mut tokens = Vec::new();
    while let Some(ch) = chars.next() {
        if ch.is_whitespace() {
            continue;
        }
        if ch == '/' && chars.peek() == Some(&'/') {
            for c in chars.by_ref() {
                if c == '\n' {
                    break;
                }
            }
        } else if ch == '/' && chars.peek() == Some(&'*') {
            chars.next();
            loop {
                let c = chars.next().ok_or("animdefs: unclosed comment")?;
                if c == '*' && chars.peek() == Some(&'/') {
                    chars.next();
                    break;
                }
            }
        } else if "{}=:;".contains(ch) {
            tokens.push(ch.to_string());
        } else if ch == '"' {
            let mut token = String::new();
            loop {
                let c = chars.next().ok_or("animdefs: unclosed string")?;
                if c == '"' {
                    break;
                }
                token.push(c);
            }
            tokens.push(token);
        } else {
            let mut token = ch.to_string();
            while chars
                .peek()
                .is_some_and(|c| !c.is_whitespace() && !"{}=:;/".contains(*c))
            {
                token.push(chars.next().unwrap());
            }
            tokens.push(token);
        }
    }
    Ok(tokens)
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn section_scoping_defaults_and_fallback() {
        let defs = parse_animdefs(
            r#"
            // SECTION:ANIM { tag=FAKE; }
            SECTION:Audio { tag=TRAN; SECTION:Sound { triggerable=1; } }
            SECTION:ANIM { tag=BASE; SECTION:Other { tag=NOPE; triggerable=1; } }
            section:anim { tag="ARW1"; unknown=kBox; triggerable=-3; }
            /* SECTION:ANIM {} */ SECTION:ANIM { tag=GAS; }
        "#,
        )
        .unwrap();
        assert_eq!(defs.definitions.len(), 3);
        assert!(!defs.definitions[0].triggerable);
        assert_eq!(defs.definitions[0].tag, u32::from_le_bytes(*b"BASE"));
        assert!(
            defs.find_tag_or_first(u32::from_le_bytes(*b"ARW1"))
                .unwrap()
                .triggerable
        );
        assert_eq!(defs.find_tag_or_first(123), defs.definitions.first());
        assert_eq!(defs.find_tag_or_first(0), None);
        assert_eq!(defs.definitions[2].tag, u32::from_le_bytes(*b"GAS\0"));
        assert!(parse_animdefs("SECTION:ANIM { triggerable=bad; }").is_err());
        assert!(parse_animdefs("SECTION:ANIM {").is_err());
        assert!(parse_animdefs("/*").is_err());
        assert_eq!(AnimDefs::default().find_tag_or_first(123), None);
    }

    #[test]
    fn local_arrow_metadata() {
        let path = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("../../../../local/game/GameData/Track/animdefs.txt");
        if !path.exists() {
            return;
        }
        let defs = parse_animdefs(&std::fs::read_to_string(path).unwrap()).unwrap();
        assert_eq!(defs.definitions[0].tag, u32::from_le_bytes(*b"ENDW"));
        for tag in [*b"ARW1", *b"ARW2", *b"ARW3", *b"ARW4"] {
            let def = defs.find_tag_or_first(u32::from_le_bytes(tag)).unwrap();
            assert_eq!(def.tag, u32::from_le_bytes(tag));
            assert!(def.triggerable);
        }
        assert!(
            !defs
                .find_tag_or_first(u32::from_le_bytes(*b"CONE"))
                .unwrap()
                .triggerable
        );
    }
}
