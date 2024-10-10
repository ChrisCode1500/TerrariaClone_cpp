#include "GameWindow.h"
#include "PlayerController.h"
#include "CustomCamera.h"
#include "Background.h"


GameWindow::GameWindow(int fps) : fps{ fps } {
	InitWindow(screen_width, screen_height, "Terraria Clone");
	screen_width = GetScreenWidth();
	screen_height = GetScreenHeight();
}


void GameWindow::run_game() {
	SetTargetFPS(fps);
	PlayerController player(screen_width / 2.0f, screen_height / 2.0f, 50, 125, 5, "character.png");
	CustomCamera player_camera(		
		Vector2{ player.x_pos, player.y_pos },
		Vector2{ screen_width / 2.0f, screen_height / 2.0f },
		0.0f,
		1.0f
	);
	Background background("default_bg.png");

	while (!WindowShouldClose()) {
		BeginDrawing();
		player.update();
		player_camera.update(Vector2{ player.x_pos, player.y_pos });

		ClearBackground(SKYBLUE);
		BeginMode2D(player_camera.camera);

		// draw background
		background.draw();

		player.draw();

		EndMode2D();

		EndDrawing();
	}
}
