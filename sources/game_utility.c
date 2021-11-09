#include"game_utility.h"

#include"raylib.h"

float GetRandomFloat(){
    return GetRandomValue(-10, 10) / 10.0f;
}

float LinearInterpolate(float t, float a, float b) {
    return t * (a + b) - a; 
}