#pragma once
#include <stdexcept>

template <typename Type>
Type changeBit(Type a, int i, char operation) {
    unsigned long long mask = 1ULL << i;
    switch (operation) {
        case 's': // set
            a = static_cast<Type>(a | mask);
            break;
        case 'c': // clear
            a = static_cast<Type>(a & ~mask);
            break;
        case 't': // toggle
            a = static_cast<Type>(a ^ mask);
            break;
        default:
            throw std::invalid_argument("Error: unknown bit operation! Use 's', 'c' or 't'.");
    }
    return a;
}

float changeFloatBit(float f, int i, char operation);
double changeDoubleBit(double d, int i, char operation);