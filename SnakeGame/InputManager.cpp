#include "InputManager.hpp"
#include<iostream>

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

bool InputManager::isSpriteClicked(sf::Sprite sprite, sf::Mouse::Button button, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		if (sprite.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
		{
			return true;
		}
	}
	return false;
}

bool InputManager::isMouseButtonReleased(sf::RenderWindow& window)
{
	std::cout << "inFunction" << std::endl;
	sf::Event event;
	window.pollEvent(event);
		std::cout << "inWhile" << std::endl;
		return (event.type == sf::Event::MouseButtonReleased);
}

sf::Vector2i InputManager::getMousePosition(sf::RenderWindow& window)
{
	return sf::Mouse::getPosition(window);
}