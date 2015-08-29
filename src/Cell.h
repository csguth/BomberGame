/*
 * Cell.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef CELL_H_
#define CELL_H_

#include "Entity.h"
#include "Bomb.h"
#include <vector>

namespace bg {

class Cell {
	std::vector<Entity*> m_entities;
	Bomb* m_bomb;

public:
	Cell();
	virtual ~Cell();
	bool addEntity(Entity* entity);
	bool addBomb(Bomb* entity);
	bool bomb(Bomb* bomb);
	void bombExploded(Bomb* bomb);

};

} /* namespace bg */

#endif /* CELL_H_ */
