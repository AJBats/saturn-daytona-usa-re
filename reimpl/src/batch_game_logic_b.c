#include "game.h"

extern int DAT_0600c2a6;
extern int DAT_0600c36a;
extern int DAT_0600c36c;
extern int DAT_0600c36e;
extern int DAT_0600c370;
extern int DAT_0600c372;
extern int DAT_0600c416;
extern int DAT_0600c418;
extern int DAT_0600c41a;
extern int DAT_0600c616;
extern int DAT_0600c6f6;
extern int DAT_0600c6f8;
extern int DAT_0600c6fa;
extern int DAT_0600c6fc;
extern int DAT_0600c6fe;
extern int DAT_0600c700;
extern int DAT_0600c702;
extern int DAT_0600c7be;
extern int DAT_0600c7c0;
extern int DAT_0600c8b6;
extern int DAT_0600c8b8;
extern int DAT_0600c8ba;
extern int DAT_0600c8bc;
extern int DAT_0600c8be;
extern int DAT_0600c8c0;
extern int DAT_0600c8c2;
extern int DAT_0600c962;
extern int DAT_0600c964;
extern int DAT_0600c9e4;
extern int DAT_0600c9e6;
extern int DAT_0600cac0;
extern int DAT_0600cac2;
extern int DAT_0600cb84;
extern int DAT_0600cb86;
extern int DAT_0600cc2a;
extern int DAT_0600ccf6;
extern int DAT_0600ccf8;
extern int DAT_0600ccfa;
extern int DAT_0600cdbc;
extern int DAT_0600cdbe;
extern int DAT_0600cdc0;
extern int DAT_0600cdc2;
extern int DAT_0600ce8e;
extern int DAT_0600cf3a;
extern int DAT_0600cf40;
extern int DAT_0600cf42;
extern int DAT_0600cfe2;
extern int DAT_0600cfe4;
extern int DAT_0600cfe6;
extern int DAT_0600d0aa;
extern int DAT_0600d0ac;
extern int DAT_0600d0ae;
extern int DAT_0600d0b0;
extern int DAT_0600d0b2;
extern int DAT_0600d0b4;
extern int DAT_0600d0b6;
extern int DAT_0600d112;
extern int DAT_0600d114;
extern int DAT_0600d116;
extern int DAT_0600d118;
extern int DAT_0600d11a;
extern int DAT_0600d192;
extern int DAT_0600d1fa;
extern int DAT_0600d1fc;
extern int DAT_0600d1fe;
extern int DAT_0600d200;
extern int DAT_0600d202;
extern int DAT_0600d204;
extern int DAT_0600d206;
extern int DAT_0600d26a;
extern int DAT_0600d26c;
extern int DAT_0600d26e;
extern int DAT_0600d270;
extern int DAT_0600d272;
extern int DAT_0600d4a6;
extern int DAT_0600d534;
extern int DAT_0600d536;
extern int DAT_0600d5d6;
extern int DAT_0600d6ba;
extern int DAT_0600d76a;
extern int DAT_0600d82a;
extern int DAT_0600d82c;
extern int DAT_0600d82e;
extern int DAT_0600d894;
extern int DAT_0600d896;
extern int DAT_0600d996;
extern int DAT_0600d998;
extern int DAT_0600d99a;
extern int DAT_0600db40;
extern int DAT_0600db44;
extern int DAT_0600db46;
extern int DAT_0600dbda;
extern int DAT_0600dbdc;
extern int DAT_0600dbde;
extern int DAT_0600dc98;
extern int DAT_0600dc9a;
extern int DAT_0600dc9c;
extern int DAT_0600dc9e;
extern int DAT_0600dd62;
extern int DAT_0600de1e;
extern int DAT_0600deb2;
extern int FUN_0600c970();
extern void FUN_0600d37c();
extern void FUN_0600d3c4();
extern void FUN_0600d50c();
extern int FUN_0600d84c();
extern int FUN_0600d8a4();
extern unsigned int FUN_0600db9e();
extern int FUN_0600e0c0();
extern int FUN_0600e410();
extern int FUN_0600e47c();
extern int FUN_0600e4f2();
extern int FUN_0600e99c();
extern int PTR_DAT_0600c2a8;
extern int PTR_DAT_0600c374;
extern int PTR_DAT_0600c618;
extern int PTR_DAT_0600cb88;
extern int PTR_DAT_0600cfe8;
extern int PTR_DAT_0600d11c;
extern int PTR_DAT_0600d194;
extern int PTR_DAT_0600d208;
extern int PTR_DAT_0600d274;
extern int PTR_DAT_0600d304;
extern int PTR_DAT_0600d408;
extern int PTR_DAT_0600d770;
extern int PTR_DAT_0600d99c;
extern short DAT_0600c590;
extern short DAT_0600c594;
extern short DAT_0600c596;
extern short DAT_0600c598;
extern short DAT_0600c59a;
extern short DAT_0600ce86;
extern short DAT_0600ce88;
extern short DAT_0600ce8a;
extern short DAT_0600ce8c;
extern short DAT_0600d404;
extern short DAT_0600d406;
extern short PTR_DAT_0600c59c;

/* render_frame_basic -- Basic render frame for single-player race replay.
 * Copies primary render state to secondary (+0x30 block), runs main rendering
 * pipeline (camera, world tiles, objects), waits for VDP1 completion,
 * then restores secondary state. */
#if 0 /* FUN_0600C218 -- replaced by ASM import */
void FUN_0600c218(void)
{
    unsigned short ready_mask = PTR_DAT_0600c2a8;
    unsigned char *vdp_status = (unsigned char *)-495;  /* VDP1 status port */
    int saved = OBJ_STATE_SECONDARY;

    OBJ_STATE_SECONDARY = saved + 0x30;
    (*(int(*)())0x06027630)(saved + 0x30, OBJ_STATE_PRIMARY, 0x30);  /* memcpy render state */

    (*(int(*)())0x0600D31C)();                /* camera update */
    *(int *)0x06063574 = 0x0600C286;          /* set render callback */
    *(short *)0x21000000 = (short)0x0000FFFF; /* SCU DMA trigger */
    (*(int(*)())0x060058FA)();                /* HUD sprites */
    (*(int(*)())0x06006868)();                /* world tile rendering */
    (*(int(*)())0x0601BDEC)();                /* object rendering */

    /* Wait for VDP1 draw completion */
    do { } while ((*vdp_status & ready_mask) != ready_mask);
    *vdp_status = *vdp_status & 0xf;

    (*(int(*)())0x0603C000)();                /* finalize frame */
    OBJ_STATE_SECONDARY -= 0x30;
}
#endif

/* FUN_0600c302: L2 version in car_iteration.c */
extern void FUN_0600C302(void);
void FUN_0600c302(void) { FUN_0600C302(); }

/* camera_view_select -- Select camera view based on controller input.
 *
 * Pool verified (0x0600C41C-0x0600C4DC):
 *   0x0600C41C = 0x06063E20 (CAMERA_MODE)
 *   0x0600C420 = 0x06083255 (RENDER_FLAG_BYTE)
 *   0x0600C424 = 0x0607865E (CAM_MODE_SELECTOR)
 *   0x0600C428 = 0x00008000 (CAM_DIRECT_MODE)
 *   0x0600C42C = 0x06078656 (CAM_BTN_CLOSE)
 *   0x0600C430 = 0x06078658 (CAM_BTN_FAR)
 *   0x0600C434 = 0x0607865A (CAM_BTN_BUMPER)
 *   0x0600C438 = 0x0607865C (CAM_BTN_REAR)
 *
 * In direct mode (selector == 0x8000), buttons map to views 0-3.
 * In cycle mode, increment/decrement with wrap based on render flag.
 * After mode selection, sets PHASE_FLAG for render distance if in race.
 *
 * Called from game logic with edge-triggered controller input. */
