#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int x = 0;
    int *pX = &x;

    printf("x = %d\n", x);
    printf("pX = %p\n", pX);
    printf("*pX = %d\n", *pX);
    printf("&pX = %p\n", &pX);

    // int **vec = calloc(sizeof(int *), 10);

    // for (int i = 0; i < 10; i++)
    //     vec[i] = calloc(sizeof(int), 10);

    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //         printf("%d ", vec[i][j]);

    //     printf("\n");
    // }

    int vec[5] = {1, 2, 3, 4, 5};
    int *p = vec;

    printf("%d", *(p + 1));

    printf("\n");

    return 0;
}
