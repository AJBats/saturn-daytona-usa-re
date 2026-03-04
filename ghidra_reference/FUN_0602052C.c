/* FUN_0602052C  0x0602052C */


void FUN_0602052c(undefined1 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  *(undefined2 *)PTR_DAT_06020600 = 3;
  (*(code *)PTR_FUN_06020604)();
  (*(code *)PTR_FUN_06020608)();
  (*(code *)PTR_FUN_0602060c)(0xc);
  (*(code *)PTR_FUN_0602060c)(4);
  puVar1 = PTR_FUN_06020610;
  (*(code *)PTR_FUN_06020610)(PTR_DAT_06020618,PTR_DAT_06020614,0x20);
  (*(code *)puVar1)(PTR_DAT_06020620,PTR_DAT_0602061c,0x20);
  puVar2 = PTR_DAT_06020624;
  (*(code *)puVar1)(PTR_DAT_06020628,PTR_DAT_06020624,0x20);
  (*(code *)puVar1)(PTR_DAT_0602062c,puVar2,0x20);
  puVar2 = PTR_FUN_06020634;
  puVar1 = PTR_DAT_06020630;
  (*(code *)PTR_FUN_06020634)
            (0,*(undefined4 *)(PTR_DAT_06020630 + DAT_060205f2),0,
             PTR_DAT_06020638 + *(int *)((int)(PTR_DAT_06020630 + DAT_060205f2) + 4));
  puVar4 = (undefined4 *)(puVar1 + DAT_060205f4);
  (*(code *)puVar2)(4,*puVar4,(int)DAT_060205f6,puVar4[1]);
  puVar4 = (undefined4 *)(puVar1 + DAT_060205f8);
  (*(code *)puVar2)(0xc,*puVar4,(int)DAT_060205fc,puVar4[1] + (int)DAT_060205fa);
  puVar1 = PTR_FUN_0602063c;
  (*(code *)PTR_FUN_0602063c)(0x20,0);
  (*(code *)puVar1)(8,0);
  (*(code *)puVar1)(4,0);
  puVar1 = PTR_FUN_06020640;
  (*(code *)PTR_FUN_06020640)((int)DAT_060205fe,0);
  (*(code *)puVar1)(4);
  (*(code *)puVar1)(8,5);
  (*(code *)puVar1)(0x10,6);
  (*(code *)puVar1)(0x20,7);
  *DAT_060206c8 = 1;
  FUN_06020dee(param_1);
  puVar2 = PTR_DAT_060206d0;
  puVar1 = PTR_DAT_060206cc;
  *(undefined **)PTR_DAT_060206cc = PTR_DAT_060206d0;
  *(undefined **)PTR_DAT_060206d4 = puVar2;
  *(undefined4 *)PTR_DAT_060206d8 = *(undefined4 *)puVar1;
  uVar3 = (*(code *)PTR_FUN_060206e4)(PTR_DAT_060206e0,PTR_DAT_060206dc);
  uVar3 = (*(code *)PTR_FUN_060206e8)(uVar3,*(undefined4 *)puVar1);
  *(undefined4 *)PTR_DAT_060206ec = uVar3;
  uVar3 = (*(code *)PTR_FUN_060206e4)(PTR_DAT_060206f4,*(int *)puVar1 + DAT_060206f0);
  uVar3 = (*(code *)PTR_FUN_060206e8)(uVar3,*(undefined4 *)puVar1);
  *(undefined4 *)PTR_DAT_060206f8 = uVar3;
  (*(code *)PTR_FUN_060206fc)(8);
  (*(code *)PTR_FUN_06020700)(*(undefined4 *)PTR_DAT_060206d4,*(undefined4 *)PTR_DAT_060206d8);
  (*(code *)PTR_FUN_06020704)(*(undefined4 *)PTR_DAT_060206ec,*(undefined4 *)PTR_DAT_060206f8,0);
  (*(code *)PTR_FUN_06020708)();
  return;
}

