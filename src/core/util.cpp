#include "util.h"
#include <iostream>
#include <cstdlib>
#include <cctype>

// Primitive helper utilities, clamping, and screen control

int clampInt(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}



bool stringEquals(const char* a, const char* b){
    if (a==nullptr || b==nullptr) {
        return a==b; // returns 1 if both equal else 0
    }
    while (*a && *b) {
        if (*a!=*b) {
            return false;
        }
        ++a;
        ++b;
    }
    return *a==*b; // both should be at end of the string
}



void clearScreen(){
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif  
}



void printHeader(const char* title){
    std::cout<<"====================\n";
    std::cout<<title << "\n";
    std::cout<<"====================\n";
}




bool isSpaceChar(char c) {
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}



void trimWhitespace(char* str){
    if (str==nullptr) return;

    //cut whitespaces at start and end
    char* start=str;
    while (isSpaceChar(*start)) {
        ++start;
    }

    char* end=start;
    while (*end!='\0') {
    ++end;
    }

    // terminate string after last character 
    while (end>start && isSpaceChar(*(end-1))) {
    --end;
    }
    *end='\0';
    // shift trimmed string to beginning
    char* read=start;
    char* write=str;
    while (read<end) {
        *write++=*read++;
    }
    *write='\0';
}
