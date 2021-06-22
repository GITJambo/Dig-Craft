#pragma once
#include "Obstaculo.h"
class Parede_Indestrutivel :
    public Obstaculo
{
public:
    Parede_Indestrutivel(int xN = 0, int yN = 0, Mapa* mapaN = nullptr);
    ~Parede_Indestrutivel();
};

