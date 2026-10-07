/* AUTOMATIC GHIDRA PSEUDO-C. NOT A COMPILABLE RECOVERED SOURCE TREE.
   Original SHA256 8149374c3806c5420635f150f561de0a849f891add4d24bcf967d5d60f0e312e */

/* VA 00401000 */

undefined4 * __thiscall FUN_00401000(void *this,byte param_1)

{
  FUN_00403569(this);
  if ((param_1 & 1) != 0) {
    FUN_00401a7e(this);
  }
  return this;
}



/* VA 00401022 */

undefined4 * __thiscall FUN_00401022(void *this,byte param_1)

{
  FUN_00401d62(this);
  if ((param_1 & 1) != 0) {
    FUN_00401a7e(this);
  }
  return this;
}



/* VA 00401044 */

void __thiscall
FUN_00401044(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *this_00;

  if (*(int *)((int)this + 0x14) == 0) {
    *(undefined4 *)((int)this + 0xc) = param_1;
    *(undefined4 *)((int)this + 0x10) = param_2;
    *(undefined4 *)this = 1;
    *(undefined4 *)((int)this + 4) = param_4;
  }
  else {
    this_00 = *(void **)((int)this + 8);
    if (this_00 == (void *)0x0) {
      this_00 = operator_new(0x18);
      if (this_00 == (void *)0x0) {
        this_00 = (void *)0x0;
      }
      else {
        *(undefined4 *)((int)this_00 + 0xc) = 0;
        *(undefined4 *)((int)this_00 + 0x10) = 0;
        *(undefined4 *)((int)this_00 + 8) = 0;
        *(undefined4 *)((int)this_00 + 0x14) = 0;
      }
      *(void **)((int)this + 8) = this_00;
    }
    FUN_00401044(this_00,param_1,param_2,1,param_4);
  }
  *(int *)((int)this + 0x14) = *(int *)((int)this + 0x14) + 1;
  return;
}



/* VA 004010ae */

void __fastcall FUN_004010ae(int param_1)

{
  void *pvVar1;

  pvVar1 = *(void **)(param_1 + 8);
  if (pvVar1 != (void *)0x0) {
    FUN_004010ae((int)pvVar1);
    FUN_00401a7e(pvVar1);
  }
  return;
}



/* VA 004010c9 */

void __fastcall FUN_004010c9(int param_1,void *param_2)

{
  void *pvVar1;
  void *this;
  char *pcVar2;
  int *piVar3;

  pvVar1 = operator_new(0x18);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar1 + 0xc) = 0;
    *(undefined4 *)((int)pvVar1 + 0x10) = 0;
    *(undefined4 *)((int)pvVar1 + 8) = 0;
    *(undefined4 *)((int)pvVar1 + 0x14) = 0;
  }
  *(void **)(param_1 + 0x214) = pvVar1;
  pvVar1 = (void *)FUN_00407b17(param_2,"base");
  if (pvVar1 == (void *)0x0) {
    return;
  }
  this = (void *)FUN_00407b17(pvVar1,"property");
  do {
    while( true ) {
      if (this == (void *)0x0) {
        return;
      }
      pcVar2 = (char *)FUN_00407b6d(this,"name");
      if (pcVar2 != (char *)0x0) break;
LAB_00401175:
      this = (void *)FUN_00407612(this,"property");
    }
    if (*pcVar2 != '\0') {
      piVar3 = FUN_00403178(this,param_1 + 0x108,param_1,0);
      pcVar2 = _strdup(pcVar2);
      FUN_004014c6(*(void **)(param_1 + 0x214),pcVar2,piVar3);
    }
    if (this != (void *)0x0) goto LAB_00401175;
    this = (void *)FUN_00407643(pvVar1,"property");
  } while( true );
}



/* VA 0040118b */

void __fastcall
FUN_0040118b(int param_1,void *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;

  pvVar1 = operator_new(0x10);
  puVar3 = (undefined4 *)0x0;
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar1 + 8) = 0;
    *(undefined4 *)((int)pvVar1 + 4) = 0;
    *(undefined4 *)((int)pvVar1 + 0xc) = 0;
  }
  *(void **)(param_1 + 0x218) = pvVar1;
  puVar2 = operator_new(0x20);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = FUN_004030aa(puVar2);
  }
  puVar2[4] = param_3;
  FUN_00401456(*(void **)(param_1 + 0x218),puVar2);
  puVar2 = operator_new(0x20);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = FUN_004030aa(puVar2);
  }
  puVar2[4] = param_4;
  FUN_00401456(*(void **)(param_1 + 0x218),puVar2);
  puVar2 = operator_new(0x20);
  if (puVar2 != (undefined4 *)0x0) {
    puVar3 = FUN_004030aa(puVar2);
  }
  puVar3[4] = param_5;
  FUN_00401456(*(void **)(param_1 + 0x218),puVar3);
  FUN_00403117(param_1,param_2,param_1 + 0x108,*(void **)(param_1 + 0x218));
  return;
}



/* VA 00401250 */

void __fastcall
FUN_00401250(int param_1,void *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  void *pvVar1;
  int iVar2;
  void *this;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char local_110 [260];
  void *local_c;
  int local_8;

  local_8 = param_1;
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar1 + 8) = 0;
    *(undefined4 *)((int)pvVar1 + 4) = 0;
    *(undefined4 *)((int)pvVar1 + 0xc) = 0;
  }
  *(void **)(param_1 + 0x220) = pvVar1;
  pvVar1 = (void *)FUN_00407b17(param_2,"thrash");
  local_c = pvVar1;
  iVar2 = FUN_00407b6d(pvVar1,"dir");
  sprintf(local_110,"%s\\%s",param_3,iVar2);
  if (pvVar1 != (void *)0x0) {
    pvVar1 = (void *)FUN_00407b17(pvVar1,"driver");
    while (pvVar1 != (void *)0x0) {
      this = operator_new(0x324);
      if (this == (void *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = FUN_00402651(this,local_8,pvVar1,local_110,local_110);
      }
      puVar4 = operator_new(0x20);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        puVar4 = FUN_004030aa(puVar4);
      }
      puVar4[4] = param_4;
      FUN_00401456((void *)puVar3[199],puVar4);
      puVar4 = operator_new(0x20);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        puVar4 = FUN_004030aa(puVar4);
      }
      puVar4[4] = param_5;
      FUN_00401456((void *)puVar3[199],puVar4);
      puVar4 = operator_new(0x20);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        puVar4 = FUN_004030aa(puVar4);
      }
      puVar4[4] = param_6;
      FUN_00401456((void *)puVar3[199],puVar4);
      FUN_00401456(*(void **)(local_8 + 0x220),puVar3);
      if (pvVar1 == (void *)0x0) {
        pvVar1 = (void *)FUN_00407643(local_c,"driver");
      }
      else {
        pvVar1 = (void *)FUN_00407612(pvVar1,"driver");
      }
    }
  }
  return;
}



/* VA 004013aa */

void __fastcall FUN_004013aa(int param_1,void *param_2)

{
  void *pvVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 extraout_ECX;

  pvVar1 = operator_new(0x18);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar1 + 0xc) = 0;
    *(undefined4 *)((int)pvVar1 + 0x10) = 0;
    *(undefined4 *)((int)pvVar1 + 8) = 0;
    *(undefined4 *)((int)pvVar1 + 0x14) = 0;
  }
  *(void **)(param_1 + 0x228) = pvVar1;
  pvVar1 = (void *)FUN_00407b17(param_2,"messages");
  if (pvVar1 != (void *)0x0) {
    for (pvVar1 = (void *)FUN_00407b17(pvVar1,"item"); pvVar1 != (void *)0x0;
        pvVar1 = (void *)FUN_00407612(pvVar1,"item")) {
      pcVar2 = (char *)FUN_00407b6d(pvVar1,"key");
      pcVar2 = _strdup(pcVar2);
      pcVar3 = FUN_00403472(pvVar1,*(char **)(param_1 + 0x210),(char *)0x0);
      pcVar3 = _strdup(pcVar3);
      FUN_00401044(*(void **)(param_1 + 0x228),pcVar2,pcVar3,extraout_ECX,1);
    }
  }
  return;
}



/* VA 00401456 */

void __thiscall FUN_00401456(void *this,undefined4 param_1)

{
  void *this_00;

  if (*(int *)((int)this + 0xc) == 0) {
    *(undefined4 *)((int)this + 8) = param_1;
    *(undefined4 *)this = 2;
  }
  else {
    this_00 = *(void **)((int)this + 4);
    if (this_00 == (void *)0x0) {
      this_00 = operator_new(0x10);
      if (this_00 == (void *)0x0) {
        this_00 = (void *)0x0;
      }
      else {
        *(undefined4 *)((int)this_00 + 8) = 0;
        *(undefined4 *)((int)this_00 + 4) = 0;
        *(undefined4 *)((int)this_00 + 0xc) = 0;
      }
      *(void **)((int)this + 4) = this_00;
    }
    FUN_00401456(this_00,param_1);
  }
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
  return;
}



/* VA 004014ab */

void __fastcall FUN_004014ab(int param_1)

{
  void *pvVar1;

  pvVar1 = *(void **)(param_1 + 4);
  if (pvVar1 != (void *)0x0) {
    FUN_004014ab((int)pvVar1);
    FUN_00401a7e(pvVar1);
  }
  return;
}



/* VA 004014c6 */

void __thiscall FUN_004014c6(void *this,undefined4 param_1,undefined4 param_2)

{
  void *this_00;

  if (*(int *)((int)this + 0x14) == 0) {
    *(undefined4 *)((int)this + 0xc) = param_1;
    *(undefined4 *)((int)this + 0x10) = param_2;
    *(undefined4 *)this = 1;
    *(undefined4 *)((int)this + 4) = 2;
  }
  else {
    this_00 = *(void **)((int)this + 8);
    if (this_00 == (void *)0x0) {
      this_00 = operator_new(0x18);
      if (this_00 == (void *)0x0) {
        this_00 = (void *)0x0;
      }
      else {
        *(undefined4 *)((int)this_00 + 0xc) = 0;
        *(undefined4 *)((int)this_00 + 0x10) = 0;
        *(undefined4 *)((int)this_00 + 8) = 0;
        *(undefined4 *)((int)this_00 + 0x14) = 0;
      }
      *(void **)((int)this + 8) = this_00;
    }
    FUN_004014c6(this_00,param_1,param_2);
  }
  *(int *)((int)this + 0x14) = *(int *)((int)this + 0x14) + 1;
  return;
}



/* VA 00401530 */

void __thiscall FUN_00401530(void *this,undefined4 param_1)

{
  void *this_00;

  if (*(int *)((int)this + 0xc) == 0) {
    *(undefined4 *)((int)this + 8) = param_1;
    *(undefined4 *)this = 1;
  }
  else {
    this_00 = *(void **)((int)this + 4);
    if (this_00 == (void *)0x0) {
      this_00 = operator_new(0x10);
      if (this_00 == (void *)0x0) {
        this_00 = (void *)0x0;
      }
      else {
        *(undefined4 *)((int)this_00 + 8) = 0;
        *(undefined4 *)((int)this_00 + 4) = 0;
        *(undefined4 *)((int)this_00 + 0xc) = 0;
      }
      *(void **)((int)this + 4) = this_00;
    }
    FUN_00401530(this_00,param_1);
  }
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
  return;
}



/* VA 00401585 */

undefined4 * __thiscall FUN_00401585(void *this,byte param_1)

{
  FUN_00403569(this);
  if ((param_1 & 1) != 0) {
    FUN_00401a7e(this);
  }
  return this;
}



/* VA 004015a7 */

undefined4 * __thiscall FUN_004015a7(void *this,byte param_1)

{
  FUN_00403569(this);
  if ((param_1 & 1) != 0) {
    FUN_00401a7e(this);
  }
  return this;
}



/* VA 004015c9 */

undefined4 * __thiscall FUN_004015c9(void *this,byte param_1)

{
  FUN_00403041(this);
  if ((param_1 & 1) != 0) {
    FUN_00401a7e(this);
  }
  return this;
}



/* VA 004015eb */

undefined4 * __thiscall FUN_004015eb(void *this,byte param_1)

{
  FUN_00403569(this);
  if ((param_1 & 1) != 0) {
    FUN_00401a7e(this);
  }
  return this;
}



/* VA 0040160d */

undefined4 * __thiscall FUN_0040160d(void *this,byte param_1)

{
  FUN_004037d2(this);
  if ((param_1 & 1) != 0) {
    FUN_00401a7e(this);
  }
  return this;
}



/* VA 00401635 */

undefined4 * __thiscall FUN_00401635(void *this,byte param_1)

{
  *(undefined ***)this = &PTR_FUN_0040a654;
  FUN_00407881(this);
  if ((param_1 & 1) != 0) {
    FUN_00401a7e(this);
  }
  return this;
}



/* VA 0040165d */

void * __fastcall FUN_0040165d(void *param_1)

{
  FUN_004014ab((int)param_1);
  FUN_00401a7e(param_1);
  return param_1;
}



/* VA 00401675 */

void __thiscall FUN_00401675(void *this,undefined4 param_1)

{
  void *this_00;

  if (*(int *)((int)this + 0xc) == 0) {
    *(undefined4 *)((int)this + 8) = param_1;
    *(undefined4 *)this = 0;
  }
  else {
    this_00 = *(void **)((int)this + 4);
    if (this_00 == (void *)0x0) {
      this_00 = operator_new(0x10);
      if (this_00 == (void *)0x0) {
        this_00 = (void *)0x0;
      }
      else {
        *(undefined4 *)((int)this_00 + 8) = 0;
        *(undefined4 *)((int)this_00 + 4) = 0;
        *(undefined4 *)((int)this_00 + 0xc) = 0;
      }
      *(void **)((int)this + 4) = this_00;
    }
    FUN_00401675(this_00,param_1);
  }
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
  return;
}



/* VA 004016c5 */

void __thiscall FUN_004016c5(void *this,undefined4 param_1,undefined4 param_2)

{
  void *this_00;

  if (*(int *)((int)this + 0x14) == 0) {
    *(undefined4 *)((int)this + 0xc) = param_1;
    *(undefined4 *)((int)this + 0x10) = param_2;
    *(undefined4 *)this = 0;
    *(undefined4 *)((int)this + 4) = 0;
  }
  else {
    this_00 = *(void **)((int)this + 8);
    if (this_00 == (void *)0x0) {
      this_00 = operator_new(0x18);
      if (this_00 == (void *)0x0) {
        this_00 = (void *)0x0;
      }
      else {
        *(undefined4 *)((int)this_00 + 0xc) = 0;
        *(undefined4 *)((int)this_00 + 0x10) = 0;
        *(undefined4 *)((int)this_00 + 8) = 0;
        *(undefined4 *)((int)this_00 + 0x14) = 0;
      }
      *(void **)((int)this + 8) = this_00;
    }
    FUN_004016c5(this_00,param_1,param_2);
  }
  *(int *)((int)this + 0x14) = *(int *)((int)this + 0x14) + 1;
  return;
}



/* VA 00401725 */

int * __thiscall FUN_00401725(void *this,char *param_1)

{
  size_t sVar1;

  *(undefined4 *)this = 0;
  sVar1 = strlen(param_1);
  FUN_0040175c(this,sVar1,sVar1);
  memcpy(*(size_t **)this + 2,param_1,**(size_t **)this);
  return this;
}



/* VA 0040175c */

void __thiscall FUN_0040175c(void *this,int param_1,int param_2)

{
  int *piVar1;

  if (param_2 == 0) {
    *(undefined4 **)this = &DAT_0040c0f0;
  }
  else {
    piVar1 = (int *)FUN_00401a9c(param_2 + 0xfU & 0xfffffffc);
    *(int **)this = piVar1;
    *piVar1 = param_1;
    *(undefined1 *)(*(int *)this + 8 + param_1) = 0;
    *(int *)(*(int *)this + 4) = param_2;
  }
  return;
}



/* VA 004017a6 */

undefined4 * __thiscall FUN_004017a6(void *this,byte param_1)

{
  *(undefined ***)this = &PTR_FUN_0040aa88;
  if ((param_1 & 1) != 0) {
    FUN_00401a7e(this);
  }
  return this;
}



/* VA 004017c9 */

undefined4 * __fastcall FUN_004017c9(undefined4 *param_1)

{
  param_1[2] = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[5] = &DAT_0040c0f0;
  param_1[6] = &DAT_0040c0f0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_0040a88c;
  param_1[4] = 0;
  param_1[8] = 0;
  param_1[7] = 0;
  return param_1;
}



/* VA 004017f3 */

void __thiscall FUN_004017f3(void *this,FILE *param_1)

{
  FUN_00406fc8(this,param_1,this,(void *)0x0);
  return;
}



/* VA 00401805 */

undefined4 * __thiscall FUN_00401805(void *this,byte param_1)

{
  FUN_00401827(this);
  if ((param_1 & 1) != 0) {
    FUN_00401a7e(this);
  }
  return this;
}



/* VA 00401827 */

void __fastcall FUN_00401827(undefined4 *param_1)

{
  if ((undefined4 *)param_1[6] != &DAT_0040c0f0) {
    free((void *)param_1[6]);
  }
  if ((undefined4 *)param_1[5] != &DAT_0040c0f0) {
    free((void *)param_1[5]);
  }
  *param_1 = &PTR_FUN_0040aa88;
  return;
}



/* VA 00401855 */

undefined4 * __thiscall FUN_00401855(void *this,byte param_1)

{
  *(undefined ***)this = &PTR_FUN_0040a898;
  FUN_00407881(this);
  if ((param_1 & 1) != 0) {
    FUN_00401a7e(this);
  }
  return this;
}



/* VA 0040187d */

undefined4 * __fastcall FUN_0040187d(undefined4 *param_1)

{
  undefined4 *puVar1;

  FUN_0040772e(param_1,4);
  *param_1 = &PTR__scalar_deleting_destructor__0040a7c0;
  puVar1 = (undefined4 *)strlen("");
  FUN_00408f82(param_1 + 8,&DAT_0040a2a2,puVar1);
  *(undefined1 *)(param_1 + 0xb) = 0;
  return param_1;
}



