#include "game.h"

extern int DAT_0604009e;
extern int DAT_060400a0;
extern int DAT_060400a2;
extern int DAT_060401e8;
extern int DAT_0604089c;
extern int DAT_06040d2c;
extern int DAT_06040dc0;
extern int DAT_06040dc2;
extern int DAT_06040e72;
extern int DAT_06041174;
extern int DAT_060411f6;
extern int DAT_0604128e;
extern int DAT_0604155c;
extern int DAT_0604155e;
extern int DAT_060415ec;
extern int DAT_060415ee;
extern int DAT_060417d8;
extern int DAT_060417da;
extern int DAT_060417dc;
extern int DAT_060417de;
extern int DAT_060417e0;
extern int DAT_060417e2;
extern int DAT_0604185e;
extern int DAT_06041b0a;
extern int DAT_06041bc6;
extern int DAT_06041bc8;
extern int DAT_06041bca;
extern int DAT_06041bcc;
extern int DAT_06041bce;
extern int DAT_06041bd0;
extern int DAT_06041bd2;
extern int DAT_06041ca8;
extern int DAT_06041caa;
extern int DAT_06041d58;
extern int DAT_06041d5a;
extern int DAT_06041dec;
extern int DAT_06041dee;
extern int DAT_06041df0;
extern int DAT_06041df2;
extern int DAT_06041eb4;
extern int DAT_06041eb6;
extern int DAT_06041f90;
extern int DAT_06041f92;
extern int DAT_06041f94;
extern int DAT_06041f96;
extern int DAT_0604207a;
extern int DAT_0604207c;
extern int DAT_0604207e;
extern int FUN_06034984();
extern int cd_register_double_read();
extern int FUN_06035C4E();
extern int FUN_060400b4();
extern int FUN_060405b8();
extern int FUN_060412b2();
extern int FUN_06041310();
extern int FUN_06041698();
extern int FUN_060417a8();
extern int FUN_06041826();
extern int cd_command_queue_process();
extern int FUN_06041aa0();
extern int cd_dma_transfer_poll();
extern int FUN_06041cc8();
extern int cd_session_skip_poll();
extern int cd_session_play_poll();
extern int cd_session_read_step();
extern int cd_session_file_batch();
extern int cd_session_state_reset();
extern int PTR_DAT_06040dc4;
extern int PTR_DAT_06041176;
extern int PTR_DAT_060411f8;
extern int PTR_DAT_06041306;
extern int PTR_DAT_060414c4;
extern int PTR_DAT_060415f0;
extern int PTR_DAT_0604172a;
extern int PTR_DAT_06041b0c;
extern int PTR_DAT_06041cac;
extern int PTR_DAT_06041eb8;
extern void FUN_06040722();

/* cd_subsystem_open -- Open CD subsystem with given mode.
 * Clears active bit in state flags (DAT_0604009e). Calls low-level
 * open (0x06040C98) with session buffer +0xD0 and mode param.
 * On success, sets active bit. Stores max channel (0x17 or -1 based
 * on mode) at session +0xC8. Maps error codes: -15 -> -3, -14 -> -2,
 * -13 -> -23, other non-zero -> -1, 0 -> success. */
int FUN_0604000c(param_1)
    int param_1;
{
    char *cd_state_ptr = (char *)0x060A4D14;    /* CD subsystem state */
    int result;
    int max_channel;

    /* Clear active flag */
    *(unsigned int *)(CD_STATE_A + (int)DAT_0604009e) =
         *(unsigned int *)(CD_STATE_A + (int)DAT_0604009e) & 0xfffffffe;

    result = (*(int(*)())0x06040C98)(*(int *)cd_state_ptr + 0xd0, param_1);

    if (result == 0) {
        /* Set active flag on success */
        *(unsigned int *)((int)DAT_0604009e + *(int *)cd_state_ptr) =
             *(unsigned int *)(*(int *)cd_state_ptr + (int)DAT_0604009e) | 1;
    }

    /* Set max channel count based on mode */
    max_channel = (param_1 == 0) ? 0xffffffff : 0x17;
    *(int *)(*(int *)cd_state_ptr + 0xc8) = max_channel;

    /* Map error codes */
    if (result == -0xf) return 0xfffffffd;
    if (result == -0xe) return 0xfffffffe;
    if (result != -0xd) {
        return (result != 0) ? 0xffffffff : 0;
    }
    return 0xffffffe9;
}


/* cd_session_open -- Initialize a CD session context for playback.
 *
 * If source (param_2) is NULL: opens a new session by querying track info
 * via 0x060415C8, setting up block size, sector offset, and volume.
 * If source is non-NULL: copies configuration from an existing session.
 * Sets track/flags word, clears position/state, sets sentinel to 0x7FFFFFFF.
 *
 * Returns the session pointer, or NULL if track info query fails. */
unsigned int * cd_track_context_init(session, source, track_flags)
    unsigned int *session;
    unsigned int *source;
    unsigned int track_flags;
{

  int iVar1;

  unsigned int uVar2;

  unsigned int local_20;

  int uStack_1c;

  char uStack_18;

  char uStack_17;

  char uStack_16;

  char uStack_15;

  if (source == (unsigned int *)0x0) {

    *session = 0x40000000 | track_flags;

    iVar1 = (*(int(*)())0x060415C8)(track_flags,&local_20);

    if (iVar1 != 0) {

      return (unsigned int *)0x0;

    }

    session[1] = local_20;

    uVar2 = FUN_060400b4(uStack_15);

    session[3] = uVar2;

    uVar2 = (*(int(*)())0x06035F44)();

    session[4] = uVar2;

    (*(int(*)())0x06036BE4)(uStack_1c);

    uVar2 = (*(int(*)())0x06036BE4)();

    session[5] = uVar2;

    *(char *)(session + 7) = uStack_16;

    *(char *)((int)session + 0x1d) = uStack_15;

    *(char *)((int)session + 0x1e) = uStack_18;

    *(char *)((int)session + 0x1f) = uStack_17;

  }

  else {

    *session = track_flags;

    session[1] = *source;

    uVar2 = FUN_060400b4(*(char *)((int)source + 0xb));

    session[3] = uVar2;

    session[4] = (int)DAT_060401e8 + source[1] >> 0xb;

    (*(int(*)())0x06036BE4)();

    uVar2 = (*(int(*)())0x06036BE4)();

    session[5] = uVar2;

    *(char *)(session + 7) = *(char *)((int)source + 10);

    *(char *)((int)session + 0x1d) = *(char *)((int)source + 0xb);

    *(char *)((int)session + 0x1e) = *(char *)(source + 2);

    *(char *)((int)session + 0x1f) = *(char *)((int)source + 9);

  }

  session[6] = 0;

  session[9] = 0;

  session[8] = 0;

  session[10] = 0x7FFFFFFF;

  return session;

}

/* cd_session_seek -- Seek to position in CD session.
 * Stores param_2 at session+0x20, calculates sector offset via FUN_060408B0,
 * clamps to 0 if negative, stores adjusted offset at session+0x24. */
void FUN_060401f8(int param_1, int param_2)
{
    int sector;

    *(int *)(param_1 + 0x20) = param_2;
    sector = (*(int(*)())0x060408B0)(*(int *)(param_1 + 0x18), 0x7FFFFFFF, 0);
    if (sector < 0)
        sector = 0;
    *(int *)(param_1 + 0x24) = sector - *(int *)(*(int *)(param_1 + 0x18) + 0x10);
}

/* cd_file_info_extract -- Extract fields from CD file record into output params.
 * Reads FAD (frame address), file size, LBA range, flags, and attributes
 * from a packed CD file record. Each output pointer may be NULL to skip.
 * FAD has bit 30 stripped (marks CD-XA). Sectors remaining computed as
 * start - used, or 0 if interleave flags set. Returns 0x1D or 0. */
