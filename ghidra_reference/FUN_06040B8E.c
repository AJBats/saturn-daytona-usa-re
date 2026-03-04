/* FUN_06040B8E  0x06040B8E */


undefined *
FUN_06040b8e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            ,int param_6,int param_7,int param_8,int param_9)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 *unaff_r13;
  undefined4 unaff_r14;
  
  (*(code *)PTR_FUN_06040c04)(*unaff_r13,param_2,param_3,&param_8,&param_9,&param_7);
  puVar1 = PTR_DAT_06040c08;
  if (((param_9 <= unaff_r13[2] + unaff_r13[4] + param_5) && (param_7 != 0)) && (0 < param_5)) {
    param_6 = param_6 - (param_8 - param_7);
  }
  uVar2 = (*(code *)PTR_FUN_06040c0c)();
  *(undefined4 *)puVar1 = uVar2;
  *(undefined4 *)(puVar1 + 4) = unaff_r14;
  *(int *)(puVar1 + 8) = param_6;
  *(int *)(puVar1 + 0xc) = param_5;
  puVar1[0x10] = 1;
  return puVar1;
}

