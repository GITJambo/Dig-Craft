#pragma once
#include "stdafx.h"
class EfeitoVisual
{
private:
	sf::RectangleShape imagem;
	sf::RectangleShape barraVida;
	sf::Texture* Vetortextura;
	sf::RenderWindow* window;
	int tipo;
	int tamanhoVetor = 0;
	int* vidas;
	//posicao e direcao da entidade
	short int* direcao;
	int* x;
	int* y;
public:
	EfeitoVisual(sf::RenderWindow* wPtr, int tipoN, int* xN, int* yN, short int* direcaoN, int* numVidas);
	~EfeitoVisual();
	void Executar();
	sf::RectangleShape getImagem();

	void movePosAnimacao(sf::Vector2f pos);
	void SetarNumEfeito(int posicao);
	void DesenharEfeito();

	void setVida();
	//verificar quais funções são uteis teste deletar
};

EfeitoVisual::EfeitoVisual(sf::RenderWindow* wPtr, int tipoN, int* xN, int* yN, short int* direcaoN, int* numVidas)
{
	imagem.setSize(sf::Vector2f(100.f, 100.f));
	window = wPtr;
	tipo = tipoN;
	direcao = direcaoN;
	x = xN;
	y = yN;
	vidas = numVidas;
	if (tipo == 1) {
		int tamanhoVetor = 4;
		Vetortextura = new sf::Texture[tamanhoVetor];
		Vetortextura[0].loadFromFile("images/efeitos/smoke/s1.png");
		Vetortextura[1].loadFromFile("images/efeitos/smoke/s2.png");
		Vetortextura[2].loadFromFile("images/efeitos/smoke/s3.png");
		Vetortextura[3].loadFromFile("images/efeitos/smoke/s4.png");
		barraVida.setFillColor(sf::Color(10, 120, 20));
		barraVida.setPosition(sf::Vector2f(*x * 100.f + 15, *y * 100.f - 10));
		barraVida.setSize(sf::Vector2f(*vidas * 20.f, 12.f));
	}
}

inline EfeitoVisual::~EfeitoVisual()
{

}

inline void EfeitoVisual::Executar()
{
	window->draw(barraVida);

	if (*direcao == -1) {
		imagem.setScale(sf::Vector2f(*direcao, 1));
		imagem.setOrigin(100, 0);
	}
	else {
		imagem.setScale(sf::Vector2f(*direcao, 1));
		imagem.setOrigin(0, 0);
	}

}

inline sf::RectangleShape EfeitoVisual::getImagem()
{
	return imagem;
}

inline void EfeitoVisual::movePosAnimacao(sf::Vector2f pos)
{
	barraVida.move(pos);
}

inline void EfeitoVisual::SetarNumEfeito(int posicao) {
	cout << posicao;
	imagem.setTexture(&Vetortextura[posicao]);
}

inline void EfeitoVisual::DesenharEfeito()
{
	imagem.setPosition(*x * 100.f - 100 * *direcao, *y * 100.f);
	window->draw(imagem);
}


inline void EfeitoVisual::setVida()
{
	barraVida.setSize(sf::Vector2f(20 * *vidas, 12.f));
}#pragma once
