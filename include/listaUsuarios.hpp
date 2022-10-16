#ifndef LISTA_USUARIOS_H
#define LISTA_USUARIOS_H

#include "lista.hpp"
#include "usuario.hpp"

class ListaUsuarios : public Lista<Usuario> {
public:
    ListaUsuarios();

    void inserir_inicio(int id);

    void remover(int id);

    bool presente(int id);

    void imprimir();

    virtual ~ListaUsuarios() = default;
};

#endif
