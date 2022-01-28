//
// Created by Jan on 16/01/2022.
//

#include <iostream>
#include "TextureManager.h"
#include "SurfaceManager.h"
#include "GameWindow.h"

SDL_Texture* TextureManager::LoadTexture(const std::string& filePath)
{
	SDL_Texture* tex = nullptr;
	SurfaceManager surface = SurfaceManager(filePath);
	tex = SDL_CreateTextureFromSurface(GameWindow::getInstance()->getRenderer(), surface.getData());
	if(tex == nullptr)
	{
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return tex;
	}
	return tex ;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect srcrect, SDL_Rect destrect, SDL_RendererFlip flip)
{
	if(SDL_RenderCopyEx(GameWindow::getInstance()->getRenderer(), texture, &srcrect, &destrect, NULL, NULL, flip)!= 0)
	{
		std::cout << "SDL_RenderCopy Error: " << SDL_GetError() << std::endl;
	}
}
