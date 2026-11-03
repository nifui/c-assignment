#include <stdio.h>
#include "../utils.h"

void pay_amount(int dollars, int* twenties, int* tens, int* fives, int* ones) {

    *twenties = dollars / 20;
    dollars %= 20;

    *tens = dollars / 10;
    dollars %= 10;

    *fives = dollars / 5;
    dollars %= 5;

    *ones = dollars;
}

int main(void) {
    int money;
    if (!read_integer("Enter a dollar amount: ", &money)) {
        return 1;
    }

    int twenties, tens, fives, ones;

    pay_amount(money, &twenties, &tens, &fives, &ones);

    printf("$20 bills: %i\n$10 bills: %i\n$5: %i\n$1: %i\n", twenties, tens, fives, ones);

    return 0;
}
