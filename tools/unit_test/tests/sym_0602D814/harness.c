/* Unit test harness for sym_0602D814 (speed writer)
 *
 * Calls sym_0602D814 with various inputs, captures ENTIRE car struct.
 * Built twice: once linked with vanilla .s, once with decomp .c.
 * Compare full output dumps byte-for-byte between both discs.
 *
 * Input vectors:
 *   - car[+0x0C] speed, car[+0xFC] accel_delta, car[+0xDC] gear_idx
 *   - sym_060477BC gear ratio table (global, shared)
 *   - All other car fields pre-filled with canary pattern (0xA5)
 *     to catch stray reads from wrong offsets
 *
 * Output capture: full car struct snapshot (0x268 bytes per test)
 *   - Catches writes to wrong offsets
 *   - Catches stray writes from register spills
 */

extern char _results_start;

typedef unsigned int uint;
typedef unsigned short ushort;

extern void sym_0602D814(int car);
extern char sym_060477BC;
extern char test_car;

#define OFF_SPEED     0x0C
#define OFF_GEAR      0xDC
#define OFF_ACCEL     0xFC
#define CAR_SIZE      0x268

/* Results header */
struct results {
    uint magic;      /* 0xDEADBEEF when done */
    uint total;
    /* Followed by: uint hash[total] — one 32-bit hash per test */
};

/* Test inputs — expanded for better coverage */
static int speeds[] = {
    0,              /* zero */
    1,              /* minimal positive */
    100,            /* small positive */
    0x10000,        /* medium (64K) */
    0x100000,       /* large (1M) — pushes gear_scaled past clamp */
    0x7FFFFFFF,     /* INT_MAX — overflow when accel added */
    -1,             /* minimal negative — immediate clamp */
    -0x100000       /* large negative — clamp */
};

static int accels[] = {
    0,              /* no change */
    1,              /* minimal positive */
    70,             /* typical gameplay value */
    -100,           /* braking */
    0x10000,        /* large positive */
    -0x10000,       /* large negative */
    0x7FFFFFFF      /* huge — overflow with positive speed */
};

static short gears[] = { 0, 1, 2, 3 };

/* Fill car with canary pattern, then set inputs */
static void setup_car(char *car, int speed, int accel, short gear)
{
    int i;
    /* Canary fill: 0xA5 pattern catches stray reads from wrong offsets */
    for (i = 0; i < CAR_SIZE; i++) {
        car[i] = (char)0xA5;
    }
    /* Set known inputs */
    *(int *)(car + OFF_SPEED) = speed;
    *(int *)(car + OFF_ACCEL) = accel;
    *(short *)(car + OFF_GEAR) = gear;
}

/* Hash the full car struct into a 32-bit value for compact storage.
 * We compare hashes between vanilla and decomp — any byte difference
 * in the entire 0x268-byte struct produces a different hash. */
static uint hash_car(char *car)
{
    uint h;
    int i;
    h = 0x811C9DC5;  /* FNV-1a offset basis */
    for (i = 0; i < CAR_SIZE; i++) {
        h = h ^ (unsigned char)car[i];
        h = h * 0x01000193;  /* FNV prime */
    }
    return h;
}

void run_tests(void)
{
    struct results *res;
    uint *hashes;
    char *car;
    int si, ai, gi, test_num;
    int n_speeds, n_accels, n_gears;

    res = (struct results *)&_results_start;
    res->magic = 0xFEEDFACE;
    res->total = 0;
    hashes = (uint *)((char *)res + 8);
    car = &test_car;
    test_num = 0;

    n_speeds = 8;
    n_accels = 7;
    n_gears = 4;

    for (si = 0; si < n_speeds; si++) {
        for (ai = 0; ai < n_accels; ai++) {
            for (gi = 0; gi < n_gears; gi++) {
                setup_car(car, speeds[si], accels[ai], gears[gi]);

                sym_0602D814((int)car);

                /* Hash full car struct — catches any byte difference */
                hashes[test_num] = hash_car(car);
                test_num++;
            }
        }
    }

    res->total = test_num;
    res->magic = 0xDEADBEEF;
}
