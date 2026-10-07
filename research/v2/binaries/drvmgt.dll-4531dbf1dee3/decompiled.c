/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 4531dbf1dee3e48b9bf2da45ba7854990287c64c73da4cf406d7f9d647256774 */

/* VA 10001000 */

undefined4 __cdecl FUN_10001000(int *param_1)

{
  int iVar1;

  iVar1 = *param_1;
  if (iVar1 == 0) {
    return 0;
  }
  if ((iVar1 == 1) && ((uint)param_1[1] < 3)) {
    return 0;
  }
  return CONCAT22((short)((uint)iVar1 >> 0x10),1);
}



/* VA 10001020 */

undefined4 FUN_10001020(void)

{
  HANDLE hObject;
  BOOL BVar1;

  hObject = (HANDLE)FUN_10001040();
  if (hObject == (HANDLE)0xffffffff) {
    return 0xffff0000;
  }
  BVar1 = CloseHandle(hObject);
  return CONCAT22((short)((uint)BVar1 >> 0x10),1);
}



/* VA 10001040 */

void FUN_10001040(void)

{
  CHAR local_100 [256];

  wsprintfA(local_100,s______s_10006030,s_Secdrv_10006038);
  CreateFileA(local_100,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  return;
}



/* VA 10001090 */

bool FUN_10001090(void)

{
  HANDLE hDevice;
  BOOL BVar1;
  DWORD local_4;

  hDevice = (HANDLE)FUN_10001040();
  if (hDevice == (HANDLE)0xffffffff) {
    return false;
  }
  BVar1 = DeviceIoControl(hDevice,0xef002407,DAT_100087b8,0x514,(LPVOID)((int)DAT_100087b8 + 0x514),
                          0x610,&local_4,(LPOVERLAPPED)0x0);
  if (hDevice != (HANDLE)0x0) {
    CloseHandle(hDevice);
  }
  return BVar1 != 0;
}



/* VA 100010f0 */

undefined4 FUN_100010f0(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;

  puVar1 = DAT_100087b8;
  if (DAT_100087b8 == (undefined4 *)0x0) {
    DAT_100087b8 = (undefined4 *)FUN_10001f00(0xb24);
    if (DAT_100087b8 == (undefined4 *)0x0) {
      return 0;
    }
    puVar3 = DAT_100087b8;
    for (iVar2 = 0x2c9; puVar1 = DAT_100087b8, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    *DAT_100087b8 = 1;
    DAT_100087b8[1] = 3;
    DAT_100087b8[2] = 0;
  }
  return CONCAT22((short)((uint)puVar1 >> 0x10),1);
}



/* VA 10001150 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 __fastcall FUN_10001150(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,_DAT_7ffe0000);
}



/* VA 10001170 */

undefined4 __fastcall
FUN_10001170(undefined4 param_1,undefined4 param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_8;
  int local_4;

  local_8 = 0xf367ac7f;
  uVar3 = FUN_10001150(param_1,param_2);
  FUN_10001620(&local_8,&local_4);
  iVar2 = 0xc;
  *param_3 = (uint)uVar3;
  do {
    uVar1 = FUN_10001670(&local_4);
    *(uint *)((int)param_3 + iVar2) = uVar1;
    iVar2 = iVar2 + -4;
    *param_3 = *param_3 ^ uVar1;
  } while (iVar2 != 0);
  *param_4 = (uint)uVar3;
  return CONCAT22((short)((uint)param_4 >> 0x10),1);
}



/* VA 100011d0 */

bool __fastcall FUN_100011d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  undefined8 uVar1;

  uVar1 = FUN_10001150(param_1,param_2);
  return (bool)('\x01' - (10U < (uint)((int)uVar1 - *param_4)));
}



/* VA 100011f0 */

undefined4 __cdecl
FUN_100011f0(undefined4 param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;

  iVar2 = DAT_100087b8;
  iVar1 = DAT_100087b8 + 0x10;
  *(undefined4 *)(DAT_100087b8 + 0xc) = param_1;
  FUN_10001170(param_4,iVar1,(uint *)iVar1,(uint *)param_4);
  *(uint *)(iVar2 + 0x410) = param_3;
  puVar4 = (undefined4 *)(iVar2 + 0x414);
  for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar4 = *param_2;
    param_2 = param_2 + 1;
    puVar4 = puVar4 + 1;
  }
  for (uVar3 = param_3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar4 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  return CONCAT22((short)(param_3 >> 0x10),1);
}



/* VA 10001240 */

undefined4 __cdecl FUN_10001240(undefined4 *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined3 extraout_var;
  uint uVar5;
  undefined4 *puVar6;

  iVar2 = DAT_100087b8;
  uVar4 = FUN_10001000((int *)(DAT_100087b8 + 0x514));
  if ((short)uVar4 == 0) {
    return 0x6f;
  }
  iVar1 = iVar2 + 0x520;
  bVar3 = FUN_100011d0(param_3,iVar1,iVar1,(int *)param_3);
  if ((short)CONCAT31(extraout_var,bVar3) == 0) {
    return 0x70;
  }
  puVar6 = (undefined4 *)(iVar2 + 0x924);
  for (uVar5 = param_2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *param_1 = *puVar6;
    puVar6 = puVar6 + 1;
    param_1 = param_1 + 1;
  }
  for (uVar5 = param_2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)param_1 = *(undefined1 *)puVar6;
    puVar6 = (undefined4 *)((int)puVar6 + 1);
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return 0x6e;
}



/* VA 100012b0 */

int __cdecl
FUN_100012b0(undefined4 param_1,undefined4 *param_2,uint param_3,undefined4 *param_4,uint param_5,
            byte *param_6)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined1 local_4 [4];

  uVar2 = FUN_10001020();
  if (((short)uVar2 == 0) && (iVar3 = FUN_10001e50(param_6), iVar3 != 100)) {
    return iVar3;
  }
  uVar2 = FUN_100010f0();
  if ((short)uVar2 == 0) {
    return 0x65;
  }
  uVar2 = FUN_100011f0(param_1,param_2,param_3,local_4);
  if ((short)uVar2 == 0) {
    return 0x65;
  }
  bVar1 = FUN_10001090();
  if ((short)CONCAT31(extraout_var,bVar1) == 0) {
    return 0x65;
  }
  iVar3 = FUN_10001240(param_4,param_5,local_4);
  if (iVar3 != 0x6e) {
    if (iVar3 != 0x6f) {
      return 0x65;
    }
    iVar3 = FUN_10001ec0(param_6);
    if (iVar3 != 100) {
      return iVar3;
    }
    uVar2 = FUN_100011f0(param_1,param_2,param_3,local_4);
    if ((short)uVar2 == 0) {
      return 0x65;
    }
    bVar1 = FUN_10001090();
    if ((short)CONCAT31(extraout_var_00,bVar1) == 0) {
      return 0x65;
    }
    iVar3 = FUN_10001240(param_4,param_5,local_4);
    if (iVar3 != 0x6e) {
      return 0x65;
    }
  }
  return 100;
}



/* VA 100013d0 */

int __cdecl Setup(LPCSTR param_1,byte *param_2)

{
  int iVar1;

                    /* 0x13d0  3  Setup */
  if (param_2 == (byte *)0x0) {
    return 0x65;
  }
  iVar1 = FUN_100012b0(0x3e,(undefined4 *)0x0,0,&param_2,4,param_2);
  if (iVar1 == 100) {
    if (param_2 != (byte *)0x5278d11b) {
      return 0x65;
    }
    FUN_10001470(param_1);
    iVar1 = 100;
  }
  return iVar1;
}



/* VA 10001420 */

int __cdecl Remove(LPCSTR param_1)

{
  uint uVar1;
  DWORD DVar2;
  int iVar3;

                    /* 0x1420  2  Remove */
  uVar1 = FUN_10001500(param_1);
  if ((short)uVar1 == 0) {
    return 0x6b;
  }
  DVar2 = FUN_10001550();
  if (DVar2 != 0) {
    return 100;
  }
  iVar3 = FUN_10001d60();
  FUN_100015d0();
  return iVar3;
}



/* VA 10001460 */

undefined4 _DllMain_12(void)

{
                    /* 0x1460  1  _DllMain@12 */
  return 1;
}



/* VA 10001470 */

uint __cdecl FUN_10001470(LPCSTR param_1)

