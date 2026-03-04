/* FUN_060120CC  0x060120CC */


void FUN_060120cc(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined1 in_r3;
  
  *PTR_DAT_06012150 = in_r3;
  *(undefined4 *)PTR_DAT_06012154 = 0;
  (*(code *)PTR_FUN_06012158)(0x20,0,0);
  puVar1 = PTR_DAT_0601215c;
  *(undefined4 *)PTR_DAT_0601215c = 0;
  puVar2 = PTR_DAT_06012160;
  *(undefined **)(puVar1 + 4) = PTR_DAT_06012160;
  *(undefined **)(puVar1 + 8) = PTR_DAT_06012164;
  puVar1 = PTR_DAT_06012168;
  *(undefined4 *)PTR_DAT_06012168 = 0;
  *(uint *)(puVar1 + 4) = (uint)puVar2 >> 2;
  *(undefined **)(puVar1 + 8) = PTR_DAT_0601216c;
  (*(code *)PTR_FUN_06012174)();
  (*(code *)PTR_FUN_06012174)();
  (*(code *)PTR_FUN_06012174)();
  *(undefined2 *)PTR_DAT_06012180 = DAT_0601214e;
  *(undefined2 *)PTR_DAT_06012184 = 0;
  *PTR_DAT_06012188 = 0;
  puVar1 = PTR_DAT_0601218c;
  if (*(int *)PTR_DAT_06012194 == 0) {
    *(undefined4 *)PTR_DAT_06012190 = 0x3c;
    *(undefined4 *)puVar1 = 0;
    return;
  }
  *(undefined4 *)PTR_DAT_06012190 = 1;
  *(undefined4 *)puVar1 = 0x14;
  FUN_0601228a();
  return;
}

