#include "Equipamento.h"

Equipamento::Equipamento()
{
    tipo = 'e';
    nome = "";
    valorDeCompra = 0;
    valorDeVenda = 0;
    especializacao = "";
    requerLevel = 0;
    atk = 0;
    mPow = 0;
    def = 0;
    res = 0;
    agi = 0;
    quantidade = 1;
    iD = 500; // ID do primeiro item
}

void Equipamento::setValores(string novoNome,
                             int novoValorDeCompra,
                             int novoValorDeVenda,
                             string novaEspecializacao,
                             int novoRequerLevel,
                             int novoAtk,
                             int novoMPow,
                             int novoDef,
                             int novoRes,
                             int novoAgi,
                             int novoID)
{
    nome = novoNome;
    valorDeCompra = novoValorDeCompra;
    valorDeVenda = novoValorDeVenda;
    especializacao = novaEspecializacao;
    requerLevel = novoRequerLevel;
    atk = novoAtk;
    mPow = novoMPow;
    def = novoDef;
    res = novoRes;
    agi = novoAgi;
    iD = novoID;
}

string Equipamento::getEspecializacao()
{
    return especializacao;
}

int Equipamento::getRequerLevel()
{
    return requerLevel;
}

int Equipamento::getAtk()
{
    return atk;
}

int Equipamento::getMPow()
{
    return mPow;
}

int Equipamento::getDef()
{
    return def;
}

int Equipamento::getRes()
{
    return res;
}

int Equipamento::getAgi()
{
    return agi;
}
