#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

// Function to calculate f(year, month) and return the value of year !!!(Should the function take structure??)

int f(int year, int month) {
    if (month <= 2)
        return year - 1;
    else
        return year;
}

// Function to calculate g(month) !!!(Should the function take structure??)

int g(int month) {
    if (month <= 2)
        return month + 13;
    else
        return month + 1;
}

// Function to calculate N

int calcDays(struct date date) {
    int n;
    
    n = 1461 * f(date.year, date.month) / 4 + 153 * g(date.month) / 5 + date.day;
    
    return n;
}

int main(void) {
    struct date date1, date2;
        
    printf("Enter date #1(mm/dd/yyyy): \n");
    scanf("%i/%i/%i", &date1.month, &date1.day, &date1.year);
    printf("Enter date #1(mm/dd/yyyy): \n");
    scanf("%i/%i/%i", &date2.month, &date2.day, &date2.year);
    
    printf("%i\n", calcDays(date2) - calcDays(date1));
}