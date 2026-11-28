#include "switches.h"
#include "util.h"

// Door lock mechanics, lifts, and cabinet verification without structures

bool verifyCabinetCode(const char* enteredCode,
                       const bool objectives[NUM_OBJECTIVES]) {
    if (!objectives[OBJ_CLUE_4] || !objectives[OBJ_CLUE_2] || !objectives[OBJ_CLUE_7]) {
        return false;
    }

    return stringEquals(enteredCode, "427");
}