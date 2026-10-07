/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 510fc1d2af0016cb1de25bac702d79bc430945bbbd3b041f694e40330ca639ff */

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
  undefined4 uVar7;
  uint *puVar8;
  HWND hWnd;
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
  HWND local_10;
  int *local_c;
  PIXELFORMATDESCRIPTOR *local_8;

  uVar7 = 0;
  local_94.lpfnWndProc = DefWindowProcA_exref;
  local_94.hInstance = DAT_1000d868;
  local_14 = 0;
  local_94.cbClsExtra = 0;
  local_94.cbWndExtra = 0;
  local_94.hIcon = (HICON)0x0;
  local_94.hCursor = (HCURSOR)0x0;
  local_94.hbrBackground = (HBRUSH)0x0;
  local_94.lpszMenuName = (LPCSTR)0x0;
  local_94.style = 0x23;
  local_94.lpszClassName = "40bd3b41-ff62-4227-b8d5-dae24eb338b7";
  local_c = param_2;
  local_8 = param_1;
  AVar3 = RegisterClassA(&local_94);
  if (AVar3 != 0) {
    local_10 = CreateWindowExA(0x40000,"40bd3b41-ff62-4227-b8d5-dae24eb338b7","DUMMY",0x86000000,0,0
                               ,1,1,(HWND)0x0,(HMENU)0x0,DAT_1000d868,(LPVOID)0x0);
    if (local_10 != (HWND)0x0) {
      hdc = GetDC(local_10);
      ppfd = local_8;
      BVar2 = (BYTE)DAT_1000c738;
      hWnd = local_10;
      if (hdc != (HDC)0x0) {
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
        puVar8 = local_48;
        for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
          uVar1 = *puVar8;
          param_1->nSize = (short)uVar1;
          param_1->nVersion = (short)(uVar1 >> 0x10);
          puVar8 = puVar8 + 1;
          param_1 = (PIXELFORMATDESCRIPTOR *)&param_1->dwFlags;
        }
        local_8->cColorBits = BVar2;
        BVar2 = DAT_1000c73c;
        local_8->nSize = 0x28;
        local_8->nVersion = 1;
        local_8->dwFlags = 0x225;
        local_8->cDepthBits = BVar2;
        local_8->cStencilBits = '\b';
        iVar6 = ChoosePixelFormat(hdc,local_8);
        *local_c = iVar6;
        if (((iVar6 != 0) && (BVar4 = SetPixelFormat(hdc,iVar6,ppfd), BVar4 != 0)) &&
           (iVar6 = (*DAT_1000c02c)(hdc), iVar6 != 0)) {
          iVar5 = (*DAT_1000c018)(hdc,iVar6);
          if (iVar5 != 0) {
            FUN_10001680("wgl","ChoosePixelFormat",(int *)&DAT_1000c020,"ARB");
            if (DAT_1000c020 != (code *)0x0) {
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
              iVar5 = (*DAT_1000c020)(hdc,&local_6c,0,1,&local_18,&local_8);
              if ((iVar5 != 0) && (local_8 != (PIXELFORMATDESCRIPTOR *)0x0)) {
                *local_c = local_18;
              }
            }
            local_14 = 1;
            (*DAT_1000c018)(hdc,0);
          }
          (*DAT_1000c024)(iVar6);
        }
        hWnd = local_10;
        ReleaseDC(local_10,hdc);
      }
      DestroyWindow(hWnd);
      uVar7 = local_14;
    }
    UnregisterClassA("40bd3b41-ff62-4227-b8d5-dae24eb338b7",DAT_1000d868);
  }
  return uVar7;
}



/* VA 10001280 */

void FUN_10001280(void)

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

  if (DAT_1000c788 == 0) {
    if (DAT_1000d86c == (HDC)0x0) {
      DAT_1000d86c = GetDC(DAT_1000d864);
    }
    iVar2 = GetPixelFormat(DAT_1000d86c);
    if (iVar2 == 0) {
      iVar3 = FUN_10001000(&local_30,&local_8);
      iVar2 = local_8;
      if (iVar3 == 0) {
        iVar2 = ChoosePixelFormat(DAT_1000d86c,&local_30);
        local_8 = iVar2;
        if (iVar2 == 0) {
          if (DAT_1000d88c != (code *)0x0) {
            sprintf(local_37c,"%s:\n%s\n\n\nFILE %s\nLINE %d","Create","ChoosePixelFormat failed",
                    "D:\\Work\\Tharsh\\Thrash.OpenGL.1\\Context.cpp",0x94);
            (*DAT_1000d88c)(0,local_37c);
          }
        }
        else if ((((byte)local_30.dwFlags & 0x80) != 0) && (DAT_1000d88c != (code *)0x0)) {
          sprintf(local_1ec,"%s:\n%s\n\n\nFILE %s\nLINE %d","Create","Needs palette",
                  "D:\\Work\\Tharsh\\Thrash.OpenGL.1\\Context.cpp",0x96);
          (*DAT_1000d88c)(0,local_1ec);
        }
      }
      BVar4 = SetPixelFormat(DAT_1000d86c,iVar2,&local_30);
      if ((BVar4 == 0) && (DVar5 = GetLastError(), DAT_1000d88c != (code *)0x0)) {
        sprintf(local_1ec,"%s:\n%s\n\n\nFILE %s\nLINE %d","Create","SetPixelFormat failed",
                "D:\\Work\\Tharsh\\Thrash.OpenGL.1\\Context.cpp",DVar5);
        (*DAT_1000d88c)(0,local_1ec);
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
      iVar2 = DescribePixelFormat(DAT_1000d86c,iVar2,0x28,&local_30);
      if ((iVar2 == 0) && (DAT_1000d88c != (code *)0x0)) {
        sprintf(local_1ec,"%s:\n%s\n\n\nFILE %s\nLINE %d","Create","DescribePixelFormat failed",
                "D:\\Work\\Tharsh\\Thrash.OpenGL.1\\Context.cpp",0x9e);
        (*DAT_1000d88c)(0,local_1ec);
      }
      if (((((local_30.iPixelType != '\0') || (local_30.cRedBits < 5)) || (local_30.cGreenBits < 5))
          || (local_30.cBlueBits < 5)) && (DAT_1000d88c != (code *)0x0)) {
        sprintf(local_37c,"%s:\n%s\n\n\nFILE %s\nLINE %d","Create","Bad pixel type",
                "D:\\Work\\Tharsh\\Thrash.OpenGL.1\\Context.cpp",0xa1);
        (*DAT_1000d88c)(0,local_37c);
      }
    }
    DAT_1000c788 = (*DAT_1000c02c)(DAT_1000d86c);
    (*DAT_1000c018)(DAT_1000d86c,DAT_1000c788);
    FUN_10001790();
    if (DAT_1000c748 != 0) {
      if (DAT_1000c01c != (code *)0x0) {
        (*DAT_1000c01c)(1);
        return;
      }
      DAT_1000c748 = 0;
    }
  }
  return;
}



/* VA 10001510 */

void FUN_10001510(void)

{
  void *pvVar1;
  HDC hdc;
  code *pcVar2;
  void *_Memory;

  pcVar2 = ReleaseDC_exref;
  if (DAT_1000c788 != 0) {
    (*DAT_1000c028)();
    if (DAT_1000d860 != 0) {
      FUN_10005080(1,0,(float *)0x0);
      _Memory = (void *)DAT_1000d860;
      do {
        pvVar1 = *(void **)((int)_Memory + 0x4c);
        (*DAT_1000c088)(1,_Memory);
        if (*(void **)((int)_Memory + 0x38) != (void *)0x0) {
          if (DAT_1000d898 == (code *)0x0) {
            free(*(void **)((int)_Memory + 0x38));
          }
          else {
            (*DAT_1000d898)();
          }
        }
        if (*(void **)((int)_Memory + 0x3c) != (void *)0x0) {
          if (DAT_1000d898 == (code *)0x0) {
            free(*(void **)((int)_Memory + 0x3c));
          }
          else {
            (*DAT_1000d898)();
          }
        }
        if (*(void **)((int)_Memory + 0x40) != (void *)0x0) {
          if (DAT_1000d898 == (code *)0x0) {
            free(*(void **)((int)_Memory + 0x40));
          }
          else {
            (*DAT_1000d898)();
          }
        }
        if (DAT_1000d898 == (code *)0x0) {
          free(_Memory);
        }
        else {
          (*DAT_1000d898)();
        }
        _Memory = pvVar1;
      } while (pvVar1 != (void *)0x0);
      DAT_1000d860 = 0;
      pcVar2 = ReleaseDC_exref;
    }
    if (DAT_1000c12c != 0) {
      hdc = GetDC((HWND)0x0);
      SetDeviceGammaRamp(hdc,&DAT_1000c130);
      (*pcVar2)(0,hdc);
    }
    (*DAT_1000c018)(DAT_1000d86c,0);
    (*DAT_1000c024)(DAT_1000c788);
    DAT_1000c788 = 0;
  }
  if (DAT_1000d86c != 0) {
    (*pcVar2)(DAT_1000d864,DAT_1000d86c);
    DAT_1000d86c = 0;
  }
  return;
}



/* VA 10001650 */

undefined4 entry(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DAT_1000d868 = param_1;
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* VA 10001680 */

void __fastcall FUN_10001680(char *param_1,char *param_2,int *param_3,char *param_4)

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
  if (DAT_1000c0a8 != (code *)0x0) {
    iVar2 = (*DAT_1000c0a8)(local_108);
    *param_3 = iVar2;
  }
  if (*param_3 + 1U < 5) {
    if (DAT_1000c098 == (HMODULE)0x0) {
      DAT_1000c098 = GetModuleHandleA("OPENGL32.dll");
    }
    pFVar3 = GetProcAddress(DAT_1000c098,local_108);
    pcVar7 = local_8;
    *param_3 = (int)pFVar3;
    if (((pFVar3 == (FARPROC)0x0) && (param_4 == (char *)0x0)) &&
       (FUN_10001680(param_1,local_8,param_3,"EXT"), *param_3 == 0)) {
      FUN_10001680(param_1,pcVar7,param_3,"ARB");
    }
  }
  return;
}



/* VA 10001790 */

void FUN_10001790(void)

{
  char cVar1;
  int iVar2;
  DWORD DVar3;
  char *pcVar4;
  char *pcVar5;
  byte bVar6;
  uint uVar7;
  undefined4 uVar8;
  char local_1ac [400];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;

  uVar8 = DAT_1000d86c;
  FUN_10001680("wgl","CreateContextAttribs",(int *)&DAT_1000c0e4,"ARB");
  if (DAT_1000c0e4 != (code *)0x0) {
    local_1c = 0x2091;
    local_18 = 1;
    local_14 = 0x2092;
    local_10 = 4;
    local_c = 0;
    iVar2 = (*DAT_1000c0e4)(uVar8,0,&local_1c);
    if (iVar2 == 0) {
      DVar3 = GetLastError();
      if (DVar3 == 0x2095) {
        if (DAT_1000d88c != (code *)0x0) {
          uVar8 = 0x9c;
          pcVar4 = "Invalid ARB version";
LAB_1000185e:
          sprintf(local_1ac,"%s:\n%s\n\n\nFILE %s\nLINE %d","CreateContextAttribs",pcVar4,
                  "D:\\Work\\Tharsh\\Thrash.OpenGL.1\\GL.cpp",uVar8);
          (*DAT_1000d88c)(0,local_1ac);
        }
      }
      else if ((DVar3 == 0x2096) && (DAT_1000d88c != (code *)0x0)) {
        uVar8 = 0x9e;
        pcVar4 = "Invalid ARB profile";
        goto LAB_1000185e;
      }
    }
    else {
      (*DAT_1000c018)(uVar8,iVar2);
      (*DAT_1000c024)(DAT_1000c788);
      DAT_1000c788 = iVar2;
    }
  }
  FUN_10001680("wgl","GetExtensionsString",(int *)&DAT_1000c05c,"EXT");
  if (DAT_1000c05c != (code *)0x0) {
    pcVar4 = (char *)(*DAT_1000c05c)();
    pcVar4 = strstr(pcVar4,"WGL_EXT_swap_control");
    if (pcVar4 != (char *)0x0) {
      FUN_10001680("wgl","SwapInterval",&DAT_1000c01c,"EXT");
    }
  }
  FUN_10001680("gl","GetString",(int *)&DAT_1000c0dc,(char *)0x0);
  FUN_10001680("gl","Color4ubv",&DAT_1000c114,(char *)0x0);
  FUN_10001680("gl","SecondaryColor3ubv",&DAT_1000c070,(char *)0x0);
  FUN_10001680("gl","TexCoord2f",(int *)&DAT_1000c080,(char *)0x0);
  FUN_10001680("gl","TexCoord4f",&DAT_1000c0e0,(char *)0x0);
  FUN_10001680("gl","Vertex2f",&DAT_1000c03c,(char *)0x0);
  FUN_10001680("gl","Vertex3f",&DAT_1000c09c,(char *)0x0);
  FUN_10001680("gl","Begin",&DAT_1000c120,(char *)0x0);
  FUN_10001680("gl","End",&DAT_1000c10c,(char *)0x0);
  FUN_10001680("gl","Scissor",&DAT_1000c110,(char *)0x0);
  FUN_10001680("gl","Viewport",&DAT_1000c0f8,(char *)0x0);
  FUN_10001680("gl","Hint",&DAT_1000c128,(char *)0x0);
  FUN_10001680("gl","MatrixMode",&DAT_1000c038,(char *)0x0);
  FUN_10001680("gl","LoadIdentity",&DAT_1000c044,(char *)0x0);
  FUN_10001680("gl","Ortho",&DAT_1000c0a4,(char *)0x0);
  FUN_10001680("gl","Scalef",&DAT_1000c0ac,(char *)0x0);
  FUN_10001680("gl","ClearDepth",&DAT_1000c124,(char *)0x0);
  FUN_10001680("gl","DepthRange",&DAT_1000c0f4,(char *)0x0);
  FUN_10001680("gl","Clear",&DAT_1000c0d4,(char *)0x0);
  FUN_10001680("gl","Flush",&DAT_1000c064,(char *)0x0);
  FUN_10001680("gl","Finish",&DAT_1000c028,(char *)0x0);
  FUN_10001680("gl","ReadBuffer",&DAT_1000c030,(char *)0x0);
  FUN_10001680("gl","DrawBuffer",&DAT_1000c084,(char *)0x0);
  FUN_10001680("gl","ReadPixels",&DAT_1000c0d8,(char *)0x0);
  FUN_10001680("gl","Enable",&DAT_1000c078,(char *)0x0);
  FUN_10001680("gl","Disable",&DAT_1000c050,(char *)0x0);
  FUN_10001680("gl","BindTexture",&DAT_1000c07c,(char *)0x0);
  FUN_10001680("gl","DeleteTextures",&DAT_1000c088,(char *)0x0);
  FUN_10001680("gl","FrontFace",&DAT_1000c094,(char *)0x0);
  FUN_10001680("gl","ClearColor",&DAT_1000c0c0,(char *)0x0);
  FUN_10001680("gl","ShadeModel",&DAT_1000c048,(char *)0x0);
  FUN_10001680("gl","Fogf",&DAT_1000c108,(char *)0x0);
  FUN_10001680("gl","Fogfv",&DAT_1000c08c,(char *)0x0);
  FUN_10001680("gl","Fogi",&DAT_1000c100,(char *)0x0);
  FUN_10001680("gl","FogCoordf",&DAT_1000c0e8,(char *)0x0);
  FUN_10001680("gl","DepthFunc",&DAT_1000c074,(char *)0x0);
  FUN_10001680("gl","AlphaFunc",&DAT_1000c0b0,(char *)0x0);
  FUN_10001680("gl","BlendFunc",&DAT_1000c0d0,(char *)0x0);
  FUN_10001680("gl","TexParameteri",&DAT_1000c054,(char *)0x0);
  FUN_10001680("gl","TexEnvi",&DAT_1000c0ec,(char *)0x0);
  FUN_10001680("gl","TexEnvf",&DAT_1000c06c,(char *)0x0);
  FUN_10001680("gl","TexImage2D",&DAT_1000c0bc,(char *)0x0);
  FUN_10001680("gl","TexSubImage2D",&DAT_1000c0c4,(char *)0x0);
  FUN_10001680("gl","DepthMask",&DAT_1000c118,(char *)0x0);
  FUN_10001680("gl","StencilFunc",&DAT_1000c040,(char *)0x0);
  FUN_10001680("gl","StencilOp",&DAT_1000c034,(char *)0x0);
  FUN_10001680("gl","LineWidth",&DAT_1000c0fc,(char *)0x0);
  FUN_10001680("gl","GenTextures",&DAT_1000c090,(char *)0x0);
  FUN_10001680("gl","ActiveTexture",(int *)&DAT_1000c104,(char *)0x0);
  FUN_10001680("gl","MultiTexCoord2f",(int *)&DAT_1000c058,(char *)0x0);
  FUN_10001680("gl","MultiTexCoord4f",&DAT_1000c0c8,(char *)0x0);
  FUN_10001680("gl","ColorTable",&DAT_1000c0a0,"EXT");
  FUN_10001680("gl","GetIntegerv",(int *)&DAT_1000c068,(char *)0x0);
  if (DAT_1000c0dc == (code *)0x0) {
    DAT_1000c11c = 0x110;
    goto LAB_10001f13;
  }
  DAT_1000c11c = 0;
  local_8 = (*DAT_1000c0dc)(0x1f02);
  uVar7 = 0;
  bVar6 = 8;
  while( true ) {
    while (cVar1 = *(char *)((uVar7 & 0xffff) + local_8), (byte)(cVar1 - 0x30U) < 10) {
      DAT_1000c11c = DAT_1000c11c + (cVar1 + -0x30 << (bVar6 & 0x1f));
      uVar7 = uVar7 + 1;
      bVar6 = bVar6 - 4;
    }
    if (cVar1 != '.') break;
    uVar7 = uVar7 + 1;
  }
  pcVar4 = (char *)(*DAT_1000c0dc)(0x1f03);
  if (DAT_1000c11c < 0x120) {
    pcVar5 = strstr(pcVar4,"GL_EXT_bgra");
    DAT_1000c0b8 = (uint)(pcVar5 != (char *)0x0);
  }
  else {
    DAT_1000c0b8 = 1;
  }
  if (DAT_1000c11c < 0x120) {
    pcVar5 = strstr(pcVar4,"GL_EXT_bgra");
    if (pcVar5 == (char *)0x0) {
      pcVar5 = strstr(pcVar4,"GL_EXT_texture_format_BGRA8888");
      if (pcVar5 == (char *)0x0) {
        pcVar5 = strstr(pcVar4,"GL_APPLE_texture_format_BGRA8888");
        if (pcVar5 == (char *)0x0) {
          DAT_1000c060 = 0;
          goto LAB_10001e7f;
        }
      }
    }
    DAT_1000c060 = 1;
  }
  else {
    DAT_1000c060 = 1;
  }
LAB_10001e7f:
  if (DAT_1000c11c < 0x120) {
    pcVar5 = strstr(pcVar4,"GL_EXT_texture_edge_clamp");
    if (pcVar5 == (char *)0x0) {
      pcVar5 = strstr(pcVar4,"GL_SGIS_texture_edge_clamp");
      if (pcVar5 == (char *)0x0) {
        DAT_1000c0b4 = 0;
        goto LAB_10001ec3;
      }
    }
    DAT_1000c0b4 = 1;
  }
  else {
    DAT_1000c0b4 = 1;
  }
LAB_10001ec3:
  if (DAT_1000c11c < 0x140) {
    pcVar5 = strstr(pcVar4,"GL_ARB_texture_mirrored_repeat");
    if (pcVar5 != (char *)0x0) goto LAB_10001ef0;
    pcVar5 = strstr(pcVar4,"GL_IBM_texture_mirrored_repeat");
    DAT_1000c04c = 0;
    if (pcVar5 != (char *)0x0) goto LAB_10001ef0;
  }
  else {
LAB_10001ef0:
    DAT_1000c04c = 1;
  }
  strstr(pcVar4,"GL_EXT_texture_filter_anisotropic");
LAB_10001f13:
  (*DAT_1000c068)(0xc00,&DAT_1000c0cc);
  return;
}