#define CAMERA_MODE           (*(volatile int *)0x06063E20)
#define CAMERA_PHASE_REF      (*(volatile int *)0x06063E1C)
#define CAM_MODE_SELECTOR     (*(volatile unsigned short *)0x0607865E)
#define CAM_BTN_CLOSE         (*(volatile unsigned short *)0x06078656)
#define CAM_BTN_FAR           (*(volatile unsigned short *)0x06078658)
#define CAM_BTN_BUMPER        (*(volatile unsigned short *)0x0607865A)
#define CAM_BTN_REAR          (*(volatile unsigned short *)0x0607865C)
#define CAM_CYCLE_BTN         (*(volatile unsigned short *)0x06078660)
#define CAM_MAX_MODE          (*(volatile int *)0x06078662)
#define CAM_DIRECT_MODE       0x8000
unsigned short camera_view_select(input_buttons)
    unsigned short input_buttons;
{
    unsigned short result;
    int new_mode;
    short phase;

    if ((unsigned int)CAM_MODE_SELECTOR == CAM_DIRECT_MODE) {
        /* Direct mode: each button selects a specific camera view */
        if ((input_buttons & CAM_BTN_CLOSE) != 0) {
            CAMERA_MODE = 0;
        } else if ((input_buttons & CAM_BTN_FAR) != 0) {
            if (*(int *)0x06083255 == '\0') {
                CAMERA_MODE = 1;
            }
        } else if ((input_buttons & CAM_BTN_BUMPER) != 0) {
            CAMERA_MODE = 2;
        } else if ((input_buttons & CAM_BTN_REAR) != 0) {
            CAMERA_MODE = 3;
        }
    } else if (((input_buttons & CAM_MODE_SELECTOR) == 0) || (CAMERA_MODE == 0)) {
        /* Cycle up: increment camera mode */
        if (((input_buttons & CAM_CYCLE_BTN) != 0) &&
           ((unsigned int)CAMERA_MODE < (unsigned int)(int)(char)CAM_MAX_MODE)) {
            if ((*(int *)0x06083255 == '\0') || (CAMERA_MODE != 0)) {
                CAMERA_MODE = CAMERA_MODE + 1;
            } else {
                CAMERA_MODE = CAMERA_MODE + 2;
            }
        }
    } else {
        /* Cycle down: decrement camera mode */
        if ((*(int *)0x06083255 == '\0') || (CAMERA_MODE != 2)) {
            new_mode = CAMERA_MODE + -1;
        } else {
            new_mode = CAMERA_MODE + -2;
        }
        CAMERA_MODE = new_mode;
    }

    /* Set render phase flag based on camera distance */
    result = (unsigned short)(unsigned char)*(int *)0x06078635;
    if ((result == 0) && (result = *(unsigned short *)0x0607ED8C, result != 0)) {
        if ((unsigned int)(CAMERA_PHASE_REF + CAMERA_MODE) < 7) {
            phase = 4;
        } else {
            phase = 3;
        }
        PHASE_FLAG = phase;
    }

    return result;
}
#undef CAMERA_MODE
#undef CAMERA_PHASE_REF
#undef CAM_MODE_SELECTOR
#undef CAM_BTN_CLOSE
#undef CAM_BTN_FAR
#undef CAM_BTN_BUMPER
#undef CAM_BTN_REAR
#undef CAM_CYCLE_BTN
#undef CAM_MAX_MODE
#undef CAM_DIRECT_MODE

/* FUN_0600c4f8: L2 version in player_physics.c */
extern void FUN_0600C4F8(void);
#if 0 /* FUN_0600C4F8 -- replaced by ASM import */
void FUN_0600c4f8(void) { FUN_0600C4F8(); }
#endif

/* FUN_0600c5d6: L2 version in player_physics.c */
extern void FUN_0600C5D6(void);
#if 0 /* FUN_0600C5D6 -- replaced by ASM import of original bytes */
void FUN_0600c5d6(void) { FUN_0600C5D6(); }
#endif

/* FUN_0600c74e: L2 version in ai_physics.c */
extern void FUN_0600C74E(void);
#if 0 /* FUN_0600C74E -- replaced by ASM import */
void FUN_0600c74e(void) { FUN_0600C74E(); }
#endif

/* FUN_0600c7d4: L2 version in physics_helpers.c */
extern void FUN_0600C7D4(int car, int course_data);
void FUN_0600c7d4(int car, int course_data) { FUN_0600C7D4(car, course_data); }

/* FUN_0600c8cc: L2 version in physics_helpers.c */
extern void FUN_0600C8CC(int car, int course_data);
#if 0 /* FUN_0600C8CC -- replaced by ASM import */
void FUN_0600c8cc(int car, int course_data) { FUN_0600C8CC(car, course_data); }
#endif

/* FUN_0600c928: L2 version in physics_helpers.c */
extern void FUN_0600C928(int car);
void FUN_0600c928(int car) { FUN_0600C928(car); }

/* car_speed_curve_apply -- Apply speed curve adjustment from lookup table.
 * Reads checkpoint param (+0x1EC) from car struct; if in range 0x45-0x62,
 * adds speed delta from table at 0x0605A1E0 to CAR_ACCEL (+0x0C).
 * Table is indexed by (checkpoint_param - 0x45). */
int FUN_0600c970(int param_1)
{
    int checkpoint_param = *(int *)(param_1 + CAR_CHECKPOINT_PARAM);

    if (checkpoint_param > 0x44 && checkpoint_param < 99) {
        *(int *)(param_1 + CAR_ACCEL) +=
            (int)*(short *)(0x0605A1E0 + ((checkpoint_param - 0x45) << 1));
    }

    return CAR_CHECKPOINT_PARAM;
}

/* FUN_0600c994: L2 version in road_segment_find.c */
extern void FUN_0600C994(void);
void FUN_0600c994(void) { FUN_0600C994(); }

/* FUN_0600ca96: L2 version in course_correction.c */
extern void FUN_0600CA96(int r4);
void FUN_0600ca96(int r4) { FUN_0600CA96(r4); }

/* track_spline_sample -- Sample track spline at given parameter.
 * Even param_2: reads exact track point from spline table (0x0607EB88).
 * Odd param_2: interpolates between two adjacent points (average).
 * Spline index offset from car's +0x1F8 field, base at 0x0607EB88.
 * Writes X, Z position and rotation data into param_1 output buffer. */
