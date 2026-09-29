0049d340 fstp dword ptr [eax + 0x80]
0049d346 mov eax, 0x60
0049d34b cmp eax, 0x64
0049d34e je 0x49d370
0049d350 mov edx, dword ptr [esi + 0x760]
0049d356 lea ecx, [eax + edx]
0049d359 mov edx, dword ptr [esi + 0x558]
0049d35f fild dword ptr [eax + edx + 0x94]
0049d366 fmul dword ptr [0x5b253c]
0049d36c fadd dword ptr [ecx]
0049d36e fstp dword ptr [ecx]
0049d370 add eax, 4
0049d373 cmp eax, 0x80
0049d378 jl 0x49d34b
0049d37a mov eax, dword ptr [esi + 0x558]
0049d380 mov ecx, dword ptr [esi + 0x760]
0049d386 mov edx, dword ptr [eax + 0x11c]
0049d38c mov eax, 0x51eb851f
0049d391 imul edx
0049d393 sar edx, 5
0049d396 mov eax, edx
0049d398 shr eax, 0x1f
0049d39b add edx, eax
0049d39d mov dword ptr [esp + 0x20], edx
0049d3a1 fild dword ptr [esp + 0x20]
0049d3a5 fmul dword ptr [0x5b253c]
0049d3ab fsub dword ptr [0x5b23f0]
0049d3b1 fmul dword ptr [0x5b23f0]
0049d3b7 fadd dword ptr [ecx + 0x108]
0049d3bd fstp dword ptr [ecx + 0x108]
0049d3c3 mov ecx, dword ptr [esi + 0x558]
0049d3c9 mov eax, dword ptr [esi + 0x760]
0049d3cf fild dword ptr [ecx + 0x128]
0049d3d5 fmul dword ptr [0x5b253c]
0049d3db fadd dword ptr [eax + 0x100]
0049d3e1 fstp dword ptr [eax + 0x100]
0049d3e7 mov edx, dword ptr [esi + 0x558]
0049d3ed mov eax, dword ptr [esi + 0x760]
0049d3f3 fild dword ptr [edx + 0x134]
0049d3f9 fmul dword ptr [0x5b253c]
0049d3ff fadd dword ptr [0x5b2580]
0049d405 fmul dword ptr [eax + 0x11c]
0049d40b fmul dword ptr [0x5b2680]
0049d411 fstp dword ptr [eax + 0x11c]
0049d417 mov eax, dword ptr [esi + 0x760]
0049d41d fld dword ptr [eax + 0x11c]
0049d423 fadd dword ptr [0x5b368c]
0049d429 fmul dword ptr [0x5b49b4]
0049d42f fmul dword ptr [eax + 0xf4]
0049d435 fstp dword ptr [eax + 0xf4]
0049d43b mov ecx, dword ptr [esi + 0x558]
0049d441 mov eax, dword ptr [esi + 0x760]
0049d447 fild dword ptr [ecx + 0x134]
0049d44d fmul dword ptr [0x5b253c]
0049d453 fsubr dword ptr [0x5b24a8]
0049d459 fmul dword ptr [0x5b2694]
0049d45f fadd dword ptr [eax + 0x114]
0049d465 fstp dword ptr [eax + 0x114]
0049d46b mov edx, dword ptr [esi + 0x558]
0049d471 mov eax, dword ptr [esi + 0x760]
0049d477 fild dword ptr [edx + 0x134]
0049d47d fmul dword ptr [0x5b253c]
0049d483 fsubr dword ptr [0x5b24a8]
0049d489 fmul dword ptr [0x5b2694]
0049d48f fadd dword ptr [eax + 0x118]
0049d495 fstp dword ptr [eax + 0x118]
0049d49b mov eax, dword ptr [esi + 0x760]
0049d4a1 fld dword ptr [eax + 0x11c]
0049d4a7 fadd dword ptr [0x5b24a8]
0049d4ad fmul dword ptr [0x5b23f0]
0049d4b3 fdivr dword ptr [eax + 0x12c]
0049d4b9 fstp dword ptr [eax + 0x12c]
0049d4bf mov ecx, dword ptr [esi + 0x558]
0049d4c5 mov eax, dword ptr [esi + 0x760]
0049d4cb fild dword ptr [ecx + 0x124]
0049d4d1 fmul dword ptr [0x5b253c]
0049d4d7 fmul dword ptr [0x5b3060]
0049d4dd fadd dword ptr [eax + 0x124]
0049d4e3 fstp dword ptr [eax + 0x124]
0049d4e9 mov edx, dword ptr [esi + 0x558]
0049d4ef mov eax, dword ptr [esi + 0x760]
0049d4f5 fild dword ptr [edx + 0x124]
0049d4fb fmul dword ptr [0x5b253c]
0049d501 fmul dword ptr [0x5b3060]
0049d507 fadd dword ptr [0x5b24a8]
0049d50d fmul dword ptr [eax + 0xf4]
0049d513 fstp dword ptr [eax + 0xf4]
0049d519 mov ecx, dword ptr [esi + 0x558]
0049d51f mov eax, dword ptr [esi + 0x760]
0049d525 fild dword ptr [ecx + 0x124]
0049d52b fmul dword ptr [0x5b253c]
0049d531 fmul dword ptr [0x5b3060]
0049d537 fadd dword ptr [0x5b24a8]
0049d53d fdivr dword ptr [eax + 0x12c]
0049d543 fstp dword ptr [eax + 0x12c]
0049d549 mov edx, dword ptr [esi + 0x558]
0049d54f mov eax, dword ptr [esi + 0x760]
0049d555 fild dword ptr [edx + 0x120]
0049d55b fmul dword ptr [0x5b253c]
0049d561 fmul dword ptr [0x5b3060]
0049d567 fstp dword ptr [eax + 0x120]
0049d56d mov eax, dword ptr [esi + 0x760]
0049d573 fld dword ptr [eax + 0x120]
0049d579 fmul dword ptr [0x5b2460]
0049d57f fadd dword ptr [0x5b24a8]
0049d585 fdivr dword ptr [eax + 0x12c]
0049d58b fstp dword ptr [eax + 0x12c]
0049d591 mov eax, dword ptr [esi + 0x558]
0049d597 fild dword ptr [eax + 0x13c]
0049d59d fmul dword ptr [0x5b253c]
0049d5a3 fmul dword ptr [0x5b3f30]
0049d5a9 fild dword ptr [eax + 0x140]
0049d5af fmul dword ptr [0x5b253c]
0049d5b5 fmul dword ptr [0x5b3f30]
0049d5bb fld st(1)
0049d5bd fcomp dword ptr [0x5b24a8]
0049d5c3 fnstsw ax
0049d5c5 test ah, 1
0049d5c8 je 0x49d5d4
0049d5ca fxch st(1)
0049d5cc fmul dword ptr [0x5b3354]
0049d5d2 fxch st(1)
0049d5d4 fcom dword ptr [0x5b24a8]
0049d5da fnstsw ax
0049d5dc test ah, 1
0049d5df je 0x49d5e7
0049d5e1 fmul dword ptr [0x5b3354]
0049d5e7 fadd st(1)
0049d5e9 mov eax, dword ptr [esi + 0x760]
0049d5ef mov ecx, 0x60
0049d5f4 fld st(0)
0049d5f6 fadd dword ptr [0x5b2608]
0049d5fc fmul dword ptr [eax + 0xf4]
0049d602 fmul dword ptr [0x5b49b4]
0049d608 fstp dword ptr [eax + 0xf4]
0049d60e fxch st(1)
0049d610 fadd st(0), st(0)
0049d612 mov eax, dword ptr [esi + 0x760]
0049d618 fdiv st(1)
0049d61a fadd dword ptr [0x5b24a8]
0049d620 fmul dword ptr [0x5b23f0]
0049d626 fmul dword ptr [eax + 0xf0]
0049d62c fstp dword ptr [eax + 0xf0]
0049d632 fstp st(0)
0049d634 mov eax, dword ptr [esi + 0x760]
0049d63a add ecx, 4
0049d63d cmp ecx, 0x80
0049d643 fld dword ptr [eax + 0x80]
0049d649 fmul dword ptr [eax + ecx - 4]
0049d64d fmul dword ptr [0x5b26f0]
0049d653 fdiv dword ptr [eax + 0x148]
0049d659 fstp dword ptr [eax + ecx - 4]
0049d65d jl 0x49d634
0049d65f mov edx, dword ptr [esi + 0x760]
0049d665 mov dword ptr [esp + 0x20], 0
0049d66d mov eax, dword ptr [edx + 0x50]
0049d670 test eax, eax
0049d672 jle 0x49d785
0049d678 mov ecx, 0x190
0049d67d fld dword ptr [edx + ecx - 0x130]
0049d684 fcomp dword ptr [0x5b23f8]
0049d68a fnstsw ax
0049d68c test ah, 0x40
0049d68f jne 0x49d6a4
0049d691 fld dword ptr [0x5b24a8]
0049d697 fdiv dword ptr [edx + ecx - 0x130]
0049d69e fstp dword ptr [edx + ecx - 0x20]
0049d6a2 jmp 0x49d6ac
0049d6a4 mov dword ptr [edx + ecx - 0x20], 0x3dcccccd
0049d6ac mov eax, dword ptr [esi + 0x760]
0049d6b2 mov ebp, 0x5d0cf0
0049d6b7 fld dword ptr [eax + ecx - 0x130]
0049d6be fdiv dword ptr [eax + 0x40]
0049d6c1 fstp dword ptr [eax + ecx]
0049d6c4 mov edx, dword ptr [esi + 0x760]
0049d6ca fld dword ptr [ecx + edx]
0049d6cd fmul dword ptr [0x5b49b4]
0049d6d3 lea eax, [ecx + edx]
0049d6d6 fstp dword ptr [eax]
0049d6d8 mov eax, dword ptr [esi + 0x760]
0049d6de fld dword ptr [eax + 0x58]
0049d6e1 fmul dword ptr [eax + ecx]
0049d6e4 fstp dword ptr [eax + ecx]
0049d6e7 mov edx, dword ptr [esi + 0x558]
0049d6ed lea edi, [edx + 0x17c]
0049d6f3 mov bl, byte ptr [edi]
0049d6f5 mov al, bl
0049d6f7 cmp bl, byte ptr [ebp]
0049d6fa jne 0x49d718
0049d6fc test al, al
0049d6fe je 0x49d714
0049d700 mov bl, byte ptr [edi + 1]
0049d703 mov al, bl
0049d705 cmp bl, byte ptr [ebp + 1]
0049d708 jne 0x49d718
0049d70a add edi, 2
0049d70d add ebp, 2
0049d710 test al, al
0049d712 jne 0x49d6f3
0049d714 xor eax, eax
0049d716 jmp 0x49d71d
0049d718 sbb eax, eax
0049d71a sbb eax, -1
0049d71d test eax, eax
0049d71f jne 0x49d733
0049d721 mov eax, dword ptr [esi + 0x760]
0049d727 add eax, ecx
0049d729 fld dword ptr [eax]
0049d72b fmul dword ptr [0x5b2480]
0049d731 jmp 0x49d74c
0049d733 mov eax, dword ptr [edx + 0xc]
0049d736 test eax, eax
0049d738 jne 0x49d74e
0049d73a mov edx, dword ptr [esi + 0x760]
0049d740 fld dword ptr [ecx + edx]
0049d743 fmul dword ptr [0x5b3f90]
0049d749 lea eax, [ecx + edx]
0049d74c fstp dword ptr [eax]
0049d74e mov eax, dword ptr [esi + 0x760]
0049d754 add ecx, 4
0049d757 fld dword ptr [eax + ecx - 0x24]
0049d75b fmul dword ptr [eax + 0x94]
0049d761 fdivr dword ptr [0x5b24a8]
0049d767 fstp dword ptr [eax + ecx - 0x44]
0049d76b mov edx, dword ptr [esi + 0x760]
0049d771 mov eax, dword ptr [esp + 0x20]
0049d775 inc eax
0049d776 mov edi, dword ptr [edx + 0x50]
0049d779 mov dword ptr [esp + 0x20], eax
0049d77d cmp eax, edi
0049d77f jl 0x49d67d
0049d785 mov eax, dword ptr [esi + 0x558]
0049d78b mov edi, 0x5d0cf0
0049d790 lea ebp, [eax + 0x17c]
0049d796 mov eax, ebp
0049d798 mov dl, byte ptr [eax]
0049d79a mov bl, byte ptr [edi]
0049d79c mov cl, dl
0049d79e cmp dl, bl
0049d7a0 jne 0x49d7c0
0049d7a2 test cl, cl
0049d7a4 je 0x49d7bc
0049d7a6 mov dl, byte ptr [eax + 1]
0049d7a9 mov bl, byte ptr [edi + 1]
0049d7ac mov cl, dl
0049d7ae cmp dl, bl
0049d7b0 jne 0x49d7c0
0049d7b2 add eax, 2
0049d7b5 add edi, 2
0049d7b8 test cl, cl
0049d7ba jne 0x49d798
0049d7bc xor eax, eax
0049d7be jmp 0x49d7c5
0049d7c0 sbb eax, eax
0049d7c2 sbb eax, -1
0049d7c5 test eax, eax
0049d7c7 jne 0x49d813
0049d7c9 mov eax, dword ptr [esi + 0x760]
0049d7cf fld dword ptr [eax + 0xf4]
0049d7d5 fmul dword ptr [0x5b2480]
0049d7db fstp dword ptr [eax + 0xf4]
0049d7e1 mov eax, dword ptr [esi + 0x760]
0049d7e7 fld dword ptr [eax + 0x12c]
0049d7ed fmul dword ptr [0x5b3f00]
0049d7f3 fstp dword ptr [eax + 0x12c]
0049d7f9 mov eax, dword ptr [esi + 0x760]
0049d7ff fld dword ptr [eax + 0x118]
0049d805 fmul dword ptr [0x5b3354]
0049d80b fstp dword ptr [eax + 0x118]
0049d811 jmp 0x49d87b
0049d813 mov edi, 0x5d0ce8
0049d818 mov eax, ebp
0049d81a mov dl, byte ptr [eax]
0049d81c mov bl, byte ptr [edi]
0049d81e mov cl, dl
0049d820 cmp dl, bl
0049d822 jne 0x49d842
0049d824 test cl, cl
0049d826 je 0x49d83e
0049d828 mov dl, byte ptr [eax + 1]
0049d82b mov bl, byte ptr [edi + 1]
0049d82e mov cl, dl
0049d830 cmp dl, bl
0049d832 jne 0x49d842
0049d834 add eax, 2
0049d837 add edi, 2
0049d83a test cl, cl
0049d83c jne 0x49d81a
0049d83e xor eax, eax
0049d840 jmp 0x49d847
0049d842 sbb eax, eax
0049d844 sbb eax, -1
0049d847 test eax, eax
0049d849 jne 0x49d87b
0049d84b mov eax, dword ptr [esi + 0x760]
0049d851 fld dword ptr [eax + 0xf4]
0049d857 fmul dword ptr [0x5b246c]
0049d85d fstp dword ptr [eax + 0xf4]
0049d863 mov eax, dword ptr [esi + 0x760]
0049d869 fld dword ptr [eax + 0x12c]
0049d86f fmul dword ptr [0x5b4a34]
0049d875 fstp dword ptr [eax + 0x12c]
0049d87b mov edi, dword ptr [esi + 0x760]
0049d881 mov ebx, dword ptr [edi + 0x50]
0049d884 fld dword ptr [edi + ebx*4 + 0x5c]
0049d888 fmul dword ptr [edi + 0x90]
0049d88e call 0x5a0f98
0049d893 mov dword ptr [esp + 0x20], eax
0049d897 fild dword ptr [esp + 0x20]
0049d89b fld dword ptr [edi + 0x94]
0049d8a1 fst dword ptr [esp + 0x20]
0049d8a5 fcomp st(1)
0049d8a7 fnstsw ax
0049d8a9 test ah, 0x41
0049d8ac je 0x49d8b4
0049d8ae fstp st(0)
0049d8b0 fld dword ptr [esp + 0x20]
0049d8b4 fld dword ptr [0x5b23f8]
0049d8ba fcomp st(1)
0049d8bc fnstsw ax
0049d8be test ah, 0x41
0049d8c1 jne 0x49d8cb
0049d8c3 fstp st(0)
0049d8c5 fld dword ptr [0x5b23f8]
0049d8cb fld st(0)
0049d8cd fmul dword ptr [0x5b4a30]
0049d8d3 call 0x5a0f98
0049d8d8 fld dword ptr [edi + eax*4 + 0x9c]
0049d8df lea ecx, [eax + eax*4]
0049d8e2 fld dword ptr [edi + 0x90]
0049d8e8 lea ecx, [ecx + ecx*4]
0049d8eb lea ecx, [ecx + ecx*4]
0049d8ee shl ecx, 2
0049d8f1 mov dword ptr [esp + 0x20], ecx
0049d8f5 fild dword ptr [esp + 0x20]
0049d8f9 fsubr st(3)
0049d8fb fmul dword ptr [0x5b4a30]
0049d901 fld dword ptr [edi + eax*4 + 0xa0]
0049d908 fsub st(3)
0049d90a fmulp st(1)
0049d90c fadd st(2)
0049d90e fmul dword ptr [edi + ebx*4 + 0x18c]
0049d915 fld st(1)
0049d917 fmul dword ptr [edi + 0x90]
0049d91d fmul st(2)
0049d91f fdivp st(1)
0049d921 fstp dword ptr [edi + 0x1b0]
0049d927 mov eax, dword ptr [esi + 0x760]
0049d92d pop edi
0049d92e fstp st(0)
0049d930 fstp st(0)
0049d932 fstp st(0)
0049d934 fld dword ptr [eax + 0x44]
0049d937 fmul dword ptr [0x5b23f0]
0049d93d fstp dword ptr [eax + 0x1b4]
0049d943 mov eax, dword ptr [esi + 0x760]
0049d949 fld dword ptr [eax + 0x1b4]
0049d94f fmul dword ptr [0x5b4a2c]
0049d955 fstp dword ptr [eax + 0x1b4]
0049d95b mov eax, dword ptr [esi + 0x760]
0049d961 fld dword ptr [eax + 0x1b4]
0049d967 fmul dword ptr [0x5b26b0]
0049d96d fstp dword ptr [eax + 0x1b4]
0049d973 mov eax, dword ptr [esi + 0x760]
0049d979 fld dword ptr [0x5b24a8]
0049d97f fdiv dword ptr [eax + 0x1b4]
0049d985 fstp dword ptr [eax + 0x1b8]
0049d98b mov esi, dword ptr [esi + 0x760]
0049d991 fld dword ptr [0x5b24a8]
0049d997 fdiv dword ptr [esi + 0xf4]
0049d99d fstp dword ptr [esi + 0x1bc]
0049d9a3 pop esi
0049d9a4 pop ebp
0049d9a5 pop ebx
0049d9a6 add esp, 0xc
0049d9a9 ret
0049d9aa nop
0049d9ab nop
0049d9ac nop
0049d9ad nop
0049d9ae nop
0049d9af nop
0049d9b0 sub esp, 0x10
0049d9b3 mov eax, dword ptr [0x5e8ae8]
0049d9b8 push edi
0049d9b9 xor edi, edi
0049d9bb mov dword ptr [esp + 4], 0
0049d9c3 test eax, eax
0049d9c5 jle 0x49dad6
0049d9cb push ebx
0049d9cc push esi
0049d9cd mov esi, dword ptr [esp + 0x20]
0049d9d1 mov ebx, 0x5e8b34
0049d9d6 mov ecx, dword ptr [ebx]
0049d9d8 mov edx, dword ptr [esi]
0049d9da mov eax, dword ptr [ecx]
0049d9dc cmp eax, edx
0049d9de je 0x49dac3
0049d9e4 fld dword ptr [esi + 0xd60]
0049d9ea fcomp dword ptr [0x5b243c]
0049d9f0 fnstsw ax
0049d9f2 test ah, 0x41
0049d9f5 jne 0x49dac3
0049d9fb lea edx, [esp + 0x10]
0049d9ff lea eax, [esi + 0x330]
0049da05 push edx
0049da06 add ecx, 0x330
0049da0c push eax
0049da0d push ecx
0049da0e push 1
0049da10 call 0x532330
0049da15 lea ecx, [esp + 0x20]
0049da19 push ecx
0049da1a call 0x532b20
0049da1f fstp dword ptr [esp + 0x34]
0049da23 fld dword ptr [esi + 0xd60]
0049da29 fmul dword ptr [0x5b2680]
0049da2f add esp, 0x14
0049da32 fcomp dword ptr [esp + 0x20]
0049da36 fnstsw ax
0049da38 test ah, 0x41
0049da3b jne 0x49dac3
0049da41 fld dword ptr [esp + 0x20]
0049da45 fcomp dword ptr [0x5b2604]
0049da4b fnstsw ax
0049da4d test ah, 0x41
0049da50 jne 0x49dac3
0049da52 lea edx, [esp + 0x10]
0049da56 lea eax, [esp + 0x10]
0049da5a push edx
0049da5b push eax
0049da5c call 0x5328d0
0049da61 lea ecx, [esi + 0x37c]
0049da67 lea edx, [esp + 0x18]
0049da6b push ecx
0049da6c push edx
0049da6d call 0x532910
0049da72 fcom dword ptr [0x5b4a48]
0049da78 add esp, 0x10
0049da7b fnstsw ax
0049da7d test ah, 0x41
0049da80 jne 0x49dac1
0049da82 fld dword ptr [esp + 0x20]
0049da86 fmul dword ptr [0x5b2600]
0049da8c fdiv dword ptr [esi + 0xd60]
0049da92 fsubr dword ptr [0x5b24a8]
0049da98 fxch st(1)
0049da9a fsub dword ptr [0x5b4a48]
0049daa0 fmul dword ptr [0x5b4a44]
0049daa6 fmul dword ptr [0x5b23f0]
0049daac fmulp st(1)
0049daae fld dword ptr [esp + 0xc]
0049dab2 fcomp st(1)
0049dab4 fnstsw ax
0049dab6 test ah, 0x41
0049dab9 je 0x49dac1
0049dabb fstp dword ptr [esp + 0xc]
0049dabf jmp 0x49dac3
0049dac1 fstp st(0)
0049dac3 mov eax, dword ptr [0x5e8ae8]
0049dac8 inc edi
0049dac9 add ebx, 4
0049dacc cmp edi, eax
0049dace jl 0x49d9d6
0049dad4 pop esi
0049dad5 pop ebx
0049dad6 fld dword ptr [0x5b24a8]
0049dadc fsub dword ptr [esp + 4]
0049dae0 pop edi
0049dae1 add esp, 0x10
0049dae4 ret
0049dae5 nop
0049dae6 nop
0049dae7 nop
0049dae8 nop
0049dae9 nop
0049daea nop
0049daeb nop
0049daec nop
0049daed nop
0049daee nop
0049daef nop
0049daf0 sub esp, 0x14
0049daf3 mov eax, dword ptr [0x5d102c]
0049daf8 push ebx
0049daf9 imul eax, dword ptr [0x5d1028]
0049db00 mov ecx, eax
0049db02 mov dword ptr [0x655a0c], eax
0049db07 and ecx, 0xffff
0049db0d push esi
0049db0e shr eax, 8
0049db11 mov dword ptr [0x5d1028], ecx
0049db17 mov ecx, dword ptr [esp + 0x20]
0049db1b and eax, 0xffff
0049db20 push edi
0049db21 mov dword ptr [esp + 0x24], eax
0049db25 mov edx, dword ptr [ecx + 0x760]
0049db2b fild dword ptr [esp + 0x24]
0049db2f mov bl, byte ptr [ecx + 0xd82]
0049db35 xor edi, edi
0049db37 cmp bl, 2
0049db3a fmul dword ptr [0x5b2604]
0049db40 fmul dword ptr [edx + 0x94]
0049db46 fmul dword ptr [0x5b253c]
0049db4c fld dword ptr [edx + 0x94]
0049db52 fmul dword ptr [0x5b25e8]
0049db58 faddp st(1)
0049db5a fstp dword ptr [esp + 0x1c]
0049db5e fld dword ptr [edx + 0x94]
0049db64 fmul dword ptr [0x5b24e8]
0049db6a fstp dword ptr [esp + 0x18]
0049db6e jl 0x49dd0a
0049db74 fld dword ptr [ecx + 0xdc0]
0049db7a fcomp dword ptr [0x5b23f8]
0049db80 fld dword ptr [ecx + 0xdc0]
0049db86 fnstsw ax
0049db88 test ah, 1
0049db8b je 0x49db8f
0049db8d fchs
0049db8f mov esi, dword ptr [edx + 0x50]
0049db92 fstp dword ptr [esp + 0x14]
0049db96 fld dword ptr [edx + esi*4 + 0x168]
0049db9d fmul dword ptr [edx + 0x94]
0049dba3 fcomp dword ptr [edx + 0x90]
0049dba9 fnstsw ax
0049dbab test ah, 0x41
0049dbae jne 0x49dbb5
0049dbb0 mov edi, 1
0049dbb5 sub esi, edi
0049dbb7 lea edi, [esi - 1]
0049dbba movsx esi, bl
0049dbbd cmp esi, edi
0049dbbf jge 0x49dbca
0049dbc1 lea eax, [esi + 1]
0049dbc4 mov dword ptr [esp + 0x10], eax
0049dbc8 jmp 0x49dbce
0049dbca mov dword ptr [esp + 0x10], esi
0049dbce cmp bl, 2
0049dbd1 jle 0x49dbdc
0049dbd3 lea eax, [esi - 1]
0049dbd6 mov dword ptr [esp + 0xc], eax
0049dbda jmp 0x49dbe0
0049dbdc mov dword ptr [esp + 0xc], esi
0049dbe0 fld dword ptr [ecx + 0x35c]
0049dbe6 fld dword ptr [ecx + 0xd60]
0049dbec fcomp dword ptr [0x5b23f8]
0049dbf2 fnstsw ax
0049dbf4 test ah, 1
0049dbf7 je 0x49dbfb
0049dbf9 fchs
0049dbfb fld st(0)
0049dbfd fmul dword ptr [edx + esi*4 + 0x60]
0049dc01 fst dword ptr [esp + 0x24]
0049dc05 fmul dword ptr [0x5b2480]
0049dc0b fcomp dword ptr [ecx + 0xdb4]
0049dc11 fnstsw ax
0049dc13 test ah, 0x41
0049dc16 jne 0x49dc22
0049dc18 mov eax, dword ptr [ecx + 0xdb4]
0049dc1e mov dword ptr [esp + 0x24], eax
0049dc22 mov eax, dword ptr [esp + 0xc]
0049dc26 fmul dword ptr [edx + eax*4 + 0x60]
0049dc2a fld dword ptr [0x628fb0]
0049dc30 fcomp dword ptr [0x5b23f0]
0049dc36 fnstsw ax
0049dc38 test ah, 0x41
0049dc3b je 0x49dcaf
0049dc3d fld dword ptr [esp + 0x24]
0049dc41 fcomp dword ptr [0x5b23f8]
0049dc47 fld dword ptr [esp + 0x24]
0049dc4b fnstsw ax
0049dc4d test ah, 1
0049dc50 je 0x49dc54
0049dc52 fchs
0049dc54 fcomp dword ptr [edx + 0x94]
0049dc5a fnstsw ax
0049dc5c test ah, 0x41
0049dc5f je 0x49dcaf
0049dc61 fcomp dword ptr [esp + 0x18]
0049dc65 fnstsw ax
0049dc67 test ah, 1
0049dc6a je 0x49dd0a
0049dc70 mov ebx, dword ptr [esp + 0xc]
0049dc74 cmp ebx, 1
0049dc77 jle 0x49dd0a
0049dc7d fld dword ptr [esp + 0x14]
0049dc81 fcomp dword ptr [0x5b2604]
0049dc87 fnstsw ax
0049dc89 test ah, 1
0049dc8c je 0x49dd0a
0049dc8e cmp ebx, esi
0049dc90 je 0x49dd0a
0049dc92 mov byte ptr [ecx + 0xd83], 1
0049dc99 mov byte ptr [ecx + 0xd82], bl
0049dc9f mov dl, byte ptr [edx + 0x54]
0049dca2 pop edi
0049dca3 pop esi
0049dca4 mov byte ptr [ecx + 0xd84], dl
0049dcaa pop ebx
0049dcab add esp, 0x14
0049dcae ret
0049dcaf fld dword ptr [esp + 0x24]
0049dcb3 fcomp dword ptr [esp + 0x1c]
0049dcb7 fnstsw ax
0049dcb9 test ah, 0x41
0049dcbc jne 0x49dcdb
0049dcbe cmp esi, edi
0049dcc0 jge 0x49dcdb
0049dcc2 mov eax, dword ptr [esp + 0x10]
0049dcc6 cmp eax, esi
0049dcc8 fstp st(0)
0049dcca je 0x49dd0a
0049dccc mov byte ptr [ecx + 0xd83], 0
0049dcd3 mov byte ptr [ecx + 0xd81], bl
0049dcd9 jmp 0x49dcfb
0049dcdb fcomp dword ptr [esp + 0x18]
0049dcdf fnstsw ax
0049dce1 test ah, 1
0049dce4 je 0x49dd0a
0049dce6 mov eax, dword ptr [esp + 0xc]
0049dcea cmp eax, esi
0049dcec je 0x49dd0a
0049dcee mov byte ptr [ecx + 0xd83], 1
0049dcf5 mov byte ptr [ecx + 0xd81], bl
