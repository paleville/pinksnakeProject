#include "Game.h"




Game::Game()
{
	this->initWindow(); //inicializa la ventana
	playerClass play;
}

Game::~Game()
{
	delete this->window;


	while (!this->states.empty()) //mientras el stack no este vacio
	{
		delete this->states.top(); //Toma el tope del stack
		this->states.pop(); //entonces se eliminaran del stack
	}
}

void Game::updateSFMLEvents()
{




	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed) //esta linea es el input de cerrar la ventana
			this->window->close(); //Esta linea cierra la ventana
	}
}

void Game::update(float dt)
{
	play.input(dt); //tomamos el input del player
	this->updateSFMLEvents();


	if (!this->states.empty()) //si no esta vacio el stack
	{
		this->states.top()->update(dt); //deltaTime = 0

		//std::cout << "DT: " << dt << std::endl;
	}

	play.update(dt);//tomamos el update del player
}

void Game::render()
{
	this->window->clear(sf::Color::White); //limpia la ventana


	this->initStates();

	play.drawPlayer("playerTex4.png", play.e_sprite, play.e_texture, *window);
	//this->window->draw(gamestate.ent.e_shape); //dibuja al entity



	if (!this->states.empty()) //si el stack no esta vacio 
	{
		this->states.top()->render(); //entonces toma el top del stack en Render
	}


	this->window->display(); //se muestra el visor de la pantalla
}

void Game::run()
{
	while (this->window->isOpen()) //mientras la ventana este abierta
	{
		dt = clock.getElapsedTime().asMicroseconds(); //deltaTime en microsegundos
		clock.restart(); //se resetea el deltaTime
		dt = dt / 800; //dividimos el deltaTime entre 800

		this->update(dt); //se ejecuta el update

		this->render(); //se ejectua el render

	}
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(500, 500), "PlatformerGame");
	window->setFramerateLimit(60);
}

void Game::initStates()
{

	

	this->states.push(new MainMenuState(this->window)); //STAR se inicializa el GameState

}
