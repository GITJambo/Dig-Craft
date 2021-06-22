#include "Projetil.h"
//#include "IdsEntidades.h"
Projetil::Projetil(int xN, int yN,int direcaoN, Mapa* mPtr) :
    Personagem(xN, yN, mPtr)
{
    //cout << " Pew, novo projetil" << endl;
    refletido = false;
    vida = 2;
    direcao = direcaoN;
    id = IdsEntidades::Projetil;
    texture.loadFromFile("images/projetil.png");
    if (direcao == -1) {
        imagem.setScale(1, 1);
        imagem.setOrigin(0, 0);
    }
    else {
        imagem.setScale(-1, 1);
        imagem.setOrigin(100, 0);
    }

    imagem.setTexture(&texture);
    imagem.setSize(sf::Vector2f(75, 75));
    imagem.setPosition(sf::Vector2f(x * 100.f, (y * 100.f) + 10.f));
    imagem.setFillColor(sf::Color(0, 255, 238));
}

Projetil::~Projetil()
{
    //cout << "destrui projetil" << endl;
}

void Projetil::setVida(int setVida)
{
    if (refletido == false)direcao *= -1;
    
    refletido = true;

    if (direcao == -1) {
        imagem.setScale(1, 1);
        imagem.setOrigin(0, 0);
    }
    else {
        imagem.setScale(-1, 1);
        imagem.setOrigin(100, 0);
    }
    imagem.setFillColor(sf::Color(255, 200, 0));
}

void Projetil::Executar()
{
    if (tempo == 12) {
        tempo = 0;
            Move();
    }
    tempo++;
}
void Projetil::Move()
{  
    if (refletido == true) {
        if (mapa->getEntId(x + 2 * direcao, y) == IdsEntidades::Projetil) {
            vida--;
            if (vida == 0) {
                mapa->setEnt(x, y, nullptr);
            }
            mapa->setEnt(x + 2 * direcao, y, nullptr);

        }
    }
    if ((mapa->getEntId(x + 1 * direcao, y) == IdsEntidades::Jogador1) || (mapa->getEntId(x - 1, y) == IdsEntidades::Zumbi)) {
        mapa->setVida(x + 1 * direcao, y, -1);
        mapa->setEnt(x, y, nullptr);
    }
    else if (mapa->getEntId(x + 1 * direcao, y) == IdsEntidades::ParedeQuebravel || mapa->getEntId(x + 1 * direcao, y) == IdsEntidades::Parede) {
        mapa->setEnt(x, y, nullptr);
    }
    else {
        imagem.move(100.f * direcao, 0.f);
        mapa->moveEnt(x, y, 1 * direcao, 0);
        x = x + 1 * direcao;
    }
}
