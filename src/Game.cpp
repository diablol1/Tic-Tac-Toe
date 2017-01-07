#pragma once

#include "Game.h"

Game::Game() : window(sf::VideoMode(300, 300, sf::Style::Titlebar), "Tic-Tac-Toe"),
	currentFieldTypeToSet(ft::FieldTypes::CIRCLE)
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fields[i][j] = Field(&textureCache,
				sf::Vector2f(textureCache.get("emptyField").getSize().x * i,
					textureCache.get("emptyField").getSize().y * j));
		}
	}
}

void Game::start()
{
	while (window.isOpen())
	{
		processEvents();
		render();
	}
}

void Game::changeCurrentFieldTypeToContrary()
{ 
	if (currentFieldTypeToSet == ft::FieldTypes::CIRCLE)
		currentFieldTypeToSet = ft::FieldTypes::CROSS;
	else
		currentFieldTypeToSet = ft::FieldTypes::CIRCLE;
}

void Game::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		else if (event.type == sf::Event::MouseButtonReleased)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (fields[i][j].isHover(window) && fields[i][j].type == ft::FieldTypes::EMPTY)
					{
						std::cout << "Clicked button: " << "X: " << i << " " << "Y: " << j << std::endl;
						fields[i][j].setFieldType(currentFieldTypeToSet);
						changeCurrentFieldTypeToContrary();
						i = 3; //To break parent loop
					}
				}
			}
		}
	}
}

void Game::render()
{
	window.clear();

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			window.draw(fields[i][j]);
		}
	}
	window.display();
}
