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
	m_walls.reserve(4);
	m_walls.emplace_back(world, b2Vec2(columns() / 2, 0.f),
			b2Vec2(columns() / 2, 1.f / 2.f));
	m_walls.emplace_back(world, b2Vec2(columns() / 2, rows()),
			b2Vec2(columns() / 2, 1.f / 2.f));

	m_walls.emplace_back(world, b2Vec2(0.f, rows() / 2.f),
			b2Vec2(1.f / 2, rows() / 2.f));

	m_walls.emplace_back(world, b2Vec2(columns(), rows() / 2.f),
			b2Vec2(1.f / 2, rows() / 2.f));
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

