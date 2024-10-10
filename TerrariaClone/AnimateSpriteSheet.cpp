#include "AnimateSpriteSheet.h"

AnimateSpriteSheet::AnimateSpriteSheet(const char* sprite_sheet_location)
	: sprite_sheet(LoadTexture(sprite_sheet_location))
{
	frame_rectangle = { 0.0f, 0.0f, (float)this->sprite_sheet.width / 6, (float)this->sprite_sheet.height };
	current_frame = 0;
	frame_counter = 0;
	frames_speed = 8;
}
void AnimateSpriteSheet::animate() {
	// animate sprite here
	if (frame_counter >= (60 / frames_speed)) {
		frame_counter = 0;
		current_frame++;

		if (current_frame > 5) {
			current_frame = 0;
		}


	}
}