{
  uint uVar1;
  LSTATUS LVar2;
  HKEY local_c;
  DWORD local_8;
  HKEY local_4;

  uVar1 = RegCreateKeyExA((HKEY)0x80000002,s_SOFTWARE_C07ft5Y_10006058,0,(LPSTR)0x0,0,0xf003f,
                          (LPSECURITY_ATTRIBUTES)0x0,&local_c,&local_8);
  if (uVar1 != 0) {
    return uVar1 & 0xffff0000;
  }
  LVar2 = RegCreateKeyExA(local_c,param_1,0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_4
                          ,&local_8);
  uVar1 = RegCloseKey(local_c);
  if (LVar2 != 0) {
    return uVar1 & 0xffff0000;
  }
  LVar2 = RegCloseKey(local_4);
  return CONCAT22((short)((uint)LVar2 >> 0x10),1);
}



/* VA 10001500 */

uint __cdecl FUN_10001500(LPCSTR param_1)

{
  uint uVar1;
  LSTATUS LVar2;
  HKEY local_4;

  uVar1 = RegOpenKeyExA((HKEY)0x80000002,s_SOFTWARE_C07ft5Y_10006058,0,0xf003f,&local_4);
  if (uVar1 != 0) {
    return uVar1 & 0xffff0000;
  }
  LVar2 = RegDeleteKeyA(local_4,param_1);
  RegCloseKey(local_4);
  return (uint)(LVar2 == 0);
}



/* VA 10001550 */

DWORD FUN_10001550(void)

{
  LSTATUS LVar1;
  DWORD dwIndex;
  HKEY local_110;
  DWORD local_10c;
  _FILETIME local_108;
  CHAR local_100 [256];

  dwIndex = 0;
  LVar1 = RegOpenKeyExA((HKEY)0x80000002,s_SOFTWARE_C07ft5Y_10006058,0,0xf003f,&local_110);
  if (LVar1 != 0) {
    return 0;
  }
  while( true ) {
    local_10c = 0x100;
    LVar1 = RegEnumKeyExA(local_110,dwIndex,local_100,&local_10c,(LPDWORD)0x0,(LPSTR)0x0,
                          (LPDWORD)0x0,&local_108);
    if (LVar1 != 0) break;
    dwIndex = dwIndex + 1;
  }
  RegCloseKey(local_110);
  return dwIndex;
}



/* VA 100015d0 */

uint FUN_100015d0(void)

{
  uint uVar1;
  LSTATUS LVar2;
  HKEY local_4;

  uVar1 = RegOpenKeyExA((HKEY)0x80000002,s_SOFTWARE_10006040,0,0xf003f,&local_4);
  if (uVar1 != 0) {
    return uVar1 & 0xffff0000;
  }
  LVar2 = RegDeleteKeyA(local_4,s_C07ft5Y_10006050);
  RegCloseKey(local_4);
  return (uint)(LVar2 == 0);
}



/* VA 10001620 */

void __cdecl FUN_10001620(undefined4 *param_1,undefined4 *param_2)

{
  *param_2 = *param_1;
  return;
}



/* VA 10001670 */

int __cdecl FUN_10001670(int *param_1)

{
  *param_1 = *param_1 * -0xd5acb1b + 0x361962e9;
  return *param_1;
}



/* VA 100017a0 */

int __cdecl FUN_100017a0(byte *param_1)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  LPCSTR pCVar4;
  char *pcVar5;
  byte local_308 [4];
  CHAR local_304 [256];
  byte local_204 [256];
  byte local_104 [260];

  GetSystemDirectoryA(local_304,0x100);
  pcVar5 = s_drivers__1000608c;
  pCVar4 = &DAT_10006088;
  iVar1 = lstrlenA(local_304);
  wsprintfA(local_304 + iVar1,pCVar4,pcVar5);
  pcVar5 = s_SECDRV_SYS_1000607c;
  pCVar4 = &DAT_10006088;
  iVar1 = lstrlenA(local_304);
  wsprintfA(local_304 + iVar1,pCVar4,pcVar5);
  if (param_1 == (byte *)0x0) {
    return 0x65;
  }
  FUN_100020c0(param_1,local_308,local_204,(byte *)0x0,(byte *)0x0);
  FUN_10002020(local_104,local_308,local_204,(byte *)s_SECDRV_1000606c,&DAT_10006074);
  FUN_10001fd0(local_304,0x80);
  BVar2 = CopyFileA((LPCSTR)local_104,local_304,0);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    return (-(uint)(DVar3 != 5) & 0xfffffffe) + 0x67;
  }
  return 100;
}



/* VA 100018b0 */

int FUN_100018b0(void)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  LPCSTR pCVar4;
  char *pcVar5;
  CHAR local_100 [256];

  GetSystemDirectoryA(local_100,0x100);
  pcVar5 = s_drivers__1000608c;
  pCVar4 = &DAT_10006088;
  iVar1 = lstrlenA(local_100);
  wsprintfA(local_100 + iVar1,pCVar4,pcVar5);
  pcVar5 = s_SECDRV_SYS_1000607c;
  pCVar4 = &DAT_10006088;
  iVar1 = lstrlenA(local_100);
  wsprintfA(local_100 + iVar1,pCVar4,pcVar5);
  BVar2 = DeleteFileA(local_100);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    return (-(uint)(DVar3 != 5) & 0xfffffffe) + 0x67;
  }
  return 100;
}



/* VA 10001950 */

uint __cdecl FUN_10001950(SC_HANDLE param_1)

{
  uint in_EAX;
  BOOL BVar1;
  DWORD dwAceIndex;
  PACL local_420;
  char *local_41c;
  int local_418;
  DWORD local_414;
  BOOL local_410;
  uint local_40c [3];
  undefined1 local_400 [512];
  undefined1 local_200 [512];

  if (param_1 != (SC_HANDLE)0x0) {
    BVar1 = QueryServiceObjectSecurity(param_1,4,local_200,0x200,&local_414);
    in_EAX = 0;
    if (((BVar1 != 0) &&
        (in_EAX = GetSecurityDescriptorDacl(local_200,&local_418,&local_420,&local_410),
        (short)in_EAX != 0)) && (in_EAX = 0, local_418 != 0)) {
      BVar1 = GetAclInformation(local_420,local_40c,0xc,AclSizeInformation);
      in_EAX = 0;
      if (BVar1 != 0) {
        dwAceIndex = 0;
        if (local_40c[0] != 0) {
          do {
            BVar1 = GetAce(local_420,dwAceIndex,&local_41c);
            in_EAX = 0;
            if (BVar1 == 0) goto LAB_10001a70;
            if (*local_41c == '\0') {
              *(uint *)(local_41c + 4) = *(uint *)(local_41c + 4) | 0x70;
              *(uint *)(local_41c + 4) = *(uint *)(local_41c + 4) | 2;
            }
            dwAceIndex = dwAceIndex + 1;
          } while (dwAceIndex < local_40c[0]);
        }
        BVar1 = InitializeSecurityDescriptor(local_400,1);
        in_EAX = 0;
        if (BVar1 != 0) {
          BVar1 = SetSecurityDescriptorDacl(local_400,1,local_420,0);
          in_EAX = 0;
          if (BVar1 != 0) {
            BVar1 = SetServiceObjectSecurity(param_1,4,local_400);
            return (uint)(BVar1 != 0);
          }
        }
      }
    }
  }
LAB_10001a70:
  return in_EAX & 0xffff0000;
}



/* VA 10001a80 */

int __cdecl FUN_10001a80(byte *param_1)

