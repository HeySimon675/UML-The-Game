
//--------------------------------------------------------------------------------------------------------------------//
//Implementação por:
    //Simão - 100%
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Fase_A

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include <stdio.h>
#include "Fase.h"

//--------------------------------------------------------------------------------------------------------------------//
//ENTIDADES QUE A FASE CONHECE

#include "Inimigo_A.h"
//Inimigo_B está incluso atraves de Fase
//Obstaculo_Plataforma está incluso atraves de Fase
//#include "Obstaculo_Spike.h"


//--------------------------------------------------------------------------------------------------------------------//
//Classe Fase_A//
class Fase_A : public Fase{

//--------------------------------------------------------------------------------------------------------------------//
//construção
private:

//--------------------------------------------------------------------------------------------------------------------//
//Criação de Entidades
    
    void criaEntidade(char aux, Vector2f pos);
    void criaInimigoA(Vector2f pos);
    //O Resto das Entidades tem metodos de criação em Fase

public:
    Fase_A(Jogador_1* jogador1 = nullptr, Jogador_2* jogador2 = nullptr);
    ~Fase_A();
    void inicializa();
    const int getID(){ return id;}
//--------------------------------------------------------------------------------------------------------------------//
//variaveis para fase


//--------------------------------------------------------------------------------------------------------------------//
//Constantes
private:
    static const String FASE_FILE;
    static const int FASE_WIDTH;
    static const int FASE_HEIGHT;
    static const int id;
    static const float FIM;
    void setFinalPosition(){finalPosition = FIM*50.0f;}
};
