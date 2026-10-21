CC = gcc
CFLAGS = -std=c11

SOURCES := $(shell find . -name '*.c')
TARGETS := $(SOURCES:.c=)

.PHONY: all clean

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)
