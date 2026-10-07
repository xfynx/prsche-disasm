/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 3cfcd03a923386c36685a772d24797fb78762cfbe63fe5676756091cf27da7a4 */

/* VA 00401000 */

LRESULT FUN_00401000(HWND param_1,UINT param_2,WPARAM param_3,int param_4)

{
  int iVar1;
  LONG LVar2;
  LRESULT LVar3;
  HDC hDC;
  HBRUSH hbr;
  HFONT h;
  HGDIOBJ h_00;
  int iVar4;
  tagPAINTSTRUCT local_60;
  tagRECT local_20;
  LOGBRUSH local_10;

  iVar1 = DAT_0042eb70;
  if (param_2 == 0xf) {
    hDC = BeginPaint(param_1,&local_60);
    local_10.lbStyle = 0;
    GetClientRect(param_1,&local_20);
    LVar2 = local_20.bottom;
    local_20.bottom = 0;
    for (; local_20.top < LVar2; local_20.top = local_20.top + 4) {
      iVar4 = LVar2 - local_20.top;
      local_10.lbColor =
           (uint)CONCAT11((char)((int)((uint)*(byte *)(iVar1 + 0x52) * iVar4 +
                                      (uint)*(byte *)(iVar1 + 0x56) * local_20.top) / LVar2),
                          (char)((int)((uint)*(byte *)(iVar1 + 0x51) * iVar4 +
                                      (uint)*(byte *)(iVar1 + 0x55) * local_20.top) / LVar2)) << 8 |
           (int)((uint)*(byte *)(iVar1 + 0x50) * iVar4 +
                (uint)*(byte *)(iVar1 + 0x54) * local_20.top) / LVar2 & 0xffU;
      hbr = CreateBrushIndirect(&local_10);
      local_20.bottom = local_20.bottom + 4;
      FillRect(hDC,&local_20,hbr);
      DeleteObject(hbr);
    }
    if (*(int *)(iVar1 + 0x58) != -1) {
      h = CreateFontIndirectA(*(LOGFONTA **)(iVar1 + 0x34));
      if (h != (HFONT)0x0) {
        local_20.left = 0x10;
        local_20.top = 8;
        SetBkMode(hDC,1);
        SetTextColor(hDC,*(COLORREF *)(iVar1 + 0x58));
        h_00 = SelectObject(hDC,h);
        DrawTextA(hDC,&DAT_0042e360,-1,&local_20,0x820);
        SelectObject(hDC,h_00);
        DeleteObject(h);
      }
    }
    EndPaint(param_1,&local_60);
    LVar3 = 0;
  }
  else {
    if (param_2 == 0x46) {
      *(uint *)(param_4 + 0x18) = *(uint *)(param_4 + 0x18) | 0x10;
      *(undefined4 *)(param_4 + 4) = DAT_0042eb68;
    }
    LVar3 = DefWindowProcA(param_1,param_2,param_3,param_4);
  }
  return LVar3;
}



/* VA 0040117d */

void FUN_0040117d(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;

  uVar1 = *(uint *)(param_1 * 0x418 + 8 + DAT_0042eb88);
  if ((uVar1 & 2) != 0) {
    uVar4 = param_1 + 1;
    if (uVar4 < DAT_0042eb8c) {
      puVar3 = (uint *)(uVar4 * 0x418 + 8 + DAT_0042eb88);
      iVar5 = 0;
      do {
        uVar2 = *puVar3;
        if ((uVar2 & 2) == 0) {
          if ((uVar2 & 4) == 0) {
            iVar6 = iVar5;
            if ((uVar2 & 0x10) == 0) {
              *puVar3 = (uVar2 ^ uVar1) & 1 ^ uVar2;
            }
          }
          else {
            iVar6 = iVar5 + -1;
            if (iVar5 == 0) {
              return;
            }
          }
        }
        else {
          iVar6 = iVar5 + 1;
        }
        uVar4 = uVar4 + 1;
        puVar3 = puVar3 + 0x106;
        iVar5 = iVar6;
      } while (uVar4 < DAT_0042eb8c);
    }
  }
  return;
}



/* VA 004011ef */

uint FUN_004011ef(uint param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int local_c;
  int local_8;

  iVar2 = DAT_0042eb88;
  iVar5 = param_1 * 0x418 + DAT_0042eb88;
  local_8 = 0;
  local_c = 0;
  if (((*(uint *)(iVar5 + 8) & 2) != 0) && (param_2 != 0)) {
    param_1 = param_1 + 1;
    *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) & 0xffffffbe;
  }
  if (param_1 < DAT_0042eb8c) {
    do {
      puVar1 = (uint *)(param_1 * 0x418 + 8 + iVar2);
      uVar3 = param_1 + 1;
      uVar4 = *puVar1;
      if ((uVar4 & 2) != 0) {
        uVar3 = FUN_004011ef(param_1,1);
        uVar4 = *puVar1;
      }
      if ((uVar4 & 4) != 0) {
        if (local_8 == 0) {
          return uVar3;
        }
        if (local_c != 0) {
          *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) | 0x40;
          return uVar3;
        }
        *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) & 0xffffff7f | 1;
        return uVar3;
      }
      if ((uVar4 & 0x40) != 0) {
        local_8 = local_8 + 1;
      }
      if ((uVar4 & 1) == 0) {
        local_c = local_c + 1;
      }
      else {
        local_8 = local_8 + 1;
      }
      param_1 = uVar3;
    } while (uVar3 < DAT_0042eb8c);
  }
  return 0;
}



/* VA 00401299 */

void FUN_00401299(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;

  uVar3 = 0;
  if ((param_1 < 0x20) && (DAT_0042eb8c != 0)) {
    puVar2 = (uint *)(DAT_0042eb88 + 8);
    do {
      uVar1 = *puVar2;
      if ((uVar1 & 6) == 0) {
        if ((puVar2[-1] & 1 << ((byte)param_1 & 0x1f)) == 0) {
          uVar1 = uVar1 & 0xfffffffe;
        }
        else {
          uVar1 = uVar1 | 1;
        }
        *puVar2 = uVar1;
      }
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 0x106;
    } while (uVar3 < DAT_0042eb8c);
  }
  return;
}



/* VA 004012e2 */

uint FUN_004012e2(int param_1)

{
  uint uVar1;
  uint *puVar2;
  bool bVar3;
  int *local_c;
  uint local_8;

  local_8 = 0;
  local_c = (int *)(DAT_0042eb70 + 0x94);
  do {
    uVar1 = 0;
    if (*local_c != 0) {
      bVar3 = DAT_0042eb8c == 0;
      if (DAT_0042eb8c != 0) {
        puVar2 = (uint *)(DAT_0042eb88 + 8);
        do {
          if (((*puVar2 & 6) == 0) &&
             (((param_1 == 0 || (*(int *)(param_1 + uVar1 * 4) != 0)) &&
              ((puVar2[-1] & 1 << ((byte)local_8 & 0x1f)) != (*puVar2 & 1) << ((byte)local_8 & 0x1f)
              )))) break;
          uVar1 = uVar1 + 1;
          puVar2 = puVar2 + 0x106;
        } while (uVar1 < DAT_0042eb8c);
        bVar3 = uVar1 == DAT_0042eb8c;
      }
      if (bVar3) {
        return local_8;
      }
    }
    local_8 = local_8 + 1;
    local_c = local_c + 1;
    if (0x1f < local_8) {
      return local_8;
    }
  } while( true );
}



/* VA 0040136d */

void FUN_0040136d(int param_1)

{
  if (param_1 < 0) {
    FUN_00405983(&DAT_0042f000 + (param_1 + 1) * -0x400);
  }
  return;
}



/* VA 00401389 */

undefined4 FUN_00401389(int param_1,HWND param_2)

{
  HWND pHVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  WPARAM wParam;
  LPARAM lParam;

  while ((-1 < param_1 && (pHVar1 = (HWND)(param_1 * 0x1c + DAT_0042eb90), pHVar1->unused != 1))) {
    pbVar2 = FUN_00401434(pHVar1);
    if (pbVar2 == (byte *)0x7fffffff) {
      return 0x7fffffff;
    }
    iVar3 = FUN_0040136d((int)pbVar2);
    if (iVar3 == 0) {
      iVar4 = 1;
      iVar3 = param_1 + 1;
    }
    else {
      iVar3 = iVar3 + -1;
      iVar4 = iVar3 - param_1;
    }
    param_1 = iVar3;
    if (param_2 != (HWND)0x0) {
      DAT_0042e34c = DAT_0042e34c + iVar4;
      lParam = 0;
      wParam = MulDiv(DAT_0042e34c,30000,DAT_0042e334);
      SendMessageA(param_2,0x402,wParam,lParam);
    }
  }
  return 0;
}



/* VA 0040140b */

void FUN_0040140b(int param_1)

{
  FUN_00401389(*(int *)(DAT_0042eb70 + 0x6c + param_1 * 4),(HWND)0x0);
  return;
}



/* VA 00401423 */

void FUN_00401423(int param_1)

{
  FUN_00404daa(param_1,&DAT_00409f80);
  return;
}



