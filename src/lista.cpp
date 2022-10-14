#include "lista.hpp"
#include "usuario.hpp"

template <typename T> Lista<T>::Lista(){
    this->primeiro_ = nullptr;
    this->ultimo_ = nullptr;
}

template <typename T> void Lista<T>::inserir(T item){
    // No<T>* novoItem = new No<T>{item, nullptr};
}

template <typename T> void Lista<T>::remover(T item){
    // No<T>* novoItem = new No<T>{item, nullptr};
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
