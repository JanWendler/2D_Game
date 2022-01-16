//
// Created by Jan on 16/01/2022.
//

#include "TextureManager.h"
#include "SurfaceManager.h"

SDL_Texture* TextureManager::LoadTexture(const std::string& fileName, SDL_Renderer* renderer)
{
	SurfaceManager surface = SurfaceManager(fileName);
	return SDL_CreateTextureFromSurface(renderer, surface.getData());
}
