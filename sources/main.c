/*******************************************************************************************
*
*   raylib [core] example - 2d camera platformer
*
*   This example has been created using raylib 2.5 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Example contributed by arvyy (@arvyy) and reviewed by Ramon Santamaria (@raysan5)
*
*   Copyright (c) 2019 arvyy (@arvyy)
*
********************************************************************************************/

#include "raylib.h"
#include "raymath.h"

#include"game.h"

int main(void)
{
    s_game game = {0};

    // Init game config
    game.screen_width = 800;
    game.screen_height = 600;
    game.title = "What the bird doing?";

    GameInit(&game);
    return GameRun(&game);

}