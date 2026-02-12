#include "saturn.h"
#include "game.h"

#define RACE_PHASE_FLAG       (*(volatile unsigned char *)0x06078635)
#define RACE_CAR_COUNT_BYTE   (*(volatile unsigned char *)0x06078634)
#define RACE_TIMER            (*(volatile int *)0x0607ED88)
#define RACE_INIT_FLAG        (*(volatile unsigned short *)0x0607ED8C)
#define RACE_BTN_CHECK_WORD   (*(volatile unsigned short *)0x0607865E)
#define RACE_BACK_TO_TITLE    (*(volatile int *)0x0605AD08)
#define RACE_MENU_OVERLAY     (*(volatile unsigned char *)0x0605AB18)
#define RACE_HELD_BUTTONS     (*(volatile unsigned short *)0x06063D98)
#define RACE_NEW_BUTTONS      (*(volatile unsigned short *)0x06063D9A)
#define RACE_BTN_EVENT_ID     (*(volatile unsigned char *)0x06078648)
#define RACE_BTN_MASK_0       (*(volatile unsigned short *)0x06078656)
#define RACE_BTN_MASK_1       (*(volatile unsigned short *)0x06078658)
#define RACE_BTN_MASK_2       (*(volatile unsigned short *)0x0607865A)
#define RACE_BTN_MASK_3       (*(volatile unsigned short *)0x0607865C)
#define RACE_FIELD_662        (*(volatile unsigned char *)0x06078662)
#define RACE_POST_UPDATE_ARG  (*(volatile unsigned char *)0x0607ED91)
#define RACE_COUNTDOWN        (*(volatile int *)0x0607EBCC)
#define RACE_COUNTDOWN_17     (*(volatile int *)0x0607EAAC)
#define RACE_RESUME_STATE     (*(volatile int *)0x0607EACC)
#define RACE_END_FLAG         (*(volatile int *)0x0607EAD0)
#define RACE_CAR_OBJ_PTR     (*(volatile int *)0x0607EAD8)
#define RACE_CURRENT_CAR      (*(volatile int *)0x0607E940)
#define RACE_TARGET_CAR       (*(volatile int *)0x0607E944)
#define RACE_DISPLAY_FLAGS    (*(volatile int *)0x0605B6D8)
#define RACE_VBL_OUT_FLAG     (*(volatile int *)0x06059F44)
#define RACE_PHASE_WORD       (*(volatile short *)0x0605A016)
#define RACE_MODE_BYTE        (*(volatile unsigned char *)0x0607864A)
#define RACE_FLAGS_WORD       (*(volatile int *)0x0607EBF4)
#define RACE_FRAME_COUNTER    (*(volatile int *)0x0607EBD0)
#define RACE_SOUND_TIMER      (*(volatile unsigned short *)0x06086054)
#define RACE_DISPLAY_MODE     (*(volatile unsigned char *)0x06078636)
#define RACE_EXT_EVENT        (*(volatile int *)0x0607EAE0)
#define RACE_SKIP_FLAG        (*(volatile unsigned char *)0x06085FF4)
#define RACE_RESULT           (*(volatile int *)0x06078638)
#define RACE_DIFFICULTY       (*(volatile unsigned char *)0x06078654)
#define RACE_DEBUG_FLAG       (*(volatile unsigned char *)0x06086030)
#define RACE_DEBUG_FLAG_2     (*(volatile unsigned char *)0x06083255)
#define RACE_MODE_FLAG        (*(volatile int *)0x0605A1C4)
#define RACE_DIFFICULTY_SAVED (*(volatile unsigned char *)0x06078652)
#define RACE_FRAME_WORD       (*(volatile unsigned short *)0x06078650)
#define RACE_SPEED_BYTE       (*(volatile unsigned char *)0x06078649)
#define RACE_RESULT_BYTE      (*(volatile unsigned char *)0x06078637)
#define RACE_DATA_SRC         (*(volatile int *)0x060786A4)
#define RACE_DATA_DST         (*(volatile int *)0x0607863C)
#define RACE_COURSE_SEL       (*(volatile int *)0x0605AD00)
#define RACE_COURSE_SEL2      (*(volatile int *)0x0605AD04)
#define RACE_OVERLAY_LO       (*(volatile unsigned char *)0x0605AB16)
#define RACE_OVERLAY_HI       (*(volatile unsigned char *)0x0605AB17)
#define RACE_UPDATE_MODE      (*(volatile unsigned char *)0x06083261)
#define RACE_PLAYER_MODE      (*(volatile int *)0x0607EAD8)
#define RACE_TRANSITION_WORD  (*(volatile unsigned short *)0x06087804)
#define RACE_RESOURCE_FLAG    (*(volatile unsigned char *)0x0605E0A2)
#define RACE_DISPLAY_BYTE     (*(volatile unsigned char *)0x0607864B)
#define RACE_MENU_OVERLAY_B   (*(volatile unsigned char *)0x0605AB18)
#define RACE_INIT_FLAG_W      (*(volatile unsigned short *)0x0607ED8C)

