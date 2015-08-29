/*
 * CarryingBombs.cpp
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#include "CarryingBombs.h"
#include <iostream>
namespace bg {

CarryingBombs::CarryingBombs(SimpleBomberManState* decorated, uint32_t numBombs):
									SimpleBombermanStateDecorator(decorated),
									m_numBombs(numBombs){
}

CarryingBombs::~CarryingBombs() {
}

SimpleBomberManState* CarryingBombs::handleInput(SimpleBomberman& bm,
		const Input& input) {
	SimpleBombermanStateDecorator::handleInput(bm, input);
	if(input.bomb() && m_numBombs)
	{
		if(bm.dropBomb())
			m_numBombs--;
	}
	return this;
}

SimpleBomberManState* CarryingBombs::update(SimpleBomberman& bm) {
	SimpleBombermanStateDecorator::update(bm);
	return this;
}

void CarryingBombs::receive() {
	std::cout << "CarryingBombs::receive" << std::endl;
	m_numBombs++;
}

} /* namespace bg */
