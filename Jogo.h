#pragma once
#include "stdafx.h"
#include "Entidade.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include "Fase.h"

class Menu;

class Jogo
{
private:
    sf::Text texto;
    bool start;
    bool doisJog;

    sf::RenderWindow window;
    sf::Sprite Background;
    sf::Texture t;
    

    Jogador* p1;
    Jogador* p2;
    Mapa *mapa;
    Menu* menu;
    Fase* fase1;
    
    //ListaEntidades *listadeEntidades;

    
public:
    Jogo();
    ~Jogo();

    void Inicializar();
    void Executar();
    void setDoisJog(bool);
    bool getDoisJog() const;

};

