#include <stdio.h>
#include <stdlib.h>
#define TAX 1.05

int main(void) {
    char   buf[128];
    char*  end;
    double amount;
    printf("Input money count: ");
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
    printf("With tax added: %f \n", TAX * amount);
    return 0;
}
