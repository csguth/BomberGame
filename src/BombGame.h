/*
 * BombGame.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef BOMBGAME_H_
#define BOMBGAME_H_

#include "BomberMan.h"
#include "Arena.h"
#include <Box2D/Box2D.h>
#include <queue>
namespace bg {

class BombGame {
	static BombGame * m_instance;
	BombGame();
	b2World m_world;
	Arena m_arena;
	std::deque<Entity*> m_entities;
public:
	virtual ~BombGame();
	static BombGame * instance();
	BomberMan * createBomberMan();
	void step();

	void draw(sf::RenderWindow & window);

	const Arena& arena() const { return m_arena; }

	bool createBomb(Bomb* bm);
};

} /* namespace bg */

#endif /* BOMBGAME_H_ */
