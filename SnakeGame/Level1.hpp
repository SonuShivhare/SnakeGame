#pragma once
#include "Defination.hpp"
#include"State.hpp"
//#include"Game.hpp"
#include"Snake.hpp"
#include"Food.hpp"

class Level1 : public State
{
public:
	Level1(GameDataRef data);
	~Level1();

	void init() override;
	void handleInput() override;
	void update() override;
	void draw() override;
private:
	GameDataRef data;
	Snake snake;

	Food food;
	sf::Sprite background;
	sf::Sprite pauseButton;
	sf::Clock clk;
	float timer;
	float delay;
	bool isMouseButtonReleased;
};