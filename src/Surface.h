//
// Created by Jan on 16/01/2022.
//

#ifndef INC_2D_GAME_SRC_SURFACE_H_
#define INC_2D_GAME_SRC_SURFACE_H_

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Surface
{
public:
	explicit Surface(const std::string& path)
	{
		data = IMG_Load(path.c_str());
	}
	[[nodiscard]] SDL_Surface* getData() const {return data;}
	~Surface()
	{
		SDL_FreeSurface(data);
	};

private:
	SDL_Surface* data;
};

#endif//INC_2D_GAME_SRC_SURFACE_H_
