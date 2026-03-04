/* FUN_06012AFA  0x06012AFA */


undefined4 FUN_06012afa(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  puVar1 = PTR_DAT_06012b4c;
  if ((*(uint *)PTR_DAT_06012b4c & 4) == 0) {
    uVar2 = FUN_06012ac4();
  }
  else {
    uVar2 = (*(code *)PTR_FUN_06012b54)
                      (8,*(undefined4 *)PTR_DAT_06012b50,(int)DAT_06012b36,
                       *(int *)(PTR_DAT_06012b50 + 4) + (int)DAT_06012b3c);
  }
  *(int *)puVar1 = *(int *)puVar1 + 1;
  return uVar2;
}

