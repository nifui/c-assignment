#include <stdio.h>

int main(void) {
    char number[16];
    int  a, b, c;

    printf("Enter phone number (xxx) xxx-xxxx: ");

    if (scanf(" (%3d) %3d-%4d", &a, &b, &c) != 3) {
        printf("Invalid telephone number.\n");
        return 1;
    }

    printf("%03d.%03d.%04d\n", a, b, c);

    return 0;
}
