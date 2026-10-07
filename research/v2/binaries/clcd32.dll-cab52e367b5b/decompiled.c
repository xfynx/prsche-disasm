/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 cab52e367b5b05b27dc12a20a1b2425ed116df3dd68b51cf81101f0028fd82a6 */

/* VA 10001000 */

void _SetVectors_If32_16(undefined2 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4
                        )

{
                    /* 0x1000  10  _SetVectors_If32@16 */
  FUN_10001247(param_1,param_2,param_3,param_4);
  return;
}



/* VA 10001020 */

void _SetIDT_If32_8(undefined2 param_1)

{
                    /* 0x1020  8  _SetIDT_If32@8 */
  FUN_100011f5(param_1);
  return;
}



/* VA 10001040 */

void _GetIDT_If32_8(undefined2 param_1)

{
                    /* 0x1040  1  _GetIDT_If32@8 */
  FUN_100011f9(param_1);
  return;
}



/* VA 10001060 */

void _GetRMInts_If32_8(undefined2 param_1)

{
                    /* 0x1060  2  _GetRMInts_If32@8 */
  FUN_100011f1(param_1);
  return;
}



/* VA 10001080 */

void _GetV86Vector_If32_12(undefined2 param_1)

{
                    /* 0x1080  3  _GetV86Vector_If32@12 */
  thunk_FUN_100011c3(param_1);
  return;
}



/* VA 100010a0 */

void _SetV86Vector_If32_12(undefined2 param_1)

{
                    /* 0x10a0  9  _SetV86Vector_If32@12 */
  FUN_100011c1(param_1);
  return;
}



/* VA 100010c0 */

void _InitIV_32_12(undefined2 param_1)

{
                    /* 0x10c0  5  _InitIV_32@12 */
  thunk_FUN_100011c3(param_1);
  return;
}



/* VA 100010e0 */

void _GetVectors_If32_8(void)

{
                    /* 0x10e0  4  _GetVectors_If32@8 */
  FUN_10001273();
  return;
}



/* VA 10001100 */

void _InitVectors_32_8(undefined4 param_1)

{
                    /* 0x1100  6  _InitVectors_32@8 */
  FUN_1000129f(param_1);
  return;
}



/* VA 10001120 */

void _IsLoadComplete_32_4(void)

{
                    /* 0x1120  7  _IsLoadComplete_32@4 */
  FUN_100012c3();
  return;
}



/* VA 10001130 */

bool FUN_10001130(void)

{
  int iVar1;

  iVar1 = FUN_10001160();
  return iVar1 != 0;
}



/* VA 10001160 */

void FUN_10001160(void)

{
  ThunkConnect32(&thk_ThunkData32);
  return;
}



/* VA 100011b5 */

void thunk_FUN_100011c3(undefined2 param_1)

{
  FUN_100011c3(param_1);
  return;
}



/* VA 100011bd */

void thunk_FUN_100011c3(undefined2 param_1)

{
  FUN_100011c3(param_1);
  return;
}



/* VA 100011c1 */

void FUN_100011c1(undefined2 param_1)

{
  undefined4 uVar1;

  uVar1 = SMapLS_IP_EBP_12(param_1);
  uVar1 = SMapLS_IP_EBP_16(uVar1);
  (*(code *)PTR_FUN_10001181)(uVar1);
  SUnMapLS_IP_EBP_12();
  SUnMapLS_IP_EBP_16();
  return;
}



/* VA 100011c3 */

void FUN_100011c3(undefined2 param_1)

{
  undefined4 uVar1;

  uVar1 = SMapLS_IP_EBP_12(param_1);
  uVar1 = SMapLS_IP_EBP_16(uVar1);
  (*(code *)PTR_FUN_10001181)(uVar1);
  SUnMapLS_IP_EBP_12();
  SUnMapLS_IP_EBP_16();
  return;
}



/* VA 100011f1 */

void FUN_100011f1(undefined2 param_1)

{
  undefined4 uVar1;

  uVar1 = SMapLS_IP_EBP_12(param_1);
  (*(code *)PTR_FUN_10001181)(uVar1);
  SUnMapLS_IP_EBP_12();
  return;
}



/* VA 100011f5 */

void FUN_100011f5(undefined2 param_1)

{
  undefined4 uVar1;

  uVar1 = SMapLS_IP_EBP_12(param_1);
  (*(code *)PTR_FUN_10001181)(uVar1);
  SUnMapLS_IP_EBP_12();
  return;
}



/* VA 100011f9 */

void FUN_100011f9(undefined2 param_1)

{
  undefined4 uVar1;

  uVar1 = SMapLS_IP_EBP_12(param_1);
  (*(code *)PTR_FUN_10001181)(uVar1);
  SUnMapLS_IP_EBP_12();
  return;
}



/* VA 10001247 */

void FUN_10001247(undefined2 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4)

{
  SMapLS_IP_EBP_16(param_2,param_1);
  (*(code *)PTR_FUN_10001181)(param_4);
  SUnMapLS_IP_EBP_16();
  return;
}



/* VA 10001273 */

void FUN_10001273(void)

{
  undefined4 uVar1;

  uVar1 = SMapLS_IP_EBP_8();
  uVar1 = SMapLS_IP_EBP_12(uVar1);
  (*(code *)PTR_FUN_10001181)(uVar1);
  SUnMapLS_IP_EBP_8();
  SUnMapLS_IP_EBP_12();
  return;
}



/* VA 1000129f */

void FUN_1000129f(undefined4 param_1)

{
  undefined4 uVar1;

  uVar1 = SMapLS_IP_EBP_12(param_1);
  (*(code *)PTR_FUN_10001181)(uVar1);
  SUnMapLS_IP_EBP_12();
  return;
}



/* VA 100012c3 */

void FUN_100012c3(void)

{
  undefined4 uVar1;

  uVar1 = SMapLS_IP_EBP_8();
  (*(code *)PTR_FUN_10001181)(uVar1);
  SUnMapLS_IP_EBP_8();
  return;
}



/* VA 100012e4 */

void SMapLS_IP_EBP_8(void)

