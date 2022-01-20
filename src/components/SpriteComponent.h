//
// Created by Jan on 20/01/2022.
//

#ifndef INC_2D_GAME_SRC_COMPONENTS_SPRITECOMPONENT_H_
#define INC_2D_GAME_SRC_COMPONENTS_SPRITECOMPONENT_H_

#include "TransformComponent.h"
#include "../TextureManager.h"
#include <SDL.h>

class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcrect, destrect;

public:
	SpriteComponent() = default;
	explicit SpriteComponent(const std::string& path)
	{
		setTexture(path);
		if (texture == NULL)
		{
			std::cout << "LoadTexture Error: " << SDL_GetError() << std::endl;
		}
	}

	void setTexture(const std::string path)
	{
		texture = TextureManager::LoadTexture(path);
	}
	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();

		srcrect.x = 0;
		srcrect.y = 0;
		srcrect.w = 32;
		srcrect.h = 32;

		destrect.x = transform->position.x;
		destrect.y = transform->position.y;
		destrect.w = 32;
		destrect.h = 32;
	}
	void update() override
	{
		destrect.x = (int)transform->position.x;
		destrect.y = (int)transform->position.y;
	};

	void render() override
	{
		TextureManager::Draw(texture, srcrect, destrect);
	}
	~SpriteComponent() override = default;
};

#endif//INC_2D_GAME_SRC_COMPONENTS_SPRITECOMPONENT_H_
