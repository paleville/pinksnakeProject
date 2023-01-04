#include "GameState.h"

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
	std::cout << "Ahora estamos en GameState" << "\n";
}

void GameState::render(sf::RenderTarget* target)
{
}
