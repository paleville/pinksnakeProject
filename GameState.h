#pragma once
#include "State.h"
#include "entityClass.h"
#include "playerClass.h"



class GameState : public State
{
public:
	GameState();
	GameState(sf::RenderWindow* window);
	virtual ~GameState();



	void endState()override;
	void update(const float& dt)override;
	void render()override;



	entityClass ent;
	playerClass play;

};