/* VA 00401434 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte * FUN_00401434(HWND param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  undefined4 uVar4;
  LRESULT LVar5;
  HGDIOBJ ho;
  HDC hdc;
  HINSTANCE pHVar6;
  HMODULE hModule;
  FARPROC pFVar7;
  HRESULT HVar8;
  int iVar9;
  byte *lpFileName;
  byte *pbVar10;
  undefined *puVar11;
  HKEY pHVar12;
  LSTATUS LVar13;
  DWORD DVar14;
  LPSTR pCVar15;
  LONG lDistanceToMove;
  BOOL BVar16;
  HANDLE pvVar17;
  HGLOBAL lpBuffer;
  uint uVar18;
  HWND pHVar19;
  int iVar20;
  byte *pbVar21;
  HWND pHVar22;
  CHAR *pCVar23;
  int *piVar24;
  HWND lpBuffer_00;
  byte *pbVar25;
  bool bVar26;
  UINT UVar27;
  undefined1 *lpBuffer_01;
  HWND *lpNumberOfBytesWritten;
  PLONG lpDistanceToMoveHigh;
  LPCSTR pCVar28;
  UINT fuLoad;
  int nDenominator;
  LPOVERLAPPED lpOverlapped;
  _WIN32_FIND_DATAA *lpFindFileData;
  _WIN32_FIND_DATAA local_1a8;
  _SHFILEOPSTRUCTA local_68;
  byte *local_48;
  tagRECT local_44;
  byte *local_34;
  byte *local_30;
  int local_2c;
  byte *local_28 [2];
  byte *local_20;
  FILETIME local_1c;
  byte *local_14;
  byte local_d;
  HWND local_c;
  byte *local_8;

  pHVar19 = DAT_0040af80;
  local_44.bottom = (LONG)DAT_0042eb68;
  pbVar21 = (byte *)0x0;
  pHVar22 = param_1;
  piVar24 = &local_2c;
  for (iVar20 = 7; iVar20 != 0; iVar20 = iVar20 + -1) {
    *piVar24 = pHVar22->unused;
    pHVar22 = pHVar22 + 1;
    piVar24 = piVar24 + 1;
  }
  iVar20 = (int)local_28[0] * 0x400;
  local_8 = (byte *)0x0;
  pHVar22 = (HWND)(&DAT_0042f000 + iVar20);
  lpBuffer_00 = (HWND)(&DAT_0042f000 + (int)local_28[1] * 0x400);
  DAT_00409b78 = local_28;
  switch(local_2c) {
  case 2:
    goto switchD_00401489_caseD_2;
  case 3:
    pCVar28 = (LPCSTR)0x0;
LAB_00401492:
    FUN_00404daa((int)local_28[0],pCVar28);
    return (byte *)0x7fffffff;
  case 4:
    DAT_0042e32c = DAT_0042e32c + 1;
    if (DAT_0042eb68 == (HWND)0x0) {
      return (byte *)0x7fffffff;
    }
    PostQuitMessage(0);
    return (byte *)0x7fffffff;
  case 5:
    iVar20 = FUN_0040136d((int)local_28[0]);
    pbVar21 = (byte *)FUN_00401389(iVar20 + -1,(HWND)0x0);
    return pbVar21;
  case 6:
    FUN_00404daa((int)local_28[0],(LPCSTR)0x0);
    break;
  case 7:
    DVar14 = FUN_004029d9(0);
    if ((int)DVar14 < 2) {
      DVar14 = 1;
    }
    Sleep(DVar14);
    break;
  case 8:
    SetForegroundWindow(DAT_0042eb68);
    break;
  case 9:
    if (DAT_0042e330 != (HWND)0x0) {
      ShowWindow(DAT_0042e330,(int)local_28[1]);
    }
    if (DAT_0042e344 != (HWND)0x0) {
      ShowWindow(DAT_0042e344,(int)local_28[0]);
    }
    break;
  case 10:
    pbVar21 = FUN_004029f6(0xfffffff0);
    pCVar15 = (LPSTR)SetFileAttributesA((LPCSTR)pbVar21,(DWORD)local_28[1]);
    goto LAB_004015a6;
  case 0xb:
    pbVar21 = FUN_004029f6(0xfffffff0);
    pcVar2 = FUN_00405593((short *)pbVar21);
    if (pcVar2 != (char *)0x0) {
      do {
        pcVar2 = (char *)FUN_0040552a(pcVar2,'\\');
        cVar1 = *pcVar2;
        *pcVar2 = '\0';
        param_1 = (HWND)CONCAT13(cVar1,param_1._0_3_);
        BVar16 = CreateDirectoryA((LPCSTR)pbVar21,(LPSECURITY_ATTRIBUTES)0x0);
        if ((BVar16 == 0) &&
           ((DVar14 = GetLastError(), DVar14 != 0xb7 ||
            (DVar14 = GetFileAttributesA((LPCSTR)pbVar21), (DVar14 & 0x10) == 0)))) {
          local_8 = local_8 + 1;
        }
        *pcVar2 = param_1._3_1_;
        pcVar2 = pcVar2 + 1;
      } while (param_1._3_1_ != '\0');
    }
    if (local_28[1] == (byte *)0x0) {
      iVar20 = -0xb;
      goto LAB_00402164;
    }
    FUN_00401423(-0x1a);
    FUN_00405a0c(&DAT_00434800,(LPCSTR)pbVar21);
    SetCurrentDirectoryA((LPCSTR)pbVar21);
    break;
  case 0xc:
    pbVar21 = FUN_004029f6(0);
    puVar11 = FUN_00405d07((LPCSTR)pbVar21);
    local_1c.dwLowDateTime = (DWORD)local_28[1];
    goto joined_r0x004019d4;
  case 0xd:
    if (local_20 == (byte *)0x0) {
      *(undefined4 *)(&DAT_0042ec20 + (int)local_28[0] * 4) = (&DAT_0042ebe0)[(int)local_28[0]];
      uVar4 = FUN_004029d9(1);
      (&DAT_0042ebe0)[(int)local_28[0]] = uVar4;
    }
    else {
      (&DAT_0042ebe0)[(int)local_28[0]] = *(undefined4 *)(&DAT_0042ec20 + (int)local_28[0] * 4);
    }
    break;
  case 0xe:
    uVar18 = (&DAT_0042ebe0)[(int)local_20];
    pbVar21 = local_28[uVar18 == 0];
    (&DAT_0042ebe0)[(int)local_20] = uVar18 & local_1c.dwLowDateTime;
    return pbVar21;
  case 0xf:
    pHVar19 = (HWND)(&DAT_0042ebe0)[(int)local_28[1]];
    goto switchD_00401a72_default;
  case 0x10:
    pbVar21 = FUN_004029f6(0xffffffd0);
    pbVar10 = FUN_004029f6(0xffffffdf);
    FUN_004029f6(0x13);
    BVar16 = MoveFileA((LPCSTR)pbVar21,(LPCSTR)pbVar10);
    if (BVar16 == 0) {
      if ((local_20 == (byte *)0x0) ||
         (puVar11 = FUN_00405d07((LPCSTR)pbVar21), puVar11 == (undefined *)0x0)) goto LAB_0040265c;
      FUN_0040575a((LPCSTR)pbVar21,(LPCSTR)pbVar10);
      iVar20 = -0x1c;
    }
    else {
      iVar20 = -0x1d;
    }
    goto LAB_00402164;
  case 0x11:
    pHVar19 = (HWND)FUN_004029f6(0);
    DVar14 = GetFullPathNameA((LPCSTR)pHVar19,0x400,(LPSTR)lpBuffer_00,(LPSTR *)&param_1);
    if (DVar14 == 0) {
LAB_004016d6:
      local_8 = (byte *)0x1;
      *(undefined1 *)&lpBuffer_00->unused = 0;
    }
    else if ((pHVar19 < param_1) && ((char)param_1->unused != '\0')) {
      puVar11 = FUN_00405d07((LPCSTR)pHVar19);
      if (puVar11 == (undefined *)0x0) goto LAB_004016d6;
      FUN_00405a0c((LPSTR)param_1,puVar11 + 0x2c);
    }
    if (local_20 == (byte *)0x0) {
      GetShortPathNameA((LPCSTR)lpBuffer_00,(LPSTR)lpBuffer_00,0x400);
    }
    break;
  case 0x12:
    pbVar21 = FUN_004029f6(0xffffffff);
    DVar14 = SearchPathA((LPCSTR)0x0,(LPCSTR)pbVar21,(LPCSTR)0x0,0x400,(LPSTR)pHVar22,
                         (LPSTR *)&param_1);
    goto LAB_00401716;
  case 0x13:
    pbVar21 = FUN_004029f6(0xffffffef);
    pCVar15 = FUN_00405712((LPSTR)pHVar22,(LPCSTR)pbVar21);
    goto LAB_004015a6;
  case 0x14:
    pHVar19 = (HWND)FUN_004029f6(0x31);
    param_1 = (HWND)((uint)local_28[0] & 7);
    local_c = pHVar19;
    iVar20 = FUN_0040556c((byte *)pHVar19);
    if (iVar20 == 0) {
      pCVar28 = (LPCSTR)FUN_00405a0c(&DAT_00409b80,&DAT_00434800);
      pCVar28 = FUN_004054ff(pCVar28);
      lstrcatA(pCVar28,(LPCSTR)pHVar19);
    }
    else {
      FUN_00405a0c(&DAT_00409b80,(LPCSTR)pHVar19);
    }
    FUN_00405c6e(&DAT_00409b80);
    do {
      if (2 < (int)param_1) {
        puVar11 = FUN_00405d07(&DAT_00409b80);
        uVar18 = 0;
        if (puVar11 != (undefined *)0x0) {
          uVar18 = CompareFileTime((FILETIME *)(puVar11 + 0x14),&local_1c);
        }
        param_1 = (HWND)(uint)((((uint)((int)&param_1[-1].unused + 1U) | 0x80000000) & uVar18) == 0)
        ;
      }
      if (param_1 == (HWND)0x0) {
        FUN_004056c4(&DAT_00409b80);
      }
      local_44.bottom = FUN_004056e3(&DAT_00409b80,0x40000000,(param_1 != (HWND)0x1) + 1);
      if ((HWND)local_44.bottom != (HWND)0xffffffff) {
        FUN_00404daa(-0x16,(LPCSTR)local_c);
        DAT_0042ec14 = DAT_0042ec14 + 1;
        puVar11 = FUN_00402e5b((int)local_20,(HANDLE)local_44.bottom,(undefined *)0x0,
                               (undefined *)0x0);
        DAT_0042ec14 = DAT_0042ec14 + -1;
        if (((byte *)local_1c.dwLowDateTime != (byte *)0xffffffff) ||
           ((byte *)local_1c.dwHighDateTime != (byte *)0xffffffff)) {
          SetFileTime((HANDLE)local_44.bottom,&local_1c,(FILETIME *)0x0,&local_1c);
        }
        CloseHandle((HANDLE)local_44.bottom);
        if (-1 < (int)puVar11) goto switchD_00401489_caseD_41;
        if (puVar11 == (undefined *)0xfffffffe) {
          FUN_00405a2e(&DAT_00409b80,-0x17);
          lstrcatA(&DAT_00409b80,(LPCSTR)local_c);
        }
        else {
          FUN_00405a2e(&DAT_00409b80,-0x12);
        }
        uVar18 = 0x200010;
        puVar11 = &DAT_00409b80;
        goto LAB_00402209;
      }
      if (param_1 != (HWND)0x0) {
        FUN_00404daa(-0x1e,(LPCSTR)local_c);
        bVar26 = param_1 == (HWND)0x2;
        goto LAB_004015a8;
      }
      FUN_00405a0c(&DAT_0040a380,&DAT_0042f000);
      FUN_00405a0c(&DAT_0042f000,&DAT_00409b80);
      FUN_00405a2e(&DAT_00409f80,(int)local_14);
      FUN_00405a0c(&DAT_0042f000,&DAT_0040a380);
      iVar20 = FUN_004052cd(&DAT_00409f80,(int)local_28[0] >> 3);
    } while (iVar20 == 4);
    if (iVar20 != 5) {
      pCVar28 = &DAT_00409b80;
      local_28[0] = (byte *)0xfffffffa;
      goto LAB_00401492;
    }
    _DAT_0042ebe8 = _DAT_0042ebe8 + 1;
    goto LAB_00402894;
  case 0x15:
    uVar18 = 0;
    goto LAB_0040190f;
  case 0x16:
    pbVar21 = FUN_004029f6(0x31);
    pbVar21 = (byte *)FUN_004052cd(pbVar21,(uint)local_28[0]);
    if (pbVar21 == (byte *)0x0) goto LAB_0040265c;
    if (pbVar21 == local_20) {
      return (byte *)local_1c.dwLowDateTime;
    }
    if (pbVar21 == (byte *)local_1c.dwHighDateTime) {
      return local_14;
    }
    break;
  case 0x17:
    uVar18 = 0xfffffff0;
LAB_0040190f:
    pbVar21 = FUN_004029f6(uVar18);
    FUN_00405331((LPCSTR)pbVar21,(uint)local_28[1]);
    break;
  case 0x18:
    pbVar21 = FUN_004029f6(1);
    pHVar19 = (HWND)lstrlenA((LPCSTR)pbVar21);
    goto switchD_00401a72_default;
  case 0x19:
    param_1 = (HWND)FUN_004029d9(2);
    iVar20 = FUN_004029d9(3);
    local_30 = FUN_004029f6(1);
    *(undefined1 *)&pHVar22->unused = 0;
    if (((local_20 == (byte *)0x0) || (param_1 != (HWND)0x0)) &&
       ((iVar9 = lstrlenA((LPCSTR)local_30), -1 < iVar20 || (iVar20 = iVar20 + iVar9, -1 < iVar20)))
       ) {
      if (iVar9 < iVar20) {
        iVar20 = iVar9;
      }
      FUN_00405a0c((LPSTR)pHVar22,(LPCSTR)(local_30 + iVar20));
      pHVar19 = param_1;
      if (param_1 != (HWND)0x0) {
        if ((int)param_1 < 0) {
          iVar20 = lstrlenA((LPCSTR)pHVar22);
          param_1 = (HWND)((int)&pHVar19->unused + iVar20);
          if ((int)param_1 < 0) {
            param_1 = (HWND)0x0;
          }
        }
        if ((int)param_1 < 0x400) {
          *(undefined1 *)((int)&param_1->unused + (int)pHVar22) = 0;
        }
      }
    }
    break;
  case 0x1a:
    pbVar21 = FUN_004029f6(0x20);
    pbVar10 = FUN_004029f6(0x31);
    if ((byte *)local_1c.dwHighDateTime == (byte *)0x0) {
      puVar11 = (undefined *)lstrcmpiA((LPCSTR)pbVar21,(LPCSTR)pbVar10);
    }
    else {
      puVar11 = (undefined *)lstrcmpA((LPCSTR)pbVar21,(LPCSTR)pbVar10);
    }
    goto joined_r0x004019d4;
  case 0x1b:
    param_1 = (HWND)FUN_004029f6(1);
    DVar14 = ExpandEnvironmentStringsA((LPCSTR)param_1,(LPSTR)pHVar22,0x400);
    if ((DVar14 == 0) ||
       ((local_20 != (byte *)0x0 && (iVar9 = lstrcmpA((LPCSTR)param_1,(LPCSTR)pHVar22), iVar9 == 0))
       )) {
      local_8 = (byte *)0x1;
      *(undefined1 *)&pHVar22->unused = 0;
    }
    (&DAT_0042f3ff)[iVar20] = 0;
    break;
  case 0x1c:
    uVar18 = FUN_004029d9(0);
    uVar3 = FUN_004029d9(1);
    if (local_14 != (byte *)0x0) {
      if (uVar18 < uVar3) {
        return (byte *)local_1c.dwLowDateTime;
      }
      if (uVar18 <= uVar3) {
        return local_20;
      }
      return (byte *)local_1c.dwHighDateTime;
    }
    if ((int)uVar18 < (int)uVar3) {
      return (byte *)local_1c.dwLowDateTime;
    }
    if ((int)uVar18 <= (int)uVar3) {
      return local_20;
    }
    return (byte *)local_1c.dwHighDateTime;
  case 0x1d:
    pHVar19 = (HWND)FUN_004029d9(1);
    uVar18 = FUN_004029d9(2);
    switch(local_1c.dwLowDateTime) {
    case 0:
      pHVar19 = (HWND)((int)&pHVar19->unused + uVar18);
      break;
    case 1:
      pHVar19 = (HWND)((int)pHVar19 - uVar18);
      break;
    case 2:
      pHVar19 = (HWND)(uVar18 * (int)pHVar19);
      break;
    case 3:
      if (uVar18 == 0) {
LAB_00401ace:
        pHVar19 = (HWND)0x0;
        local_8 = (byte *)0x1;
      }
      else {
        pHVar19 = (HWND)((int)pHVar19 / (int)uVar18);
      }
      break;
    case 4:
      pHVar19 = (HWND)((uint)pHVar19 | uVar18);
      break;
    case 5:
      pHVar19 = (HWND)((uint)pHVar19 & uVar18);
      break;
    case 6:
      pHVar19 = (HWND)((uint)pHVar19 ^ uVar18);
      break;
    case 7:
      pHVar19 = (HWND)(uint)(pHVar19 == (HWND)0x0);
      break;
    case 8:
      if (pHVar19 == (HWND)0x0) {
LAB_00401ab8:
        if (uVar18 == 0) goto LAB_00401ab0;
      }
      pHVar19 = (HWND)0x1;
      break;
    case 9:
      if (pHVar19 != (HWND)0x0) goto LAB_00401ab8;
LAB_00401ab0:
      pHVar19 = (HWND)0x0;
      break;
    case 10:
      if (uVar18 == 0) goto LAB_00401ace;
      pHVar19 = (HWND)((int)pHVar19 % (int)uVar18);
      break;
    case 0xb:
      pHVar19 = (HWND)((int)pHVar19 << ((byte)uVar18 & 0x1f));
      break;
    case 0xc:
      pHVar19 = (HWND)((int)pHVar19 >> ((byte)uVar18 & 0x1f));
    }
    goto switchD_00401a72_default;
  case 0x1e:
    pbVar21 = FUN_004029f6(1);
    uVar4 = FUN_004029d9(2);
    wsprintfA((LPSTR)pHVar22,(LPCSTR)pbVar21,uVar4);
    break;
  case 0x1f:
    if (local_20 != (byte *)0x0) {
      do {
        local_20 = local_20 + -1;
        if (pHVar19 == (HWND)0x0) goto LAB_004021fb;
        pHVar19 = (HWND)pHVar19->unused;
      } while (local_20 != (byte *)0x0);
      if (pHVar19 == (HWND)0x0) goto LAB_004021fb;
      FUN_00405a0c(&DAT_00409b80,(LPCSTR)(pHVar19 + 1));
      FUN_00405a0c((LPSTR)(pHVar19 + 1),(LPCSTR)(DAT_0040af80 + 1));
      pCVar23 = &DAT_00409b80;
      pHVar22 = DAT_0040af80 + 1;
      goto LAB_004027b1;
    }
    if (local_28[1] != (byte *)0x0) {
      if (DAT_0040af80 != (HWND)0x0) {
        FUN_00405a0c((LPSTR)pHVar22,(LPCSTR)(DAT_0040af80 + 1));
        DAT_0040af80 = (HWND)pHVar19->unused;
        goto LAB_00401b75;
      }
      goto LAB_0040265c;
    }
    pHVar19 = GlobalAlloc(0x40,0x404);
    FUN_00405a2e((byte *)(pHVar19 + 1),(int)local_28[0]);
    pHVar19->unused = (int)DAT_0040af80;
    DAT_0040af80 = pHVar19;
    break;
  case 0x20:
  case 0x21:
    local_44.bottom = FUN_004029d9(3);
    param_1 = (HWND)FUN_004029d9(4);
    if (((uint)local_14 & 1) != 0) {
      local_44.bottom = (LONG)FUN_004029f6(0x33);
    }
    if (((uint)local_14 & 2) != 0) {
      param_1 = (HWND)FUN_004029f6(0x44);
    }
    if (local_2c == 0x21) {
      pHVar19 = (HWND)FUN_004029d9(1);
      UVar27 = FUN_004029d9(2);
      if ((int)local_14 >> 2 == 0) {
        pHVar19 = (HWND)SendMessageA(pHVar19,UVar27,local_44.bottom,(LPARAM)param_1);
        local_c = pHVar19;
        local_28[1] = local_28[0];
      }
      else {
        LVar5 = SendMessageTimeoutA(pHVar19,UVar27,local_44.bottom,(LPARAM)param_1,0,
                                    (int)local_14 >> 2,(PDWORD_PTR)&local_c);
        local_8 = (byte *)(uint)(LVar5 == 0);
        pHVar19 = local_c;
        local_28[1] = local_28[0];
      }
    }
    else {
      pbVar21 = FUN_004029f6(1);
      pbVar10 = FUN_004029f6(0x12);
      pHVar19 = FindWindowExA((HWND)local_44.bottom,param_1,
                              (LPCSTR)(-(uint)(*pbVar21 != 0) & (uint)pbVar21),
                              (LPCSTR)(-(uint)(*pbVar10 != 0) & (uint)pbVar10));
      local_c = pHVar19;
      local_28[1] = local_28[0];
    }
joined_r0x004025ef:
    if (-1 < (int)local_28[1]) goto switchD_00401a72_default;
    break;
  case 0x22:
    pHVar19 = (HWND)FUN_004029d9(0);
    puVar11 = (undefined *)IsWindow(pHVar19);
    local_1c.dwLowDateTime = (DWORD)local_28[1];
joined_r0x004019d4:
    if (puVar11 == (undefined *)0x0) {
      return local_20;
    }
    return (byte *)local_1c.dwLowDateTime;
  case 0x23:
    iVar20 = FUN_004029d9(2);
    pHVar19 = (HWND)FUN_004029d9(1);
    pHVar19 = GetDlgItem(pHVar19,iVar20);
    goto switchD_00401a72_default;
  case 0x24:
    pbVar21 = local_28[1] + DAT_0042eba8;
    iVar20 = -0x15;
    pHVar19 = (HWND)FUN_004029d9(0);
    SetWindowLongA(pHVar19,iVar20,(LONG)pbVar21);
    break;
  case 0x25:
    pHVar19 = GetDlgItem(DAT_0042eb68,(int)local_28[1]);
    GetClientRect(pHVar19,&local_44);
    fuLoad = 0x10;
    iVar20 = local_44.bottom * (int)local_20;
    iVar9 = local_44.right * (int)local_20;
    UVar27 = 0;
    pbVar21 = FUN_004029f6(0);
    pvVar17 = LoadImageA((HINSTANCE)0x0,(LPCSTR)pbVar21,UVar27,iVar9,iVar20,fuLoad);
    ho = (HGDIOBJ)SendMessageA(pHVar19,0x172,0,(LPARAM)pvVar17);
    if (ho != (HGDIOBJ)0x0) {
      DeleteObject(ho);
    }
    break;
  case 0x26:
    nDenominator = 0x48;
    iVar20 = 0x5a;
    hdc = GetDC(DAT_0042eb68);
    iVar20 = GetDeviceCaps(hdc,iVar20);
    iVar9 = FUN_004029d9(2);
    _DAT_0040af84 = MulDiv(iVar9,iVar20,nDenominator);
    _DAT_0040af84 = -_DAT_0040af84;
    _DAT_0040af94 = FUN_004029d9(3);
    DAT_0040af98 = (byte)local_1c.dwHighDateTime & 1;
    DAT_0040af9b = 1;
    DAT_0040af99 = (byte)local_1c.dwHighDateTime & 2;
    DAT_0040af9a = (byte)local_1c.dwHighDateTime & 4;
    FUN_00405a2e(&DAT_0040afa0,(int)local_28[1]);
    pHVar19 = (HWND)CreateFontIndirectA((LOGFONTA *)&DAT_0040af84);
switchD_00401a72_default:
    FUN_0040596a((LPSTR)pHVar22,pHVar19);
    break;
  case 0x27:
    pHVar19 = (HWND)FUN_004029d9(0);
    iVar20 = FUN_004029d9(1);
    if ((byte *)local_1c.dwLowDateTime == (byte *)0x0) {
      ShowWindow(pHVar19,iVar20);
    }
    else {
      EnableWindow(pHVar19,iVar20);
    }
    break;
  case 0x28:
    pbVar21 = FUN_004029f6(0);
    pbVar10 = FUN_004029f6(0x31);
    pbVar25 = FUN_004029f6(0x22);
    FUN_004029f6(0x15);
    FUN_00401423(-0x14);
    pHVar6 = ShellExecuteA((HWND)local_44.bottom,(LPCSTR)(-(uint)(*pbVar21 != 0) & (uint)pbVar21),
                           (LPCSTR)pbVar10,(LPCSTR)(-(uint)(*pbVar25 != 0) & (uint)pbVar25),
                           &DAT_00434800,local_1c.dwLowDateTime);
    if ((int)pHVar6 < 0x21) goto LAB_0040265c;
    break;
  case 0x29:
    pbVar21 = FUN_004029f6(0);
    FUN_00404daa(-0x15,(LPCSTR)pbVar21);
    param_1 = FUN_0040526c((LPSTR)pbVar21);
    if (param_1 == (HWND)0x0) goto LAB_0040265c;
    pHVar19 = param_1;
    if (local_20 != (byte *)0x0) {
      while (DVar14 = WaitForSingleObject(param_1,100), DVar14 == 0x102) {
        FUN_00405d67(0xf);
      }
      GetExitCodeProcess(param_1,(LPDWORD)&local_c);
      if ((int)local_28[1] < 0) {
        pHVar19 = param_1;
        if (local_c != (HWND)0x0) {
          local_8 = (byte *)0x1;
        }
      }
      else {
        FUN_0040596a((LPSTR)lpBuffer_00,local_c);
        pHVar19 = param_1;
      }
    }
LAB_00401e8a:
    CloseHandle(pHVar19);
    break;
  case 0x2a:
    pbVar21 = FUN_004029f6(2);
    pHVar19 = (HWND)FUN_00405d07((LPCSTR)pbVar21);
    if (pHVar19 != (HWND)0x0) {
      param_1 = pHVar19;
      FUN_0040596a((LPSTR)lpBuffer_00,pHVar19[5].unused);
      pHVar19 = (HWND)pHVar19[6].unused;
      goto switchD_00401a72_default;
    }
    *(undefined1 *)&pHVar22->unused = 0;
    *(undefined1 *)&lpBuffer_00->unused = 0;
    goto LAB_0040265c;
  case 0x2b:
    local_30 = FUN_004029f6(0xffffffee);
    local_c = (HWND)GetFileVersionInfoSizeA((LPCSTR)local_30,(LPDWORD)&local_34);
    *(undefined1 *)&pHVar22->unused = 0;
    *(undefined1 *)&lpBuffer_00->unused = 0;
    local_8 = (byte *)0x1;
    if ((local_c != (HWND)0x0) &&
       (param_1 = GlobalAlloc(0x40,(SIZE_T)local_c), param_1 != (HWND)0x0)) {
      BVar16 = GetFileVersionInfoA((LPCSTR)local_30,0,(DWORD)local_c,param_1);
      pHVar19 = param_1;
      if ((BVar16 != 0) &&
         (BVar16 = VerQueryValueA(param_1,&DAT_00409010,(LPVOID *)&local_44.bottom,(PUINT)&local_48)
         , pHVar19 = param_1, BVar16 != 0)) {
        FUN_0040596a((LPSTR)pHVar22,((HWND)(local_44.bottom + 8))->unused);
        FUN_0040596a((LPSTR)lpBuffer_00,((HWND)(local_44.bottom + 0xc))->unused);
        local_8 = (byte *)0x0;
        pHVar19 = param_1;
      }
LAB_00401b75:
      GlobalFree(pHVar19);
    }
    break;
  case 0x2c:
    local_8 = (byte *)0x1;
    if (DAT_0042ec18 < 0) {
      iVar20 = -0x19;
    }
    else {
      pbVar21 = FUN_004029f6(0xfffffff0);
      param_1 = (HWND)FUN_004029f6(1);
      if ((((byte *)local_1c.dwHighDateTime != (byte *)0x0) &&
          (hModule = GetModuleHandleA((LPCSTR)pbVar21), hModule != (HMODULE)0x0)) ||
         (hModule = LoadLibraryExA((LPCSTR)pbVar21,(HANDLE)0x0,8), hModule != (HMODULE)0x0)) {
        pFVar7 = GetProcAddress(hModule,(LPCSTR)param_1);
        if (pFVar7 == (FARPROC)0x0) {
          FUN_00404daa(-9,(LPCSTR)param_1);
        }
        else {
          local_8 = (byte *)0x0;
          if (local_20 == (byte *)0x0) {
            (*pFVar7)(local_44.bottom,0x400,&DAT_0042f000,&DAT_0040af80,&PTR_DAT_00409000);
          }
          else {
            FUN_00401423((int)local_20);
            iVar20 = (*pFVar7)();
            if (iVar20 != 0) {
              local_8 = (byte *)0x1;
            }
          }
        }
        if (((byte *)local_1c.dwLowDateTime == (byte *)0x0) &&
           (iVar20 = FUN_004034f5((int)hModule), iVar20 != 0)) {
          FreeLibrary(hModule);
        }
        break;
      }
      iVar20 = -10;
    }
    goto LAB_00402164;
  case 0x2d:
    local_34 = FUN_004029f6(0xfffffff0);
    pbVar21 = FUN_004029f6(0xffffffdf);
    local_30 = FUN_004029f6(2);
    local_c = (HWND)FUN_004029f6(0xffffffcd);
    local_48 = FUN_004029f6(0x45);
    iVar20 = FUN_0040556c(pbVar21);
    if (iVar20 == 0) {
      FUN_004029f6(0x21);
    }
    HVar8 = CoCreateInstance((IID *)&DAT_00407490,(LPUNKNOWN)0x0,1,(IID *)&DAT_00407480,&param_1);
    if (-1 < HVar8) {
      iVar20 = (**(code **)param_1->unused)(param_1,&DAT_004074a0,&local_44.bottom);
      if (-1 < iVar20) {
        iVar20 = (**(code **)(param_1->unused + 0x50))(param_1,pbVar21);
        (**(code **)(param_1->unused + 0x24))(param_1,&DAT_00434800);
        uVar18 = (int)local_1c.dwHighDateTime >> 8 & 0xff;
        if (uVar18 != 0) {
          (**(code **)(param_1->unused + 0x3c))(param_1,uVar18);
        }
        (**(code **)(param_1->unused + 0x34))(param_1,(int)local_1c.dwHighDateTime >> 0x10);
        if ((byte)local_c->unused != 0) {
          (**(code **)(param_1->unused + 0x44))(param_1,local_c,local_1c.dwHighDateTime & 0xff);
        }
        (**(code **)(param_1->unused + 0x2c))(param_1,local_30);
        (**(code **)(param_1->unused + 0x1c))(param_1,local_48);
        if (-1 < iVar20) {
          iVar20 = -0x7fffbffb;
          iVar9 = MultiByteToWideChar(0,0,(LPCSTR)local_34,-1,(LPWSTR)&DAT_00409378,0x400);
          if (iVar9 != 0) {
            iVar20 = (**(code **)(*(int *)local_44.bottom + 0x18))(local_44.bottom,&DAT_00409378,1);
          }
        }
        (**(code **)(*(int *)local_44.bottom + 8))(local_44.bottom);
      }
      (**(code **)(param_1->unused + 8))(param_1);
      if (-1 < iVar20) {
        iVar20 = -0xc;
        goto LAB_00402164;
      }
    }
    local_8 = (byte *)0x1;
    iVar20 = -0x10;
    goto LAB_00402164;
  case 0x2e:
    pbVar21 = FUN_004029f6(0);
    pbVar10 = FUN_004029f6(0x11);
    param_1 = (HWND)FUN_004029f6(0x23);
    puVar11 = FUN_00405d07((LPCSTR)pbVar21);
    if (puVar11 != (undefined *)0x0) {
      local_68.hwnd = (HWND)local_44.bottom;
      local_68.wFunc = 2;
      iVar20 = lstrlenA((LPCSTR)pbVar21);
      pbVar21[iVar20 + 1] = 0;
      iVar20 = lstrlenA((LPCSTR)pbVar10);
      pbVar10[iVar20 + 1] = 0;
      local_68.lpszProgressTitle = (LPCSTR)param_1;
      local_68.fFlags = (FILEOP_FLAGS)local_20;
      local_68.pFrom = (LPCSTR)pbVar21;
      local_68.pTo = (LPCSTR)pbVar10;
      FUN_00404daa(0,(LPCSTR)param_1);
      iVar20 = SHFileOperationA(&local_68);
      if (iVar20 == 0) break;
    }
    FUN_00404daa(-7,(LPCSTR)0x0);
    goto LAB_0040265c;
  case 0x2f:
    if (local_28[0] != (byte *)0xbadf00d) {
LAB_004021fb:
      uVar18 = 0x200010;
      puVar11 = (undefined *)FUN_00405a2e((byte *)0x0,-0x18);
LAB_00402209:
      FUN_004052cd(puVar11,uVar18);
      return (byte *)0x7fffffff;
    }
    DAT_0042ebf4 = DAT_0042ebf4 + 1;
    break;
  case 0x30:
    pbVar10 = (byte *)0x0;
    pbVar25 = (byte *)0x0;
    if (local_28[0] != (byte *)0x0) {
      pbVar10 = FUN_004029f6(0);
    }
    if (local_28[1] != (byte *)0x0) {
      pbVar25 = FUN_004029f6(0x11);
    }
    if ((byte *)local_1c.dwHighDateTime != (byte *)0x0) {
      pbVar21 = FUN_004029f6(0x22);
    }
    lpFileName = FUN_004029f6(0xffffffcd);
    pCVar15 = (LPSTR)WritePrivateProfileStringA
                               ((LPCSTR)pbVar10,(LPCSTR)pbVar25,(LPCSTR)pbVar21,(LPCSTR)lpFileName);
LAB_004015a6:
    bVar26 = pCVar15 == (LPSTR)0x0;
LAB_004015a8:
    if (bVar26) goto LAB_0040265c;
    break;
  case 0x31:
    param_1 = (HWND)0x7e4e21;
    pbVar21 = FUN_004029f6(1);
    local_34 = FUN_004029f6(0x12);
    pbVar10 = FUN_004029f6(0xffffffdd);
    GetPrivateProfileStringA
              ((LPCSTR)pbVar21,(LPCSTR)local_34,(LPCSTR)&param_1,(LPSTR)pHVar22,0x3ff,
               (LPCSTR)pbVar10);
    DVar14 = pHVar22->unused - (int)param_1;
LAB_00401716:
    if (DVar14 == 0) {
LAB_00402630:
      local_8 = (byte *)0x1;
      *(undefined1 *)&pHVar22->unused = 0;
    }
    break;
  case 0x32:
    if ((byte *)local_1c.dwHighDateTime == (byte *)0x0) {
      pHVar12 = (HKEY)FUN_00402b00((HKEY)0x2);
      if (pHVar12 == (HKEY)0x0) goto LAB_0040265c;
      pbVar21 = FUN_004029f6(0x33);
      LVar13 = RegDeleteValueA(pHVar12,(LPCSTR)pbVar21);
      RegCloseKey(pHVar12);
    }
    else {
      pbVar21 = FUN_004029f6(0x22);
      uVar18 = local_1c.dwHighDateTime & 2;
      pHVar12 = (HKEY)FUN_00402aeb((int)local_28[1]);
      LVar13 = FUN_00402a36(pHVar12,(LPCSTR)pbVar21,uVar18);
    }
    if (LVar13 != 0) goto LAB_0040265c;
    break;
  case 0x33:
    pHVar12 = (HKEY)FUN_00402aeb((int)local_28[0]);
    local_34 = local_14;
    local_48 = FUN_004029f6(2);
    pbVar21 = FUN_004029f6(0x11);
    local_8 = (byte *)0x1;
    LVar13 = RegCreateKeyExA(pHVar12,(LPCSTR)pbVar21,0,(LPSTR)0x0,0,DAT_0042ec10 | 2,
                             (LPSECURITY_ATTRIBUTES)0x0,(PHKEY)&param_1,(LPDWORD)0x0);
    if (LVar13 == 0) {
      puVar11 = (undefined *)0x0;
      if ((byte *)local_1c.dwHighDateTime == (byte *)0x1) {
        FUN_004029f6(0x23);
        iVar20 = lstrlenA(&DAT_0040a380);
        puVar11 = (undefined *)(iVar20 + 1);
      }
      if ((byte *)local_1c.dwHighDateTime == (byte *)0x4) {
        _DAT_0040a380 = FUN_004029d9(3);
        puVar11 = (undefined *)0x4;
      }
      if ((byte *)local_1c.dwHighDateTime == (byte *)0x3) {
        puVar11 = FUN_00402e5b(local_1c.dwLowDateTime,(HANDLE)0x0,&DAT_0040a380,(undefined *)0xc00);
      }
      LVar13 = RegSetValueExA((HKEY)param_1,(LPCSTR)local_48,0,(DWORD)local_34,&DAT_0040a380,
                              (DWORD)puVar11);
      pHVar12 = (HKEY)param_1;
      if (LVar13 == 0) {
        local_8 = (byte *)0x0;
      }
      goto LAB_0040247d;
    }
    break;
  case 0x34:
    pHVar12 = (HKEY)FUN_00402b00((HKEY)0x20019);
    pbVar21 = FUN_004029f6(0x33);
    *(undefined1 *)&pHVar22->unused = 0;
    if (pHVar12 == (HKEY)0x0) goto LAB_0040265c;
    local_c = (HWND)0x3ff;
    LVar13 = RegQueryValueExA(pHVar12,(LPCSTR)pbVar21,(LPDWORD)0x0,(LPDWORD)&param_1,(LPBYTE)pHVar22
                              ,(LPDWORD)&local_c);
    if (LVar13 == 0) {
      if (param_1 == (HWND)0x4) {
        local_8 = (byte *)(uint)((byte *)local_1c.dwHighDateTime == (byte *)0x0);
        FUN_0040596a((LPSTR)pHVar22,pHVar22->unused);
      }
      else {
        if ((param_1 != (HWND)0x1) && (param_1 != (HWND)0x2)) goto LAB_00402420;
        local_8 = (byte *)local_1c.dwHighDateTime;
        *(byte *)((int)&local_c->unused + (int)pHVar22) = 0;
      }
    }
    else {
LAB_00402420:
      *(undefined1 *)&pHVar22->unused = 0;
      local_8 = (byte *)0x1;
    }
LAB_0040247d:
    RegCloseKey(pHVar12);
    break;
  case 0x35:
    pHVar12 = (HKEY)FUN_00402b00((HKEY)0x20019);
    DVar14 = FUN_004029d9(3);
    *(undefined1 *)&pHVar22->unused = 0;
    if (pHVar12 != (HKEY)0x0) {
      param_1 = (HWND)0x3ff;
      if ((byte *)local_1c.dwHighDateTime == (byte *)0x0) {
        LVar13 = RegEnumValueA(pHVar12,DVar14,(LPSTR)pHVar22,(LPDWORD)&param_1,(LPDWORD)0x0,
                               (LPDWORD)0x0,(LPBYTE)0x0,(LPDWORD)0x0);
        if (LVar13 != 0) goto LAB_0040265c;
      }
      else {
        RegEnumKeyA(pHVar12,DVar14,(LPSTR)pHVar22,0x3ff);
      }
      (&DAT_0042f3ff)[iVar20] = 0;
      goto LAB_0040247d;
    }
    goto LAB_0040265c;
  case 0x36:
    if ((char)pHVar22->unused != '\0') {
      pHVar19 = (HWND)FUN_00405983((byte *)pHVar22);
      goto LAB_00401e8a;
    }
    break;
  case 0x37:
    pbVar21 = FUN_004029f6(0xffffffed);
    pHVar19 = (HWND)FUN_004056e3((LPCSTR)pbVar21,(DWORD)local_28[1],(DWORD)local_20);
    if (pHVar19 != (HWND)0xffffffff) goto switchD_00401a72_default;
LAB_0040265a:
    *(undefined1 *)&pHVar22->unused = 0;
    goto LAB_0040265c;
  case 0x38:
    if (local_20 == (byte *)0x0) {
      pbVar21 = FUN_004029f6(0x11);
      DVar14 = lstrlenA((LPCSTR)pbVar21);
    }
    else {
      DAT_00409f80 = FUN_004029d9(1);
      DVar14 = 1;
    }
    if ((char)pHVar22->unused != '\0') {
      lpNumberOfBytesWritten = &param_1;
      lpOverlapped = (LPOVERLAPPED)0x0;
      lpBuffer_01 = &DAT_00409f80;
      pvVar17 = (HANDLE)FUN_00405983((byte *)pHVar22);
      pCVar15 = (LPSTR)WriteFile(pvVar17,lpBuffer_01,DVar14,(LPDWORD)lpNumberOfBytesWritten,
                                 lpOverlapped);
      goto LAB_004015a6;
    }
LAB_0040265c:
    local_8 = (byte *)0x1;
    break;
  case 0x39:
    local_30 = (byte *)0x0;
    local_44.bottom = FUN_004029d9(2);
    if (local_44.bottom < 1) break;
    if (0x3ff < local_44.bottom) {
      local_44.bottom = 0x3ff;
    }
    pbVar21 = local_30;
    if ((char)pHVar22->unused != '\0') {
      param_1 = (HWND)((uint)param_1 & 0xffffff);
      local_c = (HWND)FUN_00405983((byte *)pHVar22);
      pbVar21 = local_30;
      if (0 < local_44.bottom) {
        while( true ) {
          BVar16 = ReadFile(local_c,&local_d,1,(LPDWORD)&local_34,(LPOVERLAPPED)0x0);
          if ((BVar16 == 0) || (local_34 != (byte *)0x1)) goto LAB_004025c1;
          if ((byte *)local_1c.dwLowDateTime != (byte *)0x0) {
            FUN_0040596a((LPSTR)lpBuffer_00,(uint)local_d);
            goto LAB_00402894;
          }
          if ((param_1._3_1_ == 0xd) || (param_1._3_1_ == 10)) break;
          *(byte *)((int)&lpBuffer_00->unused + (int)pbVar21) = local_d;
          pbVar21 = (byte *)((int)pbVar21 + 1);
          param_1 = (HWND)CONCAT13(local_d,param_1._0_3_);
          if ((local_d == 0) || (local_44.bottom <= (int)pbVar21)) goto LAB_004025c1;
        }
        if ((param_1._3_1_ == local_d) || ((local_d != 0xd && (local_d != 10)))) {
          SetFilePointer(local_c,-1,(PLONG)0x0,1);
        }
        else {
          *(byte *)((int)&lpBuffer_00->unused + (int)pbVar21) = local_d;
          pbVar21 = (byte *)((int)pbVar21 + 1);
        }
      }
    }
LAB_004025c1:
    *(undefined1 *)((int)&lpBuffer_00->unused + (int)pbVar21) = 0;
    bVar26 = pbVar21 == (byte *)0x0;
    goto LAB_004015a8;
  case 0x3a:
    if ((char)pHVar22->unused != '\0') {
      lpDistanceToMoveHigh = (PLONG)0x0;
      lDistanceToMove = FUN_004029d9(2);
      pvVar17 = (HANDLE)FUN_00405983((byte *)pHVar22);
      pHVar19 = (HWND)SetFilePointer(pvVar17,lDistanceToMove,lpDistanceToMoveHigh,
                                     local_1c.dwLowDateTime);
      pHVar22 = lpBuffer_00;
      goto joined_r0x004025ef;
    }
    break;
  case 0x3b:
    if ((char)pHVar22->unused != '\0') {
      pvVar17 = (HANDLE)FUN_00405983((byte *)pHVar22);
      FindClose(pvVar17);
    }
    break;
  case 0x3c:
    if ((char)lpBuffer_00->unused != '\0') {
      lpFindFileData = &local_1a8;
      pvVar17 = (HANDLE)FUN_00405983((byte *)lpBuffer_00);
      BVar16 = FindNextFileA(pvVar17,lpFindFileData);
      if (BVar16 != 0) goto LAB_0040266f;
    }
    goto LAB_00402630;
  case 0x3d:
    pbVar21 = FUN_004029f6(2);
    pvVar17 = FindFirstFileA((LPCSTR)pbVar21,&local_1a8);
    if (pvVar17 == (HANDLE)0xffffffff) {
      *(undefined1 *)&lpBuffer_00->unused = 0;
      goto LAB_0040265a;
    }
    FUN_0040596a((LPSTR)lpBuffer_00,pvVar17);
LAB_0040266f:
    pCVar23 = local_1a8.cFileName;
LAB_004027b1:
    FUN_00405a0c((LPSTR)pHVar22,pCVar23);
    break;
  case 0x3e:
    local_c = (HWND)0xfffffd66;
    pbVar21 = FUN_004029f6(0xfffffff0);
    local_48 = pbVar21;
    iVar20 = FUN_0040556c(pbVar21);
    if (iVar20 == 0) {
      FUN_004029f6(0xffffffed);
    }
    FUN_004056c4((LPCSTR)pbVar21);
    param_1 = (HWND)FUN_004056e3((LPCSTR)pbVar21,0x40000000,2);
    if (param_1 != (HWND)0xffffffff) {
      local_30 = DAT_0042eb74;
      lpBuffer = GlobalAlloc(0x40,(SIZE_T)DAT_0042eb74);
      if (lpBuffer != (HGLOBAL)0x0) {
        FUN_004030af(0);
        FUN_0040307d(lpBuffer,(DWORD)local_30);
        pbVar21 = GlobalAlloc(0x40,(SIZE_T)local_20);
        local_34 = pbVar21;
        if (pbVar21 != (byte *)0x0) {
          FUN_00402e5b((int)local_28[1],(HANDLE)0x0,pbVar21,local_20);
          for (; *pbVar21 != 0; pbVar21 = pbVar21 + 8 + local_44.right) {
            local_44.right = *(LONG *)pbVar21;
            FUN_004056a4((undefined1 *)(*(int *)(pbVar21 + 4) + (int)lpBuffer),(int)(pbVar21 + 8),
                         local_44.right);
          }
          GlobalFree(local_34);
        }
        WriteFile(param_1,lpBuffer,(DWORD)local_30,(LPDWORD)&local_c,(LPOVERLAPPED)0x0);
        GlobalFree(lpBuffer);
        local_c = (HWND)FUN_00402e5b(-1,param_1,(undefined *)0x0,(undefined *)0x0);
      }
      CloseHandle(param_1);
    }
    iVar20 = -0xd;
    if ((int)local_c < 0) {
      iVar20 = -0x11;
      DeleteFileA((LPCSTR)local_48);
      local_8 = (byte *)0x1;
    }
LAB_00402164:
    FUN_00401423(iVar20);
    break;
  case 0x3f:
    param_1 = (HWND)FUN_004029d9(0);
    if (DAT_0042eb8c <= param_1) goto LAB_0040265c;
    iVar20 = (int)param_1 * 0x418 + DAT_0042eb88;
    if (-1 < (int)local_20) {
      pHVar19 = *(HWND *)(iVar20 + (int)local_20 * 4);
      pHVar22 = lpBuffer_00;
      if (local_20 == (byte *)0x0) {
        pCVar23 = (CHAR *)(iVar20 + 0x18);
        goto LAB_004027b1;
      }
      goto switchD_00401a72_default;
    }
    local_20 = (byte *)(-1 - (int)local_20);
    if (local_20 == (byte *)0x0) {
      FUN_00405a2e((byte *)(iVar20 + 0x18),local_1c.dwHighDateTime);
      *(byte *)(iVar20 + 9) = *(byte *)(iVar20 + 9) | 1;
    }
    else {
      local_28[1] = (byte *)FUN_004029d9(1);
    }
    *(byte **)(iVar20 + (int)local_20 * 4) = local_28[1];
    if ((byte *)local_1c.dwLowDateTime != (byte *)0x0) {
      FUN_0040117d((int)param_1);
    }
    break;
  case 0x40:
    uVar18 = FUN_004029d9(0);
    if (0x1f < uVar18) goto LAB_0040265c;
    if ((byte *)local_1c.dwLowDateTime == (byte *)0x0) {
      if (local_20 == (byte *)0x0) {
        FUN_00405a2e((byte *)lpBuffer_00,*(int *)(DAT_0042eb70 + 0x94 + uVar18 * 4));
      }
      else {
        *(byte **)(DAT_0042eb70 + 0x94 + uVar18 * 4) = local_28[1];
      }
    }
    else {
      if (local_20 == (byte *)0x0) {
        pHVar19 = (HWND)FUN_004012e2(0);
        pHVar22 = lpBuffer_00;
        goto switchD_00401a72_default;
      }
      FUN_00401299(uVar18);
      FUN_004011ef(0,0);
    }
    break;
  case 0x43:
    SendMessageA(DAT_0042eb68,0xb,DAT_0042afe0 & (uint)local_28[0],0);
    if (local_28[0] != (byte *)0x0) {
      InvalidateRect((HWND)local_44.bottom,(RECT *)0x0,0);
    }
  }
switchD_00401489_caseD_41:
  _DAT_0042ebe8 = _DAT_0042ebe8 + (int)local_8;
LAB_00402894:
  local_28[0] = (byte *)0x0;
switchD_00401489_caseD_2:
  return local_28[0];
}



/* VA 004029d9 */

