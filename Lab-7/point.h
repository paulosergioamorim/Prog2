#pragma once

#define THIS_TYPE int
#define THIS_FORMAT "%d"

typedef struct point *Point;

Point create_point(THIS_TYPE x, THIS_TYPE y);

void print_point(Point point);

void free_point(Point point);