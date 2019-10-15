#ifndef COMPRA_H
#define COMPRA_H

#include <windows.h>
#include <commctrl.h>
#include "Tela.h"
#include "Jogador.h"
#include "Loja.h"

class Compra : public Tela
{
public:
    Compra(void);
    ~Compra(void);
    void criarBotoes(HWND,LPARAM);
    HWND comparaEdit();
    void esconderBotoes(void);
    void exibirTela(Loja*);
    void exibirTextoLista(HDC, Jogador*, Loja*);
    void compra(Jogador*, Loja*, Inventario*, HDC);
    void exibirBotoes(void);
private:
    HWND realizaCompra;
    HWND retorno;
    HWND armas;
    HWND escudo;
    HWND elmo;
    HWND armadura;
    HWND acessorio;
    HWND consumo;
    HWND bolsa;

    HWND quantidade;

    HANDLE bitmapRealizaCompra;
    HANDLE bitmapRetorno;
    HANDLE bitmapArmas;
    HANDLE bitmapEscudo;
    HANDLE bitmapElmo;
    HANDLE bitmapArmadura;
    HANDLE bitmapAcessorio;
    HANDLE bitmapConsumo;
    HANDLE bitmapBolsa;

};

#endif // COMPRA_H
