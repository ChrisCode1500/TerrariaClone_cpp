#ifndef PLAYER_CONTROLLER_OCT_1_H
#define PLAYER_CONTROLLER_OCT_1_H

class PlayerController {
public:
	float x_pos{}, y_pos{};
	float width, height{};
	int move_speed{};

	Texture2D playerTexture{};
	Rectangle sourceRectangle{};
	Rectangle destinationRectangle{};
	Vector2 origin{};

	PlayerController(float x_pos, float y_pos, float width, float height, int move_speed, const char* playerTextureLocation);
	~PlayerController();

	void draw();
	void move();
	void jump(); // not yet implemented
	// figure out how to make an update function that can run anything inside, similar to other engines
	// this will avoid copy/pasting an update function for everything that needs updating
	void update();
};

#endif // !PLAYER_CONTROLLER_OCT_1_H

