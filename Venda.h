#ifndef VENDA_H
#define VENDA_H

#include <windows.h>
#include "Tela.h"
#include "Jogador.h"
#include "Loja.h"

class Venda : public Tela
{
public:
    Venda(void);
    ~Venda(void);
    void criarBotoes(HWND, LPARAM);
    void venda(Jogador*, Loja*, Inventario*, HDC);
    void exibirTela(HDC, Jogador*, Inventario*);
    void exibirBotoes();
    void esconderBotoes();
private:
    int opcaoTipo;
    char texto[20];
    HFONT font;

    HWND quantidade;
    HWND realizaVenda;
    HWND retorno;

    HANDLE bitmapRealizaVenda;
    HANDLE bitmapRetorno;
};

#endif // VENDA_H
