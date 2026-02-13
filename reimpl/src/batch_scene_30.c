#include "game.h"

extern int DAT_060303b6;
extern int DAT_06030402;
extern int DAT_0603045e;
extern int DAT_060304ac;
extern int DAT_060304ae;
extern int DAT_060304f0;
extern int DAT_060304f2;
extern int DAT_0603056a;
extern int DAT_06030588;
extern int DAT_060305ae;
extern int DAT_060305b0;
extern int DAT_06030602;
extern int DAT_06030604;
extern int DAT_0603063a;
extern int DAT_06030680;
extern int DAT_060306c8;
extern int DAT_06030714;
extern int DAT_06030716;
extern int DAT_06030742;
extern int DAT_06030a3e;
extern int DAT_06030a40;
extern int DAT_06030a42;
extern int DAT_06030a44;
extern int DAT_06030a46;
extern int DAT_06030b24;
extern int DAT_06030b26;
extern int DAT_06030b28;
extern int DAT_06030b2a;
extern int DAT_06030bc2;
extern int DAT_06030be0;
extern int DAT_06030be2;
extern int DAT_06030c00;
extern int DAT_06030c02;
extern int DAT_06030c20;
extern int DAT_06030c22;
extern int DAT_06030c40;
extern int DAT_06030c42;
extern int DAT_06030cca;
extern int DAT_06030d22;
extern int DAT_06030da2;
extern int DAT_06030eae;
extern int DAT_060310b8;
extern int DAT_0603112e;
extern int DAT_06031130;
extern int DAT_06031132;
extern int DAT_06031188;
extern int DAT_0603118a;
extern int DAT_060311b6;
extern int DAT_06031208;
extern int DAT_0603120a;
extern int DAT_0603129c;
extern int DAT_0603129e;
extern int DAT_0603135c;
extern int DAT_0603143a;
extern int DAT_06031496;
extern int DAT_06031516;
extern int DAT_0603156a;
extern int DAT_060315b0;
extern int DAT_060315be;
extern int DAT_060315ce;
extern int DAT_0603162a;
extern int DAT_0603162c;
extern int DAT_0603162e;
extern int DAT_06031750;
extern int DAT_0603178c;
extern int DAT_060317c6;
extern int DAT_060318e4;
extern int DAT_06031918;
extern int DAT_0603196c;
extern int DAT_06031a64;
extern int DAT_06031b22;
extern int DAT_06031bf8;
extern int DAT_06031c7c;
extern int DAT_06031c7e;
extern int DAT_06031d36;
extern int DAT_06031d38;
extern int DAT_06031d3a;
extern int DAT_06031e30;
extern int DAT_06031eee;
extern int DAT_06031fc4;
extern int DAT_06032048;
extern int DAT_0603204a;
extern void FUN_0603072e();
extern void FUN_06030a9c();
extern void FUN_06030b68();
extern void FUN_06030dfe();
extern void FUN_06031340();
extern int FUN_0603136e();
extern unsigned int FUN_06031d1a();
extern int FUN_060320e6();
extern int PTR_DAT_06030318;
extern int PTR_DAT_060303b8;
extern int PTR_DAT_06030404;
extern int PTR_DAT_060304b0;
extern int PTR_DAT_0603056c;
extern int PTR_DAT_06030598;
extern int PTR_DAT_06030b2c;
extern int PTR_DAT_06031234;
extern int PTR_DAT_060312a0;
extern int PTR_DAT_0603156c;
extern int PTR_DAT_06031adc;
extern int PTR_DAT_06031b64;
extern int PTR_DAT_06031ba8;
extern int PTR_DAT_06031c80;
extern int PTR_DAT_06031ea8;
extern int PTR_DAT_06031f30;
extern int PTR_DAT_06031f74;
extern int PTR_DAT_0603204c;

