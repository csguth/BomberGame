/*
 * Arena.cpp
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#include "Arena.h"
#include <iostream>
namespace bg {

Arena::Arena(b2World & world, std::size_t r, std::size_t c) :
				m_cells(r, std::vector<Cell>(c)) {
	m_walls.reserve(100);
	m_walls.emplace_back(world,
			b2Vec2(static_cast<float32>(columns()) / 2.f, 0.f),
			b2Vec2(static_cast<float32>(columns()) / 2.f, 1.f / 2.f));
	m_walls.emplace_back(world,
			b2Vec2(static_cast<float32>(columns()) / 2.f,
					static_cast<float32>(rows())),
					b2Vec2(static_cast<float32>(columns()) / 2.f, 1.f / 2.f));

	m_walls.emplace_back(world,
			b2Vec2(0.f, static_cast<float32>(rows()) / 2.f),
			b2Vec2(1.f / 2.f, static_cast<float32>(rows()) / 2.f));
	m_walls.emplace_back(world,
			b2Vec2(static_cast<float32>(columns()), static_cast<float32>(rows()) / 2.f),
			b2Vec2(1.f / 2.f, static_cast<float32>(rows()) / 2.f));
	//
	for (float32 i = 2; i < rows(); i += 2.f) {
		for(float32 j = 2; j < columns(); j+=2.f)
			m_walls.emplace_back(world, b2Vec2(j, i), b2Vec2(.5f, .5f));
	}
	//	m_walls.shrink_to_fit();
}

Arena::~Arena() {
}

void Arena::draw(sf::RenderWindow& window) {
	for (auto & wall : m_walls)
		wall.draw(window);
}

bool Arena::addEntity(Entity* entity, const b2Vec2 position) {
	std::size_t column = static_cast<std::size_t>(position.x);
	std::size_t row = static_cast<std::size_t>(position.y);
	return m_cells[column][row].addEntity(entity);
}

bool Arena::addBomb(Bomb* entity) {
	const b2Vec2 position = entity->position();
	std::size_t column = static_cast<std::size_t>(position.x);
	std::size_t row = static_cast<std::size_t>(position.y);
	return m_cells[column][row].addBomb(entity);
}

} /* namespace bg */

