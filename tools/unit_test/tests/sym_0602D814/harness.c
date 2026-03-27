/* Unit test harness for sym_0602D814 (speed writer)
 *
 * Calls sym_0602D814 with various inputs, records all output fields.
 * Built twice: once linked with vanilla .s, once with decomp .c.
 * Compare results from both discs byte-for-byte.
 *
 * Test sweep: 5 speeds x 5 accel_deltas x 4 gears = 100 tests
 */

extern char _results_start;

typedef unsigned int uint;

/* The function under test — same symbol, different implementation per disc */
extern void sym_0602D814(int car);

/* Gear ratio table */
extern char sym_060477BC;

/* Car struct in BSS */
extern char test_car;

#define OFF_SPEED     0x0C
#define OFF_GEAR      0xDC
#define OFF_ACCEL     0xFC
#define OFF_GSCALED   0xE0
#define OFF_EXCESS    0xE8
#define CAR_SIZE      0x268

struct results {
    uint magic;      /* 0xDEADBEEF when done */
    uint total;
    /* Followed by output snapshots: 5 fields x 4 bytes x 100 tests = 2000 bytes */
};

/* Output fields we capture per test */
struct test_output {
    int speed;       /* car[+0x0C] after call */
    int accel;       /* car[+0xFC] after call */
    int gscaled;     /* car[+0xE0] */
    int excess;      /* car[+0xE8] */
};

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

void run_tests(void)
{
    struct results *res;
    struct test_output *out;
    char *car;
    int si, ai, gi, test_num;

    res = (struct results *)&_results_start;
    res->magic = 0xFEEDFACE;
    res->total = 0;
    out = (struct test_output *)((char *)res + 8);
    car = &test_car;
    test_num = 0;

    for (si = 0; si < 5; si++) {
        for (ai = 0; ai < 5; ai++) {
            for (gi = 0; gi < 4; gi++) {
                /* Setup */
                zero_car(car);
                *(int *)(car + OFF_SPEED) = speeds[si];
                *(int *)(car + OFF_ACCEL) = accels[ai];
                *(short *)(car + OFF_GEAR) = gears[gi];

                /* Call function under test */
                sym_0602D814((int)car);

                /* Capture outputs */
                out[test_num].speed = *(int *)(car + OFF_SPEED);
                out[test_num].accel = *(int *)(car + OFF_ACCEL);
                out[test_num].gscaled = *(int *)(car + OFF_GSCALED);
                out[test_num].excess = *(int *)(car + OFF_EXCESS);

                test_num++;
            }
        }
    }

    res->total = test_num;
    res->magic = 0xDEADBEEF;
}
