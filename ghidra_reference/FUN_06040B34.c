/* FUN_06040B34  0x06040B34 */


undefined * FUN_06040b34(undefined4 *param_1,undefined4 param_2)

{
  int in_r0;
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  undefined4 uStack_10;
  
  if (PTR_DAT_06040b50[in_r0] == '\0') {
    uStack_10 = param_2;
    iVar2 = (*(code *)PTR_FUN_06040bfc)(param_1[1],param_1[4],param_2,&iStack_24,&iStack_20);
    if (iVar2 == 0) {
      iVar2 = (*(code *)PTR_FUN_06040c00)();
      if (iVar2 == 0) {
        if (iStack_20 < 1) {
          puVar1 = (undefined *)0x0;
        }
        else {
          (*(code *)PTR_FUN_06040c04)(*param_1,0,0,&iStack_18,&iStack_14,&iStack_1c,0,0);
          puVar1 = PTR_DAT_06040c08;
          if (((iStack_14 <= param_1[2] + param_1[4] + iStack_24) && (iStack_1c != 0)) &&
             (0 < iStack_24)) {
            iStack_20 = iStack_20 - (iStack_18 - iStack_1c);
          }
          uVar3 = (*(code *)PTR_FUN_06040c0c)();
          *(undefined4 *)puVar1 = uVar3;
          *(undefined4 *)(puVar1 + 4) = 0;
          *(int *)(puVar1 + 8) = iStack_20;
          *(int *)(puVar1 + 0xc) = iStack_24;
          puVar1[0x10] = 1;
        }
      }
      else {
        puVar1 = (undefined *)0x0;
      }
    }
    else {
      puVar1 = (undefined *)0x0;
    }
  }
  else {
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}