int cd_file_info_extract(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
    unsigned int *param_1;
    unsigned int *param_2;
    unsigned int *param_3;
    unsigned int *param_4;
    unsigned int *param_5;
    int *param_6;
    unsigned int *param_7;
    unsigned int *param_8;
{
    int result = 0;

    /* FAD (frame address) — strip CD-XA flag at bit 30 */
    if (param_2 != (unsigned int *)0x0) {
        if ((*param_1 & 0x40000000) == 0) {
            *param_2 = *param_1;
        } else {
            *param_2 = *param_1 & 0x3FFFFFFF;
        }
    }

    /* File size in bytes */
    if (param_3 != (unsigned int *)0x0) {
        *param_3 = param_1[1];
    }

    /* Flags byte at +0x1C */
    if (param_7 != (unsigned int *)0x0) {
        *param_7 = (unsigned int)*(unsigned char *)(param_1 + 7);
    }

    /* LBA start sector */
    if (param_4 != (unsigned int *)0x0) {
        *param_4 = param_1[3];
    }

    /* LBA end sector */
    if (param_5 != (unsigned int *)0x0) {
        *param_5 = param_1[4];
    }

    /* Attributes byte at +0x1D */
    if (param_8 != (unsigned int *)0x0) {
        result = 0x1d;
        *param_8 = (unsigned int)*(unsigned char *)((int)param_1 + 0x1d);
    }

    /* Sectors remaining (start - used), unless interleave bits 3+2 both set */
    if (param_6 != (int *)0x0) {
        if (((*(unsigned char *)((int)param_1 + 0x1d) & 8) == 0) ||
           (result = 0x1d, (*(unsigned char *)((int)param_1 + 0x1d) & 4) == 0)) {
            result = 0x1d;
            *param_6 = param_1[3] - param_1[5];
        } else {
            *param_6 = 0;
        }
    }

    return result;
}

/* cd_status_query -- Query CD drive status and classify state.
 * Reads CD register pair via FUN_06041330, optionally returns raw
 * status in param_2 and position in param_1. Maps status nibble to
 * state codes: 0=playing, 1=seeking, 2=stopped/paused, 3=scan,
 * 4=complete, 5=error. */
int FUN_060405b8(param_1, param_2)
    int *param_1;
    short *param_2;
{
    short raw_status;
    unsigned char reg_data[8];
    int position;

    raw_status = (*(int(*)())0x06041330)(reg_data);
    if (param_2 != (short *)0x0) {
        *param_2 = raw_status;
    }
    if (param_1 != (int *)0x0) {
        *param_1 = position;
    }

    switch (reg_data[0] & 0xf) {
    case 0:  return 2;                             /* stopped */
    case 1:
    case 2:  return 0;                             /* playing */
    case 3:
    case 8:  return 1;                             /* seeking */
    case 4:  return 2;                             /* paused */
    case 5:  return 1;                             /* seeking (retry) */
    case 6:  return 3;                             /* scanning */
    case 7:  return 4;                             /* complete */
    default: return 5;                             /* error/unknown */
    }
}

/* cd_session_is_busy -- Check if CD session is still processing.
 * Returns 0 if FUN_060405b8 reports state 4 (complete), else 1 (busy). */
int FUN_06040680(void)
{
    return (FUN_060405b8(0) == 4) ? 0 : 1;
}


/* cd_session_create -- Create and configure a new CD audio session.
 *
 * Sets up a session context struct for CD audio playback. Initializes
 * track number, size, format byte, and playback mode. Then opens the
 * CD subsystem via a chain of init calls (0x06040EEC, 0x06040E88,
 * 0x06041034, 0x060414D0, 0x0604188C). Returns session pointer on
 * success, NULL if any init step fails. */
int * cd_session_create(session, track_num, track_size, format, play_mode)
    int *session;
    int track_num;
    int track_size;
    char format;
    int play_mode;
{

  int iVar1;

  int local_1c;

  int uStack_18;

  char local_14;

  char uStack_13;

  char uStack_12;

  char uStack_11;

  char uStack_10;

  char uStack_f;

  *session = track_num;

  session[2] = 0;

  *(char *)(session + 6) = format;

  session[3] = track_size;

  session[4] = 0;

  session[8] = 1;

  *(char *)((int)session + 0x19) = 0;

  *(char *)((int)session + 0x1a) = 0;

  *(char *)((int)session + 0x1b) = 0;

  session[9] = (unsigned int)play_mode;

  local_14 = *(char *)(session + 6);

  uStack_13 = *(char *)((int)session + 0x19);

  uStack_12 = 0;

  uStack_11 = 0;

  uStack_10 = 0;

  uStack_f = 0;

  (*(int(*)())0x06035228)();

  session[10] = 0xffffffff;

  iVar1 = (*(int(*)())0x06040EEC)(&uStack_18);

  if (iVar1 == 0) {

    session[1] = uStack_18;

    iVar1 = (*(int(*)())0x06040E88)(&local_1c);

    if (iVar1 == 0) {

      session[5] = local_1c;

      iVar1 = (*(int(*)())0x06041034)(local_1c,session[8],&local_14,0,0);

      if (iVar1 == 0) {

        iVar1 = (*(int(*)())0x060414D0)(local_1c,uStack_18,(int)DAT_0604089c);

        if (iVar1 == 0) {

          iVar1 = (*(int(*)())0x0604188C)();

          if (iVar1 != 0) {

            session = (int *)0x0;

          }

        }

        else {

          session = (int *)0x0;

        }

      }

      else {

        session = (int *)0x0;

      }

    }

    else {

      (*(int(*)())0x06040F16)(uStack_18);

      session = (int *)0x0;

    }

  }

  else {

    session = (int *)0x0;

  }

  return session;

}

/* cd_session_read_sectors -- Read sectors from CD session and adjust position.
 * Calls sector read (0x060411A0) with session params. On success, calls
 * polling function (0x0604188C). If param_3 is non-null and read data
 * extends past track boundary, adjusts param_3 by wrap-around offset.
 * Returns number of sectors read, or 0 on error. */
int FUN_060408b0(param_1, param_2, param_3)
    int *param_1;
    int param_2;
    int *param_3;
{
    int result;
    int sectors_read;
    int wrap_offset;
    int track_start;
    int track_end;
    int saved_param2;

    saved_param2 = param_2;
    result = (*(int(*)())0x060411A0)(param_1[1], param_1[4], param_2, &sectors_read, param_3);

    if (result == 0) {
        result = (*(int(*)())0x0604188C)();
        if (result == 0) {
            /* Adjust position for wrap-around if needed */
            if ((((param_3 != (int *)0x0) &&
                 ((*(int(*)())0x06040220)(*param_1, 0, 0, &track_start, &track_end, &wrap_offset, 0, 0),
                 track_end <= param_1[2] + param_1[4] + sectors_read)) &&
                 (wrap_offset != 0)) && (0 < sectors_read)) {
                *param_3 = *param_3 - (track_start - wrap_offset);
            }
        } else {
            sectors_read = 0;
        }
    } else {
        sectors_read = 0;
    }
    return sectors_read;
}

/* cd_seek_position -- Seek to a target sector position within a CD stream.
 * param_1 = stream state struct (+4=handle, +8=base_sector, +0x10=offset,
 * +0x24=seek_mode). param_2 = target sector, param_3 = seek type (1=relative).
 * For relative seeks, adds to current position. For absolute, resets transfer
 * first. In mode 0 (sequential): skips sectors forward. In mode 1 (random):
 * full reset if target is outside current window. Returns final position. */
int cd_seek_position(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
    int target_sector;
    int skip_count;
    int result;

    if (param_2 < 0) {
        param_2 = 0;
    }

    if (param_3 == 1) {
        /* Relative seek: offset from current position */
        target_sector = *(int *)(param_1 + 8) + *(int *)(param_1 + 0x10) + param_2;
        skip_count = param_2;
    } else {
        /* Absolute seek: check if already at target */
        if (*(int *)(param_1 + 8) + *(int *)(param_1 + 0x10) == param_2) {
            return param_2;                    /* already there */
        }
        /* Reset transfer and wait for completion */
        result = (*(int(*)())0x060411A0)(*(int *)(param_1 + 4), 0, 0x0000FFFF, &skip_count, 0);
        if (result != 0) {
            return -1;
        }
        result = (*(int(*)())0x0604188C)();    /* cd_wait_complete */
        if (result != 0) {
            return -1;
        }
        target_sector = param_2;
        if (skip_count < 0) {
            skip_count = 0;
        }
    }

    if (*(int *)(param_1 + 0x24) == 0) {
        /* Sequential mode: skip forward within current window */
        if ((*(int *)(param_1 + 8) <= target_sector) &&
           (target_sector < *(int *)(param_1 + 0x10) + *(int *)(param_1 + 8))) {
            skip_count = target_sector - *(int *)(param_1 + 8);
        }
        if (0 < skip_count) {
            (*(int(*)())0x060412B2)(*(int *)(param_1 + 4), 0, skip_count);  /* skip sectors */
            result = (*(int(*)())0x0604188C)();  /* cd_wait_complete */
            if (result != 0) {
                return -1;
            }
        }
        *(int *)(param_1 + 8) = target_sector;
        *(int *)(param_1 + 0x10) = 0;
    } else if (*(int *)(param_1 + 0x24) == 1) {
        /* Random access mode: full reset if outside window */
        if ((target_sector < *(int *)(param_1 + 8)) ||
           (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 8) + 1 < target_sector)) {
            (*(int(*)())0x060412B2)(*(int *)(param_1 + 4), 0, 0x0000FFFF);  /* reset all */
            result = (*(int(*)())0x0604188C)();
            if (result == 0) {
                return -1;
            }
            *(int *)(param_1 + 8) = target_sector;
        }
        *(int *)(param_1 + 0x10) = target_sector - *(int *)(param_1 + 8);
    }

    return *(int *)(param_1 + 8) + *(int *)(param_1 + 0x10);
}

/* cd_read_buffer_setup -- Allocate and configure a CD read descriptor.
 * Uses static descriptor at 0x0606367C (returns NULL if already active).
 * Calls cd_read_start (0x060411A0) to initiate sector transfer, waits
 * for completion, then fills descriptor: [0]=status, [8]=sectors_read,
 * [0xC]=sector_offset, [0x10]=active flag. Adjusts sector count if
 * file extends past track boundary. Returns descriptor pointer or NULL. */
char * cd_read_buffer_setup(param_1, param_2)
    int *param_1;
    int param_2;
{
    char *desc;
    int result;
    int cd_status;
    int sector_offset;
    int sectors_read;
    int sectors_remaining;
    int lba_start;
    int lba_end;

    /* Check if read descriptor is available */
    if (((int *)0x0606367C)[0x10] != '\0') {
        return (char *)0x0;                    /* descriptor busy */
    }

    /* Initiate sector read transfer */
    result = (*(int(*)())0x060411A0)(param_1[1], param_1[4], param_2, &sector_offset, &sectors_read);
    if (result != 0) {
        return (char *)0x0;
    }

    result = (*(int(*)())0x0604188C)();        /* cd_wait_complete */
    if (result != 0) {
        return (char *)0x0;
    }

    if (sectors_read < 1) {
        return (char *)0x0;                    /* no sectors read */
    }

    /* Get file LBA range for boundary check */
    (*(int(*)())0x06040220)(*param_1, 0, 0, &lba_start, &lba_end, &sectors_remaining, 0, 0);
    desc = (char *)0x0606367C;

    /* Adjust if file extends past track boundary */
    if (((lba_end <= param_1[2] + param_1[4] + sector_offset) && (sectors_remaining != 0)) &&
       (0 < sector_offset)) {
        sectors_read = sectors_read - (lba_start - sectors_remaining);
    }

    /* Fill read descriptor */
    cd_status = (*(int(*)())0x06035C48)();     /* cd_get_transfer_status */
    *(int *)desc = cd_status;
    *(int *)(desc + 4) = 0;                    /* read position */
    *(int *)(desc + 8) = sectors_read;
    *(int *)(desc + 0xc) = sector_offset;
    desc[0x10] = 1;                            /* mark active */

    return desc;
}

/* cd_read_validate -- Validate and initiate a CD read request.
 * Calls partition setup (0x06041204) with session fields, then verifies
 * the read completed via status check (0x0604188C). Returns 1 on success,
 * 0 if either step fails. */
int FUN_06040c10(int param_1, int param_2)
{
  int result;

  result = (*(int(*)())0x06041204)(*(int *)(param_2 + 4), *(int *)(param_2 + 0x10),
                                   *(int *)(param_1 + 0xc));
  if (result != 0) return 0;

  result = (*(int(*)())0x0604188C)();
  if (result != 0) return 0;

  return 1;
}

/* cd_session_open -- Initialize and open a CD session.
 * Sets CD_SESSION_BASE, clears state via cd_session_state_reset,
 * configures mode flags. Queries drive status: 6=tray open (-13),
 * 7=no disc (-14), 9/10=fatal (-10). Sets up partition table,
 * polls until ready (status 1 or 2), initializes directory,
 * verifies CD-XA flag, configures default filter, and waits for
 * completion with 0x8000 iteration timeout. Returns 0 on success. */
