/*
 * WalkableSimpleBomberMan.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef WALKABLESIMPLEBOMBERMAN_H_
#define WALKABLESIMPLEBOMBERMAN_H_

#include "SimpleBombermanStateDecorator.h"

namespace bg {

class WalkableSimpleBomberMan: public SimpleBombermanStateDecorator {
public:
	WalkableSimpleBomberMan(SimpleBomberManState * decorated);
	virtual ~WalkableSimpleBomberMan();
	virtual SimpleBomberManState* handleInput(SimpleBomberman& bm, const Input & input);
	virtual SimpleBomberManState* update(SimpleBomberman& bm);
};

} /* namespace bg */

#endif /* WALKABLESIMPLEBOMBERMAN_H_ */
