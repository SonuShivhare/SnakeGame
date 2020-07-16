#include "Food.hpp"

Food::Food(GameDataRef data) : data(data)
{
	food.setTexture(this->data->assets.getTexture("food"));
	bonusFood.setTexture(this->data->assets.getTexture("bonusFood"));
	bf.x = Bonus_Food_Initial_X_Position;
	bf.y = Bonus_Food_Initial_Y_Position;
	bonusFood.setPosition(sf::Vector2f(bf.x * size, bf.y * size));
	srand(time(NULL));
	foodGen();
	//bonusFoodGen();
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

void Food::bonusFoodGen()
{
	do
	{
		bf.x = (rand() % (xCount - 2)) + 1;
		bf.y = (rand() % (yCount - 2)) + 1;
	}
	while (bf.x == f.x && bf.y == f.y);

	bonusFood.setPosition(sf::Vector2f(bf.x * size, bf.y * size));
}

sf::Vector2f Food::foodPos()
{
	return sf::Vector2f(f.x, f.y);
}

sf::Vector2f Food::bonusFoodPos()
{
	return sf::Vector2f(bf.x, bf.y);
}

void Food::bonusFoodDisappear()
{
	bf.x = Bonus_Food_Initial_X_Position;
	bf.y = Bonus_Food_Initial_Y_Position;
	bonusFood.setPosition(sf::Vector2f(bf.x * size, bf.y * size));
}

void Food::render()
{	
	this->data->window.draw(food);
	this->data->window.draw(bonusFood);
}