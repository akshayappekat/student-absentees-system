#include <stdio.h>
#include <time.h>

struct Date {
    int day;
    int month;
    int year;
};

int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int getDayOfWeek(int day, int month, int year) {
    struct tm t = {0};
    t.tm_mday = day;
    t.tm_mon = month - 1;
    t.tm_year = year - 1900;
    mktime(&t);
    return t.tm_wday;
}

int isPublicHoliday(struct Date d) {
    if ((d.day == 26 && d.month == 1) ||
        (d.day == 15 && d.month == 8) ||
        (d.day == 2 && d.month == 10))
        return 1;
    return 0;
}

int main() {
    int n;
    printf("Enter number of absent dates: ");
    scanf("%d", &n);

    struct Date absents[n];

    printf("Enter %d absent dates (day month year):\n", n);
    for (int i = 0; i < n; i++) {
        printf("Absent date %d: ", i + 1);
        scanf("%d %d %d", &absents[i].day, &absents[i].month, &absents[i].year);
    }

    printf("\nAbsent dates (only when college is open):\n");
    printf("------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        struct Date d = absents[i];
        int dow = getDayOfWeek(d.day, d.month, d.year);
        int isWeekend = (dow == 0 || dow == 6);
        int isHoliday = isPublicHoliday(d);

        if (!isWeekend && !isHoliday) {
            const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
            printf("%02d-%02d-%04d (%s)\n", d.day, d.month, d.year, days[dow]);
        }
    }

    return 0;
}
