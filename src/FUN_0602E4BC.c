extern int DAT_0602e51a;

extern int DAT_0602e51c;

extern int DAT_0602e51e;

extern int DAT_0602e520;

extern int DAT_0602e522;

extern int DAT_0602e5a2;

extern int DAT_0602e5a4;

extern int DAT_0602e5a6;

extern int PTR_DAT_0602e524;

extern int PTR_DAT_0602e524;

extern int PTR_DAT_0602e5a8;

extern int PTR_DAT_0602e5a8;

int FUN_0602e4bc()
{

  long long lVar1;

  int in_r0;

  short sVar2;

  char *puVar3;

  int iVar4;

  unsigned int uVar5;

  int iVar6;

  short sVar7;

  short sVar8;

  iVar6 = *(int *)(0x0602E8AC + *(int *)0x0607EAD8 * 4) +

          *(int *)(DAT_0602e51a + in_r0) * 0x10;

  sVar2 = (*0x0602744C)

                    (*(int *)(DAT_0602e51c + iVar6) - *(int *)(DAT_0602e520 + in_r0),

                     *(int *)(DAT_0602e51e + iVar6) - *(int *)(DAT_0602e522 + in_r0));

  sVar2 = -sVar2;

  sVar7 = (short)*(int *)(PTR_DAT_0602e524 + in_r0);

  sVar8 = sVar2 - sVar7;

  puVar3 = 0xFFFFFF00;

  if (((int)sVar8 <= (int)0xFFFFFF00) ||

     (puVar3 = 0x00000100, (int)0x00000100 < (int)sVar8)) {

    sVar8 = (short)puVar3;

  }

  iVar4 = (int)(short)(sVar8 + sVar7);

  *(int *)(0x00000030 + in_r0) = iVar4;

  *(int *)(0x00000028 + in_r0) = iVar4;

  lVar1 = (long long)*(int *)(0x00000008 + iVar6) * (long long)0x0000038E;

  uVar5 = (int)((unsigned long long)lVar1 >> 0x20) << 0x10 | (unsigned int)lVar1 >> 0x10;

  *(unsigned int *)(DAT_0602e5a2 + in_r0) = uVar5;

  if (((int)uVar5 < *(int *)(DAT_0602e5a4 + in_r0)) && (*(int *)0x0608325C == 0)) {

    *(int *)0x0608325C = (int)DAT_0602e5a6;

    in_r0 = (*0x0602CCD0)();

  }

  iVar6 = (int)(short)((sVar2 - (short)*(int *)(PTR_DAT_0602e5a8 + in_r0)) +

                      (short)0x00003FFF);

  if ((0x00000000 <= iVar6) && (iVar6 <= (int)0x00007FFF)) {

    return in_r0;

  }

  *(int *)(0x00000244 + in_r0) = *(int *)(0x00000244 + in_r0) + 1;

  return in_r0;

}
