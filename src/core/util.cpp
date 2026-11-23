#include "util.h"

int clampInt(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

bool stringEquals(const char* a, const char* b){
    if (a == nullptr || b == nullptr) {
        return a == b; // returns 1 if both equal else 0
    }
    while (*a && *b) {
        if (*a != *b) {
            return false;
        }
        ++a;
        ++b;
    }
    return *a == *b; // Both should be at the end of the string
}
// Primitive helper utilities, clamping, and screen control
