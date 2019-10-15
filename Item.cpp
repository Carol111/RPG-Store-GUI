#include "Item.h"

void Item::setValores(string novoNome,
                      int novoValorCompra,
                      int novoValorVenda)
{
    nome = novoNome;
    valorDeCompra = novoValorCompra;
    valorDeVenda = novoValorVenda;
}

void Item::setQuantidade(int novaQuantidade)
{
    quantidade = novaQuantidade;
}

string Item::getNome()
{
    return nome;
}

int Item::getValorDeCompra()
{
    return valorDeCompra;
}

int Item::getValorDeVenda()
{
    return valorDeVenda;
}

int Item::getQuantidade()
{
    return quantidade;
}

char Item::getTipo()
{
    return tipo;
}

int Item::getID()
{
    return iD;
}
