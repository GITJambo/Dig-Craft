#include "Parede_Indestrutivel.h"
#include "Obstaculo.h"

Parede_Indestrutivel::Parede_Indestrutivel(int xN, int yN, Mapa* mapaN) :
	Obstaculo(xN, yN, mapaN)
{
	id = IdsEntidades::Parede;
	texture.loadFromFile("images/cobble.jpg");
	imagem.setPosition((float)xN * 100, (float)yN * 100);
	imagem.setTexture(&texture);
}

Parede_Indestrutivel::~Parede_Indestrutivel()
{
	cout << "destrui parede" << endl;
}