int cd_session_open(param_1, param_2)
    int param_1;
    int param_2;
{
    int ready_flag;
    unsigned char cd_status;
    int result;
    unsigned short poll_status;
    unsigned short status_mask;
    int part_offset;
    int state_base;
    int filter_id = (int)DAT_06040d2c;
    unsigned char part_count[4];
    unsigned char cd_result[16];
    char *session_ptr = (char *)0x060A5400;
    int retry_count;

    /* Initialize session */
    CD_SESSION_BASE = param_1;
    (*(int(*)())0x0604231E)();                 /* cd_session_state_reset */

    /* Set mode flags based on param_2 */
    if (param_2 == 0) {
        *(char *)(*(int *)session_ptr + 0x17) = 0;
        *(char *)(*(int *)session_ptr + 0x2f) = 0;
    } else {
        *(char *)(*(int *)session_ptr + 0x17) = 1;
        *(char *)(*(int *)session_ptr + 0x2f) = 1;
    }

    /* Query initial drive status */
    (*(int(*)())0x06034984)(cd_result);        /* cd_get_result */
    cd_status = cd_result[0] & 0xf;
    if (cd_status == 6) return 0xfffffff3;     /* -13: tray open */
    if (cd_status == 7) return 0xfffffff2;     /* -14: no disc */
    if ((cd_status == 9) || (cd_status == 10)) {
        return 0xfffffff6;                     /* -10: fatal error */
    }

    /* Initialize partition table */
    result = (*(int(*)())0x06034B9A)(filter_id, 0x0000FFFF, filter_id, filter_id);
    if (result != 0) return 0xfffffffe;        /* -2: init failed */

    /* Poll until drive reports ready (status 1=playing or 2=paused) */
    retry_count = 0;
    ready_flag = 0;
    while (status_mask = DAT_06040dc0, !ready_flag) {
        poll_status = (*(int(*)())0x06035C4E)();  /* cd_get_status */
        if ((poll_status & status_mask) != 0) {
            (*(int(*)())0x06035C54)(0x0000FBFF);  /* cd_acknowledge */
            retry_count++;
            if (DAT_06040dc2 < retry_count) return 0xfffffffe;  /* -2: timeout */

            (*(int(*)())0x06034984)(cd_result);
            cd_status = cd_result[0] & 0xf;
            if ((cd_status == 1) || (cd_status == 2)) {
                ready_flag = 1;
            } else if ((cd_status == 9) || (cd_status == 10)) {
                return 0xfffffff6;             /* -10: drive error during init */
            }
        }
    }

    /* Initialize directory from partition table */
    part_offset = (int)PTR_DAT_06040dc4;
    state_base = CD_STATE_A;
    result = (*(int(*)())0x06034AEE)(state_base + part_offset);  /* cd_init_partition */
    if (result != 0) return 0xfffffffe;

    /* Get partition count and verify CD-XA flag (bit 30) */
    (*(int(*)())0x06034B54)(0, part_count);    /* cd_get_partition_count */
    (*(int(*)())0x06034B54)(part_count[0], part_count);
    if ((*(unsigned int *)(state_base + part_offset + (part_count[0] - 1) << 2) & 0x40000000) == 0) {
        return 0xfffffff1;                     /* -15: not CD-XA */
    }

    /* Configure default filter and wait for completion */
    (*(int(*)())0x060364D4)((int)DAT_06040e72, filter_id);  /* cd_set_filter */
    *(char **)(*(int *)session_ptr + 0x3c) = 0x00008000;    /* timeout counter */

    do {
        poll_status = (*(int(*)())0x06035C4E)();  /* cd_get_status */
        if ((poll_status & 0x40) != 0) {
            *(int *)(*(int *)session_ptr + 0x3c) = 0;
            (*(int(*)())0x06034984)(*(int *)session_ptr + 0x40);  /* store final result */
            return 0;                          /* success */
        }
        filter_id = *(int *)(*(int *)session_ptr + 0x3c) + -1;
        *(int *)(*(int *)session_ptr + 0x3c) = filter_id;
    } while (filter_id != 0);

    return 0xfffffffe;                         /* -2: timeout */
}

/* cd_session_close -- Close an open CD session by channel index.
 * Validates param_1 is in range 0..23. If session is open (byte==1),
 * calls FUN_060412b2 to start close, sets blocking flag (+0x3C=0x8000),
 * then polls FUN_06041698/FUN_06041310 until complete. Returns -6 for
 * out-of-range, -7 for not-open, -12 for timeout, 0 on success. */
int FUN_06040f16(param_1)
    int param_1;
{
    char *session_ptr = (char *)0x060A5400;
    int result;

    if ((param_1 < 0) || (0x17 < param_1)) {
        result = 0xfffffffa;                     /* out of range */
    } else if (*(char *)(param_1 + CD_SESSION_BASE) == '\x01') {
        int poll;
        FUN_060412b2(param_1, 0, 0x0000FFFF);
        *(char **)(*(int *)session_ptr + 0x3c) = 0x00008000;   /* set blocking */

        do {
            poll = FUN_06041698();
            if (poll == 3) {
                return 0xfffffff4;               /* timeout */
            }
            poll = FUN_06041310(param_1);
        } while (poll != 1);

        *(int *)(*(int *)session_ptr + 0x3c) = 0;
        *(char *)(param_1 + *(int *)session_ptr) = 0;
        result = 0;
    } else {
        result = 0xfffffff9;                     /* not open */
    }
    return result;
}

/* cd_session_lock -- Acquire CD session lock.
 * Returns -5 if already locked (+0x30 == 1).
 * Sets lock, increments sequence counter at +0x38 (clamped to >= 0).
 * Returns the new sequence number. */
int FUN_06040fb8(void)
{
    int *base = (int *)0x060A5400;
    if (*(int *)(CD_SESSION_BASE + 0x30) == 1)
        return -5;  /* already locked */
    *(int *)(CD_SESSION_BASE + 0x30) = 1;
    *(int *)(*base + 0x38) = *(int *)(*base + 0x38) + 1;
    if (*(int *)(*base + 0x38) < 0)
        *(int *)(*base + 0x38) = 0;
    return *(int *)(*base + 0x38);
}

/* cd_session_unlock -- Release CD session lock.
 * Returns -7 if not locked (+0x30 == 0).
 * Returns -9 if sequence number doesn't match param_1.
 * On success, clears lock and returns 0. */
int FUN_06040fea(int param_1)
{
    if (*(int *)(CD_SESSION_BASE + 0x30) == 0)
        return -7;  /* not locked */

    if (*(int *)(CD_SESSION_BASE + 0x38) != param_1)
        return -9;  /* sequence mismatch */

    *(int *)(CD_SESSION_BASE + 0x30) = 0;
    return 0;
}

/* cd_command_enqueue -- Add a CD command to the session command queue.
 * Queue stored at session+0x5C, 16 bytes per entry (max 24 entries).
 * Entry format: [0]=channel, [1]=filter, [8]=callback, [0xC]=userdata.
 * Sets dispatch flag (+0x58) on first entry. Increments queue counter
 * at +0x54. Dispatches immediately via cd_command_queue_process.
 * Returns 0 on success, -8 (queue full), -7 (channel not open). */
int cd_command_enqueue(param_1, param_2, param_3, param_4, param_5)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
    int param_5;
{
    char *session_ptr = (char *)0x060A5400;
    int queue_count = *(int *)(CD_SESSION_BASE + 0x54);
    int queue_offset;
    char dispatch_buf[8];

    /* Verify channel is open */
    if (*(char *)(param_1 + CD_SESSION_BASE + 0x18) != '\x01') {
        return 0xfffffff9;                     /* -7: channel not open */
    }

    /* Check queue capacity (max 24 entries) */
    if (queue_count >= 0x18) {
        return 0xfffffff8;                     /* -8: queue full */
    }

    /* Set dispatch flag on first queue entry */
    if (*(int *)(CD_SESSION_BASE + 0x58) == 0) {
        *(int *)(CD_SESSION_BASE + 0x58) = 1;
    }

    /* Write queue entry (16 bytes at +0x5C + index*16) */
    queue_offset = (queue_count << 4);
    *(char *)(*(int *)session_ptr + 0x5c + queue_offset) = (char)param_1;   /* channel */
    *(char *)(*(int *)session_ptr + queue_offset + 0x5d) = param_2;         /* filter */
    (*(int(*)())0x06035228)();                 /* cd_sync */
    *(int *)(*(int *)session_ptr + queue_offset + 100) = param_4;           /* callback */
    *(int *)(queue_offset + *(int *)session_ptr + 0x68) = param_5;          /* userdata */

    /* Increment queue counter and dispatch */
    *(int *)(*(int *)session_ptr + 0x54) = *(int *)(*(int *)session_ptr + 0x54) + 1;
    cd_command_queue_process(dispatch_buf);

    return 0;
}

/* cd_session_lock_verify -- Verify session lock and issue stop command.
 * Validates param_1 against expected filter ID or checks session+0x18 flag.
 * Verifies session handle matches param_2. Sets lock flag, stores filter ID,
 * then dispatches stop command via FUN_06041aa0. Returns negative on error. */
int FUN_06041128(int param_1, int param_2)
{
  int *session = (int *)0x060A5400;
  int offset;
  char auStack_8[8];

  if ((param_1 != DAT_06041174) && (*(char *)(param_1 + CD_SESSION_BASE + 0x18) != '\x01')) {
    return 0xfffffff9;                      /* -7: invalid filter */
  }
  if (*(int *)(CD_SESSION_BASE + 0x38) != param_2) {
    return 0xfffffff7;                      /* -9: session mismatch */
  }

  offset = (int)PTR_DAT_06041176;
  *(int *)(CD_SESSION_BASE + offset) = 1;
  *(int *)(*session + offset + 4) = param_1;
  FUN_06041aa0(auStack_8);
  return 0;
}

/* cd_read_request_init -- Initialize a CD sector read request.
 * Checks request slot busy flag. Fills request structure: FAD address (param_1),
 * sector count (param_2), destination buffer (param_3), transfer mode (param_4),
 * and callback (param_5). Dispatches via cd_dma_transfer_poll. Returns -1 if busy. */
int FUN_060411a0(int param_1, int param_2, int param_3, int param_4, int param_5)
{
  int *session = (int *)0x060A5400;
  int offset;
  char auStack_8[8];

  if (*(int *)(CD_SESSION_BASE + (int)DAT_060411f6) != 0) {
    return 0xffffffff;                      /* -1: request slot busy */
  }

  offset = (int)DAT_060411f6;
  *(int *)(CD_SESSION_BASE + offset) = 1;           /* mark slot active */
  *(int *)(*session + offset + 4)  = param_1;       /* FAD address */
  *(int *)(*session + offset + 8)  = param_2;       /* sector count */
  *(int *)(*session + offset + 0xc) = param_3;      /* destination buffer */
  *(int *)(*session + offset + 0x10) = 0;           /* reserved */
  *(int *)(*session + offset + 0x14) = param_4;     /* transfer mode */
  *(int *)(*session + (int)PTR_DAT_060411f8) = param_5;  /* callback */
  cd_dma_transfer_poll(auStack_8);
  return 0;
}

/* cd_partition_request -- Request CD data partition setup.
 * Checks partition slot (offset 0x328) busy and session active flags.
 * Fills partition request: FAD (param_1), size (param_2), filter (param_3).
 * Marks session active, dispatches via FUN_06041cc8.
 * Returns -1 if busy, -5 if session already active. */
int FUN_06041204(int param_1, int param_2, int param_3)
{
  int *session = (int *)0x060A5400;
  char auStack_8[8];

  if (*(int *)(CD_SESSION_BASE + 0x328) != 0) {
    return 0xffffffff;                      /* -1: partition slot busy */
  }
  if (*(int *)(CD_SESSION_BASE + 0x34) == 1) {
    return 0xfffffffb;                      /* -5: session already active */
  }

  *(int *)(CD_SESSION_BASE + 0x34) = 1;    /* mark session active */
  *(int *)(*session + 0x328) = 1;          /* mark slot active */
  *(int *)(*session + 0x32C) = param_1;    /* FAD address */
  *(int *)(*session + 0x330) = param_2;    /* partition size */
  *(int *)(*session + 0x334) = param_3;    /* filter index */
  FUN_06041cc8(auStack_8);
  return 0;
}

/* cd_partition_finalize -- Finalize CD partition after data transfer.
 * Checks session active flag at CD_SESSION_BASE+0x34; returns -7 if inactive.
 * Calls partition close (0x06034CC8), clears active flag. On error returns -10.
 * Reads partition result via callback at 0x06041308, stores first byte. */
int FUN_06041258(void)
{
  int *session = (int *)0x060A5400;         /* CD session pointer */
  int result;
  char local_14[16];

  if (*(int *)(CD_SESSION_BASE + 0x34) == 0) {
    return 0xfffffff9;                      /* -7: session not active */
  }

  result = (*(int(*)())0x06034CC8)();
  *(int *)(*session + 0x34) = 0;            /* clear active flag */

  if (result != 0) {
    return 0xfffffff6;                      /* -10: close failed */
  }

  (*(int(*)())*(int *)0x06041308)(local_14);
  *(char *)(*session + 0x40) = local_14[0]; /* store partition result */
  return 0;
}

