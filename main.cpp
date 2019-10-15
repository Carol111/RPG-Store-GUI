//////////////////////////////////////////////////////////////////////////////////////////////////////
//                     Universidade Federal do Vale do São Francisco - UNIVASF                      //
//                                                                                                  //
// Disciplina: Programação Orientada a Objetos 2014.1                                               //
// Projeto: RPG Store                                                                               //
//                                                                                                  //
// Docente: Marcelo Santos Linder                                                                   //
//                                                                                                  //
// Discentes: Caroline Carvalho Machado                                                             //
//            Cleiton Carvalho Machado                                                              //                                                        //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

//----------------------------------------------------------------------------------------------------
// Bibliotecas
#include <tchar.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//----------------------------------------------------------------------------------------------------
// Headers Files
#include "rpgResource.h"
#include "Jogador.h"
#include "Loja.h"
#include "Inicio.h"

//----------------------------------------------------------------------------------------------------
// Using
using namespace std;

//----------------------------------------------------------------------------------------------------
// Definições

// Nome da Classe da Janela
#define WINDOW_CLASS    "rpgStore"
// Título da Janela
#define WINDOW_TITLE    "RPG Store"
// Largura da Janela
#define WINDOW_WIDTH    606
// Altura da Janela
#define WINDOW_HEIGHT   368

//----------------------------------------------------------------------------------------------------
// Protótipo das funções

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

BOOL CALLBACK AboutDlgProc(HWND, UINT, WPARAM , LPARAM);

//----------------------------------------------------------------------------------------------------
// WinMain - Função principal

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    // Cria a classe da Janela e especifica seus atributos
	WNDCLASSEX rpgStore;

    // Definindo a janela principal

	rpgStore.cbSize = sizeof(WNDCLASSEX);
	rpgStore.style = CS_HREDRAW | CS_VREDRAW;
	rpgStore.lpfnWndProc = (WNDPROC)WindowProc;
	rpgStore.cbClsExtra = 0;
	rpgStore.cbWndExtra = 0;
	rpgStore.hInstance = hInstance;
	rpgStore.hIcon = LoadIcon (hInstance, MAKEINTRESOURCE (ID_RPGICON));
	rpgStore.hCursor = LoadCursor(NULL, IDC_ARROW);
	rpgStore.hbrBackground = (HBRUSH) WHITE_BRUSH;
	rpgStore.lpszMenuName = NULL;
	rpgStore.lpszClassName = WINDOW_CLASS;
	rpgStore.hIconSm = LoadIcon (hInstance, MAKEINTRESOURCE (ID_RPGICON));

    // Registra a classe da janela
	if(RegisterClassEx(&rpgStore))
	{
	    //Cria a janela principal
	    HWND hWnd = NULL;
	    hWnd = CreateWindowEx(0,
                              WINDOW_CLASS,
                              WINDOW_TITLE,
                              WS_OVERLAPPED|WS_SYSMENU|WS_MINIMIZEBOX|WS_VISIBLE,
                              (GetSystemMetrics(SM_CXSCREEN) - WINDOW_WIDTH)/2,
                              (GetSystemMetrics(SM_CYSCREEN) - WINDOW_HEIGHT)/2,
                              WINDOW_WIDTH,
                              WINDOW_HEIGHT,
                              HWND_DESKTOP,
                              NULL,
                              hInstance,
                              0);

        // Verifica se a janela foi criada
		if(hWnd)
        {
            // Mostra janela
            ShowWindow(hWnd, nCmdShow);
            UpdateWindow(hWnd);

            // Armazena os dados da mensagem que será obtida
            MSG msg;

            // Loop de mensagens, enquanto mensagem não for WM_QUIT
            // Obtém mensagem da fila de mensagem

            while(GetMessage(&msg, NULL, 0, 0) > 0)
            {
                // Traduz teclas virtuais ou aceleradoras (de atalho)
                TranslateMessage(&msg);
                // Envia mensagem para a função que processa mensagens (WindowProc)
                DispatchMessage(&msg);
            }

            // Retorna ao Windows com valor de msg.wParam
            return (msg.wParam);
        }
        // Se a janela não foi criada
        else
        {
            // Exibe mensagem de erro e sai do programa
            MessageBox(NULL, "Falha ao criar janela", "Erro",MB_ICONERROR | MB_OK);
            return (0);
        }
	}
	// Se a classe da janela não foi registrada
	else
    {
        // Exibe mensagem de erro e sai do programa
        MessageBox(NULL, "Falha ao registrar classe da janela", "Erro",MB_ICONERROR | MB_OK);
        return (0);
    }

    // Retorna ao Windows sem passar pelo loop de mensagens
    return (0);
}

// Dialog Box
BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch(Message)
    {
        case WM_INITDIALOG:

        return TRUE;
        case WM_COMMAND:
            EndDialog(hwnd, IDCANCEL);
        break;
        default:
            return FALSE;
    }
    return TRUE;
}

//----------------------------------------------------------------------------------------------------
// WindowProc - Processa as mensagens enviadas para o programa

