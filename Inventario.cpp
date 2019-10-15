#include "Inventario.h"
#include <cstring>
#include <iomanip>
#include <stdlib.h>

using namespace std;

Inventario::Inventario()
{
    //O inventário incialmente é capaz de armazenar 20 itens
    //podendo-se alterar essa quantidade acrescentando 3 bolsas

    conteudo = new Item[20];

    capacidadeItens = 20;
    capacidadeBolsas = 3;

    espacoOcupadoItens = 0;
    espacoOcupadoBolsas = 0;

    auxLista.mask = LVCF_FMT | LVCF_TEXT | LVCF_SUBITEM | LVCF_WIDTH;
    auxLista.fmt = LVCFMT_LEFT;
    auxLista.iSubItem = 0;
    auxLista.cx = 200;

    novo.mask = LVIF_TEXT|LVIF_IMAGE;
    novo.iSubItem = 0;

    font = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
}

Inventario::~Inventario()
{
    delete [] conteudo;
}

// Sobrecarga da função inserirItem (Equipamento)
bool Inventario::inserirItem(Equipamento *novoItem, int quantidade)
{
    if(espacoOcupadoItens == capacidadeItens)
    {
        //cout << "O inventario esta cheio" << endl;
        return false;
    }
    else

    //Verifica se o jogador pretende comprar mais itens do que permite o espaço livre no inventário
    {   if(espacoOcupadoItens+quantidade>capacidadeItens)
        {
            //cout << "Nao ha espaco suficiente no inventario" << endl;
            return false;
        }
        else
        {
        //A quantidade comprada será inserida no inventário, cada equipamento ocupa 1 espaço
            for(int i=0; i<quantidade; i++)
            {
                conteudo[espacoOcupadoItens+i]=*novoItem;
                item = (HICON) LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(novoItem->getID()));
                ImageList_AddIcon(itemInventario, item);
                ListView_SetImageList(listViewInventario, itemInventario, LVSIL_SMALL);
                novo.pszText = const_cast<char *>(novoItem->getNome().c_str());
                novo.iItem = espacoOcupadoItens+i;
                novo.iImage = espacoOcupadoItens+i;
                ListView_InsertItem(listViewInventario,&novo);
            }
            espacoOcupadoItens += quantidade;
            return true;
        }
    }
}

// Sobrecarga da função inserirItem (Consumivel)
bool Inventario::inserirItem(Consumivel *novoItem, int quantidade)
{
    if(espacoOcupadoItens == capacidadeItens)
    {
        //cout << "O inventario esta cheio" << endl;
        return false;
    }
    else
    {
        /*Caso já exista esse tipo de consumível no invetário,
        não será ocupado um novo espaço durante a compra*/

        bool existe=false;

        //Procura pelo tipo de consumível para inserir a quantidade comprada
        for(int i=0;(i<espacoOcupadoItens && existe==false);i++)
        {
            if(conteudo[i].getNome()==novoItem->getNome())
            {
                conteudo[i].setQuantidade(conteudo[i].getQuantidade()+quantidade);
                existe = true;
            }
        }

        //Caso não exista será ocupado um novo espaço no inventário
        if(existe==false)
        {
            conteudo[espacoOcupadoItens]=*novoItem; //Ocupa um espaço
            conteudo[espacoOcupadoItens].setQuantidade(conteudo[espacoOcupadoItens].getQuantidade()+quantidade); //Insere a quantidade comprada
            item = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(novoItem->getID()));
            ImageList_AddIcon(itemInventario, item);
            ListView_SetImageList(listViewInventario, itemInventario, LVSIL_SMALL);
            novo.pszText = const_cast<char *>(novoItem->getNome().c_str());
            novo.iItem = espacoOcupadoItens;
            novo.iImage = espacoOcupadoItens;
            ListView_InsertItem(listViewInventario,&novo);
            espacoOcupadoItens++;
        }
        return true;
    }
}

// Remove Item do tipo Equipamento
// se funcionar retorna a quantidade removida
// se falhar retorna 0
bool Inventario::removerItemE(int posicaoDoItem, int quantidade)
{
    if(posicaoDoItem>=espacoOcupadoItens)
    {
        //cout << "Opcao invalida" << endl;
        return false;
    }
    else
    {
        // Se o Item for do tipo Consumivel chama o método para remover Consumivel
    if((conteudo[posicaoDoItem].getTipo()=='c')&&quantidade>=1)
    {
        bool valido;
        //cout << "Insira a quantidade que deseja vender: ";
        //cin >> quantidade;
        valido = removerItemC(posicaoDoItem, quantidade);
        return valido;
    } else
    {
        if((espacoOcupadoItens==0)||(quantidade>1))
        {
            //cout << "Nao ha itens no inventario" << endl;
            return false;
        }
        else
        {
            Item *aux = new Item[capacidadeItens];

            //O itens são movidos ocupando o espaço do item removido e desocupando um espaço no final do inventário
            for(int i=0; i<posicaoDoItem; i++)
            {
                aux[i] = conteudo[i];
            }
            for(int i=posicaoDoItem;i<espacoOcupadoItens;i++)
            {
                aux[i] = conteudo[i+1];
            }
            delete conteudo;
            conteudo = aux;
            ListView_DeleteItem(listViewInventario,posicaoDoItem);

            espacoOcupadoItens--;
        }
    return true;
    }
    }
}

