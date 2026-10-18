CC = gcc
CFLAGS = -std=c11
SOURCES = $(wildcard *.c)
TARGETS = $(SOURCES:.c=)

.PHONY: all clean

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)
