/* FUN_06007268  0x06007268 */


uint FUN_06007268(void)

{
  undefined *puVar1;
  uint uVar2;
  
  *(int *)PTR_DAT_060072c0 = *(int *)PTR_DAT_060072c0 + 1;
  *(undefined4 *)PTR_DAT_060072c4 = 3;
  uVar2 = (*(code *)PTR_FUN_060072c8)();
  puVar1 = PTR_DAT_060072d4;
  if (((int)(uint)(byte)PTR_PTR_060072d0[*(int *)PTR_DAT_060072cc] <= *(int *)PTR_DAT_060072c0) &&
     (uVar2 = 0, *(int *)PTR_DAT_060072d4 != 0)) {
    uVar2 = *(ushort *)PTR_DAT_060072d8 | 3;
    *(short *)PTR_VDP1_FBCR_060072dc = (short)uVar2;
    *(undefined4 *)PTR_DAT_060072e0 = 0;
    *(undefined4 *)puVar1 = 0;
  }
  *(undefined4 *)PTR_DAT_060072c4 = 4;
  return uVar2;
}

