/* FUN_06008A18  0x06008A18 */


undefined4 FUN_06008a18(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar1 = PTR_DAT_06008ac4;
  *(int *)PTR_DAT_06008ac4 = *(int *)PTR_DAT_06008ac4 + -1;
  uVar3 = (*(code *)PTR_FUN_06008ac8)();
  puVar2 = PTR_DAT_06008acc;
  if ((-1 < *(int *)puVar1) && ((*(ushort *)PTR_DAT_06008ad0 & DAT_06008ac0) == 0)) {
    if (*(int *)PTR_DAT_06008acc == 2) {
      (*(code *)PTR_FUN_06008ae0)();
    }
    (*(code *)PTR_FUN_06008ae4)();
    (*(code *)PTR_FUN_06008ae8)();
    (*(code *)PTR_FUN_06008aec)();
    (*(code *)PTR_FUN_06008af0)();
    (*(code *)PTR_FUN_06008af4)(*(undefined4 *)puVar1,0x15);
    (*(code *)PTR_FUN_06008af8)();
    if (*(int *)puVar1 <= (int)DAT_06008ac2) {
      (*(code *)PTR_FUN_06008afc)();
    }
    uVar3 = (*(code *)PTR_FUN_06008b00)();
    return uVar3;
  }
  if (*(int *)puVar1 < 0) {
    iVar4 = *(int *)PTR_DAT_06008acc;
    *(uint *)PTR_DAT_06008acc = iVar4 + 1U;
    if (2 < iVar4 + 1U) {
      *(undefined4 *)puVar2 = 0;
    }
  }
  else {
    uVar3 = (*(code *)PTR_FUN_06008ad4)();
  }
  *(undefined4 *)PTR_DAT_06008ad8 = 4;
  *(undefined2 *)PTR_DAT_06008adc = 3;
  return uVar3;
}

