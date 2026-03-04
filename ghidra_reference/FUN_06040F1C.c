/* FUN_06040F1C  0x06040F1C */


undefined4 FUN_06040f1c(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_r14;
  
  puVar1 = PTR_DAT_06040f3c;
  if ((unaff_r14 < 0) || (0x17 < unaff_r14)) {
    uVar2 = 0xfffffffa;
  }
  else if (*(char *)(unaff_r14 + *(int *)PTR_DAT_06040f3c) == '\x01') {
    FUN_060412b2();
    *(undefined **)(*(int *)puVar1 + 0x3c) = PTR_DAT_06040fac;
    do {
      iVar3 = FUN_06041698();
      if (iVar3 == 3) {
        return 0xfffffff4;
      }
      iVar3 = FUN_06041310();
    } while (iVar3 != 1);
    *(undefined4 *)(*(int *)puVar1 + 0x3c) = 0;
    *(undefined1 *)(unaff_r14 + *(int *)puVar1) = 0;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffff9;
  }
  return uVar2;
}

