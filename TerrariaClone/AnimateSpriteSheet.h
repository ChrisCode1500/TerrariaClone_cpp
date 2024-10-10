#ifndef ANIMATE_SPRITE_SHEET_OCT_6_H
#define ANIMATE_SPRITE_SHEET_OCT_6_H

#include "raylib.h"

#define MAX_FRAME_SPEED	15
#define MIN_FRAME_SPEED	1
// I want this to replace the Players current sprite implementation
class AnimateSpriteSheet {
public:
	Texture2D sprite_sheet{};
	Rectangle frame_rectangle{};
	int current_frame{};
	int frame_counter{};
	int frames_speed{};
public:
	AnimateSpriteSheet(const char* sprite_sheet_location);
	void animate();
};

#endif // !ANIMATE_SPRITE_SHEET_OCT_6_H

