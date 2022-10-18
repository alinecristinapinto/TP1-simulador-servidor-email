#ifndef LISTA_USUARIOS_H
#define LISTA_USUARIOS_H

#include "usuario.hpp"
#include "constantes.hpp"
#include "log.hpp"

class ListaUsuarios {
public:
    ListaUsuarios();

    void inserirInicio(int id);

    void remover(int id);

    bool presente(int id);

    bool lista_vazia();

    void enviarEmail(int idUsuario, int prioridade, std::string mensagem);

    void consultarRemoverEmail(int idUsuario);

    void imprimir();

    ~ListaUsuarios();

protected:
    No<Usuario>* primeiro_;
};

#endif
