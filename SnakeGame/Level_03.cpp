#include "Level_03.hpp"
#include"PauseState.hpp"
#include"GameOverState.hpp"


Level_03::Level_03(GameDataRef data, int score) : data(data), snake(data, score), food(data)
{

}

Level_03::~Level_03()
{
}

void Level_03::init()
{
	background02.setTexture(this->data->assets.getTexture("level_03_WallBorder"));
	background.setTexture(this->data->assets.getTexture("level_01_Background"));

	pauseButton.setTexture(this->data->assets.getTexture("pauseButton"));
	pauseButton.setTextureRect(Blue_button);
	pauseButton.setPosition(0, 0); //(window_Width / 2, window_Height / 3);
	//pauseButton.setOrigin(sf::Vector2f(pauseButton.getGlobalBounds().width / 2, pauseButton.getGlobalBounds().height / 2));

	timer = 0.0f;
	delay = Snake_Speed / 1.5;
	isMouseButtonReleased = false;
}

void Level_03::handleInput()
{
	timer += clk.restart().asSeconds();
	if (timer > delay)
	{
		timer = 0;
		snake.snakeMovementDirection();
	}

	if (pauseButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->data->window))))
	{
		pauseButton.setTextureRect(Green_button);
		if (this->data->input.isSpriteClicked(pauseButton, sf::Mouse::Left, this->data->window))
		{
			pauseButton.setTextureRect(Yellow_button);
			isMouseButtonReleased = true;
		}
		else if (isMouseButtonReleased && !this->data->input.isSpriteClicked(pauseButton, sf::Mouse::Left, this->data->window))
		{
			//switch to Starting Level_01
			isMouseButtonReleased = false;
			this->data->machine.addState(stateRef(new PauseState(this->data)), false);
		}
	}
	else pauseButton.setTextureRect(Blue_button);
}

void Level_03::update()
{
	if (snake.snakeFoodCollision(food.foodPos())) food.foodGen();
	if (snake.snakeWallCollision()) this->data->machine.addState(stateRef(new GameOverState(this->data)));
	if (snake.snakeItselfCollision()) this->data->machine.addState(stateRef(new GameOverState(this->data)));
	//snake.snakeWallCross();
}

void Level_03::draw()
{
	this->data->window.clear();
	for (int i = 1; i <= yCount - 2; i += 1)
	{
		for (int j = 1; j <= xCount - 2; j += 1)
		{
			background.setPosition(j * size, i * size);
			this->data->window.draw(background);
		}
	}

	for (int i = 0; i <= yCount - 1; i += 1)
	{
		for (int j = 0; j <= xCount - 1; j += 1)
		{
			if (i == 0 || j == 0 || i == yCount - 1 || j == xCount - 1)
			{
				background02.setPosition(j * size, i * size);
				this->data->window.draw(background02);
			}
		}
	}

	this->data->window.draw(pauseButton);
	snake.render();
	food.render();
	this->data->window.display();
}