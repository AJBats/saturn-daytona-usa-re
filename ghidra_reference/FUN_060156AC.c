/* FUN_060156AC  0x060156AC */


void FUN_060156ac(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  byte unaff_r13;
  byte abStack_8 [8];
  
  (*(code *)PTR_FUN_0601573c)();
  puVar1 = PTR_DAT_06015730;
  puVar3 = (undefined4 *)(PTR_PTR_06015740 + (uint)unaff_r13 * 0x10);
  *(undefined4 *)(PTR_DAT_06015730 + (short)((ushort)unaff_r13 * 0x44) + 4) = *puVar3;
  *(undefined4 *)(puVar1 + (short)((ushort)unaff_r13 * 0x44) + 8) = puVar3[1];
  *(undefined4 *)(puVar1 + (short)((ushort)unaff_r13 * 0x44) + 0xc) = puVar3[2];
  *(undefined4 *)(puVar1 + (short)((ushort)unaff_r13 * 0x44) + 0x34) = puVar3[3];
  (*(code *)PTR_FUN_06015744)(unaff_r13);
  puVar2 = PTR_DAT_06015748;
  *(ushort *)(PTR_DAT_06015748 + (short)((ushort)unaff_r13 * 0x18) + 6) =
       (ushort)abStack_8[unaff_r13];
  puVar2[(short)((ushort)unaff_r13 * 0x18) + 4] = 1;
  puVar2[(short)((ushort)unaff_r13 * 0x18) + 5] = 0x3a;
  puVar1[(short)((ushort)unaff_r13 * 0x44) + 0x41] = 0x3c;
  puVar1[(short)((ushort)unaff_r13 * 0x44) + 2] =
       puVar1[(short)((ushort)unaff_r13 * 0x44) + 2] + '\x01';
  return;
}

