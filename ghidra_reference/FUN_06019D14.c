/* FUN_06019D14  0x06019D14 */


void FUN_06019d14(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_06019db4;
  puVar1 = PTR_DAT_06019da8;
  if (((uint)*(ushort *)(PTR_DAT_06019db0 + 2) & (uint)PTR_DAT_06019dac) == 0) {
    if ((*(ushort *)(PTR_DAT_06019db0 + 2) & DAT_06019da6) == 0) {
      if (((uint)*(ushort *)PTR_DAT_06019db0 & (uint)PTR_DAT_06019dac) == 0) {
        if (((*(ushort *)PTR_DAT_06019db0 & DAT_06019da6) != 0) && (*PTR_DAT_06019db4 == '\x19')) {
          *(int *)PTR_DAT_06019da8 = *(int *)PTR_DAT_06019da8 + -1;
          *puVar2 = 0;
        }
      }
      else if (*PTR_DAT_06019db4 == '\x19') {
        *(int *)PTR_DAT_06019da8 = *(int *)PTR_DAT_06019da8 + 1;
        *puVar2 = 0;
      }
    }
    else {
      *(int *)PTR_DAT_06019da8 = *(int *)PTR_DAT_06019da8 + -1;
      *puVar2 = 0;
    }
  }
  else {
    *(int *)PTR_DAT_06019da8 = *(int *)PTR_DAT_06019da8 + 1;
    *puVar2 = 0;
  }
  if (2 < *(int *)puVar1) {
    *(undefined4 *)puVar1 = 0;
  }
  if (*(int *)puVar1 < 0) {
    *(undefined4 *)puVar1 = 2;
  }
  FUN_06019bc8();
  return;
}

