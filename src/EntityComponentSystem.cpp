//
// Created by Jan on 21/01/2022.
//

#include "EntityComponentSystem.h"

void Entity::addGroup(Group mGroup)
{
	groupBitSet[mGroup] = true;
	manager.addToGroup(this, mGroup);
}