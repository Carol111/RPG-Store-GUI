#include "Inicio.h"
#include <iostream>
#include "rpgResource.h"


using namespace std;

Inicio::Inicio()
{
    // Carregando as Imagens dos Botões
    hInstance = GetModuleHandle(NULL);
    bitmapCompra = LoadImage(hInstance, MAKEINTRESOURCE(ID_BUTTONCOMPRA), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
    bitmapVenda = LoadImage(hInstance, MAKEINTRESOURCE(ID_BUTTONVENDA), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
    bitmapSair = LoadImage(hInstance, MAKEINTRESOURCE(ID_BUTTONSAIR), IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR);
}

Inicio::~Inicio()
{
    DestroyWindow(comprar);
    DestroyWindow(vender);
    DestroyWindow(sair);
}

// Cria os Botões que enviarão os comandos IDI_COMPRA, IDI_VENDA, IDI_SAIR

void Inicio::exibirTela(HWND hWnd, HDC hDC)
{
    // Mensagem de Boas Vindas
    HFONT font;
    char boasVindas[] = "Bem-vindo à RPG Store!";
    char deseja[] = "O que deseja?";

    // Escolhe a fonte do texto
    font = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
    SelectObject(hDC,font);

    // Escolhe a cor de fundo do texto
    SetBkColor(hDC,RGB(255,242,204));

    // Exibe texto
    TextOut(hDC,288,60,boasVindas,lstrlen(boasVindas));
    TextOut(hDC,288,80,deseja,lstrlen(deseja));

    exibirBotoes(hWnd);

}

void Inicio::exibirBotoes(HWND hWnd)
{
    // Cria botão de opção COMPRA
    comprar = CreateWindowEx(0,"BUTTON","Comprar", WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|BS_BITMAP|BS_FLAT,0,198,187,31,hWnd,(HMENU)ID_COMPRA,NULL,0);
    SendMessage(comprar, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bitmapCompra);

    // Cria botão de opção VENDA
    vender = CreateWindowEx(0,"BUTTON","Vender", WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|BS_BITMAP|BS_FLAT,0,248,187,31,hWnd,(HMENU)ID_VENDA,NULL,0);
    SendMessage(vender, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bitmapVenda);

    // Cria botão de opção SAIR
    sair = CreateWindowEx(0,"BUTTON","Sair", WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|BS_BITMAP|BS_FLAT,0,298,187,31,hWnd,(HMENU)ID_SAIR,NULL,0);
    SendMessage(sair, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bitmapSair);
}
