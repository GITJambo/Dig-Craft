#pragma once
#include "Personagem.h"
class Zumbi : public Personagem
{
private:
	int tempoAtaque = 0;
	bool playerproximo = false;
public:
	Zumbi(int xN = 0, int yN = 0, Mapa* mPtr = nullptr);
	~Zumbi();
	void Executar();
	void Move();
	
	void Arredores();
	void Arredor_PlayerProximo();
	void Arredor_Cair();
	void Atacar();

};

