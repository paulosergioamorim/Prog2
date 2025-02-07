#include "point.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct point
{
    THIS_TYPE x;
    THIS_TYPE y;
};

Point create_point(THIS_TYPE x, THIS_TYPE y)
{
    Point point = malloc(sizeof(struct point));
    point->x = x;
    point->y = y;

    assert(point);

    return point;
}

void print_point(Point point)
{
    char *format = malloc(20 * sizeof(char));

    strncpy(format, "", 15);
    strcat(format, "{");
    strcat(format, THIS_FORMAT);
    strcat(format, ", ");
    strcat(format, THIS_FORMAT);
    strcat(format, "}\n");

    if (format)
        printf(format, point->x, point->y);

    free(format);
}

void free_point(Point point)
{
    if (point)
        free(point);
}