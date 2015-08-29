/*
 * SimpleBomberman.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef SIMPLEBOMBERMAN_H_
#define SIMPLEBOMBERMAN_H_

#include "BomberMan.h"
#include "SimpleBomberManState.h"
#include <Box2D/Box2D.h>

namespace bg {

class SimpleBomberManState;
class SimpleBomberman : public BomberMan {
	b2Body * m_body;
	SimpleBomberManState * m_bombs;
	SimpleBomberManState * m_state;
	double m_base_velocity;

public:
	SimpleBomberman(b2World & world, const b2Vec2 position);
	virtual ~SimpleBomberman();
	bool dropBomb();
	void handleInput(const Input& input);
	Entity* update();
	void velocity(const b2Vec2 velocity);
	void draw(sf::RenderWindow& window) const;

	const b2Vec2 velocity() const { return m_body->GetLinearVelocity(); }
	double baseVelocity() const { return m_base_velocity; }
	void receiveBomb();
};

} /* namespace bg */

#endif /* SIMPLEBOMBERMAN_H_ */