#define HUD_BASE_ADDR         0x0605AC9C
#define HUD_BASE_ADDR_2       0x0605ACC4
#define TEXT_TIME_EXT          0x060446CC
#define TEXT_SPEED_LABEL       0x060446E0
#define TEXT_DIFFICULTY         0x060446EC
#define TEXT_LINE_A            0x060446FC
#define TEXT_LINE_B            0x06044718
#define TEXT_LINE_C            0x0604472C

#define DISPLAY_ADDR_A        (*(volatile int *)0x06063E24)
#define DISPLAY_ADDR_B        0x06063EEC
#define DISPLAY_ADDR_C        0x06063EF8
#define CAR_ARRAY_ADDR        0x06078900
#define CAR_STRIDE            0x268
#define BTN_START              0x0800
#define VDP_COLOR_WHITE        0x0000F000
#define VDP_OVERLAY_ADDR       0x0605A1C8
#define COUNTDOWN_INIT_VALUE   150

extern void FUN_0600A0C0(void);
extern void FUN_06018A3C(void);
extern void FUN_0601F784(void);
extern void FUN_0600EB14(void);
extern void FUN_06010A5C(int arg);
extern void FUN_06033AAC(void);
extern void FUN_060321C0(void);
extern void FUN_060054EA(int arg);
extern void FUN_060120C8(void);
extern void background_layer_init(void);
#define FUN_06005788 background_layer_init
extern void FUN_0601E100(void);
extern void FUN_060268B0(int arg);
extern void FUN_06026CE0(void);
extern void FUN_060033E6(void);
extern void FUN_060302C6(void);
extern void FUN_0602EFF0(void);
extern void FUN_0602F0E8(void);
extern void FUN_0600DE54(void);
extern void FUN_0600C302(void);
extern void FUN_06034900(void);
extern void FUN_0602F7EA(void);
extern void FUN_06012198(void);
extern void FUN_060121A8(void);
extern void FUN_0600BB94(void);
extern void FUN_060053AC(int r4, int r5, int r6);
extern void FUN_060055BC(void);
extern void FUN_0600BFFC(void);
extern void FUN_060283E0(int r4, int r5, int r6, int r7);
extern void FUN_060078DC(void);
extern void FUN_0600A33C(void);
extern void sound_channels_stop(void);
extern void FUN_06018E70(void);
extern void FUN_0601DE50(void);
extern void FUN_0601DBB8(void);
extern void FUN_06033BC8(void);
extern void FUN_0600DE70(void);
extern void FUN_0600A914(void);
extern void FUN_0601D9B0(void);
extern void FUN_0601D5F4(int r4, int r5);
extern void FUN_0600A084(void);
extern void sound_channels_reset(void);
extern void FUN_060284AE(int r4, int r5, int r6, int r7);
extern void FUN_0602834A(int r4, int r5, int r6, int r7);
extern void FUN_0600A1B8(void);
extern void FUN_06018DDC(int arg);
extern void FUN_06014A04(void);
extern void FUN_060210F6(void);
extern void FUN_06014A42(void);
extern void FUN_0601DF88(void);
extern void FUN_0600DF66(void);
extern void FUN_06019058(void);
extern int *vdp_display_list_fill(int channel);
extern int *vdp2_pattern_table_clear(void);
extern void FUN_06014884(int r4, int r5, int r6);
extern void FUN_060032D4(void);
extern void FUN_0600A294(void);
extern void FUN_06033EA8(void);
extern void FUN_0601FD74(void);
extern void FUN_0600DE40(void);
extern void FUN_06014A74(void);
extern void FUN_06014D2C(void);
extern void FUN_060190B8(void);
extern void scene_objects_init(void);
extern void FUN_0601389E(void);
extern void FUN_0600DFD0(void);
extern void FUN_0600C218(void);
extern void FUN_0600E060(void);
extern int FUN_06028400(int r4, int r5, int r6, int r7);
extern int FUN_0601F8C0(void);
extern int FUN_0601F900(void);
extern void FUN_060149E0(void);


