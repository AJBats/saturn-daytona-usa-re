/* FUN_0601A344  0x0601A344 */


void FUN_0601a344(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = PTR_FUN_0601a3c0;
  puVar2 = PTR_DAT_0601a3c4;
  (*(code *)PTR_FUN_0601a3c0)(PTR_DAT_0601a3c8,PTR_DAT_0601a3c4,0x60);
  (*(code *)puVar1)(PTR_DAT_0601a3cc,puVar2,0x60);
  (*(code *)puVar1)(PTR_DAT_0601a3d4,PTR_PTR_0601a3d0,0x40);
  (*(code *)PTR_FUN_0601a3d8)();
  if (*(short *)PTR_DAT_0601a3dc == 0x10) {
    (*(code *)PTR_FUN_0601a3e4)
              (4,*(undefined4 *)PTR_DAT_0601a3e0,0,*(undefined4 *)(PTR_DAT_0601a3e0 + 4),
               PTR_DAT_0601a3e0);
  }
  else {
    (*(code *)PTR_FUN_0601a3e4)
              (4,*(undefined4 *)PTR_DAT_0601a3e8,0,
               *(int *)(PTR_DAT_0601a3e8 + 4) + (int)DAT_0601a3be,PTR_DAT_0601a3e8);
  }
  (*(code *)PTR_FUN_0601a3ec)();
  *PTR_DAT_0601a3f0 = *PTR_DAT_0601a3f0 + '\x01';
  return;
}

