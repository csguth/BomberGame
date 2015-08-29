/*
 * BombGame.cpp
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#include "BombGame.h"
#include "SimpleBomberman.h"

namespace bg {

BombGame * BombGame::m_instance(nullptr);

BombGame::BombGame() :
					 m_world(b2Vec2_zero),
					 m_arena(m_world, 16, 16){
}

BombGame::~BombGame() {
}

BombGame* BombGame::instance() {
	if(!m_instance)
		m_instance = new BombGame;
	return m_instance;
}

BomberMan* BombGame::createBomberMan() {
	BomberMan * bm = new SimpleBomberman(m_world, b2Vec2(5.f, 5.f));
	m_entities.push_back(bm);
	return bm;
}

void BombGame::step() {
	std::deque<Entity*> nextRound;

	while(!m_entities.empty())
	{
		Entity* entity = m_entities.front();
		m_entities.pop_front();
		entity = entity->update();
		if(entity)
			nextRound.push_back(entity);
	}
	m_entities = nextRound;
	m_world.Step(1/60.f, 8, 3);
}

void BombGame::draw(sf::RenderWindow& window) {
	m_arena.draw(window);
	for(auto & e : m_entities)
		e->draw(window);
}

bool BombGame::createBomb(Bomb* bm) {
	if(m_arena.addBomb(bm))
	{
		m_entities.push_back(bm);
		return true;
	}
	return false;
}

} /* namespace bg */

