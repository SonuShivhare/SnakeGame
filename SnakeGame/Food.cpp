#include "Food.hpp"

Food::Food(GameDataRef data) : data(data)
{
	food.setTexture(this->data->assets.getTexture("food"));
	srand(time(NULL));
	foodGen();
}

Food::~Food()
{
}

void Food::foodGen()
{
	f.x = (rand() % (xCount - 2)) + 1;
	f.y = (rand() % (yCount - 2)) + 1;
	food.setPosition(sf::Vector2f(f.x * size, f.y * size));
}

sf::Vector2f Food::foodPos()
{
	return sf::Vector2f(f.x, f.y);
}

void Food::render()
{	
	this->data->window.draw(food);
}