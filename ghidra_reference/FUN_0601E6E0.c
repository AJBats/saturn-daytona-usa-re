/* FUN_0601E6E0  0x0601E6E0 */


undefined4 FUN_0601e6e0(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_SMPC_SF_0601e754;
  do {
  } while ((*PTR_SMPC_SF_0601e754 & 1) == 1);
  *PTR_SMPC_SF_0601e754 = 1;
  *PTR_SMPC_COMREG_0601e758 = 0x1a;
  do {
  } while ((*puVar1 & 1) != 0);
  uVar2 = (**(code **)(*(int *)PTR_PTR_0601e75c + 0x18))
                    (*(undefined2 *)(PTR_DAT_0601e760 + param_1 * 0x20 + 0x1c));
  do {
  } while ((*puVar1 & 1) == 1);
  *puVar1 = 1;
  *PTR_SMPC_COMREG_0601e758 = 0x19;
  do {
  } while ((*puVar1 & 1) != 0);
  return uVar2;
}

