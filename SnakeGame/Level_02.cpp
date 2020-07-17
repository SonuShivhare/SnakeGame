#include "Level_02.hpp"
#include"SplashScreen.hpp"
#include "PauseState.hpp"
#include "GameOverState.hpp"

Level_02::Level_02(GameDataRef data, int score) : data(data), snake(data, score), food(data)
{
	
}

Level_02::~Level_02()
{
}

void Level_02::init()
{
	background.setTexture(this->data->assets.getTexture("level_background"));
	pauseButton.setTexture(this->data->assets.getTexture("levelPauseButton"));
	pauseButton.setTextureRect(Level_Blue_button);
	pauseButton.setPosition(0, 0);

	timePerFrame = 0;
	timer = 0.0f;
	delay = Snake_Speed;
	BounusFoodTimer = Bonus_Food_Duration_Level_01;
	BounsFoodDelay = Bonus_Food_Generation_Speed + Bonus_Food_Duration_Level_01;
	isMouseButtonReleased = false;
}

void Level_02::handleInput()
{
	timePerFrame = clk.restart().asSeconds();
	timer += timePerFrame;
	BounusFoodTimer += timePerFrame;

	if (timer > delay)
	{
		timer = 0;
		snake.snakeMovementDirection();
	}

	if (pauseButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->data->window))))
	{
		pauseButton.setTextureRect(Level_Green_button);
		if (this->data->input.isSpriteClicked(pauseButton, sf::Mouse::Left, this->data->window))
		{
			pauseButton.setTextureRect(Level_Yellow_button);
			isMouseButtonReleased = true;
		}
		else if (isMouseButtonReleased)
		{
			//switch to Starting Level_01
			isMouseButtonReleased = false;
			this->data->machine.addState(stateRef(new PauseState(this -> data)), false);
		}
	}
	else pauseButton.setTextureRect(Level_Blue_button);
}

void Level_02::update()
{
	if (snake.snakeFoodCollision(food.foodPos())) food.foodGen();
	if (snake.snakeBonusFoodCollision(food.bonusFoodPos())) food.bonusFoodDisappear();
	if(snake.snakeWallCollision()) this->data->machine.addState(stateRef(new GameOverState(this->data)));
	if (snake.returnScore() >= 100)
	{
		this->data->machine.addState(stateRef(new SplashScreen(this->data, 3)));
	}

	if (BounusFoodTimer > BounsFoodDelay)
	{
		BounusFoodTimer = 0;
		food.bonusFoodGen();
	}

	if (BounusFoodTimer > Bonus_Food_Duration_Level_02)
	{
		food.bonusFoodDisappear();
	}
}

void Level_02::draw()
{
	this->data->window.clear();
	this->data->window.draw(background);
	this->data->window.draw(pauseButton);
	snake.render();
	food.render();
	this->data->window.display();
}

