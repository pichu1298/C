#include <stdio.h>

//chapter 16 Q 1
//Write a program that asks the user to enter an
//international dialing code
//and then looks it up in the country_codes array
//see Section 16.3
//if it finds the code, the program should display
//the name of the corresponding country;
//if not, the program should print an error message

struct dialing_code {
    char *country;
    int code;
};

const struct dialing_code country_codes[] = {
    {"Argentina", 54},
    {"Bangladesh", 880},
    {"Brazil", 55},
    {"Burma (Myanmar)", 95},
    {"China", 86},
    {"Colombia", 57},
    {"Congo, Dem. Rep. of", 243},
    {"Egypt", 20},
    {"Ethiopia", 251},
    {"France", 33},
    {"Germany", 49},
    {"India", 91},
    {"Indonesia", 62},
    {"Iran", 98},
    {"Italy", 39},
    {"Japan", 81},
    {"Mexico", 52},
    {"Nigeria", 234},
    {"Pakistan", 92},
    {"Philippines", 63},
    {"Poland", 48},
    {"Russia", 7},
    {"South Africa", 27},
    {"South Korea", 82},
    {"Spain", 34},
    {"Sudan", 249},
    {"Thailand", 66},
    {"Turkey", 90},
    {"Ukraine", 380},
    {"United Kingdom", 44},
    {"United States", 1},
    {"Vietnam", 84}
};


void question_one(){
    int code;
    printf("Enter an international dialing code: ");
    scanf("%d", &code);
    for (int i = 0; i < sizeof(country_codes) / sizeof(country_codes[0]); i++) {
        if (country_codes[i].code == code) {
            printf("The country corresponding to dialing code %d is %s.\n", code, country_codes[i].country);
            return;
        }
    }
    printf("Code not found.\n");

}

//Chapter 16 Q 6
//Modify programming project 9 from chapter 5
//so that each date entered by the user is stored in
//a date structure (see exercise 5). Incorporate
//the compare_dates function of Exercise 5
//into your program

//Exercise 5
//Write the following functions, assuming that the date structure contains
//three members: month, day, and year (all of type int).
//
//(a) int day_of_year(struct date d);
//    Returns the day of the year (an integer between 1 and 366) that
//    corresponds to the date d.
//
//(b) int compare_dates(struct date d1, struct date d2);
//    Returns -1 if d1 is an earlier date than d2, +1 if d1 is a later date
//    than d2, and 0 if d1 and d2 are the same.

struct date{
    int month;
    int day;
    int year;
};

int day_of_year(struct date d){
    // This function calculates the day of the year for the given date.
    // It takes into account leap years and the number of days in each month.
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day_of_year = d.day;

    // Check for leap year
    if ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0)) {
        days_in_month[2] = 29; // February has 29 days in a leap year
    }

    for (int i = 1; i < d.month; i++) {
        day_of_year += days_in_month[i];
    }

    return day_of_year;
}

int compare_dates(struct date d1, struct date d2){
    // This function compares two dates and returns:
    // -1 if d1 is earlier than d2
    // +1 if d1 is later than d2
    // 0 if d1 and d2 are the same
    if (d1.year < d2.year) {
        return -1;
    } else if (d1.year > d2.year) {
        return 1;
    } else {
        if (d1.month < d2.month) {
            return -1;
        } else if (d1.month > d2.month) {
            return 1;
        } else {
            if (d1.day < d2.day) {
                return -1;
            } else if (d1.day > d2.day) {
                return 1;
            } else {
                return 0; // Dates are the same
            }
        }
    }
}

void exercise_five(){
    day_of_year((struct date){3, 15, 2024}); // Example usage
    compare_dates((struct date){3, 15, 2024}, (struct date){3, 16, 2024}); // Example usage
}

void question_six(){
    struct date user_date;
    printf("Enter a date (month day year): ");
    scanf("%d %d %d", &user_date.month, &user_date.day, &user_date.year);
    printf("The day of the year is: %d\n", day_of_year(user_date));

    printf("Enter another date to compare (month day year): ");
    struct date another_date;
    scanf("%d %d %d", &another_date.month, &another_date.day, &another_date.year);
    printf("Comparison result: %d\n", compare_dates(user_date, another_date));
}

int main(){
    question_one();
    question_six();
    return 0;
}