/* cd_seek_request -- Issue a CD seek command to target FAD.
 * Checks seek slot (offset 0x338) busy and session active flags.
 * Fills seek request: FAD (param_1), seek mode (param_2), speed (param_3).
 * Marks session active, dispatches via cd_session_skip_poll.
 * Returns -1 if busy, -5 if session already active. */
int FUN_060412b2(int param_1, int param_2, int param_3)
{
  int *session = (int *)0x060A5400;
  char auStack_8[8];

  if (*(int *)(CD_SESSION_BASE + 0x338) != 0) {
    return 0xffffffff;                      /* -1: seek slot busy */
  }
  if (*(int *)(CD_SESSION_BASE + 0x34) == 1) {
    return 0xfffffffb;                      /* -5: session already active */
  }

  *(int *)(CD_SESSION_BASE + 0x34) = 1;    /* mark session active */
  *(int *)(*session + 0x338) = 1;          /* mark slot active */
  *(int *)(*session + 0x33C) = param_1;    /* FAD target */
  *(int *)(*session + 0x340) = param_2;    /* seek mode */
  *(int *)(*session + 0x344) = param_3;    /* seek speed */
  cd_session_skip_poll(auStack_8);
  return 0;
}

/* cd_session_read_and_process -- Read CD register pair, process if valid.
 * If double-read returns non-zero, run sector processing. Always flush. */
void FUN_06041330(int sector)
{
    if (cd_register_double_read(sector) != 0) {
        FUN_06034984(sector);
    }
    FUN_06035C4E();
}

/* cd_session_verify -- Verify CD session matches expected param.
 * Returns -9 (0xFFFFFFF7) if session mismatch, 0 on success. */
int FUN_0604134e(int param_1, int expected)
{
    if (*(int *)(CD_SESSION_BASE + 0x38) != expected) {
        return 0xFFFFFFF7;  /* session mismatch error */
    }
    (*(int(*)())0x06034DEA)();
    return 0;

}

/* cd_play_request -- Issue a CD audio play command.
 * Validates filter at param_2: checks session+0x18 and session+0x00 flags.
 * If valid and play slot (offset 0x360) is free, fills request with FAD
 * (param_1) and filter (param_2), dispatches via cd_session_read_step.
 * Returns -1 if slot busy, -5 if filter invalid. */
int FUN_06041470(int param_1, int param_2)
{
  int *session = (int *)0x060A5400;
  char auStack_8[8];

  if ((*(char *)(param_2 + CD_SESSION_BASE + 0x18) == '\x01') &&
      (*(char *)(param_2 + CD_SESSION_BASE) == '\x01')) {
    if (*(int *)(CD_SESSION_BASE + 0x360) != 0) {
      return 0xffffffff;                    /* -1: play slot busy */
    }
    *(int *)(CD_SESSION_BASE + 0x360) = 1;  /* mark slot active */
    *(int *)(*session + 0x364) = param_1;   /* FAD to play */
    *(int *)(*session + 0x368) = param_2;   /* filter index */
    cd_session_read_step(auStack_8);
    return 0;
  }
  return 0xfffffffb;                        /* -5: invalid filter */
}

/* cd_file_transfer_enqueue -- Queue a file transfer between CD channels.
 * Validates source (param_1), filter (param_2), and dest (param_3) channel
 * indices: must be 0-23, -2 (any), or DAT_0604155e (default). Checks that
 * channels are open. Adds 12-byte entry (src, filter, dest) to file table
 * at DAT_060415ee offset. Dispatches immediately via cd_session_file_batch.
 * Returns 0 on success, -6 (out of range), -7 (not open), -8 (table full). */
