extern int DAT_0600ed60;

extern int DAT_0600ed62;

extern int DAT_0600ed64;

extern int DAT_0600ed66;

extern int DAT_0600ed68;

extern int DAT_0600ed6a;

extern int DAT_0600ed6c;

extern int DAT_0600ed6e;

extern int DAT_0600ed70;

extern int DAT_0600ed72;

extern int DAT_0600ed74;

extern int DAT_0600ed76;

extern int DAT_0600ed78;

extern int DAT_0600ed7a;

extern int DAT_0600ed7c;

extern int DAT_0600ed7e;

extern int DAT_0600ed80;

extern int DAT_0600eeba;

extern int DAT_0600eebc;

extern int DAT_0600eebe;

extern int DAT_0600eec0;

extern int DAT_0600eec2;

extern int DAT_0600eec4;

extern int DAT_0600eec6;

extern int DAT_0600eec8;

extern int DAT_0600eeca;

extern int DAT_0600eecc;

extern int DAT_0600eece;

extern int DAT_0600eed0;

extern int DAT_0600eed2;

extern int DAT_0600eed4;

extern int DAT_0600eed6;

extern int DAT_0600eed8;

extern int DAT_0600eeda;

extern int DAT_0600eedc;

extern int DAT_0600eede;

extern int DAT_0600eee0;

extern int DAT_0600eee2;

extern int DAT_0600eee4;

extern int DAT_0600eee6;

extern int DAT_0600eee8;

extern int DAT_0600eeea;

extern int DAT_0600eeec;

extern int DAT_0600eeee;

extern int DAT_0600eef0;

extern int DAT_0600eef2;

extern int DAT_0600eef4;

extern int DAT_0600eef6;

extern int DAT_0600eef8;

extern int DAT_0600eefa;

extern int DAT_0600eefc;

extern int DAT_0600eefe;

extern int DAT_0600effc;

extern int DAT_0600effe;

extern int DAT_0600f000;

extern int DAT_0600f002;

extern int DAT_0600f004;

extern int DAT_0600f006;

extern int DAT_0600f008;

extern int DAT_0600f00a;

extern int DAT_0600f00c;

extern int DAT_0600f00e;

extern int DAT_0600f010;

extern int DAT_0600f012;

extern int DAT_0600f014;

extern int DAT_0600f016;

extern int DAT_0600f018;

extern int DAT_0600f01a;

extern int DAT_0600f01c;

extern int DAT_0600f01e;

extern int DAT_0600f020;

extern int DAT_0600f022;

extern int DAT_0600f024;

extern int DAT_0600f026;

extern int DAT_0600f028;

extern int DAT_0600f02a;

extern int DAT_0600f02c;

extern int DAT_0600f02e;

extern int DAT_0600f030;

extern int DAT_0600f032;

extern int DAT_0600f034;

extern int DAT_0600f036;

extern int DAT_0600f14c;

extern int DAT_0600f14e;

extern int DAT_0600f150;

extern int DAT_0600f152;

extern int DAT_0600f26a;

extern int DAT_0600f26c;

extern int DAT_0600f26e;

extern int DAT_0600f270;

extern int DAT_0600f272;

extern int DAT_0600f274;

extern int DAT_0600f276;

extern int DAT_0600f278;

extern int DAT_0600f342;

extern int DAT_0600f344;

extern int DAT_0600f346;

extern int DAT_0600f348;

extern int DAT_0600f34a;

extern int PTR_DAT_0600f154;

extern int PTR_DAT_0600f154;

extern int PTR_DAT_0600f34c;

extern int PTR_DAT_0600f34c;

