/*
 * Wall.cpp
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#include "Wall.h"
#include "b2SFMLRenderWindowDrawer.h"

namespace bg {

Wall::Wall(b2World& world, const b2Vec2 position, const b2Vec2 size) :
		m_body(nullptr) {
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = position;
	bodyDef.angle = 0;
	m_body = world.CreateBody(&bodyDef);
	b2PolygonShape boxShape;
	boxShape.SetAsBox(size.x, size.y);
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	m_body->CreateFixture(&boxFixtureDef);
}

Wall::~Wall() {
	m_body->GetWorld()->DestroyBody(m_body);
}

void Wall::draw(sf::RenderWindow& window) {
	b2DSFMLRenderWindowDrawer::instance()->draw(*m_body, sf::Color::Green, window);
}

} /* namespace bg */

