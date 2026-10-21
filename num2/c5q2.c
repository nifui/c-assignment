
#include <stdio.h>
#include <string.h>

int main(void) {
    char     buf[7];
    unsigned hours, minutes;

    printf("Enter 24-hour time (HH:MM): ");

    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    if (strlen(buf) != 5 && !(strlen(buf) == 6 && buf[5] == '\n')) {
        printf("Input must be in HH:MM format.\n");
        return 1;
    }

    if (buf[2] != ':' || buf[0] < '0' || buf[0] > '9' || buf[1] < '0' || buf[1] > '9' ||
        buf[3] < '0' || buf[3] > '9' || buf[4] < '0' || buf[4] > '9') {
        printf("Invalid time format.\n");
        return 1;
    }

    hours   = (buf[0] - '0') * 10 + (buf[1] - '0');
    minutes = (buf[3] - '0') * 10 + (buf[4] - '0');

    if (hours > 23 || minutes > 59) {
        printf("Invalid time. Hours must be 00-23 and minutes 00-59.\n");
        return 1;
    }

    const char* period = (hours < 12) ? "AM" : "PM";

    hours %= 12;
    if (hours == 0) {
        hours = 12;
    }

    printf("12-hour time: %02u:%02u %s\n", hours, minutes, period);

    return 0;
}
