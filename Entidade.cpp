#include "Entidade.h"
#include "stdafx.h"


Entidade::Entidade(int xN, int yN, Mapa* mapaN) :
	x(xN),
	y(yN),
	mapa(mapaN)
{
	vida = 1;
	imagem.setSize(sf::Vector2f(100.f, 100.f));
	imagem.setFillColor(sf::Color(255, 255, 255));
	x = xN;
	y = yN;
	id = 0;
	mapa = mapaN;
}

Entidade::~Entidade()
{
	//cout << "desconstruindo entidade" << endl;
}



void Entidade::Executar()
{
}

void Entidade::Arredores()
{
}

int Entidade::getID()
{
	return id;
}

int Entidade::getPositionX()
{
	return x * 100;
}
int Entidade::getPositionY()
{
	return y * 100;
}

void Entidade::setMorto()
{
	Vivo = false;
}

bool Entidade::getVivo()
{
	return Vivo;
}

void Entidade::setPos(int a, int b)
{
	//setar a posicao a partir do x e do y, não do 2f
	x = a;
	y = b;
	imagem.setPosition(a*100.f,b*100.f);
}

void Entidade::setVida(int setvida)
{
	vida += setvida;
}

int Entidade::getVida()
{
	return vida;
}


sf::RectangleShape Entidade::getImagem()
{
	return imagem;
}
