#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window)
	: State(window)
{
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y)); //el background se iguala con las dimensiones del screen
	this->background.setFillColor(sf::Color::Yellow); //rellena el color del rectangulo
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::endState()
{
}

void MainMenuState::update(const float& dt)
{
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	
	target->draw(this->background); //dibuja el background

	std::cout << "Ahora estamos en el Menu Principal" << std::endl;
}
