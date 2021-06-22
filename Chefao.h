#pragma once
#include "Personagem.h"
class PilardeFogo;
class Chefao :
    public Personagem
{
private:
    PilardeFogo* Pilar;
    short int tempoAnimacao = 0;
    short int tempoProjetil = 0;
    const short int duracaoAnimacao = 8;

public:

    Chefao(int xN, int yN, Mapa* mPtr);
    ~Chefao();

    void Spawn_PilardeFogo();
    void Executar();
    void Animacao_Idle();
};

