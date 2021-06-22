#include "Fase.h"
#include <stdlib.h>
#include <time.h>
#include "Entidade.h"
#include "Jogador.h"
#include "Menu.h"
#include "Obstaculo.h"
#include "Parede_Indestrutivel.h"
#include "ParedeAutoQuebravel.h"
#include "Zumbi.h"
#include "Robo.h"
#include "Chefao.h"
Fase::Fase(string faseN, sf::RenderWindow* windowN, bool doisJog, Jogador* p1N, Jogador* p2N) :
    fase(faseN),
    window(windowN),
    p1(p1N),
    p2(p2N),
    doisJogadores(doisJog)

{
    Inicializa();
    tParedes.loadFromFile("Imagens/cobble.jpg");

    Background.setPosition(0, 0);
    Background.setFillColor(sf::Color(100, 100, 100, 255));
}
Fase::~Fase()
{

}

Mapa* Fase::getMapa()
{
    return mapa;
}

void Fase::Inicializa()
{
    LerArquivo();

    view.setCenter(650, 350);
    view.setSize(1300, 700);
    /*
    string line;
    ifstream myfile(fase);
    srand(time(NULL));
    int alt, larg, posi;
    if (myfile.is_open())
    {
        getline(myfile, line);
        posi = line.find(' ');
        larg = stoi(line.substr(0, posi));
        alt = stoi(line.substr(posi + 1));
        mapa = new Mapa(larg, alt);
        aux = new Entidade(0, 0);
        int j = 0;
        while (getline(myfile, line))
        {
            for (int i = 0; i < larg; i++)
            {
                if (line[i] == '<')
                {
                    int novo = rand() % 2;
                    if (novo == 1)
                    {
                        obstaculos = new ParedeQuebravel(i, j, mapa);
                        mapa->setEntidade(i, j, obstaculos);
                    }
                    else
                    {
                        obstaculoAuto = new ParedeAutoQuebravel(i, j, mapa);
                        mapa->setEntidade(i, j, obstaculoAuto);
                    }
                }
                else if (line[i] == '6')
                {
                    obstaculosIn = new ParedeInquebravel(i, j, mapa);
                    mapa->setEntidade(i, j, obstaculosIn);
                }
                else if (line[i] == '1')
                {
                    p1->setX(i);
                    p1->setY(j);
                    p1->setID(1);
                    mapa->setEntidade(i, j, p1);
                }
                else if (p2 != nullptr && line[i] == '2')
                {
                    p2->setID(2);
                    p2->setX(i);
                    p2->setY(j);
                    mapa->setEntidade(i, j, p2);
                }
                else if (line[i] == '9')
                {
                    int novo = rand() % 2;
                    if (novo == 1)
                    {
                        zumbies = new Zumbi(i, j, mapa);
                        mapa->setEntidade(i, j, zumbies);
                    }
                    else
                    {
                        robot = new Robo(i, j, mapa);
                        mapa->setEntidade(i, j, robot);
                    }
                }
            }
            j++;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    p1->setMapa(mapa);
    if (p2 != nullptr)
        p2->setMapa(mapa);

        */
    t.loadFromFile("Imagens/flat1000x1000075f.u1.jpg");
    t.setRepeated(true);
    
    Background.setTexture(&t);

}

void Fase::LerArquivo()
{
    //ponteiros para objetos a serem istanciados
    Zumbi* zomb;
    Obstaculo* obs;
    Parede_Indestrutivel* ind;
    Chefao* chef;
    Robo* rob;
    ParedeAutoQuebravel* aut;
    string line;
    ifstream myfile(fase);
    srand(time(NULL));
    int alt, larg, posi;
    if (myfile.is_open())
    {
        getline(myfile, line);
        posi = line.find(' ');
        larg = stoi(line.substr(0, posi));
        alt = stoi(line.substr(posi + 1));
        mapa = new Mapa(window, alt, larg);
        int j = 0, i;
        while (getline(myfile, line))
        {
            for (i = 0; i < larg; i++) {
                if (line[i] == '<')
                {
                    int novo = rand() % 2;
                    if (novo == 1)
                    {
                        obs = new Obstaculo(i, j, mapa);
                        mapa->setEnt(i, j, obs);
                    }
                    else
                    {
                        aut = new ParedeAutoQuebravel(i, j, mapa);
                        mapa->setEnt(i, j, aut);
                    }
                }
                else if (line[i] == '6')
                {
                    ind = new Parede_Indestrutivel(i, j, mapa);
                    mapa->setEnt(i, j, ind);
                }
                else if (line[i] == '1')
                {
                    p1->setPos(i, j);
                    p1->setMapa(mapa);
                    mapa->setEnt(i, j, p1);
                }
                else if (line[i] == '2' && doisJogadores)
                {
                    p2->setPos(i, j);
                    p2->setMapa(mapa);
                    mapa->setEnt(i, j, p2);
                }
                else if (line[i] == '9')
                {
                    int novo = rand() % 2;
                    if (novo == 1)
                    {
                        zomb = new Zumbi(i, j, mapa);
                        mapa->setEnt(i, j, zomb);
                    }
                    else
                    {
                        rob = new Robo(i, j, mapa);
                        mapa->setEnt(i, j, rob);
                    }
                }
                else if (line[i] == '>')
                {
                    porta = new PortaFinal(i, j, mapa);
                    mapa->setEnt(i, j, porta);
                }
                /*
                if (line[i] - 48 == 3) {
                    ind = new Parede_Indestrutivel(i, j, mapa);
                    mapa->setEnt(i, j, ind);
                }
                else if (line[i] - 48 == 4) {
                    obs = new Obstaculo(i, j, mapa);
                    mapa->setEnt(i, j, obs);
                }
                else if (line[i] - 48 == 6) {

                    zomb = new Zumbi(i, j, mapa);
                    mapa->setEnt(i, j, zomb);

                }
                else if (line[i] - 48 == 7) {
                    rob = new Robo(i, j, mapa);
                    mapa->setEnt(i, j, rob);

                }
                else if (line[i] - 48 == 8) {
                    chef = new Chefao(i, j, mapa);
                    mapa->setEnt(i, j, chef);
                }
                else if (line[i] - 48 == 1) {
                    p1 = new Jogador(i, j, mapa, window, 1);
                    mapa->setEnt(i, j, p1);
                }
                else if (line[i] - 48 == 2) {
                    p2 = new Jogador(i, j, mapa, window, 2);
                    mapa->setEnt(i, j, p2);
                }
                else if (line[i] == 'e') {
                    p3 = new Jogador(i, j, mapa, &window, 3);
                    mapa->setEnt(i, j, p3);
                }*/

            }
            j++;

        }
        myfile.close();
    }
    else cout << "Unable to open file";
    Background.setSize(sf::Vector2f(1300, 100 * alt));
}



void Fase::Executa()
{
    window->setView(view);
    if (p1->getPositionY() > view.getCenter().y) {
        view.setCenter(650.f, (view.getCenter().y + p1->getPositionY() / 150));
    }else if(doisJogadores && p2->getPositionY() > view.getCenter().y)view.setCenter(650.f, (view.getCenter().y + p2->getPositionY() / 150));
    window->draw(Background);
    //mapa->printMapa();
    mapa->Executar();
    mapa->Draw();
    //window->draw(p1->getBarraVida());

}