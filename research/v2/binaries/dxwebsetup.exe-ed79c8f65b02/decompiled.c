/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 ed79c8f65b02ed83d5db8c355328294a73dc447f08f657312bf8f3a5b40c7494 */

/* VA 010015f6 */

undefined4 FUN_010015f6(undefined4 *param_1)

{
  FARPROC pFVar1;
  BOOL BVar2;
  _SID_IDENTIFIER_AUTHORITY local_18;
  HMODULE local_10;
  undefined4 local_c;
  PSID local_8;

  local_c = 0;
  local_18.Value[0] = '\0';
  local_18.Value[1] = '\0';
  local_18.Value[2] = '\0';
  local_18.Value[3] = '\0';
  local_18.Value[4] = '\0';
  local_18.Value[5] = '\x05';
  local_10 = LoadLibraryA("advapi32.dll");
  if (local_10 != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(local_10,"CheckTokenMembership");
    if (pFVar1 != (FARPROC)0x0) {
      local_c = 1;
      *param_1 = 0;
      BVar2 = AllocateAndInitializeSid(&local_18,'\x02',0x20,0x220,0,0,0,0,0,0,&local_8);
      if (BVar2 != 0) {
        (*pFVar1)(0,local_8,param_1);
        FreeSid(local_8);
      }
    }
    FreeLibrary(local_10);
  }
  return local_c;
}



/* VA 0100168b */

int FUN_0100168b(void)

{
  int iVar1;
  HANDLE ProcessHandle;
  BOOL BVar2;
  uint *TokenInformation;
  uint uVar3;
  uint *puVar4;
  DWORD DVar5;
  HANDLE *TokenHandle;
  _SID_IDENTIFIER_AUTHORITY local_1c;
  PSID local_14;
  HANDLE local_10;
  SIZE_T local_c;
  int local_8;

  uVar3 = 0;
  local_1c.Value[0] = '\0';
  local_1c.Value[1] = '\0';
  local_1c.Value[2] = '\0';
  local_1c.Value[3] = '\0';
  local_1c.Value[4] = '\0';
  local_1c.Value[5] = '\x05';
  local_8 = 0;
  iVar1 = DAT_0100a1f4;
  if (DAT_0100a1f4 == 2) {
    iVar1 = FUN_010015f6(&local_8);
    if (iVar1 == 0) {
      TokenHandle = &local_10;
      DVar5 = 8;
      ProcessHandle = GetCurrentProcess();
      BVar2 = OpenProcessToken(ProcessHandle,DVar5,TokenHandle);
      iVar1 = 0;
      if (BVar2 != 0) {
        BVar2 = GetTokenInformation(local_10,TokenGroups,(LPVOID)0x0,0,&local_c);
        if (((BVar2 == 0) && (DVar5 = GetLastError(), DVar5 == 0x7a)) &&
           (TokenInformation = LocalAlloc(0,local_c), TokenInformation != (uint *)0x0)) {
          BVar2 = GetTokenInformation(local_10,TokenGroups,TokenInformation,local_c,&local_c);
          if ((BVar2 != 0) &&
             (BVar2 = AllocateAndInitializeSid(&local_1c,'\x02',0x20,0x220,0,0,0,0,0,0,&local_14),
             BVar2 != 0)) {
            if (*TokenInformation != 0) {
              puVar4 = TokenInformation + 1;
              do {
                BVar2 = EqualSid((PSID)*puVar4,local_14);
                if (BVar2 != 0) {
                  DAT_0100a1f4 = 1;
                  local_8 = 1;
                  break;
                }
                uVar3 = uVar3 + 1;
                puVar4 = puVar4 + 2;
              } while (uVar3 < *TokenInformation);
            }
            FreeSid(local_14);
          }
          LocalFree(TokenInformation);
        }
        CloseHandle(local_10);
        iVar1 = local_8;
      }
    }
    else {
      iVar1 = local_8;
      if (local_8 != 0) {
        DAT_0100a1f4 = 1;
      }
    }
  }
  return iVar1;
}



/* VA 010017b1 */

undefined4 FUN_010017b1(HWND param_1,int param_2,uint param_3,UINT param_4)

{
  HWND pHVar1;
  CHAR local_204 [512];

  if (param_2 == 0x110) {
    pHVar1 = GetDesktopWindow();
    FUN_01002969(param_1,pHVar1);
    local_204[0] = '\0';
    LoadStringA(DAT_0100b4a4,param_4,local_204,0x200);
    SetDlgItemTextA(param_1,0x83f,local_204);
    MessageBeep(0xffffffff);
  }
  else {
    if (((param_2 != 0x111) || (param_3 < 0x83d)) || (0x83e < param_3)) {
      return 0;
    }
    EndDialog(param_1,param_3);
  }
  return 1;
}



/* VA 01001840 */

char * FUN_01001840(undefined4 *param_1,short *param_2)

{
  char cVar1;
  short *psVar2;
  char *pcVar3;
  int iVar4;

  pcVar3 = (char *)*param_1;
  iVar4 = 0;
  while( true ) {
    psVar2 = FUN_01005b00(param_2,(short)*pcVar3);
    if (psVar2 == (short *)0x0) {
      *param_1 = pcVar3;
      cVar1 = *pcVar3;
      while ((psVar2 = FUN_01005b00(param_2,(short)cVar1), psVar2 == (short *)0x0 &&
             (pcVar3[iVar4] != '\0'))) {
        iVar4 = iVar4 + 1;
        cVar1 = pcVar3[iVar4];
      }
      pcVar3 = pcVar3 + iVar4;
      if (*pcVar3 != '\0') {
        *pcVar3 = '\0';
        pcVar3 = pcVar3 + 1;
      }
      return pcVar3;
    }
    if (*pcVar3 == '\0') break;
    pcVar3 = pcVar3 + 1;
  }
  return (char *)0x0;
}



/* VA 0100189e */

void FUN_0100189e(void)

{
  FUN_010038cc((HWND)0x0,0x521,"",(LPCSTR)0x0,0x40,0);
  return;
}



/* VA 010018b5 */

undefined4 FUN_010018b5(void)

