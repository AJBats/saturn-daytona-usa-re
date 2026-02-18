# Daytona USA Saturn — Sawyer L2 Relocatable Assembly
# Build with: make (from WSL)
# Validate:   make validate (cmp against original)
# Inject:     make disc
# Full cycle:  make disc && powershell test_boot_reimpl.ps1

PROJDIR := /mnt/d/Projects/SaturnReverseTest
TOOLDIR := $(PROJDIR)/tools/sh-elf/bin

AS      := $(TOOLDIR)/sh-elf-as
CC      := $(TOOLDIR)/sh-elf-gcc
LD      := $(TOOLDIR)/sh-elf-ld
OBJCOPY := $(TOOLDIR)/sh-elf-objcopy
OBJDUMP := $(TOOLDIR)/sh-elf-objdump

CFLAGS  := -m2 -O2 -nostdlib -ffreestanding -ffunction-sections -fno-leading-underscore

BUILDDIR := build
LDSCRIPT := sawyer.ld
LDFLAGS  := -T $(LDSCRIPT) -nostdlib -Map=$(BUILDDIR)/daytona.map

# Patches (opt-in, default off for byte-identical builds)
#   make SCDQ_FIX=1   — apply SCDQ bypass (patches/FUN_060423CC.c replaces .s)
#   make ICF_FIX=1     — apply ICF bypass (patches/FUN_0600C010.s NOPs the slave poll)
SCDQ_FIX ?= 0
ICF_FIX  ?= 0

# Auto-discover .s source files
ALL_ASM  := $(wildcard src/*.s)
ASM_OBJS := $(patsubst src/%.s,$(BUILDDIR)/%.o,$(ALL_ASM))
ALL_OBJS := $(ASM_OBJS)

# When SCDQ_FIX=1, compile the C patch and replace the ASM object
ifeq ($(SCDQ_FIX),1)
    ALL_OBJS := $(filter-out $(BUILDDIR)/FUN_060423CC.o,$(ALL_OBJS))
    ALL_OBJS += $(BUILDDIR)/FUN_060423CC_patch.o
endif

# When ICF_FIX=1, assemble the patched .s and replace the original object
ifeq ($(ICF_FIX),1)
    ALL_OBJS := $(filter-out $(BUILDDIR)/FUN_0600C010.o,$(ALL_OBJS))
    ALL_OBJS += $(BUILDDIR)/FUN_0600C010_patch.o
endif

# Output
ELF  := $(BUILDDIR)/daytona.elf
BIN  := $(BUILDDIR)/APROG.BIN

# Original binary for validation
ORIGINAL := $(PROJDIR)/build/disc/files/APROG.BIN

.PHONY: all clean disc dump info validate shifttest free

all: $(BIN)

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@
	@SIZE=$$(wc -c < $@); echo "Built: $@ ($$SIZE bytes)"

$(ELF): $(ALL_OBJS) $(LDSCRIPT)
	$(LD) $(LDFLAGS) -o $@ $(ALL_OBJS)

$(BUILDDIR)/%.o: src/%.s | $(BUILDDIR)
	$(AS) --isa=sh2 -big -o $@ $<

# Patch compilation (from patches/ dir, only used when opted in)
$(BUILDDIR)/%_patch.o: patches/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Patch assembly (from patches/ dir, only used when opted in)
$(BUILDDIR)/%_patch.o: patches/%.s | $(BUILDDIR)
	$(AS) --isa=sh2 -big -o $@ $<

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Byte-identical validation against original binary
validate: $(BIN)
	@if cmp -s $(BIN) $(ORIGINAL); then \
		echo "PASS: byte-identical to original"; \
	else \
		echo "FAIL: differs from original"; \
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
	@echo "ASM sources: $(ALL_ASM)"
	@echo "Objects:     $(ALL_OBJS)"

# Inject into disc image for Mednafen testing
disc: $(BIN)
	@echo "Injecting APROG.BIN into disc image..."
	python3 $(PROJDIR)/tools/inject_binary.py $(BUILDDIR)/APROG.BIN

# Build free-layout with +4 shift (the real relocation test)
#   make free          — build only
#   make free disc     — build + inject into disc
free:
	$(MAKE) LDSCRIPT=sawyer_free.ld SCDQ_FIX=1 ICF_FIX=1

# DEPRECATED: sawyer_shifttest.ld has an ORIGIN mismatch (0x06003100 vs BIOS load 0x06003000)
# Use 'make free' instead for relocation testing
shifttest:
	@echo "WARNING: shifttest is deprecated — ORIGIN mismatch makes it fundamentally broken."
	@echo "Use 'make free' instead (sawyer_free.ld with +4 shift, SCDQ+ICF bypasses)."
	@exit 1
