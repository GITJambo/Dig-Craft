#include "ListaEntidades.h"

ListaEntidades::ListaEntidades()
{
}

ListaEntidades::~ListaEntidades()
{
}

void ListaEntidades::Inserir(Entidade* ePtr)
{
	LDE.inserirElemento(ePtr);
}

void ListaEntidades::Remover(Entidade* ePtr)
{
	LDE.removerElemento(ePtr);
}

void ListaEntidades::Listar()
{

}