#if 0 /* FUN_0600CB90 -- replaced by ASM import */
void FUN_0600cb90(param_1, param_2)
    int *param_1;
    unsigned int param_2;
{
    int *spline_pt;

    if ((param_2 & 1) == 0) {
        /* Exact point */
        spline_pt = (int *)(((*(unsigned int *)(CAR_PTR_CURRENT + 0x1f8) >> 8) +
                     ((param_2 & 0xffff) >> 1) << 3) << 4 + *(int *)0x0607EB88);
        *param_1 = *spline_pt;
        param_1[2] = spline_pt[1];
    } else {
        /* Interpolate between two points */
        unsigned int next_idx = ((param_2 & 0xffff) >> 1) + 1;
        if (*(unsigned int *)0x0607EA9C < next_idx) {
            next_idx = 0;                        /* wrap around */
        }
        unsigned int base_off = *(unsigned int *)(CAR_PTR_CURRENT + 0x1f8) >> 8;
        spline_pt = (int *)((base_off + ((param_2 & 0xffff) >> 1) << 3) << 4 + *(int *)0x0607EB88);
        int *next_pt = (int *)((base_off + (next_idx << 3)) << 4 + *(int *)0x0607EB88);
        *param_1 = *spline_pt + *next_pt >> 1;
        param_1[2] = spline_pt[1] + next_pt[1] >> 1;
    }

    /* Copy rotation data */
    *(short *)(param_1 + 3) = *(short *)(spline_pt + 2);
    *(short *)((int)param_1 + 0xe) = *(short *)((int)spline_pt + 10) << 2;
    *(short *)(param_1 + 4) = *(short *)(spline_pt + 3);
    *(short *)((int)param_1 + 0x12) = 0;
}
#endif

/* FUN_0600cc38: L2 version in course_correction.c */
extern void FUN_0600CC38(int r4, int r5);
void FUN_0600cc38(int r4, int r5) { FUN_0600CC38(r4, r5); }

/* FUN_0600cd40: L2 version in lap_counting.c */
extern int FUN_0600CD40(void);
int FUN_0600cd40(void) { return FUN_0600CD40(); }

/* FUN_0600cdd0: L2 version in lap_counting.c */
extern void FUN_0600CDD0(void);
#if 0 /* FUN_0600CDD0 -- replaced by ASM import */
void FUN_0600cdd0(void) { FUN_0600CDD0(); }
#endif

/* FUN_0600ce66: L2 version in lap_counting.c */
extern void FUN_0600CE66(void);
#if 0 /* FUN_0600CE66 -- replaced by ASM import of original bytes */
void FUN_0600ce66(void) { FUN_0600CE66(); }
#endif

/* FUN_0600ceba: L2 version in player_physics.c */
extern void FUN_0600CEBA(void);
#if 0 /* FUN_0600CEBA -- replaced by ASM import */
void FUN_0600ceba(void) { FUN_0600CEBA(); }
#endif

/* FUN_0600cf58: L2 version in collision_response.c */
extern void FUN_0600CF58(int arg);
#if 0 /* FUN_0600CF58 -- replaced by ASM import of original bytes */
void FUN_0600cf58(int arg) { FUN_0600CF58(arg); }
#endif

/* FUN_0600d0b8: static L2 in collision_response.c, dead code here */
static void FUN_0600d0b8(void) { }
/* FUN_0600d12c: static L2 in collision_response.c, dead code here */
static void FUN_0600d12c(void) { }
/* FUN_0600d210: static L2 in collision_response.c, dead code here */
static void FUN_0600d210(void) { }

/* FUN_0600d266: L2 version in player_physics.c */
extern void FUN_0600D266(void);
void FUN_0600d266(void) { FUN_0600D266(); }

/* ranking_table_init -- Initialize car ranking pointer tables.
 * Clears two 40-entry ranking arrays at 0x0607E94C and 0x0607E9EC,
 * plus 3-word summary at 0x0607EA8C. Then fills both arrays with
 * pointers to car slots (CAR_ARRAY_BASE) in reverse order based
 * on total car count (0x0607EA98). CAR_STRUCT_SIZE=0x268 per slot. */
void FUN_0600d280(void)
{
  int car_count = *(int *)0x0607EA98;
  int *rank_a = (int *)0x0607E94C;         /* ranking table A */
  int *rank_b = (int *)0x0607E9EC;         /* ranking table B */
  unsigned int i;

  /* Clear both 40-entry tables */
  for (i = 0; i < 0x28; i += 2) {
    rank_a[i] = 0;  rank_a[i + 1] = 0;
  }
  for (i = 0; i < 0x28; i += 2) {
    rank_b[i] = 0;  rank_b[i + 1] = 0;
  }
  *(int *)0x0607EA8C = 0;
  *(int *)0x0607EA90 = 0;
  *(int *)0x0607EA94 = 0;

  /* Fill with car pointers in reverse order */
  for (i = 1; i <= (unsigned int)car_count; i++) {
    rank_a[i - 1] = CAR_ARRAY_BASE + (car_count - i) * CAR_STRUCT_SIZE;
  }
  for (i = 1; i <= (unsigned int)car_count; i++) {
    rank_b[i - 1] = CAR_ARRAY_BASE + (car_count - i) * CAR_STRUCT_SIZE;
  }
}

/* ranking_update -- Update car ranking/positioning system.
 * Skips ranking sort (FUN_0600d37c) in VS mode (bit 21 = 2-player).
 * Always runs ranking display (FUN_0600d3c4) and position update (FUN_0600d50c). */
void FUN_0600d31c(void)
{
    if ((GAME_STATE_BIT & 0x00200000) == 0) {
        FUN_0600d37c();   /* ranking sort (single-player only) */
    }
    FUN_0600d3c4();       /* ranking display */
    FUN_0600d50c();       /* position update */
}

/* ranking_compare_two -- Compare velocity projection of car 0 vs car 1.
 * Only runs when GAME_STATE_BIT bit 21 is clear (not VS mode).
 * Compares CAR_VEL_PROJ (+0x1F4): the faster car gets CAR_LAP_DELTA=1,
 * the slower gets 0. Used for 2-player position tracking. */
void FUN_0600d336(void)
{
    int car0 = CAR_ARRAY_BASE;
    int car1 = car0 + CAR_STRUCT_SIZE;

    if ((GAME_STATE_BIT & 0x00200000) == 0) {
        if (*(int *)(car0 + CAR_VEL_PROJ) < *(int *)(car1 + CAR_VEL_PROJ)) {
            *(int *)(car0 + CAR_LAP_DELTA) = 1;
            *(int *)(car1 + CAR_LAP_DELTA) = 0;
        } else {
            *(int *)(car0 + CAR_LAP_DELTA) = 0;
            *(int *)(car1 + CAR_LAP_DELTA) = 1;
        }
    }
}

/* ranking_sort_bubble -- Single-pass bubble sort of car pointers by velocity.
 * Car pointer array at 0x0607E94C, count from CAR_ITERATION_BASE.
 * Compares field at DAT_0600d404 offset (velocity projection).
 * Writes final rank to DAT_0600d406 offset in each car struct. */
void FUN_0600d37c(void)
{
    register int *car_ptrs asm("r4") = (int *)0x0607E94C;
    register unsigned int count asm("r5") = *(unsigned int *)0x0607EA98;
    register int rank asm("r12") = 0;
    int cur_val, next_val;

    cur_val = *(int *)(*car_ptrs + (int)DAT_0600d404);

    while (count > 1) {
        next_val = *(int *)(car_ptrs[1] + (int)DAT_0600d404);
        if (cur_val < next_val) {
            int tmp = *car_ptrs;
            *car_ptrs = car_ptrs[1];
            car_ptrs[1] = tmp;
        } else {
            next_val = cur_val;
        }
        cur_val = *car_ptrs++;
        *(int *)(cur_val + DAT_0600d406) = rank++;
        cur_val = next_val;
        count--;
    }

    *(int *)(*car_ptrs + (int)DAT_0600d406) = rank;
}

/* race_ranking_sort -- Sort car ranking array by checkpoint progress, update position links.
 * If lead car fell behind threshold: rotates fallen cars to end of array.
 * Otherwise: bubble-sorts by progress. Then rebuilds prev/next linked list at +0x238/+0x23C. */
