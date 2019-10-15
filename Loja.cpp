#include "Loja.h"
#include "rpgResource.h"

using namespace std;

// Instancia todos os itens vendidos na Loja
Loja::Loja()
{
    //LISTA DE ARMAS          NOME              V. COMPRA  V.VENDA  ESPEC.         R.LEVEL  ATK  MPOW  DEF  RES  AGI  ICONE
    listaArmas[0].setValores( "Shortsword    ", 240,       120,     "Guerreiro  ", 1,       25,  0,    0,   0,   0,   ID_ARMA_SHORTSWORD);
    listaArmas[1].setValores( "Barong        ", 1200,      600,     "Guerreiro  ", 12,      52,  0,    0,   0,   0,   ID_ARMA_BARONG);
    listaArmas[2].setValores( "Rondell Dagger", 720,       360,     "Ladrão     ", 1,       19,  0,    0,   0,   10,  ID_ARMA_RONDELLDAGGER);
    listaArmas[3].setValores( "Jambiya       ", 1360,      680,     "Ladrão     ", 15,      31,  0,    0,   0,   27,  ID_ARMA_JAMBIYA);
    listaArmas[4].setValores( "Cure Staff    ", 450,       225,     "Mago Branco", 1,       0,   19,   0,   5,   0,   ID_ARMA_CURESTAFF);
    listaArmas[5].setValores( "Pure Staff    ", 2300,      1150,    "Mago Branco", 10,      0,   38,   0,   8,   0,   ID_ARMA_PURESTAFF);
    listaArmas[6].setValores( "Force Rod     ", 300,       150,     "Mago Negro ", 1,       0,   25,   0,   0,   0,   ID_ARMA_FORCEROD);
    listaArmas[7].setValores( "Sleet Rod     ", 4160,      2080,    "Mago Negro ", 28,      0,   90,   0,   0,   0,   ID_ARMA_SLEETROD);
    listaArmas[8].setValores( "Longbow       ", 490,       245,     "Arqueiro   ", 1,       20,  6,    0,   0,   7,   ID_ARMA_LONGBOW);
    listaArmas[9].setValores( "Mithril Bow   ", 5600,      2800,    "Arqueiro   ", 37,      120, 11,   0,   0,   18,  ID_ARMA_MITHRILBOW);

    //LISTA DE ESCUDOS          NOME              V. COMPRA  V.VENDA  ESPEC.            R.LEVEL  ATK  MPOW  DEF  RES  AGI  ICONE
    listaEscudos[0].setValores( "Round Shield  ", 300,       150,     "Guerreiro  ",    1,       0,   0,    10,  0,   0,   ID_ESCUDO_ROUNDSHIELD);
    listaEscudos[1].setValores( "Opal Shield   ", 1900,      950,     "Guerreiro  ",    12,      0,   0,    30,  7,   0,   ID_ESCUDO_OPALSHIELD);
    listaEscudos[2].setValores( "Flame Shield  ", 2200,      1100,    "Guerreiro  ",    16,      0,   0,    15,  23,  0,   ID_ESCUDO_FLAMESHIELD);
    listaEscudos[3].setValores( "Reverie Shield", 2800,      1400,    "Guerreiro  ",    22,      0,   0,    60,  0,   0,   ID_ESCUDO_REVERIESHIELD);
    listaEscudos[4].setValores( "Sacri Shield  ", 3900,      1950,    "Guerreiro  ",    34,      0,   0,    55,  31,  0,   ID_ESCUDO_SACRISHIELD);

    //LISTA DE ELMOS          NOME              V. COMPRA  V.VENDA  ESPEC.         R.LEVEL  ATK  MPOW  DEF  RES  AGI  ICONE
    listaElmos[0].setValores( "Iron Helm     ", 550,       225,     "Guerreiro  ", 7,       0,   0,    5,   2,   0,   ID_ELMO_IRONHELM);
    listaElmos[1].setValores( "Circlet       ", 370,       185,     "Ladrão     ", 3,       0,   0,    5,   1,   0,   ID_ELMO_CIRCLET);
    listaElmos[2].setValores( "Feather       ", 630,       315,     "Mago Branco", 12,      0,   0,    11,  6,   0,   ID_ELMO_FEATHER);
    listaElmos[3].setValores( "Barette       ", 630,       315,     "Mago Negro ", 12,      0,   0,    16,  9,   0,   ID_ELMO_BERETTE);
    listaElmos[4].setValores( "Headband      ", 510,       255,     "Arqueiro   ", 10,      0,   0,    8,   5,   0,   ID_ELMO_HEADBAND);

    //LISTA DE ARMADURAS          NOME              V. COMPRA  V.VENDA  ESPEC.         R.LEVEL  ATK  MPOW  DEF  RES  AGI  ICONE
    listaArmaduras[0].setValores( "Diamond Armor ", 4000,      2000,    "Guerreiro  ", 38,      0,   0,    90,  50,  0,   ID_ARMADURA_DIAMONDARMOR);
    listaArmaduras[1].setValores( "Mirage Vest   ", 3500,      1750,    "Ladrão      ", 40,      0,   0,    30,  20,  70,  ID_ARMADURA_MIRAGEVEST);
    listaArmaduras[2].setValores( "Light Robe    ", 1600,      800,     "Mago Branco", 27,      0,   0,    42,  38,  0,   ID_ARMADURA_LIGHTROBE);
    listaArmaduras[3].setValores( "Dark Robe     ", 1800,      900,     "Mago Negro ", 30,      0,   0,    50,  42,  0,   ID_ARMADURA_DARKROBE);
    listaArmaduras[4].setValores( "Peytral       ", 2180,      1090,    "Arqueiro   ", 26,      0,   0,    39,  23,  0,   ID_ARMADURA_PEYTRAL);

    //LISTA DE ACESSÓRIOS          NOME              V. COMPRA  V.VENDA  ESPEC.         R.LEVEL  ATK  MPOW  DEF  RES  AGI  ICONE
    listaAcessorios[0].setValores( "Battle Boots  ", 1010,      505,     "Guerreiro  ", 9,       0,   0,    7,   6,   12,  ID_ACESSORIO_BATTLEBOOTS);
    listaAcessorios[1].setValores( "Spark Boots   ", 2600,      1300,    "Ladrão     ", 19,      0,   0,    9,   2,   28,  ID_ACESSORIO_SPARKBOOTS);
    listaAcessorios[2].setValores( "Magic Ring    ", 700,       350,     "Mago Branco", 7,       0,   6,    9,   4,   4,   ID_ACESSORIO_MAGICRING);
    listaAcessorios[3].setValores( "Scarab        ", 1350,      675,     "Mago Negro ", 11,      0,   13,   8,   9,   6,   ID_ACESSORIO_SCARAB);
    listaAcessorios[4].setValores( "Fairy Shoes   ", 380,       190,     "Arqueiro   ", 5,       0,   0,    2,   5,   9,   ID_ACESSORIO_FAIRYSHOES);

    //LISTA DE CONSUMÍVEIS      NOME              V. COMPRA  V.VENDA  HP  MP  STATUS  TUDO   DESCRIÇÃO                                      ICONE
    listaConsumo[0].setValores( "Health Potion ", 30,        15,      50, 0,  'x',    false, "Recupera 50 pontos da barra de vida      ",  ID_CONSUMO_HEALTHPOTION);
    listaConsumo[1].setValores( "Mana Potion   ", 30,        15,      0,  30, 'x',    false, "Recupera 30 pontos da barra de mana      ",  ID_CONSUMO_MANAPOTION);
    listaConsumo[2].setValores( "Antidote      ", 50,        25,      0,  0,  'v',    false, "Cura envenenamento                       ",  ID_CONSUMO_ANTIDOTE);
    listaConsumo[3].setValores( "Soft          ", 70,        35,      0,  0,  'p',    false, "Cura paralisia                           ",  ID_CONSUMO_SOFT);
    listaConsumo[4].setValores( "Elixir        ", 200,       100,     0,  0,  'x',    true,  "Restaura o jogador ao seu estado saudável",  ID_CONSUMO_ELIXIR);

    //LISTA DE BOLSAS          NOME                 V. COMPRA  V.VENDA  CAPACIDADE  ICONE
    listaBolsas[0].setValores( "Bolsa          ",   5000,      2500,    5,          ID_BOLSA_BOLSA);
    listaBolsas[1].setValores( "Bau            ",   10000,     5000,    10,         ID_BOLSA_BAU);

    font = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
}

