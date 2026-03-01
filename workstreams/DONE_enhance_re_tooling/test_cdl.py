#!/usr/bin/env python3
"""Test E2: Code/Data Logging in Mednafen.

Boots to mode select menu, runs CDL for several frames,
dumps the bitmap, and verifies code/data coverage.
"""
import sys, os, tempfile, time

# Import from workstreams/empirical_validation/
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', 'empirical_validation'))
from investigate import MednafenBot, GAME_STATES, parse_trace, replay_to_state, wsl_path

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
CUE = os.path.join(PROJECT, 'build', 'disc', 'rebuilt_disc', 'daytona_rebuilt.cue')
TRACE = os.path.join(PROJECT, 'build', 'golden_trace', 'arcade_full.txt')

def main():
    ipc_dir = os.path.join(tempfile.gettempdir(), 'mednafen_cdl_test')
    os.makedirs(ipc_dir, exist_ok=True)

    cue_wsl = wsl_path(CUE)
    cdl_wsl = wsl_path(os.path.join(ipc_dir, 'cdl_test.bin'))
    cdl_win = os.path.join(ipc_dir, 'cdl_test.bin')

    bot = MednafenBot(ipc_dir, cue_wsl)
    if not bot.start(timeout=30):
        print('FAIL: Mednafen did not start')
        return 1

    try:
        # Deterministic mode
        bot.send_and_wait('deterministic', 'ok deterministic')

        # Replay to menu
        trace_events = parse_trace(TRACE)
        if not replay_to_state(bot, 'menu', trace_events):
            print('FAIL: replay_to_state failed')
            return 1
        print(f'At menu, frame={bot.current_frame}')

        # Start CDL
        resp = bot.send_and_wait('cdl_start', 'ok cdl_start')
        print(f'CDL start: {resp}')

        # Run 60 frames (1 second of gameplay)
        bot.frame_advance(60)
        print(f'Advanced 60 frames, now at frame={bot.current_frame}')

        # Dump CDL
        resp = bot.send_and_wait(f'cdl_dump {cdl_wsl}', 'ok cdl_dump')
        print(f'CDL dump: {resp}')

        # Stop CDL
        bot.send_and_wait('cdl_stop', 'ok cdl_stop')

        # Check status
        resp = bot.send_and_wait('cdl_status', 'ok cdl_status')
        print(f'CDL status after stop: {resp}')

        bot.send_and_wait('quit', 'ok quit')
    except Exception as e:
        print(f'ERROR: {e}')
        import traceback; traceback.print_exc()
        bot.kill()
        return 1

    # Wait for file
    deadline = time.time() + 5
    while time.time() < deadline and not os.path.exists(cdl_win):
        time.sleep(0.2)

    if not os.path.exists(cdl_win):
        print(f'FAIL: CDL file not created at {cdl_win}')
        return 1

    data = open(cdl_win, 'rb').read()
    if len(data) != 0x100000:
        print(f'FAIL: CDL file size {len(data)}, expected 1048576')
        return 1

    # Count coverage
    code_bytes = sum(1 for b in data if b & 0x01)
    read_bytes = sum(1 for b in data if b & 0x02)
    write_bytes = sum(1 for b in data if b & 0x04)
    total = len(data)
    touched = sum(1 for b in data if b != 0)

    print(f'\n=== CDL Results (60 frames at mode select) ===')
    print(f'Total WRAM High: {total:,} bytes')
    print(f'CODE:       {code_bytes:,} bytes ({100*code_bytes/total:.2f}%)')
    print(f'DATA_READ:  {read_bytes:,} bytes ({100*read_bytes/total:.2f}%)')
    print(f'DATA_WRITE: {write_bytes:,} bytes ({100*write_bytes/total:.2f}%)')
    print(f'Any access: {touched:,} bytes ({100*touched/total:.2f}%)')
    print(f'Untouched:  {total-touched:,} bytes ({100*(total-touched)/total:.2f}%)')

    # Sanity checks
    if code_bytes == 0:
        print('FAIL: No code bytes detected')
        return 1
    if read_bytes == 0:
        print('FAIL: No data read bytes detected')
        return 1
    if write_bytes == 0:
        print('FAIL: No data write bytes detected')
        return 1

    if code_bytes > total * 0.5:
        print(f'WARNING: Code coverage suspiciously high ({100*code_bytes/total:.1f}%)')

    print('\nVERDICT: PASS')
    return 0

if __name__ == '__main__':
    sys.exit(main())
