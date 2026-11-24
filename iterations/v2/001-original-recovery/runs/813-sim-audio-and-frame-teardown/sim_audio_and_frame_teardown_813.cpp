// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Original 004acc10..004ad4c9 (2234B), sha256 5571f680571973a75277e953f50d9e8ae599d9a5575763ec889a33ce45dccf62.
// Original 00425330..00425743 (1044B), sha256 bdd144199a8519b28e5fbb25b9b99be0e70c84061c1a66b979cd2aa5487a782f.
// Original 00419dc0..00419e02 (67B),   sha256 2a799ca6517264b67b85257123a8b4a79accd69120281f70d17272444a0bcae8.
// Original 0041e2c0..0041e473 (436B),  sha256 652e0e62771b3c1ce9306683531bfc602ad5a0149da2b12648faba02215ecbdf.
// Original 00436710..0043673b (44B),   sha256 a2ca1e190629517c0de6bfe8523450a45052a57b73e1bdfc749b78f96cb9977e.
// Original 00434f00..00434f95 (150B),  sha256 9a0000ed225ba5b4f846bfa54a05f8d324e1f38b18e35a80abf102e95517369c.
#include "sim_audio_and_frame_teardown_813.hpp"

#include <cstring>

namespace porsche {

const char audio_file_ver_err_005d1ad4[33] = "%s|%s - file version incorrect.\n";
const char audio_file_id_err_005d1af8[28] = "%s|%s - file id incorrect.\n";
const char audio_engine_tables_tag_005d1b14[14] = "Engine Tables";
const char audio_clt_ext_005d1b24[5] = ".clt";
const char audio_cct_ext_005d1b2c[5] = ".cct";
const char audio_elt_ext_005d1b34[5] = ".elt";
const char audio_ect_ext_005d1b3c[5] = ".ect";
const char audio_engine_oom_fmt_005d1b44[28] = "Out of memory loading '%s'\n";
const char audio_sd7a_viv_fmt_005d1b60[11] = "%ssd7a.viv";
const char audio_sd7a16_viv_fmt_005d1b6c[13] = "%ssd7a16.viv";
const char audio_name_viv_fmt_005d1b7c[9] = "%s%s.viv";
const char audio_name16_viv_fmt_005d1b88[11] = "%s%s16.viv";
const char audio_engine_tag_005d1b94[13] = "Engine Audio";

FrameVector_400* frame_callback_vector_0060c9f4 = nullptr;
FrameVector_400* frame_compact_vector_0060c9c4 = nullptr;

void* sim_teardown_secondary_0060c7e8 = nullptr;
void* sim_teardown_buf_0060ab10 = nullptr;
void* sim_teardown_buf_0060ab18 = nullptr;
void* sim_teardown_buf_0060ab1c = nullptr;

std::int32_t sim_lists_refcount_0060c978 = 0;
void* sim_lists_free_buf_0060c974 = nullptr;
void* sim_lists_table_0060c964 = nullptr;
void* sim_lists_table_0060c968 = nullptr;
SimVector12_813* sim_lists_vec_0060c818 = nullptr;
SimVector12_813* sim_lists_vec_0060c904 = nullptr;

SimVector12_813* sim_pool_vec_00610a80 = nullptr;
void* sim_pool_lock_00610a88 = nullptr;

VirtualDeleteSlot0_400* sim_obj_0060c9ac = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060c9b0 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060c9bc = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060c9c0 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060c9f0 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060c9fc = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca0c = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca14 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca18 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca1c = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca20 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca24 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca28 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca2c = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca30 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca34 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca38 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca3c = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca40 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca44 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca48 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca4c = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca50 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca54 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca58 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca5c = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca60 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca64 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca68 = nullptr;
VirtualDeleteSlot0_400* sim_obj_0060ca7c = nullptr;

namespace {

constexpr std::uint32_t kCrdlMagic = 0x6c445243u; // "CRDl"

std::uint32_t addr32(const void* ptr) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(ptr));
}

