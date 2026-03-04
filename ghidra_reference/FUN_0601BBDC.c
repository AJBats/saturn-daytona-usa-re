/* FUN_0601BBDC  0x0601BBDC */


int FUN_0601bbdc(undefined4 param_1,char param_2,uint param_3)

{
  char cVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  int unaff_r9;
  char *pcVar12;
  byte bVar13;
  uint uVar14;
  uint local_28;
  undefined1 auStack_8 [8];
  
  puVar4 = PTR_FUN_0601bcc0;
  puVar3 = PTR_FUN_0601bcbc;
  iVar11 = (int)DAT_0601bcba;
  iVar8 = (*(code *)PTR_FUN_0601bcc8)();
  puVar7 = PTR_DAT_0601bcd4;
  puVar6 = PTR_DAT_0601bcd0;
  puVar5 = PTR_DAT_0601bccc;
  for (uVar14 = (uint)param_2; (int)(uVar14 & 0xffff) < param_2 + 5; uVar14 = uVar14 + 1) {
    local_28 = (param_3 & 0xffff) * 0x40;
    (*(code *)puVar4)(8,(local_28 + 2) * 2,0x60,
                      *(undefined4 *)(PTR_PTR_0601bcd8 + (uVar14 & 0xffff) * 4));
    pcVar12 = (char *)((uVar14 & 0xffff) * 0xc + unaff_r9);
    (*(code *)puVar4)(8,(local_28 + 9) * 2,0x60,auStack_8);
    if (*pcVar12 != '\0') {
      (*(code *)puVar4)(8,((param_3 & 0xffff) * 0x40 + 9) * 2,0x60,pcVar12);
    }
    iVar8 = (uVar14 & 0xffff) * 0xc + unaff_r9;
    uVar9 = (*(code *)PTR_FUN_0601bcdc)(*(undefined4 *)(iVar8 + 4));
    (*(code *)puVar4)(8,((param_3 & 0xffff) * 0x40 + 0x10) * 2,0x78,uVar9);
    bVar13 = *(byte *)(iVar8 + 8);
    bVar2 = 0xb < bVar13;
    if (bVar2) {
      bVar13 = bVar13 - 0xc;
    }
    if (9 < bVar13) {
      local_28 = 0x2000000;
    }
    iVar8 = (param_3 & 0xffff) * 0x40;
    (*(code *)puVar3)(8,*(undefined4 *)
                         (PTR_DAT_0601bd68 + ((local_28 >> 0x18) + (uint)bVar2 + 0x3c) * 8),
                      (iVar8 + 0x21) * 2,
                      (uint)bVar13 * 0x1000 +
                      *(int *)((int)(PTR_DAT_0601bd68 +
                                    ((local_28 >> 0x18) + (uint)bVar2 + 0x3c) * 8) + 4));
    (*(code *)puVar4)(0xc,(iVar8 + 0x25) * 2,0x60,PTR_PTR_0601bd6c);
    if (*(char *)((uVar14 & 0xffff) * 0xc + unaff_r9 + 10) != '\0') {
      if (*(int *)PTR_DAT_0601bd70 == 1) {
        iVar8 = *(int *)(puVar5 + 4);
        puVar10 = (undefined4 *)puVar5;
      }
      else {
        iVar8 = *(int *)(puVar6 + 4);
        puVar10 = (undefined4 *)puVar6;
      }
      (*(code *)puVar3)(0xc,*puVar10,((param_3 & 0xffff) * 0x40 + 0x25) * 2,iVar8 + iVar11);
    }
    cVar1 = *(char *)((uVar14 & 0xffff) * 0xc + unaff_r9 + 9);
    iVar8 = (int)cVar1;
    if (cVar1 != '\0') {
      iVar8 = (*(code *)puVar3)(0xc,*(undefined4 *)puVar7,((param_3 & 0xffff) * 0x40 + 0x28) * 2,
                                PTR_DAT_0601bde8 + *(int *)(puVar7 + 4));
    }
    param_3 = param_3 + 3;
  }
  return iVar8;
}

