#ifndef CAIXA_DE_ENTRADA_H
#define CAIXA_DE_ENTRADA_H

#include "filaPorPrioridadeEmails.hpp" 

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * da caixa de entrada de um usuario.
 */
class CaixaDeEntrada {
    protected:      
    FilaPorPrioridadeEmails* mensagens;
};

#endif
