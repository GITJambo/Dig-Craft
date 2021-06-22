#pragma once
#include "Personagem.h"
class Projetil;


class Robo : public Personagem
{
private:
	Projetil* projetil;
public:
	Robo(int xN , int yN , Mapa* mPtr );
	~Robo();
	void Executar();
	void Atirar();
	void Move();
	void Arredor_Cair();
};

