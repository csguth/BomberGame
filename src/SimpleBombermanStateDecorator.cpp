/*
 * SimpleBombermanStateDecorator.cpp
 *
 *  Created on: 29 de ago de 2015
 *      Author: csguth
 */

#include "SimpleBombermanStateDecorator.h"

namespace bg {

SimpleBombermanStateDecorator::SimpleBombermanStateDecorator(
		SimpleBomberManState* decorated) :
		m_decorated(decorated) {
}

SimpleBombermanStateDecorator::~SimpleBombermanStateDecorator() {
}

SimpleBomberManState* SimpleBombermanStateDecorator::handleInput(
		SimpleBomberman& bm, const Input& input) {
	m_decorated = m_decorated->handleInput(bm, input);
	return this;
}

SimpleBomberManState* SimpleBombermanStateDecorator::update(
		SimpleBomberman& bm) {
	m_decorated = m_decorated->update(bm);
	return this;
}

} /* namespace bg */