// Remove item do tipo Consumivel
// se funcionar retorna a quantidade removida
// se falhar retorna 0
bool Inventario::removerItemC(int posicaoDoItem, int quantidade)
{
    if(espacoOcupadoItens==0)
    {
        //cout << "Nao ha itens no inventario" << endl;
        return false;
    }
    else
    {
        //Verifica se o jogador não pretende remover uma quantidade maior de consumíveis do que possui
        if(conteudo[posicaoDoItem].getQuantidade()<quantidade)
        {
            //cout << "Voce nao possui esta quantidade de " << conteudo[posicaoDoItem].getNome() << endl;
            return false;
        }
        //Remove todos os itens de um certo tipo de consumível no inventário
        else if(conteudo[posicaoDoItem].getQuantidade()==quantidade)
        {
            Item *aux = new Item[capacidadeItens];
            for(int i=0; i<posicaoDoItem; i++)
            {
                aux[i] = conteudo[i];
            }
            for(int i=posicaoDoItem;i<espacoOcupadoItens;i++)
            {
                aux[i] = conteudo[i+1];
            }
            delete conteudo;
            conteudo = aux;
            ListView_DeleteItem(listViewInventario,posicaoDoItem);

            espacoOcupadoItens--;
            return true;
        }

        //Remove uma quantidade de consumíveis menor que a quantidade que possui
        else
        {
            conteudo[posicaoDoItem].setQuantidade(conteudo[posicaoDoItem].getQuantidade()-quantidade);
            return true;
        }
    }
}

/*
Aumenta a capacidade do inventário com a quantidade de itens que a nova bolsa pode armazenar
*/
bool Inventario::inserirBolsa(Bolsa novaBolsa)
{
    if(espacoOcupadoBolsas == capacidadeBolsas)
    {
        //cout << "Jogador ja carrega o numero maximo de bolsas" << endl;
        return false;
    }
    else
    {
        bolsasDoInventario[espacoOcupadoBolsas] = novaBolsa;

        Item *aux = new Item[capacidadeItens+novaBolsa.getCapacidade()];

        //Aumenta a capacidade do Inventario de acordo com a capacidade da Bolsa inserida
        for(int i=0;i<capacidadeItens;i++)
        {
            aux[i] = conteudo[i];
        }
        delete conteudo;
        conteudo = aux;

        item = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(novaBolsa.getID()));
        ImageList_AddIcon(itemBolsa, item);
        ListView_SetImageList(listViewBolsa, itemBolsa, LVSIL_SMALL);
        novo.pszText = const_cast<char *>(novaBolsa.getNome().c_str());
        novo.iItem = espacoOcupadoBolsas;
        novo.iImage = espacoOcupadoBolsas;
        ListView_InsertItem(listViewBolsa,&novo);

        capacidadeItens += novaBolsa.getCapacidade();
        espacoOcupadoBolsas++;
        return true;
    }
}

/*
Libera a capacidade do inventário com a quantidade de itens que a bolsa podia armazenar
*/
bool Inventario::removerBolsa(int posicaoDaBolsa)
{
    if(posicaoDaBolsa>=espacoOcupadoBolsas)
    {
        //cout << "Opcao invalida" << endl;
        return 0;
    }
    else
    {
        if(espacoOcupadoBolsas==0)
    {
        //cout << "Nao ha bolsas no inventario" << endl;
        return false;
    }
    else
    {
        if(capacidadeItens-bolsasDoInventario[posicaoDaBolsa].getCapacidade() < espacoOcupadoItens)
        {
            //cout << "Remova alguns itens do inventario antes de remover a bolsa" << endl;
            return false;
        }

        //Diminui a capacidade do Inventario de acordo com a capacidade da Bolsa removida
        else
        {
            capacidadeItens -= bolsasDoInventario[posicaoDaBolsa].getCapacidade();
            Item *aux = new Item[capacidadeItens];

            for(int i=0;i<capacidadeItens;i++)
            {
                aux[i] = conteudo[i];
            }
            delete conteudo;
            conteudo = aux;

        //As bolsas são movidas ocupando o espaço da bolsa removida e desocupando um espaço no final da lista de bolsas
            for(int i=posicaoDaBolsa; i<espacoOcupadoBolsas; i++)
            {
                bolsasDoInventario[i]=bolsasDoInventario[i+1];
            }
            espacoOcupadoBolsas--;
            ListView_DeleteItem(listViewBolsa,posicaoDaBolsa);
            return true;
        }
    }
    }
}

