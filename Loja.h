#ifndef LOJA_H
#define LOJA_H

#include "Consumivel.h"
#include "Equipamento.h"
#include "Inventario.h"
#include "Item.h"
#include "Bolsa.h"
#include "Jogador.h"
#include <stdlib.h>
#include <windows.h>
#include <commctrl.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstring>

class Loja
{
public:
    Loja(void);
    ~Loja(void);
    void exibirDescricaoItem(HDC,HWND);
    void vender(Jogador*, Inventario*, int, HDC);
    bool verificarQuantidadeDeOuro(Jogador*, int, int);
    void criaLista(HWND);
    void exibeLista(int);
    void escondeLista(void);
    void comprar(Jogador*, Inventario*, int, HDC);
    HWND comparaListView();

private:
    Equipamento listaArmas[10];
    Equipamento listaEscudos[5];
    Equipamento listaElmos[5];
    Equipamento listaArmaduras[5];
    Equipamento listaAcessorios[5];
    Consumivel listaConsumo[5];
    Bolsa listaBolsas[2];

    // Auxiliares
    HICON item;
    LVITEM novo;
    LVCOLUMN auxLista;
    int listaSelecionada;
    int index;
    char strAux[20];
    HICON iconItem;
    HFONT font;

    // Lista a ser exibida
    HWND listViewArma;
    HWND listViewEscudo;
    HWND listViewElmo;
    HWND listViewArmadura;
    HWND listViewAcessorio;
    HWND listViewConsumo;
    HWND listViewBolsa;

    // Listas com as imagens dos itens
    HIMAGELIST itemArma;
    HIMAGELIST itemEscudo;
    HIMAGELIST itemElmo;
    HIMAGELIST itemArmadura;
    HIMAGELIST itemAcessorio;
    HIMAGELIST itemConsumo;
    HIMAGELIST itemBolsa;
};
#endif // LOJA_H
