#!/usr/bin/env python3
"""Test E3: DMA trace during boot (where DMA actually happens)."""
import sys, os, tempfile, time

sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', 'empirical_validation'))
from investigate import MednafenBot, wsl_path

PROJECT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
CUE = os.path.join(PROJECT, 'build', 'disc', 'rebuilt_disc', 'daytona_rebuilt.cue')

def main():
    ipc_dir = os.path.join(tempfile.gettempdir(), 'mednafen_dma_boot')
    os.makedirs(ipc_dir, exist_ok=True)

    cue_wsl = wsl_path(CUE)
    dma_wsl = wsl_path(os.path.join(ipc_dir, 'dma_boot.txt'))
    dma_win = os.path.join(ipc_dir, 'dma_boot.txt')

    bot = MednafenBot(ipc_dir, cue_wsl)
    if not bot.start(timeout=30):
        print('FAIL: Mednafen did not start')
        return 1

    try:
        bot.send_and_wait('deterministic', 'ok deterministic')

        # Start DMA trace BEFORE booting
        resp = bot.send_and_wait(f'dma_trace {dma_wsl}', 'ok dma_trace')
        print(f'DMA trace: {resp}')

        # Run through boot (500 frames should cover BIOS + initial load)
        bot.frame_advance(500)
        print(f'Advanced 500 frames')

        # Stop
        bot.send_and_wait('dma_trace_stop', 'ok dma_trace_stop')
        bot.send_and_wait('quit', 'ok quit')
    except Exception as e:
        print(f'ERROR: {e}')
        import traceback; traceback.print_exc()
        bot.kill()
        return 1

    time.sleep(1)
    if os.path.exists(dma_win):
        with open(dma_win) as f:
            lines = [l.strip() for l in f if l.strip() and not l.startswith('#')]
        print(f'\n=== DMA Trace (boot, 500 frames): {len(lines)} transfers ===')
        for line in lines[:15]:
            print(f'  {line}')
        if len(lines) > 15:
            print(f'  ... and {len(lines) - 15} more')
        if len(lines) > 0:
            print('\nVERDICT: PASS')
        else:
            print('FAIL: No DMA during boot (unexpected)')
            return 1
    else:
        print('FAIL: DMA trace file not created')
        return 1
    return 0

if __name__ == '__main__':
    sys.exit(main())
