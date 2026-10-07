#include "porsche/startup.hpp"

namespace porsche {
char* argv_0065b20c[32];
std::int32_t argc_0065b294;

std::int32_t __stdcall win_main_004b6710(void*, void*, char* command_line,
                                      std::int32_t) {
    // 0x5d6e34..0x5d6e3b copied to the original eight-byte stack local.
    char app_name[8] = "AppName";
    argv_0065b20c[0] = app_name;
    argc_0065b294 = 1;
    if (command_line) {
        while (*command_line != '\0' && argc_0065b294 < 32) {
            while (*command_line != '\0' && *command_line == ' ') {
                *command_line++ = '\0';
            }
            if (*command_line != '\0') {
                argv_0065b20c[argc_0065b294++] = command_line;
            }
            while (*command_line != '\0' && *command_line != ' ') {
                ++command_line;
            }
        }
    }
    // No quote/tab processing and no extra terminator when argc reaches 32.
    // argv[0] is consumed while its stack storage is alive, as in the original.
    return app_main_004b6a50(argc_0065b294, argv_0065b20c);
}
}
