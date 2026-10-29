
CC = gcc
CFLAGS = -std=c11 -lm

SOURCES := $(shell find . -name '*.c')
TARGETS := $(SOURCES:.c=)

.PHONY: all clean

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)
