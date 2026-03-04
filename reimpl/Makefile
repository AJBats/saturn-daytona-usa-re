# Daytona USA Saturn — COFF Hybrid Build System
#
# Pipeline:
#   1. Cygnus 2.7 AS (DOSBox-X headless) assembles .s → COFF .O
#   2. sh-elf-ld links COFF .O files (-b coff-sh, SUBALIGN(2)) → ELF
#   3. sh-elf-objcopy converts ELF → flat binary
#
# DOSBox-X runs invisibly — each .s file gets its own headless DOSBox
# session via tools/cygnus_as.sh. Use -j for parallel builds:
#   make -j8          — 8 parallel DOSBox sessions
#
# Targets:
#   make              — build free-layout binary (byte-identical to retail)
#   make disc         — build + inject into disc image
#   make retail       — build with retail/ sources only (no src/ overrides)
#   make validate     — verify free build matches original
#   make retail-validate — verify retail build matches original
#   make disc-4shift  — +4 shift build (MODS=1 auto-enabled)
#   make dump         — disassemble the ELF
#   make clean        — remove all build artifacts
#   make info         — show pipeline configuration
#
# ─── MODS Flag ──────────────────────────────────────────────────────────
#
# MODS=1 activates relocation patches (src/mods/) that fix latent Sega
# bugs exposed by code relocation. Required for shifted builds.
#
# Currently MODS=1 enables:
#   - cdb_wait_scdq.c   SCDQ poll timeout fix (latent Sega bug)
#
#   make MODS=1               — build with relocation patches
#   make MODS=1 disc          — build + inject modified binary
#   make disc-4shift          — +4 byte shift build (MODS=1 auto-enabled)
#
# RE_TESTS=1 enables experimental modifications (src/mods/re_tests/).

PROJDIR := /mnt/d/Projects/SaturnReverseTest
TOOLDIR := $(PROJDIR)/tools/sh-elf/bin

AS      := $(PROJDIR)/tools/cygnus_as.sh
CC      := $(TOOLDIR)/sh-elf-gcc
LD      := $(TOOLDIR)/sh-elf-ld
OBJCOPY := $(TOOLDIR)/sh-elf-objcopy
OBJDUMP := $(TOOLDIR)/sh-elf-objdump

CFLAGS  := -m2 -Os -nostdlib -ffreestanding -fno-leading-underscore

BUILDDIR := build
COFFDIR  := $(BUILDDIR)/coff
LDSCRIPT := free.ld
SHIFT    ?= 0
MODS     ?= 0
RE_TESTS ?= 0
LDFLAGS  := -T $(LDSCRIPT) -b coff-sh -nostdlib -relax -Map=$(BUILDDIR)/daytona.map
ifneq ($(SHIFT),0)
    LDFLAGS += --defsym __pad_size=$(SHIFT)
endif