{
                    /* WARNING: Could not recover jumptable at 0x100012e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SMapLS_IP_EBP_8();
  return;
}



/* VA 100012ea */

void SUnMapLS_IP_EBP_8(void)

{
                    /* WARNING: Could not recover jumptable at 0x100012ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SUnMapLS_IP_EBP_8();
  return;
}



/* VA 100012f0 */

void SMapLS_IP_EBP_12(void)

{
                    /* WARNING: Could not recover jumptable at 0x100012f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SMapLS_IP_EBP_12();
  return;
}



/* VA 100012f6 */

void SUnMapLS_IP_EBP_12(void)

{
                    /* WARNING: Could not recover jumptable at 0x100012f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SUnMapLS_IP_EBP_12();
  return;
}



/* VA 100012fc */

void SMapLS_IP_EBP_16(void)

{
                    /* WARNING: Could not recover jumptable at 0x100012fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SMapLS_IP_EBP_16();
  return;
}



/* VA 10001302 */

void SUnMapLS_IP_EBP_16(void)

{
                    /* WARNING: Could not recover jumptable at 0x10001302. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SUnMapLS_IP_EBP_16();
  return;
}



/* VA 10001314 */

void ThunkConnect32(void)

{
                    /* WARNING: Could not recover jumptable at 0x10001314. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ThunkConnect32();
  return;
}



/* VA 10001320 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10001320(undefined4 param_1,int param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;

  if (param_2 != 1) {
    if (param_2 != 0) {
      if (param_2 == 3) {
        FUN_10001810((undefined *)0x0);
      }
      return 1;
    }
    if (0 < DAT_100077c8) {
      DAT_100077c8 = DAT_100077c8 + -1;
      if (DAT_10007818 == 0) {
        FUN_100015d0();
      }
      FUN_10001ac0();
      FUN_10001740();
      FUN_10002370();
      return 1;
    }
    return 0;
  }
  DAT_100077e0 = GetVersion();
  if (DAT_100077d8 == 0) {
    if (((char)DAT_100077e0 == '\x03') && ((DAT_100077e0 & 0x80000000) != 0)) {
      FUN_100023b0(2);
    }
    hModule = GetModuleHandleA("kernel32.dll");
    if (hModule != (HMODULE)0x0) {
      pFVar1 = GetProcAddress(hModule,"IsTNT");
      if (pFVar1 != (FARPROC)0x0) {
        FUN_100023b0(1);
      }
    }
  }
  iVar2 = FUN_10002330();
  if (iVar2 == 0) {
    return 0;
  }
  _DAT_100077ec = DAT_100077e0 >> 8 & 0xff;
  _DAT_100077e8 = DAT_100077e0 & 0xff;
  _DAT_100077e4 = _DAT_100077e8 * 0x100 + _DAT_100077ec;
  DAT_100077e0 = DAT_100077e0 >> 0x10;
  iVar2 = FUN_100016e0();
  if (iVar2 == 0) {
    FUN_10002370();
    return 0;
  }
  DAT_10008c30 = GetCommandLineA();
  DAT_100077cc = FUN_100021d0();
  if ((DAT_10008c30 != (LPSTR)0x0) && (DAT_100077cc != (LPSTR)0x0)) {
    FUN_100018b0();
    FUN_100021c0();
    FUN_10001c10();
    FUN_10001b20();
    FUN_10001580();
    DAT_100077c8 = DAT_100077c8 + 1;
    return 1;
  }
  FUN_10001740();
  FUN_10002370();
  return 0;
}



/* VA 10001490 */

int entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;

  iVar2 = 1;
  if ((param_2 == 0) && (DAT_100077c8 == 0)) {
    return 0;
  }
  if ((param_2 != 1) && (param_2 != 2)) {
LAB_100014ee:
    bVar1 = FUN_10001130();
    iVar2 = CONCAT31(extraout_var,bVar1);
    if ((param_2 == 1) && (iVar2 == 0)) {
      FUN_10001320(param_1,0);
    }
    if ((param_2 == 0) || (param_2 == 3)) {
      iVar3 = FUN_10001320(param_1,param_2);
      if (iVar3 == 0) {
        iVar2 = 0;
      }
      if ((iVar2 != 0) && (DAT_10008c34 != (code *)0x0)) {
        iVar2 = (*DAT_10008c34)(param_1,param_2,param_3);
      }
    }
    return iVar2;
  }
  if (DAT_10008c34 != (code *)0x0) {
    iVar2 = (*DAT_10008c34)(param_1,param_2,param_3);
  }
  if (iVar2 != 0) {
    iVar2 = FUN_10001320(param_1,param_2);
    if (iVar2 != 0) goto LAB_100014ee;
  }
  return 0;
}



/* VA 10001540 */

/* Library Function - Single Match
    __amsg_exit

   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if ((DAT_100077d4 == 1) || ((DAT_100077d4 == 0 && (DAT_100077d8 == 1)))) {
    FUN_100023c0();
  }
  FUN_10002400(param_1);
  (*(code *)PTR___exit_100050ac)(0xff);
  return;
}



/* VA 10001580 */

void FUN_10001580(void)

{
  if (DAT_10008c2c != (code *)0x0) {
    (*DAT_10008c2c)();
  }
  FUN_100016c0((undefined4 *)&DAT_10005008,(undefined4 *)&DAT_10005010);
  FUN_100016c0((undefined4 *)&DAT_10005000,(undefined4 *)&DAT_10005004);
  return;
}



/* VA 100015b0 */

/* Library Function - Single Match
    __exit

   Library: Visual Studio 1998 Release */

void __cdecl __exit(int _Code)

{
  FUN_100015e0(_Code,1,0);
  return;
}



/* VA 100015d0 */

void FUN_100015d0(void)

{
  FUN_100015e0(0,0,1);
  return;
}



/* VA 100015e0 */

void __cdecl FUN_100015e0(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  undefined4 *puVar2;
  UINT uExitCode;

  FUN_100016a0();
  if (DAT_1000781c == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  DAT_10007818 = 1;
  DAT_10007814 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_10008c28 != (undefined4 *)0x0) &&
       (puVar2 = (undefined4 *)(DAT_10008c24 + -4), puVar1 = DAT_10008c28, DAT_10008c28 <= puVar2))
    {
      do {
        if ((code *)*puVar2 != (code *)0x0) {
          (*(code *)*puVar2)();
          puVar1 = DAT_10008c28;
        }
        puVar2 = puVar2 + -1;
      } while (puVar1 <= puVar2);
    }
    FUN_100016c0((undefined4 *)&DAT_10005014,(undefined4 *)&DAT_1000501c);
  }
  FUN_100016c0((undefined4 *)&DAT_10005020,(undefined4 *)&DAT_10005024);
  if (param_3 != 0) {
    FUN_100016b0();
    return;
  }
  DAT_1000781c = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}



/* VA 100016a0 */

void FUN_100016a0(void)

{
  FUN_10002690(0xd);
  return;
}



/* VA 100016b0 */

void FUN_100016b0(void)

{
  FUN_10002710(0xd);
  return;
}



/* VA 100016c0 */

void __cdecl FUN_100016c0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* VA 100016e0 */

undefined4 FUN_100016e0(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;

  FUN_100025e0();
  DAT_100050b0 = TlsAlloc();
  if (DAT_100050b0 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_10002810(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_100050b0,lpTlsValue);
      if (BVar1 != 0) {
        FUN_10001770((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        *lpTlsValue = DVar2;
        lpTlsValue[1] = 0xffffffff;
        return 1;
      }
    }
  }
  return 0;
}



/* VA 10001740 */

void FUN_10001740(void)

{
  FUN_10002610();
  if (DAT_100050b0 != 0xffffffff) {
    TlsFree(DAT_100050b0);
    DAT_100050b0 = 0xffffffff;
  }
  return;
}



/* VA 10001770 */

void __cdecl FUN_10001770(int param_1)

{
  *(undefined **)(param_1 + 0x50) = &DAT_10005330;
  *(undefined4 *)(param_1 + 0x14) = 1;
  return;
}



/* VA 10001810 */

void __cdecl FUN_10001810(undefined *param_1)

{
  if (DAT_100050b0 != 0xffffffff) {
    if ((param_1 != (undefined *)0x0) ||
       (param_1 = TlsGetValue(DAT_100050b0), param_1 != (undefined *)0x0)) {
      if (*(undefined **)(param_1 + 0x24) != (undefined *)0x0) {
        FUN_100028c0(*(undefined **)(param_1 + 0x24));
      }
      if (*(undefined **)(param_1 + 0x28) != (undefined *)0x0) {
        FUN_100028c0(*(undefined **)(param_1 + 0x28));
      }
      if (*(undefined **)(param_1 + 0x30) != (undefined *)0x0) {
        FUN_100028c0(*(undefined **)(param_1 + 0x30));
      }
      if (*(undefined **)(param_1 + 0x38) != (undefined *)0x0) {
        FUN_100028c0(*(undefined **)(param_1 + 0x38));
      }
      if (*(undefined **)(param_1 + 0x40) != (undefined *)0x0) {
        FUN_100028c0(*(undefined **)(param_1 + 0x40));
      }
      if (*(undefined **)(param_1 + 0x44) != (undefined *)0x0) {
        FUN_100028c0(*(undefined **)(param_1 + 0x44));
      }
      FUN_100028c0(param_1);
    }
    TlsSetValue(DAT_100050b0,(LPVOID)0x0);
    return;
  }
  return;
}



/* VA 100018b0 */

void FUN_100018b0(void)

{
  byte bVar1;
  undefined4 *puVar2;
  DWORD DVar3;
  HANDLE hFile;
  byte *pbVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  UINT *pUVar8;
  UINT local_48;
  _STARTUPINFOA local_44;

  puVar2 = (undefined4 *)FUN_10002930(0x480);
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_10008c20 = 0x20;
  DAT_10008b20 = puVar2;
  if (puVar2 < puVar2 + 0x120) {
    do {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar2[2] = 0;
      puVar2 = puVar2 + 9;
    } while (puVar2 < DAT_10008b20 + 0x120);
  }
  GetStartupInfoA(&local_44);
  if ((local_44.cbReserved2 != 0) && ((UINT *)local_44.lpReserved2 != (UINT *)0x0)) {
    local_48 = *(UINT *)local_44.lpReserved2;
    pUVar8 = (UINT *)((int)local_44.lpReserved2 + 4);
    pbVar4 = (byte *)((int)pUVar8 + local_48);
    if (0x7ff < (int)local_48) {
      local_48 = 0x800;
    }
    if ((int)DAT_10008c20 < (int)local_48) {
      piVar6 = &DAT_10008b24;
      do {
        puVar2 = (undefined4 *)FUN_10002930(0x480);
        if (puVar2 == (undefined4 *)0x0) {
          local_48 = DAT_10008c20;
          break;
        }
        *piVar6 = (int)puVar2;
        DAT_10008c20 = DAT_10008c20 + 0x20;
        if (puVar2 < puVar2 + 0x120) {
          do {
            *(undefined1 *)(puVar2 + 1) = 0;
            *puVar2 = 0xffffffff;
            *(undefined1 *)((int)puVar2 + 5) = 10;
            puVar2[2] = 0;
            puVar2 = puVar2 + 9;
          } while (puVar2 < (undefined4 *)(*piVar6 + 0x480));
        }
        piVar6 = piVar6 + 1;
      } while ((int)DAT_10008c20 < (int)local_48);
    }
    uVar7 = 0;
    if (0 < (int)local_48) {
      do {
        if (((*(HANDLE *)pbVar4 != (HANDLE)0xffffffff) && ((*pUVar8 & 1) != 0)) &&
           (((*pUVar8 & 8) != 0 || (DVar3 = GetFileType(*(HANDLE *)pbVar4), DVar3 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_10008b20)[(int)uVar7 >> 5] + (uVar7 & 0x1f) * 0x24);
          *puVar2 = *(undefined4 *)pbVar4;
          *(byte *)(puVar2 + 1) = (byte)*pUVar8;
        }
        uVar7 = uVar7 + 1;
        pUVar8 = (UINT *)((int)pUVar8 + 1);
        pbVar4 = pbVar4 + 4;
      } while ((int)uVar7 < (int)local_48);
    }
  }
  iVar5 = 0;
  do {
    puVar2 = DAT_10008b20 + iVar5 * 9;
    if (DAT_10008b20[iVar5 * 9] == -1) {
      *(undefined1 *)(puVar2 + 1) = 0x81;
      if (iVar5 == 0) {
        DVar3 = 0xfffffff6;
      }
      else {
        DVar3 = 0xfffffff5 - (iVar5 != 1);
      }
      hFile = GetStdHandle(DVar3);
      if ((hFile == (HANDLE)0xffffffff) || (DVar3 = GetFileType(hFile), DVar3 == 0)) {
        bVar1 = *(byte *)(puVar2 + 1) | 0x40;
        goto LAB_10001a9e;
      }
      *puVar2 = hFile;
      if ((DVar3 & 0xff) == 2) {
        bVar1 = *(byte *)(puVar2 + 1) | 0x40;
        goto LAB_10001a9e;
      }
      if ((DVar3 & 0xff) == 3) {
        bVar1 = *(byte *)(puVar2 + 1) | 8;
        goto LAB_10001a9e;
      }
    }
    else {
      bVar1 = *(byte *)(puVar2 + 1) | 0x80;
LAB_10001a9e:
      *(byte *)(puVar2 + 1) = bVar1;
    }
    iVar5 = iVar5 + 1;
    if (2 < iVar5) {
      SetHandleCount(DAT_10008c20);
      return;
    }
  } while( true );
}



/* VA 10001ac0 */

void FUN_10001ac0(void)

{
  uint *puVar1;
  uint uVar2;
  LPCRITICAL_SECTION lpCriticalSection;

  puVar1 = &DAT_10008b20;
  do {
    uVar2 = *puVar1;
    if (uVar2 != 0) {
      if (uVar2 < uVar2 + 0x480) {
        lpCriticalSection = (LPCRITICAL_SECTION)(uVar2 + 0xc);
        do {
          if (lpCriticalSection[-1].SpinCount != 0) {
            DeleteCriticalSection(lpCriticalSection);
          }
          uVar2 = uVar2 + 0x24;
          lpCriticalSection = (LPCRITICAL_SECTION)&lpCriticalSection[1].OwningThread;
        } while (uVar2 < *puVar1 + 0x480);
      }
      FUN_100028c0((undefined *)*puVar1);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x10008c20);
  return;
}



/* VA 10001b20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10001b20(void)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  int *local_4;

  iVar8 = 0;
  cVar2 = *DAT_100077cc;
  pcVar7 = DAT_100077cc;
  while (cVar2 != '\0') {
    if (cVar2 != '=') {
      iVar8 = iVar8 + 1;
    }
    uVar4 = 0xffffffff;
    pcVar9 = pcVar7;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar2 != '\0');
    pcVar9 = pcVar7 + ~uVar4;
    pcVar7 = pcVar7 + ~uVar4;
    cVar2 = *pcVar9;
  }
  piVar3 = (int *)FUN_10002930(iVar8 * 4 + 4);
  _DAT_100077fc = piVar3;
  if (piVar3 == (int *)0x0) {
    __amsg_exit(9);
  }
  cVar2 = *DAT_100077cc;
  local_4 = piVar3;
  pcVar7 = DAT_100077cc;
  do {
    if (cVar2 == '\0') {
      FUN_100028c0(DAT_100077cc);
      DAT_100077cc = (char *)0x0;
      *piVar3 = 0;
      return;
    }
    uVar4 = 0xffffffff;
    pcVar9 = pcVar7;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    if (cVar2 != '=') {
      iVar8 = FUN_10002930(uVar4);
      *piVar3 = iVar8;
      if (iVar8 == 0) {
        __amsg_exit(9);
      }
      uVar5 = 0xffffffff;
      pcVar9 = pcVar7;
      do {
        pcVar10 = pcVar9;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar10 = pcVar9 + 1;
        cVar2 = *pcVar9;
        pcVar9 = pcVar10;
      } while (cVar2 != '\0');
      uVar5 = ~uVar5;
      pcVar9 = pcVar10 + -uVar5;
      pcVar10 = (char *)*local_4;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar10 = pcVar10 + 4;
      }
      piVar3 = local_4 + 1;
      for (uVar5 = uVar5 & 3; local_4 = piVar3, uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar10 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar10 = pcVar10 + 1;
      }
    }
    cVar2 = pcVar7[uVar4];
    pcVar7 = pcVar7 + uVar4;
  } while( true );
}



/* VA 10001c10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10001c10(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_8;
  int local_4;

  GetModuleFileNameA((HMODULE)0x0,&DAT_10007820,0x104);
  _DAT_1000780c = &DAT_10007820;
  pbVar2 = DAT_10008c30;
  if (*DAT_10008c30 == 0) {
    pbVar2 = &DAT_10007820;
  }
  FUN_10001cb0(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = (undefined4 *)FUN_10002930(local_4 + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_10001cb0(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_100077f4 = puVar1;
  _DAT_100077f0 = local_8 + -1;
  return;
}



/* VA 10001cb0 */

void __cdecl FUN_10001cb0(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int *piVar6;
  byte *pbVar7;
  uint uVar8;

  piVar6 = param_5;
  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  if (*param_1 == 0x22) {
    bVar2 = param_1[1];
    while ((pbVar7 = param_1 + 1, bVar2 != 0x22 && (bVar2 != 0))) {
      if (((*(byte *)((int)&DAT_10007928 + bVar2 + 1) & 4) != 0) &&
         (*param_5 = *param_5 + 1, param_3 != (byte *)0x0)) {
        *param_3 = *pbVar7;
        param_3 = param_3 + 1;
        pbVar7 = param_1 + 2;
      }
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *pbVar7;
        param_3 = param_3 + 1;
      }
      param_1 = pbVar7;
      bVar2 = pbVar7[1];
    }
    *param_5 = *param_5 + 1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    if (*pbVar7 == 0x22) {
      pbVar7 = param_1 + 2;
    }
  }
  else {
    do {
      *piVar6 = *piVar6 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      bVar2 = *param_1;
      pbVar7 = param_1 + 1;
      param_5 = (int *)(uint)bVar2;
      if ((*(byte *)((int)param_5 + 0x10007929) & 4) != 0) {
        *piVar6 = *piVar6 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar7;
          param_3 = param_3 + 1;
        }
        pbVar7 = param_1 + 2;
      }
      if (bVar2 == 0x20) break;
      if (bVar2 == 0) goto LAB_10001d89;
      param_1 = pbVar7;
    } while (bVar2 != 9);
    if (bVar2 == 0) {
LAB_10001d89:
      pbVar7 = pbVar7 + -1;
    }
    else if (param_3 != (byte *)0x0) {
      param_3[-1] = 0;
    }
  }
  bVar4 = false;
  bVar5 = false;
  while (*pbVar7 != 0) {
    for (; (*pbVar7 == 0x20 || (*pbVar7 == 9)); pbVar7 = pbVar7 + 1) {
    }
    if (*pbVar7 == 0) break;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_3;
      param_2 = param_2 + 1;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      uVar8 = 0;
      bVar3 = true;
      bVar2 = *pbVar7;
      while (bVar2 == 0x5c) {
        pbVar1 = pbVar7 + 1;
        pbVar7 = pbVar7 + 1;
        uVar8 = uVar8 + 1;
        bVar2 = *pbVar1;
      }
      if (*pbVar7 == 0x22) {
        if ((uVar8 & 1) == 0) {
          if ((bVar4) && (pbVar7[1] == 0x22)) {
            pbVar7 = pbVar7 + 1;
          }
          else {
            bVar3 = false;
          }
          bVar4 = !bVar5;
          bVar5 = bVar4;
        }
        uVar8 = uVar8 >> 1;
      }
      for (; uVar8 != 0; uVar8 = uVar8 - 1) {
        if (param_3 != (byte *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *piVar6 = *piVar6 + 1;
      }
      bVar2 = *pbVar7;
      if ((bVar2 == 0) || ((!bVar4 && ((bVar2 == 0x20 || (bVar2 == 9)))))) break;
      if (bVar3) {
        if (param_3 == (byte *)0x0) {
          if ((*(byte *)((int)&DAT_10007928 + bVar2 + 1) & 4) != 0) {
            pbVar7 = pbVar7 + 1;
            *piVar6 = *piVar6 + 1;
          }
          *piVar6 = *piVar6 + 1;
          goto LAB_10001e85;
        }
        if ((*(byte *)((int)&DAT_10007928 + bVar2 + 1) & 4) != 0) {
          *param_3 = bVar2;
          param_3 = param_3 + 1;
          pbVar7 = pbVar7 + 1;
          *piVar6 = *piVar6 + 1;
        }
        *param_3 = *pbVar7;
        param_3 = param_3 + 1;
        *piVar6 = *piVar6 + 1;
        pbVar7 = pbVar7 + 1;
      }
      else {
LAB_10001e85:
        pbVar7 = pbVar7 + 1;
      }
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *piVar6 = *piVar6 + 1;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}



/* VA 10001ec0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10001ec0(int param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  UINT CodePage;
  UINT *pUVar5;
  BOOL BVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  BYTE *pBVar11;
  byte *pbVar12;
  byte *pbVar13;
  undefined4 *puVar14;
  _cpinfo local_14;

  FUN_10002690(0x19);
  CodePage = FUN_100020e0(param_1);
  if (CodePage == DAT_10007a2c) {
    FUN_10002710(0x19);
    return 0;
  }
  if (CodePage != 0) {
    iVar10 = 0;
    pUVar5 = &DAT_100050e8;
    do {
      if (*pUVar5 == CodePage) {
        puVar14 = &DAT_10007928;
        for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar14 = 0;
          puVar14 = puVar14 + 1;
        }
        *(undefined1 *)puVar14 = 0;
        uVar7 = 0;
        iVar10 = iVar10 * 0x30;
        pbVar12 = (byte *)(iVar10 + 0x100050f8);
        do {
          bVar3 = *pbVar12;
          for (pbVar13 = pbVar12; (bVar3 != 0 && (bVar3 = pbVar13[1], bVar3 != 0));
              pbVar13 = pbVar13 + 2) {
            uVar8 = (uint)*pbVar13;
            if (uVar8 <= bVar3) {
              bVar4 = (&DAT_100050e0)[uVar7];
              do {
                pbVar2 = (byte *)((int)&DAT_10007928 + uVar8 + 1);
                *pbVar2 = *pbVar2 | bVar4;
                uVar8 = uVar8 + 1;
              } while (uVar8 <= bVar3);
            }
            bVar3 = pbVar13[2];
          }
          uVar7 = uVar7 + 1;
          pbVar12 = pbVar12 + 8;
        } while (uVar7 < 4);
        DAT_10007a2c = CodePage;
        _DAT_10007a30 = FUN_10002130(CodePage);
        _DAT_10007a38 = *(undefined4 *)(iVar10 + 0x100050ec);
        _DAT_10007a3c = *(undefined4 *)(iVar10 + 0x100050f0);
        _DAT_10007a40 = *(undefined4 *)(iVar10 + 0x100050f4);
        FUN_10002710(0x19);
        return 0;
      }
      pUVar5 = pUVar5 + 0xc;
      iVar10 = iVar10 + 1;
    } while (pUVar5 < &DAT_100051d8);
    BVar6 = GetCPInfo(CodePage,&local_14);
    if (BVar6 == 1) {
      puVar14 = &DAT_10007928;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar14 = 0;
        puVar14 = puVar14 + 1;
      }
      *(undefined1 *)puVar14 = 0;
      if (local_14.MaxCharSize < 2) {
        DAT_10007a2c = 0;
        _DAT_10007a30 = 0;
      }
      else {
        if (local_14.LeadByte[0] != '\0') {
          pBVar11 = local_14.LeadByte + 1;
          do {
            bVar3 = *pBVar11;
            if (bVar3 == 0) break;
            for (uVar7 = (uint)pBVar11[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
              *(byte *)((int)&DAT_10007928 + uVar7 + 1) =
                   *(byte *)((int)&DAT_10007928 + uVar7 + 1) | 4;
            }
            pBVar1 = pBVar11 + 1;
            pBVar11 = pBVar11 + 2;
          } while (*pBVar1 != 0);
        }
        uVar7 = 1;
        do {
          *(byte *)((int)&DAT_10007928 + uVar7 + 1) = *(byte *)((int)&DAT_10007928 + uVar7 + 1) | 8;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 0xff);
        DAT_10007a2c = CodePage;
        _DAT_10007a30 = FUN_10002130(CodePage);
      }
      _DAT_10007a38 = 0;
      _DAT_10007a3c = 0;
      _DAT_10007a40 = 0;
      FUN_10002710(0x19);
      return 0;
    }
    if (DAT_10007a44 == 0) {
      FUN_10002710(0x19);
      return 0xffffffff;
    }
  }
  FUN_10002190();
  FUN_10002710(0x19);
  return 0;
}



/* VA 100020e0 */

int __cdecl FUN_100020e0(int param_1)

{
  int iVar1;
  bool bVar2;

  if (param_1 == -2) {
    DAT_10007a44 = 1;
                    /* WARNING: Could not recover jumptable at 0x100020fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_10007a44 = 1;
                    /* WARNING: Could not recover jumptable at 0x10002112. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_10007ad0;
  }
  DAT_10007a44 = (uint)bVar2;
  return param_1;
}



/* VA 10002130 */

undefined4 __cdecl FUN_10002130(undefined4 param_1)

{
  switch(param_1) {
  case 0x3a4:
    return 0x411;
  default:
    return 0;
  case 0x3a8:
    return 0x804;
  case 0x3b5:
    return 0x412;
  case 0x3b6:
    return 0x404;
  }
}



/* VA 10002190 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10002190(void)

{
  int iVar1;
  undefined4 *puVar2;

  puVar2 = &DAT_10007928;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_10007a2c = 0;
  _DAT_10007a30 = 0;
  _DAT_10007a38 = 0;
  _DAT_10007a3c = 0;
  _DAT_10007a40 = 0;
  return;
}



/* VA 100021c0 */

void FUN_100021c0(void)

{
  FUN_10001ec0(-3);
  return;
}



/* VA 100021d0 */

LPSTR FUN_100021d0(void)

{
  char cVar1;
  WCHAR WVar2;
  WCHAR *pWVar3;
  int iVar5;
  uint uVar6;
  LPSTR pCVar7;
  LPCH pCVar8;
  LPCH pCVar9;
  LPCH pCVar10;
  LPWCH lpWideCharStr;
  CHAR *pCVar11;
  LPSTR pCVar12;
  WCHAR *pWVar4;

  lpWideCharStr = (LPWCH)0x0;
  pCVar10 = (LPCH)0x0;
  if (DAT_10007a4c == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar10 = GetEnvironmentStrings();
      if (pCVar10 == (LPCH)0x0) {
        return (LPSTR)0x0;
      }
      DAT_10007a4c = 2;
    }
    else {
      DAT_10007a4c = 1;
    }
  }
  if (DAT_10007a4c == 1) {
    if ((lpWideCharStr != (LPWCH)0x0) ||
       (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr != (LPWCH)0x0)) {
      WVar2 = *lpWideCharStr;
      pWVar3 = lpWideCharStr;
      while (WVar2 != L'\0') {
        do {
          pWVar4 = pWVar3;
          pWVar3 = pWVar4 + 1;
        } while (*pWVar3 != L'\0');
        pWVar3 = pWVar4 + 2;
        WVar2 = *pWVar3;
      }
      iVar5 = ((int)pWVar3 - (int)lpWideCharStr >> 1) + 1;
      uVar6 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      if ((uVar6 != 0) && (pCVar7 = (LPSTR)FUN_10002930(uVar6), pCVar7 != (LPSTR)0x0)) {
        iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,pCVar7,uVar6,(LPCSTR)0x0,(LPBOOL)0x0);
        if (iVar5 == 0) {
          FUN_100028c0(pCVar7);
          pCVar7 = (LPSTR)0x0;
        }
        FreeEnvironmentStringsW(lpWideCharStr);
        return pCVar7;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return (LPSTR)0x0;
    }
  }
  else if ((DAT_10007a4c == 2) &&
          ((pCVar10 != (LPCH)0x0 || (pCVar10 = GetEnvironmentStrings(), pCVar10 != (LPCH)0x0)))) {
    cVar1 = *pCVar10;
    pCVar9 = pCVar10;
    while (cVar1 != '\0') {
      do {
        pCVar8 = pCVar9;
        pCVar9 = pCVar8 + 1;
      } while (pCVar8[1] != '\0');
      pCVar9 = pCVar8 + 2;
      cVar1 = pCVar8[2];
    }
    pCVar9 = pCVar9 + (1 - (int)pCVar10);
    pCVar7 = (LPSTR)FUN_10002930((uint)pCVar9);
    if (pCVar7 != (LPSTR)0x0) {
      pCVar11 = pCVar10;
      pCVar12 = pCVar7;
      for (uVar6 = (uint)pCVar9 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pCVar12 = *(undefined4 *)pCVar11;
        pCVar11 = pCVar11 + 4;
        pCVar12 = pCVar12 + 4;
      }
      for (uVar6 = (uint)pCVar9 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pCVar12 = *pCVar11;
        pCVar11 = pCVar11 + 1;
        pCVar12 = pCVar12 + 1;
      }
      FreeEnvironmentStringsA(pCVar10);
      return pCVar7;
    }
    FreeEnvironmentStringsA(pCVar10);
    return (LPSTR)0x0;
  }
  return (LPSTR)0x0;
}



/* VA 10002330 */

undefined4 FUN_10002330(void)

{
  undefined **ppuVar1;

  DAT_10008b04 = HeapCreate(0,0x1000,0);
  if (DAT_10008b04 == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = FUN_10002a00();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_10008b04);
    return 0;
  }
  return 1;
}



/* VA 10002370 */

void FUN_10002370(void)

{
  undefined **ppuVar1;

  ppuVar1 = &PTR_LOOP_100053b8;
  do {
    if (ppuVar1[4] != (undefined *)0x0) {
      VirtualFree(ppuVar1[4],0,0x8000);
    }
    ppuVar1 = (undefined **)*ppuVar1;
  } while (ppuVar1 != &PTR_LOOP_100053b8);
  HeapDestroy(DAT_10008b04);
  return;
}



/* VA 100023b0 */

void __cdecl FUN_100023b0(undefined4 param_1)

{
  DAT_100077d8 = param_1;
  return;
}



/* VA 100023c0 */

void FUN_100023c0(void)

{
  if ((DAT_100077d4 == 1) || ((DAT_100077d4 == 0 && (DAT_100077d8 == 1)))) {
    FUN_10002400(0xfc);
    if (DAT_10007a50 != (code *)0x0) {
      (*DAT_10007a50)();
    }
    FUN_10002400(0xff);
  }
  return;
}



/* VA 10002400 */

void __cdecl FUN_10002400(int param_1)

{
  char cVar1;
  int *piVar2;
  DWORD DVar3;
  HANDLE hFile;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  CHAR *pCVar10;
  char *pcVar11;
  DWORD local_1a8;
  char local_1a4 [100];
  char acStack_140 [60];
  CHAR local_104 [260];

  piVar2 = &DAT_100051e0;
  iVar8 = 0;
  do {
    if (param_1 == *piVar2) break;
    piVar2 = piVar2 + 2;
    iVar8 = iVar8 + 1;
  } while (piVar2 < &DAT_10005270);
  if (param_1 == (&DAT_100051e0)[iVar8 * 2]) {
    if ((DAT_100077d4 == 1) || ((DAT_100077d4 == 0 && (DAT_100077d8 == 1)))) {
      if ((DAT_10008b20 == 0) ||
         (hFile = *(HANDLE *)(DAT_10008b20 + 0x48), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar7 = *(char **)(iVar8 * 8 + 0x100051e4);
      uVar5 = 0xffffffff;
      pcVar9 = pcVar7;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      WriteFile(hFile,pcVar7,~uVar5 - 1,&local_1a8,(LPOVERLAPPED)0x0);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,local_104,0x104);
      if (DVar3 == 0) {
        pcVar7 = "<program name unknown>";
        pCVar10 = local_104;
        for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined4 *)pCVar10 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pCVar10 = pCVar10 + 4;
        }
        *(undefined2 *)pCVar10 = *(undefined2 *)pcVar7;
        pCVar10[2] = pcVar7[2];
      }
      uVar5 = 0xffffffff;
      pcVar7 = local_104;
      pcVar9 = local_104;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      if (0x3c < ~uVar5) {
        uVar5 = 0xffffffff;
        pcVar7 = local_104;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        pcVar7 = acStack_140 + ~uVar5;
        _strncpy(pcVar7,"...",3);
      }
      pcVar9 = "Runtime Error!\n\nProgram: ";
      pcVar11 = local_1a4;
      for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar11 = pcVar11 + 4;
      }
      *(undefined2 *)pcVar11 = *(undefined2 *)pcVar9;
      uVar5 = 0xffffffff;
      do {
        pcVar9 = pcVar7;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar4 = -1;
      pcVar7 = local_1a4;
      do {
        pcVar11 = pcVar7;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar11 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar11;
      } while (cVar1 != '\0');
      pcVar7 = pcVar9 + -uVar5;
      pcVar9 = pcVar11 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar5 = 0xffffffff;
      pcVar7 = "\n\n";
      do {
        pcVar9 = pcVar7;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar4 = -1;
      pcVar7 = local_1a4;
      do {
        pcVar11 = pcVar7;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar11 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar11;
      } while (cVar1 != '\0');
      pcVar7 = pcVar9 + -uVar5;
      pcVar9 = pcVar11 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar5 = 0xffffffff;
      pcVar7 = *(char **)(iVar8 * 8 + 0x100051e4);
      do {
        pcVar9 = pcVar7;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar9 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar9;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar8 = -1;
      pcVar7 = local_1a4;
      do {
        pcVar11 = pcVar7;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar11 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar11;
      } while (cVar1 != '\0');
      pcVar7 = pcVar9 + -uVar5;
      pcVar9 = pcVar11 + -1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar9 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar9 = pcVar9 + 1;
      }
      FUN_10003120(local_1a4,"Microsoft Visual C++ Runtime Library",0x12010);
      return;
    }
  }
  return;
}



/* VA 100025e0 */

void FUN_100025e0(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_100052b4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_100052a4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10005294);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10005274);
  return;
}



/* VA 10002610 */

void FUN_10002610(void)

{
  undefined **ppuVar1;

  ppuVar1 = (undefined **)&DAT_10005270;
  do {
    if (((((LPCRITICAL_SECTION)*ppuVar1 != (LPCRITICAL_SECTION)0x0) &&
         (ppuVar1 != &PTR_DAT_100052b4)) && (ppuVar1 != &PTR_DAT_100052a4)) &&
       ((ppuVar1 != &PTR_DAT_10005294 && (ppuVar1 != &PTR_DAT_10005274)))) {
      DeleteCriticalSection((LPCRITICAL_SECTION)*ppuVar1);
      FUN_100028c0(*ppuVar1);
    }
    ppuVar1 = ppuVar1 + 1;
  } while ((int)ppuVar1 < 0x10005330);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10005294);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_100052a4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_100052b4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10005274);
  return;
}



/* VA 10002690 */

void __cdecl FUN_10002690(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;

  if ((&DAT_10005270)[param_1] == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)FUN_10002930(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_10002690(0x11);
    if ((&DAT_10005270)[param_1] == 0) {
      InitializeCriticalSection(lpCriticalSection);
      (&DAT_10005270)[param_1] = lpCriticalSection;
    }
    else {
      FUN_100028c0((undefined *)lpCriticalSection);
    }
    FUN_10002710(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_10005270)[param_1]);
  return;
}



/* VA 10002710 */

void __cdecl FUN_10002710(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_10005270)[param_1]);
  return;
}



/* VA 10002730 */

void __cdecl FUN_10002730(uint param_1)

{
  if ((0x100073df < param_1) && (param_1 < 0x10007641)) {
    FUN_10002690(((int)(param_1 + 0xefff8c20) >> 5) + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



/* VA 10002770 */

void __cdecl FUN_10002770(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_10002690(param_1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



/* VA 100027a0 */

void __cdecl FUN_100027a0(uint param_1)

{
  if ((0x100073df < param_1) && (param_1 < 0x10007641)) {
    FUN_10002710(((int)(param_1 + 0xefff8c20) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



/* VA 100027e0 */

void __cdecl FUN_100027e0(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_10002710(param_1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



/* VA 10002810 */

int * __cdecl FUN_10002810(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint dwBytes;
  int *piVar3;
  int *piVar4;

  dwBytes = param_2 * param_1;
  if (dwBytes < 0xffffffe1) {
    if (dwBytes == 0) {
      dwBytes = 0x10;
    }
    else {
      dwBytes = dwBytes + 0xf & 0xfffffff0;
    }
  }
  do {
    piVar3 = (int *)0x0;
    if (dwBytes < 0xffffffe1) {
      if (DAT_100073dc < dwBytes) {
LAB_10002884:
        if (piVar3 != (int *)0x0) {
          return piVar3;
        }
      }
      else {
        FUN_10002690(9);
        piVar3 = FUN_10002d60(dwBytes >> 4);
        FUN_10002710(9);
        if (piVar3 != (int *)0x0) {
          piVar4 = piVar3;
          for (uVar2 = dwBytes >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
            *piVar4 = 0;
            piVar4 = piVar4 + 1;
          }
          for (uVar2 = dwBytes & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
            *(undefined1 *)piVar4 = 0;
            piVar4 = (int *)((int)piVar4 + 1);
          }
          goto LAB_10002884;
        }
      }
      piVar3 = HeapAlloc(DAT_10008b04,8,dwBytes);
    }
    if ((piVar3 != (int *)0x0) || (DAT_10007aec == 0)) {
      return piVar3;
    }
    iVar1 = FUN_10003390(dwBytes);
    if (iVar1 == 0) {
      return (int *)0x0;
    }
  } while( true );
}



/* VA 100028c0 */

void __cdecl FUN_100028c0(undefined *param_1)

{
  undefined *lpMem;
  byte *pbVar1;
  int local_4;

  lpMem = param_1;
  if (param_1 != (undefined *)0x0) {
    FUN_10002690(9);
    pbVar1 = (byte *)FUN_10002ca0(lpMem,&local_4,(uint *)&param_1);
    if (pbVar1 != (byte *)0x0) {
      FUN_10002d00(local_4,(int)param_1,pbVar1);
      FUN_10002710(9);
      return;
    }
    FUN_10002710(9);
    HeapFree(DAT_10008b04,0,lpMem);
  }
  return;
}



/* VA 10002930 */

void __cdecl FUN_10002930(uint param_1)

{
  FUN_10002950(param_1,DAT_10007aec);
  return;
}



/* VA 10002950 */

int * __cdecl FUN_10002950(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;

  if (param_1 < 0xffffffe1) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    do {
      if (param_1 < 0xffffffe1) {
        piVar1 = FUN_100029a0(param_1);
      }
      else {
        piVar1 = (int *)0x0;
      }
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
      if (param_2 == 0) {
        return (int *)0x0;
      }
      iVar2 = FUN_10003390(param_1);
    } while (iVar2 != 0);
  }
  return (int *)0x0;
}



/* VA 100029a0 */

int * __cdecl FUN_100029a0(int param_1)

{
  int *piVar1;
  uint dwBytes;

  dwBytes = param_1 + 0xfU & 0xfffffff0;
  if (dwBytes <= DAT_100073dc) {
    FUN_10002690(9);
    piVar1 = FUN_10002d60(param_1 + 0xfU >> 4);
    FUN_10002710(9);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
  }
  piVar1 = HeapAlloc(DAT_10008b04,0,dwBytes);
  return piVar1;
}



/* VA 10002a00 */

undefined ** FUN_10002a00(void)

{
  bool bVar1;
  undefined4 *lpAddress;
  LPVOID pvVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **lpMem;
  undefined4 *puVar5;

  if (DAT_100053c8 == -1) {
    lpMem = &PTR_LOOP_100053b8;
  }
  else {
    lpMem = HeapAlloc(DAT_10008b04,0,0x2020);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar2 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar2 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_100053b8) {
        if (PTR_LOOP_100053b8 == (undefined *)0x0) {
          PTR_LOOP_100053b8 = (undefined *)&PTR_LOOP_100053b8;
        }
        if (PTR_LOOP_100053bc == (undefined *)0x0) {
          PTR_LOOP_100053bc = (undefined *)&PTR_LOOP_100053b8;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_100053b8;
        lpMem[1] = PTR_LOOP_100053bc;
        PTR_LOOP_100053bc = (undefined *)lpMem;
        *(undefined ***)lpMem[1] = lpMem;
      }
      lpMem[5] = (undefined *)(lpAddress + 0x100000);
      lpMem[4] = (undefined *)lpAddress;
      lpMem[2] = (undefined *)(lpMem + 6);
      lpMem[3] = (undefined *)(lpMem + 0x26);
      iVar3 = 0;
      ppuVar4 = lpMem + 6;
      do {
        bVar1 = 0xf < iVar3;
        iVar3 = iVar3 + 1;
        *ppuVar4 = (undefined *)((bVar1 - 1 & 0xf1) - 1);
        ppuVar4[1] = (undefined *)0xf1;
        ppuVar4 = ppuVar4 + 2;
      } while (iVar3 < 0x400);
      puVar5 = lpAddress;
      for (iVar3 = 0x4000; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      if (lpAddress < lpMem[4] + 0x10000) {
        do {
          lpAddress[1] = 0xf0;
          *lpAddress = lpAddress + 2;
          *(undefined1 *)(lpAddress + 0x3e) = 0xff;
          lpAddress = lpAddress + 0x400;
        } while (lpAddress < lpMem[4] + 0x10000);
      }
      return lpMem;
    }
    VirtualFree(lpAddress,0,0x8000);
  }
  if (lpMem != &PTR_LOOP_100053b8) {
    HeapFree(DAT_10008b04,0,lpMem);
  }
  return (undefined **)0x0;
}



/* VA 10002b70 */

void __cdecl FUN_10002b70(undefined **param_1)

{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR_LOOP_100073d8 == param_1) {
    PTR_LOOP_100073d8 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_100053b8) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_10008b04,0,param_1);
    return;
  }
  DAT_100053c8 = 0xffffffff;
  return;
}



/* VA 10002bd0 */

void __cdecl FUN_10002bd0(int param_1)

{
  BOOL BVar1;
  undefined **ppuVar2;
  int iVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;

  ppuVar6 = (undefined **)PTR_LOOP_100053bc;
  do {
    ppuVar5 = ppuVar6;
    if (ppuVar6[4] != (undefined *)0xffffffff) {
      iVar4 = 0;
      ppuVar5 = ppuVar6 + 0x804;
      iVar3 = 0x3ff000;
      do {
        if (*ppuVar5 == (undefined *)0xf0) {
          BVar1 = VirtualFree(ppuVar6[4] + iVar3,0x1000,0x4000);
          if (BVar1 != 0) {
            *ppuVar5 = (undefined *)0xffffffff;
            DAT_10007ad4 = DAT_10007ad4 + -1;
            if (((undefined **)ppuVar6[3] == (undefined **)0x0) || (ppuVar5 < ppuVar6[3])) {
              ppuVar6[3] = (undefined *)ppuVar5;
            }
            iVar4 = iVar4 + 1;
            param_1 = param_1 + -1;
            if (param_1 == 0) break;
          }
        }
        iVar3 = iVar3 + -0x1000;
        ppuVar5 = ppuVar5 + -2;
      } while (-1 < iVar3);
      ppuVar5 = (undefined **)ppuVar6[1];
      if ((iVar4 != 0) && (ppuVar6[6] == (undefined *)0xffffffff)) {
        iVar3 = 1;
        ppuVar2 = ppuVar6 + 8;
        do {
          if (*ppuVar2 != (undefined *)0xffffffff) break;
          iVar3 = iVar3 + 1;
          ppuVar2 = ppuVar2 + 2;
        } while (iVar3 < 0x400);
        if (iVar3 == 0x400) {
          FUN_10002b70(ppuVar6);
        }
      }
    }
    if ((ppuVar5 == (undefined **)PTR_LOOP_100053bc) || (ppuVar6 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}



/* VA 10002ca0 */

int __cdecl FUN_10002ca0(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined **ppuVar1;
  uint uVar2;

  ppuVar1 = &PTR_LOOP_100053b8;
  while ((param_1 <= ppuVar1[4] || (ppuVar1[5] <= param_1))) {
    ppuVar1 = (undefined **)*ppuVar1;
    if (ppuVar1 == &PTR_LOOP_100053b8) {
      return 0;
    }
  }
  if (((uint)param_1 & 0xf) != 0) {
    return 0;
  }
  if (((uint)param_1 & 0xfff) < 0x100) {
    return 0;
  }
  *param_2 = ppuVar1;
  uVar2 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar2;
  return ((int)(param_1 + (-0x100 - uVar2)) >> 4) + 8 + uVar2;
}



/* VA 10002d00 */

void __cdecl FUN_10002d00(int param_1,int param_2,byte *param_3)

{
  int *piVar1;
  int iVar2;

  iVar2 = param_2 - *(int *)(param_1 + 0x10) >> 0xc;
  piVar1 = (int *)(param_1 + 0x18 + iVar2 * 8);
  *piVar1 = *(int *)(param_1 + 0x18 + iVar2 * 8) + (uint)*param_3;
  *param_3 = 0;
  piVar1[1] = 0xf1;
  if ((*piVar1 == 0xf0) && (DAT_10007ad4 = DAT_10007ad4 + 1, DAT_10007ad4 == 0x20)) {
    FUN_10002bd0(0x10);
  }
  return;
}



/* VA 10002d60 */

int * __cdecl FUN_10002d60(uint param_1)

{
  undefined **ppuVar1;
  uint *puVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  int *piVar5;
  undefined **ppuVar6;
  undefined **ppuVar7;
  int *piVar8;
  int iVar9;
  uint *puVar10;
  int *piVar11;
  bool bVar12;

  piVar11 = (int *)PTR_LOOP_100073d8;
  do {
    if (piVar11[4] != -1) {
      puVar10 = (uint *)piVar11[2];
      piVar8 = (int *)(((int)puVar10 + (-0x18 - (int)piVar11) >> 3) * 0x1000 + piVar11[4]);
      for (; puVar10 < piVar11 + 0x806; puVar10 = puVar10 + 2) {
        if (((int)param_1 <= (int)*puVar10) && (param_1 < puVar10[1])) {
          piVar5 = (int *)FUN_10002fa0(piVar8,*puVar10,param_1);
          if (piVar5 != (int *)0x0) {
            PTR_LOOP_100073d8 = (undefined *)piVar11;
            *puVar10 = *puVar10 - param_1;
            piVar11[2] = (int)puVar10;
            return piVar5;
          }
          puVar10[1] = param_1;
        }
        piVar8 = piVar8 + 0x400;
      }
      puVar2 = (uint *)piVar11[2];
      piVar8 = (int *)piVar11[4];
      for (puVar10 = (uint *)(piVar11 + 6); puVar10 < puVar2; puVar10 = puVar10 + 2) {
        if (((int)param_1 <= (int)*puVar10) && (param_1 < puVar10[1])) {
          piVar5 = (int *)FUN_10002fa0(piVar8,*puVar10,param_1);
          if (piVar5 != (int *)0x0) {
            PTR_LOOP_100073d8 = (undefined *)piVar11;
            *puVar10 = *puVar10 - param_1;
            piVar11[2] = (int)puVar10;
            return piVar5;
          }
          puVar10[1] = param_1;
        }
        piVar8 = piVar8 + 0x400;
      }
    }
    piVar11 = (int *)*piVar11;
  } while (piVar11 != (int *)PTR_LOOP_100073d8);
  ppuVar7 = &PTR_LOOP_100053b8;
  while ((ppuVar7[4] == (undefined *)0xffffffff || (ppuVar7[3] == (undefined *)0x0))) {
    ppuVar7 = (undefined **)*ppuVar7;
    if (ppuVar7 == &PTR_LOOP_100053b8) {
      ppuVar7 = FUN_10002a00();
      if (ppuVar7 == (undefined **)0x0) {
        return (int *)0x0;
      }
      piVar11 = (int *)ppuVar7[4];
      *(char *)(piVar11 + 2) = (char)param_1;
      PTR_LOOP_100073d8 = (undefined *)ppuVar7;
      *piVar11 = (int)piVar11 + param_1 + 8;
      piVar11[1] = 0xf0 - param_1;
      ppuVar7[6] = ppuVar7[6] + -(param_1 & 0xff);
      return piVar11 + 0x40;
    }
  }
  ppuVar3 = (undefined **)ppuVar7[3];
  puVar4 = *ppuVar3;
  piVar11 = (int *)(ppuVar7[4] + ((int)ppuVar3 + (-0x18 - (int)ppuVar7) >> 3) * 0x1000);
  ppuVar6 = ppuVar3;
  for (iVar9 = 0; (puVar4 == (undefined *)0xffffffff && (iVar9 < 0x10)); iVar9 = iVar9 + 1) {
    puVar4 = ppuVar6[2];
    ppuVar6 = ppuVar6 + 2;
  }
  piVar8 = VirtualAlloc(piVar11,iVar9 << 0xc,0x1000,4);
  if (piVar8 != piVar11) {
    return (int *)0x0;
  }
  ppuVar6 = ppuVar3;
  if (0 < iVar9) {
    piVar8 = piVar11 + 1;
    do {
      *piVar8 = 0xf0;
      piVar8[-1] = (int)(piVar8 + 1);
      *(undefined1 *)(piVar8 + 0x3d) = 0xff;
      *ppuVar6 = (undefined *)0xf0;
      ppuVar6[1] = (undefined *)0xf1;
      piVar8 = piVar8 + 0x400;
      ppuVar6 = ppuVar6 + 2;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  ppuVar1 = ppuVar7 + 0x806;
  bVar12 = false;
  if (ppuVar6 < ppuVar1) {
    do {
      if (*ppuVar6 == (undefined *)0xffffffff) break;
      ppuVar6 = ppuVar6 + 2;
    } while (ppuVar6 < ppuVar1);
    bVar12 = ppuVar6 < ppuVar1;
  }
  PTR_LOOP_100073d8 = (undefined *)ppuVar7;
  ppuVar7[3] = (undefined *)(-(uint)bVar12 & (uint)ppuVar6);
  *(char *)(piVar11 + 2) = (char)param_1;
  ppuVar7[2] = (undefined *)ppuVar3;
  *ppuVar3 = *ppuVar3 + -param_1;
  piVar11[1] = piVar11[1] - param_1;
  *piVar11 = (int)piVar11 + param_1 + 8;
  return piVar11 + 0x40;
}



/* VA 10002fa0 */

int __cdecl FUN_10002fa0(int *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;

  pbVar2 = (byte *)*param_1;
  if (param_3 <= (uint)param_1[1]) {
    *pbVar2 = (byte)param_3;
    if (pbVar2 + param_3 < param_1 + 0x3e) {
      *param_1 = *param_1 + param_3;
      param_1[1] = param_1[1] - param_3;
    }
    else {
      param_1[1] = 0;
      *param_1 = (int)(param_1 + 2);
    }
    return (int)(pbVar2 + 8) * 0x10 + (int)param_1 * -0xf;
  }
  pbVar6 = pbVar2;
  if (pbVar2[param_1[1]] != 0) {
    pbVar6 = pbVar2 + param_1[1];
  }
  if (pbVar6 + param_3 < param_1 + 0x3e) {
    do {
      if (*pbVar6 == 0) {
        pbVar3 = pbVar6 + 1;
        uVar5 = 1;
        bVar1 = pbVar6[1];
        while (bVar1 == 0) {
          pbVar3 = pbVar3 + 1;
          uVar5 = uVar5 + 1;
          bVar1 = *pbVar3;
        }
        if (param_3 <= uVar5) {
          if (param_1 + 0x3e <= pbVar6 + param_3) {
            *param_1 = (int)(param_1 + 2);
            goto LAB_100030ef;
          }
          *param_1 = (int)(pbVar6 + param_3);
          param_1[1] = uVar5 - param_3;
          goto LAB_100030f6;
        }
        if (pbVar6 == pbVar2) {
          param_1[1] = uVar5;
        }
        else {
          param_2 = param_2 - uVar5;
          if (param_2 < param_3) {
            return 0;
          }
        }
      }
      else {
        pbVar3 = pbVar6 + *pbVar6;
      }
      pbVar6 = pbVar3;
    } while (pbVar3 + param_3 < param_1 + 0x3e);
  }
  pbVar3 = (byte *)(param_1 + 2);
  pbVar6 = pbVar3;
  if (pbVar3 < pbVar2) {
    while (pbVar6 + param_3 < param_1 + 0x3e) {
      if (*pbVar6 == 0) {
        pbVar4 = pbVar6 + 1;
        uVar5 = 1;
        bVar1 = pbVar6[1];
        while (bVar1 == 0) {
          pbVar4 = pbVar4 + 1;
          uVar5 = uVar5 + 1;
          bVar1 = *pbVar4;
        }
        if (param_3 <= uVar5) {
          if (pbVar6 + param_3 < param_1 + 0x3e) {
            *param_1 = (int)(pbVar6 + param_3);
            param_1[1] = uVar5 - param_3;
          }
          else {
            *param_1 = (int)pbVar3;
LAB_100030ef:
            param_1[1] = 0;
          }
LAB_100030f6:
          *pbVar6 = (byte)param_3;
          return (int)(pbVar6 + 8) * 0x10 + (int)param_1 * -0xf;
        }
        param_2 = param_2 - uVar5;
        if (param_2 < param_3) {
          return 0;
        }
      }
      else {
        pbVar4 = pbVar6 + *pbVar6;
      }
      pbVar6 = pbVar4;
      if (pbVar2 <= pbVar4) {
        return 0;
      }
    }
  }
  return 0;
}



/* VA 10003120 */

int __cdecl FUN_10003120(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;

  iVar1 = 0;
  if (DAT_10007ad8 != (FARPROC)0x0) {
LAB_10003170:
    if (DAT_10007adc != (FARPROC)0x0) {
      iVar1 = (*DAT_10007adc)();
    }
    if ((iVar1 != 0) && (DAT_10007ae0 != (FARPROC)0x0)) {
      iVar1 = (*DAT_10007ae0)(iVar1);
    }
    iVar1 = (*DAT_10007ad8)(iVar1,param_1,param_2,param_3);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_10007ad8 = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_10007ad8 != (FARPROC)0x0) {
      DAT_10007adc = GetProcAddress(hModule,"GetActiveWindow");
      DAT_10007ae0 = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_10003170;
    }
  }
  return 0;
}



/* VA 100031b0 */

/* Library Function - Single Match
    _strncpy

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strncpy(char *_Dest,char *_Source,size_t _Count)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;

  if (_Count == 0) {
    return _Dest;
  }
  puVar5 = (uint *)_Dest;
  if (((uint)_Source & 3) != 0) {
    while( true ) {
      uVar4 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 1);
      *(char *)puVar5 = (char)uVar4;
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
      if (_Count == 0) {
        return _Dest;
      }
      if ((char)uVar4 == '\0') break;
      if (((uint)_Source & 3) == 0) {
        uVar4 = _Count >> 2;
        goto joined_r0x100031ee;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_1000322b;
        goto LAB_10003299;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
    } while (_Count != 0);
    return _Dest;
  }
  uVar4 = _Count >> 2;
  if (uVar4 != 0) {
    do {
      uVar1 = *(uint *)_Source;
      uVar2 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 4);
      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar2 == '\0') {
          *puVar5 = 0;
joined_r0x10003295:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_10003299:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_1000322b;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x10003295;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x10003295;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x10003295;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x100031ee:
    } while (uVar4 != 0);
    _Count = _Count & 3;
    if (_Count == 0) {
      return _Dest;
    }
  }
  do {
    cVar3 = (char)*(uint *)_Source;
    _Source = (char *)((int)_Source + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (_Count = _Count - 1, _Count != 0) {
LAB_1000322b:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}



/* VA 10003390 */

undefined4 __cdecl FUN_10003390(undefined4 param_1)

{
  int iVar1;

  if (DAT_10007ae8 != (code *)0x0) {
    iVar1 = (*DAT_10007ae8)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



/* VA 1000506c */

void FUN_1000506c(void)

{
  code *pcVar1;

  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}
