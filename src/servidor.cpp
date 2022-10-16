#include "servidor.hpp"

Servidor::Servidor(){
    this->usuarios = new ListaUsuarios();
}

void Servidor::cadastrarUsuario(int id){
    this->usuarios->inserir_inicio(id);
}

void Servidor::removerUsuario(int id){
    this->usuarios->remover(id);
}

void Servidor::imprimir(){
    this->usuarios->imprimir();
}
