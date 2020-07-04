#include "Game.hpp"
#include<iostream>
#include<iomanip>

Game::Game()
{
	window.create(sf::VideoMode(windowWidth, windowHeight), "Snake Game");
	window.setFramerateLimit(60);
	background_t.loadFromFile("Assets/images/background.png");
	background.setTexture(background_t);
	timer = 0;
	delay = 0.1;
	gameLevel = 1;
}

Game::~Game()
{
}

void Game::run()
{
	//Game Loop
	while (window.isOpen())
	{
		dt = clk.restart().asSeconds();
		timer += dt;
		//inputs
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed) window.close();
		}

		//Swiching Between Game windows
		if (gameLevel == 1)
		{
			startWindow.render(window, gameLevel);
		}
		else if (gameLevel == 2)
		{
			//updates
			if (timer > delay) 
			{ 
				timer = 0; 
				snake.snakeMovement(dt);
			}
			if (snake.snakeFoodCollision(food.foodPos())) food.foodGen();
			snake.snakeWallCollision(window, gameLevel);
			snake.snakeItselfCollision(window, gameLevel);
		
			//render
			window.clear();
			window.draw(background);
			food.render(window);
			snake.render(window);
			snake.scoreFunc(window);
			window.display();
		}
		else if (gameLevel == 3)
		{
			endWindow.render(window, gameLevel, snake.scoreReturn());
		}
	}
}
