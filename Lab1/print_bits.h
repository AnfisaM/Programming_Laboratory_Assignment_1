#pragma once
#include <iostream>   
#include <type_traits>

template <typename Type>
void printIntBits(Type a) {
    int size = sizeof(a) * 8;
    if (std::is_signed<Type>::value) {
        std::cout << "[sign] ";
    } else {
        std::cout << "[unsigned] ";
    }
    
    for (int i = size - 1; i >= 0; --i) {
        std::cout << ((a & (1ULL << i)) != 0);
        if (i % 8 == 0 && i > 0) std::cout << ' ';
    }
    std::cout << '\n';
}

void printFloatBits(float f);
void printDoubleBits(double d);