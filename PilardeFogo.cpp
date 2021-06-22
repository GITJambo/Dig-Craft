#include "PilardeFogo.h"

PilardeFogo::PilardeFogo(int xN, int yN, Mapa* mPtr) :
    Personagem(xN, yN, mPtr)
{
    x = xN;
    y = yN;
    id = 10;
    tempo = 0;

    animacao[0].loadFromFile("images/Chefao/PilardeFogo.png");
    imagem.setSize(sf::Vector2f(100.f, 200.f));
    imagem.setTexture(&animacao[0]);
    imagem.setPosition(sf::Vector2f(100.f * x, 100.f * y -100));
}

PilardeFogo::~PilardeFogo()
{
    //cout << "Fogo Apagado" << endl;
}

void PilardeFogo::Executar()
{
    tempo++;
    if (tempo > 200) {
        mapa->setEnt(x, y, nullptr);
    }
}
