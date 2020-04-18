#include "Utils.h"
#include <math.h>
#include <stdint.h>
#include "Position.h"

uint64_t s[2];
uint64_t newRand() {
    uint64_t s1 = s[0];
    uint64_t s0 = s[1];
    uint64_t result = s0 + s1;
    s[0] = s0;
    s1 ^= s1 << 23;
    s[1] = s1 ^ s0 ^ (s1 >> 18) ^ (s0 >> 5);
    return result;
}

void setRandSeed(int seed)
{
    s[0] = seed;
}

int randI(int x)
{
    return newRand() % x;
}

float randF(float x)
{
    return (newRand() % ((int)(x * 100))) / 100.0;
}

float distance(Position a, Position b)
{
    return((float)sqrt(pow(a.getXPos() - b.getXPos(), 2) + pow(a.getYpos() - b.getYpos(), 2)));
}

