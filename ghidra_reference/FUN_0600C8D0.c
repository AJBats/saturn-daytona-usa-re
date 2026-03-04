/* FUN_0600C8D0  0x0600C8D0 */


int FUN_0600c8d0(undefined4 param_1,int *param_2)

{
  int iVar1;
  short sVar2;
  int unaff_r14;
  
  iVar1 = (*(code *)PTR_FUN_0600c968)
                    (*param_2 - *(int *)(unaff_r14 + 0x10),param_2[2] - *(int *)(unaff_r14 + 0x18));
  sVar2 = (short)-iVar1 - (short)*(undefined4 *)(unaff_r14 + 0x28);
  if (DAT_0600c962 < sVar2) {
    *(int *)(unaff_r14 + 0x28) =
         (int)(short)((short)*(undefined4 *)(unaff_r14 + 0x28) + DAT_0600c962);
  }
  else if (sVar2 < DAT_0600c964) {
    *(int *)(unaff_r14 + 0x28) =
         (int)(short)((short)*(undefined4 *)(unaff_r14 + 0x28) + (short)PTR_DAT_0600c96c);
  }
  else {
    *(int *)(unaff_r14 + 0x28) = -iVar1;
  }
  return iVar1;
}

