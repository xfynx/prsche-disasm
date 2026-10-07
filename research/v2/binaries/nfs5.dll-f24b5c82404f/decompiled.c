/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 f24b5c82404f403645e5bc3e52d47e4dd6d19bd92613c243ac31bea285fce758 */

/* VA 10001000 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_10001000(void)

{
  uint in_EAX;
  undefined1 *puVar1;
  undefined4 unaff_retaddr;

  puVar1 = &stack0x00000004;
  for (; 0xfff < in_EAX; in_EAX = in_EAX - 0x1000) {
    puVar1 = puVar1 + -0x1000;
  }
  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}



/* VA 10001090 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10001090(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;

  bVar5 = 0;
  if (_DAT_0065b928 == 0) {
    iVar1 = *(int *)(param_1 + 0xf4);
    iVar4 = (*(code *)0x465d80)();
    if (*(int *)(iVar1 + 0x520) == iVar4) {
      bVar5 = DAT_00627f43 >> 3 & 1;
    }
  }
  (*(code *)0x44a150)();
  uVar2 = *(uint *)(param_1 + 0x2c0);
  if (bVar5 == 0) {
    if (*(char *)(param_1 + 0x471) != '\0') {
      (**(code **)(**(int **)(*(int *)(param_1 + 0xb0) + *(int *)(param_1 + 0x2c8) * 4) + 8))
                (param_2,0x30,0);
      return;
    }
    uVar3 = *(uint *)(&DAT_100050e0 + (_DAT_006197c4 * 7 + uVar2) * 4);
    if ((_DAT_0065b928 == 0) && (uVar3 < 4)) {
      (**(code **)(**(int **)(*(int *)(param_1 + 0xb0) + *(int *)(&DAT_10005094 + uVar3 * 4) * 4) +
                  8))(param_2,0x80,0);
    }
    (**(code **)(**(int **)(*(int *)(param_1 + 0xb0) + uVar3 * 4) + 8))(param_2,0x50,0);
    if (_DAT_0065b928 != 0) {
      (**(code **)(*(int *)**(undefined4 **)(param_1 + 0xb0) + 8))(param_2,0x20,0);
      return;
    }
    if ((*(byte *)(*(int *)(param_1 + 0xf4) + 0x52c) & 0x10) != 0) {
      (**(code **)(**(int **)(*(int *)(param_1 + 0xb0) + *(int *)(&DAT_10005188 + uVar2 * 4) * 4) +
                  8))(param_2,0x20,0);
      return;
    }
    (**(code **)(**(int **)(*(int *)(param_1 + 0xb0) + *(int *)(&DAT_1000516c + uVar2 * 4) * 4) + 8)
    )(param_2,0x20,0);
  }
  else {
    (**(code **)(**(int **)(*(int *)(param_1 + 0xb0) +
                           *(int *)(&DAT_100050ac + _DAT_006197c4 * 4) * 4) + 8))
              (param_2,0x10,1 < uVar2);
    (**(code **)(*(int *)**(undefined4 **)(param_1 + 0xb0) + 8))(param_2,0x40,1);
    if ((((_DAT_005e99b4 == 0) && (_DAT_005e99ac == 0)) && (_DAT_005e99b0 == 0)) &&
       (1 < _DAT_006197c4)) {
      (**(code **)(**(int **)(*(int *)(param_1 + 0xb0) +
                             *(int *)(&DAT_100050c0 + _DAT_006197c4 * 4) * 4) + 8))(param_2,0x80,1);
      return;
    }
  }
  return;
}



/* VA 10001300 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10001300(void)

{
  BOOL BVar1;
  DWORD local_4;

  BVar1 = VirtualProtect(&DAT_004e5817,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_004e5817 = 0x5b6d5c;
    VirtualProtect(&DAT_004e5817,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0044ef8b,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_0044ef8b = 0xe9;
    _DAT_0044ef8c = 0xfbb2340;
    VirtualProtect(&DAT_0044ef8b,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0044f110,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_0044f110 = 0xe9;
    _DAT_0044f111 = 0xfbb21cb;
    VirtualProtect(&DAT_0044f110,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0043a086,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0043a086 = &DAT_1000600c;
    VirtualProtect(&DAT_0043a086,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0043a08a,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_0043a08a = 0xe9;
    _DAT_0043a08b = 0xfbc6fd1;
    VirtualProtect(&DAT_0043a08a,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0043a3b6,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_0043a3b6 = 0xe9;
    _DAT_0043a3b7 = 0xfbc6cb5;
    VirtualProtect(&DAT_0043a3b6,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00444e00,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_00444e00 = 0xe9;
    _DAT_00444e01 = 0xfbbc4bb;
    VirtualProtect(&DAT_00444e00,5,local_4,&local_4);
  }
  return;
}



/* VA 10001580 */

/* WARNING: Removing unreachable block (ram,0x1000159d) */

undefined8 FUN_10001580(void)

{
  undefined8 uVar1;

  cpuid_basic_info(0);
  uVar1 = rdtsc();
  return uVar1;
}



/* VA 100015c0 */

uint FUN_100015c0(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  LARGE_INTEGER local_48;
  LARGE_INTEGER local_40;
  LARGE_INTEGER local_38;
  uint local_30 [11];

  if (DAT_100060c0 == 0) {
    GetCurrentThread();
    local_30[0] = 0;
    iVar4 = 0;
    local_30[1] = 0;
    local_30[2] = 0;
    local_30[3] = 0;
    local_30[4] = 0;
    local_30[5] = 0;
    local_30[6] = 0;
    local_30[7] = 0;
    local_30[8] = 0;
    local_30[9] = 0;
    do {
      QueryPerformanceCounter(&local_38);
      QueryPerformanceFrequency(&local_48);
      local_48.s.LowPart = local_48.s.LowPart >> 5 | local_48.s.HighPart << 0x1b;
      local_48.s.HighPart = local_48.s.HighPart >> 5;
      uVar5 = FUN_10001580();
      uVar1 = (uint)uVar5;
      do {
        do {
          QueryPerformanceCounter(&local_40);
          iVar2 = (local_40.s.HighPart - local_38._4_4_) -
                  (uint)(local_40.s.LowPart < local_38.s.LowPart);
        } while (iVar2 < local_48.s.HighPart);
      } while ((iVar2 <= local_48.s.HighPart) &&
              (local_40.s.LowPart - local_38._0_4_ < local_48.s.LowPart));
      uVar6 = FUN_10001580();
      uVar3 = (uint)uVar6 * 0x20;
      local_30[iVar4 * 2] = uVar3 + uVar1 * -0x20;
      local_30[iVar4 * 2 + 1] =
           (((int)((ulonglong)uVar6 >> 0x20) << 5 | (uint)uVar6 >> 0x1b) -
           ((int)((ulonglong)uVar5 >> 0x20) << 5 | uVar1 >> 0x1b)) - (uint)(uVar3 < uVar1 * 0x20);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 5);
    if ((local_30[1] <= local_30[3]) &&
       ((local_30[3] != local_30[1] || (local_30[0] < local_30[2])))) {
      local_30[0] = local_30[2];
      local_30[1] = local_30[3];
    }
    if ((local_30[1] <= local_30[5]) &&
       ((local_30[5] != local_30[1] || (local_30[0] < local_30[4])))) {
      local_30[0] = local_30[4];
      local_30[1] = local_30[5];
    }
    if ((local_30[1] <= local_30[7]) &&
       ((local_30[7] != local_30[1] || (local_30[0] < local_30[6])))) {
      local_30[0] = local_30[6];
      local_30[1] = local_30[7];
    }
    if ((local_30[1] <= local_30[9]) &&
       ((local_30[9] != local_30[1] || (local_30[0] < local_30[8])))) {
      local_30[0] = local_30[8];
      local_30[1] = local_30[9];
    }
    if (local_30[1] != 0) {
      return 0xffffffff;
    }
  }
  else {
    local_30[0] = DAT_100060c0 * 1000000;
  }
  return local_30[0];
}



