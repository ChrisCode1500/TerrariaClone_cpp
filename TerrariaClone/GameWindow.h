#ifndef GAME_WINDOW_OCT_1_H
#define GAME_WINDOW_OCT_1_H

#include "raylib.h"

class GameWindow {
public:
	int fps{};
	int screen_width{};
	int screen_height{};

	GameWindow(int fps);

	void run_game();
};
#endif // !GAME_WINDOW_OCT_1_H

