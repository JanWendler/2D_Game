//
// Created by Jan on 20/01/2022.
//

#ifndef INC_2D_GAME_SRC_COMPONENTS_SPRITECOMPONENT_H_
#define INC_2D_GAME_SRC_COMPONENTS_SPRITECOMPONENT_H_

#include "../TextureManager.h"
#include "TransformComponent.h"
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
		if (!entity->hasComponent<TransformComponent>())
		{
			entity->addComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();

		srcrect.x = 0;
		srcrect.y = 0;
		srcrect.w = transform->width;
		srcrect.h = transform->height;

		destrect.x = static_cast<int>(transform->position.x);
		destrect.y = static_cast<int>(transform->position.y);
		destrect.w = transform->width * transform->scale;
		destrect.h = transform->height * transform->scale;
	}
	void update() override
	{
		destrect.x = static_cast<int>(transform->position.x);
		destrect.y = static_cast<int>(transform->position.y);
		destrect.w = transform->width * transform->scale;
		destrect.h = transform->height * transform->scale;
	};

	void render() override
	{
		TextureManager::Draw(texture, srcrect, destrect);
	}
	~SpriteComponent() override
	{
		SDL_DestroyTexture(texture);
	};
};

#endif//INC_2D_GAME_SRC_COMPONENTS_SPRITECOMPONENT_H_
