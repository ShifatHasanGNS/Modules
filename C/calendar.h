/*
    Module : [ Calendar ]
    AUTHOR : [ MD. Shifat Hasan ]
    Email  : [ shifathasangns@gmail.com ]
*/

#pragma once
#ifndef _CALENDAR_
#define _CALENDAR_

// ---------------------------------------------------------------- //
//                      H E A D E R -- F I L E s                    //
// ---------------------------------------------------------------- //

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

// ---------------------------------------------------------------- //
//                            M A C R O s                           //
// ---------------------------------------------------------------- //

#define Month_1 "January"
#define Month_2 "February"
#define Month_3 "March"
#define Month_4 "April"
#define Month_5 "May"
#define Month_6 "June"
#define Month_7 "July"
#define Month_8 "August"
#define Month_9 "September"
#define Month_10 "October"
#define Month_11 "November"
#define Month_12 "December"

#define W_DAY_1 "Saturday"
#define W_DAY_2 "Sunday"
#define W_DAY_3 "Monday"
#define W_DAY_4 "Tuesday"
#define W_DAY_5 "Wednesday"
#define W_DAY_6 "Thursday"
#define W_DAY_7 "Friday"

// ---------------------------------------------------------------- //
//                        S T R U C T U R E s                       //
// ---------------------------------------------------------------- //

typedef struct
{
    int year;
    int month;
    int day; // monthly day
} Date;

typedef struct
{
    bool is_bc;
    bool is_leapyear;
    int year;
    int month;
    int day; // monthly day
    char *month_fullname;
    char *month_shortname;
    int weekly_day; // weekly day
    char *weekly_day_fullname;
    char *weekly_day_shortname;
    char *date_str;
} Date_Info;

// --------------------------------------------------------------- //
//                        F U N C T I O N s                        //
// --------------------------------------------------------------- //

int sign_int(int number)
{
    return ((number < 0) ? -1 : 1);
}

int int_num_len(int number)
{
    int sign = sign_int(number);
    int abs_num = sign * number;
    int len = (sign < 1) + 1 + floor(log10(abs_num));
    return len;
}

int clip_int(int number, int min, int max)
{
    if (number <= min)
        return min;
    else if (number >= max)
        return max;
    return number;
}

int mod_nonzero(int a, int m)
{
    int result = a % m;
    if (result == 0)
        return m;
    return result;
}

char *str_from_char(char c, int number_of_copy)
{
    char *str = (char *)calloc(number_of_copy, sizeof(char));
    for (int i = 0; i < number_of_copy; i++)
        str[i] = c;
    str[number_of_copy] = '\0';
    return str;
}

char *month_fullname_for(int month)
{
    char *month_fullname = (char *)calloc(10, sizeof(char));
    switch (month)
    {
    case 1:
        strncpy(month_fullname, "January", 8);
        break;
    case 2:
        strncpy(month_fullname, "February", 9);
        break;
    case 3:
        strncpy(month_fullname, "March", 6);
        break;
    case 4:
        strncpy(month_fullname, "April", 6);
        break;
    case 5:
        strncpy(month_fullname, "May", 4);
        break;
    case 6:
        strncpy(month_fullname, "June", 5);
        break;
    case 7:
        strncpy(month_fullname, "July", 5);
        break;
    case 8:
        strncpy(month_fullname, "August", 7);
        break;
    case 9:
        strncpy(month_fullname, "September", 10);
        break;
    case 10:
        strncpy(month_fullname, "October", 8);
        break;
    case 11:
        strncpy(month_fullname, "November", 9);
        break;
    case 12:
        strncpy(month_fullname, "December", 9);
        break;
    default:
        break;
    }
    return month_fullname;
}

char *month_shortname_for(int month)
{
    char *month_shortname = (char *)calloc(4, sizeof(char));
    switch (month)
    {
    case 1:
        strncpy(month_shortname, "Jan", 4);
        break;
    case 2:
        strncpy(month_shortname, "Feb", 4);
        break;
    case 3:
        strncpy(month_shortname, "Mar", 4);
        break;
    case 4:
        strncpy(month_shortname, "Apr", 4);
        break;
    case 5:
        strncpy(month_shortname, "May", 4);
        break;
    case 6:
        strncpy(month_shortname, "Jun", 4);
        break;
    case 7:
        strncpy(month_shortname, "Jul", 4);
        break;
    case 8:
        strncpy(month_shortname, "Aug", 4);
        break;
    case 9:
        strncpy(month_shortname, "Sep", 4);
        break;
    case 10:
        strncpy(month_shortname, "Oct", 4);
        break;
    case 11:
        strncpy(month_shortname, "Nov", 4);
        break;
    case 12:
        strncpy(month_shortname, "Dec", 4);
        break;
    default:
        break;
    }
    return month_shortname;
}

