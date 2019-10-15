#ifndef TELA_H
#define TELA_H

#include <windows.h>
#include "stdlib.h"

class Tela
{
public:
    void exibirTela(void);

protected:
    int opcao;
    HINSTANCE hInstance;
};

#endif // INICIO_H

