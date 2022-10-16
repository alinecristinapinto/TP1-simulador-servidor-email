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

void Servidor::enviarEmail(int idUsuario, int prioridadeMensagem, std::string mensagem){
    this->usuarios->enviarEmail(idUsuario, prioridadeMensagem, mensagem);
}

void Servidor::consultarEmail(int idUsuario){
    this->usuarios->consultarRemoverEmail(idUsuario);
}

void Servidor::imprimir(){
    this->usuarios->imprimir();
}