void FUN_004029d9(int param_1)

{
  byte *pbVar1;

  pbVar1 = (byte *)FUN_00405a2e((byte *)0x0,*(int *)(DAT_00409b78 + param_1 * 4));
  FUN_00405983(pbVar1);
  return;
}



/* VA 004029f6 */

byte * FUN_004029f6(uint param_1)

{
  uint uVar1;
  byte *pbVar2;

  uVar1 = param_1;
  if ((int)param_1 < 0) {
    uVar1 = -param_1;
  }
  pbVar2 = (byte *)FUN_00405a2e(&DAT_00409b80 + ((int)uVar1 >> 4) * 0x400,
                                *(int *)(DAT_00409b78 + (uVar1 & 0xf) * 4));
  if ((int)param_1 < 0) {
    FUN_00405c6e(pbVar2);
  }
  return pbVar2;
}



/* VA 00402a36 */

LSTATUS FUN_00402a36(HKEY param_1,LPCSTR param_2,int param_3)

{
  LSTATUS LVar1;
  code *pcVar2;
  CHAR local_110 [264];
  HKEY local_8;

  LVar1 = RegOpenKeyExA(param_1,param_2,0,DAT_0042ec10 | 8,&local_8);
  if (LVar1 == 0) {
    do {
      LVar1 = RegEnumKeyA(local_8,0,local_110,0x105);
      if (LVar1 != 0) break;
      if (param_3 != 0) {
        RegCloseKey(local_8);
        goto LAB_00402ac7;
      }
      LVar1 = FUN_00402a36(local_8,local_110,0);
    } while (LVar1 == 0);
    RegCloseKey(local_8);
    pcVar2 = (code *)FUN_00405d2e(2);
    if (pcVar2 == (code *)0x0) {
      if ((DAT_0042ec10 == 0) && (LVar1 = RegDeleteKeyA(param_1,param_2), LVar1 == 0)) {
        LVar1 = 0;
      }
      else {
LAB_00402ac7:
        LVar1 = 1;
      }
    }
    else {
      LVar1 = (*pcVar2)(param_1,param_2,DAT_0042ec10,0);
    }
  }
  return LVar1;
}



/* VA 00402aeb */

int FUN_00402aeb(int param_1)

{
  if (param_1 == 0) {
    param_1 = DAT_0042ebe4 + -0x7fffffff;
  }
  return param_1;
}



/* VA 00402b00 */

uint FUN_00402b00(HKEY param_1)

{
  uint samDesired;
  byte *lpSubKey;
  HKEY hKey;
  LSTATUS LVar1;
  DWORD ulOptions;
  HKEY *phkResult;

  phkResult = &param_1;
  samDesired = DAT_0042ec10 | (uint)param_1;
  ulOptions = 0;
  lpSubKey = FUN_004029f6(0x22);
  hKey = (HKEY)FUN_00402aeb(*(int *)(DAT_00409b78 + 4));
  LVar1 = RegOpenKeyExA(hKey,(LPCSTR)lpSubKey,ulOptions,samDesired,phkResult);
  return ~-(uint)(LVar1 != 0) & (uint)param_1;
}



/* VA 00402b3b */

undefined4 FUN_00402b3b(HWND param_1,int param_2)

{
  int iVar1;
  CHAR local_44 [64];

  if (param_2 == 0x110) {
    SetTimer(param_1,1,0xfa,(TIMERPROC)0x0);
    param_2 = 0x113;
  }
  if (param_2 == 0x113) {
    iVar1 = DAT_00414b80;
    if (DAT_00428b90 <= DAT_00414b80) {
      iVar1 = DAT_00428b90;
    }
    iVar1 = MulDiv(iVar1,100,DAT_00428b90);
    wsprintfA(local_44,s_verifying_installer___d___00409018,iVar1);
    SetWindowTextA(param_1,local_44);
    SetDlgItemTextA(param_1,0x406,local_44);
  }
  return 0;
}



/* VA 00402bbe */

void __cdecl FUN_00402bbe(int param_1)

{
  DWORD DVar1;

  if (param_1 != 0) {
    if (DAT_00420b88 != (HWND)0x0) {
      DestroyWindow(DAT_00420b88);
    }
    DAT_00420b88 = (HWND)0x0;
    return;
  }
  if (DAT_00420b88 != (HWND)0x0) {
    FUN_00405d67(0);
    return;
  }
  DVar1 = GetTickCount();
  if (DAT_0042eb6c < DVar1) {
    DAT_00420b88 = CreateDialogParamA(DAT_0042eb60,(LPCSTR)0x6f,(HWND)0x0,FUN_00402b3b,0);
    ShowWindow(DAT_00420b88,5);
  }
  return;
}



/* VA 00402c22 */

char * FUN_00402c22(uint param_1)

