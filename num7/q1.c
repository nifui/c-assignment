#include <stddef.h>
#include <stdio.h>
#include "../utils.h"

#define SIZE (sizeof(country_codes) / sizeof(country_codes[0]))

typedef struct dialing_code {
    char* country;
    int   code;
} dialing_code;

const dialing_code country_codes[] = {
    {"United States", 1}, {"Russia", 7},           {"Vietnam", 8},
    {"Egypt", 20},        {"South Africa", 27},    {"France", 33},
    {"Spain", 34},        {"Italy", 39},           {"United Kingdom", 44},
    {"Germany", 49},      {"Mexico", 52},          {"Argentina", 54},
    {"Brazil", 55},       {"Colombia", 57},        {"Indonesia", 62},
    {"Philippines", 63},  {"Thailand", 66},        {"Japan", 81},
    {"South Korea", 82},  {"China", 86},           {"India", 91},
    {"Turkey", 90},       {"Burma (Myanmar)", 95}, {"Iran", 98},
    {"Bangladesh", 880},  {"Nigeria", 234},        {"Congo, Dem. Rep. of", 243},
    {"Sudan", 249},       {"Ethiopia", 251},       {"Ukraine", 380}};

const char* linear_search(int code) {

    for (int i = 0; i < SIZE; i++) {

        if (country_codes[i].code == code) {
            return country_codes[i].country;
        }
    }

    return NULL;
}

int main(void) {
    char        input[100];
    int         code;
    const char* country;
    printf("Enter a dialing code to check: ");
    read_integer(input, &code);

    country = linear_search(code);

    if (country != NULL) {
        printf("Dialing code +%d belongs to %s.\n", code, country);
    } else {
        printf("Error: No country found for dialing code +%d.\n", code);
    }

    return 0;
}
