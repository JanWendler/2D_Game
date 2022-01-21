//
// Created by Jan on 21/01/2022.
//

#ifndef INC_2D_GAME_SRC_COMPONENTS_COLLISION_H_
#define INC_2D_GAME_SRC_COMPONENTS_COLLISION_H_

#include <SDL.h>
class Collision
{
public:
	// Axis Aligned Bounding Box
	static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB);
};

#endif//INC_2D_GAME_SRC_COMPONENTS_COLLISION_H_
