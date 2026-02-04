extern int DAT_06042b9c;

extern int DAT_06042b9e;

extern int DAT_06042ba0;

extern int DAT_06042ba2;

extern int DAT_06042ba4;

extern int DAT_06042ba6;

unsigned int FUN_06042aca(param_1, param_2)
    int *param_1;
    int param_2;
{

  unsigned int uVar1;

  unsigned int uVar2;

  unsigned int uVar3;

  unsigned int *puVar4;

  *(int *)((param_2 << 4) + -0x80) = *param_1;

  if ((param_1[9] & 1) == 1) {

    *(int *)((param_2 << 4) + -0x7c) = param_1[1];

  }

  if ((param_1[9] & 2) == 2) {

    *(int *)((param_2 << 4) + -0x78) = param_1[2];

  }

  puVar4 = (unsigned int *)((param_2 << 4) + -0x74);

  uVar2 = *puVar4;

  if ((param_1[9] & 4) == 4) {

    uVar2 = uVar2 & 0xFFFF3FFF | param_1[3] << 0xe;

  }

  if ((param_1[9] & 8) == 8) {

    uVar2 = uVar2 & -12289 | param_1[4] << 0xc;

  }

  if ((param_1[9] & 0x10) == 0x10) {

    uVar2 = uVar2 & -3073 | param_1[5];

  }

  if ((param_1[9] & 0x20) == 0x20) {

    uVar2 = uVar2 & -513 | param_1[6];

  }

  uVar1 = param_1[9];

  uVar3 = uVar2 & 0xffffffe7;

  if ((uVar1 & 0x40) == 0x40) {

    uVar3 = uVar2 & 0xffffffe3 | param_1[7];

  }

  if ((param_1[9] & 0x100) == 0x100) {

    uVar3 = uVar3 & 0xfffffffd;

  }

  *puVar4 = uVar3;

  if ((param_1[9] & 0x80) == 0x80) {

    *(char *)(param_2 + DAT_06042ba6) = (char)param_1[8];

  }

  return uVar1 & 0x40;

}
