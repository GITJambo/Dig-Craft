#include "Mapa.h"
#include "stdafx.h"
#include "Entidade.h"

Mapa::Mapa (sf::RenderWindow* wPtr, int larguraN, int alturaN):
	largura(larguraN + 1),
	altura(alturaN + 1)
{
	cout << "largura mapa = " << largura << endl;
	cout << "altura mapa = " << altura << endl;

	window = wPtr;
	inicializaStruct();
}

Mapa::~Mapa()
{
	LimparStruct();
}

void Mapa::inicializaStruct(){
	mapaEnt = new Entidade** [largura];
	for (int i = 0; i < largura; i++)
	{
		mapaEnt[i] = new Entidade*[altura];
		for (int j = 0; j < altura; j++)
		{
			mapaEnt[i][j] = nullptr;
		}
	}
}

Entidade* Mapa::getEnt(int x, int y)
{
	return mapaEnt[x][y];
}

void Mapa::setEnt(int x, int y,Entidade* ePtr)
{
	delete mapaEnt[y][x];
	mapaEnt[y][x] = ePtr;
}

void Mapa::LimparStruct()
{
	/*
	int i, j;
	for (i = 0; i < largura; i++) {
		for (j = 0; j < altura; j++) {
			if (mapaEnt[y][x]->idEntidade != NULL) {
				mapaEnt[y][x]->idEntidade->~Entidade();
			}
		}
	}
	*/
	
}

int Mapa::getEntId(int x, int y)
{
	if (mapaEnt[y][x] == nullptr)
		return 0;
	else return mapaEnt[y][x]->getID();
}

void Mapa::moveEnt(int xAtual, int yAtual, int xAjuste, int yAjuste)
{
	/*
	delete mapaEnt[yAtual + yAjuste][xAtual + xAjuste];
	mapaEnt[yAtual + yAjuste][xAtual + xAjuste] = mapaEnt[yAtual][xAtual];
	mapaEnt[yAtual][xAtual] = nullptr;
	*/
	delete mapaEnt[yAtual + yAjuste][xAtual + xAjuste];
	//EntidadesMortas.insert(yAtual + yAjuste, xAtual + xAjuste);

	mapaEnt[yAtual + yAjuste][xAtual + xAjuste] = mapaEnt[yAtual][xAtual];
	mapaEnt[yAtual][xAtual] = nullptr;
}

void Mapa::Draw()
{
	int i, j;
	for (i = 0; i < largura; i++) {
		for (j = 0; j < altura; j++) {
			if (mapaEnt[i][j] != nullptr) {
				window->draw(mapaEnt[i][j]->getImagem());
			}
		}
	}
}

void Mapa::Executar()
{
	int i, j;
	for (j = 0; j < altura - 1; j++) {
		for (i = 0; i < largura - 2; i++) {
			if (mapaEnt[i][j] != nullptr) {
				/*
				for (auto x : EntidadesMortas) {
					cout << x.first << " " << x.second << endl;
				}
				*/
				mapaEnt[i][j]->Executar();
			}
		}
	}
}

void Mapa::setVida(int x, int y, int vidaset)
{
	cout << "setvida chamado" <<endl;
	mapaEnt[y][x]->setVida(vidaset);
	if (mapaEnt[y][x]->getVida() < 1 ) {
		cout << "entidade vida = 0" << endl;
		//mudança
		delete mapaEnt[y][x];
		//mapaEnt[y][x]->idEntidade->~Entidade();
		mapaEnt[y][x] = nullptr;
	}
}


int Mapa::getMapaAltura()
{
	return altura;
}

int Mapa::getMapaLargura()
{
	return largura;
}

//somente debug
void Mapa::printMapa()
{
	int i, j;
	cout << "imprimindo mapa struct" << endl;
	for (i = 0; i < largura; i++) {
		for (j = 0; j < altura; j++) {
			if (mapaEnt[i][j] != nullptr)
				cout << mapaEnt[i][j]->getID() << "  ";
			else cout << "0  ";
		}
		cout << endl;
	}
}

int Mapa::getJogadorPos(int y)
{
	int i, j;
	
		for (j = 0; j < altura; j++) {
			if (mapaEnt[y][j] != nullptr && (mapaEnt[y][j]->getID() == IdsEntidades::Jogador1 || mapaEnt[y][j]->getID() == IdsEntidades::Jogador2))
				return j;
		}
	
	return -1;
}
