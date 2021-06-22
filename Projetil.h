#pragma once
#include "Personagem.h"
class Projetil :
    public Personagem
{
private:
    bool refletido;
public:
    Projetil(int xN, int yN, int direcaoN, Mapa* mPtr);
    ~Projetil();
    virtual void setVida(int setvida);
    virtual void Executar();
    void Move();
};

