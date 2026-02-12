#include "game.h"

extern char flag_0607887F;
extern int DAT_0600e0ea;
extern int DAT_0600e2ba;
extern int DAT_0600e2bc;
extern int DAT_0600e2be;
extern int DAT_0600e2c0;
extern int DAT_0600e2c2;
extern int DAT_0600e2c4;
extern int DAT_0600e2c6;
extern int DAT_0600e2c8;
extern int DAT_0600e2ca;
extern int DAT_0600e3e8;
extern int DAT_0600e3ea;
extern int DAT_0600e3ec;
extern int DAT_0600e3ee;
extern int DAT_0600e3f0;
extern int DAT_0600e3f2;
extern int DAT_0600e3f4;
extern int DAT_0600e3f6;
extern int DAT_0600e456;
extern int DAT_0600e522;
extern int DAT_0600e69c;
extern int DAT_0600e69e;
extern int DAT_0600e86c;
extern int DAT_0600e86e;
extern int DAT_0600e870;
extern int DAT_0600e872;
extern int DAT_0600e91e;
extern int DAT_0600e920;
extern int DAT_0600e922;
extern int DAT_0600e9e2;
extern int DAT_0600e9e4;
extern int DAT_0600e9e6;
extern int DAT_0600e9e8;
extern int DAT_0600e9ea;
extern int DAT_0600ea76;
extern int DAT_0600eafa;
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
extern int DAT_0600f462;
extern int DAT_0600f612;
extern int DAT_0600f614;
extern int DAT_0600f616;
extern int DAT_0600f618;
extern int DAT_0600f61a;
extern int DAT_06010042;
extern int DAT_06010044;
extern int DAT_06010046;
extern int DAT_060100f2;
extern int DAT_060100f4;
extern unsigned int FUN_0600ffd0();
extern int FUN_060100a4();
extern int PTR_DAT_0600e3f8;
extern int PTR_DAT_0600e458;
extern int PTR_DAT_0600e874;
extern int PTR_DAT_0600e924;
extern int PTR_DAT_0600e9ec;
extern int PTR_DAT_0600ea78;
extern int PTR_DAT_0600eafc;
extern int PTR_DAT_0600f154;
extern int PTR_DAT_0600f34c;
extern int PTR_DAT_0600f520;
extern int func_06011094();
extern int func_060114AC();
extern short DAT_0600e79c;
extern short DAT_0600e79e;
extern short DAT_0600ebd8;
extern short counter_0607887C;

/* FUN_0600e060: L2 version in visual_physics_update.c */
extern void FUN_0600E060(void);
void FUN_0600e060(void) { FUN_0600E060(); }

/* FUN_0600e0c0: L2 version in per_car_loop.c */
extern void FUN_0600E0C0(void);
void FUN_0600e0c0(void) { FUN_0600E0C0(); }

/* car_spawn_init -- Initialize car parameters at spawn.
 * Reads car type descriptor (12 bytes at 0x06047DE4), sets grip/speed,
 * determines difficulty multiplier from course+transmission lookup,
 * positions car at spawn point (0x06078680), copies rotation angles,
 * and looks up ground height at initial position. */
