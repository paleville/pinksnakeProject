#include "entityClass.h"

entityClass::entityClass()
{
	this->e_shape.setSize(sf::Vector2f(16.f, 16.f)); // se recorta de la textura una porcion de 16x16 pixeles
	this->e_shape.setFillColor(sf::Color::Cyan); //se va rellar con un color
	//e_movemenSpeed = 2; //velocidad de movimiento
}

entityClass::~entityClass()
{
}


