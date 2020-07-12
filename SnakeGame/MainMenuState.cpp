#include "MainMenuState.hpp"
#include"Level_01.hpp"
#include"Level_02.hpp"

MainMenuState::MainMenuState(GameDataRef data) : data(data)
{
	loadFiles();
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::loadFiles()
{
	data->assets.loadTexture("title", Game_Title);
	data->assets.loadTexture("playButton", Play_Button);
	data->assets.loadTexture("homeButton", Home_Button);
	data->assets.loadTexture("quitButton", Quit_Button);
	this->data->assets.loadTexture("food", Food_FilePath);
	data->assets.loadTexture("background", Common_Background); 
	data->assets.loadTexture("level_01_WallBorder", Level_01_Wall_Border_FilePath);
	data->assets.loadTexture("level_02_WallBorder", Level_02_Wall_Border_FilePath);
	data->assets.loadTexture("level_03_WallBorder", Level_03_Wall_Border_FilePath);
	data->assets.loadTexture("mainMenuPlayButton", Main_Manu_Play_Button);
	data->assets.loadTexture("mainMenuQlayButton", Main_Manu_Quit_Button);
	data->assets.loadTexture("mainMenuBackground", Main_Menu_Background);
	this->data->assets.loadFont("font", Font_FilePath);
	this->data->assets.loadFont("arialfont", Arial_Font_FilePath);
	this->data->assets.loadTexture("snakeBody", Snake_Segment_FilePath);
	//this->data->assets.loadSound("eatingSound", Eating_Sound_FilePath);
	data->assets.loadTexture("level_01_Background", Level1_Background);
	data->assets.loadTexture("pauseButton", Pause_Button);
	data->assets.loadTexture("gameOverBackground", GameOver_Background);
}

void MainMenuState::init()
{
	title.setTexture(this->data->assets.getTexture("title"));
	//title.setTextureRect(gameTitlePartition);
	title.setPosition(window_Width / 2, window_Height/4);
	title.setOrigin(sf::Vector2f(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2));

	playButton.setTexture(this->data->assets.getTexture("mainMenuPlayButton"));
	playButton.setTextureRect(Main_Menu_Red_Start_button);
	playButton.setPosition(window_Width / 2, window_Height/1.7);
	playButton.setOrigin(sf::Vector2f(playButton.getGlobalBounds().width / 2, playButton.getGlobalBounds().height / 2));

	quitButton.setTexture(this->data->assets.getTexture("mainMenuQlayButton"));
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
			//Switch to Level_01
			this->data->machine.addState(stateRef(new Level_01(this->data)));
			//this->data->machine.addState(stateRef(new Level_02(this->data)));
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