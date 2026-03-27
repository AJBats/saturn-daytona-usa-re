/* TU: FUN_0602D43C — Collision/steering response + speed/position writers
 *
 * 8 functions from the player physics pipeline:
 *   FUN_0602D43C  — Collision + steering response (pipeline call 16a)
 *   FUN_0602D7E4  — Helper: decrement drift counter
 *   sym_0602D814  — Speed writer (pipeline call 18)
 *   sym_0602D82A  — Speed writer continued (gear scaling)
 *   sym_0602D88E  — Fall-through prologue for FUN_0602D89A
 *   FUN_0602D89A  — Player position update entry (loads car ptr, calls D8BC)
 *   sym_0602D8BC  — Position writer body (pipeline call 19)
 *   FUN_0602D8C6  — Position writer core (sin/cos integration)
 *
 * Car pointer convention:
 *   FUN_0602D43C, FUN_0602D7E4, sym_0602D814: car in r14 (caller prologue)
 *   sym_0602D8BC, FUN_0602D8C6: car in r0 (loaded from global)
 */

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

/* Fixed-point multiply: (a * b) >> 16 using SH-2 hardware dmuls.l + xtrct.
 * This is the core operation for all physics math in the game.
 * Cygnus 2.7 doesn't optimize long long multiply to dmuls.l,
 * so we use inline asm to get the hardware instruction directly. */
static __inline__ int fixed_mul(int a, int b)
{
    int hi, lo;
    asm("dmuls.l %2,%3\n\tsts mach,%0\n\tsts macl,%1"
        : "=r"(hi), "=r"(lo) : "r"(a), "r"(b));
    return (hi << 16) | ((uint)lo >> 16);
}

/* External functions */
extern int FUN_06027344();   /* sin lookup */
extern int FUN_06027348();   /* cos lookup */
extern int FUN_06027378();   /* atan2 variant */
extern int sym_0602ECCC();   /* fixed-point divide */
extern void FUN_0602D924();  /* drift position update (external TU) */

/* External data */
extern char sym_060477BC;    /* gear ratio table (8 entries x 4 bytes) */
extern char sym_0607E944;    /* player car pointer global */

/* ──────────────────────────────────────────────────────────────────────
 * FUN_0602D7E4 — Decrement drift counter
 *
 * Assembly: 36 bytes. Decrements car[+0x166] when speed > 0.
 * If counter > 3: subtract 3. If counter in [1,3] and nonzero: set to 10.
 * ────────────────────────────────────────────────────────────────────── */
void FUN_0602D7E4(int car)
{
    int speed;
    short counter;

    speed = *(int *)(car + 8);
    if (speed <= 0) return;

    counter = *(short *)(car + 0x166);
    if (counter <= 3) {
        if (counter != 0) {
            *(short *)(car + 0x166) = 7;   /* 10 - 3 */
        } else {
            *(short *)(car + 0x166) = 10;
        }
    }
    /* counter > 3: do nothing */
}

/* ──────────────────────────────────────────────────────────────────────
 * sym_0602D814 + sym_0602D82A — Speed writer
 *
 * Integrates accel_delta (+0xFC) into speed (+0x0C).
 * Then gear-scales the result for downstream consumption.
 *
 * Assembly (sym_0602D814):
 *   mov r14, r0          ; car ptr
 *   mov.l @(12, r0), r4  ; speed = car[+0x0C]
 *   mov.w DAT_d862, r2   ; r2 = 0xFC
 *   mov.l @(r0, r2), r3  ; accel_delta = car[+0xFC]
 *   add r3, r4           ; speed += accel_delta
 *   mov.l r4, @(12, r0)  ; car[+0x0C] = speed
 *   cmp/pz r4            ; if speed >= 0 goto D82A
 *   bt sym_0602D82A
 *   mov #0, r3           ; else: speed = 0, accel_delta = 0
 *   mov.l r3, @(12, r0)
 *   mov.l r3, @(r0, r2)
 *
 * Assembly (sym_0602D82A):
 *   gear_idx = car[+0xDC] (short)
 *   gear_ratio = sym_060477BC[gear_idx * 4]
 *   product = (speed * gear_ratio) >> 16  (xtrct = middle 32 of 64)
 *   scaled = (product * 0x0221AC91) >> 16
 *   clamped = clamp(scaled, 0, 0x2134)
 *   car[+0xE0] = clamped
 *   car[+0xE8] = max(scaled - clamped, 0)
 * ────────────────────────────────────────────────────────────────────── */
