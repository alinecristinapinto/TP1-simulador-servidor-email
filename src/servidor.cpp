#include "servidor.hpp"

Servidor::Servidor(){
    this->usuarios = new ListaUsuarios();
}

void Servidor::cadastrarUsuario(int id){
    this->usuarios->inserirInicio(id);
}

void Servidor::removerUsuario(int id){
    this->usuarios->remover(id);
}

void Servidor::enviarMensagem(int idUsuario, int prioridadeMensagem, std::string mensagem){
    this->usuarios->enviarMensagem(idUsuario, prioridadeMensagem, mensagem);
}

void Servidor::imprimir(){
    this->usuarios->imprimir();
}
