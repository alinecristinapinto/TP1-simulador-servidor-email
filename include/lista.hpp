#ifndef LISTA_H
#define LISTA_H

#include <iostream>

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

    void inserir(T item);

    void remover(T item);

    bool presente(T item);

    bool listaVazia();
    
    virtual ~Lista() = default;

    private:
    No<T>* primeiro_;
    No<T>* ultimo_;
};

#endif
  