/* FUN_0601B170  0x0601B170 */


void FUN_0601b170(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined1 uVar4;
  undefined *puVar5;
  undefined *puVar6;
  int iVar7;
  int unaff_r8;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  *(int *)PTR_DAT_0601b268 = unaff_r8;
  *(int *)PTR_DAT_0601b26c = (int)DAT_0601b246;
  (*(code *)PTR_FUN_0601b274)(PTR_DAT_0601b270);
  iVar3 = (int)DAT_0601b248;
  (*(code *)PTR_FUN_0601b278)();
  *(int *)PTR_DAT_0601b27c = unaff_r8;
  **(undefined2 **)PTR_DAT_0601b270 = (short)PTR_DAT_0601b280;
  (*(code *)PTR_FUN_0601b284)();
  puVar1 = PTR_DAT_0601b288;
  (*(code *)PTR_FUN_0601b290)
            (*(int *)PTR_PTR_0601b28c * 8 + *(int *)PTR_DAT_0601b270,PTR_DAT_0601b288,
             (int)DAT_0601b24c);
  puVar5 = PTR_FUN_0601b294;
  iVar9 = (int)DAT_0601b24e;
  iVar11 = (int)DAT_0601b250;
  puVar6 = puVar1 + DAT_0601b252;
  (*(code *)PTR_FUN_0601b294)(iVar9,iVar11,0x78,puVar6,iVar3);
  iVar10 = (int)DAT_0601b254;
  iVar3 = (int)DAT_0601b256;
  (*(code *)puVar5)(iVar10,iVar11,0x7c);
  iVar8 = (int)DAT_0601b258;
  iVar7 = (int)DAT_0601b25a;
  (*(code *)puVar5)(iVar8,iVar11,(int)DAT_0601b25c);
  puVar2 = PTR_FUN_0601b298;
  (*(code *)PTR_FUN_0601b298)((int)DAT_0601b260,iVar9,(int)DAT_0601b25e);
  (*(code *)puVar2)(DAT_0601b262 + 0x7d,iVar10);
  (*(code *)puVar2)(PTR_DAT_0601b264._0_2_ + 0x7a,iVar8);
  (*(code *)puVar5)(iVar9,iVar11,0x78,puVar6);
  (*(code *)puVar5)(iVar10,iVar11,0x7c,puVar1 + iVar3);
  (*(code *)puVar5)(iVar8,iVar11,(int)DAT_0601b25c,puVar1 + iVar7);
  (*(code *)puVar2)((int)DAT_0601b260,iVar9,(int)DAT_0601b25e);
  (*(code *)puVar2)(DAT_0601b262 + 0x7d,iVar10);
  (*(code *)puVar2)(DAT_0601b38a + 0x7a,iVar8);
  (*(code *)puVar5)(iVar9,iVar11,0x78,puVar6);
  (*(code *)puVar5)(iVar10,iVar11,0x7c,puVar1 + iVar3);
  (*(code *)puVar5)(iVar8,iVar11,(int)DAT_0601b38c,puVar1 + iVar7);
  (*(code *)puVar2)((int)DAT_0601b390,iVar9,(int)DAT_0601b38e);
  (*(code *)puVar2)(DAT_0601b392 + 0x7d,iVar10);
  (*(code *)puVar2)(DAT_0601b38a + 0x7a,iVar8);
  *(short *)PTR_DAT_0601b398 = (short)unaff_r8;
  puVar5 = PTR_FUN_0601b3a4;
  puVar1 = PTR_DAT_0601b39c;
  *(uint *)PTR_DAT_0601b39c = *(uint *)PTR_DAT_0601b39c | DAT_0601b3a0;
  (*(code *)puVar5)();
  (*(code *)PTR_FUN_0601b3a4)();
  (*(code *)PTR_FUN_0601b3b0)(PTR_DAT_0601b3ac,PTR_DAT_0601b3a8,0x40);
  (*(code *)PTR_FUN_0601b3b0)(PTR_DAT_0601b3b8,PTR_DAT_0601b3b4,0x20);
  (*(code *)PTR_FUN_0601b3c4)(PTR_DAT_0601b3c0,PTR_DAT_0601b3bc);
  puVar5 = PTR_DAT_0601b3c8 + unaff_r8;
  (*(code *)PTR_FUN_0601b3d0)(PTR_DAT_0601b3cc);
  (*(code *)PTR_FUN_0601b3d8)(4,puVar5);
  (*(code *)PTR_FUN_0601b3dc)(0x10);
  (*(code *)PTR_FUN_0601b3dc)(0x20);
  puVar5 = PTR_FUN_0601b3e0;
  (*(code *)PTR_FUN_0601b3e0)((int)PTR_DAT_0601b394._0_2_,7);
  (*(code *)puVar5)(4);
  (*(code *)puVar5)(8,1);
  (*(code *)puVar5)(0x10,6);
  (*(code *)puVar5)(0x20,5);
  (*(code *)puVar5)(1);
  (*(code *)PTR_FUN_0601b3e4)(0xc);
  (*(code *)PTR_FUN_0601b3e8)();
  *(uint *)puVar1 = *(uint *)puVar1 | DAT_0601b3ec;
  uVar4 = (undefined1)unaff_r8;
  *PTR_DAT_0601b3f0 = uVar4;
  *PTR_DAT_0601b45c = uVar4;
  *PTR_DAT_0601b460 = uVar4;
  (*(code *)PTR_FUN_0601b464)(4,4,0xf);
  return;
}

