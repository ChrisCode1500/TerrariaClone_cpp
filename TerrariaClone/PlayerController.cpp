#include "raylib.h"
#include <iostream>
#include "PlayerController.h"

PlayerController::PlayerController(float x_pos, float y_pos, float width, float height, int move_speed, const char* playerTextureLocation)
	: x_pos(x_pos),
	y_pos(y_pos),
	width(width),
	height(height),
	move_speed(move_speed),
	playerTexture(LoadTexture(playerTextureLocation))
{
	sourceRectangle = { 0.0f, 0.0f, (float)playerTexture.width, (float)playerTexture.height };

	// destination rectangle (where and how big to draw the texture)
	//destinationRectangle = { x_pos, y_pos, width, height }; // maybe make the width/height in the constructor optional
	destinationRectangle = { x_pos, y_pos, (float)playerTexture.width, (float)playerTexture.height};

	// origin point for rotation (set to top-left corner)
	origin = { width / 2.0f, height / 2.0f };
}

// later implementations will probably need to be updated for sprites? idk man. Current implementation for sprites may be bad? 
void PlayerController::draw() {
	// source rectangle (portion of the texture to use)
	destinationRectangle.x = x_pos;
	destinationRectangle.y = y_pos;

	DrawTexturePro(playerTexture, sourceRectangle, destinationRectangle, origin, 0.0f, WHITE);
}

void PlayerController::move() {
	if (IsKeyDown(KEY_W)) {
		y_pos -= move_speed;
	}
	if (IsKeyDown(KEY_S)) {
		y_pos += move_speed;
	}
	if (IsKeyDown(KEY_A)) {
		sourceRectangle.width = -playerTexture.width; // flip horizontally when moving left
		x_pos -= move_speed;
	}
	if (IsKeyDown(KEY_D)) {
		sourceRectangle.width = playerTexture.width; // flip horizontally when moving right
		x_pos += move_speed;
	}
}

PlayerController::~PlayerController() {
	// unload textures if they are loaded
	if (playerTexture.id != 0) {
		UnloadTexture(playerTexture);
	}
}

void PlayerController::update() {
	PlayerController::move();
}