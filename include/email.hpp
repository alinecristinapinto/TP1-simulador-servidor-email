#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>
#include "log.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * da emails (mensagens).
 */
class Email {
public:
    Email(int prioridade, std::string mensagem);

    int getPrioridade();

    std::string getMensagem();

    virtual ~Email() = default;

protected:      
    /**
    * @brief Prioridade da mensagem - 0 a 9
    */
    int prioridade;

    std::string mensagem;
};

#endif
