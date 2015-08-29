/*
 * SimpleBomberManState.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef SIMPLEBOMBERMANSTATE_H_
#define SIMPLEBOMBERMANSTATE_H_

#include "Input.h"
#include "SimpleBomberman.h"

namespace bg {

class SimpleBomberman;
class SimpleBomberManState {
public:
	virtual ~SimpleBomberManState(){}
	virtual SimpleBomberManState* handleInput(SimpleBomberman& bm, const Input & input) { return this; };
	virtual SimpleBomberManState* update(SimpleBomberman& bm) = 0;
};

} /* namespace bg */

#endif /* SIMPLEBOMBERMANSTATE_H_ */