void FUN_0600d3c4()
{
  int *temp_buf;
  char *ranking_base;
  char *car_count_ptr;
  int temp;
  unsigned int progress;
  int entry;
  unsigned int behind_count;
  int *first_next;
  int *iter;
  unsigned int count;
  int *src;
  int *dst;
  dst = (int *)0x0607E9EC;
  if (*(unsigned int *)(*(int *)0x0607E9EC + (int)PTR_DAT_0600d408) < *(unsigned int *)0x060786B4)
  {
    /* Count how many leading cars fell behind threshold */
    for (behind_count = 1;
        (count = behind_count, temp_buf = (int *)0x0607EA8C,
        src = (int *)0x0607E9EC,
        *(unsigned int *)(*(int *)(0x0607E9EC + (behind_count << 2)) + (int)DAT_0600d4a6) <
        *(unsigned int *)0x060786B4 && (behind_count < 3)); behind_count = behind_count + 1) {
    }
    /* Copy fallen cars to temp buffer */
    for (; count != 0; count = count - 1) {
      *temp_buf = *src;
      temp_buf = temp_buf + 1;
      src = src + 1;
    }
    /* Shift remaining cars to front */
    for (count = *(int *)0x0607EA98 - behind_count; temp_buf = (int *)0x0607EA8C,
        1 < count; count = count - 1) {
      entry = *src;
      src = src + 1;
      *dst = entry;
      dst = dst + 1;
    }
    /* Append fallen cars at end */
    for (; behind_count != 0; behind_count = behind_count - 1) {
      *dst = *temp_buf;
      dst = dst + 1;
      temp_buf = temp_buf + 1;
    }
  }
  else {
    /* Bubble sort by checkpoint progress (ascending) */
    behind_count = *(unsigned int *)(*(int *)0x0607E9EC + (int)PTR_DAT_0600d408);
    iter = (int *)0x0607E9EC;
    for (count = *(unsigned int *)0x0607EA98; 1 < count; count = count - 1) {
      progress = *(unsigned int *)(iter[1] + (int)PTR_DAT_0600d408);
      if (behind_count < progress) {
        temp = *iter;
        *iter = iter[1];
        iter[1] = temp;
        progress = behind_count;
      }
      iter = iter + 1;
      behind_count = progress;
    }
  }
  /* Rebuild prev/next position links at car+0x238/+0x23C */
  car_count_ptr = (char *)0x0607EA98;
  ranking_base = (char *)0x0607E9EC;
  first_next = (int *)(0x0607E9EC + 4);
  iter = first_next;
  for (behind_count = 1; behind_count < *(int *)car_count_ptr - 1U; behind_count = behind_count + 1) {
    temp = 0x238;
    *(int *)(*iter + temp) = iter[-1];       /* prev car */
    *(int *)(*iter + temp + 4) = iter[1];    /* next car */
    iter = iter + 1;
  }
  /* Link first and last cars */
  *(int *)(*(int *)ranking_base + 0x238) = *iter;
  temp = (int)DAT_0600d536;
  *(int *)(*(int *)ranking_base + temp) = *first_next;
  *(int *)(*iter + temp + -4) = iter[-1];
  *(int *)(*iter + temp) = *(int *)ranking_base;
  *(int *)0x060786B4 = *(int *)(*iter + temp + -0x50);
  return;
}

/* car_lod_proximity_update -- Assign detail levels to cars based on distance.
 * Computes Manhattan distance from reference point (camera or player car),
 * assigns LOD tiers: close (<0xC0000, max 3), medium (<0x230000, max 7),
 * far (<0x780000). Also adjusts LOD based on checkpoint gap from player. */
void FUN_0600d50c()
{
  char *car_count_ptr;
  int dx;
  int car_ptr;
  char *player_car_ptr;
  unsigned int i;
  int *car_slot_array;
  int dz;
  int lod_medium_count;
  int car_ptr_rev;
  int ref_x;
  int ref_z;
  int lod_close_count;
  int car_z;
  car_count_ptr = (int *)0x0607EA98;        /* active car count */
  player_car_ptr = (char *)0x0607E944;      /* player car pointer */
  *(int *)0x0607EBDC = 0;
  lod_close_count = 0;
  lod_medium_count = 0;
  car_slot_array = (int *)0x0607E94C;       /* car pointer array */
  /* Pass 1: Clear detail flags for all cars */
  for (i = 0; i < *(unsigned int *)car_count_ptr; i = i + 1) {
    car_ptr = *car_slot_array;
    car_slot_array = car_slot_array + 1;
    *(int *)(car_ptr + DAT_0600d5d6) = 0;
    (*(int(*)())0x06034F78)();
    (*(int(*)())0x06034F78)();
    (*(int(*)())0x06034F78)();
    (*(int(*)())0x06034F78)();
    (*(int(*)())0x06034F78)();
  }
  /* Compute reference position for distance calculation */
  car_ptr = *(int *)player_car_ptr;
  if ((GAME_STATE_BIT & 0x10060000) == 0) {
    /* Normal mode: use camera angle + offset from camera position */
    (*(int(*)())0x06027358)(*(int *)0x06063EF0,&ref_x,&ref_z);
    ref_x = (*(int(*)())0x06027552)(-ref_x,0x00070000);
    ref_z = (*(int(*)())0x06027552)(ref_z,0x00070000);
    ref_x = ref_x + *(int *)0x06063DF8;        /* camera X */
    ref_z = ref_z + *(int *)(0x06063DF8 + 8);  /* camera Z */
  }
  else {
    /* Replay/VS mode: use player car angle + offset from car position */
    (*(int(*)())0x06027358)(*(int *)(*(int *)player_car_ptr + 0x20),&ref_x,&ref_z);
    ref_x = (*(int(*)())0x06027552)(-ref_x,0x00050000);
    ref_z = (*(int(*)())0x06027552)(ref_z,0x00050000);
    ref_x = ref_x + *(int *)(*(int *)player_car_ptr + 0x10);  /* car X */
    ref_z = ref_z + *(int *)(*(int *)player_car_ptr + 0x18);  /* car Z */
  }
  /* Pass 2: Walk ranked car list, assign LOD by Manhattan distance */
  car_ptr_rev = car_ptr;
  for (i = *(unsigned int *)car_count_ptr; 1 < i; i = i - 1) {
    dx = 0x238;
    car_ptr = *(int *)(car_ptr + dx);          /* next car via +0x238 link */
    car_ptr_rev = *(int *)(car_ptr_rev + dx + 4);  /* prev car via +0x23C link */
    *(unsigned int *)(car_ptr + dx + -0x20) = i;     /* ranking at +0x218 */
    *(unsigned int *)(car_ptr_rev + dx + -0x20) = i;
    /* Manhattan distance from reference point */
    dx = ref_x - *(int *)(car_ptr + 0x10);     /* car X at +0x10 */
    if (dx < 0) {
      dx = *(int *)(car_ptr + 0x10) - ref_x;
    }
    car_z = *(int *)(car_ptr + 0x18);          /* car Z at +0x18 */
    dz = ref_z - car_z;
    if (dz < 0) {
      dz = car_z - ref_z;
    }
    dx = dx + dz;
    /* Assign LOD tier based on distance thresholds */
    if ((dx < (int)0x000C0000) && (lod_close_count < 3)) {
      (*(int(*)())0x06034F78)();               /* LOD close (high detail) */
      lod_close_count = lod_close_count + 1;
    }
    else if ((dx < (int)0x00230000) && (lod_medium_count < 7)) {
      (*(int(*)())0x06034F78)();               /* LOD medium */
      lod_medium_count = lod_medium_count + 1;
    }
    else if (dx < (int)0x00780000) {
      (*(int(*)())0x06034F78)();               /* LOD far (low detail) */
    }
  }
  (*(int(*)())0x06034F78)();
  /* Pass 3: Adjust LOD based on checkpoint gap from player */
  lod_medium_count = *(int *)(*(int *)player_car_ptr + (int)DAT_0600d76a);
  player_car_ptr = (char *)0x06078B68;        /* car slot 1 base */
  for (i = 1; i < *(unsigned int *)car_count_ptr; i = i + 1) {
    car_ptr = *(int *)(player_car_ptr + DAT_0600d76a) - lod_medium_count;
    (*(int(*)())0x06034F78)();
    (*(int(*)())0x06034F78)();
    /* Slightly ahead (1-2 checkpoints) — boost detail */
    if ((car_ptr < 3) && (0 < car_ptr)) {
      (*(int(*)())0x06034F78)();
    }
    /* Slightly behind or same checkpoint — boost detail */
    if ((car_ptr < 1) && (-2 < car_ptr)) {
      (*(int(*)())0x06034F78)();
    }
    player_car_ptr = player_car_ptr + PTR_DAT_0600d770;  /* next car slot (stride 0x268) */
  }
  return;
}

