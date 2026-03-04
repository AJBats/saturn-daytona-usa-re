/* FUN_0601FFB8  0x0601FFB8 */


void FUN_0601ffb8(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined2 unaff_r9;
  ushort *puVar7;
  int iVar8;
  
  puVar2 = PTR_DAT_06020070;
  puVar1 = PTR_DAT_0602006c;
  iVar6 = (int)PTR_DAT_06020064._0_2_;
  puVar7 = (ushort *)((uint)*(ushort *)PTR_DAT_06020070 * 8 + *(int *)PTR_DAT_06020074);
  do {
    puVar3 = PTR_DAT_06020084;
    if (*(ushort *)puVar1 <= *puVar7) {
LAB_0602003e:
      if (*(int *)PTR_DAT_0602008c == 0x17) {
        FUN_060201b8();
      }
      *(short *)puVar1 = *(short *)puVar1 + 1;
      return;
    }
    if ((short)puVar7[1] < 0) {
      *(undefined4 *)PTR_DAT_0602007c =
           *(undefined4 *)((uint)puVar7[2] * 4 + *(int *)PTR_DAT_06020078);
      *(undefined2 *)PTR_DAT_06020080 = unaff_r9;
      goto LAB_0602003e;
    }
    iVar8 = (short)puVar7[1] * iVar6;
    uVar4 = (*(code *)PTR_FUN_06020088)((int)PTR_DAT_06020064._2_2_,(uint)puVar7[2] << 0x10);
    *(undefined4 *)(puVar3 + sRam06020068 + iVar8) = uVar4;
    iVar5 = (int)sRam0602006a;
    *(uint *)(puVar3 + iVar5 + iVar8) = (uint)puVar7[3];
    *(int *)(puVar3 + iVar5 + 0xc + iVar8) = iVar6 + -0x68;
    *(short *)puVar2 = *(short *)puVar2 + 1;
    puVar7 = puVar7 + 4;
  } while( true );
}