/* VA 10001f30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10001f30(void)

{
  char cVar1;
  float fVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  CHAR local_10c [260];
  float local_8;

  if (DAT_1000c85c == 0) {
    DAT_1000c85c = 1;
    GetModuleFileNameA(DAT_1000d868,local_10c,0x104);
    pcVar4 = strrchr(local_10c,0x2e);
    *pcVar4 = '\0';
    iVar5 = 0;
    do {
      cVar1 = local_10c[iVar5];
      *(char *)((int)&DAT_1000d8a8 + iVar5) = cVar1;
      iVar5 = iVar5 + 1;
    } while (cVar1 != '\0');
    puVar3 = (undefined4 *)0x1000d8a7;
    do {
      puVar6 = puVar3;
      puVar3 = (undefined4 *)((int)puVar6 + 1);
    } while (*(char *)((int)puVar6 + 1) != '\0');
    *(undefined4 *)((int)puVar6 + 1) = DAT_1000a5f8;
    *(undefined1 *)((int)puVar6 + 5) = DAT_1000a5fc;
    DAT_1000c730 = FUN_10009740("WINDOWED");
    DAT_1000c734 = FUN_10009740("RESOLUTION");
    if ((DAT_1000c734 != 0) && (0x1c < DAT_1000c734)) {
      DAT_1000c734 = 0;
    }
    DAT_1000c738 = FUN_10009740("COLORDEPTH");
    if (((DAT_1000c738 != 0x10) && (DAT_1000c738 != 0x18)) && (DAT_1000c738 != 0x20)) {
      DAT_1000c738 = 0x20;
    }
    _DAT_1000c73c = FUN_10009740("ZDEPTH");
    if (((_DAT_1000c73c != 0x10) && (_DAT_1000c73c != 0x18)) && (_DAT_1000c73c != 0x20)) {
      _DAT_1000c73c = 0x18;
    }
    DAT_1000c740 = FUN_10009740("REFRESH");
    if ((DAT_1000c740 != 0) && (9 < DAT_1000c740)) {
      DAT_1000c740 = 0;
    }
    DAT_1000c744 = FUN_10009740("EXCLUSIVE");
    DAT_1000c748 = FUN_10009740("VSYNC");
    DAT_1000c74c = FUN_10009740("ASPECT");
    DAT_1000c754 = FUN_10009740("TEXFILTER");
    if ((DAT_1000c754 != 0) && (2 < DAT_1000c754)) {
      DAT_1000c754 = 0;
    }
    DAT_1000c758 = FUN_10009740("ADD640X480X16");
    DAT_1000c75c = FUN_10009740("MOVIES16BIT");
    iVar5 = FUN_10009740("GAMMA");
    fVar2 = (float)iVar5;
    if (iVar5 < 0) {
      fVar2 = fVar2 + _DAT_1000ada0;
    }
    local_8 = fVar2 * (float)_DAT_1000ad70 + (float)_DAT_1000ad80;
    if ((local_8 < _DAT_1000ad68) || (_DAT_1000c750 = local_8, _DAT_1000ad78 < local_8)) {
      _DAT_1000c750 = 1.0;
    }
    DAT_1000c760 = FUN_10009740("TEX_CONVERT_ARGB32");
    DAT_1000c764 = FUN_10009740("TEX_COLOR_INDEX_4");
    DAT_1000c768 = FUN_10009740("TEX_COLOR_INDEX_8");
    DAT_1000c76c = FUN_10009740("TEX_COLOR_ARGB_1555");
    DAT_1000c770 = FUN_10009740("TEX_COLOR_RGB_565");
    DAT_1000c774 = FUN_10009740("TEX_COLOR_RGB_888");
    DAT_1000c778 = FUN_10009740("TEX_COLOR_ARGB_8888");
    DAT_1000c77c = FUN_10009740("TEX_COLOR_ARGB_4444");
    DAT_1000c780 = FUN_10009740("TEX_INDEX_RGB");
    DAT_1000c784 = FUN_10009740("TEX_INDEX_ARGB");
    FUN_10004750();
  }
  return;
}



/* VA 10002230 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * _THRASH_about_0(void)

{
                    /* 0x2230  1  _THRASH_about@0 */
  if (DAT_1000d9ac == 0) {
    FUN_10001f30();
    _DAT_1000d9a8 = DAT_1000a740;
    DAT_1000d9f4 = s_OpenGL_1_4_1000a748[0];
    DAT_1000d9f4_1._0_1_ = s_OpenGL_1_4_1000a748[1];
    DAT_1000d9f4_1._1_1_ = s_OpenGL_1_4_1000a748[2];
    DAT_1000d9f4_1._2_1_ = s_OpenGL_1_4_1000a748[3];
    DAT_1000d9f8 = s_OpenGL_1_4_1000a748[4];
    DAT_1000d9f8_1._0_1_ = s_OpenGL_1_4_1000a748[5];
    DAT_1000d9f8_1._1_1_ = s_OpenGL_1_4_1000a748[6];
    DAT_1000d9f8_1._2_1_ = s_OpenGL_1_4_1000a748[7];
    DAT_1000d9fc = s_OpenGL_1_4_1000a748[8];
    register0x00000001 = s_OpenGL_1_4_1000a748[9];
    DAT_1000d9fe = s_OpenGL_1_4_1000a748[10];
    DAT_1000da28 = s_D3D_Device_1000a754[0];
    DAT_1000da28_1._0_1_ = s_D3D_Device_1000a754[1];
    DAT_1000da28_1._1_1_ = s_D3D_Device_1000a754[2];
    DAT_1000da28_1._2_1_ = s_D3D_Device_1000a754[3];
    DAT_1000da2c = s_D3D_Device_1000a754[4];
    DAT_1000da2c_1._0_1_ = s_D3D_Device_1000a754[5];
    DAT_1000da2c_1._1_1_ = s_D3D_Device_1000a754[6];
    DAT_1000da2c_1._2_1_ = s_D3D_Device_1000a754[7];
    DAT_1000da30 = s_D3D_Device_1000a754[8];
    register0x00000001 = s_D3D_Device_1000a754[9];
    DAT_1000da32 = s_D3D_Device_1000a754[10];
    _DAT_1000d9b0 = DAT_1000c000;
    _DAT_1000c7b4 = DAT_1000c764;
    _DAT_1000c7b8 = DAT_1000c768;
    _DAT_1000c7bc = DAT_1000c76c;
    _DAT_1000c7c0 = DAT_1000c770;
    _DAT_1000c7c4 = DAT_1000c774;
    _DAT_1000c7c8 = DAT_1000c778;
    _DAT_1000c7cc = DAT_1000c77c;
    _DAT_1000c808 = DAT_1000c780;
    _DAT_1000c80c = DAT_1000c784;
    _DAT_1000d9e4 = DAT_1000d848 + 1;
    DAT_1000d9ac = 0xa0;
    _DAT_1000d9b4 = 0xe;
    _DAT_1000d9b8 = 2;
    DAT_1000d9bc = 0x200;
    _DAT_1000d9c0 = 8;
    _DAT_1000d9c4 = 2;
    DAT_1000d9c8 = 0x200;
    _DAT_1000d9cc = 8;
    _DAT_1000d9d0 = 0;
    _DAT_1000d9d4 = 0x12;
    DAT_1000d9d8 = &DAT_1000c7b0;
    _DAT_1000d9dc = 5;
    DAT_1000d9e0 = &DAT_1000c7fc;
    _DAT_1000d9e8 = &DAT_1000c898;
    _DAT_1000da14 = 4;
    _DAT_1000da18 = 0x4000000;
    _DAT_1000da1c = 3;
    _DAT_1000d9ec = 4;
    _DAT_1000da20 = "AUTHOR: Oleksiy Ryabchun, Sat Nov 13 00:15:34 2021";
    _DAT_1000da24 = 7;
    FUN_10009830((int *)&DAT_1000d9a8);
  }
  return &DAT_1000d9a8;
}



/* VA 100023f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _THRASH_clip_16(uint param_1,int param_2,uint param_3,uint param_4)

{
  double dVar1;
  float fVar2;
  int *piVar3;
  uint uVar4;
  bool bVar5;
  double dVar6;

  piVar3 = (int *)&DAT_1000c880;
  uVar4 = 0xc;
  do {
    register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4);
    if (*(int *)register0x00000010 != *piVar3) {
      DAT_1000c884 = param_2;
      DAT_1000c880 = param_1;
      DAT_1000c888 = param_3;
      DAT_1000c88c = param_4;
      uVar4 = DAT_1000c820;
      if ((0 < (int)param_1) &&
         ((DAT_1000c820 != 0 || (uVar4 = param_1, DAT_1000c828 != *DAT_1000d84c)))) {
        fVar2 = (float)(int)param_1 * _DAT_1000c840 + _DAT_1000c830;
        dVar1 = (double)fVar2;
        dVar6 = floor((double)fVar2);
        if (dVar6 + _DAT_1000ad80 <= dVar1) {
          ceil(dVar1);
        }
        uVar4 = thunk_FUN_10009c00();
      }
      param_1 = uVar4;
      uVar4 = DAT_1000c828 + DAT_1000c820;
      if ((param_1 < DAT_1000c828 + DAT_1000c820) &&
         ((DAT_1000c820 != 0 || (uVar4 = param_3, DAT_1000c828 != *DAT_1000d84c)))) {
        fVar2 = (float)(int)param_3 * _DAT_1000c840 + _DAT_1000c830;
        dVar1 = (double)fVar2;
        dVar6 = floor((double)fVar2);
        if (dVar6 + _DAT_1000ad80 <= dVar1) {
          ceil(dVar1);
        }
        uVar4 = thunk_FUN_10009c00();
      }
      param_3 = uVar4;
      if (param_2 < 1) {
        param_2 = DAT_1000c824;
      }
      else if ((DAT_1000c824 != 0) || (DAT_1000c82c != DAT_1000d84c[1])) {
        fVar2 = (float)param_2 * _DAT_1000c844 + _DAT_1000c834;
        dVar1 = (double)fVar2;
        dVar6 = floor((double)fVar2);
        if (dVar6 + _DAT_1000ad80 <= dVar1) {
          ceil(dVar1);
        }
        param_2 = thunk_FUN_10009c00();
      }
      uVar4 = DAT_1000c82c + DAT_1000c824;
      if ((param_4 < uVar4) &&
         ((DAT_1000c824 != 0 || (uVar4 = param_4, DAT_1000c82c != DAT_1000d84c[1])))) {
        fVar2 = (float)(int)param_4 * _DAT_1000c844 + _DAT_1000c834;
        dVar1 = (double)fVar2;
        dVar6 = floor((double)fVar2);
        if (dVar6 + _DAT_1000ad80 <= dVar1) {
          ceil(dVar1);
        }
        uVar4 = thunk_FUN_10009c00();
      }
      (*DAT_1000c110)(param_1,DAT_1000c81c - uVar4,param_3 - param_1,uVar4 - param_2);
      return 1;
    }
    piVar3 = piVar3 + 1;
    bVar5 = 3 < uVar4;
    uVar4 = uVar4 - 4;
  } while (bVar5);
  return 1;
}



/* VA 10002670 */

void _THRASH_idle_0(void)

{
                    /* 0x2670  23  _THRASH_idle@0 */
  return;
}



/* VA 10002680 */

undefined4 _THRASH_init_0(void)

