/* FUN_06003000  0x06003000 */


void main(void)

{
  undefined *puVar1;
  undefined *puVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  (*(code *)PTR_FUN_06003060)();
  do {
    (*(code *)PTR_FUN_06003064)();
    puVar1 = PTR_DAT_06003070;
    iVar4 = *(int *)PTR_DAT_06003074;
    *(int *)PTR_DAT_0600306c = iVar4;
    puVar2 = PTR_DAT_06003078;
    iVar5 = 1;
    iVar6 = iVar4;
    if (0xf < iVar4) {
      iVar5 = 0x10000;
      iVar6 = iVar4 + -0x10;
    }
    if (7 < iVar6) {
      iVar5 = iVar5 << 8;
      iVar6 = iVar6 + -8;
    }
    if (5 < iVar6) {
      iVar5 = iVar5 << 6;
      iVar6 = iVar6 + -6;
    }
    for (; iVar6 != 0; iVar6 = iVar6 + -1) {
      iVar5 = iVar5 << 1;
    }
    *(int *)puVar1 = iVar5;
    pcVar3 = (code *)(&PTR_FUN_0600307c)[iVar4];
    *(int *)puVar2 = *(int *)puVar2 + 1;
    (*pcVar3)();
  } while( true );
}

