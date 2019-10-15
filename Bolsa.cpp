#include "Bolsa.h"

Bolsa::Bolsa()
{
    nome = "";
    valorDeCompra = 0;
    valorDeVenda = 0;
    capacidade = 0;
    iD = 500;
}
void Bolsa::setValores(string novoNome,
                       int novoValorDeCompra,
                       int novoValorDeVenda,
                       int novaCapacidade,
                       int novoID)
{
    nome = novoNome;
    valorDeCompra = novoValorDeCompra;
    valorDeVenda = novoValorDeVenda;
    capacidade = novaCapacidade;
    iD = novoID;
}

int Bolsa::getCapacidade()
{
    return capacidade;
}