void state_14_handler(void)
{
    short buttons;
    unsigned short mask;

    FUN_0600A0C0();

    RACE_PHASE_FLAG = 0;
    RACE_CAR_COUNT_BYTE = 1;
    RACE_TIMER = 8;

    if ((unsigned short)RACE_BTN_CHECK_WORD == 0x8000
        && RACE_BACK_TO_TITLE == 0
        && RACE_MENU_OVERLAY == 0)
    {
        buttons = (short)RACE_HELD_BUTTONS;

        mask = RACE_BTN_MASK_0;
        if ((short)buttons & mask) {
            RACE_BTN_EVENT_ID = 0;
            goto pipeline;
        }

        mask = RACE_BTN_MASK_1;
        if ((short)buttons & mask) {
            RACE_BTN_EVENT_ID = 1;
            goto pipeline;
        }

        mask = RACE_BTN_MASK_2;
        if ((short)buttons & mask) {
            RACE_BTN_EVENT_ID = 2;
            goto pipeline;
        }

        mask = RACE_BTN_MASK_3;
        if ((short)buttons & mask) {
            RACE_BTN_EVENT_ID = 3;
        }
    }

pipeline:
    FUN_06018A3C();
    FUN_0601F784();

    RACE_FIELD_662 = 3;
    if (RACE_PHASE_FLAG == 0 && RACE_INIT_FLAG != 0) {
        RACE_FIELD_662 = 4;
    }

    FUN_0600EB14();
    FUN_06010A5C((unsigned char)RACE_POST_UPDATE_ARG);
    FUN_06033AAC();
    FUN_060321C0();

    RACE_COUNTDOWN = COUNTDOWN_INIT_VALUE;

    {
        int idx = RACE_CAR_OBJ_PTR;
        int table_entry = *(volatile int *)(0x0605E158 + (idx << 2));
        FUN_060054EA(table_entry);
    }

    FUN_060120C8();
    FUN_06005788();
    FUN_0601E100();

    if (RACE_MENU_OVERLAY != 0) {
        FUN_060268B0(1);
    }

    GAME_STATE = 15;
    RACE_DISPLAY_FLAGS |= 0x40000000;
    FUN_06026CE0();
    RACE_VBL_OUT_FLAG = 0;
    RACE_PHASE_WORD = 3;
    RACE_MODE_BYTE = 0;
}


void state_15_handler(void)
{
    int next_state = 16;
    int car_idx;
    int car1_addr = CAR_ARRAY_ADDR + CAR_STRIDE;

    if ((unsigned short)RACE_NEW_BUTTONS & BTN_START) {
        RACE_RESUME_STATE = 15;
        GAME_STATE = 18;
    }

    RACE_COUNTDOWN = RACE_COUNTDOWN - 1;

    if (RACE_MENU_OVERLAY != 0) {
        FUN_060268B0(0);
    }

    if (RACE_INIT_FLAG != 0) {
        FUN_060033E6();
    }

    for (car_idx = 0; (unsigned char)car_idx < RACE_CAR_COUNT_BYTE; car_idx++) {
        if (RACE_PHASE_FLAG != 0) {
            if ((unsigned char)car_idx == 0) {
                RACE_INIT_FLAG = 1;
                RACE_TARGET_CAR = car1_addr;
                RACE_CURRENT_CAR = car1_addr;
            } else {
                RACE_INIT_FLAG = 0;
                RACE_TARGET_CAR = CAR_ARRAY_ADDR;
                RACE_CURRENT_CAR = CAR_ARRAY_ADDR;
                RACE_TIMER -= 2;
            }
        }

        FUN_060302C6();
        FUN_0602EFF0();
        FUN_0602F0E8();
        FUN_0600DE54();

        if (RACE_CAR_OBJ_PTR != 0) {
            FUN_0600C302();
            if (RACE_COUNTDOWN == 0) {
                GAME_STATE = next_state;
            }
        } else {
            if (RACE_END_FLAG == 0) {
                GAME_STATE = next_state;
            }
        }
    }

    if (RACE_DEBUG_FLAG_2 != 0) {
        FUN_06034900();
    } else {
        FUN_0602F7EA();
    }

    FUN_06012198();

    if (RACE_DIFFICULTY == 1) {
        FUN_0600BB94();
        FUN_060053AC(DISPLAY_ADDR_C, DISPLAY_ADDR_B, DISPLAY_ADDR_A);
    } else {
        FUN_060055BC();
    }

    FUN_0600BFFC();

    if (RACE_DEBUG_FLAG != 0) {
        FUN_060283E0(8, 0x0082, VDP_COLOR_WHITE, VDP_OVERLAY_ADDR);
    }

    FUN_060078DC();
}


