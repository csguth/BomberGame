/*
 * b2DSFMLRenderWindowDrawer.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef B2SFMLRENDERWINDOWDRAWER_H_
#define B2SFMLRENDERWINDOWDRAWER_H_

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

namespace bg {

class b2DSFMLRenderWindowDrawer {
	static b2DSFMLRenderWindowDrawer * m_instance;
	b2DSFMLRenderWindowDrawer();
	sf::Vector2f b2Vec2tosfVec2f(b2Vec2 currentVertex);

public:
	virtual ~b2DSFMLRenderWindowDrawer();
	void draw(b2Body & body, const sf::Color fillColor, sf::RenderWindow & window);
	static b2DSFMLRenderWindowDrawer* instance();
};

} /* namespace bg */

#endif /* B2SFMLRENDERWINDOWDRAWER_H_ */
