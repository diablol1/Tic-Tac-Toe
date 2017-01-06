#pragma once

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();

	void start();
private:
	sf::RenderWindow window;

	void render();
};