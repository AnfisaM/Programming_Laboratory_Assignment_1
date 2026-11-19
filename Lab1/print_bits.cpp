#include "print_bits.h"
#include <iostream>
#include <cstring>
#include <cstdint>

void printFloatBits(float f) {
    uint32_t bits;
    std::memcpy(&bits, &f, sizeof(f));
    std::cout << "[sign] " << ((bits >> 31) & 1) << ' ';
    std::cout << "[exp] ";
    for (int i = 30; i >= 23; --i) std::cout << ((bits >> i) & 1);

    std::cout << " [mant] ";
    for (int i = 22; i >= 0; --i) std::cout << ((bits >> i) & 1);

    std::cout << '\n';
}

void printDoubleBits(double d) {
    uint64_t bits;
    std::memcpy(&bits, &d, sizeof(d));
    std::cout << "[sign] " << ((bits >> 63) & 1) << ' ';
    std::cout << "[exp] ";
    for (int i = 62; i >= 52; --i) std::cout << ((bits >> i) & 1);

    std::cout << " [mant] ";
    for (int i = 51; i >= 0; --i) std::cout << ((bits >> i) & 1);

    std::cout << '\n';
}