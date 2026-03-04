/* FUN_060096DC  0x060096DC */


void FUN_060096dc(void)

{
  undefined *puVar1;
  
  FUN_06009ffc();
  *(undefined4 *)PTR_DAT_06009750 = 0x13;
  puVar1 = PTR_DAT_06009754;
  *PTR_DAT_06009758 = *PTR_DAT_06009754;
  *puVar1 = 0;
  *(undefined2 *)PTR_DAT_0600975c = 0;
  (*(code *)PTR_FUN_06009764)(8,(int)DAT_0600974a,(int)DAT_06009748,PTR_s_PAUSE_06009760);
  puVar1 = PTR_PTR_06009768;
  (*(code *)PTR_FUN_06009770)(8,(int)DAT_0600974c,PTR_DAT_0600976c,PTR_PTR_06009768 + 0x2e);
  (*(code *)PTR_FUN_06009770)(8,(int)DAT_0600974e,PTR_DAT_0600976c,puVar1 + 0x2f);
  puVar1 = PTR_FUN_06009778;
  *(uint *)PTR_DAT_06009774 = *(uint *)PTR_DAT_06009774 | 4;
  (*(code *)puVar1)();
  *(undefined4 *)PTR_DAT_0600977c = 0;
  (*(code *)PTR_FUN_06009784)(0,DAT_06009780);
  return;
}

