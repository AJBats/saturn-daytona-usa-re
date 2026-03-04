/* FUN_06039050  0x06039050 */


ushort FUN_06039050(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  ushort uVar4;
  
  puVar3 = PTR_DAT_06039098;
  puVar2 = PTR_DAT_06039094;
  puVar1 = PTR_VDP1_FBCR_06039090;
  if (*(short *)PTR_DAT_0603909c == 0) {
    uVar4 = 0;
    if (*(int *)PTR_DAT_06039098 != 0) {
      if ((*(int *)PTR_DAT_06039098 == 2) && (*(int *)PTR_DAT_060390ec != 0)) {
        (*(code *)PTR_FUN_060390f0)();
      }
      if (*(int *)puVar3 == 3) {
        *(undefined2 *)PTR_VDP1_TVMR_060390f8 = *(undefined2 *)PTR_DAT_060390f4;
        uVar4 = 3;
      }
      else {
        uVar4 = *(ushort *)puVar2 | 3;
        *(ushort *)puVar1 = uVar4;
      }
      *(undefined4 *)PTR_DAT_060390fc = 0;
      *(undefined4 *)puVar3 = 0;
    }
  }
  else {
    if ((*(ushort *)PTR_VDP2_TVSTAT_060390a0 & 2) == 0) {
      uVar4 = *(ushort *)PTR_DAT_06039094 | 8;
    }
    else {
      uVar4 = *(ushort *)PTR_DAT_06039094 | 0xc;
    }
    *(ushort *)PTR_VDP1_FBCR_06039090 = uVar4;
  }
  return uVar4;
}

