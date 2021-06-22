#include "PortaFinal.h"
PortaFinal::PortaFinal(int xN, int yN, Mapa* mapaN) :
	Entidade(xN, yN, mapaN)
{
	encostou = false;
	id = 0;
	texture.loadFromFile("images/Door.png");
	imagem.setTexture(&texture);
}
PortaFinal::~PortaFinal()
{

}

void PortaFinal::Executar()
{
	Arredores();
}

void PortaFinal::Arredores()
{
	if (mapa->getJogadorPos(y) == x)
	{
		encostou = true;
	}
}
bool PortaFinal::getEncostou()
{
	return encostou;
}
