#include <stdio.h>
#include "point.h"

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    scanf("%d", &n);

    tPonto previousPoint = create_point(0, 0);
    for (i = 0; i < n; i++) {
        tPonto currentPoint = read_point();
        if (i == 0)
            printf("-\n");
        else
            printf("%.2f\n", get_distance(previousPoint, currentPoint));
        previousPoint = currentPoint;
    }
}
