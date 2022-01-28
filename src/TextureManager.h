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
	/// \param filePath
	/// \param renderer
	static SDL_Texture* LoadTexture(const std::string& filePath);
	static void Draw(SDL_Texture* texture, SDL_Rect srcrect, SDL_Rect destrect, SDL_RendererFlip flip);
};

#endif//INC_2D_GAME_SRC_TEXTUREMANAGER_H_
