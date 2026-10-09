#include "porsche/startup_service_56a490.hpp"

namespace porsche {

// The three cells are in the zero-filled virtual tail of the original .data
// section. Their neutral names avoid claims about the larger service/object.
void* startup_service_pointer_006af114 = nullptr;
std::uint32_t startup_service_word_006af118 = 0;
std::uint32_t startup_service_word_006af11c = 0;

// 0056a490..0056a4b8. The second word is only cleared in the non-null branch;
// the final word is cleared on both paths.
void __cdecl startup_service_release_0056a490() {
    if (startup_service_pointer_006af114 != nullptr) {
        (void)free_00531f90(startup_service_pointer_006af114);
        startup_service_pointer_006af114 = nullptr;
        startup_service_word_006af118 = 0;
    }
    startup_service_word_006af11c = 0;
}

}
