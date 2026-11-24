// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run801: 005557d0..0055596e (415B), 00574c70..00574e40 (465B).
#include "scene_texture_shrink_801.hpp"

#include "porsche/fe_stream.hpp"
#include "porsche/files.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/heap.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/splash_progress.hpp"
#include "porsche/startup_sequence.hpp"
#include "render_descriptor.hpp"
#include "texture_constructor.hpp"

#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;
using W = std::uint16_t;
using SW = std::int16_t;
using ReportFn = void(__cdecl*)(const char*, ...);

const char kCreateShapeFile[] = "\\real\\cmn\\creates.c";
const char kCreateShapeTagFmt[] = "SHP%dx%dx%d";
const char kErrInvalidDims[] =
    "createshape - INVALID SHAPE DIMENSIONS\nrequested: %dx%dx%d maximum: %dx%d\n";
const char kErrInvalidDepth[] =
    "createshape - INVALID DEPTH\nrequested: %dx%dx%d BPP MUST BE 1,4,8,15,16,24,OR 32\n";
const char kErrOutOfMemory[] =
    "SHAPE_create - OUT OF MEMORY\nrequested: %dx%dx%d bytes: %d available: %d\n";

ReportFn diag_report() {
    return reinterpret_cast<ReportFn>(diagnostic_handler_005debf0);
}

void set_diag_location(U line) {
    diagnostic_file_005deb74_set(kCreateShapeFile);
    application_diagnostic_line_005deb78 = line;
}

SW load16s(const void* base, U offset) {
    SW value = 0;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

U load32(const void* base, U offset) {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

void store16(void* base, U offset, W value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void store32(void* base, U offset, U value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void copy_halved_words(
    const B* src, B* dst, I out_w, I out_h, I src_row_pad) {
    for (I y = out_h; y > 0; --y) {
        for (I x = out_w; x > 0; --x) {
            B word_bytes[2];
            std::memcpy(word_bytes, src, sizeof(word_bytes));
            std::memcpy(dst, word_bytes, sizeof(word_bytes));
            src += 4;
            dst += 2;
        }
        src += src_row_pad * 2;
    }
}

} // namespace

void* __cdecl scene_texture_shape_create_00574c70(
    std::int32_t width, std::int32_t height,
    std::int32_t depth, std::uint32_t flags) {
    I req_depth = depth;
    if (req_depth == 0) {
        req_depth = static_cast<I>(splash_progress_format_005dead0);
        if (req_depth == 0) {
            req_depth = 0x10;
        }
    }

    const U format_word = texture_depth_format_00535380(static_cast<U>(req_depth));
    const I bits = static_cast<I>(render_descriptor_bits_00537f90(&format_word));
    const I storage_bits = (bits == 0x0f) ? 0x10 : bits;

    if (width < 0 || width > 0x4000 || height < 0 || height > 0x2000) {
        if (render_descriptor_option_005deb88 != 0u) {
            set_diag_location(0x48u);
            diag_report()(kErrInvalidDims, width, height, bits, 0x4000, 0x2000);
        }
        return nullptr;
    }

    if (texture_depth_format_00535380(static_cast<U>(bits)) == 0u) {
        if (render_descriptor_option_005deb88 != 0u) {
            set_diag_location(0x51u);
            diag_report()(kErrInvalidDepth, width, height, bits);
        }
        return nullptr;
    }

    const I rounded = static_cast<I>(
        (static_cast<U>(storage_bits * width) + 7u) & 0xfffffff8u);
    const I pitch = ((rounded / storage_bits) * storage_bits) >> 3;
    const I total_bytes = pitch * height + 0x10;

    char tag[16];
    (void)formatter_entry_005a0fbf(tag, kCreateShapeTagFmt, width, height, bits);
    B* const shape = static_cast<B*>(allocate_00531ca0(tag, total_bytes, flags));
    if (shape == nullptr) {
        if (render_descriptor_option_005deb88 != 0u) {
            const U errs = texture_create_errors_005deb80;
            set_diag_location(0x61u);
            texture_create_errors_005deb80 = errs + 1u;
            const U available = startup_sequence_value_00569a90();
            diag_report()(
                kErrOutOfMemory, width, height, bits, total_bytes, available);
        }
        return nullptr;
    }

    heap_fill_0053c290(shape, 0u, 0x10u);
    store16(shape, 0x04u, static_cast<W>(width));
    store16(shape, 0x06u, static_cast<W>(height));
    const U cur = load32(shape, 0x00u);
    store32(shape, 0x00u, cur ^ ((format_word ^ cur) & 0xffu));
    return shape;
}

void* __cdecl scene_texture_descriptor_shrink_005557d0(const void* descriptor) {
    U mode = 0u;
    switch (load32(descriptor, 0x00u) & 0x7fu) {
    case 0x03u:
    case 0x42u:
    case 0x50u:
    case 0x68u:
    case 0x7eu:
        mode = 1u;
        break;
    case 0x05u:
    case 0x6au:
    case 0x7du:
        mode = 2u;
        break;
    case 0x51u:
    case 0x78u:
        mode = 4u;
        break;
    case 0x52u:
    case 0x6du:
        mode = 3u;
        break;
    default:
        return nullptr;
    }

    const I orig_w = static_cast<I>(load16s(descriptor, 0x04u));
    const I orig_h = static_cast<I>(load16s(descriptor, 0x06u));
    const I bits = static_cast<I>(render_descriptor_bits_00537f90(descriptor));
    B* const out = static_cast<B*>(scene_texture_shape_create_00574c70(
        orig_w / 2, orig_h / 2, bits, render_descriptor_flags_005deb60));

    const U src_hdr = load32(descriptor, 0x00u);
    const U out_hdr = load32(out, 0x00u);
    store32(out, 0x00u, ((out_hdr ^ src_hdr) & 0xffu) ^ out_hdr);

    const I src_pad = ((orig_w & 1) != 0) ? (orig_w + 1) : orig_w;
    const I out_w = static_cast<I>(load16s(out, 0x04u));
    const I out_h = static_cast<I>(load16s(out, 0x06u));
    const B* src = static_cast<const B*>(descriptor) + 0x10u;
    B* dst = out + 0x10u;

    switch (mode) {
    case 1u:
        if (out_h > 0) {
            copy_halved_words(src, dst, out_w, out_h, src_pad);
        }
        break;
    case 2u: {
        for (I y = out_h; y > 0; --y) {
            for (I x = out_w; x > 0; --x) {
                store32(dst, 0u, load32(src, 0u));
                src += 8;
                dst += 4;
            }
            src += src_pad * 4;
        }
        store32(dst, 0u, load32(src, 0u));
        break;
    }
    case 3u:
        if (out_h > 0) {
            copy_halved_words(src, dst, out_w, out_h, src_pad);
        }
        // Original 00555932 falls straight into case 4.
        if (out_h > 0) {
            copy_halved_words(src, dst, out_w, out_h, src_pad);
        }
        break;
    case 4u:
        if (out_h > 0) {
            copy_halved_words(src, dst, out_w, out_h, src_pad);
        }
        break;
    }

    return out;
}

} // namespace porsche