{
  ushort uVar1;
  char *pcVar2;
  HDC hdc;
  short sVar3;
  char *pcVar4;
  short *psVar5;
  short *psVar6;
  int iVar7;
  CHAR local_108 [12];
  char local_fc [248];

                    /* 0x2680  24  _THRASH_init@0 */
  if (DAT_1000c850 == 0) {
    DAT_1000c850 = 1;
    FUN_10001f30();
    GetModuleFileNameA(DAT_1000d868,local_108,0x104);
    pcVar2 = strrchr(local_108,0x5c);
    pcVar2[1] = '\0';
    pcVar2 = &stack0xfffffef7;
    do {
      pcVar4 = pcVar2;
      pcVar2 = pcVar4 + 1;
    } while (pcVar4[1] != '\0');
    *(undefined4 *)(pcVar4 + 1) = s_OPENGL32_DLL_1000a794._0_4_;
    *(undefined4 *)(pcVar4 + 5) = s_OPENGL32_DLL_1000a794._4_4_;
    *(undefined4 *)(pcVar4 + 9) = s_OPENGL32_DLL_1000a794._8_4_;
    pcVar4[0xd] = s_OPENGL32_DLL_1000a794[0xc];
    DAT_1000c098 = LoadLibraryA(local_108);
    if ((DAT_1000c098 == (HMODULE)0x0) &&
       (DAT_1000c098 = LoadLibraryA("OPENGL32.DLL"), DAT_1000c098 == (HMODULE)0x0)) {
      DAT_1000c098 = LoadLibraryA("OPENGL.DLL");
      if (DAT_1000c098 == (HMODULE)0x0) {
        return 0;
      }
    }
    DAT_1000c0a8 = GetProcAddress(DAT_1000c098,"wglGetProcAddress");
    DAT_1000c018 = GetProcAddress(DAT_1000c098,"wglMakeCurrent");
    DAT_1000c02c = GetProcAddress(DAT_1000c098,"wglCreateContext");
    DAT_1000c024 = GetProcAddress(DAT_1000c098,"wglDeleteContext");
    DAT_1000c0f0 = GetProcAddress(DAT_1000c098,"wglSwapBuffers");
    if (DAT_1000d87c != (code *)0x0) {
      (*DAT_1000d87c)(0x464,FUN_10004b50);
      (*DAT_1000d87c)(0x465,FUN_10005030);
    }
    if ((DAT_1000c730 == 0) && (DAT_1000c78c == 0)) {
      hdc = GetDC((HWND)0x0);
      DAT_1000c12c = GetDeviceGammaRamp(hdc,&DAT_1000c130);
      ReleaseDC((HWND)0x0,hdc);
      if (DAT_1000c12c != 0) {
        if (((DAT_1000c32f <= DAT_1000c130._1_1_) || (DAT_1000c52f <= DAT_1000c330._1_1_)) ||
           (DAT_1000c72f <= DAT_1000c531)) {
          DAT_1000c12c = 0;
        }
        if (DAT_1000c29b == -1) {
          psVar6 = &DAT_1000c130;
          iVar7 = 3;
          do {
            uVar1 = 0;
            psVar5 = psVar6;
            do {
              sVar3 = uVar1 << 8;
              uVar1 = uVar1 + 1;
              *psVar5 = sVar3;
              psVar5 = psVar5 + 1;
            } while (uVar1 < 0xff);
            psVar6 = psVar6 + 0x100;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
      }
    }
  }
  return 1;
}



/* VA 10002890 */

byte _THRASH_is_0(void)

{
                    /* 0x2890  25  _THRASH_is@0 */
  return -(DAT_1000c098 != 0) & 0x55;
}



/* VA 100028a0 */

void _THRASH_pageflip_0(void)

{
                    /* 0x28a0  27  _THRASH_pageflip@0 */
  (*DAT_1000c0f0)(DAT_1000d86c);
  if (DAT_1000c748 != 0) {
                    /* WARNING: Could not recover jumptable at 0x100028b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_1000c028)();
    return;
  }
  return;
}



/* VA 100028c0 */

undefined4 _THRASH_restore_0(void)

{
  DWORD DVar1;
  DWORD DVar2;

                    /* 0x28c0  29  _THRASH_restore@0 */
  FUN_10001510();
  if (DAT_1000c098 != (HMODULE)0x0) {
    DAT_1000c0a8 = 0;
    DAT_1000c018 = 0;
    DAT_1000c02c = 0;
    DAT_1000c024 = 0;
    FreeLibrary(DAT_1000c098);
    DAT_1000c098 = (HMODULE)0x0;
  }
  if ((DAT_1000d87c != 0) && (DAT_1000d878 != (code *)0x0)) {
    DVar1 = GetWindowThreadProcessId(DAT_1000d864,(LPDWORD)0x0);
    DVar2 = GetCurrentThreadId();
    if (DVar2 != DVar1) {
      DAT_1000d864 = (HWND)(*DAT_1000d878)();
      DAT_1000d870 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
      SetForegroundWindow(DAT_1000d864);
      PostMessageA(DAT_1000d864,0x465,0,0);
      WaitForSingleObject(DAT_1000d870,10000);
      return 1;
    }
  }
  if ((DAT_1000c730 == 0) && (DAT_1000c78c == 0)) {
    ChangeDisplaySettingsA((DEVMODEA *)0x0,0);
  }
  return 1;
}



/* VA 100029b0 */

undefined4 _THRASH_selectdisplay_4(int param_1)

{
                    /* 0x29b0  30  _THRASH_selectdisplay@4 */
  if (DAT_1000d838 != param_1) {
    DAT_1000d838 = param_1;
    FUN_10004750();
  }
  return 1;
}



/* VA 100029e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _THRASH_setvideomode_12(WPARAM param_1,int param_2,int param_3)

{
  double dVar1;
  double dVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  DWORD DVar7;
  DWORD DVar8;
  float *pfVar9;

                    /* 0x29e0  33  _THRASH_setvideomode@12 */
  if ((((DAT_1000c860 != 0) && (param_1 == DAT_1000d840)) && (param_2 == DAT_1000d83c)) &&
     (param_3 == DAT_1000c874)) {
    return 1;
  }
  DAT_1000c860 = 1;
  DAT_1000d840 = param_1;
  DAT_1000d83c = param_2;
  DAT_1000c874 = param_3;
  FUN_10001510();
  if ((DAT_1000d878 != (code *)0x0) && (DAT_1000d864 = (HWND)(*DAT_1000d878)(), DAT_1000d87c != 0))
  {
    DVar7 = GetWindowThreadProcessId(DAT_1000d864,(LPDWORD)0x0);
    DVar8 = GetCurrentThreadId();
    if (DVar8 != DVar7) {
      DAT_1000d8a0 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
      SetForegroundWindow(DAT_1000d864);
      PostMessageA(DAT_1000d864,0x464,param_1,param_2);
      WaitForSingleObject(DAT_1000d8a0,10000);
      goto LAB_10002ad4;
    }
  }
  FUN_10004b50(0,DAT_1000d864,0x464,param_1,param_2,(undefined4 *)0x0);
LAB_10002ad4:
  FUN_10001280();
  (*DAT_1000c128)(0xc50,0x1102);
  (*DAT_1000c128)(0xc54,0x1100);
  (*DAT_1000c128)(0xc51,0x1100);
  (*DAT_1000c128)(0xc52,0x1100);
  (*DAT_1000c128)(0xc53,0x1100);
  DAT_1000c814 = 0;
  (*DAT_1000c0f8)(DAT_1000c820,DAT_1000c824,DAT_1000c828,DAT_1000c82c);
  (*DAT_1000c038)(0x1701);
  (*DAT_1000c044)();
  dVar1 = (double)(int)DAT_1000d84c[1];
  if ((int)DAT_1000d84c[1] < 0) {
    dVar1 = dVar1 + _DAT_1000ad98;
  }
  dVar2 = (double)(int)*DAT_1000d84c;
  if ((int)*DAT_1000d84c < 0) {
    dVar2 = dVar2 + _DAT_1000ad98;
  }
  (*DAT_1000c0a4)(0,dVar2,dVar1,0,0,0x3ff0000000000000);
  (*DAT_1000c038)(0x1700);
  (*DAT_1000c044)();
  (*DAT_1000c0ac)(0x3f800000,0x3f800000,_DAT_1000ada4);
  (*DAT_1000c0f4)(0,0x3ff0000000000000);
  (*DAT_1000c050)(0xc11);
  if (0 < DAT_1000c0cc) {
    _THRASH_window_4((float *)0x0);
    (*DAT_1000c0d4)(0x4500);
  }
  if (DAT_1000c814 != 0) {
    DAT_1000c814 = 0;
    (*DAT_1000c0f8)(DAT_1000c820,DAT_1000c824,DAT_1000c828,DAT_1000c82c);
    uVar6 = DAT_1000c88c;
    uVar5 = DAT_1000c888;
    iVar4 = DAT_1000c884;
    uVar3 = DAT_1000c880;
    DAT_1000c880 = 0;
    DAT_1000c884 = 0;
    DAT_1000c888 = 0;
    DAT_1000c88c = 0;
    _THRASH_clip_16(uVar3,iVar4,uVar5,uVar6);
  }
  FUN_10005080(0x3b,0,(float *)0x1);
  DAT_1000c858 = 1;
  (*DAT_1000c030)(0x404);
  (*DAT_1000c084)(0x404);
  (*DAT_1000c0d4)(0x4500);
  if (DAT_1000c814 != 0) {
    DAT_1000c814 = 0;
    (*DAT_1000c0f8)(DAT_1000c820,DAT_1000c824,DAT_1000c828,DAT_1000c82c);
    uVar6 = DAT_1000c88c;
    uVar5 = DAT_1000c888;
    iVar4 = DAT_1000c884;
    uVar3 = DAT_1000c880;
    DAT_1000c880 = 0;
    DAT_1000c884 = 0;
    DAT_1000c888 = 0;
    DAT_1000c88c = 0;
    _THRASH_clip_16(uVar3,iVar4,uVar5,uVar6);
  }
  FUN_10005080(0x3b,0,(float *)0x2);
  DAT_1000c858 = 1;
  (*DAT_1000c030)(0x405);
  (*DAT_1000c084)(0x405);
  (*DAT_1000c0d4)(0x4500);
  (*DAT_1000c078)(0xc11);
  DAT_1000c880 = 0;
  DAT_1000c884 = 0;
  DAT_1000c888 = 0;
  DAT_1000c88c = 0;
  _THRASH_clip_16(0,0,*DAT_1000d84c,DAT_1000d84c[1]);
  (*DAT_1000c078)(0x8458);
  pfVar9 = (float *)FUN_10009740(&DAT_1000a80c);
  FUN_10005080(0x130,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740(&DAT_1000a814);
  FUN_10005080(2,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("FILTER");
  FUN_10005080(7,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("SHADE");
  FUN_10005080(6,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("TRANSPARENCY");
  FUN_10005080(10,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("ALPHATEST");
  FUN_10005080(0x24,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("MIPMAP");
  FUN_10005080(0xb,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("BACKGROUNDCOLOUR");
  FUN_10005080(3,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("CHROMACOLOUR");
  FUN_10005080(0xc,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("DITHER");
  FUN_10005080(5,0xffff0000,pfVar9);
  FUN_10005080(0x14,0xffff0000,(float *)0x0);
  pfVar9 = (float *)FUN_10009740("FOGMODE");
  FUN_10005080(0x15,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("FOGDENSITY");
  FUN_10005080(0xe,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("STATE_FOGZNEAR");
  FUN_10005080(0x16,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("FOGZFAR");
  FUN_10005080(0x17,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("FOGCOLOUR");
  FUN_10005080(0xf,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("ALPHA");
  FUN_10005080(0x38,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("TEXTURECLAMP");
  FUN_10005080(0xd,0xffff0000,pfVar9);
  FUN_10005080(0x2e,0xffff0000,(float *)0x3f800000);
  pfVar9 = (float *)FUN_10009740("DEPTHBIAS");
  FUN_10005080(0x18,0xffff0000,pfVar9);
  FUN_10005080(8,0xffff0000,(float *)0x0);
  pfVar9 = (float *)FUN_10009740("MAXPENDING");
  FUN_10005080(0x6d,0xffff0000,pfVar9);
  FUN_10005080(0x2a,0xffff0000,(float *)0x0);
  FUN_10005080(0x29,0xffff0000,(float *)0x0);
  FUN_10005080(0x29,0xffff0001,(float *)0x2);
  pfVar9 = (float *)FUN_10009740("BACKBUFFERTYPE");
  FUN_10005080(0x2b,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("FLATFANS");
  FUN_10005080(0x11,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("LINEWIDTH");
  FUN_10005080(0x10,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("STENCILBUFFER");
  FUN_10005080(0x2f,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("DISPLAYMODE");
  FUN_10005080(0x3a,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("LINEDOUBLE");
  FUN_10005080(0x131,0xffff0000,pfVar9);
  FUN_10005080(0x3b,0xffff0000,(float *)0x0);
  FUN_10005080(0x43,0xffff0000,(float *)0x3f800000);
  pfVar9 = (float *)FUN_10009740("FLIPRATE");
  FUN_10005080(0x3c,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("SHAMELESSPLUG");
  FUN_10005080(0x3d,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("DEPTHBUFFER");
  FUN_10005080(4,0xffff0000,pfVar9);
  pfVar9 = (float *)FUN_10009740("DEPTHCMP");
  FUN_10005080(0x28,0xffff0000,pfVar9);
  return 1;
}



/* VA 100032a0 */

undefined4 _THRASH_sync_4(void)

{
                    /* 0x32a0  34  _THRASH_sync@4 */
  return 1;
}



/* VA 100032b0 */

void __fastcall FUN_100032b0(int param_1,int param_2,undefined4 *param_3,int param_4)

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



/* VA 10003390 */

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

                    /* 0x3390  28  _THRASH_readrect@20 */
  if (DAT_1000c75c == 0) {
    uVar7 = (uint)DAT_1000d84c[2] >> 3;
    if (uVar7 == 3) {
      uVar9 = 0x80e0;
      uVar5 = 0x1401;
      goto LAB_100033ec;
    }
    if (uVar7 == 4) {
      uVar9 = 0x80e1;
      uVar5 = 0x1401;
      goto LAB_100033ec;
    }
  }
  else {
    uVar7 = 2;
  }
  uVar5 = 0x8363;
  uVar9 = 0x1907;
LAB_100033ec:
  if ((DAT_1000c818 == *DAT_1000d84c) && (DAT_1000c81c == DAT_1000d84c[1])) {
    (*DAT_1000c0d8)(param_1,(DAT_1000c81c - param_2) - param_4,param_3,param_4,uVar9,uVar5,param_5);
  }
  else {
    fVar2 = (float)(int)param_3;
    if ((int)param_3 < 0) {
      fVar2 = fVar2 + _DAT_1000ada0;
    }
    dVar1 = (double)(fVar2 * _DAT_1000c840);
    dVar11 = floor((double)(fVar2 * _DAT_1000c840));
    if (dVar11 + _DAT_1000ad80 <= dVar1) {
      dVar11 = ceil(dVar1);
    }
    local_48._0_4_ = (int)(longlong)ROUND(dVar11);
    iVar4 = local_48._0_4_;
    fVar2 = (float)(int)param_4;
    if ((int)param_4 < 0) {
      fVar2 = fVar2 + _DAT_1000ada0;
    }
    dVar1 = (double)(fVar2 * _DAT_1000c844);
    dVar11 = floor((double)(fVar2 * _DAT_1000c844));
    if (dVar11 + _DAT_1000ad80 <= dVar1) {
      dVar11 = ceil(dVar1);
    }
    local_48._0_4_ = (int)(longlong)ROUND(dVar11);
    iVar3 = local_48._0_4_;
    if (DAT_1000d894 == (code *)0x0) {
      _Memory = malloc(local_48._0_4_ * iVar4 * uVar7);
    }
    else {
      _Memory = (void *)(*DAT_1000d894)();
    }
    fVar2 = (float)(int)(param_2 + param_4);
    if ((int)(param_2 + param_4) < 0) {
      fVar2 = fVar2 + _DAT_1000ada0;
    }
    dVar1 = (double)(fVar2 * _DAT_1000c844);
    local_48 = floor((double)(fVar2 * _DAT_1000c844));
    if (local_48 + _DAT_1000ad80 <= dVar1) {
      local_48 = ceil(dVar1);
    }
    fVar2 = (float)param_1;
    if (param_1 < 0) {
      fVar2 = fVar2 + _DAT_1000ada0;
    }
    dVar1 = (double)(fVar2 * _DAT_1000c840);
    dVar11 = floor((double)(fVar2 * _DAT_1000c840));
    if (dVar11 + _DAT_1000ad80 <= dVar1) {
      dVar11 = ceil(dVar1);
    }
    local_48._0_4_ = (int)(longlong)ROUND(local_48);
    iVar6 = DAT_1000c81c - local_48._0_4_;
    local_48._0_4_ = (int)(longlong)ROUND(dVar11);
    (*DAT_1000c0d8)(local_48._0_4_ + DAT_1000c820,iVar6 - DAT_1000c824,iVar4,iVar3,uVar9,uVar5,
                    _Memory);
    uVar7 = 0;
    if (iStack_74 == 4) {
      puVar10 = param_5;
      if (param_4 != 0) {
        do {
          fVar2 = (float)(int)uVar7;
          if ((int)uVar7 < 0) {
            fVar2 = fVar2 + _DAT_1000ada0;
          }
          dVar1 = (double)(fVar2 * _DAT_1000c844);
          dVar11 = floor((double)(fVar2 * _DAT_1000c844));
          if (dVar11 + _DAT_1000ad80 <= dVar1) {
            dVar11 = ceil(dVar1);
          }
          uVar8 = 0;
          local_64 = (int)(longlong)ROUND(dVar11);
          iVar4 = local_64 * unaff_EBX;
          if (param_3 != 0) {
            do {
              fVar2 = (float)(int)uVar8;
              if ((int)uVar8 < 0) {
                fVar2 = fVar2 + _DAT_1000ada0;
              }
              dVar1 = (double)(fVar2 * _DAT_1000c840);
              dVar11 = floor((double)(fVar2 * _DAT_1000c840));
              if (dVar11 + _DAT_1000ad80 <= dVar1) {
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
            fVar2 = fVar2 + _DAT_1000ada0;
          }
          dVar1 = (double)(fVar2 * _DAT_1000c844);
          dVar11 = floor((double)(fVar2 * _DAT_1000c844));
          if (dVar11 + _DAT_1000ad80 <= dVar1) {
            dVar11 = ceil(dVar1);
          }
          uVar8 = 0;
          local_64 = (int)(longlong)ROUND(dVar11);
          iVar4 = local_64 * unaff_EBX;
          if (param_3 != 0) {
            do {
              fVar2 = (float)(int)uVar8;
              if ((int)uVar8 < 0) {
                fVar2 = fVar2 + _DAT_1000ada0;
              }
              dVar1 = (double)(fVar2 * _DAT_1000c840);
              dVar11 = floor((double)(fVar2 * _DAT_1000c840));
              if (dVar11 + _DAT_1000ad80 <= dVar1) {
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
    if (DAT_1000d898 == (code *)0x0) {
      free(_Memory);
    }
    else {
      (*DAT_1000d898)();
    }
  }
  FUN_100032b0(param_3,param_4,param_5,iStack_74);
  return 1;
}



/* VA 10003950 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _THRASH_writerect_20(int param_1,int param_2,uint param_3,uint param_4,int param_5)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  void *pvVar5;
  float *_Size;
  uint uVar6;
  int iVar7;
  ushort *unaff_EBX;
  uint uVar8;
  float *pfVar9;
  ushort *_Dst;
  bool bVar10;
  uint uVar11;
  int iStack_274;
  uint uStack_270;
  uint local_268;
  float *pfStack_264;
  size_t sStack_260;
  float *pfStack_25c;
  float *local_258;
  float *pfStack_250;
  float *pfStack_24c;
  float *pfStack_248;
  float *pfStack_244;
  float *pfStack_240;
  float *pfStack_23c;
  undefined4 *puStack_238;
  int iStack_230;
  float fStack_228;
  float local_224 [6];
  undefined4 uStack_20c;
  float fStack_208;
  float afStack_204 [6];
  undefined4 uStack_1ec;
  float fStack_1e8;
  float afStack_1e4 [6];
  undefined4 uStack_1cc;
  float fStack_1c8;
  float afStack_1c4 [6];
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  char acStack_198 [404];

                    /* 0x3950  41  _THRASH_writerect@20 */
  if (DAT_1000c75c == 0) {
    uVar8 = *(uint *)(DAT_1000d84c + 8) >> 3;
    local_258 = (float *)(uVar8 * param_3);
    if (uVar8 == 3) {
      iVar3 = 5;
      goto LAB_100039bb;
    }
    if (uVar8 == 4) {
      iVar3 = 6;
      goto LAB_100039bb;
    }
  }
  else {
    uVar8 = 2;
    local_258 = (float *)(param_3 * 2);
  }
  iVar3 = 4;
LAB_100039bb:
  pfVar4 = (float *)_THRASH_talloc_20(DAT_1000d9bc,DAT_1000d9c8,iVar3,0,0);
  if (pfVar4 != (float *)0x0) {
    local_224[0] = (float)(uVar8 * DAT_1000d9bc);
    _Size = (float *)((int)local_224[0] * DAT_1000d9c8);
    if (DAT_1000d894 == (code *)0x0) {
      pvVar5 = malloc((size_t)_Size);
    }
    else {
      pvVar5 = (void *)(*DAT_1000d894)();
    }
    if (pvVar5 != (void *)0x0) {
      pfStack_250 = (float *)FUN_10009a20(1);
      if (-1 < (int)pfStack_250) {
        pfStack_250 = *(float **)(&DAT_1000da48 + (int)pfStack_250 * 4);
      }
      pfStack_24c = (float *)FUN_10009a20(6);
      if (-1 < (int)pfStack_24c) {
        pfStack_24c = *(float **)(&DAT_1000da48 + (int)pfStack_24c * 4);
      }
      pfStack_248 = (float *)FUN_10009a20(0x2a);
      if (-1 < (int)pfStack_248) {
        pfStack_248 = *(float **)(&DAT_1000da48 + (int)pfStack_248 * 4);
      }
      pfStack_244 = (float *)FUN_10009a20(2);
      if (-1 < (int)pfStack_244) {
        pfStack_244 = *(float **)(&DAT_1000da48 + (int)pfStack_244 * 4);
      }
      pfStack_240 = (float *)FUN_10009a20(0xd);
      if (-1 < (int)pfStack_240) {
        pfStack_240 = *(float **)(&DAT_1000da48 + (int)pfStack_240 * 4);
      }
      pfStack_23c = (float *)FUN_10009a20(0xb);
      if (-1 < (int)pfStack_23c) {
        pfStack_23c = *(float **)(&DAT_1000da48 + (int)pfStack_23c * 4);
      }
      puStack_238 = (undefined4 *)FUN_10009a20(10);
      if (-1 < (int)puStack_238) {
        puStack_238 = *(undefined4 **)(&DAT_1000da48 + (int)puStack_238 * 4);
      }
      FUN_10009a20(4);
      iStack_230 = FUN_10009a20(0x29);
      if (-1 < iStack_230) {
        iStack_230 = *(int *)(&DAT_1000da48 + iStack_230 * 4);
      }
      FUN_10005080(1,0,pfVar4);
      FUN_10005080(6,0,(float *)0x0);
      FUN_10005080(0x2a,0,(float *)0x0);
      FUN_10005080(2,0,(float *)0x0);
      FUN_10005080(0xd,0,(float *)0x0);
      FUN_10005080(0xb,0,(float *)0x0);
      FUN_10005080(10,0,(float *)0x0);
      FUN_10005080(4,0,(float *)0x0);
      (*DAT_1000c0ec)(0x2300,0x2200,0x1e01);
      local_224[4] = -1.7014118e+38;
      local_224[2] = 0.0;
      local_224[3] = 1.0;
      uStack_20c = 0;
      fStack_208 = 0.0;
      pfVar4 = local_224;
      pfVar9 = afStack_204;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pfVar9 = *pfVar4;
        pfVar4 = pfVar4 + 1;
        pfVar9 = pfVar9 + 1;
      }
      uStack_1ec = 0x3f800000;
      fStack_1e8 = 0.0;
      pfVar4 = local_224;
      pfVar9 = afStack_1e4;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pfVar9 = *pfVar4;
        pfVar4 = pfVar4 + 1;
        pfVar9 = pfVar9 + 1;
      }
      uStack_1cc = 0x3f800000;
      fStack_1c8 = 1.0;
      pfVar4 = local_224;
      pfVar9 = afStack_1c4;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pfVar9 = *pfVar4;
        pfVar4 = pfVar4 + 1;
        pfVar9 = pfVar9 + 1;
      }
      uStack_1ac = 0;
      uStack_1a8 = 0x3f800000;
      local_268 = 0;
      uVar8 = DAT_1000d9c8;
      pfVar4 = local_258;
      if (param_4 != 0) {
        do {
          uVar6 = param_4 - local_268;
          if (uVar8 < param_4 - local_268) {
            uVar6 = uVar8;
          }
          uVar11 = 0;
          if (param_3 != 0) {
            fStack_228 = (float)(local_268 * (int)pfVar4);
            iVar3 = local_268 + param_2;
            fVar1 = (float)iVar3;
            if (iVar3 < 0) {
              fVar1 = fVar1 + _DAT_1000ada0;
            }
            do {
              fVar2 = fStack_228;
              uVar8 = param_3 - uVar11;
              bVar10 = uVar8 == DAT_1000d9bc;
              if (DAT_1000d9bc < uVar8) {
                bVar10 = uVar6 == DAT_1000d9c8;
                uVar8 = DAT_1000d9bc;
              }
              if (!bVar10) {
                memset(unaff_EBX,0,sStack_260);
              }
              pvVar5 = (void *)(uVar11 * iStack_274 + (int)fVar2 + param_5);
              if (uVar6 != 0) {
                _Dst = unaff_EBX;
                uStack_270 = uVar6;
                do {
                  memcpy(_Dst,pvVar5,uVar8 * iStack_274);
                  pvVar5 = (void *)((int)pvVar5 + (int)pfStack_264);
                  _Dst = (ushort *)((int)_Dst + iStack_230);
                  uStack_270 = uStack_270 - 1;
                } while (uStack_270 != 0);
              }
              _THRASH_tupdate_12(puStack_238,unaff_EBX,(undefined4 *)0x0);
              iVar7 = param_1 + uVar11;
              local_224[0] = (float)iVar7;
              if (iVar7 < 0) {
                local_224[0] = local_224[0] + _DAT_1000ada0;
              }
              afStack_204[0] = (float)(int)(DAT_1000d9bc + iVar7);
              if ((int)(DAT_1000d9bc + iVar7) < 0) {
                afStack_204[0] = afStack_204[0] + _DAT_1000ada0;
              }
              afStack_1e4[1] = (float)(int)(DAT_1000d9c8 + iVar3);
              if ((int)(DAT_1000d9c8 + iVar3) < 0) {
                afStack_1e4[1] = afStack_1e4[1] + _DAT_1000ada0;
              }
              local_224[1] = fVar1;
              afStack_204[1] = fVar1;
              afStack_1e4[0] = afStack_204[0];
              afStack_1c4[0] = local_224[0];
              afStack_1c4[1] = afStack_1e4[1];
              FUN_10006890();
              (*DAT_1000c120)(6);
              if (DAT_1000c7a4 == 0) {
                FUN_10009370(&fStack_228);
                FUN_10009370(&fStack_208);
                FUN_10009370(&fStack_1e8);
                FUN_10009370(&fStack_1c8);
              }
              else {
                FUN_100094c0(&fStack_228);
                FUN_100094c0(&fStack_208);
                FUN_100094c0(&fStack_1e8);
                FUN_100094c0(&fStack_1c8);
              }
              (*DAT_1000c10c)();
              uVar11 = uVar11 + DAT_1000d9bc;
              uVar8 = DAT_1000d9c8;
            } while (uVar11 < param_3);
          }
          local_268 = local_268 + uVar8;
          pfVar4 = pfStack_264;
        } while (local_268 < param_4);
      }
      (*DAT_1000c064)();
      FUN_10005080(1,0,pfStack_25c);
      FUN_10005080(6,0,local_258);
      FUN_10005080(0x2a,0,_Size);
      FUN_10005080(2,0,pfStack_250);
      FUN_10005080(0xd,0,pfStack_24c);
      FUN_10005080(0xb,0,pfStack_248);
      FUN_10005080(10,0,pfStack_244);
      FUN_10005080(4,0,pfStack_240);
      FUN_10005080(0x29,0xffff0000,pfStack_23c);
      if (DAT_1000d898 != (code *)0x0) {
        (*DAT_1000d898)();
        _THRASH_tfree_4((int)pfStack_23c);
        return 1;
      }
      free(unaff_EBX);
      _THRASH_tfree_4((int)puStack_238);
      return 1;
    }
    _THRASH_tfree_4((int)pfVar4);
    if (DAT_1000d88c != (code *)0x0) {
      sprintf(acStack_198,"%s:\n%s\n\n\nFILE %s\nLINE %d","Write","Out of memory.",
              "D:\\Work\\Tharsh\\Thrash.OpenGL.1\\Rect.cpp",0x132);
      (*DAT_1000d88c)(0,acStack_198);
    }
  }
  return 1;
}



/* VA 10003ff0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_10003ff0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  undefined4 local_34;
  undefined4 local_2c;
  undefined4 local_24;

  DAT_1000c814 = 1;
  DAT_1000c824 = 0;
  DAT_1000c820 = 0;
  _DAT_1000c834 = 0.0;
  _DAT_1000c830 = 0.0;
  DAT_1000c818 = param_1;
  DAT_1000c828 = param_1;
  DAT_1000c81c = param_2;
  DAT_1000c82c = param_2;
  fVar1 = (float)param_1;
  if (param_1 < 0) {
    fVar1 = fVar1 + _DAT_1000ada0;
  }
  fVar2 = (float)*DAT_1000d84c;
  if (*DAT_1000d84c < 0) {
    fVar2 = fVar2 + _DAT_1000ada0;
  }
  DAT_1000c838 = fVar1 / fVar2;
  _DAT_1000c840 = DAT_1000c838;
  fVar2 = (float)param_2;
  if (param_2 < 0) {
    fVar2 = fVar2 + _DAT_1000ada0;
  }
  fVar3 = (float)DAT_1000d84c[1];
  if (DAT_1000d84c[1] < 0) {
    fVar3 = fVar3 + _DAT_1000ada0;
  }
  DAT_1000c83c = fVar2 / fVar3;
  _DAT_1000c844 = DAT_1000c83c;
  if ((DAT_1000c74c != 0) && (DAT_1000c838 != DAT_1000c83c)) {
    if (DAT_1000c838 <= DAT_1000c83c) {
      fVar1 = (float)DAT_1000d84c[1];
      if (DAT_1000d84c[1] < 0) {
        fVar1 = fVar1 + _DAT_1000ada0;
      }
      fVar1 = DAT_1000c838 * fVar1;
      dVar4 = floor((double)fVar1);
      if (dVar4 + _DAT_1000ad80 <= (double)fVar1) {
        dVar4 = ceil((double)fVar1);
      }
      local_2c = (undefined4)(longlong)ROUND(dVar4);
      DAT_1000c82c = local_2c;
      _DAT_1000c834 = (fVar2 - fVar1) * (float)_DAT_1000ad80;
      dVar4 = (double)_DAT_1000c834;
      dVar5 = floor((double)_DAT_1000c834);
      if (dVar5 + _DAT_1000ad80 <= dVar4) {
        dVar5 = ceil(dVar4);
      }
      _DAT_1000c844 = DAT_1000c838;
      local_34 = (undefined4)(longlong)ROUND(dVar5);
      DAT_1000c824 = local_34;
      return;
    }
    fVar2 = (float)*DAT_1000d84c;
    if (*DAT_1000d84c < 0) {
      fVar2 = fVar2 + _DAT_1000ada0;
    }
    fVar2 = DAT_1000c83c * fVar2;
    dVar4 = floor((double)fVar2);
    if (dVar4 + _DAT_1000ad80 <= (double)fVar2) {
      dVar4 = ceil((double)fVar2);
    }
    local_24 = (undefined4)(longlong)ROUND(dVar4);
    DAT_1000c828 = local_24;
    _DAT_1000c830 = (fVar1 - fVar2) * (float)_DAT_1000ad80;
    dVar4 = (double)_DAT_1000c830;
    dVar5 = floor((double)_DAT_1000c830);
    if (dVar5 + _DAT_1000ad80 <= dVar4) {
      dVar5 = ceil(dVar4);
    }
    _DAT_1000c840 = DAT_1000c83c;
    local_2c = (undefined4)(longlong)ROUND(dVar5);
    DAT_1000c820 = local_2c;
    return;
  }
  return;
}



/* VA 10004320 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10004320(HWND param_1,uint param_2,WPARAM param_3,uint param_4)

{
  double dVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  double dVar6;

  if (param_2 < 0x1d) {
    if (param_2 == 0x1c) {
switchD_10004342_caseD_6:
      DefWindowProcA(param_1,param_2,param_3,param_4);
      return;
    }
    switch(param_2) {
    case 5:
      FUN_10003ff0(param_4 & 0xffff,param_4 >> 0x10);
      goto LAB_100044ff;
    case 6:
    case 7:
    case 8:
      goto switchD_10004342_caseD_6;
    }
  }
  else if (param_2 < 0x113) {
    if (param_2 == 0x112) {
      DefWindowProcA(param_1,0x112,param_3,param_4);
      return;
    }
    if (param_2 == 0x86) goto switchD_10004342_caseD_6;
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
      if (iVar3 < DAT_1000c820) {
        uVar4 = 0;
      }
      else if (iVar3 < DAT_1000c828 + DAT_1000c820) {
        fVar2 = (float)(iVar3 - DAT_1000c820);
        if (iVar3 - DAT_1000c820 < 0) {
          fVar2 = fVar2 + _DAT_1000ada0;
        }
        dVar1 = (double)(fVar2 / _DAT_1000c840);
        dVar6 = floor((double)(fVar2 / _DAT_1000c840));
        if (dVar6 + _DAT_1000ad80 <= dVar1) {
          ceil(dVar1);
        }
        uVar4 = thunk_FUN_10009c00();
      }
      else {
        uVar4 = *DAT_1000d84c - 1;
      }
      if (iVar5 < DAT_1000c824) {
        param_4 = uVar4 & 0xffff;
      }
      else if (iVar5 < DAT_1000c82c + DAT_1000c824) {
        fVar2 = (float)(iVar5 - DAT_1000c824);
        if (iVar5 - DAT_1000c824 < 0) {
          fVar2 = fVar2 + _DAT_1000ada0;
        }
        dVar1 = (double)(fVar2 / _DAT_1000c844);
        dVar6 = floor((double)(fVar2 / _DAT_1000c844));
        if (dVar6 + _DAT_1000ad80 <= dVar1) {
          ceil(dVar1);
        }
        iVar3 = thunk_FUN_10009c00();
        param_4 = iVar3 << 0x10 | uVar4 & 0xffff;
      }
      else {
        param_4 = (DAT_1000d84c[1] + -1) * 0x10000 | uVar4 & 0xffff;
      }
      goto LAB_100044ff;
    }
  }
LAB_100044ff:
  CallWindowProcA(DAT_1000e4d8,param_1,param_2,param_3,param_4);
  return;
}



/* VA 10004550 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10004550(HWND param_1,uint param_2,WPARAM param_3,uint param_4)

{
  double dVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  double dVar6;

  if (param_2 < 0x201) {
    if (param_2 == 0x200) {
switchD_1000459d_caseD_201:
      iVar3 = (int)(short)param_4;
      iVar5 = (int)(short)(param_4 >> 0x10);
      if (iVar3 < DAT_1000c820) {
        uVar4 = 0;
      }
      else if (iVar3 < DAT_1000c828 + DAT_1000c820) {
        fVar2 = (float)(iVar3 - DAT_1000c820);
        if (iVar3 - DAT_1000c820 < 0) {
          fVar2 = fVar2 + _DAT_1000ada0;
        }
        dVar1 = (double)(fVar2 / _DAT_1000c840);
        dVar6 = floor((double)(fVar2 / _DAT_1000c840));
        if (dVar6 + _DAT_1000ad80 <= dVar1) {
          ceil(dVar1);
        }
        uVar4 = thunk_FUN_10009c00();
      }
      else {
        uVar4 = *DAT_1000d84c - 1;
      }
      if (iVar5 < DAT_1000c824) {
        param_4 = uVar4 & 0xffff;
      }
      else if (iVar5 < DAT_1000c82c + DAT_1000c824) {
        fVar2 = (float)(iVar5 - DAT_1000c824);
        if (iVar5 - DAT_1000c824 < 0) {
          fVar2 = fVar2 + _DAT_1000ada0;
        }
        dVar1 = (double)(fVar2 / _DAT_1000c844);
        dVar6 = floor((double)(fVar2 / _DAT_1000c844));
        if (dVar6 + _DAT_1000ad80 <= dVar1) {
          ceil(dVar1);
        }
        iVar3 = thunk_FUN_10009c00();
        param_4 = iVar3 << 0x10 | uVar4 & 0xffff;
      }
      else {
        param_4 = (DAT_1000d84c[1] + -1) * 0x10000 | uVar4 & 0xffff;
      }
      goto LAB_100046dc;
    }
    if (param_2 == 5) {
      FUN_10003ff0(param_4 & 0xffff,param_4 >> 0x10);
      goto LAB_100046dc;
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
      goto switchD_1000459d_caseD_201;
    }
  }
LAB_100046dc:
  CallWindowProcA(DAT_1000e4d8,param_1,param_2,param_3,param_4);
  return;
}



/* VA 10004720 */

undefined4 FUN_10004720(HINSTANCE param_1,undefined4 param_2,LPCSTR param_3,HWND param_4)

{
  HICON dwNewLong;

  dwNewLong = LoadIconA(param_1,param_3);
  if (dwNewLong != (HICON)0x0) {
    SetClassLongA(param_4,-0xe,(LONG)dwNewLong);
    return 0;
  }
  return 1;
}



/* VA 10004750 */

undefined4 FUN_10004750(void)

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

  memset(&DAT_1000c898,0,4000);
  DAT_1000d848 = 0;
  if (DAT_1000c758 != 0) {
    DAT_1000c8c0 = 0x280;
    DAT_1000c8c4 = 0x1e0;
    DAT_1000c8c8 = 0x10;
    DAT_1000c8cc = 4;
    DAT_1000c8d0 = 1;
    DAT_1000c8d4 = 3;
    DAT_1000c8d8 = 3;
  }
  memset(local_1b0.DeviceName,0,0x1a4);
  local_1b0.cb = 0x1a8;
  BVar1 = EnumDisplayDevicesA((LPCSTR)0x0,DAT_1000d838,&local_1b0,0);
  lpszDeviceName = local_1b0.DeviceName;
  if (BVar1 == 0) {
    lpszDeviceName = (CHAR *)0x0;
  }
  memset(&local_318,0,0x9c);
  local_318.dmSize = 0x9c;
  EnumDisplaySettingsA(lpszDeviceName,0xfffffffe,&local_318);
  DAT_1000d850 = local_318.dmPelsWidth;
  DAT_1000d854 = local_318.dmPelsHeight;
  if ((DAT_1000c730 == 0) && (DAT_1000c78c == 0)) {
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
        uVar6 = DAT_1000c738;
        if (local_318.dmBitsPerPel == DAT_1000c738) break;
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
    DAT_1000c738 = local_318.dmBitsPerPel;
    uVar6 = DAT_1000c738;
  }
  DAT_1000c738 = uVar6;
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
       (local_318.dmBitsPerPel == DAT_1000c738)) {
      puVar4 = &DAT_1000c8c0;
      uVar6 = 1;
      while (*puVar4 != 0) {
        cVar11 = *puVar4 == local_318.dmPelsWidth;
        if (puVar4[1] == local_318.dmPelsHeight) {
          cVar11 = cVar11 + '\x01';
        }
        if (puVar4[2] == local_318.dmBitsPerPel) {
          cVar11 = cVar11 + '\x01';
        }
        if (cVar11 == '\x03') goto LAB_10004ac5;
        uVar6 = uVar6 + 1;
        puVar4 = puVar4 + 10;
        if (0x62 < uVar6) {
          return local_324;
        }
      }
      *puVar4 = local_318.dmPelsWidth;
      uVar5 = 1;
      puVar4[1] = local_318.dmPelsHeight;
      puVar2 = &DAT_1000c8c0;
      puVar4[2] = local_318.dmBitsPerPel;
      puVar4[3] = 4;
      puVar4[4] = 1;
      puVar4[5] = 3;
      puVar4[6] = 3;
      if (1 < uVar6) {
LAB_10004a70:
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
LAB_10004ac5:
      if (uVar6 == 0) {
        return local_324;
      }
LAB_10004ac9:
      local_324 = 1;
      if (DAT_1000d848 < uVar6) {
        DAT_1000d848 = uVar6;
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
  if (uVar6 <= uVar5) goto LAB_10004ac9;
  goto LAB_10004a70;
}



/* VA 10004b50 */

undefined4
FUN_10004b50(undefined4 param_1,HWND param_2,undefined4 param_3,int param_4,undefined4 param_5,
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

  DAT_1000d84c = (uint *)(&DAT_1000c898 + param_4 * 0x28);
  if (DAT_1000c78c == 0) {
    if (DAT_1000c734 == 0) {
      uVar2 = *DAT_1000d84c;
      uVar3 = *(uint *)(&DAT_1000c89c + param_4 * 0x28);
    }
    else {
      uVar2 = DAT_1000d850;
      uVar3 = DAT_1000d854;
      if (DAT_1000c734 != 1) {
        uVar2 = (uint)*(ushort *)(&DAT_1000a970 + DAT_1000c734 * 4);
        uVar3 = (uint)*(ushort *)(&DAT_1000a970 + DAT_1000c734 * 4);
      }
    }
    FUN_10003ff0(uVar2,uVar3);
    if (DAT_1000c730 == 0) {
      memset(local_340.DeviceName,0,0x1a4);
      local_340.cb = 0x1a8;
      memset(&local_3e0,0,0x9c);
      local_3e0.dmSize = 0x9c;
      EnumDisplayDevicesA((LPCSTR)0x0,DAT_1000d838,&local_340,0);
      EnumDisplaySettingsA(local_340.DeviceName,0xfffffffe,&local_3e0);
      uVar2 = GetWindowLongA(param_2,-0x10);
      local_448.bottom = DAT_1000c81c;
      local_3e0.dmPelsHeight = DAT_1000c81c;
      local_448.left = 0;
      local_448.top = (DAT_1000c744 != 0) - 1;
      local_448.right = DAT_1000c818;
      local_3e0.dmPelsWidth = DAT_1000c818;
      local_3e0.dmBitsPerPel = DAT_1000d84c[2];
      local_3e0.dmFields = 0x1c0000;
      if (DAT_1000c740 != 0) {
        local_3e0.dmDisplayFrequency = (DWORD)(byte)(&DAT_1000a96b)[DAT_1000c740];
        local_3e0.dmFields = 0x5c0000;
      }
      LVar4 = ChangeDisplaySettingsExA
                        (local_340.DeviceName,&local_3e0,(HWND)0x0,0x40000006,(LPVOID)0x0);
      if ((LVar4 != 0) && (DAT_1000d88c != (code *)0x0)) {
        sprintf(local_198,"%s:\n%s\n\n\nFILE %s\nLINE %d","Change","Bad display mode",
                "D:\\Work\\Tharsh\\Thrash.OpenGL.1\\Resolution.cpp",local_3e0.dmBitsPerPel);
        (*DAT_1000d88c)(0,local_198);
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
      local_448.top = local_434.rcWork.bottom - DAT_1000c81c >> 1;
      local_448.left = local_434.rcWork.right - DAT_1000c818 >> 1;
      local_448.right = DAT_1000c818 + local_448.left;
      local_438 = 0x12cf0000;
      local_448.bottom = local_448.top + DAT_1000c81c;
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
        EnumResourceNamesA(hModule,(LPCSTR)0xe,FUN_10004720,(LONG_PTR)param_2);
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
      FUN_10003ff0(local_448.right,local_448.bottom);
      if (DAT_1000e4d8 == 0) {
        DAT_1000e4d8 = (*pcVar5)(param_2,0xfffffffc,FUN_10004320);
      }
    }
  }
  else {
    GetClientRect(param_2,&local_448);
    FUN_10003ff0(local_448.right - local_448.left,local_448.bottom - local_448.top);
    if (DAT_1000e4d8 == 0) {
      DAT_1000e4d8 = SetWindowLongA(param_2,-4,0x10004550);
    }
  }
  if (param_6 != (undefined4 *)0x0) {
    SetEvent(DAT_1000d8a0);
    *param_6 = 1;
  }
  return 1;
}



/* VA 10005030 */

undefined4 FUN_10005030(void)

{
  undefined4 *in_stack_00000018;

  if ((DAT_1000c730 == 0) && (DAT_1000c78c == 0)) {
    ChangeDisplaySettingsA((DEVMODEA *)0x0,0);
  }
  if (in_stack_00000018 != (undefined4 *)0x0) {
    SetEvent(DAT_1000d870);
    *in_stack_00000018 = 1;
  }
  return 1;
}



/* VA 10005080 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_10005080(uint param_1,uint param_2,float *param_3)

{
  longlong lVar1;
  double dVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  void *this;
  int *piVar8;
  ushort uVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  float *pfVar13;
  float fVar14;
  float *pfVar15;
  int iVar16;
  bool bVar17;
  undefined4 uVar18;
  uint local_708;
  int *local_6fc;
  float local_6f8 [8];
  _OSVERSIONINFOA local_6d8;
  ushort local_640 [127];
  ushort local_542 [671];

  uVar12 = param_2 & 0xffff;
  local_6fc = (int *)0x0;
  iVar5 = FUN_10009a20(param_1);
  if (-1 < iVar5) {
    local_6fc = (int *)(&DAT_1000da48 + (uVar12 * 0x8c + iVar5) * 4);
  }
  if (param_1 == 0x1b3) {
    fVar14 = *param_3;
    DAT_1000d844 = (uint)fVar14 & 0x80;
    if (((ushort *)param_3[4] == (ushort *)0x0) || (param_3[5] == 0.0)) {
      switch(fVar14) {
      case 1.4013e-45:
        fVar14 = param_3[3];
        pfVar13 = (float *)param_3[2];
        if (fVar14 != 0.0) {
          FUN_10006890();
          (*DAT_1000c120)();
          if (DAT_1000c7a4 == 0) {
            do {
              FUN_10009370(pfVar13);
              pfVar13 = pfVar13 + 8;
              fVar14 = (float)((int)fVar14 + -1);
            } while (fVar14 != 0.0);
            (*DAT_1000c10c)();
          }
          else {
            do {
              FUN_100094c0(pfVar13);
              pfVar13 = pfVar13 + 10;
              fVar14 = (float)((int)fVar14 + -1);
            } while (fVar14 != 0.0);
            (*DAT_1000c10c)();
          }
        }
        break;
      case 2.8026e-45:
        fVar14 = param_3[3];
        pfVar13 = (float *)param_3[2];
        if (fVar14 != 0.0) {
          FUN_10006890();
          (*DAT_1000c120)();
          if (DAT_1000c7a4 == 0) {
            do {
              FUN_10009370(pfVar13);
              pfVar13 = pfVar13 + 8;
              fVar14 = (float)((int)fVar14 + -1);
            } while (fVar14 != 0.0);
            (*DAT_1000c10c)();
          }
          else {
            do {
              FUN_100094c0(pfVar13);
              pfVar13 = pfVar13 + 10;
              fVar14 = (float)((int)fVar14 + -1);
            } while (fVar14 != 0.0);
            (*DAT_1000c10c)();
          }
        }
        break;
      case 4.2039e-45:
        fVar14 = param_3[3];
        pfVar13 = (float *)param_3[2];
        if (fVar14 != 0.0) {
          FUN_10006890();
          (*DAT_1000c120)();
          if (DAT_1000c7a4 == 0) {
            do {
              FUN_10009370(pfVar13);
              pfVar13 = pfVar13 + 8;
              fVar14 = (float)((int)fVar14 + -1);
            } while (fVar14 != 0.0);
            (*DAT_1000c10c)();
          }
          else {
            do {
              FUN_100094c0(pfVar13);
              pfVar13 = pfVar13 + 10;
              fVar14 = (float)((int)fVar14 + -1);
            } while (fVar14 != 0.0);
            (*DAT_1000c10c)();
          }
        }
        break;
      case 5.60519e-45:
        fVar14 = param_3[3];
        pfVar13 = (float *)param_3[2];
        if (fVar14 != 0.0) {
          FUN_10006890();
          (*DAT_1000c120)();
          if (DAT_1000c7a4 == 0) {
            do {
              FUN_10009370(pfVar13);
              pfVar13 = pfVar13 + 8;
              fVar14 = (float)((int)fVar14 + -1);
            } while (fVar14 != 0.0);
            (*DAT_1000c10c)();
          }
          else {
            do {
              FUN_100094c0(pfVar13);
              pfVar13 = pfVar13 + 10;
              fVar14 = (float)((int)fVar14 + -1);
            } while (fVar14 != 0.0);
            (*DAT_1000c10c)();
          }
        }
        break;
      case 7.00649e-45:
        fVar14 = param_3[3];
        pfVar13 = (float *)param_3[2];
        if (fVar14 != 0.0) {
          FUN_10006890();
          (*DAT_1000c120)();
          if (DAT_1000c7a4 == 0) {
            do {
              FUN_10009370(pfVar13);
              pfVar13 = pfVar13 + 8;
              fVar14 = (float)((int)fVar14 + -1);
            } while (fVar14 != 0.0);
            (*DAT_1000c10c)();
          }
          else {
            do {
              FUN_100094c0(pfVar13);
              pfVar13 = pfVar13 + 10;
              fVar14 = (float)((int)fVar14 + -1);
            } while (fVar14 != 0.0);
            (*DAT_1000c10c)();
          }
        }
        break;
      case 8.40779e-45:
        fVar14 = param_3[3];
        pfVar13 = (float *)param_3[2];
        if (fVar14 != 0.0) {
          FUN_10006890();
          (*DAT_1000c120)();
          if (DAT_1000c7a4 == 0) {
            do {
              FUN_10009370(pfVar13);
              pfVar13 = pfVar13 + 8;
              fVar14 = (float)((int)fVar14 + -1);
            } while (fVar14 != 0.0);
            (*DAT_1000c10c)();
          }
          else {
            do {
              FUN_100094c0(pfVar13);
              pfVar13 = pfVar13 + 10;
              fVar14 = (float)((int)fVar14 + -1);
            } while (fVar14 != 0.0);
            (*DAT_1000c10c)();
          }
        }
        break;
      default:
        goto switchD_10005109_default;
      }
    }
    else {
      switch(fVar14) {
      case 1.4013e-45:
        fVar14 = param_3[2];
        this = (void *)0x0;
        break;
      case 2.8026e-45:
        fVar14 = param_3[2];
        this = (void *)0x1;
        break;
      case 4.2039e-45:
        fVar14 = param_3[2];
        this = (void *)0x3;
        break;
      case 5.60519e-45:
        fVar14 = param_3[2];
        this = (void *)0x4;
        break;
      case 7.00649e-45:
        fVar14 = param_3[2];
        this = (void *)0x5;
        break;
      case 8.40779e-45:
        fVar14 = param_3[2];
        this = (void *)0x6;
        break;
      default:
switchD_10005109_default:
        return 0;
      }
      FUN_100096d0(this,(int)param_3[5],(int)fVar14,(ushort *)param_3[4]);
    }
    goto switchD_10005400_caseD_c;
  }
  if ((((param_2 & 0xffff0000) == 0) && (local_6fc != (int *)0x0)) &&
     ((float *)*local_6fc == param_3)) {
    return 1;
  }
  if (0x194 < (int)param_1) {
    if (param_1 == 0x195) {
      switch(param_3) {
      case (float *)0x0:
        DAT_1000c848 = 1;
        break;
      case (float *)0x1:
        DAT_1000c848 = 0;
        break;
      case (float *)0x2:
        DAT_1000c848 = 0x302;
        break;
      case (float *)0x3:
        DAT_1000c848 = 0x303;
        break;
      case (float *)0x4:
        DAT_1000c848 = 0x304;
        break;
      case (float *)0x5:
        DAT_1000c848 = 0x305;
        break;
      case (float *)0x6:
        DAT_1000c848 = 0x300;
        break;
      case (float *)0x7:
        DAT_1000c848 = 0x306;
        break;
      case (float *)0x8:
        DAT_1000c848 = 0x301;
        break;
      case (float *)0x9:
        DAT_1000c848 = 0x307;
        break;
      default:
        goto switchD_10005109_default;
      }
      (*DAT_1000c0d0)(DAT_1000c7ac,DAT_1000c848);
      iVar11 = FUN_10009a20(0x38);
      if (-1 < iVar11) {
        *(undefined4 *)(&DAT_1000da48 + (uVar12 * 0x8c + iVar11) * 4) = 4;
      }
      iVar11 = FUN_10009a20(0x68);
      if (-1 < iVar11) {
        *(undefined4 *)(&DAT_1000da48 + (uVar12 * 0x8c + iVar11) * 4) = 4;
      }
    }
    goto switchD_10005400_caseD_c;
  }
  if (param_1 == 0x194) {
    switch(param_3) {
    case (float *)0x0:
      DAT_1000c7ac = 1;
      break;
    case (float *)0x1:
      DAT_1000c7ac = 0;
      break;
    case (float *)0x2:
      DAT_1000c7ac = 0x302;
      break;
    case (float *)0x3:
      DAT_1000c7ac = 0x303;
      break;
    case (float *)0x4:
      DAT_1000c7ac = 0x304;
      break;
    case (float *)0x5:
      DAT_1000c7ac = 0x305;
      break;
    case (float *)0x6:
      DAT_1000c7ac = 0x300;
      break;
    case (float *)0x7:
      DAT_1000c7ac = 0x306;
      break;
    case (float *)0x8:
      DAT_1000c7ac = 0x301;
      break;
    case (float *)0x9:
      DAT_1000c7ac = 0x307;
      break;
    default:
      goto switchD_10005109_default;
    }
    (*DAT_1000c0d0)(DAT_1000c7ac,DAT_1000c848);
    iVar11 = FUN_10009a20(0x38);
    if (-1 < iVar11) {
      *(undefined4 *)(&DAT_1000da48 + (uVar12 * 0x8c + iVar11) * 4) = 4;
    }
    iVar11 = FUN_10009a20(0x68);
    if (-1 < iVar11) {
      *(undefined4 *)(&DAT_1000da48 + (uVar12 * 0x8c + iVar11) * 4) = 4;
    }
    goto switchD_10005400_caseD_c;
  }
  switch(param_1) {
  case 1:
    DAT_1000c84c = (uint)((float *)0xf < param_3);
    if (param_3 < (float *)0x10) {
      (*DAT_1000c050)();
    }
    else {
      (*DAT_1000c078)();
      if ((ushort *)param_3[0xe] != (ushort *)0x0) {
        piVar8 = (int *)param_3[0x10];
        if (piVar8 == (int *)0x0) {
LAB_10005453:
          _THRASH_tupdate_12(param_3,(ushort *)param_3[0xe],(undefined4 *)0x0);
        }
        else {
          piVar10 = &DAT_1000e0d8;
          uVar12 = 0x3fc;
          do {
            if (*piVar8 != *piVar10) goto LAB_10005453;
            piVar8 = piVar8 + 1;
            piVar10 = piVar10 + 1;
            bVar17 = 3 < uVar12;
            uVar12 = uVar12 - 4;
          } while (bVar17);
        }
      }
    }
    if (((param_3 == (float *)0x0) || (DAT_1000d860 == 0)) || (param_3 < (float *)0x10)) {
      DAT_1000d85c = (float *)0x0;
    }
    else if (DAT_1000d85c != param_3) {
      DAT_1000d85c = param_3;
      (*DAT_1000c07c)(0xde1,*param_3);
    }
    break;
  case 2:
    if (param_3 == (float *)0x0) {
      (*DAT_1000c050)();
    }
    else if (param_3 == (float *)0x1) {
      (*DAT_1000c078)();
      (*DAT_1000c094)(0x900);
    }
    else {
      if (param_3 != (float *)0x2) {
        return 0;
      }
      (*DAT_1000c078)();
      (*DAT_1000c094)(0x901);
    }
    break;
  case 3:
    fVar14 = (float)_DAT_1000ad88;
    (*DAT_1000c0c0)((float)((uint)param_3 >> 0x10 & 0xff) / fVar14,
                    (float)((uint)param_3 >> 8 & 0xff) / fVar14,
                    (float)((uint)param_3 & 0xff) / fVar14,(float)((uint)param_3 >> 0x18) / fVar14);
    break;
  case 4:
    if (param_3 != (float *)0x0) {
      if (param_3 != (float *)0x1) {
        return 0;
      }
      DAT_1000c7a0 = 1;
      (*DAT_1000c078)();
      (*DAT_1000c074)(DAT_1000c008);
      break;
    }
    DAT_1000c7a0 = 0;
    goto LAB_10005892;
  case 5:
    if (param_3 != (float *)0x0) {
      (*DAT_1000c078)();
      break;
    }
LAB_10005892:
    (*DAT_1000c050)();
    break;
  case 6:
    if ((param_3 == (float *)0x0) || (param_3 == (float *)0x1)) {
      (*DAT_1000c048)();
      DAT_1000d844 = 0;
    }
    else {
      if (param_3 != (float *)0x2) {
        return 0;
      }
      (*DAT_1000c048)();
      DAT_1000d844 = 1;
    }
    break;
  case 7:
  case 0x4a:
    DAT_1000c87c = param_3;
    break;
  case 8:
    (*DAT_1000c06c)(0x8500,0x8501,param_3);
    break;
  case 9:
    if (param_3 == (float *)0x0) {
      (*DAT_1000c050)();
      (*DAT_1000c050)(0xb20);
      (*DAT_1000c050)(0xb41);
    }
    else {
      if (param_3 != (float *)0x1) {
        return 0;
      }
      (*DAT_1000c078)();
      (*DAT_1000c078)(0xb20);
      (*DAT_1000c078)(0xb41);
    }
    break;
  case 10:
    if ((float *)0x6a < DAT_1000c000) {
      switch(param_3) {
      case (float *)0x0:
      case (float *)0x1:
        goto switchD_10005999_caseD_0;
      case (float *)0x2:
      case (float *)0x3:
        goto switchD_10005999_caseD_2;
      default:
        goto switchD_10005109_default;
      }
    }
    if (param_3 == (float *)0x0) {
switchD_10005999_caseD_0:
      (*DAT_1000c050)();
      (*DAT_1000c050)(0xbe2);
    }
    else {
      if ((param_3 != (float *)0x1) && (param_3 != (float *)0x2)) {
        return 0;
      }
switchD_10005999_caseD_2:
      (*DAT_1000c078)();
      (*DAT_1000c0b0)(DAT_1000c004,_DAT_1000c854);
      (*DAT_1000c078)(0xbe2);
      (*DAT_1000c0d0)(DAT_1000c7ac,DAT_1000c848);
    }
    break;
  case 0xb:
    DAT_1000c878 = param_3;
    break;
  case 0xd:
    if (param_3 == (float *)0x0) {
      if (DAT_1000c0b4 == 0) {
        DAT_1000c7a8 = 0x2900;
        DAT_1000c890 = 0x2900;
      }
      else {
        DAT_1000c7a8 = 0x812f;
        DAT_1000c890 = 0x812f;
      }
      break;
    }
    if (param_3 != (float *)0x1) {
      if (param_3 != (float *)0x2) {
        return 0;
      }
      if (DAT_1000c04c == 0) {
        return 0;
      }
      DAT_1000c7a8 = 0x8370;
      DAT_1000c890 = 0x8370;
      break;
    }
    DAT_1000c7a8 = 0x2901;
    goto LAB_10005712;
  case 0xe:
    if ((param_3 == (float *)0x0) || (((uint)param_3 & 0xfffff000) != 0)) {
      (*DAT_1000c108)(0xb62,param_3);
    }
    else {
      dVar2 = (double)(int)param_3;
      if ((int)param_3 < 0) {
        dVar2 = dVar2 + _DAT_1000ad98;
      }
      (*DAT_1000c108)(0xb62,1.0 / (float)dVar2);
    }
    break;
  case 0xf:
    local_6f8[3] = (float)_DAT_1000ad88;
    local_6f8[0] = (float)((uint)param_3 >> 0x10 & 0xff) / local_6f8[3];
    local_6f8[1] = (float)((uint)param_3 >> 8 & 0xff) / local_6f8[3];
    local_6f8[2] = (float)((uint)param_3 & 0xff) / local_6f8[3];
    local_6f8[3] = (float)((uint)param_3 >> 0x18) / local_6f8[3];
    (*DAT_1000c08c)(0xb66,local_6f8);
    break;
  case 0x10:
    (*DAT_1000c0fc)();
    break;
  case 0x12:
    DAT_1000c78c = param_3;
    break;
  case 0x13:
    iVar11 = 8;
    pfVar15 = (float *)&DAT_1000d874;
    pfVar13 = param_3;
    if (param_3 == (float *)0x0) {
      local_6f8[0] = 0.0;
      local_6f8[1] = 0.0;
      local_6f8[2] = 0.0;
      local_6f8[3] = 0.0;
      local_6f8[4] = 0.0;
      local_6f8[5] = 0.0;
      local_6f8[6] = 0.0;
      local_6f8[7] = 0.0;
      pfVar13 = local_6f8;
      for (; iVar11 != 0; iVar11 = iVar11 + -1) {
        *pfVar15 = *pfVar13;
        pfVar13 = pfVar13 + 1;
        pfVar15 = pfVar15 + 1;
      }
    }
    else {
      for (; iVar11 != 0; iVar11 = iVar11 + -1) {
        *pfVar15 = *pfVar13;
        pfVar13 = pfVar13 + 1;
        pfVar15 = pfVar15 + 1;
      }
    }
    break;
  case 0x14:
  case 0x15:
  case 0x69:
    switch(param_3) {
    case (float *)0x0:
      DAT_1000c86c = 0;
      (*DAT_1000c050)();
      break;
    case (float *)0x1:
      DAT_1000c86c = 1;
      (*DAT_1000c078)();
      if (DAT_1000c0e8 != 0) {
        (*DAT_1000c100)(0x8450,0x8451);
      }
      break;
    case (float *)0x2:
      (*DAT_1000c100)(0xb65,0x2601);
      break;
    default:
      goto switchD_10005109_default;
    case (float *)0x4:
      (*DAT_1000c100)(0xb65,0x800);
      break;
    case (float *)0x6:
      (*DAT_1000c100)(0xb65,0x801);
    }
    break;
  case 0x16:
    if (((uint)param_3 & 0xffff0000) == 0) {
      fVar14 = (float)(int)param_3;
      if ((int)param_3 < 0) {
        fVar14 = fVar14 + _DAT_1000ada0;
      }
    }
    else {
      fVar14 = (float)param_3 * (float)_DAT_1000ad90;
    }
    (*DAT_1000c108)(0xb63,fVar14);
    break;
  case 0x17:
    if (((uint)param_3 & 0xffff0000) == 0) {
      fVar14 = (float)(int)param_3;
      if ((int)param_3 < 0) {
        fVar14 = fVar14 + _DAT_1000ada0;
      }
    }
    else {
      fVar14 = (float)param_3 * (float)_DAT_1000ad90;
    }
    (*DAT_1000c108)(0xb64,fVar14);
    break;
  case 0x18:
  case 0x66:
    _DAT_1000c870 = ((float)(int)param_3 + (float)(int)param_3) * (float)_DAT_1000ad60;
    break;
  case 0x19:
    DAT_1000d864 = param_3;
    break;
  case 0x1a:
    DAT_1000d88c = param_3;
    break;
  case 0x1b:
    DAT_1000d87c = param_3;
    break;
  case 0x1c:
    DAT_1000d888 = param_3;
    break;
  case 0x1d:
    if ((param_3 == (float *)0x0) && ((param_2 & 0xffff0000) == 0)) {
      return 0;
    }
    break;
  case 0x1e:
    if (param_3 == (float *)0x20) {
      DAT_1000c7a4 = 0;
    }
    else {
      if (param_3 != (float *)0x28) {
        return 0;
      }
      DAT_1000c7a4 = 1;
    }
    break;
  case 0x1f:
    DAT_1000c000 = param_3;
    break;
  case 0x20:
    DAT_1000d894 = param_3;
    break;
  case 0x21:
    DAT_1000d898 = param_3;
    break;
  case 0x24:
    if (param_3 == (float *)0x0) {
      _DAT_1000c854 = 0.0;
    }
    else {
      _DAT_1000c854 = (float)(int)param_3;
      if ((int)param_3 < 0) {
        _DAT_1000c854 = _DAT_1000c854 + _DAT_1000ada0;
      }
      _DAT_1000c854 = _DAT_1000c854 / (float)_DAT_1000ad88;
    }
    (*DAT_1000c0b0)(DAT_1000c004,_DAT_1000c854);
    break;
  case 0x27:
    DAT_1000d89c = param_3;
    break;
  case 0x28:
    switch(param_3) {
    case (float *)0x0:
      DAT_1000c008 = 0x200;
      (*DAT_1000c074)();
      break;
    case (float *)0x1:
      DAT_1000c008 = 0x201;
      (*DAT_1000c074)();
      break;
    case (float *)0x2:
      DAT_1000c008 = 0x202;
      (*DAT_1000c074)();
      break;
    case (float *)0x3:
      DAT_1000c008 = 0x203;
      (*DAT_1000c074)();
      break;
    case (float *)0x4:
      DAT_1000c008 = 0x204;
      (*DAT_1000c074)();
      break;
    case (float *)0x5:
      DAT_1000c008 = 0x205;
      (*DAT_1000c074)();
      break;
    case (float *)0x6:
      DAT_1000c008 = 0x206;
      (*DAT_1000c074)();
      break;
    case (float *)0x7:
      DAT_1000c008 = 0x207;
      (*DAT_1000c074)();
      break;
    default:
      goto switchD_10005109_default;
    }
    break;
  case 0x29:
    if ((DAT_1000c11c < 0x130) || (param_3 == (float *)0x0)) {
      (*DAT_1000c0ec)(0x2300,0x2200,0x2100);
    }
    else {
      if (param_3 == (float *)0x1) {
        (*DAT_1000c0ec)(0x2300,0x2200,0x8570);
        (*DAT_1000c0ec)(0x2300,0x8571,0x104);
        (*DAT_1000c0ec)(0x2300,0x8573,1);
        (*DAT_1000c0ec)(0x2300,0x8580,0x1702);
        (*DAT_1000c0ec)(0x2300,0x8581,0x8578);
        (*DAT_1000c0ec)(0x2300,0x8590,0x300);
        (*DAT_1000c0ec)(0x2300,0x8591,0x300);
        uVar18 = 0x104;
      }
      else {
        if (param_3 != (float *)0x3) {
          return 0;
        }
        (*DAT_1000c0ec)(0x2300,0x2200,0x8570);
        (*DAT_1000c0ec)(0x2300,0x8571,0x2100);
        (*DAT_1000c0ec)(0x2300,0x8573,1);
        (*DAT_1000c0ec)(0x2300,0x8580,0x1702);
        (*DAT_1000c0ec)(0x2300,0x8581,0x8578);
        (*DAT_1000c0ec)(0x2300,0x8590,0x300);
        (*DAT_1000c0ec)(0x2300,0x8591,0x300);
        uVar18 = 0x2100;
      }
      (*DAT_1000c0ec)(0x2300,0x8572,uVar18);
      (*DAT_1000c0ec)(0x2300,0xd1c,1);
      (*DAT_1000c0ec)(0x2300,0x8588,0x1702);
      (*DAT_1000c0ec)(0x2300,0x8589,0x8577);
      (*DAT_1000c0ec)(0x2300,0x8598,0x302);
      (*DAT_1000c0ec)(0x2300,0x8599,0x302);
    }
    break;
  case 0x2a:
    FUN_10009a70(0x1e,(uint)(param_3 != (float *)0x0) * 8 + 0x20);
    break;
  case 0x2e:
  case 0x65:
    if (DAT_1000c12c != 0) {
      uVar12 = 0;
      do {
        iVar11 = 0x100;
        do {
          lVar1 = (longlong)
                  ROUND((float)*(ushort *)((int)&DAT_1000c130 + uVar12) *
                        _DAT_1000c750 * (float)param_3 + (float)_DAT_1000ad80);
          local_708 = (uint)lVar1;
          if (local_708 < 0x10000) {
            uVar4 = (undefined2)lVar1;
          }
          else {
            uVar4 = 0xffff;
          }
          *(undefined2 *)((int)local_640 + uVar12) = uVar4;
          uVar12 = uVar12 + 2;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      } while (uVar12 < 0x600);
      local_6d8.dwOSVersionInfoSize = 0x94;
      GetVersionExA(&local_6d8);
      if ((local_6d8.dwMajorVersion == 5) && (local_6d8.dwPlatformId == 2)) {
        puVar6 = local_542;
        iVar11 = 3;
        do {
          uVar9 = 0x8000;
          puVar7 = puVar6 + -0x7f;
          uVar12 = 0x8000;
          iVar16 = 0x80;
          do {
            if (uVar12 < *puVar7) {
              *puVar7 = uVar9;
            }
            uVar9 = uVar9 + 0x100;
            puVar7 = puVar7 + 1;
            uVar12 = uVar12 + 0x100;
            iVar16 = iVar16 + -1;
          } while (iVar16 != 0);
          if (0xfe00 < *puVar6) {
            *puVar6 = 0xfe00;
          }
          puVar6 = puVar6 + 0x100;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
      puVar6 = local_640 + 1;
      iVar11 = 3;
      do {
        iVar16 = 0xff;
        puVar7 = puVar6;
        do {
          if (*puVar7 < puVar7[-1]) {
            *puVar7 = puVar7[-1];
          }
          puVar7 = puVar7 + 1;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
        puVar6 = puVar6 + 0x100;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      SetDeviceGammaRamp(DAT_1000d86c,local_640);
    }
    break;
  case 0x2f:
    if (param_3 == (float *)0x0) {
      (*DAT_1000c050)();
      DAT_1000c794 = param_3;
    }
    else {
      (*DAT_1000c078)();
      (*DAT_1000c040)(DAT_1000c868,2,0xff);
      (*DAT_1000c034)(DAT_1000c894,DAT_1000c864,DAT_1000c790);
      DAT_1000c794 = param_3;
    }
    break;
  case 0x30:
    switch(param_3) {
    case (float *)0x0:
      DAT_1000c868 = 0x200;
      break;
    case (float *)0x1:
      DAT_1000c868 = 0x201;
      break;
    case (float *)0x2:
      DAT_1000c868 = 0x202;
      break;
    case (float *)0x3:
      DAT_1000c868 = 0x203;
      break;
    case (float *)0x4:
      DAT_1000c868 = 0x204;
      break;
    case (float *)0x5:
      DAT_1000c868 = 0x205;
      break;
    case (float *)0x6:
      DAT_1000c868 = 0x206;
      break;
    case (float *)0x7:
      DAT_1000c868 = 0x207;
      break;
    default:
      goto switchD_10005109_default;
    }
    (*DAT_1000c040)(DAT_1000c868,2,0xff);
    break;
  case 0x34:
    switch(param_3) {
    case (float *)0x0:
      DAT_1000c894 = 0x1e00;
      break;
    case (float *)0x1:
      DAT_1000c894 = 0;
      break;
    case (float *)0x2:
      DAT_1000c894 = 0x1e01;
      break;
    case (float *)0x3:
      DAT_1000c894 = 0x1e02;
      break;
    case (float *)0x4:
      DAT_1000c894 = 0x1e03;
      break;
    case (float *)0x5:
      DAT_1000c894 = 0x150a;
      break;
    case (float *)0x6:
      DAT_1000c894 = 0x8507;
      break;
    case (float *)0x7:
      DAT_1000c894 = 0x8508;
      break;
    default:
      goto switchD_10005109_default;
    }
    (*DAT_1000c034)(DAT_1000c894,DAT_1000c864,DAT_1000c790);
    break;
  case 0x35:
    switch(param_3) {
    case (float *)0x0:
      DAT_1000c864 = 0x1e00;
      break;
    case (float *)0x1:
      DAT_1000c864 = 0;
      break;
    case (float *)0x2:
      DAT_1000c864 = 0x1e01;
      break;
    case (float *)0x3:
      DAT_1000c864 = 0x1e02;
      break;
    case (float *)0x4:
      DAT_1000c864 = 0x1e03;
      break;
    case (float *)0x5:
      DAT_1000c864 = 0x150a;
      break;
    case (float *)0x6:
      DAT_1000c864 = 0x8507;
      break;
    case (float *)0x7:
      DAT_1000c864 = 0x8508;
      break;
    default:
      goto switchD_10005109_default;
    }
    (*DAT_1000c034)(DAT_1000c894,DAT_1000c864,DAT_1000c790);
    break;
  case 0x36:
    switch(param_3) {
    case (float *)0x0:
      DAT_1000c790 = 0x1e00;
      break;
    case (float *)0x1:
      DAT_1000c790 = 0;
      break;
    case (float *)0x2:
      DAT_1000c790 = 0x1e01;
      break;
    case (float *)0x3:
      DAT_1000c790 = 0x1e02;
      break;
    case (float *)0x4:
      DAT_1000c790 = 0x1e03;
      break;
    case (float *)0x5:
      DAT_1000c790 = 0x150a;
      break;
    case (float *)0x6:
      DAT_1000c790 = 0x8507;
      break;
    case (float *)0x7:
      DAT_1000c790 = 0x8508;
      break;
    default:
      goto switchD_10005109_default;
    }
    (*DAT_1000c034)(DAT_1000c894,DAT_1000c864,DAT_1000c790);
    break;
  case 0x38:
  case 0x68:
    switch(param_3) {
    case (float *)0x0:
      uVar18 = 0x302;
      DAT_1000c848 = 0x303;
      DAT_1000c7ac = 0x302;
      iVar11 = FUN_10009a20(0x194);
      if (-1 < iVar11) {
        *(undefined4 *)(&DAT_1000da48 + (uVar12 * 0x8c + iVar11) * 4) = 2;
      }
      goto LAB_10005b01;
    case (float *)0x1:
      uVar18 = 0x302;
      DAT_1000c848 = 1;
      DAT_1000c7ac = 0x302;
      iVar11 = FUN_10009a20(0x194);
      if (-1 < iVar11) {
        *(undefined4 *)(&DAT_1000da48 + (uVar12 * 0x8c + iVar11) * 4) = 2;
      }
      iVar11 = FUN_10009a20(0x195);
      uVar3 = DAT_1000c848;
      if (-1 < iVar11) {
        *(undefined4 *)(&DAT_1000da48 + (uVar12 * 0x8c + iVar11) * 4) = 0;
        (*DAT_1000c0d0)(0x302,uVar3);
        goto switchD_10005400_caseD_c;
      }
      break;
    case (float *)0x2:
      uVar18 = 0;
      DAT_1000c848 = 0x303;
      DAT_1000c7ac = 0;
      iVar11 = FUN_10009a20(0x194);
      if (-1 < iVar11) {
        *(undefined4 *)(&DAT_1000da48 + (uVar12 * 0x8c + iVar11) * 4) = 1;
      }
LAB_10005b01:
      iVar11 = FUN_10009a20(0x195);
      uVar3 = DAT_1000c848;
      if (-1 < iVar11) {
        *(undefined4 *)(&DAT_1000da48 + (uVar12 * 0x8c + iVar11) * 4) = 3;
        (*DAT_1000c0d0)(uVar18,uVar3);
        goto switchD_10005400_caseD_c;
      }
      break;
    case (float *)0x3:
      uVar18 = 0x306;
      DAT_1000c848 = 0;
      DAT_1000c7ac = 0x306;
      iVar11 = FUN_10009a20(0x194);
      if (-1 < iVar11) {
        *(undefined4 *)(&DAT_1000da48 + (uVar12 * 0x8c + iVar11) * 4) = 7;
      }
      iVar11 = FUN_10009a20(0x195);
      if (-1 < iVar11) {
        *(undefined4 *)(&DAT_1000da48 + (uVar12 * 0x8c + iVar11) * 4) = 1;
      }
      break;
    default:
      goto switchD_10005109_default;
    }
    (*DAT_1000c0d0)(uVar18,DAT_1000c848);
    break;
  case 0x39:
  case 0x6a:
    (*DAT_1000c118)();
    break;
  case 0x3b:
    DAT_1000c79c = param_3;
    break;
  case 0x40:
    switch(param_3) {
    case (float *)0x0:
      DAT_1000c004 = 0x200;
      break;
    case (float *)0x1:
      DAT_1000c004 = 0x201;
      break;
    case (float *)0x2:
      DAT_1000c004 = 0x202;
      break;
    case (float *)0x3:
      DAT_1000c004 = 0x203;
      break;
    case (float *)0x4:
      DAT_1000c004 = 0x204;
      break;
    case (float *)0x5:
      DAT_1000c004 = 0x205;
      break;
    case (float *)0x6:
      DAT_1000c004 = 0x206;
      break;
    case (float *)0x7:
      DAT_1000c004 = 0x207;
      break;
    default:
      goto switchD_10005109_default;
    }
    (*DAT_1000c0b0)(DAT_1000c004,_DAT_1000c854);
    break;
  case 0x41:
    if (param_3 == (float *)0x0) {
      DAT_1000c890 = 0x2900;
      if (DAT_1000c0b4 != 0) {
        DAT_1000c890 = 0x812f;
      }
      break;
    }
    if (param_3 != (float *)0x1) {
      if (param_3 != (float *)0x2) {
        return 0;
      }
      if (DAT_1000c04c == 0) {
        return 0;
      }
      DAT_1000c890 = 0x8370;
      break;
    }
LAB_10005712:
    DAT_1000c890 = 0x2901;
    break;
  case 0x42:
    if (param_3 == (float *)0x0) {
      DAT_1000c7a8 = 0x2900;
      if (DAT_1000c0b4 != 0) {
        DAT_1000c7a8 = 0x812f;
      }
    }
    else if (param_3 == (float *)0x1) {
      DAT_1000c7a8 = 0x2901;
    }
    else {
      if (param_3 != (float *)0x2) {
        return 0;
      }
      if (DAT_1000c04c == 0) {
        return 0;
      }
      DAT_1000c7a8 = 0x8370;
    }
    break;
  case 0x43:
    (*DAT_1000c124)((double)(float)param_3);
  }
switchD_10005400_caseD_c:
  if (local_6fc != (int *)0x0) {
    *local_6fc = (int)param_3;
  }
  if (DAT_1000d89c != (float *)0x0) {
    (*(code *)DAT_1000d89c)(iVar5,param_3);
  }
  return 1;
}



/* VA 10006890 */

void FUN_10006890(void)

{
  undefined4 uVar1;

  if ((DAT_1000c84c != 0) && (DAT_1000d85c != 0)) {
    (*DAT_1000c054)(0xde1,0x2802,DAT_1000c890);
    (*DAT_1000c054)(0xde1,0x2803,DAT_1000c7a8);
    if (DAT_1000c754 == 1) {
      (*DAT_1000c054)(0xde1,0x2800,0x2601);
      if ((DAT_1000c878 == 0) || (uVar1 = 0x2703, *(int *)(DAT_1000d85c + 0x10) == 0)) {
        uVar1 = 0x2601;
      }
    }
    else {
      if (DAT_1000c754 != 2) {
        if (DAT_1000c87c == 0) {
          (*DAT_1000c054)(0xde1,0x2800,0x2600);
          if (DAT_1000c878 == 0) {
            (*DAT_1000c054)(0xde1,0x2801,0x2600);
            return;
          }
          uVar1 = 0x2600;
          if (DAT_1000c878 != 1) {
            if (*(int *)(DAT_1000d85c + 0x10) != 0) {
              uVar1 = 0x2702;
            }
            (*DAT_1000c054)(0xde1,0x2801,uVar1);
            return;
          }
          if (*(int *)(DAT_1000d85c + 0x10) != 0) {
            uVar1 = 0x2700;
          }
          (*DAT_1000c054)(0xde1,0x2801,uVar1);
          return;
        }
        (*DAT_1000c054)(0xde1,0x2800,0x2601);
        if (DAT_1000c878 == 0) {
          (*DAT_1000c054)(0xde1,0x2801,0x2601);
          return;
        }
        uVar1 = 0x2601;
        if (DAT_1000c878 != 1) {
          if (*(int *)(DAT_1000d85c + 0x10) != 0) {
            uVar1 = 0x2703;
          }
          (*DAT_1000c054)(0xde1,0x2801,uVar1);
          return;
        }
        if (*(int *)(DAT_1000d85c + 0x10) != 0) {
          uVar1 = 0x2701;
        }
        (*DAT_1000c054)(0xde1,0x2801,uVar1);
        return;
      }
      (*DAT_1000c054)(0xde1,0x2800,0x2600);
      if ((DAT_1000c878 == 0) || (uVar1 = 0x2700, *(int *)(DAT_1000d85c + 0x10) == 0)) {
        (*DAT_1000c054)(0xde1,0x2801,0x2600);
        return;
      }
    }
    (*DAT_1000c054)(0xde1,0x2801,uVar1);
  }
  return;
}



/* VA 10006a90 */

undefined4 * _THRASH_talloc_20(uint param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  uint _Size;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  bool bVar7;
  char *pcVar8;
  undefined4 uVar9;
  char local_1a4 [400];
  char local_14 [16];

                    /* 0x6a90  35  _THRASH_talloc@20 */
  if ((param_5 & 0xffff0000) == 0) {
    if (*(int *)(DAT_1000d9d8 + param_3 * 4) == 0) {
      sprintf(local_14,"Bad color format: %d",param_3);
      if (DAT_1000d88c != (code *)0x0) {
        uVar9 = 0x96;
LAB_10006b2b:
        pcVar8 = local_14;
        goto LAB_10006b34;
      }
    }
    else if ((((param_3 == 1) || (param_3 == 2)) && (*(int *)(DAT_1000d9e0 + param_4 * 4) == 0)) &&
            (sprintf(local_14,"Bad color index format: %d",param_4), DAT_1000d88c != (code *)0x0)) {
      uVar9 = 0x9c;
      goto LAB_10006b2b;
    }
  }
  else {
    if (DAT_1000d88c == (code *)0x0) goto LAB_10006b59;
    uVar9 = 0x91;
    pcVar8 = "Multitexturing required";
LAB_10006b34:
    sprintf(local_1a4,"%s:\n%s\n\n\nFILE %s\nLINE %d","Allocate",pcVar8,
            "D:\\Work\\Tharsh\\Thrash.OpenGL.1\\Texture.cpp",uVar9);
    (*DAT_1000d88c)(0,local_1a4);
  }
LAB_10006b59:
  if (DAT_1000d894 == (code *)0x0) {
    puVar1 = malloc(0x50);
  }
  else {
    puVar1 = (undefined4 *)(*DAT_1000d894)();
  }
  if (puVar1 == (undefined4 *)0x0) {
    if (DAT_1000d88c != (code *)0x0) {
      sprintf(local_1a4,"%s:\n%s\n\n\nFILE %s\nLINE %d","Allocate","Out of memory.",
              "D:\\Work\\Tharsh\\Thrash.OpenGL.1\\Texture.cpp",0x1d6);
      (*DAT_1000d88c)(0,local_1a4);
    }
    return (undefined4 *)0x0;
  }
  (*DAT_1000c090)(1,puVar1);
  puVar1[1] = param_1;
  puVar1[2] = param_2;
  puVar1[3] = param_5 >> 0x10;
  puVar1[0x13] = DAT_1000d860;
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
  DAT_1000d860 = puVar1;
  puVar1[0xc] = _Size;
  switch(param_3) {
  case 1:
    if (param_4 == 3) {
      if (DAT_1000c760 != 0) goto LAB_10006c98;
      bVar7 = DAT_1000c0a0 != 0;
      puVar1[9] = 0x1401;
      if (bVar7) {
        puVar1[7] = 0x1900;
        puVar1[8] = 0x80e4;
        puVar1[10] = 1;
        puVar1[0xb] = 1;
        break;
      }
      puVar1[7] = 0x1907;
      puVar1[8] = 0x8051;
      puVar1[10] = 3;
    }
    else {
      if (param_4 != 4) {
        if (DAT_1000d88c == (code *)0x0) break;
        param_3 = 0xf5;
        pcVar8 = "Indexed - Bad pixel format";
        goto LAB_1000701d;
      }
      if ((DAT_1000c760 == 0) && (DAT_1000c0a0 != 0)) {
        puVar1[7] = 0x1900;
        puVar1[8] = 0x80e4;
        puVar1[9] = 0x1401;
        puVar1[10] = 1;
        puVar1[0xb] = 1;
        break;
      }
LAB_10006c98:
      puVar1[7] = 0x1908;
      puVar1[8] = 0x8058;
      puVar1[9] = 0x1401;
      puVar1[10] = 4;
    }
    _Size = _Size >> 1;
LAB_10006cb6:
    puVar1[0xb] = 0;
    goto LAB_10006cbd;
  case 2:
    if (param_4 != 3) {
      if (param_4 != 4) {
        if (DAT_1000d88c == (code *)0x0) break;
        param_3 = 0x134;
        pcVar8 = "Indexed - Bad pixel format";
        goto LAB_1000701d;
      }
      if ((DAT_1000c760 == 0) && (DAT_1000c0a0 != 0)) {
        puVar1[7] = 0x1900;
        puVar1[8] = 0x80e5;
        puVar1[9] = 0x1401;
        puVar1[10] = 1;
        puVar1[0xb] = 0;
        break;
      }
LAB_10006d8f:
      puVar1[7] = 0x80e1;
      puVar1[8] = 0x8058;
      puVar1[9] = 0x1401;
      puVar1[10] = 4;
      goto LAB_10006cb6;
    }
    if (DAT_1000c760 != 0) goto LAB_10006d8f;
    bVar7 = DAT_1000c0a0 != 0;
    puVar1[9] = 0x1401;
    puVar1[0xb] = 0;
    if (bVar7) {
      puVar1[7] = 0x1900;
      puVar1[8] = 0x80e5;
      puVar1[10] = 1;
      break;
    }
    puVar1[7] = 0x80e0;
    puVar1[8] = 0x8051;
    puVar1[10] = 3;
LAB_10006cbd:
    puVar1[0x12] = 1;
    if (DAT_1000d894 == (code *)0x0) {
      pvVar3 = malloc(_Size);
      puVar1[0xe] = pvVar3;
    }
    else {
      uVar9 = (*DAT_1000d894)();
      puVar1[0xe] = uVar9;
    }
    break;
  case 3:
    if ((DAT_1000c760 == 0) && (0x11f < DAT_1000c11c)) {
      uVar9 = 2;
      uVar4 = 0x8366;
      uVar5 = 0x8057;
      uVar6 = 0x80e1;
    }
    else {
      puVar1[0x12] = 1;
      uVar9 = 4;
      uVar4 = 0x1401;
      uVar5 = 0x8058;
      uVar6 = 0x1908;
    }
    puVar1[7] = uVar6;
    puVar1[8] = uVar5;
    puVar1[9] = uVar4;
    puVar1[10] = uVar9;
    puVar1[0xb] = 0;
    break;
  case 4:
    if (DAT_1000c760 == 0) {
      puVar1[7] = 0x1907;
      puVar1[0xb] = 0;
      if (DAT_1000c11c < 0x120) {
        puVar1[8] = 0x8051;
        puVar1[9] = 0x1401;
        puVar1[10] = 3;
        puVar1[0x12] = 1;
      }
      else {
        puVar1[8] = 0x1907;
        puVar1[9] = 0x8363;
        puVar1[10] = 2;
      }
    }
    else {
      puVar1[7] = 0x1908;
      puVar1[8] = 0x8058;
      puVar1[9] = 0x1401;
      puVar1[10] = 4;
      puVar1[0xb] = 0;
      puVar1[0x12] = 1;
    }
    break;
  case 5:
    if (DAT_1000c760 == 0) {
      puVar1[8] = 0x8051;
      puVar1[9] = 0x1401;
      puVar1[10] = 3;
      puVar1[0xb] = 0;
      if (DAT_1000c0b8 == 0) {
        puVar1[7] = 0x1907;
        puVar1[0x12] = 1;
      }
      else {
        puVar1[7] = 0x80e0;
      }
    }
    else {
      puVar1[7] = 0x1908;
      puVar1[8] = 0x8058;
      puVar1[9] = 0x1401;
      puVar1[10] = 4;
      puVar1[0xb] = 0;
      puVar1[0x12] = 1;
    }
    break;
  case 6:
    if ((DAT_1000c760 == 0) && (DAT_1000c060 != 0)) {
      uVar9 = 0x80e1;
    }
    else {
      puVar1[0x12] = 1;
      uVar9 = 0x1908;
    }
    puVar1[7] = uVar9;
    puVar1[8] = 0x8058;
    puVar1[9] = 0x1401;
    puVar1[10] = 4;
    puVar1[0xb] = 0;
    break;
  case 7:
    if ((DAT_1000c760 == 0) && (0x11f < DAT_1000c11c)) {
      uVar9 = 2;
      uVar4 = 0x8365;
      uVar5 = 0x8056;
      uVar6 = 0x80e1;
    }
    else {
      puVar1[0x12] = 1;
      uVar9 = 4;
      uVar4 = 0x1401;
      uVar5 = 0x8058;
      uVar6 = 0x1908;
    }
    puVar1[7] = uVar6;
    puVar1[8] = uVar5;
    puVar1[9] = uVar4;
    puVar1[10] = uVar9;
    puVar1[0xb] = 0;
    break;
  default:
    if (DAT_1000d88c == (code *)0x0) break;
    pcVar8 = "Bad pixel format";
LAB_1000701d:
    sprintf(local_1a4,"%s:\n%s\n\n\nFILE %s\nLINE %d","Allocate",pcVar8,
            "D:\\Work\\Tharsh\\Thrash.OpenGL.1\\Texture.cpp",param_3);
    (*DAT_1000d88c)(0,local_1a4);
  }
  if ((DAT_1000d860 == (undefined4 *)0x0) || (puVar1 < (undefined4 *)0x10)) {
    DAT_1000d85c = (undefined4 *)0x0;
  }
  else if (DAT_1000d85c != puVar1) {
    DAT_1000d85c = puVar1;
    (*DAT_1000c07c)(0xde1,*puVar1);
  }
  if (0x11f < DAT_1000c11c) {
    (*DAT_1000c054)(0xde1,0x813c,0);
    (*DAT_1000c054)(0xde1,0x813d,puVar1[4]);
  }
  uVar2 = 0;
  do {
    (*DAT_1000c0bc)(0xde1,uVar2,puVar1[8],param_1,param_2,0,puVar1[7],puVar1[9],0);
    uVar2 = uVar2 + 1;
    param_2 = param_2 >> 1;
    param_1 = param_1 >> 1;
  } while (uVar2 <= (uint)puVar1[4]);
  return puVar1;
}



/* VA 10007150 */

undefined4 * _THRASH_tupdate_12(undefined4 *param_1,ushort *param_2,undefined4 *param_3)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  uint uVar14;
  undefined1 *puVar15;
  char local_194 [400];

                    /* 0x7150  38  _THRASH_tupdate@12 */
  iVar12 = DAT_1000d858;
  if (param_3 != (undefined4 *)0x0) {
    if (DAT_1000c0a0 != (code *)0x0) {
      (*DAT_1000c0a0)(0xde1,0x8058,0x100,0x80e1,0x1401,param_3);
    }
    iVar12 = 1;
    DAT_1000d858 = 1;
    puVar10 = &DAT_1000e0d8;
    for (iVar9 = 0x100; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar10 = *param_3;
      param_3 = param_3 + 1;
      puVar10 = puVar10 + 1;
    }
  }
  if (param_2 == (ushort *)0x0) {
    return param_1;
  }
  switch(param_1[5]) {
  case 1:
    if (param_1[6] == 3) {
      if (DAT_1000c760 == 0) {
        if (param_1[0x12] == 0) break;
        if (param_2 != (ushort *)param_1[0xe]) {
          memcpy((ushort *)param_1[0xe],param_2,(uint)param_1[0xc] >> 1);
        }
        if (iVar12 == 0) goto LAB_1000736a;
        FUN_10009ae0((int)param_1);
        iVar12 = param_1[0xc];
        bVar3 = true;
        puVar6 = (undefined1 *)param_1[0xf];
        pbVar5 = (byte *)param_1[0xe];
        do {
          pbVar4 = pbVar5 + 1;
          if (bVar3) {
            pbVar4 = pbVar5;
          }
          bVar3 = (bool)(bVar3 ^ 1);
          iVar9 = (uint)*pbVar4 * 3;
          *puVar6 = *(undefined1 *)((int)&DAT_1000e0d8 + iVar9 + 2);
          puVar6[1] = *(undefined1 *)((int)&DAT_1000e0d8 + iVar9 + 1);
          puVar6[2] = *(undefined1 *)((int)&DAT_1000e0d8 + iVar9);
          iVar12 = iVar12 + -1;
          puVar6 = puVar6 + 3;
          pbVar5 = pbVar4;
        } while (iVar12 != 0);
      }
      else {
        if (param_2 != (ushort *)param_1[0xe]) {
          memcpy((ushort *)param_1[0xe],param_2,(uint)param_1[0xc] >> 1);
        }
        if (iVar12 == 0) {
LAB_1000736a:
          bVar3 = false;
          goto LAB_1000797f;
        }
        FUN_10009ae0((int)param_1);
        bVar3 = true;
        iVar12 = param_1[0xc];
        puVar6 = (undefined1 *)param_1[0xf];
        pbVar5 = (byte *)param_1[0xe];
        do {
          pbVar4 = pbVar5 + 1;
          if (bVar3) {
            pbVar4 = pbVar5;
          }
          bVar3 = (bool)(bVar3 ^ 1);
          iVar9 = (uint)*pbVar4 * 3;
          *puVar6 = *(undefined1 *)((int)&DAT_1000e0d8 + iVar9 + 2);
          puVar6[1] = *(undefined1 *)((int)&DAT_1000e0d8 + iVar9 + 1);
          puVar6[2] = *(undefined1 *)((int)&DAT_1000e0d8 + iVar9);
          puVar6[3] = 0xff;
          iVar12 = iVar12 + -1;
          puVar6 = puVar6 + 4;
          pbVar5 = pbVar4;
        } while (iVar12 != 0);
      }
    }
    else {
      if ((param_1[6] != 4) || (param_1[0x12] == 0)) break;
      if (param_2 != (ushort *)param_1[0xe]) {
        memcpy((ushort *)param_1[0xe],param_2,(uint)param_1[0xc] >> 1);
      }
      if (iVar12 == 0) goto LAB_1000736a;
      FUN_10009ae0((int)param_1);
      bVar3 = true;
      pbVar5 = (byte *)param_1[0xe];
      param_3 = (undefined4 *)param_1[0xc];
      puVar7 = (uint *)param_1[0xf];
      do {
        bVar1 = *pbVar5;
        uVar8 = bVar1 & 0xf;
        if (!bVar3) {
          pbVar5 = pbVar5 + 1;
          uVar8 = (uint)(bVar1 >> 4);
        }
        bVar3 = (bool)(bVar3 ^ 1);
        uVar8 = (&DAT_1000e0d8)[uVar8];
        param_3 = (undefined4 *)((int)param_3 + -1);
        *puVar7 = uVar8 >> 0x10 & 0xff | (uVar8 & 0xff) << 0x10 | uVar8 & 0xff00ff00;
        puVar7 = puVar7 + 1;
      } while (param_3 != (undefined4 *)0x0);
    }
    goto LAB_10007977;
  case 2:
    if (param_1[6] == 3) {
      if (DAT_1000c760 == 0) {
        if (param_1[0x12] == 0) break;
        if (param_2 != (ushort *)param_1[0xe]) {
          memcpy((ushort *)param_1[0xe],param_2,param_1[0xc]);
        }
        if (iVar12 == 0) goto LAB_1000736a;
        FUN_10009ae0((int)param_1);
        pbVar5 = (byte *)param_1[0xe];
        iVar12 = param_1[0xc];
        puVar6 = (undefined1 *)param_1[0xf];
        do {
          bVar1 = *pbVar5;
          pbVar5 = pbVar5 + 1;
          iVar9 = (uint)bVar1 * 3;
          *puVar6 = *(undefined1 *)((int)&DAT_1000e0d8 + iVar9 + 2);
          puVar6[1] = *(undefined1 *)((int)&DAT_1000e0d8 + iVar9 + 1);
          puVar6[2] = *(undefined1 *)((int)&DAT_1000e0d8 + iVar9);
          iVar12 = iVar12 + -1;
          puVar6 = puVar6 + 3;
        } while (iVar12 != 0);
      }
      else {
        if (param_2 != (ushort *)param_1[0xe]) {
          memcpy((ushort *)param_1[0xe],param_2,param_1[0xc]);
        }
        if (iVar12 == 0) goto LAB_1000736a;
        FUN_10009ae0((int)param_1);
        pbVar5 = (byte *)param_1[0xe];
        iVar12 = param_1[0xc];
        puVar6 = (undefined1 *)param_1[0xf];
        do {
          bVar1 = *pbVar5;
          pbVar5 = pbVar5 + 1;
          iVar9 = (uint)bVar1 * 3;
          *puVar6 = *(undefined1 *)((int)&DAT_1000e0d8 + iVar9 + 2);
          puVar6[1] = *(undefined1 *)((int)&DAT_1000e0d8 + iVar9 + 1);
          puVar6[2] = *(undefined1 *)((int)&DAT_1000e0d8 + iVar9);
          puVar6[3] = 0xff;
          iVar12 = iVar12 + -1;
          puVar6 = puVar6 + 4;
        } while (iVar12 != 0);
      }
    }
    else {
      if ((param_1[6] != 4) || (param_1[0x12] == 0)) break;
      if (param_2 != (ushort *)param_1[0xe]) {
        memcpy((ushort *)param_1[0xe],param_2,param_1[0xc]);
      }
      if (iVar12 == 0) goto LAB_1000736a;
      FUN_10009ae0((int)param_1);
      pbVar5 = (byte *)param_1[0xe];
      iVar12 = param_1[0xc];
      puVar10 = (undefined4 *)param_1[0xf];
      do {
        bVar1 = *pbVar5;
        pbVar5 = pbVar5 + 1;
        *puVar10 = (&DAT_1000e0d8)[bVar1];
        iVar12 = iVar12 + -1;
        puVar10 = puVar10 + 1;
      } while (iVar12 != 0);
    }
    goto LAB_10007977;
  case 3:
    if (param_1[0x12] != 0) {
      pbVar5 = (byte *)param_1[0xf];
      if (pbVar5 == (byte *)0x0) {
        if (DAT_1000d894 == (code *)0x0) {
          pbVar5 = malloc(param_1[0xc] * param_1[10]);
        }
        else {
          pbVar5 = (byte *)(*DAT_1000d894)();
        }
        param_1[0xf] = pbVar5;
        if ((pbVar5 == (byte *)0x0) && (DAT_1000d88c != (code *)0x0)) {
          sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d","Prepare","Out of memory.",
                  "D:\\Work\\Tharsh\\Thrash.Core\\Texture.cpp",0x26);
          (*DAT_1000d88c)(0,local_194);
          pbVar5 = (byte *)param_1[0xf];
        }
      }
      iVar12 = param_1[0xc];
      do {
        *pbVar5 = (byte)(*param_2 >> 7) & 0xf8;
        pbVar5[1] = (byte)(*param_2 >> 2) & 0xf8;
        pbVar5[2] = (char)*param_2 << 3;
        pbVar5[3] = *(char *)((int)param_2 + 1) >> 7;
        iVar12 = iVar12 + -1;
        pbVar5 = pbVar5 + 4;
        param_2 = param_2 + 1;
      } while (iVar12 != 0);
      goto LAB_10007977;
    }
    break;
  case 4:
    if (DAT_1000c760 == 0) {
      if (param_1[0x12] == 0) break;
      pbVar5 = (byte *)param_1[0xf];
      if (pbVar5 == (byte *)0x0) {
        if (DAT_1000d894 == (code *)0x0) {
          pbVar5 = malloc(param_1[0xc] * param_1[10]);
        }
        else {
          pbVar5 = (byte *)(*DAT_1000d894)();
        }
        param_1[0xf] = pbVar5;
        if ((pbVar5 == (byte *)0x0) && (DAT_1000d88c != (code *)0x0)) {
          sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d","Prepare","Out of memory.",
                  "D:\\Work\\Tharsh\\Thrash.Core\\Texture.cpp",0x26);
          (*DAT_1000d88c)(0,local_194);
          pbVar5 = (byte *)param_1[0xf];
        }
      }
      iVar12 = param_1[0xc];
      do {
        *pbVar5 = *(byte *)((int)param_2 + 1) & 0xf8;
        pbVar5[1] = (byte)(*param_2 >> 3) & 0xf0;
        pbVar5[2] = (char)*param_2 << 3;
        iVar12 = iVar12 + -1;
        pbVar5 = pbVar5 + 3;
        param_2 = param_2 + 1;
      } while (iVar12 != 0);
    }
    else {
      pbVar5 = (byte *)param_1[0xf];
      if (pbVar5 == (byte *)0x0) {
        if (DAT_1000d894 == (code *)0x0) {
          pbVar5 = malloc(param_1[0xc] * param_1[10]);
        }
        else {
          pbVar5 = (byte *)(*DAT_1000d894)();
        }
        param_1[0xf] = pbVar5;
        if ((pbVar5 == (byte *)0x0) && (DAT_1000d88c != (code *)0x0)) {
          sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d","Prepare","Out of memory.",
                  "D:\\Work\\Tharsh\\Thrash.Core\\Texture.cpp",0x26);
          (*DAT_1000d88c)(0,local_194);
          pbVar5 = (byte *)param_1[0xf];
        }
      }
      iVar12 = param_1[0xc];
      do {
        *pbVar5 = *(byte *)((int)param_2 + 1) & 0xf8;
        pbVar5[1] = (byte)(*param_2 >> 3) & 0xf0;
        pbVar5[2] = (char)*param_2 << 3;
        pbVar5[3] = 0xff;
        iVar12 = iVar12 + -1;
        pbVar5 = pbVar5 + 4;
        param_2 = param_2 + 1;
      } while (iVar12 != 0);
    }
    goto LAB_10007977;
  case 5:
    if (DAT_1000c760 == 0) {
      if (param_1[0x12] == 0) break;
      puVar6 = (undefined1 *)param_1[0xf];
      if (puVar6 == (undefined1 *)0x0) {
        if (DAT_1000d894 == (code *)0x0) {
          puVar6 = malloc(param_1[0xc] * param_1[10]);
        }
        else {
          puVar6 = (undefined1 *)(*DAT_1000d894)();
        }
        param_1[0xf] = puVar6;
        if ((puVar6 == (undefined1 *)0x0) && (DAT_1000d88c != (code *)0x0)) {
          sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d","Prepare","Out of memory.",
                  "D:\\Work\\Tharsh\\Thrash.Core\\Texture.cpp",0x26);
          (*DAT_1000d88c)(0,local_194);
          puVar6 = (undefined1 *)param_1[0xf];
        }
      }
      iVar12 = param_1[0xc];
      puVar15 = (undefined1 *)((int)param_2 + 1);
      do {
        *puVar6 = puVar15[1];
        puVar6[1] = *puVar15;
        puVar6[2] = puVar15[-1];
        iVar12 = iVar12 + -1;
        puVar6 = puVar6 + 3;
        puVar15 = puVar15 + 3;
      } while (iVar12 != 0);
    }
    else {
      puVar6 = (undefined1 *)param_1[0xf];
      if (puVar6 == (undefined1 *)0x0) {
        if (DAT_1000d894 == (code *)0x0) {
          puVar6 = malloc(param_1[0xc] * param_1[10]);
        }
        else {
          puVar6 = (undefined1 *)(*DAT_1000d894)();
        }
        param_1[0xf] = puVar6;
        if ((puVar6 == (undefined1 *)0x0) && (DAT_1000d88c != (code *)0x0)) {
          sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d","Prepare","Out of memory.",
                  "D:\\Work\\Tharsh\\Thrash.Core\\Texture.cpp",0x26);
          (*DAT_1000d88c)(0,local_194);
          puVar6 = (undefined1 *)param_1[0xf];
        }
      }
      iVar12 = param_1[0xc];
      puVar15 = (undefined1 *)((int)param_2 + 1);
      do {
        *puVar6 = puVar15[1];
        puVar6[1] = *puVar15;
        puVar6[2] = puVar15[-1];
        puVar6[3] = 0xff;
        iVar12 = iVar12 + -1;
        puVar6 = puVar6 + 4;
        puVar15 = puVar15 + 3;
      } while (iVar12 != 0);
    }
LAB_10007977:
    param_2 = (ushort *)param_1[0xf];
    break;
  case 6:
    if (param_1[0x12] != 0) {
      puVar7 = (uint *)param_1[0xf];
      if (puVar7 == (uint *)0x0) {
        if (DAT_1000d894 == (code *)0x0) {
          puVar7 = malloc(param_1[0xc] * param_1[10]);
        }
        else {
          puVar7 = (uint *)(*DAT_1000d894)();
        }
        param_1[0xf] = puVar7;
        if ((puVar7 == (uint *)0x0) && (DAT_1000d88c != (code *)0x0)) {
          sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d","Prepare","Out of memory.",
                  "D:\\Work\\Tharsh\\Thrash.Core\\Texture.cpp",0x26);
          (*DAT_1000d88c)(0,local_194);
          puVar7 = (uint *)param_1[0xf];
        }
      }
      iVar12 = param_1[0xc];
      puVar13 = puVar7;
      do {
        uVar8 = *(uint *)((int)puVar13 + ((int)param_2 - (int)puVar7));
        *puVar13 = uVar8 >> 0x10 & 0xff | (uVar8 & 0xff) << 0x10 | uVar8 & 0xff00ff00;
        iVar12 = iVar12 + -1;
        puVar13 = puVar13 + 1;
      } while (iVar12 != 0);
      goto LAB_10007977;
    }
    break;
  case 7:
    if (param_1[0x12] != 0) {
      puVar7 = (uint *)param_1[0xf];
      if (puVar7 == (uint *)0x0) {
        if (DAT_1000d894 == (code *)0x0) {
          puVar7 = malloc(param_1[0xc] * param_1[10]);
        }
        else {
          puVar7 = (uint *)(*DAT_1000d894)();
        }
        param_1[0xf] = puVar7;
        if ((puVar7 == (uint *)0x0) && (DAT_1000d88c != (code *)0x0)) {
          sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d","Prepare","Out of memory.",
                  "D:\\Work\\Tharsh\\Thrash.Core\\Texture.cpp",0x26);
          (*DAT_1000d88c)(0,local_194);
          puVar7 = (uint *)param_1[0xf];
        }
      }
      iVar12 = param_1[0xc];
      do {
        uVar2 = *param_2;
        uVar8 = (uint)uVar2;
        param_2 = param_2 + 1;
        *puVar7 = (((uVar8 & 0xf) << 4 | uVar8 & 0xfffff000) << 8 | uVar8 & 0xf0) << 8 |
                  uVar2 >> 4 & 0xf0;
        iVar12 = iVar12 + -1;
        puVar7 = puVar7 + 1;
      } while (iVar12 != 0);
      goto LAB_10007977;
    }
  }
  bVar3 = true;
LAB_1000797f:
  if ((DAT_1000d860 == 0) || (param_1 < (undefined4 *)0x10)) {
    DAT_1000d85c = (undefined4 *)0x0;
  }
  else if (DAT_1000d85c != param_1) {
    DAT_1000d85c = param_1;
    (*DAT_1000c07c)(0xde1,*param_1);
  }
  if (bVar3) {
    uVar8 = param_1[2];
    uVar14 = param_1[1];
    param_3 = (undefined4 *)0x0;
    do {
      (*DAT_1000c0c4)(0xde1,param_3,0,0,uVar14,uVar8,param_1[7],param_1[9],param_2);
      iVar12 = param_1[10] * uVar8;
      uVar8 = uVar8 >> 1;
      uVar11 = iVar12 * uVar14;
      uVar14 = uVar14 >> 1;
      param_2 = (ushort *)((int)param_2 + (uVar11 >> ((byte)param_1[0xb] & 0x1f)));
      param_3 = (undefined4 *)((int)param_3 + 1);
    } while (param_3 <= (undefined4 *)param_1[4]);
  }
  return param_1;
}



/* VA 10007a40 */

void _THRASH_settexture_4(float *param_1)

{
                    /* 0x7a40  32  _THRASH_settexture@4 */
  FUN_10005080(1,0,param_1);
  return;
}



/* VA 10007a60 */

undefined4 _THRASH_tfree_4(int param_1)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  void *_Memory;

                    /* 0x7a60  36  _THRASH_tfree@4 */
  if (DAT_1000d860 != 0) {
    if (DAT_1000d85c == param_1) {
      FUN_10005080(1,0,(float *)0x0);
    }
    iVar2 = DAT_1000d860;
    if (DAT_1000d860 == param_1) {
      DAT_1000d860 = *(int *)(param_1 + 0x4c);
      (*DAT_1000c088)(1,param_1);
      pcVar3 = free_exref;
      _Memory = *(void **)(param_1 + 0x38);
      if (_Memory != (void *)0x0) {
        if (DAT_1000d898 == (code *)0x0) {
LAB_10007b02:
          pcVar3 = free_exref;
          free(_Memory);
        }
        else {
          (*DAT_1000d898)();
        }
      }
LAB_10007b07:
      if (*(int *)(param_1 + 0x3c) != 0) {
        if (DAT_1000d898 == (code *)0x0) {
          (*pcVar3)(*(int *)(param_1 + 0x3c));
        }
        else {
          (*DAT_1000d898)();
        }
      }
      if (*(int *)(param_1 + 0x40) != 0) {
        if (DAT_1000d898 == (code *)0x0) {
          (*pcVar3)(*(int *)(param_1 + 0x40));
        }
        else {
          (*DAT_1000d898)();
        }
      }
      if (DAT_1000d898 != (code *)0x0) {
        (*DAT_1000d898)();
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
        (*DAT_1000c088)(1,param_1);
        pcVar3 = free_exref;
        _Memory = *(void **)(param_1 + 0x38);
        if (_Memory == (void *)0x0) goto LAB_10007b07;
        if (DAT_1000d898 == (code *)0x0) goto LAB_10007b02;
        (*DAT_1000d898)();
        goto LAB_10007b07;
      }
    } while (iVar2 != 0);
  }
  return 0;
}



/* VA 10007b70 */

undefined4 _THRASH_treset_0(void)

{
  void *pvVar1;
  void *_Memory;

                    /* 0x7b70  37  _THRASH_treset@0 */
  if (DAT_1000d860 != 0) {
    FUN_10005080(1,0,(float *)0x0);
    _Memory = (void *)DAT_1000d860;
    do {
      pvVar1 = *(void **)((int)_Memory + 0x4c);
      (*DAT_1000c088)(1,_Memory);
      if (*(void **)((int)_Memory + 0x38) != (void *)0x0) {
        if (DAT_1000d898 == (code *)0x0) {
          free(*(void **)((int)_Memory + 0x38));
        }
        else {
          (*DAT_1000d898)();
        }
      }
      if (*(void **)((int)_Memory + 0x3c) != (void *)0x0) {
        if (DAT_1000d898 == (code *)0x0) {
          free(*(void **)((int)_Memory + 0x3c));
        }
        else {
          (*DAT_1000d898)();
        }
      }
      if (*(void **)((int)_Memory + 0x40) != (void *)0x0) {
        if (DAT_1000d898 == (code *)0x0) {
          free(*(void **)((int)_Memory + 0x40));
        }
        else {
          (*DAT_1000d898)();
        }
      }
      if (DAT_1000d898 == (code *)0x0) {
        free(_Memory);
      }
      else {
        (*DAT_1000d898)();
      }
      _Memory = pvVar1;
    } while (pvVar1 != (void *)0x0);
    DAT_1000d860 = 0;
  }
  return 1;
}



/* VA 10007c30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_10007c30(undefined4 *param_1)

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
      goto LAB_10007c75;
    }
    uVar6 = 0x80e1;
  }
  uVar5 = 0x1401;
LAB_10007c75:
  if ((DAT_1000c818 == *DAT_1000d84c) && (DAT_1000c81c == DAT_1000d84c[1])) {
    (*DAT_1000c0d8)(0,0,uVar9,param_1[4],uVar6,uVar5,*param_1);
  }
  else {
    fVar2 = (float)(int)uVar9;
    if ((int)uVar9 < 0) {
      fVar2 = fVar2 + _DAT_1000ada0;
    }
    dVar1 = (double)(fVar2 * _DAT_1000c840);
    dVar8 = floor((double)(fVar2 * _DAT_1000c840));
    if (dVar8 + _DAT_1000ad80 <= dVar1) {
      dVar8 = ceil(dVar1);
    }
    local_48 = (int)(longlong)ROUND(dVar8);
    iVar4 = local_48;
    fVar2 = (float)(int)param_1[4];
    if ((int)param_1[4] < 0) {
      fVar2 = fVar2 + _DAT_1000ada0;
    }
    dVar1 = (double)(fVar2 * _DAT_1000c844);
    dVar8 = floor((double)(fVar2 * _DAT_1000c844));
    if (dVar8 + _DAT_1000ad80 <= dVar1) {
      dVar8 = ceil(dVar1);
    }
    local_48 = (int)(longlong)ROUND(dVar8);
    if (DAT_1000d894 == (code *)0x0) {
      _Memory = malloc(local_48 * iVar4 * uVar3);
    }
    else {
      _Memory = (void *)(*DAT_1000d894)();
    }
    (*DAT_1000c0d8)(0,0,iVar4,local_48,uVar6);
    puVar7 = (undefined4 *)*param_1;
    if (iStack_74 == 4) {
      uStack_70 = 0;
      if (param_1[4] != 0) {
        uVar9 = param_1[3];
        do {
          fVar2 = (float)(int)uStack_70;
          if ((int)uStack_70 < 0) {
            fVar2 = fVar2 + _DAT_1000ada0;
          }
          dVar1 = (double)(fVar2 * _DAT_1000c844);
          dVar8 = floor((double)(fVar2 * _DAT_1000c844));
          if (dVar8 + _DAT_1000ad80 <= dVar1) {
            dVar8 = ceil(dVar1);
          }
          uVar3 = 0;
          local_64 = (int)(longlong)ROUND(dVar8);
          if (uVar9 != 0) {
            do {
              fVar2 = (float)(int)uVar3;
              if ((int)uVar3 < 0) {
                fVar2 = fVar2 + _DAT_1000ada0;
              }
              dVar1 = (double)(fVar2 * _DAT_1000c840);
              dVar8 = floor((double)(fVar2 * _DAT_1000c840));
              if (dVar8 + _DAT_1000ad80 <= dVar1) {
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
            fVar2 = fVar2 + _DAT_1000ada0;
          }
          dVar1 = (double)(fVar2 * _DAT_1000c844);
          dVar8 = floor((double)(fVar2 * _DAT_1000c844));
          if (dVar8 + _DAT_1000ad80 <= dVar1) {
            dVar8 = ceil(dVar1);
          }
          uVar3 = 0;
          local_64 = (int)(longlong)ROUND(dVar8);
          iVar4 = local_64 * unaff_EBX;
          if (uStack_70 != 0) {
            do {
              fVar2 = (float)(int)uVar3;
              if ((int)uVar3 < 0) {
                fVar2 = fVar2 + _DAT_1000ada0;
              }
              dVar1 = (double)(fVar2 * _DAT_1000c840);
              dVar8 = floor((double)(fVar2 * _DAT_1000c840));
              if (dVar8 + _DAT_1000ad80 <= dVar1) {
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
    if (DAT_1000d898 == (code *)0x0) {
      free(_Memory);
    }
    else {
      (*DAT_1000d898)();
    }
  }
  FUN_100032b0(param_1[3],param_1[4],(undefined4 *)*param_1,iStack_74);
  return;
}



/* VA 100080e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_100080e0(float *param_1)

{
  float fVar1;
  float *pfVar2;
  void *pvVar3;
  int iVar4;
  float *_Size;
  uint uVar5;
  ushort *unaff_EBX;
  ushort *_Dst;
  float *pfVar6;
  uint uVar7;
  bool bVar9;
  undefined4 uVar10;
  uint uVar11;
  float fStack_26c;
  float fStack_268;
  size_t sStack_260;
  float *pfStack_25c;
  float *pfStack_258;
  float *pfStack_24c;
  float *pfStack_248;
  float *pfStack_244;
  float *pfStack_240;
  float *pfStack_23c;
  float *pfStack_238;
  undefined4 *puStack_234;
  int iStack_22c;
  float *local_228;
  float afStack_224 [2];
  int local_21c;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 uStack_20c;
  float fStack_208;
  float afStack_204 [6];
  undefined4 uStack_1ec;
  float fStack_1e8;
  float afStack_1e4 [6];
  undefined4 uStack_1cc;
  float fStack_1c8;
  float afStack_1c4 [6];
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  char local_198 [404];
  float fVar8;

  fVar1 = (float)((uint)param_1[1] / (uint)param_1[3]);
  if (fVar1 == 4.2039e-45) {
    iVar4 = 5;
  }
  else if (fVar1 == 5.60519e-45) {
    iVar4 = 6;
  }
  else {
    iVar4 = 4;
  }
  afStack_224[1] = fVar1;
  pfVar2 = (float *)_THRASH_talloc_20(DAT_1000d9bc,DAT_1000d9c8,iVar4,0,0);
  local_228 = pfVar2;
  if (pfVar2 == (float *)0x0) {
    if (DAT_1000d88c == (code *)0x0) {
      return;
    }
    uVar10 = 0xe8;
  }
  else {
    local_21c = (int)fVar1 * DAT_1000d9bc;
    _Size = (float *)(local_21c * DAT_1000d9c8);
    if (DAT_1000d894 == (code *)0x0) {
      pvVar3 = malloc((size_t)_Size);
    }
    else {
      pvVar3 = (void *)(*DAT_1000d894)();
    }
    if (pvVar3 != (void *)0x0) {
      pfStack_24c = (float *)FUN_10009a20(1);
      if (-1 < (int)pfStack_24c) {
        pfStack_24c = *(float **)(&DAT_1000da48 + (int)pfStack_24c * 4);
      }
      pfStack_248 = (float *)FUN_10009a20(6);
      if (-1 < (int)pfStack_248) {
        pfStack_248 = *(float **)(&DAT_1000da48 + (int)pfStack_248 * 4);
      }
      pfStack_244 = (float *)FUN_10009a20(0x2a);
      if (-1 < (int)pfStack_244) {
        pfStack_244 = *(float **)(&DAT_1000da48 + (int)pfStack_244 * 4);
      }
      pfStack_240 = (float *)FUN_10009a20(2);
      if (-1 < (int)pfStack_240) {
        pfStack_240 = *(float **)(&DAT_1000da48 + (int)pfStack_240 * 4);
      }
      pfStack_23c = (float *)FUN_10009a20(0xd);
      if (-1 < (int)pfStack_23c) {
        pfStack_23c = *(float **)(&DAT_1000da48 + (int)pfStack_23c * 4);
      }
      pfStack_238 = (float *)FUN_10009a20(0xb);
      if (-1 < (int)pfStack_238) {
        pfStack_238 = *(float **)(&DAT_1000da48 + (int)pfStack_238 * 4);
      }
      puStack_234 = (undefined4 *)FUN_10009a20(10);
      if (-1 < (int)puStack_234) {
        puStack_234 = *(undefined4 **)(&DAT_1000da48 + (int)puStack_234 * 4);
      }
      FUN_10009a20(4);
      iStack_22c = FUN_10009a20(0x29);
      if (-1 < iStack_22c) {
        iStack_22c = *(int *)(&DAT_1000da48 + iStack_22c * 4);
      }
      FUN_10005080(1,0,pfVar2);
      FUN_10005080(6,0,(float *)0x0);
      FUN_10005080(0x2a,0,(float *)0x0);
      FUN_10005080(2,0,(float *)0x0);
      FUN_10005080(0xd,0,(float *)0x0);
      FUN_10005080(0xb,0,(float *)0x0);
      FUN_10005080(10,0,(float *)0x0);
      FUN_10005080(4,0,(float *)0x0);
      (*DAT_1000c0ec)(0x2300,0x2200,0x1e01);
      uStack_214 = 0xff000000;
      local_21c = 0;
      uStack_218 = 0x3f800000;
      uStack_20c = 0;
      fStack_208 = 0.0;
      pfVar2 = afStack_224;
      pfVar6 = afStack_204;
      for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
        *pfVar6 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar6 = pfVar6 + 1;
      }
      uStack_1ec = 0x3f800000;
      fStack_1e8 = 0.0;
      pfVar2 = afStack_224;
      pfVar6 = afStack_1e4;
      for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
        *pfVar6 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar6 = pfVar6 + 1;
      }
      uStack_1cc = 0x3f800000;
      fStack_1c8 = 1.0;
      pfVar2 = afStack_224;
      pfVar6 = afStack_1c4;
      for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
        *pfVar6 = *pfVar2;
        pfVar2 = pfVar2 + 1;
        pfVar6 = pfVar6 + 1;
      }
      fVar1 = param_1[4];
      uStack_1ac = 0;
      uStack_1a8 = 0x3f800000;
      fStack_26c = 0.0;
      uVar7 = DAT_1000d9c8;
      pfVar2 = param_1;
      if (fVar1 != 0.0) {
        do {
          fVar8 = pfVar2[3];
          uVar5 = (int)fVar1 - (int)fStack_26c;
          if (uVar7 < (uint)((int)fVar1 - (int)fStack_26c)) {
            uVar5 = uVar7;
          }
          fStack_268 = 0.0;
          if (fVar8 != 0.0) {
            fVar1 = (float)(int)fStack_26c;
            if ((int)fStack_26c < 0) {
              fVar1 = fVar1 + _DAT_1000ada0;
            }
            do {
              uVar7 = (int)fVar8 - (int)fStack_268;
              bVar9 = uVar7 == DAT_1000d9bc;
              if (DAT_1000d9bc < uVar7) {
                bVar9 = uVar5 == DAT_1000d9c8;
                uVar7 = DAT_1000d9bc;
              }
              if (!bVar9) {
                memset(unaff_EBX,0,sStack_260);
              }
              pvVar3 = (void *)((int)pfVar2[1] * (int)fStack_26c + (int)fStack_268 * iStack_22c +
                               (int)*pfVar2);
              if (uVar5 != 0) {
                _Dst = unaff_EBX;
                uVar11 = uVar5;
                do {
                  memcpy(_Dst,pvVar3,uVar7 * iStack_22c);
                  _Dst = (ushort *)((int)_Dst + (int)local_228);
                  pvVar3 = (void *)((int)pvVar3 + (int)pfStack_25c[1]);
                  uVar11 = uVar11 - 1;
                } while (uVar11 != 0);
              }
              _THRASH_tupdate_12(puStack_234,unaff_EBX,(undefined4 *)0x0);
              afStack_224[0] = (float)(int)fStack_268;
              if ((int)fStack_268 < 0) {
                afStack_224[0] = afStack_224[0] + _DAT_1000ada0;
              }
              afStack_204[0] = (float)(int)(DAT_1000d9bc + (int)fStack_268);
              if ((int)(DAT_1000d9bc + (int)fStack_268) < 0) {
                afStack_204[0] = afStack_204[0] + _DAT_1000ada0;
              }
              afStack_1e4[1] = (float)(int)(DAT_1000d9c8 + (int)fStack_26c);
              if ((int)(DAT_1000d9c8 + (int)fStack_26c) < 0) {
                afStack_1e4[1] = afStack_1e4[1] + _DAT_1000ada0;
              }
              afStack_224[1] = fVar1;
              afStack_204[1] = fVar1;
              afStack_1e4[0] = afStack_204[0];
              afStack_1c4[0] = afStack_224[0];
              afStack_1c4[1] = afStack_1e4[1];
              FUN_10006890();
              (*DAT_1000c120)(6);
              if (DAT_1000c7a4 == 0) {
                FUN_10009370((float *)&local_228);
                FUN_10009370(&fStack_208);
                FUN_10009370(&fStack_1e8);
                FUN_10009370(&fStack_1c8);
              }
              else {
                FUN_100094c0((float *)&local_228);
                FUN_100094c0(&fStack_208);
                FUN_100094c0(&fStack_1e8);
                FUN_100094c0(&fStack_1c8);
              }
              (*DAT_1000c10c)();
              fStack_268 = (float)((int)fStack_268 + DAT_1000d9bc);
              fVar8 = pfStack_25c[3];
              uVar7 = DAT_1000d9c8;
              pfVar2 = pfStack_25c;
            } while ((uint)fStack_268 < (uint)fVar8);
          }
          fVar1 = pfVar2[4];
          fStack_26c = (float)((int)fStack_26c + uVar7);
        } while ((uint)fStack_26c < (uint)fVar1);
      }
      (*DAT_1000c064)();
      FUN_10005080(1,0,pfStack_258);
      FUN_10005080(6,0,_Size);
      FUN_10005080(0x2a,0,param_1);
      FUN_10005080(2,0,pfStack_24c);
      FUN_10005080(0xd,0,pfStack_248);
      FUN_10005080(0xb,0,pfStack_244);
      FUN_10005080(10,0,pfStack_240);
      FUN_10005080(4,0,pfStack_23c);
      FUN_10005080(0x29,0xffff0000,pfStack_238);
      if (DAT_1000d898 == (code *)0x0) {
        free(unaff_EBX);
        _THRASH_tfree_4((int)puStack_234);
        return;
      }
      (*DAT_1000d898)();
      _THRASH_tfree_4((int)pfStack_238);
      return;
    }
    _THRASH_tfree_4((int)pfVar2);
    if (DAT_1000d88c == (code *)0x0) {
      return;
    }
    uVar10 = 0xe4;
  }
  sprintf(local_198,"%s:\n%s\n\n\nFILE %s\nLINE %d","Write","Out of memory.",
          "D:\\Work\\Tharsh\\Thrash.OpenGL.1\\Window.cpp",uVar10);
  (*DAT_1000d88c)(0,local_198);
  return;
}



/* VA 10008730 */

void _THRASH_clearwindow_0(void)

{
  uint uVar1;

                    /* 0x8730  2  _THRASH_clearwindow@0 */
  uVar1 = 0;
  if (DAT_1000c7a0 != 0) {
    uVar1 = 0x100;
  }
  if (DAT_1000c794 != 0) {
    uVar1 = uVar1 | 0x400;
  }
  if (DAT_1000c858 != 0) {
    uVar1 = uVar1 | 0x4000;
  }
  (*DAT_1000c0d4)(uVar1);
  return;
}



/* VA 10008770 */

void _THRASH_flushwindow_0(void)

{
                    /* WARNING: Could not recover jumptable at 0x10008770. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                    /* 0x8770  21  _THRASH_flushwindow@0 */
  (*DAT_1000c064)();
  return;
}



/* VA 10008780 */

undefined4 _THRASH_window_4(float *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;

                    /* 0x8780  40  _THRASH_window@4 */
  if (DAT_1000c814 != 0) {
    DAT_1000c814 = 0;
    (*DAT_1000c0f8)(DAT_1000c820,DAT_1000c824,DAT_1000c828,DAT_1000c82c);
    uVar4 = DAT_1000c88c;
    uVar3 = DAT_1000c888;
    iVar2 = DAT_1000c884;
    uVar1 = DAT_1000c880;
    DAT_1000c880 = 0;
    DAT_1000c884 = 0;
    DAT_1000c888 = 0;
    DAT_1000c88c = 0;
    _THRASH_clip_16(uVar1,iVar2,uVar3,uVar4);
  }
  FUN_10005080(0x3b,0,param_1);
  switch(param_1) {
  case (float *)0x0:
  case (float *)0x1:
    uVar5 = 0x404;
    DAT_1000c858 = 1;
    goto LAB_1000885f;
  case (float *)0x2:
    DAT_1000c858 = 1;
    break;
  case (float *)0x3:
    if (0 < DAT_1000c0cc) {
      uVar5 = 0x409;
      DAT_1000c858 = 1;
      goto LAB_1000885f;
    }
    DAT_1000c858 = 0;
    break;
  default:
    return 0;
  }
  uVar5 = 0x405;
LAB_1000885f:
  (*DAT_1000c030)(uVar5);
  (*DAT_1000c084)(uVar5);
  return 1;
}



/* VA 100088a0 */

float * _THRASH_lockwindow_0(void)

{
  float fVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  void *pvVar5;
  uint uVar6;
  bool bVar7;
  undefined4 uVar8;
  char local_198 [404];

                    /* 0x88a0  26  _THRASH_lockwindow@0 */
  if ((DAT_1000c798 != 0) && (DAT_1000d88c != (code *)0x0)) {
    sprintf(local_198,"%s:\n%s\n\n\nFILE %s\nLINE %d",&DAT_1000ab68,"Lock called while locked",
            "D:\\Work\\Tharsh\\Thrash.OpenGL.1\\Window.cpp",0x137);
    (*DAT_1000d88c)(0,local_198);
  }
  DAT_1000c798 = 1;
  if (DAT_1000d888 != (code *)0x0) {
    (*DAT_1000d888)(1);
  }
  if (DAT_1000d894 == (code *)0x0) {
    pfVar3 = malloc(0x1c);
  }
  else {
    pfVar3 = (float *)(*DAT_1000d894)();
  }
  pfVar2 = DAT_1000d84c;
  if (pfVar3 == (float *)0x0) {
    if (DAT_1000d88c == (code *)0x0) {
      return (float *)0x0;
    }
    uVar8 = 0x168;
  }
  else {
    bVar7 = DAT_1000c75c == 0;
    fVar4 = *DAT_1000d84c;
    pfVar3[3] = fVar4;
    fVar1 = pfVar2[1];
    pfVar3[4] = fVar1;
    if (bVar7) {
      uVar6 = (uint)pfVar2[2] >> 3;
    }
    else {
      uVar6 = 2;
    }
    fVar4 = (float)((int)fVar4 * uVar6);
    pfVar3[1] = fVar4;
    if (DAT_1000d894 == (code *)0x0) {
      pvVar5 = malloc((int)fVar4 * (int)fVar1);
    }
    else {
      pvVar5 = (void *)(*DAT_1000d894)();
    }
    if (pvVar5 != (void *)0x0) {
      bVar7 = DAT_1000c75c == 0;
      *pfVar3 = (float)pvVar5;
      pfVar3[5] = DAT_1000c79c;
      pfVar3[6] = 1.4013e-45;
      if (bVar7) {
        if (DAT_1000d84c[2] == 3.36312e-44) {
          pfVar3[2] = 7.00649e-45;
        }
        else {
          pfVar3[2] = (float)((uint)(DAT_1000d84c[2] == 4.48416e-44) * 2 + 4);
        }
      }
      else {
        pfVar3[2] = 5.60519e-45;
      }
      FUN_10007c30(pfVar3);
      FUN_10005080(0x1d,0,pfVar3);
      return pfVar3;
    }
    if (DAT_1000d88c == (code *)0x0) {
      return pfVar3;
    }
    uVar8 = 0x165;
  }
  sprintf(local_198,"%s:\n%s\n\n\nFILE %s\nLINE %d",&DAT_1000ab68,"Out of memory.",
          "D:\\Work\\Tharsh\\Thrash.OpenGL.1\\Window.cpp",uVar8);
  (*DAT_1000d88c)(0,local_198);
  return pfVar3;
}



/* VA 10008a40 */

undefined4 _THRASH_unlockwindow_4(float *param_1)

{
                    /* 0x8a40  39  _THRASH_unlockwindow@4 */
  if (DAT_1000c798 != 0) {
    FUN_100080e0(param_1);
    DAT_1000c798 = 0;
    if (DAT_1000d888 != (code *)0x0) {
      (*DAT_1000d888)(0);
    }
  }
  return 1;
}



/* VA 10008a80 */

void _THRASH_drawline_8(float *param_1,float *param_2)

{
                    /* 0x8a80  4  _THRASH_drawline@8 */
  (*DAT_1000c120)(1);
  if (DAT_1000c7a4 == 0) {
    FUN_10009370(param_1);
    FUN_10009370(param_2);
    (*DAT_1000c10c)();
    return;
  }
  FUN_100094c0(param_1);
  FUN_100094c0(param_2);
  (*DAT_1000c10c)();
  return;
}



/* VA 10008ad0 */

void _THRASH_drawlinestrip_8(int param_1,float *param_2)

{
  int iVar1;

                    /* 0x8ad0  7  _THRASH_drawlinestrip@8 */
  if (param_1 != 0) {
    FUN_10006890();
    iVar1 = param_1 + 1;
    (*DAT_1000c120)(3);
    if (DAT_1000c7a4 == 0) {
      do {
        FUN_10009370(param_2);
        param_2 = param_2 + 8;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      (*DAT_1000c10c)();
      return;
    }
    do {
      FUN_100094c0(param_2);
      param_2 = param_2 + 10;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    (*DAT_1000c10c)();
  }
  return;
}



/* VA 10008b30 */

void _THRASH_drawlinestrip_12(int param_1,int param_2,int *param_3)

{
                    /* 0x8b30  6  _THRASH_drawlinestrip@12 */
  FUN_10009660(3,1,param_1,param_2,param_3);
  return;
}



/* VA 10008b50 */

void _THRASH_drawlinemesh_12(int param_1,int param_2,int *param_3)

{
                    /* 0x8b50  5  _THRASH_drawlinemesh@12 */
  FUN_10009660(1,0,param_1 * 2,param_2,param_3);
  return;
}



/* VA 10008b70 */

void _THRASH_drawpoint_4(float *param_1)

{
                    /* 0x8b70  8  _THRASH_drawpoint@4 */
  (*DAT_1000c120)(0);
  if (DAT_1000c7a4 == 0) {
    FUN_10009370(param_1);
    (*DAT_1000c10c)();
    return;
  }
  FUN_100094c0(param_1);
  (*DAT_1000c10c)();
  return;
}



/* VA 10008bb0 */

void _THRASH_drawpointstrip_8(int param_1,float *param_2)

{
                    /* 0x8bb0  10  _THRASH_drawpointstrip@8 */
  if (param_1 != 0) {
    FUN_10006890();
    (*DAT_1000c120)(0);
    if (DAT_1000c7a4 == 0) {
      do {
        FUN_10009370(param_2);
        param_2 = param_2 + 8;
        param_1 = param_1 + -1;
      } while (param_1 != 0);
      (*DAT_1000c10c)();
      return;
    }
    do {
      FUN_100094c0(param_2);
      param_2 = param_2 + 10;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
    (*DAT_1000c10c)();
  }
  return;
}



/* VA 10008c10 */

void _THRASH_drawpointmesh_12(int param_1,int param_2,int *param_3)

{
                    /* 0x8c10  9  _THRASH_drawpointmesh@12 */
  FUN_10009660(0,0,param_1,param_2,param_3);
  return;
}



/* VA 10008c30 */

void _THRASH_drawquad_16(float *param_1,float *param_2,float *param_3,float *param_4)

{
                    /* 0x8c30  11  _THRASH_drawquad@16 */
  FUN_10006890();
  (*DAT_1000c120)(6);
  if (DAT_1000c7a4 == 0) {
    FUN_10009370(param_1);
    FUN_10009370(param_2);
    FUN_10009370(param_3);
    FUN_10009370(param_4);
    (*DAT_1000c10c)();
    return;
  }
  FUN_100094c0(param_1);
  FUN_100094c0(param_2);
  FUN_100094c0(param_3);
  FUN_100094c0(param_4);
  (*DAT_1000c10c)();
  return;
}



/* VA 10008ca0 */

void _THRASH_drawquadmesh_12(int param_1,int param_2,int *param_3)

{
  float *pfVar1;
  float *pfVar2;

                    /* 0x8ca0  12  _THRASH_drawquadmesh@12 */
  if (param_1 != 0) {
    FUN_10006890();
    (*DAT_1000c120)(4);
    if (DAT_1000c7a4 == 0) {
      do {
        pfVar1 = (float *)(*param_3 * 0x20 + param_2);
        FUN_10009370(pfVar1);
        FUN_10009370((float *)(param_3[1] * 0x20 + param_2));
        pfVar2 = (float *)(param_3[2] * 0x20 + param_2);
        FUN_10009370(pfVar2);
        FUN_10009370(pfVar1);
        FUN_10009370(pfVar2);
        FUN_10009370((float *)(param_3[3] * 0x20 + param_2));
        param_1 = param_1 + -1;
        param_3 = param_3 + 4;
      } while (param_1 != 0);
      (*DAT_1000c10c)();
      return;
    }
    do {
      pfVar1 = (float *)(param_2 + *param_3 * 0x28);
      FUN_100094c0(pfVar1);
      FUN_100094c0((float *)(param_2 + param_3[1] * 0x28));
      pfVar2 = (float *)(param_2 + param_3[2] * 0x28);
      FUN_100094c0(pfVar2);
      FUN_100094c0(pfVar1);
      FUN_100094c0(pfVar2);
      FUN_100094c0((float *)(param_2 + param_3[3] * 0x28));
      param_1 = param_1 + -1;
      param_3 = param_3 + 4;
    } while (param_1 != 0);
    (*DAT_1000c10c)();
  }
  return;
}



/* VA 10008da0 */

void _THRASH_drawsprite_8(float *param_1,float *param_2)

{
                    /* 0x8da0  13  _THRASH_drawsprite@8 */
  FUN_10006890();
  (*DAT_1000c120)(6);
  if (DAT_1000c7a4 == 0) {
    FUN_10009370(param_1);
    FUN_10009370((float *)&stack0xffffffcc);
    FUN_10009370(param_2);
    FUN_10009370((float *)&stack0xffffffcc);
    (*DAT_1000c10c)();
    return;
  }
  FUN_100094c0(param_1);
  FUN_100094c0((float *)&stack0xffffffcc);
  FUN_100094c0(param_2);
  FUN_100094c0((float *)&stack0xffffffcc);
  (*DAT_1000c10c)();
  return;
}



/* VA 10008f90 */

void _THRASH_drawspritemesh_12(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  float *pfVar2;
  float *pfVar3;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;

                    /* 0x8f90  14  _THRASH_drawspritemesh@12 */
  if (param_1 != 0) {
    FUN_10006890();
    (*DAT_1000c120)(4);
    if (DAT_1000c7a4 == 0) {
      do {
        pfVar3 = (float *)(*param_3 * 0x20 + param_2);
        pfVar2 = (float *)(param_3[1] * 0x20 + param_2);
        FUN_10009370(pfVar3);
        fStack_34 = *pfVar2;
        fStack_24 = pfVar3[4];
        fStack_30 = pfVar3[1];
        fStack_2c = pfVar3[2];
        fStack_28 = pfVar3[3];
        fStack_1c = pfVar2[6];
        fStack_18 = pfVar3[7];
        fStack_20 = pfVar3[5];
        FUN_10009370(&fStack_34);
        FUN_10009370(pfVar2);
        fStack_34 = *pfVar3;
        fStack_24 = pfVar2[4];
        fStack_30 = pfVar2[1];
        fStack_2c = pfVar2[2];
        fStack_28 = pfVar2[3];
        fStack_1c = pfVar3[6];
        fStack_18 = pfVar2[7];
        fStack_20 = pfVar2[5];
        FUN_10009370(&fStack_34);
        param_1 = param_1 + -1;
        param_3 = param_3 + 2;
      } while (param_1 != 0);
      (*DAT_1000c10c)();
      return;
    }
    do {
      pfVar2 = (float *)(param_2 + *param_3 * 0x28);
      piVar1 = param_3 + 1;
      param_3 = param_3 + 2;
      pfVar3 = (float *)(param_2 + *piVar1 * 0x28);
      FUN_100094c0(pfVar2);
      fStack_34 = *pfVar3;
      fStack_24 = pfVar2[4];
      fStack_30 = pfVar2[1];
      fStack_2c = pfVar2[2];
      fStack_28 = pfVar2[3];
      fStack_1c = pfVar3[6];
      fStack_18 = pfVar2[7];
      fStack_14 = pfVar3[8];
      fStack_10 = pfVar2[9];
      fStack_20 = pfVar2[5];
      FUN_100094c0(&fStack_34);
      FUN_100094c0(pfVar3);
      fStack_34 = *pfVar2;
      fStack_24 = pfVar3[4];
      fStack_30 = pfVar3[1];
      fStack_2c = pfVar3[2];
      fStack_28 = pfVar3[3];
      fStack_1c = pfVar2[6];
      fStack_18 = pfVar3[7];
      fStack_14 = pfVar2[8];
      fStack_10 = pfVar3[9];
      fStack_20 = pfVar3[5];
      FUN_100094c0(&fStack_34);
      param_1 = param_1 + -1;
    } while (param_1 != 0);
    (*DAT_1000c10c)();
  }
  return;
}



/* VA 100091e0 */

void _THRASH_drawtri_12(float *param_1,float *param_2,float *param_3)

{
                    /* 0x91e0  15  _THRASH_drawtri@12 */
  FUN_10006890();
  (*DAT_1000c120)(4);
  if (DAT_1000c7a4 == 0) {
    FUN_10009370(param_1);
    FUN_10009370(param_2);
    FUN_10009370(param_3);
    (*DAT_1000c10c)();
    return;
  }
  FUN_100094c0(param_1);
  FUN_100094c0(param_2);
  FUN_100094c0(param_3);
  (*DAT_1000c10c)();
  return;
}



/* VA 10009240 */

void _THRASH_drawtristrip_8(int param_1,float *param_2)

{
  int iVar1;

                    /* 0x9240  20  _THRASH_drawtristrip@8 */
  if (param_1 != 0) {
    FUN_10006890();
    iVar1 = param_1 + 2;
    (*DAT_1000c120)(5);
    if (DAT_1000c7a4 == 0) {
      do {
        FUN_10009370(param_2);
        param_2 = param_2 + 8;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      (*DAT_1000c10c)();
      return;
    }
    do {
      FUN_100094c0(param_2);
      param_2 = param_2 + 10;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    (*DAT_1000c10c)();
  }
  return;
}



/* VA 100092a0 */

void _THRASH_drawtristrip_12(int param_1,int param_2,int *param_3)

{
                    /* 0x92a0  19  _THRASH_drawtristrip@12 */
  FUN_10009660(5,2,param_1,param_2,param_3);
  return;
}



/* VA 100092c0 */

void _THRASH_drawtrifan_8(int param_1,float *param_2)

{
  int iVar1;

                    /* 0x92c0  17  _THRASH_drawtrifan@8 */
  if (param_1 != 0) {
    FUN_10006890();
    iVar1 = param_1 + 2;
    (*DAT_1000c120)(6);
    if (DAT_1000c7a4 == 0) {
      do {
        FUN_10009370(param_2);
        param_2 = param_2 + 8;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      (*DAT_1000c10c)();
      return;
    }
    do {
      FUN_100094c0(param_2);
      param_2 = param_2 + 10;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    (*DAT_1000c10c)();
  }
  return;
}



/* VA 10009320 */

void _THRASH_drawtrifan_12(int param_1,int param_2,int *param_3)

{
                    /* 0x9320  16  _THRASH_drawtrifan@12 */
  FUN_10009660(6,2,param_1,param_2,param_3);
  return;
}



/* VA 10009340 */

void _THRASH_drawtrimesh_12(int param_1,int param_2,int *param_3)

{
                    /* 0x9340  18  _THRASH_drawtrimesh@12 */
  FUN_10009660(4,0,param_1 * 3,param_2,param_3);
  return;
}



/* VA 10009370 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_10009370(float *param_1)

{
  float fVar1;
  uint local_10;
  float local_c;
  float local_8;

  fVar1 = param_1[4];
  local_10 = (uint)fVar1 >> 0x10 & 0xff | ((uint)fVar1 & 0xff) << 0x10 | (uint)fVar1 & 0xff00ff00;
  (*DAT_1000c114)(&local_10);
  if (((DAT_1000d844 != 0) && (DAT_1000c070 != (code *)0x0)) && (fVar1 = param_1[5], fVar1 != 0.0))
  {
    local_c = (float)((uint)fVar1 >> 0x10 & 0xff | ((uint)fVar1 & 0xff) << 0x10 |
                     (uint)fVar1 & 0xff00ff00);
    (*DAT_1000c070)(&local_c);
  }
  if (DAT_1000c84c != 0) {
    fVar1 = param_1[3];
    local_c = fVar1 * param_1[6];
    (*DAT_1000c0e0)(local_c,param_1[7] * fVar1,0,fVar1);
  }
  if ((DAT_1000c86c != 0) && (DAT_1000c0e8 != (code *)0x0)) {
    local_c = 1.0 / param_1[3];
    (*DAT_1000c0e8)(local_c);
  }
  local_8 = param_1[1];
  local_c = *param_1;
  if (DAT_1000ad6c < param_1[2]) {
    (*DAT_1000c03c)(local_c,local_8);
    return;
  }
  (*DAT_1000c09c)(local_c,local_8,param_1[2] + _DAT_1000c870);
  return;
}



/* VA 100094c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_100094c0(float *param_1)

{
  float fVar1;
  uint local_10;
  float local_c;
  float local_8;

  fVar1 = param_1[4];
  local_10 = (uint)fVar1 >> 0x10 & 0xff | ((uint)fVar1 & 0xff) << 0x10 | (uint)fVar1 & 0xff00ff00;
  (*DAT_1000c114)(&local_10);
  if (((DAT_1000d844 != 0) && (DAT_1000c070 != (code *)0x0)) && (fVar1 = param_1[5], fVar1 != 0.0))
  {
    local_c = (float)((uint)fVar1 >> 0x10 & 0xff | ((uint)fVar1 & 0xff) << 0x10 |
                     (uint)fVar1 & 0xff00ff00);
    (*DAT_1000c070)(&local_c);
  }
  if (DAT_1000c84c != 0) {
    fVar1 = param_1[3];
    local_c = fVar1 * param_1[6];
    (*DAT_1000c0c8)(0x84c0,local_c,param_1[7] * fVar1,0,fVar1);
    fVar1 = param_1[3];
    local_c = fVar1 * param_1[8];
    (*DAT_1000c0c8)(0x84c1,local_c,param_1[9] * fVar1,0,fVar1);
  }
  if ((DAT_1000c86c != 0) && (DAT_1000c0e8 != (code *)0x0)) {
    local_c = 1.0 / param_1[3];
    (*DAT_1000c0e8)(local_c);
  }
  local_8 = param_1[1];
  local_c = *param_1;
  if (DAT_1000ad6c < param_1[2]) {
    (*DAT_1000c03c)(local_c,local_8);
    return;
  }
  (*DAT_1000c09c)(local_c,local_8,param_1[2] + _DAT_1000c870);
  return;
}



/* VA 10009660 */

void __fastcall FUN_10009660(undefined4 param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;

  if (param_3 == 0) {
    return;
  }
  FUN_10006890();
  iVar1 = param_3 + param_2;
  (*DAT_1000c120)(param_1);
  if (DAT_1000c7a4 == 0) {
    do {
      FUN_10009370((float *)(*param_5 * 0x20 + param_4));
      param_5 = param_5 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  else {
    do {
      FUN_100094c0((float *)(param_4 + *param_5 * 0x28));
      param_5 = param_5 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
                    /* WARNING: Could not recover jumptable at 0x100096bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_1000c10c)();
  return;
}



/* VA 100096d0 */

void __thiscall FUN_100096d0(void *this,int param_1,int param_2,ushort *param_3)

{
  if (param_1 == 0) {
    return;
  }
  FUN_10006890();
  (*DAT_1000c120)(this);
  if (DAT_1000c7a4 == 0) {
    do {
      FUN_10009370((float *)((uint)*param_3 * 0x20 + param_2));
      param_3 = param_3 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  else {
    do {
      FUN_100094c0((float *)(param_2 + (uint)*param_3 * 0x28));
      param_3 = param_3 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
                    /* WARNING: Could not recover jumptable at 0x10009731. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_1000c10c)();
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

  sprintf(local_64,"%s_%s",&DAT_1000a5f4,param_1);
  DVar1 = GetPrivateProfileStringA("THRASH",local_64,(LPCSTR)0x0,local_14,0xc,(LPCSTR)&DAT_1000d8a8)
  ;
  if (DVar1 == 0) {
    sprintf(local_64,"THRASH_%s",param_1);
    DVar1 = GetPrivateProfileStringA
                      ("THRASH",local_64,(LPCSTR)0x0,local_14,0xc,(LPCSTR)&DAT_1000d8a8);
    if (DVar1 == 0) {
      sprintf(local_64,"%s_%s",&DAT_1000a5f4,param_1);
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
    uVar1 = (uint)(ushort)(&DAT_1000a9e4)[uVar2 * 2];
    if ((uVar1 <= param_1) && (param_1 <= (ushort)(&DAT_1000a9e6)[uVar2 * 2])) break;
    uVar3 = uVar3 + 1;
    iVar4 = iVar4 + ((ushort)(&DAT_1000a9e6)[uVar2 * 2] - uVar1);
    if (0xb < uVar3) {
      return -1;
    }
  }
  return param_1 + (iVar4 - uVar1);
}



/* VA 10009a70 */

void __fastcall FUN_10009a70(uint param_1,float *param_2)

{
  FUN_10005080(param_1,0,param_2);
  return;
}



/* VA 10009a90 */

void _THRASH_setstate_8(uint param_1,float *param_2)

{
                    /* 0x9a90  31  _THRASH_setstate@8 */
  FUN_10005080(param_1 & 0xffff,param_1 >> 0x10,param_2);
  return;
}



/* VA 10009ab0 */

int _THRASH_getstate_4(uint param_1)

{
  int iVar1;

                    /* 0x9ab0  22  _THRASH_getstate@4 */
  iVar1 = FUN_10009a20(param_1 & 0xffff);
  if (-1 < iVar1) {
    iVar1 = *(int *)(&DAT_1000da48 + ((param_1 >> 0x10) * 0x8c + iVar1) * 4);
  }
  return iVar1;
}



/* VA 10009ae0 */

void __fastcall FUN_10009ae0(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  char local_194 [400];

  puVar1 = *(undefined4 **)(param_1 + 0x40);
  if (puVar1 == (undefined4 *)0x0) {
    if (DAT_1000d894 == (code *)0x0) {
      puVar1 = malloc(0x400);
    }
    else {
      puVar1 = (undefined4 *)(*DAT_1000d894)();
    }
    *(undefined4 **)(param_1 + 0x40) = puVar1;
    if ((puVar1 == (undefined4 *)0x0) && (DAT_1000d88c != (code *)0x0)) {
      sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d","PrepareIndexed","Out of memory.",
              "D:\\Work\\Tharsh\\Thrash.Core\\Texture.cpp",0x2f);
      (*DAT_1000d88c)(0,local_194);
      puVar1 = *(undefined4 **)(param_1 + 0x40);
    }
  }
  puVar4 = &DAT_1000e0d8;
  for (iVar3 = 0x100; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar1 = puVar1 + 1;
  }
  pvVar2 = *(void **)(param_1 + 0x3c);
  if (pvVar2 == (void *)0x0) {
    if (DAT_1000d894 == (code *)0x0) {
      pvVar2 = malloc(*(int *)(param_1 + 0x30) * *(int *)(param_1 + 0x28));
    }
    else {
      pvVar2 = (void *)(*DAT_1000d894)();
    }
    *(void **)(param_1 + 0x3c) = pvVar2;
  }
  if ((pvVar2 == (void *)0x0) && (DAT_1000d88c != (code *)0x0)) {
    sprintf(local_194,"%s:\n%s\n\n\nFILE %s\nLINE %d","Prepare","Out of memory.",
            "D:\\Work\\Tharsh\\Thrash.Core\\Texture.cpp",0x26);
    (*DAT_1000d88c)(0,local_194);
  }
  return;
}



/* VA 10009bd6 */

double __cdecl ceil(double _X)

{
  double dVar1;

                    /* WARNING: Could not recover jumptable at 0x10009bd6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar1 = ceil(_X);
  return dVar1;
}



/* VA 10009bdc */

double __cdecl floor(double _X)

{
  double dVar1;

                    /* WARNING: Could not recover jumptable at 0x10009bdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar1 = floor(_X);
  return dVar1;
}



/* VA 10009be2 */

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  void *pvVar1;

                    /* WARNING: Could not recover jumptable at 0x10009be2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memcpy(_Dst,_Src,_Size);
  return pvVar1;
}



/* VA 10009be8 */

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;

                    /* WARNING: Could not recover jumptable at 0x10009be8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



/* VA 10009bf0 */

int thunk_FUN_10009c00(void)

{
  uint uVar1;
  ushort uVar2;
  float10 in_ST0;
  undefined4 uStack_1c;
  undefined2 uStack_18;

  if (1 < DAT_1000e4dc) {
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



/* VA 10009c00 */

int FUN_10009c00(void)

{
  uint uVar1;
  ushort uVar2;
  float10 in_ST0;
  undefined4 uStack_1c;
  undefined2 uStack_18;

  if (1 < DAT_1000e4dc) {
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
