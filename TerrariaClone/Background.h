#ifndef BACKGROUND_OCT_4_H
#define BACKGROUND_OCT_4_H

#include "raylib.h"

class Background {
public:
	Texture2D background_texture{};
	Texture2D midground_texture{};
	Texture2D foreground_texture{};

	Rectangle sourceRectangle = {};
	Rectangle destinationRectangle = {};

	float scrollingBackground{ 0.0f };
	float scrollingMidground{ 0.0f };
	float scrollingForeground{ 0.0f };

	float scale_x{};
	float scale_y{};

private:	
	float scale{};

public: // constructors
	/// <summary>
	/// Add a background texture
	/// </summary>
	/// <param name="background_texture">Background texture location</param>
	/// <param name="scale_x">How much to scale in the x</param>
	/// <param name="scale_y">How much to scale in the y</param>
	Background(const char* background_texture_path);
	void draw();
	~Background();
	/// <summary>
	/// Add a background and midground texture
	/// </summary>
	/// <param name="background_texture">Background texture location</param>
	/// <param name="midground_texture">Midground texture location</param>
	/// <param name="scale_x">How much to scale in the x</param>
	/// <param name="scale_y">How much to scale in the y</param>
	//Background(const char* background_texture, const char* midground_texture, float scale_x, float scale_y);
	/// <summary>
	/// Add a background, midground, and foreground texture
	/// </summary>
	/// <param name="background_texture">Background texture location</param>
	/// <param name="midground_texture">Midground texture location</param>
	/// <param name="foreground_texture">Foreground texture location</param>
	/// <param name="scale_x">How much to scale in the x</param>
	/// <param name="scale_y">How much to scale in the y</param>
	//Background(const char* background_texture, const char* midground_texture, const char* foreground_texture, float scale_x, float scale_y);
};

#endif // !BACKGROUND_OCT_4_H