// Destrutor
Loja::~Loja()
{
    DestroyWindow(listViewArma);
    DestroyWindow(listViewEscudo);
    DestroyWindow(listViewElmo);
    DestroyWindow(listViewArmadura);
    DestroyWindow(listViewAcessorio);
    DestroyWindow(listViewConsumo);
    DestroyWindow(listViewBolsa);
}

HWND Loja::comparaListView()
{
    switch(listaSelecionada)
    {
        case 1: return listViewArma;
        case 2: return listViewEscudo;
        case 3: return listViewElmo;
        case 4: return listViewArmadura;
        case 5: return listViewAcessorio;
        case 6: return listViewConsumo;
        case 7: return listViewBolsa;
    }
    return listViewArma;
}

void Loja::exibirDescricaoItem(HDC hDC,HWND hWnd)
{
    // Recupera índice do item na lista
    switch(listaSelecionada)
    {
        case 1: index = ListView_GetNextItem(listViewArma, -1, LVNI_SELECTED); break;
        case 2: index = ListView_GetNextItem(listViewEscudo, -1, LVNI_SELECTED); break;
        case 3: index = ListView_GetNextItem(listViewElmo, -1, LVNI_SELECTED); break;
        case 4: index = ListView_GetNextItem(listViewArmadura, -1, LVNI_SELECTED); break;
        case 5: index = ListView_GetNextItem(listViewAcessorio, -1, LVNI_SELECTED); break;
        case 6: index = ListView_GetNextItem(listViewConsumo, -1, LVNI_SELECTED); break;
        case 7: index = ListView_GetNextItem(listViewBolsa, -1, LVNI_SELECTED); break;
    }
    if(index<0)
        index = 0;
    // Escolhe a fonte
    SelectObject(hDC,font);

    // Escolhe Background
    SetBkColor(hDC,RGB(255,242,204));

    switch(listaSelecionada)
    {
        case 1:
        {
            iconItem = LoadIcon(GetModuleHandle(NULL),MAKEINTRESOURCE(listaArmas[index].getID()));
            if(iconItem == NULL) MessageBox(hWnd,"Não foi possível carregar o icone","Erro!!!",MB_OK | MB_ICONERROR);

            // Exibe o texto na tela
            DrawIcon(hDC,333,28,iconItem);
            TextOut(hDC,368,39,listaArmas[index].getNome().c_str(),lstrlen(listaArmas[index].getNome().c_str()));
            itoa(listaArmas[index].getValorDeCompra(),strAux,10);
            TextOut(hDC,515,39,(LPCSTR)strAux,lstrlen(strAux));
            TextOut(hDC,350,85,listaArmas[index].getEspecializacao().c_str(),lstrlen(listaArmas[index].getEspecializacao().c_str()));
            strcpy(strAux,"Requer   lv.");
            TextOut(hDC,350,110,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaArmas[index].getRequerLevel(),strAux,10);
            TextOut(hDC,410,110,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"ATK");
            TextOut(hDC,350,150,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaArmas[index].getAtk(),strAux,10);
            TextOut(hDC,395,150,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"M-POW");
            TextOut(hDC,350,175,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaArmas[index].getMPow(),strAux,10);
            TextOut(hDC,395,175,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"DEF");
            TextOut(hDC,435,150,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaArmas[index].getDef(),strAux,10);
            TextOut(hDC,470,150,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"RES");
            TextOut(hDC,435,175,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaArmas[index].getRes(),strAux,10);
            TextOut(hDC,470,175,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"AGI");
            TextOut(hDC,505,150,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaArmas[index].getAgi(),strAux,10);
            TextOut(hDC,540,150,(LPCSTR)strAux,lstrlen(strAux));
            break;
        }
        case 2:
        {
            iconItem = LoadIcon(GetModuleHandle(NULL),MAKEINTRESOURCE(listaEscudos[index].getID()));
            if(iconItem == NULL) MessageBox(hWnd,"Não foi possível carregar o icone","Erro!!!",MB_OK | MB_ICONERROR);

            // Exibe o texto na tela
            DrawIcon(hDC,333,28,iconItem);
            TextOut(hDC,368,39,listaEscudos[index].getNome().c_str(),lstrlen(listaEscudos[index].getNome().c_str()));
            itoa(listaEscudos[index].getValorDeCompra(),strAux,10);
            TextOut(hDC,515,39,(LPCSTR)strAux,lstrlen(strAux));
            TextOut(hDC,350,85,listaEscudos[index].getEspecializacao().c_str(),lstrlen(listaEscudos[index].getEspecializacao().c_str()));
            strcpy(strAux,"Requer   lv.");
            TextOut(hDC,350,110,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaEscudos[index].getRequerLevel(),strAux,10);
            TextOut(hDC,410,110,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"ATK");
            TextOut(hDC,350,150,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaEscudos[index].getAtk(),strAux,10);
            TextOut(hDC,395,150,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"M-POW");
            TextOut(hDC,350,175,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaEscudos[index].getMPow(),strAux,10);
            TextOut(hDC,395,175,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"DEF");
            TextOut(hDC,435,150,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaEscudos[index].getDef(),strAux,10);
            TextOut(hDC,470,150,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"RES");
            TextOut(hDC,435,175,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaEscudos[index].getRes(),strAux,10);
            TextOut(hDC,470,175,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"AGI");
            TextOut(hDC,505,150,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaEscudos[index].getAgi(),strAux,10);
            TextOut(hDC,540,150,(LPCSTR)strAux,lstrlen(strAux));
            break;
        }
        case 3:
        {
            iconItem = LoadIcon(GetModuleHandle(NULL),MAKEINTRESOURCE(listaElmos[index].getID()));
            if(iconItem == NULL) MessageBox(hWnd,"Não foi possível carregar o icone","Erro!!!",MB_OK | MB_ICONERROR);

            // Exibe o texto na tela
            DrawIcon(hDC,333,28,iconItem);
            TextOut(hDC,368,39,listaElmos[index].getNome().c_str(),lstrlen(listaElmos[index].getNome().c_str()));
            itoa(listaElmos[index].getValorDeCompra(),strAux,10);
            TextOut(hDC,515,39,(LPCSTR)strAux,lstrlen(strAux));
            TextOut(hDC,350,85,listaElmos[index].getEspecializacao().c_str(),lstrlen(listaElmos[index].getEspecializacao().c_str()));
            strcpy(strAux,"Requer   lv.");
            TextOut(hDC,350,110,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaElmos[index].getRequerLevel(),strAux,10);
            TextOut(hDC,410,110,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"ATK");
            TextOut(hDC,350,150,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaElmos[index].getAtk(),strAux,10);
            TextOut(hDC,395,150,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"M-POW");
            TextOut(hDC,350,175,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaElmos[index].getMPow(),strAux,10);
            TextOut(hDC,395,175,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"DEF");
            TextOut(hDC,435,150,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaElmos[index].getDef(),strAux,10);
            TextOut(hDC,470,150,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"RES");
            TextOut(hDC,435,175,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaElmos[index].getRes(),strAux,10);
            TextOut(hDC,470,175,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"AGI");
            TextOut(hDC,505,150,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaElmos[index].getAgi(),strAux,10);
            TextOut(hDC,540,150,(LPCSTR)strAux,lstrlen(strAux));
            break;
        }
        case 4:
        {
            iconItem = LoadIcon(GetModuleHandle(NULL),MAKEINTRESOURCE(listaArmaduras[index].getID()));
            if(iconItem == NULL) MessageBox(hWnd,"Não foi possível carregar o icone","Erro!!!",MB_OK | MB_ICONERROR);

            // Exibe o texto na tela
            DrawIcon(hDC,333,28,iconItem);
            TextOut(hDC,368,39,listaArmaduras[index].getNome().c_str(),lstrlen(listaArmaduras[index].getNome().c_str()));
            itoa(listaArmaduras[index].getValorDeCompra(),strAux,10);
            TextOut(hDC,515,39,(LPCSTR)strAux,lstrlen(strAux));
            TextOut(hDC,350,85,listaArmaduras[index].getEspecializacao().c_str(),lstrlen(listaArmaduras[index].getEspecializacao().c_str()));
            strcpy(strAux,"Requer   lv.");
            TextOut(hDC,350,110,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaArmaduras[index].getRequerLevel(),strAux,10);
            TextOut(hDC,410,110,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"ATK");
            TextOut(hDC,350,150,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaArmaduras[index].getAtk(),strAux,10);
            TextOut(hDC,395,150,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"M-POW");
            TextOut(hDC,350,175,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaArmaduras[index].getMPow(),strAux,10);
            TextOut(hDC,395,175,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"DEF");
            TextOut(hDC,435,150,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaArmaduras[index].getDef(),strAux,10);
            TextOut(hDC,470,150,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"RES");
            TextOut(hDC,435,175,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaArmaduras[index].getRes(),strAux,10);
            TextOut(hDC,470,175,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"AGI");
            TextOut(hDC,505,150,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaArmaduras[index].getAgi(),strAux,10);
            TextOut(hDC,540,150,(LPCSTR)strAux,lstrlen(strAux));
            break;
        }
        case 5:
        {
            iconItem = LoadIcon(GetModuleHandle(NULL),MAKEINTRESOURCE(listaAcessorios[index].getID()));
            if(iconItem == NULL) MessageBox(hWnd,"Não foi possível carregar o icone","Erro!!!",MB_OK | MB_ICONERROR);

            // Exibe o texto na tela
            DrawIcon(hDC,333,28,iconItem);
            TextOut(hDC,368,39,listaAcessorios[index].getNome().c_str(),lstrlen(listaAcessorios[index].getNome().c_str()));
            itoa(listaAcessorios[index].getValorDeCompra(),strAux,10);
            TextOut(hDC,515,39,(LPCSTR)strAux,lstrlen(strAux));
            TextOut(hDC,350,85,listaAcessorios[index].getEspecializacao().c_str(),lstrlen(listaAcessorios[index].getEspecializacao().c_str()));
            strcpy(strAux,"Requer   lv.");
            TextOut(hDC,350,110,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaAcessorios[index].getRequerLevel(),strAux,10);
            TextOut(hDC,410,110,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"ATK");
            TextOut(hDC,350,150,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaAcessorios[index].getAtk(),strAux,10);
            TextOut(hDC,395,150,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"M-POW");
            TextOut(hDC,350,175,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaAcessorios[index].getMPow(),strAux,10);
            TextOut(hDC,395,175,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"DEF");
            TextOut(hDC,435,150,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaAcessorios[index].getDef(),strAux,10);
            TextOut(hDC,470,150,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"RES");
            TextOut(hDC,435,175,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaAcessorios[index].getRes(),strAux,10);
            TextOut(hDC,470,175,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"AGI");
            TextOut(hDC,505,150,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaAcessorios[index].getAgi(),strAux,10);
            TextOut(hDC,540,150,(LPCSTR)strAux,lstrlen(strAux));
            break;
        }
        case 6:
        {
            iconItem = LoadIcon(GetModuleHandle(NULL),MAKEINTRESOURCE(listaConsumo[index].getID()));
            if(iconItem == NULL) MessageBox(hWnd,"Não foi possível carregar o icone","Erro!!!",MB_OK | MB_ICONERROR);

            // Exibe o texto na tela
            DrawIcon(hDC,333,28,iconItem);
            TextOut(hDC,368,39,listaConsumo[index].getNome().c_str(),lstrlen(listaConsumo[index].getNome().c_str()));
            itoa(listaConsumo[index].getValorDeCompra(),strAux,10);
            TextOut(hDC,515,39,(LPCSTR)strAux,lstrlen(strAux));
            TextOut(hDC,350,85,listaConsumo[index].getDescricao().c_str(),lstrlen(listaConsumo[index].getDescricao().c_str()));

            strcpy(strAux,"HP");
            TextOut(hDC,350,120,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaConsumo[index].getHp(),strAux,10);
            TextOut(hDC,385,120,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"MP");
            TextOut(hDC,350,145,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaConsumo[index].getMp(),strAux,10);
            TextOut(hDC,385,145,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"STATUS");
            TextOut(hDC,435,120,(LPCSTR)strAux,lstrlen(strAux));
            if(listaConsumo[index].getStatus()=='v')
                strcpy(strAux,"veneno");
            else if(listaConsumo[index].getStatus()=='p')
                strcpy(strAux,"paralisia");
            else strcpy(strAux,"x");
            TextOut(hDC,490,120,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"TUDO");
            TextOut(hDC,435,145,(LPCSTR)strAux,lstrlen(strAux));
            if(listaConsumo[index].getTudo())
                strcpy(strAux,"Cura Tudo");
            else strcpy(strAux,"x");
            TextOut(hDC,490,145,(LPCSTR)strAux,lstrlen(strAux));

            break;
        }
        case 7:
        {
            iconItem = LoadIcon(GetModuleHandle(NULL),MAKEINTRESOURCE(listaBolsas[index].getID()));
            if(iconItem == NULL) MessageBox(hWnd,"Não foi possível carregar o icone","Erro!!!",MB_OK | MB_ICONERROR);

            // Exibe o texto na tela
            DrawIcon(hDC,333,28,iconItem);
            TextOut(hDC,368,39,listaBolsas[index].getNome().c_str(),lstrlen(listaBolsas[index].getNome().c_str()));
            itoa(listaBolsas[index].getValorDeCompra(),strAux,10);
            TextOut(hDC,510,39,(LPCSTR)strAux,lstrlen(strAux));

            strcpy(strAux,"Capacidade");
            TextOut(hDC,350,75,(LPCSTR)strAux,lstrlen(strAux));
            itoa(listaBolsas[index].getCapacidade(),strAux,10);
            TextOut(hDC,420,75,(LPCSTR)strAux,lstrlen(strAux));
            break;
        }
    }

}
// Operação de venda
void Loja::vender(Jogador *novoPlayer,Inventario *playerInventario, int quantidade, HDC hDC)
{
    switch(playerInventario->getSelected())
    {
        case 0:
        {
            int valorTemp; // armazena temporariamente o valor de venda do Item
            bool valido;

            valorTemp = playerInventario->valorItem(playerInventario->getIndex());
            valido = playerInventario->removerItemE(playerInventario->getIndex(),quantidade);// Remove o(s) Item(ns) do Inventário

            if(valido)
            {
                // Se a venda foi válida, incrementa-se o ouro do jogador
                // com o valor de venda do item multiplicado pela quantidade vendida
                novoPlayer->setOuro(novoPlayer->getOuro()+valorTemp*quantidade);
                MessageBox(NULL, "Venda efetuada com sucesso", "Venda",MB_ICONINFORMATION| MB_OK);
            }
            else
            {
                // Se a venda não foi válida, o ouro do jogador permanece o mesmo
                MessageBox(NULL, "A venda nao foi efetuada", "Venda",MB_ICONINFORMATION| MB_OK);
            }
        }break;
        case 1: // Venda de Bolsa
        {
            bool valido; // verificar se a compra foi efetuada com sucesso
            int valorTemp; // armazena temporariamente o valor de venda da Bolsa

            valorTemp = playerInventario->valorBolsa(playerInventario->getIndex());
            if(quantidade==1)
            {
            valido = playerInventario->removerBolsa(playerInventario->getIndex()); // Remove a bolsa do Inventário
            if(valido)
            {
                // Se a venda foi válida, incrementa-se o ouro do jogador com o valor de venda da bolsa
                novoPlayer->setOuro(novoPlayer->getOuro()+valorTemp);
                MessageBox(NULL, "Venda efetuada com sucesso", "Venda",MB_ICONINFORMATION| MB_OK);
            }
            else MessageBox(NULL, "A venda nao foi efetuada", "Venda",MB_ICONINFORMATION| MB_OK);
            }
            else MessageBox(NULL, "A venda nao foi efetuada", "Venda",MB_ICONINFORMATION| MB_OK);
        }break;
    }
}

