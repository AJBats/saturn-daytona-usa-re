/* FUN_0602DC68  0x0602DC68 */


int FUN_0602dc68(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  code *unaff_r13;
  
  (*unaff_r13)();
  *PTR_DAT_0602dca8 = (char)DAT_0602dcac;
  piVar2 = (int *)(PTR_DAT_0602dcb0 + DAT_0602dcb4);
  iVar1 = *(int *)(PTR_DAT_0602dcbc + *(int *)PTR_DAT_0602dcb8 * 4);
  if ((*piVar2 < iVar1) && (iVar3 = *piVar2 + DAT_0602dcc0, iVar3 < iVar1)) {
    *piVar2 = iVar3;
  }
  else {
    *piVar2 = iVar1;
  }
  iVar1 = *(int *)PTR_DAT_0602dcec;
  if (*(int *)(DAT_0602dcf0 + iVar1) == DAT_0602dcf4) {
    *PTR_DAT_0602dcf8 = (char)DAT_0602dcfc;
    *PTR_DAT_0602dd00 = (char)DAT_0602dd04;
    *(undefined4 *)PTR_DAT_0602dd08 = DAT_0602dd0c;
  }
  return iVar1;
}

