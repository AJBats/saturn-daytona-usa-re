/* FUN_0601FD9C  0x0601FD9C */


undefined4 FUN_0601fd9c(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((*(uint *)PTR_DAT_0601fe04 & (uint)PTR_DAT_0601fe08) == 0) {
    puVar2 = *(undefined4 **)(PTR_PTR_0601fe14 + *(int *)PTR_DAT_0601fe0c * 4);
  }
  else {
    puVar2 = *(undefined4 **)(PTR_PTR_0601fe10 + *(int *)PTR_DAT_0601fe0c * 4);
  }
  *(undefined4 **)PTR_DAT_0601fe00 = puVar2;
  *(undefined4 *)PTR_DAT_0601fe18 = *puVar2;
  FUN_0601fe20();
  if (*(int *)PTR_DAT_0601fe1c == 0x16 || *(int *)PTR_DAT_0601fe1c == 0x17) {
    uVar1 = FUN_060200a4();
    return uVar1;
  }
  return 0;
}

