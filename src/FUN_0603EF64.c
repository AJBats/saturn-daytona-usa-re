extern int DAT_0603ef8a;

extern int DAT_0603eff4;

char * FUN_0603ef64(param_1, param_2, param_3)
    int param_1;
    char *param_2;
    int *param_3;
{

  int iVar1;

  char *puVar2;

  if (param_2 == 0x0000FFFF) {

    param_2 = 0x7FFFFFFF;

  }

  puVar2 = (char *)

           ((unsigned int)((int)DAT_0603ef8a + (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0x14))) >> 0xb

           );

  if (param_2 < puVar2) {

    puVar2 = param_2;

  }

  if ((((param_3 != (int *)0x0) &&

       (*param_3 = (int)puVar2 * 0x800,

       *(int *)(param_1 + 0x10) < *(int *)(param_1 + 0x14) + (int)puVar2 * 0x800)) &&

      (iVar1 = (*0x06036BE4)(), *param_3 != 0)) && (iVar1 != 0)) {

    *param_3 = *param_3 - (DAT_0603eff4 - iVar1);

  }

  return puVar2;

}
