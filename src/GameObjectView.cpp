//
// Created by Jan on 16/01/2022.
//

#include <iostream>
#include "GameObjectView.h"
#include "TextureManager.h"
#include "GameWindow.h"

GameObjectView::GameObjectView(const std::string& texturePath, const GameObject& object):
	object(object)
{
	texture = TextureManager::LoadTexture(texturePath);

	srcrect.h = 32;
	srcrect.w = 32;
	srcrect.x = 0;
	srcrect.y = 0;

	destrect.h = 32;
	destrect.w = 32;
	destrect.x = 0;
	destrect.y = 0;
}


void GameObjectView::render()
{
	destrect.x = object.getCoordinates().getX();
	destrect.y = object.getCoordinates().getY();

	TextureManager::Draw(texture, srcrect, destrect);
}
