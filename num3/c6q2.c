
#include <stdio.h>
#include <limits.h>
#include "../utils.h"

unsigned int euclid_gcd(int first, int second) {
    unsigned int a = (first < 0) ? 0u - (unsigned int)first : (unsigned int)first;

    unsigned int b = (second < 0) ? 0u - (unsigned int)second : (unsigned int)second;

    while (b != 0) {
        unsigned int remainder = a % b;
        a                      = b;
        b                      = remainder;
    }

    return a;
}

int main(void) {
    int first, second;

    if (!read_integer("Enter first number: ", &first)) {
        return 1;
    }

    if (!read_integer("Enter second number: ", &second)) {
        return 1;
    }

    printf("%u\n", euclid_gcd(first, second));
    return 0;
}
