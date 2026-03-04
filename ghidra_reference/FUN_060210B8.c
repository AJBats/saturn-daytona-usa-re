/* FUN_060210B8  0x060210B8 */


void FUN_060210b8(void)

{
  undefined *puVar1;
  uint uVar2;
  byte bVar3;
  
  puVar1 = PTR_DAT_06021114;
  (*(code *)PTR_FUN_06021118)(8);
  bVar3 = 0;
  do {
    uVar2 = (uint)bVar3;
    bVar3 = bVar3 + 1;
    *(undefined4 *)(puVar1 + uVar2 * 4 + (int)DAT_06021112) = 0;
  } while (bVar3 < 0x2c);
  (*(code *)PTR_FUN_0602111c)(PTR_DAT_06021114);
                    /* WARNING: Could not recover jumptable at 0x060210f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_06021120)();
  return;
}

