extern short DAT_060274fc;

extern int FUN_06027378();
extern int FUN_0602755c();

int FUN_0602744c(param_1, param_2)
    int param_1;
    int param_2;
{
  int uVar2;
  short sVar3;

  if (param_2 == 0) {
    sVar3 = DAT_060274fc;
    if (param_1 < 0) {
      sVar3 = -sVar3;
    }
    return sVar3;
  }

  uVar2 = FUN_0602755c();
  sVar3 = FUN_06027378(uVar2);

  if (param_2 < 0) {
    sVar3 = sVar3 + (short)0x8000;
  }

  return (int)sVar3;
}
