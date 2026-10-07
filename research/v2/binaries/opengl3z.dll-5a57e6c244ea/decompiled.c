/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 5a57e6c244ea40ea90d69cf13bd3b79144ebca0a980f1d7cb87af48197581f6f */

/* VA 10001000 */

undefined4 __fastcall FUN_10001000(PIXELFORMATDESCRIPTOR *param_1,int *param_2)

{
  uint uVar1;
  BYTE BVar2;
  PIXELFORMATDESCRIPTOR *ppfd;
  ATOM AVar3;
  HDC hdc;
  BOOL BVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  HWND hWnd;
  char *pcVar8;
  undefined4 uVar9;
  char local_224 [400];
  WNDCLASSA local_94;
  undefined4 local_6c;
  uint local_68;
  undefined4 local_64;
  uint local_60;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48 [12];
  int local_18;
  undefined4 local_14;
  int *local_10;
  PIXELFORMATDESCRIPTOR *local_c;
  HWND local_8;

  local_94.lpfnWndProc = DefWindowProcA_exref;
  local_94.hInstance = DAT_1002ba64;
  local_14 = 0;
  local_94.cbClsExtra = 0;
  local_94.cbWndExtra = 0;
  local_94.hIcon = (HICON)0x0;
  local_94.hCursor = (HCURSOR)0x0;
  local_94.hbrBackground = (HBRUSH)0x0;
  local_94.lpszMenuName = (LPCSTR)0x0;
  local_94.style = 0x23;
  local_94.lpszClassName = "40bd3b41-ff62-4227-b8d5-dae24eb338b7";
  local_10 = param_2;
  local_c = param_1;
  AVar3 = RegisterClassA(&local_94);
  if (AVar3 == 0) {
    return 0;
  }
  local_8 = CreateWindowExA(0x40000,"40bd3b41-ff62-4227-b8d5-dae24eb338b7","DUMMY",0x86000000,0,0,1,
                            1,(HWND)0x0,(HMENU)0x0,DAT_1002ba64,(LPVOID)0x0);
  uVar9 = 0;
  if (local_8 == (HWND)0x0) goto LAB_10001376;
  hdc = GetDC(local_8);
  ppfd = local_c;
  BVar2 = (BYTE)DAT_1000c160;
  if (hdc == (HDC)0x0) {
    hWnd = local_8;
    if (DAT_1002ba88 != (code *)0x0) {
      sprintf(local_224,"%s:\n%s\n\n\nFILE %s\nLINE %d","Create","ChoosePixelFormat",
              "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Context.cpp",0x83);
      (*DAT_1002ba88)(0,local_224);
      hWnd = local_8;
    }
  }
  else {
    local_48[0] = 0;
    local_48[1] = 0;
    local_48[2] = 0;
    local_48[3] = 0;
    local_48[4] = 0;
    local_48[5] = 0;
    local_48[6] = 0;
    local_48[7] = 0;
    local_48[8] = 0;
    local_48[9] = 0;
    puVar7 = local_48;
    for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
      uVar1 = *puVar7;
      param_1->nSize = (short)uVar1;
      param_1->nVersion = (short)(uVar1 >> 0x10);
      puVar7 = puVar7 + 1;
      param_1 = (PIXELFORMATDESCRIPTOR *)&param_1->dwFlags;
    }
    local_c->cColorBits = BVar2;
    BVar2 = DAT_1000c164;
    local_c->nSize = 0x28;
    local_c->nVersion = 1;
    local_c->dwFlags = 0x225;
    local_c->cDepthBits = BVar2;
    local_c->cStencilBits = '\b';
    iVar6 = ChoosePixelFormat(hdc,local_c);
    *local_10 = iVar6;
    if (iVar6 == 0) {
      if (DAT_1002ba88 != (code *)0x0) {
        uVar9 = 0x7e;
        pcVar8 = "ChoosePixelFormat";
LAB_100012f2:
        sprintf(local_224,"%s:\n%s\n\n\nFILE %s\nLINE %d","Create",pcVar8,
                "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Context.cpp",uVar9);
        (*DAT_1002ba88)(0,local_224);
      }
    }
    else {
      BVar4 = SetPixelFormat(hdc,iVar6,ppfd);
      if (BVar4 == 0) {
        if (DAT_1002ba88 != (code *)0x0) {
          uVar9 = 0x7b;
          pcVar8 = "SetPixelFormat";
          goto LAB_100012f2;
        }
      }
      else {
        iVar6 = (*DAT_1000c03c)(hdc);
        if (iVar6 != 0) {
          iVar5 = (*DAT_1000c028)(hdc,iVar6);
          if (iVar5 == 0) {
            if (DAT_1002ba88 != (code *)0x0) {
              sprintf(local_224,"%s:\n%s\n\n\nFILE %s\nLINE %d","Create","WGLMakeCurrent",
                      "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Context.cpp",0x73);
              (*DAT_1002ba88)(0,local_224);
            }
            (*DAT_1000c034)(iVar6);
            hWnd = local_8;
            ReleaseDC(local_8,hdc);
          }
          else {
            FUN_100019b0("wgl","ChoosePixelFormat",(int *)&DAT_1000c030,"ARB");
            if (DAT_1000c030 != (code *)0x0) {
              uVar1 = ppfd->dwFlags;
              local_68 = uVar1 >> 2 & 1;
              local_6c = 0x2001;
              local_60 = uVar1 >> 5 & 1;
              local_64 = 0x2010;
              local_58 = uVar1 & 1;
              local_48[0] = (uint)ppfd->cColorBits;
              local_48[8] = ~(uVar1 >> 9) & 1 | 0x2028;
              local_48[2] = (uint)ppfd->cDepthBits;
              local_48[4] = (uint)ppfd->cStencilBits;
              local_5c = 0x2011;
              local_54 = 0x2013;
              local_50 = 0x202b;
              local_4c = 0x2014;
              local_48[1] = 0x2022;
              local_48[3] = 0x2023;
              local_48[5] = 0x2003;
              local_48[6] = 0x2027;
              local_48[7] = 0x2007;
              local_48[9] = 0;
              iVar5 = (*DAT_1000c030)(hdc,&local_6c,0,1,&local_18,&local_c);
              if ((iVar5 != 0) && (local_c != (PIXELFORMATDESCRIPTOR *)0x0)) {
                *local_10 = local_18;
              }
            }
            local_14 = 1;
            (*DAT_1000c028)(hdc,0);
            (*DAT_1000c034)(iVar6);
            hWnd = local_8;
            ReleaseDC(local_8,hdc);
          }
          goto LAB_1000136c;
        }
        if (DAT_1002ba88 != (code *)0x0) {
          uVar9 = 0x78;
          pcVar8 = "WGLCreateContext";
          goto LAB_100012f2;
        }
      }
    }
    hWnd = local_8;
    ReleaseDC(local_8,hdc);
  }
LAB_1000136c:
  DestroyWindow(hWnd);
  uVar9 = local_14;
LAB_10001376:
  UnregisterClassA("40bd3b41-ff62-4227-b8d5-dae24eb338b7",DAT_1002ba64);
  return uVar9;
}



/* VA 10001390 */

void FUN_10001390(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  BOOL BVar4;
  DWORD DVar5;
  undefined4 *puVar6;
  PIXELFORMATDESCRIPTOR *pPVar7;
  char local_37c [400];
  char local_1ec [404];
  undefined4 local_58 [10];
  PIXELFORMATDESCRIPTOR local_30;
  int local_8;

  if (DAT_1000c1b0 == 0) {
    if (DAT_1002ba68 == (HDC)0x0) {
      DAT_1002ba68 = GetDC(DAT_1002ba60);
    }
    iVar2 = GetPixelFormat(DAT_1002ba68);
    if (iVar2 == 0) {
      iVar3 = FUN_10001000(&local_30,&local_8);
      iVar2 = local_8;
      if (iVar3 == 0) {
        iVar2 = ChoosePixelFormat(DAT_1002ba68,&local_30);
        local_8 = iVar2;
        if (iVar2 == 0) {
          if ((((byte)local_30.dwFlags & 0x80) != 0) && (DAT_1002ba88 != (code *)0x0)) {
            sprintf(local_1ec,"%s:\n%s\n\n\nFILE %s\nLINE %d","Create","Needs palette",
                    "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Context.cpp",0xa0);
            (*DAT_1002ba88)(0,local_1ec);
          }
        }
        else if (DAT_1002ba88 != (code *)0x0) {
          sprintf(local_37c,"%s:\n%s\n\n\nFILE %s\nLINE %d","Create","ChoosePixelFormat failed",
                  "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Context.cpp",0x9e);
          (*DAT_1002ba88)(0,local_37c);
        }
      }
      BVar4 = SetPixelFormat(DAT_1002ba68,iVar2,&local_30);
      if ((BVar4 == 0) && (DVar5 = GetLastError(), DAT_1002ba88 != (code *)0x0)) {
        sprintf(local_1ec,"%s:\n%s\n\n\nFILE %s\nLINE %d","Create","SetPixelFormat failed",
                "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Context.cpp",DVar5);
        (*DAT_1002ba88)(0,local_1ec);
      }
      iVar2 = local_8;
      local_58[0] = 0;
      local_58[1] = 0;
      local_58[2] = 0;
      local_58[3] = 0;
      local_58[4] = 0;
      local_58[5] = 0;
      local_58[6] = 0;
      local_58[7] = 0;
      local_58[8] = 0;
      local_58[9] = 0;
      puVar6 = local_58;
      pPVar7 = &local_30;
      for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
        uVar1 = *puVar6;
        pPVar7->nSize = (short)uVar1;
        pPVar7->nVersion = (short)((uint)uVar1 >> 0x10);
        puVar6 = puVar6 + 1;
        pPVar7 = (PIXELFORMATDESCRIPTOR *)&pPVar7->dwFlags;
      }
      local_30.nSize = 0x28;
      local_30.nVersion = 1;
      iVar2 = DescribePixelFormat(DAT_1002ba68,iVar2,0x28,&local_30);
      if ((iVar2 == 0) && (DAT_1002ba88 != (code *)0x0)) {
        sprintf(local_1ec,"%s:\n%s\n\n\nFILE %s\nLINE %d","Create","DescribePixelFormat failed",
                "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Context.cpp",0xa8);
        (*DAT_1002ba88)(0,local_1ec);
      }
      if (((((local_30.iPixelType != '\0') || (local_30.cRedBits < 5)) || (local_30.cGreenBits < 5))
          || (local_30.cBlueBits < 5)) && (DAT_1002ba88 != (code *)0x0)) {
        sprintf(local_37c,"%s:\n%s\n\n\nFILE %s\nLINE %d","Create","Bad pixel type",
                "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Context.cpp",0xab);
        (*DAT_1002ba88)(0,local_37c);
      }
    }
    DAT_1000c1b0 = (*DAT_1000c03c)(DAT_1002ba68);
    (*DAT_1000c028)(DAT_1002ba68,DAT_1000c1b0);
    FUN_10001ac0();
    if (DAT_1000c170 != 0) {
      if (DAT_1000c02c == (code *)0x0) {
        DAT_1000c170 = 0;
      }
      else {
        (*DAT_1000c02c)(1);
      }
    }
    DAT_1000c150 = FUN_10002220(0x3e9,0x8b31);
    DAT_1000c14c = FUN_10002220(0x3ea,0x8b30);
    DAT_1000c154 = (*DAT_1000c11c)();
    (*DAT_1000c138)(DAT_1000c154,DAT_1000c150);
    (*DAT_1000c138)(DAT_1000c154,DAT_1000c14c);
    (*DAT_1000c060)(DAT_1000c154);
    (*DAT_1000c13c)(DAT_1000c154);
    DAT_1000c1bc = (*DAT_1000c100)(DAT_1000c154,&DAT_1000a714);
    DAT_1000c1b4 = (*DAT_1000c100)(DAT_1000c154,"texEnabled");
    DAT_1000c1ec = (*DAT_1000c100)(DAT_1000c154,"shadeModel");
    DAT_1000c1d8 = (*DAT_1000c100)(DAT_1000c154,"alphaFunc");
    DAT_1000c1c4 = (*DAT_1000c100)(DAT_1000c154,"alphaValue");
    DAT_1000c1c8 = (*DAT_1000c100)(DAT_1000c154,"fogMode");
    DAT_1000c1d4 = (*DAT_1000c100)(DAT_1000c154,"fogColor");
    DAT_1000c1c0 = (*DAT_1000c100)(DAT_1000c154,"fogStart");
    DAT_1000c1cc = (*DAT_1000c100)(DAT_1000c154,"fogEnd");
    DAT_1000c1f0 = (*DAT_1000c100)(DAT_1000c154,"fogDensity");
    DAT_1000c1e8 = (*DAT_1000c100)(DAT_1000c154,"specularEnabled");
    DAT_1000c1e0 = (*DAT_1000c100)(DAT_1000c154,"gamma");
    DAT_1000c1e4 = (*DAT_1000c09c)(DAT_1000c154,"vCoord");
    DAT_1000c1d0 = (*DAT_1000c09c)(DAT_1000c154,"vDiffuse");
    DAT_1000c1b8 = (*DAT_1000c09c)(DAT_1000c154,"vSpecular");
    DAT_1000c1dc = (*DAT_1000c09c)(DAT_1000c154,"vTexCoord");
    DAT_1000d2dc = &DAT_1000d2e0;
    (*DAT_1000c120)(1,&DAT_1000d2c8);
    (*DAT_1000c108)(DAT_1000d2c8);
    (*DAT_1000c078)(1,&DAT_1000d2cc);
    (*DAT_1000c058)(0x8892,DAT_1000d2cc);
    FUN_100089a0();
    DAT_1000d2d0 = 0;
  }
  return;
}



/* VA 10001830 */

void FUN_10001830(void)

{
  void *pvVar1;
  void *_Memory;

  if (DAT_1000c1b0 != 0) {
    (*DAT_1000c038)();
    if (DAT_1000d2c4 != 0) {
      FUN_10005450(1,0,(undefined *)0x0);
      _Memory = (void *)DAT_1000d2c4;
      do {
        pvVar1 = *(void **)((int)_Memory + 0x4c);
        (*DAT_1000c090)(1,_Memory);
        if (*(void **)((int)_Memory + 0x38) != (void *)0x0) {
          if (DAT_1002ba94 == (code *)0x0) {
            free(*(void **)((int)_Memory + 0x38));
          }
          else {
            (*DAT_1002ba94)();
          }
        }
        if (*(void **)((int)_Memory + 0x3c) != (void *)0x0) {
          if (DAT_1002ba94 == (code *)0x0) {
            free(*(void **)((int)_Memory + 0x3c));
          }
          else {
            (*DAT_1002ba94)();
          }
        }
        if (*(void **)((int)_Memory + 0x40) != (void *)0x0) {
          if (DAT_1002ba94 == (code *)0x0) {
            free(*(void **)((int)_Memory + 0x40));
          }
          else {
            (*DAT_1002ba94)();
          }
        }
        if (DAT_1002ba94 == (code *)0x0) {
          free(_Memory);
        }
        else {
          (*DAT_1002ba94)();
        }
        _Memory = pvVar1;
      } while (pvVar1 != (void *)0x0);
      DAT_1000d2c4 = 0;
    }
    (*DAT_1000c13c)(0);
    (*DAT_1000c0fc)(DAT_1000c154);
    (*DAT_1000c108)(0);
    (*DAT_1000c0f4)(1,&DAT_1000d2c8);
    (*DAT_1000c058)(0x8892,0);
    (*DAT_1000c0dc)(1,&DAT_1000d2cc);
    (*DAT_1000c028)(DAT_1002ba68,0);
    (*DAT_1000c034)(DAT_1000c1b0);
    DAT_1000c1b0 = 0;
  }
  if (DAT_1002ba68 != (HDC)0x0) {
    ReleaseDC(DAT_1002ba60,DAT_1002ba68);
    DAT_1002ba68 = (HDC)0x0;
  }
  return;
}



/* VA 10001980 */

undefined4 entry(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DAT_1002ba64 = param_1;
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* VA 100019b0 */

void __fastcall FUN_100019b0(char *param_1,char *param_2,int *param_3,char *param_4)

{
  char cVar1;
  int iVar2;
  FARPROC pFVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  CHAR local_108 [256];
  char *local_8;

  local_8 = param_2;
  pcVar7 = param_1;
  do {
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar7[(int)(local_108 + (-1 - (int)param_1))] = cVar1;
    pcVar5 = param_2;
  } while (cVar1 != '\0');
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar6 = (int)pcVar5 - (int)param_2;
  pcVar7 = &stack0xfffffef7;
  do {
    pcVar5 = pcVar7 + 1;
    pcVar7 = pcVar7 + 1;
  } while (*pcVar5 != '\0');
  for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)param_2;
    param_2 = param_2 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar7 = *param_2;
    param_2 = param_2 + 1;
    pcVar7 = pcVar7 + 1;
  }
  pcVar7 = param_4;
  if (param_4 != (char *)0x0) {
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    uVar6 = (int)pcVar7 - (int)param_4;
    pcVar7 = &stack0xfffffef7;
    do {
      pcVar5 = pcVar7 + 1;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar5 != '\0');
    pcVar5 = param_4;
    for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar7 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    }
  }
  if (DAT_1000c0b0 != (code *)0x0) {
    iVar2 = (*DAT_1000c0b0)(local_108);
    *param_3 = iVar2;
  }
  if (*param_3 + 1U < 5) {
    if (DAT_1000c0a4 == (HMODULE)0x0) {
      DAT_1000c0a4 = GetModuleHandleA("OPENGL32.dll");
    }
    pFVar3 = GetProcAddress(DAT_1000c0a4,local_108);
    pcVar7 = local_8;
    *param_3 = (int)pFVar3;
    if (((pFVar3 == (FARPROC)0x0) && (param_4 == (char *)0x0)) &&
       (FUN_100019b0(param_1,local_8,param_3,"EXT"), *param_3 == 0)) {
      FUN_100019b0(param_1,pcVar7,param_3,"ARB");
    }
  }
  return;
}



/* VA 10001ac0 */

void FUN_10001ac0(void)

{
  char cVar1;
  int iVar2;
  DWORD DVar3;
  byte bVar4;
  code *pcVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 uVar8;
  char local_1ac [400];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;

  uVar8 = DAT_1002ba68;
  FUN_100019b0("wgl","wglCreateContextAttribs",(int *)&DAT_1000c0f8,"ARB");
  pcVar5 = sprintf_exref;
  if (DAT_1000c0f8 != (code *)0x0) {
    local_1c = 0x2091;
    local_18 = 3;
    local_14 = 0x2092;
    local_10 = 0;
    local_c = 0;
    iVar2 = (*DAT_1000c0f8)(uVar8,0,&local_1c);
    if (iVar2 == 0) {
      DVar3 = GetLastError();
      if (DVar3 == 0x2095) {
        if (DAT_1002ba88 != (code *)0x0) {
          uVar8 = 0xaa;
          pcVar7 = "Invalid version";
LAB_10001b95:
          sprintf(local_1ac,"%s:\n%s\n\n\nFILE %s\nLINE %d","CreateContextAttribs",pcVar7,
                  "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\GL.cpp",uVar8);
          (*DAT_1002ba88)(0,local_1ac);
        }
      }
      else if ((DVar3 == 0x2096) && (DAT_1002ba88 != (code *)0x0)) {
        uVar8 = 0xac;
        pcVar7 = "Invalid profile";
        goto LAB_10001b95;
      }
    }
    else {
      (*DAT_1000c028)(uVar8,iVar2);
      (*DAT_1000c034)(DAT_1000c1b0);
      DAT_1000c1b0 = iVar2;
    }
  }
  FUN_100019b0("wgl","SwapInterval",&DAT_1000c02c,"EXT");
  FUN_100019b0("gl","GetString",(int *)&DAT_1000c0e8,(char *)0x0);
  FUN_100019b0("gl","Flush",&DAT_1000c068,(char *)0x0);
  FUN_100019b0("gl","Finish",&DAT_1000c038,(char *)0x0);
  FUN_100019b0("gl","Scissor",&DAT_1000c12c,(char *)0x0);
  FUN_100019b0("gl","Viewport",&DAT_1000c118,(char *)0x0);
  FUN_100019b0("gl","Hint",&DAT_1000c148,(char *)0x0);
  FUN_100019b0("gl","ClearDepth",&DAT_1000c144,(char *)0x0);
  FUN_100019b0("gl","DepthRange",&DAT_1000c114,(char *)0x0);
  FUN_100019b0("gl","Clear",&DAT_1000c0e0,(char *)0x0);
  FUN_100019b0("gl","ReadBuffer",&DAT_1000c040,(char *)0x0);
  FUN_100019b0("gl","DrawBuffer",&DAT_1000c08c,(char *)0x0);
  FUN_100019b0("gl","ReadPixels",&DAT_1000c0e4,(char *)0x0);
  FUN_100019b0("gl","Enable",&DAT_1000c080,(char *)0x0);
  FUN_100019b0("gl","Disable",&DAT_1000c05c,(char *)0x0);
  FUN_100019b0("gl","BindTexture",&DAT_1000c084,(char *)0x0);
  FUN_100019b0("gl","DeleteTextures",&DAT_1000c090,(char *)0x0);
  FUN_100019b0("gl","ClearColor",&DAT_1000c0bc,(char *)0x0);
  FUN_100019b0("gl","DepthFunc",&DAT_1000c07c,(char *)0x0);
  FUN_100019b0("gl","BlendFunc",&DAT_1000c0d8,(char *)0x0);
  FUN_100019b0("gl","TexParameteri",&DAT_1000c064,(char *)0x0);
  FUN_100019b0("gl","TexParameterf",&DAT_1000c088,(char *)0x0);
  FUN_100019b0("gl","TexImage2D",&DAT_1000c0b8,(char *)0x0);
  FUN_100019b0("gl","TexSubImage2D",&DAT_1000c0c4,(char *)0x0);
  FUN_100019b0("gl","DepthMask",&DAT_1000c130,(char *)0x0);
  FUN_100019b0("gl","StencilFunc",&DAT_1000c050,(char *)0x0);
  FUN_100019b0("gl","StencilOp",&DAT_1000c044,(char *)0x0);
  FUN_100019b0("gl","ActiveTexture",&DAT_1000c128,(char *)0x0);
  FUN_100019b0("gl","GetIntegerv",(int *)&DAT_1000c06c,(char *)0x0);
  FUN_100019b0("gl","GenTextures",&DAT_1000c098,(char *)0x0);
  FUN_100019b0("gl","GenBuffers",&DAT_1000c078,(char *)0x0);
  FUN_100019b0("gl","DeleteBuffers",&DAT_1000c0dc,(char *)0x0);
  FUN_100019b0("gl","BindBuffer",&DAT_1000c058,(char *)0x0);
  FUN_100019b0("gl","BufferData",&DAT_1000c0c0,(char *)0x0);
  FUN_100019b0("gl","MapBufferRange",&DAT_1000c0a0,(char *)0x0);
  FUN_100019b0("gl","UnmapBuffer",&DAT_1000c10c,(char *)0x0);
  FUN_100019b0("gl","FlushMappedBufferRange",(int *)&DAT_1000c104,(char *)0x0);
  FUN_100019b0("gl","DrawArrays",&DAT_1000c0a8,(char *)0x0);
  FUN_100019b0("gl","DrawElements",(int *)&DAT_1000c0d4,(char *)0x0);
  FUN_100019b0("gl","GenVertexArrays",&DAT_1000c120,(char *)0x0);
  FUN_100019b0("gl","BindVertexArray",&DAT_1000c108,(char *)0x0);
  FUN_100019b0("gl","DeleteVertexArrays",&DAT_1000c0f4,(char *)0x0);
  FUN_100019b0("gl","EnableVertexAttribArray",&DAT_1000c0ec,(char *)0x0);
  FUN_100019b0("gl","DisableVertexAttribArray",(int *)&DAT_1000c048,(char *)0x0);
  FUN_100019b0("gl","VertexAttribPointer",&DAT_1000c0c8,(char *)0x0);
  FUN_100019b0("gl","VertexAttribIPointer",(int *)&DAT_1000c054,(char *)0x0);
  FUN_100019b0("gl","CreateShader",&DAT_1000c124,(char *)0x0);
  FUN_100019b0("gl","CreateProgram",&DAT_1000c11c,(char *)0x0);
  FUN_100019b0("gl","ShaderSource",&DAT_1000c0f0,(char *)0x0);
  FUN_100019b0("gl","CompileShader",&DAT_1000c134,(char *)0x0);
  FUN_100019b0("gl","AttachShader",&DAT_1000c138,(char *)0x0);
  FUN_100019b0("gl","LinkProgram",&DAT_1000c060,(char *)0x0);
  FUN_100019b0("gl","UseProgram",&DAT_1000c13c,(char *)0x0);
  FUN_100019b0("gl","DeleteProgram",&DAT_1000c0fc,(char *)0x0);
  FUN_100019b0("gl","GetShaderiv",&DAT_1000c070,(char *)0x0);
  FUN_100019b0("gl","GetShaderInfoLog",&DAT_1000c0cc,(char *)0x0);
  FUN_100019b0("gl","GetAttribLocation",&DAT_1000c09c,(char *)0x0);
  FUN_100019b0("gl","GetUniformLocation",&DAT_1000c100,(char *)0x0);
  FUN_100019b0("gl","Uniform1i",(int *)&DAT_1000c094,(char *)0x0);
  FUN_100019b0("gl","Uniform1ui",&DAT_1000c0ac,(char *)0x0);
  FUN_100019b0("gl","Uniform1f",&DAT_1000c04c,(char *)0x0);
  FUN_100019b0("gl","Uniform4f",&DAT_1000c074,(char *)0x0);
  FUN_100019b0("gl","UniformMatrix4fv",&DAT_1000c0b4,(char *)0x0);
  if (DAT_1000c0e8 == (code *)0x0) {
    DAT_1000c140 = 0x110;
  }
  else {
    DAT_1000c140 = 0;
    local_8 = (*DAT_1000c0e8)(0x1f02);
    uVar6 = 0;
    bVar4 = 8;
    while( true ) {
      while (cVar1 = *(char *)((uVar6 & 0xffff) + local_8), (byte)(cVar1 - 0x30U) < 10) {
        DAT_1000c140 = DAT_1000c140 + (cVar1 + -0x30 << (bVar4 & 0x1f));
        uVar6 = uVar6 + 1;
        bVar4 = bVar4 - 4;
      }
      if (cVar1 != '.') break;
      uVar6 = uVar6 + 1;
    }
    pcVar5 = sprintf_exref;
    if (0x2ff < DAT_1000c140) goto LAB_100021fa;
  }
  if (DAT_1002ba88 != (code *)0x0) {
    (*pcVar5)(local_1ac,"%s:\n%s\n\n\nFILE %s\nLINE %d","CreateContextAttribs",
              "OpenGL 3.0 is required","D:\\Work\\Tharsh\\Thrash.OpenGL.3\\GL.cpp",0x112);
    (*DAT_1002ba88)(0,local_1ac);
  }
LAB_100021fa:
  (*DAT_1000c06c)(0xc00,&DAT_1000c0d0);
  return;
}



/* VA 10002220 */

undefined4 __fastcall FUN_10002220(uint param_1,int param_2)