// Verifica se o jogador tem ouro suficiente para realizar a compra
bool Loja::verificarQuantidadeDeOuro(Jogador *novoPlayer, int preco, int quantidade)
{
    if(preco*quantidade>novoPlayer->getOuro())
        return false;
    else return true;
}

// Método chamado pela tela de Compra para efetuar a operação de compra
void Loja::comprar(Jogador *player,Inventario *ptrInventario, int quantidade, HDC hDC)
{
    switch(listaSelecionada)
    {
        case 1:
            {
            // Verifica se o Jogador possui ouro suficiente para realizar a compra
            if(verificarQuantidadeDeOuro(player,listaArmas[index].getValorDeCompra(),quantidade))
            {
                bool valido=false;
                // Insere o Item no Inventario
                valido = ptrInventario->inserirItem(&listaArmas[index], quantidade);
                if(valido)
                {player->setOuro(player->getOuro()-listaArmas[index].getValorDeCompra()*quantidade);
                    MessageBox(NULL, "Compra efetuada com sucesso", "Compra",MB_ICONINFORMATION| MB_OK);}
                else
                    MessageBox(NULL, "A compra não foi efetuada", "Compra",MB_ICONINFORMATION| MB_OK);
            }
            else
            MessageBox(NULL, "Voce não possui ouro suficiente", "Compra",MB_ICONINFORMATION| MB_OK);
            }break;
        case 2:
            {
            // Verifica se o Jogador possui ouro suficiente para realizar a compra
            if(verificarQuantidadeDeOuro(player,listaEscudos[index].getValorDeCompra(),quantidade))
            {
                bool valido=false;
                // Insere o Item no Inventario
                valido = ptrInventario->inserirItem(&listaEscudos[index], quantidade);
                if(valido)
                {player->setOuro(player->getOuro()-listaEscudos[index].getValorDeCompra()*quantidade);
                    MessageBox(NULL, "Compra efetuada com sucesso", "Compra",MB_ICONINFORMATION| MB_OK);}
                else
                    MessageBox(NULL, "A compra não foi efetuada", "Compra",MB_ICONINFORMATION| MB_OK);
            }
            else
            MessageBox(NULL, "Voce não possui ouro suficiente", "Compra",MB_ICONINFORMATION| MB_OK);
            }break;
        case 3:
            {
            // Verifica se o Jogador possui ouro suficiente para realizar a compra
            if(verificarQuantidadeDeOuro(player,listaElmos[index].getValorDeCompra(),quantidade))
            {
                bool valido=false;
                // Insere o Item no Inventario
                valido = ptrInventario->inserirItem(&listaElmos[index], quantidade);
                if(valido)
                {player->setOuro(player->getOuro()-listaElmos[index].getValorDeCompra()*quantidade);
                    MessageBox(NULL, "Compra efetuada com sucesso", "Compra",MB_ICONINFORMATION| MB_OK);}
                else
                    MessageBox(NULL, "A compra não foi efetuada", "Compra",MB_ICONINFORMATION| MB_OK);
            }
            else
            MessageBox(NULL, "Voce não possui ouro suficiente", "Compra",MB_ICONINFORMATION| MB_OK);
            }break;
        case 4:
            {
            // Verifica se o Jogador possui ouro suficiente para realizar a compra
            if(verificarQuantidadeDeOuro(player,listaArmaduras[index].getValorDeCompra(),quantidade))
            {
                bool valido=false;
                // Insere o Item no Inventario
                valido = ptrInventario->inserirItem(&listaArmaduras[index], quantidade);
                if(valido)
                {player->setOuro(player->getOuro()-listaArmaduras[index].getValorDeCompra()*quantidade);
                    MessageBox(NULL, "Compra efetuada com sucesso", "Compra",MB_ICONINFORMATION| MB_OK);}
                else
                    MessageBox(NULL, "A compra não foi efetuada", "Compra",MB_ICONINFORMATION| MB_OK);
            }
            else
            MessageBox(NULL, "Voce não possui ouro suficiente", "Compra",MB_ICONINFORMATION| MB_OK);
            }break;
        case 5:
            {
            // Verifica se o Jogador possui ouro suficiente para realizar a compra
            if(verificarQuantidadeDeOuro(player,listaAcessorios[index].getValorDeCompra(),quantidade))
            {
                bool valido=false;
                // Insere o Item no Inventario
                valido = ptrInventario->inserirItem(&listaAcessorios[index], quantidade);
                if(valido)
                {player->setOuro(player->getOuro()-listaAcessorios[index].getValorDeCompra()*quantidade);
                    MessageBox(NULL, "Compra efetuada com sucesso", "Compra",MB_ICONINFORMATION| MB_OK);}
                else
                    MessageBox(NULL, "A compra não foi efetuada", "Compra",MB_ICONINFORMATION| MB_OK);
            }
            else
            MessageBox(NULL, "Voce não possui ouro suficiente", "Compra",MB_ICONINFORMATION| MB_OK);
            }break;
        case 6:
            {
            // Verifica se o Jogador possui ouro suficiente para realizar a compra
            if(verificarQuantidadeDeOuro(player,listaConsumo[index].getValorDeCompra(),quantidade))
            {
                bool valido=false;
                // Insere o Item no Inventario
                valido = ptrInventario->inserirItem(&listaConsumo[index], quantidade);
                if(valido)
                    {player->setOuro(player->getOuro()-listaConsumo[index].getValorDeCompra()*quantidade);
                    MessageBox(NULL, "Compra efetuada com sucesso", "Compra",MB_ICONINFORMATION| MB_OK);}
                else
                    MessageBox(NULL, "A compra não foi efetuada", "Compra",MB_ICONINFORMATION| MB_OK);
            }
            else
            MessageBox(NULL, "Voce não possui ouro suficiente", "Compra",MB_ICONINFORMATION| MB_OK);
            }break;
        case 7:
            {
            if(quantidade>1)
                MessageBox(NULL, "Apenas uma bolsa pode ser comprada por vez", "Compra",MB_ICONINFORMATION| MB_OK);
            // Verifica se o Jogador possui ouro suficiente para realizar a compra
            else if(verificarQuantidadeDeOuro(player,listaBolsas[index].getValorDeCompra(),quantidade))
            {
                bool valido=false;
                // Insere o Item no Inventario
                valido = ptrInventario->inserirBolsa(listaBolsas[index]);
                if(valido)
                {player->setOuro(player->getOuro()-listaBolsas[index].getValorDeCompra()*quantidade);
                    MessageBox(NULL, "Compra efetuada com sucesso", "Compra",MB_ICONINFORMATION| MB_OK);}
                else
                    MessageBox(NULL, "A compra não foi efetuada", "Compra",MB_ICONINFORMATION| MB_OK);
            }
            else
            MessageBox(NULL, "Voce não possui ouro suficiente", "Compra",MB_ICONINFORMATION| MB_OK);
            }break;
    }

}

