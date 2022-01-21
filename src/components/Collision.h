//
// Created by Jan on 21/01/2022.
//

#ifndef INC_2D_GAME_SRC_COMPONENTS_COLLISION_H_
#define INC_2D_GAME_SRC_COMPONENTS_COLLISION_H_

#include <SDL.h>
class ColliderComponent;
class Collision
{
public:
	// Axis Aligned Bounding Box
	static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
	static bool AABB(const ColliderComponent& collA, const ColliderComponent& collB);
};

#endif//INC_2D_GAME_SRC_COMPONENTS_COLLISION_H_
