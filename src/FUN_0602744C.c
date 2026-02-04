extern int DAT_060274fc;

extern void FUN_06027378();
extern void FUN_0602755c();

int FUN_0602744c(param_1, param_2)
    int param_1;
    int param_2;
{

  int iVar1;

  int uVar2;

  short sVar3;

  unsigned int uVar4;

  if (param_2 == 0) {

    iVar1 = (int)DAT_060274fc;

    if (param_1 < 0) {

      iVar1 = -iVar1;

    }

    return iVar1;

  }

  uVar4 = (unsigned int)(-1 < param_2);

  uVar2 = FUN_0602755c();

  sVar3 = FUN_06027378(uVar2);

  if (uVar4 == 0) {

    sVar3 = sVar3 + (short)0x00008000;

  }

  return (int)sVar3;

}
