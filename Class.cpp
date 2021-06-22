
#include <iostream>
#include <string>
using namespace std;

int main(){
    string NomeArquivo = "teste.txt";
    string line;
    ifstream myfile(NomeArquivo);
    int alt, larg, posi;
    if (myfile.is_open())
    {
        getline(myfile, line);
        posi = line.find(' ');
        larg = stoi(line.substr(0, posi));
        alt = stoi(line.substr(posi + 1));
        mapa = new Mapa(larg, alt);
        aux = new Entidade(0, 0);
        int j = 0;
        while (getline(myfile, line))
        {
            for (int i = 0; i < larg; i++)
            {
                if (line[i] == '3'||line[i] == '4')
                {
                    obstaculos = new ParedeQuebravel(i, j);
                    obstaculos->setID(line[i] - 48);
                    mapa->setEntidade(i, j, static_cast<Entidade*>(obstaculos));
                }
                else if (line[i] == '1')
                {
                    p1->setX(i);
                    p1->setY(j);
                    p1->setID(1);
                    mapa->setEntidade(i, j, static_cast<Entidade*>(p1));
                }
                else if (p2 != nullptr && line[i] == '2')
                {
                    p2->setID(2);
                    p2->setX(i);
                    p2->setY(j);
                    mapa->setEntidade(i, j, static_cast<Entidade*>(p2));
                }
                else if (line[i] == '6')
                {
                    zumbies = new Zumbi(i, j, mapa);
                    mapa->setEntidade(i, j, static_cast<Entidade*>(zumbies));
                }
            }
            j++;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    p1->setMapa(mapa);
    if(p2!=nullptr)
        p2->setMapa(mapa);
    return 0;
}