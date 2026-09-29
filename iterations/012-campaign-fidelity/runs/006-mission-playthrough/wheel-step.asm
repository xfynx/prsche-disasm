004a1b50 add cl, bl
004a1b52 xchg ah, ch
004a1b54 or dword ptr [eax], eax
004a1b56 add al, bl
004a1b58 and al, 0x1c
004a1b5b fstp dword ptr [esi + 0x9ec]
004a1b61 fld st(0)
004a1b63 fadd dword ptr [esi + 0x928]
004a1b69 fstp dword ptr [esi + 0x928]
004a1b6f jmp 0x4a1b9d
004a1b71 fsub st(1)
004a1b73 fstp dword ptr [esi + 0x864]
004a1b79 fld dword ptr [esi + 0x9ec]
004a1b7f fsub st(1)
004a1b81 fstp dword ptr [esi + 0x9ec]
004a1b87 fstp st(0)
004a1b89 fld dword ptr [esp + 0x1c]
004a1b8d fadd dword ptr [esi + 0x928]
004a1b93 fstp dword ptr [esi + 0x928]
004a1b99 fld dword ptr [esp + 0x1c]
004a1b9d fadd dword ptr [esi + 0xab0]
004a1ba3 mov dword ptr [esi + 0x84], 0x3f947ae1
004a1bad fstp dword ptr [esi + 0xab0]
004a1bb3 fld dword ptr [esi + 0xd60]
004a1bb9 fcomp dword ptr [0x5b2400]
004a1bbf fnstsw ax
004a1bc1 test ah, 0x41
004a1bc4 jne 0x4a1c64
004a1bca push esi
004a1bcb call 0x493b30
004a1bd0 fmul dword ptr [0x5b3284]
004a1bd6 mov eax, dword ptr [esi + 0x760]
004a1bdc add esp, 4
004a1bdf fsubr dword ptr [0x5b24a8]
004a1be5 fld st(0)
004a1be7 fmul dword ptr [eax + 0x10c]
004a1bed fmul dword ptr [esi + 0xd60]
004a1bf3 fld st(0)
004a1bf5 fadd dword ptr [esi + 0x864]
004a1bfb fstp dword ptr [esi + 0x864]
004a1c01 fadd dword ptr [esi + 0x928]
004a1c07 fstp dword ptr [esi + 0x928]
004a1c0d fmul dword ptr [eax + 0x110]
004a1c13 fmul dword ptr [esi + 0xd60]
004a1c19 fld st(0)
004a1c1b fadd dword ptr [esi + 0x9ec]
004a1c21 fstp dword ptr [esi + 0x9ec]
004a1c27 fld st(0)
004a1c29 fadd dword ptr [esi + 0xab0]
004a1c2f fstp dword ptr [esi + 0xab0]
004a1c35 fld dword ptr [esi + 0x3a0]
004a1c3b fcomp dword ptr [0x5b4a0c]
004a1c41 fnstsw ax
004a1c43 test ah, 0x41
004a1c46 jne 0x4a1c62
004a1c48 fmul dword ptr [0x5b2608]
004a1c4e pop edi
004a1c4f fadd dword ptr [esi + 0x84]
004a1c55 fstp dword ptr [esi + 0x84]
004a1c5b pop esi
004a1c5c pop ebp
004a1c5d pop ebx
004a1c5e add esp, 8
004a1c61 ret
004a1c62 fstp st(0)
004a1c64 pop edi
004a1c65 pop esi
004a1c66 pop ebp
004a1c67 pop ebx
004a1c68 add esp, 8
004a1c6b ret
004a1c6c nop
004a1c6d nop
004a1c6e nop
004a1c6f nop
004a1c70 push ecx
004a1c71 push esi
004a1c72 mov esi, dword ptr [esp + 0xc]
004a1c76 push esi
004a1c77 call 0x493980
004a1c7c fmul dword ptr [0x5b3284]
004a1c82 mov ecx, dword ptr [esp + 0x14]
004a1c86 add esp, 4
004a1c89 fsubr dword ptr [0x5b24a8]
004a1c8f fmul dword ptr [ecx + 0xac]
004a1c95 fstp dword ptr [esp + 0xc]
004a1c99 fld dword ptr [ecx + 0x9c]
004a1c9f fcomp dword ptr [0x5b23f8]
004a1ca5 fld dword ptr [ecx + 0x9c]
004a1cab fnstsw ax
004a1cad test ah, 1
004a1cb0 je 0x4a1cb4
004a1cb2 fchs
004a1cb4 fld dword ptr [ecx + 0xa4]
004a1cba fcomp dword ptr [0x5b23f8]
004a1cc0 fld dword ptr [ecx + 0xa4]
004a1cc6 fnstsw ax
004a1cc8 test ah, 1
004a1ccb je 0x4a1ccf
004a1ccd fchs
004a1ccf fld st(1)
004a1cd1 fcomp st(1)
004a1cd3 fnstsw ax
004a1cd5 test ah, 0x41
004a1cd8 jne 0x4a1ce4
004a1cda fmul dword ptr [0x5b2468]
004a1ce0 fadd st(1)
004a1ce2 jmp 0x4a1cee
004a1ce4 fld st(1)
004a1ce6 fmul dword ptr [0x5b2468]
004a1cec faddp st(1)
004a1cee mov eax, dword ptr [esi + 0x760]
004a1cf4 pop esi
004a1cf5 fst dword ptr [esp + 0xc]
004a1cf9 mov edx, dword ptr [eax + 0x1c0]
004a1cff fld dword ptr [esp + 8]
004a1d03 fdiv dword ptr [edx*4 + 0x5d0f58]
004a1d0a fsubr dword ptr [esp + 8]
004a1d0e fstp dword ptr [esp]
004a1d12 fcom dword ptr [esp + 8]
004a1d16 fnstsw ax
004a1d18 test ah, 0x41
004a1d1b jne 0x4a1d3f
004a1d1d fld st(0)
004a1d1f fsub dword ptr [esp + 8]
004a1d23 fld dword ptr [ecx + 0xb8]
004a1d29 fmul dword ptr [0x5b2600]
004a1d2f faddp st(1)
004a1d31 fmul dword ptr [0x5b2468]
004a1d37 fstp dword ptr [ecx + 0xb8]
004a1d3d jmp 0x4a1d49
004a1d3f mov dword ptr [ecx + 0xb8], 0
004a1d49 fld dword ptr [ecx + 0xb8]
004a1d4f fmul dword ptr [0x5b49b4]
004a1d55 fcom dword ptr [0x5b24a8]
004a1d5b fnstsw ax
004a1d5d test ah, 0x41
004a1d60 jne 0x4a1d6a
004a1d62 fstp st(0)
004a1d64 fld dword ptr [0x5b24a8]
004a1d6a fstp dword ptr [ecx + 0xb8]
004a1d70 fcom dword ptr [0x5b23f8]
004a1d76 fnstsw ax
004a1d78 test ah, 1
004a1d7b je 0x4a1d7f
004a1d7d fchs