/* FUN_0600d780: L2 version in lap_counting.c */
extern void FUN_0600D780(int player_flag);
void FUN_0600d780(int player_flag) { FUN_0600D780(player_flag); }

/* checkpoint_position_validate -- Validate checkpoint crossing position.
 * Computes delta between current and previous checkpoint index. If delta
 * is 1..15 (normal forward progress), stores checkpoint. Otherwise checks
 * if position matches halfway or halfway+2 (for lap counter logic).
 * On match, stores position and updates render offset (0x06063F20). */
int FUN_0600d84c()
{
    int car = CAR_PTR_CURRENT;
    int cur_cp = *(int *)(car + DAT_0600d894);
    int prev_off = DAT_0600d894 + -4;
    int delta = cur_cp - *(int *)(car + prev_off);
    int result;

    if ((delta < 1) || (0xf < delta)) {
        /* Not normal forward: check halfway point */
        int halfway = (int)(*(int *)0x0607EA9C + (unsigned int)(*(int *)0x0607EA9C < 0)) >> 1;
        if ((cur_cp == halfway) || (cur_cp == halfway + 2)) {
            result = 0x1e8;
            *(int *)(car + result) = cur_cp;
            result = result + 0x40;
            *(int *)0x06063F20 = *(int *)(car + result);
        }
    } else {
        /* Normal forward progress */
        result = 0x1e8;
        *(int *)(car + result) = cur_cp;
    }
    return result;
}

/* checkpoint_collision_scan -- Scan checkpoint objects for player collision.
 * Iterates through checkpoint object array at 0x06063F3C. For each entry,
 * compares object ID against car's checkpoint field (+0x1EC). If match
 * and param_1==0, calls FUN_0600d9bc to process crossing. If car flag
 * byte+3 bit 3 is set, marks collision flag at 0x060786AC. */
int FUN_0600d8a4(param_1)
    int param_1;
{
    char *cp_list_ptr = (char *)0x06063F3C;     /* checkpoint object list */
    char *coll_flag   = (char *)0x060786AC;     /* collision detected flag */
    char *car_ptr     = (char *)0x0607E940;     /* current car pointer */
    char *car_ptr2    = (int *)0x0607E944;      /* secondary car pointer */
    unsigned int idx = 0;
    unsigned int count = **(unsigned int **)0x06063F3C;

    if (count != 0) {
        do {
            if (((*(int *)((idx << 2) + *(int *)(*(int *)cp_list_ptr + 4)) ==
                  *(int *)(*(int *)car_ptr + 0x01EC)) && (param_1 == 0)) &&
                (FUN_0600d9bc(idx + 1), (*(unsigned char *)(*(int *)car_ptr2 + 3) & 8) != 0)) {
                *(int *)coll_flag = 1;
            }
            idx = idx + 1;
        } while (idx < count);
    }
}

/* FUN_0600d92c: L2 version in lap_counting.c */
extern void FUN_0600D92C(void);
void FUN_0600d92c(void) { FUN_0600D92C(); }

/* FUN_0600d9bc: L2 version in lap_counting.c */
extern void FUN_0600D9BC(int car_index);
void FUN_0600d9bc(int car_index) { FUN_0600D9BC(car_index); }

/* FUN_0600da7c: L2 version in checkpoint_detect.c */
extern void FUN_0600DA7C(void);
void FUN_0600da7c(void) { FUN_0600DA7C(); }

/* FUN_0600db64: L2 version in lap_counting.c */
extern void FUN_0600DB64(void);
void FUN_0600db64(void) { FUN_0600DB64(); }

/* checkpoint_vdp_render -- Render checkpoint crossing VDP sprites.
 * On first 4 frames of 8-frame cycle, draws sprites via FUN_06028400
 * using course-specific tile data (0x060637F8 or 0x06063808).
 * On frames 4-7, clears sprites (FUN_0600dc74). Every 64 frames,
 * plays checkpoint sound (0xAE1138FF/0xAE1139FF) and cycles animation
 * counter at 0x060786A8 (resets after 7 cycles). */
unsigned int FUN_0600db9e()
{
    int *anim_counter = (int *)0x060786A8;
    unsigned int result;

    if ((*(unsigned short *)0x06078698 & 7) < 4) {
        /* First 4 frames: draw checkpoint sprites */
        if (*(int *)0x06078644 == 1) {
            (*(int(*)())0x06028400)(8, *(int *)0x060637F8, 0xac0,
                       *(int *)(0x060637F8 + 4) + (int)DAT_0600dbdc, 0x060637F8);
        } else {
            (*(int(*)())0x06028400)(8, *(int *)0x06063808, (int)DAT_0600dc9a,
                       *(int *)(0x06063808 + 4) + (int)DAT_0600dc98, 0x06063808);
        }
    } else {
        FUN_0600dc74();                            /* clear checkpoint sprites */
    }

    result = (unsigned int)*(unsigned short *)0x06078698;

    /* Every 64 frames: play sound and cycle animation */
    if ((*(unsigned short *)0x06078698 & 0x3f) == 0) {
        int count = *anim_counter;
        *(unsigned int *)anim_counter = count + 1U;
        if (count + 1U < 7) {
            result = (*(int(*)())0x0601D5F4)(0, 0xAE1138FF);
        } else {
            int sound_id = 0xAE1138FF;
            if (*(int *)0x06078644 == 1) {
                sound_id = 0xAE1139FF;             /* alternate course sound */
            }
            result = (*(int(*)())0x0601D5F4)(0, sound_id);
            *(short *)0x06086054 = 0x28;           /* animation timer reset */
            *anim_counter = 0;
        }
    }

    return result;
}

/* FUN_0600dc74: L2 version in checkpoint_clear.c */
extern void FUN_0600DC74(void);
void FUN_0600dc74(void) { FUN_0600DC74(); }

/* FUN_0600dcc8: L2 version in lap_counting.c */
extern void FUN_0600DCC8(void);
void FUN_0600dcc8(void) { FUN_0600DCC8(); }

