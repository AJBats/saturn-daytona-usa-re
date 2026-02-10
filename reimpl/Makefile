# Daytona USA Saturn — Faithful C Reimplementation
# Build with: make (from WSL)

PROJDIR := /mnt/d/Projects/SaturnReverseTest
TOOLDIR := $(PROJDIR)/tools/sh-elf/bin

CC      := $(TOOLDIR)/sh-elf-gcc
AS      := $(TOOLDIR)/sh-elf-as
LD      := $(TOOLDIR)/sh-elf-ld
OBJCOPY := $(TOOLDIR)/sh-elf-objcopy
OBJDUMP := $(TOOLDIR)/sh-elf-objdump

CFLAGS  := -m2 -mb -O2 -Wall -nostdlib -ffreestanding -fno-builtin -Iinclude
LDFLAGS := -T saturn.ld -nostdlib

BUILDDIR := build

# Source files (add as we translate functions)
C_SRCS := src/main.c
ASM_SRCS := src/start.s

C_OBJS := $(patsubst src/%.c,$(BUILDDIR)/%.o,$(C_SRCS))
ASM_OBJS := $(patsubst src/%.s,$(BUILDDIR)/%.o,$(ASM_SRCS))
OBJS := $(C_OBJS) $(ASM_OBJS)

# Output
ELF  := $(BUILDDIR)/daytona.elf
BIN  := $(BUILDDIR)/APROG.BIN

.PHONY: all clean disc dump

all: $(BIN)

APROG_SIZE := 394896

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@
	@SIZE=$$(wc -c < $@); \
	if [ $$SIZE -lt $(APROG_SIZE) ]; then \
		truncate -s $(APROG_SIZE) $@; \
		echo "Built: $@ ($$SIZE bytes code, padded to $(APROG_SIZE))"; \
	else \
		echo "Built: $@ ($$SIZE bytes)"; \
	fi

$(ELF): $(OBJS) saturn.ld
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

$(BUILDDIR)/%.o: src/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: src/%.s | $(BUILDDIR)
	$(AS) --isa=sh2 -big -o $@ $<

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

dump: $(ELF)
	$(OBJDUMP) -d $(ELF) | head -100

clean:
	rm -rf $(BUILDDIR)

# Inject into disc image for Mednafen testing
DISC_TRACK := $(PROJDIR)/external_resources/Daytona\ USA\ \(USA\)/Daytona\ USA\ \(USA\)\ \(Track\ 01\).bin
DISC_OFFSET := 49408

disc: $(BIN)
	@echo "Injecting APROG.BIN into disc image..."
	bash $(PROJDIR)/tools/build_disc_from_bin.sh $(BIN)
