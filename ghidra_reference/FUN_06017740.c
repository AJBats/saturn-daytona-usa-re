/* FUN_06017740  0x06017740 */


void FUN_06017740(void)

{
  undefined *puVar1;
  undefined *puVar2;
  byte unaff_r12;
  int unaff_r13;
  byte bVar3;
  
  puVar2 = PTR_DAT_060177ac;
  puVar1 = PTR_FUN_060177a8;
  bVar3 = 0;
  if (unaff_r12 != 0) {
    do {
      (*(code *)puVar1)(0xc,puVar2 + (short)((ushort)bVar3 * 0x36),(unaff_r13 + 0x40) * 2,0);
      bVar3 = bVar3 + 1;
      unaff_r13 = unaff_r13 + 1;
    } while (bVar3 < unaff_r12);
  }
  return;
}

