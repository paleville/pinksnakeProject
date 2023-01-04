#pragma once


#include "GameState.h"
#include "MainMenuState.h"



class Game
{
public:

	Game();
	virtual ~Game();

	void updateSFMLEvents();
	void update(float dt);
	void render();
	void run();

	sf::RenderWindow* window;
	
	sf::Event sfEvent;

	float dt; //dela time
	//float time;
	sf::Clock clock;

	std::stack<State*> states;

	void initWindow();
	void initStates();

	GameState gamestate;
	playerClass play;
	

};

