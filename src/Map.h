//
// Created by Jan on 17/01/2022.
//

#ifndef INC_2D_GAME_SRC_MAP_H_
#define INC_2D_GAME_SRC_MAP_H_

#include <SDL.h>
class Map
{
public:
	Map();

	void LoadMap(int arr[20][25]);
	void render();
	~Map();

private:

	SDL_Rect srcrect, destrect;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];
};

#endif//INC_2D_GAME_SRC_MAP_H_
