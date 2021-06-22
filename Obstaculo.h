#pragma once
#include "stdafx.h"
#include "Obstaculo.h"
#include "Entidade.h"
class Obstaculo :
    public Entidade
{
protected:
public:
    Obstaculo(int xN = 0, int yN = 0, Mapa* mapaN = nullptr);
    ~Obstaculo();
};


