# Unit test for FUN_0602D8C6 (position writer core)
# Run from WSL: make clean && make

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
	@echo "  FUN_0602D8C6: both disc images ready."

$(BUILDDIR)/start.o: $(SHARED)/start.s | $(BUILDDIR)
	$(AS) -big -o $@ $<

$(BUILDDIR)/test_data.o: test_data.s | $(BUILDDIR)
	$(AS) -big -o $@ $<

$(BUILDDIR)/stubs.o: stubs.s | $(BUILDDIR)
	$(AS) -big -o $@ $<

$(BUILDDIR)/harness.o: harness.c | $(BUILDDIR)
	$(GCC) $(GCC_FLAGS) -o $@ $<

# Vanilla
$(BUILDDIR)/vanilla.o: vanilla.s | $(BUILDDIR)
	$(AS) -big -o $@ $<

$(BUILDDIR)/test_vanilla.elf: $(BUILDDIR)/start.o $(BUILDDIR)/harness.o \
                               $(BUILDDIR)/vanilla.o $(BUILDDIR)/stubs.o $(BUILDDIR)/test_data.o
	$(LD) -T test.ld -o $@ $^

$(BUILDDIR)/test_vanilla.bin: $(BUILDDIR)/test_vanilla.elf
	$(OBJCOPY) -O binary $< $@

$(BUILDDIR)/test_vanilla.cue: $(BUILDDIR)/test_vanilla.bin
	python3 $(SHARED)/build_disc.py $< $@ $(SHARED)/IP.BIN

# Decomp
$(BUILDDIR)/decomp.s: decomp.c | $(BUILDDIR)
	bash $(CYGNUS) $(CURDIR)/decomp.c $(CURDIR)/$(BUILDDIR)/decomp.s FUN_0602D8C6

$(BUILDDIR)/decomp.o: $(BUILDDIR)/decomp.s
	$(AS) -big -o $@ $<

$(BUILDDIR)/test_decomp.elf: $(BUILDDIR)/start.o $(BUILDDIR)/harness.o \
                              $(BUILDDIR)/decomp.o $(BUILDDIR)/stubs.o $(BUILDDIR)/test_data.o
	$(LD) -T test.ld -o $@ $^

$(BUILDDIR)/test_decomp.bin: $(BUILDDIR)/test_decomp.elf
	$(OBJCOPY) -O binary $< $@

$(BUILDDIR)/test_decomp.cue: $(BUILDDIR)/test_decomp.bin
	python3 $(SHARED)/build_disc.py $< $@ $(SHARED)/IP.BIN

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)
