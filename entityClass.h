#pragma once
#include "State.h"

class entityClass
{

public:
	entityClass();
	~entityClass();

	sf::RectangleShape shape; //rectangulo
	
	sf::FloatRect rect;
	sf::Texture	texture;
	sf::Sprite sprite;


	float movemenSpeed;
	float dx, dy, frame; //frame para animaciones

	

	

};

