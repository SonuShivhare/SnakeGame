#include "Game.hpp"
#include"MainMenuState.hpp"
#include "SoundEffect.hpp"

Game::Game()
{
	this->data->window.create(sf::VideoMode(window_Width, window_Height), "-Snake Game-");
	this->data->window.setFramerateLimit(60);

	//switch to Starting State
	this->data->machine.addState(stateRef(new MainMenuState(this->data)));

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