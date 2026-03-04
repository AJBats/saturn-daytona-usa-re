/* FUN_06009098  0x06009098 */


void FUN_06009098(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  byte bVar8;
  
  puVar5 = PTR_DAT_0600912c;
  puVar4 = PTR_DAT_06009128;
  puVar3 = PTR_DAT_06009124;
  puVar2 = PTR_DAT_06009120;
  puVar1 = PTR_DAT_0600911c;
  if ((*(ushort *)PTR_DAT_06009130 & DAT_0600911a) != 0) {
    *(undefined4 *)PTR_DAT_06009134 = 0xf;
    *(undefined4 *)puVar3 = 0x12;
  }
  *(int *)PTR_DAT_06009138 = *(int *)PTR_DAT_06009138 + -1;
  if (*DAT_0600913c != '\0') {
    (*(code *)PTR_FUN_06009140)(0);
  }
  if (*(short *)puVar4 != 0) {
    (*(code *)PTR_FUN_06009144)();
  }
  puVar6 = PTR_DAT_06009148;
  for (bVar8 = 0; bVar8 < (byte)*PTR_DAT_06009248; bVar8 = bVar8 + 1) {
    if (*PTR_DAT_0600914c != '\0') {
      if (bVar8 == 0) {
        *(undefined2 *)puVar4 = 1;
        *(undefined **)puVar5 = puVar6;
        *(undefined **)puVar2 = puVar6;
      }
      else {
        *(undefined2 *)puVar4 = 0;
        puVar7 = PTR_DAT_06009224;
        *(undefined **)puVar5 = PTR_DAT_06009224;
        *(undefined **)puVar2 = puVar7;
        *(int *)puVar1 = *(int *)puVar1 + -2;
      }
    }
    (*(code *)PTR_FUN_06009228)();
    (*(code *)PTR_FUN_0600922c)();
    (*(code *)PTR_FUN_06009230)();
    (*(code *)PTR_FUN_06009234)();
    if (*(int *)PTR_DAT_06009238 == 0) {
      if (*(int *)PTR_DAT_06009244 == 0) {
        *(undefined4 *)puVar3 = 0x10;
      }
    }
    else {
      (*(code *)PTR_FUN_0600923c)();
      if (*(int *)PTR_DAT_06009240 == 0) {
        *(undefined4 *)puVar3 = 0x10;
      }
    }
  }
  if (*PTR_DAT_0600924c == '\0') {
    (*(code *)PTR_FUN_06009254)();
  }
  else {
    (*(code *)PTR_FUN_06009250)();
  }
  (*(code *)PTR_FUN_06009258)();
  if (*PTR_DAT_0600925c == '\x01') {
    (*(code *)PTR_FUN_06009260)();
    (*(code *)PTR_FUN_06009270)(PTR_DAT_0600926c,PTR_DAT_06009268,*(undefined4 *)PTR_DAT_06009264);
  }
  else {
    (*(code *)PTR_FUN_06009274)();
  }
  (*(code *)PTR_FUN_06009278)();
  if (*PTR_DAT_0600927c != '\0') {
    (*(code *)PTR_FUN_06009288)(8,(int)DAT_06009222,PTR_DAT_06009284,PTR_DAT_06009280);
  }
  (*(code *)PTR_FUN_0600928c)();
  return;
}

