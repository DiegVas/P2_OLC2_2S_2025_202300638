# Makefile para compilar y ejecutar main.s con itao.s y ftoa.s en ARM64

AS=aarch64-linux-gnu-as
CC=aarch64-linux-gnu-gcc
QEMU=qemu-aarch64
CFLAGS=-static

OBJDIR=obj
SRC=main.s itao.s ftoa.s concat.s booltoa.s string_compare.s chartoa.s string_indexOf.s integer_indexOf.s append_to_array_integer.s append_to_array_strings.s string_to_double.s string_to_integer.s string_join.s
OBJ=$(patsubst %.s,$(OBJDIR)/%.o,$(SRC))
BIN=main

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.s | $(OBJDIR)
	$(AS) -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

run: all
	$(QEMU) ./$(BIN)

clean:
	rm -rf $(OBJDIR) $(BIN)

.PHONY: all run clean
