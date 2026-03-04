/* FUN_06013E7A  0x06013E7A */


undefined4 FUN_06013e7a(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_r8;
  code *unaff_r9;
  int *unaff_r10;
  code *unaff_r11;
  int *unaff_r12;
  ushort *unaff_r13;
  int unaff_r14;
  short *in_stack_00000000;
  int *in_stack_00000004;
  
  while( true ) {
    iVar1 = (*unaff_r11)((uint)*unaff_r13 * unaff_r14,(int)DAT_06013f48);
    (*(code *)PTR_FUN_06013f70)(0,DAT_06013f4a + iVar1,unaff_r14);
    (*unaff_r9)((int)*(short *)(unaff_r12 + 6));
    uVar2 = (*unaff_r11)(unaff_r12[1],(uint)*unaff_r13 * unaff_r14);
    iVar1 = (*unaff_r11)(unaff_r12[2],(uint)*unaff_r13 * unaff_r14);
    iVar4 = *unaff_r12;
    uVar3 = (*unaff_r11)(unaff_r12[3],(uint)*unaff_r13 * unaff_r14);
    (*(code *)PTR_FUN_06013f70)(uVar2,iVar4 - iVar1,uVar3);
    (*unaff_r9)(-(int)*(short *)(unaff_r12 + 6));
    (*(code *)PTR_FUN_06013f74)((int)*(short *)((int)unaff_r12 + 0x1a) * (uint)*unaff_r13);
    (*(code *)PTR_FUN_06013f78)((int)*(short *)(unaff_r12 + 7) * (uint)*unaff_r13);
    (*unaff_r9)((int)*(short *)((int)unaff_r12 + 0x1e) * (uint)*unaff_r13);
    iVar1 = (*unaff_r11)(unaff_r12[4],(uint)*unaff_r13 * unaff_r14);
    iVar1 = DAT_06013f4c + iVar1;
    (*(code *)PTR_FUN_06013f7c)(iVar1,iVar1,iVar1);
    (*(code *)PTR_FUN_06013f84)(*(undefined4 *)(PTR_PTR_06013f80 + unaff_r8),4);
    uVar2 = (*(code *)PTR_FUN_06013f8c)
                      (*(undefined4 *)(PTR_PTR_06013f88 + unaff_r8),(int)*in_stack_00000000,1);
    unaff_r10 = unaff_r10 + 8;
    *(int *)PTR_DAT_06013fc0 = *(int *)PTR_DAT_06013f90 + -0x30;
    unaff_r8 = unaff_r8 + 4;
    if (in_stack_00000004 <= unaff_r10) break;
    (*(code *)PTR_FUN_06013f6c)();
    unaff_r12 = unaff_r10;
  }
  return uVar2;
}