void FUN_0600e1d4()
{
  unsigned short grip_value;
  char *transmission_ptr;  /* 0x0607EAD8 */
  char *spawn_point;       /* 0x06078680 */
  int field_offset;
  int computed_val;
  int temp;
  unsigned int difficulty_idx;
  int *car_type_desc;
  int car_ptr;
  char height_buf[8];
  spawn_point = (char *)0x06078680;
  transmission_ptr = (char *)0x0607EAD8;
  car_ptr = CAR_PTR_CURRENT;
  *(int *)(car_ptr + DAT_0600e2ba) = 0;
  /* Read car type descriptor (12 bytes per type, indexed by car+4) */
  car_type_desc = (int *)(0x06047DE4 + *(int *)(car_ptr + 4) * 0xc);
  grip_value = *(unsigned short *)((int)car_type_desc + 6);
  field_offset = 0x1f0;
  *(unsigned int *)(car_ptr + field_offset) = (unsigned int)grip_value;
  *(unsigned int *)(car_ptr + field_offset + -8) = (unsigned int)grip_value;
  /* Compute initial speed parameter */
  computed_val = (*(int(*)())0x06035C2C)();
  *(int *)(DAT_0600e2be + car_ptr) = computed_val;
  *(int *)(car_ptr + DAT_0600e2c0) =
       *(int *)(0x06085FD0 + (unsigned int)*(unsigned short *)(car_type_desc + 1) << 2);
  *(unsigned int *)(car_ptr + DAT_0600e2c2) = (unsigned int)*(unsigned short *)(car_type_desc + 2);
  /* Determine difficulty/speed multiplier from course + transmission */
  difficulty_idx = (unsigned int)((unsigned char *)0x06047DD0)
                      [*(int *)0x0605AD04 + (int)(char)((char)*(int *)transmission_ptr * '\x05')]
          + COURSE_SELECT;
  if (*(int *)0x06086030 != '\0') {
    difficulty_idx = (unsigned int)(unsigned char)((int *)0x06047DDF)[*(int *)transmission_ptr];
  }
  /* Apply difficulty multiplier to base speed */
  computed_val = (*(int(*)())0x06027552)(*(int *)(0x06047D8C + (difficulty_idx << 2)),*car_type_desc);
  *(int *)(DAT_0600e2c4 + car_ptr) = computed_val;
  computed_val = (*(int(*)())0x06027552)(*(int *)(car_ptr + DAT_0600e2c4),0x372f);
  *(int *)(DAT_0600e2c8 + car_ptr) = computed_val;
  /* Set initial race position flags */
  if (*(int *)(car_ptr + DAT_0600e2be) <
      (int)(*(int *)0x0607EA9C + (unsigned int)(*(int *)0x0607EA9C < 0)) >> 1) {
    *(int *)(car_ptr + DAT_0600e2ca) = 0;
  }
  else {
    *(int *)(car_ptr + DAT_0600e3e8) = 0xffffffff;
  }
  *(int *)(car_ptr + DAT_0600e3ea + -8) = *(int *)(car_ptr + DAT_0600e3ea);
  /* Set model/palette based on car slot parity and transmission */
  difficulty_idx = *(unsigned int *)(car_ptr + 4) & 1;
  if (*(int *)transmission_ptr == 0) {
    if (difficulty_idx == 0) {
      *(int *)(car_ptr + DAT_0600e3ec + 0x7c) = 0x180;
      *(char **)(car_ptr + 0xc) = 0x00042000;     /* model data pointer */
      temp = (int)DAT_0600e3f4;
      field_offset = (int)DAT_0600e3f2;
      *(int *)(car_ptr + field_offset) = temp;
      *(int *)(car_ptr + field_offset + -4) = temp;
    }
    else {
      *(int *)(car_ptr + DAT_0600e3f0) = 0x580;
      *(char **)(car_ptr + 0xc) = 0x00042E38;
    }
  }
  else {
    if (difficulty_idx == 0) {
      *(int *)(car_ptr + DAT_0600e3f0) = 0x580;
    }
    else {
      *(int *)(car_ptr + DAT_0600e3ec + 0x7c) = 0x180;
    }
    field_offset = (int)DAT_0600e3f2;
    *(int *)(car_ptr + field_offset) = 0;
    *(int *)(car_ptr + field_offset + -4) = 0;
  }
  *(int *)(car_ptr + DAT_0600e3f0 + -4) = *(int *)(car_ptr + DAT_0600e3f0);
  /* Position car at spawn point */
  (*(int(*)())0x0600CA96)(spawn_point);
  *(int *)(car_ptr + 0x10) = *(int *)spawn_point;           /* X */
  *(int *)(car_ptr + 0x18) = *(int *)(spawn_point + 8);     /* Z */
  /* Override heading for car 0 on course 2 */
  if ((*(int *)(car_ptr + 4) == 0) && (*(int *)transmission_ptr == 2)) {
    *(short *)(spawn_point + 0xe) = DAT_0600e3f6;
  }
  /* Look up ground height at spawn position */
  computed_val = (*(int(*)())0x06006838)(*(int *)(car_ptr + 0x10),*(int *)(car_ptr + 0x18));
  (*(int(*)())0x06027EDE)(computed_val,car_ptr + 0x10,height_buf);
  /* Copy rotation from spawn point angles */
  *(int *)(car_ptr + 0x1c) = (int)*(short *)(spawn_point + 0xc);    /* roll */
  *(int *)(car_ptr + 0x20) = (int)*(short *)(spawn_point + 0xe);    /* heading */
  *(int *)(car_ptr + 0x24) = (int)*(short *)(spawn_point + 0x10);   /* pitch */
  /* Copy heading to multiple rotation state fields */
  *(int *)(car_ptr + 0x30) = *(int *)(car_ptr + 0x20);
  *(int *)(car_ptr + 0x34) = *(int *)(car_ptr + 0x20);
  *(int *)(car_ptr + 0x28) = *(int *)(car_ptr + 0x20);
  *(int *)(car_ptr + PTR_DAT_0600e3f8) = *(int *)(car_ptr + 0x20);
  return;
}

