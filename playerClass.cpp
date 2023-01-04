#include "playerClass.h"

playerClass::playerClass()
{
}

playerClass::playerClass(sf::Texture& texture)
{
	sprite.setTexture(texture); //configurar la textura a partir del sprite del entity
	rect = sf::FloatRect(0, 0, 130, 16); //dimensiones del rectangulo

	dx = 0.f;
	dy = 0.f;
	frame = 0.f;
}
