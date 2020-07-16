#pragma once
#include"Defination.hpp"
#include"State.hpp"
#include"Game.hpp"



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
};