/* FUN_0600e410: L2 version in physics_entry.c */
extern void FUN_0600E410(void);
void FUN_0600e410(void) { FUN_0600E410(); }

/* FUN_0600e47c: L2 version in physics_entry.c */
extern void FUN_0600E47C(void);
void FUN_0600e47c(void) { FUN_0600E47C(); }

/* FUN_0600e4f2: L2 version in physics_entry.c */
extern void FUN_0600E4F2(void);
void FUN_0600e4f2(void) { FUN_0600E4F2(); }

/* FUN_0600e71a: L2 version in player_physics.c */
extern void FUN_0600E71A(void);
void FUN_0600e71a(void) { FUN_0600E71A(); }

/* FUN_0600e7c8: L2 version in alt_physics.c */
extern void FUN_0600E7C8(void);
void FUN_0600e7c8(void) { FUN_0600E7C8(); }

/* FUN_0600e906: L2 version in ai_physics.c */
extern void FUN_0600E906(void);
void FUN_0600e906(void) { FUN_0600E906(); }

/* FUN_0600e99c: L2 version in camera_setup.c */
extern void FUN_0600E99C(void);
void FUN_0600e99c(void) { FUN_0600E99C(); }

/* FUN_0600ea18: L2 version in road_recovery.c */
extern void FUN_0600EA18(int car);
void FUN_0600ea18(int car) { FUN_0600EA18(car); }

/* FUN_0600eb14: L2 version in race_init.c */
extern void FUN_0600EB14(void);
void FUN_0600eb14(void) { FUN_0600EB14(); }

