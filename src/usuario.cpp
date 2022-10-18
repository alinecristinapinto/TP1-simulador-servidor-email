#include "usuario.hpp"

Usuario::Usuario(){
    this->id = -1;
    this->caixa = new CaixaDeEntrada();
}

Usuario::Usuario(int id){
    Log::erroAssert(!(id >= 0 && id <= pow(10,6)), "ID " + std::to_string(id) + " INVALIDO");

    this->id = id;
    this->caixa = new CaixaDeEntrada();
}

int Usuario::getId(){
    return this->id;
}

CaixaDeEntrada* Usuario::getCaixaDeEntrada(){
    return this->caixa;
}
