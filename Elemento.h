#pragma once


template <class tipo> class Elemento{
private:
	Elemento<tipo>* pProx;
	tipo info;
public:
	Elemento();
	~Elemento();

	void setProximo(Elemento<tipo>*);
	Elemento<tipo>* getProximo();

	void setInfo(tipo);
	tipo getInfo();
};

template<class tipo>
inline Elemento<tipo>::Elemento()
{
	info = nullptr;
	pProx = nullptr;
}

template<class tipo>
inline Elemento<tipo>::~Elemento()
{
	info = nullptr;
	pProx = nullptr;
}

template<class tipo>
inline void Elemento<tipo>::setProximo(Elemento<tipo>*Pp)
{
	pProx = Pp;
}

template<class tipo>
inline Elemento<tipo>* Elemento<tipo>::getProximo()
{
	return pProx;
}

template<class tipo>
inline void Elemento<tipo>::setInfo(tipo pI)
{
	info = pI;
}

template<class tipo>
inline tipo Elemento<tipo>::getInfo()
{
	return info;
}