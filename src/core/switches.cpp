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



bool canUseLift1(int fromFloor, int toFloor){
    if ((fromFloor==1 && toFloor==2) || (fromFloor==2 && toFloor==1))
        return true;
    else 
        return false;
}



bool canUseLift2(int fromFloor, int toFloor, bool lift2Operational, int emergencyTripsLeft){
    if ((fromFloor==2 || fromFloor==4 || fromFloor==5) && (toFloor==2 || toFloor==4 || toFloor==5) && (fromFloor != toFloor)){
        if (lift2Operational){
            return true;
        }
        else if (emergencyTripsLeft>0){
            return true;
        }
        return false;
    }
}