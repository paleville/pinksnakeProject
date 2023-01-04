#pragma once


#include "GameState.h"
#include "MainMenuState.h"



class Game
{
public:

	Game();
	virtual ~Game();

	void updateSFMLEvents();
	void update();
	void render();
	void run();

	sf::RenderWindow* window;
	sf::Event sfEvent;

	float dt; //dela time

	std::stack<State*> states;

	void initWindow();
	void initStates();

	entityClass ent;
	

};

