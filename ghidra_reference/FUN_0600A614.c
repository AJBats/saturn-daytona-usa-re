/* FUN_0600A614  0x0600A614 */


void FUN_0600a614(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  char *pcVar4;
  
  puVar2 = PTR_DAT_0600a704;
  puVar1 = PTR_DAT_0600a700;
  pcVar4 = *(char **)PTR_DAT_0600a708;
  if (pcVar4[1] != '\0') {
    (*(code *)PTR_FUN_0600a70c)();
    (*(code *)PTR_FUN_0600a718)
              (*(int *)PTR_PTR_0600a710 + (int)DAT_0600a6fc,
               *(int *)(PTR_PTR_0600a710 + 4) + (int)DAT_0600a6fa,
               *(int *)(PTR_PTR_0600a710 + 8) + DAT_0600a714);
    (*(code *)PTR_FUN_0600a71c)(puVar2,puVar2,puVar2);
    iVar3 = (*pcVar4 + 0xe) * 4;
    (*(code *)PTR_FUN_0600a728)
              (*(undefined4 *)(PTR_PTR_0600a724 + iVar3),*(undefined4 *)(PTR_DAT_0600a720 + iVar3));
    iVar3 = (*pcVar4 + 0xe) * 4;
    (*(code *)PTR_FUN_0600a738)
              (*(undefined4 *)(PTR_PTR_0600a734 + iVar3),(int)*(short *)PTR_DAT_0600a730,
               *(undefined4 *)(PTR_DAT_0600a72c + iVar3));
    *(int *)puVar1 = *(int *)puVar1 + -0x30;
  }
  if (pcVar4[4] != '\0') {
    (*(code *)PTR_FUN_0600a70c)();
    (*(code *)PTR_FUN_0600a718)
              (*(undefined4 *)PTR_DAT_0600a73c,*(int *)(PTR_DAT_0600a73c + 4) + (int)DAT_0600a6fa,
               DAT_0600a740 - *(int *)(PTR_DAT_0600a73c + 8));
    (*(code *)PTR_FUN_0600a71c)(puVar2,puVar2,puVar2);
    iVar3 = (pcVar4[3] + 0xe) * 4;
    (*(code *)PTR_FUN_0600a728)
              (*(undefined4 *)(PTR_PTR_0600a724 + iVar3),*(undefined4 *)(PTR_DAT_0600a720 + iVar3));
    iVar3 = (pcVar4[3] + 0xe) * 4;
    (*(code *)PTR_FUN_0600a768)
              (*(undefined4 *)(PTR_PTR_0600a764 + iVar3),(int)*(short *)PTR_DAT_0600a730,
               *(undefined4 *)(PTR_DAT_0600a72c + iVar3));
    *(int *)puVar1 = *(int *)puVar1 + -0x30;
  }
  return;
}

