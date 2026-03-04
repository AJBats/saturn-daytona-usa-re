/* FUN_06012454  0x06012454 */


void FUN_06012454(void)

{
  int iVar1;
  undefined4 *unaff_r14;
  
  (*(code *)PTR_FUN_060124d4)();
  (*(code *)PTR_FUN_060124d8)();
  (*(code *)PTR_FUN_060124dc)(*unaff_r14,unaff_r14[1],unaff_r14[2]);
  iVar1 = (*(code *)PTR_FUN_060124e0)();
  (*(code *)PTR_FUN_060124e4)(iVar1 * 0xc000 + (int)DAT_060124d2);
  (*(code *)PTR_FUN_060124f4)
            (*(undefined4 *)(PTR_PTR_060124f0 + (*(int *)PTR_DAT_060124ec + -1) * 4),
             *(undefined4 *)PTR_DAT_060124e8);
  (*(code *)PTR_FUN_06012504)
            (*(undefined4 *)(PTR_PTR_06012500 + (*(int *)PTR_DAT_060124ec + -1) * 4),
             (int)*(short *)PTR_DAT_060124fc,*(undefined4 *)PTR_DAT_060124f8);
  (*(code *)PTR_FUN_06012508)();
  return;
}

