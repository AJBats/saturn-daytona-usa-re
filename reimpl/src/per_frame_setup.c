#include "saturn.h"
#include "game.h"

extern int cd_status_read(void);
extern void cd_register_double_read(char *buf);
extern void cd_frame_sync_advance(void);
extern void sound_channels_reset(void);
extern void FUN_0600A1B8(void);
extern void FUN_06020BCE(void);

#define BIOS_SERVICE_026C   (*(void (**)())0x0600026C)
#define FRAME_SYNC_STATE    (*(volatile char *)0x0607864A)
#define FRAME_SYNC_VALUE    (*(volatile char *)0x06078649)
#define STATUS_WORD_BASE    ((volatile unsigned short *)0x06063D98)

#if 0 /* per_frame_setup -- redirected to ASM import via linker PROVIDE */
void per_frame_setup(void)
{
    int cd_status;
    int cd_nibble;

    cd_status = cd_status_read();
    cd_nibble = cd_status & 0x0F;

    if (cd_nibble == 6) {
        BIOS_SERVICE_026C();
    }

    if (FRAME_SYNC_STATE == 0) {
        char buf[12];
        cd_register_double_read(buf);
        {
            unsigned char val = (unsigned char)buf[6];
            if (val < 100) {
                FRAME_SYNC_VALUE = (char)val;
            }
        }
    } else if (FRAME_SYNC_STATE == 1) {
        if (cd_nibble == 1) {
            cd_frame_sync_advance();
            FRAME_SYNC_STATE = 2;
        }
    }

    {
        unsigned short status_hi = STATUS_WORD_BASE[1];
        if (status_hi & 0x0800) {
            unsigned short status_lo = STATUS_WORD_BASE[0];
            if ((status_lo & 0x0700) == 0x0700) {
                sound_channels_reset();
                if ((unsigned int)GAME_STATE >= 6) {
                    FUN_0600A1B8();
                    if (GAME_STATE == 23) {
                        FUN_06020BCE();
                    }
                    GAME_STATE = 0;
                } else {
                    BIOS_SERVICE_026C();
                }
            }
        }
    }
}
#endif /* per_frame_setup */
