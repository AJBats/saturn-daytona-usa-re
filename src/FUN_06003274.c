extern int DAT_060032ba;

extern int DAT_060032bc;

extern int DAT_060032be;

void FUN_06003274()
{

  char *puVar1;

  puVar1 = 0x06000310;

  (*(void(*)())(*(int *)0x06000310))(4,0x06028218);

  (**(void **)puVar1)(6,0x06028230);

  (**(void **)puVar1)(9,0x06028248);

  (**(void **)puVar1)((int)DAT_060032ba,0x06028218);

  (**(void **)puVar1)((int)DAT_060032bc,0x06028230);

  (**(void **)puVar1)((int)DAT_060032be,0x06028248);

  return;

}
