#pragma once
#include"Defs.hpp"

class StartWindow
{
public:
	StartWindow();
	~StartWindow();
	void render(sf::RenderWindow& window, int& gameLevel);
private:
	sf::Texture Background_t;
	sf::Sprite Background;
	
	sf::Texture title_t;
	sf::Sprite title;

	/*sf::Font title_f;
	sf::Text title;*/

	sf::Texture StartButton01_t;
	sf::Texture StartButton02_t;
	sf::Sprite StartButton01;
	sf::Sprite StartButton02;
};

