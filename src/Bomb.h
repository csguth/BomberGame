/*
 * Bomb.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef BOMB_H_
#define BOMB_H_

#include "Entity.h"
#include <Box2D/Box2D.h>

namespace bg {

class Cell;
class Bomb : public Entity {
protected:
	Cell* m_cell;
public:
	virtual ~Bomb(){}
	virtual void explode() = 0;
	virtual b2Vec2 position() const = 0;
	void cell(Cell* cell) { m_cell = cell; }
};

} /* namespace bg */

#endif /* BOMB_H_ */
