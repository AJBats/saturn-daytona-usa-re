/* FUN_060140C8  0x060140C8 */


void FUN_060140c8(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint in_r2;
  
  if (*(uint *)PTR_DAT_06014138 <= in_r2) {
    uVar2 = *(undefined4 *)(PTR_DAT_0601413c + *(int *)PTR_DAT_06014138 * 4);
    (*(code *)PTR_FUN_06014140)();
    puVar1 = PTR_DAT_06014144;
    (*(code *)PTR_FUN_06014148)(uVar2,(int)DAT_06014136,PTR_DAT_06014144);
    (*(code *)PTR_FUN_0601414c)(puVar1,puVar1,puVar1);
    FUN_06013e12();
    (*(code *)PTR_FUN_06014158)(*(undefined4 *)(PTR_PTR_06014154 + *(int *)PTR_DAT_06014150 * 4),4);
    (*(code *)PTR_FUN_06014164)
              (*(undefined4 *)(PTR_PTR_06014160 + *(int *)PTR_DAT_06014150 * 4),
               (int)*(short *)PTR_DAT_0601415c,1);
    *(int *)PTR_DAT_06014168 = *(int *)PTR_DAT_06014168 + -0x30;
  }
  return;
}

