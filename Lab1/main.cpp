#include <iostream>
#include <limits>
#include "type_info.h"
#include "print_bits.h"
#include "bit_ops.h"
#include "task.h"

int main() {
    std::cout << "\n=== 1. Type sizes ===\n";
    printTypeSizes();

    std::cout << "\n=== 2. Bits of integers ===\n";
    std::cout << "\n  Integer 5\n    ";
    printIntBits(5);
    std::cout << "\n  Integer -5\n    ";
    printIntBits(-5);
    std::cout << "\n  Integer 0\n    ";
    printIntBits(0);
    std::cout << "\n  Unsigned integer 5\n    ";
    printIntBits(5u);
    std::cout << "\n  Short -5 (16 bits)\n    ";
    printIntBits(short(-5));

    std::cout << "\n=== 3. Bits of float and double ===\n";
    std::cout << "\n  Float 3.14\n    ";
    printFloatBits(3.14f);
    std::cout << "\n  Double 3.14\n    ";
    printDoubleBits(3.14);
    std::cout << "\n  Float -2.5\n    ";
    printFloatBits(-2.5f);
    std::cout << "\n  Double -2.5\n    ";
    printDoubleBits(-2.5);
    std::cout << "\n  Float 0.0\n    ";
    printFloatBits(0.0f);
    std::cout << "\n  Double 0.0\n    ";
    printDoubleBits(0.0);
    std::cout << "\n  Float +inf (exponent all ones, mantissa 0)\n    ";
    printFloatBits(std::numeric_limits<float>::infinity());
    std::cout << "\n  Double +inf (exponent all ones, mantissa 0)\n    ";
    printDoubleBits(std::numeric_limits<double>::infinity());
    std::cout << "\n  Float denorm_min (exponent 0, mantissa not 0)\n    ";
    printFloatBits(std::numeric_limits<float>::denorm_min());
    std::cout << "\n  Double denorm_min (exponent 0, mantissa not 0)\n    ";
    printDoubleBits(std::numeric_limits<double>::denorm_min());

    std::cout << "\n=== 4. Changing bits ===\n";

    std::cout << "\n  -- Integers --\n";
    std::cout << "\n  5 with bit 3 set\n    ";
    printIntBits(changeBit(5, 3, 's'));
    std::cout << "\n  5 with bit 2 cleared\n    ";
    printIntBits(changeBit(5, 2, 'c'));
    std::cout << "\n  5 with bit 0 toggled\n    ";
    printIntBits(changeBit(5, 0, 't'));

    float f;
    double d;

    std::cout << "\n  -- Float --\n";
    f = changeFloatBit(1.0f, 31, 't');
    std::cout << "\n  1.0 with sign bit (31) toggled = " << f << "\n    ";
    printFloatBits(f);
    f = changeFloatBit(1.0f, 30, 't');
    std::cout << "\n  1.0 with top exponent bit (30) toggled = " << f << "\n    ";
    printFloatBits(f);
    f = changeFloatBit(1.0f, 22, 't');
    std::cout << "\n  1.0 with top mantissa bit (22) toggled = " << f << "\n    ";
    printFloatBits(f);
    f = changeFloatBit(0.0f, 22, 's');
    std::cout << "\n  0.0 with bit 22 set = " << f << "\n    ";
    printFloatBits(f);
    f = changeFloatBit(-1.0f, 31, 'c');
    std::cout << "\n  -1.0 with sign bit (31) cleared = " << f << "\n    ";
    printFloatBits(f);

    std::cout << "\n  -- Double --\n";
    d = changeDoubleBit(1.0, 63, 't');
    std::cout << "\n  1.0 with sign bit (63) toggled = " << d << "\n    ";
    printDoubleBits(d);
    d = changeDoubleBit(1.0, 62, 't');
    std::cout << "\n  1.0 with top exponent bit (62) toggled = " << d << "\n    ";
    printDoubleBits(d);
    d = changeDoubleBit(1.0, 51, 't');
    std::cout << "\n  1.0 with top mantissa bit (51) toggled = " << d << "\n    ";
    printDoubleBits(d);

    std::cout << "\n=== 5. Individual task: division by 2 ===\n";
    std::cout << "\n  x\tShift\tCorrected\tx / 2\n";
    const int tests[] = {6, 7, -6, -7, -8, 0};
    for (int x : tests) {
        std::cout << "  " << x << '\t' << divideBy2Shift(x) << '\t'
                  << divideBy2Corrected(x) << "\t\t" << x / 2 << '\n';
    }
    std::cout << '\n';
    return 0;
}