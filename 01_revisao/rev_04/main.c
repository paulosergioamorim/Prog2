#include <stdio.h>
#include <math.h>

int to_octal(int decimalNumber);

int main(int argc, char const *argv[])
{
    int number = 0;

    fflush(stdin);
    scanf("%d\n", &number);

    printf("%d", to_octal(number));

    return 0;
}

int to_octal(int decimalNumber)
{
    int acc = 0;

    for (int i = 0; decimalNumber != 0; i++) 
    {
        acc += (decimalNumber % 8) * pow(10, i);
        decimalNumber /= 8;
    }

    return acc;
}