/* replay_input_process -- Read/record input state for replay/ghost car mode.
 * Replay buffer at 0x0607ED88 (read index), 0x0607ED90 (data array).
 * When replay active (0x0607ED8C != 0): reads packed byte from buffer,
 *   low 2 bits = steering direction → car+DAT_060304ac
 *   bit 0x80 = accelerate (ramps car+DAT_060304ae speed, max PTR_DAT_060304b0)
 *   bit 0x40 = brake (ramps car+0x90 brake, capped at 0xB8)
 *   no bit = decelerate toward 0x38 minimum
 * When recording: reads digital input (0x06063D9A for steering, 0x06063D98
 *   for buttons), maps D-pad to steering 0-3 via masks at 0x06081890-96,
 *   shoulder buttons for increment/decrement via 0x06081888/8A,
 *   button masks at 0x0608188C (accel) and 0x0608188E (brake).
 *   Packs state byte and writes to replay buffer, wraps at DAT_0603045e. */
void replay_input_process()
{
  unsigned short button_state;
  char *replay_buf_ptr;
  int car_ptr;
  unsigned int input_raw;
  short steer_val;
  int speed;
  int accel_flag;
  int offset;
  int max_speed;
  unsigned char packed_state;
  replay_buf_ptr = (char *)0x0607ED88;                      /* replay buffer read index */
  car_ptr = CAR_PTR_TARGET;
  if (*(short *)0x0607ED8C != 0) {
    /* replay playback: read packed input byte from buffer */
    offset = *(int *)0x0607ED88;
    packed_state = ((int *)0x0607ED90)[offset];              /* replay data array */
    *(unsigned short *)(DAT_060304ac + car_ptr) = packed_state & 3;  /* steering direction (0-3) */
    *(int *)replay_buf_ptr = offset + 2;                     /* advance read index */
    accel_flag = 1;
    if ((packed_state & 0x80) == 0) {
      /* no accelerate: decelerate toward 0x38 */
      accel_flag = 0x38;
      offset = *(int *)(DAT_060304f0 + car_ptr) + -2;
      if (offset < 0x38) {
        offset = 0x38;                                       /* clamp minimum speed */
      }
      *(int *)(DAT_060304f0 + car_ptr) = offset;
      *(int *)(0x0000006C + car_ptr) = 0;                   /* clear acceleration flag */
    }
    else {
      /* accelerate: ramp up speed */
      offset = (int)DAT_060304ae;
      *(int *)(offset + car_ptr) = 1;                        /* set accel active */
      offset = offset + 8;
      speed = *(int *)(offset + car_ptr);
      if (speed <= PTR_DAT_060304b0) {
        speed = speed + 4;                                   /* ramp up by 4 */
      }
      *(int *)(offset + car_ptr) = speed;
    }
    if ((packed_state & 0x40) == 0) {
      /* no brake: reduce brake pressure */
      offset = *(int *)(0x00000090 + car_ptr);
      *(int *)(0x0000008C + car_ptr) = offset;              /* save previous brake */
      offset = offset + -5;
      if (offset < 0x38) {
        offset = 0x38;                                       /* clamp minimum */
      }
      *(int *)(0x00000090 + car_ptr) = offset;
      *(int *)(0x00000088 + car_ptr) = 0;                   /* clear brake flag */
    }
    else {
      /* brake active: ramp up brake pressure */
      *(int *)(0x00000088 + car_ptr) = accel_flag;
      offset = 0x00000090;
      speed = *(int *)(0x00000090 + car_ptr);
      max_speed = 0xb8;
      *(int *)(0x0000008C + car_ptr) = speed;
      if (speed <= max_speed) {
        speed = speed + 5;                                   /* ramp up by 5 */
      }
      *(int *)(offset + car_ptr) = speed;
    }
    return;
  }
  /* recording mode: read live input and pack into replay buffer */
  input_raw = (unsigned int)*(unsigned short *)0x06063D9A;   /* digital input state */
  offset = (int)PTR_DAT_06030318;
  /* map D-pad to steering direction (0-3) */
  if (*(short *)0x0608188A < 1) {
    if ((input_raw & (int)*(short *)0x06081896) == 0) {
      if ((input_raw & (int)*(short *)0x06081894) == 0) {
        if ((input_raw & (int)*(short *)0x06081892) == 0) {
          if ((input_raw & (int)*(short *)0x06081890) != 0) {
            *(short *)(offset + car_ptr) = 0;                /* steer direction 0 */
          }
        }
        else {
          *(short *)(offset + car_ptr) = 1;                  /* steer direction 1 */
        }
      }
      else {
        *(short *)(offset + car_ptr) = 2;                    /* steer direction 2 */
      }
    }
    else {
      *(short *)(offset + car_ptr) = 3;                      /* steer direction 3 */
    }
  }
  else if ((input_raw & (int)*(short *)0x0608188A) == 0) {
    /* shoulder down: increment steering (max 3) */
    if ((input_raw & (int)*(short *)0x06081888) != 0) {
      steer_val = *(short *)(offset + car_ptr);
      if (steer_val != 3) {
        steer_val = steer_val + 1;
      }
      *(short *)(offset + car_ptr) = steer_val;
    }
  }
  else {
    /* shoulder up: decrement steering (min 0) */
    steer_val = *(short *)(offset + car_ptr);
    if (steer_val != 0) {
      steer_val = steer_val + -1;
    }
    *(short *)(offset + car_ptr) = steer_val;
  }
  packed_state = (unsigned char)*(short *)(offset + car_ptr);
  button_state = *(unsigned short *)0x06063D98;              /* button input */
  accel_flag = 1;
  if ((button_state & *(unsigned short *)0x0608188C) == 0) {
    /* no accel button: decelerate */
    accel_flag = 0x38;
    offset = *(int *)(DAT_06030402 + car_ptr) + -2;
    if (offset < 0x39) {
      offset = 0x38;
    }
    *(int *)(DAT_06030402 + car_ptr) = offset;
    *(int *)(0x0000006C + car_ptr) = 0;
  }
  else {
    /* accel button pressed: set bit 0x80, ramp speed */
    packed_state = packed_state | 0x80;
    offset = (int)DAT_060303b6;
    *(int *)(offset + car_ptr) = 1;
    offset = offset + 8;
    speed = *(int *)(offset + car_ptr);
    if (speed <= PTR_DAT_060303b8) {
      speed = speed + 4;
    }
    *(int *)(offset + car_ptr) = speed;
  }
  if ((button_state & *(unsigned short *)0x0608188E) == 0) {
    /* no brake button: reduce brake */
    offset = *(int *)(0x00000090 + car_ptr);
    *(int *)(0x0000008C + car_ptr) = offset;
    offset = offset + -5;
    if (offset < 0x38) {
      offset = 0x38;
    }
    *(int *)(0x00000090 + car_ptr) = offset;
    *(int *)(0x00000088 + car_ptr) = 0;
  }
  else {
    /* brake button pressed: set bit 0x40, ramp brake */
    packed_state = packed_state | 0x40;
    *(int *)(0x00000088 + car_ptr) = accel_flag;
    offset = 0x00000090;
    speed = *(int *)(0x00000090 + car_ptr);
    max_speed = 0xb8;
    *(int *)(0x0000008C + car_ptr) = speed;
    if (speed <= max_speed) {
      speed = speed + 5;
    }
    *(int *)(offset + car_ptr) = speed;
  }
  /* write packed state to replay buffer */
  replay_buf_ptr = (char *)0x0607ED88;
  offset = *(int *)0x0607ED88;
  ((int *)0x0607ED90)[offset] = packed_state;
  car_ptr = offset + 2;
  if ((int)DAT_0603045e <= offset + 2) {
    car_ptr = offset;                                        /* wrap buffer index */
  }
  *(int *)replay_buf_ptr = car_ptr;
  return;
}



