#include "game.h"

extern char flag_0607864B;
extern int DAT_060082aa;
extern int DAT_060082ac;
extern int DAT_060082ae;
extern int DAT_060082b0;
extern int DAT_060082b2;
extern int DAT_06008358;
extern int DAT_0600835a;
extern int DAT_060083fa;
extern int DAT_060083fc;
extern int DAT_060083fe;
extern int DAT_06008400;
extern int DAT_06008402;
extern int DAT_060084a2;
extern int DAT_060084a4;
extern int DAT_060084a6;
extern int DAT_0600855e;
extern int DAT_06008624;
extern int DAT_06008626;
extern int DAT_06008628;
extern int DAT_0600862a;
extern int DAT_06008718;
extern int DAT_0600871a;
extern int DAT_0600871c;
extern int DAT_0600871e;
extern int DAT_060087e8;
extern int DAT_060087ea;
extern int DAT_060087ec;
extern int DAT_060087ee;
extern int DAT_060087f0;
extern int DAT_060087f2;
extern int DAT_060087f4;
extern int DAT_060087f6;
extern int DAT_060088aa;
extern int DAT_060088ac;
extern int DAT_060088ae;
extern int DAT_060088b0;
extern int DAT_060088b2;
extern int DAT_060088b4;
extern int DAT_060088b6;
extern void FUN_060084ca();
extern void FUN_060086c0();
extern int speed_force_timer();
extern int PTR_DAT_06008360;
extern int PTR_DAT_06008560;
extern int counter_0607EBCC;
extern int func_0601389E();
extern int func_06018E70();
extern int state_0605AD10;

/* gear_shift_steering_deflect -- Handle steering deflection during gear shifts.
 * If steer timer (CAR_STEER_TIMER at +0xB8) is 0: detect new shift input.
 *   - Right shift (bit 0x10): set timer=0x30, direction=-1
 *   - Left shift (bit 0x20): set timer=0x30, direction=+1
 *   - Play shift sound (0xAE111BFF) if in race state
 * If timer active: decrement, look up deflection from sine table
 *   (0x0604546C normal / 0x0604540C if flag bit 0x40), apply to steering
 *   at car+0x1D8, decelerate by 0xE3. Calls CD sync twice. */
void FUN_060081f4(void)
{
    int *car_iter = (int *)0x0607E944;   /* car iteration pointer */
    int timer_val;

    if (*(int *)(CAR_PTR_TARGET + CAR_STEER_TIMER) == 0) {
        if ((0x13 < *(int *)(CAR_PTR_TARGET + CAR_SPEED)) &&
            (*(int *)(CAR_PTR_TARGET + (int)DAT_060082b2) == 0)) {
            if ((**(unsigned char **)car_iter & 0x10) == 0) {
                if ((**(unsigned char **)car_iter & 0x20) != 0) {
                    *(int *)(CAR_PTR_TARGET + CAR_STEER_TIMER) = 0x30;
                    *(int *)(*(int *)car_iter + (int)DAT_0600835a) = 1;
                    if (((unsigned int)0x00020000 & *(unsigned int *)0x0607EBC4) != 0) {
                        (*(int(*)())0x0601D5F4)(0, 0xAE111BFF); /* shift sound */
                    }
                }
            } else {
                *(int *)(CAR_PTR_TARGET + CAR_STEER_TIMER) = 0x30;
                *(int *)(*(int *)car_iter + (int)DAT_060082ac) = 0xffffffff;
                if (((unsigned int)0x00020000 & *(unsigned int *)0x0607EBC4) != 0) {
                    (*(int(*)())0x0601D5F4)(0, 0xAE111BFF); /* shift sound */
                }
            }
        }
    } else {
        *(int *)0x0607EBD4 = 0x46;  /* physics mode: steering override */
        timer_val = *(int *)(*(int *)car_iter + CAR_STEER_TIMER);
        *(int *)(*(int *)car_iter + CAR_STEER_TIMER) -= 1;

        char *sine_tbl = (char *)0x0604546C;  /* normal deflection table */
        if ((**(unsigned char **)car_iter & 0x40) != 0) {
            sine_tbl = (char *)0x0604540C;    /* alternate deflection table */
        }
        int deflect;
        if (*(int *)(*(int *)car_iter + (int)DAT_060082ac) < 0) {
            deflect = (int)*(short *)(sine_tbl + ((0x30 - timer_val) << 1));
        } else {
            deflect = -(int)*(short *)(sine_tbl + ((0x30 - timer_val) << 1));
        }
        *(int *)(*(int *)car_iter + 0x1d8) = deflect;
        *(int *)(*(int *)car_iter + CAR_ACCEL) -= 0xe3; /* deceleration penalty */
    }
    (*(int(*)())0x06034F78)(0);   /* CD sync */
    (*(int(*)())0x06034F78)();    /* CD sync */
}

