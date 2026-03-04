/* FUN_0601B48C  0x0601B48C */


void FUN_0601b48c(void)

{
  (*(code *)PTR_FUN_0601b500)(PTR_DAT_0601b4fc,PTR_DAT_0601b4f8,(int)PTR_DAT_0601b4f2._0_2_);
  (*(code *)PTR_FUN_0601b500)(PTR_DAT_0601b508,PTR_DAT_0601b504,0x20);
  (*(code *)PTR_FUN_0601b50c)();
  (*(code *)PTR_FUN_0601b510)(0xc);
  (*(code *)PTR_FUN_0601b51c)
            (8,*(undefined4 *)PTR_DAT_0601b514,0x16,
             PTR_DAT_0601b518 + *(int *)(PTR_DAT_0601b514 + 4),PTR_DAT_0601b514);
  *PTR_DAT_0601b520 = 1;
  return;
}

