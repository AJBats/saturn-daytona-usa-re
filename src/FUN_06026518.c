extern int DAT_06026572;

extern int DAT_06026574;

extern int DAT_06026576;

extern int DAT_06026578;

void FUN_06026518(param_1)
    unsigned int param_1;
{

  if ((param_1 & 4) != 0) {

    (*0x060284AE)(8,(int)DAT_06026574,(int)DAT_06026572,0x06059128);

    (*0x060284AE)(8,(int)DAT_06026576,(int)DAT_06026572,0x06059128);

    return;

  }

  (*0x06028400)

            (8,*(int *)0x06063B80,(int)DAT_06026574,

             *(int *)(0x06063B80 + 4) + (int)DAT_06026578,0x06063B80);

  (*0x06028400)

            (8,*(int *)0x06063B88,(int)DAT_06026576,

             *(int *)(0x06063B88 + 4) + (int)DAT_06026578);

  return;

}
