#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int acc = 1;

    fflush(stdin);
    scanf("%d\n", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++, acc++)
            printf("%d ", acc);

        printf("\n");
    }

    return 0;
}
