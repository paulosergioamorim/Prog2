#include "eleitor.h"
#include <stdio.h>

tEleitor CriaEleitor(int id, int votoP, int votoG)
{
    tEleitor eleitor = {id, votoP, votoG};

    return eleitor;
}

tEleitor LeEleitor()
{
    int id = 0;
    int votoP = 0;
    int votoG = 0;

    scanf("%d %d %d", &id, &votoP, &votoG);

    return CriaEleitor(id, votoP, votoG);
}

int ObtemVotoPresidente(tEleitor eleitor)
{
    return eleitor.votoP;
}

int ObtemVotoGovernador(tEleitor eleitor)
{
    return eleitor.votoG;
}

int EhMesmoEleitor(tEleitor eleitor1, tEleitor eleitor2)
{
    return eleitor1.id == eleitor2.id;
}
