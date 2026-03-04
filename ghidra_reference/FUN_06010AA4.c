/* FUN_06010AA4  0x06010AA4 */


void FUN_06010aa4(ushort param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  
  puVar1 = PTR_DAT_06010ae4;
  *(int *)PTR_DAT_06010ae4 = *(int *)PTR_DAT_06010ae4 + -1;
  puVar2 = PTR_DAT_06010b7c;
  if ((param_1 & PTR_DAT_06010acc._0_2_) == 0) {
    if ((*(int *)puVar1 <= (int)DAT_06010b70) &&
       ((*(int *)puVar1 < 1 || ((param_1 & DAT_06010b72) != 0)))) {
      *(undefined2 *)PTR_DAT_06010b7c = *(undefined2 *)PTR_DAT_06010b80;
      uVar3 = (uint)*(ushort *)puVar2;
      if ((uVar3 == (int)DAT_06010b74) || ((uVar3 == (int)DAT_06010b76 || (uVar3 == 4)))) {
        *(undefined2 *)puVar2 = 0;
      }
      *(undefined4 *)puVar1 = 0;
      FUN_06010b54();
      *PTR_DAT_06010b84 = 10;
      if (*(uint *)PTR_DAT_06010b88 < 10) {
        (*(code *)PTR_FUN_06010b90)(0xc,(int)DAT_06010b7a,(int)DAT_06010b78,PTR_DAT_06010b8c);
        return;
      }
    }
  }
  else {
    *PTR_DAT_06010ae8 = 0;
  }
  return;
}

