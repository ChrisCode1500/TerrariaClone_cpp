#ifndef CAMERA_OCT_2_H
#define CAMERA_OCT_2_H

#include "raylib.h"

class CustomCamera {
public:	
	Camera2D camera{};
	Vector2 target{};
	Vector2 offset{};
	float rotation{};
	float zoom{};

	CustomCamera(Vector2 target, Vector2 offset, float rotation, float zoom);

	void update(Vector2 updated_target);
};

#endif // !CAMERA_OCT_2_H

