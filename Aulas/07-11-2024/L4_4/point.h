#ifndef _POINT_
#define _POINT_
typedef struct
{
    int x;
    int y;
} Point;

Point create_point(int x, int y);
Point read_point();
Point get_simetric(Point p);
int get_x(Point p);
int get_y(Point p);
int get_quadrant(Point p);
float get_distance(Point pA, Point pB);
Point set_x(Point p, int x);
Point set_y(Point p, int y);
Point translate_x(Point p, int dX);
Point translate_y(Point p, int dY);
void print_point(Point p);
#endif