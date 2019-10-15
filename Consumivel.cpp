#include "Consumivel.h"

#include <iostream>
#include <cstring>
using namespace std;

Consumivel::Consumivel()
{
    tipo = 'c';
    nome = "";
    valorDeCompra = 0;
    valorDeVenda = 0;
    hp = 0;
    mp = 0;
    status = 'x';
    tudo = false;
    descricao = "";
    quantidade = 0;
    iD = 500; // ID do primeiro item
}

void Consumivel::setValores(string novoNome,
                            int novoValorDeCompra,
                            int novoValorDeVenda,
                            int novoHp,
                            int novoMp,
                            char novoStatus,
                            bool novoTudo,
                            string novoDescricao,
                            int novoID)
{
    nome = novoNome;
    valorDeCompra = novoValorDeCompra;
    valorDeVenda = novoValorDeVenda;
    hp = novoHp;
    mp = novoMp;
    status = novoStatus;
    tudo = novoTudo;
    descricao = novoDescricao;
    iD = novoID;
}

int Consumivel::getHp()
{
    return hp;
}

int Consumivel::getMp()
{
    return mp;
}

char Consumivel::getStatus()
{
    return status;
}

bool Consumivel::getTudo()
{
    return tudo;
}

string Consumivel::getDescricao()
{
    return descricao;
}
