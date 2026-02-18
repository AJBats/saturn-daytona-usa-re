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
SCDQ_FIX ?= 0

# Auto-discover .s source files
ALL_ASM  := $(wildcard src/*.s)
ASM_OBJS := $(patsubst src/%.s,$(BUILDDIR)/%.o,$(ALL_ASM))
ALL_OBJS := $(ASM_OBJS)

# When SCDQ_FIX=1, compile the C patch and replace the ASM object
ifeq ($(SCDQ_FIX),1)
    ALL_OBJS := $(filter-out $(BUILDDIR)/FUN_060423CC.o,$(ALL_OBJS))
    ALL_OBJS += $(BUILDDIR)/FUN_060423CC_patch.o
endif

# Output
ELF  := $(BUILDDIR)/daytona.elf
BIN  := $(BUILDDIR)/APROG.BIN

# Original binary for validation
ORIGINAL := $(PROJDIR)/build/disc/files/APROG.BIN

.PHONY: all clean disc dump info validate shifttest

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

# Build with shifted ORIGIN to prove free layout
shifttest:
	$(MAKE) LDSCRIPT=sawyer_shifttest.ld
