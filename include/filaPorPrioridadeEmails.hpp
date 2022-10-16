#ifndef LISTA_EMAILS_H
#define LISTA_EMAILS_H

#include <iostream>
#include "lista.hpp"
#include "email.hpp"

struct Celula {
    Email item;
    Celula* anterior; 
    Celula* proximo; 
};


class FilaPorPrioridadeEmails {
public:
    FilaPorPrioridadeEmails();

    void adicionar(int prioridade, std::string mensagem);

    void consultarRemoverPrimeiroEmail();

    bool vazia();

    void imprimir();

    ~FilaPorPrioridadeEmails();
protected:
    Celula* primeiro_;
    Celula* ultimo_; 
};

#endif
