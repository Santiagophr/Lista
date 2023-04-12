#ifndef LLSE_H
#define LLSE_H

#include <no.h>
#include <QString>

namespace ped{
class LLSE //Classe Lista Linear Simplesmente Encadeada
{
private:
    No* inicio;
    int quantidadeElementos;
    int posicao;
public:
    LLSE();
    bool estaVazia()const;

    void inserirInicio(int elemento);
    int retirarInicio();
    int acessarInicio()const;

    QString obterDadosLista()const;

    int acessarFim()const;
    void inserirFim(int elemento);
    int retirarFim();

    int acessarPosicao(int posicao);
    void inserirPosicao(int elemento, int posicao);
    int retirarPosicao(int posicao);

    int getQuantidadeElementos() const;

};
}

#endif // LLSE_H
