#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    float x1 = 0;
    float x2 = 0;
    float y1 = 0;
    float y2 = 0;
    float r1 = 0;
    float r2 = 0;
    float centersDistante = 0;

    fflush(stdin);
    scanf("%f %f %f\n", &x1, &y1, &r1);
    scanf("%f %f %f\n", &x2, &y2, &r2);

    centersDistante = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    if (centersDistante <= r1 + r2)
        printf("ACERTOU");
    else
        printf("ERROU");

    return 0;
}
