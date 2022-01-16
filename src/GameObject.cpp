//
// Created by Jan on 16/01/2022.
//

#include "GameObject.h"
#include "TextureManager.h"
GameObject::GameObject(int x, int y):
	cor(x,y)
{

}
void GameObject::updatePosition(int dx, int dy)
{
	cor.setX(cor.getX()+dx);
	cor.setY(cor.getY()+dy);
}
