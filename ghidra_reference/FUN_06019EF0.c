/* FUN_06019EF0  0x06019EF0 */


void FUN_06019ef0(void)

{
  undefined *puVar1;
  undefined *puVar2;
  char cVar3;
  
  puVar2 = PTR_DAT_06019f58;
  puVar1 = PTR_DAT_06019f50;
  if ((*(ushort *)PTR_DAT_06019f4c & 1) == 0) {
    cVar3 = '\x19';
  }
  else {
    cVar3 = '\x06';
  }
  if (((uint)*(ushort *)(PTR_DAT_06019f4c + 2) & (uint)PTR_DAT_06019f54) == 0) {
    if ((*(ushort *)(PTR_DAT_06019f4c + 2) & DAT_06019f40) == 0) {
      if (((uint)*(ushort *)PTR_DAT_06019f4c & (uint)PTR_DAT_06019f54) == 0) {
        if (((*(ushort *)PTR_DAT_06019f4c & DAT_06019f40) != 0) && (*PTR_DAT_06019f58 == cVar3)) {
          *(int *)PTR_DAT_06019f50 = *(int *)PTR_DAT_06019f50 + -1;
          *puVar2 = 0;
        }
      }
      else if (*PTR_DAT_06019f58 == cVar3) {
        *(int *)PTR_DAT_06019f50 = *(int *)PTR_DAT_06019f50 + 1;
        *puVar2 = 0;
      }
    }
    else {
      *(int *)PTR_DAT_06019f50 = *(int *)PTR_DAT_06019f50 + -1;
      *puVar2 = 0;
    }
  }
  else {
    *(int *)PTR_DAT_06019f50 = *(int *)PTR_DAT_06019f50 + 1;
    *puVar2 = 0;
  }
  if (4 < *(int *)puVar1) {
    *(undefined4 *)puVar1 = 4;
  }
  if (*(int *)puVar1 < 0) {
    *(undefined4 *)puVar1 = 0;
  }
  FUN_06019db8();
  return;
}

