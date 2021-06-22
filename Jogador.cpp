#include "Jogador.h"
#include "Obstaculo.h"
#include "stdafx.h"
#include "EfeitoVisual.h"

Jogador::Jogador(int xN, int yN, Mapa* mPtr, sf::RenderWindow* wPtr,int idN) :
    Personagem(xN, yN, mPtr)
{
    id = idN;
    vida = 3;
    window = wPtr;
    if (id == 1){
        animacao[0].loadFromFile("images/jogador/caindo.png");
        animacao[1].loadFromFile("images/jogador/i1.png");
        animacao[2].loadFromFile("images/jogador/i2.png");
        animacao[3].loadFromFile("images/jogador/i3.png");
        animacao[4].loadFromFile("images/jogador/i4.png");
        animacao[5].loadFromFile("images/jogador/r1.png");
        animacao[6].loadFromFile("images/jogador/r2.png");
        animacao[7].loadFromFile("images/jogador/r3.png");
        animacao[8].loadFromFile("images/jogador/r4.png");

    }
    else if(id == 2) {
        animacao[0].loadFromFile("images/jogador2/caindo.png");
        animacao[1].loadFromFile("images/jogador3/i1.png");
        animacao[2].loadFromFile("images/jogador3/i2.png");
        animacao[3].loadFromFile("images/jogador3/i3.png");
        animacao[4].loadFromFile("images/jogador3/i4.png");
        animacao[5].loadFromFile("images/jogador3/r1.png");
        animacao[6].loadFromFile("images/jogador3/r2.png");
        animacao[7].loadFromFile("images/jogador3/r3.png");
        animacao[8].loadFromFile("images/jogador3/r4.png");/*
        animacao[0].loadFromFile("images/jogador2/caindo.png");
        animacao[1].loadFromFile("images/jogador2/i1.png");
        animacao[2].loadFromFile("images/jogador2/i2.png");
        animacao[3].loadFromFile("images/jogador2/i3.png");
        animacao[4].loadFromFile("images/jogador2/i4.png");
        animacao[5].loadFromFile("images/jogador2/r1.png");
        animacao[6].loadFromFile("images/jogador2/r2.png");
        animacao[7].loadFromFile("images/jogador2/r3.png");
        animacao[8].loadFromFile("images/jogador2/r4.png");*/
    }
    else {/*
        animacao[0].loadFromFile("images/jogador2/caindo.png");
        animacao[1].loadFromFile("images/jogador3/i1.png");
        animacao[2].loadFromFile("images/jogador3/i2.png");
        animacao[3].loadFromFile("images/jogador3/i3.png");
        animacao[4].loadFromFile("images/jogador3/i4.png");
        animacao[5].loadFromFile("images/jogador3/r1.png");
        animacao[6].loadFromFile("images/jogador3/r2.png");
        animacao[7].loadFromFile("images/jogador3/r3.png");
        animacao[8].loadFromFile("images/jogador3/r4.png");
    */}

    //teste DELETAR
    efeitosJogador = new EfeitoVisual(wPtr, 1, &x, &y,&direcao, &vida);
    efeitosJogador->SetarNumEfeito(0);
    //

    imagem.setPosition(sf::Vector2f(100.f*x + 10, 100.f*y ));
    imagem.setSize(sf::Vector2f(100.f, 100.f));
    imagem.setTexture(&animacao[1]);

}

Jogador::~Jogador()
{
    cout << "jogador morto" << endl;
}

void Jogador::Executar()
{
    efeitosJogador->Executar();
    Arredores();
    Animacao();
    if (AcaoCoolDown > 0) AcaoCoolDown--;
    //window->draw(olho);
}

void Jogador::Arredores()
{
    //cout << mapa->getEntId(x, y + 1);
    if (AcaoCoolDown == 0 && Pulando == false) {
        if (mapa->getEntId(x, y + 1) == IdsEntidades::Vazio){
            cout << "Caindo!!" << endl;
            Cair();
        }
        if (mapa->getEntId(x, y + 1) == IdsEntidades::Zumbi) {
            cout << " bonk" << endl;
            Cair();
        } 
    }
}

