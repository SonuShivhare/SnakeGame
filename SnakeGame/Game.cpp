#include "Game.hpp"
#include"SplashScreen.hpp"
#include "MainMenuState.hpp"

Game::Game()
{
	this->data->window.create(sf::VideoMode(window_Width, window_Height), "-Snake Game-");
	this->data->window.setFramerateLimit(60);
	loadFiles();

	//switch to starting Splash Screen
	this->data->machine.addState(stateRef(new MainMenuState(this->data)));

	this->run();
}

Game::~Game()
{
}

void Game::loadFiles()
{
	this->data->assets.loadTexture("title", Game_Title);
	this->data->assets.loadTexture("mainMenuPlayButton", Main_Manu_Play_Button);
	this->data->assets.loadTexture("mainMenuQuitButton", Main_Manu_Quit_Button);
	this->data->assets.loadTexture("mainMenuBackground", Main_Menu_Background);
	this->data->assets.loadTexture("playButton", Play_Button);
	this->data->assets.loadTexture("homeButton", Home_Button);
	this->data->assets.loadTexture("quitButton", Quit_Button);
	this->data->assets.loadTexture("pauseButton", Pause_Button);
	this->data->assets.loadTexture("levelPauseButton", Level_Pause_Button);
	this->data->assets.loadTexture("food", Food_FilePath);
	this->data->assets.loadTexture("bonusFood", Bonus_Food_FilePath);
	this->data->assets.loadTexture("background", Common_Background);
	this->data->assets.loadTexture("levels_background", Level_Common_Grass_Background);
	this->data->assets.loadTexture("level_01_Border", Level_01_Grass_Border_FilePath);
	this->data->assets.loadTexture("level_02_Border", Level_02_Stone_Border_FilePath);
	this->data->assets.loadTexture("level_03_Border", Level_03_Grass_Stone_Border_FilePath);
	this->data->assets.loadTexture("level_01_Splash_Screen_Background", Level_01_Splash_Screen_Background_FilePath);
	this->data->assets.loadTexture("level_02_Splash_Screen_Background", Level_02_Splash_Screen_Background_FilePath);
	this->data->assets.loadTexture("level_03_Splash_Screen_Background", Level_03_Splash_Screen_Background_FilePath);
	this->data->assets.loadTexture("gameOverBackground", GameOver_Background);
	this->data->assets.loadFont("font", Font_FilePath);
	this->data->assets.loadFont("arialfont", Arial_Font_FilePath);
	this->data->assets.loadTexture("snakeBody", Snake_Segment_FilePath);
}

void Game::run()
{
	//Game-Loop
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