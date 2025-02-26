#include "tadgen.h"
#include <stdio.h>

/*
tad_gen_01
Digite o tipo e numero de elementos:
Digite o vetor:
1 2 3 4
*/

int main() {
    int type = 0;
    int numElem = 0;
    tGeneric *generic = NULL;
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos:\n");
    scanf("%d %d", &type, &numElem);

    switch (type) {
        case 0:
            generic = CriaGenerico(FLOAT, numElem);
            break;
        case 1:
            generic = CriaGenerico(INT, numElem);
            break;
    }

    LeGenerico(generic);

    ImprimeGenerico(generic);

    return 0;
}
