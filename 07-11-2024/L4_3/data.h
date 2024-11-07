#ifndef _DATA_
#define _DATA_

typedef struct
{
    int dia;
    int mes;
    int ano;
} tData;

tData LeData();
int EhBisexto(tData data);
void ImprimeData(tData data);
#endif