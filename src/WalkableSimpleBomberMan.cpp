/*
 * WalkableSimpleBomberMan.cpp
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#include "WalkableSimpleBomberMan.h"

namespace bg {

WalkableSimpleBomberMan::WalkableSimpleBomberMan(
		SimpleBomberManState* decorated) :
											SimpleBombermanStateDecorator(decorated)
{
}

WalkableSimpleBomberMan::~WalkableSimpleBomberMan() {
}

SimpleBomberManState* WalkableSimpleBomberMan::handleInput(SimpleBomberman& bm, const Input& input) {
	SimpleBombermanStateDecorator::handleInput(bm, input);

	b2Vec2 velocity(0.f, 0.f);

	if(input.up())
		velocity.y += bm.baseVelocity();
	if(input.down())
		velocity.y -= bm.baseVelocity();
	if(input.right())
		velocity.x += bm.baseVelocity();
	if(input.left())
		velocity.x -= bm.baseVelocity();

	bm.velocity(velocity);
	return this;
}

SimpleBomberManState* WalkableSimpleBomberMan::update(SimpleBomberman& bm) {
	SimpleBombermanStateDecorator::update(bm);
	return this;
}

} /* namespace bg */
