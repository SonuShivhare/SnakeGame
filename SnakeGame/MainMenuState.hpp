#pragma once
#include"Defination.hpp"
#include"State.hpp"
#include"Game.hpp"
#include"Level1.hpp"



class MainMenuState : public State
{
public:
	MainMenuState(GameDataRef data);
	~MainMenuState(); 

	void init() override;
	void handleInput() override;
	void update() override;
	void draw() override;
private:
	GameDataRef data;
	sf::Sprite background;
	sf::Sprite playButton;
	sf::Sprite quitButton;
	sf::Sprite title;
	sf::IntRect gameTitlePartition;
	sf::Clock clk;
	float timer;
	float delay;
};

