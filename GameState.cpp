#include "GameState.h"

GameState::GameState()
{
}

GameState::GameState(sf::RenderWindow* window)
	: State(window)
{
}

GameState::~GameState()
{
}

void GameState::endState()
{
}

void GameState::update(const float& dt)
{
	//std::cout << "Ahora estamos en GameState" << "\n";

	//this->ent.update(dt);
}

void GameState::render()
{
	//this->ent.render(this->window);
	//play.drawPlayer("playerTex3.png", play.e_sprite, play.e_texture, *window);
}
