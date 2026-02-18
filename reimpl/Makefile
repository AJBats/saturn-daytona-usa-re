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

# Auto-discover .c and .s source files (.c takes priority over .s)
C_SRCS   := $(wildcard src/*.c)
ALL_ASM  := $(wildcard src/*.s)
ASM_SRCS := $(filter-out $(patsubst %.c,%.s,$(C_SRCS)),$(ALL_ASM))
C_OBJS   := $(patsubst src/%.c,$(BUILDDIR)/%.o,$(C_SRCS))
ASM_OBJS := $(patsubst src/%.s,$(BUILDDIR)/%.o,$(ASM_SRCS))
ALL_OBJS := $(C_OBJS) $(ASM_OBJS)

# Output
ELF  := $(BUILDDIR)/daytona.elf
BIN  := $(BUILDDIR)/APROG.BIN

# Original binary for validation
ORIGINAL := $(PROJDIR)/build/aprog.bin

.PHONY: all clean disc dump info validate

all: $(BIN)

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@
	@SIZE=$$(wc -c < $@); echo "Built: $@ ($$SIZE bytes)"

$(ELF): $(ALL_OBJS) $(LDSCRIPT)
	$(LD) $(LDFLAGS) -o $@ $(ALL_OBJS)

$(BUILDDIR)/%.o: src/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDDIR)/%.o: src/%.s | $(BUILDDIR)
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
	@echo "ASM sources: $(ASM_SRCS)"
	@echo "Objects:     $(ASM_OBJS)"

# Inject into disc image for Mednafen testing
disc: $(BIN)
	@echo "Injecting APROG.BIN into disc image..."
	python3 $(PROJDIR)/tools/inject_binary.py $(BUILDDIR)/APROG.BIN
