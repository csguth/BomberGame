/*
 * CarryingBombs.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef CARRYINGBOMBS_H_
#define CARRYINGBOMBS_H_

#include "SimpleBombermanStateDecorator.h"

namespace bg {

class CarryingBombs: public SimpleBombermanStateDecorator {
	uint32_t m_numBombs;
public:
	CarryingBombs(SimpleBomberManState * decorated, uint32_t numBombs);
	virtual ~CarryingBombs();
	SimpleBomberManState* handleInput(SimpleBomberman& bm, const Input & input);
	SimpleBomberManState* update(SimpleBomberman& bm);
	void receive();
};

} /* namespace bg */

#endif /* CARRYINGBOMBS_H_ */
