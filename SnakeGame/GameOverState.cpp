#include "GameOverState.hpp"
#include"MainMenuState.hpp"

GameOverState::GameOverState(GameDataRef data) : data(data)
{
}

GameOverState::~GameOverState()
{
}

void GameOverState::init()
{
	homeButton.setTexture(data->assets.getTexture("homeButton"));
	homeButton.setTextureRect(Green_button);
	homeButton.setPosition(window_Width / 1.6, window_Height / 1.2);
	homeButton.setOrigin(sf::Vector2f(homeButton.getGlobalBounds().width / 2, homeButton.getGlobalBounds().height / 2));
	

	quitButton.setTexture(data->assets.getTexture("quitButton"));
	quitButton.setTextureRect(Green_button);
	quitButton.setPosition(window_Width / 1.15, window_Height / 1.2);
	quitButton.setOrigin(sf::Vector2f(quitButton.getGlobalBounds().width / 2, quitButton.getGlobalBounds().height / 2));
	
	highestScore.setFont(this->data->assets.getFont("arialfont"));
	highestScore.setFillColor(sf::Color::Black);
	highestScore.Bold;
	highestScore.setCharacterSize(45);
	highestScore.setString("High Score\n\t  " + std::to_string(highScore.returnHighestScore()));
	highestScore.setPosition(sf::Vector2f(window_Width / 1.35, window_Height / 2.5));
	highestScore.setOrigin(sf::Vector2f(highestScore.getGlobalBounds().width / 2, highestScore.getGlobalBounds().height / 2));

	currentScore.setFont(this->data->assets.getFont("font"));
	currentScore.setFillColor(sf::Color::Black);
	currentScore.setCharacterSize(60);
	currentScore.setString("Your Score\n\t\t" + std::to_string(highScore.returnPlayerScore()));
	currentScore.setPosition(sf::Vector2f(window_Width / 3.3, window_Height / 2.6));
	currentScore.setOrigin(sf::Vector2f(currentScore.getGlobalBounds().width / 2, currentScore.getGlobalBounds().height / 2));

	background.setTexture(this->data->assets.getTexture("gameOverBackground"));

	highScore.compareScore();

	isMouseButtonReleased = false;

}

void GameOverState::handleInput()
{
	if (homeButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->data->window))))
	{
		homeButton.setTextureRect(Blue_button);
		if (this->data->input.isSpriteClicked(homeButton, sf::Mouse::Left, this->data->window))
		{
			homeButton.setTextureRect(Yellow_button);
			isMouseButtonReleased = true;
		}
		else if (isMouseButtonReleased && !this->data->input.isSpriteClicked(homeButton, sf::Mouse::Left, this->data->window))
		{
			//resume the game
			isMouseButtonReleased = false;
			this->data->machine.addState(stateRef(new MainMenuState(this->data)));
		}
	}
	else homeButton.setTextureRect(Green_button);

	if (quitButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->data->window))))
	{
		quitButton.setTextureRect(Blue_button);
		if (this->data->input.isSpriteClicked(quitButton, sf::Mouse::Left, this->data->window))
		{
			quitButton.setTextureRect(Yellow_button);
			isMouseButtonReleased = true;
		}
		else if (isMouseButtonReleased && !this->data->input.isSpriteClicked(quitButton, sf::Mouse::Left, this->data->window))
		{
			//resume the game
			isMouseButtonReleased = false;
			this->data->window.close();
		}
	}
	else quitButton.setTextureRect(Green_button);
}

void GameOverState::update()
{
}

void GameOverState::draw()
{
	this->data->window.clear();
	this->data->window.draw(background);
	this->data->window.draw(homeButton);
	this->data->window.draw(quitButton);
	this->data->window.draw(highestScore);
	this->data->window.draw(currentScore);
	this->data->window.display();
}