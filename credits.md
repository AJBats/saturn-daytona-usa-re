# Credits & Acknowledgments

This project would not be possible without the work of the Sega Saturn
reverse engineering and homebrew community. These people built the tools
and knowledge base that makes Saturn research accessible today.

## Tools & Resources Used

### Ghidra Sega Saturn Loader
- **Author:** VGKintsugi
- **Repository:** https://github.com/VGKintsugi/Ghidra-SegaSaturn-Loader
- **Description:** Ghidra extension that loads Sega Saturn disc images and
  binaries with correct SH-2 memory mapping, IP.BIN parsing, and
  peripheral register labeling.

### Saturn IDA/Ghidra Library Signatures
- **Author:** CyberWarriorX (Theo Berkau)
- **Website:** http://cyberwarriorx.com/saturn-utilities
- **Description:** IDA FLIRT signature files generated from the official
  Sega Saturn SBL (Sega Basic Library) and SGL (Sega Graphics Library)
  SDKs. Allows automatic identification of SDK functions in game binaries.
- **Files used:** sbl60.sig, sbl601.sig, sgl20a.sig, sgl21.sig,
  sgl300.sig, sgl302j.sig

### ApplySig - IDA FLIRT Signatures for Ghidra
- **Author:** NWMonster
- **Repository:** https://github.com/NWMonster/ApplySig
- **License:** LGPL-3.0
- **Description:** Ghidra Python script that parses and applies IDA FLIRT
  (.sig) signature files, enabling function identification in Ghidra using
  signatures originally created for IDA Pro.

## Community Knowledge

### Saturn Reverse Engineering Community
- **SegaXtreme forums** - Long-running community hub for Saturn technical
  discussion, homebrew development, and reverse engineering.
- **decomp.dev / decomp community** - Methodology and tooling conventions
  for matching decompilation projects.

### Compiler Research
- **Toshiyasu Morita** (Sega of America) - Maintained the SOA Cygnus GCC
  distribution for Saturn developers from 1994-1996. His detailed changelog
  (GCC.LOG) documents every compiler release and bugfix, and was instrumental
  in identifying the compiler version timeline for this project.
- **sozud/saturn-compilers** - Collection of Sega Saturn cross-compiler
  toolchains (Cygnus GCC, Hitachi SHC) preserved for decomp work.
- **sotn-decomp** (Castlevania: Symphony of the Night decomp) - Reference
  project demonstrating Saturn matching decomp methodology with Cygnus GCC.

### Mednafen
- **Author:** Mednafen Team
- **Website:** https://mednafen.github.io/
- **Description:** Multi-system emulator with cycle-accurate Saturn
  emulation. Used as the primary testing and debugging platform for this
  project, including automated boot testing and the Claude debugger
  interface.

### Claude
- **Author:** Anthropic
- **Website:** https://claude.ai
- **Description:** AI collaborator used throughout this project for
  binary analysis, assembly decoding, tooling development, codebase
  annotation, linker script design, and debugger-driven testing.

## Inspiration

- **Chris Sawyer** - for writing RollerCoaster Tycoon entirely in
  assembly, which inspired the approach of treating assembly as source
  code rather than pursuing a traditional C decompilation.

## Additional Thanks

- The Sega Saturn hardware documentation efforts by Charles MacDonald
  and others who mapped out the VDP1, VDP2, SCU, SMPC, and CD block
  register sets.
- Sega themselves, for creating the Saturn and the Daytona USA arcade/port
  that made 1990s gaming what it was.
