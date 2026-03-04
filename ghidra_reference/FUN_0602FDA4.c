/* FUN_0602FDA4  0x0602FDA4 */


void FUN_0602fda4(void)

{
  ushort uVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  byte *pbVar5;
  int iVar6;
  short sVar9;
  int iVar7;
  uint uVar8;
  int iVar10;
  byte bVar11;
  byte bVar12;
  int unaff_r14;
  
  puVar3 = PTR_DAT_060300fc;
  iVar4 = *(int *)PTR_DAT_0602fdcc;
  if (*(short *)PTR_DAT_0602fdd0 == 0) {
    uVar8 = (uint)*(ushort *)PTR_DAT_0602fdf8;
    iVar10 = (int)PTR_DAT_0602fdf4._0_2_;
    if (*(short *)PTR_DAT_0602fdfc < 1) {
      if ((uVar8 & (int)*(short *)PTR_DAT_0602fe2c) == 0) {
        if ((uVar8 & (int)*(short *)PTR_DAT_0602fe40) == 0) {
          if ((uVar8 & (int)*(short *)PTR_DAT_0602fe54) == 0) {
            if ((uVar8 & (int)*(short *)PTR_DAT_0602fea0) != 0) {
              *(undefined2 *)(iVar10 + iVar4) = 0;
            }
          }
          else {
            *(undefined2 *)(iVar10 + iVar4) = 1;
          }
        }
        else {
          *(undefined2 *)(iVar10 + iVar4) = 2;
        }
      }
      else {
        *(undefined2 *)(iVar10 + iVar4) = 3;
      }
    }
    else if ((uVar8 & (int)*(short *)PTR_DAT_0602fdfc) == 0) {
      if ((uVar8 & (int)*(short *)PTR_DAT_0602fe18) != 0) {
        sVar9 = *(short *)(iVar10 + iVar4);
        if (sVar9 != 3) {
          sVar9 = sVar9 + 1;
        }
        *(short *)(iVar10 + iVar4) = sVar9;
      }
    }
    else {
      sVar9 = *(short *)(iVar10 + iVar4);
      if (sVar9 != 0) {
        sVar9 = sVar9 + -1;
      }
      *(short *)(iVar10 + iVar4) = sVar9;
    }
    bVar12 = (byte)*(undefined2 *)(iVar10 + iVar4);
    uVar1 = *(ushort *)PTR_DAT_0602fea4;
    if ((uVar1 & *(ushort *)PTR_DAT_0602fea8) == 0) {
      uVar8 = *(uint *)(DAT_0602febe + iVar4);
      if ((int)uVar8 < 0xb0) {
        iVar10 = uVar8 - (uVar8 >> 4);
        if (iVar10 < 0x6f) {
          iVar10 = 0x38;
        }
      }
      else {
        iVar10 = uVar8 - 1;
      }
      *(int *)(DAT_0602febe + iVar4) = iVar10;
      *(undefined4 *)(DAT_0602ff00 + iVar4) = 0;
    }
    else {
      bVar12 = bVar12 | 0x80;
      iVar6 = (int)DAT_0602fe9a;
      *(undefined4 *)(iVar6 + iVar4) = 1;
      iVar6 = iVar6 + 8;
      iVar7 = *(int *)(iVar6 + iVar4);
      iVar10 = iVar7;
      if ((iVar7 <= DAT_0602fe9c) && (iVar10 = iVar7 + 10, (int)DAT_0602fe9e <= iVar7 + 10)) {
        iVar10 = (int)DAT_0602fe9c;
      }
      *(int *)(iVar6 + iVar4) = iVar10;
    }
    bVar11 = 0;
    if ((uVar1 & *(ushort *)PTR_DAT_0602ff04) == 0) {
      uVar8 = *(uint *)(DAT_0602ff3c + iVar4);
      *(uint *)(DAT_0602ff40 + iVar4) = uVar8;
      iVar10 = uVar8 - (uVar8 >> 1);
      if (iVar10 < 0x38) {
        iVar10 = 0x38;
      }
      *(int *)(DAT_0602ff3c + iVar4) = iVar10;
      *(undefined4 *)(DAT_0602ff44 + iVar4) = 0;
    }
    else {
      bVar12 = bVar12 | 0x40;
      *(undefined4 *)(DAT_0602fefa + iVar4) = 1;
      iVar10 = (int)DAT_0602fefc;
      iVar6 = *(int *)(iVar10 + iVar4);
      *(int *)(DAT_0602fefe + iVar4) = iVar6;
      if (iVar6 <= DAT_0602ff08) {
        iVar6 = iVar6 + 0x28;
      }
      *(int *)(iVar10 + iVar4) = iVar6;
    }
    bVar2 = false;
    if (*(short *)(PTR_DAT_0602ff38._0_2_ + iVar4) != 0) {
      bVar2 = true;
      bVar11 = (byte)*(undefined2 *)PTR_DAT_060300a0;
      if (*PTR_DAT_060300a4 == '\0') {
        bVar11 = ~bVar11;
      }
      *(uint *)(DAT_0603009a + iVar4) = bVar11 - 0x80;
      goto LAB_06030068;
    }
    if ((uVar1 & *(ushort *)PTR_DAT_0602ffa0) == 0) {
      if ((uVar1 & *(ushort *)PTR_DAT_06030000) == 0) {
        *(undefined4 *)(DAT_0603002a + iVar4) = 0;
        if (*(int *)(DAT_0603002c + iVar4) != 0) {
          *(undefined4 *)(DAT_0603002c + iVar4) = 0;
          bVar11 = 0;
          *(undefined4 *)(DAT_06030048 + iVar4) = 0;
          *(undefined4 *)(DAT_0603004a + iVar4) = 0;
        }
        goto LAB_06030068;
      }
      bVar12 = bVar12 | 0x10;
      *(undefined4 *)(DAT_0602fff8 + iVar4) = 0;
      *(undefined4 *)(DAT_0602fffa + iVar4) = 1;
      iVar10 = (int)DAT_0602fffc;
      iVar6 = *(int *)(iVar10 + iVar4);
      if (iVar6 < 0) {
        bVar11 = 0x32;
        iVar6 = iVar6 >> 1;
        if (iVar6 < 0x33) {
          iVar6 = 0;
          goto LAB_0602ffd8;
        }
      }
      else {
LAB_0602ffd8:
        bVar11 = 0x70 - (char)iVar6;
        (*(code *)PTR_FUN_06030004)(*(undefined4 *)(DAT_0602fffe + iVar4));
        iVar6 = iVar6 + extraout_r1_00;
        iVar4 = unaff_r14;
      }
      *(int *)(iVar10 + iVar4) = iVar6;
      goto LAB_06030068;
    }
    bVar12 = bVar12 | 0x20;
    *(undefined4 *)(DAT_0602ff96 + iVar4) = 0;
    *(undefined4 *)(DAT_0602ff98 + iVar4) = 1;
    iVar10 = (int)DAT_0602ff9a;
    iVar6 = *(int *)(iVar10 + iVar4);
    if (iVar6 < 1) {
LAB_0602ff76:
      bVar11 = 0x90 - (char)iVar6;
      (*(code *)PTR_FUN_0602ffa4)(*(undefined4 *)(PTR_DAT_0602ff9c._0_2_ + iVar4));
      iVar6 = iVar6 + extraout_r1;
      iVar4 = unaff_r14;
    }
    else {
      bVar11 = 0xce;
      iVar6 = iVar6 >> 1;
      if (-0x33 < iVar6) {
        iVar6 = 0;
        goto LAB_0602ff76;
      }
    }
    *(int *)(iVar10 + iVar4) = iVar6;
LAB_06030068:
    puVar3 = PTR_DAT_060300ac;
    iVar4 = *(int *)PTR_DAT_060300ac;
    pbVar5 = PTR_DAT_060300a8 + iVar4;
    *pbVar5 = bVar12;
    if (bVar2) {
      pbVar5[1] = bVar11;
    }
    iVar10 = iVar4 + 2;
    if ((int)DAT_0603009c < iVar4 + 2) {
      iVar10 = iVar4;
    }
    *(int *)puVar3 = iVar10;
    return;
  }
  iVar10 = *(int *)PTR_DAT_060300fc;
  bVar12 = PTR_DAT_060300f8[iVar10];
  *(ushort *)(DAT_060300f0 + iVar4) = bVar12 & 3;
  *(int *)puVar3 = iVar10 + 1;
  if ((bVar12 & 0x80) == 0) {
    uVar8 = *(uint *)(DAT_06030112 + iVar4);
    if ((int)uVar8 < 0xb0) {
      iVar10 = uVar8 - (uVar8 >> 4);
      if (iVar10 < 0x6f) {
        iVar10 = 0x38;
      }
    }
    else {
      iVar10 = uVar8 - 1;
    }
    *(int *)(DAT_06030112 + iVar4) = iVar10;
    *(undefined4 *)(DAT_06030150 + iVar4) = 0;
  }
  else {
    iVar6 = (int)DAT_060300f2;
    *(undefined4 *)(iVar6 + iVar4) = 1;
    iVar6 = iVar6 + 8;
    iVar7 = *(int *)(iVar6 + iVar4);
    iVar10 = iVar7;
    if ((iVar7 <= DAT_060300f4) && (iVar10 = iVar7 + 10, (int)DAT_060300f6 <= iVar7 + 10)) {
      iVar10 = (int)DAT_060300f4;
    }
    *(int *)(iVar6 + iVar4) = iVar10;
  }
  if ((bVar12 & 0x40) == 0) {
    uVar8 = *(uint *)(DAT_06030184 + iVar4);
    *(uint *)(DAT_06030188 + iVar4) = uVar8;
    iVar10 = uVar8 - (uVar8 >> 1);
    if (iVar10 < 0x38) {
      iVar10 = 0x38;
    }
    *(int *)(DAT_06030184 + iVar4) = iVar10;
    *(undefined4 *)(DAT_0603018c + iVar4) = 0;
  }
  else {
    *(undefined4 *)(DAT_06030148 + iVar4) = 1;
    iVar10 = (int)DAT_0603014a;
    iVar6 = *(int *)(iVar10 + iVar4);
    *(int *)(PTR_DAT_0603014c._0_2_ + iVar4) = iVar6;
    if (iVar6 <= DAT_06030154) {
      iVar6 = iVar6 + 0x28;
    }
    *(int *)(iVar10 + iVar4) = iVar6;
  }
  if (*PTR_DAT_06030190 != '\0') {
    *(uint *)(PTR_DAT_060302b0._0_2_ + iVar4) =
         (byte)PTR_DAT_060302b4[*(int *)PTR_DAT_060302b8] - 0x80;
    goto LAB_06030296;
  }
  if ((bVar12 & 0x20) == 0) {
    if ((bVar12 & 0x10) == 0) {
      *(undefined4 *)(DAT_0603025e + iVar4) = 0;
      if (*(int *)(DAT_06030260 + iVar4) != 0) {
        *(undefined4 *)(DAT_06030260 + iVar4) = 0;
        *(undefined4 *)(DAT_0603027c + iVar4) = 0;
        *(undefined4 *)(DAT_0603027e + iVar4) = 0;
      }
      goto LAB_06030296;
    }
    *(undefined4 *)(DAT_06030230 + iVar4) = 0;
    *(undefined4 *)(DAT_06030232 + iVar4) = 1;
    iVar10 = (int)DAT_06030234;
    iVar6 = *(int *)(iVar10 + iVar4);
    if (iVar6 < 0) {
      iVar6 = iVar6 >> 1;
      if (iVar6 < 0x33) {
        iVar6 = 0;
        goto LAB_06030210;
      }
    }
    else {
LAB_06030210:
      (*(code *)PTR_FUN_06030238)
                (*(undefined4 *)(DAT_06030236 + iVar4),1,(int)DAT_06030236,0x70 - iVar6);
      iVar6 = iVar6 + extraout_r1_02;
      iVar4 = unaff_r14;
    }
    *(int *)(iVar10 + iVar4) = iVar6;
    goto LAB_06030296;
  }
  *(undefined4 *)(DAT_060301dc + iVar4) = 0;
  *(undefined4 *)(DAT_060301de + iVar4) = 1;
  iVar10 = (int)DAT_060301e0;
  iVar6 = *(int *)(iVar10 + iVar4);
  if (iVar6 < 1) {
LAB_060301bc:
    (*(code *)PTR_FUN_060301e4)
              (*(undefined4 *)(DAT_060301e2 + iVar4),1,(int)DAT_060301e2,-0x70 - iVar6);
    iVar6 = iVar6 + extraout_r1_01;
    iVar4 = unaff_r14;
  }
  else {
    iVar6 = iVar6 >> 1;
    if (-0x33 < iVar6) {
      iVar6 = 0;
      goto LAB_060301bc;
    }
  }
  *(int *)(iVar10 + iVar4) = iVar6;
LAB_06030296:
  *(int *)PTR_DAT_060302b8 = *(int *)PTR_DAT_060302b8 + 1;
  return;
}

