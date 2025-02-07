#include "array_points.h"
#include <stdlib.h>
#include <assert.h>
#include <time.h>

struct array_points {
    Point *vec;
    int elCount;
    int memSize;
};

ArrayPoints create_array() {
    ArrayPoints array = malloc(sizeof(struct array_points));
    assert(array);

    array->elCount = 0;
    array->memSize = DEFAULT_SIZE;

    array->vec = malloc(array->memSize * sizeof(Point));
    assert(array->vec);

    return array;
}

void insert_point(ArrayPoints array, Point point) {
    if (array->elCount + 1 == array->memSize)
    {
        array->memSize *= 2;
        array->vec = realloc(array->vec, array->memSize * sizeof(Point));
    }

    array->vec[array->elCount] = point;
    array->elCount++;
}

void insert_random_points(ArrayPoints array, int count) {
    srand(time(NULL));

    for (int i = 0; i < count; i++)
    {
        THIS_TYPE x = (THIS_TYPE)rand() % 10;
        THIS_TYPE y = (THIS_TYPE)rand() % 10;

        Point point = create_point(x, y);
        insert_point(array, point);
    }
}

void print_points(ArrayPoints array) {
    for (int i = 0; i < array->elCount; i++)
        print_point(array->vec[i]);
}

void free_points(ArrayPoints array) {
    for (int i = 0; i < array->elCount; i++)
        free_point(array->vec[i]);
}