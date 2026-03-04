/* FUN_0601AF1E  0x0601AF1E */


void FUN_0601af1e(void)

{
  undefined *puVar1;
  
  (*(code *)PTR_FUN_0601af7c)
            (8,*(undefined4 *)PTR_DAT_0601af74,(int)DAT_0601af6a,
             PTR_DAT_0601af78 + *(int *)(PTR_DAT_0601af74 + 4));
  puVar1 = PTR_DAT_0601af80;
  FUN_0601b09a((int)(char)*(undefined4 *)PTR_DAT_0601af88,(int)(char)*(undefined4 *)PTR_DAT_0601af84
               ,(int)(char)*PTR_DAT_0601af80);
  *puVar1 = *puVar1 + '\x05';
  *PTR_DAT_0601af6c = 10;
  *PTR_DAT_0601af70 = *PTR_DAT_0601af70 + '\x01';
  return;
}

