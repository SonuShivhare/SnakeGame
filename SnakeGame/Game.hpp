#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetsManager.hpp"
#include "InputManager.hpp"
#include"SoundEffect.hpp"

struct GameData
{
	StateMachine machine;
	sf::RenderWindow window;
	AssetsManager assets;
	InputManager input;
	SoundEffect soundEffect;
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

