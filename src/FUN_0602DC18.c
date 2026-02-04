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

char * 
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int iVar4;

  int in_pr;

  (**(void **)(0x0602DC44 + *(int *)0x06082A30 * 4))();

  puVar1 = 0x0608325C;

  iVar3 = *(int *)0x0608325C;

  if (iVar3 != 0) {

    *(int *)0x06083258 = *(int *)(0x0602EC54 + iVar3 * 4);

    *(int *)puVar1 = iVar3 + -1;

  }

  (*(void(*)())0x0600DB64)();

  iVar3 = *(int *)0x0607E940;

  if (*(int *)(0x00000244 + iVar3) < 0x00000007) {

    iVar4 = *(int *)0x0607EAC8 - 0x00000001;

    if (0x00000028 == iVar4) {

      *(unsigned int *)(DAT_0602e284 + iVar3) =

           *(unsigned int *)(DAT_0602e284 + iVar3) & ~(int)DAT_0602e286 & ~(int)DAT_0602e288 &

           ~(int)DAT_0602e28a & ~(int)DAT_0602e28c;

      iVar4 = *(int *)0x0607EAC8 - 0x00000001;

    }

    *(int *)0x0607EAC8 = iVar4;

  }

  else {

    *(char **)0x0605A1D0 = 0x00010000;

    *(int *)0x06063E20 = *(int *)0x06082A34;

    *(int *)0x06082A30 = 0x00000000;

    *(int *)0x0605A1C4 = (int)DAT_0602e3ca;

    *(int *)(0x0607EAC8 + iVar3) = 0x00000001;

    *(int *)(PTR_DAT_0602e3cc + iVar3) = (int)DAT_0602e3ca;

  }

  iVar4 = *(int *)(DAT_0602e28e + iVar3);

  if (iVar4 != 0x00000000) {

    *(int *)(DAT_0602e28e + iVar3) = iVar4 - 0x00000001;

  }

  *(int *)(0x000000C0 + iVar3) = 0x00000000;

  (*(void(*)())0x0602F3EC)();

  (*(void(*)())0x0602F7BC)();

  (*(void(*)())0x06030A06)();

  (*(void(*)())0x06030EE0)();

  (*(void(*)())0x060085B8)();

  (*(void(*)())0x0600C4F8)();

  (*(void(*)())0x0602D82A)();

  (*(void(*)())0x0602F17C)();

  iVar3 = (*(void(*)())0x0602ECCC)();

  if (iVar3 < 2) {

    iVar3 = 1;

  }

  else if (0x7e < iVar3) {

    iVar3 = 0x7f;

  }

  (*(void(*)())0x0601D5F4)(1,iVar3,param_3,param_4,in_pr);

  (*(void(*)())0x0602E450)(*(int *)((int)DAT_0602e372 + *(int *)0x0607E940));

  (*(void(*)())0x0602E4BC)();

  (*(void(*)())0x0600CE66)();

  (*(void(*)())0x0603053C)(0x00000000);

  (*(void(*)())0x0600D780)(0x00000000);

  puVar2 = *(char **)0x0607E940;

  *(int *)(puVar2 + DAT_0602e376) = *(int *)(puVar2 + 0x00300020);

  puVar1 = 0x06082A26;

  if (0x00000028 <= *(int *)0x06082A2C) {

    if (((int)(char)*0x06082A25 & 0x00000004) == 0) {

      puVar2 = (char *)(*(void(*)())0x0603226C)();

    }

    else {

      *(int *)0x06082A26 = (char)0x00000000;

      puVar2 = puVar1;

    }

  }

  return puVar2;

}
