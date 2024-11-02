#include <stdio.h>
#include <string.h>

int palindromo(char *string, int tamanho);

int main()
{
    char string[100] = "";

    while (scanf("%s", string))
    {   
        if (palindromo(string, strlen(string)))
            printf("SIM\n");
        else
            printf("NAO\n");
    }
    
    return 0;
}

int palindromo(char *string, int tamanho)
{
    if (tamanho <= 1)
        return 1;
    char firstChar = *string;
    char lastChar = *(string + tamanho - 1);
    return firstChar == lastChar && palindromo(string + 1, tamanho - 2);
}
