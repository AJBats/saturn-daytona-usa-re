/* FUN_06009A60  0x06009A60 */


void FUN_06009a60(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  byte bVar4;
  int iVar5;
  undefined4 in_r7;
  int iVar6;
  undefined1 uVar7;
  
  puVar3 = PTR_PTR_06009b1c;
  puVar2 = PTR_DAT_06009b18;
  puVar1 = PTR_DAT_06009b14;
  iVar6 = *(int *)PTR_DAT_06009b18;
  (*(code *)PTR_FUN_06009b20)();
  (*(code *)PTR_FUN_06009b24)();
  FUN_06009ffc();
  iVar5 = (char)*PTR_DAT_06009b28 + 10;
  (*(code *)PTR_FUN_06009b2c)(iVar5,iVar5,0,in_r7,iVar5);
  iVar5 = (int)PTR_DAT_06009b10._0_2_;
  *puVar1 = (char)*(undefined4 *)(*(int *)puVar2 + iVar5);
  *(undefined4 *)PTR_DAT_06009b30 = *(undefined4 *)(*(int *)puVar2 + iVar5 + 0x1c);
  *(undefined4 *)PTR_DAT_06009b38 = *(undefined4 *)PTR_DAT_06009b34;
  if ((((*PTR_DAT_06009b3c != '\0') && (1 < *(int *)PTR_DAT_06009b40)) && (*puVar1 == '\0')) &&
     (*(int *)PTR_DAT_06009b44 == 0)) {
    *puVar3 = *puVar3 | 8;
  }
  if (((*PTR_DAT_06009b48 != '\0') && (1 < *(int *)PTR_DAT_06009b4c)) &&
     (*(int *)PTR_DAT_06009b44 == 0)) {
    if ((char)*puVar1 < '\x03') {
      iVar5 = *(int *)PTR_DAT_06009b54;
      if (iVar5 == 0) {
        bVar4 = *PTR_DAT_06009b50 | 1;
LAB_06009b66:
        *PTR_DAT_06009b50 = bVar4;
      }
      else if (iVar5 == 1) {
        *PTR_DAT_06009b50 = *PTR_DAT_06009b50 | 2;
      }
      else if (iVar5 == 2) {
        bVar4 = *PTR_DAT_06009b50 | 4;
        goto LAB_06009b66;
      }
    }
    if (*puVar1 == '\0') {
      iVar5 = *(int *)PTR_DAT_06009c28;
      if (iVar5 == 0) {
        bVar4 = *puVar3 | 1;
LAB_06009b98:
        *puVar3 = bVar4;
      }
      else if (iVar5 == 1) {
        *puVar3 = *puVar3 | 2;
      }
      else if (iVar5 == 2) {
        bVar4 = *puVar3 | 4;
        goto LAB_06009b98;
      }
    }
  }
  FUN_0600a1b8();
  if ((*(byte *)(iVar6 + 3) & 8) == 0) {
    iVar5 = *(int *)PTR_DAT_06009c28;
    uVar7 = 0;
    if (iVar5 == 0) {
      if (*(int *)(iVar6 + 0x18) < DAT_06009c30) {
        *PTR_DAT_06009c2c = 0;
        goto LAB_06009bfa;
      }
    }
    else {
      if (iVar5 != 1) {
        if (iVar5 != 2) goto LAB_06009bfa;
        goto LAB_06009bf8;
      }
      if (DAT_06009c34 < *(int *)(iVar6 + 0x10)) {
        *PTR_DAT_06009c2c = 0;
        goto LAB_06009bfa;
      }
    }
    *PTR_DAT_06009c2c = 1;
  }
  else {
    uVar7 = 2;
LAB_06009bf8:
    *PTR_DAT_06009c2c = uVar7;
  }
LAB_06009bfa:
  *(undefined4 *)(*(int *)puVar2 + 0x40) = 0;
  *(undefined4 *)PTR_DAT_06009c38 = 0x15;
  *(undefined4 *)PTR_DAT_06009c3c = 0x56;
  *PTR_DAT_06009c40 = 4;
  *(undefined2 *)PTR_DAT_06009c44 = 4;
  return;
}

