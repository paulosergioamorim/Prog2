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
    int len = strlen(string);

    printf("%s", string);
}
