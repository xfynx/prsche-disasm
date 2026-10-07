#include "porsche/files.hpp"

namespace porsche {

// Recovered from Porsche.exe SHA-256
// ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// VA 0x580730..0x580f00; heap_enter/leave are retained as the original
// unconditional lock boundaries, including a null lock value.

void __cdecl io_append_00580730(IoList* list, IoNode* node) {
    const auto lock = list->lock;
    heap_enter_005322b0(lock);
    if (node != nullptr) {
        IoNode* old_tail = list->tail;
        node->next = nullptr;
        ++list->count;
        list->tail = node;
        if (old_tail == nullptr) {
            list->head = node;
            list->flags |= 1u;
            heap_leave_005322c0(lock);
            return;
        }
        old_tail->next = node;
        list->flags |= 1u;
    }
    heap_leave_005322c0(lock);
}

IoNode* __cdecl io_pop_00580790(IoList* list) {
    const auto lock = list->lock;
    heap_enter_005322b0(lock);
    IoNode* node = list->head;
    if (node != nullptr) {
        if (node == list->tail) {
            list->tail = nullptr;
            list->head = nullptr;
        } else {
            list->head = node->next;
        }
        node->next = nullptr;
        --list->count;
    }
    list->flags |= 1u;
    heap_leave_005322c0(lock);
    return node;
}

void __cdecl io_sorted_00580850(IoList* list, IoNode* node) {
    const auto lock = list->lock;
    heap_enter_005322b0(lock);
    if (node != nullptr) {
        const auto argument = list->argument;
        const auto key = list->key;
        const auto node_key = key(node, argument);
        ++list->count;
        IoNode* current = list->head;
        IoNode* previous = nullptr;
        while (current != nullptr && key(current, argument) < node_key) {
            previous = current;
            current = current->next;
        }
        node->next = current;
        if (previous == nullptr) {
            list->head = node;
        } else {
            previous->next = node;
        }
        if (current == nullptr) {
            list->tail = node;
        }
        list->flags |= 1u;
    }
    heap_leave_005322c0(lock);
}

std::uint32_t __cdecl io_remove_00580930(IoList* list, IoNode* node) {
    std::uint32_t result = 0;
    if (node != nullptr && list->count != 0) {
        IoNode* previous = list->head;
        if (node == previous) {
            --list->count;
            if (node != list->tail) {
                IoNode* next = node->next;
                node->next = nullptr;
                list->head = next;
                list->flags |= 1u;
                return 1;
            }
            const auto flags = list->flags;
            node->next = nullptr;
            list->head = nullptr;
            list->tail = nullptr;
            list->flags = flags | 1u;
            return 1;
        }
        IoNode* current = previous != nullptr ? previous->next : nullptr;
        while (current != nullptr && current != node) {
            previous = current;
            current = current->next;
        }
        if (previous != nullptr && previous->next == node) {
            previous->next = node->next;
            result = 1;
            --list->count;
            if (node == list->tail) {
                list->tail = previous;
            }
            const auto flags = list->flags;
            node->next = nullptr;
            list->flags = flags | 1u;
        }
    }
    return result;
}

IoNode* __cdecl io_find_00580ad0(IoList* list, IoPredicate predicate, std::uint32_t argument) {
    const auto lock = list->lock;
    heap_enter_005322b0(lock);
    IoNode* node = list->head;
    while (node != nullptr && predicate != nullptr && predicate(node, argument) == 0) {
        node = node->next;
    }
    heap_leave_005322c0(lock);
    return node;
}

IoNode* __cdecl io_take_00580c10(IoList* list, IoPredicate predicate, std::uint32_t argument) {
    const auto lock = list->lock;
    heap_enter_005322b0(lock);
    IoNode* node = list->head;
    if (node != nullptr) {
        while (predicate != nullptr && predicate(node, argument) == 0) {
            node = node->next;
            if (node == nullptr) {
                heap_leave_005322c0(lock);
                return nullptr;
            }
        }
        if (node != nullptr && io_remove_00580930(list, node) == 0) {
            node = nullptr;
        }
    }
    heap_leave_005322c0(lock);
    return node;
}

std::uint32_t __cdecl io_lock_00580ea0(IoList* list) {
    heap_enter_005322b0(list->lock);
    return 0;
}

void __cdecl io_unlock_00580ec0(IoList* list, std::uint32_t token) {
    (void)token;
    heap_leave_005322c0(list->lock);
}

}