/* VA 10001760 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10001760(void)

{
  BOOL BVar1;
  DWORD local_4;

  BVar1 = VirtualProtect(&DAT_00555f5a,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_00555f5a = 0xe9;
    _DAT_00555f5b = 0xfaab7c1;
    VirtualProtect(&DAT_00555f5a,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00555a2b,2,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00555a2b = 0xe1f7;
    VirtualProtect(&DAT_00555a2b,2,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_005561ad,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_005561ad = 0xe9;
    _DAT_005561ae = 0xfaab2ee;
    VirtualProtect(&DAT_005561ad,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00555ba4,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_00555ba4 = 0xe9;
    _DAT_00555ba5 = 0xfaab917;
    VirtualProtect(&DAT_00555ba4,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0044e370,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_0044e370 = 0xe9;
    _DAT_0044e371 = 0xfbb315b;
    VirtualProtect(&DAT_0044e370,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0044e410,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_0044e410 = 0xe9;
    _DAT_0044e411 = 0xfbb30db;
    VirtualProtect(&DAT_0044e410,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0044e480,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_0044e480 = 0xe9;
    _DAT_0044e481 = 0xfbb308b;
    VirtualProtect(&DAT_0044e480,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0044e500,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_0044e500 = 0xe9;
    _DAT_0044e501 = 0xfbb301b;
    VirtualProtect(&DAT_0044e500,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0044e580,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_0044e580 = 0xe9;
    _DAT_0044e581 = 0xfbb2fbb;
    VirtualProtect(&DAT_0044e580,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0044e5f0,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_0044e5f0 = 0xe9;
    _DAT_0044e5f1 = 0xfbb2f5b;
    VirtualProtect(&DAT_0044e5f0,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0044e670,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_0044e670 = 0xe9;
    _DAT_0044e671 = 0xfbb2efb;
    VirtualProtect(&DAT_0044e670,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00438de1,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00438de1 = &DAT_100051a8;
    VirtualProtect(&DAT_00438de1,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_005b3684,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_005b3684 = 0x48742400;
    VirtualProtect(&DAT_005b3684,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_005b3688,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_005b3688 = 0x47f42400;
    VirtualProtect(&DAT_005b3688,4,local_4,&local_4);
  }
  return;
}



/* VA 10001a90 */

undefined4 entry(HMODULE param_1,int param_2)

{
  HMODULE pHVar1;
  undefined4 local_130;
  undefined4 local_12c;
  CHAR *local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  HMODULE local_114;
  CHAR local_110 [268];

  if (param_2 == 0) {
    if ((DAT_100060d8 != 0) && (DAT_100060d8 != -1)) {
      (*DAT_100060d4)(DAT_100060d8);
    }
  }
  else if (param_2 == 1) {
    pHVar1 = GetModuleHandleA("KERNEL32.dll");
    if (pHVar1 != (HMODULE)0x0) {
      DAT_100060dc = GetProcAddress(pHVar1,"CreateActCtxA");
      DAT_100060d4 = GetProcAddress(pHVar1,"ReleaseActCtx");
      GetProcAddress(pHVar1,"ActivateActCtx");
      GetProcAddress(pHVar1,"DeactivateActCtx");
      DAT_10006118 = GetProcAddress(pHVar1,"SetProcessAffinityMask");
    }
    pHVar1 = GetModuleHandleA("USER32.dll");
    if (pHVar1 != (HMODULE)0x0) {
      DAT_10006124 = GetProcAddress(pHVar1,"MonitorFromWindow");
      DAT_10006128 = GetProcAddress(pHVar1,"GetMonitorInfoA");
    }
    FUN_10002020();
    if (DAT_100060dc != (FARPROC)0x0) {
      GetModuleFileNameA(param_1,local_110,0x103);
      local_128 = local_110;
      local_124 = 0;
      local_120 = 0;
      local_118 = 0;
      local_130 = 0x20;
      local_114 = param_1;
      local_11c = 2;
      local_12c = 0x88;
      DAT_100060d8 = (*DAT_100060dc)(&local_130);
      return 1;
    }
  }
  return 1;
}



/* VA 10001bd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10001bd0(uint *param_1)

{
  int iVar1;

  if (DAT_10006114 == 1) {
    iVar1 = (*_DAT_006bd934)();
    if (6 < *(uint *)(iVar1 + 0x7c)) {
      *param_1 = *param_1 | 0x20000;
    }
  }
  return;
}



/* VA 10001c20 */

undefined4
FUN_10001c20(LPCSTR param_1,LPCSTR param_2,uint param_3,int param_4,undefined4 param_5,DWORD param_6
            ,uint param_7,undefined4 param_8,undefined4 param_9,int param_10,undefined4 param_11,
            int param_12,int param_13,DWORD param_14)

