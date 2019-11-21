
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 09/11/19.
//Last Update 09/11 12hrs
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


//--------------------------------------------------------------------------------------------------------------------//
//Metodos//

    void setPosition(Vector2f position);

public:
    Personagem(Vector2f position = POSICAO_PADRAO, Vector2f size = TAMANHO_PADRAO, float speed = VELOCIDADE_PADRAO);
    virtual ~Personagem();

    void inicializaPersonagem(Vector2f position, Vector2f size, float speed);
    virtual void calculaMovimento(const float deltaTime) = 0;
    void draw();
    void update(float deltaTime);
    const bool isDead();
    void setPositionx(const float positionx);



//--------------------------------------------------------------------------------------------------------------------//
//Constantes//
    static const Vector2f POSICAO_PADRAO;
protected:
    static const float VELOCIDADE_PADRAO;
    static const Vector2f TAMANHO_PADRAO;
    static const float PULO_PADRAO;
};

