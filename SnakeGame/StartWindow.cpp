#include "StartWindow.hpp"

StartWindow::StartWindow()
{
	Background_t.loadFromFile("Assets/images/Background05.png");
	Background.setTexture(Background_t);
	//Background.setOrigin(sf::Vector2f(Background.getGlobalBounds().width, Background.getGlobalBounds().height));
	Background.setPosition(sf::Vector2f(0, 0));

	title_t.loadFromFile("Assets/images/Title00.png");
	title.setTexture(title_t);
	title.setOrigin(title.getGlobalBounds().width / 2, 0);
	title.setPosition(sf::Vector2f(windowWidth / 2.2, 0));

	/*title_f.loadFromFile("c:/Windows/Fonts/arial.ttf");
	title.setFont(title_f);
	title.setStyle(title.Bold);
	title.setCharacterSize(50);
	title.setString("Snake");
	//title.setColor(sf::Color::Blue);
	title.setOrigin(title.getGlobalBounds().width / 2, 0);
	title.setPosition(windowWidth / 2, 0);*/

	StartButton01_t.loadFromFile("Assets/images/StartButton01.png");
	StartButton01.setTexture(StartButton01_t);
	StartButton01.setOrigin(sf::Vector2f(StartButton01.getGlobalBounds().width / 2, StartButton01.getGlobalBounds().height / 2));
	StartButton01.setPosition(sf::Vector2f(windowWidth / 2.2, windowHeight / 1.6));

	StartButton02_t.loadFromFile("Assets/images/StartButton02.png");
	StartButton02.setTexture(StartButton02_t);
	StartButton02.setOrigin(sf::Vector2f(StartButton02.getGlobalBounds().width / 2, StartButton02.getGlobalBounds().height / 2));
	StartButton02.setPosition(sf::Vector2f(windowWidth / 2.2, windowHeight / 1.6));
}

StartWindow::~StartWindow()
{
}

void StartWindow::render(sf::RenderWindow& window, int& gameLevel)
{
	window.clear();
	window.draw(Background);
	window.draw(title);

	window.draw(StartButton01);
	if (StartButton01.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
	{
		window.draw(StartButton02);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) gameLevel = 2;
	}

	window.display();
}
