#include <iostream>
#include "GameWindow.h"

/*
    Terraria Clone
    Made with Raylib & C++

    --- Author ---
    Christopher Gaudet
*/

int main()
{
    int fps{ 60 };
    GameWindow game(fps);
    game.run_game();
}