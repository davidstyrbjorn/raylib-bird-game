typedef struct s_game {
    const char* title;
} s_game;

/* FUNCTIONS FOR HANDLING CORE GAME */
void RunGame(s_game* game);
void Update(int key);
void Render();