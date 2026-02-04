extern void FUN_0603253c();
extern void FUN_06032584();
extern void FUN_0603268c();
extern void FUN_06032e6c();
extern void FUN_06032ea4();

int FUN_06032304(param_1)
    int param_1;
{

  int uVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  iVar4 = *(int *)(0x060623B0 + param_1 * 4);

  piVar2 = *(int **)(iVar4 + 0x000002D8);

  iVar3 = piVar2[1];

  if (*piVar2 == *(int *)0x06082A20) {

    *(int **)(iVar4 + 0x000002D8) = piVar2 + 3;

    uVar1 = (**(void **)(0x06032334 + iVar3 * 4))();

    return uVar1;

  }

  if (*(unsigned char *)(iVar4 + 0x000002DC) == 0) {

    FUN_06032e6c();

    FUN_0603253c();

    FUN_0603268c();

  }

  else if ((*(unsigned char *)(iVar4 + 0x000002DC) & 4) != 0) {

    FUN_06032e6c();

    FUN_0603253c();

    FUN_0603268c();

    uVar1 = FUN_06032584();

    return uVar1;

  }

  FUN_06032584();

  uVar1 = FUN_06032ea4();

  return uVar1;

}
