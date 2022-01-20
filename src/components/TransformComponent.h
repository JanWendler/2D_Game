//
// Created by Jan on 20/01/2022.
//

#ifndef INC_2D_GAME_SRC_COMPONENTS_TRANSFORMCOMPONENT_H_
#define INC_2D_GAME_SRC_COMPONENTS_TRANSFORMCOMPONENT_H_

#include "../EntityComponentSystem.h"
#include "../Vector2D.h"
#include <iostream>

class TransformComponent : public Component
{
public:
	Vector2D position;
	Vector2D velocity;

	float speed = 3;

	TransformComponent()
		: position(0, 0)
	{
	}
	TransformComponent(float x, float y)
		: position(x, y)
	{
	}

	void init() override
	{
	}

	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
	void render() override
	{
	}
	~TransformComponent() override = default;
};

#endif//INC_2D_GAME_SRC_COMPONENTS_TRANSFORMCOMPONENT_H_
