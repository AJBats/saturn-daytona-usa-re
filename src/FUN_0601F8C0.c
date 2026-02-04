extern void FUN_0601f5e0();
extern void FUN_0601f9cc();

int FUN_0601f8c0()
{

  *0x0605E05C = 0;

  FUN_0601f5e0();

  if (*0x0605E05C == '\0') {

    return 1;

  }

  (*0x060149E0)();

  FUN_0601f9cc();

  (*0x060149CC)();

  return 0;

}
