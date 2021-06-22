#include "Zumbi.h"
//#include "IdsEntidades.h"
Zumbi::Zumbi(int xN, int yN, Mapa* mPtr) :
    Personagem(xN, yN, mPtr)
{
    id = IdsEntidades::Zumbi;
    direcao = 1;
    numFramesAcao = 20;
    vida = 1;
    x = xN;
    y = yN;
    playerproximo = false;
    animacao[0].loadFromFile("images/ogro/i1.png");
    animacao[1].loadFromFile("images/ogro/i1.png");
    animacao[2].loadFromFile("images/ogro/i2.png");
    animacao[3].loadFromFile("images/ogro/i3.png");
    animacao[4].loadFromFile("images/ogro/i4.png");
    animacao[5].loadFromFile("images/ogro/r1.png");
    animacao[6].loadFromFile("images/ogro/r2.png");
    animacao[7].loadFromFile("images/ogro/r3.png");
    animacao[8].loadFromFile("images/ogro/r4.png");
    imagem.setTexture(&animacao[0]);
    imagem.setPosition(sf::Vector2f(x*100.f, y*100.f));
}

Zumbi::~Zumbi()
{
    cout << "zumbi morto :c" << endl;
}

void Zumbi::Executar()
{
    
    Arredores();
    tempo++;
    if (tempo >= 120) Move();
    if (Andando == true) Animacao_Move(100.f * direcao, 0.f);
    if (Caindo == true) Animacao_Move(0.f , 100.f);
    if (AcaoCoolDown > 0) AcaoCoolDown--;
}

void Zumbi::Move()
{
     tempo = 0;
    if (AcaoCoolDown == 0)
    {
        if (mapa->getEntId(x + direcao, y) == IdsEntidades::Vazio && 
            mapa->getEntId(x + direcao, y + 1) != IdsEntidades::Vazio)
        {
            AcaoCoolDown = numFramesAcao;
            mapa->moveEnt(x, y, 1 * direcao, 0);
            x = x + 1 * direcao;
            Andando = true;
        
        }
        else{
            direcao *= -1;
            imagem.setScale(sf::Vector2f((float)direcao, 1.f));
            imagem.setTexture(&animacao[0]);
            direcao == 1 ? imagem.setOrigin(0, 0) : imagem.setOrigin(100.f, 0);
        }
    }
}
   


void Zumbi::Arredores()
{
    Arredor_Cair();
    Arredor_PlayerProximo();
}

void Zumbi::Arredor_Cair()
{
    if (AcaoCoolDown == 0)
    {
        if (mapa->getEntId(x, y + 1) == IdsEntidades::Vazio) {
            AcaoCoolDown = numFramesAcao;
            Caindo = true;
            y++;
        }
    }
    
}

void Zumbi::Arredor_PlayerProximo()
{
    if ((mapa->getEntId(x - 1, y) == IdsEntidades::Jogador1) || (mapa->getEntId(x + 1, y) == IdsEntidades::Jogador1 )) {
        imagem.setFillColor(sf::Color(20, 20, 120));
        playerproximo = true;
    }
    else {
        playerproximo = false;
        imagem.setFillColor(sf::Color(255, 255, 255));
    }
    if (playerproximo == true) {
        tempoAtaque++;
        if (tempoAtaque >= 30) {
            tempoAtaque = 0;
            Atacar();
        }
    }
    else (tempoAtaque = 0);
}

void Zumbi::Atacar()
{
    if (mapa->getEntId(x - 1, y) == 1) mapa->setVida(x - 1, y, -1);
    else if (mapa->getEntId(x + 1, y) == 1) mapa->setVida(x + 1, y, -1);
}