{
  SC_HANDLE hSCManager;
  DWORD DVar1;
  int iVar2;
  SC_HANDLE hService;
  uint uVar3;
  int iVar4;
  LPCSTR pCVar5;
  char *pcVar6;
  CHAR local_100 [256];

  hSCManager = OpenSCManagerA((LPCSTR)0x0,(LPCSTR)0x0,0xf003f);
  if (hSCManager == (SC_HANDLE)0x0) {
    DVar1 = GetLastError();
    return (-(uint)(DVar1 != 5) & 0xfffffffe) + 0x67;
  }
  GetSystemDirectoryA(local_100,0x100);
  pcVar6 = s_drivers__1000608c;
  pCVar5 = &DAT_10006088;
  iVar2 = lstrlenA(local_100);
  wsprintfA(local_100 + iVar2,pCVar5,pcVar6);
  pcVar6 = s_SECDRV_SYS_1000607c;
  pCVar5 = &DAT_10006088;
  iVar2 = lstrlenA(local_100);
  wsprintfA(local_100 + iVar2,pCVar5,pcVar6);
  hService = CreateServiceA(hSCManager,s_Secdrv_10006038,s_Secdrv_10006038,0xf01ff,1,3,1,local_100,
                            (LPCSTR)0x0,(LPDWORD)0x0,(LPCSTR)0x0,(LPCSTR)0x0,(LPCSTR)0x0);
  iVar2 = 0x65;
  if (hService != (SC_HANDLE)0x0) {
    uVar3 = FUN_10001950(hService);
    if ((short)uVar3 == 0) {
      DeleteService(hService);
    }
    else {
      iVar4 = FUN_100017a0(param_1);
      if (iVar4 == 100) {
        iVar2 = 100;
      }
    }
  }
  CloseServiceHandle(hSCManager);
  if (hService != (SC_HANDLE)0x0) {
    CloseServiceHandle(hService);
  }
  return iVar2;
}



/* VA 10001b90 */

int FUN_10001b90(void)

{
  SC_HANDLE hSCManager;
  SC_HANDLE hService;
  DWORD DVar1;
  BOOL BVar2;
  uint uVar3;
  int local_20;
  _SERVICE_STATUS local_1c;

  hSCManager = OpenSCManagerA((LPCSTR)0x0,(LPCSTR)0x0,1);
  if (hSCManager == (SC_HANDLE)0x0) {
    return 0x65;
  }
  hService = OpenServiceA(hSCManager,s_Secdrv_10006038,0x34);
  DVar1 = GetLastError();
  CloseServiceHandle(hSCManager);
  if (hService == (SC_HANDLE)0x0) {
    return (-(uint)(DVar1 != 0x424) & 0xfffffffd) + 0x68;
  }
  local_20 = 100;
  BVar2 = QueryServiceStatus(hService,&local_1c);
  if (BVar2 == 0) {
    return 0x65;
  }
  if (local_1c.dwCurrentState != 4) {
    if (3 < DAT_100087bc) {
      return 0x65;
    }
    BVar2 = StartServiceA(hService,0,(LPCSTR *)0x0);
    if (BVar2 == 0) {
      DAT_100087bc = DAT_100087bc + 1;
      CloseServiceHandle(hService);
      return 0x6a;
    }
    QueryServiceStatus(hService,&local_1c);
    uVar3 = 0;
    if (local_1c.dwCurrentState != 4) {
      while( true ) {
        QueryServiceStatus(hService,&local_1c);
        Sleep(200);
        if (0x32 < uVar3) break;
        uVar3 = uVar3 + 1;
        if (local_1c.dwCurrentState == 4) {
          CloseServiceHandle(hService);
          return 100;
        }
      }
      local_20 = 0x65;
    }
  }
  CloseServiceHandle(hService);
  return local_20;
}



/* VA 10001ce0 */

undefined4 FUN_10001ce0(void)

{
  SC_HANDLE hSCManager;
  SC_HANDLE hService;
  BOOL BVar1;
  undefined4 uVar2;
  _SERVICE_STATUS local_1c;

  hSCManager = OpenSCManagerA((LPCSTR)0x0,(LPCSTR)0x0,1);
  if (hSCManager == (SC_HANDLE)0x0) {
    return 0x65;
  }
  hService = OpenServiceA(hSCManager,s_Secdrv_10006038,0x34);
  CloseServiceHandle(hSCManager);
  if (hService == (SC_HANDLE)0x0) {
    return 0x65;
  }
  uVar2 = 0x65;
  BVar1 = ControlService(hService,1,&local_1c);
  if (BVar1 != 0) {
    uVar2 = 100;
  }
  CloseServiceHandle(hService);
  return uVar2;
}



/* VA 10001d60 */

int FUN_10001d60(void)

{
  SC_HANDLE hSCManager;
  SC_HANDLE hService;
  DWORD DVar1;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  _SERVICE_STATUS local_1c;

  hSCManager = OpenSCManagerA((LPCSTR)0x0,(LPCSTR)0x0,1);
  if (hSCManager == (SC_HANDLE)0x0) {
    return 0x65;
  }
  hService = OpenServiceA(hSCManager,s_Secdrv_10006038,0xf01ff);
  DVar1 = GetLastError();
  CloseServiceHandle(hSCManager);
  if (hService == (SC_HANDLE)0x0) {
    return (DVar1 == 0x424) + 0x67;
  }
  iVar4 = 100;
  BVar2 = QueryServiceStatus(hService,&local_1c);
  if (BVar2 != 0) {
    if (local_1c.dwCurrentState != 4) goto LAB_10001df7;
    BVar2 = ControlService(hService,1,&local_1c);
    if (BVar2 != 0) goto LAB_10001df7;
  }
  iVar4 = 0x65;
LAB_10001df7:
  if (iVar4 == 100) {
    BVar2 = DeleteService(hService);
    if (BVar2 == 0) {
      DVar1 = GetLastError();
      return (-(uint)(DVar1 != 5) & 0xfffffffe) + 0x67;
    }
    CloseServiceHandle(hService);
    iVar3 = FUN_100018b0();
    if (iVar3 != 100) {
      return 0x69;
    }
  }
  else {
    CloseServiceHandle(hService);
  }
  return iVar4;
}



/* VA 10001e50 */

int __cdecl FUN_10001e50(byte *param_1)

{
  int iVar1;

  iVar1 = FUN_10001b90();
  switch(iVar1) {
  case 100:
  case 0x65:
    break;
  default:
    iVar1 = 0x65;
    break;
  case 0x68:
    iVar1 = FUN_10001a80(param_1);
    if (iVar1 == 100) goto LAB_10001e89;
    break;
  case 0x6a:
    iVar1 = FUN_100017a0(param_1);
    if (iVar1 != 100) {
      return iVar1;
    }
LAB_10001e89:
    iVar1 = FUN_10001b90();
    return (iVar1 != 100) + 100;
  }
  return iVar1;
}



/* VA 10001ec0 */

int __cdecl FUN_10001ec0(byte *param_1)

{
  int iVar1;

  iVar1 = FUN_10001ce0();
  if (iVar1 != 100) {
    return 0x65;
  }
  iVar1 = FUN_100017a0(param_1);
  if (iVar1 == 100) {
    iVar1 = FUN_10001b90();
    iVar1 = (iVar1 != 100) + 100;
  }
  return iVar1;
}



/* VA 10001f00 */

void __cdecl FUN_10001f00(uint param_1)

{
  FUN_10001f20(param_1,DAT_100087e4);
  return;
}



/* VA 10001f20 */

int * __cdecl FUN_10001f20(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;

  if (param_1 < 0xffffffe1) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    do {
      if (param_1 < 0xffffffe1) {
        piVar1 = FUN_10001f70(param_1);
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
      iVar2 = FUN_100024a0(param_1);
    } while (iVar2 != 0);
  }
  return (int *)0x0;
}



/* VA 10001f70 */

int * __cdecl FUN_10001f70(int param_1)

{
  int *piVar1;
  uint dwBytes;

  dwBytes = param_1 + 0xfU & 0xfffffff0;
  if (dwBytes <= DAT_10008184) {
    FUN_100025f0(9);
    piVar1 = FUN_10002ad0(param_1 + 0xfU >> 4);
    FUN_10002670(9);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
  }
  piVar1 = HeapAlloc(DAT_10009c50,0,dwBytes);
  return piVar1;
}



/* VA 10001fd0 */

undefined4 __cdecl FUN_10001fd0(LPCSTR param_1,byte param_2)

{
  DWORD DVar1;
  BOOL BVar2;

  DVar1 = GetFileAttributesA(param_1);
  if (DVar1 != 0xffffffff) {
    if ((param_2 & 0x80) == 0) {
      DVar1 = DVar1 | 1;
    }
    else {
      DVar1 = DVar1 & 0xfffffffe;
    }
    BVar2 = SetFileAttributesA(param_1,DVar1);
    if (BVar2 != 0) {
      return 0;
    }
  }
  DVar1 = GetLastError();
  FUN_10002e90(DVar1);
  return 0xffffffff;
}



