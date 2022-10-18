#include "email.hpp"

Email::Email(int prioridade, std::string mensagem){
    Log::erroAssert(!(prioridade >= 0 && prioridade <= 9), "PRIORIDADE " + std::to_string(prioridade) + " INVALIDA");

    this->prioridade = prioridade;
    this->mensagem = mensagem;
}

int Email::getPrioridade(){
    return this->prioridade;
}

std::string Email::getMensagem(){
    return this->mensagem;
}
