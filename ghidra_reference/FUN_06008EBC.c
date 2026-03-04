/* FUN_06008EBC  0x06008EBC */


void FUN_06008ebc(void)

{
  ushort uVar1;
  undefined *puVar2;
  
  (*(code *)PTR_FUN_06008f3c)();
  *PTR_DAT_06008f40 = 0;
  *PTR_DAT_06008f44 = 1;
  *(undefined4 *)PTR_DAT_06008f48 = 8;
  if ((((undefined *)(uint)*(ushort *)PTR_DAT_06008f4c == PTR_DAT_06008f50) && (*DAT_06008f54 == 0))
     && (*DAT_06008f58 == '\0')) {
    uVar1 = *(ushort *)PTR_DAT_06008f5c;
    if ((uVar1 & *(ushort *)PTR_DAT_06008f64) == 0) {
      if ((uVar1 & *(ushort *)PTR_DAT_06008f68) == 0) {
        if ((uVar1 & *(ushort *)PTR_DAT_06008f6c) == 0) {
          if ((uVar1 & *(ushort *)PTR_DAT_0600902c) != 0) {
            *PTR_DAT_06008f60 = 3;
          }
        }
        else {
          *PTR_DAT_06008f60 = 2;
        }
      }
      else {
        *PTR_DAT_06008f60 = 1;
      }
    }
    else {
      *PTR_DAT_06008f60 = 0;
    }
  }
  (*(code *)PTR_FUN_06009030)();
  (*(code *)PTR_FUN_06009034)();
  puVar2 = PTR_DAT_06009038;
  *PTR_DAT_06009038 = 3;
  if ((*PTR_DAT_0600903c == '\0') && (*(short *)PTR_DAT_06009040 != 0)) {
    *puVar2 = 4;
  }
  (*(code *)PTR_FUN_06009044)();
  (*(code *)PTR_FUN_0600904c)(*PTR_DAT_06009048);
  (*(code *)PTR_FUN_06009050)();
  (*(code *)PTR_FUN_06009054)();
  *(int *)PTR_DAT_06009058 = (int)PTR_DAT_06009028._0_2_;
  (*(code *)PTR_FUN_06009064)(*(undefined4 *)(PTR_PTR_06009060 + *(int *)PTR_DAT_0600905c * 4));
  (*(code *)PTR_FUN_06009068)();
  (*(code *)PTR_FUN_0600906c)();
  (*(code *)PTR_FUN_06009070)();
  if (*DAT_06009074 != '\0') {
    (*(code *)PTR_FUN_06009078)(1);
  }
  *(undefined4 *)PTR_DAT_0600907c = 0xf;
  *(uint *)PTR_DAT_06009080 = *(uint *)PTR_DAT_06009080 | DAT_06009084;
  (*(code *)PTR_FUN_06009088)();
  *(undefined4 *)PTR_DAT_0600908c = 0;
  *(undefined2 *)PTR_DAT_06009090 = 3;
  *PTR_DAT_06009094 = 0;
  return;
}

