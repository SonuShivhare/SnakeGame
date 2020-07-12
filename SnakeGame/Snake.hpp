#pragma once
#include"Defination.hpp"
#include"Game.hpp"
#include"SoundEffect.hpp"
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
	~Snake();
	void snakeMovementDirection();
	//void scoreFunc();
	int returnScore();
	void snakeWallCross();
	bool snakeFoodCollision(sf::Vector2f f);
	void snakeWallCollision(int& gameLevel);
	void snakeItselfCollision(int& gameLevel);
	void render();
private:
	GameDataRef data;
	HighestScore highScore;

	SoundEffect audio;
	sf::Sprite snakeBody;
	sf::Sprite background;
	sf::Text scoreText;
	SnakeArray s[500];
	int snakeLength;
	int snakeDirection;	
	int score;
};

