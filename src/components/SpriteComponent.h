//
// Created by Jan on 20/01/2022.
//

#ifndef INC_2D_GAME_SRC_COMPONENTS_SPRITECOMPONENT_H_
#define INC_2D_GAME_SRC_COMPONENTS_SPRITECOMPONENT_H_

#include "../TextureManager.h"
#include "TransformComponent.h"
#include "Animation.h"
#include <SDL.h>
#include <map>

class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcrect, destrect;

	bool animated = false;
	int animFrames = 0;
	int animSpeed = 100;
	int animIndex = 0;
	std::map <std::string, Animation> animations;
	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
public:
	enum FlipDir
	{
		None,
		Horizontal,
		Vertical
	};
	SpriteComponent() = default;
	explicit SpriteComponent(const std::string& path)
	{
		setTexture(path);
		if (texture == NULL)
		{
			std::cout << "LoadTexture Error: " << SDL_GetError() << std::endl;
		}
	}
	SpriteComponent(const std::string& path, bool isAnimated)
		: animated(isAnimated)
	{
		Animation idle = Animation(0,3,100);
		Animation walk = Animation(1,8,100);

		animations.emplace("Idle", idle);
		animations.emplace("Walk", walk);

		play("Idle");

		setTexture(path);
	}
	void setTexture(const std::string& path)
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
		if (animated)
		{
			srcrect.x = srcrect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}
		srcrect.y = animIndex * transform->height;
		destrect.x = static_cast<int>(transform->position.x);
		destrect.y = static_cast<int>(transform->position.y);
		destrect.w = transform->width * transform->scale;
		destrect.h = transform->height * transform->scale;
	};

	void render() override
	{
		TextureManager::Draw(texture, srcrect, destrect, spriteFlip);
	}
	void play(const std::string& animName)
	{
		animFrames = animations[animName].frames;
		animIndex = animations[animName].index;
		animSpeed = animations[animName].speed;
	}
	void flip(FlipDir flipDir)
	{
		switch (flipDir)
		{

		case None:
			spriteFlip = SDL_FLIP_NONE;
			break;
		case Horizontal:
			spriteFlip = SDL_FLIP_HORIZONTAL;
			break;
		case Vertical:
			spriteFlip = SDL_FLIP_VERTICAL;
			break;
		}
	}
	~SpriteComponent() override
	{
		SDL_DestroyTexture(texture);
	};
};

#endif//INC_2D_GAME_SRC_COMPONENTS_SPRITECOMPONENT_H_
