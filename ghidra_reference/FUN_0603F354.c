/* FUN_0603F354  0x0603F354 */


int FUN_0603f354(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  int unaff_r11;
  int unaff_r12;
  int iVar3;
  int unaff_r14;
  char local_38 [16];
  undefined1 auStack_28 [16];
  undefined1 auStack_18 [24];
  
  puVar1 = PTR_FUN_0603f380;
  FUN_0603f3da(auStack_18);
  iVar3 = 0;
  while ((0 < unaff_r11 && (FUN_0603f582(auStack_18,local_38), local_38[0] != '\0'))) {
    if ((iVar3 <= unaff_r12) ||
       (iVar2 = (*(code *)PTR_FUN_0603f430)(unaff_r14 + -0xc,auStack_28,0xc,param_4,param_1),
       iVar2 != 0)) {
      FUN_0603f84c(unaff_r14,local_38);
      (*(code *)puVar1)(unaff_r14 + 0xc,auStack_28,0xc);
    }
    unaff_r14 = unaff_r14 + 0x18;
    iVar3 = iVar3 + 1;
    unaff_r11 = unaff_r11 + -1;
  }
  *(byte *)(unaff_r14 + -0xd) = *(byte *)(unaff_r14 + -0xd) | 0x80;
  return iVar3;
}

