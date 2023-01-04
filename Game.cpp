#include "Game.h"

Game::Game()
{
	this->initWindow(); //inicializa la ventana
	
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

void Game::update()
{
	this->updateSFMLEvents();



	if (!this->states.empty()) //si no esta vacio el stack
	{
		this->states.top()->update(this->dt); //deltaTime = 0

		//std::cout << "DT: " << dt << std::endl;
	}

	
}

void Game::render()
{
	this->window->clear(); //limpia la ventana
	

	this->initStates();

	sf::Texture	texture;
	texture.loadFromFile("playerTex3.png");

	playerClass play(texture); //player


	this->window->draw(ent.shape); //dibuja al entity
	this->window->draw(play.sprite); //dibuja al sprite del player


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
		this->update(); //se ejecuta el update
		
		this->render(); //se ejectua el render

	}
}

void Game::initWindow()
{
	this->window =  new sf::RenderWindow(sf::VideoMode(500, 500), "PlatformerGame");
}

void Game::initStates()
{

	int mapWidth = 10; //ancho del mapa	
	int mapHeight = 10; //altura del mapa

	sf::Texture tileset_texture; //textura
	sf::Sprite tileset_sprite; //sprite

	tileset_texture.loadFromFile("tileset3.png"); //se carga el archivo
	tileset_sprite.setTexture(tileset_texture); //se convierte el archivo a sprite


	int map[] =
	{
		0,1,1,1,1,2,1,1,1,2,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,3,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		2,1,1,1,1,2,1,1,1,2,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,3,1,1,1,1,
		2,1,1,1,2,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		3,1,1,1,1,0,1,1,1,0,

	};

	for (int y = 0; y < mapHeight; y++) //for loop de la altura del mapa
	{
		for (int x = 0; x < mapWidth; x++) //for loop de la anchura del mapa
		{
			int tilecount = x + y * 10;

			tileset_sprite.setPosition(x * 16.f, y * 16.f); //calcular las dimensiones de cada cuadrado de la textura/sprite
			tileset_sprite.setTextureRect(sf::IntRect(map[tilecount] * 16, 0, 16, 16));

			this->window->draw(tileset_sprite);
		}
	}

	this->states.push(new GameState(this->window)); //STAR se inicializa el GameState


	/// <summary>
	/// /
	/// </summary>

	

	/// <summary>
	/// //
	/// </summary>







	

	
}
