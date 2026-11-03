#include <stddef.h>
#include <stdio.h>

void reverseArray(int* buf, size_t size) {
    if (buf == NULL || size < 2) {
        return;
    }

    for (size_t i = 0; i < size / 2; i++) {
        int temp              = *(buf + i);
        *(buf + i)            = *(buf + size - 1 - i);
        *(buf + size - 1 - i) = temp;
    }
}

int main(void) {
    int data[6] = {1, 2, 3, 4, 5, 6};
    reverseArray(data, 6);
    for (int i = 0; i < 6; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}
