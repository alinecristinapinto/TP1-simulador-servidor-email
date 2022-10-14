#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "msgassert.hpp"

/**
 * @brief Struct que representa um no de uma lista generica
 */
template <typename T> struct No {  
    T item;
    No* anterior; 
    No* proximo; 
}; 

/**
 * @brief Classe que representa uma lista duplamente encadeada generica
 */
template <typename T> class Lista {
    public:
    Lista();

    void inserir_fim(T item);

    void remover(T item);

    bool presente(T item);

    bool listaVazia();
    
    virtual ~Lista() = default;

    private:
    No<T>* primeiro_;
    No<T>* ultimo_;
};

#endif
  