#ifndef LISTA_EMAILS_H
#define LISTA_EMAILS_H

#include <iostream>
#include "email.hpp"
#include "constantes.hpp"
#include "log.hpp"

class FilaPorPrioridadeEmails {
public:
    FilaPorPrioridadeEmails();

    void adicionar(int prioridade, std::string mensagem);

    void consultarRemoverPrimeiroEmail(int idUsuario);

    bool vazia();

    void imprimir();

    ~FilaPorPrioridadeEmails();
protected:
    No<Email>* primeiro_;
    No<Email>* ultimo_; 
};

#endif
