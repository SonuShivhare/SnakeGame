#include "MainMenuState.hpp"
#include"SplashScreen.hpp"

MainMenuState::MainMenuState(GameDataRef data) : data(data)
{
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::init()
{
	title.setTexture(this->data->assets.getTexture("title"));
	title.setPosition(window_Width / 2, window_Height/5);
	title.setOrigin(sf::Vector2f(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2));

	playButton.setTexture(this->data->assets.getTexture("mainMenuPlayButton"));
	playButton.setTextureRect(Main_Menu_Red_Start_button);
	playButton.setPosition(window_Width / 2, window_Height/1.7);
	playButton.setOrigin(sf::Vector2f(playButton.getGlobalBounds().width / 2, playButton.getGlobalBounds().height / 2));

	quitButton.setTexture(this->data->assets.getTexture("mainMenuQuitButton"));
	quitButton.setTextureRect(Main_Menu_Red_Quit_button);
	quitButton.setPosition(window_Width / 2, window_Height / 1.23);
	quitButton.setOrigin(sf::Vector2f(quitButton.getGlobalBounds().width / 2, quitButton.getGlobalBounds().height / 2));
	
	background.setTexture(this->data->assets.getTexture("mainMenuBackground"));
}

void MainMenuState::handleInput()
{
	if (playButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->data->window))))
	{
		playButton.setTextureRect(Main_Menu_Blue_Start_button);
		if (this->data->input.isSpriteClicked(playButton, sf::Mouse::Left, this->data->window))
		{
			//Switch to Level_01 Splash Screen
			this->data->machine.addState(stateRef(new SplashScreen(this->data, 1)));
		}
	}
	else playButton.setTextureRect(Main_Menu_Red_Start_button);

	if (quitButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->data->window))))
	{
		quitButton.setTextureRect(Main_Menu_Blue_Quit_button);
		if (this->data->input.isSpriteClicked(quitButton, sf::Mouse::Left, this->data->window))
		{
			//Closing the Game
			this->data->window.close();
		}
	}
	else quitButton.setTextureRect(Main_Menu_Red_Quit_button);
}

void MainMenuState::update()
{
}

void MainMenuState::draw()
{
	this->data->window.clear();
	this->data->window.draw(background);
	this->data->window.draw(title);
	this->data->window.draw(playButton);
	this->data->window.draw(quitButton);
	this->data->window.display();
}