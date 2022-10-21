#include "filaPorPrioridadeEmails.hpp"

FilaPorPrioridadeEmails::FilaPorPrioridadeEmails(){
    this->primeiro_ = nullptr;
}

bool FilaPorPrioridadeEmails::vazia(){
    return this->primeiro_ == nullptr;
}

void FilaPorPrioridadeEmails::adicionar(int prioridade, std::string mensagem){
    No<Email> *novoItem = new No<Email>{Email(prioridade, mensagem), nullptr};
    Log::erroAssert(novoItem == NULL, "Erro ao alocar memoria para mensagem de email");

    if(this->vazia()){
        this->primeiro_ = novoItem;  
        return;
    }

    No<Email> *aux = this->primeiro_, *anterior = nullptr;

    while(true) {
        if(aux == nullptr){
            novoItem->proximo = aux;
            anterior->proximo = novoItem;

            return;
        } else if(aux->item.getPrioridade() < novoItem->item.getPrioridade()){
            novoItem->proximo = aux;

            if(aux == this->primeiro_){
                this->primeiro_ = novoItem;
            } else {
                anterior->proximo = novoItem;
            }

            return;
        } 

        anterior = aux;
        aux = aux->proximo;
    }
}

void FilaPorPrioridadeEmails::consultarRemoverPrimeiroEmail(int idUsuario){
    if(this->vazia()){
        Log::erro("CAIXA DE ENTRADA VAZIA");
        return;
    }

    No<Email> *remover = this->primeiro_;
    Log::info(("CONSULTA " + std::to_string(idUsuario) + ": " + remover->item.getMensagem()));
    
    this->primeiro_ = this->primeiro_->proximo;
    
    delete remover;
}

void FilaPorPrioridadeEmails::imprimir(){
    No<Email>* aux = this->primeiro_;

    while (aux){
        std::cout << aux->item.getPrioridade() << " " << aux->item.getMensagem() << std::endl;
        aux = aux->proximo;
    }
}

FilaPorPrioridadeEmails::~FilaPorPrioridadeEmails(){
    while (this->primeiro_ != nullptr){
        this->consultarRemoverPrimeiroEmail(-1);
    }
}