int gear_shift_handler()
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  int uVar4;

  puVar2 = (char *)0x0607EBE0;

  puVar1 = (char *)0x0607E940;

  if (*(int *)(CAR_PTR_CURRENT + 0xb8) == 0) {

    if ((0x258 < GAME_STATE_VAR) &&

       (*(int *)(CAR_PTR_CURRENT + (int)DAT_060083fc) == 0)) {

      if ((**(unsigned char **)0x0607E940 & 0x10) == 0) {

        if ((**(unsigned char **)0x0607E940 & 0x20) != 0) {

          *(int *)(CAR_PTR_CURRENT + 0xb8) = 0x20;

          *(int *)(*(int *)puVar1 + (int)DAT_06008400) = 1;

          *(int *)puVar2 = *(int *)puVar1;

          *(short *)(*(int *)puVar1 + (int)DAT_06008402) = 0x28;

        }

      }

      else {

        *(int *)(CAR_PTR_CURRENT + 0xb8) = 0x20;

        *(int *)(*(int *)puVar1 + (int)DAT_06008400) = 0xffffffff;

        *(int *)puVar2 = *(int *)puVar1;

        *(short *)(*(int *)puVar1 + (int)DAT_06008402) = 0x28;

      }

    }

  }

  else {

    iVar3 = 0xb8;

    *(int *)(CAR_PTR_CURRENT + iVar3) = *(int *)(CAR_PTR_CURRENT + iVar3) + -1;

    if (*(int *)(*(int *)puVar1 + (int)DAT_0600835a) < 1) {

      iVar3 = -(int)*(short *)(0x060453CC + *(int *)(*(int *)puVar1 + iVar3) << 1);

    }

    else {

      iVar3 = (int)*(short *)(0x060453CC + *(int *)(*(int *)puVar1 + iVar3) << 1);

    }

    *(int *)(*(int *)puVar1 + 0x1d8) = iVar3;

  }

  (*(int(*)())0x06034F78)(puVar1,0);

  uVar4 = (*(int(*)())0x06034F78)();

  return uVar4;

}

/* race_finish_trigger_a -- Trigger race finish sequence (variant A).
 * Checks if target car has completed condition (DAT_060084a2 field == 0).
 * If so: plays finish sound (0xAE1102FF) when in race state, sets car
 * activation flag, stores finish time, and dispatches finish handler
 * FUN_060084ca with result table entry from 0x060453B4. */
void FUN_06008418(void)
{
  int *car_ptr = (int *)0x0607E944;

  if (*(int *)(CAR_PTR_TARGET + (int)DAT_060084a2) == 0) {
    if ((GAME_STATE_BIT & (unsigned int)0x00020000) != 0) {
      (*(int(*)())0x0601D5F4)(0, 0xAE1102FF);  /* finish sound */
    }
    unsigned char *flag = (unsigned char *)(*car_ptr + 1);
    *flag = *flag & 0xfe | 1;                   /* set finish bit */
    *(int *)(*car_ptr + (int)DAT_060084a6) = (int)DAT_060084a4;
    FUN_060084ca(*(int *)0x060453B4);
  }
}

