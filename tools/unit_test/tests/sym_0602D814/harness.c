/* Unit test harness for sym_0602D814 (speed writer)
 *
 * Tests both vanilla (assembly) and decomp (C) versions with identical
 * inputs, compares car struct outputs byte-for-byte.
 *
 * Test sweep:
 *   - 5 speed values: 0, 100, 0x10000, 0x100000, -1
 *   - 5 accel_delta values: 0, 70, -100, 0x10000, -0x10000
 *   - 4 gear indices: 0, 1, 2, 3
 *   = 100 test cases
 */

/* Results written to this address, read by MCP after test completes */
extern char _results_start;

typedef unsigned int uint;

/* Both versions have the same signature: void sym_0602D814(int car) */
extern void vanilla_sym_0602D814(int car);
extern void decomp_sym_0602D814(int car);

/* Gear ratio table — must match original game data */
extern char sym_060477BC;

/* Two car structs: one for vanilla, one for decomp */
extern char vanilla_car;
extern char decomp_car;

/* Results structure */
struct results {
    uint magic;           /* 0=not started, 0xFEEDFACE=running, 0xDEADBEEF=done */
    uint total;
    uint passed;
    uint failed;
    int  first_fail_test; /* -1 if all pass */
    int  first_fail_off;  /* byte offset of first mismatch */
    uint first_fail_van;  /* vanilla value */
    uint first_fail_dec;  /* decomp value */
};

/* Car struct offsets used by sym_0602D814 */
#define OFF_SPEED     0x0C
#define OFF_GEAR      0xDC
#define OFF_ACCEL     0xFC
#define OFF_GSCALED   0xE0
#define OFF_EXCESS    0xE8
#define CAR_SIZE      0x268

static int speeds[] = { 0, 100, 0x10000, 0x100000, -1 };
static int accels[] = { 0, 70, -100, 0x10000, -0x10000 };
static short gears[] = { 0, 1, 2, 3 };

static void zero_car(char *car)
{
    int i;
    for (i = 0; i < CAR_SIZE; i++) {
        car[i] = 0;
    }
}

static void setup_car(char *car, int speed, int accel, short gear)
{
    zero_car(car);
    *(int *)(car + OFF_SPEED) = speed;
    *(int *)(car + OFF_ACCEL) = accel;
    *(short *)(car + OFF_GEAR) = gear;
}

static int compare_cars(char *van, char *dec, int *fail_offset)
{
    int i;
    for (i = 0; i < CAR_SIZE; i += 4) {
        if (*(uint *)(van + i) != *(uint *)(dec + i)) {
            *fail_offset = i;
            return 0;
        }
    }
    return 1;
}

void run_tests(void)
{
    struct results *res;
    int si, ai, gi, test_num;
    int fail_off;

    res = (struct results *)&_results_start;
    res->magic = 0xFEEDFACE;
    res->total = 0;
    res->passed = 0;
    res->failed = 0;
    res->first_fail_test = -1;

    test_num = 0;
    for (si = 0; si < 5; si++) {
        for (ai = 0; ai < 5; ai++) {
            for (gi = 0; gi < 4; gi++) {
                /* Setup identical state */
                setup_car(&vanilla_car, speeds[si], accels[ai], gears[gi]);
                setup_car(&decomp_car, speeds[si], accels[ai], gears[gi]);

                /* Call both versions */
                vanilla_sym_0602D814((int)&vanilla_car);
                decomp_sym_0602D814((int)&decomp_car);

                /* Compare */
                res->total++;
                if (compare_cars(&vanilla_car, &decomp_car, &fail_off)) {
                    res->passed++;
                } else {
                    res->failed++;
                    if (res->first_fail_test == -1) {
                        res->first_fail_test = test_num;
                        res->first_fail_off = fail_off;
                        res->first_fail_van = *(uint *)(&vanilla_car + fail_off);
                        res->first_fail_dec = *(uint *)(&decomp_car + fail_off);
                    }
                }
                test_num++;
            }
        }
    }

    res->magic = 0xDEADBEEF;
}
