#include "playerClass.h"

playerClass::playerClass()
{	
	e_movemenSpeed = 0.1f;
	e_jumpSpeed = 1.f;
	e_dx = 0;
	e_dy = 0;
	e_frame = 0;
	e_on_floor = false;
}


void playerClass::input(float dt)
{


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		e_dx = e_movemenSpeed; //e_dx ahora vale 0.1f
		e_frame += 0.5f; //e_frame ahora vale 0.5f
		goRight = true; //goRight se vuele verdadero
	}


	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		e_dx = -e_movemenSpeed;
		e_frame += 0.5f;
		goRight = false;
	}
	else
	{
		e_dx = 0; // e_dx se vuelve 0 para que el player no se mueva horizontalmente si no presionamos ninguna tecla
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (e_on_floor) //si esta en el suelo
		{
			e_dy = -e_jumpSpeed;	//puede saltar porque ahora  e_dy vale 1.f	
		}
	}
	

}

void playerClass::update(float dt)
{
	//GRAVEDAD
	e_rect.left += e_dx * dt;
	e_rect.top += e_dy * dt;

	if (!e_on_floor) //si no esta en el suelo
	{		
		e_dy = e_dy + 0.006 * dt; //fuerza que empuja al Player hacia abajo
		e_sprite.move(e_sprite.getPosition().x, e_dy);
	}

	e_on_floor = false; //por defecto e_on_floor es falso porque no esta tocando el suelo

	if (e_rect.top > e_floor) //si rect.top es mayor a 138
	{
		input(dt);
		e_rect.top = e_floor; //rectop es igual al suelo o rectop esta tocando en el suelo
		e_dy = 0; //direccion en y es igual a 0
		e_on_floor = true; //e_on_floor se vuelve verdadero
	}

	e_sprite.setPosition(e_rect.left, e_rect.top);
	e_dx = 0;
}

void playerClass::drawPlayer(std::string texDirectory, sf::Sprite e_sprite, sf::Texture& texture, sf::RenderWindow& p_window)
{

	if (!e_texture.loadFromFile(texDirectory)) //Si no hay archivo de textura
	{
		std::cerr << "Error\n"; //entonces hay un error
	}
	e_sprite.setTexture(e_texture);  //configuramos la textura como sprite
	e_sprite.setTextureRect(sf::IntRect(0, 0, 18, 18)); //recortar la textura en 18x18 pixeles



	if (goRight == true && e_movemenSpeed >= 0.1) //cuando este if statement se cumpla
	{
		e_sprite.setTextureRect(sf::IntRect(18 * (int)e_frame, 0, 18, 18)); //se ejecuta la animacion hacia la derecha
		
		if (e_frame > 6) //cuando e_frame sea mayor a 6
		{
			
			e_frame -= 6; //e_frame no se va a pasar del frame 6
		}		
	}

	else if (e_movemenSpeed == 0) //si el player no se esta moviendo
	{
		e_sprite.setTextureRect(sf::IntRect(0, 0, 18, 18)); //la animacion se queda tal cual esta actualmente
	}


	if (goRight == false && e_movemenSpeed >= -0.1f) //si esto se cumple
	{
			e_sprite.setTextureRect(sf::IntRect(18 * (int)e_frame + 18, 0, -18, 18)); //entonces el player ejecutara animaciones mirando hacia la izquierda
			
			if (e_frame > 6)
			{
				e_frame -= 6;
			}		
	}
	else if (e_movemenSpeed == 0)
	{
		e_sprite.setTextureRect(sf::IntRect(0, 0, -18, 18)); //le
	}

	p_window.draw(e_sprite);
}

