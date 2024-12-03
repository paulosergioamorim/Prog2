#include <stdio.h>
#include <math.h>
#include "point.h"

tPonto create_point(float x, float y)
{
    tPonto point = {x, y};
    return point;
}

tPonto read_point()
{
    float x = 0;
    float y = 0;
    scanf("%f %f", &x, &y);
    return create_point(x, y);
}

float get_distance(tPonto pA, tPonto pB)
{
    return sqrt(pow(pA.x - pB.x, 2) + pow(pA.y - pB.y, 2));
}
