#ifndef CAR_H
#define CAR_H

#include"raylib.h"

typedef struct s_game s_game;

typedef struct s_car {
    Vector2 position; // Varies
    float rotation; // Varies
    Texture2D texture;
    Rectangle rect;
    float scale;

    // Physics members
    float mass;
    float max_angular; // Const
    float current_angular; // Varies
    float max_thrust; // Const
    float current_thrust; // Varies
    float engine_power;
    float friction;
} s_car;

void UpdateCar(s_game* game, float delta_time);
void InputCar(s_game* game, float delta_time);

#endif