{
  HRSRC hResInfo;
  HGLOBAL hResData;
  undefined4 uVar1;
  char *pcVar2;
  char local_338 [400];
  char local_1a8 [40];
  undefined1 local_180 [360];
  LPVOID local_18;
  DWORD local_14;
  LPVOID local_10;
  int local_c;
  int local_8;

  local_c = param_2;
  hResInfo = FindResourceA(DAT_1002ba64,(LPCSTR)(param_1 & 0xffff),(LPCSTR)0xa);
  if ((hResInfo == (HRSRC)0x0) && (DAT_1002ba88 != (code *)0x0)) {
    sprintf(local_1a8,"%s:\n%s\n\n\nFILE %s\nLINE %d","CompileFromResource","FindResource failed",
            "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Shaders.cpp",0x2a);
    (*DAT_1002ba88)(0,local_1a8);
  }
  hResData = LoadResource(DAT_1002ba64,hResInfo);
  if ((hResData == (HGLOBAL)0x0) && (DAT_1002ba88 != (code *)0x0)) {
    sprintf(local_1a8,"%s:\n%s\n\n\nFILE %s\nLINE %d","CompileFromResource","LoadResource failed",
            "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Shaders.cpp",0x2e);
    (*DAT_1002ba88)(0,local_1a8);
  }
  local_10 = LockResource(hResData);
  if ((local_10 == (LPVOID)0x0) && (DAT_1002ba88 != (code *)0x0)) {
    sprintf(local_1a8,"%s:\n%s\n\n\nFILE %s\nLINE %d","CompileFromResource","LockResource failed",
            "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Shaders.cpp",0x32);
    (*DAT_1002ba88)(0,local_1a8);
  }
  uVar1 = (*DAT_1000c124)(local_c);
  local_18 = local_10;
  local_14 = SizeofResource(DAT_1002ba64,hResInfo);
  (*DAT_1000c0f0)(uVar1,1,&local_18,&local_14);
  (*DAT_1000c134)(uVar1);
  (*DAT_1000c070)(uVar1,0x8b81,&local_8);
  if (local_8 == 0) {
    (*DAT_1000c070)(uVar1,0x8b84,&local_8);
    if (local_8 == 0) {
      if (DAT_1002ba88 == (code *)0x0) {
        return uVar1;
      }
      pcVar2 = "[VERTEX SHADER]";
      if (local_c != 0x8b31) {
        pcVar2 = "[FRAGMENT SHADER]";
      }
      sprintf(local_1a8,"%s:\n%s\n\n\nFILE %s\nLINE %d",pcVar2,"Compile shader failed",
              "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Shaders.cpp",0x42);
      pcVar2 = local_1a8;
    }
    else {
      (*DAT_1000c0cc)(uVar1,0x168,&local_8,local_180);
      if (DAT_1002ba88 == (code *)0x0) {
        return uVar1;
      }
      pcVar2 = "[VERTEX SHADER]";
      if (local_c != 0x8b31) {
        pcVar2 = "[FRAGMENT SHADER]";
      }
      sprintf(local_338,"%s:\n%s\n\n\nFILE %s\nLINE %d",pcVar2,local_180,
              "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Shaders.cpp",0x48);
      pcVar2 = local_338;
    }
    (*DAT_1002ba88)(0,pcVar2);
  }
  return uVar1;
}



/* VA 10002440 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10002440(void)

{
  char cVar1;
  float fVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  CHAR local_10c [260];
  float local_8;

  if (DAT_1000c2c0 == 0) {
    DAT_1000c2c0 = 1;
    GetModuleFileNameA(DAT_1002ba64,local_10c,0x104);
    pcVar4 = strrchr(local_10c,0x2e);
    *pcVar4 = '\0';
    iVar5 = 0;
    do {
      cVar1 = local_10c[iVar5];
      *(char *)((int)&DAT_1002baa0 + iVar5) = cVar1;
      iVar5 = iVar5 + 1;
    } while (cVar1 != '\0');
    puVar3 = (undefined4 *)((int)&DAT_1002ba9c + 3);
    do {
      puVar6 = puVar3;
      puVar3 = (undefined4 *)((int)puVar6 + 1);
    } while (*(char *)((int)puVar6 + 1) != '\0');
    *(undefined4 *)((int)puVar6 + 1) = DAT_1000a7c4;
    *(undefined1 *)((int)puVar6 + 5) = DAT_1000a7c8;
    DAT_1000c158 = FUN_10009740("WINDOWED");
    DAT_1000c15c = FUN_10009740("RESOLUTION");
    if ((DAT_1000c15c != 0) && (0x1c < DAT_1000c15c)) {
      DAT_1000c15c = 0;
    }
    DAT_1000c160 = FUN_10009740("COLORDEPTH");
    if (((DAT_1000c160 != 0x10) && (DAT_1000c160 != 0x18)) && (DAT_1000c160 != 0x20)) {
      DAT_1000c160 = 0x20;
    }
    _DAT_1000c164 = FUN_10009740("ZDEPTH");
    if (((_DAT_1000c164 != 0x10) && (_DAT_1000c164 != 0x18)) && (_DAT_1000c164 != 0x20)) {
      _DAT_1000c164 = 0x18;
    }
    DAT_1000c168 = FUN_10009740("REFRESH");
    if ((DAT_1000c168 != 0) && (9 < DAT_1000c168)) {
      DAT_1000c168 = 0;
    }
    DAT_1000c16c = FUN_10009740("EXCLUSIVE");
    DAT_1000c170 = FUN_10009740("VSYNC");
    DAT_1000c174 = FUN_10009740("ASPECT");
    DAT_1000c17c = FUN_10009740("TEXFILTER");
    if ((DAT_1000c17c != 0) && (2 < DAT_1000c17c)) {
      DAT_1000c17c = 0;
    }
    DAT_1000c180 = FUN_10009740("ADD640X480X16");
    DAT_1000c184 = FUN_10009740("MOVIES16BIT");
    iVar5 = FUN_10009740("GAMMA");
    fVar2 = (float)iVar5;
    if (iVar5 < 0) {
      fVar2 = fVar2 + _DAT_1000b000;
    }
    local_8 = fVar2 * (float)_DAT_1000afd0 + (float)_DAT_1000afe0;
    if ((local_8 < _DAT_1000afc8) || (_DAT_1000c178 = local_8, _DAT_1000afd8 < local_8)) {
      _DAT_1000c178 = 1.0;
    }
    _DAT_1000c014 = 1.0 / _DAT_1000c178;
    DAT_1000c188 = FUN_10009740("TEX_CONVERT_ARGB32");
    DAT_1000c18c = FUN_10009740("TEX_COLOR_INDEX_4");
    DAT_1000c190 = FUN_10009740("TEX_COLOR_INDEX_8");
    DAT_1000c194 = FUN_10009740("TEX_COLOR_ARGB_1555");
    DAT_1000c198 = FUN_10009740("TEX_COLOR_RGB_565");
    DAT_1000c19c = FUN_10009740("TEX_COLOR_RGB_888");
    DAT_1000c1a0 = FUN_10009740("TEX_COLOR_ARGB_8888");
    DAT_1000c1a4 = FUN_10009740("TEX_COLOR_ARGB_4444");
    DAT_1000c1a8 = FUN_10009740("TEX_INDEX_RGB");
    DAT_1000c1ac = FUN_10009740("TEX_INDEX_ARGB");
    FUN_10004b20();
  }
  return;
}



/* VA 10002750 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * _THRASH_about_0(void)

{
                    /* 0x2750  1  _THRASH_about@0 */
  if (DAT_1002bba4 == 0) {
    FUN_10002440();
    _DAT_1002bba0 = DAT_1000a90c;
    DAT_1002bbec = s_OpenGL_3_0_1000a914[0];
    DAT_1002bbec_1._0_1_ = s_OpenGL_3_0_1000a914[1];
    DAT_1002bbec_1._1_1_ = s_OpenGL_3_0_1000a914[2];
    DAT_1002bbec_1._2_1_ = s_OpenGL_3_0_1000a914[3];
    DAT_1002bbf0 = s_OpenGL_3_0_1000a914[4];
    DAT_1002bbf0_1._0_1_ = s_OpenGL_3_0_1000a914[5];
    DAT_1002bbf0_1._1_1_ = s_OpenGL_3_0_1000a914[6];
    DAT_1002bbf0_1._2_1_ = s_OpenGL_3_0_1000a914[7];
    DAT_1002bbf4 = s_OpenGL_3_0_1000a914[8];
    register0x00000001 = s_OpenGL_3_0_1000a914[9];
    DAT_1002bbf6 = s_OpenGL_3_0_1000a914[10];
    DAT_1002bc20 = s_D3D_Device_1000a920[0];
    DAT_1002bc20_1._0_1_ = s_D3D_Device_1000a920[1];
    DAT_1002bc20_1._1_1_ = s_D3D_Device_1000a920[2];
    DAT_1002bc20_1._2_1_ = s_D3D_Device_1000a920[3];
    DAT_1002bc24 = s_D3D_Device_1000a920[4];
    DAT_1002bc24_1._0_1_ = s_D3D_Device_1000a920[5];
    DAT_1002bc24_1._1_1_ = s_D3D_Device_1000a920[6];
    DAT_1002bc24_1._2_1_ = s_D3D_Device_1000a920[7];
    DAT_1002bc28 = s_D3D_Device_1000a920[8];
    register0x00000001 = s_D3D_Device_1000a920[9];
    DAT_1002bc2a = s_D3D_Device_1000a920[10];
    _DAT_1002bba8 = DAT_1000c004;
    _DAT_1000c214 = DAT_1000c18c;
    _DAT_1000c218 = DAT_1000c190;
    _DAT_1000c21c = DAT_1000c194;
    _DAT_1000c220 = DAT_1000c198;
    _DAT_1000c224 = DAT_1000c19c;
    _DAT_1000c228 = DAT_1000c1a0;
    _DAT_1000c22c = DAT_1000c1a4;
    _DAT_1000c268 = DAT_1000c1a8;
    _DAT_1000c26c = DAT_1000c1ac;
    _DAT_1002bbdc = DAT_1000d2a0 + 1;
    DAT_1002bba4 = 0xa0;
    _DAT_1002bbac = 0xe;
    _DAT_1002bbb0 = 2;
    DAT_1002bbb4 = 0x200;
    _DAT_1002bbb8 = 8;
    _DAT_1002bbbc = 2;
    DAT_1002bbc0 = 0x200;
    _DAT_1002bbc4 = 8;
    _DAT_1002bbc8 = 0;
    _DAT_1002bbcc = 0x12;
    DAT_1002bbd0 = &DAT_1000c210;
    _DAT_1002bbd4 = 5;
    DAT_1002bbd8 = &DAT_1000c25c;
    _DAT_1002bbe0 = &DAT_1000c2f8;
    _DAT_1002bc0c = 4;
    _DAT_1002bc10 = 0x4000000;
    _DAT_1002bc14 = 3;
    _DAT_1002bbe4 = 4;
    _DAT_1002bc18 = "AUTHOR: Oleksiy Ryabchun, Sat Nov 13 00:15:34 2021";
    _DAT_1002bc1c = 7;
    FUN_10009830((int *)&DAT_1002bba0);
  }
  return &DAT_1002bba0;
}



/* VA 10002910 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _THRASH_clip_16(uint param_1,int param_2,uint param_3,uint param_4)

{
  double dVar1;
  float fVar2;
  int *piVar3;
  uint uVar4;
  bool bVar5;
  double dVar6;

  piVar3 = (int *)&DAT_1000c2e0;
  uVar4 = 0xc;
  do {
    register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4);
    if (*(int *)register0x00000010 != *piVar3) {
      DAT_1000c2e4 = param_2;
      DAT_1000c2e0 = param_1;
      DAT_1000c2e8 = param_3;
      DAT_1000c2ec = param_4;
      FUN_10008a60();
      uVar4 = DAT_1000c284;
      if ((0 < (int)param_1) &&
         ((DAT_1000c284 != 0 || (uVar4 = param_1, DAT_1000c28c != *DAT_1000d2a4)))) {
        fVar2 = (float)(int)param_1 * _DAT_1000c2a4 + _DAT_1000c294;
        dVar1 = (double)fVar2;
        dVar6 = floor((double)fVar2);
        if (dVar6 + _DAT_1000afe0 <= dVar1) {
          ceil(dVar1);
        }
        uVar4 = thunk_FUN_10009bf0();
      }
      param_1 = uVar4;
      uVar4 = DAT_1000c28c + DAT_1000c284;
      if ((param_1 < DAT_1000c28c + DAT_1000c284) &&
         ((DAT_1000c284 != 0 || (uVar4 = param_3, DAT_1000c28c != *DAT_1000d2a4)))) {
        fVar2 = (float)(int)param_3 * _DAT_1000c2a4 + _DAT_1000c294;
        dVar1 = (double)fVar2;
        dVar6 = floor((double)fVar2);
        if (dVar6 + _DAT_1000afe0 <= dVar1) {
          ceil(dVar1);
        }
        uVar4 = thunk_FUN_10009bf0();
      }
      param_3 = uVar4;
      if (param_2 < 1) {
        param_2 = DAT_1000c288;
      }
      else if ((DAT_1000c288 != 0) || (DAT_1000c290 != DAT_1000d2a4[1])) {
        fVar2 = (float)param_2 * _DAT_1000c2a8 + _DAT_1000c298;
        dVar1 = (double)fVar2;
        dVar6 = floor((double)fVar2);
        if (dVar6 + _DAT_1000afe0 <= dVar1) {
          ceil(dVar1);
        }
        param_2 = thunk_FUN_10009bf0();
      }
      uVar4 = DAT_1000c290 + DAT_1000c288;
      if ((param_4 < uVar4) &&
         ((DAT_1000c288 != 0 || (uVar4 = param_4, DAT_1000c290 != DAT_1000d2a4[1])))) {
        fVar2 = (float)(int)param_4 * _DAT_1000c2a8 + _DAT_1000c298;
        dVar1 = (double)fVar2;
        dVar6 = floor((double)fVar2);
        if (dVar6 + _DAT_1000afe0 <= dVar1) {
          ceil(dVar1);
        }
        uVar4 = thunk_FUN_10009bf0();
      }
      (*DAT_1000c12c)(param_1,DAT_1000c280 - uVar4,param_3 - param_1,uVar4 - param_2);
      return 1;
    }
    piVar3 = piVar3 + 1;
    bVar5 = 3 < uVar4;
    uVar4 = uVar4 - 4;
  } while (bVar5);
  return 1;
}



/* VA 10002b90 */

void _THRASH_idle_0(void)

{
                    /* 0x2b90  23  _THRASH_idle@0 */
  return;
}



/* VA 10002ba0 */

undefined4 _THRASH_init_0(void)

{
  char *pcVar1;
  char *pcVar2;
  CHAR local_108 [12];
  char local_fc [248];

                    /* 0x2ba0  24  _THRASH_init@0 */
  if (DAT_1000c2b8 == 0) {
    DAT_1000c2b8 = 1;
    FUN_10002440();
    GetModuleFileNameA(DAT_1002ba64,local_108,0x104);
    pcVar1 = strrchr(local_108,0x5c);
    pcVar1[1] = '\0';
    pcVar1 = &stack0xfffffef7;
    do {
      pcVar2 = pcVar1;
      pcVar1 = pcVar2 + 1;
    } while (pcVar2[1] != '\0');
    *(undefined4 *)(pcVar2 + 1) = s_OPENGL32_DLL_1000a960._0_4_;
    *(undefined4 *)(pcVar2 + 5) = s_OPENGL32_DLL_1000a960._4_4_;
    *(undefined4 *)(pcVar2 + 9) = s_OPENGL32_DLL_1000a960._8_4_;
    pcVar2[0xd] = s_OPENGL32_DLL_1000a960[0xc];
    DAT_1000c0a4 = LoadLibraryA(local_108);
    if (DAT_1000c0a4 == (HMODULE)0x0) {
      DAT_1000c0a4 = LoadLibraryA("OPENGL32.DLL");
      if (DAT_1000c0a4 == (HMODULE)0x0) {
        DAT_1000c0a4 = LoadLibraryA("OPENGL.DLL");
        if (DAT_1000c0a4 == (HMODULE)0x0) {
          return 0;
        }
      }
    }
    DAT_1000c0b0 = GetProcAddress(DAT_1000c0a4,"wglGetProcAddress");
    DAT_1000c028 = GetProcAddress(DAT_1000c0a4,"wglMakeCurrent");
    DAT_1000c03c = GetProcAddress(DAT_1000c0a4,"wglCreateContext");
    DAT_1000c034 = GetProcAddress(DAT_1000c0a4,"wglDeleteContext");
    DAT_1000c110 = GetProcAddress(DAT_1000c0a4,"wglSwapBuffers");
    if (DAT_1002ba78 != (code *)0x0) {
      (*DAT_1002ba78)(0x464,FUN_10004f20);
      (*DAT_1002ba78)(0x465,FUN_10005400);
    }
  }
  return 1;
}



/* VA 10002cf0 */

byte _THRASH_is_0(void)

{
                    /* 0x2cf0  25  _THRASH_is@0 */
  return -(DAT_1000c0a4 != 0) & 0x55;
}



/* VA 10002d00 */

void _THRASH_pageflip_0(void)

