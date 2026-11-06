#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(const char* str) {
    if (str == NULL) {
        return false;
    }

    char   cleaned[256];
    char   reversed[256];
    size_t j = 0;
    size_t length;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (isalpha((unsigned char)str[i])) {
            cleaned[j++] = (char)tolower((unsigned char)str[i]);
        }
    }

    cleaned[j] = '\0';
    length     = strlen(cleaned);

    for (size_t i = 0; i < length; i++) {
        reversed[i] = cleaned[length - 1 - i];
    }

    reversed[length] = '\0';

    return strcmp(cleaned, reversed) == 0;
}

int main(void) {
    char input[256];

    printf("Enter a message: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    printf("%s\n", isPalindrome(input) ? "Palindrome" : "Not a palindrome");

    return 0;
}
