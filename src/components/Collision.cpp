//
// Created by Jan on 21/01/2022.
//

#include "Collision.h"
#include "ColliderComponent.h"

bool Collision::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB)
{
	if(SDL_HasIntersection(&rectA, &rectB))
		return true;
	return false;
}
bool Collision::AABB(const ColliderComponent& collA, const ColliderComponent& collB)
{
	if(AABB(collA.collider, collB.collider))
	{
		std::cout << collA.tag << " hit: " << collB.tag << std::endl;
		return true;
	}
	return false;
}
