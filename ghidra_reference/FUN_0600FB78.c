/* FUN_0600FB78  0x0600FB78 */


void FUN_0600fb78(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  puVar1 = PTR_DAT_0600fc3c;
  (*(code *)PTR_FUN_0600fc40)();
  (*(code *)PTR_FUN_0600fc44)();
  puVar3 = PTR_DAT_0600fd44;
  puVar4 = PTR_FUN_0600fc50;
  puVar2 = PTR_FUN_0600fc4c;
  if (*PTR_DAT_0600fc48 == '\0') {
    (*(code *)PTR_FUN_0600fd4c)(1);
    if (*(short *)(puVar1 + 6) == 0x10) {
      FUN_06010470();
    }
    else {
      FUN_060103b8((int)*(short *)(puVar1 + 2));
    }
  }
  else {
    iVar6 = (int)DAT_0600fc2c;
    iVar7 = (int)DAT_0600fc2e;
    if (*(int *)PTR_DAT_0600fc54 == 0) {
      iVar5 = (int)DAT_0600fc30;
      (*(code *)PTR_FUN_0600fc50)(0xc,(int)DAT_0600fc32,iVar5,PTR_s_ACCELERATION_0600fc58);
      puVar3 = PTR_DAT_0600fc5c;
      (*(code *)puVar4)(0xc,(int)DAT_0600fc34,iVar5,
                        *(undefined4 *)(PTR_DAT_0600fc60 + *(int *)PTR_DAT_0600fc5c * 4));
      (*(code *)puVar4)(0xc,(int)DAT_0600fc36,iVar5,PTR_DAT_0600fc64);
      (*(code *)puVar4)(0xc,(int)PTR_DAT_0600fc38._0_2_,iVar5,
                        *(undefined4 *)(PTR_PTR_0600fc68 + *(int *)puVar3 * 4));
      if (9 < *(uint *)puVar3) {
        if (*(uint *)puVar3 < 0xc) {
          puVar4 = PTR_s_HORSE_0600fd3c;
          if (*(int *)PTR_DAT_0600fc6c == 1) {
            puVar4 = PTR_s_DAYTONA_UMA_0600fc78;
          }
          (*(code *)puVar2)(0xc,iVar7,iVar6,puVar4);
        }
        else {
          puVar4 = PTR_s_HORSE_2_0600fc74;
          if (*(int *)PTR_DAT_0600fc6c == 1) {
            puVar4 = PTR_s_DAYTONA_UMA2_0600fc70;
          }
          (*(code *)puVar2)(0xc,iVar7,iVar6,puVar4);
        }
      }
      if (*(short *)(puVar1 + 6) == 0x10) {
        if (*(int *)PTR_DAT_0600fd40 == 0) {
          FUN_06010760();
        }
        else {
          *(int *)PTR_DAT_0600fd40 = *(int *)PTR_DAT_0600fd40 + -1;
        }
      }
      else {
        FUN_060104e0((int)*(short *)(puVar1 + 2));
      }
    }
    else {
      (*(code *)PTR_FUN_0600fc50)(0xc,(int)DAT_0600fd36,0,PTR_DAT_0600fd44);
      (*(code *)puVar4)(0xc,(int)DAT_0600fd38,0,puVar3);
      (*(code *)puVar2)(0xc,iVar7,iVar6,PTR_DAT_0600fd48);
    }
  }
  if ((*(ushort *)puVar1 & DAT_0600fd3a) == 0) {
    *(undefined4 *)PTR_DAT_0600fd50 = 0;
  }
  else {
    *(undefined4 *)PTR_DAT_0600fd50 = 1;
  }
  FUN_06010aa4((int)*(short *)(puVar1 + 2));
  return;
}

