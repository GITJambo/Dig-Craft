#pragma once
#include "Elemento.h"
#include "stdafx.h"

template <class tipo> class Lista {

private:
	Elemento<tipo>* pPrimeiro;
	Elemento<tipo>* pUltimo;
	int tamanhoLista;
public:
	Lista();
	~Lista();

	tipo* getElemento(int);
	void inserirElemento(tipo);
	void removerElemento(tipo);
};

template<class tipo>
inline Lista<tipo>::Lista()
{
	tamanhoLista = 0;
	pPrimeiro = nullptr;
	pUltimo = nullptr;
}

template<class tipo>
inline Lista<tipo>::~Lista()	
{
	pPrimeiro = nullptr;
	pUltimo = nullptr;
}

template<class tipo>
inline tipo* Lista<tipo>::getElemento(int pos)
{
	
	if (pos <= tamanhoLista) {
		if (pos == 0) {
			return pPrimeiro->getInfo();
		}
		Elemento<tipo>* aux = new Elemento<tipo>;
		aux = pPrimeiro;
		int i;
		for (i = 0; i <= tamanhoLista; i++) 
			aux = aux->getProximo();
		return aux->getInfo();
	}
	cout << "Erro, Usuario nao esta na lista" << endl;
}

template<class tipo>
inline void Lista<tipo>::inserirElemento(tipo elem){

	if (elem != nullptr) {


		
			cout << "1" << endl;
		if (pPrimeiro == nullptr) {
			cout << "2" << endl;

			pPrimeiro = new Elemento<tipo>; 
			pPrimeiro->setInfo(elem);
			pUltimo = pPrimeiro;
			
		}
		else {
			Elemento<tipo>* aux;
			aux = new Elemento<tipo>;
			aux->setInfo(elem);

			pUltimo->setProximo(aux);
			pUltimo = aux;
		}
		tamanhoLista++;
	}
}
template<class tipo>
inline void Lista<tipo>::removerElemento(tipo elem)
{

	if (elem != nullptr) {
		Elemento<tipo>* aux;
		Elemento<tipo>* anterior;

		
		aux = pPrimeiro;
		anterior = nullptr;

		while (aux->getInfo() != elem ) {
			anterior = aux;
			aux = aux->getProximo();
		}
		if (aux != NULL) {
			cout << "encontrado entidade " << endl;

			if (aux == pPrimeiro) {
				pPrimeiro = aux->getProximo();
			}
			else if (aux == pUltimo) {
				anterior->setProximo(nullptr);
				pUltimo = anterior;
			}
			else {
				anterior->setProximo(aux->getProximo());
			}
			delete aux;
			tamanhoLista--;
		}
	}
}
