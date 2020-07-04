#pragma once
#include "Defs.hpp"
#include "Snake.hpp"
#include "Food.hpp"
#include "StartWindow.hpp"
#include "EndWindow.hpp"

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	sf::RenderWindow window;
	sf::Texture background_t;
	sf::Sprite background;
	sf::Clock clk;
	float dt;
	float timer;
	float delay;
	Snake snake;
	Food food;

	StartWindow startWindow;
	EndWindow endWindow;
	int gameLevel;
};

