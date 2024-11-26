#include <stdio.h>

int somaDigitos(int n);

int main(int argc, char const *argv[])
{
    int n = 0;
    scanf("%d", &n);
    int sum = somaDigitos(n);
    printf("%d\n", sum);

    return 0;
}

int somaDigitos(int n)
{
    int unity = n % 10;

    if (unity == 0)
        return 0;

    return unity + somaDigitos(n / 10);
}
