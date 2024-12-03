#include <stdio.h>
#include "data.h"

int main(int argc, char const *argv[])
{
    int i = 0;
    scanf("%d", &i);

    for (i; i > 0; i--)
    {
        tData data = LeData();
        ImprimeData(data);
        printf(":");
        printf(EhBisexto(data) ? "Bisexto\n" : "Normal\n");
    }
}
