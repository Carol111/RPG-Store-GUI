#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H

#include "Item.h"
#include <iostream>
#include <cstring>
using namespace std;

class Equipamento : public Item
{
public:
    Equipamento();
    void setValores(string,
                    int,
                    int,
                    string,
                    int,
                    int,
                    int,
                    int,
                    int,
                    int,
                    int);
    string getEspecializacao(void);
    int getRequerLevel(void);
    int getAtk(void);
    int getMPow(void);
    int getDef(void);
    int getRes(void);
    int getAgi(void);

private:
    string especializacao;
    int requerLevel;
    int atk;
    int mPow;
    int def;
    int res;
    int agi;
};
#endif // EQUIPAMENTO_H
