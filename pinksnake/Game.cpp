#include "Game.h"

Game::Game()
{
	this->initWindow(); //inicializa la ventana
	//this->initStates();
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
		this->states.top()->update(this->dt);
	}

	
}

void Game::render()
{
	this->window->clear(); //limpia la ventana
	

	this->initStates();


	

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
	/// <summary>
	/// /
	/// </summary>

	sf::Texture tileTexture;
	sf::Sprite tiles;


	std::vector<std::vector<sf::Vector2i>> map; //vector de SFML map
	std::vector<sf::Vector2i> tempMap; //mapa temporal

	std::ifstream openMap1("map1.txt"); // //esta carga el archivo de texto
	



	if (openMap1.is_open()) //si el archivo esta abierto
	{
		std::string tileLocation;
		openMap1 >> tileLocation;

		tileTexture.loadFromFile(tileLocation); //carga el archivo de la textura
		tiles.setTexture(tileTexture); //la textura se convierte en sprite

		while (!openMap1.eof()) //mientras no se lea hasta el final del archivo
		{
			this->states.push(new MainMenuState(this->window)); //STAR se inicializa el GameState

			std::string str;
			openMap1 >> str;

			char x = str[0], y = str[2];

			if (!isdigit(x) || !isdigit(y))
				tempMap.push_back(sf::Vector2i(-1, -1));
			else
				tempMap.push_back(sf::Vector2i(x - '0', y - '0'));

			if (openMap1.peek() == '\n')
			{
				map.push_back(tempMap);
				tempMap.clear();
			}
		}
		map.push_back(tempMap);
	}


	


	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j].x != -1 && map[i][j].y != -1)
			{
				tiles.setPosition(i * 32, j * 32);
				tiles.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y * 32, 32, 32));
				this->window->draw(tiles); //dibuja los tiles
			}
		}
	}

	/// <summary>
	/// //
	/// </summary>







	

	
}