void sym_0602D814(int car)
{
    int speed, accel_delta;
    int gear_idx, gear_ratio;
    int mid32, scaled, clamped, excess;

    /* Step 1: speed += accel_delta */
    speed = *(int *)(car + 0x0C);
    accel_delta = *(int *)(car + 0xFC);
    speed = speed + accel_delta;
    *(int *)(car + 0x0C) = speed;

    if (speed < 0) {
        *(int *)(car + 0x0C) = 0;
        *(int *)(car + 0xFC) = 0;
    }

    /* Step 2 (sym_0602D82A): gear-scaled speed */
    speed = *(int *)(car + 0x0C);
    gear_idx = *(short *)(car + 0xDC);
    gear_ratio = *(int *)((int)&sym_060477BC + (gear_idx << 2));

    /* fixed_mul: (speed * gear_ratio) >> 16 via dmuls.l + xtrct */
    mid32 = fixed_mul(speed, gear_ratio);

    /* Second fixed_mul by constant 0x0221AC91 */
    mid32 = fixed_mul(mid32, 0x0221AC91);
    scaled = (int)((uint)mid32 >> 16);

    /* Clamp to [0, 0x2134] */
    clamped = scaled;
    if (scaled <= 0) {
        clamped = 0;
    } else if (scaled > 0x2134) {
        clamped = 0x2134;
    }
    *(int *)(car + 0xE0) = clamped;

    /* Excess = raw - clamped, clamped >= 0 */
    excess = scaled - clamped;
    if (excess < 0) excess = 0;
    *(int *)(car + 0xE8) = excess;
}

/* ──────────────────────────────────────────────────────────────────────
 * FUN_0602D8C6 — Position writer core
 *
 * Integrates speed into world position using sin/cos of slip angle.
 *
 * Assembly:
 *   car[+0x20] = car[+0x30]           ; heading = heading_copy
 *   slip = -car[+0x28]                ; negate slip angle
 *   speed = car[+0x0C]
 *   save car[+0x38] = car[+0x10]      ; pre-update X
 *   save car[+0x3C] = car[+0x18]      ; pre-update Z
 *   sin_val = FUN_06027344(slip)       ; sin
 *   cos_val = FUN_06027348(slip)       ; cos
 *   vel_x = (speed * cos_val) >> 16   ; xtrct
 *   car[+0x18C] = vel_x
 *   car[+0x10] += vel_x
 *   vel_z = (speed * sin_val) >> 16   ; xtrct
 *   car[+0x190] = vel_z
 *   car[+0x18] += vel_z
 * ────────────────────────────────────────────────────────────────────── */
void FUN_0602D8C6(int car)
{
    int speed, world_x, world_z, slip;
    int sin_val, cos_val;
    int vel_x, vel_z;

    /* Copy heading */
    *(int *)(car + 0x20) = *(int *)(car + 0x30);

    /* Negate slip angle */
    slip = -(*(int *)(car + 0x28));
    speed = *(int *)(car + 0x0C);
    world_x = *(int *)(car + 0x10);
    world_z = *(int *)(car + 0x18);

    /* Save pre-update position */
    *(int *)(car + 0x38) = world_x;
    *(int *)(car + 0x3C) = world_z;

    /* sin/cos of negated slip angle */
    sin_val = FUN_06027344(slip);
    cos_val = FUN_06027348(slip);

    /* Velocity X = (cos_val * speed) >> 16 via dmuls.l + xtrct */
    vel_x = fixed_mul(cos_val, speed);
    *(int *)(car + 0x18C) = vel_x;
    *(int *)(car + 0x10) = world_x + vel_x;

    /* Velocity Z = (sin_val * speed) >> 16 via dmuls.l + xtrct */
    vel_z = fixed_mul(sin_val, speed);
    *(int *)(car + 0x190) = vel_z;
    *(int *)(car + 0x18) = world_z + vel_z;
}