/* vdp1_race_sprites_init -- register all VDP1 sprites and palettes for the racing scene */
void FUN_0600ec78()
{
  char *vdp1_cmd_base;
  char *vram_base;
  char *char_register;
  char *sprite_table;
  char *dma_copy;
  int vdp1_offset;
  int preview_size;
  int palette_size;

  (*(int(*)())0x0600A140)(); /* car_state_reset */

  /* Set up VDP1 command buffer addresses */
  vdp1_cmd_base = (char *)0x06063F5C;
  vdp1_offset = *(int *)(0x06059FFC << 3) + *(int *)0x06063F5C;
  preview_size = vdp1_offset + 0x40;
  *(int *)0x06078884 = preview_size;       /* vdp1_target_a */
  palette_size = 0xc0;
  *(int *)0x06078880 = preview_size + palette_size; /* vdp1_target_b */

  /* Set up sprite DMA chain (3 entries, stride 0x20) */
  sprite_table = (char *)0x06078888;
  *(int *)0x06078888 = vdp1_offset + DAT_0600ed62;
  *(int *)(sprite_table + 4) = *(int *)sprite_table + 0x20;
  *(int *)(sprite_table + 8) = *(int *)sprite_table + 0x40;

  *(int *)0x0606A4F4 = 0;
  *(int *)0x0606A4EC = (int)DAT_0600ed64;

  /* BIOS interrupt setup */
  (*(int(*)())(BIOS_FUNC_0344))(0xffffffff,0x83);
  (*(int(*)())0x06012E00)(); /* scenery_init */
  (*(int(*)())(BIOS_FUNC_0344))(-132,0);

  /* DMA base VDP1 command table */
  (*(int(*)())0x0602766C)(*(int *)vdp1_cmd_base,0x0605A018,0x60);
  VDP1_CMD_BASE_PTR = 3;
  *(short *)(*(int *)vdp1_cmd_base + 0x60) = (short)0x00008000; /* end-of-list marker */
  *(short *)0x06089E44 = 0;

  /* Register 57 character sprites (IDs 1-0x39) via char_register(id, size, flags, vram_addr) */
  vram_base = (char *)0x002A0000; /* VDP1 VRAM base */
  char_register = (char *)0x06007658;
  preview_size = 0x108;

  (*(int(*)())0x06007658)(1,preview_size,0,0x002A0000 + DAT_0600ed6c);
  (*(int(*)())char_register)(2,0x810,0,vram_base + DAT_0600ed6e);
  (*(int(*)())char_register)(3,(int)DAT_0600ed74,0,vram_base + DAT_0600ed72);
  (*(int(*)())char_register)(4,(int)DAT_0600ed78,0,vram_base + DAT_0600ed76);
  (*(int(*)())char_register)(5,0x519,0,vram_base + DAT_0600ed7a);
  (*(int(*)())char_register)(6,(int)DAT_0600ed80,0,vram_base + DAT_0600ed7e);
  (*(int(*)())char_register)(7,0x738,4,vram_base + DAT_0600eeba);
  (*(int(*)())char_register)(8,0x738,4,vram_base + DAT_0600eebe);
  (*(int(*)())char_register)(9,0x208,0,vram_base + DAT_0600eec0);
  (*(int(*)())char_register)(10,0xa28,0x3c,vram_base + DAT_0600eec4);
  /* HUD elements (IDs 0x10-0x18) */
  (*(int(*)())char_register)(0x10,0x228,8,vram_base + DAT_0600eec8);
  (*(int(*)())char_register)(0x11,0x428,8,vram_base + DAT_0600eecc);
  (*(int(*)())char_register)(0x12,0x418,8,vram_base + DAT_0600eed0);
  (*(int(*)())char_register)(0x13,0x820,8,vram_base + DAT_0600eed4);
  (*(int(*)())char_register)(0x14,0x518,8,vram_base + DAT_0600eed8);
  (*(int(*)())char_register)(0x15,0x518,8,vram_base + DAT_0600eedc);
  (*(int(*)())char_register)(0x16,0x508,0xc,vram_base + DAT_0600eede);
  (*(int(*)())char_register)(0x17,0xd10,8,vram_base + DAT_0600eee2);
  (*(int(*)())char_register)(0x18,(int)DAT_0600eee8,0x1c,vram_base + DAT_0600eee6);
  /* Wheel/tire sprites (IDs 0x19-0x1f) */
  preview_size = 0x348;
  (*(int(*)())char_register)(0x19,preview_size,0x10,vram_base + DAT_0600eeec);
  (*(int(*)())char_register)(0x1a,preview_size,0x10,vram_base + DAT_0600eeee);
  (*(int(*)())char_register)(0x1b,preview_size,0x10,vram_base + DAT_0600eef0);
  (*(int(*)())char_register)(0x1c,0x630,0x1c,vram_base + DAT_0600eef2);
  (*(int(*)())char_register)(0x1d,0xa28,0x10,vram_base + DAT_0600eef6);
  (*(int(*)())char_register)(0x1e,0xc08,0x18,vram_base + DAT_0600eef8);
  (*(int(*)())char_register)(0x1f,0xc10,0x18,vram_base + DAT_0600eefc);
  /* Track object sprites (IDs 0x20-0x31) */
  preview_size = 0x308;
  (*(int(*)())char_register)(0x20,preview_size,0xc,vram_base + DAT_0600effe);
  (*(int(*)())char_register)(0x21,0x410,0xc,vram_base + DAT_0600f000);
  (*(int(*)())char_register)(0x22,preview_size,0xc,vram_base + DAT_0600f004);
  (*(int(*)())char_register)(0x23,preview_size,0xc,vram_base + DAT_0600f006);
  (*(int(*)())char_register)(0x24,0x410,0xc,vram_base + DAT_0600f008);
  (*(int(*)())char_register)(0x25,(int)DAT_0600f00c,0x14,vram_base + DAT_0600f00a);
  (*(int(*)())char_register)(0x26,(int)DAT_0600f00c,0x14,vram_base + DAT_0600f00e);
  (*(int(*)())char_register)(0x27,0x610,0xc,vram_base + DAT_0600f010);
  (*(int(*)())char_register)(0x28,0x510,0x14,vram_base + DAT_0600f014);
  (*(int(*)())char_register)(0x29,0x310,0x14,vram_base + DAT_0600f018);
  (*(int(*)())char_register)(0x2a,(int)DAT_0600f01e,0x14,vram_base + DAT_0600f01c);
  (*(int(*)())char_register)(0x2b,(int)DAT_0600f022,0x14,vram_base + DAT_0600f020);
  (*(int(*)())char_register)(0x2c,0x110,0xc,vram_base + DAT_0600f024);
  (*(int(*)())char_register)(0x2d,0x110,0xc,vram_base + DAT_0600f028);
  (*(int(*)())char_register)(0x2e,0x510,0x14,vram_base + DAT_0600f02a);
  (*(int(*)())char_register)(0x2f,0x310,0x14,vram_base + DAT_0600f02c);
  (*(int(*)())char_register)(0x30,(int)DAT_0600f01e,0x14,vram_base + DAT_0600f02e);
  (*(int(*)())char_register)(0x31,(int)DAT_0600f022,0x14,vram_base + DAT_0600f030);
  /* Scenery/billboard sprites (IDs 0x32-0x39) */
  vdp1_offset = 0x108;
  (*(int(*)())char_register)(0x32,vdp1_offset,0x14,vram_base + DAT_0600f032);
  (*(int(*)())char_register)(0x33,vdp1_offset,0x14,vram_base + DAT_0600f034);
  (*(int(*)())char_register)(0x34,vdp1_offset,0x14,vram_base + DAT_0600f036);
  (*(int(*)())char_register)(0x35,vdp1_offset,0x14,vram_base + DAT_0600f14c);
  (*(int(*)())char_register)(0x36,vdp1_offset,0x10,vram_base + DAT_0600f14e);
  (*(int(*)())char_register)(0x37,vdp1_offset,0x1c,vram_base + DAT_0600f150);
  (*(int(*)())char_register)(0x38,vdp1_offset,8,vram_base + DAT_0600f152);
  (*(int(*)())char_register)(0x39,vdp1_offset,0x10,vram_base + PTR_DAT_0600f154);

  *(short *)0x06089E46 = 1;

  /* Register 57 sprite table entries (IDs 0x41-0x79) via sprite_table(cmd_id, char_id, priority) */
  sprite_table = (char *)0x06007540;
  (*(int(*)())0x06007540)(0x41,1,0);
  (*(int(*)())sprite_table)(0x42,2,0);
  (*(int(*)())sprite_table)(0x43,3,0);
  (*(int(*)())sprite_table)(0x44,4,0);
  (*(int(*)())sprite_table)(0x45,5,0);
  (*(int(*)())sprite_table)(0x46,6,0);
  (*(int(*)())sprite_table)(0x47,7,4);
  (*(int(*)())sprite_table)(0x48,8,4);
  (*(int(*)())sprite_table)(0x49,9,0);
  (*(int(*)())sprite_table)(0x4a,10,0x3c);
  /* HUD sprite entries (0x50-0x58) */
  (*(int(*)())sprite_table)(0x50,0x10,0x20);
  (*(int(*)())sprite_table)(0x51,0x11,0x20);
  (*(int(*)())sprite_table)(0x52,0x12,0x20);
  (*(int(*)())sprite_table)(0x53,0x13,0x20);
  (*(int(*)())sprite_table)(0x54,0x14,0x20);
  (*(int(*)())sprite_table)(0x55,0x15,0x20);
  (*(int(*)())sprite_table)(0x56,0x16,0x24);
  (*(int(*)())sprite_table)(0x57,0x17,0x20);
  (*(int(*)())sprite_table)(0x58,0x18,0x34);
  /* Wheel/tire entries (0x59-0x5f) */
  (*(int(*)())sprite_table)(0x59,0x19,0x28);
  (*(int(*)())sprite_table)(0x5a,0x1a,0x28);
  (*(int(*)())sprite_table)(0x5b,0x1b,0x28);
  (*(int(*)())sprite_table)(0x5c,0x1c,0x34);
  (*(int(*)())sprite_table)(0x5d,0x1d,0x28);
  (*(int(*)())sprite_table)(0x5e,0x1e,0x30);
  (*(int(*)())sprite_table)(0x5f,0x1f,0x30);
  /* Track object entries (0x60-0x79) */
  (*(int(*)())sprite_table)(0x60,0x20,0x24);
  (*(int(*)())sprite_table)(0x61,0x21,0x24);
  (*(int(*)())sprite_table)(0x62,0x22,0x24);
  (*(int(*)())sprite_table)(99,0x23,0x24);
  (*(int(*)())sprite_table)(100,0x24);
  (*(int(*)())sprite_table)(0x65,0x25,0x2c);
  (*(int(*)())sprite_table)(0x66,0x26,0x2c);
  (*(int(*)())sprite_table)(0x67,0x27,0x24);
  (*(int(*)())sprite_table)(0x68,0x28,0x2c);
  (*(int(*)())sprite_table)(0x69,0x29,0x2c);
  (*(int(*)())sprite_table)(0x6a,0x2a,0x2c);
  (*(int(*)())sprite_table)(0x6b,0x2b,0x2c);
  (*(int(*)())sprite_table)(0x6c,0x2c,0x24);
  (*(int(*)())sprite_table)(0x6d,0x2d,0x24);
  (*(int(*)())sprite_table)(0x6e,0x2e,0x2c);
  (*(int(*)())sprite_table)(0x6f,0x2f,0x2c);
  (*(int(*)())sprite_table)(0x70,0x30,0x2c);
  (*(int(*)())sprite_table)(0x71,0x31,0x2c);
  (*(int(*)())sprite_table)(0x72,0x32,0x2c);
  (*(int(*)())sprite_table)(0x73,0x33,0x2c);
  (*(int(*)())sprite_table)(0x74,0x34,0x2c);
  (*(int(*)())sprite_table)(0x75,0x35,0x2c);
  (*(int(*)())sprite_table)(0x76,0x36,0x28);
  (*(int(*)())sprite_table)(0x77,0x37,0x34);
  (*(int(*)())sprite_table)(0x78,0x38,0x20);
  (*(int(*)())sprite_table)(0x79,0x39,0x28);

  /* Large overlay sprites (IDs 0x101-0x103, size 0xB40) */
  preview_size = 0xb40;
  (*(int(*)())char_register)(0x101,preview_size,0x78,vram_base + DAT_0600f26c);
  (*(int(*)())char_register)((int)DAT_0600f272,preview_size,0x7c,vram_base + DAT_0600f270);
  palette_size = 0x80;
  (*(int(*)())char_register)(0x103,preview_size,palette_size,vram_base + DAT_0600f276);
  (*(int(*)())sprite_table)((int)DAT_0600f344,DAT_0600f342 + 0x7d);
  (*(int(*)())sprite_table)((int)DAT_0600f348,DAT_0600f346 + 0x7a);
  (*(int(*)())sprite_table)((int)PTR_DAT_0600f34c,DAT_0600f34a + 0x77);

  /* VDP2 CRAM palette write */
  vdp1_cmd_base = (char *)0x06086028;
  *(short *)0x06086028 = (short)0x00008000;
  (*(int(*)())0x06036E90)(0x25F00FFE,1,vdp1_cmd_base); /* vdp2_cram_write */

  /* Initialize subsystems */
  (*(int(*)())0x060149E0)(); /* vdp1_sprite_table_init */
  (*(int(*)())0x0600A026)(); /* car_physics_init */
  (*(int(*)())0x0601D2DC)(); /* sound_init */

  /* Bulk DMA palette banks to VDP2 CRAM (0x25F0xxxx) — 12 banks, mirrored to both pages */
  dma_copy = (char *)0x0602761E;
  vram_base = (char *)0x060484EC;
  (*(int(*)())0x0602761E)(0x25F00060,0x060484EC,palette_size);
  (*(int(*)())dma_copy)(0x25F00460,vram_base,palette_size);
  vram_base = (char *)0x0604870C;
  (*(int(*)())dma_copy)(0x25F00520,0x0604870C,0x20);
  (*(int(*)())dma_copy)(0x25F00540,vram_base,0x20);
  vram_base = (char *)0x0604842C;
  (*(int(*)())dma_copy)(0x25F001A0,0x0604842C,0x40);
  (*(int(*)())dma_copy)(0x25F007A0,vram_base,0x40);
  vram_base = (char *)0x0604846C;
  (*(int(*)())dma_copy)(0x25F001E0,0x0604846C,0x20);
  (*(int(*)())dma_copy)(0x25F007E0,vram_base,0x20);
  (*(int(*)())dma_copy)(0x25F005A0,0x0605CA5C,0x40);
  vram_base = (char *)0x0604814C;
  (*(int(*)())dma_copy)(0x25F00000,0x0604814C,0x60);
  (*(int(*)())dma_copy)(0x25F00600,vram_base,0x60);
  (*(int(*)())dma_copy)(0x25F006A0,0x060484CC,0x20);
  vram_base = (char *)0x060487AC;
  (*(int(*)())dma_copy)(0x25F00120,0x060487AC,palette_size);
  (*(int(*)())dma_copy)(0x25F00720,vram_base,palette_size);
  vram_base = (char *)0x060487CC;
  (*(int(*)())dma_copy)(0x25F00680,0x060487CC,0x20);
  (*(int(*)())dma_copy)(0x25F00140,vram_base,0x20);
  vram_base = (char *)0x060483EC;
  (*(int(*)())dma_copy)(0x25F000C0,0x060483EC,0x20);
  (*(int(*)())dma_copy)(0x25F006C0,vram_base,0x20);

  /* Final initialization */
  *(short *)0x0605AAA0 = 0;    /* polygon_count = 0 */
  *(int *)0x0607887F = 0;
  dma_copy = (char *)0x06026CE0;
  INPUT_STATE = INPUT_STATE | 0x40000000; /* enable race input flag */
  (*(int(*)())dma_copy)();      /* matrix_pipeline_init */
  VBLANK_OUT_COUNTER = 0;

  return;
}

