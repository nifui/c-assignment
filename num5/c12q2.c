#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(const char* str) {
    if (str == NULL) {
        return false;
    }

    const char* left  = str;
    const char* right = str + strlen(str);

    if (left == right) {
        return true;
    }

    right--;

    while (left < right) {
        while (left < right && !isalpha((unsigned char)*left)) {
            left++;
        }
        while (left < right && !isalpha((unsigned char)*right)) {
            right--;
        }
        if (tolower((unsigned char)*left) != tolower((unsigned char)*right)) {
            return false;
        }

        left++;
        right--;
    }

    return true;
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
