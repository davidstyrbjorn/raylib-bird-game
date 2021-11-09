#ifndef BIRD
#define BIRD

#include"raylib.h"

typedef struct s_game s_game;
// Object for the bird that flies around the screen and shits all over the map

typedef enum BIRD_STATES {
    BIRD_FLYING, // Roam randomly around the map
    BIRD_ABOUT_TO_SHIT, // Target player
    BIRD_JUST_SHAT // Fly slowly/be stationary
} BIRD_STATES;

typedef struct s_bird {
    Vector2 position;
    Texture2D texture;
    Rectangle rect;
    BIRD_STATES state;
    Vector2 direction;
    float speed;
    float state_timer;
    float min_speed, max_speed;
} s_bird;

void UpdateBird(s_game* game, float delta_time);
void CheckBirdCollision(s_game* game);
void UpdateBirdState(s_game* game, BIRD_STATES new_state);

#endif BIRD