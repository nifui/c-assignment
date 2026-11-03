#include <stdio.h>

void swap(int* a, int* b) {
    int c = *a;
    *a    = *b;
    *b    = c;
}

int main(void) {
    int x = 3, y = 9;
    printf("Before: x=%d y=%d\n", x, y);
    swap(&x, &y);
    printf("After: x=%d y=%d\n", x, y);
    return 0;
}
