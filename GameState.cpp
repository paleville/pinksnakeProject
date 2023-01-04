#include "GameState.h"

GameState::GameState()
{
}

GameState::GameState(sf::RenderWindow* window)
	: State(window)
{
	const int H = 23; //ancho del mapa	
	const int W = 80 / 2; //altura del mapa




	sf::String map[H] =
	{
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B                                                                             BB",
		"B             000 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B       BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};

	for (int i = 0; i < H; i++) //for loop de la altura del mapa
	{
		for (int j = 0; j < W; j++) //for loop de la anchura del mapa
		{
			if (map[i][j] == 'B')
			{
				sf::Texture grass_texture; //textura
				sf::Sprite grass_sprite; //sprite
				grass_texture.loadFromFile("grassTex.png"); //se carga el archivo
				grass_sprite.setTexture(grass_texture); //se convierte el archivo a sprite
				grass_sprite.setPosition(j * 16, i * 16);
				window->draw(grass_sprite);
			}
			if (map[i][j] == '0')
			{
				sf::Texture coin_texture; //textura
				sf::Sprite coin_sprite; //sprite
				coin_texture.loadFromFile("coinTex.png"); //se carga el archivo
				coin_sprite.setTexture(coin_texture); //se convierte el archivo a sprite
				coin_sprite.setPosition(j * 16, i * 16);
				window->draw(coin_sprite);
			}
			if (map[i][j] == ' ')
			{
				continue;
			}
		}
	}
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

void GameState::render(sf::RenderTarget* target)
{
	//this->ent.render(this->window);
	//play.drawPlayer("playerTex3.png", play.e_sprite, play.e_texture, *window);

	

}
