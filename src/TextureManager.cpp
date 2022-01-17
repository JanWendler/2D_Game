//
// Created by Jan on 16/01/2022.
//

#include <iostream>
#include "TextureManager.h"
#include "SurfaceManager.h"
#include "GameWindow.h"

SDL_Texture* TextureManager::LoadTexture(const std::string& filePath)
{
	SurfaceManager surface = SurfaceManager(filePath);
	return SDL_CreateTextureFromSurface(GameWindow::getInstance()->getRenderer(), surface.getData());
}
void TextureManager::Draw(SDL_Texture* texture, SDL_Rect srcrect, SDL_Rect destrect)
{
	if(SDL_RenderCopy(GameWindow::getInstance()->getRenderer(), texture, &srcrect, &destrect)!= 0)
	{
		std::cout << "SDL_RenderCopy Error: " << SDL_GetError() << std::endl;
	}
}
