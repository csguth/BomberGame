/*
 * SimpleBombermanStandingState.cpp
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#include "SimpleBombermanStandingState.h"
#include "SimpleBomberManWalkingState.h"

#include <iostream>

namespace bg {

SimpleBombermanStandingState::~SimpleBombermanStandingState() {
}

SimpleBombermanStandingState::SimpleBombermanStandingState() {
}

SimpleBomberManState* SimpleBombermanStandingState::update(
		SimpleBomberman& bm) {
	SimpleBomberManState* nextState = this;
	if(bm.velocity().x != 0.f || bm.velocity().y != 0.f)
	{
		nextState = new SimpleBomberManWalkingState;
		delete this;
	}
	return nextState;
}

} /* namespace bg */
