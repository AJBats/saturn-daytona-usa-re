/* FUN_0600A478  0x0600A478 */


void FUN_0600a478(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int unaff_r14;
  int iVar1;
  
  iVar1 = unaff_r14 * 4;
  (*(code *)PTR_FUN_0600a514)
            (*(undefined4 *)(PTR_PTR_0600a510 + iVar1),*(undefined4 *)(PTR_DAT_0600a50c + iVar1),
             param_3,param_4,param_1);
  (*(code *)PTR_FUN_0600a524)
            (*(undefined4 *)(PTR_PTR_0600a520 + iVar1),(int)*(short *)PTR_DAT_0600a51c,
             *(undefined4 *)(PTR_DAT_0600a518 + iVar1));
  return;
}