/* ──────────────────────────────────────────────────────────────────────
 * sym_0602D8BC — Position writer (drift check gate)
 *
 * Assembly:
 *   mov #0, r4
 *   mov.w .L_pool_D916, r1  ; r1 = 0x250
 *   mov.w @(r0, r1), r2     ; drift = car[+0x250] (short)
 *   cmp/eq r4, r2            ; if drift == 0
 *   bf external_0602D924     ; else branch to drift handler
 *   <fall through to FUN_0602D8C6>
 * ────────────────────────────────────────────────────────────────────── */
void sym_0602D8BC(int car)
{
    short drift;

    drift = *(short *)(car + 0x250);
    if (drift != 0) {
        /* bf to external drift handler — separate TU */
        FUN_0602D924(car);
        return;
    }
    FUN_0602D8C6(car);
}

/* ──────────────────────────────────────────────────────────────────────
 * sym_0602D88E + FUN_0602D89A — Player position update entry
 *
 * sym_0602D88E: pushes r8-r13 (callee-saved), falls into FUN_0602D89A
 * FUN_0602D89A: pushes r14+pr, loads car ptr from sym_0607E944,
 *               calls sym_0602D8BC, pops everything, returns.
 *
 * In C: one function (the prologue push is compiler-generated).
 * ────────────────────────────────────────────────────────────────────── */
void FUN_0602D89A(void)
{
    int car;

    car = *(int *)&sym_0607E944;
    sym_0602D8BC(car);
}

/* ──────────────────────────────────────────────────────────────────────
 * FUN_0602D43C — Collision + steering response (936 bytes)
 *
 * Computes heading correction from collision state, applies EMA smoothing.
 * Calls FUN_06027344 (atan2/sin), FUN_06027378 (atan2 variant),
 * sym_0602ECCC (fixed-point divide).
 *
 * Car struct offsets used (all resolved from DAT_ pool constants):
 *   +0x00  flags          +0x08  speed_index      +0x0C  speed
 *   +0x40  heading_rate   +0x58  smooth_heading   +0x5C  heading_corr
 *   +0x7F  collision_byte +0x7E  collision_byte2
 *   +0x0108 force_x       +0x010C force_z         +0x0140 force_mag_x
 *   +0x0144 force_mag_z   +0x0154 collision_val   +0x0166 counter
 *   +0x0168 counter_limit +0x0178 heading_delta    +0x00CC field_cc
 *   +0x00D4 drift_flag    +0x00FA field_fa
 * ────────────────────────────────────────────────────────────────────── */