{
  HANDLE ProcessHandle;
  BOOL BVar1;
  UINT UVar2;
  DWORD DesiredAccess;
  HANDLE *TokenHandle;
  _TOKEN_PRIVILEGES local_18;
  HANDLE local_8;

  TokenHandle = &local_8;
  DesiredAccess = 0x28;
  ProcessHandle = GetCurrentProcess();
  BVar1 = OpenProcessToken(ProcessHandle,DesiredAccess,TokenHandle);
  if (BVar1 == 0) {
    UVar2 = 0x4f5;
  }
  else {
    LookupPrivilegeValueA((LPCSTR)0x0,"SeShutdownPrivilege",&local_18.Privileges[0].Luid);
    local_18.PrivilegeCount = 1;
    local_18.Privileges[0].Attributes = 2;
    BVar1 = AdjustTokenPrivileges(local_8,0,&local_18,0,(PTOKEN_PRIVILEGES)0x0,(PDWORD)0x0);
    if (BVar1 == 0) {
      UVar2 = 0x4f6;
    }
    else {
      BVar1 = ExitWindowsEx(2,0);
      if (BVar1 != 0) {
        return 1;
      }
      UVar2 = 0x4f7;
    }
  }
  FUN_010038cc((HWND)0x0,UVar2,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
  return 0;
}



/* VA 01001946 */

void FUN_01001946(void)

{
  LSTATUS LVar1;
  HKEY local_8;

  if (DAT_0100a2e0 != '\0') {
    LVar1 = RegOpenKeyExA((HKEY)0x80000002,s_Software_Microsoft_Windows_Curre_0100a0c4,0,0x20006,
                          &local_8);
    if (LVar1 == 0) {
      RegDeleteValueA(local_8,&DAT_0100a2e0);
      RegCloseKey(local_8);
    }
  }
  return;
}



/* VA 0100198b */

void FUN_0100198b(void)

{
  LSTATUS LVar1;
  FARPROC pFVar2;
  UINT UVar3;
  int iVar4;
  BYTE *lpData;
  DWORD DVar5;
  char *pcVar6;
  int iVar7;
  undefined4 *puVar8;
  CHAR local_220;
  undefined4 local_21f;
  CHAR local_11c;
  undefined4 local_11b;
  DWORD local_18;
  DWORD local_14;
  uint local_10;
  HKEY local_c;
  HMODULE local_8;

  local_11c = '\0';
  local_220 = '\0';
  puVar8 = &local_11b;
  for (iVar7 = 0x40; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)puVar8 = 0;
  *(undefined1 *)((int)puVar8 + 2) = 0;
  puVar8 = &local_21f;
  for (iVar7 = 0x40; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)puVar8 = 0;
  *(undefined1 *)((int)puVar8 + 2) = 0;
  local_10 = 0;
  LVar1 = RegCreateKeyExA((HKEY)0x80000002,s_Software_Microsoft_Windows_Curre_0100a0c4,0,(LPSTR)0x0,
                          0,0x2001f,(LPSECURITY_ATTRIBUTES)0x0,&local_c,&local_14);
  if (LVar1 != 0) {
    return;
  }
  local_8 = (HMODULE)0x0;
  do {
    wsprintfA(&DAT_0100a2e0,s_wextract_cleanup_d_0100a190,local_8);
    LVar1 = RegQueryValueExA(local_c,&DAT_0100a2e0,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,&local_18);
    if (LVar1 != 0) break;
    local_8 = (HMODULE)((int)local_8 + 1);
  } while ((int)local_8 < 200);
  if (local_8 == (HMODULE)0xc8) {
    RegCloseKey(local_c);
    DAT_0100a2e0 = 0;
    return;
  }
  GetSystemDirectoryA(&local_220,0x104);
  FUN_01005b32(&local_220,"advpack.dll");
  local_8 = LoadLibraryA(&local_220);
  if (local_8 == (HMODULE)0x0) {
LAB_01001b0b:
    DVar5 = GetModuleFileNameA(DAT_0100b4a4,&local_11c,0x104);
    if (DVar5 == 0) goto LAB_01001b23;
  }
  else {
    pFVar2 = GetProcAddress(local_8,"DelNodeRunDLL32");
    local_10 = (uint)(pFVar2 != (FARPROC)0x0);
    FreeLibrary(local_8);
    if ((pFVar2 != (FARPROC)0x0) == 0) goto LAB_01001b0b;
    UVar3 = GetSystemDirectoryA(&local_11c,0x104);
    if (UVar3 != 0) {
      FUN_01005b32(&local_11c,"");
    }
  }
  iVar7 = lstrlenA(&DAT_0100ac44);
  iVar4 = lstrlenA(&local_11c);
  lpData = LocalAlloc(0x40,iVar7 + 0x50 + iVar4);
  if (lpData != (BYTE *)0x0) {
    DAT_0100a330 = (uint)(local_10 == 0);
    pcVar6 = s_rundll32_exe__sadvpack_dll_DelNo_0100a1b0;
    if (local_10 == 0) {
      pcVar6 = s__s__D__s_0100a1a4;
    }
    wsprintfA((LPSTR)lpData,pcVar6,&local_11c,&DAT_0100ac44);
    iVar7 = lstrlenA((LPCSTR)lpData);
    RegSetValueExA(local_c,&DAT_0100a2e0,0,1,lpData,iVar7 + 1);
    RegCloseKey(local_c);
    LocalFree(lpData);
    return;
  }
  FUN_010038cc((HWND)0x0,0x4b5,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
LAB_01001b23:
  RegCloseKey(local_c);
  return;
}



/* VA 01001b8b */

void FUN_01001b8b(void)

{
  LSTATUS LVar1;
  UINT UVar2;
  int iVar3;
  undefined4 *puVar4;
  BYTE local_348 [568];
  CHAR local_110;
  undefined4 local_10f;
  DWORD local_c;
  HKEY local_8;

  if (DAT_0100a2e0 != '\0') {
    LVar1 = RegOpenKeyExA((HKEY)0x80000002,s_Software_Microsoft_Windows_Curre_0100a0c4,0,0x2001f,
                          &local_8);
    if (LVar1 == 0) {
      local_c = 0x238;
      LVar1 = RegQueryValueExA(local_8,&DAT_0100a2e0,(LPDWORD)0x0,(LPDWORD)0x0,local_348,&local_c);
      if (LVar1 == 0) {
        local_110 = '\0';
        puVar4 = &local_10f;
        for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        *(undefined2 *)puVar4 = 0;
        *(undefined1 *)((int)puVar4 + 2) = 0;
        UVar2 = GetSystemDirectoryA(&local_110,0x104);
        if (UVar2 != 0) {
          FUN_01005b32(&local_110,"");
        }
        wsprintfA((LPSTR)local_348,s_rundll32_exe__sadvpack_dll_DelNo_0100a1b0,&local_110,
                  &DAT_0100ac44);
        iVar3 = lstrlenA((LPCSTR)local_348);
        RegSetValueExA(local_8,&DAT_0100a2e0,0,1,local_348,iVar3 + 1);
      }
      RegCloseKey(local_8);
    }
  }
  return;
}



/* VA 01001c7f */

void FUN_01001c7f(LPCSTR param_1)

{
  HANDLE hFindFile;
  int iVar1;
  BOOL BVar2;
  _WIN32_FIND_DATAA local_248;
  CHAR local_108 [260];

  if ((param_1 != (LPCSTR)0x0) && (*param_1 != '\0')) {
    lstrcpyA(local_108,param_1);
    lstrcatA(local_108,"*");
    hFindFile = FindFirstFileA(local_108,&local_248);
    if (hFindFile != (HANDLE)0xffffffff) {
      do {
        lstrcpyA(local_108,param_1);
        if (((byte)local_248.dwFileAttributes & 0x10) == 0) {
          lstrcatA(local_108,local_248.cFileName);
          SetFileAttributesA(local_108,0x80);
          DeleteFileA(local_108);
        }
        else {
          iVar1 = lstrcmpA(local_248.cFileName,".");
          if ((iVar1 != 0) && (iVar1 = lstrcmpA(local_248.cFileName,".."), iVar1 != 0)) {
            lstrcatA(local_108,local_248.cFileName);
            FUN_01005b32(local_108,"");
            FUN_01001c7f(local_108);
          }
        }
        BVar2 = FindNextFileA(hFindFile,&local_248);
      } while (BVar2 != 0);
      FindClose(hFindFile);
      RemoveDirectoryA(param_1);
    }
  }
  return;
}



/* VA 01001da9 */

undefined4 FUN_01001da9(LPCSTR param_1)

{
  int iVar1;

  if (((param_1 != (LPCSTR)0x0) && (iVar1 = lstrlenA(param_1), 2 < iVar1)) &&
     (((param_1[1] == ':' && (param_1[2] == '\\')) || ((*param_1 == '\\' && (param_1[1] == '\\')))))
     ) {
    return 1;
  }
  return 0;
}



/* VA 01001ddf */

LONG FUN_01001ddf(void)

{
  UINT UVar1;
  HFILE hFile;
  LONG LVar2;
  CHAR local_108 [260];

  LVar2 = 0;
  UVar1 = GetWindowsDirectoryA(local_108,0x104);
  if (UVar1 != 0) {
    FUN_01005b32(local_108,"wininit.ini");
    WritePrivateProfileStringA((LPCSTR)0x0,(LPCSTR)0x0,(LPCSTR)0x0,local_108);
    hFile = _lopen(local_108,0x40);
    if (hFile != -1) {
      LVar2 = _llseek(hFile,0,2);
      _lclose(hFile);
    }
  }
  return LVar2;
}



/* VA 01001e52 */

DWORD FUN_01001e52(HKEY param_1,LPCSTR param_2)

{
  LSTATUS LVar1;
  DWORD local_8;

  local_8 = 0;
  LVar1 = RegOpenKeyExA((HKEY)0x80000002,(LPCSTR)param_1,0,0x20019,&param_1);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExA(param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,&local_8);
    if (LVar1 != 0) {
      local_8 = 0;
    }
    RegCloseKey(param_1);
  }
  return local_8;
}



/* VA 01001ea3 */

DWORD FUN_01001ea3(HKEY param_1)

{
  LSTATUS LVar1;
  DWORD local_8;

  local_8 = 0;
  LVar1 = RegOpenKeyExA((HKEY)0x80000002,(LPCSTR)param_1,0,0x20019,&param_1);
  if (LVar1 == 0) {
    LVar1 = RegQueryInfoKeyA(param_1,(LPSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                             (LPDWORD)0x0,&local_8,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                             (PFILETIME)0x0);
    if (LVar1 != 0) {
      local_8 = 0;
    }
    RegCloseKey(param_1);
  }
  return local_8;
}



/* VA 01001ef8 */

DWORD FUN_01001ef8(ushort param_1)

{
  DWORD DVar1;

  DVar1 = 0;
  if (param_1 == 0) {
    DVar1 = FUN_01001ddf();
  }
  else if (param_1 == 1) {
    DVar1 = FUN_01001ea3((HKEY)s_System_CurrentControlSet_Control_0100a148);
  }
  else if ((1 < param_1) && (param_1 < 4)) {
    DVar1 = FUN_01001e52((HKEY)s_System_CurrentControlSet_Control_0100a0f8,
                         s_PendingFileRenameOperations_0100a12c);
  }
  return DVar1;
}



/* VA 01001f34 */

bool FUN_01001f34(DWORD param_1,ushort param_2)

{
  DWORD DVar1;

  DVar1 = FUN_01001ef8(param_2);
  return param_1 != DVar1;
}



/* VA 01001f4b */

uint FUN_01001f4b(LPCSTR param_1)

{
  DWORD DVar1;
  uint uVar2;

  DVar1 = GetFileAttributesA(param_1);
  if (DVar1 == 0xffffffff) {
    uVar2 = CreateDirectoryA(param_1,(LPSECURITY_ATTRIBUTES)0x0);
  }
  else {
    uVar2 = DVar1 & 0x10;
  }
  return uVar2;
}



/* VA 01001f6e */

bool FUN_01001f6e(char *param_1)

{
  UINT UVar1;
  char local_108 [260];

  UVar1 = GetWindowsDirectoryA(local_108,0x104);
  if (UVar1 == 0) {
    FUN_010038cc((HWND)0x0,0x4f0,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
  }
  return *param_1 == local_108[0];
}



/* VA 01001fb1 */

LPSTR FUN_01001fb1(undefined4 param_1,LPSTR param_2)

{
  wsprintfA(param_2,"%lu",param_1);
  return param_2;
}



/* VA 01001fce */

bool FUN_01001fce(int param_1,int param_2,int param_3,LPCSTR param_4)

{
  LPSTR pCVar1;
  int iVar2;
  char cVar3;
  LPCSTR pCVar4;
  uint uVar5;
  uint uVar6;
  CHAR local_10 [12];

  cVar3 = '\0';
  DAT_0100aa5c = 0x70;
  if (param_1 == 1) {
    uVar6 = 0;
    uVar5 = 0x10;
    pCVar4 = (LPCSTR)0x0;
    pCVar1 = FUN_01001fb1(param_2 + param_3,local_10);
    FUN_010038cc((HWND)0x0,0x4fa,pCVar1,pCVar4,uVar5,uVar6);
  }
  else if (param_1 == 4) {
    uVar6 = 5;
    uVar5 = 0x20;
    pCVar4 = (LPCSTR)0x0;
    pCVar1 = FUN_01001fb1(param_2 + param_3,local_10);
    iVar2 = FUN_010038cc((HWND)0x0,0x4bd,pCVar1,pCVar4,uVar5,uVar6);
    cVar3 = '\x01' - (iVar2 != 4);
  }
  else if (param_1 == 2) {
    uVar6 = 0x104;
    uVar5 = 0x40;
    pCVar1 = FUN_01001fb1(param_3,local_10);
    iVar2 = FUN_010038cc((HWND)0x0,0x4cc,pCVar1,param_4,uVar5,uVar6);
    if (iVar2 == 6) {
      cVar3 = '\x01';
      DAT_0100aa5c = 0;
    }
  }
  return (bool)cVar3;
}



/* VA 01002081 */

undefined4 FUN_01002081(LPBYTE param_1,UINT param_2,HKEY param_3)

{
  LPSTR pCVar1;
  LPSTR lpsz;
  HKEY pHVar2;
  LSTATUS LVar3;
  DWORD DVar4;
  LPCSTR lpsz_00;
  CHAR local_110 [260];
  DWORD local_c;
  int local_8;

  local_8 = 0;
  *param_1 = '\0';
  pHVar2 = param_3;
  if ((char)param_3->unused == '#') {
    lpsz_00 = (LPCSTR)((int)&param_3->unused + 1);
    pCVar1 = CharUpperA((LPSTR)(int)*lpsz_00);
    lpsz = CharNextA(lpsz_00);
    pHVar2 = (HKEY)CharNextA(lpsz);
    if ((char)pCVar1 == 'S') goto LAB_01002198;
    if ((char)pCVar1 == 'W') {
      GetWindowsDirectoryA((LPSTR)param_1,param_2);
      goto LAB_010021a4;
    }
    local_c = 0x104;
    lstrcpyA(local_110,"Software\\Microsoft\\Windows\\CurrentVersion\\App Paths");
    FUN_01005b32(local_110,(LPCSTR)pHVar2);
    LVar3 = RegOpenKeyExA((HKEY)0x80000002,local_110,0,0x20019,&param_3);
    if (LVar3 != 0) goto LAB_010021a4;
    LVar3 = RegQueryValueExA(param_3,"",(LPDWORD)0x0,&param_2,param_1,&local_c);
    if (LVar3 == 0) {
      if ((param_2 == 2) &&
         (DVar4 = ExpandEnvironmentStringsA((LPCSTR)param_1,local_110,0x104), DVar4 != 0)) {
        lstrcpyA((LPSTR)param_1,local_110);
      }
      else if (param_2 != 1) goto LAB_01002173;
      local_8 = 1;
    }
LAB_01002173:
    RegCloseKey(param_3);
  }
  else {
LAB_01002198:
    GetSystemDirectoryA((LPSTR)param_1,param_2);
  }
  if (local_8 != 0) {
    return 1;
  }
LAB_010021a4:
  FUN_01005b32((LPCSTR)param_1,(LPCSTR)pHVar2);
  return 1;
}



/* VA 010021b7 */

uint FUN_010021b7(uint param_1)

{
  uint uVar1;

  if ((param_1 & 1) == 0) {
    uVar1 = -(uint)((param_1 & 2) != 0) & 0x101;
  }
  else {
    uVar1 = 0x104;
  }
  return uVar1;
}



/* VA 010021d4 */

uint FUN_010021d4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  if (param_3 <= param_1) {
    if (param_3 < param_1) {
      return 1;
    }
    if (param_4 <= param_2) {
      return (uint)(param_4 < param_2);
    }
  }
  return 0xffffffff;
}



/* VA 010021fb */

void FUN_010021fb(BYTE *param_1,BYTE *param_2)

{
  BYTE TestChar;
  BOOL BVar1;
  LPSTR pCVar2;
  int iVar3;
  CHAR local_104 [260];

  *param_2 = '\0';
  if ((param_1 != (BYTE *)0x0) && (*param_1 != '\0')) {
    GetModuleFileNameA(DAT_0100b4a4,local_104,0x104);
    TestChar = *param_1;
    while (TestChar != '\0') {
      BVar1 = IsDBCSLeadByte(TestChar);
      *param_2 = *param_1;
      if (BVar1 != 0) {
        param_2[1] = param_1[1];
      }
      if (*param_1 == '#') {
        param_1 = (BYTE *)CharNextA((LPCSTR)param_1);
        pCVar2 = CharUpperA((LPSTR)(int)(char)*param_1);
        if ((char)pCVar2 == 'D') {
          FUN_01005b71(local_104);
          iVar3 = lstrlenA(local_104);
          pCVar2 = CharPrevA(local_104,local_104 + iVar3);
          if ((pCVar2 != (LPSTR)0x0) && (*pCVar2 == '\\')) {
            *pCVar2 = '\0';
          }
        }
        else {
          pCVar2 = CharUpperA((LPSTR)(int)(char)*param_1);
          if ((char)pCVar2 != 'E') {
            if (*param_1 == '#') goto LAB_010022db;
            goto LAB_010022e0;
          }
        }
        lstrcpyA((LPSTR)param_2,local_104);
        iVar3 = lstrlenA(local_104);
        param_2 = param_2 + iVar3;
      }
      else {
LAB_010022db:
        param_2 = (BYTE *)CharNextA((LPCSTR)param_2);
      }
LAB_010022e0:
      param_1 = (BYTE *)CharNextA((LPCSTR)param_1);
      TestChar = *param_1;
    }
    *param_2 = '\0';
  }
  return;
}



/* VA 010022ff */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_010022ff(short *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  short *lpString1;
  uint uVar2;
  char *pcVar3;
  DWORD DVar4;
  int iVar5;
  code *pcVar6;
  char *lpString2;
  UINT UVar7;
  CHAR *pCVar8;
  short *psVar9;
  BYTE local_614 [1024];
  undefined1 local_214 [260];
  CHAR local_110 [260];
  short *local_c;
  short *local_8;

  pcVar6 = lstrcpyA_exref;
  lstrcpyA(local_214,(LPCSTR)param_1);
  if (local_214[0] == '\"') {
    local_8 = (short *)(local_214 + 1);
    psVar9 = (short *)&DAT_01001328;
  }
  else {
    local_8 = (short *)local_214;
    psVar9 = (short *)&DAT_01001324;
  }
  local_c = (short *)FUN_01001840(&local_8,psVar9);
  psVar9 = local_8;
  iVar1 = FUN_01001da9((LPCSTR)local_8);
  if (iVar1 == 0) {
    lstrcpyA(local_110,&DAT_0100ac44);
    FUN_01005b32(local_110,(LPCSTR)psVar9);
  }
  else {
    lstrcpyA(local_110,(LPCSTR)psVar9);
  }
  lpString1 = FUN_01005be8(psVar9,0x2e);
  if ((lpString1 == (short *)0x0) || (iVar1 = lstrcmpiA((LPCSTR)lpString1,".INF"), iVar1 != 0)) {
    psVar9 = FUN_01005be8(psVar9,0x2e);
    if ((psVar9 == (short *)0x0) || (iVar1 = lstrcmpiA((LPCSTR)psVar9,".BAT"), iVar1 != 0)) {
      local_8 = LocalAlloc(0x40,0x400);
      if (local_8 == (short *)0x0) {
        pCVar8 = (LPCSTR)0x0;
        UVar7 = 0x4b5;
        local_8 = (short *)0x0;
        goto LAB_01002594;
      }
      DVar4 = GetFileAttributesA(local_110);
      if ((DVar4 == 0xffffffff) || ((DVar4 & 0x10) != 0)) {
LAB_010025e9:
        (*pcVar6)(local_614,param_1);
      }
      else {
        lstrcpyA((LPSTR)local_614,local_110);
        param_1 = local_c;
        pcVar6 = lstrcatA_exref;
        if ((local_c != (short *)0x0) && ((char)*local_c != '\0')) {
          lstrcatA((LPSTR)local_614," ");
          goto LAB_010025e9;
        }
      }
      FUN_010021fb(local_614,(BYTE *)local_8);
LAB_01002601:
      *param_2 = local_8;
      return 1;
    }
    iVar1 = lstrlenA(s_Command_com__c__s_0100a1e0);
    iVar5 = lstrlenA(local_110);
    local_8 = LocalAlloc(0x40,iVar1 + 8 + iVar5);
    if (local_8 != (short *)0x0) {
      wsprintfA((LPSTR)local_8,s_Command_com__c__s_0100a1e0,local_110);
      goto LAB_01002601;
    }
  }
  else {
    uVar2 = FUN_01005bca(local_110);
    if (uVar2 == 0) {
      pCVar8 = local_110;
      UVar7 = 0x525;
      goto LAB_01002594;
    }
    local_8 = local_c;
    psVar9 = (short *)FUN_01001840(&local_8,(short *)&DAT_01001318);
    lstrlenA(s_DefaultInstall_0100a0a4);
    lpString2 = (char *)local_8;
    if (psVar9 != (short *)0x0) {
      if ((char)*psVar9 != '\0') {
        local_8 = psVar9;
      }
      FUN_01001840(&local_8,(short *)&DAT_01001314);
      lpString2 = (char *)local_8;
      if ((char)*local_8 != '\0') {
        lstrlenA((LPCSTR)local_8);
      }
    }
    local_8 = LocalAlloc(0x40,0x200);
    if (local_8 != (short *)0x0) {
      pcVar3 = lpString2;
      if ((char)*(short *)lpString2 == '\0') {
        pcVar3 = s_DefaultInstall_0100a0a4;
      }
      DAT_0100aa60 = GetPrivateProfileIntA(pcVar3,"Reboot",0,local_110);
      *param_3 = 1;
      DVar4 = GetPrivateProfileStringA("Version","AdvancedINF","",(LPSTR)local_8,8,local_110);
      if (DVar4 == 0) {
        _DAT_0100b494 = _DAT_0100b494 & 0xfffffffb;
        if (DAT_0100aa64 == 0) {
          pcVar3 = "setupx.dll";
          GetShortPathNameA(local_110,local_110,0x104);
        }
        else {
          pcVar3 = "setupapi.dll";
        }
        if ((char)*(short *)lpString2 == '\0') {
          lpString2 = s_DefaultInstall_0100a0a4;
        }
        wsprintfA((LPSTR)local_8,s_rundll32_exe__s_InstallHinfSecti_0100a014,pcVar3,lpString2,
                  local_110);
      }
      else {
        _DAT_0100b494 = _DAT_0100b494 | 4;
        if ((char)*(short *)lpString2 == '\0') {
          lpString2 = s_DefaultInstall_0100a0a4;
        }
        lstrcpyA((LPSTR)param_1,lpString2);
        lstrcpyA((LPSTR)local_8,local_110);
      }
      goto LAB_01002601;
    }
  }
  pCVar8 = (LPCSTR)0x0;
  UVar7 = 0x4b5;
LAB_01002594:
  FUN_010038cc((HWND)0x0,UVar7,pCVar8,(LPCSTR)0x0,0x10,0);
  return 0;
}



/* VA 01002613 */

undefined4 FUN_01002613(void)

{
  bool bVar1;
  undefined3 extraout_var;

  if ((DAT_0100aa60 == 0) &&
     (bVar1 = FUN_01001f34(DAT_0100ab84,DAT_0100aa64), CONCAT31(extraout_var,bVar1) == 0)) {
    return 0xffffffff;
  }
  return 2;
}



/* VA 0100263f */

void FUN_0100263f(byte param_1)

{
  int iVar1;

  if (((param_1 & 2) == 0) && (iVar1 = FUN_01002613(), iVar1 != 2)) {
    return;
  }
  if (((param_1 & 4) == 0) &&
     (iVar1 = FUN_010038cc((HWND)0x0,0x522,"",(LPCSTR)0x0,0x40,4), iVar1 != 6)) {
    return;
  }
  if (DAT_0100aa64 == 0) {
    ExitWindowsEx(2,0);
  }
  else {
    FUN_010018b5();
  }
  return;
}



/* VA 01002691 */

undefined4 FUN_01002691(int param_1,LPBYTE param_2,UINT param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  LPVOID lpData;
  BOOL BVar4;
  uint uVar5;
  uint uVar6;
  uint *extraout_ECX;
  int extraout_ECX_00;
  int *piVar7;
  int extraout_EDX;
  int extraout_EDX_00;
  uint local_34 [4];
  LPVOID local_24;
  uint local_20;
  DWORD local_1c;
  DWORD local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  HGLOBAL local_8;

  local_8 = (HGLOBAL)0x0;
  local_14 = 0;
  local_c = 0;
  if (0 < *(int *)(param_1 + 0x7c)) {
    local_10 = 0;
    do {
      piVar7 = (int *)(local_10 + param_1 + 0x84 + *(int *)(param_1 + 0x80));
      iVar3 = FUN_01002081(param_2,param_3,(HKEY)(piVar7[0xe] + 0x84 + param_1));
      if (iVar3 == 0) goto LAB_010027d7;
      local_18 = GetFileVersionInfoSizeA((LPCSTR)param_2,&local_1c);
      if (local_18 == 0) {
        if ((*piVar7 != 0) || (piVar7[1] != 0)) goto LAB_010027d7;
      }
      else {
        local_8 = GlobalAlloc(0x42,local_18);
        if ((local_8 == (HGLOBAL)0x0) || (lpData = GlobalLock(local_8), lpData == (LPVOID)0x0))
        goto LAB_010027d7;
        BVar4 = GetFileVersionInfoA((LPCSTR)param_2,local_1c,local_18,lpData);
        if (((BVar4 != 0) && (BVar4 = VerQueryValueA(lpData,"\\",&local_24,&local_20), BVar4 != 0))
           && (local_20 != 0)) {
          uVar1 = *(uint *)((int)local_24 + 0xc);
          uVar2 = *(uint *)((int)local_24 + 8);
          piVar7 = piVar7 + 4;
          do {
            uVar5 = FUN_010021d4(uVar2,uVar1,piVar7[-4],piVar7[-3]);
            uVar6 = *extraout_ECX;
            *(uint *)((int)local_34 + extraout_EDX + 8) = uVar5;
            uVar6 = FUN_010021d4(uVar2,uVar1,extraout_ECX[-1],uVar6);
            *(uint *)((int)local_34 + extraout_EDX_00) = uVar6;
            piVar7 = (int *)(extraout_ECX_00 + 0x18);
          } while (extraout_EDX_00 + 4 < 8);
          if ((((int)local_34[2] < 0) || (0 < (int)local_34[0])) &&
             (((int)local_34[3] < 0 || (0 < (int)local_34[1])))) {
            GlobalUnlock(local_8);
            goto LAB_010027d7;
          }
        }
        GlobalUnlock(local_8);
      }
      local_c = local_c + 1;
      local_10 = local_10 + 0x3c;
    } while (local_c < *(int *)(param_1 + 0x7c));
  }
  local_14 = 1;
LAB_010027d7:
  *param_4 = local_c;
  if (local_8 != (HGLOBAL)0x0) {
    GlobalFree(local_8);
  }
  return local_14;
}



/* VA 01002803 */

void FUN_01002803(HWND param_1,LONG param_2)

{
  DAT_0100b4a0 = GetWindowLongA(param_1,-4);
  SetWindowLongA(param_1,-4,param_2);
  return;
}



/* VA 01002827 */

LRESULT FUN_01002827(HWND param_1,UINT param_2,WPARAM param_3,int param_4)

{
  LRESULT LVar1;

  if (((param_2 == 0xb1) && (param_3 == 0)) && (param_4 == -2)) {
    LVar1 = 0;
  }
  else {
    LVar1 = CallWindowProcA(DAT_0100b4a0,param_1,param_2,param_3,param_4);
  }
  return LVar1;
}



/* VA 0100285f */

undefined4 FUN_0100285f(LPCSTR param_1)

{
  int iVar1;

  if (((param_1 != (LPCSTR)0x0) && (iVar1 = lstrlenA(param_1), 2 < iVar1)) &&
     ((param_1[1] == ':' || ((*param_1 == '\\' && (param_1[1] == '\\')))))) {
    return 1;
  }
  return 0;
}



/* VA 0100288f */

void FUN_0100288f(void)

{
  DWORD DVar1;
  BOOL BVar2;
  tagMSG local_24;
  int local_8;

  local_8 = 0;
  do {
    do {
      DVar1 = MsgWaitForMultipleObjects(1,(HANDLE *)&stack0x00000004,0,0xffffffff,0xff);
      if (DVar1 == 0) {
        return;
      }
      BVar2 = PeekMessageA(&local_24,(HWND)0x0,0,0,1);
    } while (BVar2 == 0);
    do {
      if (local_24.message == 0x12) {
        local_8 = 1;
      }
      else {
        DispatchMessageA(&local_24);
      }
      BVar2 = PeekMessageA(&local_24,(HWND)0x0,0,0,1);
    } while (BVar2 != 0);
  } while (local_8 == 0);
  return;
}



/* VA 010028fa */

void FUN_010028fa(uint param_1)

{
  int iVar1;

  if ((DAT_0100b495 & 8) == 0) {
    iVar1 = FUN_01002613();
    if ((iVar1 == 2) || (((param_1 & 0xff000000) == 0xaa000000 && ((param_1 & 1) != 0)))) {
      DAT_0100aa5c = 0xbc2;
      return;
    }
    if ((DAT_0100b495 & 2) == 0) {
      return;
    }
  }
  DAT_0100aa5c = param_1;
  return;
}



/* VA 01002969 */

void FUN_01002969(HWND param_1,HWND param_2)

{
  HDC hdc;
  int iVar1;
  int iVar2;
  int iVar3;
  tagRECT local_30;
  tagRECT local_20;
  int local_10;
  int local_c;
  int local_8;

  GetWindowRect(param_1,&local_30);
  iVar2 = local_30.right - local_30.left;
  iVar1 = local_30.bottom - local_30.top;
  GetWindowRect(param_2,&local_20);
  local_c = local_20.bottom - local_20.top;
  iVar3 = local_20.right - local_20.left;
  hdc = GetDC(param_1);
  local_8 = GetDeviceCaps(hdc,8);
  local_10 = GetDeviceCaps(hdc,10);
  ReleaseDC(param_1,hdc);
  iVar3 = (iVar3 - iVar2) / 2 + local_20.left;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else if (local_8 < iVar3 + iVar2) {
    iVar3 = local_8 - iVar2;
  }
  iVar2 = (local_c - iVar1) / 2 + local_20.top;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else if (local_10 < iVar2 + iVar1) {
    iVar2 = local_10 - iVar1;
  }
  SetWindowPos(param_1,(HWND)0x0,iVar3,iVar2,0,0,5);
  return;
}



/* VA 01002a34 */

DWORD FUN_01002a34(LPCSTR param_1,undefined4 *param_2,uint param_3)

{
  HRSRC pHVar1;
  DWORD DVar2;
  HGLOBAL hResData;
  undefined4 *hResData_00;
  uint uVar3;
  undefined4 *puVar4;

  pHVar1 = FindResourceA((HMODULE)0x0,param_1,(LPCSTR)0xa);
  DVar2 = SizeofResource((HMODULE)0x0,pHVar1);
  if ((DVar2 <= param_3) && (param_2 != (undefined4 *)0x0)) {
    if (DVar2 != 0) {
      pHVar1 = FindResourceA((HMODULE)0x0,param_1,(LPCSTR)0xa);
      hResData = LoadResource((HMODULE)0x0,pHVar1);
      hResData_00 = LockResource(hResData);
      if (hResData_00 != (undefined4 *)0x0) {
        puVar4 = hResData_00;
        for (uVar3 = DVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *param_2 = *puVar4;
          puVar4 = puVar4 + 1;
          param_2 = param_2 + 1;
        }
        for (uVar3 = DVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)param_2 = *(undefined1 *)puVar4;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
          param_2 = (undefined4 *)((int)param_2 + 1);
        }
        FreeResource(hResData_00);
        return DVar2;
      }
    }
    DVar2 = 0;
  }
  return DVar2;
}



/* VA 01002aa6 */

LPSTR FUN_01002aa6(UINT param_1,LPSTR param_2,int param_3)

{
  if (param_2 != (LPSTR)0x0) {
    *param_2 = '\0';
    LoadStringA(DAT_0100b4a4,param_1,param_2,param_3);
  }
  return param_2;
}



/* VA 01002acd */

undefined4 FUN_01002acd(LPSTR param_1,int param_2,LPCSTR param_3,LPCSTR param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;

  iVar1 = lstrlenA(param_3);
  iVar2 = lstrlenA(param_4);
  if (iVar1 + 1 + iVar2 < param_2) {
    lstrcpyA(param_1,param_3);
    iVar1 = lstrlenA(param_1);
    if (param_1[iVar1 + -1] != '\\') {
      iVar1 = lstrlenA(param_1);
      if (param_1[iVar1 + -1] != '/') {
        iVar1 = lstrlenA(param_1);
        param_1[iVar1] = '\\';
        iVar1 = lstrlenA(param_1);
        param_1[iVar1 + 1] = '\0';
      }
    }
    lstrcatA(param_1,param_4);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* VA 01002b34 */

void FUN_01002b34(LPCSTR param_1)

{
  LPCSTR lpsz;
  int iVar1;

  if (*param_1 != '\0') {
    lpsz = param_1 + 1;
    iVar1 = 0;
    if ((*lpsz == ':') && (param_1[2] == '\\')) {
      lpsz = param_1 + 3;
    }
    else if ((*param_1 == '\\') && (*lpsz == '\\')) {
      lpsz = param_1 + 2;
      iVar1 = 2;
    }
    for (; *lpsz != '\0'; lpsz = CharNextA(lpsz)) {
      if ((*lpsz == '\\') && (lpsz[-1] != ':')) {
        if (iVar1 == 0) {
          *lpsz = '\0';
          CreateDirectoryA(param_1,(LPSECURITY_ATTRIBUTES)0x0);
          *lpsz = '\\';
        }
        else {
          iVar1 = iVar1 + -1;
        }
      }
    }
  }
  return;
}



/* VA 01002b9d */

uint __cdecl FUN_01002b9d(uint param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  BOOL BVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;

  iVar1 = param_1 * 0x18;
  if (*(int *)(&DAT_0100b4c4 + iVar1) == 0) {
    BVar2 = ReadFile(*(HANDLE *)(&DAT_0100b4d4 + iVar1),param_2,param_3,&param_3,(LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      return 0xffffffff;
    }
    return param_3;
  }
  if (*(int *)(&DAT_0100b4c4 + iVar1) == 1) {
    uVar4 = *(int *)(&DAT_0100b4d0 + iVar1) - *(int *)(&DAT_0100b4cc + iVar1);
    if (param_3 < uVar4) {
      uVar4 = param_3;
    }
    puVar5 = (undefined4 *)(*(int *)(&DAT_0100b4c8 + iVar1) + *(int *)(&DAT_0100b4cc + iVar1));
    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *param_2 = *puVar5;
      puVar5 = puVar5 + 1;
      param_2 = param_2 + 1;
    }
    for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)param_2 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
    }
    *(uint *)(&DAT_0100b4cc + iVar1) = *(int *)(&DAT_0100b4cc + iVar1) + uVar4;
    return uVar4;
  }
  return param_1;
}



/* VA 01002c23 */

DWORD __cdecl FUN_01002c23(int param_1,LPCVOID param_2,DWORD param_3)

{
  BOOL BVar1;
  DWORD DVar2;

  FUN_0100288f();
  if (DAT_0100ac38 != 0) {
    return 0xffffffff;
  }
  BVar1 = WriteFile(*(HANDLE *)(&DAT_0100b4d4 + param_1 * 0x18),param_2,param_3,&param_3,
                    (LPOVERLAPPED)0x0);
  DVar2 = param_3;
  if (BVar1 == 0) {
    DVar2 = 0xffffffff;
  }
  else if (((param_3 != 0xffffffff) && (DAT_0100ae60 = DAT_0100ae60 + param_3, DAT_0100a2bc != 0))
          && (DAT_0100aa4c != (HWND)0x0)) {
    SendDlgItemMessageA(DAT_0100aa4c,0x83a,0x402,(uint)(DAT_0100ae60 * 100) / DAT_0100ae58,0);
  }
  return DVar2;
}



/* VA 01002cb2 */

undefined4 __cdecl FUN_01002cb2(int param_1)

{
  undefined4 uVar1;
  BOOL BVar2;
  int iVar3;

  iVar3 = param_1 * 0x18;
  if (*(int *)(&DAT_0100b4c4 + iVar3) == 1) {
    uVar1 = 0;
    (&DAT_0100b4c0)[param_1 * 6] = 1;
    *(undefined4 *)(&DAT_0100b4c8 + iVar3) = 0;
    *(undefined4 *)(&DAT_0100b4d0 + iVar3) = 0;
    *(undefined4 *)(&DAT_0100b4cc + iVar3) = 0;
  }
  else {
    BVar2 = CloseHandle(*(HANDLE *)(&DAT_0100b4d4 + iVar3));
    if (BVar2 == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = 0;
      (&DAT_0100b4c0)[param_1 * 6] = 1;
    }
  }
  return uVar1;
}



/* VA 01002d05 */

DWORD __cdecl FUN_01002d05(DWORD param_1,int param_2,int param_3)

{
  int iVar1;
  DWORD DVar2;

  iVar1 = param_1 * 0x18;
  if (*(int *)(&DAT_0100b4c4 + iVar1) != 1) {
    if (param_3 == 0) {
      param_1 = 0;
    }
    else if (param_3 == 1) {
      param_1 = 1;
    }
    else if (param_3 == 2) {
      param_1 = 2;
    }
    DVar2 = SetFilePointer(*(HANDLE *)(&DAT_0100b4d4 + iVar1),param_2,(PLONG)0x0,param_1);
    if (DVar2 == 0xffffffff) {
      return 0xffffffff;
    }
    return DVar2;
  }
  if (param_3 != 0) {
    if (param_3 == 1) {
      *(int *)(&DAT_0100b4cc + iVar1) = *(int *)(&DAT_0100b4cc + iVar1) + param_2;
      goto LAB_01002d47;
    }
    if (param_3 != 2) {
      return 0xffffffff;
    }
    param_2 = *(int *)(&DAT_0100b4d0 + iVar1) + param_2;
  }
  *(int *)(&DAT_0100b4cc + iVar1) = param_2;
LAB_01002d47:
  return *(DWORD *)(&DAT_0100b4cc + iVar1);
}



/* VA 01002d87 */

bool FUN_01002d87(int param_1,WORD param_2,WORD param_3)

{
  BOOL BVar1;
  _FILETIME local_14;
  _FILETIME local_c;

  if (((*(int *)(&DAT_0100b4c4 + param_1 * 0x18) != 1) &&
      (BVar1 = DosDateTimeToFileTime(param_2,param_3,&local_14), BVar1 != 0)) &&
     (BVar1 = LocalFileTimeToFileTime(&local_14,&local_c), BVar1 != 0)) {
    BVar1 = SetFileTime(*(HANDLE *)(&DAT_0100b4d4 + param_1 * 0x18),&local_c,&local_c,&local_c);
    return BVar1 != 0;
  }
  return false;
}



/* VA 01002ded */

ushort FUN_01002ded(ushort param_1)

{
  ushort uVar1;

  if (param_1 == 0) {
    uVar1 = 0x80;
  }
  else {
    uVar1 = param_1 & 0x27;
  }
  return uVar1;
}



/* VA 01002e1b */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01002e1b(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;

  puVar2 = &DAT_0100b17c;
  puVar3 = &DAT_0100ae6c;
  for (iVar1 = 0xc4; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  lstrcpyA((LPSTR)&DAT_0100b17c,*(LPCSTR *)(param_1 + 0xc));
  lstrcpyA(&DAT_0100b280,*(LPCSTR *)(param_1 + 4));
  lstrcpyA(&DAT_0100b384,*(LPCSTR *)(param_1 + 8));
  _DAT_0100b488 = *(undefined2 *)(param_1 + 0x1e);
  _DAT_0100b48a = *(undefined2 *)(param_1 + 0x20);
  return 0;
}



/* VA 01002e6f */

bool FUN_01002e6f(void)

{
  HRSRC hResInfo;
  HGLOBAL hResData;

  DAT_0100aba4 = FUN_01002a34("CABINET",(undefined4 *)0x0,0);
  hResInfo = FindResourceA((HMODULE)0x0,"CABINET",(LPCSTR)0xa);
  hResData = LoadResource((HMODULE)0x0,hResInfo);
  DAT_0100aba0 = LockResource(hResData);
  return DAT_0100aba0 != (LPVOID)0x0;
}



/* VA 01002eaf */

void FUN_01002eaf(void)

{
  undefined4 *puVar1;
  undefined4 *hMem;
  CHAR local_104 [260];

  hMem = DAT_0100ac40;
  while (hMem != (undefined4 *)0x0) {
    if ((DAT_0100b884 == 0) && (DAT_0100b490 == 0)) {
      SetFileAttributesA((LPCSTR)*hMem,0x80);
      DeleteFileA((LPCSTR)*hMem);
    }
    puVar1 = (undefined4 *)hMem[1];
    LocalFree((HLOCAL)*hMem);
    LocalFree(hMem);
    hMem = puVar1;
  }
  if (((DAT_0100b880 != 0) && (DAT_0100b884 == 0)) && (DAT_0100b490 == 0)) {
    lstrcpyA(local_104,&DAT_0100ac44);
    if ((DAT_0100b494 & 0x20) != 0) {
      FUN_01005b71(local_104);
    }
    SetCurrentDirectoryA("..");
    FUN_01001c7f(local_104);
  }
  if ((DAT_0100aa64 != 1) && (DAT_0100b880 != 0)) {
    FUN_01001946();
  }
  DAT_0100b880 = 0;
  return;
}



/* VA 01002f7a */

bool FUN_01002f7a(LPCSTR param_1,LPSTR param_2)

{
  DWORD DVar1;
  UINT UVar2;
  BOOL BVar3;
  int iVar4;
  CHAR local_104 [260];

  iVar4 = 0;
  do {
    wsprintfA(local_104,"IXP%03d.TMP",iVar4);
    iVar4 = iVar4 + 1;
    lstrcpyA(param_2,param_1);
    FUN_01005b32(param_2,local_104);
    RemoveDirectoryA(param_2);
    DVar1 = GetFileAttributesA(param_2);
    if (DVar1 == 0xffffffff) {
      BVar3 = CreateDirectoryA(param_2,(LPSECURITY_ATTRIBUTES)0x0);
      if (BVar3 != 0) {
        DAT_0100b880 = 1;
        return true;
      }
      break;
    }
  } while (iVar4 < 400);
  UVar2 = GetTempFileNameA(param_1,"IXP",0,param_2);
  if (UVar2 != 0) {
    DeleteFileA(param_2);
    CreateDirectoryA(param_2,(LPSECURITY_ATTRIBUTES)0x0);
  }
  return UVar2 != 0;
}



/* VA 0100302b */

undefined4 FUN_0100302b(char *param_1,int *param_2)

{
  LPCSTR lpString;
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;

  iVar4 = 0;
  cVar1 = *param_1;
  while ((cVar1 != '\0' &&
         ((((cVar1 == ' ' || (cVar1 == '\t')) || (cVar1 == '\r')) ||
          (((cVar1 == '\n' || (cVar1 == '\v')) || (cVar1 == '\f'))))))) {
    iVar4 = iVar4 + 1;
    cVar1 = param_1[iVar4];
  }
  lpString = param_1 + iVar4;
  if (*lpString == '\0') {
    uVar2 = 0;
  }
  else {
    iVar3 = lstrlenA(lpString);
    do {
      iVar3 = iVar3 + -1;
      if (iVar3 < 0) break;
      cVar1 = lpString[iVar3];
    } while (((cVar1 == ' ') || (cVar1 == '\t')) ||
            ((cVar1 == '\r' || (((cVar1 == '\n' || (cVar1 == '\v')) || (cVar1 == '\f'))))));
    param_1[iVar3 + iVar4 + 1] = '\0';
    *param_2 = iVar4;
    uVar2 = 1;
  }
  return uVar2;
}



/* VA 010030a7 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_010030a7(char *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  LPCSTR lpsz;
  DWORD DVar5;
  short *psVar6;
  LPSTR pCVar7;
  char *pcVar8;
  short *psVar9;
  int iVar10;
  char *lpString1;
  char local_10c [3];
  undefined2 local_109;
  int local_8;

  local_8 = 1;
  if ((param_1 == (char *)0x0) || (lpsz = param_1, *param_1 == '\0')) {
    local_8 = 1;
  }
  else {
    do {
      if (local_8 == 0) break;
      for (; ((((cVar4 = *lpsz, cVar4 == ' ' || (cVar4 == '\t')) || (cVar4 == '\r')) ||
              ((cVar4 == '\n' || (cVar4 == '\v')))) || (cVar4 == '\f')); lpsz = CharNextA(lpsz)) {
      }
      if (*lpsz == '\0') break;
      iVar10 = 0;
      bVar1 = false;
      bVar3 = false;
      do {
        if (bVar1) {
          if (bVar3) break;
        }
        else {
          cVar4 = *lpsz;
          if (((cVar4 == ' ') || (cVar4 == '\t')) ||
             ((cVar4 == '\r' || (((cVar4 == '\n' || (cVar4 == '\v')) || (cVar4 == '\f')))))) break;
        }
        bVar2 = bVar3;
        if (*lpsz == '\"') {
          pcVar8 = lpsz + 1;
          if (*pcVar8 == '\"') {
            local_10c[iVar10] = '\"';
            iVar10 = iVar10 + 1;
            pcVar8 = lpsz + 2;
          }
          else {
            bVar2 = true;
            if (!bVar1) {
              bVar2 = bVar3;
              bVar1 = true;
            }
          }
        }
        else {
          local_10c[iVar10] = *lpsz;
          iVar10 = iVar10 + 1;
          pcVar8 = lpsz + 1;
        }
        lpsz = pcVar8;
        bVar3 = bVar2;
      } while (*pcVar8 != '\0');
      local_10c[iVar10] = '\0';
      if (bVar1) {
        if (!bVar3) {
LAB_0100317c:
          local_8 = 0;
          break;
        }
      }
      else if (bVar3) goto LAB_0100317c;
      if ((local_10c[0] != '/') && (local_10c[0] != '-')) {
        return 0;
      }
      pCVar7 = CharUpperA((LPSTR)(int)local_10c[1]);
      cVar4 = (char)pCVar7;
      if (cVar4 == '?') {
        FUN_0100189e();
        if (DAT_0100aa54 != (HANDLE)0x0) {
          CloseHandle(DAT_0100aa54);
        }
                    /* WARNING: Subroutine does not return */
        ExitProcess(0);
      }
      if (cVar4 == 'C') {
        if (local_10c[2] == '\0') {
          DAT_0100b884 = 1;
        }
        else {
          if (local_10c[2] != ':') goto LAB_0100322f;
          pcVar8 = (char *)(((char)local_109 == '\"') + 3);
          psVar6 = (short *)(local_10c + (int)pcVar8);
          iVar10 = lstrlenA((LPCSTR)psVar6);
          if ((((iVar10 == 0) ||
               ((psVar9 = FUN_01005b00(psVar6,0x5b), psVar9 != (short *)0x0 &&
                (psVar9 = FUN_01005b00(psVar6,0x5d), psVar9 == (short *)0x0)))) ||
              ((psVar9 = FUN_01005b00(psVar6,0x5d), psVar9 != (short *)0x0 &&
               (psVar9 = FUN_01005b00(psVar6,0x5b), psVar9 == (short *)0x0)))) ||
             (param_1 = pcVar8, iVar10 = FUN_0100302b((char *)psVar6,(int *)&param_1), iVar10 == 0))
          goto LAB_010034f2;
          lstrcpyA(&DAT_0100baa2,local_10c + (int)(param_1 + (int)pcVar8));
        }
      }
      else if (cVar4 == 'D') {
LAB_010033ce:
        if (local_10c[2] != ':') goto LAB_0100322f;
        pcVar8 = (char *)(((char)local_109 == '\"') + 3);
        iVar10 = lstrlenA(local_10c + (int)pcVar8);
        if ((iVar10 == 0) ||
           (param_1 = pcVar8, iVar10 = FUN_0100302b(local_10c + (int)pcVar8,(int *)&param_1),
           iVar10 == 0)) {
LAB_010034f2:
          local_8 = 0;
        }
        else {
          pCVar7 = CharUpperA((LPSTR)(int)local_10c[1]);
          if ((char)pCVar7 == 'T') {
            lpString1 = &DAT_0100b99e;
          }
          else {
            lpString1 = &DAT_0100b89a;
          }
          lstrcpyA(lpString1,local_10c + (int)(param_1 + (int)pcVar8));
          FUN_01005b32(lpString1,"");
          iVar10 = FUN_0100285f(lpString1);
          if (iVar10 == 0) {
            return 0;
          }
        }
      }
      else if (cVar4 == 'N') {
        if (local_10c[2] == '\0') {
          DAT_0100b88c = 1;
        }
        else {
          if (local_10c[2] != ':') goto LAB_0100322f;
          if ((char)local_109 != '\0') {
            pcVar8 = local_10c + 3;
            do {
              pCVar7 = CharUpperA((LPSTR)(int)*pcVar8);
              cVar4 = (char)pCVar7;
              pcVar8 = pcVar8 + 1;
              if (cVar4 == 'E') {
                DAT_0100b88c = 1;
              }
              else if (cVar4 == 'G') {
                DAT_0100b890 = 1;
              }
              else if (cVar4 == 'V') {
                DAT_0100b894 = 1;
              }
              else {
                local_8 = 0;
              }
            } while (*pcVar8 != '\0');
          }
        }
      }
      else if (cVar4 == 'Q') {
        if (local_10c[2] != '\0') {
          if (local_10c[2] != ':') goto LAB_0100322f;
          pCVar7 = CharUpperA((LPSTR)(int)(char)local_109);
          cVar4 = (char)pCVar7;
          if (cVar4 != '1') {
            if (cVar4 == 'A') {
              DAT_0100b898 = 1;
              goto LAB_01003233;
            }
            if (cVar4 != 'U') goto LAB_0100322f;
          }
        }
        DAT_0100b898 = 2;
      }
      else if (cVar4 == 'R') {
        if (local_10c[2] == '\0') {
          DAT_0100b888 = 1;
          _DAT_0100b48c = 3;
        }
        else if (local_10c[2] == ':') {
          _DAT_0100b48c = 1;
          if ((char)local_109 != '\0') {
            pcVar8 = local_10c + 3;
            do {
              pCVar7 = CharUpperA((LPSTR)(int)*pcVar8);
              cVar4 = (char)pCVar7;
              pcVar8 = pcVar8 + 1;
              if (cVar4 == 'A') {
                _DAT_0100b48c = _DAT_0100b48c | 2;
                goto LAB_010032df;
              }
              if (cVar4 == 'D') {
                _DAT_0100bba8 = _DAT_0100bba8 | 0x40;
                goto LAB_010032e5;
              }
              if (cVar4 == 'I') {
                _DAT_0100b48c = _DAT_0100b48c & 0xfffffffd;
LAB_010032df:
                DAT_0100b888 = 1;
              }
              else {
                if (cVar4 == 'N') {
                  _DAT_0100b48c = _DAT_0100b48c & 0xfffffffe;
                  goto LAB_010032df;
                }
                if (cVar4 == 'P') {
                  _DAT_0100bba8 = _DAT_0100bba8 | 0x80;
                }
                else {
                  if (cVar4 == 'S') {
                    _DAT_0100b48c = _DAT_0100b48c | 4;
                    goto LAB_010032df;
                  }
                  local_8 = 0;
                }
              }
LAB_010032e5:
            } while (*pcVar8 != '\0');
          }
        }
        else {
          iVar10 = lstrcmpiA("RegServer",local_10c + 1);
          if (iVar10 != 0) goto LAB_0100322f;
        }
      }
      else {
        if (cVar4 == 'T') goto LAB_010033ce;
LAB_0100322f:
        local_8 = 0;
      }
LAB_01003233:
    } while (*lpsz != '\0');
    if ((DAT_0100b88c != 0) && (DAT_0100b99e == '\0')) {
      DVar5 = GetModuleFileNameA(DAT_0100b4a4,&DAT_0100b99e,0x104);
      if (DVar5 == 0) {
        local_8 = 0;
      }
      else {
        psVar6 = FUN_01005be8((short *)&DAT_0100b99e,0x5c);
        *(undefined1 *)((int)psVar6 + 1) = 0;
      }
    }
  }
  return local_8;
}



