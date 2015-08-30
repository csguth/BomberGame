//============================================================================
// Name        : BombGame.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdint>
#include <SFML/Graphics.hpp>
#include "BombGame.h"
#include "KeyboardInput.h"
#include "VideoConfiguration.h"
int main() {


	bg::VideoConfiguration* configs = bg::VideoConfiguration::instance();
	bg::Arena arena = bg::BombGame::instance()->arena();
	sf::RenderWindow window(sf::VideoMode(arena.columns()*configs->cellSizeInPixels(), arena.rows()*configs->cellSizeInPixels()), "Bomber Game!");
	window.setFramerateLimit(60);
	sf::View view1;
	view1.setCenter(arena.columns()*configs->cellSizeInPixels()/2.f, -static_cast<float32>(arena.rows())*configs->cellSizeInPixels()/2.f);
	view1.setSize(arena.columns()*configs->cellSizeInPixels(), arena.rows()*configs->cellSizeInPixels());
	window.setView(view1);
	bg::BomberMan * player1 = bg::BombGame::instance()->createBomberMan();

	bg::KeyboardInput input1;

	while (window.isOpen()) {
		sf::Event event;
		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
//
		player1->handleInput(input1);
		player1->update();

		bg::BombGame::instance()->step();

		window.clear(sf::Color::White);
		bg::BombGame::instance()->draw(window);
		window.display();

	}

//	delete player1;
	return 0;
}
