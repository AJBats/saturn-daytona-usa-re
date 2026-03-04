/* FUN_0602DDA0  0x0602DDA0 */


undefined4 * FUN_0602dda0(void)

{
  uint *puVar1;
  int extraout_r1;
  int iVar2;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  int extraout_r1_03;
  uint uVar3;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  uint extraout_r3_02;
  int iVar4;
  undefined4 *puVar5;
  code *unaff_r12;
  
  do {
    (*unaff_r12)();
    iVar2 = extraout_r1;
    if (extraout_r1 < DAT_0602dea8) {
      iVar2 = -extraout_r1;
    }
    *piRam0602deac = iVar2;
    uVar3 = extraout_r3;
    do {
      if ((uRam0602deb0 & uVar3) != 0) {
        (*(code *)PTR_FUN_0602dea4)();
        iVar2 = extraout_r1_00;
        if (extraout_r1_00 < DAT_0602dea8) {
          iVar2 = -extraout_r1_00;
        }
        *piRam0602deb8 = iVar2;
        uVar3 = extraout_r3_00;
      }
      if ((uRam0602debc & uVar3) != 0) {
        *puRam0602dec0 = *puRam0602dec0 & 0xffff;
        (*(code *)PTR_FUN_0602dea4)();
        iVar2 = extraout_r1_01;
        if (extraout_r1_01 < DAT_0602dea8) {
          iVar2 = -extraout_r1_01;
        }
        *(int *)PTR_DAT_0602dec4 = iVar2;
        uVar3 = extraout_r3_01;
      }
      if ((DAT_0602de7c & uVar3) != 0) {
        (*(code *)PTR_FUN_0602dea4)();
        iVar2 = extraout_r1_02;
        if (extraout_r1_02 < DAT_0602dea8) {
          iVar2 = -extraout_r1_02;
        }
        *(int *)PTR_DAT_0602decc = iVar2;
        uVar3 = extraout_r3_02;
      }
      if ((DAT_0602ded0 & uVar3) != 0) {
        (*(code *)PTR_FUN_0602dea4)();
        iVar2 = extraout_r1_03;
        if (extraout_r1_03 < DAT_0602dea8) {
          iVar2 = -extraout_r1_03;
        }
        *(int *)PTR_DAT_0602ded8 = iVar2;
      }
      (*(code *)PTR_FUN_0602dedc)();
      if (*(int *)PTR_DAT_0602de84 != 0) {
        *(int *)PTR_DAT_0602de84 = *(int *)PTR_DAT_0602de84 + -1;
        puVar5 = *(undefined4 **)PTR_DAT_0602df0c;
        if ((DAT_0602df10 & (uint)puVar5) != 0) {
          iVar4 = *(int *)PTR_DAT_0602df14;
          iVar2 = *(int *)PTR_DAT_0602df18;
          if (iVar4 < iVar2) {
            iVar2 = iVar2 - *(int *)PTR_DAT_0602df1c;
            if (iVar4 <= iVar2) {
LAB_0602df34:
              *(int *)PTR_DAT_0602df18 = iVar2;
              goto LAB_0602df36;
            }
          }
          else {
            iVar2 = iVar2 + *(int *)PTR_DAT_0602df30;
            if (iVar2 <= iVar4) goto LAB_0602df34;
          }
          *(int *)PTR_DAT_0602df18 = iVar4;
        }
LAB_0602df36:
        if ((DAT_0602df58 & (uint)puVar5) != 0) {
          iVar4 = *(int *)PTR_DAT_0602df5c;
          iVar2 = *(int *)PTR_DAT_0602df60;
          if (iVar4 < iVar2) {
            iVar2 = iVar2 - *(int *)PTR_DAT_0602df64;
            if (iVar4 <= iVar2) {
LAB_0602df7c:
              *(int *)PTR_DAT_0602df60 = iVar2;
              goto LAB_0602df7e;
            }
          }
          else {
            iVar2 = iVar2 + *(int *)PTR_DAT_0602df78;
            if (iVar2 <= iVar4) goto LAB_0602df7c;
          }
          *(int *)PTR_DAT_0602df60 = iVar4;
        }
LAB_0602df7e:
        if ((DAT_0602dfa0 & (uint)puVar5) != 0) {
          iVar4 = *(int *)PTR_DAT_0602dfa4;
          iVar2 = *(int *)PTR_DAT_0602dfa8;
          if (iVar4 < iVar2) {
            iVar2 = iVar2 - *(int *)PTR_DAT_0602dfac;
            if (iVar4 <= iVar2) {
LAB_0602dfc4:
              *(int *)PTR_DAT_0602dfa8 = iVar2;
              goto LAB_0602dfc6;
            }
          }
          else {
            iVar2 = iVar2 + *(int *)PTR_DAT_0602dfc0;
            if (iVar2 <= iVar4) goto LAB_0602dfc4;
          }
          *(int *)PTR_DAT_0602dfa8 = iVar4;
        }
LAB_0602dfc6:
        if ((DAT_0602dfe8 & (uint)puVar5) != 0) {
          iVar4 = *(int *)PTR_DAT_0602dfec;
          iVar2 = *(int *)PTR_DAT_0602dff0;
          if (iVar4 < iVar2) {
            iVar2 = iVar2 - *(int *)PTR_DAT_0602dff4;
            if (iVar4 <= iVar2) {
LAB_0602e00c:
              *(int *)PTR_DAT_0602dff0 = iVar2;
              goto LAB_0602e00e;
            }
          }
          else {
            iVar2 = iVar2 + *(int *)PTR_DAT_0602e008;
            if (iVar2 <= iVar4) goto LAB_0602e00c;
          }
          *(int *)PTR_DAT_0602dff0 = iVar4;
        }
LAB_0602e00e:
        if ((DAT_0602e030 & (uint)puVar5) == 0) {
          return puVar5;
        }
        iVar4 = *(int *)PTR_DAT_0602e034;
        iVar2 = *(int *)PTR_DAT_0602e038;
        if (iVar4 < iVar2) {
          puVar5 = *(undefined4 **)PTR_DAT_0602e03c;
          iVar2 = iVar2 - (int)puVar5;
          if (iVar4 <= iVar2) {
LAB_0602e054:
            *(int *)PTR_DAT_0602e038 = iVar2;
            return puVar5;
          }
        }
        else {
          puVar5 = *(undefined4 **)PTR_DAT_0602e050;
          iVar2 = iVar2 + (int)puVar5;
          if (iVar2 <= iVar4) goto LAB_0602e054;
        }
        *(int *)PTR_DAT_0602e038 = iVar4;
        return puVar5;
      }
      *(int *)PTR_DAT_0602e06c = *(int *)PTR_DAT_0602e06c + 1;
      *(undefined4 *)PTR_DAT_0602e070 = DAT_0602e074;
      puVar1 = (uint *)(*(int *)(*piRam0602dd40 * 4 + iRam0602dd44) + *piRam0602dd48 * 0x20);
      uVar3 = *puVar1;
      if (uVar3 == uRam0602dd4c) {
        *piRam0602dd48 = iRam0602dd50;
        puVar5 = puRam0602dd54;
        *puRam0602dd54 = uRam0602dd58;
        return puVar5;
      }
      *puRam0602de78 = DAT_0602de7c;
      *puRam0602de80 = uVar3;
      *(uint *)PTR_DAT_0602de84 = puVar1[1];
      *puRam0602de88 = puVar1[2];
      *puRam0602de8c = puVar1[3];
      *puRam0602de90 = puVar1[4];
      *(uint *)PTR_DAT_0602de94 = puVar1[5];
      *(uint *)PTR_DAT_0602de98 = puVar1[6];
      unaff_r12 = (code *)PTR_FUN_0602dea4;
    } while ((uRam0602de9c & uVar3) == 0);
  } while( true );
}

