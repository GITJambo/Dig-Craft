#include "Jogo.h"
#include "Jogador.h"
//#include "IdsEntidades.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Entidade.h"
#include "stdafx.h"
#include "Obstaculo.h"
#include "Zumbi.h"
#include "Robo.h"
#include "Projetil.h"
#include "Parede_Indestrutivel.h"
#include "Chefao.h"
#include "Menu.h"

Jogo::Jogo() :
    window(sf::VideoMode(1300, 700), "The game!")


{
    p1 = new Jogador(0, 0, mapa, &window, 1);
 
    
    //stl set
    t.loadFromFile("images/BG.jpg");
    Background.setTexture(t);
    menu = new Menu(1, &window, this);
    Inicializar();
	Executar();
}

Jogo::~Jogo() {
    delete p1;
    delete p2;
    delete mapa;
}

void Jogo::setDoisJog(bool dois)
{
    doisJog = dois;
    if(doisJog)   p2 = new Jogador(0, 0, mapa, &window, 2);
    delete fase1;
    fase1 = new Fase("mapa.txt", &window, doisJog, p1, p2);
}

void Jogo::Inicializar()
{
   // LerArquivo();
}

void Jogo::Executar()
{   
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    int frames = 0;
    while (window.isOpen())
    {
        
        sf::Event event;
        //menu.setEvent(&event);
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                //config janela
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::EventType::LostFocus:
                    start = false;
                    break;
                case sf::Event::EventType::GainedFocus:
                    !start ? start = false : start = true;
                    break;
                case sf::Event::EventType::KeyPressed:
                    
                    //cout << "tecla apertada" << endl;
                    if (sf::Keyboard::C == event.key.code) window.close();
                    if (!menu->getAberto())
                    {
                        //Controle do jogador P1
                        if (sf::Keyboard::W == event.key.code) p1->moverCima();
                        if (sf::Keyboard::A == event.key.code) p1->Move(-1);
                        if (sf::Keyboard::S == event.key.code) p1->moverBaixo();
                        if (sf::Keyboard::D == event.key.code) p1->Move(1);
                        if (sf::Keyboard::Q == event.key.code) p1->Cavar();
                        if (sf::Keyboard::R == event.key.code) p1->SpawnBloco();
                        if (sf::Keyboard::Num1 == event.key.code) mapa->printMapa();
                        //controle P2
                        if (doisJog) {
                            if (sf::Keyboard::Left == event.key.code) p2->Move(-1);
                            if (sf::Keyboard::Down == event.key.code) p2->moverBaixo();
                            if (sf::Keyboard::Right == event.key.code) p2->Move(1);
                            if (sf::Keyboard::Up == event.key.code) p2->moverCima();
                        }
                    }
                    else
                    {
                        //Controle do Menu
                        if (sf::Keyboard::W == event.key.code || sf::Keyboard::Up == event.key.code) menu->MoveCima();
                        if (sf::Keyboard::S == event.key.code || sf::Keyboard::Down == event.key.code) menu->MoveBaixo();
                        if (sf::Keyboard::Enter == event.key.code) menu->Selecionar();
                    }
                    if (sf::Keyboard::Escape == event.key.code) {
                        if (!menu->getAberto())
                        {
                            menu->setTipo(2);
                        }
                        else menu->setTipo(0);
                    }
                    break;
            }
               
        }

        window.clear();
        
        if (!menu->getAberto())
        {
           // window.draw(Background);
           
            fase1->Executa();
            //mapa->Draw();
            //mapa->Executar();
            
        }
        else
            menu->Desenha();
        window.display();
        
    }
}

bool Jogo::getDoisJog() const
{
    return doisJog;
}