{
                    /* 0x2d00  27  _THRASH_pageflip@0 */
  (*DAT_1000c110)(DAT_1002ba68);
  if (DAT_1000c170 != 0) {
                    /* WARNING: Could not recover jumptable at 0x10002d15. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_1000c038)();
    return;
  }
  return;
}



/* VA 10002d20 */

undefined4 _THRASH_restore_0(void)

{
  DWORD DVar1;
  DWORD DVar2;

                    /* 0x2d20  29  _THRASH_restore@0 */
  FUN_10001830();
  if (DAT_1000c0a4 != (HMODULE)0x0) {
    DAT_1000c0b0 = 0;
    DAT_1000c028 = 0;
    DAT_1000c03c = 0;
    DAT_1000c034 = 0;
    FreeLibrary(DAT_1000c0a4);
    DAT_1000c0a4 = (HMODULE)0x0;
  }
  if ((DAT_1002ba78 != 0) && (DAT_1002ba74 != (code *)0x0)) {
    DVar1 = GetWindowThreadProcessId(DAT_1002ba60,(LPDWORD)0x0);
    DVar2 = GetCurrentThreadId();
    if (DVar2 != DVar1) {
      DAT_1002ba60 = (HWND)0x0;
      DAT_1002ba60 = (HWND)(*DAT_1002ba74)();
      DAT_1002ba6c = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
      SetForegroundWindow(DAT_1002ba60);
      PostMessageA(DAT_1002ba60,0x465,0,0);
      WaitForSingleObject(DAT_1002ba6c,10000);
      return 1;
    }
  }
  if ((DAT_1000c158 == 0) && (DAT_1000c204 == 0)) {
    ChangeDisplaySettingsA((DEVMODEA *)0x0,0);
  }
  return 1;
}



/* VA 10002e20 */

undefined4 _THRASH_selectdisplay_4(int param_1)

{
                    /* 0x2e20  30  _THRASH_selectdisplay@4 */
  if (DAT_1000c2f4 != param_1) {
    DAT_1000c2f4 = param_1;
    FUN_10004b20();
  }
  return 1;
}



/* VA 10002e50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _THRASH_setvideomode_12(WPARAM param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  DWORD DVar5;
  DWORD DVar6;
  undefined *puVar7;
  float afStack_a0 [6];
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;

                    /* 0x2e50  33  _THRASH_setvideomode@12 */
  if ((((DAT_1000c2c4 != 0) && (param_1 == DAT_1000d29c)) && (param_2 == DAT_1000d298)) &&
     (param_3 == DAT_1000c2d4)) {
    return 1;
  }
  DAT_1000c2c4 = 1;
  DAT_1000d29c = param_1;
  DAT_1000d298 = param_2;
  DAT_1000c2d4 = param_3;
  FUN_10001830();
  if ((DAT_1002ba74 != (code *)0x0) && (DAT_1002ba60 = (HWND)(*DAT_1002ba74)(), DAT_1002ba78 != 0))
  {
    DVar5 = GetWindowThreadProcessId(DAT_1002ba60,(LPDWORD)0x0);
    DVar6 = GetCurrentThreadId();
    if (DVar6 != DVar5) {
      DAT_1002ba9c = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
      SetForegroundWindow(DAT_1002ba60);
      PostMessageA(DAT_1002ba60,0x464,param_1,param_2);
      WaitForSingleObject(DAT_1002ba9c,10000);
      goto LAB_10002f44;
    }
  }
  FUN_10004f20(0,DAT_1002ba60,0x464,param_1,param_2,(undefined4 *)0x0);
LAB_10002f44:
  FUN_10001390();
  (*DAT_1000c148)(0xc52,0x1100);
  (*DAT_1000c148)(0xc53,0x1100);
  DAT_1000c278 = 0;
  (*DAT_1000c118)(DAT_1000c284,DAT_1000c288,DAT_1000c28c,DAT_1000c290);
  afStack_a0[5] = (float)(int)DAT_1000d2a4[1];
  if ((int)DAT_1000d2a4[1] < 0) {
    afStack_a0[5] = afStack_a0[5] + _DAT_1000b000;
  }
  afStack_a0[0] = (float)(int)*DAT_1000d2a4;
  if ((int)*DAT_1000d2a4 < 0) {
    afStack_a0[0] = afStack_a0[0] + _DAT_1000b000;
  }
  afStack_a0[0] = (float)_DAT_1000afe8 / afStack_a0[0];
  afStack_a0[1] = 0.0;
  afStack_a0[2] = 0.0;
  afStack_a0[3] = 0.0;
  afStack_a0[4] = 0.0;
  uStack_88 = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  uStack_78 = 0x40000000;
  uStack_74 = 0;
  uStack_70 = 0xbf800000;
  uStack_6c = 0x3f800000;
  uStack_68 = 0xbf800000;
  uStack_64 = 0x3f800000;
  afStack_a0[5] = (float)_DAT_1000b008 / afStack_a0[5];
  (*DAT_1000c0b4)(DAT_1000c1bc,1,0,afStack_a0);
  (*DAT_1000c114)(0,0x3ff0000000000000);
  (*DAT_1000c05c)(0xc11);
  if (0 < DAT_1000c0d0) {
    _THRASH_window_4((undefined *)0x0);
    (*DAT_1000c0e0)(0x4500);
  }
  if (DAT_1000c278 != 0) {
    DAT_1000c278 = 0;
    (*DAT_1000c118)(DAT_1000c284,DAT_1000c288,DAT_1000c28c,DAT_1000c290);
    uVar4 = DAT_1000c2ec;
    uVar3 = DAT_1000c2e8;
    iVar2 = DAT_1000c2e4;
    uVar1 = DAT_1000c2e0;
    DAT_1000c2e0 = 0;
    DAT_1000c2e4 = 0;
    DAT_1000c2e8 = 0;
    DAT_1000c2ec = 0;
    _THRASH_clip_16(uVar1,iVar2,uVar3,uVar4);
  }
  FUN_10005450(0x3b,0,(undefined *)0x1);
  DAT_1000c2bc = 1;
  (*DAT_1000c040)(0x404);
  (*DAT_1000c08c)(0x404);
  (*DAT_1000c0e0)(0x4500);
  if (DAT_1000c278 != 0) {
    DAT_1000c278 = 0;
    (*DAT_1000c118)(DAT_1000c284,DAT_1000c288,DAT_1000c28c,DAT_1000c290);
    uVar4 = DAT_1000c2ec;
    uVar3 = DAT_1000c2e8;
    iVar2 = DAT_1000c2e4;
    uVar1 = DAT_1000c2e0;
    DAT_1000c2e0 = 0;
    DAT_1000c2e4 = 0;
    DAT_1000c2e8 = 0;
    DAT_1000c2ec = 0;
    _THRASH_clip_16(uVar1,iVar2,uVar3,uVar4);
  }
  FUN_10005450(0x3b,0,(undefined *)0x2);
  DAT_1000c2bc = 1;
  (*DAT_1000c040)(0x405);
  (*DAT_1000c08c)(0x405);
  (*DAT_1000c0e0)(0x4500);
  (*DAT_1000c080)(0xc11);
  DAT_1000c2e0 = 0;
  DAT_1000c2e4 = 0;
  DAT_1000c2e8 = 0;
  DAT_1000c2ec = 0;
  _THRASH_clip_16(0,0,*DAT_1000d2a4,DAT_1000d2a4[1]);
  (*DAT_1000c128)(0x84c0);
  puVar7 = (undefined *)FUN_10009740(&DAT_1000a9d8);
  FUN_10005450(0x130,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740(&DAT_1000a9e0);
  FUN_10005450(2,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("FILTER");
  FUN_10005450(7,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("SHADE");
  FUN_10005450(6,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("TRANSPARENCY");
  FUN_10005450(10,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("ALPHATEST");
  FUN_10005450(0x24,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("MIPMAP");
  FUN_10005450(0xb,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("BACKGROUNDCOLOUR");
  FUN_10005450(3,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("CHROMACOLOUR");
  FUN_10005450(0xc,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("DITHER");
  FUN_10005450(5,0xffff0000,puVar7);
  FUN_10005450(0x14,0xffff0000,(undefined *)0x0);
  puVar7 = (undefined *)FUN_10009740("FOGMODE");
  FUN_10005450(0x15,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("FOGDENSITY");
  FUN_10005450(0xe,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("STATE_FOGZNEAR");
  FUN_10005450(0x16,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("FOGZFAR");
  FUN_10005450(0x17,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("FOGCOLOUR");
  FUN_10005450(0xf,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("ALPHA");
  FUN_10005450(0x38,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("TEXTURECLAMP");
  FUN_10005450(0xd,0xffff0000,puVar7);
  FUN_10005450(0x2e,0xffff0000,(undefined *)0x3f800000);
  puVar7 = (undefined *)FUN_10009740("DEPTHBIAS");
  FUN_10005450(0x18,0xffff0000,puVar7);
  FUN_10005450(8,0xffff0000,(undefined *)0x0);
  puVar7 = (undefined *)FUN_10009740("MAXPENDING");
  FUN_10005450(0x6d,0xffff0000,puVar7);
  FUN_10005450(0x2a,0xffff0000,(undefined *)0x0);
  FUN_10005450(0x29,0xffff0000,(undefined *)0x0);
  FUN_10005450(0x29,0xffff0001,(undefined *)0x2);
  puVar7 = (undefined *)FUN_10009740("BACKBUFFERTYPE");
  FUN_10005450(0x2b,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("FLATFANS");
  FUN_10005450(0x11,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("LINEWIDTH");
  FUN_10005450(0x10,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("STENCILBUFFER");
  FUN_10005450(0x2f,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("DISPLAYMODE");
  FUN_10005450(0x3a,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("LINEDOUBLE");
  FUN_10005450(0x131,0xffff0000,puVar7);
  FUN_10005450(0x3b,0xffff0000,(undefined *)0x0);
  FUN_10005450(0x43,0xffff0000,(undefined *)0x3f800000);
  puVar7 = (undefined *)FUN_10009740("FLIPRATE");
  FUN_10005450(0x3c,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("SHAMELESSPLUG");
  FUN_10005450(0x3d,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("DEPTHBUFFER");
  FUN_10005450(4,0xffff0000,puVar7);
  puVar7 = (undefined *)FUN_10009740("DEPTHCMP");
  FUN_10005450(0x28,0xffff0000,puVar7);
  return 1;
}



/* VA 10003710 */

undefined4 _THRASH_sync_4(void)

{
                    /* 0x3710  34  _THRASH_sync@4 */
  return 1;
}



/* VA 10003720 */

void __fastcall FUN_10003720(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;

  iVar1 = param_2 + -1;
  uVar7 = param_1 * param_4;
  if ((uVar7 & 3) == 0) {
    uVar7 = uVar7 >> 2;
    puVar6 = param_3 + iVar1 * uVar7;
    uVar5 = uVar7;
    if (param_3 < puVar6) {
      do {
        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
          uVar4 = *param_3;
          *param_3 = *puVar6;
          param_3 = param_3 + 1;
          *puVar6 = uVar4;
          puVar6 = puVar6 + 1;
        }
        puVar6 = puVar6 + uVar7 * -2;
        uVar5 = uVar7;
      } while (param_3 < puVar6);
      return;
    }
  }
  else if ((uVar7 & 1) == 0) {
    uVar7 = uVar7 >> 1;
    puVar6 = (undefined4 *)((int)param_3 + iVar1 * uVar7 * 2);
    uVar5 = uVar7;
    if (param_3 < puVar6) {
      do {
        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
          uVar3 = *(undefined2 *)param_3;
          *(undefined2 *)param_3 = *(undefined2 *)puVar6;
          param_3 = (undefined4 *)((int)param_3 + 2);
          *(undefined2 *)puVar6 = uVar3;
          puVar6 = (undefined4 *)((int)puVar6 + 2);
        }
        puVar6 = puVar6 + -uVar7;
        uVar5 = uVar7;
      } while (param_3 < puVar6);
      return;
    }
  }
  else {
    puVar6 = (undefined4 *)(iVar1 * uVar7 + (int)param_3);
    uVar5 = uVar7;
    if (param_3 < puVar6) {
      do {
        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
          uVar2 = *(undefined1 *)param_3;
          *(undefined1 *)param_3 = *(undefined1 *)puVar6;
          param_3 = (undefined4 *)((int)param_3 + 1);
          *(undefined1 *)puVar6 = uVar2;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
        puVar6 = (undefined4 *)((int)puVar6 + uVar7 * -2);
        uVar5 = uVar7;
      } while (param_3 < puVar6);
    }
  }
  return;
}



/* VA 10003800 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
_THRASH_readrect_20(int param_1,int param_2,uint param_3,uint param_4,undefined4 *param_5)

{
  double dVar1;
  float fVar2;
  int iVar3;
  void *_Memory;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int unaff_EBX;
  uint uVar7;
  uint uVar8;
  void *unaff_EDI;
  undefined4 uVar9;
  undefined4 *puVar10;
  double dVar11;
  int iStack_74;
  int local_64;
  double local_48;

                    /* 0x3800  28  _THRASH_readrect@20 */
  if (DAT_1000c184 == 0) {
    uVar7 = (uint)DAT_1000d2a4[2] >> 3;
    if (uVar7 == 3) {
      uVar9 = 0x80e0;
      uVar5 = 0x1401;
      goto LAB_1000385c;
    }
    if (uVar7 == 4) {
      uVar9 = 0x80e1;
      uVar5 = 0x1401;
      goto LAB_1000385c;
    }
  }
  else {
    uVar7 = 2;
  }
  uVar5 = 0x8363;
  uVar9 = 0x1907;
LAB_1000385c:
  if ((DAT_1000c27c == *DAT_1000d2a4) && (DAT_1000c280 == DAT_1000d2a4[1])) {
    (*DAT_1000c0e4)(param_1,(DAT_1000c280 - param_2) - param_4,param_3,param_4,uVar9,uVar5,param_5);
  }
  else {
    fVar2 = (float)(int)param_3;
    if ((int)param_3 < 0) {
      fVar2 = fVar2 + _DAT_1000b000;
    }
    dVar1 = (double)(fVar2 * _DAT_1000c2a4);
    dVar11 = floor((double)(fVar2 * _DAT_1000c2a4));
    if (dVar11 + _DAT_1000afe0 <= dVar1) {
      dVar11 = ceil(dVar1);
    }
    local_48._0_4_ = (int)(longlong)ROUND(dVar11);
    iVar4 = local_48._0_4_;
    fVar2 = (float)(int)param_4;
    if ((int)param_4 < 0) {
      fVar2 = fVar2 + _DAT_1000b000;
    }
    dVar1 = (double)(fVar2 * _DAT_1000c2a8);
    dVar11 = floor((double)(fVar2 * _DAT_1000c2a8));
    if (dVar11 + _DAT_1000afe0 <= dVar1) {
      dVar11 = ceil(dVar1);
    }
    local_48._0_4_ = (int)(longlong)ROUND(dVar11);
    iVar3 = local_48._0_4_;
    if (DAT_1002ba90 == (code *)0x0) {
      _Memory = malloc(local_48._0_4_ * iVar4 * uVar7);
    }
    else {
      _Memory = (void *)(*DAT_1002ba90)();
    }
    fVar2 = (float)(int)(param_2 + param_4);
    if ((int)(param_2 + param_4) < 0) {
      fVar2 = fVar2 + _DAT_1000b000;
    }
    dVar1 = (double)(fVar2 * _DAT_1000c2a8);
    local_48 = floor((double)(fVar2 * _DAT_1000c2a8));
    if (local_48 + _DAT_1000afe0 <= dVar1) {
      local_48 = ceil(dVar1);
    }
    fVar2 = (float)param_1;
    if (param_1 < 0) {
      fVar2 = fVar2 + _DAT_1000b000;
    }
    dVar1 = (double)(fVar2 * _DAT_1000c2a4);
    dVar11 = floor((double)(fVar2 * _DAT_1000c2a4));
    if (dVar11 + _DAT_1000afe0 <= dVar1) {
      dVar11 = ceil(dVar1);
    }
    local_48._0_4_ = (int)(longlong)ROUND(local_48);
    iVar6 = DAT_1000c280 - local_48._0_4_;
    local_48._0_4_ = (int)(longlong)ROUND(dVar11);
    (*DAT_1000c0e4)(local_48._0_4_ + DAT_1000c284,iVar6 - DAT_1000c288,iVar4,iVar3,uVar9,uVar5,
                    _Memory);
    uVar7 = 0;
    if (iStack_74 == 4) {
      puVar10 = param_5;
      if (param_4 != 0) {
        do {
          fVar2 = (float)(int)uVar7;
          if ((int)uVar7 < 0) {
            fVar2 = fVar2 + _DAT_1000b000;
          }
          dVar1 = (double)(fVar2 * _DAT_1000c2a8);
          dVar11 = floor((double)(fVar2 * _DAT_1000c2a8));
          if (dVar11 + _DAT_1000afe0 <= dVar1) {
            dVar11 = ceil(dVar1);
          }
          uVar8 = 0;
          local_64 = (int)(longlong)ROUND(dVar11);
          iVar4 = local_64 * unaff_EBX;
          if (param_3 != 0) {
            do {
              fVar2 = (float)(int)uVar8;
              if ((int)uVar8 < 0) {
                fVar2 = fVar2 + _DAT_1000b000;
              }
              dVar1 = (double)(fVar2 * _DAT_1000c2a4);
              dVar11 = floor((double)(fVar2 * _DAT_1000c2a4));
              if (dVar11 + _DAT_1000afe0 <= dVar1) {
                dVar11 = ceil(dVar1);
              }
              uVar8 = uVar8 + 1;
              local_64 = (int)(longlong)ROUND(dVar11);
              *puVar10 = *(undefined4 *)((int)unaff_EDI + (local_64 + iVar4) * 4);
              puVar10 = puVar10 + 1;
            } while (uVar8 < param_3);
          }
          uVar7 = uVar7 + 1;
          _Memory = unaff_EDI;
        } while (uVar7 < param_4);
      }
    }
    else {
      puVar10 = param_5;
      if (param_4 != 0) {
        do {
          fVar2 = (float)(int)uVar7;
          if ((int)uVar7 < 0) {
            fVar2 = fVar2 + _DAT_1000b000;
          }
          dVar1 = (double)(fVar2 * _DAT_1000c2a8);
          dVar11 = floor((double)(fVar2 * _DAT_1000c2a8));
          if (dVar11 + _DAT_1000afe0 <= dVar1) {
            dVar11 = ceil(dVar1);
          }
          uVar8 = 0;
          local_64 = (int)(longlong)ROUND(dVar11);
          iVar4 = local_64 * unaff_EBX;
          if (param_3 != 0) {
            do {
              fVar2 = (float)(int)uVar8;
              if ((int)uVar8 < 0) {
                fVar2 = fVar2 + _DAT_1000b000;
              }
              dVar1 = (double)(fVar2 * _DAT_1000c2a4);
              dVar11 = floor((double)(fVar2 * _DAT_1000c2a4));
              if (dVar11 + _DAT_1000afe0 <= dVar1) {
                dVar11 = ceil(dVar1);
              }
              uVar8 = uVar8 + 1;
              local_64 = (int)(longlong)ROUND(dVar11);
              *(undefined2 *)puVar10 = *(undefined2 *)((int)unaff_EDI + (local_64 + iVar4) * 2);
              puVar10 = (undefined4 *)((int)puVar10 + 2);
            } while (uVar8 < param_3);
          }
          uVar7 = uVar7 + 1;
          _Memory = unaff_EDI;
        } while (uVar7 < param_4);
      }
    }
    if (DAT_1002ba94 == (code *)0x0) {
      free(_Memory);
    }
    else {
      (*DAT_1002ba94)();
    }
  }
  FUN_10003720(param_3,param_4,param_5,iStack_74);
  return 1;
}



/* VA 10003dc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _THRASH_writerect_20(int param_1,int param_2,uint param_3,uint param_4,int param_5)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  size_t _Size;
  ushort *_Dst;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  float *pfVar8;
  void *_Src;
  float *pfVar9;
  ushort *_Dst_00;
  bool bVar10;
  uint uStack_26c;
  uint local_264;
  uint uStack_260;
  uint uStack_258;
  int local_254;
  undefined *puStack_24c;
  undefined *puStack_248;
  undefined *puStack_244;
  undefined *puStack_240;
  undefined *puStack_23c;
  undefined *puStack_238;
  undefined *puStack_234;
  undefined *puStack_230;
  float afStack_218 [6];
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  float afStack_1f8 [6];
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  float afStack_1d8 [6];
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  float afStack_1b8 [6];
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  char acStack_198 [404];

                    /* 0x3dc0  41  _THRASH_writerect@20 */
  if (DAT_1000c184 == 0) {
    local_264 = *(uint *)(DAT_1000d2a4 + 8) >> 3;
    local_254 = local_264 * param_3;
    if (local_264 == 3) {
      iVar2 = 5;
      goto LAB_10003e2b;
    }
    if (local_264 == 4) {
      iVar2 = 6;
      goto LAB_10003e2b;
    }
  }
  else {
    local_264 = 2;
    local_254 = param_3 * 2;
  }
  iVar2 = 4;
LAB_10003e2b:
  puVar3 = _THRASH_talloc_20(DAT_1002bbb4,DAT_1002bbc0,iVar2,0,0);
  if (puVar3 != (undefined4 *)0x0) {
    iVar2 = local_264 * DAT_1002bbb4;
    _Size = iVar2 * DAT_1002bbc0;
    if (DAT_1002ba90 == (code *)0x0) {
      _Dst = malloc(_Size);
    }
    else {
      _Dst = (ushort *)(*DAT_1002ba90)();
    }
    if (_Dst != (ushort *)0x0) {
      puStack_24c = (undefined *)FUN_10009a20(1);
      if (-1 < (int)puStack_24c) {
        puStack_24c = *(undefined **)(&DAT_1002bc40 + (int)puStack_24c * 4);
      }
      puStack_248 = (undefined *)FUN_10009a20(6);
      if (-1 < (int)puStack_248) {
        puStack_248 = *(undefined **)(&DAT_1002bc40 + (int)puStack_248 * 4);
      }
      puStack_244 = (undefined *)FUN_10009a20(0x2a);
      if (-1 < (int)puStack_244) {
        puStack_244 = *(undefined **)(&DAT_1002bc40 + (int)puStack_244 * 4);
      }
      puStack_240 = (undefined *)FUN_10009a20(2);
      if (-1 < (int)puStack_240) {
        puStack_240 = *(undefined **)(&DAT_1002bc40 + (int)puStack_240 * 4);
      }
      puStack_23c = (undefined *)FUN_10009a20(0xd);
      if (-1 < (int)puStack_23c) {
        puStack_23c = *(undefined **)(&DAT_1002bc40 + (int)puStack_23c * 4);
      }
      puStack_238 = (undefined *)FUN_10009a20(0xb);
      if (-1 < (int)puStack_238) {
        puStack_238 = *(undefined **)(&DAT_1002bc40 + (int)puStack_238 * 4);
      }
      puStack_234 = (undefined *)FUN_10009a20(10);
      if (-1 < (int)puStack_234) {
        puStack_234 = *(undefined **)(&DAT_1002bc40 + (int)puStack_234 * 4);
      }
      puStack_230 = (undefined *)FUN_10009a20(4);
      if (-1 < (int)puStack_230) {
        puStack_230 = *(undefined **)(&DAT_1002bc40 + (int)puStack_230 * 4);
      }
      FUN_10005450(1,0,(undefined *)puVar3);
      FUN_10005450(6,0,(undefined *)0x0);
      FUN_10005450(0x2a,0,(undefined *)0x0);
      FUN_10005450(2,0,(undefined *)0x0);
      FUN_10005450(0xd,0,(undefined *)0x0);
      FUN_10005450(0xb,0,(undefined *)0x0);
      FUN_10005450(10,0,(undefined *)0x0);
      FUN_10005450(4,0,(undefined *)0x0);
      afStack_218[4] = -NAN;
      afStack_218[2] = 0.0;
      afStack_218[3] = 1.0;
      uStack_200 = 0;
      uStack_1fc = 0;
      pfVar8 = afStack_218;
      pfVar9 = afStack_1d8;
      for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
        *pfVar9 = *pfVar8;
        pfVar8 = pfVar8 + 1;
        pfVar9 = pfVar9 + 1;
      }
      uStack_1c0 = 0x3f800000;
      uStack_1bc = 0;
      pfVar8 = afStack_218;
      pfVar9 = afStack_1f8;
      for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
        *pfVar9 = *pfVar8;
        pfVar8 = pfVar8 + 1;
        pfVar9 = pfVar9 + 1;
      }
      uStack_1e0 = 0x3f800000;
      uStack_1dc = 0x3f800000;
      pfVar8 = afStack_218;
      pfVar9 = afStack_1b8;
      for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
        *pfVar9 = *pfVar8;
        pfVar8 = pfVar8 + 1;
        pfVar9 = pfVar9 + 1;
      }
      uStack_1a0 = 0;
      uStack_19c = 0x3f800000;
      uStack_258 = 0;
      uVar7 = DAT_1002bbc0;
      if (param_4 != 0) {
        do {
          uVar5 = param_4 - uStack_258;
          if (uVar7 < param_4 - uStack_258) {
            uVar5 = uVar7;
          }
          uStack_26c = 0;
          if (param_3 != 0) {
            iVar4 = uStack_258 + param_2;
            fVar1 = (float)iVar4;
            if (iVar4 < 0) {
              fVar1 = fVar1 + _DAT_1000b000;
            }
            do {
              uVar7 = param_3 - uStack_26c;
              bVar10 = uVar7 == DAT_1002bbb4;
              if (DAT_1002bbb4 < uVar7) {
                bVar10 = uVar5 == DAT_1002bbc0;
                uVar7 = DAT_1002bbb4;
              }
              if (!bVar10) {
                memset(_Dst,0,_Size);
              }
              _Src = (void *)(uStack_26c * local_264 + uStack_258 * local_254 + param_5);
              if (uVar5 != 0) {
                _Dst_00 = _Dst;
                uStack_260 = uVar5;
                do {
                  memcpy(_Dst_00,_Src,uVar7 * local_264);
                  _Src = (void *)((int)_Src + local_254);
                  _Dst_00 = (ushort *)((int)_Dst_00 + iVar2);
                  uStack_260 = uStack_260 - 1;
                } while (uStack_260 != 0);
              }
              _THRASH_tupdate_12(puVar3,_Dst,(undefined4 *)0x0);
              iVar6 = param_1 + uStack_26c;
              afStack_218[0] = (float)iVar6;
              if (iVar6 < 0) {
                afStack_218[0] = afStack_218[0] + _DAT_1000b000;
              }
              afStack_1f8[0] = (float)(int)(DAT_1002bbb4 + iVar6);
              if ((int)(DAT_1002bbb4 + iVar6) < 0) {
                afStack_1f8[0] = afStack_1f8[0] + _DAT_1000b000;
              }
              afStack_1f8[1] = (float)(int)(DAT_1002bbc0 + iVar4);
              if ((int)(DAT_1002bbc0 + iVar4) < 0) {
                afStack_1f8[1] = afStack_1f8[1] + _DAT_1000b000;
              }
              afStack_218[1] = fVar1;
              afStack_1d8[0] = afStack_1f8[0];
              afStack_1d8[1] = fVar1;
              afStack_1b8[0] = afStack_218[0];
              afStack_1b8[1] = afStack_1f8[1];
              FUN_10008cb0(afStack_218,afStack_1d8,afStack_1f8);
              FUN_10008cb0(afStack_1f8,afStack_1b8,afStack_218);
              uStack_26c = uStack_26c + DAT_1002bbb4;
              uVar7 = DAT_1002bbc0;
            } while (uStack_26c < param_3);
          }
          uStack_258 = uStack_258 + uVar7;
        } while (uStack_258 < param_4);
      }
      FUN_10008a60();
      (*DAT_1000c068)();
      FUN_10005450(1,0,puStack_24c);
      FUN_10005450(6,0,puStack_248);
      FUN_10005450(0x2a,0,puStack_244);
      FUN_10005450(2,0,puStack_240);
      FUN_10005450(0xd,0,puStack_23c);
      FUN_10005450(0xb,0,puStack_238);
      FUN_10005450(10,0,puStack_234);
      FUN_10005450(4,0,puStack_230);
      if (DAT_1002ba94 == (code *)0x0) {
        free(_Dst);
        _THRASH_tfree_4((int)puVar3);
        return 1;
      }
      (*DAT_1002ba94)();
      _THRASH_tfree_4((int)puStack_230);
      return 1;
    }
    _THRASH_tfree_4((int)puVar3);
    if (DAT_1002ba88 != (code *)0x0) {
      sprintf(acStack_198,"%s:\n%s\n\n\nFILE %s\nLINE %d","Write","Out of memory.",
              "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Rect.cpp",0x131);
      (*DAT_1002ba88)(0,acStack_198);
    }
  }
  return 1;
}



/* VA 100043c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_100043c0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  undefined4 local_34;
  undefined4 local_2c;
  undefined4 local_24;

  DAT_1000c278 = 1;
  DAT_1000c288 = 0;
  DAT_1000c284 = 0;
  _DAT_1000c298 = 0.0;
  _DAT_1000c294 = 0.0;
  DAT_1000c27c = param_1;
  DAT_1000c28c = param_1;
  DAT_1000c280 = param_2;
  DAT_1000c290 = param_2;
  fVar1 = (float)param_1;
  if (param_1 < 0) {
    fVar1 = fVar1 + _DAT_1000b000;
  }
  fVar2 = (float)*DAT_1000d2a4;
  if (*DAT_1000d2a4 < 0) {
    fVar2 = fVar2 + _DAT_1000b000;
  }
  DAT_1000c29c = fVar1 / fVar2;
  _DAT_1000c2a4 = DAT_1000c29c;
  fVar2 = (float)param_2;
  if (param_2 < 0) {
    fVar2 = fVar2 + _DAT_1000b000;
  }
  fVar3 = (float)DAT_1000d2a4[1];
  if (DAT_1000d2a4[1] < 0) {
    fVar3 = fVar3 + _DAT_1000b000;
  }
  DAT_1000c2a0 = fVar2 / fVar3;
  _DAT_1000c2a8 = DAT_1000c2a0;
  if ((DAT_1000c174 != 0) && (DAT_1000c29c != DAT_1000c2a0)) {
    if (DAT_1000c29c <= DAT_1000c2a0) {
      fVar1 = (float)DAT_1000d2a4[1];
      if (DAT_1000d2a4[1] < 0) {
        fVar1 = fVar1 + _DAT_1000b000;
      }
      fVar1 = DAT_1000c29c * fVar1;
      dVar4 = floor((double)fVar1);
      if (dVar4 + _DAT_1000afe0 <= (double)fVar1) {
        dVar4 = ceil((double)fVar1);
      }
      local_2c = (undefined4)(longlong)ROUND(dVar4);
      DAT_1000c290 = local_2c;
      _DAT_1000c298 = (fVar2 - fVar1) * (float)_DAT_1000afe0;
      dVar4 = (double)_DAT_1000c298;
      dVar5 = floor((double)_DAT_1000c298);
      if (dVar5 + _DAT_1000afe0 <= dVar4) {
        dVar5 = ceil(dVar4);
      }
      _DAT_1000c2a8 = DAT_1000c29c;
      local_34 = (undefined4)(longlong)ROUND(dVar5);
      DAT_1000c288 = local_34;
      return;
    }
    fVar2 = (float)*DAT_1000d2a4;
    if (*DAT_1000d2a4 < 0) {
      fVar2 = fVar2 + _DAT_1000b000;
    }
    fVar2 = DAT_1000c2a0 * fVar2;
    dVar4 = floor((double)fVar2);
    if (dVar4 + _DAT_1000afe0 <= (double)fVar2) {
      dVar4 = ceil((double)fVar2);
    }
    local_24 = (undefined4)(longlong)ROUND(dVar4);
    DAT_1000c28c = local_24;
    _DAT_1000c294 = (fVar1 - fVar2) * (float)_DAT_1000afe0;
    dVar4 = (double)_DAT_1000c294;
    dVar5 = floor((double)_DAT_1000c294);
    if (dVar5 + _DAT_1000afe0 <= dVar4) {
      dVar5 = ceil(dVar4);
    }
    _DAT_1000c2a4 = DAT_1000c2a0;
    local_2c = (undefined4)(longlong)ROUND(dVar5);
    DAT_1000c284 = local_2c;
    return;
  }
  return;
}



/* VA 100046f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100046f0(HWND param_1,uint param_2,WPARAM param_3,uint param_4)

{
  double dVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  double dVar6;

  if (param_2 < 0x1d) {
    if (param_2 == 0x1c) {
switchD_10004712_caseD_6:
      DefWindowProcA(param_1,param_2,param_3,param_4);
      return;
    }
    switch(param_2) {
    case 5:
      FUN_100043c0(param_4 & 0xffff,(int)param_4 >> 0x10);
      goto LAB_100048cf;
    case 6:
    case 7:
    case 8:
      goto switchD_10004712_caseD_6;
    }
  }
  else if (param_2 < 0x113) {
    if (param_2 == 0x112) {
      DefWindowProcA(param_1,0x112,param_3,param_4);
      return;
    }
    if (param_2 == 0x86) goto switchD_10004712_caseD_6;
  }
  else {
    switch(param_2) {
    case 0x200:
    case 0x201:
    case 0x202:
    case 0x203:
    case 0x204:
    case 0x205:
    case 0x206:
    case 0x207:
    case 0x208:
    case 0x209:
    case 0x20b:
    case 0x20c:
    case 0x20d:
      iVar3 = (int)(short)param_4;
      iVar5 = (int)(short)(param_4 >> 0x10);
      if (iVar3 < DAT_1000c284) {
        uVar4 = 0;
      }
      else if (iVar3 < DAT_1000c28c + DAT_1000c284) {
        fVar2 = (float)(iVar3 - DAT_1000c284);
        if (iVar3 - DAT_1000c284 < 0) {
          fVar2 = fVar2 + _DAT_1000b000;
        }
        dVar1 = (double)(fVar2 / _DAT_1000c2a4);
        dVar6 = floor((double)(fVar2 / _DAT_1000c2a4));
        if (dVar6 + _DAT_1000afe0 <= dVar1) {
          ceil(dVar1);
        }
        uVar4 = thunk_FUN_10009bf0();
      }
      else {
        uVar4 = *DAT_1000d2a4 - 1;
      }
      if (iVar5 < DAT_1000c288) {
        param_4 = uVar4 & 0xffff;
      }
      else if (iVar5 < DAT_1000c290 + DAT_1000c288) {
        fVar2 = (float)(iVar5 - DAT_1000c288);
        if (iVar5 - DAT_1000c288 < 0) {
          fVar2 = fVar2 + _DAT_1000b000;
        }
        dVar1 = (double)(fVar2 / _DAT_1000c2a8);
        dVar6 = floor((double)(fVar2 / _DAT_1000c2a8));
        if (dVar6 + _DAT_1000afe0 <= dVar1) {
          ceil(dVar1);
        }
        iVar3 = thunk_FUN_10009bf0();
        param_4 = iVar3 << 0x10 | uVar4 & 0xffff;
      }
      else {
        param_4 = (DAT_1000d2a4[1] + -1) * 0x10000 | uVar4 & 0xffff;
      }
      goto LAB_100048cf;
    }
  }
LAB_100048cf:
  CallWindowProcA(DAT_1002c6d0,param_1,param_2,param_3,param_4);
  return;
}



/* VA 10004920 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10004920(HWND param_1,uint param_2,WPARAM param_3,uint param_4)

{
  double dVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  double dVar6;

  if (param_2 < 0x201) {
    if (param_2 == 0x200) {
switchD_1000496d_caseD_201:
      iVar3 = (int)(short)param_4;
      iVar5 = (int)(short)(param_4 >> 0x10);
      if (iVar3 < DAT_1000c284) {
        uVar4 = 0;
      }
      else if (iVar3 < DAT_1000c28c + DAT_1000c284) {
        fVar2 = (float)(iVar3 - DAT_1000c284);
        if (iVar3 - DAT_1000c284 < 0) {
          fVar2 = fVar2 + _DAT_1000b000;
        }
        dVar1 = (double)(fVar2 / _DAT_1000c2a4);
        dVar6 = floor((double)(fVar2 / _DAT_1000c2a4));
        if (dVar6 + _DAT_1000afe0 <= dVar1) {
          ceil(dVar1);
        }
        uVar4 = thunk_FUN_10009bf0();
      }
      else {
        uVar4 = *DAT_1000d2a4 - 1;
      }
      if (iVar5 < DAT_1000c288) {
        param_4 = uVar4 & 0xffff;
      }
      else if (iVar5 < DAT_1000c290 + DAT_1000c288) {
        fVar2 = (float)(iVar5 - DAT_1000c288);
        if (iVar5 - DAT_1000c288 < 0) {
          fVar2 = fVar2 + _DAT_1000b000;
        }
        dVar1 = (double)(fVar2 / _DAT_1000c2a8);
        dVar6 = floor((double)(fVar2 / _DAT_1000c2a8));
        if (dVar6 + _DAT_1000afe0 <= dVar1) {
          ceil(dVar1);
        }
        iVar3 = thunk_FUN_10009bf0();
        param_4 = iVar3 << 0x10 | uVar4 & 0xffff;
      }
      else {
        param_4 = (DAT_1000d2a4[1] + -1) * 0x10000 | uVar4 & 0xffff;
      }
      goto LAB_10004aac;
    }
    if (param_2 == 5) {
      FUN_100043c0(param_4 & 0xffff,(int)param_4 >> 0x10);
      goto LAB_10004aac;
    }
  }
  else {
    switch(param_2) {
    case 0x201:
    case 0x202:
    case 0x203:
    case 0x204:
    case 0x205:
    case 0x206:
    case 0x207:
    case 0x208:
    case 0x209:
    case 0x20b:
    case 0x20c:
    case 0x20d:
      goto switchD_1000496d_caseD_201;
    }
  }
LAB_10004aac:
  CallWindowProcA(DAT_1002c6d0,param_1,param_2,param_3,param_4);
  return;
}



/* VA 10004af0 */

undefined4 FUN_10004af0(HINSTANCE param_1,undefined4 param_2,LPCSTR param_3,HWND param_4)

{
  HICON dwNewLong;

  dwNewLong = LoadIconA(param_1,param_3);
  if (dwNewLong != (HICON)0x0) {
    SetClassLongA(param_4,-0xe,(LONG)dwNewLong);
    return 0;
  }
  return 1;
}



/* VA 10004b20 */

undefined4 FUN_10004b20(void)

{
  BOOL BVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  CHAR *lpszDeviceName;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 *puVar8;
  uint *puVar9;
  DEVMODEA *pDVar10;
  char cVar11;
  DWORD local_324;
  DWORD local_31c;
  DEVMODEA local_318;
  undefined4 local_274 [39];
  uint local_1d8 [10];
  _DISPLAY_DEVICEA local_1b0;

  memset(&DAT_1000c2f8,0,4000);
  DAT_1000d2a0 = 0;
  if (DAT_1000c180 != 0) {
    DAT_1000c320 = 0x280;
    DAT_1000c324 = 0x1e0;
    DAT_1000c328 = 0x10;
    DAT_1000c32c = 4;
    DAT_1000c330 = 1;
    DAT_1000c334 = 3;
    DAT_1000c338 = 3;
  }
  memset(local_1b0.DeviceName,0,0x1a4);
  local_1b0.cb = 0x1a8;
  BVar1 = EnumDisplayDevicesA((LPCSTR)0x0,DAT_1000c2f4,&local_1b0,0);
  lpszDeviceName = local_1b0.DeviceName;
  if (BVar1 == 0) {
    lpszDeviceName = (CHAR *)0x0;
  }
  memset(&local_318,0,0x9c);
  local_318.dmSize = 0x9c;
  EnumDisplaySettingsA(lpszDeviceName,0xfffffffe,&local_318);
  DAT_1000d2a8 = local_318.dmPelsWidth;
  DAT_1000d2ac = local_318.dmPelsHeight;
  if ((DAT_1000c158 == 0) && (DAT_1000c204 == 0)) {
    uVar5 = 0;
    memset(local_274,0,0x9c);
    local_324 = 0;
    puVar8 = local_274;
    pDVar10 = &local_318;
    for (iVar3 = 0x27; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined4 *)pDVar10->dmDeviceName = *puVar8;
      puVar8 = puVar8 + 1;
      pDVar10 = (DEVMODEA *)(pDVar10->dmDeviceName + 4);
    }
    local_318.dmSize = 0x9c;
    iVar3 = EnumDisplaySettingsA(lpszDeviceName,0,&local_318);
    while (uVar6 = uVar5, iVar3 != 0) {
      if ((0x27f < local_318.dmPelsWidth) && (0x1df < local_318.dmPelsHeight)) {
        uVar6 = DAT_1000c160;
        if (local_318.dmBitsPerPel == DAT_1000c160) break;
        if (uVar5 < local_318.dmBitsPerPel) {
          uVar5 = local_318.dmBitsPerPel;
        }
      }
      memset(local_274,0,0x9c);
      puVar8 = local_274;
      pDVar10 = &local_318;
      for (iVar3 = 0x27; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined4 *)pDVar10->dmDeviceName = *puVar8;
        puVar8 = puVar8 + 1;
        pDVar10 = (DEVMODEA *)(pDVar10->dmDeviceName + 4);
      }
      local_318.dmSize = 0x9c;
      local_324 = local_324 + 1;
      iVar3 = EnumDisplaySettingsA(lpszDeviceName,local_324,&local_318);
    }
  }
  else {
    DAT_1000c160 = local_318.dmBitsPerPel;
    uVar6 = DAT_1000c160;
  }
  DAT_1000c160 = uVar6;
  local_324 = 0;
  memset(local_274,0,0x9c);
  local_31c = 0;
  puVar8 = local_274;
  pDVar10 = &local_318;
  for (iVar3 = 0x27; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)pDVar10->dmDeviceName = *puVar8;
    puVar8 = puVar8 + 1;
    pDVar10 = (DEVMODEA *)(pDVar10->dmDeviceName + 4);
  }
  local_318.dmSize = 0x9c;
  BVar1 = EnumDisplaySettingsA(lpszDeviceName,0,&local_318);
  if (BVar1 == 0) {
    return 0;
  }
  do {
    if (((0x27f < local_318.dmPelsWidth) && (0x1df < local_318.dmPelsHeight)) &&
       (local_318.dmBitsPerPel == DAT_1000c160)) {
      puVar4 = &DAT_1000c320;
      uVar6 = 1;
      while (*puVar4 != 0) {
        cVar11 = *puVar4 == local_318.dmPelsWidth;
        if (puVar4[1] == local_318.dmPelsHeight) {
          cVar11 = cVar11 + '\x01';
        }
        if (puVar4[2] == local_318.dmBitsPerPel) {
          cVar11 = cVar11 + '\x01';
        }
        if (cVar11 == '\x03') goto LAB_10004e95;
        uVar6 = uVar6 + 1;
        puVar4 = puVar4 + 10;
        if (0x62 < uVar6) {
          return local_324;
        }
      }
      *puVar4 = local_318.dmPelsWidth;
      uVar5 = 1;
      puVar4[1] = local_318.dmPelsHeight;
      puVar2 = &DAT_1000c320;
      puVar4[2] = local_318.dmBitsPerPel;
      puVar4[3] = 4;
      puVar4[4] = 1;
      puVar4[5] = 3;
      puVar4[6] = 3;
      if (1 < uVar6) {
LAB_10004e40:
        if ((puVar2[2] <= local_318.dmBitsPerPel) &&
           ((local_318.dmBitsPerPel != puVar2[2] ||
            ((*puVar2 <= local_318.dmPelsWidth &&
             ((local_318.dmPelsWidth != *puVar2 || (puVar2[1] <= local_318.dmPelsHeight))))))))
        break;
        puVar7 = puVar2;
        puVar9 = local_1d8;
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar9 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar9 = puVar9 + 1;
        }
        puVar7 = puVar4;
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar2 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar2 = puVar2 + 1;
        }
        puVar2 = local_1d8;
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar4 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar4 = puVar4 + 1;
        }
      }
LAB_10004e95:
      if (uVar6 == 0) {
        return local_324;
      }
LAB_10004e99:
      local_324 = 1;
      if (DAT_1000d2a0 < uVar6) {
        DAT_1000d2a0 = uVar6;
      }
    }
    memset(local_274,0,0x9c);
    puVar8 = local_274;
    pDVar10 = &local_318;
    for (iVar3 = 0x27; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined4 *)pDVar10->dmDeviceName = *puVar8;
      puVar8 = puVar8 + 1;
      pDVar10 = (DEVMODEA *)(pDVar10->dmDeviceName + 4);
    }
    local_318.dmSize = 0x9c;
    local_31c = local_31c + 1;
    BVar1 = EnumDisplaySettingsA(lpszDeviceName,local_31c,&local_318);
    if (BVar1 == 0) {
      return local_324;
    }
  } while( true );
  uVar5 = uVar5 + 1;
  puVar2 = puVar2 + 10;
  if (uVar6 <= uVar5) goto LAB_10004e99;
  goto LAB_10004e40;
}



/* VA 10004f20 */

undefined4
FUN_10004f20(undefined4 param_1,HWND param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 *param_6)

{
  HMONITOR hMonitor;
  DWORD lParam;
  HMODULE hModule;
  LRESULT LVar1;
  uint uVar2;
  uint uVar3;
  LONG LVar4;
  code *pcVar5;
  tagRECT local_448;
  uint local_438;
  tagMONITORINFO local_434;
  WINDOWPLACEMENT local_40c;
  DEVMODEA local_3e0;
  _DISPLAY_DEVICEA local_340;
  char local_198 [404];

  DAT_1000d2a4 = (uint *)(&DAT_1000c2f8 + param_4 * 0x28);
  if (DAT_1000c204 == 0) {
    if (DAT_1000c15c == 0) {
      uVar2 = *DAT_1000d2a4;
      uVar3 = *(uint *)(&DAT_1000c2fc + param_4 * 0x28);
    }
    else {
      uVar2 = DAT_1000d2a8;
      uVar3 = DAT_1000d2ac;
      if (DAT_1000c15c != 1) {
        uVar2 = (uint)*(ushort *)(&DAT_1000ab40 + DAT_1000c15c * 4);
        uVar3 = (uint)*(ushort *)(&DAT_1000ab40 + DAT_1000c15c * 4);
      }
    }
    FUN_100043c0(uVar2,uVar3);
    if (DAT_1000c158 == 0) {
      memset(local_340.DeviceName,0,0x1a4);
      local_340.cb = 0x1a8;
      memset(&local_3e0,0,0x9c);
      local_3e0.dmSize = 0x9c;
      EnumDisplayDevicesA((LPCSTR)0x0,DAT_1000c2f4,&local_340,0);
      EnumDisplaySettingsA(local_340.DeviceName,0xfffffffe,&local_3e0);
      uVar2 = GetWindowLongA(param_2,-0x10);
      local_448.bottom = DAT_1000c280;
      local_3e0.dmPelsHeight = DAT_1000c280;
      local_448.left = 0;
      local_448.top = (DAT_1000c16c != 0) - 1;
      local_448.right = DAT_1000c27c;
      local_3e0.dmPelsWidth = DAT_1000c27c;
      local_3e0.dmBitsPerPel = DAT_1000d2a4[2];
      local_3e0.dmFields = 0x1c0000;
      if (DAT_1000c168 != 0) {
        local_3e0.dmDisplayFrequency = (DWORD)(byte)(&DAT_1000ab3b)[DAT_1000c168];
        local_3e0.dmFields = 0x5c0000;
      }
      LVar4 = ChangeDisplaySettingsExA
                        (local_340.DeviceName,&local_3e0,(HWND)0x0,0x40000006,(LPVOID)0x0);
      if ((LVar4 != 0) && (DAT_1002ba88 != (code *)0x0)) {
        sprintf(local_198,"%s:\n%s\n\n\nFILE %s\nLINE %d","Change","Bad display mode",
                "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Resolution.cpp",0x1dd);
        (*DAT_1002ba88)(0,local_198);
      }
      ChangeDisplaySettingsExA(local_340.DeviceName,&local_3e0,(HWND)0x0,0x40000004,(LPVOID)0x0);
      EnumDisplaySettingsA(local_340.DeviceName,0xffffffff,&local_3e0);
      AdjustWindowRect(&local_448,uVar2 | 0x6000000,0);
      SetWindowPos(param_2,(HWND)0xfffffffe,
                   local_3e0.field6_0x2c.field1.dmPosition.x + local_448.left,
                   local_3e0.field6_0x2c.field1.dmPosition.y + local_448.top,
                   local_448.right - local_448.left,local_448.bottom - local_448.top,0);
    }
    else {
      hMonitor = MonitorFromWindow(param_2,2);
      local_434.cbSize = 0x28;
      local_434.rcMonitor.left = 0;
      local_434.rcMonitor.top = 0;
      local_434.rcMonitor.right = 0;
      local_434.rcMonitor.bottom = 0;
      local_434.rcWork.left = 0;
      local_434.rcWork.top = 0;
      local_434.rcWork.right = 0;
      local_434.rcWork.bottom = 0;
      local_434.dwFlags = 0;
      GetMonitorInfoA(hMonitor,&local_434);
      LVar4 = 0x12cf0000;
      local_448.top = local_434.rcWork.bottom - DAT_1000c280 >> 1;
      local_448.left = local_434.rcWork.right - DAT_1000c27c >> 1;
      local_448.right = DAT_1000c27c + local_448.left;
      local_438 = 0x12cf0000;
      local_448.bottom = local_448.top + DAT_1000c280;
      AdjustWindowRect(&local_448,0x12cf0000,0);
      pcVar5 = SetWindowLongA_exref;
      if ((local_434.rcWork.right - local_434.rcWork.left <= local_448.right - local_448.left) ||
         (local_434.rcWork.bottom - local_434.rcWork.top <= local_448.bottom - local_448.top)) {
        LVar4 = 0x13cf0000;
        local_438 = 0x13cf0000;
      }
      SetWindowLongA(param_2,-0x10,LVar4);
      SetWindowLongA(param_2,-0x14,0x40001);
      lParam = GetClassLongA(param_2,-0xe);
      if (lParam == 0) {
        hModule = (HMODULE)GetWindowLongA(param_2,-6);
        EnumResourceNamesA(hModule,(LPCSTR)0xe,FUN_10004af0,(LONG_PTR)param_2);
      }
      else {
        LVar1 = SendMessageA(param_2,0x7f,1,0);
        if (LVar1 == 0) {
          SendMessageA(param_2,0x80,1,lParam);
        }
        LVar1 = SendMessageA(param_2,0x80,0,0);
        pcVar5 = SetWindowLongA_exref;
        if (LVar1 == 0) {
          SendMessageA(param_2,0x80,0,lParam);
          pcVar5 = SetWindowLongA_exref;
        }
      }
      if ((local_438 & 0x1000000) != 0) {
        SetWindowPos(param_2,(HWND)0xfffffffe,local_434.rcWork.left,local_434.rcWork.top,
                     local_434.rcWork.right - local_434.rcWork.left,
                     local_434.rcWork.bottom - local_434.rcWork.top,0);
      }
      local_40c.flags = 0;
      local_40c.showCmd = 0;
      local_40c.ptMinPosition.x = 0;
      local_40c.ptMinPosition.y = 0;
      local_40c.ptMaxPosition.x = 0;
      local_40c.ptMaxPosition.y = 0;
      local_40c.rcNormalPosition.left = 0;
      local_40c.rcNormalPosition.top = 0;
      local_40c.rcNormalPosition.right = 0;
      local_40c.rcNormalPosition.bottom = 0;
      local_40c.length = 0x2c;
      GetWindowPlacement(param_2,&local_40c);
      local_40c.rcNormalPosition.left = local_448.left;
      local_40c.rcNormalPosition.top = local_448.top;
      local_40c.rcNormalPosition.right = local_448.right;
      local_40c.rcNormalPosition.bottom = local_448.bottom;
      SetWindowPlacement(param_2,&local_40c);
      GetClientRect(param_2,&local_448);
      FUN_100043c0(local_448.right,local_448.bottom);
      if (DAT_1002c6d0 == 0) {
        DAT_1002c6d0 = (*pcVar5)(param_2,0xfffffffc,FUN_100046f0);
      }
    }
  }
  else {
    GetClientRect(param_2,&local_448);
    FUN_100043c0(local_448.right - local_448.left,local_448.bottom - local_448.top);
    if (DAT_1002c6d0 == 0) {
      DAT_1002c6d0 = SetWindowLongA(param_2,-4,0x10004920);
    }
  }
  if (param_6 != (undefined4 *)0x0) {
    SetEvent(DAT_1002ba9c);
    *param_6 = 1;
  }
  return 1;
}



/* VA 10005400 */

undefined4 FUN_10005400(void)

{
  undefined4 *in_stack_00000018;

  if ((DAT_1000c158 == 0) && (DAT_1000c204 == 0)) {
    ChangeDisplaySettingsA((DEVMODEA *)0x0,0);
  }
  if (in_stack_00000018 != (undefined4 *)0x0) {
    SetEvent(DAT_1002ba6c);
    *in_stack_00000018 = 1;
  }
  return 1;
}



/* VA 10005450 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_10005450(uint param_1,uint param_2,undefined *param_3)

{
  ushort uVar1;
  ushort uVar2;
  float fVar3;
  double dVar4;
  code *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  float *pfVar11;
  uint uVar12;
  ushort *puVar13;
  undefined *puVar14;
  int iVar15;
  float *pfVar16;
  int *piVar17;
  ushort *puVar18;
  int iVar19;
  undefined4 uVar20;
  float *pfVar21;
  float *pfVar22;
  int *piVar23;
  undefined4 uVar24;
  uint uVar25;
  float *pfVar26;
  int iVar27;
  bool bVar28;
  float10 fVar29;
  ulonglong uVar30;
  undefined8 local_88;
  int *local_74;
  undefined4 local_60 [23];

  uVar25 = param_2 & 0xffff;
  local_74 = (int *)0x0;
  iVar6 = FUN_10009a20(param_1);
  if (-1 < iVar6) {
    local_74 = (int *)(&DAT_1002bc40 + (uVar25 * 0x8c + iVar6) * 4);
  }
  if (param_1 == 0x1b3) {
    if (DAT_1000d2b8 != (*(uint *)param_3 & 0x80)) {
      DAT_1000d2b8 = *(uint *)param_3 & 0x80;
      (*DAT_1000c0ac)(DAT_1000c1e8);
    }
    puVar13 = *(ushort **)(param_3 + 0x10);
    pcVar5 = DAT_1000c274;
    if ((puVar13 == (ushort *)0x0) || (uVar25 = *(uint *)(param_3 + 0x14), uVar25 == 0)) {
      switch(*(undefined4 *)param_3) {
      case 1:
        local_88._4_4_ = *(uint *)(param_3 + 0xc);
        if (local_88._4_4_ != 0) {
          puVar8 = *(undefined4 **)(param_3 + 8);
          do {
            if ((DAT_1000d2d0 != 0) || (DAT_1000d2d8 == 0xf3c)) {
              FUN_10008a60();
              DAT_1000d2d0 = 0;
            }
            puVar9 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
            local_88._4_4_ = local_88._4_4_ + -1;
            puVar10 = puVar8;
            puVar7 = puVar9;
            DAT_1000d2d8 = DAT_1000d2d8 + 1;
            for (iVar19 = 8; iVar19 != 0; iVar19 = iVar19 + -1) {
              *puVar7 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar9[2] = (float)puVar9[2] + _DAT_1000c2d0;
            puVar8 = puVar8 + 8;
            pcVar5 = DAT_1000c274;
          } while (local_88._4_4_ != 0);
        }
        break;
      case 2:
        local_88._4_4_ = *(uint *)(param_3 + 0xc) >> 1;
        if (local_88._4_4_ != 0) {
          puVar8 = *(undefined4 **)(param_3 + 8);
          do {
            if ((DAT_1000d2d0 != 1) || (DAT_1000d2d8 == 0xf3c)) {
              FUN_10008a60();
              DAT_1000d2d0 = 1;
            }
            fVar3 = _DAT_1000c2d0;
            puVar9 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
            puVar10 = puVar8;
            puVar7 = puVar9;
            DAT_1000d2d8 = DAT_1000d2d8 + 1;
            for (iVar19 = 8; iVar19 != 0; iVar19 = iVar19 + -1) {
              *puVar7 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar9[2] = (float)puVar9[2] + fVar3;
            iVar19 = DAT_1000d2d8 * 0x20;
            DAT_1000d2d8 = DAT_1000d2d8 + 1;
            puVar9 = (undefined4 *)(iVar19 + DAT_1000d2dc);
            local_88._4_4_ = local_88._4_4_ - 1;
            puVar10 = puVar8 + 8;
            puVar7 = puVar9;
            for (iVar19 = 8; iVar19 != 0; iVar19 = iVar19 + -1) {
              *puVar7 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar9[2] = fVar3 + (float)puVar9[2];
            puVar8 = puVar8 + 0x10;
            pcVar5 = DAT_1000c274;
          } while (local_88._4_4_ != 0);
        }
        break;
      case 3:
        iVar19 = *(int *)(param_3 + 0xc);
        if (iVar19 != 1) {
          puVar8 = *(undefined4 **)(param_3 + 8);
          if ((DAT_1000d2d0 != 1) || (DAT_1000d2d8 == 0xf3c)) {
            FUN_10008a60();
            DAT_1000d2d0 = 1;
          }
          fVar3 = _DAT_1000c2d0;
          iVar27 = DAT_1000d2d8 * 0x20;
          DAT_1000d2d8 = DAT_1000d2d8 + 1;
          puVar9 = (undefined4 *)(iVar27 + DAT_1000d2dc);
          puVar10 = puVar8;
          puVar7 = puVar9;
          for (iVar27 = 8; iVar27 != 0; iVar27 = iVar27 + -1) {
            *puVar7 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar7 = puVar7 + 1;
          }
          puVar9[2] = (float)puVar9[2] + fVar3;
          puVar9 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
          iVar19 = iVar19 + -2;
          puVar10 = puVar8 + 8;
          puVar7 = puVar9;
          DAT_1000d2d8 = DAT_1000d2d8 + 1;
          for (iVar27 = 8; iVar27 != 0; iVar27 = iVar27 + -1) {
            *puVar7 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar7 = puVar7 + 1;
          }
          puVar9[2] = fVar3 + (float)puVar9[2];
          puVar10 = puVar8 + 8;
          puVar8 = puVar8 + 0x10;
          while (pcVar5 = DAT_1000c274, iVar19 != 0) {
            if ((DAT_1000d2d0 != 1) || (DAT_1000d2d8 == 0xf3c)) {
              FUN_10008a60();
              DAT_1000d2d0 = 1;
              fVar3 = _DAT_1000c2d0;
            }
            iVar27 = DAT_1000d2d8 * 0x20;
            DAT_1000d2d8 = DAT_1000d2d8 + 1;
            puVar9 = (undefined4 *)(iVar27 + DAT_1000d2dc);
            puVar7 = puVar9;
            for (iVar27 = 8; iVar27 != 0; iVar27 = iVar27 + -1) {
              *puVar7 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar9[2] = (float)puVar9[2] + fVar3;
            puVar9 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
            iVar19 = iVar19 + -1;
            puVar10 = puVar8;
            puVar7 = puVar9;
            DAT_1000d2d8 = DAT_1000d2d8 + 1;
            for (iVar27 = 8; iVar27 != 0; iVar27 = iVar27 + -1) {
              *puVar7 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar9[2] = fVar3 + (float)puVar9[2];
            puVar10 = puVar8;
            puVar8 = puVar8 + 8;
          }
        }
        break;
      case 4:
        uVar25 = *(uint *)(param_3 + 0xc) / 3;
        if (uVar25 != 0) {
          pfVar21 = *(float **)(param_3 + 8);
          do {
            FUN_10008cb0(pfVar21,pfVar21 + 8,pfVar21 + 0x10);
            uVar25 = uVar25 - 1;
            pfVar21 = pfVar21 + 0x18;
            pcVar5 = DAT_1000c274;
          } while (uVar25 != 0);
        }
        break;
      case 5:
        iVar19 = *(int *)(param_3 + 0xc);
        if (iVar19 != 2) {
          pfVar21 = *(float **)(param_3 + 8);
          FUN_10008cb0(pfVar21,pfVar21 + 8,pfVar21 + 0x10);
          local_88 = ZEXT48(pfVar21 + 8);
          pfVar11 = pfVar21 + 0x10;
          pfVar21 = pfVar21 + 0x18;
          for (iVar19 = iVar19 + -3; pcVar5 = DAT_1000c274, iVar19 != 0; iVar19 = iVar19 + -1) {
            local_88._4_4_ = (uint)(local_88 >> 0x20);
            pfVar16 = (float *)local_88;
            pfVar22 = pfVar11;
            if (local_88._4_4_ == 0) {
              pfVar16 = pfVar11;
              pfVar22 = (float *)local_88;
            }
            FUN_10008cb0(pfVar16,pfVar22,pfVar21);
            local_88 = CONCAT44(local_88._4_4_,pfVar11) ^ 0x100000000;
            pfVar11 = pfVar21;
            pfVar21 = pfVar21 + 8;
          }
        }
        break;
      case 6:
        iVar19 = *(int *)(param_3 + 0xc);
        if (iVar19 != 2) {
          pfVar21 = *(float **)(param_3 + 8);
          FUN_10008cb0(pfVar21,pfVar21 + 8,pfVar21 + 0x10);
          pfVar11 = pfVar21 + 0x10;
          pfVar22 = pfVar21 + 0x18;
          for (iVar19 = iVar19 + -3; pcVar5 = DAT_1000c274, iVar19 != 0; iVar19 = iVar19 + -1) {
            FUN_10008cb0(pfVar21,pfVar11,pfVar22);
            pfVar11 = pfVar22;
            pfVar22 = pfVar22 + 8;
          }
        }
        break;
      default:
        goto switchD_100054f0_default;
      }
    }
    else {
      switch(*(undefined4 *)param_3) {
      case 1:
        iVar19 = *(int *)(param_3 + 8);
        do {
          uVar2 = *puVar13;
          puVar13 = puVar13 + 1;
          if ((DAT_1000d2d0 != 0) || (DAT_1000d2d8 == 0xf3c)) {
            FUN_10008a60();
            DAT_1000d2d0 = 0;
          }
          fVar3 = _DAT_1000c2d0;
          iVar27 = DAT_1000d2d8 * 0x20;
          DAT_1000d2d8 = DAT_1000d2d8 + 1;
          puVar7 = (undefined4 *)(iVar27 + DAT_1000d2dc);
          uVar25 = uVar25 - 1;
          puVar8 = (undefined4 *)((uint)uVar2 * 0x20 + iVar19);
          puVar10 = puVar7;
          for (iVar27 = 8; iVar27 != 0; iVar27 = iVar27 + -1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar10 = puVar10 + 1;
          }
          puVar7[2] = fVar3 + (float)puVar7[2];
          pcVar5 = DAT_1000c274;
        } while (uVar25 != 0);
        break;
      case 2:
        local_88._0_4_ = (float *)(uVar25 >> 1);
        if ((float *)local_88 != (float *)0x0) {
          iVar19 = *(int *)(param_3 + 8);
          do {
            uVar2 = *puVar13;
            uVar1 = puVar13[1];
            if ((DAT_1000d2d0 != 1) || (DAT_1000d2d8 == 0xf3c)) {
              FUN_10008a60();
              DAT_1000d2d0 = 1;
            }
            fVar3 = _DAT_1000c2d0;
            puVar7 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
            puVar8 = (undefined4 *)((uint)uVar2 * 0x20 + iVar19);
            puVar10 = puVar7;
            DAT_1000d2d8 = DAT_1000d2d8 + 1;
            for (iVar27 = 8; iVar27 != 0; iVar27 = iVar27 + -1) {
              *puVar10 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar10 = puVar10 + 1;
            }
            puVar7[2] = (float)puVar7[2] + fVar3;
            iVar27 = DAT_1000d2d8 * 0x20;
            DAT_1000d2d8 = DAT_1000d2d8 + 1;
            puVar7 = (undefined4 *)(iVar27 + DAT_1000d2dc);
            local_88._0_4_ = (float *)((int)(float *)local_88 - 1);
            puVar8 = (undefined4 *)((uint)uVar1 * 0x20 + iVar19);
            puVar10 = puVar7;
            for (iVar27 = 8; iVar27 != 0; iVar27 = iVar27 + -1) {
              *puVar10 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar10 = puVar10 + 1;
            }
            puVar7[2] = fVar3 + (float)puVar7[2];
            puVar13 = puVar13 + 2;
            pcVar5 = DAT_1000c274;
          } while ((float *)local_88 != (float *)0x0);
        }
        break;
      case 3:
        if (uVar25 != 1) {
          uVar2 = *puVar13;
          iVar19 = *(int *)(param_3 + 8);
          puVar8 = (undefined4 *)((uint)puVar13[1] * 0x20 + iVar19);
          if ((DAT_1000d2d0 != 1) || (DAT_1000d2d8 == 0xf3c)) {
            FUN_10008a60();
            DAT_1000d2d0 = 1;
          }
          fVar3 = _DAT_1000c2d0;
          iVar27 = DAT_1000d2d8 * 0x20;
          DAT_1000d2d8 = DAT_1000d2d8 + 1;
          puVar9 = (undefined4 *)(iVar27 + DAT_1000d2dc);
          puVar10 = (undefined4 *)((uint)uVar2 * 0x20 + iVar19);
          puVar7 = puVar9;
          for (iVar27 = 8; iVar27 != 0; iVar27 = iVar27 + -1) {
            *puVar7 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar7 = puVar7 + 1;
          }
          puVar9[2] = (float)puVar9[2] + fVar3;
          puVar9 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
          iVar27 = uVar25 - 2;
          puVar10 = puVar8;
          puVar7 = puVar9;
          DAT_1000d2d8 = DAT_1000d2d8 + 1;
          for (iVar15 = 8; iVar15 != 0; iVar15 = iVar15 + -1) {
            *puVar7 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar7 = puVar7 + 1;
          }
          puVar9[2] = fVar3 + (float)puVar9[2];
          puVar13 = puVar13 + 2;
          while (pcVar5 = DAT_1000c274, iVar27 != 0) {
            puVar10 = (undefined4 *)((uint)*puVar13 * 0x20 + iVar19);
            if ((DAT_1000d2d0 != 1) || (DAT_1000d2d8 == 0xf3c)) {
              FUN_10008a60();
              DAT_1000d2d0 = 1;
              fVar3 = _DAT_1000c2d0;
            }
            iVar15 = DAT_1000d2d8 * 0x20;
            DAT_1000d2d8 = DAT_1000d2d8 + 1;
            puVar9 = (undefined4 *)(iVar15 + DAT_1000d2dc);
            puVar7 = puVar9;
            for (iVar15 = 8; iVar15 != 0; iVar15 = iVar15 + -1) {
              *puVar7 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar9[2] = (float)puVar9[2] + fVar3;
            puVar9 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
            iVar27 = iVar27 + -1;
            puVar8 = puVar10;
            puVar7 = puVar9;
            DAT_1000d2d8 = DAT_1000d2d8 + 1;
            for (iVar15 = 8; iVar15 != 0; iVar15 = iVar15 + -1) {
              *puVar7 = *puVar8;
              puVar8 = puVar8 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar9[2] = fVar3 + (float)puVar9[2];
            puVar13 = puVar13 + 1;
            puVar8 = puVar10;
          }
        }
        break;
      case 4:
        uVar25 = uVar25 / 3;
        if (uVar25 != 0) {
          iVar19 = *(int *)(param_3 + 8);
          do {
            FUN_10008cb0((float *)((uint)*puVar13 * 0x20 + iVar19),
                         (float *)((uint)puVar13[1] * 0x20 + iVar19),
                         (float *)((uint)puVar13[2] * 0x20 + iVar19));
            uVar25 = uVar25 - 1;
            puVar13 = puVar13 + 3;
            pcVar5 = DAT_1000c274;
          } while (uVar25 != 0);
        }
        break;
      case 5:
        if (uVar25 != 2) {
          iVar19 = *(int *)(param_3 + 8);
          puVar18 = puVar13 + 3;
          pfVar21 = (float *)((uint)puVar13[1] * 0x20 + iVar19);
          pfVar11 = (float *)((uint)puVar13[2] * 0x20 + iVar19);
          FUN_10008cb0((float *)((uint)*puVar13 * 0x20 + iVar19),pfVar21,pfVar11);
          uVar25 = uVar25 - 3;
          local_88 = (ulonglong)uVar25;
          uVar30 = local_88;
          while (pcVar5 = DAT_1000c274, uVar25 != 0) {
            uVar2 = *puVar18;
            puVar18 = puVar18 + 1;
            pfVar26 = (float *)(iVar19 + (uint)uVar2 * 0x20);
            local_88._4_4_ = (uint)(uVar30 >> 0x20);
            pfVar16 = pfVar21;
            pfVar22 = pfVar11;
            if (local_88._4_4_ == 0) {
              pfVar16 = pfVar11;
              pfVar22 = pfVar21;
            }
            FUN_10008cb0(pfVar16,pfVar22,pfVar26);
            local_88._0_4_ = (float *)uVar30;
            uVar25 = (int)(float *)local_88 - 1;
            local_88 = CONCAT44(local_88._4_4_,uVar25) ^ 0x100000000;
            pfVar21 = pfVar11;
            pfVar11 = pfVar26;
            uVar30 = local_88;
          }
        }
        break;
      case 6:
        if (uVar25 != 2) {
          iVar19 = *(int *)(param_3 + 8);
          pfVar11 = (float *)((uint)*puVar13 * 0x20 + iVar19);
          pfVar21 = (float *)((uint)puVar13[2] * 0x20 + iVar19);
          FUN_10008cb0(pfVar11,(float *)((uint)puVar13[1] * 0x20 + iVar19),pfVar21);
          puVar13 = puVar13 + 3;
          for (iVar27 = uVar25 - 3; pcVar5 = DAT_1000c274, iVar27 != 0; iVar27 = iVar27 + -1) {
            pfVar22 = (float *)((uint)*puVar13 * 0x20 + iVar19);
            FUN_10008cb0(pfVar11,pfVar21,pfVar22);
            puVar13 = puVar13 + 1;
            pfVar21 = pfVar22;
          }
        }
        break;
      default:
switchD_100054f0_default:
        return 0;
      }
    }
    goto switchD_10005ce7_caseD_c;
  }
  if ((local_74 != (int *)0x0) && ((param_2 & 0xffff0000) == 0)) {
    uVar12 = 0;
    do {
      if (*(uint *)((int)&DAT_1000abb8 + uVar12) == param_1) {
        if ((undefined *)*local_74 == param_3) {
          return 1;
        }
        FUN_10008a60();
        goto LAB_10005cc4;
      }
      uVar12 = uVar12 + 4;
    } while (uVar12 < 0x8c);
    if ((undefined *)*local_74 == param_3) {
      return 1;
    }
  }
LAB_10005cc4:
  pcVar5 = DAT_1000c274;
  if (0x194 < (int)param_1) {
    if (param_1 != 0x195) goto switchD_10005ce7_caseD_c;
    switch(param_3) {
    case (undefined *)0x0:
      uVar30 = CONCAT44(1,DAT_1000c20c);
      DAT_1000c2b0 = 1;
      break;
    case (undefined *)0x1:
      uVar30 = (ulonglong)DAT_1000c20c;
      DAT_1000c2b0 = 0;
      break;
    case (undefined *)0x2:
      uVar30 = CONCAT44(0x302,DAT_1000c20c);
      DAT_1000c2b0 = 0x302;
      break;
    case (undefined *)0x3:
      uVar30 = CONCAT44(0x303,DAT_1000c20c);
      DAT_1000c2b0 = 0x303;
      break;
    case (undefined *)0x4:
      uVar30 = CONCAT44(0x304,DAT_1000c20c);
      DAT_1000c2b0 = 0x304;
      break;
    case (undefined *)0x5:
      uVar30 = CONCAT44(0x305,DAT_1000c20c);
      DAT_1000c2b0 = 0x305;
      break;
    case (undefined *)0x6:
      uVar30 = CONCAT44(0x300,DAT_1000c20c);
      DAT_1000c2b0 = 0x300;
      break;
    case (undefined *)0x7:
      uVar30 = CONCAT44(0x306,DAT_1000c20c);
      DAT_1000c2b0 = 0x306;
      break;
    case (undefined *)0x8:
      uVar30 = CONCAT44(0x301,DAT_1000c20c);
      DAT_1000c2b0 = 0x301;
      break;
    case (undefined *)0x9:
      uVar30 = CONCAT44(0x307,DAT_1000c20c);
      DAT_1000c2b0 = 0x307;
      break;
    default:
      goto switchD_100054f0_default;
    }
LAB_1000699c:
    (*DAT_1000c0d8)(uVar30);
    iVar19 = FUN_10009a20(0x38);
    if (-1 < iVar19) {
      *(undefined4 *)(&DAT_1002bc40 + (uVar25 * 0x8c + iVar19) * 4) = 4;
    }
    iVar19 = FUN_10009a20(0x68);
    pcVar5 = DAT_1000c274;
    if (-1 < iVar19) {
      *(undefined4 *)(&DAT_1002bc40 + (uVar25 * 0x8c + iVar19) * 4) = 4;
      pcVar5 = DAT_1000c274;
    }
    goto switchD_10005ce7_caseD_c;
  }
  if (param_1 == 0x194) {
    switch(param_3) {
    case (undefined *)0x0:
      DAT_1000c20c = 1;
      break;
    case (undefined *)0x1:
      DAT_1000c20c = 0;
      break;
    case (undefined *)0x2:
      DAT_1000c20c = 0x302;
      break;
    case (undefined *)0x3:
      DAT_1000c20c = 0x303;
      break;
    case (undefined *)0x4:
      DAT_1000c20c = 0x304;
      break;
    case (undefined *)0x5:
      DAT_1000c20c = 0x305;
      break;
    case (undefined *)0x6:
      DAT_1000c20c = 0x300;
      break;
    case (undefined *)0x7:
      DAT_1000c20c = 0x306;
      break;
    case (undefined *)0x8:
      DAT_1000c20c = 0x301;
      break;
    case (undefined *)0x9:
      DAT_1000c20c = 0x307;
      break;
    default:
      goto switchD_100054f0_default;
    }
    uVar30 = CONCAT44(DAT_1000c2b0,DAT_1000c20c);
    goto LAB_1000699c;
  }
  switch(param_1) {
  case 1:
    DAT_1000c2b4 = (uint)((undefined *)0xf < param_3);
    if (((undefined *)0xf < param_3) &&
       (puVar13 = *(ushort **)(param_3 + 0x38), puVar13 != (ushort *)0x0)) {
      piVar17 = *(int **)(param_3 + 0x40);
      if (piVar17 == (int *)0x0) {
LAB_10005d2d:
        _THRASH_tupdate_12((undefined4 *)param_3,puVar13,(undefined4 *)0x0);
      }
      else {
        piVar23 = &DAT_1002c2d0;
        uVar25 = 0x3fc;
        do {
          if (*piVar17 != *piVar23) {
            puVar13 = *(ushort **)(param_3 + 0x38);
            goto LAB_10005d2d;
          }
          piVar17 = piVar17 + 1;
          piVar23 = piVar23 + 1;
          bVar28 = 3 < uVar25;
          uVar25 = uVar25 - 4;
        } while (bVar28);
      }
    }
    (*DAT_1000c0ac)(DAT_1000c1b4,DAT_1000c2b4);
    pcVar5 = DAT_1000c274;
    if (((param_3 == (undefined *)0x0) || (DAT_1000d2c4 == 0)) || (param_3 < (undefined *)0x10)) {
      DAT_1000d2c0 = (undefined *)0x0;
    }
    else if (DAT_1000d2c0 != param_3) {
      DAT_1000d2c0 = param_3;
      (*DAT_1000c084)(0xde1,*(undefined4 *)param_3);
      pcVar5 = DAT_1000c274;
    }
    break;
  case 2:
    pcVar5 = (code *)param_3;
    if ((undefined *)0x2 < param_3) {
      return 0;
    }
    break;
  case 3:
    _DAT_1000d2b4 = param_3;
    fVar29 = (float10)_CIpow();
    fVar29 = (float10)_CIpow((float)fVar29);
    fVar29 = (float10)_CIpow((float)fVar29);
    (*DAT_1000c0bc)((float)fVar29);
    pcVar5 = DAT_1000c274;
    break;
  case 4:
    if (param_3 != (undefined *)0x0) {
      if (param_3 != (undefined *)0x1) {
        return 0;
      }
      DAT_1000c200 = 1;
      (*DAT_1000c080)();
      (*DAT_1000c07c)(DAT_1000c00c);
      pcVar5 = DAT_1000c274;
      break;
    }
    DAT_1000c200 = 0;
    goto LAB_10005ec2;
  case 5:
    if (param_3 != (undefined *)0x0) {
      (*DAT_1000c080)();
      pcVar5 = DAT_1000c274;
      break;
    }
LAB_10005ec2:
    (*DAT_1000c05c)();
    pcVar5 = DAT_1000c274;
    break;
  case 6:
    if ((param_3 == (undefined *)0x0) || (param_3 == (undefined *)0x1)) {
      (*DAT_1000c0ac)(DAT_1000c1ec);
      pcVar5 = DAT_1000c274;
      if (DAT_1000d2b8 != 0) {
        DAT_1000d2b8 = 0;
        (*DAT_1000c0ac)(DAT_1000c1e8,0);
        pcVar5 = DAT_1000c274;
      }
    }
    else {
      if (param_3 != (undefined *)0x2) {
        return 0;
      }
      (*DAT_1000c0ac)(DAT_1000c1ec,1);
      pcVar5 = DAT_1000c274;
      if (DAT_1000d2b8 != 1) {
        DAT_1000d2b8 = 1;
        (*DAT_1000c0ac)(DAT_1000c1e8,1);
        pcVar5 = DAT_1000c274;
      }
    }
    break;
  case 7:
  case 0x4a:
    DAT_1000c2dc = (code *)param_3;
    break;
  case 8:
    _DAT_1000c2ac = param_3;
    break;
  case 9:
    if (param_3 == (undefined *)0x0) {
      (*DAT_1000c05c)();
      (*DAT_1000c05c)(0xb20);
      (*DAT_1000c05c)(0xb41);
      pcVar5 = DAT_1000c274;
    }
    else {
      if (param_3 != (undefined *)0x1) {
        return 0;
      }
      (*DAT_1000c080)();
      (*DAT_1000c080)(0xb20);
      (*DAT_1000c080)(0xb41);
      pcVar5 = DAT_1000c274;
    }
    break;
  case 10:
    if ((code *)0x6a < DAT_1000c004) {
      switch(param_3) {
      case (undefined *)0x0:
      case (undefined *)0x1:
        goto switchD_10005fc9_caseD_0;
      case (undefined *)0x2:
      case (undefined *)0x3:
        goto switchD_10005fc9_caseD_2;
      default:
        goto switchD_100054f0_default;
      }
    }
    if (param_3 == (undefined *)0x0) {
switchD_10005fc9_caseD_0:
      (*DAT_1000c0ac)(DAT_1000c1d8,7);
      (*DAT_1000c05c)(0xbe2);
      pcVar5 = DAT_1000c274;
    }
    else {
      if ((param_3 != (undefined *)0x1) && (param_3 != (undefined *)0x2)) {
        return 0;
      }
switchD_10005fc9_caseD_2:
      (*DAT_1000c0ac)(DAT_1000c1d8,4);
      (*DAT_1000c080)(0xbe2);
      (*DAT_1000c0d8)(DAT_1000c20c,DAT_1000c2b0);
      pcVar5 = DAT_1000c274;
    }
    break;
  case 0xb:
    DAT_1000c2d8 = (code *)param_3;
    break;
  case 0xd:
    if (param_3 == (undefined *)0x0) {
      DAT_1000c208 = 0x812f;
LAB_10005e0a:
      DAT_1000c2f0 = 0x812f;
      break;
    }
    if (param_3 != (undefined *)0x1) {
      if (param_3 != (undefined *)0x2) {
        return 0;
      }
      DAT_1000c208 = 0x8370;
      DAT_1000c2f0 = 0x8370;
      break;
    }
    DAT_1000c208 = 0x2901;
    goto LAB_10005df1;
  case 0xe:
    puVar14 = param_3;
    if ((param_3 != (undefined *)0x0) && (((uint)param_3 & 0xfffff000) == 0)) {
      dVar4 = (double)(int)param_3;
      if ((int)param_3 < 0) {
        dVar4 = dVar4 + _DAT_1000aff8;
      }
      puVar14 = (undefined *)(1.0 / (float)dVar4);
    }
    (*DAT_1000c04c)(DAT_1000c1f0,puVar14);
    pcVar5 = DAT_1000c274;
    break;
  case 0xf:
    fVar3 = (float)_DAT_1000aff0;
    (*DAT_1000c074)(DAT_1000c1d4,(float)((uint)param_3 >> 0x10 & 0xff) / fVar3,
                    (float)((uint)param_3 >> 8 & 0xff) / fVar3,(float)((uint)param_3 & 0xff) / fVar3
                    ,(float)((uint)param_3 >> 0x18) / fVar3);
    pcVar5 = DAT_1000c274;
    break;
  case 0x12:
    DAT_1000c204 = (code *)param_3;
    break;
  case 0x13:
    puVar10 = &DAT_1002ba70;
    iVar19 = 8;
    puVar8 = (undefined4 *)param_3;
    if (param_3 == (undefined *)0x0) {
      local_60[0] = 0;
      local_60[1] = 0;
      local_60[2] = 0;
      local_60[3] = 0;
      local_60[4] = 0;
      local_60[5] = 0;
      local_60[6] = 0;
      local_60[7] = 0;
      puVar8 = local_60;
      for (; pcVar5 = DAT_1000c274, iVar19 != 0; iVar19 = iVar19 + -1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
    }
    else {
      for (; pcVar5 = DAT_1000c274, iVar19 != 0; iVar19 = iVar19 + -1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
    }
    break;
  case 0x14:
  case 0x15:
  case 0x69:
    if (param_3 < (undefined *)0x2) {
      puVar14 = (undefined *)0x0;
      if (param_3 != (undefined *)0x0) {
        puVar14 = DAT_1000d2b0;
      }
      (*DAT_1000c0ac)(DAT_1000c1c8,puVar14);
      pcVar5 = DAT_1000c274;
    }
    else {
      DAT_1000d2b0 = param_3;
      (*DAT_1000c0ac)(DAT_1000c1c8,param_3);
      pcVar5 = DAT_1000c274;
    }
    break;
  case 0x16:
    fVar3 = (float)(int)param_3;
    if ((int)param_3 < 0) {
      fVar3 = fVar3 + _DAT_1000b000;
    }
    (*DAT_1000c04c)(DAT_1000c1c0,fVar3);
    pcVar5 = DAT_1000c274;
    break;
  case 0x17:
    fVar3 = (float)(int)param_3;
    if ((int)param_3 < 0) {
      fVar3 = fVar3 + _DAT_1000b000;
    }
    (*DAT_1000c04c)(DAT_1000c1cc,fVar3);
    pcVar5 = DAT_1000c274;
    break;
  case 0x18:
  case 0x66:
    _DAT_1000c2d0 = ((float)(int)param_3 + (float)(int)param_3) * (float)_DAT_1000afc0;
    break;
  case 0x19:
    DAT_1002ba60 = (code *)param_3;
    break;
  case 0x1a:
    DAT_1002ba88 = (code *)param_3;
    break;
  case 0x1b:
    DAT_1002ba78 = (code *)param_3;
    break;
  case 0x1c:
    DAT_1002ba84 = (code *)param_3;
    break;
  case 0x1d:
    if ((param_3 == (undefined *)0x0) && ((param_2 & 0xffff0000) == 0)) {
      return 0;
    }
    break;
  case 0x1f:
    DAT_1000c004 = (code *)param_3;
    break;
  case 0x20:
    DAT_1002ba90 = (code *)param_3;
    break;
  case 0x21:
    DAT_1002ba94 = (code *)param_3;
    break;
  case 0x24:
    if (param_3 == (undefined *)0x0) {
      fVar3 = 0.0;
    }
    else {
      fVar3 = (float)(int)param_3;
      if ((int)param_3 < 0) {
        fVar3 = fVar3 + _DAT_1000b000;
      }
      fVar3 = fVar3 / (float)_DAT_1000aff0;
    }
    (*DAT_1000c04c)(DAT_1000c1c4,fVar3);
    pcVar5 = DAT_1000c274;
    break;
  case 0x27:
    DAT_1002ba98 = (code *)param_3;
    break;
  case 0x28:
    switch(param_3) {
    case (undefined *)0x0:
      DAT_1000c00c = 0x200;
      (*DAT_1000c07c)();
      pcVar5 = DAT_1000c274;
      break;
    case (undefined *)0x1:
      DAT_1000c00c = 0x201;
      (*DAT_1000c07c)();
      pcVar5 = DAT_1000c274;
      break;
    case (undefined *)0x2:
      DAT_1000c00c = 0x202;
      (*DAT_1000c07c)();
      pcVar5 = DAT_1000c274;
      break;
    case (undefined *)0x3:
      DAT_1000c00c = 0x203;
      (*DAT_1000c07c)();
      pcVar5 = DAT_1000c274;
      break;
    case (undefined *)0x4:
      DAT_1000c00c = 0x204;
      (*DAT_1000c07c)();
      pcVar5 = DAT_1000c274;
      break;
    case (undefined *)0x5:
      DAT_1000c00c = 0x205;
      (*DAT_1000c07c)();
      pcVar5 = DAT_1000c274;
      break;
    case (undefined *)0x6:
      DAT_1000c00c = 0x206;
      (*DAT_1000c07c)();
      pcVar5 = DAT_1000c274;
      break;
    case (undefined *)0x7:
      DAT_1000c00c = 0x207;
      (*DAT_1000c07c)();
      pcVar5 = DAT_1000c274;
      break;
    default:
      goto switchD_100054f0_default;
    }
    break;
  case 0x2e:
  case 0x65:
    _DAT_1000c014 = _DAT_1000c178 * (float)param_3;
    (*DAT_1000c04c)(DAT_1000c1e0,_DAT_1000c014);
    _DAT_1000c014 = 1.0 / _DAT_1000c014;
    fVar29 = (float10)_CIpow((float)((uint)_DAT_1000d2b4 >> 0x18) / (float)_DAT_1000aff0);
    fVar29 = (float10)_CIpow((float)fVar29);
    uVar25 = (uint)_DAT_1000d2b4 >> 0x10;
    fVar29 = (float10)_CIpow((float)fVar29);
    local_74 = (int *)((ulonglong)(double)(uVar25 & 0xff) >> 0x20);
    (*DAT_1000c0bc)((float)fVar29);
    pcVar5 = DAT_1000c274;
    break;
  case 0x2f:
    if (param_3 == (undefined *)0x0) {
      (*DAT_1000c05c)();
      DAT_1000c1f4 = param_3;
      pcVar5 = DAT_1000c274;
    }
    else {
      (*DAT_1000c080)();
      (*DAT_1000c050)(DAT_1000c2cc,2,0xff);
      (*DAT_1000c044)(DAT_1000c010,DAT_1000c008,DAT_1000c000);
      DAT_1000c1f4 = param_3;
      pcVar5 = DAT_1000c274;
    }
    break;
  case 0x30:
    switch(param_3) {
    case (undefined *)0x0:
      DAT_1000c2cc = 0x200;
      break;
    case (undefined *)0x1:
      DAT_1000c2cc = 0x201;
      break;
    case (undefined *)0x2:
      DAT_1000c2cc = 0x202;
      break;
    case (undefined *)0x3:
      DAT_1000c2cc = 0x203;
      break;
    case (undefined *)0x4:
      DAT_1000c2cc = 0x204;
      break;
    case (undefined *)0x5:
      DAT_1000c2cc = 0x205;
      break;
    case (undefined *)0x6:
      DAT_1000c2cc = 0x206;
      break;
    case (undefined *)0x7:
      DAT_1000c2cc = 0x207;
      break;
    default:
      goto switchD_100054f0_default;
    }
    (*DAT_1000c050)(DAT_1000c2cc,2,0xff);
    pcVar5 = DAT_1000c274;
    break;
  case 0x34:
    switch(param_3) {
    case (undefined *)0x0:
      DAT_1000c010 = 0x1e00;
      break;
    case (undefined *)0x1:
      DAT_1000c010 = 0;
      break;
    case (undefined *)0x2:
      DAT_1000c010 = 0x1e01;
      break;
    case (undefined *)0x3:
      DAT_1000c010 = 0x1e02;
      break;
    case (undefined *)0x4:
      DAT_1000c010 = 0x1e03;
      break;
    case (undefined *)0x5:
      DAT_1000c010 = 0x150a;
      break;
    case (undefined *)0x6:
      DAT_1000c010 = 0x8507;
      break;
    case (undefined *)0x7:
      DAT_1000c010 = 0x8508;
      break;
    default:
      goto switchD_100054f0_default;
    }
    (*DAT_1000c044)(DAT_1000c010,DAT_1000c008,DAT_1000c000);
    pcVar5 = DAT_1000c274;
    break;
  case 0x35:
    switch(param_3) {
    case (undefined *)0x0:
      DAT_1000c008 = 0x1e00;
      break;
    case (undefined *)0x1:
      DAT_1000c008 = 0;
      break;
    case (undefined *)0x2:
      DAT_1000c008 = 0x1e01;
      break;
    case (undefined *)0x3:
      DAT_1000c008 = 0x1e02;
      break;
    case (undefined *)0x4:
      DAT_1000c008 = 0x1e03;
      break;
    case (undefined *)0x5:
      DAT_1000c008 = 0x150a;
      break;
    case (undefined *)0x6:
      DAT_1000c008 = 0x8507;
      break;
    case (undefined *)0x7:
      DAT_1000c008 = 0x8508;
      break;
    default:
      goto switchD_100054f0_default;
    }
    (*DAT_1000c044)(DAT_1000c010,DAT_1000c008,DAT_1000c000);
    pcVar5 = DAT_1000c274;
    break;
  case 0x36:
    switch(param_3) {
    case (undefined *)0x0:
      DAT_1000c000 = 0x1e00;
      break;
    case (undefined *)0x1:
      DAT_1000c000 = 0;
      break;
    case (undefined *)0x2:
      DAT_1000c000 = 0x1e01;
      break;
    case (undefined *)0x3:
      DAT_1000c000 = 0x1e02;
      break;
    case (undefined *)0x4:
      DAT_1000c000 = 0x1e03;
      break;
    case (undefined *)0x5:
      DAT_1000c000 = 0x150a;
      break;
    case (undefined *)0x6:
      DAT_1000c000 = 0x8507;
      break;
    case (undefined *)0x7:
      DAT_1000c000 = 0x8508;
      break;
    default:
      goto switchD_100054f0_default;
    }
    (*DAT_1000c044)(DAT_1000c010,DAT_1000c008,DAT_1000c000);
    pcVar5 = DAT_1000c274;
    break;
  case 0x38:
  case 0x68:
    switch(param_3) {
    case (undefined *)0x0:
      uVar24 = 0x302;
      DAT_1000c20c = 0x302;
      DAT_1000c2b0 = 0x303;
      iVar19 = FUN_10009a20(0x194);
      if (-1 < iVar19) {
        *(undefined4 *)(&DAT_1002bc40 + (uVar25 * 0x8c + iVar19) * 4) = 2;
      }
      goto LAB_100060d2;
    case (undefined *)0x1:
      uVar24 = 0x302;
      uVar20 = 1;
      DAT_1000c20c = 0x302;
      DAT_1000c2b0 = 1;
      iVar19 = FUN_10009a20(0x194);
      if (-1 < iVar19) {
        *(undefined4 *)(&DAT_1002bc40 + (uVar25 * 0x8c + iVar19) * 4) = 2;
      }
      iVar19 = FUN_10009a20(0x195);
      if (-1 < iVar19) {
        *(undefined4 *)(&DAT_1002bc40 + (uVar25 * 0x8c + iVar19) * 4) = 0;
        (*DAT_1000c0d8)(0x302,1);
        pcVar5 = DAT_1000c274;
        goto switchD_10005ce7_caseD_c;
      }
      break;
    case (undefined *)0x2:
      uVar24 = 0;
      DAT_1000c20c = 0;
      DAT_1000c2b0 = 0x303;
      iVar19 = FUN_10009a20(0x194);
      if (-1 < iVar19) {
        *(undefined4 *)(&DAT_1002bc40 + (uVar25 * 0x8c + iVar19) * 4) = 1;
      }
LAB_100060d2:
      uVar20 = 0x303;
      iVar19 = FUN_10009a20(0x195);
      if (-1 < iVar19) {
        *(undefined4 *)(&DAT_1002bc40 + (uVar25 * 0x8c + iVar19) * 4) = 3;
        (*DAT_1000c0d8)(uVar24,0x303);
        pcVar5 = DAT_1000c274;
        goto switchD_10005ce7_caseD_c;
      }
      break;
    case (undefined *)0x3:
      iVar19 = FUN_10009a20(0x194);
      if (-1 < iVar19) {
        *(undefined4 *)(&DAT_1002bc40 + (uVar25 * 0x8c + iVar19) * 4) = 7;
      }
      iVar19 = FUN_10009a20(0x195);
      if (-1 < iVar19) {
        *(undefined4 *)(&DAT_1002bc40 + (uVar25 * 0x8c + iVar19) * 4) = 1;
      }
      uVar24 = 0x306;
      uVar20 = 0;
      DAT_1000c20c = 0x306;
      DAT_1000c2b0 = 0;
      break;
    default:
      goto switchD_100054f0_default;
    }
    (*DAT_1000c0d8)(uVar24,uVar20);
    pcVar5 = DAT_1000c274;
    break;
  case 0x39:
  case 0x6a:
    (*DAT_1000c130)();
    pcVar5 = DAT_1000c274;
    break;
  case 0x3b:
    DAT_1000c1fc = (code *)param_3;
    break;
  case 0x40:
    (*DAT_1000c0ac)(DAT_1000c1d8,DAT_1000c2c8);
    pcVar5 = DAT_1000c274;
    break;
  case 0x41:
    if (param_3 == (undefined *)0x0) goto LAB_10005e0a;
    if (param_3 != (undefined *)0x1) {
      if (param_3 != (undefined *)0x2) {
        return 0;
      }
      DAT_1000c2f0 = 0x8370;
      break;
    }
LAB_10005df1:
    DAT_1000c2f0 = 0x2901;
    break;
  case 0x42:
    if (param_3 == (undefined *)0x0) {
      DAT_1000c208 = 0x812f;
    }
    else if (param_3 == (undefined *)0x1) {
      DAT_1000c208 = 0x2901;
    }
    else {
      if (param_3 != (undefined *)0x2) {
        return 0;
      }
      DAT_1000c208 = 0x8370;
    }
    break;
  case 0x43:
    (*DAT_1000c144)((double)(float)param_3);
    pcVar5 = DAT_1000c274;
  }
switchD_10005ce7_caseD_c:
  DAT_1000c274 = pcVar5;
  if (local_74 != (int *)0x0) {
    *local_74 = (int)param_3;
  }
  if (DAT_1002ba98 != (code *)0x0) {
    (*DAT_1002ba98)(iVar6,param_3);
  }
  return 1;
}



/* VA 10006d40 */

undefined4 * _THRASH_talloc_20(uint param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  uint _Size;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 uVar7;
  char local_1a4 [400];
  char local_14 [16];

                    /* 0x6d40  35  _THRASH_talloc@20 */
  if ((param_5 & 0xffff0000) == 0) {
    if (*(int *)(DAT_1002bbd0 + param_3 * 4) == 0) {
      sprintf(local_14,"Bad color format: %d",param_3);
      if (DAT_1002ba88 != (code *)0x0) {
        uVar7 = 0x98;
LAB_10006ddb:
        pcVar6 = local_14;
        goto LAB_10006de4;
      }
    }
    else if ((((param_3 == 1) || (param_3 == 2)) && (*(int *)(DAT_1002bbd8 + param_4 * 4) == 0)) &&
            (sprintf(local_14,"Bad color index format: %d",param_4), DAT_1002ba88 != (code *)0x0)) {
      uVar7 = 0x9e;
      goto LAB_10006ddb;
    }
  }
  else {
    if (DAT_1002ba88 == (code *)0x0) goto LAB_10006e09;
    uVar7 = 0x93;
    pcVar6 = "Multitexturing required";
LAB_10006de4:
    sprintf(local_1a4,"%s:\n%s\n\n\nFILE %s\nLINE %d","Allocate",pcVar6,
            "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Texture.cpp",uVar7);
    (*DAT_1002ba88)(0,local_1a4);
  }
LAB_10006e09:
  if (DAT_1002ba90 == (code *)0x0) {
    puVar1 = malloc(0x50);
  }
  else {
    puVar1 = (undefined4 *)(*DAT_1002ba90)();
  }
  if (puVar1 == (undefined4 *)0x0) {
    if (DAT_1002ba88 != (code *)0x0) {
      sprintf(local_1a4,"%s:\n%s\n\n\nFILE %s\nLINE %d","Allocate","Out of memory.",
              "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Texture.cpp",399);
      (*DAT_1002ba88)(0,local_1a4);
    }
    return (undefined4 *)0x0;
  }
  (*DAT_1000c098)(1,puVar1);
  puVar1[1] = param_1;
  puVar1[2] = param_2;
  puVar1[3] = param_5 >> 0x10;
  puVar1[0x13] = DAT_1000d2c4;
  uVar2 = param_1 * param_2;
  puVar1[4] = param_5 & 0xffff;
  puVar1[5] = param_3;
  puVar1[6] = param_4;
  param_5 = (param_5 & 0xffff) + 1;
  _Size = 0;
  puVar1[0x12] = 0;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0;
  puVar1[0x10] = 0;
  do {
    _Size = _Size + uVar2;
    uVar2 = uVar2 >> 2;
    param_5 = param_5 - 1;
  } while (param_5 != 0);
  DAT_1000d2c4 = puVar1;
  puVar1[0xc] = _Size;
  switch(param_3) {
  case 1:
    if (param_4 == 3) {
      puVar1[9] = 0x1401;
      _Size = _Size >> 1;
      puVar1[0x12] = 1;
      if (DAT_1000c188 == 0) {
        puVar1[7] = 0x1907;
        puVar1[8] = 0x8051;
        puVar1[10] = 3;
      }
      else {
LAB_10006f2f:
        puVar1[7] = 0x80e1;
        puVar1[8] = 0x8058;
        puVar1[10] = 4;
      }
    }
    else {
      if (param_4 != 4) {
        if (DAT_1002ba88 == (code *)0x0) break;
        param_3 = 0xe1;
        pcVar6 = "Indexed - Bad pixel format";
        goto LAB_1000717a;
      }
      _Size = _Size >> 1;
      puVar1[7] = 0x1908;
      puVar1[8] = 0x8058;
      puVar1[9] = 0x1401;
      puVar1[10] = 4;
      puVar1[0x12] = 1;
    }
LAB_10006f5b:
    if (DAT_1002ba90 != (code *)0x0) {
      uVar7 = (*DAT_1002ba90)();
      puVar1[0xe] = uVar7;
      break;
    }
    goto LAB_10006f6f;
  case 2:
    if (param_4 != 3) {
      if (param_4 == 4) {
        puVar1[7] = 0x80e1;
        puVar1[8] = 0x8058;
        puVar1[9] = 0x1401;
        puVar1[10] = 4;
        puVar1[0x12] = 1;
        goto LAB_10006f5b;
      }
      if (DAT_1002ba88 == (code *)0x0) break;
      param_3 = 0x10a;
      pcVar6 = "Indexed - Bad pixel format";
      goto LAB_1000717a;
    }
    puVar1[9] = 0x1401;
    puVar1[0x12] = 1;
    if (DAT_1000c188 != 0) goto LAB_10006f2f;
    puVar1[7] = 0x80e0;
    puVar1[8] = 0x8051;
    puVar1[10] = 3;
    if (DAT_1002ba90 != (code *)0x0) {
      uVar7 = (*DAT_1002ba90)();
      puVar1[0xe] = uVar7;
      break;
    }
LAB_10006f6f:
    pvVar3 = malloc(_Size);
    puVar1[0xe] = pvVar3;
    break;
  case 3:
    if (DAT_1000c188 == 0) {
      uVar7 = 0x8366;
      uVar5 = 0x8057;
LAB_10007056:
      puVar1[7] = 0x80e1;
      puVar1[8] = uVar5;
      puVar1[9] = uVar7;
      puVar1[10] = 2;
      break;
    }
    goto LAB_10007020;
  case 4:
    if (DAT_1000c188 == 0) {
      puVar1[7] = 0x1907;
      puVar1[8] = 0x1907;
      puVar1[9] = 0x8363;
      puVar1[10] = 2;
    }
    else {
      puVar1[0xb] = 0;
      puVar1[0x12] = 1;
      puVar1[7] = 0x1908;
      puVar1[8] = 0x8058;
      puVar1[9] = 0x1401;
      puVar1[10] = 4;
    }
    break;
  case 5:
    if (DAT_1000c188 == 0) {
      uVar7 = 3;
      uVar5 = 0x8051;
      uVar4 = 0x80e0;
    }
    else {
      puVar1[0x12] = 1;
      uVar7 = 4;
      uVar5 = 0x8058;
      uVar4 = 0x1908;
    }
    puVar1[7] = uVar4;
    puVar1[8] = uVar5;
    puVar1[9] = 0x1401;
    puVar1[10] = uVar7;
    break;
  case 6:
    if (DAT_1000c188 == 0) {
      uVar7 = 0x80e1;
    }
    else {
      puVar1[0x12] = 1;
      uVar7 = 0x1908;
    }
    puVar1[7] = uVar7;
    puVar1[8] = 0x8058;
    puVar1[9] = 0x1401;
    puVar1[10] = 4;
    break;
  case 7:
    if (DAT_1000c188 == 0) {
      uVar7 = 0x8365;
      uVar5 = 0x8056;
      goto LAB_10007056;
    }
LAB_10007020:
    puVar1[0x12] = 1;
    puVar1[7] = 0x1908;
    puVar1[8] = 0x8058;
    puVar1[9] = 0x1401;
    puVar1[10] = 4;
    break;
  default:
    if (DAT_1002ba88 == (code *)0x0) break;
    pcVar6 = "Bad pixel format";
LAB_1000717a:
    sprintf(local_1a4,"%s:\n%s\n\n\nFILE %s\nLINE %d","Allocate",pcVar6,
            "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Texture.cpp",param_3);
    (*DAT_1002ba88)(0,local_1a4);
  }
  FUN_10008a60();
  if ((DAT_1000d2c4 == (undefined4 *)0x0) || (puVar1 < (undefined4 *)0x10)) {
    DAT_1000d2c0 = (undefined4 *)0x0;
  }
  else if (DAT_1000d2c0 != puVar1) {
    DAT_1000d2c0 = puVar1;
    (*DAT_1000c084)(0xde1,*puVar1);
  }
  (*DAT_1000c064)(0xde1,0x813c,0);
  (*DAT_1000c064)(0xde1,0x813d,puVar1[4]);
  uVar2 = 0;
  do {
    (*DAT_1000c0b8)(0xde1,uVar2,puVar1[8],param_1,param_2,0,puVar1[7],puVar1[9],0);
    uVar2 = uVar2 + 1;
    param_2 = param_2 >> 1;
    param_1 = param_1 >> 1;
  } while (uVar2 <= (uint)puVar1[4]);
  return puVar1;
}



/* VA 100072a0 */

undefined4 * _THRASH_tupdate_12(undefined4 *param_1,ushort *param_2,undefined4 *param_3)

{
  byte bVar1;
  ushort uVar2;
  ushort *puVar3;
  bool bVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  uint *puVar13;
  uint uVar14;
  undefined1 *puVar15;
  char local_194 [400];

                    /* 0x72a0  38  _THRASH_tupdate@12 */
  iVar12 = DAT_1000d2bc;
  if (param_3 != (undefined4 *)0x0) {
    iVar12 = 1;
    DAT_1000d2bc = 1;
    puVar11 = &DAT_1002c2d0;
    for (iVar10 = 0x100; iVar10 != 0; iVar10 = iVar10 + -1) {
      *puVar11 = *param_3;
      param_3 = param_3 + 1;
      puVar11 = puVar11 + 1;
    }
  }
  if (param_2 == (ushort *)0x0) {
    return param_1;
  }
  switch(param_1[5]) {
  case 1:
    if (param_1[6] == 3) {
      puVar3 = (ushort *)param_1[0xe];
      if (DAT_1000c188 == 0) {
        if (param_2 != puVar3) {
          memcpy(puVar3,param_2,(uint)param_1[0xc] >> 1);
        }
        if (iVar12 == 0) goto LAB_1000747a;
        FUN_10009ac0((int)param_1);
        bVar4 = true;
        iVar12 = param_1[0xc];
        puVar7 = (undefined1 *)param_1[0xf];
        pbVar6 = (byte *)param_1[0xe];
        do {
          pbVar5 = pbVar6 + 1;
          if (bVar4) {
            pbVar5 = pbVar6;
          }
          bVar4 = (bool)(bVar4 ^ 1);
          iVar10 = (uint)*pbVar5 * 3;
          *puVar7 = *(undefined1 *)((int)&DAT_1002c2d0 + iVar10 + 2);
          puVar7[1] = *(undefined1 *)((int)&DAT_1002c2d0 + iVar10 + 1);
          puVar7[2] = *(undefined1 *)((int)&DAT_1002c2d0 + iVar10);
          iVar12 = iVar12 + -1;
          puVar7 = puVar7 + 3;
          pbVar6 = pbVar5;
        } while (iVar12 != 0);
      }
      else {
        if (param_2 != puVar3) {
          memcpy(puVar3,param_2,(uint)param_1[0xc] >> 1);
        }
        if (iVar12 == 0) {
LAB_1000747a:
          bVar4 = false;
          goto LAB_1000792f;
        }
        FUN_10009ac0((int)param_1);
        bVar4 = true;
        iVar12 = param_1[0xc];
        puVar7 = (undefined1 *)param_1[0xf];
        pbVar6 = (byte *)param_1[0xe];
        do {
          pbVar5 = pbVar6 + 1;
          if (bVar4) {
            pbVar5 = pbVar6;
          }
          bVar4 = (bool)(bVar4 ^ 1);
          iVar10 = (uint)*pbVar5 * 3;
          *puVar7 = *(undefined1 *)((int)&DAT_1002c2d0 + iVar10 + 2);
          puVar7[1] = *(undefined1 *)((int)&DAT_1002c2d0 + iVar10 + 1);
          puVar7[2] = *(undefined1 *)((int)&DAT_1002c2d0 + iVar10);
          puVar7[3] = 0xff;
          iVar12 = iVar12 + -1;
          puVar7 = puVar7 + 4;
          pbVar6 = pbVar5;
        } while (iVar12 != 0);
      }
LAB_10007927:
      param_2 = (ushort *)param_1[0xf];
    }
    else if (param_1[6] == 4) {
      if (param_2 != (ushort *)param_1[0xe]) {
        memcpy((ushort *)param_1[0xe],param_2,(uint)param_1[0xc] >> 1);
      }
      if (iVar12 == 0) goto LAB_1000747a;
      FUN_10009ac0((int)param_1);
      bVar4 = true;
      pbVar6 = (byte *)param_1[0xe];
      param_3 = (undefined4 *)param_1[0xc];
      puVar8 = (uint *)param_1[0xf];
      do {
        bVar1 = *pbVar6;
        uVar9 = bVar1 & 0xf;
        if (!bVar4) {
          pbVar6 = pbVar6 + 1;
          uVar9 = (uint)(bVar1 >> 4);
        }
        bVar4 = (bool)(bVar4 ^ 1);
        uVar9 = (&DAT_1002c2d0)[uVar9];
        param_3 = (undefined4 *)((int)param_3 + -1);
        *puVar8 = uVar9 >> 0x10 & 0xff | (uVar9 & 0xff) << 0x10 | uVar9 & 0xff00ff00;
        puVar8 = puVar8 + 1;
      } while (param_3 != (undefined4 *)0x0);
      goto LAB_10007927;
    }
    break;
  case 2:
    if (param_1[6] == 3) {
      puVar3 = (ushort *)param_1[0xe];
      if (DAT_1000c188 == 0) {
        if (param_2 != puVar3) {
          memcpy(puVar3,param_2,param_1[0xc]);
        }
        if (iVar12 == 0) goto LAB_1000747a;
        FUN_10009ac0((int)param_1);
        pbVar6 = (byte *)param_1[0xe];
        iVar12 = param_1[0xc];
        puVar7 = (undefined1 *)param_1[0xf];
        do {
          bVar1 = *pbVar6;
          pbVar6 = pbVar6 + 1;
          iVar10 = (uint)bVar1 * 3;
          *puVar7 = *(undefined1 *)((int)&DAT_1002c2d0 + iVar10 + 2);
          puVar7[1] = *(undefined1 *)((int)&DAT_1002c2d0 + iVar10 + 1);
          puVar7[2] = *(undefined1 *)((int)&DAT_1002c2d0 + iVar10);
          iVar12 = iVar12 + -1;
          puVar7 = puVar7 + 3;
        } while (iVar12 != 0);
      }
      else {
        if (param_2 != puVar3) {
          memcpy(puVar3,param_2,param_1[0xc]);
        }
        if (iVar12 == 0) goto LAB_1000747a;
        FUN_10009ac0((int)param_1);
        pbVar6 = (byte *)param_1[0xe];
        iVar12 = param_1[0xc];
        puVar7 = (undefined1 *)param_1[0xf];
        do {
          bVar1 = *pbVar6;
          pbVar6 = pbVar6 + 1;
          iVar10 = (uint)bVar1 * 3;
          *puVar7 = *(undefined1 *)((int)&DAT_1002c2d0 + iVar10 + 2);
          puVar7[1] = *(undefined1 *)((int)&DAT_1002c2d0 + iVar10 + 1);
          puVar7[2] = *(undefined1 *)((int)&DAT_1002c2d0 + iVar10);
          puVar7[3] = 0xff;
          iVar12 = iVar12 + -1;
          puVar7 = puVar7 + 4;
        } while (iVar12 != 0);
      }
      goto LAB_10007927;
    }
    if (param_1[6] == 4) {
      if (param_2 != (ushort *)param_1[0xe]) {
        memcpy((ushort *)param_1[0xe],param_2,param_1[0xc]);
      }
      if (iVar12 == 0) goto LAB_1000747a;
      FUN_10009ac0((int)param_1);
      pbVar6 = (byte *)param_1[0xe];
      iVar12 = param_1[0xc];
      puVar11 = (undefined4 *)param_1[0xf];
      do {
        bVar1 = *pbVar6;
        pbVar6 = pbVar6 + 1;
        *puVar11 = (&DAT_1002c2d0)[bVar1];
        iVar12 = iVar12 + -1;
        puVar11 = puVar11 + 1;
      } while (iVar12 != 0);
      goto LAB_10007927;
    }
    break;
  case 3:
    if (param_1[0x12] != 0) {
      pbVar6 = (byte *)param_1[0xf];
      if (pbVar6 == (byte *)0x0) {
        if (DAT_1002ba90 == (code *)0x0) {
          pbVar6 = malloc(param_1[0xc] * param_1[10]);
        }
        else {
          pbVar6 = (byte *)(*DAT_1002ba90)();
        }
        param_1[0xf] = pbVar6;
        if ((pbVar6 == (byte *)0x0) && (DAT_1002ba88 != (code *)0x0)) {
          sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d","Prepare","Out of memory.",
                  "D:\\Work\\Tharsh\\Thrash.Core\\Texture.cpp",0x26);
          (*DAT_1002ba88)(0,local_194);
          pbVar6 = (byte *)param_1[0xf];
        }
      }
      iVar12 = param_1[0xc];
      do {
        *pbVar6 = (byte)(*param_2 >> 7) & 0xf8;
        pbVar6[1] = (byte)(*param_2 >> 2) & 0xf8;
        pbVar6[2] = (char)*param_2 << 3;
        pbVar6[3] = *(char *)((int)param_2 + 1) >> 7;
        iVar12 = iVar12 + -1;
        pbVar6 = pbVar6 + 4;
        param_2 = param_2 + 1;
      } while (iVar12 != 0);
      goto LAB_10007927;
    }
    break;
  case 4:
    if (param_1[0x12] != 0) {
      pbVar6 = (byte *)param_1[0xf];
      if (pbVar6 == (byte *)0x0) {
        if (DAT_1002ba90 == (code *)0x0) {
          pbVar6 = malloc(param_1[0xc] * param_1[10]);
        }
        else {
          pbVar6 = (byte *)(*DAT_1002ba90)();
        }
        param_1[0xf] = pbVar6;
        if ((pbVar6 == (byte *)0x0) && (DAT_1002ba88 != (code *)0x0)) {
          sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d","Prepare","Out of memory.",
                  "D:\\Work\\Tharsh\\Thrash.Core\\Texture.cpp",0x26);
          (*DAT_1002ba88)(0,local_194);
          pbVar6 = (byte *)param_1[0xf];
        }
      }
      iVar12 = param_1[0xc];
      do {
        *pbVar6 = *(byte *)((int)param_2 + 1) & 0xf8;
        pbVar6[1] = (byte)(*param_2 >> 3) & 0xf0;
        pbVar6[2] = (char)*param_2 << 3;
        pbVar6[3] = 0xff;
        iVar12 = iVar12 + -1;
        pbVar6 = pbVar6 + 4;
        param_2 = param_2 + 1;
      } while (iVar12 != 0);
      goto LAB_10007927;
    }
    break;
  case 5:
    if (DAT_1000c188 != 0) {
      puVar7 = (undefined1 *)param_1[0xf];
      if (puVar7 == (undefined1 *)0x0) {
        if (DAT_1002ba90 == (code *)0x0) {
          puVar7 = malloc(param_1[0xc] * param_1[10]);
        }
        else {
          puVar7 = (undefined1 *)(*DAT_1002ba90)();
        }
        param_1[0xf] = puVar7;
        if ((puVar7 == (undefined1 *)0x0) && (DAT_1002ba88 != (code *)0x0)) {
          sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d","Prepare","Out of memory.",
                  "D:\\Work\\Tharsh\\Thrash.Core\\Texture.cpp",0x26);
          (*DAT_1002ba88)(0,local_194);
          puVar7 = (undefined1 *)param_1[0xf];
        }
      }
      iVar12 = param_1[0xc];
      puVar15 = (undefined1 *)((int)param_2 + 1);
      do {
        *puVar7 = puVar15[1];
        puVar7[1] = *puVar15;
        puVar7[2] = puVar15[-1];
        puVar7[3] = 0xff;
        iVar12 = iVar12 + -1;
        puVar7 = puVar7 + 4;
        puVar15 = puVar15 + 3;
      } while (iVar12 != 0);
      goto LAB_10007927;
    }
    break;
  case 6:
    if (param_1[0x12] != 0) {
      puVar8 = (uint *)param_1[0xf];
      if (puVar8 == (uint *)0x0) {
        if (DAT_1002ba90 == (code *)0x0) {
          puVar8 = malloc(param_1[0xc] * param_1[10]);
        }
        else {
          puVar8 = (uint *)(*DAT_1002ba90)();
        }
        param_1[0xf] = puVar8;
        if ((puVar8 == (uint *)0x0) && (DAT_1002ba88 != (code *)0x0)) {
          sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d","Prepare","Out of memory.",
                  "D:\\Work\\Tharsh\\Thrash.Core\\Texture.cpp",0x26);
          (*DAT_1002ba88)(0,local_194);
          puVar8 = (uint *)param_1[0xf];
        }
      }
      iVar12 = param_1[0xc];
      puVar13 = puVar8;
      do {
        uVar9 = *(uint *)(((int)param_2 - (int)puVar8) + (int)puVar13);
        *puVar13 = uVar9 >> 0x10 & 0xff | (uVar9 & 0xff) << 0x10 | uVar9 & 0xff00ff00;
        iVar12 = iVar12 + -1;
        puVar13 = puVar13 + 1;
      } while (iVar12 != 0);
      goto LAB_10007927;
    }
    break;
  case 7:
    if (param_1[0x12] != 0) {
      puVar8 = (uint *)param_1[0xf];
      if (puVar8 == (uint *)0x0) {
        if (DAT_1002ba90 == (code *)0x0) {
          puVar8 = malloc(param_1[0xc] * param_1[10]);
        }
        else {
          puVar8 = (uint *)(*DAT_1002ba90)();
        }
        param_1[0xf] = puVar8;
        if ((puVar8 == (uint *)0x0) && (DAT_1002ba88 != (code *)0x0)) {
          sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d","Prepare","Out of memory.",
                  "D:\\Work\\Tharsh\\Thrash.Core\\Texture.cpp",0x26);
          (*DAT_1002ba88)(0,local_194);
          puVar8 = (uint *)param_1[0xf];
        }
      }
      iVar12 = param_1[0xc];
      do {
        uVar2 = *param_2;
        uVar9 = (uint)uVar2;
        param_2 = param_2 + 1;
        *puVar8 = (((uVar9 & 0xf) << 4 | uVar9 & 0xfffff000) << 8 | uVar9 & 0xf0) << 8 |
                  uVar2 >> 4 & 0xf0;
        iVar12 = iVar12 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar12 != 0);
      goto LAB_10007927;
    }
  }
  bVar4 = true;
LAB_1000792f:
  FUN_10008a60();
  if ((DAT_1000d2c4 == 0) || (param_1 < (undefined4 *)0x10)) {
    DAT_1000d2c0 = (undefined4 *)0x0;
  }
  else if (DAT_1000d2c0 != param_1) {
    DAT_1000d2c0 = param_1;
    (*DAT_1000c084)(0xde1,*param_1);
  }
  if (bVar4) {
    uVar9 = param_1[2];
    uVar14 = param_1[1];
    param_3 = (undefined4 *)0x0;
    do {
      (*DAT_1000c0c4)(0xde1,param_3,0,0,uVar14,uVar9,param_1[7],param_1[9],param_2);
      iVar12 = uVar9 * uVar14;
      uVar9 = uVar9 >> 1;
      uVar14 = uVar14 >> 1;
      param_2 = (ushort *)((int)param_2 + iVar12 * param_1[10]);
      param_3 = (undefined4 *)((int)param_3 + 1);
    } while (param_3 <= (undefined4 *)param_1[4]);
  }
  return param_1;
}



/* VA 100079f0 */

void _THRASH_settexture_4(undefined *param_1)

{
                    /* 0x79f0  32  _THRASH_settexture@4 */
  FUN_10005450(1,0,param_1);
  return;
}



/* VA 10007a10 */

undefined4 _THRASH_tfree_4(int param_1)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  void *_Memory;

                    /* 0x7a10  36  _THRASH_tfree@4 */
  if (DAT_1000d2c4 != 0) {
    if (DAT_1000d2c0 == param_1) {
      FUN_10005450(1,0,(undefined *)0x0);
    }
    iVar2 = DAT_1000d2c4;
    if (DAT_1000d2c4 == param_1) {
      DAT_1000d2c4 = *(int *)(param_1 + 0x4c);
      (*DAT_1000c090)(1,param_1);
      pcVar3 = free_exref;
      _Memory = *(void **)(param_1 + 0x38);
      if (_Memory != (void *)0x0) {
        if (DAT_1002ba94 == (code *)0x0) {
LAB_10007ab0:
          pcVar3 = free_exref;
          free(_Memory);
        }
        else {
          (*DAT_1002ba94)();
        }
      }
LAB_10007ab5:
      if (*(int *)(param_1 + 0x3c) != 0) {
        if (DAT_1002ba94 == (code *)0x0) {
          (*pcVar3)(*(int *)(param_1 + 0x3c));
        }
        else {
          (*DAT_1002ba94)();
        }
      }
      if (*(int *)(param_1 + 0x40) != 0) {
        if (DAT_1002ba94 == (code *)0x0) {
          (*pcVar3)(*(int *)(param_1 + 0x40));
        }
        else {
          (*DAT_1002ba94)();
        }
      }
      if (DAT_1002ba94 != (code *)0x0) {
        (*DAT_1002ba94)();
        return 1;
      }
      (*pcVar3)(param_1);
      return 1;
    }
    do {
      piVar1 = (int *)(iVar2 + 0x4c);
      iVar2 = *piVar1;
      if (iVar2 == param_1) {
        *piVar1 = *(int *)(param_1 + 0x4c);
        (*DAT_1000c090)(1,param_1);
        pcVar3 = free_exref;
        _Memory = *(void **)(param_1 + 0x38);
        if (_Memory == (void *)0x0) goto LAB_10007ab5;
        if (DAT_1002ba94 == (code *)0x0) goto LAB_10007ab0;
        (*DAT_1002ba94)();
        goto LAB_10007ab5;
      }
    } while (iVar2 != 0);
  }
  return 0;
}



/* VA 10007b20 */

undefined4 _THRASH_treset_0(void)

{
  void *pvVar1;
  void *_Memory;

                    /* 0x7b20  37  _THRASH_treset@0 */
  if (DAT_1000d2c4 != 0) {
    FUN_10005450(1,0,(undefined *)0x0);
    _Memory = (void *)DAT_1000d2c4;
    do {
      pvVar1 = *(void **)((int)_Memory + 0x4c);
      (*DAT_1000c090)(1,_Memory);
      if (*(void **)((int)_Memory + 0x38) != (void *)0x0) {
        if (DAT_1002ba94 == (code *)0x0) {
          free(*(void **)((int)_Memory + 0x38));
        }
        else {
          (*DAT_1002ba94)();
        }
      }
      if (*(void **)((int)_Memory + 0x3c) != (void *)0x0) {
        if (DAT_1002ba94 == (code *)0x0) {
          free(*(void **)((int)_Memory + 0x3c));
        }
        else {
          (*DAT_1002ba94)();
        }
      }
      if (*(void **)((int)_Memory + 0x40) != (void *)0x0) {
        if (DAT_1002ba94 == (code *)0x0) {
          free(*(void **)((int)_Memory + 0x40));
        }
        else {
          (*DAT_1002ba94)();
        }
      }
      if (DAT_1002ba94 == (code *)0x0) {
        free(_Memory);
      }
      else {
        (*DAT_1002ba94)();
      }
      _Memory = pvVar1;
    } while (pvVar1 != (void *)0x0);
    DAT_1000d2c4 = 0;
  }
  return 1;
}



/* VA 10007be0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_10007be0(undefined4 *param_1)

{
  double dVar1;
  float fVar2;
  uint uVar3;
  void *_Memory;
  int iVar4;
  undefined4 uVar5;
  int unaff_EBX;
  undefined4 uVar6;
  undefined4 *puVar7;
  void *unaff_EDI;
  double dVar8;
  uint uVar9;
  int iStack_74;
  uint uStack_70;
  int iStack_6c;
  int local_64;
  int local_48;

  uVar9 = param_1[3];
  uVar3 = (uint)param_1[1] / uVar9;
  if (uVar3 == 3) {
    uVar6 = 0x80e0;
  }
  else {
    if (uVar3 != 4) {
      uVar6 = 0x1907;
      uVar5 = 0x8363;
      goto LAB_10007c25;
    }
    uVar6 = 0x80e1;
  }
  uVar5 = 0x1401;
LAB_10007c25:
  if ((DAT_1000c27c == *DAT_1000d2a4) && (DAT_1000c280 == DAT_1000d2a4[1])) {
    (*DAT_1000c0e4)(0,0,uVar9,param_1[4],uVar6,uVar5,*param_1);
  }
  else {
    fVar2 = (float)(int)uVar9;
    if ((int)uVar9 < 0) {
      fVar2 = fVar2 + _DAT_1000b000;
    }
    dVar1 = (double)(fVar2 * _DAT_1000c2a4);
    dVar8 = floor((double)(fVar2 * _DAT_1000c2a4));
    if (dVar8 + _DAT_1000afe0 <= dVar1) {
      dVar8 = ceil(dVar1);
    }
    local_48 = (int)(longlong)ROUND(dVar8);
    iVar4 = local_48;
    fVar2 = (float)(int)param_1[4];
    if ((int)param_1[4] < 0) {
      fVar2 = fVar2 + _DAT_1000b000;
    }
    dVar1 = (double)(fVar2 * _DAT_1000c2a8);
    dVar8 = floor((double)(fVar2 * _DAT_1000c2a8));
    if (dVar8 + _DAT_1000afe0 <= dVar1) {
      dVar8 = ceil(dVar1);
    }
    local_48 = (int)(longlong)ROUND(dVar8);
    if (DAT_1002ba90 == (code *)0x0) {
      _Memory = malloc(local_48 * iVar4 * uVar3);
    }
    else {
      _Memory = (void *)(*DAT_1002ba90)();
    }
    (*DAT_1000c0e4)(0,0,iVar4,local_48,uVar6);
    puVar7 = (undefined4 *)*param_1;
    if (iStack_74 == 4) {
      uStack_70 = 0;
      if (param_1[4] != 0) {
        uVar9 = param_1[3];
        do {
          fVar2 = (float)(int)uStack_70;
          if ((int)uStack_70 < 0) {
            fVar2 = fVar2 + _DAT_1000b000;
          }
          dVar1 = (double)(fVar2 * _DAT_1000c2a8);
          dVar8 = floor((double)(fVar2 * _DAT_1000c2a8));
          if (dVar8 + _DAT_1000afe0 <= dVar1) {
            dVar8 = ceil(dVar1);
          }
          uVar3 = 0;
          local_64 = (int)(longlong)ROUND(dVar8);
          if (uVar9 != 0) {
            do {
              fVar2 = (float)(int)uVar3;
              if ((int)uVar3 < 0) {
                fVar2 = fVar2 + _DAT_1000b000;
              }
              dVar1 = (double)(fVar2 * _DAT_1000c2a4);
              dVar8 = floor((double)(fVar2 * _DAT_1000c2a4));
              if (dVar8 + _DAT_1000afe0 <= dVar1) {
                dVar8 = ceil(dVar1);
              }
              uVar3 = uVar3 + 1;
              iStack_6c = (int)(longlong)ROUND(dVar8);
              *puVar7 = *(undefined4 *)((int)unaff_EDI + (iStack_6c + local_64 * unaff_EBX) * 4);
              puVar7 = puVar7 + 1;
              uVar9 = param_1[3];
            } while (uVar3 < uVar9);
          }
          uStack_70 = uStack_70 + 1;
          _Memory = unaff_EDI;
        } while (uStack_70 < (uint)param_1[4]);
      }
    }
    else {
      uVar9 = 0;
      if (param_1[4] != 0) {
        uStack_70 = param_1[3];
        do {
          fVar2 = (float)(int)uVar9;
          if ((int)uVar9 < 0) {
            fVar2 = fVar2 + _DAT_1000b000;
          }
          dVar1 = (double)(fVar2 * _DAT_1000c2a8);
          dVar8 = floor((double)(fVar2 * _DAT_1000c2a8));
          if (dVar8 + _DAT_1000afe0 <= dVar1) {
            dVar8 = ceil(dVar1);
          }
          uVar3 = 0;
          local_64 = (int)(longlong)ROUND(dVar8);
          iVar4 = local_64 * unaff_EBX;
          if (uStack_70 != 0) {
            do {
              fVar2 = (float)(int)uVar3;
              if ((int)uVar3 < 0) {
                fVar2 = fVar2 + _DAT_1000b000;
              }
              dVar1 = (double)(fVar2 * _DAT_1000c2a4);
              dVar8 = floor((double)(fVar2 * _DAT_1000c2a4));
              if (dVar8 + _DAT_1000afe0 <= dVar1) {
                dVar8 = ceil(dVar1);
              }
              uVar3 = uVar3 + 1;
              local_64 = (int)(longlong)ROUND(dVar8);
              *(undefined2 *)puVar7 = *(undefined2 *)((int)unaff_EDI + (local_64 + iVar4) * 2);
              puVar7 = (undefined4 *)((int)puVar7 + 2);
              uStack_70 = param_1[3];
            } while (uVar3 < uStack_70);
          }
          uVar9 = uVar9 + 1;
          _Memory = unaff_EDI;
        } while (uVar9 < (uint)param_1[4]);
      }
    }
    if (DAT_1002ba94 == (code *)0x0) {
      free(_Memory);
    }
    else {
      (*DAT_1002ba94)();
    }
  }
  FUN_10003720(param_1[3],param_1[4],(undefined4 *)*param_1,iStack_74);
  return;
}



/* VA 10008090 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_10008090(int *param_1)

{
  float fVar1;
  uint uVar2;
  undefined4 *puVar3;
  size_t _Size;
  ushort *_Dst;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  float *pfVar10;
  void *_Src;
  float *pfVar11;
  ushort *_Dst_00;
  bool bVar12;
  undefined4 uVar13;
  uint uStack_264;
  uint uStack_25c;
  uint uStack_258;
  undefined *puStack_248;
  undefined *puStack_244;
  undefined *puStack_240;
  undefined *puStack_23c;
  undefined *puStack_238;
  undefined *puStack_234;
  undefined *puStack_230;
  undefined *puStack_22c;
  float afStack_218 [6];
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  float afStack_1f8 [6];
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  float afStack_1d8 [6];
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  float afStack_1b8 [6];
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  char local_198 [404];

  uVar2 = (uint)param_1[1] / (uint)param_1[3];
  if (uVar2 == 3) {
    iVar5 = 5;
  }
  else if (uVar2 == 4) {
    iVar5 = 6;
  }
  else {
    iVar5 = 4;
  }
  puVar3 = _THRASH_talloc_20(DAT_1002bbb4,DAT_1002bbc0,iVar5,0,0);
  if (puVar3 == (undefined4 *)0x0) {
    if (DAT_1002ba88 == (code *)0x0) {
      return;
    }
    uVar13 = 0xe8;
  }
  else {
    iVar5 = uVar2 * DAT_1002bbb4;
    _Size = iVar5 * DAT_1002bbc0;
    if (DAT_1002ba90 == (code *)0x0) {
      _Dst = malloc(_Size);
    }
    else {
      _Dst = (ushort *)(*DAT_1002ba90)();
    }
    if (_Dst != (ushort *)0x0) {
      puStack_248 = (undefined *)FUN_10009a20(1);
      if (-1 < (int)puStack_248) {
        puStack_248 = *(undefined **)(&DAT_1002bc40 + (int)puStack_248 * 4);
      }
      puStack_244 = (undefined *)FUN_10009a20(6);
      if (-1 < (int)puStack_244) {
        puStack_244 = *(undefined **)(&DAT_1002bc40 + (int)puStack_244 * 4);
      }
      puStack_240 = (undefined *)FUN_10009a20(0x2a);
      if (-1 < (int)puStack_240) {
        puStack_240 = *(undefined **)(&DAT_1002bc40 + (int)puStack_240 * 4);
      }
      puStack_23c = (undefined *)FUN_10009a20(2);
      if (-1 < (int)puStack_23c) {
        puStack_23c = *(undefined **)(&DAT_1002bc40 + (int)puStack_23c * 4);
      }
      puStack_238 = (undefined *)FUN_10009a20(0xd);
      if (-1 < (int)puStack_238) {
        puStack_238 = *(undefined **)(&DAT_1002bc40 + (int)puStack_238 * 4);
      }
      puStack_234 = (undefined *)FUN_10009a20(0xb);
      if (-1 < (int)puStack_234) {
        puStack_234 = *(undefined **)(&DAT_1002bc40 + (int)puStack_234 * 4);
      }
      puStack_230 = (undefined *)FUN_10009a20(10);
      if (-1 < (int)puStack_230) {
        puStack_230 = *(undefined **)(&DAT_1002bc40 + (int)puStack_230 * 4);
      }
      puStack_22c = (undefined *)FUN_10009a20(4);
      if (-1 < (int)puStack_22c) {
        puStack_22c = *(undefined **)(&DAT_1002bc40 + (int)puStack_22c * 4);
      }
      FUN_10005450(1,0,(undefined *)puVar3);
      FUN_10005450(6,0,(undefined *)0x0);
      FUN_10005450(0x2a,0,(undefined *)0x0);
      FUN_10005450(2,0,(undefined *)0x0);
      FUN_10005450(0xd,0,(undefined *)0x0);
      FUN_10005450(0xb,0,(undefined *)0x0);
      FUN_10005450(10,0,(undefined *)0x0);
      FUN_10005450(4,0,(undefined *)0x0);
      afStack_218[4] = -NAN;
      afStack_218[2] = 0.0;
      afStack_218[3] = 1.0;
      uStack_200 = 0;
      uStack_1fc = 0;
      pfVar10 = afStack_218;
      pfVar11 = afStack_1d8;
      for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
        *pfVar11 = *pfVar10;
        pfVar10 = pfVar10 + 1;
        pfVar11 = pfVar11 + 1;
      }
      uStack_1c0 = 0x3f800000;
      uStack_1bc = 0;
      pfVar10 = afStack_218;
      pfVar11 = afStack_1f8;
      for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
        *pfVar11 = *pfVar10;
        pfVar10 = pfVar10 + 1;
        pfVar11 = pfVar11 + 1;
      }
      uStack_1e0 = 0x3f800000;
      uStack_1dc = 0x3f800000;
      pfVar10 = afStack_218;
      pfVar11 = afStack_1b8;
      for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
        *pfVar11 = *pfVar10;
        pfVar10 = pfVar10 + 1;
        pfVar11 = pfVar11 + 1;
      }
      uStack_1a0 = 0;
      uStack_19c = 0x3f800000;
      uStack_25c = 0;
      uVar7 = param_1[4];
      uVar4 = DAT_1002bbc0;
      if (uVar7 != 0) {
        do {
          uVar9 = param_1[3];
          uVar8 = uVar7 - uStack_25c;
          if (uVar4 < uVar7 - uStack_25c) {
            uVar8 = uVar4;
          }
          uStack_258 = 0;
          if (uVar9 != 0) {
            fVar1 = (float)(int)uStack_25c;
            if ((int)uStack_25c < 0) {
              fVar1 = fVar1 + _DAT_1000b000;
            }
            do {
              uVar9 = uVar9 - uStack_258;
              bVar12 = uVar9 == DAT_1002bbb4;
              if (DAT_1002bbb4 < uVar9) {
                bVar12 = uVar8 == DAT_1002bbc0;
                uVar9 = DAT_1002bbb4;
              }
              if (!bVar12) {
                memset(_Dst,0,_Size);
              }
              _Src = (void *)(param_1[1] * uStack_25c + uStack_258 * uVar2 + *param_1);
              if (uVar8 != 0) {
                _Dst_00 = _Dst;
                uStack_264 = uVar8;
                do {
                  memcpy(_Dst_00,_Src,uVar9 * uVar2);
                  _Dst_00 = (ushort *)((int)_Dst_00 + iVar5);
                  _Src = (void *)((int)_Src + param_1[1]);
                  uStack_264 = uStack_264 - 1;
                } while (uStack_264 != 0);
              }
              _THRASH_tupdate_12(puVar3,_Dst,(undefined4 *)0x0);
              afStack_218[0] = (float)(int)uStack_258;
              if ((int)uStack_258 < 0) {
                afStack_218[0] = afStack_218[0] + _DAT_1000b000;
              }
              afStack_1f8[0] = (float)(int)(DAT_1002bbb4 + uStack_258);
              if ((int)(DAT_1002bbb4 + uStack_258) < 0) {
                afStack_1f8[0] = afStack_1f8[0] + _DAT_1000b000;
              }
              afStack_1f8[1] = (float)(int)(DAT_1002bbc0 + uStack_25c);
              if ((int)(DAT_1002bbc0 + uStack_25c) < 0) {
                afStack_1f8[1] = afStack_1f8[1] + _DAT_1000b000;
              }
              afStack_218[1] = fVar1;
              afStack_1d8[0] = afStack_1f8[0];
              afStack_1d8[1] = fVar1;
              afStack_1b8[0] = afStack_218[0];
              afStack_1b8[1] = afStack_1f8[1];
              FUN_10008cb0(afStack_218,afStack_1d8,afStack_1f8);
              FUN_10008cb0(afStack_1f8,afStack_1b8,afStack_218);
              uStack_258 = uStack_258 + DAT_1002bbb4;
              uVar9 = param_1[3];
              uVar4 = DAT_1002bbc0;
            } while (uStack_258 < uVar9);
          }
          uVar7 = param_1[4];
          uStack_25c = uStack_25c + uVar4;
        } while (uStack_25c < uVar7);
      }
      FUN_10008a60();
      (*DAT_1000c068)();
      FUN_10005450(1,0,puStack_248);
      FUN_10005450(6,0,puStack_244);
      FUN_10005450(0x2a,0,puStack_240);
      FUN_10005450(2,0,puStack_23c);
      FUN_10005450(0xd,0,puStack_238);
      FUN_10005450(0xb,0,puStack_234);
      FUN_10005450(10,0,puStack_230);
      FUN_10005450(4,0,puStack_22c);
      if (DAT_1002ba94 != (code *)0x0) {
        (*DAT_1002ba94)();
        _THRASH_tfree_4((int)puStack_22c);
        return;
      }
      free(_Dst);
      _THRASH_tfree_4((int)puVar3);
      return;
    }
    _THRASH_tfree_4((int)puVar3);
    if (DAT_1002ba88 == (code *)0x0) {
      return;
    }
    uVar13 = 0xe4;
  }
  sprintf(local_198,"%s:\n%s\n\n\nFILE %s\nLINE %d","Write","Out of memory.",
          "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Window.cpp",uVar13);
  (*DAT_1002ba88)(0,local_198);
  return;
}



/* VA 10008650 */

void _THRASH_clearwindow_0(void)

{
  uint uVar1;

                    /* 0x8650  2  _THRASH_clearwindow@0 */
  uVar1 = 0;
  if (DAT_1000c200 != 0) {
    uVar1 = 0x100;
  }
  if (DAT_1000c1f4 != 0) {
    uVar1 = uVar1 | 0x400;
  }
  if (DAT_1000c2bc != 0) {
    uVar1 = uVar1 | 0x4000;
  }
  (*DAT_1000c0e0)(uVar1);
  return;
}



/* VA 10008690 */

void _THRASH_flushwindow_0(void)

{
                    /* 0x8690  21  _THRASH_flushwindow@0 */
  FUN_10008a60();
                    /* WARNING: Could not recover jumptable at 0x10008695. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_1000c068)();
  return;
}



/* VA 100086a0 */

undefined4 _THRASH_window_4(undefined *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;

                    /* 0x86a0  40  _THRASH_window@4 */
  if (DAT_1000c278 != 0) {
    DAT_1000c278 = 0;
    (*DAT_1000c118)(DAT_1000c284,DAT_1000c288,DAT_1000c28c,DAT_1000c290);
    uVar4 = DAT_1000c2ec;
    uVar3 = DAT_1000c2e8;
    iVar2 = DAT_1000c2e4;
    uVar1 = DAT_1000c2e0;
    DAT_1000c2e0 = 0;
    DAT_1000c2e4 = 0;
    DAT_1000c2e8 = 0;
    DAT_1000c2ec = 0;
    _THRASH_clip_16(uVar1,iVar2,uVar3,uVar4);
  }
  FUN_10005450(0x3b,0,param_1);
  switch(param_1) {
  case (undefined *)0x0:
  case (undefined *)0x1:
    uVar5 = 0x404;
    DAT_1000c2bc = 1;
    goto LAB_1000877f;
  case (undefined *)0x2:
    DAT_1000c2bc = 1;
    break;
  case (undefined *)0x3:
    if (0 < DAT_1000c0d0) {
      uVar5 = 0x409;
      DAT_1000c2bc = 1;
      goto LAB_1000877f;
    }
    DAT_1000c2bc = 0;
    break;
  default:
    return 0;
  }
  uVar5 = 0x405;
LAB_1000877f:
  (*DAT_1000c040)(uVar5);
  (*DAT_1000c08c)(uVar5);
  return 1;
}



/* VA 100087c0 */

undefined4 * _THRASH_lockwindow_0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  bool bVar7;
  undefined4 uVar8;
  char local_194 [400];

                    /* 0x87c0  26  _THRASH_lockwindow@0 */
  if ((DAT_1000c1f8 != 0) && (DAT_1002ba88 != (code *)0x0)) {
    sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d",&DAT_1000adc8,"Lock called while locked",
            "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Window.cpp",0x138);
    (*DAT_1002ba88)(0,local_194);
  }
  DAT_1000c1f8 = 1;
  if (DAT_1002ba84 != (code *)0x0) {
    (*DAT_1002ba84)(1);
  }
  if (DAT_1002ba90 == (code *)0x0) {
    puVar3 = malloc(0x1c);
  }
  else {
    puVar3 = (undefined4 *)(*DAT_1002ba90)();
  }
  piVar2 = DAT_1000d2a4;
  if (puVar3 == (undefined4 *)0x0) {
    if (DAT_1002ba88 == (code *)0x0) {
      return (undefined4 *)0x0;
    }
    uVar8 = 0x169;
  }
  else {
    bVar7 = DAT_1000c184 == 0;
    iVar4 = *DAT_1000d2a4;
    puVar3[3] = iVar4;
    iVar1 = piVar2[1];
    puVar3[4] = iVar1;
    if (bVar7) {
      uVar6 = (uint)piVar2[2] >> 3;
    }
    else {
      uVar6 = 2;
    }
    iVar4 = iVar4 * uVar6;
    puVar3[1] = iVar4;
    if (DAT_1002ba90 == (code *)0x0) {
      pvVar5 = malloc(iVar4 * iVar1);
    }
    else {
      pvVar5 = (void *)(*DAT_1002ba90)();
    }
    if (pvVar5 != (void *)0x0) {
      bVar7 = DAT_1000c184 == 0;
      *puVar3 = pvVar5;
      puVar3[5] = DAT_1000c1fc;
      puVar3[6] = 1;
      if (bVar7) {
        if (DAT_1000d2a4[2] == 0x18) {
          puVar3[2] = 5;
        }
        else {
          puVar3[2] = (uint)(DAT_1000d2a4[2] == 0x20) * 2 + 4;
        }
      }
      else {
        puVar3[2] = 4;
      }
      FUN_10007be0(puVar3);
      FUN_10005450(0x1d,0,(undefined *)puVar3);
      return puVar3;
    }
    if (DAT_1002ba88 == (code *)0x0) {
      return puVar3;
    }
    uVar8 = 0x166;
  }
  sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d",&DAT_1000adc8,"Out of memory.",
          "D:\\Work\\Tharsh\\Thrash.OpenGL.3\\Window.cpp",uVar8);
  (*DAT_1002ba88)(0,local_194);
  return puVar3;
}



/* VA 10008960 */

undefined4 _THRASH_unlockwindow_4(int *param_1)

{
                    /* 0x8960  39  _THRASH_unlockwindow@4 */
  if (DAT_1000c1f8 != 0) {
    FUN_10008090(param_1);
    DAT_1000c1f8 = 0;
    if (DAT_1002ba84 != (code *)0x0) {
      (*DAT_1002ba84)(0);
    }
  }
  return 1;
}



/* VA 100089a0 */

void FUN_100089a0(void)

{
  (*DAT_1000c0c0)(0x8892,0x400000,0,0x88e0);
  (*DAT_1000c0ec)(DAT_1000c1e4);
  (*DAT_1000c0c8)(DAT_1000c1e4,4,0x1406,0,0x20,0);
  (*DAT_1000c0ec)(DAT_1000c1d0);
  (*DAT_1000c0c8)(DAT_1000c1d0,4,0x1401,1,0x20,0x10);
  (*DAT_1000c0ec)(DAT_1000c1b8);
  (*DAT_1000c0c8)(DAT_1000c1b8,4,0x1401,1,0x20,0x14);
  (*DAT_1000c0ec)(DAT_1000c1dc);
  (*DAT_1000c0c8)(DAT_1000c1dc,2,0x1406,0,0x20,0x18);
  DAT_1000d2d4 = 0;
  return;
}



/* VA 10008a60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10008a60(void)

{
  void *_Dst;
  undefined4 uVar1;
  size_t _Size;

  if ((DAT_1000d2d0 != 0) && (DAT_1000d2d8 != 0)) {
    if ((DAT_1000c2b4 != 0) && (DAT_1000d2c0 != 0)) {
      (*DAT_1000c064)(0xde1,0x2802,DAT_1000c2f0);
      (*DAT_1000c064)(0xde1,0x2803,DAT_1000c208);
      (*DAT_1000c088)(0xde1,0x8501,_DAT_1000c2ac);
      if (DAT_1000c17c == 1) {
        (*DAT_1000c064)(0xde1,0x2800,0x2601);
        if ((DAT_1000c2d8 == 0) || (uVar1 = 0x2703, *(int *)(DAT_1000d2c0 + 0x10) == 0)) {
          uVar1 = 0x2601;
        }
      }
      else if (DAT_1000c17c == 2) {
        (*DAT_1000c064)(0xde1,0x2800,0x2600);
        if ((DAT_1000c2d8 == 0) || (uVar1 = 0x2700, *(int *)(DAT_1000d2c0 + 0x10) == 0)) {
          uVar1 = 0x2600;
        }
      }
      else if (DAT_1000c2dc == 0) {
        (*DAT_1000c064)(0xde1,0x2800,0x2600);
        if (DAT_1000c2d8 == 0) {
          uVar1 = 0x2600;
        }
        else {
          uVar1 = 0x2600;
          if (DAT_1000c2d8 == 1) {
            if (*(int *)(DAT_1000d2c0 + 0x10) != 0) {
              uVar1 = 0x2700;
            }
          }
          else if (*(int *)(DAT_1000d2c0 + 0x10) != 0) {
            uVar1 = 0x2702;
          }
        }
      }
      else {
        (*DAT_1000c064)(0xde1,0x2800,0x2601);
        if (DAT_1000c2d8 == 0) {
          uVar1 = 0x2601;
        }
        else {
          uVar1 = 0x2601;
          if (DAT_1000c2d8 == 1) {
            if (*(int *)(DAT_1000d2c0 + 0x10) != 0) {
              uVar1 = 0x2701;
            }
          }
          else if (*(int *)(DAT_1000d2c0 + 0x10) != 0) {
            uVar1 = 0x2703;
          }
        }
      }
      (*DAT_1000c064)(0xde1,0x2801,uVar1);
    }
    _Size = DAT_1000d2d8 * 0x20;
    if (0x400000 < DAT_1000d2d4 + _Size) {
      FUN_100089a0();
    }
    _Dst = (void *)(*DAT_1000c0a0)(0x8892,DAT_1000d2d4,_Size,0x22);
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,DAT_1000d2dc,_Size);
    }
    (*DAT_1000c10c)(0x8892);
    (*DAT_1000c0a8)(DAT_1000d2d0,DAT_1000d2d4 >> 5,DAT_1000d2d8);
    DAT_1000d2d4 = DAT_1000d2d4 + _Size;
    DAT_1000d2d8 = 0;
    DAT_1000d2d0 = 0;
  }
  return;
}



/* VA 10008cb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_10008cb0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  bool bVar5;
  bool bVar6;

  if (DAT_1000c274 != 0) {
    fVar1 = (*param_2 - *param_1) * (param_3[1] - param_1[1]) -
            (param_2[1] - param_1[1]) * (*param_3 - *param_1);
    if (DAT_1000c274 == 1) {
      bVar6 = fVar1 == _DAT_1000afbc;
      bVar5 = fVar1 < _DAT_1000afbc;
    }
    else {
      bVar6 = fVar1 == 0.0;
      bVar5 = 0.0 < fVar1;
    }
    if (bVar5 || bVar6) {
      return;
    }
  }
  if ((DAT_1000d2d0 != 4) || (DAT_1000d2d8 == 0xf3c)) {
    FUN_10008a60();
    DAT_1000d2d0 = 4;
  }
  fVar1 = _DAT_1000c2d0;
  pfVar2 = (float *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
  pfVar4 = pfVar2;
  DAT_1000d2d8 = DAT_1000d2d8 + 1;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar4 = *param_1;
    param_1 = param_1 + 1;
    pfVar4 = pfVar4 + 1;
  }
  pfVar2[2] = pfVar2[2] + fVar1;
  iVar3 = DAT_1000d2d8 * 0x20;
  DAT_1000d2d8 = DAT_1000d2d8 + 1;
  pfVar2 = (float *)(iVar3 + DAT_1000d2dc);
  pfVar4 = pfVar2;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar4 = *param_2;
    param_2 = param_2 + 1;
    pfVar4 = pfVar4 + 1;
  }
  pfVar2[2] = pfVar2[2] + fVar1;
  pfVar2 = (float *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
  DAT_1000d2d8 = DAT_1000d2d8 + 1;
  pfVar4 = pfVar2;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar4 = *param_3;
    param_3 = param_3 + 1;
    pfVar4 = pfVar4 + 1;
  }
  pfVar2[2] = fVar1 + pfVar2[2];
  return;
}



/* VA 10008dc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _THRASH_drawline_8(undefined4 *param_1,undefined4 *param_2)

{
  float fVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;

                    /* 0x8dc0  4  _THRASH_drawline@8 */
  if ((DAT_1000d2d0 != 1) || (DAT_1000d2d8 == 0xf3c)) {
    FUN_10008a60();
    DAT_1000d2d0 = 1;
  }
  fVar1 = _DAT_1000c2d0;
  puVar2 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
  puVar4 = puVar2;
  DAT_1000d2d8 = DAT_1000d2d8 + 1;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_1;
    param_1 = param_1 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar2[2] = (float)puVar2[2] + fVar1;
  puVar2 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
  DAT_1000d2d8 = DAT_1000d2d8 + 1;
  puVar4 = puVar2;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_2;
    param_2 = param_2 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar2[2] = fVar1 + (float)puVar2[2];
  return;
}



