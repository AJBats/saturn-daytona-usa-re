/* FUN_06008C14  0x06008C14 */


char FUN_06008c14(void)

{
  undefined *puVar1;
  int iVar2;
  char cVar3;
  
  puVar1 = PTR_DAT_06008c38;
  iVar2 = (*(code *)PTR_FUN_06008c50)();
  if (iVar2 == 0) {
    *(undefined4 *)puVar1 = 0x1f;
    cVar3 = '\0';
  }
  else {
    cVar3 = *PTR_DAT_06008c54;
    if (cVar3 == '\0') {
      *(undefined4 *)puVar1 = 4;
    }
    else {
      *(undefined4 *)puVar1 = 7;
    }
    *PTR_DAT_06008cb4 = 0;
  }
  *(undefined2 *)PTR_DAT_06008cb8 = 3;
  return cVar3;
}

