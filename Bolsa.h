#ifndef BOLSA_H
#define BOLSA_H

#include "Item.h"
#include <iostream>
#include <cstring>

using namespace std;

class Bolsa : public Item
{
public:
    Bolsa();
    void setValores(string,
                    int,
                    int,
                    int,
                    int);
    int getCapacidade(void);

private:
    int capacidade;
};
#endif // BOLSA_H
