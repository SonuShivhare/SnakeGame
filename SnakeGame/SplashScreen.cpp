#include"SplashScreen.hpp"
#include"MainMenuState.hpp"
#include"Level_01.hpp"
#include"Level_02.hpp"
#include"Level_03.hpp"

SplashScreen::SplashScreen(GameDataRef data, int splashScreen, float delay) : data(data)
{
	this->splashScreen = splashScreen;
	this->delay = delay;
	this->timer = 0.0f;
	this->timer2 = 0.0f;
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::GameStart()
{
	this->data->window.draw(gameStartBackground);
	this->data->window.draw(snake_Animation);
}

void SplashScreen::level_01()
{
	this->data->window.draw(level_01_Background);
}

void SplashScreen::level_02()
{
	this->data->window.draw(level_02_Background);
}

void SplashScreen::level_03()
{
	this->data->window.draw(level_03_Background);
}

void SplashScreen::init()
{
	gameStartBackground.setTexture(this->data->assets.getTexture("game_Start_Splash_Screen_Background"));
	level_01_Background.setTexture(this->data->assets.getTexture("level_01_Splash_Screen_Background"));
	level_02_Background.setTexture(this->data->assets.getTexture("level_02_Splash_Screen_Background"));
	level_03_Background.setTexture(this->data->assets.getTexture("level_03_Splash_Screen_Background"));
	snake_Animation.setTexture(this->data->assets.getTexture("snake_Animation"));
	
	snake_Animation_Partition = sf::IntRect(0, 0, 701, 185);
	snakeSlithering = sf::Vector2f(-700, window_Height / 2);
	snake_Animation.setTextureRect(snake_Animation_Partition);
	snake_Animation.setOrigin(sf::Vector2f(0, snake_Animation.getGlobalBounds().height / 2));
	snake_Animation.setPosition(snakeSlithering);

	snakeAnimationSpeed = 0.07f;

	//if(splashScreen != 0) this->data->soundEffect.playLevelUpSound();
}

void SplashScreen::handleInput()
{
}

void SplashScreen::update()
{
	timePerFrame = clk.restart().asSeconds();
	timer += timePerFrame;
	timer2 += timePerFrame;

	snakeSlithering.x += 11;
	snake_Animation.setPosition(snakeSlithering);

	if (timer2 > snakeAnimationSpeed)
	{
		timer2 = 0;

		if (snake_Animation_Partition.top != 6290)	snake_Animation_Partition.top += 185;
		else snake_Animation_Partition.top = 0;

		snake_Animation.setTextureRect(snake_Animation_Partition);
	}

	if (timer > delay)
	{
		switch (splashScreen)
		{
		case 0: this->data->machine.addState(stateRef(new MainMenuState(this->data)));
			break;
		case 1: this->data->machine.addState(stateRef(new Level_01(this->data)));
			break;
		case 2: this->data->machine.addState(stateRef(new Level_02(this->data, highScore.returnPlayerScore())));
			break;
		case 3: this->data->machine.addState(stateRef(new Level_03(this->data, highScore.returnPlayerScore())));
			break;
		}
	}
}

void SplashScreen::draw()
{
	this->data->window.clear();

	switch (splashScreen)
	{
	case 0: GameStart();
		break;
	case 1: level_01();
		break;
	case 2: level_02();
		break;
	case 3: level_03();
		break;
	}

	this->data->window.display();
}


