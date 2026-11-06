#include <stddef.h>
#include <stdio.h>
#include <string.h>

void smallest_word(char** prev, char* new_word) {
    if (**prev == '\0' || strcmp(new_word, *prev) < 0) {
        strcpy(*prev, new_word);
    }
}

void biggest_word(char** prev, char* new_word) {
    if (**prev == '\0' || strcmp(new_word, *prev) > 0) {
        strcpy(*prev, new_word);
    }
}

int main() {
    char buffer[21];
    char smallest_buffer[21];
    char biggest_buffer[21];

    char* smallest = smallest_buffer;
    char* biggest  = biggest_buffer;

    size_t str_size = 0;

    smallest[0] = '\0';
    biggest[0]  = '\0';

    // Includes the null terminator
    while (str_size != 5) {
        printf("\nEnter word: ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            break;

        str_size = strlen(buffer);

        buffer[strcspn(buffer, "\n")] = '\0';

        smallest_word(&smallest, buffer);
        biggest_word(&biggest, buffer);
    }

    printf("Smallest word: %s\n", smallest);
    printf("Biggest word: %s\n", biggest);

    return 0;
}