int cd_file_transfer_enqueue(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{
    char *session_ptr = (char *)0x060A5400;
    int default_ch = (int)DAT_0604155e;
    int table_count = *(int *)(CD_SESSION_BASE + (int)DAT_0604155c);
    int entry_offset;
    int table_base;
    char dispatch_buf[8];

    /* Validate channel indices (0-23, -2=any, default_ch=wildcard) */
    if ((((param_1 != default_ch) && (param_1 != -2)) && ((param_1 < 0 || (0x17 < param_1)))) ||
       (((param_2 < 0 || (0x17 < param_2)) ||
        ((param_3 != default_ch && ((param_3 != -2 && ((param_3 < 0 || (0x17 < param_3)))))))))) {
        return 0xfffffffa;                     /* -6: out of range */
    }

    /* Verify channels are open (or special value) */
    if (((param_1 == default_ch) ||
        ((param_1 == -2 || (*(char *)(param_1 + CD_SESSION_BASE + 0x18) == '\x01')))) &&
       (((param_3 == default_ch ||
         ((param_3 == -2 || (*(char *)(param_3 + CD_SESSION_BASE + 0x18) == '\x01')))) &&
        (*(char *)(param_2 + CD_SESSION_BASE) == '\x01')))) {

        if (0x17 < table_count) {
            return 0xfffffff8;                 /* -8: file table full */
        }

        /* Set active flag on first entry */
        if (*(int *)(CD_SESSION_BASE + 0x1e0) == 0) {
            *(int *)(CD_SESSION_BASE + 0x1e0) = 1;
        }

        /* Write 12-byte file entry (src_channel, filter, dest_channel) */
        entry_offset = (int)(short)((short)table_count * 0xc);
        table_base = (int)DAT_060415ee;
        *(int *)(*(int *)session_ptr + table_base + entry_offset) = param_1;
        *(int *)(table_base + *(int *)session_ptr + entry_offset + 4) = param_2;
        *(int *)(entry_offset + (int)DAT_060415ee + *(int *)session_ptr + 8) = param_3;

        /* Increment file count and dispatch */
        *(int *)(*(int *)session_ptr + (int)PTR_DAT_060415f0) =
             *(int *)(*(int *)session_ptr + (int)PTR_DAT_060415f0) + 1;
        cd_session_file_batch(dispatch_buf);
        return 0;
    }

    return 0xfffffff9;                         /* -7: channel not open */
}

/* cd_session_seek -- Seek to a position on CD and verify track state.
 * Queries CD subsystem state via 0x06036A98. If state != 2 or seek
 * position exceeds track end + 2, returns -11 (0xFFFFFFF5) error.
 * Otherwise performs seek via 0x06036AF2, reads TOC status, and
 * stores first byte into session +0x40. */
int FUN_060415c8(param_1, param_2)
    int param_1;
    int param_2;
{
    int result;
    int cd_state;
    int track_end;
    int seek_pos;
    char seek_buf[4];
    int seek_param;
    char toc_buf[16];

    seek_pos = param_1;
    seek_param = param_2;
    result = (*(int(*)())0x06036A98)(&cd_state, &track_end, seek_buf);
    if (result != 0) {
        return 0xfffffff5;                       /* CD error */
    }
    if ((cd_state == 2) && (seek_pos < track_end + 2)) {
        result = (*(int(*)())0x06036AF2)(seek_pos, seek_param);
        if (result != 0) {
            return 0xfffffff5;
        }
        (*(int(*)())0x060349B6)(toc_buf);
        *(char *)(CD_SESSION_BASE + 0x40) = toc_buf[0];
        return 0;
    }
    return 0xfffffff5;
}

/* cd_session_poll_loop -- Poll all 8 CD channels and process pending ops.
 * Decrements session countdown at CD_SESSION_BASE+0x3c. If expired,
 * calls cd_session_state_reset and returns 3 (timeout). Otherwise checks interrupt
 * status via 0x06035C4E: if set, clears interrupt (0x06035C54), reads
 * CD data (0x06034984), and invokes session callback if present.
 * Then iterates 8 channels: skips free slots (FUN_060417a8), dispatches
 * active ones (FUN_06041826). Returns 1 if any channel exceeds 30
 * retries, 0 if all idle, 1 if any active. */
int FUN_06041698()
{
    char *session_table = (char *)0x060A5400;
    int result;
    int active_count = 0;
    int retry_count = 0;
    unsigned int irq_mask = (unsigned int)PTR_DAT_0604172a;
    char cd_buffer[16];
    int countdown;

    if ((*(int *)(CD_SESSION_BASE + 0x3c) == 0) ||
       (countdown = *(int *)(CD_SESSION_BASE + 0x3c) + -1,
       *(int *)(CD_SESSION_BASE + 0x3c) = countdown, 0 < countdown)) {

        short irq_status = (*(int(*)())0x06035C4E)();

        if (((int)irq_status & irq_mask) == 0) {
            /* No interrupt: try reading CD register */
            int read_ok = (*(int(*)())0x060349C4)(cd_buffer);
            if (read_ok == 0) {
                (*(int(*)())0x06035168)();         /* acknowledge */
            }
        } else {
            /* Interrupt pending: clear and process */
            (*(int(*)())0x06035C54)(0x0000FBFF);   /* clear IRQ bit */
            (*(int(*)())0x06034984)(cd_buffer);    /* read CD data */
            (*(int(*)())0x06035168)();             /* acknowledge */
            if (*(int *)(*(int *)session_table + 0x4c) != 0) {
                int session = *(int *)session_table;
                (*(int(*)())(*(int *)(session + 0x4c)))(*(int *)(session + 0x50));
            }
        }

        /* Poll all 8 CD channels */
        int ch;
        for (ch = 0; ch < 8; ch = ch + 1) {
            int free = FUN_060417a8(ch);
            if (free == 0) {
                int dispatched = FUN_06041826(ch, &retry_count);
                active_count = active_count + dispatched;
                if (0x1e < retry_count) {
                    return 1;                      /* retry limit exceeded */
                }
            }
        }

        if (active_count < 1) {
            result = 0;                            /* all channels idle */
        } else {
            result = 1;                            /* channels still active */
        }
    } else {
        cd_session_state_reset();                            /* timeout handler */
        result = 3;
    }

    return result;
}


/* cd_channel_dispatch -- Dispatch CD channel handler by index.
 * Routes channel index (0-7) to its processing function:
 * 0=cd_command_queue_process, 1=FUN_06041aa0 (read poll), 2=cd_dma_transfer_poll,
 * 3=FUN_06041cc8 (write poll), 4=cd_session_skip_poll, 5=cd_session_play_poll,
 * 6=cd_session_file_batch, 7=cd_session_read_step. Always returns 0. */
int FUN_06041826(param_1, param_2)
    int param_1;
    int param_2;
{
    if (param_1 == 0) {
        cd_command_queue_process(param_2);
        return 0;
    }
    if (param_1 == 1) {
        FUN_06041aa0(param_2);                     /* cd_session_read_poll */
        return 0;
    }
    if (param_1 == 2) {
        cd_dma_transfer_poll(param_2);
        return 0;
    }
    if (param_1 == 3) {
        FUN_06041cc8(param_2);                     /* cd_session_write_poll */
        return 0;
    }
    if (param_1 == 4) {
        cd_session_skip_poll(param_2);
        return 0;
    }
    if (param_1 == 5) {
        cd_session_play_poll(param_2);
        return 0;
    }
    if (param_1 == 6) {
        cd_session_file_batch(param_2);
        return 0;
    }
    if (param_1 != 7) {
        return 0;
    }
    cd_session_read_step(param_2);
    return 0;
}

/* cd_session_sync -- Synchronously wait for CD session to complete.
 * Sets transfer size to 0x8000 (32KB), polls FUN_06041698 until
 * it returns non-1 (complete or error), then clears transfer size. */
int FUN_0604188c(void)
{
    int result;

    *(char **)(CD_SESSION_BASE + 0x3c) = (char *)0x00008000;

    do {
        result = FUN_06041698();
    } while (result == 1);

    *(int *)(CD_SESSION_BASE + 0x3c) = 0;
    return result;
}

/* cd_command_queue_process -- Process CD command queue entries sequentially.
 * Iterates through queue at session+0x5C (16 bytes per entry).
 * Three-state machine at +0x58:
 *   State 1: cd_connect (0x06036380) with channel + filter
 *   State 2: cd_set_sector (0x060362A8) with channel + sector data
 *   State 3: cd_read_cmd (0x060361FC) with channel + callback + userdata
 * After each step: reads cd_result, stores header byte at +0x40.
 * On break (command failure): compacts remaining entries and updates count.
 * Clears dispatch flag (+0x58) when queue empty and CD status bit 0x40 set.
 * Returns remaining queue count. */
int cd_command_queue_process(param_1)
    int *param_1;
{
    int result;
    unsigned short cd_status;
    char *entry;
    int cmd_idx;
    char cd_result[16];
    char *session_ptr = (char *)0x060A5400;

    for (cmd_idx = 0; cmd_idx < *(int *)(*(int *)session_ptr + 0x54); cmd_idx++) {
        /* State 1: connect to channel */
        if (*(int *)(*(int *)session_ptr + 0x58) == 1) {
            entry = (char *)(*(int *)session_ptr + 0x5c + (cmd_idx << 4));
            result = (*(int(*)())0x06036380)((int)*entry, (int)entry[1]);  /* cd_connect */
            if (result != 0) break;
            (*(int(*)())0x060349B6)(cd_result);
            *(char *)(*(int *)session_ptr + 0x40) = cd_result[0];
            *param_1 = *param_1 + 1;
            *(int *)(*(int *)session_ptr + 0x58) = 2;
        }

        /* State 2: set sector parameters */
        if (*(int *)(*(int *)session_ptr + 0x58) == 2) {
            entry = (char *)(*(int *)session_ptr + 0x5c + (cmd_idx << 4));
            result = (*(int(*)())0x060362A8)((int)*entry, entry + 2);  /* cd_set_sector */
            if (result != 0) break;
            (*(int(*)())0x060349B6)(cd_result);
            *(char *)(*(int *)session_ptr + 0x40) = cd_result[0];
            *param_1 = *param_1 + 1;
            if (*(int *)((cmd_idx << 4) + *(int *)session_ptr + 0x68) == 0) {
                *(int *)(*(int *)session_ptr + 0x58) = 1;  /* no callback — next entry */
            } else {
                *(int *)(*(int *)session_ptr + 0x58) = 3;  /* has callback — issue read */
            }
        }

        /* State 3: issue read command with callback */
        if (*(int *)(*(int *)session_ptr + 0x58) == 3) {
            entry = (char *)(*(int *)session_ptr + 0x5c + (cmd_idx << 4));
            result = (*(int(*)())0x060361FC)((int)*entry, *(int *)(entry + 8), *(int *)(entry + 0xc));
            if (result != 0) break;
            (*(int(*)())0x060349B6)(cd_result);
            *(char *)(*(int *)session_ptr + 0x40) = cd_result[0];
            *param_1 = *param_1 + 1;
            *(int *)(*(int *)session_ptr + 0x58) = 1;  /* back to connect for next */
        }
    }

    /* Compact remaining entries if interrupted mid-queue */
    if (cmd_idx < *(int *)(*(int *)session_ptr + 0x54)) {
        int compact_idx = 0;
        for (; cmd_idx < *(int *)(*(int *)session_ptr + 0x54); cmd_idx++) {
            (*(int(*)())0x06035168)(compact_idx, *(int *)session_ptr + 0x5c);  /* copy entry */
            compact_idx++;
        }
        *(int *)(*(int *)session_ptr + 0x54) = compact_idx;
    } else {
        *(int *)(*(int *)session_ptr + 0x54) = 0;  /* all processed */
    }

    /* Clear dispatch flag when queue empty and CD ready */
    cd_status = (*(int(*)())0x06035C4E)();
    if (((cd_status & 0x40) != 0) && (*(int *)(*(int *)session_ptr + 0x54) == 0)) {
        *(int *)(*(int *)session_ptr + 0x58) = 0;
    }

    return *(int *)(*(int *)session_ptr + 0x54);
}

/* cd_session_read_poll -- Poll CD read state and advance on completion.
 * When session state == 1: calls CD read (0x06036144), increments
 * param_1 counter, advances to state 2 on success. Reads disc TOC
 * into local buffer and stores first byte into session +0x40.
 * When state == 2: checks status register bit 6, clears completion
 * field on set. Returns completion field value. */
int FUN_06041aa0(param_1)
    int *param_1;
{
    char *session_ptr = (char *)0x060A5400;     /* CD session pointer */
    int status;
    unsigned short flags;
    char toc_buf[16];

    if (*(int *)((int)DAT_06041b0a + CD_SESSION_BASE) == 1) {
        status = (*(int(*)())0x06036144)(*(int *)(CD_SESSION_BASE + 0x308));
        *param_1 = *param_1 + 1;
        if (status == 0) {
            *(int *)(*(int *)session_ptr + (int)DAT_06041b0a) = 2;
        }
        (*(int(*)())0x060349B6)(toc_buf);
        *(char *)(*(int *)session_ptr + 0x40) = toc_buf[0];
    }

    if ((*(int *)((int)DAT_06041b0a + *(int *)session_ptr) == 2) &&
        (flags = (*(int(*)())0x06035C4E)(), (flags & 0x40) != 0)) {
        *(int *)(*(int *)session_ptr + (int)DAT_06041bc6) = 0;
    }
    return *(int *)((int)DAT_06041bc6 + *(int *)session_ptr);
}

/* cd_dma_transfer_poll -- Poll CD DMA transfer state machine.
 * Three-state machine at DAT_06041bc8/DAT_06041caa offsets:
 *   State 1: Query available sectors via 0x06036572, compute transfer size
 *            (clamped to buffer at +0x318). Store size at *[+0x320].
 *            If no sectors: clear state, optionally clear callback result.
 *            If DMA enabled (+DAT_06041ca8): advance to state 2.
 *   State 2: Acquire lock (+0x34), initiate DMA via 0x060365C4 with
 *            source (+0x310), dest (+0x314), and size (*[+0x320]).
 *            Advance to state 3 on success.
 *   State 3: Poll DMA completion via 0x0603660E. On complete: store
 *            transferred byte count (<<1) at callback pointer, clear lock.
 * Returns 0 (complete), 1 (in progress), or 2 (DMA busy). */
int cd_dma_transfer_poll(param_1)
    int *param_1;
{
    int available_sectors;
    int transfer_size;
    int result;
    int dma_bytes;
    char cd_result[16];
    char *session_ptr = (char *)0x060A5400;

    /* State 1: query and compute transfer size */
    if (*(int *)((int)DAT_06041bc8 + CD_SESSION_BASE) == 1) {
        (*(int(*)())0x06036572)(*(int *)(CD_SESSION_BASE + 0x310), &available_sectors);
        (*(int(*)())0x060349B6)(cd_result);    /* cd_get_result */
        *(char *)(*(int *)session_ptr + 0x40) = cd_result[0];
        *param_1 = *param_1 + 1;

        /* Clamp to buffer capacity */
        transfer_size = available_sectors - *(int *)(*(int *)session_ptr + (int)DAT_06041bcc);
        available_sectors = *(int *)(*(int *)session_ptr + 0x318);
        if (transfer_size < available_sectors) {
            available_sectors = transfer_size;
        }
        **(int **)(*(int *)session_ptr + 0x320) = available_sectors;

        /* No data available: complete immediately */
        if (available_sectors < 1) {
            transfer_size = (int)DAT_06041bc8;
            *(int *)(*(int *)session_ptr + transfer_size) = 0;
            if (*(int *)(*(int *)session_ptr + transfer_size + 0x18) != 0) {
                **(int **)(*(int *)session_ptr + (int)DAT_06041bd2) = 0;
            }
            return 0;
        }

        /* Check if DMA is enabled */
        if (*(int *)(*(int *)session_ptr + (int)DAT_06041ca8) == 0) {
            *(int *)(*(int *)session_ptr + (int)DAT_06041caa) = 0;
            return 0;                          /* no DMA — done */
        }
        *(int *)(*(int *)session_ptr + (int)DAT_06041caa) = 2;  /* advance to DMA */
    }

    /* State 2: initiate DMA transfer */
    if (*(int *)((int)DAT_06041caa + *(int *)session_ptr) == 2) {
        if (*(int *)(*(int *)session_ptr + 0x34) == 1) {
            return 2;                          /* DMA lock held — busy */
        }
        *(int *)(*(int *)session_ptr + 0x34) = 1;  /* acquire lock */

        result = (*(int(*)())0x060365C4)(      /* cd_dma_start */
            *(int *)(*(int *)session_ptr + 0x310),
            *(int *)(*(int *)session_ptr + 0x314),
            **(int **)(*(int *)session_ptr + 0x320));
        if (result != 0) {
            return 2;                          /* DMA start failed */
        }

        (*(int(*)())0x060349B6)(cd_result);
        *(char *)(*(int *)session_ptr + 0x40) = cd_result[0];
        *param_1 = *param_1 + 1;
        *(int *)(*(int *)session_ptr + (int)DAT_06041caa) = 3;
    }

    /* State 3: poll DMA completion */
    if (*(int *)((int)DAT_06041caa + *(int *)session_ptr) == 3) {
        result = (*(int(*)())0x0603660E)(&dma_bytes);  /* cd_dma_poll */
        if (result == 0) {
            (*(int(*)())0x060349B6)(cd_result);
            *(char *)(*(int *)session_ptr + 0x40) = cd_result[0];
            *param_1 = *param_1 + 1;

            transfer_size = (int)DAT_06041caa;
            *(int *)(*(int *)session_ptr + transfer_size) = 0;  /* clear state */
            **(int **)(*(int *)session_ptr + transfer_size + 0x18) = dma_bytes << 1;  /* store byte count */
            *(int *)(*(int *)session_ptr + 0x34) = 0;  /* release lock */
            return 0;                          /* complete */
        }
        return 1;                              /* DMA in progress */
    }

    return 1;
}

/* cd_session_write_poll -- Poll CD write state and advance on completion.
 * When state == 1 at session +0x328: calls CD write (0x060367E8) with
 * 3 session parameters. On failure returns 1 (busy). On success reads
 * TOC, stores first byte, increments counter, advances to state 2.
 * When state == 2: calls finalize (0x06034C68). Returns 0 on complete,
 * 1 if still in progress. */
int FUN_06041cc8(param_1)
    int *param_1;
{
    char *session_ptr = (char *)0x060A5400;     /* CD session pointer */
    int result;
    char toc_buf[16];

    if (*(int *)(0x328 + CD_SESSION_BASE) == 1) {
        int param_off = (int)DAT_06041d5a;
        result = (*(int(*)())0x060367E8)(*(int *)(CD_SESSION_BASE + param_off + -8),
                                         *(int *)(CD_SESSION_BASE + param_off + -4),
                                         *(int *)(CD_SESSION_BASE + param_off));
        if (result != 0) {
            return 1;
        }
        (*(int(*)())0x060349B6)(toc_buf);
        *(char *)(*(int *)session_ptr + 0x40) = toc_buf[0];
        *param_1 = *param_1 + 1;
        *(int *)(*(int *)session_ptr + 0x328) = 2;
    }

    if ((*(int *)(0x328 + *(int *)session_ptr) == 2) &&
        (result = (*(int(*)())0x06034C68)(0), result == 0)) {
        *(int *)(*(int *)session_ptr + 0x328) = 0;
        return 0;
    }
    return 1;
}

/* cd_session_skip_poll -- Poll CD skip/seek state machine.
 * Four-state machine at session +0x338:
 *   State 1: If filter=0xFFFF and no offset, set default filter (0x060364D4)
 *            → state 4. If filter=0, complete immediately. Else → state 2.
 *   State 2: Issue skip command (0x0603683C) → state 3 on success.
 *   State 3: Poll status bits (PTR_DAT_06041eb8). Complete when set.
 *   State 4: Poll status bit 0x40. Complete when set.
 * On completion: acknowledge (0xFFF7), clear state and lock.
 * Returns 1 (busy) or 0 (complete). */
int cd_session_skip_poll(param_1)
    int *param_1;
{
    int busy = 1;
    int result;
    unsigned short cd_status;
    unsigned short completion_mask;
    char cd_result[16];
    char *session_ptr = (char *)0x060A5400;

    /* State 1: determine skip mode */
    if (*(int *)(CD_SESSION_BASE + 0x338) == 1) {
        if ((*(int *)(CD_SESSION_BASE + 0x340) == 0) &&
           (*(char **)(CD_SESSION_BASE + (int)DAT_06041df0) == (char *)0x0000FFFF)) {
            /* Default filter mode: set filter and skip to state 4 */
            result = (*(int(*)())0x060364D4)(0, *(int *)(CD_SESSION_BASE + (int)DAT_06041df2));
            if (result != 0) return 1;
            (*(int(*)())0x060349B6)(cd_result);
            *(char *)(*(int *)session_ptr + 0x40) = cd_result[0];
            *param_1 = *param_1 + 1;
            *(int *)(*(int *)session_ptr + 0x338) = 4;
        } else if (*(int *)(CD_SESSION_BASE + (int)DAT_06041df0) == 0) {
            busy = 0;                          /* no filter — done immediately */
        } else {
            *(int *)(CD_SESSION_BASE + 0x338) = 2;  /* normal skip */
        }
    }

    /* State 2: issue skip command */
    if (*(int *)(0x338 + *(int *)session_ptr) == 2) {
        int param_off = (int)DAT_06041eb6;
        result = (*(int(*)())0x0603683C)(      /* cd_skip_sectors */
            *(int *)(*(int *)session_ptr + param_off + -8),
            *(int *)(*(int *)session_ptr + param_off + -4),
            *(int *)(*(int *)session_ptr + param_off));
        *param_1 = *param_1 + 1;
        if (result == 0) {
            *(int *)(*(int *)session_ptr + 0x338) = 3;
            (*(int(*)())0x060349B6)(cd_result);
            *(char *)(*(int *)session_ptr + 0x40) = cd_result[0];
        }
    }

    /* State 3: poll for skip completion */
    completion_mask = PTR_DAT_06041eb8;
    if ((*(int *)(0x338 + *(int *)session_ptr) == 3) &&
       (cd_status = (*(int(*)())0x06035C4E)(), (cd_status & completion_mask) != 0)) {
        busy = 0;
    }

    /* State 4: poll for filter completion (bit 0x40) */
    if ((*(int *)(0x338 + *(int *)session_ptr) == 4) &&
       (cd_status = (*(int(*)())0x06035C4E)(), (cd_status & 0x40) != 0)) {
        busy = 0;
    }

    /* On completion: acknowledge and clear state */
    if (!busy) {
        (*(int(*)())0x06035C54)(0x0000FFF7);   /* cd_acknowledge */
        *(int *)(*(int *)session_ptr + (int)DAT_06041f90) = 0;
        *(int *)(*(int *)session_ptr + 0x34) = 0;  /* release lock */
    }

    return busy;
}

/* cd_session_play_poll -- Poll CD audio play/stream state machine.
 * Five-state machine at session +0x348:
 *   State 1: Set up filter (0x060363BC), connect channel (0x06036380).
 *   State 2: Issue play command (0x0603697C) with 4 parameters.
 *   State 3: Poll status bits (DAT_0604207c), advance to state 4.
 *   State 4: Reconnect channel (0x06036380) for playback monitoring.
 *   State 5: Poll status bit 0x40, return to state 0 (complete).
 * Returns state value (0=done, 1-5=in progress). */
int cd_session_play_poll(param_1)
    int *param_1;
{
    int result;
    unsigned short cd_status;
    unsigned short play_mask;
    char cd_result[16];
    char *session_ptr = (char *)0x060A5400;

    /* State 1: configure filter and connect channel */
    if (*(int *)(0x348 + CD_SESSION_BASE) == 1) {
        (*(int(*)())0x060363BC)(               /* cd_set_filter */
            *(int *)(CD_SESSION_BASE + (int)DAT_06041f96),
            CD_SESSION_BASE + (int)DAT_06041f94);
        *param_1 = *param_1 + 1;
        (*(int(*)())0x060349B6)(cd_result);
        *(char *)(*(int *)session_ptr + 0x40) = cd_result[0];

        result = (*(int(*)())0x06036380)(      /* cd_connect */
            *(int *)(*(int *)session_ptr + (int)DAT_06041f96), 0);
        if (result != 0) return 1;

        (*(int(*)())0x060349B6)(cd_result);
        *(char *)(*(int *)session_ptr + 0x40) = cd_result[0];
        *param_1 = *param_1 + 1;
        *(int *)(*(int *)session_ptr + 0x348) = 2;
    }

    /* State 2: issue play command */
    if (*(int *)(0x348 + *(int *)session_ptr) == 2) {
        int param_off = (int)DAT_06041f96;
        result = (*(int(*)())0x0603697C)(      /* cd_play */
            *(int *)(*(int *)session_ptr + param_off + 4),
            *(int *)(*(int *)session_ptr + param_off + 8),
            *(int *)(*(int *)session_ptr + param_off + 0xc),
            *(int *)(*(int *)session_ptr + param_off));
        if (result != 0) return 1;

        (*(int(*)())0x060349B6)(cd_result);
        *(char *)(*(int *)session_ptr + 0x40) = cd_result[0];
        *param_1 = *param_1 + 1;
        *(int *)(*(int *)session_ptr + 0x348) = 3;
    }

    /* State 3: poll for play start */
    play_mask = DAT_0604207c;
    if ((*(int *)(0x348 + *(int *)session_ptr) == 3) &&
       (cd_status = (*(int(*)())0x06035C4E)(), (cd_status & play_mask) != 0)) {
        *(int *)(*(int *)session_ptr + 0x348) = 4;
    }

    /* State 4: reconnect channel for monitoring */
    if (*(int *)(0x348 + *(int *)session_ptr) == 4) {
        result = (*(int(*)())0x06036380)(      /* cd_connect */
            *(int *)(*(int *)session_ptr + DAT_0604207e + -0x10),
            *(int *)(*(int *)session_ptr + (int)DAT_0604207e));
        if (result != 0) return 1;
        *param_1 = *param_1 + 1;
        *(int *)(*(int *)session_ptr + 0x348) = 5;
    }

    /* State 5: poll for playback completion (bit 0x40) */
    if ((*(int *)(0x348 + *(int *)session_ptr) == 5) &&
       (cd_status = (*(int(*)())0x06035C4E)(), (cd_status & 0x40) != 0)) {
        *(int *)(*(int *)session_ptr + 0x348) = 0;  /* complete */
    }

    return *(int *)(0x348 + *(int *)session_ptr);
}

/* --- FUN_060400D6 (L1 import from src/FUN_060400D6.c) --- */

unsigned int * FUN_060400d6(param_1, param_2, param_3)
    unsigned int *param_1;
    unsigned int *param_2;
    unsigned int param_3;
{

  int iVar1;

  unsigned int uVar2;

  unsigned int local_20;

  int uStack_1c;

  char uStack_18;

  char uStack_17;

  char uStack_16;

  char uStack_15;

  if (param_2 == (unsigned int *)0x0) {

    *param_1 = 0x40000000 | param_3;

    iVar1 = (*(int(*)())0x060415C8)(param_3,&local_20);

    if (iVar1 != 0) {

      return (unsigned int *)0x0;

    }

    param_1[1] = local_20;

    uVar2 = FUN_060400b4(uStack_15);

    param_1[3] = uVar2;

    uVar2 = (*(int(*)())0x06035F44)();

    param_1[4] = uVar2;

    (*(int(*)())0x06036BE4)(uStack_1c);

    uVar2 = (*(int(*)())0x06036BE4)();

    param_1[5] = uVar2;

    *(char *)(param_1 + 7) = uStack_16;

    *(char *)((int)param_1 + 0x1d) = uStack_15;

    *(char *)((int)param_1 + 0x1e) = uStack_18;

    *(char *)((int)param_1 + 0x1f) = uStack_17;

  }

  else {

    *param_1 = param_3;

    param_1[1] = *param_2;

    uVar2 = FUN_060400b4(*(char *)((int)param_2 + 0xb));

    param_1[3] = uVar2;

    param_1[4] = (int)DAT_060401e8 + param_2[1] >> 0xb;

    (*(int(*)())0x06036BE4)();

    uVar2 = (*(int(*)())0x06036BE4)();

    param_1[5] = uVar2;

    *(char *)(param_1 + 7) = *(char *)((int)param_2 + 10);

    *(char *)((int)param_1 + 0x1d) = *(char *)((int)param_2 + 0xb);

    *(char *)((int)param_1 + 0x1e) = *(char *)(param_2 + 2);

    *(char *)((int)param_1 + 0x1f) = *(char *)((int)param_2 + 9);

  }

  param_1[6] = 0;

  param_1[9] = 0;

  param_1[8] = 0;

  param_1[10] = 0x7FFFFFFF;

  return param_1;

}

/* --- FUN_0604077C (L1 import from src/FUN_0604077C.c) --- */

int * FUN_0604077C(param_1, param_2, param_3, param_4, param_5)
    int *param_1;
    int param_2;
    int param_3;
    char param_4;
    int param_5;
{

  int iVar1;

  int local_1c;

  int uStack_18;

  char local_14;

  char uStack_13;

  char uStack_12;

  char uStack_11;

  char uStack_10;

  char uStack_f;

  *param_1 = param_2;

  param_1[2] = 0;

  *(char *)(param_1 + 6) = param_4;

  param_1[3] = param_3;

  param_1[4] = 0;

  param_1[8] = 1;

  *(char *)((int)param_1 + 0x19) = 0;

  *(char *)((int)param_1 + 0x1a) = 0;

  *(char *)((int)param_1 + 0x1b) = 0;

  param_1[9] = (unsigned int)param_5;

  local_14 = *(char *)(param_1 + 6);

  uStack_13 = *(char *)((int)param_1 + 0x19);

  uStack_12 = 0;

  uStack_11 = 0;

  uStack_10 = 0;

  uStack_f = 0;

  (*(int(*)())0x06035228)();

  param_1[10] = 0xffffffff;

  iVar1 = (*(int(*)())0x06040EEC)(&uStack_18);

  if (iVar1 == 0) {

    param_1[1] = uStack_18;

    iVar1 = (*(int(*)())0x06040E88)(&local_1c);

    if (iVar1 == 0) {

      param_1[5] = local_1c;

      iVar1 = (*(int(*)())0x06041034)(local_1c,param_1[8],&local_14,0,0);

      if (iVar1 == 0) {

        iVar1 = (*(int(*)())0x060414D0)(local_1c,uStack_18,(int)DAT_0604089c);

        if (iVar1 == 0) {

          iVar1 = (*(int(*)())0x0604188C)();

          if (iVar1 != 0) {

            param_1 = (int *)0x0;

          }

        }

        else {

          param_1 = (int *)0x0;

        }

      }

      else {

        param_1 = (int *)0x0;

      }

    }

    else {

      (*(int(*)())0x06040F16)(uStack_18);

      param_1 = (int *)0x0;

    }

  }

  else {

    param_1 = (int *)0x0;

  }

  return param_1;

}

/* --- FUN_060409E6 (L1 import from src/FUN_060409E6.c) --- */

int FUN_060409e6(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  int iVar2;

  int iVar3;

  int local_1c;

  int iStack_18;

  puVar1 = (char *)0x0604188C;

  if (param_2 < 0) {

    param_2 = 0;

  }

  if (param_3 == 1) {

    iVar2 = *(int *)(param_1 + 8) + *(int *)(param_1 + 0x10) + param_2;

    local_1c = param_2;

  }

  else {

    if (*(int *)(param_1 + 8) + *(int *)(param_1 + 0x10) == param_2) {

      return param_2;

    }

    iVar2 = (*(int(*)())0x060411A0)(*(int *)(param_1 + 4),0,0x0000FFFF,&local_1c,0)

    ;

    if (iVar2 != 0) {

      return -1;

    }

    iVar2 = (*(int(*)())puVar1)();

    if (iVar2 != 0) {

      return -1;

    }

    iVar2 = param_2;

    if (local_1c < 0) {

      local_1c = 0;

    }

  }

  if (*(int *)(param_1 + 0x24) == 0) {

    if ((*(int *)(param_1 + 8) <= iVar2) &&

       (iVar2 < *(int *)(param_1 + 0x10) + *(int *)(param_1 + 8))) {

      local_1c = iVar2 - *(int *)(param_1 + 8);

    }

    if (0 < local_1c) {

      (*(int(*)())0x060412B2)(*(int *)(param_1 + 4),0,local_1c);

      iVar3 = (*(int(*)())puVar1)();

      if (iVar3 != 0) {

        return -1;

      }

    }

    *(int *)(param_1 + 8) = iVar2;

    *(int *)(param_1 + 0x10) = 0;

  }

  else if (*(int *)(param_1 + 0x24) == 1) {

    if ((iVar2 < *(int *)(param_1 + 8)) ||

       (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 8) + 1 < iVar2)) {

      iStack_18 = param_1;

      (*(int(*)())0x060412B2)(*(int *)(param_1 + 4),0,0x0000FFFF);

      iVar3 = (*(int(*)())puVar1)();

      if (iVar3 == 0) {

        return -1;

      }

      *(int *)(param_1 + 8) = iVar2;

    }

    *(int *)(param_1 + 0x10) = iVar2 - *(int *)(param_1 + 8);

  }

  return *(int *)(param_1 + 8) + *(int *)(param_1 + 0x10);

}