void state_16_handler(void)
{
    GAME_STATE = 17;

    if (RACE_CAR_OBJ_PTR != 0) {
        FUN_060121A8();
    } else {
        FUN_06012198();
    }

    RACE_PHASE_WORD = 4;
}


void state_17_handler(void)
{
    int car_obj;

    if ((unsigned short)RACE_NEW_BUTTONS & BTN_START) {
        RACE_RESUME_STATE = 17;
        GAME_STATE = 18;
    }

    FUN_0600A33C();

    if (RACE_SKIP_FLAG != 0)
        goto post_section;
    if (RACE_END_FLAG != 0)
        goto post_section;

    {
        int countdown = RACE_COUNTDOWN_17 - 1;
        RACE_COUNTDOWN_17 = countdown;
        if (countdown > 0)
            goto post_section;
    }

    sound_channels_stop();
    {
        int car_ptr = RACE_TARGET_CAR;
        int finish_pos = *(volatile int *)(car_ptr + CAR_FINISH_POS);
        RACE_RESULT = finish_pos;
    }
    GAME_STATE = 24;

post_section:
    {
        int flags = RACE_FLAGS_WORD;
        if (flags & 0x01) {
            RACE_FLAGS_WORD = flags & ~1;
            sound_channels_stop();
            GAME_STATE = 20;
            FUN_06018E70();
            goto section3;
        }
    }

    if (RACE_END_FLAG == 0) {
        RACE_FRAME_COUNTER = RACE_FRAME_COUNTER + 1;
    }

section3:
    if (RACE_SOUND_TIMER == 0) {
        if (RACE_COUNTDOWN_17 == 200) {
            FUN_0601D5F4(0, (int)0xAE1134FF);
            RACE_SOUND_TIMER = 40;
        }
    }

    if (RACE_DISPLAY_MODE != 0) {
        car_obj = RACE_CAR_OBJ_PTR;
        if (car_obj != 0) {
            FUN_060121A8();
        } else {
            FUN_06012198();
        }
    }

    if (RACE_EXT_EVENT != 0) {
        FUN_0601DE50();
        if (RACE_CAR_OBJ_PTR != 0) {
            FUN_0601DBB8();
        }
    }

    if (RACE_MENU_OVERLAY != 0) {
        FUN_060268B0(0);
    }

    if (RACE_MODE_FLAG == 1) {
        GAME_STATE = 28;
    }

    if (RACE_CAR_OBJ_PTR == 2) {
        FUN_06033BC8();
    }

    FUN_0600DE70();
    FUN_0600A914();
    FUN_0600BB94();
    FUN_060053AC(DISPLAY_ADDR_C, DISPLAY_ADDR_B, DISPLAY_ADDR_A);
    FUN_0601D9B0();
    FUN_0600BFFC();

    if (RACE_INIT_FLAG != 0) {
        FUN_060033E6();
    }

    if (RACE_DEBUG_FLAG != 0) {
        FUN_060283E0(8, 0x0082, VDP_COLOR_WHITE, VDP_OVERLAY_ADDR);
    }

    {
        int car_ptr = RACE_TARGET_CAR;
        int finish = *(volatile int *)(car_ptr + CAR_FINISH_POS);
        if (finish > 0) {
            FUN_0600A084();
        }
    }

    FUN_060078DC();
}


void state_18_handler(void)
{
    sound_channels_reset();

    GAME_STATE = 19;

    RACE_DIFFICULTY_SAVED = RACE_DIFFICULTY;
    RACE_DIFFICULTY = 0;
    RACE_FRAME_WORD = 0;

    FUN_060284AE(8, 0x051C, 0x0090, TEXT_TIME_EXT);

    FUN_060283E0(8, 0x061C, VDP_COLOR_WHITE, HUD_BASE_ADDR + 46);
    FUN_060283E0(8, 0x051C, VDP_COLOR_WHITE, HUD_BASE_ADDR + 47);

    RACE_DISPLAY_FLAGS |= 0x04;
    FUN_06026CE0();
    RACE_VBL_OUT_FLAG = 0;

    FUN_0601D5F4(0, (int)0xAE0004FF);
}


