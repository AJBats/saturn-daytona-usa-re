# Daytona USA Saturn — Reimplementation Build System
#
# Default build is the free-layout reimplementation (+4 shift).
# Reimplemented functions in src/ automatically override retail/ originals.
#
#   make              — build free-layout binary
#   make disc         — build + inject into disc image
#   make retail       — build byte-identical retail binary
#   make disc-retail  — build + inject retail binary
#   make validate     — verify retail build matches original

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
LDFLAGS  := -T $(LDSCRIPT) -nostdlib -Map=$(BUILDDIR)/daytona.map

# Auto-discover retail .s files
RETAIL_ASM  := $(wildcard retail/*.s)
RETAIL_OBJS := $(patsubst retail/%.s,$(BUILDDIR)/%.o,$(RETAIL_ASM))

# Auto-discover reimplemented files (src/ overrides retail/)
REIMPL_C    := $(wildcard src/*.c)
REIMPL_S    := $(wildcard src/*.s)
REIMPL_STEMS := $(sort $(basename $(notdir $(REIMPL_C) $(REIMPL_S))))

# Build object list: start with retail, filter out reimplemented stems, add reimpl objects
ALL_OBJS := $(filter-out $(addprefix $(BUILDDIR)/,$(addsuffix .o,$(REIMPL_STEMS))),$(RETAIL_OBJS))
ALL_OBJS += $(patsubst src/%.c,$(BUILDDIR)/%.o,$(REIMPL_C))
ALL_OBJS += $(patsubst src/%.s,$(BUILDDIR)/%.o,$(REIMPL_S))

# Output
ELF  := $(BUILDDIR)/daytona.elf
BIN  := $(BUILDDIR)/APROG.BIN

# Original binary for validation
ORIGINAL := $(PROJDIR)/build/disc/files/APROG.BIN

# Config change detection: if flags changed since last build, force a full rebuild.
# Includes reimpl stems so switching between free/retail rebuilds overridden objects.
CONFIG_STR := LDSCRIPT=$(LDSCRIPT) REIMPL=$(REIMPL_STEMS)
PREV_CONFIG := $(shell cat $(BUILDDIR)/.build_config 2>/dev/null)
ifneq ($(CONFIG_STR),$(PREV_CONFIG))
    $(info Config changed: [$(PREV_CONFIG)] -> [$(CONFIG_STR)])
    $(shell rm -f $(BUILDDIR)/*.o $(ELF) $(BIN))
endif

.PHONY: all clean disc disc-internal retail disc-retail dump info validate

all: $(BIN)

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@
	@SIZE=$$(wc -c < $@); \
	if [ "$(LDSCRIPT)" = "free.ld" ]; then \
		echo ""; \
		echo "========================================"; \
		echo "  FREE BUILD: $$SIZE bytes"; \
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

# Byte-identical retail build (all retail/, no src/ overrides)
retail:
	$(MAKE) LDSCRIPT=sega.ld REIMPL_C= REIMPL_S=

# Build + inject retail binary
disc-retail:
	$(MAKE) LDSCRIPT=sega.ld REIMPL_C= REIMPL_S=
	$(MAKE) LDSCRIPT=sega.ld REIMPL_C= REIMPL_S= disc

# Byte-identical validation (always builds retail first)
validate:
	$(MAKE) LDSCRIPT=sega.ld REIMPL_C= REIMPL_S=
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
	@echo "Linker script: $(LDSCRIPT)"
	@echo "Retail ASM:    $(words $(RETAIL_ASM)) files"
	@echo "Reimplemented: $(REIMPL_STEMS)"
	@echo "Total objects:  $(words $(ALL_OBJS))"
