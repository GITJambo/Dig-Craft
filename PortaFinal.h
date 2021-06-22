#pragma once
#include "Entidade.h"
class PortaFinal : public Entidade
{
private:
	bool encostou = false;
public:
	PortaFinal(int xN, int yN, Mapa* mapaN);
	~PortaFinal();
	void Executar();
	void Arredores();
	bool getEncostou();
};

