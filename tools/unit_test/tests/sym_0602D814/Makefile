# Unit test for sym_0602D814 (speed writer)
#
# Builds two disc images:
#   test_vanilla.cue  — vanilla assembly version
#   test_decomp.cue   — C decompiled version
# Both run the same harness, sweep identical inputs, write results to memory.
# Compare results via MCP: read_memory at _results_start.

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
	wsl -d Ubuntu -- python3 $(shell wslpath -a $(SHARED)/build_disc.py 2>/dev/null || echo $(SHARED)/build_disc.py) \
		$(shell wslpath -a $< 2>/dev/null || echo $<) \
		$(shell wslpath -a $@ 2>/dev/null || echo $@) \
		$(shell wslpath -a $(SHARED)/IP.BIN 2>/dev/null || echo $(SHARED)/IP.BIN)

# ─── Decomp build ───────────────────────────────────────────────────────

$(BUILDDIR)/decomp.s: decomp.c | $(BUILDDIR)
	wsl -d Ubuntu -- bash -lc "cd $(shell wslpath -a $(PROJDIR)) && \
		bash tools/cygnus_compile.sh \
		$(shell wslpath -a $(CURDIR)/decomp.c) \
		$(shell wslpath -a $(CURDIR)/$(BUILDDIR)/decomp.s) \
		decomp_sym_0602D814"

$(BUILDDIR)/decomp.o: $(BUILDDIR)/decomp.s
	$(AS) -big -o $@ $<

$(BUILDDIR)/test_decomp.elf: $(BUILDDIR)/start.o $(BUILDDIR)/harness.o \
                              $(BUILDDIR)/decomp.o $(BUILDDIR)/test_data.o
	$(LD) -T test.ld -o $@ $^

$(BUILDDIR)/test_decomp.bin: $(BUILDDIR)/test_decomp.elf
	$(OBJCOPY) -O binary $< $@

$(BUILDDIR)/test_decomp.cue: $(BUILDDIR)/test_decomp.bin
	wsl -d Ubuntu -- python3 $(shell wslpath -a $(SHARED)/build_disc.py 2>/dev/null || echo $(SHARED)/build_disc.py) \
		$(shell wslpath -a $< 2>/dev/null || echo $<) \
		$(shell wslpath -a $@ 2>/dev/null || echo $@) \
		$(shell wslpath -a $(SHARED)/IP.BIN 2>/dev/null || echo $(SHARED)/IP.BIN)

# ─── Housekeeping ────────────────────────────────────────────────────────

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)
