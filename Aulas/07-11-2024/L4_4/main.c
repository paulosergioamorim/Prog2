#include <stdio.h>
#include "point.h"

int main(int argc, char const *argv[])
{
    int i = 0;
    scanf("%d", &i);
    for (i; i > 0; i--)
    {
        Point point = read_point();
        print_point(point);
        printf(" %d ", get_quadrant(point));
        Point simetricPoint = get_simetric(point);
        print_point(simetricPoint);
        printf(" %d\n", get_quadrant(simetricPoint));
    }

    return 0;
}
