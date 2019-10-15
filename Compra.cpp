#include "Compra.h"
#include "rpgResource.h"
#include <iostream>
#include <stdio.h>
#include <windowsx.h>

Compra::Compra()
{
    // Carregando as Imagens dos Botões
    hInstance = GetModuleHandle(NULL);

    bitmapRealizaCompra = LoadImage(hInstance, MAKEINTRESOURCE(ID_BUTTONREALIZACOMPRA), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
    bitmapRetorno = LoadImage(hInstance, MAKEINTRESOURCE(ID_BUTTONRETORNO), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);

    bitmapArmas = LoadImage(hInstance, MAKEINTRESOURCE(ID_BUTTONARMAS), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
    bitmapEscudo = LoadImage(hInstance, MAKEINTRESOURCE(ID_BUTTONESCUDO), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
    bitmapElmo = LoadImage(hInstance, MAKEINTRESOURCE(ID_BUTTONELMO), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
    bitmapArmadura = LoadImage(hInstance, MAKEINTRESOURCE(ID_BUTTONARMADURA), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
    bitmapAcessorio = LoadImage(hInstance, MAKEINTRESOURCE(ID_BUTTONACESSORIO), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
    bitmapConsumo = LoadImage(hInstance, MAKEINTRESOURCE(ID_BUTTONCONSUMO), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
    bitmapBolsa = LoadImage(hInstance, MAKEINTRESOURCE(ID_BUTTONBOLSA), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
}

Compra::~Compra()
{
    DestroyWindow(realizaCompra);
    DestroyWindow(retorno);
    DestroyWindow(armas);
    DestroyWindow(escudo);
    DestroyWindow(elmo);
    DestroyWindow(armadura);
    DestroyWindow(acessorio);
    DestroyWindow(consumo);
    DestroyWindow(bolsa);
}

HWND Compra::comparaEdit()
{
    return quantidade;
}

void Compra::criarBotoes(HWND hWnd, LPARAM lParam)
{
    // Caixa para entrada de quantidade
    quantidade = CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","1", WS_CHILD|WS_BORDER|ES_NUMBER|BS_FLAT,368,247,70,22,hWnd,NULL,NULL,0);
    SendMessage((HWND)quantidade,(UINT)WM_SETFONT,(WPARAM)GetStockObject(DEFAULT_GUI_FONT),(LPARAM) lParam);

    // Cria botão de opção REALIZACOMPRA
    realizaCompra = CreateWindowEx(0,"BUTTON","Realizar Compra", WS_CHILD|BS_PUSHBUTTON|BS_BITMAP|BS_FLAT,460,245,125,25,hWnd,(HMENU)ID_REALIZACOMPRA,hInstance,0);
    SendMessage(realizaCompra, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bitmapRealizaCompra);

    // Cria botão de opção RETORNO
    retorno = CreateWindowEx(0,"BUTTON","Retornar", WS_CHILD|BS_PUSHBUTTON|BS_BITMAP|BS_FLAT,544,290,41,32,hWnd,(HMENU)ID_RETORNO,hInstance,0);
    SendMessage(retorno, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bitmapRetorno);

    //-------------------------------------------------------------------------------------------------------------------------------------------------------
    // MENU DE LISTA

    // Cria botão de exibição de ARMA
    armas = CreateWindowEx(0,"BUTTON","Arma", WS_CHILD|BS_PUSHBUTTON|BS_BITMAP|BS_FLAT,17,21,41,41,hWnd,(HMENU)ID_ARMAS,hInstance,0);
    SendMessage(armas, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bitmapArmas);

    // Cria botão de exibição de ESCUDO
    escudo = CreateWindowEx(0,"BUTTON","Escudo", WS_CHILD|BS_PUSHBUTTON|BS_BITMAP|BS_FLAT,58,21,41,41,hWnd,(HMENU)ID_ESCUDO,hInstance,0);
    SendMessage(escudo, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bitmapEscudo);

    // Cria botão de exibição de ELMO
    elmo = CreateWindowEx(0,"BUTTON","Elmo", WS_CHILD|BS_PUSHBUTTON|BS_BITMAP|BS_FLAT,99,21,41,41,hWnd,(HMENU)ID_ELMO,hInstance,0);
    SendMessage(elmo, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bitmapElmo);

    // Cria botão de exibição de ARMADURA
    armadura = CreateWindowEx(0,"BUTTON","Armadura", WS_CHILD|BS_PUSHBUTTON|BS_BITMAP|BS_FLAT,140,21,41,41,hWnd,(HMENU)ID_ARMADURA,hInstance,0);
    SendMessage(armadura, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bitmapArmadura);

    // Cria botão de exibição de ACESSORIO
    acessorio = CreateWindowEx(0,"BUTTON","Acessorio", WS_CHILD|BS_PUSHBUTTON|BS_BITMAP|BS_FLAT,181,21,41,41,hWnd,(HMENU)ID_ACESSORIO,hInstance,0);
    SendMessage(acessorio, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bitmapAcessorio);

    // Cria botão de exibição de CONSUMO
    consumo = CreateWindowEx(0,"BUTTON","Consumo", WS_CHILD|BS_PUSHBUTTON|BS_BITMAP|BS_FLAT,222,21,41,41,hWnd,(HMENU)ID_CONSUMO,hInstance,0);
    SendMessage(consumo, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bitmapConsumo);

    // Cria botão de exibição de BOLSA
    bolsa = CreateWindowEx(0,"BUTTON","Bolsa", WS_CHILD|BS_PUSHBUTTON|BS_BITMAP|BS_FLAT,263,21,42,41,hWnd,(HMENU)ID_BOLSA,hInstance,0);
    SendMessage(bolsa, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bitmapBolsa);
}

void Compra::exibirTextoLista(HDC hDC, Jogador *player, Loja *rpgStore)
{
    HFONT font;
    char textoLista[] = "Nome                                                      Preco";

    // Carrega a quantidade de ouro do jogador para uma string a ser exibida
    char playerOuro[10];
    sprintf(playerOuro,"%d    ",player->getOuro());

    // Escolhe a fonte
    font = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
    SelectObject(hDC,font);

    // Escolhe Background
    SetBkColor(hDC,RGB(255,242,204));

    // Exibe o texto na tela
    TextOut(hDC,50,85,textoLista,lstrlen(textoLista));
    TextOut(hDC,455,300,playerOuro,lstrlen(playerOuro));
}
// Método que exibe a tela de Compra
void Compra::exibirTela(Loja *rpgStore)
{
    exibirBotoes();

    rpgStore->exibeLista(1); // Exibe a primeira lista de Equipamentos (Armas)
}

void Compra::exibirBotoes()
{
    ShowWindow(quantidade,SW_SHOW);
    ShowWindow(realizaCompra,SW_SHOW);
    ShowWindow(retorno,SW_SHOW);
    ShowWindow(armas,SW_SHOW);
    ShowWindow(escudo,SW_SHOW);
    ShowWindow(elmo,SW_SHOW);
    ShowWindow(armadura,SW_SHOW);
    ShowWindow(acessorio,SW_SHOW);
    ShowWindow(consumo,SW_SHOW);
    ShowWindow(bolsa,SW_SHOW);
}

void Compra::esconderBotoes()
{
    ShowWindow(quantidade,SW_HIDE);
    ShowWindow(realizaCompra,SW_HIDE);
    ShowWindow(retorno,SW_HIDE);
    ShowWindow(armas,SW_HIDE);
    ShowWindow(escudo,SW_HIDE);
    ShowWindow(elmo,SW_HIDE);
    ShowWindow(armadura,SW_HIDE);
    ShowWindow(acessorio,SW_HIDE);
    ShowWindow(consumo,SW_HIDE);
    ShowWindow(bolsa,SW_HIDE);
}

void Compra::compra(Jogador *player, Loja *rpgStore, Inventario * playerInventario, HDC hDC)
{
    int qtd;
    char textoQuantidade[10];
    Edit_GetLine(quantidade,0,&textoQuantidade,9);
    qtd = atoi(textoQuantidade);
    rpgStore->comprar(player,playerInventario,qtd,hDC);
}
