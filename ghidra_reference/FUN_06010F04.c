/* FUN_06010F04  0x06010F04 */


undefined4 FUN_06010f04(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined4 uVar8;
  int iVar9;
  undefined2 *puVar10;
  
  iVar9 = *(int *)PTR_DAT_06010f30;
  uVar8 = (*(code *)PTR_FUN_06010f34)();
  puVar1 = PTR_FUN_0601101c;
  if (*(uint *)PTR_DAT_06010f38 < 10) {
    (*(code *)PTR_FUN_0601101c)
              (*(undefined4 *)PTR_DAT_06011028,*(undefined4 *)PTR_DAT_06011024,
               *(undefined4 *)PTR_DAT_06011020);
    (*(code *)PTR_FUN_06011030)((int)*(short *)PTR_DAT_0601102c);
    puVar4 = PTR_FUN_0601103c;
    puVar3 = PTR_DAT_06011038;
    puVar2 = PTR_PTR_06011034;
    (*(code *)PTR_FUN_0601103c)(*(undefined4 *)PTR_PTR_06011034,*(undefined4 *)PTR_DAT_06011038);
    puVar5 = PTR_FUN_06011040;
    puVar10 = (undefined2 *)(PTR_DAT_06011048 + iVar9 * 2);
    (*(code *)PTR_FUN_06011040)
              (*(undefined4 *)PTR_PTR_0601104c,*puVar10,*(undefined4 *)PTR_DAT_06011044);
    (*(code *)PTR_FUN_06011050)();
    (*(code *)puVar1)(*(undefined4 *)PTR_PTR_06011054,*(undefined4 *)(PTR_PTR_06011054 + 4),
                      -*(int *)(PTR_PTR_06011054 + 8));
    (*(code *)puVar4)(*(undefined4 *)(puVar2 + 4),*(undefined4 *)(puVar3 + 4));
    (*(code *)puVar5)(*(undefined4 *)PTR_PTR_0601105c,*puVar10,*(undefined4 *)PTR_DAT_06011058);
    puVar7 = PTR_DAT_06011060;
    puVar6 = PTR_FUN_06011050;
    *(int *)PTR_DAT_06011060 = *(int *)PTR_DAT_06011060 + -0x30;
    (*(code *)puVar6)();
    (*(code *)puVar1)(*(undefined4 *)PTR_DAT_0601106c,*(undefined4 *)PTR_PTR_06011068,
                      -*(int *)PTR_PTR_06011064);
    (*(code *)puVar4)(*(undefined4 *)(puVar2 + 8),*(undefined4 *)(puVar3 + 8));
    (*(code *)puVar5)(*(undefined4 *)PTR_PTR_06011074,*puVar10,*(undefined4 *)PTR_DAT_06011070);
    puVar6 = PTR_FUN_06011050;
    *(int *)puVar7 = *(int *)puVar7 + -0x30;
    (*(code *)puVar6)();
    (*(code *)puVar1)(*(undefined4 *)PTR_DAT_06011080,*(undefined4 *)PTR_PTR_0601107c,
                      -*(int *)PTR_DAT_06011078);
    (*(code *)puVar4)(*(undefined4 *)(puVar2 + 0xc),*(undefined4 *)(puVar3 + 0xc));
    uVar8 = (*(code *)puVar5)(*(undefined4 *)PTR_PTR_06011088,*puVar10,
                              *(undefined4 *)PTR_DAT_06011084);
    *(int *)puVar7 = *(int *)puVar7 + -0x30;
  }
  *(short *)PTR_DAT_06011090 = (short)PTR_DAT_0601108c;
  return uVar8;
}

