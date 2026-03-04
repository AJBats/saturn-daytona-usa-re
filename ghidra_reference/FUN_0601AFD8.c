/* FUN_0601AFD8  0x0601AFD8 */


void FUN_0601afd8(void)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = PTR_DAT_0601b064;
  (*(code *)PTR_FUN_0601b068)
            (0,0x30,0x30,0,1,*(uint *)PTR_DAT_0601b064 & 0xffff,(int)PTR_DAT_0601b060._0_2_,
             (int)DAT_0601b05e);
  uVar2 = *(int *)puVar1 + 2;
  *(uint *)puVar1 = uVar2;
  if ((uint)(int)DAT_0601b05e <= uVar2) {
    *PTR_DAT_0601b06c = *PTR_DAT_0601b06c + '\x01';
    *PTR_DAT_0601b070 = 0x28;
  }
  return;
}

