# Daytona USA (Saturn) - Progressive Decomp Build System
#
# First-time setup:
#   1. .\extract-disc.ps1          (PowerShell - extract APROG.BIN from disc image)
#   2. ./setup-toolchain.sh        (bash/WSL - build sh-elf-binutils, run splitter)
#
# On Windows:  wsl make verify
#
# Targets:
#   make build      - Assemble and link APROG.BIN from asm source
#   make verify     - Build and verify byte-identical match against original
#   make split      - Re-run the splitter to regenerate asm from original binary
#   make clean      - Remove build artifacts (not the .s source)

SHELL := /bin/bash

# Project-local toolchain (built by setup-toolchain.sh), falls back to PATH
SH_ELF_BIN := $(wildcard tools/sh-elf/bin)
ifdef SH_ELF_BIN
    AS      := tools/sh-elf/bin/sh-elf-as
    LD      := tools/sh-elf/bin/sh-elf-ld
    OBJCOPY := tools/sh-elf/bin/sh-elf-objcopy
else
    AS      := sh-elf-as
    LD      := sh-elf-ld
    OBJCOPY := sh-elf-objcopy
endif
PYTHON   := python3

# Paths
BUILD_DIR    := build
SCRIPTS_DIR  := scripts
ORIGINAL     := $(BUILD_DIR)/disc/files/APROG.BIN
ASM_SRC      := $(BUILD_DIR)/aprog.s
LD_SCRIPT    := $(BUILD_DIR)/aprog.ld
SYMS         := $(BUILD_DIR)/aprog_syms.txt
OBJ          := $(BUILD_DIR)/aprog.o
ELF          := $(BUILD_DIR)/aprog.elf
BIN          := $(BUILD_DIR)/aprog.bin

# Default target
.PHONY: build verify split clean

build: $(BIN)

$(OBJ): $(ASM_SRC)
	$(AS) --big -o $@ $<

$(ELF): $(OBJ) $(LD_SCRIPT)
	$(LD) -T $(LD_SCRIPT) -o $@ $(OBJ)

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

verify: $(BIN)
	@cmp $(BIN) $(ORIGINAL) \
		&& echo "PASS: $(BIN) is byte-identical to $(ORIGINAL)" \
		|| (echo "FAIL: $(BIN) differs from $(ORIGINAL)"; exit 1)

split:
	$(PYTHON) $(SCRIPTS_DIR)/split_binary.py

clean:
	rm -f $(OBJ) $(ELF) $(BIN)