std::uint32_t load_u32(const void* base, std::uint32_t offset) {
    std::uint32_t value = 0u;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof(value));
    return value;
}

void store_u16(void* base, std::uint32_t offset, std::uint16_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, sizeof(value));
}

void store_u32(void* base, std::uint32_t offset, std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, sizeof(value));
}

void copy_c_string(char* dst, const char* src) {
    const std::size_t len = std::strlen(src);
    std::memcpy(dst, src, len + 1u);
}

void append_c_string(char* dst, const char* src) {
    const std::size_t tail = std::strlen(dst);
    const std::size_t len = std::strlen(src);
    std::memcpy(dst + tail, src, len + 1u);
}

bool ends_with_ext4(const char* name, const char* ext) {
    const std::size_t len = std::strlen(name);
    return std::strcmp(name + len - 4u, ext) == 0;
}

std::uint8_t* load_engine_table_entry(
    void* file_handle,
    const char* path,
    const char* entry_name,
    std::uint32_t entry_offset,
    std::uint32_t entry_size) {
    std::uint8_t* const buf = static_cast<std::uint8_t*>(
        allocate_00531ca0(entry_name, static_cast<std::int32_t>(entry_size), 0x10u));
    if (buf == nullptr) {
        return nullptr;
    }
    (void)read_00533bf0(file_handle, entry_offset, buf, entry_size, 0x64u);
    if (load_u32(buf, 0u) != kCrdlMagic) {
        (void)formatter_stdio_printf_005a177b(
            audio_file_id_err_005d1af8, path, entry_name);
    }
    if (buf[4] != 2u) {
        (void)formatter_stdio_printf_005a177b(
            audio_file_ver_err_005d1ad4, path, entry_name);
    }
    return buf;
}

void release_slot0(VirtualDeleteSlot0_400*& cell) {
    VirtualDeleteSlot0_400* const obj = cell;
    cell = nullptr;
    if (obj != nullptr) {
        obj->delete_slot0(1u);
    }
}

void pool_free_block(void* ptr, std::uint32_t elem_count, std::uint32_t elem_bytes) {
    const std::uint32_t bytes = elem_count * elem_bytes;
    if (bytes > 0x100u) {
        context_table_release_0059ecd0(ptr);
        return;
    }
    std::uint8_t* const pool_base =
        static_cast<std::uint8_t*>(application_context_heap_state_005e4fe8()) + 0x28u;
    void* const lock = reinterpret_cast<void*>(
        static_cast<std::uintptr_t>(load_u32(pool_base, 0u)));
    heap_enter_005322b0(lock);
    const std::uint32_t bucket = (bytes - 1u) >> 3u;
    const std::uint32_t head = load_u32(pool_base, 0x0cu + bucket * 4u);
    store_u32(ptr, 4u, head);
    store_u32(pool_base, 0x0cu + bucket * 4u, addr32(ptr));
    heap_leave_005322c0(lock);
}

void release_dword_vector(SimVector12_813*& vec_cell) {
    SimVector12_813* const vec = vec_cell;
    if (vec != nullptr) {
        const std::uint32_t* const begin_ptr = reinterpret_cast<const std::uint32_t*>(
            static_cast<std::uintptr_t>(vec->begin));
        const std::uint32_t* const end_ptr = reinterpret_cast<const std::uint32_t*>(
            static_cast<std::uintptr_t>(vec->end));
        (void)sim_teardown_copy_dwords_00436710(
            end_ptr, end_ptr, const_cast<std::uint32_t*>(begin_ptr));
        const std::int32_t erased_count =
            static_cast<std::int32_t>(vec->end - vec->begin) >> 2;
        vec->end -= static_cast<std::uint32_t>(erased_count) << 2u;

        const std::uint32_t cap_count =
            static_cast<std::uint32_t>(
                static_cast<std::int32_t>(vec->capacity_end - vec->begin) >> 2);
        if (cap_count != 0u) {
            pool_free_block(
                reinterpret_cast<void*>(static_cast<std::uintptr_t>(vec->begin)),
                cap_count, 4u);
        }
        (void)application_release_0059f050(vec);
    }
    vec_cell = nullptr;
}

