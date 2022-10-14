#include "usuario.hpp"

Usuario::Usuario(){
    this->id = -1;
    this->caixa = new CaixaDeEntrada();
}

Usuario::Usuario(int id){
    this->id = id;
    this->caixa = new CaixaDeEntrada();
}