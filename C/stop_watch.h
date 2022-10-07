#ifndef _STOP_WATCH_H_
#define _STOP_WATCH_H_

#include <time.h>
#include <string.h>

typedef enum
{
    nanosecond,
    microsecond,
    milisecond,
    second,
} time_unit;

typedef struct timespec TimeStamp;

#define TIME(_TIME_STAMP_) clock_gettime(CLOCK_MONOTONIC, &_TIME_STAMP_);

double time_elapsed(TimeStamp before, TimeStamp after, time_unit unit) // returns elapsed time according to the time_unit.
{
    double before_nsec = before.tv_nsec;
    double after_nsec = after.tv_nsec;
    double unit_value = -1.0;
    switch (unit)
    {
        case nanosecond: unit_value = 1; break;
        case microsecond: unit_value = 1e3; break;
        case milisecond: unit_value = 1e6; break;
        case second: unit_value = 1e9; break;
        default: break;
    }
    double elapsed = (after_nsec - before_nsec) / (unit_value);
    return elapsed;
}

void print_elapsed_time(TimeStamp before, TimeStamp after, time_unit unit)
{
    char unit_str[13];
    switch (unit)
    {
        case nanosecond: strncpy(unit_str, "nanoseconds", 13); break;
        case microsecond: strncpy(unit_str, "microseconds", 13); break;
        case milisecond: strncpy(unit_str, "miliseconds", 13); break;
        case second: strncpy(unit_str, "seconds", 13); break;
        default: return;
    }
    printf("[ Time Elapsed : %lf %s ]\n", time_elapsed(before, after, unit), unit_str);
}

#endif


// Example: //

/*

#include "stop_watch.h"

int main(int argc, char *argv[])
{
    TimeStamp before, after;

    TIME(before);
    ...your code here of which runtime you want to measure...
    TIME(after);
    
    print_elapsed_time(before, after, microsecond);  // you can use other time units as well.
}

*/