/* VA 10008e50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _THRASH_drawlinestrip_8(int param_1,undefined4 *param_2)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;

                    /* 0x8e50  7  _THRASH_drawlinestrip@8 */
  if (param_1 != 0) {
    if ((DAT_1000d2d0 != 1) || (DAT_1000d2d8 == 0xf3c)) {
      FUN_10008a60();
      DAT_1000d2d0 = 1;
    }
    fVar1 = _DAT_1000c2d0;
    iVar2 = DAT_1000d2d8 * 0x20;
    DAT_1000d2d8 = DAT_1000d2d8 + 1;
    puVar3 = (undefined4 *)(iVar2 + DAT_1000d2dc);
    puVar5 = param_2;
    puVar6 = puVar3;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar3[2] = (float)puVar3[2] + fVar1;
    puVar3 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
    puVar5 = param_2 + 8;
    puVar6 = puVar3;
    DAT_1000d2d8 = DAT_1000d2d8 + 1;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    puVar3[2] = fVar1 + (float)puVar3[2];
    puVar5 = param_2 + 8;
    while (param_1 = param_1 + -1, param_1 != 0) {
      if ((DAT_1000d2d0 != 1) || (DAT_1000d2d8 == 0xf3c)) {
        FUN_10008a60();
        DAT_1000d2d0 = 1;
        fVar1 = _DAT_1000c2d0;
      }
      iVar2 = DAT_1000d2d8 * 0x20;
      DAT_1000d2d8 = DAT_1000d2d8 + 1;
      puVar4 = (undefined4 *)(iVar2 + DAT_1000d2dc);
      puVar6 = puVar5;
      puVar3 = puVar4;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar4[2] = (float)puVar4[2] + fVar1;
      puVar4 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
      puVar6 = puVar5 + 8;
      puVar3 = puVar4;
      DAT_1000d2d8 = DAT_1000d2d8 + 1;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar4[2] = fVar1 + (float)puVar4[2];
      puVar5 = puVar5 + 8;
    }
  }
  return;
}



