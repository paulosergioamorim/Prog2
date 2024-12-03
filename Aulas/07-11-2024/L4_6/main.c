#include <stdio.h>
#include "point.h"
#include "line.h"

int main(int argc, char const *argv[])
{
    int i = 0;
    scanf("%d", &i);

    for (i; i > 0; i--)
    {
        tPonto point = read_point();
        tReta line = read_line();
        tPonto pi = get_start_point(line);
        tPonto pf = get_end_point(line);

        float distancePi = get_distance(pi, point);
        float distancePf = get_distance(pf, point);

        if (distancePi == distancePf)
            printf("EQUIDISTANTE\n");
        else if (distancePi < distancePf)
            printf("INICIO\n");
        else
            printf("FIM\n");
    }

    return 0;
}
