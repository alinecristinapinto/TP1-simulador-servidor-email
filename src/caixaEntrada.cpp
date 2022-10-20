#include "caixaEntrada.hpp"

CaixaDeEntrada::CaixaDeEntrada(){
    this->mensagens = new FilaPorPrioridadeEmails();
}

void CaixaDeEntrada::adicionar(int prioridade, std::string mensagem){
    this->mensagens->adicionar(prioridade, mensagem);
}

void CaixaDeEntrada::consultarRemoverPrimeiroEmail(int idUsuario){
    this->mensagens->consultarRemoverPrimeiroEmail(idUsuario);
}
