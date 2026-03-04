/* FUN_0602F9A6  0x0602F9A6 */


uint FUN_0602f9a6(void)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  uint *puVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  short *psVar11;
  undefined4 *unaff_r14;
  uint *puVar12;
  
  puVar3 = PTR_DAT_0602fa10;
  puVar2 = PTR_FUN_0602fa0c;
  puVar12 = (uint *)*unaff_r14;
  if (((char)*PTR_DAT_0602fa10 != 0) &&
     (iVar4 = (char)*PTR_DAT_0602fa10 + -1, *PTR_DAT_0602fa10 = (char)iVar4, iVar4 == 2)) {
    (*(code *)puVar2)(0,DAT_0602fa14);
  }
  if (((char)puVar3[1] != 0) && (iVar4 = (char)puVar3[1] + -1, puVar3[1] = (char)iVar4, iVar4 == 2))
  {
    (*(code *)puVar2)(0,DAT_0602fa18);
  }
  if (((char)puVar3[2] != 0) && (iVar4 = (char)puVar3[2] + -1, puVar3[2] = (char)iVar4, iVar4 == 2))
  {
    (*(code *)puVar2)(0,DAT_0602fa18);
  }
  uVar1 = DAT_0602fa64;
  uVar9 = DAT_0602fa20;
  if ((char)*PTR_DAT_0602fd9a_1_0602fa1c == 0) {
    if ((char)PTR_DAT_0602fd9a_1_0602fa1c[1] == 0) goto LAB_0602fa42;
    iVar4 = (char)PTR_DAT_0602fd9a_1_0602fa1c[1] + -1;
    PTR_DAT_0602fd9a_1_0602fa1c[1] = (char)iVar4;
    uVar9 = uVar1;
    uVar1 = DAT_0602fa68;
  }
  else {
    iVar4 = (char)*PTR_DAT_0602fd9a_1_0602fa1c + -1;
    *PTR_DAT_0602fd9a_1_0602fa1c = (char)iVar4;
    uVar1 = DAT_0602fa24;
  }
  if ((iVar4 == 4) || (uVar9 = uVar1, iVar4 == 0)) {
    (*(code *)puVar2)(0,uVar9);
  }
