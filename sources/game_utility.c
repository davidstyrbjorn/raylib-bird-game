#include"game_utility.h"

#include"raylib.h"
#include"raymath.h"

float GetRandomFloat(){
    return GetRandomValue(-10, 10) / 10.0f;
}

float LinearInterpolate(float t, float a, float b) {
    return t * (a + b) - a; 
}

void DrawCoordinateAxis() {
    Vector2 origin = (Vector2){ 0.0f, 0.0f };
    float axisThickness = 8.0f;
    float axisScale = 500.0f;
    Color axisColor = RED;

    DrawLineEx(origin, Vector2Add(origin, (Vector2) { axisScale, 0.0f }), axisThickness, axisColor); // X-axis
    DrawLineEx(origin, Vector2Add(origin, (Vector2) { 0.0f, axisScale }), axisThickness, axisColor); // Y-axis
}
