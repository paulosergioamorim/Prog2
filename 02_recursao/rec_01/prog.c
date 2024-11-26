#include <stdio.h>
#include <string.h>

void ImprimeInvertido(char *string);

int main()
{
    char string[1001] = "";
    scanf("%1000[^\n]", string);
    ImprimeInvertido(string);
    return 0;
}

void ImprimeInvertido(char *string)
{
    if (*string == '\0')
        return;

    ImprimeInvertido(string + 1);
    printf("%c", *string);
}
