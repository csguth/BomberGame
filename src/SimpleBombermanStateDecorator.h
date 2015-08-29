/*
 * SimpleBombermanStateDecorator.h
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#ifndef SIMPLEBOMBERMANSTATEDECORATOR_H_
#define SIMPLEBOMBERMANSTATEDECORATOR_H_

#include "SimpleBomberManState.h"

namespace bg {

class SimpleBombermanStateDecorator: public SimpleBomberManState {
protected:
	SimpleBomberManState * m_decorated;
public:
	SimpleBombermanStateDecorator(SimpleBomberManState * decorated);
	virtual ~SimpleBombermanStateDecorator();
	SimpleBomberManState* handleInput(SimpleBomberman& bm, const Input & input);
	SimpleBomberManState* update(SimpleBomberman& bm);
};

} /* namespace bg */

#endif /* SIMPLEBOMBERMANSTATEDECORATOR_H_ */
