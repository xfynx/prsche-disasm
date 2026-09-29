0049c760 jge 0x49c766
0049c762 xor edi, edi
0049c764 jmp 0x49c769
0049c766 mov edi, dword ptr [edi + 4]
0049c769 push eax
0049c76a mov eax, dword ptr [esi + 0x760]
0049c770 push edi
0049c771 push eax
0049c772 call 0x5323e0
0049c777 add esp, 0xc
0049c77a xor bl, bl
0049c77c mov eax, dword ptr [0x628c70]
0049c781 test eax, eax
0049c783 je 0x49c797
0049c785 mov eax, dword ptr [eax + 0x10]
0049c788 test eax, eax
0049c78a je 0x49c797
0049c78c mov ecx, dword ptr [eax]
0049c78e push ecx
0049c78f call 0x5322c0
0049c794 add esp, 4
0049c797 test bl, bl
0049c799 je 0x49c82f
0049c79f mov edx, dword ptr [esi + 0x558]
0049c7a5 mov eax, dword ptr [0x65b2ac]
0049c7aa add edx, 0x268
0049c7b0 lea ecx, [esp + 0xc]
0049c7b4 push edx
0049c7b5 push eax
0049c7b6 push 0x5d0cc0
0049c7bb push ecx
0049c7bc call 0x5a0fbf
0049c7c1 lea edx, [esp + 0x1c]
0049c7c5 push 0
0049c7c7 push edx
0049c7c8 call 0x59d9b0
0049c7cd mov edi, eax
0049c7cf add esp, 0x18
0049c7d2 test edi, edi
0049c7d4 jne 0x49c7fb
0049c7d6 mov eax, dword ptr [0x65b2ac]
0049c7db lea ecx, [esp + 0xc]
0049c7df push eax
0049c7e0 push 0x5d0cb0
0049c7e5 push ecx
0049c7e6 call 0x5a0fbf
0049c7eb lea edx, [esp + 0x18]
0049c7ef push edi
0049c7f0 push edx
0049c7f1 call 0x59d8e0
0049c7f6 add esp, 0x14
0049c7f9 mov edi, eax
0049c7fb mov eax, dword ptr [esi + 0x760]
0049c801 push 0x1c4
0049c806 push 0
0049c808 push eax
0049c809 call 0x53c290
0049c80e lea ecx, [esp + 0x18]
0049c812 push ecx
0049c813 call 0x561ba0
0049c818 mov edx, dword ptr [esi + 0x760]
0049c81e push eax
0049c81f push edi
0049c820 push edx
0049c821 call 0x5323e0
0049c826 push edi
0049c827 call 0x531f90
0049c82c add esp, 0x20
0049c82f mov eax, dword ptr [esi + 0x760]
0049c835 mov edx, dword ptr [eax + 0x50]
0049c838 add edx, 2
0049c83b mov dword ptr [eax + 0x50], edx
0049c83e mov eax, dword ptr [esi + 0x760]
0049c844 fld dword ptr [eax + 0x90]
0049c84a fmul dword ptr [0x5b4a28]
0049c850 fstp dword ptr [eax + 0x90]
0049c856 mov eax, dword ptr [esi + 0x760]
0049c85c fld dword ptr [eax + 0x58]
0049c85f fmul dword ptr [0x5b3ca0]
0049c865 fstp dword ptr [eax + 0x58]
0049c868 mov eax, dword ptr [esi + 0x760]
0049c86e fld dword ptr [eax + 0x5c]
0049c871 fmul dword ptr [0x5b3ca0]
0049c877 fstp dword ptr [eax + 0x5c]
0049c87a mov eax, dword ptr [esi + 0x760]
0049c880 fld dword ptr [eax + 0x98]
0049c886 fmul dword ptr [0x5b3ca0]
0049c88c fstp dword ptr [eax + 0x98]
0049c892 mov eax, dword ptr [esi + 0x760]
0049c898 fld dword ptr [eax + 0xf0]
0049c89e fmul dword ptr [0x5b3ca0]
0049c8a4 fstp dword ptr [eax + 0xf0]
0049c8aa mov eax, dword ptr [esi + 0x760]
0049c8b0 fld dword ptr [eax + 0xf8]
0049c8b6 fmul dword ptr [0x5b3ca0]
0049c8bc fstp dword ptr [eax + 0xf8]
0049c8c2 mov eax, dword ptr [esi + 0x760]
0049c8c8 fld dword ptr [eax + 0x108]
0049c8ce fmul dword ptr [0x5b3ca0]
0049c8d4 fstp dword ptr [eax + 0x108]
0049c8da mov eax, dword ptr [esi + 0x760]
0049c8e0 fld dword ptr [eax + 0x114]
0049c8e6 fmul dword ptr [0x5b3ca0]
0049c8ec fstp dword ptr [eax + 0x114]
0049c8f2 mov eax, dword ptr [esi + 0x760]
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
0049c94c mov eax, dword ptr [esi + 0x760]
0049c952 fld dword ptr [eax + 0x120]
0049c958 fmul dword ptr [0x5b3060]
0049c95e fstp dword ptr [eax + 0x120]
0049c964 mov eax, dword ptr [esi + 0x760]
0049c96a fld dword ptr [eax + 0x124]
0049c970 fmul dword ptr [0x5b3060]
0049c976 fstp dword ptr [eax + 0x124]
0049c97c mov eax, dword ptr [esi + 0x760]
0049c982 fld dword ptr [eax + 0x128]
0049c988 fmul dword ptr [0x5b3060]
0049c98e fstp dword ptr [eax + 0x128]
0049c994 mov eax, dword ptr [esi + 0x760]
0049c99a fld dword ptr [eax + 0x12c]
0049c9a0 fmul dword ptr [0x5b3060]
0049c9a6 fstp dword ptr [eax + 0x12c]
0049c9ac mov eax, dword ptr [esi + 0x558]
0049c9b2 mov ecx, dword ptr [eax + 0x518]
0049c9b8 test ecx, ecx
0049c9ba je 0x49ca16
0049c9bc mov eax, dword ptr [esi + 0x760]
0049c9c2 fld dword ptr [eax + 0x44]
0049c9c5 fmul dword ptr [0x5b24e8]
0049c9cb fstp dword ptr [eax + 0x44]
0049c9ce mov eax, dword ptr [esi + 0x760]
0049c9d4 fld dword ptr [eax + 0x114]
0049c9da fmul dword ptr [0x5b4a24]
0049c9e0 fstp dword ptr [eax + 0x114]
0049c9e6 mov eax, dword ptr [esi + 0x760]
0049c9ec fld dword ptr [eax + 0x118]
0049c9f2 fmul dword ptr [0x5b4a24]
0049c9f8 fstp dword ptr [eax + 0x118]
0049c9fe mov eax, dword ptr [esi + 0x760]
0049ca04 fld dword ptr [eax + 0xf4]
0049ca0a fmul dword ptr [0x5b3f64]
0049ca10 fstp dword ptr [eax + 0xf4]
0049ca16 push esi
0049ca17 call 0x49cb50
0049ca1c add esp, 4
0049ca1f pop edi
0049ca20 pop esi
0049ca21 pop ebx
0049ca22 add esp, 0x64
0049ca25 ret
0049ca26 nop
0049ca27 nop
0049ca28 nop
0049ca29 nop
0049ca2a nop
0049ca2b nop
0049ca2c nop
0049ca2d nop
0049ca2e nop
0049ca2f nop