/* VA 10002020 */

void __cdecl FUN_10002020(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;

  if ((param_2 != (byte *)0x0) && (*param_2 != 0)) {
    *param_1 = *param_2;
    param_1[1] = 0x3a;
    param_1 = param_1 + 2;
  }
  if ((param_3 != (byte *)0x0) && (bVar1 = *param_3, pbVar2 = param_3, bVar1 != 0)) {
    do {
      pbVar3 = param_1;
      *pbVar3 = bVar1;
      bVar1 = pbVar2[1];
      param_1 = pbVar3 + 1;
      pbVar2 = pbVar2 + 1;
    } while (bVar1 != 0);
    pbVar2 = FUN_10002f30(param_3,pbVar2);
    if ((*pbVar2 != 0x2f) && (*pbVar2 != 0x5c)) {
      *param_1 = 0x5c;
      param_1 = pbVar3 + 2;
    }
  }
  if (param_4 != (byte *)0x0) {
    bVar1 = *param_4;
    while (bVar1 != 0) {
      *param_1 = bVar1;
      pbVar2 = param_4 + 1;
      param_1 = param_1 + 1;
      param_4 = param_4 + 1;
      bVar1 = *pbVar2;
    }
  }
  if (param_5 == (byte *)0x0) {
    *param_1 = 0;
  }
  else {
    if ((*param_5 != 0) && (*param_5 != 0x2e)) {
      *param_1 = 0x2e;
      param_1 = param_1 + 1;
    }
    bVar1 = *param_5;
    *param_1 = bVar1;
    if (bVar1 != 0) {
      do {
        param_1 = param_1 + 1;
        param_5 = param_5 + 1;
        bVar1 = *param_5;
        *param_1 = bVar1;
      } while (bVar1 != 0);
      return;
    }
  }
  return;
}



/* VA 100020c0 */

void __cdecl FUN_100020c0(byte *param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *local_4;

  iVar4 = -1;
  pbVar5 = param_1;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar2 = *pbVar5;
    pbVar5 = pbVar5 + 1;
  } while (bVar2 != 0);
  local_4 = (byte *)0x0;
  if ((iVar4 == -2) || (param_1[1] != 0x3a)) {
    if (param_2 != (byte *)0x0) {
      *param_2 = 0;
    }
  }
  else {
    if (param_2 != (byte *)0x0) {
      FUN_100032d0(param_2,param_1,2);
      param_2[2] = 0;
    }
    param_1 = param_1 + 2;
  }
  bVar2 = *param_1;
  param_2 = (byte *)0x0;
  pbVar5 = param_1;
  while (bVar2 != 0) {
    bVar2 = *pbVar5;
    if ((*(byte *)((int)&DAT_10008858 + bVar2 + 1) & 4) == 0) {
      if ((bVar2 == 0x2f) || (bVar2 == 0x5c)) {
        param_2 = pbVar5 + 1;
      }
      else if (bVar2 == 0x2e) {
        local_4 = pbVar5;
      }
    }
    else {
      pbVar5 = pbVar5 + 1;
    }
    pbVar1 = pbVar5 + 1;
    pbVar5 = pbVar5 + 1;
    bVar2 = *pbVar1;
  }
  if (param_2 == (byte *)0x0) {
    param_2 = param_1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
    }
  }
  else if (param_3 != (byte *)0x0) {
    uVar3 = (int)param_2 - (int)param_1;
    if (0xfe < uVar3) {
      uVar3 = 0xff;
    }
    FUN_100032d0(param_3,param_1,uVar3);
    param_3[uVar3] = 0;
  }
  if ((local_4 == (byte *)0x0) || (local_4 < param_2)) {
    if (param_4 != (byte *)0x0) {
      uVar3 = (int)pbVar5 - (int)param_2;
      if (0xfe < uVar3) {
        uVar3 = 0xff;
      }
      FUN_100032d0(param_4,param_2,uVar3);
      param_4[uVar3] = 0;
    }
    if (param_5 != (byte *)0x0) {
      *param_5 = 0;
    }
  }
  else {
    if (param_4 != (byte *)0x0) {
      uVar3 = (int)local_4 - (int)param_2;
      if (0xfe < uVar3) {
        uVar3 = 0xff;
      }
      FUN_100032d0(param_4,param_2,uVar3);
      param_4[uVar3] = 0;
    }
    if (param_5 != (byte *)0x0) {
      uVar3 = (int)pbVar5 - (int)local_4;
      if (0xfe < uVar3) {
        uVar3 = 0xff;
      }
      FUN_100032d0(param_5,local_4,uVar3);
      param_5[uVar3] = 0;
      return;
    }
  }
  return;
}



/* VA 10002240 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10002240(undefined4 param_1,int param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;

  if (param_2 != 1) {
    if (param_2 != 0) {
      if (param_2 == 3) {
        FUN_10003610((undefined *)0x0);
      }
      return 1;
    }
    if (0 < DAT_100087d0) {
      DAT_100087d0 = DAT_100087d0 + -1;
      if (DAT_100089b4 == 0) {
        FUN_100033d0();
      }
      FUN_100038c0();
      FUN_10003540();
      FUN_10002500();
      return 1;
    }
    return 0;
  }
  DAT_1000897c = GetVersion();
  if (DAT_100087e0 == 0) {
    if (((char)DAT_1000897c == '\x03') && ((DAT_1000897c & 0x80000000) != 0)) {
      FUN_10003e20(2);
    }
    hModule = GetModuleHandleA("kernel32.dll");
    if (hModule != (HMODULE)0x0) {
      pFVar1 = GetProcAddress(hModule,"IsTNT");
      if (pFVar1 != (FARPROC)0x0) {
        FUN_10003e20(1);
      }
    }
  }
  iVar2 = FUN_100024c0();
  if (iVar2 == 0) {
    return 0;
  }
  _DAT_10008988 = DAT_1000897c >> 8 & 0xff;
  _DAT_10008984 = DAT_1000897c & 0xff;
  _DAT_10008980 = _DAT_10008984 * 0x100 + _DAT_10008988;
  DAT_1000897c = DAT_1000897c >> 0x10;
  iVar2 = FUN_100034e0();
  if (iVar2 == 0) {
    FUN_10002500();
    return 0;
  }
  DAT_10009c54 = GetCommandLineA();
  DAT_100087d4 = FUN_10003cc0();
  if ((DAT_10009c54 != (LPSTR)0x0) && (DAT_100087d4 != (LPSTR)0x0)) {
    FUN_100036b0();
    FUN_100032c0();
    FUN_10003a10();
    FUN_10003920();
    FUN_10003380();
    DAT_100087d0 = DAT_100087d0 + 1;
    return 1;
  }
  FUN_10003540();
  FUN_10002500();
  return 0;
}



/* VA 100023b0 */

int entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;

  iVar1 = 1;
  if ((param_2 == 0) && (DAT_100087d0 == 0)) {
    return 0;
  }
  if ((param_2 != 1) && (param_2 != 2)) {
LAB_1000240e:
    iVar1 = _DllMain_12();
    if ((param_2 == 1) && (iVar1 == 0)) {
      FUN_10002240(param_1,0);
    }
    if ((param_2 == 0) || (param_2 == 3)) {
      iVar2 = FUN_10002240(param_1,param_2);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      if ((iVar1 != 0) && (DAT_10009c58 != (code *)0x0)) {
        iVar1 = (*DAT_10009c58)(param_1,param_2,param_3);
      }
    }
    return iVar1;
  }
  if (DAT_10009c58 != (code *)0x0) {
    iVar1 = (*DAT_10009c58)(param_1,param_2,param_3);
  }
  if (iVar1 != 0) {
    iVar1 = FUN_10002240(param_1,param_2);
    if (iVar1 != 0) goto LAB_1000240e;
  }
  return 0;
}



/* VA 10002460 */

/* Library Function - Single Match
    __amsg_exit

   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if ((DAT_100087dc == 1) || ((DAT_100087dc == 0 && (DAT_100087e0 == 1)))) {
    FUN_10003e30();
  }
  FUN_10003e70((undefined *)param_1);
  (*(code *)PTR___exit_10006098)(0xff);
  return;
}



/* VA 100024a0 */

undefined4 __cdecl FUN_100024a0(undefined4 param_1)

