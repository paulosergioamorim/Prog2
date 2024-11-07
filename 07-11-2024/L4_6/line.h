#ifndef _LINE_
#define _LINE_
#include "point.h"

typedef struct
{
    tPonto pi;
    tPonto pf;
} tReta;

tReta create_line(tPonto pi, tPonto pf);
tReta read_line();
void print_line(tReta r);
tPonto get_start_point(tReta r);
tPonto get_end_point(tReta r);
tReta move(tReta r, tPonto pi, tPonto pf);
float length_of_line(tReta r);

#endif