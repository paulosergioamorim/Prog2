#include <stdio.h>
#include "date.h"

date read_date()
{
    int d = 0;
    int m = 0;
    int y = 0;
    date date = {0, 0, 0};
    scanf("%d %d %d", &d, &m, &y);

    if (m > 12)
        m = 12;
    if (m == 2)
    {
        if (d > 28)
            d = 28;
    }
    else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        if (d > 31)
            d = 31;
    }
    else if (d > 30)
        d = 30;

    date.d = d;
    date.m = m;
    date.y = y;

    return date;
}

date next_date(date date)
{
    if (date.m == 2)
    {
        if (date.d == 28)
        {
            date.d = 1;
            date.m++;
        }
        else
            date.d++;
    }
    else if (date.m == 12)
    {
        if (date.d == 31)
        {
            date.d = 1;
            date.m = 1;
            date.y++;
        }
        else
            date.d++;
    }
    else if (date.m == 1 || date.m == 3 || date.m == 5 || date.m == 7 || date.m == 8 || date.m == 10)
    {
        if (date.d == 31)
        {
            date.d = 1;
            date.m++;
        }
        else
            date.d++;
    }
    else
    {
        if (date.d == 30)
        {
            date.d = 1;
            date.m++;
        }
        else
            date.d++;
    }

    return date;
}

void print_date(date date)
{
    if (date.d < 10)
        printf("'0%d/", date.d);
    else
        printf("'%d/", date.d);
    if (date.m < 10)
        printf("0%d/", date.m);
    else
        printf("%d/", date.m);
    printf("%d'\n", date.y);
}

int is_before(date dA, date dB)
{
    if (dA.y < dB.y)
        return 1;
    if (dA.y == dB.y)
    {
        if (dA.m < dB.m)
            return 1;
        if (dA.m == dB.m)
            return dA.d < dB.d;
        return 0;
    }
    return 0;
}