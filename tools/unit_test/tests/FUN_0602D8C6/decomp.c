/* Decomp version of FUN_0602D8C6 for unit testing. */

typedef unsigned int uint;

extern int FUN_06027344();   /* sin stub */
extern int FUN_06027348();   /* cos stub */

static __inline__ int fixed_mul(int a, int b)
{
    int hi, lo;
    asm("dmuls.l %2,%3\n\tsts mach,%0\n\tsts macl,%1"
        : "=r"(hi), "=r"(lo) : "r"(a), "r"(b));
    return (hi << 16) | ((uint)lo >> 16);
}

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

    /* Velocity X = (cos * speed) >> 16 via dmuls + xtrct */
    vel_x = fixed_mul(cos_val, speed);
    *(int *)(car + 0x18C) = vel_x;
    *(int *)(car + 0x10) = world_x + vel_x;

    /* Velocity Z = (sin * speed) >> 16 via dmuls + xtrct */
    vel_z = fixed_mul(sin_val, speed);
    *(int *)(car + 0x190) = vel_z;
    *(int *)(car + 0x18) = world_z + vel_z;
}
