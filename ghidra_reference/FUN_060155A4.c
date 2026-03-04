/* FUN_060155A4  0x060155A4 */


void FUN_060155a4(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  byte bVar7;
  byte bVar8;
  
  puVar4 = PTR_DAT_06015674;
  puVar3 = PTR_FUN_06015670;
  puVar2 = PTR_DAT_0601566c;
  puVar1 = PTR_DAT_06015668;
  bVar7 = 0;
  do {
    if (bVar7 == 3 || bVar7 == 0) {
      uVar5 = (*(code *)puVar3)(*(undefined4 *)(puVar4 + (short)((ushort)bVar7 * 0x44) + 0x1c),
                                puVar1);
      *(undefined4 *)(puVar4 + (short)((ushort)bVar7 * 0x44) + 0x10) = uVar5;
      iVar6 = (*(code *)puVar3)(*(undefined4 *)(puVar4 + (short)((ushort)bVar7 * 0x44) + 0x1c),
                                puVar2);
      *(int *)(puVar4 + (short)((ushort)bVar7 * 0x44) + 0x14) = iVar6;
      if (iVar6 < 0) {
        *(int *)(puVar4 + (short)((ushort)bVar7 * 0x44) + 0x14) =
             -*(int *)(puVar4 + (short)((ushort)bVar7 * 0x44) + 0x14);
      }
    }
    else {
      *(undefined4 *)(puVar4 + (short)((ushort)bVar7 * 0x44) + 0x10) =
           *(undefined4 *)(puVar4 + (short)((ushort)bVar7 * 0x44) + 0x1c);
    }
    bVar8 = bVar7 + 1;
    *(int *)(puVar4 + (short)((ushort)bVar7 * 0x44) + 0x18) =
         *(int *)(puVar4 + (short)((ushort)bVar7 * 0x44) + 0x18) +
         *(int *)(puVar4 + (short)((ushort)bVar7 * 0x44) + 0x24);
    *(int *)(puVar4 + (short)((ushort)bVar7 * 0x44) + 0x1c) =
         *(int *)(puVar4 + (short)((ushort)bVar7 * 0x44) + 0x1c) +
         *(int *)(puVar4 + (short)((ushort)bVar7 * 0x44) + 0x20);
    bVar7 = bVar8;
  } while (bVar8 < 4);
  return;
}

