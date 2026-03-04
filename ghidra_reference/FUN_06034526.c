/* FUN_06034526  0x06034526 */


undefined8 FUN_06034526(void)

{
  undefined4 uVar1;
  undefined *puVar2;
  code *in_r0;
  int iVar3;
  undefined *puVar4;
  int unaff_r14;
  undefined4 in_stack_00000010;
  
  iVar3 = (*in_r0)();
  puVar2 = DAT_0603455c;
  uVar1 = DAT_06034558;
  puVar4 = PTR_DAT_06034554;
  if (iVar3 < (int)PTR_DAT_06034554) {
    DAT_0603455c[unaff_r14] = (char)DAT_06034558;
    puVar4 = puVar2;
    in_stack_00000010 = uVar1;
  }
  return CONCAT44(in_stack_00000010,puVar4);
}

