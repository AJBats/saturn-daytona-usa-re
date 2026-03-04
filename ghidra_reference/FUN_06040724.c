/* FUN_06040724  0x06040724 */


int FUN_06040724(int param_1,int param_2)

{
  int in_r0;
  int iVar1;
  int extraout_r3;
  
  if (*(char *)(param_1 + in_r0) == '\0') {
    return param_2;
  }
  (*(code *)PTR_FUN_06040774)(param_1,param_2,*(undefined1 *)(param_1 + 0x1e));
  iVar1 = (*(code *)PTR_FUN_06040778)();
  return iVar1 + extraout_r3;
}

