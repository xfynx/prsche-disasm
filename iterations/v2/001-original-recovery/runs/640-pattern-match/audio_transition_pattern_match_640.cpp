// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 004a5f90..004a615f (464B) and 6B .data operator string 005d13bc..005d13c1.
#include "audio_transition_pattern_match_640.hpp"

namespace porsche {

char audio_transition_pattern_ops_005d13bc[6] = "&|!~^";

std::uint32_t __cdecl audio_transition_pattern_match_004a5f90(
    const char* text, char* pattern) {
    char* split = nullptr;
    if (audio_transition_pattern_ops_005d13bc[0] != '\0') {
        for (const char* op = audio_transition_pattern_ops_005d13bc; *op != '\0'; ++op) {
            const char* const hit =
                formatter_text_find_last_005a2870(pattern, static_cast<signed char>(*op));
            if (reinterpret_cast<std::uintptr_t>(hit) >
                reinterpret_cast<std::uintptr_t>(split)) {
                split = const_cast<char*>(hit);
            }
        }
    }

    if (split != nullptr) {
        const char op = *split;
        if (op == '&') {
            *split = '\0';
            std::uint32_t matched = 0u;
            if (audio_transition_pattern_match_004a5f90(text, pattern) != 0u &&
                audio_transition_pattern_match_004a5f90(text, split + 1) != 0u) {
                matched = 1u;
            }
            *split = '&';
            return matched;
        }
        if (op == '|') {
            *split = '\0';
            std::uint32_t matched = 0u;
            if (audio_transition_pattern_match_004a5f90(text, pattern) != 0u ||
                audio_transition_pattern_match_004a5f90(text, split + 1) != 0u) {
                matched = 1u;
            }
            *split = '|';
            return matched;
        }
        if (op == '!' || op == '~') {
            *split = '\0';
            std::uint32_t matched = 0u;
            if (audio_transition_pattern_match_004a5f90(text, pattern) != 0u ||
                audio_transition_pattern_match_004a5f90(text, split + 1) != 0u) {
                matched = 1u;
            }
            // Original 004a60a8 / 004a60af unconditionally restores '!' (0x21), even for '~'.
            *split = '!';
            return matched;
        }
        if (op == '^') {
            *split = '\0';
            const std::uint32_t right = audio_transition_pattern_match_004a5f90(text, split + 1);
            const std::uint32_t left = audio_transition_pattern_match_004a5f90(text, pattern);
            *split = '^';
            return right ^ left;
        }
    }

    for (;;) {
        const char p = *pattern;
        if (p == '*') {
            ++pattern;
            if (audio_transition_pattern_match_004a5f90(text, pattern) != 0u) {
                return 1u;
            }
            while (*text != '\0') {
                ++text;
                if (audio_transition_pattern_match_004a5f90(text, pattern) != 0u) {
                    return 1u;
                }
            }
            return 0u;
        }
        if (p == '?') {
            ++pattern;
            if (*text == '\0') {
                return 0u;
            }
            ++text;
            continue;
        }
        if (p == '#') {
            ++pattern;
            if (formatter_text_digit_005a2c52(static_cast<signed char>(*text)) == 0) {
                return 0u;
            }
            ++text;
            continue;
        }
        if (p == '~') {
            ++pattern;
            return audio_transition_pattern_match_004a5f90(text, pattern) == 0u ? 1u : 0u;
        }
        const int lower_text =
            formatter_float_lower_005a2248(static_cast<signed char>(*text));
        const int lower_pattern =
            formatter_float_lower_005a2248(static_cast<signed char>(*pattern));
        if (lower_text != lower_pattern) {
            return 0u;
        }
        if (*pattern == '\0') {
            return 1u;
        }
        ++pattern;
        ++text;
    }
}

} // namespace porsche
