/* FUN_06023584  0x06023584 */


void FUN_06023584(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int unaff_r9;
  int iVar4;
  int iVar5;
  short sVar6;
  ushort uVar7;
  ushort uVar8;
  ushort local_4 [2];
  
  puVar1 = PTR_DAT_060236b0;
  iVar3 = (int)DAT_060236ac;
  (*(code *)PTR_FUN_060236b8)();
  puVar2 = PTR_DAT_060236bc;
  *(undefined2 *)(PTR_DAT_060236bc + 4) = 3;
  *(undefined2 *)(puVar2 + 6) = 4;
  *(undefined2 *)(puVar2 + 8) = 5;
  *(undefined2 *)(puVar2 + 10) = 6;
  *(undefined2 *)(puVar2 + 0xc) = 7;
  *(undefined2 *)(puVar2 + 0xe) = 8;
  *(undefined2 *)(puVar2 + 0x10) = 9;
  *(undefined2 *)(puVar2 + 0x12) = 10;
  *(undefined2 *)(puVar2 + 0x14) = 0xb;
  *(undefined2 *)(puVar2 + 0x16) = 0xc;
  *(undefined2 *)(puVar2 + 0x18) = 0xd;
  *(undefined2 *)(puVar2 + 0x1a) = 0xe;
  *(undefined2 *)(puVar2 + 0x1c) = 0xf;
  *(undefined2 *)(puVar2 + 0x1e) = 0x10;
  *(undefined2 *)(puVar2 + 0x20) = 0x11;
  *(undefined2 *)(puVar2 + 0x22) = 0x12;
  *(undefined2 *)(puVar2 + 0x24) = 0x13;
  *(undefined2 *)(puVar2 + 0x26) = 0x14;
  *(undefined2 *)(puVar2 + 0x28) = 0x15;
  *(undefined2 *)(puVar2 + 0x2a) = 0x16;
  *(undefined2 *)(puVar2 + 0x2c) = 0x17;
  *(undefined2 *)(puVar2 + 0x2e) = 0x18;
  *(undefined2 *)(puVar2 + 0x30) = 0x19;
  *(undefined2 *)(puVar2 + 0x32) = 0x1a;
  *(undefined2 *)(puVar2 + 0x34) = 0x1b;
  *(undefined2 *)(puVar2 + 0x36) = 0x1c;
  *(short *)(puVar2 + 0x38) = (short)unaff_r9;
  *(undefined2 *)(puVar2 + 0x3a) = 0x1e;
  *(undefined2 *)(puVar2 + 0x3c) = 0x1f;
  *(undefined2 *)(puVar2 + 0x3e) = 0x20;
  *(undefined2 *)(puVar2 + 0x40) = 0x21;
  *(undefined2 *)(puVar2 + 0x42) = 0x22;
  *(undefined2 *)(puVar2 + 0x44) = 0x23;
  *(undefined2 *)(puVar2 + 0x46) = 0x24;
  *(undefined2 *)(puVar2 + 0x48) = 0x25;
  *(undefined2 *)(puVar2 + 0x4a) = 0x26;
  *(undefined2 *)(puVar2 + 0x4c) = 0x27;
  *(undefined2 *)(puVar2 + 0x4e) = 0x28;
  *(undefined2 *)(puVar2 + 0x50) = 0x29;
  *(undefined2 *)(puVar2 + 0x52) = 0x2a;
  sVar6 = 0x1e;
  *(undefined2 *)(puVar2 + 0x54) = 0x36;
  *(undefined2 *)(puVar2 + 0x56) = 0x37;
  *(undefined **)(&stack0x00000000 + iVar3) = PTR_DAT_06023748;
  (*(code *)PTR_FUN_06023754)
            (*(int *)PTR_PTR_0602374c * 8 + *(int *)PTR_DAT_06023750 + (int)DAT_06023746,
             PTR_DAT_06023748,(int)DAT_06023744);
  uVar8 = 0;
  do {
    if (0x20 < uVar8) {
      return;
    }
    iVar4 = *(int *)(&stack0x00000004 + (short)(uVar8 * 0xc) + iVar3);
    *(undefined2 *)((int)local_4 + iVar3) =
         *(undefined2 *)((int)(&stack0x00000004 + (short)(uVar8 * 0xc) + iVar3) + 8);
    uVar7 = 0;
    if (*(short *)((int)local_4 + iVar3) != 0) {
      do {
        if (iVar4 == 0) break;
        if (uVar8 == 0x1d) {
          if (uVar7 == 0x17) {
            *(undefined4 *)PTR_DAT_06023758 = *(undefined4 *)puVar1;
          }
          else if (uVar7 == 0x3a) {
            *(undefined4 *)PTR_DAT_0602375c = *(undefined4 *)puVar1;
          }
          else if ((uint)uVar7 == (int)DAT_06023814) {
            *(undefined4 *)PTR_DAT_06023818 = *(undefined4 *)puVar1;
          }
        }
        (*(code *)PTR_FUN_0602381c)(iVar4,sVar6,*(undefined4 *)(&stack0x00000000 + iVar3));
        uVar7 = uVar7 + 1;
        iVar4 = iVar4 + 0xc;
      } while (uVar7 < *(ushort *)((int)local_4 + iVar3));
    }
    iVar4 = (short)(uVar8 * 0xc) + iVar3;
    iVar5 = *(int *)(&stack0x00000008 + iVar4);
    *(undefined2 *)((int)local_4 + iVar3) = *(undefined2 *)(&stack0x0000000e + iVar4);
    if (unaff_r9 <= (int)(uint)uVar8) {
      sVar6 = sVar6 + *(short *)(PTR_PTR_06023820 + (uVar8 - 0x1d) * 2);
    }
    uVar7 = 0;
    if (*(short *)((int)local_4 + iVar3) != 0) {
      do {
        (*(code *)PTR_FUN_06023824)(iVar5,sVar6);
        uVar7 = uVar7 + 1;
        iVar5 = iVar5 + 6;
      } while (uVar7 < *(ushort *)((int)local_4 + iVar3));
    }
    if (uVar8 == 0x20) {
      *(short *)PTR_DAT_06023828 = sVar6;
    }
    if (uVar8 == 0x1f) {
      sVar6 = sVar6 + 0x2a;
    }
    if ((int)(uint)uVar8 < unaff_r9) {
      sVar6 = sVar6 + 10;
    }
    uVar8 = uVar8 + 1;
  } while( true );
}

