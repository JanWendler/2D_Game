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

	int height = 32;
	int width = 32;
	int scale = 1;
	float speed = 3;

	TransformComponent()
		: TransformComponent(0, 0, 32, 32, 1)
	{
	}
	explicit TransformComponent(int sc)
		: TransformComponent(0, 0, 32, 32, sc)
	{
	}

	TransformComponent(float x, float y)
		: TransformComponent(x, y, 32, 32, 1)
	{
	}

	TransformComponent(float x, float y, int h, int w, int sc)
		: position(x, y), height(h), width(w), scale(sc)
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
