/* FUN_06014468  0x06014468 */


uint FUN_06014468(undefined4 param_1,uint param_2)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = PTR_DAT_060144e8;
  uVar2 = (int)(((uint)*(ushort *)(PTR_DAT_060144ec + 4) ^ (uint)PTR_DAT_060144f0) & 0xff) >> 3;
  uVar3 = uVar2;
  if ((int)param_2 < (int)uVar2) {
    uVar3 = param_2 & 0xffff;
  }
  *(undefined4 *)PTR_DAT_060144f4 = *(undefined4 *)PTR_DAT_060144e8;
  *(uint *)puVar1 = uVar3;
  if (2 < *(uint *)PTR_DAT_060144f8) {
    if (uVar3 < 0xf) {
      *(undefined4 *)puVar1 = 0x1b;
    }
    else {
      *(undefined4 *)puVar1 = 0x1c;
    }
  }
  if (*(int *)puVar1 != *(int *)PTR_DAT_060144f4) {
    uVar2 = (*(code *)PTR_FUN_06014500)(0,DAT_060144fc);
  }
  *(uint *)PTR_DAT_06014508 =
       (uint)(byte)PTR_s_ABCDEFGHIJKLMNOPQRSTUVWXYZ____06014504[*(int *)puVar1];
  return uVar2;
}

