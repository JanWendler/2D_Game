//
// Created by Jan on 16/01/2022.
//

#include "GameObjectController.h"
#include <utility>

GameObjectController::GameObjectController(std::string name, const std::string& texturePath):
	name(std::move(name))
{
	object = new GameObject(0,0);
	view = new GameObjectView(texturePath,*object);
}

void GameObjectController::update(int x, int y)
{
	object->updatePosition(x,y);
}

void GameObjectController::render()
{
	view->render();
}