void release_pair_vector(FrameVector_400*& vec_cell) {
    FrameVector_400* const vec = vec_cell;
    const std::int32_t pair_count =
        static_cast<std::int32_t>(vec->end - vec->begin) >> 3;
    vec->end -= static_cast<std::uint32_t>(pair_count) << 3u;

    if (vec_cell != nullptr) {
        const std::uint32_t begin_addr = vec_cell->begin;
        const std::uint32_t cap_addr = load_u32(vec_cell, 8u);
        const std::uint32_t cap_count =
            static_cast<std::uint32_t>(
                static_cast<std::int32_t>(cap_addr - begin_addr) >> 3);
        if (cap_count != 0u) {
            pool_free_block(
                reinterpret_cast<void*>(static_cast<std::uintptr_t>(begin_addr)),
                cap_count, 8u);
        }
        (void)application_release_0059f050(vec_cell);
    }
    vec_cell = nullptr;
}

} // namespace

void __cdecl application_sim_boundary_004acc10(
    std::int32_t slot, std::uint32_t name_va) {
    if (slot >= 2 || slot < 0 || audio_channel_banks_00656aa8[slot] != nullptr) {
        return;
    }

    std::uint8_t* const table = static_cast<std::uint8_t*>(
        allocate_00531ca0(audio_engine_tag_005d1b94, 0x758, 0u));
    audio_channel_banks_00656aa8[slot] = table;

    store_u32(table, 0x754u, 0u);
    store_u32(table, 0x34u, 0u);
    table[0x40u] = 0u;
    store_u32(table, 0x38u, 0xffffffffu);
    store_u32(table, 0xc4u, 0u);
    store_u32(table, 0xc8u, 0u);
    store_u32(table, 0xccu, 0x1000u);

    for (std::uint32_t i = 0u; i < 32u; ++i) {
        store_u32(table, 0x44u + i * 4u, 0u);
        store_u32(table, 0x45cu + i * 0x0cu, 0xffffffffu);
        store_u32(table, 0x5dcu + i * 0x0cu, 0xffffffffu);
        table[0x2dcu + i * 0x0cu] = 0xffu;
        store_u16(table, 0x2d4u + i * 0x0cu, 0x200u);
        store_u16(table, 0x2d6u + i * 0x0cu, 0x200u);
        store_u32(table, 0x2d8u + i * 0x0cu, 0u);
    }

    static constexpr std::uint32_t kDefaults[13] = {
        0x32u, 0u, 0x46u, 0x14u, 0x40u, 0x80u, 0x80u,
        0xaau, 0x50u, 0x68u, 0x19u, 0xdcu, 0x1eu,
    };
    std::memcpy(table, kDefaults, sizeof(kDefaults));

    char path[128];
    copy_c_string(path, application_audio_path_prefix_0065b318);
    const std::uint32_t active_idx = application_state_006573e8.word(0x0065741cu);
    append_c_string(
        path,
        application_state_006573e8.characters(0x006582f4u + active_idx * 0x580u));
    append_c_string(path, application_audio_spl_text_005d1a04);
    (void)resource_loadat_quiet_0059db50(path, table, 0x34u);

    table[0x2d2u] = 0u;
    table[0x2d3u] = 0u;

    const char* const name_str =
        (name_va >= application_state_base_va &&
         name_va < application_state_base_va + application_state_bytes)
            ? application_state_006573e8.characters(name_va)
            : reinterpret_cast<const char*>(static_cast<std::uintptr_t>(name_va));

    void* big_file = nullptr;
    const std::int32_t quality =
        static_cast<std::int32_t>(application_state_006573e8.word(0x00657c98u));
    if (quality > 1) {
        (void)formatter_entry_005a0fbf(
            path, audio_name16_viv_fmt_005d1b88,
            application_audio_path_prefix_0065b318, name_str);
        big_file = resource_load_bigheader_quiet_0059df70(path, 0x10u);
    }
    if (big_file == nullptr) {
        (void)formatter_entry_005a0fbf(
            path, audio_name_viv_fmt_005d1b7c,
            application_audio_path_prefix_0065b318, name_str);
        big_file = resource_load_bigheader_quiet_0059df70(path, 0x10u);
    }
    if (big_file == nullptr && quality > 1) {
        (void)formatter_entry_005a0fbf(
            path, audio_sd7a16_viv_fmt_005d1b6c,
            application_audio_path_prefix_0065b318, name_str);
        big_file = resource_load_bigheader_quiet_0059df70(path, 0x10u);
    }
    if (big_file == nullptr) {
        (void)formatter_entry_005a0fbf(
            path, audio_sd7a_viv_fmt_005d1b60,
            application_audio_path_prefix_0065b318);
        big_file = resource_load_bigheader_0059dea0(path, 0x10u);
        if (big_file == nullptr) {
            return;
        }
    }

    void* file_handle = nullptr;
    (void)open_0059e040(path, 1u, 0x64u, &file_handle);
    const std::int32_t entry_count = static_cast<std::int32_t>(
        audio_resource_data_offset_00566880(addr32(big_file)));

    std::uint32_t bnk_loaded = 0u;
    std::uint8_t* tables[4] = {nullptr, nullptr, nullptr, nullptr};
    std::uint32_t entry_offset = 0u;
    std::uint32_t entry_size = 0u;

    for (std::int32_t idx = 0; idx < entry_count; ++idx) {
        const char* const entry_name = reinterpret_cast<const char*>(
            static_cast<std::uintptr_t>(audio_resource_locate_005666f0(
                addr32(big_file), 0u, static_cast<std::uint32_t>(idx),
                addr32(&entry_offset), addr32(&entry_size))));

        if (ends_with_ext4(entry_name, audio_bank_suffix_text_005d146c) &&
            bnk_loaded == 0u) {
            void* const bnk_buf = allocate_00531ca0(
                entry_name, static_cast<std::int32_t>(entry_size), 0x10u);
            if (bnk_buf != nullptr) {
                (void)read_00533bf0(
                    file_handle, entry_offset, bnk_buf, entry_size, 0x64u);
                (void)audio_bank_finalize_004a6bc0(
                    entry_name, static_cast<std::int32_t>(entry_size),
                    bnk_buf, static_cast<std::uint32_t>(slot));
                bnk_loaded = 1u;
                table[0xd0u] = static_cast<std::uint8_t>(
                    application_audio_records_006564a0[slot].raw_00 & 0xffu);
            } else {
                (void)formatter_stdio_printf_005a177b(
                    audio_engine_oom_fmt_005d1b44, entry_name);
            }
        } else if (ends_with_ext4(entry_name, audio_ect_ext_005d1b3c) &&
                   tables[0] == nullptr) {
            tables[0] = load_engine_table_entry(
                file_handle, path, entry_name, entry_offset, entry_size);
        } else if (ends_with_ext4(entry_name, audio_elt_ext_005d1b34) &&
                   tables[1] == nullptr) {
            tables[1] = load_engine_table_entry(
                file_handle, path, entry_name, entry_offset, entry_size);
        } else if (ends_with_ext4(entry_name, audio_cct_ext_005d1b2c) &&
                   tables[2] == nullptr) {
            tables[2] = load_engine_table_entry(
                file_handle, path, entry_name, entry_offset, entry_size);
        } else if (ends_with_ext4(entry_name, audio_clt_ext_005d1b24) &&
                   tables[3] == nullptr) {
            tables[3] = load_engine_table_entry(
                file_handle, path, entry_name, entry_offset, entry_size);
        }
    }

    (void)close_00533da0(file_handle, 0x64u);
    (void)free_00531f90(big_file);

    if (bnk_loaded == 0u || tables[0] == nullptr ||
        tables[1] == nullptr || tables[3] == nullptr) {
        return;
    }

    std::int32_t total_bytes = 0;
    for (std::uint32_t t = 0u; t < 4u; ++t) {
        std::uint8_t* const hdr = tables[t];
        if (hdr[5] == 0u) {
            for (std::uint32_t j = 0u; j < 8u; ++j) {
                const std::int8_t tag = static_cast<std::int8_t>(hdr[0x20u + j]);
                if (tag > -1) {
                    const std::uint32_t slot_a_off = 0x128u + j * 4u;
                    const std::uint32_t slot_b_off = 0x148u + j * 4u;
                    const std::uint32_t ptr_a =
                        load_u32(hdr, slot_a_off) + addr32(hdr + slot_a_off);
                    store_u32(hdr, slot_a_off, ptr_a);
                    const std::uint32_t ptr_b =
                        load_u32(hdr, slot_b_off) + addr32(hdr + slot_b_off);
                    store_u32(hdr, slot_b_off, ptr_b);

                    const std::uint32_t slice_off = 0x2d4u + (t * 8u + j) * 0x0cu;
                    table[slice_off + 8u] = static_cast<std::uint8_t>(tag);

                    const std::uint8_t* const curve =
                        reinterpret_cast<const std::uint8_t*>(
                            static_cast<std::uintptr_t>(ptr_a));
                    std::int32_t c = 0;
                    while (c < 0x200 && curve[c] == 0u) {
                        ++c;
                    }
                    const std::int16_t start_c = static_cast<std::int16_t>(c);
                    store_u16(table, slice_off + 0u, static_cast<std::uint16_t>(start_c));
                    if (c < 0x200) {
                        while (c < 0x200 && curve[c] != 0u) {
                            ++c;
                        }
                    }
                    const std::int16_t end_c = static_cast<std::int16_t>(c);
                    store_u16(table, slice_off + 2u, static_cast<std::uint16_t>(end_c));
                    total_bytes +=
                        static_cast<std::int32_t>(end_c) - static_cast<std::int32_t>(start_c);
                }
            }
            hdr[5] = 1u;
        }
    }

    std::uint8_t* const pool = static_cast<std::uint8_t*>(
        allocate_00531ca0(audio_engine_tables_tag_005d1b14, total_bytes, 0u));
    store_u32(table, 0x754u, addr32(pool));

    std::uint8_t* cursor = pool;
    for (std::uint32_t t = 0u; t < 4u; ++t) {
        std::uint8_t* const hdr = tables[t];
        for (std::uint32_t j = 0u; j < 8u; ++j) {
            const std::uint32_t slice_off = 0x2d4u + (t * 8u + j) * 0x0cu;
            std::int16_t start_c = 0;
            std::int16_t end_c = 0;
            std::memcpy(&start_c, table + slice_off + 0u, sizeof(start_c));
            std::memcpy(&end_c, table + slice_off + 2u, sizeof(end_c));
            const std::int32_t len =
                static_cast<std::int32_t>(end_c) - static_cast<std::int32_t>(start_c);
            if (len != 0) {
                store_u32(table, slice_off + 4u, addr32(cursor));
                const std::uint8_t* const src =
                    reinterpret_cast<const std::uint8_t*>(
                        static_cast<std::uintptr_t>(load_u32(hdr, 0x128u + j * 4u))) +
                    static_cast<std::int32_t>(start_c);
                std::memcpy(cursor, src, static_cast<std::size_t>(len));
                cursor += len;
            }
        }
        (void)free_00531f90(hdr);
    }
}

