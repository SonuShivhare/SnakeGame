#pragma once
#include "Defs.hpp"

struct foodArray
{
	int x;
	int y;
};

class Food
{
public:
	Food();
	~Food();
	void foodGen();
	sf::Vector2f foodPos();
	void render(sf::RenderWindow& window);
private:
	sf::Texture food_t;
	sf::Sprite food;
	foodArray f;
};