LRESULT CALLBACK WindowProc (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // Objetos da RPG Store
    static Loja rpgStore;
    static Jogador player;
    static Inventario playerInventario;

    //Telas
    static Inicio telaInicio;
    static Compra telaCompra;
    static Venda telaVenda;

    // Variáveis para verificar qual fundo deve ser pintado na tela
    static char tela = 'x';

    // Variáveis para manipulação da parte gráfica do programa
    static HDC hDC = NULL;
    static HDC hdcMem = NULL;
    static PAINTSTRUCT psPaint;
    static HBITMAP fundo;
    static HBITMAP quadro;
    static BITMAP bm;

    // Verifica qual foi a mensagem enviada
    switch(uMsg)
    {
        case WM_CREATE: // Cria a RPG Store
        {
            // O jogador começa com 20.000$ de ouro para realizar compras na RPG Store
            player.setOuro(20000);

            // Cria listas de itens
            rpgStore.criaLista(hWnd);
            telaCompra.criarBotoes(hWnd,lParam);
            telaVenda.criarBotoes(hWnd,lParam);
            playerInventario.criaListaBolsa(hWnd);
            playerInventario.criaListaInventario(hWnd);

            // Tela atual
            tela = 'i';
            // Carrega fundo da tela inicial
            fundo = (HBITMAP) LoadImage(NULL,"img\\bitmaps\\tela\\telaInicio.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
            if(fundo == NULL) MessageBox(hWnd,"Não foi possível carregar o fundo","Erro!!!",MB_OK | MB_ICONERROR);

            // Carrega quadro da compra
            quadro = (HBITMAP) LoadImage(NULL,"img\\bitmaps\\tela\\telaDescricao.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);

            // Pegando dimensões do objeto
            GetObject(fundo,sizeof(BITMAP),&bm);

            return (0);
        } break;

        case WM_NOTIFY:
        {
            if((((LPNMHDR)lParam)->hwndFrom)==(rpgStore.comparaListView()))
            {
                if((((LPNMHDR)lParam)->code)==NM_CLICK)
                {
                tela = 'd';
                GetObject(quadro,sizeof(BITMAP),&bm);
                InvalidateRect(hWnd,NULL,FALSE);
                UpdateWindow(hWnd);
                }
            }
            else if((((LPNMHDR)lParam)->hwndFrom)==(playerInventario.comparaListInventario()))
            {
                if((((LPNMHDR)lParam)->code)==NM_CLICK)
                {
                tela = 'p';
                GetObject(quadro,sizeof(BITMAP),&bm);
                InvalidateRect(hWnd,NULL,FALSE);
                UpdateWindow(hWnd);
                }
            }
            else if((((LPNMHDR)lParam)->hwndFrom)==(playerInventario.comparaListBolsa()))
            {
                if((((LPNMHDR)lParam)->code)==NM_CLICK)
                {
                tela = 'p';
                playerInventario.setIndex(-1);
                GetObject(quadro,sizeof(BITMAP),&bm);
                InvalidateRect(hWnd,NULL,FALSE);
                UpdateWindow(hWnd);
                }
            }break;
        }break;

        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case ID_COMPRA: // Pressiona botão de COMPRA
                {
                    // Destrói os botões da tela anterior
                    telaInicio.~Inicio();
                    telaCompra.exibirBotoes();
                    rpgStore.exibeLista(1);

                    // Tela atual
                    tela = 'c';

                    // Carrega fundo da tela inicial
                    fundo = (HBITMAP) LoadImage(NULL,"img\\bitmaps\\tela\\telaCompra.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                    if(fundo == NULL) MessageBox(hWnd,"Não foi possível carregar o fundo","Erro!!!",MB_OK | MB_ICONERROR);
                    // Pegando dimensões do objeto
                    GetObject(fundo,sizeof(BITMAP),&bm);

                    // Força repintura da tela
                    InvalidateRect(hWnd,NULL,FALSE);
                    UpdateWindow(hWnd);
                }break;
                case ID_ARMAS:
                {
                    tela = 'x';
                    rpgStore.escondeLista();
                    rpgStore.exibeLista(1);
                }break;
                case ID_ESCUDO:
                {
                    tela = 'x';
                    rpgStore.escondeLista();
                    rpgStore.exibeLista(2);
                }break;
                case ID_ELMO:
                {
                    tela = 'x';
                    rpgStore.escondeLista();
                    rpgStore.exibeLista(3);
                }break;
                case ID_ARMADURA:
                {
                    tela = 'x';
                    rpgStore.escondeLista();
                    rpgStore.exibeLista(4);
                }break;
                case ID_ACESSORIO:
                {
                    tela = 'x';
                    rpgStore.escondeLista();
                    rpgStore.exibeLista(5);
                }break;
                case ID_CONSUMO:
                {
                    tela = 'x';
                    rpgStore.escondeLista();
                    rpgStore.exibeLista(6);
                }break;
                case ID_BOLSA:
                {
                    tela = 'x';
                    rpgStore.escondeLista();
                    rpgStore.exibeLista(7);
                }break;
                case ID_VENDA: // Pressiona botão de VENDA
                {
                    // Destrói os botões da tela anterior
                    telaInicio.~Inicio();
                    playerInventario.exibirBolsa();
                    playerInventario.exibirConteudo();

                    // Tela atual
                    tela = 'v';

                    // Carrega fundo da tela inicial
                    fundo = (HBITMAP) LoadImage(NULL,"img\\bitmaps\\tela\\telaVenda.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                    if(fundo == NULL) MessageBox(hWnd,"Não foi possível carregar o fundo","Erro!!!",MB_OK | MB_ICONERROR);
                    // Pegando dimensões do objeto
                    GetObject(fundo,sizeof(BITMAP),&bm);

                    // Força repintura da tela
                    InvalidateRect(hWnd,NULL,FALSE);
                    UpdateWindow(hWnd);
                }break;
                case ID_REALIZACOMPRA:
                {
                    telaCompra.compra(&player,&rpgStore,&playerInventario,hDC);
                    // Tela atual
                    tela = 'd';
                    InvalidateRect(hWnd,NULL,FALSE);
                    UpdateWindow(hWnd);
                }break;
                case ID_REALIZAVENDA:
                {
                    telaVenda.venda(&player,&rpgStore,&playerInventario,hDC);
                    // Tela atual
                    fundo = (HBITMAP) LoadImage(NULL,"img\\bitmaps\\tela\\telaVenda.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                    if(fundo == NULL) MessageBox(hWnd,"Não foi possível carregar o fundo","Erro!!!",MB_OK | MB_ICONERROR);
                    GetObject(fundo,sizeof(BITMAP),&bm);
                    tela = 'v';
                    InvalidateRect(hWnd,NULL,FALSE);
                    UpdateWindow(hWnd);
                }break;
                case ID_RETORNO: // Pressiona botão SAIR
                {
                    // Destrói os botões da tela anterior
                    telaCompra.esconderBotoes();
                    telaVenda.esconderBotoes();
                    playerInventario.esconderListas();
                    rpgStore.escondeLista();

                    // Tela atual
                    tela = 'i';

                    // Carrega fundo da tela inicial
                    fundo = (HBITMAP) LoadImage(NULL,"img\\bitmaps\\tela\\telaInicio.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                    if(fundo == NULL) MessageBox(hWnd,"Não foi possível carregar o fundo","Erro!!!",MB_OK | MB_ICONERROR);
                    // Pegando dimensões do objeto
                    GetObject(fundo,sizeof(BITMAP),&bm);

                    // Força repintura da tela
                    InvalidateRect(hWnd,NULL,FALSE);
                    UpdateWindow(hWnd);
                }break;
                case ID_SAIR: // Pressiona botão SAIR
                {
                    SendMessage(hWnd, WM_CLOSE, 0, 0);
                }break;
                default:break;
            }
        }break;

        case WM_PAINT: // Janela (ou parte dela) precisa ser atualizada
        {
            // Indica que a janela já foi atualizada
            hDC = BeginPaint(hWnd, &psPaint);
            hdcMem = CreateCompatibleDC(hDC);

            SelectObject(hdcMem, fundo);

            switch (tela)
            {
            case 'i':
            {
                BitBlt(hDC, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
                telaInicio.exibirTela(hWnd, hDC);
            }break;
            case 'c':
            {
                BitBlt(hDC, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
                telaCompra.exibirTextoLista(hDC, &player, &rpgStore);
                telaCompra.exibirTela(&rpgStore);
                rpgStore.exibirDescricaoItem(hDC,hWnd);
            }break;
            case 'v':
            {
                BitBlt(hDC, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
                telaVenda.exibirTela(hDC,&player,&playerInventario);
            }break;
            case 'd':
            {
                SelectObject(hdcMem, quadro);
                StretchBlt(hDC, 326, 22, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
                telaCompra.exibirTextoLista(hDC, &player, &rpgStore);
                rpgStore.exibirDescricaoItem(hDC,hWnd);
            }break;
            case 'p':
            {
                SelectObject(hdcMem, quadro);
                StretchBlt(hDC, 326, 22, bm.bmWidth-3, 100, hdcMem, 0, 0, bm.bmWidth-3, 100, SRCCOPY);
                playerInventario.exibirDescricaoItem(hDC,hWnd);
            }break;
            default:break;
            }
            DeleteDC(hdcMem);

            EndPaint(hWnd, &psPaint);

            return (0);
        } break;

        case WM_CLOSE: // Janela foi fechada
        {
            // Destrói a janela
            DestroyWindow(hWnd);

            return (0);
        } break;

        case WM_DESTROY: // Janela foi destruída
        {
            // Envia mensagem WM_QUIT para o loop de mensagens
            PostQuitMessage(WM_QUIT);

            return (0);
        }
        default: // Deixa o Windows processar as mensagens que não foram verificadas na função
            return(DefWindowProc(hWnd, uMsg, wParam, lParam));
    }
    return (0);
}