/* race_finish_trigger_b -- Trigger race finish sequence (variant B).
 * Identical to race_finish_trigger_a but uses result table at 0x060453BC
 * (different course or mode variant). */
void FUN_06008460(void)
{
  int *car_ptr = (int *)0x0607E944;

  if (*(int *)(CAR_PTR_TARGET + (int)DAT_060084a2) == 0) {
    if ((GAME_STATE_BIT & (unsigned int)0x00020000) != 0) {
      (*(int(*)())0x0601D5F4)(0, 0xAE1102FF);  /* finish sound */
    }
    unsigned char *flag = (unsigned char *)(*car_ptr + 1);
    *flag = *flag & 0xfe | 1;                   /* set finish bit */
    *(int *)(*car_ptr + (int)DAT_060084a6) = (int)DAT_060084a4;
    FUN_060084ca(*(int *)0x060453BC);
  }
}

/* race_finish_dispatch -- Process finish state for current car.
 * Increments finish counter on target car, clears timer field, calls
 * FUN_060086c0 for result processing. If player 1 car (0x06078900) is
 * finishing in race mode: transitions to PHASE_FLAG=3 (results screen),
 * sets up camera parameters, disables VBL interrupt, stores finish place. */
void FUN_060084ca(void)
{
  int *car_ptr = (int *)0x0607E944;
  int off = (int)DAT_0600855e;

  *(int *)(CAR_PTR_TARGET + off) = *(int *)(CAR_PTR_TARGET + off) + 1;
  *(int *)(*car_ptr + off + -0x10) = 0;
  FUN_060086c0();

  /* If player 1 car finished in race mode */
  if ((*(char **)car_ptr == (char *)CAR_ARRAY_BASE) &&
      ((GAME_STATE_BIT & (unsigned int)0x00020000) != 0) &&
      ((*(int *)0x06078635 != '\0' || (*(short *)0x0607ED8C == 0)))) {

    PHASE_FLAG = 3;                         /* transition to results */
    *(int *)0x06078654 = 7;
    *(int *)0x06063E1C = 2;
    *(int *)0x06059F30 = 1;
    (*(int(*)())0x06038BD4)(8, 0);          /* SCU interrupt config */

    /* Camera setup for results screen */
    *(char **)0x06063E24 = (char *)0x00058000;
    *(char **)0x06063E34 = (char *)0x0000F300;
    *(char **)0x06063E28 = (char *)0x006E0000;
    *(char **)0x06063E2C = (char *)0x00100000;
    *(int *)0x06063E30 = 0;
    *(int *)0x0607866C = (char)*(int *)(*car_ptr + (int)PTR_DAT_06008560);
  }
}

/* collision_response_handler -- Handle car collision steering response.
 * If collision timer (DAT_06008624) is active: sets physics mode 0x46,
 * snaps heading to heading3 if direction flag == 1 and activation bit set.
 * Runs speed_force_timer(). When timer < 2: set phase flag based on
 * game state (4 for VS mode 0x200000, else 1). Returns collision offset. */
int FUN_060085b8(void)
{
    int *car_iter = (int *)0x0607E940;
    int result = 0;

    if (*(int *)(CAR_PTR_CURRENT + (int)DAT_06008624) != 0) {
        *(int *)0x0607EBD4 = 0x46;  /* physics mode: collision override */
        if ((*(int *)((int)DAT_06008626 + *(int *)car_iter) == 1) &&
            (((int)*(char *)(*(int *)car_iter + CAR_ACTIVATE_FLAGS) & 0x80U) != 0)) {
            *(int *)(*(int *)car_iter + CAR_HEADING2) = *(int *)(*(int *)car_iter + CAR_HEADING3);
            *(int *)(*(int *)car_iter + DAT_0600862a + -8) =
                *(int *)(*(int *)car_iter + (int)DAT_0600862a);
        }
        speed_force_timer();
        result = (int)DAT_06008624;
        if (*(int *)(*(int *)car_iter + result) < 2) {
            if (*(char **)0x0607EBC4 == 0x00200000) {
                *(int *)0x06078654 = 4;   /* VS mode phase */
            } else {
                *(int *)0x06078654 = 1;   /* normal phase */
            }
        }
    }
    return result;
}

