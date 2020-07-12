#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetsManager.hpp"
#include "InputManager.hpp"

struct GameData
{
	StateMachine machine;
	sf::RenderWindow window;
	AssetsManager assets;
	InputManager input;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
public:
	Game();
	~Game();
	
private:
	GameDataRef data = std::make_shared<GameData>();
	void run();
};

