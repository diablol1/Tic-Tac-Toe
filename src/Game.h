#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
public:
	Game();

	void start();
private:
	sf::RenderWindow window;

	sf::Texture emptyFieldTexture;
	sf::Texture circleFieldTexture;
	sf::Texture crossFieldTexture;

	sf::Sprite fields[3][3];

	void processEvents();
	void render();

	bool isCursorOn(const sf::FloatRect& rect);
};