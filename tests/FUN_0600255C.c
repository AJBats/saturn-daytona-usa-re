extern int PTR_DAT_060025cc;

extern int PTR_DAT_060025d0;

extern int PTR_VDP1_TVMR_060025c8;


void FUN_0600255c()
{

  unsigned int uStack_8;

  short *puStack_4;

  

  puStack_4 = (short *)PTR_VDP1_TVMR_060025c8;

  for (uStack_8 = 0; uStack_8 < 6; uStack_8 = uStack_8 + 1) {

    *puStack_4 = 0;

    puStack_4 = puStack_4 + 1;

  }

  *(short *)PTR_DAT_060025cc = (short)PTR_DAT_060025d0;

  return;

}
