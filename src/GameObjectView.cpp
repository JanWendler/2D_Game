//
// Created by Jan on 16/01/2022.
//

#include <iostream>
#include "GameObjectView.h"
#include "TextureManager.h"

void GameObjectView::render()
{
	if(SDL_RenderClear(renderer)!=0)
	{
		std::cout << "SDL_RenderClear Error: " << SDL_GetError() << std::endl;
		return;
	}

	destrect.x = object.getCoordinates().getX();
	destrect.y = object.getCoordinates().getY();

	if(SDL_RenderCopy(renderer, texture, NULL, &destrect)!= 0)
	{
		std::cout << "SDL_RenderCopy Error: " << SDL_GetError() << std::endl;
	}
}
GameObjectView::GameObjectView(const std::string& texturePath, SDL_Renderer* renderer, const GameObject& object):
	renderer(renderer), object(object)
{
	texture = TextureManager::LoadTexture(texturePath, renderer);

	srcrect.h = 128;
	srcrect.w = 128;
	srcrect.x = 128;
	srcrect.y = 128;

	destrect.h = 128;
	destrect.w = 128;
	destrect.x = 128;
	destrect.y = 128;
}