/* FUN_0600dd88: L2 version in lap_counting.c */
extern void FUN_0600DD88(int car_index);
void FUN_0600dd88(int car_index) { FUN_0600DD88(car_index); }

/* FUN_0600de40: L2 version in car_iteration.c */
extern void FUN_0600DE40(void);
#if 0 /* FUN_0600DE40 -- replaced by ASM import of original bytes */
void FUN_0600de40(void) { FUN_0600DE40(); }
#endif

/* FUN_0600de54: L2 version in car_iteration.c */
extern void FUN_0600DE54(void);
#if 0 /* FUN_0600DE54 -- replaced by ASM import of original bytes */
void FUN_0600de54(void) { FUN_0600DE54(); }
#endif

/* FUN_0600de70: L2 version in car_iteration.c */
extern void FUN_0600DE70(void);
void FUN_0600de70(void) { FUN_0600DE70(); }

/* FUN_0600df66: L2 version in car_iteration.c */
extern void FUN_0600DF66(void);
void FUN_0600df66(void) { FUN_0600DF66(); }

/* FUN_0600dfd0: L2 version in visual_physics_update.c */
extern void FUN_0600DFD0(void);
#if 0 /* FUN_0600DFD0 -- replaced by ASM import of original bytes */
void FUN_0600dfd0(void) { FUN_0600DFD0(); }
#endif

/* FUN_0600D12C -- original binary (496 bytes) */
__asm__(
    ".section .text.FUN_0600D12C, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0600D12C\n"
    ".type _FUN_0600D12C, @function\n"
    "_FUN_0600D12C:\n"
    ".byte 0x2F, 0xE6, 0xD5, 0x1A, 0x90, 0x2F, 0xD6, 0x1A, 0x65, 0x52, 0x04, 0x5E, 0x90, 0x2C, 0x0E, 0x5E\n"  /* 0x0600D12C */
    ".byte 0x2E, 0xE8, 0x89, 0x1A, 0x57, 0xE4, 0x53, 0x54, 0x52, 0xE6, 0x37, 0x38, 0x37, 0x2C, 0x53, 0x56\n"  /* 0x0600D13C */
    ".byte 0xD2, 0x14, 0x37, 0x38, 0x37, 0x23, 0x89, 0x02, 0x64, 0xE3, 0xA0, 0x25, 0x6E, 0xF6, 0x52, 0x44\n"  /* 0x0600D14C */
    ".byte 0x53, 0x54, 0x51, 0x46, 0x32, 0x38, 0x32, 0x1C, 0x53, 0x56, 0x65, 0x23, 0x35, 0x38, 0x35, 0x63\n"  /* 0x0600D15C */
    ".byte 0x89, 0x01, 0xA0, 0x19, 0x6E, 0xF6, 0xA0, 0x0C, 0x00, 0x09, 0x52, 0x44, 0x53, 0x54, 0x51, 0x46\n"  /* 0x0600D16C */
    ".byte 0x32, 0x38, 0x32, 0x1C, 0x53, 0x56, 0x65, 0x23, 0x35, 0x38, 0x35, 0x63, 0x89, 0x01, 0xA0, 0x0B\n"  /* 0x0600D17C */
    ".byte 0x6E, 0xF6, 0x00, 0x0B, 0x6E, 0xF6, 0x01, 0x18, 0x02, 0x34, 0xFF, 0xFF, 0x06, 0x07, 0xE9, 0x40\n"  /* 0x0600D18C */
    ".byte 0x00, 0x0F, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0xD6, 0x19, 0x90, 0x28, 0x66, 0x62, 0x05, 0x4E\n"  /* 0x0600D19C */
    ".byte 0x03, 0x6E, 0x67, 0x53, 0x37, 0x38, 0x93, 0x23, 0x37, 0x33, 0x8B, 0x1E, 0x93, 0x21, 0x37, 0x37\n"  /* 0x0600D1AC */
    ".byte 0x89, 0x1B, 0x97, 0x1E, 0x93, 0x1E, 0x35, 0x37, 0x89, 0x01, 0xA0, 0x01, 0x35, 0x7C, 0x35, 0x78\n"  /* 0x0600D1BC */
    ".byte 0x45, 0x11, 0x89, 0x03, 0xE3, 0x00, 0x90, 0x16, 0xA0, 0x0A, 0x06, 0x36, 0x93, 0x14, 0x35, 0x37\n"  /* 0x0600D1CC */
    ".byte 0x8B, 0x04, 0x93, 0x11, 0x90, 0x0F, 0x06, 0x36, 0xA0, 0x02, 0x00, 0x09, 0x90, 0x0B, 0x06, 0x56\n"  /* 0x0600D1DC */
    ".byte 0x93, 0x0B, 0x90, 0x0B, 0x06, 0x36, 0x70, 0x30, 0x06, 0x46, 0x00, 0x0B, 0x00, 0x09, 0x01, 0xFC\n"  /* 0x0600D1EC */
    ".byte 0xFD, 0x00, 0x03, 0x00, 0x04, 0x00, 0x01, 0xF8, 0x08, 0x00, 0x01, 0x00, 0x02, 0x04, 0xFF, 0xFF\n"  /* 0x0600D1FC */
    ".byte 0x06, 0x07, 0xE9, 0x40, 0xD5, 0x19, 0xD4, 0x1A, 0x90, 0x29, 0x65, 0x52, 0x64, 0x42, 0x03, 0x5E\n"  /* 0x0600D20C */
    ".byte 0x04, 0x4E, 0x66, 0x43, 0x36, 0x38, 0x93, 0x23, 0x36, 0x33, 0x8B, 0x1C, 0x93, 0x21, 0x36, 0x37\n"  /* 0x0600D21C */
    ".byte 0x89, 0x19, 0x90, 0x1C, 0x03, 0x5E, 0x33, 0x47, 0x8B, 0x01, 0xA0, 0x01, 0x74, 0xF0, 0x74, 0x10\n"  /* 0x0600D22C */
    ".byte 0x44, 0x11, 0x89, 0x03, 0xE3, 0x00, 0x90, 0x15, 0xA0, 0x0A, 0x05, 0x36, 0x93, 0x13, 0x34, 0x37\n"  /* 0x0600D23C */
    ".byte 0x8B, 0x04, 0x93, 0x10, 0x90, 0x0E, 0x05, 0x36, 0xA0, 0x02, 0x00, 0x09, 0x90, 0x0A, 0x05, 0x46\n"  /* 0x0600D24C */
    ".byte 0xE3, 0x40, 0x90, 0x09, 0x05, 0x36, 0x00, 0x0B, 0x00, 0x09, 0x00, 0x0B, 0x00, 0x09, 0x01, 0xFC\n"  /* 0x0600D25C */
    ".byte 0xFD, 0x00, 0x03, 0x00, 0x01, 0xF8, 0x08, 0x00, 0x02, 0x04, 0xFF, 0xFF, 0x06, 0x07, 0xE9, 0x40\n"  /* 0x0600D26C */
    ".byte 0x06, 0x07, 0xE9, 0x44, 0x2F, 0xC6, 0x4F, 0x12, 0xDC, 0x20, 0x91, 0x3D, 0xE7, 0x28, 0xD5, 0x20\n"  /* 0x0600D27C */
    ".byte 0xE4, 0x00, 0xD6, 0x20, 0xA0, 0x05, 0x60, 0x43, 0x26, 0x42, 0x76, 0x04, 0x26, 0x42, 0x70, 0x02\n"  /* 0x0600D28C */
    ".byte 0x76, 0x04, 0x30, 0x72, 0x8B, 0xF8, 0xD6, 0x1C, 0xA0, 0x05, 0x60, 0x43, 0x26, 0x42, 0x76, 0x04\n"  /* 0x0600D29C */
    ".byte 0x26, 0x42, 0x70, 0x02, 0x76, 0x04, 0x30, 0x72, 0x8B, 0xF8, 0xD6, 0x18, 0x26, 0x42, 0x76, 0x04\n"  /* 0x0600D2AC */
    ".byte 0x26, 0x42, 0x76, 0x04, 0x26, 0x42, 0xD0, 0x13, 0xA0, 0x09, 0xE6, 0x01, 0x62, 0x03, 0x70, 0x04\n"  /* 0x0600D2BC */
    ".byte 0x63, 0x52, 0x33, 0x68, 0x03, 0x17, 0x03, 0x1A, 0x33, 0xCC, 0x22, 0x32, 0x76, 0x01, 0x62, 0x52\n"  /* 0x0600D2CC */
    ".byte 0x36, 0x26, 0x8B, 0xF3, 0xD0, 0x0C, 0xA0, 0x09, 0xE6, 0x01, 0x62, 0x03, 0x70, 0x04, 0x63, 0x52\n"  /* 0x0600D2DC */
    ".byte 0x33, 0x68, 0x03, 0x17, 0x03, 0x1A, 0x33, 0xCC, 0x22, 0x32, 0x76, 0x01, 0x62, 0x52, 0x36, 0x26\n"  /* 0x0600D2EC */
    ".byte 0x8B, 0xF3, 0x4F, 0x16, 0x00, 0x0B, 0x6C, 0xF6, 0x02, 0x68, 0xFF, 0xFF, 0x06, 0x07, 0x89, 0x00\n"  /* 0x0600D2FC */
    ".byte 0x06, 0x07, 0xEA, 0x98, 0x06, 0x07, 0xE9, 0x4C, 0x06, 0x07, 0xE9, 0xEC, 0x06, 0x07, 0xEA, 0x8C\n"  /* 0x0600D30C */
);

