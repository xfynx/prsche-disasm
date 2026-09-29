0049cb50 sub esp, 0xc
0049cb53 push ebx
0049cb54 push ebp
0049cb55 push esi
0049cb56 mov esi, dword ptr [esp + 0x1c]
0049cb5a push edi
0049cb5b push 0x5d0d38
0049cb60 mov eax, dword ptr [esi + 0x558]
0049cb66 add eax, 0x2a8
0049cb6b push eax
0049cb6c call 0x5ae3c0
0049cb71 add esp, 8
0049cb74 test eax, eax
0049cb76 je 0x49cbe3
0049cb78 mov ecx, dword ptr [esi + 0x558]
0049cb7e push 0x5d0d34
0049cb83 add ecx, 0x2a8
0049cb89 push ecx
0049cb8a call 0x5ae3c0
0049cb8f add esp, 8
0049cb92 test eax, eax
0049cb94 je 0x49cbe3
0049cb96 mov edx, dword ptr [esi + 0x558]
0049cb9c push 0x5d0d30
0049cba1 add edx, 0x2a8
0049cba7 push edx
0049cba8 call 0x5ae3c0
0049cbad add esp, 8
0049cbb0 test eax, eax
0049cbb2 je 0x49cbe3
0049cbb4 mov eax, dword ptr [esi + 0x558]
0049cbba push 0x5d0d2c
0049cbbf add eax, 0x2a8
0049cbc4 push eax
0049cbc5 call 0x5ae3c0
0049cbca add esp, 8
0049cbcd test eax, eax
0049cbcf je 0x49cbe3
0049cbd1 mov ecx, dword ptr [esi + 0x760]
0049cbd7 mov dword ptr [ecx + 0x1c0], 0
0049cbe1 jmp 0x49cbf3
0049cbe3 mov edx, dword ptr [esi + 0x760]
0049cbe9 mov dword ptr [edx + 0x1c0], 2
0049cbf3 mov eax, dword ptr [esi + 0x760]
0049cbf9 mov dword ptr [esp + 0x10], 0
0049cc01 fld dword ptr [0x5b24a8]
0049cc07 fdiv dword ptr [eax + 0x94]
0049cc0d mov dword ptr [esp + 0x20], 0
0049cc15 mov edi, 0x15
0049cc1a fstp dword ptr [eax + 0x14c]
0049cc20 mov eax, dword ptr [esi + 0x760]
0049cc26 fld dword ptr [eax + 0x88]
0049cc2c fmul dword ptr [0x5b3714]
0049cc32 fmul dword ptr [eax + 0x84]
0049cc38 fld dword ptr [eax + 0x8c]
0049cc3e fmul dword ptr [0x5b4a40]
0049cc44 faddp st(1)
0049cc46 fmul dword ptr [0x5b4a3c]
0049cc4c fstp dword ptr [eax + 0x148]
0049cc52 mov edx, dword ptr [esi + 0x760]
0049cc58 lea ecx, [edx + 0x9c]
0049cc5e fld dword ptr [ecx]
0049cc60 fld dword ptr [esp + 0x10]
0049cc64 fcomp st(1)
0049cc66 fnstsw ax
0049cc68 test ah, 0x41
0049cc6b je 0x49cc73
0049cc6d fstp dword ptr [esp + 0x10]
0049cc71 jmp 0x49cc75
0049cc73 fstp st(0)
0049cc75 add ecx, 4
0049cc78 dec edi
0049cc79 jne 0x49cc5e
0049cc7b mov edi, dword ptr [esi + 0x558]
0049cc81 mov eax, dword ptr [edx + 0xf4]
0049cc87 add edi, 0x2a8
0049cc8d push 0x5d0d28
0049cc92 push edi
0049cc93 mov dword ptr [esi + 0x10d8], eax
0049cc99 call 0x5ae3c0
0049cc9e add esp, 8
0049cca1 test eax, eax
0049cca3 jne 0x49ccb5
0049cca5 mov ecx, dword ptr [esi + 0x760]
0049ccab mov dword ptr [ecx + 0xf0], 0x3eef5c29
0049ccb5 push 0x5d0d28
0049ccba push edi
0049ccbb call 0x5ae3c0
0049ccc0 add esp, 8
0049ccc3 test eax, eax
0049ccc5 je 0x49d212
0049cccb push 0x5d0d24
0049ccd0 push edi
0049ccd1 call 0x5ae3c0
0049ccd6 add esp, 8
0049ccd9 test eax, eax
0049ccdb je 0x49d212
0049cce1 push 0x5d0d34
0049cce6 push edi
0049cce7 call 0x5ae3c0
0049ccec add esp, 8
0049ccef test eax, eax
0049ccf1 je 0x49d212
0049ccf7 push 0x5d0d30
0049ccfc push edi
0049ccfd call 0x5ae3c0
0049cd02 add esp, 8
0049cd05 test eax, eax
0049cd07 je 0x49d212
0049cd0d lea edi, [esi + 0x768]
0049cd13 mov dword ptr [esp + 0x18], 0x14
0049cd1b mov ecx, dword ptr [edi]
0049cd1d cmp word ptr [ecx + 0x26], 0
0049cd22 je 0x49d200
0049cd28 mov eax, dword ptr [esi + 0x760]
0049cd2e fld dword ptr [ecx + 0x54]
0049cd31 fadd dword ptr [eax + 0x40]
0049cd34 fstp dword ptr [eax + 0x40]
0049cd37 mov edx, dword ptr [edi]
0049cd39 mov eax, dword ptr [esi + 0x760]
0049cd3f fld dword ptr [edx + 0x58]
0049cd42 fmul dword ptr [0x5b3ca0]
0049cd48 fadd dword ptr [0x5b24a8]
0049cd4e fdivr dword ptr [eax + 0x90]
0049cd54 fstp dword ptr [eax + 0x90]
0049cd5a mov eax, dword ptr [edi]
0049cd5c mov cx, word ptr [eax + 0x26]
0049cd60 cmp cx, 1
0049cd64 jne 0x49ce7b
0049cd6a lea edx, [eax + 0x28]
0049cd6d mov ebp, 0x5d0d1c
0049cd72 mov eax, edx
0049cd74 mov bl, byte ptr [eax]
0049cd76 mov cl, bl
0049cd78 cmp bl, byte ptr [ebp]
0049cd7b jne 0x49cd99
0049cd7d test cl, cl
0049cd7f je 0x49cd95
0049cd81 mov bl, byte ptr [eax + 1]
0049cd84 mov cl, bl
0049cd86 cmp bl, byte ptr [ebp + 1]
0049cd89 jne 0x49cd99
0049cd8b add eax, 2
0049cd8e add ebp, 2
0049cd91 test cl, cl
0049cd93 jne 0x49cd74
0049cd95 xor eax, eax
0049cd97 jmp 0x49cd9e
0049cd99 sbb eax, eax
0049cd9b sbb eax, -1
0049cd9e test eax, eax
0049cda0 jne 0x49cdc5
0049cda2 mov eax, 0x9c
0049cda7 mov ecx, dword ptr [edi]
0049cda9 mov edx, dword ptr [esi + 0x760]
0049cdaf mov ecx, dword ptr [ecx + eax + 0x74]
0049cdb3 mov dword ptr [eax + edx], ecx
0049cdb6 add eax, 4
0049cdb9 cmp eax, 0xf0
0049cdbe jl 0x49cda7
0049cdc0 jmp 0x49d200
0049cdc5 mov ebp, 0x5d0d14
0049cdca mov eax, edx
0049cdcc mov bl, byte ptr [eax]
0049cdce mov cl, bl
0049cdd0 cmp bl, byte ptr [ebp]
0049cdd3 jne 0x49cdf1
0049cdd5 test cl, cl
0049cdd7 je 0x49cded
0049cdd9 mov bl, byte ptr [eax + 1]
0049cddc mov cl, bl
0049cdde cmp bl, byte ptr [ebp + 1]
0049cde1 jne 0x49cdf1
0049cde3 add eax, 2
0049cde6 add ebp, 2
0049cde9 test cl, cl
0049cdeb jne 0x49cdcc
0049cded xor eax, eax
0049cdef jmp 0x49cdf6
0049cdf1 sbb eax, eax
0049cdf3 sbb eax, -1
0049cdf6 test eax, eax
0049cdf8 jne 0x49ce09
0049cdfa mov edx, dword ptr [esi + 0x760]
0049ce00 mov dword ptr [edx + 0x4c], 1
0049ce07 jmp 0x49ce4f
0049ce09 mov ebp, 0x5d0d04
0049ce0e mov eax, edx
0049ce10 mov dl, byte ptr [eax]
0049ce12 mov bl, byte ptr [ebp]
0049ce15 mov cl, dl
0049ce17 cmp dl, bl
0049ce19 jne 0x49ce39
0049ce1b test cl, cl
0049ce1d je 0x49ce35
0049ce1f mov dl, byte ptr [eax + 1]
0049ce22 mov bl, byte ptr [ebp + 1]
0049ce25 mov cl, dl
0049ce27 cmp dl, bl
0049ce29 jne 0x49ce39
0049ce2b add eax, 2
0049ce2e add ebp, 2
0049ce31 test cl, cl
0049ce33 jne 0x49ce10
0049ce35 xor eax, eax
0049ce37 jmp 0x49ce3e
0049ce39 sbb eax, eax
0049ce3b sbb eax, -1
0049ce3e test eax, eax
0049ce40 jne 0x49ce4f
0049ce42 mov eax, dword ptr [esi + 0x760]
0049ce48 mov dword ptr [eax + 0x4c], 2
0049ce4f mov eax, 0x9c
0049ce54 mov edx, dword ptr [edi]
0049ce56 mov ecx, dword ptr [esi + 0x760]
0049ce5c add ecx, eax
0049ce5e fld dword ptr [edx + eax + 0x74]
0049ce62 fmul dword ptr [0x5b4a38]
0049ce68 add eax, 4
0049ce6b cmp eax, 0xf0
0049ce70 fadd dword ptr [ecx]
0049ce72 fstp dword ptr [ecx]
0049ce74 jl 0x49ce54
0049ce76 jmp 0x49d200
0049ce7b cmp cx, 2
0049ce7f jne 0x49ceaa
0049ce81 fld dword ptr [eax + 0xc0]
0049ce87 fadd dword ptr [0x5b2600]
0049ce8d mov ecx, dword ptr [esi + 0x760]
0049ce93 fmul dword ptr [0x5b2468]
0049ce99 fmul dword ptr [ecx + 0x104]
0049ce9f fstp dword ptr [ecx + 0x104]
0049cea5 jmp 0x49d200
0049ceaa cmp cx, 3
0049ceae jne 0x49cf5e
0049ceb4 mov ecx, 0x5d0cf8
0049ceb9 lea ebp, [eax + 0x28]
0049cebc mov bl, byte ptr [ebp]
0049cebf mov dl, bl
0049cec1 cmp bl, byte ptr [ecx]
0049cec3 jne 0x49cee1
0049cec5 test dl, dl
0049cec7 je 0x49cedd
0049cec9 mov bl, byte ptr [ebp + 1]
0049cecc mov dl, bl
0049cece cmp bl, byte ptr [ecx + 1]
0049ced1 jne 0x49cee1
0049ced3 add ebp, 2
0049ced6 add ecx, 2
0049ced9 test dl, dl
0049cedb jne 0x49cebc
0049cedd xor ecx, ecx
0049cedf jmp 0x49cee6
0049cee1 sbb ecx, ecx
0049cee3 sbb ecx, -1
0049cee6 test ecx, ecx
0049cee8 jne 0x49cf49
0049ceea movsx eax, word ptr [eax + 0xec]
0049cef1 mov ecx, dword ptr [esi + 0x760]
0049cef7 mov dword ptr [ecx + 0x54], eax
0049cefa mov edx, dword ptr [edi]
0049cefc mov ecx, dword ptr [esi + 0x760]
0049cf02 movsx eax, word ptr [edx + 0xea]
0049cf09 add eax, 2
0049cf0c mov dword ptr [ecx + 0x50], eax
0049cf0f mov edx, dword ptr [edi]
0049cf11 mov eax, dword ptr [esi + 0x760]
0049cf17 mov ecx, dword ptr [edx + 0xc0]
0049cf1d mov dword ptr [eax + 0x80], ecx
0049cf23 mov eax, 0x60
0049cf28 mov edx, dword ptr [edi]
0049cf2a mov ecx, dword ptr [esi + 0x760]
0049cf30 mov edx, dword ptr [edx + eax + 0x90]
0049cf37 mov dword ptr [eax + ecx], edx
0049cf3a add eax, 4
0049cf3d cmp eax, 0x80
0049cf42 jl 0x49cf28
0049cf44 jmp 0x49d200
0049cf49 mov ecx, dword ptr [esi + 0x760]
0049cf4f movsx eax, word ptr [eax + 0xec]
0049cf56 add dword ptr [ecx + 0x54], eax
0049cf59 jmp 0x49d200
0049cf5e cmp cx, 4
0049cf62 jne 0x49d01d
0049cf68 fld dword ptr [eax + 0xc0]
0049cf6e fadd dword ptr [0x5b2404]
0049cf74 mov ecx, dword ptr [esi + 0x760]
0049cf7a fmul dword ptr [ecx + 0x11c]
0049cf80 fmul dword ptr [0x5b2694]
0049cf86 fstp dword ptr [ecx + 0x11c]
0049cf8c mov ecx, dword ptr [edi]
0049cf8e mov eax, dword ptr [esi + 0x760]
0049cf94 fld dword ptr [ecx + 0xc0]
0049cf9a fadd dword ptr [0x5b2404]
0049cfa0 fmul dword ptr [eax + 0x130]
0049cfa6 fmul dword ptr [0x5b2694]
0049cfac fstp dword ptr [eax + 0x130]
0049cfb2 mov edx, dword ptr [edi]
0049cfb4 mov eax, dword ptr [esi + 0x760]
0049cfba fld dword ptr [edx + 0xc0]
0049cfc0 fadd dword ptr [0x5b243c]
0049cfc6 fmul dword ptr [eax + 0xf4]
0049cfcc fmul dword ptr [0x5b26a4]
0049cfd2 fstp dword ptr [eax + 0xf4]
0049cfd8 mov ecx, dword ptr [edi]
0049cfda mov eax, dword ptr [esi + 0x760]
0049cfe0 fld dword ptr [ecx + 0xc0]
0049cfe6 fadd dword ptr [0x5b2600]
0049cfec fmul dword ptr [0x5b2468]
0049cff2 fdivr dword ptr [eax + 0x12c]
0049cff8 fstp dword ptr [eax + 0x12c]
0049cffe mov edx, dword ptr [edi]
0049d000 mov eax, dword ptr [esi + 0x760]
0049d006 fld dword ptr [edx + 0xc4]
0049d00c fmul dword ptr [0x5b3060]
0049d012 fstp dword ptr [eax + 0x120]
0049d018 jmp 0x49d200
0049d01d cmp cx, 5
0049d021 jne 0x49d098
0049d023 fld dword ptr [eax + 0xc0]
0049d029 fadd dword ptr [0x5b2404]
0049d02f mov ecx, dword ptr [esi + 0x760]
0049d035 fmul dword ptr [0x5b2694]
0049d03b fdivr dword ptr [ecx + 0x114]
0049d041 fstp dword ptr [ecx + 0x114]
0049d047 mov ecx, dword ptr [edi]
0049d049 mov eax, dword ptr [esi + 0x760]
0049d04f fld dword ptr [ecx + 0xc0]
0049d055 fadd dword ptr [0x5b2404]
0049d05b fmul dword ptr [0x5b2694]
0049d061 fdivr dword ptr [eax + 0x118]
0049d067 fstp dword ptr [eax + 0x118]
0049d06d mov edx, dword ptr [edi]
0049d06f mov eax, dword ptr [esi + 0x760]
0049d075 fld dword ptr [edx + 0xc0]
0049d07b fadd dword ptr [0x5b263c]
0049d081 fmul dword ptr [eax + 0xf4]
0049d087 fmul dword ptr [0x5b49b0]
0049d08d fstp dword ptr [eax + 0xf4]
0049d093 jmp 0x49d200
0049d098 cmp cx, 8
0049d09c jne 0x49d113
0049d09e fld dword ptr [eax + 0xc0]
0049d0a4 fadd dword ptr [0x5b2404]
0049d0aa mov ecx, dword ptr [esi + 0x760]
0049d0b0 fmul dword ptr [ecx + 0x11c]
0049d0b6 fmul dword ptr [0x5b2694]
0049d0bc fstp dword ptr [ecx + 0x11c]
0049d0c2 mov ecx, dword ptr [edi]
0049d0c4 mov eax, dword ptr [esi + 0x760]
0049d0ca fld dword ptr [ecx + 0xc0]
0049d0d0 fadd dword ptr [0x5b263c]
0049d0d6 fmul dword ptr [eax + 0xf4]
0049d0dc fmul dword ptr [0x5b49b0]
0049d0e2 fstp dword ptr [eax + 0xf4]
0049d0e8 mov edx, dword ptr [edi]
0049d0ea mov eax, dword ptr [esi + 0x760]
0049d0f0 fld dword ptr [edx + 0xc0]
0049d0f6 fadd dword ptr [0x5b2600]
