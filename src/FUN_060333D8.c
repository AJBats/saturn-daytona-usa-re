extern int FUN_0603307c();
extern int FUN_06033470();
extern int FUN_06033550();
extern int FUN_06033648();
extern int FUN_06033700();

int FUN_060333d8(param_1, param_2, param_3, param_4)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
{

  char *puVar1;

  int uVar2;

  int in_pr;

  puVar1 = 0x060629AA;

  *(short *)0x060629AA = 8;

  *(short *)(puVar1 + -2) = 2;

  FUN_06033550();

  *(short *)0x0606299A = 8;

  FUN_06033648();

  FUN_06033470();

  if (('\0' < **(char **)0x06033880) || (**(int **)0x06033864 < 1)) {

    FUN_06033700(param_1,param_2,0x0606298C,param_4,in_pr);

  }

  FUN_06033700(param_1,param_2,0x0606299C,param_4,in_pr);

  uVar2 = FUN_0603307c();

  return uVar2;

}
