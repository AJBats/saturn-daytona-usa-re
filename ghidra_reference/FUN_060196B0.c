/* FUN_060196B0  0x060196B0 */


void FUN_060196b0(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 unaff_r11;
  undefined1 uVar4;
  
  puVar3 = PTR_DAT_06019770;
  puVar2 = PTR_DAT_0601976c;
  puVar1 = PTR_DAT_06019768;
  (*(code *)PTR_FUN_06019774)();
  uVar4 = (undefined1)unaff_r11;
  if ((*(ushort *)(PTR_DAT_06019778 + 2) & DAT_06019762) != 0) {
    (*(code *)PTR_FUN_06019788)
              (0xc,*(undefined4 *)
                    (PTR_DAT_06019780 + (uint)*(ushort *)(PTR_PTR_0601977c + (char)*puVar3 * 2) * 8)
               ,((uint)(byte)(PTR_DAT_06019784 + (char)*puVar3 * 2)[1] * 0x40 +
                (uint)(byte)PTR_DAT_06019784[(char)*puVar3 * 2]) * 2,
               *(int *)((int)(PTR_DAT_06019780 +
                             (uint)*(ushort *)(PTR_PTR_0601977c + (char)*puVar3 * 2) * 8) + 4) +
               (int)(short)PTR_DAT_06019764._0_2_);
    if ('\x01' < (char)*puVar3) {
      *puVar3 = uVar4;
    }
    *(undefined4 *)PTR_DAT_0601978c = unaff_r11;
    *puVar2 = uVar4;
    *(undefined4 *)PTR_DAT_06019790 = 4;
    *puVar1 = 1;
    *PTR_DAT_06019794 = 1;
    return;
  }
  if ((*(ushort *)(PTR_DAT_06019778 + 2) & PTR_DAT_06019764._0_2_) == 0) {
    if ((*(ushort *)(PTR_DAT_06019778 + 2) & DAT_06019864) != 0) {
      *puVar1 = 1;
      *puVar2 = 5;
      *puVar3 = *puVar3 + -1;
      if ((char)*puVar3 < '\0') {
        *puVar3 = 3;
      }
    }
  }
  else {
    *puVar1 = 1;
    *puVar2 = 5;
    *puVar3 = *puVar3 + '\x01';
    if ('\x03' < (char)*puVar3) {
      *puVar3 = uVar4;
    }
  }
  *PTR_DAT_0601986c = *PTR_DAT_0601986c + '\x01';
  *puVar2 = *puVar2 + '\x01';
                    /* WARNING: Could not recover jumptable at 0x060197e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((char)*puVar3 * 4 + DAT_06019870))();
  return;
}

