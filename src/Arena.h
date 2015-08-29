/*
 * Arena.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef ARENA_H_
#define ARENA_H_

#include <Box2D/Box2D.h>
#include "Wall.h"
#include "Cell.h"

namespace bg {

class Arena {
	std::vector<Wall> m_walls;
	std::vector<std::vector<Cell> > m_cells;
public:
	Arena(b2World & world, std::size_t rows, std::size_t columns);
	virtual ~Arena();
	void draw(sf::RenderWindow & window);

	std::size_t rows() const {
		return m_cells.size();
	}
	std::size_t columns() const {
		return m_cells.front().size();
	}

	bool addEntity(Entity* entity, const b2Vec2 position);
	bool addBomb(Bomb* entity);
};

} /* namespace bg */

#endif /* ARENA_H_ */
