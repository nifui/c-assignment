#include <stdio.h>
#include <ctype.h>

int main(void) {
    char word[100];
    // Score LUT
    const int scores[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                            1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    printf("Enter a word: ");

    if (fgets(word, sizeof(word), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    int total = 0;

    for (int i = 0; word[i] != '\0' && word[i] != '\n'; i++) {
        unsigned char c = (unsigned char)word[i];

        if (!isalpha(c)) {
            fprintf(stderr, "Error: input must contain only letters.\n");
            return 1;
        }

        c = (unsigned char)toupper(c);
        total += scores[c - 'A'];
    }

    printf("Scrabble value: %d\n", total);

    return 0;
}
