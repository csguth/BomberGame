/*
 * SimpleBomb.cpp
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#include "SimpleBomb.h"
#include "b2SFMLRenderWindowDrawer.h"
#include "BombGame.h"
#include <iostream>

namespace bg {

SimpleBomb::~SimpleBomb() {
}

void SimpleBomb::explode() {
	std::cout << "Boom!!" << std::endl;
	m_cell->bombExploded(this);
	m_owner.receiveBomb();
}

SimpleBomb::SimpleBomb(b2World & world, BomberMan & owner,
		const b2Vec2 position) :
		m_owner(owner), m_counter(60 * 3), m_body(nullptr), m_ownerOver(true) {

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = position;
	bodyDef.angle = 0;
	m_body = world.CreateBody(&bodyDef);
	b2CircleShape circleShape;
	circleShape.m_radius = 0.5f;
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &circleShape;
	boxFixtureDef.density = 1;
	m_body->CreateFixture(&boxFixtureDef);

}

Entity* SimpleBomb::update() {
	if (!--m_counter) {
		explode();
		delete this;
		return nullptr;
	}
	return this;
}

void SimpleBomb::draw(sf::RenderWindow& window) const {
	b2DSFMLRenderWindowDrawer::instance()->draw(*m_body, sf::Color::Black,
			window);
}

b2Vec2 SimpleBomb::position() const {
	return m_body->GetPosition();
}

} /* namespace bg */
