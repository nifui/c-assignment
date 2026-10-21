
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char  buf[5];
    char* endptr;
    printf("Enter grade number (0 - 100) : ");
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }
    long score = strtol(buf, &endptr, 10);
    if (endptr == buf) {
        fprintf(stderr, "Invalid score.\n");
        return 1;
    }
    while (*endptr == ' ' || *endptr == '\t' || *endptr == '\n' || *endptr == '\r') {
        endptr++;
    }
    if (*endptr != '\0' || score < 0 || score > 100) {
        fprintf(stderr, "Score must be between 0 and 100.\n");
        return 1;
    }
    char grade;
    switch (score / 10) {
    case 10:
    case 9:
        grade = 'A';
        break;
    case 8:
        grade = 'B';
        break;
    case 7:
        grade = 'C';
        break;
    case 6:
        grade = 'D';
        break;
    default:
        grade = 'F';
        break;
    }

    printf("Grade is: %c\n", grade);

    return 0;
}
