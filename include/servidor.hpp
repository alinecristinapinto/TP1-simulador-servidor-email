#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <iostream>
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

    void enviarEmail(int idUsuario, int prioridadeMensagem, std::string mensagem);

    void consultarEmail(int idUsuario);

    virtual ~Servidor() = default;

protected:      
    ListaUsuarios *usuarios;
};

#endif