void FUN_0602D43C(int car)
{
    int collision_val, counter_limit;
    int heading_rate, heading_corr;
    int speed_sq, atan_result;
    int force_product, force_scaled;
    int delta, clamp_val, temp;
    int r12_val;
    short counter;
    int angle_sign;
    int push_val;

    /* r10 = car[+0x154] (collision value) */
    collision_val = *(int *)(car + 0x154);
    counter_limit = 0x168;

    /* r7 = car[+0x166] (counter, sign-extended short) */
    counter = *(short *)(car + 0x166);

    /* if counter > 0, skip the collision check block */
    if (counter <= 0) {
        /* Collision gate: check speed, heading_rate, and threshold */
        if (*(int *)(car + 8) >= 0xF0 &&
            *(int *)(car + 0x40) != 0 &&
            *(int *)(car + 0x10C) <= 0x6800)
        {
            int abs_cv;
            abs_cv = collision_val;

            if (collision_val > 0x2F8) {
                /* abs_cv stays as-is */
            } else if (collision_val >= -0x2F8) {
                goto skip_counter_write;
            } else {
                abs_cv = -collision_val;
            }

            abs_cv = abs_cv - 0x2F8;

            /* Clamp to [4, 10] */
            if (abs_cv < 5) {
                abs_cv = 4;
            } else if (abs_cv > 10) {
                abs_cv = 10;
            }

            *(short *)(car + counter_limit) = (short)abs_cv;
        }
    }

skip_counter_write:
    /* Read counter back (might have been written above) */
    counter = *(short *)(car + counter_limit);

    if (counter > 0) {
        /* Decrement counter */
        if (*(int *)(car + 0x11C) == 0) {
            counter = counter - 2;
        }
        counter = counter - 1;
        *(short *)(car + counter_limit) = counter;

        push_val = 0;
        temp = 0x000A0000 - (counter * 0x10000);
        if (temp >= 0) {
            /* fixed_mul: car[+0x10C] * temp */
            force_product = fixed_mul(*(int *)(car + 0x10C), temp);

            /* Write to scratch area at 0xFF00 and compute atan2 */
            /* This is a local struct pattern — Ghidra shows writes to -256 */
            *(int *)(0xFF00) = 0x000A0000;
            *(int *)(0xFF10) = (short)(force_product >> 16);
            *(int *)(0xFF14) = force_product << 16;
            push_val = *(int *)(0xFF1C);
        }

        *(int *)(car + 0x10C) = push_val;
        FUN_0602D7E4(car);
    }

    /* atan2 of car[+0x5C] (heading rate component) */
    atan_result = FUN_06027344(*(int *)(car + 0x5C));

    /* Compute force_product: fixed_mul(car[+0x10C], car[+0x144]) */
    force_product = fixed_mul(*(int *)(car + 0x10C), *(int *)(car + 0x144));

    /* Second multiply: force_product * car[+0xCC] (shift variant) */
    {
        int mid;
        mid = fixed_mul(force_product, *(short *)(car + 0xCE));
        force_scaled = (mid >> 8) & 0x00FFFFFF;  /* shll8 mach; shlr16 macl; shlr8 macl; or */
    }

    /* Branch based on speed (car[+0x0C]) vs 0x100 */
    if (*(int *)(car + 0x0C) < 0x100) {
        /* Low speed: use fixed angle_sign */
        angle_sign = 0x4000;
        if ((int)force_scaled < 0) {
            angle_sign = -0x4000;
        }
        push_val = 0;
    } else {
        /* High speed: compute speed^2, then atan2 */
        int speed_val;
        speed_val = *(int *)(car + 0x0C);
        speed_sq = fixed_mul(speed_val, speed_val);
        push_val = speed_sq;

        /* Write speed_sq to scratch, compute atan2 */
        *(int *)(0xFF00) = speed_sq;
        *(int *)(0xFF10) = (short)(force_scaled >> 16);
        *(int *)(0xFF14) = force_scaled << 16;
        angle_sign = FUN_06027378(*(int *)(0xFF1C));

        if (angle_sign == 0) {
            angle_sign = *(char *)(car + 0x7F);
        }
    }

    /* Steering correction with counter check */
    if (*(short *)(car + 0x166) > 0 &&
        *(int *)(car + 8) < 0x46)
    {
        int hr, xor_val;
        hr = *(int *)(car + 0x40);
        xor_val = hr ^ *(int *)(car + 0x5C);
        if (xor_val < 0) {
            /* Signs differ — apply damping */
            int scaled_angle;
            scaled_angle = angle_sign << 16;
            temp = FUN_06027344((short)(hr >> 1) * 9);
            angle_sign = (short)(fixed_mul(scaled_angle, temp) >> 16);
            if (angle_sign < 0) {
                angle_sign = 0;
            }
        }
    }

    /* Compute delta from heading rate and collision */
    delta = angle_sign * 3;
    temp = -(*(int *)(car + 0x5C));

    if (temp < 0) {
        delta = angle_sign * -3;
        if (temp <= delta) goto use_delta;
    } else {
        if (delta <= temp) goto use_delta;
    }
    delta = temp;

use_delta:
    /* Subtract atan2-scaled collision contribution */
    temp = -delta;
    delta = collision_val - temp - *(int *)(car + 0x178);
    delta = delta + *(int *)(car + 0x178);

    /* Clamp to [-0x300, 0x300] */
    clamp_val = -0x300;
    if (delta > clamp_val) {
        clamp_val = delta;
        if (delta >= 0x300) {
            clamp_val = 0x300;
        }
    }
    *(int *)(car + 0x178) = clamp_val;

    /* EMA smoothing on car[+0x5C] */
    heading_corr = *(int *)(car + 0x5C);
    temp = clamp_val + heading_corr;
    *(int *)(car + 0x5C) = temp - (-(heading_corr - temp) >> 3);

    /* Second force computation: fixed_mul(car[+0x140], car[+0x108]) */
    force_product = fixed_mul(*(int *)(car + 0x140), *(int *)(car + 0x108));

    /* Multiply by car[+0xCC] field (shift variant) */
    {
        int mid;
        mid = fixed_mul(force_product, *(short *)(car + 0xCC));
        force_scaled = (mid >> 8) & 0x00FFFFFF;
    }

    if (push_val != 0) {
        /* speed_sq was nonzero — compute atan2 */
        *(int *)(0xFF00) = push_val;
        *(int *)(0xFF10) = (short)(force_scaled >> 16);
        *(int *)(0xFF14) = force_scaled << 16;
        angle_sign = FUN_06027378(*(int *)(0xFF1C));

        if (angle_sign == 0) {
            angle_sign = *(char *)(car + 0x7E);
        }
    } else {
        angle_sign = 0x4000;
    }

    /* Divide/scale step */
    {
        int speed_idx, fa_val;
        speed_idx = *(int *)(car + 8);
        fa_val = *(int *)(car + 0xFA);
        if (speed_idx > 0x32) {
            /* clamp */
        } else {
            speed_idx = 0x32;
        }
        if (fa_val > speed_idx) {
            /* already fine */
        } else {
            fa_val = speed_idx;
        }

        r12_val = sym_0602ECCC(fa_val - 0x32, (speed_idx - 0x32) << 8);
    }

    /* Apply angle_sign * r12_val scaling */
    {
        int heading_a, heading_b, diff, xor_val;
        heading_a = *(int *)(car + 0x40);
        heading_b = *(int *)(car + 0x5C);
        temp = heading_b;
        diff = heading_a - heading_b;
        push_val = r12_val;

        r12_val = (short)angle_sign * (short)((r12_val * 3 + 0x200) & 0xFFFF);
        r12_val = r12_val >> 8;

        xor_val = heading_a ^ diff;
        if (xor_val < 0) {
            /* Sign correction */
            int limit;
            limit = 0xFE0;
            if ((int)heading_a < 0) {
                limit = -0xFE0;
            }
            heading_a = heading_a - limit;
            heading_a = -heading_a;
            r12_val = sym_0602ECCC(limit, (heading_a * r12_val) & 0xFFFFFFFF);
        }

        /* Clamp and apply */
        if (diff >= 0) {
            if (r12_val > diff) goto apply_heading;
        } else {
            r12_val = -r12_val;
            if (diff > r12_val) goto apply_heading;
        }
        r12_val = diff;
    }

apply_heading:
    r12_val = r12_val << 8;
    {
        int val;
        val = sym_0602ECCC(push_val, r12_val);
        r12_val = val;
    }

    /* EMA smoothing on car[+0x58] */
    {
        int smooth;
        smooth = *(int *)(car + 0x58);
        temp = smooth - r12_val;
        temp = -(smooth - temp);
        *(int *)(car + 0x58) = temp - (-(smooth - temp) >> 3);
    }

    /* Speed gate: check car[+0x08] >= 0x41 */
    if (*(int *)(car + 8) > 0x41) {
        int hval;
        hval = *(int *)(car + 0x5C);
        if (hval <= (int)0xFFFFCD80) {
            /* Set collision flags */
            *(int *)(car) = *(int *)(car) | 0x10000000 | 0x40000000;
        } else if (hval >= -(int)0xFFFFCD80) {
            *(int *)(car) = *(int *)(car) | 0x20000000 | 0x40000000;
        }
    }

    /* Final clamp on car[+0x5C] to [-0xFFFFCC00, 0xFFFFCC00] */
    {
        int hval;
        hval = *(int *)(car + 0x5C);
        if (hval <= (int)0xFFFFCC00 || hval >= -(int)0xFFFFCC00) {
            *(short *)(car + 0xD4) = 1;
            if (hval <= (int)0xFFFFCC00) {
                hval = (int)0xFFFFCC00;
            } else {
                hval = -(int)0xFFFFCC00;
            }
        }
        *(int *)(car + 0x5C) = hval;
    }
}
