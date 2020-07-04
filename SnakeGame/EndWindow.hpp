#pragma once
#include "Defs.hpp"

class EndWindow
{
public:
	EndWindow();
	~EndWindow();
	void totalScore(int scoreA);
	void render(sf::RenderWindow& window, int& gameLevel, int scoreA);
private:
	sf::Texture Background_t;
	sf::Sprite Background;

	sf::Font score_t;
	sf::Text score_s;

	sf::Texture QuitButton01_t;
	sf::Texture QuitButton02_t;
	sf::Sprite QuitButton01;
	sf::Sprite QuitButton02;
};

