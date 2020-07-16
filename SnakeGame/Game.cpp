#include "Game.hpp"
#include"MainMenuState.hpp"
#include "SoundEffect.hpp"
#include"SplashScreen.hpp"

Game::Game()
{
	this->data->window.create(sf::VideoMode(window_Width, window_Height), "-Snake Game-");
	this->data->window.setFramerateLimit(60);
	loadFiles();

	//switch to Starting State
	//this->data->machine.addState(stateRef(new MainMenuState(this->data)));
	this->data->machine.addState(stateRef(new SplashScreen(this->data, 0, 3.0)));

	this->run();
}

Game::~Game()
{
}

void Game::loadFiles()
{
	data->assets.loadTexture("title", Game_Title);
	data->assets.loadTexture("playButton", Play_Button);
	data->assets.loadTexture("homeButton", Home_Button);
	data->assets.loadTexture("quitButton", Quit_Button);
	this->data->assets.loadTexture("food", Food_FilePath);
	this->data->assets.loadTexture("bonusFood", Bonus_Food_FilePath);
	data->assets.loadTexture("background", Common_Background);
	data->assets.loadTexture("level_01_WallBorder", Level_01_Wall_Border_FilePath);
	data->assets.loadTexture("level_02_WallBorder", Level_02_Wall_Border_FilePath);
	data->assets.loadTexture("level_03_WallBorder", Level_03_Wall_Border_FilePath);
	data->assets.loadTexture("level_01_Background", Level_01_Background_FilePath);
	data->assets.loadTexture("level_02_Background", Level_02_Background_FilePath);
	data->assets.loadTexture("level_03_Background", Level_03_Background_FilePath);
	data->assets.loadTexture("game_Start_Splash_Screen_Background", Game_Starting_Splash_Screen_Background_FilePath);
	data->assets.loadTexture("snake_Animation", Game_Starting_Splash_Screen_Snake_Animation_FilePath);
	data->assets.loadTexture("level_01_Splash_Screen_Background", Level_01_Splash_Screen_Background_FilePath);
	data->assets.loadTexture("level_02_Splash_Screen_Background", Level_02_Splash_Screen_Background_FilePath);
	data->assets.loadTexture("level_03_Splash_Screen_Background", Level_03_Splash_Screen_Background_FilePath);
	data->assets.loadTexture("mainMenuPlayButton", Main_Manu_Play_Button);
	data->assets.loadTexture("mainMenuQlayButton", Main_Manu_Quit_Button);
	data->assets.loadTexture("mainMenuBackground", Main_Menu_Background);
	this->data->assets.loadFont("font", Font_FilePath);
	this->data->assets.loadFont("arialfont", Arial_Font_FilePath);
	this->data->assets.loadTexture("snakeBody", Snake_Segment_FilePath);
	//this->data->assets.loadSound("eatingSound", Eating_Sound_FilePath);
	data->assets.loadTexture("pauseButton", Pause_Button);
	data->assets.loadTexture("levelPauseButton", Level_Pause_Button);
	data->assets.loadTexture("gameOverBackground", GameOver_Background);
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