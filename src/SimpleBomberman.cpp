/*
 * SimpleBomberman.cpp
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#include "SimpleBomberman.h"
#include "SimpleBomb.h"
#include "SimpleBombermanStandingState.h"
#include "CarryingBombs.h"
#include "WalkableSimpleBomberMan.h"

#include <iostream>
#include "b2SFMLRenderWindowDrawer.h"
#include "BombGame.h"

namespace bg {

SimpleBomberman::SimpleBomberman(b2World & world, const b2Vec2 position) :
				m_body(nullptr), m_bombs(
						new CarryingBombs(new SimpleBombermanStandingState, 1)), m_state(
								new WalkableSimpleBomberMan(m_bombs)), m_lastBomb(nullptr), m_base_velocity(
										5.f) {
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = position;
	bodyDef.angle = 0;
	m_body = world.CreateBody(&bodyDef);
	b2PolygonShape boxShape;
	boxShape.SetAsBox(.3f, .3f);
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	m_body->CreateFixture(&boxFixtureDef);
}

SimpleBomberman::~SimpleBomberman() {
	m_body->GetWorld()->DestroyBody(m_body);
}

bool SimpleBomberman::dropBomb() {
	Bomb* bomb = new SimpleBomb(*m_body->GetWorld(), *this,
			m_body->GetPosition());
	bool result = BombGame::instance()->createBomb(bomb);
	if (result) {
		std::cout << "Dropped a bomb" << std::endl;
		m_lastBomb = bomb;
	}
	return result;
}

void SimpleBomberman::handleInput(const Input& input) {
	m_state = m_state->handleInput(*this, input);
}

Entity* SimpleBomberman::update() {
	m_state = m_state->update(*this);
	const b2Vec2 bomberManPosition = m_body->GetPosition();
	std::size_t bomberManColumn = static_cast<std::size_t>(bomberManPosition.x);
	std::size_t bomberManRow = static_cast<std::size_t>(bomberManPosition.y);
	std::cout << bomberManRow << ", " << bomberManColumn << std::endl;
	if (m_lastBomb) {
		const b2Vec2 lastBombPosition = m_lastBomb->position();
		std::size_t lastBombColumn = static_cast<std::size_t>(lastBombPosition.x);
		std::size_t lastBombRow = static_cast<std::size_t>(lastBombPosition.y);
		if(bomberManColumn != lastBombColumn || bomberManRow != lastBombRow)
		{
			m_lastBomb->enableCollision();
			m_lastBomb = nullptr;
		}
	}
	return this;
}

void SimpleBomberman::velocity(const b2Vec2 velocity) {
	m_body->SetLinearVelocity(velocity);
}

void SimpleBomberman::draw(sf::RenderWindow& window) const {
	b2DSFMLRenderWindowDrawer::instance()->draw(*m_body, sf::Color::Blue,
			window);
}

void SimpleBomberman::bombExploded(Bomb*b) {
	if(m_lastBomb == b)
		m_lastBomb = nullptr;
	dynamic_cast<CarryingBombs*>(m_bombs)->receive();
}

} /* namespace bg */

