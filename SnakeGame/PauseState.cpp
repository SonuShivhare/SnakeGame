#include "PauseState.hpp"
#include "MainMenuState.hpp"

PauseState::PauseState(GameDataRef data) : data(data)
{
}

PauseState::~PauseState()
{
}

void PauseState::init()
{
	background.setTexture(this->data->assets.getTexture("background"));
	playButton.setTexture(this->data->assets.getTexture("playButton"));
	homeButton.setTexture(this->data->assets.getTexture("homeButton"));

	playButton.setTextureRect(Blue_button);
	homeButton.setTextureRect(Blue_button);

	playButton.setPosition(window_Width / 2, window_Height / 3);
	homeButton.setPosition(window_Width / 2, window_Height / 1.5);

	playButton.setOrigin(sf::Vector2f(playButton.getGlobalBounds().width / 2, playButton.getGlobalBounds().height / 2));
	homeButton.setOrigin(sf::Vector2f(homeButton.getGlobalBounds().width / 2, homeButton.getGlobalBounds().height / 2));

	bool isMouseButtonReleased = true;
}

void PauseState::handleInput()
{
	if (playButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->data->window))))
	{
		playButton.setTextureRect(Green_button);
		if (this->data->input.isSpriteClicked(playButton, sf::Mouse::Left, this->data->window))
		{
			playButton.setTextureRect(Yellow_button);
			isMouseButtonReleased = true;
		}
		else if (isMouseButtonReleased)
		{
			//resume the game
			isMouseButtonReleased = false;
			this->data->machine.removeState();
		}
	}
	else playButton.setTextureRect(Blue_button);

	if (homeButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->data->window))))
	{
		homeButton.setTextureRect(Green_button);
		if (this->data->input.isSpriteClicked(homeButton, sf::Mouse::Left, this->data->window))
		{
			homeButton.setTextureRect(Yellow_button);
			isMouseButtonReleased = true;
		}
		else if (isMouseButtonReleased)
		{
			//which to main menu
			isMouseButtonReleased = false;
			this->data->machine.removeState();
			this->data->machine.addState(stateRef(new MainMenuState(this->data)));
		}
	}
	else homeButton.setTextureRect(Blue_button);
}

void PauseState::update()
{

}

void PauseState::draw()
{
	this->data->window.clear();
	this->data->window.draw(background);
	this->data->window.draw(playButton);
	this->data->window.draw(homeButton);
	this->data->window.display();
}