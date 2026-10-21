
#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[14];
    int  sum = 0;

    printf("Enter 12 EAN digits: ");

    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    buf[strcspn(buf, "\n")] = '\0';

    if (strlen(buf) != 12) {
        printf("Input must contain exactly 12 digits.\n");
        return 1;
    }

    for (int i = 0; i < 12; i++) {
        if (buf[i] < '0' || buf[i] > '9') {
            printf("Input must contain digits only.\n");
            return 1;
        }
    }

    for (int i = 0; i < 12; i += 2) {
        sum += (buf[i] - '0');
        sum += (buf[i + 1] - '0') * 3;
    }
    int check_digit = (10 - sum % 10) % 10;
    printf("EAN-13: %s%d\n", buf, check_digit);

    return 0;
}