# Auto-discover retail .s files
RETAIL_ASM  := $(wildcard retail/*.s)
RETAIL_OBJS := $(patsubst retail/%.s,$(COFFDIR)/%.O,$(RETAIL_ASM))

# Auto-discover reimplemented files (src/ overrides retail/ by stem name)
# src/*.s and src/*.c are always active — these must byte-match retail.
# src/mods/ contains relocation patches that intentionally change the binary.
# src/mods/re_tests/ contains experimental modifications for testing.
REIMPL_S    := $(wildcard src/*.s)
REIMPL_C    := $(wildcard src/*.c)
ifeq ($(MODS),1)
REIMPL_S    += $(wildcard src/mods/*.s)
REIMPL_C    += $(wildcard src/mods/*.c)
endif
ifeq ($(RE_TESTS),1)
REIMPL_S    += $(wildcard src/mods/re_tests/*.s)
REIMPL_C    += $(wildcard src/mods/re_tests/*.c)
endif
REIMPL_STEMS := $(sort $(basename $(notdir $(REIMPL_C) $(REIMPL_S))))

# Build object list: retail .O in sorted order, src/ overrides by stem name.
# Only append reimpl objects that have NO retail counterpart (e.g., mod-only files).
ALL_OBJS := $(RETAIL_OBJS)
ifneq ($(strip $(REIMPL_STEMS)),)
    ALL_OBJS += $(filter-out $(RETAIL_OBJS),$(addprefix $(COFFDIR)/,$(addsuffix .O,$(REIMPL_STEMS))))
endif

# Output
ELF      := $(BUILDDIR)/daytona.elf
BIN      := $(BUILDDIR)/APROG.BIN

# Original binary for validation
ORIGINAL := $(PROJDIR)/build/disc/files/APROG.BIN

# Config change detection: if flags changed since last build, force a full rebuild.
# Includes reimpl stems so switching between free/retail rebuilds overridden objects.
CONFIG_STR := SHIFT=$(SHIFT) MODS=$(MODS) RE_TESTS=$(RE_TESTS) REIMPL=$(REIMPL_STEMS)
PREV_CONFIG := $(shell cat $(COFFDIR)/.build_config 2>/dev/null)
ifneq ($(CONFIG_STR),$(PREV_CONFIG))
    $(info Config changed: [$(PREV_CONFIG)] -> [$(CONFIG_STR)])
    $(shell rm -f $(COFFDIR)/*.O $(ELF) $(BIN))
endif

.PHONY: all clean disc disc-4shift retail retail-validate disc-retail dump info validate

all: $(BIN)

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@
	@SIZE=$$(wc -c < $@); \
	echo ""; \
	echo "========================================"; \
	echo "  COFF BUILD: $$SIZE bytes (shift=$(SHIFT), mods=$(MODS))"; \
	echo "  Reimplemented: $(REIMPL_STEMS)"; \
	echo "========================================"; \
	echo ""

$(ELF): $(ALL_OBJS) $(LDSCRIPT)
	$(LD) $(LDFLAGS) -o $@ $(ALL_OBJS)
	@echo "$(CONFIG_STR)" > $(COFFDIR)/.build_config

# Assembly rules: src/ overrides retail/ via pattern rule precedence.
# Each rule launches one headless DOSBox-X session (~0.3-0.5s per file).
ifeq ($(RE_TESTS),1)
$(COFFDIR)/%.O: src/mods/re_tests/%.s | $(COFFDIR)
	$(AS) $< $@

$(COFFDIR)/%.O: src/mods/re_tests/%.c | $(COFFDIR)
	$(CC) $(CFLAGS) -c -o $@ $<
endif

ifeq ($(MODS),1)
$(COFFDIR)/%.O: src/mods/%.s | $(COFFDIR)
	$(AS) $< $@

$(COFFDIR)/%.O: src/mods/%.c | $(COFFDIR)
	$(CC) $(CFLAGS) -c -o $@ $<
endif

ifneq ($(strip $(REIMPL_STEMS)),)
$(COFFDIR)/%.O: src/%.s | $(COFFDIR)
	$(AS) $< $@

$(COFFDIR)/%.O: src/%.c | $(COFFDIR)
	$(CC) $(CFLAGS) -c -o $@ $<
endif

$(COFFDIR)/%.O: retail/%.s | $(COFFDIR)
	$(AS) $< $@

$(COFFDIR):
	mkdir -p $(COFFDIR)

# Build + inject into disc image (default = free build)
disc: $(BIN)
	@echo "Injecting APROG.BIN into disc image..."
	python3 $(PROJDIR)/tools/inject_binary.py $(BUILDDIR)/APROG.BIN

# Build + inject with +4 shift (relocation validation, MODS=1 required)
disc-4shift:
	$(MAKE) SHIFT=4 MODS=1 disc

# Retail build (no src/ overrides)
retail:
	$(MAKE) REIMPL_C= REIMPL_S=

# Build + inject retail binary
disc-retail:
	$(MAKE) REIMPL_C= REIMPL_S=
	$(MAKE) REIMPL_C= REIMPL_S= disc

# Validate retail build matches original
retail-validate:
	$(MAKE) REIMPL_C= REIMPL_S=
	@if cmp -s $(BIN) $(ORIGINAL); then \
		echo "PASS: retail byte-identical to original"; \
	else \
		echo "FAIL: retail differs from original"; \
		cmp -l $(BIN) $(ORIGINAL) 2>/dev/null | head -20; \
		echo "..."; \
		echo "Original: $$(wc -c < $(ORIGINAL)) bytes"; \
		echo "Built:    $$(wc -c < $(BIN)) bytes"; \
	fi

# Validate free build (free.ld) matches original retail APROG.BIN
validate: $(BIN)
	@if cmp -s $(BIN) $(ORIGINAL); then \
		echo "PASS: free build byte-identical to original"; \
	else \
		echo "FAIL: free build differs from original"; \
		cmp -l $(BIN) $(ORIGINAL) 2>/dev/null | head -20; \
		echo "..."; \
		echo "Original: $$(wc -c < $(ORIGINAL)) bytes"; \
		echo "Built:    $$(wc -c < $(BIN)) bytes"; \
	fi

dump: $(ELF)
	$(OBJDUMP) -d $(ELF)

clean:
	rm -rf $(BUILDDIR)

info:
	@echo "Pipeline:   Cygnus AS (DOSBox-X) -> sh-elf-ld -b coff-sh"
	@echo "Assembler:  $(AS)"
	@echo "Linker:     $(LDSCRIPT)"
	@echo "Shift:      $(SHIFT)"
	@echo "MODS:       $(MODS)"
	@echo "RE_TESTS:   $(RE_TESTS)"
	@echo "Retail ASM: $(words $(RETAIL_ASM)) files"
	@echo "Reimpl:     $(words $(REIMPL_S)) .s + $(words $(REIMPL_C)) .c"
	@echo "Total .O:   $(words $(ALL_OBJS))"