{
  int iVar1;

  if (DAT_100087e8 != (code *)0x0) {
    iVar1 = (*DAT_100087e8)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



/* VA 100024c0 */

undefined4 FUN_100024c0(void)

{
  undefined **ppuVar1;

  DAT_10009c50 = HeapCreate(0,0x1000,0);
  if (DAT_10009c50 == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = FUN_10002770();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_10009c50);
    return 0;
  }
  return 1;
}



/* VA 10002500 */

void FUN_10002500(void)

{
  undefined **ppuVar1;

  ppuVar1 = &PTR_LOOP_10006160;
  do {
    if (ppuVar1[4] != (undefined *)0x0) {
      VirtualFree(ppuVar1[4],0,0x8000);
    }
    ppuVar1 = (undefined **)*ppuVar1;
  } while (ppuVar1 != &PTR_LOOP_10006160);
  HeapDestroy(DAT_10009c50);
  return;
}



/* VA 10002540 */

void FUN_10002540(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_100060e4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_100060d4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_100060c4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_100060a4);
  return;
}



/* VA 10002570 */

void FUN_10002570(void)

{
  undefined **ppuVar1;

  ppuVar1 = (undefined **)&DAT_100060a0;
  do {
    if (((((LPCRITICAL_SECTION)*ppuVar1 != (LPCRITICAL_SECTION)0x0) &&
         (ppuVar1 != &PTR_DAT_100060e4)) && (ppuVar1 != &PTR_DAT_100060d4)) &&
       ((ppuVar1 != &PTR_DAT_100060c4 && (ppuVar1 != &PTR_DAT_100060a4)))) {
      DeleteCriticalSection((LPCRITICAL_SECTION)*ppuVar1);
      FUN_10004050(*ppuVar1);
    }
    ppuVar1 = ppuVar1 + 1;
  } while ((int)ppuVar1 < 0x10006160);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_100060c4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_100060d4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_100060e4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_100060a4);
  return;
}



/* VA 100025f0 */

void __cdecl FUN_100025f0(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;

  if ((&DAT_100060a0)[param_1] == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)FUN_10001f00(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_100025f0(0x11);
    if ((&DAT_100060a0)[param_1] == 0) {
      InitializeCriticalSection(lpCriticalSection);
      (&DAT_100060a0)[param_1] = lpCriticalSection;
    }
    else {
      FUN_10004050((undefined *)lpCriticalSection);
    }
    FUN_10002670(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_100060a0)[param_1]);
  return;
}



/* VA 10002670 */

void __cdecl FUN_10002670(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_100060a0)[param_1]);
  return;
}



/* VA 10002690 */

void __cdecl FUN_10002690(uint param_1)