{
  DWORD DVar1;
  HANDLE hFile;
  LPCSTR pCVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  int *piVar8;
  uint uVar9;
  uint local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined *local_18;
  int local_14;
  HANDLE local_10;
  uint local_c;
  int local_8;

  local_c = 0;
  local_8 = 0;
  DVar1 = GetTickCount();
  DAT_0042eb6c = DVar1 + 1000;
  GetModuleFileNameA((HMODULE)0x0,&DAT_00435c00,0x400);
  hFile = (HANDLE)FUN_004056e3(&DAT_00435c00,0x80000000,3);
  if (hFile == (HANDLE)0xffffffff) {
    DAT_00409014 = hFile;
    return s_Error_launching_installer_00409104;
  }
  DAT_00409014 = hFile;
  local_10 = hFile;
  FUN_00405a0c(&DAT_00434c00,&DAT_00435c00);
  pCVar2 = FUN_00405546(&DAT_00434c00);
  FUN_00405a0c(&DAT_00436000,pCVar2);
  uVar3 = GetFileSize(hFile,(LPDWORD)0x0);
  DAT_00428b90 = uVar3;
  for (; 0 < (int)uVar3; uVar3 = uVar3 - uVar9) {
    uVar4 = (-(uint)(DAT_0042eb74 != 0) & 0x7e00) + 0x200;
    uVar9 = uVar3;
    if ((int)uVar4 <= (int)uVar3) {
      uVar9 = uVar4;
    }
    iVar5 = FUN_0040307d(&DAT_00420b90,uVar9);
    if (iVar5 == 0) {
      FUN_00402bbe(1);
      goto LAB_00402dfa;
    }
    if (DAT_0042eb74 == 0) {
      FUN_004056a4((undefined1 *)&local_2c,0x420b90,0x1c);
      if (((((local_2c & 0xfffffff0) == 0) && (local_28 == -0x21524111)) && (local_1c == 0x74736e49)
          ) && ((local_20 == 0x74666f73 && (local_24 == 0x6c6c754e)))) {
        param_1 = param_1 | local_2c;
        DAT_0042ec00 = DAT_0042ec00 | param_1 & 2;
        DAT_0042eb74 = DAT_00414b80;
        if ((int)uVar3 < local_14) goto LAB_00402dfa;
        if (((param_1 & 8) == 0) && ((param_1 & 4) != 0)) break;
        local_8 = local_8 + 1;
        uVar3 = local_14 - 4;
        if (uVar3 < uVar9) {
          uVar9 = uVar3;
        }
      }
    }
    else if ((param_1 & 2) == 0) {
      FUN_00402bbe(0);
    }
    if ((int)uVar3 < (int)DAT_00428b90) {
      local_c = FUN_00405d9a(local_c,&DAT_00420b90,uVar9);
    }
    DAT_00414b80 = DAT_00414b80 + uVar9;
  }
  FUN_00402bbe(1);
  if (DAT_0042eb74 != 0) {
    if (local_8 != 0) {
      FUN_004030af(DAT_00414b80);
      iVar5 = FUN_0040307d(&param_1,4);
      if ((iVar5 == 0) || (local_c != param_1)) goto LAB_00402dfa;
    }
    puVar6 = GlobalAlloc(0x40,(SIZE_T)local_18);
    FUN_004030af(DAT_0042eb74 + 0x1c);
    puVar7 = FUN_00402e5b(-1,(HANDLE)0x0,(undefined *)puVar6,local_18);
    if (puVar7 == local_18) {
      DAT_0042eb78 = *puVar6;
      if ((local_2c & 1) != 0) {
        DAT_0042eb7c = DAT_0042eb7c + 1;
      }
      piVar8 = puVar6 + 0x11;
      iVar5 = 8;
      DAT_0042eb70 = puVar6;
      do {
        piVar8 = piVar8 + -2;
        *piVar8 = *piVar8 + (int)puVar6;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      DVar1 = SetFilePointer(local_10,0,(PLONG)0x0,1);
      puVar6[0xf] = DVar1;
      FUN_004056a4(&DAT_0042eb80,(int)(puVar6 + 1),0x40);
      return (char *)0x0;
    }
  }
LAB_00402dfa:
  return s_Installer_integrity_check_has_fa_00409038;
}



/* VA 00402e5b */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00402e5b(int param_1,HANDLE param_2,undefined *param_3,undefined *param_4)

{
  int iVar1;
  DWORD DVar2;
  BOOL BVar3;
  DWORD nNumberOfBytesToWrite;
  undefined *puVar4;
  undefined *puVar5;
  CHAR local_5c [64];
  int local_1c;
  DWORD local_18;
  DWORD local_14;
  undefined *local_10;
  undefined *local_c;
  undefined *local_8;

  puVar4 = param_4;
  puVar5 = param_3;
  local_c = param_4;
  if (param_3 == (undefined *)0x0) {
    local_c = (undefined *)0x8000;
  }
  local_8 = (undefined *)0x0;
  local_10 = param_3;
  if (param_3 == (undefined *)0x0) {
    local_10 = &DAT_00418b88;
  }
  if (-1 < param_1) {
    FUN_004030af(DAT_0042ebb8 + param_1);
  }
  iVar1 = FUN_0040307d(&param_4,4);
  if (iVar1 != 0) {
    if (((uint)param_4 & 0x80000000) == 0) {
      if (puVar5 == (undefined *)0x0) {
        while( true ) {
          if ((int)param_4 < 1) {
            return local_8;
          }
          puVar5 = local_c;
          if ((int)param_4 < (int)local_c) {
            puVar5 = param_4;
          }
          iVar1 = FUN_0040307d(&DAT_00414b88,(DWORD)puVar5);
          if (iVar1 == 0) break;
          BVar3 = WriteFile(param_2,&DAT_00414b88,(DWORD)puVar5,(LPDWORD)&param_3,(LPOVERLAPPED)0x0)
          ;
          if ((BVar3 == 0) || (puVar5 != param_3)) {
            return (undefined *)0xfffffffe;
          }
          local_8 = local_8 + (int)puVar5;
          param_4 = param_4 + -(int)puVar5;
        }
      }
      else {
        if ((int)param_4 < (int)puVar4) {
          puVar4 = param_4;
        }
        iVar1 = FUN_0040307d(puVar5,(DWORD)puVar4);
        if (iVar1 != 0) {
          return puVar4;
        }
      }
    }
    else {
      local_14 = GetTickCount();
      _DAT_0040b4ec = 0;
      _DAT_0040b4e8 = 0;
      puVar5 = (undefined *)((uint)param_4 & 0x7fffffff);
      _DAT_0040afd0 = 8;
      _DAT_00414b78 = &DAT_0040cb70;
      _DAT_00414b74 = &DAT_0040cb70;
      _DAT_00414b70 = &DAT_00414b70;
      param_4 = puVar5;
      if (puVar5 == (undefined *)0x0) {
        _DAT_0040afd0 = 8;
        _DAT_0040b4e8 = 0;
        _DAT_0040b4ec = 0;
        return local_8;
      }
      while( true ) {
        puVar4 = (undefined *)0x4000;
        if ((int)param_4 < 0x4000) {
          puVar4 = param_4;
        }
        iVar1 = FUN_0040307d(&DAT_00414b88,(DWORD)puVar4);
        if (iVar1 == 0) break;
        param_4 = param_4 + -(int)puVar4;
        _DAT_0040afc0 = &DAT_00414b88;
        _DAT_0040afc4 = puVar4;
        while( true ) {
          puVar4 = local_10;
          DAT_0040afc8 = local_10;
          _DAT_0040afcc = local_c;
          local_1c = FUN_00405e08((int *)&DAT_0040afc0);
          if (local_1c < 0) {
            return (undefined *)0xfffffffc;
          }
          nNumberOfBytesToWrite = (int)DAT_0040afc8 - (int)puVar4;
          DVar2 = GetTickCount();
          if ((((byte)DAT_0042ec14 & 1) != 0) &&
             ((200 < DVar2 - local_14 || (param_4 == (undefined *)0x0)))) {
            iVar1 = MulDiv((int)puVar5 - (int)param_4,100,(int)puVar5);
            wsprintfA(local_5c,s______d___00409120,iVar1);
            FUN_00404daa(0,local_5c);
            local_14 = DVar2;
          }
          if (nNumberOfBytesToWrite == 0) break;
          if (param_3 == (undefined *)0x0) {
            BVar3 = WriteFile(param_2,local_10,nNumberOfBytesToWrite,&local_18,(LPOVERLAPPED)0x0);
            if (BVar3 == 0) {
              return (undefined *)0xfffffffe;
            }
            if (local_18 != nNumberOfBytesToWrite) {
              return (undefined *)0xfffffffe;
            }
          }
          else {
            local_c = local_c + -nNumberOfBytesToWrite;
            local_10 = DAT_0040afc8;
          }
          local_8 = local_8 + nNumberOfBytesToWrite;
          if (local_1c == 1) {
            return local_8;
          }
        }
        if ((int)param_4 < 1) {
          return local_8;
        }
      }
    }
  }
  return (undefined *)0xfffffffd;
}



/* VA 0040307d */

undefined4 FUN_0040307d(LPVOID param_1,DWORD param_2)

{
  DWORD DVar1;
  BOOL BVar2;
  undefined4 uVar3;

  DVar1 = param_2;
  BVar2 = ReadFile(DAT_00409014,param_1,param_2,&param_2,(LPOVERLAPPED)0x0);
  if ((BVar2 == 0) || (param_2 != DVar1)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



/* VA 004030af */

void FUN_004030af(LONG param_1)

{
  SetFilePointer(DAT_00409014,param_1,(PLONG)0x0,0);
  return;
}



/* VA 004030c6 */

void FUN_004030c6(void)

{
  int iVar1;

  FUN_00405c6e(&DAT_00435400);
  iVar1 = FUN_0040556c(&DAT_00435400);
  if (iVar1 == 0) {
    return;
  }
  FUN_004054ff(&DAT_00435400);
  CreateDirectoryA(&DAT_00435400,(LPSECURITY_ATTRIBUTES)0x0);
  FUN_00405712(&DAT_00435000,&DAT_00435400);
  return;
}



/* VA 004030fa */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  char cVar1;
  bool bVar2;
  LPSTR pCVar3;
  char *pcVar4;
  LPCSTR lpsz;
  int *piVar5;
  int *piVar6;
  int iVar7;
  undefined3 extraout_var;
  code *pcVar8;
  code *pcVar9;
  code *pcVar10;
  HANDLE pvVar11;
  BOOL BVar12;
  uint uVar13;
  undefined4 uVar14;
  int **ppiVar15;
  char *local_180;
  char local_17c [4];
  UINT local_178;
  int *local_174;
  undefined4 uStack_170;
  undefined1 auStack_16c [12];
  SHFILEINFOA local_160;

  local_178 = 0;
  local_180 = s_Error_writing_temporary_file__Ma_00409160;
  uVar13 = 0;
  local_17c[0] = ' ';
  InitCommonControls();
  SetErrorMode(0x8001);
  DAT_0042ec18 = OleInitialize((LPVOID)0x0);
  DAT_0042eb64 = FUN_00405d2e(8);
  SHGetFileInfoA(&DAT_00428f98,0,&local_160,0x160,0);
  FUN_00405a0c(&DAT_0042e360,s_NSIS_Error_00409154);
  pCVar3 = GetCommandLineA();
  FUN_00405a0c(&DAT_00434000,pCVar3);
  DAT_0042eb60 = GetModuleHandleA((LPCSTR)0x0);
  pcVar4 = &DAT_00434000;
  if (DAT_00434000 == '\"') {
    local_17c[0] = '\"';
    pcVar4 = &DAT_00434001;
  }
  lpsz = (LPCSTR)FUN_0040552a(pcVar4,local_17c[0]);
  piVar5 = (int *)CharNextA(lpsz);
  local_174 = piVar5;
  while (cVar1 = (char)*piVar5, cVar1 != '\0') {
    while (cVar1 == ' ') {
      piVar5 = (int *)((int)piVar5 + 1);
      cVar1 = *(char *)piVar5;
    }
    local_17c[0] = ' ';
    if ((char)*piVar5 == '\"') {
      piVar5 = (int *)((int)piVar5 + 1);
      local_17c[0] = '\"';
    }
    piVar6 = piVar5;
    if ((char)*piVar5 == '/') {
      piVar6 = (int *)((int)piVar5 + 1);
      if ((*(char *)piVar6 == 'S') && ((*(byte *)((int)piVar5 + 2) | 0x20) == 0x20)) {
        uVar13 = uVar13 | 2;
      }
      if ((*piVar6 == 0x4352434e) && ((*(byte *)((int)piVar5 + 5) | 0x20) == 0x20)) {
        uVar13 = uVar13 | 4;
      }
      if (*(int *)((int)piVar5 + -1) == 0x3d442f20) {
        pcVar4 = (char *)((int)piVar5 + -1);
        pcVar4[0] = '\0';
        pcVar4[1] = '\0';
        pcVar4[2] = '\0';
        pcVar4[3] = '\0';
        FUN_00405a0c(&DAT_00434400,(LPCSTR)((int)piVar5 + 3));
        break;
      }
    }
    piVar5 = (int *)FUN_0040552a((LPCSTR)piVar6,local_17c[0]);
    if ((char)*piVar5 == '\"') {
      piVar5 = (int *)((int)piVar5 + 1);
    }
  }
  GetTempPathA(0x400,&DAT_00435400);
  iVar7 = FUN_004030c6();
  if (iVar7 == 0) {
    GetWindowsDirectoryA(&DAT_00435400,0x3fb);
    lstrcatA(&DAT_00435400,s__Temp_0040914c);
    iVar7 = FUN_004030c6();
    if (iVar7 == 0) goto LAB_004032e6;
  }
  DeleteFileA(&DAT_00435000);
  local_180 = FUN_00402c22(uVar13);
  if (local_180 != (char *)0x0) goto LAB_004032e6;
  if (DAT_0042eb7c != 0) {
    for (piVar5 = (int *)FUN_0040552a(&DAT_00434000,'\0');
        ((int *)0x433fff < piVar5 && (*piVar5 != 0x3d3f5f20)); piVar5 = (int *)((int)piVar5 + -1)) {
    }
    local_180 = s_Error_launching_installer_00409104;
    if (piVar5 < &DAT_00434000) {
      lstrcatA(&DAT_00435400,s__nsu_tmp_00409140);
      iVar7 = lstrcmpiA(&DAT_00435400,&DAT_00434c00);
      if (iVar7 != 0) {
        CreateDirectoryA(&DAT_00435400,(LPSECURITY_ATTRIBUTES)0x0);
        SetCurrentDirectoryA(&DAT_00435400);
        if (DAT_00434400 == '\0') {
          FUN_00405a0c(&DAT_00434400,&DAT_00434c00);
        }
        FUN_00405a0c(&DAT_0042f000,(LPCSTR)local_174);
        _DAT_0042f400 = 0x41;
        iVar7 = 0x1a;
        do {
          FUN_00405a2e(&DAT_00428b98,*(int *)(DAT_0042eb70 + 0x120));
          DeleteFileA(&DAT_00428b98);
          if ((local_180 != (char *)0x0) &&
             (BVar12 = CopyFileA(&DAT_00435c00,&DAT_00428b98,1), BVar12 != 0)) {
            FUN_0040575a(&DAT_00428b98,(LPCSTR)0x0);
            FUN_00405a2e(&DAT_00428b98,*(int *)(DAT_0042eb70 + 0x124));
            pvVar11 = FUN_0040526c(&DAT_00428b98);
            if (pvVar11 != (HANDLE)0x0) {
              CloseHandle(pvVar11);
              local_180 = (char *)0x0;
            }
          }
          DAT_0042f400 = DAT_0042f400 + '\x01';
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        FUN_0040575a(&DAT_00435400,(LPCSTR)0x0);
      }
      goto LAB_004032e6;
    }
    *(undefined1 *)piVar5 = 0;
    piVar5 = piVar5 + 1;
    bVar2 = FUN_004055e0((LPCSTR)piVar5);
    if (CONCAT31(extraout_var,bVar2) == 0) goto LAB_004032e6;
    FUN_00405a0c(&DAT_00434400,(LPCSTR)piVar5);
    FUN_00405a0c(&DAT_00434800,(LPCSTR)piVar5);
    local_180 = (char *)0x0;
  }
  DAT_0042ec0c = -1;
  local_178 = FUN_00403555();
LAB_004032e6:
  FUN_0040347b();
  OleUninitialize();
  if (local_180 != (char *)0x0) {
    FUN_004052cd(local_180,0x200010);
                    /* WARNING: Subroutine does not return */
    ExitProcess(2);
  }
  if (DAT_0042ebf4 != 0) {
    pcVar8 = (code *)FUN_00405d2e(3);
    pcVar9 = (code *)FUN_00405d2e(4);
    pcVar10 = (code *)FUN_00405d2e(5);
    if (((pcVar8 != (code *)0x0) && (pcVar9 != (code *)0x0)) && (pcVar10 != (code *)0x0)) {
      ppiVar15 = &local_174;
      uVar14 = 0x28;
      pvVar11 = GetCurrentProcess();
      iVar7 = (*pcVar8)(pvVar11,uVar14,ppiVar15);
      if (iVar7 != 0) {
        (*pcVar9)(0,s_SeShutdownPrivilege_0040912c,auStack_16c);
        local_17c[0] = '\x01';
        local_17c[1] = '\0';
        local_17c[2] = '\0';
        local_17c[3] = '\0';
        uStack_170 = 2;
        (*pcVar10)(0,0,local_17c,0,0,0);
      }
    }
    BVar12 = ExitWindowsEx(2,0);
    if (BVar12 == 0) {
      FUN_0040140b(9);
    }
  }
  if (DAT_0042ec0c != -1) {
    local_178 = DAT_0042ec0c;
  }
                    /* WARNING: Subroutine does not return */
  ExitProcess(local_178);
}



/* VA 0040347b */

void FUN_0040347b(void)

{
  if (DAT_00409014 != (HANDLE)0xffffffff) {
    CloseHandle(DAT_00409014);
    DAT_00409014 = (HANDLE)0xffffffff;
  }
  FUN_004034c0();
  FUN_00405331(&DAT_00435800,7);
  return;
}



/* VA 004034a5 */

void FUN_004034a5(undefined4 param_1)

{
  undefined4 *puVar1;

  for (puVar1 = DAT_00428f9c; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    (*(code *)puVar1[1])(param_1);
  }
  return;
}



/* VA 004034c0 */

void FUN_004034c0(void)

{
  undefined4 *puVar1;
  undefined4 *hMem;

  hMem = DAT_00428f9c;
  FUN_004034a5(0);
  while (hMem != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*hMem;
    FreeLibrary((HMODULE)hMem[2]);
    GlobalFree(hMem);
    hMem = puVar1;
  }
  DAT_00428f9c = (undefined4 *)0x0;
  return;
}



/* VA 004034f5 */

undefined4 FUN_004034f5(int param_1)

{
  undefined4 *puVar1;

  puVar1 = DAT_00428f9c;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 1;
    }
    if (puVar1[2] == param_1) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return 0;
}



/* VA 00403513 */

undefined4 FUN_00403513(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;

  iVar1 = FUN_004034f5(param_1);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    puVar3 = GlobalAlloc(0x40,0xc);
    if (puVar3 == (undefined4 *)0x0) {
      uVar2 = 0xffffffff;
    }
    else {
      puVar3[2] = param_1;
      puVar3[1] = param_2;
      *puVar3 = DAT_00428f9c;
      uVar2 = 0;
      DAT_00428f9c = puVar3;
    }
  }
  return uVar2;
}



/* VA 00403555 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

INT_PTR FUN_00403555(void)

{
  bool bVar1;
  ATOM AVar2;
  code *pcVar3;
  uint uVar4;
  undefined3 extraout_var;
  undefined1 *puVar5;
  int iVar6;
  DWORD DVar7;
  undefined3 extraout_var_00;
  int iVar8;
  HMODULE pHVar9;
  BOOL BVar10;
  INT_PTR IVar11;
  LPCSTR pCVar12;
  char acStack_14 [4];
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;

  iVar8 = DAT_0042eb70;
  pcVar3 = (code *)FUN_00405d2e(6);
  if (pcVar3 == (code *)0x0) {
    _DAT_00435000 = 0x7830;
    FUN_004058f3((HKEY)0x80000001,"Control Panel\\Desktop\\ResourceLocale",(LPCSTR)0x0,
                 (LPBYTE)&DAT_00429fe0,(HKEY)0x0);
    if (DAT_00429fe0 == '\0') {
      FUN_004058f3((HKEY)0x80000003,".DEFAULT\\Control Panel\\International","Locale",
                   (LPBYTE)&DAT_00429fe0,(HKEY)0x0);
    }
    lstrcatA(&DAT_00435000,&DAT_00429fe0);
  }
  else {
    uVar4 = (*pcVar3)();
    FUN_0040596a(&DAT_00435000,uVar4 & 0xffff);
  }
  FUN_0040381e();
  DAT_0042ebe0 = DAT_0042eb78 & 0x20;
  _DAT_0042ebfc = 0x10000;
  bVar1 = FUN_004055e0(&DAT_00434400);
  if ((CONCAT31(extraout_var,bVar1) == 0) && (*(int *)(iVar8 + 0x48) != 0)) {
    pCVar12 = &DAT_0042db00;
    FUN_004058f3(*(HKEY *)(iVar8 + 0x44),(LPCSTR)(*(int *)(iVar8 + 0x48) + DAT_0042eb98),
                 (LPCSTR)(*(int *)(iVar8 + 0x4c) + DAT_0042eb98),(LPBYTE)&DAT_0042db00,(HKEY)0x0);
    if (DAT_0042db00 != '\0') {
      if (DAT_0042db00 == '\"') {
        pCVar12 = &DAT_0042db01;
        puVar5 = (undefined1 *)FUN_0040552a(&DAT_0042db01,'\"');
        *puVar5 = 0;
      }
      iVar6 = lstrlenA(pCVar12);
      if (((pCVar12 < pCVar12 + iVar6 + -4) &&
          (iVar6 = lstrcmpiA(pCVar12 + iVar6 + -4,&DAT_004091bc), iVar6 == 0)) &&
         ((DVar7 = GetFileAttributesA(pCVar12), DVar7 == 0xffffffff || ((DVar7 & 0x10) == 0)))) {
        FUN_00405546(pCVar12);
      }
      pCVar12 = FUN_004054ff(pCVar12);
      FUN_00405a0c(&DAT_00434400,pCVar12);
    }
  }
  bVar1 = FUN_004055e0(&DAT_00434400);
  if (CONCAT31(extraout_var_00,bVar1) == 0) {
    FUN_00405a2e(&DAT_00434400,*(int *)(iVar8 + 0x118));
  }
  DAT_0042e348 = LoadImageA(DAT_0042eb60,(LPCSTR)0x67,1,0,0,0x8040);
  if (*(int *)(iVar8 + 0x50) == -1) {
LAB_00403745:
    iVar8 = FUN_0040140b(0);
    if (iVar8 == 0) {
      FUN_0040381e();
      if (DAT_0042ec00 == 0) {
        ShowWindow(DAT_00429fb8,5);
        pHVar9 = LoadLibraryA("RichEd20");
        if (pHVar9 == (HMODULE)0x0) {
          LoadLibraryA("RichEd32");
        }
        BVar10 = GetClassInfoA((HINSTANCE)0x0,"RichEdit20A",(LPWNDCLASSA)&DAT_0042e300);
        if (BVar10 == 0) {
          GetClassInfoA((HINSTANCE)0x0,"RichEdit",(LPWNDCLASSA)&DAT_0042e300);
          _DAT_0042e324 = "RichEdit20A";
          RegisterClassA((WNDCLASSA *)&DAT_0042e300);
        }
        IVar11 = DialogBoxParamA(DAT_0042eb60,(LPCSTR)(DAT_0042e340 + 0x69U & 0xffff),(HWND)0x0,
                                 (DLGPROC)&LAB_004038eb,0);
        FUN_0040140b(5);
        FUN_004034a5(1);
        return IVar11;
      }
      iVar8 = FUN_00404e7c((HWND)0x0);
      if (iVar8 == 0) {
        FUN_0040140b(1);
        goto LAB_00403814;
      }
      if (DAT_0042e32c == 0) {
        FUN_0040140b(2);
      }
    }
    IVar11 = 2;
  }
  else {
    _DAT_0042e324 = acStack_14;
    builtin_strncpy(acStack_14,"_Nb",4);
    _DAT_0042e304 = FUN_00401000;
    _DAT_0042e310 = DAT_0042eb60;
    _DAT_0042e314 = DAT_0042e348;
    AVar2 = RegisterClassA((WNDCLASSA *)&DAT_0042e300);
    if (AVar2 != 0) {
      SystemParametersInfoA(0x30,0,&iStack_10,0);
      DAT_00429fb8 = CreateWindowExA(0x80,acStack_14,(LPCSTR)0x0,0x80000000,iStack_10,iStack_c,
                                     iStack_8 - iStack_10,iStack_4 - iStack_c,(HWND)0x0,(HMENU)0x0,
                                     DAT_0042eb60,(LPVOID)0x0);
      goto LAB_00403745;
    }
LAB_00403814:
    IVar11 = 0;
  }
  return IVar11;
}



/* VA 0040381e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040381e(void)

{
  int iVar1;
  LPCSTR lpString;
  ushort *puVar2;
  ushort uVar3;
  int iVar4;
  int *piVar5;

  uVar3 = 0xffff;
  iVar1 = FUN_00405983(&DAT_00435000);
  do {
    if (DAT_0042eba4 != 0) {
      puVar2 = (ushort *)(*(int *)(DAT_0042eb70 + 100) * DAT_0042eba4 + _DAT_0042eba0);
      iVar4 = DAT_0042eba4;
      do {
        puVar2 = (ushort *)((int)puVar2 - *(int *)(DAT_0042eb70 + 100));
        iVar4 = iVar4 + -1;
        if (((*puVar2 ^ (ushort)iVar1) & uVar3) == 0) {
          DAT_0042e340 = *(undefined4 *)(puVar2 + 1);
          DAT_0042ec08 = *(undefined4 *)(puVar2 + 3);
          DAT_0042e33c = puVar2 + 5;
          if (DAT_0042e33c != (ushort *)0x0) {
            FUN_0040596a(&DAT_00435000,(uint)*puVar2);
            lpString = (LPCSTR)FUN_00405a2e(&DAT_0042e360,-2);
            SetWindowTextA(DAT_00429fb8,lpString);
            piVar5 = DAT_0042eb88;
            for (iVar1 = DAT_0042eb8c; iVar1 != 0; iVar1 = iVar1 + -1) {
              if (*piVar5 != 0) {
                FUN_00405a2e((byte *)(piVar5 + 6),*piVar5);
              }
              piVar5 = piVar5 + 0x106;
            }
            return;
          }
          break;
        }
      } while (iVar4 != 0);
    }
    if (uVar3 == 0xffff) {
      uVar3 = 0x3ff;
    }
    else {
      uVar3 = 0;
    }
  } while( true );
}



/* VA 00403d97 */

void FUN_00403d97(WPARAM param_1)

{
  if (param_1 == 0x78) {
    DAT_0042e32c = DAT_0042e32c + 1;
  }
  SendMessageA(DAT_0042eb68,0x408,param_1,0);
  return;
}



/* VA 00403dbe */

void FUN_00403dbe(HWND param_1,int param_2,int param_3)

{
  LPCSTR lpString;

  lpString = (LPCSTR)FUN_00405a2e((byte *)0x0,param_3);
  SetDlgItemTextA(param_1,param_2 + 1000,lpString);
  return;
}



/* VA 00403de0 */

void FUN_00403de0(BOOL param_1)

{
  EnableWindow(DAT_00429fd8,param_1);
  return;
}



/* VA 00403df3 */

void FUN_00403df3(WPARAM param_1)

{
  SendMessageA(DAT_0042eb68,0x28,param_1,1);
  return;
}



/* VA 00403e0a */

void FUN_00403e0a(UINT param_1)

{
  if (DAT_0042e338 != (HWND)0x0) {
    SendMessageA(DAT_0042e338,param_1,0,0);
  }
  return;
}



/* VA 00403e25 */

COLORREF FUN_00403e25(int param_1,HDC param_2,HWND param_3)

{
  COLORREF *pCVar1;
  COLORREF color;
  HBRUSH pHVar2;
  LOGBRUSH local_10;

  if ((param_1 - 0x133U < 6) &&
     (pCVar1 = (COLORREF *)GetWindowLongA(param_3,-0x15), pCVar1 != (COLORREF *)0x0)) {
    color = *pCVar1;
    if ((pCVar1[5] & 2) != 0) {
      color = GetSysColor(color);
    }
    if ((pCVar1[5] & 1) != 0) {
      SetTextColor(param_2,color);
    }
    SetBkMode(param_2,pCVar1[4]);
    local_10.lbColor = pCVar1[1];
    if ((pCVar1[5] & 8) != 0) {
      local_10.lbColor = GetSysColor(local_10.lbColor);
    }
    if ((pCVar1[5] & 4) != 0) {
      SetBkColor(param_2,local_10.lbColor);
    }
    if ((pCVar1[5] & 0x10) != 0) {
      local_10.lbStyle = pCVar1[2];
      if ((HGDIOBJ)pCVar1[3] != (HGDIOBJ)0x0) {
        DeleteObject((HGDIOBJ)pCVar1[3]);
      }
      pHVar2 = CreateBrushIndirect(&local_10);
      pCVar1[3] = (COLORREF)pHVar2;
    }
    return pCVar1[3];
  }
  return 0;
}



/* VA 00403ed2 */

undefined4 FUN_00403ed2(int param_1,LPSTR param_2,int param_3,int *param_4)

{
  int iVar1;

  lstrcpynA(param_2,(LPCSTR)(DAT_00428fa4 + param_1),param_3);
  iVar1 = lstrlenA(param_2);
  *param_4 = iVar1;
  DAT_00428fa4 = DAT_00428fa4 + iVar1;
  return 0;
}



/* VA 00403f06 */

COLORREF FUN_00403f06(HWND param_1,int param_2,HDC param_3,HWND param_4)

{
  uint *puVar1;
  char cVar2;
  HWND pHVar3;
  DWORD lParam;
  int iVar4;
  HCURSOR pHVar5;
  COLORREF CVar6;
  uint uVar7;
  LPCSTR lpString;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam_00;
  LPCSTR local_10;
  int local_c;
  code *local_8;

  if (param_2 == 0x110) {
    iVar4 = param_4[0xc].unused;
    if (iVar4 < 0) {
      iVar4 = *(int *)(DAT_0042e33c - (iVar4 * 4 + 4));
    }
    cVar2 = *(char *)(iVar4 + DAT_0042eb98);
    local_c = 0;
    lpString = (char *)(iVar4 + DAT_0042eb98) + 1;
    local_8 = FUN_00403ed2;
    uVar7 = (uint)~param_4[5].unused >> 5 & 1 | param_4[5].unused & 1U;
    local_10 = lpString;
    FUN_00403dbe(param_1,0x22,param_4[0xd].unused);
    FUN_00403dbe(param_1,0x23,param_4[0xe].unused);
    CheckDlgButton(param_1,(uVar7 == 0) + 0x40a,1);
    FUN_00403de0(uVar7);
    pHVar3 = GetDlgItem(param_1,1000);
    FUN_00403df3((WPARAM)pHVar3);
    SendMessageA(pHVar3,0x45b,1,0);
    lParam = *(DWORD *)(DAT_0042eb70 + 0x68);
    if ((int)lParam < 0) {
      lParam = GetSysColor(-lParam);
    }
    SendMessageA(pHVar3,0x443,0,lParam);
    SendMessageA(pHVar3,0x445,0,0x4010000);
    DAT_00428fa4 = 0;
    iVar4 = lstrlenA(lpString);
    SendMessageA(pHVar3,0x435,0,iVar4);
    SendMessageA(pHVar3,0x449,(int)cVar2,(LPARAM)&local_10);
    DAT_00429fc0 = 0;
    return 0;
  }
  if (param_2 == 0x111) {
    if ((((short)((uint)param_3 >> 0x10) != 0) || (DAT_00429fc0 != 0)) ||
       (puVar1 = (uint *)(DAT_004297b0 + 0x14), (*(byte *)puVar1 & 0x20) == 0)) goto LAB_0040417e;
    lParam_00 = 0;
    wParam = 0;
    Msg = 0xf0;
    pHVar3 = GetDlgItem(param_1,0x40a);
    uVar7 = SendMessageA(pHVar3,Msg,wParam,lParam_00);
    *puVar1 = *puVar1 & 0xfffffffe | uVar7 & 1;
    FUN_00403de0(uVar7 & 1);
    FUN_00404191();
  }
  if (param_2 == 0x4e) {
    pHVar3 = GetDlgItem(param_1,1000);
    if ((param_4[2].unused == 0x70b) && (param_4[3].unused == 0x201)) {
      local_c = param_4[7].unused;
      local_10 = (LPCSTR)param_4[6].unused;
      local_8 = (code *)&DAT_0042db00;
      if ((uint)(local_c - (int)local_10) < 0x800) {
        SendMessageA(pHVar3,1099,0,(LPARAM)&local_10);
        pHVar5 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
        SetCursor(pHVar5);
        ShellExecuteA(param_1,&DAT_004091c4,(LPCSTR)local_8,(LPCSTR)0x0,(LPCSTR)0x0,1);
        pHVar5 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
        SetCursor(pHVar5);
      }
    }
    if ((param_4[2].unused == 0x700) && (param_4[3].unused == 0x100)) {
      if (param_4[4].unused == 0xd) {
        SendMessageA(DAT_0042eb68,0x111,1,0);
      }
      if (param_4[4].unused == 0x1b) {
        SendMessageA(DAT_0042eb68,0x10,0,0);
      }
      return 1;
    }
  }
  else if (param_2 == 0x40b) {
    DAT_00429fc0 = DAT_00429fc0 + 1;
  }
LAB_0040417e:
  CVar6 = FUN_00403e25(param_2,param_3,param_4);
  return CVar6;
}



/* VA 00404191 */

void FUN_00404191(void)

{
  HWND hWnd;

  hWnd = DAT_00428fa0;
  if (DAT_0042ebec == 0) {
    hWnd = DAT_00429fd8;
  }
  SendMessageA(hWnd,0xf4,1,1);
  return;
}



/* VA 004041b5 */

void FUN_004041b5(HWND param_1,int param_2,HDC param_3,HWND param_4)

{
  if (param_2 == 0x110) {
    FUN_00403dbe(param_1,0x1d,param_4[0xc].unused);
    SetDlgItemTextA(param_1,1000,&DAT_0042f000 + param_4[0xf].unused * 0x400);
  }
  FUN_00403e25(param_2,param_3,param_4);
  return;
}



/* VA 004041fc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004041fc(HWND param_1,uint param_2,HDC param_3,HWND param_4)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  LPITEMIDLIST pv;
  undefined3 extraout_var;
  BOOL BVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  LPCSTR pCVar9;
  byte *lpString;
  LPCITEMIDLIST *ppIVar10;
  _browseinfoA local_4c;
  uint local_2c;
  DWORD local_28;
  int local_24;
  undefined1 local_20 [4];
  DWORD local_1c;
  undefined1 local_18 [4];
  DWORD local_14;
  code *local_10;
  HWND local_c;
  int local_8;

  local_24 = DAT_004297b0;
  local_8 = *(int *)(DAT_004297b0 + 0x38);
  lpString = &DAT_0042f000 + *(int *)(DAT_004297b0 + 0x3c) * 0x400;
  if (param_2 == 0x40b) {
    FUN_004052b1(0x3fb,(LPSTR)lpString);
    FUN_00405c6e(lpString);
  }
  if (param_2 == 0x110) {
    local_c = GetDlgItem(param_1,0x3fb);
    iVar2 = FUN_0040556c(lpString);
    if ((iVar2 != 0) && (pcVar3 = FUN_00405593((short *)lpString), pcVar3 == (char *)0x0)) {
      FUN_004054ff((LPCSTR)lpString);
    }
    DAT_0042e338 = param_1;
    SetWindowTextA(local_c,(LPCSTR)lpString);
    FUN_00403dbe(param_1,1,param_4[0xd].unused);
    FUN_00403dbe(param_1,0x14,param_4[0xc].unused);
    FUN_00403df3((WPARAM)local_c);
    pcVar4 = (code *)FUN_00405d2e(7);
    if (pcVar4 == (code *)0x0) goto LAB_0040451c;
    (*pcVar4)(local_c,1);
  }
  iVar2 = local_8;
  if (param_2 == 0x111) {
    if (((uint)param_3 & 0xffff) == 0x3fb) {
      if ((short)((uint)param_3 >> 0x10) != 0x300) goto LAB_0040451c;
      param_2 = 0x40f;
    }
    if (((uint)param_3 & 0xffff) == 0x3e9) {
      ppIVar10 = &local_4c.pidlRoot;
      for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {
        *ppIVar10 = (LPCITEMIDLIST)0x0;
        ppIVar10 = ppIVar10 + 1;
      }
      local_4c.hwndOwner = param_1;
      local_4c.pszDisplayName = &DAT_00429fe0;
      local_4c.lpfn = FUN_00404531;
      local_4c.lParam = (LPARAM)lpString;
      local_4c.lpszTitle = (LPCSTR)FUN_00405a2e(&DAT_004293b0,iVar2);
      local_4c.ulFlags = 0x41;
      pv = SHBrowseForFolderA(&local_4c);
      if (pv == (LPITEMIDLIST)0x0) {
        param_2 = 0x40f;
      }
      else {
        CoTaskMemFree(pv);
        FUN_004054ff((LPCSTR)lpString);
        if ((*(int *)(DAT_0042eb70 + 0x11c) != 0) && (lpString == &DAT_00434400)) {
          FUN_00405a2e((byte *)0x0,*(int *)(DAT_0042eb70 + 0x11c));
          iVar2 = lstrcmpiA(&DAT_0042db00,&DAT_00429fe0);
          if (iVar2 != 0) {
            lstrcatA(&DAT_00434400,&DAT_0042db00);
          }
        }
        DAT_00429fcc = DAT_00429fcc + 1;
        SetDlgItemTextA(param_1,0x3fb,(LPCSTR)lpString);
      }
    }
  }
  if ((param_2 == 0x40f) || (param_2 == 0x405)) {
    local_8 = 0;
    local_c = (HWND)0x0;
    FUN_004052b1(0x3fb,(LPSTR)lpString);
    bVar1 = FUN_004055e0((LPCSTR)lpString);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      local_8 = 1;
    }
    FUN_00405a0c(&DAT_00428fa8,(LPCSTR)lpString);
    pCVar9 = (LPCSTR)0x0;
    local_10 = (code *)FUN_00405d2e(0);
    if (local_10 != (code *)0x0) {
      do {
        iVar2 = (*local_10)(&DAT_00428fa8,&local_2c,local_18,local_20);
        if (iVar2 != 0) {
          local_c = (HWND)0x1;
          uVar6 = local_2c >> 10 | local_28 << 0x16;
          goto LAB_00404488;
        }
        if (pCVar9 != (LPCSTR)0x0) {
          pCVar9[0] = '\0';
          pCVar9[1] = '\0';
        }
        pCVar9 = FUN_00405546(&DAT_00428fa8);
        pCVar9 = pCVar9 + -1;
        pCVar9[0] = '\\';
        pCVar9[1] = '\0';
      } while (pCVar9 != &DAT_00428fa8);
    }
    FUN_00405a0c(&DAT_00428fa8,(LPCSTR)lpString);
    pcVar3 = FUN_00405593((short *)&DAT_00428fa8);
    if (pcVar3 != (char *)0x0) {
      *pcVar3 = '\0';
    }
    BVar5 = GetDiskFreeSpaceA(&DAT_00428fa8,&local_14,&local_1c,(LPDWORD)&local_10,&local_28);
    uVar6 = param_2;
    if (BVar5 != 0) {
      uVar6 = MulDiv(local_14 * local_1c,(int)local_10,0x400);
      local_c = (HWND)0x1;
    }
LAB_00404488:
    uVar7 = FUN_0040464c(5);
    if ((local_c != (HWND)0x0) && (uVar6 < uVar7)) {
      local_8 = 2;
    }
    if (*(int *)(DAT_0042e33c + 0x10) != 0) {
      FUN_00404597(0x3ff,-5,uVar7);
      if (local_c == (HWND)0x0) {
        SetDlgItemTextA(param_1,0x400,&DAT_00428f98);
      }
      else {
        FUN_00404597(0x400,-4,uVar6);
      }
    }
    _DAT_0042ec04 = local_8;
    if (local_8 == 0) {
      local_8 = FUN_0040140b(7);
    }
    if ((*(uint *)(local_24 + 0x14) & 0x400) != 0) {
      local_8 = 0;
    }
    FUN_00403de0((uint)(local_8 == 0));
    if ((local_8 == 0) && (DAT_00429fcc == 0)) {
      FUN_00404191();
    }
    DAT_00429fcc = 0;
  }
LAB_0040451c:
  FUN_00403e25(param_2,param_3,param_4);
  return;
}



/* VA 00404531 */

undefined4 FUN_00404531(HWND param_1,int param_2,LPCITEMIDLIST param_3,LPSTR param_4)

{
  BOOL BVar1;
  int iVar2;
  LPARAM lParam;

  if (param_2 == 1) {
    FUN_004052b1(0x3fb,param_4);
    SendMessageA(param_1,0x466,1,(LPARAM)param_4);
  }
  if (param_2 == 2) {
    BVar1 = SHGetPathFromIDListA(param_3,param_4);
    if ((BVar1 == 0) || (iVar2 = FUN_0040140b(7), iVar2 != 0)) {
      lParam = 0;
    }
    else {
      lParam = 1;
    }
    SendMessageA(param_1,0x465,0,lParam);
    return 0;
  }
  return 0;
}



/* VA 00404597 */

void FUN_00404597(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  sbyte sVar7;
  char *pcVar8;
  byte local_44 [32];
  byte local_24 [32];

  sVar7 = 0x14;
  iVar3 = -0x24;
  if (param_3 < 0x100000) {
    sVar7 = 10;
    iVar3 = -0x23;
  }
  if (param_3 < 0x400) {
    sVar7 = 0;
    iVar3 = -0x22;
  }
  if (param_3 < 0xffff3333) {
    param_3 = param_3 + (1 << sVar7) / 0x14;
  }
  uVar1 = FUN_00405a2e(local_24,-0x21);
  uVar2 = FUN_00405a2e(local_44,iVar3);
  uVar5 = ((param_3 & 0xffffff) * 10 >> sVar7) % 10;
  uVar6 = param_3 >> sVar7;
  pcVar8 = s__u__u_s_s_004091cc;
  iVar3 = FUN_00405a2e(&DAT_00429fe0,param_2);
  iVar4 = lstrlenA(&DAT_00429fe0);
  wsprintfA((LPSTR)(iVar3 + iVar4),pcVar8,uVar6,uVar5,uVar2,uVar1);
  SetDlgItemTextA(DAT_0042e338,param_1,&DAT_00429fe0);
  return;
}



/* VA 0040464c */

int FUN_0040464c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar1 = 0;
  iVar2 = DAT_0042eb88;
  for (iVar3 = DAT_0042eb8c; iVar3 != 0; iVar3 = iVar3 + -1) {
    if ((*(byte *)(iVar2 + 8) & 1) != 0) {
      iVar1 = iVar1 + *(int *)(iVar2 + param_1 * 4);
    }
    iVar2 = iVar2 + 0x418;
  }
  return iVar1;
}



