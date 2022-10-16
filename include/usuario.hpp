#ifndef USUARIO_H
#define USUARIO_H

#include "caixaEntrada.hpp" 

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de usuario.
 */
class Usuario {
public:
    Usuario();
    
    Usuario(int id);

    int getId();

    CaixaDeEntrada* getCaixaDeEntrada();

    virtual ~Usuario() = default;

protected:      
    int id;
    CaixaDeEntrada *caixa;
};

#endif
