/* FUN_0601BE64  0x0601BE64 */


undefined4 FUN_0601be64(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  puVar4 = PTR_DAT_0601bed4;
  puVar3 = PTR_DAT_0601bed0;
  puVar2 = PTR_DAT_0601becc;
  puVar1 = PTR_DAT_0601bec8;
  iVar7 = *(int *)PTR_DAT_0601bed8;
  if ((*(int *)PTR_DAT_0601bedc == 0) || (*(int *)PTR_DAT_0601bee0 == 0)) {
    (*(code *)PTR_FUN_0601bee4)();
    (*(code *)PTR_FUN_0601bee4)();
    (*(code *)PTR_FUN_0601bee4)();
    uVar5 = (*(code *)PTR_FUN_0601bee4)();
  }
  else {
    if ((*(byte *)(iVar7 + 3) & 0x40) != 0) {
      *(undefined2 *)PTR_DAT_0601bf8c = 8;
      (*(code *)PTR_FUN_0601bf90)();
    }
    if (((int)*(char *)(iVar7 + 3) & 0x80U) != 0) {
      *(undefined2 *)PTR_DAT_0601bf94 = 8;
      (*(code *)PTR_FUN_0601bf90)();
    }
    if ((*(byte *)(iVar7 + 2) & 1) != 0) {
      *(undefined2 *)PTR_DAT_0601bf98 = 8;
      (*(code *)PTR_FUN_0601bf90)();
    }
    if ((*(byte *)(iVar7 + 2) & 2) != 0) {
      *(undefined2 *)PTR_DAT_0601bf9c = 8;
      (*(code *)PTR_FUN_0601bf90)();
    }
    iVar6 = (int)DAT_0601bf8a;
    if (*(short *)PTR_DAT_0601bf8c == 0) {
      if (*(short *)PTR_DAT_0601c0a0 == 0) {
        if (*(short *)PTR_DAT_0601c1f4 == 0) {
          if (*(short *)PTR_DAT_0601c2c0 != 0) {
            (*(code *)PTR_FUN_0601c2c4)();
            (*(code *)PTR_FUN_0601c2c8)(iVar6,iVar6,iVar6);
            (*(code *)PTR_FUN_0601c2d0)(DAT_0601c2cc,puVar1,(int)DAT_0601c2bc);
            (*(code *)PTR_FUN_0601c2d4)((int)DAT_0601c2be);
            iVar6 = ((byte)*puVar3 + 0x12) * 4;
            (*(code *)PTR_FUN_0601c2e0)
                      (*(undefined4 *)(PTR_PTR_0601c2dc + iVar6),
                       *(undefined4 *)(PTR_DAT_0601c2d8 + iVar6));
            iVar6 = ((byte)*puVar3 + 0x12) * 4;
            (*(code *)PTR_FUN_0601c2f0)
                      (*(undefined4 *)(PTR_PTR_0601c2ec + iVar6),(int)*(short *)PTR_DAT_0601c2e8,
                       *(undefined4 *)(PTR_DAT_0601c2e4 + iVar6));
            *(int *)puVar2 = *(int *)puVar2 + -0x30;
            *puVar3 = *puVar3 + '\x01';
            if (2 < (byte)*puVar3) {
              *puVar3 = 0;
            }
            *(short *)PTR_DAT_0601c2c0 = *(short *)PTR_DAT_0601c2c0 + -1;
          }
        }
        else {
          (*(code *)PTR_FUN_0601c1f8)(iVar6,iVar6,iVar6);
          (*(code *)PTR_FUN_0601c200)(PTR_DAT_0601c1fc,puVar1,(int)DAT_0601c1ee);
          (*(code *)PTR_FUN_0601c204)((int)DAT_0601c1f0);
          iVar6 = ((byte)*puVar4 + 0x12) * 4;
          (*(code *)PTR_FUN_0601c210)
                    (*(undefined4 *)(PTR_PTR_0601c20c + iVar6),
                     *(undefined4 *)(PTR_DAT_0601c208 + iVar6));
          iVar6 = ((byte)*puVar4 + 0x12) * 4;
          (*(code *)PTR_FUN_0601c220)
                    (*(undefined4 *)(PTR_PTR_0601c21c + iVar6),(int)*(short *)PTR_DAT_0601c218,
                     *(undefined4 *)(PTR_DAT_0601c214 + iVar6));
          *(int *)puVar2 = *(int *)puVar2 + -0x30;
          *puVar4 = *puVar4 + '\x01';
          if (2 < (byte)*puVar4) {
            *puVar4 = 0;
          }
          *(short *)PTR_DAT_0601c1f4 = *(short *)PTR_DAT_0601c1f4 + -1;
        }
      }
      else {
        (*(code *)PTR_FUN_0601c0a4)();
        if ((*(int *)PTR_DAT_0601c0a8 == 1) && (*(int *)PTR_DAT_0601c0ac == 1)) {
          (*(code *)PTR_FUN_0601c078)(DAT_0601c0b4,puVar1,DAT_0601c0b0);
          (*(code *)PTR_FUN_0601c0b8)(iVar6,iVar6,iVar6);
        }
        else {
          (*(code *)PTR_FUN_0601c13c)(DAT_0601c138,puVar1,(int)DAT_0601c132);
        }
        (*(code *)PTR_FUN_0601c140)((int)DAT_0601c134);
        iVar6 = ((byte)*puVar3 + 0x12) * 4;
        (*(code *)PTR_FUN_0601c14c)
                  (*(undefined4 *)(PTR_PTR_0601c148 + iVar6),
                   *(undefined4 *)(PTR_DAT_0601c144 + iVar6));
        iVar6 = ((byte)*puVar3 + 0x12) * 4;
        (*(code *)PTR_FUN_0601c15c)
                  (*(undefined4 *)(PTR_PTR_0601c158 + iVar6),(int)*(short *)PTR_DAT_0601c154,
                   *(undefined4 *)(PTR_DAT_0601c150 + iVar6));
        *(int *)puVar2 = *(int *)puVar2 + -0x30;
        *puVar3 = *puVar3 + '\x01';
        if (2 < (byte)*puVar3) {
          *puVar3 = 0;
        }
        *(short *)PTR_DAT_0601c160 = *(short *)PTR_DAT_0601c160 + -1;
      }
    }
    else {
      (*(code *)PTR_FUN_0601bfa0)();
      if ((*(int *)PTR_DAT_0601bfa4 == 1) && (*(int *)PTR_DAT_0601bfa8 == 1)) {
        (*(code *)PTR_FUN_0601bfb4)(PTR_DAT_0601bfb0,puVar1,DAT_0601bfac);
        (*(code *)PTR_FUN_0601bfb8)(iVar6,iVar6,iVar6);
      }
      else {
        (*(code *)PTR_FUN_0601c078)(PTR_DAT_0601c074,puVar1,(int)DAT_0601c06e);
      }
      (*(code *)PTR_FUN_0601c07c)((int)DAT_0601c070);
      iVar6 = ((byte)*puVar4 + 0x12) * 4;
      (*(code *)PTR_FUN_0601c088)
                (*(undefined4 *)(PTR_PTR_0601c084 + iVar6),*(undefined4 *)(PTR_DAT_0601c080 + iVar6)
                );
      iVar6 = ((byte)*puVar4 + 0x12) * 4;
      (*(code *)PTR_FUN_0601c098)
                (*(undefined4 *)(PTR_PTR_0601c094 + iVar6),(int)*(short *)PTR_DAT_0601c090,
                 *(undefined4 *)(PTR_DAT_0601c08c + iVar6));
      *(int *)puVar2 = *(int *)puVar2 + -0x30;
      *puVar4 = *puVar4 + '\x01';
      if (2 < (byte)*puVar4) {
        *puVar4 = 0;
      }
      *(short *)PTR_DAT_0601c09c = *(short *)PTR_DAT_0601c09c + -1;
    }
    if (*(int *)PTR_DAT_0601c2f4 == 0) {
      uVar5 = 0;
    }
    else {
      if ((*(short *)(iVar7 + DAT_0601c3a6) == 0) && (*(short *)(iVar7 + DAT_0601c3a8) == 0)) {
        *(undefined2 *)PTR_DAT_0601c3ac = 0;
      }
      if ((*(short *)(iVar7 + DAT_0601c3a6) != 0) ||
         (uVar5 = 0, *(short *)(iVar7 + DAT_0601c3a8) != 0)) {
        (*(code *)PTR_FUN_0601c3b0)();
        (*(code *)PTR_FUN_0601c3bc)
                  (*(undefined4 *)PTR_DAT_0601c3b4,
                   *(int *)(PTR_DAT_0601c3b4 + 4) + (int)DAT_0601c3aa,
                   DAT_0601c3b8 - *(int *)(PTR_DAT_0601c3b4 + 8));
        (*(code *)PTR_FUN_0601c3c0)(puVar1);
        iVar6 = (*(short *)(PTR_DAT_0601c3c4 + *(short *)(iVar7 + DAT_0601c3a6) * 2) + 0xe) * 4;
        (*(code *)PTR_FUN_0601c3d0)
                  (*(undefined4 *)(PTR_PTR_0601c3cc + iVar6),
                   *(undefined4 *)(PTR_DAT_0601c3c8 + iVar6));
        iVar7 = (*(short *)(PTR_DAT_0601c3c4 + *(short *)(iVar7 + DAT_0601c3a6) * 2) + 0xe) * 4;
        uVar5 = (*(code *)PTR_FUN_0601c3e0)
                          (*(undefined4 *)(PTR_PTR_0601c3dc + iVar7),(int)*(short *)PTR_DAT_0601c3d8
                           ,*(undefined4 *)(PTR_DAT_0601c3d4 + iVar7));
        *(int *)puVar2 = *(int *)puVar2 + -0x30;
      }
    }
  }
  return uVar5;
}

