0049a8ae mov eax, 1
0049a8b3 cmp ecx, eax
0049a8b5 jle 0x49a8c0
0049a8b7 mov word ptr [esi + 0x418], ax
0049a8be jmp 0x49a8c9
0049a8c0 mov word ptr [esi + 0x418], 0
0049a8c9 push esi
0049a8ca call 0x49ae30
0049a8cf mov ecx, dword ptr [esp + 0x10c]
0049a8d6 lea eax, [esp + 0x40]
0049a8da push eax
0049a8db push ecx
0049a8dc push esi
0049a8dd call 0x49a900
0049a8e2 fld dword ptr [esp + 0x50]

0049c8f8 fld dword ptr [eax + 0x118]
0049c8fe fmul dword ptr [0x5b3ca0]
0049c904 fstp dword ptr [eax + 0x118]
0049c90a mov eax, dword ptr [esi + 0x760]
0049c910 fld dword ptr [eax + 0x44]
0049c913 fmul dword ptr [0x5b3060]
0049c919 fstp dword ptr [eax + 0x44]
0049c91c mov eax, dword ptr [esi + 0x760]
0049c922 fld dword ptr [eax + 0x10c]
0049c928 fmul dword ptr [0x5b3060]
0049c92e fstp dword ptr [eax + 0x10c]
0049c934 mov eax, dword ptr [esi + 0x760]
0049c93a fld dword ptr [eax + 0x110]
0049c940 fmul dword ptr [0x5b3060]
0049c946 fstp dword ptr [eax + 0x110]

0049c904 fstp dword ptr [eax + 0x118]
0049c90a mov eax, dword ptr [esi + 0x760]
0049c910 fld dword ptr [eax + 0x44]
0049c913 fmul dword ptr [0x5b3060]
0049c919 fstp dword ptr [eax + 0x44]
0049c91c mov eax, dword ptr [esi + 0x760]
0049c922 fld dword ptr [eax + 0x10c]
0049c928 fmul dword ptr [0x5b3060]
0049c92e fstp dword ptr [eax + 0x10c]
0049c934 mov eax, dword ptr [esi + 0x760]
0049c93a fld dword ptr [eax + 0x110]
0049c940 fmul dword ptr [0x5b3060]
0049c946 fstp dword ptr [eax + 0x110]
0049c94c mov eax, dword ptr [esi + 0x760]
0049c952 fld dword ptr [eax + 0x120]

0049c910 fld dword ptr [eax + 0x44]
0049c913 fmul dword ptr [0x5b3060]
0049c919 fstp dword ptr [eax + 0x44]
0049c91c mov eax, dword ptr [esi + 0x760]
0049c922 fld dword ptr [eax + 0x10c]
0049c928 fmul dword ptr [0x5b3060]
0049c92e fstp dword ptr [eax + 0x10c]
0049c934 mov eax, dword ptr [esi + 0x760]
0049c93a fld dword ptr [eax + 0x110]
0049c940 fmul dword ptr [0x5b3060]
0049c946 fstp dword ptr [eax + 0x110]
0049c94c mov eax, dword ptr [esi + 0x760]
0049c952 fld dword ptr [eax + 0x120]
0049c958 fmul dword ptr [0x5b3060]
0049c95e fstp dword ptr [eax + 0x120]

0049c919 fstp dword ptr [eax + 0x44]
0049c91c mov eax, dword ptr [esi + 0x760]
0049c922 fld dword ptr [eax + 0x10c]
0049c928 fmul dword ptr [0x5b3060]
0049c92e fstp dword ptr [eax + 0x10c]
0049c934 mov eax, dword ptr [esi + 0x760]
0049c93a fld dword ptr [eax + 0x110]
0049c940 fmul dword ptr [0x5b3060]
0049c946 fstp dword ptr [eax + 0x110]
0049c94c mov eax, dword ptr [esi + 0x760]
0049c952 fld dword ptr [eax + 0x120]
0049c958 fmul dword ptr [0x5b3060]
0049c95e fstp dword ptr [eax + 0x120]
0049c964 mov eax, dword ptr [esi + 0x760]
0049c96a fld dword ptr [eax + 0x124]

0049d117 jne 0x49d166
0049d119 fld dword ptr [eax + 0xc4]
0049d11f fmul dword ptr [0x5b3284]
0049d125 mov ecx, dword ptr [esi + 0x760]
0049d12b fadd dword ptr [0x5b24a8]
0049d131 fld dword ptr [eax + 0xc0]
0049d137 fmul dword ptr [0x5b3284]
0049d13d fadd dword ptr [0x5b24a8]
0049d143 fmul dword ptr [ecx + 0x10c]
0049d149 fstp dword ptr [ecx + 0x10c]
0049d14f mov eax, dword ptr [esi + 0x760]
0049d155 fmul dword ptr [eax + 0x110]
0049d15b fstp dword ptr [eax + 0x110]
0049d161 jmp 0x49d200
0049d166 cmp cx, 9

0049d119 fld dword ptr [eax + 0xc4]
0049d11f fmul dword ptr [0x5b3284]
0049d125 mov ecx, dword ptr [esi + 0x760]
0049d12b fadd dword ptr [0x5b24a8]
0049d131 fld dword ptr [eax + 0xc0]
0049d137 fmul dword ptr [0x5b3284]
0049d13d fadd dword ptr [0x5b24a8]
0049d143 fmul dword ptr [ecx + 0x10c]
0049d149 fstp dword ptr [ecx + 0x10c]
0049d14f mov eax, dword ptr [esi + 0x760]
0049d155 fmul dword ptr [eax + 0x110]
0049d15b fstp dword ptr [eax + 0x110]
0049d161 jmp 0x49d200
0049d166 cmp cx, 9
0049d16a jne 0x49d200

