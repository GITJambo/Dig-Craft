#pragma once
#include "Stdafx.h"

class Jogo;
class Menu
{
private:
	sf::Font fonte;
	int tipo;
	int max;
	sf::Text* textos;
	sf::RectangleShape Background;
	sf::Texture texturaBg;
	sf::Text nome;
	sf::RenderWindow* window;
	Jogo* jogo;
	int posicao;
	bool aberto;
public:
	Menu(int tipoN, sf::RenderWindow* windowN,Jogo* jogoN);
	~Menu();
	void Desenha();
	void setTipo(int tipoN);
	void MoveCima();
	void MoveBaixo();
	void Selecionar();
	bool getAberto();

};