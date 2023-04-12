#include "llse.h"

namespace ped{

int LLSE::getQuantidadeElementos() const
{
   return quantidadeElementos;
}
LLSE::LLSE():
    inicio(0),
    quantidadeElementos(0)
{

}

bool LLSE::estaVazia()const
{
    return (quantidadeElementos == 0);
}

int LLSE::acessarInicio()const
{
    if(estaVazia()) throw QString("A lista esta vazia!");
    return inicio->getDado();
}
int LLSE::retirarInicio()
{
    if(estaVazia()) throw QString("A lista esta vazia!");
    quantidadeElementos--;
    No* aux = inicio;
    inicio = aux->getProximo();
    int valor = aux->getDado();
    delete aux;
    return valor;
}

void LLSE::inserirInicio(int elemento)
{
    try {
        No *aux = new No(elemento);
        quantidadeElementos++;
        if(inicio != nullptr){
            aux->setProximo(inicio);
        }
        inicio = aux;
    } catch (std::bad_alloc &erro) {
        throw QString("No nao foi criado!");
    }

}
QString LLSE::obterDadosLista()const
{
    QString dados = "| ";
    No* aux = inicio;
    for(int i=0;i<quantidadeElementos;i++)
    {
        dados += QString::number(aux->getDado());
        if(i < quantidadeElementos -1)
        {
            dados += " | -> | ";
            aux = aux->getProximo();
        }
    }
    dados += " |";
    return dados;
}
int LLSE::acessarFim()const
{
    if(estaVazia()) throw QString("Erro ao acessar fim!");
    No* aux = inicio;
    for(int pos=0; pos<quantidadeElementos-1; pos++)
    {
        aux = aux->getProximo();
    }
    return aux->getDado();
}
void LLSE::inserirFim(int elemento)
{
    try {
        No *novo = new No(elemento);
        if(estaVazia())
        {
            quantidadeElementos++;
            inicio = novo;
        } else
          {  No *aux = inicio;
            for(int pos = 0; pos < quantidadeElementos-1; pos++)
            {
                aux = aux->getProximo();
            }
            aux->setProximo(novo);
            quantidadeElementos++;
          }
    } catch (std::bad_alloc) {
        throw QString("Erro ao inserir no fim!");
    }
}
int LLSE::retirarFim()
{
    if(estaVazia()) throw QString("Impossivel tirar dados de uma lista vazia!");
    if(quantidadeElementos == 1)
    {
        int valor = inicio->getDado();
        delete inicio;
        quantidadeElementos = 0;
        inicio = 0;
        return valor;
    }
    No* aux = inicio;
    for(int pos=0; pos<quantidadeElementos-2; pos++)
    {
        aux = aux->getProximo();
    }
    int valor = aux->getProximo()->getDado();
    delete aux->getProximo();
    aux->setProximo(0);
    quantidadeElementos--;
    return valor;
}
int LLSE::acessarPosicao(int posicao)
{
    if(estaVazia()) throw QString("A lista esta vazia!");
    if(posicao < 0 || posicao >= quantidadeElementos) throw QString("Nao pode ser acessado!");
    if(posicao == 0) return acessarInicio();
    if(posicao == quantidadeElementos-1) return acessarFim();
    No *aux = inicio;
    for(int i=0; i<posicao; i++)
    {
        aux = aux->getProximo();
    }
    return aux->getDado();
}
void LLSE::inserirPosicao(int elemento, int posicao)
{
    try {
        if(posicao < 0 || posicao > quantidadeElementos) throw QString("A posição desejada não existe");
        if(posicao == 0) return inserirInicio(elemento);
        if(posicao == quantidadeElementos) return inserirFim(elemento);

        No *aux = new No(elemento);
        No *anterior = inicio;

        for(int pos = 0; pos < posicao - 1; pos++)
        {
            anterior = anterior->getProximo();
        }

        aux->setProximo(anterior->getProximo());
        anterior->setProximo(aux);
        quantidadeElementos++;
    }
    catch (std::bad_alloc &erro)
    {
        throw QString("Nó não foi criado!");
    }
}
int LLSE::retirarPosicao(int posicao)
{
    if(estaVazia()) throw QString("A lista está vazia!");
    if(posicao < 0 || posicao >= quantidadeElementos) throw QString("A posição desejada não existe");
    if(posicao == 0) return retirarInicio();
    if(posicao == quantidadeElementos - 1) return retirarFim();

    No *aux = inicio;
    No *anterior = nullptr;

    for(int pos = 0; pos < posicao; pos++)
    {
        anterior = aux;
        aux = aux->getProximo();
    }
    anterior->setProximo(aux->getProximo());
    int valor = aux->getDado();
    delete aux;
    quantidadeElementos--;

    return valor;
}
}
