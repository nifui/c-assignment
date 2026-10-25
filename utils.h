#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

int read_integer(const char* prompt, int* result) {
    char  buf[12];
    char* end;

    printf("%s", prompt);

    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 0;
    }

    if (strchr(buf, '\n') == NULL && !feof(stdin)) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }
        fprintf(stderr, "Input is too long.\n");
        return 0;
    }

    errno      = 0;
    long value = strtol(buf, &end, 10);

    if (end == buf || errno == ERANGE || value < INT_MIN || value > INT_MAX) {
        fprintf(stderr, "Invalid integer.\n");
        return 0;
    }

    while (*end != '\0') {
        if (*end != '\n' && *end != ' ' && *end != '\t' && *end != '\r') {
            fprintf(stderr, "Invalid characters in input.\n");
            return 0;
        }
        end++;
    }

    *result = (int)value;
    return 1;
}
