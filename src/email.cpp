#include "email.hpp"

Email::Email(int prioridade, std::string mensagem){
    if(!(prioridade >= 0 && prioridade <= 9)){
        std::cout << "PRIORIDADE " << prioridade << " INVALIDA" << std::endl;
    }

    this->prioridade = prioridade;
    this->mensagem = mensagem;
}

int Email::getPrioridade(){
    return this->prioridade;
}

std::string Email::getMensagem(){
    return this->mensagem;
}
