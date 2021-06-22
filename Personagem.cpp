#include "Personagem.h"
Personagem::Personagem(int xN, int yN, Mapa* mPtr) :
	Entidade(xN, yN, mPtr)
{
	tempo = 0;
	direcao = 1;
}
Personagem::~Personagem()
{

}

void Personagem::Animacao_Move(float posX, float posY)
{
    if (AcaoCoolDown > 0) {
        imagem.move(posX / numFramesAcao, posY / numFramesAcao);
        if      (AcaoCoolDown <= numFramesAcao * 1 / 4) imagem.setTexture(&animacao[5]);
        else if (AcaoCoolDown <= numFramesAcao * 2 / 4) imagem.setTexture(&animacao[6]);
        else if (AcaoCoolDown <= numFramesAcao * 3 / 4) imagem.setTexture(&animacao[7]);
        else if (AcaoCoolDown <= numFramesAcao * 4 / 4) imagem.setTexture(&animacao[8]);
    }
    else {
        Andando = false;
        Caindo = false;
    }
}
void Personagem::Arredor_Cair()
{

}