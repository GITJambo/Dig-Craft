#pragma once

#include "Entidade.h"
#include "Stdafx.h"

class Personagem : public Entidade
{
protected:
	int tempo;
	int direcao;

	short int AcaoCoolDown = 0;
	short int numFramesAcao = 16;

	bool Andando = false;
	bool Caindo = false;

	sf::Texture animacao[10];
public:
	Personagem(int xN = 0, int yN = 0,  Mapa* mPtr = nullptr);
	~Personagem();
	//virtual void Move();

	virtual void Arredor_Cair();
	virtual void Animacao_Move(float posX, float posY);
};
