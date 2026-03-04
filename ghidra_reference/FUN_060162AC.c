/* FUN_060162AC  0x060162AC */


void FUN_060162ac(void)

{
  int *piVar1;
  undefined *puVar2;
  undefined4 uVar3;
  short in_r3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  char unaff_r10;
  char unaff_r11;
  short unaff_r12;
  short sVar7;
  byte unaff_r14;
  
  puVar2 = PTR_DAT_06016354;
  sVar7 = unaff_r12 * 4 + in_r3 * 0x40;
  piVar1 = (int *)(PTR_DAT_06016354 + sVar7 + 0x10);
  iVar4 = *(int *)(PTR_DAT_06016354 + sVar7 + 4);
  *(int *)(PTR_DAT_06016354 + sVar7 + 4) = iVar4 + *piVar1;
  iVar4 = (*(code *)PTR_FUN_06016358)((iVar4 + *piVar1) - *(int *)(puVar2 + sVar7 + 0x34));
  if (*PTR_PTR_0601635c == '\0' && iVar4 <= *(int *)(puVar2 + sVar7 + 0x24)) {
    *PTR_PTR_0601635c = unaff_r10;
    puVar6 = puVar2 + (short)((ushort)unaff_r14 * 0x44);
    *(undefined4 *)(puVar6 + 4) = *(undefined4 *)(puVar6 + 0x20);
    uVar3 = (*(code *)PTR_FUN_06016360)();
    *(undefined4 *)(puVar6 + 0x10) = uVar3;
  }
  if (unaff_r14 < 4 &&
      *(int *)(puVar2 + (short)((ushort)unaff_r14 * 0x44) + 4) <=
      *(int *)(puVar2 + (short)((ushort)unaff_r14 * 0x44) + 0x34)) {
    *(undefined4 *)(puVar2 + (short)((ushort)unaff_r14 * 0x44) + 4) =
         *(undefined4 *)(puVar2 + (short)((ushort)unaff_r14 * 0x44) + 0x34);
    unaff_r11 = unaff_r10;
  }
  else if (*(int *)(puVar2 + (short)((ushort)unaff_r14 * 0x44) + 0x34) <=
           *(int *)(puVar2 + (short)((ushort)unaff_r14 * 0x44) + 4) && 3 < unaff_r14) {
    *(undefined4 *)(puVar2 + (short)((ushort)unaff_r14 * 0x44) + 4) =
         *(undefined4 *)(puVar2 + (short)((ushort)unaff_r14 * 0x44) + 0x34);
    unaff_r11 = unaff_r10;
  }
  if ((*PTR_DAT_0601645c != '\0') &&
     (iVar4 = (int)DAT_0601645a, iVar5 = *(int *)(puVar2 + (short)((ushort)unaff_r14 * 0x44) + 0x30)
     , *(int *)(puVar2 + (short)((ushort)unaff_r14 * 0x44) + 0x30) = iVar5 + iVar4,
     -1 < iVar5 + iVar4)) {
    *(undefined4 *)(puVar2 + (short)((ushort)unaff_r14 * 0x44) + 0x30) = 0;
  }
  FUN_06016dd8(unaff_r14);
  if (unaff_r11 != '\0') {
    puVar2[(short)((ushort)unaff_r14 * 0x44) + 2] = 7;
  }
  return;
}

