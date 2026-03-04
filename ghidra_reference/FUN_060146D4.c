/* FUN_060146D4  0x060146D4 */


uint FUN_060146d4(void)

{
  undefined *puVar1;
  char cVar3;
  uint uVar2;
  undefined4 in_r3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  *(undefined4 *)PTR_DAT_060146f8 = in_r3;
  cVar3 = FUN_0601476c(PTR_DAT_060146fc);
  if (cVar3 == '\0') {
    *PTR_DAT_06014758 = 4;
  }
  else {
    *PTR_DAT_06014700 = 6;
  }
  puVar1 = PTR_DAT_06014764;
  uVar2 = *(uint *)PTR_DAT_0601475c;
  if ((uVar2 & 1) == 0) {
    puVar4 = *(undefined1 **)PTR_DAT_06014760;
    if (puVar4 != (undefined1 *)0x0) {
      puVar5 = PTR_DAT_06014764 + 1;
      *puVar4 = *PTR_DAT_06014764;
      puVar4[1] = *puVar5;
      puVar4[2] = puVar1[2];
      puVar4[3] = puVar1[3];
    }
    puVar1 = PTR_DAT_06014764;
    puVar4 = *(undefined1 **)PTR_DAT_06014768;
    if (puVar4 != (undefined1 *)0x0) {
      puVar5 = PTR_DAT_06014764 + 1;
      *puVar4 = *PTR_DAT_06014764;
      puVar4[1] = *puVar5;
      puVar4[2] = puVar1[2];
      puVar4[3] = puVar1[3];
    }
  }
  return uVar2;
}

