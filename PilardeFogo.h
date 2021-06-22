#pragma once
#include "Personagem.h"
class PilardeFogo :
    public Personagem
{
private:
public:
    PilardeFogo(int xN = 0, int yN = 0, Mapa* mPtr = nullptr);
    ~PilardeFogo();
    void Executar();
};

