#include "Level_01.hpp"
#include"PauseState.hpp"
#include"SplashScreen.hpp"

Level_01::Level_01(GameDataRef data) : data(data), snake(data), food(data)
{
	
}

Level_01::~Level_01()
{
}

void Level_01::init()
{
	background.setTexture(this->data->assets.getTexture("level_01_Background"));
	backgroundWall.setTexture(this->data->assets.getTexture("level_01_Border"));


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

void Level_01::handleInput()
{
	timePerFrame = clk.restart().asSeconds();
	timer += timePerFrame;
	BounusFoodTimer += timePerFrame;

	if (timer > delay)
	{
		timer = 0;
		snake.snakeMovementDirection_level_01();
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

void Level_01::update()
{
	if (snake.snakeFoodCollision(food.foodPos())) food.foodGen();
	if(snake.snakeBonusFoodCollision(food.bonusFoodPos())) food.bonusFoodDisappear();
	if (snake.returnScore() >= 50)
	{
	
		this->data->machine.addState(stateRef(new SplashScreen(this->data, 2)));
	}

	if (BounusFoodTimer > BounsFoodDelay)
	{
		BounusFoodTimer = 0;
		food.bonusFoodGen();
	}

	if (BounusFoodTimer > Bonus_Food_Duration_Level_01)
	{
		food.bonusFoodDisappear();
	}
}

void Level_01::draw()
{
	this->data->window.clear();
	this->data->window.draw(background);
	snake.render();
	this->data->window.draw(backgroundWall);
	snake.renderScore();
	this->data->window.draw(pauseButton);
	food.render();
	this->data->window.display();
}

