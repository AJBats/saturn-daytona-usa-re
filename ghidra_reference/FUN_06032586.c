/* FUN_06032586  0x06032586 */


undefined4 FUN_06032586(void)

{
  undefined *puVar1;
  code *in_r0;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined *unaff_r14;
  
  (*in_r0)();
  (*(code *)PTR_FUN_060325dc)
            (*(undefined4 *)(unaff_r14 + DAT_060325d0),*(undefined4 *)(unaff_r14 + DAT_060325d4),
             *(undefined4 *)(unaff_r14 + DAT_060325d8));
  (*(code *)PTR_FUN_060325e4)((int)*(short *)(unaff_r14 + DAT_060325e0));
  puVar1 = unaff_r14;
  if (((uint)PTR_DAT_060325f0 & (int)(char)unaff_r14[DAT_060325ec]) == 0) {
    puVar1 = PTR_DAT_060325f4;
  }
  *(undefined **)(unaff_r14 + DAT_06032668) = puVar1 + DAT_060325e8;
  iVar4 = DAT_0603266c;
  do {
    iVar3 = iVar4;
    (*(code *)PTR_FUN_06032670)();
    (*(code *)PTR_FUN_06032678)(*(undefined4 *)(unaff_r14 + DAT_06032668));
    (*(code *)PTR_FUN_06032680)((int)(char)unaff_r14[(DAT_0603266c - iVar3) + DAT_0603267c]);
    *(int *)(unaff_r14 + DAT_06032668) = *(int *)(unaff_r14 + DAT_06032668) + DAT_06032684;
    (*(code *)PTR_FUN_06032688)();
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar2 = (*(code *)PTR_FUN_06032688)();
  return uVar2;
}

