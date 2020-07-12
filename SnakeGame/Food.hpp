#pragma once
#include"Defination.hpp"
#include"Game.hpp"

struct foodArray
{
	int x;
	int y;
};

class Food
{
public:
	Food(GameDataRef data);
	~Food();

	sf::Vector2f foodPos();
	void foodGen();	
	void render();
private:
	GameDataRef data;
	foodArray f;
	sf::Sprite food;	
};

