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
	TransformComponent *transform;
	const SDL_Event* event;
	void init() override
	{
		if(!entity->hasComponent<TransformComponent>())
		{
			entity->addComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();
		event = &Game::event;
	}

	void update() override
	{

		if(event->type == SDL_KEYDOWN)
		{
			switch(event->key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = -1;
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				break;
			case SDLK_s:
				transform->velocity.y = 1;
				break;
			case SDLK_d:
				transform->velocity.x = 1;
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
				break;
			case SDLK_a:
				transform->velocity.x = 0;
				break;
			case SDLK_s:
				transform->velocity.y = 0;
				break;
			case SDLK_d:
				transform->velocity.x = 0;
				break;
			default:
				break;
			}
		}
	}
};
#endif//INC_2D_GAME_SRC_COMPONENTS_KEYBOARDCONTROLLER_H_
