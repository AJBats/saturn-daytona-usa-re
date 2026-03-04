/* FUN_0602D9F0  0x0602D9F0 */


uint * FUN_0602d9f0(void)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  
  puVar1 = *(uint **)PTR_DAT_0602dab0;
  if ((*(int *)(DAT_0602dab8 + (int)puVar1) < *(int *)PTR_DAT_0602dab4 + -1) &&
     ((((*(int *)PTR_DAT_0602dabc != DAT_0602dac0 ||
        (*(int *)(DAT_0602dac4 + (int)puVar1) < DAT_0602dac8)) &&
       (*(int *)(DAT_0602dacc + (int)puVar1) == DAT_0602dad0)) &&
      ((*(int *)((int)DAT_0602da9c + (int)puVar1) == 0 &&
        (*(short *)((int)DAT_0602da9a + (int)puVar1) == 0 &&
        *(short *)((int)DAT_0602da98 + (int)puVar1) == 0) &&
       (puVar2 = (uint *)((int)DAT_0602da9e + (int)puVar1),
       (int)DAT_0602daa0 == (puVar2[3] & puVar2[2] & puVar2[1] & *puVar2))))))) {
    puVar1 = *(uint **)PTR_DAT_0602dad4;
    iVar3 = (int)(short)((short)puVar1[10] - (short)*(undefined4 *)((int)DAT_0602daa2 + (int)puVar1)
                        ) + (int)DAT_0602daa4;
    if ((DAT_0602daa6 < iVar3) && (iVar3 <= DAT_0602daa8)) {
      if (((DAT_0602dad8 & *puVar1) != 0) || (*PTR_DAT_0602dadc != '\0')) {
        *PTR_DAT_0602daf8 = (char)DAT_0602dafc;
        return puVar1;
      }
      *puVar1 = *puVar1 | (uint)PTR_DAT_0602dae0;
      *(int *)PTR_DAT_0602dae4 = (int)DAT_0602daaa;
      *(int *)PTR_DAT_0602dae8 = (int)PTR_DAT_0602daac._0_2_;
    }
  }
  *PTR_DAT_0602dadc = (char)DAT_0602dad0;
  return puVar1;
}

