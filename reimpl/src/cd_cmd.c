/* cd_cmd.c -- CD block command interface
 *
 * CD block command registers are at 0x25890000+.
 * CR1-CR4 (0x25890018/1C/20/24) are used to send commands to the CD controller.
 *
 * FUN_06035E3C: Write 4 command words (CR1-CR4) to CD block
 * FUN_06035E5E: Read 4 response words from CD block
 * FUN_06034C48: Initialize CD command buffer, set command byte, execute
 * FUN_060349B6: Call FUN_06035F04 (CD block command), return 0
 * FUN_06035D22: Wrapper around FUN_06035D5A (CD status read)
 * FUN_06035C08: Wrapper around FUN_06035FEC (CD data transfer)
 *
 * Original addresses: 0x06035E3C, 0x06035E5E, 0x06034C48, 0x060349B6,
 *   0x06035D22, 0x06035C08
 */

extern void FUN_06035F04(void);
extern int FUN_06035D5A(void);
extern int FUN_06035FEC(int, int);

void FUN_06035E3C(short *param_1)
{
    *(volatile short *)0x25890018 = *param_1;
    *(volatile short *)0x2589001C = param_1[1];
    *(volatile short *)0x25890020 = param_1[2];
    *(volatile short *)0x25890024 = param_1[3];
}

void FUN_06035E5E(short *param_1)
{
    short r0;

    r0 = *(volatile short *)0x25890018;
    *param_1 = r0;

    r0 = *(volatile short *)0x2589001C;
    param_1[1] = r0;

    r0 = *(volatile short *)0x25890020;
    param_1[2] = r0;

    r0 = *(volatile short *)0x25890024;
    param_1[3] = r0;
}

void FUN_06034C48(void)
{
    char local_c[12];
    (*(void (*)(char *))0x06035E90)(local_c);
    local_c[0] = 5;
    (*(void (*)(int, char *))0x06035EC8)(0, local_c);
}

int FUN_060349B6(void)
{
    FUN_06035F04();
    return 0;
}

int FUN_06035D22(void)
{
    return FUN_06035D5A();
}

int FUN_06035C08(int param1, int param2)
{
    return FUN_06035FEC(param1, param2);
}
