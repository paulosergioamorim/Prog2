#ifndef _DATE_
#define _DATE_

typedef struct
{
    int d;
    int m;
    int y;
} date;

date read_date();
date next_date(date date);
void print_date(date date);
int is_before(date dA, date dB);
#endif