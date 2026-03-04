/* FUN_060193FE  0x060193FE */


void FUN_060193fe(undefined1 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined1 in_r0;
  undefined1 in_r3;
  
  *PTR_DAT_060194b0 = in_r3;
  *PTR_DAT_060194b4 = param_1;
  *PTR_DAT_060194b8 = in_r0;
  *PTR_DAT_060194bc = param_1;
  *PTR_DAT_060194c0 = param_1;
  *PTR_DAT_060194c4 = param_1;
  (*(code *)PTR_FUN_060194cc)(0xf,DAT_060194c8);
  puVar2 = PTR_FUN_060194d8;
  puVar1 = PTR_DAT_060194d0;
  *(uint *)PTR_DAT_060194d0 = *(uint *)PTR_DAT_060194d0 | DAT_060194d4;
  (*(code *)puVar2)();
  (*(code *)PTR_FUN_060194d8)();
  FUN_0601938c();
  (*(code *)PTR_FUN_060194dc)();
  (*(code *)PTR_FUN_060194e8)(PTR_DAT_060194e4,PTR_DAT_060194e0,0,9);
  (*(code *)PTR_FUN_060194e8)(PTR_DAT_060194f0,PTR_DAT_060194ec,0,8);
  puVar2 = PTR_FUN_060194f4;
  (*(code *)PTR_FUN_060194f4)(8,0);
  (*(code *)puVar2)(0x10,0);
  (*(code *)puVar2)(0x20,0);
  (*(code *)PTR_FUN_060194f8)(4);
  (*(code *)PTR_FUN_060194f8)(0xc);
  puVar2 = PTR_FUN_060194fc;
  *(uint *)puVar1 = *(uint *)puVar1 | 4;
  (*(code *)puVar2)();
  (*(code *)PTR_FUN_06019508)
            (4,*(undefined4 *)PTR_DAT_06019500,0,PTR_DAT_06019504 + *(int *)(PTR_DAT_06019500 + 4),
             PTR_DAT_06019500);
  FUN_06019324();
  return;
}