int steering_physics_update()
{
  char *puVar1;

  puVar1 = (char *)0x0607E940;

  if ((**(unsigned char **)0x0607E940 & 8) == 0) {
    if (*(int *)(CAR_PTR_CURRENT + 0x01BC) != 0) {
      return speed_force_timer();
    }
    return 0;
  }

  **(unsigned char **)0x0607E940 = **(unsigned char **)0x0607E940 & 0xf7;

  if (*(int *)(*(int *)puVar1 + 0x01BC) != 0) {
    return speed_force_timer();
  }

  *(short *)(*(int *)puVar1 + 0x00D4) = 0x14;

  if ((GAME_STATE_BIT & 0x00800000) != 0) {
    FUN_060086c0(*(int *)0x060453C4);
    return 0;
  }

  FUN_060086c0(*(int *)(0x060453B4 + ((GAME_STATE_VAR & 1) << 3)));
  return 0;
}

/* result_table_apply -- Apply race result parameters from table entry.
 * Reads 2-word result entry from param_1: word 0 = completion code stored
 * at car+0x1B8, word 1 = timer base stored at DAT_0600871a offset.
 * Timer-0x28 stored at DAT_0600871c and car+0x208. Calls
 * FUN_06034F78 twice (CD sync), increments FORCE_SETUP_COUNT, runs timer. */
void FUN_060086c0(int *param_1)
{
  int *car_iter = (int *)0x0607E940;       /* car iteration pointer */

  (*(int(*)())0x06034F78)();                /* CD sync */
  (*(int(*)())0x06034F78)();                /* CD sync (double) */

  *(int *)(*car_iter + 0x1b8) = *param_1;  /* completion code */
  int timer = param_1[1];
  *(int *)(*car_iter + (int)DAT_0600871a) = timer;
  timer = timer + -0x28;
  *(int *)(*car_iter + (int)DAT_0600871c) = timer;
  *(int *)(*car_iter + 0x208) = timer;

  FORCE_SETUP_COUNT = FORCE_SETUP_COUNT + 1;
  speed_force_timer();
}

