#include "Obstaculo.h"

Obstaculo::Obstaculo(int xN, int yN, Mapa* mapaN) :
	Entidade(xN, yN, mapaN)
{
	id = IdsEntidades::ParedeQuebravel;
	texture.loadFromFile("images/dirt.jpg");
	imagem.setPosition((float)xN * 100, (float)yN * 100);
	imagem.setTexture(&texture);
}

Obstaculo::~Obstaculo()
{
	cout << "destruiu parede" << endl;
}


