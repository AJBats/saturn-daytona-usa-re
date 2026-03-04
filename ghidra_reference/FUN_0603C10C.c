/* FUN_0603C10C  0x0603C10C */


void FUN_0603c10c(void)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  int unaff_r13;
  
  puVar1 = PTR_DAT_0603c17c;
  FUN_0603cd5c();
  (*(code *)PTR_FUN_0603c180)();
  (*(code *)PTR_FUN_0603c184)();
  (*(code *)PTR_FUN_0603c188)();
  (*(code *)PTR_FUN_0603c18c)();
  (*(code *)PTR_FUN_0603c190)();
  uVar3 = 0;
  do {
    uVar2 = uVar3 & 0xff;
    uVar3 = uVar3 + 1;
    *(undefined4 *)(puVar1 + uVar2 * 4) = 0;
  } while ((int)(uVar3 & 0xff) < unaff_r13);
  *(undefined4 *)PTR_DAT_0603c194 = 0;
  *PTR_DAT_0603c198 = 0;
  return;
}

