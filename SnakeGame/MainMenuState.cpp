#include "MainMenuState.hpp"
#include "GameOverState.hpp"

MainMenuState::MainMenuState(GameDataRef data) : data(data)
{
	gameTitlePartition = sf::IntRect(0, 0, 900, 126);
	timer = 0;
	delay = Snake_Game_Title_Speed;
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::init()
{
	data->assets.loadTexture("background", Common_Background);
	data->assets.loadTexture("mainMenuBackground", Main_Menu_Background);
	this->data->assets.loadFont("font", Font_FilePath);
	this->data->assets.loadFont("arialfont", Arial_Font_FilePath);

	data->assets.loadTexture("title", Game_Title);
	title.setTexture(this->data->assets.getTexture("title"));
	//title.setTextureRect(gameTitlePartition);
	title.setPosition(window_Width / 2, window_Height/4);
	title.setOrigin(sf::Vector2f(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2));

	data->assets.loadTexture("playButton", Play_Button);
	data->assets.loadTexture("homeButton", Home_Button);
	data->assets.loadTexture("quitButton", Quit_Button);
	data->assets.loadTexture("mainMenuPlayButton", Main_Manu_Play_Button);
	data->assets.loadTexture("mainMenuQlayButton", Main_Manu_Quit_Button);

	background.setTexture(this->data->assets.getTexture("mainMenuBackground"));
	
	playButton.setTexture(this->data->assets.getTexture("mainMenuPlayButton"));
	playButton.setTextureRect(Main_Menu_Red_Start_button);
	playButton.setPosition(window_Width / 2, window_Height/1.7);
	playButton.setOrigin(sf::Vector2f(playButton.getGlobalBounds().width / 2, playButton.getGlobalBounds().height / 2));

	quitButton.setTexture(this->data->assets.getTexture("mainMenuQlayButton"));
	quitButton.setTextureRect(Main_Menu_Red_Quit_button);
	quitButton.setPosition(window_Width / 2, window_Height / 1.23);
	quitButton.setOrigin(sf::Vector2f(quitButton.getGlobalBounds().width / 2, quitButton.getGlobalBounds().height / 2));
}

void MainMenuState::handleInput()
{
	timer += clk.restart().asSeconds();
	if (playButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->data->window))))
	{
		playButton.setTextureRect(Main_Menu_Blue_Start_button);
		if (this->data->input.isSpriteClicked(playButton, sf::Mouse::Left, this->data->window))
		{
			//Switch to Level1
			this->data->machine.addState(stateRef(new Level1(this->data)));
			//this->data->machine.addState(stateRef(new GameOverState(this->data)));
		}
	}
	else playButton.setTextureRect(Main_Menu_Red_Start_button);

	if (quitButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->data->window))))
	{
		quitButton.setTextureRect(Main_Menu_Blue_Quit_button);
		if (this->data->input.isSpriteClicked(quitButton, sf::Mouse::Left, this->data->window))
		{
			//switch to Starting Level_01
			this->data->window.close();
		}
	}
	else quitButton.setTextureRect(Main_Menu_Red_Quit_button);
}

void MainMenuState::update()
{
	/*if (timer > delay)
	{
		timer = 0;
		if (gameTitlePartition.top == 378) gameTitlePartition.top = 0;
		else gameTitlePartition.top += 126;
		title.setTextureRect(gameTitlePartition);
	}*/
	
}

void MainMenuState::draw()
{
	this->data->window.clear();
	/*for (int i = 0; i < yCount; i+=1)
	{
		for (int j = 0; j < xCount; j+=1)
		{
			background.setTexture(this->data->assets.getTexture("mainMenuBackground"));
			background.setPosition(j * size, i * size);
			this->data->window.draw(background);
		}
	}*/
	this->data->window.draw(background);
	this->data->window.draw(title);
	this->data->window.draw(playButton);
	this->data->window.draw(quitButton);
	this->data->window.display();
}