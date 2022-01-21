//
// Created by Jan on 17/01/2022.
//

#ifndef INC_2D_GAME_SRC_MAP_H_
#define INC_2D_GAME_SRC_MAP_H_

#include <SDL.h>
#include <string>
class Map
{
public:
	static void LoadMap(const std::string& path, int sizeX, int sizeY);
};

#endif//INC_2D_GAME_SRC_MAP_H_
