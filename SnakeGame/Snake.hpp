#pragma once
#include"Defination.hpp"
#include"Game.hpp"
//#include"SoundEffect.hpp"
#include"HighestScore.hpp"

struct SnakeArray
{
	int x;
	int y;
};

class Snake
{
public:
	Snake(GameDataRef data);
	Snake(GameDataRef data, int score);
	~Snake();
	void snakeMovementDirection();
	bool snakeFoodCollision(sf::Vector2f f);
	bool snakeBonusFoodCollision(sf::Vector2f f);
	void snakeMovementDirection_level_01();
	bool snakeWallCollision();
	bool snakeItselfCollision();
	int  returnScore();
	void snakeAnimation();
	void renderScore();
	void render();
private:
	GameDataRef data;
	HighestScore highScore;
	//SoundEffect audio;
	sf::Sprite snakeBody;
	sf::Text scoreText;
	SnakeArray s[500];
	SnakeArray preSegment;
	SnakeArray postSegment;
	int snakeLength;
	int snakeDirection;	
	int score;
};

