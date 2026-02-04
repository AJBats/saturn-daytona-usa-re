extern int DAT_0601f962;

extern int DAT_0601f964;

extern int FUN_0601fd20();

int FUN_0601f900()
{

  short local_8 [4];

  if ((*(unsigned short *)0x06063D9A & DAT_0601f962) != 0) {

    local_8[0] = DAT_0601f964;

    (*(int(*)())0x06036E90)(0x25E7FFFE,1,local_8);

    return 1;

  }

  FUN_0601fd20();

  return 0;

}
