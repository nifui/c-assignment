#include <stddef.h>
#include <stdio.h>
#include <limits.h>

void minMax(int* buf, size_t size, int* low, int* high) {
    int h = INT_MIN;
    int l = INT_MAX;
    for (size_t i = 0; i < size; i++) {
        if (*(buf + i) < l) {
            l = *(buf + i);
        }
        if (*(buf + i) > h) {
            h = *(buf + i);
        }
    }
    *high = h;
    *low  = l;
}

int main(void) {
    int data[5] = {4, -2, 9, 0, 7};
    int lo, hi;
    minMax(data, 5, &lo, &hi);
    printf("min = %d, max = %d\n", lo, hi);
    return 0;
}
