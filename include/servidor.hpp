#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <iostream>
#include "msgassert.hpp"
#include "listaUsuarios.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento do servidor de emails
 */
class Servidor {
    public:
    Servidor();

    void cadastrarUsuario(int id);

    void removerUsuario(int id);

    void imprimir();

    void enviarMensagem(int idUsuario, int prioridadeMensagem, std::string mensagem);

    protected:      
    /**
    * @brief Lista de usuarios do servidor de email
    */
    ListaUsuarios *usuarios;
};

#endif
