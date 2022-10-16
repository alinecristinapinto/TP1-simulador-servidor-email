#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * da emails (mensagens).
 */
class Email {
public:
    Email(int prioridade, std::string mensagem);

    int getPrioridade();

    std::string getMensagem();

    ~Email();

protected:      
    /**
    * @brief Prioridade da mensagem - 0 a 9
    */
    int prioridade;

    std::string mensagem;
};

#endif
