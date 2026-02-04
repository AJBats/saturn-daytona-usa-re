int FUN_06035c1c(param_1)
    char *param_1;
{

  char cVar1;

  int iVar2;

  

  iVar2 = 0;

  while (cVar1 = *param_1, param_1 = param_1 + 1, cVar1 != '\0') {

    iVar2 = iVar2 + 1;

  }

  return iVar2;

}
