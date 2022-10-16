#ifndef LISTA_EMAILS_H
#define LISTA_EMAILS_H

#include <iostream>
#include "lista.hpp"
#include "email.hpp"

class FilaPorPrioridadeEmails {
public:
    FilaPorPrioridadeEmails();

    void adicionar(int prioridade, std::string mensagem);

    bool vazia();

    void imprimir();

    ~FilaPorPrioridadeEmails();
protected:
    No<Email>* primeiro_;
    No<Email>* ultimo_; 
};

#endif