void FUN_0600ec78()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  (*(int(*)())0x0600A140)();

  puVar1 = 0x06063F5C;

  iVar5 = *(int *)(0x06059FFC << 3) + *(int *)0x06063F5C;

  iVar4 = iVar5 + 0x40;

  *(int *)0x06078884 = iVar4;

  iVar6 = 0xc0;

  *(int *)0x06078880 = iVar4 + iVar6;

  puVar2 = 0x06078888;

  *(int *)0x06078888 = iVar5 + DAT_0600ed62;

  *(int *)(puVar2 + 4) = *(int *)puVar2 + 0x20;

  *(int *)(puVar2 + 8) = *(int *)puVar2 + 0x40;

  *(int *)0x0606A4F4 = 0;

  *(int *)0x0606A4EC = (int)DAT_0600ed64;

  (*(int(*)())(*(int *)0x06000344))(0xffffffff,0x83);

  (*(int(*)())0x06012E00)();

  (*(int(*)())(*(int *)0x06000344))(-132,0);

  (*(int(*)())0x0602766C)(*(int *)puVar1,0x0605A018,0x60);

  *(int *)0x0605A008 = 3;

  *(short *)(*(int *)puVar1 + 0x60) = (short)0x00008000;

  *(short *)0x06089E44 = 0;

  puVar2 = 0x002A0000;

  puVar1 = 0x06007658;

  iVar5 = 0x108;

  (*(int(*)())0x06007658)(1,iVar5,0,0x002A0000 + DAT_0600ed6c);

  (*(int(*)())puVar1)(2,0x810,0,puVar2 + DAT_0600ed6e);

  (*(int(*)())puVar1)(3,(int)DAT_0600ed74,0,puVar2 + DAT_0600ed72);

  (*(int(*)())puVar1)(4,(int)DAT_0600ed78,0,puVar2 + DAT_0600ed76);

  (*(int(*)())puVar1)(5,0x519,0,puVar2 + DAT_0600ed7a);

  (*(int(*)())puVar1)(6,(int)DAT_0600ed80,0,puVar2 + DAT_0600ed7e);

  (*(int(*)())puVar1)(7,0x738,4,puVar2 + DAT_0600eeba);

  (*(int(*)())puVar1)(8,0x738,4,puVar2 + DAT_0600eebe);

  (*(int(*)())puVar1)(9,0x208,0,puVar2 + DAT_0600eec0);

  (*(int(*)())puVar1)(10,0xa28,0x3c,puVar2 + DAT_0600eec4);

  (*(int(*)())puVar1)(0x10,0x228,8,puVar2 + DAT_0600eec8);

  (*(int(*)())puVar1)(0x11,0x428,8,puVar2 + DAT_0600eecc);

  (*(int(*)())puVar1)(0x12,0x418,8,puVar2 + DAT_0600eed0);

  (*(int(*)())puVar1)(0x13,0x820,8,puVar2 + DAT_0600eed4);

  (*(int(*)())puVar1)(0x14,0x518,8,puVar2 + DAT_0600eed8);

  (*(int(*)())puVar1)(0x15,0x518,8,puVar2 + DAT_0600eedc);

  (*(int(*)())puVar1)(0x16,0x508,0xc,puVar2 + DAT_0600eede);

  (*(int(*)())puVar1)(0x17,0xd10,8,puVar2 + DAT_0600eee2);

  (*(int(*)())puVar1)(0x18,(int)DAT_0600eee8,0x1c,puVar2 + DAT_0600eee6);

  iVar4 = 0x348;

  (*(int(*)())puVar1)(0x19,iVar4,0x10,puVar2 + DAT_0600eeec);

  (*(int(*)())puVar1)(0x1a,iVar4,0x10,puVar2 + DAT_0600eeee);

  (*(int(*)())puVar1)(0x1b,iVar4,0x10,puVar2 + DAT_0600eef0);

  (*(int(*)())puVar1)(0x1c,0x630,0x1c,puVar2 + DAT_0600eef2);

  (*(int(*)())puVar1)(0x1d,0xa28,0x10,puVar2 + DAT_0600eef6);

  (*(int(*)())puVar1)(0x1e,0xc08,0x18,puVar2 + DAT_0600eef8);

  (*(int(*)())puVar1)(0x1f,0xc10,0x18,puVar2 + DAT_0600eefc);

  iVar4 = 0x308;

  (*(int(*)())puVar1)(0x20,iVar4,0xc,puVar2 + DAT_0600effe);

  (*(int(*)())puVar1)(0x21,0x410,0xc,puVar2 + DAT_0600f000);

  (*(int(*)())puVar1)(0x22,iVar4,0xc,puVar2 + DAT_0600f004);

  (*(int(*)())puVar1)(0x23,iVar4,0xc,puVar2 + DAT_0600f006);

  (*(int(*)())puVar1)(0x24,0x410,0xc,puVar2 + DAT_0600f008);

  (*(int(*)())puVar1)(0x25,(int)DAT_0600f00c,0x14,puVar2 + DAT_0600f00a);

  (*(int(*)())puVar1)(0x26,(int)DAT_0600f00c,0x14,puVar2 + DAT_0600f00e);

  (*(int(*)())puVar1)(0x27,0x610,0xc,puVar2 + DAT_0600f010);

  (*(int(*)())puVar1)(0x28,0x510,0x14,puVar2 + DAT_0600f014);

  (*(int(*)())puVar1)(0x29,0x310,0x14,puVar2 + DAT_0600f018);

  (*(int(*)())puVar1)(0x2a,(int)DAT_0600f01e,0x14,puVar2 + DAT_0600f01c);

  (*(int(*)())puVar1)(0x2b,(int)DAT_0600f022,0x14,puVar2 + DAT_0600f020);

  (*(int(*)())puVar1)(0x2c,0x110,0xc,puVar2 + DAT_0600f024);

  (*(int(*)())puVar1)(0x2d,0x110,0xc,puVar2 + DAT_0600f028);

  (*(int(*)())puVar1)(0x2e,0x510,0x14,puVar2 + DAT_0600f02a);

  (*(int(*)())puVar1)(0x2f,0x310,0x14,puVar2 + DAT_0600f02c);

  (*(int(*)())puVar1)(0x30,(int)DAT_0600f01e,0x14,puVar2 + DAT_0600f02e);

  (*(int(*)())puVar1)(0x31,(int)DAT_0600f022,0x14,puVar2 + DAT_0600f030);

  (*(int(*)())puVar1)(0x32,iVar5,0x14,puVar2 + DAT_0600f032);

  (*(int(*)())puVar1)(0x33,iVar5,0x14,puVar2 + DAT_0600f034);

  (*(int(*)())puVar1)(0x34,iVar5,0x14,puVar2 + DAT_0600f036);

  (*(int(*)())puVar1)(0x35,iVar5,0x14,puVar2 + DAT_0600f14c);

  (*(int(*)())puVar1)(0x36,iVar5,0x10,puVar2 + DAT_0600f14e);

  (*(int(*)())puVar1)(0x37,iVar5,0x1c,puVar2 + DAT_0600f150);

  (*(int(*)())puVar1)(0x38,iVar5,8,puVar2 + DAT_0600f152);

  (*(int(*)())puVar1)(0x39,iVar5,0x10,puVar2 + PTR_DAT_0600f154);

  *(short *)0x06089E46 = 1;

  puVar3 = 0x06007540;

  (*(int(*)())0x06007540)(0x41,1,0);

  (*(int(*)())puVar3)(0x42,2,0);

  (*(int(*)())puVar3)(0x43,3,0);

  (*(int(*)())puVar3)(0x44,4,0);

  (*(int(*)())puVar3)(0x45,5,0);

  (*(int(*)())puVar3)(0x46,6,0);

  (*(int(*)())puVar3)(0x47,7,4);

  (*(int(*)())puVar3)(0x48,8,4);

  (*(int(*)())puVar3)(0x49,9,0);

  (*(int(*)())puVar3)(0x4a,10,0x3c);

  (*(int(*)())puVar3)(0x50,0x10,0x20);

  (*(int(*)())puVar3)(0x51,0x11,0x20);

  (*(int(*)())puVar3)(0x52,0x12,0x20);

  (*(int(*)())puVar3)(0x53,0x13,0x20);

  (*(int(*)())puVar3)(0x54,0x14,0x20);

  (*(int(*)())puVar3)(0x55,0x15,0x20);

  (*(int(*)())puVar3)(0x56,0x16,0x24);

  (*(int(*)())puVar3)(0x57,0x17,0x20);

  (*(int(*)())puVar3)(0x58,0x18,0x34);

  (*(int(*)())puVar3)(0x59,0x19,0x28);

  (*(int(*)())puVar3)(0x5a,0x1a,0x28);

  (*(int(*)())puVar3)(0x5b,0x1b,0x28);

  (*(int(*)())puVar3)(0x5c,0x1c,0x34);

  (*(int(*)())puVar3)(0x5d,0x1d,0x28);

  (*(int(*)())puVar3)(0x5e,0x1e,0x30);

  (*(int(*)())puVar3)(0x5f,0x1f,0x30);

  (*(int(*)())puVar3)(0x60,0x20,0x24);

  (*(int(*)())puVar3)(0x61,0x21,0x24);

  (*(int(*)())puVar3)(0x62,0x22,0x24);

  (*(int(*)())puVar3)(99,0x23,0x24);

  (*(int(*)())puVar3)(100,0x24);

  (*(int(*)())puVar3)(0x65,0x25,0x2c);

  (*(int(*)())puVar3)(0x66,0x26,0x2c);

  (*(int(*)())puVar3)(0x67,0x27,0x24);

  (*(int(*)())puVar3)(0x68,0x28,0x2c);

  (*(int(*)())puVar3)(0x69,0x29,0x2c);

  (*(int(*)())puVar3)(0x6a,0x2a,0x2c);

  (*(int(*)())puVar3)(0x6b,0x2b,0x2c);

  (*(int(*)())puVar3)(0x6c,0x2c,0x24);

  (*(int(*)())puVar3)(0x6d,0x2d,0x24);

  (*(int(*)())puVar3)(0x6e,0x2e,0x2c);

  (*(int(*)())puVar3)(0x6f,0x2f,0x2c);

  (*(int(*)())puVar3)(0x70,0x30,0x2c);

  (*(int(*)())puVar3)(0x71,0x31,0x2c);

  (*(int(*)())puVar3)(0x72,0x32,0x2c);

  (*(int(*)())puVar3)(0x73,0x33,0x2c);

  (*(int(*)())puVar3)(0x74,0x34,0x2c);

  (*(int(*)())puVar3)(0x75,0x35,0x2c);

  (*(int(*)())puVar3)(0x76,0x36,0x28);

  (*(int(*)())puVar3)(0x77,0x37,0x34);

  (*(int(*)())puVar3)(0x78,0x38,0x20);

  (*(int(*)())puVar3)(0x79,0x39,0x28);

  iVar4 = 0xb40;

  (*(int(*)())puVar1)(0x101,iVar4,0x78,puVar2 + DAT_0600f26c);

  (*(int(*)())puVar1)((int)DAT_0600f272,iVar4,0x7c,puVar2 + DAT_0600f270);

  iVar5 = 0x80;

  (*(int(*)())puVar1)(0x103,iVar4,iVar5,puVar2 + DAT_0600f276);

  (*(int(*)())puVar3)((int)DAT_0600f344,DAT_0600f342 + 0x7d);

  (*(int(*)())puVar3)((int)DAT_0600f348,DAT_0600f346 + 0x7a);

  (*(int(*)())puVar3)((int)PTR_DAT_0600f34c,DAT_0600f34a + 0x77);

  puVar1 = 0x06086028;

  *(short *)0x06086028 = (short)0x00008000;

  (*(int(*)())0x06036E90)(0x25F00FFE,1,puVar1);

  (*(int(*)())0x060149E0)();

  (*(int(*)())0x0600A026)();

  (*(int(*)())0x0601D2DC)();

  puVar2 = 0x060484EC;

  puVar1 = 0x0602761E;

  (*(int(*)())0x0602761E)(0x25F00060,0x060484EC,iVar6);

  (*(int(*)())puVar1)(0x25F00460,puVar2,iVar6);

  puVar2 = 0x0604870C;

  (*(int(*)())puVar1)(0x25F00520,0x0604870C,0x20);

  (*(int(*)())puVar1)(0x25F00540,puVar2,0x20);

  puVar2 = 0x0604842C;

  (*(int(*)())puVar1)(0x25F001A0,0x0604842C,0x40);

  (*(int(*)())puVar1)(0x25F007A0,puVar2,0x40);

  puVar2 = 0x0604846C;

  (*(int(*)())puVar1)(0x25F001E0,0x0604846C,0x20);

  (*(int(*)())puVar1)(0x25F007E0,puVar2,0x20);

  (*(int(*)())puVar1)(0x25F005A0,0x0605CA5C,0x40);

  puVar2 = 0x0604814C;

  (*(int(*)())puVar1)(0x25F00000,0x0604814C,0x60);

  (*(int(*)())puVar1)(0x25F00600,puVar2,0x60);

  (*(int(*)())puVar1)(0x25F006A0,0x060484CC,0x20);

  puVar2 = 0x060487AC;

  (*(int(*)())puVar1)(0x25F00120,0x060487AC,iVar5);

  (*(int(*)())puVar1)(0x25F00720,puVar2,iVar5);

  puVar2 = 0x060487CC;

  (*(int(*)())puVar1)(0x25F00680,0x060487CC,0x20);

  (*(int(*)())puVar1)(0x25F00140,puVar2,0x20);

  puVar2 = 0x060483EC;

  (*(int(*)())puVar1)(0x25F000C0,0x060483EC,0x20);

  (*(int(*)())puVar1)(0x25F006C0,puVar2,0x20);

  *(short *)0x0605AAA0 = 0;

  *(int *)0x0607887F = 0;

  puVar1 = 0x06026CE0;

  *(unsigned int *)0x0605B6D8 = *(unsigned int *)0x0605B6D8 | 0x40000000;

  (*(int(*)())puVar1)();

  *(int *)0x06059F44 = 0;

  return;

}
