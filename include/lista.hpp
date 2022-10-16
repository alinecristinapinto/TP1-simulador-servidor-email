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

    bool lista_vazia();
    
    virtual ~Lista() = default;

protected:
    No<T>* primeiro_;
};

#endif
  