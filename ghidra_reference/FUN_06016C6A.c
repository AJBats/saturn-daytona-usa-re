/* FUN_06016C6A  0x06016C6A */


void FUN_06016c6a(undefined1 param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_06016ca0;
  FUN_0601772e((int)(char)*PTR_DAT_06016ca0);
  *puVar1 = *puVar1 + -6;
  if ((char)*puVar1 < '\x01') {
    FUN_0601772e(0);
    FUN_060172e4(param_1);
    return;
  }
  return;
}

