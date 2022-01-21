//
// Created by Jan on 20/01/2022.
//

#ifndef INC_2D_GAME_SRC_COMPONENTS_COLLIDERCOMPONENT_H_
#define INC_2D_GAME_SRC_COMPONENTS_COLLIDERCOMPONENT_H_

#include <SDL.h>
#include <string>
#include <utility>
#include "../Game.h"
#include "TransformComponent.h"

class ColliderComponent : public Component
{
public:
	SDL_Rect collider;
	std::string tag;

	TransformComponent* transform;

	explicit ColliderComponent(std::string tag):
 		tag(std::move(tag))
	{}
	void init() override
	{
		if (!entity->hasComponent<TransformComponent>())
		{
			entity->addComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();

		Game::getInstance()->getColliders()->push_back(this);

	}

	void update() override
	{
		collider.x = (int)transform->position.x;
		collider.y = (int)transform->position.y;
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}

	~ColliderComponent() override = default;
};
#endif//INC_2D_GAME_SRC_COMPONENTS_COLLIDERCOMPONENT_H_