void state_19_handler(void)
{
    unsigned short new_btns;
    unsigned short held_btns;
    unsigned char speed;

    new_btns = RACE_NEW_BUTTONS;
    held_btns = RACE_HELD_BUTTONS;

    if (RACE_MENU_OVERLAY != 0) {
        FUN_060268B0(0);
    }

    if (RACE_MODE_BYTE != 0) {
        if (new_btns & 0x8000) {
            speed = RACE_SPEED_BYTE;
            if (speed < 99) {
                RACE_SPEED_BYTE = speed + 1;
            }
        } else if (new_btns & 0x4000) {
            speed = RACE_SPEED_BYTE;
            if (speed > 1) {
                RACE_SPEED_BYTE = speed - 1;
            }
        }
        FUN_0602834A(8, 0x0CB8, VDP_COLOR_WHITE, (unsigned char)RACE_SPEED_BYTE);
        FUN_060283E0(8, 0x0694, VDP_COLOR_WHITE, TEXT_SPEED_LABEL);
    }

    if ((new_btns & BTN_START) && RACE_FRAME_WORD >= 20 && RACE_MODE_BYTE != 1) {
        FUN_0601D5F4(0, (int)0xAE0004FF);

        FUN_060284AE(8, 0x0526, VDP_COLOR_WHITE - 0x1000, HUD_BASE_ADDR + 59);
        FUN_060284AE(8, 0x079C, VDP_COLOR_WHITE - 0x1000, HUD_BASE_ADDR + 40);
        FUN_060284AE(8, 0x0CCC, VDP_COLOR_WHITE - 0x1000, HUD_BASE_ADDR + 46);

        GAME_STATE = RACE_RESUME_STATE;
        RACE_DIFFICULTY = RACE_DIFFICULTY_SAVED;

        if (RACE_MODE_BYTE != 0) {
            RACE_MODE_BYTE = 0;
            speed = RACE_SPEED_BYTE;
            FUN_06018DDC((int)speed);
            FUN_060283E0(8, 0x0694, VDP_COLOR_WHITE, TEXT_DIFFICULTY);
        }
        goto common_end;
    }

    if (((unsigned short)held_btns & 0x70) == 0x70) {
        FUN_0600A1B8();
        RACE_DISPLAY_FLAGS |= (int)0x80000000;

        if (RACE_INIT_FLAG != 0) {
            RACE_FLAGS_WORD = 1;
            RACE_INIT_FLAG = 2;
            GAME_STATE = 24;
            FUN_06026CE0();
            RACE_VBL_OUT_FLAG = 0;
        } else {
            RACE_BACK_TO_TITLE = 1;
            GAME_STATE = 14;
        }
        goto common_end;
    }

    {
        unsigned short counter = RACE_FRAME_WORD + 1;
        RACE_FRAME_WORD = counter;

        if (counter & 0x10) {
            FUN_060284AE(8, 0x079C, VDP_COLOR_WHITE - 0x1000, HUD_BASE_ADDR_2);
            FUN_060284AE(8, 0x0CCC, VDP_COLOR_WHITE - 0x1000, HUD_BASE_ADDR_2);
        } else {
            if (RACE_INIT_FLAG != 0) {
                FUN_060284AE(8, 0x079C, VDP_COLOR_WHITE - 0x1000, TEXT_LINE_A);
                FUN_060284AE(8, 0x0CCC, VDP_COLOR_WHITE - 0x1000, TEXT_LINE_B);
            } else {
                FUN_060284AE(8, 0x079C, VDP_COLOR_WHITE - 0x1000, TEXT_LINE_A);
                FUN_060284AE(8, 0x0CCC, VDP_COLOR_WHITE - 0x1000, TEXT_LINE_C);
            }
        }
    }

common_end:
    if (RACE_INIT_FLAG != 0) {
        FUN_060033E6();
    }

    if (RACE_DEBUG_FLAG != 0) {
        FUN_060283E0(8, 0x0082, VDP_COLOR_WHITE, VDP_OVERLAY_ADDR);
    }

    RACE_DISPLAY_FLAGS |= 0x04;
    FUN_06026CE0();
    RACE_VBL_OUT_FLAG = 0;
}