/* VA 01003547 */

DWORD FUN_01003547(void)

{
  DWORD DVar1;

  DVar1 = GetLastError();
  if ((int)DVar1 < 1) {
    DVar1 = GetLastError();
    return DVar1;
  }
  DVar1 = GetLastError();
  return DVar1 & 0xffff | 0x80070000;
}



/* VA 01003566 */

undefined4 FUN_01003566(undefined *param_1)

{
  LPCSTR lpString;
  HRSRC hResInfo;
  HGLOBAL hResData;
  undefined4 *hResData_00;
  int iVar1;
  CHAR local_28 [20];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;

  local_c = 1;
  local_8 = 0;
  wsprintfA(local_28,"UPDFILE%lu",0);
  hResInfo = FindResourceA((HMODULE)0x0,local_28,(LPCSTR)0xa);
  while( true ) {
    if (hResInfo == (HRSRC)0x0) {
      return local_c;
    }
    hResData = LoadResource((HMODULE)0x0,hResInfo);
    hResData_00 = LockResource(hResData);
    if (hResData_00 == (undefined4 *)0x0) break;
    local_14 = *hResData_00;
    local_10 = hResData_00[1];
    lpString = (LPCSTR)(hResData_00 + 2);
    iVar1 = lstrlenA(lpString);
    iVar1 = (*(code *)param_1)(local_14,local_10,lpString,lpString + iVar1 + 1);
    if (iVar1 == 0) {
      local_c = 0;
      FreeResource(hResData_00);
      return local_c;
    }
    FreeResource(hResData_00);
    local_8 = local_8 + 1;
    wsprintfA(local_28,"UPDFILE%lu",local_8);
    hResInfo = FindResourceA((HMODULE)0x0,local_28,(LPCSTR)0xa);
  }
  DAT_0100aa5c = 0x80070714;
  return 0;
}



/* VA 0100366a */

undefined4 FUN_0100366a(DWORD param_1,undefined4 param_2,LPCSTR param_3,LPCVOID param_4)

{
  HANDLE hFile;
  BOOL BVar1;
  CHAR local_110 [260];
  DWORD local_c;
  undefined4 local_8;

  local_8 = 1;
  local_c = 0;
  lstrcpyA(local_110,&DAT_0100ac44);
  FUN_01005b32(local_110,param_3);
  hFile = CreateFileA(local_110,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    DAT_0100aa5c = 0x80070052;
    local_8 = 0;
  }
  else {
    BVar1 = WriteFile(hFile,param_4,param_1,&local_c,(LPOVERLAPPED)0x0);
    if ((BVar1 == 0) || (param_1 != local_c)) {
      DAT_0100aa5c = 0x80070052;
      local_8 = 0;
    }
    CloseHandle(hFile);
  }
  return local_8;
}



/* VA 0100370f */

void FUN_0100370f(LPCSTR param_1)

{
  DWORD DVar1;
  CHAR local_108 [260];

  lstrcpyA(local_108,&DAT_0100ac44);
  FUN_01005b32(local_108,param_1);
  DVar1 = GetFileAttributesA(local_108);
  if ((DVar1 == 0xffffffff) || ((DVar1 & 0x10) != 0)) {
    LoadLibraryA(param_1);
  }
  else {
    LoadLibraryExA(local_108,(HANDLE)0x0,8);
  }
  return;
}



/* VA 0100376f */

undefined4 FUN_0100376f(void)

{
  return 0;
}



/* VA 01003772 */

void FUN_01003772(void)

{
  return;
}



/* VA 01003773 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01003773(HWND param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  HWND pHVar2;
  code *pcVar3;
  INT_PTR nResult;

  if (param_2 == 0xf) {
    if (DAT_0100aa58 == 0) {
      _DAT_0100a840 = SendDlgItemMessageA(param_1,0x834,0xb1,0xffffffff,0);
      DAT_0100aa58 = 1;
    }
LAB_01003837:
    uVar1 = 0;
  }
  else {
    if (param_2 == 0x10) {
LAB_010037a3:
      nResult = 0;
LAB_010037a5:
      EndDialog(param_1,nResult);
    }
    else {
      if (param_2 == 0x110) {
        pHVar2 = GetDesktopWindow();
        FUN_01002969(param_1,pHVar2);
        SetDlgItemTextA(param_1,0x834,DAT_0100b49c);
        SetWindowTextA(param_1,&DAT_0100abb4);
        SetForegroundWindow(param_1);
        pcVar3 = FUN_01002827;
        pHVar2 = GetDlgItem(param_1,0x834);
        FUN_01002803(pHVar2,(LONG)pcVar3);
        return 1;
      }
      if (param_2 != 0x111) goto LAB_01003837;
      if (param_3 == 6) {
        nResult = 1;
        goto LAB_010037a5;
      }
      if (param_3 == 7) goto LAB_010037a3;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* VA 0100383d */

undefined4 FUN_0100383d(HWND param_1,int param_2,uint param_3)

{
  HWND pHVar1;

  if (param_2 == 0x10) {
    EndDialog(param_1,2);
  }
  else if (param_2 == 0x110) {
    pHVar1 = GetDesktopWindow();
    FUN_01002969(param_1,pHVar1);
    SetWindowTextA(param_1,&DAT_0100abb4);
    SetDlgItemTextA(param_1,0x838,DAT_0100ae64);
    SetForegroundWindow(param_1);
  }
  else {
    if (param_2 != 0x111) {
      return 0;
    }
    if (5 < param_3) {
      if (7 < param_3) {
        if (param_3 != 0x839) {
          return 1;
        }
        DAT_0100ac3c = 1;
      }
      EndDialog(param_1,param_3);
      return 1;
    }
  }
  return 1;
}



/* VA 010038cc */

int FUN_010038cc(HWND param_1,UINT param_2,LPCSTR param_3,LPCSTR param_4,uint param_5,uint param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  LPSTR lpString1;
  int iVar4;
  char *pcVar5;
  CHAR *pCVar6;
  char local_23c [512];
  CHAR local_3c [56];

  pcVar5 = "LoadString() Error.  Could not load string resource.";
  pCVar6 = local_3c;
  for (iVar4 = 0xd; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)pCVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pCVar6 = pCVar6 + 4;
  }
  *pCVar6 = *pcVar5;
  if (((byte)DAT_0100b898 & 1) != 0) {
    return 1;
  }
  FUN_01002aa6(param_2,local_23c,0x200);
  if (local_23c[0] == '\0') {
    iVar4 = FUN_01005d22();
    if ((iVar4 == 0) || (iVar4 = FUN_01005cd4(DAT_0100b4a4,(LPCSTR)0x10,(LPCSTR)0x1), iVar4 == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0x180000;
    }
    MessageBoxA(param_1,local_3c,&DAT_0100abb4,uVar1 | 0x10010);
  }
  else if (param_4 == (LPCSTR)0x0) {
    if (param_3 == (LPCSTR)0x0) {
      iVar4 = lstrlenA(local_23c);
      lpString1 = LocalAlloc(0x40,iVar4 + 1);
      if (lpString1 != (LPSTR)0x0) {
        lstrcpyA(lpString1,local_23c);
        goto LAB_01003a1b;
      }
    }
    else {
      iVar4 = lstrlenA(param_3);
      iVar2 = lstrlenA(local_23c);
      lpString1 = LocalAlloc(0x40,iVar4 + 100 + iVar2);
      if (lpString1 != (LPSTR)0x0) {
        wsprintfA(lpString1,local_23c,param_3);
LAB_01003a1b:
        MessageBeep(param_5);
        iVar4 = FUN_01005d22();
        if ((iVar4 == 0) ||
           (iVar4 = FUN_01005cd4(DAT_0100b4a4,(LPCSTR)0x10,(LPCSTR)0x1), iVar4 == 0)) {
          uVar1 = 0;
        }
        else {
          uVar1 = 0x180000;
        }
        iVar4 = MessageBoxA(param_1,lpString1,&DAT_0100abb4,uVar1 | param_5 | param_6 | 0x10000);
        LocalFree(lpString1);
        return iVar4;
      }
    }
  }
  else {
    iVar4 = lstrlenA(param_3);
    iVar2 = lstrlenA(param_4);
    iVar3 = lstrlenA(local_23c);
    lpString1 = LocalAlloc(0x40,iVar4 + iVar2 + 100 + iVar3);
    if (lpString1 != (LPSTR)0x0) {
      wsprintfA(lpString1,local_23c,param_3,param_4);
      goto LAB_01003a1b;
    }
  }
  return -1;
}



/* VA 01003a7a */

undefined4 FUN_01003a7a(LPCSTR param_1)

