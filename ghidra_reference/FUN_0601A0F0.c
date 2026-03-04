/* FUN_0601A0F0  0x0601A0F0 */


void FUN_0601a0f0(void)

{
  undefined *puVar1;
  undefined *puVar2;
  char cVar3;
  
  puVar2 = PTR_DAT_0601a1a4;
  puVar1 = PTR_DAT_0601a19c;
  if ((*(ushort *)PTR_DAT_0601a198 & 1) == 0) {
    cVar3 = '\x19';
  }
  else {
    cVar3 = '\x06';
  }
  if (((uint)*(ushort *)(PTR_DAT_0601a198 + 2) & (uint)PTR_DAT_0601a1a0) == 0) {
    if ((*(ushort *)(PTR_DAT_0601a198 + 2) & DAT_0601a196) == 0) {
      if (((uint)*(ushort *)PTR_DAT_0601a198 & (uint)PTR_DAT_0601a1a0) == 0) {
        if (((*(ushort *)PTR_DAT_0601a198 & DAT_0601a196) != 0) && (*PTR_DAT_0601a1a4 == cVar3)) {
          *(int *)PTR_DAT_0601a19c = *(int *)PTR_DAT_0601a19c + -1;
          *puVar2 = 0;
        }
      }
      else if (*PTR_DAT_0601a1a4 == cVar3) {
        *(int *)PTR_DAT_0601a19c = *(int *)PTR_DAT_0601a19c + 1;
        *puVar2 = 0;
      }
    }
    else {
      *(int *)PTR_DAT_0601a19c = *(int *)PTR_DAT_0601a19c + -1;
      *puVar2 = 0;
    }
  }
  else {
    *(int *)PTR_DAT_0601a19c = *(int *)PTR_DAT_0601a19c + 1;
    *puVar2 = 0;
  }
  if (4 < *(int *)puVar1) {
    *(undefined4 *)puVar1 = 4;
  }
  if (*(int *)puVar1 < 0) {
    *(undefined4 *)puVar1 = 0;
  }
  FUN_06019fb2();
  return;
}

