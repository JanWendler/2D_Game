//
// Created by Jan on 16/01/2022.
//

#ifndef INC_2D_GAME_SRC_SURFACEMANAGER_H_
#define INC_2D_GAME_SRC_SURFACEMANAGER_H_

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

class SurfaceManager
{
public:
	explicit SurfaceManager(const std::string& path)
	{
		data = IMG_Load(path.c_str());
		if(data == nullptr)
		{
			std::cout << "IMG_Load Error: " << SDL_GetError() << std::endl;
		}
	}
	[[nodiscard]] SDL_Surface* getData() const {return data;}
	~SurfaceManager()
	{
		SDL_FreeSurface(data);
	};

private:
	SDL_Surface* data;
};

#endif//INC_2D_GAME_SRC_SURFACEMANAGER_H_
