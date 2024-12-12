#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *vec = calloc(10, sizeof(int));

    for (int i = 0; i < 10; i++)
        *(vec+i) = i;

    for (int i = 0; i < 10; i++)
        printf("%d", *(vec+1));    

    return 0;
}
