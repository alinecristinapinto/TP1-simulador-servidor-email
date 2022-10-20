#include "usuario.hpp"

Usuario::Usuario(int id){
    Log::erroAssert(!(id >= 0 && id <= pow(10,6)), "ID " + std::to_string(id) + " INVALIDO");

    this->id = id;
    this->caixa = new CaixaDeEntrada();
}

int Usuario::getId(){
    std::cout << &this->id << std::endl;
    return this->id;
}

CaixaDeEntrada* Usuario::getCaixaDeEntrada(){
    return this->caixa;
}
