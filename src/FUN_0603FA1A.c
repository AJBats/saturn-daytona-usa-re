extern int DAT_0603fa5e;

extern int PTR_DAT_0603fa60;

extern int PTR_DAT_0603fa60;

extern int FUN_0603face();

void FUN_0603fa1a(param_1, param_2)
    int *param_1;
    int param_2;
{

  unsigned short uVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  char auStack_28 [4];

  int uStack_24;

  int uStack_20;

  int uStack_1c;

  puVar3 = 0x01000000;

  puVar2 = 0x060A4D14;

  uVar1 = DAT_0603fa5e;

  uStack_20 = *param_1;

  uStack_1c = param_1[2];

  *(int *)(*(int *)0x060A4D14 + (int)PTR_DAT_0603fa60) = 0;

  uStack_24 = param_2;

  do {

    if (((*(unsigned char *)(param_1 + 0xd) & uVar1) == 0) || ((*(unsigned char *)(param_1 + 0xd) & uVar1) == 5))

    break;

    FUN_0603face(param_1,auStack_28);

    iVar4 = *(int *)(*(int *)puVar2 + (int)PTR_DAT_0603fa60) + 1;

    *(int *)(*(int *)puVar2 + (int)PTR_DAT_0603fa60) = iVar4;

  } while (iVar4 <= (int)puVar3);

  if (param_1[1] != 0) {

    (*(void(*)())0x0603F91C)(uStack_20,param_1[1],uStack_24);

    param_1[6] = param_1[6] + *(int *)(param_1[1] + 0xc);

    param_1[1] = 0;

  }

  if (param_1[3] != 0) {

    (*(void(*)())0x0603F91C)(uStack_1c,param_1[3],uStack_24);

    param_1[3] = 0;

  }

  *(unsigned char *)(param_1 + 0xd) = *(unsigned char *)(param_1 + 0xd) & 0x80 | 5;

  return;

}
