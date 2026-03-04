/* FUN_06005120  0x06005120 */


void FUN_06005120(undefined4 param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint in_r3;
  undefined *puVar1;
  
  puVar1 = PTR_DAT_06005168;
  if ((in_r3 & param_4) == 0) {
    puVar1 = PTR_DAT_06005164;
  }
  if ((param_4 & 8) == 0) {
    (*(code *)PTR_FUN_06005170)(puVar1 + param_2,param_1,param_3);
    return;
  }
  (*(code *)PTR_FUN_0600516c)(param_1,puVar1 + param_2);
  return;
}

