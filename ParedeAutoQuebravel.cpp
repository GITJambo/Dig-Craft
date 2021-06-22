#include "ParedeAutoQuebravel.h"

ParedeAutoQuebravel::ParedeAutoQuebravel(int xN, int yN, Mapa* mapaN) :
	Obstaculo(xN, yN, mapaN),
	trigger(0)
{
	imagem.setFillColor(sf::Color(168, 147, 125));
}
ParedeAutoQuebravel::~ParedeAutoQuebravel()
{

}
void ParedeAutoQuebravel::Executar()
{
	Arredores();
}

void ParedeAutoQuebravel::Arredores()
{
	if ((mapa->getEntId(x, y - 1) == IdsEntidades::Jogador2 || mapa->getEntId(x, y - 1) == IdsEntidades::Jogador1))
	{
		if (trigger == 0)
		trigger = 1;
	}
	else if (trigger == 1)
	{
		mapa->moveEnt(x, y, -x, -y);
	}
}