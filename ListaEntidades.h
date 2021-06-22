#pragma once
#include "Lista.h"
#include "Entidade.h"

class ListaEntidades
{
private:
	Lista<Entidade*> LDE;
public:
	ListaEntidades();
	~ListaEntidades();

	void Inserir(Entidade*);
	void Remover(Entidade*);
	void Listar();
};

