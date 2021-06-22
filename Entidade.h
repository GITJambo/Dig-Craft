#pragma once
#include <SFML/Graphics.hpp>
#include "IdsEntidades.h"
#include "Mapa.h"
class Entidade
{
protected:
	int id;
	Mapa* mapa;
	int x, y;

	sf::Texture texture;
	sf::RectangleShape imagem;

	int vida;
	bool Vivo = true;

public:
	Entidade(int xN = 0, int yN = 0, Mapa* mapaN = nullptr);
	virtual ~Entidade();
	virtual void Executar();
	virtual void Arredores();
	int getID();

	int getPositionX();
	int getPositionY();

	void setMorto();
	bool getVivo();

	virtual void setPos(int a, int b);
	
	virtual void setVida(int setvida);
	int getVida();

	sf::RectangleShape getImagem();
};

