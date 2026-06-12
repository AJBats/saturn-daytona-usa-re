/* Unit test harness for FUN_0602D8C6 (position writer core)
 *
 * Sweeps: speed, slip_angle, world position.
 * External calls (sin/cos) use shared stubs — same for both builds.
 * Full car struct hash with canary pattern.
 *
 * Input vectors:
 *   - car[+0x0C] speed
 *   - car[+0x28] slip_angle
 *   - car[+0x10] world_x, car[+0x18] world_z
 *   - car[+0x30] heading_copy
 *   - FUN_06027344 return (sin stub), FUN_06027348 return (cos stub)
 */

extern char _results_start;

typedef unsigned int uint;

extern void FUN_0602D8C6(int car);
extern char test_car;

#define CAR_SIZE 0x268

struct results {
    uint magic;
    uint total;
};

static int speeds[] = { 0, 0x10000, 0x100000, -1 };
static int slip_angles[] = { 0, 0x4000, -0x4000, 0x7FFFFFFF };
static int positions[] = { 0, 0x10000 };
static int headings[] = { 0, 0x4000 };

static void setup_car(char *car, int speed, int slip, int wx, int wz, int heading)
{
    int i;
    int *p;
    /* Word-level canary fill (0xA5A5A5A5) — much faster than byte loop */
    p = (int *)car;
    for (i = 0; i < CAR_SIZE / 4; i++) {
        p[i] = (int)0xA5A5A5A5;
    }
    *(int *)(car + 0x0C) = speed;
    *(int *)(car + 0x28) = slip;
    *(int *)(car + 0x10) = wx;
    *(int *)(car + 0x18) = wz;
    *(int *)(car + 0x30) = heading;
}

static uint hash_car(char *car)
{
    /* XOR-rotate hash — no multiply, fast on SH-2.
     * Rotate-left by 5 + XOR gives decent avalanche. */
    uint h;
    int i;
    int *p;
    h = 0;
    p = (int *)car;
    for (i = 0; i < CAR_SIZE / 4; i++) {
        h = (h << 5) | (h >> 27);  /* rotate left 5 */
        h = h ^ (uint)p[i];
    }
    return h;
}

void run_tests(void)
{
    struct results *res;
    uint *hashes;
    char *car;
    int si, ai, pi, hi, test_num;
    int n_speeds, n_slips, n_pos, n_head;

    res = (struct results *)&_results_start;
    res->magic = 0xFEEDFACE;
    res->total = 0;
    hashes = (uint *)((char *)res + 8);
    car = &test_car;
    test_num = 0;

    n_speeds = 4;
    n_slips = 4;
    n_pos = 2;
    n_head = 2;

    for (si = 0; si < n_speeds; si++) {
        for (ai = 0; ai < n_slips; ai++) {
            for (pi = 0; pi < n_pos; pi++) {
                for (hi = 0; hi < n_head; hi++) {
                    setup_car(car, speeds[si], slip_angles[ai],
                              positions[pi], positions[pi], headings[hi]);

                    FUN_0602D8C6((int)car);

                    hashes[test_num] = hash_car(car);
                    test_num++;
                }
            }
        }
    }

    res->total = test_num;
    res->magic = 0xDEADBEEF;
}
