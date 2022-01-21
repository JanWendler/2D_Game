//
// Created by Jan on 17/01/2022.
//

#include "Map.h"
#include "Game.h"
#include "fstream"

void Map::LoadMap(const std::string& path, int sizeX, int sizeY)
{
	char tile;
	std::fstream mapFile;
	mapFile.open(path);
	Game* game = Game::getInstance();

	for(int y = 0; y < sizeY; ++y)
	{
		for(int x = 0; x < sizeX; ++x)
		{
			mapFile.get(tile);
			game->addTile(strtol(&tile,NULL,0),x*32,y*32);
			mapFile.ignore();
		}
	}
	mapFile.close();
}