/* FUN_06030a06: L2 version in timer_update.c */
extern void FUN_06030A06(void);




/* FUN_06030fc0: L2 version in collision.c */
extern void FUN_06030FC0(int car_a, int car_b, int dist);



/* FUN_060316c4: L2 version in collision.c */
extern void FUN_060316C4(int car_a, int car_b, int dist);
extern void FUN_06031df4();
extern void FUN_06031d8c();
extern void FUN_060316c4();
extern void FUN_06030fc0();
extern void FUN_06030a06();
extern void FUN_0603053c();

/* polygon_face_project_and_clip -- Project polygon faces through view matrix and clip.
 * param_1 = polygon face data base, param_2 = face color/material type,
 * param_3 = face count (processes backwards).
 * Each face is 0x18 bytes with vertex normals at offsets -6..-1 and face
 * index at -2. Loads face normals from table at 0x06094FA8 (0xC-byte entries).
 * Transforms vertices by 3x3 view matrix at *(0x06089EDC) using software
 * 32-bit fixed-point MAC multiply-accumulate (no FPU).
 * Performs screen-space bounds check via FUN_06031d1a (DAT_06031d36/d38/d3a).
 * Writes clipped quad to output buffer at 0x0608AC20 (0x18-byte entries,
 * indexed by 0x060620D0). Dispatches final render via function pointer
 * table at 0x06031D78 (indexed by face type & 7). */
