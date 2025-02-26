#include "brasileirao.h"

int main(int argc, char const *argv[])
{
    BRA *bra = CriaCamp();
    RealizaCamp(bra);
    FinalizaCamp(bra);
    
    return 0;
}
