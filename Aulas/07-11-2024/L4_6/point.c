#include <stdio.h>
#include <math.h>
#include "point.h"

tPonto create_point(int x, int y)
{
    tPonto point = {x, y};
    return point;
}

tPonto read_point()
{
    int x = 0;
    int y = 0;
    scanf("%d %d", &x, &y);
    return create_point(x, y);
}

float get_distance(tPonto pA, tPonto pB)
{
    int xA = get_x(pA);
    int xB = get_x(pB);
    int yA = get_y(pA);
    int yB = get_y(pB);
    return sqrt(pow(xA - xB, 2) + pow(yA - yB, 2));
}

int get_x(tPonto p)
{
    return p.x;
}

int get_y(tPonto p)
{
    return p.y;
}
