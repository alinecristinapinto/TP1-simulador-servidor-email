#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <iostream>
#include "msgassert.hpp"
#include "usuario.hpp"
#include "lista.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento do servidor de emails
 */
class Servidor {
    public:
    Servidor();

    void cadastrarUsuario(int id);

    void removerUsuario(int id);

    protected:      
    /**
    * @brief Lista de usuarios do servidor de email
    */
    Lista<Usuario> *usuarios;
};

#endif