char *weekly_day_fullname_for(int weekly_day)
{
    char *weekly_day_fullname = (char *)calloc(10, sizeof(char));
    switch (weekly_day)
    {
    case 1:
        strncpy(weekly_day_fullname, "Saturday", 9);
        break;
    case 2:
        strncpy(weekly_day_fullname, "Sunday", 7);
        break;
    case 3:
        strncpy(weekly_day_fullname, "Monday", 7);
        break;
    case 4:
        strncpy(weekly_day_fullname, "Tuesday", 8);
        break;
    case 5:
        strncpy(weekly_day_fullname, "Wednesday", 10);
        break;
    case 6:
        strncpy(weekly_day_fullname, "Thursday", 9);
        break;
    case 7:
        strncpy(weekly_day_fullname, "Friday", 7);
        break;
    default:
        break;
    }
    return weekly_day_fullname;
}

char *weekly_day_shortname_for(int weekly_day)
{
    char *weekly_day_shortname = (char *)calloc(4, sizeof(char));
    switch (weekly_day)
    {
    case 1:
        strncpy(weekly_day_shortname, "Sat", 4);
        break;
    case 2:
        strncpy(weekly_day_shortname, "Sun", 4);
        break;
    case 3:
        strncpy(weekly_day_shortname, "Mon", 4);
        break;
    case 4:
        strncpy(weekly_day_shortname, "Tue", 4);
        break;
    case 5:
        strncpy(weekly_day_shortname, "Wed", 4);
        break;
    case 6:
        strncpy(weekly_day_shortname, "Thu", 4);
        break;
    case 7:
        strncpy(weekly_day_shortname, "Fri", 4);
        break;
    default:
        break;
    }
    return weekly_day_shortname;
}

int delta_m_for(int month)
{
    switch (month)
    {
    case 5:
        return 0;
    case 8:
        return 1;
    case 2:
    case 3:
    case 11:
        return 2;
    case 6:
        return 3;
    case 9:
    case 12:
        return 4;
    case 4:
    case 7:
        return 5;
    case 1:
    case 10:
        return 6;
    default:
        return -1;
    }
}

