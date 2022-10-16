#ifndef LISTA_USUARIOS_H
#define LISTA_USUARIOS_H

#include "lista.hpp"
#include "usuario.hpp"

class ListaUsuarios : public Lista<Usuario> {
public:
    ListaUsuarios();

    void inserirInicio(int id);

    void remover(int id);

    bool presente(int id);
    
    void enviarMensagem(int idUsuario, int prioridade, std::string mensagem);

    void imprimir();

    virtual ~ListaUsuarios() = default;
};

#endif
