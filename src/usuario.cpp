#include "usuario.hpp"

Usuario::Usuario(){
    this->id = -1;
    this->caixa = new CaixaDeEntrada();
}

Usuario::Usuario(int id){
    this->id = id;
    this->caixa = new CaixaDeEntrada();
}

int Usuario::getId(){
    return this->id;
}

CaixaDeEntrada* Usuario::getCaixaDeEntrada(){
    return this->caixa;
}
