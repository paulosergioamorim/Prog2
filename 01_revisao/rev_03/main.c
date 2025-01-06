#include <stdio.h>
#include <stdlib.h>

int count_item(int n, int vec[n], int item);

int main(int argc, char const *argv[])
{
    int n = 0;
    int hasFound = 0;

    fflush(stdin);
    scanf("%d ", &n);

    int idBooks[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &idBooks[i]);
        
    for (int i = 0; i < n; i++)
    {
        if (count_item(n, idBooks, idBooks[i]) != 1)
            continue;

        printf("%d ", idBooks[i]);
        hasFound = 1;
    }

    if (hasFound)
        return 0;

    printf("NENHUM");

    return 0;
}

int count_item(int n, int vec[n], int item)
{
    int count = 0;

    for (int i = 0; i < n; i++)
        if (vec[i] == item)
            count++;

    return count;
}
