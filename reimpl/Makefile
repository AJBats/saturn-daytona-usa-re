# Daytona USA Saturn — Sawyer L2 Relocatable Assembly
# Build with: make (from WSL)
# Validate:   make validate (cmp against original)
# Inject:     make disc
# Full cycle:  make disc && powershell test_boot_reimpl.ps1

PROJDIR := /mnt/d/Projects/SaturnReverseTest
TOOLDIR := $(PROJDIR)/tools/sh-elf/bin

AS      := $(TOOLDIR)/sh-elf-as
LD      := $(TOOLDIR)/sh-elf-ld
OBJCOPY := $(TOOLDIR)/sh-elf-objcopy
OBJDUMP := $(TOOLDIR)/sh-elf-objdump

BUILDDIR := build
LDSCRIPT := sawyer.ld
LDFLAGS  := -T $(LDSCRIPT) -nostdlib -Map=$(BUILDDIR)/daytona.map

# Auto-discover .s source files
ASM_SRCS := $(wildcard src/*.s)
ASM_OBJS := $(patsubst src/%.s,$(BUILDDIR)/%.o,$(ASM_SRCS))

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

$(ELF): $(ASM_OBJS) $(LDSCRIPT)
	$(LD) $(LDFLAGS) -o $@ $(ASM_OBJS)

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
