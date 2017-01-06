#pragma once

#include "Game.h"

Game::Game() : window(sf::VideoMode(300, 300, sf::Style::Titlebar), "Tic-Tac-Toe")
{
	emptyFieldTexture.loadFromFile("img/emptyField.png");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fields[i][j].setTexture(emptyFieldTexture);
			fields[i][j].setPosition(emptyFieldTexture.getSize().x * i, emptyFieldTexture.getSize().y * j);
		}
	}
}

void Game::start()
{
	while (window.isOpen())
	{
		render();
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
