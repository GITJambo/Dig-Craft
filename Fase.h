#pragma once
#include "Jogador.h"
#include "Mapa.h"
#include "PortaFinal.h"
#include "stdafx.h"
#include <fstream>
class Fase
{
protected:
    sf::RenderWindow* window;
    sf::Texture t;
    sf::Texture tParedes;
    sf::Texture tParedesInq;
    sf::RectangleShape Background;
    Jogador* p1;
    Jogador* p2;
    sf::View view;
    string fase;
    Mapa* mapa;
    PortaFinal* porta;
    bool doisJogadores;
public:
    Fase(string faseN, sf::RenderWindow* windowN, bool doisJog, Jogador* p1N, Jogador* p2N = nullptr);
    ~Fase();
    void Inicializa();
    void Executa();
    void LerArquivo();
    Mapa* getMapa();
};

