/* FUN_0601A7AC  0x0601A7AC */


void FUN_0601a7ac(void)

{
  if ((*(ushort *)(PTR_DAT_0601a804 + 2) & DAT_0601a7e2) == 0) {
    if (((uint)*(ushort *)(PTR_DAT_0601a804 + 2) & (uint)PTR_DAT_0601a808) != 0) {
      *PTR_DAT_0601a800 = 1;
    }
  }
  else {
    *PTR_DAT_0601a800 = 0;
  }
  FUN_0601a65e();
  FUN_0601a73e();
  return;
}

