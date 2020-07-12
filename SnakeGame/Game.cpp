#include "Game.hpp"
#include"MainMenuState.hpp"
#include"Food.hpp"
#include"Snake.hpp"

Game::Game()
{
	data->window.create(sf::VideoMode(window_Width, window_Height), "-Snake Game-");
	data->window.setFramerateLimit(60);
	//switch to Starting State
	data->machine.addState(stateRef(new MainMenuState(this->data)));

	//new Food(this->data);

	this->run();
}

Game::~Game()
{
}

void Game::run()
{
	while (this->data->window.isOpen())
	{
		sf::Event event;
		while (this->data->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->data->window.close();
			}
		}

		this->data->machine.processStateChanges();
		this->data->machine.getActiveState()->handleInput();
		this->data->machine.getActiveState()->update();
		this->data->machine.getActiveState()->draw();
	}
}