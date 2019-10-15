#ifndef INICIO_H
#define INICIO_H

#include <windows.h>
#include "Tela.h"
#include "Jogador.h"
#include "Compra.h"
#include "Venda.h"
#include "Loja.h"
#include "Inventario.h"


class Inicio : public Tela
{
public:
    Inicio(void);
    ~Inicio(void);
    void exibirTela(HWND, HDC);
    void exibirBotoes(HWND);

private:
    HWND comprar;
    HWND vender;
    HWND sair;

    HANDLE bitmapCompra;
    HANDLE bitmapVenda;
    HANDLE bitmapSair;



};

#endif // INICIO_H

