# Daytona USA (Saturn) - Reverse Engineering Project

A reverse engineering project for **Daytona USA** (Sega Saturn, 1995).

## Prerequisites

- **WSL** (Ubuntu) with `build-essential` installed - this project was developed entirely in WSL on Windows, so native Linux likely works but is untested and may require modifications to certain scripts
- **Python 3.10+** (Windows side, for validation and tooling)
- Your backup of Daytona USA in BIN/CUE form

## Setup

Clone with `--recursive` to pull the custom Mednafen debugger submodule:

```bash
git clone --recursive https://github.com/AJBats/SaturnReverseTest.git
```

If you already cloned without `--recursive`:

```bash
git submodule update --init
```

Place your disc image at:

```
external_resources/Daytona USA (USA)/
  Daytona USA (USA).cue
  Daytona USA (USA) (Track 01).bin
  Daytona USA (USA) (Track 02).bin
  ...
```

Then run the setup script from WSL:

```bash
./setup.sh
```

This will:
1. Check prerequisites (Python 3, gcc, make, wget)
2. Extract APROG.BIN from your disc image
3. Generate the disassembly (build/aprog.s)
4. Build the sh-elf cross-toolchain (binutils 2.42 + GCC 13.3.0)

You can check what's installed at any time with `./setup.sh status`.

## Building

All build commands run from `reimpl/` via WSL:

```bash
# Build the free-layout binary (byte-identical to Sega's original)
make

# Build + inject into disc image for emulator testing
make disc

# Build with Sega's original linker layout + inject into disc
make disc-retail

# +4 byte shift build (relocation stress test - proves all pointers relocate)
make disc-4shift

# Full validation (retail match + free match + shifted boot test)
# Run from Windows:
python tools/validate_build.py
```

## Validation

Every change must pass three independent tests:

| Test | What it proves |
|------|---------------|
| **Retail match** | Assembly linked with Sega's original layout is byte-identical |
| **Free match** | Free-layout linker produces identical output with reordered sections |
| **Free+4 shift** | Every pointer in the binary relocates correctly when all code shifts by 4 bytes |

The shifted build also runs an automated boot test - three screenshots compared against golden baselines to verify the game actually runs, not just links.

## Project Structure

```
reimpl/
  retail/     - Original Sega assembly (1,049 files, untouched)
  src/        - Annotated L3 assembly (1,046 files, human-readable mnemonics)
  src/mods/   - Code modifications (bug fixes, new features)
  free.ld     - Free-layout linker script
  sega.ld     - Original-layout linker script (for retail validation)
  Makefile

asm/          - Sawyer-style annotation files (46 files, reverse engineering notes)
mednafen/     - Custom Mednafen debugger (git submodule, see AJBats/mednafen-saturn-debug)
```

---

## Journal

This project started as an experiment to see what Claude could do when set upon reverse engineering Saturn games. I really have no experience reverse engineering, so I came into this originally seeking to learn something new about RE, hoping Claude could teach me the basics.

After going through the regular study of examining other Saturn RE projects (and some N64 too), I set up Ghidra and with Claude we were able to get pretty far in the traditional decomp process. However, we had this problem hanging over us which is that we didn't know what compiler version Daytona USA was built with. Our closest guess was some version of gcc 2.6. We had Cygnus 2.7 from the community, but this wasn't producing matching code.

I then asked Claude: "Why don't we take inspiration from Chris Sawyer, who famously wrote all of RollerCoaster Tycoon in assembly? If we treat the assembly as the source, we can sidestep the compiler issue." He liked the idea, and we did a test. This test changed everything. I discovered what many have already discovered, that Claude can read assembly as if it were C code. In fact he doesn't even need the mnemonics, he can infer them directly from the binary of the executable Sega shipped in Daytona USA.

From this point on, we pivoted from a traditional decomp. Without a perfect match version of gcc, the traditional method of reversing back to C to produce a byte-matching binary is off the table. So instead we treat the assembly as our code.

The exe shipped by Sega has fixed memory offsets for everything, functions and data alike. The compiler made it that way because the code was never meant to change. But the whole point of a decomp is to get to where you *can* make changes. We began work on a linker file that would take the original assembly from Sega and link it in such a way that allows us to move and resize functions. Claude was successful.

So let me now share what I think is the real gold of this project as it stands today:

- **The modifiable build.** We've produced a build that shifts every byte over by 4 bytes, and play-tested the resulting binary on a real Saturn, thus proving we've successfully made the codebase modifiable.
- **Claude in a debugger.** We gave Claude a Mednafen debugger, allowing him to step code, set breakpoints, and get memory dumps. We even have memory watches for data changes. Claude can drive it all, and it's how we were able to debug our byte-shifted build to a state where it could boot and play.
- **The annotations.** I asked Claude to work backwards from Saturn input registers (button presses) to begin annotating the codebase with intent, knowing this was Daytona USA. He also knocked this completely out of the park. His source annotations are not perfect and they need to be verified, but there is enough here that is right that it's an amazing first step for mapping out this codebase.

And here's the crazy part: this project is four weeks old. A person like me who knows nothing about Saturn reverse engineering is able to use Claude, and in just four weeks, I have a game understood to a point where we could feasibly begin making code modifications. Each modification would have to be tested and validated, but now with Claude in a Mednafen debugger, this becomes traditional software engineering.

Now I'll talk a bit about the ramifications of this for reverse engineering in general. Claude and other AI tools are only going to keep getting better. Folks who actually know about RE who are not newbies like me are going to start using these tools far more effectively than I have. I see a pathway where there is a scaling multiplier with RE projects. We no longer just reverse engineer our favorite games. There's a real possibility that with Claude we can reverse engineer entire console libraries. I have already made plans for the next game I want to get to this point, and I think I can do it much faster having learned what I have. What I hope this project does is inspire others to give these tools a try. I think many others already are, but if any reverse engineering hobbyist is on the fence about these tools, they are a force multiplier.

---

## Acknowledgments

See [credits.md](credits.md).
