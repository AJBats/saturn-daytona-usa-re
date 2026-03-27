/* Decomp version of sym_0602D814 for unit testing.
 * Renamed to decomp_sym_0602D814 to avoid symbol conflict with vanilla.
 * Contains only the speed writer function and its dependencies.
 */

typedef unsigned int uint;

extern char sym_060477BC;    /* gear ratio table */

static __inline__ int fixed_mul(int a, int b)
{
    int hi, lo;
    asm("dmuls.l %2,%3\n\tsts mach,%0\n\tsts macl,%1"
        : "=r"(hi), "=r"(lo) : "r"(a), "r"(b));
    return (hi << 16) | ((uint)lo >> 16);
}

void decomp_sym_0602D814(int car)
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

    /* Step 2: gear-scaled speed */
    speed = *(int *)(car + 0x0C);
    gear_idx = *(short *)(car + 0xDC);
    gear_ratio = *(int *)((int)&sym_060477BC + (gear_idx << 2));

    mid32 = fixed_mul(speed, gear_ratio);
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

    /* Excess */
    excess = scaled - clamped;
    if (excess < 0) excess = 0;
    *(int *)(car + 0xE8) = excess;
}