/* VA 10008fa0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _THRASH_drawlinestrip_12(int param_1,int param_2,int *param_3)

{
  float fVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;

                    /* 0x8fa0  6  _THRASH_drawlinestrip@12 */
  if (param_1 != 0) {
    iVar5 = *param_3;
    piVar2 = param_3 + 2;
    puVar6 = (undefined4 *)(param_3[1] * 0x20 + param_2);
    if ((DAT_1000d2d0 != 1) || (DAT_1000d2d8 == 0xf3c)) {
      FUN_10008a60();
      DAT_1000d2d0 = 1;
    }
    fVar1 = _DAT_1000c2d0;
    puVar3 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
    puVar7 = (undefined4 *)(iVar5 * 0x20 + param_2);
    puVar8 = puVar3;
    DAT_1000d2d8 = DAT_1000d2d8 + 1;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    puVar3[2] = (float)puVar3[2] + fVar1;
    iVar5 = DAT_1000d2d8 * 0x20;
    DAT_1000d2d8 = DAT_1000d2d8 + 1;
    puVar3 = (undefined4 *)(iVar5 + DAT_1000d2dc);
    puVar7 = puVar6;
    puVar8 = puVar3;
    for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    puVar3[2] = fVar1 + (float)puVar3[2];
    while (param_1 = param_1 + -1, param_1 != 0) {
      iVar5 = *piVar2;
      piVar2 = piVar2 + 1;
      puVar7 = (undefined4 *)(iVar5 * 0x20 + param_2);
      if ((DAT_1000d2d0 != 1) || (DAT_1000d2d8 == 0xf3c)) {
        FUN_10008a60();
        DAT_1000d2d0 = 1;
        fVar1 = _DAT_1000c2d0;
      }
      puVar3 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
      puVar8 = puVar3;
      DAT_1000d2d8 = DAT_1000d2d8 + 1;
      for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
      puVar3[2] = (float)puVar3[2] + fVar1;
      iVar5 = DAT_1000d2d8 * 0x20;
      DAT_1000d2d8 = DAT_1000d2d8 + 1;
      puVar3 = (undefined4 *)(iVar5 + DAT_1000d2dc);
      puVar6 = puVar7;
      puVar8 = puVar3;
      for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
      puVar3[2] = fVar1 + (float)puVar3[2];
      puVar6 = puVar7;
    }
  }
  return;
}



