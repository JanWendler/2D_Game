//
// Created by Jan on 17/01/2022.
//

#ifndef INC_2D_GAME_SRC_ENTITYCOMPONENTSYSTEM_H_
#define INC_2D_GAME_SRC_ENTITYCOMPONENTSYSTEM_H_
#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <memory>
#include <vector>

class Component;
class Entity;
using ComponentID = std::size_t;

inline ComponentID getComponentID()
{
	static ComponentID lastID = 0;
	return lastID++;
}

template<typename T>
inline ComponentID getComponentTypeID() noexcept
{
	static ComponentID typeID{getComponentID()};
	return typeID;
}

constexpr std::size_t maxComponents = 32;
using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public:
	Entity* entity;

	virtual void init(){};
	virtual void update(){};
	virtual void render(){};

	virtual ~Component() = default;
};

class Entity
{
private:
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;

public:
	void update()
	{
		for (auto& c: components)
			c->update();
	}
	void render()
	{
		for (auto& c: components)
			c->render();
	}
	bool isActive() const
	{
		return active;
	}
	void destroy()
	{
		active = false;
	}

	template<typename T>
	bool hasComponent() const
	{
		return componentBitSet[getComponentTypeID<T>()];
	}

	template<typename T, typename... Targs>
	T& addComponent(Targs&&... mArgs)
	{
		T* c(new T(std::forward<Targs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{c};
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = c;
		componentBitSet[getComponentTypeID<T>()] = true;

		c->init();
		return *c;
	}

	template<typename T>
	T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
};

class Manager
{
private:
	std::vector<std::unique_ptr<Entity>> entities;

public:
	void update()
	{
		for (auto& e: entities)
			e->update();
	}
	void render()
	{
		for (auto& e: entities)
			e->render();
	}
	void refresh()
	{
		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
									  [](const std::unique_ptr<Entity>& mEntity) {
										  return !mEntity->isActive();
									  }),
					   std::end(entities));
	}

	Entity& addEntity()
	{
		auto* e = new Entity();
		std::unique_ptr<Entity> uPtr{e};
		entities.emplace_back(std::move(uPtr));
		return *e;
	}
	~Manager()
	{
		std::cout << "Manager Destructor" << std::endl;
	}
};
#endif//INC_2D_GAME_SRC_ENTITYCOMPONENTSYSTEM_H_
