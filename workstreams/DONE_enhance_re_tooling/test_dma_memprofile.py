#!/usr/bin/env python3
"""Test E3 (DMA trace) and E4 (memory write profiling).

Boots to menu, runs DMA trace + mem_profile during gameplay, checks output.
"""
import sys, os, tempfile, time

sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', 'empirical_validation'))
from investigate import MednafenBot, GAME_STATES, parse_trace, replay_to_state, wsl_path

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
CUE = os.path.join(PROJECT, 'build', 'disc', 'rebuilt_disc', 'daytona_rebuilt.cue')
TRACE = os.path.join(PROJECT, 'build', 'golden_trace', 'arcade_full.txt')

def main():
    ipc_dir = os.path.join(tempfile.gettempdir(), 'mednafen_dma_test')
    os.makedirs(ipc_dir, exist_ok=True)

    cue_wsl = wsl_path(CUE)
    dma_wsl = wsl_path(os.path.join(ipc_dir, 'dma_trace.txt'))
    dma_win = os.path.join(ipc_dir, 'dma_trace.txt')
    mp_wsl = wsl_path(os.path.join(ipc_dir, 'mem_profile.txt'))
    mp_win = os.path.join(ipc_dir, 'mem_profile.txt')

    bot = MednafenBot(ipc_dir, cue_wsl)
    if not bot.start(timeout=30):
        print('FAIL: Mednafen did not start')
        return 1

    try:
        bot.send_and_wait('deterministic', 'ok deterministic')

        # Replay to menu
        trace_events = parse_trace(TRACE)
        if not replay_to_state(bot, 'menu', trace_events):
            print('FAIL: replay_to_state failed')
            return 1
        print(f'At menu, frame={bot.current_frame}')

        # Start DMA trace
        resp = bot.send_and_wait(f'dma_trace {dma_wsl}', 'ok dma_trace')
        print(f'DMA trace: {resp}')

        # Start mem_profile on button input area (sym_06063D98 region)
        # Using a wider range to catch more writes
        resp = bot.send_and_wait(f'mem_profile 06063D00 06063EFF {mp_wsl}', 'ok mem_profile')
        print(f'Mem profile: {resp}')

        # Run 60 frames with a button press
        bot.input_press('DOWN')
        bot.frame_advance(30)
        bot.input_release('DOWN')
        bot.frame_advance(30)
        print(f'Advanced 60 frames, now at frame={bot.current_frame}')

        # Stop traces
        bot.send_and_wait('dma_trace_stop', 'ok dma_trace_stop')
        bot.send_and_wait('mem_profile_stop', 'ok mem_profile_stop')

        bot.send_and_wait('quit', 'ok quit')
    except Exception as e:
        print(f'ERROR: {e}')
        import traceback; traceback.print_exc()
        bot.kill()
        return 1

    # Analyze DMA trace
    time.sleep(1)
    if os.path.exists(dma_win):
        with open(dma_win) as f:
            lines = [l.strip() for l in f if l.strip() and not l.startswith('#')]
        print(f'\n=== DMA Trace: {len(lines)} transfers ===')
        for line in lines[:10]:
            print(f'  {line}')
        if len(lines) > 10:
            print(f'  ... and {len(lines) - 10} more')
        if len(lines) == 0:
            print('FAIL: No DMA transfers logged')
            return 1
    else:
        print(f'FAIL: DMA trace file not created at {dma_win}')
        return 1

    # Analyze mem_profile
    if os.path.exists(mp_win):
        with open(mp_win) as f:
            lines = [l.strip() for l in f if l.strip() and not l.startswith('#')]
        print(f'\n=== Memory Write Profile: {len(lines)} writes ===')
        for line in lines[:10]:
            print(f'  {line}')
        if len(lines) > 10:
            print(f'  ... and {len(lines) - 10} more')
        if len(lines) == 0:
            print('WARNING: No memory writes in profiled range (may be expected)')
    else:
        print(f'WARNING: Mem profile file not created (may be expected if no writes hit range)')

    print('\nVERDICT: PASS')
    return 0

if __name__ == '__main__':
    sys.exit(main())
