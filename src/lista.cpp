#include "lista.hpp"
#include "usuario.hpp"

template <typename T> Lista<T>::Lista(){
    this->primeiro_ = nullptr;
    this->ultimo_ = nullptr;
}

template <typename T> void Lista<T>::inserir_fim(T item){
    No<T>* novo_item = new No<T>{item, nullptr};
    erroAssert(!(novo_item == NULL), "Erro ao alocar memoria para item da lista");

    novo_item->item = item;
    novo_item->proximo = nullptr;

    if(this->listaVazia()){
        novo_item->anterior = nullptr;
    } else {
        novo_item->anterior = this->ultimo_;
        this->ultimo_ = novo_item;
    }
}

template <typename T> void Lista<T>::remover(T item){
    //No<T>* novo_item = new No<T>{item, nullptr};
}

template <typename T> bool Lista<T>::presente(T item){
    return false;
}

template <typename T>  bool Lista<T>::listaVazia() {
    return this->primeiro_ == nullptr && this->ultimo_ == nullptr;
}

// Limitacao do uso de templates em C++ 
// https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
template class Lista<Usuario>;
