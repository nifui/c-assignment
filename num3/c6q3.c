#include "../utils.h"
#include <limits.h>

unsigned int magnitude(int value) {
    return value < 0 ? 0u - (unsigned int)value : (unsigned int)value;
}

unsigned int euclid_gcd(int first, int second) {
    unsigned int a = magnitude(first);
    unsigned int b = magnitude(second);

    while (b != 0) {
        unsigned int remainder = a % b;
        a                      = b;
        b                      = remainder;
    }

    return a;
}

int main(void) {
    int numerator, denominator;

    if (!read_integer("Enter numerator: ", &numerator) ||
        !read_integer("Enter denominator: ", &denominator)) {
        return 1;
    }

    if (denominator == 0) {
        fprintf(stderr, "Error: denominator cannot be zero.\n");
        return 1;
    }

    unsigned int gcd = euclid_gcd(numerator, denominator);

    unsigned int reduced_num = magnitude(numerator) / gcd;
    unsigned int reduced_den = magnitude(denominator) / gcd;

    printf("In lowest terms: %s%u / %u\n", numerator < 0 ? "-" : "", reduced_num, reduced_den);

    return 0;
}