void Jogador::Move(short int direcaoNova)
{
    if (Pulando == true && direcao != direcaoNova) direcao = direcaoNova;

    if (Pulando == true && (mapa->getEntId(x + 1 * direcao, y + 1) > IdsEntidades::Jogador2)) {
        cout << "moveu no ar" << endl;
        direcao = direcaoNova;
        
        mapa->moveEnt(x, y, 1 * direcao, 0);

        x = x + 1 * direcao;
        FramesRestantesPulo = AcaoCoolDown;
        AcaoCoolDown = numFramesAcao;
        AndandoNoAr = true;
        Andando = true;
    }

    if (AcaoCoolDown == 0) {
        direcao = direcaoNova;
        //refletir projeteis
        if (mapa->getEntId(x + 1 * direcao, y) == IdsEntidades::Projetil) {
            mapa->setVida(x + 1 * direcao, y, -1);
            cout << "refletiu" << endl;
        }

        //mover se normalmente
        else {
            if (mapa->getEntId(x + 1 * direcao, y) == IdsEntidades::Zumbi) {
                
                Atacar();
                cout << "Atacou" << endl;
            }
            else if (mapa->getEntId(x + 1 * direcao, y) == IdsEntidades::Vazio || mapa->getEntId(x + 1 * direcao, y) > IdsEntidades::Parede) {
               
                AcaoCoolDown = numFramesAcao;
                mapa->moveEnt(x, y, 1 * direcao, 0);
                x = x + 1 * direcao;
                Andando = true;
                cout << "moveu normal" << endl;
            }
            else cout << "bonk" << endl;

        }
    }
    Animacao_Direcao();
}

void Jogador::moverCima()
{
    if (AcaoCoolDown == 0) {
        if (mapa->getEntId(x, y - 1) == IdsEntidades::ParedeQuebravel) {
            AcaoCoolDown = numFramesAcao;
            Atacando = true;
            mapa->setEnt(x, y - 1, nullptr);
        }
        else if (mapa->getEntId(x, y - 1) == IdsEntidades::Vazio){
            AcaoCoolDown = numFramesAcao;
            Pulando = true;
            mapa->moveEnt(x, y, 0, -1);
            y = y--;
        }
    }
}

void Jogador::moverBaixo()
{
    if (AcaoCoolDown == 0) {
        if (mapa->getEntId(x, y + 1) == IdsEntidades::ParedeQuebravel) {
            mapa->setEnt(x, y + 1, nullptr);
        }
        if (mapa->getEntId(x, y + 1) == IdsEntidades::Parede) {
            imagem.setTexture(&animacao[0]);
        }
    }
}

void Jogador::Cair()
{
    if (AcaoCoolDown == 0) {
        mapa->moveEnt(x, y, 0, 1);
        AcaoCoolDown = numFramesAcao;
        Caindo = true;
        y++;
    }
}

sf::RectangleShape Jogador::getHp()
{
    return hp;
}


void Jogador::printPosition()
{
    sf::Vector2f aux;
    aux = imagem.getPosition();
    cout << "pos: " << aux.x << ", " << aux.y << endl;
    cout << "x = " << x << ", " << "y = " << y << endl;
}

void Jogador::setVida(int setvida)
{
    vida += setvida;
    efeitosJogador->setVida();
}

void Jogador::SpawnBloco()
{
    if (AcaoCoolDown == 0){
        if (mapa->getEntId(x+1*direcao,y) == 0){
            spawn_bloco = new Obstaculo(x + 1 * direcao, y, mapa);
            mapa->setEnt(x + 1 * direcao, y, spawn_bloco);
        }
    }
}



