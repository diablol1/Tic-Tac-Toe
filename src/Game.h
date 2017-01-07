#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Field.h"
#include "Enums.h"

class Game
{
public:
	Game();

	void start();
private:
	TextureCache textureCache;

	sf::RenderWindow window;

	Field fields[3][3];
	ft::FieldTypes currentFieldTypeToSet;

	void changeCurrentFieldTypeToContrary();

	void processEvents();
	void render();
};