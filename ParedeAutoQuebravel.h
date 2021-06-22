#pragma once
#include "IdsEntidades.h"
#include "Obstaculo.h"
#include "Mapa.h"
class ParedeAutoQuebravel : public Obstaculo
{
private:
	int trigger;
public:
	ParedeAutoQuebravel(int xN = 0, int yN = 0, Mapa* mapaN = nullptr);
	~ParedeAutoQuebravel();
	void Executar();
	void Arredores();
};

