#include <stdio.h>
#include <string.h>
#include <stddef.h>

void reverseArray(char* buf, size_t size) {
    if (buf == NULL || size < 2) {
        return;
    }

    for (size_t i = 0; i < size / 2; i++) {
        char temp             = *(buf + i);
        *(buf + i)            = *(buf + size - 1 - i);
        *(buf + size - 1 - i) = temp;
    }
}

int main(void) {
    char input[256];

    printf("Enter a message: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    reverseArray(input, strlen(input));

    printf("%s\n", input);

    return 0;
}
