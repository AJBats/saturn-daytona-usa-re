extern void FUN_06033f54();

int FUN_06033ea8()
{

  int iVar1;

  int iVar2;

  if (*(short *)0x06063E08 == 1) {

    *0x06083254 = *0x06083254 + '\x01';

  }

  if (*0x06083254 == '\x01') {

    (*0x06033F54)(0x00000000);

    (*0x06033F54)(0x00000001);

    (*0x06033F54)(0x00000002);

    (*0x06033F54)(0x00000004);

  }

  iVar1 = (int)(char)*0x06083254;

  iVar2 = 0x00000006;

  if ((char)*0x06083254 == 2) {

    do {

      FUN_06033f54();

      iVar2 = iVar2 + 1;

      iVar1 = 0x00000019;

    } while (iVar2 < 0x00000019);

  }

  return iVar1;

}
