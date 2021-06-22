
#include "Menu.h"
#include "Jogo.h"

Menu::Menu(int tipoN, sf::RenderWindow* windowN, Jogo* jogoN)
{
	jogo = jogoN;
	aberto = true;
	posicao = 0;
	window = windowN;
	setTipo(tipoN);
	if (fonte.loadFromFile("Dirt Road.ttf"))
		nome.setFont(fonte);
	nome.setString("DigCraft");
	nome.setCharacterSize(100);
	nome.setPosition(1300 / 2.f - 200, 10.f);
	nome.setFillColor(sf::Color(218, 165, 32, 255));
	nome.setOutlineThickness(3);
	nome.setOutlineColor(sf::Color::Black);
	texturaBg.loadFromFile("images/backgroundCastles.png");
	Background.setTexture(&texturaBg);
	Background.setSize(sf::Vector2f(1300.f, 700.f));
	Background.setSize(sf::Vector2f(1300.f, 700.f));
	Background.setFillColor(sf::Color(147, 112, 219));
}

Menu::~Menu()
{
	delete window;
}
void Menu::setTipo(int tipoN)
{
	aberto = true;
	posicao = 0;
	tipo = tipoN;
	if (tipo == 0)
		aberto = false;
	else if (tipo == 1)
	{
		max = 3;
		textos = new sf::Text[max];
		for (int i = 0; i < max; i++)
		{
			textos[i].setFont(fonte);
			textos[i].setOutlineColor(sf::Color::Black);
			textos[i].setOutlineThickness(2);
			textos[i].setFillColor(sf::Color::White);
			textos[i].setPosition(sf::Vector2f(500.f, (600 - (max * 100)) + 100.f * i));
		}
		textos[0].setString("Carregar Jogo");
		textos[1].setString("Novo Jogo");
		textos[2].setString("Sair");

	}
	else if (tipo == 2)
	{
		max = 3;
		//textos = new sf::Text[max];
		for (int i = 0; i < max; i++)
		{
			textos[i].setFont(fonte);
			textos[i].setOutlineColor(sf::Color::Black);
			textos[i].setOutlineThickness(2);
			textos[i].setFillColor(sf::Color::White);
			textos[i].setPosition(sf::Vector2f(600.f, (700 - (max* 100)) + 100 * i));
		}
		textos[0].setString("Retornar ao Jogo");
		textos[1].setString("Menu Principal");
		textos[2].setString("Sair");

	}
	else if (tipo == 3)
	{
		max = 3;
		//textos = new sf::Text[max];
		for (int i = 0; i < max; i++)
		{
			textos[i].setFont(fonte);
			textos[i].setOutlineColor(sf::Color::Black);
			textos[i].setOutlineThickness(2);
			textos[i].setFillColor(sf::Color::White);
			textos[i].setPosition(sf::Vector2f(600.f, (700 - (max * 100.f)) + 100.f * i));
		}
		textos[0].setString("1 Jogador");
		textos[1].setString("2 Jogadores");
		textos[2].setString("Voltar");

	}
	textos[posicao].setOutlineColor(sf::Color::Red);
	textos[posicao].setOutlineThickness(5);
}


void Menu::Desenha()
{
	window->setView(window->getDefaultView());
	window->draw(Background);
	window->draw(nome);
	for (int i = 0; i < max; i++)
		window->draw(textos[i]);

}

void Menu::MoveCima()
{
	textos[posicao].setOutlineColor(sf::Color::Black);
	textos[posicao].setOutlineThickness(2);
	posicao--;
	if (posicao<0)
	{
		posicao = max - 1;
	}
	textos[posicao].setOutlineColor(sf::Color::Red);
	textos[posicao].setOutlineThickness(5);
}
void Menu::MoveBaixo()
{

	textos[posicao].setOutlineColor(sf::Color::Black);
	textos[posicao].setOutlineThickness(2);
	posicao++;
	if (posicao >= max)
	{
		posicao = 0;
	}
	textos[posicao].setOutlineColor(sf::Color::Red);
	textos[posicao].setOutlineThickness(5);
}


void Menu::Selecionar()
{
	cout << tipo;
	//Menu Inicial

	if (tipo == 1)
	{
		if (posicao == 1)
		{
			setTipo(3);
		}
		if (posicao == 2)
			window->close();
	}
	//Menu pause
	else if (tipo == 2)
	{
		if (posicao == 0)
			aberto = false;
		if (posicao == 1)
			setTipo(1);
		if (posicao == 2)
			window->close();
	}
	//Menu escolher dois jogadores
	else if (tipo == 3)
	{
		if (posicao == 0)
		{
			aberto = false;
			jogo->setDoisJog(false);
		}
		if (posicao == 1)
		{
			aberto = false;
			jogo->setDoisJog(true);
		}
	}
	
}
bool Menu::getAberto()
{
	return aberto;
}
