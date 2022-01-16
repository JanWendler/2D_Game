//
// Created by Jan on 16/01/2022.
//

#ifndef INC_2D_GAME_SRC_TEXTUREMANAGER_H_
#define INC_2D_GAME_SRC_TEXTUREMANAGER_H_

#include <SDL.h>
#include <string>
class TextureManager
{
public:
	/// \brief Loads the textures of a picture in to the texture parameter via the renderer
	/// \param texture
	/// \param fileName
	/// \param renderer
	static SDL_Texture* LoadTexture(const std::string& fileName, SDL_Renderer* renderer);
};

#endif//INC_2D_GAME_SRC_TEXTUREMANAGER_H_
