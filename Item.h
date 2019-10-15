#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>

using namespace std;

class Item
{
public:
    void setValores(string,
                    int,
                    int);
    void setQuantidade(int);
    string getNome(void);
    int getValorDeCompra(void);
    int getValorDeVenda(void);
    int getQuantidade(void);
    char getTipo(void);
    int getID(void);

protected:
    char tipo;
    string nome;
    int valorDeCompra;
    int valorDeVenda;
    int quantidade;
    int iD;
};
#endif // ITEM_H
