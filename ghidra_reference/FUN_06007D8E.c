/* FUN_06007D8E  0x06007D8E */


void FUN_06007d8e(void)

{
  bool bVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)(int)DAT_06007d9e;
  bVar1 = false;
  while ((*pbVar2 & PTR_DAT_06007da0._0_2_) != PTR_DAT_06007da0._0_2_) {
    bVar1 = true;
  }
  *pbVar2 = *pbVar2 & 0xf;
  if (bVar1) {
    *(short *)PTR_PTR_06007e00 = *(short *)PTR_PTR_06007e00 + -10;
  }
  else {
    *(short *)PTR_PTR_06007e00 = *(short *)PTR_PTR_06007e00 + 10;
  }
                    /* WARNING: Could not recover jumptable at 0x06007dfa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_06007e04)();
  return;
}