/* VA 10009100 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _THRASH_drawlinemesh_12(int param_1,int param_2,int *param_3)

{
  int iVar1;
  float fVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;

  while (param_1 != 0) {
    iVar5 = *param_3;
    iVar1 = param_3[1];
    if ((DAT_1000d2d0 != 1) || (DAT_1000d2d8 == 0xf3c)) {
      FUN_10008a60();
      DAT_1000d2d0 = 1;
    }
    fVar2 = _DAT_1000c2d0;
    puVar3 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
    puVar6 = (undefined4 *)(iVar5 * 0x20 + param_2);
    puVar7 = puVar3;
    DAT_1000d2d8 = DAT_1000d2d8 + 1;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    puVar3[2] = (float)puVar3[2] + fVar2;
    iVar5 = DAT_1000d2d8 * 0x20;
    DAT_1000d2d8 = DAT_1000d2d8 + 1;
    puVar3 = (undefined4 *)(iVar5 + DAT_1000d2dc);
    param_1 = param_1 + -1;
    puVar6 = (undefined4 *)(iVar1 * 0x20 + param_2);
    puVar7 = puVar3;
    for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    puVar3[2] = fVar2 + (float)puVar3[2];
    param_3 = param_3 + 2;
  }
  return;
}



/* VA 100091c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _THRASH_drawpoint_4(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;

                    /* 0x91c0  8  _THRASH_drawpoint@4 */
  if ((DAT_1000d2d0 != 0) || (DAT_1000d2d8 == 0xf3c)) {
    FUN_10008a60();
    DAT_1000d2d0 = 0;
  }
  puVar1 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
  DAT_1000d2d8 = DAT_1000d2d8 + 1;
  puVar3 = puVar1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_1;
    param_1 = param_1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1[2] = (float)puVar1[2] + _DAT_1000c2d0;
  return;
}