void state_20_handler(void)
{
    int car_obj;
    int player_mode;

    car_obj = RACE_TARGET_CAR;

    FUN_06014A04();
    FUN_060210F6();
    sound_channels_reset();

    {
        int event = (unsigned char)RACE_BTN_EVENT_ID;
        FUN_06018DDC(event + 10);
    }

    {
        int car = RACE_TARGET_CAR;
        int finish = *(volatile int *)(car + CAR_FINISH_POS);
        RACE_RESULT_BYTE = (unsigned char)finish;
        car = RACE_TARGET_CAR;
        *(volatile int *)&RACE_RESULT = *(volatile int *)(car + CAR_RACE_RESULT);
    }

    RACE_DATA_DST = RACE_DATA_SRC;

    if (RACE_DEBUG_FLAG_2 != 0 && RACE_COURSE_SEL > 1
        && RACE_RESULT_BYTE == 0 && RACE_EXT_EVENT == 0)
    {
        unsigned char flags = RACE_OVERLAY_HI;
        RACE_OVERLAY_HI = flags | 0x08;
    }

    if (RACE_SKIP_FLAG != 0 && RACE_COURSE_SEL2 > 1
        && RACE_EXT_EVENT == 0)
    {
        if (RACE_RESULT_BYTE < 3) {
            player_mode = RACE_PLAYER_MODE;
            if (player_mode == 0) {
                RACE_OVERLAY_LO |= 1;
            } else if (player_mode == 1) {
                RACE_OVERLAY_LO |= 2;
            } else if (player_mode == 2) {
                RACE_OVERLAY_LO |= 4;
            }
        }

        if (RACE_RESULT_BYTE == 0) {
            player_mode = RACE_PLAYER_MODE;
            if (player_mode == 0) {
                RACE_OVERLAY_HI |= 1;
            } else if (player_mode == 1) {
                RACE_OVERLAY_HI |= 2;
            } else if (player_mode == 2) {
                RACE_OVERLAY_HI |= 4;
            }
        }
    }

    FUN_0600A1B8();

    {
        unsigned char car_flags = *(volatile unsigned char *)(car_obj + 3);
        if (car_flags & 0x08) {
            RACE_UPDATE_MODE = 2;
        } else {
            player_mode = RACE_PLAYER_MODE;
            if (player_mode == 0) {
                int z = *(volatile int *)(car_obj + 0x18);
                if (z >= (int)0xFFB80000) {
                    RACE_UPDATE_MODE = 1;
                } else {
                    RACE_UPDATE_MODE = 0;
                }
            } else if (player_mode == 1) {
                int x = *(volatile int *)(car_obj + 0x10);
                if (x > (int)0xFEC60000) {
                    RACE_UPDATE_MODE = 0;
                } else {
                    RACE_UPDATE_MODE = 1;
                }
            } else if (player_mode == 2) {
                RACE_UPDATE_MODE = 0;
            }
        }
    }

    *(volatile int *)(RACE_TARGET_CAR + CAR_FIELD_40) = 0;

    GAME_STATE = 21;
    RACE_COUNTDOWN = 86;
    RACE_DIFFICULTY = 4;
    RACE_PHASE_WORD = 4;
}


void state_21_handler(void)
{
    FUN_06014A42();

    if (RACE_EXT_EVENT != 0) {
        FUN_0601DF88();
        if (RACE_PLAYER_MODE != 0) {
            FUN_0601DBB8();
        }
    }

    FUN_0600DF66();
    FUN_0600A914();
    FUN_0600BB94();
    FUN_060053AC(DISPLAY_ADDR_C, DISPLAY_ADDR_B, DISPLAY_ADDR_A);
    FUN_0600BFFC();

    if (RACE_INIT_FLAG != 0) {
        FUN_060033E6();
    }

    {
        int car_ptr = RACE_TARGET_CAR;
        int finish = *(volatile int *)(car_ptr + CAR_FINISH_POS);
        if (finish > 0) {
            FUN_0600A084();
        }
    }

    FUN_060078DC();
}


void state_22_handler(void)
{
    FUN_06019058();

    vdp_display_list_fill(4);
    vdp_display_list_fill(8);
    vdp_display_list_fill(12);
    vdp2_pattern_table_clear();

    FUN_06014884(8, 0, 0);
    FUN_06014884(16, 0, 0);
    FUN_06014884(32, 0, 0);

    FUN_060032D4();

    RACE_COUNTDOWN = 1000;
    GAME_STATE = 23;
    RACE_TRANSITION_WORD = 0;

    FUN_0600EB14();
    FUN_06033AAC();

    RACE_PHASE_WORD = 4;

    {
        int event = (unsigned char)RACE_BTN_EVENT_ID;
        FUN_06018DDC(event + 14);
    }
}


