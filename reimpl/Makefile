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
# ─── MODS Flag ──────────────────────────────────────────────────────────
#
# If you want to start moving code around — changing function sizes, writing
# C reimplementations, fixing bugs — enable MODS. This activates a curated
# list of patches (in src/mods/) that fix latent Sega bugs exposed by code
# relocation. Without these patches, shifted builds hang or crash.
#
# Currently MODS=1 enables:
#   - cdb_wait_scdq.c   SCDQ poll timeout fix (latent Sega bug — retail code
#                        polls CD status forever; shifting addresses changes
#                        cache-line timing and triggers the infinite loop)
#
# If you need more patches to make relocated code work, add them to src/mods/.
# The free.ld linker script handles arbitrary function sizing. The +4 shift
# build validates that all pointers relocate correctly — if it boots, your
# relocation is clean.
#
#   make MODS=1               — build with relocation patches
#   make MODS=1 disc          — build + inject modified binary
#   make disc-4shift           — +4 byte shift build (MODS=1 auto-enabled)
#
# Full L3 validation procedure:
#   make retail-validate                 — test 1: retail matches original
#   make validate                        — test 2: free matches original
#   python tools/validate_build.py       — all 3 tests (includes shifted boot test)

PROJDIR := /mnt/d/Projects/SaturnReverseTest
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
MODS     ?= 0
RE_TESTS ?= 0
LDFLAGS  := -T $(LDSCRIPT) -nostdlib -Map=$(BUILDDIR)/daytona.map
ifneq ($(SHIFT),0)
    LDFLAGS += --defsym __pad_size=$(SHIFT)
endif

# Auto-discover retail .s files
RETAIL_ASM  := $(wildcard retail/*.s)
RETAIL_OBJS := $(patsubst retail/%.s,$(BUILDDIR)/%.o,$(RETAIL_ASM))

# Auto-discover reimplemented files (src/ overrides retail/ by stem name)
# src/*.s and src/*.c are always active — these must byte-match retail.
# src/mods/ contains relocation patches that intentionally change the binary.
# src/mods/re_tests/ contains experimental C reimplementations for testing.
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
CONFIG_STR := LDSCRIPT=$(LDSCRIPT) SHIFT=$(SHIFT) MODS=$(MODS) RE_TESTS=$(RE_TESTS) REIMPL=$(REIMPL_STEMS)
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
# src/mods/ rules are additionally gated by MODS=1 so they don't leak into default builds.
# src/mods/re_tests/ rules are gated by RE_TESTS=1.
ifeq ($(RE_TESTS),1)
$(BUILDDIR)/%.o: src/mods/re_tests/%.s | $(BUILDDIR)
	$(AS) --isa=sh2 -big -o $@ $<

$(BUILDDIR)/%.o: src/mods/re_tests/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c -o $@ $<
endif

ifeq ($(MODS),1)
$(BUILDDIR)/%.o: src/mods/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDDIR)/%.o: src/mods/%.s | $(BUILDDIR)
	$(AS) --isa=sh2 -big -o $@ $<
endif

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

# Build + inject with +4 shift (relocation validation, MODS=1 required)
disc-4shift:
	$(MAKE) SHIFT=4 MODS=1 disc

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