/* --- FUN_06040C98 (L1 import from src/FUN_06040C98.c) --- */

int FUN_06040c98(param_1, param_2)
    int param_1;
    int param_2;
{

  int bVar1;

  char *puVar2;

  char *puVar3;

  char *puVar4;

  unsigned char bVar8;

  int iVar5;

  unsigned short uVar6;

  unsigned short uVar7;

  int iVar9;

  int iVar10;

  int iVar11;

  unsigned char local_30 [4];

  unsigned char local_2c [16];

  puVar4 = (char *)0x0604231E;

  puVar3 = (char *)0x060A5400;

  puVar2 = (char *)0x06034984;

  iVar11 = (int)DAT_06040d2c;

  *(int *)0x060A5400 = param_1;

  (*(int(*)())puVar4)();

  if (param_2 == 0) {

    *(char *)(*(int *)puVar3 + 0x17) = 0;

    *(char *)(*(int *)puVar3 + 0x2f) = 0;

  }

  else {

    *(char *)(*(int *)puVar3 + 0x17) = 1;

    *(char *)(*(int *)puVar3 + 0x2f) = 1;

  }

  (*(int(*)())puVar2)(local_2c);

  bVar8 = local_2c[0] & 0xf;

  if (bVar8 == 6) {

    return 0xfffffff3;

  }

  if (bVar8 == 7) {

    return 0xfffffff2;

  }

  if ((bVar8 != 9) && (bVar8 != 10)) {

    iVar5 = (*(int(*)())0x06034B9A)(iVar11,0x0000FFFF,iVar11,iVar11);

    if (iVar5 != 0) {

      return 0xfffffffe;

    }

    iVar5 = 0;

    bVar1 = 0;

    while (uVar7 = DAT_06040dc0, !bVar1) {

      uVar6 = (*(int(*)())0x06035C4E)();

      if ((uVar6 & uVar7) != 0) {

        (*(int(*)())0x06035C54)(0x0000FBFF);

        iVar5 = iVar5 + 1;

        if (DAT_06040dc2 < iVar5) {

          return 0xfffffffe;

        }

        (*(int(*)())puVar2)(local_2c);

        bVar8 = local_2c[0] & 0xf;

        if ((bVar8 == 1) || (bVar8 == 2)) {

          bVar1 = 1;

        }

        else if ((bVar8 == 9) || (bVar8 == 10)) {

          return 0xfffffff6;

        }

      }

    }

    iVar9 = (int)PTR_DAT_06040dc4;

    iVar10 = *(int *)0x060A4D14;

    iVar5 = (*(int(*)())0x06034AEE)(iVar10 + iVar9);

    if (iVar5 != 0) {

      return 0xfffffffe;

    }

    (*(int(*)())0x06034B54)(0,local_30);

    (*(int(*)())0x06034B54)(local_30[0],local_30);

    if ((*(unsigned int *)(iVar10 + iVar9 + (local_30[0] - 1) << 2) & 0x40000000) == 0) {

      return 0xfffffff1;

    }

    (*(int(*)())0x060364D4)((int)DAT_06040e72,iVar11);

    *(char **)(*(int *)puVar3 + 0x3c) = 0x00008000;

    do {

      uVar7 = (*(int(*)())0x06035C4E)();

      if ((uVar7 & 0x40) != 0) {

        *(int *)(*(int *)puVar3 + 0x3c) = 0;

        (*(int(*)())puVar2)(*(int *)puVar3 + 0x40);

        return 0;

      }

      iVar11 = *(int *)(*(int *)puVar3 + 0x3c) + -1;

      *(int *)(*(int *)puVar3 + 0x3c) = iVar11;

    } while (iVar11 != 0);

    return 0xfffffffe;

  }

  return 0xfffffff6;

}

