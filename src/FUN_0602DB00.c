extern int DAT_0602dbac;

extern int DAT_0602dbae;

extern int DAT_0602dbb0;

extern int DAT_0602dbb2;

extern int DAT_0602dbb4;

extern int DAT_0602dbb6;

extern int DAT_0602dbb8;

extern int DAT_0602dbba;

extern int DAT_0602dbbc;

extern int DAT_0602dbbe;

extern int DAT_0602dbc0;

extern int DAT_0602dbc2;

extern int DAT_0602e284;

extern int DAT_0602e286;

extern int DAT_0602e288;

extern int DAT_0602e28a;

extern int DAT_0602e28c;

extern int DAT_0602e28e;

extern int DAT_0602e372;

extern int DAT_0602e376;

extern int DAT_0602e3ca;

extern int PTR_DAT_0602e3cc;

extern int PTR_DAT_0602e3cc;

char * FUN_0602db00()
{

  char *puVar1;

  int iVar2;

  char *puVar3;

  int uVar4;

  int iVar5;

  unsigned int uVar6;

  (*(void(*)())0x0601D5F4)(0x00000002,0x00000000);

  (*(void(*)())0x0601D5F4)(0x00000003,0x00000000);

  uVar4 = 0x00000000;

  *(int *)0x06082A30 = 0x00000000;

  *(int *)0x06082A26 = (char)uVar4;

  *(int *)0x060788FC = uVar4;

  *(int *)0x06082A38 = uVar4;

  iVar2 = *(int *)0x0607E940;

  *(int *)0x0607EAC8 = 0x000000C8;

  uVar4 = 0x00000000;

  *(int *)(DAT_0602dbac + iVar2) = 0x00000000;

  *(int *)(DAT_0602dbae + iVar2) = uVar4;

  *(int *)(DAT_0602dbb0 + iVar2) = uVar4;

  *(int *)(DAT_0602dbb2 + iVar2) = uVar4;

  *(int *)0x06082A2C = uVar4;

  *(int *)(DAT_0602dbb4 + iVar2) = uVar4;

  *(int *)(DAT_0602dbb6 + iVar2) = uVar4;

  uVar4 = *(int *)(DAT_0602dbb8 + iVar2);

  *(int *)(DAT_0602dbba + iVar2) = uVar4;

  *(int *)(DAT_0602dbbc + iVar2) = uVar4;

  *(int *)(DAT_0602dbbe + iVar2) = 0x00000000;

  uVar6 = (int)((unsigned long long)((long long)0x0000038E * (long long)(int)0x00FA0000) >> 0x20) <<

          0x10 | (unsigned int)((long long)0x0000038E * (long long)(int)0x00FA0000) >> 0x10;

  if (0x000000FA <= *(int *)(DAT_0602dbc0 + iVar2)) {

    *(unsigned int *)(0x0000000C + iVar2) = uVar6;

  }

  *(unsigned int *)(0x00000194 + iVar2) = uVar6;

  *(int *)0x0605A1C4 = (int)DAT_0602dbc2;

  *(int *)0x06082A34 = *(int *)0x06063E1C;

  *(int *)0x06063E20 = (int)DAT_0602dbc2;

  (**(void **)(0x0602DC44 + *(int *)0x06082A30 * 4))();

  puVar1 = 0x0608325C;

  iVar2 = *(int *)0x0608325C;

  if (iVar2 != 0) {

    *(int *)0x06083258 = *(int *)(0x0602EC54 + iVar2 * 4);

    *(int *)puVar1 = iVar2 + -1;

  }

  (*(void(*)())0x0600DB64)();

  iVar2 = *(int *)0x0607E940;

  if (*(int *)(0x00000244 + iVar2) < 0x00000007) {

    iVar5 = *(int *)0x0607EAC8 - 0x00000001;

    if (0x00000028 == iVar5) {

      *(unsigned int *)(DAT_0602e284 + iVar2) =

           *(unsigned int *)(DAT_0602e284 + iVar2) & ~(int)DAT_0602e286 & ~(int)DAT_0602e288 &

           ~(int)DAT_0602e28a & ~(int)DAT_0602e28c;

      iVar5 = *(int *)0x0607EAC8 - 0x00000001;

    }

    *(int *)0x0607EAC8 = iVar5;

  }

  else {

    *(char **)0x0605A1D0 = 0x00010000;

    *(int *)0x06063E20 = *(int *)0x06082A34;

    *(int *)0x06082A30 = 0x00000000;

    *(int *)0x0605A1C4 = (int)DAT_0602e3ca;

    *(int *)(0x0607EAC8 + iVar2) = 0x00000001;

    *(int *)(PTR_DAT_0602e3cc + iVar2) = (int)DAT_0602e3ca;

  }

  iVar5 = *(int *)(DAT_0602e28e + iVar2);

  if (iVar5 != 0x00000000) {

    *(int *)(DAT_0602e28e + iVar2) = iVar5 - 0x00000001;

  }

  *(int *)(0x000000C0 + iVar2) = 0x00000000;

  (*(void(*)())0x0602F3EC)();

  (*(void(*)())0x0602F7BC)();

  (*(void(*)())0x06030A06)();

  (*(void(*)())0x06030EE0)();

  (*(void(*)())0x060085B8)();

  (*(void(*)())0x0600C4F8)();

  (*(void(*)())0x0602D82A)();

  (*(void(*)())0x0602F17C)();

  iVar2 = (*(void(*)())0x0602ECCC)();

  if (iVar2 < 2) {

    iVar2 = 1;

  }

  else if (0x7e < iVar2) {

    iVar2 = 0x7f;

  }

  (*(void(*)())0x0601D5F4)(1,iVar2);

  (*(void(*)())0x0602E450)(*(int *)((int)DAT_0602e372 + *(int *)0x0607E940));

  (*(void(*)())0x0602E4BC)();

  (*(void(*)())0x0600CE66)();

  (*(void(*)())0x0603053C)(0x00000000);

  (*(void(*)())0x0600D780)(0x00000000);

  puVar3 = *(char **)0x0607E940;

  *(int *)(puVar3 + DAT_0602e376) = *(int *)(puVar3 + 0x00300020);

  puVar1 = 0x06082A26;

  if (0x00000028 <= *(int *)0x06082A2C) {

    if (((int)(char)*0x06082A25 & 0x00000004) == 0) {

      puVar3 = (char *)(*(void(*)())0x0603226C)();

    }

    else {

      *(int *)0x06082A26 = (char)0x00000000;

      puVar3 = puVar1;

    }

  }

  return puVar3;

}
