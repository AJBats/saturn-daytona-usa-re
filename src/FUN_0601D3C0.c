extern int DAT_0601d444;

extern int DAT_0601d446;

void FUN_0601d3c0()
{

  char *puVar1;

  puVar1 = 0x0605AB16;

  if ((*(int *)0x06086024 == 0) && ((*(unsigned short *)0x06063D9A & DAT_0601d444) != 0)) {

    if ((char *)(unsigned int)*(unsigned short *)0x06063D98 == 0x0000AAA8) {

      *0x0605AB16 = *0x0605AB16 | 7;

    }

    if ((unsigned int)*(unsigned short *)0x06063D98 == (int)DAT_0601d446) {

      *puVar1 = *puVar1 | 7;

      *0x0605AB17 = *0x0605AB17 | 7;

    }

    (*0x06014884)(0x20,0);

    (*0x06028400)(0xc,0x06094FA8,0);

    *(int *)0x0607EBCC = 0xc;

    *0x0607887F = 4;

    *(int *)0x06086024 = 1;

  }

  (**(void **)(0x0605DF80 + (unsigned int)(unsigned char)*0x0607887F * 4))();

  return;

}
