char * FUN_06033020(param_1)
    int *param_1;
{

  char *puVar1;

  int iVar2;

  char *puVar3;

  puVar1 = 0x06082A28;

  puVar3 = 0x00003333;

  if ((0x00000001 & (int)(char)*0x06082A25) == 0) {

    puVar3 = (char *)0x0;

  }

  iVar2 = *(int *)0x06082A28 + ((int)puVar3 - *(int *)0x06082A28 >> 1);

  *(int *)0x06082A28 = iVar2;

  *param_1 = *param_1 + iVar2;

  return puVar1;

}
