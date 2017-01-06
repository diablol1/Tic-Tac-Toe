#pragma once

#include <SFML/Graphics.hpp>
#include <array>

class Game
{
public:
	Game();

	void start();
private:
	sf::RenderWindow window;

	sf::Texture emptyFieldTexture;
	sf::Sprite fields[3][3];

	void processEvents();
	void render();
};