#include "CustomCamera.h"

CustomCamera::CustomCamera(Vector2 target, Vector2 offset, float rotation, float zoom) 
	: target(target),
	offset(offset),
	rotation(rotation),
	zoom(zoom)
{
	CustomCamera::camera.target = target;
	CustomCamera::camera.offset = offset;
	CustomCamera::camera.rotation = rotation;
	CustomCamera::camera.zoom = zoom;
}

void CustomCamera::update(Vector2 updated_target) {
	CustomCamera::camera.target = updated_target;

	// allows zooming in/out with the mouse wheel
	camera.zoom += (float)GetMouseWheelMove() * 0.07f;

	// min/max camera zoom
	if (camera.zoom > 3.0f) {
		camera.zoom = 3.0f;
	} else if (camera.zoom < 1.0f) {
		camera.zoom = 1.0f;
	}
}