#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char   buf[128];
    char*  end;
    double amount;
    printf("Input number x: ");
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        if (ferror(stdin)) {
            perror("Error reading file with fgets");
        } else if (feof(stdin)) {
            printf("End of file reached.\n");
        }
        return 0;
    }
    amount = strtod(buf, &end);
    if (end == buf) {
        printf("Invalid number.\n");
        return 0;
    }
    double result =
        (((((3.0 * amount + 2.0) * amount - 5.0) * amount - 1.0) * amount + 7.0) * amount - 6.0);

    printf("Polynomial value for 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 with x: %f \n", result);
}
