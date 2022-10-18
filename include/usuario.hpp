#ifndef USUARIO_H
#define USUARIO_H

#include "caixaEntrada.hpp" 
#include "log.hpp"
#include <cmath>

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de usuario.
 */
class Usuario {
public:    
    Usuario(int id);

    int getId();

    CaixaDeEntrada* getCaixaDeEntrada();

    virtual ~Usuario() = default;

protected:      
    int id;
    CaixaDeEntrada *caixa;
};

#endif