/* VA 004018b0 */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCRibbonInfo::XElementSeparator::`scalar deleting
   destructor'(unsigned int)

   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCRibbonInfo::XElementSeparator::_scalar_deleting_destructor_
          (XElementSeparator *this,uint param_1)

{
  *(undefined ***)this = &PTR__scalar_deleting_destructor__0040a7c0;
  FUN_00407881((undefined4 *)this);
  if ((param_1 & 1) != 0) {
    FUN_00401a7e(this);
  }
  return this;
}



/* VA 004018d8 */

void __fastcall FUN_004018d8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0040a8dc;
  if ((undefined4 *)param_1[0xd] != &DAT_0040c0f0) {
    free((void *)param_1[0xd]);
  }
  if ((undefined4 *)param_1[0xc] != &DAT_0040c0f0) {
    free((void *)param_1[0xc]);
  }
  if ((undefined4 *)param_1[0xb] != &DAT_0040c0f0) {
    free((void *)param_1[0xb]);
  }
  FUN_00407881(param_1);
  return;
}



/* VA 0040191a */

void __thiscall FUN_0040191a(void *this,undefined4 param_1,undefined4 param_2)

{
  (**(code **)(*(int *)this + 0x44))(param_1,param_2,0);
  return;
}



/* VA 0040192e */

undefined4 * __thiscall FUN_0040192e(void *this,byte param_1)

{
  FUN_004018d8(this);
  if ((param_1 & 1) != 0) {
    FUN_00401a7e(this);
  }
  return this;
}



/* VA 00401950 */

undefined4 * __thiscall FUN_00401950(void *this,byte param_1)

{
  *(undefined ***)this = &PTR_FUN_0040aa44;
  FUN_00407881(this);
  if ((param_1 & 1) != 0) {
    FUN_00401a7e(this);
  }
  return this;
}



/* VA 00401978 */

void __fastcall FUN_00401978(int param_1)

{
  int iVar1;

  iVar1 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      FUN_00408f33((void *)(param_1 + 0xc),*(size_t **)(param_1 + 0x10) + 2,
                   **(size_t **)(param_1 + 0x10));
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 4));
  }
  return;
}



/* VA 0040199f */

undefined4 * __thiscall FUN_0040199f(void *this,byte param_1)

{
  FUN_00407881(this);
  if ((param_1 & 1) != 0) {
    FUN_00401a7e(this);
  }
  return this;
}



/* VA 004019c1 */

undefined4 * __thiscall FUN_004019c1(void *this,byte param_1)

{
  FUN_00407591(this);
  if ((param_1 & 1) != 0) {
    FUN_00401a7e(this);
  }
  return this;
}



/* VA 004019e3 */

undefined4 __fastcall FUN_004019e3(byte param_1)

{
  int iVar1;

  iVar1 = isspace((uint)param_1);
  if (((iVar1 == 0) && (param_1 != 10)) && (param_1 != 0xd)) {
    return 0;
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}



/* VA 00401a07 */

byte * __fastcall FUN_00401a07(byte *param_1,byte *param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;

  if (param_4 == 1) {
    iVar1 = (int)(char)(&DAT_0040a940)[*param_1];
    *param_3 = iVar1;
    if (iVar1 != 1) {
      if (iVar1 == 0) {
        return (byte *)0x0;
      }
      iVar2 = 0;
      if (*param_1 != 0) {
        pbVar3 = param_1;
        do {
          if (iVar1 <= iVar2) break;
          iVar2 = iVar2 + 1;
          pbVar3[(int)param_2 - (int)param_1] = *pbVar3;
          pbVar3 = pbVar3 + 1;
        } while (*pbVar3 != 0);
      }
      return param_1 + iVar1;
    }
  }
  else {
    *param_3 = 1;
  }
  if (*param_1 == 0x26) {
    pbVar3 = FUN_00407f72(param_1,param_2,param_3,param_4);
  }
  else {
    *param_2 = *param_1;
    pbVar3 = param_1 + 1;
  }
  return pbVar3;
}



/* VA 00401a72 */

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;

                    /* WARNING: Could not recover jumptable at 0x00401a72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = operator_new(param_1);
  return pvVar1;
}



/* VA 00401a78 */

void __cdecl free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x00401a78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(_Memory);
  return;
}



/* VA 00401a7e */

void __cdecl FUN_00401a7e(void *param_1)

{
  free(param_1);
  return;
}



/* VA 00401a8c */

void __cdecl free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x00401a78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(_Memory);
  return;
}



/* VA 00401a97 */

void __cdecl free(void *_Memory)

{
                    /* WARNING: Could not recover jumptable at 0x00401a78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  free(_Memory);
  return;
}



/* VA 00401a9c */

void __cdecl FUN_00401a9c(uint param_1)

{
  operator_new(param_1);
  return;
}



/* VA 00401aa5 */

void __thiscall FUN_00401aa5(void *this,int param_1)

{
  char cVar1;
  byte bVar2;
  byte extraout_CH;
  byte extraout_CH_00;
  undefined4 extraout_ECX;
  uint uVar3;
  undefined4 extraout_ECX_00;
  byte *pbVar4;
  size_t _Size;
  int iVar5;
  byte local_c [7];
  byte local_5;

  iVar5 = 0;
  pbVar4 = DAT_0040c084;
  if (param_1 != 0) {
    do {
      param_1 = param_1 + -1;
      local_c[iVar5] = *pbVar4;
      bVar2 = local_c[0];
      iVar5 = iVar5 + 1;
      pbVar4 = pbVar4 + 1;
      local_5 = local_c[2];
      if (iVar5 == 3) {
        iVar5 = 0;
        cVar1 = FUN_00401bc4(local_c[0] >> 2);
        *(char *)this = cVar1;
        uVar3 = CONCAT31((int3)((uint)extraout_ECX >> 8),bVar2) & 0xffffff03;
        cVar1 = FUN_00401bc4((char)uVar3 * '\x10' + ((byte)(uVar3 >> 8) >> 4));
        *(char *)((int)this + 1) = cVar1;
        cVar1 = FUN_00401bc4((extraout_CH & 0xf) * '\x04' + (local_5 >> 6));
        *(char *)((int)this + 2) = cVar1;
        cVar1 = FUN_00401bc4(local_5 & 0x3f);
        *(char *)((int)this + 3) = cVar1;
        this = (void *)((int)this + 4);
      }
    } while (param_1 != 0);
    if (iVar5 != 0) {
      _Size = 3 - iVar5;
      if (iVar5 < 3) {
        memset(local_c + iVar5,0,_Size);
        local_5 = local_c[2];
        bVar2 = local_c[0];
      }
      cVar1 = FUN_00401bc4(bVar2 >> 2);
      *(char *)this = cVar1;
      uVar3 = CONCAT31((int3)((uint)extraout_ECX_00 >> 8),bVar2) & 0xffffff03;
      cVar1 = FUN_00401bc4((char)uVar3 * '\x10' + ((byte)(uVar3 >> 8) >> 4));
      *(char *)((int)this + 1) = cVar1;
      cVar1 = FUN_00401bc4((extraout_CH_00 & 0xf) * '\x04' + (local_5 >> 6));
      *(char *)((int)this + 2) = cVar1;
      this = (void *)((int)this + 3);
      if (iVar5 < 3) {
        memset(this,0x3d,_Size);
        this = (void *)((int)this + _Size);
      }
    }
  }
  *(char *)this = '\0';
  return;
}



/* VA 00401bc4 */

char __fastcall FUN_00401bc4(byte param_1)

{
  char cVar1;

  cVar1 = (param_1 != 0x3e) * '\x04' + '+';
  if (param_1 < 0x3e) {
    cVar1 = -4;
  }
  if (param_1 < 0x34) {
    cVar1 = 'G';
  }
  if (param_1 < 0x1a) {
    cVar1 = 'A';
  }
  return cVar1 + param_1;
}



/* VA 00401bf7 */

undefined4 __thiscall FUN_00401bf7(void *this,LPCSTR param_1)

{
  LPCSTR lpString;
  BOOL BVar1;

  if (*(int *)((int)this + 0x20) != *(int *)((int)this + 0x1c)) {
    lpString = "1";
    if (*(int *)((int)this + 0x20) == 0) {
      lpString = "0";
    }
    BVar1 = WritePrivateProfileStringA
                      (*(LPCSTR *)((int)this + 8),*(LPCSTR *)((int)this + 0xc),lpString,param_1);
    if (BVar1 == 0) {
      return 0;
    }
    *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)((int)this + 0x20);
  }
  return 1;
}



/* VA 00401c36 */

undefined4 __thiscall FUN_00401c36(void *this,LPCSTR param_1)

{
  UINT UVar1;

  UVar1 = GetPrivateProfileIntA(*(LPCSTR *)((int)this + 8),*(LPCSTR *)((int)this + 0xc),0,param_1);
  *(UINT *)((int)this + 0x20) = UVar1;
  *(UINT *)((int)this + 0x1c) = UVar1;
  return 1;
}



/* VA 00401c5b */

undefined4 * __thiscall FUN_00401c5b(void *this,int param_1)

{
  FUN_00403637(this,param_1);
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined ***)this = &PTR_FUN_0040a198;
  return this;
}



/* VA 00401c7e */

undefined4 * __thiscall FUN_00401c7e(void *this,void *param_1,int param_2)

{
  FUN_004035ac(this,param_1,param_2);
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined ***)this = &PTR_FUN_0040a198;
  *(undefined4 *)((int)this + 4) = 4;
  return this;
}



/* VA 00401cab */

undefined4 __thiscall FUN_00401cab(void *this,LPCSTR param_1)

{
  int iVar1;
  BOOL BVar2;
  char *pcVar3;

  pcVar3 = *(char **)((int)this + 0x1c);
  if ((*(char **)((int)this + 0x20) != pcVar3) &&
     ((pcVar3 == (char *)0x0 || (iVar1 = strcmp(*(char **)((int)this + 0x20),pcVar3), iVar1 != 0))))
  {
    BVar2 = WritePrivateProfileStringA
                      (*(LPCSTR *)((int)this + 8),*(LPCSTR *)((int)this + 0xc),
                       *(LPCSTR *)((int)this + 0x20),param_1);
    if (BVar2 == 0) {
      return 0;
    }
    if (*(int *)((int)this + 0x1c) != 0) {
      free(*(void **)((int)this + 0x1c));
    }
    pcVar3 = _strdup(*(char **)((int)this + 0x20));
    *(char **)((int)this + 0x1c) = pcVar3;
  }
  return 1;
}



/* VA 00401d08 */

DWORD __thiscall FUN_00401d08(void *this,LPCSTR param_1)

{
  DWORD DVar1;
  char *pcVar2;
  CHAR local_104 [256];

  DVar1 = GetPrivateProfileStringA
                    (*(LPCSTR *)((int)this + 8),*(LPCSTR *)((int)this + 0xc),(LPCSTR)0x0,local_104,
                     0x100,param_1);
  if (DVar1 != 0) {
    pcVar2 = _strdup(local_104);
    *(char **)((int)this + 0x20) = pcVar2;
    pcVar2 = _strdup(local_104);
    *(char **)((int)this + 0x1c) = pcVar2;
  }
  return DVar1;
}



/* VA 00401d62 */

void __fastcall FUN_00401d62(undefined4 *param_1)

{
  void *pvVar1;

  pvVar1 = (void *)param_1[9];
  *param_1 = &PTR_FUN_0040a1d4;
  if (pvVar1 != (void *)0x0) {
    FUN_004010ae((int)pvVar1);
    FUN_00401a7e(pvVar1);
  }
  if (param_1[8] != 0) {
    free((void *)param_1[8]);
  }
  if (param_1[7] != 0) {
    free((void *)param_1[7]);
  }
  FUN_00403569(param_1);
  return;
}



/* VA 00401dab */

undefined4 * __thiscall FUN_00401dab(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  char *pcVar5;
  char *_Src;
  undefined4 uVar6;

  FUN_00403637(this,param_1);
  *(undefined ***)this = &PTR_FUN_0040a1d4;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  pvVar3 = operator_new(0x18);
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar3 + 0xc) = 0;
    *(undefined4 *)((int)pvVar3 + 0x10) = 0;
    *(undefined4 *)((int)pvVar3 + 8) = 0;
    *(undefined4 *)((int)pvVar3 + 0x14) = 0;
  }
  *(void **)((int)this + 0x24) = pvVar3;
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x14);
    while (iVar2 != 0) {
      uVar6 = 1;
      _Src = *(char **)(iVar1 + 0x10);
      pcVar4 = _strdup(_Src);
      pcVar5 = _strdup(*(char **)(iVar1 + 0xc));
      FUN_00401044(*(void **)((int)this + 0x24),pcVar5,pcVar4,_Src,uVar6);
      iVar1 = *(int *)(iVar1 + 8);
      iVar2 = iVar1;
    }
  }
  return this;
}



/* VA 00401e23 */

undefined4 * __thiscall FUN_00401e23(void *this,void *param_1,int param_2)

{
  bool bVar1;
  void *pvVar2;
  char *pcVar3;
  int iVar4;
  char *_Str2;
  char *_Str;
  int iVar5;
  size_t sVar6;
  size_t sVar7;
  char *extraout_ECX;
  undefined4 extraout_ECX_00;
  char *local_1c;
  void *local_14;
  int local_10;

  FUN_004035ac(this,param_1,param_2);
  *(undefined ***)this = &PTR_FUN_0040a1d4;
  *(undefined4 *)((int)this + 4) = 2;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  pvVar2 = operator_new(0x18);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar2 + 0xc) = 0;
    *(undefined4 *)((int)pvVar2 + 0x10) = 0;
    *(undefined4 *)((int)pvVar2 + 8) = 0;
    *(undefined4 *)((int)pvVar2 + 0x14) = 0;
  }
  *(void **)((int)this + 0x24) = pvVar2;
  pcVar3 = _strdup(*(char **)((int)this + 0xc));
  if (pcVar3 != (char *)0x0) {
    _strupr(pcVar3);
    iVar4 = strcmp(pcVar3,"THRASHDRIVER");
    free(pcVar3);
    if (((iVar4 == 0) && (*(int *)(param_2 + 0x224) != 0)) &&
       (1 < *(uint *)(*(int *)(param_2 + 0x224) + 0xc))) {
      bVar1 = true;
      goto LAB_00401ec4;
    }
  }
  bVar1 = false;
LAB_00401ec4:
  local_14 = (void *)FUN_00407b17(param_1,"option");
LAB_00402056:
  if (local_14 == (void *)0x0) {
    return this;
  }
  pcVar3 = (char *)FUN_00407b6d(local_14,"key");
  _Str2 = _strdup(pcVar3);
  pcVar3 = FUN_00403472(local_14,*(char **)(param_2 + 0x210),(char *)0x0);
  _Str = _strdup(pcVar3);
  pcVar3 = extraout_ECX;
  if ((bVar1) && (iVar4 = *(int *)(param_2 + 0x220), iVar4 != 0)) {
    iVar5 = *(int *)(iVar4 + 0xc);
    while (iVar5 != 0) {
      pcVar3 = _Str2;
      iVar5 = strcmp((char *)**(undefined4 **)(iVar4 + 8),_Str2);
      if (iVar5 == 0) {
        if ((*(int *)(iVar4 + 8) != 0) && (*(int *)(*(int *)(iVar4 + 8) + 8) != 0)) {
          local_10 = 0;
          iVar4 = *(int *)(param_2 + 0x224);
          if ((iVar4 != 0) && (1 < *(uint *)(iVar4 + 0xc))) goto LAB_00401f95;
        }
        break;
      }
      iVar4 = *(int *)(iVar4 + 4);
      iVar5 = iVar4;
    }
  }
  FUN_00401044(*(void **)((int)this + 0x24),_Str2,_Str,pcVar3,1);
  goto LAB_00401f4f;
LAB_00401f95:
  do {
    if (local_10 == 0) {
      local_1c = _strdup(_Str2);
    }
    else {
      sVar6 = strlen(_Str2);
      local_1c = malloc(sVar6 + 3);
      sprintf(local_1c,"%s@%d",_Str2,local_10);
    }
    strlen(*(char **)(iVar4 + 8));
    strlen(_Str);
    sVar6 = strlen(*(char **)(iVar4 + 8));
    sVar7 = strlen(_Str);
    pcVar3 = malloc(sVar7 + sVar6 + 7);
    local_10 = local_10 + 1;
    sprintf(pcVar3,"%s - %d: %s",_Str,local_10,*(undefined4 *)(iVar4 + 8));
    free(_Str);
    FUN_00401044(*(void **)((int)this + 0x24),local_1c,pcVar3,extraout_ECX_00,1);
    iVar4 = *(int *)(iVar4 + 4);
  } while (iVar4 != 0);
LAB_00401f4f:
  if (local_14 == (void *)0x0) {
    local_14 = (void *)FUN_00407643(param_1,"option");
  }
  else {
    local_14 = (void *)FUN_00407612(local_14,"option");
  }
  goto LAB_00402056;
}



/* VA 00402067 */

undefined4 FUN_00402067(void)

{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar1 = DAT_0040c0d0;
  iVar3 = DAT_0040c0d0 + 0x108;
  iVar2 = FUN_004030e9(iVar3,*(int *)(DAT_0040c0d0 + 0x218));
  if (((iVar2 != 0) && (iVar3 = FUN_00402e40(iVar3,*(int *)(iVar1 + 0x21c)), iVar3 != 0)) &&
     (iVar3 = FUN_004025ed(*(int *)(iVar1 + 0x220)), iVar3 != 0)) {
    return 1;
  }
  return 0;
}



/* VA 004020b5 */

void FUN_004020b5(int param_1)

{
  int iVar1;
  int iVar2;
  int extraout_EDX;
  int extraout_EDX_00;

  iVar1 = DAT_0040c0d0;
  iVar2 = FUN_0040315c(*(int *)(DAT_0040c0d0 + 0x218),param_1);
  if (iVar2 == 0) {
    iVar2 = FUN_00402ed5(*(int *)(iVar1 + 0x21c),extraout_EDX);
    if (iVar2 == 0) {
      FUN_00402616(*(int *)(iVar1 + 0x220),extraout_EDX_00);
    }
  }
  return;
}



/* VA 004020f1 */

/* WARNING: Variable defined which should be unmapped: param_2 */

char * __thiscall FUN_004020f1(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;

  iVar1 = *(int *)(param_1 + 0x228);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x14);
    while ((iVar2 != 0 && (iVar2 = strcmp(*(char **)(iVar1 + 0xc),param_2), iVar2 != 0))) {
      iVar1 = *(int *)(iVar1 + 8);
      iVar2 = iVar1;
    }
  }
  return param_2;
}



/* VA 0040212b */

undefined4 * __thiscall FUN_0040212b(void *this,char *param_1)

{
  undefined4 uVar1;
  void *this_00;
  char *_Str1;
  int iVar2;
  void *this_01;
  undefined4 *puVar3;

  uVar1 = DAT_0040c084;
  this_00 = (void *)FUN_00407b17(this,"root");
  _Str1 = (char *)FUN_00407b6d(this_00,"version");
  if ((((_Str1 != (char *)0x0) && (*_Str1 != '\0')) && (iVar2 = strcmp(_Str1,param_1), iVar2 == 0))
     && (this_01 = operator_new(0x230), this_01 != (void *)0x0)) {
    puVar3 = FUN_00402239(this_01,this_00,uVar1);
    return puVar3;
  }
  return (undefined4 *)0x0;
}



/* VA 00402189 */

void __fastcall FUN_00402189(int param_1)

{
  void *pvVar1;

  if (*(void **)(param_1 + 0x210) != (void *)0x0) {
    free(*(void **)(param_1 + 0x210));
  }
  if (*(void **)(param_1 + 0x22c) != (void *)0x0) {
    free(*(void **)(param_1 + 0x22c));
  }
  pvVar1 = *(void **)(param_1 + 0x214);
  if (pvVar1 != (void *)0x0) {
    FUN_004010ae((int)pvVar1);
    FUN_00401a7e(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x218);
  if (pvVar1 != (void *)0x0) {
    FUN_004014ab((int)pvVar1);
    FUN_00401a7e(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x21c);
  if (pvVar1 != (void *)0x0) {
    FUN_004014ab((int)pvVar1);
    FUN_00401a7e(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x220);
  if (pvVar1 != (void *)0x0) {
    FUN_004014ab((int)pvVar1);
    FUN_00401a7e(pvVar1);
  }
  pvVar1 = *(void **)(param_1 + 0x224);
  if (pvVar1 != (void *)0x0) {
    FUN_004014ab((int)pvVar1);
    FUN_00401a7e(pvVar1);
  }
  return;
}



/* VA 00402239 */

undefined4 * __thiscall FUN_00402239(void *this,void *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char *pcVar2;
  LCID LVar3;
  void *pvVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int iVar5;
  void *pvVar6;
  undefined4 local_10 [2];
  undefined4 *local_8;

  *(undefined4 *)this = 0;
  local_8 = this;
  FUN_00407a43(param_1,"maximized",this);
  pcVar2 = (char *)FUN_00407b6d(param_1,"lang");
  if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
    iVar5 = GetLocaleInfoA(0x400,3,(LPSTR)local_10,5);
    if (iVar5 == 0) {
      LVar3 = GetUserDefaultLCID();
      *(undefined4 *)((int)this + 0x210) = 0;
      *(LCID *)((int)this + 0x20c) = LVar3;
    }
    else {
      *(undefined4 *)((int)this + 0x20c) = 0x400;
      pcVar2 = _strdup((char *)local_10);
      *(char **)((int)this + 0x210) = pcVar2;
      _strupr(pcVar2);
    }
  }
  else {
    pcVar2 = _strdup(pcVar2);
    *(char **)((int)this + 0x210) = pcVar2;
    _strupr(pcVar2);
    DAT_0040c044 = *(undefined4 *)((int)this + 0x210);
    EnumSystemLocalesA(FUN_0040250c,2);
    iVar5 = 0x400;
    if (DAT_0040c040 != 0) {
      iVar5 = DAT_0040c040;
    }
    *(int *)((int)this + 0x20c) = iVar5;
  }
  if (((DAT_0040c04c == (code *)0x0) || (DAT_0040c050 == 0)) || (DAT_0040c048 == 0)) {
    *(undefined4 *)((int)this + 0x224) = 0;
  }
  else {
    pvVar4 = operator_new(0x10);
    if (pvVar4 == (void *)0x0) {
      pvVar4 = (void *)0x0;
    }
    else {
      *(undefined4 *)((int)pvVar4 + 8) = 0;
      *(undefined4 *)((int)pvVar4 + 4) = 0;
      *(undefined4 *)((int)pvVar4 + 0xc) = 0;
    }
    *(void **)((int)this + 0x224) = pvVar4;
    (*DAT_0040c04c)(0,0,FUN_00402482,pvVar4);
  }
  pvVar4 = (void *)FUN_00407b17(param_1,"readme");
  if (pvVar4 == (void *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = FUN_00403472(pvVar4,*(char **)((int)this + 0x210),(char *)0x0);
    pcVar2 = _strdup(pcVar2);
  }
  *(char **)((int)this + 0x22c) = pcVar2;
  FUN_004013aa((int)this,param_1);
  FUN_004010c9((int)this,param_1);
  FUN_004020f1((int)this,"LABEL_NAME");
  local_10[0] = extraout_EAX;
  FUN_004020f1((int)this,"LABEL_COPYRIGHT");
  FUN_004020f1((int)this,"LABEL_VERSION");
  puVar1 = local_8;
  FUN_00401250((int)local_8,param_1,param_2,extraout_EAX,extraout_EAX_00,extraout_EAX_01);
  pvVar4 = (void *)FUN_00407b17(param_1,"main");
  iVar5 = FUN_00407b6d(pvVar4,"ini");
  sprintf((char *)(puVar1 + 0x42),"%s\\%s",param_2,iVar5);
  iVar5 = FUN_00407b6d(pvVar4,"exe");
  sprintf((char *)(local_8 + 1),"%s\\%s",param_2,iVar5);
  puVar1 = local_8;
  FUN_0040118b((int)local_8,pvVar4,local_10[0],extraout_EAX_00,extraout_EAX_01);
  pvVar6 = operator_new(0x10);
  if (pvVar6 == (void *)0x0) {
    pvVar6 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar6 + 8) = 0;
    *(undefined4 *)((int)pvVar6 + 4) = 0;
    *(undefined4 *)((int)pvVar6 + 0xc) = 0;
  }
  puVar1[0x87] = pvVar6;
  FUN_00402e72((int)puVar1,pvVar4,puVar1 + 0x42,pvVar6);
  return puVar1;
}



/* VA 00402482 */

undefined4 FUN_00402482(undefined4 param_1,undefined4 param_2,undefined4 param_3,void *param_4)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 local_1f8 [8];
  undefined1 auStack_1d8 [32];
  undefined4 auStack_1b8 [9];
  char acStack_194 [128];
  uint uStack_114;

  local_1f8[0] = 0x48;
  iVar1 = (*DAT_0040c050)(param_1,local_1f8);
  if (iVar1 != 0) {
    auStack_1b8[0] = 0x1a8;
    uStack_114 = 1;
    iVar1 = 0;
    while (iVar3 = (*DAT_0040c048)(auStack_1d8,iVar1,auStack_1b8,0), iVar3 != 0) {
      iVar1 = iVar1 + 1;
      if ((uStack_114 & 1) != 0) {
        pcVar2 = _strdup(acStack_194);
        FUN_00401530(param_4,pcVar2);
      }
    }
  }
  return 1;
}



/* VA 0040250c */

undefined4 FUN_0040250c(char *param_1)

{
  LCID Locale;
  int iVar1;
  CHAR local_10 [12];

  Locale = strtol(param_1,(char **)0x0,0x10);
  iVar1 = GetLocaleInfoA(Locale,3,local_10,10);
  if ((iVar1 != 0) && (iVar1 = strcmp(local_10,DAT_0040c044), iVar1 == 0)) {
    DAT_0040c040 = Locale;
    return 0;
  }
  return 1;
}



/* VA 0040255e */

undefined4 __fastcall FUN_0040255e(int param_1)

{
  int iVar1;

  iVar1 = FUN_004030e9(param_1 + 0x218,*(int *)(param_1 + 0x31c));
  if ((iVar1 != 0) && (iVar1 = FUN_00402e40(param_1 + 0x218,*(int *)(param_1 + 800)), iVar1 != 0)) {
    return 1;
  }
  return 0;
}



/* VA 00402594 */

void __fastcall FUN_00402594(int *param_1)

{
  void *pvVar1;

  if (*param_1 != 0) {
    free((void *)*param_1);
  }
  if (param_1[1] != 0) {
    free((void *)param_1[1]);
  }
  pvVar1 = (void *)param_1[199];
  if (pvVar1 != (void *)0x0) {
    FUN_004014ab((int)pvVar1);
    FUN_00401a7e(pvVar1);
  }
  pvVar1 = (void *)param_1[200];
  if (pvVar1 != (void *)0x0) {
    FUN_004014ab((int)pvVar1);
    FUN_00401a7e(pvVar1);
  }
  return;
}



/* VA 004025ed */

undefined4 __fastcall FUN_004025ed(int param_1)

{
  int iVar1;

  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    while (iVar1 != 0) {
      iVar1 = FUN_0040255e(*(int *)(param_1 + 8));
      if (iVar1 == 0) {
        return 0;
      }
      param_1 = *(int *)(param_1 + 4);
      iVar1 = param_1;
    }
  }
  return 1;
}



/* VA 00402616 */

int __fastcall FUN_00402616(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int extraout_EDX;
  int extraout_EDX_00;

  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 0xc);
    while (iVar2 != 0) {
      iVar2 = *(int *)(param_1 + 8);
      iVar1 = FUN_0040315c(*(int *)(iVar2 + 0x31c),param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar2 = FUN_00402ed5(*(int *)(iVar2 + 800),extraout_EDX);
      if (iVar2 != 0) {
        return iVar2;
      }
      param_1 = *(int *)(param_1 + 4);
      param_2 = extraout_EDX_00;
      iVar2 = param_1;
    }
  }
  return 0;
}



/* VA 00402651 */

undefined4 * __thiscall
FUN_00402651(void *this,int param_1,void *param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  int iVar2;
  void *pvVar3;

  pcVar1 = (char *)FUN_00407b6d(param_2,"key");
  pcVar1 = _strdup(pcVar1);
  *(char **)this = pcVar1;
  pcVar1 = FUN_00403472(param_2,*(char **)(param_1 + 0x210),"title");
  pcVar1 = _strdup(pcVar1);
  *(char **)((int)this + 4) = pcVar1;
  *(undefined4 *)((int)this + 8) = 0;
  FUN_00407a43(param_2,"multi",(undefined1 *)((int)this + 8));
  sprintf((char *)((int)this + 0x10),"%s\\%s",param_4,*(undefined4 *)this);
  iVar2 = FUN_00407b6d(param_2,"exe");
  if (iVar2 == 0) {
    *(undefined4 *)((int)this + 0xc) = 0;
  }
  else {
    *(undefined4 *)((int)this + 0xc) = 1;
    sprintf((char *)((int)this + 0x114),"%s\\%s",(char *)((int)this + 0x10),iVar2);
  }
  iVar2 = FUN_00407b6d(param_2,"ini");
  sprintf((char *)((int)this + 0x218),"%s\\%s",(int)this + 0x10,iVar2);
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar3 + 8) = 0;
    *(undefined4 *)((int)pvVar3 + 4) = 0;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0;
  }
  *(void **)((int)this + 0x31c) = pvVar3;
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar3 + 8) = 0;
    *(undefined4 *)((int)pvVar3 + 4) = 0;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0;
  }
  *(void **)((int)this + 800) = pvVar3;
  FUN_00402e72(param_1,param_2,(int)this + 0x218,pvVar3);
  return this;
}



/* VA 00402774 */

void __fastcall FUN_00402774(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    free(*(void **)(param_1 + 0x10));
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    free(*(void **)(param_1 + 0x14));
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    free(*(void **)(param_1 + 0x18));
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    free(*(void **)(param_1 + 0x1c));
  }
  return;
}



/* VA 004027b1 */

uint * __thiscall FUN_004027b1(void *this,LPCSTR param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  DWORD _Size;
  BOOL BVar5;
  int iVar6;
  char *pcVar7;
  void *pvVar8;
  LPCSTR lpFormat;
  char *_Format;
  LPCSTR lpFormat_00;
  char *_Format_00;
  char *_Memory;
  ushort *puVar9;
  undefined4 uVar10;
  CHAR *pCVar11;
  int iVar12;
  CHAR local_344 [256];
  CHAR local_244 [256];
  char local_144 [264];
  ushort *local_3c;
  SYSTEMTIME local_38;
  char *local_28;
  uint local_24;
  DWORD local_20;
  char local_1c [2];
  char local_1a [10];
  LPCVOID local_10;
  int *local_c;
  uint local_8;

  local_20 = 0;
  local_8 = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  local_c = (int *)0x0;
  _Size = GetFileVersionInfoSizeA(param_1,&local_20);
  if (_Size == 0) {
    return this;
  }
  local_10 = malloc(_Size);
  BVar5 = GetFileVersionInfoA(param_1,local_20,_Size,local_10);
  if (BVar5 == 0) goto LAB_00402c03;
  param_1 = (LPCSTR)0x0;
  VerQueryValueA(local_10,"\\VarFileInfo\\Translation",&local_3c,(PUINT)&param_1);
  _Memory = (char *)0x0;
  local_28 = (char *)0x0;
  puVar9 = local_3c;
  for (local_24 = (uint)param_1 >> 2; local_24 != 0; local_24 = local_24 - 1) {
    if (*(int *)((int)this + 0x10) == 0) {
      iVar6 = sprintf(local_144,"\\StringFileInfo\\%04x%04x\\%s",(uint)*puVar9,(uint)puVar9[1],
                      "ProductName");
      if (((iVar6 != 0) &&
          (BVar5 = VerQueryValueA(local_10,local_144,&local_c,&local_8), BVar5 != 0)) &&
         (local_8 != 0)) {
        pcVar7 = _strdup((char *)local_c);
        *(char **)((int)this + 0x10) = pcVar7;
      }
LAB_004028c8:
      if (*(int *)((int)this + 0x14) == 0) goto LAB_004028ce;
    }
    else {
      if (*(int *)((int)this + 0x14) != 0) {
        if ((*(int *)((int)this + 0x18) == 0) || ((param_2 != 0 && (_Memory == (char *)0x0))))
        goto LAB_004028c8;
        break;
      }
LAB_004028ce:
      iVar6 = sprintf(local_144,"\\StringFileInfo\\%04x%04x\\%s",(uint)*puVar9,(uint)puVar9[1],
                      "FileDescription");
      if (((iVar6 != 0) &&
          (BVar5 = VerQueryValueA(local_10,local_144,&local_c,&local_8), BVar5 != 0)) &&
         (local_8 != 0)) {
        pcVar7 = _strdup((char *)local_c);
        *(char **)((int)this + 0x14) = pcVar7;
      }
    }
    if ((((*(int *)((int)this + 0x18) == 0) &&
         (iVar6 = sprintf(local_144,"\\StringFileInfo\\%04x%04x\\%s",(uint)*puVar9,(uint)puVar9[1],
                          "LegalCopyright"), iVar6 != 0)) &&
        (BVar5 = VerQueryValueA(local_10,local_144,&local_c,&local_8), BVar5 != 0)) &&
       (local_8 != 0)) {
      pcVar7 = _strdup((char *)local_c);
      *(char **)((int)this + 0x18) = pcVar7;
    }
    if (((param_2 != 0) && (_Memory == (char *)0x0)) &&
       ((iVar6 = sprintf(local_144,"\\StringFileInfo\\%04x%04x\\%s",(uint)*puVar9,(uint)puVar9[1],
                         "ProductVersion"), iVar6 != 0 &&
        ((BVar5 = VerQueryValueA(local_10,local_144,&local_c,&local_8), BVar5 != 0 && (local_8 != 0)
         ))))) {
      _Memory = _strdup((char *)local_c);
    }
    puVar9 = puVar9 + 2;
  }
  local_28 = _Memory;
  BVar5 = VerQueryValueA(local_10,"\\",&local_c,&local_8);
  if (((BVar5 != 0) && (local_8 != 0)) && (*local_c == -0x110fb43)) {
    uVar1 = *(ushort *)((int)local_c + 10);
    *(uint *)this = (uint)uVar1;
    uVar2 = *(ushort *)(local_c + 2);
    *(uint *)((int)this + 4) = (uint)uVar2;
    uVar3 = *(ushort *)((int)local_c + 0xe);
    *(uint *)((int)this + 8) = (uint)uVar3;
    uVar4 = *(ushort *)(local_c + 3);
    *(uint *)((int)this + 0xc) = (uint)uVar4;
    if (param_2 == 0) goto LAB_00402c03;
    if (((uVar1 != 0) && (uVar2 != 0)) && ((uVar3 != 0 && (uVar4 != 0)))) {
      pvVar8 = malloc(0x100);
      iVar6 = param_2;
      *(void **)((int)this + 0x1c) = pvVar8;
      local_38.wYear = 0;
      local_38.wMonth = 0;
      local_38.wDayOfWeek = 0;
      local_38.wDay = 0;
      local_38.wHour = 0;
      local_38.wMinute = 0;
      local_38.wSecond = 0;
      local_38.wMilliseconds = 0;
      if (*(uint *)this < 0x1000) {
        local_38.wMonth = *(WORD *)((int)this + 4);
        local_38.wYear = *(WORD *)this;
        local_38._4_4_ = (uint)*(ushort *)((int)this + 8) << 0x10;
        pCVar11 = local_244;
        iVar12 = 0x100;
        FUN_004020f1(param_2,"MP_DATE_PATTERN");
        GetDateFormatA(*(LCID *)(iVar6 + 0x20c),0,&local_38,lpFormat,pCVar11,iVar12);
        pCVar11 = local_244;
        uVar10 = *(undefined4 *)((int)this + 0xc);
        pcVar7 = "";
        if (_Memory != (char *)0x0) {
          pcVar7 = _Memory;
        }
        FUN_004020f1(iVar6,"MP_VERSION_PATTERN");
        sprintf(*(char **)((int)this + 0x1c),_Format,pcVar7,uVar10,pCVar11);
      }
      else {
        sprintf(local_1c,"%x",*(undefined4 *)this);
        iVar6 = atoi(local_1c);
        local_38.wYear = (WORD)iVar6;
        sprintf(local_1c,"%x",*(undefined4 *)((int)this + 4));
        iVar6 = atoi(local_1c);
        local_38.wMonth = (WORD)iVar6;
        sprintf(local_1c,"%x",*(undefined4 *)((int)this + 8));
        iVar6 = atoi(local_1c);
        local_38.wDay = (short)iVar6;
        sprintf(local_1c,"%x",*(undefined4 *)((int)this + 0xc));
        iVar6 = atoi(local_1a);
        local_1a[0] = '\0';
        local_38.wMinute = (WORD)iVar6;
        iVar12 = atoi(local_1c);
        iVar6 = param_2;
        local_38.wHour = (WORD)iVar12;
        pCVar11 = local_244;
        iVar12 = 0x100;
        FUN_004020f1(param_2,"EA_DATE_PATTERN");
        GetDateFormatA(*(LCID *)(iVar6 + 0x20c),0,&local_38,lpFormat_00,pCVar11,iVar12);
        GetTimeFormatA(*(LCID *)(iVar6 + 0x20c),0,&local_38,local_244,local_344,0x100);
        pCVar11 = local_344;
        FUN_004020f1(iVar6,"EA_VERSION_PATTERN");
        sprintf(*(char **)((int)this + 0x1c),_Format_00,pCVar11);
        _Memory = local_28;
      }
      if (_Memory != (char *)0x0) {
        free(_Memory);
      }
      goto LAB_00402c03;
    }
  }
  *(char **)((int)this + 0x1c) = _Memory;
LAB_00402c03:
  free(local_10);
  return this;
}



/* VA 00402c16 */

undefined4 __thiscall FUN_00402c16(void *this,LPCSTR param_1)

{
  BOOL BVar1;
  char local_18 [20];

  if (*(float *)((int)this + 0x2c) != *(float *)((int)this + 0x1c)) {
    sprintf(local_18,"%f",(double)*(float *)((int)this + 0x2c));
    BVar1 = WritePrivateProfileStringA
                      (*(LPCSTR *)((int)this + 8),*(LPCSTR *)((int)this + 0xc),local_18,param_1);
    if (BVar1 == 0) {
      return 0;
    }
    *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)((int)this + 0x2c);
  }
  return 1;
}



/* VA 00402c6f */

DWORD __thiscall FUN_00402c6f(void *this,LPCSTR param_1)

{
  DWORD DVar1;
  double dVar2;
  CHAR local_104 [256];

  DVar1 = GetPrivateProfileStringA
                    (*(LPCSTR *)((int)this + 8),*(LPCSTR *)((int)this + 0xc),(LPCSTR)0x0,local_104,
                     0x100,param_1);
  if (DVar1 != 0) {
    dVar2 = atof(local_104);
    *(float *)((int)this + 0x2c) = (float)dVar2;
    *(float *)((int)this + 0x1c) = (float)dVar2;
  }
  return DVar1;
}



/* VA 00402cc7 */

undefined4 * __thiscall FUN_00402cc7(void *this,int param_1)

{
  FUN_00403637(this,param_1);
  *(undefined ***)this = &PTR_FUN_0040a380;
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)((int)this + 0x1c) = 0x800000;
  *(undefined4 *)((int)this + 0x2c) = 0x800000;
  return this;
}



/* VA 00402d05 */

undefined4 * __thiscall FUN_00402d05(void *this,void *param_1,int param_2)

{
  byte bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  void *local_c;
  void *pvStack_8;

  local_c = this;
  pvStack_8 = this;
  FUN_004035ac(this,param_1,param_2);
  *(undefined ***)this = &PTR_FUN_0040a380;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 4) = 1;
  *(undefined4 *)((int)this + 0x1c) = 0x800000;
  *(undefined4 *)((int)this + 0x2c) = 0x800000;
  *(undefined4 *)((int)this + 0x20) = 0x800000;
  *(undefined4 *)((int)this + 0x24) = 0x7f7fffff;
  bVar1 = FUN_004079fd(param_1,"min",&local_c);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    *(float *)((int)this + 0x20) = (float)(double)CONCAT44(pvStack_8,local_c);
  }
  bVar1 = FUN_004079fd(param_1,"max",&local_c);
  if (CONCAT31(extraout_var_00,bVar1) == 0) {
    *(float *)((int)this + 0x24) = (float)(double)CONCAT44(pvStack_8,local_c);
  }
  FUN_00407a20(param_1,"precision",(undefined4 *)((int)this + 0x28));
  return this;
}



/* VA 00402da4 */

void __thiscall FUN_00402da4(void *this,undefined4 param_1)

{
  FUN_004030e9(param_1,*(int *)((int)this + 4));
  return;
}



/* VA 00402db6 */

void __fastcall FUN_00402db6(int *param_1)

{
  void *pvVar1;

  if (*param_1 != 0) {
    free((void *)*param_1);
  }
  pvVar1 = (void *)param_1[1];
  if (pvVar1 != (void *)0x0) {
    FUN_004014ab((int)pvVar1);
    FUN_00401a7e(pvVar1);
  }
  return;
}



/* VA 00402de1 */

undefined4 * __thiscall FUN_00402de1(void *this,int param_1,void *param_2,undefined4 param_3)

{
  char *pcVar1;
  void *pvVar2;

  pcVar1 = FUN_00403472(param_2,*(char **)(param_1 + 0x210),"title");
  pcVar1 = _strdup(pcVar1);
  *(char **)this = pcVar1;
  pvVar2 = operator_new(0x10);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar2 + 8) = 0;
    *(undefined4 *)((int)pvVar2 + 4) = 0;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0;
  }
  *(void **)((int)this + 4) = pvVar2;
  FUN_00403117(param_1,param_2,param_3,pvVar2);
  return this;
}



/* VA 00402e40 */

undefined4 __fastcall FUN_00402e40(undefined4 param_1,int param_2)

{
  int iVar1;

  if (param_2 != 0) {
    iVar1 = *(int *)(param_2 + 0xc);
    while (iVar1 != 0) {
      iVar1 = FUN_004030e9(param_1,*(int *)(*(int *)(param_2 + 8) + 4));
      if (iVar1 == 0) {
        return 0;
      }
      param_2 = *(int *)(param_2 + 4);
      iVar1 = param_2;
    }
  }
  return 1;
}



/* VA 00402e72 */

void __fastcall FUN_00402e72(int param_1,void *param_2,undefined4 param_3,void *param_4)

{
  void *this;
  void *this_00;
  undefined4 *puVar1;

  this = (void *)FUN_00407b17(param_2,"group");
  while (this != (void *)0x0) {
    this_00 = operator_new(8);
    if (this_00 == (void *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_00402de1(this_00,param_1,this,param_3);
    }
    FUN_00401456(param_4,puVar1);
    if (this == (void *)0x0) {
      this = (void *)FUN_00407643(param_2,"group");
    }
    else {
      this = (void *)FUN_00407612(this,"group");
    }
  }
  return;
}



/* VA 00402ed5 */

int __fastcall FUN_00402ed5(int param_1,int param_2)

{
  int iVar1;
  int extraout_EDX;

  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    while (iVar1 != 0) {
      iVar1 = FUN_0040315c(*(int *)(*(int *)(param_1 + 8) + 4),param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
      param_1 = *(int *)(param_1 + 4);
      param_2 = extraout_EDX;
      iVar1 = param_1;
    }
  }
  return 0;
}



/* VA 00402efc */

undefined4 __thiscall FUN_00402efc(void *this,LPCSTR param_1)

{
  BOOL BVar1;
  char local_18 [20];

  if (*(int *)((int)this + 0x28) != *(int *)((int)this + 0x1c)) {
    sprintf(local_18,"%d",*(int *)((int)this + 0x28));
    BVar1 = WritePrivateProfileStringA
                      (*(LPCSTR *)((int)this + 8),*(LPCSTR *)((int)this + 0xc),local_18,param_1);
    if (BVar1 == 0) {
      return 0;
    }
    *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)((int)this + 0x28);
  }
  return 1;
}



/* VA 00402f45 */

undefined4 __thiscall FUN_00402f45(void *this,LPCSTR param_1)

{
  UINT UVar1;

  UVar1 = GetPrivateProfileIntA(*(LPCSTR *)((int)this + 8),*(LPCSTR *)((int)this + 0xc),0,param_1);
  *(UINT *)((int)this + 0x28) = UVar1;
  *(UINT *)((int)this + 0x1c) = UVar1;
  return 1;
}



/* VA 00402f6a */

undefined4 * __thiscall FUN_00402f6a(void *this,int param_1)

{
  FUN_00403637(this,param_1);
  *(undefined ***)this = &PTR_FUN_0040a398;
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)this + 0x1c) = 0x80000000;
  *(undefined4 *)((int)this + 0x28) = 0x80000000;
  return this;
}



/* VA 00402f9f */

undefined4 * __thiscall FUN_00402f9f(void *this,void *param_1,int param_2)

{
  FUN_004035ac(this,param_1,param_2);
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = &PTR_FUN_0040a398;
  *(undefined4 *)((int)this + 0x1c) = 0x80000000;
  *(undefined4 *)((int)this + 0x28) = 0x80000000;
  *(undefined4 *)((int)this + 0x20) = 0x80000000;
  *(undefined4 *)((int)this + 0x24) = 0x7fffffff;
  FUN_00407a20(param_1,"min",(undefined4 *)((int)this + 0x20));
  FUN_00407a20(param_1,"max",(undefined4 *)((int)this + 0x24));
  return this;
}



/* VA 00402ff8 */

DWORD __thiscall FUN_00402ff8(void *this,LPCSTR param_1)

{
  DWORD DVar1;
  char *pcVar2;
  CHAR local_104 [256];

  DVar1 = GetPrivateProfileStringA
                    (*(LPCSTR *)((int)this + 8),*(LPCSTR *)((int)this + 0xc),(LPCSTR)0x0,local_104,
                     0x100,param_1);
  if (DVar1 != 0) {
    pcVar2 = _strdup(local_104);
    *(char **)((int)this + 0x1c) = pcVar2;
  }
  return DVar1;
}



/* VA 00403041 */

void __fastcall FUN_00403041(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0040a3a4;
  if (param_1[7] != 0) {
    free((void *)param_1[7]);
  }
  FUN_00403569(param_1);
  return;
}



/* VA 00403062 */

undefined4 * __thiscall FUN_00403062(void *this,int param_1)

{
  FUN_00403637(this,param_1);
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined ***)this = &PTR_FUN_0040a3a4;
  return this;
}



/* VA 00403081 */

undefined4 * __thiscall FUN_00403081(void *this,void *param_1,int param_2)

{
  FUN_004035ac(this,param_1,param_2);
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined ***)this = &PTR_FUN_0040a3a4;
  *(undefined4 *)((int)this + 4) = 5;
  return this;
}



/* VA 004030aa */

undefined4 * __fastcall FUN_004030aa(undefined4 *param_1)

{
  undefined4 *extraout_ECX;

  FUN_004030cf(param_1);
  extraout_ECX[7] = 0;
  *extraout_ECX = &PTR_FUN_0040a3a4;
  extraout_ECX[1] = 5;
  return extraout_ECX;
}



/* VA 004030cf */

undefined4 * __fastcall FUN_004030cf(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0040a40c;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  return param_1;
}



/* VA 004030e9 */

undefined4 __fastcall FUN_004030e9(undefined4 param_1,int param_2)

{
  int iVar1;

  if (param_2 != 0) {
    iVar1 = *(int *)(param_2 + 0xc);
    while (iVar1 != 0) {
      iVar1 = (**(code **)(**(int **)(param_2 + 8) + 8))(param_1);
      if (iVar1 == 0) {
        return 0;
      }
      param_2 = *(int *)(param_2 + 4);
      iVar1 = param_2;
    }
  }
  return 1;
}



/* VA 00403117 */

void __fastcall FUN_00403117(int param_1,void *param_2,undefined4 param_3,void *param_4)

{
  void *this;
  int *piVar1;

  for (this = (void *)FUN_00407b17(param_2,"property"); this != (void *)0x0;
      this = (void *)FUN_00407612(this,"property")) {
    piVar1 = FUN_00403178(this,param_3,param_1,*(int *)(param_1 + 0x214));
    FUN_00401456(param_4,piVar1);
  }
  return;
}



/* VA 0040315c */

int __fastcall FUN_0040315c(int param_1,int param_2)

{
  int iVar1;

  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    while (iVar1 != 0) {
      if (*(int *)(*(int *)(param_1 + 8) + 0x18) == param_2) {
        return *(int *)(param_1 + 8);
      }
      param_1 = *(int *)(param_1 + 4);
      iVar1 = param_1;
    }
  }
  return 0;
}



/* VA 00403178 */

int * __fastcall FUN_00403178(void *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;

  piVar5 = (int *)0x0;
  if (((param_4 != 0) && (pcVar2 = (char *)FUN_00407b6d(param_1,"inherit"), pcVar2 != (char *)0x0))
     && (*pcVar2 != '\0')) {
    iVar3 = *(int *)(param_4 + 0x14);
    while (iVar3 != 0) {
      iVar3 = strcmp(*(char **)(param_4 + 0xc),pcVar2);
      if (iVar3 == 0) {
        iVar3 = *(int *)(param_4 + 0x10);
        if (iVar3 != 0) {
          iVar1 = *(int *)(iVar3 + 4);
          if (iVar1 == 0) {
            pvVar4 = operator_new(0x2c);
            if (pvVar4 != (void *)0x0) {
              piVar5 = FUN_00402f6a(pvVar4,iVar3);
            }
          }
          else if (iVar1 == 1) {
            pvVar4 = operator_new(0x30);
            if (pvVar4 != (void *)0x0) {
              piVar5 = FUN_00402cc7(pvVar4,iVar3);
            }
          }
          else if (iVar1 == 2) {
            pvVar4 = operator_new(0x28);
            if (pvVar4 != (void *)0x0) {
              piVar5 = FUN_00401dab(pvVar4,iVar3);
            }
          }
          else if (iVar1 == 3) {
            pvVar4 = operator_new(0x28);
            if (pvVar4 != (void *)0x0) {
              piVar5 = FUN_004036ab(pvVar4,iVar3);
            }
          }
          else if (iVar1 == 4) {
            pvVar4 = operator_new(0x24);
            if (pvVar4 != (void *)0x0) {
              piVar5 = FUN_00401c5b(pvVar4,iVar3);
            }
          }
          else if (iVar1 == 5) {
            pvVar4 = operator_new(0x20);
            if (pvVar4 != (void *)0x0) {
              piVar5 = FUN_00403062(pvVar4,iVar3);
            }
          }
          else {
            pvVar4 = operator_new(0x24);
            if (pvVar4 != (void *)0x0) {
              piVar5 = FUN_0040381c(pvVar4,iVar3);
            }
          }
          pcVar2 = (char *)FUN_00407b6d(param_1,"section");
          if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
            pcVar2 = _strdup(pcVar2);
            piVar5[2] = (int)pcVar2;
          }
          pcVar2 = (char *)FUN_00407b6d(param_1,"key");
          if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
            pcVar2 = _strdup(pcVar2);
            piVar5[3] = (int)pcVar2;
          }
          goto LAB_0040345b;
        }
        break;
      }
      param_4 = *(int *)(param_4 + 8);
      iVar3 = param_4;
    }
  }
  pcVar2 = (char *)FUN_00407b6d(param_1,"type");
  iVar3 = strcmp(pcVar2,"integer");
  if (iVar3 == 0) {
    pvVar4 = operator_new(0x2c);
    if (pvVar4 != (void *)0x0) {
      piVar5 = FUN_00402f9f(pvVar4,param_1,param_3);
    }
  }
  else {
    iVar3 = strcmp(pcVar2,"float");
    if (iVar3 == 0) {
      pvVar4 = operator_new(0x30);
      if (pvVar4 != (void *)0x0) {
        piVar5 = FUN_00402d05(pvVar4,param_1,param_3);
      }
    }
    else {
      iVar3 = strcmp(pcVar2,"choice");
      if (iVar3 == 0) {
        pvVar4 = operator_new(0x28);
        if (pvVar4 != (void *)0x0) {
          piVar5 = FUN_00401e23(pvVar4,param_1,param_3);
        }
      }
      else {
        iVar3 = strcmp(pcVar2,"radio");
        if (iVar3 == 0) {
          pvVar4 = operator_new(0x28);
          if (pvVar4 != (void *)0x0) {
            piVar5 = FUN_00403686(pvVar4,param_1,param_3);
          }
        }
        else {
          iVar3 = strcmp(pcVar2,"check");
          if (iVar3 == 0) {
            pvVar4 = operator_new(0x24);
            if (pvVar4 != (void *)0x0) {
              piVar5 = FUN_00401c7e(pvVar4,param_1,param_3);
            }
          }
          else {
            iVar3 = strcmp(pcVar2,"label");
            if (iVar3 == 0) {
              pvVar4 = operator_new(0x20);
              if (pvVar4 != (void *)0x0) {
                piVar5 = FUN_00403081(pvVar4,param_1,param_3);
              }
            }
            else {
              pvVar4 = operator_new(0x24);
              if (pvVar4 != (void *)0x0) {
                piVar5 = FUN_004037f3(pvVar4,param_1,param_3);
              }
            }
          }
        }
      }
    }
  }
LAB_0040345b:
  if (param_4 != 0) {
    (**(code **)(*piVar5 + 4))(param_2);
  }
  return piVar5;
}



/* VA 00403472 */

undefined * __fastcall FUN_00403472(void *param_1,char *param_2,char *param_3)

{
  void *pvVar1;
  char *pcVar2;
  int iVar3;
  void *this;
  undefined *puVar4;
  void *this_00;
  char local_10 [8];
  char *local_8;

  local_8 = param_2;
  if (param_3 != (char *)0x0) {
    param_1 = (void *)FUN_00407b17(param_1,param_3);
  }
  if (param_1 == (void *)0x0) {
    puVar4 = &DAT_0040a2a2;
  }
  else {
    pvVar1 = (void *)FUN_00407b17(param_1,"value");
    this_00 = pvVar1;
    if (param_2 == (char *)0x0) goto joined_r0x00403525;
    this = pvVar1;
    if (pvVar1 == (void *)0x0) goto joined_r0x00403525;
    do {
      pcVar2 = (char *)FUN_00407b6d(this,"lang");
      if (pcVar2 == (char *)0x0) {
LAB_00403502:
        this = (void *)FUN_00407612(this,"value");
      }
      else {
        if (*pcVar2 != '\0') {
          strcpy(local_10,pcVar2);
          _strupr(local_10);
          iVar3 = strcmp(local_10,local_8);
          if (iVar3 == 0) goto LAB_0040351a;
        }
        if (this != (void *)0x0) goto LAB_00403502;
        this = (void *)FUN_00407643(param_1,"value");
      }
    } while (this != (void *)0x0);
    do {
      pcVar2 = (char *)FUN_00407b6d(this_00,"lang");
      this = this_00;
      if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) break;
      if (this_00 == (void *)0x0) {
        this_00 = (void *)FUN_00407643(param_1,"value");
      }
      else {
        this_00 = (void *)FUN_00407612(this_00,"value");
      }
joined_r0x00403525:
      this = pvVar1;
    } while (this_00 != (void *)0x0);
LAB_0040351a:
    puVar4 = (undefined *)FUN_004079e3((int)this);
  }
  return puVar4;
}



/* VA 00403569 */

void __fastcall FUN_00403569(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0040a40c;
  if (param_1[2] != 0) {
    free((void *)param_1[2]);
  }
  if (param_1[3] != 0) {
    free((void *)param_1[3]);
  }
  if (param_1[4] != 0) {
    free((void *)param_1[4]);
  }
  if (param_1[5] != 0) {
    free((void *)param_1[5]);
  }
  return;
}



/* VA 004035ac */

undefined4 * __thiscall FUN_004035ac(void *this,void *param_1,int param_2)

{
  char *pcVar1;

  *(undefined ***)this = &PTR_FUN_0040a40c;
  pcVar1 = (char *)FUN_00407b6d(param_1,"section");
  pcVar1 = _strdup(pcVar1);
  *(char **)((int)this + 8) = pcVar1;
  pcVar1 = (char *)FUN_00407b6d(param_1,"key");
  pcVar1 = _strdup(pcVar1);
  *(char **)((int)this + 0xc) = pcVar1;
  pcVar1 = FUN_00403472(param_1,*(char **)(param_2 + 0x210),"title");
  pcVar1 = _strdup(pcVar1);
  *(char **)((int)this + 0x10) = pcVar1;
  pcVar1 = FUN_00403472(param_1,*(char **)(param_2 + 0x210),"description");
  pcVar1 = _strdup(pcVar1);
  *(undefined4 *)((int)this + 0x18) = 0;
  *(char **)((int)this + 0x14) = pcVar1;
  return this;
}



/* VA 00403637 */

undefined4 * __thiscall FUN_00403637(void *this,int param_1)

{
  char *pcVar1;

  *(undefined ***)this = &PTR_FUN_0040a40c;
  pcVar1 = _strdup(*(char **)(param_1 + 8));
  *(char **)((int)this + 8) = pcVar1;
  pcVar1 = _strdup(*(char **)(param_1 + 0xc));
  *(char **)((int)this + 0xc) = pcVar1;
  pcVar1 = _strdup(*(char **)(param_1 + 0x10));
  *(char **)((int)this + 0x10) = pcVar1;
  pcVar1 = _strdup(*(char **)(param_1 + 0x14));
  *(char **)((int)this + 0x14) = pcVar1;
  *(undefined4 *)((int)this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  return this;
}



/* VA 00403686 */

undefined4 * __thiscall FUN_00403686(void *this,void *param_1,int param_2)

{
  FUN_00401e23(this,param_1,param_2);
  *(undefined ***)this = &PTR_FUN_0040a1d4;
  *(undefined4 *)((int)this + 4) = 3;
  return this;
}



/* VA 004036ab */

undefined4 * __thiscall FUN_004036ab(void *this,int param_1)

{
  FUN_00401dab(this,param_1);
  *(undefined ***)this = &PTR_FUN_0040a1d4;
  return this;
}



/* VA 004036cb */

void FUN_004036cb(void)

{
  HMODULE hModule;

  hModule = GetModuleHandleA("USER32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_0040c054 = GetProcAddress(hModule,"MonitorFromWindow");
    DAT_0040c050 = GetProcAddress(hModule,"GetMonitorInfoA");
    DAT_0040c04c = GetProcAddress(hModule,"EnumDisplayMonitors");
    DAT_0040c048 = GetProcAddress(hModule,"EnumDisplayDevicesA");
  }
  return;
}



/* VA 0040371b */

undefined4 __thiscall FUN_0040371b(void *this,LPCSTR param_1)

{
  int iVar1;
  BOOL BVar2;
  char *pcVar3;

  pcVar3 = *(char **)((int)this + 0x20);
  if ((*(char **)((int)this + 0x1c) != pcVar3) &&
     ((pcVar3 == (char *)0x0 || (iVar1 = strcmp(*(char **)((int)this + 0x1c),pcVar3), iVar1 != 0))))
  {
    BVar2 = WritePrivateProfileStringA
                      (*(LPCSTR *)((int)this + 8),*(LPCSTR *)((int)this + 0xc),
                       *(LPCSTR *)((int)this + 0x1c),param_1);
    if (BVar2 == 0) {
      return 0;
    }
    if (*(int *)((int)this + 0x20) != 0) {
      free(*(void **)((int)this + 0x20));
    }
    pcVar3 = _strdup(*(char **)((int)this + 0x1c));
    *(char **)((int)this + 0x20) = pcVar3;
  }
  return 1;
}



/* VA 00403778 */

DWORD __thiscall FUN_00403778(void *this,LPCSTR param_1)

{
  DWORD DVar1;
  char *pcVar2;
  CHAR local_104 [256];

  DVar1 = GetPrivateProfileStringA
                    (*(LPCSTR *)((int)this + 8),*(LPCSTR *)((int)this + 0xc),(LPCSTR)0x0,local_104,
                     0x100,param_1);
  if (DVar1 != 0) {
    pcVar2 = _strdup(local_104);
    *(char **)((int)this + 0x1c) = pcVar2;
    pcVar2 = _strdup(local_104);
    *(char **)((int)this + 0x20) = pcVar2;
  }
  return DVar1;
}



/* VA 004037d2 */

void __fastcall FUN_004037d2(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0040a470;
  if (param_1[8] != 0) {
    free((void *)param_1[8]);
  }
  FUN_00403041(param_1);
  return;
}



/* VA 004037f3 */

undefined4 * __thiscall FUN_004037f3(void *this,void *param_1,int param_2)

{
  FUN_00403081(this,param_1,param_2);
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined ***)this = &PTR_FUN_0040a470;
  *(undefined4 *)((int)this + 4) = 6;
  return this;
}



/* VA 0040381c */

undefined4 * __thiscall FUN_0040381c(void *this,int param_1)

{
  FUN_00403062(this,param_1);
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined ***)this = &PTR_FUN_0040a470;
  return this;
}



/* VA 0040383b */

WPARAM entry(void)

{
  LPCSTR pCVar1;
  void *pvVar2;
  uint *puVar3;
  char *pcVar4;
  size_t sVar5;
  int iVar6;
  WPARAM WVar7;
  INITCOMMONCONTROLSEX local_234;
  char local_22c [20];
  CHAR local_218 [264];
  CHAR local_110 [268];

  WVar7 = 0;
  DAT_0040c058 = GetModuleHandleA((LPCSTR)0x0);
  FUN_004036cb();
  GetModuleFileNameA(DAT_0040c058,local_110,0x104);
  DAT_0040c084 = local_110;
  pvVar2 = operator_new(0x20);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (uint *)0x0;
  }
  else {
    puVar3 = FUN_004027b1(pvVar2,DAT_0040c084,0);
  }
  sprintf(local_22c,"%d.%d.%d.%d",*puVar3,puVar3[1],puVar3[2],puVar3[3]);
  FUN_00402774((int)puVar3);
  FUN_00401a7e(puVar3);
  DAT_0040c0c8 = strrchr(DAT_0040c084,0x2e);
  pCVar1 = DAT_0040c084;
  *DAT_0040c0c8 = '\0';
  pcVar4 = strrchr(pCVar1,0x5c);
  pCVar1 = DAT_0040c084;
  *pcVar4 = '\0';
  DAT_0040c0c8 = pcVar4 + 1;
  sVar5 = strlen(pCVar1);
  FUN_00401aa5(local_218,sVar5);
  DAT_0040c098 = local_218;
  DAT_0040c0e0 = FindWindowA(DAT_0040c098,(LPCSTR)0x0);
  if (DAT_0040c0e0 == (HWND)0x0) {
    iVar6 = FUN_00404b3d(local_22c);
    if (iVar6 != 0) {
      DAT_0040c068 = GetStockObject(0x11);
      DAT_0040c0e8 = LoadIconA(DAT_0040c058,(LPCSTR)0x64);
      DAT_0040c094 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
      DAT_0040c0b8 = LoadImageA(DAT_0040c058,(LPCSTR)0x66,1,0,0,0);
      DAT_0040c08c = LoadImageA(DAT_0040c058,(LPCSTR)0x65,1,0x10,0x10,0);
      local_234.dwSize = 8;
      local_234.dwICC = 0xff;
      InitCommonControlsEx(&local_234);
      FUN_0040433b(DAT_0040c098,FUN_0040660a);
      FUN_0040433b("NFS_MP_CD",FUN_0040653a);
      WVar7 = FUN_00403df5();
      pvVar2 = DAT_0040c0d0;
      if (DAT_0040c0d0 != (void *)0x0) {
        FUN_00402189((int)DAT_0040c0d0);
        FUN_00401a7e(pvVar2);
      }
    }
  }
  else {
    ShowWindow(DAT_0040c0e0,9);
    SetForegroundWindow(DAT_0040c0e0);
  }
  return WVar7;
}



/* VA 00403a22 */

void __fastcall FUN_00403a22(int param_1,int param_2)

{
  undefined4 *puVar1;
  size_t sVar2;
  size_t sVar3;
  LPCSTR pCVar4;
  HWND pHVar5;
  undefined4 *puVar6;
  int iVar7;
  void *this;
  HWND hWndInsertAfter;
  undefined4 extraout_ECX;
  int cy;
  char *_Dest;
  int iVar8;
  tagRECT local_44;
  tagRECT local_34;
  tagRECT local_24;
  int local_14;
  int local_10;
  int local_c;
  int local_8;

  _Dest = (char *)0x0;
  local_10 = param_1;
  if (((*(int *)(param_1 + 8) != 0) && (local_c = *(int *)(DAT_0040c0d0 + 0x224), local_c != 0)) &&
     (1 < *(uint *)(local_c + 0xc))) {
    do {
      if (param_2 == 0) {
        sVar2 = strlen(*(char **)(param_1 + 4));
        sVar3 = strlen(*(char **)(local_c + 8));
        _Dest = malloc(sVar3 + sVar2 + 4);
        sprintf(_Dest,"%s - %s",*(undefined4 *)(param_1 + 4),*(undefined4 *)(local_c + 8));
        break;
      }
      local_c = *(int *)(local_c + 4);
      param_2 = param_2 + -1;
    } while (local_c != 0);
  }
  pCVar4 = _Dest;
  if (_Dest == (char *)0x0) {
    pCVar4 = *(LPCSTR *)(param_1 + 4);
  }
  DAT_0040c070 = param_1;
  DAT_0040c0dc = FUN_004061d0(DAT_0040c0e0,"NFS_MP_CD",pCVar4,0x1bb,0x134,0xc80000,&DAT_0040c0b0);
  if (_Dest != (char *)0x0) {
    free(_Dest);
  }
  DAT_0040c080 = FUN_00406114(DAT_0040c0dc,0x50);
  DAT_0040c064 = operator_new(0x18);
  if (DAT_0040c064 == (void *)0x0) {
    DAT_0040c064 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)DAT_0040c064 + 0xc) = 0;
    *(undefined4 *)((int)DAT_0040c064 + 0x10) = 0;
    *(undefined4 *)((int)DAT_0040c064 + 8) = 0;
    *(undefined4 *)((int)DAT_0040c064 + 0x14) = 0;
  }
  local_8 = 0;
  local_c = 6;
  pHVar5 = FUN_00405927(DAT_0040c0dc,*(int *)(param_1 + 0x31c),0x62,0x14d,&local_8,&local_c,
                        DAT_0040c064,(HWND)0x0);
  FUN_0040563a(DAT_0040c0dc,pHVar5,*(int *)(param_1 + 0x31c),local_8,0x14d,DAT_0040c064,0);
  FUN_00404432(param_1);
  local_8 = 0;
  puVar6 = operator_new(0x10);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    puVar6[2] = 0;
    puVar6[1] = 0;
    puVar6[3] = 0;
  }
  iVar8 = *(int *)(param_1 + 800);
  if ((iVar8 != 0) && (*(int *)(iVar8 + 0xc) != 0)) {
    do {
      local_c = local_c + 6;
      pHVar5 = FUN_00405927(DAT_0040c0dc,(*(undefined4 **)(iVar8 + 8))[1],0xc,0x1a3,&local_8,
                            &local_c,DAT_0040c064,(HWND)**(undefined4 **)(iVar8 + 8));
      if (puVar6[3] == 0) {
        *puVar6 = 0;
        iVar7 = 0;
        puVar6[2] = pHVar5;
      }
      else {
        this = (void *)puVar6[1];
        if (this == (void *)0x0) {
          this = operator_new(0x10);
          if (this == (void *)0x0) {
            this = (void *)0x0;
          }
          else {
            *(undefined4 *)((int)this + 8) = 0;
            *(undefined4 *)((int)this + 4) = 0;
            *(undefined4 *)((int)this + 0xc) = 0;
          }
          puVar6[1] = this;
        }
        FUN_00401675(this,pHVar5);
        iVar7 = puVar6[3];
      }
      puVar6[3] = iVar7 + 1;
      iVar8 = *(int *)(iVar8 + 4);
    } while (iVar8 != 0);
    iVar8 = *(int *)(local_10 + 800);
    param_1 = local_10;
  }
  if (puVar6 != (undefined4 *)0x0) {
    if ((puVar6[3] != 0) && (iVar8 != 0)) {
      puVar1 = puVar6;
      iVar7 = *(int *)(iVar8 + 0xc);
      while (iVar7 != 0) {
        FUN_0040563a(DAT_0040c0dc,(HWND)puVar1[2],(*(int **)(iVar8 + 8))[1],local_8,0x1a3,
                     DAT_0040c064,**(int **)(iVar8 + 8));
        puVar1 = (undefined4 *)puVar1[1];
        param_1 = local_10;
        if (puVar1 == (undefined4 *)0x0) break;
        iVar8 = *(int *)(iVar8 + 4);
        iVar7 = iVar8;
      }
    }
    if ((void *)puVar6[1] != (void *)0x0) {
      FUN_0040165d((void *)puVar6[1]);
    }
    FUN_00401a7e(puVar6);
  }
  iVar8 = local_c;
  iVar7 = local_c + 10;
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_004060b2(DAT_0040c0dc,"BUTTON_CONFIG",0xc,iVar7,DAT_0040c064,0x404ee9,0);
  }
  pHVar5 = FUN_004060b2(DAT_0040c0dc,"BUTTON_CANCEL",0x12f,iVar7,DAT_0040c064,0x404f2a,0);
  hWndInsertAfter = FUN_004060b2(DAT_0040c0dc,"BUTTON_OK",0xa9,iVar7,DAT_0040c064,0x404f48,1);
  SetWindowPos(pHVar5,hWndInsertAfter,0,0,0,0,3);
  local_24.bottom = iVar8 + 0x2b;
  local_24.left = 0;
  local_24.top = 0;
  local_24.right = 0x1bb;
  AdjustWindowRect(&local_24,0xc80000,0);
  local_14 = local_24.right - local_24.left;
  cy = local_24.bottom - local_24.top;
  GetWindowRect(DAT_0040c0e0,&local_44);
  iVar7 = (((local_44.right - local_44.left) - local_24.right) + local_24.left) / 2 + local_44.left;
  iVar8 = (((local_44.bottom - local_44.top) - local_24.bottom) + local_24.top) / 2 + local_44.top;
  FUN_00404393(extraout_ECX,&local_34);
  if (local_34.right < iVar7 + local_14) {
    iVar7 = local_34.right - local_14;
  }
  if (iVar7 < local_34.left) {
    iVar7 = local_34.left;
  }
  if (local_34.bottom < iVar8 + cy) {
    iVar8 = local_34.bottom - cy;
  }
  if (iVar8 < local_34.top) {
    iVar8 = local_34.top;
  }
  SetWindowPos(DAT_0040c0dc,(HWND)0x0,iVar7,iVar8,local_14,cy,4);
  ShowWindow(DAT_0040c0dc,5);
  return;
}



/* VA 00403df5 */

WPARAM FUN_00403df5(void)

{
  code *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  void *pvVar4;
  uint *puVar5;
  undefined4 uVar6;
  HWND pHVar7;
  int iVar8;
  HANDLE lParam;
  undefined4 *puVar9;
  int iVar10;
  code *pcVar11;
  BOOL BVar12;
  undefined4 extraout_ECX;
  code *pcVar13;
  char *name;
  uint uVar14;
  UINT fuLoad;
  char local_16c [268];
  tagMSG local_60;
  tagRECT local_44;
  tagRECT local_34;
  HWND local_24;
  code *local_20;
  tagRECT local_1c;
  code *local_c;
  undefined4 *local_8;

  local_20 = operator_new_exref;
  pvVar4 = operator_new(0x20);
  if (pvVar4 == (void *)0x0) {
    puVar5 = (uint *)0x0;
  }
  else {
    puVar5 = FUN_004027b1(pvVar4,(LPCSTR)(DAT_0040c0d0 + 4),DAT_0040c0d0);
  }
  iVar8 = *(int *)(DAT_0040c0d0 + 0x218);
  if ((iVar8 != 0) && (*(int *)(iVar8 + 0xc) != 0)) {
    iVar10 = 3;
    local_c = _strdup_exref;
    do {
      local_8 = (undefined4 *)(*(int *)(iVar8 + 8) + 0x1c);
      if (iVar10 == 2) {
        uVar14 = puVar5[6];
LAB_00403e7b:
        uVar6 = (*local_c)(uVar14);
        *local_8 = uVar6;
      }
      else {
        if (iVar10 == 3) {
          uVar14 = puVar5[5];
          goto LAB_00403e7b;
        }
        uVar6 = (*local_c)(puVar5[7]);
        *local_8 = uVar6;
        if (iVar10 == 1) break;
      }
      iVar10 = iVar10 + -1;
      iVar8 = *(int *)(iVar8 + 4);
    } while (iVar8 != 0);
  }
  DAT_0040c0e0 = FUN_004061d0((HWND)0x0,DAT_0040c098,(LPCSTR)puVar5[4],0x20c,100,0xca0000,
                              &DAT_0040c0b4);
  FUN_00402774((int)puVar5);
  uVar6 = 0x20;
  FUN_00401a7e(puVar5);
  pHVar7 = (HWND)FUN_00406114(DAT_0040c0e0,0x80);
  sprintf(local_16c,"%s\\%s%s",DAT_0040c084,DAT_0040c0c8,&DAT_0040a5e4,puVar5,uVar6);
  iVar8 = _access(local_16c,0);
  if (iVar8 == 0) {
    fuLoad = 0x10;
    name = local_16c;
  }
  else {
    fuLoad = 0;
    name = (LPCSTR)0x67;
  }
  lParam = LoadImageA(DAT_0040c058,name,0,0,0,fuLoad);
  if (lParam == (HANDLE)0x0) {
    FUN_00404d2c();
  }
  SendMessageA(pHVar7,0x172,0,(LPARAM)lParam);
  pcVar11 = local_20;
  DAT_0040c090 = (void *)(*local_20)(0x18);
  if (DAT_0040c090 == (void *)0x0) {
    DAT_0040c090 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)DAT_0040c090 + 0xc) = 0;
    *(undefined4 *)((int)DAT_0040c090 + 0x10) = 0;
    *(undefined4 *)((int)DAT_0040c090 + 8) = 0;
    *(undefined4 *)((int)DAT_0040c090 + 0x14) = 0;
  }
  local_8 = (undefined4 *)0x0;
  local_c = (code *)0x6;
  DAT_0040c0c4 = FUN_00405927(DAT_0040c0e0,*(int *)(DAT_0040c0d0 + 0x218),0x92,0x16e,&local_8,
                              (int *)&local_c,DAT_0040c090,(HWND)0x0);
  FUN_0040563a(DAT_0040c0e0,DAT_0040c0c4,*(int *)(DAT_0040c0d0 + 0x218),(int)local_8,0x16e,
               DAT_0040c090,0);
  pcVar13 = local_c;
  pcVar1 = local_c + 10;
  DAT_0040c088 = FUN_004060b2(DAT_0040c0e0,"BUTTON_MORE_OPTIONS",0xc,(int)pcVar1,DAT_0040c090,
                              0x4053ad,0);
  DAT_0040c074 = FUN_004060b2(DAT_0040c0e0,"BUTTON_SAVE",0x180,(int)pcVar1,DAT_0040c090,0x405332,0);
  DAT_0040c0d8 = FUN_004060b2(DAT_0040c0e0,"BUTTON_LAUNCH",0xfa,(int)pcVar1,DAT_0040c090,0x405250,1)
  ;
  DAT_0040c06c = FUN_004060b2(DAT_0040c0e0,"BUTTON_README",0xc,(int)pcVar1,DAT_0040c090,0x404de1,0);
  DAT_0040c060 = FUN_00405f5f((int)pcVar1);
  local_8 = (undefined4 *)0x0;
  DAT_0040c0c0 = pcVar13 + 0x2b;
  puVar9 = (undefined4 *)(*pcVar11)(0x10);
  if (puVar9 == (undefined4 *)0x0) {
    puVar9 = (undefined4 *)0x0;
  }
  else {
    puVar9[2] = 0;
    puVar9[1] = 0;
    puVar9[3] = 0;
  }
  iVar8 = *(int *)(DAT_0040c0d0 + 0x21c);
  DAT_0040c07c = puVar9;
  if (iVar8 != 0) {
    iVar10 = *(int *)(iVar8 + 0xc);
    while (iVar10 != 0) {
      local_c = pcVar13 + 6;
      local_24 = FUN_00405927(DAT_0040c0e0,(*(undefined4 **)(iVar8 + 8))[1],0x92,0x16e,&local_8,
                              (int *)&local_c,DAT_0040c090,(HWND)**(undefined4 **)(iVar8 + 8));
      puVar9 = DAT_0040c07c;
      piVar2 = DAT_0040c07c + 3;
      if (*piVar2 == 0) {
        *DAT_0040c07c = 0;
        puVar9[2] = local_24;
        iVar10 = 0;
      }
      else {
        pvVar4 = (void *)DAT_0040c07c[1];
        if (pvVar4 == (void *)0x0) {
          pvVar4 = (void *)(*local_20)(0x10);
          if (pvVar4 == (void *)0x0) {
            pvVar4 = (void *)0x0;
          }
          else {
            *(undefined4 *)((int)pvVar4 + 8) = 0;
            *(undefined4 *)((int)pvVar4 + 4) = 0;
            *(undefined4 *)((int)pvVar4 + 0xc) = 0;
          }
          puVar9[1] = pvVar4;
        }
        FUN_00401675(pvVar4,local_24);
        iVar10 = *piVar2;
        puVar9 = DAT_0040c07c;
      }
      *piVar2 = iVar10 + 1;
      iVar8 = *(int *)(iVar8 + 4);
      pcVar13 = local_c;
      iVar10 = iVar8;
    }
  }
  puVar3 = local_8;
  iVar8 = *(int *)(DAT_0040c0d0 + 0x21c);
  DAT_0040c078 = pcVar13 + 10;
  if (((puVar9 != (undefined4 *)0x0) && (puVar9[3] != 0)) && (iVar8 != 0)) {
    iVar10 = *(int *)(iVar8 + 0xc);
    while (iVar10 != 0) {
      FUN_0040563a(DAT_0040c0e0,(HWND)puVar9[2],(*(int **)(iVar8 + 8))[1],(int)puVar3,0x16e,
                   DAT_0040c090,**(int **)(iVar8 + 8));
      puVar9 = (undefined4 *)puVar9[1];
      if (puVar9 == (undefined4 *)0x0) break;
      iVar8 = *(int *)(iVar8 + 4);
      iVar10 = iVar8;
    }
  }
  GetWindowRect(DAT_0040c0d8,&local_34);
  DAT_0040c0a8 = local_34.left;
  DAT_0040c0ac = local_34.top;
  ScreenToClient(DAT_0040c0e0,(LPPOINT)&DAT_0040c0a8);
  GetWindowRect(DAT_0040c074,&local_34);
  DAT_0040c09c = local_34.left;
  DAT_0040c0a0 = local_34.top;
  ScreenToClient(DAT_0040c0e0,(LPPOINT)&DAT_0040c09c);
  FUN_00404602();
  local_1c.bottom = (LONG)DAT_0040c078;
  local_1c.left = 0;
  local_1c.top = 0;
  local_1c.right = 0x20c;
  AdjustWindowRect(&local_1c,0xca0000,0);
  FUN_00404393(extraout_ECX,&local_44);
  local_1c.right = local_1c.right - local_1c.left;
  local_1c.bottom = local_1c.bottom + -local_1c.top;
  local_1c.left = ((local_44.right - local_1c.right) - local_44.left) / 2 + local_44.left;
  local_1c.top = ((local_44.bottom - local_1c.bottom) - local_44.top) / 2 + local_44.top;
  pcVar11 = DAT_0040c0c0 + (local_1c.bottom - (int)DAT_0040c078);
  if (DAT_0040c05c != 0) {
    pcVar11 = (code *)local_1c.bottom;
  }
  if (local_44.top <= local_1c.top) {
    local_44.top = local_1c.top;
  }
  SetWindowPos(DAT_0040c0e0,(HWND)0x0,local_1c.left,local_44.top,local_1c.right,(int)pcVar11,4);
  ShowWindow(DAT_0040c0e0,5);
  UpdateWindow(DAT_0040c0e0);
  while (BVar12 = GetMessageA(&local_60,(HWND)0x0,0,0), BVar12 != 0) {
    pHVar7 = DAT_0040c0e0;
    if (DAT_0040c0dc != (HWND)0x0) {
      pHVar7 = DAT_0040c0dc;
    }
    BVar12 = IsDialogMessageA(pHVar7,&local_60);
    if (BVar12 == 0) {
      TranslateMessage(&local_60);
      DispatchMessageA(&local_60);
    }
  }
  return local_60.wParam;
}



/* VA 0040433b */

void __fastcall FUN_0040433b(LPCSTR param_1,WNDPROC param_2)

{
  WNDCLASSEXA local_34;

  local_34.cbSize = 0x30;
  local_34.lpszMenuName = (LPCSTR)0x0;
  local_34.cbClsExtra = 0;
  local_34.cbWndExtra = 0;
  local_34.hInstance = DAT_0040c058;
  local_34.hCursor = DAT_0040c094;
  local_34.style = 3;
  local_34.hIcon = DAT_0040c0e8;
  local_34.hbrBackground = (HBRUSH)0x6;
  local_34.hIconSm = DAT_0040c0e8;
  local_34.lpfnWndProc = param_2;
  local_34.lpszClassName = param_1;
  RegisterClassExA(&local_34);
  return;
}



/* VA 00404393 */

void __fastcall FUN_00404393(undefined4 param_1,LPRECT param_2)

{
  HWND hWnd;
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_30;
  undefined4 local_2c [4];
  LONG local_1c;
  LONG LStack_18;
  LONG LStack_14;
  LONG LStack_10;

  if ((DAT_0040c054 != (code *)0x0) && (DAT_0040c050 != (code *)0x0)) {
    local_30 = 0x28;
    puVar2 = local_2c;
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    iVar1 = (*DAT_0040c054)(DAT_0040c0e0,2);
    if ((iVar1 != 0) && (iVar1 = (*DAT_0040c050)(iVar1,&local_30), iVar1 != 0)) {
      param_2->left = local_1c;
      param_2->top = LStack_18;
      param_2->right = LStack_14;
      param_2->bottom = LStack_10;
      return;
    }
  }
  hWnd = GetDesktopWindow();
  GetWindowRect(hWnd,param_2);
  return;
}



/* VA 004043fd */

void __fastcall FUN_004043fd(uint param_1,undefined4 param_2,int param_3)

{
  int iVar1;

  if (param_3 != 0) {
    iVar1 = *(int *)(param_3 + 0x14);
    while (iVar1 != 0) {
      if (*(uint *)(param_3 + 0xc) == (param_1 & 0xffff)) {
        if (*(code **)(param_3 + 0x10) == (code *)0x0) {
          return;
        }
        (**(code **)(param_3 + 0x10))(param_2,param_1 >> 0x10);
        return;
      }
      param_3 = *(int *)(param_3 + 8);
      iVar1 = param_3;
    }
  }
  return;
}



/* VA 00404432 */

void __fastcall FUN_00404432(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  HANDLE hFindFile;
  void *pvVar4;
  char *pcVar5;
  BOOL BVar6;
  CHAR *_Src;
  _WIN32_FIND_DATAA local_24c;
  char local_10c [264];

  iVar1 = *(int *)(param_1 + 800);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0xc);
    while (iVar2 != 0) {
      iVar2 = *(int *)(*(int *)(iVar1 + 8) + 4);
      if (iVar2 != 0) {
        iVar3 = *(int *)(iVar2 + 0xc);
        while (iVar3 != 0) {
          iVar3 = *(int *)(iVar2 + 8);
          if ((*(int *)(iVar3 + 4) == 2) || (*(int *)(iVar3 + 4) == 3)) {
            strcpy(local_10c,*(char **)(iVar3 + 0xc));
            _strupr(local_10c);
            iVar3 = strcmp(local_10c,"FILE");
            if (iVar3 == 0) {
              strcpy(local_10c,*(char **)(*(int *)(iVar2 + 8) + 8));
              _strupr(local_10c);
              iVar3 = strcmp(local_10c,"THRASH");
              if (iVar3 == 0) {
                strcpy(local_10c,(char *)(param_1 + 0x10));
                strcat(local_10c,"\\*.dll");
                hFindFile = FindFirstFileA(local_10c,&local_24c);
                if (hFindFile == (HANDLE)0xffffffff) {
                  return;
                }
                iVar1 = *(int *)(iVar2 + 8);
                pvVar4 = *(void **)(iVar1 + 0x24);
                if (pvVar4 != (void *)0x0) {
                  FUN_004010ae((int)pvVar4);
                  FUN_00401a7e(pvVar4);
                }
                pvVar4 = operator_new(0x18);
                if (pvVar4 == (void *)0x0) {
                  pvVar4 = (void *)0x0;
                }
                else {
                  *(undefined4 *)((int)pvVar4 + 0xc) = 0;
                  *(undefined4 *)((int)pvVar4 + 0x10) = 0;
                  *(undefined4 *)((int)pvVar4 + 8) = 0;
                  *(undefined4 *)((int)pvVar4 + 0x14) = 0;
                }
                *(void **)(iVar1 + 0x24) = pvVar4;
                do {
                  if (((byte)local_24c.dwFileAttributes & 0x10) == 0) {
                    _Src = local_24c.cFileName;
                    pcVar5 = _strdup(_Src);
                    FUN_00401044(*(void **)(iVar1 + 0x24),pcVar5,pcVar5,_Src,0);
                  }
                  BVar6 = FindNextFileA(hFindFile,&local_24c);
                } while (BVar6 != 0);
                return;
              }
            }
          }
          iVar2 = *(int *)(iVar2 + 4);
          iVar3 = iVar2;
        }
      }
      iVar1 = *(int *)(iVar1 + 4);
      iVar2 = iVar1;
    }
  }
  return;
}



/* VA 004045c1 */

void __fastcall FUN_004045c1(HWND param_1,char *param_2,LPSIZE param_3)

{
  HDC hdc;
  size_t c;

  hdc = GetDC(param_1);
  SelectObject(hdc,DAT_0040c068);
  c = strlen(param_2);
  GetTextExtentPoint32A(hdc,param_2,c,param_3);
  ReleaseDC(param_1,hdc);
  return;
}



/* VA 00404602 */

void FUN_00404602(void)

{
  int iVar1;
  int iVar2;
  LPCSTR lpString;
  LPCSTR lpString_00;
  code *pcVar3;
  tagRECT local_18;
  int local_8;

  if (DAT_0040c05c == 0) {
    FUN_004020f1(DAT_0040c0d0,"BUTTON_MORE_OPTIONS");
    SetWindowTextA(DAT_0040c088,lpString_00);
    pcVar3 = SetWindowPos_exref;
    SetWindowPos(DAT_0040c088,DAT_0040c0c4,0,0,0,0,3);
    SetWindowPos(DAT_0040c074,DAT_0040c0d8,DAT_0040c09c,DAT_0040c0a0,0,0,1);
    SetWindowPos(DAT_0040c0d8,DAT_0040c088,DAT_0040c0a8,DAT_0040c0ac,0,0,1);
    SetWindowPos(DAT_0040c060,(HWND)0x0,0,0,0,0,0x87);
    SetWindowPos(DAT_0040c06c,(HWND)0x0,0,0,0,0,0x87);
    if (DAT_0040c07c != 0) {
      iVar1 = DAT_0040c07c;
      iVar2 = *(int *)(DAT_0040c07c + 0xc);
      while (iVar2 != 0) {
        SetWindowPos(*(HWND *)(iVar1 + 8),(HWND)0x0,0,0,0,0,0x87);
        iVar1 = *(int *)(iVar1 + 4);
        iVar2 = iVar1;
      }
    }
  }
  else {
    FUN_004020f1(DAT_0040c0d0,"BUTTON_LESS_OPTIONS");
    SetWindowTextA(DAT_0040c088,lpString);
    GetWindowRect(DAT_0040c088,&local_18);
    ScreenToClient(DAT_0040c0e0,(LPPOINT)&local_18);
    pcVar3 = SetWindowPos_exref;
    local_18.top = local_18.top + 0x1d;
    SetWindowPos(DAT_0040c074,DAT_0040c088,local_18.left,local_18.top,0,0,1);
    local_18.top = local_18.top + 0x1d;
    SetWindowPos(DAT_0040c0d8,DAT_0040c074,local_18.left,local_18.top,0,0,1);
    local_18.top = local_18.top + 0x1d;
    SetWindowPos(DAT_0040c060,(HWND)0x0,local_18.left,local_18.top,0,0,0x45);
    local_18.top = local_18.top + 8;
    SetWindowPos(DAT_0040c06c,DAT_0040c0d8,local_18.left,local_18.top,0,0,0x41);
    SetWindowPos(DAT_0040c0c4,DAT_0040c06c,0,0,0,0,3);
    local_18.top = local_18.top + 0x21;
    if (DAT_0040c078 < local_18.top) {
      DAT_0040c078 = local_18.top;
    }
    if (DAT_0040c07c != 0) {
      iVar1 = DAT_0040c07c;
      iVar2 = *(int *)(DAT_0040c07c + 0xc);
      while (iVar2 != 0) {
        SetWindowPos(*(HWND *)(iVar1 + 8),(HWND)0x0,0,0,0,0,0x47);
        iVar1 = *(int *)(iVar1 + 4);
        iVar2 = iVar1;
      }
    }
  }
  if (local_8 != 0) {
    local_18.bottom = DAT_0040c0c0;
    if (DAT_0040c05c != 0) {
      local_18.bottom = DAT_0040c078;
    }
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0x20c;
    AdjustWindowRect(&local_18,0xca0000,0);
    (*pcVar3)(DAT_0040c0e0,0,0,0,local_18.right - local_18.left,local_18.bottom - local_18.top,6);
  }
  return;
}



/* VA 00404840 */

void __cdecl FUN_00404840(undefined4 param_1)

{
  void *this;
  uint *puVar1;
  uint lParam;
  int iVar2;
  int iVar3;
  char local_10c [264];

  sprintf(local_10c,"%s\\%s",DAT_0040c070 + 0x10,param_1);
  this = operator_new(0x20);
  if (this == (void *)0x0) {
    puVar1 = (uint *)0x0;
  }
  else {
    puVar1 = FUN_004027b1(this,local_10c,DAT_0040c0d0);
  }
  iVar3 = *(int *)(DAT_0040c070 + 0x31c);
  if ((iVar3 != 0) && (*(int *)(iVar3 + 0xc) != 0)) {
    iVar2 = 3;
    do {
      if (iVar2 == 2) {
        lParam = puVar1[6];
      }
      else if (iVar2 == 3) {
        lParam = puVar1[5];
      }
      else {
        lParam = puVar1[7];
      }
      SendMessageA(*(HWND *)(*(int *)(iVar3 + 8) + 0x18),0xc,0,lParam);
      iVar2 = iVar2 + -1;
    } while ((iVar2 != 0) && (iVar3 = *(int *)(iVar3 + 4), iVar3 != 0));
  }
  if (puVar1 != (uint *)0x0) {
    FUN_00402774((int)puVar1);
    FUN_00401a7e(puVar1);
  }
  return;
}



/* VA 004048fc */

void __cdecl FUN_004048fc(char *param_1)

{
  int iVar1;
  HANDLE lParam;
  char local_104 [256];

  strcpy(local_104,param_1);
  _strupr(local_104);
  iVar1 = strcmp(local_104,"D3D");
  if (iVar1 == 0) {
    lParam = DAT_0040c0ec;
    if (DAT_0040c0ec == (HANDLE)0x0) {
      lParam = LoadImageA(DAT_0040c058,(LPCSTR)0x69,0,0,0,0);
      DAT_0040c0ec = lParam;
    }
  }
  else {
    iVar1 = strcmp(local_104,"VOODOO");
    if (iVar1 == 0) {
      lParam = DAT_0040c0e4;
      if (DAT_0040c0e4 == (HANDLE)0x0) {
        lParam = LoadImageA(DAT_0040c058,(LPCSTR)0x68,0,0,0,0);
        DAT_0040c0e4 = lParam;
      }
    }
    else {
      iVar1 = strcmp(local_104,"OPENGL");
      if (iVar1 == 0) {
        lParam = DAT_0040c0bc;
        if (DAT_0040c0bc == (HANDLE)0x0) {
          lParam = LoadImageA(DAT_0040c058,(LPCSTR)0x6a,0,0,0,0);
          DAT_0040c0bc = lParam;
        }
      }
      else {
        iVar1 = strcmp(local_104,"SOFTWARE");
        if (iVar1 == 0) {
          lParam = DAT_0040c0a4;
          if (DAT_0040c0a4 == (HANDLE)0x0) {
            lParam = LoadImageA(DAT_0040c058,(LPCSTR)0x6b,0,0,0,0);
            DAT_0040c0a4 = lParam;
          }
        }
        else {
          lParam = DAT_0040c0cc;
          if (DAT_0040c0cc == (HANDLE)0x0) {
            lParam = LoadImageA(DAT_0040c058,(LPCSTR)0x6c,0,0,0,0);
            DAT_0040c0cc = lParam;
          }
        }
      }
    }
  }
  SendMessageA(DAT_0040c080,0x172,0,(LPARAM)lParam);
  return;
}



/* VA 00404a4e */

void __fastcall FUN_00404a4e(int param_1,char *param_2,undefined *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char local_10c [256];
  int local_c;
  char *local_8;

  iVar1 = *(int *)(DAT_0040c070 + 800);
  if (iVar1 != 0) {
    iVar4 = 0;
    local_c = param_1;
    local_8 = param_2;
    iVar2 = *(int *)(iVar1 + 0xc);
    while (iVar2 != 0) {
      iVar2 = *(int *)(*(int *)(iVar1 + 8) + 4);
      if (iVar2 != 0) {
        iVar3 = *(int *)(iVar2 + 0xc);
        while (iVar3 != 0) {
          strcpy(local_10c,*(char **)(*(int *)(iVar2 + 8) + 8));
          _strupr(local_10c);
          iVar3 = strcmp(local_10c,"THRASH");
          if (iVar3 == 0) {
            strcpy(local_10c,*(char **)(*(int *)(iVar2 + 8) + 0xc));
            _strupr(local_10c);
            iVar3 = strcmp(local_10c,local_8);
            if (iVar3 == 0) {
              iVar1 = *(int *)(*(int *)(iVar2 + 8) + 0x24);
              if (iVar1 == 0) {
                return;
              }
              iVar2 = *(int *)(iVar1 + 0x14);
              while( true ) {
                if (iVar2 == 0) {
                  return;
                }
                if (iVar4 == local_c) break;
                iVar1 = *(int *)(iVar1 + 8);
                iVar4 = iVar4 + 1;
                iVar2 = iVar1;
              }
              (*(code *)param_3)(*(undefined4 *)(iVar1 + 0xc));
              return;
            }
          }
          iVar2 = *(int *)(iVar2 + 4);
          iVar3 = iVar2;
        }
      }
      iVar1 = *(int *)(iVar1 + 4);
      iVar2 = iVar1;
    }
  }
  return;
}



/* VA 00404b3d */

undefined4 __fastcall FUN_00404b3d(char *param_1)

{
  bool bVar1;
  int iVar2;
  HRSRC hResInfo;
  HGLOBAL hResData;
  byte *pbVar3;
  DWORD DVar4;
  void *this;
  UINT uID;
  char local_35c [256];
  CHAR local_25c [256];
  char local_15c [264];
  undefined **local_54 [8];
  int local_34;
  char *local_8;

  local_8 = param_1;
  sprintf(local_15c,"%s\\%s%s",DAT_0040c084,DAT_0040c0c8,&DAT_0040a57c);
  uID = 0;
  iVar2 = _access(local_15c,0);
  if (iVar2 == 0) {
    FUN_00407992(local_54,local_15c);
    bVar1 = FUN_0040728e(local_54,(char *)(local_34 + 8));
    if (bVar1) {
      DAT_0040c0d0 = FUN_0040212b(local_54,param_1);
      if (DAT_0040c0d0 == (undefined4 *)0x0) {
        uID = 0xca;
      }
    }
    else {
      DVar4 = GetLastError();
      uID = (DVar4 != 2) + 200;
    }
    local_54[0] = &PTR_FUN_0040a654;
    FUN_00407881(local_54);
  }
  else {
    hResInfo = FindResourceA(DAT_0040c058,(LPCSTR)0x2,(LPCSTR)0xa);
    if (hResInfo == (HRSRC)0x0) {
      uID = 200;
    }
    else {
      hResData = LoadResource(DAT_0040c058,hResInfo);
      if (hResData == (HGLOBAL)0x0) {
        uID = 0xc9;
      }
      else {
        pbVar3 = LockResource(hResData);
        if (pbVar3 == (byte *)0x0) {
          uID = 0xc9;
        }
        else {
          FUN_00407969(local_54);
          FUN_00408d67(this,pbVar3,(undefined4 *)0x0,0);
          DAT_0040c0d0 = FUN_0040212b(local_54,local_8);
          local_54[0] = &PTR_FUN_0040a654;
          if (DAT_0040c0d0 == (undefined4 *)0x0) {
            uID = 0xca;
          }
          FUN_00407881(local_54);
        }
        FreeResource(hResData);
      }
    }
  }
  if (uID == 0) {
    iVar2 = FUN_00404d0a((char *)(DAT_0040c0d0 + 1));
    if ((iVar2 != 0) && (iVar2 = FUN_00404d0a((char *)(DAT_0040c0d0 + 0x42)), iVar2 != 0)) {
      DAT_0040c05c = *DAT_0040c0d0;
      return 1;
    }
  }
  else {
    LoadStringA(DAT_0040c058,uID,local_25c,0x100);
    sprintf(local_35c,local_25c,local_15c);
    MessageBoxA((HWND)0x0,local_35c,"Error",0x10);
  }
  return 0;
}



/* VA 00404d0a */

undefined4 __fastcall FUN_00404d0a(char *param_1)

{
  int iVar1;

  iVar1 = _access(param_1,0);
  if (iVar1 != 0) {
    FUN_00404d2c();
    return 0;
  }
  return 1;
}



/* VA 00404d2c */

void FUN_00404d2c(void)

{
  char *_Format;
  LPCSTR lpCaption;
  UINT uType;
  char local_104 [256];

  FUN_004020f1(DAT_0040c0d0,"ERROR_FILE_NOT_FOUND");
  sprintf(local_104,_Format);
  uType = 0x10;
  FUN_004020f1(DAT_0040c0d0,"ERROR_TITLE");
  MessageBoxA(DAT_0040c0e0,local_104,lpCaption,uType);
  return;
}



/* VA 00404d7f */

void __fastcall FUN_00404d7f(HWND param_1,HWND param_2,HWND param_3)

{
  if (param_2 != (HWND)0x0) {
    SetWindowPos(param_1,param_2,0,0,0,0,3);
  }
  if (param_3 != (HWND)0x0) {
    SetWindowPos(param_3,param_1,0,0,0,0,3);
  }
  return;
}



/* VA 00404db3 */

void __fastcall FUN_00404db3(HWND param_1)

{
  SendMessageA(param_1,0x30,DAT_0040c068,1);
  return;
}



/* VA 00404dc5 */

int __fastcall FUN_00404dc5(void *param_1,int param_2)

{
  int iVar1;

  iVar1 = 0;
  if ((param_1 != (void *)0x0) && (param_2 != 0)) {
    iVar1 = *(int *)((int)param_1 + 0x14) + 1;
    FUN_004016c5(param_1,iVar1,param_2);
  }
  return iVar1;
}



/* VA 00404de1 */

void __cdecl FUN_00404de1(undefined4 param_1,short param_2)

{
  int iVar1;

  if (param_2 == 0) {
    iVar1 = FUN_00404d0a(*(char **)(DAT_0040c0d0 + 0x22c));
    if (iVar1 != 0) {
      ShellExecuteA((HWND)0x0,(LPCSTR)0x0,*(LPCSTR *)(DAT_0040c0d0 + 0x22c),(LPCSTR)0x0,(LPCSTR)0x0,
                    5);
    }
  }
  return;
}



/* VA 00404e1b */

void __cdecl FUN_00404e1b(HWND param_1,short param_2)

{
  int iVar1;

  if (param_2 == 0) {
    iVar1 = 0;
    while( true ) {
      param_1 = GetWindow(param_1,3);
      if (param_1 == (HWND)0x0) break;
      iVar1 = iVar1 + 1;
    }
    FUN_00404a4e(iVar1,"TYPE",FUN_004048fc);
  }
  return;
}



/* VA 00404e52 */

void __cdecl FUN_00404e52(HWND param_1,short param_2)

{
  LRESULT LVar1;

  if (param_2 == 1) {
    LVar1 = SendMessageA(param_1,0x147,0,0);
    FUN_00404a4e(LVar1,"TYPE",FUN_004048fc);
  }
  return;
}



/* VA 00404e82 */

void __cdecl FUN_00404e82(HWND param_1,short param_2)

{
  int iVar1;

  if (param_2 == 0) {
    iVar1 = 0;
    while( true ) {
      param_1 = GetWindow(param_1,3);
      if (param_1 == (HWND)0x0) break;
      iVar1 = iVar1 + 1;
    }
    FUN_00404a4e(iVar1,"FILE",FUN_00404840);
  }
  return;
}



/* VA 00404eb9 */

void __cdecl FUN_00404eb9(HWND param_1,short param_2)

{
  LRESULT LVar1;

  if (param_2 == 1) {
    LVar1 = SendMessageA(param_1,0x147,0,0);
    FUN_00404a4e(LVar1,"FILE",FUN_00404840);
  }
  return;
}



/* VA 00404ee9 */

void __cdecl FUN_00404ee9(undefined4 param_1,short param_2)

{
  int iVar1;

  if (((param_2 == 0) && (*(int *)(DAT_0040c070 + 0xc) != 0)) &&
     (iVar1 = FUN_00404d0a((char *)(DAT_0040c070 + 0x114)), iVar1 != 0)) {
    ShellExecuteA((HWND)0x0,(LPCSTR)0x0,(LPCSTR)(DAT_0040c070 + 0x114),(LPCSTR)0x0,(LPCSTR)0x0,5);
  }
  return;
}



/* VA 00404f2a */

void __cdecl FUN_00404f2a(undefined4 param_1,short param_2)

{
  if (param_2 == 0) {
    SendMessageA(DAT_0040c0dc,0x10,0,0);
  }
  return;
}



/* VA 00404f48 */

void __cdecl FUN_00404f48(undefined4 param_1,short param_2)

{
  if (param_2 == 0) {
    FUN_0040540d(*(int *)(DAT_0040c070 + 800));
    SendMessageA(DAT_0040c0dc,0x10,0,0);
  }
  return;
}



/* VA 00404f77 */

void __cdecl FUN_00404f77(HWND param_1,short param_2)

{
  float fVar1;
  HWND hWnd;
  int iVar2;
  LRESULT LVar3;
  char *pcVar4;
  int iVar5;
  char *_Format;
  LPCSTR lpCaption;
  int iVar6;
  float fVar7;
  double dVar8;
  UINT UVar9;
  char local_21c [20];
  char local_208 [256];
  char local_108 [260];

  if (param_2 != 0) {
    return;
  }
  hWnd = GetWindow(param_1,3);
  iVar2 = FUN_004020b5((int)hWnd);
  iVar6 = *(int *)(iVar2 + 4);
  if (iVar6 == 0) {
    SendMessageA(hWnd,0xd,0x100,(LPARAM)local_208);
    atoi(local_208);
    sprintf(local_208,"%d");
  }
  else if (iVar6 == 1) {
    SendMessageA(hWnd,0xd,0x100,(LPARAM)local_208);
    dVar8 = atof(local_208);
    fVar1 = (float)dVar8;
    fVar7 = *(float *)(iVar2 + 0x20);
    if ((*(float *)(iVar2 + 0x20) <= fVar1) &&
       (fVar7 = *(float *)(iVar2 + 0x24), fVar1 <= *(float *)(iVar2 + 0x24))) {
      fVar7 = fVar1;
    }
    if (*(int *)(iVar2 + 0x28) == 0) {
      pcVar4 = "%f";
    }
    else {
      sprintf(local_21c,"%%.%df");
      pcVar4 = local_21c;
    }
    sprintf(local_208,pcVar4,(double)fVar7);
  }
  else if (iVar6 == 2) {
    iVar5 = SendMessageA(hWnd,0x147,0,0);
    iVar6 = *(int *)(iVar2 + 0x24);
    if (iVar6 != 0) {
      iVar2 = *(int *)(iVar6 + 0x14);
      while (iVar2 != 0) {
        if (iVar5 == 0) {
          pcVar4 = *(char **)(iVar6 + 0xc);
          goto LAB_004050a8;
        }
        iVar5 = iVar5 + -1;
        iVar6 = *(int *)(iVar6 + 8);
        iVar2 = iVar6;
      }
    }
  }
  else if (iVar6 == 3) {
    iVar6 = 0;
    UVar9 = 5;
    while ((hWnd = GetWindow(hWnd,UVar9), hWnd != (HWND)0x0 &&
           (LVar3 = SendMessageA(hWnd,0xf0,0,0), LVar3 == 0))) {
      iVar6 = iVar6 + 1;
      UVar9 = 2;
    }
    iVar2 = *(int *)(iVar2 + 0x24);
    if (iVar2 != 0) {
      iVar5 = *(int *)(iVar2 + 0x14);
      while (iVar5 != 0) {
        if (iVar6 == 0) {
          pcVar4 = *(char **)(iVar2 + 0xc);
          goto LAB_004050a8;
        }
        iVar6 = iVar6 + -1;
        iVar2 = *(int *)(iVar2 + 8);
        iVar5 = iVar2;
      }
    }
  }
  else {
    if (iVar6 == 4) {
      LVar3 = SendMessageA(hWnd,0xf0,0,0);
      pcVar4 = "1";
      if (LVar3 != 1) {
        pcVar4 = "0";
      }
    }
    else {
      if (iVar6 != 5) {
        SendMessageA(hWnd,0xd,0x100,(LPARAM)local_208);
        goto LAB_00405184;
      }
      pcVar4 = *(char **)(iVar2 + 0x1c);
    }
LAB_004050a8:
    strcpy(local_208,pcVar4);
  }
LAB_00405184:
  iVar6 = 0;
  pcVar4 = strchr(local_208,0x40);
  if (pcVar4 != (char *)0x0) {
    *pcVar4 = '\0';
    iVar6 = atoi(pcVar4 + 1);
  }
  iVar2 = *(int *)(DAT_0040c0d0 + 0x220);
  if (iVar2 != 0) {
    iVar5 = *(int *)(iVar2 + 0xc);
    while (iVar5 != 0) {
      iVar5 = strcmp((char *)**(undefined4 **)(iVar2 + 8),local_208);
      if (iVar5 == 0) {
        iVar2 = *(int *)(iVar2 + 8);
        if (iVar2 != 0) {
          iVar5 = FUN_00404d0a((char *)(iVar2 + 0x218));
          if (iVar5 == 0) {
            return;
          }
          FUN_00403a22(iVar2,iVar6);
          return;
        }
        break;
      }
      iVar2 = *(int *)(iVar2 + 4);
      iVar5 = iVar2;
    }
  }
  FUN_004020f1(DAT_0040c0d0,"ERROR_DRIVER_NOT_FOUND");
  sprintf(local_108,_Format);
  UVar9 = 0x10;
  FUN_004020f1(DAT_0040c0d0,"ERROR_TITLE");
  MessageBoxA(DAT_0040c0e0,local_108,lpCaption,UVar9);
  return;
}



/* VA 00405250 */

void __cdecl FUN_00405250(undefined4 param_1,short param_2)

{
  LPCSTR extraout_EAX;
  LPCSTR lpText;
  int iVar1;
  LPCSTR extraout_EAX_00;
  LPCSTR lpText_00;
  LPCSTR pCVar2;
  UINT UVar3;

  if (param_2 == 0) {
    if (DAT_0040c0d4 == (HANDLE)0x0) {
      FUN_0040542e(*(int *)(DAT_0040c0d0 + 0x218));
      FUN_0040540d(*(int *)(DAT_0040c0d0 + 0x21c));
      iVar1 = FUN_00402067();
      if (iVar1 == 0) {
        UVar3 = 0x10;
        FUN_004020f1(DAT_0040c0d0,"ERROR_TITLE");
        pCVar2 = extraout_EAX_00;
        FUN_004020f1(DAT_0040c0d0,"ERROR_NOT_SAVED");
        MessageBoxA(DAT_0040c0e0,lpText_00,pCVar2,UVar3);
        return;
      }
      iVar1 = FUN_00404d0a((char *)(DAT_0040c0d0 + 4));
      if (iVar1 != 0) {
        CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00406254,(LPVOID)(DAT_0040c0d0 + 4),0,
                     (LPDWORD)&param_2);
      }
    }
    else {
      UVar3 = 0x31;
      FUN_004020f1(DAT_0040c0d0,"WARN_TITLE");
      pCVar2 = extraout_EAX;
      FUN_004020f1(DAT_0040c0d0,"ERROR_STILL_RUNNING");
      iVar1 = MessageBoxA(DAT_0040c0e0,lpText,pCVar2,UVar3);
      if (iVar1 == 1) {
        TerminateProcess(DAT_0040c0d4,0);
        return;
      }
    }
  }
  return;
}



/* VA 00405332 */

void __cdecl FUN_00405332(undefined4 param_1,short param_2)

{
  int iVar1;
  LPCSTR extraout_EAX;
  LPCSTR extraout_EAX_00;
  LPCSTR lpText;
  char *pcVar2;
  LPCSTR lpCaption;
  UINT uType;

  if (param_2 == 0) {
    FUN_0040542e(*(int *)(DAT_0040c0d0 + 0x218));
    FUN_0040540d(*(int *)(DAT_0040c0d0 + 0x21c));
    iVar1 = FUN_00402067();
    if (iVar1 == 0) {
      uType = 0x10;
      FUN_004020f1(DAT_0040c0d0,"ERROR_TITLE");
      pcVar2 = "ERROR_NOT_SAVED";
      lpCaption = extraout_EAX_00;
    }
    else {
      uType = 0x40;
      FUN_004020f1(DAT_0040c0d0,"INFO_TITLE");
      pcVar2 = "INFO_SAVED";
      lpCaption = extraout_EAX;
    }
    FUN_004020f1(DAT_0040c0d0,pcVar2);
    MessageBoxA(DAT_0040c0e0,lpText,lpCaption,uType);
  }
  return;
}



/* VA 004053ad */

void __cdecl FUN_004053ad(undefined4 param_1,short param_2)

{
  if (param_2 == 0) {
    DAT_0040c05c = (uint)(DAT_0040c05c == 0);
    FUN_00404602();
    return;
  }
  return;
}



/* VA 004053d2 */

void __cdecl FUN_004053d2(HWND param_1,short param_2)

{
  HWND hWnd;

  if (param_2 == 0) {
    hWnd = GetWindow(param_1,2);
    SendMessageA(hWnd,0x201,1,0);
    SendMessageA(hWnd,0x202,1,0);
  }
  return;
}



/* VA 0040540d */

void __fastcall FUN_0040540d(int param_1)

{
  int iVar1;

  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    while (iVar1 != 0) {
      FUN_0040542e(*(int *)(*(int *)(param_1 + 8) + 4));
      param_1 = *(int *)(param_1 + 4);
      iVar1 = param_1;
    }
  }
  return;
}



/* VA 0040542e */

void __fastcall FUN_0040542e(int param_1)

{
  int iVar1;
  float fVar2;
  char *pcVar3;
  LRESULT LVar4;
  HWND hWnd;
  int iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  double dVar9;
  char local_120 [256];
  char local_20 [20];
  int local_c;
  int local_8;

  if (param_1 != 0) {
    iVar7 = *(int *)(param_1 + 0xc);
    while (iVar7 != 0) {
      iVar7 = *(int *)(param_1 + 8);
      iVar6 = *(int *)(iVar7 + 4);
      local_c = iVar7;
      if (iVar6 == 0) {
        SendMessageA(*(HWND *)(iVar7 + 0x18),0xd,0x14,(LPARAM)local_20);
        iVar5 = atoi(local_20);
        iVar6 = *(int *)(iVar7 + 0x20);
        *(int *)(iVar7 + 0x28) = iVar5;
        if ((iVar5 < iVar6) || (iVar6 = *(int *)(iVar7 + 0x24), iVar6 < iVar5)) {
          *(int *)(iVar7 + 0x28) = iVar6;
        }
      }
      else if (iVar6 == 1) {
        SendMessageA(*(HWND *)(iVar7 + 0x18),0xd,0x14,(LPARAM)local_20);
        dVar9 = atof(local_20);
        fVar2 = (float)dVar9;
        fVar8 = *(float *)(iVar7 + 0x20);
        *(float *)(iVar7 + 0x2c) = fVar2;
        if ((fVar2 < fVar8) || (fVar8 = *(float *)(iVar7 + 0x24), fVar8 < fVar2)) {
          *(float *)(iVar7 + 0x2c) = fVar8;
        }
      }
      else if (iVar6 == 2) {
        if (*(int *)(iVar7 + 0x20) != 0) {
          free(*(void **)(iVar7 + 0x20));
        }
        iVar5 = SendMessageA(*(HWND *)(iVar7 + 0x18),0x147,0,0);
        iVar6 = *(int *)(iVar7 + 0x24);
        if (iVar6 != 0) {
          iVar1 = *(int *)(iVar6 + 0x14);
          while (iVar1 != 0) {
            if (iVar5 == 0) {
              pcVar3 = *(char **)(iVar6 + 0xc);
              goto LAB_004055a8;
            }
            iVar5 = iVar5 + -1;
            iVar6 = *(int *)(iVar6 + 8);
            iVar1 = iVar6;
          }
        }
      }
      else if (iVar6 == 3) {
        if (*(int *)(iVar7 + 0x20) != 0) {
          free(*(void **)(iVar7 + 0x20));
        }
        local_8 = 0;
        hWnd = GetWindow(*(HWND *)(iVar7 + 0x18),5);
        iVar6 = local_8;
        while ((hWnd != (HWND)0x0 &&
               (LVar4 = SendMessageA(hWnd,0xf0,0,0), iVar7 = local_c, LVar4 == 0))) {
          iVar6 = iVar6 + 1;
          hWnd = GetWindow(hWnd,2);
          iVar7 = local_c;
        }
        iVar5 = *(int *)(iVar7 + 0x24);
        local_8 = iVar6;
        if ((iVar5 != 0) && (*(int *)(iVar5 + 0x14) != 0)) {
LAB_0040554a:
          if (iVar6 != 0) goto code_r0x0040554e;
          pcVar3 = *(char **)(iVar5 + 0xc);
LAB_004055a8:
          pcVar3 = _strdup(pcVar3);
          goto LAB_004054d8;
        }
      }
      else if (iVar6 == 4) {
        LVar4 = SendMessageA(*(HWND *)(iVar7 + 0x18),0xf0,0,0);
        pcVar3 = (char *)(uint)(LVar4 == 1);
LAB_004054d8:
        *(char **)(iVar7 + 0x20) = pcVar3;
      }
      else if (iVar6 == 6) {
        if (*(int *)(iVar7 + 0x1c) != 0) {
          free(*(void **)(iVar7 + 0x1c));
        }
        SendMessageA(*(HWND *)(iVar7 + 0x18),0xd,0x100,(LPARAM)local_120);
        pcVar3 = _strdup(local_120);
        *(char **)(iVar7 + 0x1c) = pcVar3;
      }
LAB_0040562a:
      param_1 = *(int *)(param_1 + 4);
      iVar7 = param_1;
    }
  }
  return;
code_r0x0040554e:
  iVar5 = *(int *)(iVar5 + 8);
  iVar6 = iVar6 + -1;
  if (iVar5 == 0) goto LAB_0040562a;
  goto LAB_0040554a;
}



/* VA 0040563a */

void __fastcall
FUN_0040563a(HWND param_1,HWND param_2,int param_3,int param_4,int param_5,void *param_6,int param_7
            )

{
  int iVar1;
  char *_Str;
  int iVar2;
  undefined4 extraout_EAX;
  int iVar3;
  HWND pHVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  HWND local_140;
  code *local_134;
  char local_108 [260];

  iVar8 = param_4 + 0x18;
  iVar5 = param_5 - iVar8;
  iVar7 = 10;
  if (param_7 != 0) {
    iVar7 = 0xf;
  }
  if (param_3 != 0) {
    iVar1 = *(int *)(param_3 + 0xc);
    while (iVar1 != 0) {
      iVar1 = *(int *)(param_3 + 8);
      local_140 = (HWND)0x0;
      bVar9 = false;
      _Str = _strdup(*(char **)(iVar1 + 0xc));
      if (_Str != (char *)0x0) {
        _strupr(_Str);
        iVar2 = strcmp(_Str,"THRASHDRIVER");
        bVar9 = iVar2 == 0;
        free(_Str);
      }
      iVar2 = iVar5 + -8;
      if ((*(int *)(iVar1 + 0xc) != 0) && (bVar9)) {
        local_140 = FUN_00406051(param_2,iVar5 + -0x2a + iVar8,iVar7 + -1,param_6);
        FUN_004020f1(DAT_0040c0d0,"BUTTON_CONFIG");
        FUN_00406138(param_1,local_140,extraout_EAX);
        iVar2 = iVar5 + -0x2d;
      }
      iVar3 = *(int *)(iVar1 + 4);
      if (iVar3 == 0) {
        pHVar4 = FUN_00405cda(param_2,*(HWND *)(iVar1 + 0x18),local_140,iVar8,iVar7,iVar2,
                              *(undefined4 *)(iVar1 + 0x28));
      }
      else if (iVar3 == 1) {
        pHVar4 = FUN_00405c5c(param_2,*(HWND *)(iVar1 + 0x18),local_140,iVar8,iVar7,iVar2,
                              *(float *)(iVar1 + 0x2c),*(int *)(iVar1 + 0x28));
      }
      else if (iVar3 == 4) {
        pHVar4 = FUN_004059bc(param_2,*(HWND *)(iVar1 + 0x18),local_140,*(int *)(iVar1 + 0x20),iVar8
                              ,iVar7);
      }
      else {
        if (iVar3 == 5) {
          iVar3 = 1;
        }
        else {
          if (iVar3 != 6) {
            local_134 = (code *)0x0;
            strcpy(local_108,*(char **)(*(int *)(param_3 + 8) + 8));
            _strupr(local_108);
            iVar3 = strcmp(local_108,"THRASH");
            if (iVar3 == 0) {
              strcpy(local_108,*(char **)(*(int *)(param_3 + 8) + 0xc));
              _strupr(local_108);
              iVar3 = strcmp(local_108,"FILE");
              if (iVar3 == 0) {
                iVar3 = *(int *)(iVar1 + 4);
                FUN_00404840(*(undefined4 *)(iVar1 + 0x20));
                local_134 = FUN_00404eb9;
                pcVar6 = FUN_00404e82;
              }
              else {
                iVar3 = strcmp(local_108,"TYPE");
                if (iVar3 != 0) goto LAB_00405859;
                iVar3 = *(int *)(iVar1 + 4);
                FUN_004048fc(*(char **)(iVar1 + 0x20));
                local_134 = FUN_00404e52;
                pcVar6 = FUN_00404e1b;
              }
              if (iVar3 != 2) {
                local_134 = pcVar6;
              }
            }
LAB_00405859:
            if (*(int *)(iVar1 + 4) == 2) {
              pHVar4 = FUN_00405b8c(param_2,*(HWND *)(iVar1 + 0x18),local_140,
                                    (int)*(HWND *)(iVar1 + 0x24),*(char **)(iVar1 + 0x20),iVar8,
                                    iVar7,iVar2,param_6,(int)local_134);
            }
            else {
              pHVar4 = FUN_00405ac3(param_2,*(HWND *)(iVar1 + 0x18),local_140,
                                    *(HWND *)(iVar1 + 0x24),*(char **)(iVar1 + 0x20),iVar8,iVar7,
                                    iVar2,param_6,(int)local_134);
            }
            goto LAB_00405903;
          }
          iVar3 = 0;
        }
        pHVar4 = FUN_00405ddf(param_2,*(HWND *)(iVar1 + 0x18),local_140,*(LPCSTR *)(iVar1 + 0x1c),
                              iVar8,iVar7,iVar2,iVar3);
      }
LAB_00405903:
      iVar7 = iVar7 + 0x18;
      *(HWND *)(iVar1 + 0x18) = pHVar4;
      param_3 = *(int *)(param_3 + 4);
      iVar1 = param_3;
    }
  }
  return;
}



/* VA 00405927 */

HWND __fastcall
FUN_00405927(HWND param_1,int param_2,int param_3,int param_4,undefined4 *param_5,int *param_6,
            void *param_7,HWND param_8)

{
  int *piVar1;
  HWND pHVar2;
  int iVar3;
  int iVar4;

  piVar1 = param_6;
  iVar3 = 10;
  if (param_8 != (HWND)0x0) {
    iVar3 = 0xf;
  }
  iVar4 = *(int *)(param_2 + 0xc) * 0x18 + 5 + iVar3;
  param_8 = FUN_00405f97(param_1,(LPCSTR)param_8,param_3,*param_6,param_4,iVar4);
  *piVar1 = *piVar1 + iVar4;
  iVar3 = iVar3 + 3;
  iVar4 = *(int *)(param_2 + 0xc);
  while (iVar4 != 0) {
    pHVar2 = FUN_00405e3d(param_1,param_8,*(char **)(*(int *)(param_2 + 8) + 0x10),
                          *(char **)(*(int *)(param_2 + 8) + 0x14),param_8,iVar3,(int *)&param_6,
                          param_7);
    *(HWND *)(*(int *)(param_2 + 8) + 0x18) = pHVar2;
    if ((int *)*param_5 < param_6) {
      *param_5 = param_6;
    }
    iVar3 = iVar3 + 0x18;
    param_2 = *(int *)(param_2 + 4);
    iVar4 = param_2;
  }
  return param_8;
}



/* VA 004059bc */

HWND __fastcall
FUN_004059bc(HWND param_1,HWND param_2,HWND param_3,int param_4,int param_5,int param_6)

{
  HWND hWnd;

  hWnd = CreateWindowExA(0,"Button",(LPCSTR)0x0,0x50010003,param_5,param_6 + 3,0xf,0xe,param_1,
                         (HMENU)0x0,DAT_0040c058,(LPVOID)0x0);
  FUN_00404db3(hWnd);
  FUN_00404d7f(hWnd,param_2,param_3);
  if (param_4 != 0) {
    SendMessageA(hWnd,0xf1,1,0);
  }
  return hWnd;
}



/* VA 00405a20 */

HWND __fastcall
FUN_00405a20(HWND param_1,char *param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 *param_6,void *param_7,int param_8)

{
  HMENU hMenu;
  HWND hWnd;
  undefined1 *cx;
  HWND cy;
  HINSTANCE hInstance;
  LPVOID lpParam;
  tagSIZE local_c;

  lpParam = (LPVOID)0x0;
  hInstance = DAT_0040c058;
  local_c.cx = (LONG)param_1;
  local_c.cy = (LONG)param_1;
  hMenu = (HMENU)FUN_00404dc5(param_7,param_8);
  hWnd = CreateWindowExA(0,"Button",(LPCSTR)0x0,0x50010009,param_4,3,0xe,0xd,param_1,hMenu,hInstance
                         ,lpParam);
  if (param_2 != (char *)0x0) {
    FUN_00404db3(hWnd);
    FUN_004045c1(hWnd,param_2,&local_c);
    cy = (HWND)0xd;
    if (0xd < local_c.cy) {
      cy = (HWND)local_c.cy;
    }
    cx = (undefined1 *)((int)&((HWND)(local_c.cx + 0x10))->unused + 3);
    *param_6 = cx;
    SetWindowPos(hWnd,(HWND)0x0,0,0,(int)cx,(int)cy,6);
    SendMessageA(hWnd,0xc,0,(LPARAM)param_2);
    if (param_3 != 0) {
      SendMessageA(hWnd,0xf1,1,0);
    }
  }
  return hWnd;
}



/* VA 00405ac3 */

HWND __fastcall
FUN_00405ac3(HWND param_1,HWND param_2,HWND param_3,HWND param_4,char *param_5,int param_6,
            int param_7,int param_8,void *param_9,int param_10)

{
  HWND pHVar1;
  bool bVar2;
  bool bVar3;
  HWND pHVar4;
  int iVar5;
  HWND pHVar6;
  HWND hWnd;
  HWND pHVar7;
  int local_8;

  pHVar4 = FUN_00405ff5(param_1,param_6,param_7,param_8,0x14);
  FUN_00404d7f(pHVar4,param_2,param_3);
  local_8 = 0;
  bVar2 = true;
  bVar3 = false;
  hWnd = param_4;
  if ((param_4 != (HWND)0x0) && (pHVar7 = param_4, param_4[5].unused != 0)) {
    do {
      if ((param_5 == (char *)0x0) || (iVar5 = strcmp((char *)pHVar7[3].unused,param_5), iVar5 != 0)
         ) {
        iVar5 = 0;
      }
      else {
        iVar5 = 1;
        bVar3 = true;
      }
      pHVar6 = FUN_00405a20(pHVar4,(char *)pHVar7[4].unused,iVar5,local_8,&param_4,&param_4,param_9,
                            param_10);
      pHVar1 = pHVar7 + 2;
      local_8 = (int)&param_4[3].unused + local_8;
      if (bVar2) {
        hWnd = pHVar6;
      }
      bVar2 = false;
      pHVar7 = (HWND)pHVar1->unused;
    } while ((HWND)pHVar1->unused != (HWND)0x0);
    if (bVar3) {
      return pHVar4;
    }
  }
  SendMessageA(hWnd,0xf1,1,0);
  return pHVar4;
}



/* VA 00405b8c */

HWND __fastcall
FUN_00405b8c(HWND param_1,HWND param_2,HWND param_3,int param_4,char *param_5,int param_6,
            int param_7,int param_8,void *param_9,int param_10)

{
  bool bVar1;
  HMENU hMenu;
  HWND hWnd;
  int iVar2;
  HINSTANCE hInstance;
  LPVOID lpParam;
  WPARAM local_c;

  lpParam = (LPVOID)0x0;
  hInstance = DAT_0040c058;
  hMenu = (HMENU)FUN_00404dc5(param_9,param_10);
  hWnd = CreateWindowExA(0,"ComboBox",(LPCSTR)0x0,0x50210203,param_6,param_7,param_8,0xe2,param_1,
                         hMenu,hInstance,lpParam);
  FUN_00404db3(hWnd);
  FUN_00404d7f(hWnd,param_2,param_3);
  local_c = 0;
  bVar1 = false;
  if ((param_4 != 0) && (*(int *)(param_4 + 0x14) != 0)) {
    do {
      SendMessageA(hWnd,0x143,0,*(LPARAM *)(param_4 + 0x10));
      if ((param_5 != (char *)0x0) &&
         (iVar2 = strcmp(*(char **)(param_4 + 0xc),param_5), iVar2 == 0)) {
        SendMessageA(hWnd,0x14e,local_c,0);
        bVar1 = true;
      }
      local_c = local_c + 1;
      param_4 = *(int *)(param_4 + 8);
    } while (param_4 != 0);
    if (bVar1) {
      return hWnd;
    }
  }
  SendMessageA(hWnd,0x14e,0,0);
  return hWnd;
}



/* VA 00405c5c */

HWND __fastcall
FUN_00405c5c(HWND param_1,HWND param_2,HWND param_3,int param_4,int param_5,int param_6,
            float param_7,int param_8)

{
  HWND hWnd;
  char *_Format;
  char local_2c [20];
  char local_18 [20];

  hWnd = FUN_00405d1d(param_1,param_2,param_3,param_4,param_5,param_6);
  if (param_8 == 0) {
    _Format = "%f";
  }
  else {
    sprintf(local_2c,"%%.%df");
    _Format = local_2c;
  }
  sprintf(local_18,_Format,(double)param_7);
  SendMessageA(hWnd,0xc,0,(LPARAM)local_18);
  return hWnd;
}



/* VA 00405cda */

HWND __fastcall
FUN_00405cda(HWND param_1,HWND param_2,HWND param_3,int param_4,int param_5,int param_6,
            undefined4 param_7)

{
  HWND hWnd;
  char local_18 [20];

  hWnd = FUN_00405d1d(param_1,param_2,param_3,param_4,param_5,param_6);
  sprintf(local_18,"%d",param_7);
  SendMessageA(hWnd,0xc,0,(LPARAM)local_18);
  return hWnd;
}



/* VA 00405d1d */

HWND __fastcall
FUN_00405d1d(HWND param_1,HWND param_2,HWND param_3,int param_4,int param_5,int param_6)

{
  HWND hWnd;
  LONG LVar1;
  HWND hWndInsertAfter;

  hWnd = CreateWindowExA(0x200,"Edit",(LPCSTR)0x0,0x50010000,param_4,param_5,param_6,0x14,param_1,
                         (HMENU)0x0,DAT_0040c058,(LPVOID)0x0);
  FUN_00404db3(hWnd);
  LVar1 = SetWindowLongA(hWnd,-4,0x4064c7);
  if (DAT_0040c100 == 0) {
    DAT_0040c100 = LVar1;
  }
  hWndInsertAfter =
       CreateWindowExA(0,"msctls_updown32",(LPCSTR)0x0,0x500001b4,0,0,0,0,param_1,(HMENU)0x0,
                       DAT_0040c058,(LPVOID)0x0);
  if (param_2 != (HWND)0x0) {
    FUN_00404d7f(hWnd,param_2,hWndInsertAfter);
  }
  if (param_3 != (HWND)0x0) {
    SetWindowPos(param_3,hWndInsertAfter,0,0,0,0,3);
  }
  SendMessageA(hWndInsertAfter,0x30,DAT_0040c068,1);
  return hWnd;
}



/* VA 00405ddf */

HWND __fastcall
FUN_00405ddf(HWND param_1,HWND param_2,HWND param_3,LPCSTR param_4,int param_5,int param_6,
            int param_7,int param_8)

{
  HWND pHVar1;

  pHVar1 = CreateWindowExA(0x200,"Edit",param_4,-(uint)(param_8 != 0) & 0x800 | 0x50010080,param_5,
                           param_6,param_7,0x14,param_1,(HMENU)0x0,DAT_0040c058,(LPVOID)0x0);
  FUN_00404db3(pHVar1);
  FUN_00404d7f(pHVar1,param_2,param_3);
  return pHVar1;
}



/* VA 00405e3d */

HWND __fastcall
FUN_00405e3d(HWND param_1,HWND param_2,char *param_3,char *param_4,undefined4 param_5,int param_6,
            int *param_7,void *param_8)

{
  HMENU hMenu;
  HWND hWnd;
  size_t sVar1;
  char *_Dest;
  HWND hWnd_00;
  HINSTANCE hInstance;
  LPVOID lpParam;
  tagSIZE local_18;
  HWND local_10;
  HWND local_c;

  lpParam = (LPVOID)0x0;
  hInstance = DAT_0040c058;
  local_10 = param_2;
  local_c = param_1;
  hMenu = (HMENU)FUN_00404dc5(param_8,0x4053d2);
  hWnd = CreateWindowExA(0,"Static",(LPCSTR)0x0,0x5000010b,0xc,param_6,0,0,param_2,hMenu,hInstance,
                         lpParam);
  FUN_00404db3(hWnd);
  sVar1 = strlen(param_3);
  _Dest = malloc(sVar1 + 2);
  strcpy(_Dest,param_3);
  strcat(_Dest,":");
  FUN_004045c1(hWnd,_Dest,&local_18);
  if ((param_4 != (char *)0x0) && (*param_4 != '\0')) {
    FUN_00406138(local_c,hWnd,param_4);
    hWnd_00 = CreateWindowExA(0,"Static",(LPCSTR)0x0,0x50000003,local_18.cx + 0x10,param_6 + -1,0,0,
                              local_10,(HMENU)0x0,DAT_0040c058,(LPVOID)0x0);
    SendMessageA(hWnd_00,0x172,1,DAT_0040c0b8);
    local_18.cx = local_18.cx + 0x14;
  }
  SetWindowPos(hWnd,(HWND)0x0,0,0,local_18.cx,local_18.cy,6);
  SendMessageA(hWnd,0xc,0,(LPARAM)_Dest);
  free(_Dest);
  *param_7 = local_18.cx;
  return hWnd;
}



/* VA 00405f5f */

void __cdecl FUN_00405f5f(int param_1)

{
  CreateWindowExA(0x20000,"Static",(LPCSTR)0x0,0x5000000b,0xc,param_1,0x80,2,DAT_0040c0e0,(HMENU)0x0
                  ,DAT_0040c058,(LPVOID)0x0);
  return;
}



/* VA 00405f97 */

HWND __fastcall
FUN_00405f97(HWND param_1,LPCSTR param_2,int param_3,int param_4,int param_5,int param_6)

{
  HWND hWnd;
  LONG LVar1;

  hWnd = CreateWindowExA(0x10000,"Button",param_2,0x50030007,param_3,param_4,param_5,param_6,param_1
                         ,(HMENU)0x0,DAT_0040c058,(LPVOID)0x0);
  FUN_00404db3(hWnd);
  LVar1 = SetWindowLongA(hWnd,-4,0x40634a);
  if (DAT_0040c0fc == 0) {
    DAT_0040c0fc = LVar1;
  }
  return hWnd;
}



/* VA 00405ff5 */

HWND __fastcall FUN_00405ff5(HWND param_1,int param_2,int param_3,int param_4,int param_5)

{
  HWND hWnd;
  LONG LVar1;

  hWnd = CreateWindowExA(0x10000,"Static",(LPCSTR)0x0,0x50020000,param_2,param_3,param_4,param_5,
                         param_1,(HMENU)0x0,DAT_0040c058,(LPVOID)0x0);
  FUN_00404db3(hWnd);
  LVar1 = SetWindowLongA(hWnd,-4,0x4062f5);
  if (DAT_0040c104 == 0) {
    DAT_0040c104 = LVar1;
  }
  return hWnd;
}



/* VA 00406051 */

HWND __thiscall FUN_00406051(void *this,int param_1,int param_2,void *param_3)

{
  LPARAM lParam;
  HMENU hMenu;
  HWND hWnd;
  HINSTANCE hInstance;
  LPVOID lpParam;

  lParam = DAT_0040c08c;
  lpParam = (LPVOID)0x0;
  hInstance = DAT_0040c058;
  hMenu = (HMENU)FUN_00404dc5(param_3,0x404f77);
  hWnd = CreateWindowExA(0,"Button",(LPCSTR)0x0,0x50010040,param_1,param_2,0x23,0x17,this,hMenu,
                         hInstance,lpParam);
  FUN_00404db3(hWnd);
  SendMessageA(hWnd,0xf7,1,lParam);
  return hWnd;
}



/* VA 004060b2 */

HWND __fastcall
FUN_004060b2(HWND param_1,char *param_2,int param_3,int param_4,void *param_5,int param_6,
            int param_7)

{
  HMENU hMenu;
  uint dwStyle;
  LPCSTR lpWindowName;
  HWND pHVar1;
  int nWidth;
  int nHeight;
  HINSTANCE hInstance;
  LPVOID lpParam;

  lpParam = (LPVOID)0x0;
  hInstance = DAT_0040c058;
  hMenu = (HMENU)FUN_00404dc5(param_5,param_6);
  nHeight = 0x17;
  nWidth = 0x80;
  dwStyle = param_7 != 0 | 0x50010000;
  FUN_004020f1(DAT_0040c0d0,param_2);
  pHVar1 = CreateWindowExA(0,"Button",lpWindowName,dwStyle,param_3,param_4,nWidth,nHeight,param_1,
                           hMenu,hInstance,lpParam);
  FUN_00404db3(pHVar1);
  return pHVar1;
}



/* VA 00406114 */

void __fastcall FUN_00406114(HWND param_1,int param_2)

{
  CreateWindowExA(0,"Static",(LPCSTR)0x0,0x5000000e,0xc,0xc,param_2,param_2,param_1,(HMENU)0x0,
                  DAT_0040c058,(LPVOID)0x0);
  return;
}



/* VA 00406138 */

HWND __fastcall FUN_00406138(HWND param_1,undefined4 param_2,undefined4 param_3)

{
  HWND hWnd;
  undefined4 local_3c;
  undefined4 local_38;
  HWND local_34;
  undefined4 local_30;
  undefined8 local_2c;
  undefined8 local_24;
  HINSTANCE local_1c;
  undefined4 local_18;
  undefined8 local_14;
  HWND local_c;

  local_c = param_1;
  hWnd = CreateWindowExA(0,"tooltips_class32",(LPCSTR)0x0,0x80000003,-0x80000000,-0x80000000,
                         -0x80000000,-0x80000000,param_1,(HMENU)0x0,DAT_0040c058,(LPVOID)0x0);
  SendMessageA(hWnd,0x418,0,0x1e0);
  local_34 = local_c;
  local_1c = DAT_0040c058;
  local_18 = param_3;
  local_2c = 0;
  local_24 = 0;
  local_14 = 0;
  local_3c = 0x28;
  local_38 = 0x11;
  local_30 = param_2;
  SendMessageA(hWnd,0x404,0,(LPARAM)&local_3c);
  return hWnd;
}



/* VA 004061d0 */

HWND __fastcall
FUN_004061d0(HWND param_1,LPCSTR param_2,LPCSTR param_3,int param_4,int param_5,DWORD param_6,
            undefined4 *param_7)

{
  HWND pHVar1;
  HWND pHVar2;
  tagRECT local_14;

  local_14.right = param_4;
  local_14.left = 0;
  local_14.top = 0;
  local_14.bottom = param_5;
  AdjustWindowRect(&local_14,param_6,0);
  pHVar1 = CreateWindowExA(0,param_2,param_3,param_6,-0x80000000,-0x80000000,
                           local_14.right - local_14.left,local_14.bottom - local_14.top,param_1,
                           (HMENU)0x0,DAT_0040c058,(LPVOID)0x0);
  FUN_00404db3(pHVar1);
  pHVar2 = FUN_00405ff5(pHVar1,0,0,param_4,param_5);
  *param_7 = pHVar2;
  return pHVar1;
}



/* VA 00406254 */

undefined4 FUN_00406254(LPCSTR param_1)

{
  BOOL BVar1;
  SHELLEXECUTEINFOA local_50;
  tagRECT local_14;

  GetWindowRect(DAT_0040c0e0,&local_14);
  ShowWindow(DAT_0040c0e0,6);
  memset(&local_50,0,0x3c);
  local_50.cbSize = 0x3c;
  local_50.lpFile = param_1;
  local_50.fMask = 0x40;
  local_50.nShow = 5;
  BVar1 = ShellExecuteExA(&local_50);
  if (BVar1 != 0) {
    DAT_0040c0d4 = local_50.hProcess;
    WaitForSingleObject(local_50.hProcess,0xffffffff);
  }
  DAT_0040c0d4 = (HANDLE)0x0;
  ShowWindow(DAT_0040c0e0,9);
  SetWindowPos(DAT_0040c0e0,(HWND)0x0,local_14.left,local_14.top,0,0,5);
  return 1;
}



/* VA 004062f5 */

LRESULT FUN_004062f5(HWND param_1,UINT param_2,uint param_3,LPARAM param_4)

{
  LRESULT LVar1;
  HWND pHVar2;
  int iVar3;

  if (param_2 == 0x111) {
    pHVar2 = GetParent(param_1);
    iVar3 = DAT_0040c064;
    if (pHVar2 == DAT_0040c0e0) {
      iVar3 = DAT_0040c090;
    }
    FUN_004043fd(param_3,param_4,iVar3);
    LVar1 = 0;
  }
  else {
    LVar1 = CallWindowProcA(DAT_0040c104,param_1,param_2,param_3,param_4);
  }
  return LVar1;
}



/* VA 0040634a */

LRESULT FUN_0040634a(HWND param_1,UINT param_2,uint param_3,undefined4 *param_4)

{
  float fVar1;
  HWND hWnd;
  int iVar2;
  LRESULT LVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  char local_34 [20];
  char local_20 [20];
  double local_c;

  if (param_2 == 0x4e) {
    if (param_4[2] == -0x2d2) {
      hWnd = GetWindow((HWND)*param_4,3);
      iVar2 = FUN_004020b5((int)hWnd);
      SendMessageA(hWnd,0xd,0x14,(LPARAM)local_20);
      if (*(int *)(iVar2 + 4) == 0) {
        atoi(local_20);
        sprintf(local_20,"%d");
      }
      else {
        dVar6 = atof(local_20);
        fVar1 = (float)dVar6;
        fVar5 = *(float *)(iVar2 + 0x20);
        fVar4 = fVar5;
        if ((fVar5 <= fVar1) &&
           (fVar4 = *(float *)(iVar2 + 0x24), fVar1 <= *(float *)(iVar2 + 0x24))) {
          fVar4 = fVar1;
        }
        fVar4 = fVar4 - (float)(int)param_4[4];
        if ((fVar5 <= fVar4) &&
           (fVar5 = *(float *)(iVar2 + 0x24), fVar4 <= *(float *)(iVar2 + 0x24))) {
          fVar5 = fVar4;
        }
        local_c = (double)fVar5;
        if (*(int *)(iVar2 + 0x28) == 0) {
          sprintf(local_20,"%f",local_c);
        }
        else {
          sprintf(local_34,"%%.%df");
          sprintf(local_20,local_34,local_c);
        }
      }
      SendMessageA(hWnd,0xc,0,(LPARAM)local_20);
      return 0;
    }
  }
  else if (param_2 == 0x111) {
    iVar2 = DAT_0040c090;
    if (DAT_0040c064 != 0) {
      iVar2 = DAT_0040c064;
    }
    FUN_004043fd(param_3,param_4,iVar2);
    return 0;
  }
  LVar3 = CallWindowProcA(DAT_0040c0fc,param_1,param_2,param_3,(LPARAM)param_4);
  return LVar3;
}



/* VA 004064c7 */

LRESULT FUN_004064c7(HWND param_1,UINT param_2,uint param_3,LPARAM param_4)

{
  uint wParam;
  LRESULT LVar1;
  bool bVar2;
  undefined1 local_1c [20];
  undefined1 local_8 [4];

  wParam = param_3;
  if ((param_2 == 0x102) && ((param_3 < 0x30 || (0x39 < param_3)))) {
    if (param_3 == 0x2d) {
      SendMessageA(param_1,0xd,0x14,(LPARAM)local_1c);
      SendMessageA(param_1,0xb0,(WPARAM)&param_3,(LPARAM)local_8);
      bVar2 = param_3 == 0;
    }
    else {
      bVar2 = param_3 == 8;
    }
    if (!bVar2) {
      return 0;
    }
  }
  LVar1 = CallWindowProcA(DAT_0040c100,param_1,param_2,wParam,param_4);
  return LVar1;
}



/* VA 0040653a */

undefined4 FUN_0040653a(HWND param_1,int param_2,uint param_3,uint param_4)

{
  void *pvVar1;
  undefined4 uVar2;

  pvVar1 = DAT_0040c064;
  if (param_2 == 1) {
    EnableWindow(DAT_0040c0e0,0);
  }
  else if (param_2 == 2) {
    if (DAT_0040c064 != (void *)0x0) {
      FUN_004010ae((int)DAT_0040c064);
      FUN_00401a7e(pvVar1);
    }
    DAT_0040c064 = (void *)0x0;
    DAT_0040c0dc = 0;
    EnableWindow(DAT_0040c0e0,1);
    SetForegroundWindow(DAT_0040c0e0);
  }
  else if (param_2 == 5) {
    SetWindowPos(DAT_0040c0b0,(HWND)0x0,0,0,param_4 & 0xffff,param_4 >> 0x10,6);
  }
  else {
    if (param_2 != 0x111) {
                    /* WARNING: Could not recover jumptable at 0x0040655b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = DefWindowProcA();
      return uVar2;
    }
    if ((short)param_3 == 2) {
      SendMessageA(param_1,0x10,0,0);
    }
    else {
      FUN_004043fd(param_3,param_4,(int)DAT_0040c064);
    }
  }
  return 0;
}



/* VA 0040660a */

undefined4 FUN_0040660a(undefined4 param_1,int param_2,uint param_3,uint param_4)

{
  void *pvVar1;
  undefined4 uVar2;

  pvVar1 = DAT_0040c090;
  if (param_2 == 2) {
    if (DAT_0040c090 != (void *)0x0) {
      FUN_004010ae((int)DAT_0040c090);
      FUN_00401a7e(pvVar1);
    }
    pvVar1 = DAT_0040c07c;
    if (DAT_0040c07c != (void *)0x0) {
      FUN_004014ab((int)DAT_0040c07c);
      FUN_00401a7e(pvVar1);
    }
    PostQuitMessage(0);
  }
  else if (param_2 == 5) {
    SetWindowPos(DAT_0040c0b4,(HWND)0x0,0,0,param_4 & 0xffff,param_4 >> 0x10,6);
  }
  else {
    if (param_2 != 0x111) {
                    /* WARNING: Could not recover jumptable at 0x00406623. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = DefWindowProcA();
      return uVar2;
    }
    FUN_004043fd(param_3,param_4,(int)DAT_0040c090);
  }
  return 0;
}



/* VA 004066a5 */

undefined4 __thiscall FUN_004066a5(void *this,int param_1)

{
  void *this_00;
  size_t sVar1;
  int *piVar2;
  char *_Str;

  FUN_00401978((int)this);
  sVar1 = strlen("<");
  FUN_00408f33((void *)((int)this + 0xc),&DAT_0040a79c,sVar1);
  _Str = (char *)(*(int *)(param_1 + 0x20) + 8);
  sVar1 = strlen(_Str);
  this_00 = (void *)((int)this + 0xc);
  FUN_00408f33(this_00,_Str,sVar1);
  sVar1 = strlen(">");
  FUN_00408f33(this_00,&DAT_0040a6d4,sVar1);
  piVar2 = FUN_00408f33(this_00,*(size_t **)((int)this + 0x14) + 2,**(size_t **)((int)this + 0x14));
  return CONCAT31((int3)((uint)piVar2 >> 8),1);
}



/* VA 00406715 */

undefined4 __thiscall FUN_00406715(void *this,int param_1)

{
  void *this_00;
  size_t sVar1;
  int *piVar2;
  char *_Str;

  FUN_00401978((int)this);
  sVar1 = strlen("<!--");
  FUN_00408f33((void *)((int)this + 0xc),&DAT_0040a7b4,sVar1);
  _Str = (char *)(*(int *)(param_1 + 0x20) + 8);
  sVar1 = strlen(_Str);
  this_00 = (void *)((int)this + 0xc);
  FUN_00408f33(this_00,_Str,sVar1);
  sVar1 = strlen("-->");
  FUN_00408f33(this_00,&DAT_0040a7bc,sVar1);
  piVar2 = FUN_00408f33(this_00,*(size_t **)((int)this + 0x14) + 2,**(size_t **)((int)this + 0x14));
  return CONCAT31((int3)((uint)piVar2 >> 8),1);
}



/* VA 00406785 */

undefined4 __thiscall FUN_00406785(void *this,int *param_1)

{
  int *piVar1;

  FUN_00401978((int)this);
  (**(code **)(*param_1 + 0x44))(0,0,(void *)((int)this + 0xc));
  piVar1 = FUN_00408f33((void *)((int)this + 0xc),*(size_t **)((int)this + 0x14) + 2,
                        **(size_t **)((int)this + 0x14));
  return CONCAT31((int3)((uint)piVar1 >> 8),1);
}



/* VA 004067b9 */

undefined4 __thiscall FUN_004067b9(void *this,size_t *param_1)

{
  size_t *psVar1;
  void *this_00;
  size_t sVar2;
  size_t sVar3;
  int *piVar4;
  int *extraout_EAX;
  size_t *psVar5;
  size_t *_Memory;
  size_t *local_8;

  psVar5 = param_1 + 8;
  psVar1 = (size_t *)((int)this + 0xc);
  local_8 = psVar1;
  if ((char)param_1[0xb] == '\0') {
    if (*(char *)((int)this + 8) == '\0') {
      param_1 = psVar5;
      FUN_00401978((int)this);
      local_8 = &DAT_0040c0f0;
      FUN_00407766(param_1,&local_8);
      _Memory = local_8;
      FUN_00408f33((void *)((int)this + 0xc),local_8 + 2,*local_8);
      psVar1 = *(size_t **)((int)this + 0x14);
      psVar5 = (size_t *)((int)this + 0xc);
      sVar2 = *psVar1;
    }
    else {
      param_1 = &DAT_0040c0f0;
      FUN_00407766(psVar5,&param_1);
      sVar2 = *param_1;
      psVar5 = local_8;
      _Memory = param_1;
      psVar1 = param_1;
    }
    piVar4 = FUN_00408f33(psVar5,psVar1 + 2,sVar2);
    if (_Memory != &DAT_0040c0f0) {
      free(_Memory);
      piVar4 = extraout_EAX;
    }
  }
  else {
    param_1 = psVar5;
    FUN_00401978((int)this);
    sVar2 = strlen("<![CDATA[");
    FUN_00408f33(psVar1,"<![CDATA[",sVar2);
    sVar2 = *param_1;
    sVar3 = strlen((char *)(sVar2 + 8));
    this_00 = (void *)((int)this + 0xc);
    FUN_00408f33(this_00,(char *)(sVar2 + 8),sVar3);
    sVar2 = strlen("]]>");
    FUN_00408f33(this_00,&DAT_0040a7b0,sVar2);
    piVar4 = FUN_00408f33(this_00,*(size_t **)((int)this + 0x14) + 2,**(size_t **)((int)this + 0x14)
                         );
  }
  return CONCAT31((int3)((uint)piVar4 >> 8),1);
}



/* VA 004068ab */

undefined4 __thiscall FUN_004068ab(void *this,int param_1)

{
  int *in_EAX;
  size_t sVar1;
  void *this_00;
  char *_Str;

  *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  if (*(int *)(param_1 + 0x18) != 0) {
    if (*(char *)((int)this + 8) == '\0') {
      FUN_00401978((int)this);
    }
    else {
      *(undefined1 *)((int)this + 8) = 0;
    }
    this_00 = (void *)((int)this + 0xc);
    sVar1 = strlen("</");
    FUN_00408f33(this_00,&DAT_0040a7a0,sVar1);
    _Str = (char *)(*(int *)(param_1 + 0x20) + 8);
    sVar1 = strlen(_Str);
    FUN_00408f33(this_00,_Str,sVar1);
    sVar1 = strlen(">");
    FUN_00408f33(this_00,&DAT_0040a6d4,sVar1);
    in_EAX = FUN_00408f33(this_00,*(size_t **)((int)this + 0x14) + 2,**(size_t **)((int)this + 0x14)
                         );
  }
  return CONCAT31((int3)((uint)in_EAX >> 8),1);
}



/* VA 00406933 */

undefined4 __thiscall FUN_00406933(void *this,int param_1,void *param_2)

{
  void *this_00;
  size_t *psVar1;
  size_t sVar2;
  int iVar3;
  int *piVar4;
  undefined4 extraout_ECX;
  char *_Str;

  FUN_00401978((int)this);
  this_00 = (void *)((int)this + 0xc);
  sVar2 = strlen("<");
  FUN_00408f33(this_00,&DAT_0040a79c,sVar2);
  _Str = (char *)(*(int *)(param_1 + 0x20) + 8);
  sVar2 = strlen(_Str);
  FUN_00408f33(this_00,_Str,sVar2);
  for (; param_2 != (void *)0x0; param_2 = (void *)FUN_0040712c((int)param_2)) {
    sVar2 = strlen(" ");
    FUN_00408f33(this_00,&DAT_0040a6cc,sVar2);
    FUN_00406fc8(param_2,(FILE *)0x0,extraout_ECX,this_00);
  }
  if (*(int *)(param_1 + 0x18) == 0) {
    sVar2 = strlen(" />");
    FUN_00408f33(this_00,&DAT_0040a6d0,sVar2);
    psVar1 = *(size_t **)((int)this + 0x14);
    sVar2 = *psVar1;
  }
  else {
    sVar2 = strlen(">");
    FUN_00408f33(this_00,&DAT_0040a6d4,sVar2);
    iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x30))();
    if ((iVar3 != 0) && (*(int **)(param_1 + 0x1c) == *(int **)(param_1 + 0x18))) {
      piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x18) + 0x30))();
      if ((char)piVar4[0xb] == '\0') {
        *(undefined1 *)((int)this + 8) = 1;
        goto LAB_00406a21;
      }
    }
    psVar1 = *(size_t **)((int)this + 0x14);
    sVar2 = *psVar1;
  }
  piVar4 = FUN_00408f33(this_00,psVar1 + 2,sVar2);
LAB_00406a21:
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  return CONCAT31((int3)((uint)piVar4 >> 8),1);
}



/* VA 00406a37 */

undefined4 * __thiscall FUN_00406a37(void *this,char *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;

  puVar1 = (undefined4 *)FUN_00406a96(this,param_1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = operator_new(0x24);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_004017c9(puVar1);
    }
    puVar1[8] = this;
    puVar1[7] = *(undefined4 *)((int)this + 0x1c);
    *(undefined4 **)(*(int *)((int)this + 0x1c) + 0x20) = puVar1;
    *(undefined4 **)((int)this + 0x1c) = puVar1;
    puVar2 = (undefined4 *)strlen(param_1);
    FUN_00408f82(puVar1 + 5,param_1,puVar2);
  }
  return puVar1;
}



/* VA 00406a96 */

int __thiscall FUN_00406a96(void *this,char *param_1)

{
  int iVar1;
  void *pvVar2;

  pvVar2 = *(void **)((int)this + 0x20);
  while( true ) {
    if (pvVar2 == this) {
      return 0;
    }
    iVar1 = strcmp((char *)(*(int *)((int)pvVar2 + 0x14) + 8),param_1);
    if (iVar1 == 0) break;
    pvVar2 = *(void **)((int)pvVar2 + 0x20);
  }
  return (int)pvVar2;
}



/* VA 00406acb */

void __thiscall FUN_00406acb(void *this,int param_1)

{
  void *pvVar1;
  void *pvVar2;

  pvVar2 = *(void **)((int)this + 0x20);
  do {
    pvVar1 = pvVar2;
    if (pvVar1 == this) {
      return;
    }
    pvVar2 = *(void **)((int)pvVar1 + 0x20);
  } while (pvVar1 != (void *)param_1);
  *(void **)(*(int *)((int)pvVar1 + 0x1c) + 0x20) = *(void **)((int)pvVar1 + 0x20);
  *(undefined4 *)(*(int *)((int)pvVar1 + 0x20) + 0x1c) = *(undefined4 *)((int)pvVar1 + 0x1c);
  *(undefined4 *)((int)pvVar1 + 0x20) = 0;
  *(undefined4 *)((int)pvVar1 + 0x1c) = 0;
  return;
}



/* VA 00406b02 */

void __thiscall FUN_00406b02(void *this,int param_1)

{
  *(void **)(param_1 + 0x20) = this;
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)((int)this + 0x1c);
  *(int *)(*(int *)((int)this + 0x1c) + 0x20) = param_1;
  *(int *)((int)this + 0x1c) = param_1;
  return;
}



/* VA 00406b23 */

int __fastcall FUN_00406b23(undefined4 *param_1)

{
  int extraout_ECX;

  FUN_004017c9(param_1);
  *(int *)(extraout_ECX + 0x20) = extraout_ECX;
  *(int *)(extraout_ECX + 0x1c) = extraout_ECX;
  return extraout_ECX;
}



/* VA 00406b64 */

void __thiscall FUN_00406b64(void *this,int *param_1)

{
  (**(code **)(*param_1 + 0x14))(this);
  return;
}



/* VA 00406b74 */

void __thiscall FUN_00406b74(void *this,int param_1)

{
  FUN_004076f4(this,param_1);
  return;
}



/* VA 00406b7d */

void __thiscall FUN_00406b7d(void *this,FILE *param_1,int param_2)

{
  if (0 < param_2) {
    do {
      fprintf(param_1,"    ");
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  fprintf(param_1,"<%s>",*(int *)((int)this + 0x20) + 8);
  return;
}



/* VA 00406bff */

void __thiscall FUN_00406bff(void *this,int *param_1)

{
  (**(code **)(*param_1 + 0x20))(this);
  return;
}



/* VA 00406c0f */

void __thiscall FUN_00406c0f(void *this,int param_1)

{
  FUN_004076f4(this,param_1);
  FUN_00408f82((void *)(param_1 + 0x2c),*(undefined4 **)((int)this + 0x2c) + 2,
               (undefined4 *)**(undefined4 **)((int)this + 0x2c));
  FUN_00408f82((void *)(param_1 + 0x30),*(undefined4 **)((int)this + 0x30) + 2,
               (undefined4 *)**(undefined4 **)((int)this + 0x30));
  FUN_00408f82((void *)(param_1 + 0x34),*(undefined4 **)((int)this + 0x34) + 2,
               (undefined4 *)**(undefined4 **)((int)this + 0x34));
  return;
}



/* VA 00406c58 */

void __thiscall FUN_00406c58(void *this,FILE *param_1,undefined4 param_2,void *param_3)

{
  size_t sVar1;

  if (param_1 != (FILE *)0x0) {
    fprintf(param_1,"<?xml ");
  }
  if (param_3 != (void *)0x0) {
    sVar1 = strlen("<?xml ");
    FUN_00408f33(param_3,"<?xml ",sVar1);
  }
  if (**(int **)((int)this + 0x2c) != 0) {
    if (param_1 != (FILE *)0x0) {
      fprintf(param_1,"version=\"%s\" ",*(int **)((int)this + 0x2c) + 2);
    }
    if (param_3 != (void *)0x0) {
      sVar1 = strlen("version=\"");
      FUN_00408f33(param_3,"version=\"",sVar1);
      FUN_00408f33(param_3,*(size_t **)((int)this + 0x2c) + 2,**(size_t **)((int)this + 0x2c));
      sVar1 = strlen("\" ");
      FUN_00408f33(param_3,&DAT_0040a74c,sVar1);
    }
  }
  if (**(int **)((int)this + 0x30) != 0) {
    if (param_1 != (FILE *)0x0) {
      fprintf(param_1,"encoding=\"%s\" ",*(int **)((int)this + 0x30) + 2);
    }
    if (param_3 != (void *)0x0) {
      sVar1 = strlen("encoding=\"");
      FUN_00408f33(param_3,"encoding=\"",sVar1);
      FUN_00408f33(param_3,*(size_t **)((int)this + 0x30) + 2,**(size_t **)((int)this + 0x30));
      sVar1 = strlen("\" ");
      FUN_00408f33(param_3,&DAT_0040a74c,sVar1);
    }
  }
  if (**(int **)((int)this + 0x34) != 0) {
    if (param_1 != (FILE *)0x0) {
      fprintf(param_1,"standalone=\"%s\" ",*(int **)((int)this + 0x34) + 2);
    }
    if (param_3 != (void *)0x0) {
      sVar1 = strlen("standalone=\"");
      FUN_00408f33(param_3,"standalone=\"",sVar1);
      FUN_00408f33(param_3,*(size_t **)((int)this + 0x34) + 2,**(size_t **)((int)this + 0x34));
      sVar1 = strlen("\" ");
      FUN_00408f33(param_3,&DAT_0040a74c,sVar1);
    }
  }
  if (param_1 != (FILE *)0x0) {
    fprintf(param_1,"?>");
  }
  if (param_3 != (void *)0x0) {
    sVar1 = strlen("?>");
    FUN_00408f33(param_3,&DAT_0040a790,sVar1);
  }
  return;
}



/* VA 00406e36 */

void __thiscall FUN_00406e36(void *this,int *param_1)

{
  (**(code **)(*param_1 + 0x1c))(this);
  return;
}



/* VA 00406e46 */

void __thiscall FUN_00406e46(void *this,int param_1)

{
  FUN_004076f4(this,param_1);
  *(undefined1 *)(param_1 + 0x2c) = *(undefined1 *)((int)this + 0x2c);
  return;
}



/* VA 00406e62 */

void __thiscall FUN_00406e62(void *this,FILE *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;

  if (*(char *)((int)this + 0x2c) == '\0') {
    param_2 = &DAT_0040c0f0;
    FUN_00407766((undefined4 *)((int)this + 0x20),&param_2);
    puVar1 = param_2;
    fprintf(param_1,"%s",param_2 + 2);
    if (puVar1 != &DAT_0040c0f0) {
      free(puVar1);
    }
  }
  else {
    fprintf(param_1,"\n");
    puVar1 = param_2;
    if (0 < (int)param_2) {
      do {
        fprintf(param_1,"    ");
        puVar1 = (undefined4 *)((int)puVar1 + -1);
      } while (puVar1 != (undefined4 *)0x0);
    }
    fprintf(param_1,"<![CDATA[%s]]>\n",*(int *)((int)this + 0x20) + 8);
  }
  return;
}



/* VA 00406f20 */

void __thiscall FUN_00406f20(void *this,int *param_1)

{
  (**(code **)(*param_1 + 0x18))(this);
  return;
}



/* VA 00406f30 */

void __thiscall FUN_00406f30(void *this,int param_1)

{
  FUN_004076f4(this,param_1);
  return;
}



/* VA 00406f39 */

void __thiscall FUN_00406f39(void *this,FILE *param_1,int param_2)

{
  if (0 < param_2) {
    do {
      fprintf(param_1,"    ");
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  fprintf(param_1,"<!--%s-->",*(int *)((int)this + 0x20) + 8);
  return;
}



/* VA 00406f7a */

byte __thiscall FUN_00406f7a(void *this,undefined4 param_1)

{
  int iVar1;

  iVar1 = sscanf((char *)(*(int *)((int)this + 0x18) + 8),"%lf",param_1);
  return -(iVar1 != 1) & 2;
}



/* VA 00406fa1 */

byte __thiscall FUN_00406fa1(void *this,undefined4 param_1)

{
  int iVar1;

  iVar1 = sscanf((char *)(*(int *)((int)this + 0x18) + 8),"%d",param_1);
  return -(iVar1 != 1) & 2;
}



/* VA 00406fc8 */

void __thiscall FUN_00406fc8(void *this,FILE *param_1,undefined4 param_2,void *param_3)

{
  int *piVar1;
  size_t *_Memory;
  size_t *_Memory_00;
  int *piVar2;
  size_t sVar3;
  undefined *puVar4;
  size_t *local_c;
  size_t *local_8;

  local_8 = &DAT_0040c0f0;
  local_c = &DAT_0040c0f0;
  FUN_00407766((undefined4 *)((int)this + 0x14),&local_8);
  FUN_00407766((undefined4 *)((int)this + 0x18),&local_c);
  _Memory_00 = local_8;
  _Memory = local_c;
  piVar1 = *(int **)((int)this + 0x18);
  if (*piVar1 != 0) {
    for (piVar2 = piVar1 + 2; (char)*piVar2 != '\0'; piVar2 = (int *)((int)piVar2 + 1)) {
      if ((char)*piVar2 == '\"') {
        if ((int)piVar2 - (int)piVar1 != 7) {
          if (param_1 != (FILE *)0x0) {
            fprintf(param_1,"%s=\'%s\'",local_8 + 2,local_c + 2);
          }
          if (param_3 == (void *)0x0) goto LAB_00407089;
          FUN_00408f33(param_3,_Memory_00 + 2,*_Memory_00);
          sVar3 = strlen("=\'");
          FUN_00408f33(param_3,&DAT_0040a6fc,sVar3);
          FUN_00408f33(param_3,_Memory + 2,*_Memory);
          sVar3 = strlen("\'");
          puVar4 = &DAT_0040a700;
          goto LAB_00407081;
        }
        break;
      }
    }
  }
  if (param_1 != (FILE *)0x0) {
    fprintf(param_1,"%s=\"%s\"",local_8 + 2,local_c + 2);
  }
  if (param_3 != (void *)0x0) {
    FUN_00408f33(param_3,_Memory_00 + 2,*_Memory_00);
    sVar3 = strlen("=\"");
    FUN_00408f33(param_3,&DAT_0040a6ec,sVar3);
    FUN_00408f33(param_3,_Memory + 2,*_Memory);
    sVar3 = strlen("\"");
    puVar4 = &DAT_0040a6f0;
LAB_00407081:
    FUN_00408f33(param_3,puVar4,sVar3);
  }
LAB_00407089:
  if (_Memory != &DAT_0040c0f0) {
    free(_Memory);
  }
  if (_Memory_00 != &DAT_0040c0f0) {
    free(_Memory_00);
  }
  return;
}



/* VA 0040712c */

int __fastcall FUN_0040712c(int param_1)

{
  int iVar1;
  int iVar2;

  iVar1 = *(int *)(param_1 + 0x20);
  if ((**(int **)(iVar1 + 0x18) != 0) || (iVar2 = 0, **(int **)(iVar1 + 0x14) != 0)) {
    iVar2 = iVar1;
  }
  return iVar2;
}



/* VA 00407144 */

void __thiscall FUN_00407144(void *this,void *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;

  FUN_004076f4(this,(int)param_1);
  *(undefined1 *)((int)param_1 + 0x2c) = *(undefined1 *)((int)this + 0x2c);
  *(undefined4 *)((int)param_1 + 0x30) = *(undefined4 *)((int)this + 0x30);
  *(undefined4 *)((int)param_1 + 0x34) = *(undefined4 *)((int)this + 0x34);
  uVar1 = *(undefined4 *)((int)this + 0x3c);
  *(undefined4 *)((int)param_1 + 0x38) = *(undefined4 *)((int)this + 0x38);
  *(undefined4 *)((int)param_1 + 0x3c) = uVar1;
  *(undefined1 *)((int)param_1 + 0x40) = *(undefined1 *)((int)this + 0x40);
  for (piVar3 = *(int **)((int)this + 0x18); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[10]) {
    puVar2 = (undefined4 *)(**(code **)(*piVar3 + 0x3c))();
    FUN_00407674(param_1,puVar2);
  }
  return;
}



/* VA 00407199 */

bool __thiscall FUN_00407199(void *this,FILE *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  size_t _ElementSize;
  char *_DstBuf;
  size_t sVar4;
  char *pcVar5;
  undefined4 uVar6;

  if (param_1 == (FILE *)0x0) {
    FUN_00408bd2(this,2,(byte *)0x0,(undefined4 *)0x0,0);
  }
  else {
    FUN_004076d3((int)this);
    *(undefined4 *)((int)this + 8) = 0xffffffff;
    *(undefined4 *)((int)this + 4) = 0xffffffff;
    fseek(param_1,0,2);
    _ElementSize = ftell(param_1);
    fseek(param_1,0,0);
    if ((int)_ElementSize < 1) {
      uVar6 = 0xc;
    }
    else {
      _DstBuf = (char *)FUN_00401a9c(_ElementSize + 1);
      *_DstBuf = '\0';
      sVar4 = fread(_DstBuf,_ElementSize,1,param_1);
      if (sVar4 == 1) {
        _DstBuf[_ElementSize] = '\0';
        cVar1 = *_DstBuf;
        pcVar2 = _DstBuf;
        pcVar3 = _DstBuf;
        while (cVar1 != '\0') {
          pcVar5 = pcVar3 + 1;
          if (cVar1 == '\r') {
            *pcVar2 = '\n';
            if (*pcVar5 == '\n') {
              pcVar5 = pcVar3 + 2;
            }
          }
          else {
            *pcVar2 = cVar1;
          }
          pcVar2 = pcVar2 + 1;
          pcVar3 = pcVar5;
          cVar1 = *pcVar5;
        }
        *pcVar2 = '\0';
        (**(code **)(*(int *)this + 8))(_DstBuf,0,0);
        free(_DstBuf);
        return *(char *)((int)this + 0x2c) == '\0';
      }
      free(_DstBuf);
      uVar6 = 2;
    }
    FUN_00408bd2(this,uVar6,(byte *)0x0,(undefined4 *)0x0,0);
  }
  return false;
}



/* VA 0040728e */

bool __thiscall FUN_0040728e(void *this,char *param_1)

{
  char *_Memory;
  bool bVar1;
  FILE *_File;

  FUN_00401725(&param_1,param_1);
  _Memory = param_1;
  FUN_00408f82((void *)((int)this + 0x20),param_1 + 8,*(undefined4 **)param_1);
  _File = fopen((char *)(*(int *)((int)this + 0x20) + 8),"rb");
  if (_File == (FILE *)0x0) {
    bVar1 = false;
    FUN_00408bd2(this,2,(byte *)0x0,(undefined4 *)0x0,0);
  }
  else {
    bVar1 = FUN_00407199(this,_File);
    fclose(_File);
  }
  if (_Memory != (char *)&DAT_0040c0f0) {
    free(_Memory);
  }
  return bVar1;
}



/* VA 00407342 */

void __thiscall FUN_00407342(void *this,int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;

  iVar2 = *(int *)((int)this + 0x4c);
  if (iVar2 == (int)this + 0x2c) {
    iVar2 = 0;
  }
  cVar1 = (**(code **)(*param_1 + 4))(this,iVar2);
  if (cVar1 != '\0') {
    piVar3 = *(int **)((int)this + 0x18);
    while ((piVar3 != (int *)0x0 && (cVar1 = (**(code **)(*piVar3 + 0x40))(param_1), cVar1 != '\0'))
          ) {
      piVar3 = (int *)piVar3[10];
    }
  }
  (**(code **)(*param_1 + 0xc))(this);
  return;
}



/* VA 0040738e */

void __thiscall FUN_0040738e(void *this,void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;

  FUN_004076f4(this,(int)param_1);
  iVar1 = *(int *)((int)this + 0x4c);
  if (iVar1 != (int)this + 0x2c) {
    for (; iVar1 != 0; iVar1 = FUN_0040712c(iVar1)) {
      FUN_00407535(param_1,(char *)(*(int *)(iVar1 + 0x14) + 8),(char *)(*(int *)(iVar1 + 0x18) + 8)
                  );
    }
  }
  for (piVar3 = *(int **)((int)this + 0x18); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[10]) {
    puVar2 = (undefined4 *)(**(code **)(*piVar3 + 0x3c))();
    FUN_00407674(param_1,puVar2);
  }
  return;
}



/* VA 004073ee */

void __thiscall FUN_004073ee(void *this,FILE *param_1,int param_2)

{
  int *piVar1;
  int iVar2;

  iVar2 = param_2;
  if (0 < param_2) {
    do {
      fprintf(param_1,"    ");
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  fprintf(param_1,"<%s",*(int *)((int)this + 0x20) + 8);
  piVar1 = *(int **)((int)this + 0x4c);
  if (piVar1 != (int *)((int)this + 0x2c)) {
    for (; piVar1 != (int *)0x0; piVar1 = (int *)FUN_0040712c((int)piVar1)) {
      fprintf(param_1," ");
      (**(code **)(*piVar1 + 4))(param_1,param_2);
    }
  }
  piVar1 = *(int **)((int)this + 0x18);
  if (piVar1 == (int *)0x0) {
    fprintf(param_1," />");
  }
  else {
    if ((piVar1 == *(int **)((int)this + 0x1c)) &&
       (iVar2 = (**(code **)(*piVar1 + 0x2c))(), iVar2 != 0)) {
      fprintf(param_1,">");
      (**(code **)(**(int **)((int)this + 0x18) + 4))(param_1,param_2 + 1);
      iVar2 = *(int *)((int)this + 0x20);
    }
    else {
      fprintf(param_1,">");
      piVar1 = *(int **)((int)this + 0x18);
      if (piVar1 != (int *)0x0) {
        do {
          iVar2 = (**(code **)(*piVar1 + 0x2c))();
          if (iVar2 == 0) {
            fprintf(param_1,"\n");
          }
          (**(code **)(*piVar1 + 4))(param_1,param_2 + 1);
          piVar1 = (int *)piVar1[10];
        } while (piVar1 != (int *)0x0);
      }
      fprintf(param_1,"\n");
      if (0 < param_2) {
        do {
          fprintf(param_1,"    ");
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
      iVar2 = *(int *)((int)this + 0x20);
    }
    fprintf(param_1,"</%s>",iVar2 + 8);
  }
  return;
}



/* VA 00407535 */

void __thiscall FUN_00407535(void *this,char *param_1,char *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;

  puVar1 = FUN_00406a37((void *)((int)this + 0x2c),param_1);
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)strlen(param_2);
    FUN_00408f82(puVar1 + 6,param_2,puVar2);
  }
  return;
}



/* VA 00407565 */

void __fastcall FUN_00407565(int param_1)

{
  undefined4 *puVar1;

  FUN_004076d3(param_1);
  while ((puVar1 = *(undefined4 **)(param_1 + 0x4c), puVar1 != (undefined4 *)(param_1 + 0x2c) &&
         (puVar1 != (undefined4 *)0x0))) {
    FUN_00406acb((undefined4 *)(param_1 + 0x2c),(int)puVar1);
    (**(code **)*puVar1)(1);
  }
  return;
}



/* VA 00407591 */

void __fastcall FUN_00407591(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0040a848;
  FUN_00407565((int)param_1);
  FUN_00401827(param_1 + 0xb);
  FUN_00407881(param_1);
  return;
}



/* VA 004075af */

undefined4 * __thiscall FUN_004075af(void *this,char *param_1)

{
  undefined4 *puVar1;

  FUN_0040772e(this,1);
  *(undefined ***)this = &PTR_FUN_0040a848;
  FUN_00406b23((undefined4 *)((int)this + 0x2c));
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  puVar1 = (undefined4 *)strlen(param_1);
  FUN_00408f82((void *)((int)this + 0x20),param_1,puVar1);
  return this;
}



/* VA 004075ef */

undefined4 __fastcall FUN_004075ef(int *param_1)

{
  int iVar1;
  undefined4 uVar2;

  while( true ) {
    if (param_1 == (int *)0x0) {
      return 0;
    }
    iVar1 = (**(code **)(*param_1 + 0x10))();
    if (iVar1 != 0) break;
    param_1 = (int *)param_1[4];
  }
                    /* WARNING: Could not recover jumptable at 0x0040760f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(*param_1 + 0x10))();
  return uVar2;
}



/* VA 00407612 */

int __thiscall FUN_00407612(void *this,char *param_1)

{
  int iVar1;
  int iVar2;

  iVar2 = *(int *)((int)this + 0x28);
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    iVar1 = strcmp((char *)(*(int *)(iVar2 + 0x20) + 8),param_1);
    if (iVar1 == 0) break;
    iVar2 = *(int *)(iVar2 + 0x28);
  }
  return iVar2;
}



/* VA 00407643 */

int __thiscall FUN_00407643(void *this,char *param_1)

{
  int iVar1;
  int iVar2;

  iVar2 = *(int *)((int)this + 0x18);
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    iVar1 = strcmp((char *)(*(int *)(iVar2 + 0x20) + 8),param_1);
    if (iVar1 == 0) break;
    iVar2 = *(int *)(iVar2 + 0x28);
  }
  return iVar2;
}



/* VA 00407674 */

undefined4 * __thiscall FUN_00407674(void *this,undefined4 *param_1)

{
  int iVar1;
  void *this_00;
  undefined4 uVar2;
  byte *pbVar3;
  undefined4 *puVar4;

  if (param_1[5] == 0) {
    (**(code **)*param_1)(1);
    iVar1 = FUN_004075ef(this);
    if (iVar1 != 0) {
      iVar1 = 0;
      puVar4 = (undefined4 *)0x0;
      pbVar3 = (byte *)0x0;
      uVar2 = 0xf;
      this_00 = (void *)FUN_004075ef(this);
      FUN_00408bd2(this_00,uVar2,pbVar3,puVar4,iVar1);
    }
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1[4] = this;
    param_1[9] = *(undefined4 *)((int)this + 0x1c);
    param_1[10] = 0;
    if (*(int *)((int)this + 0x1c) == 0) {
      *(undefined4 **)((int)this + 0x18) = param_1;
    }
    else {
      *(undefined4 **)(*(int *)((int)this + 0x1c) + 0x28) = param_1;
    }
    *(undefined4 **)((int)this + 0x1c) = param_1;
  }
  return param_1;
}



/* VA 004076d3 */

void __fastcall FUN_004076d3(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;

  puVar2 = *(undefined4 **)(param_1 + 0x18);
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[10];
    (**(code **)*puVar2)(1);
    puVar2 = puVar1;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}



/* VA 004076f4 */

void __thiscall FUN_004076f4(void *this,int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char *_Str;

  _Str = (char *)(*(int *)((int)this + 0x20) + 8);
  puVar2 = (undefined4 *)strlen(_Str);
  FUN_00408f82((void *)(param_1 + 0x20),_Str,puVar2);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)((int)this + 0xc);
  uVar1 = *(undefined4 *)((int)this + 8);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)((int)this + 4);
  *(undefined4 *)(param_1 + 8) = uVar1;
  return;
}



/* VA 0040772e */

undefined4 * __thiscall FUN_0040772e(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 8) = 0xffffffff;
  *(undefined4 *)((int)this + 4) = 0xffffffff;
  *(undefined4 *)((int)this + 0x14) = param_1;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined ***)this = &PTR_FUN_0040a804;
  *(undefined4 **)((int)this + 0x20) = &DAT_0040c0f0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  return this;
}



/* VA 00407766 */

void __fastcall FUN_00407766(undefined4 *param_1,void *param_2)

{
  byte bVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  byte *pbVar7;
  byte local_2c [32];
  undefined4 *local_c;
  byte local_8 [4];

  piVar6 = (int *)*param_1;
  iVar4 = 0;
  local_c = param_1;
  if (0 < *piVar6) {
    do {
      bVar1 = *(byte *)((int)piVar6 + iVar4 + 8);
      if ((((bVar1 == 0x26) && (iVar2 = *piVar6, iVar4 < iVar2 + -2)) &&
          (*(char *)((int)piVar6 + iVar4 + 9) == '#')) &&
         (*(char *)((int)piVar6 + iVar4 + 10) == 'x')) {
        while (iVar4 < iVar2 + -1) {
          FUN_00408f33(param_2,(void *)((int)piVar6 + iVar4 + 8),1);
          iVar5 = iVar4 + 1;
          piVar6 = (int *)*local_c;
          iVar2 = iVar4 + 9;
          iVar4 = iVar5;
          if (*(char *)((int)piVar6 + iVar2) == ';') break;
          iVar2 = *piVar6;
        }
      }
      else {
        iVar4 = iVar4 + 1;
        pbVar7 = PTR_s__amp__0040c000;
        sVar3 = DAT_0040c004;
        if (((bVar1 != 0x26) && (pbVar7 = PTR_DAT_0040c00c, sVar3 = DAT_0040c010, bVar1 != 0x3c)) &&
           ((pbVar7 = PTR_DAT_0040c018, sVar3 = DAT_0040c01c, bVar1 != 0x3e &&
            ((pbVar7 = PTR_s__quot__0040c024, sVar3 = DAT_0040c028, bVar1 != 0x22 &&
             (pbVar7 = PTR_s__apos__0040c030, sVar3 = DAT_0040c034, bVar1 != 0x27)))))) {
          if (bVar1 < 0x20) {
            sprintf((char *)local_2c,"&#x%02X;",(uint)bVar1);
            sVar3 = strlen((char *)local_2c);
            pbVar7 = local_2c;
          }
          else {
            pbVar7 = local_8;
            sVar3 = 1;
            local_8[0] = bVar1;
          }
        }
        FUN_00408f33(param_2,pbVar7,sVar3);
      }
      piVar6 = (int *)*local_c;
    } while (iVar4 < *piVar6);
  }
  return;
}



/* VA 00407881 */

void __fastcall FUN_00407881(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;

  *param_1 = &PTR_FUN_0040a804;
  puVar2 = (undefined4 *)param_1[6];
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[10];
    (**(code **)*puVar2)(1);
    puVar2 = puVar1;
  }
  if ((undefined4 *)param_1[8] != &DAT_0040c0f0) {
    free((void *)param_1[8]);
  }
  *param_1 = &PTR_FUN_0040aa88;
  return;
}



/* VA 004078e9 */

void __thiscall FUN_004078e9(void *this,int *param_1)

{
  char cVar1;
  int *piVar2;

  cVar1 = (**(code **)(*param_1 + 8))(this);
  if (cVar1 != '\0') {
    piVar2 = *(int **)((int)this + 0x18);
    while ((piVar2 != (int *)0x0 && (cVar1 = (**(code **)(*piVar2 + 0x40))(param_1), cVar1 != '\0'))
          ) {
      piVar2 = (int *)piVar2[10];
    }
  }
  (**(code **)(*param_1 + 0x10))(this);
  return;
}



/* VA 00407927 */

void __thiscall FUN_00407927(void *this,FILE *param_1,undefined4 param_2)

{
  int *piVar1;

  for (piVar1 = *(int **)((int)this + 0x18); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[10]) {
    (**(code **)(*piVar1 + 4))(param_1,param_2);
    fprintf(param_1,"\n");
  }
  return;
}



/* VA 00407969 */

undefined4 * __fastcall FUN_00407969(void *param_1)

{
  undefined4 *extraout_ECX;

  FUN_0040772e(param_1,0);
  *(undefined1 *)(extraout_ECX + 0x10) = 0;
  *(undefined1 *)(extraout_ECX + 0xb) = 0;
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xf] = 0;
  extraout_ECX[0xe] = 0;
  *extraout_ECX = &PTR_FUN_0040a654;
  extraout_ECX[0xd] = 4;
  return extraout_ECX;
}



/* VA 00407992 */

undefined4 * __thiscall FUN_00407992(void *this,char *param_1)

{
  undefined4 *puVar1;

  FUN_0040772e(this,0);
  *(undefined ***)this = &PTR_FUN_0040a654;
  *(undefined4 *)((int)this + 0x3c) = 0xffffffff;
  *(undefined4 *)((int)this + 0x38) = 0xffffffff;
  *(undefined4 *)((int)this + 0x34) = 4;
  *(undefined1 *)((int)this + 0x40) = 0;
  puVar1 = (undefined4 *)strlen(param_1);
  FUN_00408f82((void *)((int)this + 0x20),param_1,puVar1);
  *(undefined1 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  return this;
}



/* VA 004079e3 */

int __fastcall FUN_004079e3(int param_1)

{
  int iVar1;

  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x30))();
    if (iVar1 != 0) {
      return *(int *)(iVar1 + 0x20) + 8;
    }
  }
  return 0;
}



/* VA 004079fd */

byte __thiscall FUN_004079fd(void *this,char *param_1,undefined4 param_2)

{
  byte bVar1;
  void *this_00;

  this_00 = (void *)FUN_00406a96((void *)((int)this + 0x2c),param_1);
  if (this_00 == (void *)0x0) {
    bVar1 = 1;
  }
  else {
    bVar1 = FUN_00406f7a(this_00,param_2);
  }
  return bVar1;
}



/* VA 00407a20 */

byte __thiscall FUN_00407a20(void *this,char *param_1,undefined4 param_2)

{
  byte bVar1;
  void *this_00;

  this_00 = (void *)FUN_00406a96((void *)((int)this + 0x2c),param_1);
  if (this_00 == (void *)0x0) {
    bVar1 = 1;
  }
  else {
    bVar1 = FUN_00406fa1(this_00,param_2);
  }
  return bVar1;
}



/* VA 00407a43 */

undefined4 __thiscall FUN_00407a43(void *this,char *param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 uVar2;

  iVar1 = FUN_00406a96((void *)((int)this + 0x2c),param_1);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = FUN_0040838f((char *)(*(int *)(iVar1 + 0x18) + 8),"true",'\x01');
    if ((((char)uVar2 == '\0') &&
        (uVar2 = FUN_0040838f((char *)(*(int *)(iVar1 + 0x18) + 8),"yes",'\x01'),
        (char)uVar2 == '\0')) &&
       (uVar2 = FUN_0040838f((char *)(*(int *)(iVar1 + 0x18) + 8),"1",'\x01'), (char)uVar2 == '\0'))
    {
      uVar2 = FUN_0040838f((char *)(*(int *)(iVar1 + 0x18) + 8),"false",'\x01');
      if ((((char)uVar2 == '\0') &&
          (uVar2 = FUN_0040838f((char *)(*(int *)(iVar1 + 0x18) + 8),"no",'\x01'),
          (char)uVar2 == '\0')) &&
         (uVar2 = FUN_0040838f((char *)(*(int *)(iVar1 + 0x18) + 8),"0",'\x01'), (char)uVar2 == '\0'
         )) {
        return 2;
      }
      *param_2 = 0;
    }
    else {
      *param_2 = 1;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* VA 00407b17 */

void __thiscall FUN_00407b17(void *this,char *param_1)

{
  int *this_00;
  int iVar1;

  this_00 = (int *)FUN_00407643(this,param_1);
  while( true ) {
    if (this_00 == (int *)0x0) {
      return;
    }
    iVar1 = (**(code **)(*this_00 + 0x18))();
    if (iVar1 != 0) break;
    this_00 = (int *)FUN_00407612(this_00,param_1);
  }
  (**(code **)(*this_00 + 0x18))();
  return;
}



/* VA 00407b4c */

void __thiscall FUN_00407b4c(void *this,char *param_1,void *param_2)

{
  if (param_2 == (void *)0x0) {
    FUN_00407643(this,param_1);
  }
  else {
    FUN_00407612(param_2,param_1);
  }
  return;
}



/* VA 00407b6d */

int __thiscall FUN_00407b6d(void *this,char *param_1)

{
  int iVar1;

  iVar1 = FUN_00406a96((void *)((int)this + 0x2c),param_1);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0x18) + 8;
  }
  return iVar1;
}



/* VA 00407b8d */

uint __fastcall FUN_00407b8d(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;

  uVar3 = 0;
  puVar1 = *(uint **)(param_1 + 0x20);
  if (*puVar1 != 0) {
    do {
      uVar2 = FUN_004019e3(*(byte *)((int)puVar1 + uVar3 + 8));
      if ((char)uVar2 == '\0') {
        return uVar2 & 0xffffff00;
      }
      puVar1 = *(uint **)(param_1 + 0x20);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar1);
  }
  return CONCAT31((int3)((uint)puVar1 >> 8),1);
}



/* VA 00407bb8 */

byte * __thiscall FUN_00407bb8(void *this,byte *param_1,undefined4 param_2,int param_3)

{
  void *this_00;
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  byte *pbVar5;

  this_00 = (void *)FUN_004075ef(this);
  do {
    while( true ) {
      pbVar5 = FUN_00408172(param_1,param_3);
      if (pbVar5 == (byte *)0x0) {
        if (this_00 != (void *)0x0) {
          FUN_00408bd2(this_00,5,(byte *)0x0,(undefined4 *)0x0,param_3);
        }
        return (byte *)0x0;
      }
      if (*pbVar5 == 0) {
        return pbVar5;
      }
      if (*pbVar5 != 0x3c) break;
      uVar4 = FUN_0040838f((char *)pbVar5,"</",'\0');
      if ((char)uVar4 != '\0') {
        return pbVar5;
      }
      piVar2 = FUN_00407c9f(this,pbVar5,param_3);
      if (piVar2 == (int *)0x0) {
        return (byte *)0x0;
      }
      param_1 = (byte *)(**(code **)(*piVar2 + 8))(pbVar5,param_2,param_3);
LAB_00407c61:
      FUN_00407674(this,piVar2);
    }
    puVar1 = operator_new(0x30);
    if ((puVar1 == (undefined4 *)0x0) || (piVar2 = FUN_0040187d(puVar1), piVar2 == (int *)0x0)) {
      return (byte *)0x0;
    }
    param_1 = (byte *)(**(code **)(*piVar2 + 8))(pbVar5,param_2,param_3);
    uVar3 = FUN_00407b8d((int)piVar2);
    if ((char)uVar3 == '\0') goto LAB_00407c61;
    (**(code **)*piVar2)(1);
  } while( true );
}



/* VA 00407c9f */

undefined4 * __thiscall FUN_00407c9f(void *this,byte *param_1,int param_2)

{
  byte *pbVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *extraout_ECX;
  undefined4 *extraout_ECX_00;
  undefined4 *extraout_ECX_01;
  undefined4 *puVar5;

  pbVar1 = FUN_00408172(param_1,param_2);
  if ((((pbVar1 == (byte *)0x0) || (*pbVar1 == 0)) || (*pbVar1 != 0x3c)) ||
     ((pbVar1 = FUN_00408172(pbVar1,param_2), pbVar1 == (byte *)0x0 || (*pbVar1 == 0)))) {
    return (undefined4 *)0x0;
  }
  uVar2 = FUN_0040838f((char *)pbVar1,"<?xml",'\x01');
  if ((char)uVar2 == '\0') {
    uVar2 = FUN_0040838f((char *)pbVar1,"<!--",'\0');
    if ((char)uVar2 != '\0') {
      pvVar3 = operator_new(0x2c);
      if (pvVar3 != (void *)0x0) {
        FUN_0040772e(pvVar3,2);
        *extraout_ECX_00 = &PTR_FUN_0040a898;
        puVar5 = extraout_ECX_00;
        goto LAB_00407e0b;
      }
      goto LAB_00407de8;
    }
    uVar2 = FUN_0040838f((char *)pbVar1,"<![CDATA[",'\0');
    if ((char)uVar2 == '\0') {
      uVar2 = FUN_0040838f((char *)pbVar1,"<!",'\0');
      if (((char)uVar2 != '\0') ||
         ((iVar4 = FUN_004082d2(pbVar1[1]), iVar4 == 0 && (pbVar1[1] != 0x5f)))) {
        pvVar3 = operator_new(0x2c);
        if (pvVar3 != (void *)0x0) {
          FUN_0040772e(pvVar3,3);
          *extraout_ECX_01 = &PTR_FUN_0040aa44;
          puVar5 = extraout_ECX_01;
          goto LAB_00407e0b;
        }
        goto LAB_00407de8;
      }
      pvVar3 = operator_new(0x50);
      if (pvVar3 == (void *)0x0) {
        return (undefined4 *)0x0;
      }
      puVar5 = FUN_004075af(pvVar3,"");
    }
    else {
      puVar5 = operator_new(0x30);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        puVar5 = FUN_0040187d(puVar5);
      }
      *(undefined1 *)(puVar5 + 0xb) = 1;
    }
  }
  else {
    pvVar3 = operator_new(0x38);
    if (pvVar3 != (void *)0x0) {
      FUN_0040772e(pvVar3,5);
      *extraout_ECX = &PTR_FUN_0040a8dc;
      extraout_ECX[0xb] = &DAT_0040c0f0;
      extraout_ECX[0xc] = &DAT_0040c0f0;
      extraout_ECX[0xd] = &DAT_0040c0f0;
      puVar5 = extraout_ECX;
      goto LAB_00407e0b;
    }
LAB_00407de8:
    puVar5 = (undefined4 *)0x0;
  }
  if (puVar5 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
LAB_00407e0b:
  puVar5[4] = this;
  return puVar5;
}



/* VA 00407e1f */

byte * __fastcall
FUN_00407e1f(byte *param_1,void *param_2,undefined4 param_3,char *param_4,undefined4 param_5,
            int param_6)

{
  byte bVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  size_t sVar5;
  byte *pbVar6;
  char *_Str;
  size_t local_10;
  void *local_c;
  undefined4 local_8;

  local_c = param_2;
  puVar3 = (undefined4 *)strlen("");
  FUN_00408f82(param_2,&DAT_0040a2a2,puVar3);
  _Str = param_4;
  if ((char)param_3 == '\0') {
    if (param_1 != (byte *)0x0) {
      do {
        if (*param_1 == 0) {
          return (byte *)0x0;
        }
        uVar4 = FUN_0040838f((char *)param_1,_Str,'\0');
        if ((char)uVar4 != '\0') break;
        param_3 = 0;
        param_1 = FUN_00401a07(param_1,(byte *)&param_3,(int *)&local_10,param_6);
        FUN_00408f33(param_2,&param_3,local_10);
      } while (param_1 != (byte *)0x0);
LAB_00407f4f:
      if ((param_1 != (byte *)0x0) && (*param_1 != 0)) {
        sVar5 = strlen(_Str);
        pbVar6 = param_1 + sVar5;
        if ((pbVar6 != (byte *)0x0) && (*pbVar6 != 0)) {
          return pbVar6;
        }
      }
    }
  }
  else {
    bVar2 = false;
    param_1 = FUN_00408172(param_1,param_6);
    _Str = param_4;
    while ((param_1 != (byte *)0x0 && (*param_1 != 0))) {
      uVar4 = FUN_0040838f((char *)param_1,_Str,'\0');
      if ((char)uVar4 != '\0') goto LAB_00407f4f;
      bVar1 = *param_1;
      if (((bVar1 == 0xd) || (bVar1 == 10)) || (uVar4 = FUN_004019e3(bVar1), (char)uVar4 != '\0')) {
        param_1 = param_1 + 1;
        bVar2 = true;
      }
      else {
        if (bVar2) {
          param_3 = CONCAT31(param_3._1_3_,0x20);
          FUN_00408f33(local_c,&param_3,1);
        }
        bVar2 = false;
        local_8 = 0;
        param_1 = FUN_00401a07(param_1,(byte *)&local_8,(int *)&local_10,param_6);
        if (local_10 == 1) {
          param_3 = CONCAT31(param_3._1_3_,(byte)local_8);
          puVar3 = &param_3;
          sVar5 = 1;
        }
        else {
          puVar3 = &local_8;
          sVar5 = local_10;
        }
        FUN_00408f33(local_c,puVar3,sVar5);
      }
    }
  }
  return (byte *)0x0;
}



/* VA 00407f72 */

byte * __fastcall FUN_00407f72(byte *param_1,byte *param_2,undefined4 *param_3,int param_4)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  undefined **ppuVar6;
  int iVar7;
  int local_10;
  int local_8;

  iVar7 = 0;
  *param_3 = 0;
  bVar1 = param_1[1];
  if ((bVar1 != 0) && (bVar1 == 0x23)) {
    bVar1 = param_1[2];
    if (bVar1 != 0) {
      local_8 = 1;
      uVar5 = 0;
      if (bVar1 == 0x78) {
        if (param_1[3] == 0) {
          return (byte *)0x0;
        }
        pcVar3 = strchr((char *)(param_1 + 3),0x3b);
        if (pcVar3 == (char *)0x0) {
          return (byte *)0x0;
        }
        if (*pcVar3 == '\0') {
          return (byte *)0x0;
        }
        local_10 = (int)pcVar3 - (int)param_1;
        while( true ) {
          pcVar3 = pcVar3 + -1;
          cVar2 = *pcVar3;
          if (cVar2 == 'x') break;
          if ((byte)(cVar2 - 0x30U) < 10) {
            iVar7 = cVar2 + -0x30;
          }
          else if ((byte)(cVar2 + 0x9fU) < 6) {
            iVar7 = cVar2 + -0x57;
          }
          else {
            if (5 < (byte)(cVar2 + 0xbfU)) {
              return (byte *)0x0;
            }
            iVar7 = cVar2 + -0x37;
          }
          uVar5 = local_8 * iVar7 + uVar5;
          local_8 = local_8 << 4;
        }
      }
      else {
        pcVar3 = strchr((char *)(param_1 + 2),0x3b);
        if (pcVar3 == (char *)0x0) {
          return (byte *)0x0;
        }
        if (*pcVar3 == '\0') {
          return (byte *)0x0;
        }
        local_10 = (int)pcVar3 - (int)param_1;
        while( true ) {
          pcVar3 = pcVar3 + -1;
          cVar2 = *pcVar3;
          if (cVar2 == '#') break;
          if (9 < (byte)(cVar2 - 0x30U)) {
            return (byte *)0x0;
          }
          uVar5 = uVar5 + (cVar2 + -0x30) * local_8;
          local_8 = local_8 * 10;
        }
      }
      if (param_4 == 1) {
        FUN_004082e7(uVar5,param_2,param_3);
      }
      else {
        *param_2 = (byte)uVar5;
        *param_3 = 1;
      }
      local_10 = local_10 + 1;
      goto LAB_004080f1;
    }
  }
  ppuVar6 = &PTR_s__amp__0040c000;
  while (iVar4 = strncmp(*ppuVar6,(char *)param_1,(size_t)ppuVar6[1]), iVar4 != 0) {
    ppuVar6 = ppuVar6 + 3;
    iVar7 = iVar7 + 1;
    if (0x40c03b < (int)ppuVar6) {
      *param_2 = *param_1;
      return param_1 + 1;
    }
  }
  *param_2 = (&DAT_0040c008)[iVar7 * 0xc];
  local_10 = (&DAT_0040c004)[iVar7 * 3];
  *param_3 = 1;
LAB_004080f1:
  return param_1 + local_10;
}



/* VA 004080fa */

byte * __fastcall FUN_004080fa(byte *param_1,void *param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  byte *pbVar4;

  puVar2 = (undefined4 *)strlen("");
  FUN_00408f82(param_2,&DAT_0040a2a2,puVar2);
  if (((param_1 == (byte *)0x0) || (*param_1 == 0)) ||
     ((iVar3 = FUN_004082d2(*param_1), pbVar4 = param_1, iVar3 == 0 && (*param_1 != 0x5f)))) {
    pbVar4 = (byte *)0x0;
  }
  else {
    do {
      if ((*pbVar4 == 0) ||
         ((((iVar3 = FUN_004082bd(*pbVar4), iVar3 == 0 && (bVar1 = *pbVar4, bVar1 != 0x5f)) &&
           (bVar1 != 0x2d)) && ((bVar1 != 0x2e && (bVar1 != 0x3a)))))) break;
      pbVar4 = pbVar4 + 1;
    } while (pbVar4 != (byte *)0x0);
    if (0 < (int)(pbVar4 + -(int)param_1)) {
      FUN_00408f82(param_2,param_1,(undefined4 *)(pbVar4 + -(int)param_1));
    }
  }
  return pbVar4;
}



/* VA 00408172 */

byte * __fastcall FUN_00408172(byte *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;

  if ((param_1 == (byte *)0x0) || (bVar2 = *param_1, bVar2 == 0)) {
    return (byte *)0x0;
  }
  if (param_2 == 1) {
    do {
      if (bVar2 == 0xef) {
        if (param_1[1] == 0xbb) {
          bVar1 = param_1[2];
joined_r0x00408194:
          if (bVar1 != 0xbf) goto LAB_004081b3;
        }
        else {
          if (param_1[1] != 0xbf) goto LAB_004081b3;
          if (param_1[2] != 0xbe) {
            bVar1 = param_1[2];
            goto joined_r0x00408194;
          }
        }
        param_1 = param_1 + 3;
      }
      else {
LAB_004081b3:
        uVar3 = FUN_004019e3(bVar2);
        if ((char)uVar3 == '\0') {
          return param_1;
        }
        param_1 = param_1 + 1;
      }
      bVar2 = *param_1;
    } while (bVar2 != 0);
  }
  else {
    do {
      uVar3 = FUN_004019e3(bVar2);
      if ((char)uVar3 == '\0') {
        return param_1;
      }
      param_1 = param_1 + 1;
      bVar2 = *param_1;
    } while (bVar2 != 0);
  }
  return param_1;
}



/* VA 004081e1 */

void __thiscall FUN_004081e1(void *this,byte *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  bool bVar9;
  int local_8;

  if (*(int *)((int)this + 0xc) < 1) {
    return;
  }
  local_8 = *(int *)this;
  iVar8 = *(int *)((int)this + 4);
  iVar4 = local_8;
  pbVar6 = *(byte **)((int)this + 8);
LAB_00408249:
  do {
    while( true ) {
      pbVar7 = pbVar6;
      if (param_1 <= pbVar7) {
        *(int *)this = iVar4;
        *(int *)((int)this + 4) = iVar8;
        *(byte **)((int)this + 8) = pbVar7;
        return;
      }
      uVar5 = (uint)*pbVar7;
      if (uVar5 == 0) {
        return;
      }
      if (uVar5 != 9) break;
      iVar8 = iVar8 + (*(int *)((int)this + 0xc) - iVar8 % *(int *)((int)this + 0xc));
      pbVar6 = pbVar7 + 1;
    }
    if (uVar5 == 10) {
      bVar9 = pbVar7[1] == 0xd;
    }
    else {
      if (uVar5 != 0xd) {
        if (uVar5 == 0xef) {
          if (param_2 != 1) {
LAB_00408291:
            iVar8 = iVar8 + 1;
            pbVar6 = pbVar7 + 1;
            goto LAB_00408249;
          }
          bVar1 = pbVar7[1];
          iVar4 = local_8;
          pbVar6 = pbVar7;
          if ((bVar1 == 0) || (bVar2 = pbVar7[2], bVar2 == 0)) goto LAB_00408249;
          if (bVar1 == 0xbb) {
LAB_00408278:
            if (bVar2 == 0xbf) {
LAB_0040827c:
              pbVar6 = pbVar7 + 3;
              goto LAB_00408249;
            }
          }
          else if (bVar1 == 0xbf) {
            if (bVar2 != 0xbe) goto LAB_00408278;
            goto LAB_0040827c;
          }
          pbVar6 = pbVar7 + 3;
        }
        else {
          if (param_2 != 1) goto LAB_00408291;
          cVar3 = (&DAT_0040a940)[uVar5];
          if (cVar3 == '\0') {
            cVar3 = '\x01';
          }
          pbVar6 = pbVar7 + cVar3;
        }
        iVar8 = iVar8 + 1;
        iVar4 = local_8;
        goto LAB_00408249;
      }
      bVar9 = pbVar7[1] == 10;
    }
    iVar8 = 0;
    local_8 = iVar4 + 1;
    iVar4 = local_8;
    pbVar6 = pbVar7 + 1;
    if (bVar9) {
      pbVar6 = pbVar7 + 2;
    }
  } while( true );
}



/* VA 004082bd */

int __fastcall FUN_004082bd(byte param_1)

{
  int iVar1;

  if (param_1 < 0x7f) {
    iVar1 = isalnum((uint)param_1);
    return iVar1;
  }
  return 1;
}



/* VA 004082d2 */

int __fastcall FUN_004082d2(byte param_1)

{
  int iVar1;

  if (param_1 < 0x7f) {
    iVar1 = isalpha((uint)param_1);
    return iVar1;
  }
  return 1;
}



/* VA 004082e7 */

void __fastcall FUN_004082e7(uint param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  int iVar2;
  byte local_20 [4];
  byte local_1c [24];

  local_1c[4] = 0xc0;
  local_1c[5] = 0;
  local_1c[6] = 0;
  local_1c[7] = 0;
  local_1c[0] = 0;
  local_1c[1] = 0;
  local_1c[2] = 0;
  local_1c[3] = 0;
  local_1c[8] = 0xe0;
  local_1c[9] = 0;
  local_1c[10] = 0;
  local_1c[0xb] = 0;
  local_1c[0xc] = 0xf0;
  local_1c[0xd] = 0;
  local_1c[0xe] = 0;
  local_1c[0xf] = 0;
  if (param_1 < 0x80) {
    iVar2 = 1;
    *param_3 = 1;
  }
  else {
    if (param_1 < 0x800) {
      iVar2 = 2;
      *param_3 = 2;
    }
    else {
      if (param_1 < 0x10000) {
        iVar2 = 3;
        *param_3 = 3;
      }
      else {
        if (0x1fffff < param_1) {
          *param_3 = 0;
          return;
        }
        iVar2 = 4;
        *param_3 = 4;
        bVar1 = (byte)param_1;
        param_1 = param_1 >> 6;
        param_2[3] = bVar1 & 0x3f | 0x80;
      }
      bVar1 = (byte)param_1;
      param_1 = param_1 >> 6;
      param_2[2] = bVar1 & 0x3f | 0x80;
    }
    bVar1 = (byte)param_1;
    param_1 = param_1 >> 6;
    param_2[1] = bVar1 & 0x3f | 0x80;
  }
  *param_2 = local_20[iVar2 * 4] | (byte)param_1;
  return;
}



/* VA 0040838f */

uint __fastcall FUN_0040838f(char *param_1,char *param_2,char param_3)

{
  char cVar1;
  uint in_EAX;
  uint uVar2;
  int iVar3;

  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    if (param_3 == '\0') {
      do {
        cVar1 = *param_2;
        in_EAX = CONCAT31((int3)(in_EAX >> 8),cVar1);
        if (cVar1 == '\0') goto LAB_004083ec;
        if (*param_1 != cVar1) break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
      } while (*param_1 != '\0');
    }
    else {
      iVar3 = (int)param_1 - (int)param_2;
      do {
        if (*param_2 == '\0') goto LAB_004083ec;
        uVar2 = tolower((int)param_2[iVar3]);
        in_EAX = tolower((int)*param_2);
      } while ((uVar2 == in_EAX) && (param_2 = param_2 + 1, param_2[iVar3] != '\0'));
    }
    if (*param_2 == '\0') {
LAB_004083ec:
      return CONCAT31((int3)(in_EAX >> 8),1);
    }
  }
  return in_EAX & 0xffffff00;
}



/* VA 004083f7 */

byte * __thiscall FUN_004083f7(void *this,byte *param_1,int *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  void *this_00;
  byte *pbVar4;
  undefined4 *puVar5;

  this_00 = (void *)FUN_004075ef(this);
  pbVar4 = FUN_00408172(param_1,param_3);
  piVar3 = param_2;
  if (param_2 != (int *)0x0) {
    FUN_004081e1(param_2,pbVar4,param_3);
    iVar2 = piVar3[1];
    *(int *)((int)this + 4) = *piVar3;
    *(int *)((int)this + 8) = iVar2;
  }
  if (((pbVar4 == (byte *)0x0) || (*pbVar4 == 0)) || (*pbVar4 != 0x3c)) {
    if (this_00 != (void *)0x0) {
      FUN_00408bd2(this_00,9,pbVar4,piVar3,param_3);
    }
    return (byte *)0x0;
  }
  puVar5 = (undefined4 *)strlen("");
  FUN_00408f82((void *)((int)this + 0x20),&DAT_0040a2a2,puVar5);
  pbVar4 = pbVar4 + 1;
  if (pbVar4 != (byte *)0x0) {
    do {
      bVar1 = *pbVar4;
      if (bVar1 == 0) goto LAB_004084a6;
      if (bVar1 == 0x3e) break;
      param_1 = (byte *)CONCAT31(param_1._1_3_,bVar1);
      FUN_00408f33((void *)((int)this + 0x20),&param_1,1);
      pbVar4 = pbVar4 + 1;
    } while (pbVar4 != (byte *)0x0);
    if (pbVar4 != (byte *)0x0) goto LAB_004084a6;
  }
  if (this_00 == (void *)0x0) {
    return pbVar4;
  }
  FUN_00408bd2(this_00,9,(byte *)0x0,(undefined4 *)0x0,param_3);
  if (pbVar4 == (byte *)0x0) {
    return (byte *)0x0;
  }
LAB_004084a6:
  if (*pbVar4 == 0x3e) {
    pbVar4 = pbVar4 + 1;
  }
  return pbVar4;
}



/* VA 004084cf */

byte * __thiscall FUN_004084cf(void *this,byte *param_1,int *param_2,int param_3)

{
  int iVar1;
  void *this_00;
  undefined4 *puVar2;
  byte *pbVar3;
  undefined4 uVar4;
  size_t sVar5;
  void *this_01;

  this_00 = (void *)FUN_004075ef(this);
  this_01 = (void *)((int)this + 0x20);
  puVar2 = (undefined4 *)strlen("");
  FUN_00408f82(this_01,&DAT_0040a2a2,puVar2);
  pbVar3 = FUN_00408172(param_1,param_3);
  if (param_2 != (int *)0x0) {
    FUN_004081e1(param_2,pbVar3,param_3);
    iVar1 = param_2[1];
    *(int *)((int)this + 4) = *param_2;
    *(int *)((int)this + 8) = iVar1;
  }
  uVar4 = FUN_0040838f((char *)pbVar3,"<!--",'\0');
  if ((char)uVar4 == '\0') {
    if (this_00 != (void *)0x0) {
      FUN_00408bd2(this_00,10,pbVar3,param_2,param_3);
    }
    pbVar3 = (byte *)0x0;
  }
  else {
    sVar5 = strlen("<!--");
    pbVar3 = pbVar3 + sVar5;
    puVar2 = (undefined4 *)strlen("");
    FUN_00408f82(this_01,&DAT_0040a2a2,puVar2);
    if (pbVar3 != (byte *)0x0) {
      do {
        if (*pbVar3 == 0) {
          return pbVar3;
        }
        uVar4 = FUN_0040838f((char *)pbVar3,"-->",'\0');
        if ((char)uVar4 != '\0') break;
        FUN_00408f33(this_01,pbVar3,1);
        pbVar3 = pbVar3 + 1;
      } while (pbVar3 != (byte *)0x0);
      if ((pbVar3 != (byte *)0x0) && (*pbVar3 != 0)) {
        sVar5 = strlen("-->");
        pbVar3 = pbVar3 + sVar5;
      }
    }
  }
  return pbVar3;
}



/* VA 004085cb */

byte * __thiscall FUN_004085cb(void *this,byte *param_1,int *param_2,int param_3)

{
  size_t *psVar1;
  void *pvVar2;
  byte *pbVar3;
  void *this_00;
  int *piVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  byte bVar9;
  void *this_01;
  undefined4 uVar10;
  int *local_10;
  byte *local_c;
  void *local_8;

  local_8 = this;
  pbVar3 = FUN_00408172(param_1,param_3);
  this_00 = (void *)FUN_004075ef(this);
  if ((pbVar3 == (byte *)0x0) || (bVar9 = *pbVar3, bVar9 == 0)) {
    if (this_00 == (void *)0x0) {
      return (byte *)0x0;
    }
    param_2 = (int *)0x0;
    pbVar3 = (byte *)0x0;
  }
  else {
    if (param_2 != (int *)0x0) {
      FUN_004081e1(param_2,pbVar3,param_3);
      iVar8 = param_2[1];
      *(int *)((int)local_8 + 4) = *param_2;
      *(int *)((int)local_8 + 8) = iVar8;
      bVar9 = *pbVar3;
    }
    if (bVar9 == 0x3c) {
      pbVar3 = FUN_00408172(pbVar3 + 1,param_3);
      piVar4 = (int *)((int)local_8 + 0x20);
      pbVar5 = FUN_004080fa(pbVar3,piVar4);
      if ((pbVar5 != (byte *)0x0) && (*pbVar5 != 0)) {
        FUN_00401725(&local_10,"</");
        psVar1 = (size_t *)*piVar4;
        FUN_00408f33(&local_10,psVar1 + 2,*psVar1);
        do {
          piVar4 = local_10;
          if (*pbVar5 == 0) {
LAB_00408820:
            if (piVar4 != &DAT_0040c0f0) {
              free(piVar4);
              return pbVar5;
            }
            return pbVar5;
          }
          local_c = FUN_00408172(pbVar5,param_3);
          if ((local_c == (byte *)0x0) || (bVar9 = *local_c, bVar9 == 0)) {
            if (this_00 != (void *)0x0) {
              uVar10 = 6;
LAB_00408817:
              FUN_00408bd2(this_00,uVar10,pbVar5,param_2,param_3);
            }
LAB_0040881e:
            pbVar5 = (byte *)0x0;
            goto LAB_00408820;
          }
          if (bVar9 == 0x2f) {
            pbVar3 = local_c + 1;
            if (*pbVar3 != 0x3e) {
              if (this_00 != (void *)0x0) {
                uVar10 = 7;
                pbVar5 = pbVar3;
                goto LAB_00408817;
              }
              goto LAB_0040881e;
            }
LAB_00408805:
            pbVar5 = pbVar3 + 1;
            goto LAB_00408820;
          }
          if (bVar9 == 0x3e) {
            pbVar3 = FUN_00407bb8(local_8,local_c + 1,param_2,param_3);
            if ((pbVar3 == (byte *)0x0) || (*pbVar3 == 0)) {
              if (this_00 != (void *)0x0) {
                uVar10 = 8;
                pbVar5 = pbVar3;
                goto LAB_00408817;
              }
              goto LAB_0040881e;
            }
            pbVar5 = (byte *)0x0;
            uVar10 = FUN_0040838f((char *)pbVar3,(char *)(piVar4 + 2),'\0');
            if (((((char)uVar10 != '\0') &&
                 (pbVar3 = FUN_00408172(pbVar3 + *piVar4,param_3), pbVar3 != (byte *)0x0)) &&
                (*pbVar3 != 0)) && (*pbVar3 == 0x3e)) goto LAB_00408805;
            if (this_00 != (void *)0x0) {
              FUN_00408bd2(this_00,8,pbVar3,param_2,param_3);
            }
            goto LAB_00408820;
          }
          puVar6 = operator_new(0x24);
          if ((puVar6 == (undefined4 *)0x0) || (piVar7 = FUN_004017c9(puVar6), piVar7 == (int *)0x0)
             ) goto LAB_0040881e;
          piVar7[4] = (int)this_00;
          pbVar5 = (byte *)(**(code **)(*piVar7 + 8))(local_c,param_2,param_3);
          pvVar2 = local_8;
          if ((pbVar5 == (byte *)0x0) || (*pbVar5 == 0)) {
LAB_0040874a:
            if (this_00 != (void *)0x0) {
              FUN_00408bd2(this_00,3,local_c,param_2,param_3);
            }
            (**(code **)*piVar7)(1);
            goto LAB_0040881e;
          }
          this_01 = (void *)((int)local_8 + 0x2c);
          iVar8 = FUN_00406a96(this_01,(char *)(piVar7[5] + 8));
          if (iVar8 != 0) goto LAB_0040874a;
          piVar7[8] = (int)this_01;
          piVar7[7] = *(int *)((int)pvVar2 + 0x48);
          *(int **)(*(int *)((int)pvVar2 + 0x48) + 0x20) = piVar7;
          *(int **)((int)pvVar2 + 0x48) = piVar7;
        } while( true );
      }
      if (this_00 == (void *)0x0) {
        return (byte *)0x0;
      }
      uVar10 = 4;
      goto LAB_0040884d;
    }
    if (this_00 == (void *)0x0) {
      return (byte *)0x0;
    }
  }
  uVar10 = 3;
LAB_0040884d:
  FUN_00408bd2(this_00,uVar10,pbVar3,param_2,param_3);
  return (byte *)0x0;
}



/* VA 0040885d */

byte * __thiscall FUN_0040885d(void *this,byte *param_1,undefined4 *param_2,byte *param_3)

{
  byte bVar1;
  byte *pbVar2;
  void *pvVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 extraout_ECX;
  char *pcVar7;

  pbVar4 = param_3;
  param_3 = FUN_00408172(param_1,(int)param_3);
  if ((param_3 != (byte *)0x0) && (*param_3 != 0)) {
    if (param_2 != (undefined4 *)0x0) {
      FUN_004081e1(param_2,param_3,(int)pbVar4);
      uVar6 = param_2[1];
      *(undefined4 *)((int)this + 4) = *param_2;
      *(undefined4 *)((int)this + 8) = uVar6;
    }
    pbVar2 = FUN_004080fa(param_3,(void *)((int)this + 0x14));
    if ((pbVar2 == (byte *)0x0) || (*pbVar2 == 0)) {
      pvVar3 = *(void **)((int)this + 0x10);
      pbVar2 = param_3;
    }
    else {
      pbVar2 = FUN_00408172(pbVar2,(int)pbVar4);
      if (((pbVar2 == (byte *)0x0) || (*pbVar2 == 0)) || (*pbVar2 != 0x3d)) {
        pvVar3 = *(void **)((int)this + 0x10);
      }
      else {
        pbVar2 = FUN_00408172(pbVar2 + 1,(int)pbVar4);
        if (pbVar2 != (byte *)0x0) {
          bVar1 = *pbVar2;
          if (bVar1 != 0) {
            pvVar3 = (void *)((int)this + 0x18);
            if (bVar1 == 0x27) {
              pcVar7 = "\'";
LAB_0040892a:
              pbVar4 = FUN_00407e1f(pbVar2 + 1,pvVar3,0,pcVar7,
                                    CONCAT31((int3)((uint)extraout_ECX >> 8),bVar1),(int)pbVar4);
              return pbVar4;
            }
            if (bVar1 == 0x22) {
              pcVar7 = "\"";
              goto LAB_0040892a;
            }
            puVar5 = (undefined4 *)strlen("");
            FUN_00408f82(pvVar3,&DAT_0040a2a2,puVar5);
            while( true ) {
              if (*pbVar2 == 0) {
                return pbVar2;
              }
              uVar6 = FUN_004019e3(*pbVar2);
              if ((char)uVar6 != '\0') {
                return pbVar2;
              }
              bVar1 = *pbVar2;
              if (bVar1 == 0x2f) {
                return pbVar2;
              }
              if (bVar1 == 0x3e) {
                return pbVar2;
              }
              if ((bVar1 == 0x27) || (bVar1 == 0x22)) break;
              param_3 = (byte *)CONCAT31(param_3._1_3_,bVar1);
              FUN_00408f33(pvVar3,&param_3,1);
              pbVar2 = pbVar2 + 1;
              if (pbVar2 == (byte *)0x0) {
                return (byte *)0x0;
              }
            }
          }
        }
        pvVar3 = *(void **)((int)this + 0x10);
      }
    }
    if (pvVar3 != (void *)0x0) {
      FUN_00408bd2(pvVar3,6,pbVar2,param_2,(int)pbVar4);
    }
  }
  return (byte *)0x0;
}



/* VA 004089cc */

byte * __thiscall FUN_004089cc(void *this,byte *param_1,int *param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  void *this_00;
  void *this_01;
  void *this_02;
  void *this_03;
  void *this_04;
  char *_Str;
  undefined4 local_2c [6];
  int local_14;
  void *local_8;

  local_8 = this;
  pbVar3 = FUN_00408172(param_1,(int)param_3);
  pvVar4 = (void *)FUN_004075ef(this);
  if (((pbVar3 == (byte *)0x0) || (*pbVar3 == 0)) ||
     (uVar5 = FUN_0040838f((char *)pbVar3,"<?xml",'\x01'), (char)uVar5 == '\0')) {
    if (pvVar4 != (void *)0x0) {
      FUN_00408bd2(pvVar4,0xb,(byte *)0x0,(undefined4 *)0x0,(int)param_3);
    }
    return (byte *)0x0;
  }
  if (param_2 != (int *)0x0) {
    FUN_004081e1(param_2,pbVar3,(int)param_3);
    iVar2 = param_2[1];
    *(int *)((int)local_8 + 4) = *param_2;
    *(int *)((int)local_8 + 8) = iVar2;
  }
  pvVar4 = (void *)((int)local_8 + 0x2c);
  puVar6 = (undefined4 *)strlen("");
  FUN_00408f82(pvVar4,&DAT_0040a2a2,puVar6);
  this_00 = (void *)((int)local_8 + 0x30);
  puVar6 = (undefined4 *)strlen("");
  FUN_00408f82(this_00,&DAT_0040a2a2,puVar6);
  local_8 = (void *)((int)local_8 + 0x34);
  puVar6 = (undefined4 *)strlen("");
  FUN_00408f82(local_8,&DAT_0040a2a2,puVar6);
  pbVar3 = pbVar3 + 5;
joined_r0x00408aa8:
  do {
    if (pbVar3 == (byte *)0x0) {
      return (byte *)0x0;
    }
    if (*pbVar3 == 0) {
      return (byte *)0x0;
    }
    if (*pbVar3 == 0x3e) {
      return pbVar3 + 1;
    }
    pbVar3 = FUN_00408172(pbVar3,(int)param_3);
    uVar5 = FUN_0040838f((char *)pbVar3,"version",'\x01');
    if ((char)uVar5 != '\0') {
      FUN_004017c9(local_2c);
      pbVar3 = FUN_0040885d(this_01,pbVar3,param_2,param_3);
      _Str = (char *)(local_14 + 8);
      puVar6 = (undefined4 *)strlen(_Str);
      this_04 = pvVar4;
LAB_00408b77:
      FUN_00408f82(this_04,_Str,puVar6);
      FUN_00401827(local_2c);
      goto joined_r0x00408aa8;
    }
    uVar5 = FUN_0040838f((char *)pbVar3,"encoding",'\x01');
    if ((char)uVar5 != '\0') {
      FUN_004017c9(local_2c);
      pbVar3 = FUN_0040885d(this_02,pbVar3,param_2,param_3);
      _Str = (char *)(local_14 + 8);
      puVar6 = (undefined4 *)strlen(_Str);
      this_04 = this_00;
      goto LAB_00408b77;
    }
    uVar5 = FUN_0040838f((char *)pbVar3,"standalone",'\x01');
    if ((char)uVar5 != '\0') {
      FUN_004017c9(local_2c);
      pbVar3 = FUN_0040885d(this_03,pbVar3,param_2,param_3);
      _Str = (char *)(local_14 + 8);
      puVar6 = (undefined4 *)strlen(_Str);
      this_04 = local_8;
      goto LAB_00408b77;
    }
    if (pbVar3 == (byte *)0x0) {
      return (byte *)0x0;
    }
    while ((bVar1 = *pbVar3, bVar1 != 0 && (bVar1 != 0x3e))) {
      uVar5 = FUN_004019e3(bVar1);
      if (((char)uVar5 != '\0') || (pbVar3 = pbVar3 + 1, pbVar3 == (byte *)0x0)) break;
    }
  } while( true );
}



/* VA 00408bd2 */

void __thiscall
FUN_00408bd2(void *this,undefined4 param_1,byte *param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;

  if (*(char *)((int)this + 0x2c) == '\0') {
    *(undefined4 *)((int)this + 0x3c) = 0xffffffff;
    *(undefined4 *)((int)this + 0x38) = 0xffffffff;
    *(undefined1 *)((int)this + 0x2c) = 1;
    *(undefined4 *)((int)this + 0x30) = param_1;
    if ((param_2 != (byte *)0x0) && (param_3 != (undefined4 *)0x0)) {
      FUN_004081e1(param_3,param_2,param_4);
      uVar1 = param_3[1];
      *(undefined4 *)((int)this + 0x38) = *param_3;
      *(undefined4 *)((int)this + 0x3c) = uVar1;
    }
  }
  return;
}



/* VA 00408c1c */

byte * __thiscall FUN_00408c1c(void *this,byte *param_1,int *param_2,char *param_3)

{
  void *this_00;
  int iVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 *puVar4;
  void *this_01;
  undefined4 uVar5;
  byte *pbVar6;
  size_t sVar7;
  char *extraout_ECX;
  char *pcVar8;

  this_00 = (void *)((int)this + 0x20);
  puVar4 = (undefined4 *)strlen("");
  FUN_00408f82(this_00,&DAT_0040a2a2,puVar4);
  this_01 = (void *)FUN_004075ef(this);
  pcVar3 = param_3;
  piVar2 = param_2;
  if (param_2 != (int *)0x0) {
    FUN_004081e1(param_2,param_1,(int)param_3);
    iVar1 = piVar2[1];
    *(int *)((int)this + 4) = *piVar2;
    *(int *)((int)this + 8) = iVar1;
  }
  if ((*(char *)((int)this + 0x2c) == '\0') &&
     (pcVar8 = pcVar3, uVar5 = FUN_0040838f((char *)param_1,"<![CDATA[",'\0'), (char)uVar5 == '\0'))
  {
    pbVar6 = FUN_00407e1f(param_1,this_00,1,"<",pcVar8,(int)pcVar3);
    if ((pbVar6 != (byte *)0x0) && (*pbVar6 != 0)) {
      return pbVar6 + -1;
    }
  }
  else {
    *(undefined1 *)((int)this + 0x2c) = 1;
    uVar5 = FUN_0040838f((char *)param_1,"<![CDATA[",'\0');
    if ((char)uVar5 != '\0') {
      pcVar8 = "<![CDATA[";
      sVar7 = strlen("<![CDATA[");
      pbVar6 = param_1 + sVar7;
      while (((pbVar6 != (byte *)0x0 && (*pbVar6 != 0)) &&
             (pcVar8 = pcVar3, uVar5 = FUN_0040838f((char *)pbVar6,"]]>",'\0'), (char)uVar5 == '\0')
             )) {
        param_2 = (int *)CONCAT31(param_2._1_3_,*pbVar6);
        FUN_00408f33(this_00,&param_2,1);
        pbVar6 = pbVar6 + 1;
        pcVar8 = extraout_ECX;
      }
      param_2 = &DAT_0040c0f0;
      pbVar6 = FUN_00407e1f(pbVar6,&param_2,0,"]]>",pcVar8,(int)pcVar3);
      if (param_2 == &DAT_0040c0f0) {
        return pbVar6;
      }
      free(param_2);
      return pbVar6;
    }
    if (this_01 != (void *)0x0) {
      FUN_00408bd2(this_01,0xe,param_1,piVar2,(int)pcVar3);
    }
  }
  return (byte *)0x0;
}



/* VA 00408d67 */

byte * __thiscall FUN_00408d67(void *this,byte *param_1,undefined4 *param_2,int param_3)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_18;
  undefined4 local_14;
  byte *local_10;
  undefined4 local_c;

  local_18 = 0;
  *(undefined1 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  if ((param_1 != (byte *)0x0) && (*param_1 != 0)) {
    *(undefined4 *)((int)this + 8) = 0xffffffff;
    *(undefined4 *)((int)this + 4) = 0xffffffff;
    if (param_2 == (undefined4 *)0x0) {
      uVar4 = 0;
    }
    else {
      local_18 = *param_2;
      *(undefined4 *)((int)this + 4) = local_18;
      uVar4 = param_2[1];
    }
    *(undefined4 *)((int)this + 8) = uVar4;
    local_c = *(undefined4 *)((int)this + 0x34);
    local_14 = *(undefined4 *)((int)this + 8);
    local_10 = param_1;
    *(undefined4 *)((int)this + 4) = local_18;
    *(undefined4 *)((int)this + 8) = local_14;
    if (((((param_3 == 0) && (*param_1 != 0)) && (*param_1 == 0xef)) &&
        ((param_1[1] != 0 && (param_1[1] == 0xbb)))) && ((param_1[2] != 0 && (param_1[2] == 0xbf))))
    {
      param_3 = 1;
      *(undefined1 *)((int)this + 0x40) = 1;
    }
    pbVar1 = FUN_00408172(param_1,param_3);
    if (pbVar1 != (byte *)0x0) {
      do {
        if ((*pbVar1 == 0) || (piVar2 = FUN_00407c9f(this,pbVar1,param_3), piVar2 == (int *)0x0))
        break;
        pbVar1 = (byte *)(**(code **)(*piVar2 + 8))(pbVar1,&local_18,param_3);
        FUN_00407674(this,piVar2);
        if ((param_3 == 0) && (iVar3 = (**(code **)(*piVar2 + 0x34))(), iVar3 != 0)) {
          iVar3 = (**(code **)(*piVar2 + 0x34))();
          iVar3 = *(int *)(iVar3 + 0x30);
          if ((*(char *)(iVar3 + 8) == '\0') ||
             (uVar4 = FUN_0040838f((char *)(iVar3 + 8),"UTF-8",'\x01'), (char)uVar4 != '\0')) {
            param_3 = 1;
          }
          else {
            uVar4 = FUN_0040838f((char *)(iVar3 + 8),"UTF8",'\x01');
            param_3 = ((char)uVar4 == '\0') + 1;
          }
        }
        pbVar1 = FUN_00408172(pbVar1,param_3);
      } while (pbVar1 != (byte *)0x0);
      if (*(int *)((int)this + 0x18) != 0) {
        return pbVar1;
      }
    }
    if (*(char *)((int)this + 0x2c) != '\0') {
      return (byte *)0x0;
    }
  }
  *(undefined1 *)((int)this + 0x2c) = 1;
  *(undefined4 *)((int)this + 0x30) = 0xc;
  *(undefined4 *)((int)this + 0x38) = 0xffffffff;
  *(undefined4 *)((int)this + 0x3c) = 0xffffffff;
  return (byte *)0x0;
}



/* VA 00408ee0 */

void __thiscall FUN_00408ee0(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;

  puVar1 = param_1;
  if ((undefined4 *)(*(int **)this)[1] < param_1) {
    param_1 = &DAT_0040c0f0;
    FUN_0040175c(&param_1,**(int **)this,(int)puVar1);
    puVar2 = param_1;
    memcpy(param_1 + 2,*(size_t **)this + 2,**(size_t **)this);
    puVar1 = *(undefined4 **)this;
    *(undefined4 **)this = puVar2;
    if (puVar1 != &DAT_0040c0f0) {
      free(puVar1);
    }
  }
  return;
}



/* VA 00408f33 */

int * __thiscall FUN_00408f33(void *this,void *param_1,size_t param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;

  piVar2 = *(int **)this;
  iVar3 = *piVar2;
  uVar1 = iVar3 + param_2;
  if ((uint)piVar2[1] < uVar1) {
    FUN_00408ee0(this,(undefined4 *)(piVar2[1] + uVar1));
    piVar2 = *(int **)this;
    iVar3 = *piVar2;
  }
  memmove((void *)((int)piVar2 + iVar3 + 8),param_1,param_2);
  **(uint **)this = uVar1;
  *(undefined1 *)(*(int *)this + 8 + uVar1) = 0;
  return this;
}



/* VA 00408f82 */

int * __thiscall FUN_00408f82(void *this,void *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;

  puVar2 = param_2;
  iVar1 = *(int *)this;
  if ((*(undefined4 **)(iVar1 + 4) < param_2) ||
     ((uint)((int)(param_2 + 2) * 3) < *(uint *)(iVar1 + 4))) {
    param_2 = &DAT_0040c0f0;
    FUN_0040175c(&param_2,(int)puVar2,(int)puVar2);
    puVar3 = param_2;
    memcpy(param_2 + 2,param_1,(size_t)puVar2);
    puVar2 = *(undefined4 **)this;
    *(undefined4 **)this = puVar3;
    if (puVar2 != &DAT_0040c0f0) {
      free(puVar2);
    }
  }
  else {
    memmove((void *)(iVar1 + 8),param_1,(size_t)param_2);
    **(undefined4 **)this = puVar2;
    *(undefined1 *)(*(int *)this + 8 + (int)puVar2) = 0;
  }
  return this;
}



/* VA 00408ffb */

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;

                    /* WARNING: Could not recover jumptable at 0x00408ffb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}
