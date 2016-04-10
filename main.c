/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 10, 2016, 2:07 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Chapter 9, Exercise 5
 */

/* Write a function called clockKeeper that takes as its argument a dateAndTime
 * structure as defined in this chapter. The function should call the timeUpdate
 * function, and if the time reaches midnight, the function should call the
 * dateUpdate function to switch over to the next day. Have the function return
 * the updated dateAndTime structure. */

struct date {
    int month;
    int day;
    int year;
};

struct time {
    int hour;
    int minutes;
    int seconds;
};

struct dateAndTime {
    struct date sdate;
    struct time stime;
};

// Function to update time by one second

struct time timeUpdate(struct time now) {
    ++now.seconds;
    
    if (now.seconds == 60) {        // next minute
        now.seconds = 0;
        ++now.minutes;
        
        if (now.minutes == 60) {    // next hour
            now.minutes = 0;
            ++now.hour;
            
            if (now.hour == 24)     // midnight
                now.hour = 0;
        }
    }
    
    return now;
}

// Function to find the number of days in a month

int numberOfDays(struct date d) {
    int days;
    bool isLeapYear(struct date d);
    const int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if (isLeapYear && d.month == 2)
        days = 29;
    else
        days = daysPerMonth[d.month - 1];
    
    return days;
}

// Function to determine if it's a leap year

bool isLeapYear(struct date d) {
    bool leapYearFlag;
    
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
        leapYearFlag = true;    // It's a leap year
    else
        leapYearFlag = false;   // Not a leap year
    
    return leapYearFlag;
}

// Function to calculate tomorrow's date

struct date dateUpdate(struct date today) {
    struct date tomorrow;
    int numberOfDays(struct date d);
    
    if (today.day != numberOfDays(today)) {
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    } else if (today.month == 12) {     // end of year
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    } else {                            // end of month
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }
    
    return tomorrow;
}

// And here's the fuckin' clockKeeper function

int main(int argc, char** argv) {
    struct dateAndTime test;
    
    printf("Enter date (mm/dd/yyyy): ");
    scanf("%i/%i/%i", &test.sdate.month, &test.sdate.day, &test.sdate.year);
    printf("\nEnter time (hh:mm:ss): ");
    scanf("%i:%i:%i", &test.stime.hour, &test.stime.minutes, &test.stime.seconds);
    
    //test.stime = timeUpdate(test.stime);
    
    printf("\nUpdated time: %i:%i:%i", test.stime.hour, test.stime.minutes, test.stime.seconds);
    
    return (EXIT_SUCCESS);
}