//Cria as listas de Itens
void Loja::criaLista(HWND hWnd)
{
    // CRIA LIST VIEW DE CADA TIPO DE ITEM
    listViewArma = CreateWindowEx(0,WC_LISTVIEW,"",WS_CHILD|LVS_REPORT|LVS_ICON|LVS_NOCOLUMNHEADER|LVS_SINGLESEL,17,105,287,216,hWnd,(HMENU)ID_LISTA,GetModuleHandle(NULL),0);
    ListView_SetBkColor(listViewArma,RGB(255,242,204));
    ShowWindow(listViewArma,SW_HIDE);
    ListView_SetTextBkColor(listViewArma,RGB(255,242,204));

    listViewEscudo = CreateWindowEx(0,WC_LISTVIEW,"",WS_CHILD|LVS_REPORT|LVS_ICON|LVS_NOCOLUMNHEADER|LVS_SINGLESEL,17,105,287,216,hWnd,(HMENU)ID_LISTA,GetModuleHandle(NULL),0);
    ListView_SetBkColor(listViewEscudo,RGB(255,242,204));
    ShowWindow(listViewEscudo,SW_HIDE);
    ListView_SetTextBkColor(listViewEscudo,RGB(255,242,204));

    listViewElmo = CreateWindowEx(0,WC_LISTVIEW,"",WS_CHILD|LVS_REPORT|LVS_ICON|LVS_NOCOLUMNHEADER|LVS_SINGLESEL,17,105,287,216,hWnd,(HMENU)ID_LISTA,GetModuleHandle(NULL),0);
    ListView_SetBkColor(listViewElmo,RGB(255,242,204));
    ShowWindow(listViewElmo,SW_HIDE);
    ListView_SetTextBkColor(listViewElmo,RGB(255,242,204));

    listViewArmadura = CreateWindowEx(0,WC_LISTVIEW,"",WS_CHILD|LVS_REPORT|LVS_ICON|LVS_NOCOLUMNHEADER|LVS_SINGLESEL,17,105,287,216,hWnd,(HMENU)ID_LISTA,GetModuleHandle(NULL),0);
    ListView_SetBkColor(listViewArmadura,RGB(255,242,204));
    ShowWindow(listViewArmadura,SW_HIDE);
    ListView_SetTextBkColor(listViewArmadura,RGB(255,242,204));

    listViewAcessorio = CreateWindowEx(0,WC_LISTVIEW,"",WS_CHILD|LVS_REPORT|LVS_ICON|LVS_NOCOLUMNHEADER|LVS_SINGLESEL,17,105,287,216,hWnd,(HMENU)ID_LISTA,GetModuleHandle(NULL),0);
    ListView_SetBkColor(listViewAcessorio,RGB(255,242,204));
    ShowWindow(listViewAcessorio,SW_HIDE);
    ListView_SetTextBkColor(listViewAcessorio,RGB(255,242,204));

    listViewConsumo = CreateWindowEx(0,WC_LISTVIEW,"",WS_CHILD|LVS_REPORT|LVS_ICON|LVS_NOCOLUMNHEADER|LVS_SINGLESEL,17,105,287,216,hWnd,(HMENU)ID_LISTA,GetModuleHandle(NULL),0);
    ListView_SetBkColor(listViewConsumo,RGB(255,242,204));
    ShowWindow(listViewConsumo,SW_HIDE);
    ListView_SetTextBkColor(listViewConsumo,RGB(255,242,204));

    listViewBolsa = CreateWindowEx(0,WC_LISTVIEW,"",WS_CHILD|LVS_REPORT|LVS_ICON|LVS_NOCOLUMNHEADER|LVS_SINGLESEL,17,105,287,216,hWnd,(HMENU)ID_LISTA,GetModuleHandle(NULL),0);
    ListView_SetBkColor(listViewBolsa,RGB(255,242,204));
    ShowWindow(listViewBolsa,SW_HIDE);
    ListView_SetTextBkColor(listViewBolsa,RGB(255,242,204));

    //CRIA LISTA DE IMAGENS DOS ITENS PARA ASSOCIAR COM A LIST VIEW
    itemArma = ImageList_Create(30,30,ILC_MASK|ILC_COLORDDB,10,0);
    itemEscudo = ImageList_Create(30,30,ILC_MASK|ILC_COLORDDB,5,0);
    itemElmo = ImageList_Create(30,30,ILC_MASK|ILC_COLORDDB,5,0);
    itemArmadura = ImageList_Create(30,30,ILC_MASK|ILC_COLORDDB,5,0);
    itemAcessorio = ImageList_Create(30,30,ILC_MASK|ILC_COLORDDB,5,0);
    itemConsumo = ImageList_Create(30,30,ILC_MASK|ILC_COLORDDB,5,0);
    itemBolsa = ImageList_Create(30,30,ILC_MASK|ILC_COLORDDB,2,0);

    // CARREGA IMAGEM DOS ITENS
    for(int i = 0; i<10; i++)
    {
        item = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(listaArmas[i].getID()));
        ImageList_AddIcon(itemArma, item);
    }
    for(int i = 0; i<5; i++)
    {
        item = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(listaEscudos[i].getID()));
        ImageList_AddIcon(itemEscudo, item);
    }
    for(int i = 0; i<5; i++)
    {
        item = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(listaElmos[i].getID()));
        ImageList_AddIcon(itemElmo, item);
    }
    for(int i = 0; i<5; i++)
    {
        item = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(listaArmaduras[i].getID()));
        ImageList_AddIcon(itemArmadura, item);
    }
    for(int i = 0; i<5; i++)
    {
        item = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(listaAcessorios[i].getID()));
        ImageList_AddIcon(itemAcessorio, item);
    }
    for(int i = 0; i<5; i++)
    {
        item = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(listaConsumo[i].getID()));
        ImageList_AddIcon(itemConsumo, item);
    }
    for(int i = 0; i<2; i++)
    {
        item = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(listaBolsas[i].getID()));
        ImageList_AddIcon(itemBolsa, item);
    }

    ListView_SetImageList(listViewArma, itemArma, LVSIL_SMALL);
    ListView_SetImageList(listViewEscudo, itemEscudo, LVSIL_SMALL);
    ListView_SetImageList(listViewElmo, itemElmo, LVSIL_SMALL);
    ListView_SetImageList(listViewArmadura, itemArmadura, LVSIL_SMALL);
    ListView_SetImageList(listViewAcessorio, itemAcessorio, LVSIL_SMALL);
    ListView_SetImageList(listViewConsumo, itemConsumo, LVSIL_SMALL);
    ListView_SetImageList(listViewBolsa, itemBolsa, LVSIL_SMALL);
