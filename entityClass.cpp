#include "entityClass.h"

entityClass::entityClass()
{
	this->shape.setSize(sf::Vector2f(16.f, 16.f)); // se recorta de la textura una porcion de 16x16 pixeles
	this->shape.setFillColor(sf::Color::Cyan); //se va rellar con un color
	movemenSpeed = 100; //velocidad de movimiento
}

entityClass::~entityClass()
{
}


