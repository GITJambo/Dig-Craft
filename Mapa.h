#pragma once
#include <SFML/Graphics.hpp>
#include <set>
class Entidade;

class Mapa
{
private:

	Entidade*** mapaEnt;

	//set<pair<int, int>> EntidadesMortas;

	//Lista <Lista<MapaStruct>>
	//factory method
	sf::RenderWindow* window;
	const int largura;
	const int altura;
	int x;
	int y;
public:
	Mapa(sf::RenderWindow* wPtr = nullptr, int larguraN = 0, int alturaN = 0);
	~Mapa();

	int getMapaAltura();
	int getMapaLargura();

	void inicializaStruct();
	Entidade* getEnt(int x, int y);
	void setEnt(int x, int y,Entidade*);
	void LimparStruct();

	int getEntId(int x, int y);
	void moveEnt(int xAtual,int yAtual,int xAjuste, int yAjuste);

	void Draw();
	void Executar();
	void setVida(int x,int y, int vidaset);
	//somente debug
	void printMapa();
	int getJogadorPos(int y);
};

/*
	struct mapa{
		int id;
		Entidade * ent;

	};
	//enum teste { vazio = 0, personagem = 1, parede = 2, inimigo = 4 };
	//teste** mapa;
	*/