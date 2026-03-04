/* FUN_0601B584  0x0601B584 */


void FUN_0601b584(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_FUN_0601b5f8;
  (*(code *)PTR_FUN_0601b5f8)(PTR_DAT_0601b600,PTR_DAT_0601b5fc,0x60);
  (*(code *)puVar1)(PTR_DAT_0601b608,PTR_DAT_0601b604,0x20);
  (*(code *)puVar1)(PTR_DAT_0601b610,PTR_DAT_0601b60c,0x20);
  (*(code *)PTR_FUN_0601b61c)(PTR_DAT_0601b618,PTR_DAT_0601b614,(int)PTR_DAT_0601b5f4._0_2_);
  (*(code *)PTR_FUN_0601b620)(0xc);
  (*(code *)PTR_FUN_0601b624)();
  (*(code *)PTR_FUN_0601b630)
            (8,*(undefined4 *)PTR_DAT_0601b628,0x16,
             PTR_DAT_0601b62c + *(int *)(PTR_DAT_0601b628 + 4),PTR_DAT_0601b628);
  FUN_0601ba50((int)(char)*PTR_DAT_0601b638,(int)(char)*PTR_DAT_0601b634,0);
  *PTR_DAT_0601b63c = 0;
  *PTR_DAT_0601b640 = 4;
  return;
}

