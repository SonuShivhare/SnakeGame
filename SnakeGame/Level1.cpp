#include "Level1.hpp"
#include"GameOverState.hpp"
#include"PauseState.hpp"

Level1::Level1(GameDataRef data) : data(data), snake(data), food(data)
{
	data->assets.loadTexture("level_01_Background", Level1_Background);
	//background.setTexture(this->data->assets.getTexture("level_01_Background"));
	data->assets.loadTexture("pauseButton", Pause_Button);

	pauseButton.setTexture(this->data->assets.getTexture("pauseButton"));
	pauseButton.setTextureRect(Blue_button);
	pauseButton.setPosition(0, 0); //(window_Width / 2, window_Height / 3);
	//pauseButton.setOrigin(sf::Vector2f(pauseButton.getGlobalBounds().width / 2, pauseButton.getGlobalBounds().height / 2));

	food.foodGen();
	timer = 0.0f;
	delay = 0.1f;
	isMouseButtonReleased = false;
}

Level1::~Level1()
{
}

void Level1::init()
{

}

void Level1::handleInput()
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
			this->data->machine.addState(stateRef(new PauseState(this -> data)), false);
		}
	}
	else pauseButton.setTextureRect(Blue_button);
}

void Level1::update()
{
	if (snake.snakeFoodCollision(food.foodPos())) food.foodGen();
	snake.snakeWallCross();
	if (snake.returnScore() >= 4000)
	{
		this->data->machine.addState(stateRef(new GameOverState(this->data)));
	}
}

void Level1::draw()
{
	this->data->window.clear();
	for (int i = 0; i < yCount; i += 1)
	{
		for (int j = 0; j < xCount; j += 1)
		{
			background.setTexture(this->data->assets.getTexture("level_01_Background"));
			background.setPosition(j * size, i * size);
			this->data->window.draw(background);
		}
	}
	//this->data->window.draw(background);
	this->data->window.draw(pauseButton);
	snake.render();
	food.render();
	this->data->window.display();
}