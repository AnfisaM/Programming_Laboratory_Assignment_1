#include "task.h"

int divideBy2Shift(int x) {
    return x >> 1;
}

int divideBy2Corrected(int x) {
    // negative and odd: the shift rounds down, so add 1 to round toward zero
    if (((x >> 31) & 1) == 1 && (x & 1)) {
        return (x >> 1) + 1;
    }
    return x >> 1;
}