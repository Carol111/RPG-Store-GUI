#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Item.h"
#include "Equipamento.h"
#include "Consumivel.h"
#include "Bolsa.h"
#include "rpgResource.h"
#include <stdlib.h>
#include <windows.h>
#include <commctrl.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstring>

class Inventario
{
public:
    Inventario();
    ~Inventario();
    //Sobrecarga de método inserirItem (Equipamento ou Consumivel)
    bool inserirItem(Equipamento*,int);
    bool inserirItem(Consumivel*,int);
    //Sobrecarga de método removerItem (Equipamento ou Consumivel)
    void criaListaInventario(HWND);
    void criaListaBolsa(HWND);
    bool removerItemE(int,int);
    bool removerItemC(int,int);
    bool inserirBolsa(Bolsa);
    bool removerBolsa(int);
    int getSelected(void);
    int getIndex(void);
    int setIndex(int);
    void exibirConteudo(void);
    void exibirBolsa(void);
    void exibirDados(void);
    void exibirDescricaoItem(HDC, HWND);
    HWND comparaListBolsa(void);
    HWND comparaListInventario(void);
    void esconderListas(void);
    int valorItem(int);
    int valorBolsa(int);

private:
    int capacidadeItens;
    int capacidadeBolsas;
    int espacoOcupadoItens;
    int espacoOcupadoBolsas;
    Item *conteudo; // inicialmente deve ter 20 espaços e no máximo 50
    Bolsa bolsasDoInventario[3]; // carrega no máximo 3 bolsas, Grandes (+10 espaços) ou Pequenas (+5 espaços)

    // Auxiliares
    HICON item;
    LVITEM novo;
    LVCOLUMN auxLista;
    int selected;
    int index;
    char strAux[20];
    HFONT font;

    // Lista a ser exibida
    HWND listViewInventario;
    HWND listViewBolsa;

    // Listas com as imagens dos itens
    HIMAGELIST itemInventario;
    HIMAGELIST itemBolsa;
};
#endif // INVENTARIO_H
