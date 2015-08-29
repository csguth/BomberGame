/*
 * SimpleBomberManWalkingState.cpp
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#include "SimpleBomberManWalkingState.h"
#include "SimpleBombermanStandingState.h"

#include <iostream>

namespace bg {

SimpleBomberManWalkingState::SimpleBomberManWalkingState() {
}

SimpleBomberManWalkingState::~SimpleBomberManWalkingState() {
}

SimpleBomberManState* SimpleBomberManWalkingState::update(SimpleBomberman& bm) {
	SimpleBomberManState* nextState = this;
	if (bm.velocity().x == 0.f && bm.velocity().y == 0.f) {
		nextState = new SimpleBombermanStandingState;
		delete this;
	}
	return nextState;
}

} /* namespace bg */
