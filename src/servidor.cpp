#include "servidor.hpp"

Servidor::Servidor(){
    this->usuarios = new Lista<Usuario>();
}

void Servidor::cadastrarUsuario(int id){
    // if(this->usuarios->presente(id)){
    //     // erroAssert(true, "ERRO: CONTA 1 JA EXISTENTE");
    //     std::cout << "ERRO: CONTA " << id << " JA EXISTENTE" << std::endl;
    // } else {
        // this->usuarios->inserir(id);
        std::cout << "OK: CONTA " << id << " CADASTRADA" << std::endl;
    // }
}

void Servidor::removerUsuario(int id){
    // if(!this->usuarios->presente(id)){
    //     // erroAssert(true, "ERRO: CONTA 1 NAO EXISTE");
    //     std::cout << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
    // } else {
        // this->usuarios->remover(id);
        std::cout << "OK: CONTA " << id << " REMOVIDA" << std::endl;
    // }
}
