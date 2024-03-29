
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 26/10/19.
#pragma once

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <string.h>

class Entidade;
//--------------------------------------------------------------------------------------------------------------------//
//Namespace's
using namespace sf;
using namespace std;
using std::vector;
using std::string;

namespace gerenciadores {
    class GerenciadorGrafico;
}
//--------------------------------------------------------------------------------------------------------------------//
//Gerenciador Grafico


typedef class GerenciadorGrafico {
private:
    friend class Jogo;
    RenderWindow _window;
    View pView;
    map<int, Texture*> _mTexture;  //testando nova estrutura para poder carregar mais facilmente a textura das Entidades
    vector<Texture*> _vTexture;
    static GerenciadorGrafico* _instance;   //Singleton
    Event event;
    static int key; //chave do Map
    Font font;
//contrutora privada//
    GerenciadorGrafico();
public:

    ~GerenciadorGrafico();
    static GerenciadorGrafico* getGerGrafico();     //implementação do Singleton
    vector<Texture*>* getVector();
    map<int,Texture*>* getMap();
    int getLastKey(){return key;}
//--------------------------------------------------------------------------------------------------------------------//
//METODOS PARA TESTE//
private:
    //RenderWindow* getWindow(){ return _window;}
//--------------------------------------------------------------------------------------------------------------------//
//METODOS OBSOLETOS
void drawEntidade(Entidade* entidade);
//--------------------------------------------------------------------------------------------------------------------//
//loop//
public:
    void executar();
    bool janelaAberta();
    void exibir();
    void draw(RectangleShape body);
    void drawPontos(int pontos);
    void draw(Text text);
    void fechar(){_window.close();}
    //verifica atravez do id se a entidade possui uma textura e então associa ela atravez do map de Texturas
    void associaTextura(Entidade* entidade);
    //ou poderia implementar um metodo que só retorna a textura para a Entidade, somente passando o proprio id
    //a função iria acessar o map pelo id, retornando a textura, não teria como verificar se é a textura certa, mas como
    //nao metodos para usuario, não vejo problema.
    Texture* getTexture(int id);
    const String getFont(){ return FONT_ARIAL;}
private:
    void updateSFML();


//--------------------------------------------------------------------------------------------------------------------//
//Inicializadoras//
public:
    void inicializa();
private:
    void inicializaView();
    void carregaTexturas();
    void carregaFontes();
    void inicializaWindow();
    void load(const String _caminho);
//end Private

//--------------------------------------------------------------------------------------------------------------------//
//Static Const//
public:
    //Janela e View//
    static const unsigned int larguraJanela;
    static const unsigned int alturaJanela;
    static const Vector2f WindowSize;
    static const String titulo;
    static const Vector2f center;
    //View //

    //Diretorios//
    static const String SYSTEM_PREFIX;
    static const String TEXTURE_DIR;
    static const String FONTES_DIR;

    //Fontes//
    static const String FONT_ARIAL;
    //player//
    static const String JOGADOR_1_tx;
    static const String JOGADOR_2_tx;
    
    //Inimigo//
    static const String INIMIGO_A_tx;
    static const String INIMIGO_B_tx;
    static const String INIMIGO_BOSS_tx;
    
    //Obstaculos//
    static const String OBSTACULO_PLATAFORMA_tx;
    static const String OBSTACULO_CAIXA_tx;
    static const String OBSTACULO_SPIKE_tx;
    
    //Projetil//
    static const String PROJETIL_tx;

    //Fases//
    static const String FASE_A_tx;
    static const String FASE_B_tx;

    
}gGrafico;


