/* FUN_06040894  0x06040894 */


undefined4 FUN_06040894(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  *(uint *)(param_1 + 0x24) = param_2 & 0xff;
  return uVar1;
}

