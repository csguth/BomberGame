/*
 * SimpleBombermanStandingState.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef SIMPLEBOMBERMANSTANDINGSTATE_H_
#define SIMPLEBOMBERMANSTANDINGSTATE_H_

#include "SimpleBomberManState.h"
#include "SimpleBomberman.h"

namespace bg {

class SimpleBombermanStandingState: public SimpleBomberManState {
public:
	SimpleBombermanStandingState();
	virtual ~SimpleBombermanStandingState();
	SimpleBomberManState* update(SimpleBomberman& bm);
};

} /* namespace bg */

#endif /* SIMPLEBOMBERMANSTANDINGSTATE_H_ */