0049d125 mov ecx, dword ptr [esi + 0x760]
0049d12b fadd dword ptr [0x5b24a8]
0049d131 fld dword ptr [eax + 0xc0]
0049d137 fmul dword ptr [0x5b3284]
0049d13d fadd dword ptr [0x5b24a8]
0049d143 fmul dword ptr [ecx + 0x10c]
0049d149 fstp dword ptr [ecx + 0x10c]
0049d14f mov eax, dword ptr [esi + 0x760]
0049d155 fmul dword ptr [eax + 0x110]
0049d15b fstp dword ptr [eax + 0x110]
0049d161 jmp 0x49d200
0049d166 cmp cx, 9
0049d16a jne 0x49d200
0049d170 mov ecx, dword ptr [esi + 0x760]
0049d176 fld dword ptr [ecx + 0xf4]

0049d12b fadd dword ptr [0x5b24a8]
0049d131 fld dword ptr [eax + 0xc0]
0049d137 fmul dword ptr [0x5b3284]
0049d13d fadd dword ptr [0x5b24a8]
0049d143 fmul dword ptr [ecx + 0x10c]
0049d149 fstp dword ptr [ecx + 0x10c]
0049d14f mov eax, dword ptr [esi + 0x760]
0049d155 fmul dword ptr [eax + 0x110]
0049d15b fstp dword ptr [eax + 0x110]
0049d161 jmp 0x49d200
0049d166 cmp cx, 9
0049d16a jne 0x49d200
0049d170 mov ecx, dword ptr [esi + 0x760]
0049d176 fld dword ptr [ecx + 0xf4]
0049d17c fmul dword ptr [0x5b2600]

0049d2d8 fstp dword ptr [esp + 0x20]
0049d2dc fld dword ptr [esp + 0x20]
0049d2e0 fadd st(1)
0049d2e2 fadd dword ptr [0x5b2600]
0049d2e8 fmul dword ptr [0x5b2694]
0049d2ee fdivr dword ptr [eax + 0x90]
0049d2f4 fstp dword ptr [eax + 0x90]
0049d2fa mov eax, dword ptr [esi + 0x760]
0049d300 fmul dword ptr [eax + 0x10c]
0049d306 fstp dword ptr [eax + 0x10c]
0049d30c mov eax, dword ptr [esi + 0x760]
0049d312 fld dword ptr [esp + 0x20]
0049d316 fmul dword ptr [eax + 0x110]
0049d31c fstp dword ptr [eax + 0x110]
0049d322 mov ecx, dword ptr [esi + 0x558]

0049d2dc fld dword ptr [esp + 0x20]
0049d2e0 fadd st(1)
0049d2e2 fadd dword ptr [0x5b2600]
0049d2e8 fmul dword ptr [0x5b2694]
0049d2ee fdivr dword ptr [eax + 0x90]
0049d2f4 fstp dword ptr [eax + 0x90]
0049d2fa mov eax, dword ptr [esi + 0x760]
0049d300 fmul dword ptr [eax + 0x10c]
0049d306 fstp dword ptr [eax + 0x10c]
0049d30c mov eax, dword ptr [esi + 0x760]
0049d312 fld dword ptr [esp + 0x20]
0049d316 fmul dword ptr [eax + 0x110]
0049d31c fstp dword ptr [eax + 0x110]
0049d322 mov ecx, dword ptr [esi + 0x558]
0049d328 mov eax, dword ptr [esi + 0x760]

0049d2e8 fmul dword ptr [0x5b2694]
0049d2ee fdivr dword ptr [eax + 0x90]
0049d2f4 fstp dword ptr [eax + 0x90]
0049d2fa mov eax, dword ptr [esi + 0x760]
0049d300 fmul dword ptr [eax + 0x10c]
0049d306 fstp dword ptr [eax + 0x10c]
0049d30c mov eax, dword ptr [esi + 0x760]
0049d312 fld dword ptr [esp + 0x20]
0049d316 fmul dword ptr [eax + 0x110]
0049d31c fstp dword ptr [eax + 0x110]
0049d322 mov ecx, dword ptr [esi + 0x558]
0049d328 mov eax, dword ptr [esi + 0x760]
0049d32e fild dword ptr [ecx + 0xf0]
0049d334 fmul dword ptr [0x5b253c]
0049d33a fadd dword ptr [eax + 0x80]

0049d2ee fdivr dword ptr [eax + 0x90]
0049d2f4 fstp dword ptr [eax + 0x90]
0049d2fa mov eax, dword ptr [esi + 0x760]
0049d300 fmul dword ptr [eax + 0x10c]
0049d306 fstp dword ptr [eax + 0x10c]
0049d30c mov eax, dword ptr [esi + 0x760]
0049d312 fld dword ptr [esp + 0x20]
0049d316 fmul dword ptr [eax + 0x110]
0049d31c fstp dword ptr [eax + 0x110]
0049d322 mov ecx, dword ptr [esi + 0x558]
0049d328 mov eax, dword ptr [esi + 0x760]
0049d32e fild dword ptr [ecx + 0xf0]
0049d334 fmul dword ptr [0x5b253c]
0049d33a fadd dword ptr [eax + 0x80]
0049d340 fstp dword ptr [eax + 0x80]

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
