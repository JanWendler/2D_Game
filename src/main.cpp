
#include <SDL2/SDL.h>
#include "Game.h"

int main(int argc, char* argv[])
{
	Game* game = Game::getInstance("Main Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 820, 640, false);
	game->run();
	return 0;
}

