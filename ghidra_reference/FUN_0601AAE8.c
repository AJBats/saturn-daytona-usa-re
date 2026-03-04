/* FUN_0601AAE8  0x0601AAE8 */


void FUN_0601aae8(void)

{
  undefined *puVar1;
  
  if ((*(ushort *)PTR_DAT_0601ab50 & DAT_0601ab4e) != 0) {
    *(undefined4 *)PTR_DAT_0601ab54 = 0x1e;
    *PTR_DAT_0601ab58 = 1;
    *PTR_DAT_0601ab5c = 0;
    *PTR_DAT_0601ab60 = 0;
    *PTR_DAT_0601ab64 = 1;
    *PTR_DAT_0601ab68 = 0;
    *PTR_DAT_0601ab6c = 0;
    (*(code *)PTR_FUN_0601ab70)(0xc);
    puVar1 = PTR_FUN_0601ab78;
    *(uint *)PTR_DAT_0601ab74 = *(uint *)PTR_DAT_0601ab74 | 4;
    (*(code *)puVar1)();
    (*(code *)PTR_FUN_0601ab7c)();
    (*(code *)PTR_FUN_0601ab84)(0xf,DAT_0601ab80);
    (*(code *)PTR_FUN_0601ab88)();
    return;
  }
  return;
}

