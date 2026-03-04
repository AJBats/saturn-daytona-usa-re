/* FUN_060114B8  0x060114B8 */


uint FUN_060114b8(void)

{
  undefined *puVar1;
  int in_r0;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  short *psVar5;
  uint unaff_r13;
  
  puVar1 = PTR_DAT_06011504;
  iVar3 = *(int *)(PTR_DAT_060114fc + *(int *)PTR_DAT_06011500 * 4 + in_r0 * 0x10) -
          *(int *)PTR_DAT_06011504;
  *(int *)PTR_DAT_06011504 = *(int *)PTR_DAT_06011504 + ((int)(iVar3 + (uint)(iVar3 < 0)) >> 1);
  if (((*PTR_DAT_06011508 == '\x03') || (*PTR_DAT_06011508 == '\v')) &&
     ((*(uint *)PTR_DAT_0601150c & 1) != 0)) {
    return *(uint *)PTR_DAT_0601150c;
  }
  psVar5 = (short *)(PTR_DAT_060115c8 + (unaff_r13 & 0xffff) * 2);
  puVar4 = (undefined4 *)(PTR_DAT_060115d0 + (unaff_r13 & 0xffff) * 0x10 + 0xc);
  FUN_060116a8(*(undefined4 *)puVar1,*puVar4,(int)DAT_060115c6,PTR_DAT_060115cc,(int)*psVar5);
  FUN_06011978(PTR_DAT_060115d4,*(undefined4 *)puVar1,*puVar4,(int)*psVar5);
  uVar2 = FUN_06011978(PTR_PTR_060115d8,*(undefined4 *)puVar1,*puVar4,(int)*psVar5);
  return uVar2;
}

