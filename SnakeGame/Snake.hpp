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
	void snakeWallCross();
	bool snakeWallCollision();
	bool snakeItselfCollision();
	int  returnScore();
	void render();
private:
	GameDataRef data;
	HighestScore highScore;
	//SoundEffect audio;
	sf::Sprite snakeBody;
	sf::Text scoreText;
	SnakeArray s[500];
	int snakeLength;
	int snakeDirection;	
	int score;
};