/* game_phase_render -- Render current game phase with overlay sprites.
 * Phase < 5 or 9: renders countdown/ready overlay via FUN_06028430
 *   (phase 9 uses priority 0xC, others use 8).
 * Phase > 9 with start button: processes course selection input from
 *   button masks at 0x06078656..0x0607865C → stores choice at 0x06078648.
 * Phase 8-11: renders transition sprites (normal mode uses FUN_060284AE,
 *   demo mode uses FUN_06028400 with course-specific data).
 * Finally resets primary matrix, dispatches phase handler from jump
 * table at 0x0605AC2C, calls FUN_0600ffd0 and FUN_060078DC. */
void FUN_0600f424()
{
    char *phase_ptr = (char *)0x0607887F;

    /* Countdown/ready overlay */
    if (((unsigned char)*(int *)0x0607887F < 5) || (*(int *)0x0607887F == 9)) {
        int vdp_pos = (*(int(*)())0x06034FE0)();
        if (*(int *)0x0607887F == '\t') {
            (*(int(*)())0x06028430)(0xc, 0x148, 0x18, vdp_pos);
        } else {
            (*(int(*)())0x06028430)(8, 0x148, 0x18, vdp_pos);
        }
    }

    /* Course selection input (phase > 9, start pressed, not locked) */
    if (((9 < (unsigned char)*phase_ptr) &&
        ((char *)(unsigned int)*(unsigned short *)0x0607865E == (char *)0x00008000)) &&
        (*(int *)0x0605AB18 == '\0')) {
        unsigned short buttons = *(unsigned short *)0x06063D98;
        if ((buttons & *(unsigned short *)0x06078656) == 0) {
            if ((buttons & *(unsigned short *)0x06078658) == 0) {
                if ((buttons & *(unsigned short *)0x0607865A) == 0) {
                    if ((buttons & *(unsigned short *)0x0607865C) != 0) {
                        *(int *)0x06078648 = 3;    /* course 3 */
                    }
                } else {
                    *(int *)0x06078648 = 2;        /* course 2 */
                }
            } else {
                *(int *)0x06078648 = 1;            /* course 1 */
            }
        } else {
            *(int *)0x06078648 = 0;                /* course 0 */
        }
    }

    /* Transition sprites (phase 8-11) */
    char *sprite_data = (char *)0x0605ACE4;
    if (((unsigned char)*phase_ptr < 0xc) && (8 < (unsigned char)*phase_ptr)) {
        int tile_off = (int)DAT_0600f612;
        if (DEMO_MODE_FLAG == 0) {
            (*(int(*)())0x060284AE)(0xc, tile_off, 0x90, sprite_data);
            (*(int(*)())0x060284AE)(0xc, (int)DAT_0600f618, 0x90, sprite_data);
            (*(int(*)())0x060283E0)(0xc, (int)DAT_0600f61a, 0, sprite_data);
        } else if (*(int *)0x06078644 == 1) {
            (*(int(*)())0x06028400)(0xc, *(int *)0x06063848, tile_off,
                       *(int *)(0x06063848 + 4) + (int)DAT_0600f614, 0x06063848);
        } else {
            (*(int(*)())0x06028400)(0xc, *(int *)0x06063850, tile_off,
                       *(int *)(0x06063850 + 4) + (int)DAT_0600f614, 0x06063850);
        }
    }

    /* Dispatch phase handler from jump table */
    (*(int(*)())0x06026DBC)();                     /* matrix_reset */
    (*(int(*)())(*(int *)(0x0605AC2C + ((unsigned int)(unsigned char)(*phase_ptr) << 2))))();
    FUN_0600ffd0();
    OBJ_STATE_PRIMARY = OBJ_STATE_PRIMARY + -0x30;
    (*(int(*)())0x060078DC)();                     /* post-phase cleanup */
}

