#pragma once

#include "point.h"
#define DEFAULT_SIZE 100

typedef struct array_points *ArrayPoints;

ArrayPoints create_array();

void insert_point(ArrayPoints array, Point point);

void insert_random_points(ArrayPoints array, int count);

void print_points(ArrayPoints points);

void free_points(ArrayPoints points);