bool is_leapyear(int year)
{
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

int weekly_day_for(Date date)
{
    bool lambda = is_leapyear(date.year) && (date.month > 2);
    bool is_bc = (date.year < 0);
    int days = ceil(1.25 * date.year) + date.day + delta_m_for(date.month) + lambda - is_bc;
    int weekly_day = days % 7;
    if (weekly_day == 0)
        return 7;
    return weekly_day;
}

int last_day_for(int year, int month)
{
    month = clip_int(month, 1, 12);

    if (month == 2 && is_leapyear(year))
        return 28;

    switch (month)
    {
    case 2:
        return 29;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}

int clip_day(Date date)
{
    int last_day = last_day_for(date.year, date.month);
    return clip_int(date.day, 1, last_day);
}

char *refine_date_str(char *date_str)
{
    int len = strlen(date_str);
    if (len < 3)
        return NULL;

    bool is_minus_checked = 0;
    int count = 3, i = 0, r = 0;
    char *refined_date_str = (char *)calloc(len, sizeof(char));

    while (i < len && count > 0)
    {
        if (date_str[i] == '-' && is_minus_checked == 0)
        {
            is_minus_checked = 1;
            refined_date_str[r++] = '-';
        }
        else if (date_str[i] == '/' && (refined_date_str[r - 1] >= '0' && refined_date_str[r - 1] <= '9'))
        {
            is_minus_checked = 1;
            if (--count > 0)
                refined_date_str[r++] = '/';
        }
        else if (date_str[i] >= '0' && date_str[i] <= '9')
            refined_date_str[r++] = date_str[i];
        i++;
    }
    refined_date_str[r] = '\0';

    return refined_date_str;
}

Date new_date_from(char *date_str) // Format for 'date_str': year/month/day | Example: date_str = "2022/11/2"
{
    Date date;
    date_str = refine_date_str(date_str);
    sscanf(date_str, "%d/%d/%d", &date.year, &date.month, &date.day);
    date.month = clip_int(date.month, 1, 12);
    date.day = clip_day(date);
    return date;
}

Date new_date(int year, int month, int day)
{
    Date date;
    date.year = year;
    date.month = clip_int(month, 1, 12);
    date.day = day;
    date.day = clip_day(date);
    return date;
}

Date_Info new_date_info_from(char *date_str) // Format for 'date_str': year/month/day | Example: date_str = "2022/11/2"
{
    Date_Info date_info;
    date_str = refine_date_str(date_str);
    sscanf(date_str, "%d/%d/%d", &date_info.year, &date_info.month, &date_info.day);
    date_info.is_bc = (date_info.year < 0);
    date_info.is_leapyear = is_leapyear(date_info.year);
    date_info.month = clip_int(date_info.month, 1, 12);
    Date date = new_date(date_info.year, date_info.month, date_info.day);
    date_info.day = clip_day(date);
    date.day = date_info.day;
    date_info.month_fullname = month_fullname_for(date_info.month);
    date_info.month_shortname = month_shortname_for(date_info.month);
    date_info.weekly_day = weekly_day_for(date);
    date_info.weekly_day_fullname = weekly_day_fullname_for(date_info.weekly_day);
    date_info.weekly_day_shortname = weekly_day_shortname_for(date_info.weekly_day);
    sprintf(date_info.date_str, "%d/%d/%d", date_info.year, date_info.month, date_info.day);
    return date_info;
}

Date_Info new_date_info(Date date)
{
    Date_Info date_info;
    date_info.is_bc = (date.year < 0);
    date_info.is_leapyear = is_leapyear(date.year);
    date_info.year = date.year;
    date_info.month = clip_int(date.month, 1, 12);
    date = new_date(date_info.year, date_info.month, date.day);
    date_info.day = clip_day(date);
    date.day = date_info.day;
    date_info.month_fullname = month_fullname_for(date_info.month);
    date_info.month_shortname = month_shortname_for(date_info.month);
    date_info.weekly_day = weekly_day_for(date);
    date_info.weekly_day_fullname = weekly_day_fullname_for(date_info.weekly_day);
    date_info.weekly_day_shortname = weekly_day_shortname_for(date_info.weekly_day);
    int len = int_num_len(date_info.year) + int_num_len(date_info.month) + int_num_len(date_info.day) + 3;
    date_info.date_str = (char *)calloc(len, sizeof(char));
    sprintf(date_info.date_str, "%d/%d/%d", date_info.year, date_info.month, date_info.day);
    return date_info;
}

void print_date_str(Date date, bool is_month_as_name)
{
    printf("%d/", date.year);
    if (is_month_as_name)
    {
        printf("%s/", month_fullname_for(date.month));
    }
    else
    {
        if (date.month < 10)
            printf("0");
        printf("%d/", date.month);
    }
    if (date.day < 10)
        printf("0");
    printf("%d", date.day);
    printf(" ");
}

void print_date_str_(Date date, bool is_month_as_name)
{
    print_date_str(date, is_month_as_name);
    printf("\n");
}

void print_date_info(Date date)
{
    Date_Info date_info = new_date_info(date);
    char *bc_or_ad = (char *)calloc(3, sizeof(char));
    if (date_info.is_bc)
        strncpy(bc_or_ad, "BC", 3);
    else
        strncpy(bc_or_ad, "AD", 3);

    char *leapyear_or_not = (char *)calloc(13, sizeof(char));
    if (is_leapyear(date.year))
        strncpy(leapyear_or_not, "Leapyear", 9);
    else
        strncpy(leapyear_or_not, "not Leapyear", 13);

    printf("%d (%s, %s) / %d (%s) / %d (%s)", date_info.year, bc_or_ad, leapyear_or_not, date_info.month, date_info.month_fullname, date_info.day, weekly_day_fullname_for(date_info.weekly_day));
    printf("\n");
}

void print_calendar_month(int year, int month)
{
    month = clip_int(month, 1, 12);
    char *month_name = month_fullname_for(month);

    int title_padding = (22 - (int_num_len(year) + strlen(month_name))) >> 1;
    if (title_padding < 1)
        title_padding = 0;
    printf("%s[ %s, %d ]\n", str_from_char(' ', title_padding), month_name, year);

    printf("SAT SUN MON TUE WED THU FRI\n");

    Date date = new_date(year, month, 1);
    int weekly_day = weekly_day_for(date);

    int padding_for_first_day = (weekly_day << 2) - 3 + (weekly_day < 10);
    printf("%s1", str_from_char(' ', padding_for_first_day));

    for (int i = 2; i <= last_day_for(year, month); i++)
    {
        weekly_day = mod_nonzero((weekly_day + 1), 7);
        if (weekly_day == 1)
            printf("\n ");
        else
            printf("  ");

        printf("%s%d", str_from_char(' ', (i < 10)), i);
    }
    printf("\n");
}

void print_calendar_year(int year)
{
    for (int month = 1; month < 12; month++)
    {
        print_calendar_month(year, month);
        printf("\n\n");
    }
    print_calendar_month(year, 12);
    printf("\n");
}

#endif // _CALENDAR_