/* VA 10009230 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _THRASH_drawpointstrip_8(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;

  while (param_1 != 0) {
    if ((DAT_1000d2d0 != 0) || (DAT_1000d2d8 == 0xf3c)) {
      FUN_10008a60();
      DAT_1000d2d0 = 0;
    }
    puVar1 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
    param_1 = param_1 + -1;
    puVar3 = param_2;
    puVar4 = puVar1;
    DAT_1000d2d8 = DAT_1000d2d8 + 1;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar1[2] = (float)puVar1[2] + _DAT_1000c2d0;
    param_2 = param_2 + 8;
  }
  return;
}



/* VA 100092b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _THRASH_drawpointmesh_12(int param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;

  while (param_1 != 0) {
    iVar1 = *param_3;
    param_3 = param_3 + 1;
    if ((DAT_1000d2d0 != 0) || (DAT_1000d2d8 == 0xf3c)) {
      FUN_10008a60();
      DAT_1000d2d0 = 0;
    }
    puVar2 = (undefined4 *)(DAT_1000d2d8 * 0x20 + DAT_1000d2dc);
    param_1 = param_1 + -1;
    puVar4 = (undefined4 *)(iVar1 * 0x20 + param_2);
    puVar5 = puVar2;
    DAT_1000d2d8 = DAT_1000d2d8 + 1;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar2[2] = (float)puVar2[2] + _DAT_1000c2d0;
  }
  return;
}



/* VA 10009330 */

