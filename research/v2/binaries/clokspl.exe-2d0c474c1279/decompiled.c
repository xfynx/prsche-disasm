/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 2d0c474c1279f265148b7fab973e9a475498ee2cb54b7a1aad494ad74069ef76 */

/* VA 0040100c */

undefined4 * FUN_0040100c(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0041595b();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0041954b(extraout_ECX + 0x2f);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0040b374(extraout_ECX + 0x4e);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0x4e] = &PTR_LAB_0041d2c4;
  extraout_ECX[0x5e] = 0;
  *extraout_ECX = &PTR_LAB_0041c110;
  extraout_ECX[0x5f] = 1;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}



/* VA 00401070 */

undefined * __thiscall FUN_00401070(void *this,byte param_1)

{
  FUN_0040108c();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 0040108c */

void FUN_0040108c(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041c110;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FID_conflict__CHotKeyCtrl();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  CStatusBar::~CStatusBar((CStatusBar *)(extraout_ECX + 0x2f));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00415a3d();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 004010dc */

int __thiscall FUN_004010dc(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined1 local_14 [16];

  iVar1 = FUN_004162bc(this,param_1);
  if ((((iVar1 != -1) &&
       (iVar1 = FUN_004195df((void *)((int)this + 0xbc),(int)this,0x50008200,(HMENU)0xe801),
       iVar1 != 0)) && (iVar1 = FUN_00419678(), iVar1 != 0)) &&
     (iVar1 = FUN_00417a43((void *)((int)this + 0x138),0x50200804,local_14,this,0xe900), iVar1 != 0)
     ) {
    *(undefined4 *)((int)this + 0x174) = 1;
    iVar1 = FUN_004012fd();
    return (iVar1 != 0) - 1;
  }
  return -1;
}



/* VA 00401204 */

void __fastcall FUN_00401204(void *param_1)

{
  FUN_0040ec8f(param_1,1);
  SetForegroundWindow(*(HWND *)((int)param_1 + 0x1c));
  return;
}



/* VA 0040124f */

undefined * __thiscall FUN_0040124f(void *this,byte param_1)

{
  FID_conflict__CHotKeyCtrl();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 0040126b */

undefined4 * __fastcall FUN_0040126b(undefined4 *param_1)

{
  FUN_0040b374(param_1);
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  *param_1 = &PTR_LAB_0041c2a8;
  return param_1;
}



/* VA 00401285 */

undefined * __thiscall FUN_00401285(void *this,byte param_1)

{
  FUN_004012a1();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 004012a1 */

void FUN_004012a1(void)

{
  HGDIOBJ ho;
  CWnd *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(CWnd **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_LAB_0041c2a8;
  DAT_00426c74 = 0;
  ho = *(HGDIOBJ *)(this + 0x3c);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  DeleteObject(ho);
  DeleteObject(*(HGDIOBJ *)(this + 0x40));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWnd::~CWnd(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 004012f3 */

void __cdecl FUN_004012f3(undefined4 param_1)

{
  DAT_00426c70 = param_1;
  return;
}



/* VA 004012fd */

undefined4 FUN_004012fd(void)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  if ((DAT_00426c70 != 0) && (DAT_00426c74 == (int *)0x0)) {
    uVar3 = extraout_ECX;
    puVar2 = (undefined4 *)FUN_0040f348(0x44);
    *(undefined4 **)(unaff_EBP + -0x10) = puVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (puVar2 == (undefined4 *)0x0) {
      DAT_00426c74 = (int *)0x0;
    }
    else {
      DAT_00426c74 = FUN_0040126b(puVar2);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    bVar1 = FUN_00401384(*(int *)(unaff_EBP + 8));
    if (CONCAT31(extraout_var,bVar1) == 0) {
      if (DAT_00426c74 != (int *)0x0) {
        (**(code **)(*DAT_00426c74 + 4))(1,uVar3);
      }
      uVar3 = 0;
      goto LAB_00401375;
    }
    UpdateWindow((HWND)DAT_00426c74[7]);
  }
  uVar3 = 1;
LAB_00401375:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}



/* VA 00401381 */

undefined4 FUN_00401381(void)

{
  return 0;
}



/* VA 00401384 */

bool FUN_00401384(int param_1)

{
  bool bVar1;
  CWnd *pCVar2;
  int iVar3;
  HDC pHVar4;
  LPSTR pCVar5;
  char *pcVar6;
  DWORD DVar7;
  HCURSOR pHVar8;
  HWND pHVar9;
  LPCSTR pCVar10;
  int iVar11;
  HMENU pHVar12;
  LPVOID pvVar13;
  CHAR local_128 [260];
  undefined1 local_24 [4];
  int local_20;
  int local_1c;
  int local_c;
  void *local_8;

  GetDesktopWindow();
  pCVar2 = FUN_0040b6dd();
  GetDC(*(HWND *)(pCVar2 + 0x1c));
  iVar3 = FUN_00410b14();
  pHVar4 = (HDC)0x0;
  if (iVar3 != 0) {
    pHVar4 = *(HDC *)(iVar3 + 4);
  }
  local_c = GetDeviceCaps(pHVar4,0xc);
  GetDesktopWindow();
  pCVar2 = FUN_0040b6dd();
  GetDC(*(HWND *)(pCVar2 + 0x1c));
  iVar3 = FUN_00410b14();
  if (iVar3 == 0) {
    pHVar4 = (HDC)0x0;
  }
  else {
    pHVar4 = *(HDC *)(iVar3 + 4);
  }
  iVar3 = GetDeviceCaps(pHVar4,0xe);
  pCVar5 = GetCommandLineA();
  _strrchr(pCVar5,0x20);
  GetModuleFileNameA((HMODULE)0x0,local_128,0x104);
  pcVar6 = _strrchr(local_128,0x5c);
  pcVar6[1] = '\0';
  if (iVar3 * local_c < 8) {
    pcVar6 = s__s_s_016_004230a8;
  }
  else {
    pcVar6 = s__s_s_256_0042309c;
  }
  FUN_00402be0(local_128,pcVar6);
  DVar7 = GetFileAttributesA(local_128);
  if (DVar7 == 0xffffffff) {
    bVar1 = false;
  }
  else {
    FUN_00401684(local_8,local_128,(undefined4 *)((int)local_8 + 0x3c),
                 (undefined4 *)((int)local_8 + 0x40));
    GetObjectA(*(HANDLE *)((int)local_8 + 0x3c),0x18,local_24);
    if (param_1 == 0) {
      pHVar9 = (HWND)0x0;
    }
    else {
      pHVar9 = *(HWND *)(param_1 + 0x1c);
    }
    FUN_00419dc2();
    pHVar8 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    pvVar13 = (LPVOID)0x0;
    pHVar12 = (HMENU)0x0;
    iVar11 = 0;
    iVar3 = 0;
    DVar7 = 0x90000000;
    pCVar10 = (LPCSTR)0x0;
    pCVar5 = FUN_0040c3b0(0,pHVar8,(HBRUSH)0x0,(HICON)0x0);
    bVar1 = FUN_0040bc7c(local_8,0,pCVar5,pCVar10,DVar7,iVar3,iVar11,local_20,local_1c,pHVar9,
                         pHVar12,pvVar13);
  }
  return bVar1;
}



/* VA 0040151f */

undefined4 __fastcall FUN_0040151f(int *param_1)

{
  int iVar1;
  undefined4 uVar2;

  iVar1 = FUN_0040b632(param_1);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_0040db9d(param_1,0);
    uVar2 = 0;
  }
  return uVar2;
}



/* VA 0040153f */

void FUN_0040153f(void)

{
  HDC pHVar1;
  int iVar2;
  undefined4 uVar3;
  HGDIOBJ pvVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  BOOL BVar5;

  FUN_00402bc0();
  FUN_004112db();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00410a60((undefined4 *)(unaff_EBP + -0x34));
  iVar2 = *(int *)(extraout_ECX + 0x3c);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (iVar2 != 0) {
    pHVar1 = CreateCompatibleDC((HDC)(-(uint)(unaff_EBP != 0x88) & *(uint *)(unaff_EBP + -0x84)));
    FUN_00410b2a((void *)(unaff_EBP + -0x34),(uint)pHVar1);
    BVar5 = 0;
    iVar2 = FUN_00411418();
    uVar3 = FUN_00410d67((void *)(unaff_EBP + -0x88),iVar2,BVar5);
    *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
    RealizePalette(*(HDC *)(unaff_EBP + -0x84));
    iVar2 = FUN_00411418();
    if (iVar2 == 0) {
      pvVar4 = (HGDIOBJ)0x0;
    }
    else {
      pvVar4 = *(HGDIOBJ *)(iVar2 + 4);
    }
    uVar3 = FUN_00410c65(*(HDC *)(unaff_EBP + -0x30),pvVar4);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
    GetWindowRect(*(HWND *)(extraout_ECX + 0x1c),(LPRECT)(unaff_EBP + -0x24));
    ScreenToClient(*(HWND *)(extraout_ECX + 0x1c),(LPPOINT)(unaff_EBP + -0x24));
    ScreenToClient(*(HWND *)(extraout_ECX + 0x1c),(LPPOINT)(unaff_EBP + -0x1c));
    BitBlt(*(HDC *)(unaff_EBP + -0x84),0,0,*(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x24)
           ,*(int *)(unaff_EBP + -0x18) - *(int *)(unaff_EBP + -0x20),
           (HDC)(-(uint)(unaff_EBP != 0x34) & *(uint *)(unaff_EBP + -0x30)),0,0,0xcc0020);
    FUN_00410d67((void *)(unaff_EBP + -0x88),*(int *)(unaff_EBP + -0x10),0);
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      pvVar4 = (HGDIOBJ)0x0;
    }
    else {
      pvVar4 = *(HGDIOBJ *)(*(int *)(unaff_EBP + -0x14) + 4);
    }
    FUN_00410c65(*(HDC *)(unaff_EBP + -0x30),pvVar4);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00410b92();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CPaintDC::~CPaintDC((CPaintDC *)(unaff_EBP + -0x88));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00401684 */

undefined4 __thiscall
FUN_00401684(void *this,LPCSTR param_1,undefined4 *param_2,undefined4 *param_3)

{
  HANDLE h;
  undefined4 uVar1;
  HGDIOBJ h_00;
  LOGPALETTE *plpal;
  BYTE *pBVar2;
  HPALETTE pHVar3;
  BYTE *pBVar4;
  HDC pHVar5;
  int iVar6;
  RGBQUAD local_41c [256];
  undefined1 local_1c [16];
  ushort local_c;
  ushort local_a;

  pHVar5 = (HDC)0x0;
  *param_2 = 0;
  *param_3 = 0;
  h = LoadImageA((HINSTANCE)0x0,param_1,0,0,0,0x2050);
  *param_2 = h;
  if (h == (HANDLE)0x0) {
    uVar1 = 0;
  }
  else {
    GetObjectA(h,0x18,local_1c);
    if ((int)((uint)local_a * (uint)local_c) < 9) {
      pHVar5 = CreateCompatibleDC((HDC)0x0);
      h_00 = SelectObject(pHVar5,(HGDIOBJ)*param_2);
      iVar6 = 0x100;
      GetDIBColorTable(pHVar5,0,0x100,local_41c);
      plpal = (LOGPALETTE *)FUN_00402cf0(0x408);
      pBVar4 = &local_41c[0].rgbGreen;
      plpal->palVersion = 0x300;
      plpal->palNumEntries = 0x100;
      pBVar2 = &plpal->palPalEntry[0].peGreen;
      do {
        ((PALETTEENTRY *)(pBVar2 + -1))->peRed = pBVar4[1];
        *pBVar2 = *pBVar4;
        pBVar2[1] = ((RGBQUAD *)(pBVar4 + -1))->rgbBlue;
        pBVar2[2] = '\0';
        pBVar4 = pBVar4 + 4;
        pBVar2 = pBVar2 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      pHVar3 = CreatePalette(plpal);
      *param_3 = pHVar3;
      FUN_00402c80((undefined *)plpal);
      SelectObject(pHVar5,h_00);
      DeleteDC(pHVar5);
    }
    else {
      GetDC(*(HWND *)((int)this + 0x1c));
      iVar6 = FUN_00410b14();
      if (iVar6 != 0) {
        pHVar5 = *(HDC *)(iVar6 + 4);
      }
      pHVar3 = CreateHalftonePalette(pHVar5);
      *param_3 = pHVar3;
      ReleaseDC(*(HWND *)((int)this + 0x1c),*(HDC *)(iVar6 + 4));
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* VA 004017c9 */

UINT FUN_004017c9(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  UINT UVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  FUN_00411173();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar1 = (uint)(*(int *)(unaff_EBP + 8) == 0);
  iVar2 = FUN_00411418();
  uVar3 = FUN_00410d67((void *)(unaff_EBP + -0x20),iVar2,uVar1);
  *(undefined4 *)(unaff_EBP + 8) = uVar3;
  UVar4 = RealizePalette(*(HDC *)(unaff_EBP + -0x1c));
  if (0 < (int)UVar4) {
    InvalidateRect(*(HWND *)(extraout_ECX + 0x1c),(RECT *)0x0,0);
  }
  FUN_00410d67((void *)(unaff_EBP + -0x20),*(int *)(unaff_EBP + 8),1);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004111e5();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return UVar4;
}



/* VA 00401858 */

undefined4 FUN_00401858(void)

{
  CWinThread *pCVar1;
  undefined4 uVar2;

  pCVar1 = AfxGetThread();
  if (pCVar1 != (CWinThread *)0x0) {
    pCVar1 = AfxGetThread();
    uVar2 = (**(code **)(*(int *)pCVar1 + 0x7c))();
    return uVar2;
  }
  return 0;
}



/* VA 00401895 */

undefined * __thiscall FUN_00401895(void *this,byte param_1)

{
  FUN_004018b1();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 004018b1 */

void FUN_004018b1(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041db1c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040fbd1((int)extraout_ECX);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d1bc;
  *unaff_FS_OFFSET = uVar1;
  return;
}



/* VA 004018ee */

void FUN_004018ee(void)

{
  FUN_00401913((undefined4 *)&DAT_00426c78);
  return;
}



/* VA 004018f8 */

void FUN_004018f8(void)

{
  FUN_00402fb0(0x401904);
  return;
}



/* VA 0040190e */

void thunk_FUN_0041a3e5(void)

{
  int *piVar1;
  int iVar2;
  CWinThread *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(CWinThread **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_LAB_0041dc2c;
  piVar1 = *(int **)(this + 0x80);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(1);
  }
  if (*(int **)(this + 0xa8) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0xa8) + 0x14))(1);
  }
  iVar2 = FUN_00419dc2();
  if (*(char *)(iVar2 + 0x14) == '\0') {
    if (DAT_004287a0 != (int *)0x0) {
      (**(code **)(*DAT_004287a0 + 4))(1);
      DAT_004287a0 = (int *)0x0;
    }
    if (DAT_0042879c != (int *)0x0) {
      (**(code **)(*DAT_0042879c + 4))(1);
      DAT_0042879c = (int *)0x0;
    }
  }
  if (*(HGLOBAL *)(this + 0x94) != (HGLOBAL)0x0) {
    FUN_00411713(*(HGLOBAL *)(this + 0x94));
  }
  if (*(HGLOBAL *)(this + 0x98) != (HGLOBAL)0x0) {
    FUN_00411713(*(HGLOBAL *)(this + 0x98));
  }
  if (*(ATOM *)(this + 0xb0) != 0) {
    GlobalDeleteAtom(*(ATOM *)(this + 0xb0));
  }
  if (*(ATOM *)(this + 0xb2) != 0) {
    GlobalDeleteAtom(*(ATOM *)(this + 0xb2));
  }
  if (*(int **)(this + 0xac) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0xac) + 4))(1);
  }
  iVar2 = FUN_00419dc2();
  if (*(int *)(iVar2 + 0x10) == *(int *)(this + 0x78)) {
    *(undefined4 *)(iVar2 + 0x10) = 0;
  }
  if (*(CWinThread **)(iVar2 + 4) == this) {
    *(undefined4 *)(iVar2 + 4) = 0;
  }
  FUN_00402c80(*(undefined **)(this + 0x78));
  FUN_00402c80(*(undefined **)(this + 0x7c));
  FUN_00402c80(*(undefined **)(this + 0x88));
  FUN_00402c80(*(undefined **)(this + 0x8c));
  FUN_00402c80(*(undefined **)(this + 0x90));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWinThread::~CWinThread(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00401913 */

undefined4 * __fastcall FUN_00401913(undefined4 *param_1)

{
  FUN_00419fef();
  *param_1 = &PTR_LAB_0041c3b8;
  return param_1;
}



/* VA 00401927 */

undefined * __thiscall FUN_00401927(void *this,byte param_1)

{
  thunk_FUN_0041a3e5();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 00401949 */

void FUN_00401949(void)

{
  int iVar1;
  int *this;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  FUN_0041a197();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0041a139((int *)(unaff_EBP + -0x34));
  FUN_004012f3(*(undefined4 *)(unaff_EBP + -0x30));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0041a222();
  iVar1 = FUN_0040f348(0x180);
  *(int *)(unaff_EBP + -0x10) = iVar1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (iVar1 == 0) {
    this = (int *)0x0;
  }
  else {
    this = FUN_0040100c();
  }
  iVar1 = *this;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar1 = (**(code **)(iVar1 + 0xc0))(2,0xcf8000,0,0);
  if (iVar1 != 0) {
    FUN_0040ec8f(this,0);
    UpdateWindow((HWND)this[7]);
    *(int **)(extraout_ECX + 0x1c) = this;
    FUN_004012fd();
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 004019f3 */

void FUN_004019f3(void)

{
  int iVar1;
  int *piVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  piVar2 = FUN_0040e63d((void *)(unaff_EBP + -0x68),100,0);
  iVar1 = *piVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (**(code **)(iVar1 + 0xc0))();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CDialog::~CDialog((CDialog *)(unaff_EBP + -0x68));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00401a32 */

undefined4 __thiscall FUN_00401a32(void *this,int *param_1)

{
  int iVar1;
  undefined4 uVar2;

  iVar1 = FUN_00401381();
  if (iVar1 == 0) {
    uVar2 = FUN_0040f67f(this,param_1);
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* VA 00401a57 */

void FUN_00401a57(void)

{
  HLOCAL pvVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  pvVar1 = FUN_0041a61c(0x84);
  *(HLOCAL *)(unaff_EBP + -0x10) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar1 != (HLOCAL)0x0) {
    FUN_00419bd7();
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00401a8b */

void FUN_00401a8b(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  puVar1 = FUN_0041a61c(0x10);
  *(undefined4 **)(unaff_EBP + -0x10) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00419fcb(puVar1);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00401abc */

void FUN_00401abc(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  puVar1 = FUN_0041a61c(0x118);
  *(undefined4 **)(unaff_EBP + -0x10) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004199c3(puVar1);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00401af0 */

/* Library Function - Single Match
    public: class CWnd * __thiscall CWnd::GetOwner(void)const

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

CWnd * __thiscall CWnd::GetOwner(CWnd *this)

{
  CWnd *pCVar1;

  if (*(int *)(this + 0x20) == 0) {
    GetParent(*(HWND *)(this + 0x1c));
  }
  pCVar1 = FUN_0040b6dd();
  return pCVar1;
}



/* VA 00401b29 */

HLOCAL __thiscall FUN_00401b29(void *this,byte param_1)

{
  FUN_0041aca2();
  if ((param_1 & 1) != 0) {
    FUN_0041a63a(this);
  }
  return this;
}



/* VA 00401b77 */

void FUN_00401b77(void)

{
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00410434(extraout_ECX);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0040adf9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0040adf9();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00401bb8 */

undefined4 * __thiscall FUN_00401bb8(void *this,undefined4 param_1,undefined4 param_2)

{
  FUN_0041016c(this,param_1);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x94) = param_2;
  *(undefined ***)this = &PTR_LAB_0041da04;
  return this;
}



/* VA 00401be2 */

undefined4 * __thiscall FUN_00401be2(void *this,undefined4 param_1,undefined4 param_2)

{
  FUN_0041016c(this,param_1);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x94) = param_2;
  *(undefined ***)this = &PTR_LAB_0041da24;
  return this;
}



/* VA 00401c0c */

void __fastcall FUN_00401c0c(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_0041d1bc;
  return;
}



/* VA 00401c13 */

undefined * __thiscall FUN_00401c13(void *this,byte param_1)

{
  FUN_00401c2f();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 00401c2f */

void FUN_00401c2f(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041d9ec;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00411485((int)extraout_ECX);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d1bc;
  *unaff_FS_OFFSET = uVar1;
  return;
}



/* VA 00401c62 */

undefined * __thiscall FUN_00401c62(void *this,byte param_1)

{
  FUN_00401c7e();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 00401c7e */

void FUN_00401c7e(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041d9ec;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00411485((int)extraout_ECX);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d1bc;
  *unaff_FS_OFFSET = uVar1;
  return;
}



/* VA 00401cf1 */

void __thiscall
FUN_00401cf1(void *this,int param_1,int param_2,UINT param_3,RECT *param_4,LPCSTR param_5,
            UINT param_6,INT *param_7)

{
  ExtTextOutA(*(HDC *)((int)this + 4),param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



/* VA 00401d16 */

int * __thiscall
FUN_00401d16(void *this,int *param_1,int param_2,int param_3,LPCSTR param_4,int param_5,int param_6,
            INT *param_7,int param_8)

{
  LONG LVar1;

  LVar1 = TabbedTextOutA(*(HDC *)((int)this + 4),param_2,param_3,param_4,param_5,param_6,param_7,
                         param_8);
  param_1[1] = (int)(short)((uint)LVar1 >> 0x10);
  *param_1 = (int)(short)LVar1;
  return param_1;
}



/* VA 00401d6a */

void __thiscall
FUN_00401d6a(void *this,int param_1,GRAYSTRINGPROC param_2,LPARAM param_3,int param_4,int param_5,
            int param_6,int param_7,int param_8)

{
  HBRUSH hBrush;

  hBrush = (HBRUSH)0x0;
  if (param_1 != 0) {
    hBrush = *(HBRUSH *)(param_1 + 4);
  }
  GrayStringA(*(HDC *)((int)this + 4),hBrush,param_2,param_3,param_4,param_5,param_6,param_7,param_8
             );
  return;
}



/* VA 00401dcb */

HLOCAL __thiscall FUN_00401dcb(void *this,byte param_1)

{
  FUN_0041ace9();
  if ((param_1 & 1) != 0) {
    FUN_0041a63a(this);
  }
  return this;
}



/* VA 00401de6 */

undefined4 * __thiscall FUN_00401de6(void *this,byte param_1)

{
  FUN_00401c0c(this);
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 00401e02 */

undefined4 * __thiscall FUN_00401e02(void *this,undefined4 param_1,undefined4 param_2)

{
  FUN_0041016c(this,param_1);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x94) = param_2;
  *(undefined ***)this = &PTR_LAB_0041de24;
  return this;
}



/* VA 00401e2c */

undefined4 * __thiscall FUN_00401e2c(void *this,undefined4 param_1,undefined4 param_2)

{
  FUN_0041016c(this,param_1);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x94) = param_2;
  *(undefined ***)this = &PTR_LAB_0041de44;
  return this;
}



/* VA 00401e56 */

void __thiscall FUN_00401e56(void *this,undefined4 param_1)

{
  *(int *)this = (int)(short)param_1;
  *(int *)((int)this + 4) = (int)(short)((uint)param_1 >> 0x10);
  return;
}



/* VA 00401e82 */

/* Library Function - Multiple Matches With Same Base Name
    protected: int __thiscall CToolBarCtrl::OnCreate(struct tagCREATESTRUCTA *)
    protected: int __thiscall CToolBarCtrl::OnCreate(struct tagCREATESTRUCTW *)

   Library: Visual Studio 2003 Release */

undefined4 __fastcall OnCreate(int *param_1)

{
  int iVar1;
  undefined4 uVar2;

  iVar1 = FUN_0040b632(param_1);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    SendMessageA((HWND)param_1[7],0x41e,0x14,0);
    uVar2 = 0;
  }
  return uVar2;
}



/* VA 00401eab */

void __thiscall FUN_00401eab(void *this,WPARAM param_1)

{
  uint uVar1;
  int iVar2;

  uVar1 = SendMessageA(*(HWND *)((int)this + 0x1c),0x1002,param_1,0);
  iVar2 = FUN_004020b8(uVar1);
  if (iVar2 != 0) {
    SendMessageA(*(HWND *)((int)this + 0x1c),0x1003,param_1,0);
  }
  return;
}



/* VA 00401ee4 */

void __fastcall FUN_00401ee4(int *param_1)

{
  FUN_00401eab(param_1,0);
  FUN_00401eab(param_1,1);
  FUN_00401eab(param_1,2);
  FUN_0040be58(param_1);
  return;
}



/* VA 00401f09 */

void __thiscall FUN_00401f09(void *this,WPARAM param_1)

{
  uint uVar1;
  int iVar2;

  uVar1 = SendMessageA(*(HWND *)((int)this + 0x1c),0x1108,param_1,0);
  iVar2 = FUN_004020b8(uVar1);
  if (iVar2 != 0) {
    SendMessageA(*(HWND *)((int)this + 0x1c),0x1109,param_1,0);
  }
  return;
}



/* VA 00401f42 */

void __fastcall FUN_00401f42(int *param_1)

{
  FUN_00401f09(param_1,0);
  FUN_00401f09(param_1,2);
  FUN_0040be3a(param_1);
  return;
}



/* VA 00401f98 */

void __fastcall FUN_00401f98(undefined4 *param_1)

{
  param_1[1] = 0;
  *param_1 = &PTR_LAB_0041e5e4;
  return;
}



/* VA 00401fa5 */

undefined * __thiscall FUN_00401fa5(void *this,byte param_1)

{
  FUN_00401fc1();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 00401fc1 */

void FUN_00401fc1(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041e5e4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040208e((int)extraout_ECX);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d1bc;
  *unaff_FS_OFFSET = uVar1;
  return;
}



/* VA 00401ff4 */

int __fastcall FUN_00401ff4(int param_1)

{
  int iVar1;
  void *this;

  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    this = (void *)FUN_0040201e();
    if (this != (void *)0x0) {
      FUN_0040af44(this,*(uint *)(param_1 + 4));
    }
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return iVar1;
}



/* VA 0040201e */

undefined4 FUN_0040201e(void)

{
  AFX_MODULE_THREAD_STATE *pAVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  pAVar1 = AfxGetModuleThreadState();
  if ((*(int *)(pAVar1 + 0x24) == 0) && (*(int *)(unaff_EBP + 8) != 0)) {
    uVar2 = FUN_0040f334(&LAB_00411749);
    iVar3 = FUN_0040f348(0x44);
    *(int *)(unaff_EBP + 8) = iVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar3 == 0) {
      pvVar4 = (void *)0x0;
    }
    else {
      pvVar4 = FUN_004102fd();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(void **)(pAVar1 + 0x24) = pvVar4;
    FUN_0040f334(uVar2);
  }
  uVar2 = *(undefined4 *)(pAVar1 + 0x24);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}



/* VA 0040208e */

BOOL __fastcall FUN_0040208e(int param_1)

{
  HIMAGELIST himl;
  BOOL BVar1;

  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  himl = (HIMAGELIST)FUN_00401ff4(param_1);
  BVar1 = ImageList_Destroy(himl);
  return BVar1;
}



/* VA 004020a4 */

void FUN_004020a4(void)

{
  int iVar1;

  iVar1 = FUN_0040201e();
  if (iVar1 != 0) {
    FUN_00410434(iVar1);
    return;
  }
  return;
}



/* VA 004020b8 */

undefined4 FUN_004020b8(uint param_1)

{
  void *this;
  undefined4 uVar1;

  this = (void *)FUN_0040201e();
  uVar1 = 0;
  if (this != (void *)0x0) {
    uVar1 = FUN_0040aec1(this,param_1);
  }
  return uVar1;
}



/* VA 004020d4 */

undefined * __thiscall FUN_004020d4(void *this,byte param_1)

{
  FUN_004020f0();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 004020f0 */

void FUN_004020f0(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041d9ec;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00411485((int)extraout_ECX);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d1bc;
  *unaff_FS_OFFSET = uVar1;
  return;
}



/* VA 00402131 */

undefined4 * FUN_00402131(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0040b374(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  CMap<>(extraout_ECX + 0xf,10);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041e83c;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}



/* VA 0040216a */

undefined * __thiscall FUN_0040216a(void *this,byte param_1)

{
  FUN_004021d1();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 00402186 */

void __thiscall FUN_00402186(void *this,int param_1,uint param_2)

{
  bool bVar1;
  HWND pHVar2;
  undefined3 extraout_var;
  undefined4 uVar3;

  uVar3 = 0;
  if (param_1 == 0) {
    pHVar2 = (HWND)0x0;
  }
  else {
    pHVar2 = *(HWND *)(param_1 + 0x1c);
  }
  bVar1 = FUN_0040bc7c(this,0,"tooltips_class32",(LPCSTR)0x0,param_2 | 0x80000000,-0x80000000,
                       -0x80000000,-0x80000000,-0x80000000,pHVar2,(HMENU)0x0,(LPVOID)0x0);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    if (param_1 != 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x1c);
    }
    *(undefined4 *)((int)this + 0x20) = uVar3;
  }
  return;
}



/* VA 004021d1 */

void FUN_004021d1(void)

{
  CWnd *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(CWnd **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_LAB_0041e83c;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0040bf81((int)this);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0040b0d3();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWnd::~CWnd(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00402218 */

undefined4 __fastcall FUN_00402218(int *param_1)

{
  int iVar1;

  iVar1 = *param_1;
  (**(code **)(iVar1 + 0x60))();
  if (param_1 != (int *)0x0) {
    (**(code **)(iVar1 + 4))(1);
  }
  return 1;
}



/* VA 00402232 */

void __thiscall FUN_00402232(void *this,undefined4 param_1,undefined4 *param_2)

{
  void *this_00;
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_30 [8];
  int local_10;
  byte *local_c [2];

  puVar2 = param_2;
  puVar4 = local_30;
  for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  if (((local_10 == 0) && (local_c[0] != (byte *)0xffffffff)) && (local_c[0] != (byte *)0x0)) {
    this_00 = (void *)((int)this + 0x3c);
    bVar1 = FUN_0040b1c0(this_00,local_c[0],&param_2);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      puVar2 = FUN_0040b204(this_00,local_c[0]);
      *puVar2 = 0;
    }
    FUN_0040b1e2(this_00,local_c[0],local_c);
  }
  (**(code **)(*(int *)this + 0xa8))(0x404,param_1,local_30);
  return;
}



/* VA 004022bd */

HWND FUN_004022bd(undefined4 param_1,POINT *param_2)

{
  bool bVar1;
  HWND hWnd;
  HWND hWnd_00;
  undefined3 extraout_var;
  BOOL BVar2;
  tagPOINT local_c;

  local_c.x = param_2->x;
  local_c.y = param_2->y;
  hWnd = WindowFromPoint(*param_2);
  hWnd_00 = hWnd;
  if ((hWnd != (HWND)0x0) &&
     ((hWnd_00 = GetParent(hWnd), hWnd_00 == (HWND)0x0 ||
      (bVar1 = FUN_00411541(hWnd_00,2), CONCAT31(extraout_var,bVar1) == 0)))) {
    ScreenToClient(hWnd,&local_c);
    hWnd_00 = FUN_004115b6(hWnd,local_c.x,local_c.y);
    if ((hWnd_00 == (HWND)0x0) || (BVar2 = IsWindowEnabled(hWnd_00), BVar2 != 0)) {
      hWnd_00 = hWnd;
    }
  }
  return hWnd_00;
}



/* VA 00402330 */

undefined4 __thiscall FUN_00402330(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;

  iVar1 = FUN_00419a6f();
  iVar2 = *(int *)(iVar1 + 0xcc);
  if (param_1 == 0) {
    if ((*(byte *)((int)this + 0x24) & 1) != 0) {
      if (*(void **)(iVar1 + 0xd0) == this) {
        FUN_0040c038(1);
      }
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar2 + 0x1c);
      }
      if (iVar1 != 0) {
        _memset(&local_30,0,0x2c);
        local_28 = *(undefined4 *)((int)this + 0x1c);
        local_30 = 0x2c;
        local_2c = 1;
        local_24 = local_28;
        SendMessageA(*(HWND *)(iVar2 + 0x1c),0x405,0,(LPARAM)&local_30);
      }
      *(uint *)((int)this + 0x24) = *(uint *)((int)this + 0x24) & 0xfffffffe;
    }
  }
  else if ((*(byte *)((int)this + 0x24) & 1) == 0) {
    iVar2 = FUN_00419dc2();
    *(undefined1 **)(iVar2 + 0x1034) = &LAB_004023d2;
    *(uint *)((int)this + 0x24) = *(uint *)((int)this + 0x24) | 1;
  }
  return 1;
}



/* VA 004023e2 */

void FUN_004023e2(void)

{
  CWnd CVar1;
  bool bVar2;
  SHORT SVar3;
  CWnd *pCVar4;
  int iVar5;
  undefined4 uVar6;
  CWnd *pCVar7;
  int iVar8;
  LRESULT LVar9;
  int iVar10;
  undefined3 extraout_var;
  undefined4 *puVar11;
  CWnd *extraout_ECX;
  int unaff_EBP;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  iVar5 = *(int *)(*(int *)(unaff_EBP + 8) + 4);
  CVar1 = extraout_ECX[0x24];
  *(CWnd **)(unaff_EBP + -0x10) = extraout_ECX;
  if ((((((byte)CVar1 & 1) == 0) ||
       ((((iVar5 != 0x200 && (iVar5 != 0xa0)) && (iVar5 != 0x202)) &&
        ((iVar5 != 0x205 && (iVar5 != 0x208)))))) || (SVar3 = GetKeyState(1), SVar3 < 0)) ||
     ((SVar3 = GetKeyState(2), SVar3 < 0 || (SVar3 = GetKeyState(4), SVar3 < 0))))
  goto LAB_004026cb;
  while (pCVar4 = FUN_0040b6dd(), pCVar4 != (CWnd *)0x0) {
    if (pCVar4 == extraout_ECX) goto LAB_00402484;
    if (((byte)pCVar4[0x24] & 1) != 0) break;
    GetParent(*(HWND *)(pCVar4 + 0x1c));
  }
  if (pCVar4 != extraout_ECX) goto LAB_004026cb;
LAB_00402484:
  iVar5 = FUN_0041a9d0(&DAT_00428660,FUN_00401abc);
  *(int *)(unaff_EBP + -0x18) = iVar5;
  pCVar4 = *(CWnd **)(iVar5 + 0xcc);
  uVar6 = FUN_0040cd68((int)extraout_ECX);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
  if (pCVar4 == (CWnd *)0x0) {
LAB_004024d2:
    iVar8 = FUN_0040f348(0x58);
    *(int *)(unaff_EBP + -0x1c) = iVar8;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar8 == 0) {
      pCVar4 = (CWnd *)0x0;
    }
    else {
      pCVar4 = (CWnd *)FUN_00402131();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar8 = FUN_00402186(pCVar4,*(int *)(unaff_EBP + -0x14),1);
    if (iVar8 == 0) {
      if (pCVar4 != (CWnd *)0x0) {
        (**(code **)(*(int *)pCVar4 + 4))(1);
      }
      goto LAB_004026cb;
    }
    SendMessageA(*(HWND *)(pCVar4 + 0x1c),0x401,0,0);
    *(CWnd **)(iVar5 + 0xcc) = pCVar4;
  }
  else {
    pCVar7 = CWnd::GetOwner(pCVar4);
    if (pCVar7 != *(CWnd **)(unaff_EBP + -0x14)) {
      iVar8 = *(int *)pCVar4;
      (**(code **)(iVar8 + 0x60))();
      (**(code **)(iVar8 + 4))(1);
      pCVar4 = (CWnd *)0x0;
      *(undefined4 *)(iVar5 + 0xcc) = 0;
    }
    if (pCVar4 == (CWnd *)0x0) goto LAB_004024d2;
  }
  _memset((void *)(unaff_EBP + -0x50),0,0x2c);
  *(undefined4 *)(unaff_EBP + -0x50) = 0x2c;
  *(undefined4 *)(unaff_EBP + -0x4c) = 1;
  uVar6 = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1c);
  *(undefined4 *)(unaff_EBP + -0x48) = uVar6;
  *(undefined4 *)(unaff_EBP + -0x44) = uVar6;
  LVar9 = SendMessageA(*(HWND *)(pCVar4 + 0x1c),0x408,0,unaff_EBP + -0x50);
  if (LVar9 == 0) {
    SendMessageA(*(HWND *)(pCVar4 + 0x1c),0x404,0,unaff_EBP + -0x50);
  }
  uVar6 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x14);
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x18);
  *(undefined4 *)(unaff_EBP + -0x24) = uVar6;
  ScreenToClient(*(HWND *)(*(int *)(unaff_EBP + -0x10) + 0x1c),(LPPOINT)(unaff_EBP + -0x24));
  _memset((void *)(unaff_EBP + -0x7c),0,0x2c);
  *(undefined4 *)(unaff_EBP + -0x7c) = 0x2c;
  iVar10 = (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x6c))
                     (*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20),
                      unaff_EBP + -0x7c);
  *(int *)(unaff_EBP + -0x1c) = iVar10;
  uVar12 = -(uint)(iVar10 != -1) & *(uint *)(unaff_EBP + -0x10);
  iVar8 = *(int *)(iVar5 + 0xd4);
  *(uint *)(unaff_EBP + -0x14) = uVar12;
  if ((iVar8 == iVar10) && (*(uint *)(iVar5 + 0xd0) == uVar12)) {
    if (iVar10 != -1) {
      FUN_004026dc((int)pCVar4,*(undefined4 **)(unaff_EBP + 8));
    }
  }
  else {
    if (iVar10 != -1) {
      uVar12 = *(uint *)(unaff_EBP + -0x78);
      puVar11 = (undefined4 *)(unaff_EBP + -0x7c);
      puVar13 = (undefined4 *)(unaff_EBP + -0x50);
      for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar13 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar13 = puVar13 + 1;
      }
      *(uint *)(unaff_EBP + -0x4c) = uVar12 & 0x3fffffff;
      SendMessageA(*(HWND *)(pCVar4 + 0x1c),0x404,0,unaff_EBP + -0x50);
      if (((*(byte *)(unaff_EBP + -0x75) & 0x40) != 0) ||
         (bVar2 = FUN_0040cdaf(*(int *)(unaff_EBP + -0x10)), CONCAT31(extraout_var,bVar2) != 0)) {
        SendMessageA(*(HWND *)(pCVar4 + 0x1c),0x401,1,0);
        SetWindowPos(*(HWND *)(pCVar4 + 0x1c),(HWND)0x0,0,0,0,0,0x213);
      }
      iVar5 = *(int *)(unaff_EBP + -0x18);
      uVar12 = *(uint *)(unaff_EBP + -0x14);
    }
    FUN_004026dc((int)pCVar4,*(undefined4 **)(unaff_EBP + 8));
    iVar8 = *(int *)(iVar5 + 0xd8);
    puVar11 = (undefined4 *)(iVar5 + 0xd8);
    *(undefined4 **)(unaff_EBP + 8) = puVar11;
    if (iVar8 == 0x2c) {
      SendMessageA(*(HWND *)(pCVar4 + 0x1c),0x405,0,(LPARAM)puVar11);
      puVar11 = *(undefined4 **)(unaff_EBP + 8);
    }
    uVar6 = *(undefined4 *)(unaff_EBP + -0x1c);
    *(uint *)(iVar5 + 0xd0) = uVar12;
    *(undefined4 *)(iVar5 + 0xd4) = uVar6;
    puVar13 = (undefined4 *)(unaff_EBP + -0x7c);
    for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar11 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar11 = puVar11 + 1;
    }
  }
  if ((*(int *)(unaff_EBP + -0x58) != -1) && (*(int *)(unaff_EBP + -0x5c) == 0)) {
    FUN_00402c80(*(undefined **)(unaff_EBP + -0x58));
  }
LAB_004026cb:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 004026dc */

void FUN_004026dc(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  HWND *ppHVar3;
  HWND local_28;
  uint local_24;
  undefined4 local_1c;
  undefined1 local_14 [8];
  tagPOINT local_c;

  puVar2 = param_2;
  ppHVar3 = &local_28;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppHVar3 = (HWND)*puVar2;
    puVar2 = puVar2 + 1;
    ppHVar3 = ppHVar3 + 1;
  }
  local_28 = (HWND)SendMessageA(*(HWND *)(param_1 + 0x1c),0x410,0,(LPARAM)local_14);
  local_c.x = param_2[5];
  local_c.y = param_2[6];
  if ((0x1ff < local_24) && (local_24 < 0x20a)) {
    ScreenToClient(local_28,&local_c);
  }
  local_1c = CONCAT22((undefined2)local_c.y,(undefined2)local_c.x);
  SendMessageA(*(HWND *)(param_1 + 0x1c),0x407,0,(LPARAM)&local_28);
  return;
}



/* VA 0040275e */

void __fastcall FUN_0040275e(undefined4 *param_1)

{
  param_1[1] = 0;
  *param_1 = &PTR_LAB_0041d9ec;
  return;
}



/* VA 00402770 */

void FUN_00402770(undefined *UNRECOVERED_JUMPTABLE)

{
  undefined4 *unaff_FS_OFFSET;

  *unaff_FS_OFFSET = *(undefined4 *)*unaff_FS_OFFSET;
                    /* WARNING: Could not recover jumptable at 0x0040279b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}



/* VA 004027b0 */

void FUN_004027b0(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  LOCK();
  UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x004027b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}



/* VA 004027c0 */

void FUN_004027c0(PVOID param_1,PEXCEPTION_RECORD param_2)

{
  undefined4 *puVar1;
  undefined4 *unaff_FS_OFFSET;

  puVar1 = (undefined4 *)*unaff_FS_OFFSET;
  RtlUnwind(param_1,(PVOID)0x4027ec,param_2,(PVOID)0x0);
  param_2->ExceptionFlags = param_2->ExceptionFlags & 0xfffffffd;
  *puVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = puVar1;
  return;
}



/* VA 00402820 */

undefined4 __cdecl
FUN_00402820(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4)

{
  int *in_EAX;
  undefined4 uVar1;

  uVar1 = FUN_00404740(param_1,param_2,param_3,param_4,in_EAX,0,(PVOID)0x0,0);
  return uVar1;
}



/* VA 00402860 */

undefined4 __cdecl
FUN_00402860(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int *unaff_FS_OFFSET;
  int local_18;
  code *local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;

  local_8 = param_4 + 1;
  local_14 = FUN_004028c0;
  local_10 = param_2;
  local_c = param_1;
  local_18 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_18;
  uVar1 = __CallSettingFrame_12(param_3,param_1,param_5);
  *unaff_FS_OFFSET = local_18;
  return uVar1;
}



/* VA 004028c0 */

void __cdecl FUN_004028c0(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  FUN_00404740(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),param_2,0);
  return;
}



/* VA 004028f0 */

undefined4 __cdecl
FUN_004028f0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  DWORD *pDVar1;
  int *unaff_FS_OFFSET;
  undefined4 uVar2;
  undefined4 **ppuVar3;
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  code *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 *local_10;
  undefined1 *local_c;
  int local_8;

  local_c = &stack0xfffffffc;
  local_10 = &stack0xffffffbc;
  local_28 = FUN_004029c0;
  local_24 = param_5;
  local_20 = param_2;
  local_1c = param_6;
  local_18 = param_7;
  local_8 = 0;
  local_14 = 0x40298c;
  local_2c = (undefined4 *)*unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_2c;
  local_34 = param_1;
  local_30 = param_3;
  ppuVar3 = &local_34;
  uVar2 = *param_1;
  pDVar1 = FUN_00405240();
  (*(code *)pDVar1[0x1a])(uVar2,ppuVar3);
  if (local_8 == 0) {
    *unaff_FS_OFFSET = (int)local_2c;
  }
  else {
    *local_2c = *(undefined4 *)*unaff_FS_OFFSET;
    *unaff_FS_OFFSET = (int)local_2c;
  }
  return 0;
}



/* VA 004029c0 */

undefined4 __cdecl FUN_004029c0(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3)

{
  undefined4 uVar1;

  if ((param_1->ExceptionFlags & 0x66) != 0) {
    *(undefined4 *)((int)param_2 + 0x24) = 1;
    return 1;
  }
  FUN_00404740(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),*(PVOID *)((int)param_2 + 0x14),1);
  if (*(int *)((int)param_2 + 0x24) == 0) {
    FUN_004027c0(param_2,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x00402a34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)((int)param_2 + 0x18))();
  return uVar1;
}



/* VA 00402a50 */

int __cdecl FUN_00402a50(int param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;

  iVar2 = *(int *)(param_1 + 0x10);
  uVar5 = *(uint *)(param_1 + 0xc);
  uVar3 = uVar5;
  uVar4 = uVar5;
  while (-1 < param_2) {
    if (uVar5 == 0xffffffff) {
      FUN_00405350();
    }
    uVar5 = uVar5 - 1;
    iVar1 = iVar2 + uVar5 * 0x14;
    if (((*(int *)(iVar1 + 4) < param_3) && (param_3 <= *(int *)(iVar1 + 8))) ||
       (uVar5 == 0xffffffff)) {
      param_2 = param_2 + -1;
      uVar3 = uVar4;
      uVar4 = uVar5;
    }
  }
  uVar5 = uVar5 + 1;
  *param_4 = uVar5;
  *param_5 = uVar3;
  if ((*(uint *)(param_1 + 0xc) < uVar3) || (uVar3 < uVar5)) {
    FUN_00405350();
  }
  return iVar2 + uVar5 * 0x14;
}



/* VA 00402ad0 */

/* Library Function - Single Match
    __global_unwind2

   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x402ae8,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}



/* VA 00402b12 */

/* Library Function - Single Match
    __local_unwind2

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

void __cdecl __local_unwind2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  int iStack_10;

  iStack_10 = param_1;
  puStack_18 = &LAB_00402af0;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_00402ba6();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}



/* VA 00402b7a */

/* Library Function - Single Match
    __abnormal_termination

   Library: Visual Studio */

int __cdecl __abnormal_termination(void)

{
  int iVar1;
  int iVar2;
  int *unaff_FS_OFFSET;

  iVar2 = 0;
  iVar1 = *unaff_FS_OFFSET;
  if ((*(undefined1 **)(iVar1 + 4) == &LAB_00402af0) &&
     (*(int *)(iVar1 + 8) == *(int *)(*(int *)(iVar1 + 0xc) + 0xc))) {
    iVar2 = 1;
  }
  return iVar2;
}



/* VA 00402b9d */

/* Library Function - Single Match
    __NLG_Notify1

   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __fastcall __NLG_Notify1(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;

  DAT_00423740 = param_1;
  DAT_0042373c = in_EAX;
  DAT_00423744 = unaff_EBP;
  return;
}



/* VA 00402ba6 */

void FUN_00402ba6(void)

{
  undefined4 in_EAX;
  int unaff_EBP;

  DAT_00423740 = *(undefined4 *)(unaff_EBP + 8);
  DAT_0042373c = in_EAX;
  DAT_00423744 = unaff_EBP;
  return;
}



/* VA 00402bc0 */

void FUN_00402bc0(void)

{
  undefined4 unaff_FS_OFFSET;
  undefined1 auStack_c [12];

  *(undefined1 **)unaff_FS_OFFSET = auStack_c;
  return;
}



/* VA 00402be0 */

int __cdecl FUN_00402be0(undefined1 *param_1,char *param_2)

{
  int iVar1;
  undefined1 *local_20;
  int local_1c;
  undefined1 *local_18;
  undefined4 local_14;

  local_18 = param_1;
  local_20 = param_1;
  local_14 = 0x42;
  local_1c = 0x7fffffff;
  iVar1 = FUN_00405510((int *)&local_20,param_2,(undefined4 *)&stack0x0000000c);
  local_1c = local_1c + -1;
  if (-1 < local_1c) {
    *local_20 = 0;
    return iVar1;
  }
  FUN_004053e0(0,(int *)&local_20);
  return iVar1;
}



/* VA 00402c50 */

/* Library Function - Single Match
    _strrchr

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strrchr(char *_Str,int _Ch)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;

  iVar2 = -1;
  do {
    pcVar4 = _Str;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = _Str + 1;
    cVar1 = *_Str;
    _Str = pcVar4;
  } while (cVar1 != '\0');
  iVar2 = -(iVar2 + 1);
  pcVar4 = pcVar4 + -1;
  do {
    pcVar3 = pcVar4;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar3 = pcVar4 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar3;
  } while ((char)_Ch != cVar1);
  pcVar3 = pcVar3 + 1;
  if (*pcVar3 != (char)_Ch) {
    pcVar3 = (char *)0x0;
  }
  return pcVar3;
}



/* VA 00402c80 */

void __cdecl FUN_00402c80(undefined *param_1)

{
  undefined *lpMem;
  byte *pbVar1;
  int local_4;

  lpMem = param_1;
  if (param_1 != (undefined *)0x0) {
    FUN_00406040(9);
    pbVar1 = (byte *)FUN_00406460(lpMem,&local_4,(uint *)&param_1);
    if (pbVar1 != (byte *)0x0) {
      FUN_004064c0(local_4,(int)param_1,pbVar1);
      FUN_004060c0(9);
      return;
    }
    FUN_004060c0(9);
    HeapFree(DAT_0042a1c4,0,lpMem);
  }
  return;
}



/* VA 00402cf0 */

void __cdecl FUN_00402cf0(uint param_1)

{
  FUN_00402d10(param_1,DAT_00428de4);
  return;
}



/* VA 00402d10 */

int * __cdecl FUN_00402d10(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;

  if (param_1 < 0xffffffe1) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    do {
      if (param_1 < 0xffffffe1) {
        piVar1 = FUN_00402d60(param_1);
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
      iVar2 = FUN_004069b0(param_1);
    } while (iVar2 != 0);
  }
  return (int *)0x0;
}



/* VA 00402d60 */

int * __cdecl FUN_00402d60(int param_1)

{
  int *piVar1;
  uint dwBytes;

  dwBytes = param_1 + 0xfU & 0xfffffff0;
  if (dwBytes <= DAT_00425b9c) {
    FUN_00406040(9);
    piVar1 = FUN_00406520(param_1 + 0xfU >> 4);
    FUN_004060c0(9);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
  }
  piVar1 = HeapAlloc(DAT_0042a1c4,0,dwBytes);
  return piVar1;
}



/* VA 00402dc0 */

/* Library Function - Single Match
    _memset

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  size_t sVar3;
  uint *puVar4;

  if (_Size == 0) {
    return _Dst;
  }
  uVar1 = _Val & 0xff;
  puVar4 = _Dst;
  if (3 < _Size) {
    uVar2 = -(int)_Dst & 3;
    sVar3 = _Size;
    if (uVar2 != 0) {
      sVar3 = _Size - uVar2;
      do {
        *(undefined1 *)puVar4 = (undefined1)_Val;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    _Size = sVar3 & 3;
    uVar2 = sVar3 >> 2;
    if (uVar2 != 0) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}



/* VA 00402e20 */

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
        goto joined_r0x00402e5e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_00402e9b;
        goto LAB_00402f09;
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
joined_r0x00402f05:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_00402f09:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_00402e9b;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x00402f05;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x00402f05;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x00402f05;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x00402e5e:
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
LAB_00402e9b:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}



/* VA 00402f20 */

int __cdecl FUN_00402f20(int param_1)

{
  SIZE_T SVar1;
  int *piVar2;

  FUN_00403a00();
  SVar1 = FUN_00403bc0((undefined *)DAT_0042a1cc);
  if (SVar1 < (uint)((int)DAT_0042a1c8 + (4 - (int)DAT_0042a1cc))) {
    SVar1 = FUN_00403bc0((undefined *)DAT_0042a1cc);
    piVar2 = FUN_004069d0(DAT_0042a1cc,SVar1 + 0x10);
    if (piVar2 == (int *)0x0) {
      FUN_00403a10();
      return 0;
    }
    DAT_0042a1c8 = piVar2 + ((int)DAT_0042a1c8 - (int)DAT_0042a1cc >> 2);
    DAT_0042a1cc = piVar2;
  }
  *DAT_0042a1c8 = param_1;
  DAT_0042a1c8 = DAT_0042a1c8 + 1;
  FUN_00403a10();
  return param_1;
}



/* VA 00402fb0 */

int __cdecl FUN_00402fb0(int param_1)

{
  int iVar1;

  iVar1 = FUN_00402f20(param_1);
  return (iVar1 != 0) - 1;
}



/* VA 00403010 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  byte bVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  HMODULE pHVar5;
  UINT UVar6;
  byte *pbVar7;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar9;
  _STARTUPINFOA local_60;
  undefined1 *local_1c;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  byte *pbVar8;

  local_8 = 0xffffffff;
  puStack_c = &DAT_0041f100;
  puStack_10 = &LAB_00407548;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  local_1c = &stack0xffffff88;
  DVar2 = GetVersion();
  _DAT_00428be4 = DVar2 >> 8 & 0xff;
  _DAT_00428be0 = DVar2 & 0xff;
  _DAT_00428bdc = _DAT_00428be0 * 0x100 + _DAT_00428be4;
  _DAT_00428bd8 = DVar2 >> 0x10;
  iVar3 = FUN_00405fd0();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  iVar3 = FUN_004051c0();
  if (iVar3 == 0) {
    __amsg_exit(0x10);
  }
  local_8 = 0;
  FUN_00407330();
  FUN_004045e0();
  DAT_0042a1d4 = (byte *)GetCommandLineA();
  DAT_00428bc8 = FUN_004071d0();
  if ((DAT_00428bc8 == (LPSTR)0x0) || (DAT_0042a1d4 == (byte *)0x0)) {
    FUN_00403900(0xffffffff);
  }
  FUN_00406f20();
  FUN_00406e30();
  FUN_004038d0();
  pbVar7 = DAT_0042a1d4;
  if (*DAT_0042a1d4 == 0x22) {
    while( true ) {
      pbVar8 = pbVar7;
      pbVar7 = pbVar8 + 1;
      bVar1 = *pbVar7;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      iVar3 = FUN_00406dd0((uint)bVar1);
      if (iVar3 != 0) {
        pbVar7 = pbVar8 + 2;
      }
    }
    if (*pbVar7 == 0x22) {
      pbVar7 = pbVar8 + 2;
    }
  }
  else {
    for (; 0x20 < *pbVar7; pbVar7 = pbVar7 + 1) {
    }
  }
  for (; (*pbVar7 != 0 && (*pbVar7 < 0x21)); pbVar7 = pbVar7 + 1) {
  }
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  if ((local_60.dwFlags & 1) == 0) {
    uVar4 = 10;
  }
  else {
    uVar4 = local_60._48_4_ & 0xffff;
  }
  uVar9 = 0;
  pHVar5 = GetModuleHandleA((LPCSTR)0x0);
  UVar6 = FUN_0040a7e4(pHVar5,uVar9,pbVar7,uVar4);
  FUN_00403900(UVar6);
  *unaff_FS_OFFSET = local_14;
  return;
}



/* VA 004031c0 */

/* Library Function - Single Match
    __amsg_exit

   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_00428bd0 == 1) {
    FUN_00407620();
  }
  FUN_00407660((undefined *)param_1);
  (*(code *)PTR___exit_00423750)(0xff);
  return;
}



/* VA 004031f0 */

void __fastcall FUN_004031f0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0041f114;
  FUN_00406040(0x1b);
  if ((undefined *)param_1[1] != (undefined *)0x0) {
    FUN_00402c80((undefined *)param_1[1]);
  }
  FUN_004060c0(0x1b);
  return;
}



/* VA 00403220 */

undefined4 * __thiscall FUN_00403220(void *this,byte param_1)

{
  FUN_004031f0(this);
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 00403240 */

byte * __cdecl FUN_00403240(byte *param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;

  if (DAT_00428d1c == 0) {
    pbVar3 = (byte *)_strchr((char *)param_1,param_2);
    return pbVar3;
  }
  FUN_00406040(0x19);
  bVar1 = *param_1;
  while (uVar2 = (uint)bVar1, bVar1 != 0) {
    if ((*(byte *)((int)&DAT_00428c18 + uVar2 + 1) & 4) == 0) {
      pbVar3 = param_1;
      if (param_2 == uVar2) break;
    }
    else {
      pbVar3 = param_1 + 1;
      if (param_1[1] == 0) {
        FUN_004060c0(0x19);
        return (byte *)0x0;
      }
      if (param_2 == CONCAT11(bVar1,param_1[1])) {
        FUN_004060c0(0x19);
        return param_1;
      }
    }
    param_1 = pbVar3 + 1;
    bVar1 = pbVar3[1];
  }
  FUN_004060c0(0x19);
  return (byte *)((param_2 != uVar2) - 1 & (uint)param_1);
}



/* VA 00403310 */

void FUN_00403310(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  DWORD *pDVar2;
  DWORD *pDVar3;
  DWORD local_20 [4];
  DWORD local_10;
  ULONG_PTR local_c;
  undefined4 local_8;
  undefined4 local_4;

  pDVar2 = &DAT_0041f118;
  pDVar3 = local_20;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pDVar3 = *pDVar2;
    pDVar2 = pDVar2 + 1;
    pDVar3 = pDVar3 + 1;
  }
  local_8 = param_1;
  local_4 = param_2;
  RaiseException(local_20[0],local_20[1],local_10,&local_c);
  return;
}



/* VA 00403360 */

int __cdecl FUN_00403360(byte *param_1,byte *param_2)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;

  if (DAT_00428d1c != 0) {
    FUN_00406040(0x19);
    pbVar3 = param_2;
    while( true ) {
      param_2._0_2_ = (ushort)*param_1;
      pbVar5 = param_1 + 1;
      if ((*(byte *)((int)&DAT_00428c18 + (ushort)param_2 + 1) & 4) != 0) {
        bVar1 = *pbVar5;
        if (bVar1 == 0) {
          param_2._0_2_ = 0;
        }
        else {
          pbVar5 = param_1 + 2;
          param_2._0_2_ = CONCAT11(*param_1,bVar1);
        }
      }
      uVar2 = (ushort)*pbVar3;
      pbVar4 = pbVar3 + 1;
      if ((*(byte *)((int)&DAT_00428c18 + uVar2 + 1) & 4) != 0) {
        bVar1 = *pbVar4;
        if (bVar1 == 0) {
          uVar2 = 0;
        }
        else {
          pbVar4 = pbVar3 + 2;
          uVar2 = CONCAT11(*pbVar3,bVar1);
        }
      }
      if ((ushort)param_2 != uVar2) break;
      pbVar3 = pbVar4;
      param_1 = pbVar5;
      if ((ushort)param_2 == 0) {
        FUN_004060c0(0x19);
        return 0;
      }
    }
    FUN_004060c0(0x19);
    return (-(uint)(uVar2 < (ushort)param_2) & 2) - 1;
  }
  while( true ) {
    bVar1 = *param_1;
    bVar6 = bVar1 < *param_2;
    if (bVar1 != *param_2) break;
    if (bVar1 == 0) {
      return 0;
    }
    bVar1 = param_1[1];
    bVar6 = bVar1 < param_2[1];
    if (bVar1 != param_2[1]) break;
    param_1 = param_1 + 2;
    param_2 = param_2 + 2;
    if (bVar1 == 0) {
      return 0;
    }
  }
  return (1 - (uint)bVar6) - (uint)(bVar6 != 0);
}



/* VA 00403460 */

/* Library Function - Single Match
    _memcmp

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  uint *puVar7;
  uint *puVar8;
  bool bVar9;

  if (_Size != 0) {
    if ((((uint)_Buf1 | (uint)_Buf2) & 3) == 0) {
      uVar2 = _Size & 3;
      uVar5 = _Size >> 2;
      bVar9 = false;
      puVar7 = _Buf1;
      puVar8 = _Buf2;
      if (uVar5 != 0) {
        do {
          _Buf1 = puVar7;
          _Buf2 = puVar8;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          _Buf2 = puVar8 + 1;
          _Buf1 = puVar7 + 1;
          bVar9 = *puVar7 == *puVar8;
          puVar7 = _Buf1;
          puVar8 = _Buf2;
        } while (bVar9);
        if (!bVar9) {
          uVar2 = *(uint *)((int)_Buf1 + -4);
          uVar5 = *(uint *)((int)_Buf2 + -4);
          bVar9 = (byte)uVar2 < (byte)uVar5;
          if ((((byte)uVar2 == (byte)uVar5) &&
              (bVar4 = (byte)(uVar2 >> 8), bVar6 = (byte)(uVar5 >> 8), bVar9 = bVar4 < bVar6,
              bVar4 == bVar6)) &&
             (bVar4 = (byte)(uVar2 >> 0x10), bVar6 = (byte)(uVar5 >> 0x10), bVar9 = bVar4 < bVar6,
             bVar4 == bVar6)) {
            bVar9 = (byte)(uVar2 >> 0x18) < (byte)(uVar5 >> 0x18);
          }
          goto LAB_004034da;
        }
      }
      if (uVar2 != 0) {
        uVar5 = *(uint *)_Buf1;
        uVar1 = *(uint *)_Buf2;
        bVar9 = (byte)uVar5 < (byte)uVar1;
        if ((byte)uVar5 != (byte)uVar1) {
LAB_004034da:
          return (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        }
        iVar3 = 0;
        if (uVar2 != 1) {
          bVar6 = (byte)(uVar5 >> 8);
          bVar4 = (byte)(uVar1 >> 8);
          bVar9 = bVar6 < bVar4;
          if (bVar6 != bVar4) goto LAB_004034da;
          iVar3 = 0;
          if (uVar2 != 2) {
            bVar9 = (uVar5 & 0xff0000) < (uVar1 & 0xff0000);
            if ((uVar5 & 0xff0000) != (uVar1 & 0xff0000)) goto LAB_004034da;
            iVar3 = uVar2 - 3;
          }
        }
        return iVar3;
      }
    }
    else {
      if ((_Size & 1) == 0) goto LAB_0040348d;
      bVar9 = *(byte *)_Buf1 < *(byte *)_Buf2;
      if (*(byte *)_Buf1 != *(byte *)_Buf2) goto LAB_004034da;
      _Buf1 = (void *)((int)_Buf1 + 1);
      _Buf2 = (void *)((int)_Buf2 + 1);
      for (_Size = _Size - 1; _Size != 0; _Size = _Size - 2) {
LAB_0040348d:
        bVar9 = *(byte *)_Buf1 < *(byte *)_Buf2;
        if ((*(byte *)_Buf1 != *(byte *)_Buf2) ||
           (bVar9 = *(byte *)((int)_Buf1 + 1) < *(byte *)((int)_Buf2 + 1),
           *(byte *)((int)_Buf1 + 1) != *(byte *)((int)_Buf2 + 1))) goto LAB_004034da;
        _Buf2 = (void *)((int)_Buf2 + 2);
        _Buf1 = (void *)((int)_Buf1 + 2);
      }
    }
  }
  return 0;
}



/* VA 00403510 */

undefined4 * __cdecl FUN_00403510(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;

  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_004036c7_caseD_2;
        case 3:
          goto switchD_004036c7_caseD_3;
        }
        goto switchD_004036c7_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_004036c7_caseD_0;
      case 1:
        goto switchD_004036c7_caseD_1;
      case 2:
        goto switchD_004036c7_caseD_2;
      case 3:
        goto switchD_004036c7_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_004036c7_caseD_2;
            case 3:
              goto switchD_004036c7_caseD_3;
            }
            goto switchD_004036c7_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_004036c7_caseD_2;
            case 3:
              goto switchD_004036c7_caseD_3;
            }
            goto switchD_004036c7_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_004036c7_caseD_2;
            case 3:
              goto switchD_004036c7_caseD_3;
            }
            goto switchD_004036c7_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_004036c7_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_004036c7_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_004036c7_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_004036c7_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_00403545_caseD_2;
      case 3:
        goto switchD_00403545_caseD_3;
      }
      goto switchD_00403545_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_00403545_caseD_0;
    case 1:
      goto switchD_00403545_caseD_1;
    case 2:
      goto switchD_00403545_caseD_2;
    case 3:
      goto switchD_00403545_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00403545_caseD_2;
          case 3:
            goto switchD_00403545_caseD_3;
          }
          goto switchD_00403545_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00403545_caseD_2;
          case 3:
            goto switchD_00403545_caseD_3;
          }
          goto switchD_00403545_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00403545_caseD_2;
          case 3:
            goto switchD_00403545_caseD_3;
          }
          goto switchD_00403545_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_00403545_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_00403545_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_00403545_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_00403545_caseD_0:
  return param_1;
}



/* VA 00403850 */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_00403850(void)

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



/* VA 00403880 */

char * __cdecl FUN_00403880(char *param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;

  if (param_1 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar2 = param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = (char *)FUN_00402cf0(~uVar3);
    if (pcVar2 != (char *)0x0) {
      uVar3 = 0xffffffff;
      do {
        pcVar5 = param_1;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar5 = param_1 + 1;
        cVar1 = *param_1;
        param_1 = pcVar5;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar5 = pcVar5 + -uVar3;
      pcVar6 = pcVar2;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar6 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
      }
      return pcVar2;
    }
  }
  return (char *)0x0;
}



/* VA 004038d0 */

void FUN_004038d0(void)

{
  if (DAT_0042a1d0 != (code *)0x0) {
    (*DAT_0042a1d0)();
  }
  FUN_00403a20((undefined4 *)&DAT_0042305c,(undefined4 *)&DAT_0042306c);
  FUN_00403a20((undefined4 *)&DAT_00423000,(undefined4 *)&DAT_00423058);
  return;
}



/* VA 00403900 */

void __cdecl FUN_00403900(UINT param_1)

{
  FUN_00403940(param_1,0,0);
  return;
}



/* VA 00403920 */

/* Library Function - Single Match
    __exit

   Library: Visual Studio 1998 Release */

void __cdecl __exit(int _Code)

{
  FUN_00403940(_Code,1,0);
  return;
}



/* VA 00403940 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00403940(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  undefined4 *puVar2;
  UINT uExitCode;

  FUN_00403a00();
  if (DAT_00428c14 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_00428c10 = 1;
  DAT_00428c0c = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_0042a1cc != (undefined4 *)0x0) &&
       (puVar2 = (undefined4 *)(DAT_0042a1c8 + -4), puVar1 = DAT_0042a1cc, DAT_0042a1cc <= puVar2))
    {
      do {
        if ((code *)*puVar2 != (code *)0x0) {
          (*(code *)*puVar2)();
          puVar1 = DAT_0042a1cc;
        }
        puVar2 = puVar2 + -1;
      } while (puVar1 <= puVar2);
    }
    FUN_00403a20((undefined4 *)&DAT_00423070,(undefined4 *)&DAT_00423078);
  }
  FUN_00403a20((undefined4 *)&DAT_0042307c,(undefined4 *)&DAT_00423084);
  if (param_3 != 0) {
    FUN_00403a10();
    return;
  }
  DAT_00428c14 = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}



/* VA 00403a00 */

void FUN_00403a00(void)

{
  FUN_00406040(0xd);
  return;
}



/* VA 00403a10 */

void FUN_00403a10(void)

{
  FUN_004060c0(0xd);
  return;
}



/* VA 00403a20 */

void __cdecl FUN_00403a20(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* VA 00403a40 */

int __cdecl FUN_00403a40(short *param_1)

{
  short sVar1;
  short *psVar2;

  sVar1 = *param_1;
  psVar2 = param_1;
  while (psVar2 = psVar2 + 1, sVar1 != 0) {
    sVar1 = *psVar2;
  }
  return ((int)psVar2 - (int)param_1 >> 1) + -1;
}



/* VA 00403a60 */

int __cdecl FUN_00403a60(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;

  while( true ) {
    if (DAT_00425eec < 2) {
      uVar2 = (byte)PTR_DAT_00425ce0[(uint)*param_1 * 2] & 8;
    }
    else {
      uVar2 = FUN_00407c60((uint)*param_1,8);
    }
    if (uVar2 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar2 = (uint)*param_1;
  pbVar6 = param_1 + 1;
  if ((uVar2 == 0x2d) || (uVar4 = uVar2, uVar2 == 0x2b)) {
    uVar4 = (uint)*pbVar6;
    pbVar6 = param_1 + 2;
  }
  iVar5 = 0;
  while( true ) {
    if (DAT_00425eec < 2) {
      uVar3 = (byte)PTR_DAT_00425ce0[uVar4 * 2] & 4;
    }
    else {
      uVar3 = FUN_00407c60(uVar4,4);
    }
    if (uVar3 == 0) break;
    bVar1 = *pbVar6;
    pbVar6 = pbVar6 + 1;
    iVar5 = (uVar4 - 0x30) + iVar5 * 10;
    uVar4 = (uint)bVar1;
  }
  if (uVar2 == 0x2d) {
    iVar5 = -iVar5;
  }
  return iVar5;
}



/* VA 00403b00 */

void __cdecl FUN_00403b00(byte *param_1)

{
  FUN_00403a60(param_1);
  return;
}



/* VA 00403b10 */

undefined * __cdecl FUN_00403b10(undefined *param_1,int *param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined *puVar3;
  uint dwBytes;
  int local_4;

  if ((int *)0xffffffe0 < param_2) {
    return (undefined *)0x0;
  }
  if (param_2 == (int *)0x0) {
    dwBytes = 0x10;
  }
  else {
    dwBytes = (int)param_2 + 0xfU & 0xfffffff0;
  }
  FUN_00406040(9);
  pbVar1 = (byte *)FUN_00406460(param_1,&local_4,(uint *)&param_2);
  if (pbVar1 != (byte *)0x0) {
    puVar3 = (undefined *)0x0;
    if (dwBytes <= DAT_00425b9c) {
      iVar2 = FUN_004068e0(local_4,param_2,pbVar1,dwBytes >> 4);
      if (iVar2 != 0) {
        puVar3 = param_1;
      }
    }
    FUN_004060c0(9);
    return puVar3;
  }
  FUN_004060c0(9);
  puVar3 = HeapReAlloc(DAT_0042a1c4,0x10,param_1,dwBytes);
  return puVar3;
}



/* VA 00403bc0 */

SIZE_T __cdecl FUN_00403bc0(undefined *param_1)

{
  byte bVar1;
  byte *pbVar2;
  SIZE_T SVar3;
  uint local_8;
  undefined4 local_4;

  FUN_00406040(9);
  pbVar2 = (byte *)FUN_00406460(param_1,&local_4,&local_8);
  if (pbVar2 != (byte *)0x0) {
    bVar1 = *pbVar2;
    FUN_004060c0(9);
    return (uint)bVar1 << 4;
  }
  FUN_004060c0(9);
  SVar3 = HeapSize(DAT_0042a1c4,0,param_1);
  return SVar3;
}



/* VA 00403c30 */

uint __cdecl FUN_00403c30(byte *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  DWORD *pDVar4;
  byte bVar5;
  uint local_c;
  byte *local_8;
  uint local_4;

  local_4 = 0;
  bVar5 = *param_1;
  pbVar1 = param_1;
  while( true ) {
    local_c = (uint)bVar5;
    local_8 = pbVar1 + 1;
    if (DAT_00425eec < 2) {
      uVar2 = (byte)PTR_DAT_00425ce0[local_c * 2] & 8;
    }
    else {
      uVar2 = FUN_00407c60(local_c,8);
    }
    if (uVar2 == 0) break;
    bVar5 = *local_8;
    pbVar1 = local_8;
  }
  if (bVar5 == 0x2d) {
    param_4 = param_4 | 2;
  }
  else if (bVar5 != 0x2b) goto LAB_00403cbb;
  bVar5 = *local_8;
  local_8 = pbVar1 + 2;
  local_c = (uint)bVar5;
LAB_00403cbb:
  if ((((int)param_3 < 0) || (param_3 == 1)) || (0x24 < (int)param_3)) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_1;
    }
    return 0;
  }
  if (param_3 == 0) {
    if (bVar5 == 0x30) {
      if ((*local_8 == 0x78) || (param_3 = 8, *local_8 == 0x58)) {
        param_3 = 0x10;
      }
    }
    else {
      param_3 = 10;
    }
  }
  if (((param_3 == 0x10) && (bVar5 == 0x30)) && ((*local_8 == 0x78 || (*local_8 == 0x58)))) {
    bVar5 = local_8[1];
    local_c = (uint)bVar5;
    local_8 = local_8 + 2;
  }
  uVar2 = (uint)(0xffffffff / (ulonglong)param_3);
  do {
    if (DAT_00425eec < 2) {
      uVar3 = (byte)PTR_DAT_00425ce0[local_c * 2] & 4;
    }
    else {
      uVar3 = FUN_00407c60(local_c,4);
    }
    if (uVar3 == 0) {
      if (DAT_00425eec < 2) {
        uVar3 = *(ushort *)(PTR_DAT_00425ce0 + local_c * 2) & 0x103;
      }
      else {
        uVar3 = FUN_00407c60(local_c,0x103);
      }
      if (uVar3 == 0) {
LAB_00403df4:
        local_8 = local_8 + -1;
        if ((param_4 & 8) == 0) {
          if (param_2 != (undefined4 *)0x0) {
            local_8 = param_1;
          }
          local_4 = 0;
        }
        else if (((param_4 & 4) != 0) ||
                (((param_4 & 1) == 0 &&
                 ((((param_4 & 2) != 0 && (0x80000000 < local_4)) ||
                  (((param_4 & 2) == 0 && (0x7fffffff < local_4)))))))) {
          pDVar4 = FUN_00404720();
          *pDVar4 = 0x22;
          if ((param_4 & 1) == 0) {
            local_4 = ((param_4 & 2) != 0) + 0x7fffffff;
          }
          else {
            local_4 = 0xffffffff;
          }
        }
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = local_8;
        }
        if ((param_4 & 2) != 0) {
          local_4 = -local_4;
        }
        return local_4;
      }
      uVar3 = FUN_00407d40((int)(char)bVar5);
      uVar3 = uVar3 - 0x37;
    }
    else {
      uVar3 = (int)(char)bVar5 - 0x30;
    }
    if (param_3 <= uVar3) goto LAB_00403df4;
    if ((local_4 < uVar2) ||
       ((local_4 == uVar2 && (uVar3 <= (uint)(0xffffffff % (ulonglong)param_3))))) {
      local_4 = local_4 * param_3 + uVar3;
      param_4 = param_4 | 8;
    }
    else {
      param_4 = param_4 | 0xc;
    }
    bVar5 = *local_8;
    local_8 = local_8 + 1;
    local_c = (uint)bVar5;
  } while( true );
}



/* VA 00403ec0 */

void __cdecl FUN_00403ec0(byte *param_1,undefined4 *param_2,uint param_3)

{
  FUN_00403c30(param_1,param_2,param_3,1);
  return;
}



/* VA 00403ef0 */

undefined4 * __cdecl FUN_00403ef0(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;

  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_004040a7_caseD_2;
        case 3:
          goto switchD_004040a7_caseD_3;
        }
        goto switchD_004040a7_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_004040a7_caseD_0;
      case 1:
        goto switchD_004040a7_caseD_1;
      case 2:
        goto switchD_004040a7_caseD_2;
      case 3:
        goto switchD_004040a7_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_004040a7_caseD_2;
            case 3:
              goto switchD_004040a7_caseD_3;
            }
            goto switchD_004040a7_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_004040a7_caseD_2;
            case 3:
              goto switchD_004040a7_caseD_3;
            }
            goto switchD_004040a7_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_004040a7_caseD_2;
            case 3:
              goto switchD_004040a7_caseD_3;
            }
            goto switchD_004040a7_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_004040a7_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_004040a7_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_004040a7_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_004040a7_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_00403f25_caseD_2;
      case 3:
        goto switchD_00403f25_caseD_3;
      }
      goto switchD_00403f25_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_00403f25_caseD_0;
    case 1:
      goto switchD_00403f25_caseD_1;
    case 2:
      goto switchD_00403f25_caseD_2;
    case 3:
      goto switchD_00403f25_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00403f25_caseD_2;
          case 3:
            goto switchD_00403f25_caseD_3;
          }
          goto switchD_00403f25_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00403f25_caseD_2;
          case 3:
            goto switchD_00403f25_caseD_3;
          }
          goto switchD_00403f25_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_00403f25_caseD_2;
          case 3:
            goto switchD_00403f25_caseD_3;
          }
          goto switchD_00403f25_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_00403f25_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_00403f25_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_00403f25_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_00403f25_caseD_0:
  return param_1;
}



/* VA 00404230 */

int * __cdecl FUN_00404230(int param_1,int param_2)

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
      if (DAT_00425b9c < dwBytes) {
LAB_004042a4:
        if (piVar3 != (int *)0x0) {
          return piVar3;
        }
      }
      else {
        FUN_00406040(9);
        piVar3 = FUN_00406520(dwBytes >> 4);
        FUN_004060c0(9);
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
          goto LAB_004042a4;
        }
      }
      piVar3 = HeapAlloc(DAT_0042a1c4,8,dwBytes);
    }
    if ((piVar3 != (int *)0x0) || (DAT_00428de4 == 0)) {
      return piVar3;
    }
    iVar1 = FUN_004069b0(dwBytes);
    if (iVar1 == 0) {
      return (int *)0x0;
    }
  } while( true );
}



/* VA 004042e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_004042e0(int param_1)

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

  FUN_00406040(0x19);
  CodePage = FUN_00404500(param_1);
  if (CodePage == DAT_00428d1c) {
    FUN_004060c0(0x19);
    return 0;
  }
  if (CodePage != 0) {
    iVar10 = 0;
    pUVar5 = &DAT_00423788;
    do {
      if (*pUVar5 == CodePage) {
        puVar14 = &DAT_00428c18;
        for (iVar9 = 0x40; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar14 = 0;
          puVar14 = puVar14 + 1;
        }
        *(undefined1 *)puVar14 = 0;
        uVar7 = 0;
        iVar10 = iVar10 * 0x30;
        pbVar12 = (byte *)(iVar10 + 0x423798);
        do {
          bVar3 = *pbVar12;
          for (pbVar13 = pbVar12; (bVar3 != 0 && (bVar3 = pbVar13[1], bVar3 != 0));
              pbVar13 = pbVar13 + 2) {
            uVar8 = (uint)*pbVar13;
            if (uVar8 <= bVar3) {
              bVar4 = (&DAT_00423780)[uVar7];
              do {
                pbVar2 = (byte *)((int)&DAT_00428c18 + uVar8 + 1);
                *pbVar2 = *pbVar2 | bVar4;
                uVar8 = uVar8 + 1;
              } while (uVar8 <= bVar3);
            }
            bVar3 = pbVar13[2];
          }
          uVar7 = uVar7 + 1;
          pbVar12 = pbVar12 + 8;
        } while (uVar7 < 4);
        DAT_00428d1c = CodePage;
        _DAT_00428d20 = FUN_00404550(CodePage);
        _DAT_00428d28 = *(undefined4 *)(iVar10 + 0x42378c);
        _DAT_00428d2c = *(undefined4 *)(iVar10 + 0x423790);
        _DAT_00428d30 = *(undefined4 *)(iVar10 + 0x423794);
        FUN_004060c0(0x19);
        return 0;
      }
      pUVar5 = pUVar5 + 0xc;
      iVar10 = iVar10 + 1;
    } while (pUVar5 < &DAT_00423878);
    BVar6 = GetCPInfo(CodePage,&local_14);
    if (BVar6 == 1) {
      puVar14 = &DAT_00428c18;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar14 = 0;
        puVar14 = puVar14 + 1;
      }
      *(undefined1 *)puVar14 = 0;
      if (local_14.MaxCharSize < 2) {
        DAT_00428d1c = 0;
        _DAT_00428d20 = 0;
      }
      else {
        if (local_14.LeadByte[0] != '\0') {
          pBVar11 = local_14.LeadByte + 1;
          do {
            bVar3 = *pBVar11;
            if (bVar3 == 0) break;
            for (uVar7 = (uint)pBVar11[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
              *(byte *)((int)&DAT_00428c18 + uVar7 + 1) =
                   *(byte *)((int)&DAT_00428c18 + uVar7 + 1) | 4;
            }
            pBVar1 = pBVar11 + 1;
            pBVar11 = pBVar11 + 2;
          } while (*pBVar1 != 0);
        }
        uVar7 = 1;
        do {
          *(byte *)((int)&DAT_00428c18 + uVar7 + 1) = *(byte *)((int)&DAT_00428c18 + uVar7 + 1) | 8;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 0xff);
        DAT_00428d1c = CodePage;
        _DAT_00428d20 = FUN_00404550(CodePage);
      }
      _DAT_00428d28 = 0;
      _DAT_00428d2c = 0;
      _DAT_00428d30 = 0;
      FUN_004060c0(0x19);
      return 0;
    }
    if (DAT_00428d34 == 0) {
      FUN_004060c0(0x19);
      return 0xffffffff;
    }
  }
  FUN_004045b0();
  FUN_004060c0(0x19);
  return 0;
}



/* VA 00404500 */

int __cdecl FUN_00404500(int param_1)

{
  int iVar1;
  bool bVar2;

  if (param_1 == -2) {
    DAT_00428d34 = 1;
                    /* WARNING: Could not recover jumptable at 0x0040451d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00428d34 = 1;
                    /* WARNING: Could not recover jumptable at 0x00404532. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_00428f28;
  }
  DAT_00428d34 = (uint)bVar2;
  return param_1;
}



/* VA 00404550 */

undefined4 __cdecl FUN_00404550(undefined4 param_1)

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



/* VA 004045b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004045b0(void)

{
  int iVar1;
  undefined4 *puVar2;

  puVar2 = &DAT_00428c18;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_00428d1c = 0;
  _DAT_00428d20 = 0;
  _DAT_00428d28 = 0;
  _DAT_00428d2c = 0;
  _DAT_00428d30 = 0;
  return;
}



/* VA 004045e0 */

void FUN_004045e0(void)

{
  FUN_004042e0(-3);
  return;
}



/* VA 004045f0 */

byte * __cdecl FUN_004045f0(byte *param_1)

{
  byte *pbVar1;

  pbVar1 = param_1 + 1;
  if ((*(byte *)((int)&DAT_00428c18 + *param_1 + 1) & 4) != 0) {
    pbVar1 = param_1 + 2;
  }
  return pbVar1;
}



/* VA 00404610 */

byte * __cdecl FUN_00404610(byte *param_1,uint param_2)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  byte *pbVar5;

  pbVar5 = (byte *)0x0;
  if (DAT_00428d1c == 0) {
    pbVar5 = (byte *)_strrchr((char *)param_1,param_2);
    return pbVar5;
  }
  FUN_00406040(0x19);
  do {
    bVar3 = *param_1;
    if ((*(byte *)((int)&DAT_00428c18 + bVar3 + 1) & 4) == 0) {
      pbVar4 = param_1;
      bVar2 = bVar3;
      if (param_2 == bVar3) {
LAB_00404688:
        pbVar5 = pbVar4;
        bVar3 = bVar2;
      }
    }
    else {
      bVar2 = param_1[1];
      pbVar4 = param_1 + 1;
      if (bVar2 == 0) {
        bVar3 = bVar2;
        if (pbVar5 == (byte *)0x0) goto LAB_00404688;
      }
      else {
        uVar1 = CONCAT11(bVar3,bVar2);
        bVar3 = bVar2;
        if (param_2 == uVar1) {
          pbVar5 = param_1;
        }
      }
    }
    param_1 = pbVar4 + 1;
    if (bVar3 == 0) {
      FUN_004060c0(0x19);
      return pbVar5;
    }
  } while( true );
}



/* VA 004046a0 */

void __cdecl FUN_004046a0(undefined *param_1)

{
  DWORD *pDVar1;
  undefined **ppuVar2;
  int iVar3;

  pDVar1 = FUN_00404730();
  iVar3 = 0;
  *pDVar1 = (DWORD)param_1;
  ppuVar2 = (undefined **)&DAT_00423878;
  do {
    if (param_1 == *ppuVar2) {
      pDVar1 = FUN_00404720();
      *pDVar1 = *(DWORD *)(iVar3 * 8 + 0x42387c);
      return;
    }
    ppuVar2 = ppuVar2 + 2;
    iVar3 = iVar3 + 1;
  } while (ppuVar2 < &PTR_DAT_004239e0);
  if (((undefined *)0x12 < param_1) && (param_1 < (undefined *)0x25)) {
    pDVar1 = FUN_00404720();
    *pDVar1 = 0xd;
    return;
  }
  if (((undefined *)0xbb < param_1) && (param_1 < (undefined *)0xcb)) {
    pDVar1 = FUN_00404720();
    *pDVar1 = 8;
    return;
  }
  pDVar1 = FUN_00404720();
  *pDVar1 = 0x16;
  return;
}



/* VA 00404720 */

DWORD * FUN_00404720(void)

{
  DWORD *pDVar1;

  pDVar1 = FUN_00405240();
  return pDVar1 + 2;
}



/* VA 00404730 */

DWORD * FUN_00404730(void)

{
  DWORD *pDVar1;

  pDVar1 = FUN_00405240();
  return pDVar1 + 3;
}



/* VA 00404740 */

undefined4 __cdecl
FUN_00404740(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int *param_5,
            int param_6,PVOID param_7,undefined4 param_8)

{
  code *pcVar1;
  undefined4 uVar2;

  if (*param_5 != 0x19930520) {
    FUN_00405350();
  }
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    if (param_5[3] != 0) {
      if (((param_1->ExceptionCode == 0xe06d7363) && (0x19930520 < param_1->ExceptionInformation[0])
          ) && (pcVar1 = *(code **)(param_1->ExceptionInformation[2] + 8), pcVar1 != (code *)0x0)) {
        uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar2;
      }
      FUN_00404810(param_1,param_2,param_3,param_4,(int)param_5,(char)param_8,param_6,param_7);
    }
  }
  else if ((param_5[1] != 0) && (param_6 == 0)) {
    FUN_00404bb0((int)param_2,param_4,(int)param_5,-1);
    return 1;
  }
  return 1;
}



/* VA 00404810 */

void __cdecl
FUN_00404810(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            char param_6,int param_7,PVOID param_8)

{
  byte bVar1;
  bool bVar2;
  DWORD *pDVar3;
  undefined3 extraout_var;
  byte *pbVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint local_20;
  int *local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  int *local_8;
  int local_4;

  iVar7 = *(int *)((int)param_2 + 8);
  local_10 = iVar7;
  if ((iVar7 < -1) || (*(int *)(param_5 + 4) <= iVar7)) {
    FUN_00405350();
  }
  if (param_1->ExceptionCode == 0xe06d7363) {
    if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
       (param_1->ExceptionInformation[2] == 0)) {
      pDVar3 = FUN_00405240();
      if (pDVar3[0x1b] == 0) {
        return;
      }
      pDVar3 = FUN_00405240();
      param_1 = (PEXCEPTION_RECORD)pDVar3[0x1b];
      pDVar3 = FUN_00405240();
      param_3 = pDVar3[0x1c];
      bVar2 = FUN_00407fb0(param_1,1);
      if (CONCAT31(extraout_var,bVar2) == 0) {
        FUN_00405350();
      }
      if (param_1->ExceptionCode != 0xe06d7363) goto LAB_00404a86;
      if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
         (param_1->ExceptionInformation[2] == 0)) {
        FUN_00405350();
      }
    }
    if (((param_1->ExceptionCode == 0xe06d7363) && (param_1->NumberParameters == 3)) &&
       (param_1->ExceptionInformation[0] == 0x19930520)) {
      local_1c = (int *)FUN_00402a50(param_5,param_7,iVar7,&local_20,&local_c);
      if (local_20 < local_c) {
        do {
          if ((*local_1c <= iVar7) && (iVar7 <= local_1c[1])) {
            local_14 = local_1c[3];
            pbVar9 = (byte *)local_1c[4];
            if (0 < local_14) {
              piVar6 = *(int **)(param_1->ExceptionInformation[2] + 0xc);
              local_8 = piVar6 + 1;
              local_4 = *piVar6;
              do {
                local_18 = local_4;
                if (0 < local_4) {
                  iVar7 = *(int *)(pbVar9 + 4);
                  piVar6 = local_8;
                  do {
                    if ((iVar7 == 0) || (pbVar4 = (byte *)(iVar7 + 8), *(char *)(iVar7 + 8) == '\0')
                       ) {
LAB_004049df:
                      bVar2 = true;
                    }
                    else {
                      iVar5 = *(int *)((byte *)*piVar6 + 4);
                      if (iVar7 == iVar5) {
LAB_004049ba:
                        if (((((*(byte *)*piVar6 & 2) == 0) || ((*pbVar9 & 8) != 0)) &&
                            (((*(uint *)param_1->ExceptionInformation[2] & 1) == 0 ||
                             ((*pbVar9 & 1) != 0)))) &&
                           (((*(uint *)param_1->ExceptionInformation[2] & 2) == 0 ||
                            ((*pbVar9 & 2) != 0)))) goto LAB_004049df;
                        bVar2 = false;
                      }
                      else {
                        pbVar8 = (byte *)(iVar5 + 8);
                        do {
                          bVar1 = *pbVar4;
                          bVar2 = bVar1 < *pbVar8;
                          if (bVar1 != *pbVar8) {
LAB_0040499d:
                            iVar5 = (1 - (uint)bVar2) - (uint)(bVar2 != 0);
                            goto LAB_004049a2;
                          }
                          if (bVar1 == 0) break;
                          bVar1 = pbVar4[1];
                          bVar2 = bVar1 < pbVar8[1];
                          if (bVar1 != pbVar8[1]) goto LAB_0040499d;
                          pbVar4 = pbVar4 + 2;
                          pbVar8 = pbVar8 + 2;
                        } while (bVar1 != 0);
                        iVar5 = 0;
LAB_004049a2:
                        if (iVar5 == 0) goto LAB_004049ba;
                        bVar2 = false;
                      }
                    }
                    if (bVar2) {
                      FUN_00404c90(param_1,param_2,param_3,param_4,param_5,pbVar9,(byte *)*piVar6,
                                   local_1c,param_7,param_8);
                      iVar7 = local_10;
                      goto LAB_00404a4f;
                    }
                    piVar6 = piVar6 + 1;
                    local_18 = local_18 + -1;
                  } while (0 < local_18);
                }
                local_14 = local_14 + -1;
                pbVar9 = pbVar9 + 0x10;
                iVar7 = local_10;
              } while (0 < local_14);
            }
          }
LAB_00404a4f:
          local_20 = local_20 + 1;
          local_1c = local_1c + 5;
        } while (local_20 < local_c);
      }
      if (param_6 == '\0') {
        return;
      }
      FUN_004050c0((int)param_1);
      return;
    }
  }
LAB_00404a86:
  if (param_6 != '\0') {
    FUN_004052c0();
    return;
  }
  FUN_00404ad0(param_1,param_2,param_3,param_4,param_5,iVar7,param_7,param_8);
  return;
}



/* VA 00404ad0 */

void __cdecl
FUN_00404ad0(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            int param_6,int param_7,PVOID param_8)

{
  DWORD *pDVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint local_8;
  uint local_4;

  pDVar1 = FUN_00405240();
  if ((pDVar1[0x1a] != 0) &&
     (iVar2 = FUN_004028f0(&param_1->ExceptionCode,param_2,param_3,param_4,param_5,param_7,param_8),
     iVar2 != 0)) {
    return;
  }
  piVar3 = (int *)FUN_00402a50(param_5,param_7,param_6,&local_8,&local_4);
  if (local_8 < local_4) {
    do {
      if ((*piVar3 <= param_6) && (param_6 <= piVar3[1])) {
        iVar4 = piVar3[4] + piVar3[3] * 0x10;
        iVar2 = *(int *)(iVar4 + -0xc);
        if ((iVar2 == 0) || (*(char *)(iVar2 + 8) == '\0')) {
          FUN_00404c90(param_1,param_2,param_3,param_4,param_5,(byte *)(iVar4 + -0x10),(byte *)0x0,
                       piVar3,param_7,param_8);
        }
      }
      local_8 = local_8 + 1;
      piVar3 = piVar3 + 5;
    } while (local_8 < local_4);
  }
  return;
}



/* VA 00404bb0 */

void __cdecl FUN_00404bb0(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  puStack_c = &DAT_0041f260;
  puStack_10 = &LAB_00407548;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  for (iVar2 = *(int *)(param_1 + 8); local_8 = 0xffffffff, iVar2 != param_4;
      iVar2 = *(int *)(*(int *)(param_3 + 8) + iVar2 * 8)) {
    if ((iVar2 < 0) || (*(int *)(param_3 + 4) <= iVar2)) {
      FUN_00405350();
    }
    local_8 = 0;
    iVar1 = *(int *)(*(int *)(param_3 + 8) + 4 + iVar2 * 8);
    if (iVar1 != 0) {
      __CallSettingFrame_12(iVar1,param_1,0x103);
    }
  }
  *(int *)(param_1 + 8) = iVar2;
  *unaff_FS_OFFSET = local_14;
  return;
}



/* VA 00404c90 */

void __cdecl
FUN_00404c90(PEXCEPTION_RECORD param_1,PVOID param_2,DWORD param_3,undefined4 param_4,int param_5,
            byte *param_6,byte *param_7,int *param_8,int param_9,PVOID param_10)

{
  undefined *UNRECOVERED_JUMPTABLE;

  if (param_7 != (byte *)0x0) {
    FUN_00404eb0((int)param_1,(int)param_2,param_6,param_7);
  }
  if (param_10 == (PVOID)0x0) {
    param_10 = param_2;
  }
  FUN_004027c0(param_10,param_1);
  FUN_00404bb0((int)param_2,param_4,param_5,*param_8);
  *(int *)((int)param_2 + 8) = param_8[1] + 1;
  UNRECOVERED_JUMPTABLE =
       (undefined *)
       FUN_00404d20((DWORD)param_1,param_2,param_3,param_5,*(undefined4 *)(param_6 + 0xc),param_9,
                    0x100);
  if (UNRECOVERED_JUMPTABLE != (undefined *)0x0) {
    FUN_00402770(UNRECOVERED_JUMPTABLE);
  }
  return;
}



/* VA 00404d20 */

undefined4 __cdecl
FUN_00404d20(DWORD param_1,undefined4 param_2,DWORD param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7)

{
  DWORD *pDVar1;
  undefined4 uVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  local_8 = 0xffffffff;
  puStack_c = &DAT_0041f270;
  puStack_10 = &LAB_00407548;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  FUN_00405240();
  FUN_00405240();
  pDVar1 = FUN_00405240();
  pDVar1[0x1b] = param_1;
  pDVar1 = FUN_00405240();
  pDVar1[0x1c] = param_3;
  local_8 = 1;
  uVar2 = FUN_00402860(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_00404e18();
  *unaff_FS_OFFSET = local_14;
  return uVar2;
}



/* VA 00404e18 */

void FUN_00404e18(void)

{
  DWORD *pDVar1;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;

  *(undefined4 *)(unaff_ESI + -4) = *(undefined4 *)(unaff_EBP + -0x28);
  pDVar1 = FUN_00405240();
  pDVar1[0x1b] = *(DWORD *)(unaff_EBP + -0x1c);
  pDVar1 = FUN_00405240();
  pDVar1[0x1c] = *(DWORD *)(unaff_EBP + -0x20);
  if ((((*unaff_EDI == -0x1f928c9d) && (unaff_EDI[4] == 3)) && (unaff_EDI[5] == 0x19930520)) &&
     ((*(int *)(unaff_EBP + -0x24) == 0 && (unaff_EBX != 0)))) {
    __abnormal_termination();
    FUN_004050c0((int)unaff_EDI);
  }
  return;
}



/* VA 00404eb0 */

void __cdecl FUN_00404eb0(int param_1,int param_2,byte *param_3,byte *param_4)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined4 *puVar4;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined4 *unaff_FS_OFFSET;
  uint uVar5;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  puStack_c = &DAT_0041f288;
  puStack_10 = &LAB_00407548;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  if (((*(int *)(param_3 + 4) != 0) && (*(char *)(*(int *)(param_3 + 4) + 8) != '\0')) &&
     (*(int *)(param_3 + 8) != 0)) {
    piVar1 = (int *)(param_2 + 0xc + *(int *)(param_3 + 8));
    local_8 = 0;
    if ((*param_3 & 8) == 0) {
      if ((*param_4 & 1) == 0) {
        if (*(int *)(param_4 + 0x18) == 0) {
          bVar2 = FUN_00407fb0(*(void **)(param_1 + 0x18),1);
          if ((CONCAT31(extraout_var_03,bVar2) != 0) &&
             (bVar2 = FUN_00407fd0(piVar1,1), CONCAT31(extraout_var_04,bVar2) != 0)) {
            uVar5 = *(uint *)(param_4 + 0x14);
            puVar4 = (undefined4 *)FUN_00405140(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
            FUN_00403ef0(piVar1,puVar4,uVar5);
            goto LAB_004050a0;
          }
        }
        else {
          bVar2 = FUN_00407fb0(*(void **)(param_1 + 0x18),1);
          if (((CONCAT31(extraout_var_05,bVar2) != 0) &&
              (bVar2 = FUN_00407fd0(piVar1,1), CONCAT31(extraout_var_06,bVar2) != 0)) &&
             (bVar2 = FUN_00407ff0(*(FARPROC *)(param_4 + 0x18)),
             CONCAT31(extraout_var_07,bVar2) != 0)) {
            if ((*param_4 & 4) == 0) {
              FUN_00405140(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
              FUN_004027b0(piVar1,*(undefined **)(param_4 + 0x18));
            }
            else {
              FUN_00405140(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
              FUN_004027b0(piVar1,*(undefined **)(param_4 + 0x18));
            }
            goto LAB_004050a0;
          }
        }
      }
      else {
        bVar2 = FUN_00407fb0(*(void **)(param_1 + 0x18),1);
        if ((CONCAT31(extraout_var_01,bVar2) != 0) &&
           (bVar2 = FUN_00407fd0(piVar1,1), CONCAT31(extraout_var_02,bVar2) != 0)) {
          FUN_00403ef0(piVar1,*(undefined4 **)(param_1 + 0x18),*(uint *)(param_4 + 0x14));
          if ((*(int *)(param_4 + 0x14) == 4) && (*piVar1 != 0)) {
            iVar3 = FUN_00405140(*piVar1,(int *)(param_4 + 8));
            *piVar1 = iVar3;
          }
          goto LAB_004050a0;
        }
      }
    }
    else {
      bVar2 = FUN_00407fb0(*(void **)(param_1 + 0x18),1);
      if ((CONCAT31(extraout_var,bVar2) != 0) &&
         (bVar2 = FUN_00407fd0(piVar1,1), CONCAT31(extraout_var_00,bVar2) != 0)) {
        iVar3 = *(int *)(param_1 + 0x18);
        *piVar1 = iVar3;
        iVar3 = FUN_00405140(iVar3,(int *)(param_4 + 8));
        *piVar1 = iVar3;
        goto LAB_004050a0;
      }
    }
    FUN_00405350();
  }
LAB_004050a0:
  *unaff_FS_OFFSET = local_14;
  return;
}



/* VA 004050c0 */

void __cdecl FUN_004050c0(int param_1)

{
  undefined *UNRECOVERED_JUMPTABLE;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  puStack_c = &DAT_0041f298;
  puStack_10 = &LAB_00407548;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  if ((param_1 != 0) &&
     (UNRECOVERED_JUMPTABLE = *(undefined **)(*(int *)(param_1 + 0x1c) + 4),
     UNRECOVERED_JUMPTABLE != (undefined *)0x0)) {
    local_8 = 0;
    FUN_004027b0(*(undefined4 *)(param_1 + 0x18),UNRECOVERED_JUMPTABLE);
  }
  *unaff_FS_OFFSET = local_14;
  return;
}



/* VA 00405140 */

int __cdecl FUN_00405140(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;

  iVar2 = param_1 + *param_2;
  iVar1 = param_2[1];
  if (-1 < iVar1) {
    iVar2 = iVar2 + *(int *)(*(int *)(param_1 + iVar1) + param_2[2]) + iVar1;
  }
  return iVar2;
}



/* VA 00405170 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12

   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;

  pcVar1 = (code *)__NLG_Notify1(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  __NLG_Notify1(param_3);
  return;
}



/* VA 004051c0 */

undefined4 FUN_004051c0(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;

  FUN_00406010();
  DAT_00423aa0 = TlsAlloc();
  if (DAT_00423aa0 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_00404230(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_00423aa0,lpTlsValue);
      if (BVar1 != 0) {
        FUN_00405220((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        *lpTlsValue = DVar2;
        lpTlsValue[1] = 0xffffffff;
        return 1;
      }
    }
  }
  return 0;
}



/* VA 00405220 */

void __cdecl FUN_00405220(int param_1)

{
  *(undefined **)(param_1 + 0x50) = &DAT_00425ba0;
  *(undefined4 *)(param_1 + 0x14) = 1;
  return;
}



/* VA 00405240 */

DWORD * FUN_00405240(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;

  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_00423aa0);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)FUN_00404230(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_00423aa0,lpTlsValue);
      if (BVar1 != 0) {
        FUN_00405220((int)lpTlsValue);
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



/* VA 004052c0 */

void FUN_004052c0(void)

{
  DWORD *pDVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  puStack_c = &DAT_0041f2a8;
  puStack_10 = &LAB_00407548;
  uStack_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_14;
  local_8 = 0;
  pDVar1 = FUN_00405240();
  if (pDVar1[0x18] != 0) {
    local_8 = 1;
    pDVar1 = FUN_00405240();
    (*(code *)pDVar1[0x18])();
  }
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* VA 00405337 */

void __cdecl _abort(void)

{
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* VA 00405350 */

void FUN_00405350(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;

  puStack_c = &DAT_0041f2c0;
  puStack_10 = &LAB_00407548;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  if (PTR_FUN_00423aa4 != (undefined *)0x0) {
    local_8 = 1;
    (*(code *)PTR_FUN_00423aa4)();
  }
  local_8 = 0xffffffff;
  FUN_004053be();
  *unaff_FS_OFFSET = local_14;
  return;
}



/* VA 004053be */

void FUN_004053be(void)

{
  FUN_004052c0();
  return;
}



/* VA 004053e0 */

uint __cdecl FUN_004053e0(uint param_1,int *param_2)

{
  uint uVar1;
  char *pcVar2;
  int *piVar3;
  byte bVar4;
  undefined3 extraout_var;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;

  piVar3 = param_2;
  uVar7 = param_2[3];
  uVar1 = param_2[4];
  if (((uVar7 & 0x82) == 0) || ((uVar7 & 0x40) != 0)) {
LAB_00405503:
    param_2[3] = uVar7 | 0x20;
    return 0xffffffff;
  }
  uVar6 = 0;
  if ((uVar7 & 1) != 0) {
    param_2[1] = 0;
    if ((uVar7 & 0x10) == 0) goto LAB_00405503;
    *param_2 = param_2[2];
    param_2[3] = uVar7 & 0xfffffffe;
  }
  uVar7 = param_2[3];
  param_2[1] = 0;
  param_2[3] = uVar7 & 0xffffffef | 2;
  if ((uVar7 & 0x10c) == 0) {
    if ((param_2 == (int *)&DAT_004261b0) || (param_2 == (int *)&DAT_004261d0)) {
      bVar4 = FUN_00408420(uVar1);
      if (CONCAT31(extraout_var,bVar4) != 0) goto LAB_00405453;
    }
    FUN_004083c0(piVar3);
  }
LAB_00405453:
  if ((piVar3[3] & 0x108U) == 0) {
    uVar7 = 1;
    uVar6 = FUN_00408130(uVar1,(char *)&param_1,1);
  }
  else {
    pcVar2 = (char *)piVar3[2];
    uVar7 = *piVar3 - (int)pcVar2;
    *piVar3 = (int)(pcVar2 + 1);
    piVar3[1] = piVar3[6] + -1;
    if ((int)uVar7 < 1) {
      if (uVar1 == 0xffffffff) {
        puVar5 = &DAT_00425c28;
      }
      else {
        puVar5 = (undefined *)((&DAT_0042a0c0)[(int)uVar1 >> 5] + (uVar1 & 0x1f) * 0x24);
      }
      if ((puVar5[4] & 0x20) != 0) {
        FUN_00408030(uVar1,0,2);
      }
      *(undefined1 *)piVar3[2] = (undefined1)param_1;
    }
    else {
      uVar6 = FUN_00408130(uVar1,pcVar2,uVar7);
      *(undefined1 *)piVar3[2] = (undefined1)param_1;
    }
  }
  if (uVar6 != uVar7) {
    piVar3[3] = piVar3[3] | 0x20;
    return 0xffffffff;
  }
  return param_1 & 0xff;
}



/* VA 00405510 */

int __cdecl FUN_00405510(int *param_1,char *param_2,undefined4 *param_3)

{
  WCHAR WVar1;
  uint uVar2;
  short *psVar3;
  int *piVar4;
  undefined4 uVar5;
  WCHAR *pWVar6;
  int iVar7;
  char cVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  char *pcVar11;
  int iVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  longlong lVar15;
  uint uVar16;
  uint local_24c;
  WCHAR *local_248;
  int local_244;
  int local_240;
  char local_23a;
  char local_239;
  int local_238;
  int local_234;
  int local_230;
  uint local_22c;
  int local_228;
  int local_224;
  int local_220;
  uint local_21c;
  undefined4 local_218;
  CHAR local_214 [4];
  undefined4 local_210;
  undefined4 local_20c;
  uint local_204;
  undefined1 local_200 [511];
  undefined1 uStack_1;

  local_220 = 0;
  puVar10 = (undefined1 *)0x0;
  local_240 = 0;
  cVar8 = *param_2;
  local_21c = CONCAT31(local_21c._1_3_,cVar8);
  pcVar11 = param_2;
  do {
    if ((cVar8 == '\0') || (param_2 = pcVar11 + 1, local_240 < 0)) {
      return local_240;
    }
    if ((cVar8 < ' ') || ('x' < cVar8)) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(byte *)((int)&PTR_LAB_0041f2b8 + (int)cVar8) & 0xf;
    }
    local_220 = (int)(char)(&DAT_0041f2d8)[uVar2 * 8 + local_220] >> 4;
    switch(local_220) {
    case 0:
switchD_0040558d_caseD_0:
      local_230 = 0;
      if ((PTR_DAT_00425ce0[(local_21c & 0xff) * 2 + 1] & 0x80) != 0) {
        FUN_00405ea0((int)cVar8,param_1,&local_240);
        cVar8 = *param_2;
        param_2 = pcVar11 + 2;
      }
      FUN_00405ea0((int)cVar8,param_1,&local_240);
      break;
    case 1:
      local_218 = 0;
      local_228 = 0;
      local_234 = 0;
      local_238 = 0;
      local_24c = 0;
      local_244 = -1;
      local_230 = 0;
      break;
    case 2:
      switch(cVar8) {
      case ' ':
        local_24c = local_24c | 2;
        break;
      case '#':
        local_24c = local_24c | 0x80;
        break;
      case '+':
        local_24c = local_24c | 1;
        break;
      case '-':
        local_24c = local_24c | 4;
        break;
      case '0':
        local_24c = local_24c | 8;
      }
      break;
    case 3:
      if (cVar8 == '*') {
        local_234 = FUN_00405f70((int *)&param_3);
        if (local_234 < 0) {
          local_24c = local_24c | 4;
          local_234 = -local_234;
        }
      }
      else {
        local_234 = cVar8 + -0x30 + local_234 * 10;
      }
      break;
    case 4:
      local_244 = 0;
      break;
    case 5:
      if (cVar8 == '*') {
        local_244 = FUN_00405f70((int *)&param_3);
        if (local_244 < 0) {
          local_244 = -1;
        }
      }
      else {
        local_244 = cVar8 + -0x30 + local_244 * 10;
      }
      break;
    case 6:
      switch(cVar8) {
      case 'I':
        if ((*param_2 != '6') || (pcVar11[2] != '4')) {
          local_220 = 0;
          goto switchD_0040558d_caseD_0;
        }
        param_2 = pcVar11 + 3;
        local_24c = local_24c | 0x8000;
        break;
      case 'h':
        local_24c = local_24c | 0x20;
        break;
      case 'l':
        local_24c = local_24c | 0x10;
        break;
      case 'w':
        local_24c = local_24c | 0x800;
      }
      break;
    case 7:
      switch(cVar8) {
      case 'C':
        if ((local_24c & 0x830) == 0) {
          local_24c = local_24c | 0x800;
        }
      case 'c':
        if ((local_24c & 0x810) == 0) {
          uVar5 = FUN_00405f70((int *)&param_3);
          local_200[0] = (char)uVar5;
          puVar10 = (undefined1 *)0x1;
        }
        else {
          uVar5 = FUN_00405fb0(&param_3);
          puVar10 = (undefined1 *)FUN_00408530(local_200,(WCHAR)uVar5);
          if ((int)puVar10 < 0) {
            local_248 = (WCHAR *)local_200;
            local_228 = 1;
            break;
          }
        }
        local_248 = (WCHAR *)local_200;
        break;
      case 'E':
      case 'G':
        local_218 = 1;
        cVar8 = cVar8 + ' ';
      case 'e':
      case 'f':
      case 'g':
        local_248 = (WCHAR *)local_200;
        if (local_244 < 0) {
          local_244 = 6;
        }
        else if ((local_244 == 0) && (cVar8 == 'g')) {
          local_244 = 1;
        }
        local_210 = *param_3;
        local_20c = param_3[1];
        param_3 = param_3 + 2;
        (*(code *)PTR_FUN_00426410)(&local_210,local_200,(int)cVar8,local_244,local_218);
        if (((local_24c & 0x80) != 0) && (local_244 == 0)) {
          (*(code *)PTR_FUN_0042641c)(local_200);
        }
        if ((cVar8 == 'g') && ((local_24c & 0x80) == 0)) {
          (*(code *)PTR_FUN_00426414)(local_200);
        }
        uVar2 = local_24c | 0x40;
        if (local_200[0] == '-') {
          local_248 = (WCHAR *)(local_200 + 1);
          uVar2 = local_24c | 0x140;
        }
        local_24c = uVar2;
        uVar2 = 0xffffffff;
        pWVar6 = local_248;
        do {
          if (uVar2 == 0) break;
          uVar2 = uVar2 - 1;
          WVar1 = *pWVar6;
          pWVar6 = (WCHAR *)((int)pWVar6 + 1);
        } while ((char)WVar1 != '\0');
        puVar10 = (undefined1 *)(~uVar2 - 1);
        break;
      case 'S':
        if ((local_24c & 0x830) == 0) {
          local_24c = local_24c | 0x800;
        }
      case 's':
        iVar12 = 0x7fffffff;
        if (local_244 != -1) {
          iVar12 = local_244;
        }
        local_248 = (WCHAR *)FUN_00405f70((int *)&param_3);
        if ((local_24c & 0x810) == 0) {
          pWVar6 = local_248;
          if (local_248 == (WCHAR *)0x0) {
            pWVar6 = (WCHAR *)PTR_DAT_00423aa8;
            local_248 = (WCHAR *)PTR_DAT_00423aa8;
          }
          for (; (iVar12 != 0 && (iVar12 = iVar12 + -1, (char)*pWVar6 != '\0'));
              pWVar6 = (WCHAR *)((int)pWVar6 + 1)) {
          }
          puVar10 = (undefined1 *)((int)pWVar6 - (int)local_248);
        }
        else {
          if (local_248 == (WCHAR *)0x0) {
            local_248 = (WCHAR *)PTR_DAT_00423aac;
          }
          local_230 = 1;
          for (pWVar6 = local_248; (iVar12 != 0 && (iVar12 = iVar12 + -1, *pWVar6 != L'\0'));
              pWVar6 = pWVar6 + 1) {
          }
          puVar10 = (undefined1 *)((int)pWVar6 - (int)local_248 >> 1);
        }
        break;
      case 'X':
        goto switchD_004057a1_caseD_58;
      case 'Z':
        psVar3 = (short *)FUN_00405f70((int *)&param_3);
        if ((psVar3 == (short *)0x0) ||
           (local_248 = *(WCHAR **)(psVar3 + 2), local_248 == (WCHAR *)0x0)) {
          uVar2 = 0xffffffff;
          local_248 = (WCHAR *)PTR_DAT_00423aa8;
          pcVar11 = PTR_DAT_00423aa8;
          do {
            if (uVar2 == 0) break;
            uVar2 = uVar2 - 1;
            cVar8 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar8 != '\0');
          puVar10 = (undefined1 *)(~uVar2 - 1);
        }
        else if ((local_24c & 0x800) == 0) {
          puVar10 = (undefined1 *)(int)*psVar3;
          local_230 = 0;
        }
        else {
          local_230 = 1;
          puVar10 = (undefined1 *)((uint)(int)*psVar3 >> 1);
        }
        break;
      case 'd':
      case 'i':
        local_22c = 10;
        local_24c = local_24c | 0x40;
        goto LAB_00405ad7;
      case 'n':
        piVar4 = (int *)FUN_00405f70((int *)&param_3);
        if ((local_24c & 0x20) == 0) {
          local_228 = 1;
          *piVar4 = local_240;
        }
        else {
          local_228 = 1;
          *(undefined2 *)piVar4 = (undefined2)local_240;
        }
        break;
      case 'o':
        local_22c = 8;
        if ((local_24c & 0x80) != 0) {
          local_24c = local_24c | 0x200;
        }
        goto LAB_00405ad7;
      case 'p':
        local_244 = 8;
switchD_004057a1_caseD_58:
        local_224 = 7;
LAB_00405a92:
        local_22c = 0x10;
        if ((local_24c & 0x80) != 0) {
          local_23a = '0';
          local_239 = (char)local_224 + 'Q';
          local_238 = 2;
        }
        goto LAB_00405ad7;
      case 'u':
        local_22c = 10;
LAB_00405ad7:
        if ((local_24c & 0x8000) == 0) {
          if ((local_24c & 0x20) == 0) {
            if ((local_24c & 0x40) == 0) {
              uVar2 = FUN_00405f70((int *)&param_3);
              uVar13 = (ulonglong)uVar2;
            }
            else {
              iVar12 = FUN_00405f70((int *)&param_3);
              uVar13 = (ulonglong)iVar12;
            }
          }
          else if ((local_24c & 0x40) == 0) {
            uVar2 = FUN_00405f70((int *)&param_3);
            uVar13 = (ulonglong)uVar2 & 0xffffffff0000ffff;
          }
          else {
            uVar5 = FUN_00405f70((int *)&param_3);
            uVar13 = (ulonglong)(int)(short)uVar5;
          }
        }
        else {
          uVar13 = FUN_00405f90((int *)&param_3);
        }
        iVar12 = (int)(uVar13 >> 0x20);
        if ((((local_24c & 0x40) != 0) && (iVar12 == 0 || (longlong)uVar13 < 0)) &&
           ((longlong)uVar13 < 0)) {
          local_24c = local_24c | 0x100;
          uVar13 = CONCAT44(-(iVar12 + (uint)((int)uVar13 != 0)),-(int)uVar13);
        }
        iVar12 = (int)(uVar13 >> 0x20);
        if ((local_24c & 0x8000) == 0) {
          iVar12 = 0;
        }
        lVar15 = CONCAT44(iVar12,(int)uVar13);
        if (local_244 < 0) {
          local_244 = 1;
        }
        else {
          local_24c = local_24c & 0xfffffff7;
        }
        local_248 = (WCHAR *)register0x00000010;
        if ((int)uVar13 == 0 && iVar12 == 0) {
          local_238 = 0;
        }
        while( true ) {
          uVar2 = local_22c;
          pWVar6 = (WCHAR *)((int)local_248 + -1);
          iVar12 = local_244 + -1;
          if ((local_244 < 1) && (lVar15 == 0)) break;
          local_204 = (int)local_22c >> 0x1f;
          uVar16 = (uint)((ulonglong)lVar15 >> 0x20);
          uVar14 = __aullrem((uint)lVar15,uVar16,local_22c,local_204);
          iVar7 = (int)uVar14 + 0x30;
          lVar15 = __aulldiv((uint)lVar15,uVar16,uVar2,local_204);
          if (0x39 < iVar7) {
            iVar7 = iVar7 + local_224;
          }
          *(char *)pWVar6 = (char)iVar7;
          local_244 = iVar12;
          local_248 = pWVar6;
        }
        puVar10 = &uStack_1 + -(int)pWVar6;
        local_244 = iVar12;
        if (((local_24c & 0x200) != 0) &&
           (((char)*local_248 != '0' || (puVar10 == (undefined1 *)0x0)))) {
          puVar10 = &stack0x00000000 + -(int)pWVar6;
          *(char *)pWVar6 = '0';
          local_248 = pWVar6;
        }
        break;
      case 'x':
        local_224 = 0x27;
        goto LAB_00405a92;
      }
      if (local_228 == 0) {
        if ((local_24c & 0x40) != 0) {
          if ((local_24c & 0x100) == 0) {
            if ((local_24c & 1) == 0) {
              if ((local_24c & 2) == 0) goto LAB_00405c6f;
              local_23a = ' ';
            }
            else {
              local_23a = '+';
            }
          }
          else {
            local_23a = '-';
          }
          local_238 = 1;
        }
LAB_00405c6f:
        iVar12 = (local_234 - (int)puVar10) - local_238;
        if ((local_24c & 0xc) == 0) {
          FUN_00405ef0(0x20,iVar12,param_1,&local_240);
        }
        FUN_00405f30(&local_23a,local_238,param_1,&local_240);
        if (((local_24c & 8) != 0) && ((local_24c & 4) == 0)) {
          FUN_00405ef0(0x30,iVar12,param_1,&local_240);
        }
        if ((local_230 == 0) || (pWVar6 = local_248, puVar9 = puVar10, (int)puVar10 < 1)) {
          FUN_00405f30((char *)local_248,(int)puVar10,param_1,&local_240);
        }
        else {
          do {
            puVar9 = puVar9 + -1;
            iVar7 = FUN_00408530(local_214,*pWVar6);
            if (iVar7 < 1) break;
            FUN_00405f30(local_214,iVar7,param_1,&local_240);
            pWVar6 = pWVar6 + 1;
          } while (puVar9 != (undefined1 *)0x0);
        }
        if ((local_24c & 4) != 0) {
          FUN_00405ef0(0x20,iVar12,param_1,&local_240);
        }
      }
    }
    cVar8 = *param_2;
    local_21c = CONCAT31(local_21c._1_3_,cVar8);
    pcVar11 = param_2;
  } while( true );
}



/* VA 00405ea0 */

void __cdecl FUN_00405ea0(uint param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;

  iVar1 = param_2[1];
  param_2[1] = iVar1 + -1;
  if (iVar1 + -1 < 0) {
    uVar2 = FUN_004053e0(param_1,param_2);
  }
  else {
    *(char *)*param_2 = (char)param_1;
    uVar2 = param_1 & 0xff;
    *param_2 = *param_2 + 1;
  }
  if (uVar2 == 0xffffffff) {
    *param_3 = -1;
    return;
  }
  *param_3 = *param_3 + 1;
  return;
}



/* VA 00405ef0 */

void __cdecl FUN_00405ef0(uint param_1,int param_2,int *param_3,int *param_4)

{
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    FUN_00405ea0(param_1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}



/* VA 00405f30 */

void __cdecl FUN_00405f30(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;

  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_00405ea0((int)cVar1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}



/* VA 00405f70 */

undefined4 __cdecl FUN_00405f70(int *param_1)

{
  undefined4 *puVar1;

  puVar1 = (undefined4 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}



/* VA 00405f90 */

undefined8 __cdecl FUN_00405f90(int *param_1)

{
  undefined8 *puVar1;

  puVar1 = (undefined8 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}



/* VA 00405fb0 */

undefined4 __cdecl FUN_00405fb0(undefined4 *param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;

  puVar1 = (undefined2 *)*param_1;
  puVar2 = puVar1 + 2;
  *param_1 = puVar2;
  return CONCAT22((short)((uint)puVar2 >> 0x10),*puVar1);
}



/* VA 00405fd0 */

undefined4 FUN_00405fd0(void)

{
  undefined **ppuVar1;

  DAT_0042a1c4 = HeapCreate(0,0x1000,0);
  if (DAT_0042a1c4 == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = FUN_004061c0();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_0042a1c4);
    return 0;
  }
  return 1;
}



/* VA 00406010 */

void FUN_00406010(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_00423afc);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_00423aec);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_00423adc);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_00423abc);
  return;
}



/* VA 00406040 */

void __cdecl FUN_00406040(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;

  if (*(int *)(&DAT_00423ab8 + param_1 * 4) == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)FUN_00402cf0(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_00406040(0x11);
    if (*(int *)(&DAT_00423ab8 + param_1 * 4) == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *(LPCRITICAL_SECTION *)(&DAT_00423ab8 + param_1 * 4) = lpCriticalSection;
    }
    else {
      FUN_00402c80((undefined *)lpCriticalSection);
    }
    FUN_004060c0(0x11);
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)(&DAT_00423ab8 + param_1 * 4));
  return;
}



/* VA 004060c0 */

void __cdecl FUN_004060c0(int param_1)

{
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(&DAT_00423ab8 + param_1 * 4));
  return;
}



/* VA 004060e0 */

void __cdecl FUN_004060e0(uint param_1)

{
  if ((0x42618f < param_1) && (param_1 < 0x4263f1)) {
    FUN_00406040(((int)(param_1 - 0x426190) >> 5) + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



/* VA 00406120 */

void __cdecl FUN_00406120(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_00406040(param_1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



/* VA 00406150 */

void __cdecl FUN_00406150(uint param_1)

{
  if ((0x42618f < param_1) && (param_1 < 0x4263f1)) {
    FUN_004060c0(((int)(param_1 - 0x426190) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}



/* VA 00406190 */

void __cdecl FUN_00406190(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_004060c0(param_1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}



/* VA 004061c0 */

undefined ** FUN_004061c0(void)

{
  bool bVar1;
  undefined4 *lpAddress;
  LPVOID pvVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **lpMem;
  undefined4 *puVar5;

  if (DAT_00423b88 == -1) {
    lpMem = &PTR_LOOP_00423b78;
  }
  else {
    lpMem = HeapAlloc(DAT_0042a1c4,0,0x2020);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar2 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar2 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_00423b78) {
        if (PTR_LOOP_00423b78 == (undefined *)0x0) {
          PTR_LOOP_00423b78 = (undefined *)&PTR_LOOP_00423b78;
        }
        if (PTR_LOOP_00423b7c == (undefined *)0x0) {
          PTR_LOOP_00423b7c = (undefined *)&PTR_LOOP_00423b78;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_00423b78;
        lpMem[1] = PTR_LOOP_00423b7c;
        PTR_LOOP_00423b7c = (undefined *)lpMem;
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
  if (lpMem != &PTR_LOOP_00423b78) {
    HeapFree(DAT_0042a1c4,0,lpMem);
  }
  return (undefined **)0x0;
}



/* VA 00406330 */

void __cdecl FUN_00406330(undefined **param_1)

{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR_LOOP_00425b98 == param_1) {
    PTR_LOOP_00425b98 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_00423b78) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_0042a1c4,0,param_1);
    return;
  }
  DAT_00423b88 = 0xffffffff;
  return;
}



/* VA 00406390 */

void __cdecl FUN_00406390(int param_1)

{
  BOOL BVar1;
  undefined **ppuVar2;
  int iVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;

  ppuVar6 = (undefined **)PTR_LOOP_00423b7c;
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
            DAT_00428de0 = DAT_00428de0 + -1;
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
          FUN_00406330(ppuVar6);
        }
      }
    }
    if ((ppuVar5 == (undefined **)PTR_LOOP_00423b7c) || (ppuVar6 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}



/* VA 00406460 */

int __cdecl FUN_00406460(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined **ppuVar1;
  uint uVar2;

  ppuVar1 = &PTR_LOOP_00423b78;
  while ((param_1 <= ppuVar1[4] || (ppuVar1[5] <= param_1))) {
    ppuVar1 = (undefined **)*ppuVar1;
    if (ppuVar1 == &PTR_LOOP_00423b78) {
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



/* VA 004064c0 */

void __cdecl FUN_004064c0(int param_1,int param_2,byte *param_3)

{
  int *piVar1;
  int iVar2;

  iVar2 = param_2 - *(int *)(param_1 + 0x10) >> 0xc;
  piVar1 = (int *)(param_1 + 0x18 + iVar2 * 8);
  *piVar1 = *(int *)(param_1 + 0x18 + iVar2 * 8) + (uint)*param_3;
  *param_3 = 0;
  piVar1[1] = 0xf1;
  if ((*piVar1 == 0xf0) && (DAT_00428de0 = DAT_00428de0 + 1, DAT_00428de0 == 0x20)) {
    FUN_00406390(0x10);
  }
  return;
}



/* VA 00406520 */

int * __cdecl FUN_00406520(uint param_1)

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

  piVar11 = (int *)PTR_LOOP_00425b98;
  do {
    if (piVar11[4] != -1) {
      puVar10 = (uint *)piVar11[2];
      piVar8 = (int *)(((int)puVar10 + (-0x18 - (int)piVar11) >> 3) * 0x1000 + piVar11[4]);
      for (; puVar10 < piVar11 + 0x806; puVar10 = puVar10 + 2) {
        if (((int)param_1 <= (int)*puVar10) && (param_1 < puVar10[1])) {
          piVar5 = (int *)FUN_00406760(piVar8,*puVar10,param_1);
          if (piVar5 != (int *)0x0) {
            PTR_LOOP_00425b98 = (undefined *)piVar11;
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
          piVar5 = (int *)FUN_00406760(piVar8,*puVar10,param_1);
          if (piVar5 != (int *)0x0) {
            PTR_LOOP_00425b98 = (undefined *)piVar11;
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
  } while (piVar11 != (int *)PTR_LOOP_00425b98);
  ppuVar7 = &PTR_LOOP_00423b78;
  while ((ppuVar7[4] == (undefined *)0xffffffff || (ppuVar7[3] == (undefined *)0x0))) {
    ppuVar7 = (undefined **)*ppuVar7;
    if (ppuVar7 == &PTR_LOOP_00423b78) {
      ppuVar7 = FUN_004061c0();
      if (ppuVar7 == (undefined **)0x0) {
        return (int *)0x0;
      }
      piVar11 = (int *)ppuVar7[4];
      *(char *)(piVar11 + 2) = (char)param_1;
      PTR_LOOP_00425b98 = (undefined *)ppuVar7;
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
  PTR_LOOP_00425b98 = (undefined *)ppuVar7;
  ppuVar7[3] = (undefined *)(-(uint)bVar12 & (uint)ppuVar6);
  *(char *)(piVar11 + 2) = (char)param_1;
  ppuVar7[2] = (undefined *)ppuVar3;
  *ppuVar3 = *ppuVar3 + -param_1;
  piVar11[1] = piVar11[1] - param_1;
  *piVar11 = (int)piVar11 + param_1 + 8;
  return piVar11 + 0x40;
}



/* VA 00406760 */

int __cdecl FUN_00406760(int *param_1,uint param_2,uint param_3)

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
            goto LAB_004068af;
          }
          *param_1 = (int)(pbVar6 + param_3);
          param_1[1] = uVar5 - param_3;
          goto LAB_004068b6;
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
LAB_004068af:
            param_1[1] = 0;
          }
LAB_004068b6:
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



/* VA 004068e0 */

undefined4 __cdecl FUN_004068e0(int param_1,int *param_2,byte *param_3,uint param_4)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;

  uVar5 = 0;
  piVar3 = (int *)(param_1 + 0x18 + ((int)param_2 - *(int *)(param_1 + 0x10) >> 0xc) * 8);
  uVar7 = (uint)*param_3;
  if (uVar7 <= param_4) {
    if ((uVar7 < param_4) && (pbVar1 = param_3 + param_4, pbVar1 <= param_2 + 0x3e)) {
      for (pbVar8 = param_3 + uVar7; (pbVar8 < pbVar1 && (*pbVar8 == 0)); pbVar8 = pbVar8 + 1) {
      }
      if (pbVar8 == pbVar1) {
        *param_3 = (byte)param_4;
        if ((param_3 <= (byte *)*param_2) && ((byte *)*param_2 < pbVar1)) {
          if (pbVar1 < param_2 + 0x3e) {
            *param_2 = (int)pbVar1;
            iVar6 = 0;
            bVar4 = *pbVar1;
            while (bVar4 == 0) {
              iVar2 = iVar6 + 1;
              iVar6 = iVar6 + 1;
              bVar4 = pbVar1[iVar2];
            }
            param_2[1] = iVar6;
          }
          else {
            param_2[1] = 0;
            *param_2 = (int)(param_2 + 2);
          }
        }
        *piVar3 = *piVar3 + (uVar7 - param_4);
        uVar5 = 1;
      }
    }
    return uVar5;
  }
  *param_3 = (byte)param_4;
  piVar3[1] = 0xf1;
  *piVar3 = *piVar3 + (uVar7 - param_4);
  return 1;
}



/* VA 004069b0 */

undefined4 __cdecl FUN_004069b0(undefined4 param_1)

{
  int iVar1;

  if (DAT_00428de8 != (code *)0x0) {
    iVar1 = (*DAT_00428de8)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



/* VA 004069d0 */

int * __cdecl FUN_004069d0(int *param_1,uint param_2)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int *local_8;
  int local_4;

  if (param_1 == (int *)0x0) {
    piVar1 = (int *)FUN_00402cf0(param_2);
    return piVar1;
  }
  if (param_2 == 0) {
    FUN_00402c80((undefined *)param_1);
    return (int *)0x0;
  }
  uVar4 = param_2;
  if (param_2 < 0xffffffe1) {
    if (param_2 == 0) {
      param_2 = 0x10;
      uVar4 = param_2;
    }
    else {
      param_2 = param_2 + 0xf & 0xfffffff0;
      uVar4 = param_2;
    }
  }
  do {
    piVar1 = (int *)0x0;
    if (uVar4 < 0xffffffe1) {
      FUN_00406040(9);
      pbVar2 = (byte *)FUN_00406460((undefined *)param_1,&local_4,(uint *)&local_8);
      if (pbVar2 == (byte *)0x0) {
        FUN_004060c0(9);
        piVar1 = HeapReAlloc(DAT_0042a1c4,0,param_1,uVar4);
      }
      else {
        if (uVar4 < DAT_00425b9c) {
          iVar3 = FUN_004068e0(local_4,local_8,pbVar2,uVar4 >> 4);
          piVar1 = param_1;
          if (iVar3 != 0) goto LAB_00406ad5;
          piVar1 = FUN_00406520(uVar4 >> 4);
          if (piVar1 != (int *)0x0) {
            uVar5 = (uint)*pbVar2 << 4;
            if (uVar4 <= (uint)*pbVar2 << 4) {
              uVar5 = uVar4;
            }
            piVar6 = param_1;
            piVar7 = piVar1;
            for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
              *piVar7 = *piVar6;
              piVar6 = piVar6 + 1;
              piVar7 = piVar7 + 1;
            }
            for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(char *)piVar7 = (char)*piVar6;
              piVar6 = (int *)((int)piVar6 + 1);
              piVar7 = (int *)((int)piVar7 + 1);
            }
            FUN_004064c0(local_4,(int)local_8,pbVar2);
            uVar4 = param_2;
            goto LAB_00406ad5;
          }
LAB_00406ad9:
          piVar1 = HeapAlloc(DAT_0042a1c4,0,uVar4);
          if (piVar1 != (int *)0x0) {
            uVar5 = (uint)*pbVar2 << 4;
            if (uVar4 <= (uint)*pbVar2 << 4) {
              uVar5 = uVar4;
            }
            piVar6 = param_1;
            piVar7 = piVar1;
            for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
              *piVar7 = *piVar6;
              piVar6 = piVar6 + 1;
              piVar7 = piVar7 + 1;
            }
            for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(char *)piVar7 = (char)*piVar6;
              piVar6 = (int *)((int)piVar6 + 1);
              piVar7 = (int *)((int)piVar7 + 1);
            }
            FUN_004064c0(local_4,(int)local_8,pbVar2);
            uVar4 = param_2;
          }
        }
        else {
LAB_00406ad5:
          if (piVar1 == (int *)0x0) goto LAB_00406ad9;
        }
        FUN_004060c0(9);
      }
    }
    if ((piVar1 != (int *)0x0) || (DAT_00428de4 == 0)) {
      return piVar1;
    }
    iVar3 = FUN_004069b0(uVar4);
    if (iVar3 == 0) {
      return (int *)0x0;
    }
  } while( true );
}



/* VA 00406dd0 */

void __cdecl FUN_00406dd0(uint param_1)

{
  FUN_00406df0(param_1,0,4);
  return;
}



/* VA 00406df0 */

undefined4 __cdecl FUN_00406df0(uint param_1,uint param_2,byte param_3)

{
  uint uVar1;

  if ((*(byte *)((int)&DAT_00428c18 + (param_1 & 0xff) + 1) & param_3) == 0) {
    if (param_2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(ushort *)(&DAT_00425cea + (param_1 & 0xff) * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}



/* VA 00406e30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406e30(void)

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
  cVar2 = *DAT_00428bc8;
  pcVar7 = DAT_00428bc8;
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
  piVar3 = (int *)FUN_00402cf0(iVar8 * 4 + 4);
  _DAT_00428bf4 = piVar3;
  if (piVar3 == (int *)0x0) {
    __amsg_exit(9);
  }
  cVar2 = *DAT_00428bc8;
  local_4 = piVar3;
  pcVar7 = DAT_00428bc8;
  do {
    if (cVar2 == '\0') {
      FUN_00402c80(DAT_00428bc8);
      DAT_00428bc8 = (char *)0x0;
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
      iVar8 = FUN_00402cf0(uVar4);
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



/* VA 00406f20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406f20(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_8;
  int local_4;

  GetModuleFileNameA((HMODULE)0x0,&DAT_00428df0,0x104);
  _DAT_00428c04 = &DAT_00428df0;
  pbVar2 = DAT_0042a1d4;
  if (*DAT_0042a1d4 == 0) {
    pbVar2 = &DAT_00428df0;
  }
  FUN_00406fc0(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = (undefined4 *)FUN_00402cf0(local_4 + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_00406fc0(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  DAT_00428bec = puVar1;
  DAT_00428be8 = local_8 + -1;
  return;
}



/* VA 00406fc0 */

void __cdecl FUN_00406fc0(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

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
      if (((*(byte *)((int)&DAT_00428c18 + bVar2 + 1) & 4) != 0) &&
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
      if ((*(byte *)((int)param_5 + 0x428c19) & 4) != 0) {
        *piVar6 = *piVar6 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar7;
          param_3 = param_3 + 1;
        }
        pbVar7 = param_1 + 2;
      }
      if (bVar2 == 0x20) break;
      if (bVar2 == 0) goto LAB_00407099;
      param_1 = pbVar7;
    } while (bVar2 != 9);
    if (bVar2 == 0) {
LAB_00407099:
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
          if ((*(byte *)((int)&DAT_00428c18 + bVar2 + 1) & 4) != 0) {
            pbVar7 = pbVar7 + 1;
            *piVar6 = *piVar6 + 1;
          }
          *piVar6 = *piVar6 + 1;
          goto LAB_00407195;
        }
        if ((*(byte *)((int)&DAT_00428c18 + bVar2 + 1) & 4) != 0) {
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
LAB_00407195:
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



/* VA 004071d0 */

LPSTR FUN_004071d0(void)

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
  if (DAT_00428ef8 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar10 = GetEnvironmentStrings();
      if (pCVar10 == (LPCH)0x0) {
        return (LPSTR)0x0;
      }
      DAT_00428ef8 = 2;
    }
    else {
      DAT_00428ef8 = 1;
    }
  }
  if (DAT_00428ef8 == 1) {
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
      if ((uVar6 != 0) && (pCVar7 = (LPSTR)FUN_00402cf0(uVar6), pCVar7 != (LPSTR)0x0)) {
        iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,pCVar7,uVar6,(LPCSTR)0x0,(LPBOOL)0x0);
        if (iVar5 == 0) {
          FUN_00402c80(pCVar7);
          pCVar7 = (LPSTR)0x0;
        }
        FreeEnvironmentStringsW(lpWideCharStr);
        return pCVar7;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return (LPSTR)0x0;
    }
  }
  else if ((DAT_00428ef8 == 2) &&
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
    pCVar7 = (LPSTR)FUN_00402cf0((uint)pCVar9);
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



/* VA 00407330 */

void FUN_00407330(void)

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

  puVar2 = (undefined4 *)FUN_00402cf0(0x480);
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_0042a1c0 = 0x20;
  DAT_0042a0c0 = puVar2;
  if (puVar2 < puVar2 + 0x120) {
    do {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar2[2] = 0;
      puVar2 = puVar2 + 9;
    } while (puVar2 < DAT_0042a0c0 + 0x120);
  }
  GetStartupInfoA(&local_44);
  if ((local_44.cbReserved2 != 0) && ((UINT *)local_44.lpReserved2 != (UINT *)0x0)) {
    local_48 = *(UINT *)local_44.lpReserved2;
    pUVar8 = (UINT *)((int)local_44.lpReserved2 + 4);
    pbVar4 = (byte *)((int)pUVar8 + local_48);
    if (0x7ff < (int)local_48) {
      local_48 = 0x800;
    }
    if ((int)DAT_0042a1c0 < (int)local_48) {
      piVar6 = &DAT_0042a0c4;
      do {
        puVar2 = (undefined4 *)FUN_00402cf0(0x480);
        if (puVar2 == (undefined4 *)0x0) {
          local_48 = DAT_0042a1c0;
          break;
        }
        *piVar6 = (int)puVar2;
        DAT_0042a1c0 = DAT_0042a1c0 + 0x20;
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
      } while ((int)DAT_0042a1c0 < (int)local_48);
    }
    uVar7 = 0;
    if (0 < (int)local_48) {
      do {
        if (((*(HANDLE *)pbVar4 != (HANDLE)0xffffffff) && ((*pUVar8 & 1) != 0)) &&
           (((*pUVar8 & 8) != 0 || (DVar3 = GetFileType(*(HANDLE *)pbVar4), DVar3 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_0042a0c0)[(int)uVar7 >> 5] + (uVar7 & 0x1f) * 0x24);
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
    puVar2 = DAT_0042a0c0 + iVar5 * 9;
    if (DAT_0042a0c0[iVar5 * 9] == -1) {
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
        goto LAB_0040751e;
      }
      *puVar2 = hFile;
      if ((DVar3 & 0xff) == 2) {
        bVar1 = *(byte *)(puVar2 + 1) | 0x40;
        goto LAB_0040751e;
      }
      if ((DVar3 & 0xff) == 3) {
        bVar1 = *(byte *)(puVar2 + 1) | 8;
        goto LAB_0040751e;
      }
    }
    else {
      bVar1 = *(byte *)(puVar2 + 1) | 0x80;
LAB_0040751e:
      *(byte *)(puVar2 + 1) = bVar1;
    }
    iVar5 = iVar5 + 1;
    if (2 < iVar5) {
      SetHandleCount(DAT_0042a1c0);
      return;
    }
  } while( true );
}



/* VA 00407605 */

void FUN_00407605(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}



/* VA 00407620 */

void FUN_00407620(void)

{
  if ((DAT_00428bd0 == 1) || ((DAT_00428bd0 == 0 && (DAT_00423754 == 1)))) {
    FUN_00407660((undefined *)0xfc);
    if (DAT_00428efc != (code *)0x0) {
      (*DAT_00428efc)();
    }
    FUN_00407660((undefined *)0xff);
  }
  return;
}



/* VA 00407660 */

void __cdecl FUN_00407660(undefined *param_1)

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

  ppuVar2 = (undefined **)&DAT_00425c50;
  iVar8 = 0;
  do {
    if (param_1 == *ppuVar2) break;
    ppuVar2 = ppuVar2 + 2;
    iVar8 = iVar8 + 1;
  } while (ppuVar2 < &PTR_DAT_00425ce0);
  if (param_1 == (undefined *)(&DAT_00425c50)[iVar8 * 2]) {
    if ((DAT_00428bd0 == 1) || ((DAT_00428bd0 == 0 && (DAT_00423754 == 1)))) {
      if ((DAT_0042a0c0 == 0) ||
         (hFile = *(HANDLE *)(DAT_0042a0c0 + 0x48), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar7 = *(char **)(iVar8 * 8 + 0x425c54);
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
      pcVar7 = *(char **)(iVar8 * 8 + 0x425c54);
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
      FUN_00408710(local_1a4,"Microsoft Visual C++ Runtime Library",0x12010);
      return;
    }
  }
  return;
}



/* VA 00407850 */

/* Library Function - Single Match
    _strchr

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strchr(char *_Str,int _Val)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;

  while (((uint)_Str & 3) != 0) {
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    _Str = (char *)((int)_Str + 1);
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      uVar1 = *(uint *)_Str;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11((char)_Val,(char)_Val),CONCAT11((char)_Val,(char)_Val));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = (uint *)((int)_Str + 4);
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      _Str = (char *)puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (char *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (char *)0x0;
        }
      }
    }
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 1);
    }
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 2);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 3);
    }
    _Str = (char *)puVar5;
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
  }
  return (char *)0x0;
}



/* VA 00407910 */

int FUN_00407910(int *param_1)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;

  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    FUN_004052c0();
    return 1;
  }
  if (DAT_00428f00 != (FARPROC)0x0) {
    bVar2 = FUN_00407ff0(DAT_00428f00);
    if (CONCAT31(extraout_var,bVar2) != 0) {
      iVar3 = (*DAT_00428f00)(param_1);
      return iVar3;
    }
  }
  return 0;
}



/* VA 004079a0 */

/* Library Function - Single Match
    _strpbrk

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strpbrk(char *_Str,char *_Control)

{
  byte bVar1;
  byte *pbVar2;
  byte abStack_28 [32];

  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *_Control;
    if (bVar1 == 0) break;
    _Control = _Control + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  do {
    pbVar2 = (byte *)_Str;
    bVar1 = *pbVar2;
    if (bVar1 == 0) {
      return (char *)0x0;
    }
    _Str = (char *)(pbVar2 + 1);
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return (char *)pbVar2;
}



/* VA 004079e0 */

int __cdecl
FUN_004079e0(LCID param_1,uint param_2,char *param_3,LPCWSTR param_4,LPWSTR param_5,int param_6,
            UINT param_7)

{
  int iVar1;
  LPCWSTR cbMultiByte;
  LPCWSTR lpWideCharStr;
  int iVar2;

  if (DAT_00428f08 == 0) {
    iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_00428f08 = 1;
    }
    else {
      DAT_00428f08 = 2;
    }
  }
  cbMultiByte = param_4;
  if (0 < (int)param_4) {
    cbMultiByte = (LPCWSTR)FUN_00407c00(param_3,(int)param_4);
  }
  if (DAT_00428f08 == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,(int)cbMultiByte,(LPSTR)param_5,param_6);
    return iVar1;
  }
  if (DAT_00428f08 != 1) {
    return DAT_00428f08;
  }
  param_4 = (LPCWSTR)0x0;
  if (param_7 == 0) {
    param_7 = DAT_00428f28;
  }
  iVar1 = MultiByteToWideChar(param_7,9,param_3,(int)cbMultiByte,(LPWSTR)0x0,0);
  if (iVar1 == 0) {
    return 0;
  }
  lpWideCharStr = (LPCWSTR)FUN_00402cf0(iVar1 * 2);
  if (lpWideCharStr == (LPCWSTR)0x0) {
    return 0;
  }
  iVar2 = MultiByteToWideChar(param_7,1,param_3,(int)cbMultiByte,lpWideCharStr,iVar1);
  if ((iVar2 != 0) &&
     (iVar2 = LCMapStringW(param_1,param_2,lpWideCharStr,iVar1,(LPWSTR)0x0,0), iVar2 != 0)) {
    if ((param_2 & 0x400) == 0) {
      param_4 = (LPCWSTR)FUN_00402cf0(iVar2 * 2);
      if ((param_4 == (LPCWSTR)0x0) ||
         (iVar1 = LCMapStringW(param_1,param_2,lpWideCharStr,iVar1,param_4,iVar2), iVar1 == 0))
      goto LAB_00407bdf;
      if (param_6 == 0) {
        iVar2 = WideCharToMultiByte(param_7,0x220,param_4,iVar2,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0
                                   );
        iVar1 = iVar2;
      }
      else {
        iVar2 = WideCharToMultiByte(param_7,0x220,param_4,iVar2,(LPSTR)param_5,param_6,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        iVar1 = iVar2;
      }
    }
    else {
      if (param_6 == 0) goto LAB_00407b44;
      if (param_6 < iVar2) goto LAB_00407bdf;
      iVar1 = LCMapStringW(param_1,param_2,lpWideCharStr,iVar1,param_5,param_6);
    }
    if (iVar1 != 0) {
LAB_00407b44:
      FUN_00402c80((undefined *)lpWideCharStr);
      FUN_00402c80((undefined *)param_4);
      return iVar2;
    }
  }
LAB_00407bdf:
  FUN_00402c80((undefined *)lpWideCharStr);
  FUN_00402c80((undefined *)param_4);
  return 0;
}



/* VA 00407c00 */

int __cdecl FUN_00407c00(char *param_1,int param_2)

{
  char *pcVar1;
  int iVar2;

  iVar2 = param_2;
  for (pcVar1 = param_1; (iVar2 != 0 && (iVar2 = iVar2 + -1, *pcVar1 != '\0')); pcVar1 = pcVar1 + 1)
  {
  }
  if (*pcVar1 != '\0') {
    return param_2;
  }
  return (int)pcVar1 - (int)param_1;
}



/* VA 00407c30 */

/* Library Function - Single Match
    __strrev

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl __strrev(char *_Str)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;

  iVar2 = -1;
  pcVar3 = _Str;
  do {
    pcVar4 = pcVar3;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar4;
  } while (cVar1 != '\0');
  if (iVar2 != -2) {
    pcVar4 = pcVar4 + -2;
    for (pcVar3 = _Str; pcVar3 < pcVar4; pcVar3 = pcVar3 + 1) {
      cVar1 = *pcVar3;
      *pcVar3 = *pcVar4;
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + -1;
    }
  }
  return _Str;
}



/* VA 00407c60 */

uint __cdecl FUN_00407c60(int param_1,uint param_2)

{
  int iVar1;
  BOOL BVar2;
  uint local_4;

  iVar1 = param_1;
  if (param_1 + 1U < 0x101) {
    return *(ushort *)(PTR_DAT_00425ce0 + param_1 * 2) & param_2;
  }
  if ((PTR_DAT_00425ce0[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
    param_1._0_2_ = (ushort)(byte)param_1;
    iVar1 = 1;
  }
  else {
    param_1._0_2_ = CONCAT11((byte)param_1,(char)((uint)param_1 >> 8));
    param_1._3_1_ = SUB41(iVar1,3);
    param_1._0_3_ = (uint3)(ushort)param_1;
    iVar1 = 2;
  }
  BVar2 = FUN_00408930(1,(LPCSTR)&param_1,iVar1,(LPWORD)&local_4,0,0);
  if (BVar2 == 0) {
    return 0;
  }
  return local_4 & 0xffff & param_2;
}



/* VA 00407d40 */

uint __cdecl FUN_00407d40(uint param_1)

{
  bool bVar1;

  if (DAT_00428f18 == 0) {
    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {
      return param_1 - 0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_0042a0a8);
    bVar1 = DAT_0042a0a4 != 0;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_0042a0a8);
      FUN_00406040(0x13);
    }
    param_1 = FUN_00407dd0(param_1);
    if (bVar1) {
      FUN_004060c0(0x13);
      return param_1;
    }
    InterlockedDecrement((LONG *)&DAT_0042a0a8);
  }
  return param_1;
}



/* VA 00407dd0 */

uint __cdecl FUN_00407dd0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  LPCWSTR pWVar3;
  int iVar4;
  uint local_8 [2];

  uVar1 = param_1;
  if (DAT_00428f18 == 0) {
    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {
      return param_1 - 0x20;
    }
  }
  else {
    if ((int)param_1 < 0x100) {
      if (DAT_00425eec < 2) {
        uVar2 = (byte)PTR_DAT_00425ce0[param_1 * 2] & 2;
      }
      else {
        uVar2 = FUN_00407c60(param_1,2);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    uVar2 = param_1;
    if ((PTR_DAT_00425ce0[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1._0_2_ = (ushort)(byte)uVar1;
      pWVar3 = (LPCWSTR)0x1;
    }
    else {
      param_1._0_2_ = CONCAT11((byte)uVar1,(char)(uVar1 >> 8));
      param_1._3_1_ = SUB41(uVar2,3);
      param_1._0_3_ = (uint3)(ushort)param_1;
      pWVar3 = (LPCWSTR)0x2;
    }
    iVar4 = FUN_004079e0(DAT_00428f18,0x200,(char *)&param_1,pWVar3,(LPWSTR)local_8,3,0);
    if (iVar4 == 0) {
      return uVar1;
    }
    if (iVar4 == 1) {
      return local_8[0] & 0xff;
    }
    param_1 = (local_8[0] >> 8 & 0xff) << 8 | local_8[0] & 0xff;
  }
  return param_1;
}



/* VA 00407ee0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_00407ee0(byte *param_1,byte *param_2)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  uint uVar8;
  uint uVar9;
  uint uVar7;

  iVar2 = _DAT_0042a0a8;
  if (DAT_00428f18 == 0) {
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_00407f2e;
        bVar5 = *param_2;
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar4 == bVar5);
      bVar3 = bVar5 + 0xbf + (-((byte)(bVar5 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar4 + 0xbf;
      bVar5 = bVar4 + (-(bVar4 < 0x1a) & 0x20U) + 0x41;
    } while (bVar5 == bVar3);
    cVar6 = (bVar5 < bVar3) * -2 + '\x01';
LAB_00407f2e:
    uVar7 = (uint)cVar6;
  }
  else {
    LOCK();
    _DAT_0042a0a8 = _DAT_0042a0a8 + 1;
    UNLOCK();
    bVar1 = 0 < DAT_0042a0a4;
    if (bVar1) {
      LOCK();
      UNLOCK();
      _DAT_0042a0a8 = iVar2;
      FUN_00406040(0x13);
    }
    uVar9 = (uint)bVar1;
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') goto LAB_00407f8f;
        bVar5 = *param_2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar5);
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),bVar4);
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      uVar8 = FUN_00409a00(uVar8);
      uVar7 = FUN_00409a00(uVar7);
    } while ((byte)uVar8 == (byte)uVar7);
    uVar8 = (uint)((byte)uVar8 < (byte)uVar7);
    uVar7 = (1 - uVar8) - (uint)(uVar8 != 0);
LAB_00407f8f:
    if (uVar9 == 0) {
      LOCK();
      _DAT_0042a0a8 = _DAT_0042a0a8 + -1;
      UNLOCK();
    }
    else {
      FUN_004060c0(0x13);
    }
  }
  return uVar7;
}



/* VA 00407fb0 */

bool __cdecl FUN_00407fb0(void *param_1,UINT_PTR param_2)

{
  BOOL BVar1;

  BVar1 = IsBadReadPtr(param_1,param_2);
  return BVar1 == 0;
}



/* VA 00407fd0 */

bool __cdecl FUN_00407fd0(LPVOID param_1,UINT_PTR param_2)

{
  BOOL BVar1;

  BVar1 = IsBadWritePtr(param_1,param_2);
  return BVar1 == 0;
}



/* VA 00407ff0 */

bool __cdecl FUN_00407ff0(FARPROC param_1)

{
  BOOL BVar1;

  BVar1 = IsBadCodePtr(param_1);
  return BVar1 == 0;
}



/* VA 00408010 */

/* Library Function - Single Match
    _abort

   Library: Visual Studio 1998 Release */

void __cdecl _abort(void)

{
  FUN_00407660((undefined *)0xa);
  FUN_00409b00((DWORD *)0x16);
                    /* WARNING: Subroutine does not return */
  __exit(3);
}



/* VA 00408030 */

DWORD __cdecl FUN_00408030(uint param_1,LONG param_2,DWORD param_3)

{
  DWORD DVar1;
  DWORD *pDVar2;

  if ((param_1 < DAT_0042a1c0) &&
     ((*(byte *)((&DAT_0042a0c0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_00409e40(param_1);
    DVar1 = FUN_004080b0(param_1,param_2,param_3);
    FUN_00409eb0(param_1);
    return DVar1;
  }
  pDVar2 = FUN_00404720();
  *pDVar2 = 9;
  pDVar2 = FUN_00404730();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* VA 004080b0 */

DWORD __cdecl FUN_004080b0(uint param_1,LONG param_2,DWORD param_3)

{
  HANDLE hFile;
  DWORD *pDVar1;
  DWORD DVar2;
  undefined *puVar3;

  hFile = (HANDLE)FUN_00409df0(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    pDVar1 = FUN_00404720();
    *pDVar1 = 9;
    return 0xffffffff;
  }
  DVar2 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
  if (DVar2 == 0xffffffff) {
    puVar3 = (undefined *)GetLastError();
  }
  else {
    puVar3 = (undefined *)0x0;
  }
  if (puVar3 != (undefined *)0x0) {
    FUN_004046a0(puVar3);
    return 0xffffffff;
  }
  *(byte *)((&DAT_0042a0c0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) =
       *(byte *)((&DAT_0042a0c0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0xfd;
  return DVar2;
}



/* VA 00408130 */

int __cdecl FUN_00408130(uint param_1,char *param_2,uint param_3)

{
  int iVar1;
  DWORD *pDVar2;

  if ((param_1 < DAT_0042a1c0) &&
     ((*(byte *)((&DAT_0042a0c0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_00409e40(param_1);
    iVar1 = FUN_004081b0(param_1,param_2,param_3);
    FUN_00409eb0(param_1);
    return iVar1;
  }
  pDVar2 = FUN_00404720();
  *pDVar2 = 9;
  pDVar2 = FUN_00404730();
  *pDVar2 = 0;
  return -1;
}



/* VA 004081b0 */

int __cdecl FUN_004081b0(uint param_1,char *param_2,uint param_3)

{
  int *piVar1;
  char cVar2;
  char *pcVar3;
  BOOL BVar4;
  DWORD *pDVar5;
  int iVar6;
  char *pcVar7;
  DWORD local_41c;
  undefined *local_414;
  DWORD local_410;
  int local_40c;
  int *local_408;
  char local_404 [1028];

  local_41c = 0;
  local_40c = 0;
  if (param_3 == 0) {
    return 0;
  }
  piVar1 = &DAT_0042a0c0 + ((int)param_1 >> 5);
  iVar6 = (param_1 & 0x1f) * 0x24;
  local_408 = piVar1;
  if ((*(byte *)(iVar6 + 4 + *piVar1) & 0x20) != 0) {
    FUN_004080b0(param_1,0,2);
  }
  if ((*(byte *)((undefined4 *)(*piVar1 + iVar6) + 1) & 0x80) == 0) {
    BVar4 = WriteFile(*(HANDLE *)(*piVar1 + iVar6),param_2,param_3,&local_410,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      local_414 = (undefined *)GetLastError();
    }
    else {
      local_41c = local_410;
      local_414 = (undefined *)0x0;
    }
  }
  else {
    local_414 = (undefined *)0x0;
    pcVar7 = param_2;
    if (param_3 != 0) {
      do {
        pcVar3 = local_404;
        do {
          if (param_3 <= (uint)((int)pcVar7 - (int)param_2)) break;
          cVar2 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          if (cVar2 == '\n') {
            *pcVar3 = '\r';
            local_40c = local_40c + 1;
            pcVar3 = pcVar3 + 1;
          }
          *pcVar3 = cVar2;
          pcVar3 = pcVar3 + 1;
        } while ((int)pcVar3 - (int)local_404 < 0x400);
        BVar4 = WriteFile(*(HANDLE *)(iVar6 + *local_408),local_404,(int)pcVar3 - (int)local_404,
                          &local_410,(LPOVERLAPPED)0x0);
        if (BVar4 == 0) {
          local_414 = (undefined *)GetLastError();
          break;
        }
        local_41c = local_41c + local_410;
        if (((int)local_410 < (int)pcVar3 - (int)local_404) ||
           (param_3 <= (uint)((int)pcVar7 - (int)param_2))) break;
      } while( true );
    }
  }
  if (local_41c != 0) {
    return local_41c - local_40c;
  }
  if (local_414 == (undefined *)0x0) {
    if (((*(byte *)(iVar6 + 4 + *local_408) & 0x40) != 0) && (*param_2 == '\x1a')) {
      return 0;
    }
    pDVar5 = FUN_00404720();
    *pDVar5 = 0x1c;
    pDVar5 = FUN_00404730();
    *pDVar5 = 0;
    return -1;
  }
  if (local_414 != (undefined *)0x5) {
    FUN_004046a0(local_414);
    return -1;
  }
  pDVar5 = FUN_00404720();
  *pDVar5 = 9;
  pDVar5 = FUN_00404730();
  *pDVar5 = 5;
  return -1;
}



/* VA 004083c0 */

void __cdecl FUN_004083c0(int *param_1)

{
  int iVar1;

  DAT_00428ff8 = DAT_00428ff8 + 1;
  iVar1 = FUN_00402cf0(0x1000);
  param_1[2] = iVar1;
  if (iVar1 != 0) {
    param_1[3] = param_1[3] | 8;
    param_1[6] = 0x1000;
    *param_1 = param_1[2];
    param_1[1] = 0;
    return;
  }
  param_1[6] = 2;
  param_1[3] = param_1[3] | 4;
  param_1[2] = (int)(param_1 + 5);
  *param_1 = (int)(param_1 + 5);
  param_1[1] = 0;
  return;
}



/* VA 00408420 */

byte __cdecl FUN_00408420(uint param_1)

{
  if (DAT_0042a1c0 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_0042a0c0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 0x40;
}



/* VA 00408530 */

int __cdecl FUN_00408530(LPSTR param_1,WCHAR param_2)

{
  int iVar1;
  bool bVar2;

  InterlockedIncrement((LONG *)&DAT_0042a0a8);
  bVar2 = DAT_0042a0a4 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_0042a0a8);
    FUN_00406040(0x13);
  }
  iVar1 = FUN_004085a0(param_1,param_2);
  if (!bVar2) {
    InterlockedDecrement((LONG *)&DAT_0042a0a8);
    return iVar1;
  }
  FUN_004060c0(0x13);
  return iVar1;
}



/* VA 004085a0 */

int __cdecl FUN_004085a0(LPSTR param_1,WCHAR param_2)

{
  LPSTR lpMultiByteStr;
  int iVar1;
  DWORD *pDVar2;

  lpMultiByteStr = param_1;
  if (param_1 == (LPSTR)0x0) {
    return 0;
  }
  if (DAT_00428f18 == 0) {
    if ((ushort)param_2 < 0x100) {
      *param_1 = (CHAR)param_2;
      return 1;
    }
  }
  else {
    param_1 = (LPSTR)0x0;
    iVar1 = WideCharToMultiByte(DAT_00428f28,0x220,&param_2,1,lpMultiByteStr,DAT_00425eec,
                                (LPCSTR)0x0,(LPBOOL)&param_1);
    if ((iVar1 != 0) && (param_1 == (LPSTR)0x0)) {
      return iVar1;
    }
  }
  pDVar2 = FUN_00404720();
  *pDVar2 = 0x2a;
  return -1;
}



/* VA 00408620 */

/* Library Function - Single Match
    __aulldiv

   Library: Visual Studio */

undefined8 __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar6;

  uVar9 = param_1;
  uVar6 = param_4;
  uVar7 = param_2;
  uVar3 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar6 >> 1;
      uVar3 = (uint)(CONCAT14((uVar6 & 1) != 0,uVar3) >> 1);
      uVar8 = uVar7 >> 1;
      uVar9 = (uint)(CONCAT14((uVar7 & 1) != 0,uVar9) >> 1);
      uVar6 = uVar5;
      uVar7 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar9) / (ulonglong)uVar3;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar9 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar9)) ||
       ((param_2 <= uVar9 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}



/* VA 00408690 */

/* Library Function - Single Match
    __aullrem

   Library: Visual Studio */

undefined8 __aullrem(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;

  uVar4 = param_1;
  uVar9 = param_4;
  uVar10 = param_2;
  uVar3 = param_3;
  if (param_4 == 0) {
    iVar6 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar7 = 0;
  }
  else {
    do {
      uVar5 = uVar9 >> 1;
      uVar3 = (uint)(CONCAT14((uVar9 & 1) != 0,uVar3) >> 1);
      uVar8 = uVar10 >> 1;
      uVar4 = (uint)(CONCAT14((uVar10 & 1) != 0,uVar4) >> 1);
      uVar9 = uVar5;
      uVar10 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar4) / (ulonglong)uVar3;
    uVar3 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar4 = (uint)lVar2;
    uVar10 = uVar9 + uVar3;
    if (((CARRY4(uVar9,uVar3)) || (param_2 < uVar10)) || ((param_2 <= uVar10 && (param_1 < uVar4))))
    {
      bVar11 = uVar4 < param_3;
      uVar4 = uVar4 - param_3;
      uVar10 = (uVar10 - param_4) - (uint)bVar11;
    }
    iVar6 = -(uVar4 - param_1);
    iVar7 = -(uint)(uVar4 - param_1 != 0) - ((uVar10 - param_2) - (uint)(uVar4 < param_1));
  }
  return CONCAT44(iVar7,iVar6);
}



/* VA 00408710 */

int __cdecl FUN_00408710(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;

  iVar1 = 0;
  if (DAT_00428ffc != (FARPROC)0x0) {
LAB_00408760:
    if (DAT_00429000 != (FARPROC)0x0) {
      iVar1 = (*DAT_00429000)();
    }
    if ((iVar1 != 0) && (DAT_00429004 != (FARPROC)0x0)) {
      iVar1 = (*DAT_00429004)(iVar1);
    }
    iVar1 = (*DAT_00428ffc)(iVar1,param_1,param_2,param_3);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_00428ffc = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_00428ffc != (FARPROC)0x0) {
      DAT_00429000 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_00429004 = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_00408760;
    }
  }
  return 0;
}



/* VA 004087a0 */

BOOL __cdecl
FUN_004087a0(DWORD param_1,LPCWSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6)

{
  BOOL BVar1;
  int cbMultiByte;
  int *lpMultiByteStr;
  int iVar2;
  LPWORD lpCharType;
  BOOL local_4;

  lpCharType = (LPWORD)0x0;
  if (DAT_00429008 == 0) {
    BVar1 = GetStringTypeW(1,L"",1,(LPWORD)&local_4);
    if (BVar1 == 0) {
      BVar1 = GetStringTypeA(0,1,"",1,(LPWORD)&local_4);
      if (BVar1 == 0) {
        return 0;
      }
      DAT_00429008 = 2;
    }
    else {
      DAT_00429008 = 1;
    }
  }
  if (DAT_00429008 != 1) {
    local_4 = DAT_00429008;
    if (DAT_00429008 == 2) {
      local_4 = 0;
      if (param_5 == 0) {
        param_5 = DAT_00428f28;
      }
      cbMultiByte = WideCharToMultiByte(param_5,0x220,param_2,param_3,(LPSTR)0x0,0,(LPCSTR)0x0,
                                        (LPBOOL)0x0);
      if (cbMultiByte == 0) {
        return 0;
      }
      lpMultiByteStr = FUN_00404230(1,cbMultiByte);
      if (lpMultiByteStr == (int *)0x0) {
        return 0;
      }
      iVar2 = WideCharToMultiByte(param_5,0x220,param_2,param_3,(LPSTR)lpMultiByteStr,cbMultiByte,
                                  (LPCSTR)0x0,(LPBOOL)0x0);
      if ((iVar2 != 0) &&
         (lpCharType = (LPWORD)FUN_00402cf0(cbMultiByte * 2 + 2), lpCharType != (LPWORD)0x0)) {
        if (param_6 == 0) {
          param_6 = DAT_00428f18;
        }
        lpCharType[param_3] = 0xffff;
        lpCharType[param_3 + -1] = 0xffff;
        local_4 = GetStringTypeA(param_6,param_1,(LPCSTR)lpMultiByteStr,cbMultiByte,lpCharType);
        if ((lpCharType[param_3 + -1] == 0xffff) || (lpCharType[param_3] != 0xffff)) {
          local_4 = 0;
        }
        else {
          FUN_00403ef0((undefined4 *)param_4,(undefined4 *)lpCharType,param_3 * 2);
        }
      }
      FUN_00402c80((undefined *)lpMultiByteStr);
      FUN_00402c80((undefined *)lpCharType);
    }
    return local_4;
  }
  BVar1 = GetStringTypeW(param_1,param_2,param_3,param_4);
  return BVar1;
}



/* VA 00408930 */

BOOL __cdecl
FUN_00408930(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6)

{
  BOOL BVar1;
  int iVar2;
  LPCWSTR lpWideCharStr;
  WORD local_2;

  lpWideCharStr = (LPCWSTR)0x0;
  if (DAT_0042900c == 0) {
    BVar1 = GetStringTypeA(0,1,"",1,&local_2);
    if (BVar1 == 0) {
      BVar1 = GetStringTypeW(1,L"",1,&local_2);
      if (BVar1 == 0) {
        return 0;
      }
      DAT_0042900c = 1;
    }
    else {
      DAT_0042900c = 2;
    }
  }
  if (DAT_0042900c == 2) {
    if (param_6 == 0) {
      param_6 = DAT_00428f18;
    }
    BVar1 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
    return BVar1;
  }
  param_6 = DAT_0042900c;
  if (DAT_0042900c == 1) {
    param_6 = 0;
    if (param_5 == 0) {
      param_5 = DAT_00428f28;
    }
    iVar2 = MultiByteToWideChar(param_5,9,param_2,param_3,(LPWSTR)0x0,0);
    if (iVar2 != 0) {
      lpWideCharStr = (LPCWSTR)FUN_00404230(2,iVar2);
      if (lpWideCharStr != (LPCWSTR)0x0) {
        iVar2 = MultiByteToWideChar(param_5,1,param_2,param_3,lpWideCharStr,iVar2);
        if (iVar2 != 0) {
          BVar1 = GetStringTypeW(param_1,lpWideCharStr,iVar2,param_4);
          FUN_00402c80((undefined *)lpWideCharStr);
          return BVar1;
        }
      }
    }
    FUN_00402c80((undefined *)lpWideCharStr);
  }
  return param_6;
}



/* VA 00408b10 */

uint __cdecl FUN_00408b10(char *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  char *pcVar44;

  uVar40 = (uint)DAT_0042904e;
  pcVar44 = (char *)(uint)DAT_00429050;
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  uVar1 = FUN_0040a110(1,uVar40,0x31,param_1 + 4);
  uVar2 = FUN_0040a110(1,uVar40,0x32,param_1 + 8);
  uVar3 = FUN_0040a110(1,uVar40,0x33,param_1 + 0xc);
  uVar4 = FUN_0040a110(1,uVar40,0x34,param_1 + 0x10);
  uVar5 = FUN_0040a110(1,uVar40,0x35,param_1 + 0x14);
  uVar6 = FUN_0040a110(1,uVar40,0x36,param_1 + 0x18);
  uVar7 = FUN_0040a110(1,uVar40,0x37,param_1);
  uVar8 = FUN_0040a110(1,uVar40,0x2a,param_1 + 0x20);
  uVar9 = FUN_0040a110(1,uVar40,0x2b,param_1 + 0x24);
  uVar10 = FUN_0040a110(1,uVar40,0x2c,param_1 + 0x28);
  uVar11 = FUN_0040a110(1,uVar40,0x2d,param_1 + 0x2c);
  uVar12 = FUN_0040a110(1,uVar40,0x2e,param_1 + 0x30);
  uVar13 = FUN_0040a110(1,uVar40,0x2f,param_1 + 0x34);
  uVar14 = FUN_0040a110(1,uVar40,0x30,param_1 + 0x1c);
  uVar15 = FUN_0040a110(1,uVar40,0x44,param_1 + 0x38);
  uVar16 = FUN_0040a110(1,uVar40,0x45,param_1 + 0x3c);
  uVar17 = FUN_0040a110(1,uVar40,0x46,param_1 + 0x40);
  uVar18 = FUN_0040a110(1,uVar40,0x47,param_1 + 0x44);
  uVar19 = FUN_0040a110(1,uVar40,0x48,param_1 + 0x48);
  uVar20 = FUN_0040a110(1,uVar40,0x49,param_1 + 0x4c);
  uVar21 = FUN_0040a110(1,uVar40,0x4a,param_1 + 0x50);
  uVar22 = FUN_0040a110(1,uVar40,0x4b,param_1 + 0x54);
  uVar23 = FUN_0040a110(1,uVar40,0x4c,param_1 + 0x58);
  uVar24 = FUN_0040a110(1,uVar40,0x4d,param_1 + 0x5c);
  uVar25 = FUN_0040a110(1,uVar40,0x4e,param_1 + 0x60);
  uVar26 = FUN_0040a110(1,uVar40,0x4f,param_1 + 100);
  uVar27 = FUN_0040a110(1,uVar40,0x38,param_1 + 0x68);
  uVar28 = FUN_0040a110(1,uVar40,0x39,param_1 + 0x6c);
  uVar29 = FUN_0040a110(1,uVar40,0x3a,param_1 + 0x70);
  uVar30 = FUN_0040a110(1,uVar40,0x3b,param_1 + 0x74);
  uVar31 = FUN_0040a110(1,uVar40,0x3c,param_1 + 0x78);
  uVar32 = FUN_0040a110(1,uVar40,0x3d,param_1 + 0x7c);
  uVar33 = FUN_0040a110(1,uVar40,0x3e,param_1 + 0x80);
  uVar34 = FUN_0040a110(1,uVar40,0x3f,param_1 + 0x84);
  uVar35 = FUN_0040a110(1,uVar40,0x40,param_1 + 0x88);
  uVar36 = FUN_0040a110(1,uVar40,0x41,param_1 + 0x8c);
  uVar37 = FUN_0040a110(1,uVar40,0x42,param_1 + 0x90);
  uVar38 = FUN_0040a110(1,uVar40,0x43,param_1 + 0x94);
  uVar39 = FUN_0040a110(1,uVar40,0x28,param_1 + 0x98);
  uVar40 = FUN_0040a110(1,uVar40,0x29,param_1 + 0x9c);
  uVar41 = FUN_0040a110(1,(LCID)pcVar44,0x1f,param_1 + 0xa0);
  uVar42 = FUN_0040a110(1,(LCID)pcVar44,0x20,param_1 + 0xa4);
  uVar43 = FUN_004090d0(pcVar44,(int)param_1);
  return uVar1 | uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11 |
         uVar12 | uVar13 | uVar14 | uVar15 | uVar16 | uVar17 | uVar18 | uVar19 | uVar20 | uVar21 |
         uVar22 | uVar23 | uVar24 | uVar25 | uVar26 | uVar27 | uVar28 | uVar29 | uVar30 | uVar31 |
         uVar32 | uVar33 | uVar34 | uVar35 | uVar36 | uVar37 | uVar38 | uVar39 | uVar40 | uVar41 |
         uVar42 | uVar43;
}



/* VA 00408e90 */

void __cdecl FUN_00408e90(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_00402c80((undefined *)param_1[1]);
    FUN_00402c80((undefined *)param_1[2]);
    FUN_00402c80((undefined *)param_1[3]);
    FUN_00402c80((undefined *)param_1[4]);
    FUN_00402c80((undefined *)param_1[5]);
    FUN_00402c80((undefined *)param_1[6]);
    FUN_00402c80((undefined *)*param_1);
    FUN_00402c80((undefined *)param_1[8]);
    FUN_00402c80((undefined *)param_1[9]);
    FUN_00402c80((undefined *)param_1[10]);
    FUN_00402c80((undefined *)param_1[0xb]);
    FUN_00402c80((undefined *)param_1[0xc]);
    FUN_00402c80((undefined *)param_1[0xd]);
    FUN_00402c80((undefined *)param_1[7]);
    FUN_00402c80((undefined *)param_1[0xe]);
    FUN_00402c80((undefined *)param_1[0xf]);
    FUN_00402c80((undefined *)param_1[0x10]);
    FUN_00402c80((undefined *)param_1[0x11]);
    FUN_00402c80((undefined *)param_1[0x12]);
    FUN_00402c80((undefined *)param_1[0x13]);
    FUN_00402c80((undefined *)param_1[0x14]);
    FUN_00402c80((undefined *)param_1[0x15]);
    FUN_00402c80((undefined *)param_1[0x16]);
    FUN_00402c80((undefined *)param_1[0x17]);
    FUN_00402c80((undefined *)param_1[0x18]);
    FUN_00402c80((undefined *)param_1[0x19]);
    FUN_00402c80((undefined *)param_1[0x1a]);
    FUN_00402c80((undefined *)param_1[0x1b]);
    FUN_00402c80((undefined *)param_1[0x1c]);
    FUN_00402c80((undefined *)param_1[0x1d]);
    FUN_00402c80((undefined *)param_1[0x1e]);
    FUN_00402c80((undefined *)param_1[0x1f]);
    FUN_00402c80((undefined *)param_1[0x20]);
    FUN_00402c80((undefined *)param_1[0x21]);
    FUN_00402c80((undefined *)param_1[0x22]);
    FUN_00402c80((undefined *)param_1[0x23]);
    FUN_00402c80((undefined *)param_1[0x24]);
    FUN_00402c80((undefined *)param_1[0x25]);
    FUN_00402c80((undefined *)param_1[0x26]);
    FUN_00402c80((undefined *)param_1[0x27]);
    FUN_00402c80((undefined *)param_1[0x28]);
    FUN_00402c80((undefined *)param_1[0x29]);
    FUN_00402c80((undefined *)param_1[0x2a]);
  }
  return;
}



/* VA 004090d0 */

uint __cdecl FUN_004090d0(char *param_1,int param_2)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  char *pcVar7;
  char *pcVar8;
  int local_8;
  int local_4;

  pcVar7 = param_1;
  local_4 = 0;
  local_8 = 0;
  uVar3 = FUN_0040a110(0,(LCID)param_1,0x23,(char *)&local_4);
  uVar4 = FUN_0040a110(0,(LCID)pcVar7,0x25,(char *)&local_8);
  uVar5 = FUN_0040a110(1,(LCID)pcVar7,0x1e,(char *)&param_1);
  uVar5 = uVar3 | uVar4 | uVar5;
  if (uVar5 != 0) {
    return uVar5;
  }
  puVar6 = (undefined1 *)FUN_00402cf0(0xd);
  *(undefined1 **)(param_2 + 0xa8) = puVar6;
  if (local_4 == 0) {
    *puVar6 = 0x68;
    pcVar7 = puVar6 + 1;
    if (local_8 == 0) goto LAB_0040916c;
    *pcVar7 = 'h';
  }
  else {
    *puVar6 = 0x48;
    pcVar7 = puVar6 + 1;
    if (local_8 == 0) goto LAB_0040916c;
    *pcVar7 = 'H';
  }
  pcVar7 = puVar6 + 2;
LAB_0040916c:
  cVar2 = *param_1;
  pcVar8 = param_1;
  while (cVar2 != '\0') {
    *pcVar7 = cVar2;
    pcVar1 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
    cVar2 = *pcVar1;
  }
  *pcVar7 = 'm';
  pcVar8 = pcVar7 + 1;
  if (local_8 != 0) {
    *pcVar8 = 'm';
    pcVar8 = pcVar7 + 2;
  }
  cVar2 = *param_1;
  pcVar7 = param_1;
  while (cVar2 != '\0') {
    *pcVar8 = cVar2;
    pcVar1 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
    cVar2 = *pcVar1;
  }
  *pcVar8 = 's';
  pcVar8[1] = 's';
  pcVar8[2] = '\0';
  FUN_00402c80(param_1);
  return 0;
}



/* VA 004094c0 */

uint __cdecl FUN_004094c0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;

  uVar15 = (uint)DAT_00429044;
  if (param_1 == 0) {
    return 0xffffffff;
  }
  uVar1 = FUN_0040a110(1,uVar15,0x15,(char *)(param_1 + 0xc));
  uVar2 = FUN_0040a110(1,uVar15,0x14,(char *)(param_1 + 0x10));
  uVar3 = FUN_0040a110(1,uVar15,0x16,(char *)(param_1 + 0x14));
  uVar4 = FUN_0040a110(1,uVar15,0x17,(char *)(param_1 + 0x18));
  uVar5 = FUN_0040a110(1,uVar15,0x18,(char *)(param_1 + 0x1c));
  FUN_00409610(*(char **)(param_1 + 0x1c));
  uVar6 = FUN_0040a110(1,uVar15,0x50,(char *)(param_1 + 0x20));
  uVar7 = FUN_0040a110(1,uVar15,0x51,(char *)(param_1 + 0x24));
  uVar8 = FUN_0040a110(0,uVar15,0x1a,(char *)(param_1 + 0x28));
  uVar9 = FUN_0040a110(0,uVar15,0x19,(char *)(param_1 + 0x29));
  uVar10 = FUN_0040a110(0,uVar15,0x54,(char *)(param_1 + 0x2a));
  uVar11 = FUN_0040a110(0,uVar15,0x55,(char *)(param_1 + 0x2b));
  uVar12 = FUN_0040a110(0,uVar15,0x56,(char *)(param_1 + 0x2c));
  uVar13 = FUN_0040a110(0,uVar15,0x57,(char *)(param_1 + 0x2d));
  uVar14 = FUN_0040a110(0,uVar15,0x52,(char *)(param_1 + 0x2e));
  uVar15 = FUN_0040a110(0,uVar15,0x53,(char *)(param_1 + 0x2f));
  return uVar1 | uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11 |
         uVar12 | uVar13 | uVar14 | uVar15;
}



/* VA 00409610 */

void __cdecl FUN_00409610(char *param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;

  cVar2 = *param_1;
  do {
    if (cVar2 == '\0') {
      return;
    }
    if ((cVar2 < '0') || ('9' < cVar2)) {
      pcVar3 = param_1;
      if (cVar2 != ';') goto LAB_00409626;
      do {
        *pcVar3 = pcVar3[1];
        pcVar1 = pcVar3 + 1;
        pcVar3 = pcVar3 + 1;
      } while (*pcVar1 != '\0');
    }
    else {
      *param_1 = cVar2 + -0x30;
LAB_00409626:
      param_1 = param_1 + 1;
    }
    cVar2 = *param_1;
  } while( true );
}



/* VA 00409650 */

void __cdecl FUN_00409650(int param_1)

{
  if ((param_1 != 0) && (*(undefined **)(param_1 + 0xc) != &DAT_00429070)) {
    FUN_00402c80(*(undefined **)(param_1 + 0xc));
    FUN_00402c80(*(undefined **)(param_1 + 0x10));
    FUN_00402c80(*(undefined **)(param_1 + 0x14));
    FUN_00402c80(*(undefined **)(param_1 + 0x18));
    FUN_00402c80(*(undefined **)(param_1 + 0x1c));
    FUN_00402c80(*(undefined **)(param_1 + 0x20));
    FUN_00402c80(*(undefined **)(param_1 + 0x24));
  }
  return;
}



/* VA 00409980 */

/* Library Function - Single Match
    _strcspn

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strcspn(char *_Str,char *_Control)

{
  byte bVar1;
  size_t sVar2;
  byte abStack_28 [32];

  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *_Control;
    if (bVar1 == 0) break;
    _Control = _Control + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  sVar2 = 0xffffffff;
  do {
    sVar2 = sVar2 + 1;
    bVar1 = *_Str;
    if (bVar1 == 0) {
      return sVar2;
    }
    _Str = _Str + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return sVar2;
}



/* VA 004099c0 */

/* Library Function - Single Match
    _strncmp

   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;

  uVar5 = 0;
  sVar3 = _MaxCount;
  pcVar6 = _Str1;
  if (_MaxCount != 0) {
    do {
      if (sVar3 == 0) break;
      sVar3 = sVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar4 = _MaxCount - sVar3;
    do {
      pcVar6 = _Str2;
      pcVar7 = _Str1;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = _Str1 + 1;
      pcVar6 = _Str2 + 1;
      cVar2 = *_Str1;
      cVar1 = *_Str2;
      _Str2 = pcVar6;
      _Str1 = pcVar7;
    } while (cVar1 == cVar2);
    uVar5 = 0;
    if ((byte)pcVar6[-1] <= (byte)pcVar7[-1]) {
      if (pcVar6[-1] == pcVar7[-1]) {
        return 0;
      }
      uVar5 = 0xfffffffe;
    }
    uVar5 = ~uVar5;
  }
  return uVar5;
}



/* VA 00409a00 */

uint __cdecl FUN_00409a00(uint param_1)

{
  uint uVar1;
  uint uVar2;
  LPCWSTR pWVar3;
  int iVar4;
  uint local_8 [2];

  uVar1 = param_1;
  if (DAT_00428f18 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    if ((int)param_1 < 0x100) {
      if (DAT_00425eec < 2) {
        uVar2 = (byte)PTR_DAT_00425ce0[param_1 * 2] & 1;
      }
      else {
        uVar2 = FUN_00407c60(param_1,1);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    uVar2 = param_1;
    if ((PTR_DAT_00425ce0[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1._0_2_ = (ushort)(byte)uVar1;
      pWVar3 = (LPCWSTR)0x1;
    }
    else {
      param_1._0_2_ = CONCAT11((byte)uVar1,(char)(uVar1 >> 8));
      param_1._3_1_ = SUB41(uVar2,3);
      param_1._0_3_ = (uint3)(ushort)param_1;
      pWVar3 = (LPCWSTR)0x2;
    }
    iVar4 = FUN_004079e0(DAT_00428f18,0x100,(char *)&param_1,pWVar3,(LPWSTR)local_8,3,0);
    if (iVar4 == 0) {
      return uVar1;
    }
    if (iVar4 == 1) {
      return local_8[0] & 0xff;
    }
    param_1 = (local_8[0] >> 8 & 0xff) << 8 | local_8[0] & 0xff;
  }
  return param_1;
}



/* VA 00409b00 */

undefined4 __cdecl FUN_00409b00(DWORD *param_1)

{
  DWORD *pDVar1;
  bool bVar2;
  DWORD *pDVar3;
  DWORD *pDVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  undefined4 *puVar9;
  bool bVar10;
  DWORD local_4;

  pDVar3 = param_1;
  bVar2 = false;
  pDVar4 = param_1;
  switch(param_1) {
  case (DWORD *)0x2:
    puVar9 = &DAT_00429054;
    bVar2 = true;
    pcVar8 = DAT_00429054;
    break;
  default:
    return 0xffffffff;
  case (DWORD *)0x4:
  case (DWORD *)0x8:
  case (DWORD *)0xb:
    pDVar4 = FUN_00405240();
    uVar5 = FUN_00409d10((int)param_1,pDVar4[0x14]);
    puVar9 = (undefined4 *)(uVar5 + 8);
    pcVar8 = (code *)*puVar9;
    break;
  case (DWORD *)0xf:
    puVar9 = &DAT_00429060;
    bVar2 = true;
    pcVar8 = DAT_00429060;
    break;
  case (DWORD *)0x15:
    puVar9 = &DAT_00429058;
    bVar2 = true;
    pcVar8 = DAT_00429058;
    break;
  case (DWORD *)0x16:
    puVar9 = &DAT_0042905c;
    bVar2 = true;
    pcVar8 = DAT_0042905c;
  }
  if (bVar2) {
    FUN_00406040(1);
  }
  if (pcVar8 == (code *)0x1) {
    if (!bVar2) {
      return 0;
    }
    FUN_004060c0(1);
    return 0;
  }
  if (pcVar8 == (code *)0x0) {
    if (bVar2) {
      FUN_004060c0(1);
    }
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (((param_1 == (DWORD *)0x8) || (param_1 == (DWORD *)0xb)) || (param_1 == (DWORD *)0x4)) {
    pDVar1 = (DWORD *)pDVar4[0x15];
    bVar10 = param_1 == (DWORD *)0x8;
    pDVar4[0x15] = 0;
    param_1 = pDVar1;
    if (bVar10) {
      local_4 = pDVar4[0x16];
      pDVar4[0x16] = 0x8c;
      goto LAB_00409c33;
    }
  }
  else {
LAB_00409c33:
    if (pDVar3 == (DWORD *)0x8) {
      if (DAT_00425c18 < DAT_00425c1c + DAT_00425c18) {
        iVar7 = DAT_00425c18 * 0xc;
        iVar6 = DAT_00425c18;
        do {
          iVar6 = iVar6 + 1;
          *(undefined4 *)(pDVar4[0x14] + 8 + iVar7) = 0;
          iVar7 = iVar7 + 0xc;
        } while (iVar6 < DAT_00425c1c + DAT_00425c18);
      }
      goto LAB_00409c78;
    }
  }
  *puVar9 = 0;
LAB_00409c78:
  if (bVar2) {
    FUN_004060c0(1);
  }
  if (pDVar3 == (DWORD *)0x8) {
    (*pcVar8)(8,pDVar4[0x16]);
  }
  else {
    (*pcVar8)(pDVar3);
    if ((pDVar3 != (DWORD *)0xb) && (pDVar3 != (DWORD *)0x4)) {
      return 0;
    }
  }
  pDVar4[0x15] = (DWORD)param_1;
  if (pDVar3 == (DWORD *)0x8) {
    pDVar4[0x16] = local_4;
  }
  return 0;
}



/* VA 00409d10 */

uint __cdecl FUN_00409d10(int param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;

  uVar2 = param_2;
  if (*(int *)(param_2 + 4) != param_1) {
    uVar3 = param_2;
    do {
      uVar2 = uVar3 + 0xc;
      if (param_2 + DAT_00425c24 * 0xc <= uVar2) break;
      piVar1 = (int *)(uVar3 + 0x10);
      uVar3 = uVar2;
    } while (*piVar1 != param_1);
  }
  if ((param_2 + DAT_00425c24 * 0xc <= uVar2) || (*(int *)(uVar2 + 4) != param_1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* VA 00409df0 */

undefined4 __cdecl FUN_00409df0(uint param_1)

{
  DWORD *pDVar1;

  if ((param_1 < DAT_0042a1c0) &&
     ((*(byte *)((&DAT_0042a0c0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_0042a0c0)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  pDVar1 = FUN_00404720();
  *pDVar1 = 9;
  pDVar1 = FUN_00404730();
  *pDVar1 = 0;
  return 0xffffffff;
}



/* VA 00409e40 */

void __cdecl FUN_00409e40(uint param_1)

{
  int iVar1;
  int iVar2;

  iVar2 = (param_1 & 0x1f) * 0x24;
  iVar1 = (&DAT_0042a0c0)[(int)param_1 >> 5] + iVar2;
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_00406040(0x11);
    if (*(int *)(iVar1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    FUN_004060c0(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_0042a0c0)[(int)param_1 >> 5] + 0xc + iVar2));
  return;
}



/* VA 00409eb0 */

void __cdecl FUN_00409eb0(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_0042a0c0)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));
  return;
}



/* VA 0040a100 */

void FUN_0040a100(void)

{
  __amsg_exit(2);
  return;
}



/* VA 0040a110 */

undefined4 __cdecl FUN_0040a110(int param_1,LCID param_2,LCTYPE param_3,char *param_4)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  DWORD DVar4;
  LPSTR _Source;
  char *_Dest;
  int iVar5;
  byte *pbVar6;
  CHAR local_80 [128];

  if (param_1 != 1) {
    if (param_1 != 0) {
      return 0xffffffff;
    }
    iVar5 = FUN_0040a2c0(param_2,param_3,(LPWSTR)&DAT_00429068,4,0);
    if (iVar5 != 0) {
      pbVar6 = &DAT_00429068;
      *param_4 = '\0';
      while( true ) {
        bVar1 = *pbVar6;
        if (DAT_00425eec < 2) {
          uVar3 = (byte)PTR_DAT_00425ce0[(uint)bVar1 * 2] & 4;
        }
        else {
          uVar3 = FUN_00407c60((uint)bVar1,4);
        }
        if (uVar3 == 0) break;
        pbVar6 = pbVar6 + 2;
        *param_4 = *param_4 * '\n' + bVar1 + -0x30;
        if (0x42906f < (int)pbVar6) {
          return 0;
        }
      }
      return 0;
    }
    return 0xffffffff;
  }
  _Source = local_80;
  bVar2 = false;
  uVar3 = FUN_0040a3f0(param_2,param_3,local_80,0x80,0);
  if (uVar3 == 0) {
    DVar4 = GetLastError();
    if (((DVar4 != 0x7a) || (uVar3 = FUN_0040a3f0(param_2,param_3,(LPSTR)0x0,0,0), uVar3 == 0)) ||
       (_Source = (LPSTR)FUN_00402cf0(uVar3), _Source == (LPSTR)0x0)) goto LAB_0040a1c0;
    bVar2 = true;
    uVar3 = FUN_0040a3f0(param_2,param_3,_Source,uVar3,0);
    if (uVar3 == 0) goto LAB_0040a1c0;
  }
  _Dest = (char *)FUN_00402cf0(uVar3);
  *(char **)param_4 = _Dest;
  if (_Dest != (char *)0x0) {
    _strncpy(_Dest,_Source,uVar3);
    if (!bVar2) {
      return 0;
    }
    FUN_00402c80(_Source);
    return 0;
  }
LAB_0040a1c0:
  if (!bVar2) {
    return 0xffffffff;
  }
  FUN_00402c80(_Source);
  return 0xffffffff;
}



/* VA 0040a2c0 */

int __cdecl FUN_0040a2c0(LCID param_1,LCTYPE param_2,LPWSTR param_3,int param_4,UINT param_5)

{
  int iVar1;
  uint cchData;
  LPSTR lpLCData;

  if (DAT_00429074 == 0) {
    iVar1 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = GetLocaleInfoA(0,1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_00429074 = 2;
    }
    else {
      DAT_00429074 = 1;
    }
  }
  if (DAT_00429074 == 1) {
    iVar1 = GetLocaleInfoW(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  if (DAT_00429074 != 2) {
    return DAT_00429074;
  }
  if (param_5 == 0) {
    param_5 = DAT_00428f28;
  }
  cchData = GetLocaleInfoA(param_1,param_2,(LPSTR)0x0,0);
  if (cchData != 0) {
    lpLCData = (LPSTR)FUN_00402cf0(cchData);
    if (lpLCData == (LPSTR)0x0) {
      return 0;
    }
    iVar1 = GetLocaleInfoA(param_1,param_2,lpLCData,cchData);
    if (iVar1 != 0) {
      if (param_4 == 0) {
        iVar1 = MultiByteToWideChar(param_5,1,lpLCData,-1,(LPWSTR)0x0,0);
        if (iVar1 != 0) {
          FUN_00402c80(lpLCData);
          return iVar1;
        }
      }
      else {
        iVar1 = MultiByteToWideChar(param_5,1,lpLCData,-1,param_3,param_4);
        if (iVar1 != 0) {
          FUN_00402c80(lpLCData);
          return iVar1;
        }
      }
    }
    FUN_00402c80(lpLCData);
    return 0;
  }
  return 0;
}



/* VA 0040a3f0 */

int __cdecl FUN_0040a3f0(LCID param_1,LCTYPE param_2,LPSTR param_3,int param_4,UINT param_5)

{
  int iVar1;
  LPWSTR lpLCData;

  if (DAT_00429078 == 0) {
    iVar1 = GetLocaleInfoA(0,1,(LPSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
      if (iVar1 == 0) {
        return 0;
      }
      DAT_00429078 = 1;
    }
    else {
      DAT_00429078 = 2;
    }
  }
  if (DAT_00429078 == 2) {
    iVar1 = GetLocaleInfoA(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  if (DAT_00429078 != 1) {
    return DAT_00429078;
  }
  if (param_5 == 0) {
    param_5 = DAT_00428f28;
  }
  iVar1 = GetLocaleInfoW(param_1,param_2,(LPWSTR)0x0,0);
  if (iVar1 != 0) {
    lpLCData = (LPWSTR)FUN_00402cf0(iVar1 * 2);
    if (lpLCData == (LPWSTR)0x0) {
      return 0;
    }
    iVar1 = GetLocaleInfoW(param_1,param_2,lpLCData,iVar1);
    if (iVar1 != 0) {
      if (param_4 == 0) {
        iVar1 = WideCharToMultiByte(param_5,0x220,lpLCData,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
        if (iVar1 != 0) {
          FUN_00402c80((undefined *)lpLCData);
          return iVar1;
        }
      }
      else {
        iVar1 = WideCharToMultiByte(param_5,0x220,lpLCData,-1,param_3,param_4,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        if (iVar1 != 0) {
          FUN_00402c80((undefined *)lpLCData);
          return iVar1;
        }
      }
    }
    FUN_00402c80((undefined *)lpLCData);
    return 0;
  }
  return 0;
}



/* VA 0040a7c0 */

void RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue)

{
                    /* WARNING: Could not recover jumptable at 0x0040a7c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnwind(TargetFrame,TargetIp,ExceptionRecord,ReturnValue);
  return;
}



/* VA 0040a7c6 */

LPARAM ReuseDDElParam(LPARAM lParam,UINT msgIn,UINT msgOut,UINT_PTR uiLo,UINT_PTR uiHi)

{
  LPARAM LVar1;

                    /* WARNING: Could not recover jumptable at 0x0040a7c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = ReuseDDElParam(lParam,msgIn,msgOut,uiLo,uiHi);
  return LVar1;
}



/* VA 0040a7cc */

BOOL UnpackDDElParam(UINT msg,LPARAM lParam,PUINT_PTR puiLo,PUINT_PTR puiHi)

{
  BOOL BVar1;

                    /* WARNING: Could not recover jumptable at 0x0040a7cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = UnpackDDElParam(msg,lParam,puiLo,puiHi);
  return BVar1;
}



/* VA 0040a7d2 */

BOOL ClosePrinter(HANDLE hPrinter)

{
  BOOL BVar1;

                    /* WARNING: Could not recover jumptable at 0x0040a7d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ClosePrinter(hPrinter);
  return BVar1;
}



/* VA 0040a7d8 */

LONG DocumentPropertiesA(HWND hWnd,HANDLE hPrinter,LPSTR pDeviceName,PDEVMODEA pDevModeOutput,
                        PDEVMODEA pDevModeInput,DWORD fMode)

{
  LONG LVar1;

                    /* WARNING: Could not recover jumptable at 0x0040a7d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = DocumentPropertiesA(hWnd,hPrinter,pDeviceName,pDevModeOutput,pDevModeInput,fMode);
  return LVar1;
}



/* VA 0040a7de */

BOOL OpenPrinterA(LPSTR pPrinterName,LPHANDLE phPrinter,LPPRINTER_DEFAULTSA pDefault)

{
  BOOL BVar1;

                    /* WARNING: Could not recover jumptable at 0x0040a7de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = OpenPrinterA(pPrinterName,phPrinter,pDefault);
  return BVar1;
}



/* VA 0040a7e4 */

void FUN_0040a7e4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_004109fb(param_1,param_2,param_3,param_4);
  return;
}



/* VA 0040a7fc */

undefined4 FUN_0040a7fc(int param_1)

{
  int iVar1;

  iVar1 = FUN_00419dc2();
  *(char *)(iVar1 + 0x14) = (char)param_1;
  if (param_1 == 0) {
    FUN_004042e0(-3);
  }
  return 1;
}



/* VA 0040a81a */

undefined4 __fastcall FUN_0040a81a(undefined4 param_1)

{
  FUN_0040a7fc(0);
  return param_1;
}



/* VA 0040a841 */

void FUN_0040a841(void)

{
  FUN_0040a81a(&DAT_00429084);
  return;
}



/* VA 0040a84b */

void FUN_0040a84b(void)

{
  FUN_00402fb0(0x40a857);
  return;
}



/* VA 0040a861 */

/* Library Function - Single Match
    public: void __thiscall CSimpleException::InitString(void)

   Library: Visual Studio 2015 Release */

void __thiscall CSimpleException::InitString(CSimpleException *this)

{
  int iVar1;

  *(undefined4 *)(this + 0xc) = 1;
  iVar1 = FUN_0040fa52(*(UINT *)(this + 0x94),(LPSTR)(this + 0x14),0x80);
  *(uint *)(this + 0x10) = (uint)(iVar1 != 0);
  return;
}



/* VA 0040a8cd */

void FUN_0040a8cd(void)

{
  undefined *local_8;

  local_8 = &DAT_00428858;
  FUN_00403310(&local_8,&DAT_00421a00);
  return;
}



/* VA 0040a8e8 */

void __thiscall FUN_0040a8e8(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined ***)this = &PTR_LAB_0041dd54;
  *(undefined4 *)((int)this + 0x18) = param_1;
  return;
}



/* VA 0040a90b */

undefined * __thiscall FUN_0040a90b(void *this,byte param_1)

{
  FUN_0040a947();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 0040a927 */

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall CObList::RemoveAll(void)
    public: void __thiscall CPtrList::RemoveAll(void)

   Library: Visual Studio 2015 Release */

void __fastcall RemoveAll(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_0040aaaf(*(undefined4 **)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



/* VA 0040a947 */

void FUN_0040a947(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041dd54;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  RemoveAll((int)extraout_ECX);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d1bc;
  *unaff_FS_OFFSET = uVar1;
  return;
}



/* VA 0040a97a */

void __thiscall FUN_0040a97a(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;

  if (*(int *)((int)this + 0x10) == 0) {
    iVar1 = FUN_0040aa8f((undefined4 *)((int)this + 0x14),*(int *)((int)this + 0x18),0xc);
    iVar3 = *(int *)((int)this + 0x18);
    puVar2 = (undefined4 *)(iVar1 + -8 + iVar3 * 0xc);
    if (-1 < iVar3 + -1) {
      do {
        *puVar2 = *(undefined4 *)((int)this + 0x10);
        *(undefined4 **)((int)this + 0x10) = puVar2;
        puVar2 = puVar2 + -3;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  puVar2 = *(undefined4 **)((int)this + 0x10);
  *(undefined4 *)((int)this + 0x10) = *puVar2;
  puVar2[1] = param_1;
  *puVar2 = param_2;
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
  puVar2[2] = 0;
  return;
}



/* VA 0040a9cf */

void __thiscall FUN_0040a9cf(void *this,undefined4 *param_1)

{
  int *piVar1;

  *param_1 = *(undefined4 *)((int)this + 0x10);
  piVar1 = (int *)((int)this + 0xc);
  *piVar1 = *piVar1 + -1;
  *(undefined4 **)((int)this + 0x10) = param_1;
  if (*piVar1 == 0) {
    RemoveAll((int)this);
  }
  return;
}



/* VA 0040a9e8 */

/* Library Function - Multiple Matches With Same Base Name
    public: struct __POSITION * __thiscall CList<struct HWND__ *,struct HWND__ *>::AddTail(struct
   HWND__ *)
    public: struct __POSITION * __thiscall CList<class IControlSiteFactory *,class
   IControlSiteFactory *>::AddTail(class IControlSiteFactory *)
    public: struct __POSITION * __thiscall CObList::AddTail(class CObject *)
    public: struct __POSITION * __thiscall CPtrList::AddTail(void *)

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

void __thiscall AddTail(void *this,undefined4 param_1)

{
  int iVar1;

  iVar1 = FUN_0040a97a(this,*(undefined4 *)((int)this + 8),0);
  *(undefined4 *)(iVar1 + 8) = param_1;
  if (*(int **)((int)this + 8) == (int *)0x0) {
    *(int *)((int)this + 4) = iVar1;
  }
  else {
    **(int **)((int)this + 8) = iVar1;
  }
  *(int *)((int)this + 8) = iVar1;
  return;
}



/* VA 0040aa11 */

int __fastcall FUN_0040aa11(void *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;

  piVar1 = *(int **)((int)param_1 + 4);
  iVar2 = *piVar1;
  iVar3 = piVar1[2];
  *(int *)((int)param_1 + 4) = iVar2;
  if (iVar2 == 0) {
    *(undefined4 *)((int)param_1 + 8) = 0;
  }
  else {
    *(undefined4 *)(iVar2 + 4) = 0;
  }
  FUN_0040a9cf(param_1,piVar1);
  return iVar3;
}



/* VA 0040aa35 */

void __thiscall FUN_0040aa35(void *this,int *param_1)

{
  if (param_1 == *(int **)((int)this + 4)) {
    *(int *)((int)this + 4) = *param_1;
  }
  else {
    *(int *)param_1[1] = *param_1;
  }
  if (param_1 == *(int **)((int)this + 8)) {
    *(int *)((int)this + 8) = param_1[1];
  }
  else {
    *(int *)(*param_1 + 4) = param_1[1];
  }
  FUN_0040a9cf(this,param_1);
  return;
}



/* VA 0040aa6c */

undefined4 * __thiscall FUN_0040aa6c(void *this,int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) goto LAB_0040aa79;
  param_2 = *(undefined4 **)((int)this + 4);
  while( true ) {
    if (param_2 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if (param_2[2] == param_1) break;
LAB_0040aa79:
    param_2 = (undefined4 *)*param_2;
  }
  return param_2;
}



/* VA 0040aa8f */

void FUN_0040aa8f(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;

  puVar1 = (undefined4 *)FUN_0040f348(param_2 * param_3 + 4);
  *puVar1 = *param_1;
  *param_1 = puVar1;
  return;
}



/* VA 0040aaaf */

void __fastcall FUN_0040aaaf(undefined4 *param_1)

{
  undefined4 *puVar1;

  while (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_1;
    FUN_0040f384((undefined *)param_1);
    param_1 = puVar1;
  }
  return;
}



/* VA 0040aac5 */

void __fastcall FUN_0040aac5(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_0041f0ec;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  return;
}



/* VA 0040aadc */

undefined * __thiscall FUN_0040aadc(void *this,byte param_1)

{
  FUN_0040aaf8();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 0040aaf8 */

void FUN_0040aaf8(void)

{
  undefined *puVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041f0ec;
  puVar1 = (undefined *)extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040f384(puVar1);
  *extraout_ECX = &PTR_LAB_0041d1bc;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 0040ab2f */

void __thiscall FUN_0040ab2f(void *this,int param_1,int param_2)

{
  void *_Dst;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;

  if (param_2 != -1) {
    *(int *)((int)this + 0x10) = param_2;
  }
  if (param_1 == 0) {
    FUN_0040f384(*(undefined **)((int)this + 4));
    *(undefined4 *)((int)this + 4) = 0;
    *(undefined4 *)((int)this + 0xc) = 0;
    *(undefined4 *)((int)this + 8) = 0;
  }
  else {
    if (*(int *)((int)this + 4) == 0) {
      _Dst = (void *)FUN_0040f348(param_1 << 2);
      *(void **)((int)this + 4) = _Dst;
      _memset(_Dst,0,param_1 << 2);
      *(int *)((int)this + 0xc) = param_1;
    }
    else {
      if (*(int *)((int)this + 0xc) < param_1) {
        iVar1 = *(int *)((int)this + 0x10);
        if (*(int *)((int)this + 0x10) == 0) {
          iVar1 = *(int *)((int)this + 8) / 8;
          iVar3 = 4;
          if (3 < iVar1) {
            iVar3 = iVar1;
          }
          if (iVar3 < 0x401) {
            if (iVar1 < 4) {
              iVar1 = 4;
            }
          }
          else {
            iVar1 = 0x400;
          }
        }
        param_2 = iVar1 + *(int *)((int)this + 0xc);
        if (param_2 <= param_1) {
          param_2 = param_1;
        }
        puVar2 = (undefined4 *)FUN_0040f348(param_2 << 2);
        FUN_00403510(puVar2,*(undefined4 **)((int)this + 4),*(int *)((int)this + 8) << 2);
        _memset(puVar2 + *(int *)((int)this + 8),0,
                (*(int *)((int)this + 8) * 0x3fffffff + param_1) * 4);
        FUN_0040f384(*(undefined **)((int)this + 4));
        *(undefined4 **)((int)this + 4) = puVar2;
        *(int *)((int)this + 8) = param_1;
        *(int *)((int)this + 0xc) = param_2;
        return;
      }
      iVar1 = *(int *)((int)this + 8);
      if (iVar1 < param_1) {
        _memset((void *)(*(int *)((int)this + 4) + iVar1 * 4),0,(iVar1 * 0x3fffffff + param_1) * 4);
      }
    }
    *(int *)((int)this + 8) = param_1;
  }
  return;
}



/* VA 0040ac52 */

void __thiscall FUN_0040ac52(void *this,int param_1,undefined4 param_2)

{
  if (*(int *)((int)this + 8) <= param_1) {
    FUN_0040ab2f(this,param_1 + 1,-1);
  }
  *(undefined4 *)(*(int *)((int)this + 4) + param_1 * 4) = param_2;
  return;
}



/* VA 0040ac79 */

void __thiscall FUN_0040ac79(void *this,int param_1,undefined4 param_2,int param_3)

{
  int iVar1;

  iVar1 = *(int *)((int)this + 8);
  if (param_1 < iVar1) {
    FUN_0040ab2f(this,iVar1 + param_3,-1);
    FUN_00403ef0((undefined4 *)(*(int *)((int)this + 4) + (param_3 + param_1) * 4),
                 (undefined4 *)(*(int *)((int)this + 4) + param_1 * 4),
                 (param_1 * 0x3fffffff + iVar1) * 4);
    _memset((void *)(*(int *)((int)this + 4) + param_1 * 4),0,param_3 << 2);
  }
  else {
    FUN_0040ab2f(this,param_3 + param_1,-1);
  }
  if (param_3 != 0) {
    iVar1 = param_1 << 2;
    do {
      *(undefined4 *)(*(int *)((int)this + 4) + iVar1) = param_2;
      iVar1 = iVar1 + 4;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}



/* VA 0040ad0e */

void __thiscall FUN_0040ad0e(void *this,int param_1,int param_2)

{
  int iVar1;

  iVar1 = (*(int *)((int)this + 8) - param_1) - param_2;
  if (iVar1 != 0) {
    FUN_00403510((undefined4 *)(*(int *)((int)this + 4) + param_1 * 4),
                 (undefined4 *)(*(int *)((int)this + 4) + (param_2 + param_1) * 4),iVar1 * 4);
  }
  *(int *)((int)this + 8) = *(int *)((int)this + 8) - param_2;
  return;
}



/* VA 0040ad45 */

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall CMap<void *,void *,void *,void *>::CMap<void *,void *,void *,void *>(int)
    public: __thiscall CMap<class ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class
   ATL::ChTraitsOS<wchar_t> > >,wchar_t const *,void *,void *>::CMap<class
   ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class ATL::ChTraitsOS<wchar_t> > >,wchar_t const
   *,void *,void *>(int)

   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

void __thiscall CMap<>(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined ***)this = &PTR_LAB_0041de8c;
  *(undefined4 *)((int)this + 8) = 0x11;
  *(undefined4 *)((int)this + 0x18) = param_1;
  return;
}



/* VA 0040ad6c */

undefined * __thiscall FUN_0040ad6c(void *this,byte param_1)

{
  FUN_0040adf9();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 0040ad88 */

void __thiscall FUN_0040ad88(void *this,int param_1,int param_2)

{
  void *_Dst;

  if (*(undefined **)((int)this + 4) != (undefined *)0x0) {
    FUN_0040f384(*(undefined **)((int)this + 4));
    *(undefined4 *)((int)this + 4) = 0;
  }
  if (param_2 != 0) {
    _Dst = (void *)FUN_0040f348(param_1 << 2);
    *(void **)((int)this + 4) = _Dst;
    _memset(_Dst,0,param_1 << 2);
  }
  *(int *)((int)this + 8) = param_1;
  return;
}



/* VA 0040adce */

/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall CMapPtrToPtr::RemoveAll(void)
    public: void __thiscall CMapPtrToWord::RemoveAll(void)
    public: void __thiscall CMapWordToOb::RemoveAll(void)
    public: void __thiscall CMapWordToPtr::RemoveAll(void)

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release,
   Visual Studio 2010 Release */

void __fastcall RemoveAll(int param_1)

{
  if (*(undefined **)(param_1 + 4) != (undefined *)0x0) {
    FUN_0040f384(*(undefined **)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  FUN_0040aaaf(*(undefined4 **)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



/* VA 0040adf9 */

void FUN_0040adf9(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041de8c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  RemoveAll((int)extraout_ECX);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d1bc;
  *unaff_FS_OFFSET = uVar1;
  return;
}



/* VA 0040ae2c */

void __fastcall FUN_0040ae2c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;

  if (*(int *)(param_1 + 0x10) == 0) {
    iVar2 = FUN_0040aa8f((undefined4 *)(param_1 + 0x14),*(int *)(param_1 + 0x18),0xc);
    iVar4 = *(int *)(param_1 + 0x18);
    puVar3 = (undefined4 *)(iVar2 + -8 + iVar4 * 0xc);
    if (-1 < iVar4 + -1) {
      do {
        *puVar3 = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 **)(param_1 + 0x10) = puVar3;
        puVar3 = puVar3 + -3;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  puVar3 = *(undefined4 **)(param_1 + 0x10);
  uVar1 = *puVar3;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  puVar3[1] = 0;
  puVar3[2] = 0;
  return;
}



/* VA 0040ae76 */

void __thiscall FUN_0040ae76(void *this,undefined4 *param_1)

{
  int *piVar1;

  *param_1 = *(undefined4 *)((int)this + 0x10);
  piVar1 = (int *)((int)this + 0xc);
  *piVar1 = *piVar1 + -1;
  *(undefined4 **)((int)this + 0x10) = param_1;
  if (*piVar1 == 0) {
    RemoveAll((int)this);
  }
  return;
}



/* VA 0040ae8f */

undefined4 * __thiscall FUN_0040ae8f(void *this,uint param_1,uint *param_2)

{
  undefined4 *puVar1;
  uint uVar2;

  uVar2 = (param_1 >> 4) % *(uint *)((int)this + 8);
  *param_2 = uVar2;
  if (*(int *)((int)this + 4) != 0) {
    for (puVar1 = *(undefined4 **)(*(int *)((int)this + 4) + uVar2 * 4); puVar1 != (undefined4 *)0x0
        ; puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[1] == param_1) {
        return puVar1;
      }
    }
  }
  return (undefined4 *)0x0;
}



/* VA 0040aec1 */

undefined4 __thiscall FUN_0040aec1(void *this,uint param_1)

{
  undefined4 *puVar1;

  if (*(int *)((int)this + 4) != 0) {
    for (puVar1 = *(undefined4 **)
                   (*(int *)((int)this + 4) + ((param_1 >> 4) % *(uint *)((int)this + 8)) * 4);
        puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[1] == param_1) {
        return puVar1[2];
      }
    }
  }
  return 0;
}



/* VA 0040aef4 */

undefined4 * __thiscall FUN_0040aef4(void *this,uint param_1)

{
  uint uVar1;
  undefined4 *puVar2;

  uVar1 = param_1;
  puVar2 = FUN_0040ae8f(this,param_1,&param_1);
  if (puVar2 == (undefined4 *)0x0) {
    if (*(int *)((int)this + 4) == 0) {
      FUN_0040ad88(this,*(int *)((int)this + 8),1);
    }
    puVar2 = (undefined4 *)FUN_0040ae2c((int)this);
    puVar2[1] = uVar1;
    *puVar2 = *(undefined4 *)(*(int *)((int)this + 4) + param_1 * 4);
    *(undefined4 **)(*(int *)((int)this + 4) + param_1 * 4) = puVar2;
  }
  return puVar2 + 2;
}



/* VA 0040af44 */

undefined4 __thiscall FUN_0040af44(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;

  iVar1 = *(int *)((int)this + 4);
  if (iVar1 != 0) {
    uVar4 = (param_1 >> 4) % *(uint *)((int)this + 8);
    puVar2 = *(undefined4 **)(iVar1 + uVar4 * 4);
    puVar5 = (undefined4 *)(iVar1 + uVar4 * 4);
    while (puVar3 = puVar2, puVar3 != (undefined4 *)0x0) {
      if (puVar3[1] == param_1) {
        *puVar5 = *puVar3;
        FUN_0040ae76(this,puVar3);
        return 1;
      }
      puVar5 = puVar3;
      puVar2 = (undefined4 *)*puVar3;
    }
  }
  return 0;
}



/* VA 0040af86 */

void __thiscall FUN_0040af86(void *this,int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;

  piVar3 = (int *)*param_1;
  if (piVar3 == (int *)0xffffffff) {
    uVar4 = 0;
    if (*(uint *)((int)this + 8) != 0) {
      piVar1 = *(int **)((int)this + 4);
      do {
        piVar3 = (int *)*piVar1;
        if (piVar3 != (int *)0x0) break;
        uVar4 = uVar4 + 1;
        piVar1 = piVar1 + 1;
      } while (uVar4 < *(uint *)((int)this + 8));
    }
  }
  iVar5 = *piVar3;
  if (iVar5 == 0) {
    uVar4 = *(uint *)((int)this + 8);
    uVar2 = ((uint)piVar3[1] >> 4) % uVar4 + 1;
    if (uVar2 < uVar4) {
      piVar1 = (int *)(*(int *)((int)this + 4) + uVar2 * 4);
      do {
        iVar5 = *piVar1;
        if (iVar5 != 0) break;
        uVar2 = uVar2 + 1;
        piVar1 = piVar1 + 1;
      } while (uVar2 < uVar4);
    }
  }
  *param_1 = iVar5;
  *param_2 = piVar3[1];
  *param_3 = piVar3[2];
  return;
}



/* VA 0040aff8 */

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall CMap<void *,void *,void *,void *>::CMap<void *,void *,void *,void *>(int)
    public: __thiscall CMap<class ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class
   ATL::ChTraitsOS<wchar_t> > >,wchar_t const *,void *,void *>::CMap<class
   ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class ATL::ChTraitsOS<wchar_t> > >,wchar_t const
   *,void *,void *>(int)

   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

void __thiscall CMap<>(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined ***)this = &PTR_LAB_0041ea34;
  *(undefined4 *)((int)this + 8) = 0x11;
  *(undefined4 *)((int)this + 0x18) = param_1;
  return;
}



/* VA 0040b01f */

undefined * __thiscall FUN_0040b01f(void *this,byte param_1)

{
  FUN_0040b0d3();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 0040b03b */

void __thiscall FUN_0040b03b(void *this,int param_1,int param_2)

{
  void *_Dst;

  if (*(undefined **)((int)this + 4) != (undefined *)0x0) {
    FUN_0040f384(*(undefined **)((int)this + 4));
    *(undefined4 *)((int)this + 4) = 0;
  }
  if (param_2 != 0) {
    _Dst = (void *)FUN_0040f348(param_1 << 2);
    *(void **)((int)this + 4) = _Dst;
    _memset(_Dst,0,param_1 << 2);
  }
  *(int *)((int)this + 8) = param_1;
  return;
}



/* VA 0040b081 */

void __fastcall FUN_0040b081(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;

  if (*(int *)(param_1 + 4) != 0) {
    uVar1 = 0;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        for (puVar2 = *(undefined4 **)(*(int *)(param_1 + 4) + uVar1 * 4);
            puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
          FUN_0040ff87(puVar2 + 2);
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(param_1 + 8));
    }
    FUN_0040f384(*(undefined **)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  FUN_0040aaaf(*(undefined4 **)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



/* VA 0040b0d3 */

void FUN_0040b0d3(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041ea34;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040b081((int)extraout_ECX);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d1bc;
  *unaff_FS_OFFSET = uVar1;
  return;
}



/* VA 0040b106 */

undefined4 * __fastcall FUN_0040b106(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined **ppuVar4;
  int iVar5;
  uint uVar6;

  if (*(int *)(param_1 + 0x10) == 0) {
    iVar2 = FUN_0040aa8f((undefined4 *)(param_1 + 0x14),*(int *)(param_1 + 0x18),0x10);
    iVar5 = *(int *)(param_1 + 0x18);
    puVar3 = (undefined4 *)(iVar5 * 0x10 + -0xc + iVar2);
    if (-1 < iVar5 + -1) {
      do {
        *puVar3 = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 **)(param_1 + 0x10) = puVar3;
        puVar3 = puVar3 + -4;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  puVar3 = *(undefined4 **)(param_1 + 0x10);
  uVar6 = 4;
  uVar1 = *puVar3;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  ppuVar4 = FUN_0040fe6d();
  FUN_00403510(puVar3 + 2,ppuVar4,uVar6);
  puVar3[3] = 0;
  return puVar3;
}



/* VA 0040b166 */

undefined4 * __thiscall FUN_0040b166(void *this,byte *param_1,uint *param_2)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  byte *pbVar5;
  undefined4 *puVar6;

  uVar2 = 0;
  bVar4 = *param_1;
  pbVar5 = param_1;
  while (bVar4 != 0) {
    uVar2 = uVar2 * 0x21 + (int)(char)bVar4;
    pbVar1 = pbVar5 + 1;
    pbVar5 = pbVar5 + 1;
    bVar4 = *pbVar1;
  }
  uVar2 = uVar2 % *(uint *)((int)this + 8);
  *param_2 = uVar2;
  if (*(int *)((int)this + 4) != 0) {
    for (puVar6 = *(undefined4 **)(*(int *)((int)this + 4) + uVar2 * 4); puVar6 != (undefined4 *)0x0
        ; puVar6 = (undefined4 *)*puVar6) {
      iVar3 = FUN_00403360((byte *)puVar6[2],param_1);
      if (iVar3 == 0) {
        return puVar6;
      }
    }
  }
  return (undefined4 *)0x0;
}



/* VA 0040b1c0 */

bool __thiscall FUN_0040b1c0(void *this,byte *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;

  puVar1 = FUN_0040b166(this,param_1,(uint *)&param_1);
  if (puVar1 != (undefined4 *)0x0) {
    *param_2 = puVar1[3];
  }
  return puVar1 != (undefined4 *)0x0;
}



/* VA 0040b1e2 */

bool __thiscall FUN_0040b1e2(void *this,byte *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;

  puVar1 = FUN_0040b166(this,param_1,(uint *)&param_1);
  if (puVar1 != (undefined4 *)0x0) {
    *param_2 = puVar1[2];
  }
  return puVar1 != (undefined4 *)0x0;
}



/* VA 0040b204 */

undefined4 * __thiscall FUN_0040b204(void *this,byte *param_1)

{
  undefined4 *puVar1;
  void *local_8;

  local_8 = this;
  puVar1 = FUN_0040b166(this,param_1,(uint *)&local_8);
  if (puVar1 == (undefined4 *)0x0) {
    if (*(int *)((int)this + 4) == 0) {
      FUN_0040b03b(this,*(int *)((int)this + 8),1);
    }
    puVar1 = FUN_0040b106((int)this);
    puVar1[1] = local_8;
    FUN_0040ffdd(puVar1 + 2,(LPCSTR)param_1);
    *puVar1 = *(undefined4 *)(*(int *)((int)this + 4) + (int)local_8 * 4);
    *(undefined4 **)(*(int *)((int)this + 4) + (int)local_8 * 4) = puVar1;
  }
  return puVar1 + 3;
}



/* VA 0040b286 */

void FUN_0040b286(void)

{
  FUN_0040b3ba(&DAT_00428560,0);
  return;
}



/* VA 0040b293 */

void FUN_0040b293(void)

{
  FUN_00402fb0(0x40b29f);
  return;
}



/* VA 0040b2c4 */

void FUN_0040b2c4(void)

{
  FUN_0040b3ba(&DAT_00428620,1);
  return;
}



/* VA 0040b2d1 */

void FUN_0040b2d1(void)

{
  FUN_00402fb0(0x40b2dd);
  return;
}



/* VA 0040b302 */

void FUN_0040b302(void)

{
  FUN_0040b3ba(&DAT_004285a0,0xffffffff);
  return;
}



/* VA 0040b30f */

void FUN_0040b30f(void)

{
  FUN_00402fb0(0x40b31b);
  return;
}



/* VA 0040b340 */

void FUN_0040b340(void)

{
  FUN_0040b3ba(&DAT_004285e0,0xfffffffe);
  return;
}



/* VA 0040b34d */

void FUN_0040b34d(void)

{
  FUN_00402fb0(0x40b359);
  return;
}



/* VA 0040b374 */

undefined4 * __fastcall FUN_0040b374(undefined4 *param_1)

{
  FUN_0040ed8e(param_1);
  *param_1 = &PTR_LAB_0041cd4c;
  _memset(param_1 + 7,0,0x20);
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  return param_1;
}



/* VA 0040b39e */

/* Library Function - Single Match
    public: virtual void * __thiscall CWnd::`scalar deleting destructor'(unsigned int)

   Library: Visual Studio 2003 Release */

void * __thiscall CWnd::_scalar_deleting_destructor_(CWnd *this,uint param_1)

{
  ~CWnd(this);
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 0040b3ba */

undefined4 * __thiscall FUN_0040b3ba(void *this,undefined4 param_1)

{
  FUN_0040ed8e(this);
  *(undefined ***)this = &PTR_LAB_0041cd4c;
  _memset((undefined4 *)((int)this + 0x1c),0,0x20);
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x1c) = param_1;
  return this;
}



/* VA 0040b408 */

undefined4 FUN_0040b408(HWND param_1,int param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  undefined4 uVar2;
  uint dwNewLong;

  uVar1 = GetWindowLongA(param_1,param_2);
  dwNewLong = ~param_3 & uVar1 | param_4;
  if (uVar1 == dwNewLong) {
    uVar2 = 0;
  }
  else {
    SetWindowLongA(param_1,param_2,dwNewLong);
    if (param_5 != 0) {
      SetWindowPos(param_1,(HWND)0x0,0,0,0,0,param_5 | 0x17);
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* VA 0040b457 */

void FUN_0040b457(HWND param_1,uint param_2,uint param_3,uint param_4)

{
  FUN_0040b408(param_1,-0x14,param_2,param_3,param_4);
  return;
}



/* VA 0040b471 */

undefined4 FUN_0040b471(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBP;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc0;
  iVar2 = FUN_0041a9d0(&DAT_00428660,FUN_00401abc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = iVar2;
  puVar5 = (undefined4 *)(iVar2 + 0x34);
  puVar6 = (undefined4 *)(unaff_EBP + -0x40);
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar4 = *(int *)(unaff_EBP + 0x10);
  piVar1 = *(int **)(unaff_EBP + 8);
  *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(unaff_EBP + 0x14);
  uVar3 = *(undefined4 *)(unaff_EBP + 0x18);
  *(int *)(iVar2 + 0x38) = iVar4;
  *(undefined4 *)(iVar2 + 0x40) = uVar3;
  if ((iVar4 == 2) && ((int *)piVar1[0xd] != (int *)0x0)) {
    (**(code **)(*(int *)piVar1[0xd] + 100))(0);
  }
  if (iVar4 == 0x110) {
    FUN_0040b561((int)piVar1,(LPRECT)(unaff_EBP + -0x24),(undefined4 *)(unaff_EBP + 0xc));
  }
  uVar3 = (**(code **)(*piVar1 + 0xa0))
                    (iVar4,*(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x18));
  *(undefined4 *)(unaff_EBP + 8) = uVar3;
  if (iVar4 == 0x110) {
    FUN_0040b584(piVar1,(int *)(unaff_EBP + -0x24),*(uint *)(unaff_EBP + 0xc));
  }
  uVar3 = *(undefined4 *)(unaff_EBP + 8);
  puVar5 = (undefined4 *)(unaff_EBP + -0x40);
  puVar6 = (undefined4 *)(iVar2 + 0x34);
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}



/* VA 0040b561 */

void FUN_0040b561(int param_1,LPRECT param_2,undefined4 *param_3)

{
  undefined4 uVar1;

  GetWindowRect(*(HWND *)(param_1 + 0x1c),param_2);
  uVar1 = FUN_0040eb4e(param_1);
  *param_3 = uVar1;
  return;
}



/* VA 0040b584 */

void FUN_0040b584(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  CWnd *pCVar2;
  int iVar3;
  tagRECT local_14;

  if (((((param_3 & 0x10000000) == 0) &&
       (uVar1 = FUN_0040eb4e((int)param_1), (uVar1 & 0x50000000) == 0)) &&
      (GetWindowRect((HWND)param_1[7],&local_14), *param_2 == local_14.left)) &&
     (param_2[1] == local_14.top)) {
    GetWindow((HWND)param_1[7],4);
    pCVar2 = FUN_0040b6dd();
    if ((pCVar2 != (CWnd *)0x0) && (iVar3 = FUN_0040ecb6((int)pCVar2), iVar3 != 0)) {
      return;
    }
    iVar3 = (**(code **)(*param_1 + 0xb4))();
    if (iVar3 != 0) {
      FUN_0040db9d(param_1,0);
    }
  }
  return;
}



/* VA 0040b5fd */

int FUN_0040b5fd(void)

{
  int iVar1;
  LONG LVar2;
  DWORD DVar3;

  iVar1 = FUN_0041a9d0(&DAT_00428660,FUN_00401abc);
  LVar2 = GetMessageTime();
  *(LONG *)(iVar1 + 0x44) = LVar2;
  DVar3 = GetMessagePos();
  *(int *)(iVar1 + 0x48) = (int)(short)DVar3;
  *(int *)(iVar1 + 0x4c) = (int)(short)(DVar3 >> 0x10);
  return iVar1 + 0x34;
}



/* VA 0040b632 */

void __fastcall FUN_0040b632(int *param_1)

{
  int iVar1;

  iVar1 = FUN_0041a9d0(&DAT_00428660,FUN_00401abc);
  (**(code **)(*param_1 + 0xa8))
            (*(undefined4 *)(iVar1 + 0x38),*(undefined4 *)(iVar1 + 0x3c),
             *(undefined4 *)(iVar1 + 0x40));
  return;
}



/* VA 0040b659 */

void FUN_0040b659(void)

{
  int iVar1;

  iVar1 = FUN_0040b66d();
  if (iVar1 != 0) {
    FUN_00410434(iVar1);
    return;
  }
  return;
}



/* VA 0040b66d */

undefined4 FUN_0040b66d(void)

{
  AFX_MODULE_THREAD_STATE *pAVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  pAVar1 = AfxGetModuleThreadState();
  if ((*(int *)(pAVar1 + 0x14) == 0) && (*(int *)(unaff_EBP + 8) != 0)) {
    uVar2 = FUN_0040f334(&LAB_00411749);
    iVar3 = FUN_0040f348(0x44);
    *(int *)(unaff_EBP + 8) = iVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar3 == 0) {
      pvVar4 = (void *)0x0;
    }
    else {
      pvVar4 = FUN_004102fd();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(void **)(pAVar1 + 0x14) = pvVar4;
    FUN_0040f334(uVar2);
  }
  uVar2 = *(undefined4 *)(pAVar1 + 0x14);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}



/* VA 0040b6dd */

CWnd * FUN_0040b6dd(void)

{
  CHandleMap *pCVar1;
  CWnd *this;

  pCVar1 = (CHandleMap *)FUN_0040b66d();
  this = (CWnd *)FUN_00410359();
  CWnd::AttachControlSite(this,pCVar1);
  return this;
}



/* VA 0040b705 */

undefined4 FUN_0040b705(uint param_1)

{
  void *this;
  undefined4 uVar1;

  this = (void *)FUN_0040b66d();
  uVar1 = 0;
  if (this != (void *)0x0) {
    uVar1 = FUN_0040aec1(this,param_1);
  }
  return uVar1;
}



/* VA 0040b721 */

bool __thiscall FUN_0040b721(void *this,uint param_1)

{
  CHandleMap *this_00;
  undefined4 *puVar1;

  if (param_1 != 0) {
    this_00 = (CHandleMap *)FUN_0040b66d();
    *(uint *)((int)this + 0x1c) = param_1;
    puVar1 = FUN_0040aef4(this_00,param_1);
    *puVar1 = this;
    CWnd::AttachControlSite(this,this_00);
  }
  return param_1 != 0;
}



/* VA 0040b75a */

int __fastcall FUN_0040b75a(int param_1)

{
  int iVar1;
  void *this;

  iVar1 = *(int *)(param_1 + 0x1c);
  if (iVar1 != 0) {
    this = (void *)FUN_0040b66d();
    if (this != (void *)0x0) {
      FUN_0040af44(this,*(uint *)(param_1 + 0x1c));
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  *(undefined4 *)(param_1 + 0x38) = 0;
  return iVar1;
}



/* VA 0040b789 */

undefined4 FUN_0040b789(uint param_1,int param_2)

{
  undefined4 uVar1;

  if (param_2 == 0x360) {
    uVar1 = 1;
  }
  else {
    FUN_0040b705(param_1);
    uVar1 = FUN_0040b471();
  }
  return uVar1;
}



/* VA 0040b7b8 */

undefined * FUN_0040b7b8(void)

{
  return FUN_0040b789;
}



/* VA 0040b7be */

undefined4 FUN_0040b7be(void)

{
  HWND hWnd;
  undefined4 uVar1;
  HANDLE pvVar2;
  CWnd *pCVar3;
  LRESULT LVar4;
  int iVar5;
  CWnd *pCVar6;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  bool bVar7;

  FUN_00402bc0();
  hWnd = *(HWND *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc4;
  pvVar2 = GetPropA(hWnd,"AfxOldWndProc");
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(HANDLE *)(unaff_EBP + -0x18) = pvVar2;
  iVar5 = *(int *)(unaff_EBP + 0xc);
  bVar7 = true;
  if (iVar5 == 6) {
    pCVar3 = FUN_0040b6dd();
    pCVar6 = FUN_0040b6dd();
    FUN_0040b90b((int)pCVar6,*(WPARAM *)(unaff_EBP + 0x10),(int)pCVar3);
  }
  else if (iVar5 == 0x20) {
    pCVar3 = FUN_0040b6dd();
    iVar5 = FUN_0040b96c((int)pCVar3,(int)*(short *)(unaff_EBP + 0x14),
                         *(uint *)(unaff_EBP + 0x14) >> 0x10);
    bVar7 = iVar5 == 0;
  }
  else if (iVar5 == 0x82) {
    SetWindowLongA(hWnd,-4,*(LONG *)(unaff_EBP + -0x18));
    RemovePropA(hWnd,"AfxOldWndProc");
  }
  else if (iVar5 == 0x110) {
    pCVar3 = FUN_0040b6dd();
    FUN_0040b561((int)pCVar3,(LPRECT)(unaff_EBP + -0x30),(undefined4 *)(unaff_EBP + -0x1c));
    bVar7 = false;
    LVar4 = CallWindowProcA(*(WNDPROC *)(unaff_EBP + -0x18),hWnd,0x110,*(WPARAM *)(unaff_EBP + 0x10)
                            ,*(LPARAM *)(unaff_EBP + 0x14));
    *(LRESULT *)(unaff_EBP + -0x14) = LVar4;
    FUN_0040b584((int *)pCVar3,(int *)(unaff_EBP + -0x30),*(uint *)(unaff_EBP + -0x1c));
  }
  if (bVar7) {
    LVar4 = CallWindowProcA(*(WNDPROC *)(unaff_EBP + -0x18),hWnd,*(UINT *)(unaff_EBP + 0xc),
                            *(WPARAM *)(unaff_EBP + 0x10),*(LPARAM *)(unaff_EBP + 0x14));
    *(LRESULT *)(unaff_EBP + -0x14) = LVar4;
  }
  uVar1 = *(undefined4 *)(unaff_EBP + -0x14);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}



/* VA 0040b90b */

void FUN_0040b90b(int param_1,WPARAM param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;

  uVar1 = FUN_0040eb4e(param_1);
  if ((uVar1 & 0x40000000) == 0) {
    iVar2 = FUN_0040cd3c(param_1);
    iVar3 = FUN_0040cd3c(param_3);
    if (iVar2 != iVar3) {
      local_c = *(undefined4 *)(param_1 + 0x1c);
      if (param_3 == 0) {
        local_8 = 0;
      }
      else {
        local_8 = *(undefined4 *)(param_3 + 0x1c);
      }
      SendMessageA(*(HWND *)(iVar2 + 0x1c),0x36e,param_2,(LPARAM)&local_c);
    }
  }
  return;
}



/* VA 0040b96c */

undefined4 FUN_0040b96c(int param_1,int param_2,int param_3)

{
  int iVar1;
  CWnd *pCVar2;
  CWnd *pCVar3;

  if (((param_2 == -2) && (((param_3 == 0x201 || (param_3 == 0x207)) || (param_3 == 0x204)))) &&
     (iVar1 = FUN_0040cd3c(param_1), iVar1 != 0)) {
    GetLastActivePopup(*(HWND *)(iVar1 + 0x1c));
    pCVar2 = FUN_0040b6dd();
    if (pCVar2 != (CWnd *)0x0) {
      GetForegroundWindow();
      pCVar3 = FUN_0040b6dd();
      if ((pCVar2 != pCVar3) && (iVar1 = FUN_0040ecb6((int)pCVar2), iVar1 != 0)) {
        SetForegroundWindow(*(HWND *)(pCVar2 + 0x1c));
        return 1;
      }
    }
  }
  return 0;
}



/* VA 0040b9e4 */

undefined4 FUN_0040b9e4(undefined4 param_1,int param_2,HDC param_3,HWND param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;

  iVar1 = FUN_0041aa65();
  if (((*(HANDLE *)(iVar1 + 4) != (HANDLE)0x0) &&
      ((((param_2 == 0x135 || (param_2 == 0x136)) || (param_2 == 0x138)) ||
       ((param_2 == 0x137 || (param_2 == 0x134)))))) &&
     (iVar2 = FUN_0040da67(param_3,param_4,param_2 + -0x132,*(HANDLE *)(iVar1 + 4),
                           *(COLORREF *)(iVar1 + 8)), iVar2 != 0)) {
    return *(undefined4 *)(iVar1 + 4);
  }
  uVar3 = FUN_0040b7be();
  return uVar3;
}



/* VA 0040ba60 */

LRESULT FUN_0040ba60(int param_1,HWND param_2,int *param_3)

{
  int *this;
  int iVar1;
  LRESULT LVar2;
  int iVar3;
  LONG *pLVar4;
  int iVar5;
  undefined *puVar6;
  undefined *puVar7;
  HANDLE hData;
  HANDLE pvVar8;
  code *dwNewLong;

  iVar1 = FUN_0041a9d0(&DAT_00428660,FUN_00401abc);
  if (param_1 != 3) {
    LVar2 = CallNextHookEx(*(HHOOK *)(iVar1 + 0x2c),param_1,(WPARAM)param_2,(LPARAM)param_3);
    return LVar2;
  }
  this = *(int **)(iVar1 + 0x14);
  if ((this == (int *)0x0) &&
     (((*(byte *)(*param_3 + 0x23) & 0x40) != 0 ||
      (iVar3 = FUN_00419dc2(), *(char *)(iVar3 + 0x14) != '\0')))) goto LAB_0040bbbc;
  if (this == (int *)0x0) {
    hData = (HANDLE)GetWindowLongA(param_2,-4);
    if (hData != (HANDLE)0x0) {
      SetPropA(param_2,"AfxOldWndProc",hData);
      pvVar8 = GetPropA(param_2,"AfxOldWndProc");
      if (pvVar8 == hData) {
        dwNewLong = FUN_0040b9e4;
        if (*(int *)(iVar1 + 0x28) == 0) {
          dwNewLong = FUN_0040b7be;
        }
        SetWindowLongA(param_2,-4,(LONG)dwNewLong);
      }
    }
    goto LAB_0040bbbc;
  }
  FUN_0040b721(this,(uint)param_2);
  iVar3 = *this;
  (**(code **)(iVar3 + 0x58))();
  pLVar4 = (LONG *)(**(code **)(iVar3 + 0x88))();
  if ((((DAT_00428844 == 0) &&
       (iVar5 = FUN_00419dc2(), iVar3 = DAT_00428988, *(char *)(iVar5 + 0x14) == '\0')) &&
      (DAT_00428988 != 0)) &&
     ((*(int *)(DAT_00428988 + 0x20) != 0 && (iVar5 = FUN_0040b471(), iVar5 != 0)))) {
    puVar6 = FUN_0040b7b8();
    puVar7 = (undefined *)GetWindowLongA(param_2,-4);
    (**(code **)(iVar3 + 0x20))(param_2,iVar5);
    if (puVar7 != puVar6) {
      puVar7 = (undefined *)SetWindowLongA(param_2,-4,(LONG)puVar6);
LAB_0040bb67:
      *pLVar4 = (LONG)puVar7;
    }
  }
  else {
    puVar6 = FUN_0040b7b8();
    puVar7 = (undefined *)SetWindowLongA(param_2,-4,(LONG)puVar6);
    if (puVar7 != puVar6) goto LAB_0040bb67;
  }
  *(undefined4 *)(iVar1 + 0x14) = 0;
LAB_0040bbbc:
  LVar2 = CallNextHookEx(*(HHOOK *)(iVar1 + 0x2c),3,(WPARAM)param_2,(LPARAM)param_3);
  iVar3 = FUN_00419dc2();
  if (*(char *)(iVar3 + 0x14) != '\0') {
    UnhookWindowsHookEx(*(HHOOK *)(iVar1 + 0x2c));
    *(undefined4 *)(iVar1 + 0x2c) = 0;
  }
  return LVar2;
}



/* VA 0040bbee */

void FUN_0040bbee(int param_1)

{
  int iVar1;
  DWORD dwThreadId;
  HHOOK pHVar2;

  iVar1 = FUN_0041a9d0(&DAT_00428660,FUN_00401abc);
  if (*(int *)(iVar1 + 0x14) != param_1) {
    if (*(int *)(iVar1 + 0x2c) == 0) {
      dwThreadId = GetCurrentThreadId();
      pHVar2 = SetWindowsHookExA(5,FUN_0040ba60,(HINSTANCE)0x0,dwThreadId);
      *(HHOOK *)(iVar1 + 0x2c) = pHVar2;
      if (pHVar2 == (HHOOK)0x0) {
        FUN_0040a8cd();
      }
    }
    *(int *)(iVar1 + 0x14) = param_1;
  }
  return;
}



/* VA 0040bc3a */

undefined4 FUN_0040bc3a(void)

{
  int iVar1;
  int iVar2;

  iVar1 = FUN_0041a9d0(&DAT_00428660,FUN_00401abc);
  iVar2 = FUN_00419dc2();
  if ((*(char *)(iVar2 + 0x14) != '\0') && (*(HHOOK *)(iVar1 + 0x2c) != (HHOOK)0x0)) {
    UnhookWindowsHookEx(*(HHOOK *)(iVar1 + 0x2c));
    *(undefined4 *)(iVar1 + 0x2c) = 0;
  }
  if (*(int *)(iVar1 + 0x14) != 0) {
    *(undefined4 *)(iVar1 + 0x14) = 0;
    return 0;
  }
  return 1;
}



/* VA 0040bc7c */

bool __thiscall
FUN_0040bc7c(void *this,DWORD param_1,LPCSTR param_2,LPCSTR param_3,DWORD param_4,int param_5,
            int param_6,int param_7,int param_8,HWND param_9,HMENU param_10,LPVOID param_11)

{
  int iVar1;
  int iVar2;
  HWND pHVar3;
  bool bVar4;
  LPVOID local_34;
  HINSTANCE local_30;
  HMENU local_2c;
  HWND local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  DWORD local_14;
  LPCSTR local_10;
  LPCSTR local_c;
  DWORD local_8;

  local_8 = param_1;
  local_c = param_2;
  local_10 = param_3;
  local_14 = param_4;
  local_18 = param_5;
  local_1c = param_6;
  local_20 = param_7;
  local_24 = param_8;
  local_28 = param_9;
  local_2c = param_10;
  iVar1 = FUN_00419dc2();
  local_30 = *(HINSTANCE *)(iVar1 + 8);
  iVar1 = *(int *)this;
  local_34 = param_11;
  iVar2 = (**(code **)(iVar1 + 100))(&local_34);
  if (iVar2 == 0) {
    (**(code **)(iVar1 + 0xac))();
    bVar4 = false;
  }
  else {
    FUN_0040bbee((int)this);
    pHVar3 = CreateWindowExA(local_8,local_c,local_10,local_14,local_18,local_1c,local_20,local_24,
                             local_28,local_2c,local_30,local_34);
    iVar2 = FUN_0040bc3a();
    if (iVar2 == 0) {
      (**(code **)(iVar1 + 0xac))();
    }
    bVar4 = pHVar3 != (HWND)0x0;
  }
  return bVar4;
}



/* VA 0040bd40 */

undefined4 FUN_0040bd40(int param_1)

{
  int iVar1;

  if (*(int *)(param_1 + 0x28) == 0) {
    iVar1 = FUN_00419dc2();
    if ((*(byte *)(iVar1 + 0x18) & 1) == 0) {
      iVar1 = FUN_0040e0b4(1);
    }
    else {
      iVar1 = 1;
    }
    if (iVar1 == 0) {
      return 0;
    }
    *(char **)(param_1 + 0x28) = "AfxWnd42s";
  }
  return 1;
}



/* VA 0040bd72 */

void __thiscall
FUN_0040bd72(void *this,LPCSTR param_1,LPCSTR param_2,uint param_3,int *param_4,int param_5,
            HMENU param_6,LPVOID param_7)

{
  HWND pHVar1;

  if (param_5 == 0) {
    pHVar1 = (HWND)0x0;
  }
  else {
    pHVar1 = *(HWND *)(param_5 + 0x1c);
  }
  FUN_0040bc7c(this,0,param_1,param_2,param_3 | 0x40000000,*param_4,param_4[1],param_4[2] - *param_4
               ,param_4[3] - param_4[1],pHVar1,param_6,param_7);
  return;
}



/* VA 0040bdbe */

/* Library Function - Single Match
    public: virtual __thiscall CWnd::~CWnd(void)

   Library: Visual Studio 2003 Release */

void __thiscall CWnd::~CWnd(CWnd *this)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041cd4c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((((extraout_ECX[7] != 0) && (extraout_ECX != (undefined4 *)&DAT_00428560)) &&
      (extraout_ECX != (undefined4 *)&DAT_00428620)) &&
     ((extraout_ECX != (undefined4 *)&DAT_004285a0 && (extraout_ECX != (undefined4 *)&DAT_004285e0))
     )) {
    FUN_0040bf81((int)extraout_ECX);
  }
  if ((int *)extraout_ECX[0xd] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[0xd] + 4))(1);
  }
  iVar1 = extraout_ECX[0xe];
  if ((iVar1 != 0) && (*(undefined4 **)(iVar1 + 0x24) == extraout_ECX)) {
    *(undefined4 *)(iVar1 + 0x24) = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0040edca();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 0040be3a */

void __fastcall FUN_0040be3a(int *param_1)

{
  if ((int *)param_1[0xd] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0xd] + 4))(1);
  }
  param_1[0xd] = 0;
  FUN_0040b632(param_1);
  return;
}



/* VA 0040be58 */

void __fastcall FUN_0040be58(int *param_1)

{
  bool bVar1;
  CWinThread *pCVar2;
  int iVar3;
  undefined3 extraout_var;
  int iVar4;
  LONG LVar5;
  LONG LVar6;
  int *piVar7;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;

  pCVar2 = AfxGetThread();
  if (pCVar2 == (CWinThread *)0x0) goto LAB_0040bea3;
  if (*(int **)(pCVar2 + 0x1c) == param_1) {
    iVar3 = FUN_00419dc2();
    if (*(char *)(iVar3 + 0x14) == '\0') {
      iVar3 = FUN_00419dc2();
      if (pCVar2 == *(CWinThread **)(iVar3 + 4)) {
        bVar1 = FUN_00417a9c();
        if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_0040be98;
      }
      AfxPostQuitMessage(0);
    }
LAB_0040be98:
    *(undefined4 *)(pCVar2 + 0x1c) = 0;
  }
  if (*(int **)(pCVar2 + 0x20) == param_1) {
    *(undefined4 *)(pCVar2 + 0x20) = 0;
  }
LAB_0040bea3:
  if ((int *)param_1[0xc] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0xc] + 0x58))();
    param_1[0xc] = 0;
  }
  if ((int *)param_1[0xd] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0xd] + 4))(1);
  }
  param_1[0xd] = 0;
  if ((*(byte *)(param_1 + 9) & 1) != 0) {
    iVar3 = FUN_00419a6f();
    iVar3 = *(int *)(iVar3 + 0xcc);
    if (iVar3 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar3 + 0x1c);
    }
    if (iVar4 != 0) {
      _memset(&local_30,0,0x2c);
      local_28 = param_1[7];
      local_30 = 0x2c;
      local_2c = 1;
      local_24 = local_28;
      SendMessageA(*(HWND *)(iVar3 + 0x1c),0x405,0,(LPARAM)&local_30);
    }
  }
  LVar5 = GetWindowLongA((HWND)param_1[7],-4);
  FUN_0040b632(param_1);
  LVar6 = GetWindowLongA((HWND)param_1[7],-4);
  if (LVar6 == LVar5) {
    piVar7 = (int *)(**(code **)(*param_1 + 0x88))();
    if (*piVar7 != 0) {
      SetWindowLongA((HWND)param_1[7],-4,*piVar7);
    }
  }
  FUN_0040b75a((int)param_1);
  (**(code **)(*param_1 + 0xac))();
  return;
}



/* VA 0040bf81 */

BOOL __fastcall FUN_0040bf81(int param_1)

{
  void *this;
  int iVar1;
  BOOL BVar2;

  if (*(int *)(param_1 + 0x1c) == 0) {
    return 0;
  }
  this = (void *)FUN_0040b66d();
  iVar1 = FUN_0040aec1(this,*(uint *)(param_1 + 0x1c));
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    BVar2 = DestroyWindow(*(HWND *)(param_1 + 0x1c));
  }
  else {
    BVar2 = (**(code **)(**(int **)(param_1 + 0x38) + 0x58))();
  }
  if (iVar1 == 0) {
    FUN_0040b75a(param_1);
  }
  return BVar2;
}



/* VA 0040bfce */

void __thiscall FUN_0040bfce(void *this,UINT param_1,WPARAM param_2,LPARAM param_3)

{
  int *piVar1;
  WNDPROC lpPrevWndFunc;

  lpPrevWndFunc = *(WNDPROC *)((int)this + 0x28);
  if (lpPrevWndFunc == (WNDPROC)0x0) {
    piVar1 = (int *)(**(code **)(*(int *)this + 0x88))();
    lpPrevWndFunc = (WNDPROC)*piVar1;
    if (lpPrevWndFunc == (WNDPROC)0x0) {
      DefWindowProcA(*(HWND *)((int)this + 0x1c),param_1,param_2,param_3);
      return;
    }
  }
  CallWindowProcA(lpPrevWndFunc,*(HWND *)((int)this + 0x1c),param_1,param_2,param_3);
  return;
}



/* VA 0040c019 */

undefined4 __thiscall FUN_0040c019(void *this,undefined4 param_1)

{
  int iVar1;

  iVar1 = FUN_00419dc2();
  if (*(code **)(iVar1 + 0x1034) != (code *)0x0) {
    (**(code **)(iVar1 + 0x1034))(param_1,this);
  }
  return 0;
}



/* VA 0040c038 */

void FUN_0040c038(int param_1)

{
  int iVar1;
  int *piVar2;
  SHORT SVar3;
  int iVar4;
  int iVar5;

  iVar4 = FUN_00419a6f();
  iVar1 = *(int *)(iVar4 + 0xcc);
  if (iVar1 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(iVar1 + 0x1c);
  }
  if (iVar5 != 0) {
    SendMessageA(*(HWND *)(iVar1 + 0x1c),0x401,0,0);
  }
  piVar2 = *(int **)(iVar4 + 0x108);
  if ((param_1 != 0) && (piVar2 != (int *)0x0)) {
    SVar3 = GetKeyState(1);
    if (-1 < SVar3) {
      (**(code **)(*piVar2 + 0xe4))(0xffffffff);
    }
  }
  return;
}



/* VA 0040c095 */

uint __thiscall FUN_0040c095(void *this,LONG param_1,LONG param_2,uint *param_3)

{
  HWND hWnd;
  uint uVar1;
  uint uVar2;

  hWnd = FUN_004115b6(*(HWND *)((int)this + 0x1c),param_1,param_2);
  if (hWnd == (HWND)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = GetDlgCtrlID(hWnd);
    uVar1 = uVar1 & 0xffff;
    if ((param_3 != (uint *)0x0) && (0x2b < *param_3)) {
      uVar2 = *(uint *)((int)this + 0x1c);
      param_3[1] = param_3[1] | 1;
      param_3[9] = 0xffffffff;
      param_3[2] = uVar2;
      param_3[3] = (uint)hWnd;
      uVar2 = SendMessageA(hWnd,0x87,0,0);
      if ((uVar2 & 0x2000) == 0) {
        param_3[1] = param_3[1] | 0x80000002;
      }
    }
  }
  return uVar1;
}



/* VA 0040c106 */

void __thiscall FUN_0040c106(void *this,void *param_1)

{
  int iVar1;
  LPSTR lpString;
  int nMaxCount;

  if (*(int **)((int)this + 0x38) == (int *)0x0) {
    iVar1 = GetWindowTextLengthA(*(HWND *)((int)this + 0x1c));
    nMaxCount = iVar1 + 1;
    lpString = (LPSTR)FUN_0041007b(param_1,iVar1);
    GetWindowTextA(*(HWND *)((int)this + 0x1c),lpString,nMaxCount);
    FUN_00410053(param_1,-1);
  }
  else {
    (**(code **)(**(int **)((int)this + 0x38) + 0x90))(param_1);
  }
  return;
}



/* VA 0040c14e */

void __thiscall FUN_0040c14e(void *this,undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;

  if (*param_2 == 1) {
    piVar1 = (int *)FUN_0040fb8b(param_2[5]);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x14))(param_2);
      return;
    }
  }
  else {
    iVar2 = FUN_0040d4ff();
    if (iVar2 != 0) {
      return;
    }
  }
  FUN_0040b632(this);
  return;
}



/* VA 0040c18b */

undefined4 __thiscall FUN_0040c18b(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;

  iVar1 = FUN_0040d4ff();
  if (iVar1 == 0) {
    param_2 = FUN_0040b632(this);
  }
  return param_2;
}



/* VA 0040c1d5 */

void * __thiscall FUN_0040c1d5(void *this,undefined4 param_1,void *param_2)

{
  int iVar1;

  if ((param_2 == (void *)0x0) || (iVar1 = FUN_0040d4d2(param_2,&param_2), iVar1 == 0)) {
    param_2 = (void *)FUN_0040b632(this);
  }
  return param_2;
}



/* VA 0040c200 */

void * __thiscall FUN_0040c200(void *this,undefined4 param_1,void *param_2)

{
  int iVar1;

  if ((param_2 == (void *)0x0) || (iVar1 = FUN_0040d4d2(param_2,&param_2), iVar1 == 0)) {
    param_2 = (void *)FUN_0040b632(this);
  }
  return param_2;
}



/* VA 0040c22b */

void __thiscall FUN_0040c22b(void *this,undefined4 param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  CWnd *this_00;

  if (*param_2 == 1) {
    iVar1 = FUN_0041a9d0(&DAT_00428660,FUN_00401abc);
    if (*(HWND *)(iVar1 + 0x50) != *(HWND *)((int)this + 0x1c)) {
      GetMenu(*(HWND *)((int)this + 0x1c));
    }
    iVar1 = FUN_0040fb75();
    piVar2 = (int *)FUN_0040c2a4(iVar1,param_2[2]);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x18))(param_2);
    }
  }
  else {
    this_00 = FUN_0040cf04(*(HWND *)((int)this + 0x1c),param_2[1],1);
    if ((this_00 != (CWnd *)0x0) && (iVar1 = FUN_0040d4d2(this_00,0), iVar1 != 0)) {
      return;
    }
  }
  FUN_0040b632(this);
  return;
}



/* VA 0040c2a4 */

int __cdecl FUN_0040c2a4(int param_1,UINT param_2)

{
  int iVar1;
  int iVar2;
  UINT UVar3;
  int nPos;

  iVar1 = GetMenuItemCount(*(HMENU *)(param_1 + 4));
  nPos = 0;
  if (0 < iVar1) {
    do {
      GetSubMenu(*(HMENU *)(param_1 + 4),nPos);
      iVar2 = FUN_0040fb75();
      if (iVar2 == 0) {
        UVar3 = GetMenuItemID(*(HMENU *)(param_1 + 4),nPos);
        if (UVar3 == param_2) {
          iVar1 = FUN_0040fb8b(*(uint *)(param_1 + 4));
          return iVar1;
        }
      }
      else {
        iVar2 = FUN_0040c2a4(iVar2,param_2);
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      nPos = nPos + 1;
    } while (nPos < iVar1);
  }
  return 0;
}



/* VA 0040c307 */

undefined4 FUN_0040c307(void)

{
  WNDCLASSA *lpWndClass;
  ATOM AVar1;
  BOOL BVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  lpWndClass = *(WNDCLASSA **)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc4;
  BVar2 = GetClassInfoA(lpWndClass->hInstance,lpWndClass->lpszClassName,
                        (LPWNDCLASSA)(unaff_EBP + -0x38));
  if (BVar2 == 0) {
    AVar1 = RegisterClassA(lpWndClass);
    if (AVar1 == 0) {
      uVar3 = 0;
      goto LAB_0040c389;
    }
    iVar4 = FUN_00419dc2();
    if (*(char *)(iVar4 + 0x14) != '\0') {
      FUN_0041adc3(1);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar4 = FUN_00419dc2();
      lstrcatA((LPSTR)(iVar4 + 0x34),lpWndClass->lpszClassName);
      *(undefined1 *)(unaff_EBP + 9) = 0;
      *(undefined1 *)(unaff_EBP + 8) = 10;
      lstrcatA((LPSTR)(iVar4 + 0x34),(LPCSTR)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0041ae33(1);
    }
  }
  uVar3 = 1;
LAB_0040c389:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}



/* VA 0040c3b0 */

LPSTR FUN_0040c3b0(UINT param_1,HCURSOR param_2,HBRUSH param_3,HICON param_4)

{
  HINSTANCE hInstance;
  int iVar1;
  BOOL BVar2;
  LPSTR lpClassName;
  tagWNDCLASSA local_2c;

  iVar1 = FUN_00419a6f();
  lpClassName = (LPSTR)(iVar1 + 0x58);
  iVar1 = FUN_00419dc2();
  hInstance = *(HINSTANCE *)(iVar1 + 8);
  if (((param_2 == (HCURSOR)0x0) && (param_3 == (HBRUSH)0x0)) && (param_4 == (HICON)0x0)) {
    wsprintfA(lpClassName,"Afx:%x:%x",hInstance,param_1);
  }
  else {
    wsprintfA(lpClassName,"Afx:%x:%x:%x:%x:%x",hInstance,param_1,param_2,param_3,param_4);
  }
  BVar2 = GetClassInfoA(hInstance,lpClassName,&local_2c);
  if (BVar2 == 0) {
    local_2c.style = param_1;
    local_2c.lpfnWndProc = DefWindowProcA_exref;
    local_2c.cbWndExtra = 0;
    local_2c.cbClsExtra = 0;
    local_2c.lpszMenuName = (LPCSTR)0x0;
    local_2c.hIcon = param_4;
    local_2c.hCursor = param_2;
    local_2c.hbrBackground = param_3;
    local_2c.hInstance = hInstance;
    local_2c.lpszClassName = lpClassName;
    iVar1 = FUN_0040c307();
    if (iVar1 == 0) {
      FUN_0041149b();
    }
  }
  return lpClassName;
}



/* VA 0040c464 */

void __thiscall FUN_0040c464(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;

  local_c = param_1;
  local_10 = param_2;
  iVar1 = FUN_0040b5fd();
  local_8 = *(int *)(iVar1 + 4) + -0x132;
  (**(code **)(*(int *)this + 0xa0))(0x19,0,&local_10);
  return;
}



/* VA 0040c4a0 */

void FUN_0040c4a0(void)

{
  int iVar1;
  int iVar2;
  HWND hWnd;
  BOOL BVar3;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  iVar1 = FUN_00419dc2();
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar1 + 4);
  FUN_00419dc2();
  FUN_0040f066();
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = (**(code **)(iVar1 + 0xb8))();
  if (iVar2 != 0) {
    (**(code **)(iVar1 + 0xf8))();
  }
  SendMessageA((HWND)extraout_ECX[7],0x1f,0,0);
  FUN_0040cf7d((HWND)extraout_ECX[7],0x1f,0,0,1,1);
  iVar1 = FUN_0040cd3c((int)extraout_ECX);
  SendMessageA(*(HWND *)(iVar1 + 0x1c),0x1f,0,0);
  FUN_0040cf7d(*(HWND *)(iVar1 + 0x1c),0x1f,0,0,1,1);
  hWnd = GetCapture();
  if (hWnd != (HWND)0x0) {
    SendMessageA(hWnd,0x1f,0,0);
  }
  BVar3 = WinHelpA(*(HWND *)(iVar1 + 0x1c),*(LPCSTR *)(*(int *)(unaff_EBP + -0x10) + 0x8c),
                   *(UINT *)(unaff_EBP + 0xc),*(ULONG_PTR *)(unaff_EBP + 8));
  if (BVar3 == 0) {
    FUN_00412862();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00419dc2();
  FUN_0040f07b();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 0040c586 */

/* Library Function - Single Match
    struct AFX_MSGMAP_ENTRY const * __stdcall AfxFindMessageEntry(struct AFX_MSGMAP_ENTRY const
   *,unsigned int,unsigned int,unsigned int)

   Library: Visual Studio */

AFX_MSGMAP_ENTRY *
AfxFindMessageEntry(AFX_MSGMAP_ENTRY *param_1,uint param_2,uint param_3,uint param_4)

{
  while( true ) {
    if (*(int *)(param_1 + 0x10) == 0) {
      return (AFX_MSGMAP_ENTRY *)0x0;
    }
    if ((((param_2 == *(uint *)param_1) && (param_3 == *(uint *)(param_1 + 4))) &&
        (*(uint *)(param_1 + 8) <= param_4)) && (param_4 <= *(uint *)(param_1 + 0xc))) break;
    param_1 = param_1 + 0x18;
  }
  return param_1;
}



/* VA 0040c5c6 */

undefined4 __thiscall
FUN_0040c5c6(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;

  local_8 = 0;
  iVar1 = *(int *)this;
  iVar2 = (**(code **)(iVar1 + 0xa4))(param_1,param_2,param_3,&local_8);
  if (iVar2 == 0) {
    local_8 = (**(code **)(iVar1 + 0xa8))(param_1,param_2,param_3);
  }
  return local_8;
}



/* VA 0040c608 */

/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined4 FUN_0040c608(void)

{
  code *pcVar1;
  short sVar2;
  int iVar3;
  CWnd *pCVar4;
  uint uVar5;
  int iVar6;
  AFX_MSGMAP_ENTRY *pAVar7;
  DWORD DVar8;
  CWnd *pCVar9;
  int *extraout_ECX;
  uint uVar10;
  CWnd *pCVar11;
  int unaff_EBP;
  short sVar12;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar13;

  FUN_00402bc0();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  uVar5 = *(uint *)(unaff_EBP + 8);
  if (uVar5 == 0x111) {
    iVar3 = (**(code **)(*extraout_ECX + 0x80))
                      (*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
    if (iVar3 != 0) {
LAB_0040ca5c:
      *(undefined4 *)(unaff_EBP + -0x10) = 1;
      goto switchD_0040c7d5_caseD_26;
    }
LAB_0040c78a:
    uVar13 = 0;
    goto LAB_0040c78c;
  }
  if (uVar5 == 0x4e) {
    if (**(int **)(unaff_EBP + 0x10) != 0) {
      iVar3 = (**(code **)(*extraout_ECX + 0x84))
                        (*(undefined4 *)(unaff_EBP + 0xc),*(int **)(unaff_EBP + 0x10),
                         unaff_EBP + -0x10);
LAB_0040ca80:
      if (iVar3 != 0) goto switchD_0040c7d5_caseD_26;
    }
    goto LAB_0040c78a;
  }
  pCVar9 = *(CWnd **)(unaff_EBP + 0x10);
  if (uVar5 == 6) {
    pCVar4 = FUN_0040b6dd();
    FUN_0040b90b((int)extraout_ECX,*(WPARAM *)(unaff_EBP + 0xc),(int)pCVar4);
  }
  sVar12 = (short)pCVar9;
  if ((uVar5 == 0x20) &&
     (iVar3 = FUN_0040b96c((int)extraout_ECX,(int)sVar12,(uint)pCVar9 >> 0x10), iVar3 != 0))
  goto LAB_0040ca5c;
  uVar13 = (**(code **)(*extraout_ECX + 0x30))();
  *(undefined4 *)(unaff_EBP + -0x14) = uVar13;
  FUN_0041adc3(7);
  uVar10 = *(uint *)(unaff_EBP + 8);
  uVar5 = uVar5 & 0x1ff ^ *(uint *)(unaff_EBP + -0x14) & 0x1ff;
  iVar3 = uVar5 * 0xc;
  iVar6 = *(int *)(unaff_EBP + -0x14);
  if ((uVar10 != *(uint *)(&DAT_00426d60 + uVar5 * 0xc)) ||
     (iVar6 != *(int *)(&DAT_00426d68 + iVar3))) {
    *(uint *)(&DAT_00426d60 + iVar3) = uVar10;
    *(int *)(&DAT_00426d68 + iVar3) = iVar6;
    if (iVar6 != 0) {
      while( true ) {
        if (uVar10 < 0xc000) {
          pAVar7 = AfxFindMessageEntry(*(AFX_MSGMAP_ENTRY **)(iVar6 + 4),uVar10,0,0);
          *(AFX_MSGMAP_ENTRY **)(unaff_EBP + 0x10) = pAVar7;
          if (pAVar7 != (AFX_MSGMAP_ENTRY *)0x0) {
            *(AFX_MSGMAP_ENTRY **)(&DAT_00426d64 + iVar3) = pAVar7;
            FUN_0041ae33(7);
            iVar3 = *(int *)(unaff_EBP + 0x10);
            goto LAB_0040c7aa;
          }
        }
        else {
          pAVar7 = AfxFindMessageEntry(*(AFX_MSGMAP_ENTRY **)(iVar6 + 4),0xc000,0,0);
          *(AFX_MSGMAP_ENTRY **)(unaff_EBP + 0x10) = pAVar7;
          if (pAVar7 != (AFX_MSGMAP_ENTRY *)0x0) {
            while( true ) {
              if (**(int **)(pAVar7 + 0x10) == *(int *)(unaff_EBP + 8)) {
                *(AFX_MSGMAP_ENTRY **)(&DAT_00426d64 + iVar3) = pAVar7;
                FUN_0041ae33(7);
                iVar3 = *(int *)(unaff_EBP + 0x10);
                goto LAB_0040ca96;
              }
              pAVar7 = AfxFindMessageEntry(pAVar7 + 0x18,0xc000,0,0);
              *(AFX_MSGMAP_ENTRY **)(unaff_EBP + 0x10) = pAVar7;
              if (pAVar7 == (AFX_MSGMAP_ENTRY *)0x0) break;
              pAVar7 = *(AFX_MSGMAP_ENTRY **)(unaff_EBP + 0x10);
            }
          }
        }
        iVar6 = **(int **)(unaff_EBP + -0x14);
        *(int *)(unaff_EBP + -0x14) = iVar6;
        if (iVar6 == 0) break;
        uVar10 = *(uint *)(unaff_EBP + 8);
        iVar6 = *(int *)(unaff_EBP + -0x14);
      }
    }
    *(undefined4 *)(&DAT_00426d64 + iVar3) = 0;
    FUN_0041ae33(7);
    goto LAB_0040c78a;
  }
  iVar3 = *(int *)(&DAT_00426d64 + iVar3);
  *(int *)(unaff_EBP + 0x10) = iVar3;
  FUN_0041ae33(7);
  if (iVar3 == 0) goto LAB_0040c78a;
  if (0xbfff < *(uint *)(unaff_EBP + 8)) {
LAB_0040ca96:
    uVar13 = (**(code **)(iVar3 + 0x14))(*(undefined4 *)(unaff_EBP + 0xc),pCVar9);
    goto LAB_0040ca9f;
  }
LAB_0040c7aa:
  iVar6 = *(int *)(unaff_EBP + 0x10);
  pcVar1 = *(code **)(iVar3 + 0x14);
  iVar3 = *(int *)(iVar6 + 0x10);
  if (*(int *)(iVar6 + 8) == 0x1a) {
    DVar8 = GetVersion();
    iVar6 = *(int *)(unaff_EBP + 0x10);
    iVar3 = (-(uint)((byte)DVar8 < 4) & 0xfffffff0) + 0x2f;
  }
  sVar2 = (short)((uint)pCVar9 >> 0x10);
  switch(iVar3) {
  case 1:
    pCVar9 = (CWnd *)FUN_00410b14();
    goto LAB_0040c8e0;
  case 2:
    pCVar9 = *(CWnd **)(unaff_EBP + 0xc);
    goto LAB_0040c8e0;
  case 3:
  case 8:
    uVar5 = (uint)pCVar9 >> 0x10;
    pCVar9 = (CWnd *)(int)sVar12;
    pCVar4 = FUN_0040b6dd();
    goto LAB_0040c8fb;
  case 4:
    FUN_00410a60((undefined4 *)(unaff_EBP + -0x24));
    uVar5 = *(uint *)(pCVar9 + 4);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(uint *)(unaff_EBP + -0x20) = uVar5;
    FUN_0040b374((undefined4 *)(unaff_EBP + -0x60));
    uVar5 = *(uint *)pCVar9;
    uVar10 = *(uint *)(pCVar9 + 8);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(uint *)(unaff_EBP + -0x44) = uVar5;
    iVar3 = FUN_0040b705(uVar5);
    if (iVar3 == 0) {
      if ((extraout_ECX[0xd] != 0) &&
         (iVar3 = FUN_0040aec1((void *)(extraout_ECX[0xd] + 0x20),*(uint *)(unaff_EBP + -0x44)),
         iVar3 != 0)) {
        *(int *)(unaff_EBP + -0x28) = iVar3;
      }
      iVar3 = unaff_EBP + -0x60;
    }
    uVar13 = (*pcVar1)(unaff_EBP + -0x24,iVar3,uVar10);
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x44) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = uVar13;
    CWnd::~CWnd((CWnd *)(unaff_EBP + -0x60));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    goto LAB_0040c8a2;
  case 5:
    FUN_00410a60((undefined4 *)(unaff_EBP + -0x24));
    uVar5 = *(uint *)(pCVar9 + 8);
    *(uint *)(unaff_EBP + -0x20) = *(uint *)(pCVar9 + 4);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    uVar13 = (*pcVar1)(unaff_EBP + -0x24,uVar5);
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x10) = uVar13;
LAB_0040c8a2:
    FUN_00410b92();
    goto switchD_0040c7d5_caseD_26;
  case 6:
    uVar5 = *(uint *)(unaff_EBP + 0xc) >> 0x10;
    pCVar9 = FUN_0040b6dd();
    goto LAB_0040c8f6;
  case 7:
    pCVar9 = (CWnd *)(*(uint *)(unaff_EBP + 0xc) >> 0x10);
    pCVar4 = (CWnd *)(uint)*(ushort *)(unaff_EBP + 0xc);
    goto LAB_0040ca11;
  case 9:
  case 0x2a:
LAB_0040c8e0:
    uVar13 = (*pcVar1)(pCVar9);
    goto LAB_0040ca9f;
  case 10:
  case 0x21:
    pCVar4 = *(CWnd **)(unaff_EBP + 0xc);
    goto LAB_0040ca11;
  case 0xb:
    uVar5 = FUN_0040fb75();
    pCVar9 = (CWnd *)(*(uint *)(unaff_EBP + 0xc) >> 0x10);
LAB_0040c8f6:
    pCVar4 = (CWnd *)(uint)*(ushort *)(unaff_EBP + 0xc);
LAB_0040c8fb:
    uVar13 = (*pcVar1)(pCVar4,pCVar9,uVar5);
    goto LAB_0040ca9f;
  case 0xc:
    (*pcVar1)();
    goto switchD_0040c7d5_caseD_26;
  case 0xd:
    pCVar9 = *(CWnd **)(unaff_EBP + 0xc);
    break;
  case 0xe:
  case 0x12:
  case 0x25:
  case 0x2f:
    goto LAB_0040ca21;
  case 0xf:
    pCVar9 = (CWnd *)(int)sVar2;
    pCVar4 = (CWnd *)(int)sVar12;
    goto LAB_0040ca24;
  case 0x10:
  case 0x11:
    pCVar11 = (CWnd *)((uint)pCVar9 >> 0x10);
    pCVar4 = (CWnd *)((uint)pCVar9 & 0xffff);
    goto LAB_0040ca4a;
  case 0x13:
    pCVar11 = FUN_0040b6dd();
    pCVar4 = FUN_0040b6dd();
    pCVar9 = (CWnd *)(uint)((CWnd *)extraout_ECX[7] == pCVar9);
    goto LAB_0040ca4e;
  case 0x14:
    pCVar9 = (CWnd *)FUN_00410b14();
    break;
  case 0x15:
    pCVar9 = (CWnd *)FUN_0040fb75();
    break;
  case 0x16:
    pCVar11 = (CWnd *)((uint)pCVar9 >> 0x10);
    pCVar4 = (CWnd *)((uint)pCVar9 & 0xffff);
    pCVar9 = (CWnd *)FUN_0040fb75();
    goto LAB_0040ca4e;
  case 0x17:
    goto LAB_0040c983;
  case 0x18:
    pCVar11 = (CWnd *)((uint)pCVar9 >> 0x10);
    pCVar4 = (CWnd *)((uint)pCVar9 & 0xffff);
    goto LAB_0040c9a3;
  case 0x19:
    pCVar4 = (CWnd *)(int)sVar12;
    pCVar11 = (CWnd *)(int)sVar2;
LAB_0040c9a3:
    pCVar9 = FUN_0040b6dd();
    goto LAB_0040ca4e;
  case 0x1a:
    pCVar4 = FUN_0040b6dd();
    goto LAB_0040ca24;
  case 0x1b:
    pCVar9 = FUN_0040b6dd();
LAB_0040ca21:
    pCVar4 = *(CWnd **)(unaff_EBP + 0xc);
    goto LAB_0040ca24;
  case 0x1c:
    pCVar11 = (CWnd *)(*(uint *)(unaff_EBP + 0xc) >> 0x10);
    pCVar4 = FUN_0040b6dd();
    goto LAB_0040ca38;
  case 0x1d:
  case 0x1e:
    pCVar4 = (CWnd *)(int)(short)*(undefined4 *)(unaff_EBP + 0xc);
    iVar3 = *(int *)(iVar6 + 0x10);
    *(CWnd **)(unaff_EBP + 8) = pCVar4;
    pCVar9 = (CWnd *)(int)(short)((uint)*(undefined4 *)(unaff_EBP + 0xc) >> 0x10);
    *(CWnd **)(unaff_EBP + 0xc) = pCVar9;
    if (iVar3 == 0x1d) {
      pCVar11 = FUN_0040b6dd();
      pCVar4 = *(CWnd **)(unaff_EBP + 0xc);
      pCVar9 = *(CWnd **)(unaff_EBP + 8);
      goto LAB_0040ca4e;
    }
LAB_0040ca24:
    (*pcVar1)(pCVar4,pCVar9);
    goto switchD_0040c7d5_caseD_26;
  case 0x1f:
  case 0x24:
    break;
  case 0x20:
  case 0x2b:
    (*pcVar1)(*(undefined4 *)(unaff_EBP + 0xc),pCVar9);
    goto LAB_0040ca5c;
  case 0x22:
    pCVar4 = (CWnd *)(int)sVar12;
    pCVar9 = (CWnd *)(int)sVar2;
    goto LAB_0040ca11;
  case 0x23:
    uVar13 = (*pcVar1)();
    goto LAB_0040ca9f;
  default:
    goto switchD_0040c7d5_caseD_26;
  case 0x2c:
LAB_0040c983:
    pCVar9 = FUN_0040b6dd();
    break;
  case 0x2d:
    pCVar4 = FUN_0040b6dd();
LAB_0040ca11:
    uVar13 = (*pcVar1)(pCVar4,pCVar9);
LAB_0040ca9f:
    *(undefined4 *)(unaff_EBP + -0x10) = uVar13;
    goto switchD_0040c7d5_caseD_26;
  case 0x2e:
    iVar3 = (*pcVar1)(*(undefined2 *)(unaff_EBP + 0xc),*(uint *)(unaff_EBP + 0xc) >> 0x10,
                      (uint)pCVar9 & 0xffff,(uint)pCVar9 >> 0x10);
    *(int *)(unaff_EBP + -0x10) = iVar3;
    goto LAB_0040ca80;
  case 0x30:
    pCVar4 = (CWnd *)(*(uint *)(unaff_EBP + 0xc) >> 0x10);
    pCVar11 = pCVar9;
LAB_0040ca38:
    pCVar9 = (CWnd *)(uint)*(ushort *)(unaff_EBP + 0xc);
    goto LAB_0040ca4e;
  case 0x31:
    pCVar4 = (CWnd *)(int)sVar12;
    pCVar11 = (CWnd *)(int)sVar2;
LAB_0040ca4a:
    pCVar9 = *(CWnd **)(unaff_EBP + 0xc);
LAB_0040ca4e:
    (*pcVar1)(pCVar9,pCVar4,pCVar11);
    goto switchD_0040c7d5_caseD_26;
  }
  (*pcVar1)(pCVar9);
switchD_0040c7d5_caseD_26:
  if (*(undefined4 **)(unaff_EBP + 0x14) != (undefined4 *)0x0) {
    **(undefined4 **)(unaff_EBP + 0x14) = *(undefined4 *)(unaff_EBP + -0x10);
  }
  uVar13 = 1;
LAB_0040c78c:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar13;
}



/* VA 0040cb7a */

CCmdUI * __fastcall FUN_0040cb7a(CCmdUI *param_1)

{
  CCmdUI::CCmdUI(param_1);
  *(undefined ***)param_1 = &PTR_LAB_0041ce34;
  *(undefined4 *)(param_1 + 0x28) = 1;
  return param_1;
}



/* VA 0040cbad */

undefined4 __thiscall FUN_0040cbad(void *this,uint param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  CCmdUI local_30 [4];
  uint local_2c;
  int local_8;

  uVar3 = param_1 & 0xffff;
  param_1 = param_1 >> 0x10;
  if (param_2 == 0) {
    if (uVar3 == 0) {
      return 0;
    }
    FUN_0040cb7a(local_30);
    local_2c = uVar3;
    (**(code **)(*(int *)this + 0x14))(uVar3,0xffffffff,local_30,0);
    if (local_8 != 0) {
      param_1 = 0;
LAB_0040cbf1:
      uVar1 = (**(code **)(*(int *)this + 0x14))(uVar3,param_1,0,0);
      return uVar1;
    }
  }
  else {
    iVar2 = FUN_0041a9d0(&DAT_00428660,FUN_00401abc);
    if ((*(int *)(iVar2 + 0xb8) != *(int *)((int)this + 0x1c)) &&
       (iVar2 = FUN_0040d4ff(), iVar2 == 0)) {
      if (uVar3 == 0) {
        return 0;
      }
      goto LAB_0040cbf1;
    }
  }
  return 1;
}



/* VA 0040cc39 */

undefined4 __thiscall
FUN_0040cc39(void *this,undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_10;
  undefined4 *local_c;
  uint local_8;

  local_8 = GetDlgCtrlID((HWND)*param_2);
  local_8 = local_8 & 0xffff;
  uVar1 = param_2[2];
  iVar2 = FUN_0041a9d0(&DAT_00428660,FUN_00401abc);
  if ((*(int *)(iVar2 + 0xb8) != *(int *)((int)this + 0x1c)) && (iVar2 = FUN_0040d4ff(), iVar2 == 0)
     ) {
    local_10 = param_3;
    local_c = param_2;
    uVar3 = (**(code **)(*(int *)this + 0x14))(local_8,uVar1 & 0xffff | 0x4e0000,&local_10,0);
    return uVar3;
  }
  return 1;
}



/* VA 0040ccb3 */

CWnd * __fastcall FUN_0040ccb3(int param_1)

{
  int iVar1;
  CWnd *pCVar2;
  HWND hWnd;

  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  if (iVar1 != 0) {
    hWnd = *(HWND *)(param_1 + 0x1c);
    while( true ) {
      GetParent(hWnd);
      pCVar2 = FUN_0040b6dd();
      if (pCVar2 == (CWnd *)0x0) break;
      iVar1 = (**(code **)(*(int *)pCVar2 + 0xb8))();
      if (iVar1 != 0) {
        return pCVar2;
      }
      hWnd = *(HWND *)(pCVar2 + 0x1c);
    }
  }
  return (CWnd *)0x0;
}



/* VA 0040ccf7 */

/* Library Function - Single Match
    struct HWND__ * __stdcall AfxGetParentOwner(struct HWND__ *)

   Library: Visual Studio 2003 Release */

HWND__ * AfxGetParentOwner(HWND__ *param_1)

{
  CWnd *pCVar1;
  uint uVar2;
  HWND__ *pHVar3;

  pCVar1 = (CWnd *)FUN_0040b705((uint)param_1);
  if (pCVar1 == (CWnd *)0x0) {
    uVar2 = GetWindowLongA(param_1,-0x10);
    if ((uVar2 & 0x40000000) == 0) {
      pHVar3 = GetWindow(param_1,4);
    }
    else {
      pHVar3 = GetParent(param_1);
    }
  }
  else {
    pCVar1 = CWnd::GetOwner(pCVar1);
    pHVar3 = (HWND__ *)0x0;
    if (pCVar1 != (CWnd *)0x0) {
      pHVar3 = *(HWND__ **)(pCVar1 + 0x1c);
    }
  }
  return pHVar3;
}



/* VA 0040cd3c */

void __fastcall FUN_0040cd3c(int param_1)

{
  int iVar1;
  HWND__ *pHVar2;

  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  if (iVar1 != 0) {
    pHVar2 = *(HWND__ **)(param_1 + 0x1c);
    do {
      pHVar2 = AfxGetParentOwner(pHVar2);
    } while (pHVar2 != (HWND__ *)0x0);
    FUN_0040b6dd();
    return;
  }
  return;
}



/* VA 0040cd68 */

void __fastcall FUN_0040cd68(int param_1)

{
  int iVar1;
  uint uVar2;
  HWND hWnd;

  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  if (iVar1 != 0) {
    hWnd = *(HWND *)(param_1 + 0x1c);
    uVar2 = GetWindowLongA(hWnd,-0x10);
    while ((uVar2 & 0x40000000) != 0) {
      hWnd = GetParent(hWnd);
      if (hWnd == (HWND)0x0) break;
      uVar2 = GetWindowLongA(hWnd,-0x10);
    }
    FUN_0040b6dd();
  }
  return;
}



/* VA 0040cdaf */

bool __fastcall FUN_0040cdaf(int param_1)

{
  CWnd *pCVar1;
  int iVar2;
  CWnd *pCVar3;

  GetForegroundWindow();
  pCVar1 = FUN_0040b6dd();
  iVar2 = FUN_0040cd3c(param_1);
  GetLastActivePopup(*(HWND *)(iVar2 + 0x1c));
  pCVar3 = FUN_0040b6dd();
  return pCVar1 == pCVar3;
}



/* VA 0040cde3 */

/* Library Function - Single Match
    public: void __thiscall CWnd::ActivateTopParent(void)

   Library: Visual Studio 2003 Release */

void __thiscall CWnd::ActivateTopParent(CWnd *this)

{
  int iVar1;
  CWnd *pCVar2;
  BOOL BVar3;

  iVar1 = FUN_0040cd3c((int)this);
  GetForegroundWindow();
  pCVar2 = FUN_0040b6dd();
  if (pCVar2 != (CWnd *)0x0) {
    if (*(HWND *)(pCVar2 + 0x1c) == *(HWND *)(this + 0x1c)) {
      return;
    }
    BVar3 = IsChild(*(HWND *)(pCVar2 + 0x1c),*(HWND *)(this + 0x1c));
    if (BVar3 != 0) {
      return;
    }
  }
  SetForegroundWindow(*(HWND *)(iVar1 + 0x1c));
  return;
}



/* VA 0040ce20 */

CWnd * __fastcall FUN_0040ce20(CWnd *param_1)

{
  CWnd *pCVar1;
  int iVar2;
  CWnd *pCVar3;

  if (param_1 == (CWnd *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x1c);
  }
  if (iVar2 != 0) {
    iVar2 = (**(code **)(*(int *)param_1 + 0xb8))();
    pCVar3 = param_1;
    if (iVar2 == 0) {
      param_1 = FUN_0040ccb3((int)param_1);
      pCVar3 = param_1;
    }
    while (pCVar1 = pCVar3, pCVar1 != (CWnd *)0x0) {
      pCVar3 = FUN_0040ccb3((int)pCVar1);
      param_1 = pCVar1;
    }
    return param_1;
  }
  return (CWnd *)0x0;
}



/* VA 0040ce64 */

void FUN_0040ce64(int param_1,undefined4 *param_2)

{
  HWND hWnd;
  int iVar1;
  uint uVar2;
  HWND pHVar3;
  HWND hWnd_00;
  BOOL BVar4;
  HWND hWnd_01;
  bool bVar5;

  if (param_1 == 0) {
    hWnd_01 = (HWND)0x0;
  }
  else {
    hWnd_01 = *(HWND *)(param_1 + 0x1c);
  }
  bVar5 = false;
  if (hWnd_01 == (HWND)0x0) {
    iVar1 = FUN_00401858();
    if (iVar1 != 0) {
      hWnd_01 = *(HWND *)(iVar1 + 0x1c);
    }
    bVar5 = hWnd_01 == (HWND)0x0;
  }
  pHVar3 = hWnd_01;
  hWnd_00 = hWnd_01;
  if (!bVar5) {
    do {
      uVar2 = GetWindowLongA(hWnd_01,-0x10);
      pHVar3 = hWnd_01;
      hWnd_00 = hWnd_01;
      if ((uVar2 & 0x40000000) == 0) break;
      hWnd_01 = GetParent(hWnd_01);
      pHVar3 = hWnd_01;
      hWnd_00 = hWnd_01;
    } while (hWnd_01 != (HWND)0x0);
  }
  while (hWnd = pHVar3, hWnd != (HWND)0x0) {
    pHVar3 = GetParent(hWnd);
    hWnd_01 = hWnd;
  }
  if ((param_1 == 0) && (hWnd_00 != (HWND)0x0)) {
    hWnd_00 = GetLastActivePopup(hWnd_00);
  }
  if (param_2 != (undefined4 *)0x0) {
    if (((hWnd_01 == (HWND)0x0) || (BVar4 = IsWindowEnabled(hWnd_01), BVar4 == 0)) ||
       (hWnd_01 == hWnd_00)) {
      *param_2 = 0;
    }
    else {
      *param_2 = hWnd_01;
      EnableWindow(hWnd_01,0);
    }
  }
  FUN_0040b6dd();
  return;
}



/* VA 0040cf04 */

CWnd * FUN_0040cf04(HWND param_1,int param_2,int param_3)

{
  HWND pHVar1;
  HWND pHVar2;
  CWnd *pCVar3;

  pHVar1 = GetDlgItem(param_1,param_2);
  if (pHVar1 != (HWND)0x0) {
    pHVar2 = GetTopWindow(pHVar1);
    if ((pHVar2 != (HWND)0x0) &&
       (pCVar3 = FUN_0040cf04(pHVar1,param_2,param_3), pCVar3 != (CWnd *)0x0)) {
      return pCVar3;
    }
    if (param_3 == 0) {
      pCVar3 = FUN_0040b6dd();
      return pCVar3;
    }
    pCVar3 = (CWnd *)FUN_0040b705((uint)pHVar1);
    if (pCVar3 != (CWnd *)0x0) {
      return pCVar3;
    }
  }
  pHVar1 = GetTopWindow(param_1);
  while( true ) {
    if (pHVar1 == (HWND)0x0) {
      return (CWnd *)0x0;
    }
    pCVar3 = FUN_0040cf04(pHVar1,param_2,param_3);
    if (pCVar3 != (CWnd *)0x0) break;
    pHVar1 = GetWindow(pHVar1,2);
  }
  return pCVar3;
}



/* VA 0040cf7d */

void FUN_0040cf7d(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4,int param_5,int param_6)

{
  HWND hWnd;
  int iVar1;
  HWND pHVar2;

  for (hWnd = GetTopWindow(param_1); hWnd != (HWND)0x0; hWnd = GetWindow(hWnd,2)) {
    if (param_6 == 0) {
      SendMessageA(hWnd,param_2,param_3,param_4);
    }
    else {
      iVar1 = FUN_0040b705((uint)hWnd);
      if (iVar1 != 0) {
        FUN_0040b471();
      }
    }
    if (param_5 != 0) {
      pHVar2 = GetTopWindow(hWnd);
      if (pHVar2 != (HWND)0x0) {
        FUN_0040cf7d(hWnd,param_2,param_3,param_4,param_5,param_6);
      }
    }
  }
  return;
}



/* VA 0040cfff */

void __thiscall FUN_0040cfff(void *this,int param_1,int param_2,BOOL param_3)

{
  int iVar1;
  HWND hWnd;

  iVar1 = (**(code **)(*(int *)this + 0x70))(param_1);
  if (iVar1 == 0) {
    hWnd = *(HWND *)((int)this + 0x1c);
  }
  else {
    param_1 = 2;
    hWnd = *(HWND *)(iVar1 + 0x1c);
  }
  SetScrollPos(hWnd,param_1,param_2,param_3);
  return;
}



/* VA 0040d02f */

void __thiscall FUN_0040d02f(void *this,undefined4 param_1)

{
  int iVar1;
  int unaff_retaddr;
  HWND hWnd;

  iVar1 = (**(code **)(*(int *)this + 0x70))(param_1);
  if (iVar1 == 0) {
    hWnd = *(HWND *)((int)this + 0x1c);
  }
  else {
    unaff_retaddr = 2;
    hWnd = *(HWND *)(iVar1 + 0x1c);
  }
  GetScrollPos(hWnd,unaff_retaddr);
  return;
}



/* VA 0040d057 */

void __thiscall FUN_0040d057(void *this,int param_1,int param_2,int param_3,BOOL param_4)

{
  int iVar1;
  HWND hWnd;

  iVar1 = (**(code **)(*(int *)this + 0x70))(param_1);
  if (iVar1 == 0) {
    hWnd = *(HWND *)((int)this + 0x1c);
  }
  else {
    param_1 = 2;
    hWnd = *(HWND *)(iVar1 + 0x1c);
  }
  SetScrollRange(hWnd,param_1,param_2,param_3,param_4);
  return;
}



/* VA 0040d08a */

void __thiscall FUN_0040d08a(void *this,int param_1,undefined4 param_2)

{
  void *this_00;
  int wBar;

  wBar = param_1;
  if (param_1 == 3) {
    FUN_0040d08a(this,0,param_2);
    wBar = 1;
  }
  this_00 = (void *)(**(code **)(*(int *)this + 0x70))(wBar);
  if (this_00 == (void *)0x0) {
    ShowScrollBar(*(HWND *)((int)this + 0x1c),wBar,param_1);
  }
  else {
    FUN_0040ecd1(this_00,param_1);
  }
  return;
}



/* VA 0040d0cd */

undefined4 __thiscall FUN_0040d0cd(void *this,int param_1,LPCSCROLLINFO param_2,BOOL param_3)

{
  undefined4 uVar1;
  int iVar2;
  HWND hwnd;

  if (DAT_0042883c < 0x333) {
    uVar1 = 0;
  }
  else {
    hwnd = *(HWND *)((int)this + 0x1c);
    if (param_1 != 2) {
      iVar2 = (**(code **)(*(int *)this + 0x70))(param_1);
      if (iVar2 != 0) {
        hwnd = *(HWND *)(iVar2 + 0x1c);
        param_1 = 2;
      }
    }
    param_2->cbSize = 0x1c;
    SetScrollInfo(hwnd,param_1,param_2,param_3);
    uVar1 = 1;
  }
  return uVar1;
}



/* VA 0040d11a */

void __thiscall FUN_0040d11a(void *this,int param_1,int param_2,RECT *param_3,RECT *param_4)

{
  BOOL BVar1;
  HWND hWnd;
  undefined1 local_14 [16];

  BVar1 = IsWindowVisible(*(HWND *)((int)this + 0x1c));
  if (((BVar1 == 0) && (param_3 == (RECT *)0x0)) && (param_4 == (RECT *)0x0)) {
    for (hWnd = GetWindow(*(HWND *)((int)this + 0x1c),5); hWnd != (HWND)0x0;
        hWnd = GetWindow(hWnd,2)) {
      GetWindowRect(hWnd,(LPRECT)local_14);
      ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)local_14);
      ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)(local_14 + 8));
      SetWindowPos(hWnd,(HWND)0x0,local_14._0_4_ + param_1,local_14._4_4_ + param_2,0,0,0x15);
    }
  }
  else {
    ScrollWindow(*(HWND *)((int)this + 0x1c),param_1,param_2,param_3,param_4);
  }
  if ((*(int **)((int)this + 0x34) != (int *)0x0) && (param_3 == (RECT *)0x0)) {
    (**(code **)(**(int **)((int)this + 0x34) + 0x60))(param_1,param_2);
  }
  return;
}



/* VA 0040d1d7 */

void __thiscall
FUN_0040d1d7(void *this,uint param_1,uint param_2,uint param_3,int param_4,LPRECT param_5,
            int *param_6,int param_7)

{
  HWND pHVar1;
  HWND hWnd;
  uint uVar2;
  int iVar3;
  CWnd *pCVar4;
  HDWP local_28;
  tagRECT local_24;
  LONG local_14;
  LONG local_10;
  int local_c;
  HWND local_8;

  local_8 = (HWND)0x0;
  local_c = param_7;
  local_10 = 0;
  local_14 = 0;
  if (param_6 == (int *)0x0) {
    GetClientRect(*(HWND *)((int)this + 0x1c),&local_24);
  }
  else {
    local_24.left = *param_6;
    local_24.top = param_6[1];
    local_24.right = param_6[2];
    local_24.bottom = param_6[3];
  }
  if (param_4 == 1) {
    local_28 = (HDWP)0x0;
  }
  else {
    local_28 = BeginDeferWindowPos(8);
  }
  for (hWnd = GetTopWindow(*(HWND *)((int)this + 0x1c)); hWnd != (HWND)0x0; hWnd = GetWindow(hWnd,2)
      ) {
    uVar2 = GetDlgCtrlID(hWnd);
    uVar2 = uVar2 & 0xffff;
    iVar3 = FUN_0040b705((uint)hWnd);
    pHVar1 = hWnd;
    if ((((uVar2 != param_3) && (pHVar1 = local_8, param_1 <= uVar2)) && (uVar2 <= param_2)) &&
       (iVar3 != 0)) {
      SendMessageA(hWnd,0x361,0,(LPARAM)&local_28);
      pHVar1 = local_8;
    }
    local_8 = pHVar1;
  }
  if (param_4 == 1) {
    if (param_7 == 0) {
      param_5->right = local_14;
      param_5->top = 0;
      param_5->left = 0;
      param_5->bottom = local_10;
    }
    else {
      CopyRect(param_5,&local_24);
    }
  }
  else {
    if ((param_3 != 0) && (local_8 != (HWND)0x0)) {
      pCVar4 = FUN_0040b6dd();
      if (param_4 == 2) {
        local_24.left = local_24.left + param_5->left;
        local_24.top = local_24.top + param_5->top;
        local_24.right = local_24.right - param_5->right;
        local_24.bottom = local_24.bottom - param_5->bottom;
      }
      (**(code **)(*(int *)pCVar4 + 0x68))(&local_24,0);
      FUN_0040d311((int *)&local_28,local_8,&local_24);
    }
    if (local_28 != (HDWP)0x0) {
      EndDeferWindowPos(local_28);
    }
  }
  return;
}



/* VA 0040d311 */

void FUN_0040d311(int *param_1,HWND param_2,RECT *param_3)

{
  int Y;
  int X;
  HWND hWnd;
  BOOL BVar1;
  HDWP pvVar2;
  undefined1 local_14 [16];

  hWnd = GetParent(param_2);
  if ((param_1 == (int *)0x0) || (*param_1 != 0)) {
    GetWindowRect(param_2,(LPRECT)local_14);
    ScreenToClient(hWnd,(LPPOINT)local_14);
    ScreenToClient(hWnd,(LPPOINT)(local_14 + 8));
    BVar1 = EqualRect((RECT *)local_14,param_3);
    if (BVar1 == 0) {
      Y = param_3->top;
      X = param_3->left;
      if (param_1 == (int *)0x0) {
        SetWindowPos(param_2,(HWND)0x0,X,Y,param_3->right - X,param_3->bottom - Y,0x14);
      }
      else {
        pvVar2 = DeferWindowPos((HDWP)*param_1,param_2,(HWND)0x0,X,Y,param_3->right - X,
                                param_3->bottom - Y,0x14);
        *param_1 = (int)pvVar2;
      }
    }
  }
  return;
}



/* VA 0040d3ab */

void __thiscall FUN_0040d3ab(void *this,LPRECT param_1,int param_2)

{
  uint dwExStyle;
  DWORD dwStyle;
  BOOL bMenu;

  dwExStyle = FUN_0040eb68((int)this);
  if (param_2 == 0) {
    dwExStyle = dwExStyle & 0xfffffdff;
  }
  bMenu = 0;
  dwStyle = FUN_0040eb4e((int)this);
  AdjustWindowRectEx(param_1,dwStyle,bMenu,dwExStyle);
  return;
}



/* VA 0040d3d6 */

undefined4 __thiscall FUN_0040d3d6(void *this,uint param_1,int param_2)

{
  HWND hWnd;
  int iVar1;
  HWND hWnd_00;
  BOOL BVar2;
  uint uVar3;

  iVar1 = FUN_0040cd3c((int)this);
  uVar3 = param_1 & 0xfff0;
  if ((uVar3 == 0xf040) || (uVar3 == 0xf050)) {
    if ((short)param_2 != 0x75) {
      return 0;
    }
    if (iVar1 == 0) {
      return 0;
    }
    FUN_0040ecf8(iVar1);
  }
  else {
    if ((uVar3 != 0xf060) && (uVar3 != 0xf100)) {
      return 0;
    }
    if (((uVar3 == 0xf060) || (param_2 != 0)) && (iVar1 != 0)) {
      hWnd = *(HWND *)((int)this + 0x1c);
      hWnd_00 = GetFocus();
      SetActiveWindow(*(HWND *)(iVar1 + 0x1c));
      FUN_0040b6dd();
      SendMessageA(*(HWND *)(iVar1 + 0x1c),0x112,param_1,param_2);
      BVar2 = IsWindow(hWnd);
      if (BVar2 != 0) {
        SetActiveWindow(hWnd);
      }
      BVar2 = IsWindow(hWnd_00);
      if (BVar2 != 0) {
        SetFocus(hWnd_00);
      }
    }
  }
  return 1;
}



/* VA 0040d490 */

undefined4 FUN_0040d490(HWND param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  HWND hWnd;

  hWnd = (HWND)*param_2;
  while( true ) {
    if (hWnd == (HWND)0x0) {
      return 0;
    }
    piVar1 = (int *)FUN_0040b705((uint)hWnd);
    if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x98))(param_2), iVar2 != 0))
    break;
    if (hWnd == param_1) {
      return 0;
    }
    hWnd = GetParent(hWnd);
  }
  return 1;
}



/* VA 0040d4d2 */

void __thiscall FUN_0040d4d2(void *this,undefined4 param_1)

{
  int iVar1;

  iVar1 = FUN_0041a9d0(&DAT_00428660,FUN_00401abc);
  (**(code **)(*(int *)this + 0xb0))
            (*(undefined4 *)(iVar1 + 0x38),*(undefined4 *)(iVar1 + 0x3c),
             *(undefined4 *)(iVar1 + 0x40),param_1);
  return;
}



/* VA 0040d4ff */

undefined4 FUN_0040d4ff(void)

{
  HWND hWnd;
  void *this;
  void *this_00;
  HWND pHVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  this = (void *)FUN_0040b66d();
  if (this != (void *)0x0) {
    hWnd = *(HWND *)(unaff_EBP + 8);
    this_00 = (void *)FUN_0040aec1(this,(uint)hWnd);
    if (this_00 != (void *)0x0) {
      uVar3 = FUN_0040d4d2(this_00,*(undefined4 *)(unaff_EBP + 0xc));
      goto LAB_0040d593;
    }
    pHVar1 = GetParent(hWnd);
    iVar2 = FUN_0040aec1(this,(uint)pHVar1);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x34) != 0)) {
      iVar2 = FUN_0040aec1((void *)(*(int *)(iVar2 + 0x34) + 0x20),(uint)hWnd);
      if (iVar2 != 0) {
        FUN_0040b3ba((void *)(unaff_EBP + -0x48),hWnd);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(int *)(unaff_EBP + -0x10) = iVar2;
        uVar3 = FUN_0040d4d2((void *)(unaff_EBP + -0x48),*(undefined4 *)(unaff_EBP + 0xc));
        *(undefined4 *)(unaff_EBP + -0x2c) = 0;
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        CWnd::~CWnd((CWnd *)(unaff_EBP + -0x48));
        goto LAB_0040d593;
      }
    }
  }
  uVar3 = 0;
LAB_0040d593:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}



/* VA 0040d5a3 */

uint __thiscall FUN_0040d5a3(void *this,uint param_1,int *param_2,int param_3,int *param_4)

{
  LRESULT LVar1;
  uint uVar2;

  if (*(int *)((int)this + 0x38) == 0) {
    uVar2 = FUN_0040d5fe(this,param_1,param_2,param_3,param_4);
  }
  else {
    LVar1 = SendMessageA(*(HWND *)((int)this + 0x1c),param_1 + 0x2000,(WPARAM)param_2,param_3);
    if (((param_1 < 0x132) || (0x138 < param_1)) || (uVar2 = 0, LVar1 != 0)) {
      if (param_4 != (int *)0x0) {
        *param_4 = LVar1;
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* VA 0040d5fe */

uint __thiscall FUN_0040d5fe(void *this,uint param_1,int *param_2,int param_3,int *param_4)

{
  uint uVar1;
  int *local_c;
  int local_8;

  if (param_1 < 0x3a) {
    if ((param_1 == 0x39) || ((0x2a < param_1 && (param_1 < 0x30)))) {
LAB_0040d6de:
      uVar1 = FUN_0040c608();
      return uVar1;
    }
  }
  else {
    if (param_1 == 0x4e) {
      local_c = param_4;
      local_8 = param_3;
      uVar1 = FUN_0040ee06(this,(undefined4 *)0x0,*(uint *)(param_3 + 8) & 0xffff | 0xbc4e0000,
                           &local_c,(undefined4 *)0x0);
      return uVar1;
    }
    if (param_1 == 0x111) {
      uVar1 = FUN_0040ee06(this,(undefined4 *)0x0,(uint)param_2 >> 0x10 | 0xbd110000,
                           (undefined4 *)0x0,(undefined4 *)0x0);
      if (uVar1 == 0) {
        return 0;
      }
      if (param_4 != (int *)0x0) {
        *param_4 = 1;
        return 1;
      }
      return 1;
    }
    if ((0x113 < param_1) && ((param_1 < 0x116 || (param_1 == 0x210)))) goto LAB_0040d6de;
  }
  if ((0x131 < param_1) && (param_1 < 0x139)) {
    local_8 = param_1 - 0x132;
    local_c = param_2;
    uVar1 = FUN_0040c608();
    if (*param_4 != 0) {
      return uVar1;
    }
  }
  return 0;
}



/* VA 0040d743 */

void __fastcall FUN_0040d743(int *param_1)

{
  int iVar1;
  CWinThread *pCVar2;
  uint uVar3;

  iVar1 = FUN_00419dc2();
  iVar1 = *(int *)(iVar1 + 4);
  FUN_0041aa65();
  if (*(int **)(iVar1 + 0x1c) == param_1) {
    FUN_004100d0(0x4287e8);
  }
  iVar1 = FUN_00419dc2();
  if (*(char *)(iVar1 + 0x14) == '\0') {
    pCVar2 = AfxGetThread();
    if (pCVar2 != (CWinThread *)0x0) {
      pCVar2 = AfxGetThread();
      if (*(int **)(pCVar2 + 0x1c) == param_1) {
        iVar1 = FUN_0041aa65();
        if (*(code **)(iVar1 + 0x1c) != (code *)0x0) {
          (**(code **)(iVar1 + 0x1c))();
        }
      }
    }
  }
  uVar3 = FUN_0040eb4e((int)param_1);
  if ((uVar3 & 0x40000000) == 0) {
    FUN_0040cf7d((HWND)param_1[7],0x15,0,0,1,1);
  }
  FUN_0040b632(param_1);
  return;
}



/* VA 0040d7cd */

void __fastcall FUN_0040d7cd(CWnd *param_1)

{
  int iVar1;
  CWinThread *pCVar2;

  iVar1 = FUN_00419dc2();
  if (*(char *)(iVar1 + 0x14) == '\0') {
    iVar1 = FUN_0041aa65();
    pCVar2 = AfxGetThread();
    if (pCVar2 != (CWinThread *)0x0) {
      pCVar2 = AfxGetThread();
      if ((*(CWnd **)(pCVar2 + 0x1c) == param_1) && (*(code **)(iVar1 + 0x24) != (code *)0x0)) {
        (**(code **)(iVar1 + 0x24))();
      }
    }
  }
  FUN_0041179b((HKEY)0x1);
  CWnd::OnDisplayChange(param_1,0,0);
  return;
}



/* VA 0040d821 */

void __thiscall FUN_0040d821(void *this,LPSTR param_1)

{
  CWinThread *pCVar1;
  int iVar2;
  uint uVar3;

  pCVar1 = AfxGetThread();
  if (pCVar1 != (CWinThread *)0x0) {
    pCVar1 = AfxGetThread();
    if (*(void **)(pCVar1 + 0x1c) == this) {
      iVar2 = FUN_00419dc2();
      FUN_0040fdc0(*(void **)(iVar2 + 4),param_1);
    }
  }
  uVar3 = FUN_0040eb4e((int)this);
  if ((uVar3 & 0x40000000) == 0) {
    iVar2 = FUN_0040b5fd();
    FUN_0040cf7d(*(HWND *)((int)this + 0x1c),*(UINT *)(iVar2 + 4),*(WPARAM *)(iVar2 + 8),
                 *(LPARAM *)(iVar2 + 0xc),1,1);
  }
  return;
}



/* VA 0040d876 */

undefined4 __fastcall FUN_0040d876(int *param_1)

{
  SHORT SVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;

  uVar2 = FUN_0040eb4e((int)param_1);
  if (((((uVar2 & 0x40000000) == 0) && (iVar3 = FUN_00401858(), iVar3 != 0)) &&
      (SVar1 = GetKeyState(0x10), -1 < SVar1)) &&
     ((SVar1 = GetKeyState(0x11), -1 < SVar1 && (SVar1 = GetKeyState(0x12), -1 < SVar1)))) {
    SendMessageA(*(HWND *)(iVar3 + 0x1c),0x111,0xe146,0);
    return 1;
  }
  uVar4 = FUN_0040b632(param_1);
  return uVar4;
}



/* VA 0040d8da */

/* Library Function - Single Match
    protected: long __thiscall CWnd::OnDisplayChange(unsigned int,long)

   Library: Visual Studio 1998 Release */

long __thiscall CWnd::OnDisplayChange(CWnd *this,uint param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  long lVar3;

  iVar1 = FUN_00419dc2();
  if (*(CWnd **)(*(int *)(iVar1 + 4) + 0x1c) == this) {
    FUN_00410114(0x4287e8);
  }
  uVar2 = FUN_0040eb4e((int)this);
  if ((uVar2 & 0x40000000) == 0) {
    iVar1 = FUN_0040b5fd();
    FUN_0040cf7d(*(HWND *)(this + 0x1c),*(UINT *)(iVar1 + 4),*(WPARAM *)(iVar1 + 8),
                 *(LPARAM *)(iVar1 + 0xc),1,1);
  }
  lVar3 = FUN_0040b632((int *)this);
  return lVar3;
}



/* VA 0040d927 */

undefined4 __thiscall FUN_0040d927(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;

  iVar1 = FUN_0040d4ff();
  if (iVar1 == 0) {
    param_2 = FUN_0040b632(this);
  }
  return param_2;
}



/* VA 0040d951 */

void __thiscall FUN_0040d951(void *this,undefined4 param_1,undefined4 param_2,void *param_3)

{
  int iVar1;

  if ((param_3 != (void *)0x0) && (iVar1 = FUN_0040d4d2(param_3,0), iVar1 != 0)) {
    return;
  }
  FUN_0040b632(this);
  return;
}



/* VA 0040d972 */

void __thiscall FUN_0040d972(void *this,undefined4 param_1,undefined4 param_2,void *param_3)

{
  int iVar1;

  if ((param_3 != (void *)0x0) && (iVar1 = FUN_0040d4d2(param_3,0), iVar1 != 0)) {
    return;
  }
  FUN_0040b632(this);
  return;
}



/* VA 0040d993 */

void __fastcall FUN_0040d993(int *param_1)

{
  BOOL BVar1;
  tagMSG local_20;

  while( true ) {
    BVar1 = PeekMessageA(&local_20,(HWND)0x0,0x121,0x121,1);
    if (BVar1 == 0) break;
    DispatchMessageA(&local_20);
  }
  FUN_0040b632(param_1);
  return;
}



/* VA 0040d9dd */

void * __thiscall FUN_0040d9dd(void *this,undefined4 param_1,void *param_2)

{
  int iVar1;

  iVar1 = FUN_0040d4d2(param_2,&param_2);
  if (iVar1 == 0) {
    param_2 = (void *)FUN_0040b632(this);
  }
  return param_2;
}



/* VA 0040da04 */

void * __thiscall FUN_0040da04(void *this,int param_1,void *param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  HWND pHVar4;

  pvVar1 = param_2;
  iVar2 = FUN_0040d4d2(param_2,&param_2);
  if (iVar2 == 0) {
    iVar2 = FUN_0041aa65();
    pHVar4 = (HWND)0x0;
    if (pvVar1 != (void *)0x0) {
      pHVar4 = *(HWND *)((int)pvVar1 + 0x1c);
    }
    iVar3 = FUN_0040da67(*(HDC *)(param_1 + 4),pHVar4,param_3,*(HANDLE *)(iVar2 + 4),
                         *(COLORREF *)(iVar2 + 8));
    if (iVar3 == 0) {
      param_2 = (void *)FUN_0040b632(this);
    }
    else {
      param_2 = *(void **)(iVar2 + 4);
    }
  }
  return param_2;
}



/* VA 0040da67 */

undefined4 FUN_0040da67(HDC param_1,HWND param_2,int param_3,HANDLE param_4,COLORREF param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined1 local_10 [4];
  COLORREF local_c;

  if ((((param_1 == (HDC)0x0) || (param_4 == (HANDLE)0x0)) || (param_3 == 1)) ||
     ((param_3 == 0 || (param_3 == 5)))) {
LAB_0040dad6:
    uVar2 = 0;
  }
  else {
    if (param_3 == 2) {
      bVar1 = FUN_00411541(param_2,2);
      if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_0040dad6;
    }
    GetObjectA(param_4,0xc,local_10);
    SetBkColor(param_1,local_c);
    if (param_5 == 0xffffffff) {
      param_5 = GetSysColor(8);
    }
    SetTextColor(param_1,param_5);
    uVar2 = 1;
  }
  return uVar2;
}



/* VA 0040dae4 */

undefined4 FUN_0040dae4(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd0;
  FUN_0040db87((void *)(unaff_EBP + -0x2c),extraout_ECX,*(undefined4 *)(unaff_EBP + 8));
  iVar3 = FUN_00419a6f();
  *(undefined4 *)(unaff_EBP + 8) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = iVar3;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar3 + 0xb8);
  *(int *)(iVar3 + 0xb8) = extraout_ECX[7];
  (**(code **)(*extraout_ECX + 0x8c))(unaff_EBP + -0x2c);
  *(undefined4 *)(unaff_EBP + 8) = 1;
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *(undefined4 *)(iVar3 + 0xb8) = *(undefined4 *)(unaff_EBP + -0x18);
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  *unaff_FS_OFFSET = uVar1;
  return uVar2;
}



/* VA 0040db87 */

void __thiscall FUN_0040db87(void *this,undefined4 param_1,undefined4 param_2)

{
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)this = param_2;
  *(undefined4 *)((int)this + 4) = param_1;
  return;
}



/* VA 0040db9d */

void __thiscall FUN_0040db9d(void *this,int param_1)

{
  HWND hWnd;
  HWND pHVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  tagRECT local_3c;
  tagRECT local_2c;
  tagRECT local_1c;
  void *local_c;
  uint local_8;

  local_c = this;
  local_8 = FUN_0040eb4e((int)this);
  if (param_1 == 0) {
    if ((local_8 & 0x40000000) == 0) {
      hWnd = GetWindow(*(HWND *)((int)this + 0x1c),4);
    }
    else {
      hWnd = GetParent(*(HWND *)((int)this + 0x1c));
    }
    if ((hWnd != (HWND)0x0) && (pHVar1 = (HWND)SendMessageA(hWnd,0x36b,0,0), pHVar1 != (HWND)0x0)) {
      hWnd = pHVar1;
    }
  }
  else {
    hWnd = *(HWND *)(param_1 + 0x1c);
  }
  GetWindowRect(*(HWND *)((int)this + 0x1c),&local_3c);
  if ((local_8 & 0x40000000) == 0) {
    if ((hWnd != (HWND)0x0) &&
       ((uVar2 = GetWindowLongA(hWnd,-0x10), (uVar2 & 0x10000000) == 0 ||
        ((uVar2 & 0x20000000) != 0)))) {
      hWnd = (HWND)0x0;
    }
    SystemParametersInfoA(0x30,0,&local_1c,0);
    if (hWnd == (HWND)0x0) {
      local_2c.left = local_1c.left;
      local_2c.top = local_1c.top;
      local_2c.right = local_1c.right;
      local_2c.bottom = local_1c.bottom;
    }
    else {
      GetWindowRect(hWnd,&local_2c);
    }
  }
  else {
    pHVar1 = GetParent(*(HWND *)((int)this + 0x1c));
    GetClientRect(pHVar1,&local_1c);
    GetClientRect(hWnd,&local_2c);
    MapWindowPoints(hWnd,pHVar1,(LPPOINT)&local_2c,2);
  }
  iVar3 = (local_2c.left + local_2c.right) / 2 - (local_3c.right - local_3c.left) / 2;
  iVar4 = (local_2c.top + local_2c.bottom) / 2 - (local_3c.bottom - local_3c.top) / 2;
  if ((local_1c.left <= iVar3) &&
     (local_1c.left = iVar3, local_1c.right < iVar3 + (local_3c.right - local_3c.left))) {
    local_1c.left = (local_3c.left - local_3c.right) + local_1c.right;
  }
  if ((local_1c.top <= iVar4) &&
     (local_1c.top = iVar4, local_1c.bottom < (local_3c.bottom - local_3c.top) + iVar4)) {
    local_1c.top = (local_3c.top - local_3c.bottom) + local_1c.bottom;
  }
  FUN_0040ec40(local_c,0,local_1c.left,local_1c.top,-1,-1,0x15);
  return;
}



/* VA 0040dd1b */

ushort * __thiscall FUN_0040dd1b(void *this,LPCSTR param_1)

{
  HMODULE hModule;
  int iVar1;
  HRSRC hResInfo;
  HGLOBAL hResData;
  ushort *puVar2;

  puVar2 = (ushort *)0x0;
  if (param_1 != (LPCSTR)0x0) {
    iVar1 = FUN_00419dc2();
    hModule = *(HMODULE *)(iVar1 + 0xc);
    hResInfo = FindResourceA(hModule,param_1,(LPCSTR)0xf0);
    if (hResInfo != (HRSRC)0x0) {
      hResData = LoadResource(hModule,hResInfo);
      if (hResData == (HGLOBAL)0x0) {
        return (ushort *)0x0;
      }
      puVar2 = LockResource(hResData);
    }
  }
  puVar2 = FUN_0040dd6b(this,puVar2);
  return puVar2;
}



/* VA 0040dd6b */

ushort * __thiscall FUN_0040dd6b(void *this,ushort *param_1)

{
  int iVar1;
  ushort *puVar2;
  ushort uVar3;
  LRESULT LVar4;
  ushort *puVar5;

  puVar5 = (ushort *)0x1;
  puVar2 = param_1;
  for (; (puVar2 != (ushort *)0x0 && (*param_1 != 0));
      param_1 = (ushort *)((int)(param_1 + 4) + iVar1)) {
    uVar3 = param_1[1];
    iVar1 = *(int *)(param_1 + 2);
    if (uVar3 == 0x401) {
      uVar3 = 0x180;
    }
    else if (uVar3 == 0x403) {
      uVar3 = 0x143;
    }
    if (((uVar3 == 0x180) || (uVar3 == 0x143)) &&
       (LVar4 = SendDlgItemMessageA(*(HWND *)((int)this + 0x1c),(uint)*param_1,(uint)uVar3,0,
                                    (LPARAM)(param_1 + 4)), LVar4 == -1)) {
      puVar5 = (ushort *)0x0;
    }
    puVar2 = puVar5;
  }
  if (puVar5 != (ushort *)0x0) {
    FUN_0040cf7d(*(HWND *)((int)this + 0x1c),0x364,0,0,0,0);
  }
  return puVar5;
}



/* VA 0040ddf5 */

void FUN_0040ddf5(void)

{
  HWND pHVar1;
  uint uVar2;
  void *this;
  int extraout_ECX;
  int iVar3;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  CCmdUI::CCmdUI((CCmdUI *)(unaff_EBP + -0x38));
  FUN_0040b374((undefined4 *)(unaff_EBP + -0x74));
  pHVar1 = *(HWND *)(extraout_ECX + 0x1c);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  pHVar1 = GetTopWindow(pHVar1);
  do {
    if (pHVar1 == (HWND)0x0) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x58) = 0;
      CWnd::~CWnd((CWnd *)(unaff_EBP + -0x74));
      *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
      return;
    }
    *(HWND *)(unaff_EBP + -0x58) = pHVar1;
    uVar2 = GetDlgCtrlID(pHVar1);
    *(uint *)(unaff_EBP + -0x34) = uVar2 & 0xffff;
    *(int *)(unaff_EBP + -0x24) = unaff_EBP + -0x74;
    this = (void *)FUN_0040b705((uint)pHVar1);
    if (((this == (void *)0x0) ||
        (uVar2 = FUN_0040ee06(this,(undefined4 *)0x0,0xbd11ffff,(undefined4 *)(unaff_EBP + -0x38),
                              (undefined4 *)0x0), uVar2 == 0)) &&
       (uVar2 = FUN_0040ee06(*(void **)(unaff_EBP + -0x10),*(undefined4 **)(unaff_EBP + -0x34),
                             0xffffffff,(undefined4 *)(unaff_EBP + -0x38),(undefined4 *)0x0),
       uVar2 == 0)) {
      iVar3 = *(int *)(unaff_EBP + 0xc);
      if (iVar3 != 0) {
        uVar2 = SendMessageA(*(HWND *)(unaff_EBP + -0x58),0x87,0,0);
        if ((uVar2 & 0x2000) != 0) {
          uVar2 = FUN_0040eb4e(unaff_EBP + -0x74);
          uVar2 = uVar2 & 0xf;
          if (((uVar2 != 3) && (uVar2 != 6)) && ((uVar2 != 7 && (uVar2 != 9)))) goto LAB_0040debb;
        }
        iVar3 = 0;
      }
LAB_0040debb:
      FUN_0040f2c5((void *)(unaff_EBP + -0x38),*(int **)(unaff_EBP + 8),iVar3);
    }
    pHVar1 = GetWindow(pHVar1,2);
  } while( true );
}



/* VA 0040defa */

undefined4 __thiscall FUN_0040defa(void *this,LPMSG param_1)

{
  uint uVar1;
  undefined4 uVar2;

  uVar1 = param_1->message;
  if (((uVar1 < 0x100) || (0x108 < uVar1)) && ((uVar1 < 0x200 || (0x209 < uVar1)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0040eb1b(this,param_1);
  }
  return uVar2;
}



/* VA 0040df2a */

int __thiscall FUN_0040df2a(void *this,byte param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  HWND hWnd;
  CWinThread *pCVar4;
  BOOL BVar5;
  LRESULT LVar6;
  CWinThread *pCVar7;
  int iVar8;
  LPMSG lpMsg;
  int local_c;

  bVar1 = true;
  local_c = 0;
  if ((param_1 & 4) != 0) {
    uVar3 = FUN_0040eb4e((int)this);
    bVar2 = true;
    if ((uVar3 & 0x10000000) == 0) goto LAB_0040df5b;
  }
  bVar2 = false;
LAB_0040df5b:
  hWnd = GetParent(*(HWND *)((int)this + 0x1c));
  *(uint *)((int)this + 0x24) = *(uint *)((int)this + 0x24) | 0x18;
  pCVar4 = AfxGetThread();
  lpMsg = (LPMSG)(pCVar4 + 0x30);
LAB_0040df7c:
  while ((!bVar1 || (BVar5 = PeekMessageA(lpMsg,(HWND)0x0,0,0,0), BVar5 != 0))) {
    do {
      pCVar7 = AfxGetThread();
      iVar8 = (**(code **)(*(int *)pCVar7 + 100))();
      if (iVar8 == 0) {
        AfxPostQuitMessage(0);
        return -1;
      }
      if ((bVar2) && ((*(int *)(pCVar4 + 0x34) == 0x118 || (*(int *)(pCVar4 + 0x34) == 0x104)))) {
        FUN_0040ec8f(this,1);
        UpdateWindow(*(HWND *)((int)this + 0x1c));
        bVar2 = false;
      }
      iVar8 = (**(code **)(*(int *)this + 0x78))();
      if (iVar8 == 0) {
        *(uint *)((int)this + 0x24) = *(uint *)((int)this + 0x24) & 0xffffffe7;
        return *(int *)((int)this + 0x2c);
      }
      pCVar7 = AfxGetThread();
      iVar8 = (**(code **)(*(int *)pCVar7 + 0x6c))(lpMsg);
      if (iVar8 != 0) {
        bVar1 = true;
        local_c = 0;
      }
      BVar5 = PeekMessageA(lpMsg,(HWND)0x0,0,0,0);
    } while (BVar5 != 0);
  }
  if (bVar2) {
    FUN_0040ec8f(this,1);
    UpdateWindow(*(HWND *)((int)this + 0x1c));
    bVar2 = false;
  }
  if ((((param_1 & 1) == 0) && (hWnd != (HWND)0x0)) && (local_c == 0)) {
    SendMessageA(hWnd,0x121,0,*(LPARAM *)((int)this + 0x1c));
  }
  if ((param_1 & 2) == 0) goto code_r0x0040dfd6;
  goto LAB_0040dfee;
code_r0x0040dfd6:
  iVar8 = local_c + 1;
  LVar6 = SendMessageA(*(HWND *)((int)this + 0x1c),0x36a,0,local_c);
  local_c = iVar8;
  if (LVar6 == 0) {
LAB_0040dfee:
    bVar1 = false;
  }
  goto LAB_0040df7c;
}



/* VA 0040e0b4 */

int FUN_0040e0b4(byte param_1)

{
  int iVar1;
  int iVar2;
  uint local_2c;
  code *local_28;
  undefined4 local_1c;
  undefined4 local_14;
  undefined4 local_10;
  char *local_8;

  iVar2 = 0;
  _memset(&local_2c,0,0x28);
  local_28 = DefWindowProcA_exref;
  iVar1 = FUN_00419dc2();
  local_1c = *(undefined4 *)(iVar1 + 8);
  local_14 = DAT_00428828;
  iVar1 = FUN_00419dc2();
  if ((param_1 & 1) == 0) {
    if ((param_1 & 0x20) == 0) {
      if ((param_1 & 2) == 0) {
        if ((param_1 & 4) == 0) {
          if ((param_1 & 8) == 0) {
            if ((param_1 & 0x10) != 0) {
              InitCommonControls();
              *(byte *)(iVar1 + 0x18) = *(byte *)(iVar1 + 0x18) | 0x10;
              iVar2 = 1;
            }
          }
          else {
            local_2c = 0xb;
            local_10 = 6;
            iVar2 = AfxRegisterWithIcon((int)&local_2c,"AfxFrameOrView42s",0x7a02);
            if (iVar2 != 0) {
              *(byte *)(iVar1 + 0x18) = *(byte *)(iVar1 + 0x18) | 8;
            }
          }
        }
        else {
          local_10 = 0;
          local_2c = 8;
          iVar2 = AfxRegisterWithIcon((int)&local_2c,"AfxMDIFrame42s",0x7a01);
          if (iVar2 != 0) {
            *(byte *)(iVar1 + 0x18) = *(byte *)(iVar1 + 0x18) | 4;
          }
        }
      }
      else {
        local_2c = 0;
        local_8 = "AfxControlBar42s";
        local_10 = 0x10;
        iVar2 = FUN_0040c307();
        if (iVar2 != 0) {
          *(byte *)(iVar1 + 0x18) = *(byte *)(iVar1 + 0x18) | 2;
        }
      }
    }
    else {
      local_2c = local_2c | 0x8b;
      local_8 = "AfxOleControl42s";
      iVar2 = FUN_0040c307();
      if (iVar2 != 0) {
        *(byte *)(iVar1 + 0x18) = *(byte *)(iVar1 + 0x18) | 0x20;
      }
    }
  }
  else {
    local_2c = 0xb;
    local_8 = "AfxWnd42s";
    iVar2 = FUN_0040c307();
    if (iVar2 != 0) {
      *(byte *)(iVar1 + 0x18) = *(byte *)(iVar1 + 0x18) | 1;
    }
  }
  return iVar2;
}



/* VA 0040e1ee */

/* Library Function - Multiple Matches With Same Base Name
    int __stdcall _AfxRegisterWithIcon(struct tagWNDCLASSA *,char const *,unsigned int)
    int __stdcall _AfxRegisterWithIcon(struct tagWNDCLASSW *,wchar_t const *,unsigned int)

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

void AfxRegisterWithIcon(int param_1,undefined4 param_2,ushort param_3)

{
  int iVar1;
  HICON pHVar2;

  *(undefined4 *)(param_1 + 0x24) = param_2;
  iVar1 = FUN_00419dc2();
  pHVar2 = LoadIconA(*(HINSTANCE *)(iVar1 + 0xc),(LPCSTR)(uint)param_3);
  *(HICON *)(param_1 + 0x14) = pHVar2;
  if (pHVar2 == (HICON)0x0) {
    pHVar2 = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    *(HICON *)(param_1 + 0x14) = pHVar2;
  }
  FUN_0040c307();
  return;
}



/* VA 0040e236 */

undefined4 __fastcall FUN_0040e236(int param_1)

{
  int iVar1;

  iVar1 = *(int *)(param_1 + 0x90);
  if (((iVar1 != 0) && (iVar1 != 0xe002)) && (iVar1 != 0xe001)) {
    return 1;
  }
  return 0;
}



/* VA 0040e32e */

undefined4 __thiscall
FUN_0040e32e(void *this,undefined4 *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  CWnd *pCVar2;
  int iVar3;
  CWinThread *pCVar4;
  undefined4 uVar5;

  uVar1 = FUN_0040ee06(this,param_1,param_2,param_3,param_4);
  if (uVar1 == 0) {
    if ((((param_2 == 0) || (param_2 == 0xffffffff)) && (((uint)param_1 & 0x8000) != 0)) &&
       (param_1 < (undefined4 *)0xf000)) {
      GetParent(*(HWND *)((int)this + 0x1c));
      pCVar2 = FUN_0040b6dd();
      if (pCVar2 != (CWnd *)0x0) {
        iVar3 = (**(code **)(*(int *)pCVar2 + 0x14))(param_1,param_2,param_3,param_4);
        if (iVar3 != 0) goto LAB_0040e3a5;
      }
      pCVar4 = AfxGetThread();
      if (pCVar4 != (CWinThread *)0x0) {
        iVar3 = (**(code **)(*(int *)pCVar4 + 0x14))(param_1,param_2,param_3,param_4);
        if (iVar3 != 0) goto LAB_0040e3a5;
      }
    }
    uVar5 = 0;
  }
  else {
LAB_0040e3a5:
    uVar5 = 1;
  }
  return uVar5;
}



/* VA 0040e3b3 */

CDialog * __thiscall FUN_0040e3b3(void *this,byte param_1)

{
  CDialog::~CDialog(this);
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 0040e3cf */

/* Library Function - Single Match
    public: virtual __thiscall CDialog::~CDialog(void)

   Library: Visual Studio 2003 Release */

void __thiscall CDialog::~CDialog(CDialog *this)

{
  CWnd *this_00;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(CWnd **)(unaff_EBP + -0x10) = this_00;
  *(undefined ***)this_00 = &PTR_LAB_0041cf5c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(this_00 + 0x1c) != 0) {
    FUN_0040bf81((int)this_00);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWnd::~CWnd(this_00);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 0040e40d */

bool FUN_0040e40d(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  LPVOID pvVar4;
  HWND pHVar5;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  bool bVar6;

  FUN_00402bc0();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc0;
  *(int **)(unaff_EBP + -0x24) = extraout_ECX;
  if (*(int *)(unaff_EBP + 0x10) == 0) {
    iVar2 = FUN_00419dc2();
    *(undefined4 *)(unaff_EBP + 0x10) = *(undefined4 *)(iVar2 + 8);
  }
  iVar2 = FUN_00419dc2();
  piVar1 = *(int **)(iVar2 + 0x1038);
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(int **)(unaff_EBP + -0x28) = piVar1;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = FUN_00419dc2();
  if ((*(byte *)(iVar2 + 0x18) & 0x10) == 0) {
    FUN_0040e0b4(0x10);
  }
  if (piVar1 == (int *)0x0) {
LAB_0040e488:
    if (*(int *)(unaff_EBP + 8) != 0) {
      FUN_0040fe73((undefined4 *)(unaff_EBP + -0x1c));
      *(undefined1 *)(unaff_EBP + -4) = 1;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      iVar2 = FUN_00410645(*(uint **)(unaff_EBP + 8),(void *)(unaff_EBP + -0x1c),
                           (undefined2 *)(unaff_EBP + -0x18));
      if (iVar2 == 0) {
LAB_0040e514:
        FUN_00410495((void *)(unaff_EBP + -0x40),*(uint **)(unaff_EBP + 8));
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_004107cb((short)*(undefined4 *)(unaff_EBP + -0x18));
        uVar3 = FUN_00410532((undefined4 *)(unaff_EBP + -0x40));
        *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_00410524((undefined4 *)(unaff_EBP + -0x40));
      }
      else {
        iVar2 = GetSystemMetrics(0x2a);
        bVar6 = false;
        if (iVar2 != 0) {
          iVar2 = FUN_00403360(*(byte **)(unaff_EBP + -0x1c),(byte *)"MS Sans Serif");
          if (iVar2 != 0) {
            iVar2 = FUN_00403360(*(byte **)(unaff_EBP + -0x1c),&DAT_0041d034);
            if (iVar2 != 0) {
              bVar6 = false;
              goto LAB_0040e510;
            }
          }
          bVar6 = true;
          if (*(short *)(unaff_EBP + -0x18) == 8) {
            *(undefined4 *)(unaff_EBP + -0x18) = 0;
          }
        }
LAB_0040e510:
        if (bVar6) goto LAB_0040e514;
      }
      if (*(int *)(unaff_EBP + -0x14) != 0) {
        pvVar4 = GlobalLock(*(HGLOBAL *)(unaff_EBP + -0x14));
        *(LPVOID *)(unaff_EBP + 8) = pvVar4;
      }
      extraout_ECX[0xb] = -1;
      extraout_ECX[9] = extraout_ECX[9] | 0x10;
      FUN_0040bbee((int)extraout_ECX);
      if (*(int *)(unaff_EBP + 0xc) == 0) {
        pHVar5 = (HWND)0x0;
      }
      else {
        pHVar5 = *(HWND *)(*(int *)(unaff_EBP + 0xc) + 0x1c);
      }
      pHVar5 = CreateDialogIndirectParamA
                         (*(HINSTANCE *)(unaff_EBP + 0x10),*(LPCDLGTEMPLATEA *)(unaff_EBP + 8),
                          pHVar5,(DLGPROC)&LAB_0040e255,0);
      *(HWND *)(unaff_EBP + -0x20) = pHVar5;
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0040ff87((int *)(unaff_EBP + -0x1c));
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (*(int **)(unaff_EBP + -0x28) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_EBP + -0x28) + 0x14))(unaff_EBP + -0x34);
        if (*(int *)(unaff_EBP + -0x20) != 0) {
          (**(code **)(*extraout_ECX + 0xbc))(0);
        }
      }
      iVar2 = FUN_0040bc3a();
      if (iVar2 == 0) {
        (**(code **)(*extraout_ECX + 0xac))();
      }
      pHVar5 = *(HWND *)(unaff_EBP + -0x20);
      if ((pHVar5 != (HWND)0x0) && ((*(byte *)(extraout_ECX + 9) & 0x10) == 0)) {
        DestroyWindow(pHVar5);
        pHVar5 = (HWND)0x0;
      }
      if (*(int *)(unaff_EBP + -0x14) != 0) {
        GlobalUnlock(*(HGLOBAL *)(unaff_EBP + -0x14));
        GlobalFree(*(HGLOBAL *)(unaff_EBP + -0x14));
      }
      bVar6 = pHVar5 != (HWND)0x0;
      goto LAB_0040e61a;
    }
  }
  else {
    iVar2 = (**(code **)(*extraout_ECX + 0xbc))(unaff_EBP + -0x34);
    if (iVar2 != 0) {
      uVar3 = (**(code **)(*piVar1 + 0x10))(unaff_EBP + -0x34,*(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + 8) = uVar3;
      goto LAB_0040e488;
    }
  }
  bVar6 = false;
LAB_0040e61a:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return bVar6;
}



/* VA 0040e63d */

undefined4 * __thiscall FUN_0040e63d(void *this,uint param_1,undefined4 param_2)

{
  FUN_0040b374(this);
  *(undefined ***)this = &PTR_LAB_0041cf5c;
  _memset((uint *)((int)this + 0x3c),0,0x20);
  *(undefined4 *)((int)this + 0x50) = param_2;
  *(uint *)((int)this + 0x3c) = param_1;
  *(uint *)((int)this + 0x40) = param_1 & 0xffff;
  return this;
}



/* VA 0040e676 */

undefined4 __fastcall FUN_0040e676(int param_1)

{
  int iVar1;
  undefined4 uVar2;

  FUN_00419dc2();
  FUN_00412759(0);
  iVar1 = FUN_0040ce64(*(int *)(param_1 + 0x50),(undefined4 *)(param_1 + 0x54));
  FUN_0040bbee(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x1c);
  }
  return uVar2;
}



/* VA 0040e6ad */

void __fastcall FUN_0040e6ad(int param_1)

{
  BOOL BVar1;

  FUN_0040bc3a();
  FUN_0040b75a(param_1);
  BVar1 = IsWindow(*(HWND *)(param_1 + 0x54));
  if (BVar1 != 0) {
    EnableWindow(*(HWND *)(param_1 + 0x54),1);
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  FUN_00419dc2();
  FUN_00412759(1);
  return;
}



/* VA 0040e850 */

void __thiscall FUN_0040e850(void *this,INT_PTR param_1)

{
  if ((*(byte *)((int)this + 0x24) & 0x18) != 0) {
    (**(code **)(*(int *)this + 0x7c))(param_1);
  }
  EndDialog(*(HWND *)((int)this + 0x1c),param_1);
  return;
}



/* VA 0040e898 */

int __fastcall FUN_0040e898(int *param_1)

{
  int *piVar1;
  int iVar2;
  CWnd *pCVar3;

  (**(code **)(*param_1 + 0xd4))();
  iVar2 = FUN_00419dc2();
  piVar1 = *(int **)(iVar2 + 0x1038);
  if ((piVar1 != (int *)0x0) && (iVar2 = param_1[0x16], iVar2 != 0)) {
    if (param_1[0x13] == 0) {
      iVar2 = (**(code **)(*piVar1 + 0x20))(param_1,param_1[0x10],iVar2);
    }
    else {
      iVar2 = (**(code **)(*piVar1 + 0x1c))(param_1,param_1[0x13],iVar2);
    }
    if (iVar2 == 0) {
      FUN_0040e850(param_1,-1);
      return 0;
    }
  }
  iVar2 = FUN_0040b632(param_1);
  if ((iVar2 != 0) && ((*(byte *)((int)param_1 + 0x25) & 1) != 0)) {
    GetNextDlgTabItem((HWND)param_1[7],(HWND)0x0,0);
    pCVar3 = FUN_0040b6dd();
    if (pCVar3 != (CWnd *)0x0) {
      FUN_0040ecf8((int)pCVar3);
      iVar2 = 0;
    }
  }
  return iVar2;
}



/* VA 0040e920 */

undefined4 FUN_0040e920(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined1 local_c [8];

  iVar1 = FUN_00419dc2();
  uVar3 = 0;
  if (*(int *)(iVar1 + 4) != 0) {
    piVar2 = (int *)FUN_00401858();
    if ((piVar2 != (int *)0x0) &&
       (iVar1 = (**(code **)(*piVar2 + 0x14))(0xe146,0,0,local_c), iVar1 != 0)) {
      return 1;
    }
    iVar1 = FUN_00419dc2();
    uVar3 = (**(code **)(**(int **)(iVar1 + 4) + 0x14))(0xe146,0,0,local_c);
  }
  return uVar3;
}



/* VA 0040e977 */

undefined4 __fastcall FUN_0040e977(void *param_1)

{
  ushort *puVar1;
  int iVar2;
  void *this;

  if (*(ushort **)((int)param_1 + 0x4c) == (ushort *)0x0) {
    puVar1 = FUN_0040dd1b(param_1,*(LPCSTR *)((int)param_1 + 0x40));
  }
  else {
    puVar1 = FUN_0040dd6b(param_1,*(ushort **)((int)param_1 + 0x4c));
  }
  if (puVar1 != (ushort *)0x0) {
    iVar2 = FUN_0040dae4();
    if (iVar2 != 0) {
      this = (void *)FUN_0040eaf1(param_1,0xe146);
      if (this != (void *)0x0) {
        iVar2 = FUN_0040e920();
        FUN_0040ec8f(this,-(uint)(iVar2 != 0) & 5);
      }
      return 1;
    }
  }
  FUN_0040e850(param_1,-1);
  return 0;
}



/* VA 0040e9dc */

void __fastcall FUN_0040e9dc(void *param_1)

{
  int iVar1;

  iVar1 = FUN_0040dae4();
  if (iVar1 != 0) {
    FUN_0040e850(param_1,1);
  }
  return;
}



/* VA 0040e9fd */

undefined4 __fastcall FUN_0040e9fd(int param_1)

{
  short sVar1;
  HMODULE hModule;
  int iVar2;
  HRSRC hResInfo;
  HGLOBAL hResData;
  uint *puVar3;
  undefined4 uVar4;
  uint uVar5;
  short sVar6;

  puVar3 = *(uint **)(param_1 + 0x48);
  hResData = *(HGLOBAL *)(param_1 + 0x44);
  if (*(int *)(param_1 + 0x40) != 0) {
    iVar2 = FUN_00419dc2();
    hModule = *(HMODULE *)(iVar2 + 0xc);
    hResInfo = FindResourceA(hModule,*(LPCSTR *)(param_1 + 0x40),(LPCSTR)0x5);
    hResData = LoadResource(hModule,hResInfo);
  }
  if (hResData != (HGLOBAL)0x0) {
    puVar3 = LockResource(hResData);
  }
  uVar4 = 1;
  if (puVar3 != (uint *)0x0) {
    uVar5 = *puVar3;
    if (*(short *)((int)puVar3 + 2) == -1) {
      uVar5 = puVar3[3];
      sVar1 = *(short *)((int)puVar3 + 0x12);
      sVar6 = (short)puVar3[5];
    }
    else {
      sVar1 = *(short *)((int)puVar3 + 10);
      sVar6 = (short)puVar3[3];
    }
    if ((((uVar5 & 0x1801) == 0) && (sVar1 == 0)) && (sVar6 == 0)) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
  }
  return uVar4;
}



/* VA 0040eaf1 */

void __thiscall FUN_0040eaf1(void *this,int param_1)

{
  if (*(int **)((int)this + 0x34) == (int *)0x0) {
    GetDlgItem(*(HWND *)((int)this + 0x1c),param_1);
    FUN_0040b6dd();
  }
  else {
    (**(code **)(**(int **)((int)this + 0x34) + 0x78))(param_1);
  }
  return;
}



/* VA 0040eb1b */

void __thiscall FUN_0040eb1b(void *this,LPMSG param_1)

{
  int iVar1;

  if ((*(byte *)((int)this + 0x25) & 1) == 0) {
    IsDialogMessageA(*(HWND *)((int)this + 0x1c),param_1);
  }
  else {
    iVar1 = FUN_00419dc2();
    (**(code **)(**(int **)(iVar1 + 0x1038) + 0x24))(this,param_1);
  }
  return;
}



/* VA 0040eb4e */

void __fastcall FUN_0040eb4e(int param_1)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    GetWindowLongA(*(HWND *)(param_1 + 0x1c),-0x10);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0040eb65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x38) + 0x78))();
  return;
}



/* VA 0040eb68 */

void __fastcall FUN_0040eb68(int param_1)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    GetWindowLongA(*(HWND *)(param_1 + 0x1c),-0x14);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0040eb7f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x38) + 0x7c))();
  return;
}



/* VA 0040ebb6 */

void __thiscall FUN_0040ebb6(void *this,uint param_1,uint param_2,uint param_3)

{
  if (*(int **)((int)this + 0x38) == (int *)0x0) {
    FUN_0040b457(*(HWND *)((int)this + 0x1c),param_1,param_2,param_3);
  }
  else {
    (**(code **)(**(int **)((int)this + 0x38) + 0x84))(param_1,param_2,param_3);
  }
  return;
}



/* VA 0040ebea */

void __thiscall FUN_0040ebea(void *this,LPCSTR param_1)

{
  if (*(int **)((int)this + 0x38) == (int *)0x0) {
    SetWindowTextA(*(HWND *)((int)this + 0x1c),param_1);
  }
  else {
    (**(code **)(**(int **)((int)this + 0x38) + 0x88))(param_1);
  }
  return;
}



/* VA 0040ec11 */

void __thiscall FUN_0040ec11(void *this,LPSTR param_1,int param_2)

{
  if (*(int **)((int)this + 0x38) == (int *)0x0) {
    GetWindowTextA(*(HWND *)((int)this + 0x1c),param_1,param_2);
  }
  else {
    (**(code **)(**(int **)((int)this + 0x38) + 0x8c))(param_1,param_2);
  }
  return;
}



/* VA 0040ec40 */

void __thiscall
FUN_0040ec40(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,UINT param_6)

{
  HWND hWndInsertAfter;

  if (*(int **)((int)this + 0x38) == (int *)0x0) {
    hWndInsertAfter = (HWND)0x0;
    if (param_1 != 0) {
      hWndInsertAfter = *(HWND *)(param_1 + 0x1c);
    }
    SetWindowPos(*(HWND *)((int)this + 0x1c),hWndInsertAfter,param_2,param_3,param_4,param_5,param_6
                );
  }
  else {
    (**(code **)(**(int **)((int)this + 0x38) + 0xa4))
              (param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return;
}



/* VA 0040ec8f */

void __thiscall FUN_0040ec8f(void *this,int param_1)

{
  if (*(int **)((int)this + 0x38) == (int *)0x0) {
    ShowWindow(*(HWND *)((int)this + 0x1c),param_1);
  }
  else {
    (**(code **)(**(int **)((int)this + 0x38) + 0xa8))(param_1);
  }
  return;
}



/* VA 0040ecb6 */

void __fastcall FUN_0040ecb6(int param_1)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    IsWindowEnabled(*(HWND *)(param_1 + 0x1c));
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0040eccb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x38) + 0xac))();
  return;
}



/* VA 0040ecd1 */

void __thiscall FUN_0040ecd1(void *this,BOOL param_1)

{
  if (*(int **)((int)this + 0x38) == (int *)0x0) {
    EnableWindow(*(HWND *)((int)this + 0x1c),param_1);
  }
  else {
    (**(code **)(**(int **)((int)this + 0x38) + 0xb0))(param_1);
  }
  return;
}



/* VA 0040ecf8 */

void __fastcall FUN_0040ecf8(int param_1)

{
  if (*(int **)(param_1 + 0x38) == (int *)0x0) {
    SetFocus(*(HWND *)(param_1 + 0x1c));
    FUN_0040b6dd();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0040ed13. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x38) + 0xb4))();
  return;
}



/* VA 0040ed19 */

/* Library Function - Single Match
    protected: void __thiscall CWnd::AttachControlSite(class CHandleMap *)

   Library: Visual Studio 1998 Release */

void __thiscall CWnd::AttachControlSite(CWnd *this,CHandleMap *param_1)

{
  HWND pHVar1;
  int iVar2;

  if ((this != (CWnd *)0x0) && (*(int *)(this + 0x38) == 0)) {
    pHVar1 = GetParent(*(HWND *)(this + 0x1c));
    iVar2 = FUN_0040aec1(param_1,(uint)pHVar1);
    if (iVar2 != 0) {
      FUN_0040ed49(this,iVar2);
    }
  }
  return;
}



/* VA 0040ed49 */

void __thiscall FUN_0040ed49(void *this,int param_1)

{
  int iVar1;
  int iVar2;

  if ((((this != (void *)0x0) && (*(int *)((int)this + 0x38) == 0)) && (param_1 != 0)) &&
     (*(int *)(param_1 + 0x34) != 0)) {
    iVar2 = FUN_0040aec1((void *)(*(int *)(param_1 + 0x34) + 0x20),*(uint *)((int)this + 0x1c));
    if (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x24);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0x38) == iVar2)) {
        *(undefined4 *)(iVar1 + 0x38) = 0;
      }
      *(int *)((int)this + 0x38) = iVar2;
      *(void **)(iVar2 + 0x24) = this;
    }
  }
  return;
}



/* VA 0040ed8e */

void __fastcall FUN_0040ed8e(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_0041d15c;
  param_1[1] = 1;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 1;
  param_1[6] = 0;
  return;
}



/* VA 0040edae */

undefined * __thiscall FUN_0040edae(void *this,byte param_1)

{
  FUN_0040edca();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 0040edca */

void FUN_0040edca(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041d15c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (extraout_ECX[4] != 0) {
    (**(code **)(extraout_ECX[4] + 0x1c))();
  }
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d1bc;
  *unaff_FS_OFFSET = uVar1;
  return;
}



/* VA 0040ee06 */

uint __thiscall
FUN_0040ee06(void *this,undefined4 *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  void *_Buf1;
  int iVar1;
  undefined4 *puVar2;
  AFX_MSGMAP_ENTRY *pAVar3;
  uint uVar4;
  int *piVar5;

  if (param_2 == 0xfffffffe) {
    iVar1 = FUN_00419dc2();
    param_2 = (**(code **)(**(int **)(iVar1 + 0x1038) + 4))(this,param_1,param_3,param_4);
  }
  else {
    uVar4 = 0;
    if (param_2 == 0xfffffffd) {
      param_2 = 0;
      _Buf1 = (void *)param_3[0xc];
      puVar2 = (undefined4 *)(**(code **)(*(int *)this + 0x34))();
      while ((puVar2 != (undefined4 *)0x0 && (param_2 == 0))) {
        piVar5 = (int *)puVar2[1];
        while ((((undefined4 *)piVar5[1] != (undefined4 *)0x0 && (piVar5[2] != 0)) && (param_2 == 0)
               )) {
          if (param_1 == (undefined4 *)piVar5[1]) {
            if (_Buf1 == (void *)0x0) {
              iVar1 = *piVar5;
            }
            else {
              if ((void *)*piVar5 == (void *)0x0) goto LAB_0040eeab;
              iVar1 = _memcmp(_Buf1,(void *)*piVar5,0x10);
            }
            if (iVar1 == 0) {
              param_2 = 1;
              param_3[1] = piVar5[2];
            }
          }
LAB_0040eeab:
          piVar5 = piVar5 + 3;
        }
        puVar2 = (undefined4 *)*puVar2;
      }
    }
    else {
      if (param_2 != 0xffffffff) {
        uVar4 = param_2 >> 0x10;
        param_2 = param_2 & 0xffff;
      }
      if (uVar4 == 0) {
        uVar4 = 0x111;
      }
      for (puVar2 = (undefined4 *)(**(code **)(*(int *)this + 0x30))(); puVar2 != (undefined4 *)0x0;
          puVar2 = (undefined4 *)*puVar2) {
        pAVar3 = AfxFindMessageEntry((AFX_MSGMAP_ENTRY *)puVar2[1],uVar4,param_2,(uint)param_1);
        if (pAVar3 != (AFX_MSGMAP_ENTRY *)0x0) {
          uVar4 = FUN_0040ef1e(this,param_1,param_2,*(undefined **)(pAVar3 + 0x14),param_3,
                               *(uint *)(pAVar3 + 0x10),param_4);
          return uVar4;
        }
      }
      param_2 = 0;
    }
  }
  return param_2;
}



/* VA 0040ef1e */

uint __cdecl
FUN_0040ef1e(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined *param_4,
            undefined4 *param_5,uint param_6,undefined4 *param_7)

{
  uint uVar1;

  uVar1 = 1;
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = param_1;
    param_7[1] = param_4;
    return 1;
  }
  if (param_6 < 0xd) {
    if (param_6 == 0xc) {
      (*(code *)param_4)();
      return 1;
    }
    param_5 = param_2;
    if (param_6 != 2) {
      return 0;
    }
LAB_0040f013:
    uVar1 = (*(code *)param_4)(param_5);
    return uVar1;
  }
  if (param_6 < 0x24) {
    if (param_6 == 0x23) {
      uVar1 = (*(code *)param_4)();
      return uVar1;
    }
    param_5 = param_2;
    if (param_6 != 0xd) {
      return 0;
    }
LAB_0040f008:
    (*(code *)param_4)(param_5);
    return 1;
  }
  switch(param_6) {
  case 0x26:
    (*(code *)param_4)(param_5[1],*param_5);
    break;
  case 0x27:
    uVar1 = (*(code *)param_4)(param_5[1],*param_5);
    break;
  case 0x28:
    (*(code *)param_4)(param_2,param_5[1],*param_5);
    break;
  case 0x29:
    uVar1 = (*(code *)param_4)(param_2,param_5[1],*param_5);
    break;
  default:
    return 0;
  case 0x2c:
    (*(code *)param_4)(param_5);
    goto LAB_0040eff7;
  case 0x2d:
    (*(code *)param_4)(param_5,param_2);
LAB_0040eff7:
    uVar1 = (uint)(param_5[7] == 0);
    param_5[7] = 0;
    break;
  case 0x2e:
    goto LAB_0040f008;
  case 0x2f:
    goto LAB_0040f013;
  }
  return uVar1;
}



/* VA 0040f066 */

void FUN_0040f066(void)

{
  int iVar1;

  iVar1 = FUN_00419dc2();
  (**(code **)(**(int **)(iVar1 + 4) + 0x98))(1);
  return;
}



/* VA 0040f07b */

void FUN_0040f07b(void)

{
  int iVar1;

  iVar1 = FUN_00419dc2();
  (**(code **)(**(int **)(iVar1 + 4) + 0x98))(0xffffffff);
  return;
}



/* VA 0040f0a8 */

/* Library Function - Single Match
    public: virtual void __thiscall CCmdTarget::OnFinalRelease(void)

   Library: Visual Studio 1998 Release */

void __thiscall CCmdTarget::OnFinalRelease(CCmdTarget *this)

{
  int iVar1;
  CTypeLibCache *this_00;

  FUN_0041adc3(0xd);
  iVar1 = *(int *)this;
  this_00 = (CTypeLibCache *)(**(code **)(iVar1 + 0x28))();
  if (this_00 != (CTypeLibCache *)0x0) {
    CTypeLibCache::Unlock(this_00);
  }
  FUN_0041ae33(0xd);
  if (this != (CCmdTarget *)0x0) {
    (**(code **)(iVar1 + 4))(1);
  }
  return;
}



/* VA 0040f0f9 */

undefined4 FUN_0040f0f9(void)

{
  int iVar1;

  iVar1 = FUN_00419a6f();
  return *(undefined4 *)(iVar1 + 0xc4);
}



/* VA 0040f105 */

/* Library Function - Single Match
    public: __thiscall CCmdUI::CCmdUI(void)

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release,
   Visual Studio 2010 Release */

void __thiscall CCmdUI::CCmdUI(CCmdUI *this)

{
  *(undefined ***)this = &PTR_FUN_0041d1d4;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  return;
}



/* VA 0040f12b */

void __thiscall FUN_0040f12b(void *this,int param_1)

{
  HWND pHVar1;
  CWnd *pCVar2;
  HWND pHVar3;

  if (*(int *)((int)this + 0xc) == 0) {
    if (param_1 == 0) {
      pHVar3 = *(HWND *)(*(int *)((int)this + 0x14) + 0x1c);
      pHVar1 = GetFocus();
      if (pHVar1 == pHVar3) {
        GetParent(pHVar3);
        pCVar2 = FUN_0040b6dd();
        pHVar3 = (HWND)0x0;
        if (*(int *)((int)this + 0x14) != 0) {
          pHVar3 = *(HWND *)(*(int *)((int)this + 0x14) + 0x1c);
        }
        GetNextDlgTabItem(*(HWND *)(pCVar2 + 0x1c),pHVar3,0);
        pCVar2 = FUN_0040b6dd();
        FUN_0040ecf8((int)pCVar2);
      }
    }
    FUN_0040ecd1(*(void **)((int)this + 0x14),param_1);
  }
  else {
    if (*(int *)((int)this + 0x10) != 0) {
      return;
    }
    EnableMenuItem(*(HMENU *)(*(int *)((int)this + 0xc) + 4),*(UINT *)((int)this + 8),
                   (-(uint)(param_1 != 0) & 0xfffffffd) + 3 | 0x400);
  }
  *(undefined4 *)((int)this + 0x18) = 1;
  return;
}



/* VA 0040f1bb */

void __thiscall FUN_0040f1bb(void *this,WPARAM param_1)

{
  uint uVar1;

  if (*(int *)((int)this + 0xc) == 0) {
    uVar1 = SendMessageA(*(HWND *)(*(int *)((int)this + 0x14) + 0x1c),0x87,0,0);
    if ((uVar1 & 0x2000) != 0) {
      SendMessageA(*(HWND *)(*(int *)((int)this + 0x14) + 0x1c),0xf1,param_1,0);
    }
  }
  else if (*(int *)((int)this + 0x10) == 0) {
    CheckMenuItem(*(HMENU *)(*(int *)((int)this + 0xc) + 4),*(UINT *)((int)this + 8),
                  (uint)CONCAT11(4,-(param_1 != 0) & 8));
  }
  return;
}



/* VA 0040f21d */

void __thiscall FUN_0040f21d(void *this,int param_1)

{
  (**(code **)(*(int *)this + 4))(param_1 != 0);
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x10) == 0)) {
    if (DAT_00428838 == (HBITMAP)0x0) {
      FUN_0041945f();
    }
    if (DAT_00428838 != (HBITMAP)0x0) {
      SetMenuItemBitmaps(*(HMENU *)(*(int *)((int)this + 0xc) + 4),*(UINT *)((int)this + 8),0x400,
                         (HBITMAP)0x0,DAT_00428838);
    }
  }
  return;
}



/* VA 0040f26f */

void __thiscall FUN_0040f26f(void *this,LPCSTR param_1)

{
  UINT UVar1;

  if (*(int *)((int)this + 0xc) == 0) {
    FUN_0041162b(*(HWND *)(*(int *)((int)this + 0x14) + 0x1c),param_1);
  }
  else if (*(int *)((int)this + 0x10) == 0) {
    UVar1 = GetMenuState(*(HMENU *)(*(int *)((int)this + 0xc) + 4),*(UINT *)((int)this + 8),0x400);
    ModifyMenuA(*(HMENU *)(*(int *)((int)this + 0xc) + 4),*(UINT *)((int)this + 8),
                UVar1 & 0xfffff6fb | 0x400,*(UINT_PTR *)((int)this + 4),param_1);
  }
  return;
}



/* VA 0040f2c5 */

undefined4 __thiscall FUN_0040f2c5(void *this,int *param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 local_10 [2];
  undefined4 local_8;

  if ((*(int *)((int)this + 4) == 0) || (*(short *)((int)this + 4) == -1)) {
    local_8 = 1;
  }
  else {
    iVar1 = *param_1;
    *(undefined4 *)((int)this + 0x18) = 0;
    pcVar2 = *(code **)(iVar1 + 0x14);
    local_8 = (*pcVar2)(*(int *)((int)this + 4),0xffffffff,this,0);
    if ((param_2 != 0) && (*(int *)((int)this + 0x18) == 0)) {
      local_10[0] = 0;
      uVar3 = (*pcVar2)(*(undefined4 *)((int)this + 4),0,this,local_10);
      (*(code *)**(undefined4 **)this)(uVar3);
    }
  }
  return local_8;
}



/* VA 0040f334 */

undefined4 FUN_0040f334(undefined4 param_1)

{
  undefined4 uVar1;
  AFX_MODULE_THREAD_STATE *pAVar2;

  pAVar2 = AfxGetModuleThreadState();
  uVar1 = *(undefined4 *)(pAVar2 + 0x28);
  *(undefined4 *)(pAVar2 + 0x28) = param_1;
  return uVar1;
}



/* VA 0040f348 */

int __cdecl FUN_0040f348(uint param_1)

{
  int iVar1;
  AFX_MODULE_THREAD_STATE *pAVar2;
  code *pcVar3;

  pcVar3 = DAT_0041d5dc;
  while( true ) {
    iVar1 = FUN_00402cf0(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (pcVar3 == DAT_0041d5dc) {
      pAVar2 = AfxGetModuleThreadState();
      pcVar3 = *(code **)(pAVar2 + 0x28);
    }
    if (pcVar3 == (code *)0x0) break;
    iVar1 = (*pcVar3)(param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 0;
}



/* VA 0040f384 */

void __cdecl FUN_0040f384(undefined *param_1)

{
  FUN_00402c80(param_1);
  return;
}



/* VA 0040f38f */

/* Library Function - Single Match
    class CWinThread * __stdcall AfxGetThread(void)

   Library: Visual Studio 1998 Release */

CWinThread * AfxGetThread(void)

{
  AFX_MODULE_THREAD_STATE *pAVar1;
  int iVar2;
  CWinThread *pCVar3;

  pAVar1 = AfxGetModuleThreadState();
  pCVar3 = *(CWinThread **)(pAVar1 + 4);
  if (pCVar3 == (CWinThread *)0x0) {
    iVar2 = FUN_00419dc2();
    pCVar3 = *(CWinThread **)(iVar2 + 4);
  }
  return pCVar3;
}



/* VA 0040f3a4 */

void FUN_0040f3a4(void)

{
  int iVar1;
  DWORD dwThreadId;
  HHOOK pHVar2;
  int iVar3;

  iVar1 = FUN_00419dc2();
  if (*(char *)(iVar1 + 0x14) == '\0') {
    iVar1 = FUN_00419a6f();
    dwThreadId = GetCurrentThreadId();
    pHVar2 = SetWindowsHookExA(-1,(HOOKPROC)&LAB_0040f789,(HINSTANCE)0x0,dwThreadId);
    *(HHOOK *)(iVar1 + 0x30) = pHVar2;
    iVar1 = FUN_0041aa65();
    if (*(int *)(iVar1 + 0x14) != 0) {
      iVar3 = FUN_00419dc2();
      (**(code **)(iVar1 + 0x14))(*(undefined4 *)(iVar3 + 8));
    }
    FUN_0041a9d0(&DAT_0042898c,&LAB_00401db6);
  }
  return;
}



/* VA 0040f418 */

void __fastcall FUN_0040f418(int *param_1)

{
  int iVar1;
  bool bVar2;
  BOOL BVar3;
  int iVar4;
  int iVar5;

  bVar2 = true;
  iVar1 = *param_1;
  iVar5 = 0;
  do {
    if (bVar2) {
      iVar4 = iVar5;
      do {
        BVar3 = PeekMessageA((LPMSG)(param_1 + 0xc),(HWND)0x0,0,0,0);
        iVar5 = iVar4;
        if (BVar3 != 0) break;
        iVar5 = iVar4 + 1;
        iVar4 = (**(code **)(iVar1 + 0x68))(iVar4);
        if (iVar4 == 0) {
          bVar2 = false;
        }
        iVar4 = iVar5;
      } while (bVar2);
    }
    do {
      iVar4 = (**(code **)(iVar1 + 100))();
      if (iVar4 == 0) {
        (**(code **)(iVar1 + 0x70))();
        return;
      }
      iVar4 = (**(code **)(iVar1 + 0x6c))((LPMSG)(param_1 + 0xc));
      if (iVar4 != 0) {
        bVar2 = true;
        iVar5 = 0;
      }
      BVar3 = PeekMessageA((LPMSG)(param_1 + 0xc),(HWND)0x0,0,0,0);
    } while (BVar3 != 0);
  } while( true );
}



/* VA 0040f4fb */

bool __thiscall FUN_0040f4fb(void *this,int param_1)

{
  void *pvVar1;
  BOOL BVar2;
  int iVar3;
  void *this_00;

  if (param_1 < 1) {
    pvVar1 = *(void **)((int)this + 0x1c);
    if ((pvVar1 != (void *)0x0) && (*(HWND *)((int)pvVar1 + 0x1c) != (HWND)0x0)) {
      BVar2 = IsWindowVisible(*(HWND *)((int)pvVar1 + 0x1c));
      if (BVar2 != 0) {
        FUN_0040b471();
        FUN_0040cf7d(*(HWND *)((int)pvVar1 + 0x1c),0x363,1,0,1,1);
      }
    }
    iVar3 = FUN_00419dc2();
    iVar3 = FUN_0041a9d0((void *)(iVar3 + 0x1070),FUN_00401a57);
    for (this_00 = *(void **)(iVar3 + 8); this_00 != (void *)0x0;
        this_00 = *(void **)((int)this_00 + 0x54)) {
      if ((*(int *)((int)this_00 + 0x1c) != 0) && (this_00 != pvVar1)) {
        if (*(int *)((int)this_00 + 0x88) == 0) {
          FUN_0040ec8f(this_00,0);
        }
        BVar2 = IsWindowVisible(*(HWND *)((int)this_00 + 0x1c));
        if ((BVar2 != 0) || (-1 < *(int *)((int)this_00 + 0x88))) {
          FUN_0040b471();
          FUN_0040cf7d(*(HWND *)((int)this_00 + 0x1c),0x363,1,0,1,1);
        }
        if (0 < *(int *)((int)this_00 + 0x88)) {
          FUN_0040ec8f(this_00,*(int *)((int)this_00 + 0x88));
        }
        *(undefined4 *)((int)this_00 + 0x88) = 0xffffffff;
      }
    }
  }
  else {
    iVar3 = FUN_00419dc2();
    iVar3 = FUN_0041a9d0((void *)(iVar3 + 0x1070),FUN_00401a57);
    if (*(int *)(iVar3 + 0x10) == 0) {
      FUN_00410206();
      FUN_0041020f(1);
    }
  }
  return param_1 < 0;
}



/* VA 0040f606 */

undefined4 __thiscall FUN_0040f606(void *this,int param_1)

{
  undefined4 *puVar1;
  AFX_MSGMAP_ENTRY *pAVar2;

  puVar1 = (undefined4 *)(**(code **)(*(int *)this + 0x30))();
  do {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if (*(uint *)(param_1 + 4) < 0xc000) {
      pAVar2 = AfxFindMessageEntry((AFX_MSGMAP_ENTRY *)puVar1[1],*(uint *)(param_1 + 4),0,0);
      if (pAVar2 != (AFX_MSGMAP_ENTRY *)0x0) {
LAB_0040f643:
        (**(code **)(pAVar2 + 0x14))(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
    else {
      pAVar2 = (AFX_MSGMAP_ENTRY *)puVar1[1];
      while (pAVar2 = AfxFindMessageEntry(pAVar2,0xc000,0,0), pAVar2 != (AFX_MSGMAP_ENTRY *)0x0) {
        if (**(int **)(pAVar2 + 0x10) == *(int *)(param_1 + 4)) goto LAB_0040f643;
        pAVar2 = pAVar2 + 0x18;
      }
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}



/* VA 0040f67f */

undefined4 __thiscall FUN_0040f67f(void *this,int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  int *piVar6;
  undefined4 uVar7;

  if ((*param_1 != 0) || (iVar2 = FUN_0040f606(this,(int)param_1), iVar2 == 0)) {
    uVar1 = param_1[1];
    if (((uVar1 < 0x100) || (0x108 < uVar1)) && ((uVar1 < 0x104 || (0x107 < uVar1)))) {
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
    }
    if (((((iVar2 != 0) || (uVar1 == 0x201)) || (uVar1 == 0x203)) ||
        (((uVar1 == 0x204 || (uVar1 == 0x206)) ||
         ((uVar1 == 0x207 || ((uVar1 == 0x209 || (uVar1 == 0xa1)))))))) ||
       ((uVar1 == 0xa3 ||
        ((((uVar1 == 0xa4 || (uVar1 == 0xa6)) || (uVar1 == 0xa7)) || (uVar1 == 0xa9)))))) {
      FUN_0040c038(iVar2);
    }
    piVar3 = (int *)FUN_00401858();
    pHVar4 = (HWND)0x0;
    if (piVar3 != (int *)0x0) {
      pHVar4 = (HWND)piVar3[7];
    }
    iVar2 = FUN_0040d490(pHVar4,param_1);
    if (iVar2 == 0) {
      if (piVar3 != (int *)0x0) {
        pCVar5 = FUN_0040b6dd();
        piVar6 = (int *)FUN_0040cd3c((int)pCVar5);
        if (piVar6 != piVar3) {
          uVar7 = (**(code **)(*piVar3 + 0x98))(param_1);
          return uVar7;
        }
      }
      return 0;
    }
  }
  return 1;
}



/* VA 0040f764 */

/* Library Function - Single Match
    long __stdcall AfxInternalProcessWndProcException(class CException *,struct tagMSG const *)

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

long AfxInternalProcessWndProcException(CException *param_1,tagMSG *param_2)

{
  long lVar1;

  if (param_2->message == 1) {
    lVar1 = -1;
  }
  else {
    if (param_2->message == 0xf) {
      ValidateRect(param_2->hwnd,(RECT *)0x0);
    }
    lVar1 = 0;
  }
  return lVar1;
}



/* VA 0040f7e1 */

undefined4 FUN_0040f7e1(int param_1,undefined4 *param_2)

{
  CWnd *pCVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  HWND hWnd;
  undefined4 local_24 [7];
  int *local_8;

  if (param_2 == (undefined4 *)0x0) {
    return 0;
  }
  if (param_1 != 0) {
    if (param_1 != 2) {
      return 0;
    }
    pCVar1 = FUN_0040b6dd();
    if (((((pCVar1 != (CWnd *)0x0) && (pCVar1 = FUN_0040ce20(pCVar1), pCVar1 != (CWnd *)0x0)) &&
         (iVar2 = FUN_0040e236((int)pCVar1), iVar2 != 0)) &&
        ((*(int *)(pCVar1 + 0x50) != 0 &&
         (iVar2 = FUN_00401858(), *(int *)((int)local_8 + 0x1c) != 0)))) &&
       (((param_2[1] == 0x100 && (param_2[2] == 0xd)) || (param_2[1] == 0x202)))) {
      hWnd = *(HWND *)(iVar2 + 0x1c);
      goto LAB_0040f89c;
    }
  }
  iVar2 = FUN_00401858();
  if (((0x332 < DAT_0042883c) || (iVar2 == 0)) || (iVar3 = FUN_0040f928((int)param_2), iVar3 == 0))
  {
    if ((((param_1 != 0) || (local_8[8] == 0)) || ((uint)param_2[1] < 0x100)) ||
       ((0x108 < (uint)param_2[1] ||
        (iVar2 = FUN_0041a9d0(&DAT_00428660,FUN_00401abc), *(int *)(iVar2 + 0xbc) != 0)))) {
      return 0;
    }
    *(undefined4 *)(iVar2 + 0xbc) = 1;
    puVar4 = local_24;
    for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *param_2;
      param_2 = param_2 + 1;
      puVar4 = puVar4 + 1;
    }
    iVar3 = FUN_0040ecb6(local_8[8]);
    if ((iVar3 != 0) && (iVar3 = (**(code **)(*local_8 + 0x60))(local_24), iVar3 != 0)) {
      *(undefined4 *)(iVar2 + 0xbc) = 0;
      return 1;
    }
    *(undefined4 *)(iVar2 + 0xbc) = 0;
    return 0;
  }
  hWnd = *(HWND *)(iVar2 + 0x1c);
LAB_0040f89c:
  SendMessageA(hWnd,0x111,0xe146,0);
  return 1;
}



/* VA 0040f928 */

undefined4 FUN_0040f928(int param_1)

{
  SHORT SVar1;

  if ((((*(int *)(param_1 + 4) == 0x100) && (*(int *)(param_1 + 8) == 0x70)) &&
      ((*(uint *)(param_1 + 0xc) >> 0x10 & 0x4000) == 0)) &&
     (((SVar1 = GetKeyState(0x10), -1 < SVar1 && (SVar1 = GetKeyState(0x11), -1 < SVar1)) &&
      (SVar1 = GetKeyState(0x12), -1 < SVar1)))) {
    return 1;
  }
  return 0;
}



/* VA 0040f98e */

undefined4 __fastcall FUN_0040f98e(int *param_1)

{
  LPMSG lpMsg;
  BOOL BVar1;
  int iVar2;
  undefined4 uVar3;

  lpMsg = (LPMSG)(param_1 + 0xc);
  BVar1 = GetMessageA(lpMsg,(HWND)0x0,0,0);
  uVar3 = 0;
  if (BVar1 != 0) {
    if (param_1[0xd] != 0x36a) {
      iVar2 = (**(code **)(*param_1 + 0x60))(lpMsg);
      if (iVar2 == 0) {
        TranslateMessage(lpMsg);
        DispatchMessageA(lpMsg);
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}



/* VA 0040f9ce */

bool FUN_0040f9ce(UINT param_1)

{
  int iVar1;
  LPSTR pCVar2;
  int iVar3;
  int iVar4;
  CHAR local_108 [256];
  void *local_8;

  iVar1 = FUN_0040fa52(param_1,local_108,0x100);
  if (0x100U - iVar1 < 3) {
    iVar3 = 0x100;
    do {
      iVar4 = iVar3 + 0x100;
      iVar1 = iVar4;
      pCVar2 = (LPSTR)FUN_00410004(local_8,iVar3 + 0xff);
      iVar1 = FUN_0040fa52(param_1,pCVar2,iVar1);
      iVar3 = iVar4;
    } while (iVar4 - iVar1 < 3);
    FUN_00410053(local_8,-1);
  }
  else {
    FUN_0040ffdd(local_8,local_108);
  }
  return 0 < iVar1;
}



/* VA 0040fa52 */

void FUN_0040fa52(UINT param_1,LPSTR param_2,int param_3)

{
  int iVar1;

  iVar1 = FUN_00419dc2();
  iVar1 = LoadStringA(*(HINSTANCE *)(iVar1 + 0xc),param_1,param_2,param_3);
  if (iVar1 == 0) {
    *param_2 = '\0';
  }
  return;
}



/* VA 0040fa79 */

undefined4 FUN_0040fa79(int *param_1,byte *param_2,int param_3,char param_4)

{
  byte *pbVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;

  if (param_2 == (byte *)0x0) {
LAB_0040faed:
    uVar4 = 0;
  }
  else {
    if (param_3 != 0) {
      do {
        param_3 = param_3 + -1;
        pbVar1 = FUN_00403240(param_2,(int)param_4);
        if (pbVar1 == (byte *)0x0) {
          FUN_0040ff12(param_1);
          goto LAB_0040faed;
        }
        param_2 = pbVar1 + 1;
      } while (param_3 != 0);
    }
    pbVar1 = FUN_00403240(param_2,(int)param_4);
    if (pbVar1 == (byte *)0x0) {
      uVar2 = lstrlenA((LPCSTR)param_2);
    }
    else {
      uVar2 = (int)pbVar1 - (int)param_2;
    }
    puVar3 = (undefined4 *)FUN_0041007b(param_1,uVar2);
    FUN_00403510(puVar3,(undefined4 *)param_2,uVar2);
    uVar4 = 1;
  }
  return uVar4;
}



/* VA 0040faf1 */

void FUN_0040faf1(void)

{
  int iVar1;

  iVar1 = FUN_0040fb05();
  if (iVar1 != 0) {
    FUN_00410434(iVar1);
    return;
  }
  return;
}



/* VA 0040fb05 */

undefined4 FUN_0040fb05(void)

{
  AFX_MODULE_THREAD_STATE *pAVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  pAVar1 = AfxGetModuleThreadState();
  if ((*(int *)(pAVar1 + 0x18) == 0) && (*(int *)(unaff_EBP + 8) != 0)) {
    uVar2 = FUN_0040f334(&LAB_00411749);
    iVar3 = FUN_0040f348(0x44);
    *(int *)(unaff_EBP + 8) = iVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar3 == 0) {
      pvVar4 = (void *)0x0;
    }
    else {
      pvVar4 = FUN_004102fd();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(void **)(pAVar1 + 0x18) = pvVar4;
    FUN_0040f334(uVar2);
  }
  uVar2 = *(undefined4 *)(pAVar1 + 0x18);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}



/* VA 0040fb75 */

void FUN_0040fb75(void)

{
  FUN_0040fb05();
  FUN_00410359();
  return;
}



/* VA 0040fb8b */

undefined4 FUN_0040fb8b(uint param_1)

{
  void *this;
  undefined4 uVar1;

  this = (void *)FUN_0040fb05();
  uVar1 = 0;
  if (this != (void *)0x0) {
    uVar1 = FUN_0040aec1(this,param_1);
  }
  return uVar1;
}



/* VA 0040fba7 */

int __fastcall FUN_0040fba7(int param_1)

{
  int iVar1;
  void *this;

  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    this = (void *)FUN_0040fb05();
    if (this != (void *)0x0) {
      FUN_0040af44(this,*(uint *)(param_1 + 4));
    }
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return iVar1;
}



/* VA 0040fbd1 */

BOOL __fastcall FUN_0040fbd1(int param_1)

{
  HMENU hMenu;
  BOOL BVar1;

  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  hMenu = (HMENU)FUN_0040fba7(param_1);
  BVar1 = DestroyMenu(hMenu);
  return BVar1;
}



/* VA 0040fbf3 */

void __thiscall FUN_0040fbf3(void *this,int param_1)

{
  void *this_00;

  this_00 = (void *)(*(code *)**(undefined4 **)this)();
  FUN_0040fc6b(this_00,param_1);
  return;
}



/* VA 0040fc05 */

void * __cdecl FUN_0040fc05(int param_1,void *param_2)

{
  int iVar1;

  if (param_2 != (void *)0x0) {
    iVar1 = FUN_0040fbf3(param_2,param_1);
    if (iVar1 != 0) {
      return param_2;
    }
  }
  return (void *)0x0;
}



/* VA 0040fc25 */

undefined4 FUN_0040fc25(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  uVar2 = 0;
  iVar1 = *(int *)(extraout_ECX + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  if (iVar1 != 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar2 = (**(code **)(extraout_ECX + 0xc))();
    *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    uVar2 = *(undefined4 *)(unaff_EBP + -0x14);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}



/* VA 0040fc6b */

undefined4 __thiscall FUN_0040fc6b(void *this,int param_1)

{
  while( true ) {
    if (this == (void *)0x0) {
      return 0;
    }
    if (this == (void *)param_1) break;
    this = *(void **)((int)this + 0x10);
  }
  return 1;
}



/* VA 0040fc8a */

void __fastcall FUN_0040fc8a(int *param_1)

{
  int iVar1;

  if (param_1[7] == 0) {
    iVar1 = FUN_00417abb();
    if (iVar1 != 0) {
      AfxPostQuitMessage(0);
    }
  }
  FUN_0040f418(param_1);
  return;
}



/* VA 0040fcac */

void __thiscall FUN_0040fcac(void *this,undefined4 param_1,undefined4 param_2)

{
  int *piVar1;

  piVar1 = (int *)FUN_00401858();
  *(undefined4 *)((int)this + 0x84) = 0;
  PostMessageA((HWND)piVar1[7],0x36a,0,0);
  (**(code **)(*piVar1 + 0x74))(param_1,param_2);
  return;
}



/* VA 0040fd5a */

bool __thiscall FUN_0040fd5a(void *this,int param_1)

{
  int iVar1;
  int *piVar2;

  iVar1 = param_1;
  if (param_1 < 1) {
    FUN_0040f4fb(this,param_1);
    param_1 = 0;
    if (*(int **)((int)this + 0x80) != (int *)0x0) {
      param_1 = (**(code **)(**(int **)((int)this + 0x80) + 0x18))();
    }
    while (param_1 != 0) {
      piVar2 = (int *)(**(code **)(**(int **)((int)this + 0x80) + 0x1c))(&param_1);
      (**(code **)(*piVar2 + 0x90))();
    }
  }
  else if (param_1 == 1) {
    FUN_0040f4fb(this,1);
  }
  return iVar1 < 1;
}



/* VA 0040fdc0 */

void __thiscall FUN_0040fdc0(void *this,LPSTR param_1)

{
  LPVOID pvVar1;
  int iVar2;
  BOOL BVar3;
  SIZE_T dwBytes;
  HGLOBAL hMem;
  PDEVMODEA pDevModeOutput;
  LONG LVar4;
  void *local_8;

  if (*(HGLOBAL *)((int)this + 0x98) != (HGLOBAL)0x0) {
    local_8 = this;
    pvVar1 = GlobalLock(*(HGLOBAL *)((int)this + 0x98));
    iVar2 = lstrcmpA((LPCSTR)((uint)*(ushort *)((int)pvVar1 + 2) + (int)pvVar1),param_1);
    if (iVar2 == 0) {
      BVar3 = OpenPrinterA(param_1,&local_8,(LPPRINTER_DEFAULTSA)0x0);
      if (BVar3 != 0) {
        if (*(HGLOBAL *)((int)this + 0x94) != (HGLOBAL)0x0) {
          FUN_00411713(*(HGLOBAL *)((int)this + 0x94));
        }
        dwBytes = DocumentPropertiesA((HWND)0x0,local_8,param_1,(PDEVMODEA)0x0,(PDEVMODEA)0x0,0);
        hMem = GlobalAlloc(0x42,dwBytes);
        *(HGLOBAL *)((int)this + 0x94) = hMem;
        pDevModeOutput = GlobalLock(hMem);
        LVar4 = DocumentPropertiesA((HWND)0x0,local_8,param_1,pDevModeOutput,(PDEVMODEA)0x0,2);
        if (LVar4 != 1) {
          FUN_00411713(*(HGLOBAL *)((int)this + 0x94));
          *(undefined4 *)((int)this + 0x94) = 0;
        }
        ClosePrinter(local_8);
      }
    }
  }
  return;
}



/* VA 0040fe6d */

undefined ** FUN_0040fe6d(void)

{
  return &PTR_DAT_0042356c;
}



/* VA 0040fe73 */

undefined4 * __fastcall FUN_0040fe73(undefined4 *param_1)

{
  undefined **ppuVar1;

  ppuVar1 = FUN_0040fe6d();
  *param_1 = *ppuVar1;
  return param_1;
}



/* VA 0040fe83 */

void __thiscall FUN_0040fe83(void *this,int param_1)

{
  undefined **ppuVar1;
  undefined4 *puVar2;

  if (param_1 == 0) {
    ppuVar1 = FUN_0040fe6d();
    puVar2 = (undefined4 *)*ppuVar1;
  }
  else {
    puVar2 = (undefined4 *)FUN_0040f348(param_1 + 0xd);
    *puVar2 = 1;
    *(undefined1 *)((int)puVar2 + param_1 + 0xc) = 0;
    puVar2[1] = param_1;
    puVar2[2] = param_1;
    puVar2 = puVar2 + 3;
  }
  *(undefined4 **)this = puVar2;
  return;
}



/* VA 0040febd */

void __fastcall FUN_0040febd(int *param_1)

{
  LONG LVar1;
  undefined **ppuVar2;

  if ((LONG *)(*param_1 + -0xc) != (LONG *)PTR_DAT_00423568) {
    LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0xc));
    if (LVar1 < 1) {
      FUN_0040f384((undefined *)(*param_1 + -0xc));
    }
    ppuVar2 = FUN_0040fe6d();
    *param_1 = (int)*ppuVar2;
  }
  return;
}



/* VA 0040feef */

void FUN_0040feef(LONG *param_1)

{
  LONG LVar1;

  if (param_1 != (LONG *)PTR_DAT_00423568) {
    LVar1 = InterlockedDecrement(param_1);
    if (LVar1 < 1) {
      FUN_0040f384((undefined *)param_1);
    }
  }
  return;
}



/* VA 0040ff12 */

void __fastcall FUN_0040ff12(int *param_1)

{
  if (*(int *)(*param_1 + -8) != 0) {
    if (-1 < *(int *)(*param_1 + -0xc)) {
      FUN_0040febd(param_1);
      return;
    }
    FUN_0040ffdd(param_1,&DAT_004287a4);
  }
  return;
}



/* VA 0040ff30 */

void __fastcall FUN_0040ff30(int *param_1)

{
  undefined4 *puVar1;

  puVar1 = (undefined4 *)*param_1;
  if (1 < (int)puVar1[-3]) {
    FUN_0040febd(param_1);
    FUN_0040fe83(param_1,puVar1[-2]);
    FUN_00403510((undefined4 *)*param_1,puVar1,puVar1[-2] + 1);
  }
  return;
}



/* VA 0040ff5e */

void __thiscall FUN_0040ff5e(void *this,int param_1)

{
  if ((1 < *(int *)(*(int *)this + -0xc)) || (*(int *)(*(int *)this + -4) < param_1)) {
    FUN_0040febd(this);
    FUN_0040fe83(this,param_1);
  }
  return;
}



/* VA 0040ff87 */

void __fastcall FUN_0040ff87(int *param_1)

{
  LONG LVar1;

  if ((LONG *)(*param_1 + -0xc) != (LONG *)PTR_DAT_00423568) {
    LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0xc));
    if (LVar1 < 1) {
      FUN_0040f384((undefined *)(*param_1 + -0xc));
    }
  }
  return;
}



/* VA 0040ffb0 */

void __thiscall FUN_0040ffb0(void *this,uint param_1,undefined4 *param_2)

{
  FUN_0040ff5e(this,param_1);
  FUN_00403510(*(undefined4 **)this,param_2,param_1);
  *(uint *)(*(int *)this + -8) = param_1;
  *(undefined1 *)(*(int *)this + param_1) = 0;
  return;
}



/* VA 0040ffdd */

void * __thiscall FUN_0040ffdd(void *this,LPCSTR param_1)

{
  uint uVar1;

  if (param_1 == (LPCSTR)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = lstrlenA(param_1);
  }
  FUN_0040ffb0(this,uVar1,(undefined4 *)param_1);
  return this;
}



/* VA 00410004 */

int __thiscall FUN_00410004(void *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;

  puVar1 = *(undefined4 **)this;
  if ((1 < (int)puVar1[-3]) || ((int)puVar1[-1] < param_1)) {
    iVar2 = puVar1[-2];
    if (param_1 < iVar2) {
      param_1 = iVar2;
    }
    FUN_0040fe83(this,param_1);
    FUN_00403510(*(undefined4 **)this,puVar1,iVar2 + 1);
    *(int *)(*(int *)this + -8) = iVar2;
    FUN_0040feef(puVar1 + -3);
  }
  return *(int *)this;
}



/* VA 00410053 */

void __thiscall FUN_00410053(void *this,int param_1)

{
  FUN_0040ff30(this);
  if (param_1 == -1) {
    param_1 = lstrlenA(*(LPCSTR *)this);
  }
  *(int *)(*(int *)this + -8) = param_1;
  *(undefined1 *)(*(int *)this + param_1) = 0;
  return;
}



/* VA 0041007b */

int __thiscall FUN_0041007b(void *this,int param_1)

{
  FUN_00410004(this,param_1);
  *(int *)(*(int *)this + -8) = param_1;
  *(undefined1 *)(*(int *)this + param_1) = 0;
  return *(int *)this;
}



/* VA 0041009b */

int __cdecl FUN_0041009b(LPWSTR param_1,LPCSTR param_2,int param_3)

{
  int iVar1;

  if ((param_3 == 0) && (param_1 != (LPWSTR)0x0)) {
    return 0;
  }
  iVar1 = MultiByteToWideChar(0,0,param_2,-1,param_1,param_3);
  if (0 < iVar1) {
    param_1[iVar1 + -1] = L'\0';
  }
  return iVar1;
}



/* VA 004100d0 */

void __fastcall FUN_004100d0(int param_1)

{
  DWORD DVar1;
  HBRUSH pHVar2;

  DVar1 = GetSysColor(0xf);
  *(DWORD *)(param_1 + 0x28) = DVar1;
  DVar1 = GetSysColor(0x10);
  *(DWORD *)(param_1 + 0x2c) = DVar1;
  DVar1 = GetSysColor(0x14);
  *(DWORD *)(param_1 + 0x30) = DVar1;
  DVar1 = GetSysColor(0x12);
  *(DWORD *)(param_1 + 0x34) = DVar1;
  DVar1 = GetSysColor(6);
  *(DWORD *)(param_1 + 0x38) = DVar1;
  pHVar2 = GetSysColorBrush(0xf);
  *(HBRUSH *)(param_1 + 0x24) = pHVar2;
  pHVar2 = GetSysColorBrush(6);
  *(HBRUSH *)(param_1 + 0x20) = pHVar2;
  return;
}



/* VA 00410114 */

void __fastcall FUN_00410114(int param_1)

{
  int iVar1;
  HDC hdc;

  iVar1 = GetSystemMetrics(0xb);
  *(int *)(param_1 + 8) = iVar1;
  iVar1 = GetSystemMetrics(0xc);
  *(int *)(param_1 + 0xc) = iVar1;
  if (*(int *)(param_1 + 0x68) == 0) {
    FUN_0041ab69();
  }
  else {
    FUN_0041ab39();
  }
  hdc = GetDC((HWND)0x0);
  iVar1 = GetDeviceCaps(hdc,0x58);
  *(int *)(param_1 + 0x18) = iVar1;
  iVar1 = GetDeviceCaps(hdc,0x5a);
  *(int *)(param_1 + 0x1c) = iVar1;
  ReleaseDC((HWND)0x0,hdc);
  return;
}



/* VA 0041016c */

void __thiscall FUN_0041016c(void *this,undefined4 param_1)

{
  *(undefined ***)this = &PTR_LAB_0041de04;
  *(undefined4 *)((int)this + 4) = param_1;
  return;
}



/* VA 004101b1 */

void __thiscall FUN_004101b1(void *this,undefined4 param_1)

{
  int iVar1;
  undefined1 local_208 [512];
  undefined4 local_8;

  iVar1 = (**(code **)(*(int *)this + 0x14))(local_208,0x200,&local_8);
  if (iVar1 == 0) {
    FUN_00412862();
  }
  else {
    FUN_00412841(local_208,param_1,local_8);
  }
  return;
}



/* VA 00410206 */

void FUN_00410206(void)

{
  AFX_MODULE_THREAD_STATE *pAVar1;

  pAVar1 = AfxGetModuleThreadState();
  *(int *)(pAVar1 + 0x10) = *(int *)(pAVar1 + 0x10) + 1;
  return;
}



/* VA 0041020f */

bool FUN_0041020f(int param_1)

{
  AFX_MODULE_THREAD_STATE *pAVar1;
  int iVar2;
  CWinThread *pCVar3;
  int iVar4;
  SIZE_T SVar5;
  undefined4 uVar6;

  pAVar1 = AfxGetModuleThreadState();
  if ((*(int *)(pAVar1 + 0x10) != 0) &&
     (iVar2 = *(int *)(pAVar1 + 0x10) + -1, *(int *)(pAVar1 + 0x10) = iVar2, iVar2 == 0)) {
    pCVar3 = AfxGetThread();
    iVar2 = FUN_00419dc2();
    iVar2 = *(int *)(iVar2 + 4);
    if (param_1 != 0) {
      if (((param_1 != -1) && (pCVar3 != (CWinThread *)0x0)) &&
         (*(code **)(pCVar3 + 0x54) != (code *)0x0)) {
        (**(code **)(pCVar3 + 0x54))(0,0);
      }
      FUN_00411394();
      FUN_00410a90();
      FUN_0040faf1();
      FUN_0040b659();
      FUN_004020a4();
    }
    iVar4 = FUN_0041a9d0(&DAT_00428660,FUN_00401abc);
    if (((iVar2 != 0) &&
        ((*(undefined **)(iVar4 + 0xc) == (undefined *)0x0 ||
         (SVar5 = FUN_00403bc0(*(undefined **)(iVar4 + 0xc)), SVar5 < *(uint *)(iVar2 + 0xb8))))) &&
       (*(int *)(iVar2 + 0xb8) != 0)) {
      SVar5 = 0;
      if (*(undefined **)(iVar4 + 0xc) != (undefined *)0x0) {
        SVar5 = FUN_00403bc0(*(undefined **)(iVar4 + 0xc));
        FUN_00402c80(*(undefined **)(iVar4 + 0xc));
      }
      iVar2 = FUN_00402cf0(*(uint *)(iVar2 + 0xb8));
      *(int *)(iVar4 + 0xc) = iVar2;
      if ((iVar2 == 0) && (SVar5 != 0)) {
        uVar6 = FUN_00402cf0(SVar5);
        *(undefined4 *)(iVar4 + 0xc) = uVar6;
      }
    }
  }
  return *(int *)(pAVar1 + 0x10) != 0;
}



/* VA 004102fd */

void * FUN_004102fd(void)

{
  undefined4 uVar1;
  void *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(void **)(unaff_EBP + -0x10) = this;
  CMap<>(this,10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  CMap<>((void *)((int)this + 0x1c),4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0040ad88((void *)((int)this + 0x1c),7,0);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *(undefined4 *)((int)this + 0x38) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)((int)this + 0x3c) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)((int)this + 0x40) = *(undefined4 *)(unaff_EBP + 0x10);
  *unaff_FS_OFFSET = uVar1;
  return this;
}



/* VA 00410359 */

int FUN_00410359(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint *puVar6;
  void *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  uVar1 = *(uint *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  *(void **)(unaff_EBP + -0x1c) = this;
  if (uVar1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_0040aec1(this,uVar1);
    if (iVar3 == 0) {
      iVar3 = FUN_0040aec1((void *)((int)this + 0x1c),uVar1);
      if (iVar3 == 0) {
        uVar4 = FUN_0040f334(&LAB_00411749);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
        iVar3 = FUN_0040fc25();
        *(int *)(unaff_EBP + -0x14) = iVar3;
        if (iVar3 == 0) {
          FUN_0040a8cd();
        }
        puVar5 = FUN_0040aef4((void *)((int)this + 0x1c),uVar1);
        *puVar5 = *(undefined4 *)(unaff_EBP + -0x14);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_0040f334(*(undefined4 *)(unaff_EBP + -0x18));
        puVar6 = (uint *)(*(int *)((int)this + 0x3c) + *(int *)(unaff_EBP + -0x14));
        *puVar6 = uVar1;
        if (*(int *)((int)this + 0x40) == 2) {
          puVar6[1] = uVar1;
        }
        iVar3 = *(int *)(unaff_EBP + -0x14);
      }
      else {
        iVar2 = *(int *)((int)this + 0x3c);
        *(uint *)(iVar2 + iVar3) = uVar1;
        if (*(int *)((int)this + 0x40) == 2) {
          *(uint *)(iVar2 + iVar3 + 4) = uVar1;
        }
      }
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar3;
}



/* VA 00410434 */

void __fastcall FUN_00410434(int param_1)

{
  undefined4 *puVar1;
  int local_10;
  int local_c;
  int *local_8;

  local_c = -(uint)(*(int *)(param_1 + 0x28) != 0);
  if (local_c != 0) {
    do {
      FUN_0040af86((void *)(param_1 + 0x1c),&local_c,&local_10,(int *)&local_8);
      puVar1 = (undefined4 *)((int)local_8 + *(int *)(param_1 + 0x3c));
      *puVar1 = 0;
      if (*(int *)(param_1 + 0x40) == 2) {
        puVar1[1] = 0;
      }
      if (local_8 != (int *)0x0) {
        (**(code **)(*local_8 + 4))(1);
      }
    } while (local_c != 0);
  }
  RemoveAll(param_1 + 0x1c);
  return;
}



/* VA 00410495 */

undefined4 * __thiscall FUN_00410495(void *this,uint *param_1)

{
  int iVar1;

  if (param_1 == (uint *)0x0) {
    *(undefined4 *)this = 0;
    *(undefined4 *)((int)this + 4) = 0;
    *(undefined4 *)((int)this + 8) = 0;
  }
  else {
    iVar1 = FUN_0041058e(param_1);
    FUN_004104c4(this,param_1,iVar1);
  }
  return this;
}



/* VA 004104c4 */

undefined4 __thiscall FUN_004104c4(void *this,undefined4 *param_1,int param_2)

{
  HGLOBAL hMem;
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;

  *(int *)((int)this + 4) = param_2;
  hMem = GlobalAlloc(0x40,param_2 + 0x40);
  *(HGLOBAL *)this = hMem;
  uVar3 = 0;
  if (hMem != (HGLOBAL)0x0) {
    puVar1 = GlobalLock(hMem);
    FUN_00403510(puVar1,param_1,*(uint *)((int)this + 4));
    if (*(short *)((int)puVar1 + 2) == -1) {
      uVar2 = puVar1[3];
    }
    else {
      uVar2 = *puVar1;
    }
    *(uint *)((int)this + 8) = ~uVar2 >> 6 & 1;
    GlobalUnlock(*(HGLOBAL *)this);
    uVar3 = 1;
  }
  return uVar3;
}



/* VA 00410524 */

void __fastcall FUN_00410524(undefined4 *param_1)

{
  if ((HGLOBAL)*param_1 != (HGLOBAL)0x0) {
    GlobalFree((HGLOBAL)*param_1);
  }
  return;
}



/* VA 00410532 */

undefined4 __fastcall FUN_00410532(undefined4 *param_1)

{
  undefined4 uVar1;

  uVar1 = *param_1;
  *param_1 = 0;
  return uVar1;
}



/* VA 00410538 */

void __cdecl FUN_00410538(int param_1)

{
  short *psVar1;
  short sVar2;

  if (*(short *)(param_1 + 2) == -1) {
    psVar1 = (short *)(param_1 + 0x1a);
  }
  else {
    psVar1 = (short *)(param_1 + 0x12);
  }
  sVar2 = *psVar1;
  if (sVar2 == -1) {
    psVar1 = psVar1 + 2;
  }
  else {
    while (psVar1 = psVar1 + 1, sVar2 != 0) {
      sVar2 = *psVar1;
    }
  }
  sVar2 = *psVar1;
  if (sVar2 == -1) {
    psVar1 = psVar1 + 2;
  }
  else {
    while (psVar1 = psVar1 + 1, sVar2 != 0) {
      sVar2 = *psVar1;
    }
  }
  do {
    sVar2 = *psVar1;
    psVar1 = psVar1 + 1;
  } while (sVar2 != 0);
  return;
}



/* VA 0041058e */

int __cdecl FUN_0041058e(uint *param_1)

{
  short *psVar1;
  int iVar2;
  ushort *puVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  bool bVar7;

  bVar7 = *(short *)((int)param_1 + 2) == -1;
  psVar1 = (short *)FUN_00410538((int)param_1);
  if (*(short *)((int)param_1 + 2) == -1) {
    uVar6 = param_1[3];
  }
  else {
    uVar6 = *param_1;
  }
  if ((uVar6 & 0x40) != 0) {
    iVar2 = FUN_00403a40(psVar1 + (-(uint)bVar7 & 2) + 1);
    psVar1 = psVar1 + (-(uint)bVar7 & 2) + 1 + iVar2 + 1;
  }
  if (bVar7) {
    bVar4 = (byte)param_1[4];
  }
  else {
    bVar4 = (byte)param_1[2];
  }
  if (bVar4 != 0) {
    uVar6 = (uint)bVar4;
    do {
      puVar3 = (ushort *)(((int)psVar1 + 3U & 0xfffffffc) + (-(uint)bVar7 & 6) + 0x12);
      uVar5 = *puVar3;
      if (uVar5 == 0xffff) {
        puVar3 = puVar3 + 2;
      }
      else {
        while (puVar3 = puVar3 + 1, uVar5 != 0) {
          uVar5 = *puVar3;
        }
      }
      uVar5 = *puVar3;
      if (uVar5 == 0xffff) {
        puVar3 = puVar3 + 2;
      }
      else {
        while (puVar3 = puVar3 + 1, uVar5 != 0) {
          uVar5 = *puVar3;
        }
      }
      uVar6 = uVar6 - 1;
      psVar1 = (short *)((int)puVar3 + *puVar3 + 2);
    } while (uVar6 != 0);
  }
  return (int)psVar1 - (int)param_1;
}



/* VA 00410645 */

undefined4 __cdecl FUN_00410645(uint *param_1,void *param_2,undefined2 *param_3)

{
  short sVar1;
  uint uVar2;
  undefined2 *puVar3;
  LPSTR lpMultiByteStr;
  int cbMultiByte;
  LPCSTR lpDefaultChar;
  LPBOOL lpUsedDefaultChar;

  if (*(short *)((int)param_1 + 2) == -1) {
    uVar2 = param_1[3];
  }
  else {
    uVar2 = *param_1;
  }
  if ((uVar2 & 0x40) == 0) {
    return 0;
  }
  puVar3 = (undefined2 *)FUN_00410538((int)param_1);
  lpUsedDefaultChar = (LPBOOL)0x0;
  *param_3 = *puVar3;
  sVar1 = *(short *)((int)param_1 + 2);
  lpDefaultChar = (LPCSTR)0x0;
  cbMultiByte = 0x20;
  lpMultiByteStr = (LPSTR)FUN_0041007b(param_2,0x20);
  WideCharToMultiByte(0,0,puVar3 + ((sVar1 != -1) - 1 & 2) + 1,-1,lpMultiByteStr,cbMultiByte,
                      lpDefaultChar,lpUsedDefaultChar);
  FUN_00410053(param_2,-1);
  return 1;
}



/* VA 004106b4 */

undefined4 __thiscall FUN_004106b4(void *this,LPCSTR param_1,undefined2 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  char cVar8;
  int iVar9;
  undefined4 *puVar10;
  WCHAR local_54 [32];
  undefined2 *local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  uint local_8;

  if (*(int *)((int)this + 4) == 0) {
    uVar2 = 0;
  }
  else {
    local_c = this;
    puVar3 = GlobalLock(*(HGLOBAL *)this);
    local_8 = (uint)(*(short *)((int)puVar3 + 2) == -1);
    if (*(short *)((int)puVar3 + 2) == -1) {
      uVar4 = puVar3[3];
    }
    else {
      uVar4 = *puVar3;
    }
    local_10 = (undefined4 *)(uVar4 & 0x40);
    iVar9 = (-(uint)(local_8 != 0) & 2) + 1;
    if (local_8 == 0) {
      *puVar3 = *puVar3 | 0x40;
    }
    else {
      puVar3[3] = puVar3[3] | 0x40;
    }
    iVar5 = MultiByteToWideChar(0,0,param_1,-1,local_54,0x20);
    iVar5 = iVar9 * 2 + iVar5 * 2;
    puVar6 = (undefined2 *)FUN_00410538((int)puVar3);
    iVar7 = 0;
    local_14 = puVar6;
    if (local_10 != (undefined4 *)0x0) {
      iVar7 = FUN_00403a40(puVar6 + iVar9);
      iVar7 = iVar9 * 2 + 2 + iVar7 * 2;
    }
    local_10 = (undefined4 *)(iVar7 + 3 + (int)puVar6 & 0xfffffffc);
    puVar10 = (undefined4 *)((int)puVar6 + iVar5 + 3 & 0xfffffffc);
    if (local_8 == 0) {
      cVar8 = (char)puVar3[2];
    }
    else {
      cVar8 = (char)puVar3[4];
    }
    if ((iVar5 != iVar7) && (cVar8 != '\0')) {
      FUN_00403ef0(puVar10,local_10,(int)puVar3 + (local_c[1] - (int)local_10));
    }
    *local_14 = param_2;
    FUN_00403ef0((undefined4 *)(local_14 + iVar9),(undefined4 *)local_54,iVar5 + iVar9 * -2);
    puVar1 = local_c;
    local_c[1] = (int)puVar10 + (local_c[1] - (int)local_10);
    GlobalUnlock((HGLOBAL)*local_c);
    puVar1[2] = 0;
    uVar2 = 1;
  }
  return uVar2;
}



/* VA 004107cb */

void FUN_004107cb(short param_1)

{
  short sVar1;
  HANDLE h;
  int iVar2;
  HDC hdc;
  char *pcVar3;
  int local_44 [7];
  CHAR local_28 [32];
  void *local_8;

  sVar1 = 10;
  pcVar3 = "System";
  h = GetStockObject(0x11);
  if (h == (HGDIOBJ)0x0) {
    h = GetStockObject(0xd);
    if (h == (HGDIOBJ)0x0) goto LAB_0041083f;
  }
  iVar2 = GetObjectA(h,0x3c,local_44);
  if (iVar2 != 0) {
    pcVar3 = local_28;
    hdc = GetDC((HWND)0x0);
    if (local_44[0] < 0) {
      local_44[0] = -local_44[0];
    }
    iVar2 = GetDeviceCaps(hdc,0x5a);
    iVar2 = MulDiv(local_44[0],0x48,iVar2);
    sVar1 = (short)iVar2;
    ReleaseDC((HWND)0x0,hdc);
  }
LAB_0041083f:
  if (param_1 == 0) {
    param_1 = sVar1;
  }
  FUN_004106b4(local_8,pcVar3,param_1);
  return;
}



/* VA 0041085c */

undefined4 FUN_0041085c(void)

{
  LPSTR lpBuffer;
  DWORD DVar1;
  BOOL BVar2;
  undefined4 uVar3;
  HANDLE hFindFile;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  lpBuffer = *(LPSTR *)(unaff_EBP + 8);
  DVar1 = GetFullPathNameA(*(LPCSTR *)(unaff_EBP + 0xc),0x104,lpBuffer,(LPSTR *)(unaff_EBP + -0x14))
  ;
  if (DVar1 == 0) {
    lstrcpynA(lpBuffer,*(LPCSTR *)(unaff_EBP + 0xc),0x104);
  }
  else {
    FUN_0040fe73((undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00410935(lpBuffer,(void *)(unaff_EBP + 8));
    BVar2 = GetVolumeInformationA
                      (*(LPCSTR *)(unaff_EBP + 8),(LPSTR)0x0,0,(LPDWORD)0x0,
                       (LPDWORD)(unaff_EBP + -0x18),(LPDWORD)(unaff_EBP + -0x10),(LPSTR)0x0,0);
    if (BVar2 != 0) {
      if ((*(byte *)(unaff_EBP + -0x10) & 2) == 0) {
        CharUpperA(lpBuffer);
      }
      if ((*(byte *)(unaff_EBP + -0x10) & 4) == 0) {
        hFindFile = FindFirstFileA(*(LPCSTR *)(unaff_EBP + 0xc),
                                   (LPWIN32_FIND_DATAA)(unaff_EBP + -0x158));
        if (hFindFile != (HANDLE)0xffffffff) {
          FindClose(hFindFile);
          lstrcpyA(*(LPSTR *)(unaff_EBP + -0x14),(LPCSTR)(unaff_EBP + -300));
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0040ff87((int *)(unaff_EBP + 8));
      uVar3 = 1;
      goto LAB_00410925;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0040ff87((int *)(unaff_EBP + 8));
  }
  uVar3 = 0;
LAB_00410925:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}



/* VA 00410935 */

void FUN_00410935(LPCSTR param_1,void *param_2)

{
  byte *lpString1;
  byte *pbVar1;
  byte bVar2;

  lpString1 = (byte *)FUN_00410004(param_2,0x104);
  _memset(lpString1,0,0x104);
  lstrcpynA((LPSTR)lpString1,param_1,0x104);
  bVar2 = *lpString1;
  pbVar1 = lpString1;
  while ((bVar2 != 0 &&
         (((bVar2 != 0x5c && (bVar2 != 0x2f)) || ((pbVar1[1] != 0x5c && (pbVar1[1] != 0x2f))))))) {
    pbVar1 = FUN_004045f0(pbVar1);
    bVar2 = *pbVar1;
  }
  if (*pbVar1 == 0) {
    bVar2 = *lpString1;
    while (((bVar2 != 0 && (bVar2 != 0x5c)) && (bVar2 != 0x2f))) {
      lpString1 = FUN_004045f0(lpString1);
      bVar2 = *lpString1;
    }
  }
  else {
    for (lpString1 = pbVar1 + 2;
        ((bVar2 = *lpString1, bVar2 != 0 && (bVar2 != 0x5c)) && (bVar2 != 0x2f));
        lpString1 = FUN_004045f0(lpString1)) {
    }
    if (*lpString1 == 0) goto LAB_004109b6;
    do {
      lpString1 = FUN_004045f0(lpString1);
LAB_004109b6:
      bVar2 = *lpString1;
    } while (((bVar2 != 0) && (bVar2 != 0x5c)) && (bVar2 != 0x2f));
  }
  if (*lpString1 != 0) {
    lpString1[1] = 0;
  }
  FUN_00410053(param_2,-1);
  return;
}



/* VA 004109fb */

undefined4 FUN_004109fb(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;

  uVar4 = 0xffffffff;
  iVar2 = FUN_00419dc2();
  piVar1 = *(int **)(iVar2 + 4);
  iVar2 = FUN_0041b0bd(param_1,param_2,param_3,param_4);
  if (iVar2 != 0) {
    iVar2 = *piVar1;
    iVar3 = (**(code **)(iVar2 + 0x8c))();
    if (iVar3 != 0) {
      iVar3 = (**(code **)(iVar2 + 0x58))();
      if (iVar3 == 0) {
        piVar1 = (int *)piVar1[7];
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0x60))();
        }
        uVar4 = (**(code **)(iVar2 + 0x70))();
      }
      else {
        uVar4 = (**(code **)(iVar2 + 0x5c))();
      }
    }
  }
  FUN_0041b3ce();
  return uVar4;
}



/* VA 00410a60 */

void __fastcall FUN_00410a60(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_0041d7d4;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}



/* VA 00410a74 */

undefined * __thiscall FUN_00410a74(void *this,byte param_1)

{
  FUN_00410b92();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 00410a90 */

void FUN_00410a90(void)

{
  int iVar1;

  iVar1 = FUN_00410aa4();
  if (iVar1 != 0) {
    FUN_00410434(iVar1);
    return;
  }
  return;
}



/* VA 00410aa4 */

undefined4 FUN_00410aa4(void)

{
  AFX_MODULE_THREAD_STATE *pAVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  pAVar1 = AfxGetModuleThreadState();
  if ((*(int *)(pAVar1 + 0x1c) == 0) && (*(int *)(unaff_EBP + 8) != 0)) {
    uVar2 = FUN_0040f334(&LAB_00411749);
    iVar3 = FUN_0040f348(0x44);
    *(int *)(unaff_EBP + 8) = iVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar3 == 0) {
      pvVar4 = (void *)0x0;
    }
    else {
      pvVar4 = FUN_004102fd();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(void **)(pAVar1 + 0x1c) = pvVar4;
    FUN_0040f334(uVar2);
  }
  uVar2 = *(undefined4 *)(pAVar1 + 0x1c);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}



/* VA 00410b14 */

void FUN_00410b14(void)

{
  FUN_00410aa4();
  FUN_00410359();
  return;
}



/* VA 00410b2a */

bool __thiscall FUN_00410b2a(void *this,uint param_1)

{
  void *this_00;
  undefined4 *puVar1;

  if (param_1 != 0) {
    this_00 = (void *)FUN_00410aa4();
    *(uint *)((int)this + 4) = param_1;
    puVar1 = FUN_0040aef4(this_00,param_1);
    *puVar1 = this;
    (**(code **)(*(int *)this + 0x14))(*(undefined4 *)((int)this + 4));
  }
  return param_1 != 0;
}



/* VA 00410b61 */

int __fastcall FUN_00410b61(int *param_1)

{
  int iVar1;
  void *this;

  iVar1 = param_1[1];
  if (iVar1 != 0) {
    this = (void *)FUN_00410aa4();
    if (this != (void *)0x0) {
      FUN_0040af44(this,param_1[1]);
    }
  }
  (**(code **)(*param_1 + 0x1c))();
  param_1[1] = 0;
  return iVar1;
}



/* VA 00410b92 */

void FUN_00410b92(void)

{
  undefined4 uVar1;
  HDC hdc;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = (int)&PTR_LAB_0041d7d4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (extraout_ECX[1] != 0) {
    hdc = (HDC)FUN_00410b61(extraout_ECX);
    DeleteDC(hdc);
  }
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = (int)&PTR_LAB_0041d1bc;
  *unaff_FS_OFFSET = uVar1;
  return;
}



/* VA 00410c27 */

int __thiscall FUN_00410c27(void *this,int param_1)

{
  int iVar1;
  BOOL BVar2;

  iVar1 = 1;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    iVar1 = RestoreDC(*(HDC *)((int)this + 4),param_1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    if ((iVar1 != 0) && (BVar2 = RestoreDC(*(HDC *)((int)this + 8),param_1), BVar2 != 0)) {
      return 1;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* VA 00410c65 */

void FUN_00410c65(HDC param_1,HGDIOBJ param_2)

{
  SelectObject(param_1,param_2);
  FUN_00411418();
  return;
}



/* VA 00410c7c */

void __thiscall FUN_00410c7c(void *this,int param_1)

{
  HGDIOBJ h;

  h = GetStockObject(param_1);
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    SelectObject(*(HDC *)((int)this + 4),h);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    SelectObject(*(HDC *)((int)this + 8),h);
  }
  FUN_00411418();
  return;
}



/* VA 00410cc1 */

void __thiscall FUN_00410cc1(void *this,int param_1)

{
  HGDIOBJ pvVar1;

  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    if (param_1 == 0) {
      pvVar1 = (HGDIOBJ)0x0;
    }
    else {
      pvVar1 = *(HGDIOBJ *)(param_1 + 4);
    }
    SelectObject(*(HDC *)((int)this + 4),pvVar1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    if (param_1 == 0) {
      pvVar1 = (HGDIOBJ)0x0;
    }
    else {
      pvVar1 = *(HGDIOBJ *)(param_1 + 4);
    }
    SelectObject(*(HDC *)((int)this + 8),pvVar1);
  }
  FUN_00411418();
  return;
}



/* VA 00410d14 */

void __thiscall FUN_00410d14(void *this,int param_1)

{
  HGDIOBJ pvVar1;

  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    if (param_1 == 0) {
      pvVar1 = (HGDIOBJ)0x0;
    }
    else {
      pvVar1 = *(HGDIOBJ *)(param_1 + 4);
    }
    SelectObject(*(HDC *)((int)this + 4),pvVar1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    if (param_1 == 0) {
      pvVar1 = (HGDIOBJ)0x0;
    }
    else {
      pvVar1 = *(HGDIOBJ *)(param_1 + 4);
    }
    SelectObject(*(HDC *)((int)this + 8),pvVar1);
  }
  FUN_00411418();
  return;
}



/* VA 00410d67 */

void __thiscall FUN_00410d67(void *this,int param_1,BOOL param_2)

{
  HPALETTE hPal;

  hPal = (HPALETTE)0x0;
  if (param_1 != 0) {
    hPal = *(HPALETTE *)(param_1 + 4);
  }
  SelectPalette(*(HDC *)((int)this + 4),hPal,param_2);
  FUN_00411418();
  return;
}



/* VA 00410d89 */

COLORREF __thiscall FUN_00410d89(void *this,COLORREF param_1)

{
  undefined4 local_8;

  local_8 = this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    local_8 = (void *)SetBkColor(*(HDC *)((int)this + 4),param_1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    local_8 = (void *)SetBkColor(*(HDC *)((int)this + 8),param_1);
  }
  return (COLORREF)local_8;
}



/* VA 00410dc1 */

int __thiscall FUN_00410dc1(void *this,int param_1)

{
  undefined4 local_8;

  local_8 = this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    local_8 = (void *)SetBkMode(*(HDC *)((int)this + 4),param_1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    local_8 = (void *)SetBkMode(*(HDC *)((int)this + 8),param_1);
  }
  return (int)local_8;
}



/* VA 00410df9 */

COLORREF __thiscall FUN_00410df9(void *this,COLORREF param_1)

{
  undefined4 local_8;

  local_8 = this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    local_8 = (void *)SetTextColor(*(HDC *)((int)this + 4),param_1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    local_8 = (void *)SetTextColor(*(HDC *)((int)this + 8),param_1);
  }
  return (COLORREF)local_8;
}



/* VA 00410e31 */

int __thiscall FUN_00410e31(void *this,int param_1)

{
  undefined4 local_8;

  local_8 = this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    local_8 = (void *)SetMapMode(*(HDC *)((int)this + 4),param_1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    local_8 = (void *)SetMapMode(*(HDC *)((int)this + 8),param_1);
  }
  return (int)local_8;
}



/* VA 00410e69 */

void __thiscall FUN_00410e69(void *this,int *param_1,int param_2,int param_3)

{
  tagPOINT local_c;

  local_c.x = (LONG)this;
  local_c.y = (LONG)this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    SetViewportOrgEx(*(HDC *)((int)this + 4),param_2,param_3,&local_c);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    SetViewportOrgEx(*(HDC *)((int)this + 8),param_2,param_3,&local_c);
  }
  *param_1 = local_c.x;
  param_1[1] = local_c.y;
  return;
}



/* VA 00410eb5 */

void __thiscall FUN_00410eb5(void *this,int *param_1,int param_2,int param_3)

{
  tagPOINT local_c;

  local_c.x = (LONG)this;
  local_c.y = (LONG)this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    OffsetViewportOrgEx(*(HDC *)((int)this + 4),param_2,param_3,&local_c);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    OffsetViewportOrgEx(*(HDC *)((int)this + 8),param_2,param_3,&local_c);
  }
  *param_1 = local_c.x;
  param_1[1] = local_c.y;
  return;
}



/* VA 00410f01 */

void __thiscall FUN_00410f01(void *this,int *param_1,int param_2,int param_3)

{
  tagSIZE local_c;

  local_c.cx = (LONG)this;
  local_c.cy = (LONG)this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    SetViewportExtEx(*(HDC *)((int)this + 4),param_2,param_3,&local_c);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    SetViewportExtEx(*(HDC *)((int)this + 8),param_2,param_3,&local_c);
  }
  *param_1 = local_c.cx;
  param_1[1] = local_c.cy;
  return;
}



/* VA 00410f4d */

void __thiscall
FUN_00410f4d(void *this,int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  tagSIZE local_c;

  local_c.cx = (LONG)this;
  local_c.cy = (LONG)this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    ScaleViewportExtEx(*(HDC *)((int)this + 4),param_2,param_3,param_4,param_5,&local_c);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    ScaleViewportExtEx(*(HDC *)((int)this + 8),param_2,param_3,param_4,param_5,&local_c);
  }
  *param_1 = local_c.cx;
  param_1[1] = local_c.cy;
  return;
}



/* VA 00410fa5 */

void __thiscall FUN_00410fa5(void *this,int *param_1,int param_2,int param_3)

{
  tagSIZE local_c;

  local_c.cx = (LONG)this;
  local_c.cy = (LONG)this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    SetWindowExtEx(*(HDC *)((int)this + 4),param_2,param_3,&local_c);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    SetWindowExtEx(*(HDC *)((int)this + 8),param_2,param_3,&local_c);
  }
  *param_1 = local_c.cx;
  param_1[1] = local_c.cy;
  return;
}



/* VA 00410ff1 */

void __thiscall
FUN_00410ff1(void *this,int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  tagSIZE local_c;

  local_c.cx = (LONG)this;
  local_c.cy = (LONG)this;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    ScaleWindowExtEx(*(HDC *)((int)this + 4),param_2,param_3,param_4,param_5,&local_c);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    ScaleWindowExtEx(*(HDC *)((int)this + 8),param_2,param_3,param_4,param_5,&local_c);
  }
  *param_1 = local_c.cx;
  param_1[1] = local_c.cy;
  return;
}



/* VA 00411059 */

int __thiscall FUN_00411059(void *this,int param_1)

{
  int iVar1;
  HRGN pHVar2;

  iVar1 = param_1;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    if (param_1 == 0) {
      pHVar2 = (HRGN)0x0;
    }
    else {
      pHVar2 = *(HRGN *)(param_1 + 4);
    }
    param_1 = SelectClipRgn(*(HDC *)((int)this + 4),pHVar2);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    if (iVar1 == 0) {
      pHVar2 = (HRGN)0x0;
    }
    else {
      pHVar2 = *(HRGN *)(iVar1 + 4);
    }
    param_1 = SelectClipRgn(*(HDC *)((int)this + 8),pHVar2);
  }
  return param_1;
}



/* VA 004110a7 */

int * __thiscall FUN_004110a7(void *this,int *param_1)

{
  int *piVar1;

  piVar1 = param_1;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    param_1 = (int *)ExcludeClipRect(*(HDC *)((int)this + 4),*param_1,param_1[1],param_1[2],
                                     param_1[3]);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    param_1 = (int *)ExcludeClipRect(*(HDC *)((int)this + 8),*piVar1,piVar1[1],piVar1[2],piVar1[3]);
  }
  return param_1;
}



/* VA 004110f3 */

int * __thiscall FUN_004110f3(void *this,int *param_1)

{
  int *piVar1;

  piVar1 = param_1;
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    param_1 = (int *)IntersectClipRect(*(HDC *)((int)this + 4),*param_1,param_1[1],param_1[2],
                                       param_1[3]);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    param_1 = (int *)IntersectClipRect(*(HDC *)((int)this + 8),*piVar1,piVar1[1],piVar1[2],piVar1[3]
                                      );
  }
  return param_1;
}



/* VA 0041113f */

UINT __thiscall FUN_0041113f(void *this,UINT param_1)

{
  if (*(HDC *)((int)this + 4) != *(HDC *)((int)this + 8)) {
    SetTextAlign(*(HDC *)((int)this + 4),param_1);
  }
  if (*(HDC *)((int)this + 8) != (HDC)0x0) {
    param_1 = SetTextAlign(*(HDC *)((int)this + 8),param_1);
  }
  return param_1;
}



/* VA 00411173 */

undefined4 * FUN_00411173(void)

{
  int iVar1;
  bool bVar2;
  HWND hWnd;
  HDC pHVar3;
  undefined3 extraout_var;
  undefined4 *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = this;
  FUN_00410a60(this);
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *this = &PTR_LAB_0041d854;
  hWnd = (HWND)0x0;
  if (iVar1 != 0) {
    hWnd = *(HWND *)(iVar1 + 0x1c);
  }
  this[4] = hWnd;
  pHVar3 = GetDC(hWnd);
  bVar2 = FUN_00410b2a(this,(uint)pHVar3);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    FUN_0041149b();
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return this;
}



/* VA 004111c9 */

undefined * __thiscall FUN_004111c9(void *this,byte param_1)

{
  FUN_004111e5();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 004111e5 */

void FUN_004111e5(void)

{
  HDC hDC;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = (int)&PTR_LAB_0041d854;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  hDC = (HDC)FUN_00410b61(extraout_ECX);
  ReleaseDC((HWND)extraout_ECX[4],hDC);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00410b92();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00411227 */

undefined4 * FUN_00411227(void)

{
  int iVar1;
  bool bVar2;
  HWND hWnd;
  HDC pHVar3;
  undefined3 extraout_var;
  undefined4 *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = this;
  FUN_00410a60(this);
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *this = &PTR_LAB_0041d8d4;
  hWnd = (HWND)0x0;
  if (iVar1 != 0) {
    hWnd = *(HWND *)(iVar1 + 0x1c);
  }
  this[4] = hWnd;
  pHVar3 = GetWindowDC(hWnd);
  bVar2 = FUN_00410b2a(this,(uint)pHVar3);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    FUN_0041149b();
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return this;
}



/* VA 0041127d */

undefined * __thiscall FUN_0041127d(void *this,byte param_1)

{
  FUN_00411299();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 00411299 */

void FUN_00411299(void)

{
  HDC hDC;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = (int)&PTR_LAB_0041d8d4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  hDC = (HDC)FUN_00410b61(extraout_ECX);
  ReleaseDC((HWND)extraout_ECX[4],hDC);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00410b92();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 004112db */

undefined4 * FUN_004112db(void)

{
  int iVar1;
  HWND hWnd;
  bool bVar2;
  HDC pHVar3;
  undefined3 extraout_var;
  undefined4 *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = this;
  FUN_00410a60(this);
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *this = &PTR_LAB_0041d954;
  hWnd = *(HWND *)(iVar1 + 0x1c);
  this[4] = hWnd;
  pHVar3 = BeginPaint(hWnd,(LPPAINTSTRUCT)(this + 5));
  bVar2 = FUN_00410b2a(this,(uint)pHVar3);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    FUN_0041149b();
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return this;
}



/* VA 00411331 */

/* Library Function - Single Match
    public: virtual void * __thiscall CPaintDC::`scalar deleting destructor'(unsigned int)

   Library: Visual Studio 2003 Release */

void * __thiscall CPaintDC::_scalar_deleting_destructor_(CPaintDC *this,uint param_1)

{
  ~CPaintDC(this);
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 0041134d */

/* Library Function - Single Match
    public: virtual __thiscall CPaintDC::~CPaintDC(void)

   Library: Visual Studio 2003 Release */

void __thiscall CPaintDC::~CPaintDC(CPaintDC *this)

{
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = (int)&PTR_LAB_0041d954;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  EndPaint((HWND)extraout_ECX[4],(PAINTSTRUCT *)(extraout_ECX + 5));
  FUN_00410b61(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00410b92();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00411394 */

void FUN_00411394(void)

{
  int iVar1;

  iVar1 = FUN_004113a8();
  if (iVar1 != 0) {
    FUN_00410434(iVar1);
    return;
  }
  return;
}



/* VA 004113a8 */

undefined4 FUN_004113a8(void)

{
  AFX_MODULE_THREAD_STATE *pAVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  pAVar1 = AfxGetModuleThreadState();
  if ((*(int *)(pAVar1 + 0x20) == 0) && (*(int *)(unaff_EBP + 8) != 0)) {
    uVar2 = FUN_0040f334(&LAB_00411749);
    iVar3 = FUN_0040f348(0x44);
    *(int *)(unaff_EBP + 8) = iVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar3 == 0) {
      pvVar4 = (void *)0x0;
    }
    else {
      pvVar4 = FUN_004102fd();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(void **)(pAVar1 + 0x20) = pvVar4;
    FUN_0040f334(uVar2);
  }
  uVar2 = *(undefined4 *)(pAVar1 + 0x20);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}



/* VA 00411418 */

void FUN_00411418(void)

{
  FUN_004113a8();
  FUN_00410359();
  return;
}



/* VA 0041142e */

bool __thiscall FUN_0041142e(void *this,uint param_1)

{
  void *this_00;
  undefined4 *puVar1;

  if (param_1 != 0) {
    this_00 = (void *)FUN_004113a8();
    *(uint *)((int)this + 4) = param_1;
    puVar1 = FUN_0040aef4(this_00,param_1);
    *puVar1 = this;
  }
  return param_1 != 0;
}



/* VA 0041145b */

int __fastcall FUN_0041145b(int param_1)

{
  int iVar1;
  void *this;

  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    this = (void *)FUN_004113a8();
    if (this != (void *)0x0) {
      FUN_0040af44(this,*(uint *)(param_1 + 4));
    }
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return iVar1;
}



/* VA 00411485 */

BOOL __fastcall FUN_00411485(int param_1)

{
  HGDIOBJ ho;
  BOOL BVar1;

  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  ho = (HGDIOBJ)FUN_0041145b(param_1);
  BVar1 = DeleteObject(ho);
  return BVar1;
}



/* VA 0041149b */

void FUN_0041149b(void)

{
  undefined *local_8;

  local_8 = &DAT_00428700;
  FUN_00403310(&local_8,&DAT_004216f8);
  return;
}



/* VA 004114c9 */

undefined4 FUN_004114c9(UINT param_1,int *param_2)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  byte local_104 [256];

  iVar1 = FUN_0040fa52(param_1,(LPSTR)local_104,0x100);
  uVar3 = 0;
  if (iVar1 != 0) {
    pbVar2 = FUN_00403240(local_104,10);
    if (pbVar2 != (byte *)0x0) {
      iVar1 = FUN_00403b00(pbVar2 + 1);
      *param_2 = iVar1;
      iVar1 = MulDiv(iVar1,DAT_00428804,0x48);
      *param_2 = iVar1;
      *pbVar2 = 0;
    }
    lstrcpynA((LPSTR)(param_2 + 7),(LPCSTR)local_104,0x20);
    uVar3 = 1;
  }
  return uVar3;
}



/* VA 00411541 */

bool FUN_00411541(HWND param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  CHAR local_10 [12];

  if ((param_1 != (HWND)0x0) && (uVar1 = GetWindowLongA(param_1,-0x10), (uVar1 & 0xf) == param_2)) {
    GetClassNameA(param_1,local_10,10);
    iVar2 = lstrcmpiA(local_10,"combobox");
    return (bool)('\x01' - (iVar2 != 0));
  }
  return false;
}



/* VA 0041158b */

bool FUN_0041158b(HWND param_1,LPCSTR param_2)

{
  int iVar1;
  CHAR local_24 [32];

  GetClassNameA(param_1,local_24,0x20);
  iVar1 = lstrcmpiA(local_24,param_2);
  return (bool)('\x01' - (iVar1 != 0));
}



/* VA 004115b6 */

HWND FUN_004115b6(HWND param_1,LONG param_2,LONG param_3)

{
  POINT pt;
  int iVar1;
  uint uVar2;
  BOOL BVar3;
  UINT uCmd;
  tagRECT local_14;

  ClientToScreen(param_1,(LPPOINT)&param_2);
  uCmd = 5;
  do {
    param_1 = GetWindow(param_1,uCmd);
    if (param_1 == (HWND)0x0) {
      return (HWND)0x0;
    }
    iVar1 = GetDlgCtrlID(param_1);
    if (((short)iVar1 != -1) && (uVar2 = GetWindowLongA(param_1,-0x10), (uVar2 & 0x10000000) != 0))
    {
      GetWindowRect(param_1,&local_14);
      pt.y = param_3;
      pt.x = param_2;
      BVar3 = PtInRect(&local_14,pt);
      if (BVar3 != 0) {
        return param_1;
      }
    }
    uCmd = 2;
  } while( true );
}



/* VA 0041162b */

void FUN_0041162b(HWND param_1,LPCSTR param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  CHAR local_104 [256];

  uVar1 = lstrlenA(param_2);
  if (((uVar1 < 0x101) && (uVar2 = GetWindowTextA(param_1,local_104,0x100), uVar2 == uVar1)) &&
     (iVar3 = lstrcmpA(local_104,param_2), iVar3 == 0)) {
    return;
  }
  SetWindowTextA(param_1,param_2);
  return;
}



/* VA 00411683 */

void FUN_00411683(undefined4 *param_1)

{
  if ((HGDIOBJ)*param_1 != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)*param_1);
    *param_1 = 0;
  }
  return;
}



/* VA 0041169c */

void FUN_0041169c(HWND param_1)

{
  bool bVar1;
  HWND hWnd;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar2;
  HWND pHVar3;
  HWND pHVar4;

  hWnd = GetFocus();
  if (hWnd == (HWND)0x0) {
    return;
  }
  if (hWnd == param_1) {
    return;
  }
  bVar1 = FUN_00411541(hWnd,3);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    hWnd = GetParent(hWnd);
    if (hWnd == param_1) {
      return;
    }
    bVar1 = FUN_00411541(hWnd,2);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      return;
    }
  }
  if ((param_1 != (HWND)0x0) && (uVar2 = GetWindowLongA(param_1,-0x10), (uVar2 & 0x40000000) != 0))
  {
    pHVar3 = GetParent(param_1);
    pHVar4 = GetDesktopWindow();
    if (pHVar3 == pHVar4) {
      return;
    }
  }
  SendMessageA(hWnd,0x14f,0,0);
  return;
}



/* VA 00411713 */

void FUN_00411713(HGLOBAL param_1)

{
  UINT UVar1;
  uint uVar2;

  if (param_1 != (HGLOBAL)0x0) {
    UVar1 = GlobalFlags(param_1);
    for (uVar2 = UVar1 & 0xff; uVar2 != 0; uVar2 = uVar2 - 1) {
      GlobalUnlock(param_1);
    }
    GlobalFree(param_1);
  }
  return;
}



/* VA 0041179b */

LRESULT __cdecl FUN_0041179b(HKEY param_1)

{
  HWND hWnd;
  BOOL BVar1;
  LSTATUS LVar2;
  byte local_120 [128];
  _OSVERSIONINFOA local_a0;
  DWORD local_c [2];

  if ((param_1 != (HKEY)0x0) || (DAT_00428b94 == 0)) {
    DAT_00428b94 = 1;
    if (DAT_00428ba0 == 0) {
      DAT_00428b9c = RegisterWindowMessageA("MSH_SCROLL_LINES_MSG");
      DAT_00428ba0 = (DAT_00428b9c != 0) + 1;
    }
    if (((DAT_00428ba0 == 2) && (hWnd = FindWindowA("MouseZ","Magellan MSWHEEL"), hWnd != (HWND)0x0)
        ) && (DAT_00428b9c != 0)) {
      DAT_00428b98 = SendMessageA(hWnd,DAT_00428b9c,0,0);
    }
    else {
      _memset(&local_a0,0,0x94);
      local_a0.dwOSVersionInfoSize = 0x94;
      DAT_00428b98 = 3;
      BVar1 = GetVersionExA(&local_a0);
      if ((BVar1 != 0) && ((local_a0.dwPlatformId == 1 || (local_a0.dwPlatformId == 2)))) {
        if (local_a0.dwMajorVersion < 4) {
          LVar2 = RegOpenKeyExA((HKEY)0x80000001,"Control Panel\\Desktop",0,1,&param_1);
          if (LVar2 == 0) {
            local_c[1] = 0x80;
            LVar2 = RegQueryValueExA(param_1,"WheelScrollLines",(LPDWORD)0x0,local_c,local_120,
                                     local_c + 1);
            if (LVar2 == 0) {
              DAT_00428b98 = FUN_00403ec0(local_120,(undefined4 *)0x0,10);
            }
            RegCloseKey(param_1);
          }
        }
        else if ((local_a0.dwPlatformId == 2) && (3 < local_a0.dwMajorVersion)) {
          SystemParametersInfoA(0x68,0,&DAT_00428b98,0);
        }
      }
    }
  }
  return DAT_00428b98;
}



/* VA 00411912 */

void __thiscall FUN_00411912(void *this,undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  tagRECT local_14;

  *(undefined4 *)((int)this + 0x40) = 0xffffffff;
  *(undefined4 *)((int)this + 0x44) = param_1;
  *(undefined4 *)((int)this + 0x48) = param_2;
  if (*(int *)((int)this + 0x1c) != 0) {
    uVar1 = FUN_0040eb4e((int)this);
    if ((uVar1 & 0x300000) != 0) {
      FUN_0040cfff(this,0,0,1);
      FUN_0040cfff(this,1,0,1);
      FUN_0040d08a(this,3,0);
    }
  }
  GetClientRect(*(HWND *)((int)this + 0x1c),&local_14);
  *(LONG *)((int)this + 0x4c) = local_14.right - local_14.left;
  *(LONG *)((int)this + 0x50) = local_14.bottom - local_14.top;
  if (*(int *)((int)this + 0x1c) != 0) {
    FUN_00411c1b(this);
    InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,1);
  }
  return;
}



/* VA 0041199d */

void __thiscall FUN_0041199d(void *this,int *param_1)

{
  int iVar1;
  int iVar2;
  tagRECT local_14;

  iVar1 = FUN_0040d02f(this,1);
  iVar2 = FUN_0040d02f(this,0);
  if (*(int *)((int)this + 100) != 0) {
    GetClientRect(*(HWND *)((int)this + 0x1c),&local_14);
    if (*(int *)((int)this + 0x4c) < local_14.right - local_14.left) {
      iVar2 = ((local_14.right - local_14.left) - *(int *)((int)this + 0x4c)) / -2;
    }
    if (*(int *)((int)this + 0x50) < local_14.bottom - local_14.top) {
      iVar1 = ((local_14.bottom - local_14.top) - *(int *)((int)this + 0x50)) / -2;
    }
  }
  *param_1 = iVar2;
  param_1[1] = iVar1;
  return;
}



/* VA 00411a16 */

void __thiscall FUN_00411a16(void *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;

  iVar1 = FUN_0040d02f(this,0);
  FUN_0040cfff(this,0,param_1,1);
  iVar2 = FUN_0040d02f(this,1);
  FUN_0040cfff(this,1,param_2,1);
  FUN_0040d11a(this,iVar1 - param_1,iVar2 - param_2,(RECT *)0x0,(RECT *)0x0);
  return;
}



/* VA 00411a68 */

void __fastcall FUN_00411a68(int *param_1)

{
  FUN_0040b632(param_1);
  if (param_1[0x10] == -1) {
    FUN_00411912(param_1,param_1[0x11],param_1[0x12]);
  }
  else {
    FUN_00411c1b(param_1);
  }
  return;
}



/* VA 00411a90 */

void __thiscall FUN_00411a90(void *this,int *param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;

  param_1[1] = 0;
  *param_1 = 0;
  uVar2 = FUN_0040eb4e((int)this);
  pcVar1 = *(code **)(*(int *)this + 0x70);
  iVar3 = (*pcVar1)(1);
  if ((iVar3 == 0) && (*param_1 = DAT_004287e8, (uVar2 & 0x800000) != 0)) {
    *param_1 = *param_1 + -1;
  }
  iVar3 = (*pcVar1)(0);
  if ((iVar3 == 0) && (param_1[1] = DAT_004287ec, (uVar2 & 0x800000) != 0)) {
    param_1[1] = param_1[1] + -1;
  }
  return;
}



/* VA 00411aea */

undefined4 __thiscall FUN_00411aea(void *this,int *param_1,int *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  tagRECT local_14;

  GetClientRect(*(HWND *)((int)this + 0x1c),&local_14);
  *param_1 = local_14.right;
  param_1[1] = local_14.bottom;
  uVar1 = FUN_0040eb4e((int)this);
  FUN_00411a90(this,param_2);
  if ((*param_2 != 0) && ((uVar1 & 0x200000) != 0)) {
    *param_1 = *param_1 + *param_2;
  }
  if ((param_2[1] != 0) && ((uVar1 & 0x100000) != 0)) {
    param_1[1] = param_1[1] + param_2[1];
  }
  if ((*param_2 < *param_1) && (param_2[1] < param_1[1])) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* VA 00411b5f */

void __thiscall
FUN_00411b5f(void *this,int param_1,int param_2,uint *param_3,int *param_4,int *param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  void *local_c;
  void *local_8;

  local_c = this;
  local_8 = this;
  FUN_00411a90(this,(int *)&local_c);
  piVar2 = param_4;
  iVar1 = *(int *)((int)this + 0x50);
  *param_4 = *(int *)((int)this + 0x4c) - param_1;
  param_4[1] = iVar1 - param_2;
  piVar3 = (int *)FUN_0041199d(this,&param_1);
  *param_5 = *piVar3;
  param_5[1] = piVar3[1];
  uVar4 = (uint)(0 < *piVar2);
  if (uVar4 == 0) {
    *param_5 = 0;
  }
  else if (param_6 != 0) {
    piVar2[1] = piVar2[1] + (int)local_8;
  }
  uVar5 = (uint)(0 < piVar2[1]);
  if (uVar5 == 0) {
    param_5[1] = 0;
  }
  else if (param_6 != 0) {
    *piVar2 = *piVar2 + (int)local_c;
  }
  if (((uVar5 != 0) && (uVar4 == 0)) && (0 < *piVar2)) {
    piVar2[1] = piVar2[1] + (int)local_8;
    uVar4 = 1;
  }
  iVar1 = *piVar2;
  if ((0 < iVar1) && (iVar1 <= *param_5)) {
    *param_5 = iVar1;
  }
  iVar1 = piVar2[1];
  if ((0 < iVar1) && (iVar1 <= param_5[1])) {
    param_5[1] = iVar1;
  }
  *param_3 = uVar4;
  param_3[1] = uVar5;
  return;
}



/* VA 00411c1b */

void __fastcall FUN_00411c1b(void *param_1)

{
  CWnd *pCVar1;
  LRESULT LVar2;
  int iVar3;
  SCROLLINFO local_6c;
  tagRECT local_50;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  UINT local_10;
  UINT local_c;
  int local_8;

  if (*(int *)((int)param_1 + 0x68) != 0) {
    return;
  }
  *(undefined4 *)((int)param_1 + 0x68) = 1;
  local_8 = 1;
  GetParent(*(HWND *)((int)param_1 + 0x1c));
  pCVar1 = FUN_0040b6dd();
  if ((pCVar1 != (CWnd *)0x0) &&
     (LVar2 = SendMessageA(*(HWND *)(pCVar1 + 0x1c),0x368,0,(LPARAM)&local_40), LVar2 != 0)) {
    local_8 = 0;
  }
  if (local_8 == 0) {
    FUN_00411a90(param_1,&local_20);
    local_10 = local_38 - local_40;
    local_c = local_34 - local_3c;
  }
  else {
    iVar3 = FUN_00411aea(param_1,(int *)&local_10,&local_20);
    if (iVar3 == 0) {
      GetClientRect(*(HWND *)((int)param_1 + 0x1c),&local_50);
      if ((0 < local_50.right) && (0 < local_50.bottom)) {
        FUN_0040d08a(param_1,3,0);
      }
      goto LAB_00411d89;
    }
  }
  FUN_00411b5f(param_1,local_10,local_c,&local_18,&local_30,&local_28,local_8);
  if (local_18 != 0) {
    local_c = local_c - local_1c;
  }
  if (local_14 != 0) {
    local_10 = local_10 - local_20;
  }
  FUN_00411a16(param_1,local_28,local_24);
  local_6c.fMask = 3;
  local_6c.nMin = 0;
  FUN_0040d08a(param_1,0,local_18);
  if (local_18 != 0) {
    local_6c.nPage = local_10;
    local_6c.nMax = *(int *)((int)param_1 + 0x4c) + -1;
    iVar3 = FUN_0040d0cd(param_1,0,&local_6c,1);
    if (iVar3 == 0) {
      FUN_0040d057(param_1,0,0,local_30,1);
    }
  }
  FUN_0040d08a(param_1,1,local_14);
  if (local_14 != 0) {
    local_6c.nPage = local_c;
    local_6c.nMax = *(int *)((int)param_1 + 0x50) + -1;
    iVar3 = FUN_0040d0cd(param_1,1,&local_6c,1);
    if (iVar3 == 0) {
      FUN_0040d057(param_1,1,0,local_2c,1);
    }
  }
LAB_00411d89:
  *(undefined4 *)((int)param_1 + 0x68) = 0;
  return;
}



/* VA 00411d91 */

void __thiscall FUN_00411d91(void *this,undefined1 param_1,undefined4 param_2,void *param_3)

{
  int iVar1;
  void *pvVar2;

  if ((param_3 != (void *)0x0) && (iVar1 = FUN_0040d4d2(param_3,0), iVar1 != 0)) {
    return;
  }
  iVar1 = *(int *)this;
  pvVar2 = (void *)(**(code **)(iVar1 + 0x70))(0);
  if (param_3 == pvVar2) {
    (**(code **)(iVar1 + 0xc4))(CONCAT11(0xff,param_1),param_2,1);
  }
  return;
}



/* VA 00411dd5 */

void __thiscall FUN_00411dd5(void *this,byte param_1,undefined4 param_2,void *param_3)

{
  int iVar1;
  void *pvVar2;

  if ((param_3 != (void *)0x0) && (iVar1 = FUN_0040d4d2(param_3,0), iVar1 != 0)) {
    return;
  }
  iVar1 = *(int *)this;
  pvVar2 = (void *)(**(code **)(iVar1 + 0x70))(1);
  if (param_3 == pvVar2) {
    (**(code **)(iVar1 + 0xc4))(CONCAT31((uint3)param_1,0xff),param_2,1);
  }
  return;
}



/* VA 00411e1c */

/* Library Function - Single Match
    public: int __thiscall CScrollView::OnMouseWheel(unsigned int,short,class CPoint)

   Library: Visual Studio 2003 Release */

int __thiscall CScrollView::OnMouseWheel(CScrollView *this,uint param_1,short param_2)

{
  CWnd *pCVar1;
  int extraout_EAX;

  if (((param_1 & 0xc) == 0) && (pCVar1 = FUN_00412094((CWnd *)this,1), pCVar1 == (CWnd *)0x0)) {
    FUN_00411e50((int *)this,param_1,param_2);
    return extraout_EAX;
  }
  return 0;
}



/* VA 00411e50 */

int __thiscall FUN_00411e50(int *param_1,undefined4 param_2,short param_3)

{
  int iVar1;
  code *pcVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  LRESULT nNumerator;
  int iVar7;
  int unaff_EDI;

  uVar5 = FUN_0040eb4e((int)param_1);
  iVar1 = *param_1;
  pcVar2 = *(code **)(iVar1 + 0x70);
  iVar6 = (*pcVar2)(1);
  if (((iVar6 == 0) || (iVar6 = FUN_0040ecb6(iVar6), iVar6 == 0)) && ((uVar5 & 0x200000) == 0)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  iVar6 = (*pcVar2)(0);
  iVar7 = 0;
  if (((iVar6 != 0) && (iVar6 = FUN_0040ecb6(iVar6), iVar6 != 0)) ||
     (bVar4 = false, (uVar5 & 0x100000) != 0)) {
    bVar4 = true;
  }
  if ((!bVar3) && (!bVar4)) {
    return unaff_EDI;
  }
  nNumerator = FUN_0041179b((HKEY)0x0);
  if (bVar3) {
    iVar7 = MulDiv(-(int)param_3,nNumerator,0x78);
    if ((iVar7 == -1) || (nNumerator == -1)) {
      iVar6 = param_1[0x16];
      if (0 < param_3) {
        iVar6 = -iVar6;
      }
    }
    else {
      iVar6 = param_1[0x18] * iVar7;
      if (param_1[0x16] <= param_1[0x18] * iVar7) {
        iVar6 = param_1[0x16];
      }
    }
    iVar7 = 0;
  }
  else {
    if (!bVar4) goto LAB_00411f5e;
    iVar6 = MulDiv(-(int)param_3,nNumerator,0x78);
    if ((iVar6 == -1) || (nNumerator == -1)) {
      iVar7 = param_1[0x15];
    }
    else {
      iVar7 = param_1[0x17] * iVar6;
      if (param_1[0x15] <= param_1[0x17] * iVar6) {
        iVar7 = param_1[0x15];
      }
    }
    iVar6 = 0;
  }
  iVar7 = (**(code **)(iVar1 + 200))(iVar7,iVar6,1);
LAB_00411f5e:
  if (iVar7 != 0) {
    UpdateWindow((HWND)param_1[7]);
  }
  return unaff_EDI;
}



/* VA 00411f74 */

/* Library Function - Multiple Matches With Same Base Name
    protected: int __thiscall CView::OnCreate(struct tagCREATESTRUCTA *)
    protected: int __thiscall CView::OnCreate(struct tagCREATESTRUCTW *)

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

undefined4 __thiscall OnCreate(void *this,int *param_1)

{
  void *this_00;
  int iVar1;
  undefined4 uVar2;

  iVar1 = FUN_0040b632(this);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    if ((*param_1 != 0) && (this_00 = *(void **)(*param_1 + 4), this_00 != (void *)0x0)) {
      FUN_004121d3(this_00,(int)this);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* VA 00411fa4 */

void __fastcall FUN_00411fa4(int *param_1)

{
  CWnd *this;
  int *piVar1;

  this = FUN_0040ccb3((int)param_1);
  if (this != (CWnd *)0x0) {
    piVar1 = (int *)FUN_00416b58((int)this);
    if (piVar1 == param_1) {
      CFrameWnd::SetActiveView((CFrameWnd *)this,(CView *)0x0,1);
    }
  }
  FUN_0040be3a(param_1);
  return;
}



/* VA 00411fd3 */

void FUN_00411fd3(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  FUN_004112db();
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (**(code **)(iVar1 + 0xe4))(unaff_EBP + -0x60,0);
  (**(code **)(iVar1 + 0xf8))(unaff_EBP + -0x60);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CPaintDC::~CPaintDC((CPaintDC *)(unaff_EBP + -0x60));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00412027 */

int __fastcall FUN_00412027(CView *param_1)

{
  int iVar1;
  CWnd *this;
  CView *pCVar2;
  HWND hWnd;
  BOOL BVar3;

  iVar1 = FUN_0040b632((int *)param_1);
  if (((iVar1 != 3) && (iVar1 != 4)) && (this = FUN_0040ccb3((int)param_1), this != (CWnd *)0x0)) {
    pCVar2 = (CView *)FUN_00416b58((int)this);
    hWnd = GetFocus();
    if (((pCVar2 == param_1) && (*(HWND *)(param_1 + 0x1c) != hWnd)) &&
       (BVar3 = IsChild(*(HWND *)(param_1 + 0x1c),hWnd), BVar3 == 0)) {
      (**(code **)(*(int *)param_1 + 0xec))(1,param_1,param_1);
      return iVar1;
    }
    CFrameWnd::SetActiveView((CFrameWnd *)this,param_1,1);
  }
  return iVar1;
}



/* VA 00412094 */

CWnd * FUN_00412094(CWnd *param_1,int param_2)

{
  CWnd *this;
  int iVar1;
  BOOL BVar2;

  GetParent(*(HWND *)(param_1 + 0x1c));
  this = FUN_0040b6dd();
  iVar1 = FUN_0040fbf3(this,0x41e758);
  if (iVar1 != 0) {
    if (param_2 != 0) {
      return this;
    }
    do {
      GetParent(*(HWND *)(param_1 + 0x1c));
      param_1 = FUN_0040b6dd();
      if (param_1 == (CWnd *)0x0) {
        return this;
      }
      BVar2 = IsIconic(*(HWND *)(param_1 + 0x1c));
    } while (BVar2 == 0);
  }
  return (CWnd *)0x0;
}



/* VA 004121d3 */

void __thiscall FUN_004121d3(void *this,int param_1)

{
  int iVar1;

  AddTail((void *)((int)this + 0x28),param_1);
  iVar1 = *(int *)this;
  *(void **)(param_1 + 0x3c) = this;
  (**(code **)(iVar1 + 0x70))();
  return;
}



/* VA 004121f3 */

int __thiscall FUN_004121f3(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;

  iVar1 = *(int *)((int)this + 0x58);
  if (0 < iVar1) {
    piVar3 = *(int **)((int)this + 0x5c);
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if (*piVar3 == param_1) {
          return iVar2;
        }
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 5;
      } while (iVar2 < iVar1);
    }
  }
  return -1;
}



/* VA 0041221b */

undefined4 __thiscall FUN_0041221b(void *this,int param_1)

{
  return *(undefined4 *)(*(int *)((int)this + 0x5c) + 8 + param_1 * 0x14);
}



/* VA 0041222c */

void __thiscall FUN_0041222c(void *this,int param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;

  uVar3 = *(uint *)(*(int *)((int)this + 0x5c) + 8 + param_1 * 0x14);
  iVar2 = *(int *)((int)this + 0x5c) + param_1 * 0x14;
  if (uVar3 != param_2) {
    *(uint *)(iVar2 + 8) = param_2;
    if (((param_2 ^ uVar3) & 0x8000000) == 0) {
      puVar1 = (uint *)(iVar2 + 0xc);
      *puVar1 = *puVar1 | 1;
      FUN_00412277();
    }
    else {
      FUN_00419883(this,1,0);
    }
  }
  return;
}



/* VA 00412277 */

undefined4 FUN_00412277(void)

{
  int *this;
  int iVar1;
  uint uVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  uVar2 = *(uint *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  iVar3 = *(int *)(extraout_ECX + 0x5c);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  iVar1 = iVar3 + uVar2 * 0x14;
  if ((*(byte *)(iVar3 + 0xc + uVar2 * 0x14) & 1) == 0) {
    if (*(int *)(unaff_EBP + 0xc) == 0) {
      if (*(int *)(*(int *)(iVar1 + 0x10) + -8) == 0) goto LAB_0041232e;
      if (*(int *)(unaff_EBP + 0xc) == 0) goto LAB_004122c9;
    }
    iVar3 = FUN_00403360(*(byte **)(iVar1 + 0x10),*(byte **)(unaff_EBP + 0xc));
    if (iVar3 == 0) goto LAB_0041232e;
  }
LAB_004122c9:
  *(undefined4 *)(unaff_EBP + -4) = 0;
  this = (int *)(iVar1 + 0x10);
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    FUN_0040ff12(this);
  }
  else {
    FUN_0040ffdd(this,*(LPCSTR *)(unaff_EBP + 0xc));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 0x10) == 0) {
    *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 1;
  }
  else {
    *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xfffffffe;
    if ((*(byte *)(iVar1 + 0xb) & 4) == 0) {
      iVar3 = *this;
    }
    else {
      iVar3 = 0;
    }
    (**(code **)(**(int **)(unaff_EBP + -0x14) + 0xa8))(0x401,uVar2 | *(ushort *)(iVar1 + 8),iVar3);
  }
LAB_0041232e:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return 1;
}



/* VA 0041233f */

void FUN_0041233f(void)

{
  int iVar1;
  undefined4 *puVar2;
  HGDIOBJ pvVar3;
  int iVar4;
  int *this;
  int iVar5;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  FUN_00411173();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  pvVar3 = (HGDIOBJ)SendMessageA((HWND)this[7],0x31,0,0);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (pvVar3 != (HGDIOBJ)0x0) {
    pvVar3 = SelectObject(*(HDC *)(unaff_EBP + -0x3c),pvVar3);
    *(HGDIOBJ *)(unaff_EBP + -0x10) = pvVar3;
  }
  GetTextMetricsA(*(HDC *)(unaff_EBP + -0x38),(LPTEXTMETRICA)(unaff_EBP + -0x78));
  if (*(int *)(unaff_EBP + -0x10) != 0) {
    SelectObject(*(HDC *)(unaff_EBP + -0x3c),*(HGDIOBJ *)(unaff_EBP + -0x10));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004111e5();
  SetRectEmpty((LPRECT)(unaff_EBP + -0x2c));
  FUN_00419814(this,(int *)(unaff_EBP + -0x2c),*(int *)(unaff_EBP + 0x10));
  (**(code **)(*this + 0xa8))(0x407,0,unaff_EBP + -0x1c);
  iVar5 = *(int *)(unaff_EBP + -0x20);
  iVar1 = *(int *)(unaff_EBP + -0x28);
  iVar4 = GetSystemMetrics(6);
  iVar5 = (((iVar4 + *(int *)(unaff_EBP + -0x18)) * 2 - (iVar5 - iVar1)) -
          *(int *)(unaff_EBP + -0x6c)) + -1 + *(int *)(unaff_EBP + -0x78);
  if (iVar5 < this[0x1e]) {
    iVar5 = this[0x1e];
  }
  puVar2 = *(undefined4 **)(unaff_EBP + 8);
  *puVar2 = 0x7fff;
  puVar2[1] = iVar5;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00412437 */

void __thiscall FUN_00412437(void *this,undefined4 param_1,int *param_2)

{
  tagRECT local_14;

  SetRectEmpty(&local_14);
  FUN_004137e1(this,&local_14.left,1);
  *param_2 = *param_2 + local_14.left;
  param_2[1] = param_2[1] + local_14.top + -2;
  param_2[2] = param_2[2] + local_14.right;
  param_2[3] = param_2[3] + local_14.bottom;
  return;
}



/* VA 004124a4 */

uint __thiscall FUN_004124a4(void *this,uint param_1,int *param_2,int param_3,int *param_4)

{
  uint uVar1;

  if (param_1 == 0x2b) {
    (**(code **)(*(int *)this + 0xe8))(param_3);
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_0040d5a3(this,param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



/* VA 004124e7 */

void __fastcall FUN_004124e7(int *param_1)

{
  FUN_0040b632(param_1);
  FUN_00419883(param_1,1,0);
  return;
}



/* VA 004124fe */

void __thiscall FUN_004124fe(void *this,int param_1)

{
  uint uVar1;

  uVar1 = *(uint *)((int)this + 100);
  *(uint *)((int)this + 100) = uVar1 & 0xfffff0ff;
  FUN_00412f8c(this,param_1);
  *(uint *)((int)this + 100) = uVar1;
  return;
}



/* VA 0041251e */

int __fastcall FUN_0041251e(void *param_1)

{
  int iVar1;

  iVar1 = FUN_004121f3(param_1,0);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = FUN_00412277();
    iVar1 = (iVar1 != 0) - 1;
  }
  return iVar1;
}



/* VA 0041254a */

int __thiscall FUN_0041254a(void *this,int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;

  uVar3 = 0;
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_004121f3(this,0);
    if (-1 < iVar2) {
      puVar1 = *(undefined4 **)(*(int *)((int)this + 0x5c) + iVar2 * 0x14 + 0x10);
      uVar3 = puVar1[-2];
      if (param_1 < (int)uVar3) {
        uVar3 = param_1 - 1;
      }
      FUN_00403510(param_2,puVar1,uVar3);
    }
    *(undefined1 *)(uVar3 + (int)param_2) = 0;
    iVar2 = uVar3 + 1;
  }
  return iVar2;
}



/* VA 004125c2 */

void __thiscall FUN_004125c2(void *this,int param_1)

{
  int iVar1;

  iVar1 = FUN_0040b632(this);
  if (iVar1 != 0) {
    *(int *)((int)this + 0x78) = param_1;
  }
  return;
}



/* VA 004125d9 */

void __thiscall FUN_004125d9(void *this,int param_1)

{
  void *this_00;
  uint uVar1;

  this_00 = *(void **)((int)this + 0x14);
  *(undefined4 *)((int)this + 0x18) = 1;
  uVar1 = FUN_0041221b(this_00,*(int *)((int)this + 8));
  uVar1 = uVar1 & 0xfbffffff;
  if (param_1 == 0) {
    uVar1 = uVar1 | 0x4000000;
  }
  FUN_0041222c(this_00,*(int *)((int)this + 8),uVar1);
  return;
}



/* VA 00412612 */

void __thiscall FUN_00412612(void *this,int param_1)

{
  void *this_00;
  uint uVar1;

  this_00 = *(void **)((int)this + 0x14);
  uVar1 = FUN_0041221b(this_00,*(int *)((int)this + 8));
  uVar1 = uVar1 & 0xfffffdff;
  if (param_1 != 0) {
    uVar1 = uVar1 | 0x200;
  }
  FUN_0041222c(this_00,*(int *)((int)this + 8),uVar1);
  return;
}



/* VA 00412654 */

void __thiscall FUN_00412654(void *this,int *param_1)

{
  uint uVar1;
  undefined **local_2c;
  undefined4 *local_28;
  uint local_24;
  void *local_18;
  uint local_c;

  CCmdUI::CCmdUI((CCmdUI *)&local_2c);
  local_c = *(uint *)((int)this + 0x58);
  local_2c = &PTR_FUN_0041d5cc;
  local_24 = 0;
  local_18 = this;
  if (local_c != 0) {
    do {
      local_28 = *(undefined4 **)(*(int *)((int)this + 0x5c) + local_24 * 0x14);
      uVar1 = FUN_0040ee06(this,local_28,0xffffffff,&local_2c,(undefined4 *)0x0);
      if (uVar1 == 0) {
        FUN_0040f2c5(&local_2c,param_1,0);
      }
      local_24 = local_24 + 1;
    } while (local_24 < local_c);
  }
  FUN_0040ddf5();
  return;
}



/* VA 004126c8 */

void __fastcall FUN_004126c8(int param_1)

{
  FUN_0040ec8f(*(void **)(param_1 + 0x1c),0);
  ShowOwnedPopups(*(HWND *)(*(int *)(param_1 + 0x1c) + 0x1c),0);
  FUN_0040ec40(*(void **)(param_1 + 0x1c),0x428620,0,0,0,0,0x13);
  return;
}



/* VA 004126fa */

void __thiscall FUN_004126fa(void *this,int param_1)

{
  HCURSOR pHVar1;

  FUN_0041adc3(2);
  *(int *)((int)this + 0xa0) = *(int *)((int)this + 0xa0) + param_1;
  if (*(int *)((int)this + 0xa0) < 1) {
    *(undefined4 *)((int)this + 0xa0) = 0;
    SetCursor(*(HCURSOR *)((int)this + 0xa4));
  }
  else {
    pHVar1 = SetCursor(DAT_00428824);
    if ((0 < param_1) && (*(int *)((int)this + 0xa0) == 1)) {
      *(HCURSOR *)((int)this + 0xa4) = pHVar1;
    }
  }
  FUN_0041ae33(2);
  return;
}



/* VA 00412759 */

void FUN_00412759(undefined4 param_1)

{
  int *piVar1;
  int iVar2;

  piVar1 = (int *)FUN_00401858();
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xb8))();
    if ((iVar2 != 0) && ((int *)piVar1[0x1a] != (int *)0x0)) {
      (**(code **)(*(int *)piVar1[0x1a] + 0x6c))(param_1);
    }
  }
  return;
}



/* VA 00412787 */

int __thiscall FUN_00412787(void *this,LPCSTR param_1,uint param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  HWND hWnd;
  int *piVar5;
  HWND local_8;

  local_8 = this;
  FUN_00412759(0);
  iVar1 = FUN_0040ce64(0,&local_8);
  piVar5 = (int *)((int)this + 0x9c);
  if (iVar1 != 0) {
    piVar2 = (int *)FUN_0040cd3c(iVar1);
    iVar3 = (**(code **)(*piVar2 + 0xb8))();
    if (iVar3 != 0) {
      piVar5 = piVar2 + 0x13;
    }
  }
  iVar3 = *piVar5;
  if (param_3 != 0) {
    *piVar5 = param_3 + 0x30000;
  }
  if (((param_2 & 0xf0) == 0) &&
     ((uVar4 = param_2 & 0xf, uVar4 < 2 || ((2 < uVar4 && (uVar4 < 5)))))) {
    param_2 = param_2 | 0x30;
  }
  FUN_00419a6f();
  hWnd = (HWND)0x0;
  if (iVar1 != 0) {
    hWnd = *(HWND *)(iVar1 + 0x1c);
  }
  iVar1 = MessageBoxA(hWnd,param_1,*(LPCSTR *)((int)this + 0x78),param_2);
  *piVar5 = iVar3;
  if (local_8 != (HWND)0x0) {
    EnableWindow(local_8,1);
  }
  FUN_00412759(1);
  return iVar1;
}



/* VA 00412841 */

void FUN_00412841(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;

  iVar1 = FUN_00419dc2();
  (**(code **)(**(int **)(iVar1 + 4) + 0x94))(param_1,param_2,param_3);
  return;
}



/* VA 00412862 */

undefined4 FUN_00412862(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  FUN_0040fe73((undefined4 *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040f9ce(*(UINT *)(unaff_EBP + 8));
  iVar3 = *(int *)(unaff_EBP + 0x10);
  if (iVar3 == -1) {
    iVar3 = *(int *)(unaff_EBP + 8);
  }
  iVar1 = FUN_00419dc2();
  uVar2 = (**(code **)(**(int **)(iVar1 + 4) + 0x94))
                    (*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + 0xc),iVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0040ff87((int *)(unaff_EBP + -0x10));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}



/* VA 004128db */

void __fastcall FUN_004128db(int param_1)

{
  undefined1 local_108 [260];

  if (*(int *)(param_1 + 0xa8) != 0) {
    FUN_0041085c();
    (**(code **)(**(int **)(param_1 + 0xa8) + 4))(local_108);
  }
  return;
}



/* VA 00412928 */

void __thiscall FUN_00412928(void *this,undefined4 param_1)

{
  if (*(int **)((int)this + 0x80) != (int *)0x0) {
    (**(code **)(**(int **)((int)this + 0x80) + 0x2c))(param_1);
  }
  return;
}



/* VA 004129b9 */

void FUN_004129b9(void)

{
  undefined4 *puVar1;
  int iVar2;
  CWnd *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(CWnd **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_LAB_0041e174;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0041310d((int *)this);
  if (*(void **)(this + 0x6c) != (void *)0x0) {
    FUN_0041661a(*(void **)(this + 0x6c),(int)this);
  }
  puVar1 = *(undefined4 **)(this + 0x74);
  *(undefined4 *)(this + 0x74) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004138cd(puVar1);
    FUN_0040f384((undefined *)puVar1);
  }
  if (*(undefined **)(this + 0x5c) != (undefined *)0x0) {
    FUN_00402c80(*(undefined **)(this + 0x5c));
  }
  iVar2 = FUN_00419a6f();
  if (*(CWnd **)(iVar2 + 0x108) == this) {
    *(undefined4 *)(iVar2 + 0x108) = 0;
    *(undefined4 *)(iVar2 + 0x104) = 0xffffffff;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWnd::~CWnd(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00412a56 */

void FUN_00412a56(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;

  uVar1 = 0x7fff;
  if ((param_2 == 0) || (param_3 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x7fff;
  }
  if ((param_2 == 0) || (param_3 != 0)) {
    uVar1 = 0;
  }
  *param_1 = uVar2;
  param_1[1] = uVar1;
  return;
}



/* VA 00412aae */

/* Library Function - Single Match
    public: void __thiscall CControlBar::ResetTimer(unsigned int,unsigned int)

   Library: Visual Studio 2003 Release */

void __thiscall CControlBar::ResetTimer(CControlBar *this,uint param_1,uint param_2)

{
  KillTimer(*(HWND *)(this + 0x1c),0xe000);
  KillTimer(*(HWND *)(this + 0x1c),0xe001);
  SetTimer(*(HWND *)(this + 0x1c),param_1,param_2,(TIMERPROC)0x0);
  return;
}



/* VA 00412ae4 */

void __thiscall FUN_00412ae4(void *this,int param_1)

{
  POINT Point;
  bool bVar1;
  SHORT SVar2;
  int iVar3;
  undefined3 extraout_var;
  int iVar4;
  CWnd *pCVar5;
  HWND hWnd;
  BOOL BVar6;
  HWND pHVar7;
  int iVar8;
  tagPOINT local_18;
  int local_10;
  int local_c;
  int local_8;

  SVar2 = GetKeyState(1);
  if (SVar2 < 0) {
    return;
  }
  iVar3 = FUN_00419a6f();
  GetCursorPos(&local_18);
  ScreenToClient(*(HWND *)((int)this + 0x1c),&local_18);
  local_10 = *(int *)this;
  iVar8 = 0;
  local_8 = (**(code **)(local_10 + 0x6c))(local_18.x,local_18.y,0);
  if (local_8 < 0) {
    *(undefined4 *)(iVar3 + 0x104) = 0xffffffff;
  }
  else {
    local_c = FUN_0040cd3c((int)this);
    bVar1 = FUN_0040cdaf((int)this);
    if ((CONCAT31(extraout_var,bVar1) == 0) || (iVar4 = FUN_0040ecb6(local_c), iVar4 == 0)) {
      local_8 = -1;
    }
    if (*(int *)(iVar3 + 0xcc) != 0) {
      iVar8 = *(int *)(*(int *)(iVar3 + 0xcc) + 0x1c);
    }
    GetCapture();
    pCVar5 = FUN_0040b6dd();
    if (pCVar5 != this) {
      if (pCVar5 == (CWnd *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(pCVar5 + 0x1c);
      }
      if ((iVar4 != iVar8) && (iVar8 = FUN_0040cd3c((int)pCVar5), iVar8 == local_c)) {
        local_8 = -1;
      }
    }
  }
  bVar1 = true;
  if (local_8 < 0) goto LAB_00412bfa;
  ClientToScreen(*(HWND *)((int)this + 0x1c),&local_18);
  Point.y = local_18.y;
  Point.x = local_18.x;
  hWnd = WindowFromPoint(Point);
  if (hWnd == (HWND)0x0) {
LAB_00412beb:
    local_8 = -1;
    *(undefined4 *)(iVar3 + 0x104) = 0xffffffff;
  }
  else if ((hWnd != *(HWND *)((int)this + 0x1c)) &&
          (BVar6 = IsChild(*(HWND *)((int)this + 0x1c),hWnd), BVar6 == 0)) {
    pHVar7 = (HWND)0x0;
    if (*(int *)(iVar3 + 0xcc) != 0) {
      pHVar7 = *(HWND *)(*(int *)(iVar3 + 0xcc) + 0x1c);
    }
    if (pHVar7 != hWnd) goto LAB_00412beb;
  }
  bVar1 = local_8 < 0;
LAB_00412bfa:
  if (bVar1) {
    if (*(int *)(iVar3 + 0x104) == -1) {
      KillTimer(*(HWND *)((int)this + 0x1c),0xe001);
    }
    (**(code **)(local_10 + 0xe4))(0xffffffff);
  }
  if ((param_1 == 0xe000) && (KillTimer(*(HWND *)((int)this + 0x1c),0xe000), -1 < local_8)) {
    (**(code **)(local_10 + 0xe4))(local_8);
  }
  return;
}



/* VA 00412c4d */

undefined4 __thiscall FUN_00412c4d(void *this,WPARAM param_1)

{
  CWnd *pCVar1;
  int iVar2;

  pCVar1 = CWnd::GetOwner(this);
  iVar2 = FUN_00419a6f();
  if (param_1 == 0xffffffff) {
    *(undefined4 *)(iVar2 + 0x108) = 0;
    if ((*(byte *)((int)this + 0x60) & 8) == 0) {
      KillTimer(*(HWND *)((int)this + 0x1c),0xe000);
      return 0;
    }
    SendMessageA(*(HWND *)(pCVar1 + 0x1c),0x375,0xe001,0);
    *(uint *)((int)this + 0x60) = *(uint *)((int)this + 0x60) & 0xfffffff7;
  }
  else {
    if (((*(byte *)((int)this + 0x60) & 8) != 0) && (*(WPARAM *)(iVar2 + 0x104) == param_1)) {
      return 0;
    }
    *(void **)(iVar2 + 0x108) = this;
    SendMessageA(*(HWND *)(pCVar1 + 0x1c),0x362,param_1,0);
    *(uint *)((int)this + 0x60) = *(uint *)((int)this + 0x60) | 8;
    CControlBar::ResetTimer(this,0xe001,200);
  }
  return 1;
}



/* VA 00412ce4 */

undefined4 __thiscall FUN_00412ce4(void *this,LPMSG param_1)

{
  LPMSG ptVar1;
  SHORT SVar2;
  int iVar3;
  CWnd *pCVar4;
  undefined4 uVar5;
  CWnd *pCVar6;
  uint uVar7;
  uint uVar8;
  undefined4 local_48;
  byte local_41;
  undefined *local_24;
  tagPOINT local_1c;
  CWnd *local_14;
  int local_10;
  int local_c;
  uint local_8;

  ptVar1 = param_1;
  iVar3 = FUN_0040c019(this,param_1);
  if (iVar3 != 0) {
    return 1;
  }
  uVar7 = param_1->message;
  local_8 = uVar7;
  local_14 = CWnd::GetOwner(this);
  if (((((*(byte *)((int)this + 100) & 0x20) == 0) && (uVar7 != 0x201)) && (uVar7 != 0x202)) ||
     (((uVar7 < 0x200 || (0x209 < uVar7)) && ((uVar7 < 0xa0 || (0xa9 < uVar7))))))
  goto LAB_00412e89;
  local_10 = FUN_00419a6f();
  local_1c.x = (param_1->pt).x;
  local_1c.y = (param_1->pt).y;
  ScreenToClient(*(HWND *)((int)this + 0x1c),&local_1c);
  _memset(&local_48,0,0x2c);
  local_48 = 0x2c;
  iVar3 = *(int *)this;
  param_1 = (LPMSG)(**(code **)(iVar3 + 0x6c))(local_1c.x,local_1c.y,&local_48);
  if (local_24 != (undefined *)0xffffffff) {
    FUN_00402c80(local_24);
  }
  if ((local_8 == 0x201) && ((local_41 & 0x80) != 0)) {
    local_c = 1;
  }
  else {
    local_c = 0;
  }
  if ((local_8 != 0x201) && (SVar2 = GetKeyState(1), SVar2 < 0)) {
    param_1 = *(LPMSG *)(local_10 + 0x104);
  }
  if (((int)param_1 < 0) || (local_c != 0)) {
    SVar2 = GetKeyState(1);
    if ((-1 < SVar2) || (local_c != 0)) {
      (**(code **)(iVar3 + 0xe4))(0xffffffff);
      KillTimer(*(HWND *)((int)this + 0x1c),0xe001);
    }
  }
  else if (local_8 == 0x202) {
    (**(code **)(iVar3 + 0xe4))(0xffffffff);
    uVar8 = 200;
    uVar7 = 0xe001;
LAB_00412e3c:
    CControlBar::ResetTimer(this,uVar7,uVar8);
  }
  else if (((*(byte *)((int)this + 0x60) & 8) == 0) && (SVar2 = GetKeyState(1), -1 < SVar2)) {
    if (param_1 != *(LPMSG *)(local_10 + 0x104)) {
      uVar8 = 300;
      uVar7 = 0xe000;
      goto LAB_00412e3c;
    }
  }
  else {
    (**(code **)(iVar3 + 0xe4))(param_1);
  }
  *(LPMSG *)(local_10 + 0x104) = param_1;
LAB_00412e89:
  pCVar4 = FUN_0040ce20(this);
  pCVar6 = local_14;
  if ((pCVar4 == (CWnd *)0x0) || (*(int *)(pCVar4 + 0x50) == 0)) {
    for (; local_14 = pCVar6, pCVar6 != (CWnd *)0x0; pCVar6 = FUN_0040ccb3((int)pCVar6)) {
      iVar3 = (**(code **)(*(int *)pCVar6 + 0x98))(ptVar1);
      if (iVar3 != 0) {
        return 1;
      }
    }
    uVar5 = FUN_0040defa(this,ptVar1);
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}



/* VA 00412ed8 */

uint __thiscall FUN_00412ed8(void *this,uint param_1,WPARAM param_2,LPARAM param_3)

{
  uint Msg;
  int iVar1;
  CWnd *pCVar2;

  Msg = param_1;
  if ((param_1 < 0x2b) ||
     ((((0x2f < param_1 && (param_1 != 0x39)) && (param_1 != 0x4e)) && (param_1 != 0x111)))) {
    param_1 = FUN_0040c5c6(this,param_1,param_2,param_3);
  }
  else {
    iVar1 = (**(code **)(*(int *)this + 0xa4))(param_1,param_2,param_3,&param_1);
    if (iVar1 == 0) {
      pCVar2 = CWnd::GetOwner(this);
      param_1 = SendMessageA(*(HWND *)(pCVar2 + 0x1c),Msg,param_2,param_3);
    }
  }
  return param_1;
}



/* VA 00412f49 */

uint __thiscall FUN_00412f49(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  void *pvStack_14;
  void *pvStack_10;
  undefined4 uStack_c;

  uStack_c = 0;
  iVar1 = *(int *)this;
  pvStack_14 = this;
  pvStack_10 = this;
  FUN_00401e56(&pvStack_14,param_2);
  iVar1 = (**(code **)(iVar1 + 0x6c))();
  if (iVar1 == -1) {
    uVar2 = GetDlgCtrlID(*(HWND *)((int)this + 0x1c));
    uVar2 = -(uint)((uVar2 & 0xffff) != 0) & (uVar2 & 0xffff) + 0x50000;
  }
  else {
    uVar2 = iVar1 + 0x10000;
  }
  return uVar2;
}



/* VA 00412f8c */

void __thiscall FUN_00412f8c(void *this,int param_1)

{
  int yBottom;
  int xRight;
  int yBottom_00;
  tagRECT local_18;
  int local_8;

  FUN_0040b632(this);
  if ((*(byte *)(param_1 + 0x18) & 1) == 0) {
    GetWindowRect(*(HWND *)((int)this + 0x1c),&local_18);
    xRight = local_18.right - local_18.left;
    local_8 = *(int *)(param_1 + 0x10);
    yBottom_00 = local_18.bottom - local_18.top;
    yBottom = *(int *)(param_1 + 0x14);
    if ((local_8 != xRight) && ((*(byte *)((int)this + 0x65) & 4) != 0)) {
      SetRect(&local_18,local_8 - DAT_004287f8,0,local_8,yBottom);
      InvalidateRect(*(HWND *)((int)this + 0x1c),&local_18,1);
      SetRect(&local_18,xRight - DAT_004287f8,0,xRight,yBottom);
      InvalidateRect(*(HWND *)((int)this + 0x1c),&local_18,1);
    }
    if ((yBottom != yBottom_00) && ((*(byte *)((int)this + 0x65) & 8) != 0)) {
      SetRect(&local_18,0,yBottom - DAT_004287fc,local_8,yBottom);
      InvalidateRect(*(HWND *)((int)this + 0x1c),&local_18,1);
      SetRect(&local_18,0,yBottom_00 - DAT_004287fc,local_8,yBottom_00);
      InvalidateRect(*(HWND *)((int)this + 0x1c),&local_18,1);
    }
  }
  return;
}



/* VA 00413084 */

undefined4 __fastcall FUN_00413084(int *param_1)

{
  int iVar1;
  CWnd *pCVar2;
  undefined4 uVar3;

  iVar1 = FUN_0040b632(param_1);
  if (iVar1 == -1) {
    uVar3 = 0xffffffff;
  }
  else {
    if ((*(byte *)(param_1 + 0x19) & 0x10) != 0) {
      FUN_00402330(param_1,1);
    }
    GetParent((HWND)param_1[7]);
    pCVar2 = FUN_0040b6dd();
    iVar1 = (**(code **)(*(int *)pCVar2 + 0xb8))();
    if (iVar1 != 0) {
      param_1[0x1b] = (int)pCVar2;
      AddTail(pCVar2 + 0x6c,param_1);
    }
    uVar3 = 0;
  }
  return uVar3;
}



/* VA 004130d7 */

void __fastcall FUN_004130d7(int *param_1)

{
  int iVar1;

  iVar1 = FUN_00419a6f();
  if (*(int **)(iVar1 + 0x108) == param_1) {
    (**(code **)(*param_1 + 0xe4))(0xffffffff);
  }
  if ((void *)param_1[0x1b] != (void *)0x0) {
    FUN_0041661a((void *)param_1[0x1b],(int)param_1);
    param_1[0x1b] = 0;
  }
  FUN_0040be3a(param_1);
  return;
}



/* VA 0041310d */

void __fastcall FUN_0041310d(int *param_1)

{
  int iVar1;
  CWnd *pCVar2;

  if (param_1[7] != 0) {
    iVar1 = FUN_00417a19(param_1);
    if (iVar1 != 0) {
      pCVar2 = FUN_00417a08((int)param_1);
      (**(code **)(*(int *)pCVar2 + 0x60))();
      return;
    }
  }
  FUN_0040bf81((int)param_1);
  return;
}



/* VA 00413138 */

/* Library Function - Single Match
    public: int __thiscall CControlBar::OnMouseActivate(class CWnd *,unsigned int,unsigned int)

   Library: Visual Studio 2003 Release */

int __thiscall
CControlBar::OnMouseActivate(CControlBar *this,CWnd *param_1,uint param_2,uint param_3)

{
  int iVar1;

  iVar1 = FUN_00417a19((int *)this);
  if (iVar1 == 0) {
    iVar1 = FUN_0040b632((int *)this);
  }
  else {
    CWnd::ActivateTopParent((CWnd *)this);
    iVar1 = 3;
  }
  return iVar1;
}



/* VA 00413159 */

void FUN_00413159(void)

{
  int iVar1;
  int iVar2;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  FUN_004112db();
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = (**(code **)(iVar1 + 0xd0))();
  if (iVar2 != 0) {
    (**(code **)(iVar1 + 0xe0))(unaff_EBP + -0x60);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CPaintDC::~CPaintDC((CPaintDC *)(unaff_EBP + -0x60));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 004131ab */

void FUN_004131ab(void)

{
  void *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  FUN_00411227();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  GetClientRect(*(HWND *)((int)this + 0x1c),(LPRECT)(unaff_EBP + -0x2c));
  GetWindowRect(*(HWND *)((int)this + 0x1c),(LPRECT)(unaff_EBP + -0x1c));
  ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)(unaff_EBP + -0x1c));
  ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)(unaff_EBP + -0x14));
  OffsetRect((LPRECT)(unaff_EBP + -0x2c),-*(int *)(unaff_EBP + -0x1c),-*(int *)(unaff_EBP + -0x18));
  FUN_004110a7((void *)(unaff_EBP + -0x40),(int *)(unaff_EBP + -0x2c));
  OffsetRect((LPRECT)(unaff_EBP + -0x1c),-*(int *)(unaff_EBP + -0x1c),-*(int *)(unaff_EBP + -0x18));
  FUN_00413633(this,(void *)(unaff_EBP + -0x40),(int *)(unaff_EBP + -0x1c));
  FUN_004110f3((void *)(unaff_EBP + -0x40),(int *)(unaff_EBP + -0x1c));
  SendMessageA(*(HWND *)((int)this + 0x1c),0x14,*(WPARAM *)(unaff_EBP + -0x3c),0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00411299();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00413276 */

HANDLE __thiscall FUN_00413276(void *this,int param_1,void *param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  HWND pHVar4;

  pvVar1 = param_2;
  iVar2 = FUN_0040d4d2(param_2,&param_2);
  pvVar3 = param_2;
  if (iVar2 == 0) {
    pHVar4 = (HWND)0x0;
    if (pvVar1 != (void *)0x0) {
      pHVar4 = *(HWND *)((int)pvVar1 + 0x1c);
    }
    iVar2 = FUN_0040da67(*(HDC *)(param_1 + 4),pHVar4,param_3,DAT_0042880c,DAT_0042881c);
    pvVar3 = DAT_0042880c;
    if (iVar2 == 0) {
      pvVar3 = (void *)FUN_0040b632(this);
    }
  }
  return pvVar3;
}



/* VA 004132ce */

void __thiscall FUN_004132ce(void *this,undefined4 param_1,LONG param_2,LONG param_3)

{
  int iVar1;

  if ((*(int *)((int)this + 0x70) != 0) &&
     (iVar1 = (**(code **)(*(int *)this + 0x6c))(param_2,param_3,0), iVar1 == -1)) {
    ClientToScreen(*(HWND *)((int)this + 0x1c),(LPPOINT)&param_2);
    (**(code **)**(undefined4 **)((int)this + 0x74))(param_2,param_3);
    return;
  }
  FUN_0040b632(this);
  return;
}



/* VA 00413314 */

void __thiscall FUN_00413314(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;

  if ((*(int *)((int)this + 0x70) != 0) &&
     (iVar1 = (**(code **)(*(int *)this + 0x6c))(param_2,param_3,0), iVar1 == -1)) {
    (**(code **)(**(int **)((int)this + 0x74) + 8))();
    return;
  }
  FUN_0040b632(this);
  return;
}



/* VA 00413346 */

undefined4 __thiscall FUN_00413346(void *this,undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  CWnd *pCVar3;
  int iVar4;
  uint uVar5;

  uVar1 = FUN_0040eb4e((int)this);
  uVar2 = *(uint *)((int)this + 0x60);
  uVar5 = 0;
  if (((uVar2 & 1) == 0) || ((uVar1 & 0x10000000) == 0)) {
    if (((uVar2 & 2) != 0) && ((uVar1 & 0x10000000) == 0)) {
      uVar5 = 0x40;
    }
  }
  else {
    uVar5 = 0x80;
  }
  *(uint *)((int)this + 0x60) = uVar2 & 0xfffffffc;
  if (uVar5 != 0) {
    FUN_0040ec40(this,0,0,0,0,0,uVar5 | 0x17);
  }
  uVar2 = FUN_0040eb4e((int)this);
  if ((uVar2 & 0x10000000) != 0) {
    if ((*(int *)((int)this + 0x70) != 0) &&
       (uVar2 = FUN_0040eb4e(*(int *)((int)this + 0x70)), (uVar2 & 0x10000000) == 0)) {
      return 0;
    }
    pCVar3 = CWnd::GetOwner(this);
    if ((pCVar3 == (CWnd *)0x0) || (iVar4 = (**(code **)(*(int *)pCVar3 + 0xb8))(), iVar4 == 0)) {
      pCVar3 = FUN_0040ccb3((int)this);
    }
    if (pCVar3 != (CWnd *)0x0) {
      (**(code **)(*(int *)this + 200))(pCVar3,param_1);
    }
    return 0;
  }
  return 0;
}



/* VA 004133f8 */

uint __thiscall FUN_004133f8(void *this,int *param_1)

{
  uint uVar1;
  uint uVar2;
  HDWP pvVar3;
  uint uVar4;
  uint uVar5;

  uVar2 = FUN_0040eb4e((int)this);
  uVar2 = uVar2 & 0x10000000;
  uVar5 = uVar2 | *(uint *)((int)this + 100) & 0xff00;
  uVar1 = *(uint *)((int)this + 0x60);
  if ((uVar1 & 3) != 0) {
    uVar4 = 0;
    if ((uVar1 & 1) == 0) {
      if (uVar2 == 0) {
        uVar4 = 0x40;
      }
    }
    else if (uVar2 != 0) {
      uVar4 = 0x80;
    }
    if (uVar4 == 0) {
      *(uint *)((int)this + 0x60) = uVar1 & 0xfffffffc;
    }
    else {
      uVar5 = uVar5 ^ 0x10000000;
      if (*param_1 != 0) {
        *(uint *)((int)this + 0x60) = uVar1 & 0xfffffffc;
        pvVar3 = DeferWindowPos((HDWP)*param_1,*(HWND *)((int)this + 0x1c),(HWND)0x0,0,0,0,0,
                                uVar4 | 0x17);
        *param_1 = (int)pvVar3;
      }
    }
  }
  return uVar5;
}



/* VA 00413470 */

undefined4 __thiscall FUN_00413470(void *this,undefined4 param_1,int *param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  tagRECT local_24;
  int local_14;
  int local_10;
  int local_c;
  void *local_8;

  local_c = *(int *)this;
  local_8 = this;
  uVar1 = (**(code **)(local_c + 0xd4))(param_2);
  if (((uVar1 & 0x10000000) != 0) && ((uVar1 & 0xf000) != 0)) {
    CopyRect(&local_24,(RECT *)(param_2 + 1));
    iVar4 = local_24.right - local_24.left;
    iVar3 = local_24.bottom - local_24.top;
    bVar5 = param_2[7] != 0;
    if (((*(uint *)((int)local_8 + 100) & 4) == 0) || ((*(uint *)((int)local_8 + 100) & 1) == 0)) {
      if ((uVar1 & 0xa000) == 0) {
        bVar2 = bVar5 | 0x10;
      }
      else {
        bVar2 = bVar5 | 10;
      }
    }
    else {
      bVar2 = bVar5 | 6;
    }
    (**(code **)(local_c + 0xc4))(&local_14,0xffffffff,bVar2);
    if (iVar4 <= local_14) {
      local_14 = iVar4;
    }
    if (iVar3 <= local_10) {
      local_10 = iVar3;
    }
    if ((uVar1 & 0xa000) == 0) {
      if ((uVar1 & 0x5000) != 0) {
        param_2[5] = param_2[5] + local_14;
        iVar3 = param_2[6];
        if (param_2[6] <= local_10) {
          iVar3 = local_10;
        }
        param_2[6] = iVar3;
        if ((uVar1 & 0x1000) == 0) {
          if ((uVar1 & 0x4000) != 0) {
            local_24.left = local_24.right - local_14;
            param_2[3] = param_2[3] - local_14;
          }
        }
        else {
          param_2[1] = param_2[1] + local_14;
        }
      }
    }
    else {
      param_2[6] = param_2[6] + local_10;
      iVar3 = param_2[5];
      if (param_2[5] <= local_14) {
        iVar3 = local_14;
      }
      param_2[5] = iVar3;
      if ((uVar1 & 0x2000) == 0) {
        if ((uVar1 & 0x8000) != 0) {
          local_24.top = local_24.bottom - local_10;
          param_2[4] = param_2[4] - local_10;
        }
      }
      else {
        param_2[2] = param_2[2] + local_10;
      }
    }
    local_24.right = local_14 + local_24.left;
    local_24.bottom = local_10 + local_24.top;
    if (*param_2 != 0) {
      FUN_0040d311(param_2,*(HWND *)((int)local_8 + 0x1c),&local_24);
    }
  }
  return 0;
}



/* VA 004135ae */

void __thiscall FUN_004135ae(void *this,int param_1)

{
  uint uVar1;

  *(uint *)((int)this + 0x60) = *(uint *)((int)this + 0x60) & 0xfffffffc;
  if (param_1 != 0) {
    uVar1 = FUN_0040eb4e((int)this);
    if ((uVar1 & 0x10000000) == 0) {
      *(uint *)((int)this + 0x60) = *(uint *)((int)this + 0x60) | 2;
      return;
    }
    if (param_1 != 0) {
      return;
    }
  }
  uVar1 = FUN_0040eb4e((int)this);
  if ((uVar1 & 0x10000000) != 0) {
    *(uint *)((int)this + 0x60) = *(uint *)((int)this + 0x60) | 1;
  }
  return;
}



/* VA 0041360a */

void __thiscall FUN_0041360a(void *this,void *param_1)

{
  tagRECT local_14;

  GetClientRect(*(HWND *)((int)this + 0x1c),&local_14);
  FUN_00413633(this,param_1,&local_14.left);
  return;
}



/* VA 00413633 */

void __thiscall FUN_00413633(void *this,void *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  COLORREF CVar5;
  uint uVar6;
  int iVar7;
  int local_30;
  int local_2c;
  int local_24;

  uVar4 = *(uint *)((int)this + 100);
  if ((uVar4 & 0xf00) != 0) {
    local_30 = param_2[2];
    local_2c = param_2[3];
    local_24 = param_2[1];
    iVar7 = param_2[3];
    CVar5 = DAT_00428814;
    if (DAT_00428844 == 0) {
      CVar5 = DAT_00428820;
    }
    if ((uVar4 & 0x80) != 0) {
      local_30 = local_30 + -1;
      local_2c = local_2c + -1;
    }
    uVar1 = uVar4 & 0x200;
    if (uVar1 != 0) {
      local_24 = local_24 + DAT_004287fc;
    }
    uVar2 = uVar4 & 0x800;
    if (uVar2 != 0) {
      iVar7 = iVar7 - DAT_004287fc;
    }
    uVar3 = uVar4 & 0x100;
    if (uVar3 != 0) {
      FUN_00417e6e(param_1,0,local_24,1,iVar7 - local_24,CVar5);
    }
    if (uVar1 != 0) {
      FUN_00417e6e(param_1,0,0,param_2[2],1,CVar5);
    }
    uVar6 = uVar4 & 0x400;
    if (uVar6 != 0) {
      FUN_00417e6e(param_1,local_30,local_24,-1,iVar7 - local_24,CVar5);
    }
    if (uVar2 != 0) {
      FUN_00417e6e(param_1,0,local_2c,param_2[2],-1,CVar5);
    }
    CVar5 = DAT_00428818;
    if ((uVar4 & 0x80) != 0) {
      if (uVar3 != 0) {
        FUN_00417e6e(param_1,1,local_24,1,iVar7 - local_24,DAT_00428818);
      }
      if (uVar1 != 0) {
        FUN_00417e6e(param_1,0,1,param_2[2],1,CVar5);
      }
      if (uVar6 != 0) {
        FUN_00417e6e(param_1,param_2[2],local_24,-1,iVar7 - local_24,CVar5);
      }
      if (uVar2 != 0) {
        FUN_00417e6e(param_1,0,param_2[3],param_2[2],-1,CVar5);
      }
    }
    if (uVar3 != 0) {
      *param_2 = *param_2 + DAT_004287f8;
    }
    if (uVar1 != 0) {
      param_2[1] = param_2[1] + DAT_004287fc;
    }
    if (uVar6 != 0) {
      param_2[2] = param_2[2] - DAT_004287f8;
    }
    if (uVar2 != 0) {
      param_2[3] = param_2[3] - DAT_004287fc;
    }
  }
  return;
}



/* VA 004137e1 */

void __thiscall FUN_004137e1(void *this,int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;

  uVar1 = *(uint *)((int)this + 100);
  if ((uVar1 & 0x100) != 0) {
    *param_1 = *param_1 + DAT_004287f8;
  }
  if ((uVar1 & 0x200) != 0) {
    param_1[1] = param_1[1] + DAT_004287fc;
  }
  if ((uVar1 & 0x400) != 0) {
    param_1[2] = param_1[2] - DAT_004287f8;
  }
  if ((uVar1 & 0x800) != 0) {
    param_1[3] = param_1[3] - DAT_004287fc;
  }
  if (param_2 == 0) {
    *param_1 = *param_1 + *(int *)((int)this + 0x48);
    param_1[1] = param_1[1] + *(int *)((int)this + 0x40);
    param_1[2] = param_1[2] - *(int *)((int)this + 0x4c);
    iVar2 = *(int *)((int)this + 0x44);
  }
  else {
    *param_1 = *param_1 + *(int *)((int)this + 0x40);
    param_1[1] = param_1[1] + *(int *)((int)this + 0x48);
    param_1[2] = param_1[2] - *(int *)((int)this + 0x44);
    iVar2 = *(int *)((int)this + 0x4c);
  }
  param_1[3] = param_1[3] - iVar2;
  return;
}



/* VA 00413858 */

uint __thiscall FUN_00413858(void *this,LPCSTR param_1,LPCSTR param_2,undefined4 param_3)

{
  HKEY hKey;
  LSTATUS LVar1;
  uint uVar2;
  CHAR local_14 [16];

  if (*(int *)((int)this + 0x7c) == 0) {
    wsprintfA(local_14,"%d",param_3);
    uVar2 = WritePrivateProfileStringA(param_1,param_2,local_14,*(LPCSTR *)((int)this + 0x90));
  }
  else {
    hKey = GetSectionKey(this,param_1);
    uVar2 = 0;
    if (hKey != (HKEY)0x0) {
      LVar1 = RegSetValueExA(hKey,param_2,0,4,(BYTE *)&param_3,4);
      RegCloseKey(hKey);
      uVar2 = (uint)(LVar1 == 0);
    }
  }
  return uVar2;
}



/* VA 004138cd */

void __fastcall FUN_004138cd(undefined4 *param_1)

{
  void *this;

  *param_1 = &PTR_FUN_0041e914;
  this = *(void **)(param_1[0x1a] + 0x70);
  if (this != (void *)0x0) {
    FUN_00414cbe(this,param_1[0x1a],-1,0);
  }
  return;
}



/* VA 004138e8 */

void __thiscall FUN_004138e8(void *this,int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  tagRECT local_5c;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  tagRECT local_3c;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;

  *(undefined4 *)((int)this + 0x88) = 1;
  FUN_0041417e((int)this);
  iVar1 = *(int *)((int)this + 0x68);
  if ((*(uint *)(iVar1 + 100) & 4) == 0) {
    if ((*(uint *)(iVar1 + 100) & 2) == 0) {
      GetWindowRect(*(HWND *)(iVar1 + 0x1c),&local_3c);
      uVar2 = *(uint *)((int)this + 0x78) & 0xa000;
      *(int *)((int)this + 4) = param_1;
      *(int *)((int)this + 8) = param_2;
      (**(code **)(**(int **)((int)this + 0x68) + 0xc4))
                (&local_c,0xffffffff,(-(uVar2 != 0) & 6U) + 10);
      if (uVar2 == 0) {
        local_4c = local_3c.left;
        *(LONG *)((int)this + 0x38) = local_3c.left;
        *(LONG *)((int)this + 0x3c) = local_3c.top;
        local_48 = param_2 - (local_3c.right - local_3c.left) / 2;
        *(LONG *)((int)this + 0x40) = local_3c.right;
        *(LONG *)((int)this + 0x44) = local_3c.bottom;
        piVar3 = (int *)((int)this + 0x28);
      }
      else {
        local_48 = local_3c.top;
        *(LONG *)((int)this + 0x28) = local_3c.left;
        *(LONG *)((int)this + 0x2c) = local_3c.top;
        local_4c = param_1 - (local_3c.bottom - local_3c.top) / 2;
        *(LONG *)((int)this + 0x30) = local_3c.right;
        *(LONG *)((int)this + 0x34) = local_3c.bottom;
        piVar3 = (int *)((int)this + 0x38);
      }
      local_40 = local_8 + local_48;
      local_44 = local_4c + local_c;
      *piVar3 = local_4c;
      piVar3[1] = local_48;
      piVar3[2] = local_44;
      piVar3[3] = local_40;
      *(undefined4 *)((int)this + 0x48) = *(undefined4 *)((int)this + 0x28);
      *(undefined4 *)((int)this + 0x4c) = *(undefined4 *)((int)this + 0x2c);
      *(undefined4 *)((int)this + 0x50) = *(undefined4 *)((int)this + 0x30);
      *(undefined4 *)((int)this + 0x54) = *(undefined4 *)((int)this + 0x34);
      *(undefined4 *)((int)this + 0x58) = *(undefined4 *)((int)this + 0x38);
      *(undefined4 *)((int)this + 0x5c) = *(undefined4 *)((int)this + 0x3c);
      *(undefined4 *)((int)this + 0x60) = *(undefined4 *)((int)this + 0x40);
      *(undefined4 *)((int)this + 100) = *(undefined4 *)((int)this + 0x44);
    }
    else {
      GetWindowRect(*(HWND *)(iVar1 + 0x1c),&local_5c);
      *(int *)((int)this + 4) = param_1;
      *(int *)((int)this + 8) = param_2;
      (**(code **)(**(int **)((int)this + 0x68) + 0xc4))(&local_3c.right,0xffffffff,10);
      (**(code **)(**(int **)((int)this + 0x68) + 0xc4))(&local_2c,0xffffffff,0x10);
      *(LONG *)((int)this + 0x28) = local_5c.left;
      *(LONG *)((int)this + 0x2c) = local_5c.top;
      *(LONG *)((int)this + 0x30) = local_3c.right + local_5c.left;
      *(LONG *)((int)this + 0x34) = local_3c.bottom + local_5c.top;
      *(LONG *)((int)this + 0x48) = local_5c.left;
      *(LONG *)((int)this + 0x4c) = local_5c.top;
      *(LONG *)((int)this + 0x50) = local_3c.right + local_5c.left;
      *(LONG *)((int)this + 0x54) = local_3c.bottom + local_5c.top;
      local_24 = local_5c.left;
      local_1c = local_2c + local_5c.left;
      local_18 = local_28 + local_5c.top;
      local_20 = local_5c.top;
      *(LONG *)((int)this + 0x38) = local_5c.left;
      *(LONG *)((int)this + 0x3c) = local_5c.top;
      *(int *)((int)this + 0x40) = local_1c;
      *(int *)((int)this + 0x44) = local_18;
      *(LONG *)((int)this + 0x58) = local_5c.left;
      *(LONG *)((int)this + 0x5c) = local_5c.top;
      *(int *)((int)this + 0x60) = local_1c;
      *(int *)((int)this + 100) = local_18;
    }
  }
  else {
    GetWindowRect(*(HWND *)(iVar1 + 0x1c),&local_5c);
    *(int *)((int)this + 4) = param_1;
    *(int *)((int)this + 8) = param_2;
    (**(code **)(**(int **)((int)this + 0x68) + 0xc4))(&local_1c,0,10);
    (**(code **)(**(int **)((int)this + 0x68) + 0xc4))(&local_2c,0,0x10);
    (**(code **)(**(int **)((int)this + 0x68) + 0xc4))(&local_3c.right,0,6);
    *(LONG *)((int)this + 0x28) = local_5c.left;
    *(LONG *)((int)this + 0x2c) = local_5c.top;
    *(int *)((int)this + 0x30) = local_1c + local_5c.left;
    local_c = local_2c + local_5c.left;
    *(int *)((int)this + 0x34) = local_18 + local_5c.top;
    local_14 = local_5c.left;
    local_10 = local_5c.top;
    *(LONG *)((int)this + 0x38) = local_5c.left;
    *(LONG *)((int)this + 0x3c) = local_5c.top;
    *(int *)((int)this + 0x40) = local_c;
    *(int *)((int)this + 0x44) = local_28 + local_5c.top;
    local_44 = local_3c.right + local_5c.left;
    local_40 = local_3c.bottom + local_5c.top;
    *(LONG *)((int)this + 0x48) = local_5c.left;
    *(LONG *)((int)this + 0x4c) = local_5c.top;
    *(int *)((int)this + 0x50) = local_44;
    *(int *)((int)this + 0x54) = local_40;
    local_4c = local_5c.left;
    local_48 = local_5c.top;
    *(LONG *)((int)this + 0x58) = local_5c.left;
    *(LONG *)((int)this + 0x5c) = local_5c.top;
    *(int *)((int)this + 0x60) = local_44;
    *(int *)((int)this + 100) = local_40;
    local_8 = local_40;
  }
  FUN_00418f04((LPRECT)((int)this + 0x48),0xc40000);
  FUN_00418f04((LPRECT)((int)this + 0x58),0xc40000);
  InflateRect((LPRECT)((int)this + 0x48),-DAT_004287f8,-DAT_004287fc);
  InflateRect((LPRECT)((int)this + 0x58),-DAT_004287f8,-DAT_004287fc);
  FUN_00413c22((LPRECT)((int)this + 0x28),param_1,param_2);
  FUN_00413c22((LPRECT)((int)this + 0x38),param_1,param_2);
  FUN_00413c22((LPRECT)((int)this + 0x48),param_1,param_2);
  FUN_00413c22((LPRECT)((int)this + 0x58),param_1,param_2);
  uVar2 = FUN_004143f0((int)this);
  *(uint *)((int)this + 0x74) = uVar2;
  FUN_00413c61(this,param_1,param_2);
  FUN_00414550(this);
  return;
}



/* VA 00413c22 */

void __cdecl FUN_00413c22(LPRECT param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;

  iVar1 = param_1->left;
  if ((param_2 < iVar1) || (iVar1 = param_1->right, iVar1 < param_2)) {
    iVar1 = param_2 - iVar1;
  }
  else {
    iVar1 = 0;
  }
  iVar2 = param_1->top;
  if ((param_3 < iVar2) || (iVar2 = param_1->bottom, iVar2 < param_3)) {
    iVar2 = param_3 - iVar2;
  }
  else {
    iVar2 = 0;
  }
  OffsetRect(param_1,iVar1,iVar2);
  return;
}



/* VA 00413c61 */

void __thiscall FUN_00413c61(void *this,int param_1,int param_2)

{
  int dy;
  uint uVar1;
  int dx;

  dx = param_1 - *(int *)((int)this + 4);
  dy = param_2 - *(int *)((int)this + 8);
  OffsetRect((LPRECT)((int)this + 0x28),dx,dy);
  OffsetRect((LPRECT)((int)this + 0x48),dx,dy);
  OffsetRect((LPRECT)((int)this + 0x38),dx,dy);
  OffsetRect((LPRECT)((int)this + 0x58),dx,dy);
  *(int *)((int)this + 4) = param_1;
  *(int *)((int)this + 8) = param_2;
  if (*(int *)((int)this + 0x80) == 0) {
    uVar1 = FUN_004143f0((int)this);
  }
  else {
    uVar1 = 0;
  }
  *(uint *)((int)this + 0x74) = uVar1;
  FUN_00414288(this,0);
  return;
}



/* VA 00413cdd */

void __thiscall FUN_00413cdd(void *this,int param_1,int param_2)

{
  if (param_1 == 0x11) {
    FUN_0041439e(this,(int *)((int)this + 0x80),param_2);
  }
  if (param_1 == 0x10) {
    FUN_0041439e(this,(int *)((int)this + 0x7c),param_2);
  }
  return;
}



/* VA 00413d11 */

void __fastcall FUN_00413d11(void *param_1)

{
  void *pvVar1;
  uint uVar2;
  LONG *pLVar3;
  int iVar4;
  int iVar5;
  RECT local_18;
  void *local_8;

  FUN_0041423f(param_1);
  if (*(uint *)((int)param_1 + 0x74) == 0) {
    uVar2 = *(uint *)((int)param_1 + 0x78);
    if ((((uVar2 & 4) == 0) && (((uVar2 & 0xa000) == 0 || (*(int *)((int)param_1 + 0x7c) != 0)))) &&
       (((uVar2 & 0x5000) == 0 || (*(int *)((int)param_1 + 0x7c) == 0)))) {
      *(undefined4 *)((int)param_1 + 0xa8) = *(undefined4 *)((int)param_1 + 0x58);
      iVar5 = *(int *)((int)param_1 + 0x5c);
      uVar2 = (uint)CONCAT11(0x10,(byte)*(undefined4 *)((int)param_1 + 0x70) & 0x40);
      iVar4 = *(int *)((int)param_1 + 0x58);
      *(uint *)((int)param_1 + 0xa4) = uVar2;
      *(int *)((int)param_1 + 0xac) = iVar5;
    }
    else {
      *(undefined4 *)((int)param_1 + 0xa8) = *(undefined4 *)((int)param_1 + 0x48);
      iVar5 = *(int *)((int)param_1 + 0x4c);
      uVar2 = (uint)CONCAT11(0x20,(byte)*(undefined4 *)((int)param_1 + 0x70) & 0x40);
      iVar4 = *(int *)((int)param_1 + 0x48);
      *(uint *)((int)param_1 + 0xa4) = uVar2;
      *(int *)((int)param_1 + 0xac) = iVar5;
    }
    FUN_0041923b(*(void **)((int)param_1 + 0x6c),*(void **)((int)param_1 + 0x68),iVar4,iVar5,uVar2);
  }
  else {
    local_8 = (void *)FUN_00414508(param_1,*(uint *)((int)param_1 + 0x74));
    pLVar3 = (LONG *)((int)param_1 + 0x38);
    if ((*(byte *)((int)param_1 + 0x75) & 0x50) == 0) {
      pLVar3 = (LONG *)((int)param_1 + 0x28);
    }
    local_18.left = *pLVar3;
    local_18.top = pLVar3[1];
    local_18.right = pLVar3[2];
    local_18.bottom = pLVar3[3];
    uVar2 = GetDlgCtrlID(*(HWND *)((int)local_8 + 0x1c));
    pvVar1 = local_8;
    uVar2 = uVar2 & 0xffff;
    if ((0xe81a < uVar2) && (uVar2 < 0xe81f)) {
      *(uint *)((int)param_1 + 0x90) = uVar2;
      ((LPPOINT)((int)param_1 + 0x94))->x = local_18.left;
      *(LONG *)((int)param_1 + 0x98) = local_18.top;
      *(LONG *)((int)param_1 + 0x9c) = local_18.right;
      *(LONG *)((int)param_1 + 0xa0) = local_18.bottom;
      ScreenToClient(*(HWND *)((int)local_8 + 0x1c),(LPPOINT)((int)param_1 + 0x94));
      ScreenToClient(*(HWND *)((int)pvVar1 + 0x1c),(LPPOINT)((int)param_1 + 0x9c));
    }
    FUN_00419157(*(void **)((int)param_1 + 0x6c),*(void **)((int)param_1 + 0x68),pvVar1,&local_18);
    (**(code **)(**(int **)((int)param_1 + 0x6c) + 0xd0))(1);
  }
  return;
}



/* VA 00413e35 */

void __thiscall FUN_00413e35(void *this,undefined4 param_1,int param_2,int param_3)

{
  tagRECT local_2c;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;

  *(undefined4 *)((int)this + 0x88) = 0;
  FUN_0041417e((int)this);
  GetWindowRect(*(HWND *)(*(int *)((int)this + 0x68) + 0x1c),&local_2c);
  *(int *)((int)this + 4) = param_2;
  *(int *)((int)this + 8) = param_3;
  *(undefined4 *)((int)this + 0x8c) = param_1;
  (**(code **)(**(int **)((int)this + 0x68) + 0xc4))(&local_c,0,6);
  local_10 = local_8 + local_2c.top;
  local_14 = local_c + local_2c.left;
  *(LONG *)((int)this + 0x28) = local_2c.left;
  *(LONG *)((int)this + 0x2c) = local_2c.top;
  *(int *)((int)this + 0x30) = local_14;
  *(int *)((int)this + 0x34) = local_10;
  *(LONG *)((int)this + 0x38) = local_2c.left;
  *(LONG *)((int)this + 0x3c) = local_2c.top;
  *(int *)((int)this + 0x40) = local_14;
  *(int *)((int)this + 0x44) = local_10;
  local_1c = local_2c.left;
  local_18 = local_2c.top;
  ((LPRECT)((int)this + 0x48))->left = local_2c.left;
  *(LONG *)((int)this + 0x4c) = local_2c.top;
  *(int *)((int)this + 0x50) = local_14;
  *(int *)((int)this + 0x54) = local_10;
  FUN_00418f04((LPRECT)((int)this + 0x48),0xc40000);
  InflateRect((LPRECT)((int)this + 0x48),-DAT_004287f8,-DAT_004287fc);
  local_1c = 0;
  local_18 = 0;
  local_14 = (*(int *)((int)this + 0x50) - ((LPRECT)((int)this + 0x48))->left) -
             (*(int *)((int)this + 0x40) - *(int *)((int)this + 0x38));
  local_10 = (*(int *)((int)this + 0x54) - *(int *)((int)this + 0x4c)) -
             (*(int *)((int)this + 0x44) - *(int *)((int)this + 0x3c));
  *(undefined4 *)((int)this + 0x74) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(int *)((int)this + 0x60) = local_14;
  *(int *)((int)this + 100) = local_10;
  FUN_00413f59(this,param_2,param_3);
  FUN_00414550(this);
  return;
}



/* VA 00413f59 */

void __thiscall FUN_00413f59(void *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  void *local_c;
  void *local_8;

  iVar1 = param_1 - *(int *)((int)this + 4);
  iVar3 = param_2 - *(int *)((int)this + 8);
  iVar2 = *(int *)((int)this + 0x8c);
  uVar4 = 2;
  if (iVar2 == 10) {
    *(int *)((int)this + 0x28) = *(int *)((int)this + 0x28) + iVar1;
  }
  else {
    if (iVar2 != 0xb) {
      uVar4 = 0x22;
      if (iVar2 == 0xc) {
        *(int *)((int)this + 0x2c) = *(int *)((int)this + 0x2c) + iVar3;
      }
      else {
        *(int *)((int)this + 0x34) = *(int *)((int)this + 0x34) + iVar3;
      }
      iVar2 = *(int *)((int)this + 0x34) - *(int *)((int)this + 0x2c);
      goto LAB_00413fb3;
    }
    *(int *)((int)this + 0x30) = *(int *)((int)this + 0x30) + iVar1;
  }
  iVar2 = *(int *)((int)this + 0x30) - *(int *)((int)this + 0x28);
LAB_00413fb3:
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  local_c = this;
  local_8 = this;
  (**(code **)(**(int **)((int)this + 0x68) + 0xc4))(&local_c,iVar2,uVar4);
  if ((*(int *)((int)this + 0x8c) == 10) || (*(int *)((int)this + 0x8c) == 0xc)) {
    *(int *)((int)this + 0x38) = *(int *)((int)this + 0x40) - (int)local_c;
    *(int *)((int)this + 0x3c) = *(int *)((int)this + 0x44) - (int)local_8;
    *(int *)((int)this + 0x48) =
         ((*(int *)((int)this + 0x50) - *(int *)((int)this + 0x60)) + *(int *)((int)this + 0x58)) -
         (int)local_c;
    *(int *)((int)this + 0x4c) =
         ((*(int *)((int)this + 0x5c) - *(int *)((int)this + 100)) + *(int *)((int)this + 0x54)) -
         (int)local_8;
  }
  else {
    *(int *)((int)this + 0x40) = *(int *)((int)this + 0x38) + (int)local_c;
    *(int *)((int)this + 0x44) = *(int *)((int)this + 0x3c) + (int)local_8;
    *(int *)((int)this + 0x50) =
         ((*(int *)((int)this + 0x60) + *(int *)((int)this + 0x48)) - *(int *)((int)this + 0x58)) +
         (int)local_c;
    *(int *)((int)this + 0x54) =
         (*(int *)((int)this + 100) - *(int *)((int)this + 0x5c)) + *(int *)((int)this + 0x4c) +
         (int)local_8;
  }
  *(int *)((int)this + 4) = param_1;
  *(int *)((int)this + 8) = param_2;
  FUN_00414288(this,0);
  return;
}



/* VA 00414055 */

void __fastcall FUN_00414055(void *param_1)

{
  void *local_8;
  void *pvStack_4;

  local_8 = param_1;
  pvStack_4 = param_1;
  FUN_0041423f(param_1);
  (**(code **)(**(int **)((int)param_1 + 0x68) + 0xc4))
            (&local_8,*(int *)((int)param_1 + 0x40) - *(int *)((int)param_1 + 0x38),0x42);
  FUN_0041923b(*(void **)((int)param_1 + 0x6c),*(void **)((int)param_1 + 0x68),
               *(int *)((int)param_1 + 0x48),*(int *)((int)param_1 + 0x4c),
               (uint)((ushort)*(undefined4 *)((int)param_1 + 0x70) & 0x40 | 0x2004));
  return;
}



/* VA 00414098 */

void __fastcall FUN_00414098(int param_1)

{
  int iVar1;
  CWnd *pCVar2;
  void *pvVar3;
  undefined1 local_14 [12];
  LONG local_8;

  iVar1 = FUN_00417a19(*(int **)(param_1 + 0x68));
  if (iVar1 == 0) {
    local_14._8_4_ = *(int *)(param_1 + 0xa8);
    local_8 = *(int *)(param_1 + 0xac);
    if (((int)local_14._8_4_ < 0) || (local_8 < 0)) {
      local_14._8_4_ = *(int *)(param_1 + 0x94);
      local_8 = *(int *)(param_1 + 0x98);
      GetParent(*(HWND *)(*(int *)(param_1 + 0x68) + 0x1c));
      pCVar2 = FUN_0040b6dd();
      ClientToScreen(*(HWND *)(pCVar2 + 0x1c),(LPPOINT)(local_14 + 8));
    }
    FUN_0041923b(*(void **)(param_1 + 0x6c),*(void **)(param_1 + 0x68),local_14._8_4_,local_8,
                 *(uint *)(param_1 + 0xa4));
  }
  else if ((*(byte *)(*(int *)(param_1 + 0x68) + 0x69) & 0xf0) != 0) {
    local_14._0_4_ = *(LONG *)(param_1 + 0x94);
    local_14._4_4_ = *(LONG *)(param_1 + 0x98);
    local_14._8_4_ = *(LONG *)(param_1 + 0x9c);
    local_8 = *(LONG *)(param_1 + 0xa0);
    pvVar3 = (void *)0x0;
    if (*(uint *)(param_1 + 0x90) != 0) {
      pvVar3 = (void *)FUN_00417150(*(void **)(param_1 + 0x6c),*(uint *)(param_1 + 0x90));
      ClientToScreen(*(HWND *)((int)pvVar3 + 0x1c),(LPPOINT)local_14);
      ClientToScreen(*(HWND *)((int)pvVar3 + 0x1c),(LPPOINT)(local_14 + 8));
    }
    FUN_004191ac(*(void **)(param_1 + 0x6c),*(void **)(param_1 + 0x68),pvVar3,(RECT *)local_14);
    (**(code **)(**(int **)(param_1 + 0x6c) + 0xd0))(1);
  }
  return;
}



/* VA 0041417e */

void __fastcall FUN_0041417e(int param_1)

{
  BOOL BVar1;
  CWnd *pCVar2;
  undefined4 uVar3;
  DWORD flags;
  tagMSG local_1c;

  while( true ) {
    BVar1 = PeekMessageA(&local_1c,(HWND)0x0,0xf,0xf,0);
    if (BVar1 == 0) {
      *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(*(int *)(param_1 + 0x68) + 0x68);
      *(uint *)(param_1 + 0x78) = *(uint *)(*(int *)(param_1 + 0x68) + 100) & 0xf000;
      SetRectEmpty((LPRECT)(param_1 + 0xc));
      *(undefined4 *)(param_1 + 0x20) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 0x24) = 0;
      *(undefined4 *)(param_1 + 0x7c) = 0;
      *(undefined4 *)(param_1 + 0x80) = 0;
      GetDesktopWindow();
      pCVar2 = FUN_0040b6dd();
      BVar1 = LockWindowUpdate(*(HWND *)(pCVar2 + 0x1c));
      if (BVar1 == 0) {
        flags = 3;
      }
      else {
        flags = 0x403;
      }
      GetDCEx(*(HWND *)(pCVar2 + 0x1c),(HRGN)0x0,flags);
      uVar3 = FUN_00410b14();
      *(undefined4 *)(param_1 + 0x84) = uVar3;
      return;
    }
    BVar1 = GetMessageA(&local_1c,(HWND)0x0,0xf,0xf);
    if (BVar1 == 0) break;
    DispatchMessageA(&local_1c);
  }
  return;
}



/* VA 0041423f */

void __fastcall FUN_0041423f(void *param_1)

{
  CWnd *pCVar1;

  FUN_00414288(param_1,1);
  ReleaseCapture();
  GetDesktopWindow();
  pCVar1 = FUN_0040b6dd();
  LockWindowUpdate((HWND)0x0);
  if (*(int *)((int)param_1 + 0x84) != 0) {
    ReleaseDC(*(HWND *)(pCVar1 + 0x1c),*(HDC *)(*(int *)((int)param_1 + 0x84) + 4));
    *(undefined4 *)((int)param_1 + 0x84) = 0;
  }
  return;
}



/* VA 00414288 */

void __thiscall FUN_00414288(void *this,int param_1)

{
  int iVar1;
  LONG *pLVar2;
  tagRECT local_28;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;

  local_18 = 1;
  local_14 = 1;
  GetStockObject(0);
  iVar1 = FUN_00411418();
  local_10 = iVar1;
  local_8 = FUN_00417ae6();
  local_c = iVar1;
  if ((*(uint *)((int)this + 0x74) & 0xa000) == 0) {
    if ((*(uint *)((int)this + 0x74) & 0x5000) == 0) {
      local_18 = GetSystemMetrics(0x20);
      local_18 = local_18 + -1;
      local_14 = GetSystemMetrics(0x21);
      local_14 = local_14 + -1;
      if ((((*(uint *)((int)this + 0x78) & 0xa000) == 0) || (*(int *)((int)this + 0x7c) != 0)) &&
         (((*(uint *)((int)this + 0x78) & 0x5000) == 0 || (*(int *)((int)this + 0x7c) == 0)))) {
        pLVar2 = (LONG *)((int)this + 0x58);
      }
      else {
        pLVar2 = (LONG *)((int)this + 0x48);
      }
      local_28.left = *pLVar2;
      local_28.top = pLVar2[1];
      local_28.right = pLVar2[2];
      local_28.bottom = pLVar2[3];
      local_c = local_8;
      goto LAB_0041431f;
    }
    pLVar2 = (LONG *)((int)this + 0x38);
  }
  else {
    pLVar2 = (LONG *)((int)this + 0x28);
  }
  local_28.left = *pLVar2;
  local_28.top = pLVar2[1];
  local_28.right = pLVar2[2];
  local_28.bottom = pLVar2[3];
LAB_0041431f:
  if (param_1 != 0) {
    local_14 = 0;
    local_18 = 0;
  }
  if ((DAT_00428844 != 0) && ((*(byte *)((int)this + 0x75) & 0xf0) != 0)) {
    InflateRect(&local_28,-1,-1);
  }
  FUN_00417b59();
  *(LONG *)((int)this + 0xc) = local_28.left;
  *(int *)((int)this + 0x1c) = local_18;
  *(LONG *)((int)this + 0x10) = local_28.top;
  *(LONG *)((int)this + 0x14) = local_28.right;
  *(int *)((int)this + 0x20) = local_14;
  *(LONG *)((int)this + 0x18) = local_28.bottom;
  *(uint *)((int)this + 0x24) = (uint)(local_c == local_8);
  return;
}



/* VA 0041439e */

void __thiscall FUN_0041439e(void *this,int *param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;

  if (*param_1 != param_2) {
    *param_1 = param_2;
    if ((((*(uint *)((int)this + 0x70) & 0xa000) == 0) ||
        ((*(uint *)((int)this + 0x70) & 0x5000) == 0)) || (*(int *)((int)this + 0x7c) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    *(undefined4 *)((int)this + 0x7c) = uVar1;
    if (*(int *)((int)this + 0x80) == 0) {
      uVar2 = FUN_004143f0((int)this);
    }
    else {
      uVar2 = 0;
    }
    *(uint *)((int)this + 0x74) = uVar2;
    FUN_00414288(this,0);
  }
  return;
}



/* VA 004143f0 */

uint __fastcall FUN_004143f0(int param_1)

{
  uint uVar1;
  uint uVar2;

  uVar1 = 0;
  uVar2 = *(uint *)(param_1 + 0x78) & 0xa000;
  if (*(int *)(param_1 + 0x7c) != 0) {
    uVar2 = (uint)(uVar2 == 0);
  }
  if (((uVar2 != 0) && ((*(uint *)(param_1 + 0x70) & 0xa000) != 0)) ||
     ((*(uint *)(param_1 + 0x70) & 0x5000) != 0)) {
    uVar1 = FUN_00419338(*(void **)(param_1 + 0x6c));
  }
  if ((*(int *)(param_1 + 0x7c) == 0) && (uVar1 == 0)) {
    if ((*(uint *)(param_1 + 0x70) & 0xa000) != 0) {
      uVar2 = FUN_00419338(*(void **)(param_1 + 0x6c));
      uVar1 = FUN_00419338(*(void **)(param_1 + 0x6c));
      uVar1 = ~-(uint)(uVar1 != uVar2) & uVar1;
    }
    if ((uVar1 == 0) && ((*(uint *)(param_1 + 0x70) & 0x5000) != 0)) {
      uVar2 = FUN_00419338(*(void **)(param_1 + 0x6c));
      uVar1 = FUN_00419338(*(void **)(param_1 + 0x6c));
      uVar1 = ~-(uint)(uVar1 != uVar2) & uVar1;
    }
  }
  return uVar1;
}



/* VA 00414508 */

uint __thiscall FUN_00414508(void *this,uint param_1)

{
  if (((param_1 & 0xa000) == 0) && ((param_1 & 0x5000) == 0)) {
    param_1 = 0;
  }
  else {
    FUN_00419338(*(void **)((int)this + 0x6c));
  }
  return param_1;
}



/* VA 00414550 */

undefined4 __fastcall FUN_00414550(void *param_1)

{
  HWND pHVar1;
  CWnd *pCVar2;
  BOOL BVar3;
  tagMSG local_20;

  pHVar1 = GetCapture();
  if (pHVar1 == (HWND)0x0) {
    SetCapture(*(HWND *)(*(int *)((int)param_1 + 0x68) + 0x1c));
    FUN_0040b6dd();
    GetCapture();
    pCVar2 = FUN_0040b6dd();
    if (pCVar2 == *(CWnd **)((int)param_1 + 0x68)) {
      do {
        BVar3 = GetMessageA(&local_20,(HWND)0x0,0,0);
        if (BVar3 == 0) {
          AfxPostQuitMessage(local_20.wParam);
          break;
        }
        if (local_20.message == 0x100) {
          if (*(int *)((int)param_1 + 0x88) != 0) {
            FUN_00413cdd(param_1,local_20.wParam,1);
          }
          if (local_20.wParam == 0x1b) break;
        }
        else if (local_20.message == 0x101) {
          if (*(int *)((int)param_1 + 0x88) != 0) {
            FUN_00413cdd(param_1,local_20.wParam,0);
          }
        }
        else if (local_20.message == 0x200) {
          if (*(int *)((int)param_1 + 0x88) == 0) {
            FUN_00413f59(param_1,local_20.pt.x,local_20.pt.y);
          }
          else {
            FUN_00413c61(param_1,local_20.pt.x,local_20.pt.y);
          }
        }
        else {
          if (local_20.message == 0x202) {
            if (*(int *)((int)param_1 + 0x88) == 0) {
              FUN_00414055(param_1);
            }
            else {
              FUN_00413d11(param_1);
            }
            return 1;
          }
          if (local_20.message == 0x204) break;
          DispatchMessageA(&local_20);
        }
        GetCapture();
        pCVar2 = FUN_0040b6dd();
      } while (pCVar2 == *(CWnd **)((int)param_1 + 0x68));
    }
    FUN_0041423f(param_1);
  }
  return 0;
}



/* VA 00414671 */

undefined4 * FUN_00414671(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0041ae54(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040aac5(extraout_ECX + 0x1f);
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *extraout_ECX = &PTR_LAB_0041ebb4;
  extraout_ECX[0x1e] = uVar1;
  extraout_ECX[0xf] = 1;
  iVar2 = extraout_ECX[0x21];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0040ac52(extraout_ECX + 0x1f,iVar2,0);
  extraout_ECX[0x24] = 0;
  SetRectEmpty((LPRECT)(extraout_ECX + 0x25));
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0x12] = 0;
  extraout_ECX[0x13] = 0;
  extraout_ECX[0x11] = 0;
  extraout_ECX[0x10] = 0;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}



/* VA 004146ec */

undefined * __thiscall FUN_004146ec(void *this,byte param_1)

{
  FUN_00414708();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 00414708 */

void FUN_00414708(void)

{
  uint uVar1;
  undefined4 *this;
  int unaff_EBP;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = this;
  *this = &PTR_LAB_0041ebb4;
  iVar2 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (0 < (int)this[0x21]) {
    do {
      uVar1 = FUN_00415419(this,iVar2);
      if ((uVar1 != 0) && (*(undefined4 **)(uVar1 + 0x70) == this)) {
        *(undefined4 *)(uVar1 + 0x70) = 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)this[0x21]);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0040aaf8();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004129b9();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00414774 */

bool __thiscall FUN_00414774(void *this,int param_1,uint param_2,HMENU param_3)

{
  int iVar1;
  bool bVar2;
  tagRECT local_14;

  *(uint *)((int)this + 100) = param_2;
  iVar1 = FUN_00419dc2();
  if ((*(byte *)(iVar1 + 0x18) & 2) == 0) {
    iVar1 = FUN_0040e0b4(2);
  }
  else {
    iVar1 = 1;
  }
  bVar2 = false;
  if (iVar1 != 0) {
    SetRectEmpty(&local_14);
    iVar1 = FUN_0040bd72(this,"AfxControlBar42s",(LPCSTR)0x0,param_2,&local_14.left,param_1,param_3,
                         (LPVOID)0x0);
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}



/* VA 004147d4 */

int __fastcall FUN_004147d4(void *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;

  iVar2 = 0;
  iVar3 = 0;
  if (0 < *(int *)((int)param_1 + 0x84)) {
    do {
      uVar1 = FUN_00415419(param_1,iVar3);
      if (uVar1 != 0) {
        iVar2 = iVar2 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)((int)param_1 + 0x84));
  }
  return iVar2;
}



/* VA 00414801 */

int __fastcall FUN_00414801(void *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;

  iVar4 = 0;
  iVar3 = 0;
  if (0 < *(int *)((int)param_1 + 0x84)) {
    do {
      piVar1 = (int *)FUN_00415419(param_1,iVar4);
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 0xd0))();
        if (iVar2 != 0) {
          iVar3 = iVar3 + 1;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)((int)param_1 + 0x84));
  }
  return iVar3;
}



/* VA 0041483c */

void __thiscall FUN_0041483c(void *this,void *param_1,RECT *param_2)

{
  undefined4 uVar1;
  void *this_00;
  BOOL BVar2;
  uint uVar3;
  CWnd *pCVar4;
  HWND hWndNewParent;
  int iVar5;
  int iVar6;
  CHAR local_130 [260];
  tagRECT local_2c;
  int local_1c;
  int local_18;
  undefined1 local_14 [12];
  int local_8;

  GetWindowRect(*(HWND *)((int)param_1 + 0x1c),&local_2c);
  if (*(void **)((int)param_1 + 0x70) == this) {
    if (param_2 == (RECT *)0x0) {
      return;
    }
    BVar2 = EqualRect(&local_2c,param_2);
    if (BVar2 != 0) {
      return;
    }
  }
  if ((*(int *)((int)this + 0x78) != 0) && ((*(byte *)((int)param_1 + 0x68) & 0x40) != 0)) {
    *(uint *)((int)this + 100) = *(uint *)((int)this + 100) | 0x40;
  }
  *(uint *)((int)this + 100) = *(uint *)((int)this + 100) & 0xfffffff9;
  uVar3 = *(uint *)((int)this + 100);
  *(uint *)((int)this + 100) = *(uint *)((int)param_1 + 100) & 6 | uVar3;
  if ((uVar3 & 0x40) == 0) {
    FUN_0040ec11(param_1,local_130,0x104);
    FUN_0041162b(*(HWND *)((int)this + 0x1c),local_130);
  }
  uVar1 = *(undefined4 *)((int)param_1 + 100);
  uVar3 = CONCAT22((short)((uint)uVar1 >> 0x10),
                   CONCAT11(((byte)((uint)*(undefined4 *)((int)param_1 + 100) >> 8) ^
                            (byte)((uint)*(undefined4 *)((int)this + 100) >> 8)) & 0xf0 ^
                            (byte)((uint)uVar1 >> 8),(char)uVar1));
  if (*(int *)((int)this + 0x78) == 0) {
    uVar3 = uVar3 & 0xfffffffe | 0xf00;
  }
  else {
    uVar3 = uVar3 | 0xf01;
  }
  FUN_0041af3b(param_1,uVar3);
  local_1c = 0;
  if ((*(void **)((int)param_1 + 0x70) != this) &&
     (BVar2 = IsWindowVisible(*(HWND *)((int)param_1 + 0x1c)), BVar2 != 0)) {
    FUN_0040ec40(param_1,0,0,0,0,0,0x97);
    local_1c = 1;
  }
  local_18 = -1;
  if (param_2 == (RECT *)0x0) {
    FUN_0040ac52((void *)((int)this + 0x7c),*(int *)((int)this + 0x84),param_1);
    FUN_0040ac52((void *)((int)this + 0x7c),*(int *)((int)this + 0x84),0);
    FUN_0040ec40(param_1,0,-DAT_004287f8,-DAT_004287fc,0,0,0x115);
  }
  else {
    CopyRect((LPRECT)local_14,param_2);
    ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)local_14);
    ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)(local_14 + 8));
    local_18 = FUN_00415435(this,param_1,local_14._0_4_,local_14._4_4_,local_14._8_4_,local_8,
                            (int)(local_14._8_4_ - local_14._0_4_) / 2 + local_14._0_4_,
                            (local_8 - local_14._4_4_) / 2 + local_14._4_4_);
    FUN_0040ec40(param_1,0,local_14._0_4_,local_14._4_4_,local_14._8_4_ - local_14._0_4_,
                 local_8 - local_14._4_4_,0x114);
  }
  GetParent(*(HWND *)((int)param_1 + 0x1c));
  pCVar4 = FUN_0040b6dd();
  if (pCVar4 != this) {
    if (this == (void *)0x0) {
      hWndNewParent = (HWND)0x0;
    }
    else {
      hWndNewParent = *(HWND *)((int)this + 0x1c);
    }
    SetParent(*(HWND *)((int)param_1 + 0x1c),hWndNewParent);
    FUN_0040b6dd();
  }
  this_00 = *(void **)((int)param_1 + 0x70);
  if (this_00 == this) {
    iVar6 = 0;
    iVar5 = local_18;
  }
  else {
    if (this_00 == (void *)0x0) goto LAB_00414a44;
    if ((*(int *)((int)this + 0x78) == 0) || (*(int *)((int)this_00 + 0x78) != 0)) {
      iVar6 = 0;
    }
    else {
      iVar6 = 1;
    }
    iVar5 = -1;
  }
  FUN_00414cbe(this_00,(int)param_1,iVar5,iVar6);
LAB_00414a44:
  *(void **)((int)param_1 + 0x70) = this;
  if (local_1c != 0) {
    FUN_0040ec40(param_1,0,0,0,0,0,0x57);
  }
  FUN_00414c67(this,(int)param_1);
  pCVar4 = FUN_00417a08((int)this);
  *(uint *)(pCVar4 + 0xb8) = *(uint *)(pCVar4 + 0xb8) | 0xc;
  return;
}



/* VA 00414a77 */

void __thiscall FUN_00414a77(void *this,void *param_1,RECT *param_2)

{
  undefined4 uVar1;
  BOOL BVar2;
  uint uVar3;
  CWnd *pCVar4;
  HWND hWndNewParent;
  int iVar5;
  UINT UVar6;
  CHAR local_128 [260];
  tagRECT local_24;
  undefined1 local_14 [12];
  int local_8;

  GetWindowRect(*(HWND *)((int)param_1 + 0x1c),&local_24);
  if (*(void **)((int)param_1 + 0x70) == this) {
    if (param_2 == (RECT *)0x0) {
      return;
    }
    BVar2 = EqualRect(&local_24,param_2);
    if (BVar2 != 0) {
      return;
    }
  }
  if ((*(int *)((int)this + 0x78) != 0) && ((*(byte *)((int)param_1 + 0x68) & 0x40) != 0)) {
    *(uint *)((int)this + 100) = *(uint *)((int)this + 100) | 0x40;
  }
  *(uint *)((int)this + 100) = *(uint *)((int)this + 100) & 0xfffffff9;
  uVar3 = *(uint *)((int)this + 100);
  *(uint *)((int)this + 100) = *(uint *)((int)param_1 + 100) & 6 | uVar3;
  if ((uVar3 & 0x40) == 0) {
    FUN_0040ec11(param_1,local_128,0x104);
    FUN_0041162b(*(HWND *)((int)this + 0x1c),local_128);
  }
  uVar1 = *(undefined4 *)((int)param_1 + 100);
  uVar3 = CONCAT22((short)((uint)uVar1 >> 0x10),
                   CONCAT11(((byte)((uint)*(undefined4 *)((int)param_1 + 100) >> 8) ^
                            (byte)((uint)*(undefined4 *)((int)this + 100) >> 8)) & 0xf0 ^
                            (byte)((uint)uVar1 >> 8),(char)uVar1));
  if (*(int *)((int)this + 0x78) == 0) {
    uVar3 = uVar3 & 0xfffffffe | 0xf00;
  }
  else {
    uVar3 = uVar3 | 0xf01;
  }
  FUN_0041af3b(param_1,uVar3);
  iVar5 = -1;
  uVar3 = GetDlgCtrlID(*(HWND *)((int)param_1 + 0x1c));
  iVar5 = FUN_004153aa(this,uVar3 & 0xffff,iVar5);
  if (0 < iVar5) {
    *(void **)(*(int *)((int)this + 0x80) + iVar5 * 4) = param_1;
  }
  if (param_2 == (RECT *)0x0) {
    if (iVar5 < 1) {
      FUN_0040ac52((void *)((int)this + 0x7c),*(int *)((int)this + 0x84),param_1);
      FUN_0040ac52((void *)((int)this + 0x7c),*(int *)((int)this + 0x84),0);
    }
    UVar6 = 0x115;
    local_8 = 0;
    local_14._4_4_ = -DAT_004287fc;
    iVar5 = 0;
    local_14._0_4_ = -DAT_004287f8;
  }
  else {
    CopyRect((LPRECT)local_14,param_2);
    ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)local_14);
    ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)(local_14 + 8));
    if (iVar5 < 1) {
      FUN_00415435(this,param_1,local_14._0_4_,local_14._4_4_,local_14._8_4_,local_8,
                   (int)(local_14._8_4_ - local_14._0_4_) / 2 + local_14._0_4_,
                   (local_8 - local_14._4_4_) / 2 + local_14._4_4_);
    }
    UVar6 = 0x114;
    local_8 = local_8 - local_14._4_4_;
    iVar5 = local_14._8_4_ - local_14._0_4_;
  }
  FUN_0040ec40(param_1,0,local_14._0_4_,local_14._4_4_,iVar5,local_8,UVar6);
  GetParent(*(HWND *)((int)param_1 + 0x1c));
  pCVar4 = FUN_0040b6dd();
  if (pCVar4 != this) {
    if (this == (void *)0x0) {
      hWndNewParent = (HWND)0x0;
    }
    else {
      hWndNewParent = *(HWND *)((int)this + 0x1c);
    }
    SetParent(*(HWND *)((int)param_1 + 0x1c),hWndNewParent);
    FUN_0040b6dd();
  }
  if (*(void **)((int)param_1 + 0x70) != (void *)0x0) {
    FUN_00414cbe(*(void **)((int)param_1 + 0x70),(int)param_1,-1,0);
  }
  *(void **)((int)param_1 + 0x70) = this;
  pCVar4 = FUN_00417a08((int)this);
  *(uint *)(pCVar4 + 0xb8) = *(uint *)(pCVar4 + 0xb8) | 0xc;
  return;
}



/* VA 00414c67 */

void __thiscall FUN_00414c67(void *this,int param_1)

{
  uint uVar1;
  int iVar2;

  iVar2 = -1;
  uVar1 = GetDlgCtrlID(*(HWND *)(param_1 + 0x1c));
  iVar2 = FUN_004153aa(this,uVar1 & 0xffff,iVar2);
  if (0 < iVar2) {
    FUN_0040ad0e((void *)((int)this + 0x7c),iVar2,1);
    if ((*(int *)(*(int *)((int)this + 0x80) + -4 + iVar2 * 4) == 0) &&
       (*(int *)(*(int *)((int)this + 0x80) + iVar2 * 4) == 0)) {
      FUN_0040ad0e((void *)((int)this + 0x7c),iVar2,1);
    }
  }
  return;
}



/* VA 00414cbe */

undefined4 __thiscall FUN_00414cbe(void *this,int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  CWnd *this_00;
  int iVar4;
  int *piVar5;

  iVar1 = FUN_004153aa(this,param_1,param_2);
  if (param_3 == 0) {
    FUN_0040ad0e((void *)((int)this + 0x7c),iVar1,1);
    if ((*(int *)(*(int *)((int)this + 0x80) + -4 + iVar1 * 4) == 0) &&
       (*(int *)(*(int *)((int)this + 0x80) + iVar1 * 4) == 0)) {
      FUN_0040ad0e((void *)((int)this + 0x7c),iVar1,1);
    }
    FUN_00414c67(this,param_1);
  }
  else {
    iVar3 = *(int *)((int)this + 0x80);
    iVar4 = iVar1 * 4;
    uVar2 = GetDlgCtrlID(*(HWND *)(param_1 + 0x1c));
    *(uint *)(iVar3 + iVar4) = uVar2 & 0xffff;
    iVar3 = FUN_004153aa(this,*(int *)(*(int *)((int)this + 0x80) + iVar4),iVar1);
    if (0 < iVar3) {
      FUN_0040ad0e((void *)((int)this + 0x7c),iVar1,1);
      piVar5 = (int *)(iVar4 + *(int *)((int)this + 0x80));
      if ((piVar5[-1] == 0) && (*piVar5 == 0)) {
        FUN_0040ad0e((void *)((int)this + 0x7c),iVar1,1);
      }
    }
  }
  if (*(int *)(param_1 + 0x74) != 0) {
    this_00 = FUN_00417a08((int)this);
    if ((*(int *)((int)this + 0x78) == 0) ||
       (iVar1 = (**(code **)(*(int *)this + 0xe8))(), iVar1 != 0)) {
      *(uint *)(this_00 + 0xb8) = *(uint *)(this_00 + 0xb8) | 0xc;
    }
    else {
      iVar1 = FUN_004147d4(this);
      if (iVar1 == 0) {
        (**(code **)(*(int *)this_00 + 0x60))();
        return 1;
      }
      FUN_0040ec8f(this_00,0);
    }
  }
  return 0;
}



/* VA 00414dce */

void __thiscall FUN_00414dce(void *this,int *param_1,int param_2,int param_3)

{
  uint uVar1;
  BOOL BVar2;
  CWnd *pCVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  HDWP local_88 [8];
  tagRECT local_68;
  undefined1 local_58 [12];
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  tagRECT local_28;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;

  FUN_00412a56(&local_14,param_2,param_3);
  BVar2 = IsRectEmpty((RECT *)((int)this + 0x94));
  if (BVar2 == 0) {
    local_3c = *(int *)((int)this + 0x9c) - ((RECT *)((int)this + 0x94))->left;
    local_38 = *(int *)((int)this + 0xa0) - *(int *)((int)this + 0x98);
  }
  else {
    pCVar3 = FUN_0040ccb3((int)this);
    GetClientRect(*(HWND *)(pCVar3 + 0x1c),(LPRECT)local_58);
    local_3c = local_58._8_4_ - local_58._0_4_;
    local_38 = local_4c - local_58._4_4_;
  }
  if (*(int *)((int)this + 0x90) == 0) {
    local_88[0] = BeginDeferWindowPos(*(int *)((int)this + 0x84));
  }
  else {
    local_88[0] = (HDWP)0x0;
  }
  iVar6 = -DAT_004287f8;
  local_30 = -DAT_004287fc;
  local_2c = 0;
  local_c = 0;
  local_18 = 0;
  local_34 = iVar6;
  if (0 < *(int *)((int)this + 0x84)) {
    do {
      local_8 = (int *)FUN_00415419(this,local_18);
      local_40 = *(int *)(*(int *)((int)this + 0x80) + local_18 * 4);
      if (local_8 != (int *)0x0) {
        iVar5 = *local_8;
        iVar4 = (**(code **)(iVar5 + 0xd0))();
        if (iVar4 != 0) {
          uVar1 = local_8[0x19];
          if (((uVar1 & 4) == 0) || ((uVar1 & 1) == 0)) {
            iVar4 = (-(uint)((uVar1 & 0xa000) != 0) & 0xfffffffa) + 0x10;
          }
          else {
            iVar4 = 6;
          }
          (**(code **)(iVar5 + 0xc4))(&local_48,0xffffffff,iVar4);
          local_28.right = local_48 + iVar6;
          local_28.top = local_30;
          local_28.bottom = local_44 + local_30;
          local_28.left = iVar6;
          GetWindowRect((HWND)local_8[7],(LPRECT)local_58);
          ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)local_58);
          ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)(local_58 + 8));
          if (param_3 == 0) {
            if ((local_28.top < (int)local_58._4_4_) && (*(int *)((int)this + 0x78) == 0)) {
              OffsetRect(&local_28,0,local_58._4_4_ - local_28.top);
            }
            if ((local_38 < local_28.bottom) && (*(int *)((int)this + 0x78) == 0)) {
              iVar4 = local_38 - ((local_28.bottom - DAT_004287fc) - local_28.top);
              iVar5 = local_30;
              if (local_30 < iVar4) {
                iVar5 = iVar4;
              }
              OffsetRect(&local_28,0,iVar5 - local_28.top);
            }
            if (local_c == 0) {
              if (((local_38 - DAT_004287fc <= local_28.top) && (0 < local_18)) &&
                 (*(int *)(*(int *)((int)this + 0x80) + -4 + local_18 * 4) != 0)) {
                FUN_0040ac79((void *)((int)this + 0x7c),local_18,0,1);
                local_8 = (int *)0x0;
                local_40 = 0;
                local_c = 1;
              }
            }
            else {
              local_c = 0;
              OffsetRect(&local_28,0,-(DAT_004287fc + local_28.top));
            }
            if (local_c != 0) goto LAB_0041517f;
            BVar2 = EqualRect(&local_28,(RECT *)local_58);
            if (BVar2 == 0) {
              if ((*(int *)((int)this + 0x90) == 0) && ((*(byte *)(local_8 + 0x19) & 1) == 0)) {
                iVar6 = local_8[0x1d];
                *(LONG *)(iVar6 + 0x94) = local_28.left;
                *(LONG *)(iVar6 + 0x98) = local_28.top;
                *(LONG *)(iVar6 + 0x9c) = local_28.right;
                *(LONG *)(iVar6 + 0xa0) = local_28.bottom;
                iVar6 = local_34;
              }
              FUN_0040d311((int *)local_88,(HWND)local_8[7],&local_28);
            }
            local_30 = (local_28.top - DAT_004287fc) + local_44;
            iVar5 = local_48;
          }
          else {
            if ((local_28.left < (int)local_58._0_4_) && (*(int *)((int)this + 0x78) == 0)) {
              OffsetRect(&local_28,local_58._0_4_ - local_28.left,0);
            }
            if ((local_3c < local_28.right) && (*(int *)((int)this + 0x78) == 0)) {
              iVar5 = local_3c - ((local_28.right - DAT_004287f8) - local_28.left);
              if (iVar5 <= iVar6) {
                iVar5 = iVar6;
              }
              OffsetRect(&local_28,iVar5 - local_28.left,0);
            }
            if (local_c == 0) {
              if (((local_3c - DAT_004287f8 <= local_28.left) && (0 < local_18)) &&
                 (*(int *)(*(int *)((int)this + 0x80) + -4 + local_18 * 4) != 0)) {
                FUN_0040ac79((void *)((int)this + 0x7c),local_18,0,1);
                local_8 = (int *)0x0;
                local_40 = 0;
                local_c = 1;
              }
            }
            else {
              local_c = 0;
              OffsetRect(&local_28,-(DAT_004287f8 + local_28.left),0);
            }
            if (local_c != 0) goto LAB_00415167;
            BVar2 = EqualRect(&local_28,(RECT *)local_58);
            if (BVar2 == 0) {
              if ((*(int *)((int)this + 0x90) == 0) && ((*(byte *)(local_8 + 0x19) & 1) == 0)) {
                iVar6 = local_8[0x1d];
                *(LONG *)(iVar6 + 0x94) = local_28.left;
                *(LONG *)(iVar6 + 0x98) = local_28.top;
                *(LONG *)(iVar6 + 0x9c) = local_28.right;
                *(LONG *)(iVar6 + 0xa0) = local_28.bottom;
              }
              FUN_0040d311((int *)local_88,(HWND)local_8[7],&local_28);
            }
            iVar6 = (local_28.left - DAT_004287f8) + local_48;
            iVar5 = local_44;
            local_34 = iVar6;
          }
          if (local_2c <= iVar5) {
            local_2c = iVar5;
          }
        }
LAB_00415167:
        if (local_c == 0) {
          (**(code **)(*local_8 + 0xd4))(local_88);
        }
      }
LAB_0041517f:
      if (((local_8 == (int *)0x0) && (local_40 == 0)) && (local_2c != 0)) {
        if (param_3 == 0) {
          iVar6 = iVar6 + (local_2c - DAT_004287f8);
          if (local_14 <= iVar6) {
            local_14 = iVar6;
          }
          if (local_10 <= local_30) {
            local_10 = local_30;
          }
          local_30 = -DAT_004287fc;
        }
        else {
          local_30 = local_30 + (local_2c - DAT_004287fc);
          if (local_14 <= iVar6) {
            local_14 = iVar6;
          }
          if (local_10 <= local_30) {
            local_10 = local_30;
          }
          iVar6 = -DAT_004287f8;
        }
        local_2c = 0;
        local_34 = iVar6;
      }
      local_18 = local_18 + 1;
    } while (local_18 < *(int *)((int)this + 0x84));
  }
  if ((*(int *)((int)this + 0x90) == 0) && (local_88[0] != (HDWP)0x0)) {
    EndDeferWindowPos(local_88[0]);
  }
  SetRectEmpty(&local_68);
  FUN_004137e1(this,&local_68.left,param_3);
  if (((param_2 == 0) || (param_3 == 0)) && (local_14 != 0)) {
    local_14 = local_14 + (local_68.left - local_68.right);
  }
  if (((param_2 == 0) || (param_3 != 0)) && (local_10 != 0)) {
    local_10 = local_10 + (local_68.top - local_68.bottom);
  }
  *param_1 = local_14;
  param_1[1] = local_10;
  return;
}



/* VA 00415278 */

void __thiscall FUN_00415278(void *this,undefined4 param_1,int *param_2)

{
  LPRECT lprcDst;
  LONG LVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;

  uVar5 = *(undefined4 *)((int)this + 0x90);
  lprcDst = (LPRECT)((int)this + 0x94);
  LVar1 = lprcDst->left;
  uVar2 = *(undefined4 *)((int)this + 0x98);
  uVar3 = *(undefined4 *)((int)this + 0x9c);
  uVar4 = *(undefined4 *)((int)this + 0xa0);
  *(uint *)((int)this + 0x90) = (uint)(*param_2 == 0);
  CopyRect(lprcDst,(RECT *)(param_2 + 1));
  FUN_00413470(this,param_1,param_2);
  lprcDst->left = LVar1;
  *(undefined4 *)((int)this + 0x98) = uVar2;
  *(undefined4 *)((int)this + 0x9c) = uVar3;
  *(undefined4 *)((int)this + 0xa0) = uVar4;
  *(undefined4 *)((int)this + 0x90) = uVar5;
  return;
}



/* VA 004152de */

void __thiscall FUN_004152de(void *this,undefined4 param_1,int *param_2)

{
  tagRECT local_14;

  SetRectEmpty(&local_14);
  FUN_004137e1(this,&local_14.left,*(uint *)((int)this + 100) & 0xa000);
  *param_2 = *param_2 + local_14.left;
  param_2[1] = param_2[1] + local_14.top;
  param_2[2] = param_2[2] + local_14.right;
  param_2[3] = param_2[3] + local_14.bottom;
  return;
}



/* VA 0041532c */

void FUN_0041532c(void)

{
  int iVar1;
  int iVar2;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  FUN_004112db();
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = (**(code **)(iVar1 + 0xd0))();
  if (iVar2 != 0) {
    iVar2 = (**(code **)(iVar1 + 0xe8))();
    if (iVar2 != 0) {
      (**(code **)(iVar1 + 0xe0))(unaff_EBP + -0x60);
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CPaintDC::~CPaintDC((CPaintDC *)(unaff_EBP + -0x60));
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 0041538a */

void __thiscall FUN_0041538a(void *this,int param_1)

{
  uint uVar1;

  uVar1 = *(uint *)((int)this + 100);
  *(uint *)((int)this + 100) = uVar1 & 0xfffff0ff;
  FUN_00412f8c(this,param_1);
  *(uint *)((int)this + 100) = uVar1;
  return;
}



/* VA 004153aa */

int __thiscall FUN_004153aa(void *this,int param_1,int param_2)

{
  int iVar1;

  iVar1 = 0;
  if (0 < *(int *)((int)this + 0x84)) {
    do {
      if ((iVar1 != param_2) && (*(int *)(*(int *)((int)this + 0x80) + iVar1 * 4) == param_1)) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)((int)this + 0x84));
  }
  return -1;
}



/* VA 004153d8 */

void __thiscall FUN_004153d8(void *this,int param_1)

{
  int *piVar1;
  int iVar2;

  iVar2 = 0;
  if (0 < *(int *)((int)this + 0x84)) {
    do {
      piVar1 = (int *)FUN_00415419(this,iVar2);
      if (piVar1 != (int *)0x0) {
        FUN_00417a08((int)piVar1);
        FUN_00416be4(piVar1,param_1,1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)this + 0x84));
  }
  return;
}



/* VA 00415419 */

uint __thiscall FUN_00415419(void *this,int param_1)

{
  uint uVar1;

  uVar1 = *(uint *)(*(int *)((int)this + 0x80) + param_1 * 4);
  return uVar1 & -(uint)((short)(uVar1 >> 0x10) != 0);
}



/* VA 00415435 */

int __thiscall
FUN_00415435(void *this,undefined4 param_1,int param_2,int param_3,undefined4 param_4,
            undefined4 param_5,int param_6,int param_7)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined1 local_24 [12];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;

  local_10 = 0;
  local_c = 0;
  bVar3 = (*(uint *)((int)this + 100) & 0xa000) == 0;
  local_14 = 0;
  local_8 = 0;
  if (0 < *(int *)((int)this + 0x84)) {
    do {
      piVar1 = (int *)FUN_00415419(this,local_8);
      if ((piVar1 == (int *)0x0) || (iVar2 = (**(code **)(*piVar1 + 0xd0))(), iVar2 == 0)) {
        iVar2 = local_c - DAT_004287fc;
        local_c = 0;
        local_14 = local_14 + iVar2;
        iVar2 = param_7;
        if (bVar3) {
          iVar2 = param_6;
        }
        if (iVar2 < local_14) {
          if (local_8 == 0) {
            FUN_0040ac79((void *)((int)this + 0x7c),local_10 + 1,0,1);
          }
          iVar2 = local_10 + 1;
          goto LAB_00415554;
        }
LAB_0041551e:
        local_10 = local_8;
      }
      else {
        GetWindowRect((HWND)piVar1[7],(LPRECT)local_24);
        ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)local_24);
        ScreenToClient(*(HWND *)((int)this + 0x1c),(LPPOINT)(local_24 + 8));
        if (bVar3) {
          iVar2 = (local_24._8_4_ - local_24._0_4_) + -1;
        }
        else {
          iVar2 = local_18 - local_24._4_4_;
        }
        if (local_c <= iVar2) {
          if (bVar3) {
            local_c = (local_24._8_4_ - local_24._0_4_) + -1;
          }
          else {
            local_c = local_18 - local_24._4_4_;
          }
        }
        if (bVar3) {
          bVar5 = SBORROW4(param_3,local_24._4_4_);
          iVar2 = param_3 - local_24._4_4_;
          bVar4 = param_3 == local_24._4_4_;
        }
        else {
          bVar5 = SBORROW4(param_2,local_24._0_4_);
          iVar2 = param_2 - local_24._0_4_;
          bVar4 = param_2 == local_24._0_4_;
        }
        if (!bVar4 && bVar5 == iVar2 < 0) goto LAB_0041551e;
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)((int)this + 0x84));
  }
  iVar2 = local_10 + 1;
  FUN_0040ac79((void *)((int)this + 0x7c),iVar2,0,1);
LAB_00415554:
  FUN_0040ac79((void *)((int)this + 0x7c),iVar2,param_1,1);
  return iVar2;
}



/* VA 004155ac */

undefined4 * FUN_004155ac(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00417eec();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00414671();
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0x42] = 0;
  *extraout_ECX = &PTR_LAB_0041eca4;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}



/* VA 004155ef */

undefined * __thiscall FUN_004155ef(void *this,byte param_1)

{
  FUN_0041560b();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 0041560b */

void FUN_0041560b(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00414708();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004180ad();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 0041563f */

undefined4 FUN_0041563f(void)

{
  uint uVar1;
  bool bVar2;
  DWORD DVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 uVar5;
  HWND hWndNewParent;
  void *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  DVar3 = 0x80c83b00;
  *(undefined4 *)((int)this + 0xb0) = 1;
  if ((uVar1 & 4) != 0) {
    DVar3 = 0x80c83300;
  }
  iVar4 = FUN_004180f7(this,0,(LPCSTR)0x0,&DAT_004287a4,DVar3,(int *)&DAT_00426d40,
                       *(int *)(unaff_EBP + 8),(HMENU)0x0);
  if (iVar4 == 0) {
    *(undefined4 *)((int)this + 0xb0) = 0;
  }
  else {
    GetSystemMenu(*(HWND *)((int)this + 0x1c),0);
    iVar4 = FUN_0040fb75();
    DeleteMenu(*(HMENU *)(iVar4 + 4),0xf000,0);
    FUN_0040fe73((undefined4 *)(unaff_EBP + 0xc));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    bVar2 = FUN_0040f9ce(0xf011);
    if (CONCAT31(extraout_var,bVar2) != 0) {
      DeleteMenu(*(HMENU *)(iVar4 + 4),0xf060,0);
      AppendMenuA(*(HMENU *)(iVar4 + 4),0,0xf060,*(LPCSTR *)(unaff_EBP + 0xc));
    }
    bVar2 = FUN_00414774((void *)((int)this + 0xcc),*(int *)(unaff_EBP + 8),
                         (-(uint)((uVar1 & 0x5000) != 0) & 0xfffff000) + 0x2000 | uVar1 & 0x40 |
                         0x50000000,(HMENU)0xe81f);
    if (CONCAT31(extraout_var_00,bVar2) != 0) {
      if (this == (void *)0x0) {
        hWndNewParent = (HWND)0x0;
      }
      else {
        hWndNewParent = *(HWND *)((int)this + 0x1c);
      }
      SetParent(*(HWND *)((int)this + 0xe8),hWndNewParent);
      FUN_0040b6dd();
      *(undefined4 *)((int)this + 0xb0) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0040ff87((int *)(unaff_EBP + 0xc));
      uVar5 = 1;
      goto LAB_0041577a;
    }
    *(undefined4 *)((int)this + 0xb0) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0040ff87((int *)(unaff_EBP + 0xc));
  }
  uVar5 = 0;
LAB_0041577a:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar5;
}



/* VA 0041578b */

void __thiscall FUN_0041578b(void *this,int param_1)

{
  CHAR local_108 [260];

  if (*(int *)((int)this + 0xb0) == 0) {
    FUN_00417745(this,param_1);
    FUN_0040ec11((void *)((int)this + 0xcc),local_108,0x104);
    FUN_0041162b(*(HWND *)((int)this + 0x1c),local_108);
  }
  return;
}



/* VA 004157e1 */

void __thiscall FUN_004157e1(void *this,uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;

  if (param_1 == 2) {
    CWnd::ActivateTopParent(this);
    if ((*(byte *)((int)this + 0x130) & 0x40) == 0) {
      uVar1 = 0;
      iVar2 = 1;
      do {
        if (*(int *)((int)this + 0x150) <= iVar2) break;
        uVar1 = FUN_00415419((void *)((int)this + 0xcc),iVar2);
        iVar2 = iVar2 + 1;
      } while (uVar1 == 0);
      (**(code **)**(undefined4 **)(uVar1 + 0x74))(param_2,param_3);
      return;
    }
  }
  else if ((9 < param_1) && (param_1 < 0x12)) {
    CWnd::ActivateTopParent(this);
    uVar1 = 0;
    iVar2 = 1;
    do {
      if (*(int *)((int)this + 0x150) <= iVar2) break;
      uVar1 = FUN_00415419((void *)((int)this + 0xcc),iVar2);
      iVar2 = iVar2 + 1;
    } while (uVar1 == 0);
    (**(code **)(**(int **)(uVar1 + 0x74) + 4))(param_1,param_2,param_3);
    return;
  }
  FUN_0041863e(this,param_1);
  return;
}



/* VA 0041595b */

undefined4 * FUN_0041595b(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0040b374(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040a8e8(extraout_ECX + 0x1b,10);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0040fe73(extraout_ECX + 0x2b);
  extraout_ECX[0x10] = 0xffffffff;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *extraout_ECX = &PTR_LAB_0041c8ec;
  extraout_ECX[0xf] = 1;
  extraout_ECX[0x27] = 0;
  extraout_ECX[0x11] = 0;
  extraout_ECX[0x12] = 0;
  extraout_ECX[0x23] = 0;
  extraout_ECX[0x24] = 0;
  extraout_ECX[0x25] = 0;
  extraout_ECX[0x26] = 0;
  extraout_ECX[0x28] = 0;
  extraout_ECX[0x29] = 0;
  extraout_ECX[0x1a] = 0;
  extraout_ECX[0x2a] = 0;
  extraout_ECX[0x2e] = 0;
  SetRectEmpty((LPRECT)(extraout_ECX + 0x16));
  extraout_ECX[0x22] = 0xffffffff;
  extraout_ECX[0x14] = 0;
  extraout_ECX[0x13] = 0;
  extraout_ECX[0x15] = 0;
  extraout_ECX[0x2c] = 0;
  extraout_ECX[0x2d] = 0;
  FUN_00415aa4((int)extraout_ECX);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}



/* VA 00415a21 */

undefined * __thiscall FUN_00415a21(void *this,byte param_1)

{
  FUN_00415a3d();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 00415a3d */

void FUN_00415a3d(void)

{
  CWnd *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(CWnd **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_LAB_0041c8ec;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_00415ac8((int)this);
  if (*(undefined **)(this + 0xa4) != (undefined *)0x0) {
    FUN_0040f384(*(undefined **)(this + 0xa4));
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0040ff87((int *)(this + 0xac));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0040a947();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWnd::~CWnd(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00415aa4 */

void __fastcall FUN_00415aa4(int param_1)

{
  int iVar1;

  iVar1 = FUN_00419dc2();
  iVar1 = FUN_0041a9d0((void *)(iVar1 + 0x1070),FUN_00401a57);
  FUN_0041a5be((void *)(iVar1 + 8),param_1);
  return;
}



/* VA 00415ac8 */

void __fastcall FUN_00415ac8(int param_1)

{
  int iVar1;

  iVar1 = FUN_00419dc2();
  iVar1 = FUN_0041a9d0((void *)(iVar1 + 0x1070),FUN_00401a57);
  FUN_0041a5d1((void *)(iVar1 + 8),param_1);
  return;
}



/* VA 00415aec */

bool __thiscall FUN_00415aec(void *this,LPCSTR param_1)

{
  int iVar1;
  HACCEL pHVar2;

  iVar1 = FUN_00419dc2();
  pHVar2 = LoadAcceleratorsA(*(HINSTANCE *)(iVar1 + 0xc),param_1);
  *(HACCEL *)((int)this + 0x48) = pHVar2;
  return pHVar2 != (HACCEL)0x0;
}



/* VA 00415bb9 */

void __thiscall FUN_00415bb9(void *this,undefined4 param_1)

{
  FUN_0040b632(this);
  if (*(int **)((int)this + 0x68) != (int *)0x0) {
    (**(code **)(**(int **)((int)this + 0x68) + 0x74))(param_1);
  }
  return;
}



/* VA 00415bd5 */

undefined4 __fastcall FUN_00415bd5(int *param_1)

{
  int iVar1;
  undefined4 uVar2;

  if ((int *)param_1[0x1a] != (int *)0x0) {
    iVar1 = (**(code **)(*(int *)param_1[0x1a] + 0x78))();
    if (iVar1 != 0) {
      return 1;
    }
  }
  uVar2 = FUN_0040b632(param_1);
  return uVar2;
}



/* VA 00415c61 */

undefined4 __fastcall FUN_00415c61(CWnd *param_1)

{
  CWnd *pCVar1;
  undefined4 uVar2;

  pCVar1 = FUN_0040ce20(param_1);
  if (*(int *)(pCVar1 + 0x50) == 0) {
    uVar2 = FUN_0040b632((int *)param_1);
  }
  else {
    SetCursor(DAT_0042882c);
    uVar2 = 1;
  }
  return uVar2;
}



/* VA 00415c8b */

undefined4 __thiscall FUN_00415c8b(void *this,undefined4 param_1,int param_2)

{
  int iVar1;

  if (param_2 == 0) {
    iVar1 = FUN_0040e236((int)this);
    if (iVar1 == 0) {
      param_2 = *(int *)((int)this + 0x8c) + 0x20000;
    }
    else {
      param_2 = *(int *)((int)this + 0x90) + 0x10000;
    }
    if (param_2 == 0) {
      return 0;
    }
  }
  iVar1 = FUN_00419dc2();
  (**(code **)(**(int **)(iVar1 + 4) + 0xa0))(param_2,1);
  return 1;
}



/* VA 00415d6c */

undefined4 FUN_00415d6c(HWND__ *param_1,HWND__ *param_2)

{
  do {
    if (param_1 == param_2) {
      return 1;
    }
    param_2 = AfxGetParentOwner(param_2);
  } while (param_2 != (HWND__ *)0x0);
  return 0;
}



/* VA 00415eb9 */

void __fastcall FUN_00415eb9(int param_1)

{
  int *piVar1;
  BOOL BVar2;
  int iVar3;

  if (((*(int *)(param_1 + 0xa0) != 0) &&
      (iVar3 = *(int *)(param_1 + 0xa0) + -1, *(int *)(param_1 + 0xa0) = iVar3, iVar3 == 0)) &&
     (piVar1 = *(int **)(param_1 + 0xa4), piVar1 != (int *)0x0)) {
    if (*piVar1 != 0) {
      iVar3 = 0;
      do {
        BVar2 = IsWindow(*(HWND *)(iVar3 + (int)piVar1));
        if (BVar2 != 0) {
          EnableWindow(*(HWND *)(*(int *)(param_1 + 0xa4) + iVar3),1);
        }
        piVar1 = *(int **)(param_1 + 0xa4);
        iVar3 = iVar3 + 4;
      } while (*(int *)(iVar3 + (int)piVar1) != 0);
    }
    FUN_0040f384(*(undefined **)(param_1 + 0xa4));
    *(undefined4 *)(param_1 + 0xa4) = 0;
  }
  return;
}



/* VA 00415f28 */

void __thiscall FUN_00415f28(void *this,int param_1)

{
  HWND hWnd;
  HWND__ *hWnd_00;
  int iVar1;
  int iVar2;
  uint uVar3;
  UINT uCmd;

  uCmd = 5;
  hWnd = GetDesktopWindow();
  for (hWnd_00 = GetWindow(hWnd,uCmd); hWnd_00 != (HWND__ *)0x0; hWnd_00 = GetWindow(hWnd_00,2)) {
    iVar1 = FUN_0040b705((uint)hWnd_00);
    if (((iVar1 != 0) && (*(HWND__ **)((int)this + 0x1c) != hWnd_00)) &&
       (iVar2 = FUN_00415d6c(*(HWND__ **)((int)this + 0x1c),hWnd_00), iVar2 != 0)) {
      uVar3 = GetWindowLongA(hWnd_00,-0x10);
      if (param_1 == 0) {
        if ((uVar3 & 0x18000000) == 0x10000000) {
          ShowWindow(hWnd_00,0);
          *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) | 2;
        }
      }
      else if (((uVar3 & 0x18000000) == 0) && ((*(byte *)(iVar1 + 0x24) & 2) != 0)) {
        ShowWindow(hWnd_00,4);
        *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) & 0xfffffffd;
      }
    }
  }
  return;
}



/* VA 00415fca */

void __thiscall FUN_00415fca(void *this,int param_1)

{
  HWND hWnd;
  CWnd *pCVar1;
  HWND pHVar2;

  if ((param_1 == 0) || ((*(byte *)((int)this + 0x24) & 4) == 0)) {
    GetParent(*(HWND *)((int)this + 0x1c));
    pCVar1 = FUN_0040b6dd();
    if (pCVar1 == (CWnd *)0x0) {
      if ((param_1 == 0) && (*(int *)((int)this + 0xa0) == 0)) {
        *(byte *)((int)this + 0x24) = *(byte *)((int)this + 0x24) | 0x80;
        (**(code **)(*(int *)this + 0x90))();
      }
      else if ((param_1 != 0) && ((*(uint *)((int)this + 0x24) & 0x80) != 0)) {
        *(uint *)((int)this + 0x24) = *(uint *)((int)this + 0x24) & 0xffffff7f;
        (**(code **)(*(int *)this + 0x94))();
        hWnd = *(HWND *)((int)this + 0x1c);
        pHVar2 = GetActiveWindow();
        if (pHVar2 == hWnd) {
          SendMessageA(hWnd,6,1,0);
        }
      }
      if ((param_1 != 0) && ((*(byte *)((int)this + 0x24) & 0x20) != 0)) {
        SendMessageA(*(HWND *)((int)this + 0x1c),0x86,1,0);
      }
      FUN_00416088(this,(-(uint)(param_1 != 0) & 0xfffffff0) + 0x20);
    }
  }
  else {
    FUN_0040ecd1(this,0);
    SetFocus((HWND)0x0);
  }
  return;
}



/* VA 00416088 */

void __thiscall FUN_00416088(void *this,uint param_1)

{
  uint uVar1;
  CWnd *pCVar2;
  int iVar3;
  HWND hWnd;
  UINT uCmd;

  uVar1 = FUN_0040eb4e((int)this);
  pCVar2 = this;
  if ((uVar1 & 0x40000000) == 0) {
    pCVar2 = FUN_0040ce20(this);
  }
  if ((param_1 & 0xc) != 0) {
    iVar3 = FUN_0040ecb6((int)pCVar2);
    if ((((~param_1 & 8) == 0) || (iVar3 == 0)) || (pCVar2 == this)) {
      SendMessageA(*(HWND *)(pCVar2 + 0x1c),0x86,0,0);
    }
    else {
      *(byte *)((int)this + 0x25) = *(byte *)((int)this + 0x25) | 2;
      SendMessageA(*(HWND *)(pCVar2 + 0x1c),0x86,1,0);
      *(byte *)((int)this + 0x25) = *(byte *)((int)this + 0x25) & 0xfd;
    }
  }
  uCmd = 5;
  hWnd = GetDesktopWindow();
  while (hWnd = GetWindow(hWnd,uCmd), hWnd != (HWND)0x0) {
    iVar3 = FUN_00415d6c(*(HWND__ **)(pCVar2 + 0x1c),hWnd);
    if (iVar3 != 0) {
      SendMessageA(hWnd,0x36d,param_1,0);
    }
    uCmd = 2;
  }
  return;
}



/* VA 00416132 */

undefined4 FUN_00416132(int param_1)

{
  int iVar1;

  if (*(int *)(param_1 + 0x28) == 0) {
    iVar1 = FUN_00419dc2();
    if ((*(byte *)(iVar1 + 0x18) & 8) == 0) {
      iVar1 = FUN_0040e0b4(8);
    }
    else {
      iVar1 = 1;
    }
    if (iVar1 == 0) {
      return 0;
    }
    *(char **)(param_1 + 0x28) = "AfxFrameOrView42s";
  }
  if ((*(uint *)(param_1 + 0x20) & 0x8000) != 0) {
    if (DAT_00428844 == 0) {
      return 1;
    }
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x4000;
  }
  if (DAT_00428844 != 0) {
    *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 2;
  }
  return 1;
}



/* VA 0041618a */

undefined4 __thiscall
FUN_0041618a(void *this,LPCSTR param_1,LPCSTR param_2,DWORD param_3,int *param_4,int param_5,
            LPCSTR param_6,DWORD param_7,LPVOID param_8)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  HMENU hMenu;
  HWND pHVar3;

  pHVar3 = (HWND)0x0;
  hMenu = (HMENU)0x0;
  if (param_6 != (LPCSTR)0x0) {
    iVar2 = FUN_00419dc2();
    hMenu = LoadMenuA(*(HINSTANCE *)(iVar2 + 0xc),param_6);
    if (hMenu == (HMENU)0x0) {
      (**(code **)(*(int *)this + 0xac))();
      return 0;
    }
  }
  FUN_0040ffdd((void *)((int)this + 0xac),param_2);
  if (param_5 != 0) {
    pHVar3 = *(HWND *)(param_5 + 0x1c);
  }
  bVar1 = FUN_0040bc7c(this,param_7,param_1,param_2,param_3,*param_4,param_4[1],
                       param_4[2] - *param_4,param_4[3] - param_4[1],pHVar3,hMenu,param_8);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if (hMenu != (HMENU)0x0) {
      DestroyMenu(hMenu);
    }
    return 0;
  }
  return 1;
}



/* VA 00416222 */

int * FUN_00416222(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  void *local_8;

  piVar1 = (int *)FUN_0040fc25();
  if (piVar1 != (int *)0x0) {
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    iVar2 = (**(code **)(*piVar1 + 0x5c))(0,0,0x50800000,&local_18,local_8,param_2,param_1);
    if (iVar2 != 0) {
      if (DAT_00428844 == 0) {
        return piVar1;
      }
      uVar3 = FUN_0040eb68((int)piVar1);
      if ((uVar3 & 0x200) == 0) {
        return piVar1;
      }
      FUN_0040ebb6(local_8,0x200,0,0x20);
      return piVar1;
    }
  }
  return (int *)0x0;
}



/* VA 004162bc */

void __thiscall FUN_004162bc(void *this,undefined4 *param_1)

{
  FUN_004162cb(this,param_1,*param_1);
  return;
}



/* VA 004162cb */

undefined4 __thiscall FUN_004162cb(void *this,undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;

  iVar1 = FUN_0040b632(this);
  if (iVar1 != -1) {
    iVar1 = *(int *)this;
    iVar2 = (**(code **)(iVar1 + 0xe4))(param_1,param_2);
    if (iVar2 != 0) {
      PostMessageA(*(HWND *)((int)this + 0x1c),0x362,0xe001,0);
      (**(code **)(iVar1 + 0xd0))(1);
      return 0;
    }
  }
  return 0xffffffff;
}



/* VA 0041631a */

/* Library Function - Multiple Matches With Same Base Name
    protected: char const * __thiscall CFrameWnd::GetIconWndClass(unsigned long,unsigned int)
    protected: wchar_t const * __thiscall CFrameWnd::GetIconWndClass(unsigned long,unsigned int)

   Library: Visual Studio 2003 Release */

LPSTR __thiscall GetIconWndClass(void *this,undefined4 param_1,ushort param_2)

{
  int iVar1;
  HICON pHVar2;
  BOOL BVar3;
  LPSTR pCVar4;
  undefined1 local_5c [32];
  undefined4 local_3c;
  LPCSTR local_34;
  tagWNDCLASSA local_2c;

  iVar1 = FUN_00419dc2();
  pHVar2 = LoadIconA(*(HINSTANCE *)(iVar1 + 0xc),(LPCSTR)(uint)param_2);
  if (pHVar2 != (HICON)0x0) {
    _memset(local_5c,0,0x30);
    local_3c = param_1;
    (**(code **)(*(int *)this + 100))(local_5c);
    if (local_34 != (LPCSTR)0x0) {
      iVar1 = FUN_00419dc2();
      BVar3 = GetClassInfoA(*(HINSTANCE *)(iVar1 + 8),local_34,&local_2c);
      if ((BVar3 != 0) && (local_2c.hIcon != pHVar2)) {
        pCVar4 = FUN_0040c3b0(local_2c.style,local_2c.hCursor,local_2c.hbrBackground,pHVar2);
        return pCVar4;
      }
    }
  }
  return (LPSTR)0x0;
}



/* VA 0041639d */

undefined4 FUN_0041639d(void)

{
  uint uVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  LPSTR pCVar4;
  undefined4 uVar5;
  HMENU pHVar6;
  void *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  uVar1 = *(uint *)(unaff_EBP + 8);
  *(uint *)((int)this + 0x8c) = uVar1;
  FUN_0040fe73((undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  bVar2 = FUN_0040f9ce(uVar1);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    FUN_0040fa79((int *)((int)this + 0xac),*(byte **)(unaff_EBP + 8),0,'\n');
  }
  iVar3 = FUN_00419dc2();
  if ((*(byte *)(iVar3 + 0x18) & 8) == 0) {
    iVar3 = FUN_0040e0b4(8);
  }
  else {
    iVar3 = 1;
  }
  if (iVar3 != 0) {
    pCVar4 = GetIconWndClass(this,*(undefined4 *)(unaff_EBP + 0xc),(ushort)uVar1);
    iVar3 = FUN_0041618a(this,pCVar4,*(LPCSTR *)((int)this + 0xac),*(DWORD *)(unaff_EBP + 0xc),
                         (int *)&DAT_00426d40,*(int *)(unaff_EBP + 0x10),(LPCSTR)(uVar1 & 0xffff),0,
                         *(LPVOID *)(unaff_EBP + 0x14));
    if (iVar3 != 0) {
      pHVar6 = GetMenu(*(HWND *)((int)this + 0x1c));
      *(HMENU *)((int)this + 0x44) = pHVar6;
      FUN_00415aec(this,(LPCSTR)(uVar1 & 0xffff));
      if (*(int *)(unaff_EBP + 0x14) == 0) {
        FUN_0040cf7d(*(HWND *)((int)this + 0x1c),0x364,0,0,1,1);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0040ff87((int *)(unaff_EBP + 8));
      uVar5 = 1;
      goto LAB_00416477;
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0040ff87((int *)(unaff_EBP + 8));
  uVar5 = 0;
LAB_00416477:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar5;
}



/* VA 004164c2 */

void __fastcall FUN_004164c2(CWnd *param_1)

{
  int *this;
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined3 extraout_var;
  int iVar5;
  CWnd *pCVar6;
  int local_8;

  if ((*(code **)(param_1 + 0x9c) == (code *)0x0) ||
     (iVar2 = (**(code **)(param_1 + 0x9c))(param_1), iVar2 != 0)) {
    iVar2 = *(int *)param_1;
    piVar3 = (int *)(**(code **)(iVar2 + 0xc4))();
    if ((piVar3 == (int *)0x0) || (iVar4 = (**(code **)(*piVar3 + 0x94))(param_1), iVar4 != 0)) {
      iVar4 = FUN_00419dc2();
      this = *(int **)(iVar4 + 4);
      if ((CWnd *)this[7] == param_1) {
        if ((piVar3 == (int *)0x0) && (iVar4 = (**(code **)(*this + 0x90))(), iVar4 == 0)) {
          return;
        }
        FUN_004126c8((int)this);
        FUN_00412928(this,0);
        bVar1 = FUN_00417a9c();
        if (CONCAT31(extraout_var,bVar1) == 0) {
          FUN_00417aac(0);
          return;
        }
        iVar4 = FUN_00419dc2();
        if ((*(char *)(iVar4 + 0x14) == '\0') && (this[7] == 0)) {
          AfxPostQuitMessage(0);
          return;
        }
      }
      if ((piVar3 != (int *)0x0) && (piVar3[0x12] != 0)) {
        iVar4 = *piVar3;
        bVar1 = false;
        local_8 = (**(code **)(iVar4 + 0x68))();
        do {
          if (local_8 == 0) goto LAB_004165a5;
          iVar5 = (**(code **)(iVar4 + 0x6c))(&local_8);
          pCVar6 = FUN_0040ccb3(iVar5);
        } while (pCVar6 == param_1);
        bVar1 = true;
LAB_004165a5:
        if (!bVar1) {
          (**(code **)(iVar4 + 0x84))();
          return;
        }
        (**(code **)(iVar4 + 0x9c))(param_1);
      }
      (**(code **)(iVar2 + 0x60))();
    }
  }
  return;
}



/* VA 004165cb */

void __fastcall FUN_004165cb(int *param_1)

{
  HMENU hMenu;
  HMENU pHVar1;
  int iVar2;

  FUN_004170c7();
  if (param_1[0x11] != 0) {
    hMenu = (HMENU)param_1[0x11];
    pHVar1 = GetMenu((HWND)param_1[7]);
    if (pHVar1 != hMenu) {
      SetMenu((HWND)param_1[7],hMenu);
    }
  }
  iVar2 = FUN_00419dc2();
  if (*(int **)(*(int *)(iVar2 + 4) + 0x1c) == param_1) {
    WinHelpA((HWND)param_1[7],(LPCSTR)0x0,2,0);
  }
  FUN_0040be3a(param_1);
  return;
}



/* VA 0041661a */

void __thiscall FUN_0041661a(void *this,int param_1)

{
  int *piVar1;

  piVar1 = FUN_0040aa6c((void *)((int)this + 0x6c),param_1,(undefined4 *)0x0);
  if (piVar1 != (int *)0x0) {
    FUN_0040aa35((void *)((int)this + 0x6c),piVar1);
  }
  return;
}



/* VA 0041663b */

undefined4 __thiscall
FUN_0041663b(void *this,undefined4 *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;

  piVar1 = (int *)FUN_00416b58((int)this);
  if (((piVar1 == (int *)0x0) ||
      (iVar2 = (**(code **)(*piVar1 + 0x14))(param_1,param_2,param_3,param_4), iVar2 == 0)) &&
     (uVar3 = FUN_0040ee06(this,param_1,param_2,param_3,param_4), uVar3 == 0)) {
    iVar2 = FUN_00419dc2();
    if ((*(int **)(iVar2 + 4) == (int *)0x0) ||
       (iVar2 = (**(code **)(**(int **)(iVar2 + 4) + 0x14))(param_1,param_2,param_3,param_4),
       iVar2 == 0)) {
      return 0;
    }
  }
  return 1;
}



/* VA 00416775 */

void __thiscall FUN_00416775(void *this,int param_1,CWnd *param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  CWnd *pCVar3;
  CWnd *pCVar4;
  LRESULT LVar5;
  int *piVar6;
  int iVar7;

  FUN_0040b632(this);
  uVar2 = FUN_0040eb4e((int)this);
  pCVar3 = this;
  if ((uVar2 & 0x40000000) == 0) {
    pCVar3 = FUN_0040ce20(this);
  }
  if (param_1 != 0) {
    param_2 = this;
  }
  if ((pCVar3 == param_2) ||
     ((pCVar4 = FUN_0040ce20(param_2), pCVar3 == pCVar4 &&
      (LVar5 = SendMessageA(*(HWND *)(param_2 + 0x1c),0x36d,0x40,0), LVar5 != 0)))) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  *(uint *)(pCVar3 + 0x24) = *(uint *)(pCVar3 + 0x24) & 0xffffffdf;
  if (bVar1) {
    *(uint *)(pCVar3 + 0x24) = *(uint *)(pCVar3 + 0x24) | 0x20;
  }
  FUN_00416088(this,(-(uint)bVar1 & 0xfffffffc) + 8);
  piVar6 = (int *)FUN_00416b58((int)this);
  if (piVar6 == (int *)0x0) {
    iVar7 = (**(code **)(*(int *)this + 200))();
    piVar6 = (int *)FUN_00416b58(iVar7);
    if (piVar6 == (int *)0x0) {
      return;
    }
  }
  if ((param_1 != 0) && (param_3 == 0)) {
    (**(code **)(*piVar6 + 0xec))(1,piVar6,piVar6);
  }
  (**(code **)(*piVar6 + 0xf0))(param_1,this);
  return;
}



/* VA 00416849 */

void __thiscall FUN_00416849(void *this,undefined4 param_1)

{
  int iVar1;

  if ((*(byte *)((int)this + 0x24) & 0x20) != 0) {
    param_1 = 1;
  }
  iVar1 = FUN_0040ecb6((int)this);
  if (iVar1 == 0) {
    param_1 = 0;
  }
  (**(code **)(*(int *)this + 0xa8))(0x86,param_1,0);
  return;
}



/* VA 00416880 */

void __thiscall FUN_00416880(void *this,uint param_1)

{
  CWnd *pCVar1;
  LRESULT LVar2;
  uint uVar3;

  pCVar1 = FUN_0040ce20(this);
  uVar3 = param_1 & 0xfff0;
  if (*(int *)(pCVar1 + 0x50) == 0) {
LAB_004168ac:
    FUN_0040b632(this);
  }
  else {
    if (uVar3 < 0xf011) {
      if ((uVar3 != 0xf010) && (uVar3 != 0xf000)) goto LAB_004168ac;
    }
    else if (uVar3 != 0xf020) {
      if (((((uVar3 != 0xf030) && (uVar3 != 0xf040)) && (uVar3 != 0xf050)) &&
          ((uVar3 != 0xf060 && (uVar3 != 0xf120)))) && (uVar3 != 0xf130)) goto LAB_004168ac;
    }
    LVar2 = SendMessageA(*(HWND *)((int)this + 0x1c),0x365,0,(uVar3 - 0xf000 >> 4) + 0x1ef00);
    if (LVar2 == 0) {
      SendMessageA(*(HWND *)((int)this + 0x1c),0x111,0xe147,0);
    }
  }
  return;
}



/* VA 00416917 */

void __thiscall FUN_00416917(void *this,HDROP param_1)

{
  int iVar1;
  UINT iFile;
  CHAR local_110 [260];
  code *local_c;
  UINT local_8;

  SetActiveWindow(*(HWND *)((int)this + 0x1c));
  FUN_0040b6dd();
  iFile = 0;
  local_8 = DragQueryFileA(param_1,0xffffffff,(LPSTR)0x0,0);
  iVar1 = FUN_00419dc2();
  if (local_8 != 0) {
    local_c = *(code **)(**(int **)(iVar1 + 4) + 0x84);
    do {
      DragQueryFileA(param_1,iFile,local_110,0x104);
      (*local_c)(local_110);
      iFile = iFile + 1;
    } while (iFile < local_8);
  }
  DragFinish(param_1);
  return;
}



/* VA 00416992 */

undefined4 __fastcall FUN_00416992(int param_1)

{
  int iVar1;
  undefined4 uVar2;

  iVar1 = FUN_00419dc2();
  if ((*(int **)(iVar1 + 4))[7] == param_1) {
    uVar2 = (**(code **)(**(int **)(iVar1 + 4) + 0x90))();
    return uVar2;
  }
  return 1;
}



/* VA 004169b3 */

void __thiscall FUN_004169b3(void *this,int param_1)

{
  int *this_00;
  int iVar1;

  iVar1 = FUN_00419dc2();
  this_00 = *(int **)(iVar1 + 4);
  if ((param_1 != 0) && ((void *)this_00[7] == this)) {
    FUN_00417aac(1);
    FUN_00412928(this_00,1);
    (**(code **)(*this_00 + 0x70))();
  }
  return;
}



/* VA 004169e7 */

undefined4 FUN_004169e7(HWND param_1,undefined4 param_2)

{
  int iVar1;
  short sVar2;
  CHAR local_10c [260];
  int local_8;

  iVar1 = FUN_00419dc2();
  iVar1 = *(int *)(iVar1 + 4);
  if (((((ATOM)param_2 != 0) && (sVar2 = (short)((uint)param_2 >> 0x10), sVar2 != 0)) &&
      ((ATOM)param_2 == *(ATOM *)(iVar1 + 0xb0))) && (sVar2 == *(short *)(iVar1 + 0xb2))) {
    GlobalGetAtomNameA(*(ATOM *)(iVar1 + 0xb0),local_10c,0x103);
    GlobalAddAtomA(local_10c);
    GlobalGetAtomNameA(*(ATOM *)(iVar1 + 0xb2),local_10c,0x103);
    GlobalAddAtomA(local_10c);
    SendMessageA(param_1,0x3e4,*(WPARAM *)(local_8 + 0x1c),*(LPARAM *)(iVar1 + 0xb0));
  }
  return 0;
}



/* VA 00416aa2 */

undefined4 __thiscall FUN_00416aa2(void *this,HWND param_1,LPARAM param_2)

{
  LPCSTR lpString2;
  LPARAM lParam;
  int iVar1;
  CHAR local_214 [520];
  uint local_c;
  HGLOBAL local_8;

  UnpackDDElParam(1000,param_2,&local_c,(PUINT_PTR)&local_8);
  lpString2 = GlobalLock(local_8);
  lstrcpynA(local_214,lpString2,0x208);
  GlobalUnlock(local_8);
  lParam = ReuseDDElParam(param_2,1000,0x3e4,0x8000,(UINT_PTR)local_8);
  PostMessageA(param_1,0x3e4,*(WPARAM *)((int)this + 0x1c),lParam);
  iVar1 = FUN_0040ecb6((int)this);
  if (iVar1 != 0) {
    iVar1 = FUN_00419dc2();
    (**(code **)(**(int **)(iVar1 + 4) + 0x9c))(local_214);
  }
  return 0;
}



/* VA 00416b58 */

undefined4 __fastcall FUN_00416b58(int param_1)

{
  return *(undefined4 *)(param_1 + 0x98);
}



/* VA 00416b5f */

/* Library Function - Single Match
    public: void __thiscall CFrameWnd::SetActiveView(class CView *,int)

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

void __thiscall CFrameWnd::SetActiveView(CFrameWnd *this,CView *param_1,int param_2)

{
  CView *pCVar1;

  pCVar1 = *(CView **)(this + 0x98);
  if (param_1 != pCVar1) {
    *(undefined4 *)(this + 0x98) = 0;
    if (pCVar1 != (CView *)0x0) {
      (**(code **)(*(int *)pCVar1 + 0xec))(0,param_1,pCVar1);
    }
    if (((*(int *)(this + 0x98) == 0) &&
        (*(CView **)(this + 0x98) = param_1, param_1 != (CView *)0x0)) && (param_2 != 0)) {
      (**(code **)(*(int *)param_1 + 0xec))(1,param_1,pCVar1);
    }
  }
  return;
}



/* VA 00416be4 */

void FUN_00416be4(int *param_1,int param_2,int param_3)

{
  CWnd *this;
  int iVar1;
  uint uVar2;

  this = FUN_00417a08((int)param_1);
  if (param_3 == 0) {
    FUN_0040ec40(param_1,0,0,0,0,0,(-(uint)(param_2 != 0) & 0xffffffc0) + 0x80 | 0x17);
    (**(code **)(*param_1 + 0xcc))(param_2);
    if ((param_2 != 0) || (iVar1 = FUN_00417a19(param_1), iVar1 == 0)) {
      (**(code **)(*(int *)this + 0xd0))(0);
    }
  }
  else {
    (**(code **)(*param_1 + 0xcc))(param_2);
    *(uint *)(this + 0xb8) = *(uint *)(this + 0xb8) | 0xc;
  }
  iVar1 = FUN_00417a19(param_1);
  if (iVar1 == 0) {
    return;
  }
  if ((int *)param_1[0x1c] == (int *)0x0) {
    uVar2 = (uint)(param_2 != 0);
  }
  else {
    uVar2 = (**(code **)(*(int *)param_1[0x1c] + 0xe8))();
  }
  if ((uVar2 == 1) && (param_2 != 0)) {
    *(undefined4 *)(this + 0x88) = 0xffffffff;
    if (param_3 == 0) {
      iVar1 = 8;
LAB_00416cbf:
      FUN_0040ec8f(this,iVar1);
      return;
    }
    *(undefined4 *)(this + 0x88) = 8;
  }
  else {
    if (uVar2 == 0) {
      *(undefined4 *)(this + 0x88) = 0xffffffff;
      if (param_3 != 0) {
        *(undefined4 *)(this + 0x88) = 0;
        return;
      }
      iVar1 = 0;
      goto LAB_00416cbf;
    }
    if (param_3 != 0) {
      return;
    }
  }
  (**(code **)(*(int *)this + 0xd0))(0);
  return;
}



/* VA 00416cdf */

void __thiscall FUN_00416cdf(void *this,int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  HMENU pHVar2;
  HMENU pHVar3;
  uint uVar4;
  UINT UVar5;
  int nPos;
  CCmdUI local_30 [4];
  UINT local_2c;
  uint local_28;
  int local_24;
  int local_20;
  uint local_10;
  int local_c;
  int *local_8;

  local_8 = this;
  FUN_0041169c(*(HWND *)((int)this + 0x1c));
  if (param_3 == 0) {
    CCmdUI::CCmdUI(local_30);
    local_24 = param_1;
    iVar1 = FUN_00419a6f();
    if (*(int *)(iVar1 + 0x54) == *(int *)(param_1 + 4)) {
      local_c = param_1;
    }
    else {
      pHVar2 = GetMenu(*(HWND *)((int)this + 0x1c));
      if (((pHVar2 != (HMENU)0x0) && (iVar1 = FUN_0040cd3c((int)this), iVar1 != 0)) &&
         (pHVar2 = GetMenu(*(HWND *)(iVar1 + 0x1c)), pHVar2 != (HMENU)0x0)) {
        iVar1 = GetMenuItemCount(pHVar2);
        nPos = 0;
        if (0 < iVar1) {
          do {
            pHVar3 = GetSubMenu(pHVar2,nPos);
            if (pHVar3 == *(HMENU *)(param_1 + 4)) {
              local_c = FUN_0040fb75();
              break;
            }
            nPos = nPos + 1;
          } while (nPos < iVar1);
        }
      }
    }
    local_10 = GetMenuItemCount(*(HMENU *)(param_1 + 4));
    local_28 = 0;
    if (local_10 != 0) {
      do {
        local_2c = GetMenuItemID(*(HMENU *)(param_1 + 4),local_28);
        uVar4 = local_10;
        if (local_2c != 0) {
          if (local_2c == 0xffffffff) {
            GetSubMenu(*(HMENU *)(param_1 + 4),local_28);
            local_20 = FUN_0040fb75();
            uVar4 = local_10;
            if (((local_20 == 0) ||
                (local_2c = GetMenuItemID(*(HMENU *)(local_20 + 4),0), uVar4 = local_10,
                local_2c == 0)) || (local_2c == 0xffffffff)) goto LAB_00416e2e;
            iVar1 = 0;
          }
          else {
            local_20 = 0;
            if ((local_8[0xf] == 0) || (0xefff < local_2c)) {
              iVar1 = 0;
            }
            else {
              iVar1 = 1;
            }
          }
          FUN_0040f2c5(local_30,local_8,iVar1);
          uVar4 = GetMenuItemCount(*(HMENU *)(param_1 + 4));
          if (uVar4 < local_10) {
            local_28 = local_28 + (uVar4 - local_10);
            while ((local_28 < uVar4 &&
                   (UVar5 = GetMenuItemID(*(HMENU *)(param_1 + 4),local_28), UVar5 == local_2c))) {
              local_28 = local_28 + 1;
            }
          }
        }
LAB_00416e2e:
        local_10 = uVar4;
        local_28 = local_28 + 1;
      } while (local_28 < local_10);
    }
  }
  return;
}



/* VA 00416e44 */

void __thiscall FUN_00416e44(void *this,uint param_1,uint param_2)

{
  CWnd *pCVar1;
  int iVar2;

  pCVar1 = FUN_0040ce20(this);
  if (param_2 == 0xffff) {
    *(uint *)((int)this + 0x24) = *(uint *)((int)this + 0x24) & 0xffffffbf;
    if (*(int *)(pCVar1 + 0x50) == 0) {
      *(undefined4 *)((int)this + 0x90) = 0xe001;
    }
    else {
      *(undefined4 *)((int)this + 0x90) = 0xe002;
    }
    SendMessageA(*(HWND *)((int)this + 0x1c),0x362,*(WPARAM *)((int)this + 0x90),0);
    iVar2 = (**(code **)(*(int *)this + 0xdc))();
    if (iVar2 != 0) {
      UpdateWindow(*(HWND *)(iVar2 + 0x1c));
    }
    goto LAB_00416efc;
  }
  if ((param_1 == 0) || ((param_2 & 0x810) != 0)) {
    *(undefined4 *)((int)this + 0x90) = 0;
  }
  else {
    if ((param_1 < 0xf000) || (0xf1ef < param_1)) {
      if (0xfeff < param_1) {
        *(undefined4 *)((int)this + 0x90) = 0xef1f;
        goto LAB_00416ef8;
      }
    }
    else {
      param_1 = (param_1 - 0xf000 >> 4) + 0xef00;
    }
    *(uint *)((int)this + 0x90) = param_1;
  }
LAB_00416ef8:
  *(uint *)(pCVar1 + 0x24) = *(uint *)(pCVar1 + 0x24) | 0x40;
LAB_00416efc:
  if (*(int *)((int)this + 0x90) != *(int *)((int)this + 0x94)) {
    GetParent(*(HWND *)((int)this + 0x1c));
    pCVar1 = FUN_0040b6dd();
    if (pCVar1 != (CWnd *)0x0) {
      PostMessageA(*(HWND *)((int)this + 0x1c),0x36a,0,0);
    }
  }
  return;
}



/* VA 00416f9a */

undefined4 FUN_00416f9a(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  CWnd *pCVar5;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  iVar1 = *extraout_ECX;
  extraout_ECX[9] = extraout_ECX[9] & 0xffffffbf;
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX[0x25];
  iVar4 = (**(code **)(iVar1 + 0xdc))();
  *(int *)(unaff_EBP + -0x18) = iVar4;
  if (iVar4 == 0) {
    iVar4 = *(int *)(unaff_EBP + 8);
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    FUN_0040fe73((undefined4 *)(unaff_EBP + -0x14));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (*(int *)(unaff_EBP + 0xc) == 0) {
      iVar4 = *(int *)(unaff_EBP + 8);
      if (iVar4 != 0) {
        if ((iVar4 == 0xef06) && (extraout_ECX[0x27] != 0)) {
          iVar4 = 0xf005;
        }
        (**(code **)(iVar1 + 0xcc))(iVar4,unaff_EBP + -0x14);
        *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x14);
      }
    }
    else {
      iVar4 = *(int *)(unaff_EBP + 8);
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + 0xc);
    }
    FUN_0040ebea(*(void **)(unaff_EBP + -0x18),*(LPCSTR *)(unaff_EBP + -0x10));
    pCVar5 = FUN_0040ccb3(*(int *)(unaff_EBP + -0x18));
    if (pCVar5 != (CWnd *)0x0) {
      *(int *)(pCVar5 + 0x94) = iVar4;
      *(int *)(pCVar5 + 0x90) = iVar4;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0040ff87((int *)(unaff_EBP + -0x14));
  }
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  uVar3 = *(undefined4 *)(unaff_EBP + -0x1c);
  extraout_ECX[0x25] = iVar4;
  extraout_ECX[0x24] = iVar4;
  *unaff_FS_OFFSET = uVar2;
  return uVar3;
}



/* VA 0041707f */

void __thiscall FUN_0041707f(void *this,int param_1)

{
  FUN_0040d993(this);
  if ((param_1 == 2) && (*(WPARAM *)((int)this + 0x90) != *(WPARAM *)((int)this + 0x94))) {
    FUN_004170b0(this,*(WPARAM *)((int)this + 0x90));
  }
  return;
}



/* VA 004170b0 */

void __thiscall FUN_004170b0(void *this,WPARAM param_1)

{
  SendMessageA(*(HWND *)((int)this + 0x1c),0x362,param_1,0);
  return;
}



/* VA 004170c7 */

void FUN_004170c7(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  CWnd *pCVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar5;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  FUN_0040a8e8((void *)(unaff_EBP + -0x28),10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar5 = *(undefined4 **)(extraout_ECX + 0x70);
  while (puVar5 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar5;
    piVar2 = (int *)puVar5[2];
    iVar3 = (**(code **)(*piVar2 + 0xd8))();
    puVar5 = puVar1;
    if (iVar3 != 0) {
      AddTail((void *)(unaff_EBP + -0x28),piVar2);
    }
  }
  puVar5 = *(undefined4 **)(unaff_EBP + -0x24);
  while (puVar5 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar5;
    piVar2 = (int *)puVar5[2];
    puVar5 = puVar1;
    if (piVar2[0x1e] == 0) {
      (**(code **)(*piVar2 + 0x60))();
    }
    else {
      pCVar4 = FUN_0040ccb3((int)piVar2);
      (**(code **)(*(int *)pCVar4 + 0x60))();
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0040a947();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00417150 */

int __thiscall FUN_00417150(void *this,uint param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;

  if (param_1 == 0) {
LAB_0041717d:
    iVar3 = 0;
  }
  else {
    puVar4 = *(undefined4 **)((int)this + 0x70);
    do {
      if (puVar4 == (undefined4 *)0x0) goto LAB_0041717d;
      puVar1 = (undefined4 *)*puVar4;
      iVar3 = puVar4[2];
      uVar2 = GetDlgCtrlID(*(HWND *)(iVar3 + 0x1c));
      puVar4 = puVar1;
    } while ((uVar2 & 0xffff) != param_1);
  }
  return iVar3;
}



/* VA 00417184 */

void __thiscall FUN_00417184(void *this,int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;

  iVar2 = FUN_00417150(this,param_1[1]);
  if (iVar2 == 0) {
    param_1[7] = 1;
  }
  else {
    iVar1 = *param_1;
    uVar3 = FUN_0040eb4e(iVar2);
    (**(code **)(iVar1 + 4))(uVar3 >> 0x1c & 1);
  }
  return;
}



/* VA 004171f2 */

undefined4 FUN_004171f2(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  HWND hWnd;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  iVar2 = FUN_0040f0f9();
  if (iVar2 == 0) {
    FUN_0040fe73((undefined4 *)(unaff_EBP + -0x10));
    puVar1 = *(undefined4 **)(unaff_EBP + 0xc);
    iVar2 = puVar1[2];
    hWnd = (HWND)puVar1[1];
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (((iVar2 == -0x208) && ((*(byte *)(puVar1 + 0x19) & 1) != 0)) ||
       ((iVar2 == -0x212 && ((*(byte *)(puVar1 + 0x2d) & 1) != 0)))) {
      uVar4 = GetDlgCtrlID(hWnd);
      hWnd = (HWND)(uVar4 & 0xffff);
    }
    if (hWnd != (HWND)0x0) {
      FUN_0040fa52((UINT)hWnd,(LPSTR)(unaff_EBP + -0x110),0x100);
      FUN_0040fa79((int *)(unaff_EBP + -0x10),(byte *)(unaff_EBP + -0x110),1,'\n');
    }
    if (puVar1[2] == -0x208) {
      lstrcpynA((LPSTR)(puVar1 + 4),*(LPCSTR *)(unaff_EBP + -0x10),0x50);
    }
    else {
      FUN_0041009b((LPWSTR)(puVar1 + 4),*(LPCSTR *)(unaff_EBP + -0x10),0x50);
    }
    **(undefined4 **)(unaff_EBP + 0x10) = 0;
    SetWindowPos((HWND)*puVar1,(HWND)0x0,0,0,0,0,0x213);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0040ff87((int *)(unaff_EBP + -0x10));
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar3;
}



/* VA 00417334 */

void __thiscall FUN_00417334(void *this,int *param_1)

{
  void *pvVar1;

  pvVar1 = (void *)FUN_00401858();
  if (pvVar1 == this) {
    (**(code **)(*param_1 + 4))(*(int *)((int)this + 0x50) != 0);
  }
  else {
    param_1[7] = 1;
  }
  return;
}



/* VA 00417363 */

/* Library Function - Single Match
    public: virtual void __thiscall CFrameWnd::OnUpdateFrameTitle(int)

   Library: Visual Studio 1998 Release */

void __thiscall CFrameWnd::OnUpdateFrameTitle(CFrameWnd *this,int param_1)

{
  uint uVar1;
  int iVar2;
  LPCSTR pCVar3;

  uVar1 = FUN_0040eb4e((int)this);
  if ((uVar1 & 0x8000) != 0) {
    if ((*(int **)(this + 0x68) != (int *)0x0) &&
       (iVar2 = (**(code **)(**(int **)(this + 0x68) + 0x70))(), iVar2 != 0)) {
      return;
    }
    iVar2 = (**(code **)(*(int *)this + 0xc4))();
    if ((param_1 == 0) || (iVar2 == 0)) {
      pCVar3 = (LPCSTR)0x0;
    }
    else {
      pCVar3 = *(LPCSTR *)(iVar2 + 0x1c);
    }
    FUN_004173a7(this,pCVar3);
  }
  return;
}



/* VA 004173a7 */

void __thiscall FUN_004173a7(void *this,LPCSTR param_1)

{
  uint uVar1;
  int iVar2;
  LPCSTR pCVar3;
  int iVar4;
  CHAR local_208 [516];

  uVar1 = FUN_0040eb4e((int)this);
  if ((uVar1 & 0x4000) == 0) {
    lstrcpyA(local_208,*(LPCSTR *)((int)this + 0xac));
    if (param_1 != (LPCSTR)0x0) {
      lstrcatA(local_208," - ");
      lstrcatA(local_208,param_1);
      iVar4 = *(int *)((int)this + 0x40);
      if (0 < iVar4) {
        pCVar3 = ":%d";
        iVar2 = lstrlenA(local_208);
        wsprintfA(local_208 + iVar2,pCVar3,iVar4);
      }
    }
  }
  else {
    local_208[0] = '\0';
    if (param_1 != (LPCSTR)0x0) {
      lstrcpyA(local_208,param_1);
      iVar4 = *(int *)((int)this + 0x40);
      if (0 < iVar4) {
        pCVar3 = ":%d";
        iVar2 = lstrlenA(local_208);
        wsprintfA(local_208 + iVar2,pCVar3,iVar4);
      }
      lstrcatA(local_208," - ");
    }
    lstrcatA(local_208,*(LPCSTR *)((int)this + 0xac));
  }
  FUN_0041162b(*(HWND *)((int)this + 0x1c),local_208);
  return;
}



/* VA 004174a4 */

void __thiscall FUN_004174a4(void *this,int param_1,int *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  HWND pHVar8;
  HMENU pHVar9;
  HWND hWnd;
  HWND unaff_retaddr;
  uint uStack_c;

  iVar4 = (**(code **)(*(int *)this + 200))();
  if ((param_1 != 0) && (*(int **)(iVar4 + 0x68) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar4 + 0x68) + 100))(0);
  }
  uStack_c = 0;
  puVar3 = *(undefined4 **)((int)this + 0x70);
  while (puVar3 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar3;
    piVar2 = (int *)puVar3[2];
    uVar5 = GetDlgCtrlID((HWND)piVar2[7]);
    uVar5 = uVar5 & 0xffff;
    puVar3 = puVar1;
    if ((0xe7ff < uVar5) && (uVar5 < 0xe820)) {
      uVar6 = 1 << ((byte)uVar5 & 0x1f);
      iVar7 = (**(code **)(*piVar2 + 0xd0))();
      if (iVar7 != 0) {
        uStack_c = uStack_c | uVar6;
      }
      iVar7 = (**(code **)(*piVar2 + 0xd8))();
      if ((iVar7 == 0) || (uVar5 != 0xe81f)) {
        FUN_00416be4(piVar2,param_2[2] & uVar6,1);
      }
    }
  }
  param_2[2] = uStack_c;
  if (param_1 == 0) {
    *(undefined4 *)((int)this + 0x9c) = 0;
    pHVar8 = GetDlgItem(*(HWND *)((int)this + 0x1c),0xea21);
    if (pHVar8 != (HWND)0x0) {
      hWnd = GetDlgItem(*(HWND *)((int)this + 0x1c),0xe900);
      if (hWnd != (HWND)0x0) {
        SetWindowLongA(hWnd,-0xc,0xea21);
      }
      SetWindowLongA(pHVar8,-0xc,0xe900);
    }
    if (param_2[1] != 0) {
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,1);
      SetMenu(*(HWND *)((int)this + 0x1c),(HMENU)param_2[1]);
    }
    if (*(int **)(iVar4 + 0x68) != (int *)0x0) {
      (**(code **)(**(int **)(iVar4 + 0x68) + 100))(1);
    }
    (**(code **)(*(int *)this + 0xd0))(1);
    if (*param_2 != 0xe900) {
      unaff_retaddr = GetDlgItem(*(HWND *)((int)this + 0x1c),*param_2);
    }
    ShowWindow(unaff_retaddr,5);
    *(int *)((int)this + 0x48) = param_2[5];
    FUN_00415f28(this,1);
  }
  else {
    *(int *)((int)this + 0x9c) = param_2[4];
    FUN_00415f28(this,0);
    pHVar8 = GetDlgItem(*(HWND *)((int)this + 0x1c),*param_2);
    ShowWindow(pHVar8,0);
    pHVar9 = GetMenu(*(HWND *)((int)this + 0x1c));
    param_2[1] = (int)pHVar9;
    if (pHVar9 != (HMENU)0x0) {
      InvalidateRect(*(HWND *)((int)this + 0x1c),(RECT *)0x0,1);
      SetMenu(*(HWND *)((int)this + 0x1c),(HMENU)0x0);
      *(uint *)((int)this + 0xb8) = *(uint *)((int)this + 0xb8) & 0xfffffffe;
    }
    param_2[5] = *(int *)((int)this + 0x48);
    *(undefined4 *)((int)this + 0x48) = 0;
    FUN_00415aec(this,(LPCSTR)0x7915);
    if (*param_2 != 0xe900) {
      pHVar8 = GetDlgItem(*(HWND *)((int)this + 0x1c),0xe900);
    }
    if (pHVar8 != (HWND)0x0) {
      SetWindowLongA(pHVar8,-0xc,0xea21);
    }
  }
  return;
}



/* VA 004176d3 */

void __fastcall FUN_004176d3(int *param_1)

{
  if ((*(byte *)(param_1 + 0x2e) & 1) != 0) {
    (**(code **)(*param_1 + 0xec))(param_1[0x2a]);
  }
  if ((*(byte *)(param_1 + 0x2e) & 2) != 0) {
    (**(code **)(*param_1 + 0xe8))(1);
  }
  if ((param_1[0x2e] & 8U) != 0) {
    (**(code **)(*param_1 + 0xd0))(param_1[0x2e] & 4);
    UpdateWindow((HWND)param_1[7]);
  }
  if (param_1[0x24] != param_1[0x25]) {
    FUN_004170b0(param_1,param_1[0x24]);
  }
  param_1[0x2e] = 0;
  return;
}



/* VA 00417745 */

void __thiscall FUN_00417745(void *this,int param_1)

{
  uint uVar1;
  tagRECT local_14;

  if (*(int *)((int)this + 0xb0) == 0) {
    *(undefined4 *)((int)this + 0xb0) = 1;
    if ((*(uint *)((int)this + 0xb8) & 4) != 0) {
      param_1 = 1;
    }
    *(uint *)((int)this + 0xb8) = *(uint *)((int)this + 0xb8) & 0xfffffff3;
    if ((param_1 != 0) && (*(int **)((int)this + 0x68) != (int *)0x0)) {
      (**(code **)(**(int **)((int)this + 0x68) + 0x58))();
    }
    uVar1 = FUN_0040eb4e((int)this);
    if ((uVar1 & 0x2000) == 0) {
      FUN_0040d1d7(this,0,0xffff,0xe900,2,(LPRECT)((int)this + 0x58),(int *)0x0,1);
    }
    else {
      local_14.right = 0x7fff;
      local_14.bottom = 0x7fff;
      local_14.left = 0;
      local_14.top = 0;
      FUN_0040d1d7(this,0,0xffff,0xe900,1,&local_14,&local_14.left,0);
      FUN_0040d1d7(this,0,0xffff,0xe900,2,(LPRECT)((int)this + 0x58),&local_14.left,1);
      (**(code **)(*(int *)this + 0x68))(&local_14,0);
      FUN_0040ec40(this,0,0,0,local_14.right - local_14.left,local_14.bottom - local_14.top,0x16);
    }
    *(undefined4 *)((int)this + 0xb0) = 0;
  }
  return;
}



/* VA 00417832 */

undefined4 __thiscall FUN_00417832(void *this,int param_1,RECT *param_2)

{
  BOOL BVar1;

  if (param_1 == 1) {
    FUN_0040d1d7(this,0,0xffff,0xe900,1,param_2,(int *)0x0,1);
  }
  else if ((param_1 != 2) && (param_1 == 3)) {
    if (param_2 == (RECT *)0x0) {
      if ((((*(int *)((int)this + 0x58) == 0) && (*(int *)((int)this + 0x60) == 0)) &&
          (*(int *)((int)this + 0x5c) == 0)) && (*(int *)((int)this + 100) == 0)) {
        return 0;
      }
      SetRectEmpty((LPRECT)((int)this + 0x58));
    }
    else {
      BVar1 = EqualRect((RECT *)((int)this + 0x58),param_2);
      if (BVar1 != 0) {
        return 0;
      }
      CopyRect((RECT *)((int)this + 0x58),param_2);
    }
  }
  return 1;
}



/* VA 004178ac */

void __thiscall FUN_004178ac(void *this,int param_1)

{
  FUN_0040b632(this);
  if (param_1 != 1) {
    (**(code **)(*(int *)this + 0xd0))(1);
  }
  return;
}



/* VA 004178e1 */

LRESULT __thiscall FUN_004178e1(void *this,int param_1,LRESULT param_2)

{
  SHORT SVar1;
  uint uVar2;
  HWND hWnd;
  HWND pHVar3;
  LRESULT LVar4;
  uint uVar5;

  SVar1 = GetKeyState(0x11);
  if (SVar1 < 0) {
    uVar5 = 8;
  }
  else {
    uVar5 = 0;
  }
  SVar1 = GetKeyState(0x10);
  if (SVar1 < 0) {
    uVar2 = 4;
  }
  else {
    uVar2 = 0;
  }
  hWnd = GetFocus();
  pHVar3 = GetDesktopWindow();
  if (hWnd == (HWND)0x0) {
    param_2 = SendMessageA(*(HWND *)((int)this + 0x1c),0x20a,param_1 << 0x10 | uVar5 | uVar2,param_2
                          );
  }
  else {
    LVar4 = param_2;
    do {
      param_2 = LVar4;
      LVar4 = SendMessageA(hWnd,0x20a,param_1 << 0x10 | uVar5 | uVar2,param_2);
      hWnd = GetParent(hWnd);
      if (LVar4 != 0) {
        return LVar4;
      }
      if (hWnd == (HWND)0x0) {
        return 0;
      }
      param_2 = 0;
      LVar4 = 0;
    } while (hWnd != pHVar3);
  }
  return param_2;
}



/* VA 004179d9 */

/* Library Function - Single Match
    protected: void __thiscall CFrameWnd::BringToTop(int)

   Libraries: Visual Studio 1998 Release, Visual Studio 2003 Release */

void __thiscall CFrameWnd::BringToTop(CFrameWnd *this,int param_1)

{
  HWND hWnd;

  if ((((param_1 != 0) && (param_1 != 6)) && (param_1 != 7)) && ((param_1 != 8 && (param_1 != 4))))
  {
    hWnd = GetLastActivePopup(*(HWND *)(this + 0x1c));
    BringWindowToTop(hWnd);
  }
  return;
}



/* VA 00417a08 */

CWnd * __fastcall FUN_00417a08(int param_1)

{
  CWnd *pCVar1;

  pCVar1 = FUN_0040ccb3(param_1);
  if (pCVar1 == (CWnd *)0x0) {
    pCVar1 = *(CWnd **)(param_1 + 0x6c);
  }
  return pCVar1;
}



/* VA 00417a19 */

int __fastcall FUN_00417a19(int *param_1)

{
  int iVar1;

  iVar1 = (**(code **)(*param_1 + 0xd8))();
  if (iVar1 != 0) {
    return param_1[0x1e];
  }
  if ((param_1[0x1c] != 0) && (*(int *)(param_1[0x1c] + 0x78) != 0)) {
    return 1;
  }
  return 0;
}



/* VA 00417a43 */

void __thiscall
FUN_00417a43(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(*(int *)this + 0x5c))(&DAT_0041d2b4,0,param_1,param_2,param_3,param_4,0);
  return;
}



/* VA 00417a64 */

/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall CAnimateCtrl::~CAnimateCtrl(void)
    public: virtual __thiscall CButton::~CButton(void)
    public: virtual __thiscall CComboBox::~CComboBox(void)
    public: virtual __thiscall CDateTimeCtrl::~CDateTimeCtrl(void)
     21 names - too many to list

   Library: Visual Studio 2003 Release */

void FID_conflict__CHotKeyCtrl(void)

{
  CWnd *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(CWnd **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_LAB_0041d2c4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040bf81((int)this);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWnd::~CWnd(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00417a9c */

bool FUN_00417a9c(void)

{
  int iVar1;

  iVar1 = FUN_00419dc2();
  return *(int *)(iVar1 + 0x2c) == 0;
}



/* VA 00417aac */

void FUN_00417aac(undefined4 param_1)

{
  int iVar1;

  iVar1 = FUN_00419dc2();
  *(undefined4 *)(iVar1 + 0x30) = param_1;
  return;
}



/* VA 00417abb */

undefined4 FUN_00417abb(void)

{
  int iVar1;

  iVar1 = FUN_00419dc2();
  return *(undefined4 *)(iVar1 + 0x30);
}



/* VA 00417ace */

void FUN_00417ace(void)

{
  return;
}



/* VA 00417acf */

void FUN_00417acf(void)

{
  FUN_00402fb0(0x417adb);
  return;
}



/* VA 00417ae6 */

void FUN_00417ae6(void)

{
  byte bVar1;
  undefined2 *puVar2;
  HBITMAP hbm;
  int iVar3;
  undefined2 local_14 [8];

  FUN_0041adc3(8);
  if (DAT_00428ba4 == (HBRUSH)0x0) {
    iVar3 = 0;
    puVar2 = local_14;
    do {
      bVar1 = (byte)iVar3;
      iVar3 = iVar3 + 1;
      *puVar2 = (short)(0x5555 << (bVar1 & 1));
      puVar2 = puVar2 + 1;
    } while (iVar3 < 8);
    hbm = CreateBitmap(8,8,1,1,local_14);
    if (hbm != (HBITMAP)0x0) {
      DAT_00428ba4 = CreatePatternBrush(hbm);
      DeleteObject(hbm);
    }
  }
  FUN_0041ae33(8);
  FUN_00411418();
  return;
}



/* VA 00417b59 */

void FUN_00417b59(void)

{
  RECT *lprcSrc;
  HRGN pHVar1;
  undefined4 uVar2;
  int iVar3;
  int *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  FUN_0040275e((undefined4 *)(unaff_EBP + -0x34));
  *(undefined ***)(unaff_EBP + -0x34) = &PTR_LAB_0041e5cc;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040275e((undefined4 *)(unaff_EBP + -0x1c));
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_LAB_0041e5cc;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0040275e((undefined4 *)(unaff_EBP + -0x14));
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_0041e5cc;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pHVar1 = CreateRectRgnIndirect(*(RECT **)(unaff_EBP + 8));
  FUN_0041142e((void *)(unaff_EBP + -0x1c),(uint)pHVar1);
  CopyRect((LPRECT)(unaff_EBP + -0x44),*(RECT **)(unaff_EBP + 8));
  InflateRect((LPRECT)(unaff_EBP + -0x44),-*(int *)(unaff_EBP + 0xc),-*(int *)(unaff_EBP + 0x10));
  IntersectRect((LPRECT)(unaff_EBP + -0x44),(RECT *)(unaff_EBP + -0x44),*(RECT **)(unaff_EBP + 8));
  pHVar1 = CreateRectRgnIndirect((RECT *)(unaff_EBP + -0x44));
  FUN_0041142e((void *)(unaff_EBP + -0x14),(uint)pHVar1);
  pHVar1 = CreateRectRgn(0,0,0,0);
  FUN_0041142e((void *)(unaff_EBP + -0x34),(uint)pHVar1);
  CombineRgn(*(HRGN *)(unaff_EBP + -0x30),
             (HRGN)(-(uint)(unaff_EBP != 0x1c) & *(uint *)(unaff_EBP + -0x18)),
             (HRGN)(-(uint)(unaff_EBP != 0x14) & *(uint *)(unaff_EBP + -0x10)),3);
  if (*(int *)(unaff_EBP + 0x20) == 0) {
    uVar2 = FUN_00417ae6();
    *(undefined4 *)(unaff_EBP + 0x20) = uVar2;
  }
  if (*(int *)(unaff_EBP + 0x24) == 0) {
    *(undefined4 *)(unaff_EBP + 0x24) = *(undefined4 *)(unaff_EBP + 0x20);
  }
  FUN_0040275e((undefined4 *)(unaff_EBP + -0x24));
  *(undefined ***)(unaff_EBP + -0x24) = &PTR_LAB_0041e5cc;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_0040275e((undefined4 *)(unaff_EBP + -0x2c));
  *(undefined ***)(unaff_EBP + -0x2c) = &PTR_LAB_0041e5cc;
  lprcSrc = *(RECT **)(unaff_EBP + 0x14);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  if (lprcSrc != (RECT *)0x0) {
    pHVar1 = CreateRectRgn(0,0,0,0);
    FUN_0041142e((void *)(unaff_EBP + -0x24),(uint)pHVar1);
    SetRectRgn(*(HRGN *)(unaff_EBP + -0x18),lprcSrc->left,lprcSrc->top,lprcSrc->right,
               lprcSrc->bottom);
    CopyRect((LPRECT)(unaff_EBP + -0x44),lprcSrc);
    InflateRect((LPRECT)(unaff_EBP + -0x44),-*(int *)(unaff_EBP + 0x18),-*(int *)(unaff_EBP + 0x1c))
    ;
    IntersectRect((LPRECT)(unaff_EBP + -0x44),(RECT *)(unaff_EBP + -0x44),lprcSrc);
    SetRectRgn(*(HRGN *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + -0x44),*(int *)(unaff_EBP + -0x40),
               *(int *)(unaff_EBP + -0x3c),*(int *)(unaff_EBP + -0x38));
    CombineRgn(*(HRGN *)(unaff_EBP + -0x20),
               (HRGN)(-(uint)(unaff_EBP != 0x1c) & *(uint *)(unaff_EBP + -0x18)),
               (HRGN)(-(uint)(unaff_EBP != 0x14) & *(uint *)(unaff_EBP + -0x10)),3);
    if (*(int *)(*(int *)(unaff_EBP + 0x20) + 4) == *(int *)(*(int *)(unaff_EBP + 0x24) + 4)) {
      pHVar1 = CreateRectRgn(0,0,0,0);
      FUN_0041142e((void *)(unaff_EBP + -0x2c),(uint)pHVar1);
      CombineRgn(*(HRGN *)(unaff_EBP + -0x28),
                 (HRGN)(-(uint)(unaff_EBP != 0x24) & *(uint *)(unaff_EBP + -0x20)),
                 (HRGN)(-(uint)(unaff_EBP != 0x34) & *(uint *)(unaff_EBP + -0x30)),3);
    }
  }
  if ((*(int *)(*(int *)(unaff_EBP + 0x20) + 4) != *(int *)(*(int *)(unaff_EBP + 0x24) + 4)) &&
     (lprcSrc != (RECT *)0x0)) {
    FUN_00411059(this,unaff_EBP + -0x24);
    (**(code **)(*this + 0x58))(unaff_EBP + -0x44);
    iVar3 = FUN_00410cc1(this,*(int *)(unaff_EBP + 0x24));
    PatBlt((HDC)this[1],*(int *)(unaff_EBP + -0x44),*(int *)(unaff_EBP + -0x40),
           *(int *)(unaff_EBP + -0x3c) - *(int *)(unaff_EBP + -0x44),
           *(int *)(unaff_EBP + -0x38) - *(int *)(unaff_EBP + -0x40),0x5a0049);
    FUN_00410cc1(this,iVar3);
  }
  iVar3 = unaff_EBP + -0x2c;
  if (*(int *)(unaff_EBP + -0x28) == 0) {
    iVar3 = unaff_EBP + -0x34;
  }
  FUN_00411059(this,iVar3);
  (**(code **)(*this + 0x58))(unaff_EBP + -0x44);
  iVar3 = FUN_00410cc1(this,*(int *)(unaff_EBP + 0x20));
  PatBlt((HDC)this[1],*(int *)(unaff_EBP + -0x44),*(int *)(unaff_EBP + -0x40),
         *(int *)(unaff_EBP + -0x3c) - *(int *)(unaff_EBP + -0x44),
         *(int *)(unaff_EBP + -0x38) - *(int *)(unaff_EBP + -0x40),0x5a0049);
  if (iVar3 != 0) {
    FUN_00410cc1(this,iVar3);
  }
  FUN_00411059(this,0);
  *(undefined ***)(unaff_EBP + -0x2c) = &PTR_LAB_0041d9ec;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_00411485(unaff_EBP + -0x2c);
  *(undefined ***)(unaff_EBP + -0x24) = &PTR_LAB_0041d9ec;
  *(undefined ***)(unaff_EBP + -0x2c) = &PTR_LAB_0041d1bc;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_00411485(unaff_EBP + -0x24);
  *(undefined ***)(unaff_EBP + -0x24) = &PTR_LAB_0041d1bc;
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_0041d9ec;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_00411485(unaff_EBP + -0x14);
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_0041d1bc;
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_LAB_0041d9ec;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_00411485(unaff_EBP + -0x1c);
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_LAB_0041d1bc;
  *(undefined ***)(unaff_EBP + -0x34) = &PTR_LAB_0041d9ec;
  *(undefined4 *)(unaff_EBP + -4) = 9;
  FUN_00411485(unaff_EBP + -0x34);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00417e6e */

void __thiscall
FUN_00417e6e(void *this,int param_1,int param_2,int param_3,int param_4,COLORREF param_5)

{
  RECT local_14;

  SetBkColor(*(HDC *)((int)this + 4),param_5);
  local_14.left = param_1;
  local_14.right = param_3 + param_1;
  local_14.bottom = param_4 + param_2;
  local_14.top = param_2;
  ExtTextOutA(*(HDC *)((int)this + 4),0,0,2,&local_14,(LPCSTR)0x0,0,(INT *)0x0);
  return;
}



/* VA 00417ec4 */

void FUN_00417ec4(void)

{
  return;
}



/* VA 00417ec5 */

void FUN_00417ec5(void)

{
  FUN_00402fb0(0x417ed1);
  return;
}



/* VA 00417eec */

undefined4 * FUN_00417eec(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0041595b();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040fe73(extraout_ECX + 0x32);
  extraout_ECX[0x31] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = &PTR_LAB_0041ef5c;
  FUN_00417f52();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}



/* VA 00417f36 */

undefined * __thiscall FUN_00417f36(void *this,byte param_1)

{
  FUN_004180ad();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 00417f52 */

void FUN_00417f52(void)

{
  HFONT h;
  int iVar1;
  BOOL BVar2;
  int unaff_EBP;
  HGDIOBJ h_00;
  undefined4 *unaff_FS_OFFSET;
  bool bVar3;
  char *lpString2;

  FUN_00402bc0();
  h_00 = (HGDIOBJ)0x0;
  if (DAT_0042884c != 0) goto LAB_004180a0;
  FUN_0041adc3(10);
  if (DAT_00428bb4 == (HBITMAP)0x0) {
    iVar1 = FUN_00419dc2();
    DAT_00428bb4 = LoadBitmapA(*(HINSTANCE *)(iVar1 + 0xc),(LPCSTR)0x7912);
    iVar1 = GetObjectA(DAT_00428bb4,0x18,(LPVOID)(unaff_EBP + -0x24));
    if (iVar1 != 0) {
      DAT_00428bc0 = *(undefined4 *)(unaff_EBP + -0x20);
      DAT_00428bc4 = *(int *)(unaff_EBP + -0x1c);
    }
  }
  if (DAT_00428bb0 == (HFONT)0x0) {
    _memset((void *)(unaff_EBP + -0x60),0,0x3c);
    *(undefined1 *)(unaff_EBP + -0x49) = 1;
    *(undefined4 *)(unaff_EBP + -0x50) = 400;
    *(int *)(unaff_EBP + -0x60) = 1 - DAT_00428bc4;
    iVar1 = GetSystemMetrics(0x2a);
    if (iVar1 == 0) {
      lpString2 = "Small Fonts";
    }
    else {
      lpString2 = "Terminal";
    }
    lstrcpyA((LPSTR)(unaff_EBP + -0x44),lpString2);
    iVar1 = FUN_004114c9(0xf233,(int *)(unaff_EBP + -0x60));
    if (iVar1 == 0) {
      *(undefined1 *)(unaff_EBP + -0x45) = 0x20;
    }
    DAT_00428bb0 = CreateFontIndirectA((LOGFONTA *)(unaff_EBP + -0x60));
    if (DAT_00428bb0 != (HFONT)0x0) goto LAB_00418033;
  }
  else {
LAB_00418033:
    FUN_00411173();
    h = DAT_00428bb0;
    bVar3 = DAT_00428bb0 != (HFONT)0x0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (bVar3) {
      h_00 = SelectObject(*(HDC *)(unaff_EBP + -0x1c),h);
    }
    BVar2 = GetTextMetricsA(*(HDC *)(unaff_EBP + -0x18),(LPTEXTMETRICA)(unaff_EBP + -0x5c));
    if (h_00 != (HGDIOBJ)0x0) {
      SelectObject(*(HDC *)(unaff_EBP + -0x1c),h_00);
    }
    if ((BVar2 == 0) || (DAT_00428bc4 < *(int *)(unaff_EBP + -0x5c) - *(int *)(unaff_EBP + -0x50)))
    {
      FUN_00411683(&DAT_00428bb0);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004111e5();
  }
  FUN_0041ae33(10);
LAB_004180a0:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 004180ad */

void FUN_004180ad(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041ef5c;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0040bf81((int)extraout_ECX);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0040ff87(extraout_ECX + 0x32);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00415a3d();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 004180f7 */

void __thiscall
FUN_004180f7(void *this,DWORD param_1,LPCSTR param_2,LPCSTR param_3,DWORD param_4,int *param_5,
            int param_6,HMENU param_7)

{
  HCURSOR pHVar1;
  HWND pHVar2;
  HBRUSH pHVar3;
  HICON pHVar4;

  FUN_0040ffdd((void *)((int)this + 200),param_3);
  pHVar2 = (HWND)0x0;
  if (param_2 == (LPCSTR)0x0) {
    pHVar4 = (HICON)0x0;
    pHVar3 = (HBRUSH)0x0;
    pHVar1 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    param_2 = FUN_0040c3b0(8,pHVar1,pHVar3,pHVar4);
  }
  if (param_6 != 0) {
    pHVar2 = *(HWND *)(param_6 + 0x1c);
  }
  FUN_0040bc7c(this,param_1,param_2,param_3,param_4,*param_5,param_5[1],param_5[2] - *param_5,
               param_5[3] - param_5[1],pHVar2,param_7,(LPVOID)0x0);
  return;
}



/* VA 00418232 */

void __thiscall FUN_00418232(void *this,int param_1)

{
  tagRECT local_24;
  tagRECT local_14;

  FUN_0040b632(this);
  GetWindowRect(*(HWND *)((int)this + 0x1c),&local_14);
  GetClientRect(*(HWND *)((int)this + 0x1c),&local_24);
  *(LONG *)(param_1 + 0x18) = (local_14.right - local_14.left) - local_24.right;
  *(LONG *)(param_1 + 0x1c) = (local_14.bottom - local_14.top) - local_24.bottom;
  return;
}



/* VA 0041827a */

undefined4 __thiscall FUN_0041827a(void *this,int param_1)

{
  uint uVar1;
  undefined4 uVar2;

  uVar1 = FUN_0040eb4e((int)this);
  if ((uVar1 & 0x100) == 0) {
    if (DAT_0042884c != 0) {
      uVar2 = FUN_0040b632(this);
      return uVar2;
    }
    if (*(int *)((int)this + 0xc4) != param_1) {
      *(int *)((int)this + 0xc4) = param_1;
      SendMessageA(*(HWND *)((int)this + 0x1c),0x85,0,0);
    }
  }
  else if ((*(byte *)((int)this + 0x25) & 2) != 0) {
    return 0;
  }
  return 1;
}



/* VA 004182cb */

void __thiscall FUN_004182cb(void *this,LPRECT param_1)

{
  uint uVar1;
  int iVar2;
  int nIndex;

  if (DAT_0042884c == 0) {
    uVar1 = FUN_0040eb4e((int)this);
    if ((uVar1 & 0x40600) == 0) {
      GetSystemMetrics(6);
      nIndex = 5;
    }
    else {
      GetSystemMetrics(0x21);
      nIndex = 0x20;
    }
    iVar2 = GetSystemMetrics(nIndex);
    InflateRect(param_1,-iVar2,nIndex);
    if ((uVar1 & 0xc00000) != 0) {
      param_1->top = param_1->top + DAT_00428bc4;
    }
  }
  else {
    FUN_0040b632(this);
  }
  return;
}



/* VA 00418331 */

uint __thiscall FUN_00418331(void *this,int param_1,int param_2)

{
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  SHORT SVar1;
  int iVar2;
  uint uVar3;
  BOOL BVar4;
  int iVar5;
  RECT local_70 [3];
  tagRECT local_3c;
  tagRECT local_2c;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;

  local_8 = FUN_0040eb4e((int)this);
  GetWindowRect(*(HWND *)((int)this + 0x1c),&local_2c);
  iVar2 = GetSystemMetrics(0x21);
  local_10 = iVar2;
  local_c = GetSystemMetrics(0x20);
  if (DAT_0042884c != 0) {
    uVar3 = FUN_0040b632(this);
    if ((DAT_00428844 != 0) && ((local_8 & 0x1000) != 0)) {
      if (uVar3 == 3) {
        uVar3 = 2;
      }
      SVar1 = GetKeyState(2);
      if (SVar1 < 0) {
        return 0;
      }
    }
    if (((uVar3 < 10) || (0x11 < uVar3)) && (uVar3 != 4)) {
      return uVar3;
    }
    if ((local_8 & 0x800) != 0) {
      return 2;
    }
    InflateRect(&local_2c,-local_c,-iVar2);
    if ((local_8 & 0x200) == 0) {
      return uVar3;
    }
    if (uVar3 != 4) {
      if (uVar3 == 0xd) {
        uVar3 = (local_2c.top <= param_2) - 1 & 2;
LAB_00418424:
        return uVar3 + 10;
      }
      if (uVar3 == 0xe) {
        uVar3 = (uint)(param_2 < local_2c.top);
        goto LAB_0041843b;
      }
      if (uVar3 == 0x10) {
        uVar3 = (param_2 <= local_2c.bottom) - 1 & 5;
        goto LAB_00418424;
      }
      if (uVar3 != 0x11) {
        return uVar3;
      }
    }
    uVar3 = (param_2 <= local_2c.bottom) - 1 & 4;
LAB_0041843b:
    return uVar3 + 0xb;
  }
  pt.y = param_2;
  pt.x = param_1;
  BVar4 = PtInRect(&local_2c,pt);
  if (BVar4 == 0) {
    return 0;
  }
  local_14 = GetSystemMetrics(6);
  iVar2 = GetSystemMetrics(5);
  local_70[0].top = local_2c.top;
  local_70[0].left = local_2c.left;
  local_70[0].bottom = local_2c.bottom;
  local_70[0].right = local_2c.right;
  FUN_004182cb(this,(LPRECT)0x0);
  CopyRect(&local_3c,local_70);
  pt_00.y = param_2;
  pt_00.x = param_1;
  BVar4 = PtInRect(&local_3c,pt_00);
  if (BVar4 != 0) {
    return 1;
  }
  if ((local_8 & 0x40600) == 0) goto LAB_004185f6;
  local_1c = 0;
  iVar2 = local_c + iVar2 * -3 + DAT_00428bc0;
  iVar5 = local_10 + local_14 * -2 + DAT_00428bc4;
  if (param_2 < local_10 + local_2c.top) {
    if ((local_8 & 0x200) == 0) {
      if (local_2c.left + iVar2 < param_1) {
        uVar3 = ((param_1 < local_2c.right - iVar2) - 1 & 2) + 0xc;
      }
      else {
LAB_00418587:
        uVar3 = 0xd;
      }
    }
    else {
      uVar3 = 0xc;
    }
  }
  else {
    local_18 = local_2c.bottom - local_10;
    if (param_2 < local_18) {
      if (param_1 < local_2c.left + local_c) {
        if ((local_8 & 0x200) == 0) {
          if (param_2 <= iVar5 + local_2c.top) goto LAB_00418587;
          uVar3 = ((param_2 < local_2c.bottom - iVar5) - 1 & 6) + 10;
        }
        else {
          uVar3 = 10;
        }
      }
      else if (param_1 < local_2c.right - local_c) {
        uVar3 = 0;
      }
      else if ((local_8 & 0x200) == 0) {
        if (iVar5 + local_2c.top < param_2) {
          uVar3 = ((param_2 < local_2c.bottom - iVar5) - 1 & 6) + 0xb;
        }
        else {
          uVar3 = 0xe;
        }
      }
      else {
        uVar3 = 0xb;
      }
    }
    else if ((local_8 & 0x200) == 0) {
      if (local_2c.left + iVar2 < param_1) {
        uVar3 = ((param_1 < local_2c.right - iVar2) - 1 & 2) + 0xf;
      }
      else {
        uVar3 = 0x10;
      }
    }
    else {
      uVar3 = 0xf;
    }
  }
  if (uVar3 != 0) {
    if ((local_8 & 0x800) != 0) {
      return 2;
    }
    return uVar3;
  }
  InflateRect(&local_2c,-local_c,-local_10);
LAB_004185f6:
  local_2c.bottom = local_14 + local_2c.top + DAT_00428bc4;
  pt_01.y = param_2;
  pt_01.x = param_1;
  BVar4 = PtInRect(&local_2c,pt_01);
  if (BVar4 == 0) {
    return 0xfffffffe;
  }
  if ((param_1 < local_2c.left + -2 + DAT_00428bc0) && ((local_8 & 0x80000) != 0)) {
    return 3;
  }
  return 2;
}



/* VA 0041863e */

void __thiscall FUN_0041863e(void *this,int param_1)

{
  if ((DAT_0042884c == 0) && (param_1 == 3)) {
    *(undefined4 *)((int)this + 0xbc) = 1;
    *(undefined4 *)((int)this + 0xc0) = 1;
    SetCapture(*(HWND *)((int)this + 0x1c));
    FUN_0040b6dd();
    FUN_0041876a();
  }
  else {
    FUN_0040b632(this);
  }
  return;
}



/* VA 00418683 */

void __thiscall FUN_00418683(void *this,undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  CWnd *pCVar2;
  uint uVar3;

  if (*(int *)((int)this + 0xbc) == 0) {
    FUN_0040b632(this);
  }
  else {
    ClientToScreen(*(HWND *)((int)this + 0x1c),(LPPOINT)&param_2);
    GetCapture();
    pCVar2 = FUN_0040b6dd();
    if (pCVar2 == this) {
      uVar1 = *(uint *)((int)this + 0xc0);
      uVar3 = FUN_00418331(this,param_2,param_3);
      if ((uVar3 == 3) != uVar1) {
        *(uint *)((int)this + 0xc0) = (uint)(uVar1 == 0);
        FUN_0041876a();
      }
    }
    else {
      *(undefined4 *)((int)this + 0xbc) = 0;
      SendMessageA(*(HWND *)((int)this + 0x1c),0x85,0,0);
    }
  }
  return;
}



/* VA 0041870a */

void __thiscall FUN_0041870a(void *this,undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;

  if (*(int *)((int)this + 0xbc) == 0) {
    FUN_0040b632(this);
  }
  else {
    ReleaseCapture();
    *(undefined4 *)((int)this + 0xbc) = 0;
    ClientToScreen(*(HWND *)((int)this + 0x1c),(LPPOINT)&param_2);
    uVar1 = FUN_00418331(this,param_2,param_3);
    if (uVar1 == 3) {
      FUN_0041876a();
      SendMessageA(*(HWND *)((int)this + 0x1c),0x10,0,0);
    }
  }
  return;
}



/* VA 0041876a */

void FUN_0041876a(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  tagRECT local_1c;
  int local_c;
  int local_8;

  local_8 = GetSystemMetrics(6);
  iVar1 = GetSystemMetrics(5);
  iVar2 = GetSystemMetrics(0x21);
  iVar3 = GetSystemMetrics(0x20);
  local_1c.top = local_8;
  local_1c.right = DAT_00428bc0 - iVar1;
  local_1c.bottom = DAT_00428bc4;
  local_1c.left = iVar1;
  uVar4 = FUN_0040eb4e(local_c);
  if ((uVar4 & 0x40600) != 0) {
    OffsetRect(&local_1c,iVar3 - iVar1,iVar2 - local_8);
  }
  GetWindowDC(*(HWND *)(local_c + 0x1c));
  iVar1 = FUN_00410b14();
  InvertRect(*(HDC *)(iVar1 + 4),&local_1c);
  ReleaseDC(*(HWND *)(local_c + 0x1c),*(HDC *)(iVar1 + 4));
  return;
}



/* VA 00418802 */

void FUN_00418802(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  DWORD DVar4;
  HBRUSH pHVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  HGDIOBJ pvVar9;
  HDC pHVar10;
  undefined3 extraout_var;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar11;
  undefined4 *unaff_FS_OFFSET;
  bool bVar12;

  FUN_00402bc0();
  bVar12 = DAT_0042884c != 0;
  *(int **)(unaff_EBP + -0x5c) = extraout_ECX;
  if (bVar12) {
    FUN_0040b632(extraout_ECX);
    goto LAB_00418d6a;
  }
  FUN_00411227();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar3 = FUN_0040eb4e((int)extraout_ECX);
  *(undefined4 *)(unaff_EBP + -0x34) = uVar3;
  GetWindowRect((HWND)extraout_ECX[7],(LPRECT)(unaff_EBP + -0x28));
  OffsetRect((LPRECT)(unaff_EBP + -0x28),-*(int *)(unaff_EBP + -0x28),-*(int *)(unaff_EBP + -0x24));
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined ***)(unaff_EBP + -0x30) = &PTR_LAB_0041d9d4;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  DVar4 = GetSysColor(6);
  pHVar5 = CreateSolidBrush(DVar4);
  FUN_0041142e((void *)(unaff_EBP + -0x30),(uint)pHVar5);
  *(undefined4 *)(unaff_EBP + -0x54) = 0;
  *(undefined ***)(unaff_EBP + -0x58) = &PTR_LAB_0041d9d4;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  DVar4 = GetSysColor(0xb - (uint)(*(int *)(*(int *)(unaff_EBP + -0x5c) + 0xc4) != 0));
  pHVar5 = CreateSolidBrush(DVar4);
  FUN_0041142e((void *)(unaff_EBP + -0x58),(uint)pHVar5);
  *(undefined4 *)(unaff_EBP + -0x4c) = 0;
  *(undefined ***)(unaff_EBP + -0x50) = &PTR_LAB_0041d9d4;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  DVar4 = GetSysColor(3 - (uint)(*(int *)(*(int *)(unaff_EBP + -0x5c) + 0xc4) != 0));
  pHVar5 = CreateSolidBrush(DVar4);
  FUN_0041142e((void *)(unaff_EBP + -0x50),(uint)pHVar5);
  iVar6 = GetSystemMetrics(6);
  *(int *)(unaff_EBP + -0x18) = iVar6;
  iVar6 = GetSystemMetrics(5);
  *(int *)(unaff_EBP + -0x10) = iVar6;
  iVar7 = GetSystemMetrics(0x21);
  *(int *)(unaff_EBP + -0x14) = iVar7;
  iVar7 = GetSystemMetrics(0x20);
  if ((*(uint *)(unaff_EBP + -0x34) & 0x40600) != 0) {
    FUN_00418d79(unaff_EBP + -0x48,(RECT *)(unaff_EBP + -0x28),iVar6,*(int *)(unaff_EBP + -0x18),
                 unaff_EBP + -0x30);
    InflateRect((LPRECT)(unaff_EBP + -0x28),-iVar6,-*(int *)(unaff_EBP + -0x18));
    FUN_00418d79(unaff_EBP + -0x48,(RECT *)(unaff_EBP + -0x28),iVar7 - iVar6,
                 *(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18),unaff_EBP + -0x58);
    iVar11 = iVar7 + iVar6 * -2;
    iVar8 = *(int *)(unaff_EBP + -0x14) + *(int *)(unaff_EBP + -0x18) * -2;
    *(int *)(unaff_EBP + -0x14) = iVar8;
    iVar6 = DAT_00428bc4;
    if ((*(byte *)(unaff_EBP + -0x33) & 2) == 0) {
      *(uint *)(unaff_EBP + -0x74) = iVar7 + *(int *)(unaff_EBP + -0x10) * -3 + DAT_00428bc0;
      iVar6 = iVar6 + iVar8;
      FUN_00417e6e((void *)(unaff_EBP + -0x48),*(int *)(unaff_EBP + -0x28),
                   *(int *)(unaff_EBP + -0x24) + iVar6,iVar11,1,0);
      FUN_00417e6e((void *)(unaff_EBP + -0x48),*(int *)(unaff_EBP + -0x28),
                   *(int *)(unaff_EBP + -0x1c) - iVar6,iVar11,1,0);
      FUN_00417e6e((void *)(unaff_EBP + -0x48),*(int *)(unaff_EBP + -0x20) - iVar11,
                   *(int *)(unaff_EBP + -0x24) + iVar6,iVar11,1,0);
      FUN_00417e6e((void *)(unaff_EBP + -0x48),*(int *)(unaff_EBP + -0x20) - iVar11,
                   *(int *)(unaff_EBP + -0x1c) - iVar6,iVar11,1,0);
      iVar6 = *(int *)(unaff_EBP + -0x74);
      FUN_00417e6e((void *)(unaff_EBP + -0x48),*(int *)(unaff_EBP + -0x28) + iVar6,
                   *(int *)(unaff_EBP + -0x24),1,*(int *)(unaff_EBP + -0x14),0);
      FUN_00417e6e((void *)(unaff_EBP + -0x48),*(int *)(unaff_EBP + -0x20) - iVar6,
                   *(int *)(unaff_EBP + -0x24),1,*(int *)(unaff_EBP + -0x14),0);
      FUN_00417e6e((void *)(unaff_EBP + -0x48),*(int *)(unaff_EBP + -0x28) + iVar6,
                   *(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x14),1,
                   *(int *)(unaff_EBP + -0x14),0);
      FUN_00417e6e((void *)(unaff_EBP + -0x48),*(int *)(unaff_EBP + -0x20) - iVar6,
                   *(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x14),1,
                   *(int *)(unaff_EBP + -0x14),0);
      iVar8 = *(int *)(unaff_EBP + -0x14);
    }
    InflateRect((LPRECT)(unaff_EBP + -0x28),-iVar11,-iVar8);
    iVar6 = *(int *)(unaff_EBP + -0x10);
  }
  if ((*(byte *)(unaff_EBP + -0x32) & 0xc0) == 0) {
    FUN_00418d79(unaff_EBP + -0x48,(RECT *)(unaff_EBP + -0x28),iVar6,*(int *)(unaff_EBP + -0x18),
                 unaff_EBP + -0x30);
LAB_00418d1e:
    *(undefined ***)(unaff_EBP + -0x50) = &PTR_LAB_0041d9ec;
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_00411485(unaff_EBP + -0x50);
    *(undefined ***)(unaff_EBP + -0x58) = &PTR_LAB_0041d9ec;
    *(undefined ***)(unaff_EBP + -0x50) = &PTR_LAB_0041d1bc;
    *(undefined1 *)(unaff_EBP + -4) = 10;
    FUN_00411485(unaff_EBP + -0x58);
    *(undefined ***)(unaff_EBP + -0x58) = &PTR_LAB_0041d1bc;
    *(undefined ***)(unaff_EBP + -0x30) = &PTR_LAB_0041d9ec;
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x24);
    *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x1c);
    iVar6 = *(int *)(unaff_EBP + -0x18);
    *(int *)(unaff_EBP + -0x60) = *(int *)(unaff_EBP + -0x24) + iVar6 + DAT_00428bc4;
    FUN_00418d79(unaff_EBP + -0x48,(RECT *)(unaff_EBP + -0x6c),*(int *)(unaff_EBP + -0x10),iVar6,
                 unaff_EBP + -0x30);
    InflateRect((LPRECT)(unaff_EBP + -0x6c),-*(int *)(unaff_EBP + -0x10),-iVar6);
    FillRect(*(HDC *)(unaff_EBP + -0x44),(RECT *)(unaff_EBP + -0x6c),
             (HBRUSH)(-(uint)(unaff_EBP != 0x50) & *(uint *)(unaff_EBP + -0x4c)));
    FUN_00418d79(unaff_EBP + -0x48,(RECT *)(unaff_EBP + -0x28),*(int *)(unaff_EBP + -0x10),iVar6,
                 unaff_EBP + -0x30);
    if (DAT_00428bb0 != (HGDIOBJ)0x0) {
      pvVar9 = SelectObject(*(HDC *)(unaff_EBP + -0x44),DAT_00428bb0);
      *(HGDIOBJ *)(unaff_EBP + -0x18) = pvVar9;
      FUN_0040fe73((undefined4 *)(unaff_EBP + -0x10));
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_0040c106(*(void **)(unaff_EBP + -0x5c),(void *)(unaff_EBP + -0x10));
      iVar6 = (-(uint)((*(uint *)(unaff_EBP + -0x34) & 0x80000) != 0) & DAT_00428bc0) +
              *(int *)(unaff_EBP + -0x6c);
      GetTextExtentPointA(*(HDC *)(unaff_EBP + -0x40),*(LPCSTR *)(unaff_EBP + -0x10),
                          *(int *)(*(LPCSTR *)(unaff_EBP + -0x10) + -8),(LPSIZE)(unaff_EBP + -0x74))
      ;
      if (*(int *)(unaff_EBP + -0x74) <= *(int *)(unaff_EBP + -100) - *(int *)(unaff_EBP + -0x6c)) {
        FUN_0041113f((void *)(unaff_EBP + -0x48),6);
        iVar6 = iVar6 + (*(int *)(unaff_EBP + -100) - iVar6) / 2;
      }
      GetTextMetricsA(*(HDC *)(unaff_EBP + -0x40),(LPTEXTMETRICA)(unaff_EBP + -0xb4));
      iVar7 = *(int *)(unaff_EBP + -0xb0);
      iVar8 = *(int *)(unaff_EBP + -0xac);
      iVar11 = *(int *)(unaff_EBP + -0xa8);
      InflateRect((LPRECT)(unaff_EBP + -0x6c),0,1);
      iVar1 = *(int *)(unaff_EBP + -0x60);
      iVar2 = *(int *)(unaff_EBP + -0x68);
      DVar4 = GetSysColor((-(uint)(*(int *)(*(int *)(unaff_EBP + -0x5c) + 0xc4) != 0) & 0xfffffff6)
                          + 0x13);
      FUN_00410df9((void *)(unaff_EBP + -0x48),DVar4);
      FUN_00410dc1((void *)(unaff_EBP + -0x48),1);
      ExtTextOutA(*(HDC *)(unaff_EBP + -0x44),iVar6,
                  (((iVar1 - iVar2) - (iVar7 + iVar8 + iVar11)) + 1) / 2 +
                  *(int *)(unaff_EBP + -0x68),4,(RECT *)(unaff_EBP + -0x6c),
                  *(LPCSTR *)(unaff_EBP + -0x10),*(UINT *)(*(LPCSTR *)(unaff_EBP + -0x10) + -8),
                  (INT *)0x0);
      if (*(int *)(unaff_EBP + -0x18) != 0) {
        SelectObject(*(HDC *)(unaff_EBP + -0x44),*(HGDIOBJ *)(unaff_EBP + -0x18));
      }
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_0040ff87((int *)(unaff_EBP + -0x10));
    }
    if ((*(byte *)(unaff_EBP + -0x32) & 8) == 0) {
LAB_00418cfe:
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x60);
      goto LAB_00418d1e;
    }
    FUN_00410a60((undefined4 *)(unaff_EBP + -0x7c));
    *(undefined1 *)(unaff_EBP + -4) = 5;
    pHVar10 = CreateCompatibleDC((HDC)(-(uint)(unaff_EBP != 0x48) & *(uint *)(unaff_EBP + -0x44)));
    bVar12 = FUN_00410b2a((void *)(unaff_EBP + -0x7c),(uint)pHVar10);
    if (CONCAT31(extraout_var,bVar12) != 0) {
      if (DAT_00428bb4 == (HGDIOBJ)0x0) {
        pvVar9 = (HGDIOBJ)0x0;
      }
      else {
        pvVar9 = SelectObject(*(HDC *)(unaff_EBP + -0x78),DAT_00428bb4);
      }
      BitBlt(*(HDC *)(unaff_EBP + -0x44),*(int *)(unaff_EBP + -0x28),*(int *)(unaff_EBP + -0x24),
             DAT_00428bc0,DAT_00428bc4,
             (HDC)(-(uint)(unaff_EBP != 0x7c) & *(uint *)(unaff_EBP + -0x78)),0,0,0xcc0020);
      if (pvVar9 != (HGDIOBJ)0x0) {
        SelectObject(*(HDC *)(unaff_EBP + -0x78),pvVar9);
      }
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_00410b92();
      goto LAB_00418cfe;
    }
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_00410b92();
    *(undefined ***)(unaff_EBP + -0x50) = &PTR_LAB_0041d9ec;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_00411485(unaff_EBP + -0x50);
    *(undefined ***)(unaff_EBP + -0x58) = &PTR_LAB_0041d9ec;
    *(undefined ***)(unaff_EBP + -0x50) = &PTR_LAB_0041d1bc;
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_00411485(unaff_EBP + -0x58);
    *(undefined ***)(unaff_EBP + -0x58) = &PTR_LAB_0041d1bc;
    *(undefined ***)(unaff_EBP + -0x30) = &PTR_LAB_0041d9ec;
    *(undefined1 *)(unaff_EBP + -4) = 8;
  }
  FUN_00411485(unaff_EBP + -0x30);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined ***)(unaff_EBP + -0x30) = &PTR_LAB_0041d1bc;
  FUN_00411299();
LAB_00418d6a:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 00418d79 */

void __cdecl FUN_00418d79(int param_1,RECT *param_2,int param_3,int param_4,int param_5)

{
  HBRUSH pHVar1;
  tagRECT local_14;

  CopyRect(&local_14,param_2);
  local_14.right = local_14.left + param_3;
  pHVar1 = (HBRUSH)0x0;
  if (param_5 != 0) {
    pHVar1 = *(HBRUSH *)(param_5 + 4);
  }
  FillRect(*(HDC *)(param_1 + 4),&local_14,pHVar1);
  local_14.right = param_2->right;
  local_14.left = local_14.right - param_3;
  pHVar1 = (HBRUSH)0x0;
  if (param_5 != 0) {
    pHVar1 = *(HBRUSH *)(param_5 + 4);
  }
  FillRect(*(HDC *)(param_1 + 4),&local_14,pHVar1);
  CopyRect(&local_14,param_2);
  local_14.bottom = local_14.top + param_4;
  local_14.left = local_14.left + param_3;
  local_14.right = local_14.right - param_3;
  pHVar1 = (HBRUSH)0x0;
  if (param_5 != 0) {
    pHVar1 = *(HBRUSH *)(param_5 + 4);
  }
  FillRect(*(HDC *)(param_1 + 4),&local_14,pHVar1);
  local_14.bottom = param_2->bottom;
  local_14.top = local_14.bottom - param_4;
  pHVar1 = (HBRUSH)0x0;
  if (param_5 != 0) {
    pHVar1 = *(HBRUSH *)(param_5 + 4);
  }
  FillRect(*(HDC *)(param_1 + 4),&local_14,pHVar1);
  return;
}



/* VA 00418e34 */

void __thiscall FUN_00418e34(void *this,uint param_1,int param_2)

{
  SHORT SVar1;
  uint uVar2;
  int iVar3;

  uVar2 = FUN_0040eb4e((int)this);
  if (((uVar2 & 0x80000000) != 0) &&
     ((((param_1 & 0xfff0) != 0xf060 ||
       (((SVar1 = GetKeyState(0x73), SVar1 < 0 && (SVar1 = GetKeyState(0x12), SVar1 < 0)) &&
        ((uVar2 & 0x100) != 0)))) && (iVar3 = FUN_0040d3d6(this,param_1,param_2), iVar3 != 0)))) {
    return;
  }
  FUN_00416880(this,param_1);
  return;
}



/* VA 00418f04 */

void FUN_00418f04(LPRECT param_1,uint param_2)

{
  int dx;
  int nIndex;

  if (DAT_0042884c == 0) {
    if ((param_2 & 0x40600) == 0) {
      GetSystemMetrics(6);
      nIndex = 5;
    }
    else {
      GetSystemMetrics(0x21);
      nIndex = 0x20;
    }
    dx = GetSystemMetrics(nIndex);
    InflateRect(param_1,dx,nIndex);
    if ((param_2 & 0xc00000) != 0) {
      FUN_00417f52();
      param_1->top = param_1->top - DAT_00428bc4;
    }
  }
  else {
    AdjustWindowRectEx(param_1,param_2,0,0x188);
  }
  return;
}



/* VA 00418fc7 */

undefined4 FUN_00418fc7(void)

{
  undefined4 uVar1;
  int iVar2;
  LPSTR lpString1;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  bool bVar3;

  FUN_00402bc0();
  bVar3 = DAT_0042884c == 0;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  if (bVar3) {
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (*(int *)(unaff_EBP + 0xc) == 0) {
      FUN_0040ff12(extraout_ECX + 0x32);
    }
    else {
      iVar2 = lstrlenA(*(LPCSTR *)(unaff_EBP + 0xc));
      lpString1 = (LPSTR)FUN_0041007b(extraout_ECX + 0x32,iVar2);
      lstrcpyA(lpString1,*(LPCSTR *)(unaff_EBP + 0xc));
    }
    SendMessageA((HWND)extraout_ECX[7],0x85,0,0);
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_0040b632(extraout_ECX);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar1;
}



/* VA 0041911e */

int * __thiscall FUN_0041911e(void *this,undefined4 param_1)

{
  int *piVar1;
  int iVar2;

  piVar1 = (int *)FUN_0040fc25();
  if (piVar1 == (int *)0x0) {
    FUN_0040a8cd();
  }
  iVar2 = (**(code **)(*piVar1 + 0xfc))(this,param_1);
  if (iVar2 == 0) {
    FUN_0041149b();
  }
  return piVar1;
}



/* VA 00419157 */

void __thiscall FUN_00419157(void *this,void *param_1,void *param_2,RECT *param_3)

{
  uint *puVar1;
  int iVar2;

  if (param_2 == (void *)0x0) {
    iVar2 = 0;
    puVar1 = &DAT_0041f074;
    do {
      if (((*puVar1 ^ *(uint *)((int)param_1 + 100)) & 0xf000) == 0) {
        param_2 = (void *)FUN_00417150(this,(&DAT_0041f070)[iVar2 * 2]);
        break;
      }
      puVar1 = puVar1 + 2;
      iVar2 = iVar2 + 1;
    } while ((int)puVar1 < 0x41f094);
  }
  FUN_0041483c(param_2,param_1,param_3);
  return;
}



/* VA 004191ac */

void __thiscall FUN_004191ac(void *this,void *param_1,void *param_2,RECT *param_3)

{
  void *this_00;
  uint uVar1;
  uint *puVar2;
  int iVar3;
  void *local_8;

  if (param_2 == (void *)0x0) {
    local_8 = (void *)0x0;
    puVar2 = &DAT_0041f070;
    do {
      this_00 = (void *)FUN_00417150(this,*puVar2);
      if (this_00 != (void *)0x0) {
        iVar3 = -1;
        uVar1 = GetDlgCtrlID(*(HWND *)((int)param_1 + 0x1c));
        iVar3 = FUN_004153aa(this_00,uVar1 & 0xffff,iVar3);
        if (0 < iVar3) break;
      }
      if (((*(uint *)((int)param_1 + 100) ^ puVar2[1]) & 0xf000) == 0) {
        local_8 = (void *)FUN_00417150(this,*puVar2);
      }
      puVar2 = puVar2 + 2;
      this_00 = param_2;
    } while ((int)puVar2 < 0x41f090);
    param_2 = this_00;
    if (param_2 == (void *)0x0) {
      param_2 = local_8;
    }
  }
  FUN_00414a77(param_2,param_1,param_3);
  return;
}



/* VA 0041923b */

void __thiscall FUN_0041923b(void *this,void *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  CWnd *this_00;
  void *pvVar2;
  uint uVar3;

  if ((((*(int *)((int)param_1 + 0x6c) == 0) ||
       (pvVar2 = *(void **)((int)param_1 + 0x70), pvVar2 == (void *)0x0)) ||
      (*(int *)((int)pvVar2 + 0x78) == 0)) ||
     ((iVar1 = FUN_004147d4(pvVar2), iVar1 != 1 ||
      ((*(uint *)((int)pvVar2 + 100) & param_4 & 0xf000) == 0)))) {
    uVar3 = param_4;
    if (((*(byte *)((int)param_1 + 100) & 4) != 0) && (uVar3 = param_4 | 4, (param_4 & 0x5000) != 0)
       ) {
      uVar3 = param_4 & 0xffff2fff | 0x2004;
    }
    param_4 = uVar3;
    this_00 = (CWnd *)FUN_0041911e(this,param_4);
    FUN_0040ec40(this_00,0,param_2,param_3,0,0,0x15);
    if (*(int *)(this_00 + 0x20) == 0) {
      *(undefined4 *)(this_00 + 0x20) = *(undefined4 *)((int)param_1 + 0x1c);
    }
    pvVar2 = (void *)FUN_0040eaf1(this_00,0xe81f);
    FUN_0041483c(pvVar2,param_1,(RECT *)0x0);
    (**(code **)(*(int *)this_00 + 0xd0))(1);
    uVar3 = GetWindowLongA(*(HWND *)((int)param_1 + 0x1c),-0x10);
    if ((uVar3 & 0x10000000) == 0) {
      return;
    }
    FUN_0040ec8f(this_00,8);
  }
  else {
    GetParent(*(HWND *)((int)pvVar2 + 0x1c));
    this_00 = FUN_0040b6dd();
    FUN_0040ec40(this_00,0,param_2,param_3,0,0,0x15);
    (**(code **)(*(int *)this_00 + 0xd0))(1);
  }
  UpdateWindow(*(HWND *)(this_00 + 0x1c));
  return;
}



/* VA 00419338 */

uint __thiscall FUN_00419338(void *this)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  BOOL BVar4;
  undefined4 *puVar5;
  uint in_stack_00000014;
  int *in_stack_00000018;
  tagRECT local_14;

  in_stack_00000014 = in_stack_00000014 & 0xf040;
  if (in_stack_00000018 != (int *)0x0) {
    *in_stack_00000018 = 0;
  }
  puVar5 = *(undefined4 **)((int)this + 0x70);
  do {
    do {
      if (puVar5 == (undefined4 *)0x0) {
        return 0;
      }
      puVar1 = (undefined4 *)*puVar5;
      piVar2 = (int *)puVar5[2];
      iVar3 = (**(code **)(*piVar2 + 0xd8))();
      puVar5 = puVar1;
    } while ((((iVar3 == 0) || (BVar4 = IsWindowVisible((HWND)piVar2[7]), BVar4 == 0)) ||
             ((piVar2[0x19] & in_stack_00000014 & 0xf000) == 0)) ||
            ((piVar2[0x1e] != 0 && ((piVar2[0x19] & in_stack_00000014 & 0x40) == 0))));
    GetWindowRect((HWND)piVar2[7],&local_14);
    if (local_14.right == local_14.left) {
      local_14.right = local_14.right + 1;
    }
    if (local_14.bottom == local_14.top) {
      local_14.bottom = local_14.bottom + 1;
    }
    BVar4 = IntersectRect(&local_14,&local_14,(RECT *)&stack0x00000004);
  } while (BVar4 == 0);
  if (in_stack_00000018 != (int *)0x0) {
    *in_stack_00000018 = (int)piVar2;
  }
  return piVar2[0x19] & in_stack_00000014;
}



/* VA 004193e0 */

void FUN_004193e0(void)

{
  int iVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  iVar1 = FUN_0040f348(0xbc);
  *(int *)(unaff_EBP + -0x10) = iVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 != 0) {
    FUN_0041595b();
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 0041945f */

void FUN_0041945f(void)

{
  byte bVar1;
  LONG LVar2;
  uint uVar3;
  undefined1 *puVar4;
  int nWidth;
  int iVar5;
  int iVar6;
  undefined1 local_94 [132];
  int local_10;
  int local_c;
  byte *local_8;

  LVar2 = GetMenuCheckMarkDimensions();
  nWidth = (int)(short)LVar2;
  local_10 = (int)(short)((uint)LVar2 >> 0x10);
  if (0x20 < nWidth) {
    nWidth = 0x20;
  }
  iVar5 = nWidth + 0xf >> 4;
  iVar6 = ((nWidth + -4) / 2 + iVar5 * 0x10) - nWidth;
  if (0xc < iVar6) {
    iVar6 = 0xc;
  }
  if (0x20 < local_10) {
    local_10 = 0x20;
  }
  _memset(local_94,0xff,0x80);
  local_8 = &DAT_0041d128;
  local_c = 5;
  puVar4 = local_94 + (local_10 + -6 >> 1) * iVar5 * 2;
  do {
    bVar1 = *local_8;
    uVar3 = (uint)local_8 >> 0x10;
    local_8 = local_8 + 1;
    uVar3 = ~(CONCAT22((short)uVar3,(ushort)bVar1) << ((byte)iVar6 & 0x1f));
    puVar4[1] = (char)uVar3;
    *puVar4 = (char)(uVar3 >> 8);
    puVar4 = puVar4 + iVar5 * 2;
    local_c = local_c + -1;
  } while (local_c != 0);
  DAT_00428838 = CreateBitmap(nWidth,local_10,1,1,local_94);
  if (DAT_00428838 == (HBITMAP)0x0) {
    DAT_00428838 = LoadBitmapA((HINSTANCE)0x0,(LPCSTR)0x7fe3);
  }
  return;
}



/* VA 0041954b */

undefined4 * __fastcall FUN_0041954b(undefined4 *param_1)

{
  FUN_0041ae54(param_1);
  *param_1 = &PTR_LAB_0041d4c4;
  param_1[0x12] = 2;
  if (DAT_00428844 == 0) {
    param_1[0x10] = 2;
    param_1[0x11] = 2;
    param_1[0x13] = 1;
  }
  else {
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    param_1[0x13] = 0;
  }
  param_1[0x1e] = 0;
  return param_1;
}



/* VA 00419588 */

/* Library Function - Single Match
    public: virtual void * __thiscall CStatusBar::`scalar deleting destructor'(unsigned int)

   Library: Visual Studio 2003 Release */

void * __thiscall CStatusBar::_scalar_deleting_destructor_(CStatusBar *this,uint param_1)

{
  ~CStatusBar(this);
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 004195a4 */

/* Library Function - Single Match
    public: virtual __thiscall CStatusBar::~CStatusBar(void)

   Library: Visual Studio 2003 Release */

void __thiscall CStatusBar::~CStatusBar(CStatusBar *this)

{
  undefined4 *this_00;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = this_00;
  *this_00 = &PTR_LAB_0041d4c4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004197af(this_00,0,0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004129b9();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 004195df */

void __thiscall FUN_004195df(void *this,int param_1,undefined4 param_2,HMENU param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  tagRECT local_14;

  *(undefined4 *)((int)this + 100) = param_2;
  uVar3 = CONCAT31((uint3)((uint)param_2 >> 8) & 0xffff00,0x4e);
  uVar1 = FUN_0040eb4e(param_1);
  if ((uVar1 & 0x40000) != 0) {
    uVar3 = uVar3 | 0x100;
  }
  iVar2 = FUN_00419dc2();
  if ((*(byte *)(iVar2 + 0x18) & 0x10) == 0) {
    FUN_0040e0b4(0x10);
  }
  SetRectEmpty(&local_14);
  FUN_0040bd72(this,"msctls_statusbar32",(LPCSTR)0x0,uVar3,&local_14.left,param_1,param_3,
               (LPVOID)0x0);
  return;
}



/* VA 00419678 */

undefined4 FUN_00419678(void)

{
  UINT *pUVar1;
  UINT UVar2;
  bool bVar3;
  int iVar4;
  HGDIOBJ pvVar5;
  undefined3 extraout_var;
  int iVar6;
  undefined4 uVar7;
  void *this;
  int unaff_EBP;
  UINT *pUVar8;
  UINT *pUVar9;
  void *this_00;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(void **)(unaff_EBP + -0x1c) = this;
  iVar4 = FUN_004197af(this,*(int *)(unaff_EBP + 0xc),0x14);
  uVar7 = 0;
  if (iVar4 != 0) {
    *(undefined4 *)(unaff_EBP + -0x18) = 1;
    this_00 = this;
    if (*(int *)(unaff_EBP + 8) != 0) {
      pvVar5 = (HGDIOBJ)SendMessageA(*(HWND *)((int)this + 0x1c),0x31,0,0);
      FUN_00411173();
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      if (pvVar5 != (HGDIOBJ)0x0) {
        pvVar5 = SelectObject(*(HDC *)(unaff_EBP + -0x34),pvVar5);
        *(HGDIOBJ *)(unaff_EBP + -0x14) = pvVar5;
      }
      pUVar9 = *(UINT **)((int)this + 0x5c);
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      if (0 < *(int *)(unaff_EBP + 0xc)) {
        pUVar8 = pUVar9 + 4;
        do {
          pUVar1 = *(UINT **)(unaff_EBP + 8);
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 4;
          UVar2 = *pUVar1;
          pUVar8[-1] = pUVar8[-1] | 1;
          *pUVar9 = UVar2;
          if (UVar2 != 0) {
            bVar3 = FUN_0040f9ce(UVar2);
            if (CONCAT31(extraout_var,bVar3) != 0) {
              GetTextExtentPointA(*(HDC *)(unaff_EBP + -0x30),(LPCSTR)*pUVar8,
                                  *(int *)((LPCSTR)*pUVar8 + -8),(LPSIZE)(unaff_EBP + -0x24));
              pUVar8[-3] = *(UINT *)(unaff_EBP + -0x24);
              iVar4 = FUN_00412277();
              if (iVar4 != 0) goto LAB_0041975a;
            }
            *(undefined4 *)(unaff_EBP + -0x18) = 0;
            break;
          }
          iVar6 = GetSystemMetrics(0);
          iVar4 = *(int *)(unaff_EBP + -0x10);
          pUVar8[-3] = iVar6 / 4;
          if (iVar4 == 0) {
            pUVar8[-2] = pUVar8[-2] | 0x8000100;
          }
LAB_0041975a:
          pUVar9 = pUVar9 + 5;
          pUVar8 = pUVar8 + 5;
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + 0xc));
      }
      if (*(int *)(unaff_EBP + -0x14) != 0) {
        SelectObject(*(HDC *)(unaff_EBP + -0x34),*(HGDIOBJ *)(unaff_EBP + -0x14));
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004111e5();
      this_00 = *(void **)(unaff_EBP + -0x1c);
    }
    FUN_00419883(this_00,1,1);
    uVar7 = *(undefined4 *)(unaff_EBP + -0x18);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar7;
}



/* VA 004197af */

undefined4 __thiscall FUN_004197af(void *this,int param_1,int param_2)

{
  undefined **ppuVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;

  iVar5 = 0;
  if (0 < *(int *)((int)this + 0x58)) {
    piVar3 = (int *)(*(int *)((int)this + 0x5c) + 0x10);
    do {
      FUN_0040ff87(piVar3);
      piVar3 = piVar3 + 5;
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)((int)this + 0x58));
  }
  iVar5 = FUN_0041af6c(this,param_1,param_2);
  uVar2 = 0;
  if (iVar5 != 0) {
    iVar5 = 0;
    if (0 < *(int *)((int)this + 0x58)) {
      puVar4 = (undefined4 *)(*(int *)((int)this + 0x5c) + 0x10);
      do {
        uVar6 = 4;
        ppuVar1 = FUN_0040fe6d();
        FUN_00403510(puVar4,ppuVar1,uVar6);
        puVar4 = puVar4 + 5;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)((int)this + 0x58));
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* VA 00419814 */

void __thiscall FUN_00419814(void *this,int *param_1,int param_2)

{
  uint uVar1;
  HWND hWnd;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  int local_10 [3];

  FUN_004137e1(this,param_1,param_2);
  uVar1 = FUN_0040eb4e((int)this);
  if ((uVar1 & 0x100) != 0) {
    hWnd = GetParent(*(HWND *)((int)this + 0x1c));
    BVar2 = IsZoomed(hWnd);
    if (BVar2 == 0) {
      (**(code **)(*(int *)this + 0xa8))(0x407,0,local_10);
      iVar3 = GetSystemMetrics(5);
      iVar4 = GetSystemMetrics(2);
      param_1[2] = param_1[2] + ((iVar3 * -2 - local_10[0]) - iVar4);
    }
  }
  return;
}



/* VA 00419883 */

void __thiscall FUN_00419883(void *this,int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  tagRECT local_30;
  int local_20;
  int local_18;
  code *local_14;
  undefined1 *local_10;
  int local_c;
  int *local_8;

  if (param_1 != 0) {
    GetWindowRect(*(HWND *)((int)this + 0x1c),&local_30);
    OffsetRect(&local_30,-local_30.left,-local_30.top);
    FUN_00419814(this,&local_30.left,1);
    local_14 = *(code **)(*(int *)this + 0xa8);
    (*local_14)();
    param_1 = 0;
    iVar4 = *(int *)((int)this + 0x58);
    iVar5 = (local_30.right - local_30.left) + local_18;
    if (0 < iVar4) {
      piVar1 = (int *)(*(int *)((int)this + 0x5c) + 4);
      iVar3 = iVar4;
      do {
        if ((*(byte *)((int)piVar1 + 7) & 8) != 0) {
          param_1 = param_1 + 1;
        }
        iVar2 = *piVar1;
        piVar1 = piVar1 + 5;
        iVar5 = iVar5 + ((-6 - local_18) - iVar2);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    FUN_00403850();
    local_c = 0;
    local_10 = &stack0xffffffb8;
    if (0 < iVar4) {
      iVar4 = *(int *)((int)this + 0x5c) + 8;
      local_10 = &stack0xffffffb8;
      local_8 = (int *)&stack0xffffffb8;
      do {
        iVar3 = local_20 + 6 + *(int *)(iVar4 + -4);
        if (((*(byte *)(iVar4 + 3) & 8) != 0) && (0 < iVar5)) {
          iVar2 = iVar5 / param_1;
          iVar3 = iVar3 + iVar2;
          param_1 = param_1 + -1;
          iVar5 = iVar5 - iVar2;
        }
        iVar4 = iVar4 + 0x14;
        piVar1 = local_8 + 1;
        *local_8 = iVar3;
        local_8 = piVar1;
        local_20 = iVar3 + local_18;
        local_c = local_c + 1;
      } while (local_c < *(int *)((int)this + 0x58));
    }
    (*local_14)(0x404,*(undefined4 *)((int)this + 0x58),local_10);
  }
  iVar4 = 0;
  if ((param_2 != 0) && (0 < *(int *)((int)this + 0x58))) {
    iVar5 = *(int *)((int)this + 0x5c) + 0x10;
    do {
      if ((*(byte *)(iVar5 + -4) & 1) != 0) {
        FUN_00412277();
      }
      iVar5 = iVar5 + 0x14;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)((int)this + 0x58));
  }
  return;
}



/* VA 004199c3 */

void __fastcall FUN_004199c3(undefined4 *param_1)

{
  param_1[0x35] = 0xffffffff;
  param_1[0x41] = 0xffffffff;
  *param_1 = &PTR_FUN_0041d5e4;
  return;
}



/* VA 004199da */

HLOCAL __thiscall FUN_004199da(void *this,byte param_1)

{
  FUN_004199f5();
  if ((param_1 & 1) != 0) {
    FUN_0041a63a(this);
  }
  return this;
}



/* VA 004199f5 */

void FUN_004199f5(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0041d5e4;
  piVar1 = (int *)extraout_ECX[0x33];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x60))();
    if ((int *)extraout_ECX[0x33] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[0x33] + 4))(1);
    }
  }
  if ((HHOOK)extraout_ECX[0xc] != (HHOOK)0x0) {
    UnhookWindowsHookEx((HHOOK)extraout_ECX[0xc]);
  }
  if ((HHOOK)extraout_ECX[0xb] != (HHOOK)0x0) {
    UnhookWindowsHookEx((HHOOK)extraout_ECX[0xb]);
  }
  if ((undefined *)extraout_ECX[3] != (undefined *)0x0) {
    FUN_00402c80((undefined *)extraout_ECX[3]);
  }
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d5ec;
  *unaff_FS_OFFSET = uVar2;
  return;
}



/* VA 00419a6f */

void FUN_00419a6f(void)

{
  FUN_0041a9d0(&DAT_00428660,FUN_00401abc);
  return;
}



/* VA 00419a89 */

void FUN_00419a89(void)

{
  return;
}



/* VA 00419a8a */

void FUN_00419a8a(void)

{
  FUN_00402fb0(0x419a96);
  return;
}



/* VA 00419aa5 */

void __thiscall FUN_00419aa5(void *this,undefined1 param_1)

{
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x103c) = 0;
  *(undefined4 *)((int)this + 0x1040) = 0;
  *(undefined4 *)((int)this + 0x104c) = 0xffffffff;
  *(undefined4 *)((int)this + 0x1050) = 0;
  *(undefined4 *)((int)this + 0x1064) = 0;
  *(undefined4 *)((int)this + 0x1068) = 0;
  *(undefined ***)this = &PTR_FUN_0041d5f4;
  *(undefined4 *)((int)this + 0x28) = 0x1c;
  *(undefined4 *)((int)this + 0x20) = 0x14;
  *(undefined2 *)((int)this + 0x18) = 0;
  *(undefined1 *)((int)this + 0x14) = param_1;
  *(undefined4 *)((int)this + 0x30) = 1;
  *(undefined4 *)((int)this + 0x1040) = 0x18;
  return;
}



/* VA 00419b09 */

HLOCAL __thiscall FUN_00419b09(void *this,byte param_1)

{
  FUN_00419b24();
  if ((param_1 & 1) != 0) {
    FUN_0041a63a(this);
  }
  return this;
}



/* VA 00419b24 */

void FUN_00419b24(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0041d5f4;
  puVar1 = (undefined4 *)extraout_ECX[0x411];
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  if (extraout_ECX[0x41b] != 0) {
    iVar3 = -(uint)(*(int *)(extraout_ECX[0x41b] + 0xc) != 0);
    *(int *)(unaff_EBP + -0x14) = iVar3;
    if (iVar3 != 0) {
      do {
        FUN_0040af86((void *)extraout_ECX[0x41b],(int *)(unaff_EBP + -0x14),
                     (int *)(unaff_EBP + -0x1c),(int *)(unaff_EBP + -0x10));
        if (*(undefined4 **)(unaff_EBP + -0x10) != extraout_ECX + 0x412) {
          FUN_0040f384(*(undefined **)(unaff_EBP + -0x10));
        }
      } while (*(int *)(unaff_EBP + -0x14) != 0);
    }
    if ((int *)extraout_ECX[0x41b] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[0x41b] + 4))(1);
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0041aa47(extraout_ECX + 0x41c);
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d5ec;
  *unaff_FS_OFFSET = uVar2;
  return;
}



/* VA 00419bd7 */

undefined4 * FUN_00419bd7(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041d5ec;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  CMap<>(extraout_ECX + 0xc,10);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  CMap<>(extraout_ECX + 0x13,10);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0040a8e8(extraout_ECX + 0x1a,10);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_0041d5fc;
  extraout_ECX[3] = 0x54;
  extraout_ECX[10] = &LAB_0040f32c;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}



/* VA 00419c42 */

HLOCAL __thiscall FUN_00419c42(void *this,byte param_1)

{
  FUN_00419c5d();
  if ((param_1 & 1) != 0) {
    FUN_0041a63a(this);
  }
  return this;
}



/* VA 00419c5d */

void FUN_00419c5d(void)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0041d5fc;
  puVar2 = (undefined *)extraout_ECX[5];
  *(undefined4 *)(unaff_EBP + -4) = 3;
  if (puVar2 != (undefined *)0x0) {
    FUN_00401b77();
    FUN_0040f384(puVar2);
  }
  puVar2 = (undefined *)extraout_ECX[6];
  if (puVar2 != (undefined *)0x0) {
    FUN_00401b77();
    FUN_0040f384(puVar2);
  }
  puVar2 = (undefined *)extraout_ECX[7];
  if (puVar2 != (undefined *)0x0) {
    FUN_00401b77();
    FUN_0040f384(puVar2);
  }
  puVar2 = (undefined *)extraout_ECX[8];
  if (puVar2 != (undefined *)0x0) {
    FUN_00401b77();
    FUN_0040f384(puVar2);
  }
  puVar2 = (undefined *)extraout_ECX[9];
  if (puVar2 != (undefined *)0x0) {
    FUN_00401b77();
    FUN_0040f384(puVar2);
  }
  if (extraout_ECX[0x1d] != 0) {
    do {
      puVar2 = (undefined *)FUN_0040aa11(extraout_ECX + 0x1a);
      FUN_0040f384(puVar2);
    } while (extraout_ECX[0x1d] != 0);
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0040a947();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0040adf9();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0040adf9();
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d5ec;
  *unaff_FS_OFFSET = uVar1;
  return;
}



/* VA 00419d44 */

void FUN_00419d44(void)

{
  return;
}



/* VA 00419d45 */

void FUN_00419d45(void)

{
  FUN_00402fb0(0x419d51);
  return;
}



/* VA 00419da2 */

HLOCAL __thiscall FUN_00419da2(void *this,byte param_1)

{
  thunk_FUN_00419b24();
  if ((param_1 & 1) != 0) {
    FUN_0041a63a(this);
  }
  return this;
}



/* VA 00419dbd */

void thunk_FUN_00419b24(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0041d5f4;
  puVar1 = (undefined4 *)extraout_ECX[0x411];
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  if (extraout_ECX[0x41b] != 0) {
    iVar3 = -(uint)(*(int *)(extraout_ECX[0x41b] + 0xc) != 0);
    *(int *)(unaff_EBP + -0x14) = iVar3;
    if (iVar3 != 0) {
      do {
        FUN_0040af86((void *)extraout_ECX[0x41b],(int *)(unaff_EBP + -0x14),
                     (int *)(unaff_EBP + -0x1c),(int *)(unaff_EBP + -0x10));
        if (*(undefined4 **)(unaff_EBP + -0x10) != extraout_ECX + 0x412) {
          FUN_0040f384(*(undefined **)(unaff_EBP + -0x10));
        }
      } while (*(int *)(unaff_EBP + -0x14) != 0);
    }
    if ((int *)extraout_ECX[0x41b] != (int *)0x0) {
      (**(code **)(*(int *)extraout_ECX[0x41b] + 4))(1);
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0041aa47(extraout_ECX + 0x41c);
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d5ec;
  *unaff_FS_OFFSET = uVar2;
  return;
}



/* VA 00419dc2 */

void FUN_00419dc2(void)

{
  int iVar1;

  iVar1 = FUN_0041a9d0(&DAT_00428660,FUN_00401abc);
  if (*(int *)(iVar1 + 4) == 0) {
    FUN_0041aa65();
  }
  return;
}



/* VA 00419de8 */

/* Library Function - Single Match
    class AFX_MODULE_THREAD_STATE * __stdcall AfxGetModuleThreadState(void)

   Library: Visual Studio 2003 Release */

AFX_MODULE_THREAD_STATE * AfxGetModuleThreadState(void)

{
  int iVar1;
  AFX_MODULE_THREAD_STATE *pAVar2;

  iVar1 = FUN_00419dc2();
  pAVar2 = (AFX_MODULE_THREAD_STATE *)FUN_0041a9d0((void *)(iVar1 + 0x1070),FUN_00401a57);
  return pAVar2;
}



/* VA 00419dff */

/* Library Function - Single Match
    public: void __thiscall CTypeLibCache::Unlock(void)

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release,
   Visual Studio 2010 Release */

void __thiscall CTypeLibCache::Unlock(CTypeLibCache *this)

{
  int *piVar1;
  LONG LVar2;

  LVar2 = InterlockedDecrement((LONG *)(this + 0x20));
  if (LVar2 == 0) {
    piVar1 = *(int **)(this + 0x1c);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(this + 0x1c) = 0;
    }
    piVar1 = *(int **)(this + 8);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(this + 8) = 0;
    }
  }
  return;
}



/* VA 00419e44 */

void FUN_00419e44(void)

{
  FUN_00401bb8(&DAT_00428700,0,0xf022);
  return;
}



/* VA 00419e56 */

void FUN_00419e56(void)

{
  FUN_00402fb0(0x419e62);
  return;
}



/* VA 00419e7c */

void FUN_00419e7c(void)

{
  FUN_00401be2(&DAT_00428668,0,0xf024);
  return;
}



/* VA 00419e8e */

void FUN_00419e8e(void)

{
  FUN_00402fb0(0x419e9a);
  return;
}



/* VA 00419f1a */

/* Library Function - Single Match
    public: virtual void * __thiscall CWinThread::`scalar deleting destructor'(unsigned int)

   Library: Visual Studio 2003 Release */

void * __thiscall CWinThread::_scalar_deleting_destructor_(CWinThread *this,uint param_1)

{
  ~CWinThread(this);
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 00419f36 */

undefined4 * FUN_00419f36(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0040ed8e(extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_LAB_0041da6c;
  extraout_ECX[0x13] = 0;
  extraout_ECX[0x14] = 0;
  FUN_00419f73((int)extraout_ECX);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}



/* VA 00419f73 */

void __fastcall FUN_00419f73(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  GetCursorPos((LPPOINT)(param_1 + 0x5c));
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x24) = 1;
  return;
}



/* VA 00419fcb */

void __fastcall FUN_00419fcb(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0041dc24;
  return;
}



/* VA 00419fd4 */

HLOCAL __thiscall FUN_00419fd4(void *this,byte param_1)

{
  FUN_0041b36a();
  if ((param_1 & 1) != 0) {
    FUN_0041a63a(this);
  }
  return this;
}



/* VA 00419fef */

undefined4 * FUN_00419fef(void)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  HANDLE pvVar5;
  DWORD DVar6;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00419f36();
  *extraout_ECX = &PTR_LAB_0041dc2c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + 8) == 0) {
    extraout_ECX[0x1e] = 0;
  }
  else {
    pcVar2 = FUN_00403880(*(char **)(unaff_EBP + 8));
    extraout_ECX[0x1e] = pcVar2;
  }
  iVar3 = FUN_00419dc2();
  iVar4 = FUN_0041a9d0((void *)(iVar3 + 0x1070),FUN_00401a57);
  *(undefined4 **)(iVar4 + 4) = extraout_ECX;
  pvVar5 = GetCurrentThread();
  extraout_ECX[10] = pvVar5;
  DVar6 = GetCurrentThreadId();
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0xb] = DVar6;
  *(undefined4 **)(iVar3 + 4) = extraout_ECX;
  extraout_ECX[0x1a] = 0;
  extraout_ECX[0x23] = 0;
  extraout_ECX[0x24] = 0;
  extraout_ECX[0x1f] = 0;
  extraout_ECX[0x22] = 0;
  extraout_ECX[0x2a] = 0;
  extraout_ECX[0x20] = 0;
  *(undefined2 *)((int)extraout_ECX + 0xb2) = 0;
  *(undefined2 *)(extraout_ECX + 0x2c) = 0;
  extraout_ECX[0x1c] = 0;
  extraout_ECX[0x2b] = 0;
  extraout_ECX[0x28] = 0;
  extraout_ECX[0x29] = 0;
  extraout_ECX[0x25] = 0;
  extraout_ECX[0x26] = 0;
  extraout_ECX[0x2d] = 0;
  extraout_ECX[0x2f] = 0;
  extraout_ECX[0x21] = 0;
  extraout_ECX[0x2e] = 0x200;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}



/* VA 0041a0d9 */

undefined * __thiscall FUN_0041a0d9(void *this,byte param_1)

{
  FUN_0041a3e5();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 0041a139 */

void FUN_0041a139(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;

  if (1 < DAT_00428be8) {
    pcVar2 = *(code **)(*param_1 + 0x14);
    iVar3 = 1;
    do {
      iVar1 = iVar3 + 1;
      uVar5 = 0;
      pcVar4 = *(char **)(DAT_00428bec + iVar3 * 4);
      if ((*pcVar4 == '-') || (*pcVar4 == '/')) {
        pcVar4 = pcVar4 + 1;
        uVar5 = 1;
      }
      (*pcVar2)(pcVar4,uVar5,iVar1 == DAT_00428be8);
      iVar3 = iVar1;
    } while (iVar1 < DAT_00428be8);
  }
  return;
}



/* VA 0041a197 */

undefined4 * FUN_0041a197(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041d1bc;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040fe73(extraout_ECX + 5);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0040fe73(extraout_ECX + 6);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0040fe73(extraout_ECX + 7);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_0040fe73(extraout_ECX + 8);
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[4] = 0;
  *extraout_ECX = &PTR_LAB_0041dcd4;
  extraout_ECX[1] = 1;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}



/* VA 0041a206 */

undefined * __thiscall FUN_0041a206(void *this,byte param_1)

{
  FUN_0041a222();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 0041a222 */

void FUN_0041a222(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041dcd4;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_0040ff87(extraout_ECX + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0040ff87(extraout_ECX + 7);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0040ff87(extraout_ECX + 6);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0040ff87(extraout_ECX + 5);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d1bc;
  *unaff_FS_OFFSET = uVar1;
  return;
}



/* VA 0041a2a8 */

void __thiscall FUN_0041a2a8(void *this,LPCSTR param_1)

{
  int iVar1;

  iVar1 = lstrcmpA(param_1,"pt");
  if (iVar1 == 0) {
    *(undefined4 *)((int)this + 0x10) = 3;
  }
  else {
    iVar1 = lstrcmpA(param_1,"p");
    if (iVar1 == 0) {
      *(undefined4 *)((int)this + 0x10) = 2;
    }
    else {
      iVar1 = lstrcmpiA(param_1,"Unregister");
      if ((iVar1 != 0) && (iVar1 = lstrcmpiA(param_1,"Unregserver"), iVar1 != 0)) {
        iVar1 = lstrcmpA(param_1,"dde");
        if (iVar1 == 0) {
          FUN_00417aac(0);
          *(undefined4 *)((int)this + 0x10) = 4;
          return;
        }
        iVar1 = lstrcmpiA(param_1,"Embedding");
        if (iVar1 == 0) {
          FUN_00417aac(0);
          *(undefined4 *)((int)this + 8) = 1;
        }
        else {
          iVar1 = lstrcmpiA(param_1,"Automation");
          if (iVar1 != 0) {
            return;
          }
          FUN_00417aac(0);
          *(undefined4 *)((int)this + 0xc) = 1;
        }
        *(undefined4 *)((int)this + 4) = 0;
        return;
      }
      *(undefined4 *)((int)this + 0x10) = 5;
    }
  }
  return;
}



/* VA 0041a366 */

void __thiscall FUN_0041a366(void *this,LPCSTR param_1)

{
  void *this_00;

  this_00 = (void *)((int)this + 0x14);
  if ((*(int *)(*(int *)((int)this + 0x14) + -8) == 0) ||
     ((*(int *)((int)this + 0x10) == 3 &&
      (((this_00 = (void *)((int)this + 0x18), *(int *)(*(int *)((int)this + 0x18) + -8) == 0 ||
        (this_00 = (void *)((int)this + 0x1c), *(int *)(*(int *)((int)this + 0x1c) + -8) == 0)) ||
       (this_00 = (void *)((int)this + 0x20), *(int *)(*(int *)((int)this + 0x20) + -8) == 0)))))) {
    FUN_0040ffdd(this_00,param_1);
  }
  return;
}



/* VA 0041a3b6 */

void __thiscall FUN_0041a3b6(void *this,int param_1)

{
  undefined4 uVar1;

  if (param_1 != 0) {
    if ((*(int *)((int)this + 0x10) == 0) && (*(int *)(*(int *)((int)this + 0x14) + -8) != 0)) {
      *(undefined4 *)((int)this + 0x10) = 1;
    }
    uVar1 = 0;
    if ((*(int *)((int)this + 8) == 0) && (*(int *)((int)this + 0xc) == 0)) {
      uVar1 = 1;
    }
    *(undefined4 *)((int)this + 4) = uVar1;
  }
  return;
}



/* VA 0041a3e5 */

void FUN_0041a3e5(void)

{
  int *piVar1;
  int iVar2;
  CWinThread *this;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(CWinThread **)(unaff_EBP + -0x10) = this;
  *(undefined ***)this = &PTR_LAB_0041dc2c;
  piVar1 = *(int **)(this + 0x80);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(1);
  }
  if (*(int **)(this + 0xa8) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0xa8) + 0x14))(1);
  }
  iVar2 = FUN_00419dc2();
  if (*(char *)(iVar2 + 0x14) == '\0') {
    if (DAT_004287a0 != (int *)0x0) {
      (**(code **)(*DAT_004287a0 + 4))(1);
      DAT_004287a0 = (int *)0x0;
    }
    if (DAT_0042879c != (int *)0x0) {
      (**(code **)(*DAT_0042879c + 4))(1);
      DAT_0042879c = (int *)0x0;
    }
  }
  if (*(HGLOBAL *)(this + 0x94) != (HGLOBAL)0x0) {
    FUN_00411713(*(HGLOBAL *)(this + 0x94));
  }
  if (*(HGLOBAL *)(this + 0x98) != (HGLOBAL)0x0) {
    FUN_00411713(*(HGLOBAL *)(this + 0x98));
  }
  if (*(ATOM *)(this + 0xb0) != 0) {
    GlobalDeleteAtom(*(ATOM *)(this + 0xb0));
  }
  if (*(ATOM *)(this + 0xb2) != 0) {
    GlobalDeleteAtom(*(ATOM *)(this + 0xb2));
  }
  if (*(int **)(this + 0xac) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0xac) + 4))(1);
  }
  iVar2 = FUN_00419dc2();
  if (*(int *)(iVar2 + 0x10) == *(int *)(this + 0x78)) {
    *(undefined4 *)(iVar2 + 0x10) = 0;
  }
  if (*(CWinThread **)(iVar2 + 4) == this) {
    *(undefined4 *)(iVar2 + 4) = 0;
  }
  FUN_00402c80(*(undefined **)(this + 0x78));
  FUN_00402c80(*(undefined **)(this + 0x7c));
  FUN_00402c80(*(undefined **)(this + 0x88));
  FUN_00402c80(*(undefined **)(this + 0x8c));
  FUN_00402c80(*(undefined **)(this + 0x90));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  CWinThread::~CWinThread(this);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 0041a51a */

void __fastcall FUN_0041a51a(void *param_1)

{
  int iVar1;

  if (*(int **)((int)param_1 + 0xa8) != (int *)0x0) {
    (**(code **)(**(int **)((int)param_1 + 0xa8) + 0x10))();
  }
  if (*(int *)((int)param_1 + 0xb4) != 0) {
    iVar1 = FUN_00419dc2();
    FUN_00413858(param_1,"Settings","PreviewPages",*(undefined4 *)(*(int *)(iVar1 + 4) + 0xb4));
  }
  return;
}



/* VA 0041a556 */

undefined4 __fastcall FUN_0041a556(void *param_1)

{
  int iVar1;

  if ((*(int *)((int)param_1 + 0xac) == 0) || (*(int *)(*(int *)((int)param_1 + 0xac) + 0x10) != 5))
  {
    iVar1 = FUN_00419dc2();
    if (*(char *)(iVar1 + 0x14) == '\0') {
      FUN_0041a51a(param_1);
    }
  }
  if (*(code **)((int)param_1 + 0xbc) != (code *)0x0) {
    (**(code **)((int)param_1 + 0xbc))();
  }
  return *(undefined4 *)((int)param_1 + 0x38);
}



/* VA 0041a59c */

void FUN_0041a59c(void)

{
  return;
}



/* VA 0041a59d */

void FUN_0041a59d(void)

{
  FUN_00402fb0(0x41a5a9);
  return;
}



/* VA 0041a5be */

void __thiscall FUN_0041a5be(void *this,int param_1)

{
  *(undefined4 *)(*(int *)((int)this + 4) + param_1) = *(undefined4 *)this;
  *(int *)this = param_1;
  return;
}



/* VA 0041a5d1 */

undefined4 __thiscall FUN_0041a5d1(void *this,int param_1)

{
  int iVar1;
  int iVar2;

  iVar2 = *(int *)this;
  if (iVar2 == 0) {
    return 0;
  }
  if (iVar2 == param_1) {
    *(undefined4 *)this = *(undefined4 *)(*(int *)((int)this + 4) + param_1);
  }
  else {
    if (iVar2 == 0) {
      return 0;
    }
    do {
      iVar1 = *(int *)(iVar2 + *(int *)((int)this + 4));
      if (iVar1 == param_1) break;
      iVar2 = iVar1;
    } while (iVar1 != 0);
    if (iVar2 == 0) {
      return 0;
    }
    *(undefined4 *)(iVar2 + *(int *)((int)this + 4)) =
         *(undefined4 *)(param_1 + *(int *)((int)this + 4));
  }
  return 1;
}



/* VA 0041a61c */

HLOCAL FUN_0041a61c(SIZE_T param_1)

{
  HLOCAL pvVar1;

  pvVar1 = LocalAlloc(0x40,param_1);
  if (pvVar1 == (HLOCAL)0x0) {
    FUN_0040a8cd();
  }
  return pvVar1;
}



/* VA 0041a63a */

void FUN_0041a63a(HLOCAL param_1)

{
  if (param_1 != (HLOCAL)0x0) {
    LocalFree(param_1);
  }
  return;
}



/* VA 0041a64e */

DWORD * __fastcall FUN_0041a64e(DWORD *param_1)

{
  DWORD DVar1;

  param_1[5] = 0;
  param_1[6] = 0;
  param_1[6] = 4;
  param_1[1] = 0;
  param_1[2] = 1;
  param_1[3] = 0;
  param_1[4] = 0;
  DVar1 = TlsAlloc();
  *param_1 = DVar1;
  if (DVar1 == 0xffffffff) {
    FUN_0040a8cd();
  }
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
  return param_1;
}



/* VA 0041a690 */

int __fastcall FUN_0041a690(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar1;
  byte *pbVar2;
  HGLOBAL pvVar3;
  HGLOBAL hMem;
  LPVOID pvVar4;
  int iVar5;
  int iVar6;

  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x1c);
  EnterCriticalSection(lpCriticalSection);
  iVar5 = *(int *)(param_1 + 4);
  iVar6 = *(int *)(param_1 + 8);
  if ((iVar5 <= iVar6) || ((*(byte *)(*(int *)(param_1 + 0x10) + iVar6 * 8) & 1) != 0)) {
    iVar6 = 1;
    if (1 < iVar5) {
      pbVar2 = *(byte **)(param_1 + 0x10);
      do {
        pbVar2 = pbVar2 + 8;
        if ((*pbVar2 & 1) == 0) break;
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar5);
      if (iVar6 < iVar5) goto LAB_0041a774;
    }
    iVar5 = iVar5 + 0x20;
    if (*(LPCVOID *)(param_1 + 0x10) == (LPCVOID)0x0) {
      pvVar3 = GlobalAlloc(0x2002,iVar5 * 8);
    }
    else {
      pvVar3 = GlobalHandle(*(LPCVOID *)(param_1 + 0x10));
      GlobalUnlock(pvVar3);
      pvVar3 = GlobalReAlloc(pvVar3,iVar5 * 8,0x2002);
    }
    if (pvVar3 == (HGLOBAL)0x0) {
      hMem = GlobalHandle(*(LPCVOID *)(param_1 + 0x10));
      GlobalLock(hMem);
      LeaveCriticalSection(lpCriticalSection);
      FUN_0040a8cd();
    }
    pvVar4 = GlobalLock(pvVar3);
    _memset((void *)((int)pvVar4 + *(int *)(param_1 + 4) * 8),0,
            (*(int *)(param_1 + 4) * 0x1fffffff + iVar5) * 8);
    *(int *)(param_1 + 4) = iVar5;
    *(LPVOID *)(param_1 + 0x10) = pvVar4;
  }
LAB_0041a774:
  if (*(int *)(param_1 + 0xc) <= iVar6) {
    *(int *)(param_1 + 0xc) = iVar6 + 1;
  }
  puVar1 = (uint *)(*(int *)(param_1 + 0x10) + iVar6 * 8);
  *puVar1 = *puVar1 | 1;
  *(int *)(param_1 + 8) = iVar6 + 1;
  LeaveCriticalSection(lpCriticalSection);
  return iVar6;
}



/* VA 0041a7a2 */

void __thiscall FUN_0041a7a2(void *this,int param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;

  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
  for (iVar2 = *(int *)((int)this + 0x14); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
    if (param_1 < *(int *)(iVar2 + 8)) {
      puVar3 = *(undefined4 **)(*(int *)(iVar2 + 0xc) + param_1 * 4);
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)(1);
      }
      *(undefined4 *)(*(int *)(iVar2 + 0xc) + param_1 * 4) = 0;
    }
  }
  puVar1 = (uint *)(*(int *)((int)this + 0x10) + param_1 * 8);
  *puVar1 = *puVar1 & 0xfffffffe;
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
  return;
}



/* VA 0041a7ff */

void __thiscall FUN_0041a7ff(void *this,int param_1,int param_2)

{
  undefined4 *lpTlsValue;
  HLOCAL pvVar1;

  lpTlsValue = TlsGetValue(*(DWORD *)this);
  if (lpTlsValue == (undefined4 *)0x0) {
LAB_0041a82f:
    lpTlsValue = FUN_0041a61c(0x10);
    if (lpTlsValue == (undefined4 *)0x0) {
      lpTlsValue = (undefined4 *)0x0;
    }
    else {
      *lpTlsValue = &PTR_FUN_0041dd6c;
    }
    lpTlsValue[2] = 0;
    lpTlsValue[3] = 0;
    FUN_0041a5be((void *)((int)this + 0x14),(int)lpTlsValue);
  }
  else {
    if ((param_1 < (int)lpTlsValue[2]) || (param_2 == 0)) goto LAB_0041a8b9;
    if (lpTlsValue == (undefined4 *)0x0) goto LAB_0041a82f;
  }
  if ((HLOCAL)lpTlsValue[3] == (HLOCAL)0x0) {
    pvVar1 = LocalAlloc(0,*(int *)((int)this + 0xc) << 2);
  }
  else {
    pvVar1 = LocalReAlloc((HLOCAL)lpTlsValue[3],*(int *)((int)this + 0xc) << 2,2);
  }
  lpTlsValue[3] = pvVar1;
  if (pvVar1 == (HLOCAL)0x0) {
    FUN_0040a8cd();
  }
  _memset((void *)(lpTlsValue[3] + lpTlsValue[2] * 4),0,
          (lpTlsValue[2] * 0x3fffffff + *(int *)((int)this + 0xc)) * 4);
  lpTlsValue[2] = *(undefined4 *)((int)this + 0xc);
  TlsSetValue(*(DWORD *)this,lpTlsValue);
LAB_0041a8b9:
  *(int *)(lpTlsValue[3] + param_1 * 4) = param_2;
  return;
}



/* VA 0041a8cd */

undefined4 * __thiscall FUN_0041a8cd(void *this,byte param_1)

{
  FUN_0041a8e8(this);
  if ((param_1 & 1) != 0) {
    FUN_0041a63a(this);
  }
  return this;
}



/* VA 0041a8e8 */

void __fastcall FUN_0041a8e8(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_0041d5ec;
  return;
}



/* VA 0041a8ef */

void __thiscall FUN_0041a8ef(void *this,undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;

  iVar3 = 1;
  bVar2 = true;
  if (1 < (int)param_1[2]) {
    do {
      if ((param_2 == 0) || (*(int *)(*(int *)((int)this + 0x10) + 4 + iVar3 * 8) == param_2)) {
        puVar1 = *(undefined4 **)(param_1[3] + iVar3 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        *(undefined4 *)(param_1[3] + iVar3 * 4) = 0;
      }
      else if (*(int *)(param_1[3] + iVar3 * 4) != 0) {
        bVar2 = false;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1[2]);
  }
  if (bVar2) {
    FUN_0041a5d1((void *)((int)this + 0x14),(int)param_1);
    LocalFree((HLOCAL)param_1[3]);
    if (param_1 != (undefined4 *)0x0) {
      (**(code **)*param_1)(1);
    }
    TlsSetValue(*(DWORD *)this,(LPVOID)0x0);
  }
  return;
}



/* VA 0041a977 */

void __thiscall FUN_0041a977(void *this,int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;

  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
  if (param_2 == 0) {
    puVar2 = TlsGetValue(*(DWORD *)this);
    if (puVar2 != (undefined4 *)0x0) {
      FUN_0041a8ef(this,puVar2,param_1);
    }
  }
  else {
    puVar2 = *(undefined4 **)((int)this + 0x14);
    while (puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)puVar2[1];
      FUN_0041a8ef(this,puVar2,param_1);
      puVar2 = puVar1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x1c));
  return;
}



/* VA 0041a9d0 */

/* WARNING: Removing unreachable block (ram,0x0041a9f7) */

int __thiscall FUN_0041a9d0(void *this,undefined *param_1)

{
  int iVar1;
  LPVOID pvVar2;

  if (*(int *)this == 0) {
    if (DAT_004287a8 == (DWORD *)0x0) {
      DAT_004287a8 = FUN_0041a64e((DWORD *)&DAT_004287b0);
    }
    iVar1 = FUN_0041a690((int)DAT_004287a8);
    *(int *)this = iVar1;
  }
  iVar1 = *(int *)this;
  pvVar2 = TlsGetValue(*DAT_004287a8);
  if ((pvVar2 == (LPVOID)0x0) || (*(int *)((int)pvVar2 + 8) <= iVar1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*(int *)((int)pvVar2 + 0xc) + iVar1 * 4);
  }
  if (iVar1 == 0) {
    iVar1 = (*(code *)param_1)();
    FUN_0041a7ff(DAT_004287a8,*(int *)this,iVar1);
  }
  return iVar1;
}



/* VA 0041aa47 */

void __fastcall FUN_0041aa47(int *param_1)

{
  if ((*param_1 != 0) && (DAT_004287a8 != (void *)0x0)) {
    FUN_0041a7a2(DAT_004287a8,*param_1);
  }
  *param_1 = 0;
  return;
}



/* VA 0041aa65 */

int FUN_0041aa65(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  if (*extraout_ECX == 0) {
    FUN_0041adc3(0x10);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (*extraout_ECX == 0) {
      iVar1 = (**(code **)(unaff_EBP + 8))();
      *extraout_ECX = iVar1;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0041ae33(0x10);
  }
  iVar1 = *extraout_ECX;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return iVar1;
}



/* VA 0041aad0 */

/* Library Function - Single Match
    public: __thiscall CProcessLocalObject::~CProcessLocalObject(void)

   Library: Visual Studio 2012 Release */

void __thiscall CProcessLocalObject::~CProcessLocalObject(CProcessLocalObject *this)

{
  if (*(int *)this != 0) {
    if (*(undefined4 **)this != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)this)(1);
    }
  }
  return;
}



/* VA 0041aaf5 */

void FUN_0041aaf5(int param_1,int param_2)

{
  if (DAT_004287a8 != (void *)0x0) {
    FUN_0041a977(DAT_004287a8,param_1,param_2);
  }
  return;
}



/* VA 0041ab19 */

void FUN_0041ab19(void)

{
  FUN_0041ab8b(0x4287e8);
  return;
}



/* VA 0041ab23 */

void FUN_0041ab23(void)

{
  FUN_00402fb0(0x41ab2f);
  return;
}



/* VA 0041ab39 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041ab39(void)

{
  int iVar1;

  if (DAT_00428844 != 0) {
    iVar1 = GetSystemMetrics(2);
    DAT_004287e8 = iVar1 + 1;
    iVar1 = GetSystemMetrics(3);
    DAT_004287ec = iVar1 + 1;
    _DAT_00428850 = 1;
  }
  return;
}



/* VA 0041ab69 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041ab69(void)

{
  DAT_004287e8 = GetSystemMetrics(2);
  DAT_004287ec = GetSystemMetrics(3);
  _DAT_00428850 = 0;
  return;
}



/* VA 0041ab8b */

int __fastcall FUN_0041ab8b(int param_1)

{
  uint uVar1;
  DWORD DVar2;
  HCURSOR pHVar3;
  int iVar4;

  DVar2 = GetVersion();
  *(DWORD *)(param_1 + 0x54) = (DVar2 & 0xff) * 0x100 + (DVar2 >> 8 & 0xff);
  *(DWORD *)(param_1 + 0x58) = DVar2 >> 0x1f;
  uVar1 = (uint)(3 < (byte)DVar2);
  *(uint *)(param_1 + 0x5c) = uVar1;
  *(uint *)(param_1 + 0x60) = 1 - uVar1;
  *(uint *)(param_1 + 100) = uVar1;
  *(undefined4 *)(param_1 + 0x68) = 0;
  if (uVar1 != 0) {
    DVar2 = GetProcessVersion(0);
    *(uint *)(param_1 + 0x68) = (uint)(0x3ffff < DVar2);
  }
  FUN_00410114(param_1);
  *(undefined4 *)(param_1 + 0x24) = 0;
  FUN_004100d0(param_1);
  pHVar3 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
  *(HCURSOR *)(param_1 + 0x3c) = pHVar3;
  pHVar3 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  *(HCURSOR *)(param_1 + 0x40) = pHVar3;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  iVar4 = (*(int *)(param_1 + 0x5c) != 0) + 1;
  *(int *)(param_1 + 0x10) = iVar4;
  *(int *)(param_1 + 0x14) = iVar4;
  return param_1;
}



/* VA 0041ac3c */

void FUN_0041ac3c(void)

{
  FUN_00401e02(&DAT_00428858,0,0xf023);
  return;
}



/* VA 0041ac4e */

void FUN_0041ac4e(void)

{
  FUN_00402fb0(0x41ac5a);
  return;
}



/* VA 0041ac74 */

void FUN_0041ac74(void)

{
  FUN_00401e2c(&DAT_004288f0,0,0xf021);
  return;
}



/* VA 0041ac86 */

void FUN_0041ac86(void)

{
  FUN_00402fb0(0x41ac92);
  return;
}



/* VA 0041aca2 */

void FUN_0041aca2(void)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0041ce4c;
  pcVar1 = (code *)extraout_ECX[4];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(0);
  }
  if ((HMODULE)extraout_ECX[2] != (HMODULE)0x0) {
    FreeLibrary((HMODULE)extraout_ECX[2]);
  }
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d5ec;
  *unaff_FS_OFFSET = uVar2;
  return;
}



/* VA 0041ace9 */

void FUN_0041ace9(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0041daf4;
  iVar3 = DAT_00428988;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((iVar3 != 0) && (pcVar1 = *(code **)(iVar3 + 0x18), pcVar1 != (code *)0x0)) {
    (*pcVar1)();
  }
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d5ec;
  *unaff_FS_OFFSET = uVar2;
  return;
}



/* VA 0041ad33 */

void FUN_0041ad33(void)

{
  return;
}



/* VA 0041ad34 */

void FUN_0041ad34(void)

{
  FUN_00402fb0(0x41ad40);
  return;
}



/* VA 0041ad59 */

void FUN_0041ad59(void)

{
  return;
}



/* VA 0041ad5a */

void FUN_0041ad5a(void)

{
  FUN_00402fb0(0x41ad66);
  return;
}



/* VA 0041ad75 */

int FUN_0041ad75(void)

{
  DWORD DVar1;

  if (DAT_00428990 == 0) {
    DAT_00428990 = 1;
    DVar1 = GetVersion();
    if (((byte)DVar1 < 4) && ((DVar1 & 0x80000000) != 0)) {
      DAT_00428b30 = 1;
    }
    else {
      DAT_00428b30 = 0;
    }
    if (DAT_00428b30 == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00428b38);
    }
  }
  return DAT_00428990;
}



/* VA 0041adc3 */

void FUN_0041adc3(int param_1)

{
  int *piVar1;

  if (DAT_00428990 == 0) {
    FUN_0041ad75();
  }
  if (DAT_00428b30 == 0) {
    piVar1 = (int *)(&DAT_00428b50 + param_1 * 4);
    if (*(int *)(&DAT_00428b50 + param_1 * 4) == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00428b38);
      if (*piVar1 == 0) {
        InitializeCriticalSection((LPCRITICAL_SECTION)(&DAT_00428998 + param_1 * 0x18));
        *piVar1 = *piVar1 + 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00428b38);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_00428998 + param_1 * 0x18));
  }
  return;
}



/* VA 0041ae33 */

void FUN_0041ae33(int param_1)

{
  if (DAT_00428b30 == 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_00428998 + param_1 * 0x18));
  }
  return;
}



/* VA 0041ae54 */

undefined4 * __fastcall FUN_0041ae54(undefined4 *param_1)

{
  FUN_0040b374(param_1);
  param_1[0x16] = 0;
  param_1[0x11] = 6;
  param_1[0x10] = 6;
  param_1[0x17] = 0;
  param_1[0xf] = 0;
  param_1[8] = 0;
  param_1[0x18] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  *param_1 = &PTR_LAB_0041e174;
  param_1[0x14] = 2;
  param_1[0x13] = 1;
  param_1[0x12] = 1;
  param_1[0x15] = 0x7fff;
  return param_1;
}



/* VA 0041aea6 */

undefined * __thiscall FUN_0041aea6(void *this,byte param_1)

{
  FUN_004129b9();
  if ((param_1 & 1) != 0) {
    FUN_0040f384(this);
  }
  return this;
}



/* VA 0041aec2 */

undefined4 __thiscall FUN_0041aec2(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;

  iVar2 = FUN_0040bd40(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  *(byte *)(param_1 + 0x23) = *(byte *)(param_1 + 0x23) | 4;
  if (DAT_00428844 == 0) {
    return 1;
  }
  uVar1 = *(uint *)((int)this + 100);
  if ((uVar1 & 0x80) != 0) {
    return 1;
  }
  uVar4 = 0;
  uVar3 = uVar1 & 0xff00;
  if (uVar3 != 0x1400) {
    if (uVar3 == 0x2800) {
      uVar4 = 0x200;
      goto LAB_0041af25;
    }
    if (uVar3 != 0x4100) {
      if (uVar3 == 0x8200) {
        uVar4 = 0x800;
      }
      goto LAB_0041af25;
    }
  }
  uVar4 = 0xa00;
LAB_0041af25:
  if (uVar4 != 0) {
    *(uint *)((int)this + 100) = uVar1 & 0xfffff0ff | uVar4 | 0x80;
  }
  return 1;
}



/* VA 0041af3b */

void __thiscall FUN_0041af3b(void *this,uint param_1)

{
  uint uVar1;

  FUN_00402330(this,param_1 & 0x10);
  uVar1 = *(uint *)((int)this + 100);
  if (uVar1 != param_1) {
    *(uint *)((int)this + 100) = param_1;
    (**(code **)(*(int *)this + 0xdc))(uVar1,param_1);
  }
  return;
}



/* VA 0041af6c */

undefined4 __thiscall FUN_0041af6c(void *this,int param_1,int param_2)

{
  int *piVar1;

  piVar1 = (int *)0x0;
  if ((0 < param_1) && (piVar1 = FUN_00404230(param_1,param_2), piVar1 == (int *)0x0)) {
    return 0;
  }
  FUN_00402c80(*(undefined **)((int)this + 0x5c));
  *(int **)((int)this + 0x5c) = piVar1;
  *(int *)((int)this + 0x58) = param_1;
  return 1;
}



/* VA 0041afa5 */

HKEY __fastcall FUN_0041afa5(int param_1)

{
  LSTATUS LVar1;
  DWORD local_14;
  HKEY local_10;
  HKEY local_c;
  HKEY local_8;

  local_10 = (HKEY)0x0;
  local_8 = (HKEY)0x0;
  local_c = (HKEY)0x0;
  LVar1 = RegOpenKeyExA((HKEY)0x80000001,"Software",0,0x2001f,&local_8);
  if (LVar1 == 0) {
    LVar1 = RegCreateKeyExA(local_8,*(LPCSTR *)(param_1 + 0x7c),0,(LPSTR)0x0,0,0x2001f,
                            (LPSECURITY_ATTRIBUTES)0x0,&local_c,&local_14);
    if (LVar1 == 0) {
      RegCreateKeyExA(local_c,*(LPCSTR *)(param_1 + 0x90),0,(LPSTR)0x0,0,0x2001f,
                      (LPSECURITY_ATTRIBUTES)0x0,&local_10,&local_14);
    }
  }
  if (local_8 != (HKEY)0x0) {
    RegCloseKey(local_8);
  }
  if (local_c != (HKEY)0x0) {
    RegCloseKey(local_c);
  }
  return local_10;
}



/* VA 0041b039 */

/* Library Function - Multiple Matches With Same Base Name
    public: struct HKEY__ * __thiscall CWinApp::GetSectionKey(char const *)
    public: struct HKEY__ * __thiscall CWinApp::GetSectionKey(wchar_t const *)

   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release */

HKEY __thiscall GetSectionKey(void *this,LPCSTR param_1)

{
  HKEY hKey;
  void *local_c;
  HKEY local_8;

  local_8 = (HKEY)0x0;
  local_c = this;
  hKey = FUN_0041afa5((int)this);
  if (hKey == (HKEY)0x0) {
    local_8 = (HKEY)0x0;
  }
  else {
    RegCreateKeyExA(hKey,param_1,0,(LPSTR)0x0,0,0x2001f,(LPSECURITY_ATTRIBUTES)0x0,&local_8,
                    (LPDWORD)&local_c);
    RegCloseKey(hKey);
  }
  return local_8;
}



/* VA 0041b07f */

void FUN_0041b07f(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  puVar1 = (undefined4 *)FUN_0040f348(8);
  *(undefined4 **)(unaff_EBP + -0x10) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00401f98(puVar1);
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 0041b0bd */

undefined4 FUN_0041b0bd(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  UINT UVar1;
  int iVar2;

  UVar1 = SetErrorMode(0);
  SetErrorMode(UVar1 | 0x8001);
  iVar2 = FUN_00419dc2();
  *(undefined4 *)(iVar2 + 8) = param_1;
  *(undefined4 *)(iVar2 + 0xc) = param_1;
  iVar2 = FUN_00419dc2();
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x68) = param_1;
    *(undefined4 *)(iVar2 + 0x6c) = param_2;
    *(undefined4 *)(iVar2 + 0x70) = param_3;
    *(undefined4 *)(iVar2 + 0x74) = param_4;
    FUN_0041b120(iVar2);
  }
  iVar2 = FUN_00419dc2();
  if (*(char *)(iVar2 + 0x14) == '\0') {
    FUN_0040f3a4();
  }
  return 1;
}



/* VA 0041b120 */

void __fastcall FUN_0041b120(int param_1)

{
  byte *pbVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  CHAR *pCVar5;
  CHAR local_310 [256];
  byte local_210 [260];
  CHAR local_10c [260];
  byte *local_8;

  iVar2 = FUN_00419dc2();
  *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(param_1 + 0x68);
  GetModuleFileNameA(*(HMODULE *)(param_1 + 0x68),(LPSTR)local_210,0x104);
  local_8 = FUN_00404610(local_210,0x2e);
  *local_8 = 0;
  FUN_0041b23d(local_210,local_10c,0x104);
  if (*(int *)(param_1 + 0x88) == 0) {
    pcVar3 = FUN_00403880(local_10c);
    *(char **)(param_1 + 0x88) = pcVar3;
  }
  if (*(int *)(param_1 + 0x78) == 0) {
    iVar4 = FUN_0040fa52(0xe000,local_310,0x100);
    if (iVar4 == 0) {
      pCVar5 = *(CHAR **)(param_1 + 0x88);
    }
    else {
      pCVar5 = local_310;
    }
    pcVar3 = FUN_00403880(pCVar5);
    *(char **)(param_1 + 0x78) = pcVar3;
  }
  pbVar1 = local_8;
  *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(param_1 + 0x78);
  if (*(int *)(param_1 + 0x8c) == 0) {
    lstrcpyA((LPSTR)local_8,".HLP");
    pcVar3 = FUN_00403880((char *)local_210);
    *(char **)(param_1 + 0x8c) = pcVar3;
    *pbVar1 = 0;
  }
  if (*(int *)(param_1 + 0x90) == 0) {
    lstrcatA(local_10c,".INI");
    pcVar3 = FUN_00403880(local_10c);
    *(char **)(param_1 + 0x90) = pcVar3;
  }
  return;
}



/* VA 0041b23d */

int FUN_0041b23d(byte *param_1,LPSTR param_2,int param_3)

{
  byte bVar1;
  byte *lpString2;
  int iVar2;

  lpString2 = param_1;
  for (; *param_1 != 0; param_1 = FUN_004045f0(param_1)) {
    bVar1 = *param_1;
    if (((bVar1 == 0x5c) || (bVar1 == 0x2f)) || (bVar1 == 0x3a)) {
      lpString2 = FUN_004045f0(param_1);
    }
  }
  if (param_2 == (LPSTR)0x0) {
    iVar2 = lstrlenA((LPCSTR)lpString2);
    iVar2 = iVar2 + 1;
  }
  else {
    lstrcpynA(param_2,(LPCSTR)lpString2,param_3);
    iVar2 = 0;
  }
  return iVar2;
}



/* VA 0041b31b */

/* Library Function - Single Match
    public: virtual __thiscall CWinThread::~CWinThread(void)

   Library: Visual Studio 2003 Release */

void __thiscall CWinThread::~CWinThread(CWinThread *this)

{
  HANDLE hObject;
  AFX_MODULE_THREAD_STATE *pAVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_0041da6c;
  hObject = (HANDLE)extraout_ECX[10];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (hObject != (HANDLE)0x0) {
    CloseHandle(hObject);
  }
  pAVar1 = AfxGetModuleThreadState();
  if (*(undefined4 **)(pAVar1 + 4) == extraout_ECX) {
    *(undefined4 *)(pAVar1 + 4) = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0040edca();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}



/* VA 0041b36a */

void FUN_0041b36a(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;

  FUN_00402bc0();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0041dc24;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00411683(extraout_ECX + 1);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_0041d5ec;
  *unaff_FS_OFFSET = uVar1;
  return;
}



/* VA 0041b3a1 */

/* Library Function - Single Match
    void __stdcall AfxPostQuitMessage(int)

   Library: Visual Studio 1998 Release */

void AfxPostQuitMessage(int param_1)

{
  CWinThread *pCVar1;

  pCVar1 = AfxGetThread();
  if ((pCVar1 != (CWinThread *)0x0) && (*(code **)(pCVar1 + 0x54) != (code *)0x0)) {
    (**(code **)(pCVar1 + 0x54))(1,1);
  }
  PostQuitMessage(param_1);
  return;
}



/* VA 0041b3ce */

void FUN_0041b3ce(void)

{
  code *pcVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *lpClassName;

  iVar2 = FUN_00419dc2();
  FUN_0041adc3(1);
  lpClassName = (byte *)(iVar2 + 0x34);
  while (*lpClassName != 0) {
    pbVar3 = FUN_00403240(lpClassName,10);
    *pbVar3 = 0;
    iVar4 = FUN_00419dc2();
    UnregisterClassA((LPCSTR)lpClassName,*(HINSTANCE *)(iVar4 + 8));
    lpClassName = pbVar3 + 1;
  }
  *(byte *)(iVar2 + 0x34) = 0;
  FUN_0041ae33(1);
  iVar2 = FUN_00419dc2();
  if ((*(int *)(iVar2 + 4) != 0) &&
     (pcVar1 = *(code **)(*(int *)(iVar2 + 4) + 0x54), pcVar1 != (code *)0x0)) {
    (*pcVar1)(1,0);
  }
  iVar2 = FUN_00419a6f();
  if (*(int **)(iVar2 + 0xcc) != (int *)0x0) {
    iVar4 = FUN_00402218(*(int **)(iVar2 + 0xcc));
    if (iVar4 != 0) {
      *(undefined4 *)(iVar2 + 0xcc) = 0;
    }
  }
  iVar4 = FUN_00419dc2();
  if (*(char *)(iVar4 + 0x14) == '\0') {
    if (*(HHOOK *)(iVar2 + 0x30) != (HHOOK)0x0) {
      UnhookWindowsHookEx(*(HHOOK *)(iVar2 + 0x30));
      *(undefined4 *)(iVar2 + 0x30) = 0;
    }
    if (*(HHOOK *)(iVar2 + 0x2c) != (HHOOK)0x0) {
      UnhookWindowsHookEx(*(HHOOK *)(iVar2 + 0x2c));
      *(undefined4 *)(iVar2 + 0x2c) = 0;
    }
  }
  return;
}
