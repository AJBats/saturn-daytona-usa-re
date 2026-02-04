extern int DAT_0603bf6e;

extern void FUN_0603b9d6();

void FUN_0603bf22(param_1, param_2)
    int param_1;
    int *param_2;
{

  FUN_0603b9d6(param_2);

  *(int *)(param_1 + DAT_0603bf6e) = 0;

  if (param_2 == (int *)0x0) {

    return;

  }

  (*0x0604087C)(*(int *)(*param_2 + 0x18));

  return;

}
