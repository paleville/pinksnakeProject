#pragma once
#include "State.h"
class MainMenuState : public State
{

public:
	MainMenuState(sf::RenderWindow* window);
	virtual ~MainMenuState();


	sf::RectangleShape background;



	void endState();
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);

};