void Jogador::Animacao()
{
    if (Atacando == true) Animacao_Atacando();
    if (AndandoNoAr == true) Animacao_AndandoNoAr();
    else if (Pulando == true) Animacao_Move(0.f, -100.f);
    else if (Caindo == true) Animacao_Move(0.f, 100.f);
    else if (Andando == true) Animacao_Move(100.f * direcao, 0.f);
    else Animacao_Idle();
}
void Jogador::Animacao_Direcao()
{
    imagem.setScale(sf::Vector2f(direcao, 1));
    if (direcao == -1){
        imagem.setOrigin(100, 0);
    }
    else
        imagem.setOrigin(0, 0);
}

void Jogador::Animacao_Move(float posX, float posY)
{
    if (AcaoCoolDown > 0) {
        //cout << AcaoCoolDown <<" " <<endl;
        imagem.move(posX / numFramesAcao, posY / numFramesAcao);
        if (Andando == true) efeitosJogador->DesenharEfeito();
        efeitosJogador->movePosAnimacao(sf::Vector2f(posX / numFramesAcao, posY / numFramesAcao));

        if (AcaoCoolDown <= numFramesAcao * 1 / 4) {
            imagem.setTexture(&animacao[5]);
            efeitosJogador->SetarNumEfeito(0);
        }
        else if (AcaoCoolDown <= numFramesAcao * 2 / 4) {
            imagem.setTexture(&animacao[6]);
            efeitosJogador->SetarNumEfeito(1);
        }
        else if (AcaoCoolDown <= numFramesAcao * 3 / 4) {
            imagem.setTexture(&animacao[7]);
            efeitosJogador->SetarNumEfeito(2);
        }
        else if (AcaoCoolDown <= numFramesAcao * 4 / 4) {
            imagem.setTexture(&animacao[8]);
            efeitosJogador->SetarNumEfeito(3);   
        }
    }
    else {
        Pulando = false;
        Andando = false;
        Caindo = false;
    }
}

void Jogador::Animacao_Atacando()
{
    if (AcaoCoolDown > 0) {
        imagem.setFillColor(sf::Color(120, 20, 20));
    }
    else {
        imagem.setFillColor(sf::Color(255, 255, 255));
        Atacando = false;
    }
}

void Jogador::Animacao_Idle()
{
    
    tempoIdle++;
    if (tempoIdle == 1) {
        imagem.setTexture(&animacao[1]);
    }
    else if (tempoIdle == tempoAnimacaoIdle) {
        imagem.setTexture(&animacao[2]);
    }
    else if (tempoIdle == tempoAnimacaoIdle * 2) {
        imagem.setTexture(&animacao[3]);
    }
    else if (tempoIdle == tempoAnimacaoIdle * 3) {
        imagem.setTexture(&animacao[4]);
    }
    else if (tempoIdle == tempoAnimacaoIdle * 4) {
        tempoIdle = 0;
    }
    
}

void Jogador::Animacao_AndandoNoAr()
{
    Animacao_Move(100.f*direcao, 0.f);
    FramesRestantesPulo--;
    if (FramesRestantesPulo >= 0) {
        imagem.move(sf::Vector2f(0, -100.f / numFramesAcao));
        efeitosJogador->movePosAnimacao(sf::Vector2f(0, -100.f / numFramesAcao));
    }
    else if (Andando == false) {
        AndandoNoAr = false;
    }
}

void Jogador::Cavar()
{
    if (AcaoCoolDown == 0) {
        if (mapa->getEntId(x + 1 * direcao, y) == 4) {
            mapa->setEnt(x +1 * direcao, y,nullptr);
        }
    }
}

void Jogador::Atacar()
{
    AcaoCoolDown = numFramesAcao;
    Atacando = true;
    mapa->setEnt(x + 1 * direcao, y, nullptr);
}

float Jogador::getPosView()
{
    return imagem.getPosition().y;
}

void Jogador::setMapa(Mapa* mpN)
{
    mapa = mpN;
}

void Jogador::setPos(int a, int b)
{
    x = a;
    y = b;
    imagem.setPosition(a * 100.f, b * 100.f);
    efeitosJogador->setPos(a, b);
}