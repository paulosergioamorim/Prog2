#include <stdio.h>

int fatorial(int n);

int main(int argc, char const *argv[])
{
    int n = 0;
    scanf("%d", &n);
    int result = fatorial(n);
    printf("%d\n", result);

    return 0;
}

int fatorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * fatorial(n - 1);
}
