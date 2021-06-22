#include "Chefao.h"
#include "PilardeFogo.h"
Chefao::Chefao(int xN, int yN, Mapa* mPtr) :
	Personagem(xN, yN, mPtr)
{
	id = IdsEntidades::Chefe;
	imagem.setSize(sf::Vector2f(200.f, 200.f));
	imagem.setPosition(sf::Vector2f(100.f*x-100, 100.f*y-100));
	animacao[0].loadFromFile("images/Chefao/d1.png");
	animacao[1].loadFromFile("images/Chefao/d2.png");
	animacao[2].loadFromFile("images/Chefao/d3.png");
	imagem.setTexture(&animacao[0]);
}

Chefao::~Chefao()
{
	cout << "chefe muerto" << endl;
}
void Chefao::Spawn_PilardeFogo(){
	tempo = 0;
	Pilar = new PilardeFogo(x - 3, y, mapa);
	mapa->setEnt(x - 3, y, Pilar);
	Pilar = new PilardeFogo(x - 1, y, mapa);
	mapa->setEnt(x - 1, y, Pilar);
	Pilar = new PilardeFogo(x - 5, y, mapa);
	mapa->setEnt(x - 5, y, Pilar);
}

void Chefao::Executar()
{
	tempo++;
	tempoAnimacao++;
	Animacao_Idle();
	//cout << "chefetempo" << tempo << endl;
	if (tempo > 700) Spawn_PilardeFogo();
}

void Chefao::Animacao_Idle()
{
	
	//cout << tempoAnimacao << endl;
	if (tempoAnimacao == 1) {
		imagem.setTexture(&animacao[0]);
	}
	else if (tempoAnimacao == duracaoAnimacao) {
		imagem.setTexture(&animacao[1]);
	}
	else if (tempoAnimacao == duracaoAnimacao * 2) {
		imagem.setTexture(&animacao[2]);
	}
	else if (tempoAnimacao == duracaoAnimacao * 3) {
		imagem.setTexture(&animacao[1]);
	}
	else if (tempoAnimacao > duracaoAnimacao*4) tempoAnimacao = 0;
}