/* FUN_0600C8CC -- original binary (4 bytes) */
__asm__(
    ".section .text.FUN_0600C8CC, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0600C8CC\n"
    ".type _FUN_0600C8CC, @function\n"
    "_FUN_0600C8CC:\n"
    ".byte 0x2F, 0xE6, 0x6E, 0x43\n"  /* 0x0600C8CC */
);

/* FUN_0600C4F8 -- original binary (222 bytes) */
__asm__(
    ".section .text.FUN_0600C4F8, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0600C4F8\n"
    ".type _FUN_0600C4F8, @function\n"
    "_FUN_0600C4F8:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x4F, 0x22, 0xDD, 0x27, 0xDE, 0x28, 0x90, 0x44, 0x6E, 0xE2\n"  /* 0x0600C4F8 */
    ".byte 0x03, 0xED, 0x43, 0x15, 0x8B, 0x03, 0x90, 0x3F, 0x02, 0xED, 0x72, 0xFF, 0x0E, 0x25, 0xD3, 0x24\n"  /* 0x0600C508 */
    ".byte 0xD2, 0x24, 0x63, 0x32, 0x23, 0x29, 0x23, 0x38, 0x8B, 0x54, 0x9C, 0x36, 0x90, 0x36, 0x03, 0xEE\n"  /* 0x0600C518 */
    ".byte 0x43, 0x15, 0x89, 0x03, 0x90, 0x33, 0x00, 0xEE, 0x20, 0x08, 0x89, 0x02, 0x90, 0x30, 0xA0, 0x23\n"  /* 0x0600C528 */
    ".byte 0x0E, 0xC6, 0x54, 0xE2, 0xD2, 0x1C, 0xD3, 0x1D, 0x44, 0x08, 0x32, 0x4C, 0x33, 0x4C, 0x62, 0x22\n"  /* 0x0600C538 */
    ".byte 0x63, 0x32, 0xD4, 0x1B, 0x32, 0x38, 0x34, 0x2C, 0x4D, 0x0B, 0xE5, 0x01, 0x64, 0x03, 0x90, 0x20\n"  /* 0x0600C548 */
    ".byte 0x4D, 0x0B, 0x05, 0xEE, 0x65, 0x03, 0x53, 0xE3, 0x45, 0x21, 0x90, 0x1B, 0x04, 0xEE, 0x34, 0x38\n"  /* 0x0600C558 */
    ".byte 0x34, 0xC3, 0x89, 0x02, 0x90, 0x14, 0xA0, 0x07, 0x0E, 0xC6, 0x35, 0x43, 0x89, 0x02, 0x90, 0x0F\n"  /* 0x0600C568 */
    ".byte 0xA0, 0x02, 0x0E, 0x56, 0x90, 0x0C, 0x0E, 0x46, 0x54, 0xE3, 0x90, 0x09, 0x03, 0xEE, 0x34, 0x3C\n"  /* 0x0600C578 */
    ".byte 0x44, 0x15, 0x8B, 0x17, 0xA0, 0x18, 0x1E, 0x43, 0x00, 0xD4, 0xF0, 0x52, 0x00, 0xBC, 0x00, 0xB8\n"  /* 0x0600C588 */
    ".byte 0x00, 0xFC, 0x01, 0x98, 0x01, 0x94, 0xFF, 0xFF, 0x06, 0x02, 0x75, 0x52, 0x06, 0x07, 0xE9, 0x40\n"  /* 0x0600C598 */
    ".byte 0x06, 0x07, 0xEB, 0xC4, 0x00, 0x00, 0x80, 0x00, 0x06, 0x04, 0x77, 0xEC, 0x06, 0x04, 0x54, 0xCC\n"  /* 0x0600C5A8 */
    ".byte 0xFE, 0xC0, 0x00, 0x00, 0xE2, 0x00, 0x1E, 0x23, 0xD5, 0x16, 0x4D, 0x0B, 0x54, 0xE3, 0x40, 0x29\n"  /* 0x0600C5B8 */
    ".byte 0x60, 0x0F, 0x1E, 0x02, 0x4F, 0x26, 0x6C, 0xF6, 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x0600C5C8 */
);

