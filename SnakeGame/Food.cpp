#include "Food.hpp"

Food::Food(GameDataRef data) : data(data)
{
	this->data->assets.loadTexture("food", Food_FilePath);
	food.setTexture(this->data->assets.getTexture("food"));

	srand(time(NULL));
	foodGen();
}

Food::~Food()
{
}

//random Genration of food
void Food::foodGen()
{
	f.x = rand() % xCount;
	f.y = rand() % yCount;
	food.setPosition(sf::Vector2f(f.x * size, f.y * size));
}

//returns the food position
sf::Vector2f Food::foodPos()
{
	return sf::Vector2f(f.x, f.y);
}

void Food::render()
{	
	this->data->window.draw(food);
}