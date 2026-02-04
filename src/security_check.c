extern int DAT_0600217a;

extern int DAT_0600217c;

extern int DAT_0600217e;

extern int DAT_06002180;

extern int DAT_06002182;

extern int DAT_0600224c;

extern int DAT_0600224e;

extern int PTR_DAT_06002184;

extern int PTR_DAT_06002188;

extern int PTR_DAT_0600218c;

extern int PTR_DAT_06002194;

extern int PTR_DAT_06002198;

extern int PTR_DAT_060021a4;

extern int PTR_DAT_060021a8;

extern int PTR_DAT_060021b0;

extern int PTR_DAT_060021b4;

extern int PTR_DAT_06002250;

extern int PTR_DAT_06002254;

extern int PTR_DAT_06002258;

extern int PTR_DAT_0600225c;

extern int PTR_DAT_06002260;

extern int PTR_DAT_06002264;

extern int PTR_DAT_06002268;

extern int PTR_DAT_0600226c;

extern int PTR_DAT_06002270;

extern int PTR_DAT_06002274;

extern int PTR_DAT_06002278;

extern int PTR_FUN_060021ac;

extern int PTR_FUN_0600227c;

extern int PTR_LAB_06002190;

extern int PTR_s_PRODUCED_BY_or_UNDERLICENSE_FROM_060021a0;

extern int PTR_s_SEGA_ENTERPRISES_LTD__0600219c;

extern void FUN_06002280();
extern void FUN_06002348();
extern void FUN_060023e6();
extern void FUN_06002404();
extern void FUN_0600245c();
extern void FUN_06002486();
extern void FUN_06002510();
extern void FUN_0600255c();
extern void FUN_06002594();

int security_check()
{

  int uVar1;

  int local_28;

  *(int *)PTR_DAT_06002188 = *(int *)PTR_DAT_06002184;

  (**(void **)PTR_DAT_0600218c)(0x40,PTR_LAB_06002190);

  (**(void **)PTR_DAT_06002194)(0xfffffffe,0);

  FUN_0600255c();

  FUN_06002594();

  FUN_060023e6();

  FUN_0600245c(PTR_DAT_06002198,(int)DAT_0600217a,0);

  (**(void **)(int)DAT_0600217c)();

  (**(void **)(int)DAT_0600217e)

            (PTR_s_PRODUCED_BY_or_UNDERLICENSE_FROM_060021a0,PTR_s_SEGA_ENTERPRISES_LTD__0600219c);

  (*PTR_FUN_060021ac)(PTR_DAT_060021a8,PTR_DAT_060021a4,(int)DAT_06002180);

  if ((*(unsigned int *)PTR_DAT_060021b0 & (int)DAT_06002182) == 0) {

    local_28 = PTR_DAT_06002250;

  }

  else {

    local_28 = PTR_DAT_060021b4;

  }

  FUN_06002486(local_28,(int)DAT_0600224c,0x12,6);

  FUN_06002404(PTR_DAT_06002258,PTR_DAT_06002254,0x10);

  FUN_06002280();

  if ((*(unsigned int *)PTR_DAT_06002260 & (int)DAT_0600224e) == 0) {

    **(short **)PTR_DAT_0600225c = (short)PTR_DAT_0600226c;

    *(int *)PTR_DAT_06002268 = 0x78;

  }

  else {

    **(short **)PTR_DAT_0600225c = (short)PTR_DAT_06002264;

    *(int *)PTR_DAT_06002268 = 100;

  }

  FUN_06002510(0x20);

  (**(void **)PTR_DAT_06002270)();

  while (*(int *)PTR_DAT_06002268 != 0) {

    FUN_060023e6();

  }

  (**(void **)PTR_DAT_06002274)(0xffffffff,1);

  (**(void **)PTR_DAT_06002278)(0x40,0);

  FUN_06002348();

  uVar1 = (*PTR_FUN_0600227c)();

  return uVar1;

}
