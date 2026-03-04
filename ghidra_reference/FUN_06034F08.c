/* FUN_06034F08  0x06034F08 */


void FUN_06034f08(void)

{
  *(undefined2 *)(int)DAT_06034f64 = 0;
  *(undefined2 *)(int)DAT_06034f66 = 0;
  *(undefined1 *)(int)DAT_06034f68 = 1;
  do {
    do {
    } while ((*(byte *)(int)DAT_06034f6a & 0x80) != PTR_DAT_06034f6c._0_2_);
    *(undefined1 *)(int)DAT_06034f6a = 0;
    if (*(int *)PTR_DAT_06034f70 != 0) {
      (**(code **)PTR_DAT_06034f74)();
    }
    *(undefined4 *)PTR_DAT_06034f70 = 0;
  } while( true );
}