void __cdecl sim_teardown_globals_00419dc0() {
    if (sim_teardown_secondary_0060c7e8 != nullptr) {
        teardown_secondary_destroy_0059f1c0(sim_teardown_secondary_0060c7e8, nullptr);
        (void)application_release_0059f050(sim_teardown_secondary_0060c7e8);
    }
    (void)application_release_0059f050(sim_teardown_buf_0060ab18);
    (void)application_release_0059f050(sim_teardown_buf_0060ab10);
    (void)application_release_0059f050(sim_teardown_buf_0060ab1c);
}

std::uint32_t* __cdecl sim_teardown_copy_dwords_00436710(
    const std::uint32_t* src_begin,
    const std::uint32_t* src_end,
    std::uint32_t* dst) {
    const std::int32_t count = src_end - src_begin;
    if (count > 0) {
        std::memcpy(dst, src_begin, static_cast<std::size_t>(count) * 4u);
        return dst + count;
    }
    return dst;
}

void __cdecl sim_teardown_lists_0041e2c0() {
    --sim_lists_refcount_0060c978;
    if (sim_lists_refcount_0060c978 != 0) {
        return;
    }
    (void)free_00531f90(sim_lists_free_buf_0060c974);
    sim_lists_free_buf_0060c974 = nullptr;

    context_table_release_0059ecd0(sim_lists_table_0060c968);
    sim_lists_table_0060c968 = nullptr;

    context_table_release_0059ecd0(sim_lists_table_0060c964);
    sim_lists_table_0060c964 = nullptr;

    release_dword_vector(sim_lists_vec_0060c818);
    release_dword_vector(sim_lists_vec_0060c904);
}

