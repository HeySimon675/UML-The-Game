
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 09/11/19.
//Implementado por:
    //Coradassi - 80%
    //Simão - 20%


#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Entidade

//Deriva as Classes:
    //Jogador
    //Inimigo

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Entidade.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Personagem//
class Personagem : public Entidade {
//--------------------------------------------------------------------------------------------------------------------//
//Parametros//
private:

protected:
    RectangleShape body;
    Vector2f vel;
    float speed;
    bool canJump;
	float deltaTime;

    /**booleano para dizer se sofreu dano ou não**/
    bool dead;
    virtual void associaTextura();
    //const int getID(){return -1;}   //a ideia é que seja usada as generalizações dessa classe

//--------------------------------------------------------------------------------------------------------------------//
//Metodos//



public:
    Personagem(Vector2f position = POSICAO_PADRAO, Vector2f size = TAMANHO_PADRAO, float speed = VELOCIDADE_PADRAO);
    virtual ~Personagem();
    void setPosition(Vector2f position);
    void inicializaPersonagem(Vector2f position, Vector2f size, float speed);
    virtual void calculaMovimento(const float deltaTime) = 0;
    void draw();
    void update(float deltaTime);
    const bool isDead();
    void setPositionx(const float positionx);
    void corrigePosicao(){body.move(25,25);}

    void emColisao(Vector2f direcao);

//COLISOES
    Vector2f getPosition(){ return body.getPosition();}
    Vector2f getHalfSize(){ return (body.getSize()/2.0f);}
    void move (float dx, float dy){body.move(dx,dy);}



//--------------------------------------------------------------------------------------------------------------------//
//Constantes//
    static const Vector2f POSICAO_PADRAO;
protected:
    static const float VELOCIDADE_PADRAO;
    static const Vector2f TAMANHO_PADRAO;
    static const float PULO_PADRAO;
};

