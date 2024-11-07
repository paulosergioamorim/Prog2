#ifndef _POINT_
#define _POINT_

#include <math.h>

typedef struct
{
    int x;
    int y;
} tPonto;

tPonto create_point(int x, int y);
tPonto read_point();
int get_x(tPonto p);
int get_y(tPonto p);
float get_distance(tPonto pA, tPonto pB);

#endif