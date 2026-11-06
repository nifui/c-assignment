#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

void reverseArray(char** buf, size_t size) {
    if (buf == NULL || size < 2) {
        return;
    }

    for (size_t i = 0; i < size / 2; i++) {
        char* temp            = *(buf + i);
        *(buf + i)            = *(buf + size - 1 - i);
        *(buf + size - 1 - i) = temp;
    }
}

int main(int argc, char* argv[]) {
    // Skip the first arg defined as the program name.
    reverseArray((argv + 1), argc - 1);
    for (int i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");
    return 0;
}
