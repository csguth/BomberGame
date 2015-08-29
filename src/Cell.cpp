/*
 * Cell.cpp
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#include "Cell.h"
#include <algorithm>

namespace bg {

Cell::Cell():
			m_bomb(nullptr){

}

Cell::~Cell() {
}

bool Cell::addEntity(Entity* entity) {
	m_entities.push_back(entity);
	return true;
}

bool Cell::bomb(Bomb* bomb) {
	if(!m_bomb)
	{
		m_bomb = bomb;
		m_entities.push_back(bomb);
		return true;
	}
	return false;
}

bool Cell::addBomb(Bomb* entity) {
	if(bomb(entity) && addEntity(entity))
	{
		entity->cell(this);
		return true;
	}
	return false;
}

void Cell::bombExploded(Bomb* bomb) {
	m_bomb = nullptr;
	m_entities.erase(std::remove_if(m_entities.begin(), m_entities.end(), [bomb](Entity*e){
		return e == bomb;
	}));
}

} /* namespace bg */

