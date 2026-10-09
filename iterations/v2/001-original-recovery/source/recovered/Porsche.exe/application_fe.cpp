#include "porsche/application_fe.hpp"

namespace porsche {
void __cdecl application_fe_apply_release_004b6ad8(std::uint32_t* stream) {
    auto* record=stream;
    while (*record) {
        fe_apply_004b4b80(record);
        record+=fe_record_words_004b4cd0(record);
    }
    free_00531f90(stream);
}
}
