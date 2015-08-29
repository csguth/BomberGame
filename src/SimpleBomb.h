/*
 * SimpleBomb.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef SIMPLEBOMB_H_
#define SIMPLEBOMB_H_

#include "BomberMan.h"
#include "Bomb.h"
#include "Cell.h"
#include <Box2D/Box2D.h>
#include <cstdint>

namespace bg {

class SimpleBomb: public Bomb {
	BomberMan & m_owner;
	uint32_t m_counter;
	b2Body* m_body;
	bool m_ownerOver;
public:
	SimpleBomb(b2World & world, BomberMan & owner, const b2Vec2 position);
	virtual ~SimpleBomb();
	void explode();
	Entity* update();
	void draw(sf::RenderWindow & window) const;
	b2Vec2 position() const;
};

} /* namespace bg */

#endif /* SIMPLEBOMB_H_ */
