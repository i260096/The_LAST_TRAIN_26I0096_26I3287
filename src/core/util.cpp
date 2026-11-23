#include "util.h"

int clampInt(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}
// Primitive helper utilities, clamping, and screen control
