#include "type_info.h"
#include <iostream>
#include <iomanip>

void printTypeSizes() {
    std::cout << std::left;
    std::cout<<std::setw(14) << "Data type"<< "Size"  << "\n";
    std::cout << std::setw(14) << "bool" << std::setw(2) << sizeof(bool) << "bytes *Holds 1 bit of data, but a byte is the smallest addressable unit\n";
    std::cout << std::setw(14) << "char" << std::setw(2) << sizeof(char) << "bytes *Always 1 byte by the standard\n";
    std::cout << std::setw(14) << "short int" << std::setw(2) << sizeof(short int) << "bytes *According to the standard, no less than 16 bits and no more than int\n";
    std::cout << std::setw(14) << "int"  << std::setw(2) << sizeof(int) << "bytes *Range of values for 4 bytes: from -2 147 483 648 to 2 147 483 647\n";
    std::cout << std::setw(14) << "long int" << std::setw(2) << sizeof(long int) << "bytes *8 bytes on macOS and Linux, 4 bytes on Windows (MSVC)\n";
    std::cout << std::setw(14) << "float" << std::setw(2) << sizeof(float) << "bytes *IEEE 754 binary32\n";
    std::cout << std::setw(14) << "double" << std::setw(2) << sizeof(double) << "bytes *IEEE 754 binary64\n";
    std::cout << std::setw(14) << "long double" << std::setw(2) << sizeof(long double) << "bytes *Size depends on the platform\n";

}