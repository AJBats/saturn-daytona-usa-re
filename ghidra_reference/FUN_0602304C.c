/* FUN_0602304C  0x0602304C */


void FUN_0602304c(void)

{
  undefined *puVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar5;
  int iVar4;
  short sVar6;
  
  puVar1 = PTR_DAT_06023188;
  *(undefined2 *)(PTR_DAT_06023188 + 4) = 3;
  *(undefined2 *)(puVar1 + 6) = 4;
  *(undefined2 *)(puVar1 + 8) = 5;
  *(undefined2 *)(puVar1 + 10) = 6;
  *(undefined2 *)(puVar1 + 0xc) = 7;
  *(undefined2 *)(puVar1 + 0xe) = 8;
  *(undefined2 *)(puVar1 + 0x10) = 9;
  *(undefined2 *)(puVar1 + 0x12) = 10;
  *(undefined2 *)(puVar1 + 0x14) = 0xb;
  *(undefined2 *)(puVar1 + 0x16) = 0xc;
  *(undefined2 *)(puVar1 + 0x18) = 0xd;
  *(undefined2 *)(puVar1 + 0x1a) = 0xe;
  *(undefined2 *)(puVar1 + 0x1c) = 0xf;
  *(undefined2 *)(puVar1 + 0x1e) = 0x10;
  *(undefined2 *)(puVar1 + 0x20) = 0x11;
  *(undefined2 *)(puVar1 + 0x22) = 0x12;
  *(undefined2 *)(puVar1 + 0x24) = 0x13;
  *(undefined2 *)(puVar1 + 0x26) = 0x14;
  *(undefined2 *)(puVar1 + 0x28) = 0x15;
  *(undefined2 *)(puVar1 + 0x2a) = 0x16;
  *(undefined2 *)(puVar1 + 0x2c) = 0x17;
  *(undefined2 *)(puVar1 + 0x2e) = 0x18;
  *(undefined2 *)(puVar1 + 0x30) = 0x19;
  *(undefined2 *)(puVar1 + 0x32) = 0x1a;
  *(undefined2 *)(puVar1 + 0x34) = 0x1b;
  *(undefined2 *)(puVar1 + 0x36) = 0x1c;
  *(undefined2 *)(puVar1 + 0x38) = 0x1d;
  *(undefined2 *)(puVar1 + 0x3a) = 0x1e;
  *(undefined2 *)(puVar1 + 0x3c) = 0x1f;
  *(undefined2 *)(puVar1 + 0x3e) = 0x20;
  *(undefined2 *)(puVar1 + 0x40) = 0x21;
  *(undefined2 *)(puVar1 + 0x42) = 0x22;
  *(undefined2 *)(puVar1 + 0x44) = 0x23;
  *(undefined2 *)(puVar1 + 0x46) = 0x24;
  *(undefined2 *)(puVar1 + 0x48) = 0x25;
  *(undefined2 *)(puVar1 + 0x4a) = 0x26;
  *(undefined2 *)(puVar1 + 0x4c) = 0x27;
  *(undefined2 *)(puVar1 + 0x4e) = 0x28;
  *(undefined2 *)(puVar1 + 0x50) = 0x29;
  *(undefined2 *)(puVar1 + 0x52) = 0x2a;
  *(undefined2 *)(puVar1 + 0x54) = 0x36;
  *(undefined2 *)(puVar1 + 0x56) = 0x37;
  puVar1 = PTR_DAT_0602318c;
  sVar6 = 0x1e;
  (*(code *)PTR_FUN_06023278)
            (*(int *)PTR_PTR_06023190 * 8 + *(int *)PTR_DAT_06023274 + (int)DAT_06023272,
             PTR_DAT_0602318c,(int)DAT_06023184);
  for (uVar5 = 0; uVar5 < 0x28; uVar5 = uVar5 + 1) {
    iVar4 = *(int *)(PTR_PTR_0602327c + (short)(uVar5 * 0xc));
    uVar3 = *(ushort *)((int)(PTR_PTR_0602327c + (short)(uVar5 * 0xc)) + 8);
    uVar2 = 0;
    if (uVar3 != 0) {
      do {
        (*(code *)PTR_FUN_06023280)(iVar4,sVar6,puVar1);
        uVar2 = uVar2 + 1;
        iVar4 = iVar4 + 0xc;
      } while (uVar2 < uVar3);
    }
    uVar3 = *(ushort *)(PTR_PTR_0602327c + (short)(uVar5 * 0xc) + 10);
    iVar4 = *(int *)(PTR_PTR_0602327c + (short)(uVar5 * 0xc) + 4);
    if (uVar5 == 0x27) {
      sVar6 = sVar6 + 0x2f;
    }
    uVar2 = 0;
    if (uVar3 != 0) {
      do {
        (*(code *)PTR_FUN_06023284)(iVar4,sVar6);
        uVar2 = uVar2 + 1;
        iVar4 = iVar4 + 6;
      } while (uVar2 < uVar3);
    }
    if (uVar5 < 0x27) {
      sVar6 = sVar6 + 10;
    }
  }
  iVar4 = *(int *)PTR_PTR_06023288;
  uVar5 = *(ushort *)(PTR_PTR_06023288 + 8);
  *(short *)PTR_DAT_0602328c = sVar6 + 0x15;
  uVar3 = 0;
  if (uVar5 != 0) {
    do {
      (*(code *)PTR_FUN_06023280)(iVar4,sVar6 + 0x15,puVar1);
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 0xc;
    } while (uVar3 < uVar5);
  }
  return;
}

