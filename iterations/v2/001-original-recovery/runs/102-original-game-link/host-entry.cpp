#include "porsche/startup.hpp"

#include <windows.h>

int WINAPI WinMain(HINSTANCE instance,HINSTANCE previous,LPSTR command_line,
                   int show_command) {
    return static_cast<int>(porsche::win_main_004b6710(
        instance,previous,command_line,show_command));
}
