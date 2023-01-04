#pragma once
#include "entityClass.h"

class playerClass :
    public entityClass
{

public:     
    playerClass();
    playerClass(sf::Texture& texture);
};

