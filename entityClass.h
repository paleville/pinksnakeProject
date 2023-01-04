#pragma once
#include "State.h"

class entityClass
{

public:
	entityClass();
	~entityClass();

	sf::RectangleShape e_shape; //rectangulo


	sf::FloatRect e_rect;
	sf::Texture	e_texture;
	sf::Sprite e_sprite;
	sf::RenderWindow* e_window;

	const int e_floor = 320 - (82 + 100); //valor 138
	bool e_on_floor;
	float e_movemenSpeed;
	float e_jumpSpeed;
	float e_dx;
	float e_dy;
	float e_frame; //frame para animaciones





};

