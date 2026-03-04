/* FUN_0601198C  0x0601198C */


void FUN_0601198c(void)

{
  short sVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined2 uVar5;
  undefined2 in_r7;
  undefined2 *puVar6;
  int unaff_r9;
  int unaff_r10;
  int *unaff_r11;
  
  puVar4 = PTR_DAT_06011af0;
  puVar3 = PTR_DAT_06011aec;
  puVar2 = PTR_FUN_06011ae8;
  puVar6 = (undefined2 *)(PTR_DAT_06011aec + (short)(*(short *)PTR_DAT_06011af0 * 0x18) + 8);
  uVar5 = (*(code *)PTR_FUN_06011ae8)(*unaff_r11 + unaff_r10);
  *puVar6 = uVar5;
  sVar1 = *(short *)puVar4;
  uVar5 = (*(code *)puVar2)(unaff_r11[1] + unaff_r9);
  *(undefined2 *)(puVar3 + (short)(sVar1 * 0x18) + 10) = uVar5;
  sVar1 = *(short *)puVar4;
  uVar5 = (*(code *)puVar2)(unaff_r11[2] + unaff_r10);
  *(undefined2 *)(puVar3 + (short)(sVar1 * 0x18) + 0xc) = uVar5;
  sVar1 = *(short *)puVar4;
  uVar5 = (*(code *)puVar2)(unaff_r11[3] + unaff_r9);
  *(undefined2 *)(puVar3 + (short)(sVar1 * 0x18) + 0xe) = uVar5;
  sVar1 = *(short *)puVar4;
  uVar5 = (*(code *)puVar2)(unaff_r11[4] + unaff_r10);
  *(undefined2 *)(puVar3 + (short)(sVar1 * 0x18) + 0x10) = uVar5;
  sVar1 = *(short *)puVar4;
  uVar5 = (*(code *)puVar2)(unaff_r11[5] + unaff_r9);
  *(undefined2 *)(puVar3 + (short)(sVar1 * 0x18) + 0x12) = uVar5;
  sVar1 = *(short *)puVar4;
  uVar5 = (*(code *)puVar2)(unaff_r11[6] + unaff_r10);
  *(undefined2 *)(puVar3 + (short)(sVar1 * 0x18) + 0x14) = uVar5;
  sVar1 = *(short *)puVar4;
  uVar5 = (*(code *)puVar2)(unaff_r11[7] + unaff_r9);
  *(undefined2 *)(puVar3 + (short)(sVar1 * 0x18) + 0x16) = uVar5;
  *(undefined2 *)(puVar3 + (short)(*(short *)puVar4 * 0x18) + 6) = in_r7;
  puVar3[(short)(*(short *)puVar4 * 0x18) + 4] = 0;
  puVar3[(short)(*(short *)puVar4 * 0x18) + 5] = 1;
  *(short *)puVar4 = *(short *)puVar4 + 1;
  return;
}

