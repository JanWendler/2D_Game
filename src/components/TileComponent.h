//
// Created by Jan on 21/01/2022.
//

#ifndef INC_2D_GAME_SRC_COMPONENTS_TILECOMPONENT_H_
#define INC_2D_GAME_SRC_COMPONENTS_TILECOMPONENT_H_

#include "../EntityComponentSystem.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"

class TileComponent : public Component
{
public:
	TransformComponent* transform;
	SpriteComponent* sprite;

	SDL_Rect tileRect;
	int tileID;

	std::string path;

	TileComponent() = default;

	TileComponent(int x, int y, int w, int h, int id)
	{
		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;
		tileID = id;

		switch (tileID)
		{
		case 0:
			path = "../../assets/Water.png";
			break;
		case 1:
			path = "../../assets/Dirt.png";
			break;
		case 2:
			path = "../../assets/Grass.png";
			break;
		case 3:
			path = "../../assets/Sand.png";
			break;
		default:
			break;
		}
	}

	void init() override
	{
		entity->addComponent<TransformComponent>(tileRect.x, tileRect.y, tileRect.h, tileRect.w, 1);
		transform = &entity->getComponent<TransformComponent>();

		entity->addComponent<SpriteComponent>(path);
		sprite = &entity->getComponent<SpriteComponent>();
	}
};
#endif//INC_2D_GAME_SRC_COMPONENTS_TILECOMPONENT_H_
