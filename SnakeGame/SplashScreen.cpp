#include"SplashScreen.hpp"
#include"MainMenuState.hpp"
#include"Level_01.hpp"
#include"Level_02.hpp"
#include"Level_03.hpp"

SplashScreen::SplashScreen(GameDataRef data, int splashScreen, float delay) : data(data)
{
	this->splashScreen = splashScreen;
	this->delay = delay;
	timer = 0.0f;
}

SplashScreen::~SplashScreen()
{
}



void SplashScreen::GameStart()
{
	this->data->window.draw(gameStartBackground);
	this->data->window.draw(snake_Animation);
	//this->data->window.draw(game_Start_Text);
}

void SplashScreen::level_01()
{
	this->data->window.draw(level_01_Background);
	//this->data->window.draw(level_01_Text);
}

void SplashScreen::level_02()
{
	this->data->window.draw(level_02_Background);
	//this->data->window.draw(level_02_Text);
}

void SplashScreen::level_03()
{
	this->data->window.draw(level_03_Background);
	//this->data->window.draw(level_03_Text);
}

void SplashScreen::init()
{
	gameStartBackground.setTexture(this->data->assets.getTexture("game_Start_Splash_Screen_Background"));
	snake_Animation.setTexture(this->data->assets.getTexture("snake_Animation"));
	level_01_Background.setTexture(this->data->assets.getTexture("level_01_Splash_Screen_Background"));
	level_02_Background.setTexture(this->data->assets.getTexture("level_02_Splash_Screen_Background"));
	level_03_Background.setTexture(this->data->assets.getTexture("level_03_Splash_Screen_Background"));
	
	snake_Animation_Partition = sf::IntRect(0, 0, 701, 185);
	snakeSlithering = sf::Vector2f(-700, window_Height / 2);
	snake_Animation.setTextureRect(snake_Animation_Partition);
	snake_Animation.setOrigin(sf::Vector2f(0, snake_Animation.getGlobalBounds().height / 2));
	snake_Animation.setPosition(snakeSlithering);

	/*game_Start_Text.setFont(this->data->assets.getFont("font"));
	level_01_Text.setFont(this->data->assets.getFont("font"));
	level_02_Text.setFont(this->data->assets.getFont("font"));
	level_03_Text.setFont(this->data->assets.getFont("font"));

	game_Start_Text.setString("Welcome");
	level_01_Text.setString("Level 1");
	level_02_Text.setString("Level 2");
	level_03_Text.setString("Level 3");

	game_Start_Text.setCharacterSize(100);
	level_01_Text.setCharacterSize(100);
	level_02_Text.setCharacterSize(100);
	level_03_Text.setCharacterSize(100);

	game_Start_Text.setOrigin(sf::Vector2f(game_Start_Text.getGlobalBounds().width / 2, game_Start_Text.getGlobalBounds().height / 2));
	level_01_Text.setOrigin(sf::Vector2f(level_01_Text.getGlobalBounds().width / 2, level_01_Text.getGlobalBounds().height / 2));
	level_02_Text.setOrigin(sf::Vector2f(level_02_Text.getGlobalBounds().width / 2, level_02_Text.getGlobalBounds().height / 2));
	level_03_Text.setOrigin(sf::Vector2f(level_03_Text.getGlobalBounds().width / 2, level_03_Text.getGlobalBounds().height / 2));

	game_Start_Text.setFillColor(sf::Color::Black);
	level_01_Text.setFillColor(sf::Color::Black);
	level_02_Text.setFillColor(sf::Color::Black);
	level_03_Text.setFillColor(sf::Color::Black);

	game_Start_Text.setPosition(sf::Vector2f(window_Width / 2, window_Height / 2));
	level_01_Text.setPosition(sf::Vector2f(window_Width / 2, window_Height / 2));
	level_02_Text.setPosition(sf::Vector2f(window_Width / 2, window_Height / 2));
	level_03_Text.setPosition(sf::Vector2f(window_Width / 2, window_Height / 2));*/

	snakeAnimationSpeed = 0.07f;

	if(splashScreen != 0) this->data->soundEffect.playLevelUpSound();
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


