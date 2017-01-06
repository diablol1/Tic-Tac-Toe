#pragma once

#include "Game.h"

Game::Game() : window(sf::VideoMode(300, 300, sf::Style::Titlebar), "Tic-Tac-Toe")
{}

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
	window.display();
}