{
  if ((0x100084a7 < param_1) && (param_1 < 0x10008709)) {
    FUN_100025f0(((int)(param_1 + 0xefff7b58) >> 5) + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



/* VA 100026d0 */

void __cdecl FUN_100026d0(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_100025f0(param_1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



/* VA 10002700 */

void __cdecl FUN_10002700(uint param_1)

{
  if ((0x100084a7 < param_1) && (param_1 < 0x10008709)) {
    FUN_10002670(((int)(param_1 + 0xefff7b58) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



/* VA 10002740 */

void __cdecl FUN_10002740(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_10002670(param_1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



/* VA 10002770 */

undefined ** FUN_10002770(void)

{
  bool bVar1;
  undefined4 *lpAddress;
  LPVOID pvVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **lpMem;
  undefined4 *puVar5;

  if (DAT_10006170 == -1) {
    lpMem = &PTR_LOOP_10006160;
  }
  else {
    lpMem = HeapAlloc(DAT_10009c50,0,0x2020);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar2 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar2 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_10006160) {
        if (PTR_LOOP_10006160 == (undefined *)0x0) {
          PTR_LOOP_10006160 = (undefined *)&PTR_LOOP_10006160;
        }
        if (PTR_LOOP_10006164 == (undefined *)0x0) {
          PTR_LOOP_10006164 = (undefined *)&PTR_LOOP_10006160;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_10006160;
        lpMem[1] = PTR_LOOP_10006164;
        PTR_LOOP_10006164 = (undefined *)lpMem;
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
  if (lpMem != &PTR_LOOP_10006160) {
    HeapFree(DAT_10009c50,0,lpMem);
  }
  return (undefined **)0x0;
}



/* VA 100028e0 */

void __cdecl FUN_100028e0(undefined **param_1)

{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR_LOOP_10008180 == param_1) {
    PTR_LOOP_10008180 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_10006160) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_10009c50,0,param_1);
    return;
  }
  DAT_10006170 = 0xffffffff;
  return;
}



/* VA 10002940 */

void __cdecl FUN_10002940(int param_1)

{
  BOOL BVar1;
  undefined **ppuVar2;
  int iVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;

  ppuVar6 = (undefined **)PTR_LOOP_10006164;
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
            DAT_10008850 = DAT_10008850 + -1;
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
          FUN_100028e0(ppuVar6);
        }
      }
    }
    if ((ppuVar5 == (undefined **)PTR_LOOP_10006164) || (ppuVar6 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}



/* VA 10002a10 */

int __cdecl FUN_10002a10(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined **ppuVar1;
  uint uVar2;

  ppuVar1 = &PTR_LOOP_10006160;
  while ((param_1 <= ppuVar1[4] || (ppuVar1[5] <= param_1))) {
    ppuVar1 = (undefined **)*ppuVar1;
    if (ppuVar1 == &PTR_LOOP_10006160) {
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



/* VA 10002a70 */

void __cdecl FUN_10002a70(int param_1,int param_2,byte *param_3)

{
  int *piVar1;
  int iVar2;

  iVar2 = param_2 - *(int *)(param_1 + 0x10) >> 0xc;
  piVar1 = (int *)(param_1 + 0x18 + iVar2 * 8);
  *piVar1 = *(int *)(param_1 + 0x18 + iVar2 * 8) + (uint)*param_3;
  *param_3 = 0;
  piVar1[1] = 0xf1;
  if ((*piVar1 == 0xf0) && (DAT_10008850 = DAT_10008850 + 1, DAT_10008850 == 0x20)) {
    FUN_10002940(0x10);
  }
  return;
}



/* VA 10002ad0 */

int * __cdecl FUN_10002ad0(uint param_1)

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

  piVar11 = (int *)PTR_LOOP_10008180;
  do {
    if (piVar11[4] != -1) {
      puVar10 = (uint *)piVar11[2];
      piVar8 = (int *)(((int)puVar10 + (-0x18 - (int)piVar11) >> 3) * 0x1000 + piVar11[4]);
      for (; puVar10 < piVar11 + 0x806; puVar10 = puVar10 + 2) {
        if (((int)param_1 <= (int)*puVar10) && (param_1 < puVar10[1])) {
          piVar5 = (int *)FUN_10002d10(piVar8,*puVar10,param_1);
          if (piVar5 != (int *)0x0) {
            PTR_LOOP_10008180 = (undefined *)piVar11;
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
          piVar5 = (int *)FUN_10002d10(piVar8,*puVar10,param_1);
          if (piVar5 != (int *)0x0) {
            PTR_LOOP_10008180 = (undefined *)piVar11;
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
  } while (piVar11 != (int *)PTR_LOOP_10008180);
  ppuVar7 = &PTR_LOOP_10006160;
  while ((ppuVar7[4] == (undefined *)0xffffffff || (ppuVar7[3] == (undefined *)0x0))) {
    ppuVar7 = (undefined **)*ppuVar7;
    if (ppuVar7 == &PTR_LOOP_10006160) {
      ppuVar7 = FUN_10002770();
      if (ppuVar7 == (undefined **)0x0) {
        return (int *)0x0;
      }
      piVar11 = (int *)ppuVar7[4];
      *(char *)(piVar11 + 2) = (char)param_1;
      PTR_LOOP_10008180 = (undefined *)ppuVar7;
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
  PTR_LOOP_10008180 = (undefined *)ppuVar7;
  ppuVar7[3] = (undefined *)(-(uint)bVar12 & (uint)ppuVar6);
  *(char *)(piVar11 + 2) = (char)param_1;
  ppuVar7[2] = (undefined *)ppuVar3;
  *ppuVar3 = *ppuVar3 + -param_1;
  piVar11[1] = piVar11[1] - param_1;
  *piVar11 = (int)piVar11 + param_1 + 8;
  return piVar11 + 0x40;
}



/* VA 10002d10 */

int __cdecl FUN_10002d10(int *param_1,uint param_2,uint param_3)

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
            goto LAB_10002e5f;
          }
          *param_1 = (int)(pbVar6 + param_3);
          param_1[1] = uVar5 - param_3;
          goto LAB_10002e66;
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
LAB_10002e5f:
            param_1[1] = 0;
          }
LAB_10002e66:
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



/* VA 10002e90 */

void __cdecl FUN_10002e90(uint param_1)

{
  DWORD *pDVar1;
  uint *puVar2;
  int iVar3;

  pDVar1 = FUN_10002f20();
  iVar3 = 0;
  *pDVar1 = param_1;
  puVar2 = &DAT_10008188;
  do {
    if (param_1 == *puVar2) {
      pDVar1 = FUN_10002f10();
      *pDVar1 = *(DWORD *)(iVar3 * 8 + 0x1000818c);
      return;
    }
    puVar2 = puVar2 + 2;
    iVar3 = iVar3 + 1;
  } while (puVar2 < &DAT_100082f0);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    pDVar1 = FUN_10002f10();
    *pDVar1 = 0xd;
    return;
  }
  if ((0xbb < param_1) && (param_1 < 0xcb)) {
    pDVar1 = FUN_10002f10();
    *pDVar1 = 8;
    return;
  }
  pDVar1 = FUN_10002f10();
  *pDVar1 = 0x16;
  return;
}



/* VA 10002f10 */

DWORD * FUN_10002f10(void)

{
  DWORD *pDVar1;

  pDVar1 = FUN_10003590();
  return pDVar1 + 2;
}



/* VA 10002f20 */

DWORD * FUN_10002f20(void)

{
  DWORD *pDVar1;

  pDVar1 = FUN_10003590();
  return pDVar1 + 3;
}



/* VA 10002f30 */

byte * __cdecl FUN_10002f30(byte *param_1,byte *param_2)

{
  byte *pbVar1;

  if (param_2 <= param_1) {
    return (byte *)0x0;
  }
  if (DAT_1000895c != 0) {
    FUN_100025f0(0x19);
    if ((*(byte *)((int)&DAT_10008858 + param_2[-1] + 1) & 4) == 0) {
      pbVar1 = param_2 + -2;
      while ((param_1 <= pbVar1 && ((*(byte *)((int)&DAT_10008858 + *pbVar1 + 1) & 4) != 0))) {
        pbVar1 = pbVar1 + -1;
      }
      FUN_10002670(0x19);
      return param_2 + (-1 - ((int)param_2 - (int)pbVar1 & 1U));
    }
    FUN_10002670(0x19);
    return param_2 + -2;
  }
  return param_2 + -1;
}



/* VA 10002fc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10002fc0(int param_1)

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

  FUN_100025f0(0x19);
  CodePage = FUN_100031e0(param_1);
  if (CodePage == DAT_1000895c) {
    FUN_10002670(0x19);
    return 0;
  }
  if (CodePage != 0) {
    iVar10 = 0;
    pUVar5 = &DAT_100082f8;
    do {
      if (*pUVar5 == CodePage) {
        puVar14 = &DAT_10008858;
        for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar14 = 0;
          puVar14 = puVar14 + 1;
        }
        *(undefined1 *)puVar14 = 0;
        uVar7 = 0;
        iVar10 = iVar10 * 0x30;
        pbVar12 = (byte *)(iVar10 + 0x10008308);
        do {
          bVar3 = *pbVar12;
          for (pbVar13 = pbVar12; (bVar3 != 0 && (bVar3 = pbVar13[1], bVar3 != 0));
              pbVar13 = pbVar13 + 2) {
            uVar8 = (uint)*pbVar13;
            if (uVar8 <= bVar3) {
              bVar4 = (&DAT_100082f0)[uVar7];
              do {
                pbVar2 = (byte *)((int)&DAT_10008858 + uVar8 + 1);
                *pbVar2 = *pbVar2 | bVar4;
                uVar8 = uVar8 + 1;
              } while (uVar8 <= bVar3);
            }
            bVar3 = pbVar13[2];
          }
          uVar7 = uVar7 + 1;
          pbVar12 = pbVar12 + 8;
        } while (uVar7 < 4);
        DAT_1000895c = CodePage;
        _DAT_10008960 = FUN_10003230(CodePage);
        _DAT_10008968 = *(undefined4 *)(iVar10 + 0x100082fc);
        _DAT_1000896c = *(undefined4 *)(iVar10 + 0x10008300);
        _DAT_10008970 = *(undefined4 *)(iVar10 + 0x10008304);
        FUN_10002670(0x19);
        return 0;
      }
      pUVar5 = pUVar5 + 0xc;
      iVar10 = iVar10 + 1;
    } while (pUVar5 < &DAT_100083e8);
    BVar6 = GetCPInfo(CodePage,&local_14);
    if (BVar6 == 1) {
      puVar14 = &DAT_10008858;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar14 = 0;
        puVar14 = puVar14 + 1;
      }
      *(undefined1 *)puVar14 = 0;
      if (local_14.MaxCharSize < 2) {
        DAT_1000895c = 0;
        _DAT_10008960 = 0;
      }
      else {
        if (local_14.LeadByte[0] != '\0') {
          pBVar11 = local_14.LeadByte + 1;
          do {
            bVar3 = *pBVar11;
            if (bVar3 == 0) break;
            for (uVar7 = (uint)pBVar11[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
              *(byte *)((int)&DAT_10008858 + uVar7 + 1) =
                   *(byte *)((int)&DAT_10008858 + uVar7 + 1) | 4;
            }
            pBVar1 = pBVar11 + 1;
            pBVar11 = pBVar11 + 2;
          } while (*pBVar1 != 0);
        }
        uVar7 = 1;
        do {
          *(byte *)((int)&DAT_10008858 + uVar7 + 1) = *(byte *)((int)&DAT_10008858 + uVar7 + 1) | 8;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 0xff);
        DAT_1000895c = CodePage;
        _DAT_10008960 = FUN_10003230(CodePage);
      }
      _DAT_10008968 = 0;
      _DAT_1000896c = 0;
      _DAT_10008970 = 0;
      FUN_10002670(0x19);
      return 0;
    }
    if (DAT_10008974 == 0) {
      FUN_10002670(0x19);
      return 0xffffffff;
    }
  }
  FUN_10003290();
  FUN_10002670(0x19);
  return 0;
}



/* VA 100031e0 */

int __cdecl FUN_100031e0(int param_1)

{
  int iVar1;
  bool bVar2;

  if (param_1 == -2) {
    DAT_10008974 = 1;
                    /* WARNING: Could not recover jumptable at 0x100031fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_10008974 = 1;
                    /* WARNING: Could not recover jumptable at 0x10003212. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_10008af0;
  }
  DAT_10008974 = (uint)bVar2;
  return param_1;
}



/* VA 10003230 */

undefined4 __cdecl FUN_10003230(undefined4 param_1)

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



/* VA 10003290 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10003290(void)

{
  int iVar1;
  undefined4 *puVar2;

  puVar2 = &DAT_10008858;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_1000895c = 0;
  _DAT_10008960 = 0;
  _DAT_10008968 = 0;
  _DAT_1000896c = 0;
  _DAT_10008970 = 0;
  return;
}



/* VA 100032c0 */

void FUN_100032c0(void)

{
  FUN_10002fc0(-3);
  return;
}



/* VA 100032d0 */

byte * __cdecl FUN_100032d0(byte *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;

  if (DAT_1000895c == 0) {
    pbVar3 = (byte *)_strncpy((char *)param_1,(char *)param_2,param_3);
    return pbVar3;
  }
  FUN_100025f0(0x19);
  uVar5 = 0;
  pbVar3 = param_1;
  pbVar6 = param_1;
  if (param_3 != 0) {
    do {
      bVar1 = *param_2;
      uVar5 = param_3 - 1;
      bVar2 = *(byte *)((int)&DAT_10008858 + bVar1 + 1);
      *pbVar6 = bVar1;
      if ((bVar2 & 4) == 0) {
        pbVar3 = pbVar6 + 1;
        param_2 = param_2 + 1;
        if (bVar1 == 0) goto LAB_1000334d;
      }
      else {
        pbVar3 = pbVar6 + 1;
        if (uVar5 == 0) {
          *pbVar6 = 0;
          goto LAB_1000334d;
        }
        bVar1 = param_2[1];
        uVar5 = param_3 - 2;
        *pbVar3 = bVar1;
        pbVar3 = pbVar6 + 2;
        param_2 = param_2 + 2;
        if (bVar1 == 0) {
          *pbVar6 = 0;
          goto LAB_1000334d;
        }
      }
      param_3 = uVar5;
      pbVar6 = pbVar3;
    } while (uVar5 != 0);
    uVar5 = 0;
  }
LAB_1000334d:
  if (uVar5 != 0) {
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      pbVar3[0] = 0;
      pbVar3[1] = 0;
      pbVar3[2] = 0;
      pbVar3[3] = 0;
      pbVar3 = pbVar3 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pbVar3 = 0;
      pbVar3 = pbVar3 + 1;
    }
  }
  FUN_10002670(0x19);
  return param_1;
}



/* VA 10003380 */

void FUN_10003380(void)

{
  if (DAT_10009c4c != (code *)0x0) {
    (*DAT_10009c4c)();
  }
  FUN_100034c0((undefined4 *)&DAT_10006008,(undefined4 *)&DAT_10006010);
  FUN_100034c0((undefined4 *)&DAT_10006000,(undefined4 *)&DAT_10006004);
  return;
}



/* VA 100033b0 */

/* Library Function - Single Match
    __exit

   Library: Visual Studio 1998 Release */

void __cdecl __exit(int _Code)

{
  FUN_100033e0(_Code,1,0);
  return;
}



/* VA 100033d0 */

void FUN_100033d0(void)

{
  FUN_100033e0(0,0,1);
  return;
}



/* VA 100033e0 */

void __cdecl FUN_100033e0(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  undefined4 *puVar2;
  UINT uExitCode;

  FUN_100034a0();
  if (DAT_100089b8 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  DAT_100089b4 = 1;
  DAT_100089b0 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_10009c48 != (undefined4 *)0x0) &&
       (puVar2 = (undefined4 *)(DAT_10009c44 + -4), puVar1 = DAT_10009c48, DAT_10009c48 <= puVar2))
    {
      do {
        if ((code *)*puVar2 != (code *)0x0) {
          (*(code *)*puVar2)();
          puVar1 = DAT_10009c48;
        }
        puVar2 = puVar2 + -1;
      } while (puVar1 <= puVar2);
    }
    FUN_100034c0((undefined4 *)&DAT_10006014,(undefined4 *)&DAT_1000601c);
  }
  FUN_100034c0((undefined4 *)&DAT_10006020,(undefined4 *)&DAT_10006024);
  if (param_3 != 0) {
    FUN_100034b0();
    return;
  }
  DAT_100089b8 = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}



/* VA 100034a0 */

void FUN_100034a0(void)

{
  FUN_100025f0(0xd);
  return;
}



/* VA 100034b0 */

void FUN_100034b0(void)

{
  FUN_10002670(0xd);
  return;
}



/* VA 100034c0 */

void __cdecl FUN_100034c0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* VA 100034e0 */

undefined4 FUN_100034e0(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;

  FUN_10002540();
  DAT_100083e8 = TlsAlloc();
  if (DAT_100083e8 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_100042a0(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_100083e8,lpTlsValue);
      if (BVar1 != 0) {
        FUN_10003570((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        *lpTlsValue = DVar2;
        lpTlsValue[1] = 0xffffffff;
        return 1;
      }
    }
  }
  return 0;
}



/* VA 10003540 */

void FUN_10003540(void)

{
  FUN_10002570();
  if (DAT_100083e8 != 0xffffffff) {
    TlsFree(DAT_100083e8);
    DAT_100083e8 = 0xffffffff;
  }
  return;
}



/* VA 10003570 */

void __cdecl FUN_10003570(int param_1)

{
  *(undefined **)(param_1 + 0x50) = &DAT_10008730;
  *(undefined4 *)(param_1 + 0x14) = 1;
  return;
}



/* VA 10003590 */

DWORD * FUN_10003590(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;

  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_100083e8);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)FUN_100042a0(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_100083e8,lpTlsValue);
      if (BVar1 != 0) {
        FUN_10003570((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        *lpTlsValue = DVar2;
        lpTlsValue[1] = 0xffffffff;
        SetLastError(dwErrCode);
        return lpTlsValue;
      }
    }
    __amsg_exit(0x10);
  }
  SetLastError(dwErrCode);
  return lpTlsValue;
}



/* VA 10003610 */

void __cdecl FUN_10003610(undefined *param_1)

{
  if (DAT_100083e8 != 0xffffffff) {
    if ((param_1 != (undefined *)0x0) ||
       (param_1 = TlsGetValue(DAT_100083e8), param_1 != (undefined *)0x0)) {
      if (*(undefined **)(param_1 + 0x24) != (undefined *)0x0) {
        FUN_10004050(*(undefined **)(param_1 + 0x24));
      }
      if (*(undefined **)(param_1 + 0x28) != (undefined *)0x0) {
        FUN_10004050(*(undefined **)(param_1 + 0x28));
      }
      if (*(undefined **)(param_1 + 0x30) != (undefined *)0x0) {
        FUN_10004050(*(undefined **)(param_1 + 0x30));
      }
      if (*(undefined **)(param_1 + 0x38) != (undefined *)0x0) {
        FUN_10004050(*(undefined **)(param_1 + 0x38));
      }
      if (*(undefined **)(param_1 + 0x40) != (undefined *)0x0) {
        FUN_10004050(*(undefined **)(param_1 + 0x40));
      }
      if (*(undefined **)(param_1 + 0x44) != (undefined *)0x0) {
        FUN_10004050(*(undefined **)(param_1 + 0x44));
      }
      FUN_10004050(param_1);
    }
    TlsSetValue(DAT_100083e8,(LPVOID)0x0);
    return;
  }
  return;
}



/* VA 100036b0 */

void FUN_100036b0(void)

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

  puVar2 = (undefined4 *)FUN_10001f00(0x480);
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_10009c40 = 0x20;
  DAT_10009b40 = puVar2;
  if (puVar2 < puVar2 + 0x120) {
    do {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar2[2] = 0;
      puVar2 = puVar2 + 9;
    } while (puVar2 < DAT_10009b40 + 0x120);
  }
  GetStartupInfoA(&local_44);
  if ((local_44.cbReserved2 != 0) && ((UINT *)local_44.lpReserved2 != (UINT *)0x0)) {
    local_48 = *(UINT *)local_44.lpReserved2;
    pUVar8 = (UINT *)((int)local_44.lpReserved2 + 4);
    pbVar4 = (byte *)((int)pUVar8 + local_48);
    if (0x7ff < (int)local_48) {
      local_48 = 0x800;
    }
    if ((int)DAT_10009c40 < (int)local_48) {
      piVar6 = &DAT_10009b44;
      do {
        puVar2 = (undefined4 *)FUN_10001f00(0x480);
        if (puVar2 == (undefined4 *)0x0) {
          local_48 = DAT_10009c40;
          break;
        }
        *piVar6 = (int)puVar2;
        DAT_10009c40 = DAT_10009c40 + 0x20;
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
      } while ((int)DAT_10009c40 < (int)local_48);
    }
    uVar7 = 0;
    if (0 < (int)local_48) {
      do {
        if (((*(HANDLE *)pbVar4 != (HANDLE)0xffffffff) && ((*pUVar8 & 1) != 0)) &&
           (((*pUVar8 & 8) != 0 || (DVar3 = GetFileType(*(HANDLE *)pbVar4), DVar3 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_10009b40)[(int)uVar7 >> 5] + (uVar7 & 0x1f) * 0x24);
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
    puVar2 = DAT_10009b40 + iVar5 * 9;
    if (DAT_10009b40[iVar5 * 9] == -1) {
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
        goto LAB_1000389e;
      }
      *puVar2 = hFile;
      if ((DVar3 & 0xff) == 2) {
        bVar1 = *(byte *)(puVar2 + 1) | 0x40;
        goto LAB_1000389e;
      }
      if ((DVar3 & 0xff) == 3) {
        bVar1 = *(byte *)(puVar2 + 1) | 8;
        goto LAB_1000389e;
      }
    }
    else {
      bVar1 = *(byte *)(puVar2 + 1) | 0x80;
LAB_1000389e:
      *(byte *)(puVar2 + 1) = bVar1;
    }
    iVar5 = iVar5 + 1;
    if (2 < iVar5) {
      SetHandleCount(DAT_10009c40);
      return;
    }
  } while( true );
}



/* VA 100038c0 */

void FUN_100038c0(void)

{
  uint *puVar1;
  uint uVar2;
  LPCRITICAL_SECTION lpCriticalSection;

  puVar1 = &DAT_10009b40;
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
      FUN_10004050((undefined *)*puVar1);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x10009c40);
  return;
}



/* VA 10003920 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10003920(void)

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
  cVar2 = *DAT_100087d4;
  pcVar7 = DAT_100087d4;
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
  piVar3 = (int *)FUN_10001f00(iVar8 * 4 + 4);
  _DAT_10008998 = piVar3;
  if (piVar3 == (int *)0x0) {
    __amsg_exit(9);
  }
  cVar2 = *DAT_100087d4;
  local_4 = piVar3;
  pcVar7 = DAT_100087d4;
  do {
    if (cVar2 == '\0') {
      FUN_10004050(DAT_100087d4);
      DAT_100087d4 = (char *)0x0;
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
      iVar8 = FUN_10001f00(uVar4);
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



/* VA 10003a10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10003a10(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_8;
  int local_4;

  GetModuleFileNameA((HMODULE)0x0,&DAT_100089c0,0x104);
  _DAT_100089a8 = &DAT_100089c0;
  pbVar2 = DAT_10009c54;
  if (*DAT_10009c54 == 0) {
    pbVar2 = &DAT_100089c0;
  }
  FUN_10003ab0(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = (undefined4 *)FUN_10001f00(local_4 + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_10003ab0(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_10008990 = puVar1;
  _DAT_1000898c = local_8 + -1;
  return;
}



/* VA 10003ab0 */

void __cdecl FUN_10003ab0(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

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
      if (((*(byte *)((int)&DAT_10008858 + bVar2 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)param_5 + 0x10008859) & 4) != 0) {
        *piVar6 = *piVar6 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar7;
          param_3 = param_3 + 1;
        }
        pbVar7 = param_1 + 2;
      }
      if (bVar2 == 0x20) break;
      if (bVar2 == 0) goto LAB_10003b89;
      param_1 = pbVar7;
    } while (bVar2 != 9);
    if (bVar2 == 0) {
LAB_10003b89:
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
          if ((*(byte *)((int)&DAT_10008858 + bVar2 + 1) & 4) != 0) {
            pbVar7 = pbVar7 + 1;
            *piVar6 = *piVar6 + 1;
          }
          *piVar6 = *piVar6 + 1;
          goto LAB_10003c85;
        }
        if ((*(byte *)((int)&DAT_10008858 + bVar2 + 1) & 4) != 0) {
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
LAB_10003c85:
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



/* VA 10003cc0 */

LPSTR FUN_10003cc0(void)

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
  if (DAT_10008ac8 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar10 = GetEnvironmentStrings();
      if (pCVar10 == (LPCH)0x0) {
        return (LPSTR)0x0;
      }
      DAT_10008ac8 = 2;
    }
    else {
      DAT_10008ac8 = 1;
    }
  }
  if (DAT_10008ac8 == 1) {
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
      if ((uVar6 != 0) && (pCVar7 = (LPSTR)FUN_10001f00(uVar6), pCVar7 != (LPSTR)0x0)) {
        iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,pCVar7,uVar6,(LPCSTR)0x0,(LPBOOL)0x0);
        if (iVar5 == 0) {
          FUN_10004050(pCVar7);
          pCVar7 = (LPSTR)0x0;
        }
        FreeEnvironmentStringsW(lpWideCharStr);
        return pCVar7;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return (LPSTR)0x0;
    }
  }
  else if ((DAT_10008ac8 == 2) &&
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
    pCVar7 = (LPSTR)FUN_10001f00((uint)pCVar9);
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



/* VA 10003e20 */

void __cdecl FUN_10003e20(undefined4 param_1)

{
  DAT_100087e0 = param_1;
  return;
}



/* VA 10003e30 */

void FUN_10003e30(void)

{
  if ((DAT_100087dc == 1) || ((DAT_100087dc == 0 && (DAT_100087e0 == 1)))) {
    FUN_10003e70((undefined *)0xfc);
    if (DAT_10008acc != (code *)0x0) {
      (*DAT_10008acc)();
    }
    FUN_10003e70((undefined *)0xff);
  }
  return;
}



/* VA 10003e70 */

void __cdecl FUN_10003e70(undefined *param_1)

{
  char cVar1;
  undefined **ppuVar2;
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

  ppuVar2 = (undefined **)&DAT_10008418;
  iVar8 = 0;
  do {
    if (param_1 == *ppuVar2) break;
    ppuVar2 = ppuVar2 + 2;
    iVar8 = iVar8 + 1;
  } while (ppuVar2 < &PTR_DAT_100084a8);
  if (param_1 == (undefined *)(&DAT_10008418)[iVar8 * 2]) {
    if ((DAT_100087dc == 1) || ((DAT_100087dc == 0 && (DAT_100087e0 == 1)))) {
      if ((DAT_10009b40 == 0) ||
         (hFile = *(HANDLE *)(DAT_10009b40 + 0x48), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar7 = *(char **)(iVar8 * 8 + 0x1000841c);
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
    else if (param_1 != (undefined *)0xfc) {
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
      pcVar7 = *(char **)(iVar8 * 8 + 0x1000841c);
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
      FUN_10004350(local_1a4,"Microsoft Visual C++ Runtime Library",0x12010);
      return;
    }
  }
  return;
}



/* VA 10004050 */

void __cdecl FUN_10004050(undefined *param_1)

{
  undefined *lpMem;
  byte *pbVar1;
  int local_4;

  lpMem = param_1;
  if (param_1 != (undefined *)0x0) {
    FUN_100025f0(9);
    pbVar1 = (byte *)FUN_10002a10(lpMem,&local_4,(uint *)&param_1);
    if (pbVar1 != (byte *)0x0) {
      FUN_10002a70(local_4,(int)param_1,pbVar1);
      FUN_10002670(9);
      return;
    }
    FUN_10002670(9);
    HeapFree(DAT_10009c50,0,lpMem);
  }
  return;
}



/* VA 100041a0 */

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
        goto joined_r0x100041de;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_1000421b;
        goto LAB_10004289;
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
joined_r0x10004285:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_10004289:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_1000421b;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x10004285;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x10004285;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x10004285;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x100041de:
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
LAB_1000421b:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}



/* VA 100042a0 */

int * __cdecl FUN_100042a0(int param_1,int param_2)

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
      if (DAT_10008184 < dwBytes) {
LAB_10004314:
        if (piVar3 != (int *)0x0) {
          return piVar3;
        }
      }
      else {
        FUN_100025f0(9);
        piVar3 = FUN_10002ad0(dwBytes >> 4);
        FUN_10002670(9);
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
          goto LAB_10004314;
        }
      }
      piVar3 = HeapAlloc(DAT_10009c50,8,dwBytes);
    }
    if ((piVar3 != (int *)0x0) || (DAT_100087e4 == 0)) {
      return piVar3;
    }
    iVar1 = FUN_100024a0(dwBytes);
    if (iVar1 == 0) {
      return (int *)0x0;
    }
  } while( true );
}



/* VA 10004350 */

int __cdecl FUN_10004350(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;

  iVar1 = 0;
  if (DAT_10008af4 != (FARPROC)0x0) {
LAB_100043a0:
    if (DAT_10008af8 != (FARPROC)0x0) {
      iVar1 = (*DAT_10008af8)();
    }
    if ((iVar1 != 0) && (DAT_10008afc != (FARPROC)0x0)) {
      iVar1 = (*DAT_10008afc)(iVar1);
    }
    iVar1 = (*DAT_10008af4)(iVar1,param_1,param_2,param_3);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_10008af4 = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_10008af4 != (FARPROC)0x0) {
      DAT_10008af8 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_10008afc = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_100043a0;
    }
  }
  return 0;
}
