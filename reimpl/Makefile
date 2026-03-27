# Daytona USA Saturn — Reimplementation Build System
#
# Default build uses the free-layout linker script (free.ld). Files in src/
# override their retail/ counterparts by stem name — this is where L3 uplifts
# and reimplementations live. The build must be byte-identical to the original
# Sega APROG.BIN. free.ld recreates original link order via SORT_BY_NAME on
# .text.FUN_* sections, so retail byte-match proves both the assembly AND the
# relocation infrastructure are correct.
#
#   make              — build free-layout binary (byte-identical to retail)
#   make disc         — build + inject into disc image
#   make retail       — build with sega.ld (original linker script)
#   make validate     — verify all builds match original
#
# ─── Mod System ─────────────────────────────────────────────────────────
#
# MODS=name1,name2,...  — comma-separated list of mod overlays to enable.
# Each mod is a subdirectory under src/mods/ containing .s and/or .c files.
#
# Available mods:
#   scdq        — SCDQ poll timeout fix (prerequisite for resized builds)
#   re_tests    — car flip benchmark experiments
#   30fps       — 30fps mod (WIP)
#   decomp      — C decompilation overlay (Cygnus 2.7 compiled)
#
# The decomp mod compiles .c files with Cygnus 2.7-96Q3 GCC (via DOSBox)
# to match the original Sega toolchain. All other mods use sh-elf-gcc.
#
#   make MODS=scdq              — build with SCDQ fix
#   make MODS=scdq,decomp disc  — build with SCDQ + decomp, inject into disc
#   make disc-4shift            — +4 byte shift build (scdq auto-enabled)
#
# Full L3 validation procedure:
#   make retail-validate                 — test 1: retail matches original
#   make validate                        — test 2: free matches original
#   python tools/validate_build.py       — all 3 tests (includes shifted boot test)

PROJDIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))..)
TOOLDIR := $(PROJDIR)/tools/sh-elf/bin

AS      := $(TOOLDIR)/sh-elf-as
CC      := $(TOOLDIR)/sh-elf-gcc
LD      := $(TOOLDIR)/sh-elf-ld
OBJCOPY := $(TOOLDIR)/sh-elf-objcopy
OBJDUMP := $(TOOLDIR)/sh-elf-objdump

CFLAGS  := -m2 -Os -nostdlib -ffreestanding -ffunction-sections -fno-leading-underscore

BUILDDIR := build
LDSCRIPT := free.ld
SHIFT    ?= 0
MODS     ?=
LDFLAGS  := -T $(LDSCRIPT) -nostdlib -Map=$(BUILDDIR)/daytona.map
ifneq ($(SHIFT),0)
    LDFLAGS += --defsym __pad_size=$(SHIFT)
endif

