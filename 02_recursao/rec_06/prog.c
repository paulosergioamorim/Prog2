#include <stdio.h>

int fibonacci(int n);

int main(int argc, char const *argv[])
{
    int n = 0;
    scanf("%d", &n);
    int result = fibonacci(n);
    printf("%d\n", result);

    return 0;
}

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}
