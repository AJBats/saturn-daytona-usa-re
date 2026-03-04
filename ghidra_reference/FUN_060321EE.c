/* FUN_060321EE  0x060321EE */


undefined * FUN_060321ee(undefined4 param_1)

{
  undefined1 uVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  int unaff_r14;
  int in_stack_00000000;
  
  while( true ) {
    FUN_06032e18(param_1);
    puVar4 = *(undefined1 **)(PTR_PTR_06032250 + in_stack_00000000 * 4);
    puVar3 = (undefined1 *)(DAT_06032254 + unaff_r14);
    iVar5 = DAT_06032258;
    do {
      uVar1 = *puVar4;
      puVar4 = puVar4 + 1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    in_stack_00000000 = in_stack_00000000 + 1;
    if (DAT_0603225c < in_stack_00000000) break;
    unaff_r14 = *(int *)(PTR_PTR_0603223c + in_stack_00000000 * 4);
    *(char *)(unaff_r14 + DAT_06032240) = (char)in_stack_00000000;
    FUN_06032d90();
    *(short *)(unaff_r14 + DAT_06032248) = (short)DAT_06032244;
    param_1 = DAT_0603224c;
  }
  *(undefined4 *)PTR_DAT_06032260 = 0;
  *PTR_DAT_06032264 = 0;
  puVar2 = PTR_DAT_06032268;
  *PTR_DAT_06032268 = 0;
  return puVar2;
}

