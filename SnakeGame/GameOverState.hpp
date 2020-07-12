#pragma once
#include"Defination.hpp"
#include"Game.hpp"
#include"State.hpp"
#include"HighestScore.hpp"

class GameOverState : public State
{
public:
	GameOverState(GameDataRef data);
	~GameOverState();

	void init() override;
	void handleInput() override;
	void update() override;
	void draw() override;
private:
	GameDataRef data;
	sf::Sprite background;
	sf::Sprite homeButton;
	sf::Sprite quitButton;
	sf::Text highestScore;
	sf::Text currentScore;
	HighestScore highScore;
	bool isMouseButtonReleased;
};