{
  byte bVar1;
  HANDLE hFile;
  HANDLE hFile_00;
  byte *pbVar2;
  uint uVar3;
  DWORD DVar4;
  uint uVar5;
  undefined4 *lpBuffer;
  BOOL BVar6;
  byte *pbVar7;
  undefined4 uVar8;
  LPCSTR pCVar9;
  int unaff_EBP;
  LPCSTR nNumberOfBytesToRead;
  code *pcVar10;
  int iVar11;
  bool bVar12;

  FUN_10001000();
  uVar8 = 0;
  hFile = CreateFileA(param_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    hFile_00 = CreateFileA(param_2,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
    pcVar10 = CloseHandle_exref;
    if (hFile_00 != (HANDLE)0xffffffff) {
      ReadFile(hFile,&param_5,0x10,(LPDWORD)&stack0xfffffffc,(LPOVERLAPPED)0x0);
      pbVar7 = &DAT_100051dc;
      pbVar2 = (byte *)&param_5;
      do {
        bVar1 = *pbVar2;
        bVar12 = bVar1 < *pbVar7;
        if (bVar1 != *pbVar7) {
LAB_10001cc0:
          uVar3 = -(uint)bVar12 | 1;
          goto LAB_10001cc5;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar12 = bVar1 < pbVar7[1];
        if (bVar1 != pbVar7[1]) goto LAB_10001cc0;
        pbVar2 = pbVar2 + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar1 != 0);
      uVar3 = 0;
LAB_10001cc5:
      if (((uVar3 == 0) && (DVar4 = GetFileSize(hFile,(LPDWORD)0x0), param_6 == DVar4)) &&
         (param_3 < param_7)) {
        uVar3 = 0;
        param_2 = (LPCSTR)0x0;
        pCVar9 = param_2;
        if (param_7 != 0) {
          do {
            ReadFile(hFile,&param_11,8,(LPDWORD)&stack0xfffffffc,(LPOVERLAPPED)0x0);
            pbVar7 = &DAT_100051e4;
            pbVar2 = (byte *)&param_11;
            do {
              bVar1 = *pbVar2;
              bVar12 = bVar1 < *pbVar7;
              if (bVar1 != *pbVar7) {
LAB_10001d40:
                uVar5 = -(uint)bVar12 | 1;
                goto LAB_10001d45;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar2[1];
              bVar12 = bVar1 < pbVar7[1];
              if (bVar1 != pbVar7[1]) goto LAB_10001d40;
              pbVar2 = pbVar2 + 2;
              pbVar7 = pbVar7 + 2;
            } while (bVar1 != 0);
            uVar5 = 0;
LAB_10001d45:
            if (uVar5 == 0) {
              param_2 = (LPCSTR)0x1;
              if (uVar3 < param_7 - 1) {
                ReadFile(hFile,&param_13,8,(LPDWORD)&stack0xfffffffc,(LPOVERLAPPED)0x0);
                pCVar9 = (LPCSTR)(param_14 - param_12);
              }
              else {
                pCVar9 = (LPCSTR)(param_6 - param_12);
              }
              break;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < param_7);
        }
        SetFilePointer(hFile,param_3 * 8 + 0x10,(PLONG)0x0,0);
        ReadFile(hFile,&param_9,8,(LPDWORD)&stack0xfffffffc,(LPOVERLAPPED)0x0);
        if (pCVar9 < (LPCSTR)(param_7 - 1)) {
          ReadFile(hFile,&param_13,8,(LPDWORD)&stack0xfffffffc,(LPOVERLAPPED)0x0);
          param_6 = param_14;
        }
        iVar11 = param_10;
        uVar3 = param_6 - param_10;
        if (param_2 == (LPCSTR)0x0) {
          param_6 = uVar3 + 0x18;
          param_7 = 1;
          param_10 = 0x18;
          WriteFile(hFile_00,&param_5,0x10,(LPDWORD)&stack0xfffffffc,(LPOVERLAPPED)0x0);
          lpBuffer = &param_9;
        }
        else {
          param_13 = param_12;
          param_12 = uVar3 + 0x20;
          param_6 = (DWORD)(pCVar9 + uVar3 + 0x20);
          param_7 = 2;
          param_10 = 0x20;
          WriteFile(hFile_00,&param_5,0x10,(LPDWORD)&stack0xfffffffc,(LPOVERLAPPED)0x0);
          WriteFile(hFile_00,&param_9,8,(LPDWORD)&stack0xfffffffc,(LPOVERLAPPED)0x0);
          lpBuffer = &param_11;
        }
        WriteFile(hFile_00,lpBuffer,8,(LPDWORD)&stack0xfffffffc,(LPOVERLAPPED)0x0);
        SetFilePointer(hFile,iVar11,(PLONG)0x0,0);
        DVar4 = uVar3;
        if (0x1000 < uVar3) {
          DVar4 = 0x1000;
        }
        param_4 = 0;
        while (DVar4 != 0) {
          while( true ) {
            BVar6 = ReadFile(hFile,&stack0x0000003c,DVar4,(LPDWORD)&stack0xfffffffc,
                             (LPOVERLAPPED)0x0);
            if ((BVar6 == 0) || (unaff_EBP == 0)) goto LAB_10001f1b;
            param_4 = param_4 + unaff_EBP;
            WriteFile(hFile_00,&stack0x0000003c,DVar4,(LPDWORD)&stack0xfffffffc,(LPOVERLAPPED)0x0);
            DVar4 = uVar3 - param_4;
            if (DVar4 < 0x1001) break;
            DVar4 = 0x1000;
          }
        }
LAB_10001f1b:
        if (param_2 != (LPCSTR)0x0) {
          SetFilePointer(hFile,param_13,(PLONG)0x0,0);
          nNumberOfBytesToRead = pCVar9;
          if ((LPCSTR)0x1000 < pCVar9) {
            nNumberOfBytesToRead = (LPCSTR)0x1000;
          }
          if (nNumberOfBytesToRead != (LPCSTR)0x0) {
            iVar11 = 0;
            do {
              while( true ) {
                BVar6 = ReadFile(hFile,&stack0x0000003c,(DWORD)nNumberOfBytesToRead,
                                 (LPDWORD)&stack0xfffffffc,(LPOVERLAPPED)0x0);
                if ((BVar6 == 0) || (unaff_EBP == 0)) goto LAB_10001fa3;
                iVar11 = iVar11 + unaff_EBP;
                WriteFile(hFile_00,&stack0x0000003c,(DWORD)nNumberOfBytesToRead,
                          (LPDWORD)&stack0xfffffffc,(LPOVERLAPPED)0x0);
                nNumberOfBytesToRead = pCVar9 + -iVar11;
                if (nNumberOfBytesToRead < (LPCSTR)0x1001) break;
                nNumberOfBytesToRead = (LPCSTR)0x1000;
              }
            } while (nNumberOfBytesToRead != (LPCSTR)0x0);
          }
        }
LAB_10001fa3:
        uVar8 = 1;
        pcVar10 = CloseHandle_exref;
      }
      (*pcVar10)(hFile_00);
    }
    (*pcVar10)(hFile);
  }
  return uVar8;
}



/* VA 10001fe0 */

undefined4 __fastcall FUN_10001fe0(undefined4 *param_1,undefined4 param_2)

{
  BOOL BVar1;
  undefined4 *local_4;

  local_4 = param_1;
  BVar1 = VirtualProtect(param_1,4,0x40,(PDWORD)&local_4);
  if (BVar1 != 0) {
    *param_1 = param_2;
    VirtualProtect(param_1,4,(DWORD)local_4,(PDWORD)&local_4);
    return 1;
  }
  return 0;
}



/* VA 10002020 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10002020(void)

{
  BOOL BVar1;
  DWORD local_4;

  FUN_100029f0();
  FUN_10001760();
  BVar1 = VirtualProtect(&DAT_004dbe0a,7,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_004dbe0a = 0x90909090;
    _DAT_004dbe0e = 0x9090;
    DAT_004dbe10 = 0x90;
    VirtualProtect(&DAT_004dbe0a,7,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_004dbe43,7,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_004dbe43 = 0x90909090;
    _DAT_004dbe47 = 0x9090;
    DAT_004dbe49 = 0x90;
    VirtualProtect(&DAT_004dbe43,7,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_004dbe18,0xc,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_004dbe18 = 0x90909090;
    _DAT_004dbe1c = 0x90909090;
    _DAT_004dbe20 = 0x90909090;
    VirtualProtect(&DAT_004dbe18,0xc,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_004dbe36,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_004dbe36 = 0xe9;
    _DAT_004dbe37 = 0xfb26195;
    VirtualProtect(&DAT_004dbe36,5,local_4,&local_4);
  }
  FUN_10003c90();
  BVar1 = VirtualProtect(&DAT_0044dfb0,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_0044dfb0 = 0xe9;
    _DAT_0044dfb1 = 0xfbb307b;
    VirtualProtect(&DAT_0044dfb0,5,local_4,&local_4);
  }
  FUN_10001300();
  FUN_10003390();
  FUN_100042d0();
  BVar1 = VirtualProtect(&DAT_005492ae,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_005492ae = 0xe9;
    _DAT_005492af = 0xfab894d;
    VirtualProtect(&DAT_005492ae,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_005de6c4,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_005de6c4 = 0;
    VirtualProtect(&DAT_005de6c4,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_005404a5,0xc,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_005404a5 = 0x90909090;
    _DAT_005404a9 = 0x90909090;
    _DAT_005404ad = 0x90909090;
    VirtualProtect(&DAT_005404a5,0xc,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0054051d,0xc,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0054051d = 0x90909090;
    _DAT_00540521 = 0x90909090;
    _DAT_00540525 = 0x90909090;
    VirtualProtect(&DAT_0054051d,0xc,local_4,&local_4);
  }
  FUN_10002e30();
  BVar1 = VirtualProtect(&DAT_005752d5,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_005752d5 = 0xe9;
    _DAT_005752d6 = 0xfa8e416;
    VirtualProtect(&DAT_005752d5,5,local_4,&local_4);
  }
  return;
}



/* VA 100022b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100022b0(HMODULE param_1)

{
  LPCSTR lpKeyName;
  CHAR *pCVar1;
  char cVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  char *pcVar5;
  int iVar6;
  BOOL BVar7;
  UINT UVar8;
  HANDLE pvVar9;
  CHAR *pCVar10;
  undefined4 *puVar11;
  uint uVar12;
  char *pcVar13;
  char *pcVar14;
  undefined4 uVar15;
  DWORD local_724;
  UINT local_720;
  CHAR local_718 [255];
  undefined4 uStack_619;
  undefined1 local_614 [259];
  char cStack_511;
  char local_510 [264];
  CHAR aCStack_408 [1028];

  DVar4 = GetModuleFileNameA(param_1,(LPSTR)((int)&uStack_619 + 1),0x104);
  if (DVar4 != 0) {
    pcVar5 = strrchr((char *)((int)&uStack_619 + 1),0x2e);
    *pcVar5 = '\0';
    iVar6 = 0;
    do {
      cVar2 = *(char *)((int)&uStack_619 + iVar6 + 1);
      local_510[iVar6] = cVar2;
      iVar6 = iVar6 + 1;
    } while (cVar2 != '\0');
    puVar3 = &uStack_619;
    do {
      puVar11 = puVar3;
      puVar3 = (undefined4 *)((int)puVar11 + 1);
    } while (*(char *)((int)puVar11 + 1) != '\0');
    *(undefined4 *)((int)puVar11 + 1) = DAT_100051ec;
    *(undefined1 *)((int)puVar11 + 5) = DAT_100051f0;
    DVar4 = GetPrivateProfileStringA
                      ("NFS5","Language","English",local_718,0x100,(LPCSTR)((int)&uStack_619 + 1));
    if (DVar4 != 0) {
      iVar6 = _stricmp(local_718,"ENGLISH");
      if (iVar6 == 0) {
        DAT_100060a0 = 0;
      }
      else {
        iVar6 = _stricmp(local_718,"FRENCH");
        if (iVar6 == 0) {
          DAT_100060a0 = 1;
        }
        else {
          iVar6 = _stricmp(local_718,"GERMAN");
          if (iVar6 == 0) {
            DAT_100060a0 = 2;
          }
          else {
            iVar6 = _stricmp(local_718,"ITALIAN");
            if (iVar6 == 0) {
              DAT_100060a0 = 3;
            }
            else {
              iVar6 = _stricmp(local_718,"SPANISH");
              if (iVar6 == 0) {
                DAT_100060a0 = 4;
              }
              else {
                iVar6 = _stricmp(local_718,"SWEDISH");
                if (iVar6 == 0) {
                  DAT_100060a0 = 5;
                }
                else {
                  iVar6 = _stricmp(local_718,"PORTBRZL");
                  if (iVar6 == 0) {
                    DAT_100060a0 = 6;
                  }
                }
              }
            }
          }
        }
      }
    }
    _DAT_100060a4 = GetPrivateProfileIntA("NFS5","NoMovies",0,(LPCSTR)((int)&uStack_619 + 1));
    if ((_DAT_100060a4 != 0) &&
       (BVar7 = VirtualProtect(&DAT_004dd611,5,0x40,&local_724), BVar7 != 0)) {
      DAT_004dd611 = 0xe9;
      _DAT_004dd612 = 0xfb24c8a;
      VirtualProtect(&DAT_004dd611,5,local_724,&local_724);
    }
    GetPrivateProfileStringA
              ("NFS5","ThrashDriver","dx7z",&DAT_100060a8,0x10,(LPCSTR)((int)&uStack_619 + 1));
    DAT_100060b8 = GetPrivateProfileIntA("NFS5","WindowedMode",0,(LPCSTR)((int)&uStack_619 + 1));
    local_720 = DAT_100060b8;
    BVar7 = VirtualProtect(&DAT_004676ba,1,0x40,&local_724);
    if (BVar7 != 0) {
      DAT_004676ba = (undefined1)local_720;
      VirtualProtect(&DAT_004676ba,1,local_724,&local_724);
    }
    if ((DAT_100060b8 != 0) && (BVar7 = VirtualProtect(&DAT_0053ac98,4,0x40,&local_724), BVar7 != 0)
       ) {
      _DAT_0053ac98 = &LAB_10003710;
      VirtualProtect(&DAT_0053ac98,4,local_724,&local_724);
    }
    DAT_100060c8 = GetPrivateProfileIntA("NFS5","Fog",1,(LPCSTR)((int)&uStack_619 + 1));
    DAT_100060cc = GetPrivateProfileIntA("NFS5","Filtering",1,(LPCSTR)((int)&uStack_619 + 1));
    DAT_100060bc = GetPrivateProfileIntA
                             ("NFS5","SingleProcAffinity",0,(LPCSTR)((int)&uStack_619 + 1));
    DAT_100060c0 = GetPrivateProfileIntA("NFS5","CpuLimit",0,(LPCSTR)((int)&uStack_619 + 1));
    DAT_100060c4 = GetPrivateProfileIntA("NFS5","NoErrorReporting",0,(LPCSTR)((int)&uStack_619 + 1))
    ;
    _DAT_100060d0 = GetPrivateProfileIntA("NFS5","CarControl",0,(LPCSTR)((int)&uStack_619 + 1));
    if ((_DAT_100060d0 != 0) &&
       (BVar7 = VirtualProtect(&DAT_0049dd4c,2,0x40,&local_724), BVar7 != 0)) {
      _DAT_0049dd4c = 0x9090;
      VirtualProtect(&DAT_0049dd4c,2,local_724,&local_724);
    }
    if (DAT_100060c4 != 0) {
      UVar8 = SetErrorMode(0);
      SetErrorMode(UVar8 | 0x8003);
    }
    if ((DAT_100060bc != 0) && (DAT_10006118 != (code *)0x0)) {
      uVar15 = 1;
      pvVar9 = GetCurrentProcess();
      (*DAT_10006118)(pvVar9,uVar15);
    }
    pcVar5 = strrchr(local_510,0x5c);
    *pcVar5 = '\0';
    pcVar5 = &cStack_511;
    do {
      pcVar13 = pcVar5;
      pcVar5 = pcVar13 + 1;
    } while (pcVar13[1] != '\0');
    *(undefined4 *)(pcVar13 + 1) = s__drivers__100052d0._0_4_;
    *(undefined4 *)(pcVar13 + 5) = s__drivers__100052d0._4_4_;
    *(undefined2 *)(pcVar13 + 9) = s__drivers__100052d0._8_2_;
    pcVar5 = &DAT_100060a8;
    do {
      pcVar13 = pcVar5;
      pcVar5 = pcVar13 + 1;
    } while (*pcVar13 != '\0');
    pcVar5 = &cStack_511;
    do {
      pcVar14 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar14 != '\0');
    pcVar14 = &DAT_100060a8;
    for (uVar12 = (uint)(pcVar13 + -0x100060a7) >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar14;
      pcVar14 = pcVar14 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar12 = (uint)(pcVar13 + -0x100060a7) & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      *pcVar5 = *pcVar14;
      pcVar14 = pcVar14 + 1;
      pcVar5 = pcVar5 + 1;
    }
    pcVar5 = &cStack_511;
    do {
      pcVar13 = pcVar5;
      pcVar5 = pcVar13 + 1;
    } while (pcVar13[1] != '\0');
    *(undefined4 *)(pcVar13 + 1) = s__thrash_ini_100052dc._0_4_;
    *(undefined4 *)(pcVar13 + 5) = s__thrash_ini_100052dc._4_4_;
    *(undefined4 *)(pcVar13 + 9) = s__thrash_ini_100052dc._8_4_;
    GetPrivateProfileStringA("THRASH","File","",&DAT_100060e0,0x32,local_510);
    DVar4 = GetPrivateProfileStringA("THRASH","Type","",local_718,0x100,local_510);
    if (DVar4 != 0) {
      iVar6 = _stricmp(local_718,"D3D");
      if (iVar6 == 0) {
        DAT_10006114 = 1;
      }
      else {
        iVar6 = _stricmp(local_718,"VOODOO");
        if (iVar6 == 0) {
          DAT_10006114 = 2;
        }
        else {
          iVar6 = _stricmp(local_718,"OPENGL");
          if (iVar6 == 0) {
            DAT_10006114 = 3;
            if (DAT_100060b8 != 0) {
              FUN_10001fe0((undefined4 *)0x5dead4,0xa9);
            }
          }
          else {
            iVar6 = _stricmp(local_718,"SOFTWARE");
            if (iVar6 == 0) {
              DAT_10006114 = 4;
            }
          }
        }
      }
    }
    pCVar10 = (CHAR *)GetPrivateProfileStringA
                                ("ENV",(LPCSTR)0x0,(LPCSTR)0x0,aCStack_408,0x400,local_510);
    lpKeyName = aCStack_408;
    pCVar1 = pCVar10;
    while (pCVar1 != (CHAR *)0x0) {
      GetPrivateProfileStringA("ENV",lpKeyName,"",local_718,0x100,local_510);
      SetEnvironmentVariableA(lpKeyName,local_718);
      pcVar5 = strchr(lpKeyName,0);
      lpKeyName = pcVar5 + 1;
      pCVar1 = aCStack_408 + ((int)pCVar10 - (int)lpKeyName);
    }
  }
  return;
}



/* VA 10002940 */

void FUN_10002940(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  char *pcVar7;
  undefined2 *puVar8;

  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar7 = (char *)(param_1 + -1);
  do {
    pcVar5 = pcVar7 + 1;
    pcVar7 = pcVar7 + 1;
  } while (*pcVar5 != '\0');
  pcVar5 = param_2;
  for (uVar3 = (uint)((int)pcVar2 - (int)param_2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar3 = (int)pcVar2 - (int)param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar7 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  }
  puVar8 = (undefined2 *)(param_1 + -1);
  do {
    pcVar2 = (char *)((int)puVar8 + 1);
    puVar8 = (undefined2 *)((int)puVar8 + 1);
  } while (*pcVar2 != '\0');
  *puVar8 = DAT_10005344;
  pcVar2 = &DAT_100060e0;
  do {
    pcVar7 = pcVar2;
    pcVar2 = pcVar7 + 1;
  } while (*pcVar7 != '\0');
  puVar4 = (undefined4 *)(param_1 + -1);
  do {
    pcVar2 = (char *)((int)puVar4 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  } while (*pcVar2 != '\0');
  puVar6 = (undefined4 *)&DAT_100060e0;
  for (uVar3 = (uint)(pcVar7 + -0x100060df) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar4 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar4 = puVar4 + 1;
  }
  for (uVar3 = (uint)(pcVar7 + -0x100060df) & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar4 = *(undefined1 *)puVar6;
    puVar6 = (undefined4 *)((int)puVar6 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  return;
}



/* VA 100029f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100029f0(void)

{
  undefined4 uVar1;
  undefined1 uVar2;
  BOOL BVar3;
  DWORD local_c;
  undefined4 local_8;
  undefined1 uStack_4;

  BVar3 = VirtualProtect(&DAT_005a2df4,5,0x40,&local_c);
  if (BVar3 != 0) {
    DAT_005a2df4 = 0xe9;
    _DAT_005a2df5 = 0xfa5fa87;
    VirtualProtect(&DAT_005a2df4,5,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_00467521,4,0x40,&local_c);
  if (BVar3 != 0) {
    _DAT_00467521 = 0xfb9b37b;
    VirtualProtect(&DAT_00467521,4,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_00467600,4,0x40,&local_c);
  if (BVar3 != 0) {
    _DAT_00467600 = 0xfb9b29c;
    VirtualProtect(&DAT_00467600,4,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_0048dc01,4,0x40,&local_c);
  if (BVar3 != 0) {
    _DAT_0048dc01 = 0xfb74c9b;
    VirtualProtect(&DAT_0048dc01,4,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_0048dc26,4,0x40,&local_c);
  if (BVar3 != 0) {
    _DAT_0048dc26 = 0xfb74c76;
    VirtualProtect(&DAT_0048dc26,4,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_00509954,4,0x40,&local_c);
  if (BVar3 != 0) {
    _DAT_00509954 = 0xfaf8f48;
    VirtualProtect(&DAT_00509954,4,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_005099b7,4,0x40,&local_c);
  if (BVar3 != 0) {
    _DAT_005099b7 = 0xfaf8ee5;
    VirtualProtect(&DAT_005099b7,4,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_0046754e,5,0x40,&local_c);
  if (BVar3 != 0) {
    DAT_0046754e = 0xe9;
    _DAT_0046754f = 0xfb9b3dd;
    VirtualProtect(&DAT_0046754e,5,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_00467662,5,0x40,&local_c);
  if (BVar3 != 0) {
    DAT_00467662 = 0xe9;
    _DAT_00467663 = 0xfb9b369;
    VirtualProtect(&DAT_00467662,5,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_004679af,1,0x40,&local_c);
  if (BVar3 != 0) {
    DAT_004679af = 0xeb;
    VirtualProtect(&DAT_004679af,1,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_00467ffe,1,0x40,&local_c);
  if (BVar3 != 0) {
    DAT_00467ffe = 0xeb;
    VirtualProtect(&DAT_00467ffe,1,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_0046804e,1,0x40,&local_c);
  if (BVar3 != 0) {
    DAT_0046804e = 0xeb;
    VirtualProtect(&DAT_0046804e,1,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_0044e2cd,1,0x40,&local_c);
  if (BVar3 != 0) {
    DAT_0044e2cd = 0xeb;
    VirtualProtect(&DAT_0044e2cd,1,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_0044e72a,1,0x40,&local_c);
  if (BVar3 != 0) {
    DAT_0044e72a = 0xeb;
    VirtualProtect(&DAT_0044e72a,1,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_0044ec02,1,0x40,&local_c);
  if (BVar3 != 0) {
    DAT_0044ec02 = 0xeb;
    VirtualProtect(&DAT_0044ec02,1,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_0044e78a,1,0x40,&local_c);
  if (BVar3 != 0) {
    DAT_0044e78a = 0xeb;
    VirtualProtect(&DAT_0044e78a,1,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_0044e70a,1,0x40,&local_c);
  if (BVar3 != 0) {
    DAT_0044e70a = 0xeb;
    VirtualProtect(&DAT_0044e70a,1,local_c,&local_c);
  }
  local_8 = 0x60a0a1;
  uStack_4 = 0x10;
  BVar3 = VirtualProtect(&DAT_0041e1f0,5,0x40,&local_c);
  uVar2 = uStack_4;
  uVar1 = local_8;
  if (BVar3 != 0) {
    _DAT_0041e1f0 = local_8;
    DAT_0041e1f4 = uStack_4;
    VirtualProtect(&DAT_0041e1f0,5,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_004a5d31,5,0x40,&local_c);
  if (BVar3 != 0) {
    _DAT_004a5d31 = uVar1;
    DAT_004a5d35 = uVar2;
    VirtualProtect(&DAT_004a5d31,5,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_004e0581,5,0x40,&local_c);
  if (BVar3 != 0) {
    _DAT_004e0581 = uVar1;
    DAT_004e0585 = uVar2;
    VirtualProtect(&DAT_004e0581,5,local_c,&local_c);
  }
  BVar3 = VirtualProtect(&DAT_00508c6a,5,0x40,&local_c);
  if (BVar3 != 0) {
    _DAT_00508c6a = uVar1;
    DAT_00508c6e = uVar2;
    VirtualProtect(&DAT_00508c6a,5,local_c,&local_c);
  }
  return;
}



/* VA 10002e30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10002e30(void)

{
  BOOL BVar1;
  DWORD local_4;

  BVar1 = VirtualProtect(&DAT_004a5496,5,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_004a5496 = 0x90909090;
    DAT_004a549a = 0x90;
    VirtualProtect(&DAT_004a5496,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b2a8,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b2a8 = ".\\gamedata\\simulation\\ai\\";
    VirtualProtect(&DAT_0065b2a8,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b2ac,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b2ac = ".\\gamedata\\simulation\\cardata\\";
    VirtualProtect(&DAT_0065b2ac,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b2b0,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b2b0 = ".\\gamedata\\simulation\\aicardata\\";
    VirtualProtect(&DAT_0065b2b0,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b2b8,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b2b8 = ".\\gamedata\\track\\";
    VirtualProtect(&DAT_0065b2b8,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b2e4,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b2e4 = ".\\gamedata\\track\\racer\\work\\";
    VirtualProtect(&DAT_0065b2e4,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b2f8,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b2f8 = ".\\gamedata\\track\\cops\\";
    VirtualProtect(&DAT_0065b2f8,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b300,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b300 = ".\\gamedata\\carmodel\\";
    VirtualProtect(&DAT_0065b300,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b304,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b304 = ".\\drivers\\";
    VirtualProtect(&DAT_0065b304,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b30c,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b30c = ".\\gamedata\\render\\";
    VirtualProtect(&DAT_0065b30c,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b310,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b310 = ".\\gamedata\\dashhud\\";
    VirtualProtect(&DAT_0065b310,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b314,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b314 = ".\\gamedata\\music\\";
    VirtualProtect(&DAT_0065b314,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b318,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b318 = ".\\gamedata\\sounds\\";
    VirtualProtect(&DAT_0065b318,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b31c,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b31c = ".\\gamedata\\speech\\";
    VirtualProtect(&DAT_0065b31c,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b32c,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b32c = ".\\fedata\\movies\\";
    VirtualProtect(&DAT_0065b32c,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b330,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b330 = ".\\fedata\\controls\\";
    VirtualProtect(&DAT_0065b330,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b334,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b334 = ".\\fedata\\art\\";
    VirtualProtect(&DAT_0065b334,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b338,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b338 = ".\\fedata\\showcase\\";
    VirtualProtect(&DAT_0065b338,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b33c,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b33c = ".\\fedata\\chron\\";
    VirtualProtect(&DAT_0065b33c,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b340,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b340 = ".\\fedata\\locale\\";
    VirtualProtect(&DAT_0065b340,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b344,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b344 = ".\\fedata\\layouts\\";
    VirtualProtect(&DAT_0065b344,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b348,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b348 = ".\\fedata\\data\\";
    VirtualProtect(&DAT_0065b348,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b34c,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b34c = ".\\fedata\\models\\";
    VirtualProtect(&DAT_0065b34c,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b350,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b350 = ".\\fedata\\trackart\\";
    VirtualProtect(&DAT_0065b350,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b354,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b354 = ".\\fedata\\factory\\";
    VirtualProtect(&DAT_0065b354,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0065b360,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0065b360 = ".\\savedata\\";
    VirtualProtect(&DAT_0065b360,4,local_4,&local_4);
  }
  return;
}



/* VA 10003390 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10003390(void)

{
  BOOL BVar1;
  DWORD local_4;

  BVar1 = VirtualProtect(&DAT_004603ff,1,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_004603ff = 0x90;
    VirtualProtect(&DAT_004603ff,1,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00460400,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_00460400 = 0xe8;
    _DAT_00460401 = 0xfba2f1b;
    VirtualProtect(&DAT_00460400,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00460525,1,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_00460525 = 0x90;
    VirtualProtect(&DAT_00460525,1,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00460526,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_00460526 = 0xe8;
    _DAT_00460527 = 0xfba2df5;
    VirtualProtect(&DAT_00460526,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00467d91,1,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_00467d91 = 0x90;
    VirtualProtect(&DAT_00467d91,1,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00467d92,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_00467d92 = 0xe8;
    _DAT_00467d93 = 0xfb9b589;
    VirtualProtect(&DAT_00467d92,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00556f9a,1,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_00556f9a = 0x90;
    VirtualProtect(&DAT_00556f9a,1,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00556f9b,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_00556f9b = 0xe8;
    _DAT_00556f9c = 0xfaac380;
    VirtualProtect(&DAT_00556f9b,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0046049a,6,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0046049a = 0x90909090;
    _DAT_0046049e = 0x9090;
    VirtualProtect(&DAT_0046049a,6,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_004604d9,6,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_004604d9 = 0x90909090;
    _DAT_004604dd = 0x9090;
    VirtualProtect(&DAT_004604d9,6,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0046059e,1,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_0046059e = 0xeb;
    VirtualProtect(&DAT_0046059e,1,local_4,&local_4);
  }
  return;
}



/* VA 100035e0 */

DWORD GetVersion(void)

{
                    /* 0x35e0  1  GetVersion */
  return 0x60001;
}



/* VA 10003840 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10003840(void)

{
  DWORD dwStyle;
  int iVar1;
  HWND hWnd;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iVar2;
  int iVar3;
  float10 fVar4;
  ulonglong uVar5;
  tagRECT local_7c;
  tagRECT local_6c;
  undefined4 local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  WINDOWPLACEMENT WStack_34;

  _DAT_10006130 = (float)DAT_1000611c / (float)DAT_10006120;
  if ((float)_DAT_10005600 < _DAT_10006130) {
    _DAT_10006134 = _DAT_005b2a88 * _DAT_10006130;
    _DAT_10006130 = _DAT_005b2a88;
    _CItan();
    fVar4 = (float10)_CIatan2();
    DAT_10006080 = (float)(fVar4 / (float10)_DAT_100055f8);
  }
  else {
    _DAT_10006130 = _DAT_005b2a8c / _DAT_10006130;
    _DAT_10006134 = _DAT_005b2a8c;
    DAT_10006080 = _DAT_005b3c9c;
  }
  if (_DAT_006b7c01 != 0) {
    return;
  }
  dwStyle = GetWindowLongA(_DAT_006b7bf8,-0x10);
  local_7c.left = 0;
  local_7c.top = 0;
  local_7c.right = 0xf0;
  uVar5 = FUN_10004470(extraout_ECX,extraout_EDX);
  local_7c.bottom = (LONG)uVar5;
  AdjustWindowRect(&local_7c,dwStyle,0);
  DAT_1000613c = local_7c.right - local_7c.left;
  DAT_10006138 = local_7c.bottom - local_7c.top;
  GetClientRect(_DAT_006b7bf8,&local_7c);
  if ((local_7c.right - local_7c.left == DAT_1000611c) &&
     (local_7c.bottom - local_7c.top == DAT_10006120)) {
    return;
  }
  local_7c.left = 0;
  local_7c.top = 0;
  local_7c.right = DAT_1000611c;
  local_7c.bottom = DAT_10006120;
  AdjustWindowRect(&local_7c,dwStyle,0);
  iVar2 = local_7c.right - local_7c.left;
  iVar3 = local_7c.bottom - local_7c.top;
  if ((DAT_10006124 != (code *)0x0) && (DAT_10006128 != (code *)0x0)) {
    local_5c = 0x28;
    local_58 = 0;
    local_54 = 0;
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    iVar1 = (*DAT_10006124)(_DAT_006b7bf8,2);
    if ((iVar1 != 0) && (iVar1 = (*DAT_10006128)(iVar1,&local_5c), iVar1 != 0)) {
      local_6c.left = local_58;
      local_6c.top = local_54;
      local_6c.right = local_50;
      local_6c.bottom = local_4c;
      goto LAB_10003a9d;
    }
  }
  hWnd = GetDesktopWindow();
  GetWindowRect(hWnd,&local_6c);
LAB_10003a9d:
  WStack_34.flags = 0;
  WStack_34.showCmd = 0;
  WStack_34.ptMinPosition.x = 0;
  local_7c.left = local_6c.left + ((local_6c.right - local_6c.left) - iVar2) / 2;
  WStack_34.ptMinPosition.y = 0;
  local_7c.right = local_7c.left + iVar2;
  local_7c.top = ((local_6c.bottom - local_6c.top) - iVar3) / 2 + local_6c.top;
  WStack_34.ptMaxPosition.x = 0;
  local_7c.bottom = local_7c.top + iVar3;
  WStack_34.ptMaxPosition.y = 0;
  WStack_34.rcNormalPosition.left = 0;
  WStack_34.rcNormalPosition.top = 0;
  WStack_34.rcNormalPosition.right = 0;
  WStack_34.rcNormalPosition.bottom = 0;
  WStack_34.length = 0x2c;
  DAT_10006140 = 0;
  GetWindowPlacement(_DAT_006b7bf8,&WStack_34);
  WStack_34.rcNormalPosition.left = local_7c.left;
  WStack_34.rcNormalPosition.top = local_7c.top;
  WStack_34.rcNormalPosition.right = local_7c.right;
  WStack_34.rcNormalPosition.bottom = local_7c.bottom;
  SetWindowPlacement(_DAT_006b7bf8,&WStack_34);
  return;
}



/* VA 10003c90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10003c90(void)

{
  BOOL BVar1;
  DWORD local_4;

  BVar1 = VirtualProtect(&DAT_00538b3f,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00538b3f = &PTR_LAB_10006078;
    VirtualProtect(&DAT_00538b3f,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00575c3c,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00575c3c = &PTR_LAB_10006078;
    VirtualProtect(&DAT_00575c3c,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00556c50,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00556c50 = &PTR_LAB_10006078;
    VirtualProtect(&DAT_00556c50,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00451824,2,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00451824 = 0x35d8;
    VirtualProtect(&DAT_00451824,2,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00451826,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00451826 = &DAT_10006134;
    VirtualProtect(&DAT_00451826,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0043a2df,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0043a2df = &DAT_10006134;
    VirtualProtect(&DAT_0043a2df,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00466fe7,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00466fe7 = &DAT_10006134;
    VirtualProtect(&DAT_00466fe7,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0046713a,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0046713a = &DAT_10006134;
    VirtualProtect(&DAT_0046713a,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00451834,2,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00451834 = 0x35d8;
    VirtualProtect(&DAT_00451834,2,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00451836,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00451836 = &DAT_10006130;
    VirtualProtect(&DAT_00451836,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00466ff4,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00466ff4 = &DAT_10006130;
    VirtualProtect(&DAT_00466ff4,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0046714a,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0046714a = &DAT_10006130;
    VirtualProtect(&DAT_0046714a,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0044ecb2,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0044ecb2 = &DAT_10006080;
    VirtualProtect(&DAT_0044ecb2,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0044f1b1,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0044f1b1 = &DAT_10006080;
    VirtualProtect(&DAT_0044f1b1,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00462bfc,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00462bfc = &DAT_10006080;
    VirtualProtect(&DAT_00462bfc,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00462c26,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00462c26 = &DAT_10006080;
    VirtualProtect(&DAT_00462c26,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00462cab,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00462cab = &DAT_10006080;
    VirtualProtect(&DAT_00462cab,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00462cc4,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00462cc4 = &DAT_10006080;
    VirtualProtect(&DAT_00462cc4,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00462dd7,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00462dd7 = &DAT_10006080;
    VirtualProtect(&DAT_00462dd7,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00462df0,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00462df0 = &DAT_10006080;
    VirtualProtect(&DAT_00462df0,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0046414b,1,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_0046414b = 0xa1;
    VirtualProtect(&DAT_0046414b,1,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0046414c,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_0046414c = &DAT_10006080;
    VirtualProtect(&DAT_0046414c,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_0046584f,1,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_0046584f = 0xa1;
    VirtualProtect(&DAT_0046584f,1,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00465850,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00465850 = &DAT_10006080;
    VirtualProtect(&DAT_00465850,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00465ae8,1,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_00465ae8 = 0xa1;
    VirtualProtect(&DAT_00465ae8,1,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00465ae9,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00465ae9 = &DAT_10006080;
    VirtualProtect(&DAT_00465ae9,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00462b80,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_00462b80 = 0xe9;
    _DAT_00462b81 = 0xfba106b;
    VirtualProtect(&DAT_00462b80,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_004692e2,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_004692e2 = 0xe9;
    _DAT_004692e3 = 0xfb9a929;
    VirtualProtect(&DAT_004692e2,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_004e8b7f,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_004e8b7f = 0xe9;
    _DAT_004e8b80 = 0xfb1b0ac;
    VirtualProtect(&DAT_004e8b7f,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_004e9900,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_004e9900 = 0xe9;
    _DAT_004e9901 = 0xfb1a34b;
    VirtualProtect(&DAT_004e9900,5,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_004e9baa,5,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_004e9baa = 0xe9;
    _DAT_004e9bab = 0xfb1a0c1;
    VirtualProtect(&DAT_004e9baa,5,local_4,&local_4);
  }
  return;
}



/* VA 100042d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100042d0(void)

{
  BOOL BVar1;
  DWORD local_4;

  BVar1 = VirtualProtect(&DAT_005dea90,2,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_005dea90 = 0x65;
    VirtualProtect(&DAT_005dea90,2,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00534377,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00534377 = &PTR_LAB_10006088;
    VirtualProtect(&DAT_00534377,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00535525,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00535525 = &PTR_LAB_10006088;
    VirtualProtect(&DAT_00535525,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00570d72,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00570d72 = &PTR_LAB_10006088;
    VirtualProtect(&DAT_00570d72,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00467c70,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00467c70 = &PTR_LAB_10006084;
    VirtualProtect(&DAT_00467c70,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_00556e76,4,0x40,&local_4);
  if (BVar1 != 0) {
    _DAT_00556e76 = &PTR_LAB_10006084;
    VirtualProtect(&DAT_00556e76,4,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_004dd6cf,1,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_004dd6cf = 0x50;
    VirtualProtect(&DAT_004dd6cf,1,local_4,&local_4);
  }
  BVar1 = VirtualProtect(&DAT_004dd57a,1,0x40,&local_4);
  if (BVar1 != 0) {
    DAT_004dd57a = 0x50;
    VirtualProtect(&DAT_004dd57a,1,local_4,&local_4);
  }
  return;
}



/* VA 10004456 */

void _CIatan2(void)

{
                    /* WARNING: Could not recover jumptable at 0x10004456. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _CIatan2();
  return;
}



/* VA 1000445c */

void _CItan(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000445c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _CItan();
  return;
}



/* VA 10004470 */

ulonglong __fastcall FUN_10004470(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  uint uVar2;
  float10 in_ST0;
  uint local_20;
  int iStack_1c;
  int iStack_14;

  if (DAT_10006148 == 0) {
    uVar1 = (ulonglong)ROUND(in_ST0);
    iStack_14 = (int)((ulonglong)(double)in_ST0 >> 0x20);
    local_20 = (uint)uVar1;
    iStack_1c = (int)(uVar1 >> 0x20);
    if ((local_20 != 0) || (iStack_14 = iStack_1c, (uVar1 & 0x7fffffff00000000) != 0)) {
      if (iStack_14 < 0) {
        uVar1 = uVar1 + (0x80000000 < (uint)-(float)(in_ST0 - (float10)(longlong)uVar1));
      }
      else {
        uVar2 = (uint)(0x80000000 < (uint)(float)(in_ST0 - (float10)(longlong)uVar1));
        uVar1 = CONCAT44(iStack_1c - (uint)(local_20 < uVar2),local_20 - uVar2);
      }
    }
    return uVar1;
  }
  return CONCAT44(param_2,(int)in_ST0);
}