{
  undefined4 *hMem;
  int iVar1;
  LPSTR lpString1;

  hMem = LocalAlloc(0x40,8);
  if (hMem == (undefined4 *)0x0) {
    FUN_010038cc(DAT_0100aa4c,0x4b5,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
  }
  else {
    iVar1 = lstrlenA(param_1);
    lpString1 = LocalAlloc(0x40,iVar1 + 1);
    *hMem = lpString1;
    if (lpString1 != (LPSTR)0x0) {
      lstrcpyA(lpString1,param_1);
      hMem[1] = DAT_0100ac40;
      DAT_0100ac40 = hMem;
      return 1;
    }
    FUN_010038cc(DAT_0100aa4c,0x4b5,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
    LocalFree(hMem);
  }
  return 0;
}



/* VA 01003b00 */

HANDLE FUN_01003b00(LPCSTR param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  HANDLE pvVar3;
  DWORD dwCreationDisposition;

  uVar2 = param_2;
  if ((param_2 & 8) == 0) {
    uVar1 = param_2 & 3;
    param_2 = 0x80000000;
    if (uVar1 != 0) {
      param_2 = 0x40000000;
    }
    if ((uVar2 & 0x100) == 0) {
      dwCreationDisposition = (-(uint)((uVar2 & 0x200) != 0) & 2) + 3;
    }
    else if ((uVar2 & 0x400) == 0) {
      dwCreationDisposition = (-(uint)((uVar2 & 0x200) != 0) & 0xfffffffe) + 4;
    }
    else {
      dwCreationDisposition = 1;
    }
    pvVar3 = CreateFileA(param_1,param_2,0,(LPSECURITY_ATTRIBUTES)0x0,dwCreationDisposition,0x80,
                         (HANDLE)0x0);
    if ((pvVar3 == (HANDLE)0xffffffff) && (dwCreationDisposition != 3)) {
      FUN_01002b34(param_1);
      pvVar3 = CreateFileA(param_1,param_2,0,(LPSECURITY_ATTRIBUTES)0x0,dwCreationDisposition,0x80,
                           (HANDLE)0x0);
    }
  }
  else {
    pvVar3 = (HANDLE)0xffffffff;
  }
  return pvVar3;
}



/* VA 01003b9b */

int __cdecl FUN_01003b9b(LPCSTR param_1,uint param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  HANDLE pvVar4;
  int iVar5;

  iVar5 = 0;
  piVar2 = &DAT_0100b4c0;
  do {
    if (*piVar2 == 1) break;
    piVar2 = piVar2 + 6;
    iVar5 = iVar5 + 1;
  } while ((int)piVar2 < 0x100b880);
  if (iVar5 == 0x28) {
    FUN_010038cc(DAT_0100aa4c,0x4bb,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
  }
  else {
    iVar3 = lstrcmpA(param_1,s__MEMCAB_0100a204);
    if (iVar3 == 0) {
      if (((param_2 & 0x100) == 0) && ((param_2 & 0xb) == 0)) {
        iVar3 = iVar5 * 0x18;
        *(undefined4 *)(&DAT_0100b4c8 + iVar3) = DAT_0100aba0;
        uVar1 = DAT_0100aba4;
        (&DAT_0100b4c0)[iVar5 * 6] = 0;
        *(undefined4 *)(&DAT_0100b4c4 + iVar3) = 1;
        *(undefined4 *)(&DAT_0100b4d0 + iVar3) = uVar1;
        *(undefined4 *)(&DAT_0100b4cc + iVar3) = 0;
        return iVar5;
      }
    }
    else {
      pvVar4 = FUN_01003b00(param_1,param_2);
      *(HANDLE *)(&DAT_0100b4d4 + iVar5 * 0x18) = pvVar4;
      if (pvVar4 != (HANDLE)0xffffffff) {
        (&DAT_0100b4c0)[iVar5 * 6] = 0;
        *(undefined4 *)(&DAT_0100b4c4 + iVar5 * 0x18) = 0;
        return iVar5;
      }
    }
  }
  return -1;
}



/* VA 01003c60 */

bool FUN_01003c60(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  int local_28 [4];
  int local_18;
  int local_14;
  undefined4 local_10 [3];

  piVar4 = local_28;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  puVar1 = _FDICreate(&LAB_01002e03,&LAB_01002e10,FUN_01003b9b,FUN_01002b9d,FUN_01002c23,
                      FUN_01002cb2,FUN_01002d05,1,local_10);
  bVar5 = false;
  if (puVar1 != (undefined4 *)0x0) {
    iVar3 = FUN_01003b9b(s__MEMCAB_0100a204,0x8000);
    if ((((iVar3 == -1) || (iVar2 = _FDIIsCabinet(puVar1,iVar3,local_28), iVar2 == 0)) ||
        (local_28[0] != DAT_0100aba4)) ||
       (((local_18 != 0 || (local_14 != 0)) || (iVar3 = FUN_01002cb2(iVar3), iVar3 == -1)))) {
      bVar5 = false;
    }
    else {
      iVar3 = FUN_010069c2(puVar1);
      bVar5 = iVar3 != 0;
    }
  }
  return bVar5;
}



/* VA 01003d13 */

undefined4 FUN_01003d13(void)

{
  DWORD DVar1;
  int iVar2;
  UINT UVar3;

  DVar1 = FUN_01002a34("FILESIZES",&DAT_0100bbc0,0x24);
  if (DVar1 == 0x24) {
    DAT_0100ae58 = DAT_0100bbe0;
    if (DAT_0100bbe0 != 0) {
      FUN_01002a34("PACKINSTSPACE",&DAT_0100b498,4);
      iVar2 = FUN_01003566(&LAB_01003638);
      if (iVar2 == 0) {
        FUN_010038cc((HWND)0x0,0x4c6,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
        return 0;
      }
      return 1;
    }
    UVar3 = 0x4c6;
  }
  else {
    UVar3 = 0x4b1;
  }
  FUN_010038cc((HWND)0x0,UVar3,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
  DAT_0100aa5c = 0x80070714;
  return 0;
}



/* VA 01003d9a */

undefined4 FUN_01003d9a(void)

{
  DWORD DVar1;
  LPCSTR lpString1;
  int iVar2;

  DVar1 = FUN_01002a34("UPROMPT",(undefined4 *)0x0,0);
  lpString1 = LocalAlloc(0x40,DVar1 + 1);
  if (lpString1 == (LPCSTR)0x0) {
    FUN_010038cc((HWND)0x0,0x4b5,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
    DAT_0100aa5c = FUN_01003547();
  }
  else {
    DVar1 = FUN_01002a34("UPROMPT",(undefined4 *)lpString1,DVar1);
    if (DVar1 != 0) {
      iVar2 = lstrcmpA(lpString1,"<None>");
      if (iVar2 == 0) {
        LocalFree(lpString1);
      }
      else {
        iVar2 = FUN_010038cc((HWND)0x0,0x3e9,lpString1,(LPCSTR)0x0,0x20,4);
        LocalFree(lpString1);
        if (iVar2 != 6) {
          DAT_0100aa5c = 0x800704c7;
          return 0;
        }
        DAT_0100aa5c = 0;
      }
      return 1;
    }
    FUN_010038cc((HWND)0x0,0x4b1,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
    LocalFree(lpString1);
    DAT_0100aa5c = 0x80070714;
  }
  return 0;
}



/* VA 01003e60 */

undefined4 FUN_01003e60(LPCSTR param_1)

{
  int iVar1;
  LPSTR lpString1;
  HANDLE hObject;
  DWORD DVar2;

  iVar1 = lstrlenA(param_1);
  lpString1 = LocalAlloc(0x40,iVar1 + 0x14);
  if (lpString1 == (LPSTR)0x0) {
    FUN_010038cc((HWND)0x0,0x4b5,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
    DAT_0100aa5c = FUN_01003547();
  }
  else {
    lstrcpyA(lpString1,param_1);
    FUN_01005b32(lpString1,"TMP4351$.TMP");
    hObject = CreateFileA(lpString1,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,1,0x4000080,(HANDLE)0x0)
    ;
    LocalFree(lpString1);
    if (hObject != (HANDLE)0xffffffff) {
      CloseHandle(hObject);
      DVar2 = GetFileAttributesA(param_1);
      if ((DVar2 != 0xffffffff) && ((DVar2 & 0x10) != 0)) {
        DAT_0100aa5c = 0;
        return 1;
      }
    }
    DAT_0100aa5c = FUN_01003547();
  }
  return 0;
}



/* VA 01003f0d */

bool FUN_01003f0d(LPCSTR param_1,uint param_2,int param_3)

{
  ushort uVar1;
  BOOL BVar2;
  uint uVar3;
  DWORD DVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  bool bVar9;
  bool bVar10;
  UINT UVar11;
  DWORD DVar12;
  CHAR *pCVar13;
  DWORD DVar14;
  va_list *ppcVar15;
  CHAR local_31c;
  undefined4 local_31b;
  CHAR local_11c [260];
  DWORD local_18;
  undefined4 local_14;
  CHAR local_10 [8];
  int local_8;

  local_8 = 0;
  if (param_2 == 0) {
    return true;
  }
  GetCurrentDirectoryA(0x104,local_11c);
  BVar2 = SetCurrentDirectoryA(param_1);
  if (BVar2 == 0) {
    FUN_010038cc((HWND)0x0,0x4bc,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
    DAT_0100aa5c = FUN_01003547();
  }
  else {
    uVar3 = FUN_01005e67((LPCSTR)0x0,&local_8);
    if (uVar3 == 0) {
      local_31c = '\0';
      puVar8 = &local_31b;
      for (iVar6 = 0x7f; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
      }
      *(undefined2 *)puVar8 = 0;
      *(undefined1 *)((int)puVar8 + 2) = 0;
      DAT_0100aa5c = FUN_01003547();
      ppcVar15 = (va_list *)0x0;
      DVar14 = 0x200;
      pCVar13 = &local_31c;
      DVar12 = 0;
      DVar4 = GetLastError();
      FormatMessageA(0x1000,(LPCVOID)0x0,DVar4,DVar12,pCVar13,DVar14,ppcVar15);
      UVar11 = 0x4b0;
    }
    else {
      BVar2 = GetVolumeInformationA
                        ((LPCSTR)0x0,(LPSTR)0x0,0,(LPDWORD)0x0,&local_18,&local_14,(LPSTR)0x0,0);
      if (BVar2 != 0) {
        SetCurrentDirectoryA(local_11c);
        lstrcpynA(local_10,param_1,3);
        iVar6 = 0x200;
        uVar1 = 0;
        do {
          if (local_8 == iVar6) break;
          iVar6 = iVar6 << 1;
          uVar1 = uVar1 + 1;
        } while (uVar1 < 8);
        if (uVar1 == 8) {
          FUN_010038cc((HWND)0x0,0x4c5,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
          return false;
        }
        if (((DAT_0100b494 & 8) == 0) || ((local_14._1_1_ & 0x80) == 0)) {
          uVar5 = (&DAT_0100bbc0)[uVar1];
          uVar7 = DAT_0100b498;
        }
        else {
          uVar5 = (&DAT_0100bbc0)[uVar1] << 1;
          uVar7 = (DAT_0100b498 >> 2) + DAT_0100b498;
        }
        if (((param_2 & 1) == 0) || ((param_2 & 2) == 0)) {
          if ((param_2 & 1) == 0) {
            bVar9 = uVar7 < uVar3;
            bVar10 = uVar7 == uVar3;
          }
          else {
            bVar9 = uVar5 < uVar3;
            bVar10 = uVar5 == uVar3;
          }
        }
        else {
          bVar9 = uVar7 + uVar5 < uVar3;
          bVar10 = uVar7 + uVar5 == uVar3;
        }
        if (bVar9 || bVar10) {
          DAT_0100aa5c = 0;
          return true;
        }
        bVar9 = FUN_01001fce(param_3,uVar5,uVar7,local_10);
        return bVar9;
      }
      local_31c = '\0';
      puVar8 = &local_31b;
      for (iVar6 = 0x7f; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
      }
      *(undefined2 *)puVar8 = 0;
      *(undefined1 *)((int)puVar8 + 2) = 0;
      DAT_0100aa5c = FUN_01003547();
      ppcVar15 = (va_list *)0x0;
      DVar14 = 0x200;
      pCVar13 = &local_31c;
      DVar12 = 0;
      DVar4 = GetLastError();
      FormatMessageA(0x1000,(LPCVOID)0x0,DVar4,DVar12,pCVar13,DVar14,ppcVar15);
      UVar11 = 0x4f9;
    }
    FUN_010038cc((HWND)0x0,UVar11,param_1,&local_31c,0x10,0);
    SetCurrentDirectoryA(local_11c);
  }
  return false;
}



/* VA 01004112 */

bool FUN_01004112(void)

{
  bool bVar1;
  UINT UVar2;
  CHAR local_108 [260];

  UVar2 = GetWindowsDirectoryA(local_108,0x104);
  if (UVar2 == 0) {
    FUN_010038cc((HWND)0x0,0x4f0,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
    DAT_0100aa5c = FUN_01003547();
    return false;
  }
  bVar1 = FUN_01003f0d(local_108,2,2);
  return bVar1;
}



/* VA 01004161 */

INT_PTR FUN_01004161(HMODULE param_1,LPCSTR param_2,HWND param_3,DLGPROC param_4,int param_5,
                    INT_PTR param_6)

{
  HRSRC hResInfo;
  LPCDLGTEMPLATEA hDialogTemplate;
  INT_PTR IVar1;

  hResInfo = FindResourceA(param_1,param_2,(LPCSTR)0x5);
  if ((hResInfo != (HRSRC)0x0) &&
     (hDialogTemplate = LoadResource(param_1,hResInfo), hDialogTemplate != (LPCDLGTEMPLATEA)0x0)) {
    if (param_5 == 0) {
      param_5 = 0;
    }
    IVar1 = DialogBoxIndirectParamA(param_1,hDialogTemplate,param_3,param_4,param_5);
    FreeResource(hDialogTemplate);
    if (IVar1 != -1) {
      return IVar1;
    }
  }
  FUN_010038cc((HWND)0x0,0x4fb,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
  return param_6;
}



/* VA 010041cd */

bool FUN_010041cd(int param_1)

{
  uint *puVar1;
  LPCSTR lpText;
  uint uVar2;
  BOOL BVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  BYTE *pBVar8;
  bool bVar9;
  bool bVar10;
  BYTE local_1b4 [260];
  _OSVERSIONINFOA local_b0;
  uint auStack_1c [4];
  uint local_c;
  UINT local_8;

  local_8 = 0;
  local_b0.dwOSVersionInfoSize = 0x94;
  BVar3 = GetVersionExA(&local_b0);
  if (BVar3 == 0) {
    local_8 = 0x4b4;
LAB_010041fa:
    FUN_010038cc((HWND)0x0,local_8,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
  }
  else {
    if (local_b0.dwPlatformId == 1) {
      DAT_0100aa64 = 0;
      DAT_0100a2bc = 1;
      DAT_0100a2c0 = 1;
    }
    else {
      if (local_b0.dwPlatformId != 2) {
        local_8 = 0x4ca;
        goto LAB_010041fa;
      }
      DAT_0100a2bc = 1;
      DAT_0100a2c0 = 1;
      DAT_0100aa64 = 2;
      if (local_b0.dwMajorVersion < 4) {
        DAT_0100aa64 = 1;
        if ((local_b0.dwMajorVersion < 3) ||
           ((local_b0.dwMajorVersion == 3 && (local_b0.dwMinorVersion < 0x33)))) {
          DAT_0100a2bc = 0;
          DAT_0100a2c0 = 0;
        }
      }
      else if (4 < local_b0.dwMajorVersion) {
        DAT_0100aa64 = 3;
      }
    }
    if ((DAT_0100b894 == 0) && (param_1 != 0)) {
      iVar7 = param_1 + 0x40;
      if (DAT_0100aa64 != 0) {
        iVar7 = param_1 + 4;
      }
      local_c = 0;
      do {
        puVar1 = (uint *)(iVar7 + local_c * 0x18);
        uVar4 = FUN_010021d4(local_b0.dwMajorVersion,local_b0.dwMinorVersion,*puVar1,puVar1[1]);
        uVar6 = local_c;
        auStack_1c[local_c + 2] = uVar4;
        iVar5 = iVar7 + uVar6 * 0x18;
        uVar4 = FUN_010021d4(local_b0.dwMajorVersion,local_b0.dwMinorVersion,*(uint *)(iVar5 + 0xc),
                             *(uint *)(iVar5 + 0x10));
        uVar6 = local_c;
        iVar5 = local_c + 2;
        auStack_1c[local_c] = uVar4;
        if (((int)auStack_1c[iVar5] < 0) || (0 < (int)uVar4)) {
          if (uVar6 == 1) goto LAB_01004405;
        }
        else {
          if (auStack_1c[iVar5] == 0) {
            if (uVar4 == 0) {
              uVar4 = local_b0.dwBuildNumber & 0xffff;
              iVar5 = iVar7 + uVar6 * 0x18;
              if (*(uint *)(iVar5 + 8) <= uVar4) {
                uVar2 = *(uint *)(iVar5 + 0x14);
                bVar9 = uVar4 < uVar2;
                bVar10 = uVar4 == uVar2;
                goto LAB_010043fb;
              }
            }
            else if (*(uint *)(iVar7 + 8 + uVar6 * 0x18) <= (local_b0.dwBuildNumber & 0xffff))
            break;
          }
          else {
            if (uVar4 != 0) break;
            uVar4 = *(uint *)(iVar7 + 0x14 + uVar6 * 0x18);
            bVar9 = (local_b0.dwBuildNumber & 0xffff) < uVar4;
            bVar10 = (local_b0.dwBuildNumber & 0xffff) == uVar4;
LAB_010043fb:
            if (bVar9 || bVar10) break;
          }
          if (uVar6 != 0) {
LAB_01004405:
            local_8 = 0x54c;
            goto LAB_01004372;
          }
        }
        local_c = uVar6 + 1;
      } while ((int)local_c < 2);
      if ((*(int *)(param_1 + 0x7c) != 0) &&
         (iVar5 = FUN_01002691(param_1,local_1b4,0x104,(int *)(auStack_1c + 4)), iVar5 == 0)) {
        local_8 = 0x54d;
        uVar6 = local_c;
LAB_01004372:
        pBVar8 = (BYTE *)0x0;
        if (local_8 == 0x54d) {
          pBVar8 = local_1b4;
          iVar7 = uVar6 * 0x3c + *(int *)(param_1 + 0x80) + 0x84 + param_1;
        }
        lpText = (LPCSTR)(*(int *)(iVar7 + 0x34) + 0x84 + param_1);
        uVar6 = FUN_010021b7(*(uint *)(iVar7 + 0x30));
        if ((((byte)DAT_0100b898 & 1) == 0) && (*lpText != '\0')) {
          MessageBeep(0);
          iVar7 = FUN_01005d22();
          if ((iVar7 == 0) ||
             (iVar7 = FUN_01005cd4(DAT_0100b4a4,(LPCSTR)0x10,(LPCSTR)0x1), iVar7 == 0)) {
            uVar4 = 0;
          }
          else {
            uVar4 = 0x180000;
          }
          iVar7 = MessageBoxA((HWND)0x0,lpText,&DAT_0100abb4,uVar4 | uVar6 | 0x30);
          if ((uVar6 & 4) == 0) {
            if ((uVar6 & 1) == 0) goto LAB_01004471;
            bVar9 = iVar7 == 1;
          }
          else {
            bVar9 = iVar7 == 6;
          }
          if (bVar9) {
            local_8 = 0;
          }
        }
        else {
          FUN_010038cc((HWND)0x0,local_8,&DAT_0100abb4,(LPCSTR)pBVar8,0x30,0);
        }
      }
    }
  }
LAB_01004471:
  return local_8 == 0;
}



/* VA 01004481 */

undefined4 FUN_01004481(void)

{
  DWORD DVar1;
  int iVar2;
  INT_PTR IVar3;

  DVar1 = FUN_01002a34("LICENSE",(undefined4 *)0x0,0);
  DAT_0100b49c = LocalAlloc(0x40,DVar1 + 1);
  if (DAT_0100b49c == (LPCSTR)0x0) {
    FUN_010038cc((HWND)0x0,0x4b5,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
    DAT_0100aa5c = FUN_01003547();
  }
  else {
    DVar1 = FUN_01002a34("LICENSE",(undefined4 *)DAT_0100b49c,DVar1);
    if (DVar1 != 0) {
      iVar2 = lstrcmpA(DAT_0100b49c,"<None>");
      if (iVar2 == 0) {
        LocalFree(DAT_0100b49c);
      }
      else {
        IVar3 = FUN_01004161(DAT_0100b4a4,(LPCSTR)0x7d1,(HWND)0x0,FUN_01003773,0,0);
        LocalFree(DAT_0100b49c);
        if (IVar3 == 0) {
          DAT_0100aa5c = 0x800704c7;
          return 0;
        }
      }
      DAT_0100aa5c = 0;
      return 1;
    }
    FUN_010038cc((HWND)0x0,0x4b1,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
    LocalFree(DAT_0100b49c);
    DAT_0100aa5c = 0x80070714;
  }
  return 0;
}



/* VA 01004560 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01004560(LPSTR param_1,LPSTARTUPINFOA param_2)

{
  BOOL BVar1;
  DWORD dwMessageId;
  DWORD dwLanguageId;
  CHAR *lpBuffer;
  DWORD nSize;
  va_list *Arguments;
  CHAR local_214 [512];
  _PROCESS_INFORMATION local_14;

  if (param_1 != (LPSTR)0x0) {
    local_14.hProcess = (HANDLE)0x0;
    local_14.hThread = (HANDLE)0x0;
    local_14.dwProcessId = 0;
    local_14.dwThreadId = 0;
    BVar1 = CreateProcessA((LPCSTR)0x0,param_1,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0
                           ,0,0x20,(LPVOID)0x0,(LPCSTR)0x0,param_2,&local_14);
    if (BVar1 == 0) {
      DAT_0100aa5c = FUN_01003547();
      Arguments = (va_list *)0x0;
      nSize = 0x200;
      lpBuffer = local_214;
      dwLanguageId = 0;
      dwMessageId = GetLastError();
      FormatMessageA(0x1000,(LPCVOID)0x0,dwMessageId,dwLanguageId,lpBuffer,nSize,Arguments);
      FUN_010038cc((HWND)0x0,0x4c4,param_1,local_214,0x10,0);
    }
    else {
      WaitForSingleObject(local_14.hProcess,0xffffffff);
      GetExitCodeProcess(local_14.hProcess,(LPDWORD)&param_2);
      if ((((DAT_0100b888 == 0) && (((uint)_DAT_0100b48c & 1) != 0)) &&
          (((uint)_DAT_0100b48c & 2) == 0)) && (((uint)param_2 & 0xff000000) == 0xaa000000)) {
        _DAT_0100b48c = param_2;
      }
      FUN_010028fa((uint)param_2);
      CloseHandle(local_14.hThread);
      CloseHandle(local_14.hProcess);
      if ((DAT_0100b495 & 4) == 0) {
        return 1;
      }
      if (-1 < (int)param_2) {
        return 1;
      }
    }
  }
  return 0;
}



/* VA 01004657 */

void FUN_01004657(void)

{
  DWORD DVar1;
  LPCSTR lpString1;
  int iVar2;
  UINT UVar3;
  LPCSTR pCVar4;
  uint uVar5;

  DVar1 = FUN_01002a34("FINISHMSG",(undefined4 *)0x0,0);
  lpString1 = LocalAlloc(0x40,DVar1 + 1);
  if (lpString1 == (LPCSTR)0x0) {
    FUN_010038cc((HWND)0x0,0x4b5,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
    return;
  }
  DVar1 = FUN_01002a34("FINISHMSG",(undefined4 *)lpString1,DVar1);
  if (DVar1 == 0) {
    uVar5 = 0x10;
    UVar3 = 0x4b1;
    pCVar4 = (LPCSTR)0x0;
  }
  else {
    iVar2 = lstrcmpA(lpString1,"<None>");
    if (iVar2 == 0) goto LAB_010046c8;
    uVar5 = 0x40;
    UVar3 = 0x3e9;
    pCVar4 = lpString1;
  }
  FUN_010038cc((HWND)0x0,UVar3,pCVar4,(LPCSTR)0x0,uVar5,0);
LAB_010046c8:
  LocalFree(lpString1);
  return;
}



/* VA 010046d4 */

bool FUN_010046d4(HWND param_1,undefined4 param_2,LPSTR param_3)

{
  HMODULE hModule;
  int iVar1;
  LPSTR pCVar2;
  UINT UVar3;
  HWND local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 *local_24;
  char *local_20;
  HMODULE local_18;
  FARPROC local_14;
  FARPROC local_10;
  FARPROC local_c;
  LPSTR local_8;

  hModule = LoadLibraryA(s_SHELL32_DLL_0100a23c);
  local_18 = hModule;
  if (hModule == (HMODULE)0x0) {
    UVar3 = 0x4c2;
  }
  else {
    local_c = GetProcAddress(hModule,s_SHBrowseForFolder_0100a264);
    if (((local_c != (FARPROC)0x0) &&
        (local_14 = GetProcAddress(hModule,(LPCSTR)0xc3), local_14 != (FARPROC)0x0)) &&
       (local_10 = GetProcAddress(hModule,s_SHGetPathFromIDList_0100a278), local_10 != (FARPROC)0x0)
       ) {
      if (DAT_0100aa80 == '\0') {
        GetTempPathA(0x104,&DAT_0100aa80);
        iVar1 = lstrlenA(&DAT_0100aa80);
        local_8 = CharPrevA(&DAT_0100aa80,&DAT_0100aa80 + iVar1);
        if ((*local_8 == '\\') && (pCVar2 = CharPrevA(&DAT_0100aa80,local_8), *pCVar2 != ':')) {
          *local_8 = '\0';
        }
      }
      local_38 = param_1;
      local_2c = param_2;
      *param_3 = '\0';
      local_34 = 0;
      local_30 = 0;
      local_28 = 1;
      local_24 = &LAB_01002948;
      local_20 = &DAT_0100aa80;
      iVar1 = (*local_c)(&local_38);
      if (iVar1 != 0) {
        (*local_10)(iVar1,&DAT_0100aa80);
        if (DAT_0100aa80 != '\0') {
          lstrcpyA(param_3,&DAT_0100aa80);
        }
        (*local_14)(iVar1);
      }
      FreeLibrary(local_18);
      return *param_3 != '\0';
    }
    FreeLibrary(hModule);
    UVar3 = 0x4c1;
  }
  FUN_010038cc(param_1,UVar3,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
  return false;
}



/* VA 01004809 */

undefined4 FUN_01004809(LPCSTR param_1)

{
  uint uVar1;
  INT_PTR IVar2;
  undefined4 unaff_EBX;

  uVar1 = FUN_01005bca(param_1);
  if (uVar1 != 0) {
    if ((DAT_0100ac3c == 0) && (((byte)DAT_0100b898 & 1) == 0)) {
      DAT_0100ae64 = param_1;
      IVar2 = FUN_01004161(DAT_0100b4a4,(LPCSTR)0x7d3,DAT_0100aa4c,FUN_0100383d,0,6);
      if (IVar2 != 6) {
        if (IVar2 == 7) {
          return unaff_EBX;
        }
        if (IVar2 == 0x839) {
          DAT_0100ac3c = 1;
        }
      }
    }
    SetFileAttributesA(param_1,0x80);
  }
  return unaff_EBX;
}



/* VA 01004888 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_01004888(int param_1,int param_2)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined2 extraout_var_00;
  BOOL BVar4;
  int extraout_EAX;
  int iVar5;
  CHAR local_108 [260];

  if (DAT_0100ac38 == 0) {
    if (param_1 == 0) {
      iVar3 = FUN_01002e1b(param_2);
      return iVar3;
    }
    if (param_1 == 1) {
      return 0;
    }
    if (param_1 == 2) {
      if (DAT_0100aa4c != (HWND)0x0) {
        SetDlgItemTextA(DAT_0100aa4c,0x837,*(LPCSTR *)(param_2 + 4));
      }
      iVar3 = FUN_01002acd(local_108,0x104,&DAT_0100ac44,*(LPCSTR *)(param_2 + 4));
      if (iVar3 != 0) {
        FUN_01004809(local_108);
        if (extraout_EAX == 0) {
          return 0;
        }
        iVar3 = FUN_01003b9b(local_108,0x8302);
        if ((iVar3 != -1) && (iVar5 = FUN_01003a7a(local_108), iVar5 != 0)) {
          _DAT_0100ae54 = _DAT_0100ae54 + 1;
          return iVar3;
        }
      }
    }
    else if (param_1 == 3) {
      iVar3 = FUN_01002acd(local_108,0x104,&DAT_0100ac44,*(LPCSTR *)(param_2 + 4));
      if ((iVar3 != 0) &&
         (bVar1 = FUN_01002d87(*(int *)(param_2 + 0x14),*(WORD *)(param_2 + 0x18),
                               *(WORD *)(param_2 + 0x1a)), CONCAT31(extraout_var,bVar1) != 0)) {
        FUN_01002cb2(*(int *)(param_2 + 0x14));
        uVar2 = FUN_01002ded(*(ushort *)(param_2 + 0x1c));
        BVar4 = SetFileAttributesA(local_108,CONCAT22(extraout_var_00,uVar2));
        return (-(uint)(BVar4 != 0) & 2) - 1;
      }
    }
    else if (param_1 != 4) {
      return 0;
    }
  }
  else if (param_1 == 3) {
    FUN_01002cb2(*(int *)(param_2 + 0x14));
  }
  return -1;
}



/* VA 010049db */

WPARAM FUN_010049db(void)

{
  bool bVar1;
  undefined3 extraout_var;
  HWND pHVar2;
  undefined3 extraout_var_00;
  undefined4 *puVar3;
  WPARAM wParam;
  UINT UVar4;
  int iVar5;

  bVar1 = FUN_01002e6f();
  if (CONCAT31(extraout_var,bVar1) == 0) {
    return 0;
  }
  if (DAT_0100aa4c != (HWND)0x0) {
    iVar5 = 0;
    pHVar2 = GetDlgItem(DAT_0100aa4c,0x842);
    ShowWindow(pHVar2,iVar5);
    iVar5 = 5;
    pHVar2 = GetDlgItem(DAT_0100aa4c,0x841);
    ShowWindow(pHVar2,iVar5);
  }
  bVar1 = FUN_01003c60();
  if (CONCAT31(extraout_var_00,bVar1) == 0) {
    UVar4 = 0x4ba;
  }
  else {
    puVar3 = _FDICreate(&LAB_01002e03,&LAB_01002e10,FUN_01003b9b,FUN_01002b9d,FUN_01002c23,
                        FUN_01002cb2,FUN_01002d05,1,&DAT_0100aba8);
    if (puVar3 != (undefined4 *)0x0) {
      wParam = FUN_01006e88(puVar3,s__MEMCAB_0100a204,"",0,FUN_01004888,0,&DAT_0100aba0);
      if (wParam == 0) goto LAB_01004abd;
      iVar5 = FUN_010069c2(puVar3);
      if (iVar5 != 0) goto LAB_01004abd;
    }
    UVar4 = DAT_0100aba8 + 0x514;
  }
  FUN_010038cc(DAT_0100aa4c,UVar4,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
  wParam = 0;
LAB_01004abd:
  if (DAT_0100aba0 != (HGLOBAL)0x0) {
    FreeResource(DAT_0100aba0);
    DAT_0100aba0 = (HGLOBAL)0x0;
  }
  if ((wParam == 0) && (DAT_0100ac38 == 0)) {
    FUN_010038cc((HWND)0x0,0x4f8,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
  }
  if ((((byte)DAT_0100b898 & 1) == 0) && ((DAT_0100b494 & 1) == 0)) {
    SendMessageA(DAT_0100aa4c,0xfa1,wParam,0);
  }
  return wParam;
}



/* VA 01004b1a */

undefined4 FUN_01004b1a(LPCSTR param_1,int param_2,uint param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  BOOL BVar3;
  undefined3 extraout_var_00;
  char *pcVar4;
  CHAR local_12c [260];
  _union_530 local_28 [9];

  if (param_2 == 0) {
    lstrcpyA(&DAT_0100ac44,param_1);
    goto LAB_01004bb6;
  }
  bVar1 = FUN_01002f7a(param_1,local_12c);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    return 0;
  }
  lstrcpyA(&DAT_0100ac44,local_12c);
  if ((DAT_0100b494 & 0x20) != 0) {
    GetSystemInfo((LPSYSTEM_INFO)&local_28[0].s);
    if (local_28[0].s.wProcessorArchitecture == 0) {
      pcVar4 = "i386";
    }
    else if (local_28[0].s.wProcessorArchitecture == 1) {
      pcVar4 = "mips";
    }
    else if (local_28[0].s.wProcessorArchitecture == 2) {
      pcVar4 = "alpha";
    }
    else {
      if (local_28[0].s.wProcessorArchitecture != 3) goto LAB_01004b9a;
      pcVar4 = "ppc";
    }
    FUN_01005b32(&DAT_0100ac44,pcVar4);
  }
LAB_01004b9a:
  FUN_01005b32(&DAT_0100ac44,"");
LAB_01004bb6:
  iVar2 = FUN_01003e60(&DAT_0100ac44);
  if (iVar2 == 0) {
    BVar3 = CreateDirectoryA(&DAT_0100ac44,(LPSECURITY_ATTRIBUTES)0x0);
    if (BVar3 == 0) {
      DAT_0100aa5c = FUN_01003547();
      return 0;
    }
    DAT_0100b880 = 1;
  }
  bVar1 = FUN_01003f0d(&DAT_0100ac44,param_3,0);
  if (CONCAT31(extraout_var_00,bVar1) == 0) {
    if (DAT_0100b880 != 0) {
      DAT_0100b880 = 0;
      RemoveDirectoryA(&DAT_0100ac44);
    }
    return 0;
  }
  DAT_0100aa5c = 0;
  return 1;
}



/* VA 01004c18 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01004c18(HMODULE param_1,char *param_2)

{
  bool bVar1;
  DWORD DVar2;
  HRSRC hResInfo;
  undefined3 extraout_var;
  INT_PTR IVar3;
  int iVar4;
  undefined4 *puVar5;
  UINT UVar6;
  CHAR local_10c [260];
  HGLOBAL local_8;

  DAT_0100b4a4 = param_1;
  puVar5 = &DAT_0100aba0;
  for (iVar4 = 0x23f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  puVar5 = &DAT_0100b880;
  for (iVar4 = 0xcb; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  puVar5 = (undefined4 *)&DAT_0100aa80;
  for (iVar4 = 0x41; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  local_8 = (HGLOBAL)0x0;
  _DAT_0100ae4c = 1;
  DVar2 = FUN_01002a34("TITLE",(undefined4 *)&DAT_0100abb4,0x7f);
  if ((DVar2 == 0) || (0x80 < DVar2)) {
    UVar6 = 0x4b1;
  }
  else {
    DAT_0100aa50 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCSTR)0x0);
    SetEvent(DAT_0100aa50);
    DVar2 = FUN_01002a34("EXTRACTOPT",(undefined4 *)&DAT_0100b494,4);
    if (DVar2 == 0) {
LAB_01004cd5:
      FUN_010038cc((HWND)0x0,0x4b1,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
      DAT_0100aa5c = 0x80070714;
      return 0;
    }
    if ((DAT_0100b494 & 0xc0) != 0) {
      DVar2 = FUN_01002a34("INSTANCECHECK",(undefined4 *)local_10c,0x104);
      if (DVar2 == 0) goto LAB_01004cd5;
      DAT_0100aa54 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0,1,local_10c);
      if ((DAT_0100aa54 != (HANDLE)0x0) && (DVar2 = GetLastError(), DVar2 == 0xb7)) {
        if ((DAT_0100b494 & 0x80) != 0) {
          FUN_010038cc((HWND)0x0,0x54b,&DAT_0100abb4,(LPCSTR)0x0,0x10,0);
LAB_01004d4a:
          CloseHandle(DAT_0100aa54);
          DAT_0100aa5c = 0x800700b7;
          return 0;
        }
        iVar4 = FUN_010038cc((HWND)0x0,0x524,&DAT_0100abb4,(LPCSTR)0x0,0x20,4);
        if (iVar4 != 6) goto LAB_01004d4a;
      }
    }
    DAT_0100aa60 = 0;
    iVar4 = FUN_010030a7(param_2);
    if (iVar4 != 0) {
      if (DAT_0100b89a != '\0') {
        FUN_01001c7f(&DAT_0100b89a);
        return 0;
      }
      hResInfo = FindResourceA(param_1,"VERCHECK",(LPCSTR)0xa);
      if (hResInfo != (HRSRC)0x0) {
        local_8 = LoadResource(param_1,hResInfo);
      }
      if (DAT_0100a2bc != 0) {
        InitCommonControls();
      }
      if (DAT_0100b884 != 0) {
        return 1;
      }
      bVar1 = FUN_010041cd((int)local_8);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        return 0;
      }
      if (((DAT_0100aa64 != 1) && (DAT_0100aa64 != 2)) && (DAT_0100aa64 != 3)) {
        return 1;
      }
      if ((DAT_0100b495 & 1) == 0) {
        return 1;
      }
      if (((byte)DAT_0100b898 & 1) != 0) {
        return 1;
      }
      iVar4 = FUN_0100168b();
      if (iVar4 != 0) {
        return 1;
      }
      IVar3 = FUN_01004161(DAT_0100b4a4,(LPCSTR)0x7d6,(HWND)0x0,FUN_010017b1,0x547,0x83e);
      if (IVar3 != 0x83d) {
        return 0;
      }
      return 1;
    }
    UVar6 = 0x520;
  }
  FUN_010038cc((HWND)0x0,UVar6,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
  return 0;
}



/* VA 01004e56 */

undefined4 FUN_01004e56(HWND param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  BOOL BVar3;
  UINT UVar4;
  DWORD DVar5;
  undefined3 extraout_var_00;
  HWND pHVar6;
  uint uVar7;
  LPCSTR pCVar8;

  if (param_2 != 0x10) {
    if (param_2 == 0x110) {
      pHVar6 = GetDesktopWindow();
      FUN_01002969(param_1,pHVar6);
      SetWindowTextA(param_1,&DAT_0100abb4);
      SendDlgItemMessageA(param_1,0x835,0xc5,0x103,0);
      if (DAT_0100aa64 != 1) {
        return 1;
      }
      BVar3 = 0;
      pHVar6 = GetDlgItem(param_1,0x836);
      EnableWindow(pHVar6,BVar3);
      return 1;
    }
    if (param_2 != 0x111) {
      return 0;
    }
    if (param_3 == 1) {
      UVar4 = GetDlgItemTextA(param_1,0x835,&DAT_0100ac44,0x104);
      if ((UVar4 == 0) || (iVar2 = FUN_0100285f(&DAT_0100ac44), iVar2 == 0)) {
        pCVar8 = (LPCSTR)0x0;
        UVar4 = 0x4bf;
      }
      else {
        DVar5 = GetFileAttributesA(&DAT_0100ac44);
        if (DVar5 == 0xffffffff) {
          iVar2 = FUN_010038cc(param_1,0x54a,&DAT_0100ac44,(LPCSTR)0x0,0x20,4);
          if (iVar2 != 6) {
            return 1;
          }
          BVar3 = CreateDirectoryA(&DAT_0100ac44,(LPSECURITY_ATTRIBUTES)0x0);
          if (BVar3 == 0) {
            pCVar8 = &DAT_0100ac44;
            UVar4 = 0x4cb;
            goto LAB_01005001;
          }
        }
        FUN_01005b32(&DAT_0100ac44,"");
        iVar2 = FUN_01003e60(&DAT_0100ac44);
        if (iVar2 != 0) {
          if ((DAT_0100ac44 != '\\') || (uVar7 = 0, DAT_0100ac45 != '\\')) {
            uVar7 = 1;
          }
          bVar1 = FUN_01003f0d(&DAT_0100ac44,uVar7,1);
          if (CONCAT31(extraout_var_00,bVar1) != 0) {
            EndDialog(param_1,1);
          }
          return 1;
        }
        pCVar8 = (LPCSTR)0x0;
        UVar4 = 0x4be;
      }
LAB_01005001:
      FUN_010038cc(param_1,UVar4,pCVar8,(LPCSTR)0x0,0x10,0);
      return 1;
    }
    if (param_3 == 2) {
      EndDialog(param_1,0);
      DAT_0100aa5c = 0x800704c7;
      return 1;
    }
    if (param_3 != 0x836) {
      return 1;
    }
    iVar2 = LoadStringA(DAT_0100b4a4,1000,&DAT_0100a640,0x200);
    if (iVar2 == 0) {
      FUN_010038cc(param_1,0x4b1,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
    }
    else {
      bVar1 = FUN_010046d4(param_1,&DAT_0100a640,&DAT_0100a338);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        return 1;
      }
      BVar3 = SetDlgItemTextA(param_1,0x835,&DAT_0100a338);
      if (BVar3 != 0) {
        return 1;
      }
      FUN_010038cc(param_1,0x4c0,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
    }
  }
  EndDialog(param_1,0);
  return 1;
}



/* VA 01005075 */

undefined4 FUN_01005075(HWND param_1,int param_2,int param_3)

{
  int iVar1;
  HWND pHVar2;
  UINT UVar3;
  WPARAM WVar4;
  LPARAM LVar5;

  if (param_2 != 0x10) {
    if (param_2 != 0x102) {
      if (param_2 == 0x110) {
        DAT_0100aa4c = param_1;
        pHVar2 = GetDesktopWindow();
        FUN_01002969(param_1,pHVar2);
        if (DAT_0100a2bc != 0) {
          LVar5 = 0xbb9;
          WVar4 = 0;
          UVar3 = 0x464;
          pHVar2 = GetDlgItem(param_1,0x83b);
          SendMessageA(pHVar2,UVar3,WVar4,LVar5);
          LVar5 = -0x10000;
          WVar4 = 0xffffffff;
          UVar3 = 0x465;
          pHVar2 = GetDlgItem(param_1,0x83b);
          SendMessageA(pHVar2,UVar3,WVar4,LVar5);
        }
        SetWindowTextA(param_1,&DAT_0100abb4);
        DAT_0100a43c = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_010049db,(LPVOID)0x0,0,
                                    (LPDWORD)&DAT_0100aa48);
        if (DAT_0100a43c == (HANDLE)0x0) {
          FUN_010038cc(param_1,0x4b8,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
          EndDialog(param_1,0);
        }
        return 1;
      }
      if (param_2 != 0x111) {
        if (param_2 == 0xfa1) {
          TerminateThread(DAT_0100a43c,0);
          EndDialog(param_1,param_3);
          return 1;
        }
        return 0;
      }
      if (param_3 != 2) {
        return 1;
      }
      ResetEvent(DAT_0100aa50);
      iVar1 = FUN_010038cc(DAT_0100aa4c,0x4b2,"",(LPCSTR)0x0,0x20,4);
      if ((iVar1 != 6) && (iVar1 != 1)) {
        SetEvent(DAT_0100aa50);
        return 1;
      }
      DAT_0100ac38 = 1;
      SetEvent(DAT_0100aa50);
      FUN_0100288f();
      goto LAB_010051f7;
    }
    if (param_3 != 0x1b) {
      return 1;
    }
  }
  DAT_0100ac38 = 1;
LAB_010051f7:
  EndDialog(param_1,0);
  return 1;
}



/* VA 01005209 */

undefined4 FUN_01005209(void)

{
  uint uVar1;
  WPARAM WVar2;
  int iVar3;

  uVar1 = 0;
  do {
    *(undefined4 *)((int)&DAT_0100b4c0 + uVar1) = 1;
    uVar1 = uVar1 + 0x18;
  } while (uVar1 < 0x3c0);
  if ((((byte)DAT_0100b898 & 1) == 0) && ((DAT_0100b494 & 1) == 0)) {
    WVar2 = FUN_01004161(DAT_0100b4a4,(LPCSTR)(0x7d5 - (uint)(DAT_0100a2bc != 0)),(HWND)0x0,
                         FUN_01005075,0,0);
  }
  else {
    WVar2 = FUN_010049db();
  }
  if (WVar2 == 0) {
    DAT_0100aa5c = 0x8007042b;
  }
  else {
    iVar3 = FUN_01003566(FUN_0100366a);
    if (iVar3 != 0) {
      DAT_0100aa5c = 0;
      return 1;
    }
  }
  return 0;
}



/* VA 01005288 */

undefined4 FUN_01005288(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  HMODULE hModule;
  FARPROC pFVar3;
  int iVar4;
  _STARTUPINFOA *p_Var5;
  short local_188 [130];
  _STARTUPINFOA local_84;
  undefined4 local_40;
  undefined *local_3c;
  LPSTR local_38;
  undefined1 *local_34;
  short *local_30;
  short local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  char *local_18;
  int local_14;
  uint local_10;
  int local_c;
  LPSTR local_8;

  local_c = 0;
  local_1c = 0;
  local_20 = 0;
  DAT_0100aa5c = 0;
  if ((DAT_0100b888 == 0) &&
     ((DVar1 = FUN_01002a34("REBOOT",(undefined4 *)&DAT_0100b48c,4), DVar1 == 0 || (4 < DVar1)))) {
    FUN_010038cc((HWND)0x0,0x4b1,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
    DAT_0100aa5c = 0x80070714;
    uVar2 = 0;
  }
  else {
    local_10 = 0;
    do {
      p_Var5 = &local_84;
      for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
        p_Var5->cb = 0;
        p_Var5 = (_STARTUPINFOA *)&p_Var5->lpReserved;
      }
      local_c = 0;
      local_84.cb = 0x44;
      if (DAT_0100baa2 == '\0') {
        DVar1 = FUN_01002a34("SHOWWINDOW",&local_14,4);
        if ((DVar1 == 0) || (4 < DVar1)) goto LAB_010053df;
        if (local_14 == 1) {
          local_84.wShowWindow = 0;
LAB_0100535c:
          local_84.dwFlags = 1;
        }
        else {
          if (local_14 == 2) {
            local_84.wShowWindow = 6;
            goto LAB_0100535c;
          }
          if (local_14 == 3) {
            local_84.wShowWindow = 3;
            goto LAB_0100535c;
          }
        }
        if (local_10 != 0) goto LAB_01005415;
        if (DAT_0100b898 != 0) {
          if ((DAT_0100b898 & 1) == 0) {
            if ((DAT_0100b898 & 2) != 0) {
              local_18 = "USRQCMD";
            }
          }
          else {
            local_18 = "ADMQCMD";
          }
          DVar1 = FUN_01002a34(local_18,(undefined4 *)local_188,0x104);
          if (DVar1 == 0) goto LAB_010053df;
          iVar4 = lstrcmpiA((LPCSTR)local_188,"<None>");
          if (iVar4 != 0) {
            local_1c = 1;
          }
        }
        if (local_1c == 0) {
          DVar1 = FUN_01002a34("RUNPROGRAM",(undefined4 *)local_188,0x104);
          if (DVar1 == 0) goto LAB_010053df;
          goto LAB_01005415;
        }
      }
      else {
        lstrcpyA((LPSTR)local_188,&DAT_0100baa2);
LAB_01005415:
        if (local_10 == 1) {
          DVar1 = FUN_01002a34("POSTRUNPROGRAM",(undefined4 *)local_188,0x104);
          if (DVar1 == 0) {
LAB_010053df:
            FUN_010038cc((HWND)0x0,0x4b1,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
            DAT_0100aa5c = 0x80070714;
            return 0;
          }
          if ((DAT_0100baa2 != '\0') || (iVar4 = lstrcmpiA((LPCSTR)local_188,"<None>"), iVar4 == 0))
          break;
        }
      }
      iVar4 = FUN_010022ff(local_188,&local_8,&local_c);
      if (iVar4 == 0) {
        return 0;
      }
      if (((local_20 == 0) && (DAT_0100aa64 != 1)) && (DAT_0100b880 != 0)) {
        if (local_c == 0) {
          local_20 = 1;
          FUN_0100198b();
          goto LAB_01005495;
        }
LAB_0100549e:
        if (DAT_0100a2c0 == 0) {
          FUN_010038cc((HWND)0x0,0x4c7,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
          LocalFree(local_8);
          DAT_0100aa5c = 0x8007042b;
          return 0;
        }
        if ((local_c == 0) || ((DAT_0100b494 & 4) == 0)) goto LAB_0100557d;
        hModule = (HMODULE)FUN_0100370f("advpack.dll");
        if (hModule == (HMODULE)0x0) {
          FUN_010038cc((HWND)0x0,0x4c8,"advpack.dll",(LPCSTR)0x0,0x10,0);
LAB_01005612:
          LocalFree(local_8);
          DAT_0100aa5c = FUN_01003547();
          return 0;
        }
        pFVar3 = GetProcAddress(hModule,s_DoInfInstall_0100a2ac);
        if (pFVar3 == (FARPROC)0x0) {
          FUN_010038cc((HWND)0x0,0x4c9,s_DoInfInstall_0100a2ac,(LPCSTR)0x0,0x10,0);
          FreeLibrary(hModule);
          goto LAB_01005612;
        }
        local_38 = local_8;
        local_30 = local_188;
        local_2c = DAT_0100aa64;
        local_28 = (uint)DAT_0100b898;
        local_40 = 0;
        local_3c = &DAT_0100abb4;
        local_34 = &DAT_0100ac44;
        if (DAT_0100b890 != 0) {
          local_28 = (uint)CONCAT12(1,DAT_0100b898);
        }
        if ((DAT_0100b494 & 8) != 0) {
          local_28 = local_28 | 0x20000;
        }
        if ((DAT_0100b494 & 0x10) != 0) {
          local_28 = local_28 | 0x40000;
        }
        if ((DAT_0100bba8 & 0x40) != 0) {
          local_28 = local_28 | 0x80000;
        }
        if ((char)DAT_0100bba8 < '\0') {
          local_28 = local_28 | 0x100000;
        }
        local_24 = DAT_0100b498;
        DAT_0100aa5c = (*pFVar3)(&local_40);
        if ((int)DAT_0100aa5c < 0) {
          FreeLibrary(hModule);
          goto LAB_0100562c;
        }
        FreeLibrary(hModule);
      }
      else {
LAB_01005495:
        if (local_c != 0) goto LAB_0100549e;
LAB_0100557d:
        iVar4 = FUN_01004560(local_8,&local_84);
        if (iVar4 == 0) {
LAB_0100562c:
          LocalFree(local_8);
          return 0;
        }
      }
      LocalFree(local_8);
      local_10 = local_10 + 1;
    } while (local_10 < 2);
    uVar2 = 1;
    if (DAT_0100a330 != 0) {
      FUN_01001b8b();
    }
  }
  return uVar2;
}



/* VA 01005636 */

bool FUN_01005636(void)

{
  bool bVar1;
  DWORD DVar2;
  LPCSTR lpString1;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined3 extraout_var;
  UINT UVar6;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  INT_PTR IVar7;
  char local_108 [3];
  undefined1 local_105;

  DVar2 = FUN_01002a34("RUNPROGRAM",(undefined4 *)0x0,0);
  lpString1 = LocalAlloc(0x40,DVar2 + 1);
  if (lpString1 == (LPCSTR)0x0) {
    FUN_010038cc((HWND)0x0,0x4b5,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
    DAT_0100aa5c = FUN_01003547();
  }
  else {
    DVar2 = FUN_01002a34("RUNPROGRAM",(undefined4 *)lpString1,DVar2);
    if (DVar2 == 0) {
      FUN_010038cc((HWND)0x0,0x4b1,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
      LocalFree(lpString1);
      DAT_0100aa5c = 0x80070714;
    }
    else {
      iVar4 = lstrcmpA(lpString1,"<None>");
      uVar3 = 1;
      if (iVar4 == 0) {
        DAT_0100b490 = 1;
      }
      LocalFree(lpString1);
      if (DAT_0100b99e == '\0') {
        if ((DAT_0100b884 != 0) || (DAT_0100b490 != 0)) {
          IVar7 = FUN_01004161(DAT_0100b4a4,(LPCSTR)0x7d2,(HWND)0x0,FUN_01004e56,0,0);
          uVar3 = (uint)(IVar7 != 0);
          goto LAB_010058f9;
        }
        DVar2 = GetTempPathA(0x104,&DAT_0100ac44);
        if ((DVar2 != 0) &&
           ((iVar4 = FUN_01004b1a(&DAT_0100ac44,1,3), iVar4 != 0 ||
            ((bVar1 = FUN_01001f6e(&DAT_0100ac44), CONCAT31(extraout_var,bVar1) == 0 &&
             (iVar4 = FUN_01004b1a(&DAT_0100ac44,1,1), iVar4 != 0)))))) goto LAB_010058f9;
        do {
          lstrcpyA(local_108,"A:\\");
          while (local_108[0] < '[') {
            UVar6 = GetDriveTypeA(local_108);
            if (((((UVar6 == 6) || (UVar6 == 3)) &&
                 (DVar2 = GetFileAttributesA(local_108), DVar2 != 0xffffffff)) ||
                (((UVar6 == 2 && (local_108[0] != 'A')) &&
                 ((local_108[0] != 'B' &&
                  ((uVar3 = FUN_01005e13(local_108), uVar3 != 0 && (0x18fff < uVar3)))))))) &&
               ((bVar1 = FUN_01003f0d(local_108,3,0), CONCAT31(extraout_var_00,bVar1) != 0 ||
                ((bVar1 = FUN_01001f6e(local_108), CONCAT31(extraout_var_01,bVar1) == 0 &&
                 (bVar1 = FUN_01003f0d(local_108,1,0), CONCAT31(extraout_var_02,bVar1) != 0)))))) {
              bVar1 = FUN_01001f6e(local_108);
              if (CONCAT31(extraout_var_03,bVar1) != 0) {
                GetWindowsDirectoryA(local_108,0x104);
              }
              FUN_01005b32(local_108,"msdownld.tmp");
              uVar3 = FUN_01001f4b(local_108);
              if (uVar3 == 0) {
                local_108[0] = local_108[0] + '\x01';
                local_105 = 0;
              }
              else {
                SetFileAttributesA(local_108,2);
                lstrcpyA(&DAT_0100ac44,local_108);
                iVar4 = FUN_01004b1a(&DAT_0100ac44,1,0);
                if (iVar4 != 0) {
                  uVar3 = 1;
                  goto LAB_010058f9;
                }
              }
            }
            else {
              local_108[0] = local_108[0] + '\x01';
            }
          }
          GetWindowsDirectoryA(local_108,0x104);
          bVar1 = FUN_01003f0d(local_108,3,4);
        } while (CONCAT31(extraout_var_04,bVar1) != 0);
      }
      else {
        uVar5 = uVar3;
        if ((DAT_0100b99e == '\\') && (DAT_0100b99f == '\\')) {
          uVar5 = 0;
        }
        iVar4 = FUN_01004b1a(&DAT_0100b99e,0,uVar5);
        if (iVar4 != 0) goto LAB_010058f9;
        FUN_010038cc((HWND)0x0,0x4be,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
      }
    }
  }
  uVar3 = 0;
LAB_010058f9:
  return SUB41(uVar3,0);
}



/* VA 010058fe */

undefined4 FUN_010058fe(void)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  BOOL BVar3;

  if (DAT_0100b898 == 0) {
    if (DAT_0100b884 == 0) {
      iVar2 = FUN_01003d9a();
      if (iVar2 == 0) {
        return 0;
      }
      if (DAT_0100b898 != 0) goto LAB_01005935;
    }
    iVar2 = FUN_01004481();
    if (iVar2 == 0) {
      return 0;
    }
  }
LAB_01005935:
  iVar2 = FUN_01003d13();
  if ((iVar2 != 0) && (bVar1 = FUN_01005636(), CONCAT31(extraout_var,bVar1) != 0)) {
    if ((DAT_0100b884 == 0) &&
       ((DAT_0100b490 == 0 && (bVar1 = FUN_01004112(), CONCAT31(extraout_var_00,bVar1) == 0)))) {
      return 0;
    }
    BVar3 = SetCurrentDirectoryA(&DAT_0100ac44);
    if (BVar3 != 0) {
      if ((DAT_0100b88c == 0) && (iVar2 = FUN_01005209(), iVar2 == 0)) {
        return 0;
      }
      if ((DAT_0100bba8 & 0xc0) == 0) {
        DAT_0100ab84 = FUN_01001ef8(DAT_0100aa64);
      }
      else {
        DAT_0100ab84 = 0;
      }
      if (((DAT_0100b884 == 0) && (DAT_0100b490 == 0)) && (iVar2 = FUN_01005288(), iVar2 == 0)) {
        return 0;
      }
      if ((DAT_0100b898 == 0) && (DAT_0100b884 == 0)) {
        FUN_01004657();
      }
      return 1;
    }
    FUN_010038cc((HWND)0x0,0x4bc,(LPCSTR)0x0,(LPCSTR)0x0,0x10,0);
    DAT_0100aa5c = FUN_01003547();
  }
  return 0;
}



/* VA 01005a00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01005a00(HMODULE param_1,undefined4 param_2,char *param_3)

{
  int iVar1;

  DAT_0100aa5c = 0;
  iVar1 = FUN_01004c18(param_1,param_3);
  if (iVar1 != 0) {
    iVar1 = FUN_010058fe();
    FUN_01002eaf();
    if (((iVar1 != 0) && (DAT_0100b89a == '\0')) && ((_DAT_0100b48c & 1) != 0)) {
      FUN_0100263f((byte)_DAT_0100b48c);
    }
  }
  if (DAT_0100aa54 != (HANDLE)0x0) {
    CloseHandle(DAT_0100aa54);
  }
  return DAT_0100aa5c;
}



/* VA 01005a5e */

void entry(void)

{
  char cVar1;
  char *pcVar2;
  HMODULE pHVar3;
  UINT uExitCode;
  undefined4 uVar4;
  _STARTUPINFOA local_48;

  pcVar2 = GetCommandLineA();
  cVar1 = *pcVar2;
  if (cVar1 != '\"') {
    do {
      if (cVar1 < '!') goto LAB_01005a96;
      pcVar2 = pcVar2 + 1;
      cVar1 = *pcVar2;
    } while( true );
  }
  do {
    pcVar2 = pcVar2 + 1;
    if (*pcVar2 == '\0') break;
  } while (*pcVar2 != '\"');
  if (*pcVar2 != '\"') goto LAB_01005a96;
  do {
    pcVar2 = pcVar2 + 1;
LAB_01005a96:
  } while ((*pcVar2 != '\0') && (*pcVar2 < '!'));
  local_48.dwFlags = 0;
  GetStartupInfoA(&local_48);
  uVar4 = 0;
  pHVar3 = GetModuleHandleA((LPCSTR)0x0);
  uExitCode = FUN_01005a00(pHVar3,uVar4,pcVar2);
                    /* WARNING: Subroutine does not return */
  ExitProcess(uExitCode);
}



/* VA 01005ad3 */

bool FUN_01005ad3(short param_1,short param_2)

{
  BOOL BVar1;
  bool bVar2;

  if ((BYTE)param_1 == (BYTE)param_2) {
    BVar1 = IsDBCSLeadByte((BYTE)param_1);
    if (BVar1 == 0) {
      bVar2 = false;
    }
    else {
      bVar2 = param_1 != param_2;
    }
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}



/* VA 01005b00 */

short * FUN_01005b00(short *param_1,short param_2)

{
  bool bVar1;
  undefined3 extraout_var;

  while( true ) {
    if ((char)*param_1 == '\0') {
      return (short *)0x0;
    }
    bVar1 = FUN_01005ad3(*param_1,param_2);
    if (CONCAT31(extraout_var,bVar1) == 0) break;
    param_1 = (short *)CharNextA((LPCSTR)param_1);
  }
  return param_1;
}



/* VA 01005b32 */

void FUN_01005b32(LPCSTR param_1,LPCSTR param_2)

{
  int iVar1;
  LPSTR pCVar2;
  LPSTR lpszCurrent;

  iVar1 = lstrlenA(param_1);
  lpszCurrent = param_1 + iVar1;
  if ((param_1 < lpszCurrent) && (pCVar2 = CharPrevA(param_1,lpszCurrent), *pCVar2 != '\\')) {
    *lpszCurrent = '\\';
    lpszCurrent = lpszCurrent + 1;
  }
  for (; *param_2 == ' '; param_2 = param_2 + 1) {
  }
  lstrcpyA(lpszCurrent,param_2);
  return;
}



/* VA 01005b71 */

undefined4 FUN_01005b71(LPCSTR param_1)

{
  int iVar1;
  LPSTR lpszCurrent;
  LPSTR pCVar2;

  iVar1 = lstrlenA(param_1);
  lpszCurrent = CharPrevA(param_1,param_1 + iVar1);
  do {
    lpszCurrent = CharPrevA(param_1,lpszCurrent);
    if (lpszCurrent <= param_1) {
      if (*lpszCurrent != '\\') {
        return 0;
      }
      break;
    }
  } while (*lpszCurrent != '\\');
  if ((lpszCurrent == param_1) || (pCVar2 = CharPrevA(param_1,lpszCurrent), *pCVar2 == ':')) {
    lpszCurrent = CharNextA(lpszCurrent);
  }
  *lpszCurrent = '\0';
  return 1;
}



/* VA 01005bca */

uint FUN_01005bca(LPCSTR param_1)

{
  DWORD DVar1;
  uint uVar2;

  DVar1 = GetFileAttributesA(param_1);
  if (DVar1 == 0xffffffff) {
    uVar2 = 0;
  }
  else {
    uVar2 = ~(DVar1 >> 4) & 1;
  }
  return uVar2;
}



/* VA 01005be8 */

short * FUN_01005be8(short *param_1,short param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  short *psVar2;

  psVar2 = (short *)0x0;
  for (; (char)*param_1 != '\0'; param_1 = (short *)CharNextA((LPCSTR)param_1)) {
    bVar1 = FUN_01005ad3(*param_1,param_2);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      psVar2 = param_1;
    }
  }
  return psVar2;
}



/* VA 01005c1c */

bool FUN_01005c1c(LPCSTR param_1,int *param_2)

{
  LPCSTR lpsz;
  char cVar1;
  int iVar2;
  int iVar3;

  iVar3 = 0;
  lpsz = param_1;
  do {
    cVar1 = *lpsz;
    if ((cVar1 < '0') || ('9' < cVar1)) {
      if ('`' < cVar1) {
        cVar1 = cVar1 + -0x20;
      }
      iVar2 = cVar1 + -0x37;
      if ((iVar2 < 10) || (0xf < iVar2)) {
        *param_2 = iVar3;
        return lpsz != param_1;
      }
    }
    else {
      iVar3 = iVar3 + -3;
      iVar2 = (int)cVar1;
    }
    iVar3 = iVar3 * 0x10 + iVar2;
    lpsz = CharNextA(lpsz);
  } while( true );
}



/* VA 01005c9f */

undefined4 FUN_01005c9f(HMODULE param_1,LPCSTR param_2,LPCSTR param_3,undefined2 param_4)

{
  undefined2 local_10 [2];
  undefined4 local_c;
  LPCSTR local_8;

  local_c = 0;
  local_10[0] = param_4;
  local_8 = param_2;
  EnumResourceLanguagesA(param_1,param_2,param_3,(ENUMRESLANGPROCA)&LAB_01005c72,(LONG_PTR)local_10)
  ;
  return local_c;
}



/* VA 01005cd4 */

int FUN_01005cd4(HMODULE param_1,LPCSTR param_2,LPCSTR param_3)

{
  int iVar1;

  if (DAT_0100a2c8 == -2) {
    DAT_0100a2c8 = 0;
    iVar1 = FUN_01005c9f(param_1,param_2,param_3,1);
    if ((iVar1 == 0) && (iVar1 = FUN_01005c9f(param_1,param_2,param_3,0xd), iVar1 == 0)) {
      return DAT_0100a2c8;
    }
    DAT_0100a2c8 = 1;
  }
  return DAT_0100a2c8;
}



/* VA 01005d22 */

int FUN_01005d22(void)

{
  bool bVar1;
  BOOL BVar2;
  int iVar3;
  LSTATUS LVar4;
  undefined3 extraout_var;
  _OSVERSIONINFOA local_b4;
  BYTE local_20 [12];
  DWORD local_14 [2];
  HKEY local_c;
  uint local_8;

  local_8 = 0;
  local_14[1] = 0xc;
  if (DAT_0100a2cc == -2) {
    DAT_0100a2cc = 0;
    local_b4.dwOSVersionInfoSize = 0x94;
    BVar2 = GetVersionExA(&local_b4);
    if ((((BVar2 != 0) && (local_b4.dwPlatformId == 1)) && (local_b4.dwMajorVersion == 4)) &&
       (local_b4.dwMinorVersion < 10)) {
      iVar3 = GetSystemMetrics(0x4a);
      if (iVar3 != 0) {
        LVar4 = RegOpenKeyExA((HKEY)0x80000001,"Control Panel\\Desktop\\ResourceLocale",0,0x20019,
                              &local_c);
        if (LVar4 == 0) {
          LVar4 = RegQueryValueExA(local_c,"",(LPDWORD)0x0,local_14,local_20,local_14 + 1);
          RegCloseKey(local_c);
          if (LVar4 == 0) {
            bVar1 = FUN_01005c1c((LPCSTR)local_20,(int *)&local_8);
            if ((CONCAT31(extraout_var,bVar1) != 0) &&
               (((local_8 & 0x3ff) == 1 || ((local_8 & 0x3ff) == 0xd)))) {
              DAT_0100a2cc = 1;
            }
          }
        }
      }
    }
  }
  return DAT_0100a2cc;
}



/* VA 01005e13 */

int FUN_01005e13(LPCSTR param_1)

{
  BOOL BVar1;
  int iVar2;
  DWORD local_14;
  DWORD local_10;
  DWORD local_c;
  DWORD local_8;

  local_c = 0;
  local_8 = 0;
  local_10 = 0;
  local_14 = 0;
  if ((*param_1 != '\0') &&
     (BVar1 = GetDiskFreeSpaceA(param_1,&local_c,&local_8,&local_10,&local_14), BVar1 != 0)) {
    iVar2 = MulDiv(local_8 * local_c,local_10,0x400);
    return iVar2;
  }
  return 0;
}



/* VA 01005e67 */

void FUN_01005e67(LPCSTR param_1,int *param_2)

{
  BOOL BVar1;
  int nNumber;
  DWORD local_14;
  DWORD local_10;
  DWORD local_c;
  DWORD local_8;

  local_c = 0;
  local_8 = 0;
  local_10 = 0;
  local_14 = 0;
  BVar1 = GetDiskFreeSpaceA(param_1,&local_c,&local_8,&local_10,&local_14);
  if (BVar1 != 0) {
    nNumber = local_8 * local_c;
    MulDiv(nNumber,local_10,0x400);
    if (param_2 != (int *)0x0) {
      *param_2 = nNumber;
    }
  }
  return;
}



/* VA 01005ebf */

/* Library Function - Single Match
    _FDICreate

   Library: Visual Studio 2005 Release */

undefined4 * __cdecl
_FDICreate(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined4 *param_9)

{
  undefined4 *puVar1;

  puVar1 = (undefined4 *)(*(code *)param_1)(0x804);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_01007068(param_9,5,0);
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[0x22] = 0xffffffff;
    puVar1[0x21] = 0xffffffff;
    puVar1[1] = param_2;
    puVar1[3] = param_3;
    puVar1[4] = param_4;
    puVar1[5] = param_5;
    puVar1[6] = param_6;
    puVar1[7] = param_7;
    puVar1[8] = param_8;
    puVar1[0x12] = 0;
    puVar1[0x11] = 0;
    puVar1[0x13] = 0;
    puVar1[2] = param_1;
    *puVar1 = param_9;
    *(undefined2 *)((int)puVar1 + 0xb2) = 0xf;
    puVar1[0x28] = 0xffff;
    puVar1[0x2a] = 0xffff;
    puVar1[0x29] = 0xffff;
  }
  return puVar1;
}



/* VA 01005f4f */

/* Library Function - Single Match
    _FDIIsCabinet

   Library: Visual Studio 2005 Release */

undefined4 __cdecl _FDIIsCabinet(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int local_28 [2];
  undefined4 local_20;
  ushort local_10;
  undefined2 local_e;
  undefined2 local_c;
  ushort local_a;
  undefined2 local_8;
  undefined2 local_6;

  iVar1 = (*(code *)param_1[4])(param_2,local_28,0x24);
  if ((iVar1 == 0x24) && (local_28[0] == 0x4643534d)) {
    if (local_10 == 0x103) {
      *param_3 = local_20;
      *(undefined2 *)(param_3 + 1) = local_e;
      *(undefined2 *)((int)param_3 + 6) = local_c;
      *(undefined2 *)(param_3 + 2) = local_8;
      *(undefined2 *)((int)param_3 + 10) = local_6;
      param_3[3] = local_a >> 2 & 1;
      param_3[4] = local_a & 1;
      param_3[5] = local_a & 2;
      return 1;
    }
    FUN_01007068((undefined4 *)*param_1,3,(uint)local_10);
  }
  return 0;
}



/* VA 01005fdb */

undefined4 FUN_01005fdb(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;

  param_1[0x1f0] = (int)param_1 + 0x3b7;
  param_1[0x1f1] = param_1 + 0x12e;
  param_1[0x1f2] = (int)param_1 + 0x5b9;
  param_1[499] = param_1[0xe];
  *(undefined2 *)((int)param_1 + 0x7da) = *(undefined2 *)(param_1 + 0x1c);
  *(undefined2 *)(param_1 + 0x1f7) = *(undefined2 *)((int)param_1 + 0x72);
  iVar1 = (*(code *)param_1[9])(0,param_1 + 0x1ef);
  if (iVar1 == -1) {
LAB_01006064:
    FUN_01007068((undefined4 *)*param_1,0xb,0);
    uVar2 = 0;
  }
  else {
    if (param_1[10] != 0) {
      param_1[0x1f9] = 0;
      param_1[0x1fa] = param_1[0xe];
      param_1[0x1fb] = param_1[0x13];
      *(undefined2 *)(param_1 + 0x1fc) = *(undefined2 *)(param_1 + 0x28);
      *(undefined2 *)((int)param_1 + 0x7f2) = *(undefined2 *)(param_1 + 0x1c);
      param_1[0x1fd] = (uint)*(ushort *)((int)param_1 + 0x72);
      iVar1 = (*(code *)param_1[10])(param_1 + 0x1f9);
      if (iVar1 == -1) goto LAB_01006064;
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* VA 0100607b */

undefined4 FUN_0100607b(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 uVar5;

  iVar1 = (*(code *)param_1[4])(param_1[0x21],param_1[0x12],param_1[0x2a]);
  if ((param_1[0x2a] == iVar1) &&
     ((uint)*(ushort *)(param_1[0x12] + 4) + param_2 <= (uint)param_1[0x26])) {
    puVar4 = (uint *)param_1[0x12];
    uVar2 = (uint)(ushort)puVar4[1];
    uVar3 = (*(code *)param_1[4])(param_1[0x21],param_1[0xf] + param_2,uVar2);
    if (uVar2 == uVar3) {
      if (*puVar4 != 0) {
        uVar2 = FUN_01007083((uint *)(param_1[0xf] + param_2),uVar2,0);
        uVar2 = FUN_01007083((uint *)(param_1[0x12] + 4),param_1[0x2a] - 4,uVar2);
        puVar4 = (uint *)param_1[0x12];
        if (uVar2 != *puVar4) goto LAB_01006199;
      }
      *(short *)(puVar4 + 1) = (short)puVar4[1] + (short)param_2;
      if ((param_2 == 0) && (*(short *)(param_1[0x12] + 6) != 0)) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
      if (param_1[10] == 0) {
        return 1;
      }
      param_1[0x1f9] = 2;
      param_1[0x1fa] = param_1[0xe];
      *(short *)(param_1 + 0x1fc) = *(short *)(param_1 + 0x2a) + -8;
      if ((short)(*(short *)(param_1 + 0x2a) + -8) == 0) {
        param_1[0x1fb] = 0;
      }
      else {
        param_1[0x1fb] = param_1[0x12] + 8;
      }
      param_1[0x1fd] = param_1[0xf] + param_2;
      *(undefined2 *)(param_1 + 0x1fe) = *(undefined2 *)(param_1[0x12] + 4);
      param_1[0x1ff] = uVar5;
      *(short *)(param_1 + 0x200) = (short)param_2;
      iVar1 = (*(code *)param_1[10])(param_1 + 0x1f9);
      if (iVar1 != -1) {
        return 1;
      }
      uVar5 = 0xb;
      goto LAB_0100619d;
    }
  }
LAB_01006199:
  uVar5 = 4;
LAB_0100619d:
  FUN_01007068((undefined4 *)*param_1,uVar5,0);
  return 0;
}



/* VA 010061ad */

undefined4 FUN_010061ad(char *param_1,int param_2,undefined4 *param_3)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;

  iVar4 = (*(code *)param_3[7])(param_3[0x22],0,1);
  iVar5 = (*(code *)param_3[4])(param_3[0x22],param_1,param_2);
  if (0 < iVar5) {
    cVar2 = param_1[param_2 + -1];
    param_1[param_2 + -1] = '\0';
    pcVar1 = param_1 + 1;
    do {
      cVar3 = *param_1;
      param_1 = param_1 + 1;
    } while (cVar3 != '\0');
    if ((((int)(param_1 + (1 - (int)pcVar1)) < param_2) || (cVar2 == '\0')) &&
       (iVar4 = (*(code *)param_3[7])(param_3[0x22],param_1 + iVar4 + (1 - (int)pcVar1),0),
       iVar4 != -1)) {
      return 1;
    }
  }
  FUN_01007068((undefined4 *)*param_3,4,0);
  return 0;
}



/* VA 01006234 */

undefined4 FUN_01006234(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;

  iVar2 = (*(code *)param_1[7])(param_1[0x22],0,1);
  if (iVar2 == -1) {
    FUN_01007068((undefined4 *)*param_1,4,0);
    uVar3 = 0;
  }
  else {
    *(undefined2 *)((int)param_1 + 0x7de) = *(undefined2 *)(param_1 + 0x2b);
    piVar1 = param_1 + 0x1ef;
    *(undefined2 *)((int)param_1 + 0x7da) = *(undefined2 *)(param_1 + 0x1c);
    *piVar1 = iVar2;
    param_1[499] = param_1[0xe];
    iVar4 = (*(code *)param_1[9])(5,piVar1);
    if ((iVar4 == -1) ||
       (((*(short *)(param_1 + 0x2b) = *(short *)((int)param_1 + 0x7de),
         *(short *)((int)param_1 + 0x7de) != 0 && (*piVar1 != iVar2)) &&
        (iVar2 = (*(code *)param_1[7])(param_1[0x22],*piVar1,0), iVar2 == -1)))) {
      FUN_01007068((undefined4 *)*param_1,0xb,0);
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}



/* VA 010062dd */

undefined4 FUN_010062dd(undefined4 *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;

  bVar1 = *(byte *)((int)param_1 + 0xb2) & 0xf;
  if ((*(byte *)((int)param_1 + 0xb2) & 0xf) != 0) {
    if (bVar1 == 1) {
      iVar2 = FUN_01003772();
    }
    else if (bVar1 == 2) {
      iVar2 = FUN_01003772();
    }
    else {
      if (bVar1 != 3) {
        if (bVar1 == 0xf) {
          return 1;
        }
        uVar3 = 6;
        goto LAB_01006305;
      }
      iVar2 = FUN_0100720e((int *)param_1[0xd]);
    }
    if (iVar2 != 0) {
      uVar3 = 7;
LAB_01006305:
      FUN_01007068((undefined4 *)*param_1,uVar3,0);
      return 0;
    }
  }
  (*(code *)param_1[1])(param_1[0xf]);
  (*(code *)param_1[1])(param_1[0x10]);
  return 1;
}



/* VA 0100634c */

/* Library Function - Single Match
    _MDICreateDecompressionGlobal@4

   Library: Visual Studio 2005 Release */

undefined4 _MDICreateDecompressionGlobal_4(undefined4 *param_1)

{
  ushort uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint local_14 [2];
  uint local_c;
  undefined4 local_8;

  uVar1 = *(ushort *)((int)param_1 + 0xb2);
  uVar3 = uVar1 & 0xf;
  param_1[0x25] = 0x8000;
  if ((uVar1 & 0xf) == 0) {
    param_1[0x26] = 0x8000;
  }
  else {
    if (uVar3 == 1) {
      iVar4 = FUN_0100376f();
    }
    else if (uVar3 == 2) {
      local_8 = param_1[8];
      local_c = uVar1 >> 8 & 0x1f;
      iVar4 = FUN_0100376f();
    }
    else {
      if (uVar3 != 3) {
        if (uVar3 == 0xf) {
          return 1;
        }
        iVar4 = 6;
        goto LAB_010064ef;
      }
      local_14[0] = 1 << ((byte)(uVar1 >> 8) & 0x1f);
      iVar4 = FUN_010070e6(param_1 + 0x25,local_14,(undefined *)0x0,(undefined *)0x0,param_1 + 0x26,
                           (undefined4 *)0x0,0,0,0,0,0);
    }
    if (iVar4 != 0) {
      iVar4 = 7;
      goto LAB_010064ef;
    }
  }
  iVar4 = (*(code *)param_1[2])(param_1[0x26]);
  param_1[0xf] = iVar4;
  if (iVar4 != 0) {
    iVar4 = (*(code *)param_1[2])(param_1[0x25]);
    param_1[0x10] = iVar4;
    if (iVar4 != 0) {
      bVar2 = *(byte *)((int)param_1 + 0xb2) & 0xf;
      if (bVar2 == 1) {
        iVar4 = FUN_0100376f();
      }
      else if (bVar2 == 2) {
        iVar4 = FUN_0100376f();
      }
      else {
        if (bVar2 != 3) {
          return 1;
        }
        iVar4 = FUN_010070e6(param_1 + 0x25,local_14,(undefined *)param_1[2],(undefined *)param_1[1]
                             ,param_1 + 0x26,param_1 + 0xd,param_1[3],param_1[4],param_1[5],
                             param_1[6],param_1[7]);
      }
      if (iVar4 == 0) {
        return 1;
      }
      iVar4 = (uint)(iVar4 != 1) * 2 + 5;
      (*(code *)param_1[1])(param_1[0xf]);
      (*(code *)param_1[1])(param_1[0x10]);
      goto LAB_010064ef;
    }
    (*(code *)param_1[1])(param_1[0xf]);
  }
  iVar4 = 5;
LAB_010064ef:
  FUN_01007068((undefined4 *)*param_1,iVar4,0);
  *(undefined2 *)((int)param_1 + 0xb2) = 0xf;
  return 0;
}



/* VA 0100650d */

undefined4 FUN_0100650d(undefined4 *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;

  bVar1 = *(byte *)((int)param_1 + 0xb2) & 0xf;
  if ((*(byte *)((int)param_1 + 0xb2) & 0xf) == 0) {
LAB_01006566:
    uVar3 = 1;
  }
  else {
    if (bVar1 == 1) {
      iVar2 = FUN_01003772();
LAB_0100655c:
      if (iVar2 == 0) goto LAB_01006566;
      uVar3 = 7;
    }
    else {
      if (bVar1 == 2) {
        iVar2 = FUN_01003772();
        goto LAB_0100655c;
      }
      if (bVar1 == 3) {
        iVar2 = FUN_010071f3((int *)param_1[0xd]);
        goto LAB_0100655c;
      }
      if (bVar1 == 0xf) goto LAB_01006566;
      uVar3 = 6;
    }
    FUN_01007068((undefined4 *)*param_1,uVar3,0);
    uVar3 = 0;
  }
  return uVar3;
}



/* VA 0100656e */

undefined4 FUN_0100656e(undefined4 *param_1,ushort *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  ushort uVar4;
  ushort *puVar5;
  byte bVar6;
  undefined3 extraout_var;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 uVar11;

  puVar5 = param_2;
  puVar9 = param_1;
  bVar6 = *(byte *)((int)param_1 + 0xb2) & 0xf;
  if ((*(byte *)((int)param_1 + 0xb2) & 0xf) == 0) {
    uVar4 = *(ushort *)(param_1[0x12] + 4);
    *param_2 = uVar4;
    puVar9 = (undefined4 *)param_1[0xf];
    puVar10 = (undefined4 *)param_1[0x10];
    for (uVar8 = (uint)(uVar4 >> 2); uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    for (uVar8 = uVar4 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    return 1;
  }
  if (bVar6 == 1) {
    param_1 = (undefined4 *)param_1[0x25];
    iVar7 = FUN_01003772();
    if (iVar7 == 0) {
      *param_2 = (ushort)param_1;
      return 1;
    }
  }
  else {
    if (bVar6 == 2) {
      param_1 = (undefined4 *)(uint)*param_2;
      iVar7 = FUN_01003772();
    }
    else {
      if (bVar6 != 3) {
        uVar11 = 6;
        goto LAB_01006598;
      }
      piVar1 = param_1 + 0x12;
      piVar2 = param_1 + 0x10;
      piVar3 = param_1 + 0xf;
      puVar10 = param_1 + 0xd;
      param_1 = (undefined4 *)(uint)*param_2;
      bVar6 = _LDIDecompress((int *)*puVar10,*piVar3,(uint)*(ushort *)(*piVar1 + 4),*piVar2,&param_1
                            );
      iVar7 = CONCAT31(extraout_var,bVar6);
    }
    if (iVar7 == 0) {
      *puVar5 = (ushort)param_1;
      return 1;
    }
  }
  uVar11 = 7;
LAB_01006598:
  FUN_01007068((undefined4 *)*puVar9,uVar11,0);
  return 0;
}



/* VA 0100666d */

bool FUN_0100666d(undefined4 *param_1,char *param_2,short param_3,short param_4)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  int local_28 [6];
  ushort local_10;
  short local_8;
  short local_6;

  puVar2 = param_1;
  pcVar3 = (char *)((int)param_1 + 0x5b9);
  iVar6 = 0x6ba - (int)pcVar3;
  do {
    cVar1 = *pcVar3;
    pcVar3[(int)param_1 + iVar6] = cVar1;
    pcVar3 = pcVar3 + 1;
    pcVar4 = param_2;
  } while (cVar1 != '\0');
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar5 = (int)pcVar4 - (int)param_2;
  pcVar3 = (char *)((int)param_1 + 0x6b9);
  do {
    pcVar4 = pcVar3 + 1;
    pcVar3 = pcVar3 + 1;
  } while (*pcVar4 != '\0');
  pcVar4 = param_2;
  for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar3 = pcVar3 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar3 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar3 = pcVar3 + 1;
  }
  iVar6 = (*(code *)param_1[3])((int)param_1 + 0x6ba,0x8000,0x180);
  puVar2[0x22] = iVar6;
  if (iVar6 != -1) {
    iVar6 = (*(code *)puVar2[3])((int)puVar2 + 0x6ba,0x8000,0x180);
    puVar2[0x21] = iVar6;
    if (iVar6 != -1) {
      iVar6 = (*(code *)puVar2[4])(puVar2[0x22],local_28,0x24);
      if ((iVar6 != 0x24) || (local_28[0] != 0x4643534d)) {
LAB_010067ee:
        uVar5 = 0;
        uVar10 = 2;
        goto LAB_01006921;
      }
      if (local_10 != 0x103) {
        uVar5 = (uint)local_10;
        uVar10 = 3;
        goto LAB_01006921;
      }
      if ((param_4 != -1) && ((param_3 != local_8 || (param_4 != local_6)))) {
        uVar5 = 0;
        uVar10 = 10;
        goto LAB_01006921;
      }
      piVar8 = local_28;
      piVar9 = puVar2 + 0x14;
      for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar9 = *piVar8;
        piVar8 = piVar8 + 1;
        piVar9 = piVar9 + 1;
      }
      param_1 = (undefined4 *)0x0;
      if (((*(byte *)((int)puVar2 + 0x6e) & 4) != 0) &&
         (iVar6 = (*(code *)puVar2[4])(puVar2[0x22],&param_1,4), iVar6 != 4)) goto LAB_010067ee;
      if (puVar2[0x28] != ((uint)param_1 & 0xffff)) {
        if (puVar2[0x13] != 0) {
          (*(code *)puVar2[1])(puVar2[0x13]);
          puVar2[0x13] = 0;
        }
        uVar5 = (uint)param_1 & 0xffff;
        puVar2[0x28] = uVar5;
        if (uVar5 == 0) goto LAB_010067cb;
        iVar6 = (*(code *)puVar2[2])(uVar5);
        puVar2[0x13] = iVar6;
        if (iVar6 != 0) goto LAB_010067cb;
LAB_0100683b:
        uVar5 = 0;
        uVar10 = 5;
        goto LAB_01006921;
      }
LAB_010067cb:
      if ((puVar2[0x28] != 0) &&
         (iVar6 = (*(code *)puVar2[4])(puVar2[0x22],puVar2[0x13],puVar2[0x28]),
         puVar2[0x28] != iVar6)) goto LAB_010067ee;
      iVar6 = ((uint)param_1 >> 0x10 & 0xff) + 8;
      if (puVar2[0x11] == 0) {
        puVar2[0x29] = iVar6;
        iVar6 = (*(code *)puVar2[2])(iVar6);
        puVar2[0x11] = iVar6;
        if (iVar6 == 0) goto LAB_0100683b;
LAB_0100681d:
        iVar6 = ((uint)param_1 >> 0x18) + 8;
        if (puVar2[0x12] == 0) {
          puVar2[0x2a] = iVar6;
          iVar6 = (*(code *)puVar2[2])(iVar6);
          puVar2[0x12] = iVar6;
          if (iVar6 == 0) goto LAB_0100683b;
        }
        else if (iVar6 != puVar2[0x2a]) goto LAB_0100684b;
        if ((*(byte *)((int)puVar2 + 0x6e) & 1) == 0) {
          *(undefined1 *)((int)puVar2 + 0x1b5) = 0;
          *(undefined1 *)((int)puVar2 + 0x2b6) = 0;
        }
        else {
          iVar6 = FUN_010061ad((char *)((int)puVar2 + 0x1b5),0x100,puVar2);
          if (iVar6 == 0) {
            return false;
          }
          iVar6 = FUN_010061ad((char *)((int)puVar2 + 0x2b6),0x100,puVar2);
          if (iVar6 == 0) {
            return false;
          }
        }
        if ((*(byte *)((int)puVar2 + 0x6e) & 2) == 0) {
          *(undefined1 *)((int)puVar2 + 0x3b7) = 0;
          *(undefined1 *)(puVar2 + 0x12e) = 0;
        }
        else {
          iVar6 = FUN_010061ad((char *)((int)puVar2 + 0x3b7),0x100,puVar2);
          if (iVar6 == 0) {
            return false;
          }
          iVar6 = FUN_010061ad((char *)(puVar2 + 0x12e),0x100,puVar2);
          if (iVar6 == 0) {
            return false;
          }
        }
        iVar6 = (*(code *)puVar2[7])(puVar2[0x22],0,1);
        puVar2[0xb] = iVar6;
        if ((iVar6 != -1) && (iVar6 = (*(code *)puVar2[7])(puVar2[0x22],puVar2[0x18]), iVar6 != -1))
        {
          *(undefined2 *)(puVar2 + 0x2b) = *(undefined2 *)(puVar2 + 0x1b);
          iVar6 = FUN_01005fdb(puVar2);
          return iVar6 != 0;
        }
        uVar5 = 0;
        uVar10 = 4;
      }
      else {
        if (iVar6 == puVar2[0x29]) goto LAB_0100681d;
LAB_0100684b:
        uVar5 = 0;
        uVar10 = 9;
      }
      goto LAB_01006921;
    }
  }
  uVar5 = 0;
  uVar10 = 1;
LAB_01006921:
  FUN_01007068((undefined4 *)*puVar2,uVar10,uVar5);
  return false;
}



/* VA 01006931 */

undefined4 FUN_01006931(undefined4 *param_1)

{
  int iVar1;

  iVar1 = (*(code *)param_1[4])(param_1[0x22],param_1 + 0x1d,0x10);
  if ((iVar1 == 0x10) && (iVar1 = FUN_010061ad((char *)(param_1 + 0x2d),0x100,param_1), iVar1 != 0))
  {
    return 1;
  }
  FUN_01007068((undefined4 *)*param_1,4,0);
  return 0;
}



/* VA 01006979 */

bool FUN_01006979(short param_1,undefined4 *param_2)

{
  int iVar1;
  bool bVar2;

  if (param_1 == *(short *)((int)param_2 + 0xb2)) {
    bVar2 = true;
  }
  else {
    iVar1 = FUN_010062dd(param_2);
    if (iVar1 == 0) {
      FUN_01007068((undefined4 *)*param_2,7,0);
      bVar2 = false;
    }
    else {
      *(short *)((int)param_2 + 0xb2) = param_1;
      iVar1 = _MDICreateDecompressionGlobal_4(param_2);
      bVar2 = iVar1 != 0;
    }
  }
  return bVar2;
}



/* VA 010069c2 */

undefined4 __cdecl FUN_010069c2(undefined4 *param_1)

{
  FUN_01006979(0xf,param_1);
  if (param_1[0x13] != 0) {
    (*(code *)param_1[1])(param_1[0x13]);
  }
  if (param_1[0x11] != 0) {
    (*(code *)param_1[1])(param_1[0x11]);
  }
  if (param_1[0x12] != 0) {
    (*(code *)param_1[1])(param_1[0x12]);
  }
  if (param_1[0x22] != -1) {
    (*(code *)param_1[6])(param_1[0x22]);
  }
  if (param_1[0x21] != -1) {
    (*(code *)param_1[6])(param_1[0x21]);
  }
  (*(code *)param_1[1])(param_1);
  return 1;
}



/* VA 01006a1d */

undefined4 FUN_01006a1d(undefined4 *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 uVar3;

  param_1[0x24] = param_2;
  iVar2 = (*(code *)param_1[7])(param_1[0x21],param_1[0x29] * param_2 + param_1[0xb],0);
  if (((iVar2 == -1) ||
      (iVar2 = (*(code *)param_1[4])(param_1[0x21],param_1[0x11],param_1[0x29]),
      param_1[0x29] != iVar2)) ||
     (iVar2 = (*(code *)param_1[7])(param_1[0x21],*(undefined4 *)param_1[0x11],0), iVar2 == -1)) {
    uVar3 = 4;
  }
  else {
    *(undefined2 *)(param_1 + 0x2c) = *(undefined2 *)(param_1[0x11] + 4);
    bVar1 = FUN_01006979(*(short *)(param_1[0x11] + 6),param_1);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      return 0;
    }
    if (param_1[10] == 0) {
      return 1;
    }
    param_1[0x1f9] = 1;
    param_1[0x1fa] = param_1[0xe];
    *(short *)(param_1 + 0x1fc) = *(short *)(param_1 + 0x29) + -8;
    if ((short)(*(short *)(param_1 + 0x29) + -8) == 0) {
      param_1[0x1fb] = 0;
    }
    else {
      param_1[0x1fb] = param_1[0x11] + 8;
    }
    *(short *)((int)param_1 + 0x7f2) = (short)param_2;
    iVar2 = (*(code *)param_1[10])(param_1 + 0x1f9);
    if (iVar2 != -1) {
      return 1;
    }
    uVar3 = 0xb;
  }
  FUN_01007068((undefined4 *)*param_1,uVar3,0);
  return 0;
}



/* VA 01006b0c */

undefined4 FUN_01006b0c(undefined4 *param_1)

{
  short sVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined3 extraout_var;
  short sVar5;
  undefined4 uVar6;

  sVar1 = *(short *)(param_1 + 0x1c);
  param_1[0x1f0] = (int)param_1 + 0x3b7;
  param_1[0x1f1] = param_1 + 0x12e;
  sVar5 = *(short *)((int)param_1 + 0x72) + 1;
  param_1[0x1f2] = (int)param_1 + 0x5b9;
  param_1[0x1f8] = 0;
  param_1[499] = param_1[0xe];
  *(short *)((int)param_1 + 0x7da) = sVar1;
  *(short *)(param_1 + 0x1f7) = sVar5;
  while( true ) {
    bVar2 = false;
    if ((param_1[0x21] != -1) && (iVar4 = (*(code *)param_1[6])(param_1[0x21]), iVar4 != 0)) break;
    iVar4 = param_1[0x22];
    if ((iVar4 != -1) && (iVar4 = (*(code *)param_1[6])(iVar4), iVar4 != 0)) break;
    param_1[0x22] = -1;
    param_1[0x21] = 0xffffffff;
    iVar4 = (*(code *)param_1[9])(4,param_1 + 0x1ef);
    if (iVar4 == -1) {
      uVar6 = 0xb;
      goto LAB_01006bf4;
    }
    bVar3 = FUN_0100666d(param_1,(char *)((int)param_1 + 0x3b7),sVar1,sVar5);
    if ((CONCAT31(extraout_var,bVar3) == 0) || (iVar4 = FUN_01006a1d(param_1,0), iVar4 == 0)) {
      if (*(int *)*param_1 == 0xb) {
        return 0;
      }
      bVar2 = true;
    }
    param_1[0x1f8] = *(undefined4 *)*param_1;
    if (!bVar2) {
      *(short *)((int)param_1 + 0xae) = *(short *)((int)param_1 + 0xae) + 1;
      do {
        if (*(short *)((int)param_1 + 0xae) == 0) {
          param_1[0x27] = 1;
          return 1;
        }
        *(short *)(param_1 + 0x2b) = *(short *)(param_1 + 0x2b) + -1;
        *(short *)((int)param_1 + 0xae) = *(short *)((int)param_1 + 0xae) + -1;
        iVar4 = FUN_01006931(param_1);
      } while (iVar4 != 0);
      return 0;
    }
  }
  uVar6 = 4;
LAB_01006bf4:
  FUN_01007068((undefined4 *)*param_1,uVar6,0);
  return 0;
}



/* VA 01006c37 */

/* Library Function - Single Match
    _FDIGetDataBlock@4

   Library: Visual Studio 2005 Release */

undefined4 _FDIGetDataBlock_4(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;

  puVar1 = param_1;
  param_1[0xc] = param_1[0xc] + (uint)*(ushort *)(param_1[0x12] + 6);
  if ((*(short *)(param_1 + 0x2c) != 0) || (iVar2 = FUN_01006b0c(param_1), iVar2 != 0)) {
    *(short *)(puVar1 + 0x2c) = *(short *)(puVar1 + 0x2c) + -1;
    iVar2 = FUN_0100607b(puVar1,0);
    if (iVar2 != 0) {
      if (*(short *)(puVar1[0x12] + 6) == 0) {
        iVar2 = FUN_01006b0c(puVar1);
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = FUN_0100607b(puVar1,(uint)*(ushort *)(puVar1[0x12] + 4));
        if (iVar2 == 0) {
          return 0;
        }
        *(short *)(puVar1 + 0x2c) = *(short *)(puVar1 + 0x2c) + -1;
      }
      param_1 = (undefined4 *)(uint)*(ushort *)(puVar1[0x12] + 6);
      iVar2 = FUN_0100656e(puVar1,(ushort *)&param_1);
      if (iVar2 != 0) {
        if ((short)param_1 == *(short *)(puVar1[0x12] + 6)) {
          return 1;
        }
        FUN_01007068((undefined4 *)*puVar1,7,0);
      }
    }
  }
  return 0;
}



/* VA 01006cd8 */

undefined4 FUN_01006cd8(undefined4 *param_1,uint param_2)

{
  int iVar1;

  if (param_1[0x27] == 0) {
    if ((param_2 & 0xfffe) == 0xfffe) {
      param_2 = *(ushort *)((int)param_1 + 0x6a) - 1;
    }
    if (param_1[0x24] != param_2) {
      iVar1 = FUN_0100650d(param_1);
      if (((iVar1 == 0) || (iVar1 = FUN_01006a1d(param_1,param_2), iVar1 == 0)) ||
         (iVar1 = _FDIGetDataBlock_4(param_1), iVar1 == 0)) {
        return 0;
      }
      param_1[0xc] = 0;
    }
  }
  return 1;
}



/* VA 01006d39 */

/* Library Function - Single Match
    _FDIGetFile@4

   Library: Visual Studio 2005 Release */

undefined4 _FDIGetFile_4(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;

  puVar1 = param_1;
  puVar5 = (undefined4 *)param_1[0x1d];
  if (puVar5 == (undefined4 *)0x0) {
LAB_01006df4:
    puVar5 = puVar1 + 0x1ef;
    puVar1[0x1f0] = puVar1 + 0x2d;
    puVar1[500] = puVar1[0x23];
    *(undefined2 *)(puVar1 + 0x1f5) = *(undefined2 *)((int)puVar1 + 0x7e);
    *(undefined2 *)((int)puVar1 + 0x7d6) = *(undefined2 *)(puVar1 + 0x20);
    *(undefined2 *)(puVar1 + 0x1f6) = *(undefined2 *)((int)puVar1 + 0x82);
    puVar1[499] = puVar1[0xe];
    *puVar5 = 0;
    *(undefined2 *)((int)puVar1 + 0x7de) = *(undefined2 *)(puVar1 + 0x1f);
    if ((*(ushort *)(puVar1 + 0x1f6) & 0x40) != 0) {
      *puVar5 = 1;
      *(ushort *)(puVar1 + 0x1f6) = *(ushort *)(puVar1 + 0x1f6) & 0xffbf;
    }
    iVar2 = (*(code *)puVar1[9])(3,puVar5);
    puVar1[0x23] = 0xffffffff;
    if (iVar2 == -1) {
      uVar6 = 0xb;
    }
    else {
      if (iVar2 != 0) {
        return 1;
      }
      uVar6 = 8;
    }
    FUN_01007068((undefined4 *)*puVar1,uVar6,0);
    return 0;
  }
  uVar4 = param_1[0x1e];
  if (uVar4 < (uint)param_1[0xc]) {
    param_1[0x24] = 0xffff;
  }
  iVar2 = FUN_01006cd8(param_1,(uint)*(ushort *)(param_1 + 0x1f));
  while (iVar2 != 0) {
    if (uVar4 < (uint)*(ushort *)(param_1[0x12] + 6) + param_1[0xc]) {
      param_1 = puVar5;
      if (puVar5 == (undefined4 *)0x0) goto LAB_01006df4;
      goto LAB_01006d8d;
    }
    iVar2 = _FDIGetDataBlock_4(param_1);
  }
  goto LAB_01006dd8;
  while( true ) {
    uVar4 = uVar4 + (int)puVar5;
    param_1 = (undefined4 *)((int)param_1 - (int)puVar5);
    if (param_1 == (undefined4 *)0x0) goto LAB_01006df4;
    iVar2 = _FDIGetDataBlock_4(puVar1);
    if (iVar2 == 0) break;
LAB_01006d8d:
    puVar5 = (undefined4 *)((uint)*(ushort *)(puVar1[0x12] + 6) - (uVar4 - puVar1[0xc]));
    if (param_1 < puVar5) {
      puVar5 = param_1;
    }
    puVar3 = (undefined4 *)
             (*(code *)puVar1[5])(puVar1[0x23],puVar1[0x10] + (uVar4 - puVar1[0xc]),puVar5);
    if (puVar5 != puVar3) {
      FUN_01007068((undefined4 *)*puVar1,8,0);
      break;
    }
  }
LAB_01006dd8:
  iVar2 = puVar1[0x23];
  if (iVar2 != -1) {
    (*(code *)puVar1[6])(iVar2);
    puVar1[0x23] = -1;
  }
  return 0;
}



/* VA 01006e88 */

undefined4 __cdecl
FUN_01006e88(undefined4 *param_1,char *param_2,char *param_3,undefined4 param_4,undefined *param_5,
            undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  undefined3 extraout_var;
  int iVar4;
  undefined4 local_8;

  param_1[0xe] = param_7;
  param_1[9] = param_5;
  param_1[10] = param_6;
  local_8 = 0;
  *(undefined2 *)((int)param_1 + 0xae) = 0;
  iVar4 = (int)param_1 + (0x5b9 - (int)param_3);
  pcVar3 = param_3;
  do {
    cVar1 = *pcVar3;
    pcVar3[iVar4] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  bVar2 = FUN_0100666d(param_1,param_2,0,-1);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    param_1[0x27] = 0;
    param_1[0x24] = 0xffff;
    do {
      cVar1 = *param_3;
      param_3[iVar4] = cVar1;
      param_3 = param_3 + 1;
    } while (cVar1 != '\0');
    iVar4 = FUN_01006234(param_1);
    if (iVar4 != 0) {
      while (*(short *)(param_1 + 0x2b) != 0) {
        do {
          *(short *)(param_1 + 0x2b) = *(short *)(param_1 + 0x2b) + -1;
          iVar4 = FUN_01006931(param_1);
          if (iVar4 == 0) goto LAB_01007035;
          param_1[0x1f0] = param_1 + 0x2d;
          param_1[0x1ef] = param_1[0x1d];
          param_1[0x1f1] = (int)param_1 + 0x1b5;
          param_1[0x1f2] = (int)param_1 + 0x2b6;
          *(undefined2 *)(param_1 + 0x1f5) = *(undefined2 *)((int)param_1 + 0x7e);
          *(undefined2 *)((int)param_1 + 0x7d6) = *(undefined2 *)(param_1 + 0x20);
          *(undefined2 *)(param_1 + 0x1f6) = *(undefined2 *)((int)param_1 + 0x82);
          param_1[499] = param_1[0xe];
          *(undefined2 *)((int)param_1 + 0x7de) = *(undefined2 *)(param_1 + 0x1f);
          if ((*(ushort *)(param_1 + 0x1f) & 0xfffd) == 0xfffd) {
            if (param_1[0x27] == 0) {
              iVar4 = (*(code *)param_5)(1);
              if (iVar4 == -1) goto LAB_01006f9b;
            }
            else {
LAB_01006fda:
              iVar4 = (*(code *)param_5)(2,param_1 + 0x1ef);
              param_1[0x23] = iVar4;
              if (iVar4 == -1) {
LAB_01006f9b:
                FUN_01007068((undefined4 *)*param_1,0xb,0);
                goto LAB_01007035;
              }
              if (iVar4 == 0) {
                if ((*(ushort *)(param_1 + 0x1f) & 0xfffe) == 0xfffe) {
                  *(short *)((int)param_1 + 0xae) = *(short *)((int)param_1 + 0xae) + 1;
                }
              }
              else {
                iVar4 = _FDIGetFile_4(param_1);
                if (iVar4 == 0) goto LAB_01007035;
              }
            }
          }
          else if (param_1[0x27] == 0) {
            if ((*(ushort *)((int)param_1 + 0x7de) < *(ushort *)((int)param_1 + 0x6a)) ||
               (0xfffb < *(ushort *)((int)param_1 + 0x7de))) goto LAB_01006fda;
          }
          else {
            *(undefined2 *)(param_1 + 0x2b) = 0;
          }
        } while (*(short *)(param_1 + 0x2b) != 0);
        iVar4 = FUN_01006234(param_1);
        if (iVar4 == 0) goto LAB_01007035;
      }
      *(short *)(param_1 + 0x2b) = *(short *)(param_1 + 0x2b) + -1;
      local_8 = 1;
    }
  }
LAB_01007035:
  if (param_1[0x22] != -1) {
    (*(code *)param_1[6])(param_1[0x22]);
  }
  iVar4 = param_1[0x21];
  if (iVar4 != -1) {
    (*(code *)param_1[6])(iVar4);
  }
  param_1[0x21] = -1;
  param_1[0x22] = 0xffffffff;
  return local_8;
}



/* VA 01007068 */

void FUN_01007068(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 1;
  return;
}



/* VA 01007083 */

uint FUN_01007083(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;

  for (uVar1 = param_2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    uVar2 = *param_1;
    param_1 = param_1 + 1;
    param_3 = param_3 ^ uVar2;
  }
  uVar2 = param_2 & 3;
  uVar1 = 0;
  if (uVar2 != 1) {
    if (uVar2 != 2) {
      if (uVar2 != 3) goto LAB_010070df;
      uVar1 = (uint)(byte)*param_1 << 0x10;
      param_1 = (uint *)((int)param_1 + 1);
    }
    uVar1 = uVar1 | (uint)(byte)*param_1 << 8;
    param_1 = (uint *)((int)param_1 + 1);
  }
  uVar1 = uVar1 | (byte)*param_1;
LAB_010070df:
  return uVar1 ^ param_3;
}



/* VA 010070e6 */

undefined4 __cdecl
FUN_010070e6(int *param_1,uint *param_2,undefined *param_3,undefined *param_4,int *param_5,
            undefined4 *param_6,int param_7,int param_8,int param_9,int param_10,int param_11)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;

  *param_5 = *param_1 + 0x1800;
  if (param_6 == (undefined4 *)0x0) {
    return 0;
  }
  *param_6 = 0;
  puVar1 = (undefined4 *)(*(code *)param_3)(0x2c);
  if (puVar1 != (undefined4 *)0x0) {
    piVar2 = (int *)(*(code *)param_3)(0x2efc);
    puVar1[10] = piVar2;
    if (piVar2 == (int *)0x0) {
      (*(code *)param_4)(puVar1);
    }
    else {
      puVar1[4] = param_8;
      puVar1[5] = param_9;
      puVar1[6] = param_10;
      puVar1[7] = param_11;
      puVar1[1] = param_3;
      puVar1[2] = param_4;
      puVar1[3] = param_7;
      puVar1[8] = *param_1;
      puVar1[9] = param_2[1];
      *puVar1 = 0x4349444c;
      iVar3 = _LZX_DecodeInit_36(piVar2,*param_2,(int)param_3,(int)param_4,param_7,param_8,param_9,
                                 param_10,param_11);
      if (iVar3 != 0) {
        *param_6 = puVar1;
        return 0;
      }
      (*(code *)param_4)(puVar1);
    }
  }
  return 1;
}



/* VA 010071a5 */

/* Library Function - Single Match
    _LDIDecompress

   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

byte __cdecl _LDIDecompress(int *param_1,int param_2,int param_3,int param_4,undefined4 *param_5)

{
  undefined1 *puVar1;
  bool bVar2;
  byte bVar3;
  undefined3 extraout_var;
  undefined4 local_8;

  local_8 = 0;
  if (*param_1 != 0x4349444c) {
    return 2;
  }
  puVar1 = (undefined1 *)*param_5;
  if ((undefined1 *)param_1[8] < puVar1) {
    bVar3 = 3;
  }
  else {
    bVar2 = _LZX_Decode_28((int *)param_1[10],puVar1,param_2,param_3,param_4,puVar1,&local_8);
    *param_5 = local_8;
    bVar3 = -(CONCAT31(extraout_var,bVar2) != 0) & 4;
  }
  return bVar3;
}



/* VA 010071f3 */

undefined4 __cdecl FUN_010071f3(int *param_1)

{
  if (*param_1 != 0x4349444c) {
    return 2;
  }
  FUN_01007240(param_1[10]);
  return 0;
}



/* VA 0100720e */

undefined4 __cdecl FUN_0100720e(int *param_1)

{
  if (*param_1 != 0x4349444c) {
    return 2;
  }
  thunk_FUN_01007385((int *)param_1[10]);
  *param_1 = 0;
  (*(code *)param_1[2])(param_1[10]);
  (*(code *)param_1[2])(param_1);
  return 0;
}



/* VA 0100723b */

void thunk_FUN_01007385(int *param_1)

{
  if (*param_1 != 0) {
    (*(code *)param_1[0xbb9])(*param_1);
    *param_1 = 0;
  }
  return;
}



/* VA 01007240 */

void FUN_01007240(int param_1)

{
  FUN_0100739f(param_1);
  FUN_0100740e(param_1);
  FUN_01007453(param_1);
  *(undefined4 *)(param_1 + 0x2ecc) = 0;
  return;
}



/* VA 01007262 */

/* Library Function - Single Match
    _LZX_Decode@28

   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

bool _LZX_Decode_28(int *param_1,undefined1 *param_2,int param_3,int param_4,int param_5,
                   undefined4 param_6,undefined4 *param_7)

{
  undefined1 *puVar1;

  param_1[0xac1] = param_3;
  param_1[0xac2] = param_3 + 4 + param_4;
  param_1[0xac3] = param_5;
  thunk_FUN_01007723((int)param_1);
  puVar1 = FUN_0100750f(param_1,param_2);
  param_1[0xbb3] = param_1[0xbb3] + 1;
  if (-1 < (int)puVar1) {
    *param_7 = puVar1;
    param_1[0xac4] = (int)(puVar1 + param_1[0xac4]);
  }
  else {
    *param_7 = 0;
  }
  return -1 >= (int)puVar1;
}



/* VA 010072be */

/* Library Function - Single Match
    _LZX_DecodeInit@36

   Library: Visual Studio 2005 Release */

undefined4
_LZX_DecodeInit_36(int *param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,
                  int param_7,int param_8,int param_9)

{
  bool bVar1;
  undefined3 extraout_var;

  param_1[3000] = param_3;
  param_1[0xbb9] = param_4;
  param_1[0xbba] = param_5;
  param_1[0xbbb] = param_6;
  param_1[0xbbc] = param_7;
  param_1[0xbbd] = param_8;
  param_1[0xbbe] = param_9;
  param_1[1] = param_2;
  param_1[2] = param_2 - 1;
  if (((param_2 & param_2 - 1) == 0) &&
     (bVar1 = FUN_01007330(param_1), CONCAT31(extraout_var,bVar1) != 0)) {
    FUN_01007240((int)param_1);
    return 1;
  }
  return 0;
}



/* VA 01007330 */

bool FUN_01007330(int *param_1)

{
  int iVar1;
  uint uVar2;

  *(undefined1 *)((int)param_1 + 0x2eb5) = 4;
  uVar2 = 4;
  do {
    uVar2 = uVar2 + (1 << ((&DAT_010014b0)[*(byte *)((int)param_1 + 0x2eb5)] & 0x1f));
    *(byte *)((int)param_1 + 0x2eb5) = *(byte *)((int)param_1 + 0x2eb5) + 1;
  } while (uVar2 < (uint)param_1[1]);
  iVar1 = (*(code *)param_1[3000])(param_1[1] + 0x105);
  *param_1 = iVar1;
  return iVar1 != 0;
}



/* VA 01007385 */

void FUN_01007385(int *param_1)

{
  if (*param_1 != 0) {
    (*(code *)param_1[0xbb9])(*param_1);
    *param_1 = 0;
  }
  return;
}



/* VA 0100739f */

void FUN_0100739f(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;

  puVar3 = (undefined4 *)(param_1 + 0xa18);
  for (uVar1 = (uint)*(byte *)(param_1 + 0x2eb5) * 8 + 0x100 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  puVar3 = (undefined4 *)(param_1 + 0x2b14);
  for (uVar1 = (uint)*(byte *)(param_1 + 0x2eb5) * 8 + 0x100 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  puVar3 = (undefined4 *)(param_1 + 0xcb8);
  for (iVar2 = 0x3e; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined1 *)puVar3 = 0;
  puVar3 = (undefined4 *)(param_1 + 0x2db4);
  for (iVar2 = 0x3e; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined1 *)puVar3 = 0;
  return;
}



/* VA 0100740e */

void FUN_0100740e(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 1;
  *(undefined4 *)(param_1 + 0x10) = 1;
  *(undefined4 *)(param_1 + 0x14) = 1;
  *(undefined4 *)(param_1 + 0x2ec0) = 0;
  *(undefined4 *)(param_1 + 0x2b10) = 0;
  *(undefined4 *)(param_1 + 0x2edc) = 1;
  *(undefined4 *)(param_1 + 0x2ed4) = 0;
  *(undefined4 *)(param_1 + 0x2ed8) = 0;
  *(undefined4 *)(param_1 + 0x2eb8) = 1;
  *(undefined4 *)(param_1 + 0x2ec4) = 0;
  *(undefined4 *)(param_1 + 0x2ebc) = 0;
  return;
}



/* VA 01007453 */

void FUN_01007453(int param_1)

{
  *(undefined4 *)(param_1 + 0x2ec8) = 0;
  return;
}



/* VA 01007461 */

void FUN_01007461(int param_1,char *param_2,int param_3)

{
  uint uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  char *pcVar7;

  if (param_3 < 7) {
    *(int *)(param_1 + 0x2ec8) = *(int *)(param_1 + 0x2ec8) + param_3;
  }
  else {
    pcVar7 = param_2 + param_3 + -6;
    uVar3 = *(undefined4 *)pcVar7;
    uVar2 = *(undefined2 *)(param_2 + param_3 + -2);
    pcVar7[0] = -0x18;
    pcVar7[1] = -0x18;
    pcVar7[2] = -0x18;
    pcVar7[3] = -0x18;
    (param_2 + param_3 + -2)[0] = -0x18;
    (param_2 + param_3 + -2)[1] = -0x18;
    uVar1 = *(int *)(param_1 + 0x2ec8) + -10 + param_3;
    pcVar7 = param_2;
    while( true ) {
      for (; *pcVar7 != -0x18; pcVar7 = pcVar7 + 1) {
        *(int *)(param_1 + 0x2ec8) = *(int *)(param_1 + 0x2ec8) + 1;
      }
      uVar4 = *(uint *)(param_1 + 0x2ec8);
      puVar6 = (uint *)(pcVar7 + 1);
      if (uVar1 <= uVar4) break;
      uVar5 = *puVar6;
      if (uVar5 < *(uint *)(param_1 + 0x2ec4)) {
        *puVar6 = uVar5 - uVar4;
      }
      else if (-uVar5 < uVar4 || -uVar4 == uVar5) {
        *puVar6 = *(uint *)(param_1 + 0x2ec4) + uVar5;
      }
      pcVar7 = pcVar7 + 5;
      *(int *)(param_1 + 0x2ec8) = *(int *)(param_1 + 0x2ec8) + 5;
    }
    *(uint *)(param_1 + 0x2ec8) = uVar1 + 10;
    *(undefined4 *)(param_2 + param_3 + -6) = uVar3;
    *(undefined2 *)(param_2 + param_3 + -2) = uVar2;
  }
  return;
}



/* VA 0100750f */

undefined1 * FUN_0100750f(int *param_1,undefined1 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  int *piVar6;
  undefined1 *puVar7;
  int *piVar8;
  undefined1 *local_4;

  local_4 = (undefined1 *)0x0;
  do {
    if ((int)param_2 < 1) {
      iVar4 = param_1[0xbb0];
      if (iVar4 == 0) {
        iVar4 = param_1[1];
      }
      FUN_01008438((int)param_1,(uint)local_4,(undefined4 *)((iVar4 - (int)local_4) + *param_1));
      return local_4;
    }
    if (param_1[2999] == 1) {
      if (param_1[0xbae] != 0) {
        param_1[0xbae] = 0;
        uVar1 = FUN_0100781c((int)param_1,1);
        if (uVar1 == 0) {
          param_1[0xbb1] = 0;
        }
        else {
          uVar1 = FUN_0100781c((int)param_1,0x10);
          uVar2 = FUN_0100781c((int)param_1,0x10);
          param_1[0xbb1] = uVar2 | uVar1 << 0x10;
        }
      }
      if (param_1[0xbb6] == 3) {
        if ((*(byte *)(param_1 + 0xbb4) & 1) != 0) {
          uVar1 = param_1[0xac1];
          if (uVar1 < (uint)param_1[0xac2]) {
            param_1[0xac1] = uVar1 + 1;
          }
        }
        param_1[0xbb6] = 0;
        FUN_01007723((int)param_1);
      }
      uVar1 = FUN_0100781c((int)param_1,3);
      param_1[0xbb6] = uVar1;
      uVar1 = FUN_0100781c((int)param_1,8);
      uVar2 = FUN_0100781c((int)param_1,8);
      uVar3 = FUN_0100781c((int)param_1,8);
      iVar4 = uVar3 + (uVar1 * 0x100 + uVar2) * 0x100;
      param_1[0xbb4] = iVar4;
      param_1[0xbb5] = iVar4;
      if (param_1[0xbb6] == 2) {
        FUN_01008747((int)param_1);
      }
      iVar4 = param_1[0xbb6];
      if ((iVar4 == 1) || (iVar4 == 2)) {
        piVar6 = param_1 + 0x286;
        piVar8 = param_1 + 0xac5;
        for (uVar1 = (uint)*(byte *)((int)param_1 + 0x2eb5) * 8 + 0x100 >> 2; uVar1 != 0;
            uVar1 = uVar1 - 1) {
          *piVar8 = *piVar6;
          piVar6 = piVar6 + 1;
          piVar8 = piVar8 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(char *)piVar8 = (char)*piVar6;
          piVar6 = (int *)((int)piVar6 + 1);
          piVar8 = (int *)((int)piVar8 + 1);
        }
        piVar6 = param_1 + 0x32e;
        piVar8 = param_1 + 0xb6d;
        for (iVar4 = 0x3e; iVar4 != 0; iVar4 = iVar4 + -1) {
          *piVar8 = *piVar6;
          piVar6 = piVar6 + 1;
          piVar8 = piVar8 + 1;
        }
        *(char *)piVar8 = (char)*piVar6;
        FUN_01008690((int)param_1);
      }
      else if ((iVar4 != 3) || (iVar4 = FUN_010078be((int)param_1), iVar4 == 0)) {
        return (undefined1 *)0xffffffff;
      }
      param_1[2999] = 2;
    }
    for (; (0 < param_1[0xbb5] && (0 < (int)param_2)); param_2 = param_2 + -(int)puVar7) {
      puVar7 = (undefined1 *)param_1[0xbb5];
      if ((int)param_2 <= param_1[0xbb5]) {
        puVar7 = param_2;
      }
      if (puVar7 == (undefined1 *)0x0) {
        return (undefined1 *)0xffffffff;
      }
      iVar4 = param_1[0xbb6];
      puVar5 = (undefined1 *)param_1[0xbb0];
      if (iVar4 == 2) {
        puVar5 = decode_verbatim_block(param_1,puVar5,puVar7);
      }
      else if (iVar4 == 1) {
        puVar5 = (undefined1 *)decode_verbatim_block(param_1,(uint)puVar5,(uint)puVar7);
      }
      else if (iVar4 == 3) {
        puVar5 = (undefined1 *)FUN_01007840(param_1,(uint)puVar5,(int)puVar7);
      }
      else {
        puVar5 = (undefined1 *)0xffffffff;
      }
      if (puVar5 != (undefined1 *)0x0) {
        return (undefined1 *)0xffffffff;
      }
      param_1[0xbb5] = param_1[0xbb5] - (int)puVar7;
      local_4 = local_4 + (int)puVar7;
    }
    if (param_1[0xbb5] == 0) {
      param_1[2999] = 1;
    }
    if (param_2 == (undefined1 *)0x0) {
      FUN_01007723((int)param_1);
    }
  } while( true );
}



/* VA 01007723 */

void FUN_01007723(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 *puVar3;
  undefined2 uVar4;

  if (*(int *)(param_1 + 0x2ed8) != 3) {
    puVar3 = *(undefined2 **)(param_1 + 0x2b04);
    if (puVar3 + 2 <= *(undefined2 **)(param_1 + 0x2b08)) {
      uVar1 = *(undefined1 *)((int)puVar3 + 3);
      uVar4 = *puVar3;
      uVar2 = *(undefined1 *)(puVar3 + 1);
      *(undefined1 *)(param_1 + 0x2eb4) = 0x10;
      *(undefined2 **)(param_1 + 0x2b04) = puVar3 + 2;
      *(uint *)(param_1 + 0x2eb0) = CONCAT31(CONCAT21(uVar4,uVar1),uVar2);
    }
  }
  return;
}



/* VA 01007774 */

void thunk_FUN_01007723(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 *puVar3;
  undefined2 uVar4;

  if (*(int *)(param_1 + 0x2ed8) != 3) {
    puVar3 = *(undefined2 **)(param_1 + 0x2b04);
    if (puVar3 + 2 <= *(undefined2 **)(param_1 + 0x2b08)) {
      uVar1 = *(undefined1 *)((int)puVar3 + 3);
      uVar4 = *puVar3;
      uVar2 = *(undefined1 *)(puVar3 + 1);
      *(undefined1 *)(param_1 + 0x2eb4) = 0x10;
      *(undefined2 **)(param_1 + 0x2b04) = puVar3 + 2;
      *(uint *)(param_1 + 0x2eb0) = CONCAT31(CONCAT21(uVar4,uVar1),uVar2);
    }
  }
  return;
}



/* VA 01007779 */

void FUN_01007779(int param_1,byte param_2)

{
  char cVar1;
  ushort *puVar2;
  ushort uVar3;
  char cVar4;
  ushort *puVar5;

  *(char *)(param_1 + 0x2eb4) = *(char *)(param_1 + 0x2eb4) - param_2;
  *(int *)(param_1 + 0x2eb0) = *(int *)(param_1 + 0x2eb0) << (param_2 & 0x1f);
  cVar1 = *(char *)(param_1 + 0x2eb4);
  if ('\0' < cVar1) {
    return;
  }
  puVar2 = *(ushort **)(param_1 + 0x2b04);
  if (puVar2 < *(ushort **)(param_1 + 0x2b08)) {
    cVar4 = cVar1 + '\x10';
    uVar3 = *puVar2;
    puVar5 = puVar2 + 1;
    *(ushort **)(param_1 + 0x2b04) = puVar5;
    *(char *)(param_1 + 0x2eb4) = cVar4;
    *(uint *)(param_1 + 0x2eb0) = (uint)uVar3 << (-cVar1 & 0x1fU) | *(uint *)(param_1 + 0x2eb0);
    if ('\0' < cVar4) {
      return;
    }
    if (puVar5 < *(ushort **)(param_1 + 0x2b08)) {
      uVar3 = *puVar5;
      *(ushort **)(param_1 + 0x2b04) = puVar2 + 2;
      *(uint *)(param_1 + 0x2eb0) = *(uint *)(param_1 + 0x2eb0) | (uint)uVar3 << (-cVar4 & 0x1fU);
      *(char *)(param_1 + 0x2eb4) = cVar1 + ' ';
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x2ebc) = 1;
  return;
}



/* VA 0100781c */

uint FUN_0100781c(int param_1,byte param_2)

{
  uint uVar1;

  uVar1 = *(uint *)(param_1 + 0x2eb0);
  FUN_01007779(param_1,param_2);
  return uVar1 >> (0x20 - param_2 & 0x1f);
}



/* VA 01007840 */

int FUN_01007840(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;

  uVar3 = param_2;
  puVar2 = (undefined1 *)param_1[0xac1];
  uVar1 = param_2 + param_3;
  uVar4 = param_2;
  while( true ) {
    if ((int)uVar1 <= (int)uVar4) {
      param_1[0xac1] = (int)puVar2;
      param_2 = 0x101;
      if ((int)uVar1 < 0x102) {
        param_2 = uVar1;
      }
      for (; uVar3 < param_2; uVar3 = uVar3 + 1) {
        *(undefined1 *)(param_1[1] + *param_1 + uVar3) = *(undefined1 *)(*param_1 + uVar3);
      }
      param_1[0xbb0] = param_1[2] & uVar4;
      return uVar4 - uVar1;
    }
    if ((undefined1 *)param_1[0xac2] <= puVar2) break;
    *(undefined1 *)(uVar4 + *param_1) = *puVar2;
    uVar4 = uVar4 + 1;
    puVar2 = puVar2 + 1;
  }
  return -1;
}



/* VA 010078be */

undefined4 FUN_010078be(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;

  *(int *)(param_1 + 0x2b04) = *(int *)(param_1 + 0x2b04) + -2;
  if (*(int *)(param_1 + 0x2b04) + 4U < *(uint *)(param_1 + 0x2b08)) {
    puVar2 = (undefined4 *)(param_1 + 0xc);
    iVar3 = 3;
    do {
      *puVar2 = **(undefined4 **)(param_1 + 0x2b04);
      *(int *)(param_1 + 0x2b04) = *(int *)(param_1 + 0x2b04) + 4;
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* VA 0100791e */

int __fastcall FUN_0100791e(undefined4 param_1,int *param_2,uint param_3,int param_4)

{
  byte bVar1;
  short sVar2;
  ushort *puVar3;
  char cVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  ushort *puVar11;
  ushort *puVar12;
  uint local_c;
  uint local_8;

  cVar4 = (char)param_2[0xbad];
  puVar3 = (ushort *)param_2[0xac2];
  local_8 = param_2[0xbac];
  iVar9 = param_4 + param_3;
  puVar12 = (ushort *)param_2[0xac1];
  uVar8 = param_3;
  do {
    while( true ) {
      if (iVar9 <= (int)uVar8) {
        *(char *)(param_2 + 0xbad) = cVar4;
        param_2[0xbac] = local_8;
        param_2[0xac1] = (int)puVar12;
        return uVar8;
      }
      iVar10 = (int)*(short *)((int)param_2 + (local_8 >> 0x16) * 2 + 0x18);
      if (iVar10 < 0) {
        uVar7 = 0x200000;
        do {
          if ((local_8 & uVar7) == 0) {
            sVar2 = (short)param_2[0x38f - iVar10];
          }
          else {
            sVar2 = *(short *)((int)param_2 + iVar10 * -4 + 0xe3e);
          }
          iVar10 = (int)sVar2;
          uVar7 = uVar7 >> 1;
        } while (iVar10 < 0);
      }
      if (puVar3 <= puVar12) {
        return -1;
      }
      bVar1 = *(byte *)(iVar10 + 0xa18 + (int)param_2);
      local_8 = local_8 << (bVar1 & 0x1f);
      cVar4 = cVar4 - bVar1;
      if (cVar4 < '\x01') {
        local_8 = local_8 | (uint)*puVar12 << (-cVar4 & 0x1fU);
        puVar12 = puVar12 + 1;
        cVar4 = cVar4 + '\x10';
      }
      uVar7 = iVar10 - 0x100;
      if (-1 < (int)uVar7) break;
      *(char *)(uVar8 + *param_2) = (char)uVar7;
      *(char *)(param_2[1] + *param_2 + uVar8) = (char)uVar7;
      uVar8 = uVar8 + 1;
    }
    local_c = uVar7 & 7;
    if (local_c == 7) {
      iVar10 = (int)*(short *)((int)param_2 + (local_8 >> 0x18) * 2 + 0x818);
      if (iVar10 < 0) {
        uVar6 = 0x800000;
        do {
          if ((local_8 & uVar6) == 0) {
            sVar2 = (short)param_2[0x8cf - iVar10];
          }
          else {
            sVar2 = *(short *)((int)param_2 + iVar10 * -4 + 0x233e);
          }
          iVar10 = (int)sVar2;
          uVar6 = uVar6 >> 1;
        } while (iVar10 < 0);
      }
      bVar1 = *(byte *)(iVar10 + 0xcb8 + (int)param_2);
      local_8 = local_8 << (bVar1 & 0x1f);
      cVar4 = cVar4 - bVar1;
      if (cVar4 < '\x01') {
        local_8 = local_8 | (uint)*puVar12 << (-cVar4 & 0x1fU);
        puVar12 = puVar12 + 1;
        cVar4 = cVar4 + '\x10';
      }
      local_c = iVar10 + 7;
    }
    cVar5 = (char)((int)uVar7 >> 3);
    if (cVar5 < '\x03') {
      iVar10 = param_2[cVar5 + 3];
      if (cVar5 != '\0') {
        param_2[cVar5 + 3] = param_2[3];
        goto LAB_01007afc;
      }
    }
    else {
      if (cVar5 < '\x04') {
        iVar10 = 1;
      }
      else {
        iVar10 = (int)cVar5;
        uVar7 = local_8 >> (0x20 - (&DAT_010014b0)[iVar10] & 0x1f);
        local_8 = local_8 << ((&DAT_010014b0)[iVar10] & 0x1f);
        cVar5 = cVar4 - (&DAT_010014b0)[iVar10];
        puVar11 = puVar12;
        cVar4 = cVar5;
        if (cVar5 < '\x01') {
          cVar4 = cVar5 + '\x10';
          local_8 = local_8 | (uint)*puVar12 << (-cVar5 & 0x1fU);
          puVar11 = puVar12 + 1;
          if (cVar4 < '\x01') {
            local_8 = local_8 | (uint)*puVar11 << (-cVar4 & 0x1fU);
            puVar11 = puVar12 + 2;
            cVar4 = cVar5 + ' ';
          }
        }
        iVar10 = uVar7 + *(int *)(&DAT_010014e8 + iVar10 * 4);
        puVar12 = puVar11;
      }
      param_2[5] = param_2[4];
      param_2[4] = param_2[3];
LAB_01007afc:
      param_2[3] = iVar10;
    }
    local_c = local_c + 2;
    param_3 = uVar8 - iVar10;
    do {
      *(undefined1 *)(*param_2 + uVar8) = *(undefined1 *)((param_2[2] & param_3) + *param_2);
      if ((int)uVar8 < 0x101) {
        *(undefined1 *)(param_2[1] + *param_2 + uVar8) = *(undefined1 *)(*param_2 + uVar8);
      }
      uVar8 = uVar8 + 1;
      param_3 = param_3 + 1;
      local_c = local_c + -1;
    } while (0 < (int)local_c);
  } while( true );
}



/* VA 01007b75 */

int FUN_01007b75(int *param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  byte bVar2;
  short sVar3;
  ushort *puVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  int iVar9;
  char cVar10;
  int iVar11;
  ushort *puVar12;
  ushort *puVar13;
  uint local_8;

  piVar5 = param_1;
  pbVar1 = (byte *)(param_1 + 0xbad);
  param_1 = (int *)((uint)*pbVar1 << 0x18);
  puVar4 = (ushort *)piVar5[0xac2];
  puVar13 = (ushort *)piVar5[0xac1];
  iVar9 = param_3 + param_2;
  param_3 = piVar5[0xbac];
  bVar8 = *pbVar1;
  do {
    if (iVar9 <= (int)param_2) {
      *(byte *)(piVar5 + 0xbad) = bVar8;
      piVar5[0xbac] = param_3;
      piVar5[0xac1] = (int)puVar13;
      piVar5[0xbb0] = piVar5[2] & param_2;
      return param_2 - iVar9;
    }
    iVar11 = (int)*(short *)((int)piVar5 + (param_3 >> 0x16) * 2 + 0x18);
    if (iVar11 < 0) {
      uVar6 = 0x200000;
      do {
        if ((param_3 & uVar6) == 0) {
          sVar3 = (short)piVar5[0x38f - iVar11];
        }
        else {
          sVar3 = *(short *)((int)piVar5 + iVar11 * -4 + 0xe3e);
        }
        iVar11 = (int)sVar3;
        uVar6 = uVar6 >> 1;
      } while (iVar11 < 0);
    }
    if (puVar4 <= puVar13) {
      return -1;
    }
    param_3 = param_3 << (*(byte *)(iVar11 + 0xa18 + (int)piVar5) & 0x1f);
    param_1._3_1_ = (byte)((uint)param_1 >> 0x18);
    bVar8 = param_1._3_1_ - *(char *)(iVar11 + 0xa18 + (int)piVar5);
    if ((char)bVar8 < '\x01') {
      param_3 = param_3 | (uint)*puVar13 << (-bVar8 & 0x1f);
      puVar13 = puVar13 + 1;
      bVar8 = bVar8 + 0x10;
    }
    param_1 = (int *)((uint)bVar8 << 0x18);
    uVar6 = iVar11 - 0x100;
    if ((int)uVar6 < 0) {
      *(char *)(param_2 + *piVar5) = (char)uVar6;
      param_2 = param_2 + 1;
    }
    else {
      local_8 = uVar6 & 7;
      if (local_8 == 7) {
        iVar11 = (int)*(short *)((int)piVar5 + (param_3 >> 0x18) * 2 + 0x818);
        if (iVar11 < 0) {
          uVar7 = 0x800000;
          do {
            if ((param_3 & uVar7) == 0) {
              sVar3 = (short)piVar5[0x8cf - iVar11];
            }
            else {
              sVar3 = *(short *)((int)piVar5 + iVar11 * -4 + 0x233e);
            }
            iVar11 = (int)sVar3;
            uVar7 = uVar7 >> 1;
          } while (iVar11 < 0);
        }
        param_3 = param_3 << (*(byte *)(iVar11 + 0xcb8 + (int)piVar5) & 0x1f);
        bVar8 = bVar8 - *(char *)(iVar11 + 0xcb8 + (int)piVar5);
        if ((char)bVar8 < '\x01') {
          param_3 = param_3 | (uint)*puVar13 << (-bVar8 & 0x1f);
          puVar13 = puVar13 + 1;
          bVar8 = bVar8 + 0x10;
        }
        param_1 = (int *)((uint)bVar8 << 0x18);
        local_8 = iVar11 + 7;
      }
      cVar10 = (char)((int)uVar6 >> 3);
      if (cVar10 < '\x03') {
        iVar11 = piVar5[cVar10 + 3];
        if (cVar10 != '\0') {
          piVar5[cVar10 + 3] = piVar5[3];
          goto LAB_01007d55;
        }
      }
      else {
        iVar11 = DAT_010014f4;
        if ('\x03' < cVar10) {
          iVar11 = (int)cVar10;
          uVar6 = param_3 >> (0x20 - (&DAT_010014b0)[iVar11] & 0x1f);
          bVar8 = param_1._3_1_ - (&DAT_010014b0)[iVar11];
          param_1 = (int *)((uint)bVar8 << 0x18);
          param_3 = param_3 << ((&DAT_010014b0)[iVar11] & 0x1f);
          puVar12 = puVar13;
          if ((char)bVar8 < '\x01') {
            bVar2 = bVar8 + 0x10;
            param_1 = (int *)((uint)bVar2 << 0x18);
            param_3 = param_3 | (uint)*puVar13 << (-bVar8 & 0x1f);
            puVar12 = puVar13 + 1;
            if ((char)bVar2 < '\x01') {
              param_3 = param_3 | (uint)*puVar12 << (-bVar2 & 0x1f);
              puVar12 = puVar13 + 2;
              param_1 = (int *)((uint)(byte)(bVar8 + 0x20) << 0x18);
            }
          }
          puVar13 = puVar12;
          iVar11 = uVar6 + *(int *)(&DAT_010014e8 + iVar11 * 4);
        }
        piVar5[5] = piVar5[4];
        piVar5[4] = piVar5[3];
LAB_01007d55:
        piVar5[3] = iVar11;
      }
      local_8 = local_8 + 2;
      uVar6 = param_2 - iVar11 & piVar5[2];
      do {
        *(undefined1 *)(*piVar5 + param_2) = *(undefined1 *)(*piVar5 + uVar6);
        param_2 = param_2 + 1;
        uVar6 = uVar6 + 1;
        local_8 = local_8 + -1;
      } while (0 < (int)local_8);
    }
    bVar8 = param_1._3_1_;
  } while( true );
}



/* VA 01007db7 */

/* Library Function - Single Match
    _decode_verbatim_block@12

   Library: Visual Studio 2005 Release
   __stdcall decode_verbatim_block,12 */

uint decode_verbatim_block(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 in_ECX;
  int *extraout_EDX;

  uVar1 = param_2;
  if ((int)param_2 < 0x101) {
    uVar1 = 0x101 - param_2;
    if ((int)param_3 <= (int)(0x101 - param_2)) {
      uVar1 = param_3;
    }
    uVar1 = FUN_0100791e(in_ECX,param_1,param_2,uVar1);
    param_3 = param_3 + (param_2 - uVar1);
    extraout_EDX[0xbb0] = uVar1;
    param_1 = extraout_EDX;
    if ((int)param_3 < 1) {
      return param_3;
    }
  }
  uVar1 = FUN_01007b75(param_1,uVar1,param_3);
  return uVar1;
}



/* VA 01007e02 */

int __fastcall FUN_01007e02(undefined4 param_1,int *param_2,int param_3,uint param_4)

{
  byte bVar1;
  undefined1 uVar2;
  short sVar3;
  ushort *puVar4;
  int iVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  ushort *puVar13;
  uint local_c;
  uint local_8;

  cVar6 = (char)param_2[0xbad];
  puVar4 = (ushort *)param_2[0xac2];
  iVar5 = *param_2;
  local_8 = param_2[0xbac];
  iVar11 = param_4 + param_3;
  puVar13 = (ushort *)param_2[0xac1];
  do {
    while( true ) {
      if (iVar11 <= param_3) {
        *(char *)(param_2 + 0xbad) = cVar6;
        param_2[0xbac] = local_8;
        param_2[0xac1] = (int)puVar13;
        return param_3;
      }
      iVar12 = (int)*(short *)((int)param_2 + (local_8 >> 0x16) * 2 + 0x18);
      if (iVar12 < 0) {
        uVar8 = 0x200000;
        do {
          if ((local_8 & uVar8) == 0) {
            sVar3 = (short)param_2[0x38f - iVar12];
          }
          else {
            sVar3 = *(short *)((int)param_2 + iVar12 * -4 + 0xe3e);
          }
          iVar12 = (int)sVar3;
          uVar8 = uVar8 >> 1;
        } while (iVar12 < 0);
      }
      if (puVar4 <= puVar13) {
        return -1;
      }
      bVar1 = *(byte *)(iVar12 + 0xa18 + (int)param_2);
      local_8 = local_8 << (bVar1 & 0x1f);
      cVar6 = cVar6 - bVar1;
      if (cVar6 < '\x01') {
        local_8 = local_8 | (uint)*puVar13 << (-cVar6 & 0x1fU);
        puVar13 = puVar13 + 1;
        cVar6 = cVar6 + '\x10';
      }
      uVar8 = iVar12 - 0x100;
      if (-1 < (int)uVar8) break;
      *(char *)(iVar5 + param_3) = (char)uVar8;
      *(char *)(param_2[1] + iVar5 + param_3) = (char)uVar8;
      param_3 = param_3 + 1;
    }
    local_c = uVar8 & 7;
    if (local_c == 7) {
      iVar12 = (int)*(short *)((int)param_2 + (local_8 >> 0x18) * 2 + 0x818);
      if (iVar12 < 0) {
        uVar7 = 0x800000;
        do {
          if ((local_8 & uVar7) == 0) {
            sVar3 = (short)param_2[0x8cf - iVar12];
          }
          else {
            sVar3 = *(short *)((int)param_2 + iVar12 * -4 + 0x233e);
          }
          iVar12 = (int)sVar3;
          uVar7 = uVar7 >> 1;
        } while (iVar12 < 0);
      }
      bVar1 = *(byte *)(iVar12 + 0xcb8 + (int)param_2);
      local_8 = local_8 << (bVar1 & 0x1f);
      cVar6 = cVar6 - bVar1;
      if (cVar6 < '\x01') {
        local_8 = local_8 | (uint)*puVar13 << (-cVar6 & 0x1fU);
        puVar13 = puVar13 + 1;
        cVar6 = cVar6 + '\x10';
      }
      local_c = iVar12 + 7;
    }
    cVar10 = (char)((int)uVar8 >> 3);
    iVar12 = (int)cVar10;
    if (cVar10 < '\x03') {
      iVar9 = param_2[iVar12 + 3];
      if (cVar10 != '\0') {
        param_2[iVar12 + 3] = param_2[3];
        goto LAB_0100806f;
      }
    }
    else {
      bVar1 = (&DAT_010014b0)[iVar12];
      if (bVar1 < 3) {
        if (bVar1 == 0) {
          iVar9 = 1;
        }
        else {
          uVar8 = local_8 >> (0x20 - bVar1 & 0x1f);
          local_8 = local_8 << (bVar1 & 0x1f);
          cVar6 = cVar6 - (&DAT_010014b0)[iVar12];
          if (cVar6 < '\x01') {
            local_8 = local_8 | (uint)*puVar13 << (-cVar6 & 0x1fU);
            puVar13 = puVar13 + 1;
            cVar6 = cVar6 + '\x10';
          }
          iVar9 = uVar8 + *(int *)(&DAT_010014e8 + iVar12 * 4);
        }
      }
      else {
        if (bVar1 == 3) {
          uVar8 = 0;
        }
        else {
          uVar8 = local_8 >> (0x23 - bVar1 & 0x1f);
          local_8 = local_8 << (bVar1 - 3 & 0x1f);
          cVar6 = cVar6 + ('\x03' - (&DAT_010014b0)[iVar12]);
          if (cVar6 < '\x01') {
            local_8 = local_8 | (uint)*puVar13 << (-cVar6 & 0x1fU);
            puVar13 = puVar13 + 1;
            cVar6 = cVar6 + '\x10';
          }
        }
        iVar9 = (int)*(char *)((local_8 >> 0x19) + 0xdb4 + (int)param_2);
        local_8 = local_8 << (*(byte *)(iVar9 + 0xe34 + (int)param_2) & 0x1f);
        cVar6 = cVar6 - *(char *)(iVar9 + 0xe34 + (int)param_2);
        if (cVar6 < '\x01') {
          local_8 = local_8 | (uint)*puVar13 << (-cVar6 & 0x1fU);
          puVar13 = puVar13 + 1;
          cVar6 = cVar6 + '\x10';
        }
        iVar9 = *(int *)(&DAT_010014e8 + iVar12 * 4) + uVar8 * 8 + iVar9;
      }
      param_2[5] = param_2[4];
      param_2[4] = param_2[3];
LAB_0100806f:
      param_2[3] = iVar9;
    }
    local_c = local_c + 2;
    param_4 = param_3 - iVar9;
    do {
      uVar2 = *(undefined1 *)((param_4 & param_2[2]) + iVar5);
      *(undefined1 *)(iVar5 + param_3) = uVar2;
      if (param_3 < 0x101) {
        *(undefined1 *)(param_2[1] + iVar5 + param_3) = uVar2;
      }
      param_3 = param_3 + 1;
      param_4 = param_4 + 1;
      local_c = local_c + -1;
    } while (0 < (int)local_c);
  } while( true );
}



/* VA 010080e2 */

int FUN_010080e2(int *param_1,undefined1 *param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  short sVar3;
  ushort *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  char cVar8;
  undefined1 *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  byte bVar13;
  undefined1 *puVar14;
  int iVar15;
  ushort *puVar16;
  uint local_8;

  piVar6 = param_1;
  puVar4 = (ushort *)param_1[0xac2];
  pbVar1 = (byte *)(param_1 + 0xbad);
  iVar5 = *param_1;
  puVar9 = param_2 + param_3;
  puVar16 = (ushort *)param_1[0xac1];
  param_1 = (int *)((uint)*pbVar1 << 0x18);
  uVar7 = piVar6[0xbac];
  bVar13 = *pbVar1;
  puVar14 = param_2;
  do {
    if ((int)puVar9 <= (int)puVar14) {
      piVar6[0xbac] = uVar7;
      piVar6[0xbb0] = piVar6[2] & (uint)puVar14;
      *(byte *)(piVar6 + 0xbad) = bVar13;
      piVar6[0xac1] = (int)puVar16;
      return (int)puVar14 - (int)puVar9;
    }
    iVar15 = (int)*(short *)((int)piVar6 + (uVar7 >> 0x16) * 2 + 0x18);
    if (iVar15 < 0) {
      uVar10 = 0x200000;
      do {
        if ((uVar7 & uVar10) == 0) {
          sVar3 = (short)piVar6[0x38f - iVar15];
        }
        else {
          sVar3 = *(short *)((int)piVar6 + iVar15 * -4 + 0xe3e);
        }
        iVar15 = (int)sVar3;
        uVar10 = uVar10 >> 1;
      } while (iVar15 < 0);
    }
    if (puVar4 <= puVar16) {
      return -1;
    }
    bVar2 = *(byte *)(iVar15 + 0xa18 + (int)piVar6);
    param_1._3_1_ = (byte)((uint)param_1 >> 0x18);
    bVar13 = param_1._3_1_ - bVar2;
    uVar7 = uVar7 << (bVar2 & 0x1f);
    if ((char)bVar13 < '\x01') {
      uVar7 = uVar7 | (uint)*puVar16 << (-bVar13 & 0x1f);
      puVar16 = puVar16 + 1;
      bVar13 = bVar13 + 0x10;
    }
    param_1 = (int *)((uint)bVar13 << 0x18);
    uVar10 = iVar15 - 0x100;
    if ((int)uVar10 < 0) {
      puVar14[iVar5] = (char)uVar10;
      puVar14 = puVar14 + 1;
    }
    else {
      local_8 = uVar10 & 7;
      if (local_8 == 7) {
        iVar15 = (int)*(short *)((int)piVar6 + (uVar7 >> 0x18) * 2 + 0x818);
        if (iVar15 < 0) {
          uVar11 = 0x800000;
          do {
            if ((uVar7 & uVar11) == 0) {
              sVar3 = (short)piVar6[0x8cf - iVar15];
            }
            else {
              sVar3 = *(short *)((int)piVar6 + iVar15 * -4 + 0x233e);
            }
            iVar15 = (int)sVar3;
            uVar11 = uVar11 >> 1;
          } while (iVar15 < 0);
        }
        bVar2 = *(byte *)(iVar15 + 0xcb8 + (int)piVar6);
        bVar13 = bVar13 - bVar2;
        uVar7 = uVar7 << (bVar2 & 0x1f);
        if ((char)bVar13 < '\x01') {
          uVar7 = uVar7 | (uint)*puVar16 << (-bVar13 & 0x1f);
          puVar16 = puVar16 + 1;
          bVar13 = bVar13 + 0x10;
        }
        param_1 = (int *)((uint)bVar13 << 0x18);
        local_8 = iVar15 + 7;
      }
      cVar8 = (char)((int)uVar10 >> 3);
      if (cVar8 < '\x03') {
        iVar15 = piVar6[cVar8 + 3];
        if (cVar8 != '\0') {
          piVar6[cVar8 + 3] = piVar6[3];
          goto LAB_01008382;
        }
      }
      else {
        iVar12 = (int)cVar8;
        bVar2 = (&DAT_010014b0)[iVar12];
        if (bVar2 < 3) {
          if (bVar2 == 0) {
            iVar15 = *(int *)(&DAT_010014e8 + iVar12 * 4);
          }
          else {
            uVar10 = uVar7 >> (0x20 - bVar2 & 0x1f);
            uVar7 = uVar7 << (bVar2 & 0x1f);
            bVar13 = bVar13 - (&DAT_010014b0)[iVar12];
            if ((char)bVar13 < '\x01') {
              uVar7 = uVar7 | (uint)*puVar16 << (-bVar13 & 0x1f);
              puVar16 = puVar16 + 1;
              bVar13 = bVar13 + 0x10;
            }
            param_1 = (int *)((uint)bVar13 << 0x18);
            iVar15 = uVar10 + *(int *)(&DAT_010014e8 + iVar12 * 4);
          }
        }
        else {
          if (bVar2 == 3) {
            uVar10 = 0;
          }
          else {
            uVar10 = uVar7 >> (0x23 - bVar2 & 0x1f);
            uVar7 = uVar7 << (bVar2 - 3 & 0x1f);
            bVar13 = param_1._3_1_ + ('\x03' - bVar2);
            if ((char)bVar13 < '\x01') {
              uVar7 = uVar7 | (uint)*puVar16 << (-bVar13 & 0x1f);
              puVar16 = puVar16 + 1;
              bVar13 = bVar13 + 0x10;
            }
          }
          iVar15 = (int)*(char *)((uVar7 >> 0x19) + 0xdb4 + (int)piVar6);
          uVar7 = uVar7 << (*(byte *)(iVar15 + 0xe34 + (int)piVar6) & 0x1f);
          bVar13 = bVar13 - *(char *)(iVar15 + 0xe34 + (int)piVar6);
          if ((char)bVar13 < '\x01') {
            uVar7 = uVar7 | (uint)*puVar16 << (-bVar13 & 0x1f);
            puVar16 = puVar16 + 1;
            bVar13 = bVar13 + 0x10;
          }
          param_1 = (int *)((uint)bVar13 << 0x18);
          iVar15 = *(int *)(&DAT_010014e8 + iVar12 * 4) + uVar10 * 8 + iVar15;
        }
        piVar6[5] = piVar6[4];
        piVar6[4] = piVar6[3];
LAB_01008382:
        piVar6[3] = iVar15;
      }
      local_8 = local_8 + 2;
      param_2 = (undefined1 *)(((int)puVar14 - iVar15 & piVar6[2]) + iVar5);
      do {
        puVar14[iVar5] = *param_2;
        puVar14 = puVar14 + 1;
        param_2 = param_2 + 1;
        local_8 = local_8 + -1;
      } while (0 < (int)local_8);
    }
    bVar13 = param_1._3_1_;
  } while( true );
}



/* VA 010083ed */

/* Library Function - Single Match
    _decode_verbatim_block@12

   Library: Visual Studio 2005 Release
   __stdcall decode_verbatim_block,12 */

undefined1 * decode_verbatim_block(int *param_1,undefined1 *param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  undefined4 in_ECX;
  int *extraout_EDX;

  puVar1 = param_2;
  if ((int)param_2 < 0x101) {
    puVar1 = (undefined1 *)(0x101U - (int)param_2);
    if ((int)param_3 <= (int)(0x101U - (int)param_2)) {
      puVar1 = param_3;
    }
    puVar1 = (undefined1 *)FUN_01007e02(in_ECX,param_1,(int)param_2,(uint)puVar1);
    param_3 = param_3 + ((int)param_2 - (int)puVar1);
    extraout_EDX[0xbb0] = (int)puVar1;
    param_1 = extraout_EDX;
    if ((int)param_3 < 1) {
      return param_3;
    }
  }
  puVar1 = (undefined1 *)FUN_010080e2(param_1,puVar1,(int)param_3);
  return puVar1;
}



/* VA 01008438 */

void FUN_01008438(int param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 *puVar2;

  if (*(undefined4 **)(param_1 + 0x2b0c) != (undefined4 *)0x0) {
    puVar2 = *(undefined4 **)(param_1 + 0x2b0c);
    for (uVar1 = param_2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar2 = *param_3;
      param_3 = param_3 + 1;
      puVar2 = puVar2 + 1;
    }
    for (uVar1 = param_2 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)puVar2 = *(undefined1 *)param_3;
      param_3 = (undefined4 *)((int)param_3 + 1);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
    if ((*(int *)(param_1 + 0x2ec4) != 0) && (*(uint *)(param_1 + 0x2ecc) < 0x8000)) {
      FUN_01007461(param_1,*(char **)(param_1 + 0x2b0c),param_2);
    }
  }
  return;
}



/* VA 01008485 */

bool FUN_01008485(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  bool bVar7;
  short local_2dc [256];
  short local_dc [94];
  byte local_20 [24];
  uint local_8;

  iVar5 = 0;
  do {
    uVar3 = FUN_0100781c(param_1,4);
    local_20[iVar5] = (byte)uVar3;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x14);
  if (*(int *)(param_1 + 0x2ebc) == 0) {
    FUN_0100878e(param_1,0x14,(int)local_20,8,(undefined4 *)local_2dc,(int)local_dc);
    iVar5 = 0;
    if (0 < param_2) {
      do {
        sVar2 = local_2dc[*(uint *)(param_1 + 0x2eb0) >> 0x18];
        if (sVar2 < 0) {
          uVar3 = 0x800000;
          do {
            if ((uVar3 & *(uint *)(param_1 + 0x2eb0)) == 0) {
              sVar2 = local_dc[-sVar2 * 2];
            }
            else {
              sVar2 = local_dc[-sVar2 * 2 + 1];
            }
            uVar3 = uVar3 >> 1;
          } while (sVar2 < 0);
        }
        local_8 = (int)sVar2;
        FUN_01007779(param_1,local_20[sVar2]);
        if (*(int *)(param_1 + 0x2ebc) != 0) {
          return false;
        }
        if (sVar2 == 0x11) {
          uVar3 = FUN_0100781c(param_1,4);
          uVar3 = (uVar3 & 0xff) + 4;
LAB_01008557:
          if (param_2 <= (int)(uVar3 + iVar5)) {
            uVar3 = param_2 - iVar5;
          }
          if (0 < (int)uVar3) {
            puVar6 = (undefined4 *)(iVar5 + param_4);
            for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
              *puVar6 = 0;
              puVar6 = puVar6 + 1;
            }
            for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
              *(undefined1 *)puVar6 = 0;
              puVar6 = (undefined4 *)((int)puVar6 + 1);
            }
            iVar5 = iVar5 + uVar3;
          }
          iVar5 = iVar5 + -1;
        }
        else {
          if (sVar2 == 0x12) {
            uVar3 = FUN_0100781c(param_1,5);
            uVar3 = (uVar3 & 0xff) + 0x14;
            goto LAB_01008557;
          }
          if (sVar2 == 0x13) {
            uVar3 = FUN_0100781c(param_1,1);
            uVar3 = (uVar3 & 0xff) + 4;
            local_8 = uVar3;
            if (param_2 <= (int)(uVar3 + iVar5)) {
              uVar3 = param_2 - iVar5;
              local_8 = uVar3;
            }
            sVar2 = local_2dc[*(uint *)(param_1 + 0x2eb0) >> 0x18];
            if (sVar2 < 0) {
              uVar4 = 0x800000;
              do {
                if ((uVar4 & *(uint *)(param_1 + 0x2eb0)) == 0) {
                  sVar2 = local_dc[-sVar2 * 2];
                }
                else {
                  sVar2 = local_dc[-sVar2 * 2 + 1];
                }
                uVar4 = uVar4 >> 1;
              } while (sVar2 < 0);
            }
            local_8 = uVar3;
            FUN_01007779(param_1,local_20[sVar2]);
            uVar1 = (&DAT_010015c5)[(uint)*(byte *)(iVar5 + param_3) - (int)sVar2];
            if (0 < (int)uVar3) {
              puVar6 = (undefined4 *)(iVar5 + param_4);
              for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
                *puVar6 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
                puVar6 = puVar6 + 1;
              }
              iVar5 = iVar5 + local_8;
              for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                *(undefined1 *)puVar6 = uVar1;
                puVar6 = (undefined4 *)((int)puVar6 + 1);
              }
            }
            iVar5 = iVar5 + -1;
          }
          else {
            *(undefined *)(iVar5 + param_4) = (&DAT_010015c5)[*(byte *)(iVar5 + param_3) - local_8];
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_2);
    }
    bVar7 = *(int *)(param_1 + 0x2ebc) == 0;
  }
  else {
    bVar7 = false;
  }
  return bVar7;
}



/* VA 01008690 */

bool FUN_01008690(int param_1)

{
  bool bVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar3;
  undefined3 extraout_var_01;

  bVar1 = FUN_01008485(param_1,0x100,param_1 + 0x2b14,param_1 + 0xa18);
  if (((CONCAT31(extraout_var,bVar1) == 0) ||
      (bVar1 = FUN_01008485(param_1,(uint)*(byte *)(param_1 + 0x2eb5) << 3,param_1 + 0x2c14,
                            param_1 + 0xb18), CONCAT31(extraout_var_00,bVar1) == 0)) ||
     (uVar3 = FUN_0100878e(param_1,(uint)*(byte *)(param_1 + 0x2eb5) * 8 + 0x100,param_1 + 0xa18,10,
                           (undefined4 *)(param_1 + 0x18),param_1 + 0xe3c), uVar3 == 0)) {
    bVar1 = false;
  }
  else {
    bVar2 = FUN_01008485(param_1,0xf9,param_1 + 0x2db4,param_1 + 0xcb8);
    bVar1 = false;
    if (CONCAT31(extraout_var_01,bVar2) != 0) {
      uVar3 = FUN_0100878e(param_1,0xf9,param_1 + 0xcb8,8,(undefined4 *)(param_1 + 0x818),
                           param_1 + 0x233c);
      bVar1 = uVar3 != 0;
    }
  }
  return bVar1;
}



/* VA 01008747 */

bool FUN_01008747(int param_1)

{
  uint uVar1;
  int iVar2;
  bool bVar3;

  iVar2 = 0;
  do {
    uVar1 = FUN_0100781c(param_1,3);
    ((byte *)(param_1 + 0xe34))[iVar2] = (byte)uVar1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  if (*(int *)(param_1 + 0x2ebc) == 0) {
    iVar2 = FUN_0100898b(param_1,(byte *)(param_1 + 0xe34),(undefined4 *)(param_1 + 0xdb4));
    bVar3 = iVar2 != 0;
  }
  else {
    bVar3 = false;
  }
  return bVar3;
}



/* VA 0100878e */

/* WARNING: Type propagation algorithm not settling */

uint FUN_0100878e(undefined4 param_1,uint param_2,int param_3,byte param_4,undefined4 *param_5,
                 int param_6)

{
  uint *puVar1;
  char cVar2;
  short sVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  short *psVar10;
  byte bVar11;
  uint uVar12;
  int *piVar13;
  undefined4 *puVar14;
  int aiStack_a4 [17];
  uint auStack_60 [18];
  uint local_18;
  uint local_14;
  int local_10;
  uint local_c;
  char local_5;

  piVar13 = aiStack_a4;
  for (iVar8 = 0x10; piVar13 = piVar13 + 1, iVar8 != 0; iVar8 = iVar8 + -1) {
    *piVar13 = 0;
  }
  uVar9 = 0;
  if (param_2 != 0) {
    do {
      aiStack_a4[*(byte *)(uVar9 + param_3)] = aiStack_a4[*(byte *)(uVar9 + param_3)] + 1;
      uVar9 = uVar9 + 1;
    } while (uVar9 < param_2);
  }
  uVar9 = 1;
  auStack_60[1] = 0;
  uVar5 = uVar9;
  do {
    piVar13 = aiStack_a4 + uVar5;
    cVar2 = (char)uVar5;
    puVar1 = auStack_60 + uVar5;
    uVar5 = uVar5 + 1;
    auStack_60[uVar5] = (*piVar13 << (0x10U - cVar2 & 0x1f)) + *puVar1;
  } while (uVar5 < 0x11);
  if (auStack_60[0x11] != 0x10000) {
    if (auStack_60[0x11] == 0) {
      uVar9 = 1 << (param_4 & 0x1f);
      for (uVar5 = (uVar9 & 0x7fffffff) >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
        *param_5 = 0;
        param_5 = param_5 + 1;
      }
      for (iVar8 = (uVar9 & 1) << 1; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)param_5 = 0;
        param_5 = (undefined4 *)((int)param_5 + 1);
      }
      return 1;
    }
    return 0;
  }
  uVar12 = (uint)param_4;
  bVar11 = 0x10 - param_4;
  local_14 = uVar12;
  uVar6 = uVar9;
  uVar5 = uVar12;
  if (uVar12 != 0) {
    do {
      auStack_60[uVar9] = auStack_60[uVar9] >> (bVar11 & 0x1f);
      uVar6 = uVar9 + 1;
      aiStack_a4[uVar9] = 1 << ((byte)(uVar5 - 1) & 0x1f);
      uVar9 = uVar6;
      uVar5 = uVar5 - 1;
    } while (uVar6 <= uVar12);
    if (0x10 < uVar6) goto LAB_01008866;
  }
  iVar8 = 0x10 - uVar6;
  do {
    bVar7 = (byte)iVar8;
    uVar9 = uVar6 + 1;
    iVar8 = iVar8 + -1;
    aiStack_a4[uVar6] = 1 << (bVar7 & 0x1f);
    uVar6 = uVar9;
  } while (uVar9 < 0x11);
LAB_01008866:
  uVar9 = auStack_60[uVar12 + 1] >> (bVar11 & 0x1f);
  local_18 = (uint)bVar11;
  if (uVar9 != 0x10000) {
    uVar5 = (1 << (param_4 & 0x1f)) - uVar9;
    puVar14 = (undefined4 *)((int)param_5 + uVar9 * 2);
    for (uVar6 = (uVar5 & 0x7fffffff) >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    }
    for (uVar9 = uVar5 * 2 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined1 *)puVar14 = 0;
      puVar14 = (undefined4 *)((int)puVar14 + 1);
    }
  }
  local_c = param_2;
  local_10 = 0;
  if (0 < (int)param_2) {
    do {
      uVar9 = local_18;
      bVar11 = *(byte *)(local_10 + param_3);
      if (bVar11 != 0) {
        puVar1 = auStack_60 + bVar11;
        uVar5 = *puVar1;
        uVar6 = aiStack_a4[bVar11] + uVar5;
        if (param_4 < bVar11) {
          *puVar1 = uVar6;
          iVar8 = uVar5 << ((byte)local_14 & 0x1f);
          psVar10 = (short *)((int)param_5 + (uVar5 >> ((byte)uVar9 & 0x1f)) * 2);
          local_5 = bVar11 - param_4;
          do {
            if (*psVar10 == 0) {
              *(undefined2 *)(local_c * 4 + 2 + param_6) = 0;
              *(undefined2 *)(local_c * 4 + param_6) = 0;
              sVar3 = (short)local_c;
              local_c = local_c + 1;
              *psVar10 = -sVar3;
            }
            psVar10 = (short *)(param_6 + *psVar10 * -4);
            if ((short)iVar8 < 0) {
              psVar10 = psVar10 + 1;
            }
            iVar8 = iVar8 << 1;
            local_5 = local_5 + -1;
          } while (local_5 != '\0');
          *psVar10 = (short)local_10;
        }
        else {
          if ((uint)(1 << ((byte)local_14 & 0x1f)) < uVar6) {
            return 0;
          }
          if (uVar5 < uVar6) {
            uVar4 = (undefined2)local_10;
            puVar14 = (undefined4 *)((int)param_5 + uVar5 * 2);
            for (uVar9 = uVar6 - uVar5 >> 1; uVar9 != 0; uVar9 = uVar9 - 1) {
              *puVar14 = CONCAT22(uVar4,uVar4);
              puVar14 = puVar14 + 1;
            }
            for (uVar9 = (uint)((uVar6 - uVar5 & 1) != 0); uVar9 != 0; uVar9 = uVar9 - 1) {
              *(undefined2 *)puVar14 = uVar4;
              puVar14 = (undefined4 *)((int)puVar14 + 2);
            }
          }
          *puVar1 = uVar6;
        }
      }
      local_10 = local_10 + 1;
    } while (local_10 < (int)param_2);
  }
  return 1;
}



/* VA 0100898b */

int FUN_0100898b(undefined4 param_1,byte *param_2,undefined4 *param_3)

{
  ushort *puVar1;
  ushort uVar2;
  byte bVar3;
  int iVar4;
  undefined2 *puVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  ushort uVar11;
  undefined4 *puVar12;
  ushort auStack_54 [17];
  short local_32;
  short sStack_30;
  undefined4 local_2e [3];
  undefined2 local_20 [10];
  ushort *local_c;
  byte local_5;

  puVar12 = local_2e;
  for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  iVar8 = 8;
  pbVar9 = param_2;
  do {
    (&sStack_30)[*pbVar9] = (&sStack_30)[*pbVar9] + 1;
    pbVar9 = pbVar9 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  bVar7 = 0xf;
  auStack_54[1] = 0;
  iVar4 = 0;
  iVar8 = 0x10;
  do {
    bVar3 = bVar7 & 0x1f;
    bVar7 = bVar7 - 1;
    *(short *)((int)auStack_54 + iVar4 + 4) =
         (*(short *)((int)local_2e + iVar4) << bVar3) + *(short *)((int)auStack_54 + iVar4 + 2);
    iVar4 = iVar4 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 0;
  if (local_32 == 0) {
    bVar7 = 6;
    iVar4 = 7;
    do {
      puVar1 = (ushort *)((int)auStack_54 + iVar8 + 2);
      *puVar1 = *puVar1 >> 9;
      bVar3 = bVar7 & 0x1f;
      bVar7 = bVar7 - 1;
      iVar4 = iVar4 + -1;
      *(short *)((int)local_2e + iVar8) = (short)(1 << bVar3);
      iVar8 = iVar8 + 2;
    } while (iVar4 != 0);
    bVar7 = 8;
    puVar5 = local_20;
    iVar8 = 9;
    do {
      bVar3 = bVar7 & 0x1f;
      bVar7 = bVar7 - 1;
      *puVar5 = (short)(1 << bVar3);
      puVar5 = puVar5 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    puVar12 = param_3;
    for (iVar8 = 0x20; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    local_5 = 0;
    do {
      bVar7 = param_2[local_5];
      if (bVar7 != 0) {
        local_c = auStack_54 + bVar7;
        uVar2 = *local_c;
        uVar11 = (&sStack_30)[bVar7] + uVar2;
        if (0x80 < uVar11) {
          return 0;
        }
        if (uVar2 < uVar11) {
          uVar6 = (uint)uVar11 - (uint)uVar2;
          pbVar9 = (byte *)((uint)uVar2 + (int)param_3);
          for (uVar10 = (uVar6 & 0xffff) >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(uint *)pbVar9 = CONCAT22(CONCAT11(local_5,local_5),CONCAT11(local_5,local_5));
            pbVar9 = pbVar9 + 4;
          }
          for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *pbVar9 = local_5;
            pbVar9 = pbVar9 + 1;
          }
        }
        *local_c = uVar11;
      }
      local_5 = local_5 + 1;
    } while (local_5 < 8);
    iVar8 = 1;
  }
  return iVar8;
}



/* VA 01008a9e */

BOOL VerQueryValueA(LPCVOID pBlock,LPCSTR lpSubBlock,LPVOID *lplpBuffer,PUINT puLen)

{
  BOOL BVar1;

                    /* WARNING: Could not recover jumptable at 0x01008a9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = VerQueryValueA(pBlock,lpSubBlock,lplpBuffer,puLen);
  return BVar1;
}



/* VA 01008aa4 */

BOOL GetFileVersionInfoA(LPCSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lpData)

{
  BOOL BVar1;

                    /* WARNING: Could not recover jumptable at 0x01008aa4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetFileVersionInfoA(lptstrFilename,dwHandle,dwLen,lpData);
  return BVar1;
}



/* VA 01008aaa */

DWORD GetFileVersionInfoSizeA(LPCSTR lptstrFilename,LPDWORD lpdwHandle)

{
  DWORD DVar1;

                    /* WARNING: Could not recover jumptable at 0x01008aaa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = GetFileVersionInfoSizeA(lptstrFilename,lpdwHandle);
  return DVar1;
}
