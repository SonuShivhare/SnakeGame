#include "EndWindow.hpp"

EndWindow::EndWindow()
{
	Background_t.loadFromFile("Assets/images/QuitBackground01.png");
	Background.setTexture(Background_t);
	//Background.setOrigin(sf::Vector2f(Background.getGlobalBounds().width, Background.getGlobalBounds().height));
	Background.setPosition(sf::Vector2f(0, 0));

	QuitButton01_t.loadFromFile("Assets/images/QuitButton02.png");
	QuitButton01.setTexture(QuitButton01_t);
	QuitButton01.setOrigin(sf::Vector2f(QuitButton01.getGlobalBounds().width / 2, QuitButton01.getGlobalBounds().height / 2));
	QuitButton01.setPosition(sf::Vector2f(windowWidth / 1.15, windowHeight / 1.1));

	QuitButton02_t.loadFromFile("Assets/images/QuitButton01.png");
	QuitButton02.setTexture(QuitButton02_t);
	QuitButton02.setOrigin(sf::Vector2f(QuitButton02.getGlobalBounds().width / 2, QuitButton02.getGlobalBounds().height / 2));
	QuitButton02.setPosition(sf::Vector2f(windowWidth / 1.15, windowHeight / 1.1));
}

EndWindow::~EndWindow()
{
}

void EndWindow::totalScore(int scoreA)
{
	score_t.loadFromFile("c:/Windows/Fonts/arial.ttf");
	score_s.setFont(score_t);
	score_s.setStyle(score_s.Bold);
	score_s.setCharacterSize(50);
	score_s.setString("Total Score : " + std::to_string(scoreA));
	score_s.setFillColor(sf::Color::Black);
	score_s.setOrigin(score_s.getGlobalBounds().width / 2, 0);
	score_s.setPosition(windowWidth / 2, windowHeight / 1.8);
}

void EndWindow::render(sf::RenderWindow& window, int& gameLevel, int scoreA)
{
	window.clear();
	window.draw(Background);
	totalScore(scoreA);
	window.draw(score_s);

	window.draw(QuitButton01);
	if (QuitButton01.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
	{
		window.draw(QuitButton02);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) window.close();
	}
	window.display();
}