/* subsystem_countdown_step -- Run subsystem handlers then decrement countdown.
 * When countdown reaches 0, sets mode flag to 4 (transition). */
void FUN_0600f870(void)
{
    short val;
    func_060114AC(0);
    func_06011094();
    val = counter_0607887C;
    counter_0607887C = val - 1;
    if ((short)(val - 1) <= 0) {
        flag_0607887F = 4;
    }
}

/* countdown_overlay_render -- Render race countdown number sprites.
 * Calls FUN_060100a4 three times (layers 0-2), then renders the
 * countdown digit sprite when phase < 5 or == 9.
 * Phase 9 (GO!) uses priority 0xC; phases 0-4 use priority 8.
 * Mirror mode (0x06078663 != 0) uses alternate sprite set at 0x0605AB19
 * and increments position offset up to 0xC. Normal mode decrements. */
unsigned int FUN_0600ffd0()
{
  short sprite_id;
  int priority;
  unsigned int result;
  char *phase = (char *)0x0607887F;           /* countdown phase (0-9) */
  unsigned int idx = 0;
  /* render 3 overlay layers */
  do {
    FUN_060100a4(idx);
    idx = idx + 1;
  } while ((idx & 0xff) < 3);
  if (*(int *)0x06078663 == '\0') {
    /* normal mode */
    if (*(int *)0x0605AA98 != 0) {
      *(int *)0x0605AA98 = *(int *)0x0605AA98 + -1;  /* decrement position offset */
    }
    result = (unsigned int)(unsigned char)*phase;
    if ((result < 5) || (result == 9)) {
      if (*phase == '\t') {
        priority = 0xc;                     /* GO! gets high priority */
        sprite_id = DAT_06010044;
      } else {
        priority = 8;
        sprite_id = DAT_06010046;
      }
      result = (*(int(*)())0x060284AE)(priority, (int)sprite_id, 0x90, 0x0605ACE4);
    }
  } else {
    /* mirror mode */
    if (*(int *)0x0605AA98 != 0xc) {
      *(int *)0x0605AA98 = *(int *)0x0605AA98 + 1;  /* increment position offset */
    }
    result = (unsigned int)(unsigned char)*phase;
    if ((result < 5) || (result == 9)) {
      if (*phase == '\t') {
        priority = 0xc;
        sprite_id = DAT_060100f2;
      } else {
        priority = 8;
        sprite_id = DAT_060100f4;
      }
      result = (*(int(*)())0x060284AE)(priority, (int)sprite_id, 0x90, 0x0605AB19);
    }
  }
  return result;
}
