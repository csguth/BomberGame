/*
 * KeyboardInput.h
 *
 *  Created on: 25 de ago de 2015
 *      Author: csguth
 */

#ifndef KEYBOARDINPUT_H_
#define KEYBOARDINPUT_H_

#include "Input.h"

namespace bg {

class KeyboardInput: public Input {
public:
	KeyboardInput();
	virtual ~KeyboardInput();

	bool up() const;
	bool right() const;
	bool down() const;
	bool left() const;
	bool bomb() const;
};

} /* namespace bg */

#endif /* KEYBOARDINPUT_H_ */
