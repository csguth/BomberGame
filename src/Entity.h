/*
 * Entity.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.hpp>

namespace bg {

class Entity {
public:
	virtual ~Entity(){}
	virtual Entity* update() = 0;
	virtual void draw(sf::RenderWindow & window) const = 0;
};

} /* namespace bg */

#endif /* ENTITY_H_ */
