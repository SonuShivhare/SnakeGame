#pragma once
#include"Defination.hpp"
#include"Game.hpp"


struct foodArray
{
	int x;
	int y;
};

struct bonusFood
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
	sf::Vector2f bonusFoodPos();
	void bonusFoodDisappear();
	void foodGen();
	void bonusFoodGen();
	void render();
private:
	GameDataRef data;
	foodArray f;
	bonusFood bf;
	sf::Sprite food;
	sf::Sprite bonusFood;
};