void _THRASH_drawquad_16(float *param_1,float *param_2,float *param_3,float *param_4)

{
                    /* 0x9330  11  _THRASH_drawquad@16 */
  FUN_10008cb0(param_1,param_2,param_3);
  FUN_10008cb0(param_3,param_4,param_1);
  return;
}



/* VA 10009360 */

void _THRASH_drawquadmesh_12(int param_1,int param_2,int *param_3)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;

  for (; param_1 != 0; param_1 = param_1 + -1) {
    iVar1 = param_3[3];
    pfVar2 = (float *)(*param_3 * 0x20 + param_2);
    pfVar3 = (float *)(param_3[2] * 0x20 + param_2);
    FUN_10008cb0(pfVar2,(float *)(param_3[1] * 0x20 + param_2),pfVar3);
    FUN_10008cb0(pfVar3,(float *)(iVar1 * 0x20 + param_2),pfVar2);
    param_3 = param_3 + 4;
  }
  return;
}



/* VA 100093c0 */

void _THRASH_drawsprite_8(float *param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float local_28 [6];
  float local_10;

                    /* 0x93c0  13  _THRASH_drawsprite@8 */
  fVar1 = *param_2;
  pfVar3 = param_1;
  pfVar4 = local_28;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar4 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pfVar4 = pfVar4 + 1;
  }
  local_10 = param_2[6];
  local_28[0] = fVar1;
  FUN_10008cb0(param_1,local_28,param_2);
  pfVar3 = param_2;
  pfVar4 = local_28;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar4 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pfVar4 = pfVar4 + 1;
  }
  local_28[0] = *param_1;
  local_10 = param_1[6];
  FUN_10008cb0(param_1,param_2,local_28);
  return;
}



/* VA 10009440 */

void _THRASH_drawspritemesh_12(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float local_28 [6];
  float local_10;

  for (; param_1 != 0; param_1 = param_1 + -1) {
    piVar1 = param_3 + 1;
    iVar4 = *param_3;
    param_3 = param_3 + 2;
    pfVar5 = (float *)(*piVar1 * 0x20 + param_2);
    pfVar3 = (float *)(iVar4 * 0x20 + param_2);
    fVar2 = *pfVar5;
    pfVar6 = pfVar3;
    pfVar7 = local_28;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pfVar7 = *pfVar6;
      pfVar6 = pfVar6 + 1;
      pfVar7 = pfVar7 + 1;
    }
    local_10 = pfVar5[6];
    local_28[0] = fVar2;
    FUN_10008cb0(pfVar3,local_28,pfVar5);
    pfVar6 = pfVar5;
    pfVar7 = local_28;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pfVar7 = *pfVar6;
      pfVar6 = pfVar6 + 1;
      pfVar7 = pfVar7 + 1;
    }
    local_28[0] = *pfVar3;
    local_10 = pfVar3[6];
    FUN_10008cb0(pfVar3,pfVar5,local_28);
  }
  return;
}



/* VA 10009500 */

void _THRASH_drawtri_12(float *param_1,float *param_2,float *param_3)

{
                    /* 0x9500  15  _THRASH_drawtri@12 */
  FUN_10008cb0(param_1,param_2,param_3);
  return;
}



/* VA 10009520 */

void _THRASH_drawtristrip_8(int param_1,float *param_2)

{
  float *pfVar1;
  bool bVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;

                    /* 0x9520  20  _THRASH_drawtristrip@8 */
  if (param_1 != 0) {
    FUN_10008cb0(param_2,param_2 + 8,param_2 + 0x10);
    bVar2 = false;
    pfVar3 = param_2 + 8;
    pfVar4 = param_2 + 0x10;
    pfVar5 = param_2 + 0x18;
    while (param_1 = param_1 + -1, param_1 != 0) {
      pfVar6 = pfVar3;
      pfVar1 = pfVar4;
      if (!bVar2) {
        pfVar6 = pfVar4;
        pfVar1 = pfVar3;
      }
      FUN_10008cb0(pfVar6,pfVar1,pfVar5);
      bVar2 = (bool)(bVar2 ^ 1);
      pfVar3 = pfVar4;
      pfVar4 = pfVar5;
      pfVar5 = pfVar5 + 8;
    }
  }
  return;
}



/* VA 100095a0 */

void _THRASH_drawtristrip_12(int param_1,int param_2,int *param_3)

{
  float *pfVar1;
  bool bVar2;
  int *piVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;

                    /* 0x95a0  19  _THRASH_drawtristrip@12 */
  if (param_1 != 0) {
    pfVar4 = (float *)(param_3[1] * 0x20 + param_2);
    pfVar6 = (float *)(param_3[2] * 0x20 + param_2);
    FUN_10008cb0((float *)(*param_3 * 0x20 + param_2),pfVar4,pfVar6);
    bVar2 = false;
    piVar3 = param_3 + 3;
    while (param_1 = param_1 + -1, param_1 != 0) {
      pfVar7 = (float *)(param_2 + *piVar3 * 0x20);
      pfVar5 = pfVar4;
      pfVar1 = pfVar6;
      if (!bVar2) {
        pfVar5 = pfVar6;
        pfVar1 = pfVar4;
      }
      FUN_10008cb0(pfVar5,pfVar1,pfVar7);
      bVar2 = (bool)(bVar2 ^ 1);
      piVar3 = piVar3 + 1;
      pfVar4 = pfVar6;
      pfVar6 = pfVar7;
    }
  }
  return;
}



/* VA 10009630 */

void _THRASH_drawtrifan_8(int param_1,float *param_2)

{
  float *pfVar1;
  float *pfVar2;

                    /* 0x9630  17  _THRASH_drawtrifan@8 */
  if (param_1 != 0) {
    FUN_10008cb0(param_2,param_2 + 8,param_2 + 0x10);
    pfVar1 = param_2 + 0x10;
    pfVar2 = param_2 + 0x18;
    while (param_1 = param_1 + -1, param_1 != 0) {
      FUN_10008cb0(param_2,pfVar1,pfVar2);
      pfVar1 = pfVar2;
      pfVar2 = pfVar2 + 8;
    }
  }
  return;
}



/* VA 10009680 */

void _THRASH_drawtrifan_12(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;

                    /* 0x9680  16  _THRASH_drawtrifan@12 */
  if (param_1 != 0) {
    pfVar2 = (float *)(*param_3 * 0x20 + param_2);
    pfVar3 = (float *)(param_3[2] * 0x20 + param_2);
    FUN_10008cb0(pfVar2,(float *)(param_3[1] * 0x20 + param_2),pfVar3);
    piVar1 = param_3 + 3;
    while (param_1 = param_1 + -1, param_1 != 0) {
      pfVar4 = (float *)(*piVar1 * 0x20 + param_2);
      FUN_10008cb0(pfVar2,pfVar3,pfVar4);
      piVar1 = piVar1 + 1;
      pfVar3 = pfVar4;
    }
  }
  return;
}



/* VA 100096f0 */

void _THRASH_drawtrimesh_12(int param_1,int param_2,int *param_3)

{
  for (; param_1 != 0; param_1 = param_1 + -1) {
    FUN_10008cb0((float *)(*param_3 * 0x20 + param_2),(float *)(param_3[1] * 0x20 + param_2),
                 (float *)(param_3[2] * 0x20 + param_2));
    param_3 = param_3 + 3;
  }
  return;
}



/* VA 10009740 */

int __cdecl FUN_10009740(undefined4 param_1)

{
  DWORD DVar1;
  int iVar2;
  char local_64 [80];
  CHAR local_14 [12];
  int local_8;

  sprintf(local_64,"%s_%s",&DAT_1000a7c0,param_1);
  DVar1 = GetPrivateProfileStringA("THRASH",local_64,(LPCSTR)0x0,local_14,0xc,(LPCSTR)&DAT_1002baa0)
  ;
  if (DVar1 == 0) {
    sprintf(local_64,"THRASH_%s",param_1);
    DVar1 = GetPrivateProfileStringA
                      ("THRASH",local_64,(LPCSTR)0x0,local_14,0xc,(LPCSTR)&DAT_1002baa0);
    if (DVar1 == 0) {
      sprintf(local_64,"%s_%s",&DAT_1000a7c0,param_1);
      DVar1 = GetEnvironmentVariableA(local_64,local_14,0xc);
      if (DVar1 == 0) {
        sprintf(local_64,"THRASH_%s",param_1);
        DVar1 = GetEnvironmentVariableA(local_64,local_14,0xc);
        if (DVar1 == 0) {
          return local_8;
        }
      }
      goto LAB_10009799;
    }
  }
  SetEnvironmentVariableA(local_64,local_14);
LAB_10009799:
  iVar2 = atoi(local_14);
  return iVar2;
}



/* VA 10009830 */

void __fastcall FUN_10009830(int *param_1)

{
  int iVar1;
  uint uVar2;

  iVar1 = FUN_10009740("signature");
  *param_1 = iVar1;
  iVar1 = FUN_10009740("version");
  param_1[2] = iVar1;
  uVar2 = FUN_10009740("linewidth");
  param_1[3] = uVar2 | param_1[3] & 0xfeU;
  iVar1 = FUN_10009740("texturesquare");
  param_1[3] = param_1[3] & 0xfdU | iVar1 * 2;
  iVar1 = FUN_10009740("texturewidthpowerof2");
  param_1[3] = param_1[3] & 0xfbU | iVar1 << 2;
  iVar1 = FUN_10009740("textureheightpowerof2");
  param_1[3] = param_1[3] & 0xf7U | iVar1 << 3;
  iVar1 = FUN_10009740("software");
  param_1[3] = param_1[3] & 0xefU | iVar1 << 4;
  iVar1 = FUN_10009740("windowed");
  param_1[3] = param_1[3] & 0xdfU | iVar1 << 5;
  iVar1 = FUN_10009740("globalclut");
  param_1[3] = param_1[3] & 0xbfU | iVar1 << 6;
  iVar1 = FUN_10009740("trilinear2pass");
  param_1[3] = param_1[3] & 0x7fU | iVar1 << 7;
  iVar1 = FUN_10009740("texturewidthmin");
  param_1[4] = iVar1;
  iVar1 = FUN_10009740("texturewidthmax");
  param_1[5] = iVar1;
  iVar1 = FUN_10009740("texturewidthmultiple");
  param_1[6] = iVar1;
  iVar1 = FUN_10009740("textureheightmin");
  param_1[7] = iVar1;
  iVar1 = FUN_10009740("textureheightmax");
  param_1[8] = iVar1;
  iVar1 = FUN_10009740("textureheightmultiple");
  param_1[9] = iVar1;
  iVar1 = FUN_10009740("clipalign");
  param_1[10] = iVar1;
  iVar1 = FUN_10009740("numstages");
  param_1[0x11] = iVar1;
  iVar1 = FUN_10009740("subtype");
  param_1[0x1b] = iVar1;
  iVar1 = FUN_10009740("textureramsize");
  param_1[0x1c] = iVar1;
  iVar1 = FUN_10009740("textureramtype");
  param_1[0x1d] = iVar1;
  iVar1 = FUN_10009740("dxversion");
  param_1[0x1f] = iVar1;
  return;
}



/* VA 10009a20 */

int __fastcall FUN_10009a20(uint param_1)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;

  iVar4 = 0;
  uVar3 = 0;
  while( true ) {
    uVar2 = (uint)uVar3;
    uVar1 = (uint)(ushort)(&DAT_1000ac44)[uVar2 * 2];
    if ((uVar1 <= param_1) && (param_1 <= (ushort)(&DAT_1000ac46)[uVar2 * 2])) break;
    uVar3 = uVar3 + 1;
    iVar4 = iVar4 + ((ushort)(&DAT_1000ac46)[uVar2 * 2] - uVar1);
    if (0xb < uVar3) {
      return -1;
    }
  }
  return param_1 + (iVar4 - uVar1);
}



/* VA 10009a70 */

void _THRASH_setstate_8(uint param_1,undefined *param_2)

{
                    /* 0x9a70  31  _THRASH_setstate@8 */
  FUN_10005450(param_1 & 0xffff,param_1 >> 0x10,param_2);
  return;
}



/* VA 10009a90 */

int _THRASH_getstate_4(uint param_1)

{
  int iVar1;

                    /* 0x9a90  22  _THRASH_getstate@4 */
  iVar1 = FUN_10009a20(param_1 & 0xffff);
  if (-1 < iVar1) {
    iVar1 = *(int *)(&DAT_1002bc40 + ((param_1 >> 0x10) * 0x8c + iVar1) * 4);
  }
  return iVar1;
}



/* VA 10009ac0 */

void __fastcall FUN_10009ac0(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  char local_194 [400];

  puVar1 = *(undefined4 **)(param_1 + 0x40);
  if (puVar1 == (undefined4 *)0x0) {
    if (DAT_1002ba90 == (code *)0x0) {
      puVar1 = malloc(0x400);
    }
    else {
      puVar1 = (undefined4 *)(*DAT_1002ba90)();
    }
    *(undefined4 **)(param_1 + 0x40) = puVar1;
    if ((puVar1 == (undefined4 *)0x0) && (DAT_1002ba88 != (code *)0x0)) {
      sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d","PrepareIndexed","Out of memory.",
              "D:\\Work\\Tharsh\\Thrash.Core\\Texture.cpp",0x2f);
      (*DAT_1002ba88)(0,local_194);
      puVar1 = *(undefined4 **)(param_1 + 0x40);
    }
  }
  puVar4 = &DAT_1002c2d0;
  for (iVar3 = 0x100; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar1 = puVar1 + 1;
  }
  pvVar2 = *(void **)(param_1 + 0x3c);
  if (pvVar2 == (void *)0x0) {
    if (DAT_1002ba90 == (code *)0x0) {
      pvVar2 = malloc(*(int *)(param_1 + 0x30) * *(int *)(param_1 + 0x28));
    }
    else {
      pvVar2 = (void *)(*DAT_1002ba90)();
    }
    *(void **)(param_1 + 0x3c) = pvVar2;
  }
  if ((pvVar2 == (void *)0x0) && (DAT_1002ba88 != (code *)0x0)) {
    sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d","Prepare","Out of memory.",
            "D:\\Work\\Tharsh\\Thrash.Core\\Texture.cpp",0x26);
    (*DAT_1002ba88)(0,local_194);
  }
  return;
}



/* VA 10009bb6 */

void _CIpow(void)

{
                    /* WARNING: Could not recover jumptable at 0x10009bb6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _CIpow();
  return;
}



/* VA 10009bbc */

double __cdecl ceil(double _X)

{
  double dVar1;

                    /* WARNING: Could not recover jumptable at 0x10009bbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar1 = ceil(_X);
  return dVar1;
}



/* VA 10009bc2 */

double __cdecl floor(double _X)

{
  double dVar1;

                    /* WARNING: Could not recover jumptable at 0x10009bc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar1 = floor(_X);
  return dVar1;
}



/* VA 10009bc8 */

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;

                    /* WARNING: Could not recover jumptable at 0x10009bc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



/* VA 10009bce */

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;

                    /* WARNING: Could not recover jumptable at 0x10009bce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



/* VA 10009be0 */

int thunk_FUN_10009bf0(void)

{
  uint uVar1;
  ushort uVar2;
  float10 in_ST0;
  undefined4 uStack_1c;
  undefined2 uStack_18;

  if (1 < DAT_1002c6d4) {
    return (int)in_ST0;
  }
  uStack_1c = (uint)((unkuint10)in_ST0 >> 0x20);
  uStack_18 = (ushort)((unkuint10)in_ST0 >> 0x40);
  uVar2 = uStack_18 & 0x7fff;
  uVar1 = -(uint)((short)uStack_18 < 0);
  if (uVar2 < 0x3fff) {
    return 0;
  }
  if ((int)uStack_1c < 0) {
    if (uVar2 < 0x401e) {
      return (uStack_1c >> (0x3eU - (char)uVar2 & 0x1f) ^ uVar1) + (uint)((short)uStack_18 < 0);
    }
    if (((uVar2 < 0x401f) && ((int)uVar1 < 0)) && (uStack_1c == 0x80000000)) {
      return -0x80000000;
    }
  }
  return -0x80000000;
}



/* VA 10009bf0 */

int FUN_10009bf0(void)

{
  uint uVar1;
  ushort uVar2;
  float10 in_ST0;
  undefined4 uStack_1c;
  undefined2 uStack_18;

  if (1 < DAT_1002c6d4) {
    return (int)in_ST0;
  }
  uStack_1c = (uint)((unkuint10)in_ST0 >> 0x20);
  uStack_18 = (ushort)((unkuint10)in_ST0 >> 0x40);
  uVar2 = uStack_18 & 0x7fff;
  uVar1 = -(uint)((short)uStack_18 < 0);
  if (uVar2 < 0x3fff) {
    return 0;
  }
  if ((int)uStack_1c < 0) {
    if (uVar2 < 0x401e) {
      return (uStack_1c >> (0x3eU - (char)uVar2 & 0x1f) ^ uVar1) + (uint)((short)uStack_18 < 0);
    }
    if (((uVar2 < 0x401f) && ((int)uVar1 < 0)) && (uStack_1c == 0x80000000)) {
      return -0x80000000;
    }
  }
  return -0x80000000;
}
