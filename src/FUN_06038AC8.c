extern void FUN_06038a48();

void FUN_06038ac8()
{

  char *puVar1;

  puVar1 = 0x060A4D58;

  (*0x0603C728)();

  if (((int)(char)*puVar1 & 0x80U) != 0) {

    FUN_06038a48(*(int *)0x0606360C,0x060A4D18,0x10);

    (*0x06034F78)();

  }

  if ((*puVar1 & 0x40) != 0) {

    FUN_06038a48(*(int *)0x06063610,0x060A4D28,8);

    (*0x06034F78)();

  }

  if ((*puVar1 & 0x20) != 0) {

    FUN_06038a48(*(int *)0x06063614,0x060A4D30,6);

    (*0x06034F78)();

  }

  if ((*puVar1 & 0x10) != 0) {

    FUN_06038a48(*(int *)0x06063618,0x060A4D36,8);

    (*0x06034F78)();

  }

  if ((*puVar1 & 8) != 0) {

    FUN_06038a48(*(int *)0x0606361C,0x060A4D3E,8);

    (*0x06034F78)();

  }

  if ((*puVar1 & 4) != 0) {

    FUN_06038a48(*(int *)0x06063620,0x060A4D46,0x10);

    (*0x06034F78)();

  }

  return;

}
