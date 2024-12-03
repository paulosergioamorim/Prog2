#include "date.h"

int main(int argc, char const *argv[])
{
    date dA = read_date();
    date dB = read_date();

    for (dA; is_before(dA, dB); dA = next_date(dA))
        print_date(dA);

    return 0;
}