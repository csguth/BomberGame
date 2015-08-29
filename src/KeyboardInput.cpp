/*
 * KeyboardInput.cpp
 *
 *  Created on: 25 de ago de 2015
 *      Author: csguth
 */

#include "KeyboardInput.h"
#include <SFML/Window/Keyboard.hpp>

namespace bg {

using kb = sf::Keyboard;

KeyboardInput::KeyboardInput() {

}

KeyboardInput::~KeyboardInput() {
}

bool KeyboardInput::up() const {
	return kb::isKeyPressed(kb::Up);
}

bool KeyboardInput::right() const {
	return kb::isKeyPressed(kb::Right);
}

bool KeyboardInput::down() const {
	return kb::isKeyPressed(kb::Down);
}

bool KeyboardInput::left() const {
	return kb::isKeyPressed(kb::Left);
}

bool KeyboardInput::bomb() const {
	return kb::isKeyPressed(kb::Space);
}

} /* namespace bg */