/* --- FUN_06041034 (L1 import from src/FUN_06041034.c) --- */

int FUN_06041034(param_1, param_2, param_3, param_4, param_5)
    int param_1;
    int param_2;
    int param_3;
    int param_4;
    int param_5;
{

  char *puVar1;

  int uVar2;

  int iVar3;

  char auStack_10 [8];

  puVar1 = (char *)0x060A5400;

  iVar3 = *(int *)(*(int *)0x060A5400 + 0x54);

  if (*(char *)(param_1 + *(int *)0x060A5400 + 0x18) == '\x01') {

    if (iVar3 < 0x18) {

      if (*(int *)(*(int *)0x060A5400 + 0x58) == 0) {

        *(int *)(*(int *)0x060A5400 + 0x58) = 1;

      }

      iVar3 = (iVar3 << 4);

      *(char *)(*(int *)puVar1 + 0x5c + iVar3) = (char)param_1;

      *(char *)(*(int *)puVar1 + iVar3 + 0x5d) = param_2;

      (*(int(*)())0x06035228)();

      *(int *)(*(int *)puVar1 + iVar3 + 100) = param_4;

      *(int *)(iVar3 + *(int *)puVar1 + 0x68) = param_5;

      *(int *)(*(int *)puVar1 + 0x54) = *(int *)(*(int *)puVar1 + 0x54) + 1;

      FUN_060418be(auStack_10);

      uVar2 = 0;

    }

    else {

      uVar2 = 0xfffffff8;

    }

  }

  else {

    uVar2 = 0xfffffff9;

  }

  return uVar2;

}

/* --- FUN_060414D0 (L1 import from src/FUN_060414D0.c) --- */

int FUN_060414d0(param_1, param_2, param_3)
    int param_1;
    int param_2;
    int param_3;
{

  char *puVar1;

  int iVar2;

  int iVar3;

  char auStack_c [8];

  puVar1 = (char *)0x060A5400;

  iVar3 = (int)DAT_0604155e;

  iVar2 = *(int *)(*(int *)0x060A5400 + (int)DAT_0604155c);

  if ((((param_1 != iVar3) && (param_1 != -2)) && ((param_1 < 0 || (0x17 < param_1)))) ||

     (((param_2 < 0 || (0x17 < param_2)) ||

      ((param_3 != iVar3 && ((param_3 != -2 && ((param_3 < 0 || (0x17 < param_3)))))))))) {

    return 0xfffffffa;

  }

  if (((param_1 == iVar3) ||

      ((param_1 == -2 || (*(char *)(param_1 + *(int *)0x060A5400 + 0x18) == '\x01')))) &&

     (((param_3 == iVar3 ||

       ((param_3 == -2 || (*(char *)(param_3 + *(int *)0x060A5400 + 0x18) == '\x01')))) &&

      (*(char *)(param_2 + *(int *)0x060A5400) == '\x01')))) {

    if (0x17 < iVar2) {

      return 0xfffffff8;

    }

    if (*(int *)(*(int *)0x060A5400 + 0x1e0) == 0) {

      *(int *)(*(int *)0x060A5400 + 0x1e0) = 1;

    }

    iVar3 = (int)(short)((short)iVar2 * 0xc);

    iVar2 = (int)DAT_060415ee;

    *(int *)(*(int *)puVar1 + iVar2 + iVar3) = param_1;

    *(int *)(iVar2 + *(int *)puVar1 + iVar3 + 4) = param_2;

    *(int *)(iVar3 + (int)DAT_060415ee + *(int *)puVar1 + 8) = param_3;

    *(int *)(*(int *)puVar1 + (int)PTR_DAT_060415f0) =

         *(int *)(*(int *)puVar1 + (int)PTR_DAT_060415f0) + 1;

    FUN_06042134(auStack_c);

    return 0;

  }

  return 0xfffffff9;

}

/* --- FUN_060418BE (L1 import from src/FUN_060418BE.c) --- */

