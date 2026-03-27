# Unit test for sym_0602D814 (speed writer)
#
# Run from WSL:
#   cd tools/unit_test/tests/sym_0602D814
#   make clean && make
#
# Builds two disc images with identical harness:
#   build/test_vanilla.cue  — linked with original assembly
#   build/test_decomp.cue   — linked with C decompilation
# Boot each in Mednafen, read results at _results_start, compare.

PROJDIR  := $(shell cd ../../../.. && pwd)
TOOLDIR  := $(PROJDIR)/tools/sh-elf/bin
SHARED   := $(PROJDIR)/tools/unit_test
CYGNUS   := $(PROJDIR)/tools/cygnus_compile.sh

AS       := $(TOOLDIR)/sh-elf-as
LD       := $(TOOLDIR)/sh-elf-ld
GCC      := $(TOOLDIR)/sh-elf-gcc
OBJCOPY  := $(TOOLDIR)/sh-elf-objcopy

BUILDDIR := build
GCC_FLAGS := -m2 -mb -O2 -fomit-frame-pointer -fno-builtin -fno-leading-underscore -nostdlib -c

.PHONY: all clean

all: $(BUILDDIR)/test_vanilla.cue $(BUILDDIR)/test_decomp.cue
	@echo "  sym_0602D814: both disc images ready."

# ─── Shared objects ──────────────────────────────────────────────────────

$(BUILDDIR)/start.o: $(SHARED)/start.s | $(BUILDDIR)
	$(AS) -big -o $@ $<

$(BUILDDIR)/test_data.o: test_data.s | $(BUILDDIR)
	$(AS) -big -o $@ $<

$(BUILDDIR)/harness.o: harness.c | $(BUILDDIR)
	$(GCC) $(GCC_FLAGS) -o $@ $<

# ─── Vanilla build ───────────────────────────────────────────────────────

$(BUILDDIR)/vanilla.o: vanilla.s | $(BUILDDIR)
	$(AS) -big -o $@ $<

$(BUILDDIR)/test_vanilla.elf: $(BUILDDIR)/start.o $(BUILDDIR)/harness.o \
                               $(BUILDDIR)/vanilla.o $(BUILDDIR)/test_data.o
	$(LD) -T test.ld -o $@ $^

$(BUILDDIR)/test_vanilla.bin: $(BUILDDIR)/test_vanilla.elf
	$(OBJCOPY) -O binary $< $@

$(BUILDDIR)/test_vanilla.cue: $(BUILDDIR)/test_vanilla.bin
	python3 $(SHARED)/build_disc.py $< $@ $(SHARED)/IP.BIN

# ─── Decomp build ───────────────────────────────────────────────────────

$(BUILDDIR)/decomp.s: decomp.c | $(BUILDDIR)
	bash $(CYGNUS) $(CURDIR)/decomp.c $(CURDIR)/$(BUILDDIR)/decomp.s sym_0602D814

$(BUILDDIR)/decomp.o: $(BUILDDIR)/decomp.s
	$(AS) -big -o $@ $<

$(BUILDDIR)/test_decomp.elf: $(BUILDDIR)/start.o $(BUILDDIR)/harness.o \
                              $(BUILDDIR)/decomp.o $(BUILDDIR)/test_data.o
	$(LD) -T test.ld -o $@ $^

$(BUILDDIR)/test_decomp.bin: $(BUILDDIR)/test_decomp.elf
	$(OBJCOPY) -O binary $< $@

$(BUILDDIR)/test_decomp.cue: $(BUILDDIR)/test_decomp.bin
	python3 $(SHARED)/build_disc.py $< $@ $(SHARED)/IP.BIN

# ─── Housekeeping ────────────────────────────────────────────────────────

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)
