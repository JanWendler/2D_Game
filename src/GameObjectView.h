//
// Created by Jan on 16/01/2022.
//

#ifndef INC_2D_GAME_SRC_GAMEOBJECTVIEW_H_
#define INC_2D_GAME_SRC_GAMEOBJECTVIEW_H_

#include <SDL.h>
#include <string>
#include "GameObject.h"
class GameObjectView
{
public:
	GameObjectView(const std::string& texturePath, SDL_Renderer* renderer, const GameObject& object);
	void render();

private:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Rect srcrect, destrect;
	std::string texturePath;
	const GameObject& object;
};

#endif//INC_2D_GAME_SRC_GAMEOBJECTVIEW_H_
