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
    if (counter > 3) {
        *(short *)(car + 0x166) = counter - 3;
    } else if (counter != 0) {
        *(short *)(car + 0x166) = 10;
    }
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
        /* drift handler at 0x0602D924 — external, not in this TU */
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
 * FUN_0602D43C — Collision + steering response
 *
 * 563-byte function with complex collision/heading correction logic.
 * Calls FUN_06027344, FUN_06027378 (trig), sym_0602ECCC (divide).
 *
 * Deferred — will decompile after speed/position writers are validated.
 * For now, this is a stub that does nothing.
 * ────────────────────────────────────────────────────────────────────── */
void FUN_0602D43C(int car)
{
    /* TODO: Full decompilation — 563 bytes, complex branching.
     * Pool constants resolved. Assembly cross-referenced.
     * Defer until unit tests validate sym_0602D814 + FUN_0602D8C6.
     */
}