/* VA 00404679 */

undefined4 FUN_00404679(HWND param_1,int param_2)

{
  DWORD DVar1;
  undefined4 local_3c;
  LRESULT local_38;
  undefined4 local_18;
  tagPOINT local_14;
  byte local_c;
  LRESULT local_8;

  local_38 = SendMessageA(param_1,0x110a,9,0);
  if (param_2 != 0) {
    DVar1 = GetMessagePos();
    local_14.x = (LONG)(short)DVar1;
    local_14.y = (LONG)(short)(DVar1 >> 0x10);
    ScreenToClient(param_1,&local_14);
    SendMessageA(param_1,0x1111,0,(LPARAM)&local_14);
    local_38 = local_8;
    if ((local_c & 0x66) == 0) {
      return 0xffffffff;
    }
  }
  local_3c = 4;
  SendMessageA(param_1,0x110c,0,(LPARAM)&local_3c);
  return local_18;
}



/* VA 004046f9 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004046f9(HWND param_1,int param_2,HDC param_3,HWND param_4)

{
  HBITMAP pHVar1;
  int iVar2;
  uint uVar3;
  HGLOBAL pvVar4;
  LRESULT LVar5;
  LPARAM lParam;
  WPARAM WVar6;
  LRESULT LVar7;
  uint uVar8;
  HWND pHVar9;
  int iVar10;
  uint *puVar11;
  LPARAM local_54 [5];
  uint local_40;
  HBITMAP local_3c;
  uint *local_38;
  undefined4 local_2c;
  int local_28;
  HGLOBAL local_20;
  int local_1c;
  HBITMAP local_18;
  int local_14;
  HWND local_10;
  HWND local_c;
  HWND local_8;

  local_c = GetDlgItem(param_1,0x3f9);
  local_8 = GetDlgItem(param_1,0x408);
  local_14 = DAT_0042eb70 + 0x94;
  local_20 = DAT_0042eb88;
  if (param_2 == 0x110) {
    _DAT_0042ebc0 = param_1;
    local_1c = 0;
    local_10 = (HWND)0x2;
    DAT_00429fd4 = GlobalAlloc(0x40,DAT_0042eb8c << 2);
    local_18 = LoadBitmapA(DAT_0042eb60,(LPCSTR)0x6e);
    DAT_00429fc8 = 0xffffffff;
    DAT_00429fd0 = SetWindowLongA(local_8,-4,0x404cfa);
    DAT_00429fbc = ImageList_Create(0x10,0x10,0x21,6,0);
    ImageList_AddMasked(DAT_00429fbc,local_18,0xff00ff);
    SendMessageA(local_8,0x1109,2,(LPARAM)DAT_00429fbc);
    LVar5 = SendMessageA(local_8,0x111c,0,0);
    if (LVar5 < 0x10) {
      SendMessageA(local_8,0x111b,0x10,0);
    }
    DeleteObject(local_18);
    iVar10 = 0;
    do {
      iVar2 = *(int *)(local_14 + iVar10 * 4);
      if (iVar2 != 0) {
        if (iVar10 != 0x20) {
          local_10 = (HWND)0x0;
        }
        lParam = FUN_00405a2e((byte *)0x0,iVar2);
        WVar6 = SendMessageA(local_c,0x143,0,lParam);
        SendMessageA(local_c,0x151,WVar6,iVar10);
      }
      pHVar9 = local_10;
      iVar10 = iVar10 + 1;
    } while (iVar10 < 0x21);
    FUN_00403dbe(param_1,0x15,param_4[(int)(local_10 + 3)].unused);
    FUN_00403dbe(param_1,0x16,param_4[(int)((int)&pHVar9[3].unused + 1)].unused);
    iVar10 = 0;
    LVar5 = 0;
    if (DAT_0042eb8c < 1) {
LAB_0040492b:
      uVar8 = GetWindowLongA(local_8,-0x10);
      SetWindowLongA(local_8,-0x10,uVar8 & 0xfffffffb);
    }
    else {
      local_18 = (HBITMAP)((int)local_20 + 8);
      do {
        pHVar1 = local_18 + 4;
        if ((char)pHVar1->unused != '\0') {
          uVar8 = local_18->unused;
          local_54[4] = uVar8 & 0x20;
          local_54[1] = 0xffff0002;
          local_54[2] = 0xd;
          local_40 = 0x20;
          local_54[0] = LVar5;
          local_3c = pHVar1;
          local_28 = iVar10;
          if ((uVar8 & 2) == 0) {
            if ((uVar8 & 4) == 0) {
              LVar7 = SendMessageA(local_8,0x1100,0,(LPARAM)local_54);
              *(LRESULT *)((int)DAT_00429fd4 + iVar10 * 4) = LVar7;
            }
            else {
              LVar5 = SendMessageA(local_8,0x110a,3,LVar5);
            }
          }
          else {
            local_54[2] = 0x4d;
            local_2c = 1;
            LVar5 = SendMessageA(local_8,0x1100,0,(LPARAM)local_54);
            local_1c = 1;
            *(LRESULT *)((int)DAT_00429fd4 + iVar10 * 4) = LVar5;
            LVar5 = *(LRESULT *)((int)DAT_00429fd4 + iVar10 * 4);
          }
        }
        iVar10 = iVar10 + 1;
        local_18 = local_18 + 0x106;
      } while (iVar10 < DAT_0042eb8c);
      if (local_1c == 0) goto LAB_0040492b;
    }
    if (local_10 == (HWND)0x0) {
      ShowWindow(local_c,5);
      FUN_00403df3((WPARAM)local_c);
      goto LAB_00404ce5;
    }
    FUN_00403df3((WPARAM)local_8);
  }
  pvVar4 = local_20;
  if (param_2 == 0x405) {
    param_3 = (HDC)0x0;
    param_2 = 0x40f;
    param_4 = (HWND)0x1;
  }
  if (((param_2 == 0x4e) || (param_2 == 0x413)) &&
     ((local_10 = param_4, param_2 == 0x413 || (param_4[1].unused == 0x408)))) {
    if (((DAT_0042eb78 & 0x200) == 0) &&
       (((param_2 == 0x413 || (param_4[2].unused == -2)) &&
        (iVar10 = FUN_00404679(local_8,(uint)(param_2 != 0x413)), -1 < iVar10)))) {
      puVar11 = (uint *)(iVar10 * 0x418 + 8 + (int)pvVar4);
      uVar8 = *puVar11;
      if ((uVar8 & 0x10) == 0) {
        if ((uVar8 & 0x40) == 0) {
          uVar8 = uVar8 ^ 1;
        }
        else {
          uVar8 = uVar8 ^ 0x80;
          if ((char)uVar8 < '\0') {
            uVar8 = uVar8 | 1;
          }
          else {
            uVar8 = uVar8 & 0xfffffffe;
          }
        }
        *puVar11 = uVar8;
        FUN_0040117d(iVar10);
        param_2 = 0x40f;
        param_4 = (HWND)(~DAT_0042eb78 >> 8 & 1);
        param_3 = (HDC)0x1;
      }
    }
    if (local_10 != (HWND)0x0) {
      if (local_10[2].unused == -0x192) {
        SendMessageA(local_8,0x419,0,local_10[0x17].unused);
      }
      if (local_10[2].unused == -0x196) {
        if (local_10[3].unused == 2) {
          puVar11 = (uint *)(local_10[0x17].unused * 0x418 + 8 + (int)pvVar4);
          *puVar11 = *puVar11 | 0x20;
        }
        else {
          puVar11 = (uint *)(local_10[0x17].unused * 0x418 + 8 + (int)pvVar4);
          *puVar11 = *puVar11 & 0xffffffdf;
        }
      }
    }
  }
  if (param_2 == 0x111) {
    if ((((short)param_3 != 0x3f9) || ((short)((uint)param_3 >> 0x10) != 1)) ||
       (WVar6 = SendMessageA(local_c,0x147,0,0), WVar6 == 0xffffffff)) goto LAB_00404ce5;
    uVar8 = SendMessageA(local_c,0x150,WVar6,0);
    if ((uVar8 == 0xffffffff) || (*(int *)(local_14 + uVar8 * 4) == 0)) {
      uVar8 = 0x20;
    }
    FUN_00401299(uVar8);
    SendMessageA(param_1,0x420,0,uVar8);
    param_3 = (HDC)0x1;
    param_4 = (HWND)0x0;
    param_2 = 0x40f;
  }
  if (param_2 == 0x200) {
    SendMessageA(local_8,0x200,0,0);
  }
  if (param_2 == 0x40b) {
    if (DAT_00429fbc != (HIMAGELIST)0x0) {
      ImageList_Destroy(DAT_00429fbc);
    }
    if (DAT_00429fd4 != (HGLOBAL)0x0) {
      GlobalFree(DAT_00429fd4);
    }
    DAT_00429fbc = (HIMAGELIST)0x0;
    DAT_00429fd4 = (HGLOBAL)0x0;
    _DAT_0042ebc0 = (HWND)0x0;
  }
  if (param_2 == 0x40f) {
    FUN_004011ef(0,0);
    if (param_3 != (HDC)0x0) {
      FUN_0040140b(8);
    }
    if (param_4 != (HWND)0x0) {
      param_4 = (HWND)FUN_004012e2((int)DAT_00429fd4);
      FUN_00401299((uint)param_4);
      iVar10 = 0;
      WVar6 = 0;
      if (0 < (int)param_4) {
        do {
          if (*(int *)(local_14 + iVar10 * 4) != 0) {
            WVar6 = WVar6 + 1;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < (int)param_4);
      }
      SendMessageA(local_c,0x14e,WVar6,0);
      param_2 = 0x420;
    }
    FUN_004011ef(0,0);
    local_20 = DAT_00429fd4;
    local_3c = (HBITMAP)0xf030;
    local_10 = (HWND)0x0;
    if (0 < DAT_0042eb8c) {
      puVar11 = (uint *)((int)DAT_0042eb88 + 8);
      do {
        uVar8 = *(uint *)((int)local_20 + (int)local_10 * 4);
        if (uVar8 != 0) {
          uVar3 = *puVar11;
          local_54[3] = 8;
          if ((uVar3 & 0x100) != 0) {
            local_38 = puVar11 + 4;
            local_54[3] = 9;
            *(byte *)((int)puVar11 + 1) = *(byte *)((int)puVar11 + 1) & 0xfe;
          }
          if ((uVar3 & 0x40) == 0) {
            iVar10 = (uVar3 & 1) + 1;
            if ((uVar3 & 0x10) != 0) {
              iVar10 = (uVar3 & 1) + 4;
            }
          }
          else {
            iVar10 = 3;
          }
          local_40 = (iVar10 << 0xb | uVar3 & 8) * 2 | uVar3 & 0x20;
          local_54[4] = uVar8;
          SendMessageA(local_8,0x1102,((int)uVar3 >> 5 & 1U) + 1,uVar8);
          SendMessageA(local_8,0x110d,0,(LPARAM)(local_54 + 3));
        }
        local_10 = (HWND)((int)&local_10->unused + 1);
        puVar11 = puVar11 + 0x106;
      } while ((int)local_10 < DAT_0042eb8c);
    }
    InvalidateRect(local_8,(RECT *)0x0,1);
    if (*(int *)(DAT_0042e33c + 0x10) != 0) {
      uVar8 = FUN_0040464c(5);
      FUN_00404597(0x3ff,-5,uVar8);
    }
  }
  if ((param_2 == 0x420) && ((DAT_0042eb78 & 0x100) != 0)) {
    iVar10 = (uint)(param_4 == (HWND)0x20) << 3;
    ShowWindow(local_8,iVar10);
    pHVar9 = GetDlgItem(param_1,0x3fe);
    ShowWindow(pHVar9,iVar10);
  }
LAB_00404ce5:
  FUN_00403e25(param_2,param_3,param_4);
  return;
}



/* VA 00404cfa */