int speed_force_timer()
{

  short sVar1;

  char *puVar2;

  int iVar3;

  int *puVar4;

  puVar2 = (char *)0x0607E940;

  if (0 < *(int *)(CAR_PTR_CURRENT + (int)DAT_060087e8)) {

    *(int *)(CAR_PTR_CURRENT + (int)DAT_060087e8) =

         *(int *)(CAR_PTR_CURRENT + (int)DAT_060087e8) + -1;

  }

  if (0 < *(int *)(*(int *)puVar2 + (int)DAT_060087ea)) {

    *(int *)(*(int *)puVar2 + (int)DAT_060087ea) = *(int *)(*(int *)puVar2 + (int)DAT_060087ea) + -1

    ;

  }

  if (*(int *)((int)DAT_060087ea + *(int *)puVar2) == 10) {

    *(short *)(*(int *)puVar2 + (int)DAT_060087ec) = 10;

  }

  iVar3 = 0x1b8;

  puVar4 = *(int **)(*(int *)puVar2 + iVar3);

  *(int **)(*(int *)puVar2 + iVar3) = puVar4 + 3;

  *(int *)(*(int *)puVar2 + iVar3 + -4) = *puVar4;

  sVar1 = *(short *)(puVar4 + 1);

  if ((*(unsigned char *)(*(int *)puVar2 + 0x1c0) & 0x40) == 0) {

    if (((int)*(char *)(*(int *)puVar2 + 0x1c0) & 0x80U) == 0) {

      *(int *)(*(int *)puVar2 + 0x1c8) = (int)*(short *)((int)puVar4 + 6);

      *(int *)(*(int *)puVar2 + (int)DAT_060088ac) = (int)*(short *)(puVar4 + 2);

      *(int *)(*(int *)puVar2 + 0x1d0) = (int)*(short *)((int)puVar4 + 10);

    }

    else {

      *(int *)(*(int *)puVar2 + 0x1c8) = -(int)*(short *)((int)puVar4 + 6);

      *(int *)(*(int *)puVar2 + (int)DAT_060087f4) = -(int)*(short *)(puVar4 + 2);

      *(int *)(*(int *)puVar2 + 0x1d0) = (int)*(short *)((int)puVar4 + 10);

    }

  }

  else {

    *(int *)(*(int *)puVar2 + 0x1c8) = (int)*(short *)((int)puVar4 + 6);

    *(int *)(*(int *)puVar2 + (int)DAT_060087f4) = -(int)*(short *)(puVar4 + 2);

    *(int *)(*(int *)puVar2 + 0x1d0) = -(int)*(short *)((int)puVar4 + 10);

  }

  if (*(unsigned int *)(*(int *)puVar2 + 4) == (unsigned int)(unsigned char)*(int *)0x0607EBBC) {

    *(int *)(*(int *)puVar2 + (int)DAT_060088b0) = *(int *)(*(int *)puVar2 + (int)DAT_060088b0) + 1;

    if (DAT_060088b2 < sVar1) {

      *(int *)(*(int *)puVar2 + (int)DAT_060088b0) = 0;

    }

    if ((*(int *)(*(int *)puVar2 + (int)DAT_060088b4) == 0) &&

       ((*(int *)0x0607866C = 0, *(int *)0x06078635 != '\0' || (*(short *)0x0607ED8C == 0)))) {

      PHASE_FLAG = 4;

    }

  }

  iVar3 = *(int *)(*(int *)puVar2 + (int)DAT_060088b4);

  if (iVar3 == 0) {

    iVar3 = (int)DAT_060088b6;

    *(int *)(*(int *)puVar2 + iVar3) = 0;

    *(int *)(*(int *)puVar2 + iVar3 + 0x14) = 0;

    *(int *)(*(int *)puVar2 + iVar3 + 0x18) = 0;

    iVar3 = iVar3 + 0x1c;

    *(int *)(*(int *)puVar2 + iVar3) = 0;

  }

  return iVar3;

}

/* state_27_countdown -- State 27 handler: countdown to state 30 transition.
 * Decrements STATE_COUNTDOWN each frame. When it hits 0, transitions
 * to state 30. Calls background update unconditionally, CD status read
 * only while still in state 27. */
void FUN_06009e02(void)
{
    STATE_COUNTDOWN--;
    if (STATE_COUNTDOWN == 0) {
        GAME_STATE = 30;
    }
    func_0601389E();
    if (GAME_STATE != 27) {
        func_06018E70();
    }
    STATE_UPDATE_FLAG = 1;
}

/* sound_channels_reset -- Stop all sound channels and reset SCSP slots.
 * Sends stop commands (data=0) to channels 1, 3, 2, then writes
 * SCSP slot configuration: slot 0 key-off (0xAE0001FF) and
 * slot 6 volume reset (0xAE0600FF).
 * Called during state transitions (states 18, 23) and error recovery. */
extern void sound_cmd_dispatch(int channel, int command);

void sound_channels_reset(void)
{
    sound_cmd_dispatch(1, 0);  /* stop channel 1 */
    sound_cmd_dispatch(3, 0);  /* stop channel 3 */
    sound_cmd_dispatch(2, 0);  /* stop channel 2 */
    sound_cmd_dispatch(0, 0xAE0001FF);  /* SCSP slot 0: key-off */
    sound_cmd_dispatch(0, 0xAE0600FF);  /* SCSP slot 6: volume reset */
}
