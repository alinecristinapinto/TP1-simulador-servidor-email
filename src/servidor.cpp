#include "servidor.hpp"

Servidor::Servidor(){
    this->usuarios = new ListaUsuarios();
}

void Servidor::cadastrarUsuario(int id){
    if(this->usuarios->presente(id)){
        std::cout << "ERRO: CONTA " << id << " JA EXISTENTE" << std::endl;
    } else {
        this->usuarios->inserir_fim(new Usuario(id));
        std::cout << "OK: CONTA " << id << " CADASTRADA" << std::endl;
    }
}

void Servidor::removerUsuario(int id){
    this->usuarios->remover(id);
}

void Servidor::imprimir(){
    this->usuarios->imprimir();
}
