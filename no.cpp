#include "no.h"

namespace ped{
No *No::getProximo() const
{
    return proximo;
}

void No::setProximo(No *newProximo)
{
    proximo = newProximo;
}

No::No():
    dado(0),
    proximo(0)
{

}
int No::getDado() const
{
    return dado;
}

void No::setDado(int newDado)
{
    dado = newDado;
}
No::No(int dado):
    dado(dado),
    proximo(0)
{

}





}



