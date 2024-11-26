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

    int *vec = calloc(sizeof(int), 10);

    for (int i = 0; i < 10; i++)
        printf("%d ", *(vec + i));

    printf("\n");

    return 0;
}