int FUN_060418be(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  unsigned short uVar4;

  char *pcVar5;

  int iVar6;

  char local_2c [16];

  puVar2 = (char *)0x060349B6;

  puVar1 = (char *)0x060A5400;

  for (iVar6 = 0; iVar6 < *(int *)(*(int *)puVar1 + 0x54); iVar6 = iVar6 + 1) {

    if (*(int *)(*(int *)puVar1 + 0x58) == 1) {

      pcVar5 = (char *)(*(int *)puVar1 + 0x5c + (iVar6 << 4));

      iVar3 = (*(int(*)())0x06036380)((int)*pcVar5,(int)pcVar5[1]);

      if (iVar3 != 0) break;

      (*(int(*)())puVar2)(local_2c);

      *(char *)(*(int *)puVar1 + 0x40) = local_2c[0];

      *param_1 = *param_1 + 1;

      *(int *)(*(int *)puVar1 + 0x58) = 2;

    }

    if (*(int *)(*(int *)puVar1 + 0x58) == 2) {

      pcVar5 = (char *)(*(int *)puVar1 + 0x5c + (iVar6 << 4));

      iVar3 = (*(int(*)())0x060362A8)((int)*pcVar5,pcVar5 + 2);

      if (iVar3 != 0) break;

      (*(int(*)())puVar2)(local_2c);

      *(char *)(*(int *)puVar1 + 0x40) = local_2c[0];

      *param_1 = *param_1 + 1;

      if (*(int *)((iVar6 << 4) + *(int *)puVar1 + 0x68) == 0) {

        *(int *)(*(int *)puVar1 + 0x58) = 1;

      }

      else {

        *(int *)(*(int *)puVar1 + 0x58) = 3;

      }

    }

    if (*(int *)(*(int *)puVar1 + 0x58) == 3) {

      pcVar5 = (char *)(*(int *)puVar1 + 0x5c + (iVar6 << 4));

      iVar3 = (*(int(*)())0x060361FC)((int)*pcVar5,*(int *)(pcVar5 + 8),*(int *)(pcVar5 + 0xc));

      if (iVar3 != 0) break;

      (*(int(*)())puVar2)(local_2c);

      *(char *)(*(int *)puVar1 + 0x40) = local_2c[0];

      *param_1 = *param_1 + 1;

      *(int *)(*(int *)puVar1 + 0x58) = 1;

    }

  }

  if (iVar6 < *(int *)(*(int *)puVar1 + 0x54)) {

    iVar3 = 0;

    for (; iVar6 < *(int *)(*(int *)puVar1 + 0x54); iVar6 = iVar6 + 1) {

      (*(int(*)())0x06035168)(iVar3,*(int *)puVar1 + 0x5c);

      iVar3 = iVar3 + 1;

    }

    *(int *)(*(int *)puVar1 + 0x54) = iVar3;

  }

  else {

    *(int *)(*(int *)puVar1 + 0x54) = 0;

  }

  uVar4 = (*(int(*)())0x06035C4E)();

  if (((uVar4 & 0x40) != 0) && (*(int *)(*(int *)puVar1 + 0x54) == 0)) {

    *(int *)(*(int *)puVar1 + 0x58) = 0;

  }

  return *(int *)(*(int *)puVar1 + 0x54);

}

/* --- FUN_06041B3C (L1 import from src/FUN_06041B3C.c) --- */

int FUN_06041b3c(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  int uVar3;

  int iVar4;

  int local_28;

  int iStack_24;

  char local_20 [16];

  puVar2 = (char *)0x060A5400;

  puVar1 = (char *)0x060349B6;

  if (*(int *)((int)DAT_06041bc8 + *(int *)0x060A5400) == 1) {

    (*(int(*)())0x06036572)(*(int *)(*(int *)0x060A5400 + 0x310),&local_28);

    (*(int(*)())puVar1)(local_20);

    *(char *)(*(int *)puVar2 + 0x40) = local_20[0];

    *param_1 = *param_1 + 1;

    iVar4 = local_28 - *(int *)(*(int *)puVar2 + (int)DAT_06041bcc);

    local_28 = *(int *)(*(int *)puVar2 + 0x318);

    if (iVar4 < local_28) {

      local_28 = iVar4;

    }

    **(int **)(*(int *)puVar2 + 0x320) = local_28;

    if (local_28 < 1) {

      iVar4 = (int)DAT_06041bc8;

      *(int *)(*(int *)puVar2 + iVar4) = 0;

      if (*(int *)(*(int *)puVar2 + iVar4 + 0x18) != 0) {

        **(int **)(*(int *)puVar2 + (int)DAT_06041bd2) = 0;

      }

      return 0;

    }

    if (*(int *)(*(int *)puVar2 + (int)DAT_06041ca8) == 0) {

      *(int *)(*(int *)puVar2 + (int)DAT_06041caa) = 0;

      return 0;

    }

    *(int *)(*(int *)puVar2 + (int)DAT_06041caa) = 2;

  }

  if (*(int *)((int)DAT_06041caa + *(int *)puVar2) == 2) {

    if (*(int *)(*(int *)puVar2 + 0x34) == 1) {

      return 2;

    }

    *(int *)(*(int *)puVar2 + 0x34) = 1;

    iVar4 = 0x320;

    iVar4 = (*(int(*)())0x060365C4)(*(int *)(*(int *)puVar2 + iVar4 + -0x10),

                       *(int *)(*(int *)puVar2 + iVar4 + -0xc),

                       **(int **)(*(int *)puVar2 + iVar4));

    if (iVar4 != 0) {

      return 2;

    }

    (*(int(*)())puVar1)(local_20);

    *(char *)(*(int *)puVar2 + 0x40) = local_20[0];

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar2 + (int)DAT_06041caa) = 3;

  }

  if (*(int *)((int)DAT_06041caa + *(int *)puVar2) == 3) {

    iVar4 = (*(int(*)())0x0603660E)(&iStack_24);

    if (iVar4 == 0) {

      (*(int(*)())puVar1)(local_20);

      *(char *)(*(int *)puVar2 + 0x40) = local_20[0];

      *param_1 = *param_1 + 1;

      iVar4 = (int)DAT_06041caa;

      *(int *)(*(int *)puVar2 + iVar4) = 0;

      **(int **)(*(int *)puVar2 + iVar4 + 0x18) = iStack_24 << 1;

      *(int *)(*(int *)puVar2 + 0x34) = 0;

      uVar3 = 0;

    }

    else {

      uVar3 = 1;

    }

  }

  else {

    uVar3 = 1;

  }

  return uVar3;

}

/* --- FUN_06041D6C (L1 import from src/FUN_06041D6C.c) --- */

int FUN_06041d6c(param_1)
    int *param_1;
{

  int bVar1;

  char *puVar2;

  int iVar3;

  unsigned short uVar4;

  unsigned short uVar5;

  char local_1c [16];

  puVar2 = (char *)0x060A5400;

  bVar1 = 1;

  if (*(int *)(*(int *)0x060A5400 + 0x338) == 1) {

    if ((*(int *)(*(int *)0x060A5400 + 0x340) == 0) &&

       (*(char **)(*(int *)0x060A5400 + (int)DAT_06041df0) == 0x0000FFFF)) {

      iVar3 = (*(int(*)())0x060364D4)(0,*(int *)(*(int *)0x060A5400 + (int)DAT_06041df2));

      if (iVar3 != 0) {

        return 1;

      }

      (*(int(*)())0x060349B6)(local_1c);

      *(char *)(*(int *)puVar2 + 0x40) = local_1c[0];

      *param_1 = *param_1 + 1;

      *(int *)(*(int *)puVar2 + 0x338) = 4;

    }

    else if (*(int *)(*(int *)0x060A5400 + (int)DAT_06041df0) == 0) {

      bVar1 = 0;

    }

    else {

      *(int *)(*(int *)0x060A5400 + 0x338) = 2;

    }

  }

  if (*(int *)(0x338 + *(int *)puVar2) == 2) {

    iVar3 = (int)DAT_06041eb6;

    iVar3 = (*(int(*)())0x0603683C)(*(int *)(*(int *)puVar2 + iVar3 + -8),

                       *(int *)(*(int *)puVar2 + iVar3 + -4),

                       *(int *)(*(int *)puVar2 + iVar3));

    *param_1 = *param_1 + 1;

    if (iVar3 == 0) {

      *(int *)(*(int *)puVar2 + 0x338) = 3;

      (*(int(*)())0x060349B6)(local_1c);

      *(char *)(*(int *)puVar2 + 0x40) = local_1c[0];

    }

  }

  uVar5 = PTR_DAT_06041eb8;

  if ((*(int *)(0x338 + *(int *)puVar2) == 3) &&

     (uVar4 = (*(int(*)())0x06035C4E)(), (uVar4 & uVar5) != 0)) {

    bVar1 = 0;

  }

  if ((*(int *)(0x338 + *(int *)puVar2) == 4) &&

     (uVar5 = (*(int(*)())0x06035C4E)(), (uVar5 & 0x40) != 0)) {

    bVar1 = 0;

  }

  if (!bVar1) {

    (*(int(*)())0x06035C54)(0x0000FFF7);

    *(int *)(*(int *)puVar2 + (int)DAT_06041f90) = 0;

    *(int *)(*(int *)puVar2 + 0x34) = 0;

  }

  return bVar1;

}

/* --- FUN_06041EE8 (L1 import from src/FUN_06041EE8.c) --- */

int FUN_06041ee8(param_1)
    int *param_1;
{

  char *puVar1;

  char *puVar2;

  int iVar3;

  unsigned short uVar4;

  unsigned short uVar5;

  char local_1c [16];

  puVar2 = (char *)0x060A5400;

  puVar1 = (char *)0x060349B6;

  if (*(int *)(0x348 + *(int *)0x060A5400) == 1) {

    (*(int(*)())0x060363BC)(*(int *)(*(int *)0x060A5400 + (int)DAT_06041f96),

               *(int *)0x060A5400 + (int)DAT_06041f94);

    *param_1 = *param_1 + 1;

    (*(int(*)())puVar1)(local_1c);

    *(char *)(*(int *)puVar2 + 0x40) = local_1c[0];

    iVar3 = (*(int(*)())0x06036380)(*(int *)(*(int *)puVar2 + (int)DAT_06041f96),0);

    if (iVar3 != 0) {

      return 1;

    }

    (*(int(*)())puVar1)(local_1c);

    *(char *)(*(int *)puVar2 + 0x40) = local_1c[0];

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar2 + 0x348) = 2;

  }

  if (*(int *)(0x348 + *(int *)puVar2) == 2) {

    iVar3 = (int)DAT_06041f96;

    iVar3 = (*(int(*)())0x0603697C)(*(int *)(*(int *)puVar2 + iVar3 + 4),

                       *(int *)(*(int *)puVar2 + iVar3 + 8),

                       *(int *)(*(int *)puVar2 + iVar3 + 0xc),

                       *(int *)(*(int *)puVar2 + iVar3));

    if (iVar3 != 0) {

      return 1;

    }

    (*(int(*)())puVar1)(local_1c);

    *(char *)(*(int *)puVar2 + 0x40) = local_1c[0];

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar2 + 0x348) = 3;

  }

  uVar5 = DAT_0604207c;

  if ((*(int *)(0x348 + *(int *)puVar2) == 3) &&

     (uVar4 = (*(int(*)())0x06035C4E)(), (uVar4 & uVar5) != 0)) {

    *(int *)(*(int *)puVar2 + 0x348) = 4;

  }

  if (*(int *)(0x348 + *(int *)puVar2) == 4) {

    iVar3 = (*(int(*)())0x06036380)(*(int *)(*(int *)puVar2 + DAT_0604207e + -0x10),

                       *(int *)(*(int *)puVar2 + (int)DAT_0604207e));

    if (iVar3 != 0) {

      return 1;

    }

    *param_1 = *param_1 + 1;

    *(int *)(*(int *)puVar2 + 0x348) = 5;

  }

  if ((*(int *)(0x348 + *(int *)puVar2) == 5) &&

     (uVar5 = (*(int(*)())0x06035C4E)(), (uVar5 & 0x40) != 0)) {

    *(int *)(*(int *)puVar2 + 0x348) = 0;

  }

  return *(int *)(0x348 + *(int *)puVar2);

}