LRESULT FUN_00404cfa(HWND param_1,UINT param_2,WPARAM param_3,int param_4)

{
  BOOL BVar1;
  LRESULT LVar2;

  if (param_2 == 0x102) {
    if (param_3 == 0x20) {
      FUN_00403e0a(0x413);
      return 0;
    }
  }
  else {
    if (param_2 == 0x200) {
      BVar1 = IsWindowVisible(param_1);
      if (BVar1 == 0) goto LAB_00404d8e;
      param_4 = FUN_00404679(param_1,1);
      param_2 = 0x419;
    }
    if ((param_2 == 0x419) && (DAT_00429fc8 != param_4)) {
      DAT_00429fc8 = param_4;
      FUN_00405a0c(&DAT_00429fe0,&DAT_0042f000);
      FUN_0040596a(&DAT_0042f000,param_4);
      FUN_0040140b(6);
      FUN_00405a0c(&DAT_0042f000,&DAT_00429fe0);
    }
  }
LAB_00404d8e:
  LVar2 = CallWindowProcA(DAT_00429fd0,param_1,param_2,param_3,param_4);
  return LVar2;
}



/* VA 00404daa */

void FUN_00404daa(int param_1,LPCSTR param_2)

{
  int iVar1;
  int iVar2;
  LRESULT LVar3;
  uint uVar4;
  undefined4 local_34;
  WPARAM local_30;
  undefined4 local_2c;
  undefined *local_20;
  uint local_c;
  HWND local_8;

  local_8 = DAT_0042e344;
  if (DAT_0042e344 != (HWND)0x0) {
    local_c = DAT_0042ec14;
    uVar4 = DAT_0042ec14 & 1;
    if (uVar4 == 0) {
      FUN_00405a2e(&DAT_004297b8,param_1);
    }
    iVar1 = lstrlenA(&DAT_004297b8);
    if (param_2 != (LPCSTR)0x0) {
      iVar2 = lstrlenA(param_2);
      if (0x7ff < (uint)(iVar2 + iVar1)) {
        return;
      }
      lstrcatA(&DAT_004297b8,param_2);
    }
    if ((local_c & 4) == 0) {
      SetWindowTextA(DAT_0042e328,&DAT_004297b8);
    }
    if ((local_c & 2) == 0) {
      local_20 = &DAT_004297b8;
      local_34 = 1;
      LVar3 = SendMessageA(local_8,0x1004,0,0);
      local_30 = LVar3 - uVar4;
      local_2c = 0;
      SendMessageA(local_8,0x1007 - uVar4,0,(LPARAM)&local_34);
      SendMessageA(local_8,0x1013,local_30,0);
    }
    if (uVar4 != 0) {
      (&DAT_004297b8)[iVar1] = 0;
    }
  }
  return;
}



/* VA 00404e7c */

int FUN_00404e7c(HWND param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;

  iVar4 = DAT_0042eb8c;
  iVar2 = DAT_0042eb88;
  uVar1 = OleInitialize((LPVOID)0x0);
  DAT_0042ec18 = DAT_0042ec18 | uVar1;
  FUN_00403e0a(0);
  if (iVar4 != 0) {
    piVar3 = (int *)(iVar2 + 0xc);
    do {
      iVar4 = iVar4 + -1;
      if (((*(byte *)(piVar3 + -1) & 1) != 0) && (iVar2 = FUN_00401389(*piVar3,param_1), iVar2 != 0)
         ) {
        DAT_0042ebec = DAT_0042ebec + 1;
        break;
      }
      piVar3 = piVar3 + 0x106;
    } while (iVar4 != 0);
  }
  FUN_00403e0a(0x404);
  OleUninitialize();
  return DAT_0042ebec;
}



/* VA 00404ee8 */

COLORREF FUN_00404ee8(HWND param_1,int param_2,HDC param_3,HWND param_4)

{
  int lParam;
  int lParam_00;
  HWND pHVar1;
  HWND pHVar2;
  HANDLE hObject;
  HMENU hMenu;
  LPCSTR lpNewItem;
  BOOL BVar3;
  LRESULT LVar4;
  HGLOBAL hMem;
  undefined2 *puVar5;
  COLORREF CVar6;
  WPARAM wParam;
  SIZE_T dwBytes;
  DWORD dwCreationFlags;
  DWORD *lpThreadId;
  undefined1 local_44 [8];
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  undefined2 *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  tagRECT local_1c;
  DWORD local_c;
  HWND local_8;

  pHVar1 = DAT_0042e344;
  wParam = 0;
  local_8 = DAT_0042e344;
  if (param_2 == 0x110) {
    local_34 = 0xffffffff;
    local_28 = 0xffffffff;
    local_3c = 2;
    local_38 = 0;
    local_30 = (undefined2 *)0x0;
    local_2c = 0;
    local_24 = 0;
    uStack_20 = 0;
    lParam = *(int *)(DAT_0042eb70 + 0x5c);
    lParam_00 = *(int *)(DAT_0042eb70 + 0x60);
    DAT_0042e330 = GetDlgItem(param_1,0x403);
    DAT_0042e328 = GetDlgItem(param_1,0x3ee);
    DAT_0042e344 = GetDlgItem(param_1,0x3f8);
    local_8 = DAT_0042e344;
    FUN_00403df3((WPARAM)DAT_0042e330);
    DAT_0042e334 = FUN_0040464c(4);
    DAT_0042e34c = 0;
    GetClientRect(local_8,&local_1c);
    local_34 = GetSystemMetrics(0x15);
    local_34 = local_1c.right - local_34;
    SendMessageA(local_8,0x101b,0,(LPARAM)&local_3c);
    SendMessageA(local_8,0x1036,0x4000,0x4000);
    if (-1 < lParam) {
      SendMessageA(local_8,0x1001,0,lParam);
      SendMessageA(local_8,0x1026,0,lParam);
    }
    if (-1 < lParam_00) {
      SendMessageA(local_8,0x1024,0,lParam_00);
    }
    FUN_00403dbe(param_1,0x1b,param_4[0xc].unused);
    if (((byte)DAT_0042eb78 & 3) != 0) {
      ShowWindow(DAT_0042e330,0);
      if (((byte)DAT_0042eb78 & 2) == 0) {
        ShowWindow(local_8,8);
      }
      else {
        DAT_0042e330 = (HWND)0x0;
      }
      FUN_00403df3((WPARAM)DAT_0042e328);
    }
    pHVar1 = GetDlgItem(param_1,0x3ec);
    SendMessageA(pHVar1,0x401,0,0x75300000);
    if (((byte)DAT_0042eb78 & 4) != 0) {
      SendMessageA(pHVar1,0x409,0,lParam_00);
      SendMessageA(pHVar1,0x2001,0,lParam);
    }
LAB_00405265:
    CVar6 = 0;
  }
  else {
    if (param_2 == 0x405) {
      lpThreadId = &local_c;
      dwCreationFlags = 0;
      pHVar2 = GetDlgItem(param_1,0x3ec);
      hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00404e7c,pHVar2,dwCreationFlags,
                             lpThreadId);
      CloseHandle(hObject);
    }
    if (param_2 == 0x111) {
      if ((short)param_3 == 0x403) {
        ShowWindow(DAT_0042e330,0);
        ShowWindow(pHVar1,8);
        FUN_00403df3((WPARAM)pHVar1);
        goto LAB_004050f0;
      }
    }
    else {
LAB_004050f0:
      if (param_2 == 0x404) {
        if (DAT_0042e32c != 0) {
          DAT_004293a8 = 2;
          FUN_00403d97(0x78);
          goto LAB_00405112;
        }
        ShowWindow(DAT_0042eb68,8);
        if (DAT_0042ebec == 0) {
          FUN_00404daa(*(int *)(DAT_004297b0 + 0x34),(LPCSTR)0x0);
        }
        FUN_00403d97(1);
      }
      if ((param_2 == 0x7b) && (param_3 == (HDC)pHVar1)) {
        pHVar2 = (HWND)SendMessageA(pHVar1,0x1004,0,0);
        if (0 < (int)pHVar2) {
          hMenu = CreatePopupMenu();
          lpNewItem = (LPCSTR)FUN_00405a2e((byte *)0x0,-0x1f);
          AppendMenuA(hMenu,0,1,lpNewItem);
          if (param_4 == (HWND)0xffffffff) {
            GetWindowRect(pHVar1,&local_1c);
          }
          else {
            local_1c.left = (LONG)(short)param_4;
            local_1c.top = (LONG)(short)((uint)param_4 >> 0x10);
          }
          BVar3 = TrackPopupMenu(hMenu,0x180,local_1c.left,local_1c.top,0,param_1,(RECT *)0x0);
          dwBytes = 1;
          if (BVar3 == 1) {
            local_3c = 0;
            local_30 = (undefined2 *)&DAT_00429fe0;
            local_2c = 0xfff;
            param_1 = pHVar2;
            do {
              param_1 = (HWND)((int)&param_1[-1].unused + 3);
              LVar4 = SendMessageA(local_8,0x102d,(WPARAM)param_1,(LPARAM)local_44);
              dwBytes = dwBytes + 2 + LVar4;
            } while (param_1 != (HWND)0x0);
            OpenClipboard((HWND)0x0);
            EmptyClipboard();
            hMem = GlobalAlloc(0x42,dwBytes);
            puVar5 = GlobalLock(hMem);
            do {
              local_30 = puVar5;
              LVar4 = SendMessageA(local_8,0x102d,wParam,(LPARAM)local_44);
              *(undefined2 *)((int)puVar5 + LVar4) = 0xa0d;
              puVar5 = (undefined2 *)((int)puVar5 + LVar4) + 1;
              wParam = wParam + 1;
            } while ((int)wParam < (int)pHVar2);
            GlobalUnlock(hMem);
            SetClipboardData(1,hMem);
            CloseClipboard();
          }
        }
        goto LAB_00405265;
      }
    }
LAB_00405112:
    CVar6 = FUN_00403e25(param_2,param_3,param_4);
  }
  return CVar6;
}



/* VA 0040526c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HANDLE FUN_0040526c(LPSTR param_1)

{
  BOOL BVar1;
  HANDLE pvVar2;
  _PROCESS_INFORMATION local_14;

  _DAT_0042bfe8 = 0x44;
  BVar1 = CreateProcessA((LPCSTR)0x0,param_1,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0
                         ,0,(LPVOID)0x0,(LPCSTR)0x0,(LPSTARTUPINFOA)&DAT_0042bfe8,&local_14);
  pvVar2 = (HANDLE)0x0;
  if (BVar1 != 0) {
    CloseHandle(local_14.hThread);
    pvVar2 = local_14.hProcess;
  }
  return pvVar2;
}



/* VA 004052ab */

BOOL SetDlgItemTextA(HWND hDlg,int nIDDlgItem,LPCSTR lpString)

