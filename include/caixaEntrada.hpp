#ifndef CAIXA_DE_ENTRADA_H
#define CAIXA_DE_ENTRADA_H

#include <string> 
#include "filaPorPrioridadeEmails.hpp" 

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * da caixa de entrada de um usuario.
 */
class CaixaDeEntrada {
public:
    CaixaDeEntrada();

    void adicionar(int prioridade, std::string mensagem);

    void consultarRemoverPrimeiroEmail(int idUsuario);
    
protected:      
    FilaPorPrioridadeEmails* mensagens;
};

#endif
