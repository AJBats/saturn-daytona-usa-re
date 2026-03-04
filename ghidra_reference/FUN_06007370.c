/* FUN_06007370  0x06007370 */


void FUN_06007370(void)

{
  undefined *puVar1;
  undefined4 in_r3;
  
  puVar1 = PTR_DAT_06007420;
  *(undefined4 *)PTR_DAT_06007424 = in_r3;
  *(int *)PTR_DAT_06007428 = (int)DAT_06007412;
  (*(code *)PTR_FUN_0600742c)(puVar1);
  (*(code *)PTR_FUN_06007430)(0,2);
  (*(code *)PTR_FUN_06007434)(0,0,0,(int)DAT_06007416,(int)DAT_06007414);
  (*(code *)PTR_FUN_0600743c)(PTR_DAT_06007438);
  (*(code *)PTR_FUN_06007440)();
  (*(code *)PTR_FUN_0600744c)
            (*(int *)PTR_PTR_06007448 * 8 + *(int *)puVar1,PTR_DAT_06007444,(int)DAT_06007418);
  if ((*(uint *)PTR_DAT_06007450 & 1) != 0) {
    (*(code *)PTR_FUN_0600744c)
              (*(int *)PTR_PTR_06007448 * 8 + *(int *)puVar1 + (int)PTR_DAT_0600741c._0_2_,
               PTR_DAT_06007454,(int)DAT_0600741a);
  }
  (*(code *)PTR_FUN_0600745c)(*(undefined4 *)puVar1,PTR_PTR_06007458,0x60);
  *(undefined4 *)PTR_DAT_06007460 = 3;
  *(short *)(*(int *)puVar1 + 0x60) = (short)PTR_DAT_06007464;
  (*(code *)PTR_FUN_06007468)();
  (*(code *)PTR_FUN_06007474)(PTR_DAT_06007470,PTR_DAT_0600746c);
  (*(code *)PTR_FUN_06007478)();
  return;
}

