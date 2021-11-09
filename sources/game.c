#include"game.h"

/* RAYLIB INCLUDES*/
#include"raylib.h"
#include"raymath.h"

#include <stdio.h>

void GameInit(s_game* game) {
    // Creates Raylib window for us to render our game in!
    InitWindow(game->screen_width, game->screen_height, game->title);

    game->camera.offset = (Vector2){ game->screen_width / 2.0f, game->screen_height / 2.0f };
    game->camera.rotation = 0.0f;
    game->camera.zoom = 1.0f;

    // Setup bird
    const float scale = 0.25f;
    game->bird.texture = LoadTexture(ASSETS_PATH"bird.png");
    // Set filter for scaling
    SetTextureFilter(game->bird.texture, TEXTURE_FILTER_BILINEAR);

    // Setup bird
    game->bird.texture.width *= scale; game->bird.texture.height *= scale; // Scale the texture
    game->bird.position = (Vector2){ 0.0f, 0.0f };
    game->bird.rect = (Rectangle){ 0, 0, game->bird.texture.width, game->bird.texture.height };
    game->bird.min_speed = 40.0f;
    game->bird.max_speed = 80.0f;
    UpdateBirdState(game, BIRD_FLYING);

    // Raylib function to limit FPS
    SetTargetFPS(60);
}

int GameRun(s_game* game){
    printf("Run game!");

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update stuff
        float delta_time = GetFrameTime();
        GameUpdate(game, delta_time);

        // Draw stuff
        BeginDrawing();
        ClearBackground(SKYBLUE);
        BeginMode2D(game->camera); // Begin 2D mode with custom camera
 
        // DrawRectangleRec(playerRect, BLUE);
        GameRender(game);

        EndMode2D();
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();  // Close window and OpenGL context
    GameEnd(); // De-Init all the memory we have allocated ourselves
    UnloadTexture(game->bird.texture);

    return 0;
}

void GameUpdate(s_game* game, float delta_time)
{
    UpdateBird(game, delta_time);
}

void GameRender(s_game* game)
{
    // Render our game stuff
    DrawTextureRec(game->bird.texture, game->bird.rect, game->bird.position, WHITE); // Draw bird
    //DrawRectangleRec(game->bird.rect, RED);

    //Vector2 middle = { game->screen_width / 2, game->screen_height / 2 };
    //DrawLineEx(middle, Vector2Add(middle, Vector2Scale(game->bird.direction,10.0f)), 4.0f, RED);

}

void GameEnd()
{

}