void state_23_handler(void)
{
    FUN_0600A294();

    RACE_COUNTDOWN = RACE_COUNTDOWN - 1;

    if (RACE_COUNTDOWN < 0) {
        {
            int car = RACE_TARGET_CAR;
            *(volatile int *)(car + CAR_FINISH_POS) = (unsigned char)RACE_RESULT_BYTE;
            car = RACE_TARGET_CAR;
            *(volatile int *)(car + CAR_RACE_RESULT) = RACE_RESULT;
        }
        RACE_DATA_SRC = RACE_DATA_DST;
        GAME_STATE = 24;
        RACE_TRANSITION_WORD = 3;
        return;
    }

    if (RACE_PLAYER_MODE == 2) {
        FUN_06033EA8();
    }

    FUN_0601FD74();

    if ((unsigned short)RACE_TRANSITION_WORD == 3) {
        VBL_DISABLE_FLAG = 0;
        FUN_06026CE0();
        return;
    }

    {
        volatile unsigned char *car_flag = (volatile unsigned char *)0x06078901;
        *car_flag = (*car_flag & 0x7F) | 0x80;
    }

    FUN_0600DE40();
    FUN_0600A914();
    FUN_060055BC();
    FUN_0600BFFC();
    FUN_060078DC();
}


void state_24_handler(void)
{
    RACE_PHASE_WORD = 3;

    FUN_06014A74();
    FUN_06019058();
    FUN_0600A1B8();

    GAME_STATE = 25;
    RACE_DIFFICULTY = 6;

    FUN_060032D4();
    FUN_060210F6();

    {
        int car = RACE_TARGET_CAR;
        *(volatile int *)(car + 0x08) = 0;
    }

    RACE_DISPLAY_FLAGS |= 0x40000000;
    FUN_06026CE0();
    RACE_VBL_OUT_FLAG = 0;
}


void state_25_handler(void)
{
    FUN_06014D2C();

    if (*(volatile unsigned char *)0x06085F8A == 0) {
        FUN_0600BB94();
        FUN_060053AC(DISPLAY_ADDR_C, DISPLAY_ADDR_B, DISPLAY_ADDR_A);
        FUN_0600BFFC();
    }

    FUN_060078DC();
}


/* 0x06009DD0: Post-race transition setup (alternate path)
 * Mirrors state_22 but with different countdown value (600 frames)
 * and different dispatch (event 19). Both state 22 and 26 converge
 * into the countdown loop at state 27. */
void state_26_handler(void)
{
    FUN_060190B8();

    GAME_STATE = 27;
    RACE_COUNTDOWN = 600;

    vdp2_pattern_table_clear();
    scene_objects_init();

    RACE_PHASE_WORD = 3;

    FUN_06018DDC(19);
}


/* 0x06009E02: Counter-based transition to state 30 (alternate path)
 * Decrements the countdown started by state 22/26.
 * When countdown reaches 0, transitions to state 30.
 * Calls FUN_0601389E each frame. If state changed (to 30),
 * also calls FUN_06018E70 for general init.
 * Sets display byte at 0x0607864B = 1 every frame. */
void state_27_handler(void)
{
    int countdown = RACE_COUNTDOWN - 1;
    RACE_COUNTDOWN = countdown;

    if (countdown == 0) {
        GAME_STATE = 30;
    }

    FUN_0601389E();

    if (GAME_STATE != 27) {
        FUN_06018E70();
    }

    RACE_DISPLAY_BYTE = 1;
}


/* 0x06009508: Abort processing
 * Handles the abort path (from state 17 when mode_flag == 1).
 * If abort flag (bit 0 of 0x0607EBF4) is still set, clears it.
 * Otherwise increments frame counter if race not ended.
 * Always transitions to state 29.
 * Runs simplified update pipeline (no per-car physics loop). */
void state_28_handler(void)
{
    int flags;

    flags = RACE_FLAGS_WORD;
    if (flags & 0x01) {
        RACE_FLAGS_WORD = flags & ~1;
        GAME_STATE = 20;   /* dead write — overwritten by state=29 below */
    } else {
        if (RACE_END_FLAG == 0) {
            RACE_FRAME_COUNTER = RACE_FRAME_COUNTER + 1;
        }
    }

    GAME_STATE = 29;

    FUN_0600DFD0();
    FUN_0600BB94();

    FUN_060053AC(DISPLAY_ADDR_C, DISPLAY_ADDR_B, DISPLAY_ADDR_A);
    FUN_0600C218();

    FUN_060078DC();
}


