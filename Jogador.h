#pragma once
#include "Personagem.h"

class Obstaculo;
class EfeitoVisual;
    
class Jogador :
    public Personagem
{
private:
    sf::RectangleShape hp;
    sf::RenderWindow* window;

    Obstaculo* spawn_bloco = nullptr;

    EfeitoVisual* efeitosJogador = nullptr;

    short int direcao = 1;

    bool Agindo = false;
    bool Andando = false;
    bool Pulando = false;
    bool AndandoNoAr = false;
    bool Caindo = false;
    bool Atacando = false;

    short int AcaoCoolDown = 0;
    short int FramesRestantesPulo = 0;
    short int tempoIdle = 0;
    short int tempoPiscar = 0;
    const short int numFramesAcao = 16;
    const short int tempoAnimacaoIdle = 12;

public:
    Jogador(int xN = 0, int yN = 0, Mapa* mPtr = nullptr, sf::RenderWindow* wPtr = nullptr,int idN = 1);
    ~Jogador();

    virtual void Executar();
    virtual void Arredores();

    void Move(short int direcao);
    void moverCima();
    void moverBaixo();
    void Cair();
    
    sf::RectangleShape getHp();
    
    //somente para debug
    void printPosition();

    void setVida(int setvida);

    void SpawnBloco();

    void Animacao();
    void Animacao_Direcao();
    void Animacao_Move(float posX, float posY);
    void Animacao_Caindo();
    void Animacao_Atacando();
    void Animacao_Andando();
    void Animacao_Pulando();
    void Animacao_Idle();
    void Animacao_AndandoNoAr();

    void Cavar();
    void Atacar();
    float getPosView();

    void setMapa(Mapa*);
    void setPos(int a, int b);
};

