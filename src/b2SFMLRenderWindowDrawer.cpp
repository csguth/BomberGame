/*
 * b2DSFMLRenderWindowDrawer.cpp
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#include "b2SFMLRenderWindowDrawer.h"
#include "VideoConfiguration.h"
namespace bg {
b2DSFMLRenderWindowDrawer* b2DSFMLRenderWindowDrawer::m_instance(nullptr);

b2DSFMLRenderWindowDrawer::b2DSFMLRenderWindowDrawer() {

}

b2DSFMLRenderWindowDrawer::~b2DSFMLRenderWindowDrawer() {
}

sf::Vector2f b2DSFMLRenderWindowDrawer::b2Vec2tosfVec2f(b2Vec2 currentVertex) {
	sf::Vector2f screenCoord(currentVertex.x, currentVertex.y);
	screenCoord.y *= -1;
	screenCoord *= VideoConfiguration::instance()->worldToScreenScaleFactor();
	return screenCoord;
}

void b2DSFMLRenderWindowDrawer::draw(b2Body& body, const sf::Color fillColor, sf::RenderWindow& window) {
	b2Shape::Type type = body.GetFixtureList()->GetShape()->m_type;
	if (type == b2Shape::e_polygon) {
		b2PolygonShape* shape =
				static_cast<b2PolygonShape*>(body.GetFixtureList()->GetShape());
		sf::ConvexShape polygon;
		polygon.setPointCount(shape->GetVertexCount());
		for (int32 i = 0; i < shape->GetVertexCount(); ++i) {
			b2Vec2 currentVertex = shape->GetVertex(i);
			currentVertex.x += body.GetPosition().x;
			currentVertex.y += body.GetPosition().y;
			sf::Vector2f screenCoord = b2Vec2tosfVec2f(currentVertex);
			polygon.setPoint(i, screenCoord);
		}
		polygon.setFillColor(fillColor);
		window.draw(polygon);
	}
	else if(type == b2Shape::e_circle)
	{
		b2CircleShape* shape =
				static_cast<b2CircleShape*>(body.GetFixtureList()->GetShape());
		sf::CircleShape circle;
		float32 radius = (shape->m_radius*VideoConfiguration::instance()->worldToScreenScaleFactor());
		sf::Vector2f position = b2Vec2tosfVec2f(body.GetPosition());
		position.x -= radius;
		position.y -= radius;
		circle.setRadius(radius);
		circle.setPosition(position);
		circle.setFillColor(fillColor);
		window.draw(circle);
	} else
		throw std::runtime_error("Not implemented");
}

b2DSFMLRenderWindowDrawer* b2DSFMLRenderWindowDrawer::instance() {
	if (!m_instance)
		m_instance = new b2DSFMLRenderWindowDrawer;
	return m_instance;
}

} /* namespace bg */
