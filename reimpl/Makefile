# Daytona USA Saturn — Faithful C Reimplementation
# Build with: make (from WSL)
# Inject:     make disc
# Full cycle:  make disc && powershell test_boot_reimpl.ps1

PROJDIR := /mnt/d/Projects/SaturnReverseTest
TOOLDIR := $(PROJDIR)/tools/sh-elf/bin

CC      := $(TOOLDIR)/sh-elf-gcc
AS      := $(TOOLDIR)/sh-elf-as
LD      := $(TOOLDIR)/sh-elf-ld
OBJCOPY := $(TOOLDIR)/sh-elf-objcopy
OBJDUMP := $(TOOLDIR)/sh-elf-objdump

CFLAGS  := -m2 -mb -Os -Wall -nostdlib -ffreestanding -fno-builtin -ffunction-sections -Iinclude

# batch_cd_system_34.c ICEs with -Os on sh-elf-gcc 13.3.0 — fall back to -O2
CFLAGS_O2 := -m2 -mb -O2 -Wall -nostdlib -ffreestanding -fno-builtin -ffunction-sections -Iinclude
LIBGCC  := $(PROJDIR)/tools/sh-elf/lib/gcc/sh-elf/13.3.0/libgcc.a
LDSCRIPT := saturn_fixed.ld
# --noinhibit-exec: 3 ASM functions have 2-byte section alignment padding that
# overlaps harmlessly with the next function (assembler pads to 4-byte boundary)
LDFLAGS := -T $(LDSCRIPT) -nostdlib --noinhibit-exec -Map=$(BUILDDIR)/daytona.map

BUILDDIR := build

# Auto-discover source files: drop a .c in src/ and it's included
C_SRCS   := $(wildcard src/*.c)
ASM_SRCS := $(wildcard src/*.s)

C_OBJS   := $(patsubst src/%.c,$(BUILDDIR)/%.o,$(C_SRCS))
ASM_OBJS := $(patsubst src/%.s,$(BUILDDIR)/%.o,$(ASM_SRCS))
OBJS     := $(ASM_OBJS) $(C_OBJS)

# Output
ELF  := $(BUILDDIR)/daytona.elf
BIN  := $(BUILDDIR)/APROG.BIN

.PHONY: all clean disc dump info sizing

all: $(BIN)

APROG_SIZE := 394896

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@
	@SIZE=$$(wc -c < $@); \
	if [ $$SIZE -gt $(APROG_SIZE) ]; then \
		echo "ERROR: $@ is $$SIZE bytes — exceeds original APROG.BIN ($(APROG_SIZE) bytes)"; \
		echo "Binary size parity VIOLATED. Fix overflow before proceeding."; \
		rm -f $@; \
		exit 1; \
	elif [ $$SIZE -lt $(APROG_SIZE) ]; then \
		truncate -s $(APROG_SIZE) $@; \
		echo "Built: $@ ($$SIZE bytes code, padded to $(APROG_SIZE))"; \
	else \
		echo "Built: $@ ($$SIZE bytes — exact match)"; \
	fi

$(ELF): $(OBJS) $(LDSCRIPT)
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LIBGCC)

# Explicit rule for files that ICE with -Os
$(BUILDDIR)/batch_cd_system_34.o: src/batch_cd_system_34.c | $(BUILDDIR)
	$(CC) $(CFLAGS_O2) -c $< -o $@

$(BUILDDIR)/%.o: src/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: src/%.s | $(BUILDDIR)
	$(AS) --isa=sh2 -big -o $@ $<

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

dump: $(ELF)
	$(OBJDUMP) -d $(ELF)

clean:
	rm -rf $(BUILDDIR)

# Show what's being built
info:
	@echo "C sources:   $(C_SRCS)"
	@echo "ASM sources: $(ASM_SRCS)"
	@echo "Objects:     $(OBJS)"

# Inject into disc image for Mednafen testing
# patch_data_holes.py fills unclaimed regions with original binary data
disc: $(BIN)
	@echo "Patching data holes with original binary..."
	python3 $(PROJDIR)/tools/patch_data_holes.py
	@echo "Injecting APROG.BIN into disc image..."
	python3 $(PROJDIR)/tools/inject_binary.py $(BUILDDIR)/APROG.BIN
