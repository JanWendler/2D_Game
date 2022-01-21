//
// Created by Jan on 21/01/2022.
//

#include "Collision.h"
bool Collision::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB)
{
	if(SDL_HasIntersection(&rectA, &rectB))
		return true;
	return false;
}
