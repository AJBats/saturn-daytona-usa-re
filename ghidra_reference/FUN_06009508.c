/* FUN_06009508  0x06009508 */


void FUN_06009508(void)

{
  if ((*(uint *)PTR_DAT_06009598 & 1) == 0) {
    if (*(int *)PTR_DAT_060095a0 == 0) {
      *(int *)PTR_DAT_060095a4 = *(int *)PTR_DAT_060095a4 + 1;
    }
  }
  else {
    *(uint *)PTR_DAT_06009598 = *(uint *)PTR_DAT_06009598 & 0xfffffffe;
    *(undefined4 *)PTR_DAT_0600959c = 0x14;
  }
  *(undefined4 *)PTR_DAT_0600959c = 0x1d;
  (*(code *)PTR_FUN_060095a8)();
  (*(code *)PTR_FUN_060095ac)();
  (*(code *)PTR_FUN_060095bc)(PTR_DAT_060095b8,PTR_DAT_060095b4,*(undefined4 *)PTR_DAT_060095b0);
  (*(code *)PTR_FUN_060095c0)();
  (*(code *)PTR_FUN_060095c4)();
  return;
}

