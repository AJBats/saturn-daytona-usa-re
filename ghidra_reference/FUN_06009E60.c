/* FUN_06009E60  0x06009E60 */


void FUN_06009e60(void)

{
  undefined *puVar1;
  
  (*(code *)PTR_FUN_06009edc)();
  puVar1 = PTR_FUN_06009ee0;
  (*(code *)PTR_FUN_06009ee0)(4);
  (*(code *)puVar1)(8);
  (*(code *)puVar1)(0xc);
  (*(code *)PTR_FUN_06009ee4)();
  puVar1 = PTR_FUN_06009ee8;
  (*(code *)PTR_FUN_06009ee8)(8,0);
  (*(code *)puVar1)(0x10,0);
  (*(code *)puVar1)(0x20,0);
  (*(code *)PTR_FUN_06009eec)();
  *(int *)PTR_DAT_06009ef0 = (int)DAT_06009eda;
  *(undefined4 *)PTR_DAT_06009ef4 = 0x17;
  *(undefined2 *)PTR_DAT_06009ef8 = 0;
  (*(code *)PTR_FUN_06009efc)();
  (*(code *)PTR_FUN_06009f00)();
  *(undefined2 *)PTR_DAT_06009f04 = 4;
  (*(code *)PTR_FUN_06009f0c)((char)*PTR_DAT_06009f08 + 0xe,(char)*PTR_DAT_06009f08 + 0xe,0);
  return;
}

