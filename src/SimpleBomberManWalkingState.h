/*
 * SimpleBomberManWalkingState.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef SIMPLEBOMBERMANWALKINGSTATE_H_
#define SIMPLEBOMBERMANWALKINGSTATE_H_

#include "SimpleBomberManState.h"

namespace bg {

class SimpleBomberManWalkingState: public SimpleBomberManState {
public:
	SimpleBomberManWalkingState();
	virtual ~SimpleBomberManWalkingState();
	virtual SimpleBomberManState* update(SimpleBomberman& bm);
};

} /* namespace bg */

#endif /* SIMPLEBOMBERMANWALKINGSTATE_H_ */
