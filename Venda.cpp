#include "Venda.h"
#include "rpgResource.h"
#include <iostream>
#include <stdio.h>
#include <windowsx.h>

Venda::Venda()
{
    // Carregando as Imagens dos Botões
    hInstance = GetModuleHandle(NULL);

    bitmapRealizaVenda = LoadImage(hInstance, MAKEINTRESOURCE(ID_BUTTONREALIZAVENDA), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
    bitmapRetorno = LoadImage(hInstance, MAKEINTRESOURCE(ID_BUTTONRETORNO), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);

    font = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
}

Venda::~Venda()
{
    DestroyWindow(quantidade);
    DestroyWindow(realizaVenda);
    DestroyWindow(retorno);
}

// Método que exibe a tela de Venda
void Venda::exibirTela(HDC hDC, Jogador *player, Inventario *playerInventario)
{
    // Escolhe a fonte
    SelectObject(hDC,font);

    // Escolhe Background
    SetBkColor(hDC,RGB(255,242,204));

    itoa(player->getOuro(),texto,10);
    TextOut(hDC,455,300,(LPCSTR)texto,lstrlen(texto));

    exibirBotoes();

    playerInventario->exibirConteudo();
    playerInventario->exibirBolsa();
}

void Venda::venda(Jogador *player, Loja *rpgStore, Inventario * playerInventario, HDC hDC)
{
    int qtd;
    char textoQuantidade[10];
    Edit_GetLine(quantidade,0,&textoQuantidade,9);
    qtd = atoi(textoQuantidade);
    rpgStore->vender(player,playerInventario,qtd,hDC);
}

void Venda::criarBotoes(HWND hWnd, LPARAM lParam)
{
    // Caixa para entrada de quantidade
    quantidade = CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","1", WS_CHILD|WS_BORDER|ES_NUMBER|BS_FLAT,368,247,70,22,hWnd,NULL,NULL,0);
    SendMessage((HWND)quantidade,(UINT)WM_SETFONT,(WPARAM)GetStockObject(DEFAULT_GUI_FONT),(LPARAM) lParam);

    // Cria botão de opção REALIZACOMPRA
    realizaVenda = CreateWindowEx(0,"BUTTON","Realizar Venda", WS_CHILD|BS_PUSHBUTTON|BS_BITMAP|BS_FLAT,459,245,125,25,hWnd,(HMENU)ID_REALIZAVENDA,hInstance,0);
    SendMessage(realizaVenda, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bitmapRealizaVenda);

    // Cria botão de opção RETORNO
    retorno = CreateWindowEx(0,"BUTTON","Retornar", WS_CHILD|BS_PUSHBUTTON|BS_BITMAP|BS_FLAT,543,290,41,32,hWnd,(HMENU)ID_RETORNO,hInstance,0);
    SendMessage(retorno, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bitmapRetorno);
}

void Venda::exibirBotoes()
{
    ShowWindow(quantidade,SW_SHOW);
    ShowWindow(realizaVenda,SW_SHOW);
    ShowWindow(retorno,SW_SHOW);
}

void Venda::esconderBotoes()
{
    ShowWindow(quantidade,SW_HIDE);
    ShowWindow(realizaVenda,SW_HIDE);
    ShowWindow(retorno,SW_HIDE);
}
