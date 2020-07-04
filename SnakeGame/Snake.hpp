#pragma once
#include "Defs.hpp"

struct SnakeArray
{
	int x;
	int y;
};

class Snake
{
public:
	Snake();
	~Snake();
	void snakeMovement(float dt);
	void scoreFunc(sf::RenderWindow& window);
	int scoreReturn();
	bool snakeFoodCollision(sf::Vector2f f);
	void snakeWallCollision(sf::RenderWindow& window, int& gameLevel);
	void snakeItselfCollision(sf::RenderWindow& window, int& gameLevel);
	void render(sf::RenderWindow& window);
private:
	sf::Texture snakeBody_t;
	sf::Sprite snakeBody;
	int snakeLength;
	int snakeDirection;
	SnakeArray s[100];

	//for Score
	sf::Font font;
	sf::Text scoreText;
	int score;
};

