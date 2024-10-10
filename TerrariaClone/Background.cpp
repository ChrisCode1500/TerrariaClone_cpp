#include "Background.h"

Background::Background(const char* background_texture_path	)
{
	// load background texture
	background_texture = LoadTexture(background_texture_path);
	if (Background::background_texture.width == 0 || Background::background_texture.height == 0) {
		TraceLog(LOG_ERROR, "Failed to load background texture");
		return;
	}

	// set scale values
	scale_x = (float)GetScreenWidth() / background_texture.width;
	scale_y = (float)GetScreenHeight() / background_texture.height;

	// use the bigger of the two scales
	this->scale = (scale_x > scale_y) ? scale_x : scale_y;

	sourceRectangle = { 0.0f, 0.0f, (float)background_texture.width, (float)background_texture.height };
	destinationRectangle = { 0.0f, 0.0f, (float)GetScreenWidth(), (float)GetScreenHeight() };
}

Background::~Background() {
	// unload textures if they are loaded
	if (background_texture.id != 0) {
		UnloadTexture(background_texture);
	}
	if (midground_texture.id != 0) {
		UnloadTexture(midground_texture);
	}
	if (foreground_texture.id != 0) {
		UnloadTexture(foreground_texture);
	}
}

void Background::draw() {
	DrawTextureEx(Background::background_texture, { 0, 0 }, 0.0f, scale, WHITE);
}

// modify & implement later to allow for parallax & background scrolling
//Background::Background(const char* background_texture, const char* midground_texture, float scale_x, float scale_y)
//	: background_texture(LoadTexture(background_texture)),
//	midground_texture(LoadTexture(midground_texture)),
//	scale_x(scale_x),
//	scale_y(scale_y)
//{
//
//}
//Background::Background(const char* background_texture, const char* midground_texture, const char* foreground_texture, float scale_x, float scale_y)
//	: background_texture(LoadTexture(background_texture)),
//	midground_texture(LoadTexture(midground_texture)),
//	foreground_texture(LoadTexture(foreground_texture)),
//	scale_x(scale_x),
//	scale_y(scale_y)
//{
//
//}