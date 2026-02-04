extern int DAT_06011efe;

extern int PTR_DAT_06011f04;

extern int PTR_DAT_06011f04;

extern void FUN_06011e7c();

void FUN_06011eb4()
{

  if (*0x06085FF4 != '\0') {

    FUN_06011e7c();

    return;

  }

  if (*(int *)0x0607EADC != 0) {

    (*0x06028400)

              (0xc,*(int *)0x060638B0,(int)PTR_DAT_06011f04,

               *(int *)(0x060638B0 + 4) + (int)DAT_06011efe);

    return;

  }

  (*0x06028400)

            (0xc,*(int *)0x060638A0,(int)PTR_DAT_06011f04,

             *(int *)(0x060638A0 + 4) + (int)DAT_06011efe);

  return;

}
