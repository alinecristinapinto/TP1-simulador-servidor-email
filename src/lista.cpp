#include "lista.hpp"
#include "usuario.hpp"
#include "email.hpp"

template <typename T> Lista<T>::Lista(){
    this->primeiro_ = nullptr;
}

template <typename T>  bool Lista<T>::lista_vazia() {
    return this->primeiro_ == nullptr;
}

// Limitacao do uso de templates em C++ 
// https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
template class Lista<Usuario>;
template class Lista<Email>;
