//
// Created by Jan on 20/01/2022.
//

#ifndef INC_2D_GAME_SRC_COMPONENTS_KEYBOARDCONTROLLER_H_
#define INC_2D_GAME_SRC_COMPONENTS_KEYBOARDCONTROLLER_H_

#include "../EntityComponentSystem.h"
#include "TransformComponent.h"
#include "../Game.h"
class KeyboardController : public Component
{
public:
	TransformComponent* transform;
	SpriteComponent* sprite;
	SDL_Event* event;
	void init() override
	{
		if(!entity->hasComponent<TransformComponent>())
		{
			entity->addComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();
		if(Game::getInstance() == nullptr)
		{
			std::cout << "this is fucked!" << std::endl;
		}
		else
		{
			if(Game::getInstance()->getEvent() == nullptr)
			{
				std::cout << "this is still fucked!" << std::endl;
			}
			else
			{
				event = Game::getInstance()->getEvent();
			}
		}
		sprite = &entity->getComponent<SpriteComponent>();
	}

	void update() override
	{

		if(event->type == SDL_KEYDOWN)
		{
			switch(event->key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = -1;
				sprite->play("Walk");
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				sprite->play("Walk");
				sprite->flip(SpriteComponent::Horizontal);
				break;
			case SDLK_s:
				transform->velocity.y = 1;
				sprite->play("Walk");
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				sprite->play("Walk");
				break;
			default:
				break;
			}
		}

		if(event->type == SDL_KEYUP)
		{
			switch(event->key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = 0;
				sprite->play("Idle");
				break;
			case SDLK_a:
				transform->velocity.x = 0;
				sprite->play("Idle");
				sprite->flip(SpriteComponent::None);
				break;
			case SDLK_s:
				transform->velocity.y = 0;
				sprite->play("Idle");
				break;
			case SDLK_d:
				transform->velocity.x = 0;
				sprite->play("Idle");
				break;
			default:
				break;
			}
		}
	}
};
#endif//INC_2D_GAME_SRC_COMPONENTS_KEYBOARDCONTROLLER_H_