void __cdecl sim_teardown_pool_00434f00() {
    heap_enter_005322b0(sim_pool_lock_00610a88);
    SimVector12_813* const vec = sim_pool_vec_00610a80;
    if (vec != nullptr) {
        const std::uint32_t cap_count =
            static_cast<std::uint32_t>(
                static_cast<std::int32_t>(vec->capacity_end - vec->begin) >> 2);
        if (cap_count != 0u) {
            pool_free_block(
                reinterpret_cast<void*>(static_cast<std::uintptr_t>(vec->begin)),
                cap_count, 4u);
        }
        (void)application_release_0059f050(vec);
    }
    sim_pool_vec_00610a80 = nullptr;
    heap_leave_005322c0(sim_pool_lock_00610a88);
}

void __cdecl application_sim_boundary_00425330() {
    release_slot0(sim_obj_0060ca14);
    release_slot0(sim_obj_0060ca18);
    release_slot0(sim_obj_0060ca1c);
    release_slot0(sim_obj_0060ca40);
    release_slot0(sim_obj_0060ca20);
    release_slot0(sim_obj_0060ca24);
    release_slot0(sim_obj_0060ca28);
    release_slot0(sim_obj_0060ca2c);
    release_slot0(sim_obj_0060c9f0);
    release_slot0(sim_obj_0060ca30);
    release_slot0(sim_obj_0060ca34);
    release_slot0(sim_obj_0060ca38);
    release_slot0(sim_obj_0060ca3c);
    release_slot0(sim_obj_0060ca44);
    release_slot0(sim_obj_0060ca4c);
    release_slot0(sim_obj_0060ca50);
    release_slot0(sim_obj_0060ca54);
    release_slot0(sim_obj_0060ca5c);
    release_slot0(sim_obj_0060ca48);
    release_slot0(sim_obj_0060c9b0);
    release_slot0(sim_obj_0060ca58);
    release_slot0(sim_obj_0060ca60);
    release_slot0(sim_obj_0060ca64);
    release_slot0(sim_obj_0060ca68);
    release_slot0(sim_obj_0060c9fc);
    release_slot0(sim_obj_0060c9c0);
    release_slot0(sim_obj_0060c9bc);
    release_slot0(sim_obj_0060ca0c);
    release_slot0(sim_obj_0060c9ac);
    sim_teardown_globals_00419dc0();
    release_slot0(sim_obj_0060ca7c);

    release_pair_vector(frame_callback_vector_0060c9f4);
    release_pair_vector(frame_compact_vector_0060c9c4);

    sim_teardown_lists_0041e2c0();
    sim_teardown_pool_00434f00();
}

} // namespace porsche
