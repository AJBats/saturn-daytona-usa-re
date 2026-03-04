/* FUN_06020814  0x06020814 */


void FUN_06020814(undefined1 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  (*(code *)PTR_FUN_06020900)();
  (*(code *)PTR_FUN_06020904)();
  (*(code *)PTR_FUN_06020910)(PTR_DAT_0602090c,PTR_DAT_06020908,0x20);
  puVar2 = PTR_FUN_06020918;
  puVar1 = PTR_DAT_06020914;
  (*(code *)PTR_FUN_06020918)
            (0,*(undefined4 *)(PTR_DAT_06020914 + DAT_060208e6),(int)DAT_060208e8,
             *(undefined4 *)((int)(PTR_DAT_06020914 + DAT_060208e6) + 4));
  puVar3 = PTR_DAT_0602091c;
  *(uint *)PTR_DAT_0602091c = *(uint *)PTR_DAT_0602091c | (uint)PTR_DAT_06020920;
  *(undefined2 *)PTR_DAT_06020924 = 1;
  *(undefined4 *)PTR_DAT_06020928 = 0;
  (*(code *)PTR_FUN_0602092c)();
  *(uint *)puVar3 = *(uint *)puVar3 | (uint)PTR_DAT_06020920;
  *(undefined2 *)PTR_DAT_06020924 = 3;
  *(undefined4 *)PTR_DAT_06020928 = 0;
  (*(code *)PTR_FUN_0602092c)();
  (*(code *)puVar2)(4,*(undefined4 *)(puVar1 + DAT_060208ea),(int)DAT_060208ee,
                    *(int *)((int)(puVar1 + DAT_060208ea) + 4) + (int)DAT_060208ec);
  (*(code *)puVar2)(4,PTR_PTR_06020930,(int)DAT_060208f2,(int)DAT_060208f0);
  (*(code *)puVar2)(4,*(undefined4 *)(puVar1 + DAT_060208f4),(int)DAT_060208f8,
                    *(int *)((int)(puVar1 + DAT_060208f4) + 4) + (int)DAT_060208f6);
  (*(code *)puVar2)(4,*(undefined4 *)(puVar1 + DAT_060208fa),(int)DAT_060208fe,
                    *(int *)((int)(puVar1 + DAT_060208fa) + 4) + (int)DAT_060208fc);
  (*(code *)PTR_FUN_06020934)(0xc);
  *(undefined2 *)PTR_DAT_06020938 = 0;
  FUN_06020dee(param_1);
  return;
}