/* 0x0600955E: Post-race menu / results screen
 * Complex state with multiple exit paths:
 *   - Start button: save resume=29, enter time extension (state 18)
 *   - Abort flag: clear flag, go to race completion (state 20)
 *   - Mode flag == 0: loop back to state 17
 * Runs update pipeline, scoring, debug display, overlay rendering. */
void state_29_handler(void)
{
    int flags;

    /* Start button check */
    if ((unsigned short)RACE_NEW_BUTTONS & BTN_START) {
        RACE_RESUME_STATE = 29;
        GAME_STATE = 18;
    }

    /* Abort flag check */
    flags = RACE_FLAGS_WORD;
    if (flags & 0x01) {
        RACE_FLAGS_WORD = flags & ~1;
        GAME_STATE = 20;
        goto main_loop;
    }

    /* Frame counter: increment if race not ended */
    if (RACE_END_FLAG == 0) {
        RACE_FRAME_COUNTER = RACE_FRAME_COUNTER + 1;
    }

main_loop:
    /* Menu overlay */
    if (RACE_MENU_OVERLAY_B != 0) {
        FUN_060268B0(0);
    }

    /* Update pipeline */
    FUN_0600E060();
    FUN_0600BB94();

    /* Display commit */
    FUN_060053AC(DISPLAY_ADDR_C, DISPLAY_ADDR_B, DISPLAY_ADDR_A);
    FUN_0600C218();

    /* Sub-init check */
    if ((unsigned short)RACE_INIT_FLAG_W != 0) {
        FUN_060033E6();
    }

    /* Debug display */
    if (RACE_DEBUG_FLAG != 0) {
        FUN_060283E0(8, 0x0082, VDP_COLOR_WHITE, VDP_OVERLAY_ADDR);
    }

    /* Scoring: check car finish position */
    {
        int car_ptr = RACE_TARGET_CAR;
        int finish = *(volatile int *)(car_ptr + CAR_PHYS_FIELD_BC);
        if (finish > 0) {
            FUN_0600A084();
        }
    }

    /* Frame sync */
    FUN_060078DC();

    /* Overlay rendering: check car overlay flags */
    {
        int car_ptr = RACE_TARGET_CAR;
        int overlay = *(volatile int *)(car_ptr + CAR_OVERLAY_FLAGS);
        if ((overlay & 0xCC) == 0) {
            int base = 0x06063798;
            FUN_06028400(4, *(volatile int *)base, 0x0214, *(volatile int *)(base + 4));
        }
    }

    /* Mode check: if mode == 0, loop back to state 17 */
    if (RACE_MODE_FLAG == 0) {
        GAME_STATE = 17;
    }
}


/* 0x06008C14: Resource check router
 * Calls FUN_0601F8C0 to check resource availability.
 * Routes to:
 *   state 31: resource check returned 0 (not ready yet)
 *   state 4:  resource ready, flag clear (retry/boundary path)
 *   state 7:  resource ready, flag set (course select path)
 * Always sets PHASE_FLAG = 3. */
void state_30_handler(void)
{
    int result = FUN_0601F8C0();

    if (result == 0) {
        GAME_STATE = 31;
    } else {
        if (RACE_RESOURCE_FLAG == 0) {
            GAME_STATE = 4;
        } else {
            GAME_STATE = 7;
        }
        RACE_RESOURCE_FLAG = 0;
    }

    RACE_PHASE_WORD = 3;
}


/* 0x06008C76: Memory router
 * Calls FUN_0601F900 to check memory state.
 * Routes to:
 *   state 4: memory flag clear (retry, also calls FUN_060149E0/FUN_06026CE0)
 *   state 6: memory flag set (re-select course)
 * If FUN_0601F900 returns 0, does nothing (stays in current state). */
void state_31_handler(void)
{
    int result = FUN_0601F900();

    if (result != 0) {
        if (RACE_RESOURCE_FLAG == 0) {
            GAME_STATE = 4;
            FUN_060149E0();
            FUN_06026CE0();
        } else {
            GAME_STATE = 6;
        }
        RACE_RESOURCE_FLAG = 0;
    }
}
