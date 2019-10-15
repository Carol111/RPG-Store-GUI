#ifndef CONSUMIVEL_H
#define CONSUMIVEL_H

#include "Item.h"
#include <iostream>
#include <cstring>
using namespace std;

class Consumivel : public Item
{
public:
    Consumivel();
    void setValores(string,
                    int,
                    int,
                    int,
                    int,
                    char,
                    bool,
                    string,
                    int);
    int getHp(void);
    int getMp(void);
    char getStatus(void);
    bool getTudo(void);
    string getDescricao(void);

private:
    int hp;
    int mp;
    char status;
    bool tudo;
    string descricao;
};
#endif // CONSUMIVEL_H
