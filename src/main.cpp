#define SDL_MAIN_HANDLED
#include "Game.h"
#include <SDL.h>
#include <iostream>

bool hasSubstring(const std::string& mainString, const std::string& subString);

int main(int argc, char* argv[])
{
	Game* game = Game::getInstance("Main Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	game->run();
	return 0;
}
