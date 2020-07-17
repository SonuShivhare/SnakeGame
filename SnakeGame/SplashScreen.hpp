#pragma once
#include"Defination.hpp"
#include"State.hpp"
#include"Game.hpp"
#include"HighestScore.hpp"

class SplashScreen : public State
{
public:
	SplashScreen(GameDataRef data, int splashScreen, float delay = 3.0f);
	~SplashScreen();

	void GameStart();
	void level_01();
	void level_02();
	void level_03();

	void init() override;
	void handleInput() override;
	void update() override;
	void draw() override;
private:
	GameDataRef data;
	HighestScore highScore;

	sf::Sprite gameStartBackground;
	sf::Sprite level_01_Background;
	sf::Sprite level_02_Background;
	sf::Sprite level_03_Background;

	sf::Sprite snake_Animation;
	sf::IntRect snake_Animation_Partition;
	sf::Vector2f snakeSlithering;

	sf::Clock clk;
	float timePerFrame;
	float timer;
	float timer2;
	float delay;
	float snakeAnimationSpeed;

	int splashScreen;
};