# Auto-discover retail .s files
RETAIL_ASM  := $(wildcard retail/*.s)
RETAIL_OBJS := $(patsubst retail/%.s,$(BUILDDIR)/%.o,$(RETAIL_ASM))

# Auto-discover reimplemented files (src/ overrides retail/ by stem name)
# src/*.s and src/*.c are always active — these must byte-match retail.
#
# ─── Mod System ──────────────────────────────────────────────────────────
# MODS=name1,name2,...  — enable one or more mod overlays from src/mods/
#
# Each mod is a subdirectory under src/mods/ containing .s and/or .c files.
# Comma-separated list. Examples:
#   make MODS=scdq                — SCDQ fix only
#   make MODS=scdq,decomp         — SCDQ fix + C decompilation overlay
#   make MODS=scdq,re_tests disc  — SCDQ fix + car flip experiments
#
# Available mods:
#   scdq        — SCDQ poll timeout fix (prerequisite for resized builds)
#   re_tests    — car flip benchmark experiments
#   30fps       — 30fps mod (WIP)
#   decomp      — C decompilation overlay (Cygnus 2.7 compiled)
#
# The decomp mod uses the Cygnus 2.7-96Q3 compiler (via DOSBox) for .c
# files to match the original Sega toolchain. All other mods use sh-elf-gcc.
# ─────────────────────────────────────────────────────────────────────────
REIMPL_S    := $(wildcard src/*.s)
REIMPL_C    := $(wildcard src/*.c)

# Parse comma-separated MODS list into space-separated MOD_LIST
comma := ,
MOD_LIST := $(subst $(comma), ,$(MODS))

# Activate each mod's source files
$(foreach mod,$(MOD_LIST),\
    $(eval REIMPL_S += $(wildcard src/mods/$(mod)/*.s))\
    $(eval REIMPL_C += $(wildcard src/mods/$(mod)/*.c))\
)
REIMPL_STEMS := $(sort $(basename $(notdir $(REIMPL_C) $(REIMPL_S))))

# Build object list: retail objects in original order. Make's pattern rule
# precedence handles src/ overrides — src/ rules are defined first, so when
# both src/foo.s and retail/foo.s exist, src/ wins. This preserves linker
# input order, which matters for section placement.
# Only append reimpl objects that have NO retail counterpart (e.g., mod-only files).
ALL_OBJS := $(RETAIL_OBJS)
ifneq ($(strip $(REIMPL_STEMS)),)
    ALL_OBJS += $(filter-out $(RETAIL_OBJS),$(addprefix $(BUILDDIR)/,$(addsuffix .o,$(REIMPL_STEMS))))
endif

# Output
ELF  := $(BUILDDIR)/daytona.elf
BIN  := $(BUILDDIR)/APROG.BIN

# Original binary for validation
ORIGINAL := $(PROJDIR)/build/disc/files/APROG.BIN

# Config change detection: if flags changed since last build, force a full rebuild.
# Includes reimpl stems so switching between free/retail rebuilds overridden objects.
CONFIG_STR := LDSCRIPT=$(LDSCRIPT) SHIFT=$(SHIFT) MODS=$(MODS) REIMPL=$(REIMPL_STEMS)
PREV_CONFIG := $(shell cat $(BUILDDIR)/.build_config 2>/dev/null)
ifneq ($(CONFIG_STR),$(PREV_CONFIG))
    $(info Config changed: [$(PREV_CONFIG)] -> [$(CONFIG_STR)])
    $(shell rm -f $(BUILDDIR)/*.o $(ELF) $(BIN))
endif

.PHONY: all clean disc disc-4shift retail retail-validate disc-retail dump info validate

all: $(BIN)

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@
	@SIZE=$$(wc -c < $@); \
	if [ "$(LDSCRIPT)" = "free.ld" ]; then \
		echo ""; \
		echo "========================================"; \
		echo "  FREE BUILD: $$SIZE bytes (shift=$(SHIFT), mods=$(MODS))"; \
		echo "  Reimplemented: $(REIMPL_STEMS)"; \
		echo "========================================"; \
		echo ""; \
	else \
		echo "RETAIL BUILD: $@ ($$SIZE bytes)"; \
	fi

$(ELF): $(ALL_OBJS) $(LDSCRIPT)
	$(LD) $(LDFLAGS) -o $@ $(ALL_OBJS)
	@echo "$(CONFIG_STR)" > $(BUILDDIR)/.build_config

# Compile rules: src/ overrides retail/ for reimplemented functions.
# Guarded so retail builds don't accidentally pick up src/ files via pattern matching.
#
# Mod compile rules: generated for each mod in MOD_LIST.
# The 'decomp' mod uses Cygnus 2.7 GCC (via DOSBox) for .c files.
# All other mods use sh-elf-gcc for .c files.
# Assembly (.s) rules are the same for all mods.

# Generate pattern rules for each active mod
$(foreach mod,$(MOD_LIST),\
    $(eval $(BUILDDIR)/%.o: src/mods/$(mod)/%.s | $(BUILDDIR) ; \
        $$(AS) --isa=sh2 -big -o $$@ $$<)\
    $(if $(filter decomp,$(mod)),\
        $(eval $(BUILDDIR)/%.o: src/mods/$(mod)/%.c | $(BUILDDIR) ; \
            @echo "  CC (cygnus) $$<" && \
            bash $$(PROJDIR)/tools/cygnus_compile.sh $$< $$(BUILDDIR)/$$*.s $$* && \
            $$(AS) --isa=sh2 -big -o $$@ $$(BUILDDIR)/$$*.s),\
        $(eval $(BUILDDIR)/%.o: src/mods/$(mod)/%.c | $(BUILDDIR) ; \
            $$(CC) $$(CFLAGS) -c -o $$@ $$<)\
    )\
)

ifneq ($(strip $(REIMPL_STEMS)),)
$(BUILDDIR)/%.o: src/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDDIR)/%.o: src/%.s | $(BUILDDIR)
	$(AS) --isa=sh2 -big -o $@ $<
endif

$(BUILDDIR)/%.o: retail/%.s | $(BUILDDIR)
	$(AS) --isa=sh2 -big -o $@ $<

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Build + inject into disc image (default = free build)
disc: $(BIN)
	@echo "Injecting APROG.BIN into disc image..."
	python3 $(PROJDIR)/tools/inject_binary.py $(BUILDDIR)/APROG.BIN

# Build + inject with +4 shift (relocation validation, scdq mod required)
disc-4shift:
	$(MAKE) SHIFT=4 MODS=scdq disc

# Byte-identical retail build (sega.ld — original linker script)
retail:
	$(MAKE) LDSCRIPT=sega.ld REIMPL_C= REIMPL_S=

# Build + inject retail binary
disc-retail:
	$(MAKE) LDSCRIPT=sega.ld REIMPL_C= REIMPL_S=
	$(MAKE) LDSCRIPT=sega.ld REIMPL_C= REIMPL_S= disc

# Validate retail build (sega.ld) matches original
retail-validate:
	$(MAKE) LDSCRIPT=sega.ld REIMPL_C= REIMPL_S=
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
	@echo "Linker script: $(LDSCRIPT)"
	@echo "Retail ASM:    $(words $(RETAIL_ASM)) files"
	@echo "Reimplemented: $(REIMPL_STEMS)"
	@echo "Total objects:  $(words $(ALL_OBJS))"
