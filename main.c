/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: georgi
 *
 * Created on April 8, 2016, 2:13 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Chapter 9, Exercise 3
 */

/*
 * Write a function elapsed_time that takes as its arguments two time structures
 * and returns a time structure that represents the elapsed time (in hours,
 * minutes, and seconds) between the two times. So the call
 * 
 * elapsed_time(time1, time2)
 * 
 * where time1 represents 3:45:15 and time2 represents 9:44:03, should return a
 * time structure that represents 5 hours, 58 minutes, and 48 seconds. Be 
 * careful with times that cross midnight. 
 */

/*
 * Algorithm that I will use:
 * 1. Define/declare the struct that will hold the time
 * 2. For each 60 seconds passed a minute should be added 
 *    For each 60 minutes passed an hour should be added.
 *    I need a function to update elapsed time until it reaches time 2
 *    Maybe a loop
 * 3. Allow the user to enter time1 and time2 and store them appropriately
 * 4. Determine how to calculate the elapsed time between time1 and time2
 */

struct time {
    int hour[24] = {0,1,2,3,4,5,6,7,8,9,10,11,12,
    13,14,15,16,17,18,19,20,21,22,23};
    
    int minutes[60] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,
    23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47
    48,49,50,51,52,53,54,55,56,57,58,59,60};
    
    int seconds[60] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,
    23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47
    48,49,50,51,52,53,54,55,56,57,58,59,60};
};

/*I want to try to update time1 until it reaches time2 but...*/
// Function to update the time by one second

struct time timeUpdate(struct time t) {
    ++t.seconds;
    
    if (t.seconds == 60) {      // next minute
        t.seconds = 0;
        ++t.minutes;
        
        if (t.minutes == 60) {  // next hour
            t.minutes = 0;
            ++t.hour;
            if (t.hour == 24)   // midnight
                t.hour = 0;
        }
        
    }
    
    return t;
}

struct time elapsed_time(struct time t1, struct time t2) {
    struct time t;
    int time_counter = 1;
    // the function should return a struct time variale with hour, minutes, secs
    /*The function needs to know that hours, mins and secs contain 60*/
    
    t.hour = t2.hour - t1.hour;
    t.minutes = t2.minutes - t1.minutes;
    t. seconds = t2.seconds - t1.seconds;
    
    /*Maybe use the timeUpdate function to calculate elapsed time second by
     * second, min by min, and hour by hour */
    /* Time update of time1 should repeat until time is reached */
    /*
    while (time_counter) {
        
    }
    */
    
    return t;
}

int main(int argc, char** argv) { 
    struct time time1, time2, time3;;
    
    printf("Enter time1(mm:hh:ss): \n");
    scanf("%i:%i:%i", &time1.hour, &time1.minutes, &time1.seconds);
    printf("Enter time2(mm:hh:ss): \n");
    scanf("%i:%i:%i", &time2.hour, &time2.minutes, &time2.seconds);
    
    /* Function that takes two structures and returns a structure???
     * The returned structure will be assigned to a struct time variable
     * and then it's members printed out. */
    time3 = elapsed_time(time1, time2);
    printf("%i:%i:%i\n", time3.hour, time3.minutes, time3.seconds);
    
    /* Now hot to calculate elapsed time ???*/
    

    return (EXIT_SUCCESS);
}

