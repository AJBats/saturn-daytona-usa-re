/* vtable_dispatch.c -- Virtual function table dispatchers
 *
 * These functions call method N from an object's vtable.
 * Object layout: [0]=self_ptr, [1]=?, [2]=method0, [3]=method1, ...
 * Each calls param_1[N](param_1[0]).
 *
 * FUN_0603F8EE: call method at index 2
 * FUN_0603F900: call method at index 3
 * FUN_0603F90E: call method at index 4
 * FUN_0603F91C: call method at index 5
 *
 * Original addresses: 0x0603F8EE, 0x0603F900, 0x0603F90E, 0x0603F91C
 */

void FUN_0603F8EE(int *param_1)
{
    (*(void (*)(int))param_1[2])(*param_1);
}

void FUN_0603F900(int *param_1)
{
    (*(void (*)(int))param_1[3])(*param_1);
}

void FUN_0603F90E(int *param_1)
{
    (*(void (*)(int))param_1[4])(*param_1);
}

void FUN_0603F91C(int *param_1)
{
    (*(void (*)(int))param_1[5])(*param_1);
}
