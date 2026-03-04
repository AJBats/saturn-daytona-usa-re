/* FUN_06023290  0x06023290 */


uint FUN_06023290(void)

{
  ushort uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  short sVar7;
  uint uVar8;
  ushort uVar9;
  
  puVar4 = PTR_DAT_060233d0;
  puVar3 = PTR_DAT_060233cc;
  puVar2 = PTR_PTR_060233c8;
  *(undefined2 *)(PTR_DAT_060233d0 + 4) = 3;
  *(undefined2 *)(puVar4 + 6) = 4;
  *(undefined2 *)(puVar4 + 8) = 5;
  *(undefined2 *)(puVar4 + 10) = 6;
  *(undefined2 *)(puVar4 + 0xc) = 7;
  *(undefined2 *)(puVar4 + 0xe) = 8;
  *(undefined2 *)(puVar4 + 0x10) = 9;
  *(undefined2 *)(puVar4 + 0x12) = 10;
  *(undefined2 *)(puVar4 + 0x14) = 0xb;
  *(undefined2 *)(puVar4 + 0x16) = 0xc;
  *(undefined2 *)(puVar4 + 0x18) = 0xd;
  *(undefined2 *)(puVar4 + 0x1a) = 0xe;
  *(undefined2 *)(puVar4 + 0x1c) = 0xf;
  *(undefined2 *)(puVar4 + 0x1e) = 0x10;
  *(undefined2 *)(puVar4 + 0x20) = 0x11;
  *(undefined2 *)(puVar4 + 0x22) = 0x12;
  *(undefined2 *)(puVar4 + 0x24) = 0x13;
  *(undefined2 *)(puVar4 + 0x26) = 0x14;
  *(undefined2 *)(puVar4 + 0x28) = 0x15;
  *(undefined2 *)(puVar4 + 0x2a) = 0x16;
  *(undefined2 *)(puVar4 + 0x2c) = 0x17;
  *(undefined2 *)(puVar4 + 0x2e) = 0x18;
  *(undefined2 *)(puVar4 + 0x30) = 0x19;
  *(undefined2 *)(puVar4 + 0x32) = 0x1a;
  *(undefined2 *)(puVar4 + 0x34) = 0x1b;
  *(undefined2 *)(puVar4 + 0x36) = 0x1c;
  *(undefined2 *)(puVar4 + 0x38) = 0x1d;
  *(undefined2 *)(puVar4 + 0x3a) = 0x1e;
  *(undefined2 *)(puVar4 + 0x3c) = 0x1f;
  *(undefined2 *)(puVar4 + 0x3e) = 0x20;
  *(undefined2 *)(puVar4 + 0x40) = 0x21;
  *(undefined2 *)(puVar4 + 0x42) = 0x22;
  *(undefined2 *)(puVar4 + 0x44) = 0x23;
  *(undefined2 *)(puVar4 + 0x46) = 0x24;
  *(undefined2 *)(puVar4 + 0x48) = 0x25;
  *(undefined2 *)(puVar4 + 0x4a) = 0x26;
  *(undefined2 *)(puVar4 + 0x4c) = 0x27;
  *(undefined2 *)(puVar4 + 0x4e) = 0x28;
  *(undefined2 *)(puVar4 + 0x50) = 0x29;
  *(undefined2 *)(puVar4 + 0x52) = 0x2a;
  *(undefined2 *)(puVar4 + 0x54) = 0x36;
  *(undefined2 *)(puVar4 + 0x56) = 0x37;
  sVar7 = 0x1e;
  uVar5 = (*(code *)PTR_FUN_06023498)
                    (*(int *)PTR_PTR_06023490 * 8 + *(int *)PTR_DAT_06023494 + (int)DAT_06023484,
                     PTR_DAT_0602348c,(int)DAT_060233c6);
  uVar8 = 0;
  while( true ) {
    if (0x14 < (uVar8 & 0xffff)) {
      return uVar5;
    }
    iVar6 = *(int *)(puVar2 + ((uVar8 & 0xff) * 0xc & 0xff));
    uVar1 = *(ushort *)((int)(puVar2 + ((uVar8 & 0xff) * 0xc & 0xff)) + 8);
    uVar5 = (uint)(short)uVar1;
    if (0x13 < (uVar8 & 0xffff)) {
      sVar7 = sVar7 + 0x36;
    }
    uVar9 = 0;
    if (uVar1 != 0) {
      do {
        if ((uVar8 & 0xffff) == 0x13) {
          if (uVar9 == 0x15) {
            *(undefined4 *)PTR_DAT_0602349c = *(undefined4 *)puVar3;
          }
          else if (uVar9 == 0x27) {
            *(undefined4 *)PTR_DAT_060234a0 = *(undefined4 *)puVar3;
          }
          else if (uVar9 == 0x40) {
            *(undefined4 *)PTR_DAT_060234a4 = *(undefined4 *)puVar3;
          }
          else if (uVar9 == 0x44) {
            *(undefined4 *)PTR_DAT_060234a8 = *(undefined4 *)puVar3;
          }
          else if ((uint)uVar9 == (int)DAT_06023486) {
            *(undefined4 *)PTR_DAT_060234ac = *(undefined4 *)puVar3;
          }
          else if ((uint)uVar9 == (int)PTR_DAT_06023488._0_2_) {
            *(undefined4 *)PTR_DAT_060234b0 = *(undefined4 *)puVar3;
          }
          else if ((uint)uVar9 == (int)DAT_0602355e) {
            *(undefined4 *)PTR_DAT_06023560 = *(undefined4 *)puVar3;
          }
        }
        uVar5 = (*(code *)PTR_FUN_06023568)(iVar6,sVar7,PTR_DAT_06023564);
        uVar9 = uVar9 + 1;
        iVar6 = iVar6 + 0xc;
      } while (uVar9 < uVar1);
    }
    iVar6 = *(int *)(puVar2 + ((uVar8 & 0xff) * 0xc & 0xff) + 4);
    if (iVar6 == 0) break;
    uVar1 = *(ushort *)(puVar2 + ((uVar8 & 0xff) * 0xc & 0xff) + 10);
    if ((uVar8 & 0xffff) == 0x13) {
      sVar7 = sVar7 + 0x53;
    }
    uVar9 = 0;
    if (uVar1 != 0) {
      do {
        (*(code *)PTR_FUN_0602356c)(iVar6,sVar7);
        uVar9 = uVar9 + 1;
        iVar6 = iVar6 + 6;
      } while (uVar9 < uVar1);
    }
    uVar5 = uVar8 & 0xffff;
    if (uVar5 == 0x14) {
      *(short *)PTR_DAT_06023570 = sVar7;
    }
    if ((uVar8 & 0xffff) < 0x13) {
      sVar7 = sVar7 + 10;
    }
    uVar8 = uVar8 + 1;
  }
  return uVar5;
}

