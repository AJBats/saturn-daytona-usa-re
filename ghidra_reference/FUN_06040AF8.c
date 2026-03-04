/* FUN_06040AF8  0x06040AF8 */


int FUN_06040af8(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_06040b32();
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = FUN_06040c10(iVar1,param_1);
  if (iVar2 == 0) {
    return 0;
  }
  return iVar1;
}

