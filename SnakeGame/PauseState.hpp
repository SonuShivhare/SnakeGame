#pragma once
#include"Defination.hpp"
#include"State.hpp"
#include"Game.hpp"

class PauseState : public State
{
public:
	PauseState(GameDataRef data);
	~PauseState();

	void init() override;
	void handleInput() override;
	void update() override;
	void draw() override;
private:
	GameDataRef data;
	sf::Sprite background;
	sf::Sprite playButton;
	sf::Sprite homeButton;
	bool isMouseButtonReleased;
};

