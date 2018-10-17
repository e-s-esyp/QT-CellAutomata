#include "rnd.h"

Rnd::Rnd()
{
    a = 1;
}

void Rnd::setSeed(unsigned long long seed) {
    a = (((seed << 1) & MODULATOR) | 1L);
}

int Rnd::rnd(unsigned long long n){
    a *= MULTIPLIER; // *5^17
    a &= MODULATOR; // mod 2^40
    return int(DIVISOR * a * n);
}

double Rnd::rnd(){
    a *= MULTIPLIER; // *5^1
    a &= MODULATOR; // mod 2^40
    return DIVISOR * a;
}
