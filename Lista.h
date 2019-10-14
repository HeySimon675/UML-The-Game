/*
-------------- Created by simao on 16/04/19. --------------------------
---------------Lista Template Duplamente Encadeada---------------------
*/
#pragma once
#include "Elemento.h"

template<class TIPO> class Lista {
private:
    Elemento<TIPO>* primeiro;
    Elemento<TIPO>* atual;
    Elemento<TIPO>* aux;
public:
    //CONSTRUTORAS
    Lista() {primeiro= nullptr; atual= nullptr;aux= nullptr;}
    ~Lista() {primeiro= nullptr; atual= nullptr;aux= nullptr;}

    //INCLUIR NA LISTA
    bool includeElemento(TIPO* el);
    void operator=(TIPO* el);

    //GET PRIMEIRO E ATUAL ELEMENTO
    Elemento<TIPO>* getPrim();
    Elemento<TIPO>* getAt();

    //REMOVE/RETORNA/LIMPA LISTA
    TIPO* retornaElemento();
    bool removeElemento();
    void operator--();
    void limpaLista();

    //FUNÇÕES NAO IMPLEMENTADAS
    void inicializaLista();
    void gravaLista();
    void returnLista();

};
//INCLUIR
template<class TIPO>
bool Lista<TIPO>::includeElemento(TIPO *el){
    aux = new Elemento<TIPO>(el); //criando um Elemento com o TIPO especificado, para por na lista
    if (primeiro== nullptr){    //lista vazia
        primeiro=aux;
        atual=aux;
        aux->setProx(nullptr);
        aux->setAnte(nullptr);   //Como é o primeiro elemento ele não possui proximo nem anterior
        aux= nullptr;

        return true;
    }else{// a lista possuí 1+ elementos
            aux= new Elemento<TIPO>(el);
            aux->setAnte(atual);
            atual->setProx(aux);
            aux->setProx(nullptr);
            atual=aux;
            aux=nullptr;
            return true;
    }
}

template<class TIPO>
void Lista<TIPO>::operator=(TIPO *el) {
    if(!includeElemento(el)){
        //TODO WARNING
        // Criar aviso para elemento não incluido na lista
    }
}


//GETS
template<class TIPO>
Elemento<TIPO> *Lista<TIPO>::getPrim() {
    return primeiro;
}

template<class TIPO>
Elemento<TIPO> *Lista<TIPO>::getAt() {
    return atual;
}

//RETURN/REMOVE/ LIMPA LISTA
template<class TIPO>
TIPO *Lista<TIPO>::retornaElemento() {
    return nullptr;
}

template<class TIPO>
bool Lista<TIPO>::removeElemento() {
    return false;
}

template<class TIPO>
void Lista<TIPO>::operator--() {
    limpaLista();
}

template<class TIPO>
void Lista<TIPO>::limpaLista() {
    //Limpa a lista alocada em memoria, não alterando a ja armazenada em arquivo
    //construir a função de modo que se limpar a lista e pedir para gravar vai "esvaziar" a lista em arquivo.
}

//NÃO IMPLEMENTADAS
template<class TIPO>
void Lista<TIPO>::inicializaLista() {
    //A função inicializa a lista deve buscar elementos ja criados da lista em questão nos arquivos .txt
}

template<class TIPO>
void Lista<TIPO>::gravaLista() {
    //reescreve o arquivo .txt que contem objetos ja criados da lista
}

template<class TIPO>
void Lista<TIPO>::returnLista() {
    //recupera uma lista de elementos<TIPO> de um arquivo .txt essa função sobrepoe os objetos criados em tempo de execução
    //util para terminar a execução sem alterar a base de dados
}

