#include "Food.hpp"

Food::Food()
{
	food_t.loadFromFile( "Assets/images/red.png" );
	food.setTexture(food_t);
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
}

//returns the food position
sf::Vector2f Food::foodPos()
{
	return sf::Vector2f(f.x, f.y);
}

void Food::render(sf::RenderWindow& window)
{
	food.setPosition(sf::Vector2f(f.x * size, f.y * size));
	window.draw(food);
}
