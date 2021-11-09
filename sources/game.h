#ifndef GAME
#define GAME

#include"bird.h"

typedef struct s_game {
    const char* title;
    int screen_width;
    int screen_height;

    s_bird bird;
    Camera2D camera;
} s_game;

/* FUNCTIONS FOR HANDLING CORE GAME */
void GameInit(s_game* game);
int GameRun(s_game* game);
void GameUpdate(s_game* game, float delta_time);
void GameRender(s_game* game);
void GameEnd();

#endif GAME