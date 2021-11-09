#include"bird.h"
#include"game.h"
#include"game_utility.h"

#include"raymath.h"

void UpdateBird(s_game* game, float delta_time)
{
	s_bird* bird = &game->bird;

	// Check collision
	CheckBirdCollision(game);

	// Update state timer
	bird->state_timer += 1.0f * delta_time;
	//printf("BIRD STATE TIMER: %.3f\n", bird->state_timer);

	switch (game->bird.state) {
	case BIRD_FLYING:
		// Move bird in direction according to speed and delta time
		bird->position = Vector2Add(
			bird->position, 
			Vector2Scale(bird->direction, delta_time * bird->speed)
		);
		
		// Update state after a certain amount of time
		if (bird->state_timer >= 8.0f) {
			UpdateBirdState(game, BIRD_ABOUT_TO_SHIT);
		}

		break;
	case BIRD_ABOUT_TO_SHIT:
		//printf("THE BIRD IS NOW TAKING A CRAP!\n");
		UpdateBirdState(game, BIRD_FLYING);
		break;
	case BIRD_JUST_SHAT:
		break;
	}
}

void CheckBirdCollision(s_game* game)
{
	s_bird* bird = &game->bird;
	int sw = game->screen_width; int sh = game->screen_height;

	printf("X: %.1f\n", bird->position.x);
	// X
	if (bird->position.x < 0 
		|| bird->position.x > sw - bird->rect.width) {
		printf("FLIP X");
		bird->direction.x *= -1;
	}
	// Y
	if (bird->position.y < 0
		|| bird->position.y > sh - bird->rect.height) {
		bird->direction.y *= -1;
	}
}

void UpdateBirdState(s_game* game, BIRD_STATES new_state) {
	s_bird* bird = &game->bird;
	
	float random_angle = { 0 };

	// Depending on new state we want to set some values
	switch(new_state) {
	case BIRD_FLYING:
		// Randomize direction vector
		random_angle = GetRandomFloat() * PI;
		bird->direction.x = cos(random_angle);
		bird->direction.y = sin(random_angle);
		
		// Randomize speed
		float t = (GetRandomFloat() + 1) / 2.0f;
		t = 1.5f;
		bird->speed = LinearInterpolate(t, bird->min_speed, bird->max_speed);

		break;
	}

	// Reset the timer
	bird->state_timer = 0.0f;

	// Assign the actual state 
	bird->state = new_state;
}