#include "Snake.hpp"

Snake::Snake(GameDataRef data) : data(data), audio(data)
{
	this->data->assets.loadTexture("snakeBody", Snake_Segment_FilePath);

	snakeBody.setTexture(this->data->assets.getTexture("snakeBody"));
	snakeBody.setTextureRect(Snake_Body);
	scoreText.setFont(this->data->assets.getFont("font"));
	scoreText.setCharacterSize(30);

	snakeDirection = 4;
	snakeLength = 4;
	s[0].x = 0;
	s[0].y = 0;
	score = 0;
}

Snake::~Snake()
{
}

void Snake::snakeMovementDirection()
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
			s[0].y += 0;
		break;

	case 4: s[0].x += 1;
			s[0].y += 0;
		break;
	}
}

//Score mechanic
/*void Snake::scoreFunc()
{
	scoreText.setString("Score : " + std::to_string(score));
	scoreText.setPosition(sf::Vector2f(window_Width / 2, 4));
	scoreText.setOrigin(sf::Vector2f(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2));
	this->data->window.draw(scoreText);
}*/

int Snake::returnScore()
{
	return score;
}

void Snake::snakeWallCross()
{
	if (s[0].x < 0) s[0].x = xCount - 1;
	if (s[0].y < 0) s[0].y = yCount - 1;
	if (s[0].x >= xCount) s[0].x = 0;
	if (s[0].y >= yCount) s[0].y = 0;
}

bool Snake::snakeFoodCollision(sf::Vector2f f)
{
	if (s[0].x == f.x && s[0].y == f.y)
	{
		audio.playEatingSound();
		score += 10;
		snakeLength ++;
		highScore.storePlayerScore(score);
		return true;
	}
	return false;
}

void Snake::snakeWallCollision(int& gameLevel)
{
	if (s[0].x < 0 || s[0].y < 0) gameLevel = 3;
	if (s[0].x >= xCount || s[0].y >= yCount) gameLevel = 3;
}

void Snake::snakeItselfCollision(int& gameLevel)
{
	for (int i = 1; i < snakeLength; i++)
	{
		if (s[0].x == s[i].x && s[0].y == s[i].y) gameLevel = 3;
	}
}

void Snake::render()
{
	for (int i = 0; i < snakeLength; i++)
	{
		snakeBody.setPosition(sf::Vector2f(s[i].x * size, s[i].y * size));
		this->data->window.draw(snakeBody);
	}

	scoreText.setString("Score : " + std::to_string(score));
	scoreText.setPosition(sf::Vector2f(window_Width / 2, 4));
	scoreText.setOrigin(sf::Vector2f(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2));
	this->data->window.draw(scoreText);
}