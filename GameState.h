#pragma once
#include "State.h"
#include "entityClass.h"
#include "playerClass.h"


class GameState : public State
{
public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();



	void endState();
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);


private:
	entityClass ent;
	playerClass play;

};

