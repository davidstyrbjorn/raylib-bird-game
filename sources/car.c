#include"car.h"
#include"game.h"

#include"raylib.h"
#include"raymath.h"

#include<math.h>
#include<stdio.h>

void UpdateCar(s_game* game, float delta_time){
    InputCar(game, delta_time);

    printf("A: %.4f\n", game->car.rotation);

    s_car* car = &game->car;
    // Affect position with thrust
    float radians = DEG2RAD * (car->rotation+90);
    car->position.x += cos(radians) * car->current_thrust * delta_time;
    car->position.y += sin(radians) * car->current_thrust * delta_time;

    // Affect the rotation with current_angular
    car->rotation += car->current_angular * delta_time * 60.0f;
}

void InputCar(s_game* game, float delta_time){
    s_car* car = &game->car;

    // Input for thrust
    int direction = 0;

    if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)){
        direction = -1;
    }
    if(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)){
        direction = 1;
    }

    // Euler integration
    float friction = car->friction * car->current_thrust;
    if(car->current_thrust > 0) friction *= -1;
    float a = (car->current_thrust * friction) / car->mass; // F/m
    a += direction * car->engine_power;
    car->current_thrust = car->current_thrust + delta_time * a;

    car->current_thrust = Clamp(car->current_thrust, -car->max_thrust, car->max_thrust);
    
    // Rotation
    if(IsKeyDown(KEY_D)){
        car->current_angular = 1;
    }else if(IsKeyDown(KEY_A)){
        car->current_angular = -1;
    }else{
        car->current_angular = 0;
    }
}