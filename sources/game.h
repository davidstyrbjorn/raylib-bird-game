#ifndef GAME_H
#define GAME_H

#include"bird.h"
#include"car.h"

typedef struct s_game {
    const char* title;
    int screen_width;
    int screen_height;

    s_bird bird;
    s_car car;
    Camera2D camera;
} s_game;

/* FUNCTIONS FOR HANDLING CORE GAME */
void GameInit(s_game* game);
int GameRun(s_game* game);
void GameUpdate(s_game* game, float delta_time);
void GameRender(s_game* game);
void GameEnd();
void InputGame(s_game* game, float delta_time);

#endif 