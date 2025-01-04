#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int n = 0;

    fflush(stdin);
    scanf("%d\n", &n);

    int idBooks[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &idBooks[i]);

    bool hasOneWithoutCopy = false;
    for (int i = 0; i < n; i++)
    {
        bool hasCopy = false;

        for (int j = 0; j < n; j++)
        {
            if (i != j && idBooks[i] == idBooks[j])
            {
                hasCopy = true;
                break;
            }
        }

        if (hasCopy)
            continue;

        printf("%d ", idBooks[i]);
        hasOneWithoutCopy = true;
    }

    if (!hasOneWithoutCopy)
        printf("NENHUM");

    return 0;
}
