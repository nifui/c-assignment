#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char input[32];
    char isbn[14];
    int  len = 0;
    int  sum = 0;

    printf("Enter ISBN-13: ");

    if (fgets(input, sizeof input, stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }

    for (int i = 0; input[i] != '\0'; i++) {
        unsigned char c = (unsigned char)input[i];

        if (c == '-' || isspace(c)) {
            continue;
        }

        if (!isdigit(c) || len >= 13) {
            printf("Invalid ISBN-13 format.\n");
            return 1;
        }

        isbn[len++] = (char)c;
    }

    isbn[len] = '\0';

    if (len != 13) {
        printf("ISBN must contain exactly 13 digits.\n");
        return 1;
    }

    // Validate ISBN-13 check digit.
    for (int i = 0; i < 12; i++) {
        sum += (isbn[i] - '0') * (i % 2 == 0 ? 1 : 3);
    }

    int check = (10 - sum % 10) % 10;

    if (check != isbn[12] - '0') {
        printf("Invalid ISBN-13 check digit.\n");
        return 1;
    }

    printf("\nISBN-13 Breakdown\n");
    printf("Full ISBN:      %s\n", isbn);
    printf("Prefix:         %.3s\n", isbn);
    printf("Check digit:    %c\n", isbn[12]);
    printf("Check digit is valid.\n");

    return 0;
}
