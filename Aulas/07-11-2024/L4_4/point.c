#include <stdio.h>
#include <math.h>
#include "point.h"

Point create_point(int x, int y)
{
    Point point = {x, y};
    return point;
}

Point read_point()
{
    int x = 0;
    int y = 0;
    scanf("%d %d", &x, &y);
    return create_point(x, y);
}

Point get_simetric(Point p)
{
    int x = get_x(p);
    int y = get_y(p);
    return create_point(-x, -y);
}

int get_x(Point p)
{
    return p.x;
}

int get_y(Point p)
{
    return p.y;
}

int get_quadrant(Point p)
{
    int x = get_x(p);
    int y = get_y(p);

    if (x == 0 || y == 0)
        return 0;
    if (x > 0)
    {
        if (y > 0)
            return 1;
        return 4;
    }
    if (y > 0)
        return 2;
    return 3;
}

float get_distance(Point pA, Point pB)
{
    int xA = get_x(pA);
    int xB = get_x(pB);
    int yA = get_y(pA);
    int yB = get_y(pB);
    return sqrt(pow(xA - xB, 2) + pow(yA - yB, 2));
}

Point set_x(Point p, int x)
{
    int y = get_y(p);
    return create_point(x, y);
}

Point set_y(Point p, int y)
{
    int x = get_x(p);
    return create_point(x, y);
}

Point translate_x(Point p, int dX)
{
    int x = get_x(p);
    int y = get_y(p);
    return create_point(x + dX, y);
}

Point translate_y(Point p, int dY)
{
    int x = get_x(p);
    int y = get_y(p);
    return create_point(x, y + dY);
}

void print_point(Point p)
{
    printf("(%d,%d)", p.x, p.y);
}