//------------------------------------------------------------------------------------------------

    // Coluna de nomes
    auxLista.mask = LVCF_FMT | LVCF_TEXT | LVCF_SUBITEM | LVCF_WIDTH;
    auxLista.fmt = LVCFMT_LEFT;
    auxLista.iSubItem = 0;
    auxLista.cx = 207;
    SendMessage((HWND) listViewArma, (UINT) LVM_INSERTCOLUMN, (WPARAM) (int) 0, (LPARAM) &auxLista);
    SendMessage((HWND) listViewEscudo, (UINT) LVM_INSERTCOLUMN, (WPARAM) (int) 0, (LPARAM) &auxLista);
    SendMessage((HWND) listViewElmo, (UINT) LVM_INSERTCOLUMN, (WPARAM) (int) 0, (LPARAM) &auxLista);
    SendMessage((HWND) listViewArmadura, (UINT) LVM_INSERTCOLUMN, (WPARAM) (int) 0, (LPARAM) &auxLista);
    SendMessage((HWND) listViewAcessorio, (UINT) LVM_INSERTCOLUMN, (WPARAM) (int) 0, (LPARAM) &auxLista);
    SendMessage((HWND) listViewConsumo, (UINT) LVM_INSERTCOLUMN, (WPARAM) (int) 0, (LPARAM) &auxLista);
    SendMessage((HWND) listViewBolsa, (UINT) LVM_INSERTCOLUMN, (WPARAM) (int) 0, (LPARAM) &auxLista);

    // Coluna de preços
    auxLista.fmt = LVCFMT_RIGHT;
    auxLista.iSubItem = 1;
    auxLista.cx = 50;
    SendMessage((HWND) listViewArma, (UINT) LVM_INSERTCOLUMN, (WPARAM) (int) 1, (LPARAM) &auxLista);
    SendMessage((HWND) listViewEscudo, (UINT) LVM_INSERTCOLUMN, (WPARAM) (int) 1, (LPARAM) &auxLista);
    SendMessage((HWND) listViewElmo, (UINT) LVM_INSERTCOLUMN, (WPARAM) (int) 1, (LPARAM) &auxLista);
    SendMessage((HWND) listViewArmadura, (UINT) LVM_INSERTCOLUMN, (WPARAM) (int) 1, (LPARAM) &auxLista);
    SendMessage((HWND) listViewAcessorio, (UINT) LVM_INSERTCOLUMN, (WPARAM) (int) 1, (LPARAM) &auxLista);
    SendMessage((HWND) listViewConsumo, (UINT) LVM_INSERTCOLUMN, (WPARAM) (int) 1, (LPARAM) &auxLista);
    SendMessage((HWND) listViewBolsa, (UINT) LVM_INSERTCOLUMN, (WPARAM) (int) 1, (LPARAM) &auxLista);

    for(int i=0; i<10; i++)
    {
        // Nome
        novo.mask = LVIF_TEXT|LVIF_IMAGE;
        novo.pszText = const_cast<char *>(listaArmas[i].getNome().c_str());
        novo.iItem = i;
        novo.iSubItem = 0;
        novo.iImage = i;
        ListView_InsertItem(listViewArma,&novo);
        // Preço
        char text[10];
        sprintf(text,"%d",listaArmas[i].getValorDeCompra());
        novo.mask = LVIF_TEXT;
        novo.pszText = text;
        novo.iItem = i;
        novo.iSubItem = 1;
        SendMessage((HWND) listViewArma,(UINT) LVM_SETITEM, (WPARAM) 0, (LPARAM) &novo);
    }
    for(int i=0; i<5; i++)
    {
        // Nome
        novo.mask = LVIF_TEXT|LVIF_IMAGE;
        novo.pszText = const_cast<char *>(listaEscudos[i].getNome().c_str());
        novo.iItem = i;
        novo.iSubItem = 0;
        novo.iImage = i;
        ListView_InsertItem(listViewEscudo,&novo);
        // Preço
        char text[10];
        sprintf(text,"%d",listaEscudos[i].getValorDeCompra());
        novo.mask = LVIF_TEXT;
        novo.pszText = text;
        novo.iItem = i;
        novo.iSubItem = 1;
        SendMessage((HWND) listViewEscudo,(UINT) LVM_SETITEM, (WPARAM) 0, (LPARAM) &novo);
    }
    for(int i=0; i<5; i++)
    {
        // Nome
        novo.mask = LVIF_TEXT|LVIF_IMAGE;
        novo.pszText = const_cast<char *>(listaElmos[i].getNome().c_str());
        novo.iItem = i;
        novo.iSubItem = 0;
        novo.iImage = i;
        ListView_InsertItem(listViewElmo,&novo);
        // Preço
        char text[10];
        sprintf(text,"%d",listaElmos[i].getValorDeCompra());
        novo.mask = LVIF_TEXT;
        novo.pszText = text;
        novo.iItem = i;
        novo.iSubItem = 1;
        SendMessage((HWND) listViewElmo,(UINT) LVM_SETITEM, (WPARAM) 0, (LPARAM) &novo);
    }
    for(int i=0; i<5; i++)
    {
        // Nome
        novo.mask = LVIF_TEXT|LVIF_IMAGE;
        novo.pszText = const_cast<char *>(listaArmaduras[i].getNome().c_str());
        novo.iItem = i;
        novo.iSubItem = 0;
        novo.iImage = i;
        ListView_InsertItem(listViewArmadura,&novo);
        // Preço
        char text[10];
        sprintf(text,"%d",listaArmaduras[i].getValorDeCompra());
        novo.mask = LVIF_TEXT;
        novo.pszText = text;
        novo.iItem = i;
        novo.iSubItem = 1;
        SendMessage((HWND) listViewArmadura,(UINT) LVM_SETITEM, (WPARAM) 0, (LPARAM) &novo);
    }
    for(int i=0; i<5; i++)
    {
        // Nome
        novo.mask = LVIF_TEXT|LVIF_IMAGE;
        novo.pszText = const_cast<char *>(listaAcessorios[i].getNome().c_str());
        novo.iItem = i;
        novo.iSubItem = 0;
        novo.iImage = i;
        ListView_InsertItem(listViewAcessorio,&novo);
        // Preço
        char text[10];
        sprintf(text,"%d",listaAcessorios[i].getValorDeCompra());
        novo.mask = LVIF_TEXT;
        novo.pszText = text;
        novo.iItem = i;
        novo.iSubItem = 1;
        SendMessage((HWND) listViewAcessorio,(UINT) LVM_SETITEM, (WPARAM) 0, (LPARAM) &novo);
    }
    for(int i=0; i<5; i++)
    {
        // Nome
        novo.mask = LVIF_TEXT|LVIF_IMAGE;
        novo.pszText = const_cast<char *>(listaConsumo[i].getNome().c_str());
        novo.iItem = i;
        novo.iSubItem = 0;
        novo.iImage = i;
        ListView_InsertItem(listViewConsumo,&novo);
        // Preço
        char text[10];
        sprintf(text,"%d",listaConsumo[i].getValorDeCompra());
        novo.mask = LVIF_TEXT;
        novo.pszText = text;
        novo.iItem = i;
        novo.iSubItem = 1;
        SendMessage((HWND) listViewConsumo,(UINT) LVM_SETITEM, (WPARAM) 0, (LPARAM) &novo);
    }
    for(int i=0; i<2; i++)
    {
        // Nome
        novo.mask = LVIF_TEXT|LVIF_IMAGE;
        novo.pszText = const_cast<char *>(listaBolsas[i].getNome().c_str());
        novo.iItem = i;
        novo.iSubItem = 0;
        novo.iImage = i;
        ListView_InsertItem(listViewBolsa,&novo);
        // Preço
        char text[10];
        sprintf(text,"%d",listaBolsas[i].getValorDeCompra());
        novo.mask = LVIF_TEXT;
        novo.pszText = text;
        novo.iItem = i;
        novo.iSubItem = 1;
        SendMessage((HWND) listViewBolsa,(UINT) LVM_SETITEM, (WPARAM) 0, (LPARAM) &novo);
    }
}

// Função que exibe a lista selecionada
void Loja::exibeLista(int opcao)
{
    listaSelecionada = opcao;
    switch(listaSelecionada)
    {
    case 1: {ShowWindow(listViewArma,SW_SHOW); break;}
    case 2: {ShowWindow(listViewEscudo,SW_SHOW); break;}
    case 3: {ShowWindow(listViewElmo,SW_SHOW); break;}
    case 4: {ShowWindow(listViewArmadura,SW_SHOW); break;}
    case 5: {ShowWindow(listViewAcessorio,SW_SHOW); break;}
    case 6: {ShowWindow(listViewConsumo,SW_SHOW); break;}
    case 7: {ShowWindow(listViewBolsa,SW_SHOW); break;}
    }
}

// Função que esconde todas as listas
void Loja::escondeLista()
{
    ShowWindow(listViewArma,SW_HIDE);
    ShowWindow(listViewEscudo,SW_HIDE);
    ShowWindow(listViewElmo,SW_HIDE);
    ShowWindow(listViewArmadura,SW_HIDE);
    ShowWindow(listViewAcessorio,SW_HIDE);
    ShowWindow(listViewConsumo,SW_HIDE);
    ShowWindow(listViewBolsa,SW_HIDE);
}
