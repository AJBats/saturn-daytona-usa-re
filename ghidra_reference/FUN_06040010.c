/* FUN_06040010  0x06040010 */


undefined4 FUN_06040010(int param_1)

{
  undefined *puVar1;
  int iVar2;
  uint in_r2;
  undefined4 uVar3;
  
  puVar1 = PTR_DAT_060400a4;
  *(uint *)(*(int *)PTR_DAT_060400a4 + (int)DAT_0604009e) =
       *(uint *)(*(int *)PTR_DAT_060400a4 + (int)DAT_0604009e) & in_r2;
  iVar2 = (*(code *)PTR_FUN_060400a8)(*(int *)puVar1 + (int)DAT_060400a0,param_1);
  if (iVar2 == 0) {
    *(uint *)((int)DAT_0604009e + *(int *)puVar1) =
         *(uint *)(*(int *)puVar1 + (int)DAT_0604009e) | 1;
  }
  if (param_1 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0x17;
  }
  *(undefined4 *)(*(int *)puVar1 + (int)DAT_060400a2) = uVar3;
  if (iVar2 == -0xf) {
    return 0xfffffffd;
  }
  if (iVar2 == -0xe) {
    return 0xfffffffe;
  }
  if (iVar2 != -0xd) {
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    return 0;
  }
  return 0xffffffe9;
}