LAB_0602fa42:
  puVar3 = PTR_DAT_0602fa70;
  uVar5 = *(uint *)PTR_DAT_0602fa6c;
  if (uVar5 == 0) {
    cVar6 = *PTR_DAT_0602fa70;
    uVar5 = (uint)(char)PTR_DAT_0602fa70[1];
    if ((int)uVar5 < 1) {
      if ((*(int *)((int)PTR_DAT_0602fa60._0_2_ + (int)puVar12) == 0) ||
         (0x1e < *(int *)((int)PTR_DAT_0602fa60._0_2_ + (int)puVar12))) {
        if (cVar6 != '\0') {
          uVar9 = DAT_0602fab8;
          if (*PTR_DAT_0602fab4 != '\0') {
            uVar9 = DAT_0602fabc;
          }
          uVar5 = (*(code *)puVar2)(0,uVar9);
          cVar6 = '\0';
        }
      }
      else {
        (*(code *)puVar2)(0,DAT_0602fa88);
        uVar5 = 0x14;
        cVar6 = '\x01';
      }
    }
    else {
      uVar5 = uVar5 - 1;
    }
    *puVar3 = cVar6;
    puVar3[1] = (char)uVar5;
  }
  puVar3 = PTR_DAT_0602fac0;
  if (*(short *)PTR_DAT_0602fac0 == 0) {
    uVar5 = *puVar12;
    if ((uVar5 & 8) == 0) {
      if (*(int *)PTR_DAT_0602fb14 == 0) {
        iVar8 = *(int *)PTR_DAT_0602fb18 + -1;
        puVar7 = *(uint **)PTR_DAT_0602fb1c;
        iVar4 = 0;
        iVar10 = 0;
        while( true ) {
          for (; (PTR_DAT_0602fb20 == (undefined *)(*puVar7 & (uint)PTR_DAT_0602fb20) ||
                 (PTR_DAT_0602fb24 == (undefined *)(*puVar7 & (uint)PTR_DAT_0602fb24)));
              puVar7 = (uint *)((int)puVar7 + (int)DAT_0602fb3c)) {
            iVar4 = iVar4 + 1;
            if (iVar4 == 2) {
              if (*PTR_DAT_0602fda0_1_0602fb4c == '\0') {
                if ((int)puVar7[3] <= (int)puVar12[3]) {
                  *PTR_DAT_0602fda0_1_0602fb4c = 10;
                  uVar5 = (*(code *)puVar2)(0,DAT_0602fb68);
                  *(undefined2 *)puVar3 = 0x3c;
                  return uVar5;
                }
              }
              else {
                *PTR_DAT_0602fda0_1_0602fb4c = *PTR_DAT_0602fda0_1_0602fb4c + -1;
              }
              goto LAB_0602fbb4;
            }
            iVar8 = iVar8 + -1;
            if (iVar8 == 0) goto LAB_0602fb6c;
          }
          if (PTR_DAT_0602fb28 == (undefined *)(*puVar7 & (uint)PTR_DAT_0602fb28)) {
            iVar10 = iVar10 + 1;
          }
          iVar8 = iVar8 + -1;
          if (iVar8 == 0) break;
          puVar7 = (uint *)((int)puVar7 + (int)PTR_DAT_0602fb10._0_2_);
        }
LAB_0602fb6c:
        if (0 < iVar10) {
          if (*PTR_DAT_0602fb80 == '\0') {
            if (-1 < (int)(puVar7[3] - puVar12[3])) {
              uVar9 = DAT_0602fbac;
              if ((int)(uint)DAT_0602fba8 <= (int)(puVar7[3] - puVar12[3])) {
                uVar9 = DAT_0602fbb0;
              }
              *PTR_DAT_0602fb80 = 3;
              uVar5 = (*(code *)puVar2)(0,uVar9);
              *(undefined2 *)puVar3 = 0x3c;
              return uVar5;
            }
          }
          else {
            *PTR_DAT_0602fb80 = *PTR_DAT_0602fb80 + -1;
          }
        }
      }
LAB_0602fbb4:
      if (*(int *)((int)puVar12 + (int)DAT_0602fbca) == 1) {
        uVar5 = (*(code *)puVar2)(0,DAT_0602fbcc);
        *(undefined2 *)puVar3 = 0x3c;
      }
      else if ((int)(char)*PTR_DAT_0602fd9a_1_0602fbe8 + (int)(char)PTR_DAT_0602fd9a_1_0602fbe8[1]
               == 1) {
        uVar5 = (*(code *)puVar2)(0,DAT_0602fbec);
        *(undefined2 *)puVar3 = 0x3c;
      }
      else {
        iVar4 = (int)*(short *)(PTR_DAT_0602fc1c + *(int *)PTR_DAT_0602fc18 * 4);
        for (psVar11 = (short *)(PTR_PTR_0602fc20 +
                                *(short *)((int)(PTR_DAT_0602fc1c + *(int *)PTR_DAT_0602fc18 * 4) +
                                          2));
            *(int *)((int)puVar12 + (int)PTR_DAT_0602fc14._0_2_) != (int)*psVar11;
            psVar11 = psVar11 + 2) {
          iVar4 = iVar4 + -1;
          if (iVar4 == 0) goto LAB_0602fcc0;
        }
        iVar4 = (int)psVar11[1];
        if (iVar4 == 2) {
          if (((int)DAT_0602fc9c <= (int)puVar12[2]) &&
             (0x17ff < *(int *)((int)puVar12 + (int)DAT_0602fc9e))) {
            uVar5 = (*(code *)puVar2)(0,DAT_0602fca0);
            *(undefined2 *)puVar3 = 0x3c;
            return uVar5;
          }
        }
        else if (iVar4 == 3) {
          if ((int)PTR_DAT_0602fcb8._0_2_ <= (int)puVar12[2]) {
            uVar5 = (*(code *)puVar2)(0,DAT_0602fcbc);
            *(undefined2 *)puVar3 = 0x3c;
            return uVar5;
          }
        }
        else if ((*(int *)((int)DAT_0602fc74 + (int)puVar12) +
                  *(int *)((int)DAT_0602fc72 + (int)puVar12) +
                  (int)*(short *)((int)DAT_0602fc70 + (int)puVar12) +
                  (int)*(short *)((int)DAT_0602fc6e + (int)puVar12) == 0) &&
                ((*(uint *)((int)DAT_0602fc76 + (int)puVar12) & 1) != 0)) {
          uVar5 = (*(code *)puVar2)(0,*(undefined4 *)(PTR_LAB_0602fc78 + iVar4 * 4));
          *(undefined2 *)puVar3 = 0x3c;
          return uVar5;
        }
LAB_0602fcc0:
        if ((*(int *)((int)puVar12 + (int)PTR_DAT_0602fcdc._0_2_) == 1) &&
           ((int)PTR_DAT_0602fce0 < (int)puVar12[3])) {
          uVar5 = (*(code *)puVar2)(0,DAT_0602fce4);
          *(undefined2 *)puVar3 = 0x3c;
        }
        else {
          uVar5 = *(uint *)PTR_DAT_0602fd1c;
          if ((uVar5 == 1) &&
             (((*(int *)((int)DAT_0602fd1a + (int)puVar12) == 0xe0 ||
               (*(int *)((int)DAT_0602fd1a + (int)puVar12) == 0xe1)) &&
              (uVar5 = puVar12[5], 0xa0000 < (int)uVar5)))) {
            uVar5 = (*(code *)puVar2)(0,DAT_0602fd20);
            *(undefined2 *)puVar3 = 0x3c;
          }
        }
      }
    }
  }
  else {
    *(short *)PTR_DAT_0602fac0 = *(short *)PTR_DAT_0602fac0 + -1;
  }
  return uVar5;
}

