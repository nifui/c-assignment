#include <stdio.h>
#include <ctype.h>

int main(void) {
    char phone[100];
    // Letter to number LUT
    const char keypad[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6',
                             '6', '6', '7', '7', '7', '7', '8', '8', '8', '9', '9', '9', '9'};

    printf("Enter alphabetic phone number: ");

    if (fgets(phone, sizeof(phone), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    for (int i = 0; phone[i] != '\0' && phone[i] != '\n'; i++) {
        unsigned char c = (unsigned char)phone[i];

        if (isalpha(c)) {
            c = (unsigned char)toupper(c);

            if (c == 'Q' || c == 'Z') {
                fprintf(stderr, "Error: Q and Z are not allowed.\n");
                return 1;
            }

            phone[i] = keypad[c - 'A'];
        }
    }

    printf("Numeric phone number: %s", phone);

    return 0;
}
