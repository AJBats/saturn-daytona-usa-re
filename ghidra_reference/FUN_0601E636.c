/* FUN_0601E636  0x0601E636 */


undefined4 FUN_0601e636(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_SMPC_SF_0601e694;
  do {
  } while ((*PTR_SMPC_SF_0601e694 & 1) == 1);
  *PTR_SMPC_SF_0601e694 = 1;
  *PTR_SMPC_COMREG_0601e698 = 0x1a;
  do {
  } while ((*puVar1 & 1) != 0);
  uVar2 = (**(code **)(*(int *)PTR_PTR_0601e69c + 0x1c))(param_1,param_2,0x10,PTR_DAT_0601e6a0);
  do {
  } while ((*puVar1 & 1) == 1);
  *puVar1 = 1;
  *PTR_SMPC_COMREG_0601e698 = 0x19;
  do {
  } while ((*puVar1 & 1) != 0);
  return uVar2;
}

