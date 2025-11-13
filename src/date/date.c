#include <stdio.h>
#include <time.h>
#include "date.h"

int getDay(){

    struct tm *actual_date;

    time_t seconds;

    time(&seconds);

    actual_date = localtime(&seconds);

    return actual_date->tm_mday;
}

int getMonth(){
    struct tm *actual_date;

    time_t seconds;

    time(&seconds);

    actual_date = localtime(&seconds);

    return (actual_date->tm_mon) + 1;
}

int getYear(){
    struct tm *actual_date;

    time_t seconds;

    time(&seconds);

    actual_date = localtime(&seconds);

    return (actual_date->tm_year) + 1900;
}