unsigned int FUN_06031a28(param_1, param_2, param_3)
    int param_1;
    char param_2;
    int param_3;
{
  unsigned int uVar1;
  char *puVar2;
  char *puVar3;
  unsigned int uVar4;
  int iVar5;
  int iVar6;
  unsigned int uVar7;
  int extraout_r3 = 0;
  int extraout_r3_00;
  int extraout_r3_01;
  int iVar8;
  unsigned int uVar9;
  int iVar10;
  char *puVar11;
  int *puVar12;
  int *puVar13;
  int iVar14;
  int iVar15;
  unsigned int *puVar16;
  int *piVar17;
  int iVar18;
  unsigned int *puVar19;
  unsigned int *puVar21;
  unsigned int *puVar22;
  int iVar23;
  int iVar24;
  unsigned int in_sr = 0;
  unsigned int uVar25;
  unsigned int uVar26;
  unsigned int uVar27;
  unsigned int uVar28;
  unsigned int uVar29;
  unsigned int *puVar20;

  puVar3 = (char *)0x06031D3C;
  puVar2 = (char *)0x06031D5C;
  puVar19 = (unsigned int *)(param_1 + param_3 * 0x18);
  do {
    puVar20 = puVar19 + -6;
    uVar4 = (unsigned int)(short)*(unsigned short *)(puVar19 + -2);
    puVar22 = (unsigned int *)-256;
    puVar16 = (unsigned int *)(0x06094FA8 + (unsigned int)*(unsigned short *)(puVar19 + -2) * 0xc);
    uVar7 = puVar16[2];
    uVar26 = in_sr & 0xfffffffe;
    uVar25 = uVar26 | 0 < (int)uVar7;
    if (((unsigned char)uVar25 & 1) == 1) {
      puVar22[4] = 0xa0;
      *puVar22 = uVar7;
      puVar22[5] = 0;
      *(unsigned int *)puVar2 = uVar7;
      puVar11 = (char *)0x06031D6C;
      if ((puVar19[-3] & 0x80000) == 0) {
        puVar21 = *(unsigned int **)0x06089EDC;
        uVar4 = *puVar21;
        uVar25 = *puVar20;
        { long long _m44 = (long long)(int)uVar4 * (int)uVar25;
          uVar25 = (unsigned int)((unsigned long long)_m44 >> 32);
          uVar27 = (unsigned int)_m44; }
        uVar7 = puVar21[1];
        uVar4 = puVar19[-5];
        { long long _m43 = (long long)(int)uVar7 * (int)uVar4;
          uVar4 = (unsigned int)((unsigned long long)_m43 >> 32);
          uVar28 = (unsigned int)_m43; }
        uVar28 = uVar27 + uVar28;
        uVar25 = uVar4 + (uVar28 < uVar27) + uVar25;
        uVar7 = puVar21[2];
        uVar4 = puVar19[-4];
        { long long _m42 = (long long)(int)uVar7 * (int)uVar4;
          uVar4 = (unsigned int)((unsigned long long)_m42 >> 32);
          uVar29 = (unsigned int)_m42; }
        uVar29 = uVar28 + uVar29;
        uVar25 = uVar4 + (uVar29 < uVar28) + uVar25;
        uVar7 = puVar21[3];
        uVar4 = *puVar20;
        { long long _m41 = (long long)(int)uVar7 * (int)uVar4;
          uVar4 = (unsigned int)((unsigned long long)_m41 >> 32);
          uVar28 = (unsigned int)_m41; }
        *(unsigned int *)0x06031D6C = uVar25 << 0x10 | uVar29 >> 0x10;
        uVar7 = puVar21[4];
        uVar25 = puVar19[-5];
        { long long _m40 = (long long)(int)uVar7 * (int)uVar25;
          uVar25 = (unsigned int)((unsigned long long)_m40 >> 32);
          uVar29 = (unsigned int)_m40; }
        uVar29 = uVar28 + uVar29;
        uVar4 = uVar25 + (uVar29 < uVar28) + uVar4;
        uVar7 = puVar21[5];
        uVar25 = puVar19[-4];
        { long long _m39 = (long long)(int)uVar7 * (int)uVar25;
          uVar25 = (unsigned int)((unsigned long long)_m39 >> 32);
          uVar28 = (unsigned int)_m39; }
        uVar28 = uVar29 + uVar28;
        uVar4 = uVar25 + (uVar28 < uVar29) + uVar4;
        uVar7 = puVar21[6];
        uVar25 = *puVar20;
        { long long _m38 = (long long)(int)uVar7 * (int)uVar25;
          uVar25 = (unsigned int)((unsigned long long)_m38 >> 32);
          uVar29 = (unsigned int)_m38; }
        *(unsigned int *)(puVar11 + 4) = uVar4 << 0x10 | uVar28 >> 0x10;
        uVar7 = puVar21[7];
        uVar4 = puVar19[-5];
        { long long _m37 = (long long)(int)uVar7 * (int)uVar4;
          uVar4 = (unsigned int)((unsigned long long)_m37 >> 32);
          uVar28 = (unsigned int)_m37; }
        uVar28 = uVar29 + uVar28;
        uVar25 = uVar4 + (uVar28 < uVar29) + uVar25;
        uVar7 = puVar21[8];
        uVar4 = puVar19[-4];
        { long long _m36 = (long long)(int)uVar7 * (int)uVar4;
          uVar4 = (unsigned int)((unsigned long long)_m36 >> 32);
          uVar29 = (unsigned int)_m36; }
        uVar29 = uVar28 + uVar29;
        uVar25 = uVar4 + (uVar29 < uVar28) + uVar25;
        *(unsigned int *)(puVar11 + 8) = uVar25 << 0x10 | uVar29 >> 0x10;
        uVar4 = *(unsigned int *)puVar11;
        uVar25 = *puVar16;
        { long long _m35 = (long long)(int)uVar4 * (int)uVar25;
          uVar25 = (unsigned int)((unsigned long long)_m35 >> 32);
          uVar27 = (unsigned int)_m35; }
        uVar7 = *(unsigned int *)(puVar11 + 4);
        uVar4 = puVar16[1];
        { long long _m34 = (long long)(int)uVar7 * (int)uVar4;
          uVar4 = (unsigned int)((unsigned long long)_m34 >> 32);
          uVar28 = (unsigned int)_m34; }
        uVar28 = uVar27 + uVar28;
        uVar25 = uVar4 + (uVar28 < uVar27) + uVar25;
        uVar7 = *(unsigned int *)(puVar11 + 8);
        uVar4 = puVar16[2];
        { long long _m33 = (long long)(int)uVar7 * (int)uVar4;
          uVar4 = (unsigned int)((unsigned long long)_m33 >> 32);
          uVar29 = (unsigned int)_m33; }
        uVar29 = uVar28 + uVar29;
        uVar25 = uVar4 + (uVar29 < uVar28) + uVar25;
        uVar4 = uVar25 << 0x10 | uVar29 >> 0x10;
        uVar26 = uVar26 | 0 < (int)uVar4;
        uVar25 = uVar26;
        if (((unsigned char)uVar26 & 1) != 1) goto LAB_06031cf2;
      }
      uVar4 = puVar16[1];
      uVar25 = *puVar16;
      uVar9 = puVar22[7];
      piVar17 = (int *)(0x06094FA8 + (unsigned int)*(unsigned short *)((int)puVar19 + -6) * 0xc);
      uVar7 = piVar17[2];
      puVar22[4] = 0xa0;
      *puVar22 = uVar7;
      puVar22[5] = 0;
      *(int *)puVar3 = (int)((unsigned long long)((long long)(int)uVar9 * (long long)(int)uVar25) >> 0x20);
      *(int *)(puVar3 + 4) =
           (int)((unsigned long long)((long long)(int)uVar9 * (long long)(int)-uVar4) >> 0x20);
      puVar11 = puVar3;
      uVar4 = FUN_06031d1a();
      uVar25 = uVar26 & 0xfffffffe | (unsigned int)(0 < extraout_r3);
      if (((unsigned char)uVar25 & 1) == 1) {
        *(int *)(puVar2 + 4) = extraout_r3;
        puVar12 = (int *)(puVar11 + 8);
        iVar6 = piVar17[1];
        iVar5 = *piVar17;
        uVar4 = puVar22[7];
        piVar17 = (int *)(0x06094FA8 + (unsigned int)*(unsigned short *)(puVar19 + -1) * 0xc);
        uVar26 = piVar17[2];
        puVar22[4] = 0xa0;
        *puVar22 = uVar26;
        puVar22[5] = 0;
        *puVar12 = (int)((unsigned long long)((long long)(int)uVar4 * (long long)iVar5) >> 0x20);
        *(int *)(puVar11 + 0xc) =
             (int)((unsigned long long)((long long)(int)uVar4 * (long long)-iVar6) >> 0x20);
        uVar4 = FUN_06031d1a();
        uVar25 = uVar25 & 0xfffffffe | (unsigned int)(0 < extraout_r3_00);
        if (((unsigned char)uVar25 & 1) == 1) {
          *(int *)(puVar2 + 8) = extraout_r3_00;
          puVar13 = puVar12 + 2;
          iVar6 = piVar17[1];
          iVar5 = *piVar17;
          uVar4 = puVar22[7];
          piVar17 = (int *)(0x06094FA8 + (unsigned int)*(unsigned short *)((int)puVar19 + -2) * 0xc);
          uVar26 = piVar17[2];
          puVar22[4] = 0xa0;
          *puVar22 = uVar26;
          puVar22[5] = 0;
          *puVar13 = (int)((unsigned long long)((long long)(int)uVar4 * (long long)iVar5) >> 0x20);
          puVar12[3] = (int)((unsigned long long)((long long)(int)uVar4 * (long long)-iVar6) >> 0x20);
          uVar4 = FUN_06031d1a();
          uVar25 = uVar25 & 0xfffffffe | (unsigned int)(0 < extraout_r3_01);
          if (((unsigned char)uVar25 & 1) == 1) {
            *(int *)(puVar2 + 0xc) = extraout_r3_01;
            iVar5 = piVar17[1];
            uVar26 = puVar22[7];
            puVar13[2] = (int)((unsigned long long)((long long)(int)uVar26 * (long long)*piVar17) >> 0x20);
            puVar13[3] = (int)((unsigned long long)((long long)(int)uVar26 * (long long)-iVar5) >> 0x20);
            FUN_06031d1a();
            puVar11 = (char *)0x0608AC20;
            iVar5 = *(int *)0x060620D0;
            iVar23 = -176;
            uVar4 = *(unsigned int *)puVar3;
            iVar6 = *(int *)(puVar3 + 8);
            iVar10 = *(int *)(puVar3 + 0x10);
            iVar15 = *(int *)(puVar3 + 0x18);
            uVar25 = uVar25 & 0xfffffffe;
            if ((((iVar23 <= (int)uVar4) || (iVar23 <= iVar6)) || (iVar23 <= iVar10)) ||
               (iVar23 <= iVar15)) {
              iVar23 = 0xb0;
              uVar26 = uVar25 | (int)uVar4 < iVar23;
              if (((((unsigned char)uVar26 & 1) == 1) ||
                  (uVar26 = uVar25 | iVar6 < iVar23, ((unsigned char)uVar26 & 1) == 1)) ||
                 ((uVar26 = uVar25 | iVar10 < iVar23, ((unsigned char)uVar26 & 1) == 1 ||
                  (uVar26 = uVar25 | iVar15 < iVar23, uVar25 = uVar26, ((unsigned char)uVar26 & 1) != 1)))) {
                iVar24 = -127;
                iVar23 = *(int *)(puVar3 + 4);
                iVar8 = *(int *)(puVar3 + 0xc);
                iVar14 = *(int *)(puVar3 + 0x14);
                iVar18 = *(int *)(puVar3 + 0x1c);
                uVar25 = uVar26 & 0xfffffffe;
                if (((iVar24 <= iVar23) || (iVar24 <= iVar8)) ||
                   ((iVar24 <= iVar14 ||
                    (uVar25 = uVar25 | iVar18 < iVar24, ((unsigned char)uVar25 & 1) != 1)))) {
                  iVar24 = 0x51;
                  if ((((iVar23 < iVar24) || (iVar8 < iVar24)) || (iVar14 < iVar24)) ||
                     (uVar25 = uVar25 & 0xfffffffe, iVar18 < iVar24)) {
                    *(short *)(0x0608AC20 + iVar5 * 0x18 + 0x16) = (short)iVar18;
                    *(short *)(puVar11 + iVar5 * 0x18 + 0x14) = (short)iVar15;
                    *(short *)(puVar11 + iVar5 * 0x18 + 0x12) = (short)iVar14;
                    *(short *)(puVar11 + iVar5 * 0x18 + 0x10) = (short)iVar10;
                    *(short *)(puVar11 + iVar5 * 0x18 + 0xe) = (short)iVar8;
                    *(short *)(puVar11 + iVar5 * 0x18 + 0xc) = (short)iVar6;
                    *(short *)(puVar11 + iVar5 * 0x18 + 10) = (short)iVar23;
                    *(short *)(puVar11 + iVar5 * 0x18 + 8) = (short)uVar4;
                    *(short *)(puVar11 + iVar5 * 0x18 + 6) =
                         *(short *)((int)puVar19 + -10);
                    puVar11[iVar5 * 0x18 + 4] =
                         (unsigned char)((unsigned int)(int)*(short *)(puVar19 + -3) >> 4) & 0xf;
                    puVar11[iVar5 * 0x18 + 5] = param_2;
                    uVar25 = (*(int(*)())(*(int *)(0x06031D78 +
                                         ((int)*(short *)(puVar19 + -3) & 7U) << 2)))(*(int *)(puVar2 + 4),*(int *)(puVar2 + 8),
                                        *(int *)(puVar2 + 0xc));
                    return uVar25;
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_06031cf2:
    param_3 = param_3 + -1;
    in_sr = uVar25 & 0xfffffffe | (unsigned int)(param_3 == 0);
    puVar19 = puVar20;
    if (((unsigned char)in_sr & 1) == 1) {
      return uVar4;
    }
  } while( 1 );
}



