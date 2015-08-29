/*
 * BomberMan.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef BOMBERMAN_H_
#define BOMBERMAN_H_

#include  "Bomb.h"
#include "Input.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

namespace bg {

class BomberMan : public Entity {
public:
	virtual ~BomberMan(){}
	virtual bool dropBomb() = 0;
	virtual void handleInput(const Input& input) = 0;
	virtual void bombExploded(Bomb*b) = 0;
};

} /* namespace bg */

#endif /* BOMBERMAN_H_ */
