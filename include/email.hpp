#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * da emails (mensagens).
 */
class Email {
    protected:      
    /**
    * @brief Prioridade da mensagem - 0 a 9
    */
    int prioridade;
    /**
    * @brief Mensagem 
    */
    std::string mensagem;
};

#endif
