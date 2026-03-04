/* FUN_060201B8  0x060201B8 */


void FUN_060201b8(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  short sVar4;
  undefined *puVar5;
  
  puVar2 = PTR_DAT_06020270;
  puVar1 = PTR_DAT_0602026c;
  if ((*(ushort *)PTR_DAT_06020274 & DAT_0602026a) != 0) {
    *(undefined2 *)PTR_DAT_06020278 = 1;
  }
  puVar3 = PTR_DAT_0602027c;
  if (*(ushort *)puVar2 < 0x15) {
    sVar4 = *(short *)puVar1;
    while ((sVar4 == 0 && (sVar4 = FUN_06020e3c(0), sVar4 != 0xf))) {
      puVar5 = PTR_DAT_06020280 + (short)(sVar4 * 0x44);
      *puVar5 = (char)*(undefined2 *)(puVar3 + (uint)*(ushort *)puVar2 * 6);
      puVar5[0x40] = (char)*(undefined2 *)(puVar3 + (uint)*(ushort *)puVar2 * 6 + 4);
      *(undefined2 *)puVar1 = *(undefined2 *)(puVar3 + (uint)*(ushort *)puVar2 * 6 + 2);
      *(short *)puVar2 = *(short *)puVar2 + 1;
      sVar4 = *(short *)puVar1;
    }
  }
  *(short *)puVar1 = *(short *)puVar1 + -1;
  FUN_06020d46();
  FUN_06020284();
  return;
}

