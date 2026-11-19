#include "bit_ops.h"
#include <cstring>
#include <cstdint>

float changeFloatBit(float f, int i, char operation) {
    uint32_t bits;
    std::memcpy(&bits, &f, sizeof(f));      // float > integer
    bits = changeBit(bits, i, operation);   // change the bit in the integer
    std::memcpy(&f, &bits, sizeof(f));      // integer > float
    return f;
}

double changeDoubleBit(double d, int i, char operation) {
    uint64_t bits;
    std::memcpy(&bits, &d, sizeof(d));
    bits = changeBit(bits, i, operation);
    std::memcpy(&d, &bits, sizeof(d));
    return d;
}