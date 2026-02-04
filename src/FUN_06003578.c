extern int DAT_0600361e;

extern int DAT_06003620;

extern int DAT_06003622;

extern int DAT_06003624;

extern int DAT_06003626;

extern int DAT_06003628;

extern int DAT_0600362a;

extern int DAT_0600362c;

extern int DAT_0600362e;

extern int DAT_06003630;

extern int DAT_06003632;

extern int DAT_06003634;

extern int DAT_06003772;

extern int DAT_06003774;

extern int DAT_06003776;

extern int DAT_06003778;

extern int DAT_0600377a;

extern int DAT_0600377c;

extern int DAT_0600377e;

extern int DAT_06003780;

extern int DAT_06003782;

extern int DAT_06003784;

extern int DAT_06003786;

extern int DAT_06003788;

extern int DAT_0600378a;

extern int DAT_0600378c;

extern int DAT_0600378e;

extern int DAT_06003884;

extern int DAT_06003886;

extern int DAT_06003888;

extern int DAT_0600388a;

extern int DAT_0600388c;

extern int DAT_0600388e;

extern int PTR_DAT_06003790;

extern int PTR_DAT_06003790;

void FUN_06003578()
{

  char *puVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  int iVar5;

  puVar3 = 0x06027630;

  puVar2 = 0x0602761E;

  puVar1 = 0x25E20000;

  (*0x0602761E)(0x25F00800,0x060481AC,(int)DAT_0600361e);

  (*puVar3)(0x25E00000,0x002CF108,(int)DAT_06003620);

  iVar5 = 8;

  do {

    iVar5 = iVar5 + -2;

    *(int *)puVar1 = 0;

    puVar4 = 0x002A0000;

  } while (iVar5 != 0);

  (*puVar3)(0x25E4363C,0x00031498 + (int)0x002A0000,(int)DAT_06003622);

  (*puVar3)(0x25E497E4,0x00037640 + (int)puVar4,(int)DAT_06003624);

  (*puVar3)(0x25E4EFEC,0x0003CE44 + (int)puVar4,0x00008094);

  (*puVar3)(0x25E40000,0x00044ED8 + (int)puVar4,(int)DAT_06003626);

  (*puVar3)(0x25E407F0,0x000456C8 + (int)puVar4,(int)DAT_06003628);

  (*puVar3)(0x25E4108C,0x00045F64 + (int)puVar4,(int)DAT_0600362a);

  (*puVar3)(0x25E41A24,0x000468FC + (int)puVar4,(int)DAT_0600362c);

  (*puVar3)(0x25E42300,0x000471D8 + (int)puVar4,(int)DAT_0600362e);

  (*puVar3)(0x25E42C78,0x00047B50 + (int)puVar4,(int)DAT_06003630);

  (*puVar3)(0x25E61CEC,0x0001F370 + (int)puVar4,(int)DAT_06003632);

  (*puVar3)(0x25E665D4,0x00023C58 + (int)puVar4,(int)DAT_06003634);

  (*puVar3)(0x25E6A9CC,0x00028050 + (int)puVar4,(int)DAT_06003772);

  iVar5 = (int)DAT_06003774;

  (*puVar3)(0x25E60000,0x0002D41C + (int)puVar4,iVar5);

  (*puVar3)(0x25E609A4,0x0002DDC0 + (int)puVar4,iVar5);

  (*puVar3)(0x25E61348,0x0002E764 + (int)puVar4,iVar5);

  (*puVar3)(0x25E6F9C4,puVar4 + DAT_06003778,(int)DAT_06003776);

  (*puVar3)(0x25E70E40,puVar4 + DAT_0600377c,(int)DAT_0600377a);

  (*puVar3)(0x25E72194,0x0000EAB0 + (int)puVar4,(int)DAT_0600377e);

  (*puVar3)(0x25E73B98,0x00017114 + (int)puVar4,(int)DAT_06003780);

  (*puVar3)(0x25E74158,0x000176D0 + (int)puVar4,iVar5);

  (*puVar3)(0x25E74AFC,0x00018074 + (int)puVar4,(int)DAT_06003782);

  (*puVar3)(0x25E75730,0x00018B10 + (int)puVar4,(int)DAT_06003784);

  (*puVar2)(0x25E759EC,0x00008F84 + (int)puVar4,(int)DAT_06003786);

  (*puVar2)(0x25E75DDC,0x00009374 + (int)puVar4,(int)DAT_06003786);

  (*puVar3)(0x25E76174,0x00048514 + (int)puVar4,(int)DAT_06003788);

  (*puVar3)(0x25E761FC,0x0004859C + (int)puVar4,(int)DAT_0600378a);

  (*puVar3)(0x25E76EFC,0x0004929C + (int)puVar4,(int)DAT_0600378c);

  (*puVar3)(0x25E77B18,0x00049EB8 + (int)puVar4,(int)DAT_0600378e);

  iVar5 = (int)PTR_DAT_06003790;

  (*puVar2)(0x060EE300,0x0000AA54 + (int)puVar4,iVar5);

  (*puVar2)(0x060EE7D4,0x0000AF28 + (int)puVar4,iVar5);

  (*puVar2)(0x060EECA8,0x0000B3FC + (int)puVar4,iVar5);

  (*puVar2)(0x060EF17C,0x0000B8D0 + (int)puVar4,iVar5);

  (*puVar2)(0x060EF650,0x0000BDA4 + (int)puVar4,iVar5);

  (*puVar2)(0x060EFB24,0x0002D048 + (int)puVar4,(int)DAT_06003884);

  (*puVar3)(0x25E33AD8,0x00019BC4 + (int)puVar4,(int)DAT_06003886);

  (*puVar3)(0x25E33764,0x0001A0EC + (int)puVar4,(int)DAT_06003888);

  (*puVar3)(0x25E3398C,0x0004FEEC + (int)puVar4,(int)DAT_0600388a);

  (*puVar3)(0x25E7B168,puVar4 + DAT_0600388e,(int)DAT_0600388c);

  return;

}
