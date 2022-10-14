#ifndef USUARIO_H
#define USUARIO_H

#include "caixaEntrada.hpp" 

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de usuario.
 */
class Usuario {
    public:
    Usuario(int id);

    virtual ~Usuario() = default;

    protected:      
    /**
    * @brief Id do usuario 
    */
    int id;
    /**
    * @brief Caixa de entrada do usuario 
    */
    CaixaDeEntrada *caixa;
};

#endif
