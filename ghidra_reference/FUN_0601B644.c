/* FUN_0601B644  0x0601B644 */


void FUN_0601b644(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_0601b6d0;
  puVar1 = PTR_DAT_0601b6cc;
  if ((*(ushort *)(PTR_DAT_0601b6d4 + 2) & DAT_0601b6c4) == 0) {
    if ((*(ushort *)(PTR_DAT_0601b6d4 + 2) & DAT_0601b6c6) != 0) {
      *PTR_DAT_0601b6d0 = *PTR_DAT_0601b6d0 + '\x05';
      if ('\x13' < (char)*puVar2) {
        *puVar2 = 0;
      }
      FUN_0601ba50((int)(char)*puVar1,(int)(char)puVar1[1],(int)(char)*puVar2);
      return;
    }
    if ((*(ushort *)(PTR_DAT_0601b6d4 + 2) & DAT_0601b6c8) != 0) {
      *PTR_DAT_0601b6d0 = *PTR_DAT_0601b6d0 + -5;
      if ((char)*puVar2 < '\0') {
        *puVar2 = 0xf;
      }
      FUN_0601ba50((int)(char)*puVar1,(int)(char)puVar1[1],(int)(char)*puVar2);
      return;
    }
  }
  else {
    *PTR_DAT_0601b6d8 = 0;
  }
  return;
}

