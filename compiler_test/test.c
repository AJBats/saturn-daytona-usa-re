/* Compiler codegen test for SH-2 pattern comparison.
 * Compile with: GCC.EXE -S -O2 -m2 -fsigned-char TEST.C -o TEST_O2.S
 * Compare output assembly against Daytona USA binary patterns in Ghidra.
 */

/* Simple arithmetic - basic codegen, leaf function */
int add_values(int a, int b, int c) {
    return a + b + c;
}

/* Local variables + loop - register allocation, prologue/epilogue */
int sum_array(int *arr, int count) {
    int total = 0;
    int i;
    for (i = 0; i < count; i++) {
        total += arr[i];
    }
    return total;
}

/* Multiple calls - pr save, call convention */
extern int external_func(int x);

int call_chain(int a, int b) {
    int x = external_func(a);
    int y = external_func(b);
    return x + y;
}

/* Pointer/memory access - load/store patterns */
void write_hw_reg(volatile unsigned int *reg, unsigned int val) {
    *reg = val;
}

unsigned int read_hw_reg(volatile unsigned int *reg) {
    return *reg;
}

/* Struct access - common game pattern */
typedef struct {
    int x, y, z;
    int speed;
    int angle;
} GameObj;

void update_position(GameObj *obj) {
    obj->x += obj->speed;
    obj->y += obj->speed;
}

/* Conditional logic - branch patterns */
int clamp(int val, int min, int max) {
    if (val < min) return min;
    if (val > max) return max;
    return val;
}

/* Switch statement - jump table vs branches */
int handle_state(int state, int input) {
    switch (state) {
        case 0: return input + 1;
        case 1: return input - 1;
        case 2: return input * 2;
        case 3: return input >> 1;
        default: return 0;
    }
}
