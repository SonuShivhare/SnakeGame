#include "Snake.hpp"

Snake::Snake()
{
	snakeBody_t.loadFromFile("Assets/images/red.png");
	snakeBody.setTexture(snakeBody_t);
	snakeDirection = 4;
	snakeLength = 4;
	s[0].x = 0;
	s[0].y = 0;

	//Related Score mechanic
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	scoreText.setFont(font);
	scoreText.setCharacterSize(30);
	score = 0;
}

Snake::~Snake()
{
}

void Snake::snakeMovement(float dt)
{
	//Switching Snake segments in array
	for (int i = snakeLength; i > 0; i--)
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}

	//setting the direction
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (snakeDirection == 2) snakeDirection == 2;
		else snakeDirection = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (snakeDirection == 1) snakeDirection == 1;
		else snakeDirection = 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (snakeDirection == 4) snakeDirection == 4;
		else snakeDirection = 3;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (snakeDirection == 3) snakeDirection == 3;
		else snakeDirection = 4;
	}

	//moving the snake based on it's direction
	switch (snakeDirection)
	{
	case 1: s[0].x += 0;
			s[0].y += -1;
			break;

	case 2: s[0].x += 0;
			s[0].y += 1;
			break;

	case 3: s[0].x += -1;
			s[0].y += 0 ;
			break;

	case 4: s[0].x += 1;
			s[0].y += 0;
			break;
	}
}

//Score mechanic
void Snake::scoreFunc(sf::RenderWindow& window)
{
	scoreText.setString("Score : " + std::to_string(score));
	scoreText.setPosition(sf::Vector2f(windowWidth / 2, 4));
	scoreText.setOrigin(sf::Vector2f(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2));
	window.draw(scoreText);
}

int Snake::scoreReturn()
{
	return score;
}

bool Snake::snakeFoodCollision(sf::Vector2f f)
{
	if (s[0].x == f.x && s[0].y == f.y)
	{
		score += 1;
		snakeLength++;
		return true;
	}
	return false;
}

void Snake::snakeWallCollision(sf::RenderWindow& window, int& gameLevel)
{
	if (s[0].x < 0 || s[0].y < 0) gameLevel = 3;
	if (s[0].x >= xCount || s[0].y >= yCount) gameLevel = 3;
}

void Snake::snakeItselfCollision(sf::RenderWindow& window, int& gameLevel)
{
	for (int i = 1; i < snakeLength; i++)
	{
		if (s[0].x == s[i].x && s[0].y == s[i].y) gameLevel = 3;
	}
}

void Snake::render(sf::RenderWindow& window)
{
	for (int i = 0; i < snakeLength; i++)
	{
		snakeBody.setPosition(sf::Vector2f(s[i].x * size, s[i].y * size));
		window.draw(snakeBody);
	}	
}
