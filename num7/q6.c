#include <stdio.h>

typedef struct date {
    int month;
    int day;
    int year;
} date;

int compare_dates(date d1, date d2) {

    if (d1.year < d2.year)
        return -1;

    if (d1.year > d2.year)
        return 1;

    if (d1.month < d2.month)
        return -1;

    if (d1.month > d2.month)
        return 1;

    if (d1.day < d2.day)
        return -1;

    if (d1.day > d2.day)
        return 1;

    return 0;
}

int main(void) {

    date date1, date2;
    int  result;

    printf("Enter the first date (mm/dd/yy): ");

    if (scanf("%d/%d/%d", &date1.month, &date1.day, &date1.year) != 3) {
        printf("Invalid date format.\n");
        return 1;
    }

    printf("Enter the second date (mm/dd/yy): ");

    if (scanf("%d/%d/%d", &date2.month, &date2.day, &date2.year) != 3) {
        printf("Invalid date format.\n");
        return 1;
    }

    result = compare_dates(date1, date2);

    if (result < 0) {
        printf("The first date comes before the second date.\n");
    } else if (result > 0) {
        printf("The first date comes after the second date.\n");
    } else {
        printf("Both dates are equal.\n");
    }

    return 0;
}