void Inventario::exibirDescricaoItem(HDC hDC,HWND hWnd)
{
    // Recupera índice do item na lista
    if(index!=-1)
    {
        selected = 0;
        index = ListView_GetNextItem(listViewInventario, -1, LVNI_SELECTED);
    }
    if(index<0)
    {
        index = ListView_GetNextItem(listViewBolsa, -1, LVNI_SELECTED);
        selected = 1;
    }

    // Escolhe a fonte
    SelectObject(hDC,font);

    // Escolhe Background
    SetBkColor(hDC,RGB(255,242,204));

    if(selected==0)
    {
        item = LoadIcon(GetModuleHandle(NULL),MAKEINTRESOURCE(conteudo[index].getID()));
        if(item == NULL) MessageBox(hWnd,"Não foi possível carregar o icone","Erro!!!",MB_OK | MB_ICONERROR);

        // Exibe o texto na tela
        DrawIcon(hDC,333,28,item);
        TextOut(hDC,368,39,conteudo[index].getNome().c_str(),lstrlen(conteudo[index].getNome().c_str()));
        itoa(conteudo[index].getValorDeVenda(),strAux,10);
        TextOut(hDC,515,39,(LPCSTR)strAux,lstrlen(strAux));

        // Exibe o texto na tela
        strcpy(strAux,"Quantidade");
        TextOut(hDC,368,80,(LPCSTR)strAux,lstrlen(strAux));
        itoa(conteudo[index].getQuantidade(),strAux,10);
        TextOut(hDC,430,80,(LPCSTR)strAux,lstrlen(strAux));
    }
    else
    {
        item = LoadIcon(GetModuleHandle(NULL),MAKEINTRESOURCE(bolsasDoInventario[index].getID()));
        if(item == NULL) MessageBox(hWnd,"Não foi possível carregar o icone","Erro!!!",MB_OK | MB_ICONERROR);

        // Exibe o texto na tela
        DrawIcon(hDC,333,28,item);
        TextOut(hDC,368,39,bolsasDoInventario[index].getNome().c_str(),lstrlen(bolsasDoInventario[index].getNome().c_str()));
        itoa(bolsasDoInventario[index].getValorDeVenda(),strAux,10);
        TextOut(hDC,515,39,(LPCSTR)strAux,lstrlen(strAux));
        strcpy(strAux,"Capacidade");
        TextOut(hDC,368,80,(LPCSTR)strAux,lstrlen(strAux));
        itoa(bolsasDoInventario[index].getCapacidade(),strAux,10);
        TextOut(hDC,430,80,(LPCSTR)strAux,lstrlen(strAux));
    }
}

void Inventario::criaListaInventario(HWND hWnd)
{
    listViewInventario = CreateWindowEx(0,WC_LISTVIEW,"",WS_CHILD|LVS_REPORT|LVS_NOCOLUMNHEADER|LVS_SINGLESEL,17,144,286,177,hWnd,(HMENU)ID_INVENTARIO,GetModuleHandle(NULL),0);
    ListView_SetBkColor(listViewInventario,RGB(255,242,204));
    ShowWindow(listViewInventario,SW_HIDE);
    ListView_SetTextBkColor(listViewInventario,RGB(255,242,204));
    itemInventario = ImageList_Create(30,30,ILC_MASK|ILC_COLORDDB,50,0);
    SendMessage((HWND) listViewInventario, (UINT) LVM_INSERTCOLUMN, (WPARAM) (int) 0, (LPARAM) &auxLista);
}

void Inventario::criaListaBolsa(HWND hWnd)
{
    listViewBolsa= CreateWindowEx(0,WC_LISTVIEW,"",WS_CHILD|LVS_LIST|LVS_NOCOLUMNHEADER|LVS_SINGLESEL,17,85,286,37,hWnd,(HMENU)ID_LBOLSA,GetModuleHandle(NULL),0);
    ListView_SetBkColor(listViewBolsa,RGB(255,242,204));
    ShowWindow(listViewBolsa,SW_HIDE);
    ListView_SetTextBkColor(listViewBolsa,RGB(255,242,204));
    itemBolsa = ImageList_Create(30,30,ILC_MASK|ILC_COLORDDB,3,0);
    SendMessage((HWND) listViewBolsa, (UINT) LVM_INSERTCOLUMN, (WPARAM) (int) 0, (LPARAM) &auxLista);
}

HWND Inventario::comparaListInventario()
{
    return listViewInventario;
}

HWND Inventario::comparaListBolsa()
{
    return listViewBolsa;
}

void Inventario::exibirConteudo()
{
    ShowWindow(listViewInventario,SW_SHOW);
}

void Inventario::exibirBolsa()
{
    ShowWindow(listViewBolsa,SW_SHOW);

}

int Inventario::valorItem(int posicao)
{
    return conteudo[posicao].getValorDeVenda();
}

int Inventario::valorBolsa(int posicao)
{
    return bolsasDoInventario[posicao].getValorDeVenda();
}

int Inventario::getIndex()
{
    return index;
}

int Inventario::getSelected()
{
    return selected;
}

int Inventario::setIndex(int novoIndex)
{
    index = novoIndex;
}

void Inventario::esconderListas()
{
    ShowWindow(listViewInventario,SW_HIDE);
    ShowWindow(listViewBolsa,SW_HIDE);
}
