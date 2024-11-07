#include <stdio.h>
#include "point.h"
#include "line.h"

tReta create_line(tPonto pi, tPonto pf)
{
    tReta line = {pi, pf};
    return line;
}

tReta read_line()
{
    tPonto pi = read_point();
    tPonto pf = read_point();
    return create_line(pi, pf);
}

void print_line(tReta r)
{
    tPonto pi = get_start_point(r);
    tPonto pf = get_end_point(r);
    printf("[(%d,%d):(%d,%d)]", pi.x, pi.y, pf.x, pf.y);
}

tPonto get_start_point(tReta r)
{
    return r.pi;
}

tPonto get_end_point(tReta r)
{
    return r.pf;
}

tReta move(tReta r, tPonto pi, tPonto pf)
{
    r.pi = pi;
    r.pf = pf;
    return r;
}

float length_of_line(tReta r)
{
    tPonto pi = get_start_point(r);
    tPonto pf = get_end_point(r);
    return get_distance(pi, pf);
}