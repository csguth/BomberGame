/*
 * Wall.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef WALL_H_
#define WALL_H_

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

namespace bg {

class Wall {
	b2Body * m_body;
public:
	Wall(b2World & world, const b2Vec2 position, const b2Vec2 size);
	virtual ~Wall();
	void draw(sf::RenderWindow & window);
};

} /* namespace bg */

#endif /* WALL_H_ */
