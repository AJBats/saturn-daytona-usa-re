/* FUN_0601B6F0  0x0601B6F0 */


void FUN_0601b6f0(void)

{
  char cVar1;
  undefined *puVar2;
  byte unaff_r8;
  int unaff_r10;
  byte bVar3;
  byte unaff_r13;
  uint uVar4;
  byte local_c [4];
  byte local_8 [8];
  
  puVar2 = PTR_DAT_0601b770;
  (*(code *)PTR_FUN_0601b778)();
  (*(code *)PTR_FUN_0601b778)();
  if ((*(ushort *)(PTR_DAT_0601b780 + 2) & DAT_0601b76c) == 0) {
    if (((*(ushort *)(PTR_DAT_0601b780 + 2) & DAT_0601b76e) != 0) &&
       (cVar1 = *puVar2, *puVar2 = cVar1 + '\x01', unaff_r10 <= (char)(cVar1 + '\x01'))) {
      *puVar2 = 0;
    }
  }
  else {
    cVar1 = *puVar2;
    *puVar2 = cVar1 + -1;
    if ((char)(cVar1 + -1) < '\0') {
      *puVar2 = unaff_r13;
    }
  }
  uVar4 = 0;
  do {
    bVar3 = unaff_r13;
    if (((int)(char)*puVar2 == (uVar4 & 0xff)) && ((*(ushort *)PTR_DAT_0601b784 & 4) != 0)) {
      bVar3 = unaff_r8;
    }
    (*(code *)PTR_FUN_0601b7f0)
              (8,*(undefined4 *)(PTR_DAT_0601b7ec + ((uVar4 & 0xff) + 0x36) * 8),
               ((uint)local_c[uVar4 & 0xff] * 0x40 + (uint)local_8[uVar4 & 0xff]) * 2,
               (uint)bVar3 * 0x1000 +
               *(int *)((int)(PTR_DAT_0601b7ec + ((uVar4 & 0xff) + 0x36) * 8) + 4));
    uVar4 = uVar4 + 1;
  } while ((int)(uVar4 & 0xff) < unaff_r10);
  return;
}

