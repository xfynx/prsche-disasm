00490000 add byte ptr [eax], al
00490002 push eax
00490003 call 0x4237d0
00490008 mov eax, dword ptr [esi + 0x25c]
0049000e add esp, 0xc
00490011 mov edi, dword ptr [eax]
00490013 cmp edi, eax
00490015 je 0x490032
00490017 mov eax, edi
00490019 mov edi, dword ptr [edi]
0049001b push 0
0049001d push 0xc
0049001f push eax
00490020 call 0x4237d0
00490025 mov eax, dword ptr [esi + 0x25c]
0049002b add esp, 0xc
0049002e cmp edi, eax
00490030 jne 0x490017
00490032 mov eax, dword ptr [esi + 0x25c]
00490038 push 0
0049003a push 0xc
0049003c mov dword ptr [eax], eax
0049003e mov eax, dword ptr [esi + 0x25c]
00490044 mov dword ptr [eax + 4], eax
00490047 mov ecx, dword ptr [esi + 0x25c]
0049004d push ecx
0049004e call 0x4237d0
00490053 mov eax, dword ptr [esi + 0x258]
00490059 add esp, 0xc
0049005c mov edi, dword ptr [eax]
0049005e cmp edi, eax
00490060 je 0x49007d
00490062 mov eax, edi
00490064 mov edi, dword ptr [edi]
00490066 push 0
00490068 push 0xc
0049006a push eax
0049006b call 0x4237d0
00490070 mov eax, dword ptr [esi + 0x258]
00490076 add esp, 0xc
00490079 cmp edi, eax
0049007b jne 0x490062
0049007d mov eax, dword ptr [esi + 0x258]
00490083 push 0
00490085 push 0xc
00490087 mov dword ptr [eax], eax
00490089 mov eax, dword ptr [esi + 0x258]
0049008f mov dword ptr [eax + 4], eax
00490092 mov edx, dword ptr [esi + 0x258]
00490098 push edx
00490099 call 0x4237d0
0049009e mov eax, dword ptr [esi + 0x254]
004900a4 add esp, 0xc
004900a7 mov edi, dword ptr [eax]
004900a9 cmp edi, eax
004900ab je 0x4900c8
004900ad mov eax, edi
004900af mov edi, dword ptr [edi]
004900b1 push 0
004900b3 push 0xc
004900b5 push eax
004900b6 call 0x4237d0
004900bb mov eax, dword ptr [esi + 0x254]
004900c1 add esp, 0xc
004900c4 cmp edi, eax
004900c6 jne 0x4900ad
004900c8 mov eax, dword ptr [esi + 0x254]
004900ce push 0
004900d0 push 0xc
004900d2 mov dword ptr [eax], eax
004900d4 mov eax, dword ptr [esi + 0x254]
004900da mov dword ptr [eax + 4], eax
004900dd mov eax, dword ptr [esi + 0x254]
004900e3 push eax
004900e4 call 0x4237d0
004900e9 mov eax, dword ptr [esi + 0x150]
004900ef add esp, 0xc
004900f2 mov edi, dword ptr [eax]
004900f4 cmp edi, eax
004900f6 je 0x490113
004900f8 mov eax, edi
004900fa mov edi, dword ptr [edi]
004900fc push 0
004900fe push 0xc
00490100 push eax
00490101 call 0x4237d0
00490106 mov eax, dword ptr [esi + 0x150]
0049010c add esp, 0xc
0049010f cmp edi, eax
00490111 jne 0x4900f8
00490113 mov eax, dword ptr [esi + 0x150]
00490119 push 0
0049011b push 0xc
0049011d mov dword ptr [eax], eax
0049011f mov eax, dword ptr [esi + 0x150]
00490125 mov dword ptr [eax + 4], eax
00490128 mov ecx, dword ptr [esi + 0x150]
0049012e push ecx
0049012f call 0x4237d0
00490134 add esp, 0xc
00490137 pop edi
00490138 pop esi
00490139 ret
0049013a nop
0049013b nop
0049013c nop
0049013d nop
0049013e nop
0049013f nop
00490140 mov eax, dword ptr [0x628c70]
00490145 push esi
00490146 test eax, eax
00490148 je 0x490187
0049014a mov ecx, dword ptr [eax + 8]
0049014d test ecx, ecx
0049014f je 0x490187
00490151 mov cl, byte ptr [eax + 0xbf]
00490157 test cl, cl
00490159 jne 0x490187
0049015b mov ecx, dword ptr [eax + 0x260]
00490161 mov eax, dword ptr [ecx]
00490163 cmp eax, ecx
00490165 je 0x490187
00490167 mov esi, dword ptr [esp + 8]
0049016b mov edx, dword ptr [eax + 8]
0049016e cmp dword ptr [edx + 0x4c], esi
00490171 je 0x490180
00490173 mov eax, dword ptr [eax]
00490175 cmp eax, ecx
00490177 jne 0x49016b
00490179 mov eax, 3
0049017e pop esi
0049017f ret
00490180 mov eax, dword ptr [eax + 8]
00490183 test eax, eax
00490185 jne 0x49018e
00490187 mov eax, 3
0049018c pop esi
0049018d ret
0049018e mov ecx, eax
00490190 call 0x490390
00490195 test al, al
00490197 jne 0x4901a0
00490199 mov eax, 4
0049019e pop esi
0049019f ret
004901a0 mov eax, dword ptr [0x657408]
004901a5 test eax, eax
004901a7 je 0x490243
004901ad cmp esi, dword ptr [0x65741c]
004901b3 je 0x4901d5
004901b5 mov eax, dword ptr [esi*4 + 0x5e8b34]
004901bc mov ecx, dword ptr [0x606ac4]
004901c2 sub ecx, dword ptr [eax + 0x3c]
004901c5 mov dword ptr [esp + 8], ecx
004901c9 fild dword ptr [esp + 8]
004901cd fmul dword ptr [0x5b2828]
004901d3 jmp 0x490220
004901d5 mov eax, dword ptr [0x628c70]
004901da test eax, eax
004901dc je 0x490209
004901de mov ecx, dword ptr [eax + 8]
004901e1 test ecx, ecx
004901e3 je 0x490209
004901e5 mov cl, byte ptr [eax + 0xbf]
004901eb test cl, cl
004901ed jne 0x490209
004901ef mov ecx, dword ptr [eax + 0x260]
004901f5 mov eax, dword ptr [ecx]
004901f7 cmp eax, ecx
004901f9 je 0x490209
004901fb mov edx, dword ptr [eax + 8]
004901fe cmp dword ptr [edx + 0x4c], esi
00490201 je 0x490236
00490203 mov eax, dword ptr [eax]
00490205 cmp eax, ecx
00490207 jne 0x4901fb
00490209 xor eax, eax
0049020b mov ecx, eax
0049020d call 0x4905a0
00490212 mov dword ptr [esp + 8], eax
00490216 fild dword ptr [esp + 8]
0049021a fmul qword ptr [0x5b49a8]
00490220 fcom qword ptr [0x5b2750]
00490226 fnstsw ax
00490228 test ah, 0x41
0049022b jne 0x49023b
0049022d mov eax, 2
00490232 fstp st(0)
00490234 pop esi
00490235 ret
00490236 mov eax, dword ptr [eax + 8]
00490239 jmp 0x49020b
0049023b fcomp qword ptr [0x5b49a0]
00490241 jmp 0x4902ac
00490243 mov eax, dword ptr [0x628c70]
00490248 test eax, eax
0049024a je 0x49027e
0049024c mov ecx, dword ptr [eax + 8]
0049024f test ecx, ecx
00490251 je 0x49027e
00490253 mov cl, byte ptr [eax + 0xbf]
00490259 test cl, cl
0049025b jne 0x49027e
0049025d mov cl, byte ptr [eax + 0xbe]
00490263 test cl, cl
00490265 je 0x49027e
00490267 mov ecx, dword ptr [eax + 0xdc]
0049026d test ecx, ecx
0049026f jl 0x49027e
00490271 mov eax, dword ptr [eax + esi*4 + 0x128]
00490278 mov dword ptr [esp + 8], eax
0049027c jmp 0x490286
0049027e mov dword ptr [esp + 8], 0
00490286 fild dword ptr [esp + 8]
0049028a fmul qword ptr [0x5b49a8]
00490290 fcom qword ptr [0x5b2778]
00490296 fnstsw ax
00490298 test ah, 0x41
0049029b jne 0x4902a6
0049029d mov eax, 2
004902a2 fstp st(0)
004902a4 pop esi
004902a5 ret
004902a6 fcomp qword ptr [0x5b4998]
004902ac fnstsw ax
004902ae test ah, 0x41
004902b1 jne 0x4902ba
004902b3 mov eax, 1
004902b8 pop esi
004902b9 ret
004902ba xor eax, eax
004902bc pop esi
004902bd ret
004902be nop
004902bf nop
004902c0 mov eax, dword ptr [0x5e4fe8]
004902c5 push ebx
004902c6 push esi
004902c7 mov ebx, ecx
004902c9 mov ecx, dword ptr [eax + 0x28]
004902cc lea esi, [eax + 0x28]
004902cf push edi
004902d0 push ecx
004902d1 call 0x5322b0
004902d6 mov eax, dword ptr [esi + 0x10]
004902d9 add esp, 4
004902dc test eax, eax
004902de jne 0x4902ec
004902e0 push 0
004902e2 push 1
004902e4 call 0x59eeb0
004902e9 add esp, 8
004902ec mov edi, dword ptr [esi + 0x10]
004902ef mov edx, dword ptr [edi + 4]
004902f2 mov dword ptr [esi + 0x10], edx
004902f5 mov eax, dword ptr [esi]
004902f7 push eax
004902f8 call 0x5322c0
004902fd mov dword ptr [ebx], edi
004902ff mov dword ptr [edi], edi
00490301 mov eax, dword ptr [ebx]
00490303 add esp, 4
00490306 mov dword ptr [eax + 4], eax
00490309 pop edi
0049030a mov eax, ebx
0049030c pop esi
0049030d pop ebx
0049030e ret 4
00490311 nop
00490312 nop
00490313 nop
00490314 nop
00490315 nop
00490316 nop
00490317 nop
00490318 nop
00490319 nop
0049031a nop
0049031b nop
0049031c nop
0049031d nop
0049031e nop
0049031f nop
00490320 mov eax, dword ptr [0x5e4fe8]
00490325 push esi
00490326 push edi
00490327 mov ecx, dword ptr [eax + 0x28]
0049032a lea edi, [eax + 0x28]
0049032d push ecx
0049032e call 0x5322b0
00490333 mov eax, dword ptr [edi + 0x10]
00490336 add esp, 4
00490339 test eax, eax
0049033b jne 0x490349
0049033d push 0
0049033f push 1
00490341 call 0x59eeb0
00490346 add esp, 8
00490349 mov esi, dword ptr [edi + 0x10]
0049034c mov edx, dword ptr [esi + 4]
0049034f mov dword ptr [edi + 0x10], edx
00490352 mov eax, dword ptr [edi]
00490354 push eax
00490355 call 0x5322c0
0049035a lea eax, [esi + 8]
0049035d add esp, 4
00490360 test eax, eax
00490362 je 0x49036c
00490364 mov ecx, dword ptr [esp + 0x14]
00490368 mov dl, byte ptr [ecx]
0049036a mov byte ptr [eax], dl
0049036c mov eax, dword ptr [esp + 0x10]
00490370 pop edi
00490371 mov dword ptr [esi], eax
00490373 mov ecx, dword ptr [eax + 4]
00490376 mov dword ptr [esi + 4], ecx
00490379 mov edx, dword ptr [eax + 4]
0049037c mov dword ptr [edx], esi
0049037e mov dword ptr [eax + 4], esi
00490381 mov eax, dword ptr [esp + 8]
00490385 mov dword ptr [eax], esi
00490387 pop esi
00490388 ret 0xc
0049038b nop
0049038c nop
0049038d nop
0049038e nop
0049038f nop
00490390 mov eax, dword ptr [0x628c70]
00490395 push esi
00490396 test eax, eax
00490398 mov esi, ecx
0049039a je 0x4903c1
0049039c mov ecx, dword ptr [eax + 8]
0049039f test ecx, ecx
004903a1 je 0x4903c1
004903a3 mov cl, byte ptr [eax + 0xbf]
004903a9 test cl, cl
004903ab jne 0x4903c1
004903ad mov cl, byte ptr [eax + 0xbe]
004903b3 test cl, cl
004903b5 je 0x4903c1
004903b7 mov ecx, dword ptr [eax + 0xdc]
004903bd test ecx, ecx
004903bf jge 0x4903c5
004903c1 xor al, al
004903c3 pop esi
004903c4 ret
004903c5 mov ecx, dword ptr [esi + 0x40]
004903c8 mov al, byte ptr [eax + 0xe5]
004903ce mov edx, 1
004903d3 pop esi
004903d4 shl edx, cl
004903d6 and dl, al
004903d8 neg dl
004903da sbb edx, edx
004903dc neg edx
004903de mov al, dl
004903e0 ret
004903e1 nop
004903e2 nop
004903e3 nop
004903e4 nop
004903e5 nop
004903e6 nop
004903e7 nop
004903e8 nop
004903e9 nop
004903ea nop
004903eb nop
004903ec nop
004903ed nop
004903ee nop
004903ef nop
004903f0 mov ecx, dword ptr [ecx + 0x5c]
004903f3 push esi
004903f4 mov eax, dword ptr [ecx]
004903f6 cmp eax, ecx
004903f8 je 0x49040d
004903fa mov dx, word ptr [esp + 8]
004903ff mov esi, dword ptr [eax + 8]
00490402 cmp word ptr [esi], dx
00490405 je 0x490413
00490407 mov eax, dword ptr [eax]
00490409 cmp eax, ecx
0049040b jne 0x4903ff
0049040d xor eax, eax
0049040f pop esi
00490410 ret 4
00490413 mov eax, dword ptr [eax + 8]
00490416 pop esi
00490417 ret 4
0049041a nop
0049041b nop
0049041c nop
0049041d nop
0049041e nop
0049041f nop
00490420 push ebx
00490421 lea ebx, [ecx + 0x5c]
00490424 push esi
00490425 push edi
00490426 mov ecx, dword ptr [ebx]
00490428 mov edi, dword ptr [esp + 0x10]
0049042c mov eax, dword ptr [ecx]
0049042e cmp eax, ecx
00490430 je 0x490449
00490432 mov edx, dword ptr [eax + 8]
00490435 cmp word ptr [edx], di
00490438 je 0x490442
0049043a mov eax, dword ptr [eax]
0049043c cmp eax, ecx
0049043e jne 0x490432
00490440 jmp 0x490449
00490442 mov ecx, dword ptr [eax + 8]
00490445 test ecx, ecx
00490447 jne 0x4904c4
00490449 push 0x10
0049044b call 0x59ef90
00490450 mov esi, eax
00490452 add esp, 4
00490455 test esi, esi
00490457 je 0x490496
00490459 mov word ptr [esi], di
0049045c mov edi, dword ptr [esp + 0x18]
00490460 push 0
00490462 push edi
00490463 push 0x5d072c
00490468 call 0x531ca0
0049046d mov ecx, dword ptr [esp + 0x20]
00490471 add esp, 0xc
00490474 test ecx, ecx
00490476 mov dword ptr [esi + 4], eax
00490479 mov dword ptr [esi + 8], edi
0049047c mov dword ptr [esi + 0xc], 0
00490483 je 0x490490
00490485 push edi
00490486 push ecx
00490487 push eax
00490488 call 0x5323e0
0049048d add esp, 0xc
00490490 mov dword ptr [esp + 0x10], esi
00490494 jmp 0x49049e
00490496 mov dword ptr [esp + 0x10], 0
0049049e lea eax, [esp + 0x10]
004904a2 lea ecx, [esp + 0x18]
004904a6 push eax
004904a7 push ecx
004904a8 mov ecx, ebx
004904aa call 0x529050
004904af push ecx
004904b0 mov ecx, esp
004904b2 push eax
004904b3 call 0x50e140
004904b8 lea edx, [esp + 0x1c]
004904bc mov ecx, ebx
004904be push edx
004904bf call 0x4937f0
004904c4 pop edi
004904c5 pop esi
004904c6 pop ebx
004904c7 ret 0xc
004904ca nop
004904cb nop
004904cc nop
004904cd nop
004904ce nop
004904cf nop
004904d0 push ecx
004904d1 mov eax, dword ptr [ecx + 0x5c]
004904d4 push ebx
004904d5 push ebp
004904d6 push esi
004904d7 lea esi, [ecx + 0x5c]
004904da mov ecx, dword ptr [eax]
004904dc cmp ecx, eax
004904de push edi
004904df je 0x49052d
004904e1 mov eax, dword ptr [esi]
004904e3 mov ebx, eax
004904e5 mov ecx, dword ptr [eax + 4]
004904e8 mov eax, dword ptr [ebx]
004904ea mov ebp, dword ptr [ecx + 8]
004904ed cmp eax, ebx
004904ef je 0x490511
004904f1 mov ecx, dword ptr [eax + 8]
004904f4 mov edi, dword ptr [eax]
004904f6 cmp ecx, ebp
004904f8 jne 0x49050b
004904fa push ecx
004904fb lea edx, [esp + 0x14]
004904ff mov ecx, esp
00490501 push edx
00490502 mov dword ptr [ecx], eax
00490504 mov ecx, esi
00490506 call 0x48b660
0049050b cmp edi, ebx
0049050d mov eax, edi
0049050f jne 0x4904f1
00490511 test ebp, ebp
00490513 je 0x490527
00490515 mov eax, dword ptr [ebp + 4]
00490518 push eax
00490519 call 0x531f90
0049051e push ebp
0049051f call 0x59f050
00490524 add esp, 8
00490527 mov eax, dword ptr [esi]
00490529 cmp dword ptr [eax], eax
0049052b jne 0x4904e1
0049052d mov eax, dword ptr [esi]
0049052f mov ebx, dword ptr [eax]
00490531 cmp ebx, eax
00490533 je 0x490565
00490535 mov ecx, dword ptr [0x5e4fe8]
0049053b mov ebp, ebx
0049053d mov ebx, dword ptr [ebx]
0049053f mov edx, dword ptr [ecx + 0x28]
00490542 lea edi, [ecx + 0x28]
00490545 push edx
00490546 call 0x5322b0
0049054b mov eax, dword ptr [edi + 0x10]
0049054e mov dword ptr [ebp + 4], eax
00490551 mov dword ptr [edi + 0x10], ebp
00490554 mov ecx, dword ptr [edi]
00490556 push ecx
00490557 call 0x5322c0
0049055c mov eax, dword ptr [esi]
0049055e add esp, 8
00490561 cmp ebx, eax
00490563 jne 0x490535
00490565 mov eax, dword ptr [esi]
00490567 mov dword ptr [eax], eax
00490569 mov eax, dword ptr [esi]
0049056b mov dword ptr [eax + 4], eax
0049056e mov edx, dword ptr [0x5e4fe8]
00490574 mov esi, dword ptr [esi]
00490576 mov eax, dword ptr [edx + 0x28]
00490579 lea edi, [edx + 0x28]
0049057c push eax
0049057d call 0x5322b0
00490582 mov ecx, dword ptr [edi + 0x10]
00490585 mov dword ptr [esi + 4], ecx
00490588 mov dword ptr [edi + 0x10], esi
0049058b mov edx, dword ptr [edi]
0049058d push edx
0049058e call 0x5322c0
00490593 add esp, 8
00490596 pop edi
00490597 pop esi
00490598 pop ebp
00490599 pop ebx
0049059a pop ecx
0049059b ret
0049059c nop
0049059d nop
0049059e nop
0049059f nop
004905a0 mov eax, dword ptr [0x628c70]
004905a5 push esi
004905a6 test eax, eax
004905a8 push edi
004905a9 mov esi, ecx
004905ab je 0x4905f6
004905ad mov ecx, dword ptr [eax + 8]
004905b0 test ecx, ecx
004905b2 je 0x4905f6
004905b4 mov cl, byte ptr [eax + 0xbf]
004905ba test cl, cl
004905bc jne 0x4905f6
004905be mov cl, byte ptr [eax + 0xbe]
004905c4 test cl, cl
004905c6 je 0x4905f6
004905c8 mov al, byte ptr [esi + 0x58]
004905cb test al, al
004905cd jne 0x4905f6
004905cf mov edi, dword ptr [0x5b2080]
004905d5 call edi
004905d7 sub eax, dword ptr [esi + 0x44]
004905da cmp eax, 0x3e8
004905df jbe 0x4905f6
004905e1 mov byte ptr [esi + 0x58], 1
004905e5 call edi
004905e7 mov dword ptr [esi + 0x44], eax
004905ea mov eax, dword ptr [esi + 0x40]
004905ed push eax
004905ee call 0x48d9f0
004905f3 add esp, 4
004905f6 mov eax, dword ptr [esi + 0x54]
004905f9 pop edi
004905fa pop esi
004905fb ret
004905fc nop
004905fd nop
004905fe nop
004905ff nop
00490600 push esi
00490601 mov esi, ecx
00490603 call dword ptr [0x5b2080]
00490609 sub eax, dword ptr [esi + 0x44]
0049060c push eax
0049060d call 0x48da30
00490612 mov eax, dword ptr [esp + 0xc]
00490616 add esp, 4
00490619 mov dword ptr [esi + 0x54], eax
0049061c mov byte ptr [esi + 0x58], 0
00490620 pop esi
00490621 ret 4
00490624 nop
00490625 nop
00490626 nop
00490627 nop
00490628 nop
00490629 nop
0049062a nop
0049062b nop
0049062c nop
0049062d nop
0049062e nop
0049062f nop
00490630 mov eax, dword ptr [ecx]
00490632 mov eax, dword ptr [eax + 4]
00490635 ret
00490636 nop
00490637 nop
00490638 nop
00490639 nop
0049063a nop
0049063b nop
0049063c nop
0049063d nop
0049063e nop
0049063f nop
00490640 push ebx
00490641 push edi
00490642 mov edi, dword ptr [0x628c74]
00490648 test edi, edi
0049064a je 0x4906a1
0049064c mov ebx, dword ptr [0x628c78]
00490652 mov eax, dword ptr [ebx]
00490654 push eax
00490655 call 0x5322b0
0049065a mov al, byte ptr [0x5d07d0]
0049065f add esp, 4
00490662 test al, al
00490664 je 0x490674
00490666 mov ecx, dword ptr [ebx]
00490668 push ecx
00490669 call 0x5322c0
0049066e add esp, 4
00490671 pop edi
00490672 pop ebx
00490673 ret
00490674 mov eax, dword ptr [edi + 0x178]
0049067a push esi
0049067b mov esi, dword ptr [eax]
0049067d cmp esi, eax
0049067f je 0x490695
00490681 mov eax, esi
00490683 mov esi, dword ptr [esi]
00490685 mov ecx, dword ptr [eax + 8]
00490688 call 0x48b6b0
0049068d cmp esi, dword ptr [edi + 0x178]
00490693 jne 0x490681
00490695 mov edx, dword ptr [ebx]
00490697 push edx
00490698 call 0x5322c0
0049069d add esp, 4
004906a0 pop esi
004906a1 pop edi
004906a2 pop ebx
004906a3 ret
004906a4 nop
004906a5 nop
004906a6 nop
004906a7 nop
004906a8 nop
004906a9 nop
004906aa nop
004906ab nop
004906ac nop
004906ad nop
004906ae nop
004906af nop
004906b0 push ebp
004906b1 mov ebp, dword ptr [0x628c78]
004906b7 mov eax, dword ptr [ebp]
004906ba push eax
004906bb call 0x5322b0
004906c0 mov al, byte ptr [0x5d07d0]
004906c5 add esp, 4
004906c8 test al, al
004906ca jne 0x4907a8
004906d0 mov eax, dword ptr [0x628c74]
004906d5 mov ecx, dword ptr [eax]
004906d7 test ecx, ecx
004906d9 je 0x4906e5
004906db call 0x48b450
004906e0 mov eax, dword ptr [0x628c74]
004906e5 mov ecx, dword ptr [eax]
004906e7 test ecx, ecx
004906e9 je 0x4907a8
004906ef mov dl, byte ptr [eax + 0x17d]
004906f5 test dl, dl
004906f7 je 0x49075c
004906f9 mov edx, dword ptr [eax + 0x180]
004906ff test edx, edx
00490701 jne 0x49070d
00490703 call 0x48b1c0
00490708 mov eax, dword ptr [0x628c74]
0049070d mov ecx, dword ptr [eax + 0x180]
00490713 inc ecx
00490714 mov dword ptr [eax + 0x180], ecx
0049071a mov ecx, dword ptr [0x5deb48]
00490720 mov eax, dword ptr [0x628c74]
00490725 lea edx, [ecx + ecx*4]
00490728 mov ecx, dword ptr [eax + 0x180]
0049072e shl edx, 1
00490730 cmp ecx, edx
00490732 jle 0x49075c
00490734 mov dword ptr [eax + 0x180], 0
0049073e mov eax, dword ptr [0x628c74]
00490743 mov ecx, dword ptr [eax]
00490745 call 0x48b200
0049074a mov ecx, dword ptr [0x628c74]
00490750 mov byte ptr [ecx + 0x17d], 0
00490757 mov eax, dword ptr [0x628c74]
0049075c push esi
0049075d lea ecx, [eax + 0x48]
00490760 call 0x48a9a0
00490765 mov ecx, dword ptr [0x628c74]
0049076b shl eax, 5
0049076e mov esi, eax
00490770 mov eax, dword ptr [ecx + 0x4c]
00490773 mov edx, esi
00490775 sub edx, eax
00490777 test edx, edx
00490779 jle 0x4907a2
0049077b mov ecx, dword ptr [ecx]
0049077d call 0x48b4f0
00490782 mov eax, dword ptr [0x628c74]
00490787 mov ecx, dword ptr [eax + 0x4c]
0049078a add ecx, 0x3e8
00490790 mov dword ptr [eax + 0x4c], ecx
00490793 mov ecx, dword ptr [0x628c74]
00490799 mov eax, esi
0049079b sub eax, dword ptr [ecx + 0x4c]
0049079e test eax, eax
004907a0 jg 0x49077b
004907a2 call 0x4907c0
004907a7 pop esi
004907a8 mov ecx, dword ptr [ebp]
004907ab push ecx
004907ac call 0x5322c0
004907b1 add esp, 4
004907b4 pop ebp
004907b5 ret
004907b6 nop
004907b7 nop
004907b8 nop
004907b9 nop
004907ba nop
004907bb nop
004907bc nop
004907bd nop
004907be nop
004907bf nop
004907c0 sub esp, 0x44
004907c3 push ebx
004907c4 push ebp
004907c5 push esi
004907c6 mov esi, ecx
004907c8 push edi
004907c9 mov eax, dword ptr [esi + 4]
004907cc test eax, eax
004907ce jne 0x49082a
004907d0 mov eax, dword ptr [esi + 0x174]
004907d6 mov edi, dword ptr [eax]
004907d8 cmp edi, eax
004907da je 0x4907fd
004907dc mov eax, edi
004907de mov edi, dword ptr [edi]
004907e0 mov eax, dword ptr [eax + 8]
004907e3 mov ecx, dword ptr [eax + 0xac]
004907e9 test ecx, ecx
004907eb jne 0x4907f5
004907ed push eax
004907ee mov ecx, esi
004907f0 call 0x492290
004907f5 cmp edi, dword ptr [esi + 0x174]
004907fb jne 0x4907dc
004907fd mov eax, dword ptr [esi + 0x178]
00490803 mov edi, dword ptr [eax]
00490805 cmp edi, eax
00490807 je 0x49082a
00490809 mov eax, edi
0049080b mov edi, dword ptr [edi]
0049080d mov eax, dword ptr [eax + 8]
00490810 mov ecx, dword ptr [eax + 0xac]
00490816 test ecx, ecx
00490818 jne 0x490822
0049081a push eax
0049081b mov ecx, esi
0049081d call 0x4923a0
00490822 cmp edi, dword ptr [esi + 0x178]
00490828 jne 0x490809
0049082a mov eax, dword ptr [esi + 0x16c]
00490830 mov edi, dword ptr [eax]
00490832 cmp edi, eax
00490834 je 0x490852
00490836 mov eax, edi
00490838 mov edi, dword ptr [edi]
0049083a mov eax, dword ptr [eax + 8]
0049083d cmp dword ptr [eax], 0
00490840 jne 0x49084a
00490842 push eax
00490843 mov ecx, esi
00490845 call 0x492770
0049084a cmp edi, dword ptr [esi + 0x16c]
00490850 jne 0x490836
00490852 mov ecx, dword ptr [esi + 0x164]
00490858 mov eax, dword ptr [ecx]
0049085a cmp eax, ecx
0049085c je 0x490ae4
00490862 jmp 0x490868
00490864 mov eax, dword ptr [esp + 0x18]
00490868 mov ecx, dword ptr [eax]
0049086a mov eax, dword ptr [eax + 8]
0049086d mov dword ptr [esp + 0x18], ecx
00490871 mov dword ptr [esp + 0x10], eax
00490875 mov cl, byte ptr [eax + 0xbc]
0049087b test cl, cl
0049087d je 0x490ad2
00490883 cmp dword ptr [eax], 0
00490886 jne 0x490895
00490888 push eax
00490889 mov ecx, esi
0049088b call 0x492770
00490890 jmp 0x490ad2
00490895 mov cl, byte ptr [eax + 0xbb]
0049089b test cl, cl
0049089d je 0x490ad2
004908a3 mov cl, byte ptr [eax + 0xbd]
004908a9 mov dword ptr [esp + 0x28], 0x5d0868
004908b1 test cl, cl
004908b3 mov cl, byte ptr [eax + 0xba]
004908b9 mov dword ptr [esp + 0x2c], 0x5d0854
004908c1 mov dword ptr [esp + 0x30], 0x5d0844
004908c9 mov dword ptr [esp + 0x34], 0x5d0838
004908d1 mov dword ptr [esp + 0x38], 0x5d0828
004908d9 mov dword ptr [esp + 0x3c], 0x5d0818
004908e1 mov dword ptr [esp + 0x40], 0x5d0808
004908e9 mov dword ptr [esp + 0x44], 0x5d07f8
004908f1 mov dword ptr [esp + 0x48], 0x5d07f0
004908f9 mov dword ptr [esp + 0x4c], 0x5d07e0
00490901 mov dword ptr [esp + 0x50], 0x5d07d4
00490909 je 0x49091f
0049090b test cl, cl
0049090d jne 0x490ad2
00490913 mov byte ptr [eax + 0xba], 1
0049091a jmp 0x490a9a
0049091f test cl, cl
00490921 jne 0x490ad2
00490927 mov byte ptr [eax + 0xba], 1
0049092e mov edi, dword ptr [esi + 0x154]
00490934 mov eax, dword ptr [esi]
00490936 inc edi
00490937 mov dword ptr [esi + 0x154], edi
0049093d mov ecx, edi
0049093f mov dl, byte ptr [eax + 0x14]
00490942 test dl, dl
00490944 jne 0x49096b
00490946 mov eax, dword ptr [eax + 0x10]
00490949 test eax, eax
0049094b je 0x49096b
0049094d mov edx, dword ptr [esi + 0x158]
00490953 push 0
00490955 shl edx, 0x10
00490958 add edx, ecx
0049095a push 0
0049095c push edx
0049095d push 0
0049095f push 0xb8
00490964 mov ecx, eax
00490966 call 0x48c870
0049096b mov eax, dword ptr [esp + 0x10]
0049096f push 0
00490971 mov edx, dword ptr [eax + 0xac]
00490977 lea ecx, [eax + 0x24]
0049097a push ecx
0049097b mov ecx, dword ptr [esi + 0xc]
0049097e push 0x80000000
00490983 push edx
00490984 push 0xb0
00490989 call 0x48c870
0049098e lea eax, [esp + 0x10]
00490992 lea ecx, [esp + 0x1c]
00490996 lea ebp, [esi + 0x168]
0049099c push eax
0049099d push ecx
0049099e mov ecx, ebp
004909a0 call 0x529050
004909a5 push ecx
004909a6 mov ecx, esp
004909a8 push eax
004909a9 call 0x50e140
004909ae lea edx, [esp + 0x28]
004909b2 mov ecx, ebp
004909b4 push edx
004909b5 call 0x4937f0
004909ba mov eax, dword ptr [esi + 0x174]
004909c0 mov ebx, dword ptr [esp + 0x10]
004909c4 mov edi, dword ptr [eax]
004909c6 cmp edi, eax
004909c8 je 0x4909df
004909ca mov ecx, dword ptr [edi + 8]
004909cd push ebx
004909ce call 0x48baa0
004909d3 mov edi, dword ptr [edi]
004909d5 mov eax, dword ptr [esi + 0x174]
004909db cmp edi, eax
004909dd jne 0x4909ca
004909df mov eax, dword ptr [esi + 0x178]
004909e5 mov edi, dword ptr [eax]
004909e7 cmp edi, eax
004909e9 je 0x490a00
004909eb mov ecx, dword ptr [edi + 8]
004909ee push ebx
004909ef call 0x48baa0
004909f4 mov edi, dword ptr [edi]
004909f6 mov eax, dword ptr [esi + 0x178]
004909fc cmp edi, eax
004909fe jne 0x4909eb
00490a00 mov eax, dword ptr [ebp]
00490a03 mov ebx, dword ptr [esp + 0x10]
00490a07 mov edi, dword ptr [eax]
00490a09 cmp edi, eax
00490a0b je 0x490a37
00490a0d mov eax, dword ptr [edi + 8]
00490a10 push ebx
00490a11 mov edx, dword ptr [eax + 0xac]
00490a17 lea ecx, [eax + 0x24]
00490a1a push ecx
00490a1b mov ecx, dword ptr [esi + 0xc]
00490a1e push 0x80000000
00490a23 push edx
00490a24 push 0xb0
00490a29 call 0x48c870
00490a2e mov edi, dword ptr [edi]
00490a30 mov eax, dword ptr [ebp]
00490a33 cmp edi, eax
00490a35 jne 0x490a0d
00490a37 mov eax, dword ptr [esi + 0x170]
00490a3d mov edi, dword ptr [esp + 0x10]
00490a41 cmp dword ptr [eax], eax
00490a43 je 0x490a9a
00490a45 mov ecx, eax
00490a47 mov eax, dword ptr [ecx]
00490a49 mov dword ptr [esp + 0x14], eax
00490a4d mov eax, dword ptr [eax]
00490a4f cmp eax, ecx
00490a51 mov dword ptr [esp + 0x14], eax
00490a55 je 0x490a9a
00490a57 mov eax, dword ptr [eax + 8]
00490a5a push edi
00490a5b mov edx, dword ptr [eax + 0x48]
00490a5e mov ebp, dword ptr [eax + 0x3c]
00490a61 lea ecx, [eax + 0x4c]
00490a64 mov eax, dword ptr [eax + 0xb0]
00490a6a or edx, ebp
00490a6c push ecx
00490a6d mov ecx, dword ptr [esi + 8]
00490a70 push edx
00490a71 push eax
00490a72 push 0xb8
00490a77 call 0x48c870
00490a7c lea ecx, [esp + 0x24]
00490a80 push 0
00490a82 push ecx
00490a83 lea ecx, [esp + 0x1c]
00490a87 call 0x4930f0
00490a8c mov eax, dword ptr [esp + 0x14]
00490a90 mov ecx, dword ptr [esi + 0x170]
00490a96 cmp eax, ecx
00490a98 jne 0x490a57
00490a9a mov eax, dword ptr [esp + 0x10]
00490a9e mov ecx, dword ptr [esi + 8]
00490aa1 push eax
00490aa2 push 0
00490aa4 mov edx, dword ptr [eax + 0xc0]
00490aaa push 0x80000000
00490aaf push edx
00490ab0 push 0xc6
00490ab5 call 0x48c870
00490aba mov eax, dword ptr [esp + 0x10]
00490abe mov ecx, dword ptr [eax + 0xc0]
00490ac4 mov edx, dword ptr [esp + ecx*4 + 0x28]
00490ac8 push edx
00490ac9 push eax
00490aca call 0x492cf0
00490acf add esp, 8
00490ad2 mov eax, dword ptr [esp + 0x18]
00490ad6 mov ecx, dword ptr [esi + 0x164]
00490adc cmp eax, ecx
00490ade jne 0x490864
00490ae4 pop edi
00490ae5 pop esi
00490ae6 pop ebp
00490ae7 pop ebx
00490ae8 add esp, 0x44
00490aeb ret
00490aec nop
00490aed nop
00490aee nop
00490aef nop
00490af0 push ebx
00490af1 push ebp
00490af2 push esi
00490af3 push edi
00490af4 mov edi, dword ptr [ecx + 0x164]
00490afa mov eax, dword ptr [ecx + 0x150]
00490b00 mov bl, 1
00490b02 inc eax
00490b03 and eax, 0x7fffff
00490b08 mov dword ptr [ecx + 0x150], eax
00490b0e mov edx, dword ptr [edi]
00490b10 cmp edx, edi
00490b12 je 0x490b27
00490b14 mov esi, dword ptr [edx + 8]
00490b17 cmp eax, dword ptr [esi + 0xac]
00490b1d jne 0x490b21
00490b1f xor bl, bl
00490b21 mov edx, dword ptr [edx]
00490b23 cmp edx, edi
00490b25 jne 0x490b14
00490b27 mov esi, dword ptr [ecx + 0x174]
00490b2d mov edx, dword ptr [esi]
00490b2f cmp edx, esi
00490b31 je 0x490b43
00490b33 mov ebp, dword ptr [edx + 8]
00490b36 cmp eax, dword ptr [ebp + 0x70]
00490b39 jne 0x490b3d
00490b3b xor bl, bl
00490b3d mov edx, dword ptr [edx]
00490b3f cmp edx, esi
00490b41 jne 0x490b33
00490b43 mov esi, dword ptr [ecx + 0x178]
00490b49 mov edx, dword ptr [esi]
00490b4b cmp edx, esi
00490b4d je 0x490b5f
00490b4f mov ebp, dword ptr [edx + 8]
00490b52 cmp eax, dword ptr [ebp + 0x70]
00490b55 jne 0x490b59
00490b57 xor bl, bl
00490b59 mov edx, dword ptr [edx]
00490b5b cmp edx, esi
00490b5d jne 0x490b4f
00490b5f test bl, bl
00490b61 je 0x490afa
00490b63 mov eax, dword ptr [ecx + 0x150]
00490b69 pop edi
00490b6a pop esi
00490b6b pop ebp
00490b6c pop ebx
00490b6d ret
00490b6e nop
00490b6f nop
00490b70 push esi
00490b71 push edi
00490b72 mov edi, ecx
00490b74 mov eax, dword ptr [edi + 0x164]
00490b7a mov esi, dword ptr [eax]
00490b7c cmp esi, eax
00490b7e je 0x490b9d
00490b80 push ebx
00490b81 mov ebx, dword ptr [esp + 0x10]
00490b85 mov eax, esi
00490b87 mov esi, dword ptr [esi]
00490b89 mov ecx, ebx
00490b8b mov eax, dword ptr [eax + 8]
00490b8e push eax
00490b8f call 0x48baa0
00490b94 cmp esi, dword ptr [edi + 0x164]
00490b9a jne 0x490b85
00490b9c pop ebx
00490b9d pop edi
00490b9e pop esi
00490b9f ret 4
00490ba2 nop
00490ba3 nop
00490ba4 nop
00490ba5 nop
00490ba6 nop
00490ba7 nop
00490ba8 nop
00490ba9 nop
00490baa nop
00490bab nop
00490bac nop
00490bad nop
00490bae nop
00490baf nop
00490bb0 sub esp, 0xc
00490bb3 mov eax, dword ptr [esp + 0x14]
00490bb7 push ebx
00490bb8 push ebp
00490bb9 push esi
00490bba mov esi, dword ptr [eax + 8]
00490bbd xor ecx, ecx
00490bbf xor edx, edx
00490bc1 xor eax, eax
00490bc3 mov cl, byte ptr [esi + 1]
00490bc6 mov dl, byte ptr [esi + 2]
00490bc9 mov al, byte ptr [esi + 3]
00490bcc mov ebp, ecx
00490bce shl ebp, 8
00490bd1 add ebp, edx
00490bd3 push edi
00490bd4 shl ebp, 8
00490bd7 add ebp, eax
00490bd9 xor eax, eax
00490bdb mov al, byte ptr [esi]
00490bdd mov dword ptr [esp + 0x18], ebp
00490be1 add eax, 0xffffff4c
00490be6 cmp eax, 5
00490be9 ja 0x490de0
00490bef jmp dword ptr [eax*4 + 0x490de8]
00490bf6 mov ebx, dword ptr [esp + 0x20]
00490bfa xor dl, dl
00490bfc mov eax, dword ptr [ebx]
00490bfe mov edi, dword ptr [eax]
00490c00 cmp edi, eax
00490c02 je 0x490c57
00490c04 mov eax, edi
00490c06 mov edi, dword ptr [edi]
00490c08 mov ecx, dword ptr [eax + 8]
00490c0b cmp dword ptr [ecx + 0xb0], ebp
00490c11 jne 0x490c4b
00490c13 xor eax, eax
00490c15 xor edx, edx
00490c17 mov al, byte ptr [esi + 4]
00490c1a mov dl, byte ptr [esi + 5]
00490c1d shl eax, 8
00490c20 add eax, edx
00490c22 xor edx, edx
00490c24 mov dl, byte ptr [esi + 6]
00490c27 shl eax, 8
00490c2a add eax, edx
00490c2c xor edx, edx
00490c2e mov dl, byte ptr [esi + 7]
00490c31 shl eax, 8
00490c34 add eax, edx
00490c36 mov edx, eax
00490c38 and edx, 0xffff
00490c3e and eax, 0xffff0000
00490c43 mov dword ptr [ecx + 0x48], edx
00490c46 mov dword ptr [ecx + 0x3c], eax
00490c49 mov dl, 1
00490c4b cmp edi, dword ptr [ebx]
00490c4d jne 0x490c04
00490c4f test dl, dl
00490c51 jne 0x490de0
00490c57 mov eax, dword ptr [esp + 0x24]
00490c5b push 0xbc
00490c60 mov esi, dword ptr [eax + 8]
00490c63 add esi, 8
00490c66 call 0x59ef90
00490c6b add esp, 4
00490c6e test eax, eax
00490c70 je 0x490c81
00490c72 push ebp
00490c73 push esi
00490c74 mov ecx, eax
00490c76 call 0x48c360
00490c7b mov dword ptr [esp + 0x10], eax
00490c7f jmp 0x490c89
00490c81 mov dword ptr [esp + 0x10], 0
00490c89 lea ecx, [esp + 0x10]
00490c8d lea edx, [esp + 0x20]
00490c91 push ecx
00490c92 push edx
00490c93 mov ecx, ebx
00490c95 call 0x529050
00490c9a push ecx
00490c9b mov ecx, esp
00490c9d push eax
00490c9e call 0x50e140
00490ca3 lea eax, [esp + 0x2c]
00490ca7 mov ecx, ebx
00490ca9 push eax
00490caa call 0x4937f0
00490caf pop edi
00490cb0 pop esi
00490cb1 pop ebp
00490cb2 pop ebx
00490cb3 add esp, 0xc
00490cb6 ret
00490cb7 mov ebp, dword ptr [esp + 0x20]
00490cbb xor dl, dl
00490cbd mov eax, dword ptr [ebp]
00490cc0 mov edi, dword ptr [eax]
00490cc2 cmp edi, eax
00490cc4 je 0x490d08
00490cc6 mov eax, edi
00490cc8 xor ebx, ebx
00490cca mov bl, byte ptr [esi + 2]
00490ccd mov edi, dword ptr [edi]
00490ccf mov ecx, dword ptr [eax + 8]
00490cd2 xor eax, eax
00490cd4 mov al, byte ptr [esi + 1]
00490cd7 shl eax, 8
00490cda add eax, ebx
00490cdc xor ebx, ebx
00490cde mov bl, byte ptr [esi + 3]
00490ce1 shl eax, 8
00490ce4 add eax, ebx
00490ce6 mov ebx, dword ptr [ecx + 0xb0]
00490cec cmp ebx, eax
00490cee jne 0x490cfb
00490cf0 lea edx, [esi + 4]
00490cf3 push edx
00490cf4 call 0x48c490
00490cf9 mov dl, 1
00490cfb cmp edi, dword ptr [ebp]
00490cfe jne 0x490cc6
00490d00 test dl, dl
00490d02 jne 0x490de0
00490d08 push 0xbc
00490d0d call 0x59ef90
00490d12 add esp, 4
00490d15 test eax, eax
00490d17 je 0x490d44
00490d19 xor ecx, ecx
00490d1b xor edx, edx
00490d1d mov cl, byte ptr [esi + 1]
00490d20 mov dl, byte ptr [esi + 2]
00490d23 shl ecx, 8
00490d26 add ecx, edx
00490d28 xor edx, edx
00490d2a mov dl, byte ptr [esi + 3]
00490d2d add esi, 4
00490d30 shl ecx, 8
00490d33 add ecx, edx
00490d35 push ecx
00490d36 push esi
00490d37 mov ecx, eax
00490d39 call 0x48c3d0
00490d3e mov dword ptr [esp + 0x14], eax
00490d42 jmp 0x490d4c
00490d44 mov dword ptr [esp + 0x14], 0
00490d4c lea eax, [esp + 0x14]
00490d50 lea ecx, [esp + 0x20]
00490d54 push eax
00490d55 push ecx
00490d56 mov ecx, ebp
00490d58 call 0x529050
00490d5d push ecx
00490d5e mov ecx, esp
00490d60 push eax
00490d61 call 0x50e140
00490d66 lea edx, [esp + 0x2c]
00490d6a mov ecx, ebp
00490d6c push edx
00490d6d call 0x4937f0
00490d72 pop edi
00490d73 pop esi
00490d74 pop ebp
00490d75 pop ebx
00490d76 add esp, 0xc
00490d79 ret
00490d7a mov eax, dword ptr [esp + 0x20]
00490d7e mov edi, dword ptr [eax]
00490d80 mov ebp, dword ptr [edi]
00490d82 cmp ebp, edi
00490d84 je 0x490de0
00490d86 mov ecx, dword ptr [esp + 0x18]
00490d8a mov eax, ebp
00490d8c mov ebp, dword ptr [ebp]
00490d8f mov ebx, dword ptr [eax + 8]
00490d92 cmp dword ptr [ebx + 0xb0], ecx
00490d98 jne 0x490dd6
00490d9a mov eax, dword ptr [edi]
00490d9c cmp eax, edi
00490d9e je 0x490dc2
00490da0 mov ecx, dword ptr [eax + 8]
00490da3 mov esi, dword ptr [eax]
00490da5 cmp ecx, ebx
00490da7 jne 0x490dbc
00490da9 push ecx
00490daa lea edx, [esp + 0x28]
00490dae mov ecx, esp
00490db0 push edx
00490db1 mov dword ptr [ecx], eax
00490db3 mov ecx, dword ptr [esp + 0x28]
00490db7 call 0x48b660
00490dbc cmp esi, edi
00490dbe mov eax, esi
00490dc0 jne 0x490da0
00490dc2 test ebx, ebx
00490dc4 je 0x490dd6
00490dc6 mov ecx, ebx
00490dc8 call 0x48c430
00490dcd push ebx
00490dce call 0x59f050
00490dd3 add esp, 4
00490dd6 mov eax, dword ptr [esp + 0x20]
00490dda mov edi, dword ptr [eax]
00490ddc cmp ebp, edi
00490dde jne 0x490d86
00490de0 pop edi
00490de1 pop esi
00490de2 pop ebp
00490de3 pop ebx
00490de4 add esp, 0xc
00490de7 ret
00490de8 mov bh, 0xc
00490dea dec ecx
00490deb add byte ptr [edx + 0xd], bh
00490dee dec ecx
00490def add al, ah
00490df1 or eax, 0xde00049
00490df6 dec ecx
00490df7 add dh, dh
00490df9 or ecx, dword ptr [ecx]
00490dfc jp 0x490e0b
00490dfe dec ecx
00490dff add byte ptr [ebx - 0x74f3dbbc], cl
00490e05 dec esp
00490e06 and al, 8
00490e08 push eax
00490e09 mov eax, dword ptr [esp + 8]
00490e0d push ecx
00490e0e push eax
00490e0f mov ecx, dword ptr [eax]
00490e11 call 0x490e20
00490e16 ret
00490e17 nop
00490e18 nop
00490e19 nop
00490e1a nop
00490e1b nop
00490e1c nop
00490e1d nop
00490e1e nop
00490e1f nop
00490e20 sub esp, 0xc
00490e23 push ebx
00490e24 mov ebx, dword ptr [0x628c78]
00490e2a push ebp
00490e2b push esi
00490e2c mov eax, dword ptr [ebx]
00490e2e push edi
00490e2f mov esi, ecx
00490e31 push eax
00490e32 mov dword ptr [esp + 0x18], esi
00490e36 mov dword ptr [esp + 0x1c], ebx
00490e3a call 0x5322b0
00490e3f mov al, byte ptr [0x5d07d0]
00490e44 add esp, 4
00490e47 test al, al
00490e49 je 0x490e62
00490e4b mov ecx, dword ptr [ebx]
00490e4d push ecx
00490e4e call 0x5322c0
00490e53 add esp, 4
00490e56 xor eax, eax
00490e58 pop edi
00490e59 pop esi
00490e5a pop ebp
00490e5b pop ebx
00490e5c add esp, 0xc
00490e5f ret 0xc
00490e62 mov edi, dword ptr [esp + 0x28]
00490e66 mov dword ptr [esp + 0x10], 1
00490e6e mov eax, dword ptr [edi]
00490e70 add eax, -4
00490e73 cmp eax, 8
00490e76 ja 0x490fa9
00490e7c jmp dword ptr [eax*4 + 0x490fcc]
00490e83 lea edi, [esi + 0x170]
00490e89 mov byte ptr [esi + 0x17c], 0
00490e90 mov eax, dword ptr [edi]
00490e92 cmp dword ptr [eax], eax
00490e94 je 0x490ee9
00490e96 mov edx, dword ptr [edi]
00490e98 mov ebp, edx
00490e9a mov eax, dword ptr [edx + 4]
00490e9d mov ebx, dword ptr [eax + 8]
00490ea0 mov eax, dword ptr [ebp]
00490ea3 cmp eax, ebp
00490ea5 je 0x490ecb
00490ea7 mov ecx, dword ptr [eax + 8]
00490eaa mov esi, dword ptr [eax]
00490eac cmp ecx, ebx
00490eae jne 0x490ec1
00490eb0 push ecx
00490eb1 mov ecx, esp
00490eb3 mov dword ptr [ecx], eax
00490eb5 lea ecx, [esp + 0x2c]
00490eb9 push ecx
00490eba mov ecx, edi
00490ebc call 0x48b660
00490ec1 cmp esi, ebp
00490ec3 mov eax, esi
00490ec5 jne 0x490ea7
00490ec7 mov esi, dword ptr [esp + 0x14]
00490ecb test ebx, ebx
00490ecd je 0x490edf
00490ecf mov ecx, ebx
00490ed1 call 0x48c430
00490ed6 push ebx
00490ed7 call 0x59f050
00490edc add esp, 4
00490edf mov eax, dword ptr [edi]
00490ee1 cmp dword ptr [eax], eax
00490ee3 jne 0x490e96
00490ee5 mov ebx, dword ptr [esp + 0x18]
00490ee9 mov byte ptr [esi + 0x17d], 1
00490ef0 jmp 0x490fb1
00490ef5 mov eax, dword ptr [edi + 8]
00490ef8 xor edx, edx
00490efa xor ecx, ecx
00490efc mov dl, byte ptr [eax]
00490efe mov cl, byte ptr [eax + 1]
00490f01 mov ebp, edx
00490f03 xor edx, edx
00490f05 mov dl, byte ptr [eax + 2]
00490f08 shl ecx, 8
00490f0b add ecx, edx
00490f0d xor edx, edx
00490f0f mov dl, byte ptr [eax + 3]
00490f12 shl ecx, 8
00490f15 add ecx, edx
00490f17 mov edx, ebp
00490f19 sub edx, 0xb8
00490f1f je 0x490f51
00490f21 dec edx
00490f22 jne 0x490fb1
00490f28 push 0
00490f2a push 0
00490f2c push 0x80000000
00490f31 push ecx
00490f32 push 0xb9
00490f37 mov ecx, dword ptr [esi + 8]
00490f3a call 0x48c870
00490f3f add esi, 0x170
00490f45 push edi
00490f46 push esi
00490f47 call 0x490bb0
00490f4c add esp, 8
00490f4f jmp 0x490fb1
00490f51 test ecx, ecx
00490f53 jle 0x490f3f
00490f55 lea edx, [eax + 8]
00490f58 push 0
00490f5a push edx
00490f5b xor edx, edx
00490f5d mov dl, byte ptr [eax + 4]
00490f60 mov ebp, edx
00490f62 xor edx, edx
00490f64 mov dl, byte ptr [eax + 5]
00490f67 shl ebp, 8
00490f6a add ebp, edx
00490f6c xor edx, edx
00490f6e mov dl, byte ptr [eax + 6]
00490f71 shl ebp, 8
00490f74 add ebp, edx
00490f76 xor edx, edx
00490f78 mov dl, byte ptr [eax + 7]
00490f7b shl ebp, 8
00490f7e add ebp, edx
00490f80 push ebp
00490f81 push ecx
00490f82 push 0xb8
00490f87 jmp 0x490f37
00490f89 mov ecx, dword ptr [esi]
00490f8b call 0x48b210
00490f90 mov byte ptr [esi + 0x17c], 1
00490f97 jmp 0x490fb1
00490f99 mov byte ptr [esi + 0x17c], 0
00490fa0 mov byte ptr [esi + 0x17d], 1
00490fa7 jmp 0x490fb1
00490fa9 mov dword ptr [esp + 0x10], 0
00490fb1 mov eax, dword ptr [ebx]
00490fb3 push eax
00490fb4 call 0x5322c0
00490fb9 mov eax, dword ptr [esp + 0x14]
00490fbd add esp, 4
00490fc0 pop edi
00490fc1 pop esi
00490fc2 pop ebp
00490fc3 pop ebx
00490fc4 add esp, 0xc
00490fc7 ret 0xc
00490fca mov edi, edi
00490fcc mov dword ptr [edi], ecx
00490fce dec ecx
00490fcf add byte ptr [ecx - 0x56ffb6f1], bl
00490fd5 cmovns eax, dword ptr [eax]
00490fd8 test eax, 0xa900490f
00490fdd cmovns eax, dword ptr [eax]
00490fe0 or dword ptr [esi], 0x49
00490fe3 add byte ptr [ebx - 0x56ffb6f2], al
00490fe9 cmovns eax, dword ptr [eax]
00490fec cmc
00490fed push cs
00490fee dec ecx
00490fef add byte ptr [ebx - 0x74f3dbbc], cl
00490ff5 dec esp
00490ff6 and al, 8
00490ff8 push eax
00490ff9 mov eax, dword ptr [esp + 8]
00490ffd push ecx
00490ffe push eax
00490fff mov ecx, dword ptr [eax]
00491001 call 0x491010
00491006 ret
00491007 nop
00491008 nop
00491009 nop
0049100a nop
0049100b nop
0049100c nop
0049100d nop
0049100e nop
0049100f nop
00491010 mov al, byte ptr [0x5d07d0]
00491015 sub esp, 0x50
00491018 test al, al
0049101a push ebx
0049101b push ebp
0049101c push esi
0049101d push edi
0049101e mov esi, ecx
00491020 je 0x49102e
00491022 xor eax, eax
00491024 pop edi
00491025 pop esi
00491026 pop ebp
00491027 pop ebx
00491028 add esp, 0x50
0049102b ret 0xc
0049102e mov eax, dword ptr [0x628c78]
00491033 test eax, eax
00491035 jne 0x491041
00491037 pop edi
00491038 pop esi
00491039 pop ebp
0049103a pop ebx
0049103b add esp, 0x50
0049103e ret 0xc
00491041 mov edi, eax
00491043 mov dword ptr [esp + 0x14], edi
00491047 mov eax, dword ptr [edi]
00491049 push eax
0049104a call 0x5322b0
0049104f mov al, byte ptr [0x5d07d0]
00491054 add esp, 4
00491057 test al, al
00491059 je 0x491072
0049105b mov ecx, dword ptr [edi]
0049105d push ecx
0049105e call 0x5322c0
00491063 add esp, 4
00491066 xor eax, eax
00491068 pop edi
00491069 pop esi
0049106a pop ebp
0049106b pop ebx
0049106c add esp, 0x50
0049106f ret 0xc
00491072 mov ebx, dword ptr [esp + 0x6c]
00491076 cmp dword ptr [ebx], 6
00491079 jne 0x49117d
0049107f mov ebp, dword ptr [esp + 0x68]
00491083 mov dl, byte ptr [ebp + 0x14]
00491086 cmp dl, 0x73
00491089 je 0x49111a
0049108f mov eax, dword ptr [esi]
00491091 mov cl, byte ptr [eax + 0x14]
00491094 test cl, cl
00491096 je 0x4910b7
00491098 mov ecx, dword ptr [esi + 0x16c]
0049109e cmp dword ptr [ecx], ecx
004910a0 je 0x49111a
004910a2 mov cl, byte ptr [eax + 0x14]
004910a5 test cl, cl
004910a7 je 0x4910b7
004910a9 mov eax, dword ptr [esi + 0x16c]
004910af cmp dword ptr [eax], eax
004910b1 je 0x491188
004910b7 push 0xcc
004910bc call 0x59ef90
004910c1 add esp, 4
004910c4 test eax, eax
004910c6 je 0x4910d2
004910c8 push ebp
004910c9 mov ecx, eax
004910cb call 0x48a570
004910d0 jmp 0x4910d4
004910d2 xor eax, eax
004910d4 mov dword ptr [ebp + 0x5c], eax
004910d7 mov ecx, dword ptr [esi + 4]
004910da test ecx, ecx
004910dc mov dword ptr [esp + 0x68], eax
004910e0 je 0x4910f3
004910e2 mov ecx, dword ptr [esi + 0x164]
004910e8 cmp dword ptr [ecx], ecx
004910ea jne 0x4910f3
004910ec mov byte ptr [eax + 0xb9], 1
004910f3 mov ecx, esi
004910f5 call 0x490af0
004910fa mov edx, dword ptr [esp + 0x68]
004910fe lea ecx, [esi + 0x164]
00491104 mov dword ptr [edx + 0xac], eax
0049110a lea eax, [esp + 0x68]
0049110e push eax
0049110f call 0x493100
00491114 mov edi, dword ptr [esp + 0x68]
00491118 jmp 0x491184
0049111a mov eax, dword ptr [esi + 0x16c]
00491120 lea edi, [esi + 0x16c]
00491126 cmp dword ptr [eax], eax
00491128 jne 0x49112f
0049112a cmp dl, 0x70
0049112d jne 0x491188
0049112f push 0xcc
00491134 call 0x59ef90
00491139 add esp, 4
0049113c test eax, eax
0049113e je 0x49114a
00491140 push ebp
00491141 mov ecx, eax
00491143 call 0x48a570
00491148 jmp 0x49114c
0049114a xor eax, eax
0049114c mov dword ptr [esp + 0x10], eax
00491150 mov dword ptr [ebp + 0x5c], eax
00491153 mov ecx, esi
00491155 mov byte ptr [eax + 0xb8], 1
0049115c call 0x490af0
00491161 mov ecx, dword ptr [esp + 0x10]
00491165 lea edx, [esp + 0x10]
00491169 push edx
0049116a mov dword ptr [ecx + 0xac], eax
00491170 mov ecx, edi
00491172 call 0x493100
00491177 mov edi, dword ptr [esp + 0x10]
0049117b jmp 0x491184
0049117d mov eax, dword ptr [esp + 0x68]
00491181 mov edi, dword ptr [eax + 0x5c]
00491184 test edi, edi
00491186 jne 0x4911a3
00491188 mov ecx, dword ptr [esp + 0x14]
0049118c mov edx, dword ptr [ecx]
0049118e push edx
0049118f call 0x5322c0
00491194 add esp, 4
00491197 xor eax, eax
00491199 pop edi
0049119a pop esi
0049119b pop ebp
0049119c pop ebx
0049119d add esp, 0x50
004911a0 ret 0xc
004911a3 cmp dword ptr [edi], 0
004911a6 jne 0x4911c3
004911a8 mov eax, dword ptr [esp + 0x14]
004911ac mov ecx, dword ptr [eax]
004911ae push ecx
004911af call 0x5322c0
004911b4 add esp, 4
004911b7 xor eax, eax
004911b9 pop edi
004911ba pop esi
004911bb pop ebp
004911bc pop ebx
004911bd add esp, 0x50
004911c0 ret 0xc
004911c3 mov ecx, dword ptr [ebx]
004911c5 mov ebp, dword ptr [edi + 0xa4]
004911cb mov dword ptr [esp + 0x18], 1
004911d3 lea eax, [ecx - 6]
004911d6 cmp eax, 6
004911d9 ja 0x491c34
004911df jmp dword ptr [eax*4 + 0x491c5c]
004911e6 cmp ecx, 9
004911e9 jne 0x4911f2
004911eb push 0x5d08d8
004911f0 jmp 0x4911f7
004911f2 push 0x5d08d0
004911f7 push edi
004911f8 call 0x492cf0
004911fd add esp, 8
00491200 mov ecx, edi
00491202 call 0x48a8c0
00491207 jmp 0x491c3c
0049120c mov eax, dword ptr [ebx + 8]
0049120f xor ecx, ecx
00491211 mov cl, byte ptr [eax]
00491213 cmp ecx, 0xb0
00491219 mov dword ptr [esp + 0x1c], ecx
0049121d jge 0x49122c
0049121f push eax
00491220 mov ecx, edi
00491222 call 0x48a2c0
00491227 jmp 0x491c3c
0049122c mov edx, dword ptr [edi + 0xac]
00491232 lea eax, [esp + 0x20]
00491236 push edx
00491237 push 0x5d08b0
0049123c push eax
0049123d call 0x5a0fbf
00491242 mov ecx, dword ptr [ebx + 4]
00491245 mov eax, dword ptr [ebx + 8]
00491248 add esp, 0xc
0049124b cmp ecx, 4
0049124e jl 0x491273
00491250 xor ecx, ecx
00491252 xor edx, edx
00491254 mov cl, byte ptr [eax + 1]
00491257 mov dl, byte ptr [eax + 2]
0049125a mov ebx, ecx
0049125c xor ecx, ecx
0049125e mov cl, byte ptr [eax + 3]
00491261 shl ebx, 8
00491264 add ebx, edx
00491266 shl ebx, 8
00491269 add ebx, ecx
0049126b shl ebx, 8
0049126e sar ebx, 8
00491271 jmp 0x491277
00491273 mov ebx, dword ptr [esp + 0x6c]
00491277 mov edx, dword ptr [esp + 0x1c]
0049127b lea ecx, [edx - 0xb1]
00491281 cmp ecx, 0x14
00491284 ja 0x491c3c
0049128a jmp dword ptr [ecx*4 + 0x491c78]
00491291 lea ecx, [edi + 0x24]
00491294 push 0
00491296 xor edx, edx
00491298 push ecx
00491299 mov dl, byte ptr [eax + 4]
0049129c xor ecx, ecx
0049129e mov cl, byte ptr [eax + 5]
004912a1 shl edx, 8
004912a4 add edx, ecx
004912a6 xor ecx, ecx
004912a8 mov cl, byte ptr [eax + 6]
004912ab shl edx, 8
004912ae add edx, ecx
004912b0 xor ecx, ecx
004912b2 mov cl, byte ptr [eax + 7]
004912b5 shl edx, 8
004912b8 add edx, ecx
004912ba mov ecx, dword ptr [esi + 0x10]
004912bd push edx
004912be mov edx, dword ptr [edi + 0xac]
004912c4 push edx
004912c5 push 0xb8
004912ca call 0x48c870
004912cf jmp 0x491c3c
004912d4 mov cl, byte ptr [edi + 0xba]
004912da test cl, cl
004912dc je 0x491c3c
004912e2 mov cl, byte ptr [edi + 0xbd]
004912e8 test cl, cl
004912ea jne 0x491c3c
004912f0 add eax, 4
004912f3 push eax
004912f4 push edi
004912f5 mov dword ptr [esp + 0x74], eax
004912f9 call 0x492cf0
004912fe add esp, 8
00491301 test ebp, ebp
00491303 jne 0x49135a
00491305 mov ecx, dword ptr [esi + 0xc]
00491308 mov ebp, dword ptr [edi + 0xac]
0049130e push ebx
0049130f call 0x48c980
00491314 mov ecx, dword ptr [esi + 0xc]
00491317 push eax
00491318 mov eax, dword ptr [esp + 0x70]
0049131c push eax
0049131d push ebx
0049131e push ebp
0049131f push 0xbb
00491324 call 0x48c870
00491329 cmp ebx, -1
0049132c je 0x491c3c
00491332 mov eax, dword ptr [edi + 0xac]
00491338 cmp ebx, eax
0049133a je 0x491c3c
00491340 mov ecx, dword ptr [esp + 0x6c]
00491344 push edi
00491345 push ecx
00491346 mov ecx, dword ptr [esi + 0xc]
00491349 push ebx
0049134a push eax
0049134b push 0xbb
00491350 call 0x48c870
00491355 jmp 0x491c3c
0049135a mov edi, dword ptr [edi + 0xac]
00491360 lea esi, [ebp + 0x64]
00491363 push ebx
00491364 mov ecx, esi
00491366 call 0x48c980
0049136b mov edx, dword ptr [esp + 0x6c]
0049136f push eax
00491370 push edx
00491371 push ebx
00491372 push edi
00491373 push 0xbb
00491378 mov ecx, esi
0049137a call 0x48c870
0049137f cmp ebx, -1
00491382 je 0x491c3c
00491388 cmp ebx, edi
0049138a je 0x491c3c
00491390 push edi
00491391 mov ecx, esi
00491393 call 0x48c980
00491398 push eax
00491399 mov eax, dword ptr [esp + 0x70]
0049139d push eax
0049139e push ebx
0049139f push edi
004913a0 push 0xbb
004913a5 mov ecx, esi
004913a7 call 0x48c870
004913ac jmp 0x491c3c
004913b1 mov cl, byte ptr [edi + 0xba]
004913b7 test cl, cl
004913b9 je 0x491c3c
004913bf mov cl, byte ptr [edi + 0xbd]
004913c5 test cl, cl
004913c7 jne 0x491c3c
004913cd mov ecx, dword ptr [esi + 4]
004913d0 test ebp, ebp
004913d2 jne 0x491486
004913d8 test ecx, ecx
004913da jne 0x491c3c
004913e0 push 0xcc8
004913e5 lea ebp, [eax + 0x18]
004913e8 call 0x59ef90
004913ed mov ebx, eax
004913ef add esp, 4
004913f2 test ebx, ebx
004913f4 je 0x49140d
004913f6 push esi
004913f7 push ebp
004913f8 mov ecx, esi
004913fa call 0x490af0
004913ff push eax
00491400 mov ecx, ebx
00491402 call 0x48b9b0
00491407 mov dword ptr [esp + 0x6c], eax
0049140b jmp 0x491415
0049140d mov dword ptr [esp + 0x6c], 0
00491415 lea ecx, [esp + 0x6c]
00491419 push ecx
0049141a lea ecx, [esi + 0x174]
00491420 call 0x493100
00491425 mov ebx, dword ptr [esi + 0x158]
0049142b mov ecx, dword ptr [esi]
0049142d inc ebx
0049142e mov dword ptr [esi + 0x158], ebx
00491434 mov dl, byte ptr [ecx + 0x14]
00491437 test dl, dl
00491439 mov eax, ebx
0049143b jne 0x491460
0049143d mov ecx, dword ptr [ecx + 0x10]
00491440 test ecx, ecx
00491442 je 0x491460
00491444 mov ebp, dword ptr [esi + 0x154]
0049144a push 0
0049144c shl eax, 0x10
0049144f add eax, ebp
00491451 push 0
00491453 push eax
00491454 push 0
00491456 push 0xb8
0049145b call 0x48c870
00491460 mov edx, dword ptr [esp + 0x6c]
00491464 mov ecx, esi
00491466 push edx
00491467 call 0x490b70
0049146c mov eax, dword ptr [esp + 0x6c]
00491470 test eax, eax
00491472 je 0x491c3c
00491478 push eax
00491479 push edi
0049147a mov ecx, esi
0049147c call 0x4924d0
00491481 jmp 0x491c3c
00491486 test ecx, ecx
00491488 je 0x49149c
0049148a add eax, 0x18
0049148d push eax
0049148e mov eax, dword ptr [esi]
00491490 mov ecx, dword ptr [eax + 4]
00491493 push ecx
00491494 call 0x55c0b0
00491499 add esp, 8
0049149c mov edx, dword ptr [esp + 0x6c]
004914a0 mov ecx, ebp
004914a2 mov eax, dword ptr [edx + 8]
004914a5 add eax, 0x18
004914a8 push eax
004914a9 call 0x48ba70
004914ae mov eax, dword ptr [esi + 0x164]
004914b4 mov ecx, dword ptr [eax]
004914b6 cmp ecx, eax
004914b8 mov dword ptr [esp + 0x6c], ecx
004914bc je 0x491c3c
004914c2 lea ecx, [esp + 0x68]
004914c6 push 0
004914c8 push ecx
004914c9 lea ecx, [esp + 0x74]
004914cd call 0x4930f0
004914d2 mov eax, dword ptr [eax]
004914d4 mov ecx, ebp
004914d6 add eax, 8
004914d9 mov edx, dword ptr [eax]
004914db push edx
004914dc call 0x48baa0
004914e1 mov eax, dword ptr [esp + 0x6c]
004914e5 mov ecx, dword ptr [esi + 0x164]
004914eb cmp eax, ecx
004914ed jne 0x4914c2
004914ef jmp 0x491c3c
004914f4 mov al, byte ptr [edi + 0xba]
004914fa test al, al
004914fc je 0x491c3c
00491502 mov al, byte ptr [edi + 0xbd]
00491508 test al, al
0049150a jne 0x491c3c
00491510 mov ecx, dword ptr [esi + 0x174]
00491516 mov eax, dword ptr [ecx]
00491518 cmp eax, ecx
0049151a je 0x4915b5
00491520 mov edx, eax
00491522 mov eax, dword ptr [eax]
00491524 mov edx, dword ptr [edx + 8]
00491527 mov dword ptr [esp + 0x6c], edx
0049152b cmp dword ptr [edx + 0x70], ebx
0049152e je 0x491536
00491530 cmp eax, ecx
00491532 jne 0x491520
00491534 jmp 0x4915b5
00491536 lea eax, [edx + 0x40]
00491539 lea ebp, [edi + 0x84]
0049153f mov dl, byte ptr [ebp]
00491542 mov cl, dl
00491544 cmp dl, byte ptr [eax]
00491546 jne 0x491564
00491548 test cl, cl
0049154a je 0x491560
0049154c mov dl, byte ptr [ebp + 1]
0049154f mov cl, dl
00491551 cmp dl, byte ptr [eax + 1]
00491554 jne 0x491564
00491556 add ebp, 2
00491559 add eax, 2
0049155c test cl, cl
0049155e jne 0x49153f
00491560 xor eax, eax
00491562 jmp 0x491569
00491564 sbb eax, eax
00491566 sbb eax, -1
00491569 test eax, eax
0049156b je 0x491586
0049156d mov ecx, dword ptr [esi + 8]
00491570 push edi
00491571 push 0
00491573 push 0x80000000
00491578 push 0xa
0049157a push 0xc6
0049157f call 0x48c870
00491584 jmp 0x4915b5
00491586 mov eax, dword ptr [esp + 0x6c]
0049158a cmp dword ptr [eax + 0xac], 8
00491591 jne 0x4915ac
00491593 mov ecx, dword ptr [esi + 8]
00491596 push edi
00491597 push 0
00491599 push 0x80000000
0049159e push 0xb
004915a0 push 0xc6
004915a5 call 0x48c870
004915aa jmp 0x4915b5
004915ac push eax
004915ad push edi
004915ae mov ecx, esi
004915b0 call 0x4924d0
004915b5 mov ebp, dword ptr [esi + 0x178]
004915bb mov eax, dword ptr [ebp]
004915be cmp eax, ebp
004915c0 je 0x491c3c
004915c6 mov ecx, eax
004915c8 mov eax, dword ptr [eax]
004915ca mov edx, dword ptr [ecx + 8]
004915cd cmp dword ptr [edx + 0x70], ebx
004915d0 je 0x4915db
004915d2 cmp eax, ebp
004915d4 jne 0x4915c6
004915d6 jmp 0x491c3c
004915db lea ebp, [edx + 0x40]
004915de lea eax, [edi + 0x84]
004915e4 mov bl, byte ptr [eax]
004915e6 mov cl, bl
004915e8 cmp bl, byte ptr [ebp]
004915eb jne 0x491609
004915ed test cl, cl
004915ef je 0x491605
004915f1 mov bl, byte ptr [eax + 1]
004915f4 mov cl, bl
004915f6 cmp bl, byte ptr [ebp + 1]
004915f9 jne 0x491609
004915fb add eax, 2
004915fe add ebp, 2
00491601 test cl, cl
00491603 jne 0x4915e4
00491605 xor eax, eax
00491607 jmp 0x49160e
00491609 sbb eax, eax
0049160b sbb eax, -1
0049160e test eax, eax
00491610 je 0x49162e
00491612 mov ecx, dword ptr [esi + 8]
00491615 push edi
00491616 push 0
00491618 push 0x80000000
0049161d push 0xa
0049161f push 0xc6
00491624 call 0x48c870
00491629 jmp 0x491c3c
0049162e cmp dword ptr [edx + 0xac], 8
00491635 jne 0x491653
00491637 mov ecx, dword ptr [esi + 8]
0049163a push edi
0049163b push 0
0049163d push 0x80000000
00491642 push 0xb
00491644 push 0xc6
00491649 call 0x48c870
0049164e jmp 0x491c3c
00491653 push edx
00491654 push edi
00491655 mov ecx, esi
00491657 call 0x4924d0
0049165c jmp 0x491c3c
00491661 xor ecx, ecx
00491663 xor edx, edx
00491665 mov cl, byte ptr [eax + 4]
00491668 mov dl, byte ptr [eax + 5]
0049166b shl ecx, 8
0049166e add ecx, edx
00491670 xor edx, edx
00491672 mov dl, byte ptr [eax + 6]
00491675 shl ecx, 8
00491678 add ecx, edx
0049167a xor edx, edx
0049167c mov dl, byte ptr [eax + 7]
0049167f shl ecx, 8
00491682 add ecx, edx
00491684 test ebp, ebp
00491686 mov dword ptr [edi + 0xb0], ecx
0049168c jne 0x4916d3
0049168e mov eax, dword ptr [esi + 0x168]
00491694 mov ebp, dword ptr [eax]
00491696 cmp ebp, eax
00491698 je 0x491c3c
0049169e mov eax, dword ptr [ebp + 8]
004916a1 cmp dword ptr [eax + 0xac], ebx
004916a7 jne 0x4916c1
004916a9 mov eax, dword ptr [eax + 0xb0]
004916af mov ecx, dword ptr [esi + 0xc]
004916b2 push edi
004916b3 push 0
004916b5 push eax
004916b6 push ebx
004916b7 push 0xc3
004916bc call 0x48c870
004916c1 mov ebp, dword ptr [ebp]
004916c4 mov eax, dword ptr [esi + 0x168]
004916ca cmp ebp, eax
004916cc jne 0x49169e
004916ce jmp 0x491c3c
004916d3 push edi
004916d4 push ebx
004916d5 mov ecx, ebp
004916d7 call 0x48c1d0
004916dc jmp 0x491c3c
004916e1 mov al, byte ptr [edi + 0xba]
004916e7 test al, al
004916e9 je 0x491c3c
004916ef mov al, byte ptr [edi + 0xbd]
004916f5 test al, al
004916f7 jne 0x491c3c
004916fd test ebp, ebp
004916ff je 0x491c3c
00491705 push ebx
00491706 mov ecx, ebp
00491708 call 0x48bee0
0049170d mov ebx, eax
0049170f test ebx, ebx
00491711 je 0x491c3c
00491717 mov al, byte ptr [ebx + 0xb9]
0049171d test al, al
0049171f je 0x49173b
00491721 mov ecx, ebp
00491723 call 0x48c000
00491728 push 0x5d089c
0049172d push edi
0049172e call 0x492cf0
00491733 add esp, 8
00491736 jmp 0x491c3c
0049173b mov ecx, dword ptr [esi + 8]
0049173e push ebx
0049173f push 0
00491741 push 0x80000000
00491746 push 9
00491748 push 0xc6
0049174d call 0x48c870
00491752 push ebx
00491753 mov ecx, esi
00491755 call 0x4925a0
0049175a push 0x5d088c
0049175f push edi
00491760 call 0x492cf0
00491765 add esp, 8
00491768 jmp 0x491c3c
0049176d mov al, byte ptr [edi + 0xba]
00491773 test al, al
00491775 je 0x491c3c
0049177b mov al, byte ptr [edi + 0xbd]
00491781 test al, al
00491783 jne 0x491c3c
00491789 push 0x5d0884
0049178e push edi
0049178f call 0x492cf0
00491794 add esp, 8
00491797 mov ecx, esi
00491799 push edi
0049179a call 0x4925a0
0049179f jmp 0x491c3c
004917a4 mov al, byte ptr [edi + 0xba]
004917aa test al, al
004917ac je 0x491c3c
004917b2 mov al, byte ptr [edi + 0xbd]
004917b8 test al, al
004917ba jne 0x491c3c
004917c0 test ebp, ebp
004917c2 je 0x491c3c
004917c8 push 0x5d0878
004917cd push edi
004917ce call 0x492cf0
004917d3 mov al, byte ptr [ebp + 0xcc3]
004917d9 add esp, 8
004917dc test al, al
004917de push edi
004917df mov ecx, ebp
004917e1 jne 0x491851
004917e3 call 0x48bf10
004917e8 lea ecx, [esp + 0x6c]
004917ec mov dword ptr [esp + 0x6c], ebp
004917f0 push ecx
004917f1 lea ecx, [esi + 0x174]
004917f7 call 0x493180
004917fc lea edx, [esp + 0x6c]
00491800 lea edi, [esi + 0x178]
00491806 lea eax, [esp + 0x68]
0049180a push edx
0049180b push eax
0049180c mov ecx, edi
0049180e call 0x529050
00491813 push ecx
00491814 mov ecx, esp
00491816 push eax
00491817 call 0x50e140
0049181c lea ecx, [esp + 0x24]
00491820 push ecx
00491821 mov ecx, edi
00491823 call 0x4937f0
00491828 mov eax, dword ptr [esi + 0x15c]
0049182e test eax, eax
00491830 lea edx, [eax + 1]
00491833 mov dword ptr [esi + 0x15c], edx
00491839 jne 0x491c3c
0049183f push 0x490640
00491844 call 0x560140
00491849 add esp, 4
0049184c jmp 0x491c3c
00491851 call 0x48bf10
00491856 jmp 0x491c3c
0049185b test ebp, ebp
0049185d je 0x491c3c
00491863 mov ecx, ebp
00491865 call 0x48bfb0
0049186a jmp 0x491c3c
0049186f test ebp, ebp
00491871 je 0x491c3c
00491877 mov eax, dword ptr [esp + 0x6c]
0049187b push edi
0049187c push eax
0049187d mov ecx, ebp
0049187f call 0x48c050
00491884 jmp 0x491c3c
00491889 test ebp, ebp
0049188b je 0x491c3c
00491891 mov ecx, dword ptr [esp + 0x6c]
00491895 push edi
00491896 push ecx
00491897 mov ecx, ebp
00491899 call 0x48c0f0
0049189e jmp 0x491c3c
004918a3 test ebp, ebp
004918a5 je 0x491c3c
004918ab mov edx, dword ptr [esp + 0x6c]
004918af push edi
004918b0 push edx
004918b1 mov ecx, ebp
004918b3 call 0x48c170
004918b8 jmp 0x491c3c
004918bd test ebp, ebp
004918bf je 0x491c3c
004918c5 xor ecx, ecx
004918c7 xor edx, edx
004918c9 mov cl, byte ptr [eax + 4]
004918cc mov dl, byte ptr [eax + 5]
004918cf shl ecx, 8
004918d2 add ecx, edx
004918d4 xor edx, edx
004918d6 mov dl, byte ptr [eax + 6]
004918d9 shl ecx, 8
004918dc add ecx, edx
004918de xor edx, edx
004918e0 mov dl, byte ptr [eax + 7]
004918e3 shl ecx, 8
004918e6 add ecx, edx
004918e8 push ecx
004918e9 push ebx
004918ea push edi
004918eb mov ecx, esi
004918ed call 0x4929b0
004918f2 jmp 0x491c3c
004918f7 mov ecx, edi
004918f9 call 0x48a700
004918fe mov eax, dword ptr [esi + 4]
00491901 xor ebx, ebx
00491903 cmp eax, ebx
00491905 jne 0x49199d
0049190b mov al, byte ptr [edi + 0xb8]
00491911 test al, al
00491913 je 0x491c3c
00491919 mov eax, dword ptr [esi + 0x170]
0049191f cmp dword ptr [eax], eax
00491921 je 0x491977
00491923 mov ecx, eax
00491925 mov eax, dword ptr [ecx]
00491927 mov dword ptr [esp + 0x6c], eax
0049192b mov eax, dword ptr [eax]
0049192d cmp eax, ecx
0049192f mov dword ptr [esp + 0x6c], eax
00491933 je 0x491977
00491935 mov eax, dword ptr [eax + 8]
00491938 push edi
00491939 mov edx, dword ptr [eax + 0x48]
0049193c lea ecx, [eax + 0x4c]
0049193f push ecx
00491940 mov ecx, dword ptr [eax + 0x3c]
00491943 mov eax, dword ptr [eax + 0xb0]
00491949 or edx, ecx
0049194b mov ecx, dword ptr [esi + 8]
0049194e push edx
0049194f push eax
00491950 push 0xb8
00491955 call 0x48c870
0049195a lea ecx, [esp + 0x1c]
0049195e push ebx
0049195f push ecx
00491960 lea ecx, [esp + 0x74]
00491964 call 0x4930f0
00491969 mov eax, dword ptr [esp + 0x6c]
0049196d mov ecx, dword ptr [esi + 0x170]
00491973 cmp eax, ecx
00491975 jne 0x491935
00491977 mov eax, dword ptr [edi + 0xac]
0049197d mov ecx, dword ptr [esi + 0x10]
00491980 lea edx, [edi + 0x24]
00491983 push ebx
00491984 push edx
00491985 push ebx
00491986 push eax
00491987 push 0xb8
0049198c call 0x48c870
00491991 mov byte ptr [edi + 0xba], 1
00491998 jmp 0x491c3c
0049199d mov al, byte ptr [edi + 0xb9]
004919a3 test al, al
004919a5 je 0x491ab9
004919ab mov eax, dword ptr [esi + 0x168]
004919b1 mov ebp, dword ptr [eax]
004919b3 cmp ebp, eax
004919b5 je 0x4919e5
004919b7 mov eax, dword ptr [ebp + 8]
004919ba push edi
004919bb mov edx, dword ptr [eax + 0xac]
004919c1 lea ecx, [eax + 0x24]
004919c4 push ecx
004919c5 mov ecx, dword ptr [esi + 0xc]
004919c8 push 0x80000000
004919cd push edx
004919ce push 0xb0
004919d3 call 0x48c870
004919d8 mov ebp, dword ptr [ebp]
004919db mov eax, dword ptr [esi + 0x168]
004919e1 cmp ebp, eax
004919e3 jne 0x4919b7
004919e5 push 0xcc8
004919ea call 0x59ef90
004919ef mov ebp, eax
004919f1 add esp, 4
004919f4 cmp ebp, ebx
004919f6 je 0x491a12
004919f8 lea eax, [esi + 0x14]
004919fb push esi
004919fc push eax
004919fd mov ecx, esi
004919ff call 0x490af0
00491a04 push eax
00491a05 mov ecx, ebp
00491a07 call 0x48b9b0
00491a0c mov dword ptr [esp + 0x6c], eax
00491a10 jmp 0x491a16
00491a12 mov dword ptr [esp + 0x6c], ebx
00491a16 lea ecx, [esp + 0x6c]
00491a1a lea ebp, [esi + 0x174]
00491a20 lea edx, [esp + 0x68]
00491a24 push ecx
00491a25 push edx
00491a26 mov ecx, ebp
00491a28 call 0x529050
00491a2d push ecx
00491a2e mov ecx, esp
00491a30 push eax
00491a31 call 0x50e140
00491a36 lea eax, [esp + 0x24]
00491a3a mov ecx, ebp
00491a3c push eax
00491a3d call 0x4937f0
00491a42 mov ebp, dword ptr [esi + 0x158]
00491a48 mov ecx, dword ptr [esi]
00491a4a inc ebp
00491a4b mov dword ptr [esi + 0x158], ebp
00491a51 mov dl, byte ptr [ecx + 0x14]
00491a54 test dl, dl
00491a56 mov eax, ebp
00491a58 jne 0x491a7a
00491a5a mov ecx, dword ptr [ecx + 0x10]
00491a5d cmp ecx, ebx
00491a5f je 0x491a7a
00491a61 mov edx, dword ptr [esi + 0x154]
00491a67 push ebx
00491a68 shl eax, 0x10
00491a6b add eax, edx
00491a6d push ebx
00491a6e push eax
00491a6f push ebx
00491a70 push 0xb8
00491a75 call 0x48c870
00491a7a mov ecx, dword ptr [esp + 0x6c]
00491a7e push ecx
00491a7f mov ecx, esi
00491a81 call 0x490b70
00491a86 mov eax, dword ptr [esp + 0x6c]
00491a8a cmp eax, ebx
00491a8c je 0x491a97
00491a8e push eax
00491a8f push edi
00491a90 mov ecx, esi
00491a92 call 0x4924d0
00491a97 push edi
00491a98 push ebx
00491a99 push 0x80000000
00491a9e mov byte ptr [edi + 0xba], 1
00491aa5 mov ecx, dword ptr [esi + 8]
00491aa8 push 0xe
00491aaa push 0xc6
00491aaf call 0x48c870
00491ab4 jmp 0x491c3c
00491ab9 mov eax, dword ptr [esi + 0x174]
00491abf cmp dword ptr [eax], eax
00491ac1 je 0x491b4c
00491ac7 mov eax, dword ptr [esi + 0x168]
00491acd mov ebp, dword ptr [eax]
00491acf cmp ebp, eax
00491ad1 je 0x491b01
00491ad3 mov eax, dword ptr [ebp + 8]
00491ad6 mov ecx, dword ptr [esi + 0xc]
00491ad9 push edi
00491ada lea edx, [eax + 0x24]
00491add mov eax, dword ptr [eax + 0xac]
00491ae3 push edx
00491ae4 push 0x80000000
00491ae9 push eax
00491aea push 0xb0
00491aef call 0x48c870
00491af4 mov ebp, dword ptr [ebp]
00491af7 mov eax, dword ptr [esi + 0x168]
00491afd cmp ebp, eax
00491aff jne 0x491ad3
00491b01 mov ecx, dword ptr [esi + 0x174]
00491b07 lea eax, [edi + 0x84]
00491b0d mov edx, dword ptr [ecx]
00491b0f mov edx, dword ptr [edx + 8]
00491b12 lea ebp, [edx + 0x40]
00491b15 mov bl, byte ptr [eax]
00491b17 mov cl, bl
00491b19 cmp bl, byte ptr [ebp]
00491b1c jne 0x491b3a
00491b1e test cl, cl
00491b20 je 0x491b36
00491b22 mov bl, byte ptr [eax + 1]
00491b25 mov cl, bl
00491b27 cmp bl, byte ptr [ebp + 1]
00491b2a jne 0x491b3a
00491b2c add eax, 2
00491b2f add ebp, 2
00491b32 test cl, cl
00491b34 jne 0x491b15
00491b36 xor eax, eax
00491b38 jmp 0x491b3f
00491b3a sbb eax, eax
00491b3c sbb eax, -1
00491b3f test eax, eax
00491b41 je 0x491be9
00491b47 jmp 0x491bd6
00491b4c mov eax, dword ptr [esi + 0x178]
00491b52 cmp dword ptr [eax], eax
00491b54 je 0x491c2e
00491b5a mov eax, dword ptr [esi + 0x168]
00491b60 mov ebp, dword ptr [eax]
00491b62 cmp ebp, eax
00491b64 je 0x491b94
00491b66 mov eax, dword ptr [ebp + 8]
00491b69 push edi
00491b6a mov edx, dword ptr [eax + 0xac]
00491b70 lea ecx, [eax + 0x24]
00491b73 push ecx
00491b74 mov ecx, dword ptr [esi + 0xc]
00491b77 push 0x80000000
00491b7c push edx
00491b7d push 0xb0
00491b82 call 0x48c870
00491b87 mov ebp, dword ptr [ebp]
00491b8a mov eax, dword ptr [esi + 0x168]
00491b90 cmp ebp, eax
00491b92 jne 0x491b66
00491b94 mov eax, dword ptr [esi + 0x178]
00491b9a mov ecx, dword ptr [eax]
00491b9c lea eax, [edi + 0x84]
00491ba2 mov edx, dword ptr [ecx + 8]
00491ba5 lea ebp, [edx + 0x40]
00491ba8 mov bl, byte ptr [eax]
00491baa mov cl, bl
00491bac cmp bl, byte ptr [ebp]
00491baf jne 0x491bcd
00491bb1 test cl, cl
00491bb3 je 0x491bc9
00491bb5 mov bl, byte ptr [eax + 1]
00491bb8 mov cl, bl
00491bba cmp bl, byte ptr [ebp + 1]
00491bbd jne 0x491bcd
00491bbf add eax, 2
00491bc2 add ebp, 2
00491bc5 test cl, cl
00491bc7 jne 0x491ba8
00491bc9 xor eax, eax
00491bcb jmp 0x491bd2
00491bcd sbb eax, eax
00491bcf sbb eax, -1
00491bd2 test eax, eax
00491bd4 je 0x491be9
00491bd6 push edi
00491bd7 push 0
00491bd9 push 0x80000000
00491bde mov byte ptr [edi + 0xbd], 1
00491be5 push 0xa
00491be7 jmp 0x491c18
00491be9 cmp dword ptr [edx + 0xac], 8
00491bf0 jne 0x491c05
00491bf2 push edi
00491bf3 push 0
00491bf5 push 0x80000000
00491bfa mov byte ptr [edi + 0xbd], 1
00491c01 push 0xb
00491c03 jmp 0x491c18
00491c05 push edx
00491c06 push edi
00491c07 mov ecx, esi
00491c09 call 0x4924d0
00491c0e push edi
00491c0f push 0
00491c11 push 0x80000000
00491c16 push 0xe
00491c18 mov ecx, dword ptr [esi + 8]
00491c1b push 0xc6
00491c20 call 0x48c870
00491c25 mov byte ptr [edi + 0xba], 1
00491c2c jmp 0x491c3c
00491c2e mov dword ptr [esp + 0x18], ebx
00491c32 jmp 0x491c3c
00491c34 mov dword ptr [esp + 0x18], 0
00491c3c mov edx, dword ptr [esp + 0x14]
00491c40 mov eax, dword ptr [edx]
00491c42 push eax
00491c43 call 0x5322c0
00491c48 mov eax, dword ptr [esp + 0x1c]
00491c4c add esp, 4
00491c4f pop edi
00491c50 pop esi
00491c51 pop ebp
00491c52 pop ebx
00491c53 add esp, 0x50
00491c56 ret 0xc
00491c59 lea ecx, [ecx]
00491c5c cmp al, 0x1c
00491c5e dec ecx
00491c5f add bh, dh
00491c61 sbb byte ptr [ecx], cl
00491c64 out 0x11, al
00491c66 dec ecx
00491c67 add dh, ah
00491c69 adc dword ptr [ecx], ecx
00491c6c out 0x11, al
00491c6e dec ecx
00491c6f add byte ptr [esp + ebx], dh
00491c72 dec ecx
00491c73 add byte ptr [edx + edx], cl
00491c76 dec ecx
00491c77 add cl, ah
00491c79 push ss
00491c7a dec ecx
00491c7b add byte ptr [esp + ebx], bh
00491c7e dec ecx
00491c7f add byte ptr [edi + edx + 0x13b10049], ah
00491c86 dec ecx
00491c87 add byte ptr [esp + ebx], bh
00491c8a dec ecx
00491c8b add ah, dh
00491c8d adc al, 0x49
00491c8f add byte ptr [ebp - 0x6effb6e8], bh
00491c95 adc cl, byte ptr [ecx]
00491c98 cmp al, 0x1c
00491c9a dec ecx
00491c9b add byte ptr [ebp + 0x17], ch
00491c9e dec ecx
00491c9f add ah, dl
00491ca1 adc cl, byte ptr [ecx]
00491ca4 outsd dx, dword ptr [esi]
00491ca5 sbb byte ptr [ecx], cl
00491ca8 mov dword ptr [eax], ebx
00491caa dec ecx
00491cab add byte ptr [ebx - 0x76ffb6e8], ah
00491cb1 sbb byte ptr [ecx], cl
00491cb4 mov dword ptr [eax], ebx
00491cb6 dec ecx
00491cb7 add byte ptr [ecx - 0x76ffb6e8], cl
00491cbd sbb byte ptr [ecx], cl
00491cc0 popal
00491cc1 push ss
00491cc2 dec ecx
00491cc3 add byte ptr [esp + ebx], bh
00491cc6 dec ecx
00491cc7 add byte ptr [ebx + 0x18], bl
00491cca dec ecx
00491ccb add byte ptr [eax - 0x746f6f70], dl
00491cd1 inc esp
00491cd2 and al, 0xc
00491cd4 sub esp, 0x14
00491cd7 push ebx
00491cd8 push ebp
00491cd9 mov ebp, ecx
00491cdb push esi
00491cdc push edi
00491cdd lea ecx, [ebp + 0x48]
00491ce0 mov dword ptr [ebp + 4], eax
00491ce3 call 0x52df00
00491ce8 lea edx, [esp + 0x30]
00491cec xor ebx, ebx
00491cee lea ecx, [ebp + 0x164]
00491cf4 push edx
00491cf5 mov dword ptr [ebp + 0x150], 0xffffffff
00491cff mov dword ptr [ebp + 0x154], ebx
00491d05 mov dword ptr [ebp + 0x158], ebx
00491d0b mov dword ptr [ebp + 0x15c], ebx
00491d11 mov dword ptr [ebp + 0x160], ebx
00491d17 call 0x4902c0
00491d1c push ebx
00491d1d push 0xc
00491d1f lea esi, [ebp + 0x168]
00491d25 call 0x4211d0
00491d2a mov dword ptr [esi], eax
00491d2c mov dword ptr [eax], eax
00491d2e mov eax, dword ptr [esi]
00491d30 push ebx
00491d31 push 0xc
00491d33 lea edi, [ebp + 0x16c]
00491d39 mov dword ptr [eax + 4], eax
00491d3c call 0x4211d0
00491d41 mov dword ptr [edi], eax
00491d43 mov dword ptr [eax], eax
00491d45 mov eax, dword ptr [edi]
00491d47 push ebx
00491d48 push 0xc
00491d4a mov dword ptr [eax + 4], eax
00491d4d call 0x4211d0
00491d52 mov dword ptr [ebp + 0x170], eax
00491d58 mov dword ptr [eax], eax
00491d5a mov eax, dword ptr [ebp + 0x170]
00491d60 push ebx
00491d61 push 0xc
00491d63 mov dword ptr [eax + 4], eax
00491d66 call 0x4211d0
00491d6b mov dword ptr [ebp + 0x174], eax
00491d71 mov dword ptr [eax], eax
00491d73 mov eax, dword ptr [ebp + 0x174]
00491d79 push ebx
00491d7a push 0xc
00491d7c mov dword ptr [eax + 4], eax
00491d7f call 0x4211d0
00491d84 mov dword ptr [ebp + 0x178], eax
00491d8a mov dword ptr [eax], eax
00491d8c mov eax, dword ptr [ebp + 0x178]
00491d92 add esp, 0x28
00491d95 mov dword ptr [eax + 4], eax
00491d98 mov eax, dword ptr [esp + 0x3c]
00491d9c mov byte ptr [ebp + 0x17c], bl
00491da2 mov byte ptr [ebp + 0x17d], bl
00491da8 mov dword ptr [ebp + 0x180], ebx
00491dae mov dword ptr [ebp + 0x184], eax
00491db4 mov eax, dword ptr [0x628c78]
00491db9 cmp eax, ebx
00491dbb jne 0x491de5
00491dbd push 4
00491dbf call 0x59ef90
00491dc4 add esp, 4
00491dc7 cmp eax, ebx
00491dc9 mov dword ptr [esp + 0x30], eax
00491dcd je 0x491dde
00491dcf call 0x5321f0
00491dd4 mov ecx, dword ptr [esp + 0x30]
00491dd8 mov dword ptr [ecx], eax
00491dda mov eax, ecx
00491ddc jmp 0x491de0
00491dde xor eax, eax
00491de0 mov dword ptr [0x628c78], eax
00491de5 mov ecx, dword ptr [eax]
00491de7 mov dword ptr [esp + 0x3c], eax
00491deb push ecx
00491dec call 0x5322b0
00491df1 mov byte ptr [0x5d07d0], bl
00491df7 mov eax, dword ptr [ebp + 4]
00491dfa add esp, 4
00491dfd cmp eax, ebx
00491dff mov dword ptr [esp + 0x30], ebx
00491e03 jne 0x491e0d
00491e05 mov dword ptr [esp + 0x30], 0x490e00
00491e0d mov edx, dword ptr [esp + 0x2c]
00491e11 lea eax, [ebp + 0x14]
00491e14 push 0x34
00491e16 push edx
00491e17 push eax
00491e18 call 0x5323e0
00491e1d push 0x168
00491e22 call 0x59ef90
00491e27 add esp, 0x10
00491e2a cmp eax, ebx
00491e2c je 0x491e55
00491e2e mov ecx, dword ptr [esp + 0x38]
00491e32 mov edx, dword ptr [esp + 0x34]
00491e36 push ecx
00491e37 lea ecx, [ebp + 0x14]
00491e3a push edx
00491e3b mov edx, dword ptr [esp + 0x30]
00491e3f push ecx
00491e40 mov ecx, dword ptr [esp + 0x3c]
00491e44 push ebp
00491e45 push ecx
00491e46 push 0x490ff0
00491e4b push edx
00491e4c mov ecx, eax
00491e4e call 0x48af80
00491e53 jmp 0x491e57
00491e55 xor eax, eax
00491e57 push 8
00491e59 mov dword ptr [ebp], eax
00491e5c mov byte ptr [ebp + 0x17e], 1
00491e63 call 0x59ef90
00491e68 add esp, 4
00491e6b cmp eax, ebx
00491e6d je 0x491e7f
00491e6f mov ecx, dword ptr [ebp]
00491e72 mov dword ptr [eax], ecx
00491e74 lea ecx, [ebp + 0x164]
00491e7a mov dword ptr [eax + 4], ecx
00491e7d jmp 0x491e81
00491e7f xor eax, eax
00491e81 push 8
00491e83 mov dword ptr [ebp + 8], eax
00491e86 call 0x59ef90
00491e8b add esp, 4
00491e8e cmp eax, ebx
00491e90 je 0x491e9c
00491e92 mov edx, dword ptr [ebp]
00491e95 mov dword ptr [eax + 4], esi
00491e98 mov dword ptr [eax], edx
00491e9a jmp 0x491e9e
00491e9c xor eax, eax
00491e9e push 8
00491ea0 mov dword ptr [ebp + 0xc], eax
00491ea3 call 0x59ef90
00491ea8 add esp, 4
00491eab cmp eax, ebx
00491ead je 0x491eb9
00491eaf mov ecx, dword ptr [ebp]
00491eb2 mov dword ptr [eax + 4], edi
00491eb5 mov dword ptr [eax], ecx
00491eb7 jmp 0x491ebb
00491eb9 xor eax, eax
00491ebb mov dword ptr [ebp + 0x10], eax
00491ebe mov eax, dword ptr [esp + 0x28]
00491ec2 cmp eax, 1
00491ec5 jne 0x491ef9
00491ec7 mov edx, dword ptr [esp + 0x38]
00491ecb push edx
00491ecc call 0x55eb70
00491ed1 mov edi, dword ptr [eax + 8]
00491ed4 or ecx, 0xffffffff
00491ed7 xor eax, eax
00491ed9 add esp, 4
00491edc repne scasb al, byte ptr es:[edi]
00491ede not ecx
00491ee0 sub edi, ecx
00491ee2 lea edx, [ebp + 0x50]
00491ee5 mov eax, ecx
00491ee7 mov esi, edi
00491ee9 mov edi, edx
00491eeb shr ecx, 2
00491eee rep movsd dword ptr es:[edi], dword ptr [esi]
00491ef0 mov ecx, eax
00491ef2 and ecx, 3
00491ef5 rep movsb byte ptr es:[edi], byte ptr [esi]
00491ef7 jmp 0x491f29
00491ef9 mov edx, dword ptr [ebp]
00491efc lea ecx, [esp + 0x10]
00491f00 push ecx
00491f01 mov eax, dword ptr [edx + 4]
00491f04 push eax
00491f05 call 0x55d650
00491f0a mov edx, dword ptr [ebp]
00491f0d lea ecx, [ebp + 0x160]
00491f13 lea eax, [ebp + 0x50]
00491f16 push ecx
00491f17 push eax
00491f18 mov eax, dword ptr [edx + 4]
00491f1b lea ecx, [esp + 0x20]
00491f1f push ecx
00491f20 push eax
00491f21 call 0x55d5a0
00491f26 add esp, 0x18
00491f29 cmp byte ptr [ebp + 0x51], 0x78
00491f2d jne 0x491f52
00491f2f mov edi, 0x5e8e50
00491f34 or ecx, 0xffffffff
00491f37 xor eax, eax
00491f39 repne scasb al, byte ptr es:[edi]
00491f3b not ecx
00491f3d sub edi, ecx
00491f3f mov edx, ecx
00491f41 mov esi, edi
00491f43 lea edi, [ebp + 0x50]
00491f46 shr ecx, 2
00491f49 rep movsd dword ptr es:[edi], dword ptr [esi]
00491f4b mov ecx, edx
00491f4d and ecx, 3
00491f50 rep movsb byte ptr es:[edi], byte ptr [esi]
00491f52 lea ecx, [ebp + 0x48]
00491f55 call 0x48a9a0
00491f5a shl eax, 5
00491f5d push 0x4906b0
00491f62 mov dword ptr [ebp + 0x4c], eax
00491f65 call 0x560140
00491f6a mov dword ptr [0x628c74], ebp
00491f70 call 0x492b60
00491f75 mov eax, dword ptr [esp + 0x40]
00491f79 mov ecx, dword ptr [eax]
00491f7b push ecx
00491f7c call 0x5322c0
00491f81 mov eax, dword ptr [ebp + 4]
00491f84 add esp, 8
00491f87 cmp eax, ebx
00491f89 je 0x491fa0
00491f8b mov ecx, dword ptr [ebp]
00491f8e push eax
00491f8f call 0x48b610
00491f94 pop edi
00491f95 mov eax, ebp
00491f97 pop esi
00491f98 pop ebp
00491f99 pop ebx
00491f9a add esp, 0x14
00491f9d ret 0x18
00491fa0 mov ecx, dword ptr [ebp]
00491fa3 call 0x48b3c0
00491fa8 pop edi
00491fa9 mov eax, ebp
00491fab pop esi
00491fac pop ebp
00491fad pop ebx
00491fae add esp, 0x14
00491fb1 ret 0x18
00491fb4 nop
00491fb5 nop
00491fb6 nop
00491fb7 nop
00491fb8 nop
00491fb9 nop
00491fba nop
00491fbb nop
00491fbc nop
00491fbd nop
00491fbe nop
00491fbf nop
00491fc0 sub esp, 8
00491fc3 mov byte ptr [0x5d07d0], 1
00491fca push ebx
00491fcb push ebp
00491fcc push esi
00491fcd push edi
00491fce mov edi, dword ptr [0x628c78]
00491fd4 mov esi, ecx
00491fd6 mov eax, dword ptr [edi]
00491fd8 push eax
00491fd9 call 0x5322b0
00491fde mov ecx, dword ptr [edi]
00491fe0 push ecx
00491fe1 call 0x5322c0
00491fe6 push 0x4906b0
00491feb mov byte ptr [esi + 0x17d], 0
00491ff2 call 0x560180
00491ff7 mov al, byte ptr [esi + 0x17e]
00491ffd add esp, 0xc
00492000 test al, al
00492002 je 0x492012
00492004 mov ecx, dword ptr [esi]
00492006 call 0x48b310
0049200b mov byte ptr [esi + 0x17e], 0
00492012 mov eax, dword ptr [esi + 0x164]
00492018 cmp dword ptr [eax], eax
0049201a je 0x49203a
0049201c mov edx, dword ptr [esi + 0x164]
00492022 mov eax, dword ptr [edx + 4]
00492025 mov ecx, dword ptr [eax + 8]
00492028 push ecx
00492029 mov ecx, esi
0049202b call 0x492770
00492030 mov eax, dword ptr [esi + 0x164]
00492036 cmp dword ptr [eax], eax
00492038 jne 0x49201c
0049203a mov eax, dword ptr [esi + 0x16c]
00492040 cmp dword ptr [eax], eax
00492042 je 0x492062
00492044 mov edx, dword ptr [esi + 0x16c]
0049204a mov eax, dword ptr [edx + 4]
0049204d mov ecx, dword ptr [eax + 8]
00492050 push ecx
00492051 mov ecx, esi
00492053 call 0x492770
00492058 mov eax, dword ptr [esi + 0x16c]
0049205e cmp dword ptr [eax], eax
00492060 jne 0x492044
00492062 mov eax, dword ptr [esi + 0x170]
00492068 lea edi, [esi + 0x170]
0049206e cmp dword ptr [eax], eax
00492070 je 0x4920c6
00492072 mov edx, dword ptr [edi]
00492074 mov ebx, edx
00492076 mov eax, dword ptr [edx + 4]
00492079 mov ecx, dword ptr [eax + 8]
0049207c mov eax, dword ptr [ebx]
0049207e cmp eax, ebx
00492080 mov dword ptr [esp + 0x10], ecx
00492084 je 0x4920aa
00492086 mov edx, dword ptr [eax + 8]
00492089 mov ebp, dword ptr [eax]
0049208b cmp edx, ecx
0049208d jne 0x4920a4
0049208f push ecx
00492090 mov ecx, esp
00492092 mov dword ptr [ecx], eax
00492094 lea ecx, [esp + 0x18]
00492098 push ecx
00492099 mov ecx, edi
0049209b call 0x48b660
004920a0 mov ecx, dword ptr [esp + 0x10]
004920a4 cmp ebp, ebx
004920a6 mov eax, ebp
004920a8 jne 0x492086
004920aa test ecx, ecx
004920ac je 0x4920c0
004920ae call 0x48c430
004920b3 mov edx, dword ptr [esp + 0x10]
004920b7 push edx
004920b8 call 0x59f050
004920bd add esp, 4
004920c0 mov eax, dword ptr [edi]
004920c2 cmp dword ptr [eax], eax
004920c4 jne 0x492072
004920c6 mov eax, dword ptr [esi + 0x10]
004920c9 push eax
004920ca call 0x59f050
004920cf mov ecx, dword ptr [esi + 0xc]
004920d2 push ecx
004920d3 call 0x59f050
004920d8 mov edx, dword ptr [esi + 8]
004920db push edx
004920dc call 0x59f050
004920e1 mov ebx, dword ptr [esi]
004920e3 add esp, 0xc
004920e6 test ebx, ebx
004920e8 je 0x4920fa
004920ea mov ecx, ebx
004920ec call 0x48b250
004920f1 push ebx
004920f2 call 0x59f050
004920f7 add esp, 4
004920fa mov ebx, dword ptr [0x628c78]
00492100 test ebx, ebx
00492102 je 0x492115
00492104 mov eax, dword ptr [ebx]
00492106 push eax
00492107 call 0x5322d0
0049210c push ebx
0049210d call 0x59f050
00492112 add esp, 8
00492115 lea ebp, [esi + 0x178]
0049211b mov dword ptr [0x628c78], 0
00492125 mov ecx, ebp
00492127 call 0x493130
0049212c mov ecx, dword ptr [ebp]
0049212f push 0
00492131 push 0xc
00492133 push ecx
00492134 call 0x4237d0
00492139 lea ebp, [esi + 0x174]
0049213f add esp, 0xc
00492142 mov ecx, ebp
00492144 call 0x493130
00492149 mov edx, dword ptr [ebp]
0049214c push 0
0049214e push 0xc
00492150 push edx
00492151 call 0x4237d0
00492156 add esp, 0xc
00492159 mov ecx, edi
0049215b call 0x493130
00492160 mov eax, dword ptr [edi]
00492162 push 0
00492164 push 0xc
00492166 push eax
00492167 call 0x4237d0
0049216c mov eax, dword ptr [esi + 0x16c]
00492172 add esp, 0xc
00492175 mov edi, dword ptr [eax]
00492177 cmp edi, eax
00492179 je 0x492196
0049217b mov eax, edi
0049217d mov edi, dword ptr [edi]
0049217f push 0
00492181 push 0xc
00492183 push eax
00492184 call 0x4237d0
00492189 mov eax, dword ptr [esi + 0x16c]
0049218f add esp, 0xc
00492192 cmp edi, eax
00492194 jne 0x49217b
00492196 mov eax, dword ptr [esi + 0x16c]
0049219c push 0
0049219e push 0xc
004921a0 mov dword ptr [eax], eax
004921a2 mov eax, dword ptr [esi + 0x16c]
004921a8 mov dword ptr [eax + 4], eax
004921ab mov ecx, dword ptr [esi + 0x16c]
004921b1 push ecx
004921b2 call 0x4237d0
004921b7 mov eax, dword ptr [esi + 0x168]
004921bd add esp, 0xc
004921c0 mov edi, dword ptr [eax]
004921c2 cmp edi, eax
004921c4 je 0x4921e1
004921c6 mov eax, edi
004921c8 mov edi, dword ptr [edi]
004921ca push 0
004921cc push 0xc
004921ce push eax
004921cf call 0x4237d0
004921d4 mov eax, dword ptr [esi + 0x168]
004921da add esp, 0xc
004921dd cmp edi, eax
004921df jne 0x4921c6
004921e1 mov eax, dword ptr [esi + 0x168]
004921e7 push 0
004921e9 push 0xc
004921eb mov dword ptr [eax], eax
004921ed mov eax, dword ptr [esi + 0x168]
004921f3 mov dword ptr [eax + 4], eax
004921f6 mov edx, dword ptr [esi + 0x168]
004921fc push edx
004921fd call 0x4237d0
00492202 mov eax, dword ptr [esi + 0x164]
00492208 add esp, 0xc
0049220b mov edi, dword ptr [eax]
0049220d cmp edi, eax
0049220f je 0x49222c
00492211 mov eax, edi
00492213 mov edi, dword ptr [edi]
00492215 push 0
00492217 push 0xc
00492219 push eax
0049221a call 0x4237d0
0049221f mov eax, dword ptr [esi + 0x164]
00492225 add esp, 0xc
00492228 cmp edi, eax
0049222a jne 0x492211
0049222c mov eax, dword ptr [esi + 0x164]
00492232 push 0
00492234 push 0xc
00492236 mov dword ptr [eax], eax
00492238 mov eax, dword ptr [esi + 0x164]
0049223e mov dword ptr [eax + 4], eax
00492241 mov eax, dword ptr [esi + 0x164]
00492247 push eax
00492248 call 0x4237d0
0049224d add esp, 0xc
00492250 pop edi
00492251 pop esi
00492252 pop ebp
00492253 pop ebx
00492254 add esp, 8
00492257 ret
00492258 nop
00492259 nop
0049225a nop
0049225b nop
0049225c nop
0049225d nop
0049225e nop
0049225f nop
00492260 mov eax, dword ptr [0x628c74]
00492265 mov byte ptr [0x5d07d0], 1
0049226c mov cl, byte ptr [eax + 0x17e]
00492272 test cl, cl
00492274 je 0x492289
00492276 mov byte ptr [eax + 0x17e], 0
0049227d mov eax, dword ptr [0x628c74]
00492282 mov ecx, dword ptr [eax]
00492284 jmp 0x48b310
00492289 ret
0049228a nop
0049228b nop
0049228c nop
0049228d nop
0049228e nop
0049228f nop
00492290 push ebx
00492291 mov ebx, ecx
00492293 push ebp
00492294 push esi
00492295 mov ebp, dword ptr [ebx + 0x174]
0049229b push edi
0049229c mov edi, dword ptr [esp + 0x14]
004922a0 mov eax, dword ptr [ebp]
004922a3 cmp eax, ebp
004922a5 je 0x4922cb
004922a7 mov ecx, dword ptr [eax + 8]
004922aa mov esi, dword ptr [eax]
004922ac cmp ecx, edi
004922ae jne 0x4922c5
004922b0 push ecx
004922b1 mov ecx, esp
004922b3 mov dword ptr [ecx], eax
004922b5 lea eax, [esp + 0x18]
004922b9 push eax
004922ba lea ecx, [ebx + 0x174]
004922c0 call 0x48b660
004922c5 cmp esi, ebp
004922c7 mov eax, esi
004922c9 jne 0x4922a7
004922cb mov esi, dword ptr [ebx + 0x158]
004922d1 mov ecx, dword ptr [ebx]
004922d3 dec esi
004922d4 mov dword ptr [ebx + 0x158], esi
004922da mov dl, byte ptr [ecx + 0x14]
004922dd test dl, dl
004922df mov eax, esi
004922e1 jne 0x492306
004922e3 mov ecx, dword ptr [ecx + 0x10]
004922e6 test ecx, ecx
004922e8 je 0x492306
004922ea mov ebp, dword ptr [ebx + 0x154]
004922f0 push 0
004922f2 shl eax, 0x10
004922f5 add eax, ebp
004922f7 push 0
004922f9 push eax
004922fa push 0
004922fc push 0xb8
00492301 call 0x48c870
00492306 mov eax, dword ptr [ebx + 0x164]
0049230c mov esi, dword ptr [eax]
0049230e cmp esi, eax
00492310 je 0x492329
00492312 mov eax, esi
00492314 mov esi, dword ptr [esi]
00492316 mov ecx, dword ptr [eax + 8]
00492319 push ecx
0049231a mov ecx, edi
0049231c call 0x48bb30
00492321 cmp esi, dword ptr [ebx + 0x164]
00492327 jne 0x492312
00492329 test edi, edi
0049232b je 0x492397
0049232d mov eax, dword ptr [edi + 0xa8]
00492333 mov esi, dword ptr [eax]
00492335 cmp esi, eax
00492337 je 0x492354
00492339 mov eax, esi
0049233b mov esi, dword ptr [esi]
0049233d push 0
0049233f push 0xc
00492341 push eax
00492342 call 0x4237d0
00492347 mov eax, dword ptr [edi + 0xa8]
0049234d add esp, 0xc
00492350 cmp esi, eax
00492352 jne 0x492339
00492354 mov eax, dword ptr [edi + 0xa8]
0049235a mov dword ptr [eax], eax
0049235c mov eax, dword ptr [edi + 0xa8]
00492362 mov dword ptr [eax + 4], eax
00492365 mov edx, dword ptr [0x5e4fe8]
0049236b mov ebx, dword ptr [edi + 0xa8]
00492371 mov eax, dword ptr [edx + 0x28]
00492374 lea esi, [edx + 0x28]
00492377 push eax
00492378 call 0x5322b0
0049237d mov ecx, dword ptr [esi + 0x10]
00492380 mov dword ptr [ebx + 4], ecx
00492383 mov dword ptr [esi + 0x10], ebx
00492386 mov edx, dword ptr [esi]
00492388 push edx
00492389 call 0x5322c0
0049238e push edi
0049238f call 0x59f050
00492394 add esp, 0xc
00492397 pop edi
00492398 pop esi
00492399 pop ebp
0049239a pop ebx
0049239b ret 4
0049239e nop
0049239f nop
004923a0 push ebx
004923a1 mov ebx, ecx
004923a3 push ebp
004923a4 push esi
004923a5 mov eax, dword ptr [ebx + 0x15c]
004923ab push edi
004923ac dec eax
004923ad mov dword ptr [ebx + 0x15c], eax
004923b3 jne 0x4923c2
004923b5 push 0x490640
004923ba call 0x560180
004923bf add esp, 4
004923c2 mov ebp, dword ptr [ebx + 0x178]
004923c8 mov edi, dword ptr [esp + 0x14]
004923cc mov eax, dword ptr [ebp]
004923cf cmp eax, ebp
004923d1 je 0x4923f7
004923d3 mov ecx, dword ptr [eax + 8]
004923d6 mov esi, dword ptr [eax]
004923d8 cmp ecx, edi
004923da jne 0x4923f1
004923dc push ecx
004923dd mov ecx, esp
004923df mov dword ptr [ecx], eax
004923e1 lea eax, [esp + 0x18]
004923e5 push eax
004923e6 lea ecx, [ebx + 0x178]
004923ec call 0x48b660
004923f1 cmp esi, ebp
004923f3 mov eax, esi
004923f5 jne 0x4923d3
004923f7 mov esi, dword ptr [ebx + 0x158]
004923fd mov ecx, dword ptr [ebx]
004923ff dec esi
00492400 mov dword ptr [ebx + 0x158], esi
00492406 mov dl, byte ptr [ecx + 0x14]
00492409 test dl, dl
0049240b mov eax, esi
0049240d jne 0x492432
0049240f mov ecx, dword ptr [ecx + 0x10]
00492412 test ecx, ecx
00492414 je 0x492432
00492416 mov ebp, dword ptr [ebx + 0x154]
0049241c push 0
0049241e shl eax, 0x10
00492421 add eax, ebp
00492423 push 0
00492425 push eax
00492426 push 0
00492428 push 0xb8
0049242d call 0x48c870
00492432 mov eax, dword ptr [ebx + 0x164]
00492438 mov esi, dword ptr [eax]
0049243a cmp esi, eax
0049243c je 0x492455
0049243e mov eax, esi
00492440 mov esi, dword ptr [esi]
00492442 mov ecx, dword ptr [eax + 8]
00492445 push ecx
00492446 mov ecx, edi
00492448 call 0x48bb30
0049244d cmp esi, dword ptr [ebx + 0x164]
00492453 jne 0x49243e
00492455 test edi, edi
00492457 je 0x4924c3
00492459 mov eax, dword ptr [edi + 0xa8]
0049245f mov esi, dword ptr [eax]
00492461 cmp esi, eax
00492463 je 0x492480
00492465 mov eax, esi
00492467 mov esi, dword ptr [esi]
00492469 push 0
0049246b push 0xc
0049246d push eax
0049246e call 0x4237d0
00492473 mov eax, dword ptr [edi + 0xa8]
00492479 add esp, 0xc
0049247c cmp esi, eax
0049247e jne 0x492465
00492480 mov eax, dword ptr [edi + 0xa8]
00492486 mov dword ptr [eax], eax
00492488 mov eax, dword ptr [edi + 0xa8]
0049248e mov dword ptr [eax + 4], eax
00492491 mov edx, dword ptr [0x5e4fe8]
00492497 mov ebx, dword ptr [edi + 0xa8]
0049249d mov eax, dword ptr [edx + 0x28]
004924a0 lea esi, [edx + 0x28]
004924a3 push eax
004924a4 call 0x5322b0
004924a9 mov ecx, dword ptr [esi + 0x10]
004924ac mov dword ptr [ebx + 4], ecx
004924af mov dword ptr [esi + 0x10], ebx
004924b2 mov edx, dword ptr [esi]
004924b4 push edx
004924b5 call 0x5322c0
004924ba push edi
004924bb call 0x59f050
004924c0 add esp, 0xc
004924c3 pop edi
004924c4 pop esi
004924c5 pop ebp
004924c6 pop ebx
004924c7 ret 4
004924ca nop
004924cb nop
004924cc nop
004924cd nop
004924ce nop
004924cf nop
004924d0 push ecx
004924d1 push ebx
004924d2 mov ebx, dword ptr [esp + 0xc]
004924d6 push ebp
004924d7 push esi
004924d8 mov eax, dword ptr [ebx + 0xa4]
004924de push edi
004924df test eax, eax
004924e1 mov ebp, ecx
004924e3 jne 0x49258d
004924e9 mov eax, dword ptr [ebx + 0xac]
004924ef mov ecx, dword ptr [ebp + 0xc]
004924f2 push 0
004924f4 push 0
004924f6 push 0x80000000
004924fb push eax
004924fc push 0xb1
00492501 call 0x48c870
00492506 mov esi, dword ptr [ebp + 0x168]
0049250c lea edi, [ebp + 0x168]
00492512 mov eax, dword ptr [esi]
00492514 cmp eax, esi
00492516 je 0x492540
00492518 mov edx, dword ptr [eax + 8]
0049251b mov ecx, dword ptr [eax]
0049251d cmp edx, ebx
0049251f mov dword ptr [esp + 0x18], ecx
00492523 jne 0x49253a
00492525 push ecx
00492526 mov ecx, esp
00492528 mov dword ptr [ecx], eax
0049252a lea ecx, [esp + 0x14]
0049252e push ecx
0049252f mov ecx, edi
00492531 call 0x48b660
00492536 mov ecx, dword ptr [esp + 0x18]
0049253a cmp ecx, esi
0049253c mov eax, ecx
0049253e jne 0x492518
00492540 mov eax, dword ptr [edi]
00492542 mov esi, dword ptr [eax]
00492544 cmp esi, eax
00492546 je 0x49256f
00492548 mov edx, dword ptr [esi + 8]
0049254b mov ecx, dword ptr [ebp + 0xc]
0049254e push ebx
0049254f push 0
00492551 mov eax, dword ptr [edx + 0xac]
00492557 push 0x80000000
0049255c push eax
0049255d push 0xb1
00492562 call 0x48c870
00492567 mov esi, dword ptr [esi]
00492569 mov eax, dword ptr [edi]
0049256b cmp esi, eax
0049256d jne 0x492548
0049256f mov ecx, dword ptr [esp + 0x1c]
00492573 push ebx
00492574 call 0x48bb50
00492579 push 0x5d08e4
0049257e push ebx
0049257f mov dword ptr [ebx + 0xa4], eax
00492585 call 0x492cf0
0049258a add esp, 8
0049258d pop edi
0049258e pop esi
0049258f pop ebp
00492590 pop ebx
00492591 pop ecx
00492592 ret 8
00492595 nop
00492596 nop
00492597 nop
00492598 nop
00492599 nop
0049259a nop
0049259b nop
0049259c nop
0049259d nop
0049259e nop
0049259f nop
004925a0 sub esp, 0xc
004925a3 mov eax, dword ptr [esp + 0x10]
004925a7 push ebx
004925a8 push ebp
004925a9 push esi
004925aa push edi
004925ab mov edi, ecx
004925ad mov ecx, dword ptr [eax + 0xa4]
004925b3 test ecx, ecx
004925b5 mov dword ptr [esp + 0x10], ecx
004925b9 je 0x49275a
004925bf mov bl, byte ptr [ecx + 0xcc3]
004925c5 push eax
004925c6 call 0x48bda0
004925cb test bl, bl
004925cd je 0x49265f
004925d3 mov eax, dword ptr [esp + 0x10]
004925d7 mov cl, byte ptr [eax + 0xcc3]
004925dd test cl, cl
004925df jne 0x49265f
004925e1 mov eax, dword ptr [edi + 0x15c]
004925e7 dec eax
004925e8 mov dword ptr [edi + 0x15c], eax
004925ee jne 0x4925fd
004925f0 push 0x490640
004925f5 call 0x560180
004925fa add esp, 4
004925fd mov ebx, dword ptr [edi + 0x178]
00492603 lea ebp, [edi + 0x178]
00492609 mov eax, dword ptr [ebx]
0049260b cmp eax, ebx
0049260d je 0x492633
0049260f mov ecx, dword ptr [esp + 0x10]
00492613 mov edx, dword ptr [eax + 8]
00492616 mov esi, dword ptr [eax]
00492618 cmp edx, ecx
0049261a jne 0x49262d
0049261c push ecx
0049261d lea edx, [esp + 0x18]
00492621 mov ecx, esp
00492623 push edx
00492624 mov dword ptr [ecx], eax
00492626 mov ecx, ebp
00492628 call 0x48b660
0049262d cmp esi, ebx
0049262f mov eax, esi
00492631 jne 0x49260f
00492633 lea eax, [esp + 0x10]
00492637 lea ecx, [esp + 0x14]
0049263b lea esi, [edi + 0x174]
00492641 push eax
00492642 push ecx
00492643 mov ecx, esi
00492645 call 0x529050
0049264a push ecx
0049264b mov ecx, esp
0049264d push eax
0049264e call 0x50e140
00492653 lea edx, [esp + 0x20]
00492657 mov ecx, esi
00492659 push edx
0049265a call 0x4937f0
0049265f mov ecx, edi
00492661 call 0x490af0
00492666 mov ecx, dword ptr [esp + 0x20]
0049266a mov dword ptr [ecx + 0xac], eax
00492670 mov eax, dword ptr [edi + 4]
00492673 test eax, eax
00492675 jne 0x49274f
0049267b mov eax, dword ptr [esp + 0x20]
0049267f mov ecx, dword ptr [edi + 0xc]
00492682 push 0
00492684 lea edx, [eax + 0x24]
00492687 mov eax, dword ptr [eax + 0xac]
0049268d push edx
0049268e push 0x80000000
00492693 push eax
00492694 push 0xb0
00492699 call 0x48c870
0049269e lea ecx, [esp + 0x20]
004926a2 lea ebx, [edi + 0x168]
004926a8 lea edx, [esp + 0x18]
004926ac push ecx
004926ad push edx
004926ae mov ecx, ebx
004926b0 call 0x529050
004926b5 push ecx
004926b6 mov ecx, esp
004926b8 push eax
004926b9 call 0x50e140
004926be lea eax, [esp + 0x1c]
004926c2 mov ecx, ebx
004926c4 push eax
004926c5 call 0x4937f0
004926ca mov eax, dword ptr [ebx]
004926cc mov ebp, dword ptr [esp + 0x20]
004926d0 mov esi, dword ptr [eax]
004926d2 cmp esi, eax
004926d4 je 0x4926ff
004926d6 mov eax, dword ptr [esi + 8]
004926d9 push ebp
004926da mov edx, dword ptr [eax + 0xac]
004926e0 lea ecx, [eax + 0x24]
004926e3 push ecx
004926e4 mov ecx, dword ptr [edi + 0xc]
004926e7 push 0x80000000
004926ec push edx
004926ed push 0xb0
004926f2 call 0x48c870
004926f7 mov esi, dword ptr [esi]
004926f9 mov eax, dword ptr [ebx]
004926fb cmp esi, eax
004926fd jne 0x4926d6
004926ff mov eax, dword ptr [edi + 0x174]
00492705 mov ebx, dword ptr [esp + 0x20]
00492709 mov esi, dword ptr [eax]
0049270b cmp esi, eax
0049270d je 0x492724
0049270f mov ecx, dword ptr [esi + 8]
00492712 push ebx
00492713 call 0x48baa0
00492718 mov esi, dword ptr [esi]
0049271a mov eax, dword ptr [edi + 0x174]
00492720 cmp esi, eax
00492722 jne 0x49270f
00492724 mov eax, dword ptr [edi + 0x178]
0049272a mov esi, dword ptr [eax]
0049272c cmp esi, eax
0049272e je 0x49275a
00492730 mov ecx, dword ptr [esi + 8]
00492733 push ebx
00492734 call 0x48baa0
00492739 mov esi, dword ptr [esi]
0049273b mov eax, dword ptr [edi + 0x178]
00492741 cmp esi, eax
00492743 jne 0x492730
00492745 pop edi
00492746 pop esi
00492747 pop ebp
00492748 pop ebx
00492749 add esp, 0xc
0049274c ret 4
0049274f mov eax, dword ptr [esp + 0x20]
00492753 mov byte ptr [eax + 0xbd], 1
0049275a pop edi
0049275b pop esi
0049275c pop ebp
0049275d pop ebx
0049275e add esp, 0xc
00492761 ret 4
00492764 nop
00492765 nop
00492766 nop
00492767 nop
00492768 nop
00492769 nop
0049276a nop
0049276b nop
0049276c nop
0049276d nop
0049276e nop
0049276f nop
00492770 sub esp, 8
00492773 push ebx
00492774 push ebp
00492775 push esi
00492776 mov esi, dword ptr [esp + 0x18]
0049277a mov ebp, ecx
0049277c push edi
0049277d push esi
0049277e mov ecx, dword ptr [ebp]
00492781 call 0x48b5a0
00492786 mov al, byte ptr [esi + 0xb8]
0049278c test al, al
0049278e je 0x4927ec
00492790 mov edi, dword ptr [ebp + 0x16c]
00492796 lea ebx, [ebp + 0x16c]
0049279c mov eax, dword ptr [edi]
0049279e cmp eax, edi
004927a0 je 0x4927ca
004927a2 mov ecx, dword ptr [esp + 0x1c]
004927a6 mov edx, dword ptr [eax + 8]
004927a9 mov esi, dword ptr [eax]
004927ab cmp edx, ecx
004927ad jne 0x4927c0
004927af push ecx
004927b0 lea edx, [esp + 0x14]
004927b4 mov ecx, esp
004927b6 push edx
004927b7 mov dword ptr [ecx], eax
004927b9 mov ecx, ebx
004927bb call 0x48b660
004927c0 cmp esi, edi
004927c2 mov eax, esi
004927c4 jne 0x4927a2
004927c6 mov esi, dword ptr [esp + 0x1c]
004927ca mov eax, dword ptr [esi + 0xac]
004927d0 mov ecx, dword ptr [ebp + 0x10]
004927d3 push 0
004927d5 push 0
004927d7 push 0x80000000
004927dc push eax
004927dd push 0xb9
004927e2 call 0x48c870
004927e7 jmp 0x49298c
004927ec lea ecx, [esp + 0x10]
004927f0 lea edi, [ebp + 0x164]
004927f6 push ecx
004927f7 mov ecx, edi
004927f9 call 0x4c3150
004927fe mov eax, dword ptr [eax]
00492800 mov ebx, dword ptr [edi]
00492802 cmp eax, ebx
00492804 je 0x49282e
00492806 mov edx, dword ptr [esp + 0x1c]
0049280a mov ecx, dword ptr [eax + 8]
0049280d mov esi, dword ptr [eax]
0049280f cmp ecx, edx
00492811 jne 0x492824
00492813 push ecx
00492814 mov ecx, esp
00492816 mov dword ptr [ecx], eax
00492818 lea eax, [esp + 0x18]
0049281c push eax
0049281d mov ecx, edi
0049281f call 0x48b660
00492824 cmp esi, ebx
00492826 mov eax, esi
00492828 jne 0x492806
0049282a mov esi, dword ptr [esp + 0x1c]
0049282e mov al, byte ptr [esi + 0xbd]
00492834 test al, al
00492836 jne 0x49298c
0049283c mov edi, dword ptr [ebp + 0x154]
00492842 mov eax, dword ptr [ebp]
00492845 dec edi
00492846 mov dword ptr [ebp + 0x154], edi
0049284c mov dl, byte ptr [eax + 0x14]
0049284f test dl, dl
00492851 mov ecx, edi
00492853 jne 0x49287a
00492855 mov eax, dword ptr [eax + 0x10]
00492858 test eax, eax
0049285a je 0x49287a
0049285c mov edx, dword ptr [ebp + 0x158]
00492862 push 0
00492864 shl edx, 0x10
00492867 add edx, ecx
00492869 push 0
0049286b push edx
0049286c push 0
0049286e push 0xb8
00492873 mov ecx, eax
00492875 call 0x48c870
0049287a mov ecx, dword ptr [esi + 0xa4]
00492880 test ecx, ecx
00492882 mov dword ptr [esp + 0x10], ecx
00492886 jne 0x4928e4
00492888 mov edi, dword ptr [ebp + 0x168]
0049288e lea ebx, [ebp + 0x168]
00492894 mov eax, dword ptr [edi]
00492896 cmp eax, edi
00492898 je 0x4928c2
0049289a mov ecx, dword ptr [esp + 0x1c]
0049289e mov edx, dword ptr [eax + 8]
004928a1 mov esi, dword ptr [eax]
004928a3 cmp edx, ecx
004928a5 jne 0x4928b8
004928a7 push ecx
004928a8 lea edx, [esp + 0x18]
004928ac mov ecx, esp
004928ae push edx
004928af mov dword ptr [ecx], eax
004928b1 mov ecx, ebx
004928b3 call 0x48b660
004928b8 cmp esi, edi
004928ba mov eax, esi
004928bc jne 0x49289a
004928be mov esi, dword ptr [esp + 0x1c]
004928c2 mov eax, dword ptr [esi + 0xac]
004928c8 mov ecx, dword ptr [ebp + 0xc]
004928cb push 0
004928cd push 0
004928cf push 0x80000000
004928d4 push eax
004928d5 push 0xb1
004928da call 0x48c870
004928df jmp 0x49298c
004928e4 mov bl, byte ptr [ecx + 0xcc3]
004928ea push esi
004928eb call 0x48bda0
004928f0 test bl, bl
004928f2 je 0x49298c
004928f8 mov ecx, dword ptr [esp + 0x10]
004928fc mov al, byte ptr [ecx + 0xcc3]
00492902 test al, al
00492904 jne 0x49298c
0049290a mov eax, dword ptr [ebp + 0x15c]
00492910 dec eax
00492911 mov dword ptr [ebp + 0x15c], eax
00492917 jne 0x492926
00492919 push 0x490640
0049291e call 0x560180
00492923 add esp, 4
00492926 mov edi, dword ptr [ebp + 0x178]
0049292c lea ebx, [ebp + 0x178]
00492932 mov eax, dword ptr [edi]
00492934 cmp eax, edi
00492936 je 0x492960
00492938 mov edx, dword ptr [esp + 0x10]
0049293c mov ecx, dword ptr [eax + 8]
0049293f mov esi, dword ptr [eax]
00492941 cmp ecx, edx
00492943 jne 0x492956
00492945 push ecx
00492946 mov ecx, esp
00492948 mov dword ptr [ecx], eax
0049294a lea eax, [esp + 0x18]
0049294e push eax
0049294f mov ecx, ebx
00492951 call 0x48b660
00492956 cmp esi, edi
00492958 mov eax, esi
0049295a jne 0x492938
0049295c mov esi, dword ptr [esp + 0x1c]
00492960 lea ecx, [esp + 0x10]
00492964 add ebp, 0x174
0049296a lea edx, [esp + 0x1c]
0049296e push ecx
0049296f push edx
00492970 mov ecx, ebp
00492972 call 0x529050
00492977 push ecx
00492978 mov ecx, esp
0049297a push eax
0049297b call 0x50e140
00492980 lea eax, [esp + 0x1c]
00492984 mov ecx, ebp
00492986 push eax
00492987 call 0x4937f0
0049298c test esi, esi
0049298e je 0x4929a0
00492990 mov ecx, esi
00492992 call 0x48a7a0
00492997 push esi
00492998 call 0x59f050
0049299d add esp, 4
004929a0 pop edi
004929a1 pop esi
004929a2 pop ebp
004929a3 pop ebx
004929a4 add esp, 8
004929a7 ret 4
004929aa nop
004929ab nop
004929ac nop
004929ad nop
004929ae nop
004929af nop
004929b0 push ecx
004929b1 push ebx
004929b2 push ebp
004929b3 push esi
004929b4 mov esi, dword ptr [esp + 0x18]
004929b8 push edi
004929b9 mov edi, dword ptr [esp + 0x20]
004929bd cmp esi, -2
004929c0 mov dword ptr [esp + 0x10], ecx
004929c4 jne 0x4929dd
004929c6 mov ebp, dword ptr [esp + 0x18]
004929ca push 0x5d092c
004929cf push ebp
004929d0 call 0x492cf0
004929d5 add esp, 8
004929d8 jmp 0x492a9d
004929dd cmp esi, -1
004929e0 jne 0x4929f9
004929e2 mov ebp, dword ptr [esp + 0x18]
004929e6 push 0x5d091c
004929eb push ebp
004929ec call 0x492cf0
004929f1 add esp, 8
004929f4 jmp 0x492a9d
004929f9 mov eax, edi
004929fb and eax, 0x8000003f
00492a00 jns 0x492a07
00492a02 dec eax
00492a03 or eax, 0xffffffc0
00492a06 inc eax
00492a07 lea eax, [eax + eax*4]
00492a0a mov ecx, 0x3c
00492a0f lea eax, [eax + eax*4]
00492a12 shl eax, 2
00492a15 cdq
00492a16 and edx, 0x3f
00492a19 add eax, edx
00492a1b sar eax, 6
00492a1e push eax
00492a1f mov eax, edi
00492a21 cdq
00492a22 and edx, 0x3f
00492a25 add eax, edx
00492a27 sar eax, 6
00492a2a cdq
00492a2b idiv ecx
00492a2d mov eax, 0x88888889
00492a32 push edx
00492a33 imul edi
00492a35 add edx, edi
00492a37 sar edx, 0xb
00492a3a mov eax, edx
00492a3c shr eax, 0x1f
00492a3f add edx, eax
00492a41 mov eax, esi
00492a43 and eax, 0x8000003f
00492a48 push edx
00492a49 jns 0x492a50
00492a4b dec eax
00492a4c or eax, 0xffffffc0
00492a4f inc eax
00492a50 lea eax, [eax + eax*4]
00492a53 mov ecx, 0x3c
00492a58 mov ebp, dword ptr [esp + 0x24]
00492a5c lea eax, [eax + eax*4]
00492a5f shl eax, 2
00492a62 cdq
00492a63 and edx, 0x3f
00492a66 add eax, edx
00492a68 sar eax, 6
00492a6b push eax
00492a6c mov eax, esi
00492a6e cdq
00492a6f and edx, 0x3f
00492a72 add eax, edx
00492a74 sar eax, 6
00492a77 cdq
00492a78 idiv ecx
00492a7a mov eax, 0x88888889
00492a7f push edx
00492a80 imul esi
00492a82 add edx, esi
00492a84 sar edx, 0xb
00492a87 mov eax, edx
00492a89 shr eax, 0x1f
00492a8c add edx, eax
00492a8e push edx
00492a8f push 0x5d08ec
00492a94 push ebp
00492a95 call 0x492cf0
00492a9a add esp, 0x20
00492a9d mov ecx, dword ptr [ebp + 0xa4]
00492aa3 push edi
00492aa4 push esi
00492aa5 mov dword ptr [esp + 0x20], ecx
00492aa9 mov bl, byte ptr [ecx + 0xcc3]
00492aaf push ebp
00492ab0 call 0x48c220
00492ab5 test bl, bl
00492ab7 je 0x492b51
00492abd mov ecx, dword ptr [esp + 0x18]
00492ac1 mov al, byte ptr [ecx + 0xcc3]
00492ac7 test al, al
00492ac9 jne 0x492b51
00492acf mov ebp, dword ptr [esp + 0x10]
00492ad3 mov eax, dword ptr [ebp + 0x15c]
00492ad9 dec eax
00492ada mov dword ptr [ebp + 0x15c], eax
00492ae0 jne 0x492aef
00492ae2 push 0x490640
00492ae7 call 0x560180
00492aec add esp, 4
00492aef mov edi, dword ptr [ebp + 0x178]
00492af5 lea ebx, [ebp + 0x178]
00492afb mov eax, dword ptr [edi]
00492afd cmp eax, edi
00492aff je 0x492b25
00492b01 mov edx, dword ptr [esp + 0x18]
00492b05 mov ecx, dword ptr [eax + 8]
00492b08 mov esi, dword ptr [eax]
00492b0a cmp ecx, edx
00492b0c jne 0x492b1f
00492b0e push ecx
00492b0f mov ecx, esp
00492b11 mov dword ptr [ecx], eax
00492b13 lea eax, [esp + 0x20]
00492b17 push eax
00492b18 mov ecx, ebx
00492b1a call 0x48b660
00492b1f cmp esi, edi
00492b21 mov eax, esi
00492b23 jne 0x492b01
00492b25 lea ecx, [esp + 0x18]
00492b29 lea esi, [ebp + 0x174]
00492b2f lea edx, [esp + 0x1c]
00492b33 push ecx
00492b34 push edx
00492b35 mov ecx, esi
00492b37 call 0x529050
00492b3c push ecx
00492b3d mov ecx, esp
00492b3f push eax
00492b40 call 0x50e140
00492b45 lea eax, [esp + 0x28]
00492b49 mov ecx, esi
00492b4b push eax
00492b4c call 0x4937f0
00492b51 pop edi
00492b52 pop esi
00492b53 pop ebp
00492b54 pop ebx
00492b55 pop ecx
00492b56 ret 0xc
00492b59 nop
00492b5a nop
00492b5b nop
00492b5c nop
00492b5d nop
00492b5e nop
00492b5f nop
00492b60 mov eax, dword ptr [0x628c74]
00492b65 mov eax, dword ptr [eax + 0x184]
00492b6b cmp eax, -1
00492b6e jle 0x492ce5
00492b74 push 0x5d0b14
00492b79 push eax
00492b7a call 0x55ec50
00492b7f mov ecx, dword ptr [0x628c74]
00492b85 push 0x5d0b0c
00492b8a mov edx, dword ptr [ecx + 0x184]
00492b90 push edx
00492b91 call 0x55ec50
00492b96 mov eax, dword ptr [0x628c74]
00492b9b push 0x5d0ae0
00492ba0 mov ecx, dword ptr [eax + 0x184]
00492ba6 push ecx
00492ba7 call 0x55ec50
00492bac mov edx, dword ptr [0x628c74]
00492bb2 push 0x5d0a94
00492bb7 mov eax, dword ptr [edx + 0x184]
00492bbd push eax
00492bbe call 0x55ec50
00492bc3 mov eax, dword ptr [0x628c74]
00492bc8 mov edx, dword ptr [eax + 0x184]
00492bce lea ecx, [eax + 0x14]
00492bd1 push ecx
00492bd2 push 0x5d0a80
00492bd7 push edx
00492bd8 call 0x55ec50
00492bdd mov eax, dword ptr [0x628c74]
00492be2 push 0x5d0a74
00492be7 mov ecx, dword ptr [eax + 0x184]
00492bed push ecx
00492bee call 0x55ec50
00492bf3 mov edx, dword ptr [0x628c74]
00492bf9 push 0x5d0a58
00492bfe mov eax, dword ptr [edx + 0x184]
00492c04 push eax
00492c05 call 0x55ec50
00492c0a mov ecx, dword ptr [0x628c74]
00492c10 push 0x5d0a08
00492c15 mov edx, dword ptr [ecx + 0x184]
00492c1b push edx
00492c1c call 0x55ec50
00492c21 mov eax, dword ptr [0x628c74]
00492c26 add esp, 0x44
00492c29 mov ecx, dword ptr [eax + 0x184]
00492c2f push 0x5d09ec
00492c34 push ecx
00492c35 call 0x55ec50
00492c3a mov edx, dword ptr [0x628c74]
00492c40 push 0x5d09c8
00492c45 mov eax, dword ptr [edx + 0x184]
00492c4b push eax
00492c4c call 0x55ec50
00492c51 mov ecx, dword ptr [0x628c74]
00492c57 push 0x5d09bc
00492c5c mov edx, dword ptr [ecx + 0x184]
00492c62 push edx
00492c63 call 0x55ec50
00492c68 mov eax, dword ptr [0x628c74]
00492c6d push 0x5d09b4
00492c72 mov ecx, dword ptr [eax + 0x184]
00492c78 push ecx
00492c79 call 0x55ec50
00492c7e mov edx, dword ptr [0x628c74]
00492c84 push 0x5d0998
00492c89 mov eax, dword ptr [edx + 0x184]
00492c8f push eax
00492c90 call 0x55ec50
00492c95 mov ecx, dword ptr [0x628c74]
00492c9b push 0x5d06fc
00492ca0 push 0x5d0960
00492ca5 mov edx, dword ptr [ecx + 0x184]
00492cab push edx
00492cac call 0x55ec50
00492cb1 mov eax, dword ptr [0x628c74]
00492cb6 add esp, 0x34
00492cb9 test eax, eax
00492cbb lea ecx, [eax + 0x50]
00492cbe jne 0x492cc5
00492cc0 mov ecx, 0x5e8e50
00492cc5 mov edx, dword ptr [eax + 0x160]
00492ccb push edx
00492ccc mov edx, dword ptr [eax + 0x184]
00492cd2 push ecx
00492cd3 lea ecx, [eax + 0x14]
00492cd6 push ecx
00492cd7 push 0x5d0944
00492cdc push edx
00492cdd call 0x55ec50
00492ce2 add esp, 0x14
00492ce5 ret
00492ce6 nop
00492ce7 nop
00492ce8 nop
00492ce9 nop
00492cea nop
00492ceb nop
00492cec nop
00492ced nop
00492cee nop
00492cef nop
00492cf0 mov eax, dword ptr [0x628c74]
00492cf5 sub esp, 0x208
00492cfb cmp dword ptr [eax + 0x184], -1
00492d02 jle 0x4930dc
00492d08 push ebx
00492d09 push ebp
00492d0a push esi
00492d0b push edi
00492d0c mov edi, 0x5d0b38
00492d11 or ecx, 0xffffffff
00492d14 xor eax, eax
00492d16 lea edx, [esp + 0x18]
00492d1a repne scasb al, byte ptr es:[edi]
00492d1c not ecx
00492d1e sub edi, ecx
00492d20 mov eax, ecx
00492d22 mov esi, edi
00492d24 mov edi, edx
00492d26 shr ecx, 2
00492d29 rep movsd dword ptr es:[edi], dword ptr [esi]
00492d2b mov ecx, eax
00492d2d and ecx, 3
00492d30 rep movsb byte ptr es:[edi], byte ptr [esi]
00492d32 lea ecx, [esp + 0x10]
00492d36 push ecx
00492d37 call 0x5a17eb
00492d3c lea edx, [esp + 0x14]
00492d40 push edx
00492d41 call 0x5a29ef
00492d46 mov edi, eax
00492d48 or ecx, 0xffffffff
00492d4b xor eax, eax
00492d4d add esp, 8
00492d50 repne scasb al, byte ptr es:[edi]
00492d52 not ecx
00492d54 sub edi, ecx
00492d56 lea edx, [esp + 0x18]
00492d5a mov esi, edi
00492d5c mov ebx, ecx
00492d5e mov edi, edx
00492d60 or ecx, 0xffffffff
00492d63 repne scasb al, byte ptr es:[edi]
00492d65 mov ecx, ebx
00492d67 dec edi
00492d68 shr ecx, 2
00492d6b rep movsd dword ptr es:[edi], dword ptr [esi]
00492d6d mov ecx, ebx
00492d6f lea edx, [esp + 0x18]
00492d73 and ecx, 3
00492d76 rep movsb byte ptr es:[edi], byte ptr [esi]
00492d78 lea edi, [esp + 0x18]
00492d7c or ecx, 0xffffffff
00492d7f repne scasb al, byte ptr es:[edi]
00492d81 not ecx
00492d83 dec ecx
00492d84 mov edi, 0x5ccdc0
00492d89 mov byte ptr [esp + ecx + 0x17], al
00492d8d or ecx, 0xffffffff
00492d90 repne scasb al, byte ptr es:[edi]
00492d92 not ecx
00492d94 sub edi, ecx
00492d96 mov esi, edi
00492d98 mov ebx, ecx
00492d9a mov edi, edx
00492d9c or ecx, 0xffffffff
00492d9f repne scasb al, byte ptr es:[edi]
00492da1 mov ecx, ebx
00492da3 dec edi
00492da4 shr ecx, 2
00492da7 rep movsd dword ptr es:[edi], dword ptr [esi]
00492da9 mov ecx, ebx
00492dab mov ebx, dword ptr [esp + 0x21c]
00492db2 and ecx, 3
00492db5 test ebx, ebx
00492db7 rep movsb byte ptr es:[edi], byte ptr [esi]
00492db9 je 0x493068
00492dbf mov edx, dword ptr [ebx]
00492dc1 test edx, edx
00492dc3 je 0x493068
00492dc9 mov edi, 0x5d0b34
00492dce or ecx, 0xffffffff
00492dd1 repne scasb al, byte ptr es:[edi]
00492dd3 not ecx
00492dd5 sub edi, ecx
00492dd7 lea ebp, [esp + 0x18]
00492ddb mov esi, edi
00492ddd mov edi, ebp
00492ddf mov ebp, ecx
00492de1 or ecx, 0xffffffff
00492de4 repne scasb al, byte ptr es:[edi]
00492de6 mov ecx, ebp
00492de8 dec edi
00492de9 shr ecx, 2
00492dec rep movsd dword ptr es:[edi], dword ptr [esi]
00492dee mov ecx, ebp
00492df0 lea eax, [esp + 0x14]
00492df4 and ecx, 3
00492df7 push eax
00492df8 rep movsb byte ptr es:[edi], byte ptr [esi]
00492dfa lea edi, [esp + 0x1c]
00492dfe or ecx, 0xffffffff
00492e01 xor eax, eax
00492e03 repne scasb al, byte ptr es:[edi]
00492e05 not ecx
00492e07 dec ecx
00492e08 lea ecx, [esp + ecx + 0x1c]
00492e0c push ecx
00492e0d push edx
00492e0e mov edx, dword ptr [0x628c74]
00492e14 mov eax, dword ptr [edx]
00492e16 mov ecx, dword ptr [eax + 4]
00492e19 push ecx
00492e1a call 0x55d5a0
00492e1f mov edi, 0x5d0b30
00492e24 or ecx, 0xffffffff
00492e27 xor eax, eax
00492e29 add esp, 0x10
00492e2c repne scasb al, byte ptr es:[edi]
00492e2e not ecx
00492e30 sub edi, ecx
00492e32 lea edx, [esp + 0x18]
00492e36 mov esi, edi
00492e38 mov ebp, ecx
00492e3a mov edi, edx
00492e3c or ecx, 0xffffffff
00492e3f repne scasb al, byte ptr es:[edi]
00492e41 mov ecx, ebp
00492e43 dec edi
00492e44 shr ecx, 2
00492e47 rep movsd dword ptr es:[edi], dword ptr [esi]
00492e49 mov ecx, ebp
00492e4b lea edx, [esp + 0x18]
00492e4f and ecx, 3
00492e52 rep movsb byte ptr es:[edi], byte ptr [esi]
00492e54 lea edi, [ebx + 0x24]
00492e57 or ecx, 0xffffffff
00492e5a repne scasb al, byte ptr es:[edi]
00492e5c not ecx
00492e5e sub edi, ecx
00492e60 mov esi, edi
00492e62 mov ebp, ecx
00492e64 mov edi, edx
00492e66 or ecx, 0xffffffff
00492e69 repne scasb al, byte ptr es:[edi]
00492e6b mov ecx, ebp
00492e6d dec edi
00492e6e shr ecx, 2
00492e71 rep movsd dword ptr es:[edi], dword ptr [esi]
00492e73 mov ecx, ebp
00492e75 lea edx, [esp + 0x18]
00492e79 and ecx, 3
00492e7c rep movsb byte ptr es:[edi], byte ptr [esi]
00492e7e mov edi, 0x5ccdc0
00492e83 or ecx, 0xffffffff
00492e86 repne scasb al, byte ptr es:[edi]
00492e88 not ecx
00492e8a sub edi, ecx
00492e8c mov esi, edi
00492e8e mov ebp, ecx
00492e90 mov edi, edx
00492e92 or ecx, 0xffffffff
00492e95 lea edx, [esp + 0x18]
00492e99 repne scasb al, byte ptr es:[edi]
00492e9b mov ecx, ebp
00492e9d dec edi
00492e9e shr ecx, 2
00492ea1 rep movsd dword ptr es:[edi], dword ptr [esi]
00492ea3 mov ecx, ebp
00492ea5 and ecx, 3
00492ea8 rep movsb byte ptr es:[edi], byte ptr [esi]
00492eaa or ecx, 0xffffffff
00492ead lea edi, [ebx + 4]
00492eb0 repne scasb al, byte ptr es:[edi]
00492eb2 not ecx
00492eb4 sub edi, ecx
00492eb6 mov ebp, ecx
00492eb8 mov esi, edi
00492eba or ecx, 0xffffffff
00492ebd mov edi, edx
00492ebf repne scasb al, byte ptr es:[edi]
00492ec1 mov ecx, ebp
00492ec3 dec edi
00492ec4 shr ecx, 2
00492ec7 rep movsd dword ptr es:[edi], dword ptr [esi]
00492ec9 mov ecx, ebp
00492ecb lea edx, [esp + 0x18]
00492ecf and ecx, 3
00492ed2 rep movsb byte ptr es:[edi], byte ptr [esi]
00492ed4 or ecx, 0xffffffff
00492ed7 mov edi, 0x5d0b2c
00492edc repne scasb al, byte ptr es:[edi]
00492ede not ecx
00492ee0 sub edi, ecx
00492ee2 mov ebp, ecx
00492ee4 mov esi, edi
00492ee6 or ecx, 0xffffffff
00492ee9 mov edi, edx
00492eeb repne scasb al, byte ptr es:[edi]
00492eed mov ecx, ebp
00492eef dec edi
00492ef0 shr ecx, 2
00492ef3 rep movsd dword ptr es:[edi], dword ptr [esi]
00492ef5 mov ecx, ebp
00492ef7 lea edx, [esp + 0x18]
00492efb and ecx, 3
00492efe rep movsb byte ptr es:[edi], byte ptr [esi]
00492f00 mov edi, 0x5e8e50
00492f05 or ecx, 0xffffffff
00492f08 repne scasb al, byte ptr es:[edi]
00492f0a not ecx
00492f0c sub edi, ecx
00492f0e mov esi, edi
00492f10 mov ebp, ecx
00492f12 mov edi, edx
00492f14 or ecx, 0xffffffff
00492f17 repne scasb al, byte ptr es:[edi]
00492f19 mov ecx, ebp
00492f1b dec edi
00492f1c shr ecx, 2
00492f1f rep movsd dword ptr es:[edi], dword ptr [esi]
00492f21 mov ecx, ebp
00492f23 lea edx, [esp + 0x18]
00492f27 and ecx, 3
00492f2a rep movsb byte ptr es:[edi], byte ptr [esi]
00492f2c mov edi, 0x5d0b28
00492f31 or ecx, 0xffffffff
00492f34 repne scasb al, byte ptr es:[edi]
00492f36 not ecx
00492f38 sub edi, ecx
00492f3a mov esi, edi
00492f3c mov ebp, ecx
00492f3e mov edi, edx
00492f40 or ecx, 0xffffffff
00492f43 repne scasb al, byte ptr es:[edi]
00492f45 mov ecx, ebp
00492f47 dec edi
00492f48 shr ecx, 2
00492f4b rep movsd dword ptr es:[edi], dword ptr [esi]
00492f4d mov ecx, ebp
00492f4f and ecx, 3
00492f52 rep movsb byte ptr es:[edi], byte ptr [esi]
00492f54 or ecx, 0xffffffff
00492f57 mov edi, 0x5d0b2c
00492f5c repne scasb al, byte ptr es:[edi]
00492f5e not ecx
00492f60 sub edi, ecx
00492f62 lea edx, [esp + 0x18]
00492f66 mov ebp, ecx
00492f68 mov esi, edi
00492f6a or ecx, 0xffffffff
00492f6d mov edi, edx
00492f6f repne scasb al, byte ptr es:[edi]
00492f71 mov ecx, ebp
00492f73 dec edi
00492f74 shr ecx, 2
00492f77 rep movsd dword ptr es:[edi], dword ptr [esi]
00492f79 mov ecx, ebp
00492f7b lea edx, [esp + 0x18]
00492f7f and ecx, 3
00492f82 rep movsb byte ptr es:[edi], byte ptr [esi]
00492f84 lea edi, [ebx + 0x84]
00492f8a or ecx, 0xffffffff
00492f8d repne scasb al, byte ptr es:[edi]
00492f8f not ecx
00492f91 sub edi, ecx
00492f93 mov ebx, dword ptr [ebx + 0xa4]
00492f99 mov esi, edi
00492f9b mov ebp, ecx
00492f9d mov edi, edx
00492f9f or ecx, 0xffffffff
00492fa2 repne scasb al, byte ptr es:[edi]
00492fa4 mov ecx, ebp
00492fa6 dec edi
00492fa7 shr ecx, 2
00492faa rep movsd dword ptr es:[edi], dword ptr [esi]
00492fac mov ecx, ebp
00492fae lea edx, [esp + 0x18]
00492fb2 and ecx, 3
00492fb5 rep movsb byte ptr es:[edi], byte ptr [esi]
00492fb7 mov edi, 0x5d0b28
00492fbc or ecx, 0xffffffff
00492fbf repne scasb al, byte ptr es:[edi]
00492fc1 not ecx
00492fc3 sub edi, ecx
00492fc5 mov esi, edi
00492fc7 mov ebp, ecx
00492fc9 mov edi, edx
00492fcb or ecx, 0xffffffff
00492fce repne scasb al, byte ptr es:[edi]
00492fd0 mov ecx, ebp
00492fd2 dec edi
00492fd3 shr ecx, 2
00492fd6 rep movsd dword ptr es:[edi], dword ptr [esi]
00492fd8 mov ecx, ebp
00492fda and ecx, 3
00492fdd test ebx, ebx
00492fdf rep movsb byte ptr es:[edi], byte ptr [esi]
00492fe1 je 0x493068
00492fe7 or ecx, 0xffffffff
00492fea mov edi, 0x5d0b24
00492fef repne scasb al, byte ptr es:[edi]
00492ff1 not ecx
00492ff3 sub edi, ecx
00492ff5 lea edx, [esp + 0x18]
00492ff9 mov ebp, ecx
00492ffb mov esi, edi
00492ffd or ecx, 0xffffffff
00493000 mov edi, edx
00493002 repne scasb al, byte ptr es:[edi]
00493004 mov ecx, ebp
00493006 dec edi
00493007 shr ecx, 2
0049300a rep movsd dword ptr es:[edi], dword ptr [esi]
0049300c mov ecx, ebp
0049300e lea edx, [esp + 0x18]
00493012 and ecx, 3
00493015 rep movsb byte ptr es:[edi], byte ptr [esi]
00493017 mov edi, ebx
00493019 or ecx, 0xffffffff
0049301c repne scasb al, byte ptr es:[edi]
0049301e not ecx
00493020 sub edi, ecx
00493022 mov esi, edi
00493024 mov ebx, ecx
00493026 mov edi, edx
00493028 or ecx, 0xffffffff
0049302b repne scasb al, byte ptr es:[edi]
0049302d mov ecx, ebx
0049302f dec edi
00493030 shr ecx, 2
00493033 rep movsd dword ptr es:[edi], dword ptr [esi]
00493035 mov ecx, ebx
00493037 lea edx, [esp + 0x18]
0049303b and ecx, 3
0049303e rep movsb byte ptr es:[edi], byte ptr [esi]
00493040 mov edi, 0x5d0b20
00493045 or ecx, 0xffffffff
00493048 repne scasb al, byte ptr es:[edi]
0049304a not ecx
0049304c sub edi, ecx
0049304e mov esi, edi
00493050 mov ebx, ecx
00493052 mov edi, edx
00493054 or ecx, 0xffffffff
00493057 repne scasb al, byte ptr es:[edi]
00493059 mov ecx, ebx
0049305b dec edi
0049305c shr ecx, 2
0049305f rep movsd dword ptr es:[edi], dword ptr [esi]
00493061 mov ecx, ebx
00493063 and ecx, 3
00493066 rep movsb byte ptr es:[edi], byte ptr [esi]
00493068 mov ecx, dword ptr [esp + 0x220]
0049306f lea eax, [esp + 0x224]
00493076 push eax
00493077 push ecx
00493078 lea edi, [esp + 0x20]
0049307c or ecx, 0xffffffff
0049307f xor eax, eax
00493081 repne scasb al, byte ptr es:[edi]
00493083 not ecx
00493085 dec ecx
00493086 lea edx, [esp + ecx + 0x20]
0049308a push edx
0049308b call 0x5a299e
00493090 mov edi, 0x5d0b1c
00493095 or ecx, 0xffffffff
00493098 xor eax, eax
0049309a lea edx, [esp + 0x24]
0049309e repne scasb al, byte ptr es:[edi]
004930a0 not ecx
004930a2 sub edi, ecx
004930a4 mov esi, edi
004930a6 mov ebx, ecx
004930a8 mov edi, edx
004930aa or ecx, 0xffffffff
004930ad repne scasb al, byte ptr es:[edi]
004930af mov ecx, ebx
004930b1 dec edi
004930b2 shr ecx, 2
004930b5 rep movsd dword ptr es:[edi], dword ptr [esi]
004930b7 mov ecx, ebx
004930b9 lea eax, [esp + 0x24]
004930bd and ecx, 3
004930c0 push eax
004930c1 rep movsb byte ptr es:[edi], byte ptr [esi]
004930c3 mov ecx, dword ptr [0x628c74]
004930c9 mov edx, dword ptr [ecx + 0x184]
004930cf push edx
004930d0 call 0x55ec50
004930d5 add esp, 0x14
004930d8 pop edi
004930d9 pop esi
004930da pop ebp
004930db pop ebx
004930dc add esp, 0x208
004930e2 ret
004930e3 nop
004930e4 nop
004930e5 nop
004930e6 nop
004930e7 nop
004930e8 nop
004930e9 nop
004930ea nop
004930eb nop
004930ec nop
004930ed nop
004930ee nop
004930ef nop
004930f0 mov edx, dword ptr [ecx]
004930f2 mov eax, dword ptr [edx]
004930f4 mov dword ptr [ecx], eax
004930f6 mov eax, dword ptr [esp + 4]
004930fa mov dword ptr [eax], edx
004930fc ret 8
004930ff nop
00493100 push ecx
00493101 mov eax, dword ptr [esp + 8]
00493105 push esi
00493106 mov esi, ecx
00493108 push eax
00493109 lea ecx, [esp + 0x10]
0049310d push ecx
0049310e mov ecx, esi
00493110 call 0x529050
00493115 push ecx
00493116 mov ecx, esp
00493118 push eax
00493119 call 0x50e140
0049311e lea edx, [esp + 0xc]
00493122 mov ecx, esi
00493124 push edx
00493125 call 0x4937f0
0049312a pop esi
0049312b pop ecx
0049312c ret 4
0049312f nop
00493130 push ebp
00493131 mov ebp, ecx
00493133 push edi
00493134 mov eax, dword ptr [ebp]
00493137 mov edi, dword ptr [eax]
00493139 cmp edi, eax
0049313b je 0x493171
0049313d push ebx
0049313e push esi
0049313f mov eax, dword ptr [0x5e4fe8]
00493144 mov ebx, edi
00493146 mov edi, dword ptr [edi]
00493148 mov ecx, dword ptr [eax + 0x28]
0049314b lea esi, [eax + 0x28]
0049314e push ecx
0049314f call 0x5322b0
00493154 mov edx, dword ptr [esi + 0x10]
00493157 mov dword ptr [ebx + 4], edx
0049315a mov dword ptr [esi + 0x10], ebx
0049315d mov eax, dword ptr [esi]
0049315f push eax
00493160 call 0x5322c0
00493165 mov eax, dword ptr [ebp]
00493168 add esp, 8
0049316b cmp edi, eax
0049316d jne 0x49313f
0049316f pop esi
00493170 pop ebx
00493171 mov eax, dword ptr [ebp]
00493174 pop edi
00493175 mov dword ptr [eax], eax
00493177 mov ebp, dword ptr [ebp]
0049317a mov dword ptr [ebp + 4], ebp
0049317d pop ebp
0049317e ret
0049317f nop
00493180 push ebx
00493181 push ebp
00493182 mov ebx, ecx
00493184 push esi
00493185 push edi
00493186 mov edi, dword ptr [ebx]
00493188 mov eax, dword ptr [edi]
0049318a cmp eax, edi
0049318c je 0x4931b5
0049318e mov ebp, dword ptr [esp + 0x14]
00493192 mov ecx, dword ptr [eax + 8]
00493195 mov edx, dword ptr [ebp]
00493198 mov esi, dword ptr [eax]
0049319a cmp ecx, edx
0049319c jne 0x4931af
0049319e push ecx
0049319f lea edx, [esp + 0x18]
004931a3 mov ecx, esp
004931a5 push edx
004931a6 mov dword ptr [ecx], eax
004931a8 mov ecx, ebx
004931aa call 0x48b660
004931af cmp esi, edi
004931b1 mov eax, esi
004931b3 jne 0x493192
004931b5 pop edi
004931b6 pop esi
004931b7 pop ebp
004931b8 pop ebx
004931b9 ret 4
004931bc nop
004931bd nop
004931be nop
004931bf nop
004931c0 push ebx
004931c1 push esi
004931c2 xor ebx, ebx
004931c4 push edi
004931c5 push ebx
004931c6 mov esi, ecx
004931c8 push 0x18
004931ca call 0x4211d0
004931cf mov dword ptr [esi], eax
004931d1 mov dword ptr [eax], eax
004931d3 mov eax, dword ptr [esi]
004931d5 push ebx
004931d6 push 0xc
004931d8 mov dword ptr [eax + 4], eax
004931db call 0x4211d0
004931e0 mov dword ptr [esi + 4], eax
004931e3 mov dword ptr [eax], eax
004931e5 mov eax, dword ptr [esi + 4]
004931e8 mov dword ptr [eax + 4], eax
004931eb mov dword ptr [esi + 8], ebx
004931ee mov dword ptr [esi + 0xc], ebx
004931f1 mov byte ptr [esi + 0x10], bl
004931f4 call 0x5321f0
004931f9 mov dword ptr [esi + 0x14], eax
004931fc mov eax, dword ptr [esp + 0x20]
00493200 mov dword ptr [esi + 0x18], eax
00493203 mov dword ptr [esi + 0x1c], ebx
00493206 mov dword ptr [esi + 0x24], ebx
00493209 mov byte ptr [esi + 0x28], bl
0049320c mov ecx, dword ptr [esi + 0x14]
0049320f push ecx
00493210 call 0x5322b0
00493215 mov dword ptr [0x628c7c], esi
0049321b push 0x14
0049321d mov byte ptr [esi + 0x29], 0xc1
00493221 mov byte ptr [esi + 0x2a], bl
00493224 call 0x5611e0
00493229 mov edi, eax
0049322b push 0x10
0049322d push edi
0049322e push 0x5d0b40
00493233 call 0x531ca0
00493238 push edi
00493239 push eax
0049323a push ebx
0049323b push 0x493570
00493240 mov dword ptr [esi + 0x20], eax
00493243 call 0x561200
00493248 push 0x493320
0049324d mov dword ptr [esi + 8], eax
00493250 call 0x5610e0
00493255 mov edx, dword ptr [esi + 0x14]
00493258 push edx
00493259 call 0x5322c0
0049325e add esp, 0x3c
00493261 mov eax, esi
00493263 pop edi
00493264 pop esi
00493265 pop ebx
00493266 ret 4
00493269 nop
0049326a nop
0049326b nop
0049326c nop
0049326d nop
0049326e nop
0049326f nop
00493270 sub esp, 0x20
00493273 push ebx
00493274 push ebp
00493275 push esi
00493276 mov esi, ecx
00493278 push edi
00493279 mov eax, dword ptr [esi + 0x14]
0049327c push eax
0049327d call 0x5322b0
00493282 mov ecx, dword ptr [esp + 0x38]
00493286 add esp, 4
00493289 lea ebx, [esi + 4]
0049328c mov ebp, 5
00493291 lea edi, [ecx + 2]
00493294 push 0xe
00493296 lea edx, [esp + 0x24]
0049329a push edi
0049329b push edx
0049329c call 0x5323e0
004932a1 add esp, 0xc
004932a4 lea eax, [esp + 0x20]
004932a8 lea ecx, [esp + 0x10]
004932ac push eax
004932ad push ecx
004932ae mov ecx, esi
004932b0 call 0x529050
004932b5 push ecx
004932b6 mov ecx, esp
004932b8 push eax
004932b9 call 0x50e140
004932be lea edx, [esp + 0x1c]
004932c2 mov ecx, esi
004932c4 push edx
004932c5 call 0x493720
004932ca mov eax, dword ptr [esi]
004932cc lea edx, [esp + 0x34]
004932d0 push edx
004932d1 add edi, 0xe
004932d4 mov ecx, dword ptr [eax + 4]
004932d7 lea eax, [esp + 0x1c]
004932db add ecx, 8
004932de push eax
004932df mov dword ptr [esp + 0x3c], ecx
004932e3 mov ecx, ebx
004932e5 call 0x529050
004932ea push ecx
004932eb mov ecx, esp
004932ed push eax
004932ee call 0x50e140
004932f3 lea ecx, [esp + 0x24]
004932f7 push ecx
004932f8 mov ecx, ebx
004932fa call 0x4937f0
004932ff mov ecx, dword ptr [esi + 0xc]
00493302 inc ecx
00493303 dec ebp
00493304 mov dword ptr [esi + 0xc], ecx
00493307 jne 0x493294
00493309 mov edx, dword ptr [esi + 0x14]
0049330c push edx
0049330d call 0x5322c0
00493312 add esp, 4
00493315 pop edi
00493316 pop esi
00493317 pop ebp
00493318 pop ebx
00493319 add esp, 0x20
0049331c ret 4
0049331f nop
00493320 mov eax, dword ptr [0x628c7c]
00493325 push esi
00493326 mov ecx, dword ptr [eax + 0x14]
00493329 lea esi, [eax + 0x14]
0049332c push ecx
0049332d call 0x5322b0
00493332 mov ecx, dword ptr [0x628c7c]
00493338 add esp, 4
0049333b call 0x493350
00493340 mov edx, dword ptr [esi]
00493342 push edx
00493343 call 0x5322c0
00493348 add esp, 4
0049334b pop esi
0049334c ret
0049334d nop
0049334e nop
0049334f nop
00493350 mov eax, dword ptr [0x628c70]
00493355 sub esp, 0x78
00493358 push ebx
00493359 xor ebx, ebx
0049335b push esi
0049335c cmp eax, ebx
0049335e push edi
0049335f mov esi, ecx
00493361 je 0x493380
00493363 cmp dword ptr [eax + 8], ebx
00493366 je 0x493380
00493368 cmp byte ptr [eax + 0xbf], bl
0049336e jne 0x493380
00493370 cmp byte ptr [eax + 0xbe], bl
00493376 je 0x493380
00493378 cmp dword ptr [eax + 0xdc], ebx
0049337e jge 0x4933a4
00493380 cmp dword ptr [esi + 0x1c], ebx
00493383 je 0x493565
00493389 call 0x561b50
0049338e mov eax, dword ptr [esi + 0x1c]
00493391 push eax
00493392 call 0x531f90
00493397 add esp, 4
0049339a mov dword ptr [esi + 0x1c], ebx
0049339d pop edi
0049339e pop esi
0049339f pop ebx
004933a0 add esp, 0x78
004933a3 ret
004933a4 cmp dword ptr [esi + 0x1c], ebx
004933a7 jne 0x4933f2
004933a9 push ebx
004933aa push 0x10000
004933af push 0x5d0b50
004933b4 mov word ptr [esp + 0x18], 0x1f40
004933bb mov byte ptr [esp + 0x1a], 1
004933c0 mov byte ptr [esp + 0x1b], 0x40
004933c5 call 0x531ca0
004933ca push 0x10000
004933cf lea ecx, [esp + 0x1c]
004933d3 push eax
004933d4 push ecx
004933d5 push 0xa0
004933da mov dword ptr [esi + 0x1c], eax
004933dd call 0x561a40
004933e2 add esp, 0x1c
004933e5 cmp eax, ebx
004933e7 jge 0x4933f2
004933e9 push eax
004933ea call 0x516950
004933ef add esp, 4
004933f2 call 0x561ae0
004933f7 cmp eax, ebx
004933f9 je 0x493456
004933fb mov ecx, dword ptr [esi + 0x24]
004933fe lea edx, [ecx*8]
00493405 sub edx, ecx
00493407 lea ecx, [esi + edx*2]
0049340a mov dl, byte ptr [esi + edx*2 + 0x2d]
0049340e cmp dl, 7
00493411 jbe 0x493417
00493413 mov byte ptr [esi + 0x28], 1
00493417 mov eax, dword ptr [eax + 0xc]
0049341a push 0xe
0049341c add ecx, 0x2b
0049341f push eax
00493420 push ecx
00493421 call 0x5323e0
00493426 mov ecx, dword ptr [esi + 0x24]
00493429 add esp, 0xc
0049342c inc ecx
0049342d mov eax, ecx
0049342f mov dword ptr [esi + 0x24], ecx
00493432 cmp eax, 5
00493435 jne 0x49344d
00493437 mov eax, dword ptr [esi + 0x18]
0049343a push 0x48
0049343c mov ecx, dword ptr [eax]
0049343e lea eax, [esi + 0x29]
00493441 push eax
00493442 push ebx
00493443 mov edx, dword ptr [ecx]
00493445 call dword ptr [edx]
00493447 mov byte ptr [esi + 0x28], bl
0049344a mov dword ptr [esi + 0x24], ebx
0049344d call 0x561ae0
00493452 cmp eax, ebx
00493454 jne 0x4933fb
00493456 mov eax, dword ptr [esi + 4]
00493459 lea edi, [esi + 4]
0049345c mov ecx, dword ptr [eax]
0049345e cmp ecx, eax
00493460 mov al, byte ptr [esi + 0x10]
00493463 je 0x493537
00493469 cmp al, bl
0049346b jne 0x4934c1
0049346d cmp dword ptr [esi + 0xc], 0xa
00493471 jl 0x493565
00493477 lea ecx, [esp + 0x14]
0049347b mov word ptr [esp + 0xc], 0x1f40
00493482 push ecx
00493483 mov byte ptr [esp + 0x12], 1
00493488 mov byte ptr [esp + 0x13], 0x40
0049348d call 0x561960
00493492 lea edx, [esp + 0x34]
00493496 mov byte ptr [esp + 0x1f], bl
0049349a push edx
0049349b call 0x561900
004934a0 lea eax, [esp + 0x1c]
004934a4 lea ecx, [esp + 0x38]
004934a8 push eax
004934a9 mov eax, dword ptr [esi + 8]
004934ac lea edx, [esp + 0x18]
004934b0 push ecx
004934b1 push edx
004934b2 push eax
004934b3 call 0x5612a0
004934b8 add esp, 0x18
004934bb mov byte ptr [esi + 0x10], 1
004934bf jmp 0x4934d6
004934c1 mov ecx, dword ptr [esi + 8]
004934c4 push ecx
004934c5 call 0x5616d0
004934ca mov edx, dword ptr [esi + 8]
004934cd push edx
004934ce call 0x561700
004934d3 add esp, 8
004934d6 mov eax, dword ptr [edi]
004934d8 cmp dword ptr [eax], eax
004934da je 0x493565
004934e0 mov eax, dword ptr [edi]
004934e2 mov dword ptr [esp + 0x18], 0xa0
004934ea mov ecx, dword ptr [eax]
004934ec lea eax, [esp + 0x14]
004934f0 push eax
004934f1 mov edx, dword ptr [ecx + 8]
004934f4 mov ecx, dword ptr [esi + 8]
004934f7 push ecx
004934f8 mov dword ptr [esp + 0x28], edx
004934fc call 0x5615c0
00493501 add esp, 8
00493504 lea edx, [esp + 0xc]
00493508 mov ecx, edi
0049350a push edx
0049350b call 0x4c3150
00493510 mov eax, dword ptr [eax]
00493512 push ecx
00493513 mov ecx, esp
00493515 mov dword ptr [ecx], eax
00493517 lea ecx, [esp + 0x14]
0049351b push ecx
0049351c mov ecx, edi
0049351e call 0x48b660
00493523 mov edx, dword ptr [esi + 0xc]
00493526 dec edx
00493527 mov dword ptr [esi + 0xc], edx
0049352a mov eax, dword ptr [edi]
0049352c cmp dword ptr [eax], eax
0049352e jne 0x4934e0
00493530 pop edi
00493531 pop esi
00493532 pop ebx
00493533 add esp, 0x78
00493536 ret
00493537 cmp al, bl
00493539 je 0x493565
0049353b mov edx, dword ptr [esi + 8]
0049353e push edx
0049353f call 0x561700
00493544 mov edi, eax
00493546 mov eax, dword ptr [esi + 8]
00493549 push eax
0049354a call 0x5616d0
0049354f add esp, 8
00493552 add edi, eax
00493554 jne 0x493565
00493556 mov ecx, dword ptr [esi + 8]
00493559 push ecx
0049355a call 0x561730
0049355f add esp, 4
00493562 mov byte ptr [esi + 0x10], bl
00493565 pop edi
00493566 pop esi
00493567 pop ebx
00493568 add esp, 0x78
0049356b ret
0049356c nop
0049356d nop
0049356e nop
0049356f nop
00493570 mov eax, dword ptr [0x628c7c]
00493575 sub esp, 8
00493578 mov ecx, dword ptr [eax + 0x14]
0049357b push esi
0049357c lea esi, [eax + 0x14]
0049357f push edi
00493580 push ecx
00493581 call 0x5322b0
00493586 mov edi, dword ptr [0x628c7c]
0049358c add esp, 4
0049358f lea edx, [esp + 8]
00493593 mov ecx, edi
00493595 push edx
00493596 call 0x4c3150
0049359b mov eax, dword ptr [eax]
0049359d push ecx
0049359e mov ecx, esp
004935a0 mov dword ptr [ecx], eax
004935a2 lea ecx, [esp + 0x10]
004935a6 push ecx
004935a7 mov ecx, edi
004935a9 call 0x4937a0
004935ae mov edx, dword ptr [esi]
004935b0 push edx
004935b1 call 0x5322c0
004935b6 add esp, 4
004935b9 pop edi
004935ba pop esi
004935bb add esp, 8
004935be ret
004935bf nop
004935c0 push ebx
004935c1 push ebp
004935c2 push esi
004935c3 mov esi, ecx
004935c5 push edi
004935c6 mov eax, dword ptr [esi + 0x14]
004935c9 push eax
004935ca call 0x5322b0
004935cf push 0x493320
004935d4 call 0x561110
004935d9 mov eax, dword ptr [esi + 0x1c]
004935dc xor ebx, ebx
004935de add esp, 8
004935e1 cmp eax, ebx
004935e3 je 0x4935f6
004935e5 call 0x561b50
004935ea mov ecx, dword ptr [esi + 0x1c]
004935ed push ecx
004935ee call 0x531f90
004935f3 add esp, 4
004935f6 cmp byte ptr [esi + 0x10], bl
004935f9 je 0x49360a
004935fb mov edx, dword ptr [esi + 8]
004935fe push edx
004935ff call 0x561730
00493604 add esp, 4
00493607 mov byte ptr [esi + 0x10], bl
0049360a mov eax, dword ptr [esi + 8]
0049360d push eax
0049360e call 0x5617d0
00493613 mov ecx, dword ptr [esi + 0x20]
00493616 push ecx
00493617 call 0x531f90
0049361c mov dword ptr [0x628c7c], ebx
00493622 mov edx, dword ptr [esi + 0x14]
00493625 push edx
00493626 call 0x5322c0
0049362b mov eax, dword ptr [esi + 0x14]
0049362e push eax
0049362f call 0x5322d0
00493634 mov eax, dword ptr [esi + 4]
00493637 add esp, 0x10
0049363a mov ebx, dword ptr [eax]
0049363c cmp ebx, eax
0049363e je 0x493671
00493640 mov ecx, dword ptr [0x5e4fe8]
00493646 mov ebp, ebx
00493648 mov ebx, dword ptr [ebx]
0049364a mov edx, dword ptr [ecx + 0x28]
0049364d lea edi, [ecx + 0x28]
00493650 push edx
00493651 call 0x5322b0
00493656 mov eax, dword ptr [edi + 0x10]
00493659 mov dword ptr [ebp + 4], eax
0049365c mov dword ptr [edi + 0x10], ebp
0049365f mov ecx, dword ptr [edi]
00493661 push ecx
00493662 call 0x5322c0
00493667 mov eax, dword ptr [esi + 4]
0049366a add esp, 8
0049366d cmp ebx, eax
0049366f jne 0x493640
00493671 mov eax, dword ptr [esi + 4]
00493674 mov dword ptr [eax], eax
00493676 mov eax, dword ptr [esi + 4]
00493679 mov dword ptr [eax + 4], eax
0049367c mov edx, dword ptr [0x5e4fe8]
00493682 mov ebx, dword ptr [esi + 4]
00493685 mov eax, dword ptr [edx + 0x28]
00493688 lea edi, [edx + 0x28]
0049368b push eax
0049368c call 0x5322b0
00493691 mov ecx, dword ptr [edi + 0x10]
00493694 mov dword ptr [ebx + 4], ecx
00493697 mov dword ptr [edi + 0x10], ebx
0049369a mov edx, dword ptr [edi]
0049369c push edx
0049369d call 0x5322c0
004936a2 mov eax, dword ptr [esi]
004936a4 add esp, 8
004936a7 mov edi, dword ptr [eax]
004936a9 cmp edi, eax
004936ab je 0x4936dc
004936ad mov eax, dword ptr [0x5e4fe8]
004936b2 mov ebp, edi
004936b4 mov edi, dword ptr [edi]
004936b6 mov ecx, dword ptr [eax + 0x28]
004936b9 lea ebx, [eax + 0x28]
004936bc push ecx
004936bd call 0x5322b0
004936c2 mov edx, dword ptr [ebx + 0x14]
004936c5 mov dword ptr [ebp + 4], edx
004936c8 mov dword ptr [ebx + 0x14], ebp
004936cb mov eax, dword ptr [ebx]
004936cd push eax
004936ce call 0x5322c0
004936d3 mov eax, dword ptr [esi]
004936d5 add esp, 8
004936d8 cmp edi, eax
004936da jne 0x4936ad
004936dc mov eax, dword ptr [esi]
004936de mov dword ptr [eax], eax
004936e0 mov eax, dword ptr [esi]
004936e2 mov dword ptr [eax + 4], eax
004936e5 mov ecx, dword ptr [0x5e4fe8]
004936eb mov esi, dword ptr [esi]
004936ed mov edx, dword ptr [ecx + 0x28]
004936f0 lea edi, [ecx + 0x28]
004936f3 push edx
004936f4 call 0x5322b0
004936f9 mov eax, dword ptr [edi + 0x14]
004936fc mov dword ptr [esi + 4], eax
004936ff mov dword ptr [edi + 0x14], esi
00493702 mov ecx, dword ptr [edi]
00493704 push ecx
00493705 call 0x5322c0
0049370a add esp, 8
0049370d pop edi
0049370e pop esi
0049370f pop ebp
00493710 pop ebx
00493711 ret
00493712 nop
00493713 nop
00493714 nop
00493715 nop
00493716 nop
00493717 nop
00493718 nop
00493719 nop
0049371a nop
0049371b nop
0049371c nop
0049371d nop
0049371e nop
0049371f nop
00493720 mov eax, dword ptr [0x5e4fe8]
00493725 push esi
00493726 push edi
00493727 mov ecx, dword ptr [eax + 0x28]
0049372a lea edi, [eax + 0x28]
0049372d push ecx
0049372e call 0x5322b0
00493733 mov eax, dword ptr [edi + 0x14]
00493736 add esp, 4
00493739 test eax, eax
0049373b jne 0x493749
0049373d push 0
0049373f push 2
00493741 call 0x59eeb0
00493746 add esp, 8
00493749 mov esi, dword ptr [edi + 0x14]
0049374c mov edx, dword ptr [esi + 4]
0049374f mov dword ptr [edi + 0x14], edx
00493752 mov eax, dword ptr [edi]
00493754 push eax
00493755 call 0x5322c0
0049375a lea eax, [esi + 8]
0049375d add esp, 4
00493760 test eax, eax
00493762 je 0x493780
00493764 mov ecx, dword ptr [esp + 0x14]
00493768 mov edx, dword ptr [ecx]
0049376a mov dword ptr [eax], edx
0049376c mov edx, dword ptr [ecx + 4]
0049376f mov dword ptr [eax + 4], edx
00493772 mov edx, dword ptr [ecx + 8]
00493775 mov dword ptr [eax + 8], edx
00493778 mov cx, word ptr [ecx + 0xc]
0049377c mov word ptr [eax + 0xc], cx
00493780 mov eax, dword ptr [esp + 0x10]
00493784 pop edi
00493785 mov dword ptr [esi], eax
00493787 mov edx, dword ptr [eax + 4]
0049378a mov dword ptr [esi + 4], edx
0049378d mov ecx, dword ptr [eax + 4]
00493790 mov dword ptr [ecx], esi
00493792 mov dword ptr [eax + 4], esi
00493795 mov eax, dword ptr [esp + 8]
00493799 mov dword ptr [eax], esi
0049379b pop esi
0049379c ret 0xc
0049379f nop
004937a0 push ebx
004937a1 push esi
004937a2 push edi
004937a3 mov edi, dword ptr [esp + 0x14]
004937a7 mov eax, dword ptr [edi + 4]
004937aa mov ebx, dword ptr [edi]
004937ac mov dword ptr [eax], ebx
004937ae mov dword ptr [ebx + 4], eax
004937b1 mov eax, dword ptr [0x5e4fe8]
004937b6 mov ecx, dword ptr [eax + 0x28]
004937b9 lea esi, [eax + 0x28]
004937bc push ecx
004937bd call 0x5322b0
004937c2 mov edx, dword ptr [esi + 0x14]
004937c5 mov dword ptr [edi + 4], edx
004937c8 mov dword ptr [esi + 0x14], edi
004937cb mov eax, dword ptr [esi]
004937cd push eax
004937ce call 0x5322c0
004937d3 mov eax, dword ptr [esp + 0x18]
004937d7 add esp, 8
004937da pop edi
004937db mov dword ptr [eax], ebx
004937dd pop esi
004937de pop ebx
004937df ret 8
004937e2 nop
004937e3 nop
004937e4 nop
004937e5 nop
004937e6 nop
004937e7 nop
004937e8 nop
004937e9 nop
004937ea nop
004937eb nop
004937ec nop
004937ed nop
004937ee nop
004937ef nop
004937f0 mov eax, dword ptr [0x5e4fe8]
004937f5 push esi
004937f6 push edi
004937f7 mov ecx, dword ptr [eax + 0x28]
004937fa lea edi, [eax + 0x28]
004937fd push ecx
004937fe call 0x5322b0
00493803 mov eax, dword ptr [edi + 0x10]
00493806 add esp, 4
00493809 test eax, eax
0049380b jne 0x493819
0049380d push 0
0049380f push 1
00493811 call 0x59eeb0
00493816 add esp, 8
00493819 mov esi, dword ptr [edi + 0x10]
0049381c mov edx, dword ptr [esi + 4]
0049381f mov dword ptr [edi + 0x10], edx
00493822 mov eax, dword ptr [edi]
00493824 push eax
00493825 call 0x5322c0
0049382a lea eax, [esi + 8]
0049382d add esp, 4
00493830 test eax, eax
00493832 je 0x49383c
00493834 mov ecx, dword ptr [esp + 0x14]
00493838 mov edx, dword ptr [ecx]
0049383a mov dword ptr [eax], edx
0049383c mov eax, dword ptr [esp + 0x10]
00493840 pop edi
00493841 mov dword ptr [esi], eax
00493843 mov ecx, dword ptr [eax + 4]
00493846 mov dword ptr [esi + 4], ecx
00493849 mov edx, dword ptr [eax + 4]
0049384c mov dword ptr [edx], esi
0049384e mov dword ptr [eax + 4], esi
00493851 mov eax, dword ptr [esp + 8]
00493855 mov dword ptr [eax], esi
00493857 pop esi
00493858 ret 0xc
0049385b nop
0049385c nop
0049385d nop
0049385e nop
0049385f nop
00493860 push ecx
00493861 mov dword ptr [esp], 0x800000
00493869 mov eax, dword ptr [esp]
0049386d mov dword ptr [0x628c84], eax
00493872 pop ecx
00493873 ret
00493874 nop
00493875 nop
00493876 nop
00493877 nop
00493878 nop
00493879 nop
0049387a nop
0049387b nop
0049387c nop
0049387d nop
0049387e nop
0049387f nop
00493880 fld dword ptr [0x5b24a8]
00493886 fdiv dword ptr [0x628c84]
0049388c fstp dword ptr [0x628c80]
00493892 ret
00493893 nop
00493894 nop
00493895 nop
00493896 nop
00493897 nop
00493898 nop
00493899 nop
0049389a nop
0049389b nop
0049389c nop
0049389d nop
0049389e nop
0049389f nop
004938a0 sub esp, 8
004938a3 push ebx
004938a4 mov ebx, dword ptr [esp + 0x10]
004938a8 push ebp
004938a9 mov ebp, 1
004938ae fld dword ptr [ebx + 0x4e8]
004938b4 lea eax, [ebx + 0x768]
004938ba push esi
004938bb mov dword ptr [esp + 0x18], ebp
004938bf push edi
004938c0 mov dword ptr [esp + 0x1c], eax
004938c4 mov dword ptr [esp + 0x14], 0x14
004938cc mov ecx, dword ptr [esp + 0x1c]
004938d0 mov edx, dword ptr [ecx]
004938d2 cmp word ptr [edx + 0x26], 1
004938d7 jne 0x49392b
004938d9 fld dword ptr [edx + 0x60]
004938dc fmul dword ptr [0x5b3284]
004938e2 inc ebp
004938e3 xor edi, edi
004938e5 mov dword ptr [esp + 0x10], edi
004938e9 lea ecx, [edx + 0x48]
004938ec fsubr dword ptr [0x5b246c]
004938f2 fld dword ptr [0x5b23f8]
004938f8 lea eax, [ebx + 0x4e4]
004938fe mov esi, 0xa
00493903 cmp byte ptr [ecx], 0
00493906 je 0x49390b
00493908 fadd dword ptr [eax]
0049390a inc edi
0049390b add eax, 4
0049390e inc ecx
0049390f dec esi
00493910 jne 0x493903
00493912 cmp edi, 1
00493915 mov dword ptr [esp + 0x10], edi
00493919 jle 0x49391f
0049391b fidiv dword ptr [esp + 0x10]
0049391f fmul st(1)
00493921 fadd dword ptr [edx + 0x164]
00493927 faddp st(2)
00493929 fstp st(0)
0049392b mov ecx, dword ptr [esp + 0x1c]
0049392f mov eax, dword ptr [esp + 0x14]
00493933 add ecx, 4
00493936 dec eax
00493937 mov dword ptr [esp + 0x1c], ecx
0049393b mov dword ptr [esp + 0x14], eax
0049393f jne 0x4938cc
00493941 mov dword ptr [esp + 0x1c], ebp
00493945 pop edi
00493946 fidiv dword ptr [esp + 0x18]
0049394a pop esi
0049394b pop ebp
0049394c pop ebx
0049394d add esp, 8
00493950 ret
00493951 nop
00493952 nop
00493953 nop
00493954 nop
00493955 nop
00493956 nop
00493957 nop
00493958 nop
00493959 nop
0049395a nop
0049395b nop
0049395c nop
0049395d nop
0049395e nop
0049395f nop
00493960 mov eax, dword ptr [esp + 4]
00493964 fld dword ptr [eax + 0x4ec]
0049396a fadd dword ptr [eax + 0x4e4]
00493970 fmul dword ptr [0x5b23f0]
00493976 ret
00493977 nop
00493978 nop
00493979 nop
0049397a nop
0049397b nop
0049397c nop
0049397d nop
0049397e nop
0049397f nop
00493980 push ecx
00493981 fld dword ptr [0x5b23f8]
00493987 push ebx
00493988 mov ebx, dword ptr [esp + 0xc]
0049398c push ebp
0049398d push esi
0049398e push edi
0049398f lea ebp, [ebx + 0x768]
00493995 mov dword ptr [esp + 0x10], 0x14
0049399d mov edx, dword ptr [ebp]
004939a0 cmp word ptr [edx + 0x26], 9
004939a5 jne 0x4939f8
004939a7 fld dword ptr [edx + 0x60]
004939aa fmul dword ptr [0x5b3284]
004939b0 xor edi, edi
004939b2 lea ecx, [edx + 0x48]
004939b5 mov dword ptr [esp + 0x18], edi
004939b9 lea eax, [ebx + 0x4e4]
004939bf fsubr dword ptr [0x5b246c]
004939c5 fld dword ptr [0x5b23f8]
004939cb mov esi, 0xa
004939d0 cmp byte ptr [ecx], 0
004939d3 je 0x4939d8
004939d5 fadd dword ptr [eax]
004939d7 inc edi
004939d8 add eax, 4
004939db inc ecx
004939dc dec esi
004939dd jne 0x4939d0
004939df cmp edi, 1
004939e2 mov dword ptr [esp + 0x18], edi
004939e6 jle 0x4939ec
004939e8 fidiv dword ptr [esp + 0x18]
004939ec fmul st(1)
004939ee fadd dword ptr [edx + 0x164]
004939f4 faddp st(2)
004939f6 fstp st(0)
004939f8 mov eax, dword ptr [esp + 0x10]
004939fc add ebp, 4
004939ff dec eax
00493a00 mov dword ptr [esp + 0x10], eax
00493a04 jne 0x49399d
00493a06 pop edi
00493a07 pop esi
00493a08 pop ebp
00493a09 pop ebx
00493a0a pop ecx
00493a0b ret
00493a0c nop
00493a0d nop
00493a0e nop
00493a0f nop
00493a10 push ecx
00493a11 fld dword ptr [0x5b23f8]
00493a17 push ebx
00493a18 mov ebx, dword ptr [esp + 0xc]
00493a1c push ebp
00493a1d push esi
00493a1e push edi
00493a1f lea ebp, [ebx + 0x768]
00493a25 mov dword ptr [esp + 0x10], 0x14
00493a2d mov edx, dword ptr [ebp]
00493a30 cmp word ptr [edx + 0x26], 2
00493a35 jne 0x493a88
00493a37 fld dword ptr [edx + 0x60]
00493a3a fmul dword ptr [0x5b3284]
00493a40 xor edi, edi
00493a42 lea ecx, [edx + 0x48]
00493a45 mov dword ptr [esp + 0x18], edi
00493a49 lea eax, [ebx + 0x4e4]
00493a4f fsubr dword ptr [0x5b246c]
00493a55 fld dword ptr [0x5b23f8]
00493a5b mov esi, 0xa
00493a60 cmp byte ptr [ecx], 0
00493a63 je 0x493a68
00493a65 fadd dword ptr [eax]
00493a67 inc edi
00493a68 add eax, 4
00493a6b inc ecx
00493a6c dec esi
00493a6d jne 0x493a60
00493a6f cmp edi, 1
00493a72 mov dword ptr [esp + 0x18], edi
00493a76 jle 0x493a7c
00493a78 fidiv dword ptr [esp + 0x18]
00493a7c fmul st(1)
00493a7e fadd dword ptr [edx + 0x164]
00493a84 faddp st(2)
00493a86 fstp st(0)
00493a88 mov eax, dword ptr [esp + 0x10]
00493a8c add ebp, 4
00493a8f dec eax
00493a90 mov dword ptr [esp + 0x10], eax
00493a94 jne 0x493a2d
00493a96 pop edi
00493a97 pop esi
00493a98 pop ebp
00493a99 pop ebx
00493a9a pop ecx
00493a9b ret
00493a9c nop
00493a9d nop
00493a9e nop
00493a9f nop
00493aa0 push ecx
00493aa1 fld dword ptr [0x5b23f8]
00493aa7 push ebx
00493aa8 mov ebx, dword ptr [esp + 0xc]
00493aac push ebp
00493aad push esi
00493aae push edi
00493aaf lea ebp, [ebx + 0x768]
00493ab5 mov dword ptr [esp + 0x10], 0x14
00493abd mov edx, dword ptr [ebp]
00493ac0 cmp word ptr [edx + 0x26], 3
00493ac5 jne 0x493b18
00493ac7 fld dword ptr [edx + 0x60]
00493aca fmul dword ptr [0x5b3284]
00493ad0 xor edi, edi
00493ad2 lea ecx, [edx + 0x48]
00493ad5 mov dword ptr [esp + 0x18], edi
00493ad9 lea eax, [ebx + 0x4e4]
00493adf fsubr dword ptr [0x5b246c]
00493ae5 fld dword ptr [0x5b23f8]
00493aeb mov esi, 0xa
00493af0 cmp byte ptr [ecx], 0
00493af3 je 0x493af8
00493af5 fadd dword ptr [eax]
00493af7 inc edi
00493af8 add eax, 4
00493afb inc ecx
00493afc dec esi
00493afd jne 0x493af0
00493aff cmp edi, 1
00493b02 mov dword ptr [esp + 0x18], edi
00493b06 jle 0x493b0c
00493b08 fidiv dword ptr [esp + 0x18]
00493b0c fmul st(1)
00493b0e fadd dword ptr [edx + 0x164]
00493b14 faddp st(2)
00493b16 fstp st(0)
00493b18 mov eax, dword ptr [esp + 0x10]
00493b1c add ebp, 4
00493b1f dec eax
00493b20 mov dword ptr [esp + 0x10], eax
00493b24 jne 0x493abd
00493b26 pop edi
00493b27 pop esi
00493b28 pop ebp
00493b29 pop ebx
00493b2a pop ecx
00493b2b ret
00493b2c nop
00493b2d nop
00493b2e nop
00493b2f nop
00493b30 push ecx
00493b31 fld dword ptr [0x5b23f8]
00493b37 push ebx
00493b38 mov ebx, dword ptr [esp + 0xc]
00493b3c push ebp
00493b3d push esi
00493b3e push edi
00493b3f lea ebp, [ebx + 0x768]
00493b45 mov dword ptr [esp + 0x10], 0x14
00493b4d mov edx, dword ptr [ebp]
00493b50 cmp word ptr [edx + 0x26], 6
00493b55 jne 0x493ba8
00493b57 fld dword ptr [edx + 0x60]
00493b5a fmul dword ptr [0x5b3284]
00493b60 xor edi, edi
00493b62 lea ecx, [edx + 0x48]
00493b65 mov dword ptr [esp + 0x18], edi
00493b69 lea eax, [ebx + 0x4e4]
00493b6f fsubr dword ptr [0x5b246c]
00493b75 fld dword ptr [0x5b23f8]
00493b7b mov esi, 0xa
00493b80 cmp byte ptr [ecx], 0
00493b83 je 0x493b88
00493b85 fadd dword ptr [eax]
00493b87 inc edi
00493b88 add eax, 4
00493b8b inc ecx
00493b8c dec esi
00493b8d jne 0x493b80
00493b8f cmp edi, 1
00493b92 mov dword ptr [esp + 0x18], edi
00493b96 jle 0x493b9c
00493b98 fidiv dword ptr [esp + 0x18]
00493b9c fmul st(1)
00493b9e fadd dword ptr [edx + 0x164]
00493ba4 faddp st(2)
00493ba6 fstp st(0)
00493ba8 mov eax, dword ptr [esp + 0x10]
00493bac add ebp, 4
00493baf dec eax
00493bb0 mov dword ptr [esp + 0x10], eax
00493bb4 jne 0x493b4d
00493bb6 pop edi
00493bb7 pop esi
00493bb8 pop ebp
00493bb9 pop ebx
00493bba pop ecx
00493bbb ret
00493bbc nop
00493bbd nop
00493bbe nop
00493bbf nop
00493bc0 sub esp, 8
00493bc3 fld dword ptr [0x5b23f8]
00493bc9 push ebx
00493bca push ebp
00493bcb mov ebp, dword ptr [esp + 0x14]
00493bcf xor ebx, ebx
00493bd1 push esi
00493bd2 mov dword ptr [esp + 0x10], ebx
00493bd6 lea eax, [ebp + 0x768]
00493bdc push edi
00493bdd mov dword ptr [esp + 0x1c], eax
00493be1 mov dword ptr [esp + 0x14], 0x14
00493be9 mov ecx, dword ptr [esp + 0x1c]
00493bed mov edx, dword ptr [ecx]
00493bef mov ax, word ptr [edx + 0x26]
00493bf3 cmp ax, 4
00493bf7 je 0x493c05
00493bf9 cmp ax, 5
00493bfd je 0x493c05
00493bff cmp ax, 8
00493c03 jne 0x493c57
00493c05 fld dword ptr [edx + 0x60]
00493c08 fmul dword ptr [0x5b3284]
00493c0e inc ebx
00493c0f xor edi, edi
00493c11 mov dword ptr [esp + 0x10], edi
00493c15 lea ecx, [edx + 0x48]
00493c18 fsubr dword ptr [0x5b246c]
00493c1e fld dword ptr [0x5b23f8]
00493c24 lea eax, [ebp + 0x4e4]
00493c2a mov esi, 0xa
00493c2f cmp byte ptr [ecx], 0
00493c32 je 0x493c37
00493c34 fadd dword ptr [eax]
00493c36 inc edi
00493c37 add eax, 4
00493c3a inc ecx
00493c3b dec esi
00493c3c jne 0x493c2f
00493c3e cmp edi, 1
00493c41 mov dword ptr [esp + 0x10], edi
00493c45 jle 0x493c4b
00493c47 fidiv dword ptr [esp + 0x10]
00493c4b fmul st(1)
00493c4d fadd dword ptr [edx + 0x164]
00493c53 faddp st(2)
00493c55 fstp st(0)
00493c57 mov ecx, dword ptr [esp + 0x1c]
00493c5b mov eax, dword ptr [esp + 0x14]
00493c5f add ecx, 4
00493c62 dec eax
00493c63 mov dword ptr [esp + 0x1c], ecx
00493c67 mov dword ptr [esp + 0x14], eax
00493c6b jne 0x493be9
00493c71 pop edi
00493c72 pop esi
00493c73 mov dword ptr [esp + 0xc], ebx
00493c77 pop ebp
00493c78 cmp ebx, 1
00493c7b pop ebx
00493c7c jle 0x493c82
00493c7e fidiv dword ptr [esp + 4]
00493c82 add esp, 8
00493c85 ret
00493c86 nop
00493c87 nop
00493c88 nop
00493c89 nop
00493c8a nop
00493c8b nop
00493c8c nop
00493c8d nop
00493c8e nop
00493c8f nop
00493c90 mov eax, dword ptr [esp + 4]
00493c94 mov ecx, 9
00493c99 fld dword ptr [0x5b23f8]
00493c9f add eax, 0x4e4
00493ca4 fadd dword ptr [eax]
00493ca6 add eax, 4
00493ca9 dec ecx
00493caa jne 0x493ca4
00493cac fmul dword ptr [0x5b49b0]
00493cb2 ret
00493cb3 nop
00493cb4 nop
00493cb5 nop
00493cb6 nop
00493cb7 nop
00493cb8 nop
00493cb9 nop
00493cba nop
00493cbb nop
00493cbc nop
00493cbd nop
00493cbe nop
00493cbf nop
00493cc0 mov eax, dword ptr [esp + 4]
00493cc4 mov ecx, 0xa
00493cc9 fld dword ptr [0x5b23f8]
00493ccf add eax, 0x4e4
00493cd4 fadd dword ptr [eax]
00493cd6 add eax, 4
00493cd9 dec ecx
00493cda jne 0x493cd4
00493cdc fmul dword ptr [0x5b49b4]
00493ce2 ret
00493ce3 nop
00493ce4 nop
00493ce5 nop
00493ce6 nop
00493ce7 nop
00493ce8 nop
00493ce9 nop
00493cea nop
00493ceb nop
00493cec nop
00493ced nop
00493cee nop
00493cef nop
00493cf0 push ecx
00493cf1 push ebx
00493cf2 push ebp
00493cf3 mov ebp, dword ptr [esp + 0x10]
00493cf7 push esi
00493cf8 push edi
00493cf9 mov dword ptr [esp + 0x10], 0x14
00493d01 lea ebx, [ebp + 0x768]
00493d07 mov edx, dword ptr [ebx]
00493d09 mov ax, word ptr [edx + 0x26]
00493d0d test ax, ax
00493d10 jle 0x493db4
00493d16 cmp ax, 0xb
00493d1a jge 0x493db4
00493d20 fld dword ptr [edx + 0x60]
00493d23 fmul dword ptr [0x5b3284]
00493d29 mov eax, dword ptr [esp + 0x1c]
00493d2d test eax, eax
00493d2f fsubr dword ptr [0x5b246c]
00493d35 je 0x493d39
00493d37 fchs
00493d39 fld dword ptr [0x5b23f8]
00493d3f xor edi, edi
00493d41 lea ecx, [edx + 0x48]
00493d44 mov dword ptr [esp + 0x18], edi
00493d48 lea eax, [ebp + 0x4e4]
00493d4e mov esi, 0xa
00493d53 cmp byte ptr [ecx], 0
00493d56 je 0x493d5b
00493d58 fadd dword ptr [eax]
00493d5a inc edi
00493d5b add eax, 4
00493d5e inc ecx
00493d5f dec esi
00493d60 jne 0x493d53
00493d62 cmp edi, 1
00493d65 mov dword ptr [esp + 0x18], edi
00493d69 jle 0x493d6f
00493d6b fidiv dword ptr [esp + 0x18]
00493d6f fmul st(1)
00493d71 mov eax, dword ptr [esp + 0x1c]
00493d75 test eax, eax
00493d77 fadd dword ptr [edx + 0x164]
00493d7d fstp dword ptr [edx + 0x164]
00493d83 fstp st(0)
00493d85 jne 0x493db4
00493d87 mov ecx, dword ptr [ebx]
00493d89 fld dword ptr [ecx + 0x164]
00493d8f fcomp dword ptr [0x5b242c]
00493d95 fnstsw ax
00493d97 test ah, 0x41
00493d9a jne 0x493da6
00493d9c mov dword ptr [ecx + 0x164], 0x42c80000
00493da6 mov eax, dword ptr [ebx]
00493da8 mov ecx, dword ptr [eax + 0x164]
00493dae mov dword ptr [ebx + 0x4e0], ecx
00493db4 mov eax, dword ptr [esp + 0x10]
00493db8 add ebx, 4
00493dbb dec eax
00493dbc mov dword ptr [esp + 0x10], eax
00493dc0 jne 0x493d07
00493dc6 pop edi
00493dc7 pop esi
00493dc8 pop ebp
00493dc9 pop ebx
00493dca pop ecx
00493dcb ret
00493dcc nop
00493dcd nop
00493dce nop
00493dcf nop
00493dd0 push esi
00493dd1 mov esi, dword ptr [esp + 8]
00493dd5 push edi
00493dd6 lea eax, [esi + 0x490]
00493ddc lea edi, [esi + 0x33c]
00493de2 push eax
00493de3 push edi
00493de4 call 0x532910
00493de9 fstp dword ptr [esi + 0xd58]
00493def lea ecx, [esi + 0x4a8]
00493df5 push ecx
00493df6 push edi
00493df7 call 0x532910
00493dfc fst dword ptr [esi + 0xd60]
00493e02 fld st(0)
00493e04 fcomp dword ptr [0x5b23f8]
00493e0a add esp, 0x10
00493e0d fnstsw ax
00493e0f test ah, 1
00493e12 je 0x493e16
00493e14 fchs
00493e16 fstp dword ptr [esp + 0xc]
00493e1a xor edx, edx
00493e1c lea eax, [esi + 0x870]
00493e22 mov dword ptr [esi + 0xdc0], edx
00493e28 mov ecx, 4
00493e2d mov dword ptr [eax], edx
00493e2f add eax, 0xc4
00493e34 dec ecx
00493e35 jne 0x493e2d
00493e37 mov dword ptr [esi + 0xdb8], edx
00493e3d pop edi
00493e3e pop esi
00493e3f ret
00493e40 push esi
00493e41 mov esi, dword ptr [esp + 8]
00493e45 push edi
00493e46 lea edi, [esi + 0x33c]
00493e4c push edi
00493e4d push 0x3f7f7cee
00493e52 push edi
00493e53 push 1
00493e55 call 0x532360
00493e5a lea eax, [esi + 0x364]
00493e60 push eax
00493e61 push edi
00493e62 call 0x532910
00493e67 fstp dword ptr [esi + 0xd58]
00493e6d lea ecx, [esi + 0x370]
00493e73 push ecx
00493e74 push edi
00493e75 call 0x532910
00493e7a fstp dword ptr [esi + 0xd5c]
00493e80 lea edx, [esi + 0x37c]
00493e86 push edx
00493e87 push edi
00493e88 call 0x532910
00493e8d fstp dword ptr [esi + 0xd60]
00493e93 fld dword ptr [esi + 0x344]
00493e99 fcomp dword ptr [0x5b23f8]
00493e9f fld dword ptr [esi + 0x344]
00493ea5 add esp, 0x28
00493ea8 fnstsw ax
00493eaa test ah, 1
00493ead je 0x493eb1
00493eaf fchs
00493eb1 fld dword ptr [edi]
00493eb3 fcomp dword ptr [0x5b23f8]
00493eb9 fld dword ptr [edi]
00493ebb fnstsw ax
00493ebd test ah, 1
00493ec0 je 0x493ec4
00493ec2 fchs
00493ec4 fcom st(1)
00493ec6 fnstsw ax
00493ec8 test ah, 0x41
00493ecb jne 0x493edd
00493ecd fxch st(1)
00493ecf fmul dword ptr [0x5b2468]
00493ed5 fadd st(1)
00493ed7 fxch st(1)
00493ed9 fstp st(0)
00493edb jmp 0x493ee5
00493edd fmul dword ptr [0x5b2468]
00493ee3 faddp st(1)
00493ee5 mov al, byte ptr [esi + 0x52c]
00493eeb fstp dword ptr [esi + 0x35c]
00493ef1 test al, 4
00493ef3 je 0x493efe
00493ef5 push esi
00493ef6 call 0x493dd0
00493efb add esp, 4
00493efe pop edi
00493eff pop esi
00493f00 ret
00493f01 nop
00493f02 nop
00493f03 nop
00493f04 nop
00493f05 nop
00493f06 nop
00493f07 nop
00493f08 nop
00493f09 nop
00493f0a nop
00493f0b nop
00493f0c nop
00493f0d nop
00493f0e nop
00493f0f nop
00493f10 fld dword ptr [esp + 8]
00493f14 fcomp dword ptr [0x5b243c]
00493f1a push esi
00493f1b mov esi, dword ptr [esp + 8]
00493f1f mov dword ptr [esi + 0x434], 0
00493f29 fnstsw ax
00493f2b test ah, 1
00493f2e jne 0x493f47
00493f30 fld dword ptr [esi + 0xd60]
00493f36 fcomp dword ptr [0x5b2470]
00493f3c fnstsw ax
00493f3e test ah, 1
00493f41 je 0x493ff2
00493f47 push edi
00493f48 mov edi, dword ptr [esp + 0x14]
00493f4c lea eax, [esi + 0x4a8]
00493f52 push eax
00493f53 push edi
00493f54 call 0x532910
00493f59 fstp dword ptr [esp + 0x14]
00493f5d lea ecx, [esi + 0x490]
00493f63 push ecx
00493f64 push edi
00493f65 call 0x532910
00493f6a fcom dword ptr [0x5b23f8]
00493f70 fst dword ptr [esp + 0x24]
00493f74 add esp, 0x10
00493f77 fnstsw ax
00493f79 pop edi
00493f7a test ah, 1
00493f7d je 0x493f81
00493f7f fchs
00493f81 fstp dword ptr [esp + 0xc]
00493f85 fld dword ptr [esp + 8]
00493f89 fcomp dword ptr [0x5b23f8]
00493f8f fld dword ptr [esp + 8]
00493f93 fnstsw ax
00493f95 test ah, 1
00493f98 je 0x493f9c
00493f9a fchs
00493f9c fcom dword ptr [esp + 0xc]
00493fa0 fnstsw ax
00493fa2 test ah, 0x41
00493fa5 jne 0x493fad
00493fa7 fstp st(0)
00493fa9 fld dword ptr [esp + 0xc]
00493fad fmul dword ptr [0x5b2468]
00493fb3 fld dword ptr [esp + 8]
00493fb7 fcomp dword ptr [0x5b23f8]
00493fbd fld dword ptr [esp + 0x10]
00493fc1 fnstsw ax
00493fc3 fcomp dword ptr [0x5b23f8]
00493fc9 test ah, 1
00493fcc fnstsw ax
00493fce je 0x493fdf
00493fd0 test ah, 1
00493fd3 je 0x493fec
00493fd5 fchs
00493fd7 fstp dword ptr [esi + 0x38c]
00493fdd pop esi
00493fde ret
00493fdf test ah, 0x41
00493fe2 jne 0x493fe6
00493fe4 fchs
00493fe6 fmul dword ptr [0x5b23f0]
00493fec fstp dword ptr [esi + 0x38c]
00493ff2 pop esi
00493ff3 ret
00493ff4 nop
00493ff5 nop
00493ff6 nop
00493ff7 nop
00493ff8 nop
00493ff9 nop
00493ffa nop
00493ffb nop
00493ffc nop
00493ffd nop
00493ffe nop
00493fff nop
00494000 sub esp, 0x48
00494003 mov eax, dword ptr [esp + 0x54]
00494007 push ebx
00494008 mov ebx, dword ptr [esp + 0x50]
0049400c push esi
0049400d push edi
0049400e mov ecx, 0xc
00494013 lea esi, [ebx + 8]
00494016 lea edi, [esp + 0x24]
0049401a rep movsd dword ptr es:[edi], dword ptr [esi]
0049401c mov ecx, dword ptr [eax]
0049401e mov esi, dword ptr [esp + 0x64]
00494022 mov dword ptr [esp + 0xc], ecx
00494026 lea ecx, [esp + 0xc]
0049402a mov edx, dword ptr [eax + 4]
0049402d push ecx
0049402e mov dword ptr [esp + 0x14], edx
00494032 lea edx, [esp + 0x10]
00494036 mov eax, dword ptr [eax + 8]
00494039 push esi
0049403a push edx
0049403b push 1
0049403d mov dword ptr [esp + 0x24], eax
00494041 call 0x532300
00494046 add esp, 0x10
00494049 lea eax, [esp + 0xc]
0049404d lea ecx, [esp + 0x24]
00494051 push 0
00494053 push eax
00494054 call 0x474060
00494059 mov al, byte ptr [esp + 0x48]
0049405d mov edi, dword ptr [esp + 0x5c]
00494061 test al, 0xf
00494063 jne 0x494079
00494065 lea ecx, [esp + 0xc]
00494069 push ecx
0049406a push 0
0049406c push edi
0049406d push 1
0049406f call 0x532360
00494074 add esp, 0x10
00494077 jmp 0x494098
00494079 push esi
0049407a call 0x532b20
0049407f mov edx, dword ptr [esi]
00494081 mov eax, dword ptr [esi + 4]
00494084 mov ecx, dword ptr [esi + 8]
00494087 add esp, 4
0049408a fstp st(0)
0049408c mov dword ptr [esp + 0xc], edx
00494090 mov dword ptr [esp + 0x10], eax
00494094 mov dword ptr [esp + 0x14], ecx
00494098 lea edx, [esp + 0xc]
0049409c lea eax, [esp + 0xc]
004940a0 push edx
004940a1 push 0x3f866666
004940a6 push eax
004940a7 push 1
004940a9 call 0x532360
004940ae lea esi, [ebx + 0x33c]
004940b4 push edi
004940b5 push esi
004940b6 call 0x532910
004940bb fchs
004940bd fst dword ptr [esp + 0x70]
004940c1 fcomp dword ptr [0x5b23f8]
004940c7 add esp, 0x18
004940ca fnstsw ax
004940cc test ah, 0x41
004940cf jne 0x49438a
004940d5 mov ecx, dword ptr [0x628c88]
004940db cmp ecx, 0x10
004940de jb 0x4940e5
004940e0 cmp ecx, 0x60
004940e3 jbe 0x4940f0
004940e5 mov ecx, 0x60
004940ea mov dword ptr [0x628c88], ecx
004940f0 fld dword ptr [ebx + 0x35c]
004940f6 fmul dword ptr [0x5b272c]
004940fc fcomp dword ptr [esp + 0x58]
00494100 fnstsw ax
00494102 test ah, 0x41
00494105 lea eax, [ecx - 0x10]
00494108 jne 0x494182
0049410a cmp eax, 0x50
0049410d ja 0x494166
0049410f xor ecx, ecx
00494111 mov cl, byte ptr [eax + 0x4943bc]
00494117 jmp dword ptr [ecx*4 + 0x4943a0]
0049411e mov dword ptr [ebx + 0x438], 0x40015
00494128 jmp 0x494170
0049412a mov dword ptr [ebx + 0x438], 0x40016
00494134 jmp 0x494170
00494136 mov dword ptr [ebx + 0x438], 0x40017
00494140 jmp 0x494170
00494142 mov dword ptr [ebx + 0x438], 0x40018
0049414c jmp 0x494170
0049414e mov dword ptr [ebx + 0x438], 0x40019
00494158 jmp 0x494170
0049415a mov dword ptr [ebx + 0x438], 0x4001a
00494164 jmp 0x494170
00494166 mov dword ptr [ebx + 0x438], 0x4001f
00494170 fld dword ptr [ebx + 0x35c]
00494176 fmul dword ptr [0x5b49b0]
0049417c fstp dword ptr [esp + 0x64]
00494180 jmp 0x4941f0
00494182 cmp eax, 0x50
00494185 ja 0x4941de
00494187 xor edx, edx
00494189 mov dl, byte ptr [eax + 0x49442c]
0049418f jmp dword ptr [edx*4 + 0x494410]
00494196 mov dword ptr [ebx + 0x438], 0x40008
004941a0 jmp 0x4941e8
004941a2 mov dword ptr [ebx + 0x438], 0x40009
004941ac jmp 0x4941e8
004941ae mov dword ptr [ebx + 0x438], 0x4000a
004941b8 jmp 0x4941e8
004941ba mov dword ptr [ebx + 0x438], 0x4000b
004941c4 jmp 0x4941e8
004941c6 mov dword ptr [ebx + 0x438], 0x4000c
004941d0 jmp 0x4941e8
004941d2 mov dword ptr [ebx + 0x438], 0x4000d
004941dc jmp 0x4941e8
004941de mov dword ptr [ebx + 0x438], 0x4001f
004941e8 mov eax, dword ptr [esp + 0x58]
004941ec mov dword ptr [esp + 0x64], eax
004941f0 fld dword ptr [esp + 0x58]
004941f4 fmul dword ptr [0x5b27a4]
004941fa lea ecx, [esp + 0x18]
004941fe push ecx
004941ff push ecx
00494200 fstp dword ptr [esp]
00494203 push edi
00494204 push 1
00494206 call 0x532360
0049420b fld dword ptr [esp + 0x28]
0049420f fadd dword ptr [esi]
00494211 add esp, 0x10
00494214 fst dword ptr [esi]
00494216 fld dword ptr [esp + 0x1c]
0049421a fadd dword ptr [ebx + 0x340]
00494220 fstp dword ptr [ebx + 0x340]
00494226 fld dword ptr [esp + 0x20]
0049422a fadd dword ptr [ebx + 0x344]
00494230 fst dword ptr [esp + 0x60]
00494234 fstp dword ptr [ebx + 0x344]
0049423a fcom dword ptr [0x5b23f8]
00494240 fnstsw ax
00494242 test ah, 1
00494245 je 0x494249
00494247 fchs
00494249 fld dword ptr [esp + 0x60]
0049424d fcomp dword ptr [0x5b23f8]
00494253 fld dword ptr [esp + 0x60]
00494257 fnstsw ax
00494259 test ah, 1
0049425c je 0x494260
0049425e fchs
00494260 fld st(1)
00494262 fcomp st(1)
00494264 fnstsw ax
00494266 test ah, 0x41
00494269 jne 0x494275
0049426b fmul dword ptr [0x5b2468]
00494271 faddp st(1)
00494273 jmp 0x494283
00494275 fxch st(1)
00494277 fmul dword ptr [0x5b2468]
0049427d fadd st(1)
0049427f fxch st(1)
00494281 fstp st(0)
00494283 fstp dword ptr [ebx + 0x35c]
00494289 fld dword ptr [esp + 0xc]
0049428d fadd dword ptr [ebx + 0x330]
00494293 mov eax, dword ptr [esp + 0x68]
00494297 test eax, eax
00494299 fstp dword ptr [ebx + 0x330]
0049429f fld dword ptr [esp + 0x10]
004942a3 fadd dword ptr [ebx + 0x334]
004942a9 fstp dword ptr [ebx + 0x334]
004942af fld dword ptr [esp + 0x14]
004942b3 fadd dword ptr [ebx + 0x338]
004942b9 fstp dword ptr [ebx + 0x338]
004942bf fld dword ptr [esp + 0xc]
004942c3 fadd dword ptr [ebx + 0x7f8]
004942c9 fstp dword ptr [ebx + 0x7f8]
004942cf fld dword ptr [esp + 0x14]
004942d3 fadd dword ptr [ebx + 0x800]
004942d9 fstp dword ptr [ebx + 0x800]
004942df fld dword ptr [esp + 0xc]
004942e3 fadd dword ptr [ebx + 0x8bc]
004942e9 fstp dword ptr [ebx + 0x8bc]
004942ef fld dword ptr [esp + 0x14]
004942f3 fadd dword ptr [ebx + 0x8c4]
004942f9 fstp dword ptr [ebx + 0x8c4]
004942ff fld dword ptr [esp + 0xc]
00494303 fadd dword ptr [ebx + 0x980]
00494309 fstp dword ptr [ebx + 0x980]
0049430f fld dword ptr [esp + 0x14]
00494313 fadd dword ptr [ebx + 0x988]
00494319 fstp dword ptr [ebx + 0x988]
0049431f fld dword ptr [esp + 0xc]
00494323 fadd dword ptr [ebx + 0xa44]
00494329 fstp dword ptr [ebx + 0xa44]
0049432f fld dword ptr [esp + 0x14]
00494333 fadd dword ptr [ebx + 0xa4c]
00494339 fstp dword ptr [ebx + 0xa4c]
0049433f je 0x494350
00494341 mov edx, dword ptr [esp + 0x58]
00494345 push edi
00494346 push edx
00494347 push ebx
00494348 call 0x493f10
0049434d add esp, 0xc
00494350 push ebx
00494351 call 0x493e40
00494356 fld dword ptr [esp + 0x68]
0049435a fmul dword ptr [0x5b2600]
00494360 add esp, 4
00494363 fcom dword ptr [0x5b23f8]
00494369 fnstsw ax
0049436b test ah, 1
0049436e je 0x494372
00494370 fchs
00494372 fstp dword ptr [esp + 0x58]
00494376 lea ecx, [esp + 0x24]
0049437a call 0x516950
0049437f fld dword ptr [esp + 0x58]
00494383 pop edi
00494384 pop esi
00494385 pop ebx
00494386 add esp, 0x48
00494389 ret
0049438a lea ecx, [esp + 0x24]
0049438e call 0x516950
00494393 fld dword ptr [0x5b23f8]
00494399 pop edi
0049439a pop esi
0049439b pop ebx
0049439c add esp, 0x48
0049439f ret
004943a0 push ds
004943a1 inc ecx
004943a2 dec ecx
004943a3 add byte ptr [edx], ch
004943a5 inc ecx
004943a6 dec ecx
004943a7 add byte ptr [esi], dh
004943a9 inc ecx
004943aa dec ecx
004943ab add byte ptr [edx + 0x41], al
004943ae dec ecx
004943af add byte ptr [esi + 0x41], cl
004943b2 dec ecx
004943b3 add byte ptr [edx + 0x41], bl
004943b6 dec ecx
004943b7 add byte ptr [esi + 0x41], ah
004943ba dec ecx
004943bb add byte ptr [eax], al
004943bd push es
004943be push es
004943bf push es
004943c0 push es
004943c1 push es
004943c2 push es
004943c3 push es
004943c4 push es
004943c5 push es
004943c6 push es
004943c7 push es
004943c8 push es
004943c9 push es
004943ca push es
004943cb push es
004943cc add dword ptr [esi], eax
004943ce push es
004943cf push es
004943d0 push es
004943d1 push es
004943d2 push es
004943d3 push es
004943d4 push es
004943d5 push es
004943d6 push es
004943d7 push es
004943d8 push es
004943d9 push es
004943da push es
004943db push es
004943dc add al, byte ptr [esi]
004943de push es
004943df push es
004943e0 push es
004943e1 push es
004943e2 push es
004943e3 push es
004943e4 push es
004943e5 push es
004943e6 push es
004943e7 push es
004943e8 push es
004943e9 push es
004943ea push es
004943eb push es
004943ec add eax, dword ptr [esi]
004943ee push es
004943ef push es
004943f0 push es
004943f1 push es
004943f2 push es
004943f3 push es
004943f4 push es
004943f5 push es
004943f6 push es
004943f7 push es
004943f8 push es
004943f9 push es
004943fa push es
004943fb push es
004943fc add al, 6
004943fe push es
004943ff push es
00494400 push es
00494401 push es
00494402 push es
00494403 push es
00494404 push es
00494405 push es
00494406 push es
00494407 push es
00494408 push es
00494409 push es
0049440a push es
0049440b push es
0049440c add eax, 0x9600498d
00494411 inc ecx
00494412 dec ecx
00494413 add byte ptr [edx - 0x51ffb6bf], ah
00494419 inc ecx
0049441a dec ecx
0049441b add byte ptr [edx - 0x39ffb6bf], bh
00494421 inc ecx
00494422 dec ecx
00494423 add dl, dl
00494425 inc ecx
00494426 dec ecx
00494427 add dh, bl
00494429 inc ecx
0049442a dec ecx
0049442b add byte ptr [eax], al
0049442d push es
0049442e push es
0049442f push es
00494430 push es
00494431 push es
00494432 push es
00494433 push es
00494434 push es
00494435 push es
00494436 push es
00494437 push es
00494438 push es
00494439 push es
0049443a push es
0049443b push es
0049443c add dword ptr [esi], eax
0049443e push es
0049443f push es
00494440 push es
00494441 push es
00494442 push es
00494443 push es
00494444 push es
00494445 push es
00494446 push es
00494447 push es
00494448 push es
00494449 push es
0049444a push es
0049444b push es
0049444c add al, byte ptr [esi]
0049444e push es
0049444f push es
00494450 push es
00494451 push es
00494452 push es
00494453 push es
00494454 push es
00494455 push es
00494456 push es
00494457 push es
00494458 push es
00494459 push es
0049445a push es
0049445b push es
0049445c add eax, dword ptr [esi]
0049445e push es
0049445f push es
00494460 push es
00494461 push es
00494462 push es
00494463 push es
00494464 push es
00494465 push es
00494466 push es
00494467 push es
00494468 push es
00494469 push es
0049446a push es
0049446b push es
0049446c add al, 6
0049446e push es
0049446f push es
00494470 push es
00494471 push es
00494472 push es
00494473 push es
00494474 push es
00494475 push es
00494476 push es
00494477 push es
00494478 push es
00494479 push es
0049447a push es
0049447b push es
0049447c add eax, 0x53909090
00494481 push edi
00494482 mov edi, dword ptr [esp + 0x10]
00494486 xor ebx, ebx
00494488 test byte ptr [edi + 0x24], 0xf
0049448c jne 0x494496
0049448e pop edi
0049448f mov eax, 1
00494494 pop ebx
00494495 ret
00494496 push esi
00494497 push 0
00494499 mov ecx, edi
0049449b call 0x4745f0
004944a0 mov ecx, edi
004944a2 mov esi, eax
004944a4 call 0x474420
004944a9 mov ecx, dword ptr [esp + 0x18]
004944ad fld dword ptr [ecx]
004944af fsub dword ptr [esi]
004944b1 fmul dword ptr [eax]
004944b3 fchs
004944b5 fld dword ptr [ecx + 8]
004944b8 fsub dword ptr [esi + 8]
004944bb fmul dword ptr [eax + 8]
004944be fsubp st(1)
004944c0 fdiv dword ptr [eax + 4]
004944c3 mov eax, dword ptr [esp + 0x10]
004944c7 fadd dword ptr [esi + 4]
004944ca pop esi
004944cb fsub dword ptr [eax + 0x334]
004944d1 fcom dword ptr [0x5b23f8]
004944d7 fnstsw ax
004944d9 test ah, 1
004944dc je 0x4944e0
004944de fchs
004944e0 fcomp dword ptr [0x5b2404]
004944e6 fnstsw ax
004944e8 test ah, 0x41
004944eb mov eax, 2
004944f0 je 0x4944f4
004944f2 mov eax, ebx
004944f4 pop edi
004944f5 pop ebx
004944f6 ret
004944f7 nop
004944f8 nop
004944f9 nop
004944fa nop
004944fb nop
004944fc nop
004944fd nop
004944fe nop
004944ff nop
00494500 mov eax, dword ptr [0x657a2c]
00494505 sub esp, 0x38
00494508 test eax, eax
0049450a push ebx
0049450b push ebp
0049450c mov ebp, dword ptr [esp + 0x4c]
00494510 push esi
00494511 mov esi, dword ptr [esp + 0x48]
00494515 push edi
00494516 mov ebx, 1
0049451b je 0x49481a
00494521 mov eax, dword ptr [esi + 0xb50]
00494527 test eax, eax
00494529 jne 0x49481a
0049452f mov eax, dword ptr [0x657400]
00494534 fld dword ptr [esp + 0x50]
00494538 test eax, eax
0049453a je 0x49455b
0049453c fmul dword ptr [0x5b246c]
00494542 fcom dword ptr [0x5b242c]
00494548 fnstsw ax
0049454a test ah, 0x41
0049454d jne 0x49457a
0049454f fstp st(0)
00494551 mov dword ptr [esp + 0x54], 0x42c80000
00494559 jmp 0x49457e
0049455b fmul dword ptr [0x5b23f0]
00494561 fcom dword ptr [0x5b242c]
00494567 fnstsw ax
00494569 test ah, 0x41
0049456c jne 0x49457a
0049456e fstp st(0)
00494570 mov dword ptr [esp + 0x54], 0x42c80000
00494578 jmp 0x49457e
0049457a fstp dword ptr [esp + 0x54]
0049457e test ebp, ebp
00494580 je 0x494596
00494582 cmp ebp, 2
00494585 je 0x494596
00494587 cmp ebp, 4
0049458a je 0x494596
0049458c cmp ebp, 6
0049458f je 0x494596
00494591 cmp ebp, 8
00494594 jne 0x4945d2
00494596 fld dword ptr [esp + 0x54]
0049459a fcomp dword ptr [0x5b2408]
004945a0 fnstsw ax
004945a2 test ah, 0x41
004945a5 jne 0x4945d2
004945a7 fld dword ptr [esi + ebp*4 + 0x4e4]
004945ae fcomp dword ptr [0x5b2408]
004945b4 fnstsw ax
004945b6 test ah, 1
004945b9 je 0x4945d2
004945bb mov eax, dword ptr [esp + 0x54]
004945bf push 0
004945c1 push eax
004945c2 push 3
004945c4 push 4
004945c6 push -1
004945c8 push ebx
004945c9 push esi
004945ca call 0x40f020
004945cf add esp, 0x1c
004945d2 fld dword ptr [esi + ebp*4 + 0x4e4]
004945d9 fcom dword ptr [esp + 0x54]
004945dd fnstsw ax
004945df test ah, 0x41
004945e2 jne 0x4945ea
004945e4 fstp dword ptr [esp + 0x54]
004945e8 jmp 0x4945f4
004945ea mov ecx, dword ptr [esp + 0x54]
004945ee fstp st(0)
004945f0 mov dword ptr [esp + 0x54], ecx
004945f4 fld dword ptr [esp + 0x54]
004945f8 cmp ebp, 7
004945fb fstp dword ptr [esi + ebp*4 + 0x4e4]
00494602 jg 0x49481a
00494608 test ebp, ebp
0049460a jne 0x494673
0049460c fld dword ptr [esi + 0x4ec]
00494612 fadd dword ptr [esi + 0x4e4]
00494618 fmul dword ptr [0x5b23f0]
0049461e fld dword ptr [esi + 0x4e8]
00494624 fst dword ptr [esp + 0x54]
00494628 fcomp st(1)
0049462a fnstsw ax
0049462c test ah, 0x41
0049462f jne 0x494637
00494631 fstp st(0)
00494633 fld dword ptr [esp + 0x54]
00494637 fstp dword ptr [esi + 0x4e8]
0049463d fld dword ptr [esi + 0x4fc]
00494643 fadd dword ptr [esi + 0x4e4]
00494649 fmul dword ptr [0x5b23f0]
0049464f fld dword ptr [esi + 0x500]
00494655 fst dword ptr [esp + 0x54]
00494659 fcomp st(1)
0049465b fnstsw ax
0049465d test ah, 0x41
00494660 jne 0x494668
00494662 fstp st(0)
00494664 fld dword ptr [esp + 0x54]
00494668 fstp dword ptr [esi + 0x500]
0049466e jmp 0x49481a
00494673 cmp ebp, ebx
00494675 jne 0x4946de
00494677 fld dword ptr [esi + 0x500]
0049467d fadd dword ptr [esi + 0x4e8]
00494683 fmul dword ptr [0x5b23f0]
00494689 fld dword ptr [esi + 0x4e4]
0049468f fst dword ptr [esp + 0x54]
00494693 fcomp st(1)
00494695 fnstsw ax
00494697 test ah, 0x41
0049469a jne 0x4946a2
0049469c fstp st(0)
0049469e fld dword ptr [esp + 0x54]
004946a2 fstp dword ptr [esi + 0x4e4]
004946a8 fld dword ptr [esi + 0x4f0]
004946ae fadd dword ptr [esi + 0x4e8]
004946b4 fmul dword ptr [0x5b23f0]
004946ba fld dword ptr [esi + 0x4ec]
004946c0 fst dword ptr [esp + 0x54]
004946c4 fcomp st(1)
004946c6 fnstsw ax
004946c8 test ah, 0x41
004946cb jne 0x4946d3
004946cd fstp st(0)
004946cf fld dword ptr [esp + 0x54]
004946d3 fstp dword ptr [esi + 0x4ec]
004946d9 jmp 0x49481a
004946de cmp ebp, 6
004946e1 jne 0x49474a
004946e3 fld dword ptr [esi + 0x4f4]
004946e9 fadd dword ptr [esi + 0x4fc]
004946ef fmul dword ptr [0x5b23f0]
004946f5 fld dword ptr [esi + 0x4f8]
004946fb fst dword ptr [esp + 0x54]
004946ff fcomp st(1)
00494701 fnstsw ax
00494703 test ah, 0x41
00494706 jne 0x49470e
00494708 fstp st(0)
0049470a fld dword ptr [esp + 0x54]
0049470e fstp dword ptr [esi + 0x4f8]
00494714 fld dword ptr [esi + 0x4e4]
0049471a fadd dword ptr [esi + 0x4fc]
00494720 fmul dword ptr [0x5b23f0]
00494726 fld dword ptr [esi + 0x500]
0049472c fst dword ptr [esp + 0x54]
00494730 fcomp st(1)
00494732 fnstsw ax
00494734 test ah, 0x41
00494737 jne 0x49473f
00494739 fstp st(0)
0049473b fld dword ptr [esp + 0x54]
0049473f fstp dword ptr [esi + 0x500]
00494745 jmp 0x49481a
0049474a cmp ebp, 7
0049474d jne 0x4947b3
0049474f fld dword ptr [esi + 0x4e8]
00494755 fadd dword ptr [esi + 0x500]
0049475b fmul dword ptr [0x5b23f0]
00494761 fld dword ptr [esi + 0x4e4]
00494767 fst dword ptr [esp + 0x54]
0049476b fcomp st(1)
0049476d fnstsw ax
0049476f test ah, 0x41
00494772 jne 0x49477a
00494774 fstp st(0)
00494776 fld dword ptr [esp + 0x54]
0049477a fstp dword ptr [esi + 0x4e4]
00494780 fld dword ptr [esi + 0x4f8]
00494786 fadd dword ptr [esi + 0x500]
0049478c fmul dword ptr [0x5b23f0]
00494792 fld dword ptr [esi + 0x4fc]
00494798 fst dword ptr [esp + 0x54]
0049479c fcomp st(1)
0049479e fnstsw ax
004947a0 test ah, 0x41
004947a3 jne 0x4947ab
004947a5 fstp st(0)
004947a7 fld dword ptr [esp + 0x54]
004947ab fstp dword ptr [esi + 0x4fc]
004947b1 jmp 0x49481a
004947b3 fld dword ptr [esp + 0x54]
004947b7 fadd dword ptr [esi + ebp*4 + 0x4ec]
004947be fmul dword ptr [0x5b23f0]
004947c4 fld dword ptr [esi + ebp*4 + 0x4e8]
004947cb fst dword ptr [esp + 0x54]
004947cf fcomp st(1)
004947d1 fnstsw ax
004947d3 test ah, 0x41
004947d6 jne 0x4947de
004947d8 fstp st(0)
004947da fld dword ptr [esp + 0x54]
004947de fstp dword ptr [esi + ebp*4 + 0x4e8]
004947e5 fld dword ptr [esi + ebp*4 + 0x4dc]
004947ec fadd dword ptr [esi + ebp*4 + 0x4e4]
004947f3 fmul dword ptr [0x5b23f0]
004947f9 fld dword ptr [esi + ebp*4 + 0x4e0]
00494800 fst dword ptr [esp + 0x54]
00494804 fcomp st(1)
00494806 fnstsw ax
00494808 test ah, 0x41
0049480b jne 0x494813
0049480d fstp st(0)
0049480f fld dword ptr [esp + 0x54]
00494813 fstp dword ptr [esi + ebp*4 + 0x4e0]
0049481a mov edi, dword ptr [esp + 0x58]
0049481e test edi, edi
00494820 je 0x494ddc
00494826 mov eax, dword ptr [0x6573e8]
0049482b mov dword ptr [esp + 0x4c], 0x3f800000
00494833 cmp eax, 3
00494836 mov dword ptr [esp + 0x10], 0x3f800000
0049483e mov dword ptr [esp + 0x14], 0x3f800000
00494846 jne 0x49485d
00494848 mov eax, dword ptr [0x657408]
0049484d test eax, eax
0049484f je 0x49485d
00494851 fld dword ptr [esp + 0x50]
00494855 fmul dword ptr [0x5b23f0]
0049485b jmp 0x494873
0049485d mov edx, dword ptr [esi + 0x558]
00494863 mov eax, dword ptr [edx + 0x518]
00494869 test eax, eax
0049486b je 0x494877
0049486d fld dword ptr [esp + 0x50]
00494871 fadd st(0), st(0)
00494873 fstp dword ptr [esp + 0x50]
00494877 fld dword ptr [esp + 0x50]
0049487b fcomp dword ptr [0x5b26d4]
00494881 fnstsw ax
00494883 test ah, 0x41
00494886 jne 0x494c1c
0049488c mov edx, dword ptr [esi + 0x52c]
00494892 and edx, 0x80
00494898 jne 0x4948a0
0049489a mov dword ptr [esi + 0x42c], ebx
004948a0 mov ecx, dword ptr [esi + 0x558]
004948a6 mov eax, dword ptr [ecx + 0x518]
004948ac test eax, eax
004948ae jne 0x4948cb
004948b0 fld dword ptr [esp + 0x50]
004948b4 fcomp dword ptr [0x5b3d60]
004948ba fnstsw ax
004948bc test ah, 0x41
004948bf jne 0x4948cb
004948c1 mov dword ptr [esi + 0xdb0], 0
004948cb fld dword ptr [esp + 0x50]
004948cf fmul dword ptr [0x5b272c]
004948d5 mov word ptr [esi + 0x418], bx
004948dc mov dword ptr [esi + 0x450], 0
004948e6 mov dword ptr [esi + 0x1100], 0xc0
004948f0 mov dword ptr [esi + 0x1104], ebx
004948f6 fstp dword ptr [esp + 0x50]
004948fa fld dword ptr [esi + 0x424]
00494900 fcomp dword ptr [0x5b2604]
00494906 fnstsw ax
00494908 test ah, 1
0049490b je 0x49491f
0049490d fld dword ptr [esi + 0x334]
00494913 fadd dword ptr [0x5b2604]
00494919 fstp dword ptr [esi + 0x334]
0049491f fld dword ptr [esp + 0x50]
00494923 fmul dword ptr [0x5b24b8]
00494929 fld dword ptr [0x5b2580]
0049492f fcomp st(1)
00494931 fnstsw ax
00494933 test ah, 0x41
00494936 jne 0x49493e
00494938 fstp dword ptr [esp + 0x54]
0049493c jmp 0x494948
0049493e fstp st(0)
00494940 mov dword ptr [esp + 0x54], 0x40000000
00494948 mov eax, dword ptr [ecx + 0x518]
0049494e fld dword ptr [0x5b2480]
00494954 test eax, eax
00494956 je 0x494960
00494958 fstp st(0)
0049495a fld dword ptr [0x5b2600]
00494960 test edx, edx
00494962 je 0x4949df
00494964 fld dword ptr [esi + 0x354]
0049496a fcomp dword ptr [0x5b24a8]
00494970 fnstsw ax
00494972 test ah, 1
00494975 je 0x4949df
00494977 mov eax, dword ptr [0x5d102c]
0049497c imul eax, dword ptr [0x5d1028]
00494983 mov dword ptr [0x655a0c], eax
00494988 mov ecx, eax
0049498a shr eax, 8
0049498d and ecx, 0xffff
00494993 and eax, 0xffff
00494998 mov dword ptr [0x5d1028], ecx
0049499e mov dword ptr [esp + 0x4c], eax
004949a2 fld dword ptr [esi + 0x354]
004949a8 fild dword ptr [esp + 0x4c]
004949ac fmul dword ptr [0x5b26a0]
004949b2 fmul dword ptr [0x5b253c]
004949b8 fadd dword ptr [0x5b2604]
004949be fstp dword ptr [esp + 0x4c]
004949c2 fcom dword ptr [esp + 0x4c]
004949c6 fnstsw ax
004949c8 test ah, 0x41
004949cb je 0x4949d3
004949cd fstp st(0)
004949cf fld dword ptr [esp + 0x4c]
004949d3 fmul dword ptr [esp + 0x50]
004949d7 fmul dword ptr [0x5b3ecc]
004949dd jmp 0x4949e9
004949df fld dword ptr [esp + 0x50]
004949e3 fmul dword ptr [0x5b2680]
004949e9 fadd dword ptr [esi + 0x340]
004949ef cmp edi, 2
004949f2 fstp dword ptr [esi + 0x340]
004949f8 fst dword ptr [esp + 0x4c]
004949fc fst dword ptr [esp + 0x10]
00494a00 fstp dword ptr [esp + 0x14]
00494a04 jne 0x494c45
00494a0a fld dword ptr [esi + 0x388]
00494a10 fcomp dword ptr [0x5b23f8]
00494a16 fld dword ptr [esi + 0x388]
00494a1c fnstsw ax
00494a1e test ah, 1
00494a21 je 0x494a25
00494a23 fchs
00494a25 fcomp dword ptr [0x5b23f0]
00494a2b fnstsw ax
00494a2d test ah, 1
00494a30 je 0x494c45
00494a36 fld dword ptr [esi + 0x390]
00494a3c fcomp dword ptr [0x5b23f8]
00494a42 fld dword ptr [esi + 0x390]
00494a48 fnstsw ax
00494a4a test ah, 1
00494a4d je 0x494a51
00494a4f fchs
00494a51 fcomp dword ptr [0x5b23f0]
00494a57 fnstsw ax
00494a59 test ah, 1
00494a5c je 0x494c45
00494a62 test byte ptr [esi + 0x52c], 0x80
00494a69 jne 0x494b4f
00494a6f mov edx, dword ptr [esi + 0x558]
00494a75 mov eax, dword ptr [edx + 0x518]
00494a7b test eax, eax
00494a7d jne 0x494b4f
00494a83 mov eax, dword ptr [0x5d102c]
00494a88 imul eax, dword ptr [0x5d1028]
00494a8f mov ecx, eax
00494a91 shr eax, 8
00494a94 and eax, 0xffff
00494a99 and ecx, 0xffff
00494a9f mov dword ptr [esp + 0x50], eax
00494aa3 mov dword ptr [0x5d1028], ecx
00494aa9 fild dword ptr [esp + 0x50]
00494aad fmul dword ptr [0x5b2400]
00494ab3 fmul dword ptr [0x5b253c]
00494ab9 fsub dword ptr [0x5b2464]
00494abf fstp dword ptr [esi + 0x388]
00494ac5 mov eax, dword ptr [0x5d102c]
00494aca imul eax, dword ptr [0x5d1028]
00494ad1 mov edx, eax
00494ad3 shr eax, 8
00494ad6 and eax, 0xffff
00494adb and edx, 0xffff
00494ae1 mov dword ptr [esp + 0x50], eax
00494ae5 mov dword ptr [0x5d1028], edx
00494aeb fild dword ptr [esp + 0x50]
00494aef fadd st(0), st(0)
00494af1 fmul dword ptr [0x5b253c]
00494af7 fsub dword ptr [0x5b24a8]
00494afd fstp dword ptr [esi + 0x38c]
00494b03 mov eax, dword ptr [0x5d102c]
00494b08 imul eax, dword ptr [0x5d1028]
00494b0f mov dword ptr [0x655a0c], eax
00494b14 mov ecx, eax
00494b16 shr eax, 8
00494b19 and ecx, 0xffff
00494b1f and eax, 0xffff
00494b24 mov dword ptr [esp + 0x50], eax
00494b28 mov dword ptr [0x5d1028], ecx
00494b2e fild dword ptr [esp + 0x50]
00494b32 fmul dword ptr [0x5b2400]
00494b38 fmul dword ptr [0x5b253c]
00494b3e fsub dword ptr [0x5b2464]
00494b44 fstp dword ptr [esi + 0x390]
00494b4a jmp 0x494c45
00494b4f mov eax, dword ptr [0x5d102c]
00494b54 imul eax, dword ptr [0x5d1028]
00494b5b mov edx, eax
00494b5d shr eax, 8
00494b60 and eax, 0xffff
00494b65 and edx, 0xffff
00494b6b mov dword ptr [esp + 0x50], eax
00494b6f mov dword ptr [0x5d1028], edx
00494b75 fild dword ptr [esp + 0x50]
00494b79 fmul dword ptr [0x5b2470]
00494b7f fmul dword ptr [0x5b253c]
00494b85 fsub dword ptr [0x5b241c]
00494b8b fstp dword ptr [esi + 0x388]
00494b91 mov eax, dword ptr [0x5d102c]
00494b96 imul eax, dword ptr [0x5d1028]
00494b9d mov ecx, eax
00494b9f shr eax, 8
00494ba2 and eax, 0xffff
00494ba7 and ecx, 0xffff
00494bad mov dword ptr [esp + 0x50], eax
00494bb1 mov dword ptr [0x5d1028], ecx
00494bb7 fild dword ptr [esp + 0x50]
00494bbb fmul dword ptr [0x5b241c]
00494bc1 fmul dword ptr [0x5b253c]
00494bc7 fsub dword ptr [0x5b2400]
00494bcd fstp dword ptr [esi + 0x38c]
00494bd3 mov eax, dword ptr [0x5d102c]
00494bd8 imul eax, dword ptr [0x5d1028]
00494bdf mov dword ptr [0x655a0c], eax
00494be4 mov edx, eax
00494be6 shr eax, 8
00494be9 and edx, 0xffff
00494bef and eax, 0xffff
00494bf4 mov dword ptr [esp + 0x50], eax
00494bf8 mov dword ptr [0x5d1028], edx
00494bfe fild dword ptr [esp + 0x50]
00494c02 fmul dword ptr [0x5b2470]
00494c08 fmul dword ptr [0x5b253c]
00494c0e fsub dword ptr [0x5b241c]
00494c14 fstp dword ptr [esi + 0x390]
00494c1a jmp 0x494c45
00494c1c fld dword ptr [esp + 0x50]
00494c20 fmul dword ptr [0x5b24b8]
00494c26 fld dword ptr [0x5b3ecc]
00494c2c fcomp st(1)
00494c2e fnstsw ax
00494c30 test ah, 0x41
00494c33 jne 0x494c3b
00494c35 fstp dword ptr [esp + 0x54]
00494c39 jmp 0x494c45
00494c3b fstp st(0)
00494c3d mov dword ptr [esp + 0x54], 0x3ea8f5c3
00494c45 lea eax, [esi + 0x364]
00494c4b lea ebx, [esi + 0x388]
00494c51 push eax
00494c52 push ebx
00494c53 lea edi, [esi + 0xd64]
00494c59 call 0x532910
00494c5e fstp dword ptr [edi]
00494c60 lea eax, [esi + 0x370]
00494c66 push eax
00494c67 push ebx
00494c68 call 0x532910
00494c6d fstp dword ptr [esi + 0xd68]
00494c73 lea ecx, [esi + 0x37c]
00494c79 push ecx
00494c7a push ebx
00494c7b call 0x532910
00494c80 fst dword ptr [esi + 0xd6c]
00494c86 add esp, 0x18
00494c89 test ebp, ebp
00494c8b jl 0x494ca4
00494c8d cmp ebp, 2
00494c90 jg 0x494ca4
00494c92 fld dword ptr [esp + 0x4c]
00494c96 fmul dword ptr [esp + 0x54]
00494c9a fmul dword ptr [0x5b23f0]
00494ca0 fsubr dword ptr [edi]
00494ca2 jmp 0x494cb4
00494ca4 fld dword ptr [esp + 0x4c]
00494ca8 fmul dword ptr [esp + 0x54]
00494cac fmul dword ptr [0x5b23f0]
00494cb2 fadd dword ptr [edi]
00494cb4 fstp dword ptr [edi]
00494cb6 cmp ebp, 2
00494cb9 jl 0x494cec
00494cbb cmp ebp, 4
00494cbe jg 0x494cec
00494cc0 fld dword ptr [esp + 0x10]
00494cc4 fmul dword ptr [esp + 0x54]
00494cc8 fmul dword ptr [0x5b23f0]
00494cce fadd dword ptr [esi + 0xd68]
00494cd4 fstp dword ptr [esi + 0xd68]
00494cda fld dword ptr [esp + 0x14]
00494cde fmul dword ptr [esp + 0x54]
00494ce2 fmul dword ptr [0x5b23f0]
00494ce8 fadd st(1)
00494cea jmp 0x494d16
00494cec fld dword ptr [esp + 0x10]
00494cf0 fmul dword ptr [esp + 0x54]
00494cf4 fmul dword ptr [0x5b23f0]
00494cfa fsubr dword ptr [esi + 0xd68]
00494d00 fstp dword ptr [esi + 0xd68]
00494d06 fld dword ptr [esp + 0x14]
00494d0a fmul dword ptr [esp + 0x54]
00494d0e fmul dword ptr [0x5b23f0]
00494d14 fsubr st(1)
00494d16 fstp dword ptr [esi + 0xd6c]
00494d1c lea edx, [esp + 0x24]
00494d20 lea eax, [esi + 0x364]
00494d26 push edx
00494d27 push eax
00494d28 fstp st(0)
00494d2a call 0x532a00
00494d2f mov eax, dword ptr [esi + 0x434]
00494d35 add esp, 8
00494d38 test eax, eax
00494d3a jne 0x494d98
00494d3c mov eax, dword ptr [esi + 0xd6c]
00494d42 push eax
00494d43 call 0x5327e0
00494d48 fmul dword ptr [esi + 0x3a8]
00494d4e mov ecx, dword ptr [esi + 0xd6c]
00494d54 push ecx
00494d55 fchs
00494d57 fstp dword ptr [esp + 0x20]
00494d5b call 0x5327f0
00494d60 fmul dword ptr [esi + 0x3ac]
00494d66 lea edx, [esp + 0x38]
00494d6a lea eax, [esp + 0x20]
00494d6e push edx
00494d6f push eax
00494d70 fchs
00494d72 fstp dword ptr [esp + 0x2c]
00494d76 mov dword ptr [esp + 0x30], 0
00494d7e call 0x532910
00494d83 fmul dword ptr [0x5b24b8]
00494d89 add esp, 0x10
00494d8c fadd dword ptr [esi + 0x334]
00494d92 fstp dword ptr [esi + 0x334]
00494d98 lea ecx, [esp + 0x24]
00494d9c push ecx
00494d9d push edi
00494d9e call 0x532910
00494da3 fstp dword ptr [ebx]
00494da5 lea edx, [esp + 0x38]
00494da9 push edx
00494daa push edi
00494dab call 0x532910
00494db0 fstp dword ptr [esi + 0x38c]
00494db6 lea eax, [esp + 0x4c]
00494dba push eax
00494dbb push edi
00494dbc call 0x532910
00494dc1 mov eax, dword ptr [esp + 0x70]
00494dc5 add esp, 0x18
00494dc8 fstp dword ptr [esi + 0x390]
00494dce cmp eax, 2
00494dd1 je 0x494ddc
00494dd3 push esi
00494dd4 call 0x49bba0
00494dd9 add esp, 4
00494ddc pop edi
00494ddd pop esi
00494dde pop ebp
00494ddf pop ebx
00494de0 add esp, 0x38
00494de3 ret
00494de4 nop
00494de5 nop
00494de6 nop
00494de7 nop
00494de8 nop
00494de9 nop
00494dea nop
00494deb nop
00494dec nop
00494ded nop
00494dee nop
00494def nop
00494df0 sub esp, 8
00494df3 push ebx
00494df4 mov ebx, dword ptr [esp + 0x14]
00494df8 push esi
00494df9 push edi
00494dfa mov edi, dword ptr [esp + 0x18]
00494dfe mov esi, 9
00494e03 lea eax, [edi + 0x364]
00494e09 push eax
00494e0a push ebx
00494e0b call 0x532910
00494e10 fstp dword ptr [esp + 0x20]
00494e14 lea ecx, [edi + 0x370]
00494e1a push ecx
00494e1b push ebx
00494e1c call 0x532910
00494e21 fstp dword ptr [esp + 0x1c]
00494e25 lea edx, [edi + 0x37c]
00494e2b push edx
00494e2c push ebx
00494e2d call 0x532910
00494e32 fstp dword ptr [esp + 0x34]
00494e36 fld dword ptr [edi + 0x430]
00494e3c add esp, 0x18
00494e3f fst dword ptr [esp + 0x10]
00494e43 fcomp dword ptr [0x5b241c]
00494e49 fnstsw ax
00494e4b test ah, 0x41
00494e4e jne 0x495019
00494e54 fld dword ptr [esp + 0xc]
00494e58 fcomp dword ptr [0x5b2448]
00494e5e mov ebx, dword ptr [esp + 0x20]
00494e62 fnstsw ax
00494e64 test ah, 1
00494e67 je 0x494e87
00494e69 test byte ptr [edi + 0x52c], 0x80
00494e70 jne 0x494e87
00494e72 mov eax, dword ptr [esp + 0x10]
00494e76 mov esi, 8
00494e7b push ebx
00494e7c push esi
00494e7d push eax
00494e7e push edi
00494e7f call 0x494500
00494e84 add esp, 0x10
00494e87 fld dword ptr [esp + 0x18]
00494e8b fcomp dword ptr [0x5b23f8]
00494e91 fld dword ptr [esp + 0x18]
00494e95 fnstsw ax
00494e97 test ah, 1
00494e9a je 0x494e9e
00494e9c fchs
00494e9e fcomp dword ptr [0x5b2604]
00494ea4 fnstsw ax
00494ea6 test ah, 1
00494ea9 je 0x494ec6
00494eab fld dword ptr [esp + 0x1c]
00494eaf fcomp dword ptr [0x5b2444]
00494eb5 fnstsw ax
00494eb7 test ah, 1
00494eba je 0x494ec6
00494ebc mov esi, 1
00494ec1 jmp 0x495007
00494ec6 fld dword ptr [esp + 0x18]
00494eca fcomp dword ptr [0x5b23f8]
00494ed0 fld dword ptr [esp + 0x18]
00494ed4 fnstsw ax
00494ed6 test ah, 1
00494ed9 je 0x494edd
00494edb fchs
00494edd fcomp dword ptr [0x5b2604]
00494ee3 fnstsw ax
00494ee5 test ah, 1
00494ee8 je 0x494f05
00494eea fld dword ptr [esp + 0x1c]
00494eee fcomp dword ptr [0x5b2604]
00494ef4 fnstsw ax
00494ef6 test ah, 0x41
00494ef9 jne 0x494f05
00494efb mov esi, 5
00494f00 jmp 0x495007
00494f05 fld dword ptr [esp + 0x1c]
00494f09 fcomp dword ptr [0x5b23f8]
00494f0f fld dword ptr [esp + 0x1c]
00494f13 fnstsw ax
00494f15 test ah, 1
00494f18 je 0x494f1c
00494f1a fchs
00494f1c fcomp dword ptr [0x5b2604]
00494f22 fnstsw ax
00494f24 test ah, 1
00494f27 je 0x494f44
00494f29 fld dword ptr [esp + 0x18]
00494f2d fcomp dword ptr [0x5b2604]
00494f33 fnstsw ax
00494f35 test ah, 0x41
00494f38 jne 0x494f44
00494f3a mov esi, 7
00494f3f jmp 0x495007
00494f44 fld dword ptr [esp + 0x1c]
00494f48 fcomp dword ptr [0x5b23f8]
00494f4e fld dword ptr [esp + 0x1c]
00494f52 fnstsw ax
00494f54 test ah, 1
00494f57 je 0x494f5b
00494f59 fchs
00494f5b fcomp dword ptr [0x5b2604]
00494f61 fnstsw ax
00494f63 test ah, 1
00494f66 je 0x494f83
00494f68 fld dword ptr [esp + 0x18]
00494f6c fcomp dword ptr [0x5b2444]
00494f72 fnstsw ax
00494f74 test ah, 1
00494f77 je 0x494f83
00494f79 mov esi, 3
00494f7e jmp 0x495007
00494f83 fld dword ptr [esp + 0x1c]
00494f87 fcomp dword ptr [0x5b2444]
00494f8d fnstsw ax
00494f8f test ah, 1
00494f92 je 0x494fc1
00494f94 fld dword ptr [esp + 0x18]
00494f98 fcomp dword ptr [0x5b2604]
00494f9e fnstsw ax
00494fa0 test ah, 0x41
00494fa3 jne 0x494fa9
00494fa5 xor esi, esi
00494fa7 jmp 0x495007
00494fa9 fld dword ptr [esp + 0x18]
00494fad fcomp dword ptr [0x5b2444]
00494fb3 fnstsw ax
00494fb5 test ah, 1
00494fb8 je 0x494fc1
00494fba mov esi, 2
00494fbf jmp 0x495007
00494fc1 fld dword ptr [esp + 0x1c]
00494fc5 fcomp dword ptr [0x5b2604]
00494fcb fnstsw ax
00494fcd test ah, 0x41
00494fd0 jne 0x495002
00494fd2 fld dword ptr [esp + 0x18]
00494fd6 fcomp dword ptr [0x5b2604]
00494fdc fnstsw ax
00494fde test ah, 0x41
00494fe1 jne 0x494fea
00494fe3 mov esi, 6
00494fe8 jmp 0x495007
00494fea fld dword ptr [esp + 0x18]
00494fee fcomp dword ptr [0x5b2444]
00494ff4 fnstsw ax
00494ff6 test ah, 1
00494ff9 je 0x495002
00494ffb mov esi, 4
00495000 jmp 0x495007
00495002 cmp esi, 8
00495005 jge 0x495019
00495007 mov ecx, dword ptr [edi + 0x430]
0049500d push ebx
0049500e push esi
0049500f push ecx
00495010 push edi
00495011 call 0x494500
00495016 add esp, 0x10
00495019 pop edi
0049501a pop esi
0049501b pop ebx
0049501c add esp, 8
0049501f ret
00495020 sub esp, 0x118
00495026 push ebx
00495027 push ebp
00495028 mov ebp, dword ptr [esp + 0x124]
0049502f push esi
00495030 push edi
00495031 mov dword ptr [esp + 0x1c], 0
00495039 lea eax, [ebp + 0x33c]
0049503f mov dword ptr [esp + 0x24], 0
00495047 mov ecx, eax
00495049 mov dword ptr [esp + 0x28], 0
00495051 mov dword ptr [esp + 0x2c], 0
00495059 mov edx, dword ptr [ecx]
0049505b mov dword ptr [esp + 0x74], edx
0049505f mov edx, dword ptr [ecx + 4]
00495062 mov dword ptr [esp + 0x78], edx
00495066 lea edx, [esp + 0x74]
0049506a mov ecx, dword ptr [ecx + 8]
0049506d push edx
0049506e push 0x3d000000
00495073 push eax
00495074 push 1
00495076 mov dword ptr [esp + 0x8c], ecx
0049507d call 0x532360
00495082 lea esi, [ebp + 8]
00495085 mov ecx, 0xc
0049508a lea edi, [esp + 0x90]
00495091 lea eax, [esp + 0x6c]
00495095 rep movsd dword ptr es:[edi], dword ptr [esi]
00495097 mov ecx, dword ptr [ebp + 0x3b0]
0049509d lea esi, [ebp + 0x37c]
004950a3 push eax
004950a4 push ecx
004950a5 push esi
004950a6 push 1
004950a8 call 0x532360
004950ad mov eax, dword ptr [ebp + 0x3a8]
004950b3 lea edx, [esp + 0x64]
004950b7 push edx
004950b8 lea ecx, [ebp + 0x364]
004950be push eax
004950bf push ecx
004950c0 push 1
004950c2 call 0x532360
004950c7 fld dword ptr [ebp + 0x3ac]
004950cd add esp, 0x30
004950d0 lea edx, [esp + 0x68]
004950d4 fchs
004950d6 push edx
004950d7 push ecx
004950d8 lea eax, [ebp + 0x370]
004950de fstp dword ptr [esp]
004950e1 push eax
004950e2 push 1
004950e4 call 0x532360
004950e9 lea ecx, [esp + 0x44]
004950ed lea edx, [esp + 0x78]
004950f1 lea ebx, [ebp + 0x330]
004950f7 push ecx
004950f8 push edx
004950f9 push ebx
004950fa push 1
004950fc call 0x532300
00495101 lea eax, [esp + 0x30]
00495105 lea ecx, [esp + 0x7c]
00495109 push eax
0049510a lea edx, [esp + 0x58]
0049510e push ecx
0049510f push edx
00495110 push 1
00495112 call 0x532300
00495117 lea eax, [esp + 0xf8]
0049511e lea ecx, [esp + 0x74]
00495122 push eax
00495123 lea edx, [esp + 0x44]
00495127 push ecx
00495128 push edx
00495129 push 1
0049512b call 0x532330
00495130 add esp, 0x40
00495133 lea eax, [esp + 0xd4]
0049513a push eax
0049513b lea ecx, [esp + 0x48]
0049513f lea edx, [esp + 0x14]
00495143 push ecx
00495144 push edx
00495145 push 1
00495147 call 0x532300
0049514c lea eax, [esp + 0x20]
00495150 lea ecx, [esp + 0x6c]
00495154 push eax
00495155 lea edx, [esp + 0x48]
00495159 push ecx
0049515a push edx
0049515b push 1
0049515d call 0x532330
00495162 lea eax, [esp + 0x100]
00495169 lea ecx, [esp + 0x64]
0049516d push eax
0049516e lea edx, [esp + 0x34]
00495172 push ecx
00495173 push edx
00495174 push 1
00495176 call 0x532330
0049517b lea eax, [esp + 0x11c]
00495182 lea ecx, [esp + 0x74]
00495186 push eax
00495187 lea edx, [esp + 0x44]
0049518b push ecx
0049518c push edx
0049518d push 1
0049518f call 0x532300
00495194 fld dword ptr [ebp + 0x3b0]
0049519a fmul dword ptr [0x5b23f0]
004951a0 add esp, 0x40
004951a3 lea eax, [esp + 0x5c]
004951a7 push eax
004951a8 push ecx
004951a9 fstp dword ptr [esp]
004951ac push esi
004951ad push 1
004951af call 0x532360
004951b4 lea ecx, [esp + 0x44]
004951b8 lea edx, [esp + 0x78]
004951bc push ecx
004951bd push edx
004951be push ebx
004951bf push 1
004951c1 call 0x532330
004951c6 lea eax, [esp + 0x30]
004951ca lea ecx, [esp + 0x7c]
004951ce push eax
004951cf lea edx, [esp + 0x58]
004951d3 push ecx
004951d4 push edx
004951d5 push 1
004951d7 call 0x532300
004951dc lea eax, [esp + 0x128]
004951e3 lea ecx, [esp + 0x74]
004951e7 push eax
004951e8 lea edx, [esp + 0x44]
004951ec push ecx
004951ed push edx
004951ee push 1
004951f0 call 0x532330
004951f5 add esp, 0x40
004951f8 lea eax, [esp + 0x104]
004951ff lea ecx, [esp + 0x44]
00495203 lea edx, [esp + 0x10]
00495207 push eax
00495208 push ecx
00495209 push edx
0049520a push 1
0049520c call 0x532300
00495211 lea eax, [esp + 0x20]
00495215 lea ecx, [esp + 0x6c]
00495219 push eax
0049521a lea edx, [esp + 0x48]
0049521e push ecx
0049521f push edx
00495220 push 1
00495222 call 0x532330
00495227 lea eax, [esp + 0x130]
0049522e lea ecx, [esp + 0x64]
00495232 push eax
00495233 lea edx, [esp + 0x34]
00495237 push ecx
00495238 push edx
00495239 push 1
0049523b call 0x532330
00495240 lea eax, [esp + 0x14c]
00495247 lea ecx, [esp + 0x74]
0049524b push eax
0049524c lea edx, [esp + 0x44]
00495250 push ecx
00495251 push edx
00495252 push 1
00495254 call 0x532300
00495259 add esp, 0x40
0049525c lea esi, [esp + 0xc8]
00495263 mov dword ptr [esp + 0x40], 8
0049526b push 1
0049526d push esi
0049526e lea ecx, [esp + 0x88]
00495275 call 0x474060
0049527a test byte ptr [esp + 0xa4], 0xf
00495282 je 0x4952df
00495284 push 0
00495286 lea ecx, [esp + 0x84]
0049528d call 0x4745f0
00495292 lea ecx, [esp + 0x80]
00495299 mov edi, eax
0049529b call 0x474420
004952a0 fld dword ptr [esi]
004952a2 fsub dword ptr [edi]
004952a4 fmul dword ptr [eax]
004952a6 fchs
004952a8 fld dword ptr [esi + 8]
004952ab fsub dword ptr [edi + 8]
004952ae fmul dword ptr [eax + 8]
004952b1 fsubp st(1)
004952b3 fdiv dword ptr [eax + 4]
004952b6 fadd dword ptr [edi + 4]
004952b9 fsub dword ptr [ebp + 0x334]
004952bf fcom dword ptr [0x5b23f8]
004952c5 fnstsw ax
004952c7 test ah, 1
004952ca je 0x4952ce
004952cc fchs
004952ce fcomp dword ptr [0x5b2404]
004952d4 fnstsw ax
004952d6 test ah, 0x41
004952d9 jne 0x49556b
004952df mov eax, ebx
004952e1 push 1
004952e3 mov ecx, dword ptr [eax]
004952e5 mov dword ptr [esp + 0x14], ecx
004952e9 lea ecx, [esp + 0x14]
004952ed mov edx, dword ptr [eax + 4]
004952f0 push ecx
004952f1 lea ecx, [esp + 0x88]
004952f8 mov dword ptr [esp + 0x1c], edx
004952fc mov eax, dword ptr [eax + 8]
004952ff mov dword ptr [esp + 0x20], eax
00495303 call 0x474060
00495308 test byte ptr [esp + 0xa4], 0xf
00495310 je 0x49536c
00495312 push 0
00495314 lea ecx, [esp + 0x84]
0049531b call 0x4745f0
00495320 lea ecx, [esp + 0x80]
00495327 mov edi, eax
00495329 call 0x474420
0049532e fld dword ptr [esp + 0x10]
00495332 fsub dword ptr [edi]
00495334 fmul dword ptr [eax]
00495336 fchs
00495338 fld dword ptr [esp + 0x18]
0049533c fsub dword ptr [edi + 8]
0049533f fmul dword ptr [eax + 8]
00495342 fsubp st(1)
00495344 fdiv dword ptr [eax + 4]
00495347 fadd dword ptr [edi + 4]
0049534a fsub dword ptr [ebp + 0x334]
00495350 fcom dword ptr [0x5b23f8]
00495356 fnstsw ax
00495358 test ah, 1
0049535b je 0x49535f
0049535d fchs
0049535f fcomp dword ptr [0x5b2404]
00495365 fnstsw ax
00495367 test ah, 0x41
0049536a jne 0x495394
0049536c lea edx, [esp + 0x10]
00495370 lea eax, [esp + 0x74]
00495374 push edx
00495375 push eax
00495376 push ebx
00495377 push 1
00495379 call 0x532330
0049537e add esp, 0x10
00495381 lea ecx, [esp + 0x10]
00495385 push 1
00495387 push ecx
00495388 lea ecx, [esp + 0x88]
0049538f call 0x474060
00495394 mov edx, dword ptr [esp + 0x10]
00495398 mov eax, dword ptr [esp + 0x14]
0049539c mov ecx, dword ptr [esp + 0x18]
004953a0 mov dword ptr [esp + 0x44], edx
004953a4 mov edx, esi
004953a6 mov dword ptr [esp + 0x48], eax
004953aa mov dword ptr [esp + 0x4c], ecx
004953ae mov dword ptr [esp + 0x30], 0
004953b6 mov eax, dword ptr [edx]
004953b8 mov dword ptr [esp + 0x50], eax
004953bc mov al, byte ptr [esp + 0xa4]
004953c3 mov ecx, dword ptr [edx + 4]
004953c6 test al, 0xf
004953c8 mov edx, dword ptr [edx + 8]
004953cb mov dword ptr [esp + 0x54], ecx
004953cf mov dword ptr [esp + 0x58], edx
004953d3 je 0x4953f7
004953d5 lea eax, [esp + 0x30]
004953d9 lea ecx, [esp + 0xb0]
004953e0 push eax
004953e1 lea edx, [esp + 0x48]
004953e5 push ecx
004953e6 push edx
004953e7 lea ecx, [esp + 0x8c]
004953ee call 0x4740d0
004953f3 test al, al
004953f5 jne 0x495415
004953f7 lea eax, [esp + 0x30]
004953fb lea ecx, [esp + 0xb0]
00495402 push eax
00495403 lea edx, [esp + 0x48]
00495407 push ecx
00495408 push edx
00495409 lea ecx, [esp + 0x8c]
00495410 call 0x4740d0
00495415 mov ecx, dword ptr [esp + 0x30]
00495419 and ecx, 0xffff
0049541f test al, al
00495421 mov dword ptr [0x628c88], ecx
00495427 je 0x49556b
0049542d lea edx, [esp + 0x68]
00495431 lea eax, [esp + 0xb0]
00495438 push edx
00495439 lea ecx, [esp + 0xc0]
00495440 push eax
00495441 push ecx
00495442 push 1
00495444 call 0x532330
00495449 fld dword ptr [esp + 0x80]
00495450 mov edx, dword ptr [esp + 0x78]
00495454 lea eax, [esp + 0x6c]
00495458 lea ecx, [esp + 0xc0]
0049545f push eax
00495460 fchs
00495462 fstp dword ptr [esp + 0x38]
00495466 push ecx
00495467 push esi
00495468 mov dword ptr [esp + 0x48], edx
0049546c mov dword ptr [esp + 0x44], 0
00495474 call 0x489f10
00495479 lea edx, [esp + 0x50]
0049547d lea eax, [esp + 0x78]
00495481 push edx
00495482 push esi
00495483 push eax
00495484 push 1
00495486 call 0x532330
0049548b lea ecx, [esp + 0x60]
0049548f lea edx, [esp + 0x60]
00495493 push ecx
00495494 push 0x3f8147ae
00495499 push edx
0049549a push 1
0049549c mov dword ptr [esp + 0x74], 0
004954a4 call 0x532360
004954a9 fld dword ptr [esp + 0x60]
004954ad fcomp dword ptr [0x5b23f8]
004954b3 add esp, 0x3c
004954b6 fnstsw ax
004954b8 test ah, 0x40
004954bb je 0x4954df
004954bd fld dword ptr [esp + 0x28]
004954c1 fcomp dword ptr [0x5b23f8]
004954c7 fnstsw ax
004954c9 test ah, 0x40
004954cc je 0x4954df
004954ce fld dword ptr [esp + 0x2c]
004954d2 fcomp dword ptr [0x5b23f8]
004954d8 fnstsw ax
004954da test ah, 0x40
004954dd jne 0x4954f1
004954df lea eax, [esp + 0x24]
004954e3 lea ecx, [esp + 0x24]
004954e7 push eax
004954e8 push ecx
004954e9 call 0x5328d0
004954ee add esp, 8
004954f1 lea edx, [esp + 0x34]
004954f5 push 1
004954f7 push edx
004954f8 lea eax, [esp + 0x2c]
004954fc push esi
004954fd push eax
004954fe push ebp
004954ff call 0x494000
00495504 mov edx, esi
00495506 lea ecx, [ebp + 0x440]
0049550c fstp dword ptr [esp + 0x34]
00495510 mov eax, dword ptr [edx]
00495512 push ebp
00495513 mov dword ptr [ecx], eax
00495515 mov eax, dword ptr [edx + 4]
00495518 mov dword ptr [ecx + 4], eax
0049551b mov edx, dword ptr [edx + 8]
0049551e mov dword ptr [ecx + 8], edx
00495521 call 0x40a630
00495526 fld dword ptr [esp + 0x38]
0049552a fcomp dword ptr [esp + 0x34]
0049552e add esp, 0x18
00495531 fnstsw ax
00495533 test ah, 0x41
00495536 jne 0x495540
00495538 mov eax, dword ptr [esp + 0x20]
0049553c mov dword ptr [esp + 0x1c], eax
00495540 fld dword ptr [esp + 0x20]
00495544 fcomp dword ptr [0x5b2470]
0049554a fnstsw ax
0049554c test ah, 0x41
0049554f jne 0x49556b
00495551 mov ecx, dword ptr [esp + 0x20]
00495555 lea edx, [esp + 0x24]
00495559 push 1
0049555b push edx
0049555c push ebp
0049555d mov dword ptr [ebp + 0x430], ecx
00495563 call 0x494df0
00495568 add esp, 0xc
0049556b mov eax, dword ptr [esp + 0x40]
0049556f add esi, 0xc
00495572 dec eax
00495573 mov dword ptr [esp + 0x40], eax
00495577 jne 0x49526b
0049557d fld dword ptr [ebp + 0x430]
00495583 fcom dword ptr [esp + 0x1c]
00495587 fnstsw ax
00495589 test ah, 0x41
0049558c je 0x495594
0049558e fstp st(0)
00495590 fld dword ptr [esp + 0x1c]
00495594 fstp dword ptr [ebp + 0x430]
0049559a lea ecx, [esp + 0x80]
004955a1 call 0x516950
004955a6 pop edi
004955a7 pop esi
004955a8 pop ebp
004955a9 pop ebx
004955aa add esp, 0x118
004955b0 ret
004955b1 nop
004955b2 nop
004955b3 nop
004955b4 nop
004955b5 nop
004955b6 nop
004955b7 nop
004955b8 nop
004955b9 nop
004955ba nop
004955bb nop
004955bc nop
004955bd nop
004955be nop
004955bf nop
004955c0 push ecx
004955c1 mov dword ptr [esp], 0x800000
004955c9 mov eax, dword ptr [esp]
004955cd mov dword ptr [0x628efc], eax
004955d2 pop ecx
004955d3 ret
004955d4 nop
004955d5 nop
004955d6 nop
004955d7 nop
004955d8 nop
004955d9 nop
004955da nop
004955db nop
004955dc nop
004955dd nop
004955de nop
004955df nop
004955e0 fld dword ptr [0x5b24a8]
004955e6 fdiv dword ptr [0x628efc]
004955ec fstp dword ptr [0x628cb8]
004955f2 ret
004955f3 nop
004955f4 nop
004955f5 nop
004955f6 nop
004955f7 nop
004955f8 nop
004955f9 nop
004955fa nop
004955fb nop
004955fc nop
004955fd nop
004955fe nop
004955ff nop
00495600 fld dword ptr [0x628f2c]
00495606 fmul dword ptr [esp + 4]
0049560a fld dword ptr [0x628f30]
00495610 fmul dword ptr [esp + 8]
00495614 mov ecx, dword ptr [0x628cbc]
0049561a faddp st(1)
0049561c fld dword ptr [0x628f34]
00495622 fmul dword ptr [esp + 0xc]
00495626 faddp st(1)
00495628 fadd dword ptr [0x628cc4]
0049562e fstp dword ptr [0x628f50]
00495634 fld dword ptr [0x628f38]
0049563a fmul dword ptr [esp + 4]
0049563e fld dword ptr [0x628f3c]
00495644 fmul dword ptr [esp + 8]
00495648 faddp st(1)
0049564a fld dword ptr [0x628f40]
00495650 fmul dword ptr [esp + 0xc]
00495654 faddp st(1)
00495656 fadd dword ptr [0x628cc8]
0049565c fstp dword ptr [0x628f54]
00495662 fld dword ptr [0x628f44]
00495668 fmul dword ptr [esp + 4]
0049566c fld dword ptr [0x628f48]
00495672 fmul dword ptr [esp + 8]
00495676 faddp st(1)
00495678 fld dword ptr [0x628f4c]
0049567e fmul dword ptr [esp + 0xc]
00495682 faddp st(1)
00495684 fadd dword ptr [0x628ccc]
0049568a fstp dword ptr [0x628cb0]
00495690 fld dword ptr [0x628cb0]
00495696 fcomp dword ptr [ecx + 0x3b0]
0049569c fnstsw ax
0049569e test ah, 0x41
004956a1 je 0x49588a
004956a7 fld dword ptr [ecx + 0x3b0]
004956ad fchs
004956af fcomp dword ptr [0x628cb0]
004956b5 fnstsw ax
004956b7 test ah, 0x41
004956ba je 0x49588a
004956c0 fld dword ptr [0x628f50]
004956c6 fcomp dword ptr [ecx + 0x3a8]
004956cc fnstsw ax
004956ce test ah, 0x41
004956d1 je 0x49588a
004956d7 fld dword ptr [ecx + 0x3a8]
004956dd fchs
004956df fcomp dword ptr [0x628f50]
004956e5 fnstsw ax
004956e7 test ah, 0x41
004956ea je 0x49588a
004956f0 fld dword ptr [0x628f54]
004956f6 fcomp dword ptr [ecx + 0x3ac]
004956fc fnstsw ax
004956fe test ah, 0x41
00495701 je 0x49588a
00495707 fld dword ptr [ecx + 0x3ac]
0049570d fchs
0049570f fcomp dword ptr [0x628f54]
00495715 fnstsw ax
00495717 test ah, 0x41
0049571a je 0x49588a
00495720 mov eax, dword ptr [0x628cc0]
00495725 fld dword ptr [esp + 4]
00495729 fmul dword ptr [eax + 0x364]
0049572f fld dword ptr [esp + 8]
00495733 fmul dword ptr [eax + 0x370]
00495739 faddp st(1)
0049573b fld dword ptr [esp + 0xc]
0049573f fmul dword ptr [eax + 0x37c]
00495745 mov eax, dword ptr [0x628cb4]
0049574a faddp st(1)
0049574c fstp dword ptr [eax]
0049574e mov eax, dword ptr [0x628cc0]
00495753 mov ecx, dword ptr [0x628cb4]
00495759 fld dword ptr [esp + 4]
0049575d fmul dword ptr [eax + 0x368]
00495763 fld dword ptr [esp + 8]
00495767 fmul dword ptr [eax + 0x374]
0049576d faddp st(1)
0049576f fld dword ptr [esp + 0xc]
00495773 fmul dword ptr [eax + 0x380]
00495779 faddp st(1)
0049577b fstp dword ptr [ecx + 4]
0049577e mov eax, dword ptr [0x628cc0]
00495783 mov edx, dword ptr [0x628cb4]
00495789 fld dword ptr [esp + 4]
0049578d fmul dword ptr [eax + 0x36c]
00495793 fld dword ptr [esp + 8]
00495797 fmul dword ptr [eax + 0x378]
0049579d faddp st(1)
0049579f fld dword ptr [esp + 0xc]
004957a3 fmul dword ptr [eax + 0x384]
004957a9 faddp st(1)
004957ab fstp dword ptr [edx + 8]
004957ae mov eax, dword ptr [0x628cc0]
004957b3 fld dword ptr [eax + 0x3a8]
004957b9 fmul dword ptr [eax + 0x364]
004957bf fmul dword ptr [esp + 4]
004957c3 fld dword ptr [eax + 0x3ac]
004957c9 fmul dword ptr [eax + 0x370]
004957cf fmul dword ptr [esp + 8]
004957d3 faddp st(1)
004957d5 fld dword ptr [eax + 0x3b0]
004957db fmul dword ptr [eax + 0x37c]
004957e1 fmul dword ptr [esp + 0xc]
004957e5 faddp st(1)
004957e7 fadd dword ptr [eax + 0x330]
004957ed mov eax, dword ptr [0x628f04]
004957f2 fstp dword ptr [eax]
004957f4 mov eax, dword ptr [0x628cc0]
004957f9 mov ecx, dword ptr [0x628f04]
004957ff fld dword ptr [eax + 0x3a8]
00495805 fmul dword ptr [eax + 0x368]
0049580b fmul dword ptr [esp + 4]
0049580f fld dword ptr [eax + 0x3ac]
00495815 fmul dword ptr [eax + 0x374]
0049581b fmul dword ptr [esp + 8]
0049581f faddp st(1)
00495821 fld dword ptr [eax + 0x3b0]
00495827 fmul dword ptr [eax + 0x380]
0049582d fmul dword ptr [esp + 0xc]
00495831 faddp st(1)
00495833 fadd dword ptr [eax + 0x334]
00495839 fstp dword ptr [ecx + 4]
0049583c mov eax, dword ptr [0x628cc0]
00495841 fld dword ptr [eax + 0x3a8]
00495847 fmul dword ptr [eax + 0x36c]
0049584d fmul dword ptr [esp + 4]
00495851 fld dword ptr [eax + 0x3ac]
00495857 fmul dword ptr [eax + 0x378]
0049585d fmul dword ptr [esp + 8]
00495861 faddp st(1)
00495863 fld dword ptr [eax + 0x3b0]
00495869 fmul dword ptr [eax + 0x384]
0049586f fmul dword ptr [esp + 0xc]
00495873 mov edx, dword ptr [0x628f04]
00495879 faddp st(1)
0049587b fadd dword ptr [eax + 0x338]
00495881 mov eax, 1
00495886 fstp dword ptr [edx + 8]
00495889 ret
0049588a xor eax, eax
0049588c ret
0049588d nop
0049588e nop
0049588f nop
00495890 fld dword ptr [0x628c8c]
00495896 fmul dword ptr [esp + 4]
0049589a fld dword ptr [0x628c98]
004958a0 fmul dword ptr [esp + 8]
004958a4 mov ecx, dword ptr [0x628cc0]
004958aa faddp st(1)
004958ac fld dword ptr [0x628ca4]
004958b2 fmul dword ptr [esp + 0xc]
004958b6 faddp st(1)
004958b8 fsub dword ptr [0x628cd0]
004958be fstp dword ptr [0x628f50]
004958c4 fld dword ptr [0x628c90]
004958ca fmul dword ptr [esp + 4]
004958ce fld dword ptr [0x628c9c]
004958d4 fmul dword ptr [esp + 8]
004958d8 faddp st(1)
004958da fld dword ptr [0x628ca8]
004958e0 fmul dword ptr [esp + 0xc]
004958e4 faddp st(1)
004958e6 fsub dword ptr [0x628cd4]
004958ec fstp dword ptr [0x628f54]
004958f2 fld dword ptr [0x628c94]
004958f8 fmul dword ptr [esp + 4]
004958fc fld dword ptr [0x628ca0]
00495902 fmul dword ptr [esp + 8]
00495906 faddp st(1)
00495908 fld dword ptr [0x628cac]
0049590e fmul dword ptr [esp + 0xc]
00495912 faddp st(1)
00495914 fsub dword ptr [0x628cd8]
0049591a fstp dword ptr [0x628cb0]
00495920 fld dword ptr [0x628cb0]
00495926 fcomp dword ptr [ecx + 0x3b0]
0049592c fnstsw ax
0049592e test ah, 0x41
00495931 je 0x495b20
00495937 fld dword ptr [ecx + 0x3b0]
0049593d fchs
0049593f fcomp dword ptr [0x628cb0]
00495945 fnstsw ax
00495947 test ah, 0x41
0049594a je 0x495b20
00495950 fld dword ptr [0x628f50]
00495956 fcomp dword ptr [ecx + 0x3a8]
0049595c fnstsw ax
0049595e test ah, 0x41
00495961 je 0x495b20
00495967 fld dword ptr [ecx + 0x3a8]
0049596d fchs
0049596f fcomp dword ptr [0x628f50]
00495975 fnstsw ax
00495977 test ah, 0x41
0049597a je 0x495b20
00495980 fld dword ptr [0x628f54]
00495986 fcomp dword ptr [ecx + 0x3ac]
0049598c fnstsw ax
0049598e test ah, 0x41
00495991 je 0x495b20
00495997 fld dword ptr [ecx + 0x3ac]
0049599d fchs
0049599f fcomp dword ptr [0x628f54]
004959a5 fnstsw ax
004959a7 test ah, 0x41
004959aa je 0x495b20
004959b0 mov eax, dword ptr [0x628cbc]
004959b5 fld dword ptr [esp + 4]
004959b9 fmul dword ptr [eax + 0x364]
004959bf fld dword ptr [esp + 8]
004959c3 fmul dword ptr [eax + 0x370]
004959c9 faddp st(1)
004959cb fld dword ptr [esp + 0xc]
004959cf fmul dword ptr [eax + 0x37c]
004959d5 mov eax, dword ptr [0x628cb4]
004959da faddp st(1)
004959dc fchs
004959de fstp dword ptr [eax]
004959e0 mov eax, dword ptr [0x628cbc]
004959e5 mov ecx, dword ptr [0x628cb4]
004959eb fld dword ptr [esp + 4]
004959ef fmul dword ptr [eax + 0x368]
004959f5 fld dword ptr [esp + 8]
004959f9 fmul dword ptr [eax + 0x374]
004959ff faddp st(1)
00495a01 fld dword ptr [esp + 0xc]
00495a05 fmul dword ptr [eax + 0x380]
00495a0b faddp st(1)
00495a0d fchs
00495a0f fstp dword ptr [ecx + 4]
00495a12 mov eax, dword ptr [0x628cbc]
00495a17 mov edx, dword ptr [0x628cb4]
00495a1d fld dword ptr [esp + 4]
00495a21 fmul dword ptr [eax + 0x36c]
00495a27 fld dword ptr [esp + 8]
00495a2b fmul dword ptr [eax + 0x378]
00495a31 faddp st(1)
00495a33 fld dword ptr [esp + 0xc]
00495a37 fmul dword ptr [eax + 0x384]
00495a3d faddp st(1)
00495a3f fchs
00495a41 fstp dword ptr [edx + 8]
00495a44 mov eax, dword ptr [0x628cbc]
00495a49 fld dword ptr [eax + 0x3a8]
00495a4f fmul dword ptr [eax + 0x364]
00495a55 fmul dword ptr [esp + 4]
00495a59 fld dword ptr [eax + 0x3ac]
00495a5f fmul dword ptr [eax + 0x370]
00495a65 fmul dword ptr [esp + 8]
00495a69 faddp st(1)
00495a6b fld dword ptr [eax + 0x3b0]
00495a71 fmul dword ptr [eax + 0x37c]
00495a77 fmul dword ptr [esp + 0xc]
00495a7b faddp st(1)
00495a7d fadd dword ptr [eax + 0x330]
00495a83 mov eax, dword ptr [0x628f04]
00495a88 fstp dword ptr [eax]
00495a8a mov eax, dword ptr [0x628cbc]
00495a8f mov ecx, dword ptr [0x628f04]
00495a95 fld dword ptr [eax + 0x3a8]
00495a9b fmul dword ptr [eax + 0x368]
00495aa1 fmul dword ptr [esp + 4]
00495aa5 fld dword ptr [eax + 0x3ac]
00495aab fmul dword ptr [eax + 0x374]
00495ab1 fmul dword ptr [esp + 8]
00495ab5 faddp st(1)
00495ab7 fld dword ptr [eax + 0x3b0]
00495abd fmul dword ptr [eax + 0x380]
00495ac3 fmul dword ptr [esp + 0xc]
00495ac7 faddp st(1)
00495ac9 fadd dword ptr [eax + 0x334]
00495acf fstp dword ptr [ecx + 4]
00495ad2 mov eax, dword ptr [0x628cbc]
00495ad7 fld dword ptr [eax + 0x3a8]
00495add fmul dword ptr [eax + 0x36c]
00495ae3 fmul dword ptr [esp + 4]
00495ae7 fld dword ptr [eax + 0x3ac]
00495aed fmul dword ptr [eax + 0x378]
00495af3 mov edx, dword ptr [0x628f04]
00495af9 fmul dword ptr [esp + 8]
00495afd faddp st(1)
00495aff fld dword ptr [eax + 0x3b0]
00495b05 fmul dword ptr [eax + 0x384]
00495b0b fmul dword ptr [esp + 0xc]
00495b0f faddp st(1)
00495b11 fadd dword ptr [eax + 0x338]
00495b17 mov eax, 1
00495b1c fstp dword ptr [edx + 8]
00495b1f ret
00495b20 xor eax, eax
00495b22 ret
00495b23 nop
00495b24 nop
00495b25 nop
00495b26 nop
00495b27 nop
00495b28 nop
00495b29 nop
00495b2a nop
00495b2b nop
00495b2c nop
00495b2d nop
00495b2e nop
00495b2f nop
00495b30 fld dword ptr [0x628f2c]
00495b36 fmul dword ptr [esp + 4]
00495b3a fld dword ptr [0x628f30]
00495b40 fmul dword ptr [esp + 8]
00495b44 mov ecx, dword ptr [0x628cbc]
00495b4a faddp st(1)
00495b4c fld dword ptr [0x628f34]
00495b52 fmul dword ptr [esp + 0xc]
00495b56 faddp st(1)
00495b58 fadd dword ptr [0x628cc4]
00495b5e fstp dword ptr [0x628f50]
00495b64 fld dword ptr [0x628f38]
00495b6a fmul dword ptr [esp + 4]
00495b6e fld dword ptr [0x628f3c]
00495b74 fmul dword ptr [esp + 8]
00495b78 faddp st(1)
00495b7a fld dword ptr [0x628f40]
00495b80 fmul dword ptr [esp + 0xc]
00495b84 faddp st(1)
00495b86 fadd dword ptr [0x628cc8]
00495b8c fstp dword ptr [0x628f54]
00495b92 fld dword ptr [0x628f44]
00495b98 fmul dword ptr [esp + 4]
00495b9c fld dword ptr [0x628f48]
00495ba2 fmul dword ptr [esp + 8]
00495ba6 faddp st(1)
00495ba8 fld dword ptr [0x628f4c]
00495bae fmul dword ptr [esp + 0xc]
00495bb2 faddp st(1)
00495bb4 fadd dword ptr [0x628ccc]
00495bba fstp dword ptr [0x628cb0]
00495bc0 fld dword ptr [0x628cb0]
00495bc6 fcomp dword ptr [ecx + 0x3b0]
00495bcc fnstsw ax
00495bce test ah, 0x41
00495bd1 je 0x495d2c
00495bd7 fld dword ptr [ecx + 0x3b0]
00495bdd fchs
00495bdf fcomp dword ptr [0x628cb0]
00495be5 fnstsw ax
00495be7 test ah, 0x41
00495bea je 0x495d2c
00495bf0 fld dword ptr [0x628f50]
00495bf6 fcomp dword ptr [ecx + 0x3a8]
00495bfc fnstsw ax
00495bfe test ah, 0x41
00495c01 je 0x495d2c
00495c07 fld dword ptr [ecx + 0x3a8]
00495c0d fchs
00495c0f fcomp dword ptr [0x628f50]
00495c15 fnstsw ax
00495c17 test ah, 0x41
00495c1a je 0x495d2c
00495c20 fld dword ptr [0x628f54]
00495c26 fcomp dword ptr [ecx + 0x3ac]
00495c2c fnstsw ax
00495c2e test ah, 0x41
00495c31 je 0x495d2c
00495c37 fld dword ptr [ecx + 0x3ac]
00495c3d fchs
00495c3f fcomp dword ptr [0x628f54]
00495c45 fnstsw ax
00495c47 test ah, 0x41
00495c4a je 0x495d2c
00495c50 mov eax, dword ptr [0x628cc0]
00495c55 fld dword ptr [eax + 0x3a8]
00495c5b fmul dword ptr [eax + 0x364]
00495c61 fmul dword ptr [esp + 4]
00495c65 fld dword ptr [eax + 0x3ac]
00495c6b fmul dword ptr [eax + 0x370]
00495c71 fmul dword ptr [esp + 8]
00495c75 faddp st(1)
00495c77 fld dword ptr [eax + 0x3b0]
00495c7d fmul dword ptr [eax + 0x37c]
00495c83 fmul dword ptr [esp + 0xc]
00495c87 faddp st(1)
00495c89 fadd dword ptr [eax + 0x330]
00495c8f mov eax, dword ptr [0x628f04]
00495c94 fstp dword ptr [eax]
00495c96 mov eax, dword ptr [0x628cc0]
00495c9b mov ecx, dword ptr [0x628f04]
00495ca1 fld dword ptr [eax + 0x3a8]
00495ca7 fmul dword ptr [eax + 0x368]
00495cad fmul dword ptr [esp + 4]
00495cb1 fld dword ptr [eax + 0x3ac]
00495cb7 fmul dword ptr [eax + 0x374]
00495cbd fmul dword ptr [esp + 8]
00495cc1 faddp st(1)
00495cc3 fld dword ptr [eax + 0x3b0]
00495cc9 fmul dword ptr [eax + 0x380]
00495ccf fmul dword ptr [esp + 0xc]
00495cd3 faddp st(1)
00495cd5 fadd dword ptr [eax + 0x334]
00495cdb fstp dword ptr [ecx + 4]
00495cde mov eax, dword ptr [0x628cc0]
00495ce3 mov edx, dword ptr [0x628f04]
00495ce9 fld dword ptr [eax + 0x3a8]
00495cef fmul dword ptr [eax + 0x36c]
00495cf5 fmul dword ptr [esp + 4]
00495cf9 fld dword ptr [eax + 0x3ac]
00495cff fmul dword ptr [eax + 0x378]
00495d05 fmul dword ptr [esp + 8]
00495d09 faddp st(1)
00495d0b fld dword ptr [eax + 0x3b0]
00495d11 fmul dword ptr [eax + 0x384]
00495d17 fmul dword ptr [esp + 0xc]
00495d1b faddp st(1)
00495d1d fadd dword ptr [eax + 0x338]
00495d23 mov eax, 1
00495d28 fstp dword ptr [edx + 8]
00495d2b ret
00495d2c xor eax, eax
00495d2e ret
00495d2f nop
00495d30 fld dword ptr [0x628c8c]
00495d36 fmul dword ptr [esp + 4]
00495d3a fld dword ptr [0x628c98]
00495d40 fmul dword ptr [esp + 8]
00495d44 mov ecx, dword ptr [0x628cc0]
00495d4a faddp st(1)
00495d4c fld dword ptr [0x628ca4]
00495d52 fmul dword ptr [esp + 0xc]
00495d56 faddp st(1)
00495d58 fsub dword ptr [0x628cd0]
00495d5e fstp dword ptr [0x628f50]
00495d64 fld dword ptr [0x628c90]
00495d6a fmul dword ptr [esp + 4]
00495d6e fld dword ptr [0x628c9c]
00495d74 fmul dword ptr [esp + 8]
00495d78 faddp st(1)
00495d7a fld dword ptr [0x628ca8]
00495d80 fmul dword ptr [esp + 0xc]
00495d84 faddp st(1)
00495d86 fsub dword ptr [0x628cd4]
00495d8c fstp dword ptr [0x628f54]
00495d92 fld dword ptr [0x628c94]
00495d98 fmul dword ptr [esp + 4]
00495d9c fld dword ptr [0x628ca0]
00495da2 fmul dword ptr [esp + 8]
00495da6 faddp st(1)
00495da8 fld dword ptr [0x628cac]
00495dae fmul dword ptr [esp + 0xc]
00495db2 faddp st(1)
00495db4 fsub dword ptr [0x628cd8]
00495dba fstp dword ptr [0x628cb0]
00495dc0 fld dword ptr [0x628cb0]
00495dc6 fcomp dword ptr [ecx + 0x3b0]
00495dcc fnstsw ax
00495dce test ah, 0x41
00495dd1 je 0x495f2c
00495dd7 fld dword ptr [ecx + 0x3b0]
00495ddd fchs
00495ddf fcomp dword ptr [0x628cb0]
00495de5 fnstsw ax
00495de7 test ah, 0x41
00495dea je 0x495f2c
00495df0 fld dword ptr [0x628f50]
00495df6 fcomp dword ptr [ecx + 0x3a8]
00495dfc fnstsw ax
00495dfe test ah, 0x41
00495e01 je 0x495f2c
00495e07 fld dword ptr [ecx + 0x3a8]
00495e0d fchs
00495e0f fcomp dword ptr [0x628f50]
00495e15 fnstsw ax
00495e17 test ah, 0x41
00495e1a je 0x495f2c
00495e20 fld dword ptr [0x628f54]
00495e26 fcomp dword ptr [ecx + 0x3ac]
00495e2c fnstsw ax
00495e2e test ah, 0x41
00495e31 je 0x495f2c
00495e37 fld dword ptr [ecx + 0x3ac]
00495e3d fchs
00495e3f fcomp dword ptr [0x628f54]
00495e45 fnstsw ax
00495e47 test ah, 0x41
00495e4a je 0x495f2c
00495e50 mov eax, dword ptr [0x628cbc]
00495e55 fld dword ptr [eax + 0x3a8]
00495e5b fmul dword ptr [eax + 0x364]
00495e61 fmul dword ptr [esp + 4]
00495e65 fld dword ptr [eax + 0x3ac]
00495e6b fmul dword ptr [eax + 0x370]
00495e71 fmul dword ptr [esp + 8]
00495e75 faddp st(1)
00495e77 fld dword ptr [eax + 0x3b0]
00495e7d fmul dword ptr [eax + 0x37c]
00495e83 fmul dword ptr [esp + 0xc]
00495e87 faddp st(1)
00495e89 fadd dword ptr [eax + 0x330]
00495e8f mov eax, dword ptr [0x628f04]
00495e94 fstp dword ptr [eax]
00495e96 mov eax, dword ptr [0x628cbc]
00495e9b mov ecx, dword ptr [0x628f04]
00495ea1 fld dword ptr [eax + 0x3a8]
00495ea7 fmul dword ptr [eax + 0x368]
00495ead fmul dword ptr [esp + 4]
00495eb1 fld dword ptr [eax + 0x3ac]
00495eb7 fmul dword ptr [eax + 0x374]
00495ebd fmul dword ptr [esp + 8]
00495ec1 faddp st(1)
00495ec3 fld dword ptr [eax + 0x3b0]
00495ec9 fmul dword ptr [eax + 0x380]
00495ecf fmul dword ptr [esp + 0xc]
00495ed3 faddp st(1)
00495ed5 fadd dword ptr [eax + 0x334]
00495edb fstp dword ptr [ecx + 4]
00495ede mov eax, dword ptr [0x628cbc]
00495ee3 mov edx, dword ptr [0x628f04]
00495ee9 fld dword ptr [eax + 0x3a8]
00495eef fmul dword ptr [eax + 0x36c]
00495ef5 fmul dword ptr [esp + 4]
00495ef9 fld dword ptr [eax + 0x3ac]
00495eff fmul dword ptr [eax + 0x378]
00495f05 fmul dword ptr [esp + 8]
00495f09 faddp st(1)
00495f0b fld dword ptr [eax + 0x3b0]
00495f11 fmul dword ptr [eax + 0x384]
00495f17 fmul dword ptr [esp + 0xc]
00495f1b faddp st(1)
00495f1d fadd dword ptr [eax + 0x338]
00495f23 mov eax, 1
00495f28 fstp dword ptr [edx + 8]
00495f2b ret
00495f2c xor eax, eax
00495f2e ret
00495f2f nop
00495f30 sub esp, 0x64
00495f33 mov eax, dword ptr [esp + 0x70]
00495f37 push ebx
00495f38 push ebp
00495f39 push esi
00495f3a mov ecx, dword ptr [eax]
00495f3c mov esi, dword ptr [esp + 0x74]
00495f40 mov dword ptr [esp + 0x10], ecx
00495f44 mov ecx, dword ptr [esp + 0x80]
00495f4b mov edx, dword ptr [eax + 4]
00495f4e lea ebp, [esi + 0x33c]
00495f54 mov dword ptr [esp + 0x14], edx
00495f58 mov edx, dword ptr [ecx]
00495f5a mov eax, dword ptr [eax + 8]
00495f5d mov dword ptr [esp + 0x1c], edx
00495f61 mov dword ptr [esp + 0x18], eax
00495f65 mov eax, dword ptr [ecx + 4]
00495f68 push edi
00495f69 lea edx, [esp + 0x20]
00495f6d mov ecx, dword ptr [ecx + 8]
00495f70 push ebp
00495f71 push edx
00495f72 mov dword ptr [esp + 0x18], 0
00495f7a mov dword ptr [esp + 0x2c], eax
00495f7e mov dword ptr [esp + 0x30], ecx
00495f82 call 0x532910
00495f87 mov ebx, dword ptr [esp + 0x84]
00495f8e lea eax, [esp + 0x58]
00495f92 fstp dword ptr [esp + 0x8c]
00495f99 lea ecx, [esi + 0x330]
00495f9f push eax
00495fa0 push ecx
00495fa1 push ebx
00495fa2 push 1
00495fa4 call 0x532330
00495fa9 lea edx, [esp + 0x80]
00495fb0 lea eax, [esp + 0x38]
00495fb4 push edx
00495fb5 lea ecx, [esp + 0x6c]
00495fb9 push eax
00495fba push ecx
00495fbb call 0x532880
00495fc0 lea edx, [esp + 0x8c]
00495fc7 lea edi, [esi + 0x388]
00495fcd push edx
00495fce push edi
00495fcf call 0x532910
00495fd4 fld dword ptr [esi + 0x358]
00495fda fmul dword ptr [0x5b23f0]
00495fe0 lea eax, [esp + 0x94]
00495fe7 push eax
00495fe8 fmul dword ptr [0x5b23f0]
00495fee fstp dword ptr [esp + 0xb0]
00495ff5 fadd dword ptr [esp + 0xb4]
00495ffc fstp dword ptr [esp + 0xa8]
00496003 call 0x532b20
00496008 fld dword ptr [esi + 0x398]
0049600e fadd st(0), st(0)
00496010 mov al, byte ptr [esi + 0x52c]
00496016 add esp, 0x30
00496019 test al, 0x80
0049601b fmulp st(1)
0049601d fmul dword ptr [0x5b23f0]
00496023 fadd dword ptr [esp + 0x80]
0049602a fdivr dword ptr [esp + 0x78]
0049602e fchs
00496030 je 0x4960ac
00496032 mov ecx, dword ptr [esi + 0x3ac]
00496038 fld dword ptr [esi + 0x3a8]
0049603e mov dword ptr [esp + 0x80], ecx
00496045 fcom dword ptr [esp + 0x80]
0049604c fnstsw ax
0049604e test ah, 0x41
00496051 je 0x49605c
00496053 fstp st(0)
00496055 fld dword ptr [esp + 0x80]
0049605c mov edx, dword ptr [esi + 0x3b0]
00496062 mov dword ptr [esp + 0x80], edx
00496069 fcom dword ptr [esp + 0x80]
00496070 fnstsw ax
00496072 test ah, 0x41
00496075 je 0x496080
00496077 fstp st(0)
00496079 fld dword ptr [esp + 0x80]
00496080 fcom dword ptr [0x5b246c]
00496086 fnstsw ax
00496088 test ah, 0x41
0049608b jne 0x4960a2
0049608d fxch st(1)
0049608f fmul dword ptr [0x5b49b8]
00496095 fdiv st(1)
00496097 fstp dword ptr [esp + 0x80]
0049609e fstp st(0)
004960a0 jmp 0x4960b9
004960a2 fstp st(0)
004960a4 fmul dword ptr [0x5b261c]
004960aa jmp 0x4960b2
004960ac fmul dword ptr [0x5b25f0]
004960b2 fstp dword ptr [esp + 0x80]
004960b9 fld dword ptr [esp + 0x84]
004960c0 fcomp dword ptr [0x5b23f8]
004960c6 fld dword ptr [esp + 0x84]
004960cd fnstsw ax
004960cf test ah, 1
004960d2 je 0x4960d6
004960d4 fchs
004960d6 mov eax, dword ptr [esi + 0x464]
004960dc mov dword ptr [esi + 0x434], 0
004960e6 fstp dword ptr [esi + 0x430]
004960ec fld dword ptr [esp + 0x88]
004960f3 fcomp dword ptr [0x5b23f8]
004960f9 or eax, 0x30000
004960fe lea ecx, [esi + 0x440]
00496104 mov dword ptr [esi + 0x438], eax
0049610a mov edx, dword ptr [ebx]
0049610c mov dword ptr [ecx], edx
0049610e mov eax, dword ptr [ebx + 4]
00496111 mov dword ptr [ecx + 4], eax
00496114 mov edx, dword ptr [ebx + 8]
00496117 fnstsw ax
00496119 mov dword ptr [ecx + 8], edx
0049611c test ah, 0x41
0049611f jne 0x496303
00496125 fld dword ptr [esp + 0x14]
00496129 fcomp dword ptr [0x5b23f8]
0049612f fnstsw ax
00496131 test ah, 0x40
00496134 je 0x49615c
00496136 fld dword ptr [esp + 0x18]
0049613a fcomp dword ptr [0x5b23f8]
00496140 fnstsw ax
00496142 test ah, 0x40
00496145 je 0x49615c
00496147 fld dword ptr [esp + 0x1c]
0049614b fcomp dword ptr [0x5b23f8]
00496151 fnstsw ax
00496153 test ah, 0x40
00496156 jne 0x496201
0049615c lea eax, [esp + 0x20]
00496160 lea ecx, [esp + 0x14]
00496164 push eax
00496165 push ecx
00496166 call 0x532910
0049616b fld dword ptr [esp + 0x28]
0049616f fmul st(1)
00496171 lea edx, [esp + 0x1c]
00496175 lea eax, [esp + 0x1c]
00496179 push edx
0049617a push eax
0049617b fsubr dword ptr [esp + 0x24]
0049617f fstp dword ptr [esp + 0x24]
00496183 fld dword ptr [esp + 0x34]
00496187 fmul st(1)
00496189 fsubr dword ptr [esp + 0x28]
0049618d fstp dword ptr [esp + 0x28]
00496191 fld dword ptr [esp + 0x38]
00496195 fmul st(1)
00496197 fsubr dword ptr [esp + 0x2c]
0049619b fstp dword ptr [esp + 0x2c]
0049619f fstp st(0)
004961a1 call 0x532910
004961a6 fstp dword ptr [esp + 0xc]
004961aa add esp, 0xc
004961ad call 0x5327d0
004961b2 fst dword ptr [esp + 0x14]
004961b6 fcomp dword ptr [0x5b27a8]
004961bc add esp, 4
004961bf fnstsw ax
004961c1 test ah, 0x41
004961c4 jne 0x4961e8
004961c6 fld dword ptr [esp + 0x10]
004961ca fmul dword ptr [0x5b23f0]
004961d0 lea ecx, [esp + 0x14]
004961d4 lea edx, [esp + 0x14]
004961d8 push ecx
004961d9 push ecx
004961da fdivr dword ptr [0x5b23f0]
004961e0 fchs
004961e2 fstp dword ptr [esp]
004961e5 push edx
004961e6 jmp 0x4961f7
004961e8 lea eax, [esp + 0x14]
004961ec lea ecx, [esp + 0x14]
004961f0 push eax
004961f1 push 0xbf800000
004961f6 push ecx
004961f7 push 1
004961f9 call 0x532360
004961fe add esp, 0x10
00496201 fld dword ptr [esp + 0x80]
00496208 fmul dword ptr [esp + 0x88]
0049620f lea edx, [esp + 0x5c]
00496213 lea eax, [esp + 0x14]
00496217 push edx
00496218 push ecx
00496219 fstp dword ptr [esp + 0x90]
00496220 fld dword ptr [esp + 0x90]
00496227 fmul dword ptr [esi + 0x358]
0049622d fmul dword ptr [0x5b23f0]
00496233 fstp dword ptr [esp]
00496236 push eax
00496237 push 1
00496239 call 0x532360
0049623e fld dword ptr [esp + 0x98]
00496245 fmul dword ptr [esi + 0x398]
0049624b lea ecx, [esp + 0x3c]
0049624f lea edx, [esp + 0x60]
00496253 push ecx
00496254 lea eax, [esp + 0x28]
00496258 fadd st(0), st(0)
0049625a push edx
0049625b push eax
0049625c fstp dword ptr [esp + 0xa0]
00496263 call 0x532880
00496268 lea ecx, [esp + 0x48]
0049626c lea edx, [esp + 0x6c]
00496270 push ecx
00496271 lea eax, [esp + 0x4c]
00496275 push edx
00496276 push eax
00496277 call 0x532880
0049627c mov edx, dword ptr [esp + 0xac]
00496283 lea ecx, [esp + 0x54]
00496287 push ecx
00496288 lea eax, [esp + 0x58]
0049628c push edx
0049628d push eax
0049628e push 1
00496290 call 0x532360
00496295 lea ecx, [esp + 0x94]
0049629c lea edx, [esp + 0x64]
004962a0 push ecx
004962a1 lea eax, [esp + 0x98]
004962a8 push edx
004962a9 push eax
004962aa push 1
004962ac call 0x532300
004962b1 add esp, 0x48
004962b4 lea ecx, [esp + 0x14]
004962b8 lea edx, [esp + 0x5c]
004962bc push ecx
004962bd push edx
004962be call 0x532910
004962c3 fcom dword ptr [esp + 0x18]
004962c7 add esp, 8
004962ca fnstsw ax
004962cc test ah, 0x41
004962cf jne 0x4962e5
004962d1 fld dword ptr [esp + 0x10]
004962d5 fdiv st(1)
004962d7 fmul dword ptr [esp + 0x88]
004962de fstp dword ptr [esp + 0x88]
004962e5 mov ecx, dword ptr [esp + 0x88]
004962ec lea eax, [esp + 0x14]
004962f0 push eax
004962f1 lea edx, [esp + 0x18]
004962f5 push ecx
004962f6 push edx
004962f7 push 1
004962f9 fstp st(0)
004962fb call 0x532360
00496300 add esp, 0x10
00496303 fld dword ptr [esp + 0x80]
0049630a fcomp dword ptr [0x5b27b4]
00496310 fnstsw ax
00496312 test ah, 1
00496315 je 0x49633e
00496317 push edi
00496318 push 0x3f666666
0049631d push edi
0049631e push 1
00496320 call 0x532360
00496325 push ebp
00496326 push 0x3f666666
0049632b push ebp
0049632c push 1
0049632e call 0x532360
00496333 add esp, 0x20
00496336 pop edi
00496337 pop esi
00496338 pop ebp
00496339 pop ebx
0049633a add esp, 0x64
0049633d ret
0049633e mov ecx, dword ptr [esp + 0x80]
00496345 lea eax, [esp + 0x44]
00496349 push eax
0049634a lea edx, [esp + 0x24]
0049634e push ecx
0049634f push edx
00496350 push 1
00496352 call 0x532360
00496357 lea eax, [esp + 0x54]
0049635b lea ecx, [esp + 0x24]
0049635f push eax
00496360 lea edx, [esp + 0x58]
00496364 push ecx
00496365 push edx
00496366 push 1
00496368 call 0x532300
0049636d fld dword ptr [esi + 0x358]
00496373 fmul dword ptr [0x5b23f0]
00496379 add esp, 0x20
0049637c lea eax, [esp + 0x38]
00496380 push eax
00496381 push ecx
00496382 lea ecx, [esp + 0x4c]
00496386 fstp dword ptr [esp]
00496389 push ecx
0049638a push 1
0049638c call 0x532360
00496391 lea edx, [esp + 0x48]
00496395 push ebp
00496396 push edx
00496397 push ebp
00496398 push 1
0049639a call 0x532300
0049639f lea eax, [esp + 0x58]
004963a3 lea ecx, [esp + 0x64]
004963a7 push eax
004963a8 lea edx, [esp + 0x74]
004963ac push ecx
004963ad push edx
004963ae call 0x532880
004963b3 fld dword ptr [esi + 0x398]
004963b9 add esp, 0x2c
004963bc lea eax, [esp + 0x38]
004963c0 fadd st(0), st(0)
004963c2 push eax
004963c3 push ecx
004963c4 lea ecx, [esp + 0x40]
004963c8 fstp dword ptr [esp]
004963cb push ecx
004963cc push 1
004963ce call 0x532360
004963d3 lea edx, [esp + 0x48]
004963d7 push edi
004963d8 push edx
004963d9 push edi
004963da push 1
004963dc call 0x532300
004963e1 mov al, byte ptr [esi + 0x52c]
004963e7 add esp, 0x20
004963ea test al, 0x80
004963ec jne 0x496405
004963ee fld dword ptr [esi + 0x3a0]
004963f4 fcomp dword ptr [0x5b23f4]
004963fa fnstsw ax
004963fc test ah, 1
004963ff je 0x4964c3
00496405 fld dword ptr [esi + 0x428]
0049640b fcomp dword ptr [0x5b2738]
00496411 fnstsw ax
00496413 test ah, 1
00496416 je 0x4964c3
0049641c fld dword ptr [esp + 0x80]
00496423 fcomp dword ptr [0x5b241c]
00496429 fnstsw ax
0049642b test ah, 1
0049642e je 0x4964c3
00496434 fld dword ptr [edi]
00496436 fcomp dword ptr [0x5b23f8]
0049643c fld dword ptr [edi]
0049643e fnstsw ax
00496440 test ah, 1
00496443 je 0x496447
00496445 fchs
00496447 fcomp dword ptr [0x5b24a8]
0049644d fnstsw ax
0049644f test ah, 1
00496452 je 0x4964c3
00496454 fld dword ptr [esi + 0x38c]
0049645a fcomp dword ptr [0x5b23f8]
00496460 fld dword ptr [esi + 0x38c]
00496466 fnstsw ax
00496468 test ah, 1
0049646b je 0x49646f
0049646d fchs
0049646f fcomp dword ptr [0x5b24a8]
00496475 fnstsw ax
00496477 test ah, 1
0049647a je 0x4964c3
0049647c fld dword ptr [esi + 0x390]
00496482 fcomp dword ptr [0x5b23f8]
00496488 fld dword ptr [esi + 0x390]
0049648e fnstsw ax
00496490 test ah, 1
00496493 je 0x496497
00496495 fchs
00496497 fcomp dword ptr [0x5b24a8]
0049649d fnstsw ax
0049649f test ah, 1
004964a2 je 0x4964c3
004964a4 push edi
004964a5 push 0x3f400000
004964aa push edi
004964ab push 1
004964ad call 0x532360
004964b2 push ebp
004964b3 push 0x3f733333
004964b8 push ebp
004964b9 push 1
004964bb call 0x532360
004964c0 add esp, 0x20
004964c3 pop edi
004964c4 pop esi
004964c5 pop ebp
004964c6 pop ebx
004964c7 add esp, 0x64
004964ca ret
004964cb nop
004964cc nop
004964cd nop
004964ce nop
004964cf nop
004964d0 mov ecx, dword ptr [esp + 4]
004964d4 fld dword ptr [0x5b260c]
004964da mov eax, dword ptr [ecx + 0x558]
004964e0 mov edx, dword ptr [eax + 0x518]
004964e6 test edx, edx
004964e8 je 0x4964f4
004964ea fstp st(0)
004964ec fld dword ptr [0x5b49c0]
004964f2 jmp 0x496518
004964f4 test byte ptr [ecx + 0x52c], 0x80
004964fb je 0x496518
004964fd fld dword ptr [ecx + 0x354]
00496503 fcomp dword ptr [0x5b260c]
00496509 fnstsw ax
0049650b test ah, 1
0049650e je 0x496518
00496510 fstp st(0)
00496512 fld dword ptr [0x5b49bc]
00496518 fld dword ptr [ecx + 0x388]
0049651e fcomp dword ptr [0x5b23f8]
00496524 fnstsw ax
00496526 test ah, 1
00496529 je 0x49654a
0049652b fld st(0)
0049652d fchs
0049652f fld dword ptr [ecx + 0x388]
00496535 fst dword ptr [esp + 4]
00496539 fcomp st(1)
0049653b fnstsw ax
0049653d test ah, 0x41
00496540 jne 0x49655d
00496542 fstp st(0)
00496544 fld dword ptr [esp + 4]
00496548 jmp 0x49655d
0049654a fld dword ptr [ecx + 0x388]
00496550 fcom st(1)
00496552 fnstsw ax
00496554 test ah, 0x41
00496557 jne 0x49655d
00496559 fstp st(0)
0049655b fld st(0)
0049655d fstp dword ptr [ecx + 0x388]
00496563 fld dword ptr [ecx + 0x38c]
00496569 fcomp dword ptr [0x5b23f8]
0049656f fnstsw ax
00496571 test ah, 1
00496574 je 0x496595
00496576 fld st(0)
00496578 fchs
0049657a fld dword ptr [ecx + 0x38c]
00496580 fst dword ptr [esp + 4]
00496584 fcomp st(1)
00496586 fnstsw ax
00496588 test ah, 0x41
0049658b jne 0x4965a8
0049658d fstp st(0)
0049658f fld dword ptr [esp + 4]
00496593 jmp 0x4965a8
00496595 fld dword ptr [ecx + 0x38c]
0049659b fcom st(1)
0049659d fnstsw ax
0049659f test ah, 0x41
004965a2 jne 0x4965a8
004965a4 fstp st(0)
004965a6 fld st(0)
004965a8 fstp dword ptr [ecx + 0x38c]
004965ae fld dword ptr [ecx + 0x390]
004965b4 fcomp dword ptr [0x5b23f8]
004965ba fnstsw ax
004965bc test ah, 1
004965bf je 0x4965e3
004965c1 fchs
004965c3 fld dword ptr [ecx + 0x390]
004965c9 fst dword ptr [esp + 4]
004965cd fcomp st(1)
004965cf fnstsw ax
004965d1 test ah, 0x41
004965d4 jne 0x4965fc
004965d6 fstp st(0)
004965d8 fld dword ptr [esp + 4]
004965dc fstp dword ptr [ecx + 0x390]
004965e2 ret
004965e3 fld dword ptr [ecx + 0x390]
004965e9 fst dword ptr [esp + 4]
004965ed fcomp st(1)
004965ef fnstsw ax
004965f1 test ah, 0x41
004965f4 je 0x4965fc
004965f6 fstp st(0)
004965f8 fld dword ptr [esp + 4]
004965fc fstp dword ptr [ecx + 0x390]
00496602 ret
00496603 nop
00496604 nop
00496605 nop
00496606 nop
00496607 nop
00496608 nop
00496609 nop
0049660a nop
0049660b nop
0049660c nop
0049660d nop
0049660e nop
0049660f nop
00496610 sub esp, 0x38
00496613 push ebx
00496614 push ebp
00496615 push esi
00496616 mov esi, dword ptr [esp + 0x48]
0049661a xor ebx, ebx
0049661c push edi
0049661d mov eax, dword ptr [esi + 0x32c]
00496623 mov dword ptr [esp + 0x10], 0xbf800000
0049662b test eax, eax
0049662d mov dword ptr [esp + 0x14], 0
00496635 mov dword ptr [esp + 0x18], 0
0049663d mov dword ptr [esp + 0x1c], 0
00496645 mov dword ptr [esp + 0x20], 0
0049664d jle 0x496852
00496653 mov ebp, dword ptr [esp + 0x50]
00496657 lea edi, [esi + 0x1dc]
0049665d mov ecx, dword ptr [esp + 0x54]
00496661 lea eax, [esp + 0x30]
00496665 push eax
00496666 push ecx
00496667 push edi
00496668 push 1
0049666a call 0x532330
0049666f lea edx, [esp + 0x40]
00496673 push ebp
00496674 push edx
00496675 call 0x532910
0049667a fchs
0049667c fcom dword ptr [0x5b49c4]
00496682 add esp, 0x18
00496685 fnstsw ax
00496687 test ah, 0x41
0049668a jne 0x4966cf
0049668c fld dword ptr [esp + 0x14]
00496690 fadd dword ptr [0x5b24a8]
00496696 fstp dword ptr [esp + 0x14]
0049669a fcom dword ptr [esp + 0x10]
0049669e fnstsw ax
004966a0 test ah, 0x41
004966a3 jne 0x4966ab
004966a5 fstp dword ptr [esp + 0x10]
004966a9 jmp 0x4966ad
004966ab fstp st(0)
004966ad fld dword ptr [esp + 0x18]
004966b1 fadd dword ptr [edi]
004966b3 fstp dword ptr [esp + 0x18]
004966b7 fld dword ptr [esp + 0x1c]
004966bb fadd dword ptr [edi + 4]
004966be fstp dword ptr [esp + 0x1c]
004966c2 fld dword ptr [esp + 0x20]
004966c6 fadd dword ptr [edi + 8]
004966c9 fstp dword ptr [esp + 0x20]
004966cd jmp 0x4966d1
004966cf fstp st(0)
004966d1 mov eax, dword ptr [esi + 0x32c]
004966d7 inc ebx
004966d8 add edi, 0xc
004966db cmp ebx, eax
004966dd jl 0x49665d
004966e3 fld dword ptr [esp + 0x14]
004966e7 fcomp dword ptr [0x5b23f8]
004966ed fnstsw ax
004966ef test ah, 0x41
004966f2 jne 0x496852
004966f8 fld dword ptr [esp + 0x10]
004966fc fcomp dword ptr [0x5b23f8]
00496702 fnstsw ax
00496704 test ah, 1
00496707 je 0x496711
00496709 mov dword ptr [esp + 0x10], 0
00496711 fld dword ptr [0x5b24a8]
00496717 fdiv dword ptr [esp + 0x14]
0049671b lea eax, [esp + 0x18]
0049671f push eax
00496720 push ecx
00496721 lea ecx, [esp + 0x20]
00496725 fstp dword ptr [esp]
00496728 push ecx
00496729 push 1
0049672b call 0x532360
00496730 lea edi, [esi + 0x388]
00496736 push edi
00496737 push 0x40c90fd0
0049673c push edi
0049673d push 1
0049673f call 0x532360
00496744 lea edx, [esp + 0x5c]
00496748 lea ebx, [esi + 0x330]
0049674e push edx
0049674f lea eax, [esp + 0x3c]
00496753 push ebx
00496754 push eax
00496755 push 1
00496757 call 0x532330
0049675c lea ecx, [esp + 0x54]
00496760 lea edx, [esp + 0x6c]
00496764 push ecx
00496765 push edx
00496766 push edi
00496767 call 0x532880
0049676c lea ecx, [esp + 0x60]
00496770 lea eax, [esi + 0x33c]
00496776 push ecx
00496777 lea edx, [esp + 0x64]
0049677b push eax
0049677c push edx
0049677d push 1
0049677f call 0x532300
00496784 mov eax, dword ptr [esp + 0xa4]
0049678b add esp, 0x4c
0049678e lea ecx, [esp + 0x24]
00496792 lea edx, [esp + 0x18]
00496796 push eax
00496797 push ebp
00496798 push ecx
00496799 push edx
0049679a push esi
0049679b call 0x495f30
004967a0 mov ecx, dword ptr [esp + 0x24]
004967a4 lea eax, [esp + 0x44]
004967a8 push eax
004967a9 push ecx
004967aa push ebp
004967ab push 1
004967ad call 0x532360
004967b2 lea edx, [esp + 0x54]
004967b6 push ebx
004967b7 push edx
004967b8 push ebx
004967b9 push 1
004967bb call 0x532300
004967c0 add esp, 0x34
004967c3 lea ebx, [esi + 0x7f8]
004967c9 mov dword ptr [esp + 0x4c], 4
004967d1 lea eax, [esp + 0x30]
004967d5 push ebx
004967d6 push eax
004967d7 push ebx
004967d8 push 1
004967da call 0x532300
004967df mov eax, dword ptr [esp + 0x5c]
004967e3 add esp, 0x10
004967e6 add ebx, 0xc4
004967ec dec eax
004967ed mov dword ptr [esp + 0x4c], eax
004967f1 jne 0x4967d1
004967f3 push edi
004967f4 push 0x3e22f987
004967f9 push edi
004967fa push 1
004967fc call 0x532360
00496801 push esi
00496802 call 0x4964d0
00496807 lea edi, [esi + 0x33c]
0049680d push edi
0049680e push ebp
0049680f call 0x532910
00496814 fcomp dword ptr [0x5b23f8]
0049681a add esp, 0x1c
0049681d push edi
0049681e push ebp
0049681f fnstsw ax
00496821 test ah, 1
00496824 je 0x496832
00496826 call 0x532910
0049682b add esp, 8
0049682e fchs
00496830 jmp 0x49683a
00496832 call 0x532910
00496837 add esp, 8
0049683a fmul dword ptr [0x5b2404]
00496840 push 0
00496842 push ebp
00496843 push esi
00496844 fstp dword ptr [esi + 0x430]
0049684a call 0x494df0
0049684f add esp, 0xc
00496852 pop edi
00496853 pop esi
00496854 pop ebp
00496855 pop ebx
00496856 add esp, 0x38
00496859 ret
0049685a nop
0049685b nop
0049685c nop
0049685d nop
0049685e nop
0049685f nop
00496860 sub esp, 0x60
00496863 push ebx
00496864 mov ebx, dword ptr [esp + 0x70]
00496868 push ebp
00496869 push esi
0049686a mov esi, dword ptr [esp + 0x70]
0049686e lea ecx, [esp + 0x48]
00496872 push edi
00496873 push ecx
00496874 lea eax, [esi + 0x330]
0049687a push eax
0049687b push ebx
0049687c push 1
0049687e call 0x532330
00496883 mov edi, dword ptr [esp + 0x88]
0049688a lea edx, [esp + 0x68]
0049688e push edx
0049688f lea eax, [edi + 0x330]
00496895 push eax
00496896 push ebx
00496897 push 1
00496899 call 0x532330
0049689e mov ebp, dword ptr [esp + 0xa0]
004968a5 lea eax, [esp + 0x54]
004968a9 push eax
004968aa lea ecx, [esp + 0x70]
004968ae push ebp
004968af push ecx
004968b0 call 0x532880
004968b5 lea edx, [esp + 0x6c]
004968b9 lea eax, [esp + 0x84]
004968c0 push edx
004968c1 push ebp
004968c2 push eax
004968c3 call 0x532880
004968c8 lea eax, [edi + 0x33c]
004968ce push ebp
004968cf push eax
004968d0 lea ebx, [esi + 0x33c]
004968d6 call 0x532910
004968db fstp dword ptr [esp + 0xb4]
004968e2 add esp, 0x40
004968e5 push ebp
004968e6 push ebx
004968e7 call 0x532910
004968ec fsubr dword ptr [esp + 0x7c]
004968f0 lea ecx, [esp + 0x3c]
004968f4 lea eax, [esi + 0x388]
004968fa push ecx
004968fb push eax
004968fc fstp dword ptr [esp + 0x84]
00496903 call 0x532910
00496908 fsubr dword ptr [esp + 0x84]
0049690f lea edx, [esp + 0x50]
00496913 lea eax, [edi + 0x388]
00496919 push edx
0049691a push eax
0049691b fstp dword ptr [esp + 0x8c]
00496922 call 0x532910
00496927 fadd dword ptr [esp + 0x8c]
0049692e lea eax, [esp + 0x4c]
00496932 lea ecx, [esp + 0x4c]
00496936 push eax
00496937 push ecx
00496938 fstp dword ptr [esp + 0x9c]
0049693f call 0x532910
00496944 fmul dword ptr [esi + 0x398]
0049694a lea edx, [esp + 0x60]
0049694e lea eax, [esp + 0x60]
00496952 push edx
00496953 push eax
00496954 fmul dword ptr [0x5b23f0]
0049695a fstp dword ptr [esp + 0x9c]
00496961 call 0x532910
00496966 fmul dword ptr [edi + 0x398]
0049696c add esp, 0x28
0049696f fmul dword ptr [0x5b23f0]
00496975 fadd dword ptr [esp + 0x74]
00496979 fld dword ptr [edi + 0x358]
0049697f fmul dword ptr [0x5b23f0]
00496985 test byte ptr [esi + 0x52c], 0x80
0049698c faddp st(1)
0049698e fld dword ptr [esi + 0x358]
00496994 fmul dword ptr [0x5b23f0]
0049699a faddp st(1)
0049699c fdivr dword ptr [esp + 0x7c]
004969a0 je 0x4969bc
004969a2 mov al, byte ptr [esi + 0x7c]
004969a5 test al, al
004969a7 jne 0x4969bc
004969a9 fcom dword ptr [0x5b23f8]
004969af fnstsw ax
004969b1 test ah, 1
004969b4 je 0x4969b8
004969b6 fchs
004969b8 mov byte ptr [esi + 0x7c], 1
004969bc test byte ptr [edi + 0x52c], 0x80
004969c3 je 0x4969df
004969c5 mov al, byte ptr [edi + 0x7c]
004969c8 test al, al
004969ca jne 0x4969df
004969cc fcom dword ptr [0x5b23f8]
004969d2 fnstsw ax
004969d4 test ah, 1
004969d7 je 0x4969db
004969d9 fchs
004969db mov byte ptr [edi + 0x7c], 1
004969df fcom dword ptr [0x5b23f8]
004969e5 fnstsw ax
004969e7 test ah, 1
004969ea je 0x4969f8
004969ec pop edi
004969ed pop esi
004969ee pop ebp
004969ef xor eax, eax
004969f1 fstp st(0)
004969f3 pop ebx
004969f4 add esp, 0x60
004969f7 ret
004969f8 mov cl, byte ptr [esi + 0x52c]
004969fe mov eax, 0x10
00496a03 test cl, 0x80
00496a06 je 0x496a1a
00496a08 cmp dword ptr [esi + 0x44c], eax
00496a0e jne 0x496a1a
00496a10 mov dword ptr [esi + 0x42c], 1
00496a1a test byte ptr [edi + 0x52c], 0x80
00496a21 je 0x496a35
00496a23 cmp dword ptr [edi + 0x44c], eax
00496a29 jne 0x496a35
00496a2b mov dword ptr [edi + 0x42c], 1
00496a35 fmul dword ptr [0x5b23f0]
00496a3b mov eax, dword ptr [0x657408]
00496a40 test eax, eax
00496a42 fstp dword ptr [esp + 0x74]
00496a46 je 0x496a6a
00496a48 mov eax, dword ptr [esi + 0xdac]
00496a4e test eax, eax
00496a50 jne 0x496a5c
00496a52 mov eax, dword ptr [edi + 0xdac]
00496a58 test eax, eax
00496a5a je 0x496a6a
00496a5c fld dword ptr [esp + 0x74]
00496a60 fmul dword ptr [0x5b2694]
00496a66 fstp dword ptr [esp + 0x74]
00496a6a mov edx, dword ptr [esp + 0x74]
00496a6e lea ecx, [esp + 0x28]
00496a72 push ecx
00496a73 push edx
00496a74 push ebp
00496a75 push 1
00496a77 call 0x532360
00496a7c push ebp
00496a7d push ebx
00496a7e call 0x532910
00496a83 fstp dword ptr [esp + 0x8c]
00496a8a lea eax, [edi + 0x33c]
00496a90 push ebp
00496a91 push eax
00496a92 call 0x532910
00496a97 fsubr dword ptr [esp + 0x94]
00496a9e fld dword ptr [edi + 0x354]
00496aa4 fadd dword ptr [esi + 0x354]
00496aaa lea eax, [esp + 0x84]
00496ab1 push eax
00496ab2 lea eax, [edi + 0x33c]
00496ab8 fmulp st(1)
00496aba push eax
00496abb push ebx
00496abc push 1
00496abe fstp dword ptr [esp + 0xac]
00496ac5 call 0x532330
00496aca lea ecx, [esp + 0x94]
00496ad1 push ecx
00496ad2 call 0x532b20
00496ad7 fmul dword ptr [0x5b2404]
00496add mov al, byte ptr [esi + 0x52c]
00496ae3 add esp, 0x34
00496ae6 test al, 0x80
00496ae8 mov ecx, 0x41100000
00496aed fstp dword ptr [esp + 0x74]
00496af1 je 0x496b4a
00496af3 fld dword ptr [esi + 0x354]
00496af9 fcomp dword ptr [0x5b2600]
00496aff fnstsw ax
00496b01 test ah, 1
00496b04 je 0x496b4a
00496b06 fld dword ptr [esp + 0x7c]
00496b0a fmul dword ptr [esi + 0x358]
00496b10 fcom dword ptr [0x5b23f8]
00496b16 fnstsw ax
00496b18 test ah, 1
00496b1b je 0x496b1f
00496b1d fchs
00496b1f fld dword ptr [0x5b2404]
00496b25 fsub dword ptr [esi + 0x354]
00496b2b fmul dword ptr [esp + 0x74]
00496b2f fst dword ptr [esp + 0x78]
00496b33 fcomp st(1)
00496b35 fnstsw ax
00496b37 test ah, 0x41
00496b3a je 0x496b42
00496b3c fstp st(0)
00496b3e fld dword ptr [esp + 0x78]
00496b42 fstp dword ptr [esi + 0x430]
00496b48 jmp 0x496b97
00496b4a fld dword ptr [edi + 0x354]
00496b50 fcomp dword ptr [0x5b26e4]
00496b56 fnstsw ax
00496b58 test ah, 0x41
00496b5b jne 0x496b91
00496b5d fld dword ptr [esp + 0x7c]
00496b61 fmul dword ptr [esi + 0x358]
00496b67 fcom dword ptr [0x5b23f8]
00496b6d fnstsw ax
00496b6f test ah, 1
00496b72 je 0x496b76
00496b74 fchs
00496b76 fld dword ptr [esp + 0x74]
00496b7a fcomp st(1)
00496b7c fnstsw ax
00496b7e test ah, 0x41
00496b81 je 0x496b89
00496b83 fstp st(0)
00496b85 fld dword ptr [esp + 0x74]
00496b89 fstp dword ptr [esi + 0x430]
00496b8f jmp 0x496b97
00496b91 mov dword ptr [esi + 0x430], ecx
00496b97 test byte ptr [edi + 0x52c], 0x80
00496b9e je 0x496bf7
00496ba0 fld dword ptr [edi + 0x354]
00496ba6 fcomp dword ptr [0x5b2600]
00496bac fnstsw ax
00496bae test ah, 1
00496bb1 je 0x496bf7
00496bb3 fld dword ptr [esp + 0x7c]
00496bb7 fmul dword ptr [edi + 0x358]
00496bbd fcom dword ptr [0x5b23f8]
00496bc3 fnstsw ax
00496bc5 test ah, 1
00496bc8 je 0x496bcc
00496bca fchs
00496bcc fld dword ptr [0x5b2404]
00496bd2 fsub dword ptr [esi + 0x354]
00496bd8 fmul dword ptr [esp + 0x74]
00496bdc fst dword ptr [esp + 0x74]
00496be0 fcomp st(1)
00496be2 fnstsw ax
00496be4 test ah, 0x41
00496be7 je 0x496bef
00496be9 fstp st(0)
00496beb fld dword ptr [esp + 0x74]
00496bef fstp dword ptr [edi + 0x430]
00496bf5 jmp 0x496c44
00496bf7 fld dword ptr [esi + 0x354]
00496bfd fcomp dword ptr [0x5b26e4]
00496c03 fnstsw ax
00496c05 test ah, 0x41
00496c08 jne 0x496c3e
00496c0a fld dword ptr [esp + 0x7c]
00496c0e fmul dword ptr [edi + 0x358]
00496c14 fcom dword ptr [0x5b23f8]
00496c1a fnstsw ax
00496c1c test ah, 1
00496c1f je 0x496c23
00496c21 fchs
00496c23 fld dword ptr [esp + 0x74]
00496c27 fcomp st(1)
00496c29 fnstsw ax
00496c2b test ah, 0x41
00496c2e je 0x496c36
00496c30 fstp st(0)
00496c32 fld dword ptr [esp + 0x74]
00496c36 fstp dword ptr [edi + 0x430]
00496c3c jmp 0x496c44
00496c3e mov dword ptr [edi + 0x430], ecx
00496c44 fld dword ptr [esi + 0x430]
00496c4a fcomp dword ptr [0x5b26d4]
00496c50 lea edx, [esp + 0x1c]
00496c54 push edx
00496c55 fnstsw ax
00496c57 test ah, 1
00496c5a je 0x496c6a
00496c5c mov eax, dword ptr [esi + 0x358]
00496c62 lea ecx, [esp + 0x2c]
00496c66 push eax
00496c67 push ecx
00496c68 jmp 0x496c7f
00496c6a fld dword ptr [esi + 0x358]
00496c70 fmul dword ptr [0x5b3f64]
00496c76 push ecx
00496c77 lea eax, [esp + 0x30]
00496c7b fstp dword ptr [esp]
00496c7e push eax
00496c7f push 1
00496c81 call 0x532360
00496c86 add esp, 0x10
00496c89 lea ecx, [esp + 0x1c]
00496c8d push ebx
00496c8e push ecx
00496c8f push ebx
00496c90 push 1
00496c92 call 0x532300
00496c97 mov al, byte ptr [edi + 0x52c]
00496c9d add esp, 0x10
00496ca0 test al, 0x80
00496ca2 mov ebx, 0x50003
00496ca7 je 0x496cbd
00496ca9 mov edx, dword ptr [edi + 0x44c]
00496caf or edx, 0x50000
00496cb5 mov dword ptr [esi + 0x438], edx
00496cbb jmp 0x496cc3
00496cbd mov dword ptr [esi + 0x438], ebx
00496cc3 fld dword ptr [esi + 0x330]
00496cc9 mov dword ptr [esi + 0x434], edi
00496ccf fsub dword ptr [edi + 0x330]
00496cd5 fstp dword ptr [esp + 0x10]
00496cd9 fld dword ptr [esi + 0x334]
00496cdf fsub dword ptr [edi + 0x334]
00496ce5 fstp dword ptr [esp + 0x14]
00496ce9 fld dword ptr [esi + 0x338]
00496cef fsub dword ptr [edi + 0x338]
00496cf5 fstp dword ptr [esp + 0x18]
00496cf9 fld dword ptr [ebp]
00496cfc fcomp dword ptr [0x5b23f8]
00496d02 fnstsw ax
00496d04 test ah, 0x40
00496d07 je 0x496d43
00496d09 fld dword ptr [ebp + 4]
00496d0c fcomp dword ptr [0x5b23f8]
00496d12 fnstsw ax
00496d14 test ah, 0x40
00496d17 je 0x496d43
00496d19 fld dword ptr [ebp + 8]
00496d1c fcomp dword ptr [0x5b23f8]
00496d22 fnstsw ax
00496d24 test ah, 0x40
00496d27 je 0x496d43
00496d29 mov dword ptr [esp + 0x10], 0
00496d31 mov dword ptr [esp + 0x14], 0x3f800000
00496d39 mov dword ptr [esp + 0x18], 0
00496d41 jmp 0x496d55
00496d43 lea eax, [esp + 0x10]
00496d47 lea ecx, [esp + 0x10]
00496d4b push eax
00496d4c push ecx
00496d4d call 0x5328d0
00496d52 add esp, 8
00496d55 fld dword ptr [edi + 0x430]
00496d5b fcomp dword ptr [0x5b26d4]
00496d61 lea edx, [esp + 0x1c]
00496d65 push edx
00496d66 fnstsw ax
00496d68 test ah, 1
00496d6b je 0x496d7b
00496d6d mov eax, dword ptr [edi + 0x358]
00496d73 lea ecx, [esp + 0x2c]
00496d77 push eax
00496d78 push ecx
00496d79 jmp 0x496d90
00496d7b fld dword ptr [edi + 0x358]
00496d81 fmul dword ptr [0x5b3f64]
00496d87 push ecx
00496d88 lea eax, [esp + 0x30]
00496d8c fstp dword ptr [esp]
00496d8f push eax
00496d90 push 1
00496d92 call 0x532360
00496d97 add esp, 0x10
00496d9a lea eax, [edi + 0x33c]
00496da0 lea ecx, [esp + 0x1c]
00496da4 push eax
00496da5 push ecx
00496da6 push eax
00496da7 push 1
00496da9 call 0x532330
00496dae mov al, byte ptr [esi + 0x52c]
00496db4 add esp, 0x10
00496db7 test al, 0x80
00496db9 je 0x496dcf
00496dbb mov edx, dword ptr [esi + 0x44c]
00496dc1 or edx, 0x50000
00496dc7 mov dword ptr [edi + 0x438], edx
00496dcd jmp 0x496dd5
00496dcf mov dword ptr [edi + 0x438], ebx
00496dd5 mov dword ptr [edi + 0x434], esi
00496ddb mov al, byte ptr [esi + 0x52c]
00496de1 test al, 0x80
00496de3 je 0x496e0a
00496de5 fld dword ptr [esi + 0x354]
00496deb fcomp dword ptr [0x5b260c]
00496df1 fnstsw ax
00496df3 test ah, 1
00496df6 je 0x496e0a
00496df8 fld dword ptr [0x5b246c]
00496dfe fdiv dword ptr [esi + 0x354]
00496e04 fstp dword ptr [esp + 0x74]
00496e08 jmp 0x496e2d
00496e0a fld dword ptr [esi + 0x430]
00496e10 fcomp dword ptr [0x5b26d4]
00496e16 mov dword ptr [esp + 0x74], 0x40400000
00496e1e fnstsw ax
00496e20 test ah, 0x41
00496e23 je 0x496e2d
00496e25 mov dword ptr [esp + 0x74], 0x3fc00000
00496e2d lea eax, [esp + 0x1c]
00496e31 lea ecx, [esp + 0x28]
00496e35 push eax
00496e36 lea edx, [esp + 0x50]
00496e3a push ecx
00496e3b push edx
00496e3c call 0x532880
00496e41 fld dword ptr [esp + 0x80]
00496e48 fmul dword ptr [esi + 0x398]
00496e4e add esp, 0xc
00496e51 lea eax, [esp + 0x1c]
00496e55 push eax
00496e56 push ecx
00496e57 lea ecx, [esp + 0x24]
00496e5b fstp dword ptr [esp]
00496e5e push ecx
00496e5f push 1
00496e61 call 0x532360
00496e66 lea eax, [esi + 0x388]
00496e6c lea edx, [esp + 0x2c]
00496e70 push eax
00496e71 push edx
00496e72 push eax
00496e73 push 1
00496e75 call 0x532300
00496e7a mov al, byte ptr [edi + 0x52c]
00496e80 add esp, 0x20
00496e83 test al, 0x80
00496e85 je 0x496eac
00496e87 fld dword ptr [edi + 0x354]
00496e8d fcomp dword ptr [0x5b260c]
00496e93 fnstsw ax
00496e95 test ah, 1
00496e98 je 0x496eac
00496e9a fld dword ptr [0x5b246c]
00496ea0 fdiv dword ptr [edi + 0x354]
00496ea6 fstp dword ptr [esp + 0x74]
00496eaa jmp 0x496ecf
00496eac fld dword ptr [edi + 0x430]
00496eb2 fcomp dword ptr [0x5b26d4]
00496eb8 mov dword ptr [esp + 0x74], 0x40400000
00496ec0 fnstsw ax
00496ec2 test ah, 0x41
00496ec5 je 0x496ecf
00496ec7 mov dword ptr [esp + 0x74], 0x3fc00000
00496ecf lea eax, [esp + 0x1c]
00496ed3 lea ecx, [esp + 0x28]
00496ed7 push eax
00496ed8 lea edx, [esp + 0x5c]
00496edc push ecx
00496edd push edx
00496ede call 0x532880
00496ee3 fld dword ptr [esp + 0x80]
00496eea fmul dword ptr [edi + 0x398]
00496ef0 add esp, 0xc
00496ef3 lea eax, [esp + 0x1c]
00496ef7 push eax
00496ef8 push ecx
00496ef9 fchs
00496efb fstp dword ptr [esp]
00496efe lea ecx, [esp + 0x24]
00496f02 push ecx
00496f03 push 1
00496f05 call 0x532360
00496f0a lea eax, [edi + 0x388]
00496f10 lea edx, [esp + 0x2c]
00496f14 push eax
00496f15 push edx
00496f16 push eax
00496f17 push 1
00496f19 call 0x532300
00496f1e inc word ptr [esi + 0x418]
00496f25 inc word ptr [edi + 0x418]
00496f2c fld dword ptr [edi + 0x330]
00496f32 fadd dword ptr [esi + 0x330]
00496f38 lea eax, [esp + 0x30]
00496f3c push 2
00496f3e push eax
00496f3f push esi
00496f40 fmul dword ptr [0x5b23f0]
00496f46 fst dword ptr [edi + 0x440]
00496f4c fstp dword ptr [esi + 0x440]
00496f52 fld dword ptr [edi + 0x334]
00496f58 fadd dword ptr [esi + 0x334]
00496f5e fmul dword ptr [0x5b23f0]
00496f64 fst dword ptr [edi + 0x444]
00496f6a fstp dword ptr [esi + 0x444]
00496f70 fld dword ptr [edi + 0x338]
00496f76 fadd dword ptr [esi + 0x338]
00496f7c fmul dword ptr [0x5b23f0]
00496f82 fst dword ptr [edi + 0x448]
00496f88 fstp dword ptr [esi + 0x448]
00496f8e call 0x494df0
00496f93 fld dword ptr [esp + 0x3c]
00496f97 fchs
00496f99 fstp dword ptr [esp + 0x3c]
00496f9d fld dword ptr [esp + 0x40]
00496fa1 fchs
00496fa3 fstp dword ptr [esp + 0x40]
00496fa7 fld dword ptr [esp + 0x44]
00496fab lea ecx, [esp + 0x3c]
00496faf push 2
00496fb1 fchs
00496fb3 fstp dword ptr [esp + 0x48]
00496fb7 push ecx
00496fb8 push edi
00496fb9 call 0x494df0
00496fbe add esp, 0x38
00496fc1 mov eax, 1
00496fc6 pop edi
00496fc7 pop esi
00496fc8 pop ebp
00496fc9 pop ebx
00496fca add esp, 0x60
00496fcd ret
00496fce nop
00496fcf nop
00496fd0 mov eax, dword ptr [esp + 0xc]
00496fd4 sub esp, 0x30
00496fd7 mov dword ptr [0x628f04], eax
00496fdc push ebx
00496fdd mov ebx, dword ptr [esp + 0x3c]
00496fe1 push esi
00496fe2 mov esi, dword ptr [esp + 0x48]
00496fe6 push edi
00496fe7 mov edi, dword ptr [esp + 0x40]
00496feb push 0
00496fed push 0
00496fef push 0x3f800000
00496ff4 mov dword ptr [0x628cbc], edi
00496ffa mov dword ptr [0x628cc0], ebx
00497000 mov dword ptr [0x628cb4], esi
00497006 call 0x495600
0049700b add esp, 0xc
0049700e test eax, eax
00497010 jne 0x497aef
00497016 push eax
00497017 push 0x3f800000
0049701c push eax
0049701d call 0x495600
00497022 add esp, 0xc
00497025 test eax, eax
00497027 jne 0x497aef
0049702d push 0x3f800000
00497032 push eax
00497033 push eax
00497034 call 0x495600
00497039 add esp, 0xc
0049703c test eax, eax
0049703e jne 0x497aef
00497044 push eax
00497045 push eax
00497046 push 0xbf800000
0049704b call 0x495600
00497050 add esp, 0xc
00497053 test eax, eax
00497055 jne 0x497aef
0049705b push eax
0049705c push 0xbf800000
00497061 push eax
00497062 call 0x495600
00497067 add esp, 0xc
0049706a test eax, eax
0049706c jne 0x497aef
00497072 push 0xbf800000
00497077 push eax
00497078 push eax
00497079 call 0x495600
0049707e add esp, 0xc
00497081 test eax, eax
00497083 jne 0x497aef
00497089 push eax
0049708a push eax
0049708b push 0x3f800000
00497090 call 0x495890
00497095 add esp, 0xc
00497098 test eax, eax
0049709a jne 0x497aef
004970a0 push eax
004970a1 push 0x3f800000
004970a6 push eax
004970a7 call 0x495890
004970ac add esp, 0xc
004970af test eax, eax
004970b1 jne 0x497aef
004970b7 push 0x3f800000
004970bc push eax
004970bd push eax
004970be call 0x495890
004970c3 add esp, 0xc
004970c6 test eax, eax
004970c8 jne 0x497aef
004970ce push eax
004970cf push eax
004970d0 push 0xbf800000
004970d5 call 0x495890
004970da add esp, 0xc
004970dd test eax, eax
004970df jne 0x497aef
004970e5 push eax
004970e6 push 0xbf800000
004970eb push eax
004970ec call 0x495890
004970f1 add esp, 0xc
004970f4 test eax, eax
004970f6 jne 0x497aef
004970fc push 0xbf800000
00497101 push eax
00497102 push eax
00497103 call 0x495890
00497108 add esp, 0xc
0049710b test eax, eax
0049710d jne 0x497aef
00497113 push 0x3f800000
00497118 push 0x3f800000
0049711d push 0x3f800000
00497122 call 0x495b30
00497127 add esp, 0xc
0049712a test eax, eax
0049712c jne 0x4971fb
00497132 push 0xbf800000
00497137 push 0x3f800000
0049713c push 0x3f800000
00497141 call 0x495b30
00497146 add esp, 0xc
00497149 test eax, eax
0049714b jne 0x4971fb
00497151 push 0x3f800000
00497156 push 0xbf800000
0049715b push 0x3f800000
00497160 call 0x495b30
00497165 add esp, 0xc
00497168 test eax, eax
0049716a jne 0x4971fb
00497170 push 0xbf800000
00497175 push 0xbf800000
0049717a push 0x3f800000
0049717f call 0x495b30
00497184 add esp, 0xc
00497187 test eax, eax
00497189 jne 0x4971fb
0049718b push 0x3f800000
00497190 push 0x3f800000
00497195 push 0xbf800000
0049719a call 0x495b30
0049719f add esp, 0xc
004971a2 test eax, eax
004971a4 jne 0x4971fb
004971a6 push 0xbf800000
004971ab push 0x3f800000
004971b0 push 0xbf800000
004971b5 call 0x495b30
004971ba add esp, 0xc
004971bd test eax, eax
004971bf jne 0x4971fb
004971c1 push 0x3f800000
004971c6 push 0xbf800000
004971cb push 0xbf800000
004971d0 call 0x495b30
004971d5 add esp, 0xc
004971d8 test eax, eax
004971da jne 0x4971fb
004971dc push 0xbf800000
004971e1 push 0xbf800000
004971e6 push 0xbf800000
004971eb call 0x495b30
004971f0 add esp, 0xc
004971f3 test eax, eax
004971f5 je 0x4975ee
004971fb lea ecx, [ebx + 0x33c]
00497201 mov dword ptr [0x628f00], 0
0049720b fld dword ptr [ecx]
0049720d fsub dword ptr [edi + 0x33c]
00497213 fcom dword ptr [0x5b23f8]
00497219 fnstsw ax
0049721b test ah, 1
0049721e je 0x497222
00497220 fchs
00497222 fst dword ptr [esp + 0x4c]
00497226 fld dword ptr [ebx + 0x340]
0049722c fsub dword ptr [edi + 0x340]
00497232 fcom dword ptr [0x5b23f8]
00497238 fnstsw ax
0049723a test ah, 1
0049723d je 0x497241
0049723f fchs
00497241 fstp dword ptr [esp + 0x40]
00497245 fld dword ptr [ebx + 0x344]
0049724b fsub dword ptr [edi + 0x344]
00497251 fcom dword ptr [0x5b23f8]
00497257 fnstsw ax
00497259 test ah, 1
0049725c je 0x497260
0049725e fchs
00497260 fstp dword ptr [esp + 0x44]
00497264 fld dword ptr [esp + 0x40]
00497268 fcomp dword ptr [esp + 0x4c]
0049726c fnstsw ax
0049726e test ah, 0x41
00497271 jne 0x497279
00497273 fstp st(0)
00497275 fld dword ptr [esp + 0x40]
00497279 fld dword ptr [esp + 0x44]
0049727d fcomp st(1)
0049727f fnstsw ax
00497281 test ah, 0x41
00497284 jne 0x49728c
00497286 fstp st(0)
00497288 fld dword ptr [esp + 0x44]
0049728c fcomp dword ptr [0x5b243c]
00497292 fnstsw ax
00497294 test ah, 0x41
00497297 jne 0x4974c4
0049729d mov dword ptr [0x628f00], 1
004972a7 mov edx, dword ptr [ecx]
004972a9 mov eax, dword ptr [ecx + 4]
004972ac mov ecx, dword ptr [ecx + 8]
004972af mov dword ptr [esp + 0x30], edx
004972b3 lea edx, [edi + 0x364]
004972b9 mov dword ptr [esp + 0x34], eax
004972bd mov dword ptr [esp + 0x38], ecx
004972c1 mov eax, dword ptr [edx]
004972c3 mov dword ptr [esp + 0xc], eax
004972c7 lea eax, [edi + 0x370]
004972cd mov ecx, dword ptr [edx + 4]
004972d0 add edi, 0x37c
004972d6 fld dword ptr [0x628f50]
004972dc mov edx, dword ptr [edx + 8]
004972df mov dword ptr [esp + 0x10], ecx
004972e3 mov ecx, dword ptr [eax]
004972e5 mov dword ptr [esp + 0x14], edx
004972e9 fcomp dword ptr [0x5b23f8]
004972ef mov edx, dword ptr [eax + 4]
004972f2 mov dword ptr [esp + 0x18], ecx
004972f6 mov ecx, dword ptr [edi]
004972f8 mov dword ptr [esp + 0x1c], edx
004972fc mov eax, dword ptr [eax + 8]
004972ff mov dword ptr [esp + 0x24], ecx
00497303 mov edx, dword ptr [edi + 4]
00497306 mov dword ptr [esp + 0x20], eax
0049730a mov dword ptr [esp + 0x28], edx
0049730e mov eax, dword ptr [edi + 8]
00497311 mov dword ptr [esp + 0x2c], eax
00497315 fnstsw ax
00497317 test ah, 0x41
0049731a jne 0x497346
0049731c fld dword ptr [esp + 0xc]
00497320 fmul dword ptr [0x5b2624]
00497326 fstp dword ptr [esp + 0xc]
0049732a fld dword ptr [esp + 0x10]
0049732e fmul dword ptr [0x5b2624]
00497334 fstp dword ptr [esp + 0x10]
00497338 fld dword ptr [esp + 0x14]
0049733c fmul dword ptr [0x5b2624]
00497342 fstp dword ptr [esp + 0x14]
00497346 fld dword ptr [0x628f54]
0049734c fcomp dword ptr [0x5b23f8]
00497352 fnstsw ax
00497354 test ah, 0x41
00497357 jne 0x497383
00497359 fld dword ptr [esp + 0x18]
0049735d fmul dword ptr [0x5b2624]
00497363 fstp dword ptr [esp + 0x18]
00497367 fld dword ptr [esp + 0x1c]
0049736b fmul dword ptr [0x5b2624]
00497371 fstp dword ptr [esp + 0x1c]
00497375 fld dword ptr [esp + 0x20]
00497379 fmul dword ptr [0x5b2624]
0049737f fstp dword ptr [esp + 0x20]
00497383 fld dword ptr [0x628cb0]
00497389 fcomp dword ptr [0x5b23f8]
0049738f fnstsw ax
00497391 test ah, 0x41
00497394 jne 0x4973c0
00497396 fld dword ptr [esp + 0x24]
0049739a fmul dword ptr [0x5b2624]
004973a0 fstp dword ptr [esp + 0x24]
004973a4 fld dword ptr [esp + 0x28]
004973a8 fmul dword ptr [0x5b2624]
004973ae fstp dword ptr [esp + 0x28]
004973b2 fld dword ptr [esp + 0x2c]
004973b6 fmul dword ptr [0x5b2624]
004973bc fstp dword ptr [esp + 0x2c]
004973c0 lea ecx, [esp + 0x30]
004973c4 lea edx, [esp + 0xc]
004973c8 push ecx
004973c9 push edx
004973ca call 0x532910
004973cf fstp dword ptr [esp + 0x48]
004973d3 lea eax, [esp + 0x38]
004973d7 lea ecx, [esp + 0x20]
004973db push eax
004973dc push ecx
004973dd call 0x532910
004973e2 fstp dword ptr [esp + 0x54]
004973e6 lea edx, [esp + 0x40]
004973ea lea eax, [esp + 0x34]
004973ee push edx
004973ef push eax
004973f0 call 0x532910
004973f5 fld dword ptr [esp + 0x58]
004973f9 fcomp dword ptr [0x5b23f8]
004973ff add esp, 0x18
00497402 fnstsw ax
00497404 test ah, 1
00497407 je 0x497413
00497409 fld dword ptr [esp + 0x40]
0049740d fchs
0049740f fstp dword ptr [esp + 0x40]
00497413 fld dword ptr [esp + 0x44]
00497417 fcom dword ptr [0x5b23f8]
0049741d fnstsw ax
0049741f test ah, 1
00497422 je 0x497426
00497424 fchs
00497426 fld st(1)
00497428 fcomp dword ptr [0x5b23f8]
0049742e fnstsw ax
00497430 test ah, 1
00497433 je 0x49743b
00497435 fxch st(1)
00497437 fchs
00497439 fxch st(1)
0049743b fld dword ptr [esp + 0x40]
0049743f fcomp st(1)
00497441 fnstsw ax
00497443 test ah, 0x41
00497446 jne 0x497479
00497448 fld dword ptr [esp + 0x40]
0049744c fcomp st(2)
0049744e fnstsw ax
00497450 test ah, 0x41
00497453 jne 0x497479
00497455 mov ecx, dword ptr [esp + 0xc]
00497459 mov edx, dword ptr [esp + 0x10]
0049745d mov eax, dword ptr [esp + 0x14]
00497461 mov dword ptr [esi], ecx
00497463 mov dword ptr [esi + 4], edx
00497466 mov dword ptr [esi + 8], eax
00497469 fstp st(0)
0049746b pop edi
0049746c pop esi
0049746d fstp st(0)
0049746f mov eax, 1
00497474 pop ebx
00497475 add esp, 0x30
00497478 ret
00497479 fcomp st(1)
0049747b fnstsw ax
0049747d test ah, 0x41
00497480 fstp st(0)
00497482 jne 0x4974a4
00497484 mov ecx, dword ptr [esp + 0x18]
00497488 mov edx, dword ptr [esp + 0x1c]
0049748c mov eax, dword ptr [esp + 0x20]
00497490 mov dword ptr [esi], ecx
00497492 mov dword ptr [esi + 4], edx
00497495 mov dword ptr [esi + 8], eax
00497498 pop edi
00497499 pop esi
0049749a mov eax, 1
0049749f pop ebx
004974a0 add esp, 0x30
004974a3 ret
004974a4 mov ecx, dword ptr [esp + 0x24]
004974a8 mov edx, dword ptr [esp + 0x28]
004974ac mov eax, dword ptr [esp + 0x2c]
004974b0 mov dword ptr [esi], ecx
004974b2 mov dword ptr [esi + 4], edx
004974b5 mov dword ptr [esi + 8], eax
004974b8 pop edi
004974b9 pop esi
004974ba mov eax, 1
004974bf pop ebx
004974c0 add esp, 0x30
004974c3 ret
004974c4 fld dword ptr [0x628f50]
004974ca fcomp dword ptr [0x5b23f8]
004974d0 fnstsw ax
004974d2 test ah, 1
004974d5 je 0x4974e5
004974d7 fld dword ptr [0x628f50]
004974dd fadd dword ptr [edi + 0x3a8]
004974e3 jmp 0x4974f1
004974e5 fld dword ptr [edi + 0x3a8]
004974eb fsub dword ptr [0x628f50]
004974f1 fstp dword ptr [esp + 0x40]
004974f5 fld dword ptr [0x628f54]
004974fb fcomp dword ptr [0x5b23f8]
00497501 fnstsw ax
00497503 test ah, 1
00497506 je 0x497516
00497508 fld dword ptr [0x628f54]
0049750e fadd dword ptr [edi + 0x3ac]
00497514 jmp 0x497522
00497516 fld dword ptr [edi + 0x3ac]
0049751c fsub dword ptr [0x628f54]
00497522 fld dword ptr [0x628cb0]
00497528 fcomp dword ptr [0x5b23f8]
0049752e fnstsw ax
00497530 test ah, 1
00497533 je 0x497543
00497535 fld dword ptr [0x628cb0]
0049753b fadd dword ptr [edi + 0x3b0]
00497541 jmp 0x49754f
00497543 fld dword ptr [edi + 0x3b0]
00497549 fsub dword ptr [0x628cb0]
0049754f fld dword ptr [esp + 0x40]
00497553 fcomp st(2)
00497555 fnstsw ax
00497557 test ah, 1
0049755a je 0x49758d
0049755c fld dword ptr [esp + 0x40]
00497560 fcomp st(1)
00497562 fnstsw ax
00497564 test ah, 1
00497567 je 0x49758d
00497569 add edi, 0x364
0049756f mov ecx, esi
00497571 fstp st(0)
00497573 mov edx, dword ptr [edi]
00497575 mov dword ptr [ecx], edx
00497577 mov eax, dword ptr [edi + 4]
0049757a mov dword ptr [ecx + 4], eax
0049757d mov edx, dword ptr [edi + 8]
00497580 fstp st(0)
00497582 mov dword ptr [ecx + 8], edx
00497585 fld dword ptr [0x628f50]
0049758b jmp 0x4975b8
0049758d fxch st(1)
0049758f fcomp st(1)
00497591 fnstsw ax
00497593 test ah, 1
00497596 fstp st(0)
00497598 je 0x4975ce
0049759a add edi, 0x370
004975a0 mov eax, esi
004975a2 mov ecx, dword ptr [edi]
004975a4 mov dword ptr [eax], ecx
004975a6 mov edx, dword ptr [edi + 4]
004975a9 mov dword ptr [eax + 4], edx
004975ac mov ecx, dword ptr [edi + 8]
004975af mov dword ptr [eax + 8], ecx
004975b2 fld dword ptr [0x628f54]
004975b8 fcomp dword ptr [0x5b23f8]
004975be fnstsw ax
004975c0 test ah, 0x41
004975c3 jne 0x497aef
004975c9 jmp 0x497acd
004975ce add edi, 0x37c
004975d4 mov edx, esi
004975d6 mov eax, dword ptr [edi]
004975d8 mov dword ptr [edx], eax
004975da mov ecx, dword ptr [edi + 4]
004975dd mov dword ptr [edx + 4], ecx
004975e0 mov eax, dword ptr [edi + 8]
004975e3 mov dword ptr [edx + 8], eax
004975e6 fld dword ptr [0x628cb0]
004975ec jmp 0x4975b8
004975ee push 0x3f800000
004975f3 push 0x3f800000
004975f8 push 0x3f800000
004975fd call 0x495d30
00497602 add esp, 0xc
00497605 test eax, eax
00497607 jne 0x4976d6
0049760d push 0xbf800000
00497612 push 0x3f800000
00497617 push 0x3f800000
0049761c call 0x495d30
00497621 add esp, 0xc
00497624 test eax, eax
00497626 jne 0x4976d6
0049762c push 0x3f800000
00497631 push 0xbf800000
00497636 push 0x3f800000
0049763b call 0x495d30
00497640 add esp, 0xc
00497643 test eax, eax
00497645 jne 0x4976d6
0049764b push 0xbf800000
00497650 push 0xbf800000
00497655 push 0x3f800000
0049765a call 0x495d30
0049765f add esp, 0xc
00497662 test eax, eax
00497664 jne 0x4976d6
00497666 push 0x3f800000
0049766b push 0x3f800000
00497670 push 0xbf800000
00497675 call 0x495d30
0049767a add esp, 0xc
0049767d test eax, eax
0049767f jne 0x4976d6
00497681 push 0xbf800000
00497686 push 0x3f800000
0049768b push 0xbf800000
00497690 call 0x495d30
00497695 add esp, 0xc
00497698 test eax, eax
0049769a jne 0x4976d6
0049769c push 0x3f800000
004976a1 push 0xbf800000
004976a6 push 0xbf800000
004976ab call 0x495d30
004976b0 add esp, 0xc
004976b3 test eax, eax
004976b5 jne 0x4976d6
004976b7 push 0xbf800000
004976bc push 0xbf800000
004976c1 push 0xbf800000
004976c6 call 0x495d30
004976cb add esp, 0xc
004976ce test eax, eax
004976d0 je 0x497afb
004976d6 mov dword ptr [0x628f00], 0
004976e0 lea ecx, [edi + 0x33c]
004976e6 fld dword ptr [ebx + 0x33c]
004976ec fsub dword ptr [ecx]
004976ee fcom dword ptr [0x5b23f8]
004976f4 fnstsw ax
004976f6 test ah, 1
004976f9 je 0x4976fd
004976fb fchs
004976fd fst dword ptr [esp + 0x4c]
00497701 fld dword ptr [ebx + 0x340]
00497707 fsub dword ptr [edi + 0x340]
0049770d fcom dword ptr [0x5b23f8]
00497713 fnstsw ax
00497715 test ah, 1
00497718 je 0x49771c
0049771a fchs
0049771c fstp dword ptr [esp + 0x40]
00497720 fld dword ptr [ebx + 0x344]
00497726 fsub dword ptr [edi + 0x344]
0049772c fcom dword ptr [0x5b23f8]
00497732 fnstsw ax
00497734 test ah, 1
00497737 je 0x49773b
00497739 fchs
0049773b fstp dword ptr [esp + 0x44]
0049773f fld dword ptr [esp + 0x40]
00497743 fcomp dword ptr [esp + 0x4c]
00497747 fnstsw ax
00497749 test ah, 0x41
0049774c jne 0x497754
0049774e fstp st(0)
00497750 fld dword ptr [esp + 0x40]
00497754 fld dword ptr [esp + 0x44]
00497758 fcomp st(1)
0049775a fnstsw ax
0049775c test ah, 0x41
0049775f jne 0x497767
00497761 fstp st(0)
00497763 fld dword ptr [esp + 0x44]
00497767 fcomp dword ptr [0x5b243c]
0049776d fnstsw ax
0049776f test ah, 0x41
00497772 jne 0x49799f
00497778 mov dword ptr [0x628f00], 1
00497782 mov edx, dword ptr [ecx]
00497784 mov eax, dword ptr [ecx + 4]
00497787 mov ecx, dword ptr [ecx + 8]
0049778a mov dword ptr [esp + 0x30], edx
0049778e lea edx, [ebx + 0x364]
00497794 mov dword ptr [esp + 0x34], eax
00497798 mov dword ptr [esp + 0x38], ecx
0049779c mov eax, dword ptr [edx]
0049779e mov dword ptr [esp + 0x24], eax
004977a2 lea eax, [ebx + 0x370]
004977a8 mov ecx, dword ptr [edx + 4]
004977ab add ebx, 0x37c
004977b1 fld dword ptr [0x628f50]
004977b7 mov edx, dword ptr [edx + 8]
004977ba mov dword ptr [esp + 0x28], ecx
004977be mov ecx, dword ptr [eax]
004977c0 mov dword ptr [esp + 0x2c], edx
004977c4 fcomp dword ptr [0x5b23f8]
004977ca mov edx, dword ptr [eax + 4]
004977cd mov dword ptr [esp + 0x18], ecx
004977d1 mov ecx, dword ptr [ebx]
004977d3 mov dword ptr [esp + 0x1c], edx
004977d7 mov eax, dword ptr [eax + 8]
004977da mov dword ptr [esp + 0xc], ecx
004977de mov edx, dword ptr [ebx + 4]
004977e1 mov dword ptr [esp + 0x20], eax
004977e5 mov dword ptr [esp + 0x10], edx
004977e9 mov eax, dword ptr [ebx + 8]
004977ec mov dword ptr [esp + 0x14], eax
004977f0 fnstsw ax
004977f2 test ah, 1
004977f5 je 0x497821
004977f7 fld dword ptr [esp + 0x24]
004977fb fmul dword ptr [0x5b2624]
00497801 fstp dword ptr [esp + 0x24]
00497805 fld dword ptr [esp + 0x28]
00497809 fmul dword ptr [0x5b2624]
0049780f fstp dword ptr [esp + 0x28]
00497813 fld dword ptr [esp + 0x2c]
00497817 fmul dword ptr [0x5b2624]
0049781d fstp dword ptr [esp + 0x2c]
00497821 fld dword ptr [0x628f54]
00497827 fcomp dword ptr [0x5b23f8]
0049782d fnstsw ax
0049782f test ah, 1
00497832 je 0x49785e
00497834 fld dword ptr [esp + 0x18]
00497838 fmul dword ptr [0x5b2624]
0049783e fstp dword ptr [esp + 0x18]
00497842 fld dword ptr [esp + 0x1c]
00497846 fmul dword ptr [0x5b2624]
0049784c fstp dword ptr [esp + 0x1c]
00497850 fld dword ptr [esp + 0x20]
00497854 fmul dword ptr [0x5b2624]
0049785a fstp dword ptr [esp + 0x20]
0049785e fld dword ptr [0x628cb0]
00497864 fcomp dword ptr [0x5b23f8]
0049786a fnstsw ax
0049786c test ah, 1
0049786f je 0x49789b
00497871 fld dword ptr [esp + 0xc]
00497875 fmul dword ptr [0x5b2624]
0049787b fstp dword ptr [esp + 0xc]
0049787f fld dword ptr [esp + 0x10]
00497883 fmul dword ptr [0x5b2624]
00497889 fstp dword ptr [esp + 0x10]
0049788d fld dword ptr [esp + 0x14]
00497891 fmul dword ptr [0x5b2624]
00497897 fstp dword ptr [esp + 0x14]
0049789b lea ecx, [esp + 0x30]
0049789f lea edx, [esp + 0x24]
004978a3 push ecx
004978a4 push edx
004978a5 call 0x532910
004978aa fstp dword ptr [esp + 0x48]
004978ae lea eax, [esp + 0x38]
004978b2 lea ecx, [esp + 0x20]
004978b6 push eax
004978b7 push ecx
004978b8 call 0x532910
004978bd fstp dword ptr [esp + 0x54]
004978c1 lea edx, [esp + 0x40]
004978c5 lea eax, [esp + 0x1c]
004978c9 push edx
004978ca push eax
004978cb call 0x532910
004978d0 fld dword ptr [esp + 0x58]
004978d4 fcomp dword ptr [0x5b23f8]
004978da add esp, 0x18
004978dd fnstsw ax
004978df test ah, 1
004978e2 je 0x4978ee
004978e4 fld dword ptr [esp + 0x40]
004978e8 fchs
004978ea fstp dword ptr [esp + 0x40]
004978ee fld dword ptr [esp + 0x44]
004978f2 fcom dword ptr [0x5b23f8]
004978f8 fnstsw ax
004978fa test ah, 1
004978fd je 0x497901
004978ff fchs
00497901 fld st(1)
00497903 fcomp dword ptr [0x5b23f8]
00497909 fnstsw ax
0049790b test ah, 1
0049790e je 0x497916
00497910 fxch st(1)
00497912 fchs
00497914 fxch st(1)
00497916 fld dword ptr [esp + 0x40]
0049791a fcomp st(1)
0049791c fnstsw ax
0049791e test ah, 0x41
00497921 jne 0x497954
00497923 fld dword ptr [esp + 0x40]
00497927 fcomp st(2)
00497929 fnstsw ax
0049792b test ah, 0x41
0049792e jne 0x497954
00497930 mov ecx, dword ptr [esp + 0x24]
00497934 mov edx, dword ptr [esp + 0x28]
00497938 mov eax, dword ptr [esp + 0x2c]
0049793c mov dword ptr [esi], ecx
0049793e mov dword ptr [esi + 4], edx
00497941 mov dword ptr [esi + 8], eax
00497944 fstp st(0)
00497946 pop edi
00497947 pop esi
00497948 fstp st(0)
0049794a mov eax, 1
0049794f pop ebx
00497950 add esp, 0x30
00497953 ret
00497954 fcomp st(1)
00497956 fnstsw ax
00497958 test ah, 0x41
0049795b fstp st(0)
0049795d jne 0x49797f
0049795f mov ecx, dword ptr [esp + 0x18]
00497963 mov edx, dword ptr [esp + 0x1c]
00497967 mov eax, dword ptr [esp + 0x20]
0049796b mov dword ptr [esi], ecx
0049796d mov dword ptr [esi + 4], edx
00497970 mov dword ptr [esi + 8], eax
00497973 pop edi
00497974 pop esi
00497975 mov eax, 1
0049797a pop ebx
0049797b add esp, 0x30
0049797e ret
0049797f mov ecx, dword ptr [esp + 0xc]
00497983 mov edx, dword ptr [esp + 0x10]
00497987 mov eax, dword ptr [esp + 0x14]
0049798b mov dword ptr [esi], ecx
0049798d mov dword ptr [esi + 4], edx
00497990 mov dword ptr [esi + 8], eax
00497993 pop edi
00497994 pop esi
00497995 mov eax, 1
0049799a pop ebx
0049799b add esp, 0x30
0049799e ret
0049799f fld dword ptr [0x628f50]
004979a5 fcomp dword ptr [0x5b23f8]
004979ab fnstsw ax
004979ad test ah, 1
004979b0 je 0x4979c0
004979b2 fld dword ptr [0x628f50]
004979b8 fadd dword ptr [ebx + 0x3a8]
004979be jmp 0x4979cc
004979c0 fld dword ptr [ebx + 0x3a8]
004979c6 fsub dword ptr [0x628f50]
004979cc fstp dword ptr [esp + 0x40]
004979d0 fld dword ptr [0x628f54]
004979d6 fcomp dword ptr [0x5b23f8]
004979dc fnstsw ax
004979de test ah, 1
004979e1 je 0x4979f1
004979e3 fld dword ptr [0x628f54]
004979e9 fadd dword ptr [ebx + 0x3ac]
004979ef jmp 0x4979fd
004979f1 fld dword ptr [ebx + 0x3ac]
004979f7 fsub dword ptr [0x628f54]
004979fd fld dword ptr [0x628cb0]
00497a03 fcomp dword ptr [0x5b23f8]
00497a09 fnstsw ax
00497a0b test ah, 1
00497a0e je 0x497a1e
00497a10 fld dword ptr [0x628cb0]
00497a16 fadd dword ptr [ebx + 0x3b0]
00497a1c jmp 0x497a2a
00497a1e fld dword ptr [ebx + 0x3b0]
00497a24 fsub dword ptr [0x628cb0]
00497a2a fld dword ptr [esp + 0x40]
00497a2e fcomp st(2)
00497a30 fnstsw ax
00497a32 test ah, 1
00497a35 je 0x497a68
00497a37 fld dword ptr [esp + 0x40]
00497a3b fcomp st(1)
00497a3d fnstsw ax
00497a3f test ah, 1
00497a42 je 0x497a68
00497a44 add ebx, 0x364
00497a4a mov ecx, esi
00497a4c fstp st(0)
00497a4e mov edx, dword ptr [ebx]
00497a50 mov dword ptr [ecx], edx
00497a52 mov eax, dword ptr [ebx + 4]
00497a55 mov dword ptr [ecx + 4], eax
00497a58 mov edx, dword ptr [ebx + 8]
00497a5b fstp st(0)
00497a5d mov dword ptr [ecx + 8], edx
00497a60 fld dword ptr [0x628f50]
00497a66 jmp 0x497a93
00497a68 fxch st(1)
00497a6a fcomp st(1)
00497a6c fnstsw ax
00497a6e test ah, 1
00497a71 fstp st(0)
00497a73 je 0x497aa2
00497a75 add ebx, 0x370
00497a7b mov eax, esi
00497a7d mov ecx, dword ptr [ebx]
00497a7f mov dword ptr [eax], ecx
00497a81 mov edx, dword ptr [ebx + 4]
00497a84 mov dword ptr [eax + 4], edx
00497a87 mov ecx, dword ptr [ebx + 8]
00497a8a mov dword ptr [eax + 8], ecx
00497a8d fld dword ptr [0x628f54]
00497a93 fcomp dword ptr [0x5b23f8]
00497a99 fnstsw ax
00497a9b test ah, 1
00497a9e je 0x497aef
00497aa0 jmp 0x497acd
00497aa2 add ebx, 0x37c
00497aa8 mov edx, esi
00497aaa mov eax, dword ptr [ebx]
00497aac mov dword ptr [edx], eax
00497aae mov ecx, dword ptr [ebx + 4]
00497ab1 mov dword ptr [edx + 4], ecx
00497ab4 mov eax, dword ptr [ebx + 8]
00497ab7 mov dword ptr [edx + 8], eax
00497aba fld dword ptr [0x628cb0]
00497ac0 fcomp dword ptr [0x5b23f8]
00497ac6 fnstsw ax
00497ac8 test ah, 1
00497acb je 0x497aef
00497acd fld dword ptr [esi]
00497acf fmul dword ptr [0x5b2624]
00497ad5 fstp dword ptr [esi]
00497ad7 fld dword ptr [esi + 4]
00497ada fmul dword ptr [0x5b2624]
00497ae0 fstp dword ptr [esi + 4]
00497ae3 fld dword ptr [esi + 8]
00497ae6 fmul dword ptr [0x5b2624]
00497aec fstp dword ptr [esi + 8]
00497aef pop edi
00497af0 pop esi
00497af1 mov eax, 1
00497af6 pop ebx
00497af7 add esp, 0x30
00497afa ret
00497afb pop edi
00497afc pop esi
00497afd xor eax, eax
00497aff pop ebx
00497b00 add esp, 0x30
00497b03 ret
00497b04 nop
00497b05 nop
00497b06 nop
00497b07 nop
00497b08 nop
00497b09 nop
00497b0a nop
00497b0b nop
00497b0c nop
00497b0d nop
00497b0e nop
00497b0f nop
00497b10 sub esp, 0x58
00497b13 push ebx
00497b14 push ebp
00497b15 push esi
00497b16 mov esi, dword ptr [esp + 0x6c]
00497b1a push edi
00497b1b mov edi, dword ptr [esp + 0x6c]
00497b1f lea ebx, [esi + 0x364]
00497b25 mov dword ptr [esp + 0x10], 0
00497b2d lea ebp, [edi + 0x364]
00497b33 push ebx
00497b34 push ebp
00497b35 call 0x532910
00497b3a fstp dword ptr [0x628f08]
00497b40 lea eax, [esi + 0x370]
00497b46 push eax
00497b47 push ebp
00497b48 call 0x532910
00497b4d fstp dword ptr [0x628f0c]
00497b53 lea eax, [esi + 0x37c]
00497b59 push eax
00497b5a push ebp
00497b5b call 0x532910
00497b60 fstp dword ptr [0x628f10]
00497b66 lea eax, [edi + 0x370]
00497b6c push ebx
00497b6d push eax
00497b6e call 0x532910
00497b73 fstp dword ptr [0x628f14]
00497b79 lea eax, [esi + 0x370]
00497b7f push eax
00497b80 lea eax, [edi + 0x370]
00497b86 push eax
00497b87 call 0x532910
00497b8c fstp dword ptr [0x628f18]
00497b92 lea eax, [esi + 0x37c]
00497b98 push eax
00497b99 lea eax, [edi + 0x370]
00497b9f push eax
00497ba0 call 0x532910
00497ba5 fstp dword ptr [0x628f1c]
00497bab lea eax, [edi + 0x37c]
00497bb1 push ebx
00497bb2 push eax
00497bb3 call 0x532910
00497bb8 fstp dword ptr [0x628f20]
00497bbe lea eax, [esi + 0x370]
00497bc4 push eax
00497bc5 lea eax, [edi + 0x37c]
00497bcb push eax
00497bcc call 0x532910
00497bd1 fstp dword ptr [0x628f24]
00497bd7 add esp, 0x40
00497bda lea eax, [esi + 0x37c]
00497be0 push eax
00497be1 lea eax, [edi + 0x37c]
00497be7 push eax
00497be8 call 0x532910
00497bed fstp dword ptr [0x628f28]
00497bf3 fld dword ptr [0x628f08]
00497bf9 fmul dword ptr [esi + 0x3a8]
00497bff add esp, 8
00497c02 fstp dword ptr [0x628f2c]
00497c08 fld dword ptr [0x628f0c]
00497c0e fmul dword ptr [esi + 0x3ac]
00497c14 fstp dword ptr [0x628f30]
00497c1a fld dword ptr [0x628f10]
00497c20 fmul dword ptr [esi + 0x3b0]
00497c26 fstp dword ptr [0x628f34]
00497c2c fld dword ptr [0x628f14]
00497c32 fmul dword ptr [esi + 0x3a8]
00497c38 fstp dword ptr [0x628f38]
00497c3e fld dword ptr [0x628f18]
00497c44 fmul dword ptr [esi + 0x3ac]
00497c4a fstp dword ptr [0x628f3c]
00497c50 fld dword ptr [0x628f1c]
00497c56 fmul dword ptr [esi + 0x3b0]
00497c5c fstp dword ptr [0x628f40]
00497c62 fld dword ptr [0x628f20]
00497c68 fmul dword ptr [esi + 0x3a8]
00497c6e mov dword ptr [esp + 0x6c], 0
00497c76 fstp dword ptr [0x628f44]
00497c7c fld dword ptr [0x628f24]
00497c82 fmul dword ptr [esi + 0x3ac]
00497c88 fstp dword ptr [0x628f48]
00497c8e fld dword ptr [0x628f28]
00497c94 fmul dword ptr [esi + 0x3b0]
00497c9a fstp dword ptr [0x628f4c]
00497ca0 fld dword ptr [0x628f08]
00497ca6 fmul dword ptr [edi + 0x3a8]
00497cac fstp dword ptr [0x628c8c]
00497cb2 fld dword ptr [0x628f0c]
00497cb8 fmul dword ptr [edi + 0x3a8]
00497cbe fstp dword ptr [0x628c90]
00497cc4 fld dword ptr [0x628f10]
00497cca fmul dword ptr [edi + 0x3a8]
00497cd0 fstp dword ptr [0x628c94]
00497cd6 fld dword ptr [0x628f14]
00497cdc fmul dword ptr [edi + 0x3ac]
00497ce2 fstp dword ptr [0x628c98]
00497ce8 fld dword ptr [0x628f18]
00497cee fmul dword ptr [edi + 0x3ac]
00497cf4 fstp dword ptr [0x628c9c]
00497cfa fld dword ptr [0x628f1c]
00497d00 fmul dword ptr [edi + 0x3ac]
00497d06 fstp dword ptr [0x628ca0]
00497d0c fld dword ptr [0x628f20]
00497d12 fmul dword ptr [edi + 0x3b0]
00497d18 fstp dword ptr [0x628ca4]
00497d1e fld dword ptr [0x628f24]
00497d24 fmul dword ptr [edi + 0x3b0]
00497d2a fstp dword ptr [0x628ca8]
00497d30 fld dword ptr [0x628f28]
00497d36 fmul dword ptr [edi + 0x3b0]
00497d3c fstp dword ptr [0x628cac]
00497d42 lea eax, [esp + 0x14]
00497d46 push eax
00497d47 lea eax, [edi + 0x330]
00497d4d push eax
00497d4e lea eax, [esi + 0x330]
00497d54 push eax
00497d55 push 1
00497d57 call 0x532330
00497d5c lea ecx, [esp + 0x24]
00497d60 push ecx
00497d61 push ebp
00497d62 call 0x532910
00497d67 fstp dword ptr [0x628cc4]
00497d6d lea edx, [esp + 0x2c]
00497d71 lea eax, [edi + 0x370]
00497d77 push edx
00497d78 push eax
00497d79 call 0x532910
00497d7e fstp dword ptr [0x628cc8]
00497d84 lea eax, [esp + 0x34]
00497d88 push eax
00497d89 lea eax, [edi + 0x37c]
00497d8f push eax
00497d90 call 0x532910
00497d95 fstp dword ptr [0x628ccc]
00497d9b lea ecx, [esp + 0x3c]
00497d9f push ecx
00497da0 push ebx
00497da1 call 0x532910
00497da6 fstp dword ptr [0x628cd0]
00497dac lea edx, [esp + 0x44]
00497db0 lea eax, [esi + 0x370]
00497db6 push edx
00497db7 push eax
00497db8 call 0x532910
00497dbd fstp dword ptr [0x628cd4]
00497dc3 lea eax, [esp + 0x4c]
00497dc7 push eax
00497dc8 lea eax, [esi + 0x37c]
00497dce push eax
00497dcf call 0x532910
00497dd4 mov ecx, dword ptr [esp + 0xb8]
00497ddb mov edx, dword ptr [esp + 0xb4]
00497de2 fstp dword ptr [0x628cd8]
00497de8 add esp, 0x40
00497deb push ecx
00497dec push edx
00497ded push esi
00497dee push edi
00497def call 0x496fd0
00497df4 add esp, 0x10
00497df7 test eax, eax
00497df9 mov eax, dword ptr [esp + 0x10]
00497dfd je 0x4980c1
00497e03 test eax, eax
00497e05 jne 0x49807d
00497e0b lea edx, [esp + 0x44]
00497e0f lea eax, [esi + 0x33c]
00497e15 lea ecx, [edi + 0x33c]
00497e1b push edx
00497e1c push eax
00497e1d push ecx
00497e1e push 1
00497e20 call 0x532330
00497e25 fld dword ptr [esp + 0x5c]
00497e29 fmul dword ptr [esp + 0x5c]
00497e2d fld dword ptr [esp + 0x54]
00497e31 fmul dword ptr [esp + 0x54]
00497e35 add esp, 0x10
00497e38 faddp st(1)
00497e3a fcomp dword ptr [0x5b49cc]
00497e40 fnstsw ax
00497e42 test ah, 0x41
00497e45 jne 0x497fc5
00497e4b fld dword ptr [esp + 0x14]
00497e4f fmul dword ptr [esp + 0x14]
00497e53 fld dword ptr [esp + 0x1c]
00497e57 fmul dword ptr [esp + 0x1c]
00497e5b faddp st(1)
00497e5d fcomp dword ptr [0x5b26a0]
00497e63 fnstsw ax
00497e65 test ah, 1
00497e68 je 0x497e99
00497e6a lea eax, [esp + 0x44]
00497e6e push eax
00497e6f call 0x532b20
00497e74 fmul dword ptr [0x5b23f0]
00497e7a add esp, 4
00497e7d fcom dword ptr [0x5b23f8]
00497e83 fnstsw ax
00497e85 test ah, 0x40
00497e88 jne 0x497f32
00497e8e fdivr dword ptr [0x5b23f0]
00497e94 jmp 0x497f3a
00497e99 mov ecx, dword ptr [esp + 0x44]
00497e9d mov edx, dword ptr [esp + 0x48]
00497ea1 mov eax, dword ptr [esp + 0x4c]
00497ea5 mov dword ptr [esp + 0x5c], ecx
00497ea9 mov dword ptr [esp + 0x60], edx
00497ead lea ecx, [esp + 0x5c]
00497eb1 lea edx, [esp + 0x5c]
00497eb5 push ecx
00497eb6 push edx
00497eb7 mov dword ptr [esp + 0x6c], eax
00497ebb call 0x5328d0
00497ec0 mov eax, dword ptr [esp + 0x1c]
00497ec4 mov ecx, dword ptr [esp + 0x20]
00497ec8 mov edx, dword ptr [esp + 0x24]
00497ecc mov dword ptr [esp + 0x58], eax
00497ed0 mov dword ptr [esp + 0x5c], ecx
00497ed4 lea eax, [esp + 0x58]
00497ed8 lea ecx, [esp + 0x58]
00497edc push eax
00497edd push ecx
00497ede mov dword ptr [esp + 0x68], edx
00497ee2 call 0x5328d0
00497ee7 lea edx, [esp + 0x60]
00497eeb lea eax, [esp + 0x6c]
00497eef push edx
00497ef0 push eax
00497ef1 call 0x532910
00497ef6 fcomp dword ptr [0x5b25e0]
00497efc add esp, 0x18
00497eff fnstsw ax
00497f01 test ah, 0x41
00497f04 jne 0x497fc5
00497f0a lea ecx, [esp + 0x44]
00497f0e push ecx
00497f0f call 0x532b20
00497f14 fmul dword ptr [0x5b23f0]
00497f1a add esp, 4
00497f1d fcom dword ptr [0x5b23f8]
00497f23 fnstsw ax
00497f25 test ah, 0x40
00497f28 jne 0x497f32
00497f2a fdivr dword ptr [0x5b23f0]
00497f30 jmp 0x497f3a
00497f32 fstp st(0)
00497f34 fld dword ptr [0x5b24a8]
00497f3a fchs
00497f3c fstp dword ptr [esp + 0x70]
00497f40 mov eax, dword ptr [esp + 0x70]
00497f44 lea edx, [esp + 0x2c]
00497f48 push edx
00497f49 push eax
00497f4a lea eax, [edi + 0x33c]
00497f50 push eax
00497f51 push 1
00497f53 call 0x532360
00497f58 fld dword ptr [esp + 0x3c]
00497f5c fmul dword ptr [0x5b24b8]
00497f62 mov edx, dword ptr [esp + 0x80]
00497f69 lea ecx, [esp + 0x48]
00497f6d push ecx
00497f6e lea eax, [esi + 0x33c]
00497f74 push edx
00497f75 push eax
00497f76 fstp dword ptr [esp + 0x48]
00497f7a fld dword ptr [esp + 0x4c]
00497f7e fmul dword ptr [0x5b24b8]
00497f84 push 1
00497f86 fstp dword ptr [esp + 0x50]
00497f8a fld dword ptr [esp + 0x54]
00497f8e fmul dword ptr [0x5b24b8]
00497f94 fstp dword ptr [esp + 0x54]
00497f98 call 0x532360
00497f9d fld dword ptr [esp + 0x58]
00497fa1 fmul dword ptr [0x5b24b8]
00497fa7 add esp, 0x20
00497faa fstp dword ptr [esp + 0x38]
00497fae fld dword ptr [esp + 0x3c]
00497fb2 fmul dword ptr [0x5b24b8]
00497fb8 fstp dword ptr [esp + 0x3c]
00497fbc fld dword ptr [esp + 0x40]
00497fc0 jmp 0x49806b
00497fc5 mov eax, dword ptr [esp + 0x14]
00497fc9 mov ecx, dword ptr [esp + 0x18]
00497fcd mov edx, dword ptr [esp + 0x1c]
00497fd1 mov dword ptr [esp + 0x20], eax
00497fd5 mov dword ptr [esp + 0x24], ecx
00497fd9 lea eax, [esp + 0x20]
00497fdd lea ecx, [esp + 0x20]
00497fe1 push eax
00497fe2 push ecx
00497fe3 mov dword ptr [esp + 0x30], edx
00497fe7 call 0x5328d0
00497fec fld dword ptr [esi + 0x354]
00497ff2 fadd dword ptr [edi + 0x354]
00497ff8 fld dword ptr [edi + 0x354]
00497ffe add esp, 8
00498001 fdiv st(1)
00498003 fstp dword ptr [esp + 0x70]
00498007 fdivr dword ptr [esi + 0x354]
0049800d fld dword ptr [esp + 0x20]
00498011 fmul st(1)
00498013 fmul dword ptr [0x5b49c8]
00498019 fstp dword ptr [esp + 0x2c]
0049801d fld dword ptr [esp + 0x24]
00498021 fmul st(1)
00498023 fmul dword ptr [0x5b49c8]
00498029 fstp dword ptr [esp + 0x30]
0049802d fld dword ptr [esp + 0x28]
00498031 fmul st(1)
00498033 fmul dword ptr [0x5b49c8]
00498039 fstp dword ptr [esp + 0x34]
0049803d fstp st(0)
0049803f fld dword ptr [esp + 0x20]
00498043 fmul dword ptr [esp + 0x70]
00498047 fmul dword ptr [0x5b24b8]
0049804d fstp dword ptr [esp + 0x38]
00498051 fld dword ptr [esp + 0x24]
00498055 fmul dword ptr [esp + 0x70]
00498059 fmul dword ptr [0x5b24b8]
0049805f fstp dword ptr [esp + 0x3c]
00498063 fld dword ptr [esp + 0x28]
00498067 fmul dword ptr [esp + 0x70]
0049806b fmul dword ptr [0x5b24b8]
00498071 mov dword ptr [esp + 0x10], 1
00498079 fstp dword ptr [esp + 0x40]
0049807d lea eax, [edi + 0x330]
00498083 lea edx, [esp + 0x2c]
00498087 push eax
00498088 push edx
00498089 push eax
0049808a push 1
0049808c call 0x532300
00498091 lea eax, [esi + 0x330]
00498097 lea ecx, [esp + 0x48]
0049809b push eax
0049809c push ecx
0049809d push eax
0049809e push 1
004980a0 call 0x532300
004980a5 mov eax, dword ptr [esp + 0x8c]
004980ac add esp, 0x20
004980af inc eax
004980b0 cmp eax, 0x20
004980b3 mov dword ptr [esp + 0x6c], eax
004980b7 jl 0x497d42
004980bd mov eax, dword ptr [esp + 0x10]
004980c1 pop edi
004980c2 pop esi
004980c3 pop ebp
004980c4 pop ebx
004980c5 add esp, 0x58
004980c8 ret
004980c9 nop
004980ca nop
004980cb nop
004980cc nop
004980cd nop
004980ce nop
004980cf nop
004980d0 sub esp, 0x18
004980d3 lea eax, [esp]
004980d7 lea ecx, [esp + 0xc]
004980db push ebx
004980dc push esi
004980dd mov esi, dword ptr [esp + 0x28]
004980e1 push edi
004980e2 mov edi, dword ptr [esp + 0x28]
004980e6 push eax
004980e7 push ecx
004980e8 push esi
004980e9 push edi
004980ea call 0x497b10
004980ef add esp, 0x10
004980f2 test eax, eax
004980f4 jne 0x4980fd
004980f6 pop edi
004980f7 pop esi
004980f8 pop ebx
004980f9 add esp, 0x18
004980fc ret
004980fd lea edx, [esp + 0xc]
00498101 lea eax, [esp + 0x18]
00498105 push edx
00498106 push eax
00498107 push esi
00498108 push edi
00498109 call 0x496860
0049810e push edi
0049810f mov ebx, 4
00498114 call 0x495020
00498119 push edi
0049811a call 0x498de0
0049811f push esi
00498120 call 0x495020
00498125 push esi
00498126 call 0x498de0
0049812b lea ecx, [esp + 0x2c]
0049812f lea edx, [esp + 0x38]
00498133 push ecx
00498134 push edx
00498135 push esi
00498136 push edi
00498137 call 0x497b10
0049813c add esp, 0x30
0049813f test eax, eax
00498141 je 0x498205
00498147 test ebx, ebx
00498149 jle 0x498205
0049814f lea eax, [esp + 0xc]
00498153 lea ecx, [esp + 0x18]
00498157 push eax
00498158 push ecx
00498159 push esi
0049815a push edi
0049815b dec ebx
0049815c call 0x496860
00498161 add esp, 0x10
00498164 test eax, eax
00498166 je 0x498205
0049816c push edi
0049816d call 0x495020
00498172 push edi
00498173 call 0x498de0
00498178 push esi
00498179 call 0x495020
0049817e push esi
0049817f call 0x498de0
00498184 add esp, 0x10
00498187 test ebx, ebx
00498189 jne 0x4981e9
0049818b mov eax, dword ptr [edi + 0xd2c]
00498191 test eax, eax
00498193 je 0x4981ba
00498195 fld dword ptr [edi + 0x35c]
0049819b fcomp dword ptr [0x5b243c]
004981a1 fnstsw ax
004981a3 test ah, 0x41
004981a6 jne 0x4981ba
004981a8 push 2
004981aa push 8
004981ac push 0x42c80000
004981b1 push edi
004981b2 call 0x494500
004981b7 add esp, 0x10
004981ba mov eax, dword ptr [esi + 0xd2c]
004981c0 test eax, eax
004981c2 je 0x4981e9
004981c4 fld dword ptr [esi + 0x35c]
004981ca fcomp dword ptr [0x5b243c]
004981d0 fnstsw ax
004981d2 test ah, 0x41
004981d5 jne 0x4981e9
004981d7 push 2
004981d9 push 8
004981db push 0x42c80000
004981e0 push esi
004981e1 call 0x494500
004981e6 add esp, 0x10
004981e9 lea edx, [esp + 0xc]
004981ed lea eax, [esp + 0x18]
004981f1 push edx
004981f2 push eax
004981f3 push esi
004981f4 push edi
004981f5 call 0x497b10
004981fa add esp, 0x10
004981fd test eax, eax
004981ff jne 0x498147
00498205 pop edi
00498206 pop esi
00498207 mov eax, 1
0049820c pop ebx
0049820d add esp, 0x18
00498210 ret
00498211 nop
00498212 nop
00498213 nop
00498214 nop
00498215 nop
00498216 nop
00498217 nop
00498218 nop
00498219 nop
0049821a nop
0049821b nop
0049821c nop
0049821d nop
0049821e nop
0049821f nop
00498220 mov eax, dword ptr [0x5e8b58]
00498225 push ebx
00498226 xor ebx, ebx
00498228 xor ecx, ecx
0049822a cmp eax, ebx
0049822c mov dword ptr [0x628f5c], ebx
00498232 jle 0x498253
00498234 mov edx, 0x5e8b34
00498239 mov eax, dword ptr [edx]
0049823b cmp byte ptr [eax + 0x7f], bl
0049823e je 0x498246
00498240 mov dword ptr [eax + 0x110c], ebx
00498246 mov eax, dword ptr [0x5e8b58]
0049824b inc ecx
0049824c add edx, 4
0049824f cmp ecx, eax
00498251 jl 0x498239
00498253 mov ecx, dword ptr [0x5e8b5c]
00498259 xor eax, eax
0049825b cmp ecx, ebx
0049825d jle 0x49827a
0049825f mov ecx, 0x5e8c24
00498264 mov edx, dword ptr [ecx]
00498266 inc eax
00498267 add ecx, 4
0049826a mov dword ptr [edx + 0x110c], ebx
00498270 mov edx, dword ptr [0x5e8b5c]
00498276 cmp eax, edx
00498278 jl 0x498264
0049827a pop ebx
0049827b ret
0049827c nop
0049827d nop
0049827e nop
0049827f nop
00498280 sub esp, 0xc
00498283 mov eax, dword ptr [esp + 0x14]
00498287 push esi
00498288 mov esi, dword ptr [esp + 0x14]
0049828c push edi
0049828d fld dword ptr [eax]
0049828f fsub dword ptr [esi + 0x330]
00498295 lea edi, [esi + 0x364]
0049829b mov dword ptr [esp + 0xc], 0
004982a3 push edi
004982a4 fstp dword ptr [esp + 0xc]
004982a8 fld dword ptr [eax + 8]
004982ab fsub dword ptr [esi + 0x338]
004982b1 lea eax, [esp + 0xc]
004982b5 push eax
004982b6 fstp dword ptr [esp + 0x18]
004982ba call 0x532910
004982bf fcomp dword ptr [0x5b23f8]
004982c5 add esp, 8
004982c8 push edi
004982c9 fnstsw ax
004982cb test ah, 1
004982ce je 0x4982e1
004982d0 lea ecx, [esp + 0xc]
004982d4 push ecx
004982d5 call 0x532910
004982da add esp, 8
004982dd fchs
004982df jmp 0x4982ee
004982e1 lea edx, [esp + 0xc]
004982e5 push edx
004982e6 call 0x532910
004982eb add esp, 8
004982ee fld dword ptr [esp + 0x20]
004982f2 fadd dword ptr [esi + 0x3a8]
004982f8 fxch st(1)
004982fa fcompp
004982fc fnstsw ax
004982fe test ah, 0x41
00498301 jne 0x49830b
00498303 pop edi
00498304 xor eax, eax
00498306 pop esi
00498307 add esp, 0xc
0049830a ret
0049830b lea edi, [esi + 0x37c]
00498311 lea eax, [esp + 8]
00498315 push edi
00498316 push eax
00498317 call 0x532910
0049831c fcomp dword ptr [0x5b23f8]
00498322 add esp, 8
00498325 push edi
00498326 fnstsw ax
00498328 test ah, 1
0049832b je 0x49833e
0049832d lea ecx, [esp + 0xc]
00498331 push ecx
00498332 call 0x532910
00498337 add esp, 8
0049833a fchs
0049833c jmp 0x49834b
0049833e lea edx, [esp + 0xc]
00498342 push edx
00498343 call 0x532910
00498348 add esp, 8
0049834b fld dword ptr [esp + 0x20]
0049834f fadd dword ptr [esi + 0x3b0]
00498355 fxch st(1)
00498357 fcompp
00498359 fnstsw ax
0049835b test ah, 0x41
0049835e jne 0x498368
00498360 pop edi
00498361 xor eax, eax
00498363 pop esi
00498364 add esp, 0xc
00498367 ret
00498368 pop edi
00498369 mov eax, 1
0049836e pop esi
0049836f add esp, 0xc
00498372 ret
00498373 nop
00498374 nop
00498375 nop
00498376 nop
00498377 nop
00498378 nop
00498379 nop
0049837a nop
0049837b nop
0049837c nop
0049837d nop
0049837e nop
0049837f nop
00498380 sub esp, 0xc
00498383 mov ecx, dword ptr [esp + 0x1c]
00498387 mov edx, dword ptr [esp + 0x18]
0049838b push ebx
0049838c push esi
0049838d lea eax, [esp + 8]
00498391 push edi
00498392 push eax
00498393 push ecx
00498394 push edx
00498395 push 1
00498397 mov dword ptr [esp + 0x1c], 0
0049839f mov dword ptr [esp + 0x20], 0
004983a7 mov dword ptr [esp + 0x24], 0
004983af call 0x532330
004983b4 mov ebx, dword ptr [esp + 0x30]
004983b8 lea eax, [esp + 0x1c]
004983bc push eax
004983bd push ebx
004983be call 0x532910
004983c3 fstp dword ptr [esp + 0x40]
004983c7 mov edx, dword ptr [esp + 0x40]
004983cb lea ecx, [esp + 0x24]
004983cf push ecx
004983d0 push edx
004983d1 push ebx
004983d2 push 1
004983d4 call 0x532360
004983d9 mov esi, dword ptr [esp + 0x44]
004983dd push ebx
004983de fld dword ptr [esp + 0x38]
004983e2 fadd dword ptr [esi + 0x330]
004983e8 lea edi, [esi + 0x33c]
004983ee push edi
004983ef fstp dword ptr [esi + 0x330]
004983f5 fld dword ptr [esp + 0x40]
004983f9 fadd dword ptr [esi + 0x334]
004983ff fstp dword ptr [esi + 0x334]
00498405 fld dword ptr [esp + 0x44]
00498409 fadd dword ptr [esi + 0x338]
0049840f fstp dword ptr [esi + 0x338]
00498415 fld dword ptr [esp + 0x3c]
00498419 fadd dword ptr [esi + 0x7f8]
0049841f fstp dword ptr [esi + 0x7f8]
00498425 fld dword ptr [esp + 0x44]
00498429 fadd dword ptr [esi + 0x800]
0049842f fstp dword ptr [esi + 0x800]
00498435 fld dword ptr [esp + 0x3c]
00498439 fadd dword ptr [esi + 0x8bc]
0049843f fstp dword ptr [esi + 0x8bc]
00498445 fld dword ptr [esp + 0x44]
00498449 fadd dword ptr [esi + 0x8c4]
0049844f fstp dword ptr [esi + 0x8c4]
00498455 fld dword ptr [esp + 0x3c]
00498459 fadd dword ptr [esi + 0x980]
0049845f fstp dword ptr [esi + 0x980]
00498465 fld dword ptr [esp + 0x44]
00498469 fadd dword ptr [esi + 0x988]
0049846f fstp dword ptr [esi + 0x988]
00498475 fld dword ptr [esp + 0x3c]
00498479 fadd dword ptr [esi + 0xa44]
0049847f fstp dword ptr [esi + 0xa44]
00498485 fld dword ptr [esp + 0x44]
00498489 fadd dword ptr [esi + 0xa4c]
0049848f fstp dword ptr [esi + 0xa4c]
00498495 call 0x532910
0049849a fchs
0049849c fst dword ptr [esp + 0x54]
004984a0 fmul dword ptr [0x5b2600]
004984a6 add esp, 0x30
004984a9 fcom dword ptr [0x5b23f8]
004984af fnstsw ax
004984b1 test ah, 1
004984b4 je 0x4984b8
004984b6 fchs
004984b8 fstp dword ptr [esi + 0x430]
004984be fld dword ptr [esp + 0xc]
004984c2 fmul dword ptr [0x5b2644]
004984c8 fadd dword ptr [edi]
004984ca fst dword ptr [esp + 0x28]
004984ce fstp dword ptr [edi]
004984d0 fld dword ptr [esp + 0x10]
004984d4 fmul dword ptr [0x5b2644]
004984da fadd dword ptr [esi + 0x340]
004984e0 fstp dword ptr [esi + 0x340]
004984e6 fld dword ptr [esp + 0x14]
004984ea fmul dword ptr [0x5b2644]
004984f0 fadd dword ptr [esi + 0x344]
004984f6 fcom dword ptr [0x5b23f8]
004984fc fst dword ptr [esi + 0x344]
00498502 fnstsw ax
00498504 test ah, 1
00498507 je 0x49850b
00498509 fchs
0049850b fld dword ptr [esp + 0x28]
0049850f fcomp dword ptr [0x5b23f8]
00498515 fld dword ptr [esp + 0x28]
00498519 fnstsw ax
0049851b test ah, 1
0049851e je 0x498522
00498520 fchs
00498522 fcom st(1)
00498524 fnstsw ax
00498526 test ah, 0x41
00498529 jne 0x49853b
0049852b fxch st(1)
0049852d fmul dword ptr [0x5b2468]
00498533 fadd st(1)
00498535 fxch st(1)
00498537 fstp st(0)
00498539 jmp 0x498543
0049853b fmul dword ptr [0x5b2468]
00498541 faddp st(1)
00498543 fdivr dword ptr [esi + 0x35c]
00498549 fst dword ptr [esp + 0x28]
0049854d fcomp dword ptr [0x5b24a8]
00498553 fnstsw ax
00498555 test ah, 1
00498558 je 0x49857b
0049855a mov eax, dword ptr [esp + 0x28]
0049855e push edi
0049855f push eax
00498560 push edi
00498561 push 1
00498563 call 0x532360
00498568 fld dword ptr [esp + 0x38]
0049856c fmul dword ptr [esi + 0x430]
00498572 add esp, 0x10
00498575 fstp dword ptr [esi + 0x430]
0049857b mov ecx, dword ptr [esp + 0x24]
0049857f push ebx
00498580 push ecx
00498581 push esi
00498582 call 0x493f10
00498587 push esi
00498588 call 0x493e40
0049858d fld dword ptr [esi + 0x430]
00498593 fcomp dword ptr [0x5b241c]
00498599 add esp, 0x10
0049859c fnstsw ax
0049859e test ah, 0x41
004985a1 jne 0x498682
004985a7 mov edx, dword ptr [esi + 0x430]
004985ad lea eax, [esi + 0x364]
004985b3 push eax
004985b4 push ebx
004985b5 mov dword ptr [esp + 0x28], edx
004985b9 call 0x532910
004985be fstp dword ptr [esp + 0x30]
004985c2 lea ecx, [esi + 0x37c]
004985c8 push ecx
004985c9 push ebx
004985ca call 0x532910
004985cf fst dword ptr [esp + 0x34]
004985d3 fcomp dword ptr [0x5b49d0]
004985d9 add esp, 0x10
004985dc fnstsw ax
004985de test ah, 1
004985e1 je 0x4985ed
004985e3 mov eax, 1
004985e8 jmp 0x498671
004985ed fld dword ptr [esp + 0x24]
004985f1 fcomp dword ptr [0x5b2610]
004985f7 fnstsw ax
004985f9 test ah, 0x41
004985fc jne 0x498605
004985fe mov eax, 5
00498603 jmp 0x498671
00498605 fld dword ptr [esp + 0x28]
00498609 fcomp dword ptr [0x5b49d0]
0049860f fnstsw ax
00498611 test ah, 1
00498614 je 0x49861d
00498616 mov eax, 3
0049861b jmp 0x498671
0049861d fld dword ptr [esp + 0x28]
00498621 fcomp dword ptr [0x5b2610]
00498627 fnstsw ax
00498629 test ah, 0x41
0049862c jne 0x498635
0049862e mov eax, 7
00498633 jmp 0x498671
00498635 fld dword ptr [esp + 0x24]
00498639 fcomp dword ptr [0x5b23f8]
0049863f fld dword ptr [esp + 0x28]
00498643 fnstsw ax
00498645 fcomp dword ptr [0x5b23f8]
0049864b test ah, 1
0049864e fnstsw ax
00498650 je 0x498662
00498652 test ah, 1
00498655 je 0x49865b
00498657 xor eax, eax
00498659 jmp 0x498671
0049865b mov eax, 2
00498660 jmp 0x498671
00498662 test ah, 1
00498665 mov eax, 6
0049866a jne 0x498671
0049866c mov eax, 4
00498671 mov edx, dword ptr [esp + 0x20]
00498675 push 1
00498677 push eax
00498678 push edx
00498679 push esi
0049867a call 0x494500
0049867f add esp, 0x10
00498682 pop edi
00498683 pop esi
00498684 pop ebx
00498685 add esp, 0xc
00498688 ret
00498689 nop
0049868a nop
0049868b nop
0049868c nop
0049868d nop
0049868e nop
0049868f nop
00498690 sub esp, 0xa4
00498696 push ebx
00498697 push ebp
00498698 push esi
00498699 mov esi, dword ptr [esp + 0xb4]
004986a0 lea eax, [esp + 0x5c]
004986a4 push edi
004986a5 fld dword ptr [esi + 0x3b0]
004986ab push eax
004986ac push ecx
004986ad fstp dword ptr [esp]
004986b0 lea ecx, [esi + 0x37c]
004986b6 mov dword ptr [esp + 0x50], 0
004986be push ecx
004986bf push 1
004986c1 mov dword ptr [esp + 0x60], 0x4479c000
004986c9 mov dword ptr [esp + 0x40], 0
004986d1 mov dword ptr [esp + 0x44], 0
004986d9 mov dword ptr [esp + 0x48], 0
004986e1 mov dword ptr [esp + 0x4c], 0
004986e9 mov dword ptr [esp + 0x50], 0
004986f1 mov dword ptr [esp + 0x54], 0
004986f9 call 0x532360
004986fe fld dword ptr [esi + 0x3a8]
00498704 add esp, 0x10
00498707 lea edx, [esp + 0x54]
0049870b push edx
0049870c push ecx
0049870d lea eax, [esi + 0x364]
00498713 fstp dword ptr [esp]
00498716 push eax
00498717 push 1
00498719 call 0x532360
0049871e fld dword ptr [esi + 0x3ac]
00498724 add esp, 0x10
00498727 lea ecx, [esp + 0x78]
0049872b fchs
0049872d push ecx
0049872e push ecx
0049872f lea edx, [esi + 0x370]
00498735 fstp dword ptr [esp]
00498738 push edx
00498739 push 1
0049873b call 0x532360
00498740 lea eax, [esp + 0x30]
00498744 lea ecx, [esp + 0x88]
0049874b lea ebp, [esi + 0x330]
00498751 push eax
00498752 push ecx
00498753 push ebp
00498754 push 1
00498756 call 0x532300
0049875b lea edx, [esp + 0x34]
0049875f lea eax, [esp + 0x80]
00498766 push edx
00498767 lea ecx, [esp + 0x44]
0049876b push eax
0049876c push ecx
0049876d push 1
0049876f call 0x532300
00498774 lea edx, [esp + 0xb4]
0049877b lea eax, [esp + 0x84]
00498782 push edx
00498783 lea ecx, [esp + 0x48]
00498787 push eax
00498788 push ecx
00498789 push 1
0049878b call 0x532330
00498790 add esp, 0x40
00498793 lea edx, [esp + 0x20]
00498797 lea eax, [esp + 0x78]
0049879b push edx
0049879c push eax
0049879d push ebp
0049879e push 1
004987a0 call 0x532330
004987a5 lea ecx, [esp + 0x24]
004987a9 lea edx, [esp + 0x70]
004987ad push ecx
004987ae push edx
004987af lea eax, [esp + 0x38]
004987b3 push eax
004987b4 push 1
004987b6 call 0x532300
004987bb lea ecx, [esp + 0xb0]
004987c2 lea edx, [esp + 0x74]
004987c6 push ecx
004987c7 lea eax, [esp + 0x38]
004987cb push edx
004987cc push eax
004987cd push 1
004987cf call 0x532300
004987d4 lea ecx, [esp + 0x50]
004987d8 lea edx, [esp + 0xa8]
004987df push ecx
004987e0 push edx
004987e1 push ebp
004987e2 push 1
004987e4 call 0x532330
004987e9 add esp, 0x40
004987ec lea eax, [esp + 0x14]
004987f0 lea ecx, [esp + 0x60]
004987f4 lea edx, [esp + 0x20]
004987f8 push eax
004987f9 push ecx
004987fa push edx
004987fb push 1
004987fd call 0x532330
00498802 lea eax, [esp + 0xac]
00498809 lea ecx, [esp + 0x64]
0049880d push eax
0049880e lea edx, [esp + 0x28]
00498812 push ecx
00498813 push edx
00498814 push 1
00498816 call 0x532330
0049881b lea eax, [esp + 0x40]
0049881f lea ecx, [esp + 0x98]
00498826 push eax
00498827 push ecx
00498828 push ebp
00498829 push 1
0049882b call 0x532300
00498830 lea edx, [esp + 0x44]
00498834 lea eax, [esp + 0x90]
0049883b push edx
0049883c lea ecx, [esp + 0x54]
00498840 push eax
00498841 push ecx
00498842 push 1
00498844 call 0x532330
00498849 add esp, 0x40
0049884c lea edx, [esp + 0xa8]
00498853 lea eax, [esp + 0x54]
00498857 lea ecx, [esp + 0x14]
0049885b push edx
0049885c push eax
0049885d push ecx
0049885e push 1
00498860 call 0x532300
00498865 add esp, 0x10
00498868 mov ebx, 0x5d0b70
0049886d mov eax, dword ptr [ebx - 4]
00498870 mov edi, dword ptr [esp + 0xbc]
00498877 lea ecx, [esp + 0x20]
0049887b mov dword ptr [esp + 0x64], 0
00498883 lea eax, [eax + eax*2]
00498886 mov edx, dword ptr [edi]
00498888 shl eax, 2
0049888b mov dword ptr [esp + 0x70], 0
00498893 fld dword ptr [esp + eax + 0x84]
0049889a fstp dword ptr [esp + 0x60]
0049889e fld dword ptr [esp + eax + 0x8c]
004988a5 mov eax, dword ptr [ebx]
004988a7 fstp dword ptr [esp + 0x68]
004988ab lea eax, [eax + eax*2]
004988ae shl eax, 2
004988b1 fld dword ptr [esp + eax + 0x84]
004988b8 fstp dword ptr [esp + 0x6c]
004988bc fld dword ptr [esp + eax + 0x8c]
004988c3 lea eax, [esp + 0x14]
004988c7 fstp dword ptr [esp + 0x74]
004988cb push eax
004988cc lea eax, [esp + 0x64]
004988d0 push ecx
004988d1 push eax
004988d2 push ebp
004988d3 mov ecx, edi
004988d5 call dword ptr [edx + 0x18]
004988d8 cmp eax, 1
004988db jg 0x498a66
004988e1 jne 0x4989ff
004988e7 fld dword ptr [esi + 0x35c]
004988ed fmul dword ptr [0x5b272c]
004988f3 fld dword ptr [0x5b2604]
004988f9 mov dword ptr [esp + 0x10], 0xc2c60000
00498901 fcomp st(1)
00498903 fnstsw ax
00498905 test ah, 0x41
00498908 jne 0x498916
0049890a fstp st(0)
0049890c mov dword ptr [esp + 0x4c], 0x3dcccccd
00498914 jmp 0x49891a
00498916 fstp dword ptr [esp + 0x4c]
0049891a mov eax, dword ptr [esi + 0x32c]
00498920 xor edi, edi
00498922 test eax, eax
00498924 jle 0x498990
00498926 lea ecx, [esi + 0x1dc]
0049892c mov dword ptr [esp + 0x2c], ecx
00498930 mov ecx, dword ptr [esp + 0x2c]
00498934 lea edx, [esp + 0x54]
00498938 lea eax, [esp + 0x14]
0049893c push edx
0049893d push eax
0049893e push ecx
0049893f push 1
00498941 call 0x532330
00498946 lea edx, [esp + 0x30]
0049894a lea eax, [esp + 0x64]
0049894e push edx
0049894f push eax
00498950 call 0x532910
00498955 fchs
00498957 fcom dword ptr [0x5b49c4]
0049895d add esp, 0x18
00498960 fnstsw ax
00498962 test ah, 0x41
00498965 jne 0x498978
00498967 fcom dword ptr [esp + 0x10]
0049896b fnstsw ax
0049896d test ah, 0x41
00498970 jne 0x498978
00498972 fstp dword ptr [esp + 0x10]
00498976 jmp 0x49897a
00498978 fstp st(0)
0049897a mov ecx, dword ptr [esp + 0x2c]
0049897e mov eax, dword ptr [esi + 0x32c]
00498984 inc edi
00498985 add ecx, 0xc
00498988 cmp edi, eax
0049898a mov dword ptr [esp + 0x2c], ecx
0049898e jl 0x498930
00498990 fld dword ptr [esp + 0x10]
00498994 fcomp dword ptr [esp + 0x50]
00498998 fnstsw ax
0049899a test ah, 1
0049899d je 0x4989ff
0049899f fld dword ptr [esp + 0x10]
004989a3 fcomp dword ptr [0x5b49c4]
004989a9 fnstsw ax
004989ab test ah, 0x41
004989ae jne 0x4989ff
004989b0 fld dword ptr [esp + 0x10]
004989b4 fcomp dword ptr [esp + 0x4c]
004989b8 fnstsw ax
004989ba test ah, 1
004989bd je 0x4989ff
004989bf mov ecx, dword ptr [esp + 0x14]
004989c3 mov edx, dword ptr [esp + 0x18]
004989c7 mov eax, dword ptr [esp + 0x1c]
004989cb mov dword ptr [esp + 0x3c], ecx
004989cf mov ecx, dword ptr [esp + 0x20]
004989d3 mov dword ptr [esp + 0x40], edx
004989d7 mov edx, dword ptr [esp + 0x24]
004989db mov dword ptr [esp + 0x44], eax
004989df mov eax, dword ptr [esp + 0x28]
004989e3 mov dword ptr [esp + 0x30], ecx
004989e7 mov ecx, dword ptr [esp + 0x10]
004989eb mov dword ptr [esp + 0x34], edx
004989ef mov dword ptr [esp + 0x38], eax
004989f3 mov dword ptr [esp + 0x50], ecx
004989f7 mov dword ptr [esp + 0x48], 1
004989ff add ebx, 8
00498a02 cmp ebx, 0x5d0b90
00498a08 jl 0x49886d
00498a0e mov eax, dword ptr [esp + 0x48]
00498a12 test eax, eax
00498a14 je 0x498a5b
00498a16 mov edi, dword ptr [esp + 0xbc]
00498a1d lea edx, [esp + 0x3c]
00498a21 push 0x3dcccccd
00498a26 lea eax, [esp + 0x34]
00498a2a push edx
00498a2b push eax
00498a2c push esi
00498a2d call 0x496610
00498a32 mov ecx, dword ptr [edi + 0x20]
00498a35 mov edx, dword ptr [ebp]
00498a38 mov eax, dword ptr [ebp + 4]
00498a3b or ecx, 0x50000
00498a41 add esp, 0x10
00498a44 mov dword ptr [esi + 0x438], ecx
00498a4a mov ecx, dword ptr [ebp + 8]
00498a4d add esi, 0x440
00498a53 mov dword ptr [esi], edx
00498a55 mov dword ptr [esi + 4], eax
00498a58 mov dword ptr [esi + 8], ecx
00498a5b pop edi
00498a5c pop esi
00498a5d pop ebp
00498a5e pop ebx
00498a5f add esp, 0xa4
00498a65 ret
00498a66 mov edx, dword ptr [esp + 0x14]
00498a6a mov eax, dword ptr [esp + 0x18]
00498a6e mov ecx, dword ptr [esp + 0x1c]
00498a72 mov dword ptr [esp + 0x3c], edx
00498a76 mov edx, dword ptr [esp + 0x20]
00498a7a mov dword ptr [esp + 0x40], eax
00498a7e mov eax, dword ptr [esp + 0x24]
00498a82 mov dword ptr [esp + 0x44], ecx
00498a86 mov ecx, dword ptr [esp + 0x28]
00498a8a mov dword ptr [esp + 0x30], edx
00498a8e mov dword ptr [esp + 0x34], eax
00498a92 mov dword ptr [esp + 0x38], ecx
00498a96 jmp 0x498a1d
00498a98 nop
00498a99 nop
00498a9a nop
00498a9b nop
00498a9c nop
00498a9d nop
00498a9e nop
00498a9f nop
00498aa0 sub esp, 0x4c
00498aa3 push esi
00498aa4 mov esi, dword ptr [esp + 0x54]
00498aa8 push edi
00498aa9 mov edi, dword ptr [esp + 0x5c]
00498aad lea eax, [esi + 0x330]
00498ab3 mov dword ptr [esp + 0xc], 0
00498abb mov dword ptr [esp + 0x10], 0
00498ac3 mov dword ptr [esp + 0x14], 0
00498acb mov ecx, dword ptr [eax]
00498acd mov dword ptr [esp + 0x18], 0
00498ad5 mov dword ptr [esp + 0x24], ecx
00498ad9 mov ecx, edi
00498adb mov edx, dword ptr [eax + 4]
00498ade mov dword ptr [esp + 0x1c], 0
00498ae6 mov dword ptr [esp + 0x28], edx
00498aea mov edx, dword ptr [edi]
00498aec mov eax, dword ptr [eax + 8]
00498aef mov dword ptr [esp + 0x20], 0
00498af7 mov dword ptr [esp + 0x2c], eax
00498afb lea eax, [esp + 0x48]
00498aff push eax
00498b00 mov dword ptr [esp + 0x34], 0
00498b08 mov dword ptr [esp + 0x38], 0
00498b10 mov dword ptr [esp + 0x3c], 0
00498b18 call dword ptr [edx + 4]
00498b1b lea ecx, [esp + 0xc]
00498b1f lea edx, [esp + 0x48]
00498b23 push ecx
00498b24 lea eax, [esp + 0x28]
00498b28 push edx
00498b29 push eax
00498b2a push 1
00498b2c mov dword ptr [esp + 0x5c], 0
00498b34 mov dword ptr [esp + 0x38], 0
00498b3c call 0x532330
00498b41 lea ecx, [esp + 0x1c]
00498b45 push ecx
00498b46 call 0x532b20
00498b4b fcomp dword ptr [0x5b27a8]
00498b51 add esp, 0x14
00498b54 fnstsw ax
00498b56 test ah, 0x41
00498b59 jne 0x498dd8
00498b5f lea edx, [esp + 0xc]
00498b63 push ebx
00498b64 lea eax, [esp + 0x10]
00498b68 push edx
00498b69 push eax
00498b6a call 0x5328d0
00498b6f fld dword ptr [esp + 0x30]
00498b73 fsub dword ptr [esp + 0x54]
00498b77 lea ecx, [esp + 0x48]
00498b7b mov dword ptr [esp + 0x4c], 0
00498b83 push ecx
00498b84 fstp dword ptr [esp + 0x4c]
00498b88 fld dword ptr [esp + 0x3c]
00498b8c fsub dword ptr [esp + 0x60]
00498b90 fstp dword ptr [esp + 0x54]
00498b94 call 0x532b20
00498b99 mov edx, dword ptr [edi]
00498b9b add esp, 0xc
00498b9e fstp dword ptr [esp + 0x60]
00498ba2 mov ecx, edi
00498ba4 call dword ptr [edx + 0x14]
00498ba7 fstp dword ptr [esp + 0xc]
00498bab lea ebx, [esi + 0x364]
00498bb1 lea eax, [esp + 0x10]
00498bb5 push ebx
00498bb6 push eax
00498bb7 call 0x532910
00498bbc fcomp dword ptr [0x5b23f8]
00498bc2 add esp, 8
00498bc5 push ebx
00498bc6 fnstsw ax
00498bc8 test ah, 1
00498bcb je 0x498bde
00498bcd lea ecx, [esp + 0x14]
00498bd1 push ecx
00498bd2 call 0x532910
00498bd7 add esp, 8
00498bda fchs
00498bdc jmp 0x498beb
00498bde lea edx, [esp + 0x14]
00498be2 push edx
00498be3 call 0x532910
00498be8 add esp, 8
00498beb fcom dword ptr [0x5b2604]
00498bf1 fnstsw ax
00498bf3 test ah, 0x41
00498bf6 jne 0x498c08
00498bf8 fld dword ptr [esi + 0x3a8]
00498bfe fdiv st(1)
00498c00 fstp dword ptr [esp + 0x5c]
00498c04 fstp st(0)
00498c06 jmp 0x498c12
00498c08 fstp st(0)
00498c0a mov dword ptr [esp + 0x5c], 0x41200000
00498c12 lea ebx, [esi + 0x37c]
00498c18 lea eax, [esp + 0x10]
00498c1c push ebx
00498c1d push eax
00498c1e call 0x532910
00498c23 fcomp dword ptr [0x5b23f8]
00498c29 add esp, 8
00498c2c push ebx
00498c2d fnstsw ax
00498c2f test ah, 1
00498c32 je 0x498c45
00498c34 lea ecx, [esp + 0x14]
00498c38 push ecx
00498c39 call 0x532910
00498c3e add esp, 8
00498c41 fchs
00498c43 jmp 0x498c52
00498c45 lea edx, [esp + 0x14]
00498c49 push edx
00498c4a call 0x532910
00498c4f add esp, 8
00498c52 fcom dword ptr [0x5b2604]
00498c58 pop ebx
00498c59 fnstsw ax
00498c5b test ah, 0x41
00498c5e jne 0x498c68
00498c60 fdivr dword ptr [esi + 0x3b0]
00498c66 jmp 0x498c70
00498c68 fstp st(0)
00498c6a fld dword ptr [0x5b241c]
00498c70 fld dword ptr [esp + 0x58]
00498c74 fcomp st(1)
00498c76 fnstsw ax
00498c78 test ah, 0x41
00498c7b jne 0x498c83
00498c7d fstp dword ptr [esp + 0x58]
00498c81 jmp 0x498c8d
00498c83 mov eax, dword ptr [esp + 0x58]
00498c87 fstp st(0)
00498c89 mov dword ptr [esp + 0x58], eax
00498c8d fld dword ptr [esp + 0x58]
00498c91 fadd dword ptr [esp + 8]
00498c95 fcomp dword ptr [esp + 0x5c]
00498c99 fnstsw ax
00498c9b test ah, 0x41
00498c9e jne 0x498dd8
00498ca4 fld dword ptr [esi + 0x35c]
00498caa fcomp dword ptr [0x5b2400]
00498cb0 fnstsw ax
00498cb2 test ah, 0x41
00498cb5 jne 0x498d2d
00498cb7 lea ecx, [esi + 0x33c]
00498cbd mov edx, dword ptr [esi + 0x33c]
00498cc3 mov dword ptr [esp + 0x3c], edx
00498cc7 lea edx, [esp + 0x3c]
00498ccb mov eax, dword ptr [ecx + 4]
00498cce push edx
00498ccf mov dword ptr [esp + 0x44], eax
00498cd3 lea eax, [esp + 0x40]
00498cd7 mov ecx, dword ptr [ecx + 8]
00498cda push eax
00498cdb mov dword ptr [esp + 0x4c], ecx
00498cdf call 0x5328d0
00498ce4 lea ecx, [esp + 0x44]
00498ce8 lea edx, [esp + 0x14]
00498cec push ecx
00498ced push edx
00498cee call 0x532910
00498cf3 fcomp dword ptr [0x5b23f0]
00498cf9 add esp, 0x10
00498cfc fnstsw ax
00498cfe test ah, 0x41
00498d01 jne 0x498d2d
00498d03 fld dword ptr [esp + 0x5c]
00498d07 fcomp dword ptr [0x5b260c]
00498d0d fnstsw ax
00498d0f test ah, 1
00498d12 je 0x498d2d
00498d14 lea eax, [esp + 0xc]
00498d18 lea ecx, [esp + 0xc]
00498d1c push eax
00498d1d push 0xbf800000
00498d22 push ecx
00498d23 push 1
00498d25 call 0x532360
00498d2a add esp, 0x10
00498d2d mov eax, dword ptr [esp + 8]
00498d31 lea edx, [esp + 0x18]
00498d35 push edx
00498d36 lea ecx, [esp + 0x10]
00498d3a push eax
00498d3b push ecx
00498d3c push 1
00498d3e call 0x532360
00498d43 lea edx, [esp + 0x28]
00498d47 lea eax, [esp + 0x28]
00498d4b push edx
00498d4c lea ecx, [esp + 0x5c]
00498d50 push eax
00498d51 push ecx
00498d52 push 1
00498d54 call 0x532300
00498d59 fld dword ptr [esp + 0x78]
00498d5d add esp, 0x20
00498d60 lea edx, [esp + 0x30]
00498d64 fchs
00498d66 push edx
00498d67 push ecx
00498d68 lea eax, [esp + 0x14]
00498d6c fstp dword ptr [esp]
00498d6f push eax
00498d70 push 1
00498d72 call 0x532360
00498d77 lea ecx, [esp + 0x40]
00498d7b lea edx, [esp + 0x40]
00498d7f push ecx
00498d80 lea eax, [esp + 0x38]
00498d84 push edx
00498d85 push eax
00498d86 push 1
00498d88 call 0x532300
00498d8d lea ecx, [esp + 0x50]
00498d91 lea edx, [esp + 0x38]
00498d95 push ecx
00498d96 lea eax, [esp + 0x30]
00498d9a push edx
00498d9b push eax
00498d9c push esi
00498d9d call 0x498380
00498da2 mov ecx, dword ptr [edi + 0x20]
00498da5 mov edx, dword ptr [esp + 0x48]
00498da9 mov eax, dword ptr [esp + 0x4c]
00498dad or ecx, 0x50000
00498db3 add esp, 0x30
00498db6 mov dword ptr [esi + 0x438], ecx
00498dbc mov dword ptr [esi + 0x434], 0
00498dc6 mov ecx, dword ptr [esp + 0x20]
00498dca add esi, 0x440
00498dd0 mov dword ptr [esi], edx
00498dd2 mov dword ptr [esi + 4], eax
00498dd5 mov dword ptr [esi + 8], ecx
00498dd8 pop edi
00498dd9 pop esi
00498dda add esp, 0x4c
00498ddd ret
00498dde nop
00498ddf nop
00498de0 sub esp, 0xc
00498de3 push ebp
00498de4 push edi
00498de5 mov edi, dword ptr [esp + 0x18]
00498de9 mov eax, dword ptr [edi + 0x43c]
00498def test eax, eax
00498df1 jne 0x498fdf
00498df7 lea eax, [edi + 0x330]
00498dfd push 0x40a00000
00498e02 push eax
00498e03 lea ecx, [edi + 8]
00498e06 call 0x473870
00498e0b mov ebp, eax
00498e0d test ebp, ebp
00498e0f je 0x498fdf
00498e15 mov eax, dword ptr [ebp]
00498e18 mov ecx, dword ptr [ebp + 4]
00498e1b push ebx
00498e1c sub ecx, eax
00498e1e xor ebx, ebx
00498e20 push esi
00498e21 sar ecx, 2
00498e24 je 0x498f6d
00498e2a mov esi, dword ptr [eax + ebx*4]
00498e2d lea eax, [esp + 0x10]
00498e31 push eax
00498e32 mov ecx, esi
00498e34 mov edx, dword ptr [esi]
00498e36 call dword ptr [edx + 4]
00498e39 mov edx, dword ptr [esi]
00498e3b mov ecx, esi
00498e3d call dword ptr [edx + 0x14]
00498e40 fstp dword ptr [esp + 0x20]
00498e44 mov eax, dword ptr [esp + 0x20]
00498e48 lea ecx, [esp + 0x10]
00498e4c push eax
00498e4d push ecx
00498e4e push edi
00498e4f call 0x498280
00498e54 add esp, 0xc
00498e57 test eax, eax
00498e59 je 0x498f59
00498e5f mov edx, dword ptr [esi]
00498e61 lea eax, [edi + 0x33c]
00498e67 push eax
00498e68 mov ecx, esi
00498e6a call dword ptr [edx + 0x20]
00498e6d test eax, eax
00498e6f je 0x498f59
00498e75 cmp eax, 2
00498e78 jne 0x498ed2
00498e7a push 0
00498e7c push 0x5d0590
00498e81 push 0x5d0570
00498e86 push 0
00498e88 push esi
00498e89 call 0x5a134b
00498e8e add esp, 0x14
00498e91 test eax, eax
00498e93 je 0x498ea4
00498e95 push esi
00498e96 push edi
00498e97 call 0x498aa0
00498e9c add esp, 8
00498e9f jmp 0x498f59
00498ea4 push 0
00498ea6 push 0x5d05b8
00498eab push 0x5d0570
00498eb0 push 0
00498eb2 push esi
00498eb3 call 0x5a134b
00498eb8 add esp, 0x14
00498ebb test eax, eax
00498ebd je 0x498f59
00498ec3 push esi
00498ec4 push edi
00498ec5 call 0x498690
00498eca add esp, 8
00498ecd jmp 0x498f59
00498ed2 cmp eax, 3
00498ed5 jne 0x498f1c
00498ed7 fld dword ptr [edi + 0x35c]
00498edd fcomp dword ptr [0x5b2580]
00498ee3 fnstsw ax
00498ee5 test ah, 0x41
00498ee8 jne 0x498f59
00498eea lea eax, [edi + 0x330]
00498ef0 lea ecx, [edi + 0x440]
00498ef6 mov dword ptr [edi + 0x430], 0x41700000
00498f00 mov dword ptr [edi + 0x438], 0x6000f
00498f0a mov edx, dword ptr [eax]
00498f0c mov dword ptr [ecx], edx
00498f0e mov edx, dword ptr [eax + 4]
00498f11 mov dword ptr [ecx + 4], edx
00498f14 mov eax, dword ptr [eax + 8]
00498f17 mov dword ptr [ecx + 8], eax
00498f1a jmp 0x498f59
00498f1c cmp eax, 1
00498f1f jne 0x498f59
00498f21 mov ecx, dword ptr [edi + 0x44c]
00498f27 lea eax, [edi + 0x330]
00498f2d or ecx, 0x50000
00498f33 lea edx, [edi + 0x440]
00498f39 mov dword ptr [edi + 0x438], ecx
00498f3f mov ecx, dword ptr [eax]
00498f41 mov dword ptr [edx], ecx
00498f43 mov dword ptr [edi + 0x430], 0x41700000
00498f4d mov ecx, dword ptr [eax + 4]
00498f50 mov dword ptr [edx + 4], ecx
00498f53 mov eax, dword ptr [eax + 8]
00498f56 mov dword ptr [edx + 8], eax
00498f59 mov eax, dword ptr [ebp]
00498f5c mov ecx, dword ptr [ebp + 4]
00498f5f sub ecx, eax
00498f61 inc ebx
00498f62 sar ecx, 2
00498f65 cmp ebx, ecx
00498f67 jb 0x498e2a
00498f6d mov edi, dword ptr [ebp]
00498f70 mov eax, dword ptr [ebp + 8]
00498f73 sub eax, edi
00498f75 mov dword ptr [esp + 0x20], edi
00498f79 sar eax, 2
00498f7c je 0x498fd4
00498f7e mov edx, dword ptr [0x5e4fe8]
00498f84 lea ebx, [eax*4]
00498f8b cmp ebx, 0x100
00498f91 lea esi, [edx + 0x28]
00498f94 jbe 0x498fb0
00498f96 push edi
00498f97 call 0x59ecd0
00498f9c add esp, 4
00498f9f push ebp
00498fa0 call 0x59f050
00498fa5 add esp, 4
00498fa8 pop esi
00498fa9 pop ebx
00498faa pop edi
00498fab pop ebp
00498fac add esp, 0xc
00498faf ret
00498fb0 mov eax, dword ptr [esi]
00498fb2 push eax
00498fb3 call 0x5322b0
00498fb8 lea eax, [ebx - 1]
00498fbb shr eax, 3
00498fbe mov ecx, dword ptr [esi + eax*4 + 0xc]
00498fc2 mov dword ptr [edi + 4], ecx
00498fc5 mov dword ptr [esi + eax*4 + 0xc], edi
00498fc9 mov edx, dword ptr [esi]
00498fcb push edx
00498fcc call 0x5322c0
00498fd1 add esp, 8
00498fd4 push ebp
00498fd5 call 0x59f050
00498fda add esp, 4
00498fdd pop esi
00498fde pop ebx
00498fdf pop edi
00498fe0 pop ebp
00498fe1 add esp, 0xc
00498fe4 ret
00498fe5 nop
00498fe6 nop
00498fe7 nop
00498fe8 nop
00498fe9 nop
00498fea nop
00498feb nop
00498fec nop
00498fed nop
00498fee nop
00498fef nop
00498ff0 sub esp, 8
00498ff3 push ebx
00498ff4 mov ebx, dword ptr [esp + 0x10]
00498ff8 mov al, byte ptr [ebx + 0x7f]
00498ffb test al, al
00498ffd je 0x49918c
00499003 mov al, byte ptr [ebx + 0x7d]
00499006 test al, al
00499008 jne 0x49918c
0049900e mov eax, dword ptr [ebx + 0x43c]
00499014 test eax, eax
00499016 jle 0x49901f
00499018 dec eax
00499019 mov dword ptr [ebx + 0x43c], eax
0049901f mov al, byte ptr [ebx + 0x7c]
00499022 test al, al
00499024 je 0x499035
00499026 push ebx
00499027 call 0x495020
0049902c push ebx
0049902d call 0x498de0
00499032 add esp, 8
00499035 mov eax, dword ptr [0x657408]
0049903a test eax, eax
0049903c je 0x49904b
0049903e mov eax, dword ptr [0x65740c]
00499043 test eax, eax
00499045 jne 0x49918c
0049904b mov ecx, dword ptr [0x628f5c]
00499051 mov dword ptr [esp + 8], 0
00499059 test ecx, ecx
0049905b mov dword ptr [ecx*4 + 0x628cdc], ebx
00499062 jle 0x499185
00499068 push ebp
00499069 push esi
0049906a push edi
0049906b mov dword ptr [esp + 0x10], 0x628cdc
00499073 mov eax, dword ptr [esp + 0x10]
00499077 fld dword ptr [ebx + 0x338]
0049907d mov ebp, dword ptr [eax]
0049907f fsub dword ptr [ebp + 0x338]
00499085 fcom dword ptr [0x5b23f8]
0049908b fnstsw ax
0049908d test ah, 1
00499090 je 0x499094
00499092 fchs
00499094 fld dword ptr [ebp + 0x3b4]
0049909a fadd dword ptr [ebx + 0x3b4]
004990a0 fstp dword ptr [esp + 0x1c]
004990a4 fcomp dword ptr [esp + 0x1c]
004990a8 fnstsw ax
004990aa test ah, 1
004990ad je 0x499166
004990b3 fld dword ptr [ebx + 0x330]
004990b9 fsub dword ptr [ebp + 0x330]
004990bf fcom dword ptr [0x5b23f8]
004990c5 fnstsw ax
004990c7 test ah, 1
004990ca je 0x4990ce
004990cc fchs
004990ce fcomp dword ptr [esp + 0x1c]
004990d2 fnstsw ax
004990d4 test ah, 1
004990d7 je 0x499166
004990dd fld dword ptr [ebx + 0x334]
004990e3 fsub dword ptr [ebp + 0x334]
004990e9 fcom dword ptr [0x5b23f8]
004990ef fnstsw ax
004990f1 test ah, 1
004990f4 je 0x4990f8
004990f6 fchs
004990f8 fcomp dword ptr [esp + 0x1c]
004990fc fnstsw ax
004990fe test ah, 1
00499101 je 0x499166
00499103 lea esi, [ebx + 0x388]
00499109 push esi
0049910a push 0x40c90fdb
0049910f push esi
00499110 push 1
00499112 call 0x532360
00499117 lea edi, [ebp + 0x388]
0049911d push edi
0049911e push 0x40c90fdb
00499123 push edi
00499124 push 1
00499126 call 0x532360
0049912b push ebp
0049912c push ebx
0049912d call 0x4980d0
00499132 push esi
00499133 push 0x3e22f981
00499138 push esi
00499139 push 1
0049913b call 0x532360
00499140 push edi
00499141 push 0x3e22f981
00499146 push edi
00499147 push 1
00499149 call 0x532360
0049914e add esp, 0x48
00499151 push ebx
00499152 call 0x4964d0
00499157 push ebp
00499158 call 0x4964d0
0049915d mov ecx, dword ptr [0x628f5c]
00499163 add esp, 8
00499166 mov eax, dword ptr [esp + 0x14]
0049916a mov esi, dword ptr [esp + 0x10]
0049916e inc eax
0049916f add esi, 4
00499172 cmp eax, ecx
00499174 mov dword ptr [esp + 0x14], eax
00499178 mov dword ptr [esp + 0x10], esi
0049917c jl 0x499073
00499182 pop edi
00499183 pop esi
00499184 pop ebp
00499185 inc ecx
00499186 mov dword ptr [0x628f5c], ecx
0049918c pop ebx
0049918d add esp, 8
00499190 ret
00499191 nop
00499192 nop
00499193 nop
00499194 nop
00499195 nop
00499196 nop
00499197 nop
00499198 nop
00499199 nop
0049919a nop
0049919b nop
0049919c nop
0049919d nop
0049919e nop
0049919f nop
004991a0 push ecx
004991a1 mov dword ptr [esp], 0x800000
004991a9 mov eax, dword ptr [esp]
004991ad mov dword ptr [0x628f64], eax
004991b2 pop ecx
004991b3 ret
004991b4 nop
004991b5 nop
004991b6 nop
004991b7 nop
004991b8 nop
004991b9 nop
004991ba nop
004991bb nop
004991bc nop
004991bd nop
004991be nop
004991bf nop
004991c0 fld dword ptr [0x5b24a8]
004991c6 fdiv dword ptr [0x628f64]
004991cc fstp dword ptr [0x628f60]
004991d2 ret
004991d3 nop
004991d4 nop
004991d5 nop
004991d6 nop
004991d7 nop
004991d8 nop
004991d9 nop
004991da nop
004991db nop
004991dc nop
004991dd nop
004991de nop
004991df nop
004991e0 mov eax, dword ptr [0x5e8e28]
004991e5 push esi
004991e6 mov esi, dword ptr [esp + 8]
004991ea push edi
004991eb xor edi, edi
004991ed cmp eax, edi
004991ef jle 0x4991fe
004991f1 cmp dword ptr [esi + 0x520], edi
004991f7 jne 0x4991fe
004991f9 call 0x516950
004991fe test byte ptr [esi + 0x52c], 4
00499205 je 0x499211
00499207 push esi
00499208 call dword ptr [esi + 0xe10]
0049920e add esp, 4
00499211 mov al, byte ptr [0x5e9664]
00499216 mov byte ptr [esi + 0xd8a], al
0049921c mov eax, dword ptr [esi + 0xda8]
00499222 cmp eax, edi
00499224 je 0x499285
00499226 push esi
00499227 call 0x40b650
0049922c push esi
0049922d call 0x40bfe0
00499232 mov eax, dword ptr [0x657408]
00499237 add esp, 8
0049923a cmp eax, edi
0049923c je 0x499255
0049923e cmp dword ptr [esi + 0xdac], edi
00499244 je 0x499255
00499246 cmp dword ptr [esi + 0x70], 1
0049924a jne 0x499255
0049924c push esi
0049924d call 0x4a0680
00499252 add esp, 4
00499255 mov cl, byte ptr [esi + 0xd9c]
0049925b mov edx, dword ptr [esi + 0xda0]
00499261 mov al, byte ptr [esi + 0xd9d]
00499267 mov byte ptr [esi + 0xd7c], cl
0049926d mov dword ptr [esi + 0xd90], edx
00499273 mov byte ptr [esi + 0xd7d], al
00499279 mov byte ptr [esi + 0xd86], 0
00499280 jmp 0x499336
00499285 cmp dword ptr [esi + 0xdac], edi
0049928b je 0x4992cf
0049928d mov ecx, dword ptr [esi + 0x74]
00499290 push ecx
00499291 call 0x5322b0
00499296 movsx eax, byte ptr [esi + 0x38]
0049929a mov dl, byte ptr [esi + 0x3a]
0049929d mov dword ptr [esi + 0xd90], eax
004992a3 mov al, byte ptr [esi + 0x3b]
004992a6 mov byte ptr [esi + 0xd7d], dl
004992ac mov edx, dword ptr [esi + 0x74]
004992af mov cl, al
004992b1 shr al, 1
004992b3 and cl, 1
004992b6 and al, 1
004992b8 push edx
004992b9 mov byte ptr [esi + 0xd85], cl
004992bf mov byte ptr [esi + 0xd86], al
004992c5 call 0x5322c0
004992ca add esp, 8
004992cd jmp 0x499336
004992cf mov al, byte ptr [0x5e9666]
004992d4 shl al, 1
004992d6 mov byte ptr [esi + 0xd7c], al
004992dc mov cl, byte ptr [0x5e9667]
004992e2 shl cl, 1
004992e4 mov byte ptr [esi + 0xd7d], cl
004992ea mov eax, dword ptr [0x65742c]
004992ef cmp eax, 1
004992f2 jne 0x499307
004992f4 movsx edx, byte ptr [0x5e9665]
004992fb neg edx
004992fd shl edx, 1
004992ff mov dword ptr [esi + 0xd90], edx
00499305 jmp 0x499316
00499307 movsx eax, byte ptr [0x5e9665]
0049930e shl eax, 1
00499310 mov dword ptr [esi + 0xd90], eax
00499316 mov cl, byte ptr [0x5e9664]
0049931c and cl, 1
0049931f mov byte ptr [esi + 0xd85], cl
00499325 mov dl, byte ptr [0x5e9664]
0049932b shr dl, 1
0049932d and dl, 1
00499330 mov byte ptr [esi + 0xd86], dl
00499336 mov al, byte ptr [0x5e9664]
0049933b shr al, 3
0049933e movsx ecx, al
00499341 add ecx, -7
00499344 mov byte ptr [esi + 0xd8b], al
0049934a cmp ecx, 8
0049934d ja 0x499435
00499353 jmp dword ptr [ecx*4 + 0x499480]
0049935a mov byte ptr [esi + 0xd8c], al
00499360 jmp 0x499435
00499365 mov al, byte ptr [esi + 0xd87]
0049936b test al, 0x10
0049936d je 0x49937f
0049936f xor al, 0x10
00499371 test al, 8
00499373 mov byte ptr [esi + 0xd87], al
00499379 jne 0x49947b
0049937f mov cl, byte ptr [esi + 0xd87]
00499385 mov word ptr [esi + 0x1232], di
0049938c xor cl, 8
0049938f or byte ptr [esi + 0x1230], 0x80
00499396 mov byte ptr [esi + 0xd87], cl
0049939c jmp 0x499435
004993a1 mov al, byte ptr [esi + 0xd87]
004993a7 test al, 8
004993a9 je 0x4993bb
004993ab xor al, 8
004993ad test al, 0x10
004993af mov byte ptr [esi + 0xd87], al
004993b5 jne 0x49947b
004993bb mov cl, byte ptr [esi + 0xd87]
004993c1 mov word ptr [esi + 0x1230], di
004993c8 xor cl, 0x10
004993cb or byte ptr [esi + 0x1232], 0x80
004993d2 mov byte ptr [esi + 0xd87], cl
004993d8 jmp 0x499435
004993da mov al, byte ptr [esi + 0xd87]
004993e0 test al, 8
004993e2 je 0x499400
004993e4 test al, 0x10
004993e6 je 0x499400
004993e8 xor al, 0x18
004993ea mov word ptr [esi + 0x1230], di
004993f1 mov byte ptr [esi + 0xd87], al
004993f7 mov word ptr [esi + 0x1232], di
004993fe jmp 0x499435
00499400 or al, 0x18
00499402 mov byte ptr [esi + 0xd87], al
00499408 mov eax, 0x80
0049940d or word ptr [esi + 0x1230], ax
00499414 or word ptr [esi + 0x1232], ax
0049941b jmp 0x499435
0049941d mov al, byte ptr [esi + 0xd87]
00499423 xor al, 3
00499425 jmp 0x49942f
00499427 mov al, byte ptr [esi + 0xd87]
0049942d xor al, 4
0049942f mov byte ptr [esi + 0xd87], al
00499435 mov eax, dword ptr [esi + 0x760]
0049943b mov dl, byte ptr [esi + 0xd82]
00499441 mov ecx, dword ptr [eax + 0x50]
00499444 push ecx
00499445 push edx
00499446 call 0x413890
0049944b fld dword ptr [esi + 0xdb4]
00499451 movsx ecx, al
00499454 mov eax, dword ptr [esi + 0x760]
0049945a add esp, 8
0049945d fcomp dword ptr [eax + 0x94]
00499463 fnstsw ax
00499465 test ah, 0x41
00499468 jne 0x499475
0049946a movsx edx, byte ptr [esi + 0xd82]
00499471 cmp ecx, edx
00499473 jl 0x49947b
00499475 mov byte ptr [esi + 0xd7e], cl
0049947b pop edi
0049947c pop esi
0049947d ret
0049947e mov edi, edi
00499480 pop edx
00499481 xchg ebx, eax
00499482 dec ecx
00499483 add byte ptr [edx - 0x6d], bl
00499486 dec ecx
00499487 add byte ptr [edx - 0x6d], bl
0049948a dec ecx
0049948b add byte ptr [ebp - 0x6d], ah
0049948e dec ecx
0049948f add byte ptr [ecx - 0x25ffb66d], ah
00499495 xchg ebx, eax
00499496 dec ecx
00499497 add byte ptr [0x35004994], bl
0049949d xchg esp, eax
0049949e dec ecx
0049949f add byte ptr [edi], ah
004994a1 xchg esp, eax
004994a2 dec ecx
004994a3 add byte ptr [eax - 0x6f6f6f70], dl
004994a9 nop
004994aa nop
004994ab nop
004994ac nop
004994ad nop
004994ae nop
004994af nop
004994b0 push ecx
004994b1 mov dword ptr [esp], 0x800000
004994b9 mov eax, dword ptr [esp]
004994bd mov dword ptr [0x628f7c], eax
004994c2 pop ecx
004994c3 ret
004994c4 nop
004994c5 nop
004994c6 nop
004994c7 nop
004994c8 nop
004994c9 nop
004994ca nop
004994cb nop
004994cc nop
004994cd nop
004994ce nop
004994cf nop
004994d0 fld dword ptr [0x5b24a8]
004994d6 fdiv dword ptr [0x628f7c]
004994dc fstp dword ptr [0x628f68]
004994e2 ret
004994e3 nop
004994e4 nop
004994e5 nop
004994e6 nop
004994e7 nop
004994e8 nop
004994e9 nop
004994ea nop
004994eb nop
004994ec nop
004994ed nop
004994ee nop
004994ef nop
004994f0 mov eax, dword ptr [esp + 4]
004994f4 push esi
004994f5 push edi
004994f6 lea esi, [eax + 0x330]
004994fc lea edi, [eax + 8]
004994ff push esi
00499500 mov ecx, edi
00499502 call 0x474440
00499507 push 1
00499509 push esi
0049950a mov ecx, edi
0049950c call 0x474060
00499511 pop edi
00499512 pop esi
00499513 ret
00499514 nop
00499515 nop
00499516 nop
00499517 nop
00499518 nop
00499519 nop
0049951a nop
0049951b nop
0049951c nop
0049951d nop
0049951e nop
0049951f nop
00499520 sub esp, 0x1c
00499523 push ebx
00499524 push ebp
00499525 mov ebp, dword ptr [0x628bc0]
0049952b push esi
0049952c mov esi, dword ptr [esp + 0x2c]
00499530 push edi
00499531 mov al, byte ptr [esi + 0x7f]
00499534 test al, al
00499536 je 0x499724
0049953c lea edi, [esi + 0x400]
00499542 xor ebx, ebx
00499544 mov eax, edi
00499546 mov ecx, dword ptr [eax]
00499548 mov dword ptr [esp + 0x20], ecx
0049954c mov edx, dword ptr [eax + 4]
0049954f mov dword ptr [esp + 0x24], edx
00499553 mov eax, dword ptr [eax + 8]
00499556 mov dword ptr [esi + 0x408], ebx
0049955c mov dword ptr [esp + 0x28], eax
00499560 mov dword ptr [esi + 0x404], ebx
00499566 mov dword ptr [edi], ebx
00499568 mov al, byte ptr [esi + 0x12]
0049956b test al, al
0049956d jne 0x4995f8
00499573 jmp 0x499577
00499575 fstp st(0)
00499577 push ebx
00499578 lea ecx, [esi + 8]
0049957b call 0x4745f0
00499580 mov ecx, dword ptr [eax]
00499582 inc ebx
00499583 mov dword ptr [esp + 0x14], ecx
00499587 cmp ebx, 4
0049958a fld dword ptr [esp + 0x14]
0049958e fadd dword ptr [edi]
00499590 mov edx, dword ptr [eax + 4]
00499593 mov dword ptr [esp + 0x18], edx
00499597 mov eax, dword ptr [eax + 8]
0049959a fst dword ptr [edi]
0049959c fld dword ptr [esp + 0x18]
004995a0 fadd dword ptr [esi + 0x404]
004995a6 mov dword ptr [esp + 0x1c], eax
004995aa fst dword ptr [esp + 0x30]
004995ae fstp dword ptr [esi + 0x404]
004995b4 fld dword ptr [esp + 0x1c]
004995b8 fadd dword ptr [esi + 0x408]
004995be fst dword ptr [esp + 0x10]
004995c2 fstp dword ptr [esi + 0x408]
004995c8 jl 0x499575
004995ca fmul dword ptr [0x5b2468]
004995d0 lea edi, [esi + 0x400]
004995d6 fstp dword ptr [edi]
004995d8 fld dword ptr [esp + 0x30]
004995dc fmul dword ptr [0x5b2468]
004995e2 fstp dword ptr [esi + 0x404]
004995e8 fld dword ptr [esp + 0x10]
004995ec fmul dword ptr [0x5b2468]
004995f2 fstp dword ptr [esi + 0x408]
004995f8 fld dword ptr [edi]
004995fa fcomp dword ptr [0x5b23f8]
00499600 fnstsw ax
00499602 test ah, 0x40
00499605 je 0x499643
00499607 fld dword ptr [edi + 4]
0049960a fcomp dword ptr [0x5b23f8]
00499610 fnstsw ax
00499612 test ah, 0x40
00499615 je 0x499643
00499617 fld dword ptr [edi + 8]
0049961a fcomp dword ptr [0x5b23f8]
00499620 fnstsw ax
00499622 test ah, 0x40
00499625 je 0x499643
00499627 mov ecx, dword ptr [esp + 0x20]
0049962b mov edx, dword ptr [esp + 0x24]
0049962f mov eax, dword ptr [esp + 0x28]
00499633 mov dword ptr [edi], ecx
00499635 mov dword ptr [edi + 4], edx
00499638 mov dword ptr [edi + 8], eax
0049963b pop edi
0049963c pop esi
0049963d pop ebp
0049963e pop ebx
0049963f add esp, 0x1c
00499642 ret
00499643 mov al, byte ptr [esi + 0x11]
00499646 test al, al
00499648 je 0x499724
0049964e lea edi, [esi + 8]
00499651 lea ebx, [esi + 0x3e8]
00499657 mov ecx, edi
00499659 call 0x474420
0049965e mov edx, dword ptr [eax]
00499660 mov ecx, ebx
00499662 mov dword ptr [ecx], edx
00499664 mov edx, dword ptr [eax + 4]
00499667 mov dword ptr [ecx + 4], edx
0049966a mov eax, dword ptr [eax + 8]
0049966d mov dword ptr [ecx + 8], eax
00499670 mov ecx, edi
00499672 call 0x474430
00499677 mov ecx, eax
00499679 lea eax, [esi + 0x3f4]
0049967f mov edx, dword ptr [ecx]
00499681 mov dword ptr [eax], edx
00499683 mov edx, dword ptr [ecx + 4]
00499686 mov dword ptr [eax + 4], edx
00499689 lea edx, [esi + 0x3dc]
0049968f mov ecx, dword ptr [ecx + 8]
00499692 push edx
00499693 mov dword ptr [eax + 8], ecx
00499696 lea eax, [esi + 0x3f4]
0049969c push eax
0049969d push ebx
0049969e call 0x532880
004996a3 movsx eax, word ptr [edi]
004996a6 mov ecx, dword ptr [ebp + 0xc]
004996a9 add esp, 0xc
004996ac lea eax, [eax + eax*4]
004996af shl eax, 4
004996b2 fld dword ptr [eax + ecx + 0x28]
004996b6 fstp dword ptr [esi + 0x3b8]
004996bc mov edx, dword ptr [ebp + 0xc]
004996bf fld dword ptr [eax + edx + 0x2c]
004996c3 fstp dword ptr [esi + 0x3bc]
004996c9 mov ecx, dword ptr [ebp + 0xc]
004996cc fld dword ptr [eax + ecx + 0x30]
004996d0 fstp dword ptr [esi + 0x3c0]
004996d6 mov edx, dword ptr [ebp + 0xc]
004996d9 fld dword ptr [eax + edx + 0x10]
004996dd fstp dword ptr [esi + 0x3c4]
004996e3 mov ecx, dword ptr [ebp + 0xc]
004996e6 fld dword ptr [eax + ecx + 0x14]
004996ea fstp dword ptr [esi + 0x3c8]
004996f0 mov edx, dword ptr [ebp + 0xc]
004996f3 fld dword ptr [eax + edx + 0x18]
004996f7 fstp dword ptr [esi + 0x3cc]
004996fd mov ecx, dword ptr [ebp + 0xc]
00499700 fld dword ptr [eax + ecx + 0x1c]
00499704 fstp dword ptr [esi + 0x3d0]
0049970a mov edx, dword ptr [ebp + 0xc]
0049970d fld dword ptr [eax + edx + 0x20]
00499711 fstp dword ptr [esi + 0x3d4]
00499717 mov ecx, dword ptr [ebp + 0xc]
0049971a fld dword ptr [eax + ecx + 0x24]
0049971e fstp dword ptr [esi + 0x3d8]
00499724 pop edi
00499725 pop esi
00499726 pop ebp
00499727 pop ebx
00499728 add esp, 0x1c
0049972b ret
0049972c nop
0049972d nop
0049972e nop
0049972f nop
00499730 mov edx, dword ptr [esp + 4]
00499734 fld dword ptr [edx + 0x3a0]
0049973a fcomp dword ptr [0x5b49d8]
00499740 fnstsw ax
00499742 test ah, 1
00499745 je 0x49974e
00499747 fld dword ptr [0x5b23f8]
0049974d ret
0049974e mov eax, dword ptr [esp + 8]
00499752 mov dword ptr [esp + 4], 0
0049975a fld dword ptr [0x5b23f0]
00499760 lea ecx, [eax + eax*2]
00499763 shl ecx, 4
00499766 add ecx, eax
00499768 mov eax, dword ptr [edx + ecx*4 + 0x844]
0049976f and eax, 0xf
00499772 lea ecx, [edx + ecx*4]
00499775 cmp eax, 3
00499778 je 0x4997bc
0049977a cmp eax, 9
0049977d je 0x4997bc
0049977f cmp eax, 5
00499782 je 0x4997bc
00499784 cmp eax, 2
00499787 je 0x4997aa
00499789 cmp eax, 7
0049978c je 0x4997aa
0049978e cmp eax, 4
00499791 je 0x499798
00499793 cmp eax, 0xa
00499796 jne 0x4997cc
00499798 fstp st(0)
0049979a fld dword ptr [0x5b23f0]
004997a0 mov dword ptr [esp + 4], 0x3cf5c28f
004997a8 jmp 0x4997cc
004997aa fstp st(0)
004997ac fld dword ptr [0x5b2468]
004997b2 mov dword ptr [esp + 4], 0x3cf5c28f
004997ba jmp 0x4997cc
004997bc fstp st(0)
004997be fld dword ptr [0x5b2464]
004997c4 mov dword ptr [esp + 4], 0x3dcccccd
004997cc fld dword ptr [edx + 0x35c]
004997d2 fmul dword ptr [0x5b24b8]
004997d8 fadd dword ptr [ecx + 0x834]
004997de fst dword ptr [ecx + 0x834]
004997e4 fcomp st(1)
004997e6 fnstsw ax
004997e8 test ah, 0x41
004997eb jne 0x4997fa
004997ed fcom dword ptr [0x5b23f8]
004997f3 fnstsw ax
004997f5 test ah, 0x41
004997f8 je 0x49980b
004997fa fld dword ptr [esp + 4]
004997fe fcomp dword ptr [0x5b27a8]
00499804 fnstsw ax
00499806 test ah, 1
00499809 je 0x49986c
0049980b mov dword ptr [ecx + 0x834], 0
00499815 mov edx, dword ptr [ecx + 0x830]
0049981b mov dword ptr [ecx + 0x82c], edx
00499821 mov eax, dword ptr [0x5d102c]
00499826 imul eax, dword ptr [0x5d1028]
0049982d fld dword ptr [esp + 4]
00499831 fmul dword ptr [0x5b49d4]
00499837 mov dword ptr [0x655a0c], eax
0049983c mov edx, eax
0049983e shr eax, 8
00499841 and edx, 0xffff
00499847 and eax, 0xffff
0049984c mov dword ptr [esp + 8], eax
00499850 mov dword ptr [0x5d1028], edx
00499856 fild dword ptr [esp + 8]
0049985a fmul dword ptr [esp + 4]
0049985e fmul dword ptr [0x5b253c]
00499864 fsubp st(1)
00499866 fstp dword ptr [ecx + 0x830]
0049986c fld dword ptr [ecx + 0x830]
00499872 fsub dword ptr [ecx + 0x82c]
00499878 fld dword ptr [ecx + 0x834]
0049987e fdiv st(2)
00499880 fmulp st(1)
00499882 fadd dword ptr [ecx + 0x82c]
00499888 fstp st(1)
0049988a ret
0049988b nop
0049988c nop
0049988d nop
0049988e nop
0049988f nop
00499890 mov edx, dword ptr [esp + 4]
00499894 mov eax, dword ptr [esp + 0xc]
00499898 mov ecx, dword ptr [esp + 8]
0049989c fld dword ptr [edx]
0049989e fsub dword ptr [eax]
004998a0 fmul dword ptr [ecx]
004998a2 fchs
004998a4 fld dword ptr [edx + 8]
004998a7 fsub dword ptr [eax + 8]
004998aa fmul dword ptr [ecx + 8]
004998ad fsubp st(1)
004998af fdiv dword ptr [ecx + 4]
004998b2 fadd dword ptr [eax + 4]
004998b5 ret
004998b6 nop
004998b7 nop
004998b8 nop
004998b9 nop
004998ba nop
004998bb nop
004998bc nop
004998bd nop
004998be nop
004998bf nop
004998c0 sub esp, 0x3c
004998c3 push ebx
004998c4 push esi
004998c5 mov esi, dword ptr [esp + 0x48]
004998c9 push edi
004998ca push 1
004998cc lea edi, [esi + 0x330]
004998d2 lea ebx, [esi + 8]
004998d5 push edi
004998d6 mov ecx, ebx
004998d8 call 0x474060
004998dd mov ecx, ebx
004998df call 0x474420
004998e4 mov ecx, dword ptr [esp + 0x50]
004998e8 mov ebx, dword ptr [eax]
004998ea mov edx, ecx
004998ec mov dword ptr [edx], ebx
004998ee mov ebx, dword ptr [eax + 4]
004998f1 mov dword ptr [edx + 4], ebx
004998f4 mov eax, dword ptr [eax + 8]
004998f7 mov dword ptr [edx + 8], eax
004998fa fld dword ptr [ecx + 4]
004998fd fcomp dword ptr [0x5b2604]
00499903 fnstsw ax
00499905 test ah, 0x41
00499908 jne 0x49993e
0049990a fld dword ptr [edi]
0049990c fsub dword ptr [esi + 0x400]
00499912 lea eax, [esi + 0x400]
00499918 push eax
00499919 push ecx
0049991a fmul dword ptr [ecx]
0049991c push esi
0049991d fchs
0049991f fld dword ptr [edi + 8]
00499922 fsub dword ptr [eax + 8]
00499925 fmul dword ptr [ecx + 8]
00499928 fsubp st(1)
0049992a fdiv dword ptr [ecx + 4]
0049992d fadd dword ptr [eax + 4]
00499930 fstp dword ptr [esp + 0x58]
00499934 call 0x49a900
00499939 add esp, 0xc
0049993c jmp 0x499946
0049993e mov dword ptr [esp + 0x4c], 0xcefa0000
00499946 fld dword ptr [esi + 0x3b0]
0049994c fmul dword ptr [0x5b2618]
00499952 lea ecx, [esp + 0x24]
00499956 lea edx, [esi + 0x37c]
0049995c push ecx
0049995d push ecx
0049995e fstp dword ptr [esp]
00499961 push edx
00499962 push 1
00499964 call 0x532360
00499969 fld dword ptr [esi + 0x3a8]
0049996f fmul dword ptr [0x5b25e8]
00499975 add esp, 0x10
00499978 lea eax, [esp + 0x18]
0049997c push eax
0049997d push ecx
0049997e fstp dword ptr [esp]
00499981 lea ecx, [esi + 0x364]
00499987 push ecx
00499988 push 1
0049998a call 0x532360
0049998f fld dword ptr [esi + 0x3ac]
00499995 add esp, 0x10
00499998 lea edx, [esp + 0x3c]
0049999c fchs
0049999e push edx
0049999f push ecx
004999a0 lea eax, [esi + 0x370]
004999a6 fstp dword ptr [esp]
004999a9 push eax
004999aa push 1
004999ac call 0x532360
004999b1 lea ecx, [esp + 0x40]
004999b5 lea edx, [esp + 0x4c]
004999b9 push ecx
004999ba push edx
004999bb push edi
004999bc push 1
004999be call 0x532300
004999c3 lea eax, [esp + 0x2c]
004999c7 lea ecx, [esp + 0x44]
004999cb push eax
004999cc lea edx, [esp + 0x54]
004999d0 push ecx
004999d1 push edx
004999d2 push 1
004999d4 call 0x532300
004999d9 lea eax, [esi + 0x7f8]
004999df lea ecx, [esp + 0x48]
004999e3 push eax
004999e4 lea edx, [esp + 0x40]
004999e8 push ecx
004999e9 push edx
004999ea push 1
004999ec call 0x532330
004999f1 add esp, 0x40
004999f4 lea eax, [esi + 0x8bc]
004999fa lea ecx, [esp + 0x18]
004999fe lea edx, [esp + 0xc]
00499a02 push eax
00499a03 push ecx
00499a04 push edx
00499a05 push 1
00499a07 call 0x532300
00499a0c lea eax, [esp + 0x1c]
00499a10 lea ecx, [esp + 0x34]
00499a14 push eax
00499a15 lea edx, [esp + 0x44]
00499a19 push ecx
00499a1a push edx
00499a1b push 1
00499a1d call 0x532330
00499a22 lea eax, [esi + 0x980]
00499a28 lea ecx, [esp + 0x38]
00499a2c push eax
00499a2d lea edx, [esp + 0x30]
00499a31 push ecx
00499a32 push edx
00499a33 push 1
00499a35 call 0x532330
00499a3a add esi, 0xa44
00499a40 lea eax, [esp + 0x48]
00499a44 push esi
00499a45 lea ecx, [esp + 0x40]
00499a49 push eax
00499a4a push ecx
00499a4b push 1
00499a4d call 0x532300
00499a52 fld dword ptr [esp + 0x8c]
00499a59 add esp, 0x40
00499a5c pop edi
00499a5d pop esi
00499a5e pop ebx
00499a5f add esp, 0x3c
00499a62 ret
00499a63 nop
00499a64 nop
00499a65 nop
00499a66 nop
00499a67 nop
00499a68 nop
00499a69 nop
00499a6a nop
00499a6b nop
00499a6c nop
00499a6d nop
00499a6e nop
00499a6f nop
00499a70 sub esp, 0xf0
00499a76 push ebx
00499a77 push ebp
00499a78 push esi
00499a79 mov esi, dword ptr [esp + 0x100]
00499a80 push edi
00499a81 mov dword ptr [esp + 0x9c], 0x3f800000
00499a8c mov dword ptr [esp + 0xa0], 0x3f800000
00499a97 mov dword ptr [esp + 0xa4], 0x3f800000
00499aa2 mov dword ptr [esp + 0xa8], 0x3f800000
00499aad mov dword ptr [esp + 0x38], 0
00499ab5 mov dword ptr [esp + 0x3c], 0
00499abd mov dword ptr [esp + 0x40], 0
00499ac5 mov dword ptr [esp + 0x44], 0
00499acd lea eax, [esp + 0xd4]
00499ad4 lea ecx, [esi + 0x1dc]
00499ada mov edx, 4
00499adf mov ebx, ecx
00499ae1 lea edi, [eax - 4]
00499ae4 add ecx, 0xc
00499ae7 add eax, 0xc
00499aea mov ebp, dword ptr [ebx]
00499aec dec edx
00499aed mov dword ptr [edi], ebp
00499aef mov ebp, dword ptr [ebx + 4]
00499af2 mov dword ptr [edi + 4], ebp
00499af5 mov ebx, dword ptr [ebx + 8]
00499af8 mov dword ptr [edi + 8], ebx
00499afb mov edi, dword ptr [esi + 0x760]
00499b01 fld dword ptr [edi + 0x120]
00499b07 fmul dword ptr [esi + 0x374]
00499b0d fadd dword ptr [eax - 0xc]
00499b10 fstp dword ptr [eax - 0xc]
00499b13 jne 0x499adf
00499b15 xor ebp, ebp
00499b17 lea eax, [esp + 0x9c]
00499b1e mov dword ptr [esp + 0x18], ebp
00499b22 mov dword ptr [esp + 0x28], eax
00499b26 lea edi, [esi + 0x7bc]
00499b2c lea ebx, [esp + ebp + 0xd0]
00499b33 lea eax, [esp + ebp + 0x60]
00499b37 mov ecx, ebx
00499b39 push 1
00499b3b push ebx
00499b3c mov edx, dword ptr [ecx]
00499b3e mov dword ptr [eax], edx
00499b40 mov edx, dword ptr [ecx + 4]
00499b43 mov dword ptr [eax + 4], edx
00499b46 mov edx, ebx
00499b48 mov ecx, dword ptr [ecx + 8]
00499b4b mov dword ptr [eax + 8], ecx
00499b4e mov ecx, dword ptr [edx]
00499b50 lea eax, [edi + 0x30]
00499b53 mov dword ptr [edi + 0x30], ecx
00499b56 mov ecx, dword ptr [edx + 4]
00499b59 mov edx, dword ptr [edx + 8]
00499b5c mov dword ptr [eax + 4], ecx
00499b5f mov ecx, edi
00499b61 mov dword ptr [eax + 8], edx
00499b64 call 0x474060
00499b69 mov ecx, edi
00499b6b call 0x474420
00499b70 mov ecx, dword ptr [eax]
00499b72 mov dword ptr [esp + 0x1c], ecx
00499b76 mov edx, dword ptr [eax + 4]
00499b79 mov dword ptr [esp + 0x20], edx
00499b7d mov eax, dword ptr [eax + 8]
00499b80 mov dword ptr [esp + 0x24], eax
00499b84 xor eax, eax
00499b86 mov ax, word ptr [edi + 0x24]
00499b8a mov dword ptr [edi + 0x88], eax
00499b90 mov ecx, dword ptr [0x6573f8]
00499b96 and eax, 0xf
00499b99 test ecx, ecx
00499b9b je 0x499bb1
00499b9d cmp eax, 1
00499ba0 je 0x499ba7
00499ba2 cmp eax, 0xa
00499ba5 jne 0x499bb1
00499ba7 mov dword ptr [edi + 0x88], 2
00499bb1 lea eax, [esp + ebp + 0x60]
00499bb5 push eax
00499bb6 push edi
00499bb7 push esi
00499bb8 call 0x494480
00499bbd add esp, 0xc
00499bc0 test eax, eax
00499bc2 je 0x499c37
00499bc4 fld dword ptr [esi + 0x3ec]
00499bca fcomp dword ptr [0x5b2604]
00499bd0 fnstsw ax
00499bd2 test ah, 0x41
00499bd5 jne 0x499bf3
00499bd7 mov ecx, dword ptr [esi + 0x3ec]
00499bdd mov edx, dword ptr [esi + 0x3f0]
00499be3 fld dword ptr [esi + 0x3e8]
00499be9 mov dword ptr [esp + 0x20], ecx
00499bed mov dword ptr [esp + 0x24], edx
00499bf1 jmp 0x499c09
00499bf3 fld dword ptr [0x5b23f8]
00499bf9 mov dword ptr [esp + 0x20], 0x3f800000
00499c01 mov dword ptr [esp + 0x24], 0
00499c09 fld dword ptr [ebx]
00499c0b fsub dword ptr [esi + 0x400]
00499c11 fmul st(1)
00499c13 fchs
00499c15 fld dword ptr [ebx + 8]
00499c18 fsub dword ptr [esi + 0x408]
00499c1e fmul dword ptr [esp + 0x24]
00499c22 fsubp st(1)
00499c24 fdiv dword ptr [esp + 0x20]
00499c28 fadd dword ptr [esi + 0x404]
00499c2e fstp dword ptr [esp + ebp + 0x64]
00499c32 jmp 0x499cc9
00499c37 push 0
00499c39 mov ecx, edi
00499c3b call 0x4745f0
00499c40 mov ecx, dword ptr [eax]
00499c42 fld dword ptr [ebx]
00499c44 mov dword ptr [esp + 0x48], ecx
00499c48 mov edx, dword ptr [eax + 4]
00499c4b fsub dword ptr [esp + 0x48]
00499c4f mov eax, dword ptr [eax + 8]
00499c52 mov ecx, dword ptr [esp + 0x18]
00499c56 mov dword ptr [esp + 0x50], eax
00499c5a mov dword ptr [esp + 0x4c], edx
00499c5e fmul dword ptr [esp + 0x1c]
00499c62 push ecx
00499c63 push esi
00499c64 fchs
00499c66 fld dword ptr [ebx + 8]
00499c69 fsub dword ptr [esp + 0x58]
00499c6d fmul dword ptr [esp + 0x2c]
00499c71 fsubp st(1)
00499c73 fdiv dword ptr [esp + 0x28]
00499c77 fadd dword ptr [esp + 0x54]
00499c7b fstp dword ptr [esp + ebp + 0x6c]
00499c7f call 0x499730
00499c84 fadd dword ptr [esp + ebp + 0x6c]
00499c88 add esp, 8
00499c8b cmp ebp, 0x18
00499c8e fstp dword ptr [esp + ebp + 0x64]
00499c92 jge 0x499cc5
00499c94 push esi
00499c95 call 0x493bc0
00499c9a fild dword ptr [esp + 0x1c]
00499c9e add esp, 4
00499ca1 fmul dword ptr [0x5b23f0]
00499ca7 fadd dword ptr [edi + 0x84]
00499cad fmul dword ptr [0x5b4a08]
00499cb3 fsin
00499cb5 fmulp st(1)
00499cb7 fmul qword ptr [0x5b4a00]
00499cbd fadd dword ptr [esp + ebp + 0x64]
00499cc1 fstp dword ptr [esp + ebp + 0x64]
00499cc5 fld dword ptr [esp + 0x1c]
00499cc9 fld dword ptr [esp + 0x3c]
00499ccd fadd dword ptr [esp + ebp + 0x60]
00499cd1 lea eax, [esp + ebp + 0x60]
00499cd5 mov ecx, dword ptr [esp + ebp + 0x64]
00499cd9 mov edx, dword ptr [eax]
00499cdb fstp dword ptr [esp + 0x3c]
00499cdf fld dword ptr [esp + 0x40]
00499ce3 fadd dword ptr [esp + ebp + 0x64]
00499ce7 mov dword ptr [edi + 0x3c], edx
00499cea mov edx, dword ptr [esp + ebp + 0x68]
00499cee mov dword ptr [edi + 0x40], ecx
00499cf1 mov ecx, dword ptr [esp + 0x20]
00499cf5 mov dword ptr [edi + 0x44], edx
00499cf8 mov edx, dword ptr [esp + 0x24]
00499cfc fstp dword ptr [esp + 0x40]
00499d00 fld dword ptr [esp + 0x44]
00499d04 fadd dword ptr [esp + ebp + 0x68]
00499d08 fstp dword ptr [esp + 0x44]
00499d0c fstp dword ptr [edi + 0x48]
00499d0f mov dword ptr [edi + 0x4c], ecx
00499d12 mov dword ptr [edi + 0x50], edx
00499d15 cmp dword ptr [0x606ac4], 2
00499d1c jl 0x499ee4
00499d22 mov ecx, dword ptr [0x657408]
00499d28 test ecx, ecx
00499d2a je 0x499d3a
00499d2c mov ecx, dword ptr [esi + 0xdac]
00499d32 test ecx, ecx
00499d34 jne 0x499ee4
00499d3a mov ecx, dword ptr [edi + 0x30]
00499d3d mov edx, dword ptr [edi + 0x34]
00499d40 mov dword ptr [esp + 0x54], ecx
00499d44 mov ecx, dword ptr [edi + 0x38]
00499d47 mov dword ptr [esp + 0x58], edx
00499d4b mov dword ptr [esp + 0x5c], ecx
00499d4f lea edx, [esp + 0x90]
00499d56 lea ecx, [esp + 0x54]
00499d5a push edx
00499d5b push ecx
00499d5c push eax
00499d5d push 1
00499d5f call 0x532330
00499d64 lea edx, [esi + 0x370]
00499d6a lea eax, [esp + 0xa0]
00499d71 push edx
00499d72 push eax
00499d73 call 0x532910
00499d78 fld dword ptr [esi + 0x374]
00499d7e fcomp dword ptr [0x5b25f0]
00499d84 add esp, 0x18
00499d87 fnstsw ax
00499d89 test ah, 1
00499d8c je 0x499d96
00499d8e fstp st(0)
00499d90 fld dword ptr [0x5b2444]
00499d96 mov eax, dword ptr [esi + 0x760]
00499d9c fld dword ptr [eax + 0x124]
00499da2 mov ecx, dword ptr [eax + 0x120]
00499da8 fld st(1)
00499daa fcomp dword ptr [0x5b23f8]
00499db0 mov dword ptr [esp + 0x14], ecx
00499db4 fnstsw ax
00499db6 test ah, 0x41
00499db9 jne 0x499e41
00499dbf test ebp, ebp
00499dc1 je 0x499e06
00499dc3 cmp ebp, 0xc
00499dc6 je 0x499e06
00499dc8 fsub dword ptr [esp + 0x14]
00499dcc fmul dword ptr [0x5b260c]
00499dd2 fst dword ptr [esp + 0x10]
00499dd6 fadd st(0), st(0)
00499dd8 fld st(1)
00499dda fcompp
00499ddc fnstsw ax
00499dde test ah, 0x41
00499de1 jne 0x499ded
00499de3 mov edx, dword ptr [esp + 0x28]
00499de7 mov dword ptr [edx], 0x3fa00000
00499ded fcom dword ptr [esp + 0x10]
00499df1 fnstsw ax
00499df3 test ah, 0x41
00499df6 jne 0x499e3c
00499df8 fstp st(0)
00499dfa fld dword ptr [esp + 0x10]
00499dfe fst dword ptr [edi + 0x64]
00499e01 jmp 0x499e91
00499e06 fsub dword ptr [esp + 0x14]
00499e0a fmul dword ptr [0x5b25e8]
00499e10 fst dword ptr [esp + 0x10]
00499e14 fadd st(0), st(0)
00499e16 fld st(1)
00499e18 fcompp
00499e1a fnstsw ax
00499e1c test ah, 0x41
00499e1f jne 0x499e2b
00499e21 mov eax, dword ptr [esp + 0x28]
00499e25 mov dword ptr [eax], 0x3fa00000
00499e2b fcom dword ptr [esp + 0x10]
00499e2f fnstsw ax
00499e31 test ah, 0x41
00499e34 jne 0x499e3c
00499e36 fstp st(0)
00499e38 fld dword ptr [esp + 0x10]
00499e3c fst dword ptr [edi + 0x64]
00499e3f jmp 0x499e91
00499e41 mov eax, dword ptr [edi + 0x80]
00499e47 test eax, eax
00499e49 je 0x499e68
00499e4b fmul dword ptr [0x5b49fc]
00499e51 fstp dword ptr [esp + 0x10]
00499e55 fcom dword ptr [esp + 0x10]
00499e59 fnstsw ax
00499e5b test ah, 0x41
00499e5e je 0x499e83
00499e60 fstp st(0)
00499e62 fld dword ptr [esp + 0x10]
00499e66 jmp 0x499e83
00499e68 fmul dword ptr [0x5b49f8]
00499e6e fstp dword ptr [esp + 0x10]
00499e72 fcom dword ptr [esp + 0x10]
00499e76 fnstsw ax
00499e78 test ah, 0x41
00499e7b je 0x499e83
00499e7d fstp st(0)
00499e7f fld dword ptr [esp + 0x10]
00499e83 fld st(0)
00499e85 fadd dword ptr [edi + 0x64]
00499e88 fmul dword ptr [0x5b23f0]
00499e8e fstp dword ptr [edi + 0x64]
00499e91 fld dword ptr [esp + 0x14]
00499e95 fmul dword ptr [0x5b49b4]
00499e9b fstp dword ptr [esp + 0x10]
00499e9f fcomp dword ptr [0x5b23f8]
00499ea5 fnstsw ax
00499ea7 test ah, 0x41
00499eaa jne 0x499ebd
00499eac fld dword ptr [edi + 0x64]
00499eaf fmul dword ptr [0x5b49b4]
00499eb5 fadd dword ptr [esp + 0x10]
00499eb9 fstp dword ptr [esp + 0x10]
00499ebd test ebp, ebp
00499ebf je 0x499ed6
00499ec1 cmp ebp, 0x18
00499ec4 je 0x499ed6
00499ec6 fld dword ptr [esp + 0x10]
00499eca call 0x5a2a10
00499ecf fchs
00499ed1 fstp dword ptr [edi + 0x6c]
00499ed4 jmp 0x499eec
00499ed6 fld dword ptr [esp + 0x10]
00499eda call 0x5a2a10
00499edf fstp dword ptr [edi + 0x6c]
00499ee2 jmp 0x499eec
00499ee4 xor eax, eax
00499ee6 mov dword ptr [edi + 0x6c], eax
00499ee9 mov dword ptr [edi + 0x64], eax
00499eec mov eax, dword ptr [esp + 0x18]
00499ef0 mov edx, dword ptr [esp + 0x28]
00499ef4 mov ebx, 4
00499ef9 add ebp, 0xc
00499efc inc eax
00499efd add edx, ebx
00499eff add edi, 0xc4
00499f05 cmp ebp, 0x30
00499f08 mov dword ptr [esp + 0x18], eax
00499f0c mov dword ptr [esp + 0x28], edx
00499f10 jl 0x499b2c
00499f16 fld dword ptr [esp + 0x3c]
00499f1a fmul dword ptr [0x5b2468]
00499f20 lea ecx, [esp + 0x9c]
00499f27 lea edx, [esp + 0xd4]
00499f2e mov dword ptr [esp + 0x18], ecx
00499f32 mov dword ptr [esp + 0x14], edx
00499f36 lea edi, [esi + 0x824]
00499f3c mov dword ptr [esp + 0x10], ebx
00499f40 fstp dword ptr [esp + 0x3c]
00499f44 fld dword ptr [esp + 0x40]
00499f48 fmul dword ptr [0x5b2468]
00499f4e fstp dword ptr [esp + 0x40]
00499f52 fld dword ptr [esp + 0x44]
00499f56 fmul dword ptr [0x5b2468]
00499f5c fstp dword ptr [esp + 0x44]
00499f60 fld dword ptr [0x5b23f8]
00499f66 mov eax, dword ptr [esp + 0x14]
00499f6a mov dword ptr [esp + 0x2c], 0
00499f72 fld dword ptr [edi - 0x28]
00499f75 fsub dword ptr [eax]
00499f77 fst dword ptr [edi - 8]
00499f7a fld dword ptr [0x5b49f4]
00499f80 fcomp st(1)
00499f82 mov dword ptr [esp + 0x30], 0
00499f8a mov dword ptr [esp + 0x34], 0
00499f92 fnstsw ax
00499f94 test ah, 0x41
00499f97 jne 0x499fa1
00499f99 fstp st(0)
00499f9b fld dword ptr [0x5b49f4]
00499fa1 fld dword ptr [esi + 0x3a0]
00499fa7 fcomp dword ptr [0x5b23f8]
00499fad fnstsw ax
00499faf fld st(0)
00499fb1 fmul dword ptr [esi + 0x368]
00499fb7 test ah, 0x41
00499fba jne 0x499fd6
00499fbc fstp dword ptr [esp + 0x1c]
00499fc0 fld st(0)
00499fc2 fmul dword ptr [esi + 0x374]
00499fc8 fstp dword ptr [esp + 0x20]
00499fcc fld st(0)
00499fce fmul dword ptr [esi + 0x380]
00499fd4 jmp 0x499ff4
00499fd6 fchs
00499fd8 fstp dword ptr [esp + 0x1c]
00499fdc fld st(0)
00499fde fmul dword ptr [esi + 0x374]
00499fe4 fchs
00499fe6 fstp dword ptr [esp + 0x20]
00499fea fld st(0)
00499fec fmul dword ptr [esi + 0x380]
00499ff2 fchs
00499ff4 fstp dword ptr [esp + 0x24]
00499ff8 fcomp dword ptr [0x5b49f0]
00499ffe fnstsw ax
0049a000 test ah, 1
0049a003 je 0x49a03e
0049a005 mov edx, dword ptr [esp + 0x38]
0049a009 mov dword ptr [edi + 0x18], 1
0049a010 inc edx
0049a011 mov dword ptr [esp + 0x38], edx
0049a015 mov edx, dword ptr [esi + 0x558]
0049a01b mov eax, dword ptr [edx + 0x518]
0049a021 test eax, eax
0049a023 jne 0x49a033
0049a025 fld dword ptr [esp + 0x20]
0049a029 fmul dword ptr [0x5b3f00]
0049a02f fstp dword ptr [esp + 0x20]
0049a033 mov eax, dword ptr [esp + 0x20]
0049a037 mov dword ptr [edi], eax
0049a039 jmp 0x49a1b3
0049a03e fld dword ptr [esp + 0x20]
0049a042 fdiv dword ptr [esi + 0x374]
0049a048 lea ebp, [esi + 0x33c]
0049a04e fstp dword ptr [edi]
0049a050 fld dword ptr [ebp]
0049a053 fcomp dword ptr [0x5b23f8]
0049a059 fld dword ptr [ebp]
0049a05c fnstsw ax
0049a05e test ah, 1
0049a061 je 0x49a065
0049a063 fchs
0049a065 fcomp dword ptr [0x5b27a8]
0049a06b fnstsw ax
0049a06d test ah, 0x41
0049a070 jne 0x49a1ac
0049a076 fld dword ptr [esi + 0x344]
0049a07c fcomp dword ptr [0x5b23f8]
0049a082 fld dword ptr [esi + 0x344]
0049a088 fnstsw ax
0049a08a test ah, 1
0049a08d je 0x49a091
0049a08f fchs
0049a091 fcomp dword ptr [0x5b27a8]
0049a097 fnstsw ax
0049a099 test ah, 0x41
0049a09c jne 0x49a1ac
0049a0a2 fstp st(0)
0049a0a4 fld dword ptr [ebp]
0049a0a7 fchs
0049a0a9 fstp dword ptr [esp + 0x2c]
0049a0ad fld dword ptr [esi + 0x344]
0049a0b3 lea ecx, [esp + 0x2c]
0049a0b7 lea edx, [esp + 0x2c]
0049a0bb fchs
0049a0bd fstp dword ptr [esp + 0x34]
0049a0c1 push ecx
0049a0c2 push edx
0049a0c3 call 0x5328d0
0049a0c8 lea eax, [esp + 0x98]
0049a0cf lea ecx, [esp + 0x34]
0049a0d3 lea ebx, [edi - 0x20]
0049a0d6 push eax
0049a0d7 push ecx
0049a0d8 push ebx
0049a0d9 call 0x532880
0049a0de lea edx, [esp + 0x40]
0049a0e2 lea eax, [esp + 0xa4]
0049a0e9 push edx
0049a0ea push ebx
0049a0eb push eax
0049a0ec call 0x532880
0049a0f1 mov eax, dword ptr [edi + 0x18]
0049a0f4 add esp, 0x20
0049a0f7 test eax, eax
0049a0f9 lea ebx, [esi + 0x364]
0049a0ff je 0x49a13c
0049a101 push ebx
0049a102 push ebp
0049a103 call 0x532910
0049a108 fcomp dword ptr [0x5b23f8]
0049a10e add esp, 8
0049a111 push ebx
0049a112 push ebp
0049a113 fnstsw ax
0049a115 test ah, 1
0049a118 je 0x49a12c
0049a11a call 0x532910
0049a11f fchs
0049a121 fmul dword ptr [0x5b49ec]
0049a127 add esp, 8
0049a12a jmp 0x49a175
0049a12c call 0x532910
0049a131 fmul dword ptr [0x5b49ec]
0049a137 add esp, 8
0049a13a jmp 0x49a175
0049a13c lea ebp, [esi + 0xd40]
0049a142 push ebx
0049a143 push ebp
0049a144 call 0x532910
0049a149 fcomp dword ptr [0x5b23f8]
0049a14f add esp, 8
0049a152 push ebx
0049a153 push ebp
0049a154 fnstsw ax
0049a156 test ah, 1
0049a159 je 0x49a167
0049a15b call 0x532910
0049a160 add esp, 8
0049a163 fchs
0049a165 jmp 0x49a16f
0049a167 call 0x532910
0049a16c add esp, 8
0049a16f fmul dword ptr [0x5b26a4]
0049a175 fstp dword ptr [esp + 0x28]
0049a179 mov edx, dword ptr [esp + 0x28]
0049a17d lea ecx, [esp + 0x2c]
0049a181 push ecx
0049a182 lea eax, [esp + 0x30]
0049a186 push edx
0049a187 push eax
0049a188 push 1
0049a18a call 0x532360
0049a18f lea ecx, [esi + 0x370]
0049a195 lea edx, [esp + 0x3c]
0049a199 push ecx
0049a19a push edx
0049a19b call 0x532910
0049a1a0 mov ecx, dword ptr [esp + 0x30]
0049a1a4 add esp, 0x18
0049a1a7 mov ebx, 4
0049a1ac mov dword ptr [edi + 0x18], 0
0049a1b3 fld dword ptr [esp + 0x1c]
0049a1b7 fmul dword ptr [ecx]
0049a1b9 mov eax, dword ptr [esp + 0x14]
0049a1bd add edi, 0xc4
0049a1c3 add eax, 0xc
0049a1c6 fstp dword ptr [edi - 0xd8]
0049a1cc fld dword ptr [esp + 0x20]
0049a1d0 fmul dword ptr [ecx]
0049a1d2 mov dword ptr [esp + 0x14], eax
0049a1d6 mov eax, dword ptr [esp + 0x10]
0049a1da fadd st(1)
0049a1dc fstp dword ptr [edi - 0xd4]
0049a1e2 fstp st(0)
0049a1e4 fld dword ptr [esp + 0x24]
0049a1e8 fmul dword ptr [ecx]
0049a1ea add ecx, ebx
0049a1ec dec eax
0049a1ed mov dword ptr [esp + 0x18], ecx
0049a1f1 mov dword ptr [esp + 0x10], eax
0049a1f5 fstp dword ptr [edi - 0xd0]
0049a1fb jne 0x499f60
0049a201 fld dword ptr [esp + 0x6c]
0049a205 fadd dword ptr [esp + 0x60]
0049a209 fld dword ptr [esp + 0x84]
0049a210 fadd dword ptr [esp + 0x78]
0049a214 fsubp st(1)
0049a216 fmul dword ptr [0x5b23f0]
0049a21c fstp dword ptr [esp + 0x1c]
0049a220 fld dword ptr [esp + 0x70]
0049a224 fadd dword ptr [esp + 0x64]
0049a228 fld dword ptr [esp + 0x88]
0049a22f fadd dword ptr [esp + 0x7c]
0049a233 fsubp st(1)
0049a235 fmul dword ptr [0x5b23f0]
0049a23b fstp dword ptr [esp + 0x20]
0049a23f fld dword ptr [esp + 0x74]
0049a243 fadd dword ptr [esp + 0x68]
0049a247 fld dword ptr [esp + 0x8c]
0049a24e fadd dword ptr [esp + 0x80]
0049a255 fsubp st(1)
0049a257 fmul dword ptr [0x5b23f0]
0049a25d fstp dword ptr [esp + 0x24]
0049a261 fld dword ptr [esp + 0x84]
0049a268 fadd dword ptr [esp + 0x6c]
0049a26c fld dword ptr [esp + 0x78]
0049a270 fadd dword ptr [esp + 0x60]
0049a274 fsubp st(1)
0049a276 fmul dword ptr [0x5b23f0]
0049a27c fst dword ptr [esp + 0x54]
0049a280 fld dword ptr [esp + 0x88]
0049a287 fadd dword ptr [esp + 0x70]
0049a28b fld dword ptr [esp + 0x7c]
0049a28f fadd dword ptr [esp + 0x64]
0049a293 fsubp st(1)
0049a295 fmul dword ptr [0x5b23f0]
0049a29b fstp dword ptr [esp + 0x58]
0049a29f fld dword ptr [esp + 0x8c]
0049a2a6 fadd dword ptr [esp + 0x74]
0049a2aa fld dword ptr [esp + 0x80]
0049a2b1 fadd dword ptr [esp + 0x68]
0049a2b5 fsubp st(1)
0049a2b7 fmul dword ptr [0x5b23f0]
0049a2bd fstp dword ptr [esp + 0x5c]
0049a2c1 fcomp dword ptr [0x5b23f8]
0049a2c7 fnstsw ax
0049a2c9 test ah, 0x40
0049a2cc je 0x49a2f4
0049a2ce fld dword ptr [esp + 0x58]
0049a2d2 fcomp dword ptr [0x5b23f8]
0049a2d8 fnstsw ax
0049a2da test ah, 0x40
0049a2dd je 0x49a2f4
0049a2df fld dword ptr [esp + 0x5c]
0049a2e3 fcomp dword ptr [0x5b23f8]
0049a2e9 fnstsw ax
0049a2eb test ah, 0x40
0049a2ee jne 0x49a3d1
0049a2f4 fld dword ptr [esp + 0x1c]
0049a2f8 fcomp dword ptr [0x5b23f8]
0049a2fe fnstsw ax
0049a300 test ah, 0x40
0049a303 je 0x49a32b
0049a305 fld dword ptr [esp + 0x20]
0049a309 fcomp dword ptr [0x5b23f8]
0049a30f fnstsw ax
0049a311 test ah, 0x40
0049a314 je 0x49a32b
0049a316 fld dword ptr [esp + 0x24]
0049a31a fcomp dword ptr [0x5b23f8]
0049a320 fnstsw ax
0049a322 test ah, 0x40
0049a325 jne 0x49a3d1
0049a32b lea eax, [esp + 0x1c]
0049a32f lea ecx, [esp + 0x1c]
0049a333 push eax
0049a334 push ecx
0049a335 call 0x5328d0
0049a33a lea edx, [esp + 0x5c]
0049a33e lea eax, [esp + 0x5c]
0049a342 push edx
0049a343 push eax
0049a344 call 0x5328d0
0049a349 lea ecx, [esp + 0x3c]
0049a34d lea edx, [esp + 0x64]
0049a351 push ecx
0049a352 lea eax, [esp + 0x30]
0049a356 push edx
0049a357 push eax
0049a358 call 0x532880
0049a35d lea ecx, [esp + 0x48]
0049a361 lea edx, [esp + 0x48]
0049a365 push ecx
0049a366 push edx
0049a367 call 0x5328d0
0049a36c fld dword ptr [esp + 0x54]
0049a370 fcomp dword ptr [0x5b23f8]
0049a376 fld dword ptr [esp + 0x50]
0049a37a add esp, 0x24
0049a37d fnstsw ax
0049a37f test ah, 1
0049a382 jne 0x49a39d
0049a384 mov eax, dword ptr [esp + 0x108]
0049a38b mov ecx, dword ptr [esp + 0x30]
0049a38f mov edx, dword ptr [esp + 0x34]
0049a393 fstp dword ptr [eax]
0049a395 mov dword ptr [eax + 4], ecx
0049a398 mov dword ptr [eax + 8], edx
0049a39b jmp 0x49a3ba
0049a39d mov eax, dword ptr [esp + 0x108]
0049a3a4 fchs
0049a3a6 fstp dword ptr [eax]
0049a3a8 fld dword ptr [esp + 0x30]
0049a3ac fchs
0049a3ae fstp dword ptr [eax + 4]
0049a3b1 fld dword ptr [esp + 0x34]
0049a3b5 fchs
0049a3b7 fstp dword ptr [eax + 8]
0049a3ba fld dword ptr [esp + 0x30]
0049a3be fcomp dword ptr [0x5b23f0]
0049a3c4 fnstsw ax
0049a3c6 test ah, 1
0049a3c9 je 0x49a3ec
0049a3cb mov dword ptr [esp + 0x38], ebx
0049a3cf jmp 0x49a3ec
0049a3d1 mov eax, dword ptr [esp + 0x108]
0049a3d8 mov dword ptr [eax], 0
0049a3de mov dword ptr [eax + 4], 0x3f800000
0049a3e5 mov dword ptr [eax + 8], 0
0049a3ec fld dword ptr [esi + 0x3a0]
0049a3f2 fcomp dword ptr [0x5b2698]
0049a3f8 fnstsw ax
0049a3fa test ah, 1
0049a3fd je 0x49a428
0049a3ff fld dword ptr [esi + 0xdc8]
0049a405 fmul dword ptr [0x5b23f0]
0049a40b fstp dword ptr [esi + 0xdc8]
0049a411 fld dword ptr [esi + 0xdc4]
0049a417 fmul dword ptr [0x5b23f0]
0049a41d fstp dword ptr [esi + 0xdc4]
0049a423 jmp 0x49a8aa
0049a428 cmp dword ptr [esp + 0x38], ebx
0049a42c jge 0x49a8aa
0049a432 mov eax, dword ptr [esi + 0x558]
0049a438 mov dword ptr [esp + 0x14], 0x41000000
0049a440 mov ecx, dword ptr [eax + 0x518]
0049a446 test ecx, ecx
0049a448 je 0x49a452
0049a44a mov dword ptr [esp + 0x14], 0x40800000
0049a452 lea ebx, [esi + 0x364]
0049a458 lea ebp, [esi + 0x388]
0049a45e push ebx
0049a45f push ebp
0049a460 lea edi, [esi + 0xd64]
0049a466 call 0x532910
0049a46b fstp dword ptr [edi]
0049a46d lea ecx, [esi + 0x370]
0049a473 push ecx
0049a474 push ebp
0049a475 call 0x532910
0049a47a fstp dword ptr [esi + 0xd68]
0049a480 lea edx, [esi + 0x37c]
0049a486 push edx
0049a487 push ebp
0049a488 call 0x532910
0049a48d fst dword ptr [esi + 0xd6c]
0049a493 fld dword ptr [esi + 0x99c]
0049a499 fadd dword ptr [esi + 0xa60]
0049a49f fld dword ptr [esi + 0x814]
0049a4a5 fadd dword ptr [esi + 0x8d8]
0049a4ab mov edx, dword ptr [esi + 0xdac]
0049a4b1 add esp, 0x18
0049a4b4 fsubp st(1)
0049a4b6 test edx, edx
0049a4b8 fdiv dword ptr [esp + 0x14]
0049a4bc je 0x49a4cd
0049a4be mov dword ptr [esi + 0xdc4], 0
0049a4c8 jmp 0x49a599
0049a4cd test byte ptr [esi + 0x52c], 0x20
0049a4d4 je 0x49a51c
0049a4d6 fld dword ptr [esi + 0xd54]
0049a4dc fcom dword ptr [0x5b241c]
0049a4e2 fnstsw ax
0049a4e4 test ah, 0x41
0049a4e7 jne 0x49a4f3
0049a4e9 fstp st(0)
0049a4eb fld dword ptr [0x5b241c]
0049a4f1 jmp 0x49a508
0049a4f3 fcom dword ptr [0x5b49e8]
0049a4f9 fnstsw ax
0049a4fb test ah, 1
0049a4fe je 0x49a508
0049a500 fstp st(0)
0049a502 fld dword ptr [0x5b49e8]
0049a508 mov eax, dword ptr [esi + 0x760]
0049a50e fmul dword ptr [eax + 0x128]
0049a514 fmul dword ptr [0x5b272c]
0049a51a jmp 0x49a585
0049a51c mov ecx, dword ptr [esi + 0x558]
0049a522 mov eax, dword ptr [ecx + 0x518]
0049a528 test eax, eax
0049a52a je 0x49a540
0049a52c mov eax, dword ptr [esi + 0x760]
0049a532 fld dword ptr [esi + 0xd54]
0049a538 fmul dword ptr [eax + 0x128]
0049a53e jmp 0x49a593
0049a540 fld dword ptr [esi + 0xd54]
0049a546 fcomp dword ptr [0x5b23f8]
0049a54c fnstsw ax
0049a54e test ah, 0x41
0049a551 jne 0x49a56d
0049a553 mov ecx, dword ptr [esi + 0x760]
0049a559 fld dword ptr [ecx + 0x128]
0049a55f fmul dword ptr [esi + 0xd54]
0049a565 fmul dword ptr [0x5b272c]
0049a56b jmp 0x49a585
0049a56d mov eax, dword ptr [esi + 0x760]
0049a573 fld dword ptr [eax + 0x128]
0049a579 fmul dword ptr [esi + 0xd54]
0049a57f fmul dword ptr [0x5b49e4]
0049a585 fld dword ptr [esi + 0xdc4]
0049a58b fmul dword ptr [0x5b24e8]
0049a591 faddp st(1)
0049a593 fstp dword ptr [esi + 0xdc4]
0049a599 fsub dword ptr [esi + 0xdc4]
0049a59f mov ecx, dword ptr [esi + 0x760]
0049a5a5 fcom dword ptr [0x5b23f8]
0049a5ab fst dword ptr [esp + 0x28]
0049a5af fnstsw ax
0049a5b1 test ah, 0x41
0049a5b4 jne 0x49a5d1
0049a5b6 mov eax, dword ptr [ecx + 0x134]
0049a5bc mov dword ptr [esp + 0x18], eax
0049a5c0 fcomp dword ptr [esp + 0x18]
0049a5c4 fnstsw ax
0049a5c6 test ah, 0x41
0049a5c9 jne 0x49a5f0
0049a5cb mov eax, dword ptr [esp + 0x18]
0049a5cf jmp 0x49a5ec
0049a5d1 fld dword ptr [ecx + 0x134]
0049a5d7 fchs
0049a5d9 fstp dword ptr [esp + 0x18]
0049a5dd fcomp dword ptr [esp + 0x18]
0049a5e1 fnstsw ax
0049a5e3 test ah, 0x41
0049a5e6 je 0x49a5f0
0049a5e8 mov eax, dword ptr [esp + 0x18]
0049a5ec mov dword ptr [esp + 0x28], eax
0049a5f0 fld dword ptr [esi + 0xa60]
0049a5f6 fadd dword ptr [esi + 0x8d8]
0049a5fc fld dword ptr [esi + 0x99c]
0049a602 fadd dword ptr [esi + 0x814]
0049a608 test edx, edx
0049a60a fsubp st(1)
0049a60c fdiv dword ptr [esp + 0x14]
0049a610 je 0x49a61e
0049a612 mov dword ptr [esi + 0xdc8], 0
0049a61c jmp 0x49a671
0049a61e test byte ptr [esi + 0x52c], 0x20
0049a625 je 0x49a63b
0049a627 fld dword ptr [ecx + 0x12c]
0049a62d fmul dword ptr [esi + 0xd4c]
0049a633 fmul dword ptr [0x5b2638]
0049a639 jmp 0x49a65d
0049a63b mov edx, dword ptr [esi + 0x558]
0049a641 fld dword ptr [ecx + 0x12c]
0049a647 mov eax, dword ptr [edx + 0x518]
0049a64d fmul dword ptr [esi + 0xd4c]
0049a653 test eax, eax
0049a655 jne 0x49a66b
0049a657 fmul dword ptr [0x5b2468]
0049a65d fld dword ptr [esi + 0xdc8]
0049a663 fmul dword ptr [0x5b24e8]
0049a669 faddp st(1)
0049a66b fstp dword ptr [esi + 0xdc8]
0049a671 xor eax, eax
0049a673 mov al, byte ptr [esi + 0xd7f]
0049a679 mov dword ptr [esp + 0x14], eax
0049a67d fild dword ptr [esp + 0x14]
0049a681 fmul dword ptr [0x5b49e0]
0049a687 fsubr dword ptr [0x5b24a8]
0049a68d fmul dword ptr [esi + 0xdc8]
0049a693 faddp st(1)
0049a695 fcom dword ptr [0x5b23f8]
0049a69b fnstsw ax
0049a69d test ah, 0x41
0049a6a0 jne 0x49a6bf
0049a6a2 mov edx, dword ptr [ecx + 0x138]
0049a6a8 mov dword ptr [esp + 0x14], edx
0049a6ac fcom dword ptr [esp + 0x14]
0049a6b0 fnstsw ax
0049a6b2 test ah, 0x41
0049a6b5 jne 0x49a6dc
0049a6b7 fstp st(0)
0049a6b9 fld dword ptr [esp + 0x14]
0049a6bd jmp 0x49a6dc
0049a6bf fld dword ptr [ecx + 0x138]
0049a6c5 fchs
0049a6c7 fstp dword ptr [esp + 0x14]
0049a6cb fcom dword ptr [esp + 0x14]
0049a6cf fnstsw ax
0049a6d1 test ah, 0x41
0049a6d4 je 0x49a6dc
0049a6d6 fstp st(0)
0049a6d8 fld dword ptr [esp + 0x14]
0049a6dc fld dword ptr [ecx + 0x114]
0049a6e2 fmul dword ptr [edi]
0049a6e4 push esi
0049a6e5 fmul dword ptr [0x5b49dc]
0049a6eb fadd dword ptr [esp + 0x2c]
0049a6ef fstp dword ptr [edi]
0049a6f1 fxch st(1)
0049a6f3 fmul dword ptr [ecx + 0x118]
0049a6f9 fadd st(1)
0049a6fb fstp dword ptr [esi + 0xd6c]
0049a701 fstp st(0)
0049a703 call 0x49bc80
0049a708 lea eax, [esp + 0xb0]
0049a70f push eax
0049a710 push ebx
0049a711 call 0x532a00
0049a716 lea ecx, [esp + 0xb8]
0049a71d push ecx
0049a71e push edi
0049a71f call 0x532910
0049a724 fstp dword ptr [ebp]
0049a727 lea edx, [esp + 0xcc]
0049a72e push edx
0049a72f push edi
0049a730 call 0x532910
0049a735 fstp dword ptr [esi + 0x38c]
0049a73b lea eax, [esp + 0xe0]
0049a742 push eax
0049a743 push edi
0049a744 call 0x532910
0049a749 mov eax, dword ptr [esp + 0x5c]
0049a74d add esp, 0x24
0049a750 fstp dword ptr [esi + 0x390]
0049a756 test eax, eax
0049a758 jle 0x49a8aa
0049a75e mov eax, dword ptr [esi + 0x83c]
0049a764 test eax, eax
0049a766 jne 0x49a776
0049a768 mov eax, dword ptr [esi + 0x9c4]
0049a76e test eax, eax
0049a770 jne 0x49a776
0049a772 xor ebp, ebp
0049a774 jmp 0x49a77b
0049a776 mov ebp, 1
0049a77b mov eax, dword ptr [esi + 0x900]
0049a781 test eax, eax
0049a783 jne 0x49a793
0049a785 mov eax, dword ptr [esi + 0xa88]
0049a78b test eax, eax
0049a78d jne 0x49a793
0049a78f xor edi, edi
0049a791 jmp 0x49a798
0049a793 mov edi, 1
0049a798 test ebp, ebp
0049a79a je 0x49a7a4
0049a79c test edi, edi
0049a79e jne 0x49a8aa
0049a7a4 mov ecx, dword ptr [esi + 0xd6c]
0049a7aa push ecx
0049a7ab call 0x5327e0
0049a7b0 fmul dword ptr [esi + 0x3a8]
0049a7b6 mov edx, dword ptr [esi + 0xd6c]
0049a7bc push edx
0049a7bd fmul dword ptr [0x5b2628]
0049a7c3 fstp dword ptr [esp + 0x50]
0049a7c7 call 0x5327f0
0049a7cc fmul dword ptr [esi + 0x3ac]
0049a7d2 add esp, 8
0049a7d5 mov dword ptr [esp + 0x50], 0
0049a7dd test ebp, ebp
0049a7df fmul dword ptr [0x5b2628]
0049a7e5 fstp dword ptr [esp + 0x4c]
0049a7e9 je 0x49a7fe
0049a7eb fld dword ptr [esi + 0xd6c]
0049a7f1 fcomp dword ptr [0x5b23f8]
0049a7f7 fnstsw ax
0049a7f9 test ah, 1
0049a7fc jne 0x49a815
0049a7fe test edi, edi
0049a800 je 0x49a81f
0049a802 fld dword ptr [esi + 0xd6c]
0049a808 fcomp dword ptr [0x5b23f8]
0049a80e fnstsw ax
0049a810 test ah, 0x41
0049a813 jne 0x49a81f
0049a815 fld dword ptr [esp + 0x4c]
0049a819 fchs
0049a81b fstp dword ptr [esp + 0x4c]
0049a81f lea eax, [esp + 0xac]
0049a826 lea ecx, [esp + 0x48]
0049a82a push eax
0049a82b push ecx
0049a82c call 0x532910
0049a831 fstp dword ptr [esp + 0x98]
0049a838 lea edx, [esp + 0xc0]
0049a83f lea eax, [esp + 0x50]
0049a843 push edx
0049a844 push eax
0049a845 call 0x532910
0049a84a fstp dword ptr [esp + 0xa4]
0049a851 lea ecx, [esp + 0xd4]
0049a858 lea edx, [esp + 0x58]
0049a85c push ecx
0049a85d push edx
0049a85e call 0x532910
0049a863 fld dword ptr [esp + 0xa8]
0049a86a fmul dword ptr [0x5b24b8]
0049a870 add esp, 0x18
0049a873 fadd dword ptr [esi + 0x330]
0049a879 fstp dword ptr [esi + 0x330]
0049a87f fld dword ptr [esp + 0x94]
0049a886 fmul dword ptr [0x5b24b8]
0049a88c fadd dword ptr [esi + 0x334]
0049a892 fstp dword ptr [esi + 0x334]
0049a898 fmul dword ptr [0x5b24b8]
0049a89e fadd dword ptr [esi + 0x338]
0049a8a4 fstp dword ptr [esi + 0x338]
0049a8aa mov ecx, dword ptr [esp + 0x38]
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
0049a8e6 add esp, 0x10
0049a8e9 pop edi
0049a8ea pop esi
0049a8eb pop ebp
0049a8ec pop ebx
0049a8ed add esp, 0xf0
0049a8f3 ret
0049a8f4 nop
0049a8f5 nop
0049a8f6 nop
0049a8f7 nop
0049a8f8 nop
0049a8f9 nop
0049a8fa nop
0049a8fb nop
0049a8fc nop
0049a8fd nop
0049a8fe nop
0049a8ff nop
0049a900 sub esp, 0x1c
0049a903 push ebx
0049a904 mov ebx, dword ptr [esp + 0x24]
0049a908 push ebp
0049a909 push esi
0049a90a fld dword ptr [ebx + 0x3a0]
0049a910 fcomp dword ptr [0x5b4a0c]
0049a916 push edi
0049a917 mov dword ptr [esp + 0x1c], 0x447a0000
0049a91f mov dword ptr [esp + 0x20], 0x447a0000
0049a927 mov dword ptr [esp + 0x24], 0x447a0000
0049a92f mov dword ptr [esp + 0x28], 0x447a0000
0049a937 fnstsw ax
0049a939 test ah, 0x41
0049a93c jne 0x49aa57
0049a942 test byte ptr [ebx + 0x52c], 0x80
0049a949 jne 0x49aa57
0049a94f mov edi, dword ptr [esp + 0x38]
0049a953 mov ebp, dword ptr [esp + 0x34]
0049a957 lea esi, [ebx + 0x1dc]
0049a95d mov dword ptr [esp + 0x30], 4
0049a965 mov eax, esi
0049a967 mov ecx, dword ptr [eax]
0049a969 mov dword ptr [esp + 0x10], ecx
0049a96d lea ecx, [esp + 0x10]
0049a971 mov edx, dword ptr [eax + 4]
0049a974 push ecx
0049a975 mov dword ptr [esp + 0x18], edx
0049a979 lea edx, [esp + 0x14]
0049a97d mov eax, dword ptr [eax + 8]
0049a980 push edi
0049a981 push edx
0049a982 push 1
0049a984 mov dword ptr [esp + 0x28], eax
0049a988 call 0x532330
0049a98d lea eax, [esp + 0x20]
0049a991 push eax
0049a992 push ebp
0049a993 call 0x532910
0049a998 fcom dword ptr [esp + 0x34]
0049a99c add esp, 0x18
0049a99f fnstsw ax
0049a9a1 test ah, 0x41
0049a9a4 je 0x49a9c4
0049a9a6 mov ecx, dword ptr [esp + 0x24]
0049a9aa mov edx, dword ptr [esp + 0x20]
0049a9ae mov eax, dword ptr [esp + 0x1c]
0049a9b2 mov dword ptr [esp + 0x28], ecx
0049a9b6 fstp dword ptr [esp + 0x1c]
0049a9ba mov dword ptr [esp + 0x24], edx
0049a9be mov dword ptr [esp + 0x20], eax
0049a9c2 jmp 0x49aa11
0049a9c4 fcom dword ptr [esp + 0x20]
0049a9c8 fnstsw ax
0049a9ca test ah, 0x41
0049a9cd je 0x49a9e5
0049a9cf mov ecx, dword ptr [esp + 0x24]
0049a9d3 mov edx, dword ptr [esp + 0x20]
0049a9d7 fstp dword ptr [esp + 0x20]
0049a9db mov dword ptr [esp + 0x28], ecx
0049a9df mov dword ptr [esp + 0x24], edx
0049a9e3 jmp 0x49aa11
0049a9e5 fcom dword ptr [esp + 0x24]
0049a9e9 fnstsw ax
0049a9eb test ah, 0x41
0049a9ee je 0x49a9fe
0049a9f0 mov eax, dword ptr [esp + 0x24]
0049a9f4 fstp dword ptr [esp + 0x24]
0049a9f8 mov dword ptr [esp + 0x28], eax
0049a9fc jmp 0x49aa11
0049a9fe fcom dword ptr [esp + 0x28]
0049aa02 fnstsw ax
0049aa04 test ah, 0x41
0049aa07 je 0x49aa0f
0049aa09 fstp dword ptr [esp + 0x28]
0049aa0d jmp 0x49aa11
0049aa0f fstp st(0)
0049aa11 mov eax, dword ptr [esp + 0x30]
0049aa15 add esi, 0xc
0049aa18 dec eax
0049aa19 mov dword ptr [esp + 0x30], eax
0049aa1d jne 0x49a965
0049aa23 fld dword ptr [esp + 0x28]
0049aa27 fadd dword ptr [esp + 0x24]
0049aa2b pop edi
0049aa2c pop esi
0049aa2d pop ebp
0049aa2e fadd dword ptr [esp + 0x14]
0049aa32 fadd dword ptr [esp + 0x10]
0049aa36 fmul dword ptr [0x5b2468]
0049aa3c fadd dword ptr [esp + 0x10]
0049aa40 fmul dword ptr [0x5b23f0]
0049aa46 fst dword ptr [ebx + 0x428]
0049aa4c fstp dword ptr [ebx + 0x424]
0049aa52 pop ebx
0049aa53 add esp, 0x1c
0049aa56 ret
0049aa57 mov eax, dword ptr [ebx + 0x32c]
0049aa5d xor edi, edi
0049aa5f test eax, eax
0049aa61 jle 0x49ab33
0049aa67 mov ebp, dword ptr [esp + 0x38]
0049aa6b lea esi, [ebx + 0x1dc]
0049aa71 mov ecx, esi
0049aa73 mov edx, dword ptr [ecx]
0049aa75 mov dword ptr [esp + 0x10], edx
0049aa79 lea edx, [esp + 0x10]
0049aa7d mov eax, dword ptr [ecx + 4]
0049aa80 push edx
0049aa81 mov dword ptr [esp + 0x18], eax
0049aa85 lea eax, [esp + 0x14]
0049aa89 mov ecx, dword ptr [ecx + 8]
0049aa8c push ebp
0049aa8d push eax
0049aa8e push 1
0049aa90 mov dword ptr [esp + 0x28], ecx
0049aa94 call 0x532330
0049aa99 mov edx, dword ptr [esp + 0x44]
0049aa9d lea ecx, [esp + 0x20]
0049aaa1 push ecx
0049aaa2 push edx
0049aaa3 call 0x532910
0049aaa8 fcom dword ptr [esp + 0x34]
0049aaac add esp, 0x18
0049aaaf fnstsw ax
0049aab1 test ah, 0x41
0049aab4 je 0x49aad4
0049aab6 mov eax, dword ptr [esp + 0x24]
0049aaba mov ecx, dword ptr [esp + 0x20]
0049aabe mov edx, dword ptr [esp + 0x1c]
0049aac2 mov dword ptr [esp + 0x28], eax
0049aac6 fstp dword ptr [esp + 0x1c]
0049aaca mov dword ptr [esp + 0x24], ecx
0049aace mov dword ptr [esp + 0x20], edx
0049aad2 jmp 0x49ab21
0049aad4 fcom dword ptr [esp + 0x20]
0049aad8 fnstsw ax
0049aada test ah, 0x41
0049aadd je 0x49aaf5
0049aadf mov eax, dword ptr [esp + 0x24]
0049aae3 mov ecx, dword ptr [esp + 0x20]
0049aae7 fstp dword ptr [esp + 0x20]
0049aaeb mov dword ptr [esp + 0x28], eax
0049aaef mov dword ptr [esp + 0x24], ecx
0049aaf3 jmp 0x49ab21
0049aaf5 fcom dword ptr [esp + 0x24]
0049aaf9 fnstsw ax
0049aafb test ah, 0x41
0049aafe je 0x49ab0e
0049ab00 mov edx, dword ptr [esp + 0x24]
0049ab04 fstp dword ptr [esp + 0x24]
0049ab08 mov dword ptr [esp + 0x28], edx
0049ab0c jmp 0x49ab21
0049ab0e fcom dword ptr [esp + 0x28]
0049ab12 fnstsw ax
0049ab14 test ah, 0x41
0049ab17 je 0x49ab1f
0049ab19 fstp dword ptr [esp + 0x28]
0049ab1d jmp 0x49ab21
0049ab1f fstp st(0)
0049ab21 mov eax, dword ptr [ebx + 0x32c]
0049ab27 inc edi
0049ab28 add esi, 0xc
0049ab2b cmp edi, eax
0049ab2d jl 0x49aa71
0049ab33 fld dword ptr [esp + 0x24]
0049ab37 fadd dword ptr [esp + 0x20]
0049ab3b mov eax, dword ptr [esp + 0x1c]
0049ab3f pop edi
0049ab40 pop esi
0049ab41 mov dword ptr [ebx + 0x424], eax
0049ab47 fadd dword ptr [esp + 0x14]
0049ab4b pop ebp
0049ab4c fmul dword ptr [0x5b2680]
0049ab52 fstp dword ptr [ebx + 0x428]
0049ab58 pop ebx
0049ab59 add esp, 0x1c
0049ab5c ret
0049ab5d nop
0049ab5e nop
0049ab5f nop
0049ab60 push ebx
0049ab61 push esi
0049ab62 mov esi, dword ptr [esp + 0xc]
0049ab66 push edi
0049ab67 push esi
0049ab68 call 0x49ae30
0049ab6d add esp, 4
0049ab70 lea ecx, [esi + 0x7ec]
0049ab76 lea eax, [esi + 0x1dc]
0049ab7c mov edx, 4
0049ab81 mov edi, eax
0049ab83 lea esi, [ecx + 0xc]
0049ab86 mov ebx, dword ptr [edi]
0049ab88 mov dword ptr [esi], ebx
0049ab8a mov ebx, dword ptr [edi + 4]
0049ab8d mov dword ptr [esi + 4], ebx
0049ab90 mov edi, dword ptr [edi + 8]
0049ab93 mov dword ptr [esi + 8], edi
0049ab96 mov esi, eax
0049ab98 mov edi, ecx
0049ab9a add eax, 0xc
0049ab9d mov ebx, dword ptr [esi]
0049ab9f add ecx, 0xc4
0049aba5 mov dword ptr [edi], ebx
0049aba7 dec edx
0049aba8 mov ebx, dword ptr [esi + 4]
0049abab mov dword ptr [edi + 4], ebx
0049abae mov esi, dword ptr [esi + 8]
0049abb1 mov dword ptr [edi + 8], esi
0049abb4 jne 0x49ab81
0049abb6 pop edi
0049abb7 pop esi
0049abb8 pop ebx
0049abb9 ret
0049abba nop
0049abbb nop
0049abbc nop
0049abbd nop
0049abbe nop
0049abbf nop
0049abc0 mov edx, dword ptr [esp + 4]
0049abc4 sub esp, 0x40
0049abc7 test byte ptr [edx + 0x52c], 0x80
0049abce jne 0x49ae27
0049abd4 mov eax, dword ptr [edx + 0x74c]
0049abda push ebx
0049abdb push ebp
0049abdc push esi
0049abdd mov eax, dword ptr [eax + 0xf8]
0049abe3 push edi
0049abe4 test eax, eax
0049abe6 mov dword ptr [edx + 0x32c], eax
0049abec jle 0x49ac25
0049abee xor ecx, ecx
0049abf0 test eax, eax
0049abf2 jle 0x49ac25
0049abf4 mov eax, 0xfc
0049abf9 mov ebp, dword ptr [edx + 0x74c]
0049abff mov esi, eax
0049ac01 add esi, ebp
0049ac03 lea edi, [edx + eax - 0x70]
0049ac07 inc ecx
0049ac08 add eax, 0xc
0049ac0b mov ebx, dword ptr [esi]
0049ac0d mov dword ptr [edi], ebx
0049ac0f mov ebx, dword ptr [esi + 4]
0049ac12 mov dword ptr [edi + 4], ebx
0049ac15 mov esi, dword ptr [esi + 8]
0049ac18 mov dword ptr [edi + 8], esi
0049ac1b mov esi, dword ptr [edx + 0x32c]
0049ac21 cmp ecx, esi
0049ac23 jl 0x49abf9
0049ac25 mov eax, dword ptr [edx + 0x32c]
0049ac2b mov dword ptr [esp + 0x10], 0
0049ac33 test eax, eax
0049ac35 jle 0x49acc2
0049ac3b dec eax
0049ac3c mov dword ptr [esp + 0x54], 0
0049ac44 test eax, eax
0049ac46 jle 0x49acab
0049ac48 lea ecx, [edx + 0x8c]
0049ac4e fld dword ptr [ecx + 0x10]
0049ac51 fcomp dword ptr [ecx + 4]
0049ac54 fnstsw ax
0049ac56 test ah, 1
0049ac59 je 0x49ac94
0049ac5b mov eax, ecx
0049ac5d mov ebx, ecx
0049ac5f mov esi, dword ptr [eax]
0049ac61 mov edi, dword ptr [eax + 4]
0049ac64 mov dword ptr [esp + 0x18], edi
0049ac68 mov eax, dword ptr [eax + 8]
0049ac6b mov dword ptr [esp + 0x1c], eax
0049ac6f lea eax, [ecx + 0xc]
0049ac72 mov edi, eax
0049ac74 mov ebp, dword ptr [edi]
0049ac76 mov dword ptr [ebx], ebp
0049ac78 mov ebp, dword ptr [edi + 4]
0049ac7b mov dword ptr [ebx + 4], ebp
0049ac7e mov edi, dword ptr [edi + 8]
0049ac81 mov dword ptr [ebx + 8], edi
0049ac84 mov dword ptr [eax], esi
0049ac86 mov esi, dword ptr [esp + 0x18]
0049ac8a mov dword ptr [eax + 4], esi
0049ac8d mov esi, dword ptr [esp + 0x1c]
0049ac91 mov dword ptr [eax + 8], esi
0049ac94 mov eax, dword ptr [esp + 0x54]
0049ac98 mov esi, dword ptr [edx + 0x32c]
0049ac9e inc eax
0049ac9f add ecx, 0xc
0049aca2 dec esi
0049aca3 mov dword ptr [esp + 0x54], eax
0049aca7 cmp eax, esi
0049aca9 jl 0x49ac4e
0049acab mov ecx, dword ptr [esp + 0x10]
0049acaf mov eax, dword ptr [edx + 0x32c]
0049acb5 inc ecx
0049acb6 cmp ecx, eax
0049acb8 mov dword ptr [esp + 0x10], ecx
0049acbc jl 0x49ac3b
0049acc2 add edx, 0x8c
0049acc8 mov dword ptr [esp + 0x20], 0
0049acd0 mov dword ptr [esp + 0x24], 0
0049acd8 mov dword ptr [esp + 0x28], 0
0049ace0 mov dword ptr [esp + 0x2c], 0
0049ace8 mov dword ptr [esp + 0x30], 0
0049acf0 mov dword ptr [esp + 0x34], 0
0049acf8 mov dword ptr [esp + 0x38], 0
0049ad00 mov dword ptr [esp + 0x3c], 0
0049ad08 mov dword ptr [esp + 0x40], 0
0049ad10 mov dword ptr [esp + 0x44], 0
0049ad18 mov dword ptr [esp + 0x48], 0
0049ad20 mov dword ptr [esp + 0x4c], 0
0049ad28 mov ecx, edx
0049ad2a mov esi, 4
0049ad2f fld dword ptr [ecx]
0049ad31 fcomp dword ptr [0x5b23f8]
0049ad37 fnstsw ax
0049ad39 test ah, 1
0049ad3c je 0x49ad69
0049ad3e fld dword ptr [ecx + 8]
0049ad41 fcomp dword ptr [0x5b23f8]
0049ad47 fnstsw ax
0049ad49 test ah, 0x41
0049ad4c jne 0x49ad69
0049ad4e mov eax, ecx
0049ad50 mov edi, dword ptr [eax]
0049ad52 mov dword ptr [esp + 0x20], edi
0049ad56 mov edi, dword ptr [eax + 4]
0049ad59 mov dword ptr [esp + 0x24], edi
0049ad5d mov eax, dword ptr [eax + 8]
0049ad60 mov dword ptr [esp + 0x28], eax
0049ad64 jmp 0x49ae0c
0049ad69 fld dword ptr [ecx]
0049ad6b fcomp dword ptr [0x5b23f8]
0049ad71 fnstsw ax
0049ad73 test ah, 0x41
0049ad76 jne 0x49ada0
0049ad78 fld dword ptr [ecx + 8]
0049ad7b fcomp dword ptr [0x5b23f8]
0049ad81 fnstsw ax
0049ad83 test ah, 0x41
0049ad86 jne 0x49ada0
0049ad88 mov eax, ecx
0049ad8a mov edi, dword ptr [eax]
0049ad8c mov dword ptr [esp + 0x2c], edi
0049ad90 mov edi, dword ptr [eax + 4]
0049ad93 mov dword ptr [esp + 0x30], edi
0049ad97 mov eax, dword ptr [eax + 8]
0049ad9a mov dword ptr [esp + 0x34], eax
0049ad9e jmp 0x49ae0c
0049ada0 fld dword ptr [ecx]
0049ada2 fcomp dword ptr [0x5b23f8]
0049ada8 fnstsw ax
0049adaa test ah, 1
0049adad je 0x49add7
0049adaf fld dword ptr [ecx + 8]
0049adb2 fcomp dword ptr [0x5b23f8]
0049adb8 fnstsw ax
0049adba test ah, 1
0049adbd je 0x49add7
0049adbf mov eax, ecx
0049adc1 mov edi, dword ptr [eax]
0049adc3 mov dword ptr [esp + 0x38], edi
0049adc7 mov edi, dword ptr [eax + 4]
0049adca mov dword ptr [esp + 0x3c], edi
0049adce mov eax, dword ptr [eax + 8]
0049add1 mov dword ptr [esp + 0x40], eax
0049add5 jmp 0x49ae0c
0049add7 fld dword ptr [ecx]
0049add9 fcomp dword ptr [0x5b23f8]
0049addf fnstsw ax
0049ade1 test ah, 0x41
0049ade4 jne 0x49ae0c
0049ade6 fld dword ptr [ecx + 8]
0049ade9 fcomp dword ptr [0x5b23f8]
0049adef fnstsw ax
0049adf1 test ah, 1
0049adf4 je 0x49ae0c
0049adf6 mov eax, ecx
0049adf8 mov edi, dword ptr [eax]
0049adfa mov dword ptr [esp + 0x44], edi
0049adfe mov edi, dword ptr [eax + 4]
0049ae01 mov dword ptr [esp + 0x48], edi
0049ae05 mov eax, dword ptr [eax + 8]
0049ae08 mov dword ptr [esp + 0x4c], eax
0049ae0c add ecx, 0xc
0049ae0f dec esi
0049ae10 jne 0x49ad2f
0049ae16 mov ecx, 0xc
0049ae1b lea esi, [esp + 0x20]
0049ae1f mov edi, edx
0049ae21 rep movsd dword ptr es:[edi], dword ptr [esi]
0049ae23 pop edi
0049ae24 pop esi
0049ae25 pop ebp
0049ae26 pop ebx
0049ae27 add esp, 0x40
0049ae2a ret
0049ae2b nop
0049ae2c nop
0049ae2d nop
0049ae2e nop
0049ae2f nop
0049ae30 sub esp, 0x24
0049ae33 lea eax, [esp]
0049ae37 push ebx
0049ae38 push edi
0049ae39 mov edi, dword ptr [esp + 0x30]
0049ae3d push eax
0049ae3e lea ecx, [edi + 0x364]
0049ae44 push ecx
0049ae45 call 0x532a00
0049ae4a mov eax, dword ptr [edi + 0x32c]
0049ae50 add esp, 8
0049ae53 xor ebx, ebx
0049ae55 test eax, eax
0049ae57 jle 0x49aeb5
0049ae59 push esi
0049ae5a lea esi, [edi + 0x8c]
0049ae60 lea edx, [esp + 0xc]
0049ae64 push edx
0049ae65 push esi
0049ae66 call 0x532910
0049ae6b fadd dword ptr [edi + 0x330]
0049ae71 lea eax, [esp + 0x20]
0049ae75 push eax
0049ae76 push esi
0049ae77 fstp dword ptr [esi + 0x150]
0049ae7d call 0x532910
0049ae82 fadd dword ptr [edi + 0x334]
0049ae88 lea ecx, [esp + 0x34]
0049ae8c push ecx
0049ae8d push esi
0049ae8e fstp dword ptr [esi + 0x154]
0049ae94 call 0x532910
0049ae99 fadd dword ptr [edi + 0x338]
0049ae9f add esp, 0x18
0049aea2 inc ebx
0049aea3 add esi, 0xc
0049aea6 fstp dword ptr [esi + 0x14c]
0049aeac cmp ebx, dword ptr [edi + 0x32c]
0049aeb2 jl 0x49ae60
0049aeb4 pop esi
0049aeb5 pop edi
0049aeb6 pop ebx
0049aeb7 add esp, 0x24
0049aeba ret
0049aebb nop
0049aebc nop
0049aebd nop
0049aebe nop
0049aebf nop
0049aec0 push esi
0049aec1 mov esi, dword ptr [esp + 8]
0049aec5 test byte ptr [esi + 0x52c], 0x80
0049aecc jne 0x49af62
0049aed2 mov eax, dword ptr [esi + 0x760]
0049aed8 xor ecx, ecx
0049aeda lea edx, [esi + 0x820]
0049aee0 fld dword ptr [eax + 0x124]
0049aee6 fld dword ptr [eax + 0x120]
0049aeec fld dword ptr [esp + 0xc]
0049aef0 fmul dword ptr [esi + 0x374]
0049aef6 fchs
0049aef8 fadd dword ptr [edx]
0049aefa fst dword ptr [esp + 8]
0049aefe fcomp dword ptr [0x5b23f8]
0049af04 fnstsw ax
0049af06 test ah, 0x41
0049af09 jne 0x49af39
0049af0b test ecx, ecx
0049af0d je 0x49af20
0049af0f cmp ecx, 1
0049af12 je 0x49af20
0049af14 fld st(1)
0049af16 fsub st(1)
0049af18 fmul dword ptr [0x5b260c]
0049af1e jmp 0x49af2a
0049af20 fld st(1)
0049af22 fsub st(1)
0049af24 fmul dword ptr [0x5b25e8]
0049af2a fld dword ptr [esp + 8]
0049af2e fcomp st(1)
0049af30 fnstsw ax
0049af32 test ah, 0x41
0049af35 je 0x49af50
0049af37 jmp 0x49af4a
0049af39 fld st(1)
0049af3b fchs
0049af3d fld dword ptr [esp + 8]
0049af41 fcomp st(1)
0049af43 fnstsw ax
0049af45 test ah, 0x41
0049af48 jne 0x49af50
0049af4a fstp st(0)
0049af4c fld dword ptr [esp + 8]
0049af50 fstp dword ptr [edx]
0049af52 inc ecx
0049af53 add edx, 0xc4
0049af59 cmp ecx, 4
0049af5c jl 0x49aeec
0049af5e fstp st(0)
0049af60 fstp st(0)
0049af62 pop esi
0049af63 ret
0049af64 nop
0049af65 nop
0049af66 nop
0049af67 nop
0049af68 nop
0049af69 nop
0049af6a nop
0049af6b nop
0049af6c nop
0049af6d nop
0049af6e nop
0049af6f nop
0049af70 push esi
0049af71 mov esi, dword ptr [esp + 8]
0049af75 mov al, byte ptr [esi + 0x7f]
0049af78 test al, al
0049af7a je 0x49b08a
0049af80 mov al, byte ptr [esi + 0x7d]
0049af83 test al, al
0049af85 jne 0x49b08a
0049af8b mov al, byte ptr [esi + 0x7c]
0049af8e test al, al
0049af90 je 0x49b08a
0049af96 push ebx
0049af97 push edi
0049af98 push esi
0049af99 call 0x417190
0049af9e add esp, 4
0049afa1 lea ebx, [esi + 0x330]
0049afa7 lea edi, [esi + 8]
0049afaa push ebx
0049afab mov ecx, edi
0049afad call 0x474440
0049afb2 push 1
0049afb4 push ebx
0049afb5 mov ecx, edi
0049afb7 call 0x474060
0049afbc mov al, byte ptr [esi + 0x11]
0049afbf test al, al
0049afc1 je 0x49afcc
0049afc3 push esi
0049afc4 call 0x499520
0049afc9 add esp, 4
0049afcc xor eax, eax
0049afce mov ax, word ptr [esi + 0x2c]
0049afd2 mov dword ptr [esi + 0x460], eax
0049afd8 and eax, 0xf
0049afdb mov dword ptr [esi + 0x464], eax
0049afe1 mov ecx, dword ptr [0x6573f8]
0049afe7 test ecx, ecx
0049afe9 je 0x49afff
0049afeb cmp eax, 1
0049afee je 0x49aff5
0049aff0 cmp eax, 0xa
0049aff3 jne 0x49afff
0049aff5 mov dword ptr [esi + 0x464], 2
0049afff movsx eax, word ptr [edi]
0049b002 lea ebx, [esi + 0x37c]
0049b008 lea edi, [eax + eax*4]
0049b00b mov eax, dword ptr [0x628bc0]
0049b010 shl edi, 4
0049b013 mov ecx, dword ptr [eax + 0xc]
0049b016 lea edx, [ecx + edi + 0x28]
0049b01a push edx
0049b01b push ebx
0049b01c call 0x532910
0049b021 call 0x5a2a10
0049b026 fstp dword ptr [esi + 0x414]
0049b02c mov eax, dword ptr [0x628bc0]
0049b031 mov ecx, dword ptr [eax + 0xc]
0049b034 lea edx, [ecx + edi + 0x1c]
0049b038 push edx
0049b039 push ebx
0049b03a call 0x532910
0049b03f fcomp dword ptr [0x5b23f8]
0049b045 add esp, 0x10
0049b048 pop edi
0049b049 pop ebx
0049b04a fnstsw ax
0049b04c test ah, 1
0049b04f je 0x49b08a
0049b051 fld dword ptr [esi + 0x414]
0049b057 fcomp dword ptr [0x5b23f8]
0049b05d fnstsw ax
0049b05f test ah, 0x41
0049b062 jne 0x49b078
0049b064 fld dword ptr [0x5b4a14]
0049b06a fsub dword ptr [esi + 0x414]
0049b070 fstp dword ptr [esi + 0x414]
0049b076 pop esi
0049b077 ret
0049b078 fld dword ptr [0x5b4a10]
0049b07e fsub dword ptr [esi + 0x414]
0049b084 fstp dword ptr [esi + 0x414]
0049b08a pop esi
0049b08b ret
0049b08c nop
0049b08d nop
0049b08e nop
0049b08f nop
0049b090 sub esp, 0x48
0049b093 push ebx
0049b094 mov ebx, dword ptr [esp + 0x54]
0049b098 push ebp
0049b099 mov ebp, dword ptr [0x628bc0]
0049b09f cmp ebx, 1
0049b0a2 push esi
0049b0a3 mov dword ptr [esp + 0xc], ebp
0049b0a7 jge 0x49b0ae
0049b0a9 mov ebx, 1
0049b0ae mov ecx, dword ptr [esp + 0x64]
0049b0b2 mov esi, dword ptr [esp + 0x58]
0049b0b6 xor eax, eax
0049b0b8 push edi
0049b0b9 cmp ecx, 1
0049b0bc lea edi, [esi + 8]
0049b0bf setne al
0049b0c2 push ebx
0049b0c3 mov ecx, edi
0049b0c5 mov dword ptr [esp + 0x18], eax
0049b0c9 call 0x473210
0049b0ce mov edx, dword ptr [ebp + 0xc]
0049b0d1 lea ecx, [ebx + ebx*4]
0049b0d4 shl ecx, 4
0049b0d7 lea eax, [ecx + edx + 4]
0049b0db mov ecx, dword ptr [ecx + edx + 4]
0049b0df mov dword ptr [esp + 0x1c], ecx
0049b0e3 mov edx, dword ptr [eax + 4]
0049b0e6 mov dword ptr [esp + 0x20], edx
0049b0ea mov eax, dword ptr [eax + 8]
0049b0ed mov dword ptr [esp + 0x24], eax
0049b0f1 mov al, byte ptr [esi + 0x52c]
0049b0f7 test al, 8
0049b0f9 je 0x49b14e
0049b0fb cmp dword ptr [0x606ac4], 0x1c0
0049b105 jle 0x49b14e
0049b107 mov ecx, dword ptr [esp + 0x64]
0049b10b fld dword ptr [ecx]
0049b10d fcomp dword ptr [0x5b23f8]
0049b113 fnstsw ax
0049b115 test ah, 0x40
0049b118 je 0x49b13a
0049b11a fld dword ptr [ecx + 4]
0049b11d fcomp dword ptr [0x5b23f8]
0049b123 fnstsw ax
0049b125 test ah, 0x40
0049b128 je 0x49b13a
0049b12a fld dword ptr [ecx + 8]
0049b12d fcomp dword ptr [0x5b23f8]
0049b133 fnstsw ax
0049b135 test ah, 0x40
0049b138 jne 0x49b14e
0049b13a mov edx, dword ptr [ecx]
0049b13c mov dword ptr [esp + 0x1c], edx
0049b140 mov eax, dword ptr [ecx + 4]
0049b143 mov dword ptr [esp + 0x20], eax
0049b147 mov ecx, dword ptr [ecx + 8]
0049b14a mov dword ptr [esp + 0x24], ecx
0049b14e lea edx, [esp + 0x1c]
0049b152 push 1
0049b154 push edx
0049b155 mov ecx, edi
0049b157 call 0x474060
0049b15c xor ebp, ebp
0049b15e lea eax, [esi + 0x7bc]
0049b164 mov dword ptr [esi + 0x408], ebp
0049b16a mov dword ptr [esi + 0x404], ebp
0049b170 mov dword ptr [esi + 0x400], ebp
0049b176 mov dword ptr [esp + 0x68], eax
0049b17a jmp 0x49b17e
0049b17c fstp st(0)
0049b17e mov ecx, dword ptr [esp + 0x68]
0049b182 push ebx
0049b183 call 0x473210
0049b188 push ebp
0049b189 mov ecx, edi
0049b18b call 0x4745f0
0049b190 mov ecx, dword ptr [eax]
0049b192 inc ebp
0049b193 mov dword ptr [esp + 0x28], ecx
0049b197 mov ecx, dword ptr [esp + 0x68]
0049b19b fld dword ptr [esp + 0x28]
0049b19f fadd dword ptr [esi + 0x400]
0049b1a5 mov edx, dword ptr [eax + 4]
0049b1a8 add ecx, 0xc4
0049b1ae mov dword ptr [esp + 0x2c], edx
0049b1b2 cmp ebp, 4
0049b1b5 mov eax, dword ptr [eax + 8]
0049b1b8 mov dword ptr [esp + 0x68], ecx
0049b1bc fst dword ptr [esi + 0x400]
0049b1c2 fld dword ptr [esp + 0x2c]
0049b1c6 fadd dword ptr [esi + 0x404]
0049b1cc mov dword ptr [esp + 0x30], eax
0049b1d0 fst dword ptr [esp + 0x5c]
0049b1d4 fstp dword ptr [esi + 0x404]
0049b1da fld dword ptr [esp + 0x30]
0049b1de fadd dword ptr [esi + 0x408]
0049b1e4 fst dword ptr [esp + 0x18]
0049b1e8 fstp dword ptr [esi + 0x408]
0049b1ee jl 0x49b17c
0049b1f0 fmul dword ptr [0x5b2468]
0049b1f6 movsx eax, word ptr [edi]
0049b1f9 fstp dword ptr [esi + 0x400]
0049b1ff fld dword ptr [esp + 0x5c]
0049b203 fmul dword ptr [0x5b2468]
0049b209 mov ecx, dword ptr [esp + 0x10]
0049b20d lea eax, [eax + eax*4]
0049b210 shl eax, 4
0049b213 lea ebp, [esi + 0x3d0]
0049b219 fstp dword ptr [esi + 0x404]
0049b21f fld dword ptr [esp + 0x18]
0049b223 fmul dword ptr [0x5b2468]
0049b229 fstp dword ptr [esi + 0x408]
0049b22f mov edx, dword ptr [ecx + 0xc]
0049b232 fld dword ptr [eax + edx + 0x1c]
0049b236 fstp dword ptr [ebp]
0049b239 mov edx, dword ptr [ecx + 0xc]
0049b23c fld dword ptr [eax + edx + 0x20]
0049b240 fstp dword ptr [esi + 0x3d4]
0049b246 mov ecx, dword ptr [ecx + 0xc]
0049b249 fld dword ptr [eax + ecx + 0x24]
0049b24d fstp dword ptr [esi + 0x3d8]
0049b253 mov ecx, edi
0049b255 call 0x474420
0049b25a mov edx, dword ptr [eax]
0049b25c mov ecx, edi
0049b25e mov dword ptr [esi + 0x3c4], edx
0049b264 call 0x474420
0049b269 mov eax, dword ptr [eax + 4]
0049b26c mov ecx, edi
0049b26e mov dword ptr [esi + 0x3c8], eax
0049b274 call 0x474420
0049b279 mov ecx, dword ptr [eax + 8]
0049b27c lea ebx, [esi + 0x3b8]
0049b282 push ebx
0049b283 lea eax, [esi + 0x3c4]
0049b289 push ebp
0049b28a push eax
0049b28b mov dword ptr [esi + 0x3cc], ecx
0049b291 call 0x532880
0049b296 push ebx
0049b297 push ebx
0049b298 call 0x5328d0
0049b29d lea eax, [esi + 0x3c4]
0049b2a3 push ebp
0049b2a4 push eax
0049b2a5 push ebx
0049b2a6 call 0x532880
0049b2ab push ebp
0049b2ac push ebp
0049b2ad call 0x5328d0
0049b2b2 lea edx, [esp + 0x5c]
0049b2b6 push edx
0049b2b7 push ebx
0049b2b8 call 0x532a00
0049b2bd mov ebx, dword ptr [esp + 0x44]
0049b2c1 push ebx
0049b2c2 push esi
0049b2c3 call 0x417260
0049b2c8 push ebx
0049b2c9 push esi
0049b2ca call 0x417310
0049b2cf add esp, 0x40
0049b2d2 mov ecx, edi
0049b2d4 lea ebx, [esi + 0x3e8]
0049b2da call 0x474420
0049b2df mov edx, dword ptr [eax]
0049b2e1 mov ecx, ebx
0049b2e3 lea ebp, [esi + 0x3f4]
0049b2e9 mov dword ptr [ecx], edx
0049b2eb mov edx, dword ptr [eax + 4]
0049b2ee mov dword ptr [ecx + 4], edx
0049b2f1 mov eax, dword ptr [eax + 8]
0049b2f4 mov dword ptr [ecx + 8], eax
0049b2f7 mov ecx, edi
0049b2f9 call 0x474430
0049b2fe mov edx, dword ptr [eax]
0049b300 mov ecx, ebp
0049b302 mov dword ptr [ecx], edx
0049b304 mov edx, dword ptr [eax + 4]
0049b307 mov dword ptr [ecx + 4], edx
0049b30a mov eax, dword ptr [eax + 8]
0049b30d mov dword ptr [ecx + 8], eax
0049b310 lea ecx, [esi + 0x3dc]
0049b316 push ecx
0049b317 push ebp
0049b318 push ebx
0049b319 call 0x532880
0049b31e mov ebx, dword ptr [esp + 0x70]
0049b322 lea edx, [esp + 0x40]
0049b326 push edx
0049b327 push ebx
0049b328 call 0x532910
0049b32d fstp dword ptr [esp + 0x3c]
0049b331 lea eax, [esp + 0x54]
0049b335 push eax
0049b336 push ebx
0049b337 call 0x532910
0049b33c fstp dword ptr [esp + 0x48]
0049b340 lea ecx, [esp + 0x68]
0049b344 push ecx
0049b345 push ebx
0049b346 call 0x532910
0049b34b mov al, byte ptr [esi + 0x52c]
0049b351 add esp, 0x24
0049b354 fstp dword ptr [esp + 0x30]
0049b358 test al, 8
0049b35a je 0x49b3b7
0049b35c cmp dword ptr [0x606ac4], 0x1c0
0049b366 jle 0x49b3b7
0049b368 fld dword ptr [ebx]
0049b36a fcomp dword ptr [0x5b23f8]
0049b370 fnstsw ax
0049b372 test ah, 0x40
0049b375 je 0x49b397
0049b377 fld dword ptr [ebx + 4]
0049b37a fcomp dword ptr [0x5b23f8]
0049b380 fnstsw ax
0049b382 test ah, 0x40
0049b385 je 0x49b397
0049b387 fld dword ptr [ebx + 8]
0049b38a fcomp dword ptr [0x5b23f8]
0049b390 fnstsw ax
0049b392 test ah, 0x40
0049b395 jne 0x49b3b7
0049b397 mov eax, dword ptr [esp + 0x1c]
0049b39b mov ecx, dword ptr [esp + 0x20]
0049b39f lea edx, [esi + 0x330]
0049b3a5 mov dword ptr [esi + 0x330], eax
0049b3ab mov eax, dword ptr [esp + 0x24]
0049b3af mov dword ptr [edx + 4], ecx
0049b3b2 mov dword ptr [edx + 8], eax
0049b3b5 jmp 0x49b3f8
0049b3b7 mov eax, dword ptr [esp + 0x60]
0049b3bb mov ecx, dword ptr [esp + 0x10]
0049b3bf mov edx, dword ptr [ecx + 0xc]
0049b3c2 lea eax, [eax + eax*4]
0049b3c5 shl eax, 4
0049b3c8 fld dword ptr [eax + edx + 4]
0049b3cc fadd dword ptr [esp + 0x28]
0049b3d0 fstp dword ptr [esi + 0x330]
0049b3d6 mov edx, dword ptr [ecx + 0xc]
0049b3d9 fld dword ptr [eax + edx + 8]
0049b3dd fadd dword ptr [esp + 0x2c]
0049b3e1 fstp dword ptr [esi + 0x334]
0049b3e7 mov ecx, dword ptr [ecx + 0xc]
0049b3ea fld dword ptr [eax + ecx + 0xc]
0049b3ee fadd dword ptr [esp + 0x30]
0049b3f2 fstp dword ptr [esi + 0x338]
0049b3f8 xor ebx, ebx
0049b3fa mov ecx, edi
0049b3fc push ebx
0049b3fd call 0x4745f0
0049b402 push esi
0049b403 mov dword ptr [esi + 0x35c], ebx
0049b409 mov byte ptr [esi + 0x7e], bl
0049b40c call 0x49af70
0049b411 mov edi, dword ptr [esp + 0x18]
0049b415 push edi
0049b416 push esi
0049b417 call 0x417260
0049b41c push edi
0049b41d push esi
0049b41e call 0x417310
0049b423 mov al, byte ptr [esi + 0x52c]
0049b429 add esp, 0x14
0049b42c test al, 0x80
0049b42e push esi
0049b42f jne 0x49b483
0049b431 call 0x49ae30
0049b436 add esp, 4
0049b439 lea ecx, [esi + 0x7ec]
0049b43f lea eax, [esi + 0x1dc]
0049b445 mov edx, 4
0049b44a mov ebx, eax
0049b44c lea edi, [ecx + 0xc]
0049b44f mov ebp, dword ptr [ebx]
0049b451 mov dword ptr [edi], ebp
0049b453 mov ebp, dword ptr [ebx + 4]
0049b456 mov dword ptr [edi + 4], ebp
0049b459 mov ebx, dword ptr [ebx + 8]
0049b45c mov dword ptr [edi + 8], ebx
0049b45f mov edi, eax
0049b461 mov ebx, ecx
0049b463 add eax, 0xc
0049b466 mov ebp, dword ptr [edi]
0049b468 add ecx, 0xc4
0049b46e mov dword ptr [ebx], ebp
0049b470 dec edx
0049b471 mov ebp, dword ptr [edi + 4]
0049b474 mov dword ptr [ebx + 4], ebp
0049b477 mov edi, dword ptr [edi + 8]
0049b47a mov dword ptr [ebx + 8], edi
0049b47d jne 0x49b44a
0049b47f xor ebx, ebx
0049b481 jmp 0x49b48b
0049b483 call 0x49ae30
0049b488 add esp, 4
0049b48b mov al, byte ptr [esi + 0x7f]
0049b48e pop edi
0049b48f test al, al
0049b491 je 0x49b4eb
0049b493 push 0x628f70
0049b498 push esi
0049b499 call 0x499a70
0049b49e fstp dword ptr [esi + 0x41c]
0049b4a4 fld dword ptr [esi + 0x424]
0049b4aa fsubr dword ptr [esi + 0x334]
0049b4b0 push 0x628f70
0049b4b5 push esi
0049b4b6 mov dword ptr [esi + 0x424], ebx
0049b4bc fstp dword ptr [esi + 0x334]
0049b4c2 call 0x499a70
0049b4c7 fstp dword ptr [esi + 0x41c]
0049b4cd add esp, 0x10
0049b4d0 lea eax, [esi + 0x820]
0049b4d6 mov ecx, 4
0049b4db mov dword ptr [eax + 0x1c], ebx
0049b4de mov dword ptr [eax], ebx
0049b4e0 mov dword ptr [eax + 8], ebx
0049b4e3 add eax, 0xc4
0049b4e8 dec ecx
0049b4e9 jne 0x49b4db
0049b4eb push esi
0049b4ec call 0x49ae30
0049b4f1 xor eax, eax
0049b4f3 add esp, 4
0049b4f6 mov ax, word ptr [esi + 0x2c]
0049b4fa mov dword ptr [esi + 0x460], eax
0049b500 and eax, 0xf
0049b503 mov dword ptr [esi + 0x464], eax
0049b509 pop esi
0049b50a pop ebp
0049b50b pop ebx
0049b50c add esp, 0x48
0049b50f ret
0049b510 mov eax, dword ptr [esp + 8]
0049b514 push ebx
0049b515 push esi
0049b516 mov esi, dword ptr [esp + 0xc]
0049b51a xor ebx, ebx
0049b51c push edi
0049b51d mov dword ptr [esi], eax
0049b51f mov byte ptr [esi + 0x7e], bl
0049b522 mov byte ptr [esi + 0x7d], bl
0049b525 mov byte ptr [esi + 0x7c], 1
0049b529 call 0x5321f0
0049b52e fld dword ptr [esp + 0x20]
0049b532 fmul dword ptr [esp + 0x20]
0049b536 fld dword ptr [esp + 0x24]
0049b53a fmul dword ptr [esp + 0x24]
0049b53e mov ecx, dword ptr [esp + 0x20]
0049b542 mov edx, dword ptr [esp + 0x24]
0049b546 mov dword ptr [esi + 0x74], eax
0049b549 mov eax, dword ptr [esp + 0x28]
0049b54d mov dword ptr [esi + 0x5c], ebx
0049b550 mov dword ptr [esi + 0x60], ebx
0049b553 mov dword ptr [esi + 0x64], ebx
0049b556 mov dword ptr [esi + 0x6c], ebx
0049b559 faddp st(1)
0049b55b mov dword ptr [esi + 0x68], ebx
0049b55e push ecx
0049b55f mov dword ptr [esi + 0x70], ebx
0049b562 mov dword ptr [esi + 0x330], ebx
0049b568 fstp dword ptr [esp]
0049b56b mov dword ptr [esi + 0x334], ebx
0049b571 mov dword ptr [esi + 0x338], ebx
0049b577 mov dword ptr [esi + 0x33c], ebx
0049b57d mov dword ptr [esi + 0x340], ebx
0049b583 mov dword ptr [esi + 0x344], ebx
0049b589 mov dword ptr [esi + 0x35c], ebx
0049b58f mov dword ptr [esi + 0x3a8], ecx
0049b595 mov dword ptr [esi + 0x3ac], edx
0049b59b mov dword ptr [esi + 0x3b0], eax
0049b5a1 call 0x5327d0
0049b5a6 fst dword ptr [esi + 0x3b4]
0049b5ac fld st(0)
0049b5ae fmul st(1)
0049b5b0 fld dword ptr [esp + 0x2c]
0049b5b4 fmul dword ptr [esp + 0x2c]
0049b5b8 faddp st(1)
0049b5ba fstp dword ptr [esp]
0049b5bd fstp st(0)
0049b5bf call 0x5327d0
0049b5c4 mov eax, dword ptr [esi + 0x52c]
0049b5ca add esp, 4
0049b5cd fstp dword ptr [esi + 0x3b4]
0049b5d3 test al, 0x10
0049b5d5 je 0x49b5f1
0049b5d7 fld dword ptr [esp + 0x20]
0049b5db fmul dword ptr [esp + 0x24]
0049b5df fmul dword ptr [esp + 0x28]
0049b5e3 fmul dword ptr [0x5b368c]
0049b5e9 fstp dword ptr [esi + 0x354]
0049b5ef jmp 0x49b5fb
0049b5f1 mov ecx, dword ptr [esp + 0x18]
0049b5f5 mov dword ptr [esi + 0x354], ecx
0049b5fb test al, 4
0049b5fd je 0x49b615
0049b5ff cmp dword ptr [0x6573fc], ebx
0049b605 je 0x49b615
0049b607 fld dword ptr [esi + 0x354]
0049b60d fmul dword ptr [0x5b240c]
0049b613 jmp 0x49b62f
0049b615 mov edx, dword ptr [esi + 0x558]
0049b61b cmp dword ptr [edx + 0x518], ebx
0049b621 je 0x49b635
0049b623 fld dword ptr [esi + 0x354]
0049b629 fmul dword ptr [0x5b49b0]
0049b62f fstp dword ptr [esi + 0x354]
0049b635 fld dword ptr [0x5b24a8]
0049b63b fdiv dword ptr [esi + 0x354]
0049b641 mov ecx, 0x3f800000
0049b646 mov eax, 1
0049b64b lea edi, [esi + 0x4e4]
0049b651 push esi
0049b652 fstp dword ptr [esi + 0x358]
0049b658 fld dword ptr [esi + 0x354]
0049b65e fmul dword ptr [0x5b2460]
0049b664 fst dword ptr [esi + 0x394]
0049b66a fld dword ptr [0x5b24a8]
0049b670 fdiv st(1)
0049b672 fstp dword ptr [esi + 0x398]
0049b678 mov dword ptr [esi + 0x388], ebx
0049b67e mov dword ptr [esi + 0x38c], ebx
0049b684 mov dword ptr [esi + 0x390], ebx
0049b68a mov dword ptr [esi + 0x39c], ebx
0049b690 mov dword ptr [esi + 0x3a0], ecx
0049b696 mov dword ptr [esi + 0x3a4], ebx
0049b69c mov dword ptr [esi + 0x460], eax
0049b6a2 mov dword ptr [esi + 0x464], eax
0049b6a8 mov dword ptr [esi + 0x84], ecx
0049b6ae mov ecx, 0xa
0049b6b3 xor eax, eax
0049b6b5 mov word ptr [esi + 0x418], bx
0049b6bc mov dword ptr [esi + 0x420], ebx
0049b6c2 mov dword ptr [esi + 0x424], ebx
0049b6c8 mov dword ptr [esi + 0x428], ebx
0049b6ce mov dword ptr [esi + 0x360], ebx
0049b6d4 mov dword ptr [esi + 0x40c], ebx
0049b6da mov dword ptr [esi + 0x42c], ebx
0049b6e0 mov dword ptr [esi + 0x430], ebx
0049b6e6 mov dword ptr [esi + 0x434], ebx
0049b6ec mov dword ptr [esi + 0x438], ebx
0049b6f2 mov dword ptr [esi + 0x43c], ebx
0049b6f8 mov dword ptr [esi + 0x454], ebx
0049b6fe mov dword ptr [esi + 0x458], ebx
0049b704 mov dword ptr [esi + 0x45c], ebx
0049b70a rep stosd dword ptr es:[edi], eax
0049b70c fstp st(0)
0049b70e mov byte ptr [esi + 0x80], bl
0049b714 mov word ptr [esi + 0x41a], bx
0049b71b mov byte ptr [esi + 0x7f], 1
0049b71f mov dword ptr [esi + 0x3c], ebx
0049b722 call 0x49abc0
0049b727 push esi
0049b728 call 0x49ae30
0049b72d add esp, 8
0049b730 pop edi
0049b731 pop esi
0049b732 pop ebx
0049b733 ret
0049b734 nop
0049b735 nop
0049b736 nop
0049b737 nop
0049b738 nop
0049b739 nop
0049b73a nop
0049b73b nop
0049b73c nop
0049b73d nop
0049b73e nop
0049b73f nop
0049b740 mov eax, dword ptr [esp + 4]
0049b744 fld dword ptr [eax + 0x53c]
0049b74a fld st(0)
0049b74c fmul dword ptr [eax + 0x33c]
0049b752 fmul dword ptr [0x5b2828]
0049b758 fadd dword ptr [eax + 0x330]
0049b75e fstp dword ptr [eax + 0x330]
0049b764 fld dword ptr [eax + 0x340]
0049b76a fmul dword ptr [0x5b2828]
0049b770 fadd dword ptr [eax + 0x334]
0049b776 fstp dword ptr [eax + 0x334]
0049b77c fmul dword ptr [eax + 0x344]
0049b782 fmul dword ptr [0x5b2828]
0049b788 fadd dword ptr [eax + 0x338]
0049b78e fstp dword ptr [eax + 0x338]
0049b794 ret
0049b795 nop
0049b796 nop
0049b797 nop
0049b798 nop
0049b799 nop
0049b79a nop
0049b79b nop
0049b79c nop
0049b79d nop
0049b79e nop
0049b79f nop
0049b7a0 sub esp, 0xc
0049b7a3 push edi
0049b7a4 mov edi, dword ptr [esp + 0x14]
0049b7a8 mov al, byte ptr [edi + 0x7f]
0049b7ab test al, al
0049b7ad je 0x49b85f
0049b7b3 mov al, byte ptr [edi + 0x7d]
0049b7b6 test al, al
0049b7b8 jne 0x49b85f
0049b7be fld dword ptr [edi + 0x33c]
0049b7c4 fmul dword ptr [0x5b2828]
0049b7ca test byte ptr [edi + 0x52c], 0x80
0049b7d1 fstp dword ptr [esp + 4]
0049b7d5 fld dword ptr [edi + 0x340]
0049b7db fmul dword ptr [0x5b2828]
0049b7e1 fstp dword ptr [esp + 8]
0049b7e5 fld dword ptr [edi + 0x344]
0049b7eb fmul dword ptr [0x5b2828]
0049b7f1 fstp dword ptr [esp + 0xc]
0049b7f5 fld dword ptr [esp + 4]
0049b7f9 fadd dword ptr [edi + 0x330]
0049b7ff fstp dword ptr [edi + 0x330]
0049b805 fld dword ptr [esp + 8]
0049b809 fadd dword ptr [edi + 0x334]
0049b80f fstp dword ptr [edi + 0x334]
0049b815 fld dword ptr [esp + 0xc]
0049b819 fadd dword ptr [edi + 0x338]
0049b81f fstp dword ptr [edi + 0x338]
0049b825 jne 0x49b85f
0049b827 push ebx
0049b828 push esi
0049b829 lea esi, [edi + 0x7f8]
0049b82f mov ebx, 4
0049b834 lea eax, [esp + 0xc]
0049b838 push esi
0049b839 push eax
0049b83a push esi
0049b83b push 1
0049b83d call 0x532300
0049b842 add esp, 0x10
0049b845 add esi, 0xc4
0049b84b dec ebx
0049b84c jne 0x49b834
0049b84e push edi
0049b84f call 0x4a2880
0049b854 push edi
0049b855 call 0x4a2790
0049b85a add esp, 8
0049b85d pop esi
0049b85e pop ebx
0049b85f pop edi
0049b860 add esp, 0xc
0049b863 ret
0049b864 nop
0049b865 nop
0049b866 nop
0049b867 nop
0049b868 nop
0049b869 nop
0049b86a nop
0049b86b nop
0049b86c nop
0049b86d nop
0049b86e nop
0049b86f nop
0049b870 mov eax, dword ptr [esp + 0xc]
0049b874 sub esp, 0x90
0049b87a lea ecx, [esp + 0x48]
0049b87e push eax
0049b87f push ecx
0049b880 call 0x532600
0049b885 mov edx, dword ptr [esp + 0xa0]
0049b88c lea eax, [esp + 8]
0049b890 push edx
0049b891 push eax
0049b892 call 0x5325a0
0049b897 lea ecx, [esp + 0x7c]
0049b89b lea edx, [esp + 0x58]
0049b89f push ecx
0049b8a0 lea eax, [esp + 0x14]
0049b8a4 push edx
0049b8a5 push eax
0049b8a6 call 0x532470
0049b8ab mov ecx, dword ptr [esp + 0xbc]
0049b8b2 lea edx, [esp + 0x40]
0049b8b6 push ecx
0049b8b7 push edx
0049b8b8 call 0x532660
0049b8bd mov eax, dword ptr [esp + 0xb8]
0049b8c4 lea ecx, [esp + 0x48]
0049b8c8 push eax
0049b8c9 lea edx, [esp + 0x94]
0049b8d0 push ecx
0049b8d1 push edx
0049b8d2 call 0x532470
0049b8d7 add esp, 0xc0
0049b8dd ret
0049b8de nop
0049b8df nop
0049b8e0 sub esp, 0xc0
0049b8e6 push esi
0049b8e7 mov esi, dword ptr [esp + 0xc8]
0049b8ee push edi
0049b8ef mov al, byte ptr [esi + 0x7f]
0049b8f2 test al, al
0049b8f4 je 0x49ba24
0049b8fa mov al, byte ptr [esi + 0x7d]
0049b8fd test al, al
0049b8ff jne 0x49ba24
0049b905 fld dword ptr [esi + 0x388]
0049b90b fmul dword ptr [0x5b2828]
0049b911 lea ecx, [esp + 0x80]
0049b918 fstp dword ptr [esp + 8]
0049b91c fld dword ptr [esi + 0x38c]
0049b922 fmul dword ptr [0x5b2828]
0049b928 fstp dword ptr [esp + 0xc]
0049b92c fld dword ptr [esi + 0x390]
0049b932 fmul dword ptr [0x5b2828]
0049b938 mov eax, dword ptr [esp + 0xc]
0049b93c push eax
0049b93d push ecx
0049b93e fstp dword ptr [esp + 0x18]
0049b942 call 0x532600
0049b947 mov edx, dword ptr [esp + 0x10]
0049b94b lea eax, [esp + 0x1c]
0049b94f push edx
0049b950 push eax
0049b951 call 0x5325a0
0049b956 lea ecx, [esp + 0x6c]
0049b95a lea edx, [esp + 0x90]
0049b961 push ecx
0049b962 lea eax, [esp + 0x28]
0049b966 push edx
0049b967 push eax
0049b968 call 0x532470
0049b96d mov ecx, dword ptr [esp + 0x2c]
0049b971 lea edx, [esp + 0x54]
0049b975 push ecx
0049b976 push edx
0049b977 call 0x532660
0049b97c lea eax, [esp + 0xc8]
0049b983 lea ecx, [esp + 0x5c]
0049b987 push eax
0049b988 lea edx, [esp + 0x84]
0049b98f push ecx
0049b990 push edx
0049b991 call 0x532470
0049b996 lea edi, [esi + 0x364]
0049b99c lea eax, [esp + 0xd4]
0049b9a3 push edi
0049b9a4 push eax
0049b9a5 push edi
0049b9a6 call 0x532470
0049b9ab mov eax, dword ptr [0x657408]
0049b9b0 add esp, 0x3c
0049b9b3 test eax, eax
0049b9b5 je 0x49b9fb
0049b9b7 mov eax, dword ptr [esi + 0xdac]
0049b9bd test eax, eax
0049b9bf je 0x49b9fb
0049b9c1 mov ecx, dword ptr [esi + 0x520]
0049b9c7 push ecx
0049b9c8 call 0x490140
0049b9cd add esp, 4
0049b9d0 cmp eax, 2
0049b9d3 jg 0x49b9fb
0049b9d5 mov eax, dword ptr [esi + 0x70]
0049b9d8 test eax, eax
0049b9da jne 0x49b9f1
0049b9dc push esi
0049b9dd mov dword ptr [esi + 0xda8], 0
0049b9e7 call 0x4a0a40
0049b9ec add esp, 4
0049b9ef jmp 0x49b9fb
0049b9f1 mov dword ptr [esi + 0xda8], 1
0049b9fb push esi
0049b9fc call 0x49ae30
0049ba01 mov al, byte ptr [esi + 0x80]
0049ba07 add esp, 4
0049ba0a dec al
0049ba0c mov byte ptr [esi + 0x80], al
0049ba12 jne 0x49ba24
0049ba14 push edi
0049ba15 call 0x4a4810
0049ba1a add esp, 4
0049ba1d mov byte ptr [esi + 0x80], 0x20
0049ba24 pop edi
0049ba25 pop esi
0049ba26 add esp, 0xc0
0049ba2c ret
0049ba2d nop
0049ba2e nop
0049ba2f nop
0049ba30 push ebx
0049ba31 push esi
0049ba32 mov esi, dword ptr [esp + 0xc]
0049ba36 push edi
0049ba37 test byte ptr [esi + 0x52c], 1
0049ba3e jne 0x49babb
0049ba40 fld dword ptr [esp + 0x18]
0049ba44 fcomp dword ptr [0x5b25e8]
0049ba4a fnstsw ax
0049ba4c test ah, 0x41
0049ba4f jne 0x49babb
0049ba51 mov eax, dword ptr [esi + 0x364]
0049ba57 mov ecx, dword ptr [esi + 0x368]
0049ba5d mov edx, dword ptr [esi + 0x36c]
0049ba63 mov dword ptr [esi + 0x490], eax
0049ba69 mov eax, dword ptr [esp + 0x14]
0049ba6d mov dword ptr [esi + 0x494], ecx
0049ba73 mov dword ptr [esi + 0x498], edx
0049ba79 pop edi
0049ba7a mov ecx, dword ptr [eax]
0049ba7c mov dword ptr [esi + 0x49c], ecx
0049ba82 mov edx, dword ptr [eax + 4]
0049ba85 mov ecx, dword ptr [esi + 0x37c]
0049ba8b mov dword ptr [esi + 0x4a0], edx
0049ba91 mov eax, dword ptr [eax + 8]
0049ba94 mov edx, dword ptr [esi + 0x380]
0049ba9a mov dword ptr [esi + 0x4a4], eax
0049baa0 mov eax, dword ptr [esi + 0x384]
0049baa6 mov dword ptr [esi + 0x4a8], ecx
0049baac mov dword ptr [esi + 0x4ac], edx
0049bab2 mov dword ptr [esi + 0x4b0], eax
0049bab8 pop esi
0049bab9 pop ebx
0049baba ret
0049babb mov edi, dword ptr [esp + 0x14]
0049babf lea ebx, [esi + 0x49c]
0049bac5 fld dword ptr [esp + 0x18]
0049bac9 mov ecx, dword ptr [edi]
0049bacb fcomp dword ptr [0x5b23f0]
0049bad1 mov dword ptr [ebx], ecx
0049bad3 mov edx, dword ptr [edi + 4]
0049bad6 mov dword ptr [esi + 0x4a0], edx
0049badc mov eax, dword ptr [edi + 8]
0049badf mov dword ptr [esi + 0x4a4], eax
0049bae5 fnstsw ax
0049bae7 test ah, 1
0049baea je 0x49bb65
0049baec push ebp
0049baed lea ebp, [esi + 0x364]
0049baf3 push edi
0049baf4 push ebp
0049baf5 call 0x532910
0049bafa fcomp dword ptr [0x5b23f8]
0049bb00 add esp, 8
0049bb03 push edi
0049bb04 push ebp
0049bb05 fnstsw ax
0049bb07 test ah, 1
0049bb0a je 0x49bb18
0049bb0c call 0x532910
0049bb11 add esp, 8
0049bb14 fchs
0049bb16 jmp 0x49bb20
0049bb18 call 0x532910
0049bb1d add esp, 8
0049bb20 fcomp dword ptr [0x5b23f0]
0049bb26 pop ebp
0049bb27 fnstsw ax
0049bb29 test ah, 0x41
0049bb2c jne 0x49bb65
0049bb2e lea edi, [esi + 0x490]
0049bb34 lea ecx, [esi + 0x37c]
0049bb3a push edi
0049bb3b push ecx
0049bb3c push ebx
0049bb3d call 0x532880
0049bb42 push edi
0049bb43 push edi
0049bb44 call 0x5328d0
0049bb49 add esi, 0x4a8
0049bb4f push esi
0049bb50 push ebx
0049bb51 push edi
0049bb52 call 0x532880
0049bb57 push esi
0049bb58 push esi
0049bb59 call 0x5328d0
0049bb5e add esp, 0x28
0049bb61 pop edi
0049bb62 pop esi
0049bb63 pop ebx
0049bb64 ret
0049bb65 lea edi, [esi + 0x4a8]
0049bb6b lea edx, [esi + 0x364]
0049bb71 push edi
0049bb72 push ebx
0049bb73 push edx
0049bb74 call 0x532880
0049bb79 push edi
0049bb7a push edi
0049bb7b call 0x5328d0
0049bb80 add esi, 0x490
0049bb86 push esi
0049bb87 push edi
0049bb88 push ebx
0049bb89 call 0x532880
0049bb8e push esi
0049bb8f push esi
0049bb90 call 0x5328d0
0049bb95 add esp, 0x28
0049bb98 pop edi
0049bb99 pop esi
0049bb9a pop ebx
0049bb9b ret
0049bb9c nop
0049bb9d nop
0049bb9e nop
0049bb9f nop
0049bba0 mov ecx, dword ptr [esp + 4]
0049bba4 fld dword ptr [0x5b260c]
0049bbaa mov eax, dword ptr [ecx + 0x558]
0049bbb0 mov edx, dword ptr [eax + 0x518]
0049bbb6 test edx, edx
0049bbb8 je 0x49bbc4
0049bbba fstp st(0)
0049bbbc fld dword ptr [0x5b49c0]
0049bbc2 jmp 0x49bbe8
0049bbc4 test byte ptr [ecx + 0x52c], 0x80
0049bbcb je 0x49bbe8
0049bbcd fld dword ptr [ecx + 0x354]
0049bbd3 fcomp dword ptr [0x5b260c]
0049bbd9 fnstsw ax
0049bbdb test ah, 1
0049bbde je 0x49bbe8
0049bbe0 fstp st(0)
0049bbe2 fld dword ptr [0x5b49bc]
0049bbe8 fcom dword ptr [ecx + 0x388]
0049bbee fnstsw ax
0049bbf0 test ah, 1
0049bbf3 je 0x49bbfd
0049bbf5 fst dword ptr [ecx + 0x388]
0049bbfb jmp 0x49bc18
0049bbfd fld st(0)
0049bbff fchs
0049bc01 fcom dword ptr [ecx + 0x388]
0049bc07 fnstsw ax
0049bc09 test ah, 0x41
0049bc0c jne 0x49bc16
0049bc0e fstp dword ptr [ecx + 0x388]
0049bc14 jmp 0x49bc18
0049bc16 fstp st(0)
0049bc18 fcom dword ptr [ecx + 0x38c]
0049bc1e fnstsw ax
0049bc20 test ah, 1
0049bc23 je 0x49bc2d
0049bc25 fst dword ptr [ecx + 0x38c]
0049bc2b jmp 0x49bc48
0049bc2d fld st(0)
0049bc2f fchs
0049bc31 fcom dword ptr [ecx + 0x38c]
0049bc37 fnstsw ax
0049bc39 test ah, 0x41
0049bc3c jne 0x49bc46
0049bc3e fstp dword ptr [ecx + 0x38c]
0049bc44 jmp 0x49bc48
0049bc46 fstp st(0)
0049bc48 fcom dword ptr [ecx + 0x390]
0049bc4e fnstsw ax
0049bc50 test ah, 1
0049bc53 je 0x49bc5c
0049bc55 fstp dword ptr [ecx + 0x390]
0049bc5b ret
0049bc5c fchs
0049bc5e fcom dword ptr [ecx + 0x390]
0049bc64 fnstsw ax
0049bc66 test ah, 0x41
0049bc69 jne 0x49bc72
0049bc6b fstp dword ptr [ecx + 0x390]
0049bc71 ret
0049bc72 fstp st(0)
0049bc74 ret
0049bc75 nop
0049bc76 nop
0049bc77 nop
0049bc78 nop
0049bc79 nop
0049bc7a nop
0049bc7b nop
0049bc7c nop
0049bc7d nop
0049bc7e nop
0049bc7f nop
0049bc80 mov ecx, dword ptr [esp + 4]
0049bc84 mov edx, 0x3f400000
0049bc89 fld dword ptr [ecx + 0xd64]
0049bc8f fcomp dword ptr [0x5b260c]
0049bc95 fnstsw ax
0049bc97 test ah, 0x41
0049bc9a jne 0x49bca4
0049bc9c mov dword ptr [ecx + 0xd64], edx
0049bca2 jmp 0x49bcc1
0049bca4 fld dword ptr [ecx + 0xd64]
0049bcaa fcomp dword ptr [0x5b3f68]
0049bcb0 fnstsw ax
0049bcb2 test ah, 1
0049bcb5 je 0x49bcc1
0049bcb7 mov dword ptr [ecx + 0xd64], 0xbf400000
0049bcc1 fld dword ptr [ecx + 0xd68]
0049bcc7 fcomp dword ptr [0x5b260c]
0049bccd fnstsw ax
0049bccf test ah, 0x41
0049bcd2 jne 0x49bcdc
0049bcd4 mov dword ptr [ecx + 0xd68], edx
0049bcda jmp 0x49bcf9
0049bcdc fld dword ptr [ecx + 0xd68]
0049bce2 fcomp dword ptr [0x5b3f68]
0049bce8 fnstsw ax
0049bcea test ah, 1
0049bced je 0x49bcf9
0049bcef mov dword ptr [ecx + 0xd68], 0xbf400000
0049bcf9 fld dword ptr [ecx + 0xd6c]
0049bcff fcomp dword ptr [0x5b260c]
0049bd05 fnstsw ax
0049bd07 test ah, 0x41
0049bd0a jne 0x49bd13
0049bd0c mov dword ptr [ecx + 0xd6c], edx
0049bd12 ret
0049bd13 fld dword ptr [ecx + 0xd6c]
0049bd19 fcomp dword ptr [0x5b3f68]
0049bd1f fnstsw ax
0049bd21 test ah, 1
0049bd24 je 0x49bd30
0049bd26 mov dword ptr [ecx + 0xd6c], 0xbf400000
0049bd30 ret
0049bd31 nop
0049bd32 nop
0049bd33 nop
0049bd34 nop
0049bd35 nop
0049bd36 nop
0049bd37 nop
0049bd38 nop
0049bd39 nop
0049bd3a nop
0049bd3b nop
0049bd3c nop
0049bd3d nop
0049bd3e nop
0049bd3f nop
0049bd40 sub esp, 0x4c
0049bd43 push ebp
0049bd44 push esi
0049bd45 mov esi, dword ptr [esp + 0x58]
0049bd49 push edi
0049bd4a mov al, byte ptr [esi + 0x7f]
0049bd4d test al, al
0049bd4f je 0x49c344
0049bd55 mov al, byte ptr [esi + 0x7c]
0049bd58 test al, al
0049bd5a je 0x49c344
0049bd60 mov al, byte ptr [esi + 0x7d]
0049bd63 test al, al
0049bd65 jne 0x49c344
0049bd6b mov eax, dword ptr [esi + 0x10b8]
0049bd71 lea ecx, [esp + 0x24]
0049bd75 push eax
0049bd76 lea edx, [esp + 0x24]
0049bd7a push ecx
0049bd7b mov ecx, dword ptr [esi]
0049bd7d lea eax, [esp + 0x24]
0049bd81 push edx
0049bd82 mov edx, dword ptr [esi + 0x78]
0049bd85 push eax
0049bd86 push ecx
0049bd87 push edx
0049bd88 push 3
0049bd8a push 1
0049bd8c call 0x414b10
0049bd91 add esp, 0x20
0049bd94 test eax, eax
0049bd96 je 0x49c344
0049bd9c test byte ptr [esi + 0x52c], 0x80
0049bda3 je 0x49bdb2
0049bda5 lea eax, [esp + 0x28]
0049bda9 push eax
0049bdaa push esi
0049bdab call 0x4998c0
0049bdb0 jmp 0x49bdbd
0049bdb2 lea ecx, [esp + 0x28]
0049bdb6 push ecx
0049bdb7 push esi
0049bdb8 call 0x499a70
0049bdbd mov eax, dword ptr [esp + 0x34]
0049bdc1 mov ecx, dword ptr [esp + 0x38]
0049bdc5 fld st(0)
0049bdc7 fsub dword ptr [esi + 0x41c]
0049bdcd fimul dword ptr [esp + 0x24]
0049bdd1 mov edx, dword ptr [esp + 0x30]
0049bdd5 add esp, 8
0049bdd8 mov dword ptr [esp + 0x38], eax
0049bddc mov dword ptr [esp + 0x3c], ecx
0049bde0 lea eax, [esp + 0x28]
0049bde4 mov dword ptr [esp + 0x34], edx
0049bde8 mov edx, dword ptr [esi + 0x424]
0049bdee lea ecx, [esi + 0x364]
0049bdf4 push eax
0049bdf5 push ecx
0049bdf6 mov dword ptr [esp + 0x14], edx
0049bdfa fstp dword ptr [esp + 0x64]
0049bdfe fstp dword ptr [esi + 0x41c]
0049be04 call 0x532910
0049be09 fstp dword ptr [esi + 0x39c]
0049be0f lea edx, [esp + 0x30]
0049be13 lea eax, [esi + 0x370]
0049be19 push edx
0049be1a push eax
0049be1b call 0x532910
0049be20 fstp dword ptr [esi + 0x3a0]
0049be26 lea ecx, [esp + 0x38]
0049be2a lea edi, [esi + 0x37c]
0049be30 push ecx
0049be31 push edi
0049be32 mov dword ptr [esp + 0x30], edi
0049be36 call 0x532910
0049be3b mov edx, dword ptr [esi + 0x3a0]
0049be41 lea eax, [esp + 0x4c]
0049be45 fstp dword ptr [esi + 0x3a4]
0049be4b push edx
0049be4c push eax
0049be4d push esi
0049be4e call 0x49ba30
0049be53 fld dword ptr [0x5b23f8]
0049be59 fld dword ptr [esi + 0x428]
0049be5f fcomp dword ptr [0x5b2738]
0049be65 add esp, 0x24
0049be68 fnstsw ax
0049be6a test ah, 0x41
0049be6d je 0x49be7f
0049be6f mov ecx, dword ptr [esi + 0x558]
0049be75 mov eax, dword ptr [ecx + 0x518]
0049be7b test eax, eax
0049be7d je 0x49be91
0049be7f fstp st(0)
0049be81 fild dword ptr [esp + 0x20]
0049be85 fmul dword ptr [0x5b4a20]
0049be8b fmul dword ptr [esi + 0x84]
0049be91 fld dword ptr [esi + 0x340]
0049be97 fsub st(1)
0049be99 lea ebp, [esi + 0x33c]
0049be9f fstp dword ptr [esp + 0x10]
0049bea3 mov edx, dword ptr [esp + 0x10]
0049bea7 fstp st(0)
0049bea9 fld dword ptr [ebp]
0049beac fcomp dword ptr [0x5b23f8]
0049beb2 fld dword ptr [ebp]
0049beb5 mov dword ptr [esi + 0x340], edx
0049bebb fnstsw ax
0049bebd test ah, 1
0049bec0 je 0x49bec4
0049bec2 fchs
0049bec4 fld dword ptr [esi + 0x344]
0049beca fcomp dword ptr [0x5b23f8]
0049bed0 fld dword ptr [esi + 0x344]
0049bed6 fnstsw ax
0049bed8 test ah, 1
0049bedb je 0x49bedf
0049bedd fchs
0049bedf fld st(1)
0049bee1 fcomp st(1)
0049bee3 fnstsw ax
0049bee5 test ah, 0x41
0049bee8 jne 0x49bef4
0049beea fmul dword ptr [0x5b2468]
0049bef0 faddp st(1)
0049bef2 jmp 0x49bf02
0049bef4 fxch st(1)
0049bef6 fmul dword ptr [0x5b2468]
0049befc fadd st(1)
0049befe fxch st(1)
0049bf00 fstp st(0)
0049bf02 fstp dword ptr [esi + 0x35c]
0049bf08 fld dword ptr [esp + 0x5c]
0049bf0c fsub dword ptr [esi + 0x420]
0049bf12 fld dword ptr [esi + 0x40c]
0049bf18 fmul dword ptr [0x5b3090]
0049bf1e mov eax, dword ptr [esp + 0x5c]
0049bf22 faddp st(1)
0049bf24 mov dword ptr [esi + 0x420], eax
0049bf2a fmul dword ptr [0x5b272c]
0049bf30 fstp dword ptr [esi + 0x40c]
0049bf36 fld dword ptr [esp + 0x5c]
0049bf3a fsub dword ptr [esp + 0x10]
0049bf3e fstp dword ptr [esp + 0x14]
0049bf42 fld dword ptr [esi + 0x3a0]
0049bf48 fcomp dword ptr [0x5b4a0c]
0049bf4e fnstsw ax
0049bf50 test ah, 1
0049bf53 jne 0x49bf62
0049bf55 test byte ptr [esi + 0x52c], 0x80
0049bf5c je 0x49c19a
0049bf62 fld dword ptr [esp + 0xc]
0049bf66 fcomp dword ptr [0x5b27b4]
0049bf6c fnstsw ax
0049bf6e test ah, 1
0049bf71 je 0x49c19a
0049bf77 lea ecx, [esi + 0x400]
0049bf7d mov edx, dword ptr [esi + 0x400]
0049bf83 mov dword ptr [esp + 0x40], edx
0049bf87 mov edx, dword ptr [esp + 0x10]
0049bf8b mov eax, dword ptr [ecx + 4]
0049bf8e mov dword ptr [esp + 0x14], edx
0049bf92 mov dword ptr [esp + 0x44], eax
0049bf96 mov al, byte ptr [esi + 0x2c]
0049bf99 mov ecx, dword ptr [ecx + 8]
0049bf9c and eax, 0xf
0049bf9f mov edi, eax
0049bfa1 mov dword ptr [esp + 0x48], ecx
0049bfa5 lea ecx, [esi + 8]
0049bfa8 fld dword ptr [edi*8 + 0x5d0b94]
0049bfaf fstp dword ptr [esp + 0x5c]
0049bfb3 call 0x474420
0049bfb8 mov ecx, dword ptr [eax]
0049bfba fld dword ptr [esi + 0x3a0]
0049bfc0 fcomp dword ptr [0x5b2698]
0049bfc6 mov dword ptr [esp + 0x4c], ecx
0049bfca mov edx, dword ptr [eax + 4]
0049bfcd mov dword ptr [esp + 0x50], edx
0049bfd1 mov eax, dword ptr [eax + 8]
0049bfd4 mov dword ptr [esp + 0x54], eax
0049bfd8 fnstsw ax
0049bfda test ah, 0x41
0049bfdd jne 0x49bff0
0049bfdf test byte ptr [esi + 0x52c], 0x80
0049bfe6 jne 0x49bff0
0049bfe8 mov dword ptr [esp + 0x5c], 0x3dcccccd
0049bff0 mov ecx, dword ptr [esp + 0x5c]
0049bff4 lea edx, [esp + 0x40]
0049bff8 push ecx
0049bff9 lea eax, [esp + 0x50]
0049bffd push edx
0049bffe push eax
0049bfff push esi
0049c000 call 0x496610
0049c005 fld dword ptr [esi + 0x3a0]
0049c00b fcomp dword ptr [0x5b23f8]
0049c011 add esp, 0x10
0049c014 fnstsw ax
0049c016 test ah, 1
0049c019 je 0x49c025
0049c01b mov dword ptr [esi + 0xdb0], 0
0049c025 fld dword ptr [esi + 0x3a0]
0049c02b fcomp dword ptr [0x5b2698]
0049c031 fnstsw ax
0049c033 test ah, 1
0049c036 je 0x49c095
0049c038 fld dword ptr [esp + 0x14]
0049c03c fcomp dword ptr [0x5b2628]
0049c042 fnstsw ax
0049c044 test ah, 1
0049c047 je 0x49c095
0049c049 fld dword ptr [edi*8 + 0x5d0b98]
0049c050 fmul dword ptr [esp + 0x14]
0049c054 lea eax, [esi + 0x388]
0049c05a push eax
0049c05b push 0x3f733333
0049c060 fsubr dword ptr [esi + 0x340]
0049c066 push eax
0049c067 push 1
0049c069 fstp dword ptr [esi + 0x340]
0049c06f fld dword ptr [ebp]
0049c072 fmul dword ptr [0x5b2610]
0049c078 fstp dword ptr [ebp]
0049c07b fld dword ptr [esi + 0x344]
0049c081 fmul dword ptr [0x5b2610]
0049c087 fstp dword ptr [esi + 0x344]
0049c08d call 0x532360
0049c092 add esp, 0x10
0049c095 mov eax, dword ptr [0x657a2c]
0049c09a test eax, eax
0049c09c je 0x49c0f0
0049c09e fld dword ptr [esi + 0x3a0]
0049c0a4 fcomp dword ptr [0x5b4a1c]
0049c0aa fnstsw ax
0049c0ac test ah, 1
0049c0af je 0x49c0f0
0049c0b1 fld dword ptr [esi + 0x504]
0049c0b7 fcomp dword ptr [0x5b2410]
0049c0bd fnstsw ax
0049c0bf test ah, 1
0049c0c2 je 0x49c0f0
0049c0c4 mov eax, dword ptr [esi + 0xb50]
0049c0ca test eax, eax
0049c0cc jne 0x49c0f0
0049c0ce push 0
0049c0d0 push 0x42200000
0049c0d5 push 3
0049c0d7 push 4
0049c0d9 push -1
0049c0db push 1
0049c0dd push esi
0049c0de call 0x40f020
0049c0e3 add esp, 0x1c
0049c0e6 mov dword ptr [esi + 0x504], 0x42200000
0049c0f0 mov edi, dword ptr [esp + 0x18]
0049c0f4 mov eax, dword ptr [0x606ac4]
0049c0f9 lea ecx, [esi + 0x330]
0049c0ff push 0
0049c101 push ecx
0049c102 lea ecx, [esi + 8]
0049c105 mov dword ptr [esi + 0x88], eax
0049c10b call 0x473330
0049c110 test ax, ax
0049c113 je 0x49c14f
0049c115 fld dword ptr [esi + 0x340]
0049c11b fcomp dword ptr [0x5b23f8]
0049c121 fnstsw ax
0049c123 test ah, 0x41
0049c126 jne 0x49c14f
0049c128 fld dword ptr [esi + 0x334]
0049c12e fsub dword ptr [esi + 0x404]
0049c134 fcomp dword ptr [0x5b2608]
0049c13a fnstsw ax
0049c13c test ah, 0x41
0049c13f jne 0x49c14f
0049c141 fld dword ptr [esi + 0x340]
0049c147 fchs
0049c149 fstp dword ptr [esi + 0x340]
0049c14f fld dword ptr [ebp]
0049c152 fcomp dword ptr [0x5b23f8]
0049c158 fnstsw ax
0049c15a test ah, 0x40
0049c15d je 0x49c183
0049c15f fld dword ptr [ebp + 4]
0049c162 fcomp dword ptr [0x5b23f8]
0049c168 fnstsw ax
0049c16a test ah, 0x40
0049c16d je 0x49c183
0049c16f fld dword ptr [ebp + 8]
0049c172 fcomp dword ptr [0x5b23f8]
0049c178 fnstsw ax
0049c17a test ah, 0x40
0049c17d jne 0x49c32e
0049c183 add esi, 0x348
0049c189 push esi
0049c18a push ebp
0049c18b call 0x5328d0
0049c190 add esp, 8
0049c193 pop edi
0049c194 pop esi
0049c195 pop ebp
0049c196 add esp, 0x4c
0049c199 ret
0049c19a fld dword ptr [esp + 0x14]
0049c19e fcomp dword ptr [0x5b2460]
0049c1a4 fld dword ptr [esp + 0xc]
0049c1a8 fnstsw ax
0049c1aa test ah, 0x41
0049c1ad jne 0x49c27d
0049c1b3 fcomp dword ptr [0x5b4a18]
0049c1b9 fnstsw ax
0049c1bb test ah, 1
0049c1be je 0x49c0f4
0049c1c4 test byte ptr [esi + 0x52c], 1
0049c1cb je 0x49c1d6
0049c1cd push esi
0049c1ce call 0x493dd0
0049c1d3 add esp, 4
0049c1d6 mov ecx, dword ptr [esp + 0x14]
0049c1da push 0
0049c1dc push ecx
0049c1dd push 5
0049c1df push 0
0049c1e1 push -1
0049c1e3 push 1
0049c1e5 push esi
0049c1e6 call 0x40f020
0049c1eb fld dword ptr [0x5b4a18]
0049c1f1 fsub dword ptr [esp + 0x28]
0049c1f5 mov dword ptr [esi + 0x424], 0xbd4ccccd
0049c1ff fst dword ptr [esp + 0x2c]
0049c203 fadd dword ptr [esi + 0x334]
0049c209 mov edx, dword ptr [esp + 0x2c]
0049c20d push edx
0049c20e push esi
0049c20f fstp dword ptr [esi + 0x334]
0049c215 call 0x49aec0
0049c21a mov eax, dword ptr [esi + 0x52c]
0049c220 add esp, 0x24
0049c223 test ah, 4
0049c226 jne 0x49c244
0049c228 fld dword ptr [esi + 0x3a0]
0049c22e fcomp dword ptr [0x5b25e8]
0049c234 fnstsw ax
0049c236 test ah, 0x41
0049c239 jne 0x49c244
0049c23b mov word ptr [esi + 0x418], 0
0049c244 mov al, byte ptr [esi + 0x2c]
0049c247 mov ecx, dword ptr [esp + 0x14]
0049c24b and eax, 0xf
0049c24e push esi
0049c24f fld dword ptr [eax*8 + 0x5d0b98]
0049c256 fmul dword ptr [0x5b261c]
0049c25c mov dword ptr [esi + 0xad0], ecx
0049c262 fmul dword ptr [esp + 0x18]
0049c266 fadd dword ptr [esp + 0x60]
0049c26a fstp dword ptr [esi + 0x340]
0049c270 call 0x49bba0
0049c275 add esp, 4
0049c278 jmp 0x49c0f4
0049c27d fcomp dword ptr [0x5b2738]
0049c283 fnstsw ax
0049c285 test ah, 1
0049c288 je 0x49c0f4
0049c28e fld dword ptr [esi + 0x334]
0049c294 fsub dword ptr [esp + 0xc]
0049c298 mov eax, dword ptr [esi + 0x52c]
0049c29e xor ecx, ecx
0049c2a0 test ah, 4
0049c2a3 mov dword ptr [esi + 0x424], ecx
0049c2a9 fstp dword ptr [esi + 0x334]
0049c2af jne 0x49c2cb
0049c2b1 fld dword ptr [esi + 0x3a0]
0049c2b7 fcomp dword ptr [0x5b49d8]
0049c2bd fnstsw ax
0049c2bf test ah, 0x41
0049c2c2 jne 0x49c2cb
0049c2c4 mov word ptr [esi + 0x418], cx
0049c2cb fld dword ptr [esp + 0x10]
0049c2cf fcomp dword ptr [0x5b23f8]
0049c2d5 fnstsw ax
0049c2d7 test ah, 0x41
0049c2da jne 0x49c30c
0049c2dc fld dword ptr [esp + 0x5c]
0049c2e0 fcomp dword ptr [0x5b23f8]
0049c2e6 fnstsw ax
0049c2e8 test ah, 0x41
0049c2eb jne 0x49c30c
0049c2ed fld dword ptr [esp + 0x10]
0049c2f1 fld dword ptr [esp + 0x5c]
0049c2f5 fcomp st(1)
0049c2f7 fnstsw ax
0049c2f9 test ah, 0x41
0049c2fc jne 0x49c304
0049c2fe fstp st(0)
0049c300 fld dword ptr [esp + 0x5c]
0049c304 fstp dword ptr [esi + 0x340]
0049c30a jmp 0x49c316
0049c30c mov edx, dword ptr [esp + 0x5c]
0049c310 mov dword ptr [esi + 0x340], edx
0049c316 fld dword ptr [esp + 0xc]
0049c31a push ecx
0049c31b fchs
0049c31d fstp dword ptr [esp]
0049c320 push esi
0049c321 call 0x49aec0
0049c326 add esp, 8
0049c329 jmp 0x49c0f4
0049c32e mov edx, dword ptr [edi]
0049c330 mov eax, dword ptr [edi + 4]
0049c333 mov ecx, dword ptr [edi + 8]
0049c336 add esi, 0x348
0049c33c mov dword ptr [esi], edx
0049c33e mov dword ptr [esi + 4], eax
0049c341 mov dword ptr [esi + 8], ecx
0049c344 pop edi
0049c345 pop esi
0049c346 pop ebp
0049c347 add esp, 0x4c
0049c34a ret
0049c34b nop
0049c34c nop
0049c34d nop
0049c34e nop
0049c34f nop
0049c350 mov ax, word ptr [ecx + 0x26]
0049c354 push esi
0049c355 mov esi, dword ptr [esp + 8]
0049c359 mov dx, word ptr [esi + 0x26]
0049c35d cmp ax, dx
0049c360 jge 0x49c368
0049c362 mov al, 1
0049c364 pop esi
0049c365 ret 4
0049c368 jne 0x49c390
0049c36a mov eax, dword ptr [ecx + 0x5c]
0049c36d mov edx, dword ptr [esi + 0x5c]
0049c370 cmp eax, edx
0049c372 je 0x49c381
0049c374 xor ecx, ecx
0049c376 cmp eax, edx
0049c378 setl cl
0049c37b mov al, cl
0049c37d pop esi
0049c37e ret 4
0049c381 mov dx, word ptr [ecx]
0049c384 xor eax, eax
0049c386 cmp dx, word ptr [esi]
0049c389 pop esi
0049c38a setl al
0049c38d ret 4
0049c390 xor al, al
0049c392 pop esi
0049c393 ret 4
0049c396 nop
0049c397 nop
0049c398 nop
0049c399 nop
0049c39a nop
0049c39b nop
0049c39c nop
0049c39d nop
0049c39e nop
0049c39f nop
0049c3a0 mov eax, dword ptr [0x65b348]
0049c3a5 sub esp, 0x50
0049c3a8 lea ecx, [esp]
0049c3ac push esi
0049c3ad push 0x5d0c4c
0049c3b2 push eax
0049c3b3 push 0x5cc588
0049c3b8 push ecx
0049c3b9 call 0x5a0fbf
0049c3be lea edx, [esp + 0x14]
0049c3c2 push edx
0049c3c3 call 0x59ddd0
0049c3c8 mov esi, eax
0049c3ca add esp, 0x14
0049c3cd test esi, esi
0049c3cf jle 0x49c42c
0049c3d1 push 0x5d0c40
0049c3d6 push 1
0049c3d8 push esi
0049c3d9 call 0x59ecb0
0049c3de push esi
0049c3df mov dword ptr [0x628f88], eax
0049c3e4 push eax
0049c3e5 lea eax, [esp + 0x18]
0049c3e9 push eax
0049c3ea call 0x59db50
0049c3ef add esp, 0x18
0049c3f2 test eax, eax
0049c3f4 jle 0x49c41d
0049c3f6 mov eax, 0x6c16c16d
0049c3fb mov ecx, dword ptr [0x628f88]
0049c401 mul esi
0049c403 sub esi, edx
0049c405 mov dword ptr [0x628f84], ecx
0049c40b shr esi, 1
0049c40d add esi, edx
0049c40f shr esi, 8
0049c412 mov dword ptr [0x628f80], esi
0049c418 pop esi
0049c419 add esp, 0x50
0049c41c ret
0049c41d mov edx, dword ptr [0x628f88]
0049c423 push edx
0049c424 call 0x59ecd0
0049c429 add esp, 4
0049c42c pop esi
0049c42d add esp, 0x50
0049c430 ret
0049c431 nop
0049c432 nop
0049c433 nop
0049c434 nop
0049c435 nop
0049c436 nop
0049c437 nop
0049c438 nop
0049c439 nop
0049c43a nop
0049c43b nop
0049c43c nop
0049c43d nop
0049c43e nop
0049c43f nop
0049c440 mov eax, dword ptr [0x628f80]
0049c445 ret
0049c446 nop
0049c447 nop
0049c448 nop
0049c449 nop
0049c44a nop
0049c44b nop
0049c44c nop
0049c44d nop
0049c44e nop
0049c44f nop
0049c450 mov eax, dword ptr [0x628f84]
0049c455 ret
0049c456 nop
0049c457 nop
0049c458 nop
0049c459 nop
0049c45a nop
0049c45b nop
0049c45c nop
0049c45d nop
0049c45e nop
0049c45f nop
0049c460 mov eax, dword ptr [0x628f88]
0049c465 push eax
0049c466 call 0x59ecd0
0049c46b pop ecx
0049c46c ret
0049c46d nop
0049c46e nop
0049c46f nop
0049c470 mov edx, dword ptr [0x628f80]
0049c476 push ebx
0049c477 xor eax, eax
0049c479 push esi
0049c47a mov esi, dword ptr [esp + 0xc]
0049c47e push edi
0049c47f test edx, edx
0049c481 jle 0x49c49d
0049c483 mov edi, dword ptr [0x628f84]
0049c489 mov ecx, edi
0049c48b movsx ebx, word ptr [ecx]
0049c48e cmp ebx, esi
0049c490 je 0x49c4b1
0049c492 inc eax
0049c493 add ecx, 0x168
0049c499 cmp eax, edx
0049c49b jl 0x49c48b
0049c49d push esi
0049c49e push 0x5d0c58
0049c4a3 call 0x4dba70
0049c4a8 add esp, 8
0049c4ab xor eax, eax
0049c4ad pop edi
0049c4ae pop esi
0049c4af pop ebx
0049c4b0 ret
0049c4b1 lea eax, [eax + eax*4]
0049c4b4 lea eax, [eax + eax*8]
0049c4b7 lea eax, [edi + eax*8]
0049c4ba pop edi
0049c4bb pop esi
0049c4bc pop ebx
0049c4bd ret
0049c4be nop
0049c4bf nop
0049c4c0 sub esp, 8
0049c4c3 mov eax, 0x32c
0049c4c8 mov ecx, dword ptr [esp + 0xc]
0049c4cc add eax, 4
0049c4cf cmp eax, 0x50c
0049c4d4 mov edx, dword ptr [ecx + 0x558]
0049c4da mov dword ptr [edx + eax - 4], 0xffffffff
0049c4e2 jb 0x49c4c8
0049c4e4 mov edx, ecx
0049c4e6 mov ecx, 0xfffff8c0
0049c4eb push ebx
0049c4ec push ebp
0049c4ed sub ecx, edx
0049c4ef push esi
0049c4f0 push edi
0049c4f1 lea ebp, [edx + 0x768]
0049c4f7 mov dword ptr [esp + 0x14], ecx
0049c4fb mov dword ptr [esp + 0x10], 0x14
0049c503 xor ebx, ebx
0049c505 jmp 0x49c50f
0049c507 mov edx, dword ptr [esp + 0x1c]
0049c50b mov ecx, dword ptr [esp + 0x14]
0049c50f mov eax, dword ptr [ebp]
0049c512 mov word ptr [eax + 0x26], bx
0049c516 xor eax, eax
0049c518 mov esi, dword ptr [ebp]
0049c51b inc eax
0049c51c cmp eax, 9
0049c51f mov byte ptr [esi + eax + 0x47], bl
0049c523 jl 0x49c518
0049c525 mov eax, dword ptr [ebp]
0049c528 mov dword ptr [eax + 0x164], ebx
0049c52e mov eax, dword ptr [ebp]
0049c531 mov dword ptr [eax + 0x54], ebx
0049c534 mov esi, dword ptr [ebp]
0049c537 mov eax, 0x3f800000
0049c53c mov dword ptr [esi + 0xc0], eax
0049c542 mov esi, dword ptr [ebp]
0049c545 mov dword ptr [esi + 0xc4], eax
0049c54b mov eax, dword ptr [ebp]
0049c54e mov dword ptr [eax + 0xc8], ebx
0049c554 mov eax, dword ptr [ebp]
0049c557 mov word ptr [eax + 0xea], bx
0049c55e mov eax, dword ptr [ebp]
0049c561 mov word ptr [eax + 0xec], bx
0049c568 mov eax, 0xf0
0049c56d mov esi, dword ptr [ebp]
0049c570 add eax, 4
0049c573 cmp eax, 0x110
0049c578 mov dword ptr [esi + eax - 4], ebx
0049c57c jl 0x49c56d
0049c57e mov eax, 0x110
0049c583 mov esi, dword ptr [ebp]
0049c586 add eax, 4
0049c589 cmp eax, 0x164
0049c58e mov dword ptr [esi + eax - 4], ebx
0049c592 jl 0x49c583
0049c594 mov edx, dword ptr [edx + 0x558]
0049c59a add ecx, ebp
0049c59c mov edx, dword ptr [ecx + edx]
0049c59f cmp edx, ebx
0049c5a1 je 0x49c64c
0049c5a7 mov esi, dword ptr [0x628f80]
0049c5ad xor eax, eax
0049c5af cmp esi, ebx
0049c5b1 jle 0x49c5cf
0049c5b3 mov ecx, dword ptr [0x628f84]
0049c5b9 movsx edi, word ptr [ecx]
0049c5bc cmp edi, edx
0049c5be je 0x49c666
0049c5c4 inc eax
0049c5c5 add ecx, 0x168
0049c5cb cmp eax, esi
0049c5cd jl 0x49c5b9
0049c5cf push edx
0049c5d0 push 0x5d0c58
0049c5d5 call 0x4dba70
0049c5da add esp, 8
0049c5dd xor esi, esi
0049c5df mov edi, dword ptr [ebp]
0049c5e2 mov ecx, 0x5a
0049c5e7 rep movsd dword ptr es:[edi], dword ptr [esi]
0049c5e9 mov edx, dword ptr [ebp]
0049c5ec xor esi, esi
0049c5ee movsx eax, word ptr [edx]
0049c5f1 mov dword ptr [ebp + 0x490], eax
0049c5f7 mov eax, dword ptr [ebp]
0049c5fa cmp word ptr [eax + 0x8c], bx
0049c601 jle 0x49c64c
0049c603 xor ecx, ecx
0049c605 movsx edx, word ptr [ecx + eax + 0x8e]
0049c60d mov ebx, edx
0049c60f movsx edi, word ptr [ecx + eax + 0x92]
0049c617 shl ebx, 4
0049c61a sub ebx, edx
0049c61c inc esi
0049c61d movsx edx, word ptr [ecx + eax + 0x90]
0049c625 add ecx, 6
0049c628 lea eax, [edx + ebx*4]
0049c62b mov edx, dword ptr [esp + 0x1c]
0049c62f mov edx, dword ptr [edx + 0x558]
0049c635 mov dword ptr [edx + eax*4 + 0x32c], edi
0049c63c mov eax, dword ptr [ebp]
0049c63f movsx edx, word ptr [eax + 0x8c]
0049c646 cmp esi, edx
0049c648 jl 0x49c605
0049c64a xor ebx, ebx
0049c64c mov eax, dword ptr [esp + 0x10]
0049c650 add ebp, 4
0049c653 dec eax
0049c654 mov dword ptr [esp + 0x10], eax
0049c658 jne 0x49c507
0049c65e pop edi
0049c65f pop esi
0049c660 pop ebp
0049c661 pop ebx
0049c662 add esp, 8
0049c665 ret
0049c666 mov ecx, dword ptr [0x628f84]
0049c66c lea eax, [eax + eax*4]
0049c66f lea eax, [eax + eax*8]
0049c672 lea esi, [ecx + eax*8]
0049c675 jmp 0x49c5df
0049c67a nop
0049c67b nop
0049c67c nop
0049c67d nop
0049c67e nop
0049c67f nop
0049c680 push ecx
0049c681 mov dword ptr [esp], 0x800000
0049c689 mov eax, dword ptr [esp]
0049c68d mov dword ptr [0x628f94], eax
0049c692 pop ecx
0049c693 ret
0049c694 nop
0049c695 nop
0049c696 nop
0049c697 nop
0049c698 nop
0049c699 nop
0049c69a nop
0049c69b nop
0049c69c nop
0049c69d nop
0049c69e nop
0049c69f nop
0049c6a0 fld dword ptr [0x5b24a8]
0049c6a6 fdiv dword ptr [0x628f94]
0049c6ac fstp dword ptr [0x628f90]
0049c6b2 ret
0049c6b3 nop
0049c6b4 nop
0049c6b5 nop
0049c6b6 nop
0049c6b7 nop
0049c6b8 nop
0049c6b9 nop
0049c6ba nop
0049c6bb nop
0049c6bc nop
0049c6bd nop
0049c6be nop
0049c6bf nop
0049c6c0 mov eax, dword ptr [0x628c70]
0049c6c5 sub esp, 0x64
0049c6c8 test eax, eax
0049c6ca push ebx
0049c6cb push esi
0049c6cc mov esi, dword ptr [esp + 0x70]
0049c6d0 push edi
0049c6d1 mov bl, 1
0049c6d3 je 0x49c79f
0049c6d9 mov ecx, dword ptr [eax + 8]
0049c6dc test ecx, ecx
0049c6de je 0x49c79f
0049c6e4 mov cl, byte ptr [eax + 0xbf]
0049c6ea test cl, cl
0049c6ec jne 0x49c79f
0049c6f2 mov cl, byte ptr [eax + 0xbe]
0049c6f8 test cl, cl
0049c6fa je 0x49c79f
0049c700 mov ecx, dword ptr [eax + 0xdc]
0049c706 test ecx, ecx
0049c708 jl 0x49c79f
0049c70e mov eax, dword ptr [eax + 0x10]
0049c711 test eax, eax
0049c713 je 0x49c720
0049c715 mov eax, dword ptr [eax]
0049c717 push eax
0049c718 call 0x5322b0
0049c71d add esp, 4
0049c720 mov ecx, dword ptr [esi + 0x520]
0049c726 push ecx
0049c727 call 0x48d720
0049c72c add esp, 4
0049c72f test eax, eax
0049c731 je 0x49c77c
0049c733 push 1
0049c735 mov ecx, eax
0049c737 call 0x4903f0
0049c73c mov edi, eax
0049c73e test edi, edi
0049c740 je 0x49c77c
0049c742 mov edx, dword ptr [esi + 0x760]
0049c748 push 0x1c4
0049c74d push 0
0049c74f push edx
0049c750 call 0x53c290
0049c755 mov eax, dword ptr [edi + 8]
0049c758 mov ecx, dword ptr [edi + 0xc]
0049c75b add esp, 0xc
0049c75e cmp ecx, eax
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
0049ca30 sub esp, 0x64
0049ca33 mov ecx, dword ptr [0x65b2b0]
0049ca39 lea edx, [esp]
0049ca3d push ebx
0049ca3e push ebp
0049ca3f push esi
0049ca40 push edi
0049ca41 mov edi, dword ptr [esp + 0x78]
0049ca45 mov eax, dword ptr [edi + 0x558]
0049ca4b add eax, 0x2a8
0049ca50 push eax
0049ca51 push ecx
0049ca52 push 0x5d0cdc
0049ca57 push edx
0049ca58 call 0x5a0fbf
0049ca5d lea eax, [esp + 0x20]
0049ca61 push 0
0049ca63 push eax
0049ca64 call 0x59d9b0
0049ca69 mov ebx, eax
0049ca6b add esp, 0x18
0049ca6e test ebx, ebx
0049ca70 jne 0x49ca98
0049ca72 mov ecx, dword ptr [0x65b2b0]
0049ca78 lea edx, [esp + 0x10]
0049ca7c push ecx
0049ca7d push 0x5d0ccc
0049ca82 push edx
0049ca83 call 0x5a0fbf
0049ca88 lea eax, [esp + 0x1c]
0049ca8c push ebx
0049ca8d push eax
0049ca8e call 0x59d8e0
0049ca93 add esp, 0x14
0049ca96 mov ebx, eax
0049ca98 mov dword ptr [esp + 0x78], 0x42c80000
0049caa0 lea ecx, [ebx + 0x11c]
0049caa6 mov edx, 0x28
0049caab fld dword ptr [esp + 0x78]
0049caaf fcomp dword ptr [ecx]
0049cab1 fnstsw ax
0049cab3 test ah, 0x41
0049cab6 jne 0x49cabe
0049cab8 mov eax, dword ptr [ecx]
0049caba mov dword ptr [esp + 0x78], eax
0049cabe sub ecx, 4
0049cac1 dec edx
0049cac2 jne 0x49caab
0049cac4 lea esi, [ebx + 0x80]
0049caca mov ebp, 0x28
0049cacf fld dword ptr [esi]
0049cad1 fsub dword ptr [esp + 0x78]
0049cad5 fst dword ptr [esi]
0049cad7 fmul dword ptr [edi + 0x10d8]
0049cadd fadd dword ptr [esp + 0x78]
0049cae1 fstp dword ptr [esi]
0049cae3 mov ecx, dword ptr [edi + 0x558]
0049cae9 add ecx, 0x2a8
0049caef push ecx
0049caf0 call 0x4a2dc0
0049caf5 fmul dword ptr [esi]
0049caf7 add esp, 4
0049cafa add esi, 4
0049cafd dec ebp
0049cafe fstp dword ptr [esi - 4]
0049cb01 jne 0x49cacf
0049cb03 mov edx, dword ptr [edi + 0x558]
0049cb09 mov esi, dword ptr [edi + 0x760]
0049cb0f add edx, 0x2a8
0049cb15 push edx
0049cb16 call 0x4a2950
0049cb1b fmul dword ptr [esi + 0x140]
0049cb21 push 0x130
0049cb26 push ebx
0049cb27 fstp dword ptr [esi + 0x140]
0049cb2d mov eax, dword ptr [edi + 0x764]
0049cb33 push eax
0049cb34 call 0x5323e0
0049cb39 push ebx
0049cb3a call 0x531f90
0049cb3f add esp, 0x14
0049cb42 pop edi
0049cb43 pop esi
0049cb44 pop ebp
0049cb45 pop ebx
0049cb46 add esp, 0x64
0049cb49 ret
0049cb4a nop
0049cb4b nop
0049cb4c nop
0049cb4d nop
0049cb4e nop
0049cb4f nop
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
0049d0fc fmul dword ptr [0x5b2468]
0049d102 fdivr dword ptr [eax + 0x12c]
0049d108 fstp dword ptr [eax + 0x12c]
0049d10e jmp 0x49d200
0049d113 cmp cx, 6
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
0049d16a jne 0x49d200
0049d170 mov ecx, dword ptr [esi + 0x760]
0049d176 fld dword ptr [ecx + 0xf4]
0049d17c fmul dword ptr [0x5b2600]
0049d182 fld st(0)
0049d184 fadd dword ptr [0x5b24a8]
0049d18a fld st(1)
0049d18c fadd dword ptr [eax + 0xc0]
0049d192 fdiv st(1)
0049d194 fstp dword ptr [esp + 0x14]
0049d198 fxch st(1)
0049d19a fadd dword ptr [eax + 0xc4]
0049d1a0 fdiv st(1)
0049d1a2 fadd dword ptr [esp + 0x14]
0049d1a6 fxch st(1)
0049d1a8 fstp st(0)
0049d1aa fld st(0)
0049d1ac fadd dword ptr [0x5b24a8]
0049d1b2 fmul dword ptr [ecx + 0xf4]
0049d1b8 fmul dword ptr [0x5b2680]
0049d1be fstp dword ptr [ecx + 0xf4]
0049d1c4 fld dword ptr [esp + 0x14]
0049d1c8 fadd st(0), st(0)
0049d1ca mov eax, dword ptr [esi + 0x760]
0049d1d0 fdiv st(1)
0049d1d2 fadd dword ptr [0x5b24a8]
0049d1d8 fmul dword ptr [0x5b23f0]
0049d1de fmul dword ptr [eax + 0xf0]
0049d1e4 fstp dword ptr [eax + 0xf0]
0049d1ea mov eax, dword ptr [edi]
0049d1ec mov ecx, dword ptr [esi + 0x760]
0049d1f2 fstp st(0)
0049d1f4 mov edx, dword ptr [eax + 0xc8]
0049d1fa mov dword ptr [ecx + 0x1c0], edx
0049d200 mov eax, dword ptr [esp + 0x18]
0049d204 add edi, 4
0049d207 dec eax
0049d208 mov dword ptr [esp + 0x18], eax
0049d20c jne 0x49cd1b
0049d212 mov ecx, dword ptr [esi + 0x760]
0049d218 mov edi, 0x15
0049d21d lea edx, [ecx + 0x9c]
0049d223 fld dword ptr [edx]
0049d225 fld dword ptr [esp + 0x20]
0049d229 fcomp st(1)
0049d22b fnstsw ax
0049d22d test ah, 0x41
0049d230 je 0x49d238
0049d232 fstp dword ptr [esp + 0x20]
0049d236 jmp 0x49d23a
0049d238 fstp st(0)
0049d23a add edx, 4
0049d23d dec edi
0049d23e jne 0x49d223
0049d240 fld dword ptr [esp + 0x20]
0049d244 fdiv dword ptr [esp + 0x10]
0049d248 fadd dword ptr [0x5b2600]
0049d24e fmul dword ptr [0x5b2468]
0049d254 fmul dword ptr [ecx + 0x90]
0049d25a fstp dword ptr [ecx + 0x90]
0049d260 mov eax, dword ptr [esi + 0x760]
0049d266 fld dword ptr [eax + 0xf4]
0049d26c fdiv dword ptr [esi + 0x10d8]
0049d272 fst dword ptr [esi + 0x10d8]
0049d278 fadd dword ptr [0x5b2580]
0049d27e fmul dword ptr [0x5b2680]
0049d284 fdivr dword ptr [eax + 0x140]
0049d28a fstp dword ptr [eax + 0x140]
0049d290 mov eax, dword ptr [esi + 0x558]
0049d296 fild dword ptr [eax + 0x114]
0049d29c fmul dword ptr [0x5b253c]
0049d2a2 fmul dword ptr [0x5b3714]
0049d2a8 fadd dword ptr [0x5b24a8]
0049d2ae fmul dword ptr [0x5b23f0]
0049d2b4 fild dword ptr [eax + 0x118]
0049d2ba mov eax, dword ptr [esi + 0x760]
0049d2c0 fmul dword ptr [0x5b253c]
0049d2c6 fmul dword ptr [0x5b3714]
0049d2cc fadd dword ptr [0x5b24a8]
0049d2d2 fmul dword ptr [0x5b23f0]
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
0049d328 mov eax, dword ptr [esi + 0x760]
0049d32e fild dword ptr [ecx + 0xf0]
0049d334 fmul dword ptr [0x5b253c]
0049d33a fadd dword ptr [eax + 0x80]
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
0049dcfb mov byte ptr [ecx + 0xd82], al
0049dd01 mov dl, byte ptr [edx + 0x54]
0049dd04 mov byte ptr [ecx + 0xd84], dl
0049dd0a pop edi
0049dd0b pop esi
0049dd0c pop ebx
0049dd0d add esp, 0x14
0049dd10 ret
0049dd11 nop
0049dd12 nop
0049dd13 nop
0049dd14 nop
0049dd15 nop
0049dd16 nop
0049dd17 nop
0049dd18 nop
0049dd19 nop
0049dd1a nop
0049dd1b nop
0049dd1c nop
0049dd1d nop
0049dd1e nop
0049dd1f nop
0049dd20 push ecx
0049dd21 mov ecx, dword ptr [esp + 8]
0049dd25 push ebp
0049dd26 xor ebp, ebp
0049dd28 push esi
0049dd29 mov eax, dword ptr [ecx + 0xdb0]
0049dd2f cmp eax, ebp
0049dd31 je 0x49dd3a
0049dd33 inc eax
0049dd34 mov dword ptr [ecx + 0xdb0], eax
0049dd3a mov al, byte ptr [ecx + 0x52c]
0049dd40 push edi
0049dd41 test al, 4
0049dd43 je 0x49dd4e
0049dd45 cmp dword ptr [ecx + 0xb50], 2
0049dd4c jge 0x49dd56
0049dd4e cmp dword ptr [ecx + 0xdb0], ebp
0049dd54 jne 0x49dd7d
0049dd56 mov byte ptr [ecx + 0xd7f], 0
0049dd5d mov byte ptr [ecx + 0xd83], 0
0049dd64 mov byte ptr [ecx + 0xd84], 0
0049dd6b mov dword ptr [ecx + 0xd98], ebp
0049dd71 mov byte ptr [ecx + 0xd80], 0xff
0049dd78 jmp 0x49e006
0049dd7d mov al, byte ptr [ecx + 0xd84]
0049dd83 mov dl, byte ptr [ecx + 0xd7d]
0049dd89 push ebx
0049dd8a mov bl, byte ptr [ecx + 0xd7c]
0049dd90 test al, al
0049dd92 mov byte ptr [ecx + 0xd7f], bl
0049dd98 mov byte ptr [ecx + 0xd80], dl
0049dd9e jle 0x49dda8
0049dda0 dec al
0049dda2 mov byte ptr [ecx + 0xd84], al
0049dda8 mov esi, dword ptr [0x606ac4]
0049ddae cmp esi, 0x1c0
0049ddb4 jle 0x49df81
0049ddba mov eax, dword ptr [ecx + 0x520]
0049ddc0 lea edi, [eax + eax*4]
0049ddc3 lea eax, [eax + edi*2]
0049ddc6 shl eax, 7
0049ddc9 lea edi, [eax + 0x658098]
0049ddcf mov eax, dword ptr [eax + 0x658098]
0049ddd5 cmp eax, 1
0049ddd8 jne 0x49dec8
0049ddde cmp esi, 0x1c4
0049dde4 jge 0x49ddf2
0049dde6 mov byte ptr [ecx + 0xd7e], 2
0049dded jmp 0x49dec8
0049ddf2 mov al, byte ptr [ecx + 0xd82]
0049ddf8 cmp byte ptr [ecx + 0xd7e], al
0049ddfe mov byte ptr [esp + 0x18], al
0049de02 jne 0x49dec2
0049de08 cmp dword ptr [ecx + 0xb50], ebp
0049de0e jne 0x49dec2
0049de14 cmp dword ptr [ecx + 0x544], ebp
0049de1a jne 0x49dec8
0049de20 cmp dword ptr [ecx + 0x540], ebp
0049de26 jne 0x49dec8
0049de2c fld dword ptr [ecx + 0x35c]
0049de32 fcomp dword ptr [0x5b23f8]
0049de38 fld dword ptr [ecx + 0x35c]
0049de3e fnstsw ax
0049de40 test ah, 1
0049de43 je 0x49de47
0049de45 fchs
0049de47 fcomp dword ptr [0x5b23f4]
0049de4d fnstsw ax
0049de4f test ah, 1
0049de52 je 0x49de7e
0049de54 cmp dl, 0x80
0049de57 jbe 0x49de7e
0049de59 test bl, bl
0049de5b jne 0x49de7e
0049de5d cmp byte ptr [esp + 0x18], 1
0049de62 jle 0x49de7e
0049de64 cmp dword ptr [ecx + 0xd98], ebp
0049de6a jne 0x49de7e
0049de6c mov byte ptr [ecx + 0xd7e], bl
0049de72 mov dword ptr [ecx + 0xd98], 1
0049de7c jmp 0x49dec8
0049de7e fld dword ptr [ecx + 0x35c]
0049de84 fcomp dword ptr [0x5b23f8]
0049de8a fld dword ptr [ecx + 0x35c]
0049de90 fnstsw ax
0049de92 test ah, 1
0049de95 je 0x49de99
0049de97 fchs
0049de99 fcomp dword ptr [0x5b23f4]
0049de9f fnstsw ax
0049dea1 test ah, 1
0049dea4 je 0x49dec8
0049dea6 cmp bl, 0x80
0049dea9 jbe 0x49dec8
0049deab mov al, byte ptr [esp + 0x18]
0049deaf test al, al
0049deb1 jne 0x49dec8
0049deb3 cmp dword ptr [ecx + 0xd98], ebp
0049deb9 je 0x49dec8
0049debb mov byte ptr [ecx + 0xd7e], 2
0049dec2 mov dword ptr [ecx + 0xd98], ebp
0049dec8 mov al, byte ptr [ecx + 0xd7e]
0049dece mov dl, byte ptr [ecx + 0xd82]
0049ded4 cmp al, dl
0049ded6 je 0x49df81
0049dedc cmp dword ptr [edi], 1
0049dedf je 0x49defa
0049dee1 cmp dword ptr [ecx + 0xda8], ebp
0049dee7 jne 0x49defa
0049dee9 cmp dl, al
0049deeb jle 0x49defe
0049deed cmp al, 1
0049deef jle 0x49defe
0049def1 mov byte ptr [ecx + 0xd83], 1
0049def8 jmp 0x49df05
0049defa cmp al, 2
0049defc jge 0x49df22
0049defe mov byte ptr [ecx + 0xd83], 0
0049df05 mov byte ptr [ecx + 0xd81], dl
0049df0b mov edx, dword ptr [ecx + 0x760]
0049df11 mov byte ptr [ecx + 0xd82], al
0049df17 mov al, byte ptr [edx + 0x54]
0049df1a mov byte ptr [ecx + 0xd84], al
0049df20 jmp 0x49df81
0049df22 jne 0x49df81
0049df24 cmp dl, 2
0049df27 jge 0x49df81
0049df29 mov esi, dword ptr [ecx + 0x760]
0049df2f mov byte ptr [ecx + 0xd81], dl
0049df35 mov ebx, 2
0049df3a mov edi, dword ptr [esi + 0x50]
0049df3d mov edx, ebx
0049df3f cmp edi, ebx
0049df41 jle 0x49df6b
0049df43 lea ebp, [esi + 0x178]
0049df49 fld dword ptr [esi + 0x94]
0049df4f fmul dword ptr [ebp]
0049df52 fcomp dword ptr [ecx + 0xd60]
0049df58 fnstsw ax
0049df5a test ah, 1
0049df5d je 0x49df61
0049df5f mov ebx, edx
0049df61 inc edx
0049df62 add ebp, 4
0049df65 cmp edx, edi
0049df67 jl 0x49df49
0049df69 xor ebp, ebp
0049df6b mov byte ptr [ecx + 0xd83], 0
0049df72 mov byte ptr [ecx + 0xd82], bl
0049df78 mov dl, byte ptr [esi + 0x54]
0049df7b mov byte ptr [ecx + 0xd84], dl
0049df81 mov eax, dword ptr [ecx + 0xda8]
0049df87 pop ebx
0049df88 cmp eax, ebp
0049df8a je 0x49dfa7
0049df8c mov eax, dword ptr [ecx + 0xd90]
0049df92 mov edi, dword ptr [ecx + 0xd94]
0049df98 add eax, edi
0049df9a cdq
0049df9b sub eax, edx
0049df9d sar eax, 1
0049df9f mov dword ptr [ecx + 0xd94], eax
0049dfa5 jmp 0x49e006
0049dfa7 mov eax, dword ptr [ecx + 0x558]
0049dfad cmp dword ptr [eax + 0x14], ebp
0049dfb0 jne 0x49dfc0
0049dfb2 mov eax, dword ptr [ecx + 0xd90]
0049dfb8 mov dword ptr [ecx + 0xd94], eax
0049dfbe jmp 0x49e006
0049dfc0 mov edx, dword ptr [0x6573f8]
0049dfc6 mov esi, 0xc
0049dfcb cmp edx, ebp
0049dfcd jne 0x49dfd7
0049dfcf cmp dword ptr [eax + 0x518], ebp
0049dfd5 je 0x49dfdc
0049dfd7 mov esi, 0x12
0049dfdc mov edx, dword ptr [ecx + 0xd94]
0049dfe2 mov eax, dword ptr [ecx + 0xd90]
0049dfe8 sub eax, edx
0049dfea js 0x49dff6
0049dfec cmp esi, eax
0049dfee jg 0x49dff2
0049dff0 mov eax, esi
0049dff2 add edx, eax
0049dff4 jmp 0x49e000
0049dff6 neg eax
0049dff8 cmp esi, eax
0049dffa jg 0x49dffe
0049dffc mov eax, esi
0049dffe sub edx, eax
0049e000 mov dword ptr [ecx + 0xd94], edx
0049e006 mov eax, dword ptr [ecx + 0xdb0]
0049e00c pop edi
0049e00d cmp eax, 0x40
0049e010 jge 0x49e022
0049e012 mov byte ptr [ecx + 0xd7f], 0
0049e019 mov byte ptr [ecx + 0xd80], 0xff
0049e020 jmp 0x49e074
0049e022 cmp dword ptr [0x606ac4], 0x1c0
0049e02c jge 0x49e037
0049e02e mov byte ptr [ecx + 0xd80], 0xff
0049e035 jmp 0x49e074
0049e037 cmp dword ptr [ecx + 0x540], ebp
0049e03d jne 0x49e047
0049e03f cmp dword ptr [ecx + 0x544], ebp
0049e045 je 0x49e074
0049e047 cmp dword ptr [ecx + 0xd98], ebp
0049e04d je 0x49e05f
0049e04f mov byte ptr [ecx + 0xd7f], 0x80
0049e056 mov byte ptr [ecx + 0xd80], 0
0049e05d jmp 0x49e06d
0049e05f mov byte ptr [ecx + 0xd7f], 0
0049e066 mov byte ptr [ecx + 0xd80], 0x80
0049e06d mov byte ptr [ecx + 0xd83], 0
0049e074 cmp dword ptr [ecx + 0xd2c], 2
0049e07b jne 0x49e084
0049e07d mov byte ptr [ecx + 0xd7f], 0
0049e084 cmp dword ptr [0x5e67b0], ebp
0049e08a je 0x49e0ca
0049e08c cmp dword ptr [ecx + 0xda8], ebp
0049e092 je 0x49e0ca
0049e094 fild dword ptr [ecx + 0xeb0]
0049e09a fmul dword ptr [ecx + 0xed0]
0049e0a0 fcomp dword ptr [0x5b23f8]
0049e0a6 fnstsw ax
0049e0a8 test ah, 0x41
0049e0ab jne 0x49e0b9
0049e0ad mov dword ptr [ecx + 0xd94], 0xffffff84
0049e0b7 jmp 0x49e0c3
0049e0b9 mov dword ptr [ecx + 0xd94], 0x7c
0049e0c3 mov byte ptr [ecx + 0xd85], 1
0049e0ca mov eax, dword ptr [0x657404]
0049e0cf mov dword ptr [esp + 0x10], 0x437c0000
0049e0d7 cmp eax, ebp
0049e0d9 jle 0x49e0e3
0049e0db mov dword ptr [esp + 0x10], 0x43700000
0049e0e3 xor edx, edx
0049e0e5 mov dl, byte ptr [ecx + 0xd7f]
0049e0eb mov dword ptr [esp + 8], edx
0049e0ef fild dword ptr [esp + 8]
0049e0f3 fdiv dword ptr [esp + 0x10]
0049e0f7 fld dword ptr [0x5b24a8]
0049e0fd fcomp st(1)
0049e0ff fnstsw ax
0049e101 test ah, 0x41
0049e104 jne 0x49e10e
0049e106 fstp dword ptr [0x628fb0]
0049e10c jmp 0x49e11a
0049e10e fstp st(0)
0049e110 mov dword ptr [0x628fb0], 0x3f800000
0049e11a xor eax, eax
0049e11c mov al, byte ptr [ecx + 0xd80]
0049e122 mov dword ptr [esp + 8], eax
0049e126 fild dword ptr [esp + 8]
0049e12a fdiv dword ptr [esp + 0x10]
0049e12e fld dword ptr [0x5b24a8]
0049e134 fcomp st(1)
0049e136 fnstsw ax
0049e138 test ah, 0x41
0049e13b jne 0x49e145
0049e13d fstp dword ptr [0x628fac]
0049e143 jmp 0x49e151
0049e145 fstp st(0)
0049e147 mov dword ptr [0x628fac], 0x3f800000
0049e151 fild dword ptr [ecx + 0xd94]
0049e157 fld dword ptr [esp + 0x10]
0049e15b fmul dword ptr [0x5b23f0]
0049e161 fdivp st(1)
0049e163 fcom dword ptr [0x5b23f8]
0049e169 fnstsw ax
0049e16b test ah, 1
0049e16e je 0x49e172
0049e170 fchs
0049e172 fstp dword ptr [0x628fb4]
0049e178 mov eax, dword ptr [ecx + 0x520]
0049e17e lea edx, [eax + eax*4]
0049e181 lea edx, [eax + edx*2]
0049e184 mov eax, 1
0049e189 shl edx, 7
0049e18c mov esi, dword ptr [edx + 0x658098]
0049e192 cmp esi, eax
0049e194 pop esi
0049e195 pop ebp
0049e196 jne 0x49e21c
0049e19c mov dl, byte ptr [ecx + 0xd82]
0049e1a2 test dl, dl
0049e1a4 jne 0x49e21c
0049e1a6 cmp dword ptr [ecx + 0xd98], eax
0049e1ac jne 0x49e21c
0049e1ae xor eax, eax
0049e1b0 mov al, byte ptr [ecx + 0xd80]
0049e1b6 mov dword ptr [esp], eax
0049e1ba fild dword ptr [esp]
0049e1be fdiv dword ptr [esp + 8]
0049e1c2 fld dword ptr [0x5b24a8]
0049e1c8 fcomp st(1)
0049e1ca fnstsw ax
0049e1cc test ah, 0x41
0049e1cf jne 0x49e1d9
0049e1d1 fstp dword ptr [0x628fb0]
0049e1d7 jmp 0x49e1e5
0049e1d9 fstp st(0)
0049e1db mov dword ptr [0x628fb0], 0x3f800000
0049e1e5 xor edx, edx
0049e1e7 mov dl, byte ptr [ecx + 0xd7f]
0049e1ed mov dword ptr [esp], edx
0049e1f1 fild dword ptr [esp]
0049e1f5 fdiv dword ptr [esp + 8]
0049e1f9 fld dword ptr [0x5b24a8]
0049e1ff fcomp st(1)
0049e201 fnstsw ax
0049e203 test ah, 0x41
0049e206 jne 0x49e210
0049e208 fstp dword ptr [0x628fac]
0049e20e pop ecx
0049e20f ret
0049e210 fstp st(0)
0049e212 mov dword ptr [0x628fac], 0x3f800000
0049e21c pop ecx
0049e21d ret
0049e21e nop
0049e21f nop
0049e220 push ebx
0049e221 push ebp
0049e222 push esi
0049e223 push edi
0049e224 mov edi, dword ptr [esp + 0x14]
0049e228 mov eax, dword ptr [edi + 0x558]
0049e22e cmp dword ptr [eax + 0xc], 1
0049e232 jne 0x49e244
0049e234 mov al, 2
0049e236 mov byte ptr [edi + 0xd7e], al
0049e23c mov byte ptr [edi + 0xd82], al
0049e242 jmp 0x49e252
0049e244 mov byte ptr [edi + 0xd7e], 1
0049e24b mov byte ptr [edi + 0xd82], 1
0049e252 xor ebx, ebx
0049e254 lea esi, [edi + 0x7ec]
0049e25a mov dword ptr [edi + 0xd98], ebx
0049e260 mov byte ptr [edi + 0xd89], bl
0049e266 mov byte ptr [edi + 0xd88], bl
0049e26c mov byte ptr [edi + 0xd8b], bl
0049e272 mov byte ptr [edi + 0xd8c], bl
0049e278 mov byte ptr [edi + 0xd7c], bl
0049e27e mov byte ptr [edi + 0xd7d], bl
0049e284 mov dword ptr [edi + 0xd90], ebx
0049e28a mov byte ptr [edi + 0xd83], bl
0049e290 mov byte ptr [edi + 0xd84], bl
0049e296 mov byte ptr [edi + 0xd7f], bl
0049e29c mov byte ptr [edi + 0xd80], bl
0049e2a2 mov dword ptr [edi + 0xd94], ebx
0049e2a8 mov byte ptr [edi + 0xd81], 1
0049e2af mov byte ptr [edi + 0xd85], bl
0049e2b5 mov ebp, 4
0049e2ba lea eax, [edi + 8]
0049e2bd lea ecx, [esi - 0x30]
0049e2c0 push eax
0049e2c1 call 0x473190
0049e2c6 mov dword ptr [esi], ebx
0049e2c8 mov dword ptr [esi + 4], ebx
0049e2cb mov dword ptr [esi + 8], ebx
0049e2ce mov dword ptr [esi + 0xc], ebx
0049e2d1 mov dword ptr [esi + 0x10], ebx
0049e2d4 mov dword ptr [esi + 0x14], ebx
0049e2d7 mov dword ptr [esi + 0x18], ebx
0049e2da mov dword ptr [esi + 0x1c], 0x3f800000
0049e2e1 mov dword ptr [esi + 0x20], ebx
0049e2e4 mov dword ptr [esi + 0x24], ebx
0049e2e7 mov dword ptr [esi + 0x28], ebx
0049e2ea mov dword ptr [esi + 0x2c], ebx
0049e2ed mov dword ptr [esi + 0x3c], ebx
0049e2f0 mov dword ptr [esi + 0x30], ebx
0049e2f3 mov dword ptr [esi + 0x38], ebx
0049e2f6 mov dword ptr [esi + 0x50], ebx
0049e2f9 mov dword ptr [esi + 0x54], ebx
0049e2fc mov dword ptr [esi + 0x34], ebx
0049e2ff mov dword ptr [esi + 0x40], ebx
0049e302 mov dword ptr [esi + 0x44], ebx
0049e305 mov dword ptr [esi + 0x48], ebx
0049e308 mov dword ptr [esi + 0x58], 1
0049e30f mov dword ptr [esi + 0x84], ebx
0049e315 add esi, 0xc4
0049e31b dec ebp
0049e31c jne 0x49e2ba
0049e31e mov ecx, dword ptr [edi + 0xdb0]
0049e324 mov dword ptr [edi + 0x86c], ebx
0049e32a mov dword ptr [edi + 0x930], ebx
0049e330 mov dword ptr [edi + 0x9f4], ebx
0049e336 neg ecx
0049e338 mov eax, 1
0049e33d mov dword ptr [edi + 0xab8], ebx
0049e343 sbb ecx, ecx
0049e345 mov dword ptr [edi + 0x878], eax
0049e34b mov dword ptr [edi + 0x93c], eax
0049e351 and ecx, 0x3b
0049e354 mov dword ptr [edi + 0xa00], ebx
0049e35a mov dword ptr [edi + 0xac4], ebx
0049e360 inc ecx
0049e361 mov dword ptr [edi + 0xacc], ebx
0049e367 mov dword ptr [edi + 0xac8], ebx
0049e36d mov dword ptr [edi + 0xe08], ebx
0049e373 mov dword ptr [edi + 0xe04], ebx
0049e379 mov dword ptr [edi + 0xd40], ebx
0049e37f mov dword ptr [edi + 0xd44], ebx
0049e385 mov dword ptr [edi + 0xd48], ebx
0049e38b mov dword ptr [edi + 0xd34], ebx
0049e391 mov dword ptr [edi + 0xd38], ebx
0049e397 mov dword ptr [edi + 0xd3c], ebx
0049e39d mov dword ptr [edi + 0xd4c], ebx
0049e3a3 mov dword ptr [edi + 0xd50], ebx
0049e3a9 mov dword ptr [edi + 0xd54], ebx
0049e3af mov dword ptr [edi + 0x103c], ebx
0049e3b5 mov dword ptr [edi + 0x1040], ebx
0049e3bb mov dword ptr [edi + 0x1044], ebx
0049e3c1 mov dword ptr [edi + 0xd58], ebx
0049e3c7 mov dword ptr [edi + 0xd5c], ebx
0049e3cd mov dword ptr [edi + 0xd60], ebx
0049e3d3 mov dword ptr [edi + 0xd64], ebx
0049e3d9 mov dword ptr [edi + 0xd68], ebx
0049e3df mov dword ptr [edi + 0xd6c], ebx
0049e3e5 mov dword ptr [edi + 0xdb0], ecx
0049e3eb mov dword ptr [edi + 0xdb4], ebx
0049e3f1 mov dword ptr [edi + 0xdbc], ebx
0049e3f7 mov dword ptr [edi + 0xdc0], ebx
0049e3fd mov dword ptr [edi + 0x54c], ebx
0049e403 mov dword ptr [edi + 0xdb8], ebx
0049e409 mov dword ptr [edi + 0xd2c], ebx
0049e40f mov dword ptr [edi + 0x540], ebx
0049e415 mov dword ptr [edi + 0xdc4], ebx
0049e41b mov dword ptr [edi + 0xdc8], ebx
0049e421 mov dword ptr [edi + 0xe94], ebx
0049e427 mov dword ptr [edi + 0xc], 0xffffffff
0049e42e pop edi
0049e42f pop esi
0049e430 pop ebp
0049e431 pop ebx
0049e432 ret
0049e433 nop
0049e434 nop
0049e435 nop
0049e436 nop
0049e437 nop
0049e438 nop
0049e439 nop
0049e43a nop
0049e43b nop
0049e43c nop
0049e43d nop
0049e43e nop
0049e43f nop
0049e440 sub esp, 0x18
0049e443 push ebp
0049e444 push esi
0049e445 mov esi, dword ptr [esp + 0x24]
0049e449 push edi
0049e44a xor edi, edi
0049e44c push esi
0049e44d mov eax, dword ptr [esi + 0x760]
0049e453 mov dword ptr [esp + 0x20], edi
0049e457 mov dword ptr [esp + 0x18], edi
0049e45b fld dword ptr [eax + 0x94]
0049e461 mov eax, dword ptr [0x5d102c]
0049e466 imul eax, dword ptr [0x5d1028]
0049e46d fmul dword ptr [0x5b272c]
0049e473 fstp dword ptr [esp + 0x24]
0049e477 mov dword ptr [0x655a0c], eax
0049e47c mov ecx, eax
0049e47e shr eax, 8
0049e481 and eax, 0xffff
0049e486 and ecx, 0xffff
0049e48c mov dword ptr [esp + 0x2c], eax
0049e490 mov dword ptr [0x5d1028], ecx
0049e496 fild dword ptr [esp + 0x2c]
0049e49a fmul dword ptr [0x5b253c]
0049e4a0 fstp dword ptr [esp + 0x2c]
0049e4a4 call 0x4938a0
0049e4a9 fmul dword ptr [0x5b4a64]
0049e4af fcomp dword ptr [esp + 0x2c]
0049e4b3 add esp, 4
0049e4b6 fnstsw ax
0049e4b8 test ah, 0x41
0049e4bb jne 0x49e4c6
0049e4bd mov edi, 1
0049e4c2 mov dword ptr [esp + 0x1c], edi
0049e4c6 fld dword ptr [esi + 0xd60]
0049e4cc mov ebp, dword ptr [esi + 0x760]
0049e4d2 push esi
0049e4d3 fld st(0)
0049e4d5 fmul dword ptr [ebp + 0x1b0]
0049e4db fmul st(1)
0049e4dd fmul st(1)
0049e4df fstp dword ptr [esp + 0x1c]
0049e4e3 fstp st(0)
0049e4e5 call 0x49d9b0
0049e4ea fmul dword ptr [esp + 0x1c]
0049e4ee mov cl, byte ptr [esi + 0xd82]
0049e4f4 add esp, 4
0049e4f7 cmp cl, 1
0049e4fa fstp dword ptr [esp + 0x18]
0049e4fe je 0x49e542
0049e500 mov eax, dword ptr [0x628f98]
0049e505 test eax, eax
0049e507 je 0x49e542
0049e509 fld dword ptr [ebp + 0x94]
0049e50f fadd dword ptr [0x5b242c]
0049e515 fld st(0)
0049e517 fmul dword ptr [0x628fb0]
0049e51d fst dword ptr [esp + 0x28]
0049e521 fld st(1)
0049e523 fstp dword ptr [esp + 0x10]
0049e527 fcomp st(1)
0049e529 fnstsw ax
0049e52b test ah, 1
0049e52e fstp st(0)
0049e530 je 0x49e53c
0049e532 mov edx, dword ptr [esp + 0x28]
0049e536 mov dword ptr [esp + 0x28], edx
0049e53a jmp 0x49e57d
0049e53c mov eax, dword ptr [esp + 0x10]
0049e540 jmp 0x49e579
0049e542 fld dword ptr [ebp + 0x94]
0049e548 fadd dword ptr [0x5b4a60]
0049e54e fld st(0)
0049e550 fmul dword ptr [0x628fb0]
0049e556 fst dword ptr [esp + 0x28]
0049e55a fld st(1)
0049e55c fstp dword ptr [esp + 0x10]
0049e560 fcomp st(1)
0049e562 fnstsw ax
0049e564 test ah, 1
0049e567 fstp st(0)
0049e569 je 0x49e575
0049e56b mov edx, dword ptr [esp + 0x28]
0049e56f mov dword ptr [esp + 0x28], edx
0049e573 jmp 0x49e57d
0049e575 mov eax, dword ptr [esp + 0x10]
0049e579 mov dword ptr [esp + 0x28], eax
0049e57d fld dword ptr [esi + 0xdb4]
0049e583 fcomp dword ptr [ebp + 0x94]
0049e589 fnstsw ax
0049e58b test ah, 1
0049e58e jne 0x49e69b
0049e594 fld dword ptr [ebp + 0x94]
0049e59a fadd dword ptr [0x5b4a60]
0049e5a0 fcomp dword ptr [esi + 0xdb4]
0049e5a6 fnstsw ax
0049e5a8 test ah, 0x41
0049e5ab jne 0x49e69b
0049e5b1 fld dword ptr [ebp + 0x94]
0049e5b7 fadd dword ptr [0x5b251c]
0049e5bd cmp cl, 1
0049e5c0 fstp dword ptr [esi + 0xdb4]
0049e5c6 jle 0x49e616
0049e5c8 mov eax, dword ptr [0x628f98]
0049e5cd test eax, eax
0049e5cf je 0x49e616
0049e5d1 mov eax, dword ptr [0x5d102c]
0049e5d6 imul eax, dword ptr [0x5d1028]
0049e5dd mov dword ptr [0x655a0c], eax
0049e5e2 mov ecx, eax
0049e5e4 shr eax, 8
0049e5e7 and eax, 0xffff
0049e5ec and ecx, 0xffff
0049e5f2 shl eax, 1
0049e5f4 mov dword ptr [0x5d1028], ecx
0049e5fa mov edx, eax
0049e5fc movsx eax, byte ptr [esi + 0xd82]
0049e603 sar edx, 0x10
0049e606 lea eax, [eax + eax*2]
0049e609 add edx, eax
0049e60b mov dword ptr [esi + 0x548], edx
0049e611 jmp 0x49e69b
0049e616 test byte ptr [esi + 0x52c], 4
0049e61d jne 0x49e666
0049e61f cmp dword ptr [0x606ac4], 0x1a0
0049e629 jge 0x49e666
0049e62b mov eax, dword ptr [0x5d102c]
0049e630 imul eax, dword ptr [0x5d1028]
0049e637 mov dword ptr [0x655a0c], eax
0049e63c mov ecx, eax
0049e63e shr eax, 8
0049e641 and eax, 0xffff
0049e646 and ecx, 0xffff
0049e64c mov dword ptr [0x5d1028], ecx
0049e652 lea edx, [eax + eax*4]
0049e655 shl edx, 2
0049e658 sar edx, 0x10
0049e65b add edx, 0xa
0049e65e mov dword ptr [esi + 0x548], edx
0049e664 jmp 0x49e69b
0049e666 mov eax, dword ptr [0x5d102c]
0049e66b imul eax, dword ptr [0x5d1028]
0049e672 mov dword ptr [0x655a0c], eax
0049e677 mov ecx, eax
0049e679 shr eax, 8
0049e67c and eax, 0xffff
0049e681 and ecx, 0xffff
0049e687 shl eax, 1
0049e689 sar eax, 0x10
0049e68c add eax, 2
0049e68f mov dword ptr [0x5d1028], ecx
0049e695 mov dword ptr [esi + 0x548], eax
0049e69b mov eax, dword ptr [esi + 0x548]
0049e6a1 test eax, eax
0049e6a3 jle 0x49e6c4
0049e6a5 mov dword ptr [0x628fb0], 0
0049e6af mov eax, dword ptr [esi + 0x548]
0049e6b5 dec eax
0049e6b6 mov dword ptr [esp + 0x28], 0
0049e6be mov dword ptr [esi + 0x548], eax
0049e6c4 mov edx, dword ptr [esi + 0x760]
0049e6ca mov ecx, dword ptr [edx + 0x4c]
0049e6cd cmp ecx, 1
0049e6d0 je 0x49e6db
0049e6d2 cmp ecx, 2
0049e6d5 jne 0x49e838
0049e6db fld dword ptr [edx + 0x94]
0049e6e1 cmp ecx, 2
0049e6e4 jne 0x49e6fa
0049e6e6 fmul dword ptr [0x5b49d4]
0049e6ec fld dword ptr [edx + 0x94]
0049e6f2 fmul dword ptr [0x5b4a5c]
0049e6f8 jmp 0x49e70c
0049e6fa fmul dword ptr [0x5b2468]
0049e700 fld dword ptr [edx + 0x94]
0049e706 fmul dword ptr [0x5b23f0]
0049e70c fld dword ptr [esi + 0xdb4]
0049e712 fsub st(2)
0049e714 fcom dword ptr [0x5b23f8]
0049e71a fnstsw ax
0049e71c test ah, 0x41
0049e71f jne 0x49e746
0049e721 fxch st(1)
0049e723 fsubrp st(2)
0049e725 fxch st(1)
0049e727 fdivr st(1)
0049e729 fxch st(1)
0049e72b fstp st(0)
0049e72d fld dword ptr [0x5b24a8]
0049e733 fcomp st(1)
0049e735 fnstsw ax
0049e737 test ah, 0x41
0049e73a je 0x49e752
0049e73c fstp st(0)
0049e73e fld dword ptr [0x5b24a8]
0049e744 jmp 0x49e752
0049e746 fstp st(0)
0049e748 fstp st(0)
0049e74a fstp st(0)
0049e74c fld dword ptr [0x5b23f8]
0049e752 fld dword ptr [esi + 0xdb4]
0049e758 fdiv dword ptr [edx + 0x94]
0049e75e cmp ecx, 1
0049e761 fmul dword ptr [0x5b23f0]
0049e767 fstp dword ptr [esp + 0x10]
0049e76b jne 0x49e77b
0049e76d fld dword ptr [0x628fb0]
0049e773 fmul dword ptr [esp + 0x10]
0049e777 fstp dword ptr [esp + 0x10]
0049e77b fmul dword ptr [0x628fb0]
0049e781 fld dword ptr [esp + 0x10]
0049e785 fcomp st(1)
0049e787 fnstsw ax
0049e789 test ah, 0x41
0049e78c jne 0x49e794
0049e78e fstp st(0)
0049e790 fld dword ptr [esp + 0x10]
0049e794 mov al, byte ptr [esi + 0xd84]
0049e79a test al, al
0049e79c jne 0x49e836
0049e7a2 fcom dword ptr [esi + 0x54c]
0049e7a8 cmp ecx, 2
0049e7ab fnstsw ax
0049e7ad jne 0x49e7e5
0049e7af test ah, 0x41
0049e7b2 jne 0x49e7bc
0049e7b4 fstp dword ptr [esi + 0x54c]
0049e7ba jmp 0x49e838
0049e7bc fld dword ptr [esi + 0x54c]
0049e7c2 fsub dword ptr [0x5b2604]
0049e7c8 fstp dword ptr [esp + 0x10]
0049e7cc fcom dword ptr [esp + 0x10]
0049e7d0 fnstsw ax
0049e7d2 test ah, 0x41
0049e7d5 je 0x49e7dd
0049e7d7 fstp st(0)
0049e7d9 fld dword ptr [esp + 0x10]
0049e7dd fstp dword ptr [esi + 0x54c]
0049e7e3 jmp 0x49e838
0049e7e5 fld dword ptr [esi + 0x54c]
0049e7eb test ah, 0x41
0049e7ee jne 0x49e813
0049e7f0 fadd dword ptr [0x5b26a0]
0049e7f6 fstp dword ptr [esp + 0x10]
0049e7fa fcom dword ptr [esp + 0x10]
0049e7fe fnstsw ax
0049e800 test ah, 0x41
0049e803 jne 0x49e80b
0049e805 fstp st(0)
0049e807 fld dword ptr [esp + 0x10]
0049e80b fstp dword ptr [esi + 0x54c]
0049e811 jmp 0x49e838
0049e813 fsub dword ptr [0x5b26a0]
0049e819 fstp dword ptr [esp + 0x10]
0049e81d fcom dword ptr [esp + 0x10]
0049e821 fnstsw ax
0049e823 test ah, 0x41
0049e826 je 0x49e82e
0049e828 fstp st(0)
0049e82a fld dword ptr [esp + 0x10]
0049e82e fstp dword ptr [esi + 0x54c]
0049e834 jmp 0x49e838
0049e836 fstp st(0)
0049e838 mov cl, byte ptr [esi + 0xd82]
0049e83e xor edx, edx
0049e840 cmp cl, 1
0049e843 mov dword ptr [esi + 0xdbc], edx
0049e849 mov dword ptr [esi + 0xdb8], edx
0049e84f je 0x49ef36
0049e855 mov al, byte ptr [esi + 0xd84]
0049e85b test al, al
0049e85d jg 0x49ef36
0049e863 cmp dword ptr [0x628f98], edx
0049e869 je 0x49ef36
0049e86f mov eax, dword ptr [esi + 0x520]
0049e875 lea ecx, [eax + eax*4]
0049e878 lea eax, [eax + ecx*2]
0049e87b shl eax, 7
0049e87e cmp dword ptr [eax + 0x658098], 1
0049e885 je 0x49e88f
0049e887 cmp dword ptr [esi + 0xda8], edx
0049e88d je 0x49e898
0049e88f push esi
0049e890 call 0x49daf0
0049e895 add esp, 4
0049e898 mov al, byte ptr [esi + 0xd84]
0049e89e test al, al
0049e8a0 je 0x49e8b9
0049e8a2 mov al, byte ptr [esi + 0xd83]
0049e8a8 test al, al
0049e8aa jne 0x49e8b9
0049e8ac movsx ecx, byte ptr [esi + 0xd81]
0049e8b3 fld dword ptr [ebp + ecx*4 + 0x60]
0049e8b7 jmp 0x49e8c4
0049e8b9 movsx edx, byte ptr [esi + 0xd82]
0049e8c0 fld dword ptr [ebp + edx*4 + 0x60]
0049e8c4 fmul dword ptr [esi + 0xd60]
0049e8ca mov edi, dword ptr [esi + 0x760]
0049e8d0 fstp dword ptr [esp + 0x10]
0049e8d4 fld dword ptr [esi + 0xdb4]
0049e8da fld dword ptr [edi + 0x94]
0049e8e0 fst dword ptr [esp + 0x14]
0049e8e4 fcomp st(1)
0049e8e6 fnstsw ax
0049e8e8 test ah, 0x41
0049e8eb je 0x49e8f3
0049e8ed fstp st(0)
0049e8ef fld dword ptr [esp + 0x14]
0049e8f3 fld dword ptr [0x5b23f8]
0049e8f9 fcomp st(1)
0049e8fb fnstsw ax
0049e8fd test ah, 0x41
0049e900 jne 0x49e90a
0049e902 fstp st(0)
0049e904 fld dword ptr [0x5b23f8]
0049e90a fld st(0)
0049e90c fmul dword ptr [0x5b4a30]
0049e912 call 0x5a0f98
0049e917 lea ecx, [eax + eax*4]
0049e91a push esi
0049e91b fld dword ptr [edi + eax*4 + 0x9c]
0049e922 lea ecx, [ecx + ecx*4]
0049e925 movsx edx, byte ptr [esi + 0xd82]
0049e92c lea ecx, [ecx + ecx*4]
0049e92f shl ecx, 2
0049e932 mov dword ptr [esp + 0x18], ecx
0049e936 fild dword ptr [esp + 0x18]
0049e93a fsubr st(2)
0049e93c fmul dword ptr [0x5b4a30]
0049e942 fld dword ptr [edi + eax*4 + 0xa0]
0049e949 fsub st(2)
0049e94b fmulp st(1)
0049e94d fadd st(1)
0049e94f fmul dword ptr [ebp + edx*4 + 0x190]
0049e956 fstp dword ptr [esp + 0x18]
0049e95a fstp st(0)
0049e95c fstp st(0)
0049e95e call 0x4938a0
0049e963 fmul dword ptr [0x5b4a64]
0049e969 push esi
0049e96a fsubr dword ptr [0x5b24a8]
0049e970 fmul dword ptr [esp + 0x1c]
0049e974 fstp dword ptr [esp + 0x1c]
0049e978 call 0x493aa0
0049e97d fmul dword ptr [0x5b3284]
0049e983 add esp, 8
0049e986 fsubr dword ptr [0x5b24a8]
0049e98c fmul dword ptr [esp + 0x14]
0049e990 fld dword ptr [esp + 0x10]
0049e994 fcomp dword ptr [0x5b23f8]
0049e99a fld dword ptr [esp + 0x10]
0049e99e fnstsw ax
0049e9a0 test ah, 1
0049e9a3 je 0x49e9a7
0049e9a5 fchs
0049e9a7 fld dword ptr [esp + 0x28]
0049e9ab fsub st(1)
0049e9ad fstp dword ptr [esp + 0x14]
0049e9b1 fstp st(0)
0049e9b3 fld dword ptr [esp + 0x14]
0049e9b7 fcomp dword ptr [0x5b23f8]
0049e9bd fld dword ptr [esp + 0x14]
0049e9c1 fnstsw ax
0049e9c3 test ah, 1
0049e9c6 je 0x49e9ca
0049e9c8 fchs
0049e9ca fcomp dword ptr [0x5b4a58]
0049e9d0 fnstsw ax
0049e9d2 test ah, 1
0049e9d5 je 0x49e9f6
0049e9d7 fld dword ptr [ebp + 0x94]
0049e9dd fsub dword ptr [0x5b2524]
0049e9e3 fcomp dword ptr [esp + 0x28]
0049e9e7 fnstsw ax
0049e9e9 test ah, 0x41
0049e9ec jne 0x49e9f6
0049e9ee mov dword ptr [esp + 0x14], 0
0049e9f6 fld dword ptr [esp + 0x10]
0049e9fa fcomp dword ptr [0x5b23f8]
0049ea00 fld dword ptr [esp + 0x10]
0049ea04 fnstsw ax
0049ea06 test ah, 1
0049ea09 je 0x49ea0d
0049ea0b fchs
0049ea0d fld dword ptr [esi + 0xdb4]
0049ea13 fsub st(1)
0049ea15 fstp dword ptr [esp + 0xc]
0049ea19 fstp st(0)
0049ea1b fld dword ptr [esp + 0xc]
0049ea1f fcomp dword ptr [0x5b4a60]
0049ea25 fnstsw ax
0049ea27 test ah, 0x41
0049ea2a jne 0x49ea41
0049ea2c mov al, byte ptr [esi + 0xd84]
0049ea32 test al, al
0049ea34 jne 0x49ea41
0049ea36 mov cl, byte ptr [esi + 0xd82]
0049ea3c cmp cl, 1
0049ea3f jne 0x49ea91
0049ea41 mov cl, byte ptr [esi + 0xd82]
0049ea47 cmp cl, 1
0049ea4a jle 0x49ea5f
0049ea4c fld dword ptr [esi + 0xd60]
0049ea52 fcomp dword ptr [0x5b2444]
0049ea58 fnstsw ax
0049ea5a test ah, 1
0049ea5d jne 0x49ea91
0049ea5f test cl, cl
0049ea61 jne 0x49ea76
0049ea63 fld dword ptr [esi + 0xd60]
0049ea69 fcomp dword ptr [0x5b2604]
0049ea6f fnstsw ax
0049ea71 test ah, 0x41
0049ea74 je 0x49ea91
0049ea76 cmp dword ptr [esi + 0xdb8], 1
0049ea7d jne 0x49ebfe
0049ea83 mov eax, dword ptr [esi + 0x548]
0049ea89 test eax, eax
0049ea8b jne 0x49ebfe
0049ea91 mov edx, dword ptr [esi + 0x760]
0049ea97 fld dword ptr [edx + 0x5c]
0049ea9a fcomp dword ptr [0x5b23f8]
0049eaa0 fld st(0)
0049eaa2 fmul dword ptr [0x5b243c]
0049eaa8 fnstsw ax
0049eaaa fcom dword ptr [0x5b23f8]
0049eab0 test ah, 0x41
0049eab3 fnstsw ax
0049eab5 jne 0x49eae0
0049eab7 test ah, 1
0049eaba je 0x49eabe
0049eabc fchs
0049eabe fld dword ptr [esi + 0xab0]
0049eac4 fadd dword ptr [esi + 0x9ec]
0049eaca fadd dword ptr [esi + 0x928]
0049ead0 fadd dword ptr [esi + 0x864]
0049ead6 fsubp st(1)
0049ead8 fsubr dword ptr [0x5b3d60]
0049eade jmp 0x49eafb
0049eae0 test ah, 1
0049eae3 je 0x49eae7
0049eae5 fchs
0049eae7 fld dword ptr [esi + 0xab0]
0049eaed fadd dword ptr [esi + 0x9ec]
0049eaf3 fsubp st(1)
0049eaf5 fsubr dword ptr [0x5b242c]
0049eafb xor eax, eax
0049eafd mov al, byte ptr [esi + 0xd7c]
0049eb03 mov dword ptr [esp + 0x28], eax
0049eb07 fild dword ptr [esp + 0x28]
0049eb0b fmul dword ptr [0x5b4a54]
0049eb11 fld dword ptr [0x5b25f0]
0049eb17 fcomp st(1)
0049eb19 fnstsw ax
0049eb1b test ah, 0x41
0049eb1e jne 0x49eb28
0049eb20 fstp st(0)
0049eb22 fld dword ptr [0x5b25f0]
0049eb28 fxch st(1)
0049eb2a fdiv st(1)
0049eb2c cmp dword ptr [edx + 0x54], 4
0049eb30 fld dword ptr [0x5b24a8]
0049eb36 fsub dword ptr [0x628fb0]
0049eb3c fmul dword ptr [0x5b242c]
0049eb42 faddp st(1)
0049eb44 fstp dword ptr [esp + 0x28]
0049eb48 fstp st(0)
0049eb4a jg 0x49eb67
0049eb4c cmp cl, 2
0049eb4f jle 0x49eb67
0049eb51 fld dword ptr [esp + 0xc]
0049eb55 fmul dword ptr [0x5b49d4]
0049eb5b fsubr dword ptr [esi + 0xdb4]
0049eb61 fstp dword ptr [esi + 0xdb4]
0049eb67 fld dword ptr [0x628fb0]
0049eb6d fcomp dword ptr [0x5b23f0]
0049eb73 fnstsw ax
0049eb75 test ah, 1
0049eb78 jne 0x49ebe3
0049eb7a mov eax, dword ptr [esp + 0x1c]
0049eb7e test eax, eax
0049eb80 jne 0x49ebe3
0049eb82 fld dword ptr [esp + 0xc]
0049eb86 fcomp dword ptr [esp + 0x20]
0049eb8a fnstsw ax
0049eb8c test ah, 0x41
0049eb8f jne 0x49ebb5
0049eb91 fld dword ptr [edx + 0x5c]
0049eb94 fcomp dword ptr [0x5b23f8]
0049eb9a fnstsw ax
0049eb9c test ah, 0x41
0049eb9f jne 0x49ebab
0049eba1 mov dword ptr [esi + 0xdbc], 2
0049ebab mov dword ptr [esi + 0xdb8], 2
0049ebb5 fld dword ptr [esp + 0xc]
0049ebb9 fcomp dword ptr [esp + 0x28]
0049ebbd fnstsw ax
0049ebbf test ah, 0x41
0049ebc2 jne 0x49ebca
0049ebc4 fld dword ptr [esp + 0x28]
0049ebc8 jmp 0x49ebce
0049ebca fld dword ptr [esp + 0xc]
0049ebce fld dword ptr [esi + 0xdb4]
0049ebd4 fsub st(1)
0049ebd6 fstp dword ptr [esi + 0xdb4]
0049ebdc fstp st(0)
0049ebde jmp 0x49ee54
0049ebe3 fld dword ptr [esp + 0xc]
0049ebe7 fmul dword ptr [0x5b49d4]
0049ebed fsubr dword ptr [esi + 0xdb4]
0049ebf3 fstp dword ptr [esi + 0xdb4]
0049ebf9 jmp 0x49ee54
0049ebfe fld dword ptr [esp + 0x14]
0049ec02 fcomp dword ptr [0x5b23f8]
0049ec08 fnstsw ax
0049ec0a test ah, 1
0049ec0d je 0x49ed4a
0049ec13 fld dword ptr [esp + 0x10]
0049ec17 fcomp dword ptr [0x5b23f8]
0049ec1d fld dword ptr [esp + 0x10]
0049ec21 fnstsw ax
0049ec23 test ah, 1
0049ec26 je 0x49ec2a
0049ec28 fchs
0049ec2a mov edx, dword ptr [esi + 0x760]
0049ec30 fld dword ptr [edx + 0x94]
0049ec36 fadd dword ptr [0x5b24e0]
0049ec3c fxch st(1)
0049ec3e fcompp
0049ec40 fnstsw ax
0049ec42 test ah, 0x41
0049ec45 jne 0x49ec90
0049ec47 movsx eax, cl
0049ec4a fchs
0049ec4c test cl, cl
0049ec4e fld dword ptr [ebp + eax*4 + 0x170]
0049ec55 fmul dword ptr [0x5b4a50]
0049ec5b fstp dword ptr [esp + 0x10]
0049ec5f fld dword ptr [esp + 0xc]
0049ec63 fchs
0049ec65 fcom dword ptr [esp + 0x10]
0049ec69 fnstsw ax
0049ec6b jne 0x49ec74
0049ec6d test ah, 0x41
0049ec70 je 0x49ec7f
0049ec72 jmp 0x49ec79
0049ec74 test ah, 0x41
0049ec77 jne 0x49ec7f
0049ec79 fstp st(0)
0049ec7b fld dword ptr [esp + 0x10]
0049ec7f fadd dword ptr [esi + 0xdb4]
0049ec85 fstp dword ptr [esi + 0xdb4]
0049ec8b jmp 0x49ee54
0049ec90 mov eax, dword ptr [esi + 0x548]
0049ec96 test eax, eax
0049ec98 jle 0x49eca0
0049ec9a fmul dword ptr [0x5b2404]
0049eca0 fmul dword ptr [ebp + 0x98]
0049eca6 push esi
0049eca7 fchs
0049eca9 fstp dword ptr [esp + 0x18]
0049ecad call 0x493aa0
0049ecb2 fmul dword ptr [0x5b3714]
0049ecb8 add esp, 4
0049ecbb fadd dword ptr [0x5b24a8]
0049ecc1 fld dword ptr [0x5b2400]
0049ecc7 fcomp st(1)
0049ecc9 fnstsw ax
0049eccb test ah, 0x41
0049ecce je 0x49ecd8
0049ecd0 fstp st(0)
0049ecd2 fld dword ptr [0x5b2400]
0049ecd8 mov al, byte ptr [esi + 0xd82]
0049ecde fmul dword ptr [esp + 0x14]
0049ece2 movsx ecx, al
0049ece5 test al, al
0049ece7 fld dword ptr [ebp + ecx*4 + 0x170]
0049ecee fmul dword ptr [0x5b4a50]
0049ecf4 fstp dword ptr [esp + 0x10]
0049ecf8 fld dword ptr [esp + 0xc]
0049ecfc fchs
0049ecfe fcom dword ptr [esp + 0x10]
0049ed02 fnstsw ax
0049ed04 jne 0x49ed0d
0049ed06 test ah, 0x41
0049ed09 je 0x49ed18
0049ed0b jmp 0x49ed12
0049ed0d test ah, 0x41
0049ed10 jne 0x49ed18
0049ed12 fstp st(0)
0049ed14 fld dword ptr [esp + 0x10]
0049ed18 fadd dword ptr [esi + 0xdb4]
0049ed1e fstp dword ptr [esi + 0xdb4]
0049ed24 fld dword ptr [esi + 0xdb4]
0049ed2a fcom dword ptr [esp + 0x28]
0049ed2e fnstsw ax
0049ed30 test ah, 0x41
0049ed33 je 0x49ec85
0049ed39 fstp st(0)
0049ed3b fld dword ptr [esp + 0x28]
0049ed3f fstp dword ptr [esi + 0xdb4]
0049ed45 jmp 0x49ee54
0049ed4a fld dword ptr [esp + 0x14]
0049ed4e fcomp dword ptr [0x5b23f8]
0049ed54 fnstsw ax
0049ed56 test ah, 0x40
0049ed59 je 0x49ed70
0049ed5b mov edx, dword ptr [esp + 0x10]
0049ed5f fstp st(0)
0049ed61 fld dword ptr [esp + 0x18]
0049ed65 mov dword ptr [esi + 0xdb4], edx
0049ed6b jmp 0x49ee54
0049ed70 mov eax, dword ptr [esp + 0x1c]
0049ed74 test eax, eax
0049ed76 je 0x49ed94
0049ed78 fstp st(0)
0049ed7a fld dword ptr [esi + 0xdb4]
0049ed80 fsub dword ptr [0x5b242c]
0049ed86 fstp dword ptr [esi + 0xdb4]
0049ed8c fld dword ptr [0x5b23f8]
0049ed92 jmp 0x49edee
0049ed94 fld dword ptr [esp + 0xc]
0049ed98 fcomp dword ptr [0x5b2484]
0049ed9e fnstsw ax
0049eda0 test ah, 0x41
0049eda3 jne 0x49edb9
0049eda5 fld dword ptr [esi + 0xdb4]
0049edab fsub dword ptr [0x5b2484]
0049edb1 fstp dword ptr [esi + 0xdb4]
0049edb7 jmp 0x49ede8
0049edb9 fld dword ptr [esp + 0xc]
0049edbd fcomp dword ptr [0x5b4a4c]
0049edc3 fnstsw ax
0049edc5 test ah, 1
0049edc8 je 0x49edde
0049edca fld dword ptr [esi + 0xdb4]
0049edd0 fadd dword ptr [0x5b2484]
0049edd6 fstp dword ptr [esi + 0xdb4]
0049eddc jmp 0x49ede8
0049edde mov eax, dword ptr [esp + 0x10]
0049ede2 mov dword ptr [esi + 0xdb4], eax
0049ede8 fmul dword ptr [0x628fb0]
0049edee fld dword ptr [esi + 0xdb4]
0049edf4 fcom dword ptr [esp + 0x28]
0049edf8 fnstsw ax
0049edfa test ah, 0x41
0049edfd jne 0x49ee05
0049edff fstp st(0)
0049ee01 fld dword ptr [esp + 0x28]
0049ee05 fstp dword ptr [esi + 0xdb4]
0049ee0b mov eax, dword ptr [0x6573f8]
0049ee10 test eax, eax
0049ee12 je 0x49ee54
0049ee14 fmul dword ptr [0x5b3f64]
0049ee1a fld dword ptr [esi + 0xdc0]
0049ee20 fcomp dword ptr [0x5b23f8]
0049ee26 fld dword ptr [esi + 0xdc0]
0049ee2c fnstsw ax
0049ee2e test ah, 1
0049ee31 je 0x49ee35
0049ee33 fchs
0049ee35 fadd dword ptr [0x5b24a8]
0049ee3b fld dword ptr [0x5b2580]
0049ee41 fcomp st(1)
0049ee43 fnstsw ax
0049ee45 test ah, 0x41
0049ee48 je 0x49ee52
0049ee4a fstp st(0)
0049ee4c fld dword ptr [0x5b2580]
0049ee52 fmulp st(1)
0049ee54 fld dword ptr [esi + 0xdb4]
0049ee5a fcomp dword ptr [0x5b23f8]
0049ee60 fnstsw ax
0049ee62 test ah, 1
0049ee65 je 0x49ef02
0049ee6b fld dword ptr [esi + 0xd60]
0049ee71 fmul dword ptr [0x5b2644]
0049ee77 fchs
0049ee79 fstp dword ptr [esp + 0x28]
0049ee7d fcom dword ptr [0x5b23f8]
0049ee83 fnstsw ax
0049ee85 test ah, 0x41
0049ee88 jne 0x49eeb2
0049ee8a fld dword ptr [esp + 0x28]
0049ee8e fcomp dword ptr [0x5b23f8]
0049ee94 fnstsw ax
0049ee96 test ah, 0x41
0049ee99 jne 0x49eeb2
0049ee9b fld st(0)
0049ee9d fsub dword ptr [esp + 0x28]
0049eea1 fcomp dword ptr [0x5b23f8]
0049eea7 fnstsw ax
0049eea9 test ah, 0x41
0049eeac je 0x49f0af
0049eeb2 fcom dword ptr [0x5b23f8]
0049eeb8 fnstsw ax
0049eeba test ah, 1
0049eebd je 0x49eee7
0049eebf fld dword ptr [esp + 0x28]
0049eec3 fcomp dword ptr [0x5b23f8]
0049eec9 fnstsw ax
0049eecb test ah, 1
0049eece je 0x49eee7
0049eed0 fld st(0)
0049eed2 fsub dword ptr [esp + 0x28]
0049eed6 fcomp dword ptr [0x5b23f8]
0049eedc fnstsw ax
0049eede test ah, 1
0049eee1 jne 0x49f0af
0049eee7 fstp st(0)
0049eee9 fld dword ptr [esp + 0x28]
0049eeed fsub dword ptr [esp + 0x18]
0049eef1 mov dword ptr [esi + 0xdb4], 0
0049eefb pop edi
0049eefc pop esi
0049eefd pop ebp
0049eefe add esp, 0x18
0049ef01 ret
0049ef02 mov ecx, dword ptr [esi + 0x760]
0049ef08 fld dword ptr [ecx + 0x94]
0049ef0e fmul dword ptr [0x5b3f64]
0049ef14 fcom dword ptr [esi + 0xdb4]
0049ef1a fnstsw ax
0049ef1c test ah, 1
0049ef1f je 0x49f0ad
0049ef25 fstp dword ptr [esi + 0xdb4]
0049ef2b pop edi
0049ef2c pop esi
0049ef2d fsub dword ptr [esp + 0x10]
0049ef31 pop ebp
0049ef32 add esp, 0x18
0049ef35 ret
0049ef36 fld dword ptr [esi + 0xdb4]
0049ef3c cmp edi, edx
0049ef3e je 0x49ef51
0049ef40 fsub dword ptr [0x5b242c]
0049ef46 fst dword ptr [esi + 0xdb4]
0049ef4c jmp 0x49f024
0049ef51 fcomp dword ptr [esp + 0x28]
0049ef55 fnstsw ax
0049ef57 mov al, byte ptr [esi + 0xd84]
0049ef5d test ah, 1
0049ef60 je 0x49ef8c
0049ef62 test al, al
0049ef64 jne 0x49ef8e
0049ef66 fld dword ptr [esi + 0xdb4]
0049ef6c fadd dword ptr [0x5b4a60]
0049ef72 fcom dword ptr [esp + 0x28]
0049ef76 fst dword ptr [esi + 0xdb4]
0049ef7c fnstsw ax
0049ef7e test ah, 0x41
0049ef81 jne 0x49f06f
0049ef87 jmp 0x49f069
0049ef8c test al, al
0049ef8e jle 0x49f03b
0049ef94 cmp byte ptr [esi + 0xd81], 1
0049ef9b je 0x49f03b
0049efa1 mov al, byte ptr [esi + 0xd83]
0049efa7 test al, al
0049efa9 je 0x49efff
0049efab cmp byte ptr [esi + 0xd80], 0x40
0049efb2 jbe 0x49efc4
0049efb4 movsx edx, byte ptr [esi + 0xd7e]
0049efbb fld dword ptr [edx*4 + 0x5d0c90]
0049efc2 jmp 0x49efd2
0049efc4 movsx eax, byte ptr [esi + 0xd7e]
0049efcb fld dword ptr [eax*4 + 0x5d0c70]
0049efd2 fadd dword ptr [esi + 0xdb4]
0049efd8 fstp dword ptr [esi + 0xdb4]
0049efde fld dword ptr [ebp + 0x94]
0049efe4 fld dword ptr [esi + 0xdb4]
0049efea fst dword ptr [esp + 0x28]
0049efee fcomp st(1)
0049eff0 fnstsw ax
0049eff2 test ah, 0x41
0049eff5 je 0x49f06f
0049eff7 fstp st(0)
0049eff9 fld dword ptr [esp + 0x28]
0049effd jmp 0x49f06f
0049efff fld dword ptr [esi + 0xdb4]
0049f005 cmp cl, 4
0049f008 jl 0x49f012
0049f00a fsub dword ptr [0x5b2484]
0049f010 jmp 0x49f018
0049f012 fsub dword ptr [0x5b242c]
0049f018 fstp dword ptr [esi + 0xdb4]
0049f01e fld dword ptr [esi + 0xdb4]
0049f024 fcom dword ptr [0x5b23f8]
0049f02a fnstsw ax
0049f02c test ah, 0x41
0049f02f je 0x49f06f
0049f031 fstp st(0)
0049f033 fld dword ptr [0x5b23f8]
0049f039 jmp 0x49f06f
0049f03b fld dword ptr [esi + 0xdb4]
0049f041 fcomp dword ptr [esp + 0x28]
0049f045 fnstsw ax
0049f047 test ah, 1
0049f04a jne 0x49f075
0049f04c fld dword ptr [esi + 0xdb4]
0049f052 fsub dword ptr [0x5b2484]
0049f058 fcom dword ptr [esp + 0x28]
0049f05c fst dword ptr [esi + 0xdb4]
0049f062 fnstsw ax
0049f064 test ah, 0x41
0049f067 je 0x49f06f
0049f069 fstp st(0)
0049f06b fld dword ptr [esp + 0x28]
0049f06f fstp dword ptr [esi + 0xdb4]
0049f075 fld dword ptr [esi + 0x54c]
0049f07b fsub dword ptr [0x5b2604]
0049f081 fld dword ptr [0x5b23f8]
0049f087 fcomp st(1)
0049f089 fnstsw ax
0049f08b test ah, 0x41
0049f08e jne 0x49f098
0049f090 fstp st(0)
0049f092 fld dword ptr [0x5b23f8]
0049f098 fstp dword ptr [esi + 0x54c]
0049f09e fld dword ptr [esp + 0x14]
0049f0a2 fsub dword ptr [esp + 0x18]
0049f0a6 pop edi
0049f0a7 pop esi
0049f0a8 pop ebp
0049f0a9 add esp, 0x18
0049f0ac ret
0049f0ad fstp st(0)
0049f0af fsub dword ptr [esp + 0x18]
0049f0b3 pop edi
0049f0b4 pop esi
0049f0b5 pop ebp
0049f0b6 add esp, 0x18
0049f0b9 ret
0049f0ba nop
0049f0bb nop
0049f0bc nop
0049f0bd nop
0049f0be nop
0049f0bf nop
0049f0c0 mov ecx, dword ptr [esp + 4]
0049f0c4 test byte ptr [ecx + 0x52c], 0x10
0049f0cb jne 0x49f157
0049f0d1 cmp dword ptr [0x6573e8], 3
0049f0d8 jne 0x49f0e3
0049f0da mov eax, dword ptr [0x657408]
0049f0df test eax, eax
0049f0e1 jne 0x49f157
0049f0e3 cmp byte ptr [ecx + 0xd80], 0x40
0049f0ea jae 0x49f104
0049f0ec fld dword ptr [ecx + 0x380]
0049f0f2 fmul dword ptr [0x5b2438]
0049f0f8 fadd dword ptr [ecx + 0xd54]
0049f0fe fstp dword ptr [ecx + 0xd54]
0049f104 fld dword ptr [ecx + 0xd58]
0049f10a fcomp dword ptr [0x5b23f8]
0049f110 fld dword ptr [ecx + 0xd58]
0049f116 fnstsw ax
0049f118 test ah, 1
0049f11b je 0x49f11f
0049f11d fchs
0049f11f fcomp dword ptr [0x5b24a8]
0049f125 fnstsw ax
0049f127 test ah, 0x41
0049f12a je 0x49f13f
0049f12c fld dword ptr [ecx + 0x374]
0049f132 fcomp dword ptr [0x5b4a6c]
0049f138 fnstsw ax
0049f13a test ah, 1
0049f13d je 0x49f157
0049f13f fld dword ptr [ecx + 0x368]
0049f145 fmul dword ptr [0x5b4a68]
0049f14b fadd dword ptr [ecx + 0xd4c]
0049f151 fstp dword ptr [ecx + 0xd4c]
0049f157 ret
0049f158 nop
0049f159 nop
0049f15a nop
0049f15b nop
0049f15c nop
0049f15d nop
0049f15e nop
0049f15f nop
0049f160 push ebp
0049f161 mov ebp, esp
0049f163 sub esp, 0x58
0049f166 push ebx
0049f167 push esi
0049f168 mov esi, dword ptr [ebp + 8]
0049f16b xor ecx, ecx
0049f16d push edi
0049f16e mov eax, dword ptr [esi + 0x760]
0049f174 mov dword ptr [ebp - 0x10], eax
0049f177 mov eax, 1
0049f17c mov dword ptr [0x628f9c], eax
0049f181 mov dword ptr [0x628f98], eax
0049f186 cmp dword ptr [esi + 0x83c], ecx
0049f18c je 0x49f1af
0049f18e cmp dword ptr [esi + 0x900], ecx
0049f194 je 0x49f1af
0049f196 fld dword ptr [esi + 0x424]
0049f19c fcomp dword ptr [0x5b26a0]
0049f1a2 fnstsw ax
0049f1a4 test ah, 0x41
0049f1a7 jne 0x49f1af
0049f1a9 mov dword ptr [0x628f9c], ecx
0049f1af cmp dword ptr [esi + 0x9c4], ecx
0049f1b5 je 0x49f1d8
0049f1b7 cmp dword ptr [esi + 0xa88], ecx
0049f1bd je 0x49f1d8
0049f1bf fld dword ptr [esi + 0x424]
0049f1c5 fcomp dword ptr [0x5b26a0]
0049f1cb fnstsw ax
0049f1cd test ah, 0x41
0049f1d0 jne 0x49f1d8
0049f1d2 mov dword ptr [0x628f98], ecx
0049f1d8 lea eax, [esi + 0x490]
0049f1de lea ebx, [esi + 0x33c]
0049f1e4 push eax
0049f1e5 push ebx
0049f1e6 call 0x532910
0049f1eb fstp dword ptr [esi + 0xd58]
0049f1f1 lea edi, [esi + 0x49c]
0049f1f7 push edi
0049f1f8 push ebx
0049f1f9 call 0x532910
0049f1fe fstp dword ptr [esi + 0xd5c]
0049f204 lea ebx, [esi + 0x4a8]
0049f20a lea eax, [esi + 0x33c]
0049f210 push ebx
0049f211 push eax
0049f212 call 0x532910
0049f217 fstp dword ptr [esi + 0xd60]
0049f21d lea eax, [esi + 0x490]
0049f223 lea ecx, [esi + 0x388]
0049f229 push eax
0049f22a push ecx
0049f22b call 0x532910
0049f230 fstp dword ptr [esi + 0xd64]
0049f236 lea eax, [esi + 0x388]
0049f23c push edi
0049f23d push eax
0049f23e call 0x532910
0049f243 fstp dword ptr [esi + 0xd68]
0049f249 lea eax, [esi + 0x388]
0049f24f push ebx
0049f250 push eax
0049f251 call 0x532910
0049f256 fstp dword ptr [esi + 0xd6c]
0049f25c fld dword ptr [esi + 0xd60]
0049f262 fcomp dword ptr [0x5b2400]
0049f268 add esp, 0x30
0049f26b fnstsw ax
0049f26d test ah, 0x41
0049f270 jne 0x49f286
0049f272 fld dword ptr [esi + 0xd58]
0049f278 fdiv dword ptr [esi + 0xd60]
0049f27e fstp dword ptr [esi + 0xdc0]
0049f284 jmp 0x49f290
0049f286 mov dword ptr [esi + 0xdc0], 0
0049f290 fld dword ptr [esi + 0xd58]
0049f296 fmul dword ptr [0x5b2644]
0049f29c mov ecx, dword ptr [ebp - 0x10]
0049f29f fmul dword ptr [0x5b2448]
0049f2a5 fstp dword ptr [ebp - 0x1c]
0049f2a8 fld dword ptr [esi + 0xd5c]
0049f2ae fmul dword ptr [0x5b2644]
0049f2b4 fmul dword ptr [0x5b2448]
0049f2ba fstp dword ptr [ebp - 0x18]
0049f2bd fld dword ptr [esi + 0xd60]
0049f2c3 fmul dword ptr [0x5b2644]
0049f2c9 fmul dword ptr [0x5b2448]
0049f2cf fstp dword ptr [ebp - 0x14]
0049f2d2 fld dword ptr [ecx + 0x1b4]
0049f2d8 fmul dword ptr [esi + 0x38c]
0049f2de fmul dword ptr [0x5b2644]
0049f2e4 fmul dword ptr [0x5b2448]
0049f2ea fld dword ptr [esi + 0x35c]
0049f2f0 fcomp dword ptr [0x5b241c]
0049f2f6 fld dword ptr [esi + 0x35c]
0049f2fc fnstsw ax
0049f2fe test ah, 1
0049f301 je 0x49f313
0049f303 fadd dword ptr [0x5b2408]
0049f309 fmul st(1)
0049f30b fmul dword ptr [0x5b4a2c]
0049f311 jmp 0x49f321
0049f313 fadd dword ptr [0x5b26f4]
0049f319 fmul st(1)
0049f31b fmul dword ptr [0x5b4a84]
0049f321 fstp dword ptr [ebp + 8]
0049f324 lea eax, [esi + 0x490]
0049f32a lea edx, [ebp - 0x28]
0049f32d push eax
0049f32e push edx
0049f32f fstp st(0)
0049f331 mov dword ptr [ebp - 0x28], 0
0049f338 mov dword ptr [ebp - 0x24], 0xc11ccccd
0049f33f mov dword ptr [ebp - 0x20], 0
0049f346 call 0x532910
0049f34b fstp dword ptr [0x628fa0]
0049f351 lea eax, [ebp - 0x28]
0049f354 push edi
0049f355 push eax
0049f356 call 0x532910
0049f35b fstp dword ptr [0x628fa4]
0049f361 lea ecx, [ebp - 0x28]
0049f364 push ebx
0049f365 push ecx
0049f366 call 0x532910
0049f36b fstp dword ptr [0x628fa8]
0049f371 fld dword ptr [ebp + 8]
0049f374 fadd dword ptr [ebp - 0x1c]
0049f377 mov edx, dword ptr [ebp - 0x18]
0049f37a mov ecx, dword ptr [ebp - 0x14]
0049f37d mov eax, edx
0049f37f push esi
0049f380 fst dword ptr [esi + 0x918]
0049f386 fstp dword ptr [esi + 0x854]
0049f38c fld dword ptr [ebp - 0x1c]
0049f38f fsub dword ptr [ebp + 8]
0049f392 mov dword ptr [esi + 0x91c], edx
0049f398 mov dword ptr [esi + 0x858], eax
0049f39e mov edx, ecx
0049f3a0 mov dword ptr [esi + 0x920], ecx
0049f3a6 mov dword ptr [esi + 0x85c], edx
0049f3ac mov ecx, eax
0049f3ae fst dword ptr [esi + 0xaa0]
0049f3b4 fstp dword ptr [esi + 0x9dc]
0049f3ba mov dword ptr [esi + 0xaa4], eax
0049f3c0 mov dword ptr [esi + 0x9e0], ecx
0049f3c6 mov eax, edx
0049f3c8 mov dword ptr [esi + 0xaa8], edx
0049f3ce mov dword ptr [esi + 0x9e4], eax
0049f3d4 call 0x49dd20
0049f3d9 fld dword ptr [0x628fa0]
0049f3df fmul dword ptr [0x5b2608]
0049f3e5 add esp, 0x1c
0049f3e8 fstp dword ptr [ebp + 8]
0049f3eb fld dword ptr [ebp + 8]
0049f3ee fistp dword ptr [ebp - 0xc]
0049f3f1 mov eax, dword ptr [ebp - 0xc]
0049f3f4 mov edi, eax
0049f3f6 cmp eax, 0x40
0049f3f9 mov dword ptr [ebp - 8], edi
0049f3fc jle 0x49f405
0049f3fe mov edi, 0x40
0049f403 jmp 0x49f40f
0049f405 cmp eax, -0x40
0049f408 jge 0x49f412
0049f40a mov edi, 0xffffffc0
0049f40f mov dword ptr [ebp - 8], edi
0049f412 fld dword ptr [esi + 0x4ec]
0049f418 fmul dword ptr [0x5b2468]
0049f41e fld dword ptr [esi + 0x4e4]
0049f424 fmul dword ptr [0x5b2468]
0049f42a mov ecx, dword ptr [0x606ac4]
0049f430 mov dword ptr [ebp + 8], 0
0049f437 and ecx, 0x80000003
0049f43d fsubp st(1)
0049f43f fstp dword ptr [ebp - 4]
0049f442 jns 0x49f449
0049f444 dec ecx
0049f445 or ecx, 0xfffffffc
0049f448 inc ecx
0049f449 jne 0x49f4c6
0049f44b mov eax, dword ptr [0x5d102c]
0049f450 push esi
0049f451 imul eax, dword ptr [0x5d1028]
0049f458 mov dword ptr [0x655a0c], eax
0049f45d mov edx, eax
0049f45f shr eax, 8
0049f462 and edx, 0xffff
0049f468 and eax, 0xffff
0049f46d mov dword ptr [0x5d1028], edx
0049f473 mov dword ptr [ebp + 8], eax
0049f476 call 0x493bc0
0049f47b fild dword ptr [ebp + 8]
0049f47e add esp, 4
0049f481 fmul dword ptr [0x5b253c]
0049f487 fsub dword ptr [0x5b23f0]
0049f48d fmulp st(1)
0049f48f fmul dword ptr [0x5b23f0]
0049f495 fstp dword ptr [ebp + 8]
0049f498 fld dword ptr [esi + 0x35c]
0049f49e fcomp dword ptr [0x5b243c]
0049f4a4 fnstsw ax
0049f4a6 test ah, 1
0049f4a9 je 0x49f4bd
0049f4ab fld dword ptr [ebp + 8]
0049f4ae fmul dword ptr [esi + 0x35c]
0049f4b4 fmul dword ptr [0x5b49ec]
0049f4ba fstp dword ptr [ebp + 8]
0049f4bd fld dword ptr [ebp + 8]
0049f4c0 fadd dword ptr [ebp - 4]
0049f4c3 fstp dword ptr [ebp - 4]
0049f4c6 fld dword ptr [ebp - 4]
0049f4c9 fistp dword ptr [ebp - 0xc]
0049f4cc mov eax, dword ptr [ebp - 0xc]
0049f4cf mov ebx, dword ptr [esi + 0xd94]
0049f4d5 add eax, ebx
0049f4d7 add eax, edi
0049f4d9 cmp eax, 0x7f
0049f4dc mov dword ptr [ebp - 0xc], eax
0049f4df jle 0x49f4ea
0049f4e1 mov dword ptr [ebp - 0xc], 0x7f
0049f4e8 jmp 0x49f4f6
0049f4ea cmp eax, -0x7f
0049f4ed jge 0x49f4f6
0049f4ef mov dword ptr [ebp - 0xc], 0xffffff81
0049f4f6 mov eax, dword ptr [0x628f9c]
0049f4fb xor edi, edi
0049f4fd cmp eax, edi
0049f4ff je 0x49f5cf
0049f505 fld dword ptr [esi + 0x934]
0049f50b fadd dword ptr [esi + 0x870]
0049f511 mov eax, dword ptr [esi + 0x760]
0049f517 fmul dword ptr [0x5b2404]
0049f51d fdiv dword ptr [eax + 0xf4]
0049f523 fld dword ptr [0x5b24e8]
0049f529 fcomp st(1)
0049f52b fnstsw ax
0049f52d test ah, 0x41
0049f530 je 0x49f53a
0049f532 fstp st(0)
0049f534 fld dword ptr [0x5b24e8]
0049f53a fst dword ptr [esi + 0x564]
0049f540 fld dword ptr [0x5b24a8]
0049f546 fsub st(1)
0049f548 fstp dword ptr [esi + 0x55c]
0049f54e fstp st(0)
0049f550 fld dword ptr [esi + 0x564]
0049f556 fmul dword ptr [0x5b275c]
0049f55c fld dword ptr [ebp + 8]
0049f55f fmul dword ptr [0x5b2484]
0049f565 faddp st(1)
0049f567 fcom dword ptr [0x5b23f8]
0049f56d fnstsw ax
0049f56f test ah, 1
0049f572 je 0x49f576
0049f574 fchs
0049f576 fstp dword ptr [esi + 0x564]
0049f57c fild dword ptr [ebp - 8]
0049f57f fadd dword ptr [ebp - 4]
0049f582 fmul dword ptr [esi + 0x55c]
0049f588 fmul dword ptr [0x5b242c]
0049f58e fstp dword ptr [esi + 0x560]
0049f594 fld dword ptr [esi + 0x35c]
0049f59a fcomp dword ptr [0x5b251c]
0049f5a0 fld dword ptr [esi + 0x55c]
0049f5a6 fnstsw ax
0049f5a8 test ah, 0x41
0049f5ab jne 0x49f5bb
0049f5ad fmul dword ptr [0x5b2764]
0049f5b3 fstp dword ptr [esi + 0x55c]
0049f5b9 jmp 0x49f5e1
0049f5bb fmul dword ptr [esi + 0x35c]
0049f5c1 fmul dword ptr [0x5b2484]
0049f5c7 fstp dword ptr [esi + 0x55c]
0049f5cd jmp 0x49f5e1
0049f5cf mov dword ptr [esi + 0x55c], edi
0049f5d5 mov dword ptr [esi + 0x560], edi
0049f5db mov dword ptr [esi + 0x564], edi
0049f5e1 mov ebx, dword ptr [ebp - 0x10]
0049f5e4 fld dword ptr [ebx + 0xfc]
0049f5ea fld dword ptr [esi + 0x35c]
0049f5f0 fcomp dword ptr [0x5b2408]
0049f5f6 fnstsw ax
0049f5f8 test ah, 1
0049f5fb je 0x49f611
0049f5fd fld dword ptr [esi + 0x35c]
0049f603 fmul dword ptr [0x5b4a2c]
0049f609 fsubr dword ptr [0x5b36e8]
0049f60f fmulp st(1)
0049f611 fld dword ptr [0x5b2470]
0049f617 fcomp st(1)
0049f619 fnstsw ax
0049f61b test ah, 0x41
0049f61e je 0x49f628
0049f620 fstp st(0)
0049f622 fld dword ptr [0x5b2470]
0049f628 mov ecx, dword ptr [esi + 0x760]
0049f62e fld dword ptr [0x5b4a80]
0049f634 fdiv dword ptr [ecx + 0xfc]
0049f63a lea ecx, [esi + 0x86c]
0049f640 fmulp st(1)
0049f642 fild dword ptr [ebp - 0xc]
0049f645 fld dword ptr [esi + 0x4e4]
0049f64b fmul dword ptr [0x5b4a7c]
0049f651 fsubr dword ptr [0x5b24a8]
0049f657 fld st(1)
0049f659 fadd dword ptr [ebx + 0x100]
0049f65f fmulp st(1)
0049f661 fmul st(2)
0049f663 fmul dword ptr [0x5b4a78]
0049f669 fstp dword ptr [ecx]
0049f66b fld dword ptr [esi + 0x4ec]
0049f671 fmul dword ptr [0x5b4a7c]
0049f677 fsubr dword ptr [0x5b24a8]
0049f67d fxch st(1)
0049f67f fsub dword ptr [ebx + 0x100]
0049f685 fmulp st(1)
0049f687 fmul st(1)
0049f689 fmul dword ptr [0x5b4a78]
0049f68f fstp dword ptr [esi + 0x930]
0049f695 fstp st(0)
0049f697 fld dword ptr [esi + 0xd60]
0049f69d fcomp dword ptr [0x5b26d4]
0049f6a3 fnstsw ax
0049f6a5 test ah, 0x41
0049f6a8 jne 0x49f6cc
0049f6aa fld dword ptr [esi + 0xd60]
0049f6b0 fmul dword ptr [0x5b4a84]
0049f6b6 fld dword ptr [ecx]
0049f6b8 fdiv st(1)
0049f6ba fstp dword ptr [ecx]
0049f6bc fld dword ptr [esi + 0x930]
0049f6c2 fdiv st(1)
0049f6c4 fstp dword ptr [esi + 0x930]
0049f6ca fstp st(0)
0049f6cc lea eax, [esi + 0xac8]
0049f6d2 mov edx, 2
0049f6d7 fld dword ptr [ecx]
0049f6d9 fmul dword ptr [0x5b23f0]
0049f6df fld dword ptr [eax]
0049f6e1 fmul dword ptr [0x5b23f0]
0049f6e7 add ecx, 0xc4
0049f6ed add eax, 4
0049f6f0 faddp st(1)
0049f6f2 dec edx
0049f6f3 fstp dword ptr [eax - 4]
0049f6f6 jne 0x49f6d7
0049f6f8 push esi
0049f6f9 call 0x49e440
0049f6fe mov eax, dword ptr [0x628f9c]
0049f703 add esp, 4
0049f706 fstp dword ptr [ebp - 4]
0049f709 cmp eax, edi
0049f70b jne 0x49f746
0049f70d cmp dword ptr [0x628f98], edi
0049f713 jne 0x49f746
0049f715 mov dword ptr [esi + 0xd4c], edi
0049f71b mov dword ptr [esi + 0xd50], edi
0049f721 mov dword ptr [esi + 0xd54], edi
0049f727 mov dword ptr [esi + 0x870], edi
0049f72d mov dword ptr [esi + 0x934], edi
0049f733 mov dword ptr [esi + 0x9f8], edi
0049f739 mov dword ptr [esi + 0xabc], edi
0049f73f pop edi
0049f740 pop esi
0049f741 pop ebx
0049f742 mov esp, ebp
0049f744 pop ebp
0049f745 ret
0049f746 push esi
0049f747 mov dword ptr [esi + 0xd2c], edi
0049f74d call 0x493a10
0049f752 fmul dword ptr [0x5b3284]
0049f758 add esp, 4
0049f75b fsubr dword ptr [0x5b24a8]
0049f761 fmul dword ptr [ebx + 0x104]
0049f767 fmul dword ptr [0x628fac]
0049f76d fstp dword ptr [ebp + 8]
0049f770 fld dword ptr [esi + 0xd60]
0049f776 fcomp dword ptr [0x5b23f8]
0049f77c fld dword ptr [esi + 0xd60]
0049f782 fnstsw ax
0049f784 test ah, 1
0049f787 je 0x49f78b
0049f789 fchs
0049f78b fmul dword ptr [0x5b2644]
0049f791 fld dword ptr [ebp + 8]
0049f794 fcomp st(1)
0049f796 fnstsw ax
0049f798 test ah, 0x41
0049f79b jne 0x49f7a2
0049f79d fstp dword ptr [ebp + 8]
0049f7a0 jmp 0x49f7a4
0049f7a2 fstp st(0)
0049f7a4 fld dword ptr [esi + 0xd60]
0049f7aa fcomp dword ptr [0x5b23f8]
0049f7b0 fnstsw ax
0049f7b2 test ah, 0x41
0049f7b5 jne 0x49f7bf
0049f7b7 fld dword ptr [ebp + 8]
0049f7ba fchs
0049f7bc fstp dword ptr [ebp + 8]
0049f7bf fld dword ptr [ebp + 8]
0049f7c2 fmul dword ptr [ebx + 0x108]
0049f7c8 push esi
0049f7c9 fstp dword ptr [ebp - 0x10]
0049f7cc call 0x4a1900
0049f7d1 lea edi, [esi + 0xd4c]
0049f7d7 xor eax, eax
0049f7d9 add esp, 4
0049f7dc mov dword ptr [edi], eax
0049f7de mov dword ptr [edi + 4], eax
0049f7e1 mov dword ptr [edi + 8], eax
0049f7e4 fld dword ptr [esi + 0x928]
0049f7ea fadd dword ptr [esi + 0x864]
0049f7f0 fld dword ptr [ebp - 4]
0049f7f3 fmul dword ptr [ebx + 0x5c]
0049f7f6 fmul dword ptr [esi + 0x864]
0049f7fc fdiv st(1)
0049f7fe fstp dword ptr [esi + 0x860]
0049f804 fld dword ptr [esi + 0x928]
0049f80a fmul dword ptr [ebx + 0x5c]
0049f80d fmul dword ptr [ebp - 4]
0049f810 fdiv st(1)
0049f812 fstp dword ptr [esi + 0x924]
0049f818 fstp st(0)
0049f81a fld dword ptr [esi + 0x9ec]
0049f820 fadd dword ptr [esi + 0xab0]
0049f826 fld dword ptr [0x5b24a8]
0049f82c fsub dword ptr [ebx + 0x5c]
0049f82f fmul dword ptr [esi + 0x9ec]
0049f835 fmul dword ptr [ebp - 4]
0049f838 fdiv st(1)
0049f83a fstp dword ptr [esi + 0x9e8]
0049f840 fld dword ptr [0x5b24a8]
0049f846 fsub dword ptr [ebx + 0x5c]
0049f849 mov dword ptr [esi + 0x874], eax
0049f84f mov dword ptr [esi + 0xac0], eax
0049f855 mov dword ptr [esi + 0x9fc], eax
0049f85b mov dword ptr [esi + 0x850], eax
0049f861 fmul dword ptr [esi + 0xab0]
0049f867 mov dword ptr [esi + 0x848], eax
0049f86d mov dword ptr [esi + 0x914], eax
0049f873 mov dword ptr [esi + 0x90c], eax
0049f879 mov dword ptr [esi + 0x9d8], eax
0049f87f fmul dword ptr [ebp - 4]
0049f882 mov dword ptr [esi + 0x9d0], eax
0049f888 mov dword ptr [esi + 0xa9c], eax
0049f88e mov dword ptr [esi + 0xa94], eax
0049f894 fdiv st(1)
0049f896 fstp dword ptr [esi + 0xaac]
0049f89c fstp st(0)
0049f89e fld dword ptr [ebp - 0x10]
0049f8a1 fmul dword ptr [0x5b23f0]
0049f8a7 fld st(0)
0049f8a9 fadd dword ptr [esi + 0x860]
0049f8af fstp dword ptr [esi + 0x860]
0049f8b5 fadd dword ptr [esi + 0x924]
0049f8bb fstp dword ptr [esi + 0x924]
0049f8c1 fld dword ptr [ebp + 8]
0049f8c4 fsub dword ptr [ebp - 0x10]
0049f8c7 fmul dword ptr [0x5b23f0]
0049f8cd fld st(0)
0049f8cf fadd dword ptr [esi + 0x9e8]
0049f8d5 fstp dword ptr [esi + 0x9e8]
0049f8db fadd dword ptr [esi + 0xaac]
0049f8e1 fstp dword ptr [esi + 0xaac]
0049f8e7 mov dword ptr [esi + 0x938], eax
0049f8ed mov ecx, dword ptr [0x628f9c]
0049f8f3 cmp ecx, eax
0049f8f5 je 0x49f917
0049f8f7 lea edx, [esi + 0x7b8]
0049f8fd push eax
0049f8fe push edx
0049f8ff push esi
0049f900 call 0x4a20d0
0049f905 lea eax, [esi + 0x87c]
0049f90b push 1
0049f90d push eax
0049f90e push esi
0049f90f call 0x4a20d0
0049f914 add esp, 0x18
0049f917 mov eax, dword ptr [0x628f98]
0049f91c test eax, eax
0049f91e je 0x49f941
0049f920 lea ecx, [esi + 0x940]
0049f926 push 2
0049f928 push ecx
0049f929 push esi
0049f92a call 0x4a20d0
0049f92f lea edx, [esi + 0xa04]
0049f935 push 3
0049f937 push edx
0049f938 push esi
0049f939 call 0x4a20d0
0049f93e add esp, 0x18
0049f941 fld dword ptr [esi + 0xa9c]
0049f947 fadd dword ptr [esi + 0x9d8]
0049f94d mov dword ptr [esi + 0xd50], 0
0049f957 lea eax, [ebp - 0x58]
0049f95a push eax
0049f95b lea eax, [esi + 0x490]
0049f961 fadd dword ptr [esi + 0x914]
0049f967 push eax
0049f968 fadd dword ptr [esi + 0x850]
0049f96e fst dword ptr [esi + 0xd54]
0049f974 fld dword ptr [esi + 0xa94]
0049f97a fadd dword ptr [esi + 0x9d0]
0049f980 fstp dword ptr [ebp + 8]
0049f983 fld dword ptr [esi + 0x90c]
0049f989 fadd dword ptr [esi + 0x848]
0049f98f fadd dword ptr [ebp + 8]
0049f992 fstp dword ptr [edi]
0049f994 fmul dword ptr [ebx + 0x1bc]
0049f99a fstp dword ptr [esi + 0xd54]
0049f9a0 fld dword ptr [esi + 0x90c]
0049f9a6 fadd dword ptr [esi + 0x848]
0049f9ac fsub dword ptr [ebp + 8]
0049f9af fmul dword ptr [ebx + 0x1b8]
0049f9b5 fld dword ptr [esi + 0x9d8]
0049f9bb fadd dword ptr [esi + 0x850]
0049f9c1 fsub dword ptr [esi + 0x914]
0049f9c7 fsub dword ptr [esi + 0xa9c]
0049f9cd fmul dword ptr [ebx + 0x1b8]
0049f9d3 mov dword ptr [ebp - 0x34], 0
0049f9da mov dword ptr [ebp - 0x2c], 0
0049f9e1 fsubp st(1)
0049f9e3 fstp dword ptr [ebp - 0x30]
0049f9e6 call 0x532a00
0049f9eb push esi
0049f9ec call 0x49f0c0
0049f9f1 lea ecx, [ebp - 0x58]
0049f9f4 push ecx
0049f9f5 push edi
0049f9f6 call 0x532910
0049f9fb fstp dword ptr [esi + 0xd40]
0049fa01 lea edx, [ebp - 0x4c]
0049fa04 push edx
0049fa05 push edi
0049fa06 call 0x532910
0049fa0b fstp dword ptr [esi + 0xd44]
0049fa11 lea eax, [ebp - 0x40]
0049fa14 push eax
0049fa15 push edi
0049fa16 call 0x532910
0049fa1b fstp dword ptr [esi + 0xd48]
0049fa21 lea ecx, [ebp - 0x58]
0049fa24 lea edx, [ebp - 0x34]
0049fa27 push ecx
0049fa28 push edx
0049fa29 call 0x532910
0049fa2e fstp dword ptr [esi + 0xd34]
0049fa34 lea eax, [ebp - 0x4c]
0049fa37 lea ecx, [ebp - 0x34]
0049fa3a push eax
0049fa3b push ecx
0049fa3c call 0x532910
0049fa41 fstp dword ptr [esi + 0xd38]
0049fa47 lea edx, [ebp - 0x40]
0049fa4a lea eax, [ebp - 0x34]
0049fa4d push edx
0049fa4e push eax
0049fa4f call 0x532910
0049fa54 fst dword ptr [esi + 0xd3c]
0049fa5a fld dword ptr [esi + 0xd40]
0049fa60 fmul dword ptr [0x5b24b8]
0049fa66 lea ebx, [esi + 0x33c]
0049fa6c add esp, 0x3c
0049fa6f fadd dword ptr [ebx]
0049fa71 fstp dword ptr [ebx]
0049fa73 fld dword ptr [esi + 0xd44]
0049fa79 fmul dword ptr [0x5b24b8]
0049fa7f lea eax, [esi + 0x388]
0049fa85 mov ecx, dword ptr [esi + 0x558]
0049fa8b mov dword ptr [ebp - 0x10], eax
0049fa8e fadd dword ptr [esi + 0x340]
0049fa94 fstp dword ptr [esi + 0x340]
0049fa9a fld dword ptr [esi + 0xd48]
0049faa0 fmul dword ptr [0x5b24b8]
0049faa6 fadd dword ptr [esi + 0x344]
0049faac fstp dword ptr [esi + 0x344]
0049fab2 fld dword ptr [esi + 0xd34]
0049fab8 fmul dword ptr [0x5b24b8]
0049fabe fadd dword ptr [eax]
0049fac0 fstp dword ptr [eax]
0049fac2 fmul dword ptr [0x5b24b8]
0049fac8 fadd dword ptr [esi + 0x390]
0049face fstp dword ptr [esi + 0x390]
0049fad4 mov eax, dword ptr [ecx + 0x518]
0049fada fld dword ptr [esi + 0xd38]
0049fae0 test eax, eax
0049fae2 je 0x49faec
0049fae4 fmul dword ptr [0x5b24b8]
0049faea jmp 0x49faf2
0049faec fmul dword ptr [0x5b4a74]
0049faf2 fadd dword ptr [esi + 0x38c]
0049faf8 fstp dword ptr [esi + 0x38c]
0049fafe fld dword ptr [edi]
0049fb00 fmul dword ptr [0x5b2468]
0049fb06 fld dword ptr [esi + 0xe08]
0049fb0c fmul dword ptr [0x5b260c]
0049fb12 faddp st(1)
0049fb14 fstp dword ptr [esi + 0xe08]
0049fb1a fld dword ptr [esi + 0xe04]
0049fb20 fmul dword ptr [0x5b25e8]
0049fb26 fld dword ptr [esi + 0xd54]
0049fb2c fmul dword ptr [0x5b2604]
0049fb32 faddp st(1)
0049fb34 fstp dword ptr [esi + 0xe04]
0049fb3a mov eax, dword ptr [0x6573f8]
0049fb3f test eax, eax
0049fb41 je 0x49fb8f
0049fb43 fld dword ptr [esi + 0xdc0]
0049fb49 fcomp dword ptr [0x5b23f8]
0049fb4f fld dword ptr [esi + 0xdc0]
0049fb55 fnstsw ax
0049fb57 test ah, 1
0049fb5a je 0x49fb5e
0049fb5c fchs
0049fb5e fcom dword ptr [0x5b2400]
0049fb64 fnstsw ax
0049fb66 test ah, 0x41
0049fb69 jne 0x49fb73
0049fb6b fstp st(0)
0049fb6d fld dword ptr [0x5b2400]
0049fb73 fmul dword ptr [0x5b4a30]
0049fb79 push ebx
0049fb7a push ecx
0049fb7b fsubr dword ptr [0x5b24a8]
0049fb81 fstp dword ptr [esp]
0049fb84 push ebx
0049fb85 push 1
0049fb87 call 0x532360
0049fb8c add esp, 0x10
0049fb8f cmp dword ptr [esi + 0x464], 3
0049fb96 jne 0x49fbc3
0049fb98 fld dword ptr [esi + 0x35c]
0049fb9e fcomp dword ptr [0x5b4a70]
0049fba4 fnstsw ax
0049fba6 test ah, 0x41
0049fba9 jne 0x49fbc3
0049fbab push ebx
0049fbac push 0x3f7eb852
0049fbb1 push ebx
0049fbb2 push 1
0049fbb4 call 0x532360
0049fbb9 add esp, 0x10
0049fbbc pop edi
0049fbbd pop esi
0049fbbe pop ebx
0049fbbf mov esp, ebp
0049fbc1 pop ebp
0049fbc2 ret
0049fbc3 mov cl, byte ptr [esi + 0xd82]
0049fbc9 cmp cl, 1
0049fbcc jle 0x49fc54
0049fbd2 fld dword ptr [0x628fb0]
0049fbd8 fcomp dword ptr [0x5b2468]
0049fbde fnstsw ax
0049fbe0 test ah, 1
0049fbe3 je 0x49fc51
0049fbe5 fld dword ptr [esi + 0x35c]
0049fbeb fcomp dword ptr [0x5b2408]
0049fbf1 fnstsw ax
0049fbf3 test ah, 1
0049fbf6 je 0x49fc51
0049fbf8 mov edx, dword ptr [esi + 0x760]
0049fbfe fld dword ptr [edx + 0xf4]
0049fc04 fcomp dword ptr [0x5b2464]
0049fc0a fnstsw ax
0049fc0c test ah, 0x41
0049fc0f jne 0x49fc51
0049fc11 fld dword ptr [esi + 0x38c]
0049fc17 fcomp dword ptr [0x5b23f8]
0049fc1d fld dword ptr [esi + 0x38c]
0049fc23 fnstsw ax
0049fc25 test ah, 1
0049fc28 je 0x49fc2c
0049fc2a fchs
0049fc2c fmul dword ptr [0x5b3f6c]
0049fc32 pop edi
0049fc33 fsubr dword ptr [0x5b24a8]
0049fc39 fld st(0)
0049fc3b fmul dword ptr [ebx]
0049fc3d fstp dword ptr [ebx]
0049fc3f fmul dword ptr [esi + 0x344]
0049fc45 fstp dword ptr [esi + 0x344]
0049fc4b pop esi
0049fc4c pop ebx
0049fc4d mov esp, ebp
0049fc4f pop ebp
0049fc50 ret
0049fc51 cmp cl, 1
0049fc54 jne 0x49fced
0049fc5a fld dword ptr [0x628fa8]
0049fc60 fcomp dword ptr [0x5b23f8]
0049fc66 fld dword ptr [0x628fa8]
0049fc6c fnstsw ax
0049fc6e test ah, 1
0049fc71 je 0x49fc75
0049fc73 fchs
0049fc75 fcomp dword ptr [0x5b23f0]
0049fc7b fnstsw ax
0049fc7d test ah, 1
0049fc80 je 0x49fced
0049fc82 fld dword ptr [esi + 0xd60]
0049fc88 fcomp dword ptr [0x5b23f8]
0049fc8e fld dword ptr [esi + 0xd60]
0049fc94 fnstsw ax
0049fc96 test ah, 1
0049fc99 je 0x49fc9d
0049fc9b fchs
0049fc9d fcomp dword ptr [0x5b2470]
0049fca3 fnstsw ax
0049fca5 test ah, 1
0049fca8 jne 0x49fcc2
0049fcaa mov esi, dword ptr [esi + 0xd94]
0049fcb0 test esi, esi
0049fcb2 jg 0x49fcb6
0049fcb4 neg esi
0049fcb6 cmp esi, 0x20
0049fcb9 mov dword ptr [ebp + 8], 0x3f7f7cee
0049fcc0 jle 0x49fcc9
0049fcc2 mov dword ptr [ebp + 8], 0x3f7d70a4
0049fcc9 mov esi, dword ptr [ebp + 8]
0049fccc push ebx
0049fccd push esi
0049fcce push ebx
0049fccf push 1
0049fcd1 call 0x532360
0049fcd6 mov eax, dword ptr [ebp - 0x10]
0049fcd9 push eax
0049fcda push esi
0049fcdb push eax
0049fcdc push 1
0049fcde call 0x532360
0049fce3 add esp, 0x20
0049fce6 pop edi
0049fce7 pop esi
0049fce8 pop ebx
0049fce9 mov esp, ebp
0049fceb pop ebp
0049fcec ret
0049fced mov al, byte ptr [esi + 0xd85]
0049fcf3 test al, al
0049fcf5 je 0x49fd1b
0049fcf7 fld dword ptr [esi + 0x35c]
0049fcfd fcomp dword ptr [0x5b24a8]
0049fd03 fnstsw ax
0049fd05 test ah, 1
0049fd08 je 0x49fd1b
0049fd0a push ebx
0049fd0b push 0x3f000000
0049fd10 push ebx
0049fd11 push 1
0049fd13 call 0x532360
0049fd18 add esp, 0x10
0049fd1b pop edi
0049fd1c pop esi
0049fd1d pop ebx
0049fd1e mov esp, ebp
0049fd20 pop ebp
0049fd21 ret
0049fd22 nop
0049fd23 nop
0049fd24 nop
0049fd25 nop
0049fd26 nop
0049fd27 nop
0049fd28 nop
0049fd29 nop
0049fd2a nop
0049fd2b nop
0049fd2c nop
0049fd2d nop
0049fd2e nop
0049fd2f nop
0049fd30 push esi
0049fd31 mov esi, dword ptr [esp + 8]
0049fd35 fld dword ptr [esi + 0x3a0]
0049fd3b fcomp dword ptr [0x5b23f0]
0049fd41 fnstsw ax
0049fd43 test ah, 1
0049fd46 je 0x49fe11
0049fd4c xor edx, edx
0049fd4e lea eax, [esi + 0x870]
0049fd54 mov dword ptr [esi + 0xdb8], edx
0049fd5a mov dword ptr [esi + 0xdc0], edx
0049fd60 mov ecx, 4
0049fd65 mov dword ptr [eax], edx
0049fd67 add eax, 0xc4
0049fd6c dec ecx
0049fd6d jne 0x49fd65
0049fd6f fld dword ptr [esi + 0xdb4]
0049fd75 fcomp dword ptr [0x5b24e0]
0049fd7b fnstsw ax
0049fd7d test ah, 0x41
0049fd80 jne 0x49fd96
0049fd82 fld dword ptr [esi + 0xdb4]
0049fd88 fsub dword ptr [0x5b24e0]
0049fd8e fstp dword ptr [esi + 0xdb4]
0049fd94 jmp 0x49fd9c
0049fd96 mov dword ptr [esi + 0xdb4], edx
0049fd9c fld dword ptr [esi + 0x424]
0049fda2 fcomp dword ptr [0x5b23f0]
0049fda8 fnstsw ax
0049fdaa test ah, 1
0049fdad je 0x49fe1a
0049fdaf lea eax, [esi + 0x33c]
0049fdb5 push eax
0049fdb6 push 0x3f733333
0049fdbb push eax
0049fdbc push 1
0049fdbe call 0x532360
0049fdc3 fld dword ptr [esi + 0x3a0]
0049fdc9 fcomp dword ptr [0x5b23f4]
0049fdcf add esp, 0x10
0049fdd2 fnstsw ax
0049fdd4 test ah, 1
0049fdd7 je 0x49fe1a
0049fdd9 fld dword ptr [esi + 0x38c]
0049fddf fmul dword ptr [0x5b25f4]
0049fde5 fstp dword ptr [esi + 0x38c]
0049fdeb fld dword ptr [esi + 0xdc4]
0049fdf1 fmul dword ptr [0x5b25f4]
0049fdf7 fstp dword ptr [esi + 0xdc4]
0049fdfd fld dword ptr [esi + 0xdc8]
0049fe03 fmul dword ptr [0x5b25f4]
0049fe09 fstp dword ptr [esi + 0xdc8]
0049fe0f pop esi
0049fe10 ret
0049fe11 push esi
0049fe12 call 0x49f160
0049fe17 add esp, 4
0049fe1a pop esi
0049fe1b ret
0049fe1c nop
0049fe1d nop
0049fe1e nop
0049fe1f nop
0049fe20 push ecx
0049fe21 mov dword ptr [esp], 0x800000
0049fe29 mov eax, dword ptr [esp]
0049fe2d mov dword ptr [0x628fbc], eax
0049fe32 pop ecx
0049fe33 ret
0049fe34 nop
0049fe35 nop
0049fe36 nop
0049fe37 nop
0049fe38 nop
0049fe39 nop
0049fe3a nop
0049fe3b nop
0049fe3c nop
0049fe3d nop
0049fe3e nop
0049fe3f nop
0049fe40 fld dword ptr [0x5b24a8]
0049fe46 fdiv dword ptr [0x628fbc]
0049fe4c fstp dword ptr [0x628fb8]
0049fe52 ret
0049fe53 nop
0049fe54 nop
0049fe55 nop
0049fe56 nop
0049fe57 nop
0049fe58 nop
0049fe59 nop
0049fe5a nop
0049fe5b nop
0049fe5c nop
0049fe5d nop
0049fe5e nop
0049fe5f nop
0049fe60 push ebp
0049fe61 mov ebp, esp
0049fe63 sub esp, 0x20
0049fe66 push ebx
0049fe67 push esi
0049fe68 mov esi, dword ptr [ebp + 8]
0049fe6b push edi
0049fe6c mov dword ptr [ebp - 0x1c], 1
0049fe73 mov dword ptr [ebp - 0x18], 2
0049fe7a mov eax, dword ptr [esi]
0049fe7c mov ecx, dword ptr [esi + 0x10]
0049fe7f mov edx, dword ptr [esi + 0x20]
0049fe82 lea edi, [esi + 0xc]
0049fe85 lea ebx, [esi + 0x18]
0049fe88 mov dword ptr [ebp + 8], eax
0049fe8b add eax, ecx
0049fe8d mov dword ptr [ebp - 0x14], 0
0049fe94 add eax, edx
0049fe96 mov dword ptr [ebp - 0x10], esi
0049fe99 test eax, eax
0049fe9b mov dword ptr [ebp - 0xc], edi
0049fe9e mov dword ptr [ebp - 8], ebx
0049fea1 jle 0x49ff18
0049fea3 add eax, 0x10000
0049fea8 push eax
0049fea9 call 0x5624b0
0049feae mov dword ptr [ebp + 8], eax
0049feb1 mov ecx, eax
0049feb3 mov eax, 0x80000000
0049feb8 xor edx, edx
0049feba div dword ptr [ebp + 8]
0049febd mov edx, dword ptr [ebx + 4]
0049fec0 add esp, 4
0049fec3 sar ecx, 1
0049fec5 mov dword ptr [ebp + 8], eax
0049fec8 mov eax, dword ptr [edi + 8]
0049fecb sub eax, edx
0049fecd mov dword ptr [ebp - 4], eax
0049fed0 mov eax, dword ptr [ebp - 4]
0049fed3 imul dword ptr [ebp + 8]
0049fed6 shl edx, 0x10
0049fed9 shr eax, 0x10
0049fedc adc eax, edx
0049fede mov edx, dword ptr [ebx]
0049fee0 mov ebx, dword ptr [esi + 8]
0049fee3 sub edx, ebx
0049fee5 mov dword ptr [ebp - 0x20], eax
0049fee8 mov dword ptr [ebp - 4], edx
0049feeb mov eax, dword ptr [ebp - 4]
0049feee imul dword ptr [ebp + 8]
0049fef1 shl edx, 0x10
0049fef4 shr eax, 0x10
0049fef7 adc eax, edx
0049fef9 mov edx, dword ptr [edi]
0049fefb mov ebx, eax
0049fefd mov eax, dword ptr [esi + 4]
0049ff00 sub eax, edx
0049ff02 mov dword ptr [ebp - 4], eax
0049ff05 mov eax, dword ptr [ebp - 4]
0049ff08 imul dword ptr [ebp + 8]
0049ff0b shl edx, 0x10
0049ff0e shr eax, 0x10
0049ff11 adc eax, edx
0049ff13 jmp 0x49fff0
0049ff18 mov eax, dword ptr [ebp + 8]
0049ff1b xor edi, edi
0049ff1d cmp ecx, eax
0049ff1f jle 0x49ff26
0049ff21 mov edi, 1
0049ff26 mov ecx, dword ptr [ebp + edi*4 - 0x10]
0049ff2a cmp edx, dword ptr [ecx + edi*4]
0049ff2d jle 0x49ff34
0049ff2f mov edi, 2
0049ff34 mov esi, dword ptr [ebp + edi*4 - 0x1c]
0049ff38 mov ecx, dword ptr [ebp + edi*4 - 0x10]
0049ff3c mov ebx, dword ptr [ebp + esi*4 - 0x1c]
0049ff40 mov edx, dword ptr [ebp + esi*4 - 0x10]
0049ff44 mov ecx, dword ptr [ecx + edi*4]
0049ff47 mov eax, dword ptr [ebp + ebx*4 - 0x10]
0049ff4b sub ecx, dword ptr [eax + ebx*4]
0049ff4e mov eax, dword ptr [edx + esi*4]
0049ff51 sub ecx, eax
0049ff53 add ecx, 0x10000
0049ff59 push ecx
0049ff5a call 0x5624b0
0049ff5f mov ecx, eax
0049ff61 add esp, 4
0049ff64 mov edx, ecx
0049ff66 mov dword ptr [ebp + 8], ecx
0049ff69 sar edx, 1
0049ff6b test ecx, ecx
0049ff6d mov dword ptr [ebp + edi*4 - 0x20], edx
0049ff71 je 0x49ff7f
0049ff73 mov eax, 0x80000000
0049ff78 xor edx, edx
0049ff7a div ecx
0049ff7c mov dword ptr [ebp + 8], eax
0049ff7f mov eax, dword ptr [ebp + esi*4 - 0x10]
0049ff83 mov ecx, dword ptr [ebp + ebx*4 - 0x10]
0049ff87 mov eax, dword ptr [eax + ebx*4]
0049ff8a mov edx, dword ptr [ecx + esi*4]
0049ff8d sub eax, edx
0049ff8f mov dword ptr [ebp - 4], eax
0049ff92 mov eax, dword ptr [ebp - 4]
0049ff95 imul dword ptr [ebp + 8]
0049ff98 shl edx, 0x10
0049ff9b shr eax, 0x10
0049ff9e adc eax, edx
0049ffa0 mov dword ptr [ebp - 0x14], eax
0049ffa3 mov eax, dword ptr [ebp + esi*4 - 0x10]
0049ffa7 mov edx, dword ptr [eax + edi*4]
0049ffaa mov eax, dword ptr [ebp + edi*4 - 0x10]
0049ffae add edx, dword ptr [eax + esi*4]
0049ffb1 mov dword ptr [ebp - 4], edx
0049ffb4 mov eax, dword ptr [ebp - 4]
0049ffb7 imul dword ptr [ebp + 8]
0049ffba shl edx, 0x10
0049ffbd shr eax, 0x10
0049ffc0 adc eax, edx
0049ffc2 mov edx, dword ptr [ecx + edi*4]
0049ffc5 mov dword ptr [ebp + esi*4 - 0x20], eax
0049ffc9 mov eax, dword ptr [ebp + edi*4 - 0x10]
0049ffcd mov eax, dword ptr [eax + ebx*4]
0049ffd0 add eax, edx
0049ffd2 mov dword ptr [ebp - 4], eax
0049ffd5 mov eax, dword ptr [ebp - 4]
0049ffd8 imul dword ptr [ebp + 8]
0049ffdb shl edx, 0x10
0049ffde shr eax, 0x10
0049ffe1 adc eax, edx
0049ffe3 mov dword ptr [ebp + ebx*4 - 0x20], eax
0049ffe7 mov eax, dword ptr [ebp - 0x18]
0049ffea mov ebx, dword ptr [ebp - 0x1c]
0049ffed mov ecx, dword ptr [ebp - 0x14]
0049fff0 mov esi, dword ptr [ebp - 0x20]
0049fff3 mov edx, dword ptr [ebp + 0xc]
0049fff6 sar esi, 2
0049fff9 sar ebx, 2
0049fffc sar eax, 2
0049ffff mov word ptr [edx], si
004a0002 pop edi
004a0003 sar ecx, 2
004a0006 mov word ptr [edx + 2], bx
004a000a pop esi
004a000b mov word ptr [edx + 4], ax
004a000f mov word ptr [edx + 6], cx
004a0013 pop ebx
004a0014 mov esp, ebp
004a0016 pop ebp
004a0017 ret
004a0018 nop
004a0019 nop
004a001a nop
004a001b nop
004a001c nop
004a001d nop
004a001e nop
004a001f nop
004a0020 sub esp, 0x10
004a0023 mov ecx, dword ptr [esp + 0x14]
004a0027 push ebx
004a0028 push ebp
004a0029 push esi
004a002a movsx eax, word ptr [ecx]
004a002d movsx edx, word ptr [ecx + 2]
004a0031 push edi
004a0032 lea ebp, [eax + eax]
004a0035 movsx edi, word ptr [ecx + 4]
004a0039 movsx ecx, word ptr [ecx + 6]
004a003d mov esi, ecx
004a003f lea ebx, [edi + edi]
004a0042 imul esi, ebp
004a0045 imul edi, ebx
004a0048 mov ebp, ecx
004a004a imul ecx, ebx
004a004d mov dword ptr [esp + 0x18], esi
004a0051 lea esi, [edx + edx]
004a0054 imul ebp, esi
004a0057 mov dword ptr [esp + 0x10], ecx
004a005b mov ecx, eax
004a005d lea esi, [eax + eax]
004a0060 imul ecx, esi
004a0063 mov dword ptr [esp + 0x14], ecx
004a0067 mov ecx, eax
004a0069 imul eax, ebx
004a006c mov dword ptr [esp + 0x24], eax
004a0070 lea esi, [edx + edx]
004a0073 mov eax, edx
004a0075 imul edx, ebx
004a0078 imul eax, esi
004a007b imul ecx, esi
004a007e mov esi, edx
004a0080 mov edx, 0x10000000
004a0085 sub edx, edi
004a0087 mov dword ptr [esp + 0x1c], eax
004a008b mov edi, edx
004a008d sub edi, eax
004a008f mov eax, dword ptr [esp + 0x28]
004a0093 sar edi, 0xc
004a0096 mov dword ptr [eax], edi
004a0098 mov edi, dword ptr [esp + 0x10]
004a009c lea ebx, [ecx + edi]
004a009f sub ecx, edi
004a00a1 sar ecx, 0xc
004a00a4 mov dword ptr [eax + 0xc], ecx
004a00a7 mov ecx, dword ptr [esp + 0x14]
004a00ab sub edx, ecx
004a00ad sar edx, 0xc
004a00b0 mov dword ptr [eax + 0x10], edx
004a00b3 mov edx, dword ptr [esp + 0x18]
004a00b7 sar ebx, 0xc
004a00ba lea edi, [esi + edx]
004a00bd sub esi, edx
004a00bf sar edi, 0xc
004a00c2 mov dword ptr [eax + 0x14], edi
004a00c5 mov edi, dword ptr [esp + 0x24]
004a00c9 add edi, ebp
004a00cb mov dword ptr [eax + 4], ebx
004a00ce mov ebx, dword ptr [esp + 0x24]
004a00d2 mov edx, 0x10000000
004a00d7 sar edi, 0xc
004a00da mov dword ptr [eax + 0x18], edi
004a00dd mov edi, dword ptr [esp + 0x1c]
004a00e1 sub edx, edi
004a00e3 sub ebx, ebp
004a00e5 sar esi, 0xc
004a00e8 sub edx, ecx
004a00ea mov dword ptr [eax + 0x1c], esi
004a00ed sar ebx, 0xc
004a00f0 pop edi
004a00f1 pop esi
004a00f2 sar edx, 0xc
004a00f5 mov dword ptr [eax + 8], ebx
004a00f8 pop ebp
004a00f9 mov dword ptr [eax + 0x20], edx
004a00fc pop ebx
004a00fd add esp, 0x10
004a0100 ret
004a0101 nop
004a0102 nop
004a0103 nop
004a0104 nop
004a0105 nop
004a0106 nop
004a0107 nop
004a0108 nop
004a0109 nop
004a010a nop
004a010b nop
004a010c nop
004a010d nop
004a010e nop
004a010f nop
004a0110 push ebp
004a0111 mov ebp, esp
004a0113 sub esp, 0x24
004a0116 mov eax, dword ptr [0x606ac4]
004a011b push esi
004a011c mov esi, dword ptr [ebp + 0xc]
004a011f push edi
004a0120 mov edi, dword ptr [ebp + 8]
004a0123 lea ecx, [esi + 0x330]
004a0129 mov dword ptr [edi + 4], eax
004a012c lea edx, [edi + 0x18]
004a012f mov eax, dword ptr [ecx]
004a0131 mov dword ptr [edx], eax
004a0133 mov eax, dword ptr [ecx + 4]
004a0136 mov dword ptr [edx + 4], eax
004a0139 mov ecx, dword ptr [ecx + 8]
004a013c mov dword ptr [edx + 8], ecx
004a013f mov dl, byte ptr [esi + 0xd80]
004a0145 mov byte ptr [edi + 2], dl
004a0148 mov al, byte ptr [esi + 0xd94]
004a014e mov byte ptr [edi], al
004a0150 mov cl, byte ptr [esi + 0xd8a]
004a0156 mov byte ptr [edi + 3], cl
004a0159 fld dword ptr [esi + 0x424]
004a015f fcomp dword ptr [0x5b23f0]
004a0165 fnstsw ax
004a0167 test ah, 0x41
004a016a jne 0x4a0172
004a016c mov byte ptr [edi + 1], 1
004a0170 jmp 0x4a0176
004a0172 mov byte ptr [edi + 1], 0
004a0176 push ebx
004a0177 lea ecx, [ebp - 0x24]
004a017a lea eax, [esi + 0x364]
004a0180 mov edx, 9
004a0185 fld dword ptr [eax]
004a0187 fmul dword ptr [0x5b3e68]
004a018d fstp dword ptr [ebp + 8]
004a0190 fld dword ptr [ebp + 8]
004a0193 fistp dword ptr [ebp + 0xc]
004a0196 mov ebx, dword ptr [ebp + 0xc]
004a0199 add eax, 4
004a019c mov dword ptr [ecx], ebx
004a019e add ecx, 4
004a01a1 dec edx
004a01a2 jne 0x4a0185
004a01a4 lea edx, [edi + 0xa]
004a01a7 lea eax, [ebp - 0x24]
004a01aa push edx
004a01ab push eax
004a01ac call 0x49fe60
004a01b1 fld dword ptr [esi + 0x38c]
004a01b7 fmul dword ptr [0x5b2428]
004a01bd add esp, 8
004a01c0 fcom dword ptr [0x5b23f8]
004a01c6 pop ebx
004a01c7 fnstsw ax
004a01c9 test ah, 1
004a01cc jne 0x4a01d6
004a01ce fld dword ptr [0x5b23f0]
004a01d4 jmp 0x4a01dc
004a01d6 fld dword ptr [0x5b2448]
004a01dc fxch st(1)
004a01de fadd st(1)
004a01e0 call 0x5a0f98
004a01e5 fstp st(0)
004a01e7 mov word ptr [edi + 8], ax
004a01eb fld dword ptr [esi + 0x33c]
004a01f1 fmul dword ptr [0x5b242c]
004a01f7 fcom dword ptr [0x5b23f8]
004a01fd fnstsw ax
004a01ff test ah, 1
004a0202 jne 0x4a020c
004a0204 fld dword ptr [0x5b23f0]
004a020a jmp 0x4a0212
004a020c fld dword ptr [0x5b2448]
004a0212 fxch st(1)
004a0214 fadd st(1)
004a0216 call 0x5a0f98
004a021b fstp st(0)
004a021d mov word ptr [edi + 0x12], ax
004a0221 fld dword ptr [esi + 0x340]
004a0227 fmul dword ptr [0x5b242c]
004a022d fcom dword ptr [0x5b23f8]
004a0233 fnstsw ax
004a0235 test ah, 1
004a0238 jne 0x4a0242
004a023a fld dword ptr [0x5b23f0]
004a0240 jmp 0x4a0248
004a0242 fld dword ptr [0x5b2448]
004a0248 fxch st(1)
004a024a fadd st(1)
004a024c call 0x5a0f98
004a0251 fstp st(0)
004a0253 mov word ptr [edi + 0x14], ax
004a0257 fld dword ptr [esi + 0x344]
004a025d fmul dword ptr [0x5b242c]
004a0263 fcom dword ptr [0x5b23f8]
004a0269 fnstsw ax
004a026b test ah, 1
004a026e jne 0x4a0278
004a0270 fld dword ptr [0x5b23f0]
004a0276 jmp 0x4a027e
004a0278 fld dword ptr [0x5b2448]
004a027e fxch st(1)
004a0280 fadd st(1)
004a0282 call 0x5a0f98
004a0287 mov word ptr [edi + 0x16], ax
004a028b pop edi
004a028c fstp st(0)
004a028e pop esi
004a028f mov esp, ebp
004a0291 pop ebp
004a0292 ret
004a0293 nop
004a0294 nop
004a0295 nop
004a0296 nop
004a0297 nop
004a0298 nop
004a0299 nop
004a029a nop
004a029b nop
004a029c nop
004a029d nop
004a029e nop
004a029f nop
004a02a0 sub esp, 0xc
004a02a3 push ebx
004a02a4 push ebp
004a02a5 push esi
004a02a6 mov esi, dword ptr [esp + 0x1c]
004a02aa push edi
004a02ab push esi
004a02ac call 0x49af70
004a02b1 lea edi, [esi + 0x370]
004a02b7 lea eax, [esi + 0x3e8]
004a02bd mov ecx, edi
004a02bf lea ebx, [esi + 0x364]
004a02c5 mov edx, dword ptr [eax]
004a02c7 lea ebp, [esi + 0x37c]
004a02cd mov dword ptr [ecx], edx
004a02cf push ebx
004a02d0 mov edx, dword ptr [eax + 4]
004a02d3 push ebp
004a02d4 mov dword ptr [ecx + 4], edx
004a02d7 push edi
004a02d8 mov eax, dword ptr [eax + 8]
004a02db mov dword ptr [ecx + 8], eax
004a02de call 0x532880
004a02e3 push ebp
004a02e4 push edi
004a02e5 push ebx
004a02e6 call 0x532880
004a02eb push ebx
004a02ec call 0x4a4810
004a02f1 fld dword ptr [esi + 0x33c]
004a02f7 fcomp dword ptr [0x5b23f8]
004a02fd fld dword ptr [esi + 0x33c]
004a0303 add esp, 0x20
004a0306 mov byte ptr [esi + 0x80], 0x20
004a030d fnstsw ax
004a030f test ah, 1
004a0312 je 0x4a0316
004a0314 fchs
004a0316 fld dword ptr [esi + 0x344]
004a031c fcomp dword ptr [0x5b23f8]
004a0322 fld dword ptr [esi + 0x344]
004a0328 fnstsw ax
004a032a test ah, 1
004a032d je 0x4a0331
004a032f fchs
004a0331 fld st(1)
004a0333 fcomp st(1)
004a0335 fnstsw ax
004a0337 test ah, 0x41
004a033a jne 0x4a0346
004a033c fmul dword ptr [0x5b2468]
004a0342 faddp st(1)
004a0344 jmp 0x4a0354
004a0346 fxch st(1)
004a0348 fmul dword ptr [0x5b2468]
004a034e fadd st(1)
004a0350 fxch st(1)
004a0352 fstp st(0)
004a0354 fstp dword ptr [esi + 0x35c]
004a035a lea ecx, [esp + 0x10]
004a035e push ecx
004a035f push esi
004a0360 call 0x499a70
004a0365 fstp dword ptr [esi + 0x41c]
004a036b fld dword ptr [esi + 0x334]
004a0371 fsub dword ptr [esi + 0x424]
004a0377 add esp, 8
004a037a xor edx, edx
004a037c mov dword ptr [esi + 0x424], edx
004a0382 lea eax, [esi + 0x820]
004a0388 mov ecx, 4
004a038d fstp dword ptr [esi + 0x334]
004a0393 mov dword ptr [eax + 0x1c], edx
004a0396 mov dword ptr [eax], edx
004a0398 mov dword ptr [eax + 8], edx
004a039b add eax, 0xc4
004a03a0 dec ecx
004a03a1 jne 0x4a0393
004a03a3 mov dword ptr [esi + 0xe94], edx
004a03a9 push esi
004a03aa mov dword ptr [esi + 0xc], 0xffffffff
004a03b1 call 0x49ae30
004a03b6 add esp, 4
004a03b9 pop edi
004a03ba pop esi
004a03bb pop ebp
004a03bc pop ebx
004a03bd add esp, 0xc
004a03c0 ret
004a03c1 nop
004a03c2 nop
004a03c3 nop
004a03c4 nop
004a03c5 nop
004a03c6 nop
004a03c7 nop
004a03c8 nop
004a03c9 nop
004a03ca nop
004a03cb nop
004a03cc nop
004a03cd nop
004a03ce nop
004a03cf nop
004a03d0 sub esp, 0x24
004a03d3 push esi
004a03d4 mov esi, dword ptr [esp + 0x2c]
004a03d8 push edi
004a03d9 mov eax, dword ptr [esi + 0x74]
004a03dc mov dword ptr [esi + 0xdac], 1
004a03e6 push eax
004a03e7 call 0x5322b0
004a03ec movsx ecx, word ptr [esi + 0x4a]
004a03f0 mov dword ptr [esp + 0x34], ecx
004a03f4 lea ecx, [esp + 0xc]
004a03f8 fild dword ptr [esp + 0x34]
004a03fc movsx edx, word ptr [esi + 0x4c]
004a0400 fmul dword ptr [0x5b3ca0]
004a0406 mov dword ptr [esp + 0x34], edx
004a040a lea edx, [esi + 0x42]
004a040d movsx eax, word ptr [esi + 0x4e]
004a0411 fstp dword ptr [esi + 0x33c]
004a0417 fild dword ptr [esp + 0x34]
004a041b mov dword ptr [esp + 0x34], eax
004a041f push ecx
004a0420 push edx
004a0421 fmul dword ptr [0x5b3ca0]
004a0427 fstp dword ptr [esi + 0x340]
004a042d fild dword ptr [esp + 0x3c]
004a0431 fmul dword ptr [0x5b3ca0]
004a0437 fstp dword ptr [esi + 0x344]
004a043d call 0x4a0020
004a0442 lea edi, [esi + 0x364]
004a0448 add esp, 0xc
004a044b lea eax, [esp + 8]
004a044f mov ecx, edi
004a0451 mov edx, 9
004a0456 fild dword ptr [eax]
004a0458 add eax, 4
004a045b add ecx, 4
004a045e dec edx
004a045f fmul dword ptr [0x5b253c]
004a0465 fstp dword ptr [ecx - 4]
004a0468 jne 0x4a0456
004a046a push edi
004a046b call 0x4a4810
004a0470 mov eax, dword ptr [esi + 0x74]
004a0473 push eax
004a0474 call 0x5322c0
004a0479 push esi
004a047a call 0x49af70
004a047f mov dword ptr [esi + 0xe94], 0
004a0489 push esi
004a048a mov dword ptr [esi + 0xc], 0xffffffff
004a0491 call 0x49ae30
004a0496 add esp, 0x10
004a0499 pop edi
004a049a pop esi
004a049b add esp, 0x24
004a049e ret
004a049f nop
004a04a0 sub esp, 0xc
004a04a3 mov ecx, dword ptr [esp + 0x18]
004a04a7 push ebx
004a04a8 mov ebx, dword ptr [esp + 0x14]
004a04ac push ebp
004a04ad push esi
004a04ae lea eax, [esp + 0xc]
004a04b2 push edi
004a04b3 lea ebp, [ebx + 0x330]
004a04b9 push eax
004a04ba push ebp
004a04bb push ecx
004a04bc push 1
004a04be call 0x532330
004a04c3 lea edx, [esp + 0x20]
004a04c7 push edx
004a04c8 call 0x532b20
004a04cd fst dword ptr [esp + 0x34]
004a04d1 fcomp dword ptr [0x5b2470]
004a04d7 add esp, 0x14
004a04da fnstsw ax
004a04dc test ah, 0x41
004a04df jne 0x4a054a
004a04e1 mov ecx, dword ptr [esp + 0x24]
004a04e5 xor eax, eax
004a04e7 mov dword ptr [ebx + 0x388], eax
004a04ed mov dword ptr [ebx + 0x390], eax
004a04f3 mov eax, dword ptr [esp + 0x2c]
004a04f7 mov dword ptr [ebx + 0x38c], ecx
004a04fd lea edx, [ebx + 0x33c]
004a0503 mov esi, dword ptr [esp + 0x30]
004a0507 mov ecx, dword ptr [eax]
004a0509 lea edi, [ebx + 0x364]
004a050f mov dword ptr [edx], ecx
004a0511 push ebx
004a0512 mov ecx, dword ptr [eax + 4]
004a0515 mov dword ptr [edx + 4], ecx
004a0518 mov ecx, 9
004a051d mov eax, dword ptr [eax + 8]
004a0520 mov dword ptr [edx + 8], eax
004a0523 mov eax, dword ptr [esp + 0x2c]
004a0527 rep movsd dword ptr es:[edi], dword ptr [esi]
004a0529 mov ecx, dword ptr [eax]
004a052b mov dword ptr [ebp], ecx
004a052e mov edx, dword ptr [eax + 4]
004a0531 mov dword ptr [ebp + 4], edx
004a0534 mov eax, dword ptr [eax + 8]
004a0537 mov dword ptr [ebp + 8], eax
004a053a call 0x4a02a0
004a053f add esp, 4
004a0542 pop edi
004a0543 pop esi
004a0544 pop ebp
004a0545 pop ebx
004a0546 add esp, 0xc
004a0549 ret
004a054a fld dword ptr [esp + 0x20]
004a054e fcomp dword ptr [0x5b2460]
004a0554 mov dword ptr [esp + 0x28], 0x3da3d70a
004a055c fnstsw ax
004a055e test ah, 0x41
004a0561 jne 0x4a0571
004a0563 fld dword ptr [esp + 0x20]
004a0567 fmul dword ptr [0x5b4a8c]
004a056d fstp dword ptr [esp + 0x28]
004a0571 mov ecx, dword ptr [esp + 0x2c]
004a0575 fld dword ptr [ecx]
004a0577 fcomp dword ptr [0x5b23f8]
004a057d fld dword ptr [ecx]
004a057f fnstsw ax
004a0581 test ah, 1
004a0584 je 0x4a0588
004a0586 fchs
004a0588 fld dword ptr [ecx + 8]
004a058b fcomp dword ptr [0x5b23f8]
004a0591 fld dword ptr [ecx + 8]
004a0594 fnstsw ax
004a0596 test ah, 1
004a0599 je 0x4a059d
004a059b fchs
004a059d fld st(1)
004a059f fcomp st(1)
004a05a1 fnstsw ax
004a05a3 test ah, 0x41
004a05a6 jne 0x4a05b2
004a05a8 fmul dword ptr [0x5b2468]
004a05ae faddp st(1)
004a05b0 jmp 0x4a05c0
004a05b2 fxch st(1)
004a05b4 fmul dword ptr [0x5b2468]
004a05ba fadd st(1)
004a05bc fxch st(1)
004a05be fstp st(0)
004a05c0 mov edx, dword ptr [esp + 0x28]
004a05c4 lea ecx, [esp + 0x10]
004a05c8 fstp dword ptr [ebx + 0x35c]
004a05ce push ecx
004a05cf lea eax, [esp + 0x14]
004a05d3 push edx
004a05d4 push eax
004a05d5 push 1
004a05d7 call 0x532360
004a05dc lea ecx, [esp + 0x20]
004a05e0 push ebp
004a05e1 push ecx
004a05e2 push ebp
004a05e3 push 1
004a05e5 call 0x532300
004a05ea mov esi, dword ptr [esp + 0x50]
004a05ee lea eax, [ebx + 0x37c]
004a05f4 lea edx, [esi + 0x18]
004a05f7 push edx
004a05f8 push eax
004a05f9 call 0x532910
004a05fe fcomp dword ptr [0x5b23f8]
004a0604 add esp, 0x28
004a0607 fnstsw ax
004a0609 test ah, 1
004a060c je 0x4a062c
004a060e lea edx, [ebx + 0x364]
004a0614 mov eax, esi
004a0616 mov ecx, edx
004a0618 mov esi, 9
004a061d mov edi, dword ptr [eax]
004a061f add eax, 4
004a0622 mov dword ptr [ecx], edi
004a0624 add ecx, 4
004a0627 dec esi
004a0628 jne 0x4a061d
004a062a jmp 0x4a0659
004a062c lea edx, [ebx + 0x364]
004a0632 mov ecx, esi
004a0634 mov eax, edx
004a0636 mov esi, 9
004a063b fld dword ptr [eax]
004a063d fmul dword ptr [0x5b4a88]
004a0643 fld dword ptr [ecx]
004a0645 fmul dword ptr [0x5b23f4]
004a064b add ecx, 4
004a064e add eax, 4
004a0651 dec esi
004a0652 faddp st(1)
004a0654 fstp dword ptr [eax - 4]
004a0657 jne 0x4a063b
004a0659 push edx
004a065a call 0x4a4810
004a065f add esp, 4
004a0662 mov byte ptr [ebx + 0x80], 0x20
004a0669 pop edi
004a066a pop esi
004a066b pop ebp
004a066c pop ebx
004a066d add esp, 0xc
004a0670 ret
004a0671 nop
004a0672 nop
004a0673 nop
004a0674 nop
004a0675 nop
004a0676 nop
004a0677 nop
004a0678 nop
004a0679 nop
004a067a nop
004a067b nop
004a067c nop
004a067d nop
004a067e nop
004a067f nop
004a0680 push ebp
004a0681 mov ebp, esp
004a0683 sub esp, 0x60
004a0686 push ebx
004a0687 mov ebx, dword ptr [ebp + 8]
004a068a mov eax, dword ptr [ebx + 0x3c]
004a068d test eax, eax
004a068f je 0x4a0a2d
004a0695 mov eax, dword ptr [ebx + 0x74]
004a0698 push esi
004a0699 push edi
004a069a push eax
004a069b call 0x5322b0
004a06a0 movsx edx, word ptr [ebx + 0x4a]
004a06a4 mov dword ptr [ebp + 8], edx
004a06a7 mov ecx, dword ptr [0x606ac4]
004a06ad fild dword ptr [ebp + 8]
004a06b0 movsx eax, word ptr [ebx + 0x4c]
004a06b4 fmul dword ptr [0x5b3ca0]
004a06ba mov edi, dword ptr [ebx + 0x3c]
004a06bd mov dword ptr [ebp + 8], eax
004a06c0 sub ecx, edi
004a06c2 mov esi, dword ptr [ebx + 0x6c]
004a06c5 mov dword ptr [ebp - 8], ecx
004a06c8 lea edx, [ebx + 0x50]
004a06cb fstp dword ptr [ebp - 0x30]
004a06ce fild dword ptr [ebp + 8]
004a06d1 movsx ecx, word ptr [ebx + 0x4e]
004a06d5 fmul dword ptr [0x5b3ca0]
004a06db mov eax, dword ptr [edx]
004a06dd mov dword ptr [ebp + 8], ecx
004a06e0 mov dword ptr [ebp - 0x18], eax
004a06e3 mov eax, dword ptr [ebx + 0x74]
004a06e6 mov ecx, dword ptr [edx + 4]
004a06e9 inc esi
004a06ea fstp dword ptr [ebp - 0x2c]
004a06ed fild dword ptr [ebp + 8]
004a06f0 mov edx, dword ptr [edx + 8]
004a06f3 push eax
004a06f4 mov dword ptr [ebp - 0x14], ecx
004a06f7 mov dword ptr [ebp - 0x10], edx
004a06fa fmul dword ptr [0x5b3ca0]
004a0700 mov dword ptr [ebx + 0x6c], esi
004a0703 fstp dword ptr [ebp - 0x28]
004a0706 call 0x5322c0
004a070b lea esi, [ebx + 8]
004a070e mov ecx, 0xc
004a0713 lea edi, [ebp - 0x60]
004a0716 add esp, 8
004a0719 rep movsd dword ptr es:[edi], dword ptr [esi]
004a071b lea ecx, [ebp - 0x18]
004a071e push ecx
004a071f lea ecx, [ebp - 0x60]
004a0722 call 0x474440
004a0727 lea edx, [ebp - 0x18]
004a072a push 1
004a072c push edx
004a072d lea ecx, [ebp - 0x60]
004a0730 call 0x474060
004a0735 movsx edi, word ptr [ebp - 0x60]
004a0739 mov esi, dword ptr [0x628bc0]
004a073f mov dword ptr [ebp + 8], edi
004a0742 lea edi, [edi + edi*4]
004a0745 mov eax, dword ptr [esi + 0xc]
004a0748 shl edi, 4
004a074b lea ecx, [edi + eax + 0x1c]
004a074f mov edx, dword ptr [edi + eax + 0x1c]
004a0753 mov dword ptr [ebp - 0x24], edx
004a0756 lea edx, [ebp - 0x30]
004a0759 mov eax, dword ptr [ecx + 4]
004a075c push edx
004a075d mov dword ptr [ebp - 0x20], eax
004a0760 lea eax, [ebp - 0x24]
004a0763 mov ecx, dword ptr [ecx + 8]
004a0766 push eax
004a0767 mov dword ptr [ebp - 0x1c], ecx
004a076a call 0x532910
004a076f mov ecx, dword ptr [0x628bc0]
004a0775 mov eax, dword ptr [ebp + 8]
004a0778 fstp dword ptr [ebp - 4]
004a077b mov edx, dword ptr [ecx + 4]
004a077e push eax
004a077f mov dword ptr [ebp - 0xc], edx
004a0782 call 0x416290
004a0787 fld dword ptr [ebp - 4]
004a078a add esp, 0xc
004a078d fmul dword ptr [0x5b2828]
004a0793 fimul dword ptr [ebp - 8]
004a0796 mov ecx, dword ptr [0x628bc0]
004a079c fild dword ptr [ebp - 0xc]
004a079f fmul dword ptr [0x5b2460]
004a07a5 fdivp st(1)
004a07a7 faddp st(1)
004a07a9 fsub dword ptr [ebx + 0xaf8]
004a07af fild dword ptr [ecx + 4]
004a07b2 fmul dword ptr [0x5b2460]
004a07b8 fmulp st(1)
004a07ba fcom dword ptr [0x5b23f8]
004a07c0 fld st(0)
004a07c2 fnstsw ax
004a07c4 test ah, 1
004a07c7 je 0x4a07cb
004a07c9 fchs
004a07cb fcomp dword ptr [0x5b4a60]
004a07d1 fnstsw ax
004a07d3 test ah, 0x41
004a07d6 jne 0x4a0882
004a07dc fmul dword ptr [0x5b49d4]
004a07e2 fstp dword ptr [ebp - 0xc]
004a07e5 fld dword ptr [ebp - 0xc]
004a07e8 fistp dword ptr [ebp - 8]
004a07eb mov edx, dword ptr [ebp - 8]
004a07ee mov eax, dword ptr [ebp + 8]
004a07f1 push -1
004a07f3 push edx
004a07f4 push eax
004a07f5 mov ecx, esi
004a07f7 call 0x4817d0
004a07fc mov edx, dword ptr [ebp - 4]
004a07ff xor ecx, ecx
004a0801 lea edi, [eax + eax*4]
004a0804 mov dword ptr [ebx + 0x388], ecx
004a080a mov dword ptr [ebx + 0x38c], ecx
004a0810 mov dword ptr [ebx + 0x390], ecx
004a0816 mov eax, dword ptr [esi + 0xc]
004a0819 lea ecx, [ebx + 0x33c]
004a081f shl edi, 4
004a0822 push ecx
004a0823 push edx
004a0824 lea ecx, [edi + eax + 0x1c]
004a0828 push ecx
004a0829 push 1
004a082b call 0x532360
004a0830 mov edx, dword ptr [esi + 0xc]
004a0833 lea ecx, [ebx + 0x37c]
004a0839 push ebx
004a083a lea eax, [edi + edx + 0x1c]
004a083e mov edx, dword ptr [edi + edx + 0x1c]
004a0842 mov dword ptr [ecx], edx
004a0844 mov edx, dword ptr [eax + 4]
004a0847 mov dword ptr [ecx + 4], edx
004a084a mov edx, dword ptr [ebp - 0x18]
004a084d mov eax, dword ptr [eax + 8]
004a0850 mov dword ptr [ecx + 8], eax
004a0853 mov eax, dword ptr [ebp - 0x14]
004a0856 lea ecx, [ebx + 0x330]
004a085c mov dword ptr [ebx + 0x330], edx
004a0862 mov edx, dword ptr [ebp - 0x10]
004a0865 mov dword ptr [ecx + 4], eax
004a0868 mov dword ptr [ecx + 8], edx
004a086b call 0x4a02a0
004a0870 add esp, 0x14
004a0873 lea ecx, [ebp - 0x60]
004a0876 call 0x516950
004a087b pop edi
004a087c pop esi
004a087d pop ebx
004a087e mov esp, ebp
004a0880 pop ebp
004a0881 ret
004a0882 fchs
004a0884 fst dword ptr [ebp + 8]
004a0887 fcomp dword ptr [0x5b23f8]
004a088d fnstsw ax
004a088f test ah, 0x41
004a0892 jne 0x4a0a23
004a0898 movsx eax, word ptr [ebx + 8]
004a089c mov ecx, dword ptr [esi + 0xc]
004a089f lea eax, [eax + eax*4]
004a08a2 shl eax, 4
004a08a5 lea edx, [eax + ecx + 0x1c]
004a08a9 mov eax, dword ptr [eax + ecx + 0x1c]
004a08ad mov dword ptr [ebp - 0x24], eax
004a08b0 lea eax, [ebx + 0x33c]
004a08b6 mov ecx, dword ptr [edx + 4]
004a08b9 push eax
004a08ba mov dword ptr [ebp - 0x20], ecx
004a08bd lea eax, [ebp - 0x24]
004a08c0 mov edx, dword ptr [edx + 8]
004a08c3 push eax
004a08c4 mov dword ptr [ebp - 0x1c], edx
004a08c7 call 0x532910
004a08cc fld dword ptr [ebp - 4]
004a08cf fsub st(1)
004a08d1 add esp, 8
004a08d4 fcom dword ptr [0x5b23f8]
004a08da fst dword ptr [ebp - 8]
004a08dd fnstsw ax
004a08df test ah, 1
004a08e2 je 0x4a08e6
004a08e4 fchs
004a08e6 fcomp dword ptr [0x5b24a8]
004a08ec fnstsw ax
004a08ee test ah, 1
004a08f1 je 0x4a09ab
004a08f7 fcom dword ptr [0x5b23f8]
004a08fd fnstsw ax
004a08ff test ah, 1
004a0902 je 0x4a0906
004a0904 fchs
004a0906 fcomp dword ptr [0x5b24a8]
004a090c fnstsw ax
004a090e test ah, 1
004a0911 je 0x4a09ad
004a0917 fld dword ptr [ebp + 8]
004a091a fcomp dword ptr [0x5b2400]
004a0920 fnstsw ax
004a0922 test ah, 0x41
004a0925 jne 0x4a09ad
004a092b mov ecx, dword ptr [ebp - 4]
004a092e xor eax, eax
004a0930 mov dword ptr [ebx + 0x388], eax
004a0936 mov dword ptr [ebx + 0x38c], eax
004a093c mov dword ptr [ebx + 0x390], eax
004a0942 mov edx, dword ptr [esi + 0xc]
004a0945 lea eax, [ebx + 0x33c]
004a094b push eax
004a094c lea eax, [edi + edx + 0x1c]
004a0950 push ecx
004a0951 push eax
004a0952 push 1
004a0954 call 0x532360
004a0959 mov ecx, dword ptr [esi + 0xc]
004a095c lea eax, [ebx + 0x37c]
004a0962 push ebx
004a0963 lea edx, [edi + ecx + 0x1c]
004a0967 mov ecx, dword ptr [edi + ecx + 0x1c]
004a096b mov dword ptr [eax], ecx
004a096d mov ecx, dword ptr [edx + 4]
004a0970 mov dword ptr [eax + 4], ecx
004a0973 mov ecx, dword ptr [ebp - 0x18]
004a0976 mov edx, dword ptr [edx + 8]
004a0979 mov dword ptr [eax + 8], edx
004a097c mov edx, dword ptr [ebp - 0x14]
004a097f lea eax, [ebx + 0x330]
004a0985 mov dword ptr [ebx + 0x330], ecx
004a098b mov ecx, dword ptr [ebp - 0x10]
004a098e mov dword ptr [eax + 4], edx
004a0991 mov dword ptr [eax + 8], ecx
004a0994 call 0x4a02a0
004a0999 add esp, 0x14
004a099c lea ecx, [ebp - 0x60]
004a099f call 0x516950
004a09a4 pop edi
004a09a5 pop esi
004a09a6 pop ebx
004a09a7 mov esp, ebp
004a09a9 pop ebp
004a09aa ret
004a09ab fstp st(0)
004a09ad fld dword ptr [ebp - 8]
004a09b0 fcomp dword ptr [0x5b23f8]
004a09b6 fnstsw ax
004a09b8 test ah, 0x41
004a09bb jne 0x4a09d0
004a09bd fld dword ptr [ebp + 8]
004a09c0 fmul dword ptr [0x5b23f0]
004a09c6 fcomp dword ptr [ebp - 8]
004a09c9 fnstsw ax
004a09cb test ah, 1
004a09ce jne 0x4a0a23
004a09d0 fld dword ptr [ebp + 8]
004a09d3 fcomp dword ptr [0x5b241c]
004a09d9 fnstsw ax
004a09db test ah, 0x41
004a09de je 0x4a09e7
004a09e0 mov dword ptr [ebp + 8], 0x41200000
004a09e7 fld dword ptr [ebp + 8]
004a09ea fmul dword ptr [0x5b4a90]
004a09f0 fstp dword ptr [ebp + 8]
004a09f3 fld dword ptr [ebp + 8]
004a09f6 fistp dword ptr [ebp - 0xc]
004a09f9 mov dl, byte ptr [ebp - 0xc]
004a09fc mov byte ptr [ebx + 0xd9d], dl
004a0a02 fld dword ptr [ebp + 8]
004a0a05 fistp dword ptr [ebp - 0xc]
004a0a08 movsx eax, byte ptr [ebx + 0xd9c]
004a0a0f cmp eax, dword ptr [ebp - 0xc]
004a0a12 jle 0x4a0a1d
004a0a14 fld dword ptr [ebp + 8]
004a0a17 fistp dword ptr [ebp - 0xc]
004a0a1a mov eax, dword ptr [ebp - 0xc]
004a0a1d sub byte ptr [ebx + 0xd9c], al
004a0a23 lea ecx, [ebp - 0x60]
004a0a26 call 0x516950
004a0a2b pop edi
004a0a2c pop esi
004a0a2d pop ebx
004a0a2e mov esp, ebp
004a0a30 pop ebp
004a0a31 ret
004a0a32 nop
004a0a33 nop
004a0a34 nop
004a0a35 nop
004a0a36 nop
004a0a37 nop
004a0a38 nop
004a0a39 nop
004a0a3a nop
004a0a3b nop
004a0a3c nop
004a0a3d nop
004a0a3e nop
004a0a3f nop
004a0a40 sub esp, 0xb4
004a0a46 push ebp
004a0a47 mov ebp, dword ptr [esp + 0xbc]
004a0a4e mov eax, dword ptr [ebp + 0x3c]
004a0a51 test eax, eax
004a0a53 je 0x4a0ddc
004a0a59 mov eax, dword ptr [ebp + 0x74]
004a0a5c push ebx
004a0a5d push edi
004a0a5e push eax
004a0a5f call 0x5322b0
004a0a64 movsx ecx, word ptr [ebp + 0x4a]
004a0a68 mov dword ptr [esp + 0x10], ecx
004a0a6c mov ebx, dword ptr [0x606ac4]
004a0a72 fild dword ptr [esp + 0x10]
004a0a76 movsx edx, word ptr [ebp + 0x4c]
004a0a7a fmul dword ptr [0x5b3ca0]
004a0a80 mov dword ptr [esp + 0x10], edx
004a0a84 mov edi, dword ptr [ebp + 0x3c]
004a0a87 movsx eax, word ptr [ebp + 0x4e]
004a0a8b fstp dword ptr [esp + 0x34]
004a0a8f fild dword ptr [esp + 0x10]
004a0a93 mov dword ptr [esp + 0x10], eax
004a0a97 lea edx, [esp + 0x7c]
004a0a9b movsx ecx, word ptr [ebp + 0x40]
004a0a9f fmul dword ptr [0x5b3ca0]
004a0aa5 lea eax, [ebp + 0x42]
004a0aa8 sub ebx, edi
004a0aaa push edx
004a0aab push eax
004a0aac mov dword ptr [esp + 0x50], ebx
004a0ab0 fstp dword ptr [esp + 0x40]
004a0ab4 fild dword ptr [esp + 0x18]
004a0ab8 mov dword ptr [esp + 0x18], ecx
004a0abc fmul dword ptr [0x5b3ca0]
004a0ac2 fstp dword ptr [esp + 0x44]
004a0ac6 fild dword ptr [esp + 0x18]
004a0aca fmul dword ptr [0x5b3060]
004a0ad0 fstp dword ptr [esp + 0x18]
004a0ad4 call 0x4a0020
004a0ad9 add esp, 0xc
004a0adc xor eax, eax
004a0ade fild dword ptr [esp + eax + 0x78]
004a0ae2 add eax, 4
004a0ae5 cmp eax, 0x24
004a0ae8 fmul dword ptr [0x5b253c]
004a0aee fstp dword ptr [esp + eax + 0x98]
004a0af5 jl 0x4a0ade
004a0af7 lea ecx, [ebp + 0x50]
004a0afa push esi
004a0afb mov edx, dword ptr [ecx]
004a0afd mov dword ptr [esp + 0x14], edx
004a0b01 mov edx, dword ptr [ebp + 0x6c]
004a0b04 mov eax, dword ptr [ecx + 4]
004a0b07 inc edx
004a0b08 mov dword ptr [ebp + 0x6c], edx
004a0b0b mov edx, dword ptr [ebp + 0x74]
004a0b0e mov ecx, dword ptr [ecx + 8]
004a0b11 push edx
004a0b12 mov dword ptr [esp + 0x1c], eax
004a0b16 mov dword ptr [esp + 0x20], ecx
004a0b1a call 0x5322c0
004a0b1f fld dword ptr [esp + 0x14]
004a0b23 fmul dword ptr [0x5b2828]
004a0b29 mov eax, ebx
004a0b2b mov ecx, dword ptr [esp + 0x38]
004a0b2f cdq
004a0b30 fstp dword ptr [esp + 0x44]
004a0b34 sub eax, edx
004a0b36 mov dword ptr [esp + 0x48], ecx
004a0b3a sar eax, 1
004a0b3c neg eax
004a0b3e mov dword ptr [esp + 0x24], eax
004a0b42 mov eax, dword ptr [esp + 0x40]
004a0b46 fild dword ptr [esp + 0x24]
004a0b4a mov dword ptr [esp + 0x24], eax
004a0b4e fmul dword ptr [esp + 0x44]
004a0b52 fstp dword ptr [esp + 0x28]
004a0b56 mov esi, dword ptr [esp + 0x28]
004a0b5a push esi
004a0b5b call 0x5327e0
004a0b60 fstp dword ptr [esp + 0x2c]
004a0b64 push esi
004a0b65 call 0x5327f0
004a0b6a fld st(0)
004a0b6c fmul dword ptr [esp + 0x50]
004a0b70 fld dword ptr [esp + 0x30]
004a0b74 fmul dword ptr [esp + 0x2c]
004a0b78 add esp, 0xc
004a0b7b lea edx, [esp + 0x7c]
004a0b7f fsubp st(1)
004a0b81 push 0
004a0b83 push ecx
004a0b84 fstp dword ptr [esp + 0x3c]
004a0b88 fld dword ptr [esp + 0x2c]
004a0b8c fmul dword ptr [esp + 0x4c]
004a0b90 fxch st(1)
004a0b92 fmul dword ptr [esp + 0x28]
004a0b96 faddp st(1)
004a0b98 fstp dword ptr [esp + 0x44]
004a0b9c fild dword ptr [esp + 0x50]
004a0ba0 fld dword ptr [esp + 0x3c]
004a0ba4 fmul dword ptr [0x5b2828]
004a0baa fmul st(1)
004a0bac fadd dword ptr [esp + 0x1c]
004a0bb0 fstp dword ptr [esp + 0x1c]
004a0bb4 fld dword ptr [esp + 0x40]
004a0bb8 fmul dword ptr [0x5b2828]
004a0bbe fmul st(1)
004a0bc0 fadd dword ptr [esp + 0x20]
004a0bc4 fstp dword ptr [esp + 0x20]
004a0bc8 fld dword ptr [esp + 0x44]
004a0bcc fmul dword ptr [0x5b2828]
004a0bd2 fmul st(1)
004a0bd4 fadd dword ptr [esp + 0x24]
004a0bd8 fstp dword ptr [esp + 0x24]
004a0bdc fmul dword ptr [esp + 0x48]
004a0be0 fstp dword ptr [esp]
004a0be3 push 0
004a0be5 push edx
004a0be6 call 0x49b870
004a0beb lea eax, [esp + 0xb0]
004a0bf2 lea ecx, [esp + 0x8c]
004a0bf9 push eax
004a0bfa push ecx
004a0bfb lea edx, [esp + 0xb8]
004a0c02 push edx
004a0c03 call 0x532470
004a0c08 add esp, 0x1c
004a0c0b lea esi, [ebp + 8]
004a0c0e mov ecx, 0xc
004a0c13 lea edi, [esp + 0x4c]
004a0c17 rep movsd dword ptr es:[edi], dword ptr [esi]
004a0c19 lea eax, [esp + 0x14]
004a0c1d push 1
004a0c1f push eax
004a0c20 lea ecx, [esp + 0x54]
004a0c24 call 0x474060
004a0c29 xor esi, esi
004a0c2b cmp word ptr [esp + 0x70], si
004a0c30 jne 0x4a0d26
004a0c36 movsx eax, word ptr [esp + 0x4c]
004a0c3b mov edx, dword ptr [0x628bc0]
004a0c41 lea ecx, [eax + eax*4]
004a0c44 mov eax, dword ptr [edx + 0xc]
004a0c47 shl ecx, 4
004a0c4a lea ecx, [ecx + eax + 4]
004a0c4e mov edx, dword ptr [ecx]
004a0c50 mov dword ptr [esp + 0x28], edx
004a0c54 lea edx, [esp + 0x28]
004a0c58 mov eax, dword ptr [ecx + 4]
004a0c5b push edx
004a0c5c mov dword ptr [esp + 0x30], eax
004a0c60 lea eax, [esp + 0x18]
004a0c64 mov ecx, dword ptr [ecx + 8]
004a0c67 push eax
004a0c68 mov dword ptr [esp + 0x38], ecx
004a0c6c lea ecx, [esp + 0x30]
004a0c70 push ecx
004a0c71 push 1
004a0c73 call 0x532330
004a0c78 fld dword ptr [esp + 0x38]
004a0c7c fcomp dword ptr [0x5b23f8]
004a0c82 add esp, 0x10
004a0c85 fnstsw ax
004a0c87 test ah, 0x40
004a0c8a je 0x4a0cae
004a0c8c fld dword ptr [esp + 0x2c]
004a0c90 fcomp dword ptr [0x5b23f8]
004a0c96 fnstsw ax
004a0c98 test ah, 0x40
004a0c9b je 0x4a0cae
004a0c9d fld dword ptr [esp + 0x30]
004a0ca1 fcomp dword ptr [0x5b23f8]
004a0ca7 fnstsw ax
004a0ca9 test ah, 0x40
004a0cac jne 0x4a0cc0
004a0cae lea edx, [esp + 0x28]
004a0cb2 lea eax, [esp + 0x28]
004a0cb6 push edx
004a0cb7 push eax
004a0cb8 call 0x5328d0
004a0cbd add esp, 8
004a0cc0 cmp word ptr [esp + 0x70], si
004a0cc5 jne 0x4a0cf7
004a0cc7 lea ecx, [esp + 0x14]
004a0ccb lea edx, [esp + 0x28]
004a0ccf push ecx
004a0cd0 lea eax, [esp + 0x18]
004a0cd4 push edx
004a0cd5 push eax
004a0cd6 push 1
004a0cd8 call 0x532300
004a0cdd add esp, 0x10
004a0ce0 lea ecx, [esp + 0x14]
004a0ce4 push 1
004a0ce6 push ecx
004a0ce7 lea ecx, [esp + 0x54]
004a0ceb call 0x474060
004a0cf0 cmp word ptr [esp + 0x70], si
004a0cf5 je 0x4a0cc7
004a0cf7 lea edx, [esp + 0x14]
004a0cfb lea eax, [esp + 0x28]
004a0cff push edx
004a0d00 lea ecx, [esp + 0x18]
004a0d04 push eax
004a0d05 push ecx
004a0d06 push 1
004a0d08 call 0x532300
004a0d0d lea edx, [esp + 0x24]
004a0d11 lea eax, [esp + 0x38]
004a0d15 push edx
004a0d16 lea ecx, [esp + 0x28]
004a0d1a push eax
004a0d1b push ecx
004a0d1c push 1
004a0d1e call 0x532300
004a0d23 add esp, 0x20
004a0d26 lea edx, [esp + 0xa0]
004a0d2d lea eax, [esp + 0x34]
004a0d31 push edx
004a0d32 mov edx, dword ptr [esp + 0x14]
004a0d36 lea ecx, [esp + 0x18]
004a0d3a push eax
004a0d3b push ecx
004a0d3c push edx
004a0d3d push ebp
004a0d3e call 0x4a04a0
004a0d43 lea eax, [esp + 0x48]
004a0d47 mov byte ptr [ebp + 0xd7e], 1
004a0d4e push eax
004a0d4f mov byte ptr [ebp + 0xd82], 1
004a0d56 call 0x532b20
004a0d5b mov al, byte ptr [ebp + 0x39]
004a0d5e add esp, 0x18
004a0d61 fstp dword ptr [ebp + 0xec4]
004a0d67 test al, al
004a0d69 jne 0x4a0db2
004a0d6b lea ecx, [esp + 0x28]
004a0d6f push ecx
004a0d70 push ebp
004a0d71 call 0x499a70
004a0d76 fstp dword ptr [ebp + 0x41c]
004a0d7c fld dword ptr [ebp + 0x424]
004a0d82 fsubr dword ptr [ebp + 0x334]
004a0d88 add esp, 8
004a0d8b mov dword ptr [ebp + 0x424], esi
004a0d91 lea eax, [ebp + 0x820]
004a0d97 mov ecx, 4
004a0d9c fstp dword ptr [ebp + 0x334]
004a0da2 mov dword ptr [eax + 0x1c], esi
004a0da5 mov dword ptr [eax], esi
004a0da7 mov dword ptr [eax + 8], esi
004a0daa add eax, 0xc4
004a0daf dec ecx
004a0db0 jne 0x4a0da2
004a0db2 push ebp
004a0db3 call 0x49ae30
004a0db8 add esp, 4
004a0dbb cmp ebx, esi
004a0dbd pop esi
004a0dbe jg 0x4a0dc2
004a0dc0 neg ebx
004a0dc2 pop edi
004a0dc3 cmp ebx, 0x100
004a0dc9 pop ebx
004a0dca jle 0x4a0dd3
004a0dcc mov dword ptr [ebp + 0x70], 1
004a0dd3 lea ecx, [esp + 0x40]
004a0dd7 call 0x516950
004a0ddc pop ebp
004a0ddd add esp, 0xb4
004a0de3 ret
004a0de4 nop
004a0de5 nop
004a0de6 nop
004a0de7 nop
004a0de8 nop
004a0de9 nop
004a0dea nop
004a0deb nop
004a0dec nop
004a0ded nop
004a0dee nop
004a0def nop
004a0df0 push esi
004a0df1 mov esi, dword ptr [esp + 8]
004a0df5 push edi
004a0df6 mov edi, dword ptr [esp + 0x10]
004a0dfa mov eax, dword ptr [esi + 0x3c]
004a0dfd mov ecx, dword ptr [edi + 4]
004a0e00 mov dword ptr [esp + 0xc], eax
004a0e04 cmp eax, ecx
004a0e06 jge 0x4a0f35
004a0e0c mov eax, dword ptr [esi + 0x74]
004a0e0f push ebx
004a0e10 push eax
004a0e11 call 0x5322b0
004a0e16 mov cl, byte ptr [edi + 1]
004a0e19 xor ebx, ebx
004a0e1b mov byte ptr [esi + 0x39], cl
004a0e1e mov dl, byte ptr [edi + 2]
004a0e21 mov byte ptr [esi + 0x3a], dl
004a0e24 mov al, byte ptr [edi]
004a0e26 mov byte ptr [esi + 0x38], al
004a0e29 mov cl, byte ptr [edi + 3]
004a0e2c mov byte ptr [esi + 0x3b], cl
004a0e2f mov edx, dword ptr [edi + 4]
004a0e32 mov dword ptr [esi + 0x3c], edx
004a0e35 mov eax, dword ptr [edi + 0xa]
004a0e38 mov dword ptr [esi + 0x42], eax
004a0e3b mov ecx, dword ptr [edi + 0xe]
004a0e3e lea edx, [edi + 0x12]
004a0e41 mov dword ptr [esi + 0x46], ecx
004a0e44 lea eax, [esi + 0x4a]
004a0e47 add esp, 4
004a0e4a mov ecx, dword ptr [edx]
004a0e4c mov dword ptr [eax], ecx
004a0e4e lea ecx, [esi + 0x50]
004a0e51 mov dx, word ptr [edx + 4]
004a0e55 mov word ptr [eax + 4], dx
004a0e59 lea eax, [edi + 0x18]
004a0e5c mov edx, dword ptr [edi + 0x18]
004a0e5f mov dword ptr [ecx], edx
004a0e61 mov edx, dword ptr [eax + 4]
004a0e64 mov dword ptr [ecx + 4], edx
004a0e67 mov eax, dword ptr [eax + 8]
004a0e6a mov dword ptr [ecx + 8], eax
004a0e6d mov cx, word ptr [edi + 8]
004a0e71 mov word ptr [esi + 0x40], cx
004a0e75 mov edx, dword ptr [0x606ac4]
004a0e7b mov edi, dword ptr [edi + 4]
004a0e7e mov eax, edx
004a0e80 sub eax, edi
004a0e82 cmp eax, ebx
004a0e84 jle 0x4a0e8a
004a0e86 mov ecx, eax
004a0e88 jmp 0x4a0e8e
004a0e8a mov ecx, edi
004a0e8c sub ecx, edx
004a0e8e cmp ecx, 1
004a0e91 jge 0x4a0e9a
004a0e93 mov eax, 1
004a0e98 jmp 0x4a0ea2
004a0e9a cmp eax, ebx
004a0e9c jg 0x4a0ea2
004a0e9e sub edi, edx
004a0ea0 mov eax, edi
004a0ea2 mov edx, dword ptr [esi + 0x74]
004a0ea5 mov dword ptr [esi + 0x68], eax
004a0ea8 push edx
004a0ea9 mov dword ptr [esi + 0x6c], ebx
004a0eac call 0x5322c0
004a0eb1 mov edx, dword ptr [esi + 0x5c]
004a0eb4 mov ecx, dword ptr [esi + 0x68]
004a0eb7 add esp, 4
004a0eba lea eax, [edx*8]
004a0ec1 sub eax, edx
004a0ec3 add eax, ecx
004a0ec5 cdq
004a0ec6 and edx, 7
004a0ec9 add eax, edx
004a0ecb sar eax, 3
004a0ece cmp ecx, 0x40
004a0ed1 mov dword ptr [esi + 0x5c], eax
004a0ed4 jle 0x4a0f03
004a0ed6 mov edx, dword ptr [esi + 0x64]
004a0ed9 inc edx
004a0eda mov eax, edx
004a0edc mov dword ptr [esi + 0x64], edx
004a0edf cmp eax, 4
004a0ee2 jg 0x4a0eec
004a0ee4 cmp ecx, 0x80
004a0eea jle 0x4a0f06
004a0eec cmp dword ptr [esi + 0x70], ebx
004a0eef jne 0x4a0efa
004a0ef1 push esi
004a0ef2 call 0x4a03d0
004a0ef7 add esp, 4
004a0efa mov dword ptr [esi + 0x70], 1
004a0f01 jmp 0x4a0f06
004a0f03 mov dword ptr [esi + 0x64], ebx
004a0f06 cmp dword ptr [esi + 0x68], 0x20
004a0f0a jge 0x4a0f1f
004a0f0c mov ecx, dword ptr [esi + 0x60]
004a0f0f inc ecx
004a0f10 mov eax, ecx
004a0f12 mov dword ptr [esi + 0x60], ecx
004a0f15 cmp eax, 8
004a0f18 jle 0x4a0f22
004a0f1a mov dword ptr [esi + 0x70], ebx
004a0f1d jmp 0x4a0f22
004a0f1f mov dword ptr [esi + 0x60], ebx
004a0f22 mov eax, dword ptr [esp + 0x10]
004a0f26 cmp eax, ebx
004a0f28 pop ebx
004a0f29 jne 0x4a0f35
004a0f2b mov dword ptr [esi + 0xdac], 1
004a0f35 pop edi
004a0f36 pop esi
004a0f37 ret
004a0f38 nop
004a0f39 nop
004a0f3a nop
004a0f3b nop
004a0f3c nop
004a0f3d nop
004a0f3e nop
004a0f3f nop
004a0f40 push ecx
004a0f41 mov dword ptr [esp], 0x800000
004a0f49 mov eax, dword ptr [esp]
004a0f4d mov dword ptr [0x6559c4], eax
004a0f52 pop ecx
004a0f53 ret
004a0f54 nop
004a0f55 nop
004a0f56 nop
004a0f57 nop
004a0f58 nop
004a0f59 nop
004a0f5a nop
004a0f5b nop
004a0f5c nop
004a0f5d nop
004a0f5e nop
004a0f5f nop
004a0f60 fld dword ptr [0x5b24a8]
004a0f66 fdiv dword ptr [0x6559c4]
004a0f6c fstp dword ptr [0x6559c0]
004a0f72 ret
004a0f73 nop
004a0f74 nop
004a0f75 nop
004a0f76 nop
004a0f77 nop
004a0f78 nop
004a0f79 nop
004a0f7a nop
004a0f7b nop
004a0f7c nop
004a0f7d nop
004a0f7e nop
004a0f7f nop
004a0f80 push ebx
004a0f81 push ebp
004a0f82 push esi
004a0f83 push edi
004a0f84 mov edi, dword ptr [0x5e8b58]
004a0f8a xor ebp, ebp
004a0f8c xor edx, edx
004a0f8e test edi, edi
004a0f90 jle 0x4a1016
004a0f96 mov ebx, dword ptr [esp + 0x14]
004a0f9a mov esi, 0x5e8b34
004a0f9f mov ecx, dword ptr [esi]
004a0fa1 mov al, byte ptr [ecx + 0x7f]
004a0fa4 test al, al
004a0fa6 je 0x4a100e
004a0fa8 fld dword ptr [ebx + 0x330]
004a0fae fsub dword ptr [ecx + 0x330]
004a0fb4 fcom dword ptr [0x5b23f8]
004a0fba fnstsw ax
004a0fbc test ah, 1
004a0fbf je 0x4a0fc3
004a0fc1 fchs
004a0fc3 fld dword ptr [ebx + 0x338]
004a0fc9 fsub dword ptr [ecx + 0x338]
004a0fcf fcom dword ptr [0x5b23f8]
004a0fd5 fnstsw ax
004a0fd7 test ah, 1
004a0fda je 0x4a0fde
004a0fdc fchs
004a0fde fld st(1)
004a0fe0 fcomp st(1)
004a0fe2 fnstsw ax
004a0fe4 test ah, 0x41
004a0fe7 jne 0x4a0ff3
004a0fe9 fmul dword ptr [0x5b2468]
004a0fef faddp st(1)
004a0ff1 jmp 0x4a1001
004a0ff3 fxch st(1)
004a0ff5 fmul dword ptr [0x5b2468]
004a0ffb fadd st(1)
004a0ffd fxch st(1)
004a0fff fstp st(0)
004a1001 fcomp dword ptr [0x5b241c]
004a1007 fnstsw ax
004a1009 test ah, 1
004a100c jne 0x4a101d
004a100e inc edx
004a100f add esi, 4
004a1012 cmp edx, edi
004a1014 jl 0x4a0f9f
004a1016 pop edi
004a1017 mov eax, ebp
004a1019 pop esi
004a101a pop ebp
004a101b pop ebx
004a101c ret
004a101d pop edi
004a101e pop esi
004a101f pop ebp
004a1020 mov eax, 1
004a1025 pop ebx
004a1026 ret
004a1027 nop
004a1028 nop
004a1029 nop
004a102a nop
004a102b nop
004a102c nop
004a102d nop
004a102e nop
004a102f nop
004a1030 push ebx
004a1031 push esi
004a1032 mov esi, dword ptr [esp + 0xc]
004a1036 xor ebx, ebx
004a1038 cmp byte ptr [esi + 0x7d], bl
004a103b je 0x4a107d
004a103d cmp byte ptr [esi + 0x7c], bl
004a1040 je 0x4a1066
004a1042 mov dword ptr [esi + 0x33c], ebx
004a1048 mov dword ptr [esi + 0x340], ebx
004a104e mov dword ptr [esi + 0x344], ebx
004a1054 mov dword ptr [esi + 0x388], ebx
004a105a mov dword ptr [esi + 0x38c], ebx
004a1060 mov dword ptr [esi + 0x390], ebx
004a1066 push esi
004a1067 call 0x4a0f80
004a106c add esp, 4
004a106f test eax, eax
004a1071 je 0x4a1272
004a1077 mov byte ptr [esi + 0x7d], bl
004a107a pop esi
004a107b pop ebx
004a107c ret
004a107d fld dword ptr [esi + 0x424]
004a1083 fcomp dword ptr [0x5b2738]
004a1089 fnstsw ax
004a108b test ah, 1
004a108e je 0x4a10d0
004a1090 lea eax, [esi + 0x33c]
004a1096 push eax
004a1097 push 0x3f6ccccd
004a109c push eax
004a109d push 1
004a109f call 0x532360
004a10a4 fld dword ptr [esi + 0x388]
004a10aa fmul dword ptr [0x5b4a94]
004a10b0 add esp, 0x10
004a10b3 fstp dword ptr [esi + 0x388]
004a10b9 fld dword ptr [esi + 0x38c]
004a10bf fmul dword ptr [0x5b25f4]
004a10c5 fstp dword ptr [esi + 0x38c]
004a10cb jmp 0x4a116c
004a10d0 fld dword ptr [esi + 0x388]
004a10d6 fcomp dword ptr [0x5b23f8]
004a10dc fld dword ptr [esi + 0x388]
004a10e2 fnstsw ax
004a10e4 test ah, 1
004a10e7 je 0x4a10eb
004a10e9 fchs
004a10eb fcomp dword ptr [0x5b2404]
004a10f1 fnstsw ax
004a10f3 test ah, 0x41
004a10f6 jne 0x4a110a
004a10f8 fld dword ptr [esi + 0x388]
004a10fe fmul dword ptr [0x5b4a94]
004a1104 fstp dword ptr [esi + 0x388]
004a110a fld dword ptr [esi + 0x38c]
004a1110 fcomp dword ptr [0x5b23f8]
004a1116 fld dword ptr [esi + 0x38c]
004a111c fnstsw ax
004a111e test ah, 1
004a1121 je 0x4a1125
004a1123 fchs
004a1125 fcomp dword ptr [0x5b2404]
004a112b fnstsw ax
004a112d test ah, 0x41
004a1130 jne 0x4a1144
004a1132 fld dword ptr [esi + 0x38c]
004a1138 fmul dword ptr [0x5b4a94]
004a113e fstp dword ptr [esi + 0x38c]
004a1144 fld dword ptr [esi + 0x390]
004a114a fcomp dword ptr [0x5b23f8]
004a1150 fld dword ptr [esi + 0x390]
004a1156 fnstsw ax
004a1158 test ah, 1
004a115b je 0x4a115f
004a115d fchs
004a115f fcomp dword ptr [0x5b2404]
004a1165 fnstsw ax
004a1167 test ah, 0x41
004a116a jne 0x4a117e
004a116c fld dword ptr [esi + 0x390]
004a1172 fmul dword ptr [0x5b4a94]
004a1178 fstp dword ptr [esi + 0x390]
004a117e fld dword ptr [esi + 0x33c]
004a1184 fcomp dword ptr [0x5b23f8]
004a118a fld dword ptr [esi + 0x33c]
004a1190 fnstsw ax
004a1192 test ah, 1
004a1195 je 0x4a1199
004a1197 fchs
004a1199 fld dword ptr [esi + 0x340]
004a119f fcomp dword ptr [0x5b23f8]
004a11a5 fld dword ptr [esi + 0x340]
004a11ab fnstsw ax
004a11ad test ah, 1
004a11b0 je 0x4a11b4
004a11b2 fchs
004a11b4 fld dword ptr [esi + 0x344]
004a11ba fcomp dword ptr [0x5b23f8]
004a11c0 fld dword ptr [esi + 0x344]
004a11c6 fnstsw ax
004a11c8 test ah, 1
004a11cb je 0x4a11cf
004a11cd fchs
004a11cf fadd st(1)
004a11d1 fadd st(2)
004a11d3 fcomp dword ptr [0x5b2604]
004a11d9 fnstsw ax
004a11db fstp st(0)
004a11dd test ah, 1
004a11e0 fstp st(0)
004a11e2 je 0x4a1272
004a11e8 fld dword ptr [esi + 0x388]
004a11ee fcomp dword ptr [0x5b23f8]
004a11f4 fld dword ptr [esi + 0x388]
004a11fa fnstsw ax
004a11fc test ah, 1
004a11ff je 0x4a1203
004a1201 fchs
004a1203 fld dword ptr [esi + 0x38c]
004a1209 fcomp dword ptr [0x5b23f8]
004a120f fld dword ptr [esi + 0x38c]
004a1215 fnstsw ax
004a1217 test ah, 1
004a121a je 0x4a121e
004a121c fchs
004a121e fld dword ptr [esi + 0x390]
004a1224 fcomp dword ptr [0x5b23f8]
004a122a fld dword ptr [esi + 0x390]
004a1230 fnstsw ax
004a1232 test ah, 1
004a1235 je 0x4a1239
004a1237 fchs
004a1239 fadd st(1)
004a123b fadd st(2)
004a123d fcomp dword ptr [0x5b26a0]
004a1243 fnstsw ax
004a1245 fstp st(0)
004a1247 test ah, 1
004a124a fstp st(0)
004a124c je 0x4a1272
004a124e fld dword ptr [esi + 0x428]
004a1254 fcomp dword ptr [0x5b27a8]
004a125a fnstsw ax
004a125c test ah, 1
004a125f je 0x4a1272
004a1261 push esi
004a1262 call 0x4a0f80
004a1267 add esp, 4
004a126a test eax, eax
004a126c jne 0x4a1272
004a126e mov byte ptr [esi + 0x7d], 1
004a1272 pop esi
004a1273 pop ebx
004a1274 ret
004a1275 nop
004a1276 nop
004a1277 nop
004a1278 nop
004a1279 nop
004a127a nop
004a127b nop
004a127c nop
004a127d nop
004a127e nop
004a127f nop
004a1280 mov edx, dword ptr [esp + 4]
004a1284 sub esp, 0x10
004a1287 mov eax, dword ptr [edx + 0x558]
004a128d cmp dword ptr [eax + 4], 1
004a1291 jne 0x4a14b0
004a1297 mov eax, dword ptr [0x628960]
004a129c mov ecx, dword ptr [esp + 0x18]
004a12a0 push esi
004a12a1 mov esi, dword ptr [0x658080]
004a12a7 mov eax, dword ptr [eax + 0x34]
004a12aa and ecx, 0x7f
004a12ad sub ecx, esi
004a12af push edi
004a12b0 mov eax, dword ptr [eax]
004a12b2 mov edi, dword ptr [eax + ecx*4]
004a12b5 fld dword ptr [edi + 0x14]
004a12b8 fmul dword ptr [0x5b273c]
004a12be fstp dword ptr [edx + 0x354]
004a12c4 mov eax, dword ptr [edi + 0x18]
004a12c7 cmp eax, 0xc
004a12ca ja 0x4a136d
004a12d0 jmp dword ptr [eax*4 + 0x4a14d4]
004a12d7 mov dword ptr [edx + 0x44c], 0x12
004a12e1 jmp 0x4a1377
004a12e6 mov dword ptr [edx + 0x44c], 0x11
004a12f0 jmp 0x4a1377
004a12f5 mov dword ptr [edx + 0x44c], 0x14
004a12ff jmp 0x4a1377
004a1301 mov dword ptr [edx + 0x44c], 0x10
004a130b jmp 0x4a1377
004a130d mov dword ptr [edx + 0x44c], 0xe
004a1317 jmp 0x4a1377
004a1319 mov dword ptr [edx + 0x44c], 0xf
004a1323 jmp 0x4a1377
004a1325 mov dword ptr [edx + 0x44c], 3
004a132f jmp 0x4a1377
004a1331 mov dword ptr [edx + 0x44c], 9
004a133b jmp 0x4a1377
004a133d mov dword ptr [edx + 0x44c], 0xa
004a1347 jmp 0x4a1377
004a1349 mov dword ptr [edx + 0x44c], 0xb
004a1353 jmp 0x4a1377
004a1355 mov dword ptr [edx + 0x44c], 0xc
004a135f jmp 0x4a1377
004a1361 mov dword ptr [edx + 0x44c], 0xd
004a136b jmp 0x4a1377
004a136d mov dword ptr [edx + 0x44c], 0x13
004a1377 mov eax, dword ptr [edi + 0x10]
004a137a xor esi, esi
004a137c fld dword ptr [0x5b23f8]
004a1382 test eax, eax
004a1384 mov dword ptr [esp + 0x20], 0
004a138c mov dword ptr [esp + 0xc], 0
004a1394 mov dword ptr [esp + 0x10], 0
004a139c mov dword ptr [esp + 0x1c], 0
004a13a4 mov dword ptr [esp + 8], 0
004a13ac mov dword ptr [edx + 0x32c], eax
004a13b2 jle 0x4a1472
004a13b8 mov eax, 0xffffff74
004a13bd push ebx
004a13be sub eax, edx
004a13c0 push ebp
004a13c1 lea ecx, [edx + 0x8c]
004a13c7 mov dword ptr [esp + 0x1c], eax
004a13cb jmp 0x4a13d1
004a13cd mov eax, dword ptr [esp + 0x1c]
004a13d1 mov ebp, dword ptr [edi + 0xc]
004a13d4 mov ebx, ecx
004a13d6 add eax, ebp
004a13d8 add eax, ecx
004a13da mov ebp, dword ptr [eax]
004a13dc mov dword ptr [ebx], ebp
004a13de mov ebp, dword ptr [eax + 4]
004a13e1 mov dword ptr [ebx + 4], ebp
004a13e4 mov eax, dword ptr [eax + 8]
004a13e7 mov dword ptr [ebx + 8], eax
004a13ea fld dword ptr [ecx]
004a13ec fcomp dword ptr [esp + 0x28]
004a13f0 fnstsw ax
004a13f2 test ah, 1
004a13f5 je 0x4a13fd
004a13f7 mov eax, dword ptr [ecx]
004a13f9 mov dword ptr [esp + 0x28], eax
004a13fd fld dword ptr [ecx]
004a13ff fcomp dword ptr [esp + 0x24]
004a1403 fnstsw ax
004a1405 test ah, 0x41
004a1408 jne 0x4a1410
004a140a mov eax, dword ptr [ecx]
004a140c mov dword ptr [esp + 0x24], eax
004a1410 fld dword ptr [ecx + 4]
004a1413 fcomp dword ptr [esp + 0x14]
004a1417 fnstsw ax
004a1419 test ah, 1
004a141c je 0x4a1425
004a141e mov eax, dword ptr [ecx + 4]
004a1421 mov dword ptr [esp + 0x14], eax
004a1425 fld dword ptr [ecx + 4]
004a1428 fcomp dword ptr [esp + 0x10]
004a142c fnstsw ax
004a142e test ah, 0x41
004a1431 jne 0x4a143a
004a1433 mov eax, dword ptr [ecx + 4]
004a1436 mov dword ptr [esp + 0x10], eax
004a143a fld dword ptr [ecx + 8]
004a143d fcomp dword ptr [esp + 0x18]
004a1441 fnstsw ax
004a1443 test ah, 1
004a1446 je 0x4a144f
004a1448 mov eax, dword ptr [ecx + 8]
004a144b mov dword ptr [esp + 0x18], eax
004a144f fcom dword ptr [ecx + 8]
004a1452 fnstsw ax
004a1454 test ah, 1
004a1457 je 0x4a145e
004a1459 fstp st(0)
004a145b fld dword ptr [ecx + 8]
004a145e mov eax, dword ptr [edx + 0x32c]
004a1464 inc esi
004a1465 add ecx, 0xc
004a1468 cmp esi, eax
004a146a jl 0x4a13cd
004a1470 pop ebp
004a1471 pop ebx
004a1472 fld dword ptr [esp + 0x1c]
004a1476 fsub dword ptr [esp + 0x20]
004a147a pop edi
004a147b pop esi
004a147c fmul dword ptr [0x5b23f0]
004a1482 fstp dword ptr [edx + 0x3a8]
004a1488 fld dword ptr [esp]
004a148c fsub dword ptr [esp + 4]
004a1490 fmul dword ptr [0x5b23f0]
004a1496 fstp dword ptr [edx + 0x3ac]
004a149c fsub dword ptr [esp + 8]
004a14a0 fmul dword ptr [0x5b23f0]
004a14a6 fstp dword ptr [edx + 0x3b0]
004a14ac add esp, 0x10
004a14af ret
004a14b0 fld dword ptr [edx + 0x3b0]
004a14b6 fmul dword ptr [edx + 0x3ac]
004a14bc fmul dword ptr [edx + 0x3a8]
004a14c2 fmul dword ptr [0x5b2404]
004a14c8 fstp dword ptr [edx + 0x354]
004a14ce add esp, 0x10
004a14d1 ret
004a14d2 mov edi, edi
004a14d4 insd dword ptr es:[edi], dx
004a14d5 adc ecx, dword ptr [edx]
004a14d8 xlatb
004a14d9 adc cl, byte ptr [edx]
004a14dc out 0x12, al
004a14de dec edx
004a14df add ch, dh
004a14e1 adc cl, byte ptr [edx]
004a14e4 add dword ptr [ebx], edx
004a14e6 dec edx
004a14e7 add byte ptr [0x19004a13], cl
004a14ed adc ecx, dword ptr [edx]
004a14f0 and eax, 0x31004a13
004a14f5 adc ecx, dword ptr [edx]
004a14f8 cmp eax, 0x49004a13
004a14fd adc ecx, dword ptr [edx]
004a1500 push ebp
004a1501 adc ecx, dword ptr [edx]
004a1504 popal
004a1505 adc ecx, dword ptr [edx]
004a1508 nop
004a1509 nop
004a150a nop
004a150b nop
004a150c nop
004a150d nop
004a150e nop
004a150f nop
004a1510 sub esp, 0x3c
004a1513 push ebx
004a1514 push ebp
004a1515 mov ebp, dword ptr [esp + 0x48]
004a1519 push esi
004a151a mov esi, dword ptr [0x658080]
004a1520 mov eax, dword ptr [ebp]
004a1523 mov ecx, dword ptr [ebp + 0x558]
004a1529 and eax, 0x7f
004a152c mov edx, dword ptr [ecx + 4]
004a152f sub eax, esi
004a1531 cmp edx, 1
004a1534 jne 0x4a15be
004a153a mov edx, dword ptr [0x628960]
004a1540 lea ebx, [ebp + 0x364]
004a1546 push edi
004a1547 mov edi, ebx
004a1549 mov ecx, dword ptr [edx + 0x34]
004a154c push ebx
004a154d push ebx
004a154e mov edx, dword ptr [ecx]
004a1550 mov ecx, 9
004a1555 mov eax, dword ptr [edx + eax*4]
004a1558 mov dword ptr [esp + 0x58], eax
004a155c lea esi, [eax + 0x34]
004a155f rep movsd dword ptr es:[edi], dword ptr [esi]
004a1561 call 0x5328d0
004a1566 lea eax, [ebp + 0x370]
004a156c push eax
004a156d push eax
004a156e call 0x5328d0
004a1573 lea eax, [ebp + 0x37c]
004a1579 push eax
004a157a push eax
004a157b call 0x5328d0
004a1580 lea edi, [ebp + 0x490]
004a1586 mov ecx, 9
004a158b mov esi, ebx
004a158d add esp, 0x18
004a1590 rep movsd dword ptr es:[edi], dword ptr [esi]
004a1592 mov ecx, dword ptr [esp + 0x50]
004a1596 lea esi, [ebp + 0x330]
004a159c mov edx, esi
004a159e push esi
004a159f lea eax, [ecx + 0x28]
004a15a2 push ebx
004a15a3 mov edi, dword ptr [eax]
004a15a5 mov dword ptr [edx], edi
004a15a7 mov edi, dword ptr [eax + 4]
004a15aa mov dword ptr [edx + 4], edi
004a15ad mov eax, dword ptr [eax + 8]
004a15b0 mov dword ptr [edx + 8], eax
004a15b3 call 0x483590
004a15b8 pop edi
004a15b9 jmp 0x4a1663
004a15be lea ecx, [eax + eax*4]
004a15c1 lea esi, [ebp + 0x330]
004a15c7 lea ebx, [ebp + 0x364]
004a15cd lea ecx, [ecx + ecx*8]
004a15d0 shl ecx, 1
004a15d2 sub ecx, eax
004a15d4 lea eax, [eax + ecx*4]
004a15d7 mov edx, dword ptr [eax*4 + 0x629540]
004a15de mov word ptr [ebp + 8], dx
004a15e2 mov eax, dword ptr [eax*4 + 0x629540]
004a15e9 mov ecx, dword ptr [0x628bc0]
004a15ef lea eax, [eax + eax*4]
004a15f2 mov edx, dword ptr [ecx + 0xc]
004a15f5 shl eax, 4
004a15f8 lea eax, [edx + eax + 4]
004a15fc mov ecx, dword ptr [eax]
004a15fe mov dword ptr [esp + 0xc], ecx
004a1602 mov edx, dword ptr [eax + 4]
004a1605 mov dword ptr [esp + 0x10], edx
004a1609 fld dword ptr [esp + 0x10]
004a160d mov eax, dword ptr [eax + 8]
004a1610 mov dword ptr [esi], ecx
004a1612 fadd dword ptr [0x5b23f0]
004a1618 mov dword ptr [esp + 0x14], eax
004a161c mov edx, eax
004a161e mov ecx, 0x3f800000
004a1623 xor eax, eax
004a1625 mov dword ptr [ebp + 0x338], edx
004a162b mov dword ptr [ebx], ecx
004a162d fstp dword ptr [ebp + 0x334]
004a1633 mov dword ptr [ebp + 0x368], eax
004a1639 mov dword ptr [ebp + 0x36c], eax
004a163f mov dword ptr [ebp + 0x370], eax
004a1645 mov dword ptr [ebp + 0x374], ecx
004a164b mov dword ptr [ebp + 0x378], eax
004a1651 mov dword ptr [ebp + 0x37c], eax
004a1657 mov dword ptr [ebp + 0x380], eax
004a165d mov dword ptr [ebp + 0x384], ecx
004a1663 push ebp
004a1664 mov byte ptr [ebp + 0x7e], 0
004a1668 mov byte ptr [ebp + 0x7f], 1
004a166c mov byte ptr [ebp + 0x7d], 1
004a1670 mov byte ptr [ebp + 0x7c], 0
004a1674 call 0x49ae30
004a1679 push ebp
004a167a call 0x4994f0
004a167f push ebp
004a1680 call 0x49af70
004a1685 push ebp
004a1686 call 0x499520
004a168b push 0x6559c8
004a1690 push ebp
004a1691 call 0x4998c0
004a1696 fstp dword ptr [ebp + 0x41c]
004a169c lea eax, [ebp + 0x400]
004a16a2 lea ecx, [ebp + 0x3e8]
004a16a8 push eax
004a16a9 push ecx
004a16aa push ebp
004a16ab call 0x49a900
004a16b0 fld dword ptr [ebp + 0x3b0]
004a16b6 fmul dword ptr [0x5b24e8]
004a16bc xor eax, eax
004a16be add esp, 0x24
004a16c1 mov ax, word ptr [ebp + 0x2c]
004a16c5 lea edx, [esp + 0x24]
004a16c9 mov dword ptr [ebp + 0x460], eax
004a16cf and eax, 0xf
004a16d2 push edx
004a16d3 push ecx
004a16d4 mov dword ptr [ebp + 0x464], eax
004a16da lea eax, [ebp + 0x37c]
004a16e0 fstp dword ptr [esp]
004a16e3 push eax
004a16e4 push 1
004a16e6 call 0x532360
004a16eb fld dword ptr [ebp + 0x3a8]
004a16f1 fmul dword ptr [0x5b25e8]
004a16f7 add esp, 0x10
004a16fa lea eax, [esp + 0x18]
004a16fe push eax
004a16ff push ecx
004a1700 fstp dword ptr [esp]
004a1703 push ebx
004a1704 push 1
004a1706 call 0x532360
004a170b fld dword ptr [ebp + 0x3ac]
004a1711 add esp, 0x10
004a1714 lea ecx, [esp + 0x3c]
004a1718 fchs
004a171a push ecx
004a171b push ecx
004a171c lea eax, [ebp + 0x370]
004a1722 fstp dword ptr [esp]
004a1725 push eax
004a1726 push 1
004a1728 call 0x532360
004a172d lea edx, [esp + 0x40]
004a1731 lea eax, [esp + 0x4c]
004a1735 push edx
004a1736 push eax
004a1737 push esi
004a1738 push 1
004a173a call 0x532300
004a173f lea ecx, [esp + 0x2c]
004a1743 lea edx, [esp + 0x44]
004a1747 push ecx
004a1748 lea eax, [esp + 0x54]
004a174c push edx
004a174d push eax
004a174e push 1
004a1750 call 0x532300
004a1755 lea ecx, [ebp + 0x7f8]
004a175b lea edx, [esp + 0x48]
004a175f push ecx
004a1760 push edx
004a1761 lea eax, [esp + 0x44]
004a1765 push eax
004a1766 push 1
004a1768 call 0x532330
004a176d add esp, 0x40
004a1770 lea ecx, [ebp + 0x8bc]
004a1776 lea edx, [esp + 0x18]
004a177a lea eax, [esp + 0xc]
004a177e push ecx
004a177f push edx
004a1780 push eax
004a1781 push 1
004a1783 call 0x532300
004a1788 lea ecx, [esp + 0x1c]
004a178c lea edx, [esp + 0x34]
004a1790 push ecx
004a1791 lea eax, [esp + 0x44]
004a1795 push edx
004a1796 push eax
004a1797 push 1
004a1799 call 0x532330
004a179e lea ecx, [ebp + 0x980]
004a17a4 lea edx, [esp + 0x38]
004a17a8 push ecx
004a17a9 lea eax, [esp + 0x30]
004a17ad push edx
004a17ae push eax
004a17af push 1
004a17b1 call 0x532330
004a17b6 lea ecx, [ebp + 0xa44]
004a17bc lea edx, [esp + 0x48]
004a17c0 push ecx
004a17c1 lea eax, [esp + 0x40]
004a17c5 push edx
004a17c6 push eax
004a17c7 push 1
004a17c9 call 0x532300
004a17ce add esp, 0x40
004a17d1 push ebp
004a17d2 call 0x49ae30
004a17d7 add esp, 4
004a17da pop esi
004a17db pop ebp
004a17dc pop ebx
004a17dd add esp, 0x3c
004a17e0 ret
004a17e1 nop
004a17e2 nop
004a17e3 nop
004a17e4 nop
004a17e5 nop
004a17e6 nop
004a17e7 nop
004a17e8 nop
004a17e9 nop
004a17ea nop
004a17eb nop
004a17ec nop
004a17ed nop
004a17ee nop
004a17ef nop
004a17f0 mov eax, dword ptr [0x628960]
004a17f5 push ebx
004a17f6 xor ebx, ebx
004a17f8 push edi
004a17f9 mov ecx, dword ptr [eax + 0x34]
004a17fc xor eax, eax
004a17fe cmp ecx, ebx
004a1800 mov dword ptr [0x65807c], eax
004a1805 je 0x4a1816
004a1807 mov eax, dword ptr [ecx + 4]
004a180a mov edx, dword ptr [ecx]
004a180c sub eax, edx
004a180e sar eax, 2
004a1811 mov dword ptr [0x65807c], eax
004a1816 xor edi, edi
004a1818 cmp eax, ebx
004a181a jle 0x4a18b3
004a1820 push ebp
004a1821 push esi
004a1822 mov esi, 0x629550
004a1827 mov ebp, 1
004a182c lea ecx, [esi - 0x368]
004a1832 push 0x5d0d44
004a1837 mov dword ptr [esi - 0x10], edi
004a183a push ecx
004a183b mov dword ptr [esi], ebx
004a183d call 0x5a0fbf
004a1842 mov dword ptr [esi - 0x58c], ebp
004a1848 mov dword ptr [esi - 0x41c], 2
004a1852 mov dword ptr [esi - 0x590], 0xb
004a185c mov dword ptr [esi - 0x584], ebp
004a1862 mov eax, dword ptr [0x65807c]
004a1867 mov dword ptr [esi - 0x580], 0xffffffff
004a1871 mov dword ptr [esi - 0x56c], ebx
004a1877 mov dword ptr [esi - 0x570], ebx
004a187d mov dword ptr [esi - 0x38c], ebx
004a1883 mov dword ptr [esi - 0x588], 0x80
004a188d mov dword ptr [esi - 0x57c], ebx
004a1893 add esp, 8
004a1896 mov dword ptr [esi - 0x578], ebx
004a189c mov dword ptr [esi - 0x574], ebx
004a18a2 inc edi
004a18a3 add esi, 0x594
004a18a9 cmp edi, eax
004a18ab jl 0x4a182c
004a18b1 pop esi
004a18b2 pop ebp
004a18b3 pop edi
004a18b4 pop ebx
004a18b5 ret
004a18b6 nop
004a18b7 nop
004a18b8 nop
004a18b9 nop
004a18ba nop
004a18bb nop
004a18bc nop
004a18bd nop
004a18be nop
004a18bf nop
004a18c0 push ecx
004a18c1 mov dword ptr [esp], 0x800000
004a18c9 mov eax, dword ptr [esp]
004a18cd mov dword ptr [0x6559d8], eax
004a18d2 pop ecx
004a18d3 ret
004a18d4 nop
004a18d5 nop
004a18d6 nop
004a18d7 nop
004a18d8 nop
004a18d9 nop
004a18da nop
004a18db nop
004a18dc nop
004a18dd nop
004a18de nop
004a18df nop
004a18e0 fld dword ptr [0x5b24a8]
004a18e6 fdiv dword ptr [0x6559d8]
004a18ec fstp dword ptr [0x6559d4]
004a18f2 ret
004a18f3 nop
004a18f4 nop
004a18f5 nop
004a18f6 nop
004a18f7 nop
004a18f8 nop
004a18f9 nop
004a18fa nop
004a18fb nop
004a18fc nop
004a18fd nop
004a18fe nop
004a18ff nop
004a1900 sub esp, 8
004a1903 push ebx
004a1904 push ebp
004a1905 push esi
004a1906 mov esi, dword ptr [esp + 0x18]
004a190a push edi
004a190b mov eax, dword ptr [esi + 0x760]
004a1911 fld dword ptr [esi + 0x4a0]
004a1917 fmul dword ptr [eax + 0xf4]
004a191d mov eax, dword ptr [0x606ae0]
004a1922 test eax, eax
004a1924 fmul dword ptr [0x5b25bc]
004a192a fstp dword ptr [esp + 0x1c]
004a192e je 0x4a194d
004a1930 lea ecx, [esi + 0x330]
004a1936 push 0
004a1938 push ecx
004a1939 lea ecx, [esi + 8]
004a193c call 0x473330
004a1941 test ax, ax
004a1944 jne 0x4a194d
004a1946 mov ebp, 1
004a194b jmp 0x4a194f
004a194d xor ebp, ebp
004a194f xor edi, edi
004a1951 lea edx, [esi + 0x838]
004a1957 mov bl, 8
004a1959 mov eax, dword ptr [edx + 0xc]
004a195c mov ecx, dword ptr [esi + 0x760]
004a1962 and eax, 0xf
004a1965 mov ecx, dword ptr [ecx + 0x1c0]
004a196b test ebp, ebp
004a196d je 0x4a199d
004a196f test byte ptr [esi + 0x52c], bl
004a1975 jne 0x4a1980
004a1977 cmp dword ptr [esi + 0xda8], 0
004a197e je 0x4a1989
004a1980 test ecx, ecx
004a1982 jne 0x4a1989
004a1984 mov ecx, 1
004a1989 lea ecx, [ecx + eax*2]
004a198c add eax, ecx
004a198e fld dword ptr [eax*4 + 0x5d0e4c]
004a1995 mov dword ptr [edx], 1
004a199b jmp 0x4a19c7
004a199d test byte ptr [esi + 0x52c], bl
004a19a3 jne 0x4a19ae
004a19a5 cmp dword ptr [esi + 0xda8], 0
004a19ac je 0x4a19b5
004a19ae cmp ecx, 1
004a19b1 jne 0x4a19b5
004a19b3 xor ecx, ecx
004a19b5 lea ecx, [ecx + eax*2]
004a19b8 add eax, ecx
004a19ba fld dword ptr [eax*4 + 0x5d0d50]
004a19c1 mov dword ptr [edx], 0
004a19c7 cmp edi, 2
004a19ca jge 0x4a19e7
004a19cc mov eax, dword ptr [esi + 0x760]
004a19d2 fmul dword ptr [eax + 0xf0]
004a19d8 fmul dword ptr [esp + 0x1c]
004a19dc fmul dword ptr [0x5b23f0]
004a19e2 fstp dword ptr [edx + 0x2c]
004a19e5 jmp 0x4a1a0a
004a19e7 mov ecx, dword ptr [esi + 0x760]
004a19ed fld dword ptr [0x5b24a8]
004a19f3 fsub dword ptr [ecx + 0xf0]
004a19f9 fmul st(1)
004a19fb fmul dword ptr [esp + 0x1c]
004a19ff fmul dword ptr [0x5b23f0]
004a1a05 fstp dword ptr [edx + 0x2c]
004a1a08 fstp st(0)
004a1a0a inc edi
004a1a0b add edx, 0xc4
004a1a11 cmp edi, 4
004a1a14 jl 0x4a1959
004a1a1a mov ecx, dword ptr [esi + 0x760]
004a1a20 mov al, byte ptr [esi + 0xd7f]
004a1a26 fld dword ptr [esi + 0xd54]
004a1a2c fmul dword ptr [ecx + 0xf8]
004a1a32 test al, al
004a1a34 fmul dword ptr [0x5b4a9c]
004a1a3a fmul dword ptr [esp + 0x1c]
004a1a3e fmul dword ptr [0x5b4a98]
004a1a44 fdiv dword ptr [ecx + 0x11c]
004a1a4a jbe 0x4a1a9f
004a1a4c fld dword ptr [esi + 0xd60]
004a1a52 fcomp dword ptr [0x5b23f8]
004a1a58 fnstsw ax
004a1a5a test ah, 0x41
004a1a5d jne 0x4a1a9f
004a1a5f fld dword ptr [esi + 0xdc0]
004a1a65 fcomp dword ptr [0x5b23f8]
004a1a6b fld dword ptr [esi + 0xdc0]
004a1a71 fnstsw ax
004a1a73 test ah, 1
004a1a76 je 0x4a1a7a
004a1a78 fchs
004a1a7a fmul dword ptr [0x5b241c]
004a1a80 fsubr dword ptr [0x5b24a8]
004a1a86 fld dword ptr [0x5b23f8]
004a1a8c fcomp st(1)
004a1a8e fnstsw ax
004a1a90 test ah, 0x41
004a1a93 jne 0x4a1a9d
004a1a95 fstp st(0)
004a1a97 fld dword ptr [0x5b23f8]
004a1a9d fmulp st(1)
004a1a9f fld dword ptr [esi + 0x864]
004a1aa5 fsub st(1)
004a1aa7 fst dword ptr [esp + 0x10]
004a1aab fstp dword ptr [esi + 0x864]
004a1ab1 fld dword ptr [esi + 0x928]
004a1ab7 fsub st(1)
004a1ab9 fst dword ptr [esp + 0x14]
004a1abd fstp dword ptr [esi + 0x928]
004a1ac3 fld st(0)
004a1ac5 fadd dword ptr [esi + 0x9ec]
004a1acb fstp dword ptr [esi + 0x9ec]
004a1ad1 fadd dword ptr [esi + 0xab0]
004a1ad7 fstp dword ptr [esi + 0xab0]
004a1add mov eax, dword ptr [0x6573f8]
004a1ae2 test eax, eax
004a1ae4 je 0x4a1b06
004a1ae6 fld dword ptr [esp + 0x10]
004a1aea fmul dword ptr [0x5b27a4]
004a1af0 fstp dword ptr [esi + 0x864]
004a1af6 fld dword ptr [esp + 0x14]
004a1afa fmul dword ptr [0x5b27a4]
004a1b00 fstp dword ptr [esi + 0x928]
004a1b06 fld dword ptr [esi + 0xd4c]
004a1b0c fmul dword ptr [ecx + 0xf8]
004a1b12 fmul dword ptr [0x5b4a9c]
004a1b18 fmul dword ptr [esp + 0x1c]
004a1b1c fmul dword ptr [0x5b23f4]
004a1b22 fdiv dword ptr [ecx + 0x11c]
004a1b28 fld st(0)
004a1b2a fdiv dword ptr [ecx + 0x130]
004a1b30 fstp dword ptr [esp + 0x1c]
004a1b34 fcom dword ptr [0x5b23f8]
004a1b3a fld dword ptr [esi + 0x864]
004a1b40 fnstsw ax
004a1b42 test ah, 0x41
004a1b45 jne 0x4a1b71
004a1b47 fsub dword ptr [esp + 0x1c]
004a1b4b fstp dword ptr [esi + 0x864]
004a1b51 fld dword ptr [esi + 0x9ec]
004a1b57 fsub dword ptr [esp + 0x1c]
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
004a1d7f fcomp dword ptr [0x5b27a8]
004a1d85 fnstsw ax
004a1d87 test ah, 0x41
004a1d8a jne 0x4a1d96
004a1d8c fstp st(0)
004a1d8e fld dword ptr [esp]
004a1d92 fdiv dword ptr [esp + 0xc]
004a1d96 fld st(0)
004a1d98 fmul dword ptr [ecx + 0x9c]
004a1d9e fstp dword ptr [ecx + 0x90]
004a1da4 fmul dword ptr [ecx + 0xa4]
004a1daa fstp dword ptr [ecx + 0x98]
004a1db0 pop ecx
004a1db1 ret
004a1db2 nop
004a1db3 nop
004a1db4 nop
004a1db5 nop
004a1db6 nop
004a1db7 nop
004a1db8 nop
004a1db9 nop
004a1dba nop
004a1dbb nop
004a1dbc nop
004a1dbd nop
004a1dbe nop
004a1dbf nop
004a1dc0 push ecx
004a1dc1 mov eax, dword ptr [0x6573f8]
004a1dc6 push ebp
004a1dc7 push esi
004a1dc8 mov esi, dword ptr [esp + 0x14]
004a1dcc xor ebp, ebp
004a1dce push edi
004a1dcf fld dword ptr [esi + 0x98]
004a1dd5 test eax, eax
004a1dd7 je 0x4a1e14
004a1dd9 fmul dword ptr [0x5b23f0]
004a1ddf fcom dword ptr [0x5b23f8]
004a1de5 fnstsw ax
004a1de7 test ah, 1
004a1dea je 0x4a1dee
004a1dec fchs
004a1dee fld dword ptr [esi + 0x90]
004a1df4 fcomp dword ptr [0x5b23f8]
004a1dfa fld dword ptr [esi + 0x90]
004a1e00 fnstsw ax
004a1e02 test ah, 1
004a1e05 je 0x4a1e09
004a1e07 fchs
004a1e09 fcom st(1)
004a1e0b fnstsw ax
004a1e0d test ah, 0x41
004a1e10 jne 0x4a1e4f
004a1e12 jmp 0x4a1e4d
004a1e14 fmul dword ptr [0x5b25e8]
004a1e1a fcom dword ptr [0x5b23f8]
004a1e20 fnstsw ax
004a1e22 test ah, 1
004a1e25 je 0x4a1e29
004a1e27 fchs
004a1e29 fld dword ptr [esi + 0x90]
004a1e2f fcomp dword ptr [0x5b23f8]
004a1e35 fld dword ptr [esi + 0x90]
004a1e3b fnstsw ax
004a1e3d test ah, 1
004a1e40 je 0x4a1e44
004a1e42 fchs
004a1e44 fcom st(1)
004a1e46 fnstsw ax
004a1e48 test ah, 0x41
004a1e4b jne 0x4a1e4f
004a1e4d fxch st(1)
004a1e4f fmul dword ptr [0x5b2468]
004a1e55 mov edi, dword ptr [esp + 0x14]
004a1e59 push edi
004a1e5a fadd st(1)
004a1e5c fstp dword ptr [esp + 0x1c]
004a1e60 fstp st(0)
004a1e62 call 0x493980
004a1e67 fmul dword ptr [0x5b3284]
004a1e6d mov ecx, dword ptr [esi + 0xc0]
004a1e73 add esp, 4
004a1e76 test ecx, ecx
004a1e78 fsubr dword ptr [0x5b24a8]
004a1e7e fmul dword ptr [esi + 0xac]
004a1e84 fstp dword ptr [esp + 0x14]
004a1e88 fld dword ptr [esi + 0x98]
004a1e8e fcomp dword ptr [0x5b23f8]
004a1e94 fnstsw ax
004a1e96 je 0x4a1ec8
004a1e98 fld dword ptr [esi + 0x98]
004a1e9e test ah, 1
004a1ea1 je 0x4a1ea5
004a1ea3 fchs
004a1ea5 fcomp dword ptr [esp + 0x14]
004a1ea9 mov edx, 2
004a1eae fnstsw ax
004a1eb0 test ah, 0x41
004a1eb3 jne 0x4a1ebe
004a1eb5 cmp byte ptr [edi + 0xd7f], 0x80
004a1ebc ja 0x4a1ef6
004a1ebe cmp dword ptr [edi + 0xdbc], edx
004a1ec4 jne 0x4a1efb
004a1ec6 jmp 0x4a1ef6
004a1ec8 fld dword ptr [esi + 0x98]
004a1ece test ah, 1
004a1ed1 je 0x4a1ed5
004a1ed3 fchs
004a1ed5 fcomp dword ptr [esp + 0x14]
004a1ed9 mov edx, 2
004a1ede fnstsw ax
004a1ee0 test ah, 0x41
004a1ee3 jne 0x4a1eee
004a1ee5 cmp byte ptr [edi + 0xd7f], 0x80
004a1eec ja 0x4a1ef6
004a1eee cmp dword ptr [edi + 0xdb8], edx
004a1ef4 jne 0x4a1efb
004a1ef6 mov ebp, 1
004a1efb test ecx, ecx
004a1efd jne 0x4a1f0e
004a1eff cmp ebp, 1
004a1f02 jne 0x4a1f0e
004a1f04 mov dword ptr [esp + 0xc], 0x40800000
004a1f0c jmp 0x4a1f25
004a1f0e mov eax, dword ptr [edi + 0x760]
004a1f14 mov eax, dword ptr [eax + 0x1c0]
004a1f1a fld dword ptr [eax*4 + 0x5d0f58]
004a1f21 fstp dword ptr [esp + 0xc]
004a1f25 fld dword ptr [esp + 0x18]
004a1f29 fcomp dword ptr [esp + 0x14]
004a1f2d fnstsw ax
004a1f2f test ah, 0x41
004a1f32 jne 0x4a205f
004a1f38 mov eax, dword ptr [edi + 0x558]
004a1f3e cmp dword ptr [eax + 0x20], 0
004a1f42 je 0x4a1f70
004a1f44 test ecx, ecx
004a1f46 jne 0x4a1f70
004a1f48 fld dword ptr [edi + 0xdc0]
004a1f4e fcomp dword ptr [0x5b23f8]
004a1f54 fld dword ptr [edi + 0xdc0]
004a1f5a fnstsw ax
004a1f5c test ah, 1
004a1f5f je 0x4a1f63
004a1f61 fchs
004a1f63 fcomp dword ptr [0x5b2638]
004a1f69 fnstsw ax
004a1f6b test ah, 1
004a1f6e jne 0x4a1f91
004a1f70 mov eax, dword ptr [edi + 0xda8]
004a1f76 test eax, eax
004a1f78 je 0x4a1fd6
004a1f7a cmp dword ptr [esi + 0x8c], 1
004a1f81 jg 0x4a1f91
004a1f83 mov eax, dword ptr [edi + 0x760]
004a1f89 cmp dword ptr [eax + 0x1c0], edx
004a1f8f jne 0x4a1fd6
004a1f91 fld dword ptr [esp + 0x14]
004a1f95 fdiv dword ptr [esp + 0x18]
004a1f99 mov dword ptr [esi + 0xb8], 0
004a1fa3 mov al, byte ptr [edi + 0xd82]
004a1fa9 cmp al, dl
004a1fab jg 0x4a1fb7
004a1fad mov eax, dword ptr [edi + 0xda8]
004a1fb3 test eax, eax
004a1fb5 je 0x4a1fc5
004a1fb7 fld st(0)
004a1fb9 fmul dword ptr [esi + 0x90]
004a1fbf fstp dword ptr [esi + 0x90]
004a1fc5 fmul dword ptr [esi + 0x98]
004a1fcb fstp dword ptr [esi + 0x98]
004a1fd1 jmp 0x4a2069
004a1fd6 fld dword ptr [esp + 0x18]
004a1fda fsub dword ptr [esp + 0x14]
004a1fde fld st(0)
004a1fe0 fdiv dword ptr [esp + 0xc]
004a1fe4 fld dword ptr [esp + 0x14]
004a1fe8 fdiv dword ptr [esp + 0xc]
004a1fec fst dword ptr [esp + 0xc]
004a1ff0 fcomp st(1)
004a1ff2 fnstsw ax
004a1ff4 test ah, 0x41
004a1ff7 je 0x4a1fff
004a1ff9 fstp st(0)
004a1ffb fld dword ptr [esp + 0xc]
004a1fff fld dword ptr [esp + 0x14]
004a2003 fsub st(1)
004a2005 test ecx, ecx
004a2007 fdiv dword ptr [esp + 0x18]
004a200b fstp dword ptr [esp + 0x14]
004a200f fstp st(0)
004a2011 je 0x4a201b
004a2013 fmul dword ptr [0x5b23f0]
004a2019 jmp 0x4a2021
004a201b fmul dword ptr [0x5b240c]
004a2021 fld dword ptr [esi + 0xb8]
004a2027 fmul dword ptr [0x5b2600]
004a202d fadd st(1)
004a202f fmul dword ptr [0x5b2468]
004a2035 fstp dword ptr [esi + 0xb8]
004a203b fstp st(0)
004a203d fld dword ptr [esp + 0x14]
004a2041 fmul dword ptr [esi + 0x90]
004a2047 fstp dword ptr [esi + 0x90]
004a204d fld dword ptr [esp + 0x14]
004a2051 fmul dword ptr [esi + 0x98]
004a2057 fstp dword ptr [esi + 0x98]
004a205d jmp 0x4a2069
004a205f mov dword ptr [esi + 0xb8], 0
004a2069 test ecx, ecx
004a206b jne 0x4a2089
004a206d cmp ebp, 1
004a2070 jne 0x4a2089
004a2072 mov ecx, dword ptr [edi + 0x558]
004a2078 mov eax, dword ptr [ecx + 0x20]
004a207b test eax, eax
004a207d jne 0x4a2089
004a207f mov edx, dword ptr [esp + 0x18]
004a2083 mov dword ptr [esi + 0xb8], edx
004a2089 fld dword ptr [esi + 0xb8]
004a208f fcom dword ptr [0x5b24a8]
004a2095 fnstsw ax
004a2097 test ah, 0x41
004a209a jne 0x4a20a4
004a209c fstp st(0)
004a209e fld dword ptr [0x5b24a8]
004a20a4 fst dword ptr [esi + 0xb8]
004a20aa mov eax, dword ptr [edi + 0x558]
004a20b0 mov ecx, dword ptr [eax + 0x20]
004a20b3 test ecx, ecx
004a20b5 je 0x4a20c8
004a20b7 fmul dword ptr [0x5b23f0]
004a20bd pop edi
004a20be fstp dword ptr [esi + 0xb8]
004a20c4 pop esi
004a20c5 pop ebp
004a20c6 pop ecx
004a20c7 ret
004a20c8 pop edi
004a20c9 pop esi
004a20ca fstp st(0)
004a20cc pop ebp
004a20cd pop ecx
004a20ce ret
004a20cf nop
004a20d0 sub esp, 0xc
004a20d3 push ebx
004a20d4 push ebp
004a20d5 push esi
004a20d6 mov esi, dword ptr [esp + 0x20]
004a20da push edi
004a20db mov edi, dword ptr [esp + 0x20]
004a20df mov eax, dword ptr [esi + 0xac]
004a20e5 xor ecx, ecx
004a20e7 mov edx, dword ptr [edi + 0x760]
004a20ed mov dword ptr [esp + 0x18], eax
004a20f1 xor ebp, ebp
004a20f3 fld dword ptr [edx + 0xfc]
004a20f9 fmul dword ptr [esi + 0xb4]
004a20ff mov dword ptr [esi + 0xb8], ecx
004a2105 mov dword ptr [esi + 0xbc], ecx
004a210b mov dword ptr [esi + 0x98], ecx
004a2111 mov dword ptr [esi + 0x90], ecx
004a2117 fmul dword ptr [0x5b4aa4]
004a211d fstp dword ptr [esp + 0x20]
004a2121 fld dword ptr [esp + 0x20]
004a2125 fcomp dword ptr [0x5b23f8]
004a212b fnstsw ax
004a212d test ah, 0x40
004a2130 jne 0x4a2199
004a2132 fld dword ptr [esp + 0x20]
004a2136 fmul dword ptr [0x5b2640]
004a213c mov eax, dword ptr [esi + 0xa4]
004a2142 mov ecx, dword ptr [esi + 0x9c]
004a2148 mov dword ptr [esp + 0x14], eax
004a214c mov dword ptr [esp + 0x10], ecx
004a2150 fstp dword ptr [esp + 0x24]
004a2154 mov ebx, dword ptr [esp + 0x24]
004a2158 push ebx
004a2159 call 0x5327e0
004a215e fstp dword ptr [esp + 0x28]
004a2162 push ebx
004a2163 call 0x5327f0
004a2168 fld st(0)
004a216a fmul dword ptr [esp + 0x18]
004a216e fld dword ptr [esp + 0x2c]
004a2172 fmul dword ptr [esp + 0x1c]
004a2176 add esp, 8
004a2179 xor ecx, ecx
004a217b fsubp st(1)
004a217d fstp dword ptr [esi + 0x9c]
004a2183 fld dword ptr [esp + 0x24]
004a2187 fmul dword ptr [esp + 0x10]
004a218b fxch st(1)
004a218d fmul dword ptr [esp + 0x14]
004a2191 faddp st(1)
004a2193 fstp dword ptr [esi + 0xa4]
004a2199 fld dword ptr [esi + 0xa8]
004a219f fcomp dword ptr [0x5b23f8]
004a21a5 mov ebx, 1
004a21aa fnstsw ax
004a21ac test bl, ah
004a21ae je 0x4a2204
004a21b0 fld dword ptr [esi + 0xa4]
004a21b6 fcomp dword ptr [0x5b23f8]
004a21bc fnstsw ax
004a21be test bl, ah
004a21c0 je 0x4a2204
004a21c2 fld dword ptr [0x628fb0]
004a21c8 fcomp dword ptr [0x5b2468]
004a21ce fnstsw ax
004a21d0 test ah, 0x41
004a21d3 jne 0x4a21e3
004a21d5 mov al, byte ptr [edi + 0xd82]
004a21db test al, al
004a21dd je 0x4a226c
004a21e3 fld dword ptr [esi + 0xa4]
004a21e9 fld dword ptr [esi + 0xa8]
004a21ef fst dword ptr [esp + 0x24]
004a21f3 fcomp st(1)
004a21f5 fnstsw ax
004a21f7 test ah, 0x41
004a21fa jne 0x4a2264
004a21fc fstp st(0)
004a21fe fld dword ptr [esp + 0x24]
004a2202 jmp 0x4a2264
004a2204 fld dword ptr [esi + 0xa8]
004a220a fcomp dword ptr [0x5b23f8]
004a2210 fnstsw ax
004a2212 test ah, 0x41
004a2215 jne 0x4a226c
004a2217 fld dword ptr [esi + 0xa4]
004a221d fcomp dword ptr [0x5b23f8]
004a2223 fnstsw ax
004a2225 test ah, 0x41
004a2228 jne 0x4a226c
004a222a fld dword ptr [0x628fb0]
004a2230 fcomp dword ptr [0x5b2468]
004a2236 fnstsw ax
004a2238 test ah, 0x41
004a223b jne 0x4a2245
004a223d cmp byte ptr [edi + 0xd82], bl
004a2243 jg 0x4a226c
004a2245 fld dword ptr [esi + 0xa4]
004a224b fld dword ptr [esi + 0xa8]
004a2251 fst dword ptr [esp + 0x24]
004a2255 fcomp st(1)
004a2257 fnstsw ax
004a2259 test ah, 0x41
004a225c je 0x4a2264
004a225e fstp st(0)
004a2260 fld dword ptr [esp + 0x24]
004a2264 fstp dword ptr [esi + 0xa8]
004a226a mov ebp, ebx
004a226c mov edx, dword ptr [edi + 0x760]
004a2272 cmp ebp, ecx
004a2274 fld dword ptr [edx + 0xf4]
004a227a fmul dword ptr [esi + 0xa8]
004a2280 fstp dword ptr [esp + 0x24]
004a2284 mov eax, dword ptr [esp + 0x24]
004a2288 mov dword ptr [esi + 0xa8], eax
004a228e je 0x4a22b4
004a2290 fld dword ptr [esp + 0x24]
004a2294 fcomp dword ptr [0x5b23f8]
004a229a fld dword ptr [esp + 0x24]
004a229e fnstsw ax
004a22a0 test ah, 1
004a22a3 je 0x4a22a7
004a22a5 fchs
004a22a7 fcomp dword ptr [esi + 0xac]
004a22ad fnstsw ax
004a22af test ah, 0x41
004a22b2 je 0x4a22fa
004a22b4 mov al, byte ptr [edi + 0xd85]
004a22ba test al, al
004a22bc je 0x4a240f
004a22c2 cmp dword ptr [esi + 0xc0], ecx
004a22c8 jne 0x4a240f
004a22ce fld dword ptr [edi + 0xd60]
004a22d4 fcomp dword ptr [0x5b23f8]
004a22da fld dword ptr [edi + 0xd60]
004a22e0 fnstsw ax
004a22e2 test ah, 1
004a22e5 je 0x4a22e9
004a22e7 fchs
004a22e9 fcomp dword ptr [0x5b23f0]
004a22ef fnstsw ax
004a22f1 test ah, 0x41
004a22f4 jne 0x4a240f
004a22fa mov al, byte ptr [edi + 0xd85]
004a2300 test al, al
004a2302 jne 0x4a2494
004a2308 mov edx, dword ptr [edi + 0x558]
004a230e cmp dword ptr [edx + 0x24], ecx
004a2311 jne 0x4a238e
004a2313 fld dword ptr [0x5b26a8]
004a2319 fsub dword ptr [esi + 0xac]
004a231f fadd st(0), st(0)
004a2321 fcomp dword ptr [edi + 0xd60]
004a2327 fnstsw ax
004a2329 test ah, 1
004a232c jne 0x4a238e
004a232e cmp byte ptr [edi + 0xd80], 0xec
004a2335 jb 0x4a238e
004a2337 fld dword ptr [edi + 0xd60]
004a233d fcomp dword ptr [0x5b23f8]
004a2343 fld dword ptr [edi + 0xd60]
004a2349 fnstsw ax
004a234b test ah, 1
004a234e je 0x4a2352
004a2350 fchs
004a2352 fcomp dword ptr [0x5b2400]
004a2358 fnstsw ax
004a235a test ah, 1
004a235d je 0x4a2367
004a235f cmp dword ptr [edi + 0xdb8], ecx
004a2365 je 0x4a238e
004a2367 cmp dword ptr [edi + 0xda8], ecx
004a236d je 0x4a2494
004a2373 cmp dword ptr [esi + 0x8c], ebx
004a2379 jg 0x4a238e
004a237b mov eax, dword ptr [edi + 0x760]
004a2381 cmp dword ptr [eax + 0x1c0], 2
004a2388 jne 0x4a2494
004a238e fld dword ptr [esp + 0x24]
004a2392 fcomp dword ptr [esi + 0xac]
004a2398 fnstsw ax
004a239a test ah, 0x41
004a239d jne 0x4a23ad
004a239f mov edx, dword ptr [esi + 0xac]
004a23a5 mov dword ptr [esi + 0xa8], edx
004a23ab jmp 0x4a23cc
004a23ad fld dword ptr [esi + 0xac]
004a23b3 fchs
004a23b5 fld dword ptr [esp + 0x24]
004a23b9 fcomp st(1)
004a23bb fnstsw ax
004a23bd test ah, 1
004a23c0 je 0x4a23ca
004a23c2 fstp dword ptr [esi + 0xa8]
004a23c8 jmp 0x4a23cc
004a23ca fstp st(0)
004a23cc mov eax, dword ptr [edi + 0x558]
004a23d2 cmp dword ptr [eax + 0x24], ecx
004a23d5 je 0x4a240f
004a23d7 fld dword ptr [edi + 0xd60]
004a23dd fcomp dword ptr [0x5b24dc]
004a23e3 fnstsw ax
004a23e5 test ah, 1
004a23e8 je 0x4a240f
004a23ea mov edx, dword ptr [0x606ac4]
004a23f0 and edx, 0x80000003
004a23f6 jns 0x4a23fd
004a23f8 dec edx
004a23f9 or edx, 0xfffffffc
004a23fc inc edx
004a23fd jne 0x4a2409
004a23ff mov eax, dword ptr [esp + 0x28]
004a2403 push eax
004a2404 jmp 0x4a2499
004a2409 mov dword ptr [esi + 0xb8], ecx
004a240f fld dword ptr [esi + 0xa4]
004a2415 fcomp dword ptr [0x5b23f8]
004a241b fld dword ptr [esi + 0xa4]
004a2421 fnstsw ax
004a2423 test ah, 1
004a2426 je 0x4a242a
004a2428 fchs
004a242a fcomp dword ptr [0x5b23f8]
004a2430 fnstsw ax
004a2432 test ah, 0x40
004a2435 jne 0x4a24d8
004a243b fld dword ptr [esi + 0xa4]
004a2441 fmul dword ptr [0x5b2448]
004a2447 mov edx, dword ptr [esi + 0x9c]
004a244d push ecx
004a244e fstp dword ptr [esp]
004a2451 push edx
004a2452 call 0x532860
004a2457 fld dword ptr [esi + 0xa4]
004a245d fcomp dword ptr [0x5b23f8]
004a2463 add esp, 8
004a2466 fnstsw ax
004a2468 test ah, 0x41
004a246b jne 0x4a24ca
004a246d fld dword ptr [esi + 0x9c]
004a2473 fcomp dword ptr [0x5b23f8]
004a2479 fnstsw ax
004a247b test ah, 0x41
004a247e jne 0x4a24b1
004a2480 fsubr dword ptr [0x5b23f0]
004a2486 xor ecx, ecx
004a2488 fmul dword ptr [0x5b26b0]
004a248e fst dword ptr [esp + 0x10]
004a2492 jmp 0x4a24e2
004a2494 mov ecx, dword ptr [esp + 0x28]
004a2498 push ecx
004a2499 push esi
004a249a push edi
004a249b call 0x4a1c70
004a24a0 add esp, 0xc
004a24a3 mov dword ptr [esi + 0xbc], ebx
004a24a9 pop edi
004a24aa pop esi
004a24ab pop ebp
004a24ac pop ebx
004a24ad add esp, 0xc
004a24b0 ret
004a24b1 fld dword ptr [esi + 0x9c]
004a24b7 fcomp dword ptr [0x5b23f8]
004a24bd fnstsw ax
004a24bf test ah, 1
004a24c2 je 0x4a24ca
004a24c4 fsubr dword ptr [0x5b2448]
004a24ca fmul dword ptr [0x5b26b0]
004a24d0 xor ecx, ecx
004a24d2 fst dword ptr [esp + 0x10]
004a24d6 jmp 0x4a24e2
004a24d8 fld dword ptr [0x5b23f8]
004a24de fst dword ptr [esp + 0x10]
004a24e2 fcom dword ptr [0x5b23f8]
004a24e8 cmp dword ptr [esi + 0xc0], ecx
004a24ee fnstsw ax
004a24f0 je 0x4a25f3
004a24f6 test ah, 1
004a24f9 je 0x4a24fd
004a24fb fchs
004a24fd fcom dword ptr [0x5b26a8]
004a2503 fnstsw ax
004a2505 test ah, 0x41
004a2508 jne 0x4a2512
004a250a fstp st(0)
004a250c fld dword ptr [0x5b26a8]
004a2512 fmul dword ptr [esp + 0x18]
004a2516 fmul dword ptr [0x5b49b0]
004a251c fld dword ptr [esp + 0x10]
004a2520 fcomp dword ptr [0x5b23f8]
004a2526 fnstsw ax
004a2528 test ah, 1
004a252b je 0x4a252f
004a252d fchs
004a252f fst dword ptr [esi + 0x90]
004a2535 fld dword ptr [esi + 0x9c]
004a253b fcomp dword ptr [0x5b23f8]
004a2541 fld dword ptr [esi + 0x9c]
004a2547 fnstsw ax
004a2549 test ah, 1
004a254c je 0x4a2550
004a254e fchs
004a2550 fld dword ptr [esi + 0xa4]
004a2556 fcomp dword ptr [0x5b23f8]
004a255c fld dword ptr [esi + 0xa4]
004a2562 fnstsw ax
004a2564 test ah, 1
004a2567 je 0x4a256b
004a2569 fchs
004a256b fadd st(1)
004a256d fcomp dword ptr [0x5b2644]
004a2573 fnstsw ax
004a2575 test ah, 1
004a2578 fstp st(0)
004a257a je 0x4a26be
004a2580 fld dword ptr [esi + 0x9c]
004a2586 fcomp dword ptr [0x5b23f8]
004a258c fnstsw ax
004a258e fcom dword ptr [0x5b23f8]
004a2594 test ah, 0x41
004a2597 fnstsw ax
004a2599 jne 0x4a25c6
004a259b test ah, 1
004a259e je 0x4a25a2
004a25a0 fchs
004a25a2 fld dword ptr [esi + 0x9c]
004a25a8 fst dword ptr [esp + 0x24]
004a25ac fcomp st(1)
004a25ae fnstsw ax
004a25b0 test ah, 0x41
004a25b3 je 0x4a25bb
004a25b5 fstp st(0)
004a25b7 fld dword ptr [esp + 0x24]
004a25bb fstp dword ptr [esi + 0x90]
004a25c1 jmp 0x4a26c0
004a25c6 test ah, 1
004a25c9 je 0x4a25cd
004a25cb fchs
004a25cd fchs
004a25cf fld dword ptr [esi + 0x9c]
004a25d5 fst dword ptr [esp + 0x24]
004a25d9 fcomp st(1)
004a25db fnstsw ax
004a25dd test ah, 0x41
004a25e0 jne 0x4a25e8
004a25e2 fstp st(0)
004a25e4 fld dword ptr [esp + 0x24]
004a25e8 fstp dword ptr [esi + 0x90]
004a25ee jmp 0x4a26c0
004a25f3 test ah, 1
004a25f6 je 0x4a25fa
004a25f8 fchs
004a25fa fstp dword ptr [esp + 0x24]
004a25fe fld dword ptr [esp + 0x24]
004a2602 fcomp dword ptr [0x5b24a8]
004a2608 fnstsw ax
004a260a test ah, 0x41
004a260d jne 0x4a268c
004a260f fld dword ptr [esp + 0x24]
004a2613 fld dword ptr [esp + 0x24]
004a2617 fcomp dword ptr [0x5b2580]
004a261d fnstsw ax
004a261f test ah, 0x41
004a2622 jne 0x4a262c
004a2624 fstp st(0)
004a2626 fld dword ptr [0x5b2580]
004a262c fmul dword ptr [esp + 0x18]
004a2630 fmul dword ptr [0x5b23f0]
004a2636 fld dword ptr [esp + 0x10]
004a263a fcomp dword ptr [0x5b23f8]
004a2640 fnstsw ax
004a2642 test ah, 1
004a2645 je 0x4a2649
004a2647 fchs
004a2649 fld dword ptr [esi + 0x9c]
004a264f fcomp dword ptr [0x5b23f8]
004a2655 fnstsw ax
004a2657 fcom dword ptr [0x5b23f8]
004a265d test ah, 0x41
004a2660 fnstsw ax
004a2662 jne 0x4a2694
004a2664 test ah, 1
004a2667 je 0x4a266b
004a2669 fchs
004a266b fld dword ptr [esi + 0x9c]
004a2671 fst dword ptr [esp + 0x24]
004a2675 fcomp st(1)
004a2677 fnstsw ax
004a2679 test ah, 0x41
004a267c je 0x4a2684
004a267e fstp st(0)
004a2680 fld dword ptr [esp + 0x24]
004a2684 fstp dword ptr [esi + 0x90]
004a268a jmp 0x4a26c0
004a268c fld dword ptr [0x5b24a8]
004a2692 jmp 0x4a262c
004a2694 test ah, 1
004a2697 je 0x4a269b
004a2699 fchs
004a269b fchs
004a269d fld dword ptr [esi + 0x9c]
004a26a3 fst dword ptr [esp + 0x24]
004a26a7 fcomp st(1)
004a26a9 fnstsw ax
004a26ab test ah, 0x41
004a26ae jne 0x4a26b6
004a26b0 fstp st(0)
004a26b2 fld dword ptr [esp + 0x24]
004a26b6 fstp dword ptr [esi + 0x90]
004a26bc jmp 0x4a26c0
004a26be fstp st(0)
004a26c0 mov eax, dword ptr [esi + 0xa8]
004a26c6 mov dword ptr [esi + 0x94], ecx
004a26cc mov ecx, dword ptr [esp + 0x28]
004a26d0 mov dword ptr [esi + 0x98], eax
004a26d6 push ecx
004a26d7 push esi
004a26d8 push edi
004a26d9 call 0x4a1dc0
004a26de mov eax, dword ptr [0x6573f8]
004a26e3 add esp, 0xc
004a26e6 test eax, eax
004a26e8 je 0x4a2706
004a26ea mov eax, dword ptr [esi + 0xc0]
004a26f0 test eax, eax
004a26f2 je 0x4a2706
004a26f4 fld dword ptr [esi + 0x90]
004a26fa fmul dword ptr [0x5b2480]
004a2700 fstp dword ptr [esi + 0x90]
004a2706 fld dword ptr [esp + 0x20]
004a270a fcomp dword ptr [0x5b23f8]
004a2710 fnstsw ax
004a2712 test ah, 0x40
004a2715 jne 0x4a277a
004a2717 fld dword ptr [esp + 0x20]
004a271b fmul dword ptr [0x5b4aa0]
004a2721 mov edx, dword ptr [esi + 0x98]
004a2727 mov eax, dword ptr [esi + 0x90]
004a272d mov dword ptr [esp + 0x28], edx
004a2731 mov dword ptr [esp + 0x18], eax
004a2735 fstp dword ptr [esp + 0x24]
004a2739 mov edi, dword ptr [esp + 0x24]
004a273d push edi
004a273e call 0x5327e0
004a2743 fstp dword ptr [esp + 0x28]
004a2747 push edi
004a2748 call 0x5327f0
004a274d fld st(0)
004a274f fmul dword ptr [esp + 0x20]
004a2753 fld dword ptr [esp + 0x2c]
004a2757 fmul dword ptr [esp + 0x30]
004a275b add esp, 8
004a275e fsubp st(1)
004a2760 fstp dword ptr [esi + 0x90]
004a2766 fmul dword ptr [esp + 0x28]
004a276a fld dword ptr [esp + 0x24]
004a276e fmul dword ptr [esp + 0x18]
004a2772 faddp st(1)
004a2774 fstp dword ptr [esi + 0x98]
004a277a pop edi
004a277b pop esi
004a277c pop ebp
004a277d pop ebx
004a277e add esp, 0xc
004a2781 ret
004a2782 nop
004a2783 nop
004a2784 nop
004a2785 nop
004a2786 nop
004a2787 nop
004a2788 nop
004a2789 nop
004a278a nop
004a278b nop
004a278c nop
004a278d nop
004a278e nop
004a278f nop
004a2790 push ebp
004a2791 mov ebp, esp
004a2793 push ecx
004a2794 push ebx
004a2795 push esi
004a2796 mov esi, dword ptr [ebp + 8]
004a2799 push edi
004a279a xor ebx, ebx
004a279c lea ecx, [esi + 0x840]
004a27a2 cmp dword ptr [esi + 0xdac], 1
004a27a9 jne 0x4a27bf
004a27ab mov eax, dword ptr [esi + 0x760]
004a27b1 fld dword ptr [esi + 0x35c]
004a27b7 fdiv dword ptr [eax + 0x148]
004a27bd jmp 0x4a282f
004a27bf mov eax, dword ptr [ecx + 0x34]
004a27c2 test eax, eax
004a27c4 jne 0x4a2839
004a27c6 xor edi, edi
004a27c8 test ebx, ebx
004a27ca je 0x4a27d1
004a27cc cmp ebx, 1
004a27cf jne 0x4a27d6
004a27d1 mov edi, 1
004a27d6 mov edx, dword ptr [esi + 0x760]
004a27dc fld dword ptr [edx + 0x5c]
004a27df fcomp dword ptr [0x5b27a8]
004a27e5 fnstsw ax
004a27e7 test ah, 1
004a27ea je 0x4a27f0
004a27ec test edi, edi
004a27ee jne 0x4a280e
004a27f0 fld dword ptr [edx + 0x5c]
004a27f3 fcomp dword ptr [0x5b3f80]
004a27f9 fnstsw ax
004a27fb test ah, 0x41
004a27fe jne 0x4a2804
004a2800 test edi, edi
004a2802 je 0x4a280e
004a2804 mov al, byte ptr [esi + 0xd82]
004a280a cmp al, 1
004a280c jne 0x4a281c
004a280e fld dword ptr [esi + 0xd60]
004a2814 fdiv dword ptr [edx + 0x148]
004a281a jmp 0x4a282f
004a281c movsx eax, al
004a281f fld dword ptr [edx + eax*4 + 0x60]
004a2823 fmul dword ptr [edx + 0x148]
004a2829 fdivr dword ptr [esi + 0xdb4]
004a282f fmul dword ptr [0x5b2828]
004a2835 fadd dword ptr [ecx]
004a2837 fstp dword ptr [ecx]
004a2839 fld dword ptr [ecx]
004a283b fcomp dword ptr [0x5b24a8]
004a2841 fnstsw ax
004a2843 test ah, 0x41
004a2846 jne 0x4a285a
004a2848 mov edx, dword ptr [ecx]
004a284a mov dword ptr [ebp + 8], edx
004a284d fld dword ptr [ebp + 8]
004a2850 fistp dword ptr [ebp - 4]
004a2853 fild dword ptr [ebp - 4]
004a2856 fsubr dword ptr [ecx]
004a2858 fstp dword ptr [ecx]
004a285a inc ebx
004a285b add ecx, 0xc4
004a2861 cmp ebx, 4
004a2864 jl 0x4a27a2
004a286a pop edi
004a286b pop esi
004a286c pop ebx
004a286d mov esp, ebp
004a286f pop ebp
004a2870 ret
004a2871 nop
004a2872 nop
004a2873 nop
004a2874 nop
004a2875 nop
004a2876 nop
004a2877 nop
004a2878 nop
004a2879 nop
004a287a nop
004a287b nop
004a287c nop
004a287d nop
004a287e nop
004a287f nop
004a2880 push ecx
004a2881 push ebx
004a2882 push esi
004a2883 push edi
004a2884 mov edi, dword ptr [esp + 0x14]
004a2888 xor ebx, ebx
004a288a lea esi, [edi + 0x844]
004a2890 cmp ebx, 2
004a2893 jge 0x4a28a7
004a2895 mov dword ptr [esp + 0xc], 0x3dcccccd
004a289d mov dword ptr [esp + 0x14], 0x3f8e353f
004a28a5 jmp 0x4a28b7
004a28a7 mov dword ptr [esp + 0xc], 0x3f000000
004a28af mov dword ptr [esp + 0x14], 0x40000000
004a28b7 mov eax, dword ptr [esi]
004a28b9 cmp eax, 9
004a28bc jne 0x4a28e0
004a28be mov eax, dword ptr [edi + 0x35c]
004a28c4 push 0x3f800000
004a28c9 push 0
004a28cb lea ecx, [edi + 0x348]
004a28d1 push eax
004a28d2 push ecx
004a28d3 push 9
004a28d5 lea edx, [esi - 0x4c]
004a28d8 push 0x3f333333
004a28dd push edx
004a28de jmp 0x4a2930
004a28e0 cmp eax, 6
004a28e3 je 0x4a2910
004a28e5 mov ecx, dword ptr [esi - 0xc]
004a28e8 test ecx, ecx
004a28ea je 0x4a28f1
004a28ec cmp eax, 1
004a28ef je 0x4a2910
004a28f1 mov ecx, dword ptr [esp + 0x14]
004a28f5 mov edx, dword ptr [esp + 0xc]
004a28f9 push ecx
004a28fa mov ecx, dword ptr [edi + 0x35c]
004a2900 push edx
004a2901 lea edx, [edi + 0x348]
004a2907 push ecx
004a2908 push edx
004a2909 push eax
004a290a mov eax, dword ptr [esi + 0x2c]
004a290d push eax
004a290e jmp 0x4a292c
004a2910 mov edx, dword ptr [edi + 0x35c]
004a2916 push 0x3f800000
004a291b push 0
004a291d lea eax, [edi + 0x348]
004a2923 push edx
004a2924 push eax
004a2925 push 6
004a2927 push 0x3f333333
004a292c lea ecx, [esi - 0x4c]
004a292f push ecx
004a2930 mov ecx, dword ptr [esi - 0x8c]
004a2936 call 0x478f30
004a293b inc ebx
004a293c add esi, 0xc4
004a2942 cmp ebx, 4
004a2945 jl 0x4a2890
004a294b pop edi
004a294c pop esi
004a294d pop ebx
004a294e pop ecx
004a294f ret
004a2950 push ecx
004a2951 push esi
004a2952 push 0x5cc7f8
004a2957 push 0x657444
004a295c mov dword ptr [esp + 0xc], 0x3f800000
004a2964 call 0x5ae3c0
004a2969 add esp, 8
004a296c test eax, eax
004a296e jne 0x4a29c9
004a2970 mov esi, dword ptr [esp + 0xc]
004a2974 push 0x5d0d2c
004a2979 push esi
004a297a call 0x5ae3c0
004a297f add esp, 8
004a2982 test eax, eax
004a2984 je 0x4a29c0
004a2986 push 0x5d0d38
004a298b push esi
004a298c call 0x5ae3c0
004a2991 add esp, 8
004a2994 test eax, eax
004a2996 je 0x4a29c0
004a2998 push 0x5d0d34
004a299d push esi
004a299e call 0x5ae3c0
004a29a3 add esp, 8
004a29a6 test eax, eax
004a29a8 je 0x4a29c0
004a29aa push 0x5d0d30
004a29af push esi
004a29b0 call 0x5ae3c0
004a29b5 add esp, 8
004a29b8 test eax, eax
004a29ba jne 0x4a2bb8
004a29c0 fld dword ptr [0x5b25e0]
004a29c6 pop esi
004a29c7 pop ecx
004a29c8 ret
004a29c9 push 0x5cf760
004a29ce push 0x657444
004a29d3 call 0x5ae3c0
004a29d8 add esp, 8
004a29db test eax, eax
004a29dd jne 0x4a2ab3
004a29e3 mov esi, dword ptr [esp + 0xc]
004a29e7 push 0x5d0d2c
004a29ec push esi
004a29ed call 0x5ae3c0
004a29f2 add esp, 8
004a29f5 test eax, eax
004a29f7 je 0x4a2aaa
004a29fd push 0x5d0d38
004a2a02 push esi
004a2a03 call 0x5ae3c0
004a2a08 add esp, 8
004a2a0b test eax, eax
004a2a0d je 0x4a2aaa
004a2a13 push 0x5d0d34
004a2a18 push esi
004a2a19 call 0x5ae3c0
004a2a1e add esp, 8
004a2a21 test eax, eax
004a2a23 je 0x4a2aaa
004a2a29 push 0x5d0d30
004a2a2e push esi
004a2a2f call 0x5ae3c0
004a2a34 add esp, 8
004a2a37 test eax, eax
004a2a39 je 0x4a2aaa
004a2a3b push 0x5d0fa8
004a2a40 push esi
004a2a41 call 0x5ae3c0
004a2a46 add esp, 8
004a2a49 test eax, eax
004a2a4b je 0x4a29c0
004a2a51 push 0x5d0fa0
004a2a56 push esi
004a2a57 call 0x5ae3c0
004a2a5c add esp, 8
004a2a5f test eax, eax
004a2a61 je 0x4a29c0
004a2a67 push 0x5d0f9c
004a2a6c push esi
004a2a6d call 0x5ae3c0
004a2a72 add esp, 8
004a2a75 test eax, eax
004a2a77 je 0x4a2aa1
004a2a79 push 0x5d0f98
004a2a7e push esi
004a2a7f call 0x5ae3c0
004a2a84 add esp, 8
004a2a87 test eax, eax
004a2a89 je 0x4a2aa1
004a2a8b push 0x5d0f90
004a2a90 push esi
004a2a91 call 0x5ae3c0
004a2a96 add esp, 8
004a2a99 test eax, eax
004a2a9b jne 0x4a2bb8
004a2aa1 fld dword ptr [0x5b25e8]
004a2aa7 pop esi
004a2aa8 pop ecx
004a2aa9 ret
004a2aaa fld dword ptr [0x5b24e8]
004a2ab0 pop esi
004a2ab1 pop ecx
004a2ab2 ret
004a2ab3 push 0x5d0f88
004a2ab8 push 0x657444
004a2abd call 0x5ae3c0
004a2ac2 add esp, 8
004a2ac5 test eax, eax
004a2ac7 jne 0x4a2adb
004a2ac9 mov eax, dword ptr [0x657430]
004a2ace test eax, eax
004a2ad0 je 0x4a2bb8
004a2ad6 jmp 0x4a2970
004a2adb push 0x5d0f80
004a2ae0 push 0x657444
004a2ae5 call 0x5ae3c0
004a2aea add esp, 8
004a2aed test eax, eax
004a2aef jne 0x4a2b68
004a2af1 mov esi, dword ptr [esp + 0xc]
004a2af5 push 0x5d0d2c
004a2afa push esi
004a2afb call 0x5ae3c0
004a2b00 add esp, 8
004a2b03 test eax, eax
004a2b05 je 0x4a29c0
004a2b0b push 0x5d0d38
004a2b10 push esi
004a2b11 call 0x5ae3c0
004a2b16 add esp, 8
004a2b19 test eax, eax
004a2b1b je 0x4a29c0
004a2b21 push 0x5d0d34
004a2b26 push esi
004a2b27 call 0x5ae3c0
004a2b2c add esp, 8
004a2b2f test eax, eax
004a2b31 je 0x4a29c0
004a2b37 push 0x5d0d30
004a2b3c push esi
004a2b3d call 0x5ae3c0
004a2b42 add esp, 8
004a2b45 test eax, eax
004a2b47 je 0x4a29c0
004a2b4d push 0x5d0d24
004a2b52 push esi
004a2b53 call 0x5ae3c0
004a2b58 add esp, 8
004a2b5b test eax, eax
004a2b5d jne 0x4a2bb8
004a2b5f fld dword ptr [0x5b49dc]
004a2b65 pop esi
004a2b66 pop ecx
004a2b67 ret
004a2b68 push 0x5d0f78
004a2b6d push 0x657444
004a2b72 call 0x5ae3c0
004a2b77 add esp, 8
004a2b7a test eax, eax
004a2b7c jne 0x4a2bb8
004a2b7e mov eax, dword ptr [0x657430]
004a2b83 test eax, eax
004a2b85 je 0x4a2bb8
004a2b87 mov esi, dword ptr [esp + 0xc]
004a2b8b push 0x5d0f70
004a2b90 push esi
004a2b91 call 0x5ae3c0
004a2b96 add esp, 8
004a2b99 test eax, eax
004a2b9b je 0x4a2baf
004a2b9d push 0x5d0f68
004a2ba2 push esi
004a2ba3 call 0x5ae3c0
004a2ba8 add esp, 8
004a2bab test eax, eax
004a2bad jne 0x4a2bb8
004a2baf fld dword ptr [0x5b27a4]
004a2bb5 pop esi
004a2bb6 pop ecx
004a2bb7 ret
004a2bb8 fld dword ptr [esp + 4]
004a2bbc pop esi
004a2bbd pop ecx
004a2bbe ret
004a2bbf nop
004a2bc0 push esi
004a2bc1 mov esi, dword ptr [esp + 8]
004a2bc5 push edi
004a2bc6 push 0x5d0fd4
004a2bcb push esi
004a2bcc mov edi, 5
004a2bd1 call 0x5ae3c0
004a2bd6 add esp, 8
004a2bd9 test eax, eax
004a2bdb je 0x4a2dab
004a2be1 push 0x5d0fcc
004a2be6 push esi
004a2be7 call 0x5ae3c0
004a2bec add esp, 8
004a2bef test eax, eax
004a2bf1 je 0x4a2dab
004a2bf7 push 0x5d0d44
004a2bfc push esi
004a2bfd call 0x5ae3c0
004a2c02 add esp, 8
004a2c05 test eax, eax
004a2c07 je 0x4a2dab
004a2c0d push 0x5d0d2c
004a2c12 push esi
004a2c13 call 0x5ae3c0
004a2c18 add esp, 8
004a2c1b test eax, eax
004a2c1d jne 0x4a2c39
004a2c1f push 0x5d0fc4
004a2c24 push 0x657444
004a2c29 call 0x5ae3c0
004a2c2e add esp, 8
004a2c31 test eax, eax
004a2c33 je 0x4a2dab
004a2c39 push 0x5d0d34
004a2c3e push esi
004a2c3f call 0x5ae3c0
004a2c44 add esp, 8
004a2c47 test eax, eax
004a2c49 jne 0x4a2c65
004a2c4b push 0x5d0fc4
004a2c50 push 0x657444
004a2c55 call 0x5ae3c0
004a2c5a add esp, 8
004a2c5d test eax, eax
004a2c5f je 0x4a2dab
004a2c65 push 0x5d0fbc
004a2c6a push esi
004a2c6b call 0x5ae3c0
004a2c70 add esp, 8
004a2c73 test eax, eax
004a2c75 je 0x4a2da3
004a2c7b push 0x5d0d24
004a2c80 push esi
004a2c81 call 0x5ae3c0
004a2c86 add esp, 8
004a2c89 test eax, eax
004a2c8b je 0x4a2da3
004a2c91 push 0x5d0f70
004a2c96 push esi
004a2c97 call 0x5ae3c0
004a2c9c add esp, 8
004a2c9f test eax, eax
004a2ca1 je 0x4a2da3
004a2ca7 push 0x5d0fb8
004a2cac push esi
004a2cad call 0x5ae3c0
004a2cb2 add esp, 8
004a2cb5 test eax, eax
004a2cb7 je 0x4a2da3
004a2cbd push 0x5d0fb4
004a2cc2 push esi
004a2cc3 call 0x5ae3c0
004a2cc8 add esp, 8
004a2ccb test eax, eax
004a2ccd je 0x4a2d9b
004a2cd3 push 0x5d0fb0
004a2cd8 push esi
004a2cd9 call 0x5ae3c0
004a2cde add esp, 8
004a2ce1 test eax, eax
004a2ce3 je 0x4a2d9b
004a2ce9 push 0x5d0d28
004a2cee push esi
004a2cef call 0x5ae3c0
004a2cf4 add esp, 8
004a2cf7 test eax, eax
004a2cf9 je 0x4a2d9b
004a2cff push 0x5d0f68
004a2d04 push esi
004a2d05 call 0x5ae3c0
004a2d0a add esp, 8
004a2d0d test eax, eax
004a2d0f je 0x4a2d9b
004a2d15 push 0x5d0f9c
004a2d1a push esi
004a2d1b call 0x5ae3c0
004a2d20 add esp, 8
004a2d23 test eax, eax
004a2d25 je 0x4a2d93
004a2d27 push 0x5d0fa8
004a2d2c push esi
004a2d2d call 0x5ae3c0
004a2d32 add esp, 8
004a2d35 test eax, eax
004a2d37 je 0x4a2d93
004a2d39 push 0x5d0f98
004a2d3e push esi
004a2d3f call 0x5ae3c0
004a2d44 add esp, 8
004a2d47 test eax, eax
004a2d49 je 0x4a2d93
004a2d4b push 0x5d0fa0
004a2d50 push esi
004a2d51 call 0x5ae3c0
004a2d56 add esp, 8
004a2d59 test eax, eax
004a2d5b je 0x4a2d93
004a2d5d push 0x5d0d34
004a2d62 push esi
004a2d63 call 0x5ae3c0
004a2d68 add esp, 8
004a2d6b test eax, eax
004a2d6d je 0x4a2d93
004a2d6f push 0x5d0d30
004a2d74 push esi
004a2d75 call 0x5ae3c0
004a2d7a add esp, 8
004a2d7d test eax, eax
004a2d7f je 0x4a2d93
004a2d81 push 0x5d0f90
004a2d86 push esi
004a2d87 call 0x5ae3c0
004a2d8c add esp, 8
004a2d8f test eax, eax
004a2d91 jne 0x4a2db3
004a2d93 pop edi
004a2d94 mov eax, 4
004a2d99 pop esi
004a2d9a ret
004a2d9b pop edi
004a2d9c mov eax, 3
004a2da1 pop esi
004a2da2 ret
004a2da3 pop edi
004a2da4 mov eax, 2
004a2da9 pop esi
004a2daa ret
004a2dab pop edi
004a2dac mov eax, 1
004a2db1 pop esi
004a2db2 ret
004a2db3 mov eax, edi
004a2db5 pop edi
004a2db6 pop esi
004a2db7 ret
004a2db8 nop
004a2db9 nop
004a2dba nop
004a2dbb nop
004a2dbc nop
004a2dbd nop
004a2dbe nop
004a2dbf nop
004a2dc0 mov eax, dword ptr [esp + 4]
004a2dc4 push ebx
004a2dc5 push esi
004a2dc6 push edi
004a2dc7 push eax
004a2dc8 call 0x4a2bc0
004a2dcd mov esi, eax
004a2dcf mov ecx, 0xa
004a2dd4 mov eax, 0x3f800000
004a2dd9 mov edi, 0x5e74fc
004a2dde add esp, 4
004a2de1 mov dword ptr [0x5e6e34], 0x41400000
004a2deb mov edx, 0x5e74ac
004a2df0 xor ebx, ebx
004a2df2 rep stosd dword ptr es:[edi], eax
004a2df4 mov dword ptr [edx + 4], ebx
004a2df7 mov dword ptr [edx], ebx
004a2df9 add edx, 8
004a2dfc cmp edx, 0x5e74fc
004a2e02 jl 0x4a2df4
004a2e04 push 0x5d0f88
004a2e09 push 0x657444
004a2e0e mov dword ptr [esp + 0x18], 0x3f800000
004a2e16 call 0x5ae3c0
004a2e1b add esp, 8
004a2e1e test eax, eax
004a2e20 jne 0x4a2fc2
004a2e26 cmp dword ptr [0x657430], ebx
004a2e2c je 0x4a2eeb
004a2e32 mov dword ptr [0x5e74ac], 0x14
004a2e3c mov dword ptr [0x5e74b0], 0x32
004a2e46 mov dword ptr [0x5e74fc], 0x3f8ccccd
004a2e50 mov dword ptr [0x5e74b4], 0x5a
004a2e5a mov dword ptr [0x5e74b8], 0x82
004a2e64 mov dword ptr [0x5e7500], 0x3f8ccccd
004a2e6e mov dword ptr [0x5e74c4], 0x186
004a2e78 mov dword ptr [0x5e74c8], 0x22d
004a2e82 mov dword ptr [0x5e7508], 0x3f933333
004a2e8c mov dword ptr [0x5e74cc], 0x8b
004a2e96 mov dword ptr [0x5e74d0], 0x96
004a2ea0 mov dword ptr [0x5e750c], 0x41c80000
004a2eaa mov dword ptr [0x5e74d4], 0x244
004a2eb4 mov dword ptr [0x5e74d8], 0x250
004a2ebe mov dword ptr [0x5e7510], 0x41f00000
004a2ec8 mov dword ptr [0x5e74dc], 0xc8
004a2ed2 mov dword ptr [0x5e74e0], 0x12c
004a2edc mov dword ptr [0x5e7514], 0x3f333333
004a2ee6 jmp 0x4a2f7c
004a2eeb mov eax, 0x20d
004a2ef0 mov dword ptr [0x5e74ac], 0x1e
004a2efa mov dword ptr [0x5e74b0], 0x46
004a2f04 mov dword ptr [0x5e74fc], 0x3f933333
004a2f0e mov dword ptr [0x5e74b4], 0x5a
004a2f18 mov dword ptr [0x5e74b8], 0x6e
004a2f22 mov dword ptr [0x5e7500], 0x3f99999a
004a2f2c mov dword ptr [0x5e74bc], 0x1a9
004a2f36 mov dword ptr [0x5e74c0], eax
004a2f3b mov dword ptr [0x5e7504], 0x3f933333
004a2f45 mov dword ptr [0x5e74c4], eax
004a2f4a mov dword ptr [0x5e74c8], 0x22d
004a2f54 mov dword ptr [0x5e7508], 0x3f90a3d7
004a2f5e mov dword ptr [0x5e74cc], 0xc8
004a2f68 mov dword ptr [0x5e74d0], 0x12c
004a2f72 mov dword ptr [0x5e750c], 0x3f333333
004a2f7c cmp esi, 5
004a2f7f jne 0x4a2f8b
004a2f81 fld dword ptr [0x5b246c]
004a2f87 pop edi
004a2f88 pop esi
004a2f89 pop ebx
004a2f8a ret
004a2f8b cmp esi, 4
004a2f8e jne 0x4a2f9a
004a2f90 fld dword ptr [0x5b4abc]
004a2f96 pop edi
004a2f97 pop esi
004a2f98 pop ebx
004a2f99 ret
004a2f9a cmp esi, 3
004a2f9d jne 0x4a2fa9
004a2f9f fld dword ptr [0x5b4ab8]
004a2fa5 pop edi
004a2fa6 pop esi
004a2fa7 pop ebx
004a2fa8 ret
004a2fa9 cmp esi, 2
004a2fac jne 0x4a2fb8
004a2fae fld dword ptr [0x5b4ab4]
004a2fb4 pop edi
004a2fb5 pop esi
004a2fb6 pop ebx
004a2fb7 ret
004a2fb8 fld dword ptr [0x5b4ab0]
004a2fbe pop edi
004a2fbf pop esi
004a2fc0 pop ebx
004a2fc1 ret
004a2fc2 push 0x5d0f80
004a2fc7 push 0x657444
004a2fcc call 0x5ae3c0
004a2fd1 add esp, 8
004a2fd4 test eax, eax
004a2fd6 jne 0x4a30ef
004a2fdc cmp esi, 5
004a2fdf jne 0x4a2fe9
004a2fe1 fld dword ptr [0x5b3f8c]
004a2fe7 jmp 0x4a3016
004a2fe9 cmp esi, 4
004a2fec jne 0x4a2ff6
004a2fee fld dword ptr [0x5b4abc]
004a2ff4 jmp 0x4a3016
004a2ff6 cmp esi, 3
004a2ff9 jne 0x4a3003
004a2ffb fld dword ptr [0x5b4ab8]
004a3001 jmp 0x4a3016
004a3003 cmp esi, 2
004a3006 jne 0x4a3010
004a3008 fld dword ptr [0x5b2480]
004a300e jmp 0x4a3016
004a3010 fld dword ptr [0x5b4ab0]
004a3016 cmp dword ptr [0x657430], ebx
004a301c je 0x4a3091
004a301e mov eax, 0x46
004a3023 pop edi
004a3024 mov dword ptr [0x5e74ac], ebx
004a302a pop esi
004a302b mov dword ptr [0x5e74b0], eax
004a3030 mov dword ptr [0x5e74fc], 0x3dcccccd
004a303a mov dword ptr [0x5e74b4], eax
004a303f mov dword ptr [0x5e74b8], 0x8c
004a3049 mov dword ptr [0x5e7500], 0x3f333333
004a3053 mov dword ptr [0x5e74c4], 0x10b
004a305d mov dword ptr [0x5e74c8], 0x15e
004a3067 mov dword ptr [0x5e7508], 0x3fd9999a
004a3071 mov dword ptr [0x5e74cc], 0x1e0
004a307b mov dword ptr [0x5e74d0], 0x261
004a3085 mov dword ptr [0x5e750c], 0x3f866666
004a308f pop ebx
004a3090 ret
004a3091 pop edi
004a3092 pop esi
004a3093 mov dword ptr [0x5e74ac], 0x1e0
004a309d mov dword ptr [0x5e74b0], 0x261
004a30a7 mov dword ptr [0x5e74fc], 0x3f900000
004a30b1 mov dword ptr [0x5e74b4], 0xff
004a30bb mov dword ptr [0x5e74b8], 0x113
004a30c5 mov dword ptr [0x5e7500], 0x3f900000
004a30cf mov dword ptr [0x5e74bc], 0x50
004a30d9 mov dword ptr [0x5e74c0], 0x78
004a30e3 mov dword ptr [0x5e7504], 0x3f4ccccd
004a30ed pop ebx
004a30ee ret
004a30ef push 0x5d0f78
004a30f4 push 0x657444
004a30f9 call 0x5ae3c0
004a30fe add esp, 8
004a3101 test eax, eax
004a3103 jne 0x4a3310
004a3109 cmp dword ptr [0x657430], ebx
004a310f je 0x4a3258
004a3115 mov eax, 0xc8
004a311a cmp esi, 5
004a311d mov dword ptr [0x5e74ac], 0xb9
004a3127 mov dword ptr [0x5e74b0], eax
004a312c mov dword ptr [0x5e74fc], 0x3f8ccccd
004a3136 mov dword ptr [0x5e74b4], 0x154
004a3140 mov dword ptr [0x5e74b8], 0x19f
004a314a mov dword ptr [0x5e7500], 0x3f933333
004a3154 mov dword ptr [0x5e74bc], 0x1fa
004a315e mov dword ptr [0x5e74c0], 0x212
004a3168 mov dword ptr [0x5e7504], 0x3fa00000
004a3172 mov dword ptr [0x5e74c4], eax
004a3177 mov dword ptr [0x5e74c8], 0x12c
004a3181 mov dword ptr [0x5e7508], 0x3f933333
004a318b mov dword ptr [0x5e74cc], 0x82
004a3195 mov dword ptr [0x5e74d0], 0xaa
004a319f mov dword ptr [0x5e750c], 0x3f8ccccd
004a31a9 mov dword ptr [0x5e74d4], 7
004a31b3 mov dword ptr [0x5e74d8], 0x2d
004a31bd mov dword ptr [0x5e7510], 0x3fb33333
004a31c7 mov dword ptr [0x5e74dc], 0x2ab
004a31d1 mov dword ptr [0x5e74e0], 0x2b8
004a31db mov dword ptr [0x5e7514], 0x3fc00000
004a31e5 mov dword ptr [0x5e74e4], 0x1ea
004a31ef mov dword ptr [0x5e74e8], 0x1fb
004a31f9 mov dword ptr [0x5e7518], 0x3fa00000
004a3203 mov dword ptr [0x5e74ec], 0x46
004a320d mov dword ptr [0x5e74f0], 0x5a
004a3217 mov dword ptr [0x5e751c], 0x3f933333
004a3221 jne 0x4a322d
004a3223 fld dword ptr [0x5b3f8c]
004a3229 pop edi
004a322a pop esi
004a322b pop ebx
004a322c ret
004a322d cmp esi, 4
004a3230 jne 0x4a323c
004a3232 fld dword ptr [0x5b4abc]
004a3238 pop edi
004a3239 pop esi
004a323a pop ebx
004a323b ret
004a323c cmp esi, 3
004a323f jne 0x4a324b
004a3241 fld dword ptr [0x5b2480]
004a3247 pop edi
004a3248 pop esi
004a3249 pop ebx
004a324a ret
004a324b fld dword ptr [0x5b25e4]
004a3251 cmp esi, 2
004a3254 pop edi
004a3255 pop esi
004a3256 pop ebx
004a3257 ret
004a3258 cmp esi, 5
004a325b mov dword ptr [0x5e74ac], 0x41
004a3265 mov dword ptr [0x5e74b0], 0x91
004a326f mov dword ptr [0x5e74fc], 0x3f8ccccd
004a3279 mov dword ptr [0x5e74b4], 0x1eb
004a3283 mov dword ptr [0x5e74b8], 0x1f9
004a328d mov dword ptr [0x5e7500], 0x3f933333
004a3297 mov dword ptr [0x5e74bc], 0x23a
004a32a1 mov dword ptr [0x5e74c0], 0x273
004a32ab mov dword ptr [0x5e7504], 0x3f933333
004a32b5 mov dword ptr [0x5e74c4], 0xe1
004a32bf mov dword ptr [0x5e74c8], 0x118
004a32c9 mov dword ptr [0x5e7508], 0x3f4ccccd
004a32d3 jne 0x4a32df
004a32d5 fld dword ptr [0x5b3f8c]
004a32db pop edi
004a32dc pop esi
004a32dd pop ebx
004a32de ret
004a32df cmp esi, 4
004a32e2 jne 0x4a32ee
004a32e4 fld dword ptr [0x5b4abc]
004a32ea pop edi
004a32eb pop esi
004a32ec pop ebx
004a32ed ret
004a32ee cmp esi, 3
004a32f1 jne 0x4a32fd
004a32f3 fld dword ptr [0x5b4ab8]
004a32f9 pop edi
004a32fa pop esi
004a32fb pop ebx
004a32fc ret
004a32fd cmp esi, 2
004a3300 jne 0x4a414d
004a3306 fld dword ptr [0x5b4aac]
004a330c pop edi
004a330d pop esi
004a330e pop ebx
004a330f ret
004a3310 push 0x5d101c
004a3315 push 0x657444
004a331a call 0x5ae3c0
004a331f add esp, 8
004a3322 test eax, eax
004a3324 jne 0x4a35ad
004a332a mov ecx, dword ptr [0x657430]
004a3330 mov edx, 0x12c
004a3335 cmp ecx, ebx
004a3337 mov edi, 0x112
004a333c je 0x4a3469
004a3342 mov eax, 0x88
004a3347 mov dword ptr [0x5e74b0], 0xeb
004a3351 mov dword ptr [0x5e74ac], eax
004a3356 mov dword ptr [0x5e74c0], eax
004a335b mov eax, 0x1e0
004a3360 mov dword ptr [0x5e74fc], 0x3f99999a
004a336a mov dword ptr [0x5e74b4], 0x12d
004a3374 mov dword ptr [0x5e74b8], 0x13a
004a337e mov dword ptr [0x5e7500], 0x3f99999a
004a3388 mov dword ptr [0x5e74bc], 0x70
004a3392 mov dword ptr [0x5e7504], 0x3dcccccd
004a339c mov dword ptr [0x5e74c4], 0x139
004a33a6 mov dword ptr [0x5e74c8], 0x163
004a33b0 mov dword ptr [0x5e7508], 0x3fa00000
004a33ba mov dword ptr [0x5e74cc], 0x122
004a33c4 mov dword ptr [0x5e74d0], 0x12e
004a33ce mov dword ptr [0x5e750c], 0x3fa66666
004a33d8 mov dword ptr [0x5e74d4], 0x115
004a33e2 mov dword ptr [0x5e74d8], 0x123
004a33ec mov dword ptr [0x5e7510], 0x3fc00000
004a33f6 mov dword ptr [0x5e74dc], eax
004a33fb mov dword ptr [0x5e74e0], 0x1fe
004a3405 mov dword ptr [0x5e7514], 0x3dcccccd
004a340f mov dword ptr [0x5e74e4], 0x2b7
004a3419 mov dword ptr [0x5e74e8], 0x2ee
004a3423 mov dword ptr [0x5e7518], 0x3f99999a
004a342d mov dword ptr [0x5e74ec], 0x1b8
004a3437 mov dword ptr [0x5e74f0], eax
004a343c mov dword ptr [0x5e751c], 0x3f99999a
004a3446 mov dword ptr [0x5e74f4], 5
004a3450 mov dword ptr [0x5e74f8], 0x50
004a345a mov dword ptr [0x5e7520], 0x3f933333
004a3464 jmp 0x4a354d
004a3469 mov dword ptr [0x5e74ac], 0x258
004a3473 mov dword ptr [0x5e74b0], 0x2b8
004a347d mov dword ptr [0x5e74fc], 0x3fb33333
004a3487 mov dword ptr [0x5e74b4], edx
004a348d mov dword ptr [0x5e74b8], 0x139
004a3497 mov dword ptr [0x5e7500], 0x3fa00000
004a34a1 mov dword ptr [0x5e74bc], 0x70
004a34ab mov dword ptr [0x5e74c0], 0x7d
004a34b5 mov dword ptr [0x5e7504], 0x3dcccccd
004a34bf mov dword ptr [0x5e74c4], 0x2f8
004a34c9 mov dword ptr [0x5e74c8], 0x343
004a34d3 mov dword ptr [0x5e7508], 0x3dcccccd
004a34dd mov dword ptr [0x5e74cc], 0x104
004a34e7 mov dword ptr [0x5e74d0], 0x113
004a34f1 mov dword ptr [0x5e750c], 0x3fa66666
004a34fb mov dword ptr [0x5e74d4], edi
004a3501 mov dword ptr [0x5e74d8], edx
004a3507 mov dword ptr [0x5e7510], 0x3fe66666
004a3511 mov dword ptr [0x5e74dc], 0x195
004a351b mov dword ptr [0x5e74e0], 0x1d6
004a3525 mov dword ptr [0x5e7514], 0x3f933333
004a352f mov dword ptr [0x5e74e4], 0x3c
004a3539 mov dword ptr [0x5e74e8], 0x72
004a3543 mov dword ptr [0x5e7518], 0x3f8ccccd
004a354d cmp esi, 5
004a3550 jne 0x4a355c
004a3552 fld dword ptr [0x5b4aa8]
004a3558 pop edi
004a3559 pop esi
004a355a pop ebx
004a355b ret
004a355c cmp esi, 4
004a355f jne 0x4a356b
004a3561 fld dword ptr [0x5b4abc]
004a3567 pop edi
004a3568 pop esi
004a3569 pop ebx
004a356a ret
004a356b cmp esi, 3
004a356e jne 0x4a357a
004a3570 fld dword ptr [0x5b4ab8]
004a3576 pop edi
004a3577 pop esi
004a3578 pop ebx
004a3579 ret
004a357a cmp esi, 2
004a357d jne 0x4a3589
004a357f fld dword ptr [0x5b2480]
004a3585 pop edi
004a3586 pop esi
004a3587 pop ebx
004a3588 ret
004a3589 cmp ecx, ebx
004a358b jne 0x4a35a3
004a358d mov dword ptr [0x5e74d4], edi
004a3593 mov dword ptr [0x5e74d8], edx
004a3599 mov dword ptr [0x5e7510], 0x3fb33333
004a35a3 fld dword ptr [0x5b2480]
004a35a9 pop edi
004a35aa pop esi
004a35ab pop ebx
004a35ac ret
004a35ad push 0x5d1014
004a35b2 push 0x657444
004a35b7 call 0x5ae3c0
004a35bc add esp, 8
004a35bf test eax, eax
004a35c1 jne 0x4a3735
004a35c7 cmp dword ptr [0x657430], ebx
004a35cd je 0x4a366a
004a35d3 mov dword ptr [0x5e74ac], ebx
004a35d9 mov dword ptr [0x5e74b0], 0x14
004a35e3 mov dword ptr [0x5e74fc], 0x3dcccccd
004a35ed mov dword ptr [0x5e74b4], 0x116
004a35f7 mov dword ptr [0x5e74b8], 0x12f
004a3601 mov dword ptr [0x5e7500], 0x3dcccccd
004a360b mov dword ptr [0x5e74bc], 0x1c7
004a3615 mov dword ptr [0x5e74c0], 0x1eb
004a361f mov dword ptr [0x5e7504], 0x3f933333
004a3629 mov dword ptr [0x5e74c4], 0x1ea
004a3633 mov dword ptr [0x5e74c8], 0x208
004a363d mov dword ptr [0x5e7508], 0x3fa66666
004a3647 mov dword ptr [0x5e74cc], 0x3c
004a3651 mov dword ptr [0x5e74d0], 0x8c
004a365b mov dword ptr [0x5e750c], 0x3f59999a
004a3665 jmp 0x4a36fb
004a366a mov eax, 0x116
004a366f mov dword ptr [0x5e74b0], 0x12c
004a3679 mov dword ptr [0x5e74ac], eax
004a367e mov dword ptr [0x5e74fc], 0x3dcccccd
004a3688 mov dword ptr [0x5e74b4], 0x24e
004a3692 mov dword ptr [0x5e74b8], 0x261
004a369c mov dword ptr [0x5e7500], 0x3dcccccd
004a36a6 mov dword ptr [0x5e74bc], 0x212
004a36b0 mov dword ptr [0x5e74c0], 0x258
004a36ba mov dword ptr [0x5e7504], 0x3f333333
004a36c4 mov dword ptr [0x5e74c4], 0xfa
004a36ce mov dword ptr [0x5e74c8], eax
004a36d3 mov dword ptr [0x5e7508], 0x3f8ccccd
004a36dd mov dword ptr [0x5e74cc], 0x190
004a36e7 mov dword ptr [0x5e74d0], 0x1d6
004a36f1 mov dword ptr [0x5e750c], 0x3fa00000
004a36fb cmp esi, 5
004a36fe jne 0x4a370a
004a3700 fld dword ptr [0x5b246c]
004a3706 pop edi
004a3707 pop esi
004a3708 pop ebx
004a3709 ret
004a370a cmp esi, 4
004a370d jne 0x4a3719
004a370f fld dword ptr [0x5b4abc]
004a3715 pop edi
004a3716 pop esi
004a3717 pop ebx
004a3718 ret
004a3719 cmp esi, 3
004a371c jne 0x4a3728
004a371e fld dword ptr [0x5b4ab8]
004a3724 pop edi
004a3725 pop esi
004a3726 pop ebx
004a3727 ret
004a3728 fld dword ptr [0x5b2480]
004a372e cmp esi, 2
004a3731 pop edi
004a3732 pop esi
004a3733 pop ebx
004a3734 ret
004a3735 push 0x5d0fc4
004a373a push 0x657444
004a373f call 0x5ae3c0
004a3744 add esp, 8
004a3747 test eax, eax
004a3749 jne 0x4a3858
004a374f mov eax, dword ptr [0x657430]
004a3754 mov dword ptr [0x5e74ac], 0x12c
004a375e cmp eax, ebx
004a3760 je 0x4a379b
004a3762 mov eax, 0x384
004a3767 mov dword ptr [0x5e74b0], 0x1c2
004a3771 mov dword ptr [0x5e74fc], 0x3fb33333
004a377b mov dword ptr [0x5e74bc], 0x320
004a3785 mov dword ptr [0x5e74c0], eax
004a378a mov dword ptr [0x5e7504], 0x3fc00000
004a3794 mov dword ptr [0x5e74c4], eax
004a3799 jmp 0x4a37f5
004a379b mov dword ptr [0x5e74b0], 0x14a
004a37a5 mov dword ptr [0x5e74fc], 0x3fcccccd
004a37af mov dword ptr [0x5e74b4], 0x15e
004a37b9 mov dword ptr [0x5e74b8], 0x190
004a37c3 mov dword ptr [0x5e7500], 0x3f99999a
004a37cd mov dword ptr [0x5e74bc], 0x2ee
004a37d7 mov dword ptr [0x5e74c0], 0x348
004a37e1 mov dword ptr [0x5e7504], 0x3fc00000
004a37eb mov dword ptr [0x5e74c4], 0x384
004a37f5 cmp esi, 5
004a37f8 mov dword ptr [0x5e74c8], 0x546
004a3802 mov dword ptr [0x5e7508], 0x3f59999a
004a380c mov dword ptr [0x5e74cc], 0x5dc
004a3816 mov dword ptr [0x5e74d0], 0x6a4
004a3820 mov dword ptr [0x5e750c], 0x3f333333
004a382a jne 0x4a3836
004a382c fld dword ptr [0x5b247c]
004a3832 pop edi
004a3833 pop esi
004a3834 pop ebx
004a3835 ret
004a3836 cmp esi, 3
004a3839 jl 0x4a3845
004a383b fld dword ptr [0x5b2480]
004a3841 pop edi
004a3842 pop esi
004a3843 pop ebx
004a3844 ret
004a3845 cmp esi, 2
004a3848 jne 0x4a45c5
004a384e fld dword ptr [0x5b25e4]
004a3854 pop edi
004a3855 pop esi
004a3856 pop ebx
004a3857 ret
004a3858 push 0x5cc7f8
004a385d push 0x657444
004a3862 call 0x5ae3c0
004a3867 add esp, 8
004a386a test eax, eax
004a386c jne 0x4a3ad0
004a3872 cmp dword ptr [0x657430], ebx
004a3878 je 0x4a39af
004a387e mov dword ptr [0x5e74ac], 0x235
004a3888 mov dword ptr [0x5e74b0], 0x262
004a3892 mov dword ptr [0x5e74fc], 0x3fc00000
004a389c mov dword ptr [0x5e74b4], 0x36b
004a38a6 mov dword ptr [0x5e74b8], 0x398
004a38b0 mov dword ptr [0x5e7500], 0x3f99999a
004a38ba mov dword ptr [0x5e74bc], 0x294
004a38c4 mov dword ptr [0x5e74c0], 0x2b7
004a38ce mov dword ptr [0x5e7504], 0x3f99999a
004a38d8 mov dword ptr [0x5e74c4], 0x325
004a38e2 mov dword ptr [0x5e74c8], 0x357
004a38ec mov dword ptr [0x5e7508], 0x3f8ccccd
004a38f6 mov dword ptr [0x5e74cc], 0x5be
004a3900 mov dword ptr [0x5e74d0], 0x5f0
004a390a mov dword ptr [0x5e750c], 0x3fa66666
004a3914 mov dword ptr [0x5e74d4], 0x1a4
004a391e mov dword ptr [0x5e74d8], 0x1d6
004a3928 mov dword ptr [0x5e7510], 0x3f99999a
004a3932 mov dword ptr [0x5e74dc], 0x2c1
004a393c mov dword ptr [0x5e74e0], 0x2e9
004a3946 mov dword ptr [0x5e7514], 0x3f99999a
004a3950 mov dword ptr [0x5e74e4], 0x741
004a395a mov dword ptr [0x5e74e8], 0x771
004a3964 mov dword ptr [0x5e7518], 0x3f8ccccd
004a396e mov dword ptr [0x5e74ec], 0x3aa
004a3978 mov dword ptr [0x5e74f0], 0x3c5
004a3982 mov dword ptr [0x5e751c], 0x3fc00000
004a398c mov dword ptr [0x5e74f4], 0x582
004a3996 mov dword ptr [0x5e74f8], 0x5b4
004a39a0 mov dword ptr [0x5e7520], 0x3f99999a
004a39aa jmp 0x4a3a9f
004a39af mov dword ptr [0x5e74ac], 0x23f
004a39b9 mov dword ptr [0x5e74b0], 0x25d
004a39c3 mov dword ptr [0x5e74fc], 0x3f99999a
004a39cd mov dword ptr [0x5e74b4], 0x36b
004a39d7 mov dword ptr [0x5e74b8], 0x398
004a39e1 mov dword ptr [0x5e7500], 0x3f99999a
004a39eb mov dword ptr [0x5e74bc], 0x294
004a39f5 mov dword ptr [0x5e74c0], 0x2b7
004a39ff mov dword ptr [0x5e7504], 0x3f99999a
004a3a09 mov dword ptr [0x5e74c4], 0x325
004a3a13 mov dword ptr [0x5e74c8], 0x357
004a3a1d mov dword ptr [0x5e7508], 0x3fa66666
004a3a27 mov dword ptr [0x5e74cc], 0x5be
004a3a31 mov dword ptr [0x5e74d0], 0x5f0
004a3a3b mov dword ptr [0x5e750c], 0x3fa66666
004a3a45 mov dword ptr [0x5e74d4], 0x587
004a3a4f mov dword ptr [0x5e74d8], 0x5b9
004a3a59 mov dword ptr [0x5e7510], 0x3f8ccccd
004a3a63 mov dword ptr [0x5e74dc], 0x712
004a3a6d mov dword ptr [0x5e74e0], 0x742
004a3a77 mov dword ptr [0x5e7514], 0x3f8ccccd
004a3a81 mov dword ptr [0x5e74e4], 0xabe
004a3a8b mov dword ptr [0x5e74e8], 0xae3
004a3a95 mov dword ptr [0x5e7518], 0x3f8ccccd
004a3a9f cmp esi, 5
004a3aa2 jne 0x4a3aae
004a3aa4 fld dword ptr [0x5b247c]
004a3aaa pop edi
004a3aab pop esi
004a3aac pop ebx
004a3aad ret
004a3aae cmp esi, 4
004a3ab1 jne 0x4a3abd
004a3ab3 fld dword ptr [0x5b2480]
004a3ab9 pop edi
004a3aba pop esi
004a3abb pop ebx
004a3abc ret
004a3abd cmp esi, 2
004a3ac0 jl 0x4a45bb
004a3ac6 fld dword ptr [0x5b27a4]
004a3acc pop edi
004a3acd pop esi
004a3ace pop ebx
004a3acf ret
004a3ad0 push 0x5d100c
004a3ad5 push 0x657444
004a3ada call 0x5ae3c0
004a3adf add esp, 8
004a3ae2 test eax, eax
004a3ae4 jne 0x4a3c67
004a3aea cmp dword ptr [0x657430], ebx
004a3af0 je 0x4a3b91
004a3af6 mov dword ptr [0x5e74ac], 0x2da
004a3b00 mov dword ptr [0x5e74b0], 0x33e
004a3b0a mov dword ptr [0x5e74fc], 0x3f933333
004a3b14 mov dword ptr [0x5e74b4], 0x492
004a3b1e mov dword ptr [0x5e74b8], 0x4f6
004a3b28 mov dword ptr [0x5e7500], 0x3fa00000
004a3b32 mov dword ptr [0x5e74bc], 0x640
004a3b3c mov dword ptr [0x5e74c0], 0x686
004a3b46 mov dword ptr [0x5e7504], 0x3f8ccccd
004a3b50 mov dword ptr [0x5e74c4], 0x690
004a3b5a mov dword ptr [0x5e74c8], 0x6c2
004a3b64 mov dword ptr [0x5e7508], 0x3f8ccccd
004a3b6e mov dword ptr [0x5e74cc], 0x37
004a3b78 mov dword ptr [0x5e74d0], 0xfa
004a3b82 mov dword ptr [0x5e750c], 0x3f59999a
004a3b8c jmp 0x4a3c45
004a3b91 mov dword ptr [0x5e74ac], 0x190
004a3b9b mov dword ptr [0x5e74b0], 0x1f4
004a3ba5 mov dword ptr [0x5e74fc], 0x3f933333
004a3baf mov dword ptr [0x5e74b4], 0x3a2
004a3bb9 mov dword ptr [0x5e74b8], 0x406
004a3bc3 mov dword ptr [0x5e7500], 0x3f8ccccd
004a3bcd mov dword ptr [0x5e74bc], 0x438
004a3bd7 mov dword ptr [0x5e74c0], 0x46a
004a3be1 mov dword ptr [0x5e7504], 0x3f8ccccd
004a3beb mov dword ptr [0x5e74c4], 0x492
004a3bf5 mov dword ptr [0x5e74c8], 0x4f6
004a3bff mov dword ptr [0x5e7508], 0x3fa00000
004a3c09 mov dword ptr [0x5e74cc], 0x640
004a3c13 mov dword ptr [0x5e74d0], 0x686
004a3c1d mov dword ptr [0x5e750c], 0x3f8ccccd
004a3c27 mov dword ptr [0x5e74d4], 0x37
004a3c31 mov dword ptr [0x5e74d8], 0x172
004a3c3b mov dword ptr [0x5e7510], 0x3f733333
004a3c45 cmp esi, 5
004a3c48 jne 0x4a3c54
004a3c4a fld dword ptr [0x5b2480]
004a3c50 pop edi
004a3c51 pop esi
004a3c52 pop ebx
004a3c53 ret
004a3c54 cmp esi, 3
004a3c57 jl 0x4a4160
004a3c5d fld dword ptr [0x5b25e4]
004a3c63 pop edi
004a3c64 pop esi
004a3c65 pop ebx
004a3c66 ret
004a3c67 push 0x5cf760
004a3c6c push 0x657444
004a3c71 call 0x5ae3c0
004a3c76 add esp, 8
004a3c79 test eax, eax
004a3c7b jne 0x4a3edb
004a3c81 mov eax, dword ptr [0x657430]
004a3c86 mov dword ptr [0x5e74ac], 0x32
004a3c90 cmp eax, ebx
004a3c92 mov dword ptr [0x5e74b0], 0xaf
004a3c9c je 0x4a3d9c
004a3ca2 mov eax, 0x3e8
004a3ca7 mov dword ptr [0x5e74fc], 0x3f666666
004a3cb1 mov dword ptr [0x5e74b4], 0x122
004a3cbb mov dword ptr [0x5e74b8], 0x136
004a3cc5 mov dword ptr [0x5e7500], 0x3fc00000
004a3ccf mov dword ptr [0x5e74bc], 0x965
004a3cd9 mov dword ptr [0x5e74c0], 0xab4
004a3ce3 mov dword ptr [0x5e7504], 0x3f666666
004a3ced mov dword ptr [0x5e74c4], 0xb90
004a3cf7 mov dword ptr [0x5e74c8], 0xbb8
004a3d01 mov dword ptr [0x5e7508], 0x3fa66666
004a3d0b mov dword ptr [0x5e74cc], 0xcf1
004a3d15 mov dword ptr [0x5e74d0], 0xcfd
004a3d1f mov dword ptr [0x5e750c], 0x3fc00000
004a3d29 mov dword ptr [0x5e74d4], 0xd34
004a3d33 mov dword ptr [0x5e74d8], 0xd3e
004a3d3d mov dword ptr [0x5e7510], 0x3fb33333
004a3d47 mov dword ptr [0x5e74dc], 0xc30
004a3d51 mov dword ptr [0x5e74e0], 0xca8
004a3d5b mov dword ptr [0x5e7514], 0x3f59999a
004a3d65 mov dword ptr [0x5e74e4], 0x17c
004a3d6f mov dword ptr [0x5e74e8], eax
004a3d74 mov dword ptr [0x5e7518], 0x3f666666
004a3d7e mov dword ptr [0x5e74ec], eax
004a3d83 mov dword ptr [0x5e74f0], 0x3fc
004a3d8d mov dword ptr [0x5e751c], 0x3fa66666
004a3d97 jmp 0x4a3eaf
004a3d9c mov eax, 0x3e8
004a3da1 mov dword ptr [0x5e74fc], 0x3f733333
004a3dab mov dword ptr [0x5e74b4], 0x122
004a3db5 mov dword ptr [0x5e74b8], 0x136
004a3dbf mov dword ptr [0x5e7500], 0x3fc00000
004a3dc9 mov dword ptr [0x5e74bc], 0x965
004a3dd3 mov dword ptr [0x5e74c0], 0xb7c
004a3ddd mov dword ptr [0x5e7504], 0x3f666666
004a3de7 mov dword ptr [0x5e74c4], 0xb90
004a3df1 mov dword ptr [0x5e74c8], 0xbb8
004a3dfb mov dword ptr [0x5e7508], 0x3fa66666
004a3e05 mov dword ptr [0x5e74cc], 0xcf1
004a3e0f mov dword ptr [0x5e74d0], 0xcfd
004a3e19 mov dword ptr [0x5e750c], 0x3fc00000
004a3e23 mov dword ptr [0x5e74d4], 0xd34
004a3e2d mov dword ptr [0x5e74d8], 0xd3e
004a3e37 mov dword ptr [0x5e7510], 0x3fb33333
004a3e41 mov dword ptr [0x5e74dc], 0xc30
004a3e4b mov dword ptr [0x5e74e0], 0xca8
004a3e55 mov dword ptr [0x5e7514], 0x3f59999a
004a3e5f mov dword ptr [0x5e74e4], 0x17c
004a3e69 mov dword ptr [0x5e74e8], eax
004a3e6e mov dword ptr [0x5e7518], 0x3f666666
004a3e78 mov dword ptr [0x5e74ec], eax
004a3e7d mov dword ptr [0x5e74f0], 0x3fc
004a3e87 mov dword ptr [0x5e751c], 0x3fa66666
004a3e91 mov dword ptr [0x5e74f4], 0xd64
004a3e9b mov dword ptr [0x5e74f8], 0xd72
004a3ea5 mov dword ptr [0x5e7520], 0x3fa66666
004a3eaf cmp esi, 4
004a3eb2 mov dword ptr [0x5e6e34], 0x41200000
004a3ebc jl 0x4a3ec8
004a3ebe fld dword ptr [0x5b27a4]
004a3ec4 pop edi
004a3ec5 pop esi
004a3ec6 pop ebx
004a3ec7 ret
004a3ec8 cmp esi, 3
004a3ecb jne 0x4a45bb
004a3ed1 fld dword ptr [0x5b3f90]
004a3ed7 pop edi
004a3ed8 pop esi
004a3ed9 pop ebx
004a3eda ret
004a3edb push 0x5d1004
004a3ee0 push 0x657444
004a3ee5 call 0x5ae3c0
004a3eea add esp, 8
004a3eed test eax, eax
004a3eef jne 0x4a408e
004a3ef5 mov eax, dword ptr [0x657430]
004a3efa mov dword ptr [0x5e74ac], 0x10e
004a3f04 cmp eax, ebx
004a3f06 je 0x4a3fb1
004a3f0c mov dword ptr [0x5e74b0], 0x140
004a3f16 mov dword ptr [0x5e74fc], 0x3f933333
004a3f20 mov dword ptr [0x5e74b4], 0x1ae
004a3f2a mov dword ptr [0x5e74b8], 0x1f4
004a3f34 mov dword ptr [0x5e7500], 0x3fa00000
004a3f3e mov dword ptr [0x5e74bc], 0x208
004a3f48 mov dword ptr [0x5e74c0], 0x230
004a3f52 mov dword ptr [0x5e7504], 0x3f866666
004a3f5c mov dword ptr [0x5e74c4], 0x294
004a3f66 mov dword ptr [0x5e74c8], 0x320
004a3f70 mov dword ptr [0x5e7508], 0x3f99999a
004a3f7a mov dword ptr [0x5e74cc], 0x334
004a3f84 mov dword ptr [0x5e74d0], 0x366
004a3f8e mov dword ptr [0x5e750c], 0x3fc00000
004a3f98 mov dword ptr [0x5e74d4], 0x3ca
004a3fa2 mov dword ptr [0x5e74d8], 0x41a
004a3fac jmp 0x4a4044
004a3fb1 mov eax, 0x3ca
004a3fb6 mov ecx, 0x41a
004a3fbb mov dword ptr [0x5e74b0], 0x1b8
004a3fc5 mov dword ptr [0x5e74fc], 0x3f8ccccd
004a3fcf mov dword ptr [0x5e74b4], 0x21c
004a3fd9 mov dword ptr [0x5e74b8], 0x230
004a3fe3 mov dword ptr [0x5e7500], 0x3f866666
004a3fed mov dword ptr [0x5e74bc], 0x276
004a3ff7 mov dword ptr [0x5e74c0], 0x320
004a4001 mov dword ptr [0x5e7504], 0x3f933333
004a400b mov dword ptr [0x5e74c4], 0x3b6
004a4015 mov dword ptr [0x5e74c8], eax
004a401a mov dword ptr [0x5e7508], 0x3f8ccccd
004a4024 mov dword ptr [0x5e74cc], eax
004a4029 mov dword ptr [0x5e74d0], ecx
004a402f mov dword ptr [0x5e750c], 0x40000000
004a4039 mov dword ptr [0x5e74d4], eax
004a403e mov dword ptr [0x5e74d8], ecx
004a4044 cmp esi, 5
004a4047 mov dword ptr [0x5e7510], 0x3f99999a
004a4051 mov dword ptr [0x5e74dc], 0x578
004a405b mov dword ptr [0x5e74e0], 0x5b6
004a4065 mov dword ptr [0x5e7514], 0x3f99999a
004a406f jne 0x4a407b
004a4071 fld dword ptr [0x5b247c]
004a4077 pop edi
004a4078 pop esi
004a4079 pop ebx
004a407a ret
004a407b cmp esi, 3
004a407e jl 0x4a4160
004a4084 fld dword ptr [0x5b2480]
004a408a pop edi
004a408b pop esi
004a408c pop ebx
004a408d ret
004a408e push 0x5d0ff8
004a4093 push 0x657444
004a4098 call 0x5ae3c0
004a409d add esp, 8
004a40a0 test eax, eax
004a40a2 jne 0x4a416a
004a40a8 cmp dword ptr [0x657430], ebx
004a40ae je 0x4a40ee
004a40b0 mov dword ptr [0x5e74ac], 0x172
004a40ba mov dword ptr [0x5e74b0], 0x226
004a40c4 mov dword ptr [0x5e74fc], 0x3f99999a
004a40ce mov dword ptr [0x5e74b4], 0x3ca
004a40d8 mov dword ptr [0x5e74b8], 0x5aa
004a40e2 mov dword ptr [0x5e7500], 0x3f59999a
004a40ec jmp 0x4a4148
004a40ee mov dword ptr [0x5e74ac], 0x320
004a40f8 mov dword ptr [0x5e74b0], 0x4f6
004a4102 mov dword ptr [0x5e74fc], 0x3f59999a
004a410c mov dword ptr [0x5e74b4], 0x514
004a4116 mov dword ptr [0x5e74b8], 0x5aa
004a4120 mov dword ptr [0x5e7500], 0x3f59999a
004a412a mov dword ptr [0x5e74bc], 0x726
004a4134 mov dword ptr [0x5e74c0], 0x73f
004a413e mov dword ptr [0x5e7504], 0x3f933333
004a4148 cmp esi, 5
004a414b jne 0x4a4157
004a414d fld dword ptr [0x5b2480]
004a4153 pop edi
004a4154 pop esi
004a4155 pop ebx
004a4156 ret
004a4157 cmp esi, 4
004a415a jne 0x4a3ec8
004a4160 fld dword ptr [0x5b27a4]
004a4166 pop edi
004a4167 pop esi
004a4168 pop ebx
004a4169 ret
004a416a push 0x5d0fec
004a416f push 0x657444
004a4174 call 0x5ae3c0
004a4179 add esp, 8
004a417c test eax, eax
004a417e jne 0x4a4291
004a4184 cmp dword ptr [0x657430], ebx
004a418a je 0x4a4206
004a418c mov dword ptr [0x5e74ac], 0x26c
004a4196 mov dword ptr [0x5e74b0], 0x258
004a41a0 mov dword ptr [0x5e74fc], 0x3f99999a
004a41aa mov dword ptr [0x5e74b4], 0x2a8
004a41b4 mov dword ptr [0x5e74b8], 0x2d0
004a41be mov dword ptr [0x5e7500], 0x3f99999a
004a41c8 mov dword ptr [0x5e74bc], 0x4d8
004a41d2 mov dword ptr [0x5e74c0], 0x528
004a41dc mov dword ptr [0x5e7504], 0x3f8ccccd
004a41e6 mov dword ptr [0x5e74c4], 0x366
004a41f0 mov dword ptr [0x5e74c8], 0x3ca
004a41fa mov dword ptr [0x5e7508], 0x3f333333
004a4204 jmp 0x4a4260
004a4206 mov dword ptr [0x5e74ac], 0x41a
004a4210 mov dword ptr [0x5e74b0], 0x44c
004a421a mov dword ptr [0x5e74fc], 0x3f99999a
004a4224 mov dword ptr [0x5e74b4], 0x49c
004a422e mov dword ptr [0x5e74b8], 0x528
004a4238 mov dword ptr [0x5e7500], 0x3f99999a
004a4242 mov dword ptr [0x5e74bc], 0x366
004a424c mov dword ptr [0x5e74c0], 0x398
004a4256 mov dword ptr [0x5e7504], 0x3f333333
004a4260 cmp esi, 5
004a4263 jne 0x4a426f
004a4265 fld dword ptr [0x5b26e0]
004a426b pop edi
004a426c pop esi
004a426d pop ebx
004a426e ret
004a426f cmp esi, 4
004a4272 jne 0x4a427e
004a4274 fld dword ptr [0x5b247c]
004a427a pop edi
004a427b pop esi
004a427c pop ebx
004a427d ret
004a427e cmp esi, 3
004a4281 jne 0x4a414d
004a4287 fld dword ptr [0x5b3f64]
004a428d pop edi
004a428e pop esi
004a428f pop ebx
004a4290 ret
004a4291 push 0x5d0fe4
004a4296 push 0x657444
004a429b call 0x5ae3c0
004a42a0 add esp, 8
004a42a3 test eax, eax
004a42a5 jne 0x4a44d4
004a42ab mov eax, dword ptr [0x657430]
004a42b0 mov dword ptr [0x5e74ac], 0x32
004a42ba cmp eax, ebx
004a42bc mov dword ptr [0x5e74b0], 0x96
004a42c6 mov dword ptr [0x5e74fc], 0x3f4ccccd
004a42d0 mov dword ptr [0x5e74b4], 0xc8
004a42da mov dword ptr [0x5e74b8], 0x118
004a42e4 mov dword ptr [0x5e7500], 0x3f666666
004a42ee je 0x4a43c6
004a42f4 mov eax, 0x546
004a42f9 mov dword ptr [0x5e74c4], 0x352
004a4303 mov dword ptr [0x5e74c8], 0x384
004a430d mov dword ptr [0x5e7508], 0x3f666666
004a4317 mov dword ptr [0x5e74cc], 0x3b6
004a4321 mov dword ptr [0x5e74d0], 0x41a
004a432b mov dword ptr [0x5e750c], 0x3f666666
004a4335 mov dword ptr [0x5e74d4], 0x44c
004a433f mov dword ptr [0x5e74d8], 0x47e
004a4349 mov dword ptr [0x5e7510], 0x3f933333
004a4353 mov dword ptr [0x5e74dc], 0x50a
004a435d mov dword ptr [0x5e74e0], eax
004a4362 mov dword ptr [0x5e7514], 0x3fc00000
004a436c mov dword ptr [0x5e74e4], eax
004a4371 mov dword ptr [0x5e74e8], 0x5aa
004a437b mov dword ptr [0x5e7518], 0x3f666666
004a4385 mov dword ptr [0x5e74ec], 0x5f0
004a438f mov dword ptr [0x5e74f0], 0x6d6
004a4399 mov dword ptr [0x5e751c], 0x3f666666
004a43a3 mov dword ptr [0x5e74f4], 0x73a
004a43ad mov dword ptr [0x5e74f8], 0x799
004a43b7 mov dword ptr [0x5e7520], 0x3ecccccd
004a43c1 jmp 0x4a4475
004a43c6 mov eax, 0x5be
004a43cb mov dword ptr [0x5e74c4], 0x334
004a43d5 mov dword ptr [0x5e74c8], 0x41a
004a43df mov dword ptr [0x5e7508], 0x3f666666
004a43e9 mov dword ptr [0x5e74cc], 0x442
004a43f3 mov dword ptr [0x5e74d0], 0x460
004a43fd mov dword ptr [0x5e750c], 0x3f933333
004a4407 mov dword ptr [0x5e74d4], 0x4e2
004a4411 mov dword ptr [0x5e74d8], 0x4f6
004a441b mov dword ptr [0x5e7510], 0x3f8ccccd
004a4425 mov dword ptr [0x5e74dc], 0x546
004a442f mov dword ptr [0x5e74e0], eax
004a4434 mov dword ptr [0x5e7514], 0x3f333333
004a443e mov dword ptr [0x5e74e4], eax
004a4443 mov dword ptr [0x5e74e8], 0x6d6
004a444d mov dword ptr [0x5e7518], 0x3f666666
004a4457 mov dword ptr [0x5e74ec], 0x73a
004a4461 mov dword ptr [0x5e74f0], 0x799
004a446b mov dword ptr [0x5e751c], 0x3ecccccd
004a4475 cmp esi, 5
004a4478 jne 0x4a448e
004a447a fld dword ptr [0x5b3f64]
004a4480 pop edi
004a4481 pop esi
004a4482 mov dword ptr [0x5e6e34], 0x41100000
004a448c pop ebx
004a448d ret
004a448e cmp esi, 4
004a4491 jne 0x4a44a7
004a4493 fld dword ptr [0x5b25e4]
004a4499 pop edi
004a449a pop esi
004a449b mov dword ptr [0x5e6e34], 0x41100000
004a44a5 pop ebx
004a44a6 ret
004a44a7 cmp esi, 3
004a44aa jne 0x4a44c0
004a44ac fld dword ptr [0x5b3f90]
004a44b2 pop edi
004a44b3 pop esi
004a44b4 mov dword ptr [0x5e6e34], 0x41100000
004a44be pop ebx
004a44bf ret
004a44c0 fld dword ptr [0x5b24a8]
004a44c6 pop edi
004a44c7 pop esi
004a44c8 mov dword ptr [0x5e6e34], 0x41100000
004a44d2 pop ebx
004a44d3 ret
004a44d4 push 0x5d0fd8
004a44d9 push 0x657444
004a44de call 0x5ae3c0
004a44e3 add esp, 8
004a44e6 test eax, eax
004a44e8 jne 0x4a45c5
004a44ee cmp dword ptr [0x657430], ebx
004a44f4 je 0x4a4552
004a44f6 mov dword ptr [0x5e74ac], 0x262
004a4500 mov dword ptr [0x5e74b0], 0x2a8
004a450a mov dword ptr [0x5e74fc], 0x3fa66666
004a4514 mov dword ptr [0x5e74b4], 0x334
004a451e mov dword ptr [0x5e74b8], 0x370
004a4528 mov dword ptr [0x5e7500], 0x3f19999a
004a4532 mov dword ptr [0x5e74bc], 0x3de
004a453c mov dword ptr [0x5e74c0], 0x578
004a4546 mov dword ptr [0x5e7504], 0x3f400000
004a4550 jmp 0x4a45ac
004a4552 mov dword ptr [0x5e74ac], 0x334
004a455c mov dword ptr [0x5e74b0], 0x370
004a4566 mov dword ptr [0x5e74fc], 0x3f19999a
004a4570 mov dword ptr [0x5e74b4], 0x3de
004a457a mov dword ptr [0x5e74b8], 0x578
004a4584 mov dword ptr [0x5e7500], 0x3f400000
004a458e mov dword ptr [0x5e74bc], 0x604
004a4598 mov dword ptr [0x5e74c0], 0x640
004a45a2 mov dword ptr [0x5e7504], 0x3faccccd
004a45ac cmp esi, 5
004a45af jne 0x4a45bb
004a45b1 fld dword ptr [0x5b27a4]
004a45b7 pop edi
004a45b8 pop esi
004a45b9 pop ebx
004a45ba ret
004a45bb fld dword ptr [0x5b24a8]
004a45c1 pop edi
004a45c2 pop esi
004a45c3 pop ebx
004a45c4 ret
004a45c5 fld dword ptr [esp + 0x10]
004a45c9 pop edi
004a45ca pop esi
004a45cb pop ebx
004a45cc ret
004a45cd nop
004a45ce nop
004a45cf nop
004a45d0 mov eax, dword ptr [0x655a08]
004a45d5 push esi
004a45d6 test eax, eax
004a45d8 jne 0x4a46d9
004a45de mov eax, dword ptr [0x6573e8]
004a45e3 mov esi, 1
004a45e8 cmp eax, 3
004a45eb jne 0x4a467e
004a45f1 mov al, byte ptr [0x5cc81c]
004a45f6 test al, al
004a45f8 jne 0x4a46d9
004a45fe mov eax, dword ptr [0x628c70]
004a4603 test eax, eax
004a4605 je 0x4a463a
004a4607 mov ecx, dword ptr [eax + 8]
004a460a test ecx, ecx
004a460c je 0x4a463a
004a460e mov cl, byte ptr [eax + 0xbf]
004a4614 test cl, cl
004a4616 jne 0x4a463a
004a4618 mov cl, byte ptr [eax + 0xbe]
004a461e test cl, cl
004a4620 je 0x4a463a
004a4622 mov ecx, dword ptr [eax + 0xdc]
004a4628 test ecx, ecx
004a462a jl 0x4a463a
004a462c mov cl, byte ptr [eax + 0xc4]
004a4632 test cl, cl
004a4634 jne 0x4a46d9
004a463a call 0x48d840
004a463f mov ecx, dword ptr [0x655a00]
004a4645 mov edx, dword ptr [0x6559f4]
004a464b shl eax, 7
004a464e sub eax, ecx
004a4650 test edx, edx
004a4652 jne 0x4a46ec
004a4658 test eax, eax
004a465a jge 0x4a46db
004a465c xor esi, esi
004a465e mov dword ptr [0x6559f4], 4
004a4668 lea eax, [esi + esi*4]
004a466b test esi, esi
004a466d lea eax, [eax + eax*4]
004a4670 lea eax, [eax + eax*4]
004a4673 lea ecx, [ecx + eax*8]
004a4676 mov dword ptr [0x655a00], ecx
004a467c jle 0x4a46d9
004a467e mov eax, dword ptr [0x6559e8]
004a4683 inc eax
004a4684 mov dword ptr [0x6559e8], eax
004a4689 mov edx, dword ptr [0x6559e0]
004a468f inc edx
004a4690 mov dword ptr [0x6559e0], edx
004a4696 test al, 1
004a4698 jne 0x4a46d6
004a469a mov eax, dword ptr [0x6559ec]
004a469f mov edx, dword ptr [0x6559f8]
004a46a5 inc eax
004a46a6 inc edx
004a46a7 test al, 1
004a46a9 mov dword ptr [0x6559ec], eax
004a46ae mov dword ptr [0x6559f8], edx
004a46b4 jne 0x4a46d6
004a46b6 mov ecx, dword ptr [0x6559f0]
004a46bc mov eax, dword ptr [0x606aa4]
004a46c1 inc ecx
004a46c2 test eax, eax
004a46c4 mov dword ptr [0x6559f0], ecx
004a46ca jne 0x4a46d6
004a46cc call 0x412e70
004a46d1 call 0x413800
004a46d6 dec esi
004a46d7 jne 0x4a467e
004a46d9 pop esi
004a46da ret
004a46db cmp eax, 0x3e8
004a46e0 jle 0x4a4668
004a46e2 mov esi, 2
004a46e7 jmp 0x4a465e
004a46ec dec dword ptr [0x6559f4]
004a46f2 jmp 0x4a4668
004a46f7 nop
004a46f8 nop
004a46f9 nop
004a46fa nop
004a46fb nop
004a46fc nop
004a46fd nop
004a46fe nop
004a46ff nop
004a4700 push esi
004a4701 xor esi, esi
004a4703 mov dword ptr [0x655a08], esi
004a4709 mov dword ptr [0x6559e0], esi
004a470f cmp dword ptr [0x655a04], esi
004a4715 jne 0x4a4758
004a4717 push 0x4a45d0
004a471c mov dword ptr [0x655a04], 1
004a4726 call 0x560140
004a472b add esp, 4
004a472e mov dword ptr [0x6559e8], esi
004a4734 mov dword ptr [0x6559ec], esi
004a473a mov dword ptr [0x6559f0], esi
004a4740 mov dword ptr [0x655a00], esi
004a4746 mov dword ptr [0x6559f4], esi
004a474c mov dword ptr [0x6559fc], esi
004a4752 mov dword ptr [0x5e99b8], esi
004a4758 pop esi
004a4759 ret
004a475a nop
004a475b nop
004a475c nop
004a475d nop
004a475e nop
004a475f nop
004a4760 mov eax, dword ptr [0x655a04]
004a4765 test eax, eax
004a4767 je 0x4a477e
004a4769 push 0x4a45d0
004a476e mov dword ptr [0x655a04], 0
004a4778 call 0x560180
004a477d pop ecx
004a477e ret
004a477f nop
004a4780 mov eax, dword ptr [esp + 4]
004a4784 push esi
004a4785 xor edx, edx
004a4787 mov esi, 0x1f4
004a478c div esi
004a478e mov ecx, 0x3ade68b1
004a4793 mov dword ptr [0x5d102c], 0x75bcd15
004a479d mov dword ptr [0x5d1028], ecx
004a47a3 mov dword ptr [0x655a10], 0
004a47ad pop esi
004a47ae test edx, edx
004a47b0 jle 0x4a47cf
004a47b2 mov eax, ecx
004a47b4 imul eax, eax, 0x75bcd15
004a47ba mov dword ptr [0x655a0c], eax
004a47bf and eax, 0xffff
004a47c4 dec edx
004a47c5 mov ecx, eax
004a47c7 jne 0x4a47b2
004a47c9 mov dword ptr [0x5d1028], ecx
004a47cf ret
004a47d0 push ecx
004a47d1 mov dword ptr [esp], 0x800000
004a47d9 mov eax, dword ptr [esp]
004a47dd mov dword ptr [0x655a18], eax
004a47e2 pop ecx
004a47e3 ret
004a47e4 nop
004a47e5 nop
004a47e6 nop
004a47e7 nop
004a47e8 nop
004a47e9 nop
004a47ea nop
004a47eb nop
004a47ec nop
004a47ed nop
004a47ee nop
004a47ef nop
004a47f0 fld dword ptr [0x5b24a8]
004a47f6 fdiv dword ptr [0x655a18]
004a47fc fstp dword ptr [0x655a14]
004a4802 ret
004a4803 nop
004a4804 nop
004a4805 nop
004a4806 nop
004a4807 nop
004a4808 nop
004a4809 nop
004a480a nop
004a480b nop
004a480c nop
004a480d nop
004a480e nop
004a480f nop
004a4810 sub esp, 0xd8
004a4816 push ebx
004a4817 mov ebx, dword ptr [esp + 0xe0]
004a481e push ebp
004a481f push esi
004a4820 push edi
004a4821 mov ebp, 4
004a4826 lea eax, [esp + 0xc4]
004a482d push eax
004a482e push ebx
004a482f call 0x532a00
004a4834 lea ecx, [esp + 0xa8]
004a483b lea edx, [esp + 0xcc]
004a4842 push ecx
004a4843 push ebx
004a4844 push edx
004a4845 call 0x532470
004a484a fld dword ptr [esp + 0xb4]
004a4851 fsub dword ptr [0x5d1068]
004a4857 mov ecx, 9
004a485c mov esi, 0x5d1068
004a4861 lea edi, [esp + 0x6c]
004a4865 add esp, 0x14
004a4868 rep movsd dword ptr es:[edi], dword ptr [esi]
004a486a fstp dword ptr [esp + 0x7c]
004a486e fld dword ptr [esp + 0xa4]
004a4875 fsub dword ptr [0x5d106c]
004a487b fstp dword ptr [esp + 0x80]
004a4882 fld dword ptr [esp + 0xa8]
004a4889 fsub dword ptr [0x5d1070]
004a488f fstp dword ptr [esp + 0x84]
004a4896 fld dword ptr [esp + 0xac]
004a489d fsub dword ptr [0x5d1074]
004a48a3 mov ecx, 9
004a48a8 mov esi, 0x5d1068
004a48ad lea edi, [esp + 0x10]
004a48b1 rep movsd dword ptr es:[edi], dword ptr [esi]
004a48b3 fstp dword ptr [esp + 0x88]
004a48ba fld dword ptr [esp + 0xb0]
004a48c1 fsub dword ptr [0x5d1078]
004a48c7 fstp dword ptr [esp + 0x8c]
004a48ce fld dword ptr [esp + 0xb4]
004a48d5 fsub dword ptr [0x5d107c]
004a48db fstp dword ptr [esp + 0x90]
004a48e2 fld dword ptr [esp + 0xb8]
004a48e9 fsub dword ptr [0x5d1080]
004a48ef mov esi, 0x5d1040
004a48f4 fstp dword ptr [esp + 0x94]
004a48fb fld dword ptr [esp + 0xbc]
004a4902 fsub dword ptr [0x5d1084]
004a4908 fstp dword ptr [esp + 0x98]
004a490f fld dword ptr [esp + 0xc0]
004a4916 fsub dword ptr [0x5d1088]
004a491c fstp dword ptr [esp + 0x9c]
004a4923 lea eax, [esp + 0x58]
004a4927 lea ecx, [esp + 0x7c]
004a492b push eax
004a492c lea edx, [esp + 0x5c]
004a4930 push ecx
004a4931 push edx
004a4932 call 0x532470
004a4937 fld dword ptr [esi]
004a4939 fld dword ptr [esp + 0x64]
004a493d fmul st(1)
004a493f add esi, 4
004a4942 add esp, 0xc
004a4945 cmp esi, 0x5d104c
004a494b fstp dword ptr [esp + 0x34]
004a494f fld dword ptr [esp + 0x5c]
004a4953 fmul st(1)
004a4955 fstp dword ptr [esp + 0x38]
004a4959 fld dword ptr [esp + 0x60]
004a495d fmul st(1)
004a495f fstp dword ptr [esp + 0x3c]
004a4963 fld dword ptr [esp + 0x64]
004a4967 fmul st(1)
004a4969 fstp dword ptr [esp + 0x40]
004a496d fld dword ptr [esp + 0x68]
004a4971 fmul st(1)
004a4973 fstp dword ptr [esp + 0x44]
004a4977 fld dword ptr [esp + 0x6c]
004a497b fmul st(1)
004a497d fstp dword ptr [esp + 0x48]
004a4981 fld dword ptr [esp + 0x70]
004a4985 fmul st(1)
004a4987 fstp dword ptr [esp + 0x4c]
004a498b fld dword ptr [esp + 0x74]
004a498f fmul st(1)
004a4991 fstp dword ptr [esp + 0x50]
004a4995 fmul dword ptr [esp + 0x78]
004a4999 fld dword ptr [esp + 0x10]
004a499d fadd dword ptr [esp + 0x34]
004a49a1 fstp dword ptr [esp + 0x10]
004a49a5 fld dword ptr [esp + 0x14]
004a49a9 fadd dword ptr [esp + 0x38]
004a49ad fstp dword ptr [esp + 0x14]
004a49b1 fld dword ptr [esp + 0x18]
004a49b5 fadd dword ptr [esp + 0x3c]
004a49b9 fstp dword ptr [esp + 0x18]
004a49bd fld dword ptr [esp + 0x1c]
004a49c1 fadd dword ptr [esp + 0x40]
004a49c5 fstp dword ptr [esp + 0x1c]
004a49c9 fld dword ptr [esp + 0x20]
004a49cd fadd dword ptr [esp + 0x44]
004a49d1 fstp dword ptr [esp + 0x20]
004a49d5 fld dword ptr [esp + 0x24]
004a49d9 fadd dword ptr [esp + 0x48]
004a49dd fstp dword ptr [esp + 0x24]
004a49e1 fld dword ptr [esp + 0x28]
004a49e5 fadd dword ptr [esp + 0x4c]
004a49e9 fstp dword ptr [esp + 0x28]
004a49ed fld dword ptr [esp + 0x2c]
004a49f1 fadd dword ptr [esp + 0x50]
004a49f5 fstp dword ptr [esp + 0x2c]
004a49f9 fld dword ptr [esp + 0x30]
004a49fd fadd st(1)
004a49ff fstp dword ptr [esp + 0x30]
004a4a03 fstp st(0)
004a4a05 jl 0x4a4923
004a4a0b lea eax, [esp + 0x10]
004a4a0f push ebx
004a4a10 push eax
004a4a11 push ebx
004a4a12 call 0x532470
004a4a17 add esp, 0xc
004a4a1a dec ebp
004a4a1b jne 0x4a4826
004a4a21 pop edi
004a4a22 pop esi
004a4a23 pop ebp
004a4a24 pop ebx
004a4a25 add esp, 0xd8
004a4a2b ret
004a4a2c nop
004a4a2d nop
004a4a2e nop
004a4a2f nop
004a4a30 push ecx
004a4a31 mov dword ptr [esp], 0x800000
004a4a39 mov eax, dword ptr [esp]
004a4a3d mov dword ptr [0x655a20], eax
004a4a42 pop ecx
004a4a43 ret
004a4a44 nop
004a4a45 nop
004a4a46 nop
004a4a47 nop
004a4a48 nop
004a4a49 nop
004a4a4a nop
004a4a4b nop
004a4a4c nop
004a4a4d nop
004a4a4e nop
004a4a4f nop
004a4a50 fld dword ptr [0x5b24a8]
004a4a56 fdiv dword ptr [0x655a20]
004a4a5c fstp dword ptr [0x655a1c]
004a4a62 ret
004a4a63 nop
004a4a64 nop
004a4a65 nop
004a4a66 nop
004a4a67 nop
004a4a68 nop
004a4a69 nop
004a4a6a nop
004a4a6b nop
004a4a6c nop
004a4a6d nop
004a4a6e nop
004a4a6f nop
004a4a70 sub esp, 0xd4
004a4a76 push ebp
004a4a77 mov ebp, dword ptr [esp + 0xdc]
004a4a7e test ebp, ebp
004a4a80 jne 0x4a4a8b
004a4a82 mov byte ptr [0x655a28], 1
004a4a89 jmp 0x4a4aac
004a4a8b cmp ebp, 0xa
004a4a8e jne 0x4a4a9f
004a4a90 mov byte ptr [0x655a28], 0
004a4a97 pop ebp
004a4a98 add esp, 0xd4
004a4a9e ret
004a4a9f mov al, byte ptr [0x655a28]
004a4aa4 test al, al
004a4aa6 je 0x4a53e0
004a4aac mov eax, dword ptr [0x655a24]
004a4ab1 test eax, eax
004a4ab3 jne 0x4a4ad4
004a4ab5 mov eax, dword ptr [0x5dead0]
004a4aba push 0x10
004a4abc push eax
004a4abd push 0x1e0
004a4ac2 push 0x280
004a4ac7 call 0x535950
004a4acc add esp, 0x10
004a4acf mov dword ptr [0x655a24], eax
004a4ad4 mov eax, dword ptr [0x628c70]
004a4ad9 test eax, eax
004a4adb je 0x4a4b57
004a4add mov ecx, dword ptr [eax + 8]
004a4ae0 test ecx, ecx
004a4ae2 je 0x4a4b57
004a4ae4 mov cl, byte ptr [eax + 0xbf]
004a4aea test cl, cl
004a4aec jne 0x4a4b57
004a4aee mov cl, byte ptr [eax + 0xbe]
004a4af4 test cl, cl
004a4af6 je 0x4a4b57
004a4af8 mov ecx, dword ptr [eax + 0xdc]
004a4afe test ecx, ecx
004a4b00 jl 0x4a4b57
004a4b02 test ebp, ebp
004a4b04 jle 0x4a4b57
004a4b06 mov al, byte ptr [0x655a28]
004a4b0b test al, al
004a4b0d je 0x4a4b57
004a4b0f mov edx, dword ptr [0x65741c]
004a4b15 push ebp
004a4b16 lea eax, [esp + 8]
004a4b1a push edx
004a4b1b lea ecx, [esp + 0x7c]
004a4b1f push eax
004a4b20 push 0x256
004a4b25 mov dword ptr [esp + 0x14], ecx
004a4b29 call 0x4edc00
004a4b2e mov ecx, dword ptr [esp + 0x14]
004a4b32 lea edx, [esp + 0x84]
004a4b39 add esp, 0x10
004a4b3c mov dword ptr [ecx], 0
004a4b42 mov eax, dword ptr [esp + 4]
004a4b46 cmp eax, edx
004a4b48 je 0x4a4b57
004a4b4a lea eax, [esp + 0x74]
004a4b4e push eax
004a4b4f call 0x48d550
004a4b54 add esp, 4
004a4b57 cmp dword ptr [0x657440], 1
004a4b5e je 0x4a53e0
004a4b64 push ebx
004a4b65 push esi
004a4b66 push edi
004a4b67 call 0x4ad670
004a4b6c mov esi, eax
004a4b6e call 0x4ad6c0
004a4b73 cmp eax, esi
004a4b75 jge 0x4a4b91
004a4b77 push 0
004a4b79 call 0x5366e0
004a4b7e add esp, 4
004a4b81 call 0x4ad670
004a4b86 mov esi, eax
004a4b88 call 0x4ad6c0
004a4b8d cmp eax, esi
004a4b8f jl 0x4a4b77
004a4b91 mov ecx, dword ptr [0x655a24]
004a4b97 push ecx
004a4b98 call 0x534480
004a4b9d mov edi, dword ptr [0x6573e8]
004a4ba3 add esp, 4
004a4ba6 test ebp, ebp
004a4ba8 je 0x4a4bc3
004a4baa cmp ebp, 5
004a4bad jne 0x4a4f5f
004a4bb3 cmp edi, 9
004a4bb6 je 0x4a4f5f
004a4bbc mov ebp, dword ptr [esp + 0xe8]
004a4bc3 xor ebx, ebx
004a4bc5 cmp ebp, 5
004a4bc8 jne 0x4a4c0f
004a4bca mov edx, dword ptr [0x65b350]
004a4bd0 push 0x657444
004a4bd5 push edx
004a4bd6 lea eax, [esp + 0x88]
004a4bdd push 0x5cccc8
004a4be2 push eax
004a4be3 call 0x5a0fbf
004a4be8 lea ecx, [esp + 0x90]
004a4bef push ecx
004a4bf0 call 0x59dc30
004a4bf5 add esp, 0x14
004a4bf8 test eax, eax
004a4bfa je 0x4a4c0f
004a4bfc lea edx, [esp + 0x80]
004a4c03 push ebx
004a4c04 push edx
004a4c05 call 0x59d8e0
004a4c0a add esp, 8
004a4c0d mov ebx, eax
004a4c0f xor esi, esi
004a4c11 cmp edi, 4
004a4c14 jne 0x4a4c3b
004a4c16 call 0x5032d0
004a4c1b sub eax, 0x209
004a4c20 je 0x4a4c36
004a4c22 dec eax
004a4c23 je 0x4a4c2f
004a4c25 dec eax
004a4c26 jne 0x4a4c3b
004a4c28 mov esi, 3
004a4c2d jmp 0x4a4c3b
004a4c2f mov esi, 2
004a4c34 jmp 0x4a4c3b
004a4c36 mov esi, 1
004a4c3b test ebp, ebp
004a4c3d push esi
004a4c3e jne 0x4a4c52
004a4c40 mov eax, dword ptr [0x65b334]
004a4c45 lea ecx, [esp + 0x20]
004a4c49 push eax
004a4c4a push 0x5d10c0
004a4c4f push ecx
004a4c50 jmp 0x4a4c63
004a4c52 mov edx, dword ptr [0x65b334]
004a4c58 lea eax, [esp + 0x20]
004a4c5c push edx
004a4c5d push 0x5d10b0
004a4c62 push eax
004a4c63 call 0x5a0fbf
004a4c68 add esp, 0x10
004a4c6b lea ecx, [esp + 0x1c]
004a4c6f push 0
004a4c71 push ecx
004a4c72 call 0x59d8e0
004a4c77 add esp, 8
004a4c7a mov esi, eax
004a4c7c xor edi, edi
004a4c7e mov dword ptr [esp + 0x10], edi
004a4c82 lea ebp, [esi + 0x14]
004a4c85 fild dword ptr [esp + 0x10]
004a4c89 push 0x20
004a4c8b push 0x20
004a4c8d push 0
004a4c8f call 0x5a0f98
004a4c94 mov edx, dword ptr [ebp]
004a4c97 push eax
004a4c98 add edx, esi
004a4c9a push edx
004a4c9b call 0x563440
004a4ca0 add edi, 0x20
004a4ca3 add esp, 0x14
004a4ca6 add ebp, 8
004a4ca9 cmp edi, 0x280
004a4caf mov dword ptr [esp + 0x10], edi
004a4cb3 jl 0x4a4c85
004a4cb5 xor edi, edi
004a4cb7 lea ebp, [esi + 0xb4]
004a4cbd mov dword ptr [esp + 0x10], edi
004a4cc1 fild dword ptr [esp + 0x10]
004a4cc5 push 0x40
004a4cc7 push 0x40
004a4cc9 push 0x20
004a4ccb call 0x5a0f98
004a4cd0 push eax
004a4cd1 mov eax, dword ptr [ebp]
004a4cd4 add eax, esi
004a4cd6 push eax
004a4cd7 call 0x563440
004a4cdc add edi, 0x40
004a4cdf add esp, 0x14
004a4ce2 add ebp, 8
004a4ce5 cmp edi, 0x280
004a4ceb mov dword ptr [esp + 0x10], edi
004a4cef jl 0x4a4cc1
004a4cf1 xor edi, edi
004a4cf3 lea ebp, [esi + 0x104]
004a4cf9 mov dword ptr [esp + 0x10], edi
004a4cfd fild dword ptr [esp + 0x10]
004a4d01 push 0x80
004a4d06 push 0x80
004a4d0b push 0x60
004a4d0d call 0x5a0f98
004a4d12 push eax
004a4d13 mov eax, dword ptr [ebp]
004a4d16 mov ecx, esi
004a4d18 add ecx, eax
004a4d1a push ecx
004a4d1b call 0x563440
004a4d20 add edi, 0x80
004a4d26 add esp, 0x14
004a4d29 add ebp, 8
004a4d2c cmp edi, 0x280
004a4d32 mov dword ptr [esp + 0x10], edi
004a4d36 jl 0x4a4cfd
004a4d38 xor edi, edi
004a4d3a lea ebp, [esi + 0x12c]
004a4d40 mov dword ptr [esp + 0x10], edi
004a4d44 fild dword ptr [esp + 0x10]
004a4d48 push 0x80
004a4d4d push 0x80
004a4d52 push 0xe0
004a4d57 call 0x5a0f98
004a4d5c mov edx, dword ptr [ebp]
004a4d5f push eax
004a4d60 add edx, esi
004a4d62 push edx
004a4d63 call 0x563440
004a4d68 add edi, 0x80
004a4d6e add esp, 0x14
004a4d71 add ebp, 8
004a4d74 cmp edi, 0x280
004a4d7a mov dword ptr [esp + 0x10], edi
004a4d7e jl 0x4a4d44
004a4d80 xor edi, edi
004a4d82 lea ebp, [esi + 0x154]
004a4d88 mov dword ptr [esp + 0x10], edi
004a4d8c fild dword ptr [esp + 0x10]
004a4d90 push 0x80
004a4d95 push 0x80
004a4d9a push 0x160
004a4d9f call 0x5a0f98
004a4da4 push eax
004a4da5 mov eax, dword ptr [ebp]
004a4da8 add eax, esi
004a4daa push eax
004a4dab call 0x563440
004a4db0 add edi, 0x80
004a4db6 add esp, 0x14
004a4db9 add ebp, 8
004a4dbc cmp edi, 0x280
004a4dc2 mov dword ptr [esp + 0x10], edi
004a4dc6 jl 0x4a4d8c
004a4dc8 cmp dword ptr [esp + 0xe8], 5
004a4dd0 jne 0x4a4f49
004a4dd6 test ebx, ebx
004a4dd8 je 0x4a4f49
004a4dde mov edi, dword ptr [ebx + 0x14]
004a4de1 mov ebp, 1
004a4de6 add edi, ebx
004a4de8 movsx eax, word ptr [edi + 8]
004a4dec cdq
004a4ded xor eax, edx
004a4def sub eax, edx
004a4df1 mov dword ptr [esp + 0x14], eax
004a4df5 movsx eax, word ptr [edi + 0xa]
004a4df9 fild dword ptr [esp + 0x14]
004a4dfd cdq
004a4dfe fstp dword ptr [esp + 0x10]
004a4e02 xor eax, edx
004a4e04 sub eax, edx
004a4e06 mov dword ptr [esp + 0x14], eax
004a4e0a mov eax, dword ptr [0x65742c]
004a4e0f fild dword ptr [esp + 0x14]
004a4e13 cmp eax, ebp
004a4e15 fstp dword ptr [esp + 0x14]
004a4e19 jne 0x4a4e24
004a4e1b push edi
004a4e1c call 0x563320
004a4e21 add esp, 4
004a4e24 movsx ecx, word ptr [edi + 6]
004a4e28 fld dword ptr [esp + 0x14]
004a4e2c movsx edx, word ptr [edi + 4]
004a4e30 push ecx
004a4e31 push edx
004a4e32 call 0x5a0f98
004a4e37 fld dword ptr [esp + 0x18]
004a4e3b push eax
004a4e3c call 0x5a0f98
004a4e41 push eax
004a4e42 push edi
004a4e43 call 0x563160
004a4e48 mov eax, dword ptr [0x65742c]
004a4e4d add esp, 0x14
004a4e50 cmp eax, ebp
004a4e52 jne 0x4a4e5d
004a4e54 push edi
004a4e55 call 0x563320
004a4e5a add esp, 4
004a4e5d mov ebp, dword ptr [ebx + 0x1c]
004a4e60 add ebp, ebx
004a4e62 movsx eax, word ptr [ebp + 6]
004a4e66 push eax
004a4e67 movsx eax, word ptr [ebp + 0xa]
004a4e6b movsx ecx, word ptr [ebp + 4]
004a4e6f cdq
004a4e70 xor eax, edx
004a4e72 push ecx
004a4e73 sub eax, edx
004a4e75 mov dword ptr [esp + 0x1c], eax
004a4e79 fild dword ptr [esp + 0x1c]
004a4e7d call 0x5a0f98
004a4e82 push eax
004a4e83 movsx eax, word ptr [ebp + 8]
004a4e87 cdq
004a4e88 xor eax, edx
004a4e8a sub eax, edx
004a4e8c mov dword ptr [esp + 0x20], eax
004a4e90 fild dword ptr [esp + 0x20]
004a4e94 call 0x5a0f98
004a4e99 push eax
004a4e9a push ebp
004a4e9b call 0x563160
004a4ea0 mov eax, dword ptr [0x657430]
004a4ea5 add esp, 0x14
004a4ea8 cmp eax, 1
004a4eab jne 0x4a4eb2
004a4ead mov edi, dword ptr [ebx + 0x2c]
004a4eb0 jmp 0x4a4eb5
004a4eb2 mov edi, dword ptr [ebx + 0x24]
004a4eb5 add edi, ebx
004a4eb7 test edi, edi
004a4eb9 je 0x4a4f49
004a4ebf movsx eax, word ptr [edi + 8]
004a4ec3 cdq
004a4ec4 xor eax, edx
004a4ec6 sub eax, edx
004a4ec8 mov dword ptr [esp + 0x14], eax
004a4ecc mov eax, dword ptr [0x65742c]
004a4ed1 fild dword ptr [esp + 0x14]
004a4ed5 cmp eax, 1
004a4ed8 fst dword ptr [esp + 0x10]
004a4edc jne 0x4a4f19
004a4ede push edi
004a4edf fstp st(0)
004a4ee1 call 0x563320
004a4ee6 movsx eax, word ptr [edi + 8]
004a4eea cdq
004a4eeb xor eax, edx
004a4eed add esp, 4
004a4ef0 sub eax, edx
004a4ef2 movsx edx, word ptr [ebp + 4]
004a4ef6 add eax, edx
004a4ef8 mov dword ptr [esp + 0x14], eax
004a4efc movsx eax, word ptr [ebp + 8]
004a4f00 fild dword ptr [esp + 0x14]
004a4f04 cdq
004a4f05 xor eax, edx
004a4f07 sub eax, edx
004a4f09 mov dword ptr [esp + 0x14], eax
004a4f0d fild dword ptr [esp + 0x14]
004a4f11 fsubr dword ptr [esp + 0x10]
004a4f15 fadd st(0), st(0)
004a4f17 fsubp st(1)
004a4f19 movsx eax, word ptr [edi + 6]
004a4f1d push eax
004a4f1e movsx eax, word ptr [edi + 0xa]
004a4f22 movsx ecx, word ptr [edi + 4]
004a4f26 cdq
004a4f27 xor eax, edx
004a4f29 push ecx
004a4f2a sub eax, edx
004a4f2c mov dword ptr [esp + 0x1c], eax
004a4f30 fild dword ptr [esp + 0x1c]
004a4f34 call 0x5a0f98
004a4f39 push eax
004a4f3a call 0x5a0f98
004a4f3f push eax
004a4f40 push edi
004a4f41 call 0x563160
004a4f46 add esp, 0x14
004a4f49 push esi
004a4f4a call 0x531f90
004a4f4f add esp, 4
004a4f52 test ebx, ebx
004a4f54 je 0x4a4f5f
004a4f56 push ebx
004a4f57 call 0x531f90
004a4f5c add esp, 4
004a4f5f mov eax, dword ptr [0x628c70]
004a4f64 test eax, eax
004a4f66 je 0x4a505d
004a4f6c mov ecx, dword ptr [eax + 8]
004a4f6f test ecx, ecx
004a4f71 je 0x4a505d
004a4f77 mov cl, byte ptr [eax + 0xbf]
004a4f7d test cl, cl
004a4f7f jne 0x4a505d
004a4f85 mov cl, byte ptr [eax + 0xbe]
004a4f8b test cl, cl
004a4f8d je 0x4a505d
004a4f93 mov ecx, dword ptr [eax + 0xdc]
004a4f99 test ecx, ecx
004a4f9b jl 0x4a505d
004a4fa1 mov ebx, dword ptr [esp + 0xe8]
004a4fa8 test ebx, ebx
004a4faa je 0x4a4fb5
004a4fac cmp ebx, 5
004a4faf jne 0x4a5064
004a4fb5 mov eax, dword ptr [0x65b334]
004a4fba xor edx, edx
004a4fbc cmp ebx, 5
004a4fbf push eax
004a4fc0 setge dl
004a4fc3 dec edx
004a4fc4 lea ecx, [esp + 0x20]
004a4fc8 and edx, 0xfffffffd
004a4fcb push 0x5d10a0
004a4fd0 add edx, 3
004a4fd3 push ecx
004a4fd4 mov edi, edx
004a4fd6 call 0x5a0fbf
004a4fdb lea edx, [esp + 0x28]
004a4fdf push 0
004a4fe1 push edx
004a4fe2 call 0x59d8e0
004a4fe7 mov esi, eax
004a4fe9 push 0x9e
004a4fee push 0x100
004a4ff3 push 0x142
004a4ff8 mov eax, dword ptr [esi + edi*8 + 0x14]
004a4ffc push 0
004a4ffe add eax, esi