/* FUN_0600CEBA -- original binary (158 bytes) */
__asm__(
    ".section .text.FUN_0600CEBA, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0600CEBA\n"
    ".type _FUN_0600CEBA, @function\n"
    "_FUN_0600CEBA:\n"
    ".byte 0x4F, 0x22, 0xD4, 0x22, 0x90, 0x3C, 0xD3, 0x20, 0x64, 0x42, 0x63, 0x32, 0x05, 0x4E, 0x70, 0x68\n"  /* 0x0600CEBA */
    ".byte 0x45, 0x08, 0x02, 0x4E, 0x35, 0x3C, 0x70, 0x04, 0x04, 0x26, 0x63, 0x51, 0x70, 0xFC, 0x63, 0x3D\n"  /* 0x0600CECA */
    ".byte 0x04, 0x36, 0x91, 0x2E, 0x92, 0x2E, 0xD3, 0x1A, 0x31, 0x4C, 0x32, 0x4C, 0x43, 0x0B, 0xE0, 0x02\n"  /* 0x0600CEDA */
    ".byte 0x62, 0x53, 0xD3, 0x17, 0x91, 0x26, 0x72, 0x02, 0x31, 0x4C, 0x43, 0x0B, 0xE0, 0x02, 0x90, 0x22\n"  /* 0x0600CEEA */
    ".byte 0x06, 0x4E, 0x70, 0xFC, 0x03, 0x4E, 0x36, 0x38, 0x66, 0x6F, 0x65, 0x6F, 0x45, 0x15, 0x8B, 0x14\n"  /* 0x0600CEFA */
    ".byte 0xD2, 0x11, 0x62, 0x22, 0x72, 0xF0, 0x35, 0x27, 0x8B, 0x0F, 0x90, 0x15, 0x02, 0x4E, 0x72, 0x01\n"  /* 0x0600CF0A */
    ".byte 0x04, 0x26, 0x70, 0xF4, 0x04, 0x26, 0xD5, 0x0C, 0x63, 0x52, 0x70, 0x10, 0x02, 0x4E, 0x33, 0x28\n"  /* 0x0600CF1A */
    ".byte 0x70, 0xF4, 0x04, 0x36, 0x63, 0x52, 0x70, 0x0C, 0x04, 0x36, 0x4F, 0x26, 0x00, 0x0B, 0x00, 0x09\n"  /* 0x0600CF2A */
    ".byte 0x01, 0x84, 0x01, 0x62, 0x01, 0x60, 0x01, 0xF0, 0x02, 0x28, 0x06, 0x07, 0xEB, 0x84, 0x06, 0x07\n"  /* 0x0600CF3A */
    ".byte 0xE9, 0x40, 0x06, 0x03, 0x52, 0x28, 0x06, 0x07, 0xEA, 0x9C, 0x06, 0x07, 0xEB, 0xD0\n"  /* 0x0600CF4A */
);

/* FUN_0600CDD0 -- original binary (150 bytes) */
__asm__(
    ".section .text.FUN_0600CDD0, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0600CDD0\n"
    ".type _FUN_0600CDD0, @function\n"
    "_FUN_0600CDD0:\n"
    ".byte 0x2F, 0xE6, 0x2F, 0xD6, 0x2F, 0xC6, 0x2F, 0xB6, 0x4F, 0x22, 0xDE, 0x2D, 0x90, 0x53, 0x6E, 0xE2\n"  /* 0x0600CDD0 */
    ".byte 0x0D, 0xEE, 0x70, 0xFC, 0x63, 0xD3, 0x4D, 0x08, 0x43, 0x08, 0x4D, 0x00, 0x43, 0x08, 0x3D, 0x3C\n"  /* 0x0600CDE0 */
    ".byte 0x03, 0xEE, 0x3D, 0x3C, 0x85, 0xDB, 0x63, 0x03, 0x63, 0x3D, 0x90, 0x45, 0x0E, 0x36, 0x70, 0x60\n"  /* 0x0600CDF0 */
    ".byte 0x04, 0xEE, 0x24, 0x48, 0x89, 0x02, 0x6C, 0x43, 0xA0, 0x02, 0x7C, 0xFF, 0xDC, 0x21, 0x6C, 0xC2\n"  /* 0x0600CE00 */
    ".byte 0x6B, 0xC3, 0x63, 0xC3, 0x90, 0x39, 0x55, 0xE6, 0x4B, 0x08, 0x43, 0x08, 0x02, 0xEE, 0x4B, 0x00\n"  /* 0x0600CE10 */
    ".byte 0x43, 0x08, 0x3B, 0x3C, 0x3B, 0x2C, 0x53, 0xB1, 0x64, 0xB2, 0x52, 0xE4, 0x35, 0x38, 0xD3, 0x1A\n"  /* 0x0600CE20 */
    ".byte 0x43, 0x0B, 0x34, 0x28, 0x66, 0x0F, 0x65, 0x6F, 0x85, 0xD7, 0x64, 0x53, 0x67, 0x03, 0x47, 0x08\n"  /* 0x0600CE30 */
    ".byte 0x34, 0x78, 0x44, 0x11, 0x89, 0x02, 0x62, 0x73, 0xA0, 0x01, 0x32, 0x58, 0x62, 0x43, 0x93, 0x1D\n"  /* 0x0600CE40 */
    ".byte 0x32, 0x37, 0x8B, 0x01, 0x90, 0x17, 0x0E, 0xC6, 0x60, 0xD3, 0x4F, 0x26, 0x6B, 0xF6, 0x6C, 0xF6\n"  /* 0x0600CE50 */
    ".byte 0x6D, 0xF6, 0x00, 0x0B, 0x6E, 0xF6\n"  /* 0x0600CE60 */
);

/* FUN_0600CB90 -- original binary (168 bytes) */
__asm__(
    ".section .text.FUN_0600CB90, \"ax\"\n"
    ".balign 2\n"
    ".global _FUN_0600CB90\n"
    ".type _FUN_0600CB90, @function\n"
    "_FUN_0600CB90:\n"
    ".byte 0x2F, 0xE6, 0x60, 0x5D, 0xDE, 0x25, 0xD7, 0x26, 0xC8, 0x01, 0x8D, 0x28, 0x67, 0x72, 0x66, 0x5D\n"  /* 0x0600CB90 */
    ".byte 0xD3, 0x24, 0x46, 0x01, 0x63, 0x32, 0x76, 0x01, 0x36, 0x36, 0x8B, 0x00, 0xE6, 0x00, 0x65, 0x5D\n"  /* 0x0600CBA0 */
    ".byte 0x46, 0x08, 0x90, 0x3A, 0x63, 0xE2, 0x45, 0x01, 0x46, 0x00, 0x01, 0x7E, 0x45, 0x08, 0x41, 0x19\n"  /* 0x0600CBB0 */
    ".byte 0x45, 0x00, 0x67, 0x13, 0x37, 0x5C, 0x31, 0x6C, 0x65, 0x73, 0x66, 0x13, 0x45, 0x08, 0x46, 0x08\n"  /* 0x0600CBC0 */
    ".byte 0x45, 0x08, 0x46, 0x08, 0x35, 0x3C, 0x36, 0x3C, 0x62, 0x52, 0x63, 0x62, 0x32, 0x3C, 0x42, 0x21\n"  /* 0x0600CBD0 */
    ".byte 0x24, 0x22, 0x52, 0x51, 0x53, 0x61, 0x32, 0x3C, 0x42, 0x21, 0xA0, 0x11, 0x14, 0x22, 0x65, 0x5D\n"  /* 0x0600CBE0 */
    ".byte 0x90, 0x1B, 0x45, 0x01, 0x06, 0x7E, 0x45, 0x08, 0x46, 0x19, 0x45, 0x00, 0x36, 0x5C, 0x65, 0x63\n"  /* 0x0600CBF0 */
    ".byte 0x45, 0x08, 0x45, 0x08, 0x63, 0xE2, 0x35, 0x3C, 0x62, 0x52, 0x24, 0x22, 0x53, 0x51, 0x14, 0x32\n"  /* 0x0600CC00 */
    ".byte 0x85, 0x54, 0x81, 0x46, 0x85, 0x55, 0x63, 0x03, 0x43, 0x08, 0x60, 0x3F, 0x81, 0x47, 0x85, 0x56\n"  /* 0x0600CC10 */
    ".byte 0x81, 0x48, 0xE0, 0x00, 0x81, 0x49, 0x00, 0x0B, 0x6E, 0xF6, 0x01, 0xF8, 0x06, 0x07, 0xEB, 0x88\n"  /* 0x0600CC20 */
    ".byte 0x06, 0x07, 0xE9, 0x40, 0x06, 0x07, 0xEA, 0x9C\n"  /* 0x0600CC30 */
);
