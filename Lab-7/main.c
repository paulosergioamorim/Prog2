#include "array_points.h"
#include <stdio.h>

#undef THIS_TYPE
#undef THIS_FORMAT

#define THIS_TYPE float
#define THIS_FORMAT "%.2f"

int main(int argc, char const *argv[])
{
    ArrayPoints points = create_array();
    int count = 0;
    sscanf(argv[1], "%d", &count);
    insert_random_points(points, count);
    print_points(points);
    free_points(points);
    return 0;
}