{
  BOOL BVar1;

                    /* WARNING: Could not recover jumptable at 0x004052ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = SetDlgItemTextA(hDlg,nIDDlgItem,lpString);
  return BVar1;
}



/* VA 004052b1 */

void FUN_004052b1(int param_1,LPSTR param_2)

{
  GetDlgItemTextA(DAT_0042e338,param_1,param_2,0x400);
  return;
}



/* VA 004052cd */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004052cd(undefined4 param_1,uint param_2)

{
  uint uVar1;

  uVar1 = param_2 & 0x1fffff;
  if ((DAT_0042ec00 == 0) || (param_2 >> 0x15 == 0)) {
    if (DAT_0042ec08 != 0) {
      uVar1 = uVar1 ^ 0x180000;
    }
    _DAT_004091dc = DAT_0042eb68;
    _DAT_004091e0 = DAT_0042eb60;
    _DAT_004091e4 = param_1;
    _DAT_004091e8 = &DAT_0042e360;
    _DAT_004091ec = uVar1;
    MessageBoxIndirectA((MSGBOXPARAMSA *)&DAT_004091d8);
  }
  return;
}



/* VA 00405331 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00405331(LPCSTR param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  BOOL BVar2;
  int iVar3;
  HANDLE hFindFile;
  char *pcVar4;
  undefined *puVar5;
  uint uVar6;
  CHAR *pCVar7;
  _WIN32_FIND_DATAA local_14c;
  int local_c;
  uint local_8;

  bVar1 = FUN_004055e0(param_1);
  local_c = CONCAT31(extraout_var,bVar1);
  if ((param_2 & 8) == 0) {
    uVar6 = param_2 & 1;
    local_8 = uVar6;
    if ((uVar6 == 0) || ((local_c != 0 && ((param_2 & 2) != 0)))) {
      FUN_00405a0c(&DAT_0042afe8,param_1);
      if (uVar6 == 0) {
        FUN_00405546(param_1);
      }
      else {
        lstrcatA(&DAT_0042afe8,&DAT_00409328);
      }
      if ((*param_1 != '\0') || (DAT_0042afe8 == '\\')) {
        lstrcatA(param_1,&DAT_00409010);
      }
      iVar3 = lstrlenA(param_1);
      hFindFile = FindFirstFileA(&DAT_0042afe8,&local_14c);
      if (hFindFile != (HANDLE)0xffffffff) {
        do {
          pCVar7 = local_14c.cFileName;
          pcVar4 = (char *)FUN_0040552a(local_14c.cFileName,'?');
          if ((*pcVar4 != '\0') && (local_14c.cAlternateFileName[0] != '\0')) {
            pCVar7 = local_14c.cAlternateFileName;
          }
          if ((*pCVar7 != '.') ||
             ((pCVar7[1] != '\0' && ((pCVar7[1] != '.' || (pCVar7[2] != '\0')))))) {
            FUN_00405a0c(param_1 + iVar3,pCVar7);
            if (((byte)local_14c.dwFileAttributes & 0x10) == 0) {
              FUN_004056c4(param_1);
              BVar2 = DeleteFileA(param_1);
              if (BVar2 == 0) {
                if ((param_2 & 4) == 0) {
                  _DAT_0042ebe8 = _DAT_0042ebe8 + 1;
                }
                else {
                  FUN_00404daa(-0xf,param_1);
                  FUN_0040575a(param_1,(LPCSTR)0x0);
                }
              }
              else {
                FUN_00404daa(-0xe,param_1);
              }
            }
            else if (((byte)param_2 & 3) == 3) {
              FUN_00405331(param_1,param_2);
            }
          }
          BVar2 = FindNextFileA(hFindFile,&local_14c);
        } while (BVar2 != 0);
        FindClose(hFindFile);
      }
      if (local_8 != 0) {
        (param_1 + iVar3)[-1] = '\0';
      }
    }
    if (local_8 != 0) {
      if (local_c != 0) {
        puVar5 = FUN_00405d07(param_1);
        if (puVar5 == (undefined *)0x0) {
          return;
        }
        FUN_004054ff(param_1);
        FUN_004056c4(param_1);
        BVar2 = RemoveDirectoryA(param_1);
        if (BVar2 != 0) {
          FUN_00404daa(-0x1b,param_1);
          return;
        }
        if ((param_2 & 4) != 0) {
          FUN_00404daa(-0xf,param_1);
          FUN_0040575a(param_1,(LPCSTR)0x0);
          return;
        }
      }
      _DAT_0042ebe8 = _DAT_0042ebe8 + 1;
    }
  }
  else {
    BVar2 = DeleteFileA(param_1);
    _DAT_0042ebe8 = _DAT_0042ebe8 + (uint)(BVar2 == 0);
  }
  return;
}



/* VA 004054ff */

LPCSTR FUN_004054ff(LPCSTR param_1)

{
  int iVar1;
  LPSTR pCVar2;

  iVar1 = lstrlenA(param_1);
  pCVar2 = CharPrevA(param_1,param_1 + iVar1);
  if (*pCVar2 != '\\') {
    lstrcatA(param_1,&DAT_00409010);
  }
  return param_1;
}



/* VA 0040552a */

void FUN_0040552a(LPCSTR param_1,char param_2)

{
  for (; (*param_1 != '\0' && (*param_1 != param_2)); param_1 = CharNextA(param_1)) {
  }
  return;
}



/* VA 00405546 */

LPCSTR FUN_00405546(LPCSTR param_1)

{
  int iVar1;
  LPCSTR lpszCurrent;

  iVar1 = lstrlenA(param_1);
  lpszCurrent = param_1 + iVar1;
  do {
    if (*lpszCurrent == '\\') break;
    lpszCurrent = CharPrevA(param_1,lpszCurrent);
  } while (param_1 < lpszCurrent);
  *lpszCurrent = '\0';
  return lpszCurrent + 1;
}



/* VA 0040556c */

undefined4 FUN_0040556c(byte *param_1)

{
  undefined4 uVar1;

  if ((*(short *)param_1 == 0x5c5c) ||
     ((('`' < (char)(*param_1 | 0x20) && ((char)(*param_1 | 0x20) < '{')) && (param_1[1] == 0x3a))))
  {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* VA 00405593 */

char * FUN_00405593(short *param_1)

{
  short *lpsz;
  char *pcVar1;
  int iVar2;

  lpsz = (short *)CharNextA((LPCSTR)param_1);
  pcVar1 = CharNextA((LPCSTR)lpsz);
  if (((char)*param_1 == '\0') || (*lpsz != 0x5c3a)) {
    if (*param_1 == 0x5c5c) {
      iVar2 = 2;
      do {
        iVar2 = iVar2 + -1;
        pcVar1 = (char *)FUN_0040552a(pcVar1,'\\');
        if (*pcVar1 == '\0') goto LAB_004055d8;
        pcVar1 = pcVar1 + 1;
      } while (iVar2 != 0);
    }
    else {
LAB_004055d8:
      pcVar1 = (char *)0x0;
    }
  }
  else {
    pcVar1 = CharNextA(pcVar1);
  }
  return pcVar1;
}



/* VA 004055e0 */

bool FUN_004055e0(LPCSTR param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  DWORD DVar4;

  FUN_00405a0c(&DAT_0042b3e8,param_1);
  pbVar1 = (byte *)FUN_00405593((short *)&DAT_0042b3e8);
  if ((pbVar1 != (byte *)0x0) &&
     ((FUN_00405c6e(pbVar1), ((byte)DAT_0042eb78 & 0x80) == 0 ||
      ((*pbVar1 != 0 && (*pbVar1 != 0x5c)))))) {
    while( true ) {
      iVar3 = lstrlenA(&DAT_0042b3e8);
      if (iVar3 <= (int)(pbVar1 + -0x42b3e8)) {
        FUN_004054ff(&DAT_0042b3e8);
        DVar4 = GetFileAttributesA(&DAT_0042b3e8);
        return DVar4 != 0xffffffff;
      }
      pbVar2 = FUN_00405d07(&DAT_0042b3e8);
      if ((pbVar2 != (byte *)0x0) && ((*pbVar2 & 0x10) == 0)) break;
      FUN_00405546(&DAT_0042b3e8);
    }
  }
  return false;
}



/* VA 00405658 */

LPCSTR FUN_00405658(LPSTR param_1,LPCSTR param_2)

{
  CHAR CVar1;
  int iVar2;
  int iVar3;

  iVar2 = lstrlenA(param_2);
  while( true ) {
    iVar3 = lstrlenA(param_1);
    if (iVar3 < iVar2) {
      return (LPCSTR)0x0;
    }
    CVar1 = param_1[iVar2];
    param_1[iVar2] = '\0';
    iVar3 = lstrcmpiA(param_1,param_2);
    param_1[iVar2] = CVar1;
    if (iVar3 == 0) break;
    param_1 = CharNextA(param_1);
  }
  return param_1;
}



/* VA 004056a4 */

void FUN_004056a4(undefined1 *param_1,int param_2,int param_3)

{
  int iVar1;

  if (0 < param_3) {
    iVar1 = param_2 - (int)param_1;
    do {
      *param_1 = param_1[iVar1];
      param_1 = param_1 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}



/* VA 004056c4 */

void FUN_004056c4(LPCSTR param_1)

{
  DWORD DVar1;

  DVar1 = GetFileAttributesA(param_1);
  if (DVar1 != 0xffffffff) {
    SetFileAttributesA(param_1,DVar1 & 0xfffffffe);
  }
  return;
}



/* VA 004056e3 */

void FUN_004056e3(LPCSTR param_1,DWORD param_2,DWORD param_3)

{
  DWORD DVar1;

  DVar1 = GetFileAttributesA(param_1);
  CreateFileA(param_1,param_2,1,(LPSECURITY_ATTRIBUTES)0x0,param_3,
              -(uint)(DVar1 != 0xffffffff) & DVar1,(HANDLE)0x0);
  return;
}



/* VA 00405712 */

LPSTR FUN_00405712(LPSTR param_1,LPCSTR param_2)

{
  char cVar1;
  LPSTR lpTempFileName;
  DWORD DVar2;
  UINT UVar3;
  int iVar4;

  lpTempFileName = param_1;
  iVar4 = 100;
  do {
    iVar4 = iVar4 + -1;
    param_1 = (LPSTR)0x61736e;
    DVar2 = GetTickCount();
    cVar1 = param_1._2_1_ + (char)(DVar2 % 0x1a);
    param_1._0_3_ = CONCAT12(cVar1,param_1._0_2_);
    UVar3 = GetTempFileNameA(param_2,(LPCSTR)&param_1,0,lpTempFileName);
    if (UVar3 != 0) {
      return lpTempFileName;
    }
  } while (iVar4 != 0);
  *lpTempFileName = '\0';
  return (LPSTR)0x0;
}



/* VA 0040575a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040575a(LPCSTR param_1,LPCSTR param_2)

{
  code *pcVar1;
  int iVar2;
  HANDLE pvVar3;
  DWORD DVar4;
  LPSTR nNumberOfBytesToRead;
  LPSTR lpBuffer;
  BOOL BVar5;
  LPCSTR pCVar6;
  LPSTR pCVar7;

  pcVar1 = (code *)FUN_00405d2e(1);
  pCVar6 = param_2;
  if ((pcVar1 == (code *)0x0) || (iVar2 = (*pcVar1)(param_1,param_2,5), iVar2 == 0)) {
    _DAT_0042c170 = 0x4c554e;
    if (pCVar6 != (LPCSTR)0x0) {
      pvVar3 = (HANDLE)FUN_004056e3(pCVar6,0,1);
      CloseHandle(pvVar3);
      DVar4 = GetShortPathNameA(pCVar6,&DAT_0042c170,0x400);
      if (DVar4 == 0) {
        return;
      }
      if (0x400 < (int)DVar4) {
        return;
      }
    }
    DVar4 = GetShortPathNameA(param_1,&DAT_0042bbe8,0x400);
    if (DVar4 == 0) {
      return;
    }
    if (0x400 < (int)DVar4) {
      return;
    }
    iVar2 = wsprintfA(&DAT_0042b7e8,s__s__s_00409334,&DAT_0042c170,&DAT_0042bbe8);
    FUN_00405a2e(&DAT_0042bbe8,*(int *)(DAT_0042eb70 + 0x128));
    pvVar3 = (HANDLE)FUN_004056e3(&DAT_0042bbe8,0xc0000000,4);
    if (pvVar3 != (HANDLE)0xffffffff) {
      nNumberOfBytesToRead = (LPSTR)GetFileSize(pvVar3,(LPDWORD)0x0);
      lpBuffer = GlobalAlloc(0x40,(SIZE_T)(nNumberOfBytesToRead + iVar2 + 10));
      if (((lpBuffer != (LPSTR)0x0) &&
          (BVar5 = ReadFile(pvVar3,lpBuffer,(DWORD)nNumberOfBytesToRead,(LPDWORD)&param_2,
                            (LPOVERLAPPED)0x0), BVar5 != 0)) && (nNumberOfBytesToRead == param_2)) {
        pCVar6 = FUN_00405658(lpBuffer,"[Rename]\r\n");
        if (pCVar6 == (LPCSTR)0x0) {
          FUN_00405a0c(lpBuffer + (int)nNumberOfBytesToRead,"[Rename]\r\n");
          nNumberOfBytesToRead = nNumberOfBytesToRead + 10;
          pCVar7 = nNumberOfBytesToRead;
        }
        else {
          pCVar6 = FUN_00405658(pCVar6 + 10,&DAT_00409330);
          pCVar7 = nNumberOfBytesToRead;
          if (pCVar6 != (LPCSTR)0x0) {
            for (pCVar7 = pCVar6 + 1; pCVar7 < lpBuffer + (int)nNumberOfBytesToRead;
                pCVar7 = pCVar7 + 1) {
              pCVar7[iVar2] = *pCVar7;
            }
            pCVar7 = pCVar6 + 1 + -(int)lpBuffer;
          }
        }
        FUN_004056a4(pCVar7 + (int)lpBuffer,0x42b7e8,iVar2);
        SetFilePointer(pvVar3,0,(PLONG)0x0,0);
        WriteFile(pvVar3,lpBuffer,(DWORD)(nNumberOfBytesToRead + iVar2),(LPDWORD)&param_2,
                  (LPOVERLAPPED)0x0);
        GlobalFree(lpBuffer);
      }
      CloseHandle(pvVar3);
    }
  }
  _DAT_0042ebf0 = _DAT_0042ebf0 + 1;
  return;
}



/* VA 004058f3 */

void FUN_004058f3(HKEY param_1,LPCSTR param_2,LPCSTR param_3,LPBYTE param_4,HKEY param_5)

{
  LPBYTE lpData;
  LSTATUS LVar1;

  lpData = param_4;
  *param_4 = '\0';
  LVar1 = RegOpenKeyExA(param_1,param_2,0,-(uint)(param_5 != (HKEY)0x0) & 0x100 | 0x20019,&param_5);
  if (LVar1 == 0) {
    param_2 = (LPCSTR)0x400;
    LVar1 = RegQueryValueExA(param_5,param_3,(LPDWORD)0x0,(LPDWORD)&param_4,lpData,(LPDWORD)&param_2
                            );
    if ((LVar1 != 0) || ((param_4 != (LPBYTE)0x1 && (param_4 != (LPBYTE)0x2)))) {
      *lpData = '\0';
    }
    lpData[0x3ff] = '\0';
    RegCloseKey(param_5);
  }
  return;
}



/* VA 0040596a */

void FUN_0040596a(LPSTR param_1,undefined4 param_2)

{
  wsprintfA(param_1,"%d",param_2);
  return;
}



/* VA 00405983 */

int FUN_00405983(byte *param_1)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  int local_8;

  iVar7 = 0;
  local_8 = 1;
  cVar2 = '\n';
  cVar6 = '9';
  if (*param_1 == 0x2d) {
    param_1 = param_1 + 1;
    local_8 = -1;
  }
  pbVar3 = param_1;
  if (*param_1 == 0x30) {
    pbVar3 = param_1 + 1;
    bVar1 = *pbVar3;
    if (('/' < (char)bVar1) && ((char)bVar1 < '8')) {
      cVar2 = '\b';
      cVar6 = '7';
    }
    if ((bVar1 & 0xdf) == 0x58) {
      cVar2 = '\x10';
      pbVar3 = param_1 + 2;
    }
  }
  do {
    uVar4 = (uint)(char)*pbVar3;
    pbVar3 = pbVar3 + 1;
    if (((int)uVar4 < 0x30) || ((int)cVar6 < (int)uVar4)) {
      if ((cVar2 != '\x10') ||
         (((int)(uVar4 & 0xffffffdf) < 0x41 || (0x46 < (int)(uVar4 & 0xffffffdf))))) {
        return local_8 * iVar7;
      }
      iVar5 = (uVar4 & 7) + 9;
    }
    else {
      iVar5 = uVar4 - 0x30;
    }
    iVar7 = cVar2 * iVar7 + iVar5;
  } while( true );
}



/* VA 00405a0c */

void FUN_00405a0c(LPSTR param_1,LPCSTR param_2)

{
  lstrcpynA(param_1,param_2,0x400);
  return;
}



/* VA 00405a22 */

int lstrlenA(LPCSTR lpString)

{
  int iVar1;

                    /* WARNING: Could not recover jumptable at 0x00405a22. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = lstrlenA(lpString);
  return iVar1;
}



/* VA 00405a28 */

LPSTR lstrcatA(LPSTR lpString1,LPCSTR lpString2)

{
  LPSTR pCVar1;

                    /* WARNING: Could not recover jumptable at 0x00405a28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = lstrcatA(lpString1,lpString2);
  return pCVar1;
}



/* VA 00405a2e */

void FUN_00405a2e(byte *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  DWORD DVar4;
  int iVar5;
  HRESULT HVar6;
  BOOL BVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  byte *lpBuffer;
  uint local_1c [4];
  LPCITEMIDLIST local_c;
  int local_8;

  pbVar9 = param_1;
  if (param_2 < 0) {
    param_2 = *(int *)(DAT_0042e33c - (param_2 * 4 + 4));
  }
  pbVar11 = (byte *)(DAT_0042eb98 + param_2);
  lpBuffer = &DAT_0042db00;
  if (param_1 + -0x42db00 < (byte *)0x800) {
    param_1 = (byte *)0x0;
    lpBuffer = pbVar9;
  }
  do {
    while( true ) {
      bVar3 = *pbVar11;
      if ((bVar3 == 0) || (0x3ff < (int)(lpBuffer + -0x42db00))) {
        *lpBuffer = 0;
        if (param_1 != (byte *)0x0) {
          FUN_00405a0c((LPSTR)param_1,&DAT_0042db00);
        }
        return;
      }
      pbVar9 = pbVar11 + 1;
      if (0xfc < bVar3) break;
      if (bVar3 == 0xfc) {
        *lpBuffer = *pbVar9;
        lpBuffer = lpBuffer + 1;
        pbVar11 = pbVar11 + 2;
      }
      else {
        *lpBuffer = bVar3;
        lpBuffer = lpBuffer + 1;
        pbVar11 = pbVar9;
      }
    }
    bVar1 = pbVar11[2];
    local_1c[3] = (uint)(char)bVar1;
    bVar2 = *pbVar9;
    uVar10 = (uint)(char)bVar2;
    uVar12 = (local_1c[3] & 0x7f) << 7 | uVar10 & 0x7f;
    local_1c[0] = CONCAT22((char)bVar2 >> 7,(short)(char)bVar2) | 0x8000;
    local_1c[2] = CONCAT22((char)bVar1 >> 7,(short)(char)bVar1) | 0x8000;
    local_1c[1] = uVar10;
    if (bVar3 == 0xfe) {
      iVar8 = 2;
      DVar4 = GetVersion();
      if (((((int)DVar4 < 0) && ((short)DVar4 != 0x5a04)) && (local_1c[3] != 0x23)) &&
         (local_1c[3] != 0x2e)) {
        local_8 = 0;
      }
      else {
        local_8 = 1;
      }
      if (DAT_0042ebe4 != 0) {
        iVar8 = 4;
      }
      if ((char)bVar2 < '\0') {
        FUN_004058f3((HKEY)0x80000002,"Software\\Microsoft\\Windows\\CurrentVersion",
                     (LPCSTR)((uVar10 & 0x3f) + DAT_0042eb98),lpBuffer,(HKEY)(uVar10 & 0x40));
        if (*lpBuffer == 0) {
          FUN_00405a2e(lpBuffer,local_1c[3]);
          goto LAB_00405bca;
        }
LAB_00405bcf:
        if (local_1c[3] == 0x1a) {
          lstrcatA((LPSTR)lpBuffer,"\\Microsoft\\Internet Explorer\\Quick Launch");
        }
      }
      else {
        if (uVar10 == 0x25) {
          GetSystemDirectoryA((LPSTR)lpBuffer,0x400);
        }
        else {
          if (uVar10 == 0x24) {
            GetWindowsDirectoryA((LPSTR)lpBuffer,0x400);
            iVar8 = 0;
          }
          while ((iVar8 != 0 &&
                 (((iVar8 = iVar8 + -1, DAT_0042eb64 == (code *)0x0 || (local_8 == 0)) ||
                  (iVar5 = (*DAT_0042eb64)(DAT_0042eb68,local_1c[iVar8],0,0,lpBuffer), iVar5 != 0)))
                 )) {
            HVar6 = SHGetSpecialFolderLocation(DAT_0042eb68,local_1c[iVar8],&local_c);
            if (HVar6 == 0) {
              BVar7 = SHGetPathFromIDListA(local_c,(LPSTR)lpBuffer);
              CoTaskMemFree(local_c);
              if (BVar7 != 0) break;
            }
            *lpBuffer = 0;
          }
        }
LAB_00405bca:
        if (*lpBuffer != 0) goto LAB_00405bcf;
      }
LAB_00405be0:
      FUN_00405c6e(lpBuffer);
    }
    else if (bVar3 == 0xfd) {
      if (uVar12 == 0x1d) {
        FUN_0040596a((LPSTR)lpBuffer,DAT_0042eb68);
      }
      else {
        FUN_00405a0c((LPSTR)lpBuffer,&DAT_0042f000 + uVar12 * 0x400);
      }
      if (uVar12 - 0x15 < 7) goto LAB_00405be0;
    }
    else if (bVar3 == 0xff) {
      FUN_00405a2e(lpBuffer,-1 - uVar12);
    }
    iVar8 = lstrlenA((LPCSTR)lpBuffer);
    lpBuffer = lpBuffer + iVar8;
    pbVar11 = pbVar11 + 3;
  } while( true );
}



/* VA 00405c6e */

void FUN_00405c6e(byte *param_1)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  LPSTR pCVar4;
  byte *lpsz;
  byte *lpsz_00;

  if ((((*param_1 == 0x5c) && (param_1[1] == 0x5c)) && (param_1[2] == 0x3f)) && (param_1[3] == 0x5c)
     ) {
    param_1 = param_1 + 4;
  }
  if ((*param_1 != 0) && (iVar2 = FUN_0040556c(param_1), iVar2 != 0)) {
    param_1 = param_1 + 2;
  }
  bVar1 = *param_1;
  lpsz_00 = param_1;
  lpsz = param_1;
  while (bVar1 != 0) {
    if ((0x1f < bVar1) &&
       (pcVar3 = (char *)FUN_0040552a(s____<>____0040933c,bVar1), *pcVar3 == '\0')) {
      pCVar4 = CharNextA((LPCSTR)lpsz_00);
      FUN_004056a4(lpsz,(int)lpsz_00,(int)pCVar4 - (int)lpsz_00);
      lpsz = (byte *)CharNextA((LPCSTR)lpsz);
    }
    lpsz_00 = (byte *)CharNextA((LPCSTR)lpsz_00);
    bVar1 = *lpsz_00;
  }
  *lpsz = 0;
  while( true ) {
    lpsz = (byte *)CharPrevA((LPCSTR)param_1,(LPCSTR)lpsz);
    if ((*lpsz != 0x20) && (*lpsz != 0x5c)) break;
    *lpsz = 0;
    if (lpsz <= param_1) {
      return;
    }
  }
  return;
}



/* VA 00405d07 */

undefined * FUN_00405d07(LPCSTR param_1)

{
  HANDLE hFindFile;
  undefined *puVar1;

  hFindFile = FindFirstFileA(param_1,(LPWIN32_FIND_DATAA)&DAT_0042c030);
  if (hFindFile == (HANDLE)0xffffffff) {
    puVar1 = (undefined *)0x0;
  }
  else {
    FindClose(hFindFile);
    puVar1 = &DAT_0042c030;
  }
  return puVar1;
}



/* VA 00405d2e */

void FUN_00405d2e(int param_1)

{
  LPCSTR lpModuleName;
  HMODULE hModule;

  lpModuleName = (&PTR_s_KERNEL32_00409200)[param_1 * 2];
  hModule = GetModuleHandleA(lpModuleName);
  if ((hModule == (HMODULE)0x0) && (hModule = LoadLibraryA(lpModuleName), hModule == (HMODULE)0x0))
  {
    return;
  }
  GetProcAddress(hModule,(&PTR_s_GetDiskFreeSpaceExA_00409204)[param_1 * 2]);
  return;
}



/* VA 00405d67 */

void FUN_00405d67(UINT param_1)

{
  BOOL BVar1;
  MSG local_20;

  while( true ) {
    BVar1 = PeekMessageA(&local_20,(HWND)0x0,param_1,param_1,1);
    if (BVar1 == 0) break;
    DispatchMessageA(&local_20);
  }
  return;
}



/* VA 00405d9a */

uint FUN_00405d9a(uint param_1,byte *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;

  if (DAT_0042c574 == 0) {
    uVar2 = 0;
    do {
      iVar3 = 8;
      uVar1 = uVar2;
      do {
        uVar1 = uVar1 >> 1 ^ -(uint)((uVar1 & 1) != 0) & 0xedb88320;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      (&DAT_0042c570)[uVar2] = uVar1;
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < 0x100);
  }
  uVar2 = ~param_1;
  for (; param_3 != 0; param_3 = param_3 + -1) {
    uVar2 = uVar2 >> 8 ^ (&DAT_0042c570)[uVar2 & 0xff ^ (uint)*param_2];
    param_2 = param_2 + 1;
  }
  return ~uVar2;
}



/* VA 00405e08 */

undefined4 FUN_00405e08(int *param_1)

{
  int *piVar1;
  uint *puVar2;
  byte bVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  byte *pbVar7;
  char cVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  undefined1 *puVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint local_44;
  byte *local_3c;
  undefined1 *local_38;
  int *local_34;
  undefined1 *local_30;
  int *local_24;
  int local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int *local_c;
  uint local_8;

  local_3c = (byte *)*param_1;
  piVar1 = param_1 + 4;
  local_38 = (undefined1 *)param_1[1];
  local_34 = (int *)param_1[0x26ee];
  uVar10 = param_1[0x14a];
  local_44 = param_1[0x14b];
  if (local_34 < (int *)param_1[0x26ed]) {
    local_30 = (undefined1 *)(param_1[0x26ed] + (-1 - (int)local_34));
  }
  else {
    local_30 = (undefined1 *)(param_1[0x26ec] - (int)local_34);
  }
LAB_0040681c:
  do {
    switch(*piVar1) {
    case 0:
      goto switchD_00405e59_caseD_0;
    case 1:
      goto switchD_00405e59_caseD_1;
    case 2:
      uVar15 = param_1[6];
      for (; uVar10 < uVar15; uVar10 = uVar10 + 8) {
        if (local_38 == (undefined1 *)0x0) goto LAB_0040682c;
        local_38 = local_38 + -1;
        local_44 = local_44 | (uint)*local_3c << ((byte)uVar10 & 0x1f);
        local_3c = local_3c + 1;
      }
      param_1[5] = param_1[5] + (*(ushort *)(&DAT_00409348 + uVar15 * 2) & local_44);
      local_44 = local_44 >> ((byte)uVar15 & 0x1f);
      uVar10 = uVar10 - uVar15;
      param_1[7] = (uint)*(byte *)((int)param_1 + 0x21);
      param_1[6] = param_1[10];
      *piVar1 = 3;
    case 3:
      for (; uVar10 < (uint)param_1[7]; uVar10 = uVar10 + 8) {
        if (local_38 == (undefined1 *)0x0) goto LAB_0040682c;
        local_38 = local_38 + -1;
        local_44 = local_44 | (uint)*local_3c << ((byte)uVar10 & 0x1f);
        local_3c = local_3c + 1;
      }
      pbVar7 = (byte *)(param_1[6] + (*(ushort *)(&DAT_00409348 + param_1[7] * 2) & local_44) * 4);
      local_44 = local_44 >> (pbVar7[1] & 0x1f);
      uVar10 = uVar10 - pbVar7[1];
      bVar3 = *pbVar7;
      uVar15 = (uint)bVar3;
      if ((bVar3 & 0x10) == 0) {
        if ((bVar3 & 0x40) != 0) goto switchD_00405e59_caseD_e;
LAB_004065ba:
        param_1[7] = uVar15;
        param_1[6] = (int)(pbVar7 + (uint)*(ushort *)(pbVar7 + 2) * 4);
      }
      else {
        param_1[6] = uVar15 & 0xf;
        param_1[7] = (uint)*(ushort *)(pbVar7 + 2);
        *piVar1 = 4;
      }
      break;
    case 4:
      uVar15 = param_1[6];
      for (; uVar10 < uVar15; uVar10 = uVar10 + 8) {
        if (local_38 == (undefined1 *)0x0) goto LAB_0040682c;
        local_38 = local_38 + -1;
        local_44 = local_44 | (uint)*local_3c << ((byte)uVar10 & 0x1f);
        local_3c = local_3c + 1;
      }
      param_1[7] = param_1[7] + (*(ushort *)(&DAT_00409348 + uVar15 * 2) & local_44);
      local_44 = local_44 >> ((byte)uVar15 & 0x1f);
      uVar10 = uVar10 - uVar15;
      *piVar1 = 5;
    case 5:
      puVar9 = (undefined1 *)param_1[7];
      if ((undefined1 *)((int)local_34 + (-0x1ba0 - (int)piVar1)) < puVar9) {
        iVar6 = ((param_1[0x26ec] - (int)puVar9) - (int)piVar1) + -0x1ba0;
      }
      else {
        iVar6 = -(int)puVar9;
      }
      local_24 = (int *)(iVar6 + (int)local_34);
      iVar6 = param_1[5];
      piVar5 = local_34;
      while (local_34 = piVar5, iVar6 != 0) {
        if (local_30 == (undefined1 *)0x0) {
          if (piVar5 == (int *)param_1[0x26ec]) {
            piVar4 = (int *)param_1[0x26ed];
            local_34 = param_1 + 0x6ec;
            if (piVar4 != local_34) {
              if (local_34 < piVar4) {
                local_30 = (undefined1 *)((int)piVar4 + (-1 - (int)local_34));
              }
              else {
                local_30 = (undefined1 *)(param_1[0x26ec] - (int)local_34);
              }
              piVar5 = local_34;
              if (local_30 != (undefined1 *)0x0) goto LAB_004066e4;
            }
          }
          param_1[0x26ee] = (int)piVar5;
          FUN_00406897((int)param_1);
          local_34 = (int *)param_1[0x26ee];
          piVar5 = (int *)param_1[0x26ed];
          if (local_34 < piVar5) {
            local_30 = (undefined1 *)((int)piVar5 + (-1 - (int)local_34));
          }
          else {
            local_30 = (undefined1 *)(param_1[0x26ec] - (int)local_34);
          }
          local_c = (int *)param_1[0x26ec];
          if ((local_34 == local_c) && (piVar4 = param_1 + 0x6ec, piVar5 != piVar4)) {
            local_34 = piVar4;
            if (piVar4 < piVar5) {
              local_30 = (undefined1 *)((int)piVar5 + (-1 - (int)piVar4));
            }
            else {
              local_30 = (undefined1 *)((int)local_c - (int)piVar4);
            }
          }
          if (local_30 == (undefined1 *)0x0) goto LAB_00406848;
        }
LAB_004066e4:
        *(char *)local_34 = (char)*local_24;
        piVar5 = (int *)((int)local_34 + 1);
        local_24 = (int *)((int)local_24 + 1);
        local_30 = local_30 + -1;
        if (local_24 == (int *)param_1[0x26ec]) {
          local_24 = param_1 + 0x6ec;
        }
        piVar4 = param_1 + 5;
        *piVar4 = *piVar4 + -1;
        iVar6 = *piVar4;
      }
LAB_00405fd8:
      *piVar1 = 0;
      break;
    case 6:
      if (local_30 == (undefined1 *)0x0) {
        if (local_34 == (int *)param_1[0x26ec]) {
          piVar4 = (int *)param_1[0x26ed];
          piVar5 = param_1 + 0x6ec;
          if (piVar4 != piVar5) {
            if (piVar5 < piVar4) {
              local_30 = (undefined1 *)((int)piVar4 + (-1 - (int)piVar5));
            }
            else {
              local_30 = (undefined1 *)(param_1[0x26ec] - (int)piVar5);
            }
            local_34 = piVar5;
            if (local_30 != (undefined1 *)0x0) goto LAB_004067b5;
          }
        }
        param_1[0x26ee] = (int)local_34;
        FUN_00406897((int)param_1);
        local_34 = (int *)param_1[0x26ee];
        piVar5 = (int *)param_1[0x26ed];
        if (local_34 < piVar5) {
          local_30 = (undefined1 *)((int)piVar5 + (-1 - (int)local_34));
        }
        else {
          local_30 = (undefined1 *)(param_1[0x26ec] - (int)local_34);
        }
        local_c = (int *)param_1[0x26ec];
        if ((local_34 == local_c) && (piVar4 = param_1 + 0x6ec, piVar5 != piVar4)) {
          local_34 = piVar4;
          if (piVar4 < piVar5) {
            local_30 = (undefined1 *)((int)piVar5 + (-1 - (int)piVar4));
          }
          else {
            local_30 = (undefined1 *)((int)local_c - (int)piVar4);
          }
        }
        if (local_30 != (undefined1 *)0x0) goto LAB_004067b5;
        goto LAB_00406848;
      }
LAB_004067b5:
      *(char *)local_34 = (char)param_1[6];
      local_30 = local_30 + -1;
      local_34 = (int *)((int)local_34 + 1);
      goto LAB_00405fd8;
    case 7:
      if (7 < uVar10) {
        uVar10 = uVar10 - 8;
        local_38 = local_38 + 1;
        local_3c = local_3c + -1;
      }
    case 0xf:
      param_1[0x26ee] = (int)local_34;
      FUN_00406897((int)param_1);
      local_34 = (int *)param_1[0x26ee];
      piVar5 = (int *)param_1[0x26ed];
      if (local_34 < piVar5) {
        local_30 = (undefined1 *)((int)piVar5 + (-1 - (int)local_34));
      }
      else {
        local_30 = (undefined1 *)(param_1[0x26ec] - (int)local_34);
      }
      if (local_34 != piVar5) {
LAB_00406848:
        uVar11 = 0;
        goto LAB_00405ec8;
      }
      *piVar1 = param_1[0x149];
      if (param_1[0x149] != 8) {
        uVar11 = 1;
        goto LAB_00405ec8;
      }
      break;
    case 8:
      for (; uVar10 < 3; uVar10 = uVar10 + 8) {
        if (local_38 == (undefined1 *)0x0) goto LAB_0040682c;
        local_38 = local_38 + -1;
        local_44 = local_44 | (uint)*local_3c << ((byte)uVar10 & 0x1f);
        local_3c = local_3c + 1;
      }
      uVar10 = uVar10 - 3;
      uVar15 = local_44 >> 3;
      uVar16 = (local_44 & 7) >> 1;
      param_1[0x149] = (-(uint)((local_44 & 1) != 0) & 7) + 8;
      if (uVar16 == 0) {
        *piVar1 = 9;
        local_44 = uVar15 >> (sbyte)(uVar10 & 7);
        uVar10 = uVar10 - (uVar10 & 7);
      }
      else {
        local_44 = uVar15;
        if (uVar16 == 1) {
          if (DAT_0042daf8 == '\0') {
            local_c = (int *)0x0;
            piVar5 = &DAT_0042c978;
            do {
              cVar8 = '\b';
              if (0x42cbb4 < (int)piVar5) {
                if ((int)piVar5 < 0x42cd78) {
                  cVar8 = '\t';
                }
                else if ((int)piVar5 < 0x42cdd8) {
                  cVar8 = '\a';
                }
              }
              *piVar5 = (int)cVar8;
              piVar5 = piVar5 + 1;
            } while ((int)piVar5 < 0x42cdf8);
            FUN_004068ff(&DAT_0042c978,0x120,0x101,0x407388,0x4073c8,&DAT_0042c974,
                         (uint *)&DAT_0040936c,0x42d278,(uint *)&local_c);
            puVar12 = &DAT_0042c978;
            for (iVar6 = 0x1e; iVar6 != 0; iVar6 = iVar6 + -1) {
              *puVar12 = 5;
              puVar12 = puVar12 + 1;
            }
            FUN_004068ff(&DAT_0042c978,0x1e,0,0x407408,0x407444,&DAT_0042c970,(uint *)&DAT_00409370,
                         0x42d278,(uint *)&local_c);
            DAT_0042daf8 = DAT_0042daf8 + '\x01';
          }
          *(undefined1 *)(param_1 + 8) = DAT_0040936c;
          *(undefined1 *)((int)param_1 + 0x21) = DAT_00409370;
          param_1[9] = DAT_0042c974;
          param_1[10] = DAT_0042c970;
          goto LAB_00405fd8;
        }
        if (uVar16 != 2) goto code_r0x00405eb8;
        *piVar1 = 0xb;
      }
      break;
    case 9:
      for (; uVar10 < 0x10; uVar10 = uVar10 + 8) {
        if (local_38 == (undefined1 *)0x0) goto LAB_0040682c;
        local_38 = local_38 + -1;
        local_44 = local_44 | (uint)*local_3c << ((byte)uVar10 & 0x1f);
        local_3c = local_3c + 1;
      }
      uVar10 = 0;
      uVar15 = local_44 & 0xffff;
      local_44 = 0;
      param_1[5] = uVar15;
      if (uVar15 == 0) goto LAB_0040611b;
      iVar6 = 10;
      goto LAB_00406121;
    case 10:
      if (local_38 == (undefined1 *)0x0) {
LAB_0040682c:
        uVar11 = 0;
        param_1[0x14b] = local_44;
        param_1[0x14a] = uVar10;
        param_1[1] = 0;
        goto LAB_00405ee0;
      }
      if (local_30 == (undefined1 *)0x0) {
        if (local_34 == (int *)param_1[0x26ec]) {
          piVar4 = (int *)param_1[0x26ed];
          piVar5 = param_1 + 0x6ec;
          if (piVar4 != piVar5) {
            if (piVar5 < piVar4) {
              local_30 = (undefined1 *)((int)piVar4 + (-1 - (int)piVar5));
            }
            else {
              local_30 = (undefined1 *)(param_1[0x26ec] - (int)piVar5);
            }
            local_34 = piVar5;
            if (local_30 != (undefined1 *)0x0) goto LAB_004060e7;
          }
        }
        param_1[0x26ee] = (int)local_34;
        FUN_00406897((int)param_1);
        local_34 = (int *)param_1[0x26ee];
        piVar5 = (int *)param_1[0x26ed];
        if (local_34 < piVar5) {
          local_30 = (undefined1 *)((int)piVar5 + (-1 - (int)local_34));
        }
        else {
          local_30 = (undefined1 *)(param_1[0x26ec] - (int)local_34);
        }
        if (local_34 == (int *)param_1[0x26ec]) {
          piVar4 = param_1 + 0x6ec;
          if (piVar4 != piVar5) {
            local_34 = piVar4;
            if (piVar4 < piVar5) {
              local_30 = (undefined1 *)((int)piVar5 + (-1 - (int)piVar4));
            }
            else {
              local_30 = (undefined1 *)(param_1[0x26ec] - (int)piVar4);
            }
          }
        }
        if (local_30 == (undefined1 *)0x0) goto LAB_00406848;
      }
LAB_004060e7:
      puVar9 = local_30;
      if (local_38 <= local_30) {
        puVar9 = local_38;
      }
      puVar13 = (undefined1 *)param_1[5];
      if (puVar9 <= (undefined1 *)param_1[5]) {
        puVar13 = puVar9;
      }
      FUN_004056a4((undefined1 *)local_34,(int)local_3c,(int)puVar13);
      local_3c = local_3c + (int)puVar13;
      local_38 = local_38 + -(int)puVar13;
      local_34 = (int *)((int)local_34 + (int)puVar13);
      local_30 = local_30 + -(int)puVar13;
      piVar5 = param_1 + 5;
      *piVar5 = *piVar5 - (int)puVar13;
      if (*piVar5 == 0) {
LAB_0040611b:
        iVar6 = param_1[0x149];
LAB_00406121:
        *piVar1 = iVar6;
      }
      break;
    case 0xb:
      for (; uVar10 < 0xe; uVar10 = uVar10 + 8) {
        if (local_38 == (undefined1 *)0x0) goto LAB_0040682c;
        local_38 = local_38 + -1;
        local_44 = local_44 | (uint)*local_3c << ((byte)uVar10 & 0x1f);
        local_3c = local_3c + 1;
      }
      param_1[5] = local_44 & 0x3fff;
      if ((((byte)(local_44 & 0x3fff) & 0x1f) < 0x1e) && ((local_44 & 0x3e0) < 0x3a1)) {
        local_44 = local_44 >> 0xe;
        uVar10 = uVar10 - 0xe;
        param_1[6] = 0;
        *piVar1 = 0xc;
        goto switchD_00405e59_caseD_c;
      }
      goto switchD_00405e59_caseD_e;
    case 0xc:
switchD_00405e59_caseD_c:
      if ((uint)param_1[6] < ((uint)param_1[5] >> 10) + 4) {
        do {
          for (; uVar10 < 3; uVar10 = uVar10 + 8) {
            if (local_38 == (undefined1 *)0x0) goto LAB_0040682c;
            local_38 = local_38 + -1;
            local_44 = local_44 | (uint)*local_3c << ((byte)uVar10 & 0x1f);
            local_3c = local_3c + 1;
          }
          uVar15 = local_44 & 7;
          uVar10 = uVar10 - 3;
          local_44 = local_44 >> 3;
          param_1[(char)(&DAT_00407374)[param_1[6]] + 7] = uVar15;
          param_1[6] = param_1[6] + 1;
        } while ((uint)param_1[6] < ((uint)param_1[5] >> 10) + 4);
      }
      while ((uint)param_1[6] < 0x13) {
        param_1[(char)(&DAT_00407374)[param_1[6]] + 7] = 0;
        param_1[6] = param_1[6] + 1;
      }
      puVar2 = (uint *)(param_1 + 0x147);
      local_c = (int *)0x0;
      *puVar2 = 7;
      iVar6 = FUN_004068ff(param_1 + 7,0x13,0x13,0,0,param_1 + 0x148,puVar2,(int)(param_1 + 0x14c),
                           (uint *)&local_c);
      if ((iVar6 == 0) && (*puVar2 != 0)) {
        param_1[6] = 0;
        *piVar1 = 0xd;
switchD_00405e59_caseD_d:
        while ((uint)param_1[6] < ((uint)param_1[5] >> 5 & 0x1f) + 0x102 + (param_1[5] & 0x1fU)) {
          for (; uVar10 < (uint)param_1[0x147]; uVar10 = uVar10 + 8) {
            if (local_38 == (undefined1 *)0x0) goto LAB_0040682c;
            local_38 = local_38 + -1;
            local_44 = local_44 | (uint)*local_3c << ((byte)uVar10 & 0x1f);
            local_3c = local_3c + 1;
          }
          iVar6 = param_1[0x148] + (*(ushort *)(&DAT_00409348 + param_1[0x147] * 2) & local_44) * 4;
          bVar3 = *(byte *)(iVar6 + 1);
          uVar15 = (uint)bVar3;
          local_18 = (uint)*(ushort *)(iVar6 + 2);
          if (local_18 < 0x10) {
            uVar10 = uVar10 - uVar15;
            local_44 = local_44 >> (bVar3 & 0x1f);
            param_1[param_1[6] + 7] = local_18;
            param_1[6] = param_1[6] + 1;
          }
          else {
            if (local_18 == 0x12) {
              local_c = (int *)0xb;
              iVar6 = 7;
            }
            else {
              iVar6 = local_18 - 0xe;
              local_c = (int *)0x3;
            }
            for (; uVar10 < iVar6 + uVar15; uVar10 = uVar10 + 8) {
              if (local_38 == (undefined1 *)0x0) goto LAB_0040682c;
              local_38 = local_38 + -1;
              local_44 = local_44 | (uint)*local_3c << ((byte)uVar10 & 0x1f);
              local_3c = local_3c + 1;
            }
            local_44 = local_44 >> (bVar3 & 0x1f);
            uVar10 = (uVar10 - uVar15) - iVar6;
            puVar9 = (undefined1 *)
                     ((int)local_c + (*(ushort *)(&DAT_00409348 + iVar6 * 2) & local_44));
            local_44 = local_44 >> ((byte)iVar6 & 0x1f);
            iVar6 = param_1[6];
            if ((undefined1 *)(((uint)param_1[5] >> 5 & 0x1f) + 0x102 + (param_1[5] & 0x1fU)) <
                puVar9 + iVar6) goto switchD_00405e59_caseD_e;
            if (local_18 == 0x10) {
              if (iVar6 == 0) goto switchD_00405e59_caseD_e;
              iVar14 = param_1[iVar6 + 6];
            }
            else {
              iVar14 = 0;
            }
            piVar5 = param_1 + iVar6 + 7;
            do {
              *piVar5 = iVar14;
              iVar6 = iVar6 + 1;
              piVar5 = piVar5 + 1;
              puVar9 = puVar9 + -1;
            } while (puVar9 != (undefined1 *)0x0);
            param_1[6] = iVar6;
          }
        }
        param_1[0x148] = 0;
        local_10 = 0;
        uVar15 = param_1[5] & 0x1f;
        uVar16 = uVar15 + 0x101;
        local_18 = ((uint)param_1[5] >> 5 & 0x1f) + 1;
        local_8 = 9;
        local_14 = 6;
        iVar6 = FUN_004068ff(param_1 + 7,uVar16,0x101,0x407388,0x4073c8,&local_1c,&local_8,
                             (int)(param_1 + 0x14c),&local_10);
        if (local_8 == 0) {
          iVar6 = -1;
        }
        if (((iVar6 != 0) ||
            (iVar6 = FUN_004068ff(param_1 + uVar15 + 0x108,local_18,0,0x407408,0x407444,&local_20,
                                  &local_14,(int)(param_1 + 0x14c),&local_10), iVar6 != 0)) ||
           ((local_14 == 0 && (0x101 < uVar16)))) goto switchD_00405e59_caseD_e;
        *piVar1 = 0;
        *(char *)((int)param_1 + 0x21) = (char)local_14;
        param_1[9] = local_1c;
        *(undefined1 *)(param_1 + 8) = (undefined1)local_8;
        param_1[10] = local_20;
switchD_00405e59_caseD_0:
        param_1[7] = (uint)*(byte *)(param_1 + 8);
        param_1[6] = param_1[9];
        *piVar1 = 1;
switchD_00405e59_caseD_1:
        for (; uVar10 < (uint)param_1[7]; uVar10 = uVar10 + 8) {
          if (local_38 == (undefined1 *)0x0) goto LAB_0040682c;
          local_38 = local_38 + -1;
          local_44 = local_44 | (uint)*local_3c << ((byte)uVar10 & 0x1f);
          local_3c = local_3c + 1;
        }
        pbVar7 = (byte *)(param_1[6] + (*(ushort *)(&DAT_00409348 + param_1[7] * 2) & local_44) * 4)
        ;
        local_44 = local_44 >> (pbVar7[1] & 0x1f);
        uVar10 = uVar10 - pbVar7[1];
        bVar3 = *pbVar7;
        uVar15 = (uint)bVar3;
        if (uVar15 == 0) {
          param_1[6] = (uint)*(ushort *)(pbVar7 + 2);
          *piVar1 = 6;
        }
        else if ((bVar3 & 0x10) == 0) {
          if ((bVar3 & 0x40) == 0) goto LAB_004065ba;
          if ((bVar3 & 0x20) == 0) goto switchD_00405e59_caseD_e;
          *piVar1 = 7;
        }
        else {
          param_1[6] = uVar15 & 0xf;
          param_1[5] = (uint)*(ushort *)(pbVar7 + 2);
          *piVar1 = 2;
        }
      }
      else {
        *piVar1 = 0x11;
      }
      break;
    case 0xd:
      goto switchD_00405e59_caseD_d;
    default:
      goto switchD_00405e59_caseD_e;
    }
  } while( true );
code_r0x00405eb8:
  if (uVar16 == 3) {
switchD_00405e59_caseD_e:
    uVar11 = 0xffffffff;
    *piVar1 = 0x11;
LAB_00405ec8:
    param_1[0x14b] = local_44;
    param_1[0x14a] = uVar10;
    param_1[1] = (int)local_38;
LAB_00405ee0:
    *param_1 = (int)local_3c;
    param_1[0x26ee] = (int)local_34;
    FUN_00406897((int)param_1);
    return uVar11;
  }
  goto LAB_0040681c;
}



/* VA 00406897 */

void FUN_00406897(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;

  uVar4 = *(uint *)(param_1 + 0x9bb4);
  while( true ) {
    uVar2 = *(uint *)(param_1 + 0x9bb8);
    if (uVar2 < uVar4) {
      uVar2 = *(uint *)(param_1 + 0x9bb0);
    }
    uVar1 = *(uint *)(param_1 + 0xc);
    uVar3 = uVar2 - uVar4;
    if (uVar1 <= uVar2 - uVar4) {
      uVar3 = uVar1;
    }
    *(uint *)(param_1 + 0xc) = uVar1 - uVar3;
    FUN_004056a4(*(undefined1 **)(param_1 + 8),uVar4,uVar3);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar3;
    if (uVar4 + uVar3 != *(int *)(param_1 + 0x9bb0)) break;
    uVar4 = param_1 + 0x1bb0;
    if (*(int *)(param_1 + 0x9bb8) == *(int *)(param_1 + 0x9bb0)) {
      *(uint *)(param_1 + 0x9bb8) = uVar4;
    }
  }
  *(uint *)(param_1 + 0x9bb4) = uVar4 + uVar3;
  return;
}



/* VA 004068ff */

undefined4
FUN_004068ff(int *param_1,uint param_2,uint param_3,int param_4,int param_5,int *param_6,
            uint *param_7,int param_8,uint *param_9)

{
  undefined3 uVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  uint *puVar12;
  uint *puVar13;
  int iVar14;
  int local_f0 [15];
  uint local_b4 [16];
  uint local_74 [16];
  int local_34;
  uint local_30;
  int local_2c;
  uint local_28;
  uint *local_24;
  uint *local_20;
  uint *local_1c;
  int local_18;
  uint local_14;
  int local_10;
  uint local_c;
  uint *local_8;

  puVar13 = param_7;
  puVar8 = local_74;
  for (iVar4 = 0x10; piVar5 = param_1, uVar7 = param_2, iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  do {
    local_74[*piVar5] = local_74[*piVar5] + 1;
    uVar7 = uVar7 - 1;
    piVar5 = piVar5 + 1;
  } while (uVar7 != 0);
  if (local_74[0] == param_2) {
    *param_6 = 0;
    *param_7 = 0;
    uVar2 = 0;
  }
  else {
    puVar12 = (uint *)0x1;
    param_7 = (uint *)*param_7;
    puVar8 = (uint *)0xf;
    do {
      iVar4 = 0;
      if (local_74[(int)puVar12] != 0) break;
      puVar12 = (uint *)((int)puVar12 + 1);
    } while (puVar12 < (uint *)0x10);
    local_8 = puVar12;
    if (param_7 < puVar12) {
      param_7 = puVar12;
    }
    do {
      if (local_74[(int)puVar8] != 0) break;
      puVar8 = (uint *)((int)puVar8 - 1);
    } while (puVar8 != (uint *)0x0);
    local_1c = puVar8;
    if (puVar8 < param_7) {
      param_7 = puVar8;
    }
    *puVar13 = (uint)param_7;
    local_34 = 1 << ((byte)puVar12 & 0x1f);
    for (; puVar12 < puVar8; puVar12 = (uint *)((int)puVar12 + 1)) {
      if ((int)(local_34 - local_74[(int)puVar12]) < 0) goto LAB_00406c30;
      local_34 = (local_34 - local_74[(int)puVar12]) * 2;
    }
    uVar7 = local_74[(int)puVar8];
    local_34 = local_34 - uVar7;
    if (-1 < local_34) {
      local_b4[1] = 0;
      local_74[(int)puVar8] = uVar7 + local_34;
      iVar6 = 0;
      iVar9 = (int)puVar8 - 1;
      if (iVar9 != 0) {
        iVar14 = 0;
        do {
          iVar6 = iVar6 + *(int *)((int)local_74 + iVar14 + 4);
          iVar9 = iVar9 + -1;
          *(int *)((int)local_b4 + iVar14 + 8) = iVar6;
          iVar14 = iVar14 + 4;
        } while (iVar9 != 0);
      }
      uVar7 = 0;
      piVar5 = param_1;
      do {
        iVar6 = *piVar5;
        piVar5 = piVar5 + 1;
        if (iVar6 != 0) {
          uVar10 = local_b4[iVar6];
          *(uint *)(&DAT_0042cdf8 + uVar10 * 2) = uVar7;
          local_b4[iVar6] = uVar10 + 1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < param_2);
      uVar7 = local_b4[(int)puVar8];
      local_10 = -1;
      local_28 = 0;
      iVar6 = -(int)param_7;
      local_c = 0;
      local_b4[0] = 0;
      local_24 = (uint *)&DAT_0042cdf8;
      local_f0[0] = 0;
      if ((int)local_8 <= (int)local_1c) {
        local_2c = (int)local_8 - 1;
        local_20 = local_74 + (int)local_8;
        do {
          local_14 = *local_20;
          piVar5 = param_1;
          while (param_1 = piVar5, local_14 != 0) {
            param_1._2_2_ = (undefined2)((uint)piVar5 >> 0x10);
            local_30 = local_14 - 1;
            local_18 = (int)param_7 + iVar6;
            if ((int)param_7 + iVar6 < (int)local_8) {
              do {
                iVar14 = local_10;
                iVar9 = local_10 + 1;
                local_10 = iVar9;
                puVar13 = (uint *)((int)local_1c - local_18);
                if (param_7 < (uint *)((int)local_1c - local_18)) {
                  puVar13 = param_7;
                }
                puVar8 = (uint *)((int)local_8 - local_18);
                uVar10 = 1 << ((byte)puVar8 & 0x1f);
                if ((local_14 < uVar10) &&
                   (iVar4 = uVar10 + (-1 - local_30), puVar12 = local_20, puVar8 < puVar13)) {
                  while (puVar8 = (uint *)((int)puVar8 + 1), puVar8 < puVar13) {
                    uVar10 = puVar12[1];
                    if ((uint)(iVar4 * 2) <= uVar10) break;
                    iVar4 = iVar4 * 2 - uVar10;
                    puVar12 = puVar12 + 1;
                  }
                }
                local_28 = 1 << ((byte)puVar8 & 0x1f);
                uVar10 = *param_9 + local_28;
                if (0x5a0 < uVar10) goto LAB_00406c30;
                iVar4 = param_8 + *param_9 * 4;
                *param_9 = uVar10;
                local_f0[iVar9] = iVar4;
                uVar10 = local_c;
                if (iVar9 == 0) {
                  *param_6 = iVar4;
                }
                else {
                  iVar14 = local_f0[iVar14];
                  local_b4[iVar9] = local_c;
                  uVar10 = uVar10 >> ((byte)iVar6 & 0x1f);
                  param_1 = (int *)CONCAT22((short)(iVar4 - iVar14 >> 2) - (short)uVar10,
                                            (short)CONCAT31((int3)param_7,(byte)puVar8));
                  *(int **)(iVar14 + uVar10 * 4) = param_1;
                }
                iVar6 = local_18;
                local_18 = local_18 + (int)param_7;
              } while (local_18 < (int)local_8);
            }
            bVar11 = (byte)iVar6;
            uVar1 = CONCAT21(param_1._2_2_,(char)local_8 - bVar11);
            if (local_24 < &DAT_0042cdf8 + uVar7 * 2) {
              uVar10 = *local_24;
              if (uVar10 < param_3) {
                param_1._0_2_ = (ushort)CONCAT31(uVar1,(uVar10 < 0x100) + -1) & 0xff60;
                uVar3 = (undefined2)*local_24;
                local_24 = local_24 + 1;
              }
              else {
                iVar9 = (uVar10 - param_3) * 2;
                local_24 = local_24 + 1;
                param_1 = (int *)CONCAT31(uVar1,*(char *)(iVar9 + param_5) + 'P');
                uVar3 = *(undefined2 *)(iVar9 + param_4);
              }
              param_1 = (int *)CONCAT22(uVar3,(ushort)param_1);
            }
            else {
              param_1 = (int *)CONCAT31(uVar1,0xc0);
            }
            for (uVar10 = local_c >> (bVar11 & 0x1f); uVar10 < local_28;
                uVar10 = uVar10 + (1 << ((char)local_8 - bVar11 & 0x1f))) {
              *(int **)(iVar4 + uVar10 * 4) = param_1;
            }
            uVar10 = 1 << ((byte)local_2c & 0x1f);
            while ((local_c & uVar10) != 0) {
              local_c = local_c ^ uVar10;
              uVar10 = uVar10 >> 1;
            }
            local_c = local_c ^ uVar10;
            local_14 = 1;
            local_14 = local_30;
            piVar5 = param_1;
            if (((1 << (bVar11 & 0x1f)) - 1U & local_c) != local_b4[local_10]) {
              do {
                iVar6 = iVar6 - (int)param_7;
                local_10 = local_10 + -1;
              } while (((1 << ((byte)iVar6 & 0x1f)) - 1U & local_c) != local_b4[local_10]);
            }
          }
          local_8 = (uint *)((int)local_8 + 1);
          local_20 = local_20 + 1;
          local_2c = local_2c + 1;
        } while ((int)local_8 <= (int)local_1c);
      }
      if (local_34 == 0) {
        return 0;
      }
      if (local_1c == (uint *)0x1) {
        return 0;
      }
    }
LAB_00406c30:
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* VA 00406c3a */

BOOL VerQueryValueA(LPCVOID pBlock,LPCSTR lpSubBlock,LPVOID *lplpBuffer,PUINT puLen)

{
  BOOL BVar1;

                    /* WARNING: Could not recover jumptable at 0x00406c3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = VerQueryValueA(pBlock,lpSubBlock,lplpBuffer,puLen);
  return BVar1;
}



/* VA 00406c40 */

BOOL GetFileVersionInfoA(LPCSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lpData)

{
  BOOL BVar1;

                    /* WARNING: Could not recover jumptable at 0x00406c40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetFileVersionInfoA(lptstrFilename,dwHandle,dwLen,lpData);
  return BVar1;
}



/* VA 00406c46 */

DWORD GetFileVersionInfoSizeA(LPCSTR lptstrFilename,LPDWORD lpdwHandle)

{
  DWORD DVar1;

                    /* WARNING: Could not recover jumptable at 0x00406c46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = GetFileVersionInfoSizeA(lptstrFilename,lpdwHandle);
  return DVar1;
}
