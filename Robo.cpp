#include "Robo.h"
#include "Projetil.h"
#include "IdsEntidades.h"
Robo::Robo(int xN, int yN, Mapa* mPtr) :
	Personagem(xN, yN, mPtr)
{
	x = xN;
	y = yN;
	direcao = 1;
	id = IdsEntidades::Robo;
	animacao[1].loadFromFile("images/Wizard/i1.png");
	animacao[2].loadFromFile("images/Wizard/i2.png");
	animacao[3].loadFromFile("images/Wizard/i3.png");
	animacao[4].loadFromFile("images/Wizard/i4.png");
	animacao[5].loadFromFile("images/Wizard/i1.png");
	animacao[6].loadFromFile("images/Wizard/i2.png");
	animacao[7].loadFromFile("images/Wizard/i3.png");
	animacao[8].loadFromFile("images/Wizard/i4.png");
	imagem.setTexture(&animacao[1]);
	imagem.setPosition(sf::Vector2f(x * 100.f, y * 100.f));
}

Robo::~Robo()
{
	cout << "robo morto" << endl;
}

void Robo::Executar()
{
	if(!Caindo)Arredor_Cair();
	if (tempo >= 120 && mapa->getJogadorPos(y) != -1) {

		tempo = 0;
		

		Atirar();
	}
	else if (tempo == 60)
	{
		if (mapa->getJogadorPos(y) > x)
		{
			direcao = 1;
			imagem.setScale(sf::Vector2f(1, 1.f));
			imagem.setOrigin(0.f, 0.f);
		}
			
		else
		{
			if (direcao != -1)
			{
				imagem.setScale(sf::Vector2f(-1, 1.f));
				imagem.setOrigin(100.f, 0.f);
			}
				
			direcao = -1;
		}
	}
	tempo++;

		
	if (Caindo == true) Animacao_Move(0.f, 100.f);
	if (AcaoCoolDown > 0) AcaoCoolDown--;
}

void Robo::Atirar()
{
	if (mapa->getEntId(x + direcao, y) == 0 ){
		
		projetil = new Projetil(x + direcao, y, direcao, mapa);
		mapa->setEnt(x + 1 * direcao, y,static_cast<Entidade*>(projetil));

	}
}

void Robo::Move()
{
}

void Robo::Arredor_Cair()
{
	if (AcaoCoolDown == 0)
	{
		if (mapa->getEntId(x, y + 1) == IdsEntidades::Vazio) {
			AcaoCoolDown = numFramesAcao;
			Caindo = true;

			mapa->moveEnt(x, y, 0, 1);
			y++;
		}
	}

}
